/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "QutsClient.h"
#include <stdexcept>
#include <fstream>
#include <sstream>
#include "QutsThreadedBinaryProtocol.h"
#include "QutsThreadedBinaryProtocol.cpp"
#include "ServerEventHandler.h"

#if defined __linux__ || __APPLE__
#include <thread>
#include <unistd.h>
#include <pwd.h>
#endif

namespace QutsClient
{
	static const std::size_t DEFAULT_WRITE_BUFFER_SIZE = (512 * 1024);
	static const std::size_t DEFAULT_READ_BUFFER_SIZE = (512 * 1024);
	static const std::size_t DEFAULT_CONNECTION_TIMEOUT = 30000;
	static const std::size_t BUFF_SIZE = 1024;

	QutsClient::QutsClient(
		Uts::ClientInfo& clientInfo, 
		std::string hostname, 
		int port,
		bool multiThreadedClient,
		bool disableQutsSignalHandler,
		::Uts::QutsOperatingMode::type qutsOperatingMode
	)
	{
		bool neededSecureClient = false;
		m_clientname = clientInfo.clientName;
		m_hostname = hostname;
		m_multiThreadedClient = multiThreadedClient;
		m_disableQutsSignalHandler = disableQutsSignalHandler;
		m_qutsOperatingMode = qutsOperatingMode;

		bool neededToUseFile = false;

		m_clientport = m_qutsServiceConstants.UTS_INVALID_LICENSE_ERROR_CODE;
		std::shared_ptr<apache::thrift::transport::TTransport> socket = nullptr;
		std::shared_ptr<apache::thrift::transport::TBufferedTransport> transport = nullptr;

		try
		{
			socket = std::shared_ptr<apache::thrift::transport::TTransport>(new apache::thrift::transport::TSocket(hostname, port));
			transport = std::shared_ptr<apache::thrift::transport::TBufferedTransport>(new apache::thrift::transport::TBufferedTransport(socket, DEFAULT_READ_BUFFER_SIZE, DEFAULT_WRITE_BUFFER_SIZE));
			transport->open();
		}
		catch (apache::thrift::transport::TTransportException ex)
		{
			//ignore the exception beacause we have file read option.
			neededToUseFile = true;
		}

		if (neededToUseFile)
		{
			try
			{
				if (socket.get() != nullptr)
				{
					socket->close();
					socket.reset();
				}
				if (transport.get() != nullptr)
				{
					transport->close();
					transport.reset();
				}

				std::ifstream inputfile(getActiveQutsServicePortFile()); //
				inputfile.seekg(0, std::ios::end);
				std::streampos length = inputfile.tellg();
				inputfile.seekg(0, std::ios::beg);
				//read file
				inputfile.read(reinterpret_cast<char*>(&port), sizeof(char));
				inputfile.close();
				socket = std::shared_ptr<apache::thrift::transport::TTransport>(new apache::thrift::transport::TSocket(hostname, port));
				transport = std::shared_ptr<apache::thrift::transport::TBufferedTransport>(new apache::thrift::transport::TBufferedTransport(socket, DEFAULT_READ_BUFFER_SIZE, DEFAULT_WRITE_BUFFER_SIZE));
				transport->open();

			}
			catch (apache::thrift::transport::TTransportException ex)
			{
				throw ex;
			}
		}

		std::shared_ptr<apache::thrift::protocol::TProtocol> protocol = std::shared_ptr<apache::thrift::protocol::TProtocol>(new apache::thrift::protocol::TBinaryProtocol(transport));
		std::shared_ptr<apache::thrift::protocol::TProtocol> tMulProtocol = std::shared_ptr<apache::thrift::protocol::TProtocol>(new apache::thrift::protocol::TMultiplexedProtocol(protocol, m_qutsServiceConstants.QUTS_SERVICE_NAME));
		std::shared_ptr<Uts::QutsServiceClient> qutsServiceClient = std::shared_ptr<Uts::QutsServiceClient>(new Uts::QutsServiceClient(tMulProtocol));

		if (!clientInfo.licenseKey.empty()) {
			neededSecureClient = true;
		}

#if defined __linux__ || __APPLE__
			Uts::ClientInfo linuxClientInfo = clientInfo;
			uid_t uid = geteuid();
			struct passwd* pInfo = getpwuid(uid);
			if (nullptr == pInfo) {
				throw std::runtime_error("No username found.");
			}
			linuxClientInfo.__set_username(pInfo->pw_name);
			if (neededSecureClient) {
				m_clientport = qutsServiceClient->registerSecureClient(linuxClientInfo);
			}
			else {
				m_clientport = qutsServiceClient->registerClient(clientInfo.clientName);
			}
#else 
		if (neededSecureClient) {
			m_clientport = qutsServiceClient->registerSecureClient(clientInfo);
		}
		else {
			m_clientport = qutsServiceClient->registerClient(clientInfo.clientName);
		}
#endif
		m_applicationPort = qutsServiceClient->getQutsApplicationPort();

		if (socket.get() != nullptr)
		{
			socket->close();
			socket.reset();
		}
		if (transport.get() != nullptr)
		{
			transport->close();
			transport.reset();
		}
		if (protocol.get() != nullptr)
		{
			protocol.reset();
		}
		if (tMulProtocol.get() != nullptr)
		{
			tMulProtocol.reset();
		}
		if (tMulProtocol.get() != nullptr)
		{
			tMulProtocol.reset();
		}
		if (qutsServiceClient.get() != nullptr)
		{
			qutsServiceClient.reset();
		}

		if (m_clientport == m_qutsServiceConstants.UTS_INVALID_LICENSE_ERROR_CODE)
			throw std::runtime_error("QUTS license is invalid.");

		if (m_clientport == m_qutsServiceConstants.UTS_DB_UPDATING_ERROR_CODE)
			throw std::runtime_error("QUTS is updating DB, please try connecting again later.");

		if (m_clientport == 0)
			throw std::runtime_error("Tried and failed to allocate client in Quts.");

		// creating client socket with port which retrun by service
		m_socket = std::shared_ptr<apache::thrift::transport::TSocket>(new apache::thrift::transport::TSocket(hostname, m_clientport));
		m_socket->setConnTimeout(DEFAULT_CONNECTION_TIMEOUT);

		transport = std::shared_ptr<apache::thrift::transport::TBufferedTransport>(new apache::thrift::transport::TBufferedTransport(m_socket, DEFAULT_READ_BUFFER_SIZE, DEFAULT_WRITE_BUFFER_SIZE));	

		this->m_binProtocol = m_multiThreadedClient == true ?
			std::shared_ptr<apache::thrift::protocol::TBinaryProtocol>(new QutsThreadedBinaryProtocol::QutsThreadedBinaryProtocol<apache::thrift::transport::TTransport>(transport)) :
			std::make_shared<apache::thrift::protocol::TBinaryProtocol>(std::shared_ptr<apache::thrift::transport::TTransport>(transport));

		std::shared_ptr<apache::thrift::protocol::TProtocol> deviceManagerProtocol = std::shared_ptr<apache::thrift::protocol::TProtocol>(new apache::thrift::protocol::TMultiplexedProtocol(this->m_binProtocol, m_deviceManagerConstants.DEVICE_MANAGER_SERVICE_NAME));
		std::shared_ptr<apache::thrift::protocol::TProtocol> utilityServiceProtocol = std::shared_ptr<apache::thrift::protocol::TProtocol>(new apache::thrift::protocol::TMultiplexedProtocol(this->m_binProtocol, m_utilityServiceConstants.UTILITY_SERVICE_NAME));

		transport->open();
		m_deviceManager = std::shared_ptr<Uts::DeviceManagerClient>(new Uts::DeviceManagerClient(deviceManagerProtocol));
		m_utilityService = std::shared_ptr<Uts::UtilityServiceClient>(new Uts::UtilityServiceClient(utilityServiceProtocol));

		// creating callback server 
		m_clientCallbackServer = std::make_shared<ClientCallbackServer::ClientCallbackServer>(ClientCallbackServer::ClientCallbackServer());
		m_callbackProcessor = std::shared_ptr<apache::thrift::TMultiplexedProcessor>(new apache::thrift::TMultiplexedProcessor());
		if (m_callbackProcessor.get() == nullptr)
		{
			throw std::runtime_error("unable to create callback processor");
		}

		m_clientCallbackProcessor = std::shared_ptr<Uts::ClientCallbackProcessor>(new Uts::ClientCallbackProcessor(m_clientCallbackServer));
		m_callbackProcessor->registerProcessor(m_clientCallbackConstants.CLIENT_CALLBACK_SERVICE_NAME, m_clientCallbackProcessor);

		int32_t callbackPort = m_clientport + Uts::ClientPortOffsets::PORT_CALLBACK_CLIENT;

		m_transport = std::shared_ptr<ServerClientSocket>(new ServerClientSocket(hostname, callbackPort));
		std::shared_ptr<apache::thrift::transport::TServerTransport> serverTransport = std::shared_ptr<apache::thrift::transport::TServerTransport>(m_transport);
		std::shared_ptr<apache::thrift::protocol::TProtocolFactory> protocolFactory = std::shared_ptr<apache::thrift::protocol::TProtocolFactory>(new apache::thrift::protocol::TBinaryProtocolFactory());
		std::shared_ptr<apache::thrift::transport::TTransportFactory> transportFactory = std::shared_ptr<apache::thrift::transport::TTransportFactory>(new apache::thrift::transport::TBufferedTransportFactory());
		
		m_callbackServer = std::shared_ptr<apache::thrift::server::TServer>(new apache::thrift::server::TSimpleServer(
			m_callbackProcessor,
			m_transport,
			transportFactory,
			protocolFactory
		));

		/*m_callbackServer = std::shared_ptr<apache::thrift::server::TServer>(new apache::thrift::server::TSimpleServer(
			m_callbackProcessor,
			m_transport,
			std::shared_ptr<apache::thrift::transport::TTransportFactory>(new apache::thrift::transport::TBufferedTransportFactory()),
			std::shared_ptr<apache::thrift::transport::TTransportFactory>(new apache::thrift::transport::TBufferedTransportFactory()),
			std::shared_ptr<apache::thrift::protocol::TProtocolFactory>(new apache::thrift::protocol::TBinaryProtocolFactory()),
			std::shared_ptr<apache::thrift::protocol::TProtocolFactory>(new apache::thrift::protocol::TBinaryProtocolFactory())
		));*/
		
		//m_eventHandler = std::shared_ptr<ServerEventHandler>(new ServerEventHandler(m_callbackServer.get()));
		//m_callbackServer->setServerEventHandler(m_eventHandler);
		m_callbackThread = std::make_shared<std::thread>(std::thread(std::bind(&apache::thrift::server::TServer::serve, m_callbackServer.get())));
	}

	QutsClient::~QutsClient()
	{
		stopMultiThreadedClient();

		clearCallbacks();

		if (m_deviceManager.get())
		{
			m_deviceManager.reset();
		}
		if (m_utilityService.get())
		{
			m_utilityService.reset();
		}
		if (m_clientCallbackServer.get())
		{
			m_clientCallbackServer.reset();
		}
		if (m_clientCallbackProcessor.get())
		{
			m_clientCallbackProcessor.reset();
		}
		if (m_callbackProcessor.get())
		{
			// Agnelo - Commented next line
			// m_callbackProcessor->unregisterProcessor(m_clientCallbackConstants.CLIENT_CALLBACK_SERVICE_NAME); //unregister callback server class
		}
		if (m_callbackServer.get())
		{
			m_callbackServer->stop();  // intruppt is not invoking
		}
		if (m_callbackThread.get())
		{
			m_callbackThread->join(); // join is blocked the thread.
		}
		if (m_socket.get())
		{
			m_socket->close();
		}
	}

	std::shared_ptr<apache::thrift::protocol::TMultiplexedProtocol> QutsClient::createService(const std::string& serviceName, const int64_t deviceHandle)
	{
		std::string identifier = "";
		m_deviceManager->createService(identifier, serviceName, deviceHandle);
		return std::shared_ptr<apache::thrift::protocol::TMultiplexedProtocol>(new apache::thrift::protocol::TMultiplexedProtocol(this->m_binProtocol, identifier));
	}

	std::shared_ptr<Uts::UtilityServiceClient> QutsClient::getUtilityService()
	{
		return m_utilityService;
	}

	std::shared_ptr<Uts::DeviceManagerClient> QutsClient::getDeviceManager()
	{
		return m_deviceManager;
	}

	std::shared_ptr<Uts::LogSessionClient> QutsClient::openLogSession(std::vector<std::string> logList)
	{
		std::string identifier = "";
		m_deviceManager->openLogSession(identifier, logList);
		std::shared_ptr<apache::thrift::protocol::TMultiplexedProtocol> protocol(new apache::thrift::protocol::TMultiplexedProtocol(this->m_binProtocol, identifier));
		return std::shared_ptr<Uts::LogSessionClient>(new Uts::LogSessionClient(protocol));
	}

	std::shared_ptr<Uts::LogSessionClient> QutsClient::getActiveLogSession()
	{
		std::string identifier = "";
		getDeviceManager()->getActiveLogSession(identifier);
		std::shared_ptr<apache::thrift::protocol::TMultiplexedProtocol> protocol(new apache::thrift::protocol::TMultiplexedProtocol(this->m_binProtocol, identifier));
		return std::shared_ptr<Uts::LogSessionClient>(new Uts::LogSessionClient(protocol));
	}

	void QutsClient::getClientNames(std::vector<std::string>& clientNames)
	{
		std::shared_ptr<apache::thrift::transport::TSocket> socket = std::shared_ptr<apache::thrift::transport::TSocket>(new apache::thrift::transport::TSocket(m_hostname, m_applicationPort));
		socket->setConnTimeout(DEFAULT_CONNECTION_TIMEOUT);
		std::shared_ptr<apache::thrift::transport::TBufferedTransport> transport = std::shared_ptr<apache::thrift::transport::TBufferedTransport>(new apache::thrift::transport::TBufferedTransport(socket, DEFAULT_READ_BUFFER_SIZE, DEFAULT_WRITE_BUFFER_SIZE));
		std::shared_ptr<apache::thrift::protocol::TBinaryProtocol> protocol = std::shared_ptr<apache::thrift::protocol::TBinaryProtocol>(new apache::thrift::protocol::TBinaryProtocol(transport));
		std::shared_ptr<apache::thrift::protocol::TProtocol> utsClientManagerProtocol = std::shared_ptr<apache::thrift::protocol::TProtocol>(new apache::thrift::protocol::TMultiplexedProtocol(protocol, m_utsClientManagerConstants.UTS_REGISTRATION_SERVICE_NAME));
		try
		{
			transport->open();
		}
		catch (apache::thrift::transport::TTransportException ex)
		{
			throw ex;
		}
		std::shared_ptr<Uts::UtsClientManagerClient> utsClientManager = std::shared_ptr<Uts::UtsClientManagerClient>(new Uts::UtsClientManagerClient(utsClientManagerProtocol));
		utsClientManager->getClientNames(clientNames);
		transport->close();
		socket->close();
		socket.reset();
		transport.reset();
		protocol.reset();
		utsClientManagerProtocol.reset();
		utsClientManager.reset();
	}

	void QutsClient::stopMultiThreadedClient()
	{
		if (m_multiThreadedClient)
		{
			if (m_binProtocol != nullptr)
			{
				QutsThreadedBinaryProtocol::QutsThreadedBinaryProtocol<apache::thrift::transport::TTransport>* threadedBinaryProtocol = (QutsThreadedBinaryProtocol::QutsThreadedBinaryProtocol<apache::thrift::transport::TTransport>*)m_binProtocol.get();
				if (threadedBinaryProtocol != nullptr)
				{
					threadedBinaryProtocol->stopReader();
				}
			}
		}
	}

	std::string QutsClient::getActiveQutsServicePortFile()
	{
#ifdef _WIN32
		return "C:\\ProgramData\\Qualcomm\\QUTS\\ActiveQutsServicePort";
#elif _WIN64
		return "C:\\ProgramData\\Qualcomm\\QUTS\\ActiveQutsServicePort";
#elif __APPLE__ || __MACH__
		return "/Library/Application Support/Qualcomm/QUTS/ActiveQutsServicePort";
#elif __linux__
		return "/opt/Qualcomm/QUTS/ActiveQutsServicePort";
#elif __FreeBSD__
		return "/opt/Qualcomm/QUTS/ActiveQutsServicePort";
#elif __unix || __unix__
		return "/opt/Qualcomm/QUTS/ActiveQutsServicePort";
#else
		return "";
#endif
	}

	OperatingSystem QutsClient::getOsType()
	{
#ifdef _WIN32
		return OperatingSystem::WIN_32;
#elif _WIN64
		return OperatingSystem::WIN_64;
#elif __APPLE__ || __MACH__
		return OperatingSystem::OSX;
#elif __linux__
		return OperatingSystem::LINUX;
#elif __FreeBSD__
		return OperatingSystem::FREEBSD;
#elif __unix || __unix__
		return OperatingSystem::UNIX;
#else
		return OperatingSystem::OTHER;
#endif
	}

	void QutsClient::clearCallbacks()
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->clearCallback();
		}
	}

	void QutsClient::setMessageCallback(const ClientCallbackServer::ClientCallbackServer::MessageCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setMessageCallback(callback);
		}
	}

	void QutsClient::setDeviceConnectedCallback(const ClientCallbackServer::ClientCallbackServer::DeviceConnectedCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setDeviceConnectedCallback(callback);
		}
	}

	void QutsClient::setDeviceDisconnectedCallback(const ClientCallbackServer::ClientCallbackServer::DeviceDisconnectedCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setDeviceDisconnectedCallback(callback);
		}
	}
	void QutsClient::setDeviceModeChangeCallback(const ClientCallbackServer::ClientCallbackServer::DeviceModeChangeCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setDeviceModeChangeCallback(callback);
		}
	}

	void QutsClient::setProtocolAddedCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolAddedCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setProtocolAddedCallback(callback);
		}
	}

	void QutsClient::setProtocolRemovedCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolRemovedCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setProtocolRemovedCallback(callback);
		}
	}

	void QutsClient::setProtocolStateChangeCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolStateChangeCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setProtocolStateChangeCallback(callback);
		}
	}
	void QutsClient::setProtocolFlowControlStatusChangeCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolFlowControlStatusChangeCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setProtocolFlowControlStatusChangeCallback(callback);
		}
	}

	void QutsClient::setProtocolLockStatusChangeCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolLockStatusChangeCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setProtocolLockStatusChangeCallback(callback);
		}
	}

	void QutsClient::setProtocolMbnDownloadStatusChangeCallback(const ClientCallbackServer::ClientCallbackServer::ProtocolMbnDownloadStatusChangeCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setProtocolMbnDownloadStatusChangeCallback(callback);
		}
	}

	void QutsClient::setClientCloseRequestCallback(const ClientCallbackServer::ClientCallbackServer::ClientCloseRequestCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setClientCloseRequestCallback(callback);
		}
	}

	void QutsClient::setMissingQShrinkHashFileCallback(const ClientCallbackServer::ClientCallbackServer::MissingQShrinkHashFileCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setMissingQShrinkHashFileCallback(callback);
		}
	}

	void QutsClient::setLogSessionMissingQShrinkHashFileCallback(const ClientCallbackServer::ClientCallbackServer::LogSessionMissingQShrinkHashFileCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setLogSessionMissingQShrinkHashFileCallback(callback);
		}
	}

	void QutsClient::setAsyncResponseCallback(const ClientCallbackServer::ClientCallbackServer::AsyncResponseCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setAsyncResponseCallback(callback);
		}
	}

	void QutsClient::setDataQueueUpdatedCallback(const ClientCallbackServer::ClientCallbackServer::DataQueueUpdatedCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setDataQueueUpdatedCallback(callback);
		}
	}

	void QutsClient::setDataViewUpdatedCallback(const ClientCallbackServer::ClientCallbackServer::DataViewUpdatedCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setDataViewUpdatedCallback(callback);
		}
	}

	void QutsClient::setServiceAvailableCallback(const ClientCallbackServer::ClientCallbackServer::ServiceAvailableCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setServiceAvailableCallback(callback);
		}
	}

	void QutsClient::setServiceEndedCallback(const ClientCallbackServer::ClientCallbackServer::ServiceEndedCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setServiceEndedCallback(callback);
		}
	}

	void QutsClient::setServiceEventCallback(const ClientCallbackServer::ClientCallbackServer::ServiceEventCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setServiceEventCallback(callback);
		}
	}

	void QutsClient::setImageManagementServiceEventCallback(const ClientCallbackServer::ClientCallbackServer::ImageManagementServiceEventCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setImageManagementServiceEventCallback(callback);
		}
	}

	void QutsClient::setDeviceConfigServiceEventCallback(const ClientCallbackServer::ClientCallbackServer::DeviceConfigServiceEventCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setDeviceConfigServiceEventCallback(callback);
		}
	}

	void QutsClient::setQShrinkStateUpdatedCallback(const ClientCallbackServer::ClientCallbackServer::QShrinkStateUpdatedCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setQShrinkStateUpdatedCallback(callback);
		}
	}

	void QutsClient::setDecryptionKeyStatusUpdateCallback(const ClientCallbackServer::ClientCallbackServer::DecryptionKeyStatusUpdateCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setDecryptionKeyStatusUpdateCallback(callback);
		}
	}

	void QutsClient::setLogSessionDecryptionKeyStatusUpdateCallback(const ClientCallbackServer::ClientCallbackServer::LogSessionDecryptionKeyStatusUpdateCallback& callback)
	{
		if (m_clientCallbackServer.get() != nullptr) {
			m_clientCallbackServer->setLogSessionDecryptionKeyStatusUpdateCallback(callback);
		}
	}
}
