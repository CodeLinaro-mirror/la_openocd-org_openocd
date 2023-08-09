/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "EudCtlService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class EudCtlServiceHandler : virtual public EudCtlServiceIf {
 public:
  EudCtlServiceHandler() {
    // Your initialization goes here
  }

   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("initializeServiceByProtocol\n");
  }

   ::Uts::ErrorCode::type destroyService() {
    // Your implementation goes here
    printf("destroyService\n");
  }

   ::Uts::ErrorCode::type enableSwd() {
    // Your implementation goes here
    printf("enableSwd\n");
  }

   ::Uts::ErrorCode::type disableSwd() {
    // Your implementation goes here
    printf("disableSwd\n");
  }

   ::Uts::ErrorCode::type spoofAttach() {
    // Your implementation goes here
    printf("spoofAttach\n");
  }

   ::Uts::ErrorCode::type spoofDetach() {
    // Your implementation goes here
    printf("spoofDetach\n");
  }

   ::Uts::ErrorCode::type rebootSoc() {
    // Your implementation goes here
    printf("rebootSoc\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<EudCtlServiceHandler> handler(new EudCtlServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new EudCtlServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

