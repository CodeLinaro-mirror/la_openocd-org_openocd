/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DeviceManager_H
#define DeviceManager_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "DeviceManager_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class DeviceManagerIf {
 public:
  virtual ~DeviceManagerIf() {}
  virtual void getLastError( ::Uts::ErrorType& _return) = 0;
  virtual void getServicesList(std::vector<std::string> & _return) = 0;
  virtual void getDevicesForService(std::vector<int64_t> & _return, const std::string& serviceName) = 0;
  virtual void getServicesForDevice(std::vector<std::string> & _return, const int64_t deviceHandle) = 0;
  virtual void createService(std::string& _return, const std::string& serviceName, const int64_t deviceHandle) = 0;
  virtual void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return) = 0;
  virtual int64_t getDeviceHandleFromProtocol(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type mergeDevice(const int64_t sourceDeviceHandle, const int64_t destinationDeviceHandle) = 0;
  virtual void getDeviceBuildId( ::Uts::BuildInfo& _return, const int64_t deviceHandle) = 0;
  virtual void getDeviceImageInfoByProtocol(std::vector< ::Uts::ImageInfo> & _return, const int64_t protocolHandle) = 0;
  virtual void getChipName(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle) = 0;
  virtual  ::Uts::DeviceMode::type getDeviceMode(const int64_t deviceHandle) = 0;
  virtual void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle) = 0;
  virtual void getActiveLogSession(std::string& _return) = 0;
  virtual  ::Uts::ErrorCode::type overrideUnknownProtocol(const int64_t protocolHandle, const  ::Uts::ProtocolType::type newType) = 0;
  virtual void addTcpConnection( ::Uts::ProtocolInfo& _return, const int64_t deviceHandle, const  ::Uts::ProtocolType::type protocolType, const bool bIsClient, const std::string& description, const std::string& host, const int32_t port) = 0;
  virtual void addTcpConnectionWithOptions( ::Uts::ProtocolInfo& _return, const std::string& host, const int32_t port, const  ::Uts::TcpOptions& options) = 0;
  virtual  ::Uts::ErrorCode::type removeTcpConnection(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type startTcpServer(const  ::Uts::ProtocolType::type protocolType, const int32_t port) = 0;
  virtual  ::Uts::ErrorCode::type startTcpServerWithOptions(const int32_t port, const  ::Uts::TcpOptions& options) = 0;
  virtual  ::Uts::ErrorCode::type stopTcpServer(const int32_t port) = 0;
  virtual void getTcpServerList(std::vector<int32_t> & _return) = 0;
  virtual  ::Uts::ErrorCode::type startLogging() = 0;
  virtual  ::Uts::ErrorCode::type resetLogFiles() = 0;
  virtual void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder) = 0;
  virtual void saveLogFilesWithFilenames(std::vector<std::string> & _return, const std::map<int64_t, std::string> & logNameConfig) = 0;
  virtual int64_t getCurrentLogFileSize(const int64_t protocolHandle) = 0;
  virtual void openLogSession(std::string& _return, const std::vector<std::string> & logFiles) = 0;
  virtual void attachToLogSession(std::string& _return, const int32_t clientId, const std::string& logSession) = 0;
  virtual  ::Uts::ErrorCode::type logAnnotation(const std::string& annotation, const int64_t messageId, const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type resetPhone(const int64_t deviceHandle, const int32_t resetTimeout) = 0;
  virtual  ::Uts::ErrorCode::type resetPhoneByProtocol(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t resetTimeout) = 0;
  virtual  ::Uts::ErrorCode::type restartQmiReadyScan(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type setOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle, const OperatingMode::type mode) = 0;
  virtual void getThroughputStatistics( ::Uts::RxTxInfo& _return, const int64_t protocolHandle) = 0;
  virtual int32_t getEsn(const int64_t deviceHandle, const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type setEsn(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t esn) = 0;
  virtual void getImei(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId) = 0;
  virtual  ::Uts::ErrorCode::type setImei(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& imei, const int32_t subscriptionId) = 0;
  virtual int64_t getMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId) = 0;
  virtual  ::Uts::ErrorCode::type setMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int64_t meid, const int32_t subscriptionId) = 0;
  virtual void checkSpc(SpcStatus& _return, const int64_t deviceHandle, const int64_t protocolHandle, const std::string& spc) = 0;
  virtual void getOperatingMode(OperatingModeInfo& _return, const int64_t deviceHandle, const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type transferImageBhi(const std::string& programmerPath) = 0;
  virtual void transferFileToDevice( ::Uts::TransferFileResult& _return, const std::string& hostPath, const std::string& devicePath, const  ::Uts::TransferFileOptions& options) = 0;
  virtual void transferFileToHost( ::Uts::TransferFileResult& _return, const std::string& devicePath, const std::string& hostPath, const  ::Uts::TransferFileOptions& options) = 0;
  virtual void getProtocolLockStatus( ::Uts::LockStatus& _return, const int64_t protocolHandle) = 0;
  virtual void getDeviceUsageIndicators( ::Uts::UsageIndicators& _return, const int64_t deviceHandle) = 0;
  virtual  ::Uts::ErrorCode::type enableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas, const  ::Uts::LogOptions& options) = 0;
  virtual  ::Uts::ErrorCode::type disableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas) = 0;
  virtual  ::Uts::ErrorCode::type enableProtocolLog(const int64_t protocolHandle, const  ::Uts::LogOptions& options) = 0;
  virtual  ::Uts::ErrorCode::type disableProtocolLog(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type configureProtocol(const  ::Uts::ProtocolConfiguration& protocolConfiguration) = 0;
  virtual void getProtocolConfiguration( ::Uts::ProtocolConfigurationResult& _return, const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type enableProtocolDataMonitoring(const std::vector<int64_t> & protocolHandleList, const bool enable) = 0;
  virtual  ::Uts::ErrorCode::type enableDeviceDataMonitoring(const std::vector<int64_t> & deviceHandleList, const bool enable) = 0;
  virtual  ::Uts::ErrorCode::type enableDevicePriority(const std::vector<int64_t> & deviceHandleList, const bool enable) = 0;
  virtual  ::Uts::ErrorCode::type configParameter(const std::string& name, const std::string& value) = 0;
  virtual int32_t getRegistrationPort() = 0;
};

class DeviceManagerIfFactory {
 public:
  typedef DeviceManagerIf Handler;

  virtual ~DeviceManagerIfFactory() {}

  virtual DeviceManagerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(DeviceManagerIf* /* handler */) = 0;
};

class DeviceManagerIfSingletonFactory : virtual public DeviceManagerIfFactory {
 public:
  DeviceManagerIfSingletonFactory(const ::std::shared_ptr<DeviceManagerIf>& iface) : iface_(iface) {}
  virtual ~DeviceManagerIfSingletonFactory() {}

  virtual DeviceManagerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(DeviceManagerIf* /* handler */) {}

 protected:
  ::std::shared_ptr<DeviceManagerIf> iface_;
};

class DeviceManagerNull : virtual public DeviceManagerIf {
 public:
  virtual ~DeviceManagerNull() {}
  void getLastError( ::Uts::ErrorType& /* _return */) {
    return;
  }
  void getServicesList(std::vector<std::string> & /* _return */) {
    return;
  }
  void getDevicesForService(std::vector<int64_t> & /* _return */, const std::string& /* serviceName */) {
    return;
  }
  void getServicesForDevice(std::vector<std::string> & /* _return */, const int64_t /* deviceHandle */) {
    return;
  }
  void createService(std::string& /* _return */, const std::string& /* serviceName */, const int64_t /* deviceHandle */) {
    return;
  }
  void getDeviceList(std::vector< ::Uts::DeviceInfo> & /* _return */) {
    return;
  }
  int64_t getDeviceHandleFromProtocol(const int64_t /* protocolHandle */) {
    int64_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type mergeDevice(const int64_t /* sourceDeviceHandle */, const int64_t /* destinationDeviceHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getDeviceBuildId( ::Uts::BuildInfo& /* _return */, const int64_t /* deviceHandle */) {
    return;
  }
  void getDeviceImageInfoByProtocol(std::vector< ::Uts::ImageInfo> & /* _return */, const int64_t /* protocolHandle */) {
    return;
  }
  void getChipName(std::string& /* _return */, const int64_t /* deviceHandle */, const int64_t /* protocolHandle */) {
    return;
  }
   ::Uts::DeviceMode::type getDeviceMode(const int64_t /* deviceHandle */) {
     ::Uts::DeviceMode::type _return = ( ::Uts::DeviceMode::type)0;
    return _return;
  }
  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & /* _return */, const int64_t /* deviceHandle */) {
    return;
  }
  void getActiveLogSession(std::string& /* _return */) {
    return;
  }
   ::Uts::ErrorCode::type overrideUnknownProtocol(const int64_t /* protocolHandle */, const  ::Uts::ProtocolType::type /* newType */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void addTcpConnection( ::Uts::ProtocolInfo& /* _return */, const int64_t /* deviceHandle */, const  ::Uts::ProtocolType::type /* protocolType */, const bool /* bIsClient */, const std::string& /* description */, const std::string& /* host */, const int32_t /* port */) {
    return;
  }
  void addTcpConnectionWithOptions( ::Uts::ProtocolInfo& /* _return */, const std::string& /* host */, const int32_t /* port */, const  ::Uts::TcpOptions& /* options */) {
    return;
  }
   ::Uts::ErrorCode::type removeTcpConnection(const int64_t /* protocolHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type startTcpServer(const  ::Uts::ProtocolType::type /* protocolType */, const int32_t /* port */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type startTcpServerWithOptions(const int32_t /* port */, const  ::Uts::TcpOptions& /* options */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type stopTcpServer(const int32_t /* port */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getTcpServerList(std::vector<int32_t> & /* _return */) {
    return;
  }
   ::Uts::ErrorCode::type startLogging() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type resetLogFiles() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void saveLogFiles(std::vector<std::string> & /* _return */, const std::string& /* saveFolder */) {
    return;
  }
  void saveLogFilesWithFilenames(std::vector<std::string> & /* _return */, const std::map<int64_t, std::string> & /* logNameConfig */) {
    return;
  }
  int64_t getCurrentLogFileSize(const int64_t /* protocolHandle */) {
    int64_t _return = 0;
    return _return;
  }
  void openLogSession(std::string& /* _return */, const std::vector<std::string> & /* logFiles */) {
    return;
  }
  void attachToLogSession(std::string& /* _return */, const int32_t /* clientId */, const std::string& /* logSession */) {
    return;
  }
   ::Uts::ErrorCode::type logAnnotation(const std::string& /* annotation */, const int64_t /* messageId */, const int64_t /* protocolHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type resetPhone(const int64_t /* deviceHandle */, const int32_t /* resetTimeout */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type resetPhoneByProtocol(const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const int32_t /* resetTimeout */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type restartQmiReadyScan(const int64_t /* protocolHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setOperatingMode(const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const OperatingMode::type /* mode */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getThroughputStatistics( ::Uts::RxTxInfo& /* _return */, const int64_t /* protocolHandle */) {
    return;
  }
  int32_t getEsn(const int64_t /* deviceHandle */, const int64_t /* protocolHandle */) {
    int32_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type setEsn(const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const int32_t /* esn */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getImei(std::string& /* _return */, const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const int32_t /* subscriptionId */) {
    return;
  }
   ::Uts::ErrorCode::type setImei(const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const std::string& /* imei */, const int32_t /* subscriptionId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  int64_t getMeid(const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const int32_t /* subscriptionId */) {
    int64_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type setMeid(const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const int64_t /* meid */, const int32_t /* subscriptionId */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void checkSpc(SpcStatus& /* _return */, const int64_t /* deviceHandle */, const int64_t /* protocolHandle */, const std::string& /* spc */) {
    return;
  }
  void getOperatingMode(OperatingModeInfo& /* _return */, const int64_t /* deviceHandle */, const int64_t /* protocolHandle */) {
    return;
  }
   ::Uts::ErrorCode::type transferImageBhi(const std::string& /* programmerPath */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void transferFileToDevice( ::Uts::TransferFileResult& /* _return */, const std::string& /* hostPath */, const std::string& /* devicePath */, const  ::Uts::TransferFileOptions& /* options */) {
    return;
  }
  void transferFileToHost( ::Uts::TransferFileResult& /* _return */, const std::string& /* devicePath */, const std::string& /* hostPath */, const  ::Uts::TransferFileOptions& /* options */) {
    return;
  }
  void getProtocolLockStatus( ::Uts::LockStatus& /* _return */, const int64_t /* protocolHandle */) {
    return;
  }
  void getDeviceUsageIndicators( ::Uts::UsageIndicators& /* _return */, const int64_t /* deviceHandle */) {
    return;
  }
   ::Uts::ErrorCode::type enableFunctionLog(const int64_t /* deviceHandle */, const std::vector< ::Uts::FunctionArea::type> & /* areas */, const  ::Uts::LogOptions& /* options */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type disableFunctionLog(const int64_t /* deviceHandle */, const std::vector< ::Uts::FunctionArea::type> & /* areas */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type enableProtocolLog(const int64_t /* protocolHandle */, const  ::Uts::LogOptions& /* options */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type disableProtocolLog(const int64_t /* protocolHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type configureProtocol(const  ::Uts::ProtocolConfiguration& /* protocolConfiguration */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getProtocolConfiguration( ::Uts::ProtocolConfigurationResult& /* _return */, const int64_t /* protocolHandle */) {
    return;
  }
   ::Uts::ErrorCode::type enableProtocolDataMonitoring(const std::vector<int64_t> & /* protocolHandleList */, const bool /* enable */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type enableDeviceDataMonitoring(const std::vector<int64_t> & /* deviceHandleList */, const bool /* enable */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type enableDevicePriority(const std::vector<int64_t> & /* deviceHandleList */, const bool /* enable */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type configParameter(const std::string& /* name */, const std::string& /* value */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  int32_t getRegistrationPort() {
    int32_t _return = 0;
    return _return;
  }
};


class DeviceManager_getLastError_args {
 public:

  DeviceManager_getLastError_args(const DeviceManager_getLastError_args&);
  DeviceManager_getLastError_args& operator=(const DeviceManager_getLastError_args&);
  DeviceManager_getLastError_args() {
  }

  virtual ~DeviceManager_getLastError_args() noexcept;

  bool operator == (const DeviceManager_getLastError_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceManager_getLastError_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getLastError_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getLastError_pargs {
 public:


  virtual ~DeviceManager_getLastError_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getLastError_result__isset {
  _DeviceManager_getLastError_result__isset() : success(false) {}
  bool success :1;
} _DeviceManager_getLastError_result__isset;

class DeviceManager_getLastError_result {
 public:

  DeviceManager_getLastError_result(const DeviceManager_getLastError_result&);
  DeviceManager_getLastError_result& operator=(const DeviceManager_getLastError_result&);
  DeviceManager_getLastError_result() {
  }

  virtual ~DeviceManager_getLastError_result() noexcept;
   ::Uts::ErrorType success;

  _DeviceManager_getLastError_result__isset __isset;

  void __set_success(const  ::Uts::ErrorType& val);

  bool operator == (const DeviceManager_getLastError_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getLastError_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getLastError_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getLastError_presult__isset {
  _DeviceManager_getLastError_presult__isset() : success(false) {}
  bool success :1;
} _DeviceManager_getLastError_presult__isset;

class DeviceManager_getLastError_presult {
 public:


  virtual ~DeviceManager_getLastError_presult() noexcept;
   ::Uts::ErrorType* success;

  _DeviceManager_getLastError_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceManager_getServicesList_args {
 public:

  DeviceManager_getServicesList_args(const DeviceManager_getServicesList_args&);
  DeviceManager_getServicesList_args& operator=(const DeviceManager_getServicesList_args&);
  DeviceManager_getServicesList_args() {
  }

  virtual ~DeviceManager_getServicesList_args() noexcept;

  bool operator == (const DeviceManager_getServicesList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceManager_getServicesList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getServicesList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getServicesList_pargs {
 public:


  virtual ~DeviceManager_getServicesList_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getServicesList_result__isset {
  _DeviceManager_getServicesList_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getServicesList_result__isset;

class DeviceManager_getServicesList_result {
 public:

  DeviceManager_getServicesList_result(const DeviceManager_getServicesList_result&);
  DeviceManager_getServicesList_result& operator=(const DeviceManager_getServicesList_result&);
  DeviceManager_getServicesList_result() {
  }

  virtual ~DeviceManager_getServicesList_result() noexcept;
  std::vector<std::string>  success;
   ::Uts::AppException e;

  _DeviceManager_getServicesList_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getServicesList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getServicesList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getServicesList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getServicesList_presult__isset {
  _DeviceManager_getServicesList_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getServicesList_presult__isset;

class DeviceManager_getServicesList_presult {
 public:


  virtual ~DeviceManager_getServicesList_presult() noexcept;
  std::vector<std::string> * success;
   ::Uts::AppException e;

  _DeviceManager_getServicesList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getDevicesForService_args__isset {
  _DeviceManager_getDevicesForService_args__isset() : serviceName(false) {}
  bool serviceName :1;
} _DeviceManager_getDevicesForService_args__isset;

class DeviceManager_getDevicesForService_args {
 public:

  DeviceManager_getDevicesForService_args(const DeviceManager_getDevicesForService_args&);
  DeviceManager_getDevicesForService_args& operator=(const DeviceManager_getDevicesForService_args&);
  DeviceManager_getDevicesForService_args() : serviceName() {
  }

  virtual ~DeviceManager_getDevicesForService_args() noexcept;
  std::string serviceName;

  _DeviceManager_getDevicesForService_args__isset __isset;

  void __set_serviceName(const std::string& val);

  bool operator == (const DeviceManager_getDevicesForService_args & rhs) const
  {
    if (!(serviceName == rhs.serviceName))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDevicesForService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDevicesForService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getDevicesForService_pargs {
 public:


  virtual ~DeviceManager_getDevicesForService_pargs() noexcept;
  const std::string* serviceName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDevicesForService_result__isset {
  _DeviceManager_getDevicesForService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDevicesForService_result__isset;

class DeviceManager_getDevicesForService_result {
 public:

  DeviceManager_getDevicesForService_result(const DeviceManager_getDevicesForService_result&);
  DeviceManager_getDevicesForService_result& operator=(const DeviceManager_getDevicesForService_result&);
  DeviceManager_getDevicesForService_result() {
  }

  virtual ~DeviceManager_getDevicesForService_result() noexcept;
  std::vector<int64_t>  success;
   ::Uts::AppException e;

  _DeviceManager_getDevicesForService_result__isset __isset;

  void __set_success(const std::vector<int64_t> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getDevicesForService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDevicesForService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDevicesForService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDevicesForService_presult__isset {
  _DeviceManager_getDevicesForService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDevicesForService_presult__isset;

class DeviceManager_getDevicesForService_presult {
 public:


  virtual ~DeviceManager_getDevicesForService_presult() noexcept;
  std::vector<int64_t> * success;
   ::Uts::AppException e;

  _DeviceManager_getDevicesForService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getServicesForDevice_args__isset {
  _DeviceManager_getServicesForDevice_args__isset() : deviceHandle(false) {}
  bool deviceHandle :1;
} _DeviceManager_getServicesForDevice_args__isset;

class DeviceManager_getServicesForDevice_args {
 public:

  DeviceManager_getServicesForDevice_args(const DeviceManager_getServicesForDevice_args&);
  DeviceManager_getServicesForDevice_args& operator=(const DeviceManager_getServicesForDevice_args&);
  DeviceManager_getServicesForDevice_args() : deviceHandle(0) {
  }

  virtual ~DeviceManager_getServicesForDevice_args() noexcept;
  int64_t deviceHandle;

  _DeviceManager_getServicesForDevice_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  bool operator == (const DeviceManager_getServicesForDevice_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getServicesForDevice_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getServicesForDevice_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getServicesForDevice_pargs {
 public:


  virtual ~DeviceManager_getServicesForDevice_pargs() noexcept;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getServicesForDevice_result__isset {
  _DeviceManager_getServicesForDevice_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getServicesForDevice_result__isset;

class DeviceManager_getServicesForDevice_result {
 public:

  DeviceManager_getServicesForDevice_result(const DeviceManager_getServicesForDevice_result&);
  DeviceManager_getServicesForDevice_result& operator=(const DeviceManager_getServicesForDevice_result&);
  DeviceManager_getServicesForDevice_result() {
  }

  virtual ~DeviceManager_getServicesForDevice_result() noexcept;
  std::vector<std::string>  success;
   ::Uts::AppException e;

  _DeviceManager_getServicesForDevice_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getServicesForDevice_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getServicesForDevice_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getServicesForDevice_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getServicesForDevice_presult__isset {
  _DeviceManager_getServicesForDevice_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getServicesForDevice_presult__isset;

class DeviceManager_getServicesForDevice_presult {
 public:


  virtual ~DeviceManager_getServicesForDevice_presult() noexcept;
  std::vector<std::string> * success;
   ::Uts::AppException e;

  _DeviceManager_getServicesForDevice_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_createService_args__isset {
  _DeviceManager_createService_args__isset() : serviceName(false), deviceHandle(false) {}
  bool serviceName :1;
  bool deviceHandle :1;
} _DeviceManager_createService_args__isset;

class DeviceManager_createService_args {
 public:

  DeviceManager_createService_args(const DeviceManager_createService_args&);
  DeviceManager_createService_args& operator=(const DeviceManager_createService_args&);
  DeviceManager_createService_args() : serviceName(), deviceHandle(0) {
  }

  virtual ~DeviceManager_createService_args() noexcept;
  std::string serviceName;
  int64_t deviceHandle;

  _DeviceManager_createService_args__isset __isset;

  void __set_serviceName(const std::string& val);

  void __set_deviceHandle(const int64_t val);

  bool operator == (const DeviceManager_createService_args & rhs) const
  {
    if (!(serviceName == rhs.serviceName))
      return false;
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_createService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_createService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_createService_pargs {
 public:


  virtual ~DeviceManager_createService_pargs() noexcept;
  const std::string* serviceName;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_createService_result__isset {
  _DeviceManager_createService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_createService_result__isset;

class DeviceManager_createService_result {
 public:

  DeviceManager_createService_result(const DeviceManager_createService_result&);
  DeviceManager_createService_result& operator=(const DeviceManager_createService_result&);
  DeviceManager_createService_result() : success() {
  }

  virtual ~DeviceManager_createService_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceManager_createService_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_createService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_createService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_createService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_createService_presult__isset {
  _DeviceManager_createService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_createService_presult__isset;

class DeviceManager_createService_presult {
 public:


  virtual ~DeviceManager_createService_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceManager_createService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceManager_getDeviceList_args {
 public:

  DeviceManager_getDeviceList_args(const DeviceManager_getDeviceList_args&);
  DeviceManager_getDeviceList_args& operator=(const DeviceManager_getDeviceList_args&);
  DeviceManager_getDeviceList_args() {
  }

  virtual ~DeviceManager_getDeviceList_args() noexcept;

  bool operator == (const DeviceManager_getDeviceList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceManager_getDeviceList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getDeviceList_pargs {
 public:


  virtual ~DeviceManager_getDeviceList_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceList_result__isset {
  _DeviceManager_getDeviceList_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceList_result__isset;

class DeviceManager_getDeviceList_result {
 public:

  DeviceManager_getDeviceList_result(const DeviceManager_getDeviceList_result&);
  DeviceManager_getDeviceList_result& operator=(const DeviceManager_getDeviceList_result&);
  DeviceManager_getDeviceList_result() {
  }

  virtual ~DeviceManager_getDeviceList_result() noexcept;
  std::vector< ::Uts::DeviceInfo>  success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceList_result__isset __isset;

  void __set_success(const std::vector< ::Uts::DeviceInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getDeviceList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceList_presult__isset {
  _DeviceManager_getDeviceList_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceList_presult__isset;

class DeviceManager_getDeviceList_presult {
 public:


  virtual ~DeviceManager_getDeviceList_presult() noexcept;
  std::vector< ::Uts::DeviceInfo> * success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getDeviceHandleFromProtocol_args__isset {
  _DeviceManager_getDeviceHandleFromProtocol_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_getDeviceHandleFromProtocol_args__isset;

class DeviceManager_getDeviceHandleFromProtocol_args {
 public:

  DeviceManager_getDeviceHandleFromProtocol_args(const DeviceManager_getDeviceHandleFromProtocol_args&);
  DeviceManager_getDeviceHandleFromProtocol_args& operator=(const DeviceManager_getDeviceHandleFromProtocol_args&);
  DeviceManager_getDeviceHandleFromProtocol_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_getDeviceHandleFromProtocol_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_getDeviceHandleFromProtocol_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getDeviceHandleFromProtocol_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceHandleFromProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceHandleFromProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getDeviceHandleFromProtocol_pargs {
 public:


  virtual ~DeviceManager_getDeviceHandleFromProtocol_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceHandleFromProtocol_result__isset {
  _DeviceManager_getDeviceHandleFromProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceHandleFromProtocol_result__isset;

class DeviceManager_getDeviceHandleFromProtocol_result {
 public:

  DeviceManager_getDeviceHandleFromProtocol_result(const DeviceManager_getDeviceHandleFromProtocol_result&);
  DeviceManager_getDeviceHandleFromProtocol_result& operator=(const DeviceManager_getDeviceHandleFromProtocol_result&);
  DeviceManager_getDeviceHandleFromProtocol_result() : success(0) {
  }

  virtual ~DeviceManager_getDeviceHandleFromProtocol_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceHandleFromProtocol_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getDeviceHandleFromProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceHandleFromProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceHandleFromProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceHandleFromProtocol_presult__isset {
  _DeviceManager_getDeviceHandleFromProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceHandleFromProtocol_presult__isset;

class DeviceManager_getDeviceHandleFromProtocol_presult {
 public:


  virtual ~DeviceManager_getDeviceHandleFromProtocol_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceHandleFromProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_mergeDevice_args__isset {
  _DeviceManager_mergeDevice_args__isset() : sourceDeviceHandle(false), destinationDeviceHandle(false) {}
  bool sourceDeviceHandle :1;
  bool destinationDeviceHandle :1;
} _DeviceManager_mergeDevice_args__isset;

class DeviceManager_mergeDevice_args {
 public:

  DeviceManager_mergeDevice_args(const DeviceManager_mergeDevice_args&);
  DeviceManager_mergeDevice_args& operator=(const DeviceManager_mergeDevice_args&);
  DeviceManager_mergeDevice_args() : sourceDeviceHandle(0), destinationDeviceHandle(0) {
  }

  virtual ~DeviceManager_mergeDevice_args() noexcept;
  int64_t sourceDeviceHandle;
  int64_t destinationDeviceHandle;

  _DeviceManager_mergeDevice_args__isset __isset;

  void __set_sourceDeviceHandle(const int64_t val);

  void __set_destinationDeviceHandle(const int64_t val);

  bool operator == (const DeviceManager_mergeDevice_args & rhs) const
  {
    if (!(sourceDeviceHandle == rhs.sourceDeviceHandle))
      return false;
    if (!(destinationDeviceHandle == rhs.destinationDeviceHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_mergeDevice_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_mergeDevice_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_mergeDevice_pargs {
 public:


  virtual ~DeviceManager_mergeDevice_pargs() noexcept;
  const int64_t* sourceDeviceHandle;
  const int64_t* destinationDeviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_mergeDevice_result__isset {
  _DeviceManager_mergeDevice_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_mergeDevice_result__isset;

class DeviceManager_mergeDevice_result {
 public:

  DeviceManager_mergeDevice_result(const DeviceManager_mergeDevice_result&);
  DeviceManager_mergeDevice_result& operator=(const DeviceManager_mergeDevice_result&);
  DeviceManager_mergeDevice_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_mergeDevice_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_mergeDevice_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_mergeDevice_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_mergeDevice_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_mergeDevice_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_mergeDevice_presult__isset {
  _DeviceManager_mergeDevice_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_mergeDevice_presult__isset;

class DeviceManager_mergeDevice_presult {
 public:


  virtual ~DeviceManager_mergeDevice_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_mergeDevice_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getDeviceBuildId_args__isset {
  _DeviceManager_getDeviceBuildId_args__isset() : deviceHandle(false) {}
  bool deviceHandle :1;
} _DeviceManager_getDeviceBuildId_args__isset;

class DeviceManager_getDeviceBuildId_args {
 public:

  DeviceManager_getDeviceBuildId_args(const DeviceManager_getDeviceBuildId_args&);
  DeviceManager_getDeviceBuildId_args& operator=(const DeviceManager_getDeviceBuildId_args&);
  DeviceManager_getDeviceBuildId_args() : deviceHandle(0) {
  }

  virtual ~DeviceManager_getDeviceBuildId_args() noexcept;
  int64_t deviceHandle;

  _DeviceManager_getDeviceBuildId_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  bool operator == (const DeviceManager_getDeviceBuildId_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceBuildId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceBuildId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getDeviceBuildId_pargs {
 public:


  virtual ~DeviceManager_getDeviceBuildId_pargs() noexcept;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceBuildId_result__isset {
  _DeviceManager_getDeviceBuildId_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceBuildId_result__isset;

class DeviceManager_getDeviceBuildId_result {
 public:

  DeviceManager_getDeviceBuildId_result(const DeviceManager_getDeviceBuildId_result&);
  DeviceManager_getDeviceBuildId_result& operator=(const DeviceManager_getDeviceBuildId_result&);
  DeviceManager_getDeviceBuildId_result() {
  }

  virtual ~DeviceManager_getDeviceBuildId_result() noexcept;
   ::Uts::BuildInfo success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceBuildId_result__isset __isset;

  void __set_success(const  ::Uts::BuildInfo& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getDeviceBuildId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceBuildId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceBuildId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceBuildId_presult__isset {
  _DeviceManager_getDeviceBuildId_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceBuildId_presult__isset;

class DeviceManager_getDeviceBuildId_presult {
 public:


  virtual ~DeviceManager_getDeviceBuildId_presult() noexcept;
   ::Uts::BuildInfo* success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceBuildId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getDeviceImageInfoByProtocol_args__isset {
  _DeviceManager_getDeviceImageInfoByProtocol_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_getDeviceImageInfoByProtocol_args__isset;

class DeviceManager_getDeviceImageInfoByProtocol_args {
 public:

  DeviceManager_getDeviceImageInfoByProtocol_args(const DeviceManager_getDeviceImageInfoByProtocol_args&);
  DeviceManager_getDeviceImageInfoByProtocol_args& operator=(const DeviceManager_getDeviceImageInfoByProtocol_args&);
  DeviceManager_getDeviceImageInfoByProtocol_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_getDeviceImageInfoByProtocol_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_getDeviceImageInfoByProtocol_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getDeviceImageInfoByProtocol_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceImageInfoByProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceImageInfoByProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getDeviceImageInfoByProtocol_pargs {
 public:


  virtual ~DeviceManager_getDeviceImageInfoByProtocol_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceImageInfoByProtocol_result__isset {
  _DeviceManager_getDeviceImageInfoByProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceImageInfoByProtocol_result__isset;

class DeviceManager_getDeviceImageInfoByProtocol_result {
 public:

  DeviceManager_getDeviceImageInfoByProtocol_result(const DeviceManager_getDeviceImageInfoByProtocol_result&);
  DeviceManager_getDeviceImageInfoByProtocol_result& operator=(const DeviceManager_getDeviceImageInfoByProtocol_result&);
  DeviceManager_getDeviceImageInfoByProtocol_result() {
  }

  virtual ~DeviceManager_getDeviceImageInfoByProtocol_result() noexcept;
  std::vector< ::Uts::ImageInfo>  success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceImageInfoByProtocol_result__isset __isset;

  void __set_success(const std::vector< ::Uts::ImageInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getDeviceImageInfoByProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceImageInfoByProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceImageInfoByProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceImageInfoByProtocol_presult__isset {
  _DeviceManager_getDeviceImageInfoByProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceImageInfoByProtocol_presult__isset;

class DeviceManager_getDeviceImageInfoByProtocol_presult {
 public:


  virtual ~DeviceManager_getDeviceImageInfoByProtocol_presult() noexcept;
  std::vector< ::Uts::ImageInfo> * success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceImageInfoByProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getChipName_args__isset {
  _DeviceManager_getChipName_args__isset() : deviceHandle(false), protocolHandle(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
} _DeviceManager_getChipName_args__isset;

class DeviceManager_getChipName_args {
 public:

  DeviceManager_getChipName_args(const DeviceManager_getChipName_args&);
  DeviceManager_getChipName_args& operator=(const DeviceManager_getChipName_args&);
  DeviceManager_getChipName_args() : deviceHandle(0), protocolHandle(0) {
  }

  virtual ~DeviceManager_getChipName_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;

  _DeviceManager_getChipName_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getChipName_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getChipName_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getChipName_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getChipName_pargs {
 public:


  virtual ~DeviceManager_getChipName_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getChipName_result__isset {
  _DeviceManager_getChipName_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getChipName_result__isset;

class DeviceManager_getChipName_result {
 public:

  DeviceManager_getChipName_result(const DeviceManager_getChipName_result&);
  DeviceManager_getChipName_result& operator=(const DeviceManager_getChipName_result&);
  DeviceManager_getChipName_result() : success() {
  }

  virtual ~DeviceManager_getChipName_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceManager_getChipName_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getChipName_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getChipName_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getChipName_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getChipName_presult__isset {
  _DeviceManager_getChipName_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getChipName_presult__isset;

class DeviceManager_getChipName_presult {
 public:


  virtual ~DeviceManager_getChipName_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceManager_getChipName_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getDeviceMode_args__isset {
  _DeviceManager_getDeviceMode_args__isset() : deviceHandle(false) {}
  bool deviceHandle :1;
} _DeviceManager_getDeviceMode_args__isset;

class DeviceManager_getDeviceMode_args {
 public:

  DeviceManager_getDeviceMode_args(const DeviceManager_getDeviceMode_args&);
  DeviceManager_getDeviceMode_args& operator=(const DeviceManager_getDeviceMode_args&);
  DeviceManager_getDeviceMode_args() : deviceHandle(0) {
  }

  virtual ~DeviceManager_getDeviceMode_args() noexcept;
  int64_t deviceHandle;

  _DeviceManager_getDeviceMode_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  bool operator == (const DeviceManager_getDeviceMode_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceMode_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceMode_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getDeviceMode_pargs {
 public:


  virtual ~DeviceManager_getDeviceMode_pargs() noexcept;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceMode_result__isset {
  _DeviceManager_getDeviceMode_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceMode_result__isset;

class DeviceManager_getDeviceMode_result {
 public:

  DeviceManager_getDeviceMode_result(const DeviceManager_getDeviceMode_result&);
  DeviceManager_getDeviceMode_result& operator=(const DeviceManager_getDeviceMode_result&);
  DeviceManager_getDeviceMode_result() : success(( ::Uts::DeviceMode::type)0) {
  }

  virtual ~DeviceManager_getDeviceMode_result() noexcept;
   ::Uts::DeviceMode::type success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceMode_result__isset __isset;

  void __set_success(const  ::Uts::DeviceMode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getDeviceMode_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceMode_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceMode_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceMode_presult__isset {
  _DeviceManager_getDeviceMode_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceMode_presult__isset;

class DeviceManager_getDeviceMode_presult {
 public:


  virtual ~DeviceManager_getDeviceMode_presult() noexcept;
   ::Uts::DeviceMode::type* success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceMode_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getProtocolList_args__isset {
  _DeviceManager_getProtocolList_args__isset() : deviceHandle(false) {}
  bool deviceHandle :1;
} _DeviceManager_getProtocolList_args__isset;

class DeviceManager_getProtocolList_args {
 public:

  DeviceManager_getProtocolList_args(const DeviceManager_getProtocolList_args&);
  DeviceManager_getProtocolList_args& operator=(const DeviceManager_getProtocolList_args&);
  DeviceManager_getProtocolList_args() : deviceHandle(0) {
  }

  virtual ~DeviceManager_getProtocolList_args() noexcept;
  int64_t deviceHandle;

  _DeviceManager_getProtocolList_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  bool operator == (const DeviceManager_getProtocolList_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getProtocolList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getProtocolList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getProtocolList_pargs {
 public:


  virtual ~DeviceManager_getProtocolList_pargs() noexcept;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getProtocolList_result__isset {
  _DeviceManager_getProtocolList_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getProtocolList_result__isset;

class DeviceManager_getProtocolList_result {
 public:

  DeviceManager_getProtocolList_result(const DeviceManager_getProtocolList_result&);
  DeviceManager_getProtocolList_result& operator=(const DeviceManager_getProtocolList_result&);
  DeviceManager_getProtocolList_result() {
  }

  virtual ~DeviceManager_getProtocolList_result() noexcept;
  std::vector< ::Uts::ProtocolInfo>  success;
   ::Uts::AppException e;

  _DeviceManager_getProtocolList_result__isset __isset;

  void __set_success(const std::vector< ::Uts::ProtocolInfo> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getProtocolList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getProtocolList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getProtocolList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getProtocolList_presult__isset {
  _DeviceManager_getProtocolList_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getProtocolList_presult__isset;

class DeviceManager_getProtocolList_presult {
 public:


  virtual ~DeviceManager_getProtocolList_presult() noexcept;
  std::vector< ::Uts::ProtocolInfo> * success;
   ::Uts::AppException e;

  _DeviceManager_getProtocolList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceManager_getActiveLogSession_args {
 public:

  DeviceManager_getActiveLogSession_args(const DeviceManager_getActiveLogSession_args&);
  DeviceManager_getActiveLogSession_args& operator=(const DeviceManager_getActiveLogSession_args&);
  DeviceManager_getActiveLogSession_args() {
  }

  virtual ~DeviceManager_getActiveLogSession_args() noexcept;

  bool operator == (const DeviceManager_getActiveLogSession_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceManager_getActiveLogSession_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getActiveLogSession_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getActiveLogSession_pargs {
 public:


  virtual ~DeviceManager_getActiveLogSession_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getActiveLogSession_result__isset {
  _DeviceManager_getActiveLogSession_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getActiveLogSession_result__isset;

class DeviceManager_getActiveLogSession_result {
 public:

  DeviceManager_getActiveLogSession_result(const DeviceManager_getActiveLogSession_result&);
  DeviceManager_getActiveLogSession_result& operator=(const DeviceManager_getActiveLogSession_result&);
  DeviceManager_getActiveLogSession_result() : success() {
  }

  virtual ~DeviceManager_getActiveLogSession_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceManager_getActiveLogSession_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getActiveLogSession_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getActiveLogSession_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getActiveLogSession_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getActiveLogSession_presult__isset {
  _DeviceManager_getActiveLogSession_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getActiveLogSession_presult__isset;

class DeviceManager_getActiveLogSession_presult {
 public:


  virtual ~DeviceManager_getActiveLogSession_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceManager_getActiveLogSession_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_overrideUnknownProtocol_args__isset {
  _DeviceManager_overrideUnknownProtocol_args__isset() : protocolHandle(false), newType(false) {}
  bool protocolHandle :1;
  bool newType :1;
} _DeviceManager_overrideUnknownProtocol_args__isset;

class DeviceManager_overrideUnknownProtocol_args {
 public:

  DeviceManager_overrideUnknownProtocol_args(const DeviceManager_overrideUnknownProtocol_args&);
  DeviceManager_overrideUnknownProtocol_args& operator=(const DeviceManager_overrideUnknownProtocol_args&);
  DeviceManager_overrideUnknownProtocol_args() : protocolHandle(0), newType(( ::Uts::ProtocolType::type)0) {
  }

  virtual ~DeviceManager_overrideUnknownProtocol_args() noexcept;
  int64_t protocolHandle;
   ::Uts::ProtocolType::type newType;

  _DeviceManager_overrideUnknownProtocol_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_newType(const  ::Uts::ProtocolType::type val);

  bool operator == (const DeviceManager_overrideUnknownProtocol_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(newType == rhs.newType))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_overrideUnknownProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_overrideUnknownProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_overrideUnknownProtocol_pargs {
 public:


  virtual ~DeviceManager_overrideUnknownProtocol_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::ProtocolType::type* newType;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_overrideUnknownProtocol_result__isset {
  _DeviceManager_overrideUnknownProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_overrideUnknownProtocol_result__isset;

class DeviceManager_overrideUnknownProtocol_result {
 public:

  DeviceManager_overrideUnknownProtocol_result(const DeviceManager_overrideUnknownProtocol_result&);
  DeviceManager_overrideUnknownProtocol_result& operator=(const DeviceManager_overrideUnknownProtocol_result&);
  DeviceManager_overrideUnknownProtocol_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_overrideUnknownProtocol_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_overrideUnknownProtocol_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_overrideUnknownProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_overrideUnknownProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_overrideUnknownProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_overrideUnknownProtocol_presult__isset {
  _DeviceManager_overrideUnknownProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_overrideUnknownProtocol_presult__isset;

class DeviceManager_overrideUnknownProtocol_presult {
 public:


  virtual ~DeviceManager_overrideUnknownProtocol_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_overrideUnknownProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_addTcpConnection_args__isset {
  _DeviceManager_addTcpConnection_args__isset() : deviceHandle(false), protocolType(false), bIsClient(false), description(false), host(false), port(false) {}
  bool deviceHandle :1;
  bool protocolType :1;
  bool bIsClient :1;
  bool description :1;
  bool host :1;
  bool port :1;
} _DeviceManager_addTcpConnection_args__isset;

class DeviceManager_addTcpConnection_args {
 public:

  DeviceManager_addTcpConnection_args(const DeviceManager_addTcpConnection_args&);
  DeviceManager_addTcpConnection_args& operator=(const DeviceManager_addTcpConnection_args&);
  DeviceManager_addTcpConnection_args() : deviceHandle(0), protocolType(( ::Uts::ProtocolType::type)0), bIsClient(0), description(), host(), port(0) {
  }

  virtual ~DeviceManager_addTcpConnection_args() noexcept;
  int64_t deviceHandle;
   ::Uts::ProtocolType::type protocolType;
  bool bIsClient;
  std::string description;
  std::string host;
  int32_t port;

  _DeviceManager_addTcpConnection_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolType(const  ::Uts::ProtocolType::type val);

  void __set_bIsClient(const bool val);

  void __set_description(const std::string& val);

  void __set_host(const std::string& val);

  void __set_port(const int32_t val);

  bool operator == (const DeviceManager_addTcpConnection_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolType == rhs.protocolType))
      return false;
    if (!(bIsClient == rhs.bIsClient))
      return false;
    if (!(description == rhs.description))
      return false;
    if (!(host == rhs.host))
      return false;
    if (!(port == rhs.port))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_addTcpConnection_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_addTcpConnection_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_addTcpConnection_pargs {
 public:


  virtual ~DeviceManager_addTcpConnection_pargs() noexcept;
  const int64_t* deviceHandle;
  const  ::Uts::ProtocolType::type* protocolType;
  const bool* bIsClient;
  const std::string* description;
  const std::string* host;
  const int32_t* port;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_addTcpConnection_result__isset {
  _DeviceManager_addTcpConnection_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_addTcpConnection_result__isset;

class DeviceManager_addTcpConnection_result {
 public:

  DeviceManager_addTcpConnection_result(const DeviceManager_addTcpConnection_result&);
  DeviceManager_addTcpConnection_result& operator=(const DeviceManager_addTcpConnection_result&);
  DeviceManager_addTcpConnection_result() {
  }

  virtual ~DeviceManager_addTcpConnection_result() noexcept;
   ::Uts::ProtocolInfo success;
   ::Uts::AppException e;

  _DeviceManager_addTcpConnection_result__isset __isset;

  void __set_success(const  ::Uts::ProtocolInfo& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_addTcpConnection_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_addTcpConnection_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_addTcpConnection_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_addTcpConnection_presult__isset {
  _DeviceManager_addTcpConnection_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_addTcpConnection_presult__isset;

class DeviceManager_addTcpConnection_presult {
 public:


  virtual ~DeviceManager_addTcpConnection_presult() noexcept;
   ::Uts::ProtocolInfo* success;
   ::Uts::AppException e;

  _DeviceManager_addTcpConnection_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_addTcpConnectionWithOptions_args__isset {
  _DeviceManager_addTcpConnectionWithOptions_args__isset() : host(false), port(false), options(false) {}
  bool host :1;
  bool port :1;
  bool options :1;
} _DeviceManager_addTcpConnectionWithOptions_args__isset;

class DeviceManager_addTcpConnectionWithOptions_args {
 public:

  DeviceManager_addTcpConnectionWithOptions_args(const DeviceManager_addTcpConnectionWithOptions_args&);
  DeviceManager_addTcpConnectionWithOptions_args& operator=(const DeviceManager_addTcpConnectionWithOptions_args&);
  DeviceManager_addTcpConnectionWithOptions_args() : host(), port(0) {
  }

  virtual ~DeviceManager_addTcpConnectionWithOptions_args() noexcept;
  std::string host;
  int32_t port;
   ::Uts::TcpOptions options;

  _DeviceManager_addTcpConnectionWithOptions_args__isset __isset;

  void __set_host(const std::string& val);

  void __set_port(const int32_t val);

  void __set_options(const  ::Uts::TcpOptions& val);

  bool operator == (const DeviceManager_addTcpConnectionWithOptions_args & rhs) const
  {
    if (!(host == rhs.host))
      return false;
    if (!(port == rhs.port))
      return false;
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_addTcpConnectionWithOptions_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_addTcpConnectionWithOptions_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_addTcpConnectionWithOptions_pargs {
 public:


  virtual ~DeviceManager_addTcpConnectionWithOptions_pargs() noexcept;
  const std::string* host;
  const int32_t* port;
  const  ::Uts::TcpOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_addTcpConnectionWithOptions_result__isset {
  _DeviceManager_addTcpConnectionWithOptions_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_addTcpConnectionWithOptions_result__isset;

class DeviceManager_addTcpConnectionWithOptions_result {
 public:

  DeviceManager_addTcpConnectionWithOptions_result(const DeviceManager_addTcpConnectionWithOptions_result&);
  DeviceManager_addTcpConnectionWithOptions_result& operator=(const DeviceManager_addTcpConnectionWithOptions_result&);
  DeviceManager_addTcpConnectionWithOptions_result() {
  }

  virtual ~DeviceManager_addTcpConnectionWithOptions_result() noexcept;
   ::Uts::ProtocolInfo success;
   ::Uts::AppException e;

  _DeviceManager_addTcpConnectionWithOptions_result__isset __isset;

  void __set_success(const  ::Uts::ProtocolInfo& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_addTcpConnectionWithOptions_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_addTcpConnectionWithOptions_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_addTcpConnectionWithOptions_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_addTcpConnectionWithOptions_presult__isset {
  _DeviceManager_addTcpConnectionWithOptions_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_addTcpConnectionWithOptions_presult__isset;

class DeviceManager_addTcpConnectionWithOptions_presult {
 public:


  virtual ~DeviceManager_addTcpConnectionWithOptions_presult() noexcept;
   ::Uts::ProtocolInfo* success;
   ::Uts::AppException e;

  _DeviceManager_addTcpConnectionWithOptions_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_removeTcpConnection_args__isset {
  _DeviceManager_removeTcpConnection_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_removeTcpConnection_args__isset;

class DeviceManager_removeTcpConnection_args {
 public:

  DeviceManager_removeTcpConnection_args(const DeviceManager_removeTcpConnection_args&);
  DeviceManager_removeTcpConnection_args& operator=(const DeviceManager_removeTcpConnection_args&);
  DeviceManager_removeTcpConnection_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_removeTcpConnection_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_removeTcpConnection_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_removeTcpConnection_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_removeTcpConnection_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_removeTcpConnection_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_removeTcpConnection_pargs {
 public:


  virtual ~DeviceManager_removeTcpConnection_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_removeTcpConnection_result__isset {
  _DeviceManager_removeTcpConnection_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_removeTcpConnection_result__isset;

class DeviceManager_removeTcpConnection_result {
 public:

  DeviceManager_removeTcpConnection_result(const DeviceManager_removeTcpConnection_result&);
  DeviceManager_removeTcpConnection_result& operator=(const DeviceManager_removeTcpConnection_result&);
  DeviceManager_removeTcpConnection_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_removeTcpConnection_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_removeTcpConnection_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_removeTcpConnection_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_removeTcpConnection_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_removeTcpConnection_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_removeTcpConnection_presult__isset {
  _DeviceManager_removeTcpConnection_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_removeTcpConnection_presult__isset;

class DeviceManager_removeTcpConnection_presult {
 public:


  virtual ~DeviceManager_removeTcpConnection_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_removeTcpConnection_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_startTcpServer_args__isset {
  _DeviceManager_startTcpServer_args__isset() : protocolType(false), port(false) {}
  bool protocolType :1;
  bool port :1;
} _DeviceManager_startTcpServer_args__isset;

class DeviceManager_startTcpServer_args {
 public:

  DeviceManager_startTcpServer_args(const DeviceManager_startTcpServer_args&);
  DeviceManager_startTcpServer_args& operator=(const DeviceManager_startTcpServer_args&);
  DeviceManager_startTcpServer_args() : protocolType(( ::Uts::ProtocolType::type)0), port(0) {
  }

  virtual ~DeviceManager_startTcpServer_args() noexcept;
   ::Uts::ProtocolType::type protocolType;
  int32_t port;

  _DeviceManager_startTcpServer_args__isset __isset;

  void __set_protocolType(const  ::Uts::ProtocolType::type val);

  void __set_port(const int32_t val);

  bool operator == (const DeviceManager_startTcpServer_args & rhs) const
  {
    if (!(protocolType == rhs.protocolType))
      return false;
    if (!(port == rhs.port))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_startTcpServer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_startTcpServer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_startTcpServer_pargs {
 public:


  virtual ~DeviceManager_startTcpServer_pargs() noexcept;
  const  ::Uts::ProtocolType::type* protocolType;
  const int32_t* port;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_startTcpServer_result__isset {
  _DeviceManager_startTcpServer_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_startTcpServer_result__isset;

class DeviceManager_startTcpServer_result {
 public:

  DeviceManager_startTcpServer_result(const DeviceManager_startTcpServer_result&);
  DeviceManager_startTcpServer_result& operator=(const DeviceManager_startTcpServer_result&);
  DeviceManager_startTcpServer_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_startTcpServer_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_startTcpServer_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_startTcpServer_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_startTcpServer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_startTcpServer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_startTcpServer_presult__isset {
  _DeviceManager_startTcpServer_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_startTcpServer_presult__isset;

class DeviceManager_startTcpServer_presult {
 public:


  virtual ~DeviceManager_startTcpServer_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_startTcpServer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_startTcpServerWithOptions_args__isset {
  _DeviceManager_startTcpServerWithOptions_args__isset() : port(false), options(false) {}
  bool port :1;
  bool options :1;
} _DeviceManager_startTcpServerWithOptions_args__isset;

class DeviceManager_startTcpServerWithOptions_args {
 public:

  DeviceManager_startTcpServerWithOptions_args(const DeviceManager_startTcpServerWithOptions_args&);
  DeviceManager_startTcpServerWithOptions_args& operator=(const DeviceManager_startTcpServerWithOptions_args&);
  DeviceManager_startTcpServerWithOptions_args() : port(0) {
  }

  virtual ~DeviceManager_startTcpServerWithOptions_args() noexcept;
  int32_t port;
   ::Uts::TcpOptions options;

  _DeviceManager_startTcpServerWithOptions_args__isset __isset;

  void __set_port(const int32_t val);

  void __set_options(const  ::Uts::TcpOptions& val);

  bool operator == (const DeviceManager_startTcpServerWithOptions_args & rhs) const
  {
    if (!(port == rhs.port))
      return false;
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_startTcpServerWithOptions_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_startTcpServerWithOptions_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_startTcpServerWithOptions_pargs {
 public:


  virtual ~DeviceManager_startTcpServerWithOptions_pargs() noexcept;
  const int32_t* port;
  const  ::Uts::TcpOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_startTcpServerWithOptions_result__isset {
  _DeviceManager_startTcpServerWithOptions_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_startTcpServerWithOptions_result__isset;

class DeviceManager_startTcpServerWithOptions_result {
 public:

  DeviceManager_startTcpServerWithOptions_result(const DeviceManager_startTcpServerWithOptions_result&);
  DeviceManager_startTcpServerWithOptions_result& operator=(const DeviceManager_startTcpServerWithOptions_result&);
  DeviceManager_startTcpServerWithOptions_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_startTcpServerWithOptions_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_startTcpServerWithOptions_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_startTcpServerWithOptions_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_startTcpServerWithOptions_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_startTcpServerWithOptions_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_startTcpServerWithOptions_presult__isset {
  _DeviceManager_startTcpServerWithOptions_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_startTcpServerWithOptions_presult__isset;

class DeviceManager_startTcpServerWithOptions_presult {
 public:


  virtual ~DeviceManager_startTcpServerWithOptions_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_startTcpServerWithOptions_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_stopTcpServer_args__isset {
  _DeviceManager_stopTcpServer_args__isset() : port(false) {}
  bool port :1;
} _DeviceManager_stopTcpServer_args__isset;

class DeviceManager_stopTcpServer_args {
 public:

  DeviceManager_stopTcpServer_args(const DeviceManager_stopTcpServer_args&);
  DeviceManager_stopTcpServer_args& operator=(const DeviceManager_stopTcpServer_args&);
  DeviceManager_stopTcpServer_args() : port(0) {
  }

  virtual ~DeviceManager_stopTcpServer_args() noexcept;
  int32_t port;

  _DeviceManager_stopTcpServer_args__isset __isset;

  void __set_port(const int32_t val);

  bool operator == (const DeviceManager_stopTcpServer_args & rhs) const
  {
    if (!(port == rhs.port))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_stopTcpServer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_stopTcpServer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_stopTcpServer_pargs {
 public:


  virtual ~DeviceManager_stopTcpServer_pargs() noexcept;
  const int32_t* port;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_stopTcpServer_result__isset {
  _DeviceManager_stopTcpServer_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_stopTcpServer_result__isset;

class DeviceManager_stopTcpServer_result {
 public:

  DeviceManager_stopTcpServer_result(const DeviceManager_stopTcpServer_result&);
  DeviceManager_stopTcpServer_result& operator=(const DeviceManager_stopTcpServer_result&);
  DeviceManager_stopTcpServer_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_stopTcpServer_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_stopTcpServer_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_stopTcpServer_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_stopTcpServer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_stopTcpServer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_stopTcpServer_presult__isset {
  _DeviceManager_stopTcpServer_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_stopTcpServer_presult__isset;

class DeviceManager_stopTcpServer_presult {
 public:


  virtual ~DeviceManager_stopTcpServer_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_stopTcpServer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceManager_getTcpServerList_args {
 public:

  DeviceManager_getTcpServerList_args(const DeviceManager_getTcpServerList_args&);
  DeviceManager_getTcpServerList_args& operator=(const DeviceManager_getTcpServerList_args&);
  DeviceManager_getTcpServerList_args() {
  }

  virtual ~DeviceManager_getTcpServerList_args() noexcept;

  bool operator == (const DeviceManager_getTcpServerList_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceManager_getTcpServerList_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getTcpServerList_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getTcpServerList_pargs {
 public:


  virtual ~DeviceManager_getTcpServerList_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getTcpServerList_result__isset {
  _DeviceManager_getTcpServerList_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getTcpServerList_result__isset;

class DeviceManager_getTcpServerList_result {
 public:

  DeviceManager_getTcpServerList_result(const DeviceManager_getTcpServerList_result&);
  DeviceManager_getTcpServerList_result& operator=(const DeviceManager_getTcpServerList_result&);
  DeviceManager_getTcpServerList_result() {
  }

  virtual ~DeviceManager_getTcpServerList_result() noexcept;
  std::vector<int32_t>  success;
   ::Uts::AppException e;

  _DeviceManager_getTcpServerList_result__isset __isset;

  void __set_success(const std::vector<int32_t> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getTcpServerList_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getTcpServerList_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getTcpServerList_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getTcpServerList_presult__isset {
  _DeviceManager_getTcpServerList_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getTcpServerList_presult__isset;

class DeviceManager_getTcpServerList_presult {
 public:


  virtual ~DeviceManager_getTcpServerList_presult() noexcept;
  std::vector<int32_t> * success;
   ::Uts::AppException e;

  _DeviceManager_getTcpServerList_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceManager_startLogging_args {
 public:

  DeviceManager_startLogging_args(const DeviceManager_startLogging_args&);
  DeviceManager_startLogging_args& operator=(const DeviceManager_startLogging_args&);
  DeviceManager_startLogging_args() {
  }

  virtual ~DeviceManager_startLogging_args() noexcept;

  bool operator == (const DeviceManager_startLogging_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceManager_startLogging_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_startLogging_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_startLogging_pargs {
 public:


  virtual ~DeviceManager_startLogging_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_startLogging_result__isset {
  _DeviceManager_startLogging_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_startLogging_result__isset;

class DeviceManager_startLogging_result {
 public:

  DeviceManager_startLogging_result(const DeviceManager_startLogging_result&);
  DeviceManager_startLogging_result& operator=(const DeviceManager_startLogging_result&);
  DeviceManager_startLogging_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_startLogging_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_startLogging_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_startLogging_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_startLogging_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_startLogging_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_startLogging_presult__isset {
  _DeviceManager_startLogging_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_startLogging_presult__isset;

class DeviceManager_startLogging_presult {
 public:


  virtual ~DeviceManager_startLogging_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_startLogging_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceManager_resetLogFiles_args {
 public:

  DeviceManager_resetLogFiles_args(const DeviceManager_resetLogFiles_args&);
  DeviceManager_resetLogFiles_args& operator=(const DeviceManager_resetLogFiles_args&);
  DeviceManager_resetLogFiles_args() {
  }

  virtual ~DeviceManager_resetLogFiles_args() noexcept;

  bool operator == (const DeviceManager_resetLogFiles_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceManager_resetLogFiles_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_resetLogFiles_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_resetLogFiles_pargs {
 public:


  virtual ~DeviceManager_resetLogFiles_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_resetLogFiles_result__isset {
  _DeviceManager_resetLogFiles_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_resetLogFiles_result__isset;

class DeviceManager_resetLogFiles_result {
 public:

  DeviceManager_resetLogFiles_result(const DeviceManager_resetLogFiles_result&);
  DeviceManager_resetLogFiles_result& operator=(const DeviceManager_resetLogFiles_result&);
  DeviceManager_resetLogFiles_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_resetLogFiles_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_resetLogFiles_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_resetLogFiles_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_resetLogFiles_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_resetLogFiles_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_resetLogFiles_presult__isset {
  _DeviceManager_resetLogFiles_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_resetLogFiles_presult__isset;

class DeviceManager_resetLogFiles_presult {
 public:


  virtual ~DeviceManager_resetLogFiles_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_resetLogFiles_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_saveLogFiles_args__isset {
  _DeviceManager_saveLogFiles_args__isset() : saveFolder(false) {}
  bool saveFolder :1;
} _DeviceManager_saveLogFiles_args__isset;

class DeviceManager_saveLogFiles_args {
 public:

  DeviceManager_saveLogFiles_args(const DeviceManager_saveLogFiles_args&);
  DeviceManager_saveLogFiles_args& operator=(const DeviceManager_saveLogFiles_args&);
  DeviceManager_saveLogFiles_args() : saveFolder() {
  }

  virtual ~DeviceManager_saveLogFiles_args() noexcept;
  std::string saveFolder;

  _DeviceManager_saveLogFiles_args__isset __isset;

  void __set_saveFolder(const std::string& val);

  bool operator == (const DeviceManager_saveLogFiles_args & rhs) const
  {
    if (!(saveFolder == rhs.saveFolder))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_saveLogFiles_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_saveLogFiles_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_saveLogFiles_pargs {
 public:


  virtual ~DeviceManager_saveLogFiles_pargs() noexcept;
  const std::string* saveFolder;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_saveLogFiles_result__isset {
  _DeviceManager_saveLogFiles_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_saveLogFiles_result__isset;

class DeviceManager_saveLogFiles_result {
 public:

  DeviceManager_saveLogFiles_result(const DeviceManager_saveLogFiles_result&);
  DeviceManager_saveLogFiles_result& operator=(const DeviceManager_saveLogFiles_result&);
  DeviceManager_saveLogFiles_result() {
  }

  virtual ~DeviceManager_saveLogFiles_result() noexcept;
  std::vector<std::string>  success;
   ::Uts::AppException e;

  _DeviceManager_saveLogFiles_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_saveLogFiles_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_saveLogFiles_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_saveLogFiles_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_saveLogFiles_presult__isset {
  _DeviceManager_saveLogFiles_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_saveLogFiles_presult__isset;

class DeviceManager_saveLogFiles_presult {
 public:


  virtual ~DeviceManager_saveLogFiles_presult() noexcept;
  std::vector<std::string> * success;
   ::Uts::AppException e;

  _DeviceManager_saveLogFiles_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_saveLogFilesWithFilenames_args__isset {
  _DeviceManager_saveLogFilesWithFilenames_args__isset() : logNameConfig(false) {}
  bool logNameConfig :1;
} _DeviceManager_saveLogFilesWithFilenames_args__isset;

class DeviceManager_saveLogFilesWithFilenames_args {
 public:

  DeviceManager_saveLogFilesWithFilenames_args(const DeviceManager_saveLogFilesWithFilenames_args&);
  DeviceManager_saveLogFilesWithFilenames_args& operator=(const DeviceManager_saveLogFilesWithFilenames_args&);
  DeviceManager_saveLogFilesWithFilenames_args() {
  }

  virtual ~DeviceManager_saveLogFilesWithFilenames_args() noexcept;
  std::map<int64_t, std::string>  logNameConfig;

  _DeviceManager_saveLogFilesWithFilenames_args__isset __isset;

  void __set_logNameConfig(const std::map<int64_t, std::string> & val);

  bool operator == (const DeviceManager_saveLogFilesWithFilenames_args & rhs) const
  {
    if (!(logNameConfig == rhs.logNameConfig))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_saveLogFilesWithFilenames_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_saveLogFilesWithFilenames_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_saveLogFilesWithFilenames_pargs {
 public:


  virtual ~DeviceManager_saveLogFilesWithFilenames_pargs() noexcept;
  const std::map<int64_t, std::string> * logNameConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_saveLogFilesWithFilenames_result__isset {
  _DeviceManager_saveLogFilesWithFilenames_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_saveLogFilesWithFilenames_result__isset;

class DeviceManager_saveLogFilesWithFilenames_result {
 public:

  DeviceManager_saveLogFilesWithFilenames_result(const DeviceManager_saveLogFilesWithFilenames_result&);
  DeviceManager_saveLogFilesWithFilenames_result& operator=(const DeviceManager_saveLogFilesWithFilenames_result&);
  DeviceManager_saveLogFilesWithFilenames_result() {
  }

  virtual ~DeviceManager_saveLogFilesWithFilenames_result() noexcept;
  std::vector<std::string>  success;
   ::Uts::AppException e;

  _DeviceManager_saveLogFilesWithFilenames_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_saveLogFilesWithFilenames_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_saveLogFilesWithFilenames_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_saveLogFilesWithFilenames_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_saveLogFilesWithFilenames_presult__isset {
  _DeviceManager_saveLogFilesWithFilenames_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_saveLogFilesWithFilenames_presult__isset;

class DeviceManager_saveLogFilesWithFilenames_presult {
 public:


  virtual ~DeviceManager_saveLogFilesWithFilenames_presult() noexcept;
  std::vector<std::string> * success;
   ::Uts::AppException e;

  _DeviceManager_saveLogFilesWithFilenames_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getCurrentLogFileSize_args__isset {
  _DeviceManager_getCurrentLogFileSize_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_getCurrentLogFileSize_args__isset;

class DeviceManager_getCurrentLogFileSize_args {
 public:

  DeviceManager_getCurrentLogFileSize_args(const DeviceManager_getCurrentLogFileSize_args&);
  DeviceManager_getCurrentLogFileSize_args& operator=(const DeviceManager_getCurrentLogFileSize_args&);
  DeviceManager_getCurrentLogFileSize_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_getCurrentLogFileSize_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_getCurrentLogFileSize_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getCurrentLogFileSize_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getCurrentLogFileSize_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getCurrentLogFileSize_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getCurrentLogFileSize_pargs {
 public:


  virtual ~DeviceManager_getCurrentLogFileSize_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getCurrentLogFileSize_result__isset {
  _DeviceManager_getCurrentLogFileSize_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getCurrentLogFileSize_result__isset;

class DeviceManager_getCurrentLogFileSize_result {
 public:

  DeviceManager_getCurrentLogFileSize_result(const DeviceManager_getCurrentLogFileSize_result&);
  DeviceManager_getCurrentLogFileSize_result& operator=(const DeviceManager_getCurrentLogFileSize_result&);
  DeviceManager_getCurrentLogFileSize_result() : success(0) {
  }

  virtual ~DeviceManager_getCurrentLogFileSize_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceManager_getCurrentLogFileSize_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getCurrentLogFileSize_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getCurrentLogFileSize_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getCurrentLogFileSize_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getCurrentLogFileSize_presult__isset {
  _DeviceManager_getCurrentLogFileSize_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getCurrentLogFileSize_presult__isset;

class DeviceManager_getCurrentLogFileSize_presult {
 public:


  virtual ~DeviceManager_getCurrentLogFileSize_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceManager_getCurrentLogFileSize_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_openLogSession_args__isset {
  _DeviceManager_openLogSession_args__isset() : logFiles(false) {}
  bool logFiles :1;
} _DeviceManager_openLogSession_args__isset;

class DeviceManager_openLogSession_args {
 public:

  DeviceManager_openLogSession_args(const DeviceManager_openLogSession_args&);
  DeviceManager_openLogSession_args& operator=(const DeviceManager_openLogSession_args&);
  DeviceManager_openLogSession_args() {
  }

  virtual ~DeviceManager_openLogSession_args() noexcept;
  std::vector<std::string>  logFiles;

  _DeviceManager_openLogSession_args__isset __isset;

  void __set_logFiles(const std::vector<std::string> & val);

  bool operator == (const DeviceManager_openLogSession_args & rhs) const
  {
    if (!(logFiles == rhs.logFiles))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_openLogSession_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_openLogSession_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_openLogSession_pargs {
 public:


  virtual ~DeviceManager_openLogSession_pargs() noexcept;
  const std::vector<std::string> * logFiles;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_openLogSession_result__isset {
  _DeviceManager_openLogSession_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_openLogSession_result__isset;

class DeviceManager_openLogSession_result {
 public:

  DeviceManager_openLogSession_result(const DeviceManager_openLogSession_result&);
  DeviceManager_openLogSession_result& operator=(const DeviceManager_openLogSession_result&);
  DeviceManager_openLogSession_result() : success() {
  }

  virtual ~DeviceManager_openLogSession_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceManager_openLogSession_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_openLogSession_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_openLogSession_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_openLogSession_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_openLogSession_presult__isset {
  _DeviceManager_openLogSession_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_openLogSession_presult__isset;

class DeviceManager_openLogSession_presult {
 public:


  virtual ~DeviceManager_openLogSession_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceManager_openLogSession_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_attachToLogSession_args__isset {
  _DeviceManager_attachToLogSession_args__isset() : clientId(false), logSession(false) {}
  bool clientId :1;
  bool logSession :1;
} _DeviceManager_attachToLogSession_args__isset;

class DeviceManager_attachToLogSession_args {
 public:

  DeviceManager_attachToLogSession_args(const DeviceManager_attachToLogSession_args&);
  DeviceManager_attachToLogSession_args& operator=(const DeviceManager_attachToLogSession_args&);
  DeviceManager_attachToLogSession_args() : clientId(0), logSession() {
  }

  virtual ~DeviceManager_attachToLogSession_args() noexcept;
  int32_t clientId;
  std::string logSession;

  _DeviceManager_attachToLogSession_args__isset __isset;

  void __set_clientId(const int32_t val);

  void __set_logSession(const std::string& val);

  bool operator == (const DeviceManager_attachToLogSession_args & rhs) const
  {
    if (!(clientId == rhs.clientId))
      return false;
    if (!(logSession == rhs.logSession))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_attachToLogSession_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_attachToLogSession_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_attachToLogSession_pargs {
 public:


  virtual ~DeviceManager_attachToLogSession_pargs() noexcept;
  const int32_t* clientId;
  const std::string* logSession;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_attachToLogSession_result__isset {
  _DeviceManager_attachToLogSession_result__isset() : success(false) {}
  bool success :1;
} _DeviceManager_attachToLogSession_result__isset;

class DeviceManager_attachToLogSession_result {
 public:

  DeviceManager_attachToLogSession_result(const DeviceManager_attachToLogSession_result&);
  DeviceManager_attachToLogSession_result& operator=(const DeviceManager_attachToLogSession_result&);
  DeviceManager_attachToLogSession_result() : success() {
  }

  virtual ~DeviceManager_attachToLogSession_result() noexcept;
  std::string success;

  _DeviceManager_attachToLogSession_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const DeviceManager_attachToLogSession_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_attachToLogSession_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_attachToLogSession_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_attachToLogSession_presult__isset {
  _DeviceManager_attachToLogSession_presult__isset() : success(false) {}
  bool success :1;
} _DeviceManager_attachToLogSession_presult__isset;

class DeviceManager_attachToLogSession_presult {
 public:


  virtual ~DeviceManager_attachToLogSession_presult() noexcept;
  std::string* success;

  _DeviceManager_attachToLogSession_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_logAnnotation_args__isset {
  _DeviceManager_logAnnotation_args__isset() : annotation(false), messageId(false), protocolHandle(false) {}
  bool annotation :1;
  bool messageId :1;
  bool protocolHandle :1;
} _DeviceManager_logAnnotation_args__isset;

class DeviceManager_logAnnotation_args {
 public:

  DeviceManager_logAnnotation_args(const DeviceManager_logAnnotation_args&);
  DeviceManager_logAnnotation_args& operator=(const DeviceManager_logAnnotation_args&);
  DeviceManager_logAnnotation_args() : annotation(), messageId(0), protocolHandle(0) {
  }

  virtual ~DeviceManager_logAnnotation_args() noexcept;
  std::string annotation;
  int64_t messageId;
  int64_t protocolHandle;

  _DeviceManager_logAnnotation_args__isset __isset;

  void __set_annotation(const std::string& val);

  void __set_messageId(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_logAnnotation_args & rhs) const
  {
    if (!(annotation == rhs.annotation))
      return false;
    if (!(messageId == rhs.messageId))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_logAnnotation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_logAnnotation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_logAnnotation_pargs {
 public:


  virtual ~DeviceManager_logAnnotation_pargs() noexcept;
  const std::string* annotation;
  const int64_t* messageId;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_logAnnotation_result__isset {
  _DeviceManager_logAnnotation_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_logAnnotation_result__isset;

class DeviceManager_logAnnotation_result {
 public:

  DeviceManager_logAnnotation_result(const DeviceManager_logAnnotation_result&);
  DeviceManager_logAnnotation_result& operator=(const DeviceManager_logAnnotation_result&);
  DeviceManager_logAnnotation_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_logAnnotation_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_logAnnotation_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_logAnnotation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_logAnnotation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_logAnnotation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_logAnnotation_presult__isset {
  _DeviceManager_logAnnotation_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_logAnnotation_presult__isset;

class DeviceManager_logAnnotation_presult {
 public:


  virtual ~DeviceManager_logAnnotation_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_logAnnotation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_resetPhone_args__isset {
  _DeviceManager_resetPhone_args__isset() : deviceHandle(false), resetTimeout(false) {}
  bool deviceHandle :1;
  bool resetTimeout :1;
} _DeviceManager_resetPhone_args__isset;

class DeviceManager_resetPhone_args {
 public:

  DeviceManager_resetPhone_args(const DeviceManager_resetPhone_args&);
  DeviceManager_resetPhone_args& operator=(const DeviceManager_resetPhone_args&);
  DeviceManager_resetPhone_args() : deviceHandle(0), resetTimeout(0) {
  }

  virtual ~DeviceManager_resetPhone_args() noexcept;
  int64_t deviceHandle;
  int32_t resetTimeout;

  _DeviceManager_resetPhone_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_resetTimeout(const int32_t val);

  bool operator == (const DeviceManager_resetPhone_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(resetTimeout == rhs.resetTimeout))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_resetPhone_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_resetPhone_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_resetPhone_pargs {
 public:


  virtual ~DeviceManager_resetPhone_pargs() noexcept;
  const int64_t* deviceHandle;
  const int32_t* resetTimeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_resetPhone_result__isset {
  _DeviceManager_resetPhone_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_resetPhone_result__isset;

class DeviceManager_resetPhone_result {
 public:

  DeviceManager_resetPhone_result(const DeviceManager_resetPhone_result&);
  DeviceManager_resetPhone_result& operator=(const DeviceManager_resetPhone_result&);
  DeviceManager_resetPhone_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_resetPhone_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_resetPhone_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_resetPhone_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_resetPhone_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_resetPhone_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_resetPhone_presult__isset {
  _DeviceManager_resetPhone_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_resetPhone_presult__isset;

class DeviceManager_resetPhone_presult {
 public:


  virtual ~DeviceManager_resetPhone_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_resetPhone_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_resetPhoneByProtocol_args__isset {
  _DeviceManager_resetPhoneByProtocol_args__isset() : deviceHandle(false), protocolHandle(false), resetTimeout(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool resetTimeout :1;
} _DeviceManager_resetPhoneByProtocol_args__isset;

class DeviceManager_resetPhoneByProtocol_args {
 public:

  DeviceManager_resetPhoneByProtocol_args(const DeviceManager_resetPhoneByProtocol_args&);
  DeviceManager_resetPhoneByProtocol_args& operator=(const DeviceManager_resetPhoneByProtocol_args&);
  DeviceManager_resetPhoneByProtocol_args() : deviceHandle(0), protocolHandle(0), resetTimeout(0) {
  }

  virtual ~DeviceManager_resetPhoneByProtocol_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;
  int32_t resetTimeout;

  _DeviceManager_resetPhoneByProtocol_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_resetTimeout(const int32_t val);

  bool operator == (const DeviceManager_resetPhoneByProtocol_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(resetTimeout == rhs.resetTimeout))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_resetPhoneByProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_resetPhoneByProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_resetPhoneByProtocol_pargs {
 public:


  virtual ~DeviceManager_resetPhoneByProtocol_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const int32_t* resetTimeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_resetPhoneByProtocol_result__isset {
  _DeviceManager_resetPhoneByProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_resetPhoneByProtocol_result__isset;

class DeviceManager_resetPhoneByProtocol_result {
 public:

  DeviceManager_resetPhoneByProtocol_result(const DeviceManager_resetPhoneByProtocol_result&);
  DeviceManager_resetPhoneByProtocol_result& operator=(const DeviceManager_resetPhoneByProtocol_result&);
  DeviceManager_resetPhoneByProtocol_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_resetPhoneByProtocol_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_resetPhoneByProtocol_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_resetPhoneByProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_resetPhoneByProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_resetPhoneByProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_resetPhoneByProtocol_presult__isset {
  _DeviceManager_resetPhoneByProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_resetPhoneByProtocol_presult__isset;

class DeviceManager_resetPhoneByProtocol_presult {
 public:


  virtual ~DeviceManager_resetPhoneByProtocol_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_resetPhoneByProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_restartQmiReadyScan_args__isset {
  _DeviceManager_restartQmiReadyScan_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_restartQmiReadyScan_args__isset;

class DeviceManager_restartQmiReadyScan_args {
 public:

  DeviceManager_restartQmiReadyScan_args(const DeviceManager_restartQmiReadyScan_args&);
  DeviceManager_restartQmiReadyScan_args& operator=(const DeviceManager_restartQmiReadyScan_args&);
  DeviceManager_restartQmiReadyScan_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_restartQmiReadyScan_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_restartQmiReadyScan_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_restartQmiReadyScan_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_restartQmiReadyScan_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_restartQmiReadyScan_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_restartQmiReadyScan_pargs {
 public:


  virtual ~DeviceManager_restartQmiReadyScan_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_restartQmiReadyScan_result__isset {
  _DeviceManager_restartQmiReadyScan_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_restartQmiReadyScan_result__isset;

class DeviceManager_restartQmiReadyScan_result {
 public:

  DeviceManager_restartQmiReadyScan_result(const DeviceManager_restartQmiReadyScan_result&);
  DeviceManager_restartQmiReadyScan_result& operator=(const DeviceManager_restartQmiReadyScan_result&);
  DeviceManager_restartQmiReadyScan_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_restartQmiReadyScan_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_restartQmiReadyScan_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_restartQmiReadyScan_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_restartQmiReadyScan_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_restartQmiReadyScan_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_restartQmiReadyScan_presult__isset {
  _DeviceManager_restartQmiReadyScan_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_restartQmiReadyScan_presult__isset;

class DeviceManager_restartQmiReadyScan_presult {
 public:


  virtual ~DeviceManager_restartQmiReadyScan_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_restartQmiReadyScan_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_setOperatingMode_args__isset {
  _DeviceManager_setOperatingMode_args__isset() : deviceHandle(false), protocolHandle(false), mode(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool mode :1;
} _DeviceManager_setOperatingMode_args__isset;

class DeviceManager_setOperatingMode_args {
 public:

  DeviceManager_setOperatingMode_args(const DeviceManager_setOperatingMode_args&);
  DeviceManager_setOperatingMode_args& operator=(const DeviceManager_setOperatingMode_args&);
  DeviceManager_setOperatingMode_args() : deviceHandle(0), protocolHandle(0), mode((OperatingMode::type)0) {
  }

  virtual ~DeviceManager_setOperatingMode_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;
  OperatingMode::type mode;

  _DeviceManager_setOperatingMode_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_mode(const OperatingMode::type val);

  bool operator == (const DeviceManager_setOperatingMode_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(mode == rhs.mode))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_setOperatingMode_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_setOperatingMode_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_setOperatingMode_pargs {
 public:


  virtual ~DeviceManager_setOperatingMode_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const OperatingMode::type* mode;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_setOperatingMode_result__isset {
  _DeviceManager_setOperatingMode_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_setOperatingMode_result__isset;

class DeviceManager_setOperatingMode_result {
 public:

  DeviceManager_setOperatingMode_result(const DeviceManager_setOperatingMode_result&);
  DeviceManager_setOperatingMode_result& operator=(const DeviceManager_setOperatingMode_result&);
  DeviceManager_setOperatingMode_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_setOperatingMode_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_setOperatingMode_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_setOperatingMode_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_setOperatingMode_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_setOperatingMode_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_setOperatingMode_presult__isset {
  _DeviceManager_setOperatingMode_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_setOperatingMode_presult__isset;

class DeviceManager_setOperatingMode_presult {
 public:


  virtual ~DeviceManager_setOperatingMode_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_setOperatingMode_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getThroughputStatistics_args__isset {
  _DeviceManager_getThroughputStatistics_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_getThroughputStatistics_args__isset;

class DeviceManager_getThroughputStatistics_args {
 public:

  DeviceManager_getThroughputStatistics_args(const DeviceManager_getThroughputStatistics_args&);
  DeviceManager_getThroughputStatistics_args& operator=(const DeviceManager_getThroughputStatistics_args&);
  DeviceManager_getThroughputStatistics_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_getThroughputStatistics_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_getThroughputStatistics_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getThroughputStatistics_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getThroughputStatistics_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getThroughputStatistics_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getThroughputStatistics_pargs {
 public:


  virtual ~DeviceManager_getThroughputStatistics_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getThroughputStatistics_result__isset {
  _DeviceManager_getThroughputStatistics_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getThroughputStatistics_result__isset;

class DeviceManager_getThroughputStatistics_result {
 public:

  DeviceManager_getThroughputStatistics_result(const DeviceManager_getThroughputStatistics_result&);
  DeviceManager_getThroughputStatistics_result& operator=(const DeviceManager_getThroughputStatistics_result&);
  DeviceManager_getThroughputStatistics_result() {
  }

  virtual ~DeviceManager_getThroughputStatistics_result() noexcept;
   ::Uts::RxTxInfo success;
   ::Uts::AppException e;

  _DeviceManager_getThroughputStatistics_result__isset __isset;

  void __set_success(const  ::Uts::RxTxInfo& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getThroughputStatistics_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getThroughputStatistics_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getThroughputStatistics_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getThroughputStatistics_presult__isset {
  _DeviceManager_getThroughputStatistics_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getThroughputStatistics_presult__isset;

class DeviceManager_getThroughputStatistics_presult {
 public:


  virtual ~DeviceManager_getThroughputStatistics_presult() noexcept;
   ::Uts::RxTxInfo* success;
   ::Uts::AppException e;

  _DeviceManager_getThroughputStatistics_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getEsn_args__isset {
  _DeviceManager_getEsn_args__isset() : deviceHandle(false), protocolHandle(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
} _DeviceManager_getEsn_args__isset;

class DeviceManager_getEsn_args {
 public:

  DeviceManager_getEsn_args(const DeviceManager_getEsn_args&);
  DeviceManager_getEsn_args& operator=(const DeviceManager_getEsn_args&);
  DeviceManager_getEsn_args() : deviceHandle(0), protocolHandle(0) {
  }

  virtual ~DeviceManager_getEsn_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;

  _DeviceManager_getEsn_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getEsn_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getEsn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getEsn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getEsn_pargs {
 public:


  virtual ~DeviceManager_getEsn_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getEsn_result__isset {
  _DeviceManager_getEsn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getEsn_result__isset;

class DeviceManager_getEsn_result {
 public:

  DeviceManager_getEsn_result(const DeviceManager_getEsn_result&);
  DeviceManager_getEsn_result& operator=(const DeviceManager_getEsn_result&);
  DeviceManager_getEsn_result() : success(0) {
  }

  virtual ~DeviceManager_getEsn_result() noexcept;
  int32_t success;
   ::Uts::AppException e;

  _DeviceManager_getEsn_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getEsn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getEsn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getEsn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getEsn_presult__isset {
  _DeviceManager_getEsn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getEsn_presult__isset;

class DeviceManager_getEsn_presult {
 public:


  virtual ~DeviceManager_getEsn_presult() noexcept;
  int32_t* success;
   ::Uts::AppException e;

  _DeviceManager_getEsn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_setEsn_args__isset {
  _DeviceManager_setEsn_args__isset() : deviceHandle(false), protocolHandle(false), esn(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool esn :1;
} _DeviceManager_setEsn_args__isset;

class DeviceManager_setEsn_args {
 public:

  DeviceManager_setEsn_args(const DeviceManager_setEsn_args&);
  DeviceManager_setEsn_args& operator=(const DeviceManager_setEsn_args&);
  DeviceManager_setEsn_args() : deviceHandle(0), protocolHandle(0), esn(0) {
  }

  virtual ~DeviceManager_setEsn_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;
  int32_t esn;

  _DeviceManager_setEsn_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_esn(const int32_t val);

  bool operator == (const DeviceManager_setEsn_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(esn == rhs.esn))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_setEsn_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_setEsn_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_setEsn_pargs {
 public:


  virtual ~DeviceManager_setEsn_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const int32_t* esn;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_setEsn_result__isset {
  _DeviceManager_setEsn_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_setEsn_result__isset;

class DeviceManager_setEsn_result {
 public:

  DeviceManager_setEsn_result(const DeviceManager_setEsn_result&);
  DeviceManager_setEsn_result& operator=(const DeviceManager_setEsn_result&);
  DeviceManager_setEsn_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_setEsn_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_setEsn_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_setEsn_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_setEsn_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_setEsn_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_setEsn_presult__isset {
  _DeviceManager_setEsn_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_setEsn_presult__isset;

class DeviceManager_setEsn_presult {
 public:


  virtual ~DeviceManager_setEsn_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_setEsn_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getImei_args__isset {
  _DeviceManager_getImei_args__isset() : deviceHandle(false), protocolHandle(false), subscriptionId(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool subscriptionId :1;
} _DeviceManager_getImei_args__isset;

class DeviceManager_getImei_args {
 public:

  DeviceManager_getImei_args(const DeviceManager_getImei_args&);
  DeviceManager_getImei_args& operator=(const DeviceManager_getImei_args&);
  DeviceManager_getImei_args() : deviceHandle(0), protocolHandle(0), subscriptionId(0) {
  }

  virtual ~DeviceManager_getImei_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;
  int32_t subscriptionId;

  _DeviceManager_getImei_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceManager_getImei_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getImei_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getImei_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getImei_pargs {
 public:


  virtual ~DeviceManager_getImei_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getImei_result__isset {
  _DeviceManager_getImei_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getImei_result__isset;

class DeviceManager_getImei_result {
 public:

  DeviceManager_getImei_result(const DeviceManager_getImei_result&);
  DeviceManager_getImei_result& operator=(const DeviceManager_getImei_result&);
  DeviceManager_getImei_result() : success() {
  }

  virtual ~DeviceManager_getImei_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _DeviceManager_getImei_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getImei_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getImei_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getImei_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getImei_presult__isset {
  _DeviceManager_getImei_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getImei_presult__isset;

class DeviceManager_getImei_presult {
 public:


  virtual ~DeviceManager_getImei_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _DeviceManager_getImei_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_setImei_args__isset {
  _DeviceManager_setImei_args__isset() : deviceHandle(false), protocolHandle(false), imei(false), subscriptionId(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool imei :1;
  bool subscriptionId :1;
} _DeviceManager_setImei_args__isset;

class DeviceManager_setImei_args {
 public:

  DeviceManager_setImei_args(const DeviceManager_setImei_args&);
  DeviceManager_setImei_args& operator=(const DeviceManager_setImei_args&);
  DeviceManager_setImei_args() : deviceHandle(0), protocolHandle(0), imei(), subscriptionId(0) {
  }

  virtual ~DeviceManager_setImei_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;
  std::string imei;
  int32_t subscriptionId;

  _DeviceManager_setImei_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_imei(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceManager_setImei_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(imei == rhs.imei))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_setImei_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_setImei_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_setImei_pargs {
 public:


  virtual ~DeviceManager_setImei_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const std::string* imei;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_setImei_result__isset {
  _DeviceManager_setImei_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_setImei_result__isset;

class DeviceManager_setImei_result {
 public:

  DeviceManager_setImei_result(const DeviceManager_setImei_result&);
  DeviceManager_setImei_result& operator=(const DeviceManager_setImei_result&);
  DeviceManager_setImei_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_setImei_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_setImei_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_setImei_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_setImei_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_setImei_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_setImei_presult__isset {
  _DeviceManager_setImei_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_setImei_presult__isset;

class DeviceManager_setImei_presult {
 public:


  virtual ~DeviceManager_setImei_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_setImei_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getMeid_args__isset {
  _DeviceManager_getMeid_args__isset() : deviceHandle(false), protocolHandle(false), subscriptionId(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool subscriptionId :1;
} _DeviceManager_getMeid_args__isset;

class DeviceManager_getMeid_args {
 public:

  DeviceManager_getMeid_args(const DeviceManager_getMeid_args&);
  DeviceManager_getMeid_args& operator=(const DeviceManager_getMeid_args&);
  DeviceManager_getMeid_args() : deviceHandle(0), protocolHandle(0), subscriptionId(0) {
  }

  virtual ~DeviceManager_getMeid_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;
  int32_t subscriptionId;

  _DeviceManager_getMeid_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceManager_getMeid_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getMeid_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getMeid_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getMeid_pargs {
 public:


  virtual ~DeviceManager_getMeid_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getMeid_result__isset {
  _DeviceManager_getMeid_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getMeid_result__isset;

class DeviceManager_getMeid_result {
 public:

  DeviceManager_getMeid_result(const DeviceManager_getMeid_result&);
  DeviceManager_getMeid_result& operator=(const DeviceManager_getMeid_result&);
  DeviceManager_getMeid_result() : success(0) {
  }

  virtual ~DeviceManager_getMeid_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DeviceManager_getMeid_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getMeid_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getMeid_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getMeid_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getMeid_presult__isset {
  _DeviceManager_getMeid_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getMeid_presult__isset;

class DeviceManager_getMeid_presult {
 public:


  virtual ~DeviceManager_getMeid_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DeviceManager_getMeid_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_setMeid_args__isset {
  _DeviceManager_setMeid_args__isset() : deviceHandle(false), protocolHandle(false), meid(false), subscriptionId(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool meid :1;
  bool subscriptionId :1;
} _DeviceManager_setMeid_args__isset;

class DeviceManager_setMeid_args {
 public:

  DeviceManager_setMeid_args(const DeviceManager_setMeid_args&);
  DeviceManager_setMeid_args& operator=(const DeviceManager_setMeid_args&);
  DeviceManager_setMeid_args() : deviceHandle(0), protocolHandle(0), meid(0), subscriptionId(0) {
  }

  virtual ~DeviceManager_setMeid_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;
  int64_t meid;
  int32_t subscriptionId;

  _DeviceManager_setMeid_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_meid(const int64_t val);

  void __set_subscriptionId(const int32_t val);

  bool operator == (const DeviceManager_setMeid_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(meid == rhs.meid))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_setMeid_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_setMeid_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_setMeid_pargs {
 public:


  virtual ~DeviceManager_setMeid_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const int64_t* meid;
  const int32_t* subscriptionId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_setMeid_result__isset {
  _DeviceManager_setMeid_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_setMeid_result__isset;

class DeviceManager_setMeid_result {
 public:

  DeviceManager_setMeid_result(const DeviceManager_setMeid_result&);
  DeviceManager_setMeid_result& operator=(const DeviceManager_setMeid_result&);
  DeviceManager_setMeid_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_setMeid_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_setMeid_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_setMeid_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_setMeid_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_setMeid_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_setMeid_presult__isset {
  _DeviceManager_setMeid_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_setMeid_presult__isset;

class DeviceManager_setMeid_presult {
 public:


  virtual ~DeviceManager_setMeid_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_setMeid_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_checkSpc_args__isset {
  _DeviceManager_checkSpc_args__isset() : deviceHandle(false), protocolHandle(false), spc(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
  bool spc :1;
} _DeviceManager_checkSpc_args__isset;

class DeviceManager_checkSpc_args {
 public:

  DeviceManager_checkSpc_args(const DeviceManager_checkSpc_args&);
  DeviceManager_checkSpc_args& operator=(const DeviceManager_checkSpc_args&);
  DeviceManager_checkSpc_args() : deviceHandle(0), protocolHandle(0), spc() {
  }

  virtual ~DeviceManager_checkSpc_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;
  std::string spc;

  _DeviceManager_checkSpc_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  void __set_spc(const std::string& val);

  bool operator == (const DeviceManager_checkSpc_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(spc == rhs.spc))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_checkSpc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_checkSpc_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_checkSpc_pargs {
 public:


  virtual ~DeviceManager_checkSpc_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;
  const std::string* spc;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_checkSpc_result__isset {
  _DeviceManager_checkSpc_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_checkSpc_result__isset;

class DeviceManager_checkSpc_result {
 public:

  DeviceManager_checkSpc_result(const DeviceManager_checkSpc_result&);
  DeviceManager_checkSpc_result& operator=(const DeviceManager_checkSpc_result&);
  DeviceManager_checkSpc_result() {
  }

  virtual ~DeviceManager_checkSpc_result() noexcept;
  SpcStatus success;
   ::Uts::AppException e;

  _DeviceManager_checkSpc_result__isset __isset;

  void __set_success(const SpcStatus& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_checkSpc_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_checkSpc_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_checkSpc_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_checkSpc_presult__isset {
  _DeviceManager_checkSpc_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_checkSpc_presult__isset;

class DeviceManager_checkSpc_presult {
 public:


  virtual ~DeviceManager_checkSpc_presult() noexcept;
  SpcStatus* success;
   ::Uts::AppException e;

  _DeviceManager_checkSpc_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getOperatingMode_args__isset {
  _DeviceManager_getOperatingMode_args__isset() : deviceHandle(false), protocolHandle(false) {}
  bool deviceHandle :1;
  bool protocolHandle :1;
} _DeviceManager_getOperatingMode_args__isset;

class DeviceManager_getOperatingMode_args {
 public:

  DeviceManager_getOperatingMode_args(const DeviceManager_getOperatingMode_args&);
  DeviceManager_getOperatingMode_args& operator=(const DeviceManager_getOperatingMode_args&);
  DeviceManager_getOperatingMode_args() : deviceHandle(0), protocolHandle(0) {
  }

  virtual ~DeviceManager_getOperatingMode_args() noexcept;
  int64_t deviceHandle;
  int64_t protocolHandle;

  _DeviceManager_getOperatingMode_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getOperatingMode_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getOperatingMode_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getOperatingMode_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getOperatingMode_pargs {
 public:


  virtual ~DeviceManager_getOperatingMode_pargs() noexcept;
  const int64_t* deviceHandle;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getOperatingMode_result__isset {
  _DeviceManager_getOperatingMode_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getOperatingMode_result__isset;

class DeviceManager_getOperatingMode_result {
 public:

  DeviceManager_getOperatingMode_result(const DeviceManager_getOperatingMode_result&);
  DeviceManager_getOperatingMode_result& operator=(const DeviceManager_getOperatingMode_result&);
  DeviceManager_getOperatingMode_result() {
  }

  virtual ~DeviceManager_getOperatingMode_result() noexcept;
  OperatingModeInfo success;
   ::Uts::AppException e;

  _DeviceManager_getOperatingMode_result__isset __isset;

  void __set_success(const OperatingModeInfo& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getOperatingMode_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getOperatingMode_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getOperatingMode_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getOperatingMode_presult__isset {
  _DeviceManager_getOperatingMode_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getOperatingMode_presult__isset;

class DeviceManager_getOperatingMode_presult {
 public:


  virtual ~DeviceManager_getOperatingMode_presult() noexcept;
  OperatingModeInfo* success;
   ::Uts::AppException e;

  _DeviceManager_getOperatingMode_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_transferImageBhi_args__isset {
  _DeviceManager_transferImageBhi_args__isset() : programmerPath(false) {}
  bool programmerPath :1;
} _DeviceManager_transferImageBhi_args__isset;

class DeviceManager_transferImageBhi_args {
 public:

  DeviceManager_transferImageBhi_args(const DeviceManager_transferImageBhi_args&);
  DeviceManager_transferImageBhi_args& operator=(const DeviceManager_transferImageBhi_args&);
  DeviceManager_transferImageBhi_args() : programmerPath() {
  }

  virtual ~DeviceManager_transferImageBhi_args() noexcept;
  std::string programmerPath;

  _DeviceManager_transferImageBhi_args__isset __isset;

  void __set_programmerPath(const std::string& val);

  bool operator == (const DeviceManager_transferImageBhi_args & rhs) const
  {
    if (!(programmerPath == rhs.programmerPath))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_transferImageBhi_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_transferImageBhi_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_transferImageBhi_pargs {
 public:


  virtual ~DeviceManager_transferImageBhi_pargs() noexcept;
  const std::string* programmerPath;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_transferImageBhi_result__isset {
  _DeviceManager_transferImageBhi_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_transferImageBhi_result__isset;

class DeviceManager_transferImageBhi_result {
 public:

  DeviceManager_transferImageBhi_result(const DeviceManager_transferImageBhi_result&);
  DeviceManager_transferImageBhi_result& operator=(const DeviceManager_transferImageBhi_result&);
  DeviceManager_transferImageBhi_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_transferImageBhi_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_transferImageBhi_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_transferImageBhi_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_transferImageBhi_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_transferImageBhi_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_transferImageBhi_presult__isset {
  _DeviceManager_transferImageBhi_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_transferImageBhi_presult__isset;

class DeviceManager_transferImageBhi_presult {
 public:


  virtual ~DeviceManager_transferImageBhi_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_transferImageBhi_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_transferFileToDevice_args__isset {
  _DeviceManager_transferFileToDevice_args__isset() : hostPath(false), devicePath(false), options(false) {}
  bool hostPath :1;
  bool devicePath :1;
  bool options :1;
} _DeviceManager_transferFileToDevice_args__isset;

class DeviceManager_transferFileToDevice_args {
 public:

  DeviceManager_transferFileToDevice_args(const DeviceManager_transferFileToDevice_args&);
  DeviceManager_transferFileToDevice_args& operator=(const DeviceManager_transferFileToDevice_args&);
  DeviceManager_transferFileToDevice_args() : hostPath(), devicePath() {
  }

  virtual ~DeviceManager_transferFileToDevice_args() noexcept;
  std::string hostPath;
  std::string devicePath;
   ::Uts::TransferFileOptions options;

  _DeviceManager_transferFileToDevice_args__isset __isset;

  void __set_hostPath(const std::string& val);

  void __set_devicePath(const std::string& val);

  void __set_options(const  ::Uts::TransferFileOptions& val);

  bool operator == (const DeviceManager_transferFileToDevice_args & rhs) const
  {
    if (!(hostPath == rhs.hostPath))
      return false;
    if (!(devicePath == rhs.devicePath))
      return false;
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_transferFileToDevice_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_transferFileToDevice_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_transferFileToDevice_pargs {
 public:


  virtual ~DeviceManager_transferFileToDevice_pargs() noexcept;
  const std::string* hostPath;
  const std::string* devicePath;
  const  ::Uts::TransferFileOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_transferFileToDevice_result__isset {
  _DeviceManager_transferFileToDevice_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_transferFileToDevice_result__isset;

class DeviceManager_transferFileToDevice_result {
 public:

  DeviceManager_transferFileToDevice_result(const DeviceManager_transferFileToDevice_result&);
  DeviceManager_transferFileToDevice_result& operator=(const DeviceManager_transferFileToDevice_result&);
  DeviceManager_transferFileToDevice_result() {
  }

  virtual ~DeviceManager_transferFileToDevice_result() noexcept;
   ::Uts::TransferFileResult success;
   ::Uts::AppException e;

  _DeviceManager_transferFileToDevice_result__isset __isset;

  void __set_success(const  ::Uts::TransferFileResult& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_transferFileToDevice_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_transferFileToDevice_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_transferFileToDevice_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_transferFileToDevice_presult__isset {
  _DeviceManager_transferFileToDevice_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_transferFileToDevice_presult__isset;

class DeviceManager_transferFileToDevice_presult {
 public:


  virtual ~DeviceManager_transferFileToDevice_presult() noexcept;
   ::Uts::TransferFileResult* success;
   ::Uts::AppException e;

  _DeviceManager_transferFileToDevice_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_transferFileToHost_args__isset {
  _DeviceManager_transferFileToHost_args__isset() : devicePath(false), hostPath(false), options(false) {}
  bool devicePath :1;
  bool hostPath :1;
  bool options :1;
} _DeviceManager_transferFileToHost_args__isset;

class DeviceManager_transferFileToHost_args {
 public:

  DeviceManager_transferFileToHost_args(const DeviceManager_transferFileToHost_args&);
  DeviceManager_transferFileToHost_args& operator=(const DeviceManager_transferFileToHost_args&);
  DeviceManager_transferFileToHost_args() : devicePath(), hostPath() {
  }

  virtual ~DeviceManager_transferFileToHost_args() noexcept;
  std::string devicePath;
  std::string hostPath;
   ::Uts::TransferFileOptions options;

  _DeviceManager_transferFileToHost_args__isset __isset;

  void __set_devicePath(const std::string& val);

  void __set_hostPath(const std::string& val);

  void __set_options(const  ::Uts::TransferFileOptions& val);

  bool operator == (const DeviceManager_transferFileToHost_args & rhs) const
  {
    if (!(devicePath == rhs.devicePath))
      return false;
    if (!(hostPath == rhs.hostPath))
      return false;
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_transferFileToHost_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_transferFileToHost_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_transferFileToHost_pargs {
 public:


  virtual ~DeviceManager_transferFileToHost_pargs() noexcept;
  const std::string* devicePath;
  const std::string* hostPath;
  const  ::Uts::TransferFileOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_transferFileToHost_result__isset {
  _DeviceManager_transferFileToHost_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_transferFileToHost_result__isset;

class DeviceManager_transferFileToHost_result {
 public:

  DeviceManager_transferFileToHost_result(const DeviceManager_transferFileToHost_result&);
  DeviceManager_transferFileToHost_result& operator=(const DeviceManager_transferFileToHost_result&);
  DeviceManager_transferFileToHost_result() {
  }

  virtual ~DeviceManager_transferFileToHost_result() noexcept;
   ::Uts::TransferFileResult success;
   ::Uts::AppException e;

  _DeviceManager_transferFileToHost_result__isset __isset;

  void __set_success(const  ::Uts::TransferFileResult& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_transferFileToHost_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_transferFileToHost_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_transferFileToHost_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_transferFileToHost_presult__isset {
  _DeviceManager_transferFileToHost_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_transferFileToHost_presult__isset;

class DeviceManager_transferFileToHost_presult {
 public:


  virtual ~DeviceManager_transferFileToHost_presult() noexcept;
   ::Uts::TransferFileResult* success;
   ::Uts::AppException e;

  _DeviceManager_transferFileToHost_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getProtocolLockStatus_args__isset {
  _DeviceManager_getProtocolLockStatus_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_getProtocolLockStatus_args__isset;

class DeviceManager_getProtocolLockStatus_args {
 public:

  DeviceManager_getProtocolLockStatus_args(const DeviceManager_getProtocolLockStatus_args&);
  DeviceManager_getProtocolLockStatus_args& operator=(const DeviceManager_getProtocolLockStatus_args&);
  DeviceManager_getProtocolLockStatus_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_getProtocolLockStatus_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_getProtocolLockStatus_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getProtocolLockStatus_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getProtocolLockStatus_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getProtocolLockStatus_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getProtocolLockStatus_pargs {
 public:


  virtual ~DeviceManager_getProtocolLockStatus_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getProtocolLockStatus_result__isset {
  _DeviceManager_getProtocolLockStatus_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getProtocolLockStatus_result__isset;

class DeviceManager_getProtocolLockStatus_result {
 public:

  DeviceManager_getProtocolLockStatus_result(const DeviceManager_getProtocolLockStatus_result&);
  DeviceManager_getProtocolLockStatus_result& operator=(const DeviceManager_getProtocolLockStatus_result&);
  DeviceManager_getProtocolLockStatus_result() {
  }

  virtual ~DeviceManager_getProtocolLockStatus_result() noexcept;
   ::Uts::LockStatus success;
   ::Uts::AppException e;

  _DeviceManager_getProtocolLockStatus_result__isset __isset;

  void __set_success(const  ::Uts::LockStatus& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getProtocolLockStatus_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getProtocolLockStatus_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getProtocolLockStatus_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getProtocolLockStatus_presult__isset {
  _DeviceManager_getProtocolLockStatus_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getProtocolLockStatus_presult__isset;

class DeviceManager_getProtocolLockStatus_presult {
 public:


  virtual ~DeviceManager_getProtocolLockStatus_presult() noexcept;
   ::Uts::LockStatus* success;
   ::Uts::AppException e;

  _DeviceManager_getProtocolLockStatus_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getDeviceUsageIndicators_args__isset {
  _DeviceManager_getDeviceUsageIndicators_args__isset() : deviceHandle(false) {}
  bool deviceHandle :1;
} _DeviceManager_getDeviceUsageIndicators_args__isset;

class DeviceManager_getDeviceUsageIndicators_args {
 public:

  DeviceManager_getDeviceUsageIndicators_args(const DeviceManager_getDeviceUsageIndicators_args&);
  DeviceManager_getDeviceUsageIndicators_args& operator=(const DeviceManager_getDeviceUsageIndicators_args&);
  DeviceManager_getDeviceUsageIndicators_args() : deviceHandle(0) {
  }

  virtual ~DeviceManager_getDeviceUsageIndicators_args() noexcept;
  int64_t deviceHandle;

  _DeviceManager_getDeviceUsageIndicators_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  bool operator == (const DeviceManager_getDeviceUsageIndicators_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceUsageIndicators_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceUsageIndicators_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getDeviceUsageIndicators_pargs {
 public:


  virtual ~DeviceManager_getDeviceUsageIndicators_pargs() noexcept;
  const int64_t* deviceHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceUsageIndicators_result__isset {
  _DeviceManager_getDeviceUsageIndicators_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceUsageIndicators_result__isset;

class DeviceManager_getDeviceUsageIndicators_result {
 public:

  DeviceManager_getDeviceUsageIndicators_result(const DeviceManager_getDeviceUsageIndicators_result&);
  DeviceManager_getDeviceUsageIndicators_result& operator=(const DeviceManager_getDeviceUsageIndicators_result&);
  DeviceManager_getDeviceUsageIndicators_result() {
  }

  virtual ~DeviceManager_getDeviceUsageIndicators_result() noexcept;
   ::Uts::UsageIndicators success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceUsageIndicators_result__isset __isset;

  void __set_success(const  ::Uts::UsageIndicators& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getDeviceUsageIndicators_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getDeviceUsageIndicators_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getDeviceUsageIndicators_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getDeviceUsageIndicators_presult__isset {
  _DeviceManager_getDeviceUsageIndicators_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getDeviceUsageIndicators_presult__isset;

class DeviceManager_getDeviceUsageIndicators_presult {
 public:


  virtual ~DeviceManager_getDeviceUsageIndicators_presult() noexcept;
   ::Uts::UsageIndicators* success;
   ::Uts::AppException e;

  _DeviceManager_getDeviceUsageIndicators_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_enableFunctionLog_args__isset {
  _DeviceManager_enableFunctionLog_args__isset() : deviceHandle(false), areas(false), options(false) {}
  bool deviceHandle :1;
  bool areas :1;
  bool options :1;
} _DeviceManager_enableFunctionLog_args__isset;

class DeviceManager_enableFunctionLog_args {
 public:

  DeviceManager_enableFunctionLog_args(const DeviceManager_enableFunctionLog_args&);
  DeviceManager_enableFunctionLog_args& operator=(const DeviceManager_enableFunctionLog_args&);
  DeviceManager_enableFunctionLog_args() : deviceHandle(0) {
  }

  virtual ~DeviceManager_enableFunctionLog_args() noexcept;
  int64_t deviceHandle;
  std::vector< ::Uts::FunctionArea::type>  areas;
   ::Uts::LogOptions options;

  _DeviceManager_enableFunctionLog_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_areas(const std::vector< ::Uts::FunctionArea::type> & val);

  void __set_options(const  ::Uts::LogOptions& val);

  bool operator == (const DeviceManager_enableFunctionLog_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(areas == rhs.areas))
      return false;
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableFunctionLog_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableFunctionLog_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_enableFunctionLog_pargs {
 public:


  virtual ~DeviceManager_enableFunctionLog_pargs() noexcept;
  const int64_t* deviceHandle;
  const std::vector< ::Uts::FunctionArea::type> * areas;
  const  ::Uts::LogOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableFunctionLog_result__isset {
  _DeviceManager_enableFunctionLog_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableFunctionLog_result__isset;

class DeviceManager_enableFunctionLog_result {
 public:

  DeviceManager_enableFunctionLog_result(const DeviceManager_enableFunctionLog_result&);
  DeviceManager_enableFunctionLog_result& operator=(const DeviceManager_enableFunctionLog_result&);
  DeviceManager_enableFunctionLog_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_enableFunctionLog_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_enableFunctionLog_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_enableFunctionLog_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableFunctionLog_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableFunctionLog_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableFunctionLog_presult__isset {
  _DeviceManager_enableFunctionLog_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableFunctionLog_presult__isset;

class DeviceManager_enableFunctionLog_presult {
 public:


  virtual ~DeviceManager_enableFunctionLog_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_enableFunctionLog_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_disableFunctionLog_args__isset {
  _DeviceManager_disableFunctionLog_args__isset() : deviceHandle(false), areas(false) {}
  bool deviceHandle :1;
  bool areas :1;
} _DeviceManager_disableFunctionLog_args__isset;

class DeviceManager_disableFunctionLog_args {
 public:

  DeviceManager_disableFunctionLog_args(const DeviceManager_disableFunctionLog_args&);
  DeviceManager_disableFunctionLog_args& operator=(const DeviceManager_disableFunctionLog_args&);
  DeviceManager_disableFunctionLog_args() : deviceHandle(0) {
  }

  virtual ~DeviceManager_disableFunctionLog_args() noexcept;
  int64_t deviceHandle;
  std::vector< ::Uts::FunctionArea::type>  areas;

  _DeviceManager_disableFunctionLog_args__isset __isset;

  void __set_deviceHandle(const int64_t val);

  void __set_areas(const std::vector< ::Uts::FunctionArea::type> & val);

  bool operator == (const DeviceManager_disableFunctionLog_args & rhs) const
  {
    if (!(deviceHandle == rhs.deviceHandle))
      return false;
    if (!(areas == rhs.areas))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_disableFunctionLog_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_disableFunctionLog_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_disableFunctionLog_pargs {
 public:


  virtual ~DeviceManager_disableFunctionLog_pargs() noexcept;
  const int64_t* deviceHandle;
  const std::vector< ::Uts::FunctionArea::type> * areas;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_disableFunctionLog_result__isset {
  _DeviceManager_disableFunctionLog_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_disableFunctionLog_result__isset;

class DeviceManager_disableFunctionLog_result {
 public:

  DeviceManager_disableFunctionLog_result(const DeviceManager_disableFunctionLog_result&);
  DeviceManager_disableFunctionLog_result& operator=(const DeviceManager_disableFunctionLog_result&);
  DeviceManager_disableFunctionLog_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_disableFunctionLog_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_disableFunctionLog_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_disableFunctionLog_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_disableFunctionLog_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_disableFunctionLog_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_disableFunctionLog_presult__isset {
  _DeviceManager_disableFunctionLog_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_disableFunctionLog_presult__isset;

class DeviceManager_disableFunctionLog_presult {
 public:


  virtual ~DeviceManager_disableFunctionLog_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_disableFunctionLog_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_enableProtocolLog_args__isset {
  _DeviceManager_enableProtocolLog_args__isset() : protocolHandle(false), options(false) {}
  bool protocolHandle :1;
  bool options :1;
} _DeviceManager_enableProtocolLog_args__isset;

class DeviceManager_enableProtocolLog_args {
 public:

  DeviceManager_enableProtocolLog_args(const DeviceManager_enableProtocolLog_args&);
  DeviceManager_enableProtocolLog_args& operator=(const DeviceManager_enableProtocolLog_args&);
  DeviceManager_enableProtocolLog_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_enableProtocolLog_args() noexcept;
  int64_t protocolHandle;
   ::Uts::LogOptions options;

  _DeviceManager_enableProtocolLog_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_options(const  ::Uts::LogOptions& val);

  bool operator == (const DeviceManager_enableProtocolLog_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (!(options == rhs.options))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableProtocolLog_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableProtocolLog_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_enableProtocolLog_pargs {
 public:


  virtual ~DeviceManager_enableProtocolLog_pargs() noexcept;
  const int64_t* protocolHandle;
  const  ::Uts::LogOptions* options;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableProtocolLog_result__isset {
  _DeviceManager_enableProtocolLog_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableProtocolLog_result__isset;

class DeviceManager_enableProtocolLog_result {
 public:

  DeviceManager_enableProtocolLog_result(const DeviceManager_enableProtocolLog_result&);
  DeviceManager_enableProtocolLog_result& operator=(const DeviceManager_enableProtocolLog_result&);
  DeviceManager_enableProtocolLog_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_enableProtocolLog_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_enableProtocolLog_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_enableProtocolLog_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableProtocolLog_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableProtocolLog_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableProtocolLog_presult__isset {
  _DeviceManager_enableProtocolLog_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableProtocolLog_presult__isset;

class DeviceManager_enableProtocolLog_presult {
 public:


  virtual ~DeviceManager_enableProtocolLog_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_enableProtocolLog_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_disableProtocolLog_args__isset {
  _DeviceManager_disableProtocolLog_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_disableProtocolLog_args__isset;

class DeviceManager_disableProtocolLog_args {
 public:

  DeviceManager_disableProtocolLog_args(const DeviceManager_disableProtocolLog_args&);
  DeviceManager_disableProtocolLog_args& operator=(const DeviceManager_disableProtocolLog_args&);
  DeviceManager_disableProtocolLog_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_disableProtocolLog_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_disableProtocolLog_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_disableProtocolLog_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_disableProtocolLog_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_disableProtocolLog_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_disableProtocolLog_pargs {
 public:


  virtual ~DeviceManager_disableProtocolLog_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_disableProtocolLog_result__isset {
  _DeviceManager_disableProtocolLog_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_disableProtocolLog_result__isset;

class DeviceManager_disableProtocolLog_result {
 public:

  DeviceManager_disableProtocolLog_result(const DeviceManager_disableProtocolLog_result&);
  DeviceManager_disableProtocolLog_result& operator=(const DeviceManager_disableProtocolLog_result&);
  DeviceManager_disableProtocolLog_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_disableProtocolLog_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_disableProtocolLog_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_disableProtocolLog_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_disableProtocolLog_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_disableProtocolLog_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_disableProtocolLog_presult__isset {
  _DeviceManager_disableProtocolLog_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_disableProtocolLog_presult__isset;

class DeviceManager_disableProtocolLog_presult {
 public:


  virtual ~DeviceManager_disableProtocolLog_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_disableProtocolLog_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_configureProtocol_args__isset {
  _DeviceManager_configureProtocol_args__isset() : protocolConfiguration(false) {}
  bool protocolConfiguration :1;
} _DeviceManager_configureProtocol_args__isset;

class DeviceManager_configureProtocol_args {
 public:

  DeviceManager_configureProtocol_args(const DeviceManager_configureProtocol_args&);
  DeviceManager_configureProtocol_args& operator=(const DeviceManager_configureProtocol_args&);
  DeviceManager_configureProtocol_args() {
  }

  virtual ~DeviceManager_configureProtocol_args() noexcept;
   ::Uts::ProtocolConfiguration protocolConfiguration;

  _DeviceManager_configureProtocol_args__isset __isset;

  void __set_protocolConfiguration(const  ::Uts::ProtocolConfiguration& val);

  bool operator == (const DeviceManager_configureProtocol_args & rhs) const
  {
    if (!(protocolConfiguration == rhs.protocolConfiguration))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_configureProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_configureProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_configureProtocol_pargs {
 public:


  virtual ~DeviceManager_configureProtocol_pargs() noexcept;
  const  ::Uts::ProtocolConfiguration* protocolConfiguration;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_configureProtocol_result__isset {
  _DeviceManager_configureProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_configureProtocol_result__isset;

class DeviceManager_configureProtocol_result {
 public:

  DeviceManager_configureProtocol_result(const DeviceManager_configureProtocol_result&);
  DeviceManager_configureProtocol_result& operator=(const DeviceManager_configureProtocol_result&);
  DeviceManager_configureProtocol_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_configureProtocol_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_configureProtocol_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_configureProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_configureProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_configureProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_configureProtocol_presult__isset {
  _DeviceManager_configureProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_configureProtocol_presult__isset;

class DeviceManager_configureProtocol_presult {
 public:


  virtual ~DeviceManager_configureProtocol_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_configureProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_getProtocolConfiguration_args__isset {
  _DeviceManager_getProtocolConfiguration_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DeviceManager_getProtocolConfiguration_args__isset;

class DeviceManager_getProtocolConfiguration_args {
 public:

  DeviceManager_getProtocolConfiguration_args(const DeviceManager_getProtocolConfiguration_args&);
  DeviceManager_getProtocolConfiguration_args& operator=(const DeviceManager_getProtocolConfiguration_args&);
  DeviceManager_getProtocolConfiguration_args() : protocolHandle(0) {
  }

  virtual ~DeviceManager_getProtocolConfiguration_args() noexcept;
  int64_t protocolHandle;

  _DeviceManager_getProtocolConfiguration_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DeviceManager_getProtocolConfiguration_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getProtocolConfiguration_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getProtocolConfiguration_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getProtocolConfiguration_pargs {
 public:


  virtual ~DeviceManager_getProtocolConfiguration_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getProtocolConfiguration_result__isset {
  _DeviceManager_getProtocolConfiguration_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getProtocolConfiguration_result__isset;

class DeviceManager_getProtocolConfiguration_result {
 public:

  DeviceManager_getProtocolConfiguration_result(const DeviceManager_getProtocolConfiguration_result&);
  DeviceManager_getProtocolConfiguration_result& operator=(const DeviceManager_getProtocolConfiguration_result&);
  DeviceManager_getProtocolConfiguration_result() {
  }

  virtual ~DeviceManager_getProtocolConfiguration_result() noexcept;
   ::Uts::ProtocolConfigurationResult success;
   ::Uts::AppException e;

  _DeviceManager_getProtocolConfiguration_result__isset __isset;

  void __set_success(const  ::Uts::ProtocolConfigurationResult& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_getProtocolConfiguration_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getProtocolConfiguration_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getProtocolConfiguration_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getProtocolConfiguration_presult__isset {
  _DeviceManager_getProtocolConfiguration_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_getProtocolConfiguration_presult__isset;

class DeviceManager_getProtocolConfiguration_presult {
 public:


  virtual ~DeviceManager_getProtocolConfiguration_presult() noexcept;
   ::Uts::ProtocolConfigurationResult* success;
   ::Uts::AppException e;

  _DeviceManager_getProtocolConfiguration_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_enableProtocolDataMonitoring_args__isset {
  _DeviceManager_enableProtocolDataMonitoring_args__isset() : protocolHandleList(false), enable(false) {}
  bool protocolHandleList :1;
  bool enable :1;
} _DeviceManager_enableProtocolDataMonitoring_args__isset;

class DeviceManager_enableProtocolDataMonitoring_args {
 public:

  DeviceManager_enableProtocolDataMonitoring_args(const DeviceManager_enableProtocolDataMonitoring_args&);
  DeviceManager_enableProtocolDataMonitoring_args& operator=(const DeviceManager_enableProtocolDataMonitoring_args&);
  DeviceManager_enableProtocolDataMonitoring_args() : enable(0) {
  }

  virtual ~DeviceManager_enableProtocolDataMonitoring_args() noexcept;
  std::vector<int64_t>  protocolHandleList;
  bool enable;

  _DeviceManager_enableProtocolDataMonitoring_args__isset __isset;

  void __set_protocolHandleList(const std::vector<int64_t> & val);

  void __set_enable(const bool val);

  bool operator == (const DeviceManager_enableProtocolDataMonitoring_args & rhs) const
  {
    if (!(protocolHandleList == rhs.protocolHandleList))
      return false;
    if (!(enable == rhs.enable))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableProtocolDataMonitoring_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableProtocolDataMonitoring_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_enableProtocolDataMonitoring_pargs {
 public:


  virtual ~DeviceManager_enableProtocolDataMonitoring_pargs() noexcept;
  const std::vector<int64_t> * protocolHandleList;
  const bool* enable;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableProtocolDataMonitoring_result__isset {
  _DeviceManager_enableProtocolDataMonitoring_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableProtocolDataMonitoring_result__isset;

class DeviceManager_enableProtocolDataMonitoring_result {
 public:

  DeviceManager_enableProtocolDataMonitoring_result(const DeviceManager_enableProtocolDataMonitoring_result&);
  DeviceManager_enableProtocolDataMonitoring_result& operator=(const DeviceManager_enableProtocolDataMonitoring_result&);
  DeviceManager_enableProtocolDataMonitoring_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_enableProtocolDataMonitoring_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_enableProtocolDataMonitoring_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_enableProtocolDataMonitoring_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableProtocolDataMonitoring_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableProtocolDataMonitoring_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableProtocolDataMonitoring_presult__isset {
  _DeviceManager_enableProtocolDataMonitoring_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableProtocolDataMonitoring_presult__isset;

class DeviceManager_enableProtocolDataMonitoring_presult {
 public:


  virtual ~DeviceManager_enableProtocolDataMonitoring_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_enableProtocolDataMonitoring_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_enableDeviceDataMonitoring_args__isset {
  _DeviceManager_enableDeviceDataMonitoring_args__isset() : deviceHandleList(false), enable(false) {}
  bool deviceHandleList :1;
  bool enable :1;
} _DeviceManager_enableDeviceDataMonitoring_args__isset;

class DeviceManager_enableDeviceDataMonitoring_args {
 public:

  DeviceManager_enableDeviceDataMonitoring_args(const DeviceManager_enableDeviceDataMonitoring_args&);
  DeviceManager_enableDeviceDataMonitoring_args& operator=(const DeviceManager_enableDeviceDataMonitoring_args&);
  DeviceManager_enableDeviceDataMonitoring_args() : enable(0) {
  }

  virtual ~DeviceManager_enableDeviceDataMonitoring_args() noexcept;
  std::vector<int64_t>  deviceHandleList;
  bool enable;

  _DeviceManager_enableDeviceDataMonitoring_args__isset __isset;

  void __set_deviceHandleList(const std::vector<int64_t> & val);

  void __set_enable(const bool val);

  bool operator == (const DeviceManager_enableDeviceDataMonitoring_args & rhs) const
  {
    if (!(deviceHandleList == rhs.deviceHandleList))
      return false;
    if (!(enable == rhs.enable))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableDeviceDataMonitoring_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableDeviceDataMonitoring_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_enableDeviceDataMonitoring_pargs {
 public:


  virtual ~DeviceManager_enableDeviceDataMonitoring_pargs() noexcept;
  const std::vector<int64_t> * deviceHandleList;
  const bool* enable;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableDeviceDataMonitoring_result__isset {
  _DeviceManager_enableDeviceDataMonitoring_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableDeviceDataMonitoring_result__isset;

class DeviceManager_enableDeviceDataMonitoring_result {
 public:

  DeviceManager_enableDeviceDataMonitoring_result(const DeviceManager_enableDeviceDataMonitoring_result&);
  DeviceManager_enableDeviceDataMonitoring_result& operator=(const DeviceManager_enableDeviceDataMonitoring_result&);
  DeviceManager_enableDeviceDataMonitoring_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_enableDeviceDataMonitoring_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_enableDeviceDataMonitoring_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_enableDeviceDataMonitoring_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableDeviceDataMonitoring_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableDeviceDataMonitoring_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableDeviceDataMonitoring_presult__isset {
  _DeviceManager_enableDeviceDataMonitoring_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableDeviceDataMonitoring_presult__isset;

class DeviceManager_enableDeviceDataMonitoring_presult {
 public:


  virtual ~DeviceManager_enableDeviceDataMonitoring_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_enableDeviceDataMonitoring_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_enableDevicePriority_args__isset {
  _DeviceManager_enableDevicePriority_args__isset() : deviceHandleList(false), enable(false) {}
  bool deviceHandleList :1;
  bool enable :1;
} _DeviceManager_enableDevicePriority_args__isset;

class DeviceManager_enableDevicePriority_args {
 public:

  DeviceManager_enableDevicePriority_args(const DeviceManager_enableDevicePriority_args&);
  DeviceManager_enableDevicePriority_args& operator=(const DeviceManager_enableDevicePriority_args&);
  DeviceManager_enableDevicePriority_args() : enable(0) {
  }

  virtual ~DeviceManager_enableDevicePriority_args() noexcept;
  std::vector<int64_t>  deviceHandleList;
  bool enable;

  _DeviceManager_enableDevicePriority_args__isset __isset;

  void __set_deviceHandleList(const std::vector<int64_t> & val);

  void __set_enable(const bool val);

  bool operator == (const DeviceManager_enableDevicePriority_args & rhs) const
  {
    if (!(deviceHandleList == rhs.deviceHandleList))
      return false;
    if (!(enable == rhs.enable))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableDevicePriority_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableDevicePriority_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_enableDevicePriority_pargs {
 public:


  virtual ~DeviceManager_enableDevicePriority_pargs() noexcept;
  const std::vector<int64_t> * deviceHandleList;
  const bool* enable;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableDevicePriority_result__isset {
  _DeviceManager_enableDevicePriority_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableDevicePriority_result__isset;

class DeviceManager_enableDevicePriority_result {
 public:

  DeviceManager_enableDevicePriority_result(const DeviceManager_enableDevicePriority_result&);
  DeviceManager_enableDevicePriority_result& operator=(const DeviceManager_enableDevicePriority_result&);
  DeviceManager_enableDevicePriority_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_enableDevicePriority_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_enableDevicePriority_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_enableDevicePriority_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_enableDevicePriority_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_enableDevicePriority_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_enableDevicePriority_presult__isset {
  _DeviceManager_enableDevicePriority_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_enableDevicePriority_presult__isset;

class DeviceManager_enableDevicePriority_presult {
 public:


  virtual ~DeviceManager_enableDevicePriority_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_enableDevicePriority_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DeviceManager_configParameter_args__isset {
  _DeviceManager_configParameter_args__isset() : name(false), value(false) {}
  bool name :1;
  bool value :1;
} _DeviceManager_configParameter_args__isset;

class DeviceManager_configParameter_args {
 public:

  DeviceManager_configParameter_args(const DeviceManager_configParameter_args&);
  DeviceManager_configParameter_args& operator=(const DeviceManager_configParameter_args&);
  DeviceManager_configParameter_args() : name(), value() {
  }

  virtual ~DeviceManager_configParameter_args() noexcept;
  std::string name;
  std::string value;

  _DeviceManager_configParameter_args__isset __isset;

  void __set_name(const std::string& val);

  void __set_value(const std::string& val);

  bool operator == (const DeviceManager_configParameter_args & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_configParameter_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_configParameter_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_configParameter_pargs {
 public:


  virtual ~DeviceManager_configParameter_pargs() noexcept;
  const std::string* name;
  const std::string* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_configParameter_result__isset {
  _DeviceManager_configParameter_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_configParameter_result__isset;

class DeviceManager_configParameter_result {
 public:

  DeviceManager_configParameter_result(const DeviceManager_configParameter_result&);
  DeviceManager_configParameter_result& operator=(const DeviceManager_configParameter_result&);
  DeviceManager_configParameter_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DeviceManager_configParameter_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DeviceManager_configParameter_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DeviceManager_configParameter_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_configParameter_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_configParameter_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_configParameter_presult__isset {
  _DeviceManager_configParameter_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DeviceManager_configParameter_presult__isset;

class DeviceManager_configParameter_presult {
 public:


  virtual ~DeviceManager_configParameter_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DeviceManager_configParameter_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DeviceManager_getRegistrationPort_args {
 public:

  DeviceManager_getRegistrationPort_args(const DeviceManager_getRegistrationPort_args&);
  DeviceManager_getRegistrationPort_args& operator=(const DeviceManager_getRegistrationPort_args&);
  DeviceManager_getRegistrationPort_args() {
  }

  virtual ~DeviceManager_getRegistrationPort_args() noexcept;

  bool operator == (const DeviceManager_getRegistrationPort_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DeviceManager_getRegistrationPort_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getRegistrationPort_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DeviceManager_getRegistrationPort_pargs {
 public:


  virtual ~DeviceManager_getRegistrationPort_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getRegistrationPort_result__isset {
  _DeviceManager_getRegistrationPort_result__isset() : success(false) {}
  bool success :1;
} _DeviceManager_getRegistrationPort_result__isset;

class DeviceManager_getRegistrationPort_result {
 public:

  DeviceManager_getRegistrationPort_result(const DeviceManager_getRegistrationPort_result&);
  DeviceManager_getRegistrationPort_result& operator=(const DeviceManager_getRegistrationPort_result&);
  DeviceManager_getRegistrationPort_result() : success(0) {
  }

  virtual ~DeviceManager_getRegistrationPort_result() noexcept;
  int32_t success;

  _DeviceManager_getRegistrationPort_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const DeviceManager_getRegistrationPort_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DeviceManager_getRegistrationPort_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceManager_getRegistrationPort_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DeviceManager_getRegistrationPort_presult__isset {
  _DeviceManager_getRegistrationPort_presult__isset() : success(false) {}
  bool success :1;
} _DeviceManager_getRegistrationPort_presult__isset;

class DeviceManager_getRegistrationPort_presult {
 public:


  virtual ~DeviceManager_getRegistrationPort_presult() noexcept;
  int32_t* success;

  _DeviceManager_getRegistrationPort_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class DeviceManagerClient : virtual public DeviceManagerIf {
 public:
  DeviceManagerClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  DeviceManagerClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void getServicesList(std::vector<std::string> & _return);
  void send_getServicesList();
  void recv_getServicesList(std::vector<std::string> & _return);
  void getDevicesForService(std::vector<int64_t> & _return, const std::string& serviceName);
  void send_getDevicesForService(const std::string& serviceName);
  void recv_getDevicesForService(std::vector<int64_t> & _return);
  void getServicesForDevice(std::vector<std::string> & _return, const int64_t deviceHandle);
  void send_getServicesForDevice(const int64_t deviceHandle);
  void recv_getServicesForDevice(std::vector<std::string> & _return);
  void createService(std::string& _return, const std::string& serviceName, const int64_t deviceHandle);
  void send_createService(const std::string& serviceName, const int64_t deviceHandle);
  void recv_createService(std::string& _return);
  void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return);
  void send_getDeviceList();
  void recv_getDeviceList(std::vector< ::Uts::DeviceInfo> & _return);
  int64_t getDeviceHandleFromProtocol(const int64_t protocolHandle);
  void send_getDeviceHandleFromProtocol(const int64_t protocolHandle);
  int64_t recv_getDeviceHandleFromProtocol();
   ::Uts::ErrorCode::type mergeDevice(const int64_t sourceDeviceHandle, const int64_t destinationDeviceHandle);
  void send_mergeDevice(const int64_t sourceDeviceHandle, const int64_t destinationDeviceHandle);
   ::Uts::ErrorCode::type recv_mergeDevice();
  void getDeviceBuildId( ::Uts::BuildInfo& _return, const int64_t deviceHandle);
  void send_getDeviceBuildId(const int64_t deviceHandle);
  void recv_getDeviceBuildId( ::Uts::BuildInfo& _return);
  void getDeviceImageInfoByProtocol(std::vector< ::Uts::ImageInfo> & _return, const int64_t protocolHandle);
  void send_getDeviceImageInfoByProtocol(const int64_t protocolHandle);
  void recv_getDeviceImageInfoByProtocol(std::vector< ::Uts::ImageInfo> & _return);
  void getChipName(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle);
  void send_getChipName(const int64_t deviceHandle, const int64_t protocolHandle);
  void recv_getChipName(std::string& _return);
   ::Uts::DeviceMode::type getDeviceMode(const int64_t deviceHandle);
  void send_getDeviceMode(const int64_t deviceHandle);
   ::Uts::DeviceMode::type recv_getDeviceMode();
  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle);
  void send_getProtocolList(const int64_t deviceHandle);
  void recv_getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return);
  void getActiveLogSession(std::string& _return);
  void send_getActiveLogSession();
  void recv_getActiveLogSession(std::string& _return);
   ::Uts::ErrorCode::type overrideUnknownProtocol(const int64_t protocolHandle, const  ::Uts::ProtocolType::type newType);
  void send_overrideUnknownProtocol(const int64_t protocolHandle, const  ::Uts::ProtocolType::type newType);
   ::Uts::ErrorCode::type recv_overrideUnknownProtocol();
  void addTcpConnection( ::Uts::ProtocolInfo& _return, const int64_t deviceHandle, const  ::Uts::ProtocolType::type protocolType, const bool bIsClient, const std::string& description, const std::string& host, const int32_t port);
  void send_addTcpConnection(const int64_t deviceHandle, const  ::Uts::ProtocolType::type protocolType, const bool bIsClient, const std::string& description, const std::string& host, const int32_t port);
  void recv_addTcpConnection( ::Uts::ProtocolInfo& _return);
  void addTcpConnectionWithOptions( ::Uts::ProtocolInfo& _return, const std::string& host, const int32_t port, const  ::Uts::TcpOptions& options);
  void send_addTcpConnectionWithOptions(const std::string& host, const int32_t port, const  ::Uts::TcpOptions& options);
  void recv_addTcpConnectionWithOptions( ::Uts::ProtocolInfo& _return);
   ::Uts::ErrorCode::type removeTcpConnection(const int64_t protocolHandle);
  void send_removeTcpConnection(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_removeTcpConnection();
   ::Uts::ErrorCode::type startTcpServer(const  ::Uts::ProtocolType::type protocolType, const int32_t port);
  void send_startTcpServer(const  ::Uts::ProtocolType::type protocolType, const int32_t port);
   ::Uts::ErrorCode::type recv_startTcpServer();
   ::Uts::ErrorCode::type startTcpServerWithOptions(const int32_t port, const  ::Uts::TcpOptions& options);
  void send_startTcpServerWithOptions(const int32_t port, const  ::Uts::TcpOptions& options);
   ::Uts::ErrorCode::type recv_startTcpServerWithOptions();
   ::Uts::ErrorCode::type stopTcpServer(const int32_t port);
  void send_stopTcpServer(const int32_t port);
   ::Uts::ErrorCode::type recv_stopTcpServer();
  void getTcpServerList(std::vector<int32_t> & _return);
  void send_getTcpServerList();
  void recv_getTcpServerList(std::vector<int32_t> & _return);
   ::Uts::ErrorCode::type startLogging();
  void send_startLogging();
   ::Uts::ErrorCode::type recv_startLogging();
   ::Uts::ErrorCode::type resetLogFiles();
  void send_resetLogFiles();
   ::Uts::ErrorCode::type recv_resetLogFiles();
  void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder);
  void send_saveLogFiles(const std::string& saveFolder);
  void recv_saveLogFiles(std::vector<std::string> & _return);
  void saveLogFilesWithFilenames(std::vector<std::string> & _return, const std::map<int64_t, std::string> & logNameConfig);
  void send_saveLogFilesWithFilenames(const std::map<int64_t, std::string> & logNameConfig);
  void recv_saveLogFilesWithFilenames(std::vector<std::string> & _return);
  int64_t getCurrentLogFileSize(const int64_t protocolHandle);
  void send_getCurrentLogFileSize(const int64_t protocolHandle);
  int64_t recv_getCurrentLogFileSize();
  void openLogSession(std::string& _return, const std::vector<std::string> & logFiles);
  void send_openLogSession(const std::vector<std::string> & logFiles);
  void recv_openLogSession(std::string& _return);
  void attachToLogSession(std::string& _return, const int32_t clientId, const std::string& logSession);
  void send_attachToLogSession(const int32_t clientId, const std::string& logSession);
  void recv_attachToLogSession(std::string& _return);
   ::Uts::ErrorCode::type logAnnotation(const std::string& annotation, const int64_t messageId, const int64_t protocolHandle);
  void send_logAnnotation(const std::string& annotation, const int64_t messageId, const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_logAnnotation();
   ::Uts::ErrorCode::type resetPhone(const int64_t deviceHandle, const int32_t resetTimeout);
  void send_resetPhone(const int64_t deviceHandle, const int32_t resetTimeout);
   ::Uts::ErrorCode::type recv_resetPhone();
   ::Uts::ErrorCode::type resetPhoneByProtocol(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t resetTimeout);
  void send_resetPhoneByProtocol(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t resetTimeout);
   ::Uts::ErrorCode::type recv_resetPhoneByProtocol();
   ::Uts::ErrorCode::type restartQmiReadyScan(const int64_t protocolHandle);
  void send_restartQmiReadyScan(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_restartQmiReadyScan();
   ::Uts::ErrorCode::type setOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle, const OperatingMode::type mode);
  void send_setOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle, const OperatingMode::type mode);
   ::Uts::ErrorCode::type recv_setOperatingMode();
  void getThroughputStatistics( ::Uts::RxTxInfo& _return, const int64_t protocolHandle);
  void send_getThroughputStatistics(const int64_t protocolHandle);
  void recv_getThroughputStatistics( ::Uts::RxTxInfo& _return);
  int32_t getEsn(const int64_t deviceHandle, const int64_t protocolHandle);
  void send_getEsn(const int64_t deviceHandle, const int64_t protocolHandle);
  int32_t recv_getEsn();
   ::Uts::ErrorCode::type setEsn(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t esn);
  void send_setEsn(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t esn);
   ::Uts::ErrorCode::type recv_setEsn();
  void getImei(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId);
  void send_getImei(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId);
  void recv_getImei(std::string& _return);
   ::Uts::ErrorCode::type setImei(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& imei, const int32_t subscriptionId);
  void send_setImei(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& imei, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_setImei();
  int64_t getMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId);
  void send_getMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId);
  int64_t recv_getMeid();
   ::Uts::ErrorCode::type setMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int64_t meid, const int32_t subscriptionId);
  void send_setMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int64_t meid, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_setMeid();
  void checkSpc(SpcStatus& _return, const int64_t deviceHandle, const int64_t protocolHandle, const std::string& spc);
  void send_checkSpc(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& spc);
  void recv_checkSpc(SpcStatus& _return);
  void getOperatingMode(OperatingModeInfo& _return, const int64_t deviceHandle, const int64_t protocolHandle);
  void send_getOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle);
  void recv_getOperatingMode(OperatingModeInfo& _return);
   ::Uts::ErrorCode::type transferImageBhi(const std::string& programmerPath);
  void send_transferImageBhi(const std::string& programmerPath);
   ::Uts::ErrorCode::type recv_transferImageBhi();
  void transferFileToDevice( ::Uts::TransferFileResult& _return, const std::string& hostPath, const std::string& devicePath, const  ::Uts::TransferFileOptions& options);
  void send_transferFileToDevice(const std::string& hostPath, const std::string& devicePath, const  ::Uts::TransferFileOptions& options);
  void recv_transferFileToDevice( ::Uts::TransferFileResult& _return);
  void transferFileToHost( ::Uts::TransferFileResult& _return, const std::string& devicePath, const std::string& hostPath, const  ::Uts::TransferFileOptions& options);
  void send_transferFileToHost(const std::string& devicePath, const std::string& hostPath, const  ::Uts::TransferFileOptions& options);
  void recv_transferFileToHost( ::Uts::TransferFileResult& _return);
  void getProtocolLockStatus( ::Uts::LockStatus& _return, const int64_t protocolHandle);
  void send_getProtocolLockStatus(const int64_t protocolHandle);
  void recv_getProtocolLockStatus( ::Uts::LockStatus& _return);
  void getDeviceUsageIndicators( ::Uts::UsageIndicators& _return, const int64_t deviceHandle);
  void send_getDeviceUsageIndicators(const int64_t deviceHandle);
  void recv_getDeviceUsageIndicators( ::Uts::UsageIndicators& _return);
   ::Uts::ErrorCode::type enableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas, const  ::Uts::LogOptions& options);
  void send_enableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas, const  ::Uts::LogOptions& options);
   ::Uts::ErrorCode::type recv_enableFunctionLog();
   ::Uts::ErrorCode::type disableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas);
  void send_disableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas);
   ::Uts::ErrorCode::type recv_disableFunctionLog();
   ::Uts::ErrorCode::type enableProtocolLog(const int64_t protocolHandle, const  ::Uts::LogOptions& options);
  void send_enableProtocolLog(const int64_t protocolHandle, const  ::Uts::LogOptions& options);
   ::Uts::ErrorCode::type recv_enableProtocolLog();
   ::Uts::ErrorCode::type disableProtocolLog(const int64_t protocolHandle);
  void send_disableProtocolLog(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_disableProtocolLog();
   ::Uts::ErrorCode::type configureProtocol(const  ::Uts::ProtocolConfiguration& protocolConfiguration);
  void send_configureProtocol(const  ::Uts::ProtocolConfiguration& protocolConfiguration);
   ::Uts::ErrorCode::type recv_configureProtocol();
  void getProtocolConfiguration( ::Uts::ProtocolConfigurationResult& _return, const int64_t protocolHandle);
  void send_getProtocolConfiguration(const int64_t protocolHandle);
  void recv_getProtocolConfiguration( ::Uts::ProtocolConfigurationResult& _return);
   ::Uts::ErrorCode::type enableProtocolDataMonitoring(const std::vector<int64_t> & protocolHandleList, const bool enable);
  void send_enableProtocolDataMonitoring(const std::vector<int64_t> & protocolHandleList, const bool enable);
   ::Uts::ErrorCode::type recv_enableProtocolDataMonitoring();
   ::Uts::ErrorCode::type enableDeviceDataMonitoring(const std::vector<int64_t> & deviceHandleList, const bool enable);
  void send_enableDeviceDataMonitoring(const std::vector<int64_t> & deviceHandleList, const bool enable);
   ::Uts::ErrorCode::type recv_enableDeviceDataMonitoring();
   ::Uts::ErrorCode::type enableDevicePriority(const std::vector<int64_t> & deviceHandleList, const bool enable);
  void send_enableDevicePriority(const std::vector<int64_t> & deviceHandleList, const bool enable);
   ::Uts::ErrorCode::type recv_enableDevicePriority();
   ::Uts::ErrorCode::type configParameter(const std::string& name, const std::string& value);
  void send_configParameter(const std::string& name, const std::string& value);
   ::Uts::ErrorCode::type recv_configParameter();
  int32_t getRegistrationPort();
  void send_getRegistrationPort();
  int32_t recv_getRegistrationPort();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class DeviceManagerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<DeviceManagerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (DeviceManagerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getServicesList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDevicesForService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getServicesForDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceHandleFromProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_mergeDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceBuildId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceImageInfoByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getChipName(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceMode(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getProtocolList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getActiveLogSession(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_overrideUnknownProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addTcpConnection(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addTcpConnectionWithOptions(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeTcpConnection(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startTcpServer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startTcpServerWithOptions(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_stopTcpServer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getTcpServerList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_startLogging(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_resetLogFiles(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_saveLogFiles(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_saveLogFilesWithFilenames(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getCurrentLogFileSize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_openLogSession(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_attachToLogSession(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_logAnnotation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_resetPhone(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_resetPhoneByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_restartQmiReadyScan(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setOperatingMode(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getThroughputStatistics(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getEsn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setEsn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getImei(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setImei(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getMeid(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setMeid(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_checkSpc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getOperatingMode(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_transferImageBhi(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_transferFileToDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_transferFileToHost(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getProtocolLockStatus(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDeviceUsageIndicators(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_enableFunctionLog(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_disableFunctionLog(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_enableProtocolLog(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_disableProtocolLog(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_configureProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getProtocolConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_enableProtocolDataMonitoring(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_enableDeviceDataMonitoring(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_enableDevicePriority(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_configParameter(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getRegistrationPort(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  DeviceManagerProcessor(::std::shared_ptr<DeviceManagerIf> iface) :
    iface_(iface) {
    processMap_["getLastError"] = &DeviceManagerProcessor::process_getLastError;
    processMap_["getServicesList"] = &DeviceManagerProcessor::process_getServicesList;
    processMap_["getDevicesForService"] = &DeviceManagerProcessor::process_getDevicesForService;
    processMap_["getServicesForDevice"] = &DeviceManagerProcessor::process_getServicesForDevice;
    processMap_["createService"] = &DeviceManagerProcessor::process_createService;
    processMap_["getDeviceList"] = &DeviceManagerProcessor::process_getDeviceList;
    processMap_["getDeviceHandleFromProtocol"] = &DeviceManagerProcessor::process_getDeviceHandleFromProtocol;
    processMap_["mergeDevice"] = &DeviceManagerProcessor::process_mergeDevice;
    processMap_["getDeviceBuildId"] = &DeviceManagerProcessor::process_getDeviceBuildId;
    processMap_["getDeviceImageInfoByProtocol"] = &DeviceManagerProcessor::process_getDeviceImageInfoByProtocol;
    processMap_["getChipName"] = &DeviceManagerProcessor::process_getChipName;
    processMap_["getDeviceMode"] = &DeviceManagerProcessor::process_getDeviceMode;
    processMap_["getProtocolList"] = &DeviceManagerProcessor::process_getProtocolList;
    processMap_["getActiveLogSession"] = &DeviceManagerProcessor::process_getActiveLogSession;
    processMap_["overrideUnknownProtocol"] = &DeviceManagerProcessor::process_overrideUnknownProtocol;
    processMap_["addTcpConnection"] = &DeviceManagerProcessor::process_addTcpConnection;
    processMap_["addTcpConnectionWithOptions"] = &DeviceManagerProcessor::process_addTcpConnectionWithOptions;
    processMap_["removeTcpConnection"] = &DeviceManagerProcessor::process_removeTcpConnection;
    processMap_["startTcpServer"] = &DeviceManagerProcessor::process_startTcpServer;
    processMap_["startTcpServerWithOptions"] = &DeviceManagerProcessor::process_startTcpServerWithOptions;
    processMap_["stopTcpServer"] = &DeviceManagerProcessor::process_stopTcpServer;
    processMap_["getTcpServerList"] = &DeviceManagerProcessor::process_getTcpServerList;
    processMap_["startLogging"] = &DeviceManagerProcessor::process_startLogging;
    processMap_["resetLogFiles"] = &DeviceManagerProcessor::process_resetLogFiles;
    processMap_["saveLogFiles"] = &DeviceManagerProcessor::process_saveLogFiles;
    processMap_["saveLogFilesWithFilenames"] = &DeviceManagerProcessor::process_saveLogFilesWithFilenames;
    processMap_["getCurrentLogFileSize"] = &DeviceManagerProcessor::process_getCurrentLogFileSize;
    processMap_["openLogSession"] = &DeviceManagerProcessor::process_openLogSession;
    processMap_["attachToLogSession"] = &DeviceManagerProcessor::process_attachToLogSession;
    processMap_["logAnnotation"] = &DeviceManagerProcessor::process_logAnnotation;
    processMap_["resetPhone"] = &DeviceManagerProcessor::process_resetPhone;
    processMap_["resetPhoneByProtocol"] = &DeviceManagerProcessor::process_resetPhoneByProtocol;
    processMap_["restartQmiReadyScan"] = &DeviceManagerProcessor::process_restartQmiReadyScan;
    processMap_["setOperatingMode"] = &DeviceManagerProcessor::process_setOperatingMode;
    processMap_["getThroughputStatistics"] = &DeviceManagerProcessor::process_getThroughputStatistics;
    processMap_["getEsn"] = &DeviceManagerProcessor::process_getEsn;
    processMap_["setEsn"] = &DeviceManagerProcessor::process_setEsn;
    processMap_["getImei"] = &DeviceManagerProcessor::process_getImei;
    processMap_["setImei"] = &DeviceManagerProcessor::process_setImei;
    processMap_["getMeid"] = &DeviceManagerProcessor::process_getMeid;
    processMap_["setMeid"] = &DeviceManagerProcessor::process_setMeid;
    processMap_["checkSpc"] = &DeviceManagerProcessor::process_checkSpc;
    processMap_["getOperatingMode"] = &DeviceManagerProcessor::process_getOperatingMode;
    processMap_["transferImageBhi"] = &DeviceManagerProcessor::process_transferImageBhi;
    processMap_["transferFileToDevice"] = &DeviceManagerProcessor::process_transferFileToDevice;
    processMap_["transferFileToHost"] = &DeviceManagerProcessor::process_transferFileToHost;
    processMap_["getProtocolLockStatus"] = &DeviceManagerProcessor::process_getProtocolLockStatus;
    processMap_["getDeviceUsageIndicators"] = &DeviceManagerProcessor::process_getDeviceUsageIndicators;
    processMap_["enableFunctionLog"] = &DeviceManagerProcessor::process_enableFunctionLog;
    processMap_["disableFunctionLog"] = &DeviceManagerProcessor::process_disableFunctionLog;
    processMap_["enableProtocolLog"] = &DeviceManagerProcessor::process_enableProtocolLog;
    processMap_["disableProtocolLog"] = &DeviceManagerProcessor::process_disableProtocolLog;
    processMap_["configureProtocol"] = &DeviceManagerProcessor::process_configureProtocol;
    processMap_["getProtocolConfiguration"] = &DeviceManagerProcessor::process_getProtocolConfiguration;
    processMap_["enableProtocolDataMonitoring"] = &DeviceManagerProcessor::process_enableProtocolDataMonitoring;
    processMap_["enableDeviceDataMonitoring"] = &DeviceManagerProcessor::process_enableDeviceDataMonitoring;
    processMap_["enableDevicePriority"] = &DeviceManagerProcessor::process_enableDevicePriority;
    processMap_["configParameter"] = &DeviceManagerProcessor::process_configParameter;
    processMap_["getRegistrationPort"] = &DeviceManagerProcessor::process_getRegistrationPort;
  }

  virtual ~DeviceManagerProcessor() {}
};

class DeviceManagerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  DeviceManagerProcessorFactory(const ::std::shared_ptr< DeviceManagerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< DeviceManagerIfFactory > handlerFactory_;
};

class DeviceManagerMultiface : virtual public DeviceManagerIf {
 public:
  DeviceManagerMultiface(std::vector<std::shared_ptr<DeviceManagerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~DeviceManagerMultiface() {}
 protected:
  std::vector<std::shared_ptr<DeviceManagerIf> > ifaces_;
  DeviceManagerMultiface() {}
  void add(::std::shared_ptr<DeviceManagerIf> iface) {
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

  void getServicesList(std::vector<std::string> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getServicesList(_return);
    }
    ifaces_[i]->getServicesList(_return);
    return;
  }

  void getDevicesForService(std::vector<int64_t> & _return, const std::string& serviceName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDevicesForService(_return, serviceName);
    }
    ifaces_[i]->getDevicesForService(_return, serviceName);
    return;
  }

  void getServicesForDevice(std::vector<std::string> & _return, const int64_t deviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getServicesForDevice(_return, deviceHandle);
    }
    ifaces_[i]->getServicesForDevice(_return, deviceHandle);
    return;
  }

  void createService(std::string& _return, const std::string& serviceName, const int64_t deviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createService(_return, serviceName, deviceHandle);
    }
    ifaces_[i]->createService(_return, serviceName, deviceHandle);
    return;
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

  int64_t getDeviceHandleFromProtocol(const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDeviceHandleFromProtocol(protocolHandle);
    }
    return ifaces_[i]->getDeviceHandleFromProtocol(protocolHandle);
  }

   ::Uts::ErrorCode::type mergeDevice(const int64_t sourceDeviceHandle, const int64_t destinationDeviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->mergeDevice(sourceDeviceHandle, destinationDeviceHandle);
    }
    return ifaces_[i]->mergeDevice(sourceDeviceHandle, destinationDeviceHandle);
  }

  void getDeviceBuildId( ::Uts::BuildInfo& _return, const int64_t deviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDeviceBuildId(_return, deviceHandle);
    }
    ifaces_[i]->getDeviceBuildId(_return, deviceHandle);
    return;
  }

  void getDeviceImageInfoByProtocol(std::vector< ::Uts::ImageInfo> & _return, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDeviceImageInfoByProtocol(_return, protocolHandle);
    }
    ifaces_[i]->getDeviceImageInfoByProtocol(_return, protocolHandle);
    return;
  }

  void getChipName(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getChipName(_return, deviceHandle, protocolHandle);
    }
    ifaces_[i]->getChipName(_return, deviceHandle, protocolHandle);
    return;
  }

   ::Uts::DeviceMode::type getDeviceMode(const int64_t deviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDeviceMode(deviceHandle);
    }
    return ifaces_[i]->getDeviceMode(deviceHandle);
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

  void getActiveLogSession(std::string& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getActiveLogSession(_return);
    }
    ifaces_[i]->getActiveLogSession(_return);
    return;
  }

   ::Uts::ErrorCode::type overrideUnknownProtocol(const int64_t protocolHandle, const  ::Uts::ProtocolType::type newType) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->overrideUnknownProtocol(protocolHandle, newType);
    }
    return ifaces_[i]->overrideUnknownProtocol(protocolHandle, newType);
  }

  void addTcpConnection( ::Uts::ProtocolInfo& _return, const int64_t deviceHandle, const  ::Uts::ProtocolType::type protocolType, const bool bIsClient, const std::string& description, const std::string& host, const int32_t port) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addTcpConnection(_return, deviceHandle, protocolType, bIsClient, description, host, port);
    }
    ifaces_[i]->addTcpConnection(_return, deviceHandle, protocolType, bIsClient, description, host, port);
    return;
  }

  void addTcpConnectionWithOptions( ::Uts::ProtocolInfo& _return, const std::string& host, const int32_t port, const  ::Uts::TcpOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addTcpConnectionWithOptions(_return, host, port, options);
    }
    ifaces_[i]->addTcpConnectionWithOptions(_return, host, port, options);
    return;
  }

   ::Uts::ErrorCode::type removeTcpConnection(const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeTcpConnection(protocolHandle);
    }
    return ifaces_[i]->removeTcpConnection(protocolHandle);
  }

   ::Uts::ErrorCode::type startTcpServer(const  ::Uts::ProtocolType::type protocolType, const int32_t port) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->startTcpServer(protocolType, port);
    }
    return ifaces_[i]->startTcpServer(protocolType, port);
  }

   ::Uts::ErrorCode::type startTcpServerWithOptions(const int32_t port, const  ::Uts::TcpOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->startTcpServerWithOptions(port, options);
    }
    return ifaces_[i]->startTcpServerWithOptions(port, options);
  }

   ::Uts::ErrorCode::type stopTcpServer(const int32_t port) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->stopTcpServer(port);
    }
    return ifaces_[i]->stopTcpServer(port);
  }

  void getTcpServerList(std::vector<int32_t> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getTcpServerList(_return);
    }
    ifaces_[i]->getTcpServerList(_return);
    return;
  }

   ::Uts::ErrorCode::type startLogging() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->startLogging();
    }
    return ifaces_[i]->startLogging();
  }

   ::Uts::ErrorCode::type resetLogFiles() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->resetLogFiles();
    }
    return ifaces_[i]->resetLogFiles();
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

  void saveLogFilesWithFilenames(std::vector<std::string> & _return, const std::map<int64_t, std::string> & logNameConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->saveLogFilesWithFilenames(_return, logNameConfig);
    }
    ifaces_[i]->saveLogFilesWithFilenames(_return, logNameConfig);
    return;
  }

  int64_t getCurrentLogFileSize(const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getCurrentLogFileSize(protocolHandle);
    }
    return ifaces_[i]->getCurrentLogFileSize(protocolHandle);
  }

  void openLogSession(std::string& _return, const std::vector<std::string> & logFiles) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->openLogSession(_return, logFiles);
    }
    ifaces_[i]->openLogSession(_return, logFiles);
    return;
  }

  void attachToLogSession(std::string& _return, const int32_t clientId, const std::string& logSession) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->attachToLogSession(_return, clientId, logSession);
    }
    ifaces_[i]->attachToLogSession(_return, clientId, logSession);
    return;
  }

   ::Uts::ErrorCode::type logAnnotation(const std::string& annotation, const int64_t messageId, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->logAnnotation(annotation, messageId, protocolHandle);
    }
    return ifaces_[i]->logAnnotation(annotation, messageId, protocolHandle);
  }

   ::Uts::ErrorCode::type resetPhone(const int64_t deviceHandle, const int32_t resetTimeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->resetPhone(deviceHandle, resetTimeout);
    }
    return ifaces_[i]->resetPhone(deviceHandle, resetTimeout);
  }

   ::Uts::ErrorCode::type resetPhoneByProtocol(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t resetTimeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->resetPhoneByProtocol(deviceHandle, protocolHandle, resetTimeout);
    }
    return ifaces_[i]->resetPhoneByProtocol(deviceHandle, protocolHandle, resetTimeout);
  }

   ::Uts::ErrorCode::type restartQmiReadyScan(const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->restartQmiReadyScan(protocolHandle);
    }
    return ifaces_[i]->restartQmiReadyScan(protocolHandle);
  }

   ::Uts::ErrorCode::type setOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle, const OperatingMode::type mode) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setOperatingMode(deviceHandle, protocolHandle, mode);
    }
    return ifaces_[i]->setOperatingMode(deviceHandle, protocolHandle, mode);
  }

  void getThroughputStatistics( ::Uts::RxTxInfo& _return, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getThroughputStatistics(_return, protocolHandle);
    }
    ifaces_[i]->getThroughputStatistics(_return, protocolHandle);
    return;
  }

  int32_t getEsn(const int64_t deviceHandle, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getEsn(deviceHandle, protocolHandle);
    }
    return ifaces_[i]->getEsn(deviceHandle, protocolHandle);
  }

   ::Uts::ErrorCode::type setEsn(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t esn) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setEsn(deviceHandle, protocolHandle, esn);
    }
    return ifaces_[i]->setEsn(deviceHandle, protocolHandle, esn);
  }

  void getImei(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getImei(_return, deviceHandle, protocolHandle, subscriptionId);
    }
    ifaces_[i]->getImei(_return, deviceHandle, protocolHandle, subscriptionId);
    return;
  }

   ::Uts::ErrorCode::type setImei(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& imei, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setImei(deviceHandle, protocolHandle, imei, subscriptionId);
    }
    return ifaces_[i]->setImei(deviceHandle, protocolHandle, imei, subscriptionId);
  }

  int64_t getMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getMeid(deviceHandle, protocolHandle, subscriptionId);
    }
    return ifaces_[i]->getMeid(deviceHandle, protocolHandle, subscriptionId);
  }

   ::Uts::ErrorCode::type setMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int64_t meid, const int32_t subscriptionId) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setMeid(deviceHandle, protocolHandle, meid, subscriptionId);
    }
    return ifaces_[i]->setMeid(deviceHandle, protocolHandle, meid, subscriptionId);
  }

  void checkSpc(SpcStatus& _return, const int64_t deviceHandle, const int64_t protocolHandle, const std::string& spc) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->checkSpc(_return, deviceHandle, protocolHandle, spc);
    }
    ifaces_[i]->checkSpc(_return, deviceHandle, protocolHandle, spc);
    return;
  }

  void getOperatingMode(OperatingModeInfo& _return, const int64_t deviceHandle, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getOperatingMode(_return, deviceHandle, protocolHandle);
    }
    ifaces_[i]->getOperatingMode(_return, deviceHandle, protocolHandle);
    return;
  }

   ::Uts::ErrorCode::type transferImageBhi(const std::string& programmerPath) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->transferImageBhi(programmerPath);
    }
    return ifaces_[i]->transferImageBhi(programmerPath);
  }

  void transferFileToDevice( ::Uts::TransferFileResult& _return, const std::string& hostPath, const std::string& devicePath, const  ::Uts::TransferFileOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->transferFileToDevice(_return, hostPath, devicePath, options);
    }
    ifaces_[i]->transferFileToDevice(_return, hostPath, devicePath, options);
    return;
  }

  void transferFileToHost( ::Uts::TransferFileResult& _return, const std::string& devicePath, const std::string& hostPath, const  ::Uts::TransferFileOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->transferFileToHost(_return, devicePath, hostPath, options);
    }
    ifaces_[i]->transferFileToHost(_return, devicePath, hostPath, options);
    return;
  }

  void getProtocolLockStatus( ::Uts::LockStatus& _return, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getProtocolLockStatus(_return, protocolHandle);
    }
    ifaces_[i]->getProtocolLockStatus(_return, protocolHandle);
    return;
  }

  void getDeviceUsageIndicators( ::Uts::UsageIndicators& _return, const int64_t deviceHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDeviceUsageIndicators(_return, deviceHandle);
    }
    ifaces_[i]->getDeviceUsageIndicators(_return, deviceHandle);
    return;
  }

   ::Uts::ErrorCode::type enableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas, const  ::Uts::LogOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->enableFunctionLog(deviceHandle, areas, options);
    }
    return ifaces_[i]->enableFunctionLog(deviceHandle, areas, options);
  }

   ::Uts::ErrorCode::type disableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->disableFunctionLog(deviceHandle, areas);
    }
    return ifaces_[i]->disableFunctionLog(deviceHandle, areas);
  }

   ::Uts::ErrorCode::type enableProtocolLog(const int64_t protocolHandle, const  ::Uts::LogOptions& options) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->enableProtocolLog(protocolHandle, options);
    }
    return ifaces_[i]->enableProtocolLog(protocolHandle, options);
  }

   ::Uts::ErrorCode::type disableProtocolLog(const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->disableProtocolLog(protocolHandle);
    }
    return ifaces_[i]->disableProtocolLog(protocolHandle);
  }

   ::Uts::ErrorCode::type configureProtocol(const  ::Uts::ProtocolConfiguration& protocolConfiguration) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->configureProtocol(protocolConfiguration);
    }
    return ifaces_[i]->configureProtocol(protocolConfiguration);
  }

  void getProtocolConfiguration( ::Uts::ProtocolConfigurationResult& _return, const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getProtocolConfiguration(_return, protocolHandle);
    }
    ifaces_[i]->getProtocolConfiguration(_return, protocolHandle);
    return;
  }

   ::Uts::ErrorCode::type enableProtocolDataMonitoring(const std::vector<int64_t> & protocolHandleList, const bool enable) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->enableProtocolDataMonitoring(protocolHandleList, enable);
    }
    return ifaces_[i]->enableProtocolDataMonitoring(protocolHandleList, enable);
  }

   ::Uts::ErrorCode::type enableDeviceDataMonitoring(const std::vector<int64_t> & deviceHandleList, const bool enable) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->enableDeviceDataMonitoring(deviceHandleList, enable);
    }
    return ifaces_[i]->enableDeviceDataMonitoring(deviceHandleList, enable);
  }

   ::Uts::ErrorCode::type enableDevicePriority(const std::vector<int64_t> & deviceHandleList, const bool enable) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->enableDevicePriority(deviceHandleList, enable);
    }
    return ifaces_[i]->enableDevicePriority(deviceHandleList, enable);
  }

   ::Uts::ErrorCode::type configParameter(const std::string& name, const std::string& value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->configParameter(name, value);
    }
    return ifaces_[i]->configParameter(name, value);
  }

  int32_t getRegistrationPort() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getRegistrationPort();
    }
    return ifaces_[i]->getRegistrationPort();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class DeviceManagerConcurrentClient : virtual public DeviceManagerIf {
 public:
  DeviceManagerConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  DeviceManagerConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
  void getServicesList(std::vector<std::string> & _return);
  int32_t send_getServicesList();
  void recv_getServicesList(std::vector<std::string> & _return, const int32_t seqid);
  void getDevicesForService(std::vector<int64_t> & _return, const std::string& serviceName);
  int32_t send_getDevicesForService(const std::string& serviceName);
  void recv_getDevicesForService(std::vector<int64_t> & _return, const int32_t seqid);
  void getServicesForDevice(std::vector<std::string> & _return, const int64_t deviceHandle);
  int32_t send_getServicesForDevice(const int64_t deviceHandle);
  void recv_getServicesForDevice(std::vector<std::string> & _return, const int32_t seqid);
  void createService(std::string& _return, const std::string& serviceName, const int64_t deviceHandle);
  int32_t send_createService(const std::string& serviceName, const int64_t deviceHandle);
  void recv_createService(std::string& _return, const int32_t seqid);
  void getDeviceList(std::vector< ::Uts::DeviceInfo> & _return);
  int32_t send_getDeviceList();
  void recv_getDeviceList(std::vector< ::Uts::DeviceInfo> & _return, const int32_t seqid);
  int64_t getDeviceHandleFromProtocol(const int64_t protocolHandle);
  int32_t send_getDeviceHandleFromProtocol(const int64_t protocolHandle);
  int64_t recv_getDeviceHandleFromProtocol(const int32_t seqid);
   ::Uts::ErrorCode::type mergeDevice(const int64_t sourceDeviceHandle, const int64_t destinationDeviceHandle);
  int32_t send_mergeDevice(const int64_t sourceDeviceHandle, const int64_t destinationDeviceHandle);
   ::Uts::ErrorCode::type recv_mergeDevice(const int32_t seqid);
  void getDeviceBuildId( ::Uts::BuildInfo& _return, const int64_t deviceHandle);
  int32_t send_getDeviceBuildId(const int64_t deviceHandle);
  void recv_getDeviceBuildId( ::Uts::BuildInfo& _return, const int32_t seqid);
  void getDeviceImageInfoByProtocol(std::vector< ::Uts::ImageInfo> & _return, const int64_t protocolHandle);
  int32_t send_getDeviceImageInfoByProtocol(const int64_t protocolHandle);
  void recv_getDeviceImageInfoByProtocol(std::vector< ::Uts::ImageInfo> & _return, const int32_t seqid);
  void getChipName(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle);
  int32_t send_getChipName(const int64_t deviceHandle, const int64_t protocolHandle);
  void recv_getChipName(std::string& _return, const int32_t seqid);
   ::Uts::DeviceMode::type getDeviceMode(const int64_t deviceHandle);
  int32_t send_getDeviceMode(const int64_t deviceHandle);
   ::Uts::DeviceMode::type recv_getDeviceMode(const int32_t seqid);
  void getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int64_t deviceHandle);
  int32_t send_getProtocolList(const int64_t deviceHandle);
  void recv_getProtocolList(std::vector< ::Uts::ProtocolInfo> & _return, const int32_t seqid);
  void getActiveLogSession(std::string& _return);
  int32_t send_getActiveLogSession();
  void recv_getActiveLogSession(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type overrideUnknownProtocol(const int64_t protocolHandle, const  ::Uts::ProtocolType::type newType);
  int32_t send_overrideUnknownProtocol(const int64_t protocolHandle, const  ::Uts::ProtocolType::type newType);
   ::Uts::ErrorCode::type recv_overrideUnknownProtocol(const int32_t seqid);
  void addTcpConnection( ::Uts::ProtocolInfo& _return, const int64_t deviceHandle, const  ::Uts::ProtocolType::type protocolType, const bool bIsClient, const std::string& description, const std::string& host, const int32_t port);
  int32_t send_addTcpConnection(const int64_t deviceHandle, const  ::Uts::ProtocolType::type protocolType, const bool bIsClient, const std::string& description, const std::string& host, const int32_t port);
  void recv_addTcpConnection( ::Uts::ProtocolInfo& _return, const int32_t seqid);
  void addTcpConnectionWithOptions( ::Uts::ProtocolInfo& _return, const std::string& host, const int32_t port, const  ::Uts::TcpOptions& options);
  int32_t send_addTcpConnectionWithOptions(const std::string& host, const int32_t port, const  ::Uts::TcpOptions& options);
  void recv_addTcpConnectionWithOptions( ::Uts::ProtocolInfo& _return, const int32_t seqid);
   ::Uts::ErrorCode::type removeTcpConnection(const int64_t protocolHandle);
  int32_t send_removeTcpConnection(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_removeTcpConnection(const int32_t seqid);
   ::Uts::ErrorCode::type startTcpServer(const  ::Uts::ProtocolType::type protocolType, const int32_t port);
  int32_t send_startTcpServer(const  ::Uts::ProtocolType::type protocolType, const int32_t port);
   ::Uts::ErrorCode::type recv_startTcpServer(const int32_t seqid);
   ::Uts::ErrorCode::type startTcpServerWithOptions(const int32_t port, const  ::Uts::TcpOptions& options);
  int32_t send_startTcpServerWithOptions(const int32_t port, const  ::Uts::TcpOptions& options);
   ::Uts::ErrorCode::type recv_startTcpServerWithOptions(const int32_t seqid);
   ::Uts::ErrorCode::type stopTcpServer(const int32_t port);
  int32_t send_stopTcpServer(const int32_t port);
   ::Uts::ErrorCode::type recv_stopTcpServer(const int32_t seqid);
  void getTcpServerList(std::vector<int32_t> & _return);
  int32_t send_getTcpServerList();
  void recv_getTcpServerList(std::vector<int32_t> & _return, const int32_t seqid);
   ::Uts::ErrorCode::type startLogging();
  int32_t send_startLogging();
   ::Uts::ErrorCode::type recv_startLogging(const int32_t seqid);
   ::Uts::ErrorCode::type resetLogFiles();
  int32_t send_resetLogFiles();
   ::Uts::ErrorCode::type recv_resetLogFiles(const int32_t seqid);
  void saveLogFiles(std::vector<std::string> & _return, const std::string& saveFolder);
  int32_t send_saveLogFiles(const std::string& saveFolder);
  void recv_saveLogFiles(std::vector<std::string> & _return, const int32_t seqid);
  void saveLogFilesWithFilenames(std::vector<std::string> & _return, const std::map<int64_t, std::string> & logNameConfig);
  int32_t send_saveLogFilesWithFilenames(const std::map<int64_t, std::string> & logNameConfig);
  void recv_saveLogFilesWithFilenames(std::vector<std::string> & _return, const int32_t seqid);
  int64_t getCurrentLogFileSize(const int64_t protocolHandle);
  int32_t send_getCurrentLogFileSize(const int64_t protocolHandle);
  int64_t recv_getCurrentLogFileSize(const int32_t seqid);
  void openLogSession(std::string& _return, const std::vector<std::string> & logFiles);
  int32_t send_openLogSession(const std::vector<std::string> & logFiles);
  void recv_openLogSession(std::string& _return, const int32_t seqid);
  void attachToLogSession(std::string& _return, const int32_t clientId, const std::string& logSession);
  int32_t send_attachToLogSession(const int32_t clientId, const std::string& logSession);
  void recv_attachToLogSession(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type logAnnotation(const std::string& annotation, const int64_t messageId, const int64_t protocolHandle);
  int32_t send_logAnnotation(const std::string& annotation, const int64_t messageId, const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_logAnnotation(const int32_t seqid);
   ::Uts::ErrorCode::type resetPhone(const int64_t deviceHandle, const int32_t resetTimeout);
  int32_t send_resetPhone(const int64_t deviceHandle, const int32_t resetTimeout);
   ::Uts::ErrorCode::type recv_resetPhone(const int32_t seqid);
   ::Uts::ErrorCode::type resetPhoneByProtocol(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t resetTimeout);
  int32_t send_resetPhoneByProtocol(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t resetTimeout);
   ::Uts::ErrorCode::type recv_resetPhoneByProtocol(const int32_t seqid);
   ::Uts::ErrorCode::type restartQmiReadyScan(const int64_t protocolHandle);
  int32_t send_restartQmiReadyScan(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_restartQmiReadyScan(const int32_t seqid);
   ::Uts::ErrorCode::type setOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle, const OperatingMode::type mode);
  int32_t send_setOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle, const OperatingMode::type mode);
   ::Uts::ErrorCode::type recv_setOperatingMode(const int32_t seqid);
  void getThroughputStatistics( ::Uts::RxTxInfo& _return, const int64_t protocolHandle);
  int32_t send_getThroughputStatistics(const int64_t protocolHandle);
  void recv_getThroughputStatistics( ::Uts::RxTxInfo& _return, const int32_t seqid);
  int32_t getEsn(const int64_t deviceHandle, const int64_t protocolHandle);
  int32_t send_getEsn(const int64_t deviceHandle, const int64_t protocolHandle);
  int32_t recv_getEsn(const int32_t seqid);
   ::Uts::ErrorCode::type setEsn(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t esn);
  int32_t send_setEsn(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t esn);
   ::Uts::ErrorCode::type recv_setEsn(const int32_t seqid);
  void getImei(std::string& _return, const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId);
  int32_t send_getImei(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId);
  void recv_getImei(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type setImei(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& imei, const int32_t subscriptionId);
  int32_t send_setImei(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& imei, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_setImei(const int32_t seqid);
  int64_t getMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId);
  int32_t send_getMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int32_t subscriptionId);
  int64_t recv_getMeid(const int32_t seqid);
   ::Uts::ErrorCode::type setMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int64_t meid, const int32_t subscriptionId);
  int32_t send_setMeid(const int64_t deviceHandle, const int64_t protocolHandle, const int64_t meid, const int32_t subscriptionId);
   ::Uts::ErrorCode::type recv_setMeid(const int32_t seqid);
  void checkSpc(SpcStatus& _return, const int64_t deviceHandle, const int64_t protocolHandle, const std::string& spc);
  int32_t send_checkSpc(const int64_t deviceHandle, const int64_t protocolHandle, const std::string& spc);
  void recv_checkSpc(SpcStatus& _return, const int32_t seqid);
  void getOperatingMode(OperatingModeInfo& _return, const int64_t deviceHandle, const int64_t protocolHandle);
  int32_t send_getOperatingMode(const int64_t deviceHandle, const int64_t protocolHandle);
  void recv_getOperatingMode(OperatingModeInfo& _return, const int32_t seqid);
   ::Uts::ErrorCode::type transferImageBhi(const std::string& programmerPath);
  int32_t send_transferImageBhi(const std::string& programmerPath);
   ::Uts::ErrorCode::type recv_transferImageBhi(const int32_t seqid);
  void transferFileToDevice( ::Uts::TransferFileResult& _return, const std::string& hostPath, const std::string& devicePath, const  ::Uts::TransferFileOptions& options);
  int32_t send_transferFileToDevice(const std::string& hostPath, const std::string& devicePath, const  ::Uts::TransferFileOptions& options);
  void recv_transferFileToDevice( ::Uts::TransferFileResult& _return, const int32_t seqid);
  void transferFileToHost( ::Uts::TransferFileResult& _return, const std::string& devicePath, const std::string& hostPath, const  ::Uts::TransferFileOptions& options);
  int32_t send_transferFileToHost(const std::string& devicePath, const std::string& hostPath, const  ::Uts::TransferFileOptions& options);
  void recv_transferFileToHost( ::Uts::TransferFileResult& _return, const int32_t seqid);
  void getProtocolLockStatus( ::Uts::LockStatus& _return, const int64_t protocolHandle);
  int32_t send_getProtocolLockStatus(const int64_t protocolHandle);
  void recv_getProtocolLockStatus( ::Uts::LockStatus& _return, const int32_t seqid);
  void getDeviceUsageIndicators( ::Uts::UsageIndicators& _return, const int64_t deviceHandle);
  int32_t send_getDeviceUsageIndicators(const int64_t deviceHandle);
  void recv_getDeviceUsageIndicators( ::Uts::UsageIndicators& _return, const int32_t seqid);
   ::Uts::ErrorCode::type enableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas, const  ::Uts::LogOptions& options);
  int32_t send_enableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas, const  ::Uts::LogOptions& options);
   ::Uts::ErrorCode::type recv_enableFunctionLog(const int32_t seqid);
   ::Uts::ErrorCode::type disableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas);
  int32_t send_disableFunctionLog(const int64_t deviceHandle, const std::vector< ::Uts::FunctionArea::type> & areas);
   ::Uts::ErrorCode::type recv_disableFunctionLog(const int32_t seqid);
   ::Uts::ErrorCode::type enableProtocolLog(const int64_t protocolHandle, const  ::Uts::LogOptions& options);
  int32_t send_enableProtocolLog(const int64_t protocolHandle, const  ::Uts::LogOptions& options);
   ::Uts::ErrorCode::type recv_enableProtocolLog(const int32_t seqid);
   ::Uts::ErrorCode::type disableProtocolLog(const int64_t protocolHandle);
  int32_t send_disableProtocolLog(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_disableProtocolLog(const int32_t seqid);
   ::Uts::ErrorCode::type configureProtocol(const  ::Uts::ProtocolConfiguration& protocolConfiguration);
  int32_t send_configureProtocol(const  ::Uts::ProtocolConfiguration& protocolConfiguration);
   ::Uts::ErrorCode::type recv_configureProtocol(const int32_t seqid);
  void getProtocolConfiguration( ::Uts::ProtocolConfigurationResult& _return, const int64_t protocolHandle);
  int32_t send_getProtocolConfiguration(const int64_t protocolHandle);
  void recv_getProtocolConfiguration( ::Uts::ProtocolConfigurationResult& _return, const int32_t seqid);
   ::Uts::ErrorCode::type enableProtocolDataMonitoring(const std::vector<int64_t> & protocolHandleList, const bool enable);
  int32_t send_enableProtocolDataMonitoring(const std::vector<int64_t> & protocolHandleList, const bool enable);
   ::Uts::ErrorCode::type recv_enableProtocolDataMonitoring(const int32_t seqid);
   ::Uts::ErrorCode::type enableDeviceDataMonitoring(const std::vector<int64_t> & deviceHandleList, const bool enable);
  int32_t send_enableDeviceDataMonitoring(const std::vector<int64_t> & deviceHandleList, const bool enable);
   ::Uts::ErrorCode::type recv_enableDeviceDataMonitoring(const int32_t seqid);
   ::Uts::ErrorCode::type enableDevicePriority(const std::vector<int64_t> & deviceHandleList, const bool enable);
  int32_t send_enableDevicePriority(const std::vector<int64_t> & deviceHandleList, const bool enable);
   ::Uts::ErrorCode::type recv_enableDevicePriority(const int32_t seqid);
   ::Uts::ErrorCode::type configParameter(const std::string& name, const std::string& value);
  int32_t send_configParameter(const std::string& name, const std::string& value);
   ::Uts::ErrorCode::type recv_configParameter(const int32_t seqid);
  int32_t getRegistrationPort();
  int32_t send_getRegistrationPort();
  int32_t recv_getRegistrationPort(const int32_t seqid);
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
