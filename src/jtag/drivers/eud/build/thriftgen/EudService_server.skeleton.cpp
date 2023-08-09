/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "EudService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class EudServiceHandler : virtual public EudServiceIf {
 public:
  EudServiceHandler() {
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

   ::Uts::ErrorCode::type destroyService() {
    // Your implementation goes here
    printf("destroyService\n");
  }

  void sendCommand(const EudCmdInfo& eudCmdInfo) {
    // Your implementation goes here
    printf("sendCommand\n");
  }

  void sendRawRequest( ::Uts::EudPacket& _return, const std::string& request, const  ::Uts::EudReturnConfig& returnConfig, const int32_t timeout) {
    // Your implementation goes here
    printf("sendRawRequest\n");
  }

  int64_t sendRawRequestAsync(const std::string& request) {
    // Your implementation goes here
    printf("sendRawRequestAsync\n");
  }

   ::Uts::EudPeripheralType::type GetEudPeripheralType(const int64_t protocolHandle) {
    // Your implementation goes here
    printf("GetEudPeripheralType\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<EudServiceHandler> handler(new EudServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new EudServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

