/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "UtilityService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class UtilityServiceHandler : virtual public UtilityServiceIf {
 public:
  UtilityServiceHandler() {
    // Your initialization goes here
  }

  void getLastError( ::Uts::ErrorType& _return) {
    // Your implementation goes here
    printf("getLastError\n");
  }

  void qmiPack(std::string& _return, const std::string& serviceIdOrName, const std::string& messageIdOrName, const std::string& xmlRequest) {
    // Your implementation goes here
    printf("qmiPack\n");
  }

  void qmiUnPack( ::Uts::QmiUnpackReturn& _return, const std::string& serviceIdOrName, const std::string& input) {
    // Your implementation goes here
    printf("qmiUnPack\n");
  }

  void nvGetAllItems(std::vector< ::Uts::NvItem> & _return) {
    // Your implementation goes here
    printf("nvGetAllItems\n");
  }

  void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId) {
    // Your implementation goes here
    printf("nvGetItemDefinition\n");
  }

   ::Uts::ErrorCode::type createDigestsForVipDownload(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath) {
    // Your implementation goes here
    printf("createDigestsForVipDownload\n");
  }

   ::Uts::ErrorCode::type createDigestsForBuildValidation(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath) {
    // Your implementation goes here
    printf("createDigestsForBuildValidation\n");
  }

  void generateCfg(std::string& _return, const  ::Uts::DiagPacketMap& mask, const  ::Uts::LogMaskFormat::type format) {
    // Your implementation goes here
    printf("generateCfg\n");
  }

  void convertToHdf(std::vector<std::string> & _return, const std::vector<std::string> & logFiles, const std::string& saveFolder) {
    // Your implementation goes here
    printf("convertToHdf\n");
  }

  void qcnDiff( ::Uts::QcnDiffResult& _return, const std::string& xqcnContents1, const std::string& xqcnContents2, const bool showSame) {
    // Your implementation goes here
    printf("qcnDiff\n");
  }

  void extractFromCfg( ::Uts::DiagPacketMap& _return, const std::string& cfgContents, const  ::Uts::LogMaskFormat::type format) {
    // Your implementation goes here
    printf("extractFromCfg\n");
  }

  void extractFromAwsi( ::Uts::DiagPacketMap& _return, const std::string& awsiContents) {
    // Your implementation goes here
    printf("extractFromAwsi\n");
  }

  int32_t getDiagId(const  ::Uts::DiagPacketType::type packetType, const std::string& idOrName) {
    // Your implementation goes here
    printf("getDiagId\n");
  }

  int32_t getQmiId(const  ::Uts::QmiPacketType::type packetType, const std::string& idOrName) {
    // Your implementation goes here
    printf("getQmiId\n");
  }

  int32_t getSaharaId(const std::string& idOrName) {
    // Your implementation goes here
    printf("getSaharaId\n");
  }

  void deserializeXqcnXml( ::Uts::QcnContent& _return, const std::string& xqcnFileContents) {
    // Your implementation goes here
    printf("deserializeXqcnXml\n");
  }

  void serializeXqcnXml(std::string& _return, const  ::Uts::QcnContent& xqcnContents) {
    // Your implementation goes here
    printf("serializeXqcnXml\n");
  }

  void deserializeNvItem(NvParserResult& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const int8_t index, const  ::Uts::NvReturns& returnConfig, const std::string& payload) {
    // Your implementation goes here
    printf("deserializeNvItem\n");
  }

  void serializeNvItem(std::string& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const std::string& valueList) {
    // Your implementation goes here
    printf("serializeNvItem\n");
  }

   ::Uts::ErrorCode::type compressEncryptedFile(const std::string& originalFile, const std::string& outputFile) {
    // Your implementation goes here
    printf("compressEncryptedFile\n");
  }

  void parseMBN( ::Uts::MbnDiffResult& _return, const std::string& mbnOrXmlPath) {
    // Your implementation goes here
    printf("parseMBN\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<UtilityServiceHandler> handler(new UtilityServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new UtilityServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

