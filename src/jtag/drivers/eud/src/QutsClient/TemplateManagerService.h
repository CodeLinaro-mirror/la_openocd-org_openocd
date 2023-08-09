/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#pragma once
#include <iostream>
#include "QutsClient.h"
namespace TemplateManagerService
{
	template<typename T1>
	class TemplateManagerService
	{
	public:
		TemplateManagerService() = delete;
		TemplateManagerService(const TemplateManagerService&) = delete;
		TemplateManagerService(const std::shared_ptr<QutsClient::QutsClient> client, const ::Uts::DeviceInfo& deviceInfo, const ::Uts::ProtocolInfo& protocolInfo);
		~TemplateManagerService();

		bool createService(std::string serviceName);

		::Uts::ProtocolInfo getProtocolInfo();
		::Uts::DeviceInfo getDeviceInfo();

		std::shared_ptr<T1> getTemplateServiceClient();
	private:
		std::shared_ptr<QutsClient::QutsClient> m_client;
		::Uts::DeviceInfo m_deviceInfo;
		::Uts::ProtocolInfo m_protocolInfo;
		bool m_serviceInitalized;

		std::shared_ptr<T1> m_templateServiceClient;
		//Uts::ProfilingServiceConstants m_profilingServiceConstants;
	};
}

