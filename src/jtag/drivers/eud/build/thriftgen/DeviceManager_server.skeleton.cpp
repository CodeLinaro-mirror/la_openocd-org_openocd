/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "DeviceManager.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class DeviceManagerHandler : virtual public DeviceManagerIf {
 public:
  DeviceManagerHandler() {
    // Your initialization goes here
  }

  void getLastError( ::Uts::ErrorType& _return) {
    // Your implementation goes here
    printf("getLastError\n");
  }

  void getServicesList(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getServicesList\n");
  }

  void getDevicesForService(std::vector<int64_t> & _return, const std::string& serviceName) {
    // Your implementation goes here
    printf("getDevicesForService\n");
  }

  void getServicesForDevice(std::vector<std::string> & _return, const int64_t deviceHandle) {
    // Your implementation goes here
    printf("getServicesForDevice\n");
  }

  void createService(std::string& _return, const std::string& serviceName, const int64_t deviceHandle) {
    // Your implementation goes here
    printf("createService\n");
  }

  void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return) {
    // Your implementation goes here
    printf("getDeviceList\n");
  }

  int64_t getDeviceHandleFromProtocol(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getDeviceHandleFromProtocol\n");
  }

   ::Uts::ErrorCode::type mergeDevice(const int64_t sourceDeviceHandle, const int64_t destinationDeviceHandle) {
    // Your implementation goes here
    printf("mergeDevice\n");
  }

  void getDeviceBuildId( ::Uts::BuildInfo& _return, const int64_t deviceHandle) {
    // Your implementation goes here
    printf("getDeviceBuildId\n");
  }

  void getDeviceImageInfoByProtocol(std::vector< ::Uts::ImageInfo> & _return, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getDeviceImageInfoByProtocol\n");
  }

  void getChipName(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getChipName\n");
  }

   ::Uts::DeviceMode::type getDeviceMode(const int64_t deviceHandle) {
    // Your implementation goes here
    printf("getDeviceMode\n");
  }

  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle) {
    // Your implementation goes here
    printf("getProtocolList\n");
  }

  void getActiveLogSession(std::string& _return) {
    // Your implementation goes here
    printf("getActiveLogSession\n");
  }

   ::Uts::ErrorCode::type overrideUnknownProtocol(const int64_t protocolHandle, const  ::Uts::ProtocolType::type newType) {
    // Your implementation goes here
    printf("overrideUnknownProtocol\n");
  }

  void addTcpConnection( ::Uts::ProtocolInfo& _return, const int64_t deviceHandle, const  ::Uts::ProtocolType::type protocolType, const bool bIsClient, const std::string& description, const std::string& host, const int32_t port) {
    // Your implementation goes here
    printf("addTcpConnection\n");
  }

  void addTcpConnectionWithOptions( ::Uts::ProtocolInfo& _return, const std::string& host, const int32_t port, const  ::Uts::TcpOptions& options) {
    // Your implementation goes here
    printf("addTcpConnectionWithOptions\n");
  }

   ::Uts::ErrorCode::type removeTcpConnection(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("removeTcpConnection\n");
  }

   ::Uts::ErrorCode::type startTcpServer(const  ::Uts::ProtocolType::type protocolType, const int32_t port) {
    // Your implementation goes here
    printf("startTcpServer\n");
  }

   ::Uts::ErrorCode::type startTcpServerWithOptions(const int32_t port, const  ::Uts::TcpOptions& options) {
    // Your implementation goes here
    printf("startTcpServerWithOptions\n");
  }

   ::Uts::ErrorCode::type stopTcpServer(const int32_t port) {
    // Your implementation goes here
    printf("stopTcpServer\n");
  }

  void getTcpServerList(std::vector<int32_t> & _return) {
    // Your implementation goes here
    printf("getTcpServerList\n");
  }

   ::Uts::ErrorCode::type startLogging() {
    // Your implementation goes here
    printf("startLogging\n");
  }

   ::Uts::ErrorCode::type resetLogFiles() {
    // Your implementation goes here
    printf("resetLogFiles\n");
  }

  void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder) {
    // Your implementation goes here
    printf("saveLogFiles\n");
  }

  void saveLogFilesWithFilenames(std::vector<std::string> & _return, const std::map<int64_t, std::string> & logNameConfig) {
    // Your implementation goes here
    printf("saveLogFilesWithFilenames\n");
  }

  int64_t getCurrentLogFileSize(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getCurrentLogFileSize\n");
  }

  void openLogSession(std::string& _return, const std::vector<std::string> & logFiles) {
    // Your implementation goes here
    printf("openLogSession\n");
  }

  void attachToLogSession(std::string& _return, const int32_t clientId, const std::string& logSession) {
    // Your implementation goes here
    printf("attachToLogSession\n");
  }

   ::Uts::ErrorCode::type logAnnotation(const std::string& annotation, const int64_t messageId, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("logAnnotation\n");
  }

   ::Uts::ErrorCode::type resetPhone(const int64_t deviceHandle, const int32_t resetTimeout) {
    // Your implementation goes here
    printf("resetPhone\n");
  }

   ::Uts::ErrorCode::type resetPhoneByProtocol(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t resetTimeout) {
    // Your implementation goes here
    printf("resetPhoneByProtocol\n");
  }

   ::Uts::ErrorCode::type restartQmiReadyScan(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("restartQmiReadyScan\n");
  }

   ::Uts::ErrorCode::type setOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle, const OperatingMode::type mode) {
    // Your implementation goes here
    printf("setOperatingMode\n");
  }

  void getThroughputStatistics( ::Uts::RxTxInfo& _return, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getThroughputStatistics\n");
  }

  int32_t getEsn(const int64_t deviceHandle, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getEsn\n");
  }

   ::Uts::ErrorCode::type setEsn(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t esn) {
    // Your implementation goes here
    printf("setEsn\n");
  }

  void getImei(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("getImei\n");
  }

   ::Uts::ErrorCode::type setImei(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& imei, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("setImei\n");
  }

  int64_t getMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("getMeid\n");
  }

   ::Uts::ErrorCode::type setMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int64_t meid, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("setMeid\n");
  }

  void checkSpc(SpcStatus& _return, const int64_t deviceHandle, const int64_t protocolHandle, const std::string& spc) {
    // Your implementation goes here
    printf("checkSpc\n");
  }

  void getOperatingMode(OperatingModeInfo& _return, const int64_t deviceHandle, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getOperatingMode\n");
  }

   ::Uts::ErrorCode::type transferImageBhi(const std::string& programmerPath) {
    // Your implementation goes here
    printf("transferImageBhi\n");
  }

  void transferFileToDevice( ::Uts::TransferFileResult& _return, const std::string& hostPath, const std::string& devicePath, const  ::Uts::TransferFileOptions& options) {
    // Your implementation goes here
    printf("transferFileToDevice\n");
  }

  void transferFileToHost( ::Uts::TransferFileResult& _return, const std::string& devicePath, const std::string& hostPath, const  ::Uts::TransferFileOptions& options) {
    // Your implementation goes here
    printf("transferFileToHost\n");
  }

  void getProtocolLockStatus( ::Uts::LockStatus& _return, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getProtocolLockStatus\n");
  }

  void getDeviceUsageIndicators( ::Uts::UsageIndicators& _return, const int64_t deviceHandle) {
    // Your implementation goes here
    printf("getDeviceUsageIndicators\n");
  }

   ::Uts::ErrorCode::type enableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas, const  ::Uts::LogOptions& options) {
    // Your implementation goes here
    printf("enableFunctionLog\n");
  }

   ::Uts::ErrorCode::type disableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas) {
    // Your implementation goes here
    printf("disableFunctionLog\n");
  }

   ::Uts::ErrorCode::type enableProtocolLog(const int64_t protocolHandle, const  ::Uts::LogOptions& options) {
    // Your implementation goes here
    printf("enableProtocolLog\n");
  }

   ::Uts::ErrorCode::type disableProtocolLog(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("disableProtocolLog\n");
  }

   ::Uts::ErrorCode::type configureProtocol(const  ::Uts::ProtocolConfiguration& protocolConfiguration) {
    // Your implementation goes here
    printf("configureProtocol\n");
  }

  void getProtocolConfiguration( ::Uts::ProtocolConfigurationResult& _return, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getProtocolConfiguration\n");
  }

   ::Uts::ErrorCode::type enableProtocolDataMonitoring(const std::vector<int64_t> & protocolHandleList, const bool enable) {
    // Your implementation goes here
    printf("enableProtocolDataMonitoring\n");
  }

   ::Uts::ErrorCode::type enableDeviceDataMonitoring(const std::vector<int64_t> & deviceHandleList, const bool enable) {
    // Your implementation goes here
    printf("enableDeviceDataMonitoring\n");
  }

   ::Uts::ErrorCode::type enableDevicePriority(const std::vector<int64_t> & deviceHandleList, const bool enable) {
    // Your implementation goes here
    printf("enableDevicePriority\n");
  }

   ::Uts::ErrorCode::type configParameter(const std::string& name, const std::string& value) {
    // Your implementation goes here
    printf("configParameter\n");
  }

  int32_t getRegistrationPort() {
    // Your implementation goes here
    printf("getRegistrationPort\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<DeviceManagerHandler> handler(new DeviceManagerHandler());
  ::std::shared_ptr<TProcessor> processor(new DeviceManagerProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

