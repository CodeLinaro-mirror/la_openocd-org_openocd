/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "LogSession.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class LogSessionHandler : virtual public LogSessionIf {
 public:
  LogSessionHandler() {
    // Your initialization goes here
  }

  void getLastError( ::Uts::ErrorType& _return) {
    // Your implementation goes here
    printf("getLastError\n");
  }

   ::Uts::ErrorCode::type destroyLogSession() {
    // Your implementation goes here
    printf("destroyLogSession\n");
  }

  void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return) {
    // Your implementation goes here
    printf("getDeviceList\n");
  }

  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle) {
    // Your implementation goes here
    printf("getProtocolList\n");
  }

  int64_t getDataPacketCount(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getDataPacketCount\n");
  }

   ::Uts::ErrorCode::type createDataView(const std::string& viewName, const DataPacketFilter& filter, const PacketReturnConfig& returnConfig) {
    // Your implementation goes here
    printf("createDataView\n");
  }

   ::Uts::ErrorCode::type createDefaultDataView(const std::string& viewName, const std::vector<int64_t> & protocolHandleList, const PacketReturnConfig& returnConfig) {
    // Your implementation goes here
    printf("createDefaultDataView\n");
  }

   ::Uts::ErrorCode::type createDataViewSet(const std::vector<DataViewInfo> & dataViewDefinitions) {
    // Your implementation goes here
    printf("createDataViewSet\n");
  }

   ::Uts::ErrorCode::type removeDataView(const std::string& viewName) {
    // Your implementation goes here
    printf("removeDataView\n");
  }

  int32_t getDataViewItemCount(const std::string& viewName) {
    // Your implementation goes here
    printf("getDataViewItemCount\n");
  }

  void getDataViewItems(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets) {
    // Your implementation goes here
    printf("getDataViewItems\n");
  }

   ::Uts::ErrorCode::type saveDataViewItemsByIndex(const std::string& viewName, const std::string& destinationFolder, const std::vector<int64_t> & dataViewIndexes) {
    // Your implementation goes here
    printf("saveDataViewItemsByIndex\n");
  }

   ::Uts::ErrorCode::type saveDataViewItemsByIndexWithFilenames(const std::string& viewName, const std::vector<int64_t> & dataViewIndexes, const std::map<int64_t, std::string> & logNamesByHandle) {
    // Your implementation goes here
    printf("saveDataViewItemsByIndexWithFilenames\n");
  }

  void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder) {
    // Your implementation goes here
    printf("saveLogFiles\n");
  }

  void getDurationByProtocol(std::string& _return, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getDurationByProtocol\n");
  }

   ::Uts::ErrorCode::type updatePacketFilters(const std::string& viewName, const DataPacketFilter& filter, const ViewConfigurationUpdate::type updateType) {
    // Your implementation goes here
    printf("updatePacketFilters\n");
  }

   ::Uts::ErrorCode::type updatePacketReturnConfig(const std::string& viewName, const PacketReturnConfig& returnConfig) {
    // Your implementation goes here
    printf("updatePacketReturnConfig\n");
  }

  void getAvailablePacketIds(DataPacketFilter& _return, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getAvailablePacketIds\n");
  }

  void getLogSessionInformation(LogSessionInformation& _return, const std::set<int64_t> & protocolHandle) {
    // Your implementation goes here
    printf("getLogSessionInformation\n");
  }

  void loadQShrinkFile(const int64_t protocolHandle, const std::string& pathName) {
    // Your implementation goes here
    printf("loadQShrinkFile\n");
  }

  int64_t getDataViewItemIndex(const std::string& viewName, const int64_t sessionIndex) {
    // Your implementation goes here
    printf("getDataViewItemIndex\n");
  }

  int64_t getTimeStampTodAdjustedByDataviewIndexForAnnotations(const std::string& viewName, const int64_t dataviewIndex) {
    // Your implementation goes here
    printf("getTimeStampTodAdjustedByDataviewIndexForAnnotations\n");
  }

  void getDataViewItemsForConfiguration(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets, const PacketReturnConfig& returnConfig) {
    // Your implementation goes here
    printf("getDataViewItemsForConfiguration\n");
  }

  void getClientSessionInfo(ClientSessionInfo& _return) {
    // Your implementation goes here
    printf("getClientSessionInfo\n");
  }

   ::Uts::ErrorCode::type createSubDataView(const std::string& viewName, const std::string& parentViewName, const DataPacketFilter& filter, const PacketRange& packets, const PacketReturnConfig& returnConfig) {
    // Your implementation goes here
    printf("createSubDataView\n");
  }

   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::WcdmaProtocolRevision::type revision) {
    // Your implementation goes here
    printf("setWcdmaProtocolRevision\n");
  }

   ::Uts::ErrorCode::type setCdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::CdmaProtocolRevision::type revision) {
    // Your implementation goes here
    printf("setCdmaProtocolRevision\n");
  }

   ::Uts::ErrorCode::type setPilotInc(const int64_t protocolHandle, const int16_t pilotInc) {
    // Your implementation goes here
    printf("setPilotInc\n");
  }

  int16_t getBandClass(const int64_t protocolHandle, const int64_t protocolIndex) {
    // Your implementation goes here
    printf("getBandClass\n");
  }

   ::Uts::CdmaProtocolRevision::type getCdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex) {
    // Your implementation goes here
    printf("getCdmaProtocolRevision\n");
  }

  int16_t getModel(const int64_t protocolHandle, const int64_t protocolIndex) {
    // Your implementation goes here
    printf("getModel\n");
  }

   ::Uts::WcdmaProtocolRevision::type getWcdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex) {
    // Your implementation goes here
    printf("getWcdmaProtocolRevision\n");
  }

  void getDecryptionKeyStatus(std::vector< ::Uts::KeyInfo> & _return, const int64_t protocolHandle) {
    // Your implementation goes here
    printf("getDecryptionKeyStatus\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<LogSessionHandler> handler(new LogSessionHandler());
  ::std::shared_ptr<TProcessor> processor(new LogSessionProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

