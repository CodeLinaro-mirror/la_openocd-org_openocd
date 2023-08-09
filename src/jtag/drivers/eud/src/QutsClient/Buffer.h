/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#pragma once
#include <iostream>
#include <list>
#include <stdint.h>
namespace Buffer
{
	static const uint32_t DEFAULT_INIT_SIZE =  1024 * 1024 * 10;  // 10K bytes

	template<typename T>
	class Buffer
	{
	private:
		std::size_t m_size;
		T* m_buffer;
		std::size_t m_position;
		std::size_t m_totalSize;
	public:
		Buffer();
		Buffer(const Buffer&);
		~Buffer();
		std::size_t size();
		void resize(size_t newSize);
		std::size_t  read(T* ptr, size_t size);
		T* begin();
		bool isNull();
	};
}

