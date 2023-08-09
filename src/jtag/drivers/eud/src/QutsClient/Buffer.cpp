/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "Buffer.h"
namespace Buffer
{
	template<typename T>
	Buffer<T>::Buffer()
	{
		try
		{
			this->m_buffer = nullptr;
			this->m_size = 0;
			this->m_position = 0;
			this->m_size = 0;
			this->m_totalSize = DEFAULT_INIT_SIZE;
			this->m_buffer = (T*)calloc(DEFAULT_INIT_SIZE, sizeof(T)); //allocate extra copy of size size 
		}
		catch (std::exception ex)
		{
			throw ex;
		}
	}

	template<typename T>
	Buffer<T>::Buffer(const Buffer& buffer)
	{
		this->m_buffer = nullptr;
		this->m_size = buffer.m_size;
		this->m_position = buffer.m_position;
		this->m_totalSize = buffer.m_totalSize;
		this->m_buffer = (T*)calloc(buffer.m_size + 1, sizeof(T));
		errno_t err = memcpy_s(this->m_buffer, this->m_size, buffer.m_buffer, buffer.m_size); //deep copy the data 
		if (err != 0)
		{
			throw std::runtime_error("failed to calloc the memory");
		}	
	}

	template<typename T>
	Buffer<T>::~Buffer()
	{
		if (this->m_buffer != nullptr)
		{
			free(this->m_buffer);
			this->m_buffer = nullptr;
		}
		this->m_size = 0;
		this->m_position = 0;
		this->m_totalSize = 0;
	}

	template<typename T>
	std::size_t Buffer<T>::size()
	{
		return this->m_size;
	}

	template<typename T>
	void Buffer<T>::resize(std::size_t newSize)
	{
		try
		{
			this->m_size += newSize;
			if (this->m_totalSize <= this->m_size)
			{
				this->m_totalSize = this->m_totalSize * 2; //double the size
				T* newBuffer = nullptr;
				newBuffer = (T*)realloc(this->m_buffer, this->m_totalSize);
				if (m_size != 0)
				{
					if (newBuffer == nullptr)
					{
						throw std::runtime_error("unable to realloc the memory");
					}
				}
				this->m_buffer = newBuffer;
			}
		}
		catch (std::runtime_error ex)
		{
			throw ex;
		}
	}

	template<typename T>
	std::size_t Buffer<T>::read(T* ptr, size_t size)
	{
		try
		{
			memcpy(this->m_buffer + this->m_position, ptr, size);
			this->m_position += size;
		}
		catch (std::runtime_error ex)
		{
			throw ex;
		}
		return size;
	}

	template<typename T>
	T* Buffer<T>::begin()
	{
		return this->m_buffer;
	}

	template<typename T>
	bool Buffer<T>::isNull()
	{
		return this->m_buffer == nullptr;;
	}
}