/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "EudSwdService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class EudSwdServiceHandler : virtual public EudSwdServiceIf {
 public:
  EudSwdServiceHandler() {
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

   ::Uts::ErrorCode::type writeRegister(const int32_t startAddress, const std::vector<int32_t> & data, const int32_t ap) {
    // Your implementation goes here
    printf("writeRegister\n");
  }

  void readRegister(std::vector<int32_t> & _return, const int32_t startAddress, const int32_t numBytes, const int32_t ap) {
    // Your implementation goes here
    printf("readRegister\n");
  }

  int32_t InitSWD(const int32_t dummy) {
    // Your implementation goes here
    printf("InitSWD\n");
  }

  void swdRead_wrapper(BfrTckr& _return, const int32_t apndp, const int32_t A2_3) {
    // Your implementation goes here
    printf("swdRead_wrapper\n");
  }

  void swdWrite(BfrTckr& _return, const int32_t APnDP, const int32_t address2To3, const int64_t senddata) {
    // Your implementation goes here
    printf("swdWrite\n");
  }

  void SWDBitbang(std::vector<int32_t> & _return, const int32_t SWDBitValues) {
    // Your implementation goes here
    printf("SWDBitbang\n");
  }

  void Jtag_to_SWD() {
    // Your implementation goes here
    printf("Jtag_to_SWD\n");
  }

  void swdFlush(BfrTckr& _return) {
    // Your implementation goes here
    printf("swdFlush\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<EudSwdServiceHandler> handler(new EudSwdServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new EudSwdServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

