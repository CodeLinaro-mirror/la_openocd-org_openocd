/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#pragma once
#include <memory>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TTransportUtils.h>
#include <thrift/protocol/TMultiplexedProtocol.h>
#include <thrift/processor/TMultiplexedProcessor.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/protocol/TMultiplexedProtocol.h>

#if 0
#include "ThriftGenFiles/DeviceManager.h"
#include "ThriftGenFiles/UtilityService.h"
#include "ThriftGenFiles/LogSession.h"
#include "ClientCallbackServer.h"
#include "ThriftGenFiles/QutsService_constants.h"
#include "ThriftGenFiles/DeviceManager_constants.h"
#include "ThriftGenFiles/UtilityService_constants.h"
#include "ThriftGenFiles/ClientCallback_constants.h"
#include "ThriftGenFiles/UtsClientManager_types.h"
#include "ThriftGenFiles/Common_types.h"
#include "ThriftGenFiles/UtsClientManager_constants.h"
#include "ThriftGenFiles/QutsService.h"
#include "ThriftGenFiles/UtsClientManager.h"
#else
#include "DeviceManager.h"
#include "UtilityService.h"
#include "LogSession.h"
#include "ClientCallbackServer.h"
#include "QutsService_constants.h"
#include "DeviceManager_constants.h"
#include "UtilityService_constants.h"
#include "ClientCallback_constants.h"
#include "UtsClientManager_types.h"
#include "Common_types.h"
#include "UtsClientManager_constants.h"
#include "QutsService.h"
#include "UtsClientManager.h"
#endif


namespace QutsClient
{
    class ServerClientSocket : public apache::thrift::server::TServerTransport
    {
    public:
        ServerClientSocket(std::string hostname, int port)
        {
            m_socket = std::make_shared<apache::thrift::transport::TSocket>(apache::thrift::transport::TSocket(hostname, port));
            m_socket->open();
        };

        virtual void listen()
        {
        }

        virtual void close()
        {
            m_socket->close();
        }

        virtual void interrupt() 
        {
            close();
        }

        virtual void interruptChildren()
        {
            close();
        }

    protected:
        virtual std::shared_ptr<apache::thrift::transport::TTransport>  acceptImpl()
        {
            if (!m_socket->isOpen())
            {
                throw apache::thrift::transport::TTransportException(apache::thrift::transport::TTransportException::TTransportExceptionType::INTERRUPTED, "Terminate the callback server");
            }
            return m_socket;
        }

        std::shared_ptr<apache::thrift::transport::TSocket> m_socket;
    };

    enum class OperatingSystem 
    {
        WIN_32,
        WIN_64,
        UNIX,
        LINUX,
        OSX,
        FREEBSD,
        OTHER
    };

	class QutsClient
	{
    public:
        QutsClient() = delete; // will never be generated
        QutsClient(const QutsClient&) = delete; // Disable Copy Constructor
        QutsClient& operator=(const QutsClient&) = delete; // Disable Assignment Operator

        QutsClient( 
            Uts::ClientInfo& clientInfo, 
            std::string = "localhost", 
            int port = 50089, 
            bool multiThreadedClient = false, 
            bool disableQutsSignalHandler = false,
            ::Uts::QutsOperatingMode::type qutsOperatingMode = ::Uts::QutsOperatingMode::DEVICE_DISCOVERY
            );
        virtual ~QutsClient();

        std::shared_ptr<apache::thrift::protocol::TMultiplexedProtocol> createService(const std::string& serviceName, const int64_t deviceHandle);

        std::shared_ptr<Uts::UtilityServiceClient> getUtilityService();
        std::shared_ptr<Uts::DeviceManagerClient> getDeviceManager();
        std::shared_ptr<Uts::LogSessionClient> openLogSession(std::vector<std::string> logList);
        std::shared_ptr<Uts::LogSessionClient> getActiveLogSession();

        void getClientNames(std::vector<std::string>& clientNames);

        std::string getActiveQutsServicePortFile();
        OperatingSystem getOsType();

        void clearCallbacks();
        void setMessageCallback(const ClientCallbackServer::ClientCallbackServer::MessageCallback& callback);
        void setDeviceConnectedCallback(const ClientCallbackServer::ClientCallbackServer::DeviceConnectedCallback& callback);
        void setDeviceDisconnectedCallback(const ClientCallbackServer::ClientCallbackServer::DeviceDisconnectedCallback& callback);
        void setDeviceModeChangeCallback(const ClientCallbackServer::ClientCallbackServer::DeviceModeChangeCallback& callback);
        void setProtocolAddedCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolAddedCallback &callback);
        void setProtocolRemovedCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolRemovedCallback& callback);
        void setProtocolStateChangeCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolStateChangeCallback& callback);
        void setProtocolFlowControlStatusChangeCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolFlowControlStatusChangeCallback& callback);
        void setProtocolLockStatusChangeCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolLockStatusChangeCallback& callback);
        void setProtocolMbnDownloadStatusChangeCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolMbnDownloadStatusChangeCallback& callback);
        void setClientCloseRequestCallback(const ClientCallbackServer::ClientCallbackServer::ClientCloseRequestCallback& callback);
        void setMissingQShrinkHashFileCallback(const ClientCallbackServer::ClientCallbackServer::MissingQShrinkHashFileCallback& callback);
        void setLogSessionMissingQShrinkHashFileCallback(const ClientCallbackServer::ClientCallbackServer::LogSessionMissingQShrinkHashFileCallback& callback);
        void setAsyncResponseCallback(const ClientCallbackServer::ClientCallbackServer::AsyncResponseCallback& callback);
        void setDataQueueUpdatedCallback(const ClientCallbackServer::ClientCallbackServer::DataQueueUpdatedCallback& callback);
        void setDataViewUpdatedCallback(const ClientCallbackServer::ClientCallbackServer::DataViewUpdatedCallback& callback);
        void setServiceAvailableCallback(const ClientCallbackServer::ClientCallbackServer::ServiceAvailableCallback& callback);
        void setServiceEndedCallback(const ClientCallbackServer::ClientCallbackServer::ServiceEndedCallback& callback);
        void setServiceEventCallback(const ClientCallbackServer::ClientCallbackServer::ServiceEventCallback& callback);
        void setImageManagementServiceEventCallback(const ClientCallbackServer::ClientCallbackServer::ImageManagementServiceEventCallback& callback);
        void setDeviceConfigServiceEventCallback(const ClientCallbackServer::ClientCallbackServer::DeviceConfigServiceEventCallback& callback);
        void setQShrinkStateUpdatedCallback(const ClientCallbackServer::ClientCallbackServer::QShrinkStateUpdatedCallback& callback);
        void setDecryptionKeyStatusUpdateCallback(const ClientCallbackServer::ClientCallbackServer::DecryptionKeyStatusUpdateCallback& callback);
        void setLogSessionDecryptionKeyStatusUpdateCallback(const ClientCallbackServer::ClientCallbackServer::LogSessionDecryptionKeyStatusUpdateCallback& callback);

    private:
        std::string m_hostname;
        std::string m_clientname;

        int32_t m_clientport;
        int32_t m_applicationPort;

        bool m_multiThreadedClient;
        bool m_disableQutsSignalHandler;

        ::Uts::QutsOperatingMode::type m_qutsOperatingMode;

        std::shared_ptr<Uts::DeviceManagerClient> m_deviceManager;
        std::shared_ptr<Uts::UtilityServiceClient> m_utilityService;
        std::shared_ptr<apache::thrift::protocol::TBinaryProtocol>  m_binProtocol;
        std::shared_ptr<apache::thrift::transport::TSocket> m_socket;
        std::shared_ptr<ClientCallbackServer::ClientCallbackServer> m_clientCallbackServer;
        std::shared_ptr<Uts::ClientCallbackProcessor> m_clientCallbackProcessor;
        std::shared_ptr<ServerClientSocket> m_transport;

        Uts::QutsServiceConstants m_qutsServiceConstants;
        Uts::DeviceManagerConstants m_deviceManagerConstants;
        Uts::UtilityServiceConstants m_utilityServiceConstants;
        Uts::ClientCallbackConstants m_clientCallbackConstants;
        Uts::UtsClientManagerConstants m_utsClientManagerConstants;

        std::shared_ptr<apache::thrift::server::TServer> m_callbackServer;
        std::shared_ptr<apache::thrift::server::TServerEventHandler> m_eventHandler;

        std::shared_ptr<std::thread> m_callbackThread;
        std::shared_ptr<apache::thrift::TMultiplexedProcessor> m_callbackProcessor;


        void stopMultiThreadedClient();
	};
}

