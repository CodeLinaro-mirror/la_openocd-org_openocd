/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "ImageManagementService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class ImageManagementServiceHandler : virtual public ImageManagementServiceIf {
 public:
  ImageManagementServiceHandler() {
    // Your initialization goes here
  }

  void getLastError( ::Uts::ErrorType& _return) {
    // Your implementation goes here
    printf("getLastError\n");
  }

   ::Uts::ErrorCode::type initializeService() {
    // Your implementation goes here
    printf("initializeService\n");
  }

   ::Uts::ErrorCode::type destroyService() {
    // Your implementation goes here
    printf("destroyService\n");
  }

  DeviceImageMode::type getDeviceImageMode() {
    // Your implementation goes here
    printf("getDeviceImageMode\n");
  }

  void transferImages(TransferImageResult& _return, const std::map<int32_t, std::string> & imageList) {
    // Your implementation goes here
    printf("transferImages\n");
  }

  void getDeviceInfo(EdlDeviceInfo& _return) {
    // Your implementation goes here
    printf("getDeviceInfo\n");
  }

   ::Uts::ErrorCode::type collectPblDumpV3(const std::string& pathName) {
    // Your implementation goes here
    printf("collectPblDumpV3\n");
  }

   ::Uts::ErrorCode::type downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options) {
    // Your implementation goes here
    printf("downloadBuild\n");
  }

   ::Uts::ErrorCode::type collectMemoryDump(const std::string& pathName) {
    // Your implementation goes here
    printf("collectMemoryDump\n");
  }

   ::Uts::ErrorCode::type collectMemoryDumpWithOptions(const MemoryDumpOptions& options) {
    // Your implementation goes here
    printf("collectMemoryDumpWithOptions\n");
  }

   ::Uts::ErrorCode::type startRemoteEfsSync(const std::string& pathName) {
    // Your implementation goes here
    printf("startRemoteEfsSync\n");
  }

   ::Uts::ErrorCode::type stopRemoteEfsSync() {
    // Your implementation goes here
    printf("stopRemoteEfsSync\n");
  }

   ::Uts::ErrorCode::type setDdrStorePath(const std::string& ddrStorePath) {
    // Your implementation goes here
    printf("setDdrStorePath\n");
  }

   ::Uts::ErrorCode::type resetDevice(const int32_t timeout) {
    // Your implementation goes here
    printf("resetDevice\n");
  }

   ::Uts::ErrorCode::type switchToEdl() {
    // Your implementation goes here
    printf("switchToEdl\n");
  }

   ::Uts::ErrorCode::type erasePartition(const DownloadBuildOptions& options) {
    // Your implementation goes here
    printf("erasePartition\n");
  }

  void getFlashInfo(std::vector<FlashInfo> & _return, const DownloadBuildOptions& options) {
    // Your implementation goes here
    printf("getFlashInfo\n");
  }

  void initPartitionTable(std::vector<PartitionInfo> & _return, const DownloadBuildOptions& options) {
    // Your implementation goes here
    printf("initPartitionTable\n");
  }

   ::Uts::ErrorCode::type readPartitionData(const std::vector<DataChunkOptions> & dataChunks) {
    // Your implementation goes here
    printf("readPartitionData\n");
  }

   ::Uts::ErrorCode::type writePartitionData(const std::vector<DataChunkOptions> & dataChunks) {
    // Your implementation goes here
    printf("writePartitionData\n");
  }

   ::Uts::ErrorCode::type erasePartitionData(const std::vector<DataChunkOptions> & dataChunks) {
    // Your implementation goes here
    printf("erasePartitionData\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<ImageManagementServiceHandler> handler(new ImageManagementServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new ImageManagementServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

