/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DeviceConfigService_H
#define DeviceConfigService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "DeviceConfigService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class DeviceConfigServiceIf {
 public:
  virtual ~DeviceConfigServiceIf() {}
  virtual void getLastError( ::Uts::ErrorType& _return) = 0;
  virtual int64_t getDevice() = 0;
  virtual  ::Uts::ErrorCode::type initializeService() = 0;
  virtual  ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions) = 0;
  virtual  ::Uts::ErrorCode::type destroyService() = 0;
  virtual void doXqcnOperation( ::Uts::DeviceConfigResp& _return, const DeviceConfigOptions& deviceConfigOptions) = 0;
  virtual void backupToXqcn(std::string& _return, const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents) = 0;
  virtual  ::Uts::ErrorCode::type restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents) = 0;
  virtual int64_t pdcGetMbnMaxStorage(const PdcMbnType::type mbnType) = 0;
  virtual int64_t pdcGetMbnStorageUsage(const PdcMbnType::type mbnType) = 0;
  virtual int64_t pdcGetMbnCount(const PdcMbnType::type mbnType) = 0;
  virtual void pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const PdcMbnType::type mbnType) = 0;
  virtual void pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const PdcMbnType::type mbnType) = 0;
  virtual void pdcGetMbnId(std::string& _return, const std::string& mbnContent) = 0;
  virtual  ::Uts::ErrorCode::type pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent) = 0;
  virtual void pdcReadMbn(std::string& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId) = 0;
  virtual  ::Uts::ErrorCode::type pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId) = 0;
  virtual void pdcGetActiveMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId) = 0;
  virtual void pdcGetPendingMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId) = 0;
  virtual void pdcValidateMbn(PdcMbnResult& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath) = 0;
  virtual  ::Uts::ErrorCode::type pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId) = 0;
  virtual  ::Uts::ErrorCode::type pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout) = 0;
  virtual  ::Uts::ErrorCode::type pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId) = 0;
  virtual int32_t pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature) = 0;
  virtual  ::Uts::ErrorCode::type pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value) = 0;
  virtual bool nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId) = 0;
  virtual void nvReadItem(NvData& _return, const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig) = 0;
  virtual  ::Uts::ErrorCode::type nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId) = 0;
  virtual  ::Uts::ErrorCode::type nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId) = 0;
  virtual void nvGetAllItems(std::vector< ::Uts::NvItem> & _return) = 0;
  virtual void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId) = 0;
  virtual bool efsHasAlternateFileSystem() = 0;
  virtual  ::Uts::ErrorCode::type efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual  ::Uts::ErrorCode::type efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual  ::Uts::ErrorCode::type efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem) = 0;
  virtual void efsGetDirectoryContents(std::vector<EfsItem> & _return, const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual  ::Uts::ErrorCode::type efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem) = 0;
  virtual void efsGetFile(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual  ::Uts::ErrorCode::type efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual  ::Uts::ErrorCode::type efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem) = 0;
  virtual bool efsPathExists(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual bool efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual bool efsIsFile(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual int64_t efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual int64_t efsGetAvailableSpace(const FileSystem::type efsSystem) = 0;
  virtual void efsGetFileCheckSum(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual void efsGetFileAttributes(EfsFileAttributes& _return, const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual bool efsIsReady() = 0;
  virtual  ::Uts::ErrorCode::type createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual  ::Uts::ErrorCode::type createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem) = 0;
  virtual void requestPrl(std::string& _return, const int32_t subscriptionId, const int8_t index) = 0;
  virtual void backupPrl(std::string& _return) = 0;
  virtual  ::Uts::ErrorCode::type restorePrl(const std::string& xqcnFileContents) = 0;
  virtual  ::Uts::ErrorCode::type sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents) = 0;
  virtual  ::Uts::ErrorCode::type forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem) = 0;
  virtual int32_t getEsn() = 0;
  virtual  ::Uts::ErrorCode::type setEsn(const int32_t esn) = 0;
  virtual void getImei(std::string& _return, const int32_t subscriptionId) = 0;
  virtual  ::Uts::ErrorCode::type setImei(const std::string& imei, const int32_t subscriptionId) = 0;
  virtual int64_t getMeid(const int32_t subscriptionId) = 0;
  virtual  ::Uts::ErrorCode::type setMeid(const int64_t meid, const int32_t subscriptionId) = 0;
  virtual bool checkSpc(const std::string& spc) = 0;
  virtual bool provisionSpc(const std::string& currentSpc, const std::string& newSpc) = 0;
  virtual void efsReadFromModemLog(std::string& _return) = 0;
  virtual  ::Uts::ErrorCode::type configureService(const DeviceConfigOptions& deviceConfigOptions) = 0;
};

class DeviceConfigServiceIfFactory {
 public:
  typedef DeviceConfigServiceIf Handler;

  virtual ~DeviceConfigServiceIfFactory() {}

  virtual DeviceConfigServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(DeviceConfigServiceIf* /* handler */) = 0;
};

class DeviceConfigServiceIfSingletonFactory : virtual public DeviceConfigServiceIfFactory {
 public:
  DeviceConfigServiceIfSingletonFactory(const ::std::shared_ptr<DeviceConfigServiceIf>& iface) : iface_(iface) {}
  virtual ~DeviceConfigServiceIfSingletonFactory() {}

  virtual DeviceConfigServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(DeviceConfigServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<DeviceConfigServiceIf> iface_;
};

class DeviceConfigServiceNull : virtual public DeviceConfigServiceIf {
 public:
  virtual ~DeviceConfigServiceNull() {}
  void getLastError( ::Uts::ErrorType& /* _return */) {
    return;
  }
  int64_t getDevice() {
    int64_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type initializeService() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t /* diagProtocolHandle */, const int64_t /* qmiProtocolHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type initializeServiceWithOptions(const DeviceConfigConnectionOptions& /* connectionOptions */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type destroyService() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void doXqcnOperation( ::Uts::DeviceConfigResp& /* _return */, const DeviceConfigOptions& /* deviceConfigOptions */) {
    return;
  }
  void backupToXqcn(std::string& /* _return */, const std::string& /* serviceProgrammingCode */, const bool /* resetUponCompletion */, const int32_t /* resetTimeout */, const std::string& /* filterFileContents */) {
    return;
  }
   ::Uts::ErrorCode::type restoreFromXqcn(const std::string& /* xqcnFileContents */, const std::string& /* serviceProgrammingCode */, const bool /* allowEsnMismatch */, const bool /* resetUponCompletion */, const int32_t /* resetTimeout */, const std::string& /* filterFileContents */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  int64_t pdcGetMbnMaxStorage(const PdcMbnType::type /* mbnType */) {
    int64_t _return = 0;
    return _return;
  }
  int64_t pdcGetMbnStorageUsage(const PdcMbnType::type /* mbnType */) {
    int64_t _return = 0;
    return _return;
  }
  int64_t pdcGetMbnCount(const PdcMbnType::type /* mbnType */) {
    int64_t _return = 0;
    return _return;
  }
  void pdcGetMbnList(std::vector<PdcMbnInfo> & /* _return */, const PdcMbnType::type /* mbnType */) {
    return;
  }
  void pdcGetDefaultMbnInfo(PdcMbnInfo& /* _return */, const PdcMbnType::type /* mbnType */) {
    return;
  }
  void pdcGetMbnId(std::string& /* _return */, const std::string& /* mbnContent */) {
    return;
  }
   ::Uts::ErrorCode::type pdcWriteMbn(const PdcMbnType::type /* mbnType */, const std::string& /* mbnContent */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void pdcReadMbn(std::string& /* _return */, const PdcMbnType::type /* mbnType */, const std::string& /* mbnId */, const int32_t /* subId */) {
    return;
  }
   ::Uts::ErrorCode::type pdcRemoveMbn(const PdcMbnType::type /* mbnType */, const std::string& /* mbnId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void pdcGetActiveMbn(std::string& /* _return */, const PdcMbnType::type /* mbnType */, const int32_t /* subId */, const int32_t /* slotId */) {
    return;
  }
  void pdcGetPendingMbn(std::string& /* _return */, const PdcMbnType::type /* mbnType */, const int32_t /* subId */, const int32_t /* slotId */) {
    return;
  }
  void pdcValidateMbn(PdcMbnResult& /* _return */, const PdcMbnType::type /* mbnType */, const std::string& /* mbnId */, const int32_t /* subId */, const std::string& /* remotePath */) {
    return;
  }
   ::Uts::ErrorCode::type pdcSelectMbn(const PdcMbnType::type /* mbnType */, const std::string& /* mbnId */, const int32_t /* subId */, const int32_t /* slotId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type pdcActivateMbn(const PdcMbnType::type /* mbnType */, const int32_t /* subId */, const int32_t /* slotId */, const int32_t /* mode */, const int32_t /* timeout */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type pdcDeactivateMbn(const PdcMbnType::type /* mbnType */, const int32_t /* subId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  int32_t pdcGetConfiguration(const int32_t /* slotId */, const PdcConfigurationType::type /* feature */) {
    int32_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type pdcSetConfiguration(const int32_t /* slotId */, const PdcConfigurationType::type /* feature */, const int32_t /* value */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  bool nvIsItemSupported(const std::string& /* nvItemNameOrId */, const int32_t /* subscriptionId */) {
    bool _return = false;
    return _return;
  }
  void nvReadItem(NvData& /* _return */, const std::string& /* nvItemNameOrId */, const int32_t /* subscriptionId */, const int8_t /* index */, const NvReturns& /* returnConfig */) {
    return;
  }
   ::Uts::ErrorCode::type nvSetItem(const std::string& /* nvItemNameOrId */, const std::string& /* valueList */, const int32_t /* subscriptionId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type nvSetOtpItem(const std::string& /* nvItemNameOrId */, const std::string& /* valueList */, const int32_t /* subscriptionId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void nvGetAllItems(std::vector< ::Uts::NvItem> & /* _return */) {
    return;
  }
  void nvGetItemDefinition(std::string& /* _return */, const std::string& /* nvItemNameOrId */) {
    return;
  }
  bool efsHasAlternateFileSystem() {
    bool _return = false;
    return _return;
  }
   ::Uts::ErrorCode::type efsCreateDirectory(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type efsRemoveDirectory(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type efsRemoveTree(const std::string& /* pathName */, const FileSystem::type /* efsSytem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void efsGetDirectoryContents(std::vector<EfsItem> & /* _return */, const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
    return;
  }
   ::Uts::ErrorCode::type efsPutFile(const std::string& /* pathName */, const std::string& /* buffer */, const FileSystem::type /* efsSystem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void efsGetFile(std::string& /* _return */, const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
    return;
  }
   ::Uts::ErrorCode::type efsDeleteFile(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type efsRename(const std::string& /* existingName */, const std::string& /* newName */, const FileSystem::type /* efsSystem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  bool efsPathExists(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
    bool _return = false;
    return _return;
  }
  bool efsIsDirectory(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
    bool _return = false;
    return _return;
  }
  bool efsIsFile(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
    bool _return = false;
    return _return;
  }
  int64_t efsGetFileSize(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
    int64_t _return = 0;
    return _return;
  }
  int64_t efsGetAvailableSpace(const FileSystem::type /* efsSystem */) {
    int64_t _return = 0;
    return _return;
  }
  void efsGetFileCheckSum(std::string& /* _return */, const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
    return;
  }
  void efsGetFileAttributes(EfsFileAttributes& /* _return */, const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
    return;
  }
  bool efsIsReady() {
    bool _return = false;
    return _return;
  }
   ::Uts::ErrorCode::type createGoldenCopy(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type createCefsCopy(const std::string& /* cefsSavePath */, const FileSystem::type /* efsSystem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void requestPrl(std::string& /* _return */, const int32_t /* subscriptionId */, const int8_t /* index */) {
    return;
  }
  void backupPrl(std::string& /* _return */) {
    return;
  }
   ::Uts::ErrorCode::type restorePrl(const std::string& /* xqcnFileContents */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type sendPrl(const int32_t /* subscriptionId */, const int8_t /* index */, const std::string& /* prlFileContents */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type forceEfsSync(const std::string& /* pathName */, const FileSystem::type /* efsSystem */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  int32_t getEsn() {
    int32_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type setEsn(const int32_t /* esn */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getImei(std::string& /* _return */, const int32_t /* subscriptionId */) {
    return;
  }
   ::Uts::ErrorCode::type setImei(const std::string& /* imei */, const int32_t /* subscriptionId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  int64_t getMeid(const int32_t /* subscriptionId */) {
    int64_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type setMeid(const int64_t /* meid */, const int32_t /* subscriptionId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  bool checkSpc(const std::string& /* spc */) {
    bool _return = false;
    return _return;
  }
  bool provisionSpc(const std::string& /* currentSpc */, const std::string& /* newSpc */) {
    bool _return = false;
    return _return;
  }
  void efsReadFromModemLog(std::string& /* _return */) {
    return;
  }
   ::Uts::ErrorCode::type configureService(const DeviceConfigOptions& /* deviceConfigOptions */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
};


class DeviceConfigService_getLastError_args {
 public:

  DeviceConfigService_getLastError_args(const DeviceConfigService_getLastError_args&);
  DeviceConfigService_getLastError_args& operator=(const DeviceConfigService_getLastError_args&);
  DeviceConfigService_getLastError_args() {
  }

  virtual ~DeviceConfigService_getLastError_args() noexcept;

  bool operator == (const DeviceConfigService_getLastError_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_getLastError_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getLastError_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_getLastError_pargs {
 public:


  virtual ~DeviceConfigService_getLastError_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getLastError_result__isset {
  _DeviceConfigService_getLastError_result__isset() : success(false) {}
  bool success :1;
} _DeviceConfigService_getLastError_result__isset;

class DeviceConfigService_getLastError_result {
 public:

  DeviceConfigService_getLastError_result(const DeviceConfigService_getLastError_result&);
  DeviceConfigService_getLastError_result& operator=(const DeviceConfigService_getLastError_result&);
  DeviceConfigService_getLastError_result() {
  }

  virtual ~DeviceConfigService_getLastError_result() noexcept;
   ::Uts::ErrorType success;

  _DeviceConfigService_getLastError_result__isset __isset;

  void __set_success(const  ::Uts::ErrorType& val);

  bool operator == (const DeviceConfigService_getLastError_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_getLastError_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getLastError_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getLastError_presult__isset {
  _DeviceConfigService_getLastError_presult__isset() : success(false) {}
  bool success :1;
} _DeviceConfigService_getLastError_presult__isset;

class DeviceConfigService_getLastError_presult {
 public:


  virtual ~DeviceConfigService_getLastError_presult() noexcept;
   ::Uts::ErrorType* success;

  _DeviceConfigService_getLastError_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_getDevice_args {
 public:

  DeviceConfigService_getDevice_args(const DeviceConfigService_getDevice_args&);
  DeviceConfigService_getDevice_args& operator=(const DeviceConfigService_getDevice_args&);
  DeviceConfigService_getDevice_args() {
  }

  virtual ~DeviceConfigService_getDevice_args() noexcept;

  bool operator == (const DeviceConfigService_getDevice_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_getDevice_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getDevice_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_getDevice_pargs {
 public:


  virtual ~DeviceConfigService_getDevice_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getDevice_result__isset {
  _DeviceConfigService_getDevice_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_getDevice_result__isset;

class DeviceConfigService_getDevice_result {
 public:

  DeviceConfigService_getDevice_result(const DeviceConfigService_getDevice_result&);
  DeviceConfigService_getDevice_result& operator=(const DeviceConfigService_getDevice_result&);
  DeviceConfigService_getDevice_result() : success(0) {
  }

  virtual ~DeviceConfigService_getDevice_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceConfigService_getDevice_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_getDevice_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_getDevice_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getDevice_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getDevice_presult__isset {
  _DeviceConfigService_getDevice_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_getDevice_presult__isset;

class DeviceConfigService_getDevice_presult {
 public:


  virtual ~DeviceConfigService_getDevice_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_getDevice_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_initializeService_args {
 public:

  DeviceConfigService_initializeService_args(const DeviceConfigService_initializeService_args&);
  DeviceConfigService_initializeService_args& operator=(const DeviceConfigService_initializeService_args&);
  DeviceConfigService_initializeService_args() {
  }

  virtual ~DeviceConfigService_initializeService_args() noexcept;

  bool operator == (const DeviceConfigService_initializeService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_initializeService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_initializeService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_initializeService_pargs {
 public:


  virtual ~DeviceConfigService_initializeService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_initializeService_result__isset {
  _DeviceConfigService_initializeService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_initializeService_result__isset;

class DeviceConfigService_initializeService_result {
 public:

  DeviceConfigService_initializeService_result(const DeviceConfigService_initializeService_result&);
  DeviceConfigService_initializeService_result& operator=(const DeviceConfigService_initializeService_result&);
  DeviceConfigService_initializeService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_initializeService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_initializeService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_initializeService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_initializeService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_initializeService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_initializeService_presult__isset {
  _DeviceConfigService_initializeService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_initializeService_presult__isset;

class DeviceConfigService_initializeService_presult {
 public:


  virtual ~DeviceConfigService_initializeService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_initializeService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_initializeServiceByProtocol_args__isset {
  _DeviceConfigService_initializeServiceByProtocol_args__isset() : diagProtocolHandle(false), qmiProtocolHandle(false) {}
  bool diagProtocolHandle :1;
  bool qmiProtocolHandle :1;
} _DeviceConfigService_initializeServiceByProtocol_args__isset;

class DeviceConfigService_initializeServiceByProtocol_args {
 public:

  DeviceConfigService_initializeServiceByProtocol_args(const DeviceConfigService_initializeServiceByProtocol_args&);
  DeviceConfigService_initializeServiceByProtocol_args& operator=(const DeviceConfigService_initializeServiceByProtocol_args&);
  DeviceConfigService_initializeServiceByProtocol_args() : diagProtocolHandle(0), qmiProtocolHandle(0) {
  }

  virtual ~DeviceConfigService_initializeServiceByProtocol_args() noexcept;
  int64_t diagProtocolHandle;
  int64_t qmiProtocolHandle;

  _DeviceConfigService_initializeServiceByProtocol_args__isset __isset;

  void __set_diagProtocolHandle(const int64_t val);

  void __set_qmiProtocolHandle(const int64_t val);

  bool operator == (const DeviceConfigService_initializeServiceByProtocol_args & rhs) const
  {
    if (!(diagProtocolHandle == rhs.diagProtocolHandle))
      return false;
    if (!(qmiProtocolHandle == rhs.qmiProtocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_initializeServiceByProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_initializeServiceByProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_initializeServiceByProtocol_pargs {
 public:


  virtual ~DeviceConfigService_initializeServiceByProtocol_pargs() noexcept;
  const int64_t* diagProtocolHandle;
  const int64_t* qmiProtocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_initializeServiceByProtocol_result__isset {
  _DeviceConfigService_initializeServiceByProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_initializeServiceByProtocol_result__isset;

class DeviceConfigService_initializeServiceByProtocol_result {
 public:

  DeviceConfigService_initializeServiceByProtocol_result(const DeviceConfigService_initializeServiceByProtocol_result&);
  DeviceConfigService_initializeServiceByProtocol_result& operator=(const DeviceConfigService_initializeServiceByProtocol_result&);
  DeviceConfigService_initializeServiceByProtocol_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_initializeServiceByProtocol_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_initializeServiceByProtocol_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_initializeServiceByProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_initializeServiceByProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_initializeServiceByProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_initializeServiceByProtocol_presult__isset {
  _DeviceConfigService_initializeServiceByProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_initializeServiceByProtocol_presult__isset;

class DeviceConfigService_initializeServiceByProtocol_presult {
 public:


  virtual ~DeviceConfigService_initializeServiceByProtocol_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_initializeServiceByProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_initializeServiceWithOptions_args__isset {
  _DeviceConfigService_initializeServiceWithOptions_args__isset() : connectionOptions(false) {}
  bool connectionOptions :1;
} _DeviceConfigService_initializeServiceWithOptions_args__isset;

class DeviceConfigService_initializeServiceWithOptions_args {
 public:

  DeviceConfigService_initializeServiceWithOptions_args(const DeviceConfigService_initializeServiceWithOptions_args&);
  DeviceConfigService_initializeServiceWithOptions_args& operator=(const DeviceConfigService_initializeServiceWithOptions_args&);
  DeviceConfigService_initializeServiceWithOptions_args() {
  }

  virtual ~DeviceConfigService_initializeServiceWithOptions_args() noexcept;
  DeviceConfigConnectionOptions connectionOptions;

  _DeviceConfigService_initializeServiceWithOptions_args__isset __isset;

  void __set_connectionOptions(const DeviceConfigConnectionOptions& val);

  bool operator == (const DeviceConfigService_initializeServiceWithOptions_args & rhs) const
  {
    if (!(connectionOptions == rhs.connectionOptions))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_initializeServiceWithOptions_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_initializeServiceWithOptions_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_initializeServiceWithOptions_pargs {
 public:


  virtual ~DeviceConfigService_initializeServiceWithOptions_pargs() noexcept;
  const DeviceConfigConnectionOptions* connectionOptions;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_initializeServiceWithOptions_result__isset {
  _DeviceConfigService_initializeServiceWithOptions_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_initializeServiceWithOptions_result__isset;

class DeviceConfigService_initializeServiceWithOptions_result {
 public:

  DeviceConfigService_initializeServiceWithOptions_result(const DeviceConfigService_initializeServiceWithOptions_result&);
  DeviceConfigService_initializeServiceWithOptions_result& operator=(const DeviceConfigService_initializeServiceWithOptions_result&);
  DeviceConfigService_initializeServiceWithOptions_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_initializeServiceWithOptions_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_initializeServiceWithOptions_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_initializeServiceWithOptions_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_initializeServiceWithOptions_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_initializeServiceWithOptions_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_initializeServiceWithOptions_presult__isset {
  _DeviceConfigService_initializeServiceWithOptions_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_initializeServiceWithOptions_presult__isset;

class DeviceConfigService_initializeServiceWithOptions_presult {
 public:


  virtual ~DeviceConfigService_initializeServiceWithOptions_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_initializeServiceWithOptions_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_destroyService_args {
 public:

  DeviceConfigService_destroyService_args(const DeviceConfigService_destroyService_args&);
  DeviceConfigService_destroyService_args& operator=(const DeviceConfigService_destroyService_args&);
  DeviceConfigService_destroyService_args() {
  }

  virtual ~DeviceConfigService_destroyService_args() noexcept;

  bool operator == (const DeviceConfigService_destroyService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_destroyService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_destroyService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_destroyService_pargs {
 public:


  virtual ~DeviceConfigService_destroyService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_destroyService_result__isset {
  _DeviceConfigService_destroyService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_destroyService_result__isset;

class DeviceConfigService_destroyService_result {
 public:

  DeviceConfigService_destroyService_result(const DeviceConfigService_destroyService_result&);
  DeviceConfigService_destroyService_result& operator=(const DeviceConfigService_destroyService_result&);
  DeviceConfigService_destroyService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_destroyService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_destroyService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_destroyService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_destroyService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_destroyService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_destroyService_presult__isset {
  _DeviceConfigService_destroyService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_destroyService_presult__isset;

class DeviceConfigService_destroyService_presult {
 public:


  virtual ~DeviceConfigService_destroyService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_destroyService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_doXqcnOperation_args__isset {
  _DeviceConfigService_doXqcnOperation_args__isset() : deviceConfigOptions(false) {}
  bool deviceConfigOptions :1;
} _DeviceConfigService_doXqcnOperation_args__isset;

class DeviceConfigService_doXqcnOperation_args {
 public:

  DeviceConfigService_doXqcnOperation_args(const DeviceConfigService_doXqcnOperation_args&);
  DeviceConfigService_doXqcnOperation_args& operator=(const DeviceConfigService_doXqcnOperation_args&);
  DeviceConfigService_doXqcnOperation_args() {
  }

  virtual ~DeviceConfigService_doXqcnOperation_args() noexcept;
  DeviceConfigOptions deviceConfigOptions;

  _DeviceConfigService_doXqcnOperation_args__isset __isset;

  void __set_deviceConfigOptions(const DeviceConfigOptions& val);

  bool operator == (const DeviceConfigService_doXqcnOperation_args & rhs) const
  {
    if (!(deviceConfigOptions == rhs.deviceConfigOptions))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_doXqcnOperation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_doXqcnOperation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_doXqcnOperation_pargs {
 public:


  virtual ~DeviceConfigService_doXqcnOperation_pargs() noexcept;
  const DeviceConfigOptions* deviceConfigOptions;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_doXqcnOperation_result__isset {
  _DeviceConfigService_doXqcnOperation_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_doXqcnOperation_result__isset;

class DeviceConfigService_doXqcnOperation_result {
 public:

  DeviceConfigService_doXqcnOperation_result(const DeviceConfigService_doXqcnOperation_result&);
  DeviceConfigService_doXqcnOperation_result& operator=(const DeviceConfigService_doXqcnOperation_result&);
  DeviceConfigService_doXqcnOperation_result() {
  }

  virtual ~DeviceConfigService_doXqcnOperation_result() noexcept;
   ::Uts::DeviceConfigResp success;
   ::Uts::AppException e;

  _DeviceConfigService_doXqcnOperation_result__isset __isset;

  void __set_success(const  ::Uts::DeviceConfigResp& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_doXqcnOperation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_doXqcnOperation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_doXqcnOperation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_doXqcnOperation_presult__isset {
  _DeviceConfigService_doXqcnOperation_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_doXqcnOperation_presult__isset;

class DeviceConfigService_doXqcnOperation_presult {
 public:


  virtual ~DeviceConfigService_doXqcnOperation_presult() noexcept;
   ::Uts::DeviceConfigResp* success;
   ::Uts::AppException e;

  _DeviceConfigService_doXqcnOperation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_backupToXqcn_args__isset {
  _DeviceConfigService_backupToXqcn_args__isset() : serviceProgrammingCode(false), resetUponCompletion(false), resetTimeout(false), filterFileContents(false) {}
  bool serviceProgrammingCode :1;
  bool resetUponCompletion :1;
  bool resetTimeout :1;
  bool filterFileContents :1;
} _DeviceConfigService_backupToXqcn_args__isset;

class DeviceConfigService_backupToXqcn_args {
 public:

  DeviceConfigService_backupToXqcn_args(const DeviceConfigService_backupToXqcn_args&);
  DeviceConfigService_backupToXqcn_args& operator=(const DeviceConfigService_backupToXqcn_args&);
  DeviceConfigService_backupToXqcn_args() : serviceProgrammingCode(), resetUponCompletion(0), resetTimeout(0), filterFileContents() {
  }

  virtual ~DeviceConfigService_backupToXqcn_args() noexcept;
  std::string serviceProgrammingCode;
  bool resetUponCompletion;
  int32_t resetTimeout;
  std::string filterFileContents;

  _DeviceConfigService_backupToXqcn_args__isset __isset;

  void __set_serviceProgrammingCode(const std::string& val);

  void __set_resetUponCompletion(const bool val);

  void __set_resetTimeout(const int32_t val);

  void __set_filterFileContents(const std::string& val);

  bool operator == (const DeviceConfigService_backupToXqcn_args & rhs) const
  {
    if (!(serviceProgrammingCode == rhs.serviceProgrammingCode))
      return false;
    if (!(resetUponCompletion == rhs.resetUponCompletion))
      return false;
    if (!(resetTimeout == rhs.resetTimeout))
      return false;
    if (!(filterFileContents == rhs.filterFileContents))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_backupToXqcn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_backupToXqcn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_backupToXqcn_pargs {
 public:


  virtual ~DeviceConfigService_backupToXqcn_pargs() noexcept;
  const std::string* serviceProgrammingCode;
  const bool* resetUponCompletion;
  const int32_t* resetTimeout;
  const std::string* filterFileContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_backupToXqcn_result__isset {
  _DeviceConfigService_backupToXqcn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_backupToXqcn_result__isset;

class DeviceConfigService_backupToXqcn_result {
 public:

  DeviceConfigService_backupToXqcn_result(const DeviceConfigService_backupToXqcn_result&);
  DeviceConfigService_backupToXqcn_result& operator=(const DeviceConfigService_backupToXqcn_result&);
  DeviceConfigService_backupToXqcn_result() : success() {
  }

  virtual ~DeviceConfigService_backupToXqcn_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_backupToXqcn_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_backupToXqcn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_backupToXqcn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_backupToXqcn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_backupToXqcn_presult__isset {
  _DeviceConfigService_backupToXqcn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_backupToXqcn_presult__isset;

class DeviceConfigService_backupToXqcn_presult {
 public:


  virtual ~DeviceConfigService_backupToXqcn_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_backupToXqcn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_restoreFromXqcn_args__isset {
  _DeviceConfigService_restoreFromXqcn_args__isset() : xqcnFileContents(false), serviceProgrammingCode(false), allowEsnMismatch(false), resetUponCompletion(false), resetTimeout(false), filterFileContents(false) {}
  bool xqcnFileContents :1;
  bool serviceProgrammingCode :1;
  bool allowEsnMismatch :1;
  bool resetUponCompletion :1;
  bool resetTimeout :1;
  bool filterFileContents :1;
} _DeviceConfigService_restoreFromXqcn_args__isset;

class DeviceConfigService_restoreFromXqcn_args {
 public:

  DeviceConfigService_restoreFromXqcn_args(const DeviceConfigService_restoreFromXqcn_args&);
  DeviceConfigService_restoreFromXqcn_args& operator=(const DeviceConfigService_restoreFromXqcn_args&);
  DeviceConfigService_restoreFromXqcn_args() : xqcnFileContents(), serviceProgrammingCode(), allowEsnMismatch(0), resetUponCompletion(0), resetTimeout(0), filterFileContents() {
  }

  virtual ~DeviceConfigService_restoreFromXqcn_args() noexcept;
  std::string xqcnFileContents;
  std::string serviceProgrammingCode;
  bool allowEsnMismatch;
  bool resetUponCompletion;
  int32_t resetTimeout;
  std::string filterFileContents;

  _DeviceConfigService_restoreFromXqcn_args__isset __isset;

  void __set_xqcnFileContents(const std::string& val);

  void __set_serviceProgrammingCode(const std::string& val);

  void __set_allowEsnMismatch(const bool val);

  void __set_resetUponCompletion(const bool val);

  void __set_resetTimeout(const int32_t val);

  void __set_filterFileContents(const std::string& val);

  bool operator == (const DeviceConfigService_restoreFromXqcn_args & rhs) const
  {
    if (!(xqcnFileContents == rhs.xqcnFileContents))
      return false;
    if (!(serviceProgrammingCode == rhs.serviceProgrammingCode))
      return false;
    if (!(allowEsnMismatch == rhs.allowEsnMismatch))
      return false;
    if (!(resetUponCompletion == rhs.resetUponCompletion))
      return false;
    if (!(resetTimeout == rhs.resetTimeout))
      return false;
    if (!(filterFileContents == rhs.filterFileContents))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_restoreFromXqcn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_restoreFromXqcn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_restoreFromXqcn_pargs {
 public:


  virtual ~DeviceConfigService_restoreFromXqcn_pargs() noexcept;
  const std::string* xqcnFileContents;
  const std::string* serviceProgrammingCode;
  const bool* allowEsnMismatch;
  const bool* resetUponCompletion;
  const int32_t* resetTimeout;
  const std::string* filterFileContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_restoreFromXqcn_result__isset {
  _DeviceConfigService_restoreFromXqcn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_restoreFromXqcn_result__isset;

class DeviceConfigService_restoreFromXqcn_result {
 public:

  DeviceConfigService_restoreFromXqcn_result(const DeviceConfigService_restoreFromXqcn_result&);
  DeviceConfigService_restoreFromXqcn_result& operator=(const DeviceConfigService_restoreFromXqcn_result&);
  DeviceConfigService_restoreFromXqcn_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_restoreFromXqcn_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_restoreFromXqcn_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_restoreFromXqcn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_restoreFromXqcn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_restoreFromXqcn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_restoreFromXqcn_presult__isset {
  _DeviceConfigService_restoreFromXqcn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_restoreFromXqcn_presult__isset;

class DeviceConfigService_restoreFromXqcn_presult {
 public:


  virtual ~DeviceConfigService_restoreFromXqcn_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_restoreFromXqcn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetMbnMaxStorage_args__isset {
  _DeviceConfigService_pdcGetMbnMaxStorage_args__isset() : mbnType(false) {}
  bool mbnType :1;
} _DeviceConfigService_pdcGetMbnMaxStorage_args__isset;

class DeviceConfigService_pdcGetMbnMaxStorage_args {
 public:

  DeviceConfigService_pdcGetMbnMaxStorage_args(const DeviceConfigService_pdcGetMbnMaxStorage_args&);
  DeviceConfigService_pdcGetMbnMaxStorage_args& operator=(const DeviceConfigService_pdcGetMbnMaxStorage_args&);
  DeviceConfigService_pdcGetMbnMaxStorage_args() : mbnType((PdcMbnType::type)0) {
  }

  virtual ~DeviceConfigService_pdcGetMbnMaxStorage_args() noexcept;
  PdcMbnType::type mbnType;

  _DeviceConfigService_pdcGetMbnMaxStorage_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  bool operator == (const DeviceConfigService_pdcGetMbnMaxStorage_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnMaxStorage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnMaxStorage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetMbnMaxStorage_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetMbnMaxStorage_pargs() noexcept;
  const PdcMbnType::type* mbnType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnMaxStorage_result__isset {
  _DeviceConfigService_pdcGetMbnMaxStorage_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnMaxStorage_result__isset;

class DeviceConfigService_pdcGetMbnMaxStorage_result {
 public:

  DeviceConfigService_pdcGetMbnMaxStorage_result(const DeviceConfigService_pdcGetMbnMaxStorage_result&);
  DeviceConfigService_pdcGetMbnMaxStorage_result& operator=(const DeviceConfigService_pdcGetMbnMaxStorage_result&);
  DeviceConfigService_pdcGetMbnMaxStorage_result() : success(0) {
  }

  virtual ~DeviceConfigService_pdcGetMbnMaxStorage_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnMaxStorage_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetMbnMaxStorage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnMaxStorage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnMaxStorage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnMaxStorage_presult__isset {
  _DeviceConfigService_pdcGetMbnMaxStorage_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnMaxStorage_presult__isset;

class DeviceConfigService_pdcGetMbnMaxStorage_presult {
 public:


  virtual ~DeviceConfigService_pdcGetMbnMaxStorage_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnMaxStorage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetMbnStorageUsage_args__isset {
  _DeviceConfigService_pdcGetMbnStorageUsage_args__isset() : mbnType(false) {}
  bool mbnType :1;
} _DeviceConfigService_pdcGetMbnStorageUsage_args__isset;

class DeviceConfigService_pdcGetMbnStorageUsage_args {
 public:

  DeviceConfigService_pdcGetMbnStorageUsage_args(const DeviceConfigService_pdcGetMbnStorageUsage_args&);
  DeviceConfigService_pdcGetMbnStorageUsage_args& operator=(const DeviceConfigService_pdcGetMbnStorageUsage_args&);
  DeviceConfigService_pdcGetMbnStorageUsage_args() : mbnType((PdcMbnType::type)0) {
  }

  virtual ~DeviceConfigService_pdcGetMbnStorageUsage_args() noexcept;
  PdcMbnType::type mbnType;

  _DeviceConfigService_pdcGetMbnStorageUsage_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  bool operator == (const DeviceConfigService_pdcGetMbnStorageUsage_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnStorageUsage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnStorageUsage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetMbnStorageUsage_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetMbnStorageUsage_pargs() noexcept;
  const PdcMbnType::type* mbnType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnStorageUsage_result__isset {
  _DeviceConfigService_pdcGetMbnStorageUsage_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnStorageUsage_result__isset;

class DeviceConfigService_pdcGetMbnStorageUsage_result {
 public:

  DeviceConfigService_pdcGetMbnStorageUsage_result(const DeviceConfigService_pdcGetMbnStorageUsage_result&);
  DeviceConfigService_pdcGetMbnStorageUsage_result& operator=(const DeviceConfigService_pdcGetMbnStorageUsage_result&);
  DeviceConfigService_pdcGetMbnStorageUsage_result() : success(0) {
  }

  virtual ~DeviceConfigService_pdcGetMbnStorageUsage_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnStorageUsage_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetMbnStorageUsage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnStorageUsage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnStorageUsage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnStorageUsage_presult__isset {
  _DeviceConfigService_pdcGetMbnStorageUsage_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnStorageUsage_presult__isset;

class DeviceConfigService_pdcGetMbnStorageUsage_presult {
 public:


  virtual ~DeviceConfigService_pdcGetMbnStorageUsage_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnStorageUsage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetMbnCount_args__isset {
  _DeviceConfigService_pdcGetMbnCount_args__isset() : mbnType(false) {}
  bool mbnType :1;
} _DeviceConfigService_pdcGetMbnCount_args__isset;

class DeviceConfigService_pdcGetMbnCount_args {
 public:

  DeviceConfigService_pdcGetMbnCount_args(const DeviceConfigService_pdcGetMbnCount_args&);
  DeviceConfigService_pdcGetMbnCount_args& operator=(const DeviceConfigService_pdcGetMbnCount_args&);
  DeviceConfigService_pdcGetMbnCount_args() : mbnType((PdcMbnType::type)0) {
  }

  virtual ~DeviceConfigService_pdcGetMbnCount_args() noexcept;
  PdcMbnType::type mbnType;

  _DeviceConfigService_pdcGetMbnCount_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  bool operator == (const DeviceConfigService_pdcGetMbnCount_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnCount_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnCount_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetMbnCount_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetMbnCount_pargs() noexcept;
  const PdcMbnType::type* mbnType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnCount_result__isset {
  _DeviceConfigService_pdcGetMbnCount_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnCount_result__isset;

class DeviceConfigService_pdcGetMbnCount_result {
 public:

  DeviceConfigService_pdcGetMbnCount_result(const DeviceConfigService_pdcGetMbnCount_result&);
  DeviceConfigService_pdcGetMbnCount_result& operator=(const DeviceConfigService_pdcGetMbnCount_result&);
  DeviceConfigService_pdcGetMbnCount_result() : success(0) {
  }

  virtual ~DeviceConfigService_pdcGetMbnCount_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnCount_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetMbnCount_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnCount_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnCount_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnCount_presult__isset {
  _DeviceConfigService_pdcGetMbnCount_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnCount_presult__isset;

class DeviceConfigService_pdcGetMbnCount_presult {
 public:


  virtual ~DeviceConfigService_pdcGetMbnCount_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnCount_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetMbnList_args__isset {
  _DeviceConfigService_pdcGetMbnList_args__isset() : mbnType(false) {}
  bool mbnType :1;
} _DeviceConfigService_pdcGetMbnList_args__isset;

class DeviceConfigService_pdcGetMbnList_args {
 public:

  DeviceConfigService_pdcGetMbnList_args(const DeviceConfigService_pdcGetMbnList_args&);
  DeviceConfigService_pdcGetMbnList_args& operator=(const DeviceConfigService_pdcGetMbnList_args&);
  DeviceConfigService_pdcGetMbnList_args() : mbnType((PdcMbnType::type)0) {
  }

  virtual ~DeviceConfigService_pdcGetMbnList_args() noexcept;
  PdcMbnType::type mbnType;

  _DeviceConfigService_pdcGetMbnList_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  bool operator == (const DeviceConfigService_pdcGetMbnList_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetMbnList_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetMbnList_pargs() noexcept;
  const PdcMbnType::type* mbnType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnList_result__isset {
  _DeviceConfigService_pdcGetMbnList_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnList_result__isset;

class DeviceConfigService_pdcGetMbnList_result {
 public:

  DeviceConfigService_pdcGetMbnList_result(const DeviceConfigService_pdcGetMbnList_result&);
  DeviceConfigService_pdcGetMbnList_result& operator=(const DeviceConfigService_pdcGetMbnList_result&);
  DeviceConfigService_pdcGetMbnList_result() {
  }

  virtual ~DeviceConfigService_pdcGetMbnList_result() noexcept;
  std::vector<PdcMbnInfo>  success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnList_result__isset __isset;

  void __set_success(const std::vector<PdcMbnInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetMbnList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnList_presult__isset {
  _DeviceConfigService_pdcGetMbnList_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnList_presult__isset;

class DeviceConfigService_pdcGetMbnList_presult {
 public:


  virtual ~DeviceConfigService_pdcGetMbnList_presult() noexcept;
  std::vector<PdcMbnInfo> * success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetDefaultMbnInfo_args__isset {
  _DeviceConfigService_pdcGetDefaultMbnInfo_args__isset() : mbnType(false) {}
  bool mbnType :1;
} _DeviceConfigService_pdcGetDefaultMbnInfo_args__isset;

class DeviceConfigService_pdcGetDefaultMbnInfo_args {
 public:

  DeviceConfigService_pdcGetDefaultMbnInfo_args(const DeviceConfigService_pdcGetDefaultMbnInfo_args&);
  DeviceConfigService_pdcGetDefaultMbnInfo_args& operator=(const DeviceConfigService_pdcGetDefaultMbnInfo_args&);
  DeviceConfigService_pdcGetDefaultMbnInfo_args() : mbnType((PdcMbnType::type)0) {
  }

  virtual ~DeviceConfigService_pdcGetDefaultMbnInfo_args() noexcept;
  PdcMbnType::type mbnType;

  _DeviceConfigService_pdcGetDefaultMbnInfo_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  bool operator == (const DeviceConfigService_pdcGetDefaultMbnInfo_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetDefaultMbnInfo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetDefaultMbnInfo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetDefaultMbnInfo_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetDefaultMbnInfo_pargs() noexcept;
  const PdcMbnType::type* mbnType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetDefaultMbnInfo_result__isset {
  _DeviceConfigService_pdcGetDefaultMbnInfo_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetDefaultMbnInfo_result__isset;

class DeviceConfigService_pdcGetDefaultMbnInfo_result {
 public:

  DeviceConfigService_pdcGetDefaultMbnInfo_result(const DeviceConfigService_pdcGetDefaultMbnInfo_result&);
  DeviceConfigService_pdcGetDefaultMbnInfo_result& operator=(const DeviceConfigService_pdcGetDefaultMbnInfo_result&);
  DeviceConfigService_pdcGetDefaultMbnInfo_result() {
  }

  virtual ~DeviceConfigService_pdcGetDefaultMbnInfo_result() noexcept;
  PdcMbnInfo success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetDefaultMbnInfo_result__isset __isset;

  void __set_success(const PdcMbnInfo& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetDefaultMbnInfo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetDefaultMbnInfo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetDefaultMbnInfo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetDefaultMbnInfo_presult__isset {
  _DeviceConfigService_pdcGetDefaultMbnInfo_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetDefaultMbnInfo_presult__isset;

class DeviceConfigService_pdcGetDefaultMbnInfo_presult {
 public:


  virtual ~DeviceConfigService_pdcGetDefaultMbnInfo_presult() noexcept;
  PdcMbnInfo* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetDefaultMbnInfo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetMbnId_args__isset {
  _DeviceConfigService_pdcGetMbnId_args__isset() : mbnContent(false) {}
  bool mbnContent :1;
} _DeviceConfigService_pdcGetMbnId_args__isset;

class DeviceConfigService_pdcGetMbnId_args {
 public:

  DeviceConfigService_pdcGetMbnId_args(const DeviceConfigService_pdcGetMbnId_args&);
  DeviceConfigService_pdcGetMbnId_args& operator=(const DeviceConfigService_pdcGetMbnId_args&);
  DeviceConfigService_pdcGetMbnId_args() : mbnContent() {
  }

  virtual ~DeviceConfigService_pdcGetMbnId_args() noexcept;
  std::string mbnContent;

  _DeviceConfigService_pdcGetMbnId_args__isset __isset;

  void __set_mbnContent(const std::string& val);

  bool operator == (const DeviceConfigService_pdcGetMbnId_args & rhs) const
  {
    if (!(mbnContent == rhs.mbnContent))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetMbnId_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetMbnId_pargs() noexcept;
  const std::string* mbnContent;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnId_result__isset {
  _DeviceConfigService_pdcGetMbnId_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnId_result__isset;

class DeviceConfigService_pdcGetMbnId_result {
 public:

  DeviceConfigService_pdcGetMbnId_result(const DeviceConfigService_pdcGetMbnId_result&);
  DeviceConfigService_pdcGetMbnId_result& operator=(const DeviceConfigService_pdcGetMbnId_result&);
  DeviceConfigService_pdcGetMbnId_result() : success() {
  }

  virtual ~DeviceConfigService_pdcGetMbnId_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnId_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetMbnId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetMbnId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetMbnId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetMbnId_presult__isset {
  _DeviceConfigService_pdcGetMbnId_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetMbnId_presult__isset;

class DeviceConfigService_pdcGetMbnId_presult {
 public:


  virtual ~DeviceConfigService_pdcGetMbnId_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetMbnId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcWriteMbn_args__isset {
  _DeviceConfigService_pdcWriteMbn_args__isset() : mbnType(false), mbnContent(false) {}
  bool mbnType :1;
  bool mbnContent :1;
} _DeviceConfigService_pdcWriteMbn_args__isset;

class DeviceConfigService_pdcWriteMbn_args {
 public:

  DeviceConfigService_pdcWriteMbn_args(const DeviceConfigService_pdcWriteMbn_args&);
  DeviceConfigService_pdcWriteMbn_args& operator=(const DeviceConfigService_pdcWriteMbn_args&);
  DeviceConfigService_pdcWriteMbn_args() : mbnType((PdcMbnType::type)0), mbnContent() {
  }

  virtual ~DeviceConfigService_pdcWriteMbn_args() noexcept;
  PdcMbnType::type mbnType;
  std::string mbnContent;

  _DeviceConfigService_pdcWriteMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_mbnContent(const std::string& val);

  bool operator == (const DeviceConfigService_pdcWriteMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(mbnContent == rhs.mbnContent))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcWriteMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcWriteMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcWriteMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcWriteMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const std::string* mbnContent;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcWriteMbn_result__isset {
  _DeviceConfigService_pdcWriteMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcWriteMbn_result__isset;

class DeviceConfigService_pdcWriteMbn_result {
 public:

  DeviceConfigService_pdcWriteMbn_result(const DeviceConfigService_pdcWriteMbn_result&);
  DeviceConfigService_pdcWriteMbn_result& operator=(const DeviceConfigService_pdcWriteMbn_result&);
  DeviceConfigService_pdcWriteMbn_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_pdcWriteMbn_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcWriteMbn_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcWriteMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcWriteMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcWriteMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcWriteMbn_presult__isset {
  _DeviceConfigService_pdcWriteMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcWriteMbn_presult__isset;

class DeviceConfigService_pdcWriteMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcWriteMbn_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcWriteMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcReadMbn_args__isset {
  _DeviceConfigService_pdcReadMbn_args__isset() : mbnType(false), mbnId(false), subId(false) {}
  bool mbnType :1;
  bool mbnId :1;
  bool subId :1;
} _DeviceConfigService_pdcReadMbn_args__isset;

class DeviceConfigService_pdcReadMbn_args {
 public:

  DeviceConfigService_pdcReadMbn_args(const DeviceConfigService_pdcReadMbn_args&);
  DeviceConfigService_pdcReadMbn_args& operator=(const DeviceConfigService_pdcReadMbn_args&);
  DeviceConfigService_pdcReadMbn_args() : mbnType((PdcMbnType::type)0), mbnId(), subId(0) {
  }

  virtual ~DeviceConfigService_pdcReadMbn_args() noexcept;
  PdcMbnType::type mbnType;
  std::string mbnId;
  int32_t subId;

  _DeviceConfigService_pdcReadMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_mbnId(const std::string& val);

  void __set_subId(const int32_t val);

  bool operator == (const DeviceConfigService_pdcReadMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(mbnId == rhs.mbnId))
      return false;
    if (!(subId == rhs.subId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcReadMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcReadMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcReadMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcReadMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const std::string* mbnId;
  const int32_t* subId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcReadMbn_result__isset {
  _DeviceConfigService_pdcReadMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcReadMbn_result__isset;

class DeviceConfigService_pdcReadMbn_result {
 public:

  DeviceConfigService_pdcReadMbn_result(const DeviceConfigService_pdcReadMbn_result&);
  DeviceConfigService_pdcReadMbn_result& operator=(const DeviceConfigService_pdcReadMbn_result&);
  DeviceConfigService_pdcReadMbn_result() : success() {
  }

  virtual ~DeviceConfigService_pdcReadMbn_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcReadMbn_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcReadMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcReadMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcReadMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcReadMbn_presult__isset {
  _DeviceConfigService_pdcReadMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcReadMbn_presult__isset;

class DeviceConfigService_pdcReadMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcReadMbn_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcReadMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcRemoveMbn_args__isset {
  _DeviceConfigService_pdcRemoveMbn_args__isset() : mbnType(false), mbnId(false) {}
  bool mbnType :1;
  bool mbnId :1;
} _DeviceConfigService_pdcRemoveMbn_args__isset;

class DeviceConfigService_pdcRemoveMbn_args {
 public:

  DeviceConfigService_pdcRemoveMbn_args(const DeviceConfigService_pdcRemoveMbn_args&);
  DeviceConfigService_pdcRemoveMbn_args& operator=(const DeviceConfigService_pdcRemoveMbn_args&);
  DeviceConfigService_pdcRemoveMbn_args() : mbnType((PdcMbnType::type)0), mbnId() {
  }

  virtual ~DeviceConfigService_pdcRemoveMbn_args() noexcept;
  PdcMbnType::type mbnType;
  std::string mbnId;

  _DeviceConfigService_pdcRemoveMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_mbnId(const std::string& val);

  bool operator == (const DeviceConfigService_pdcRemoveMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(mbnId == rhs.mbnId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcRemoveMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcRemoveMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcRemoveMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcRemoveMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const std::string* mbnId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcRemoveMbn_result__isset {
  _DeviceConfigService_pdcRemoveMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcRemoveMbn_result__isset;

class DeviceConfigService_pdcRemoveMbn_result {
 public:

  DeviceConfigService_pdcRemoveMbn_result(const DeviceConfigService_pdcRemoveMbn_result&);
  DeviceConfigService_pdcRemoveMbn_result& operator=(const DeviceConfigService_pdcRemoveMbn_result&);
  DeviceConfigService_pdcRemoveMbn_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_pdcRemoveMbn_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcRemoveMbn_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcRemoveMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcRemoveMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcRemoveMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcRemoveMbn_presult__isset {
  _DeviceConfigService_pdcRemoveMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcRemoveMbn_presult__isset;

class DeviceConfigService_pdcRemoveMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcRemoveMbn_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcRemoveMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetActiveMbn_args__isset {
  _DeviceConfigService_pdcGetActiveMbn_args__isset() : mbnType(false), subId(false), slotId(false) {}
  bool mbnType :1;
  bool subId :1;
  bool slotId :1;
} _DeviceConfigService_pdcGetActiveMbn_args__isset;

class DeviceConfigService_pdcGetActiveMbn_args {
 public:

  DeviceConfigService_pdcGetActiveMbn_args(const DeviceConfigService_pdcGetActiveMbn_args&);
  DeviceConfigService_pdcGetActiveMbn_args& operator=(const DeviceConfigService_pdcGetActiveMbn_args&);
  DeviceConfigService_pdcGetActiveMbn_args() : mbnType((PdcMbnType::type)0), subId(0), slotId(0) {
  }

  virtual ~DeviceConfigService_pdcGetActiveMbn_args() noexcept;
  PdcMbnType::type mbnType;
  int32_t subId;
  int32_t slotId;

  _DeviceConfigService_pdcGetActiveMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_subId(const int32_t val);

  void __set_slotId(const int32_t val);

  bool operator == (const DeviceConfigService_pdcGetActiveMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(subId == rhs.subId))
      return false;
    if (!(slotId == rhs.slotId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetActiveMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetActiveMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetActiveMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetActiveMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const int32_t* subId;
  const int32_t* slotId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetActiveMbn_result__isset {
  _DeviceConfigService_pdcGetActiveMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetActiveMbn_result__isset;

class DeviceConfigService_pdcGetActiveMbn_result {
 public:

  DeviceConfigService_pdcGetActiveMbn_result(const DeviceConfigService_pdcGetActiveMbn_result&);
  DeviceConfigService_pdcGetActiveMbn_result& operator=(const DeviceConfigService_pdcGetActiveMbn_result&);
  DeviceConfigService_pdcGetActiveMbn_result() : success() {
  }

  virtual ~DeviceConfigService_pdcGetActiveMbn_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetActiveMbn_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetActiveMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetActiveMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetActiveMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetActiveMbn_presult__isset {
  _DeviceConfigService_pdcGetActiveMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetActiveMbn_presult__isset;

class DeviceConfigService_pdcGetActiveMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcGetActiveMbn_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetActiveMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetPendingMbn_args__isset {
  _DeviceConfigService_pdcGetPendingMbn_args__isset() : mbnType(false), subId(false), slotId(false) {}
  bool mbnType :1;
  bool subId :1;
  bool slotId :1;
} _DeviceConfigService_pdcGetPendingMbn_args__isset;

class DeviceConfigService_pdcGetPendingMbn_args {
 public:

  DeviceConfigService_pdcGetPendingMbn_args(const DeviceConfigService_pdcGetPendingMbn_args&);
  DeviceConfigService_pdcGetPendingMbn_args& operator=(const DeviceConfigService_pdcGetPendingMbn_args&);
  DeviceConfigService_pdcGetPendingMbn_args() : mbnType((PdcMbnType::type)0), subId(0), slotId(0) {
  }

  virtual ~DeviceConfigService_pdcGetPendingMbn_args() noexcept;
  PdcMbnType::type mbnType;
  int32_t subId;
  int32_t slotId;

  _DeviceConfigService_pdcGetPendingMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_subId(const int32_t val);

  void __set_slotId(const int32_t val);

  bool operator == (const DeviceConfigService_pdcGetPendingMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(subId == rhs.subId))
      return false;
    if (!(slotId == rhs.slotId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetPendingMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetPendingMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetPendingMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetPendingMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const int32_t* subId;
  const int32_t* slotId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetPendingMbn_result__isset {
  _DeviceConfigService_pdcGetPendingMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetPendingMbn_result__isset;

class DeviceConfigService_pdcGetPendingMbn_result {
 public:

  DeviceConfigService_pdcGetPendingMbn_result(const DeviceConfigService_pdcGetPendingMbn_result&);
  DeviceConfigService_pdcGetPendingMbn_result& operator=(const DeviceConfigService_pdcGetPendingMbn_result&);
  DeviceConfigService_pdcGetPendingMbn_result() : success() {
  }

  virtual ~DeviceConfigService_pdcGetPendingMbn_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetPendingMbn_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetPendingMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetPendingMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetPendingMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetPendingMbn_presult__isset {
  _DeviceConfigService_pdcGetPendingMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetPendingMbn_presult__isset;

class DeviceConfigService_pdcGetPendingMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcGetPendingMbn_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetPendingMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcValidateMbn_args__isset {
  _DeviceConfigService_pdcValidateMbn_args__isset() : mbnType(false), mbnId(false), subId(false), remotePath(false) {}
  bool mbnType :1;
  bool mbnId :1;
  bool subId :1;
  bool remotePath :1;
} _DeviceConfigService_pdcValidateMbn_args__isset;

class DeviceConfigService_pdcValidateMbn_args {
 public:

  DeviceConfigService_pdcValidateMbn_args(const DeviceConfigService_pdcValidateMbn_args&);
  DeviceConfigService_pdcValidateMbn_args& operator=(const DeviceConfigService_pdcValidateMbn_args&);
  DeviceConfigService_pdcValidateMbn_args() : mbnType((PdcMbnType::type)0), mbnId(), subId(0), remotePath() {
  }

  virtual ~DeviceConfigService_pdcValidateMbn_args() noexcept;
  PdcMbnType::type mbnType;
  std::string mbnId;
  int32_t subId;
  std::string remotePath;

  _DeviceConfigService_pdcValidateMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_mbnId(const std::string& val);

  void __set_subId(const int32_t val);

  void __set_remotePath(const std::string& val);

  bool operator == (const DeviceConfigService_pdcValidateMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(mbnId == rhs.mbnId))
      return false;
    if (!(subId == rhs.subId))
      return false;
    if (!(remotePath == rhs.remotePath))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcValidateMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcValidateMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcValidateMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcValidateMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const std::string* mbnId;
  const int32_t* subId;
  const std::string* remotePath;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcValidateMbn_result__isset {
  _DeviceConfigService_pdcValidateMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcValidateMbn_result__isset;

class DeviceConfigService_pdcValidateMbn_result {
 public:

  DeviceConfigService_pdcValidateMbn_result(const DeviceConfigService_pdcValidateMbn_result&);
  DeviceConfigService_pdcValidateMbn_result& operator=(const DeviceConfigService_pdcValidateMbn_result&);
  DeviceConfigService_pdcValidateMbn_result() {
  }

  virtual ~DeviceConfigService_pdcValidateMbn_result() noexcept;
  PdcMbnResult success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcValidateMbn_result__isset __isset;

  void __set_success(const PdcMbnResult& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcValidateMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcValidateMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcValidateMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcValidateMbn_presult__isset {
  _DeviceConfigService_pdcValidateMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcValidateMbn_presult__isset;

class DeviceConfigService_pdcValidateMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcValidateMbn_presult() noexcept;
  PdcMbnResult* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcValidateMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcSelectMbn_args__isset {
  _DeviceConfigService_pdcSelectMbn_args__isset() : mbnType(false), mbnId(false), subId(false), slotId(false) {}
  bool mbnType :1;
  bool mbnId :1;
  bool subId :1;
  bool slotId :1;
} _DeviceConfigService_pdcSelectMbn_args__isset;

class DeviceConfigService_pdcSelectMbn_args {
 public:

  DeviceConfigService_pdcSelectMbn_args(const DeviceConfigService_pdcSelectMbn_args&);
  DeviceConfigService_pdcSelectMbn_args& operator=(const DeviceConfigService_pdcSelectMbn_args&);
  DeviceConfigService_pdcSelectMbn_args() : mbnType((PdcMbnType::type)0), mbnId(), subId(0), slotId(0) {
  }

  virtual ~DeviceConfigService_pdcSelectMbn_args() noexcept;
  PdcMbnType::type mbnType;
  std::string mbnId;
  int32_t subId;
  int32_t slotId;

  _DeviceConfigService_pdcSelectMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_mbnId(const std::string& val);

  void __set_subId(const int32_t val);

  void __set_slotId(const int32_t val);

  bool operator == (const DeviceConfigService_pdcSelectMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(mbnId == rhs.mbnId))
      return false;
    if (!(subId == rhs.subId))
      return false;
    if (!(slotId == rhs.slotId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcSelectMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcSelectMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcSelectMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcSelectMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const std::string* mbnId;
  const int32_t* subId;
  const int32_t* slotId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcSelectMbn_result__isset {
  _DeviceConfigService_pdcSelectMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcSelectMbn_result__isset;

class DeviceConfigService_pdcSelectMbn_result {
 public:

  DeviceConfigService_pdcSelectMbn_result(const DeviceConfigService_pdcSelectMbn_result&);
  DeviceConfigService_pdcSelectMbn_result& operator=(const DeviceConfigService_pdcSelectMbn_result&);
  DeviceConfigService_pdcSelectMbn_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_pdcSelectMbn_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcSelectMbn_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcSelectMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcSelectMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcSelectMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcSelectMbn_presult__isset {
  _DeviceConfigService_pdcSelectMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcSelectMbn_presult__isset;

class DeviceConfigService_pdcSelectMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcSelectMbn_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcSelectMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcActivateMbn_args__isset {
  _DeviceConfigService_pdcActivateMbn_args__isset() : mbnType(false), subId(false), slotId(false), mode(false), timeout(false) {}
  bool mbnType :1;
  bool subId :1;
  bool slotId :1;
  bool mode :1;
  bool timeout :1;
} _DeviceConfigService_pdcActivateMbn_args__isset;

class DeviceConfigService_pdcActivateMbn_args {
 public:

  DeviceConfigService_pdcActivateMbn_args(const DeviceConfigService_pdcActivateMbn_args&);
  DeviceConfigService_pdcActivateMbn_args& operator=(const DeviceConfigService_pdcActivateMbn_args&);
  DeviceConfigService_pdcActivateMbn_args() : mbnType((PdcMbnType::type)0), subId(0), slotId(0), mode(0), timeout(0) {
  }

  virtual ~DeviceConfigService_pdcActivateMbn_args() noexcept;
  PdcMbnType::type mbnType;
  int32_t subId;
  int32_t slotId;
  int32_t mode;
  int32_t timeout;

  _DeviceConfigService_pdcActivateMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_subId(const int32_t val);

  void __set_slotId(const int32_t val);

  void __set_mode(const int32_t val);

  void __set_timeout(const int32_t val);

  bool operator == (const DeviceConfigService_pdcActivateMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(subId == rhs.subId))
      return false;
    if (!(slotId == rhs.slotId))
      return false;
    if (!(mode == rhs.mode))
      return false;
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcActivateMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcActivateMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcActivateMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcActivateMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const int32_t* subId;
  const int32_t* slotId;
  const int32_t* mode;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcActivateMbn_result__isset {
  _DeviceConfigService_pdcActivateMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcActivateMbn_result__isset;

class DeviceConfigService_pdcActivateMbn_result {
 public:

  DeviceConfigService_pdcActivateMbn_result(const DeviceConfigService_pdcActivateMbn_result&);
  DeviceConfigService_pdcActivateMbn_result& operator=(const DeviceConfigService_pdcActivateMbn_result&);
  DeviceConfigService_pdcActivateMbn_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_pdcActivateMbn_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcActivateMbn_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcActivateMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcActivateMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcActivateMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcActivateMbn_presult__isset {
  _DeviceConfigService_pdcActivateMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcActivateMbn_presult__isset;

class DeviceConfigService_pdcActivateMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcActivateMbn_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcActivateMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcDeactivateMbn_args__isset {
  _DeviceConfigService_pdcDeactivateMbn_args__isset() : mbnType(false), subId(false) {}
  bool mbnType :1;
  bool subId :1;
} _DeviceConfigService_pdcDeactivateMbn_args__isset;

class DeviceConfigService_pdcDeactivateMbn_args {
 public:

  DeviceConfigService_pdcDeactivateMbn_args(const DeviceConfigService_pdcDeactivateMbn_args&);
  DeviceConfigService_pdcDeactivateMbn_args& operator=(const DeviceConfigService_pdcDeactivateMbn_args&);
  DeviceConfigService_pdcDeactivateMbn_args() : mbnType((PdcMbnType::type)0), subId(0) {
  }

  virtual ~DeviceConfigService_pdcDeactivateMbn_args() noexcept;
  PdcMbnType::type mbnType;
  int32_t subId;

  _DeviceConfigService_pdcDeactivateMbn_args__isset __isset;

  void __set_mbnType(const PdcMbnType::type val);

  void __set_subId(const int32_t val);

  bool operator == (const DeviceConfigService_pdcDeactivateMbn_args & rhs) const
  {
    if (!(mbnType == rhs.mbnType))
      return false;
    if (!(subId == rhs.subId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcDeactivateMbn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcDeactivateMbn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcDeactivateMbn_pargs {
 public:


  virtual ~DeviceConfigService_pdcDeactivateMbn_pargs() noexcept;
  const PdcMbnType::type* mbnType;
  const int32_t* subId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcDeactivateMbn_result__isset {
  _DeviceConfigService_pdcDeactivateMbn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcDeactivateMbn_result__isset;

class DeviceConfigService_pdcDeactivateMbn_result {
 public:

  DeviceConfigService_pdcDeactivateMbn_result(const DeviceConfigService_pdcDeactivateMbn_result&);
  DeviceConfigService_pdcDeactivateMbn_result& operator=(const DeviceConfigService_pdcDeactivateMbn_result&);
  DeviceConfigService_pdcDeactivateMbn_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_pdcDeactivateMbn_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcDeactivateMbn_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcDeactivateMbn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcDeactivateMbn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcDeactivateMbn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcDeactivateMbn_presult__isset {
  _DeviceConfigService_pdcDeactivateMbn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcDeactivateMbn_presult__isset;

class DeviceConfigService_pdcDeactivateMbn_presult {
 public:


  virtual ~DeviceConfigService_pdcDeactivateMbn_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcDeactivateMbn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcGetConfiguration_args__isset {
  _DeviceConfigService_pdcGetConfiguration_args__isset() : slotId(false), feature(false) {}
  bool slotId :1;
  bool feature :1;
} _DeviceConfigService_pdcGetConfiguration_args__isset;

class DeviceConfigService_pdcGetConfiguration_args {
 public:

  DeviceConfigService_pdcGetConfiguration_args(const DeviceConfigService_pdcGetConfiguration_args&);
  DeviceConfigService_pdcGetConfiguration_args& operator=(const DeviceConfigService_pdcGetConfiguration_args&);
  DeviceConfigService_pdcGetConfiguration_args() : slotId(0), feature((PdcConfigurationType::type)0) {
  }

  virtual ~DeviceConfigService_pdcGetConfiguration_args() noexcept;
  int32_t slotId;
  PdcConfigurationType::type feature;

  _DeviceConfigService_pdcGetConfiguration_args__isset __isset;

  void __set_slotId(const int32_t val);

  void __set_feature(const PdcConfigurationType::type val);

  bool operator == (const DeviceConfigService_pdcGetConfiguration_args & rhs) const
  {
    if (!(slotId == rhs.slotId))
      return false;
    if (!(feature == rhs.feature))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetConfiguration_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetConfiguration_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcGetConfiguration_pargs {
 public:


  virtual ~DeviceConfigService_pdcGetConfiguration_pargs() noexcept;
  const int32_t* slotId;
  const PdcConfigurationType::type* feature;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetConfiguration_result__isset {
  _DeviceConfigService_pdcGetConfiguration_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetConfiguration_result__isset;

class DeviceConfigService_pdcGetConfiguration_result {
 public:

  DeviceConfigService_pdcGetConfiguration_result(const DeviceConfigService_pdcGetConfiguration_result&);
  DeviceConfigService_pdcGetConfiguration_result& operator=(const DeviceConfigService_pdcGetConfiguration_result&);
  DeviceConfigService_pdcGetConfiguration_result() : success(0) {
  }

  virtual ~DeviceConfigService_pdcGetConfiguration_result() noexcept;
  int32_t success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetConfiguration_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcGetConfiguration_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcGetConfiguration_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcGetConfiguration_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcGetConfiguration_presult__isset {
  _DeviceConfigService_pdcGetConfiguration_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcGetConfiguration_presult__isset;

class DeviceConfigService_pdcGetConfiguration_presult {
 public:


  virtual ~DeviceConfigService_pdcGetConfiguration_presult() noexcept;
  int32_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcGetConfiguration_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_pdcSetConfiguration_args__isset {
  _DeviceConfigService_pdcSetConfiguration_args__isset() : slotId(false), feature(false), value(false) {}
  bool slotId :1;
  bool feature :1;
  bool value :1;
} _DeviceConfigService_pdcSetConfiguration_args__isset;

class DeviceConfigService_pdcSetConfiguration_args {
 public:

  DeviceConfigService_pdcSetConfiguration_args(const DeviceConfigService_pdcSetConfiguration_args&);
  DeviceConfigService_pdcSetConfiguration_args& operator=(const DeviceConfigService_pdcSetConfiguration_args&);
  DeviceConfigService_pdcSetConfiguration_args() : slotId(0), feature((PdcConfigurationType::type)0), value(0) {
  }

  virtual ~DeviceConfigService_pdcSetConfiguration_args() noexcept;
  int32_t slotId;
  PdcConfigurationType::type feature;
  int32_t value;

  _DeviceConfigService_pdcSetConfiguration_args__isset __isset;

  void __set_slotId(const int32_t val);

  void __set_feature(const PdcConfigurationType::type val);

  void __set_value(const int32_t val);

  bool operator == (const DeviceConfigService_pdcSetConfiguration_args & rhs) const
  {
    if (!(slotId == rhs.slotId))
      return false;
    if (!(feature == rhs.feature))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcSetConfiguration_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcSetConfiguration_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_pdcSetConfiguration_pargs {
 public:


  virtual ~DeviceConfigService_pdcSetConfiguration_pargs() noexcept;
  const int32_t* slotId;
  const PdcConfigurationType::type* feature;
  const int32_t* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcSetConfiguration_result__isset {
  _DeviceConfigService_pdcSetConfiguration_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcSetConfiguration_result__isset;

class DeviceConfigService_pdcSetConfiguration_result {
 public:

  DeviceConfigService_pdcSetConfiguration_result(const DeviceConfigService_pdcSetConfiguration_result&);
  DeviceConfigService_pdcSetConfiguration_result& operator=(const DeviceConfigService_pdcSetConfiguration_result&);
  DeviceConfigService_pdcSetConfiguration_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_pdcSetConfiguration_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcSetConfiguration_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_pdcSetConfiguration_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_pdcSetConfiguration_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_pdcSetConfiguration_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_pdcSetConfiguration_presult__isset {
  _DeviceConfigService_pdcSetConfiguration_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_pdcSetConfiguration_presult__isset;

class DeviceConfigService_pdcSetConfiguration_presult {
 public:


  virtual ~DeviceConfigService_pdcSetConfiguration_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_pdcSetConfiguration_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_nvIsItemSupported_args__isset {
  _DeviceConfigService_nvIsItemSupported_args__isset() : nvItemNameOrId(false), subscriptionId(false) {}
  bool nvItemNameOrId :1;
  bool subscriptionId :1;
} _DeviceConfigService_nvIsItemSupported_args__isset;

class DeviceConfigService_nvIsItemSupported_args {
 public:

  DeviceConfigService_nvIsItemSupported_args(const DeviceConfigService_nvIsItemSupported_args&);
  DeviceConfigService_nvIsItemSupported_args& operator=(const DeviceConfigService_nvIsItemSupported_args&);
  DeviceConfigService_nvIsItemSupported_args() : nvItemNameOrId(), subscriptionId(0) {
  }

  virtual ~DeviceConfigService_nvIsItemSupported_args() noexcept;
  std::string nvItemNameOrId;
  int32_t subscriptionId;

  _DeviceConfigService_nvIsItemSupported_args__isset __isset;

  void __set_nvItemNameOrId(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceConfigService_nvIsItemSupported_args & rhs) const
  {
    if (!(nvItemNameOrId == rhs.nvItemNameOrId))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvIsItemSupported_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvIsItemSupported_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_nvIsItemSupported_pargs {
 public:


  virtual ~DeviceConfigService_nvIsItemSupported_pargs() noexcept;
  const std::string* nvItemNameOrId;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvIsItemSupported_result__isset {
  _DeviceConfigService_nvIsItemSupported_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvIsItemSupported_result__isset;

class DeviceConfigService_nvIsItemSupported_result {
 public:

  DeviceConfigService_nvIsItemSupported_result(const DeviceConfigService_nvIsItemSupported_result&);
  DeviceConfigService_nvIsItemSupported_result& operator=(const DeviceConfigService_nvIsItemSupported_result&);
  DeviceConfigService_nvIsItemSupported_result() : success(0) {
  }

  virtual ~DeviceConfigService_nvIsItemSupported_result() noexcept;
  bool success;
   ::Uts::AppException e;

  _DeviceConfigService_nvIsItemSupported_result__isset __isset;

  void __set_success(const bool val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_nvIsItemSupported_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvIsItemSupported_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvIsItemSupported_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvIsItemSupported_presult__isset {
  _DeviceConfigService_nvIsItemSupported_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvIsItemSupported_presult__isset;

class DeviceConfigService_nvIsItemSupported_presult {
 public:


  virtual ~DeviceConfigService_nvIsItemSupported_presult() noexcept;
  bool* success;
   ::Uts::AppException e;

  _DeviceConfigService_nvIsItemSupported_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_nvReadItem_args__isset {
  _DeviceConfigService_nvReadItem_args__isset() : nvItemNameOrId(false), subscriptionId(false), index(false), returnConfig(false) {}
  bool nvItemNameOrId :1;
  bool subscriptionId :1;
  bool index :1;
  bool returnConfig :1;
} _DeviceConfigService_nvReadItem_args__isset;

class DeviceConfigService_nvReadItem_args {
 public:

  DeviceConfigService_nvReadItem_args(const DeviceConfigService_nvReadItem_args&);
  DeviceConfigService_nvReadItem_args& operator=(const DeviceConfigService_nvReadItem_args&);
  DeviceConfigService_nvReadItem_args() : nvItemNameOrId(), subscriptionId(0), index(0) {
  }

  virtual ~DeviceConfigService_nvReadItem_args() noexcept;
  std::string nvItemNameOrId;
  int32_t subscriptionId;
  int8_t index;
  NvReturns returnConfig;

  _DeviceConfigService_nvReadItem_args__isset __isset;

  void __set_nvItemNameOrId(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  void __set_index(const int8_t val);

  void __set_returnConfig(const NvReturns& val);

  bool operator == (const DeviceConfigService_nvReadItem_args & rhs) const
  {
    if (!(nvItemNameOrId == rhs.nvItemNameOrId))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(index == rhs.index))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvReadItem_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvReadItem_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_nvReadItem_pargs {
 public:


  virtual ~DeviceConfigService_nvReadItem_pargs() noexcept;
  const std::string* nvItemNameOrId;
  const int32_t* subscriptionId;
  const int8_t* index;
  const NvReturns* returnConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvReadItem_result__isset {
  _DeviceConfigService_nvReadItem_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvReadItem_result__isset;

class DeviceConfigService_nvReadItem_result {
 public:

  DeviceConfigService_nvReadItem_result(const DeviceConfigService_nvReadItem_result&);
  DeviceConfigService_nvReadItem_result& operator=(const DeviceConfigService_nvReadItem_result&);
  DeviceConfigService_nvReadItem_result() {
  }

  virtual ~DeviceConfigService_nvReadItem_result() noexcept;
  NvData success;
   ::Uts::AppException e;

  _DeviceConfigService_nvReadItem_result__isset __isset;

  void __set_success(const NvData& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_nvReadItem_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvReadItem_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvReadItem_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvReadItem_presult__isset {
  _DeviceConfigService_nvReadItem_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvReadItem_presult__isset;

class DeviceConfigService_nvReadItem_presult {
 public:


  virtual ~DeviceConfigService_nvReadItem_presult() noexcept;
  NvData* success;
   ::Uts::AppException e;

  _DeviceConfigService_nvReadItem_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_nvSetItem_args__isset {
  _DeviceConfigService_nvSetItem_args__isset() : nvItemNameOrId(false), valueList(false), subscriptionId(false) {}
  bool nvItemNameOrId :1;
  bool valueList :1;
  bool subscriptionId :1;
} _DeviceConfigService_nvSetItem_args__isset;

class DeviceConfigService_nvSetItem_args {
 public:

  DeviceConfigService_nvSetItem_args(const DeviceConfigService_nvSetItem_args&);
  DeviceConfigService_nvSetItem_args& operator=(const DeviceConfigService_nvSetItem_args&);
  DeviceConfigService_nvSetItem_args() : nvItemNameOrId(), valueList(), subscriptionId(0) {
  }

  virtual ~DeviceConfigService_nvSetItem_args() noexcept;
  std::string nvItemNameOrId;
  std::string valueList;
  int32_t subscriptionId;

  _DeviceConfigService_nvSetItem_args__isset __isset;

  void __set_nvItemNameOrId(const std::string& val);

  void __set_valueList(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceConfigService_nvSetItem_args & rhs) const
  {
    if (!(nvItemNameOrId == rhs.nvItemNameOrId))
      return false;
    if (!(valueList == rhs.valueList))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvSetItem_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvSetItem_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_nvSetItem_pargs {
 public:


  virtual ~DeviceConfigService_nvSetItem_pargs() noexcept;
  const std::string* nvItemNameOrId;
  const std::string* valueList;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvSetItem_result__isset {
  _DeviceConfigService_nvSetItem_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvSetItem_result__isset;

class DeviceConfigService_nvSetItem_result {
 public:

  DeviceConfigService_nvSetItem_result(const DeviceConfigService_nvSetItem_result&);
  DeviceConfigService_nvSetItem_result& operator=(const DeviceConfigService_nvSetItem_result&);
  DeviceConfigService_nvSetItem_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_nvSetItem_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_nvSetItem_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_nvSetItem_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvSetItem_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvSetItem_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvSetItem_presult__isset {
  _DeviceConfigService_nvSetItem_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvSetItem_presult__isset;

class DeviceConfigService_nvSetItem_presult {
 public:


  virtual ~DeviceConfigService_nvSetItem_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_nvSetItem_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_nvSetOtpItem_args__isset {
  _DeviceConfigService_nvSetOtpItem_args__isset() : nvItemNameOrId(false), valueList(false), subscriptionId(false) {}
  bool nvItemNameOrId :1;
  bool valueList :1;
  bool subscriptionId :1;
} _DeviceConfigService_nvSetOtpItem_args__isset;

class DeviceConfigService_nvSetOtpItem_args {
 public:

  DeviceConfigService_nvSetOtpItem_args(const DeviceConfigService_nvSetOtpItem_args&);
  DeviceConfigService_nvSetOtpItem_args& operator=(const DeviceConfigService_nvSetOtpItem_args&);
  DeviceConfigService_nvSetOtpItem_args() : nvItemNameOrId(), valueList(), subscriptionId(0) {
  }

  virtual ~DeviceConfigService_nvSetOtpItem_args() noexcept;
  std::string nvItemNameOrId;
  std::string valueList;
  int32_t subscriptionId;

  _DeviceConfigService_nvSetOtpItem_args__isset __isset;

  void __set_nvItemNameOrId(const std::string& val);

  void __set_valueList(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceConfigService_nvSetOtpItem_args & rhs) const
  {
    if (!(nvItemNameOrId == rhs.nvItemNameOrId))
      return false;
    if (!(valueList == rhs.valueList))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvSetOtpItem_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvSetOtpItem_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_nvSetOtpItem_pargs {
 public:


  virtual ~DeviceConfigService_nvSetOtpItem_pargs() noexcept;
  const std::string* nvItemNameOrId;
  const std::string* valueList;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvSetOtpItem_result__isset {
  _DeviceConfigService_nvSetOtpItem_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvSetOtpItem_result__isset;

class DeviceConfigService_nvSetOtpItem_result {
 public:

  DeviceConfigService_nvSetOtpItem_result(const DeviceConfigService_nvSetOtpItem_result&);
  DeviceConfigService_nvSetOtpItem_result& operator=(const DeviceConfigService_nvSetOtpItem_result&);
  DeviceConfigService_nvSetOtpItem_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_nvSetOtpItem_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_nvSetOtpItem_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_nvSetOtpItem_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvSetOtpItem_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvSetOtpItem_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvSetOtpItem_presult__isset {
  _DeviceConfigService_nvSetOtpItem_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvSetOtpItem_presult__isset;

class DeviceConfigService_nvSetOtpItem_presult {
 public:


  virtual ~DeviceConfigService_nvSetOtpItem_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_nvSetOtpItem_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_nvGetAllItems_args {
 public:

  DeviceConfigService_nvGetAllItems_args(const DeviceConfigService_nvGetAllItems_args&);
  DeviceConfigService_nvGetAllItems_args& operator=(const DeviceConfigService_nvGetAllItems_args&);
  DeviceConfigService_nvGetAllItems_args() {
  }

  virtual ~DeviceConfigService_nvGetAllItems_args() noexcept;

  bool operator == (const DeviceConfigService_nvGetAllItems_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_nvGetAllItems_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvGetAllItems_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_nvGetAllItems_pargs {
 public:


  virtual ~DeviceConfigService_nvGetAllItems_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvGetAllItems_result__isset {
  _DeviceConfigService_nvGetAllItems_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvGetAllItems_result__isset;

class DeviceConfigService_nvGetAllItems_result {
 public:

  DeviceConfigService_nvGetAllItems_result(const DeviceConfigService_nvGetAllItems_result&);
  DeviceConfigService_nvGetAllItems_result& operator=(const DeviceConfigService_nvGetAllItems_result&);
  DeviceConfigService_nvGetAllItems_result() {
  }

  virtual ~DeviceConfigService_nvGetAllItems_result() noexcept;
  std::vector< ::Uts::NvItem>  success;
   ::Uts::AppException e;

  _DeviceConfigService_nvGetAllItems_result__isset __isset;

  void __set_success(const std::vector< ::Uts::NvItem> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_nvGetAllItems_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvGetAllItems_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvGetAllItems_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvGetAllItems_presult__isset {
  _DeviceConfigService_nvGetAllItems_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvGetAllItems_presult__isset;

class DeviceConfigService_nvGetAllItems_presult {
 public:


  virtual ~DeviceConfigService_nvGetAllItems_presult() noexcept;
  std::vector< ::Uts::NvItem> * success;
   ::Uts::AppException e;

  _DeviceConfigService_nvGetAllItems_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_nvGetItemDefinition_args__isset {
  _DeviceConfigService_nvGetItemDefinition_args__isset() : nvItemNameOrId(false) {}
  bool nvItemNameOrId :1;
} _DeviceConfigService_nvGetItemDefinition_args__isset;

class DeviceConfigService_nvGetItemDefinition_args {
 public:

  DeviceConfigService_nvGetItemDefinition_args(const DeviceConfigService_nvGetItemDefinition_args&);
  DeviceConfigService_nvGetItemDefinition_args& operator=(const DeviceConfigService_nvGetItemDefinition_args&);
  DeviceConfigService_nvGetItemDefinition_args() : nvItemNameOrId() {
  }

  virtual ~DeviceConfigService_nvGetItemDefinition_args() noexcept;
  std::string nvItemNameOrId;

  _DeviceConfigService_nvGetItemDefinition_args__isset __isset;

  void __set_nvItemNameOrId(const std::string& val);

  bool operator == (const DeviceConfigService_nvGetItemDefinition_args & rhs) const
  {
    if (!(nvItemNameOrId == rhs.nvItemNameOrId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvGetItemDefinition_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvGetItemDefinition_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_nvGetItemDefinition_pargs {
 public:


  virtual ~DeviceConfigService_nvGetItemDefinition_pargs() noexcept;
  const std::string* nvItemNameOrId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvGetItemDefinition_result__isset {
  _DeviceConfigService_nvGetItemDefinition_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvGetItemDefinition_result__isset;

class DeviceConfigService_nvGetItemDefinition_result {
 public:

  DeviceConfigService_nvGetItemDefinition_result(const DeviceConfigService_nvGetItemDefinition_result&);
  DeviceConfigService_nvGetItemDefinition_result& operator=(const DeviceConfigService_nvGetItemDefinition_result&);
  DeviceConfigService_nvGetItemDefinition_result() : success() {
  }

  virtual ~DeviceConfigService_nvGetItemDefinition_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_nvGetItemDefinition_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_nvGetItemDefinition_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_nvGetItemDefinition_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_nvGetItemDefinition_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_nvGetItemDefinition_presult__isset {
  _DeviceConfigService_nvGetItemDefinition_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_nvGetItemDefinition_presult__isset;

class DeviceConfigService_nvGetItemDefinition_presult {
 public:


  virtual ~DeviceConfigService_nvGetItemDefinition_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_nvGetItemDefinition_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_efsHasAlternateFileSystem_args {
 public:

  DeviceConfigService_efsHasAlternateFileSystem_args(const DeviceConfigService_efsHasAlternateFileSystem_args&);
  DeviceConfigService_efsHasAlternateFileSystem_args& operator=(const DeviceConfigService_efsHasAlternateFileSystem_args&);
  DeviceConfigService_efsHasAlternateFileSystem_args() {
  }

  virtual ~DeviceConfigService_efsHasAlternateFileSystem_args() noexcept;

  bool operator == (const DeviceConfigService_efsHasAlternateFileSystem_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_efsHasAlternateFileSystem_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsHasAlternateFileSystem_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsHasAlternateFileSystem_pargs {
 public:


  virtual ~DeviceConfigService_efsHasAlternateFileSystem_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsHasAlternateFileSystem_result__isset {
  _DeviceConfigService_efsHasAlternateFileSystem_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsHasAlternateFileSystem_result__isset;

class DeviceConfigService_efsHasAlternateFileSystem_result {
 public:

  DeviceConfigService_efsHasAlternateFileSystem_result(const DeviceConfigService_efsHasAlternateFileSystem_result&);
  DeviceConfigService_efsHasAlternateFileSystem_result& operator=(const DeviceConfigService_efsHasAlternateFileSystem_result&);
  DeviceConfigService_efsHasAlternateFileSystem_result() : success(0) {
  }

  virtual ~DeviceConfigService_efsHasAlternateFileSystem_result() noexcept;
  bool success;
   ::Uts::AppException e;

  _DeviceConfigService_efsHasAlternateFileSystem_result__isset __isset;

  void __set_success(const bool val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsHasAlternateFileSystem_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsHasAlternateFileSystem_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsHasAlternateFileSystem_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsHasAlternateFileSystem_presult__isset {
  _DeviceConfigService_efsHasAlternateFileSystem_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsHasAlternateFileSystem_presult__isset;

class DeviceConfigService_efsHasAlternateFileSystem_presult {
 public:


  virtual ~DeviceConfigService_efsHasAlternateFileSystem_presult() noexcept;
  bool* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsHasAlternateFileSystem_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsCreateDirectory_args__isset {
  _DeviceConfigService_efsCreateDirectory_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsCreateDirectory_args__isset;

class DeviceConfigService_efsCreateDirectory_args {
 public:

  DeviceConfigService_efsCreateDirectory_args(const DeviceConfigService_efsCreateDirectory_args&);
  DeviceConfigService_efsCreateDirectory_args& operator=(const DeviceConfigService_efsCreateDirectory_args&);
  DeviceConfigService_efsCreateDirectory_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsCreateDirectory_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsCreateDirectory_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsCreateDirectory_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsCreateDirectory_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsCreateDirectory_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsCreateDirectory_pargs {
 public:


  virtual ~DeviceConfigService_efsCreateDirectory_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsCreateDirectory_result__isset {
  _DeviceConfigService_efsCreateDirectory_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsCreateDirectory_result__isset;

class DeviceConfigService_efsCreateDirectory_result {
 public:

  DeviceConfigService_efsCreateDirectory_result(const DeviceConfigService_efsCreateDirectory_result&);
  DeviceConfigService_efsCreateDirectory_result& operator=(const DeviceConfigService_efsCreateDirectory_result&);
  DeviceConfigService_efsCreateDirectory_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_efsCreateDirectory_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_efsCreateDirectory_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsCreateDirectory_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsCreateDirectory_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsCreateDirectory_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsCreateDirectory_presult__isset {
  _DeviceConfigService_efsCreateDirectory_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsCreateDirectory_presult__isset;

class DeviceConfigService_efsCreateDirectory_presult {
 public:


  virtual ~DeviceConfigService_efsCreateDirectory_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsCreateDirectory_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsRemoveDirectory_args__isset {
  _DeviceConfigService_efsRemoveDirectory_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsRemoveDirectory_args__isset;

class DeviceConfigService_efsRemoveDirectory_args {
 public:

  DeviceConfigService_efsRemoveDirectory_args(const DeviceConfigService_efsRemoveDirectory_args&);
  DeviceConfigService_efsRemoveDirectory_args& operator=(const DeviceConfigService_efsRemoveDirectory_args&);
  DeviceConfigService_efsRemoveDirectory_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsRemoveDirectory_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsRemoveDirectory_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsRemoveDirectory_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsRemoveDirectory_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsRemoveDirectory_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsRemoveDirectory_pargs {
 public:


  virtual ~DeviceConfigService_efsRemoveDirectory_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsRemoveDirectory_result__isset {
  _DeviceConfigService_efsRemoveDirectory_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsRemoveDirectory_result__isset;

class DeviceConfigService_efsRemoveDirectory_result {
 public:

  DeviceConfigService_efsRemoveDirectory_result(const DeviceConfigService_efsRemoveDirectory_result&);
  DeviceConfigService_efsRemoveDirectory_result& operator=(const DeviceConfigService_efsRemoveDirectory_result&);
  DeviceConfigService_efsRemoveDirectory_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_efsRemoveDirectory_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_efsRemoveDirectory_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsRemoveDirectory_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsRemoveDirectory_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsRemoveDirectory_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsRemoveDirectory_presult__isset {
  _DeviceConfigService_efsRemoveDirectory_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsRemoveDirectory_presult__isset;

class DeviceConfigService_efsRemoveDirectory_presult {
 public:


  virtual ~DeviceConfigService_efsRemoveDirectory_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsRemoveDirectory_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsRemoveTree_args__isset {
  _DeviceConfigService_efsRemoveTree_args__isset() : pathName(false), efsSytem(false) {}
  bool pathName :1;
  bool efsSytem :1;
} _DeviceConfigService_efsRemoveTree_args__isset;

class DeviceConfigService_efsRemoveTree_args {
 public:

  DeviceConfigService_efsRemoveTree_args(const DeviceConfigService_efsRemoveTree_args&);
  DeviceConfigService_efsRemoveTree_args& operator=(const DeviceConfigService_efsRemoveTree_args&);
  DeviceConfigService_efsRemoveTree_args() : pathName(), efsSytem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsRemoveTree_args() noexcept;
  std::string pathName;
  FileSystem::type efsSytem;

  _DeviceConfigService_efsRemoveTree_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSytem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsRemoveTree_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSytem == rhs.efsSytem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsRemoveTree_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsRemoveTree_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsRemoveTree_pargs {
 public:


  virtual ~DeviceConfigService_efsRemoveTree_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSytem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsRemoveTree_result__isset {
  _DeviceConfigService_efsRemoveTree_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsRemoveTree_result__isset;

class DeviceConfigService_efsRemoveTree_result {
 public:

  DeviceConfigService_efsRemoveTree_result(const DeviceConfigService_efsRemoveTree_result&);
  DeviceConfigService_efsRemoveTree_result& operator=(const DeviceConfigService_efsRemoveTree_result&);
  DeviceConfigService_efsRemoveTree_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_efsRemoveTree_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_efsRemoveTree_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsRemoveTree_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsRemoveTree_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsRemoveTree_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsRemoveTree_presult__isset {
  _DeviceConfigService_efsRemoveTree_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsRemoveTree_presult__isset;

class DeviceConfigService_efsRemoveTree_presult {
 public:


  virtual ~DeviceConfigService_efsRemoveTree_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsRemoveTree_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsGetDirectoryContents_args__isset {
  _DeviceConfigService_efsGetDirectoryContents_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsGetDirectoryContents_args__isset;

class DeviceConfigService_efsGetDirectoryContents_args {
 public:

  DeviceConfigService_efsGetDirectoryContents_args(const DeviceConfigService_efsGetDirectoryContents_args&);
  DeviceConfigService_efsGetDirectoryContents_args& operator=(const DeviceConfigService_efsGetDirectoryContents_args&);
  DeviceConfigService_efsGetDirectoryContents_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsGetDirectoryContents_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsGetDirectoryContents_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsGetDirectoryContents_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetDirectoryContents_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetDirectoryContents_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsGetDirectoryContents_pargs {
 public:


  virtual ~DeviceConfigService_efsGetDirectoryContents_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetDirectoryContents_result__isset {
  _DeviceConfigService_efsGetDirectoryContents_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetDirectoryContents_result__isset;

class DeviceConfigService_efsGetDirectoryContents_result {
 public:

  DeviceConfigService_efsGetDirectoryContents_result(const DeviceConfigService_efsGetDirectoryContents_result&);
  DeviceConfigService_efsGetDirectoryContents_result& operator=(const DeviceConfigService_efsGetDirectoryContents_result&);
  DeviceConfigService_efsGetDirectoryContents_result() {
  }

  virtual ~DeviceConfigService_efsGetDirectoryContents_result() noexcept;
  std::vector<EfsItem>  success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetDirectoryContents_result__isset __isset;

  void __set_success(const std::vector<EfsItem> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsGetDirectoryContents_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetDirectoryContents_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetDirectoryContents_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetDirectoryContents_presult__isset {
  _DeviceConfigService_efsGetDirectoryContents_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetDirectoryContents_presult__isset;

class DeviceConfigService_efsGetDirectoryContents_presult {
 public:


  virtual ~DeviceConfigService_efsGetDirectoryContents_presult() noexcept;
  std::vector<EfsItem> * success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetDirectoryContents_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsPutFile_args__isset {
  _DeviceConfigService_efsPutFile_args__isset() : pathName(false), buffer(false), efsSystem(false) {}
  bool pathName :1;
  bool buffer :1;
  bool efsSystem :1;
} _DeviceConfigService_efsPutFile_args__isset;

class DeviceConfigService_efsPutFile_args {
 public:

  DeviceConfigService_efsPutFile_args(const DeviceConfigService_efsPutFile_args&);
  DeviceConfigService_efsPutFile_args& operator=(const DeviceConfigService_efsPutFile_args&);
  DeviceConfigService_efsPutFile_args() : pathName(), buffer(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsPutFile_args() noexcept;
  std::string pathName;
  std::string buffer;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsPutFile_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_buffer(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsPutFile_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(buffer == rhs.buffer))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsPutFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsPutFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsPutFile_pargs {
 public:


  virtual ~DeviceConfigService_efsPutFile_pargs() noexcept;
  const std::string* pathName;
  const std::string* buffer;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsPutFile_result__isset {
  _DeviceConfigService_efsPutFile_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsPutFile_result__isset;

class DeviceConfigService_efsPutFile_result {
 public:

  DeviceConfigService_efsPutFile_result(const DeviceConfigService_efsPutFile_result&);
  DeviceConfigService_efsPutFile_result& operator=(const DeviceConfigService_efsPutFile_result&);
  DeviceConfigService_efsPutFile_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_efsPutFile_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_efsPutFile_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsPutFile_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsPutFile_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsPutFile_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsPutFile_presult__isset {
  _DeviceConfigService_efsPutFile_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsPutFile_presult__isset;

class DeviceConfigService_efsPutFile_presult {
 public:


  virtual ~DeviceConfigService_efsPutFile_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsPutFile_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsGetFile_args__isset {
  _DeviceConfigService_efsGetFile_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsGetFile_args__isset;

class DeviceConfigService_efsGetFile_args {
 public:

  DeviceConfigService_efsGetFile_args(const DeviceConfigService_efsGetFile_args&);
  DeviceConfigService_efsGetFile_args& operator=(const DeviceConfigService_efsGetFile_args&);
  DeviceConfigService_efsGetFile_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsGetFile_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsGetFile_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsGetFile_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsGetFile_pargs {
 public:


  virtual ~DeviceConfigService_efsGetFile_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetFile_result__isset {
  _DeviceConfigService_efsGetFile_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetFile_result__isset;

class DeviceConfigService_efsGetFile_result {
 public:

  DeviceConfigService_efsGetFile_result(const DeviceConfigService_efsGetFile_result&);
  DeviceConfigService_efsGetFile_result& operator=(const DeviceConfigService_efsGetFile_result&);
  DeviceConfigService_efsGetFile_result() : success() {
  }

  virtual ~DeviceConfigService_efsGetFile_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetFile_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsGetFile_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetFile_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetFile_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetFile_presult__isset {
  _DeviceConfigService_efsGetFile_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetFile_presult__isset;

class DeviceConfigService_efsGetFile_presult {
 public:


  virtual ~DeviceConfigService_efsGetFile_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetFile_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsDeleteFile_args__isset {
  _DeviceConfigService_efsDeleteFile_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsDeleteFile_args__isset;

class DeviceConfigService_efsDeleteFile_args {
 public:

  DeviceConfigService_efsDeleteFile_args(const DeviceConfigService_efsDeleteFile_args&);
  DeviceConfigService_efsDeleteFile_args& operator=(const DeviceConfigService_efsDeleteFile_args&);
  DeviceConfigService_efsDeleteFile_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsDeleteFile_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsDeleteFile_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsDeleteFile_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsDeleteFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsDeleteFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsDeleteFile_pargs {
 public:


  virtual ~DeviceConfigService_efsDeleteFile_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsDeleteFile_result__isset {
  _DeviceConfigService_efsDeleteFile_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsDeleteFile_result__isset;

class DeviceConfigService_efsDeleteFile_result {
 public:

  DeviceConfigService_efsDeleteFile_result(const DeviceConfigService_efsDeleteFile_result&);
  DeviceConfigService_efsDeleteFile_result& operator=(const DeviceConfigService_efsDeleteFile_result&);
  DeviceConfigService_efsDeleteFile_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_efsDeleteFile_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_efsDeleteFile_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsDeleteFile_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsDeleteFile_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsDeleteFile_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsDeleteFile_presult__isset {
  _DeviceConfigService_efsDeleteFile_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsDeleteFile_presult__isset;

class DeviceConfigService_efsDeleteFile_presult {
 public:


  virtual ~DeviceConfigService_efsDeleteFile_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsDeleteFile_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsRename_args__isset {
  _DeviceConfigService_efsRename_args__isset() : existingName(false), newName(false), efsSystem(false) {}
  bool existingName :1;
  bool newName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsRename_args__isset;

class DeviceConfigService_efsRename_args {
 public:

  DeviceConfigService_efsRename_args(const DeviceConfigService_efsRename_args&);
  DeviceConfigService_efsRename_args& operator=(const DeviceConfigService_efsRename_args&);
  DeviceConfigService_efsRename_args() : existingName(), newName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsRename_args() noexcept;
  std::string existingName;
  std::string newName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsRename_args__isset __isset;

  void __set_existingName(const std::string& val);

  void __set_newName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsRename_args & rhs) const
  {
    if (!(existingName == rhs.existingName))
      return false;
    if (!(newName == rhs.newName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsRename_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsRename_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsRename_pargs {
 public:


  virtual ~DeviceConfigService_efsRename_pargs() noexcept;
  const std::string* existingName;
  const std::string* newName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsRename_result__isset {
  _DeviceConfigService_efsRename_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsRename_result__isset;

class DeviceConfigService_efsRename_result {
 public:

  DeviceConfigService_efsRename_result(const DeviceConfigService_efsRename_result&);
  DeviceConfigService_efsRename_result& operator=(const DeviceConfigService_efsRename_result&);
  DeviceConfigService_efsRename_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_efsRename_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_efsRename_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsRename_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsRename_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsRename_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsRename_presult__isset {
  _DeviceConfigService_efsRename_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsRename_presult__isset;

class DeviceConfigService_efsRename_presult {
 public:


  virtual ~DeviceConfigService_efsRename_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsRename_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsPathExists_args__isset {
  _DeviceConfigService_efsPathExists_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsPathExists_args__isset;

class DeviceConfigService_efsPathExists_args {
 public:

  DeviceConfigService_efsPathExists_args(const DeviceConfigService_efsPathExists_args&);
  DeviceConfigService_efsPathExists_args& operator=(const DeviceConfigService_efsPathExists_args&);
  DeviceConfigService_efsPathExists_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsPathExists_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsPathExists_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsPathExists_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsPathExists_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsPathExists_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsPathExists_pargs {
 public:


  virtual ~DeviceConfigService_efsPathExists_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsPathExists_result__isset {
  _DeviceConfigService_efsPathExists_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsPathExists_result__isset;

class DeviceConfigService_efsPathExists_result {
 public:

  DeviceConfigService_efsPathExists_result(const DeviceConfigService_efsPathExists_result&);
  DeviceConfigService_efsPathExists_result& operator=(const DeviceConfigService_efsPathExists_result&);
  DeviceConfigService_efsPathExists_result() : success(0) {
  }

  virtual ~DeviceConfigService_efsPathExists_result() noexcept;
  bool success;
   ::Uts::AppException e;

  _DeviceConfigService_efsPathExists_result__isset __isset;

  void __set_success(const bool val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsPathExists_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsPathExists_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsPathExists_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsPathExists_presult__isset {
  _DeviceConfigService_efsPathExists_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsPathExists_presult__isset;

class DeviceConfigService_efsPathExists_presult {
 public:


  virtual ~DeviceConfigService_efsPathExists_presult() noexcept;
  bool* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsPathExists_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsIsDirectory_args__isset {
  _DeviceConfigService_efsIsDirectory_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsIsDirectory_args__isset;

class DeviceConfigService_efsIsDirectory_args {
 public:

  DeviceConfigService_efsIsDirectory_args(const DeviceConfigService_efsIsDirectory_args&);
  DeviceConfigService_efsIsDirectory_args& operator=(const DeviceConfigService_efsIsDirectory_args&);
  DeviceConfigService_efsIsDirectory_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsIsDirectory_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsIsDirectory_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsIsDirectory_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsIsDirectory_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsIsDirectory_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsIsDirectory_pargs {
 public:


  virtual ~DeviceConfigService_efsIsDirectory_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsIsDirectory_result__isset {
  _DeviceConfigService_efsIsDirectory_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsIsDirectory_result__isset;

class DeviceConfigService_efsIsDirectory_result {
 public:

  DeviceConfigService_efsIsDirectory_result(const DeviceConfigService_efsIsDirectory_result&);
  DeviceConfigService_efsIsDirectory_result& operator=(const DeviceConfigService_efsIsDirectory_result&);
  DeviceConfigService_efsIsDirectory_result() : success(0) {
  }

  virtual ~DeviceConfigService_efsIsDirectory_result() noexcept;
  bool success;
   ::Uts::AppException e;

  _DeviceConfigService_efsIsDirectory_result__isset __isset;

  void __set_success(const bool val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsIsDirectory_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsIsDirectory_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsIsDirectory_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsIsDirectory_presult__isset {
  _DeviceConfigService_efsIsDirectory_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsIsDirectory_presult__isset;

class DeviceConfigService_efsIsDirectory_presult {
 public:


  virtual ~DeviceConfigService_efsIsDirectory_presult() noexcept;
  bool* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsIsDirectory_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsIsFile_args__isset {
  _DeviceConfigService_efsIsFile_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsIsFile_args__isset;

class DeviceConfigService_efsIsFile_args {
 public:

  DeviceConfigService_efsIsFile_args(const DeviceConfigService_efsIsFile_args&);
  DeviceConfigService_efsIsFile_args& operator=(const DeviceConfigService_efsIsFile_args&);
  DeviceConfigService_efsIsFile_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsIsFile_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsIsFile_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsIsFile_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsIsFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsIsFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsIsFile_pargs {
 public:


  virtual ~DeviceConfigService_efsIsFile_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsIsFile_result__isset {
  _DeviceConfigService_efsIsFile_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsIsFile_result__isset;

class DeviceConfigService_efsIsFile_result {
 public:

  DeviceConfigService_efsIsFile_result(const DeviceConfigService_efsIsFile_result&);
  DeviceConfigService_efsIsFile_result& operator=(const DeviceConfigService_efsIsFile_result&);
  DeviceConfigService_efsIsFile_result() : success(0) {
  }

  virtual ~DeviceConfigService_efsIsFile_result() noexcept;
  bool success;
   ::Uts::AppException e;

  _DeviceConfigService_efsIsFile_result__isset __isset;

  void __set_success(const bool val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsIsFile_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsIsFile_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsIsFile_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsIsFile_presult__isset {
  _DeviceConfigService_efsIsFile_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsIsFile_presult__isset;

class DeviceConfigService_efsIsFile_presult {
 public:


  virtual ~DeviceConfigService_efsIsFile_presult() noexcept;
  bool* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsIsFile_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsGetFileSize_args__isset {
  _DeviceConfigService_efsGetFileSize_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsGetFileSize_args__isset;

class DeviceConfigService_efsGetFileSize_args {
 public:

  DeviceConfigService_efsGetFileSize_args(const DeviceConfigService_efsGetFileSize_args&);
  DeviceConfigService_efsGetFileSize_args& operator=(const DeviceConfigService_efsGetFileSize_args&);
  DeviceConfigService_efsGetFileSize_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsGetFileSize_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsGetFileSize_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsGetFileSize_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetFileSize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetFileSize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsGetFileSize_pargs {
 public:


  virtual ~DeviceConfigService_efsGetFileSize_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetFileSize_result__isset {
  _DeviceConfigService_efsGetFileSize_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetFileSize_result__isset;

class DeviceConfigService_efsGetFileSize_result {
 public:

  DeviceConfigService_efsGetFileSize_result(const DeviceConfigService_efsGetFileSize_result&);
  DeviceConfigService_efsGetFileSize_result& operator=(const DeviceConfigService_efsGetFileSize_result&);
  DeviceConfigService_efsGetFileSize_result() : success(0) {
  }

  virtual ~DeviceConfigService_efsGetFileSize_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetFileSize_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsGetFileSize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetFileSize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetFileSize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetFileSize_presult__isset {
  _DeviceConfigService_efsGetFileSize_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetFileSize_presult__isset;

class DeviceConfigService_efsGetFileSize_presult {
 public:


  virtual ~DeviceConfigService_efsGetFileSize_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetFileSize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsGetAvailableSpace_args__isset {
  _DeviceConfigService_efsGetAvailableSpace_args__isset() : efsSystem(false) {}
  bool efsSystem :1;
} _DeviceConfigService_efsGetAvailableSpace_args__isset;

class DeviceConfigService_efsGetAvailableSpace_args {
 public:

  DeviceConfigService_efsGetAvailableSpace_args(const DeviceConfigService_efsGetAvailableSpace_args&);
  DeviceConfigService_efsGetAvailableSpace_args& operator=(const DeviceConfigService_efsGetAvailableSpace_args&);
  DeviceConfigService_efsGetAvailableSpace_args() : efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsGetAvailableSpace_args() noexcept;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsGetAvailableSpace_args__isset __isset;

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsGetAvailableSpace_args & rhs) const
  {
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetAvailableSpace_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetAvailableSpace_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsGetAvailableSpace_pargs {
 public:


  virtual ~DeviceConfigService_efsGetAvailableSpace_pargs() noexcept;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetAvailableSpace_result__isset {
  _DeviceConfigService_efsGetAvailableSpace_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetAvailableSpace_result__isset;

class DeviceConfigService_efsGetAvailableSpace_result {
 public:

  DeviceConfigService_efsGetAvailableSpace_result(const DeviceConfigService_efsGetAvailableSpace_result&);
  DeviceConfigService_efsGetAvailableSpace_result& operator=(const DeviceConfigService_efsGetAvailableSpace_result&);
  DeviceConfigService_efsGetAvailableSpace_result() : success(0) {
  }

  virtual ~DeviceConfigService_efsGetAvailableSpace_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetAvailableSpace_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsGetAvailableSpace_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetAvailableSpace_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetAvailableSpace_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetAvailableSpace_presult__isset {
  _DeviceConfigService_efsGetAvailableSpace_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetAvailableSpace_presult__isset;

class DeviceConfigService_efsGetAvailableSpace_presult {
 public:


  virtual ~DeviceConfigService_efsGetAvailableSpace_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetAvailableSpace_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsGetFileCheckSum_args__isset {
  _DeviceConfigService_efsGetFileCheckSum_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsGetFileCheckSum_args__isset;

class DeviceConfigService_efsGetFileCheckSum_args {
 public:

  DeviceConfigService_efsGetFileCheckSum_args(const DeviceConfigService_efsGetFileCheckSum_args&);
  DeviceConfigService_efsGetFileCheckSum_args& operator=(const DeviceConfigService_efsGetFileCheckSum_args&);
  DeviceConfigService_efsGetFileCheckSum_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsGetFileCheckSum_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsGetFileCheckSum_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsGetFileCheckSum_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetFileCheckSum_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetFileCheckSum_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsGetFileCheckSum_pargs {
 public:


  virtual ~DeviceConfigService_efsGetFileCheckSum_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetFileCheckSum_result__isset {
  _DeviceConfigService_efsGetFileCheckSum_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetFileCheckSum_result__isset;

class DeviceConfigService_efsGetFileCheckSum_result {
 public:

  DeviceConfigService_efsGetFileCheckSum_result(const DeviceConfigService_efsGetFileCheckSum_result&);
  DeviceConfigService_efsGetFileCheckSum_result& operator=(const DeviceConfigService_efsGetFileCheckSum_result&);
  DeviceConfigService_efsGetFileCheckSum_result() : success() {
  }

  virtual ~DeviceConfigService_efsGetFileCheckSum_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetFileCheckSum_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsGetFileCheckSum_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetFileCheckSum_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetFileCheckSum_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetFileCheckSum_presult__isset {
  _DeviceConfigService_efsGetFileCheckSum_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetFileCheckSum_presult__isset;

class DeviceConfigService_efsGetFileCheckSum_presult {
 public:


  virtual ~DeviceConfigService_efsGetFileCheckSum_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetFileCheckSum_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_efsGetFileAttributes_args__isset {
  _DeviceConfigService_efsGetFileAttributes_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_efsGetFileAttributes_args__isset;

class DeviceConfigService_efsGetFileAttributes_args {
 public:

  DeviceConfigService_efsGetFileAttributes_args(const DeviceConfigService_efsGetFileAttributes_args&);
  DeviceConfigService_efsGetFileAttributes_args& operator=(const DeviceConfigService_efsGetFileAttributes_args&);
  DeviceConfigService_efsGetFileAttributes_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_efsGetFileAttributes_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_efsGetFileAttributes_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_efsGetFileAttributes_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetFileAttributes_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetFileAttributes_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsGetFileAttributes_pargs {
 public:


  virtual ~DeviceConfigService_efsGetFileAttributes_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetFileAttributes_result__isset {
  _DeviceConfigService_efsGetFileAttributes_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetFileAttributes_result__isset;

class DeviceConfigService_efsGetFileAttributes_result {
 public:

  DeviceConfigService_efsGetFileAttributes_result(const DeviceConfigService_efsGetFileAttributes_result&);
  DeviceConfigService_efsGetFileAttributes_result& operator=(const DeviceConfigService_efsGetFileAttributes_result&);
  DeviceConfigService_efsGetFileAttributes_result() {
  }

  virtual ~DeviceConfigService_efsGetFileAttributes_result() noexcept;
  EfsFileAttributes success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetFileAttributes_result__isset __isset;

  void __set_success(const EfsFileAttributes& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsGetFileAttributes_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsGetFileAttributes_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsGetFileAttributes_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsGetFileAttributes_presult__isset {
  _DeviceConfigService_efsGetFileAttributes_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsGetFileAttributes_presult__isset;

class DeviceConfigService_efsGetFileAttributes_presult {
 public:


  virtual ~DeviceConfigService_efsGetFileAttributes_presult() noexcept;
  EfsFileAttributes* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsGetFileAttributes_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_efsIsReady_args {
 public:

  DeviceConfigService_efsIsReady_args(const DeviceConfigService_efsIsReady_args&);
  DeviceConfigService_efsIsReady_args& operator=(const DeviceConfigService_efsIsReady_args&);
  DeviceConfigService_efsIsReady_args() {
  }

  virtual ~DeviceConfigService_efsIsReady_args() noexcept;

  bool operator == (const DeviceConfigService_efsIsReady_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_efsIsReady_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsIsReady_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsIsReady_pargs {
 public:


  virtual ~DeviceConfigService_efsIsReady_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsIsReady_result__isset {
  _DeviceConfigService_efsIsReady_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsIsReady_result__isset;

class DeviceConfigService_efsIsReady_result {
 public:

  DeviceConfigService_efsIsReady_result(const DeviceConfigService_efsIsReady_result&);
  DeviceConfigService_efsIsReady_result& operator=(const DeviceConfigService_efsIsReady_result&);
  DeviceConfigService_efsIsReady_result() : success(0) {
  }

  virtual ~DeviceConfigService_efsIsReady_result() noexcept;
  bool success;
   ::Uts::AppException e;

  _DeviceConfigService_efsIsReady_result__isset __isset;

  void __set_success(const bool val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsIsReady_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsIsReady_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsIsReady_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsIsReady_presult__isset {
  _DeviceConfigService_efsIsReady_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsIsReady_presult__isset;

class DeviceConfigService_efsIsReady_presult {
 public:


  virtual ~DeviceConfigService_efsIsReady_presult() noexcept;
  bool* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsIsReady_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_createGoldenCopy_args__isset {
  _DeviceConfigService_createGoldenCopy_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_createGoldenCopy_args__isset;

class DeviceConfigService_createGoldenCopy_args {
 public:

  DeviceConfigService_createGoldenCopy_args(const DeviceConfigService_createGoldenCopy_args&);
  DeviceConfigService_createGoldenCopy_args& operator=(const DeviceConfigService_createGoldenCopy_args&);
  DeviceConfigService_createGoldenCopy_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_createGoldenCopy_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_createGoldenCopy_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_createGoldenCopy_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_createGoldenCopy_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_createGoldenCopy_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_createGoldenCopy_pargs {
 public:


  virtual ~DeviceConfigService_createGoldenCopy_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_createGoldenCopy_result__isset {
  _DeviceConfigService_createGoldenCopy_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_createGoldenCopy_result__isset;

class DeviceConfigService_createGoldenCopy_result {
 public:

  DeviceConfigService_createGoldenCopy_result(const DeviceConfigService_createGoldenCopy_result&);
  DeviceConfigService_createGoldenCopy_result& operator=(const DeviceConfigService_createGoldenCopy_result&);
  DeviceConfigService_createGoldenCopy_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_createGoldenCopy_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_createGoldenCopy_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_createGoldenCopy_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_createGoldenCopy_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_createGoldenCopy_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_createGoldenCopy_presult__isset {
  _DeviceConfigService_createGoldenCopy_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_createGoldenCopy_presult__isset;

class DeviceConfigService_createGoldenCopy_presult {
 public:


  virtual ~DeviceConfigService_createGoldenCopy_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_createGoldenCopy_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_createCefsCopy_args__isset {
  _DeviceConfigService_createCefsCopy_args__isset() : cefsSavePath(false), efsSystem(false) {}
  bool cefsSavePath :1;
  bool efsSystem :1;
} _DeviceConfigService_createCefsCopy_args__isset;

class DeviceConfigService_createCefsCopy_args {
 public:

  DeviceConfigService_createCefsCopy_args(const DeviceConfigService_createCefsCopy_args&);
  DeviceConfigService_createCefsCopy_args& operator=(const DeviceConfigService_createCefsCopy_args&);
  DeviceConfigService_createCefsCopy_args() : cefsSavePath(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_createCefsCopy_args() noexcept;
  std::string cefsSavePath;
  FileSystem::type efsSystem;

  _DeviceConfigService_createCefsCopy_args__isset __isset;

  void __set_cefsSavePath(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_createCefsCopy_args & rhs) const
  {
    if (!(cefsSavePath == rhs.cefsSavePath))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_createCefsCopy_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_createCefsCopy_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_createCefsCopy_pargs {
 public:


  virtual ~DeviceConfigService_createCefsCopy_pargs() noexcept;
  const std::string* cefsSavePath;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_createCefsCopy_result__isset {
  _DeviceConfigService_createCefsCopy_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_createCefsCopy_result__isset;

class DeviceConfigService_createCefsCopy_result {
 public:

  DeviceConfigService_createCefsCopy_result(const DeviceConfigService_createCefsCopy_result&);
  DeviceConfigService_createCefsCopy_result& operator=(const DeviceConfigService_createCefsCopy_result&);
  DeviceConfigService_createCefsCopy_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_createCefsCopy_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_createCefsCopy_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_createCefsCopy_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_createCefsCopy_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_createCefsCopy_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_createCefsCopy_presult__isset {
  _DeviceConfigService_createCefsCopy_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_createCefsCopy_presult__isset;

class DeviceConfigService_createCefsCopy_presult {
 public:


  virtual ~DeviceConfigService_createCefsCopy_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_createCefsCopy_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_requestPrl_args__isset {
  _DeviceConfigService_requestPrl_args__isset() : subscriptionId(false), index(false) {}
  bool subscriptionId :1;
  bool index :1;
} _DeviceConfigService_requestPrl_args__isset;

class DeviceConfigService_requestPrl_args {
 public:

  DeviceConfigService_requestPrl_args(const DeviceConfigService_requestPrl_args&);
  DeviceConfigService_requestPrl_args& operator=(const DeviceConfigService_requestPrl_args&);
  DeviceConfigService_requestPrl_args() : subscriptionId(0), index(0) {
  }

  virtual ~DeviceConfigService_requestPrl_args() noexcept;
  int32_t subscriptionId;
  int8_t index;

  _DeviceConfigService_requestPrl_args__isset __isset;

  void __set_subscriptionId(const int32_t val);

  void __set_index(const int8_t val);

  bool operator == (const DeviceConfigService_requestPrl_args & rhs) const
  {
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(index == rhs.index))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_requestPrl_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_requestPrl_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_requestPrl_pargs {
 public:


  virtual ~DeviceConfigService_requestPrl_pargs() noexcept;
  const int32_t* subscriptionId;
  const int8_t* index;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_requestPrl_result__isset {
  _DeviceConfigService_requestPrl_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_requestPrl_result__isset;

class DeviceConfigService_requestPrl_result {
 public:

  DeviceConfigService_requestPrl_result(const DeviceConfigService_requestPrl_result&);
  DeviceConfigService_requestPrl_result& operator=(const DeviceConfigService_requestPrl_result&);
  DeviceConfigService_requestPrl_result() : success() {
  }

  virtual ~DeviceConfigService_requestPrl_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_requestPrl_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_requestPrl_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_requestPrl_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_requestPrl_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_requestPrl_presult__isset {
  _DeviceConfigService_requestPrl_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_requestPrl_presult__isset;

class DeviceConfigService_requestPrl_presult {
 public:


  virtual ~DeviceConfigService_requestPrl_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_requestPrl_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_backupPrl_args {
 public:

  DeviceConfigService_backupPrl_args(const DeviceConfigService_backupPrl_args&);
  DeviceConfigService_backupPrl_args& operator=(const DeviceConfigService_backupPrl_args&);
  DeviceConfigService_backupPrl_args() {
  }

  virtual ~DeviceConfigService_backupPrl_args() noexcept;

  bool operator == (const DeviceConfigService_backupPrl_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_backupPrl_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_backupPrl_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_backupPrl_pargs {
 public:


  virtual ~DeviceConfigService_backupPrl_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_backupPrl_result__isset {
  _DeviceConfigService_backupPrl_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_backupPrl_result__isset;

class DeviceConfigService_backupPrl_result {
 public:

  DeviceConfigService_backupPrl_result(const DeviceConfigService_backupPrl_result&);
  DeviceConfigService_backupPrl_result& operator=(const DeviceConfigService_backupPrl_result&);
  DeviceConfigService_backupPrl_result() : success() {
  }

  virtual ~DeviceConfigService_backupPrl_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_backupPrl_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_backupPrl_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_backupPrl_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_backupPrl_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_backupPrl_presult__isset {
  _DeviceConfigService_backupPrl_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_backupPrl_presult__isset;

class DeviceConfigService_backupPrl_presult {
 public:


  virtual ~DeviceConfigService_backupPrl_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_backupPrl_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_restorePrl_args__isset {
  _DeviceConfigService_restorePrl_args__isset() : xqcnFileContents(false) {}
  bool xqcnFileContents :1;
} _DeviceConfigService_restorePrl_args__isset;

class DeviceConfigService_restorePrl_args {
 public:

  DeviceConfigService_restorePrl_args(const DeviceConfigService_restorePrl_args&);
  DeviceConfigService_restorePrl_args& operator=(const DeviceConfigService_restorePrl_args&);
  DeviceConfigService_restorePrl_args() : xqcnFileContents() {
  }

  virtual ~DeviceConfigService_restorePrl_args() noexcept;
  std::string xqcnFileContents;

  _DeviceConfigService_restorePrl_args__isset __isset;

  void __set_xqcnFileContents(const std::string& val);

  bool operator == (const DeviceConfigService_restorePrl_args & rhs) const
  {
    if (!(xqcnFileContents == rhs.xqcnFileContents))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_restorePrl_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_restorePrl_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_restorePrl_pargs {
 public:


  virtual ~DeviceConfigService_restorePrl_pargs() noexcept;
  const std::string* xqcnFileContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_restorePrl_result__isset {
  _DeviceConfigService_restorePrl_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_restorePrl_result__isset;

class DeviceConfigService_restorePrl_result {
 public:

  DeviceConfigService_restorePrl_result(const DeviceConfigService_restorePrl_result&);
  DeviceConfigService_restorePrl_result& operator=(const DeviceConfigService_restorePrl_result&);
  DeviceConfigService_restorePrl_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_restorePrl_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_restorePrl_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_restorePrl_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_restorePrl_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_restorePrl_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_restorePrl_presult__isset {
  _DeviceConfigService_restorePrl_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_restorePrl_presult__isset;

class DeviceConfigService_restorePrl_presult {
 public:


  virtual ~DeviceConfigService_restorePrl_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_restorePrl_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_sendPrl_args__isset {
  _DeviceConfigService_sendPrl_args__isset() : subscriptionId(false), index(false), prlFileContents(false) {}
  bool subscriptionId :1;
  bool index :1;
  bool prlFileContents :1;
} _DeviceConfigService_sendPrl_args__isset;

class DeviceConfigService_sendPrl_args {
 public:

  DeviceConfigService_sendPrl_args(const DeviceConfigService_sendPrl_args&);
  DeviceConfigService_sendPrl_args& operator=(const DeviceConfigService_sendPrl_args&);
  DeviceConfigService_sendPrl_args() : subscriptionId(0), index(0), prlFileContents() {
  }

  virtual ~DeviceConfigService_sendPrl_args() noexcept;
  int32_t subscriptionId;
  int8_t index;
  std::string prlFileContents;

  _DeviceConfigService_sendPrl_args__isset __isset;

  void __set_subscriptionId(const int32_t val);

  void __set_index(const int8_t val);

  void __set_prlFileContents(const std::string& val);

  bool operator == (const DeviceConfigService_sendPrl_args & rhs) const
  {
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(index == rhs.index))
      return false;
    if (!(prlFileContents == rhs.prlFileContents))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_sendPrl_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_sendPrl_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_sendPrl_pargs {
 public:


  virtual ~DeviceConfigService_sendPrl_pargs() noexcept;
  const int32_t* subscriptionId;
  const int8_t* index;
  const std::string* prlFileContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_sendPrl_result__isset {
  _DeviceConfigService_sendPrl_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_sendPrl_result__isset;

class DeviceConfigService_sendPrl_result {
 public:

  DeviceConfigService_sendPrl_result(const DeviceConfigService_sendPrl_result&);
  DeviceConfigService_sendPrl_result& operator=(const DeviceConfigService_sendPrl_result&);
  DeviceConfigService_sendPrl_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_sendPrl_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_sendPrl_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_sendPrl_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_sendPrl_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_sendPrl_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_sendPrl_presult__isset {
  _DeviceConfigService_sendPrl_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_sendPrl_presult__isset;

class DeviceConfigService_sendPrl_presult {
 public:


  virtual ~DeviceConfigService_sendPrl_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_sendPrl_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_forceEfsSync_args__isset {
  _DeviceConfigService_forceEfsSync_args__isset() : pathName(false), efsSystem(false) {}
  bool pathName :1;
  bool efsSystem :1;
} _DeviceConfigService_forceEfsSync_args__isset;

class DeviceConfigService_forceEfsSync_args {
 public:

  DeviceConfigService_forceEfsSync_args(const DeviceConfigService_forceEfsSync_args&);
  DeviceConfigService_forceEfsSync_args& operator=(const DeviceConfigService_forceEfsSync_args&);
  DeviceConfigService_forceEfsSync_args() : pathName(), efsSystem((FileSystem::type)0) {
  }

  virtual ~DeviceConfigService_forceEfsSync_args() noexcept;
  std::string pathName;
  FileSystem::type efsSystem;

  _DeviceConfigService_forceEfsSync_args__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_efsSystem(const FileSystem::type val);

  bool operator == (const DeviceConfigService_forceEfsSync_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (!(efsSystem == rhs.efsSystem))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_forceEfsSync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_forceEfsSync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_forceEfsSync_pargs {
 public:


  virtual ~DeviceConfigService_forceEfsSync_pargs() noexcept;
  const std::string* pathName;
  const FileSystem::type* efsSystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_forceEfsSync_result__isset {
  _DeviceConfigService_forceEfsSync_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_forceEfsSync_result__isset;

class DeviceConfigService_forceEfsSync_result {
 public:

  DeviceConfigService_forceEfsSync_result(const DeviceConfigService_forceEfsSync_result&);
  DeviceConfigService_forceEfsSync_result& operator=(const DeviceConfigService_forceEfsSync_result&);
  DeviceConfigService_forceEfsSync_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_forceEfsSync_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_forceEfsSync_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_forceEfsSync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_forceEfsSync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_forceEfsSync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_forceEfsSync_presult__isset {
  _DeviceConfigService_forceEfsSync_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_forceEfsSync_presult__isset;

class DeviceConfigService_forceEfsSync_presult {
 public:


  virtual ~DeviceConfigService_forceEfsSync_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_forceEfsSync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_getEsn_args {
 public:

  DeviceConfigService_getEsn_args(const DeviceConfigService_getEsn_args&);
  DeviceConfigService_getEsn_args& operator=(const DeviceConfigService_getEsn_args&);
  DeviceConfigService_getEsn_args() {
  }

  virtual ~DeviceConfigService_getEsn_args() noexcept;

  bool operator == (const DeviceConfigService_getEsn_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_getEsn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getEsn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_getEsn_pargs {
 public:


  virtual ~DeviceConfigService_getEsn_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getEsn_result__isset {
  _DeviceConfigService_getEsn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_getEsn_result__isset;

class DeviceConfigService_getEsn_result {
 public:

  DeviceConfigService_getEsn_result(const DeviceConfigService_getEsn_result&);
  DeviceConfigService_getEsn_result& operator=(const DeviceConfigService_getEsn_result&);
  DeviceConfigService_getEsn_result() : success(0) {
  }

  virtual ~DeviceConfigService_getEsn_result() noexcept;
  int32_t success;
   ::Uts::AppException e;

  _DeviceConfigService_getEsn_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_getEsn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_getEsn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getEsn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getEsn_presult__isset {
  _DeviceConfigService_getEsn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_getEsn_presult__isset;

class DeviceConfigService_getEsn_presult {
 public:


  virtual ~DeviceConfigService_getEsn_presult() noexcept;
  int32_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_getEsn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_setEsn_args__isset {
  _DeviceConfigService_setEsn_args__isset() : esn(false) {}
  bool esn :1;
} _DeviceConfigService_setEsn_args__isset;

class DeviceConfigService_setEsn_args {
 public:

  DeviceConfigService_setEsn_args(const DeviceConfigService_setEsn_args&);
  DeviceConfigService_setEsn_args& operator=(const DeviceConfigService_setEsn_args&);
  DeviceConfigService_setEsn_args() : esn(0) {
  }

  virtual ~DeviceConfigService_setEsn_args() noexcept;
  int32_t esn;

  _DeviceConfigService_setEsn_args__isset __isset;

  void __set_esn(const int32_t val);

  bool operator == (const DeviceConfigService_setEsn_args & rhs) const
  {
    if (!(esn == rhs.esn))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_setEsn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_setEsn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_setEsn_pargs {
 public:


  virtual ~DeviceConfigService_setEsn_pargs() noexcept;
  const int32_t* esn;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_setEsn_result__isset {
  _DeviceConfigService_setEsn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_setEsn_result__isset;

class DeviceConfigService_setEsn_result {
 public:

  DeviceConfigService_setEsn_result(const DeviceConfigService_setEsn_result&);
  DeviceConfigService_setEsn_result& operator=(const DeviceConfigService_setEsn_result&);
  DeviceConfigService_setEsn_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_setEsn_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_setEsn_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_setEsn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_setEsn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_setEsn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_setEsn_presult__isset {
  _DeviceConfigService_setEsn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_setEsn_presult__isset;

class DeviceConfigService_setEsn_presult {
 public:


  virtual ~DeviceConfigService_setEsn_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_setEsn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_getImei_args__isset {
  _DeviceConfigService_getImei_args__isset() : subscriptionId(false) {}
  bool subscriptionId :1;
} _DeviceConfigService_getImei_args__isset;

class DeviceConfigService_getImei_args {
 public:

  DeviceConfigService_getImei_args(const DeviceConfigService_getImei_args&);
  DeviceConfigService_getImei_args& operator=(const DeviceConfigService_getImei_args&);
  DeviceConfigService_getImei_args() : subscriptionId(0) {
  }

  virtual ~DeviceConfigService_getImei_args() noexcept;
  int32_t subscriptionId;

  _DeviceConfigService_getImei_args__isset __isset;

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceConfigService_getImei_args & rhs) const
  {
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_getImei_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getImei_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_getImei_pargs {
 public:


  virtual ~DeviceConfigService_getImei_pargs() noexcept;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getImei_result__isset {
  _DeviceConfigService_getImei_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_getImei_result__isset;

class DeviceConfigService_getImei_result {
 public:

  DeviceConfigService_getImei_result(const DeviceConfigService_getImei_result&);
  DeviceConfigService_getImei_result& operator=(const DeviceConfigService_getImei_result&);
  DeviceConfigService_getImei_result() : success() {
  }

  virtual ~DeviceConfigService_getImei_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_getImei_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_getImei_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_getImei_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getImei_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getImei_presult__isset {
  _DeviceConfigService_getImei_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_getImei_presult__isset;

class DeviceConfigService_getImei_presult {
 public:


  virtual ~DeviceConfigService_getImei_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_getImei_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_setImei_args__isset {
  _DeviceConfigService_setImei_args__isset() : imei(false), subscriptionId(false) {}
  bool imei :1;
  bool subscriptionId :1;
} _DeviceConfigService_setImei_args__isset;

class DeviceConfigService_setImei_args {
 public:

  DeviceConfigService_setImei_args(const DeviceConfigService_setImei_args&);
  DeviceConfigService_setImei_args& operator=(const DeviceConfigService_setImei_args&);
  DeviceConfigService_setImei_args() : imei(), subscriptionId(0) {
  }

  virtual ~DeviceConfigService_setImei_args() noexcept;
  std::string imei;
  int32_t subscriptionId;

  _DeviceConfigService_setImei_args__isset __isset;

  void __set_imei(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceConfigService_setImei_args & rhs) const
  {
    if (!(imei == rhs.imei))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_setImei_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_setImei_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_setImei_pargs {
 public:


  virtual ~DeviceConfigService_setImei_pargs() noexcept;
  const std::string* imei;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_setImei_result__isset {
  _DeviceConfigService_setImei_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_setImei_result__isset;

class DeviceConfigService_setImei_result {
 public:

  DeviceConfigService_setImei_result(const DeviceConfigService_setImei_result&);
  DeviceConfigService_setImei_result& operator=(const DeviceConfigService_setImei_result&);
  DeviceConfigService_setImei_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_setImei_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_setImei_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_setImei_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_setImei_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_setImei_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_setImei_presult__isset {
  _DeviceConfigService_setImei_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_setImei_presult__isset;

class DeviceConfigService_setImei_presult {
 public:


  virtual ~DeviceConfigService_setImei_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_setImei_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_getMeid_args__isset {
  _DeviceConfigService_getMeid_args__isset() : subscriptionId(false) {}
  bool subscriptionId :1;
} _DeviceConfigService_getMeid_args__isset;

class DeviceConfigService_getMeid_args {
 public:

  DeviceConfigService_getMeid_args(const DeviceConfigService_getMeid_args&);
  DeviceConfigService_getMeid_args& operator=(const DeviceConfigService_getMeid_args&);
  DeviceConfigService_getMeid_args() : subscriptionId(0) {
  }

  virtual ~DeviceConfigService_getMeid_args() noexcept;
  int32_t subscriptionId;

  _DeviceConfigService_getMeid_args__isset __isset;

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceConfigService_getMeid_args & rhs) const
  {
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_getMeid_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getMeid_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_getMeid_pargs {
 public:


  virtual ~DeviceConfigService_getMeid_pargs() noexcept;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getMeid_result__isset {
  _DeviceConfigService_getMeid_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_getMeid_result__isset;

class DeviceConfigService_getMeid_result {
 public:

  DeviceConfigService_getMeid_result(const DeviceConfigService_getMeid_result&);
  DeviceConfigService_getMeid_result& operator=(const DeviceConfigService_getMeid_result&);
  DeviceConfigService_getMeid_result() : success(0) {
  }

  virtual ~DeviceConfigService_getMeid_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceConfigService_getMeid_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_getMeid_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_getMeid_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_getMeid_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_getMeid_presult__isset {
  _DeviceConfigService_getMeid_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_getMeid_presult__isset;

class DeviceConfigService_getMeid_presult {
 public:


  virtual ~DeviceConfigService_getMeid_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceConfigService_getMeid_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_setMeid_args__isset {
  _DeviceConfigService_setMeid_args__isset() : meid(false), subscriptionId(false) {}
  bool meid :1;
  bool subscriptionId :1;
} _DeviceConfigService_setMeid_args__isset;

class DeviceConfigService_setMeid_args {
 public:

  DeviceConfigService_setMeid_args(const DeviceConfigService_setMeid_args&);
  DeviceConfigService_setMeid_args& operator=(const DeviceConfigService_setMeid_args&);
  DeviceConfigService_setMeid_args() : meid(0), subscriptionId(0) {
  }

  virtual ~DeviceConfigService_setMeid_args() noexcept;
  int64_t meid;
  int32_t subscriptionId;

  _DeviceConfigService_setMeid_args__isset __isset;

  void __set_meid(const int64_t val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceConfigService_setMeid_args & rhs) const
  {
    if (!(meid == rhs.meid))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_setMeid_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_setMeid_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_setMeid_pargs {
 public:


  virtual ~DeviceConfigService_setMeid_pargs() noexcept;
  const int64_t* meid;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_setMeid_result__isset {
  _DeviceConfigService_setMeid_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_setMeid_result__isset;

class DeviceConfigService_setMeid_result {
 public:

  DeviceConfigService_setMeid_result(const DeviceConfigService_setMeid_result&);
  DeviceConfigService_setMeid_result& operator=(const DeviceConfigService_setMeid_result&);
  DeviceConfigService_setMeid_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_setMeid_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_setMeid_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_setMeid_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_setMeid_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_setMeid_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_setMeid_presult__isset {
  _DeviceConfigService_setMeid_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_setMeid_presult__isset;

class DeviceConfigService_setMeid_presult {
 public:


  virtual ~DeviceConfigService_setMeid_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_setMeid_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_checkSpc_args__isset {
  _DeviceConfigService_checkSpc_args__isset() : spc(false) {}
  bool spc :1;
} _DeviceConfigService_checkSpc_args__isset;

class DeviceConfigService_checkSpc_args {
 public:

  DeviceConfigService_checkSpc_args(const DeviceConfigService_checkSpc_args&);
  DeviceConfigService_checkSpc_args& operator=(const DeviceConfigService_checkSpc_args&);
  DeviceConfigService_checkSpc_args() : spc() {
  }

  virtual ~DeviceConfigService_checkSpc_args() noexcept;
  std::string spc;

  _DeviceConfigService_checkSpc_args__isset __isset;

  void __set_spc(const std::string& val);

  bool operator == (const DeviceConfigService_checkSpc_args & rhs) const
  {
    if (!(spc == rhs.spc))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_checkSpc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_checkSpc_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_checkSpc_pargs {
 public:


  virtual ~DeviceConfigService_checkSpc_pargs() noexcept;
  const std::string* spc;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_checkSpc_result__isset {
  _DeviceConfigService_checkSpc_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_checkSpc_result__isset;

class DeviceConfigService_checkSpc_result {
 public:

  DeviceConfigService_checkSpc_result(const DeviceConfigService_checkSpc_result&);
  DeviceConfigService_checkSpc_result& operator=(const DeviceConfigService_checkSpc_result&);
  DeviceConfigService_checkSpc_result() : success(0) {
  }

  virtual ~DeviceConfigService_checkSpc_result() noexcept;
  bool success;
   ::Uts::AppException e;

  _DeviceConfigService_checkSpc_result__isset __isset;

  void __set_success(const bool val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_checkSpc_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_checkSpc_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_checkSpc_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_checkSpc_presult__isset {
  _DeviceConfigService_checkSpc_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_checkSpc_presult__isset;

class DeviceConfigService_checkSpc_presult {
 public:


  virtual ~DeviceConfigService_checkSpc_presult() noexcept;
  bool* success;
   ::Uts::AppException e;

  _DeviceConfigService_checkSpc_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_provisionSpc_args__isset {
  _DeviceConfigService_provisionSpc_args__isset() : currentSpc(false), newSpc(false) {}
  bool currentSpc :1;
  bool newSpc :1;
} _DeviceConfigService_provisionSpc_args__isset;

class DeviceConfigService_provisionSpc_args {
 public:

  DeviceConfigService_provisionSpc_args(const DeviceConfigService_provisionSpc_args&);
  DeviceConfigService_provisionSpc_args& operator=(const DeviceConfigService_provisionSpc_args&);
  DeviceConfigService_provisionSpc_args() : currentSpc(), newSpc() {
  }

  virtual ~DeviceConfigService_provisionSpc_args() noexcept;
  std::string currentSpc;
  std::string newSpc;

  _DeviceConfigService_provisionSpc_args__isset __isset;

  void __set_currentSpc(const std::string& val);

  void __set_newSpc(const std::string& val);

  bool operator == (const DeviceConfigService_provisionSpc_args & rhs) const
  {
    if (!(currentSpc == rhs.currentSpc))
      return false;
    if (!(newSpc == rhs.newSpc))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_provisionSpc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_provisionSpc_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_provisionSpc_pargs {
 public:


  virtual ~DeviceConfigService_provisionSpc_pargs() noexcept;
  const std::string* currentSpc;
  const std::string* newSpc;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_provisionSpc_result__isset {
  _DeviceConfigService_provisionSpc_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_provisionSpc_result__isset;

class DeviceConfigService_provisionSpc_result {
 public:

  DeviceConfigService_provisionSpc_result(const DeviceConfigService_provisionSpc_result&);
  DeviceConfigService_provisionSpc_result& operator=(const DeviceConfigService_provisionSpc_result&);
  DeviceConfigService_provisionSpc_result() : success(0) {
  }

  virtual ~DeviceConfigService_provisionSpc_result() noexcept;
  bool success;
   ::Uts::AppException e;

  _DeviceConfigService_provisionSpc_result__isset __isset;

  void __set_success(const bool val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_provisionSpc_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_provisionSpc_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_provisionSpc_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_provisionSpc_presult__isset {
  _DeviceConfigService_provisionSpc_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_provisionSpc_presult__isset;

class DeviceConfigService_provisionSpc_presult {
 public:


  virtual ~DeviceConfigService_provisionSpc_presult() noexcept;
  bool* success;
   ::Uts::AppException e;

  _DeviceConfigService_provisionSpc_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceConfigService_efsReadFromModemLog_args {
 public:

  DeviceConfigService_efsReadFromModemLog_args(const DeviceConfigService_efsReadFromModemLog_args&);
  DeviceConfigService_efsReadFromModemLog_args& operator=(const DeviceConfigService_efsReadFromModemLog_args&);
  DeviceConfigService_efsReadFromModemLog_args() {
  }

  virtual ~DeviceConfigService_efsReadFromModemLog_args() noexcept;

  bool operator == (const DeviceConfigService_efsReadFromModemLog_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceConfigService_efsReadFromModemLog_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsReadFromModemLog_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_efsReadFromModemLog_pargs {
 public:


  virtual ~DeviceConfigService_efsReadFromModemLog_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsReadFromModemLog_result__isset {
  _DeviceConfigService_efsReadFromModemLog_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsReadFromModemLog_result__isset;

class DeviceConfigService_efsReadFromModemLog_result {
 public:

  DeviceConfigService_efsReadFromModemLog_result(const DeviceConfigService_efsReadFromModemLog_result&);
  DeviceConfigService_efsReadFromModemLog_result& operator=(const DeviceConfigService_efsReadFromModemLog_result&);
  DeviceConfigService_efsReadFromModemLog_result() : success() {
  }

  virtual ~DeviceConfigService_efsReadFromModemLog_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceConfigService_efsReadFromModemLog_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_efsReadFromModemLog_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_efsReadFromModemLog_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_efsReadFromModemLog_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_efsReadFromModemLog_presult__isset {
  _DeviceConfigService_efsReadFromModemLog_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_efsReadFromModemLog_presult__isset;

class DeviceConfigService_efsReadFromModemLog_presult {
 public:


  virtual ~DeviceConfigService_efsReadFromModemLog_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceConfigService_efsReadFromModemLog_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceConfigService_configureService_args__isset {
  _DeviceConfigService_configureService_args__isset() : deviceConfigOptions(false) {}
  bool deviceConfigOptions :1;
} _DeviceConfigService_configureService_args__isset;

class DeviceConfigService_configureService_args {
 public:

  DeviceConfigService_configureService_args(const DeviceConfigService_configureService_args&);
  DeviceConfigService_configureService_args& operator=(const DeviceConfigService_configureService_args&);
  DeviceConfigService_configureService_args() {
  }

  virtual ~DeviceConfigService_configureService_args() noexcept;
  DeviceConfigOptions deviceConfigOptions;

  _DeviceConfigService_configureService_args__isset __isset;

  void __set_deviceConfigOptions(const DeviceConfigOptions& val);

  bool operator == (const DeviceConfigService_configureService_args & rhs) const
  {
    if (!(deviceConfigOptions == rhs.deviceConfigOptions))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_configureService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_configureService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceConfigService_configureService_pargs {
 public:


  virtual ~DeviceConfigService_configureService_pargs() noexcept;
  const DeviceConfigOptions* deviceConfigOptions;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_configureService_result__isset {
  _DeviceConfigService_configureService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_configureService_result__isset;

class DeviceConfigService_configureService_result {
 public:

  DeviceConfigService_configureService_result(const DeviceConfigService_configureService_result&);
  DeviceConfigService_configureService_result& operator=(const DeviceConfigService_configureService_result&);
  DeviceConfigService_configureService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceConfigService_configureService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceConfigService_configureService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceConfigService_configureService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigService_configureService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigService_configureService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceConfigService_configureService_presult__isset {
  _DeviceConfigService_configureService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceConfigService_configureService_presult__isset;

class DeviceConfigService_configureService_presult {
 public:


  virtual ~DeviceConfigService_configureService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceConfigService_configureService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class DeviceConfigServiceClient : virtual public DeviceConfigServiceIf {
 public:
  DeviceConfigServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  DeviceConfigServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getLastError( ::Uts::ErrorType& _return);
  void send_getLastError();
  void recv_getLastError( ::Uts::ErrorType& _return);
  int64_t getDevice();
  void send_getDevice();
  int64_t recv_getDevice();
   ::Uts::ErrorCode::type initializeService();
  void send_initializeService();
   ::Uts::ErrorCode::type recv_initializeService();
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle);
  void send_initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle);
   ::Uts::ErrorCode::type recv_initializeServiceByProtocol();
   ::Uts::ErrorCode::type initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions);
  void send_initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions);
   ::Uts::ErrorCode::type recv_initializeServiceWithOptions();
   ::Uts::ErrorCode::type destroyService();
  void send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService();
  void doXqcnOperation( ::Uts::DeviceConfigResp& _return, const DeviceConfigOptions& deviceConfigOptions);
  void send_doXqcnOperation(const DeviceConfigOptions& deviceConfigOptions);
  void recv_doXqcnOperation( ::Uts::DeviceConfigResp& _return);
  void backupToXqcn(std::string& _return, const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents);
  void send_backupToXqcn(const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents);
  void recv_backupToXqcn(std::string& _return);
   ::Uts::ErrorCode::type restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents);
  void send_restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents);
   ::Uts::ErrorCode::type recv_restoreFromXqcn();
  int64_t pdcGetMbnMaxStorage(const PdcMbnType::type mbnType);
  void send_pdcGetMbnMaxStorage(const PdcMbnType::type mbnType);
  int64_t recv_pdcGetMbnMaxStorage();
  int64_t pdcGetMbnStorageUsage(const PdcMbnType::type mbnType);
  void send_pdcGetMbnStorageUsage(const PdcMbnType::type mbnType);
  int64_t recv_pdcGetMbnStorageUsage();
  int64_t pdcGetMbnCount(const PdcMbnType::type mbnType);
  void send_pdcGetMbnCount(const PdcMbnType::type mbnType);
  int64_t recv_pdcGetMbnCount();
  void pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const PdcMbnType::type mbnType);
  void send_pdcGetMbnList(const PdcMbnType::type mbnType);
  void recv_pdcGetMbnList(std::vector<PdcMbnInfo> & _return);
  void pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const PdcMbnType::type mbnType);
  void send_pdcGetDefaultMbnInfo(const PdcMbnType::type mbnType);
  void recv_pdcGetDefaultMbnInfo(PdcMbnInfo& _return);
  void pdcGetMbnId(std::string& _return, const std::string& mbnContent);
  void send_pdcGetMbnId(const std::string& mbnContent);
  void recv_pdcGetMbnId(std::string& _return);
   ::Uts::ErrorCode::type pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent);
  void send_pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent);
   ::Uts::ErrorCode::type recv_pdcWriteMbn();
  void pdcReadMbn(std::string& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId);
  void send_pdcReadMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId);
  void recv_pdcReadMbn(std::string& _return);
   ::Uts::ErrorCode::type pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId);
  void send_pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId);
   ::Uts::ErrorCode::type recv_pdcRemoveMbn();
  void pdcGetActiveMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId);
  void send_pdcGetActiveMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId);
  void recv_pdcGetActiveMbn(std::string& _return);
  void pdcGetPendingMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId);
  void send_pdcGetPendingMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId);
  void recv_pdcGetPendingMbn(std::string& _return);
  void pdcValidateMbn(PdcMbnResult& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath);
  void send_pdcValidateMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath);
  void recv_pdcValidateMbn(PdcMbnResult& _return);
   ::Uts::ErrorCode::type pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId);
  void send_pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId);
   ::Uts::ErrorCode::type recv_pdcSelectMbn();
   ::Uts::ErrorCode::type pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout);
  void send_pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout);
   ::Uts::ErrorCode::type recv_pdcActivateMbn();
   ::Uts::ErrorCode::type pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId);
  void send_pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId);
   ::Uts::ErrorCode::type recv_pdcDeactivateMbn();
  int32_t pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature);
  void send_pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature);
  int32_t recv_pdcGetConfiguration();
   ::Uts::ErrorCode::type pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value);
  void send_pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value);
   ::Uts::ErrorCode::type recv_pdcSetConfiguration();
  bool nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId);
  void send_nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId);
  bool recv_nvIsItemSupported();
  void nvReadItem(NvData& _return, const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig);
  void send_nvReadItem(const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig);
  void recv_nvReadItem(NvData& _return);
   ::Uts::ErrorCode::type nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId);
  void send_nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_nvSetItem();
   ::Uts::ErrorCode::type nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId);
  void send_nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_nvSetOtpItem();
  void nvGetAllItems(std::vector< ::Uts::NvItem> & _return);
  void send_nvGetAllItems();
  void recv_nvGetAllItems(std::vector< ::Uts::NvItem> & _return);
  void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId);
  void send_nvGetItemDefinition(const std::string& nvItemNameOrId);
  void recv_nvGetItemDefinition(std::string& _return);
  bool efsHasAlternateFileSystem();
  void send_efsHasAlternateFileSystem();
  bool recv_efsHasAlternateFileSystem();
   ::Uts::ErrorCode::type efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsCreateDirectory();
   ::Uts::ErrorCode::type efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsRemoveDirectory();
   ::Uts::ErrorCode::type efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem);
  void send_efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem);
   ::Uts::ErrorCode::type recv_efsRemoveTree();
  void efsGetDirectoryContents(std::vector<EfsItem> & _return, const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsGetDirectoryContents(const std::string& pathName, const FileSystem::type efsSystem);
  void recv_efsGetDirectoryContents(std::vector<EfsItem> & _return);
   ::Uts::ErrorCode::type efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem);
  void send_efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsPutFile();
  void efsGetFile(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsGetFile(const std::string& pathName, const FileSystem::type efsSystem);
  void recv_efsGetFile(std::string& _return);
   ::Uts::ErrorCode::type efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsDeleteFile();
   ::Uts::ErrorCode::type efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem);
  void send_efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsRename();
  bool efsPathExists(const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsPathExists(const std::string& pathName, const FileSystem::type efsSystem);
  bool recv_efsPathExists();
  bool efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem);
  bool recv_efsIsDirectory();
  bool efsIsFile(const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsIsFile(const std::string& pathName, const FileSystem::type efsSystem);
  bool recv_efsIsFile();
  int64_t efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem);
  int64_t recv_efsGetFileSize();
  int64_t efsGetAvailableSpace(const FileSystem::type efsSystem);
  void send_efsGetAvailableSpace(const FileSystem::type efsSystem);
  int64_t recv_efsGetAvailableSpace();
  void efsGetFileCheckSum(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsGetFileCheckSum(const std::string& pathName, const FileSystem::type efsSystem);
  void recv_efsGetFileCheckSum(std::string& _return);
  void efsGetFileAttributes(EfsFileAttributes& _return, const std::string& pathName, const FileSystem::type efsSystem);
  void send_efsGetFileAttributes(const std::string& pathName, const FileSystem::type efsSystem);
  void recv_efsGetFileAttributes(EfsFileAttributes& _return);
  bool efsIsReady();
  void send_efsIsReady();
  bool recv_efsIsReady();
   ::Uts::ErrorCode::type createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem);
  void send_createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_createGoldenCopy();
   ::Uts::ErrorCode::type createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem);
  void send_createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_createCefsCopy();
  void requestPrl(std::string& _return, const int32_t subscriptionId, const int8_t index);
  void send_requestPrl(const int32_t subscriptionId, const int8_t index);
  void recv_requestPrl(std::string& _return);
  void backupPrl(std::string& _return);
  void send_backupPrl();
  void recv_backupPrl(std::string& _return);
   ::Uts::ErrorCode::type restorePrl(const std::string& xqcnFileContents);
  void send_restorePrl(const std::string& xqcnFileContents);
   ::Uts::ErrorCode::type recv_restorePrl();
   ::Uts::ErrorCode::type sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents);
  void send_sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents);
   ::Uts::ErrorCode::type recv_sendPrl();
   ::Uts::ErrorCode::type forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem);
  void send_forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_forceEfsSync();
  int32_t getEsn();
  void send_getEsn();
  int32_t recv_getEsn();
   ::Uts::ErrorCode::type setEsn(const int32_t esn);
  void send_setEsn(const int32_t esn);
   ::Uts::ErrorCode::type recv_setEsn();
  void getImei(std::string& _return, const int32_t subscriptionId);
  void send_getImei(const int32_t subscriptionId);
  void recv_getImei(std::string& _return);
   ::Uts::ErrorCode::type setImei(const std::string& imei, const int32_t subscriptionId);
  void send_setImei(const std::string& imei, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_setImei();
  int64_t getMeid(const int32_t subscriptionId);
  void send_getMeid(const int32_t subscriptionId);
  int64_t recv_getMeid();
   ::Uts::ErrorCode::type setMeid(const int64_t meid, const int32_t subscriptionId);
  void send_setMeid(const int64_t meid, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_setMeid();
  bool checkSpc(const std::string& spc);
  void send_checkSpc(const std::string& spc);
  bool recv_checkSpc();
  bool provisionSpc(const std::string& currentSpc, const std::string& newSpc);
  void send_provisionSpc(const std::string& currentSpc, const std::string& newSpc);
  bool recv_provisionSpc();
  void efsReadFromModemLog(std::string& _return);
  void send_efsReadFromModemLog();
  void recv_efsReadFromModemLog(std::string& _return);
   ::Uts::ErrorCode::type configureService(const DeviceConfigOptions& deviceConfigOptions);
  void send_configureService(const DeviceConfigOptions& deviceConfigOptions);
   ::Uts::ErrorCode::type recv_configureService();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class DeviceConfigServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<DeviceConfigServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (DeviceConfigServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeServiceByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeServiceWithOptions(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_destroyService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_doXqcnOperation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_backupToXqcn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_restoreFromXqcn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetMbnMaxStorage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetMbnStorageUsage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetMbnCount(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetMbnList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetDefaultMbnInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetMbnId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcWriteMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcReadMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcRemoveMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetActiveMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetPendingMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcValidateMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcSelectMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcActivateMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcDeactivateMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcGetConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_pdcSetConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_nvIsItemSupported(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_nvReadItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_nvSetItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_nvSetOtpItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_nvGetAllItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_nvGetItemDefinition(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsHasAlternateFileSystem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsCreateDirectory(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsRemoveDirectory(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsRemoveTree(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsGetDirectoryContents(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsPutFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsGetFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsDeleteFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsRename(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsPathExists(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsIsDirectory(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsIsFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsGetFileSize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsGetAvailableSpace(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsGetFileCheckSum(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsGetFileAttributes(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsIsReady(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createGoldenCopy(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createCefsCopy(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_requestPrl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_backupPrl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_restorePrl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendPrl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_forceEfsSync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getEsn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setEsn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getImei(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setImei(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getMeid(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setMeid(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_checkSpc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_provisionSpc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_efsReadFromModemLog(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_configureService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  DeviceConfigServiceProcessor(::std::shared_ptr<DeviceConfigServiceIf> iface) :
    iface_(iface) {
    processMap_["getLastError"] = &DeviceConfigServiceProcessor::process_getLastError;
    processMap_["getDevice"] = &DeviceConfigServiceProcessor::process_getDevice;
    processMap_["initializeService"] = &DeviceConfigServiceProcessor::process_initializeService;
    processMap_["initializeServiceByProtocol"] = &DeviceConfigServiceProcessor::process_initializeServiceByProtocol;
    processMap_["initializeServiceWithOptions"] = &DeviceConfigServiceProcessor::process_initializeServiceWithOptions;
    processMap_["destroyService"] = &DeviceConfigServiceProcessor::process_destroyService;
    processMap_["doXqcnOperation"] = &DeviceConfigServiceProcessor::process_doXqcnOperation;
    processMap_["backupToXqcn"] = &DeviceConfigServiceProcessor::process_backupToXqcn;
    processMap_["restoreFromXqcn"] = &DeviceConfigServiceProcessor::process_restoreFromXqcn;
    processMap_["pdcGetMbnMaxStorage"] = &DeviceConfigServiceProcessor::process_pdcGetMbnMaxStorage;
    processMap_["pdcGetMbnStorageUsage"] = &DeviceConfigServiceProcessor::process_pdcGetMbnStorageUsage;
    processMap_["pdcGetMbnCount"] = &DeviceConfigServiceProcessor::process_pdcGetMbnCount;
    processMap_["pdcGetMbnList"] = &DeviceConfigServiceProcessor::process_pdcGetMbnList;
    processMap_["pdcGetDefaultMbnInfo"] = &DeviceConfigServiceProcessor::process_pdcGetDefaultMbnInfo;
    processMap_["pdcGetMbnId"] = &DeviceConfigServiceProcessor::process_pdcGetMbnId;
    processMap_["pdcWriteMbn"] = &DeviceConfigServiceProcessor::process_pdcWriteMbn;
    processMap_["pdcReadMbn"] = &DeviceConfigServiceProcessor::process_pdcReadMbn;
    processMap_["pdcRemoveMbn"] = &DeviceConfigServiceProcessor::process_pdcRemoveMbn;
    processMap_["pdcGetActiveMbn"] = &DeviceConfigServiceProcessor::process_pdcGetActiveMbn;
    processMap_["pdcGetPendingMbn"] = &DeviceConfigServiceProcessor::process_pdcGetPendingMbn;
    processMap_["pdcValidateMbn"] = &DeviceConfigServiceProcessor::process_pdcValidateMbn;
    processMap_["pdcSelectMbn"] = &DeviceConfigServiceProcessor::process_pdcSelectMbn;
    processMap_["pdcActivateMbn"] = &DeviceConfigServiceProcessor::process_pdcActivateMbn;
    processMap_["pdcDeactivateMbn"] = &DeviceConfigServiceProcessor::process_pdcDeactivateMbn;
    processMap_["pdcGetConfiguration"] = &DeviceConfigServiceProcessor::process_pdcGetConfiguration;
    processMap_["pdcSetConfiguration"] = &DeviceConfigServiceProcessor::process_pdcSetConfiguration;
    processMap_["nvIsItemSupported"] = &DeviceConfigServiceProcessor::process_nvIsItemSupported;
    processMap_["nvReadItem"] = &DeviceConfigServiceProcessor::process_nvReadItem;
    processMap_["nvSetItem"] = &DeviceConfigServiceProcessor::process_nvSetItem;
    processMap_["nvSetOtpItem"] = &DeviceConfigServiceProcessor::process_nvSetOtpItem;
    processMap_["nvGetAllItems"] = &DeviceConfigServiceProcessor::process_nvGetAllItems;
    processMap_["nvGetItemDefinition"] = &DeviceConfigServiceProcessor::process_nvGetItemDefinition;
    processMap_["efsHasAlternateFileSystem"] = &DeviceConfigServiceProcessor::process_efsHasAlternateFileSystem;
    processMap_["efsCreateDirectory"] = &DeviceConfigServiceProcessor::process_efsCreateDirectory;
    processMap_["efsRemoveDirectory"] = &DeviceConfigServiceProcessor::process_efsRemoveDirectory;
    processMap_["efsRemoveTree"] = &DeviceConfigServiceProcessor::process_efsRemoveTree;
    processMap_["efsGetDirectoryContents"] = &DeviceConfigServiceProcessor::process_efsGetDirectoryContents;
    processMap_["efsPutFile"] = &DeviceConfigServiceProcessor::process_efsPutFile;
    processMap_["efsGetFile"] = &DeviceConfigServiceProcessor::process_efsGetFile;
    processMap_["efsDeleteFile"] = &DeviceConfigServiceProcessor::process_efsDeleteFile;
    processMap_["efsRename"] = &DeviceConfigServiceProcessor::process_efsRename;
    processMap_["efsPathExists"] = &DeviceConfigServiceProcessor::process_efsPathExists;
    processMap_["efsIsDirectory"] = &DeviceConfigServiceProcessor::process_efsIsDirectory;
    processMap_["efsIsFile"] = &DeviceConfigServiceProcessor::process_efsIsFile;
    processMap_["efsGetFileSize"] = &DeviceConfigServiceProcessor::process_efsGetFileSize;
    processMap_["efsGetAvailableSpace"] = &DeviceConfigServiceProcessor::process_efsGetAvailableSpace;
    processMap_["efsGetFileCheckSum"] = &DeviceConfigServiceProcessor::process_efsGetFileCheckSum;
    processMap_["efsGetFileAttributes"] = &DeviceConfigServiceProcessor::process_efsGetFileAttributes;
    processMap_["efsIsReady"] = &DeviceConfigServiceProcessor::process_efsIsReady;
    processMap_["createGoldenCopy"] = &DeviceConfigServiceProcessor::process_createGoldenCopy;
    processMap_["createCefsCopy"] = &DeviceConfigServiceProcessor::process_createCefsCopy;
    processMap_["requestPrl"] = &DeviceConfigServiceProcessor::process_requestPrl;
    processMap_["backupPrl"] = &DeviceConfigServiceProcessor::process_backupPrl;
    processMap_["restorePrl"] = &DeviceConfigServiceProcessor::process_restorePrl;
    processMap_["sendPrl"] = &DeviceConfigServiceProcessor::process_sendPrl;
    processMap_["forceEfsSync"] = &DeviceConfigServiceProcessor::process_forceEfsSync;
    processMap_["getEsn"] = &DeviceConfigServiceProcessor::process_getEsn;
    processMap_["setEsn"] = &DeviceConfigServiceProcessor::process_setEsn;
    processMap_["getImei"] = &DeviceConfigServiceProcessor::process_getImei;
    processMap_["setImei"] = &DeviceConfigServiceProcessor::process_setImei;
    processMap_["getMeid"] = &DeviceConfigServiceProcessor::process_getMeid;
    processMap_["setMeid"] = &DeviceConfigServiceProcessor::process_setMeid;
    processMap_["checkSpc"] = &DeviceConfigServiceProcessor::process_checkSpc;
    processMap_["provisionSpc"] = &DeviceConfigServiceProcessor::process_provisionSpc;
    processMap_["efsReadFromModemLog"] = &DeviceConfigServiceProcessor::process_efsReadFromModemLog;
    processMap_["configureService"] = &DeviceConfigServiceProcessor::process_configureService;
  }

  virtual ~DeviceConfigServiceProcessor() {}
};

class DeviceConfigServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  DeviceConfigServiceProcessorFactory(const ::std::shared_ptr< DeviceConfigServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< DeviceConfigServiceIfFactory > handlerFactory_;
};

class DeviceConfigServiceMultiface : virtual public DeviceConfigServiceIf {
 public:
  DeviceConfigServiceMultiface(std::vector<std::shared_ptr<DeviceConfigServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~DeviceConfigServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<DeviceConfigServiceIf> > ifaces_;
  DeviceConfigServiceMultiface() {}
  void add(::std::shared_ptr<DeviceConfigServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getLastError( ::Uts::ErrorType& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getLastError(_return);
    }
    ifaces_[i]->getLastError(_return);
    return;
  }

  int64_t getDevice() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDevice();
    }
    return ifaces_[i]->getDevice();
  }

   ::Uts::ErrorCode::type initializeService() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initializeService();
    }
    return ifaces_[i]->initializeService();
  }

   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initializeServiceByProtocol(diagProtocolHandle, qmiProtocolHandle);
    }
    return ifaces_[i]->initializeServiceByProtocol(diagProtocolHandle, qmiProtocolHandle);
  }

   ::Uts::ErrorCode::type initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initializeServiceWithOptions(connectionOptions);
    }
    return ifaces_[i]->initializeServiceWithOptions(connectionOptions);
  }

   ::Uts::ErrorCode::type destroyService() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->destroyService();
    }
    return ifaces_[i]->destroyService();
  }

  void doXqcnOperation( ::Uts::DeviceConfigResp& _return, const DeviceConfigOptions& deviceConfigOptions) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->doXqcnOperation(_return, deviceConfigOptions);
    }
    ifaces_[i]->doXqcnOperation(_return, deviceConfigOptions);
    return;
  }

  void backupToXqcn(std::string& _return, const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->backupToXqcn(_return, serviceProgrammingCode, resetUponCompletion, resetTimeout, filterFileContents);
    }
    ifaces_[i]->backupToXqcn(_return, serviceProgrammingCode, resetUponCompletion, resetTimeout, filterFileContents);
    return;
  }

   ::Uts::ErrorCode::type restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->restoreFromXqcn(xqcnFileContents, serviceProgrammingCode, allowEsnMismatch, resetUponCompletion, resetTimeout, filterFileContents);
    }
    return ifaces_[i]->restoreFromXqcn(xqcnFileContents, serviceProgrammingCode, allowEsnMismatch, resetUponCompletion, resetTimeout, filterFileContents);
  }

  int64_t pdcGetMbnMaxStorage(const PdcMbnType::type mbnType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetMbnMaxStorage(mbnType);
    }
    return ifaces_[i]->pdcGetMbnMaxStorage(mbnType);
  }

  int64_t pdcGetMbnStorageUsage(const PdcMbnType::type mbnType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetMbnStorageUsage(mbnType);
    }
    return ifaces_[i]->pdcGetMbnStorageUsage(mbnType);
  }

  int64_t pdcGetMbnCount(const PdcMbnType::type mbnType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetMbnCount(mbnType);
    }
    return ifaces_[i]->pdcGetMbnCount(mbnType);
  }

  void pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const PdcMbnType::type mbnType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetMbnList(_return, mbnType);
    }
    ifaces_[i]->pdcGetMbnList(_return, mbnType);
    return;
  }

  void pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const PdcMbnType::type mbnType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetDefaultMbnInfo(_return, mbnType);
    }
    ifaces_[i]->pdcGetDefaultMbnInfo(_return, mbnType);
    return;
  }

  void pdcGetMbnId(std::string& _return, const std::string& mbnContent) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetMbnId(_return, mbnContent);
    }
    ifaces_[i]->pdcGetMbnId(_return, mbnContent);
    return;
  }

   ::Uts::ErrorCode::type pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcWriteMbn(mbnType, mbnContent);
    }
    return ifaces_[i]->pdcWriteMbn(mbnType, mbnContent);
  }

  void pdcReadMbn(std::string& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcReadMbn(_return, mbnType, mbnId, subId);
    }
    ifaces_[i]->pdcReadMbn(_return, mbnType, mbnId, subId);
    return;
  }

   ::Uts::ErrorCode::type pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcRemoveMbn(mbnType, mbnId);
    }
    return ifaces_[i]->pdcRemoveMbn(mbnType, mbnId);
  }

  void pdcGetActiveMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetActiveMbn(_return, mbnType, subId, slotId);
    }
    ifaces_[i]->pdcGetActiveMbn(_return, mbnType, subId, slotId);
    return;
  }

  void pdcGetPendingMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetPendingMbn(_return, mbnType, subId, slotId);
    }
    ifaces_[i]->pdcGetPendingMbn(_return, mbnType, subId, slotId);
    return;
  }

  void pdcValidateMbn(PdcMbnResult& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcValidateMbn(_return, mbnType, mbnId, subId, remotePath);
    }
    ifaces_[i]->pdcValidateMbn(_return, mbnType, mbnId, subId, remotePath);
    return;
  }

   ::Uts::ErrorCode::type pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcSelectMbn(mbnType, mbnId, subId, slotId);
    }
    return ifaces_[i]->pdcSelectMbn(mbnType, mbnId, subId, slotId);
  }

   ::Uts::ErrorCode::type pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcActivateMbn(mbnType, subId, slotId, mode, timeout);
    }
    return ifaces_[i]->pdcActivateMbn(mbnType, subId, slotId, mode, timeout);
  }

   ::Uts::ErrorCode::type pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcDeactivateMbn(mbnType, subId);
    }
    return ifaces_[i]->pdcDeactivateMbn(mbnType, subId);
  }

  int32_t pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcGetConfiguration(slotId, feature);
    }
    return ifaces_[i]->pdcGetConfiguration(slotId, feature);
  }

   ::Uts::ErrorCode::type pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->pdcSetConfiguration(slotId, feature, value);
    }
    return ifaces_[i]->pdcSetConfiguration(slotId, feature, value);
  }

  bool nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->nvIsItemSupported(nvItemNameOrId, subscriptionId);
    }
    return ifaces_[i]->nvIsItemSupported(nvItemNameOrId, subscriptionId);
  }

  void nvReadItem(NvData& _return, const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->nvReadItem(_return, nvItemNameOrId, subscriptionId, index, returnConfig);
    }
    ifaces_[i]->nvReadItem(_return, nvItemNameOrId, subscriptionId, index, returnConfig);
    return;
  }

   ::Uts::ErrorCode::type nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->nvSetItem(nvItemNameOrId, valueList, subscriptionId);
    }
    return ifaces_[i]->nvSetItem(nvItemNameOrId, valueList, subscriptionId);
  }

   ::Uts::ErrorCode::type nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->nvSetOtpItem(nvItemNameOrId, valueList, subscriptionId);
    }
    return ifaces_[i]->nvSetOtpItem(nvItemNameOrId, valueList, subscriptionId);
  }

  void nvGetAllItems(std::vector< ::Uts::NvItem> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->nvGetAllItems(_return);
    }
    ifaces_[i]->nvGetAllItems(_return);
    return;
  }

  void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->nvGetItemDefinition(_return, nvItemNameOrId);
    }
    ifaces_[i]->nvGetItemDefinition(_return, nvItemNameOrId);
    return;
  }

  bool efsHasAlternateFileSystem() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsHasAlternateFileSystem();
    }
    return ifaces_[i]->efsHasAlternateFileSystem();
  }

   ::Uts::ErrorCode::type efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsCreateDirectory(pathName, efsSystem);
    }
    return ifaces_[i]->efsCreateDirectory(pathName, efsSystem);
  }

   ::Uts::ErrorCode::type efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsRemoveDirectory(pathName, efsSystem);
    }
    return ifaces_[i]->efsRemoveDirectory(pathName, efsSystem);
  }

   ::Uts::ErrorCode::type efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsRemoveTree(pathName, efsSytem);
    }
    return ifaces_[i]->efsRemoveTree(pathName, efsSytem);
  }

  void efsGetDirectoryContents(std::vector<EfsItem> & _return, const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsGetDirectoryContents(_return, pathName, efsSystem);
    }
    ifaces_[i]->efsGetDirectoryContents(_return, pathName, efsSystem);
    return;
  }

   ::Uts::ErrorCode::type efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsPutFile(pathName, buffer, efsSystem);
    }
    return ifaces_[i]->efsPutFile(pathName, buffer, efsSystem);
  }

  void efsGetFile(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsGetFile(_return, pathName, efsSystem);
    }
    ifaces_[i]->efsGetFile(_return, pathName, efsSystem);
    return;
  }

   ::Uts::ErrorCode::type efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsDeleteFile(pathName, efsSystem);
    }
    return ifaces_[i]->efsDeleteFile(pathName, efsSystem);
  }

   ::Uts::ErrorCode::type efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsRename(existingName, newName, efsSystem);
    }
    return ifaces_[i]->efsRename(existingName, newName, efsSystem);
  }

  bool efsPathExists(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsPathExists(pathName, efsSystem);
    }
    return ifaces_[i]->efsPathExists(pathName, efsSystem);
  }

  bool efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsIsDirectory(pathName, efsSystem);
    }
    return ifaces_[i]->efsIsDirectory(pathName, efsSystem);
  }

  bool efsIsFile(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsIsFile(pathName, efsSystem);
    }
    return ifaces_[i]->efsIsFile(pathName, efsSystem);
  }

  int64_t efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsGetFileSize(pathName, efsSystem);
    }
    return ifaces_[i]->efsGetFileSize(pathName, efsSystem);
  }

  int64_t efsGetAvailableSpace(const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsGetAvailableSpace(efsSystem);
    }
    return ifaces_[i]->efsGetAvailableSpace(efsSystem);
  }

  void efsGetFileCheckSum(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsGetFileCheckSum(_return, pathName, efsSystem);
    }
    ifaces_[i]->efsGetFileCheckSum(_return, pathName, efsSystem);
    return;
  }

  void efsGetFileAttributes(EfsFileAttributes& _return, const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsGetFileAttributes(_return, pathName, efsSystem);
    }
    ifaces_[i]->efsGetFileAttributes(_return, pathName, efsSystem);
    return;
  }

  bool efsIsReady() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsIsReady();
    }
    return ifaces_[i]->efsIsReady();
  }

   ::Uts::ErrorCode::type createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createGoldenCopy(pathName, efsSystem);
    }
    return ifaces_[i]->createGoldenCopy(pathName, efsSystem);
  }

   ::Uts::ErrorCode::type createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createCefsCopy(cefsSavePath, efsSystem);
    }
    return ifaces_[i]->createCefsCopy(cefsSavePath, efsSystem);
  }

  void requestPrl(std::string& _return, const int32_t subscriptionId, const int8_t index) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->requestPrl(_return, subscriptionId, index);
    }
    ifaces_[i]->requestPrl(_return, subscriptionId, index);
    return;
  }

  void backupPrl(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->backupPrl(_return);
    }
    ifaces_[i]->backupPrl(_return);
    return;
  }

   ::Uts::ErrorCode::type restorePrl(const std::string& xqcnFileContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->restorePrl(xqcnFileContents);
    }
    return ifaces_[i]->restorePrl(xqcnFileContents);
  }

   ::Uts::ErrorCode::type sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendPrl(subscriptionId, index, prlFileContents);
    }
    return ifaces_[i]->sendPrl(subscriptionId, index, prlFileContents);
  }

   ::Uts::ErrorCode::type forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->forceEfsSync(pathName, efsSystem);
    }
    return ifaces_[i]->forceEfsSync(pathName, efsSystem);
  }

  int32_t getEsn() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getEsn();
    }
    return ifaces_[i]->getEsn();
  }

   ::Uts::ErrorCode::type setEsn(const int32_t esn) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setEsn(esn);
    }
    return ifaces_[i]->setEsn(esn);
  }

  void getImei(std::string& _return, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getImei(_return, subscriptionId);
    }
    ifaces_[i]->getImei(_return, subscriptionId);
    return;
  }

   ::Uts::ErrorCode::type setImei(const std::string& imei, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setImei(imei, subscriptionId);
    }
    return ifaces_[i]->setImei(imei, subscriptionId);
  }

  int64_t getMeid(const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getMeid(subscriptionId);
    }
    return ifaces_[i]->getMeid(subscriptionId);
  }

   ::Uts::ErrorCode::type setMeid(const int64_t meid, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setMeid(meid, subscriptionId);
    }
    return ifaces_[i]->setMeid(meid, subscriptionId);
  }

  bool checkSpc(const std::string& spc) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->checkSpc(spc);
    }
    return ifaces_[i]->checkSpc(spc);
  }

  bool provisionSpc(const std::string& currentSpc, const std::string& newSpc) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->provisionSpc(currentSpc, newSpc);
    }
    return ifaces_[i]->provisionSpc(currentSpc, newSpc);
  }

  void efsReadFromModemLog(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->efsReadFromModemLog(_return);
    }
    ifaces_[i]->efsReadFromModemLog(_return);
    return;
  }

   ::Uts::ErrorCode::type configureService(const DeviceConfigOptions& deviceConfigOptions) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->configureService(deviceConfigOptions);
    }
    return ifaces_[i]->configureService(deviceConfigOptions);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class DeviceConfigServiceConcurrentClient : virtual public DeviceConfigServiceIf {
 public:
  DeviceConfigServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  DeviceConfigServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getLastError( ::Uts::ErrorType& _return);
  int32_t send_getLastError();
  void recv_getLastError( ::Uts::ErrorType& _return, const int32_t seqid);
  int64_t getDevice();
  int32_t send_getDevice();
  int64_t recv_getDevice(const int32_t seqid);
   ::Uts::ErrorCode::type initializeService();
  int32_t send_initializeService();
   ::Uts::ErrorCode::type recv_initializeService(const int32_t seqid);
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle);
  int32_t send_initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle);
   ::Uts::ErrorCode::type recv_initializeServiceByProtocol(const int32_t seqid);
   ::Uts::ErrorCode::type initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions);
  int32_t send_initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions);
   ::Uts::ErrorCode::type recv_initializeServiceWithOptions(const int32_t seqid);
   ::Uts::ErrorCode::type destroyService();
  int32_t send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService(const int32_t seqid);
  void doXqcnOperation( ::Uts::DeviceConfigResp& _return, const DeviceConfigOptions& deviceConfigOptions);
  int32_t send_doXqcnOperation(const DeviceConfigOptions& deviceConfigOptions);
  void recv_doXqcnOperation( ::Uts::DeviceConfigResp& _return, const int32_t seqid);
  void backupToXqcn(std::string& _return, const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents);
  int32_t send_backupToXqcn(const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents);
  void recv_backupToXqcn(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents);
  int32_t send_restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents);
   ::Uts::ErrorCode::type recv_restoreFromXqcn(const int32_t seqid);
  int64_t pdcGetMbnMaxStorage(const PdcMbnType::type mbnType);
  int32_t send_pdcGetMbnMaxStorage(const PdcMbnType::type mbnType);
  int64_t recv_pdcGetMbnMaxStorage(const int32_t seqid);
  int64_t pdcGetMbnStorageUsage(const PdcMbnType::type mbnType);
  int32_t send_pdcGetMbnStorageUsage(const PdcMbnType::type mbnType);
  int64_t recv_pdcGetMbnStorageUsage(const int32_t seqid);
  int64_t pdcGetMbnCount(const PdcMbnType::type mbnType);
  int32_t send_pdcGetMbnCount(const PdcMbnType::type mbnType);
  int64_t recv_pdcGetMbnCount(const int32_t seqid);
  void pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const PdcMbnType::type mbnType);
  int32_t send_pdcGetMbnList(const PdcMbnType::type mbnType);
  void recv_pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const int32_t seqid);
  void pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const PdcMbnType::type mbnType);
  int32_t send_pdcGetDefaultMbnInfo(const PdcMbnType::type mbnType);
  void recv_pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const int32_t seqid);
  void pdcGetMbnId(std::string& _return, const std::string& mbnContent);
  int32_t send_pdcGetMbnId(const std::string& mbnContent);
  void recv_pdcGetMbnId(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent);
  int32_t send_pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent);
   ::Uts::ErrorCode::type recv_pdcWriteMbn(const int32_t seqid);
  void pdcReadMbn(std::string& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId);
  int32_t send_pdcReadMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId);
  void recv_pdcReadMbn(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId);
  int32_t send_pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId);
   ::Uts::ErrorCode::type recv_pdcRemoveMbn(const int32_t seqid);
  void pdcGetActiveMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId);
  int32_t send_pdcGetActiveMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId);
  void recv_pdcGetActiveMbn(std::string& _return, const int32_t seqid);
  void pdcGetPendingMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId);
  int32_t send_pdcGetPendingMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId);
  void recv_pdcGetPendingMbn(std::string& _return, const int32_t seqid);
  void pdcValidateMbn(PdcMbnResult& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath);
  int32_t send_pdcValidateMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath);
  void recv_pdcValidateMbn(PdcMbnResult& _return, const int32_t seqid);
   ::Uts::ErrorCode::type pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId);
  int32_t send_pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId);
   ::Uts::ErrorCode::type recv_pdcSelectMbn(const int32_t seqid);
   ::Uts::ErrorCode::type pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout);
  int32_t send_pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout);
   ::Uts::ErrorCode::type recv_pdcActivateMbn(const int32_t seqid);
   ::Uts::ErrorCode::type pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId);
  int32_t send_pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId);
   ::Uts::ErrorCode::type recv_pdcDeactivateMbn(const int32_t seqid);
  int32_t pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature);
  int32_t send_pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature);
  int32_t recv_pdcGetConfiguration(const int32_t seqid);
   ::Uts::ErrorCode::type pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value);
  int32_t send_pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value);
   ::Uts::ErrorCode::type recv_pdcSetConfiguration(const int32_t seqid);
  bool nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId);
  int32_t send_nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId);
  bool recv_nvIsItemSupported(const int32_t seqid);
  void nvReadItem(NvData& _return, const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig);
  int32_t send_nvReadItem(const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig);
  void recv_nvReadItem(NvData& _return, const int32_t seqid);
   ::Uts::ErrorCode::type nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId);
  int32_t send_nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_nvSetItem(const int32_t seqid);
   ::Uts::ErrorCode::type nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId);
  int32_t send_nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_nvSetOtpItem(const int32_t seqid);
  void nvGetAllItems(std::vector< ::Uts::NvItem> & _return);
  int32_t send_nvGetAllItems();
  void recv_nvGetAllItems(std::vector< ::Uts::NvItem> & _return, const int32_t seqid);
  void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId);
  int32_t send_nvGetItemDefinition(const std::string& nvItemNameOrId);
  void recv_nvGetItemDefinition(std::string& _return, const int32_t seqid);
  bool efsHasAlternateFileSystem();
  int32_t send_efsHasAlternateFileSystem();
  bool recv_efsHasAlternateFileSystem(const int32_t seqid);
   ::Uts::ErrorCode::type efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsCreateDirectory(const int32_t seqid);
   ::Uts::ErrorCode::type efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsRemoveDirectory(const int32_t seqid);
   ::Uts::ErrorCode::type efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem);
  int32_t send_efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem);
   ::Uts::ErrorCode::type recv_efsRemoveTree(const int32_t seqid);
  void efsGetDirectoryContents(std::vector<EfsItem> & _return, const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsGetDirectoryContents(const std::string& pathName, const FileSystem::type efsSystem);
  void recv_efsGetDirectoryContents(std::vector<EfsItem> & _return, const int32_t seqid);
   ::Uts::ErrorCode::type efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem);
  int32_t send_efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsPutFile(const int32_t seqid);
  void efsGetFile(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsGetFile(const std::string& pathName, const FileSystem::type efsSystem);
  void recv_efsGetFile(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsDeleteFile(const int32_t seqid);
   ::Uts::ErrorCode::type efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem);
  int32_t send_efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_efsRename(const int32_t seqid);
  bool efsPathExists(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsPathExists(const std::string& pathName, const FileSystem::type efsSystem);
  bool recv_efsPathExists(const int32_t seqid);
  bool efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem);
  bool recv_efsIsDirectory(const int32_t seqid);
  bool efsIsFile(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsIsFile(const std::string& pathName, const FileSystem::type efsSystem);
  bool recv_efsIsFile(const int32_t seqid);
  int64_t efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem);
  int64_t recv_efsGetFileSize(const int32_t seqid);
  int64_t efsGetAvailableSpace(const FileSystem::type efsSystem);
  int32_t send_efsGetAvailableSpace(const FileSystem::type efsSystem);
  int64_t recv_efsGetAvailableSpace(const int32_t seqid);
  void efsGetFileCheckSum(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsGetFileCheckSum(const std::string& pathName, const FileSystem::type efsSystem);
  void recv_efsGetFileCheckSum(std::string& _return, const int32_t seqid);
  void efsGetFileAttributes(EfsFileAttributes& _return, const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_efsGetFileAttributes(const std::string& pathName, const FileSystem::type efsSystem);
  void recv_efsGetFileAttributes(EfsFileAttributes& _return, const int32_t seqid);
  bool efsIsReady();
  int32_t send_efsIsReady();
  bool recv_efsIsReady(const int32_t seqid);
   ::Uts::ErrorCode::type createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_createGoldenCopy(const int32_t seqid);
   ::Uts::ErrorCode::type createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem);
  int32_t send_createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_createCefsCopy(const int32_t seqid);
  void requestPrl(std::string& _return, const int32_t subscriptionId, const int8_t index);
  int32_t send_requestPrl(const int32_t subscriptionId, const int8_t index);
  void recv_requestPrl(std::string& _return, const int32_t seqid);
  void backupPrl(std::string& _return);
  int32_t send_backupPrl();
  void recv_backupPrl(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type restorePrl(const std::string& xqcnFileContents);
  int32_t send_restorePrl(const std::string& xqcnFileContents);
   ::Uts::ErrorCode::type recv_restorePrl(const int32_t seqid);
   ::Uts::ErrorCode::type sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents);
  int32_t send_sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents);
   ::Uts::ErrorCode::type recv_sendPrl(const int32_t seqid);
   ::Uts::ErrorCode::type forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem);
  int32_t send_forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem);
   ::Uts::ErrorCode::type recv_forceEfsSync(const int32_t seqid);
  int32_t getEsn();
  int32_t send_getEsn();
  int32_t recv_getEsn(const int32_t seqid);
   ::Uts::ErrorCode::type setEsn(const int32_t esn);
  int32_t send_setEsn(const int32_t esn);
   ::Uts::ErrorCode::type recv_setEsn(const int32_t seqid);
  void getImei(std::string& _return, const int32_t subscriptionId);
  int32_t send_getImei(const int32_t subscriptionId);
  void recv_getImei(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type setImei(const std::string& imei, const int32_t subscriptionId);
  int32_t send_setImei(const std::string& imei, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_setImei(const int32_t seqid);
  int64_t getMeid(const int32_t subscriptionId);
  int32_t send_getMeid(const int32_t subscriptionId);
  int64_t recv_getMeid(const int32_t seqid);
   ::Uts::ErrorCode::type setMeid(const int64_t meid, const int32_t subscriptionId);
  int32_t send_setMeid(const int64_t meid, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_setMeid(const int32_t seqid);
  bool checkSpc(const std::string& spc);
  int32_t send_checkSpc(const std::string& spc);
  bool recv_checkSpc(const int32_t seqid);
  bool provisionSpc(const std::string& currentSpc, const std::string& newSpc);
  int32_t send_provisionSpc(const std::string& currentSpc, const std::string& newSpc);
  bool recv_provisionSpc(const int32_t seqid);
  void efsReadFromModemLog(std::string& _return);
  int32_t send_efsReadFromModemLog();
  void recv_efsReadFromModemLog(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type configureService(const DeviceConfigOptions& deviceConfigOptions);
  int32_t send_configureService(const DeviceConfigOptions& deviceConfigOptions);
   ::Uts::ErrorCode::type recv_configureService(const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
