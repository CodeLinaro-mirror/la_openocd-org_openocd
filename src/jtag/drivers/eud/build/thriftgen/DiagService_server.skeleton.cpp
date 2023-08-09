/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "DiagService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class DiagServiceHandler : virtual public DiagServiceIf {
 public:
  DiagServiceHandler() {
    // Your initialization goes here
  }

  void getLastError( ::Uts::ErrorType& _return) {
    // Your implementation goes here
    printf("getLastError\n");
  }

  int64_t getDevice() {
    // Your implementation goes here
    printf("getDevice\n");
  }

   ::Uts::ErrorCode::type initializeService() {
    // Your implementation goes here
    printf("initializeService\n");
  }

   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("initializeServiceByProtocol\n");
  }

   ::Uts::ErrorCode::type initializeServiceWithOptions(const DiagConnectionOptions& diagConnectionOptions) {
    // Your implementation goes here
    printf("initializeServiceWithOptions\n");
  }

   ::Uts::ErrorCode::type destroyService() {
    // Your implementation goes here
    printf("destroyService\n");
  }

  void sendRawRequest( ::Uts::DiagPacket& _return, const std::string& request, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) {
    // Your implementation goes here
    printf("sendRawRequest\n");
  }

  int64_t sendRawRequestAsync(const std::string& request) {
    // Your implementation goes here
    printf("sendRawRequestAsync\n");
  }

  void sendRequest( ::Uts::DiagPacket& _return, const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) {
    // Your implementation goes here
    printf("sendRequest\n");
  }

  int64_t sendRequestAsync(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList) {
    // Your implementation goes here
    printf("sendRequestAsync\n");
  }

  void getResponseAsync( ::Uts::DiagPacket& _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) {
    // Your implementation goes here
    printf("getResponseAsync\n");
  }

  void getAllResponsesAsync(std::vector< ::Uts::DiagPacket> & _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) {
    // Your implementation goes here
    printf("getAllResponsesAsync\n");
  }

   ::Uts::ErrorCode::type createDataQueue(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::DiagReturnConfig& returnConfig) {
    // Your implementation goes here
    printf("createDataQueue\n");
  }

   ::Uts::ErrorCode::type createDataQueueWithAnnotations(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::AnnotationPacketFilter& annotationsFilter, const  ::Uts::DiagReturnConfig& returnConfig) {
    // Your implementation goes here
    printf("createDataQueueWithAnnotations\n");
  }

   ::Uts::ErrorCode::type removeDataQueue(const std::string& queueName) {
    // Your implementation goes here
    printf("removeDataQueue\n");
  }

   ::Uts::ErrorCode::type clearDataQueue(const std::string& queueName) {
    // Your implementation goes here
    printf("clearDataQueue\n");
  }

  void getDataQueueItems(std::vector< ::Uts::DiagPacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout) {
    // Your implementation goes here
    printf("getDataQueueItems\n");
  }

  void getDataQueueItemsWithAnnotations(std::vector<DataQueuePacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout) {
    // Your implementation goes here
    printf("getDataQueueItemsWithAnnotations\n");
  }

   ::Uts::ErrorCode::type addDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter) {
    // Your implementation goes here
    printf("addDataQueueFilter\n");
  }

   ::Uts::ErrorCode::type removeDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter) {
    // Your implementation goes here
    printf("removeDataQueueFilter\n");
  }

   ::Uts::ErrorCode::type setLoggingMask(const std::string& maskFileContent, const  ::Uts::LogMaskFormat::type format) {
    // Your implementation goes here
    printf("setLoggingMask\n");
  }

   ::Uts::QShrink4DownloadState::type getQShrinkState() {
    // Your implementation goes here
    printf("getQShrinkState\n");
  }

  void loadQShrinkFile(const std::string& pathName) {
    // Your implementation goes here
    printf("loadQShrinkFile\n");
  }

   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const  ::Uts::WcdmaProtocolRevision::type revision) {
    // Your implementation goes here
    printf("setWcdmaProtocolRevision\n");
  }

   ::Uts::ErrorCode::type setCdmaProtocolRevision(const  ::Uts::CdmaProtocolRevision::type revision) {
    // Your implementation goes here
    printf("setCdmaProtocolRevision\n");
  }

   ::Uts::ErrorCode::type setPilotInc(const int16_t pilotInc) {
    // Your implementation goes here
    printf("setPilotInc\n");
  }

   ::Uts::ErrorCode::type setLoggingMaskFromFilter(const  ::Uts::DiagPacketFilter& filter) {
    // Your implementation goes here
    printf("setLoggingMaskFromFilter\n");
  }

  HealthReportConfigureStatus::type resetHealthReportCounters(const Subsystem::type subsystem) {
    // Your implementation goes here
    printf("resetHealthReportCounters\n");
  }

  HealthReportConfigureStatus::type setHealthReportTimer(const Subsystem::type subsystem, const int32_t timer) {
    // Your implementation goes here
    printf("setHealthReportTimer\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<DiagServiceHandler> handler(new DiagServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new DiagServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

