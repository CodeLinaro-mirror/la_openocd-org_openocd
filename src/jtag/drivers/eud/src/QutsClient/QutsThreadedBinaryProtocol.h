/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#pragma once
#include <atomic>
#include <memory>
#include <mutex>
#include <thread>
#include <condition_variable>
#include "Event.h"
#include "Buffer.h"
#include "Buffer.cpp"
#include <thrift/protocol/TBinaryProtocol.h>

namespace QutsThreadedBinaryProtocol
{
	class ResponseInfo
	{
	public:
		ResponseInfo() 
		{
			m_pResponse = nullptr;
		}

		bool isNull()
		{
			return m_pResponse == nullptr;
		}

		Event::Event m_respondEvent;
		Buffer::Buffer<uint8_t>* m_pResponse;
	};

	typedef std::shared_ptr<ResponseInfo> ResponseInfoPtr;
	typedef std::map<int32_t, ResponseInfoPtr> ResponseMap;

	template <class Transport_, class ByteOrder_ = apache::thrift::protocol::TNetworkBigEndian>
	class QutsThreadedBinaryProtocol : public apache::thrift::protocol::TBinaryProtocolT<Transport_, ByteOrder_>
	{
	public:
		typedef apache::thrift::protocol::TBinaryProtocolT<Transport_, ByteOrder_> MyBase;

		QutsThreadedBinaryProtocol(const std::shared_ptr<Transport_>& pTransport);
		QutsThreadedBinaryProtocol() = delete; // will never be generated
		QutsThreadedBinaryProtocol(const QutsThreadedBinaryProtocol&) = delete; // Disable Copy Constructor
		QutsThreadedBinaryProtocol& operator=(const QutsThreadedBinaryProtocol&) = delete; // Disable Assignment Operator
		virtual ~QutsThreadedBinaryProtocol();

		bool isStopSignaled();
		void startReader();
		void stopReader();
		void onRun();

		virtual uint32_t writeMessageBegin_virt(const std::string& name, const ::apache::thrift::protocol::TMessageType messageType, const int32_t origSeqId) override;
		virtual uint32_t writeMessageEnd_virt() override;
		virtual uint32_t readMessageBegin_virt(std::string& name, ::apache::thrift::protocol::TMessageType& messageType, int32_t& seqId) override;
		virtual uint32_t readMessageEnd_virt() override;
		virtual uint32_t readStructBegin_virt(std::string& name) override;
		virtual uint32_t readStructEnd_virt() override;
		virtual uint32_t readFieldBegin_virt(std::string& name, ::apache::thrift::protocol::TType& fieldType, int16_t& fieldId) override;
		virtual uint32_t readFieldEnd_virt() override;
		virtual uint32_t readMapBegin_virt(::apache::thrift::protocol::TType& keyType, ::apache::thrift::protocol::TType& valType, uint32_t& size) override;
		virtual uint32_t readMapEnd_virt() override;
		virtual uint32_t readListBegin_virt(::apache::thrift::protocol::TType& elemType, uint32_t& size) override;
		virtual uint32_t readListEnd_virt() override;
		virtual uint32_t readSetBegin_virt(::apache::thrift::protocol::TType& elemType, uint32_t& size) override;
		virtual uint32_t readSetEnd_virt() override;
		virtual uint32_t readBool_virt(bool& value) override;
		virtual uint32_t readBool_virt(std::vector<bool>::reference value) override;
		virtual uint32_t readByte_virt(int8_t& byte) override;
		virtual uint32_t readI16_virt(int16_t& i16) override;
		virtual uint32_t readI32_virt(int32_t& i32) override;
		virtual uint32_t readI64_virt(int64_t& i64) override;
		virtual uint32_t readDouble_virt(double& dub) override;
		virtual uint32_t readString_virt(std::string& str) override;
		virtual uint32_t readBinary_virt(std::string& str) override;

	private:
		ResponseMap						m_responseMap;          ///< Threads waiting for responses
		std::mutex						m_responseMutex;        ///< Protects m_responseMap
		volatile int32_t				m_seqId;
		// Agnelo std::atomic<volatile int32_t>   m_outstandingRequests;
		std::atomic<int32_t>   m_outstandingRequests;
		Event::Event					m_newRequestEvent;
		std::mutex						m_seqIdMutex;
		volatile bool					m_bLocked;
		volatile bool					m_bRunning;
		std::mutex						m_writeMutex;  ///< Ensure only one thread writes at a time
		std::mutex						m_readMutex;   ///< Ensure only one thread reads at a time
		//std::unique_ptr<Buffer::Buffer<uint8_t>>		m_pResponse;   ///< Response payload
		Buffer::Buffer<uint8_t>*		m_pResponse;   ///< Response payload
		std::shared_ptr<std::thread>	m_pThread;     ///< Thread that read the port

		void readMessage(::apache::thrift::protocol::TType type, Buffer::Buffer<uint8_t>* pBuffer);
	};
}