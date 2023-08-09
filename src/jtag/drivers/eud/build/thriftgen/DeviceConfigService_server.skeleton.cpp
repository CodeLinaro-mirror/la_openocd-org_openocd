/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "DeviceConfigService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::Uts;

class DeviceConfigServiceHandler : virtual public DeviceConfigServiceIf {
 public:
  DeviceConfigServiceHandler() {
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

   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle) {
    // Your implementation goes here
    printf("initializeServiceByProtocol\n");
  }

   ::Uts::ErrorCode::type initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions) {
    // Your implementation goes here
    printf("initializeServiceWithOptions\n");
  }

   ::Uts::ErrorCode::type destroyService() {
    // Your implementation goes here
    printf("destroyService\n");
  }

  void doXqcnOperation( ::Uts::DeviceConfigResp& _return, const DeviceConfigOptions& deviceConfigOptions) {
    // Your implementation goes here
    printf("doXqcnOperation\n");
  }

  void backupToXqcn(std::string& _return, const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents) {
    // Your implementation goes here
    printf("backupToXqcn\n");
  }

   ::Uts::ErrorCode::type restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents) {
    // Your implementation goes here
    printf("restoreFromXqcn\n");
  }

  int64_t pdcGetMbnMaxStorage(const PdcMbnType::type mbnType) {
    // Your implementation goes here
    printf("pdcGetMbnMaxStorage\n");
  }

  int64_t pdcGetMbnStorageUsage(const PdcMbnType::type mbnType) {
    // Your implementation goes here
    printf("pdcGetMbnStorageUsage\n");
  }

  int64_t pdcGetMbnCount(const PdcMbnType::type mbnType) {
    // Your implementation goes here
    printf("pdcGetMbnCount\n");
  }

  void pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const PdcMbnType::type mbnType) {
    // Your implementation goes here
    printf("pdcGetMbnList\n");
  }

  void pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const PdcMbnType::type mbnType) {
    // Your implementation goes here
    printf("pdcGetDefaultMbnInfo\n");
  }

  void pdcGetMbnId(std::string& _return, const std::string& mbnContent) {
    // Your implementation goes here
    printf("pdcGetMbnId\n");
  }

   ::Uts::ErrorCode::type pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent) {
    // Your implementation goes here
    printf("pdcWriteMbn\n");
  }

  void pdcReadMbn(std::string& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId) {
    // Your implementation goes here
    printf("pdcReadMbn\n");
  }

   ::Uts::ErrorCode::type pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId) {
    // Your implementation goes here
    printf("pdcRemoveMbn\n");
  }

  void pdcGetActiveMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId) {
    // Your implementation goes here
    printf("pdcGetActiveMbn\n");
  }

  void pdcGetPendingMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId) {
    // Your implementation goes here
    printf("pdcGetPendingMbn\n");
  }

  void pdcValidateMbn(PdcMbnResult& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath) {
    // Your implementation goes here
    printf("pdcValidateMbn\n");
  }

   ::Uts::ErrorCode::type pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId) {
    // Your implementation goes here
    printf("pdcSelectMbn\n");
  }

   ::Uts::ErrorCode::type pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout) {
    // Your implementation goes here
    printf("pdcActivateMbn\n");
  }

   ::Uts::ErrorCode::type pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId) {
    // Your implementation goes here
    printf("pdcDeactivateMbn\n");
  }

  int32_t pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature) {
    // Your implementation goes here
    printf("pdcGetConfiguration\n");
  }

   ::Uts::ErrorCode::type pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value) {
    // Your implementation goes here
    printf("pdcSetConfiguration\n");
  }

  bool nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("nvIsItemSupported\n");
  }

  void nvReadItem(NvData& _return, const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig) {
    // Your implementation goes here
    printf("nvReadItem\n");
  }

   ::Uts::ErrorCode::type nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("nvSetItem\n");
  }

   ::Uts::ErrorCode::type nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("nvSetOtpItem\n");
  }

  void nvGetAllItems(std::vector< ::Uts::NvItem> & _return) {
    // Your implementation goes here
    printf("nvGetAllItems\n");
  }

  void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId) {
    // Your implementation goes here
    printf("nvGetItemDefinition\n");
  }

  bool efsHasAlternateFileSystem() {
    // Your implementation goes here
    printf("efsHasAlternateFileSystem\n");
  }

   ::Uts::ErrorCode::type efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsCreateDirectory\n");
  }

   ::Uts::ErrorCode::type efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsRemoveDirectory\n");
  }

   ::Uts::ErrorCode::type efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem) {
    // Your implementation goes here
    printf("efsRemoveTree\n");
  }

  void efsGetDirectoryContents(std::vector<EfsItem> & _return, const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsGetDirectoryContents\n");
  }

   ::Uts::ErrorCode::type efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsPutFile\n");
  }

  void efsGetFile(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsGetFile\n");
  }

   ::Uts::ErrorCode::type efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsDeleteFile\n");
  }

   ::Uts::ErrorCode::type efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsRename\n");
  }

  bool efsPathExists(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsPathExists\n");
  }

  bool efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsIsDirectory\n");
  }

  bool efsIsFile(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsIsFile\n");
  }

  int64_t efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsGetFileSize\n");
  }

  int64_t efsGetAvailableSpace(const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsGetAvailableSpace\n");
  }

  void efsGetFileCheckSum(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsGetFileCheckSum\n");
  }

  void efsGetFileAttributes(EfsFileAttributes& _return, const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("efsGetFileAttributes\n");
  }

  bool efsIsReady() {
    // Your implementation goes here
    printf("efsIsReady\n");
  }

   ::Uts::ErrorCode::type createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("createGoldenCopy\n");
  }

   ::Uts::ErrorCode::type createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("createCefsCopy\n");
  }

  void requestPrl(std::string& _return, const int32_t subscriptionId, const int8_t index) {
    // Your implementation goes here
    printf("requestPrl\n");
  }

  void backupPrl(std::string& _return) {
    // Your implementation goes here
    printf("backupPrl\n");
  }

   ::Uts::ErrorCode::type restorePrl(const std::string& xqcnFileContents) {
    // Your implementation goes here
    printf("restorePrl\n");
  }

   ::Uts::ErrorCode::type sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents) {
    // Your implementation goes here
    printf("sendPrl\n");
  }

   ::Uts::ErrorCode::type forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem) {
    // Your implementation goes here
    printf("forceEfsSync\n");
  }

  int32_t getEsn() {
    // Your implementation goes here
    printf("getEsn\n");
  }

   ::Uts::ErrorCode::type setEsn(const int32_t esn) {
    // Your implementation goes here
    printf("setEsn\n");
  }

  void getImei(std::string& _return, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("getImei\n");
  }

   ::Uts::ErrorCode::type setImei(const std::string& imei, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("setImei\n");
  }

  int64_t getMeid(const int32_t subscriptionId) {
    // Your implementation goes here
    printf("getMeid\n");
  }

   ::Uts::ErrorCode::type setMeid(const int64_t meid, const int32_t subscriptionId) {
    // Your implementation goes here
    printf("setMeid\n");
  }

  bool checkSpc(const std::string& spc) {
    // Your implementation goes here
    printf("checkSpc\n");
  }

  bool provisionSpc(const std::string& currentSpc, const std::string& newSpc) {
    // Your implementation goes here
    printf("provisionSpc\n");
  }

  void efsReadFromModemLog(std::string& _return) {
    // Your implementation goes here
    printf("efsReadFromModemLog\n");
  }

   ::Uts::ErrorCode::type configureService(const DeviceConfigOptions& deviceConfigOptions) {
    // Your implementation goes here
    printf("configureService\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<DeviceConfigServiceHandler> handler(new DeviceConfigServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new DeviceConfigServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

