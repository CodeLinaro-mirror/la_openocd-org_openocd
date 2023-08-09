/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "QutsService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class QutsServiceHandler : virtual public QutsServiceIf {
 public:
  QutsServiceHandler() {
    // Your initialization goes here
  }

  int32_t registerClient(const std::string& clientName) {
    // Your implementation goes here
    printf("registerClient\n");
  }

  int32_t registerSecureClient(const  ::Uts::ClientInfo& clientInfo) {
    // Your implementation goes here
    printf("registerSecureClient\n");
  }

  int32_t getQutsApplicationPort() {
    // Your implementation goes here
    printf("getQutsApplicationPort\n");
  }

   ::Uts::ErrorCode::type registerAutomationPort(const std::string& appName, const int32_t automationPort) {
    // Your implementation goes here
    printf("registerAutomationPort\n");
  }

   ::Uts::ErrorCode::type unRegisterAutomationPort(const std::string& appName, const int32_t automationPort) {
    // Your implementation goes here
    printf("unRegisterAutomationPort\n");
  }

  bool runLoopback() {
    // Your implementation goes here
    printf("runLoopback\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<QutsServiceHandler> handler(new QutsServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new QutsServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

