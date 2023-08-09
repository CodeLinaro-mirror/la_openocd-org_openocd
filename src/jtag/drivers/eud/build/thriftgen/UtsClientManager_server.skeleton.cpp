/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "UtsClientManager.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class UtsClientManagerHandler : virtual public UtsClientManagerIf {
 public:
  UtsClientManagerHandler() {
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

  void getClientNames(std::vector<std::string> & _return) {
    // Your implementation goes here
    printf("getClientNames\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<UtsClientManagerHandler> handler(new UtsClientManagerHandler());
  ::std::shared_ptr<TProcessor> processor(new UtsClientManagerProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

