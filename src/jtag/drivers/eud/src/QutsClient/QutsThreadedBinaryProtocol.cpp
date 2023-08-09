/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "QutsThreadedBinaryProtocol.h"

namespace QutsThreadedBinaryProtocol
{
	static const int  RESPONSE_WAIT_PERIOD  = 10;
	static const size_t RESPONSE_RESERVE_SIZE = 4 * 1024;

	template<class Transport_, class ByteOrder_>
	QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::QutsThreadedBinaryProtocol(const std::shared_ptr<Transport_>& pTransport) 
		: apache::thrift::protocol::TBinaryProtocolT<Transport_, ByteOrder_>(pTransport),
		m_pResponse(),
		m_pThread(),
		m_responseMap(),
		m_responseMutex(),
		m_writeMutex(),
		m_readMutex(),
		m_seqIdMutex(),
		m_seqId(0),
		m_outstandingRequests(0),
		m_bLocked(false),
		m_newRequestEvent()
	{
		startReader(); //start thread
	}

	template<class Transport_, class ByteOrder_>
	QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::~QutsThreadedBinaryProtocol()
	{
		stopReader();
	}

	template<class Transport_, class ByteOrder_>
	bool QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::isStopSignaled()
	{
		return !this->m_bRunning;
	}

	template<class Transport_, class ByteOrder_>
	void QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::startReader()
	{
		if (this->m_pThread.get() == nullptr)
		{
			this->m_bRunning = true;
			this->m_pThread = std::shared_ptr<std::thread>(new std::thread(&QutsThreadedBinaryProtocol::onRun, this)); //creates and start thread 
		}
	}

	template<class Transport_, class ByteOrder_>
	void QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::stopReader()
	{
		if (this->m_pThread.get() != nullptr)
		{
			this->m_bRunning = false;
			this->m_pThread->join(); //waiting to exit
			this->m_pThread.reset();
		}
	}

	template<class Transport_, class ByteOrder_>
	void QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::onRun()
	{
		while (this->m_bRunning)
		{
			while (0 == this->m_outstandingRequests && this->m_bRunning)
			{
				Event::Event::waitForEvent(&m_newRequestEvent, RESPONSE_WAIT_PERIOD);
			}

			if (!this->m_bRunning)
			{
				//LOG_INFO(m_pLogger, "ThreadedClientProtocol onRun stopped.");
				return;
			}

			int32_t seqId = 0;
			std::string name = std::string("");
			::apache::thrift::protocol::TMessageType messageType = ::apache::thrift::protocol::TMessageType::T_CALL;
			Buffer::Buffer<uint8_t>* pBuffer = new Buffer::Buffer<uint8_t>();
			pBuffer->resize(0);

			// Read the message off the socket
			MyBase::readMessageBegin(name, messageType, seqId);

			// Write the header into the new buffer
			int32_t header = MyBase::VERSION_1 | messageType;
			pBuffer->resize(
				sizeof(header)
				+ sizeof(int32_t) + name.size() // String is 32 bit length prefix
				+ sizeof(seqId)
			);

			uint8_t* pWriteBuffer = pBuffer->begin();
			*reinterpret_cast<int32_t*>(pWriteBuffer) = header;
			pWriteBuffer += sizeof(header);
			*reinterpret_cast<int32_t*>(pWriteBuffer) = name.size();
			pWriteBuffer += sizeof(int32_t);
			memcpy(pWriteBuffer, name.c_str(), name.size());
			pWriteBuffer += name.size();
			*reinterpret_cast<int32_t*>(pWriteBuffer) = seqId;

			// Write the parameters into the new buffer
			readMessage(::apache::thrift::protocol::T_STRUCT, pBuffer);

			MyBase::readMessageEnd();
			MyBase::getTransport()->readEnd();
			m_outstandingRequests--;
			m_newRequestEvent.reset();
	
			typename ResponseMap::iterator it;
			try
			{
				this->m_responseMutex.lock();
				it = m_responseMap.find(seqId);
				if (m_responseMap.end() == it)
				{
					throw std::runtime_error("Could not find sequence ID for message");
				}
				it->second->m_pResponse = pBuffer;
				it->second->m_respondEvent.signal();
			}
			catch (...)
			{
				
			}	
			this->m_responseMutex.unlock();
		}
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::writeMessageBegin_virt(const std::string& name, const::apache::thrift::protocol::TMessageType messageType, const int32_t origSeqId)
	{
		// Lock this mutex so another thread doesn't insert its call
	    // into the middle of this call's buffer
		uint32_t result;
		m_writeMutex.lock();

		if (::apache::thrift::protocol::T_CALL != messageType)
		{
			m_seqIdMutex.lock(); 
			result  = MyBase::writeMessageBegin_virt(name, messageType, origSeqId);
			m_seqIdMutex.unlock();
		}
		else
		{
			// In thrift, T_CALL operations are always accomplished as follows:
			// send_function();
			// recv_function();
			// We are modifying the seq ID in the send so we can match it
			// with the one received, but we must block at the base of the
			// recv_function() call.  Therefore, we must lock the mutex so that
			// the recv_function() knows what seqId it is waiting for since it
			// is not passed back (ideally we would prefer 
			// recv_function(send_function()) where send_function returns the 
			// seqId it used.
			m_seqIdMutex.lock();
			m_bLocked = true;

			// C++ thrift doesn't use the seqId, create one so we can route
			// data back to the caller without blocking
			++m_seqId;
			try
			{
				// Insert this seqId as something to be looked for
				m_responseMutex.lock();
				m_responseMap.insert(typename ResponseMap::value_type(m_seqId, std::shared_ptr<ResponseInfo>(new ResponseInfo())));
				m_responseMutex.unlock();

				result =  MyBase::writeMessageBegin_virt(
					name,
					::apache::thrift::protocol::T_CALL,
					m_seqId
				);
			}
			catch (...)
			{
				m_responseMutex.unlock();// m_seqIdMutex.unlock();
				throw;
			}
		}
		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::writeMessageEnd_virt()
	{
		uint32_t result = MyBase::writeMessageEnd_virt();

		apache::thrift::protocol::TBinaryProtocolT<Transport_, ByteOrder_>::trans_->flush();

		// Unlock the mutex to allow other threads to make calls
		m_writeMutex.unlock();

		m_outstandingRequests++;
		m_newRequestEvent.signal();

		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readMessageBegin_virt(std::string& name, ::apache::thrift::protocol::TMessageType& messageType, int32_t& seqId)
	{
		startReader();

		int32_t waitingForSeqId = 0;

		// Unlock the mutex to allow others to call.  See notes in writeMessageBegin_virt
		if (m_bLocked)
		{
			waitingForSeqId = m_seqId;
			m_bLocked = false;
			m_seqIdMutex.unlock();
		}

		typename ResponseMap::iterator it;
		{
			bool isSeqId = false;
			m_responseMutex.lock();
			it = m_responseMap.find(waitingForSeqId);
			isSeqId = m_responseMap.end() != it;
			m_responseMutex.unlock();
			if(!isSeqId)
			{
				throw std::runtime_error("Could not find sequence ID for message");
			}
		}

		while (it->second->isNull() && this->m_bRunning)
		{
			// Wait until the receiving thread gets this seqId
			Event::Event::waitForEvent(
				&it->second->m_respondEvent,
				RESPONSE_WAIT_PERIOD
			);
		}

		if (!this->m_bRunning)
		{
			//LOG_INFO(m_pLogger, "ThreadedClientProtocol readMessageBegin_virt stopped.");
			return 0;
		}

		if (!it->second->m_pResponse->isNull())
		{
			// Lock the read so only this thread can read off m_pResponse
			m_readMutex.lock();
		}

		Buffer::Buffer<uint8_t>* pResponse = it->second->m_pResponse;
		m_responseMutex.lock();
		// Remove this seqId from being looked for
		m_responseMap.erase(it);
		m_responseMutex.unlock();
		
		if (pResponse->isNull())
		{
			// This means the port is shutting down
			return 0;
		}
		
		if (this->m_pResponse != nullptr)
		{
			delete this->m_pResponse; //causing heap failure
			this->m_pResponse = nullptr;
		}

		this->m_pResponse = new Buffer::Buffer<uint8_t>(*pResponse);
		//this->m_pResponse = pResponse;
		//m_pResponse.release();
		//m_pResponse.reset(new Buffer::Buffer<uint8_t>(*pResponse));

		delete pResponse;

		int32_t header;
		uint32_t result = readI32_virt(header);

		int32_t version = header & MyBase::VERSION_MASK;
		if (MyBase::VERSION_1 != version)
		{
			throw std::runtime_error("Bad Thrift version identifier");
		}

		messageType = static_cast<apache::thrift::protocol::TMessageType>(
			header & 0x000000ff
			);

		result += readString_virt(name);

		result += readI32_virt(seqId);

		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readMessageEnd_virt()
	{
		m_readMutex.unlock();
		return 0;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readStructBegin_virt(std::string& name)
	{
		name.clear();
		return 0;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readStructEnd_virt()
	{
		return 0;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readFieldBegin_virt(std::string& name, ::apache::thrift::protocol::TType& fieldType, int16_t& fieldId)
	{
		int8_t type;
		uint32_t result = readByte_virt(type);
		fieldType = static_cast<::apache::thrift::protocol::TType>(type);

		if (::apache::thrift::protocol::TType::T_STOP == fieldType)
		{
			fieldId = 0;
			return result;
		}

		result += readI16_virt(fieldId);
		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readFieldEnd_virt()
	{
		return 0;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readMapBegin_virt(::apache::thrift::protocol::TType& keyType, ::apache::thrift::protocol::TType& valType, uint32_t& size)
	{
		int8_t keyT;
		int8_t valueT;
		uint32_t result = readByte_virt(keyT);
		result += readByte_virt(valueT);
		int32_t containerSize;
		result += readI32_virt(containerSize);
		/*if (containerSize <= 0)
		{
			throw std::runtime_error("Negative container size in Thrift");
		}*/
		/*if(MyBase::container_limit_ == 0 || containerSize <= MyBase::container_limit_)
		{
			throw std::runtime_error("Container size limit exceeded in Thrift");
		}*/
		size = static_cast<uint32_t>(containerSize);
		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readMapEnd_virt()
	{
		return 0;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readListBegin_virt(::apache::thrift::protocol::TType& elemType, uint32_t& size)
	{
		int8_t elementType;
		uint32_t result = readByte_virt(elementType);
		elemType = static_cast<::apache::thrift::protocol::TType>(elementType);
		int32_t containerSize;
		result += readI32_virt(containerSize);
		/*if (containerSize <= 0)
		{
			throw std::runtime_error("Negative container size in Thrift");
		}*/
		/*if (MyBase::container_limit_ == 0 || containerSize <= MyBase::container_limit_)
		{
			throw std::runtime_error("Container size limit exceeded in Thrift");
		}*/
		size = static_cast<uint32_t>(containerSize);

		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readListEnd_virt()
	{
		return 0;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readSetBegin_virt(::apache::thrift::protocol::TType& elemType, uint32_t& size)
	{
		int8_t elementType;
		uint32_t result = readByte_virt(elementType);
		elemType = static_cast<::apache::thrift::protocol::TType>(elementType);
		int32_t containerSize;
		result += readI32_virt(containerSize);
		/*if (containerSize <= 0)
		{
			throw std::runtime_error("Negative container size in Thrift");
		}*/
		/*if (MyBase::container_limit_ == 0 || containerSize <= MyBase::container_limit_)
		{
			throw std::runtime_error("Container size limit exceeded in Thrift");
		}*/
		size = static_cast<uint32_t>(containerSize);

		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readSetEnd_virt()
	{
		return 0;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readBool_virt(bool& value)
	{
		int8_t byte;
		uint32_t result = readByte_virt(byte);
		value = 0 != byte;
		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readBool_virt(std::vector<bool>::reference value)
	{
		return readBool_virt(value);
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readByte_virt(int8_t& byte)
	{
		return static_cast<uint32_t>(
			m_pResponse->read(
				reinterpret_cast<uint8_t*>(&byte),
				sizeof(byte)
			)
		);
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readI16_virt(int16_t& i16)
	{
		return static_cast<uint32_t>(
			m_pResponse->read(
				reinterpret_cast<uint8_t*>(&i16),
				sizeof(i16)
			)
		);
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readI32_virt(int32_t& i32)
	{
		return static_cast<uint32_t>(
			m_pResponse->read(
				reinterpret_cast<uint8_t*>(&i32),
				sizeof(i32)
			)
		);
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readI64_virt(int64_t& i64)
	{
		return static_cast<uint32_t>(
			m_pResponse->read(
				reinterpret_cast<uint8_t*>(&i64),
				sizeof(i64)
			)
		);
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readDouble_virt(double& dub)
	{
		return static_cast<uint32_t>(
			m_pResponse->read(
				reinterpret_cast<uint8_t*>(&dub),
				sizeof(dub)
			)
		);
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readString_virt(std::string& str)
	{
		int32_t length;
		uint32_t result = readI32_virt(length);

		/*if (length <= 0)
		{
			throw std::runtime_error("Negative container size in Thrift");
		}*/
		/*if (0 >= MyBase::string_limit_ || MyBase::string_limit_ >= length)
		{
			throw std::runtime_error("Container size limit exceeded in Thrift");
		}*/

		str.resize(length);
		result += static_cast<uint32_t>(
			m_pResponse->read(reinterpret_cast<uint8_t*>(&str[0]), length)
			);
		return result;
	}

	template<class Transport_, class ByteOrder_>
	uint32_t QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readBinary_virt(std::string& str)
	{
		return readString_virt(str);
	}

	// -------------------------------------------------------------------------
    // readMessage
    //
    /// Reads a message in from the port and saves it in the buffer
    // -------------------------------------------------------------------------
	template<class Transport_, class ByteOrder_>
	void QutsThreadedBinaryProtocol<Transport_, ByteOrder_>::readMessage(::apache::thrift::protocol::TType type, Buffer::Buffer<uint8_t>* pBuffer)
	{
		switch (type)
		{
		case apache::thrift::protocol::T_BOOL:
		case apache::thrift::protocol::T_I08:
		{
			std::size_t offset = pBuffer->size();
			pBuffer->resize(sizeof(int8_t));
			MyBase::readByte(*reinterpret_cast<int8_t*>(pBuffer->begin() + offset));
		}
		break;
		case apache::thrift::protocol::T_I16:
		{
			std::size_t offset = pBuffer->size();
			pBuffer->resize(sizeof(int16_t));
			MyBase::readI16(*reinterpret_cast<int16_t*>(pBuffer->begin() + offset));
		}
		break;
		case apache::thrift::protocol::T_I32:
		{
			std::size_t offset = pBuffer->size();
			pBuffer->resize(sizeof(int32_t));
			MyBase::readI32(*reinterpret_cast<int32_t*>(pBuffer->begin() + offset));
		}
		break;
		case apache::thrift::protocol::T_I64:
		{
			std::size_t offset = pBuffer->size();
			pBuffer->resize(sizeof(int64_t));
			MyBase::readI64(*reinterpret_cast<int64_t*>(pBuffer->begin() + offset));
		}
		break;
		case apache::thrift::protocol::T_DOUBLE:
		{
			std::size_t offset = pBuffer->size();
			pBuffer->resize(sizeof(double));
			MyBase::readDouble(*reinterpret_cast<double*>(pBuffer->begin() + offset));
		}
		break;
		case apache::thrift::protocol::T_STRING:
		{
			std::size_t offset = pBuffer->size();
			std::string value;
			MyBase::readString(value);
			pBuffer->resize(sizeof(int32_t) + value.size());
			*reinterpret_cast<int32_t*>(pBuffer->begin() + offset) = value.size();
			memcpy( pBuffer->begin() + offset + sizeof(int32_t), value.c_str(), value.size());
		}
		break;
		case apache::thrift::protocol::T_STRUCT:
		{
			std::string name;
			MyBase::readStructBegin(name);

			int16_t fid;
			apache::thrift::protocol::TType fieldType;
			while (true)
			{
				std::size_t offset = pBuffer->size();
				MyBase::readFieldBegin(name, fieldType, fid);

				pBuffer->resize(sizeof(int8_t));
				*reinterpret_cast<int8_t*>(pBuffer->begin() + offset) =
					static_cast<int8_t>(fieldType);
				offset += sizeof(int8_t);

				if (apache::thrift::protocol::T_STOP == fieldType)
				{
					break;
				}

				pBuffer->resize(sizeof(int16_t));
				*reinterpret_cast<int16_t*>(pBuffer->begin() + offset) =
					static_cast<int16_t>(fid);

				readMessage(fieldType, pBuffer);
				MyBase::readFieldEnd();
			}

			MyBase::readStructEnd();
		}
		break;
		case apache::thrift::protocol::T_MAP:
		{
			apache::thrift::protocol::TType keyType;
			apache::thrift::protocol::TType valueType;
			uint32_t size;
			MyBase::readMapBegin(keyType, valueType, size);

			std::size_t offset = pBuffer->size();
			pBuffer->resize(
				+ sizeof(int8_t)
				+ sizeof(int8_t)
				+ sizeof(uint32_t)
			);
			*reinterpret_cast<int8_t*>(pBuffer->begin() + offset) = static_cast<int8_t>(keyType);
			*reinterpret_cast<int8_t*>(pBuffer->begin() + offset + sizeof(int8_t)) = static_cast<int8_t>(valueType);
			*reinterpret_cast<uint32_t*>(pBuffer->begin() + offset + sizeof(int8_t) + sizeof(int8_t)) = size;

			for (uint32_t i = 0; i < size; ++i)
			{
				readMessage(keyType, pBuffer);
				readMessage(valueType, pBuffer);
			}
			MyBase::readMapEnd();
		}
		break;
		case apache::thrift::protocol::T_SET:
		{
			apache::thrift::protocol::TType elemType;
			uint32_t size;
			MyBase::readSetBegin(elemType, size);

			std::size_t offset = pBuffer->size();
			pBuffer->resize(sizeof(int8_t) + sizeof(uint32_t));
			*reinterpret_cast<int8_t*>(pBuffer->begin() + offset) = static_cast<int8_t>(elemType);
			*reinterpret_cast<uint32_t*>(pBuffer->begin() + offset + sizeof(int8_t)) = size;

			for (uint32_t i = 0; i < size; ++i)
			{
				readMessage(elemType, pBuffer);
			}
			MyBase::readSetEnd();
		}
		break;
		case apache::thrift::protocol::T_LIST:
		{
			apache::thrift::protocol::TType elemType;
			uint32_t size;
			MyBase::readListBegin(elemType, size);

			size_t offset = pBuffer->size();
			pBuffer->resize(sizeof(int8_t) + sizeof(uint32_t));
			*reinterpret_cast<int8_t*>(pBuffer->begin() + offset) = static_cast<int8_t>(elemType);
			*reinterpret_cast<uint32_t*>(pBuffer->begin() + offset + sizeof(int8_t)) = size;

			for (uint32_t i = 0; i < size; ++i)
			{
				readMessage(elemType, pBuffer);
			}
			MyBase::readListEnd();
		}
		break;
		}
	}

}