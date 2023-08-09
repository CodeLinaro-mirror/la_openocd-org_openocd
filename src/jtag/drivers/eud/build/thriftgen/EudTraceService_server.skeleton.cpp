/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "EudTraceService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class EudTraceServiceHandler : virtual public EudTraceServiceIf {
 public:
  EudTraceServiceHandler() {
    // Your initialization goes here
  }

   ::Uts::ErrorCode::type openTrace() {
    // Your implementation goes here
    printf("openTrace\n");
  }

   ::Uts::ErrorCode::type setChunkSizes(const int32_t chukSize, const int32_t maxChunks) {
    // Your implementation goes here
    printf("setChunkSizes\n");
  }

   ::Uts::ErrorCode::type setOutputDir(const std::string& outputDir) {
    // Your implementation goes here
    printf("setOutputDir\n");
  }

   ::Uts::ErrorCode::type getOutputDir(const std::string& outputDir, const std::vector<int32_t> & pStringSize) {
    // Your implementation goes here
    printf("getOutputDir\n");
  }

   ::Uts::ErrorCode::type setTimeoutMS(const int32_t timeoutMs) {
    // Your implementation goes here
    printf("setTimeoutMS\n");
  }

   ::Uts::ErrorCode::type setTransferLength(const int32_t transferLength) {
    // Your implementation goes here
    printf("setTransferLength\n");
  }

   ::Uts::ErrorCode::type closeTrace() {
    // Your implementation goes here
    printf("closeTrace\n");
  }

   ::Uts::ErrorCode::type flushTrace() {
    // Your implementation goes here
    printf("flushTrace\n");
  }

   ::Uts::ErrorCode::type reInitTrace() {
    // Your implementation goes here
    printf("reInitTrace\n");
  }

   ::Uts::ErrorCode::type traceReset() {
    // Your implementation goes here
    printf("traceReset\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<EudTraceServiceHandler> handler(new EudTraceServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new EudTraceServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

