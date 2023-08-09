/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef LogSession_H
#define LogSession_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "LogSession_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class LogSessionIf {
 public:
  virtual ~LogSessionIf() {}
  virtual void getLastError( ::Uts::ErrorType& _return) = 0;
  virtual  ::Uts::ErrorCode::type destroyLogSession() = 0;
  virtual void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return) = 0;
  virtual void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle) = 0;
  virtual int64_t getDataPacketCount(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type createDataView(const std::string& viewName, const DataPacketFilter& filter, const PacketReturnConfig& returnConfig) = 0;
  virtual  ::Uts::ErrorCode::type createDefaultDataView(const std::string& viewName, const std::vector<int64_t> & protocolHandleList, const PacketReturnConfig& returnConfig) = 0;
  virtual  ::Uts::ErrorCode::type createDataViewSet(const std::vector<DataViewInfo> & dataViewDefinitions) = 0;
  virtual  ::Uts::ErrorCode::type removeDataView(const std::string& viewName) = 0;
  virtual int32_t getDataViewItemCount(const std::string& viewName) = 0;
  virtual void getDataViewItems(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets) = 0;
  virtual  ::Uts::ErrorCode::type saveDataViewItemsByIndex(const std::string& viewName, const std::string& destinationFolder, const std::vector<int64_t> & dataViewIndexes) = 0;
  virtual  ::Uts::ErrorCode::type saveDataViewItemsByIndexWithFilenames(const std::string& viewName, const std::vector<int64_t> & dataViewIndexes, const std::map<int64_t, std::string> & logNamesByHandle) = 0;
  virtual void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder) = 0;
  virtual void getDurationByProtocol(std::string& _return, const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type updatePacketFilters(const std::string& viewName, const DataPacketFilter& filter, const ViewConfigurationUpdate::type updateType) = 0;
  virtual  ::Uts::ErrorCode::type updatePacketReturnConfig(const std::string& viewName, const PacketReturnConfig& returnConfig) = 0;
  virtual void getAvailablePacketIds(DataPacketFilter& _return, const int64_t protocolHandle) = 0;
  virtual void getLogSessionInformation(LogSessionInformation& _return, const std::set<int64_t> & protocolHandle) = 0;
  virtual void loadQShrinkFile(const int64_t protocolHandle, const std::string& pathName) = 0;
  virtual int64_t getDataViewItemIndex(const std::string& viewName, const int64_t sessionIndex) = 0;
  virtual int64_t getTimeStampTodAdjustedByDataviewIndexForAnnotations(const std::string& viewName, const int64_t dataviewIndex) = 0;
  virtual void getDataViewItemsForConfiguration(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets, const PacketReturnConfig& returnConfig) = 0;
  virtual void getClientSessionInfo(ClientSessionInfo& _return) = 0;
  virtual  ::Uts::ErrorCode::type createSubDataView(const std::string& viewName, const std::string& parentViewName, const DataPacketFilter& filter, const PacketRange& packets, const PacketReturnConfig& returnConfig) = 0;
  virtual  ::Uts::ErrorCode::type setWcdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::WcdmaProtocolRevision::type revision) = 0;
  virtual  ::Uts::ErrorCode::type setCdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::CdmaProtocolRevision::type revision) = 0;
  virtual  ::Uts::ErrorCode::type setPilotInc(const int64_t protocolHandle, const int16_t pilotInc) = 0;
  virtual int16_t getBandClass(const int64_t protocolHandle, const int64_t protocolIndex) = 0;
  virtual  ::Uts::CdmaProtocolRevision::type getCdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex) = 0;
  virtual int16_t getModel(const int64_t protocolHandle, const int64_t protocolIndex) = 0;
  virtual  ::Uts::WcdmaProtocolRevision::type getWcdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex) = 0;
  virtual void getDecryptionKeyStatus(std::vector< ::Uts::KeyInfo> & _return, const int64_t protocolHandle) = 0;
};

class LogSessionIfFactory {
 public:
  typedef LogSessionIf Handler;

  virtual ~LogSessionIfFactory() {}

  virtual LogSessionIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(LogSessionIf* /* handler */) = 0;
};

class LogSessionIfSingletonFactory : virtual public LogSessionIfFactory {
 public:
  LogSessionIfSingletonFactory(const ::std::shared_ptr<LogSessionIf>& iface) : iface_(iface) {}
  virtual ~LogSessionIfSingletonFactory() {}

  virtual LogSessionIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(LogSessionIf* /* handler */) {}

 protected:
  ::std::shared_ptr<LogSessionIf> iface_;
};

class LogSessionNull : virtual public LogSessionIf {
 public:
  virtual ~LogSessionNull() {}
  void getLastError( ::Uts::ErrorType& /* _return */) {
    return;
  }
   ::Uts::ErrorCode::type destroyLogSession() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getDeviceList(std::vector< ::Uts::DeviceInfo> & /* _return */) {
    return;
  }
  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & /* _return */, const int64_t /* deviceHandle */) {
    return;
  }
  int64_t getDataPacketCount(const int64_t /* protocolHandle */) {
    int64_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type createDataView(const std::string& /* viewName */, const DataPacketFilter& /* filter */, const PacketReturnConfig& /* returnConfig */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type createDefaultDataView(const std::string& /* viewName */, const std::vector<int64_t> & /* protocolHandleList */, const PacketReturnConfig& /* returnConfig */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type createDataViewSet(const std::vector<DataViewInfo> & /* dataViewDefinitions */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type removeDataView(const std::string& /* viewName */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  int32_t getDataViewItemCount(const std::string& /* viewName */) {
    int32_t _return = 0;
    return _return;
  }
  void getDataViewItems(std::vector<DataPacket> & /* _return */, const std::string& /* viewName */, const PacketRange& /* packets */) {
    return;
  }
   ::Uts::ErrorCode::type saveDataViewItemsByIndex(const std::string& /* viewName */, const std::string& /* destinationFolder */, const std::vector<int64_t> & /* dataViewIndexes */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type saveDataViewItemsByIndexWithFilenames(const std::string& /* viewName */, const std::vector<int64_t> & /* dataViewIndexes */, const std::map<int64_t, std::string> & /* logNamesByHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void saveLogFiles(std::vector<std::string> & /* _return */, const std::string& /* saveFolder */) {
    return;
  }
  void getDurationByProtocol(std::string& /* _return */, const int64_t /* protocolHandle */) {
    return;
  }
   ::Uts::ErrorCode::type updatePacketFilters(const std::string& /* viewName */, const DataPacketFilter& /* filter */, const ViewConfigurationUpdate::type /* updateType */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type updatePacketReturnConfig(const std::string& /* viewName */, const PacketReturnConfig& /* returnConfig */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getAvailablePacketIds(DataPacketFilter& /* _return */, const int64_t /* protocolHandle */) {
    return;
  }
  void getLogSessionInformation(LogSessionInformation& /* _return */, const std::set<int64_t> & /* protocolHandle */) {
    return;
  }
  void loadQShrinkFile(const int64_t /* protocolHandle */, const std::string& /* pathName */) {
    return;
  }
  int64_t getDataViewItemIndex(const std::string& /* viewName */, const int64_t /* sessionIndex */) {
    int64_t _return = 0;
    return _return;
  }
  int64_t getTimeStampTodAdjustedByDataviewIndexForAnnotations(const std::string& /* viewName */, const int64_t /* dataviewIndex */) {
    int64_t _return = 0;
    return _return;
  }
  void getDataViewItemsForConfiguration(std::vector<DataPacket> & /* _return */, const std::string& /* viewName */, const PacketRange& /* packets */, const PacketReturnConfig& /* returnConfig */) {
    return;
  }
  void getClientSessionInfo(ClientSessionInfo& /* _return */) {
    return;
  }
   ::Uts::ErrorCode::type createSubDataView(const std::string& /* viewName */, const std::string& /* parentViewName */, const DataPacketFilter& /* filter */, const PacketRange& /* packets */, const PacketReturnConfig& /* returnConfig */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const int64_t /* protocolHandle */, const  ::Uts::WcdmaProtocolRevision::type /* revision */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setCdmaProtocolRevision(const int64_t /* protocolHandle */, const  ::Uts::CdmaProtocolRevision::type /* revision */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setPilotInc(const int64_t /* protocolHandle */, const int16_t /* pilotInc */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  int16_t getBandClass(const int64_t /* protocolHandle */, const int64_t /* protocolIndex */) {
    int16_t _return = 0;
    return _return;
  }
   ::Uts::CdmaProtocolRevision::type getCdmaProtocolRevision(const int64_t /* protocolHandle */, const int64_t /* protocolIndex */) {
     ::Uts::CdmaProtocolRevision::type _return = ( ::Uts::CdmaProtocolRevision::type)0;
    return _return;
  }
  int16_t getModel(const int64_t /* protocolHandle */, const int64_t /* protocolIndex */) {
    int16_t _return = 0;
    return _return;
  }
   ::Uts::WcdmaProtocolRevision::type getWcdmaProtocolRevision(const int64_t /* protocolHandle */, const int64_t /* protocolIndex */) {
     ::Uts::WcdmaProtocolRevision::type _return = ( ::Uts::WcdmaProtocolRevision::type)0;
    return _return;
  }
  void getDecryptionKeyStatus(std::vector< ::Uts::KeyInfo> & /* _return */, const int64_t /* protocolHandle */) {
    return;
  }
};


class LogSession_getLastError_args {
 public:

  LogSession_getLastError_args(const LogSession_getLastError_args&);
  LogSession_getLastError_args& operator=(const LogSession_getLastError_args&);
  LogSession_getLastError_args() {
  }

  virtual ~LogSession_getLastError_args() noexcept;

  bool operator == (const LogSession_getLastError_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const LogSession_getLastError_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getLastError_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getLastError_pargs {
 public:


  virtual ~LogSession_getLastError_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getLastError_result__isset {
  _LogSession_getLastError_result__isset() : success(false) {}
  bool success :1;
} _LogSession_getLastError_result__isset;

class LogSession_getLastError_result {
 public:

  LogSession_getLastError_result(const LogSession_getLastError_result&);
  LogSession_getLastError_result& operator=(const LogSession_getLastError_result&);
  LogSession_getLastError_result() {
  }

  virtual ~LogSession_getLastError_result() noexcept;
   ::Uts::ErrorType success;

  _LogSession_getLastError_result__isset __isset;

  void __set_success(const  ::Uts::ErrorType& val);

  bool operator == (const LogSession_getLastError_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const LogSession_getLastError_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getLastError_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getLastError_presult__isset {
  _LogSession_getLastError_presult__isset() : success(false) {}
  bool success :1;
} _LogSession_getLastError_presult__isset;

class LogSession_getLastError_presult {
 public:


  virtual ~LogSession_getLastError_presult() noexcept;
   ::Uts::ErrorType* success;

  _LogSession_getLastError_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class LogSession_destroyLogSession_args {
 public:

  LogSession_destroyLogSession_args(const LogSession_destroyLogSession_args&);
  LogSession_destroyLogSession_args& operator=(const LogSession_destroyLogSession_args&);
  LogSession_destroyLogSession_args() {
  }

  virtual ~LogSession_destroyLogSession_args() noexcept;

  bool operator == (const LogSession_destroyLogSession_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const LogSession_destroyLogSession_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_destroyLogSession_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_destroyLogSession_pargs {
 public:


  virtual ~LogSession_destroyLogSession_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_destroyLogSession_result__isset {
  _LogSession_destroyLogSession_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_destroyLogSession_result__isset;

class LogSession_destroyLogSession_result {
 public:

  LogSession_destroyLogSession_result(const LogSession_destroyLogSession_result&);
  LogSession_destroyLogSession_result& operator=(const LogSession_destroyLogSession_result&);
  LogSession_destroyLogSession_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_destroyLogSession_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_destroyLogSession_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_destroyLogSession_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_destroyLogSession_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_destroyLogSession_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_destroyLogSession_presult__isset {
  _LogSession_destroyLogSession_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_destroyLogSession_presult__isset;

class LogSession_destroyLogSession_presult {
 public:


  virtual ~LogSession_destroyLogSession_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_destroyLogSession_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class LogSession_getDeviceList_args {
 public:

  LogSession_getDeviceList_args(const LogSession_getDeviceList_args&);
  LogSession_getDeviceList_args& operator=(const LogSession_getDeviceList_args&);
  LogSession_getDeviceList_args() {
  }

  virtual ~LogSession_getDeviceList_args() noexcept;

  bool operator == (const LogSession_getDeviceList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const LogSession_getDeviceList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDeviceList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getDeviceList_pargs {
 public:


  virtual ~LogSession_getDeviceList_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDeviceList_result__isset {
  _LogSession_getDeviceList_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDeviceList_result__isset;

class LogSession_getDeviceList_result {
 public:

  LogSession_getDeviceList_result(const LogSession_getDeviceList_result&);
  LogSession_getDeviceList_result& operator=(const LogSession_getDeviceList_result&);
  LogSession_getDeviceList_result() {
  }

  virtual ~LogSession_getDeviceList_result() noexcept;
  std::vector< ::Uts::DeviceInfo>  success;
   ::Uts::AppException e;

  _LogSession_getDeviceList_result__isset __isset;

  void __set_success(const std::vector< ::Uts::DeviceInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getDeviceList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDeviceList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDeviceList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDeviceList_presult__isset {
  _LogSession_getDeviceList_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDeviceList_presult__isset;

class LogSession_getDeviceList_presult {
 public:


  virtual ~LogSession_getDeviceList_presult() noexcept;
  std::vector< ::Uts::DeviceInfo> * success;
   ::Uts::AppException e;

  _LogSession_getDeviceList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getProtocolList_args__isset {
  _LogSession_getProtocolList_args__isset() : deviceHandle(false) {}
  bool deviceHandle :1;
} _LogSession_getProtocolList_args__isset;

class LogSession_getProtocolList_args {
 public:

  LogSession_getProtocolList_args(const LogSession_getProtocolList_args&);
  LogSession_getProtocolList_args& operator=(const LogSession_getProtocolList_args&);
  LogSession_getProtocolList_args() : deviceHandle(0) {
  }

  virtual ~LogSession_getProtocolList_args() noexcept;
  int64_t deviceHandle;

  _LogSession_getProtocolList_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  bool operator == (const LogSession_getProtocolList_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const LogSession_getProtocolList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getProtocolList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getProtocolList_pargs {
 public:


  virtual ~LogSession_getProtocolList_pargs() noexcept;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getProtocolList_result__isset {
  _LogSession_getProtocolList_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getProtocolList_result__isset;

class LogSession_getProtocolList_result {
 public:

  LogSession_getProtocolList_result(const LogSession_getProtocolList_result&);
  LogSession_getProtocolList_result& operator=(const LogSession_getProtocolList_result&);
  LogSession_getProtocolList_result() {
  }

  virtual ~LogSession_getProtocolList_result() noexcept;
  std::vector< ::Uts::ProtocolInfo>  success;
   ::Uts::AppException e;

  _LogSession_getProtocolList_result__isset __isset;

  void __set_success(const std::vector< ::Uts::ProtocolInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getProtocolList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getProtocolList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getProtocolList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getProtocolList_presult__isset {
  _LogSession_getProtocolList_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getProtocolList_presult__isset;

class LogSession_getProtocolList_presult {
 public:


  virtual ~LogSession_getProtocolList_presult() noexcept;
  std::vector< ::Uts::ProtocolInfo> * success;
   ::Uts::AppException e;

  _LogSession_getProtocolList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getDataPacketCount_args__isset {
  _LogSession_getDataPacketCount_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _LogSession_getDataPacketCount_args__isset;

class LogSession_getDataPacketCount_args {
 public:

  LogSession_getDataPacketCount_args(const LogSession_getDataPacketCount_args&);
  LogSession_getDataPacketCount_args& operator=(const LogSession_getDataPacketCount_args&);
  LogSession_getDataPacketCount_args() : protocolHandle(0) {
  }

  virtual ~LogSession_getDataPacketCount_args() noexcept;
  int64_t protocolHandle;

  _LogSession_getDataPacketCount_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const LogSession_getDataPacketCount_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataPacketCount_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataPacketCount_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getDataPacketCount_pargs {
 public:


  virtual ~LogSession_getDataPacketCount_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataPacketCount_result__isset {
  _LogSession_getDataPacketCount_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataPacketCount_result__isset;

class LogSession_getDataPacketCount_result {
 public:

  LogSession_getDataPacketCount_result(const LogSession_getDataPacketCount_result&);
  LogSession_getDataPacketCount_result& operator=(const LogSession_getDataPacketCount_result&);
  LogSession_getDataPacketCount_result() : success(0) {
  }

  virtual ~LogSession_getDataPacketCount_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _LogSession_getDataPacketCount_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getDataPacketCount_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataPacketCount_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataPacketCount_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataPacketCount_presult__isset {
  _LogSession_getDataPacketCount_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataPacketCount_presult__isset;

class LogSession_getDataPacketCount_presult {
 public:


  virtual ~LogSession_getDataPacketCount_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _LogSession_getDataPacketCount_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_createDataView_args__isset {
  _LogSession_createDataView_args__isset() : viewName(false), filter(false), returnConfig(false) {}
  bool viewName :1;
  bool filter :1;
  bool returnConfig :1;
} _LogSession_createDataView_args__isset;

class LogSession_createDataView_args {
 public:

  LogSession_createDataView_args(const LogSession_createDataView_args&);
  LogSession_createDataView_args& operator=(const LogSession_createDataView_args&);
  LogSession_createDataView_args() : viewName() {
  }

  virtual ~LogSession_createDataView_args() noexcept;
  std::string viewName;
  DataPacketFilter filter;
  PacketReturnConfig returnConfig;

  _LogSession_createDataView_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_filter(const DataPacketFilter& val);

  void __set_returnConfig(const PacketReturnConfig& val);

  bool operator == (const LogSession_createDataView_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(filter == rhs.filter))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const LogSession_createDataView_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_createDataView_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_createDataView_pargs {
 public:


  virtual ~LogSession_createDataView_pargs() noexcept;
  const std::string* viewName;
  const DataPacketFilter* filter;
  const PacketReturnConfig* returnConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_createDataView_result__isset {
  _LogSession_createDataView_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_createDataView_result__isset;

class LogSession_createDataView_result {
 public:

  LogSession_createDataView_result(const LogSession_createDataView_result&);
  LogSession_createDataView_result& operator=(const LogSession_createDataView_result&);
  LogSession_createDataView_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_createDataView_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_createDataView_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_createDataView_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_createDataView_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_createDataView_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_createDataView_presult__isset {
  _LogSession_createDataView_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_createDataView_presult__isset;

class LogSession_createDataView_presult {
 public:


  virtual ~LogSession_createDataView_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_createDataView_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_createDefaultDataView_args__isset {
  _LogSession_createDefaultDataView_args__isset() : viewName(false), protocolHandleList(false), returnConfig(false) {}
  bool viewName :1;
  bool protocolHandleList :1;
  bool returnConfig :1;
} _LogSession_createDefaultDataView_args__isset;

class LogSession_createDefaultDataView_args {
 public:

  LogSession_createDefaultDataView_args(const LogSession_createDefaultDataView_args&);
  LogSession_createDefaultDataView_args& operator=(const LogSession_createDefaultDataView_args&);
  LogSession_createDefaultDataView_args() : viewName() {
  }

  virtual ~LogSession_createDefaultDataView_args() noexcept;
  std::string viewName;
  std::vector<int64_t>  protocolHandleList;
  PacketReturnConfig returnConfig;

  _LogSession_createDefaultDataView_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_protocolHandleList(const std::vector<int64_t> & val);

  void __set_returnConfig(const PacketReturnConfig& val);

  bool operator == (const LogSession_createDefaultDataView_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(protocolHandleList == rhs.protocolHandleList))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const LogSession_createDefaultDataView_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_createDefaultDataView_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_createDefaultDataView_pargs {
 public:


  virtual ~LogSession_createDefaultDataView_pargs() noexcept;
  const std::string* viewName;
  const std::vector<int64_t> * protocolHandleList;
  const PacketReturnConfig* returnConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_createDefaultDataView_result__isset {
  _LogSession_createDefaultDataView_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_createDefaultDataView_result__isset;

class LogSession_createDefaultDataView_result {
 public:

  LogSession_createDefaultDataView_result(const LogSession_createDefaultDataView_result&);
  LogSession_createDefaultDataView_result& operator=(const LogSession_createDefaultDataView_result&);
  LogSession_createDefaultDataView_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_createDefaultDataView_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_createDefaultDataView_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_createDefaultDataView_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_createDefaultDataView_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_createDefaultDataView_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_createDefaultDataView_presult__isset {
  _LogSession_createDefaultDataView_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_createDefaultDataView_presult__isset;

class LogSession_createDefaultDataView_presult {
 public:


  virtual ~LogSession_createDefaultDataView_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_createDefaultDataView_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_createDataViewSet_args__isset {
  _LogSession_createDataViewSet_args__isset() : dataViewDefinitions(false) {}
  bool dataViewDefinitions :1;
} _LogSession_createDataViewSet_args__isset;

class LogSession_createDataViewSet_args {
 public:

  LogSession_createDataViewSet_args(const LogSession_createDataViewSet_args&);
  LogSession_createDataViewSet_args& operator=(const LogSession_createDataViewSet_args&);
  LogSession_createDataViewSet_args() {
  }

  virtual ~LogSession_createDataViewSet_args() noexcept;
  std::vector<DataViewInfo>  dataViewDefinitions;

  _LogSession_createDataViewSet_args__isset __isset;

  void __set_dataViewDefinitions(const std::vector<DataViewInfo> & val);

  bool operator == (const LogSession_createDataViewSet_args & rhs) const
  {
    if (!(dataViewDefinitions == rhs.dataViewDefinitions))
      return false;
    return true;
  }
  bool operator != (const LogSession_createDataViewSet_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_createDataViewSet_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_createDataViewSet_pargs {
 public:


  virtual ~LogSession_createDataViewSet_pargs() noexcept;
  const std::vector<DataViewInfo> * dataViewDefinitions;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_createDataViewSet_result__isset {
  _LogSession_createDataViewSet_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_createDataViewSet_result__isset;

class LogSession_createDataViewSet_result {
 public:

  LogSession_createDataViewSet_result(const LogSession_createDataViewSet_result&);
  LogSession_createDataViewSet_result& operator=(const LogSession_createDataViewSet_result&);
  LogSession_createDataViewSet_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_createDataViewSet_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_createDataViewSet_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_createDataViewSet_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_createDataViewSet_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_createDataViewSet_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_createDataViewSet_presult__isset {
  _LogSession_createDataViewSet_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_createDataViewSet_presult__isset;

class LogSession_createDataViewSet_presult {
 public:


  virtual ~LogSession_createDataViewSet_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_createDataViewSet_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_removeDataView_args__isset {
  _LogSession_removeDataView_args__isset() : viewName(false) {}
  bool viewName :1;
} _LogSession_removeDataView_args__isset;

class LogSession_removeDataView_args {
 public:

  LogSession_removeDataView_args(const LogSession_removeDataView_args&);
  LogSession_removeDataView_args& operator=(const LogSession_removeDataView_args&);
  LogSession_removeDataView_args() : viewName() {
  }

  virtual ~LogSession_removeDataView_args() noexcept;
  std::string viewName;

  _LogSession_removeDataView_args__isset __isset;

  void __set_viewName(const std::string& val);

  bool operator == (const LogSession_removeDataView_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    return true;
  }
  bool operator != (const LogSession_removeDataView_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_removeDataView_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_removeDataView_pargs {
 public:


  virtual ~LogSession_removeDataView_pargs() noexcept;
  const std::string* viewName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_removeDataView_result__isset {
  _LogSession_removeDataView_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_removeDataView_result__isset;

class LogSession_removeDataView_result {
 public:

  LogSession_removeDataView_result(const LogSession_removeDataView_result&);
  LogSession_removeDataView_result& operator=(const LogSession_removeDataView_result&);
  LogSession_removeDataView_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_removeDataView_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_removeDataView_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_removeDataView_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_removeDataView_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_removeDataView_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_removeDataView_presult__isset {
  _LogSession_removeDataView_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_removeDataView_presult__isset;

class LogSession_removeDataView_presult {
 public:


  virtual ~LogSession_removeDataView_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_removeDataView_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getDataViewItemCount_args__isset {
  _LogSession_getDataViewItemCount_args__isset() : viewName(false) {}
  bool viewName :1;
} _LogSession_getDataViewItemCount_args__isset;

class LogSession_getDataViewItemCount_args {
 public:

  LogSession_getDataViewItemCount_args(const LogSession_getDataViewItemCount_args&);
  LogSession_getDataViewItemCount_args& operator=(const LogSession_getDataViewItemCount_args&);
  LogSession_getDataViewItemCount_args() : viewName() {
  }

  virtual ~LogSession_getDataViewItemCount_args() noexcept;
  std::string viewName;

  _LogSession_getDataViewItemCount_args__isset __isset;

  void __set_viewName(const std::string& val);

  bool operator == (const LogSession_getDataViewItemCount_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataViewItemCount_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataViewItemCount_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getDataViewItemCount_pargs {
 public:


  virtual ~LogSession_getDataViewItemCount_pargs() noexcept;
  const std::string* viewName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataViewItemCount_result__isset {
  _LogSession_getDataViewItemCount_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataViewItemCount_result__isset;

class LogSession_getDataViewItemCount_result {
 public:

  LogSession_getDataViewItemCount_result(const LogSession_getDataViewItemCount_result&);
  LogSession_getDataViewItemCount_result& operator=(const LogSession_getDataViewItemCount_result&);
  LogSession_getDataViewItemCount_result() : success(0) {
  }

  virtual ~LogSession_getDataViewItemCount_result() noexcept;
  int32_t success;
   ::Uts::AppException e;

  _LogSession_getDataViewItemCount_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getDataViewItemCount_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataViewItemCount_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataViewItemCount_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataViewItemCount_presult__isset {
  _LogSession_getDataViewItemCount_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataViewItemCount_presult__isset;

class LogSession_getDataViewItemCount_presult {
 public:


  virtual ~LogSession_getDataViewItemCount_presult() noexcept;
  int32_t* success;
   ::Uts::AppException e;

  _LogSession_getDataViewItemCount_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getDataViewItems_args__isset {
  _LogSession_getDataViewItems_args__isset() : viewName(false), packets(false) {}
  bool viewName :1;
  bool packets :1;
} _LogSession_getDataViewItems_args__isset;

class LogSession_getDataViewItems_args {
 public:

  LogSession_getDataViewItems_args(const LogSession_getDataViewItems_args&);
  LogSession_getDataViewItems_args& operator=(const LogSession_getDataViewItems_args&);
  LogSession_getDataViewItems_args() : viewName() {
  }

  virtual ~LogSession_getDataViewItems_args() noexcept;
  std::string viewName;
  PacketRange packets;

  _LogSession_getDataViewItems_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_packets(const PacketRange& val);

  bool operator == (const LogSession_getDataViewItems_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(packets == rhs.packets))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataViewItems_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataViewItems_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getDataViewItems_pargs {
 public:


  virtual ~LogSession_getDataViewItems_pargs() noexcept;
  const std::string* viewName;
  const PacketRange* packets;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataViewItems_result__isset {
  _LogSession_getDataViewItems_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataViewItems_result__isset;

class LogSession_getDataViewItems_result {
 public:

  LogSession_getDataViewItems_result(const LogSession_getDataViewItems_result&);
  LogSession_getDataViewItems_result& operator=(const LogSession_getDataViewItems_result&);
  LogSession_getDataViewItems_result() {
  }

  virtual ~LogSession_getDataViewItems_result() noexcept;
  std::vector<DataPacket>  success;
   ::Uts::AppException e;

  _LogSession_getDataViewItems_result__isset __isset;

  void __set_success(const std::vector<DataPacket> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getDataViewItems_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataViewItems_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataViewItems_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataViewItems_presult__isset {
  _LogSession_getDataViewItems_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataViewItems_presult__isset;

class LogSession_getDataViewItems_presult {
 public:


  virtual ~LogSession_getDataViewItems_presult() noexcept;
  std::vector<DataPacket> * success;
   ::Uts::AppException e;

  _LogSession_getDataViewItems_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_saveDataViewItemsByIndex_args__isset {
  _LogSession_saveDataViewItemsByIndex_args__isset() : viewName(false), destinationFolder(false), dataViewIndexes(false) {}
  bool viewName :1;
  bool destinationFolder :1;
  bool dataViewIndexes :1;
} _LogSession_saveDataViewItemsByIndex_args__isset;

class LogSession_saveDataViewItemsByIndex_args {
 public:

  LogSession_saveDataViewItemsByIndex_args(const LogSession_saveDataViewItemsByIndex_args&);
  LogSession_saveDataViewItemsByIndex_args& operator=(const LogSession_saveDataViewItemsByIndex_args&);
  LogSession_saveDataViewItemsByIndex_args() : viewName(), destinationFolder() {
  }

  virtual ~LogSession_saveDataViewItemsByIndex_args() noexcept;
  std::string viewName;
  std::string destinationFolder;
  std::vector<int64_t>  dataViewIndexes;

  _LogSession_saveDataViewItemsByIndex_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_destinationFolder(const std::string& val);

  void __set_dataViewIndexes(const std::vector<int64_t> & val);

  bool operator == (const LogSession_saveDataViewItemsByIndex_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(destinationFolder == rhs.destinationFolder))
      return false;
    if (!(dataViewIndexes == rhs.dataViewIndexes))
      return false;
    return true;
  }
  bool operator != (const LogSession_saveDataViewItemsByIndex_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_saveDataViewItemsByIndex_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_saveDataViewItemsByIndex_pargs {
 public:


  virtual ~LogSession_saveDataViewItemsByIndex_pargs() noexcept;
  const std::string* viewName;
  const std::string* destinationFolder;
  const std::vector<int64_t> * dataViewIndexes;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_saveDataViewItemsByIndex_result__isset {
  _LogSession_saveDataViewItemsByIndex_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_saveDataViewItemsByIndex_result__isset;

class LogSession_saveDataViewItemsByIndex_result {
 public:

  LogSession_saveDataViewItemsByIndex_result(const LogSession_saveDataViewItemsByIndex_result&);
  LogSession_saveDataViewItemsByIndex_result& operator=(const LogSession_saveDataViewItemsByIndex_result&);
  LogSession_saveDataViewItemsByIndex_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_saveDataViewItemsByIndex_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_saveDataViewItemsByIndex_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_saveDataViewItemsByIndex_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_saveDataViewItemsByIndex_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_saveDataViewItemsByIndex_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_saveDataViewItemsByIndex_presult__isset {
  _LogSession_saveDataViewItemsByIndex_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_saveDataViewItemsByIndex_presult__isset;

class LogSession_saveDataViewItemsByIndex_presult {
 public:


  virtual ~LogSession_saveDataViewItemsByIndex_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_saveDataViewItemsByIndex_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_saveDataViewItemsByIndexWithFilenames_args__isset {
  _LogSession_saveDataViewItemsByIndexWithFilenames_args__isset() : viewName(false), dataViewIndexes(false), logNamesByHandle(false) {}
  bool viewName :1;
  bool dataViewIndexes :1;
  bool logNamesByHandle :1;
} _LogSession_saveDataViewItemsByIndexWithFilenames_args__isset;

class LogSession_saveDataViewItemsByIndexWithFilenames_args {
 public:

  LogSession_saveDataViewItemsByIndexWithFilenames_args(const LogSession_saveDataViewItemsByIndexWithFilenames_args&);
  LogSession_saveDataViewItemsByIndexWithFilenames_args& operator=(const LogSession_saveDataViewItemsByIndexWithFilenames_args&);
  LogSession_saveDataViewItemsByIndexWithFilenames_args() : viewName() {
  }

  virtual ~LogSession_saveDataViewItemsByIndexWithFilenames_args() noexcept;
  std::string viewName;
  std::vector<int64_t>  dataViewIndexes;
  std::map<int64_t, std::string>  logNamesByHandle;

  _LogSession_saveDataViewItemsByIndexWithFilenames_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_dataViewIndexes(const std::vector<int64_t> & val);

  void __set_logNamesByHandle(const std::map<int64_t, std::string> & val);

  bool operator == (const LogSession_saveDataViewItemsByIndexWithFilenames_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(dataViewIndexes == rhs.dataViewIndexes))
      return false;
    if (!(logNamesByHandle == rhs.logNamesByHandle))
      return false;
    return true;
  }
  bool operator != (const LogSession_saveDataViewItemsByIndexWithFilenames_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_saveDataViewItemsByIndexWithFilenames_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_saveDataViewItemsByIndexWithFilenames_pargs {
 public:


  virtual ~LogSession_saveDataViewItemsByIndexWithFilenames_pargs() noexcept;
  const std::string* viewName;
  const std::vector<int64_t> * dataViewIndexes;
  const std::map<int64_t, std::string> * logNamesByHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_saveDataViewItemsByIndexWithFilenames_result__isset {
  _LogSession_saveDataViewItemsByIndexWithFilenames_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_saveDataViewItemsByIndexWithFilenames_result__isset;

class LogSession_saveDataViewItemsByIndexWithFilenames_result {
 public:

  LogSession_saveDataViewItemsByIndexWithFilenames_result(const LogSession_saveDataViewItemsByIndexWithFilenames_result&);
  LogSession_saveDataViewItemsByIndexWithFilenames_result& operator=(const LogSession_saveDataViewItemsByIndexWithFilenames_result&);
  LogSession_saveDataViewItemsByIndexWithFilenames_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_saveDataViewItemsByIndexWithFilenames_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_saveDataViewItemsByIndexWithFilenames_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_saveDataViewItemsByIndexWithFilenames_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_saveDataViewItemsByIndexWithFilenames_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_saveDataViewItemsByIndexWithFilenames_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_saveDataViewItemsByIndexWithFilenames_presult__isset {
  _LogSession_saveDataViewItemsByIndexWithFilenames_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_saveDataViewItemsByIndexWithFilenames_presult__isset;

class LogSession_saveDataViewItemsByIndexWithFilenames_presult {
 public:


  virtual ~LogSession_saveDataViewItemsByIndexWithFilenames_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_saveDataViewItemsByIndexWithFilenames_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_saveLogFiles_args__isset {
  _LogSession_saveLogFiles_args__isset() : saveFolder(false) {}
  bool saveFolder :1;
} _LogSession_saveLogFiles_args__isset;

class LogSession_saveLogFiles_args {
 public:

  LogSession_saveLogFiles_args(const LogSession_saveLogFiles_args&);
  LogSession_saveLogFiles_args& operator=(const LogSession_saveLogFiles_args&);
  LogSession_saveLogFiles_args() : saveFolder() {
  }

  virtual ~LogSession_saveLogFiles_args() noexcept;
  std::string saveFolder;

  _LogSession_saveLogFiles_args__isset __isset;

  void __set_saveFolder(const std::string& val);

  bool operator == (const LogSession_saveLogFiles_args & rhs) const
  {
    if (!(saveFolder == rhs.saveFolder))
      return false;
    return true;
  }
  bool operator != (const LogSession_saveLogFiles_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_saveLogFiles_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_saveLogFiles_pargs {
 public:


  virtual ~LogSession_saveLogFiles_pargs() noexcept;
  const std::string* saveFolder;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_saveLogFiles_result__isset {
  _LogSession_saveLogFiles_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_saveLogFiles_result__isset;

class LogSession_saveLogFiles_result {
 public:

  LogSession_saveLogFiles_result(const LogSession_saveLogFiles_result&);
  LogSession_saveLogFiles_result& operator=(const LogSession_saveLogFiles_result&);
  LogSession_saveLogFiles_result() {
  }

  virtual ~LogSession_saveLogFiles_result() noexcept;
  std::vector<std::string>  success;
   ::Uts::AppException e;

  _LogSession_saveLogFiles_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_saveLogFiles_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_saveLogFiles_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_saveLogFiles_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_saveLogFiles_presult__isset {
  _LogSession_saveLogFiles_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_saveLogFiles_presult__isset;

class LogSession_saveLogFiles_presult {
 public:


  virtual ~LogSession_saveLogFiles_presult() noexcept;
  std::vector<std::string> * success;
   ::Uts::AppException e;

  _LogSession_saveLogFiles_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getDurationByProtocol_args__isset {
  _LogSession_getDurationByProtocol_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _LogSession_getDurationByProtocol_args__isset;

class LogSession_getDurationByProtocol_args {
 public:

  LogSession_getDurationByProtocol_args(const LogSession_getDurationByProtocol_args&);
  LogSession_getDurationByProtocol_args& operator=(const LogSession_getDurationByProtocol_args&);
  LogSession_getDurationByProtocol_args() : protocolHandle(0) {
  }

  virtual ~LogSession_getDurationByProtocol_args() noexcept;
  int64_t protocolHandle;

  _LogSession_getDurationByProtocol_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const LogSession_getDurationByProtocol_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDurationByProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDurationByProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getDurationByProtocol_pargs {
 public:


  virtual ~LogSession_getDurationByProtocol_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDurationByProtocol_result__isset {
  _LogSession_getDurationByProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDurationByProtocol_result__isset;

class LogSession_getDurationByProtocol_result {
 public:

  LogSession_getDurationByProtocol_result(const LogSession_getDurationByProtocol_result&);
  LogSession_getDurationByProtocol_result& operator=(const LogSession_getDurationByProtocol_result&);
  LogSession_getDurationByProtocol_result() : success() {
  }

  virtual ~LogSession_getDurationByProtocol_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _LogSession_getDurationByProtocol_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getDurationByProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDurationByProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDurationByProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDurationByProtocol_presult__isset {
  _LogSession_getDurationByProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDurationByProtocol_presult__isset;

class LogSession_getDurationByProtocol_presult {
 public:


  virtual ~LogSession_getDurationByProtocol_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _LogSession_getDurationByProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_updatePacketFilters_args__isset {
  _LogSession_updatePacketFilters_args__isset() : viewName(false), filter(false), updateType(false) {}
  bool viewName :1;
  bool filter :1;
  bool updateType :1;
} _LogSession_updatePacketFilters_args__isset;

class LogSession_updatePacketFilters_args {
 public:

  LogSession_updatePacketFilters_args(const LogSession_updatePacketFilters_args&);
  LogSession_updatePacketFilters_args& operator=(const LogSession_updatePacketFilters_args&);
  LogSession_updatePacketFilters_args() : viewName(), updateType((ViewConfigurationUpdate::type)0) {
  }

  virtual ~LogSession_updatePacketFilters_args() noexcept;
  std::string viewName;
  DataPacketFilter filter;
  ViewConfigurationUpdate::type updateType;

  _LogSession_updatePacketFilters_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_filter(const DataPacketFilter& val);

  void __set_updateType(const ViewConfigurationUpdate::type val);

  bool operator == (const LogSession_updatePacketFilters_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(filter == rhs.filter))
      return false;
    if (!(updateType == rhs.updateType))
      return false;
    return true;
  }
  bool operator != (const LogSession_updatePacketFilters_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_updatePacketFilters_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_updatePacketFilters_pargs {
 public:


  virtual ~LogSession_updatePacketFilters_pargs() noexcept;
  const std::string* viewName;
  const DataPacketFilter* filter;
  const ViewConfigurationUpdate::type* updateType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_updatePacketFilters_result__isset {
  _LogSession_updatePacketFilters_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_updatePacketFilters_result__isset;

class LogSession_updatePacketFilters_result {
 public:

  LogSession_updatePacketFilters_result(const LogSession_updatePacketFilters_result&);
  LogSession_updatePacketFilters_result& operator=(const LogSession_updatePacketFilters_result&);
  LogSession_updatePacketFilters_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_updatePacketFilters_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_updatePacketFilters_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_updatePacketFilters_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_updatePacketFilters_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_updatePacketFilters_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_updatePacketFilters_presult__isset {
  _LogSession_updatePacketFilters_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_updatePacketFilters_presult__isset;

class LogSession_updatePacketFilters_presult {
 public:


  virtual ~LogSession_updatePacketFilters_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_updatePacketFilters_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_updatePacketReturnConfig_args__isset {
  _LogSession_updatePacketReturnConfig_args__isset() : viewName(false), returnConfig(false) {}
  bool viewName :1;
  bool returnConfig :1;
} _LogSession_updatePacketReturnConfig_args__isset;

class LogSession_updatePacketReturnConfig_args {
 public:

  LogSession_updatePacketReturnConfig_args(const LogSession_updatePacketReturnConfig_args&);
  LogSession_updatePacketReturnConfig_args& operator=(const LogSession_updatePacketReturnConfig_args&);
  LogSession_updatePacketReturnConfig_args() : viewName() {
  }

  virtual ~LogSession_updatePacketReturnConfig_args() noexcept;
  std::string viewName;
  PacketReturnConfig returnConfig;

  _LogSession_updatePacketReturnConfig_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_returnConfig(const PacketReturnConfig& val);

  bool operator == (const LogSession_updatePacketReturnConfig_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const LogSession_updatePacketReturnConfig_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_updatePacketReturnConfig_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_updatePacketReturnConfig_pargs {
 public:


  virtual ~LogSession_updatePacketReturnConfig_pargs() noexcept;
  const std::string* viewName;
  const PacketReturnConfig* returnConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_updatePacketReturnConfig_result__isset {
  _LogSession_updatePacketReturnConfig_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_updatePacketReturnConfig_result__isset;

class LogSession_updatePacketReturnConfig_result {
 public:

  LogSession_updatePacketReturnConfig_result(const LogSession_updatePacketReturnConfig_result&);
  LogSession_updatePacketReturnConfig_result& operator=(const LogSession_updatePacketReturnConfig_result&);
  LogSession_updatePacketReturnConfig_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_updatePacketReturnConfig_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_updatePacketReturnConfig_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_updatePacketReturnConfig_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_updatePacketReturnConfig_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_updatePacketReturnConfig_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_updatePacketReturnConfig_presult__isset {
  _LogSession_updatePacketReturnConfig_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_updatePacketReturnConfig_presult__isset;

class LogSession_updatePacketReturnConfig_presult {
 public:


  virtual ~LogSession_updatePacketReturnConfig_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_updatePacketReturnConfig_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getAvailablePacketIds_args__isset {
  _LogSession_getAvailablePacketIds_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _LogSession_getAvailablePacketIds_args__isset;

class LogSession_getAvailablePacketIds_args {
 public:

  LogSession_getAvailablePacketIds_args(const LogSession_getAvailablePacketIds_args&);
  LogSession_getAvailablePacketIds_args& operator=(const LogSession_getAvailablePacketIds_args&);
  LogSession_getAvailablePacketIds_args() : protocolHandle(0) {
  }

  virtual ~LogSession_getAvailablePacketIds_args() noexcept;
  int64_t protocolHandle;

  _LogSession_getAvailablePacketIds_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const LogSession_getAvailablePacketIds_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const LogSession_getAvailablePacketIds_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getAvailablePacketIds_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getAvailablePacketIds_pargs {
 public:


  virtual ~LogSession_getAvailablePacketIds_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getAvailablePacketIds_result__isset {
  _LogSession_getAvailablePacketIds_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getAvailablePacketIds_result__isset;

class LogSession_getAvailablePacketIds_result {
 public:

  LogSession_getAvailablePacketIds_result(const LogSession_getAvailablePacketIds_result&);
  LogSession_getAvailablePacketIds_result& operator=(const LogSession_getAvailablePacketIds_result&);
  LogSession_getAvailablePacketIds_result() {
  }

  virtual ~LogSession_getAvailablePacketIds_result() noexcept;
  DataPacketFilter success;
   ::Uts::AppException e;

  _LogSession_getAvailablePacketIds_result__isset __isset;

  void __set_success(const DataPacketFilter& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getAvailablePacketIds_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getAvailablePacketIds_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getAvailablePacketIds_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getAvailablePacketIds_presult__isset {
  _LogSession_getAvailablePacketIds_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getAvailablePacketIds_presult__isset;

class LogSession_getAvailablePacketIds_presult {
 public:


  virtual ~LogSession_getAvailablePacketIds_presult() noexcept;
  DataPacketFilter* success;
   ::Uts::AppException e;

  _LogSession_getAvailablePacketIds_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getLogSessionInformation_args__isset {
  _LogSession_getLogSessionInformation_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _LogSession_getLogSessionInformation_args__isset;

class LogSession_getLogSessionInformation_args {
 public:

  LogSession_getLogSessionInformation_args(const LogSession_getLogSessionInformation_args&);
  LogSession_getLogSessionInformation_args& operator=(const LogSession_getLogSessionInformation_args&);
  LogSession_getLogSessionInformation_args() {
  }

  virtual ~LogSession_getLogSessionInformation_args() noexcept;
  std::set<int64_t>  protocolHandle;

  _LogSession_getLogSessionInformation_args__isset __isset;

  void __set_protocolHandle(const std::set<int64_t> & val);

  bool operator == (const LogSession_getLogSessionInformation_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const LogSession_getLogSessionInformation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getLogSessionInformation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getLogSessionInformation_pargs {
 public:


  virtual ~LogSession_getLogSessionInformation_pargs() noexcept;
  const std::set<int64_t> * protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getLogSessionInformation_result__isset {
  _LogSession_getLogSessionInformation_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getLogSessionInformation_result__isset;

class LogSession_getLogSessionInformation_result {
 public:

  LogSession_getLogSessionInformation_result(const LogSession_getLogSessionInformation_result&);
  LogSession_getLogSessionInformation_result& operator=(const LogSession_getLogSessionInformation_result&);
  LogSession_getLogSessionInformation_result() {
  }

  virtual ~LogSession_getLogSessionInformation_result() noexcept;
  LogSessionInformation success;
   ::Uts::AppException e;

  _LogSession_getLogSessionInformation_result__isset __isset;

  void __set_success(const LogSessionInformation& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getLogSessionInformation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getLogSessionInformation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getLogSessionInformation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getLogSessionInformation_presult__isset {
  _LogSession_getLogSessionInformation_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getLogSessionInformation_presult__isset;

class LogSession_getLogSessionInformation_presult {
 public:


  virtual ~LogSession_getLogSessionInformation_presult() noexcept;
  LogSessionInformation* success;
   ::Uts::AppException e;

  _LogSession_getLogSessionInformation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_loadQShrinkFile_args__isset {
  _LogSession_loadQShrinkFile_args__isset() : protocolHandle(false), pathName(false) {}
  bool protocolHandle :1;
  bool pathName :1;
} _LogSession_loadQShrinkFile_args__isset;

class LogSession_loadQShrinkFile_args {
 public:

  LogSession_loadQShrinkFile_args(const LogSession_loadQShrinkFile_args&);
  LogSession_loadQShrinkFile_args& operator=(const LogSession_loadQShrinkFile_args&);
  LogSession_loadQShrinkFile_args() : protocolHandle(0), pathName() {
  }

  virtual ~LogSession_loadQShrinkFile_args() noexcept;
  int64_t protocolHandle;
  std::string pathName;

  _LogSession_loadQShrinkFile_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_pathName(const std::string& val);

  bool operator == (const LogSession_loadQShrinkFile_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(pathName == rhs.pathName))
      return false;
    return true;
  }
  bool operator != (const LogSession_loadQShrinkFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_loadQShrinkFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_loadQShrinkFile_pargs {
 public:


  virtual ~LogSession_loadQShrinkFile_pargs() noexcept;
  const int64_t* protocolHandle;
  const std::string* pathName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_loadQShrinkFile_result__isset {
  _LogSession_loadQShrinkFile_result__isset() : e(false) {}
  bool e :1;
} _LogSession_loadQShrinkFile_result__isset;

class LogSession_loadQShrinkFile_result {
 public:

  LogSession_loadQShrinkFile_result(const LogSession_loadQShrinkFile_result&);
  LogSession_loadQShrinkFile_result& operator=(const LogSession_loadQShrinkFile_result&);
  LogSession_loadQShrinkFile_result() {
  }

  virtual ~LogSession_loadQShrinkFile_result() noexcept;
   ::Uts::AppException e;

  _LogSession_loadQShrinkFile_result__isset __isset;

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_loadQShrinkFile_result & rhs) const
  {
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_loadQShrinkFile_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_loadQShrinkFile_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_loadQShrinkFile_presult__isset {
  _LogSession_loadQShrinkFile_presult__isset() : e(false) {}
  bool e :1;
} _LogSession_loadQShrinkFile_presult__isset;

class LogSession_loadQShrinkFile_presult {
 public:


  virtual ~LogSession_loadQShrinkFile_presult() noexcept;
   ::Uts::AppException e;

  _LogSession_loadQShrinkFile_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getDataViewItemIndex_args__isset {
  _LogSession_getDataViewItemIndex_args__isset() : viewName(false), sessionIndex(false) {}
  bool viewName :1;
  bool sessionIndex :1;
} _LogSession_getDataViewItemIndex_args__isset;

class LogSession_getDataViewItemIndex_args {
 public:

  LogSession_getDataViewItemIndex_args(const LogSession_getDataViewItemIndex_args&);
  LogSession_getDataViewItemIndex_args& operator=(const LogSession_getDataViewItemIndex_args&);
  LogSession_getDataViewItemIndex_args() : viewName(), sessionIndex(0) {
  }

  virtual ~LogSession_getDataViewItemIndex_args() noexcept;
  std::string viewName;
  int64_t sessionIndex;

  _LogSession_getDataViewItemIndex_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_sessionIndex(const int64_t val);

  bool operator == (const LogSession_getDataViewItemIndex_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(sessionIndex == rhs.sessionIndex))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataViewItemIndex_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataViewItemIndex_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getDataViewItemIndex_pargs {
 public:


  virtual ~LogSession_getDataViewItemIndex_pargs() noexcept;
  const std::string* viewName;
  const int64_t* sessionIndex;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataViewItemIndex_result__isset {
  _LogSession_getDataViewItemIndex_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataViewItemIndex_result__isset;

class LogSession_getDataViewItemIndex_result {
 public:

  LogSession_getDataViewItemIndex_result(const LogSession_getDataViewItemIndex_result&);
  LogSession_getDataViewItemIndex_result& operator=(const LogSession_getDataViewItemIndex_result&);
  LogSession_getDataViewItemIndex_result() : success(0) {
  }

  virtual ~LogSession_getDataViewItemIndex_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _LogSession_getDataViewItemIndex_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getDataViewItemIndex_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataViewItemIndex_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataViewItemIndex_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataViewItemIndex_presult__isset {
  _LogSession_getDataViewItemIndex_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataViewItemIndex_presult__isset;

class LogSession_getDataViewItemIndex_presult {
 public:


  virtual ~LogSession_getDataViewItemIndex_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _LogSession_getDataViewItemIndex_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args__isset {
  _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args__isset() : viewName(false), dataviewIndex(false) {}
  bool viewName :1;
  bool dataviewIndex :1;
} _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args__isset;

class LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args {
 public:

  LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args(const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args&);
  LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args& operator=(const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args&);
  LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args() : viewName(), dataviewIndex(0) {
  }

  virtual ~LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args() noexcept;
  std::string viewName;
  int64_t dataviewIndex;

  _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_dataviewIndex(const int64_t val);

  bool operator == (const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(dataviewIndex == rhs.dataviewIndex))
      return false;
    return true;
  }
  bool operator != (const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_pargs {
 public:


  virtual ~LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_pargs() noexcept;
  const std::string* viewName;
  const int64_t* dataviewIndex;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result__isset {
  _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result__isset;

class LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result {
 public:

  LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result(const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result&);
  LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result& operator=(const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result&);
  LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result() : success(0) {
  }

  virtual ~LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_presult__isset {
  _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_presult__isset;

class LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_presult {
 public:


  virtual ~LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _LogSession_getTimeStampTodAdjustedByDataviewIndexForAnnotations_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getDataViewItemsForConfiguration_args__isset {
  _LogSession_getDataViewItemsForConfiguration_args__isset() : viewName(false), packets(false), returnConfig(false) {}
  bool viewName :1;
  bool packets :1;
  bool returnConfig :1;
} _LogSession_getDataViewItemsForConfiguration_args__isset;

class LogSession_getDataViewItemsForConfiguration_args {
 public:

  LogSession_getDataViewItemsForConfiguration_args(const LogSession_getDataViewItemsForConfiguration_args&);
  LogSession_getDataViewItemsForConfiguration_args& operator=(const LogSession_getDataViewItemsForConfiguration_args&);
  LogSession_getDataViewItemsForConfiguration_args() : viewName() {
  }

  virtual ~LogSession_getDataViewItemsForConfiguration_args() noexcept;
  std::string viewName;
  PacketRange packets;
  PacketReturnConfig returnConfig;

  _LogSession_getDataViewItemsForConfiguration_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_packets(const PacketRange& val);

  void __set_returnConfig(const PacketReturnConfig& val);

  bool operator == (const LogSession_getDataViewItemsForConfiguration_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(packets == rhs.packets))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataViewItemsForConfiguration_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataViewItemsForConfiguration_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getDataViewItemsForConfiguration_pargs {
 public:


  virtual ~LogSession_getDataViewItemsForConfiguration_pargs() noexcept;
  const std::string* viewName;
  const PacketRange* packets;
  const PacketReturnConfig* returnConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataViewItemsForConfiguration_result__isset {
  _LogSession_getDataViewItemsForConfiguration_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataViewItemsForConfiguration_result__isset;

class LogSession_getDataViewItemsForConfiguration_result {
 public:

  LogSession_getDataViewItemsForConfiguration_result(const LogSession_getDataViewItemsForConfiguration_result&);
  LogSession_getDataViewItemsForConfiguration_result& operator=(const LogSession_getDataViewItemsForConfiguration_result&);
  LogSession_getDataViewItemsForConfiguration_result() {
  }

  virtual ~LogSession_getDataViewItemsForConfiguration_result() noexcept;
  std::vector<DataPacket>  success;
   ::Uts::AppException e;

  _LogSession_getDataViewItemsForConfiguration_result__isset __isset;

  void __set_success(const std::vector<DataPacket> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getDataViewItemsForConfiguration_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDataViewItemsForConfiguration_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDataViewItemsForConfiguration_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDataViewItemsForConfiguration_presult__isset {
  _LogSession_getDataViewItemsForConfiguration_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDataViewItemsForConfiguration_presult__isset;

class LogSession_getDataViewItemsForConfiguration_presult {
 public:


  virtual ~LogSession_getDataViewItemsForConfiguration_presult() noexcept;
  std::vector<DataPacket> * success;
   ::Uts::AppException e;

  _LogSession_getDataViewItemsForConfiguration_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class LogSession_getClientSessionInfo_args {
 public:

  LogSession_getClientSessionInfo_args(const LogSession_getClientSessionInfo_args&);
  LogSession_getClientSessionInfo_args& operator=(const LogSession_getClientSessionInfo_args&);
  LogSession_getClientSessionInfo_args() {
  }

  virtual ~LogSession_getClientSessionInfo_args() noexcept;

  bool operator == (const LogSession_getClientSessionInfo_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const LogSession_getClientSessionInfo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getClientSessionInfo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getClientSessionInfo_pargs {
 public:


  virtual ~LogSession_getClientSessionInfo_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getClientSessionInfo_result__isset {
  _LogSession_getClientSessionInfo_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getClientSessionInfo_result__isset;

class LogSession_getClientSessionInfo_result {
 public:

  LogSession_getClientSessionInfo_result(const LogSession_getClientSessionInfo_result&);
  LogSession_getClientSessionInfo_result& operator=(const LogSession_getClientSessionInfo_result&);
  LogSession_getClientSessionInfo_result() {
  }

  virtual ~LogSession_getClientSessionInfo_result() noexcept;
  ClientSessionInfo success;
   ::Uts::AppException e;

  _LogSession_getClientSessionInfo_result__isset __isset;

  void __set_success(const ClientSessionInfo& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getClientSessionInfo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getClientSessionInfo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getClientSessionInfo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getClientSessionInfo_presult__isset {
  _LogSession_getClientSessionInfo_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getClientSessionInfo_presult__isset;

class LogSession_getClientSessionInfo_presult {
 public:


  virtual ~LogSession_getClientSessionInfo_presult() noexcept;
  ClientSessionInfo* success;
   ::Uts::AppException e;

  _LogSession_getClientSessionInfo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_createSubDataView_args__isset {
  _LogSession_createSubDataView_args__isset() : viewName(false), parentViewName(false), filter(false), packets(false), returnConfig(false) {}
  bool viewName :1;
  bool parentViewName :1;
  bool filter :1;
  bool packets :1;
  bool returnConfig :1;
} _LogSession_createSubDataView_args__isset;

class LogSession_createSubDataView_args {
 public:

  LogSession_createSubDataView_args(const LogSession_createSubDataView_args&);
  LogSession_createSubDataView_args& operator=(const LogSession_createSubDataView_args&);
  LogSession_createSubDataView_args() : viewName(), parentViewName() {
  }

  virtual ~LogSession_createSubDataView_args() noexcept;
  std::string viewName;
  std::string parentViewName;
  DataPacketFilter filter;
  PacketRange packets;
  PacketReturnConfig returnConfig;

  _LogSession_createSubDataView_args__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_parentViewName(const std::string& val);

  void __set_filter(const DataPacketFilter& val);

  void __set_packets(const PacketRange& val);

  void __set_returnConfig(const PacketReturnConfig& val);

  bool operator == (const LogSession_createSubDataView_args & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(parentViewName == rhs.parentViewName))
      return false;
    if (!(filter == rhs.filter))
      return false;
    if (!(packets == rhs.packets))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const LogSession_createSubDataView_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_createSubDataView_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_createSubDataView_pargs {
 public:


  virtual ~LogSession_createSubDataView_pargs() noexcept;
  const std::string* viewName;
  const std::string* parentViewName;
  const DataPacketFilter* filter;
  const PacketRange* packets;
  const PacketReturnConfig* returnConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_createSubDataView_result__isset {
  _LogSession_createSubDataView_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_createSubDataView_result__isset;

class LogSession_createSubDataView_result {
 public:

  LogSession_createSubDataView_result(const LogSession_createSubDataView_result&);
  LogSession_createSubDataView_result& operator=(const LogSession_createSubDataView_result&);
  LogSession_createSubDataView_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_createSubDataView_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_createSubDataView_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_createSubDataView_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_createSubDataView_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_createSubDataView_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_createSubDataView_presult__isset {
  _LogSession_createSubDataView_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_createSubDataView_presult__isset;

class LogSession_createSubDataView_presult {
 public:


  virtual ~LogSession_createSubDataView_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_createSubDataView_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_setWcdmaProtocolRevision_args__isset {
  _LogSession_setWcdmaProtocolRevision_args__isset() : protocolHandle(false), revision(false) {}
  bool protocolHandle :1;
  bool revision :1;
} _LogSession_setWcdmaProtocolRevision_args__isset;

class LogSession_setWcdmaProtocolRevision_args {
 public:

  LogSession_setWcdmaProtocolRevision_args(const LogSession_setWcdmaProtocolRevision_args&);
  LogSession_setWcdmaProtocolRevision_args& operator=(const LogSession_setWcdmaProtocolRevision_args&);
  LogSession_setWcdmaProtocolRevision_args() : protocolHandle(0), revision(( ::Uts::WcdmaProtocolRevision::type)0) {
  }

  virtual ~LogSession_setWcdmaProtocolRevision_args() noexcept;
  int64_t protocolHandle;
   ::Uts::WcdmaProtocolRevision::type revision;

  _LogSession_setWcdmaProtocolRevision_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_revision(const  ::Uts::WcdmaProtocolRevision::type val);

  bool operator == (const LogSession_setWcdmaProtocolRevision_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(revision == rhs.revision))
      return false;
    return true;
  }
  bool operator != (const LogSession_setWcdmaProtocolRevision_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_setWcdmaProtocolRevision_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_setWcdmaProtocolRevision_pargs {
 public:


  virtual ~LogSession_setWcdmaProtocolRevision_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::WcdmaProtocolRevision::type* revision;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_setWcdmaProtocolRevision_result__isset {
  _LogSession_setWcdmaProtocolRevision_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_setWcdmaProtocolRevision_result__isset;

class LogSession_setWcdmaProtocolRevision_result {
 public:

  LogSession_setWcdmaProtocolRevision_result(const LogSession_setWcdmaProtocolRevision_result&);
  LogSession_setWcdmaProtocolRevision_result& operator=(const LogSession_setWcdmaProtocolRevision_result&);
  LogSession_setWcdmaProtocolRevision_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_setWcdmaProtocolRevision_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_setWcdmaProtocolRevision_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_setWcdmaProtocolRevision_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_setWcdmaProtocolRevision_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_setWcdmaProtocolRevision_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_setWcdmaProtocolRevision_presult__isset {
  _LogSession_setWcdmaProtocolRevision_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_setWcdmaProtocolRevision_presult__isset;

class LogSession_setWcdmaProtocolRevision_presult {
 public:


  virtual ~LogSession_setWcdmaProtocolRevision_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_setWcdmaProtocolRevision_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_setCdmaProtocolRevision_args__isset {
  _LogSession_setCdmaProtocolRevision_args__isset() : protocolHandle(false), revision(false) {}
  bool protocolHandle :1;
  bool revision :1;
} _LogSession_setCdmaProtocolRevision_args__isset;

class LogSession_setCdmaProtocolRevision_args {
 public:

  LogSession_setCdmaProtocolRevision_args(const LogSession_setCdmaProtocolRevision_args&);
  LogSession_setCdmaProtocolRevision_args& operator=(const LogSession_setCdmaProtocolRevision_args&);
  LogSession_setCdmaProtocolRevision_args() : protocolHandle(0), revision(( ::Uts::CdmaProtocolRevision::type)0) {
  }

  virtual ~LogSession_setCdmaProtocolRevision_args() noexcept;
  int64_t protocolHandle;
   ::Uts::CdmaProtocolRevision::type revision;

  _LogSession_setCdmaProtocolRevision_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_revision(const  ::Uts::CdmaProtocolRevision::type val);

  bool operator == (const LogSession_setCdmaProtocolRevision_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(revision == rhs.revision))
      return false;
    return true;
  }
  bool operator != (const LogSession_setCdmaProtocolRevision_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_setCdmaProtocolRevision_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_setCdmaProtocolRevision_pargs {
 public:


  virtual ~LogSession_setCdmaProtocolRevision_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::CdmaProtocolRevision::type* revision;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_setCdmaProtocolRevision_result__isset {
  _LogSession_setCdmaProtocolRevision_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_setCdmaProtocolRevision_result__isset;

class LogSession_setCdmaProtocolRevision_result {
 public:

  LogSession_setCdmaProtocolRevision_result(const LogSession_setCdmaProtocolRevision_result&);
  LogSession_setCdmaProtocolRevision_result& operator=(const LogSession_setCdmaProtocolRevision_result&);
  LogSession_setCdmaProtocolRevision_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_setCdmaProtocolRevision_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_setCdmaProtocolRevision_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_setCdmaProtocolRevision_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_setCdmaProtocolRevision_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_setCdmaProtocolRevision_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_setCdmaProtocolRevision_presult__isset {
  _LogSession_setCdmaProtocolRevision_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_setCdmaProtocolRevision_presult__isset;

class LogSession_setCdmaProtocolRevision_presult {
 public:


  virtual ~LogSession_setCdmaProtocolRevision_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_setCdmaProtocolRevision_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_setPilotInc_args__isset {
  _LogSession_setPilotInc_args__isset() : protocolHandle(false), pilotInc(false) {}
  bool protocolHandle :1;
  bool pilotInc :1;
} _LogSession_setPilotInc_args__isset;

class LogSession_setPilotInc_args {
 public:

  LogSession_setPilotInc_args(const LogSession_setPilotInc_args&);
  LogSession_setPilotInc_args& operator=(const LogSession_setPilotInc_args&);
  LogSession_setPilotInc_args() : protocolHandle(0), pilotInc(0) {
  }

  virtual ~LogSession_setPilotInc_args() noexcept;
  int64_t protocolHandle;
  int16_t pilotInc;

  _LogSession_setPilotInc_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_pilotInc(const int16_t val);

  bool operator == (const LogSession_setPilotInc_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(pilotInc == rhs.pilotInc))
      return false;
    return true;
  }
  bool operator != (const LogSession_setPilotInc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_setPilotInc_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_setPilotInc_pargs {
 public:


  virtual ~LogSession_setPilotInc_pargs() noexcept;
  const int64_t* protocolHandle;
  const int16_t* pilotInc;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_setPilotInc_result__isset {
  _LogSession_setPilotInc_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_setPilotInc_result__isset;

class LogSession_setPilotInc_result {
 public:

  LogSession_setPilotInc_result(const LogSession_setPilotInc_result&);
  LogSession_setPilotInc_result& operator=(const LogSession_setPilotInc_result&);
  LogSession_setPilotInc_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~LogSession_setPilotInc_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _LogSession_setPilotInc_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_setPilotInc_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_setPilotInc_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_setPilotInc_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_setPilotInc_presult__isset {
  _LogSession_setPilotInc_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_setPilotInc_presult__isset;

class LogSession_setPilotInc_presult {
 public:


  virtual ~LogSession_setPilotInc_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _LogSession_setPilotInc_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getBandClass_args__isset {
  _LogSession_getBandClass_args__isset() : protocolHandle(false), protocolIndex(false) {}
  bool protocolHandle :1;
  bool protocolIndex :1;
} _LogSession_getBandClass_args__isset;

class LogSession_getBandClass_args {
 public:

  LogSession_getBandClass_args(const LogSession_getBandClass_args&);
  LogSession_getBandClass_args& operator=(const LogSession_getBandClass_args&);
  LogSession_getBandClass_args() : protocolHandle(0), protocolIndex(0) {
  }

  virtual ~LogSession_getBandClass_args() noexcept;
  int64_t protocolHandle;
  int64_t protocolIndex;

  _LogSession_getBandClass_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  bool operator == (const LogSession_getBandClass_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(protocolIndex == rhs.protocolIndex))
      return false;
    return true;
  }
  bool operator != (const LogSession_getBandClass_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getBandClass_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getBandClass_pargs {
 public:


  virtual ~LogSession_getBandClass_pargs() noexcept;
  const int64_t* protocolHandle;
  const int64_t* protocolIndex;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getBandClass_result__isset {
  _LogSession_getBandClass_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getBandClass_result__isset;

class LogSession_getBandClass_result {
 public:

  LogSession_getBandClass_result(const LogSession_getBandClass_result&);
  LogSession_getBandClass_result& operator=(const LogSession_getBandClass_result&);
  LogSession_getBandClass_result() : success(0) {
  }

  virtual ~LogSession_getBandClass_result() noexcept;
  int16_t success;
   ::Uts::AppException e;

  _LogSession_getBandClass_result__isset __isset;

  void __set_success(const int16_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getBandClass_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getBandClass_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getBandClass_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getBandClass_presult__isset {
  _LogSession_getBandClass_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getBandClass_presult__isset;

class LogSession_getBandClass_presult {
 public:


  virtual ~LogSession_getBandClass_presult() noexcept;
  int16_t* success;
   ::Uts::AppException e;

  _LogSession_getBandClass_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getCdmaProtocolRevision_args__isset {
  _LogSession_getCdmaProtocolRevision_args__isset() : protocolHandle(false), protocolIndex(false) {}
  bool protocolHandle :1;
  bool protocolIndex :1;
} _LogSession_getCdmaProtocolRevision_args__isset;

class LogSession_getCdmaProtocolRevision_args {
 public:

  LogSession_getCdmaProtocolRevision_args(const LogSession_getCdmaProtocolRevision_args&);
  LogSession_getCdmaProtocolRevision_args& operator=(const LogSession_getCdmaProtocolRevision_args&);
  LogSession_getCdmaProtocolRevision_args() : protocolHandle(0), protocolIndex(0) {
  }

  virtual ~LogSession_getCdmaProtocolRevision_args() noexcept;
  int64_t protocolHandle;
  int64_t protocolIndex;

  _LogSession_getCdmaProtocolRevision_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  bool operator == (const LogSession_getCdmaProtocolRevision_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(protocolIndex == rhs.protocolIndex))
      return false;
    return true;
  }
  bool operator != (const LogSession_getCdmaProtocolRevision_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getCdmaProtocolRevision_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getCdmaProtocolRevision_pargs {
 public:


  virtual ~LogSession_getCdmaProtocolRevision_pargs() noexcept;
  const int64_t* protocolHandle;
  const int64_t* protocolIndex;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getCdmaProtocolRevision_result__isset {
  _LogSession_getCdmaProtocolRevision_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getCdmaProtocolRevision_result__isset;

class LogSession_getCdmaProtocolRevision_result {
 public:

  LogSession_getCdmaProtocolRevision_result(const LogSession_getCdmaProtocolRevision_result&);
  LogSession_getCdmaProtocolRevision_result& operator=(const LogSession_getCdmaProtocolRevision_result&);
  LogSession_getCdmaProtocolRevision_result() : success(( ::Uts::CdmaProtocolRevision::type)0) {
  }

  virtual ~LogSession_getCdmaProtocolRevision_result() noexcept;
   ::Uts::CdmaProtocolRevision::type success;
   ::Uts::AppException e;

  _LogSession_getCdmaProtocolRevision_result__isset __isset;

  void __set_success(const  ::Uts::CdmaProtocolRevision::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getCdmaProtocolRevision_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getCdmaProtocolRevision_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getCdmaProtocolRevision_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getCdmaProtocolRevision_presult__isset {
  _LogSession_getCdmaProtocolRevision_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getCdmaProtocolRevision_presult__isset;

class LogSession_getCdmaProtocolRevision_presult {
 public:


  virtual ~LogSession_getCdmaProtocolRevision_presult() noexcept;
   ::Uts::CdmaProtocolRevision::type* success;
   ::Uts::AppException e;

  _LogSession_getCdmaProtocolRevision_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getModel_args__isset {
  _LogSession_getModel_args__isset() : protocolHandle(false), protocolIndex(false) {}
  bool protocolHandle :1;
  bool protocolIndex :1;
} _LogSession_getModel_args__isset;

class LogSession_getModel_args {
 public:

  LogSession_getModel_args(const LogSession_getModel_args&);
  LogSession_getModel_args& operator=(const LogSession_getModel_args&);
  LogSession_getModel_args() : protocolHandle(0), protocolIndex(0) {
  }

  virtual ~LogSession_getModel_args() noexcept;
  int64_t protocolHandle;
  int64_t protocolIndex;

  _LogSession_getModel_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  bool operator == (const LogSession_getModel_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(protocolIndex == rhs.protocolIndex))
      return false;
    return true;
  }
  bool operator != (const LogSession_getModel_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getModel_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getModel_pargs {
 public:


  virtual ~LogSession_getModel_pargs() noexcept;
  const int64_t* protocolHandle;
  const int64_t* protocolIndex;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getModel_result__isset {
  _LogSession_getModel_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getModel_result__isset;

class LogSession_getModel_result {
 public:

  LogSession_getModel_result(const LogSession_getModel_result&);
  LogSession_getModel_result& operator=(const LogSession_getModel_result&);
  LogSession_getModel_result() : success(0) {
  }

  virtual ~LogSession_getModel_result() noexcept;
  int16_t success;
   ::Uts::AppException e;

  _LogSession_getModel_result__isset __isset;

  void __set_success(const int16_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getModel_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getModel_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getModel_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getModel_presult__isset {
  _LogSession_getModel_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getModel_presult__isset;

class LogSession_getModel_presult {
 public:


  virtual ~LogSession_getModel_presult() noexcept;
  int16_t* success;
   ::Uts::AppException e;

  _LogSession_getModel_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getWcdmaProtocolRevision_args__isset {
  _LogSession_getWcdmaProtocolRevision_args__isset() : protocolHandle(false), protocolIndex(false) {}
  bool protocolHandle :1;
  bool protocolIndex :1;
} _LogSession_getWcdmaProtocolRevision_args__isset;

class LogSession_getWcdmaProtocolRevision_args {
 public:

  LogSession_getWcdmaProtocolRevision_args(const LogSession_getWcdmaProtocolRevision_args&);
  LogSession_getWcdmaProtocolRevision_args& operator=(const LogSession_getWcdmaProtocolRevision_args&);
  LogSession_getWcdmaProtocolRevision_args() : protocolHandle(0), protocolIndex(0) {
  }

  virtual ~LogSession_getWcdmaProtocolRevision_args() noexcept;
  int64_t protocolHandle;
  int64_t protocolIndex;

  _LogSession_getWcdmaProtocolRevision_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_protocolIndex(const int64_t val);

  bool operator == (const LogSession_getWcdmaProtocolRevision_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(protocolIndex == rhs.protocolIndex))
      return false;
    return true;
  }
  bool operator != (const LogSession_getWcdmaProtocolRevision_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getWcdmaProtocolRevision_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getWcdmaProtocolRevision_pargs {
 public:


  virtual ~LogSession_getWcdmaProtocolRevision_pargs() noexcept;
  const int64_t* protocolHandle;
  const int64_t* protocolIndex;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getWcdmaProtocolRevision_result__isset {
  _LogSession_getWcdmaProtocolRevision_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getWcdmaProtocolRevision_result__isset;

class LogSession_getWcdmaProtocolRevision_result {
 public:

  LogSession_getWcdmaProtocolRevision_result(const LogSession_getWcdmaProtocolRevision_result&);
  LogSession_getWcdmaProtocolRevision_result& operator=(const LogSession_getWcdmaProtocolRevision_result&);
  LogSession_getWcdmaProtocolRevision_result() : success(( ::Uts::WcdmaProtocolRevision::type)0) {
  }

  virtual ~LogSession_getWcdmaProtocolRevision_result() noexcept;
   ::Uts::WcdmaProtocolRevision::type success;
   ::Uts::AppException e;

  _LogSession_getWcdmaProtocolRevision_result__isset __isset;

  void __set_success(const  ::Uts::WcdmaProtocolRevision::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getWcdmaProtocolRevision_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getWcdmaProtocolRevision_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getWcdmaProtocolRevision_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getWcdmaProtocolRevision_presult__isset {
  _LogSession_getWcdmaProtocolRevision_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getWcdmaProtocolRevision_presult__isset;

class LogSession_getWcdmaProtocolRevision_presult {
 public:


  virtual ~LogSession_getWcdmaProtocolRevision_presult() noexcept;
   ::Uts::WcdmaProtocolRevision::type* success;
   ::Uts::AppException e;

  _LogSession_getWcdmaProtocolRevision_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _LogSession_getDecryptionKeyStatus_args__isset {
  _LogSession_getDecryptionKeyStatus_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _LogSession_getDecryptionKeyStatus_args__isset;

class LogSession_getDecryptionKeyStatus_args {
 public:

  LogSession_getDecryptionKeyStatus_args(const LogSession_getDecryptionKeyStatus_args&);
  LogSession_getDecryptionKeyStatus_args& operator=(const LogSession_getDecryptionKeyStatus_args&);
  LogSession_getDecryptionKeyStatus_args() : protocolHandle(0) {
  }

  virtual ~LogSession_getDecryptionKeyStatus_args() noexcept;
  int64_t protocolHandle;

  _LogSession_getDecryptionKeyStatus_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const LogSession_getDecryptionKeyStatus_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDecryptionKeyStatus_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDecryptionKeyStatus_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class LogSession_getDecryptionKeyStatus_pargs {
 public:


  virtual ~LogSession_getDecryptionKeyStatus_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDecryptionKeyStatus_result__isset {
  _LogSession_getDecryptionKeyStatus_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDecryptionKeyStatus_result__isset;

class LogSession_getDecryptionKeyStatus_result {
 public:

  LogSession_getDecryptionKeyStatus_result(const LogSession_getDecryptionKeyStatus_result&);
  LogSession_getDecryptionKeyStatus_result& operator=(const LogSession_getDecryptionKeyStatus_result&);
  LogSession_getDecryptionKeyStatus_result() {
  }

  virtual ~LogSession_getDecryptionKeyStatus_result() noexcept;
  std::vector< ::Uts::KeyInfo>  success;
   ::Uts::AppException e;

  _LogSession_getDecryptionKeyStatus_result__isset __isset;

  void __set_success(const std::vector< ::Uts::KeyInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const LogSession_getDecryptionKeyStatus_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const LogSession_getDecryptionKeyStatus_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSession_getDecryptionKeyStatus_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _LogSession_getDecryptionKeyStatus_presult__isset {
  _LogSession_getDecryptionKeyStatus_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _LogSession_getDecryptionKeyStatus_presult__isset;

class LogSession_getDecryptionKeyStatus_presult {
 public:


  virtual ~LogSession_getDecryptionKeyStatus_presult() noexcept;
  std::vector< ::Uts::KeyInfo> * success;
   ::Uts::AppException e;

  _LogSession_getDecryptionKeyStatus_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class LogSessionClient : virtual public LogSessionIf {
 public:
  LogSessionClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  LogSessionClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
   ::Uts::ErrorCode::type destroyLogSession();
  void send_destroyLogSession();
   ::Uts::ErrorCode::type recv_destroyLogSession();
  void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return);
  void send_getDeviceList();
  void recv_getDeviceList(std::vector< ::Uts::DeviceInfo> & _return);
  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle);
  void send_getProtocolList(const int64_t deviceHandle);
  void recv_getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return);
  int64_t getDataPacketCount(const int64_t protocolHandle);
  void send_getDataPacketCount(const int64_t protocolHandle);
  int64_t recv_getDataPacketCount();
   ::Uts::ErrorCode::type createDataView(const std::string& viewName, const DataPacketFilter& filter, const PacketReturnConfig& returnConfig);
  void send_createDataView(const std::string& viewName, const DataPacketFilter& filter, const PacketReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createDataView();
   ::Uts::ErrorCode::type createDefaultDataView(const std::string& viewName, const std::vector<int64_t> & protocolHandleList, const PacketReturnConfig& returnConfig);
  void send_createDefaultDataView(const std::string& viewName, const std::vector<int64_t> & protocolHandleList, const PacketReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createDefaultDataView();
   ::Uts::ErrorCode::type createDataViewSet(const std::vector<DataViewInfo> & dataViewDefinitions);
  void send_createDataViewSet(const std::vector<DataViewInfo> & dataViewDefinitions);
   ::Uts::ErrorCode::type recv_createDataViewSet();
   ::Uts::ErrorCode::type removeDataView(const std::string& viewName);
  void send_removeDataView(const std::string& viewName);
   ::Uts::ErrorCode::type recv_removeDataView();
  int32_t getDataViewItemCount(const std::string& viewName);
  void send_getDataViewItemCount(const std::string& viewName);
  int32_t recv_getDataViewItemCount();
  void getDataViewItems(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets);
  void send_getDataViewItems(const std::string& viewName, const PacketRange& packets);
  void recv_getDataViewItems(std::vector<DataPacket> & _return);
   ::Uts::ErrorCode::type saveDataViewItemsByIndex(const std::string& viewName, const std::string& destinationFolder, const std::vector<int64_t> & dataViewIndexes);
  void send_saveDataViewItemsByIndex(const std::string& viewName, const std::string& destinationFolder, const std::vector<int64_t> & dataViewIndexes);
   ::Uts::ErrorCode::type recv_saveDataViewItemsByIndex();
   ::Uts::ErrorCode::type saveDataViewItemsByIndexWithFilenames(const std::string& viewName, const std::vector<int64_t> & dataViewIndexes, const std::map<int64_t, std::string> & logNamesByHandle);
  void send_saveDataViewItemsByIndexWithFilenames(const std::string& viewName, const std::vector<int64_t> & dataViewIndexes, const std::map<int64_t, std::string> & logNamesByHandle);
   ::Uts::ErrorCode::type recv_saveDataViewItemsByIndexWithFilenames();
  void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder);
  void send_saveLogFiles(const std::string& saveFolder);
  void recv_saveLogFiles(std::vector<std::string> & _return);
  void getDurationByProtocol(std::string& _return, const int64_t protocolHandle);
  void send_getDurationByProtocol(const int64_t protocolHandle);
  void recv_getDurationByProtocol(std::string& _return);
   ::Uts::ErrorCode::type updatePacketFilters(const std::string& viewName, const DataPacketFilter& filter, const ViewConfigurationUpdate::type updateType);
  void send_updatePacketFilters(const std::string& viewName, const DataPacketFilter& filter, const ViewConfigurationUpdate::type updateType);
   ::Uts::ErrorCode::type recv_updatePacketFilters();
   ::Uts::ErrorCode::type updatePacketReturnConfig(const std::string& viewName, const PacketReturnConfig& returnConfig);
  void send_updatePacketReturnConfig(const std::string& viewName, const PacketReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_updatePacketReturnConfig();
  void getAvailablePacketIds(DataPacketFilter& _return, const int64_t protocolHandle);
  void send_getAvailablePacketIds(const int64_t protocolHandle);
  void recv_getAvailablePacketIds(DataPacketFilter& _return);
  void getLogSessionInformation(LogSessionInformation& _return, const std::set<int64_t> & protocolHandle);
  void send_getLogSessionInformation(const std::set<int64_t> & protocolHandle);
  void recv_getLogSessionInformation(LogSessionInformation& _return);
  void loadQShrinkFile(const int64_t protocolHandle, const std::string& pathName);
  void send_loadQShrinkFile(const int64_t protocolHandle, const std::string& pathName);
  void recv_loadQShrinkFile();
  int64_t getDataViewItemIndex(const std::string& viewName, const int64_t sessionIndex);
  void send_getDataViewItemIndex(const std::string& viewName, const int64_t sessionIndex);
  int64_t recv_getDataViewItemIndex();
  int64_t getTimeStampTodAdjustedByDataviewIndexForAnnotations(const std::string& viewName, const int64_t dataviewIndex);
  void send_getTimeStampTodAdjustedByDataviewIndexForAnnotations(const std::string& viewName, const int64_t dataviewIndex);
  int64_t recv_getTimeStampTodAdjustedByDataviewIndexForAnnotations();
  void getDataViewItemsForConfiguration(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets, const PacketReturnConfig& returnConfig);
  void send_getDataViewItemsForConfiguration(const std::string& viewName, const PacketRange& packets, const PacketReturnConfig& returnConfig);
  void recv_getDataViewItemsForConfiguration(std::vector<DataPacket> & _return);
  void getClientSessionInfo(ClientSessionInfo& _return);
  void send_getClientSessionInfo();
  void recv_getClientSessionInfo(ClientSessionInfo& _return);
   ::Uts::ErrorCode::type createSubDataView(const std::string& viewName, const std::string& parentViewName, const DataPacketFilter& filter, const PacketRange& packets, const PacketReturnConfig& returnConfig);
  void send_createSubDataView(const std::string& viewName, const std::string& parentViewName, const DataPacketFilter& filter, const PacketRange& packets, const PacketReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createSubDataView();
   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::WcdmaProtocolRevision::type revision);
  void send_setWcdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::WcdmaProtocolRevision::type revision);
   ::Uts::ErrorCode::type recv_setWcdmaProtocolRevision();
   ::Uts::ErrorCode::type setCdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::CdmaProtocolRevision::type revision);
  void send_setCdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::CdmaProtocolRevision::type revision);
   ::Uts::ErrorCode::type recv_setCdmaProtocolRevision();
   ::Uts::ErrorCode::type setPilotInc(const int64_t protocolHandle, const int16_t pilotInc);
  void send_setPilotInc(const int64_t protocolHandle, const int16_t pilotInc);
   ::Uts::ErrorCode::type recv_setPilotInc();
  int16_t getBandClass(const int64_t protocolHandle, const int64_t protocolIndex);
  void send_getBandClass(const int64_t protocolHandle, const int64_t protocolIndex);
  int16_t recv_getBandClass();
   ::Uts::CdmaProtocolRevision::type getCdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex);
  void send_getCdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex);
   ::Uts::CdmaProtocolRevision::type recv_getCdmaProtocolRevision();
  int16_t getModel(const int64_t protocolHandle, const int64_t protocolIndex);
  void send_getModel(const int64_t protocolHandle, const int64_t protocolIndex);
  int16_t recv_getModel();
   ::Uts::WcdmaProtocolRevision::type getWcdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex);
  void send_getWcdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex);
   ::Uts::WcdmaProtocolRevision::type recv_getWcdmaProtocolRevision();
  void getDecryptionKeyStatus(std::vector< ::Uts::KeyInfo> & _return, const int64_t protocolHandle);
  void send_getDecryptionKeyStatus(const int64_t protocolHandle);
  void recv_getDecryptionKeyStatus(std::vector< ::Uts::KeyInfo> & _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class LogSessionProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<LogSessionIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (LogSessionProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_destroyLogSession(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getProtocolList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDataPacketCount(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createDataView(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createDefaultDataView(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createDataViewSet(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeDataView(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDataViewItemCount(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDataViewItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_saveDataViewItemsByIndex(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_saveDataViewItemsByIndexWithFilenames(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_saveLogFiles(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDurationByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_updatePacketFilters(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_updatePacketReturnConfig(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getAvailablePacketIds(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getLogSessionInformation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_loadQShrinkFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDataViewItemIndex(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTimeStampTodAdjustedByDataviewIndexForAnnotations(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDataViewItemsForConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getClientSessionInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createSubDataView(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setWcdmaProtocolRevision(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setCdmaProtocolRevision(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setPilotInc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getBandClass(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getCdmaProtocolRevision(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getModel(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getWcdmaProtocolRevision(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDecryptionKeyStatus(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  LogSessionProcessor(::std::shared_ptr<LogSessionIf> iface) :
    iface_(iface) {
    processMap_["getLastError"] = &LogSessionProcessor::process_getLastError;
    processMap_["destroyLogSession"] = &LogSessionProcessor::process_destroyLogSession;
    processMap_["getDeviceList"] = &LogSessionProcessor::process_getDeviceList;
    processMap_["getProtocolList"] = &LogSessionProcessor::process_getProtocolList;
    processMap_["getDataPacketCount"] = &LogSessionProcessor::process_getDataPacketCount;
    processMap_["createDataView"] = &LogSessionProcessor::process_createDataView;
    processMap_["createDefaultDataView"] = &LogSessionProcessor::process_createDefaultDataView;
    processMap_["createDataViewSet"] = &LogSessionProcessor::process_createDataViewSet;
    processMap_["removeDataView"] = &LogSessionProcessor::process_removeDataView;
    processMap_["getDataViewItemCount"] = &LogSessionProcessor::process_getDataViewItemCount;
    processMap_["getDataViewItems"] = &LogSessionProcessor::process_getDataViewItems;
    processMap_["saveDataViewItemsByIndex"] = &LogSessionProcessor::process_saveDataViewItemsByIndex;
    processMap_["saveDataViewItemsByIndexWithFilenames"] = &LogSessionProcessor::process_saveDataViewItemsByIndexWithFilenames;
    processMap_["saveLogFiles"] = &LogSessionProcessor::process_saveLogFiles;
    processMap_["getDurationByProtocol"] = &LogSessionProcessor::process_getDurationByProtocol;
    processMap_["updatePacketFilters"] = &LogSessionProcessor::process_updatePacketFilters;
    processMap_["updatePacketReturnConfig"] = &LogSessionProcessor::process_updatePacketReturnConfig;
    processMap_["getAvailablePacketIds"] = &LogSessionProcessor::process_getAvailablePacketIds;
    processMap_["getLogSessionInformation"] = &LogSessionProcessor::process_getLogSessionInformation;
    processMap_["loadQShrinkFile"] = &LogSessionProcessor::process_loadQShrinkFile;
    processMap_["getDataViewItemIndex"] = &LogSessionProcessor::process_getDataViewItemIndex;
    processMap_["getTimeStampTodAdjustedByDataviewIndexForAnnotations"] = &LogSessionProcessor::process_getTimeStampTodAdjustedByDataviewIndexForAnnotations;
    processMap_["getDataViewItemsForConfiguration"] = &LogSessionProcessor::process_getDataViewItemsForConfiguration;
    processMap_["getClientSessionInfo"] = &LogSessionProcessor::process_getClientSessionInfo;
    processMap_["createSubDataView"] = &LogSessionProcessor::process_createSubDataView;
    processMap_["setWcdmaProtocolRevision"] = &LogSessionProcessor::process_setWcdmaProtocolRevision;
    processMap_["setCdmaProtocolRevision"] = &LogSessionProcessor::process_setCdmaProtocolRevision;
    processMap_["setPilotInc"] = &LogSessionProcessor::process_setPilotInc;
    processMap_["getBandClass"] = &LogSessionProcessor::process_getBandClass;
    processMap_["getCdmaProtocolRevision"] = &LogSessionProcessor::process_getCdmaProtocolRevision;
    processMap_["getModel"] = &LogSessionProcessor::process_getModel;
    processMap_["getWcdmaProtocolRevision"] = &LogSessionProcessor::process_getWcdmaProtocolRevision;
    processMap_["getDecryptionKeyStatus"] = &LogSessionProcessor::process_getDecryptionKeyStatus;
  }

  virtual ~LogSessionProcessor() {}
};

class LogSessionProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  LogSessionProcessorFactory(const ::std::shared_ptr< LogSessionIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< LogSessionIfFactory > handlerFactory_;
};

class LogSessionMultiface : virtual public LogSessionIf {
 public:
  LogSessionMultiface(std::vector<std::shared_ptr<LogSessionIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~LogSessionMultiface() {}
 protected:
  std::vector<std::shared_ptr<LogSessionIf> > ifaces_;
  LogSessionMultiface() {}
  void add(::std::shared_ptr<LogSessionIf> iface) {
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

   ::Uts::ErrorCode::type destroyLogSession() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->destroyLogSession();
    }
    return ifaces_[i]->destroyLogSession();
  }

  void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDeviceList(_return);
    }
    ifaces_[i]->getDeviceList(_return);
    return;
  }

  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getProtocolList(_return, deviceHandle);
    }
    ifaces_[i]->getProtocolList(_return, deviceHandle);
    return;
  }

  int64_t getDataPacketCount(const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDataPacketCount(protocolHandle);
    }
    return ifaces_[i]->getDataPacketCount(protocolHandle);
  }

   ::Uts::ErrorCode::type createDataView(const std::string& viewName, const DataPacketFilter& filter, const PacketReturnConfig& returnConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createDataView(viewName, filter, returnConfig);
    }
    return ifaces_[i]->createDataView(viewName, filter, returnConfig);
  }

   ::Uts::ErrorCode::type createDefaultDataView(const std::string& viewName, const std::vector<int64_t> & protocolHandleList, const PacketReturnConfig& returnConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createDefaultDataView(viewName, protocolHandleList, returnConfig);
    }
    return ifaces_[i]->createDefaultDataView(viewName, protocolHandleList, returnConfig);
  }

   ::Uts::ErrorCode::type createDataViewSet(const std::vector<DataViewInfo> & dataViewDefinitions) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createDataViewSet(dataViewDefinitions);
    }
    return ifaces_[i]->createDataViewSet(dataViewDefinitions);
  }

   ::Uts::ErrorCode::type removeDataView(const std::string& viewName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeDataView(viewName);
    }
    return ifaces_[i]->removeDataView(viewName);
  }

  int32_t getDataViewItemCount(const std::string& viewName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDataViewItemCount(viewName);
    }
    return ifaces_[i]->getDataViewItemCount(viewName);
  }

  void getDataViewItems(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDataViewItems(_return, viewName, packets);
    }
    ifaces_[i]->getDataViewItems(_return, viewName, packets);
    return;
  }

   ::Uts::ErrorCode::type saveDataViewItemsByIndex(const std::string& viewName, const std::string& destinationFolder, const std::vector<int64_t> & dataViewIndexes) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->saveDataViewItemsByIndex(viewName, destinationFolder, dataViewIndexes);
    }
    return ifaces_[i]->saveDataViewItemsByIndex(viewName, destinationFolder, dataViewIndexes);
  }

   ::Uts::ErrorCode::type saveDataViewItemsByIndexWithFilenames(const std::string& viewName, const std::vector<int64_t> & dataViewIndexes, const std::map<int64_t, std::string> & logNamesByHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->saveDataViewItemsByIndexWithFilenames(viewName, dataViewIndexes, logNamesByHandle);
    }
    return ifaces_[i]->saveDataViewItemsByIndexWithFilenames(viewName, dataViewIndexes, logNamesByHandle);
  }

  void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->saveLogFiles(_return, saveFolder);
    }
    ifaces_[i]->saveLogFiles(_return, saveFolder);
    return;
  }

  void getDurationByProtocol(std::string& _return, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDurationByProtocol(_return, protocolHandle);
    }
    ifaces_[i]->getDurationByProtocol(_return, protocolHandle);
    return;
  }

   ::Uts::ErrorCode::type updatePacketFilters(const std::string& viewName, const DataPacketFilter& filter, const ViewConfigurationUpdate::type updateType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->updatePacketFilters(viewName, filter, updateType);
    }
    return ifaces_[i]->updatePacketFilters(viewName, filter, updateType);
  }

   ::Uts::ErrorCode::type updatePacketReturnConfig(const std::string& viewName, const PacketReturnConfig& returnConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->updatePacketReturnConfig(viewName, returnConfig);
    }
    return ifaces_[i]->updatePacketReturnConfig(viewName, returnConfig);
  }

  void getAvailablePacketIds(DataPacketFilter& _return, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getAvailablePacketIds(_return, protocolHandle);
    }
    ifaces_[i]->getAvailablePacketIds(_return, protocolHandle);
    return;
  }

  void getLogSessionInformation(LogSessionInformation& _return, const std::set<int64_t> & protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getLogSessionInformation(_return, protocolHandle);
    }
    ifaces_[i]->getLogSessionInformation(_return, protocolHandle);
    return;
  }

  void loadQShrinkFile(const int64_t protocolHandle, const std::string& pathName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->loadQShrinkFile(protocolHandle, pathName);
    }
    ifaces_[i]->loadQShrinkFile(protocolHandle, pathName);
  }

  int64_t getDataViewItemIndex(const std::string& viewName, const int64_t sessionIndex) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDataViewItemIndex(viewName, sessionIndex);
    }
    return ifaces_[i]->getDataViewItemIndex(viewName, sessionIndex);
  }

  int64_t getTimeStampTodAdjustedByDataviewIndexForAnnotations(const std::string& viewName, const int64_t dataviewIndex) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTimeStampTodAdjustedByDataviewIndexForAnnotations(viewName, dataviewIndex);
    }
    return ifaces_[i]->getTimeStampTodAdjustedByDataviewIndexForAnnotations(viewName, dataviewIndex);
  }

  void getDataViewItemsForConfiguration(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets, const PacketReturnConfig& returnConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDataViewItemsForConfiguration(_return, viewName, packets, returnConfig);
    }
    ifaces_[i]->getDataViewItemsForConfiguration(_return, viewName, packets, returnConfig);
    return;
  }

  void getClientSessionInfo(ClientSessionInfo& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getClientSessionInfo(_return);
    }
    ifaces_[i]->getClientSessionInfo(_return);
    return;
  }

   ::Uts::ErrorCode::type createSubDataView(const std::string& viewName, const std::string& parentViewName, const DataPacketFilter& filter, const PacketRange& packets, const PacketReturnConfig& returnConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createSubDataView(viewName, parentViewName, filter, packets, returnConfig);
    }
    return ifaces_[i]->createSubDataView(viewName, parentViewName, filter, packets, returnConfig);
  }

   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::WcdmaProtocolRevision::type revision) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setWcdmaProtocolRevision(protocolHandle, revision);
    }
    return ifaces_[i]->setWcdmaProtocolRevision(protocolHandle, revision);
  }

   ::Uts::ErrorCode::type setCdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::CdmaProtocolRevision::type revision) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setCdmaProtocolRevision(protocolHandle, revision);
    }
    return ifaces_[i]->setCdmaProtocolRevision(protocolHandle, revision);
  }

   ::Uts::ErrorCode::type setPilotInc(const int64_t protocolHandle, const int16_t pilotInc) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setPilotInc(protocolHandle, pilotInc);
    }
    return ifaces_[i]->setPilotInc(protocolHandle, pilotInc);
  }

  int16_t getBandClass(const int64_t protocolHandle, const int64_t protocolIndex) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getBandClass(protocolHandle, protocolIndex);
    }
    return ifaces_[i]->getBandClass(protocolHandle, protocolIndex);
  }

   ::Uts::CdmaProtocolRevision::type getCdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getCdmaProtocolRevision(protocolHandle, protocolIndex);
    }
    return ifaces_[i]->getCdmaProtocolRevision(protocolHandle, protocolIndex);
  }

  int16_t getModel(const int64_t protocolHandle, const int64_t protocolIndex) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getModel(protocolHandle, protocolIndex);
    }
    return ifaces_[i]->getModel(protocolHandle, protocolIndex);
  }

   ::Uts::WcdmaProtocolRevision::type getWcdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getWcdmaProtocolRevision(protocolHandle, protocolIndex);
    }
    return ifaces_[i]->getWcdmaProtocolRevision(protocolHandle, protocolIndex);
  }

  void getDecryptionKeyStatus(std::vector< ::Uts::KeyInfo> & _return, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDecryptionKeyStatus(_return, protocolHandle);
    }
    ifaces_[i]->getDecryptionKeyStatus(_return, protocolHandle);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class LogSessionConcurrentClient : virtual public LogSessionIf {
 public:
  LogSessionConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  LogSessionConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
   ::Uts::ErrorCode::type destroyLogSession();
  int32_t send_destroyLogSession();
   ::Uts::ErrorCode::type recv_destroyLogSession(const int32_t seqid);
  void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return);
  int32_t send_getDeviceList();
  void recv_getDeviceList(std::vector< ::Uts::DeviceInfo> & _return, const int32_t seqid);
  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle);
  int32_t send_getProtocolList(const int64_t deviceHandle);
  void recv_getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int32_t seqid);
  int64_t getDataPacketCount(const int64_t protocolHandle);
  int32_t send_getDataPacketCount(const int64_t protocolHandle);
  int64_t recv_getDataPacketCount(const int32_t seqid);
   ::Uts::ErrorCode::type createDataView(const std::string& viewName, const DataPacketFilter& filter, const PacketReturnConfig& returnConfig);
  int32_t send_createDataView(const std::string& viewName, const DataPacketFilter& filter, const PacketReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createDataView(const int32_t seqid);
   ::Uts::ErrorCode::type createDefaultDataView(const std::string& viewName, const std::vector<int64_t> & protocolHandleList, const PacketReturnConfig& returnConfig);
  int32_t send_createDefaultDataView(const std::string& viewName, const std::vector<int64_t> & protocolHandleList, const PacketReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createDefaultDataView(const int32_t seqid);
   ::Uts::ErrorCode::type createDataViewSet(const std::vector<DataViewInfo> & dataViewDefinitions);
  int32_t send_createDataViewSet(const std::vector<DataViewInfo> & dataViewDefinitions);
   ::Uts::ErrorCode::type recv_createDataViewSet(const int32_t seqid);
   ::Uts::ErrorCode::type removeDataView(const std::string& viewName);
  int32_t send_removeDataView(const std::string& viewName);
   ::Uts::ErrorCode::type recv_removeDataView(const int32_t seqid);
  int32_t getDataViewItemCount(const std::string& viewName);
  int32_t send_getDataViewItemCount(const std::string& viewName);
  int32_t recv_getDataViewItemCount(const int32_t seqid);
  void getDataViewItems(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets);
  int32_t send_getDataViewItems(const std::string& viewName, const PacketRange& packets);
  void recv_getDataViewItems(std::vector<DataPacket> & _return, const int32_t seqid);
   ::Uts::ErrorCode::type saveDataViewItemsByIndex(const std::string& viewName, const std::string& destinationFolder, const std::vector<int64_t> & dataViewIndexes);
  int32_t send_saveDataViewItemsByIndex(const std::string& viewName, const std::string& destinationFolder, const std::vector<int64_t> & dataViewIndexes);
   ::Uts::ErrorCode::type recv_saveDataViewItemsByIndex(const int32_t seqid);
   ::Uts::ErrorCode::type saveDataViewItemsByIndexWithFilenames(const std::string& viewName, const std::vector<int64_t> & dataViewIndexes, const std::map<int64_t, std::string> & logNamesByHandle);
  int32_t send_saveDataViewItemsByIndexWithFilenames(const std::string& viewName, const std::vector<int64_t> & dataViewIndexes, const std::map<int64_t, std::string> & logNamesByHandle);
   ::Uts::ErrorCode::type recv_saveDataViewItemsByIndexWithFilenames(const int32_t seqid);
  void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder);
  int32_t send_saveLogFiles(const std::string& saveFolder);
  void recv_saveLogFiles(std::vector<std::string> & _return, const int32_t seqid);
  void getDurationByProtocol(std::string& _return, const int64_t protocolHandle);
  int32_t send_getDurationByProtocol(const int64_t protocolHandle);
  void recv_getDurationByProtocol(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type updatePacketFilters(const std::string& viewName, const DataPacketFilter& filter, const ViewConfigurationUpdate::type updateType);
  int32_t send_updatePacketFilters(const std::string& viewName, const DataPacketFilter& filter, const ViewConfigurationUpdate::type updateType);
   ::Uts::ErrorCode::type recv_updatePacketFilters(const int32_t seqid);
   ::Uts::ErrorCode::type updatePacketReturnConfig(const std::string& viewName, const PacketReturnConfig& returnConfig);
  int32_t send_updatePacketReturnConfig(const std::string& viewName, const PacketReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_updatePacketReturnConfig(const int32_t seqid);
  void getAvailablePacketIds(DataPacketFilter& _return, const int64_t protocolHandle);
  int32_t send_getAvailablePacketIds(const int64_t protocolHandle);
  void recv_getAvailablePacketIds(DataPacketFilter& _return, const int32_t seqid);
  void getLogSessionInformation(LogSessionInformation& _return, const std::set<int64_t> & protocolHandle);
  int32_t send_getLogSessionInformation(const std::set<int64_t> & protocolHandle);
  void recv_getLogSessionInformation(LogSessionInformation& _return, const int32_t seqid);
  void loadQShrinkFile(const int64_t protocolHandle, const std::string& pathName);
  int32_t send_loadQShrinkFile(const int64_t protocolHandle, const std::string& pathName);
  void recv_loadQShrinkFile(const int32_t seqid);
  int64_t getDataViewItemIndex(const std::string& viewName, const int64_t sessionIndex);
  int32_t send_getDataViewItemIndex(const std::string& viewName, const int64_t sessionIndex);
  int64_t recv_getDataViewItemIndex(const int32_t seqid);
  int64_t getTimeStampTodAdjustedByDataviewIndexForAnnotations(const std::string& viewName, const int64_t dataviewIndex);
  int32_t send_getTimeStampTodAdjustedByDataviewIndexForAnnotations(const std::string& viewName, const int64_t dataviewIndex);
  int64_t recv_getTimeStampTodAdjustedByDataviewIndexForAnnotations(const int32_t seqid);
  void getDataViewItemsForConfiguration(std::vector<DataPacket> & _return, const std::string& viewName, const PacketRange& packets, const PacketReturnConfig& returnConfig);
  int32_t send_getDataViewItemsForConfiguration(const std::string& viewName, const PacketRange& packets, const PacketReturnConfig& returnConfig);
  void recv_getDataViewItemsForConfiguration(std::vector<DataPacket> & _return, const int32_t seqid);
  void getClientSessionInfo(ClientSessionInfo& _return);
  int32_t send_getClientSessionInfo();
  void recv_getClientSessionInfo(ClientSessionInfo& _return, const int32_t seqid);
   ::Uts::ErrorCode::type createSubDataView(const std::string& viewName, const std::string& parentViewName, const DataPacketFilter& filter, const PacketRange& packets, const PacketReturnConfig& returnConfig);
  int32_t send_createSubDataView(const std::string& viewName, const std::string& parentViewName, const DataPacketFilter& filter, const PacketRange& packets, const PacketReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createSubDataView(const int32_t seqid);
   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::WcdmaProtocolRevision::type revision);
  int32_t send_setWcdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::WcdmaProtocolRevision::type revision);
   ::Uts::ErrorCode::type recv_setWcdmaProtocolRevision(const int32_t seqid);
   ::Uts::ErrorCode::type setCdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::CdmaProtocolRevision::type revision);
  int32_t send_setCdmaProtocolRevision(const int64_t protocolHandle, const  ::Uts::CdmaProtocolRevision::type revision);
   ::Uts::ErrorCode::type recv_setCdmaProtocolRevision(const int32_t seqid);
   ::Uts::ErrorCode::type setPilotInc(const int64_t protocolHandle, const int16_t pilotInc);
  int32_t send_setPilotInc(const int64_t protocolHandle, const int16_t pilotInc);
   ::Uts::ErrorCode::type recv_setPilotInc(const int32_t seqid);
  int16_t getBandClass(const int64_t protocolHandle, const int64_t protocolIndex);
  int32_t send_getBandClass(const int64_t protocolHandle, const int64_t protocolIndex);
  int16_t recv_getBandClass(const int32_t seqid);
   ::Uts::CdmaProtocolRevision::type getCdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex);
  int32_t send_getCdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex);
   ::Uts::CdmaProtocolRevision::type recv_getCdmaProtocolRevision(const int32_t seqid);
  int16_t getModel(const int64_t protocolHandle, const int64_t protocolIndex);
  int32_t send_getModel(const int64_t protocolHandle, const int64_t protocolIndex);
  int16_t recv_getModel(const int32_t seqid);
   ::Uts::WcdmaProtocolRevision::type getWcdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex);
  int32_t send_getWcdmaProtocolRevision(const int64_t protocolHandle, const int64_t protocolIndex);
   ::Uts::WcdmaProtocolRevision::type recv_getWcdmaProtocolRevision(const int32_t seqid);
  void getDecryptionKeyStatus(std::vector< ::Uts::KeyInfo> & _return, const int64_t protocolHandle);
  int32_t send_getDecryptionKeyStatus(const int64_t protocolHandle);
  void recv_getDecryptionKeyStatus(std::vector< ::Uts::KeyInfo> & _return, const int32_t seqid);
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
