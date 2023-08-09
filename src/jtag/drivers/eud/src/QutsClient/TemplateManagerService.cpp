/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "TemplateManagerService.h"

namespace TemplateManagerService
{
	template<typename T1>
	inline TemplateManagerService<T1>::TemplateManagerService(const std::shared_ptr<QutsClient::QutsClient> client, const::Uts::DeviceInfo& deviceInfo, const::Uts::ProtocolInfo& protocolInfo)
	{
		if (client == nullptr && client.get() == nullptr)
		{
			throw std::runtime_error("invalid quts client object detected. please create quts client.");
		}
		else if (deviceInfo.deviceHandle <= 0)
		{
			throw std::runtime_error("invalid device handle found. please provide device handle.");
		}
		else if (protocolInfo.protocolHandle <= 0)
		{
			throw std::runtime_error("invalid protocol handle found. please provide protocol handle.");
		}
		m_client = client;
		m_deviceInfo = deviceInfo;
		m_protocolInfo = protocolInfo;
	}

	template<typename T1>
	inline TemplateManagerService<T1>::~TemplateManagerService()
	{
		m_client = nullptr;
		if (m_templateServiceClient != nullptr) {
			if (m_templateServiceClient.get() != nullptr) {
				m_templateServiceClient.reset();
			}
		}
	}

	template<typename T1>
	inline ::Uts::ProtocolInfo TemplateManagerService<T1>::getProtocolInfo()
	{
		return m_protocolInfo;
	}

	template<typename T1>
	inline ::Uts::DeviceInfo TemplateManagerService<T1>::getDeviceInfo()
	{
		return m_deviceInfo;
	}

	template<typename T1>
	inline std::shared_ptr<T1> TemplateManagerService<T1>::getTemplateServiceClient()
	{
		return m_templateServiceClient;
	}

	template<typename T1>
	inline bool TemplateManagerService<T1>::createService(std::string serviceName)
	{
		bool success = false;
		try
		{
			m_templateServiceClient = std::shared_ptr<T1>(new T1(
				m_client->createService(serviceName, m_protocolInfo.deviceHandle)));
			if (m_templateServiceClient != nullptr && m_templateServiceClient.get() != nullptr) {
				success = true;
			}
		}
		catch (std::exception ex)
		{
			throw ex;
		}
		return success;
	}
}