/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DiagService_H
#define DiagService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "DiagService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class DiagServiceIf {
 public:
  virtual ~DiagServiceIf() {}
  virtual void getLastError( ::Uts::ErrorType& _return) = 0;
  virtual int64_t getDevice() = 0;
  virtual  ::Uts::ErrorCode::type initializeService() = 0;
  virtual  ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type initializeServiceWithOptions(const DiagConnectionOptions& diagConnectionOptions) = 0;
  virtual  ::Uts::ErrorCode::type destroyService() = 0;
  virtual void sendRawRequest( ::Uts::DiagPacket& _return, const std::string& request, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) = 0;
  virtual int64_t sendRawRequestAsync(const std::string& request) = 0;
  virtual void sendRequest( ::Uts::DiagPacket& _return, const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) = 0;
  virtual int64_t sendRequestAsync(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList) = 0;
  virtual void getResponseAsync( ::Uts::DiagPacket& _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) = 0;
  virtual void getAllResponsesAsync(std::vector< ::Uts::DiagPacket> & _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) = 0;
  virtual  ::Uts::ErrorCode::type createDataQueue(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::DiagReturnConfig& returnConfig) = 0;
  virtual  ::Uts::ErrorCode::type createDataQueueWithAnnotations(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::AnnotationPacketFilter& annotationsFilter, const  ::Uts::DiagReturnConfig& returnConfig) = 0;
  virtual  ::Uts::ErrorCode::type removeDataQueue(const std::string& queueName) = 0;
  virtual  ::Uts::ErrorCode::type clearDataQueue(const std::string& queueName) = 0;
  virtual void getDataQueueItems(std::vector< ::Uts::DiagPacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout) = 0;
  virtual void getDataQueueItemsWithAnnotations(std::vector<DataQueuePacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout) = 0;
  virtual  ::Uts::ErrorCode::type addDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter) = 0;
  virtual  ::Uts::ErrorCode::type removeDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter) = 0;
  virtual  ::Uts::ErrorCode::type setLoggingMask(const std::string& maskFileContent, const  ::Uts::LogMaskFormat::type format) = 0;
  virtual  ::Uts::QShrink4DownloadState::type getQShrinkState() = 0;
  virtual void loadQShrinkFile(const std::string& pathName) = 0;
  virtual  ::Uts::ErrorCode::type setWcdmaProtocolRevision(const  ::Uts::WcdmaProtocolRevision::type revision) = 0;
  virtual  ::Uts::ErrorCode::type setCdmaProtocolRevision(const  ::Uts::CdmaProtocolRevision::type revision) = 0;
  virtual  ::Uts::ErrorCode::type setPilotInc(const int16_t pilotInc) = 0;
  virtual  ::Uts::ErrorCode::type setLoggingMaskFromFilter(const  ::Uts::DiagPacketFilter& filter) = 0;
  virtual HealthReportConfigureStatus::type resetHealthReportCounters(const Subsystem::type subsystem) = 0;
  virtual HealthReportConfigureStatus::type setHealthReportTimer(const Subsystem::type subsystem, const int32_t timer) = 0;
};

class DiagServiceIfFactory {
 public:
  typedef DiagServiceIf Handler;

  virtual ~DiagServiceIfFactory() {}

  virtual DiagServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(DiagServiceIf* /* handler */) = 0;
};

class DiagServiceIfSingletonFactory : virtual public DiagServiceIfFactory {
 public:
  DiagServiceIfSingletonFactory(const ::std::shared_ptr<DiagServiceIf>& iface) : iface_(iface) {}
  virtual ~DiagServiceIfSingletonFactory() {}

  virtual DiagServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(DiagServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<DiagServiceIf> iface_;
};

class DiagServiceNull : virtual public DiagServiceIf {
 public:
  virtual ~DiagServiceNull() {}
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
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t /* protocolHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type initializeServiceWithOptions(const DiagConnectionOptions& /* diagConnectionOptions */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type destroyService() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void sendRawRequest( ::Uts::DiagPacket& /* _return */, const std::string& /* request */, const  ::Uts::DiagReturns& /* returnConfig */, const int32_t /* timeout */) {
    return;
  }
  int64_t sendRawRequestAsync(const std::string& /* request */) {
    int64_t _return = 0;
    return _return;
  }
  void sendRequest( ::Uts::DiagPacket& /* _return */, const  ::Uts::DiagPacketType::type /* requestType */, const std::string& /* requestIdOrName */, const std::string& /* fieldList */, const  ::Uts::DiagReturns& /* returnConfig */, const int32_t /* timeout */) {
    return;
  }
  int64_t sendRequestAsync(const  ::Uts::DiagPacketType::type /* requestType */, const std::string& /* requestIdOrName */, const std::string& /* fieldList */) {
    int64_t _return = 0;
    return _return;
  }
  void getResponseAsync( ::Uts::DiagPacket& /* _return */, const int64_t /* transactionId */, const  ::Uts::DiagReturns& /* returnConfig */, const int32_t /* timeout */) {
    return;
  }
  void getAllResponsesAsync(std::vector< ::Uts::DiagPacket> & /* _return */, const int64_t /* transactionId */, const  ::Uts::DiagReturns& /* returnConfig */, const int32_t /* timeout */) {
    return;
  }
   ::Uts::ErrorCode::type createDataQueue(const std::string& /* queueName */, const  ::Uts::DiagPacketFilter& /* filter */, const  ::Uts::DiagReturnConfig& /* returnConfig */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type createDataQueueWithAnnotations(const std::string& /* queueName */, const  ::Uts::DiagPacketFilter& /* filter */, const  ::Uts::AnnotationPacketFilter& /* annotationsFilter */, const  ::Uts::DiagReturnConfig& /* returnConfig */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type removeDataQueue(const std::string& /* queueName */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type clearDataQueue(const std::string& /* queueName */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void getDataQueueItems(std::vector< ::Uts::DiagPacket> & /* _return */, const std::string& /* queueName */, const int32_t /* count */, const int32_t /* timeout */) {
    return;
  }
  void getDataQueueItemsWithAnnotations(std::vector<DataQueuePacket> & /* _return */, const std::string& /* queueName */, const int32_t /* count */, const int32_t /* timeout */) {
    return;
  }
   ::Uts::ErrorCode::type addDataQueueFilter(const std::string& /* queueName */, const  ::Uts::DiagPacketFilter& /* filter */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type removeDataQueueFilter(const std::string& /* queueName */, const  ::Uts::DiagPacketFilter& /* filter */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setLoggingMask(const std::string& /* maskFileContent */, const  ::Uts::LogMaskFormat::type /* format */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::QShrink4DownloadState::type getQShrinkState() {
     ::Uts::QShrink4DownloadState::type _return = ( ::Uts::QShrink4DownloadState::type)0;
    return _return;
  }
  void loadQShrinkFile(const std::string& /* pathName */) {
    return;
  }
   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const  ::Uts::WcdmaProtocolRevision::type /* revision */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setCdmaProtocolRevision(const  ::Uts::CdmaProtocolRevision::type /* revision */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setPilotInc(const int16_t /* pilotInc */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setLoggingMaskFromFilter(const  ::Uts::DiagPacketFilter& /* filter */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  HealthReportConfigureStatus::type resetHealthReportCounters(const Subsystem::type /* subsystem */) {
    HealthReportConfigureStatus::type _return = (HealthReportConfigureStatus::type)0;
    return _return;
  }
  HealthReportConfigureStatus::type setHealthReportTimer(const Subsystem::type /* subsystem */, const int32_t /* timer */) {
    HealthReportConfigureStatus::type _return = (HealthReportConfigureStatus::type)0;
    return _return;
  }
};


class DiagService_getLastError_args {
 public:

  DiagService_getLastError_args(const DiagService_getLastError_args&);
  DiagService_getLastError_args& operator=(const DiagService_getLastError_args&);
  DiagService_getLastError_args() {
  }

  virtual ~DiagService_getLastError_args() noexcept;

  bool operator == (const DiagService_getLastError_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiagService_getLastError_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getLastError_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_getLastError_pargs {
 public:


  virtual ~DiagService_getLastError_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getLastError_result__isset {
  _DiagService_getLastError_result__isset() : success(false) {}
  bool success :1;
} _DiagService_getLastError_result__isset;

class DiagService_getLastError_result {
 public:

  DiagService_getLastError_result(const DiagService_getLastError_result&);
  DiagService_getLastError_result& operator=(const DiagService_getLastError_result&);
  DiagService_getLastError_result() {
  }

  virtual ~DiagService_getLastError_result() noexcept;
   ::Uts::ErrorType success;

  _DiagService_getLastError_result__isset __isset;

  void __set_success(const  ::Uts::ErrorType& val);

  bool operator == (const DiagService_getLastError_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const DiagService_getLastError_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getLastError_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getLastError_presult__isset {
  _DiagService_getLastError_presult__isset() : success(false) {}
  bool success :1;
} _DiagService_getLastError_presult__isset;

class DiagService_getLastError_presult {
 public:


  virtual ~DiagService_getLastError_presult() noexcept;
   ::Uts::ErrorType* success;

  _DiagService_getLastError_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DiagService_getDevice_args {
 public:

  DiagService_getDevice_args(const DiagService_getDevice_args&);
  DiagService_getDevice_args& operator=(const DiagService_getDevice_args&);
  DiagService_getDevice_args() {
  }

  virtual ~DiagService_getDevice_args() noexcept;

  bool operator == (const DiagService_getDevice_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiagService_getDevice_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getDevice_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_getDevice_pargs {
 public:


  virtual ~DiagService_getDevice_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getDevice_result__isset {
  _DiagService_getDevice_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getDevice_result__isset;

class DiagService_getDevice_result {
 public:

  DiagService_getDevice_result(const DiagService_getDevice_result&);
  DiagService_getDevice_result& operator=(const DiagService_getDevice_result&);
  DiagService_getDevice_result() : success(0) {
  }

  virtual ~DiagService_getDevice_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DiagService_getDevice_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_getDevice_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_getDevice_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getDevice_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getDevice_presult__isset {
  _DiagService_getDevice_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getDevice_presult__isset;

class DiagService_getDevice_presult {
 public:


  virtual ~DiagService_getDevice_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DiagService_getDevice_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DiagService_initializeService_args {
 public:

  DiagService_initializeService_args(const DiagService_initializeService_args&);
  DiagService_initializeService_args& operator=(const DiagService_initializeService_args&);
  DiagService_initializeService_args() {
  }

  virtual ~DiagService_initializeService_args() noexcept;

  bool operator == (const DiagService_initializeService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiagService_initializeService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_initializeService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_initializeService_pargs {
 public:


  virtual ~DiagService_initializeService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_initializeService_result__isset {
  _DiagService_initializeService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_initializeService_result__isset;

class DiagService_initializeService_result {
 public:

  DiagService_initializeService_result(const DiagService_initializeService_result&);
  DiagService_initializeService_result& operator=(const DiagService_initializeService_result&);
  DiagService_initializeService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_initializeService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_initializeService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_initializeService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_initializeService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_initializeService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_initializeService_presult__isset {
  _DiagService_initializeService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_initializeService_presult__isset;

class DiagService_initializeService_presult {
 public:


  virtual ~DiagService_initializeService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_initializeService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_initializeServiceByProtocol_args__isset {
  _DiagService_initializeServiceByProtocol_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _DiagService_initializeServiceByProtocol_args__isset;

class DiagService_initializeServiceByProtocol_args {
 public:

  DiagService_initializeServiceByProtocol_args(const DiagService_initializeServiceByProtocol_args&);
  DiagService_initializeServiceByProtocol_args& operator=(const DiagService_initializeServiceByProtocol_args&);
  DiagService_initializeServiceByProtocol_args() : protocolHandle(0) {
  }

  virtual ~DiagService_initializeServiceByProtocol_args() noexcept;
  int64_t protocolHandle;

  _DiagService_initializeServiceByProtocol_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const DiagService_initializeServiceByProtocol_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const DiagService_initializeServiceByProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_initializeServiceByProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_initializeServiceByProtocol_pargs {
 public:


  virtual ~DiagService_initializeServiceByProtocol_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_initializeServiceByProtocol_result__isset {
  _DiagService_initializeServiceByProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_initializeServiceByProtocol_result__isset;

class DiagService_initializeServiceByProtocol_result {
 public:

  DiagService_initializeServiceByProtocol_result(const DiagService_initializeServiceByProtocol_result&);
  DiagService_initializeServiceByProtocol_result& operator=(const DiagService_initializeServiceByProtocol_result&);
  DiagService_initializeServiceByProtocol_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_initializeServiceByProtocol_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_initializeServiceByProtocol_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_initializeServiceByProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_initializeServiceByProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_initializeServiceByProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_initializeServiceByProtocol_presult__isset {
  _DiagService_initializeServiceByProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_initializeServiceByProtocol_presult__isset;

class DiagService_initializeServiceByProtocol_presult {
 public:


  virtual ~DiagService_initializeServiceByProtocol_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_initializeServiceByProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_initializeServiceWithOptions_args__isset {
  _DiagService_initializeServiceWithOptions_args__isset() : diagConnectionOptions(false) {}
  bool diagConnectionOptions :1;
} _DiagService_initializeServiceWithOptions_args__isset;

class DiagService_initializeServiceWithOptions_args {
 public:

  DiagService_initializeServiceWithOptions_args(const DiagService_initializeServiceWithOptions_args&);
  DiagService_initializeServiceWithOptions_args& operator=(const DiagService_initializeServiceWithOptions_args&);
  DiagService_initializeServiceWithOptions_args() {
  }

  virtual ~DiagService_initializeServiceWithOptions_args() noexcept;
  DiagConnectionOptions diagConnectionOptions;

  _DiagService_initializeServiceWithOptions_args__isset __isset;

  void __set_diagConnectionOptions(const DiagConnectionOptions& val);

  bool operator == (const DiagService_initializeServiceWithOptions_args & rhs) const
  {
    if (!(diagConnectionOptions == rhs.diagConnectionOptions))
      return false;
    return true;
  }
  bool operator != (const DiagService_initializeServiceWithOptions_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_initializeServiceWithOptions_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_initializeServiceWithOptions_pargs {
 public:


  virtual ~DiagService_initializeServiceWithOptions_pargs() noexcept;
  const DiagConnectionOptions* diagConnectionOptions;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_initializeServiceWithOptions_result__isset {
  _DiagService_initializeServiceWithOptions_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_initializeServiceWithOptions_result__isset;

class DiagService_initializeServiceWithOptions_result {
 public:

  DiagService_initializeServiceWithOptions_result(const DiagService_initializeServiceWithOptions_result&);
  DiagService_initializeServiceWithOptions_result& operator=(const DiagService_initializeServiceWithOptions_result&);
  DiagService_initializeServiceWithOptions_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_initializeServiceWithOptions_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_initializeServiceWithOptions_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_initializeServiceWithOptions_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_initializeServiceWithOptions_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_initializeServiceWithOptions_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_initializeServiceWithOptions_presult__isset {
  _DiagService_initializeServiceWithOptions_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_initializeServiceWithOptions_presult__isset;

class DiagService_initializeServiceWithOptions_presult {
 public:


  virtual ~DiagService_initializeServiceWithOptions_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_initializeServiceWithOptions_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DiagService_destroyService_args {
 public:

  DiagService_destroyService_args(const DiagService_destroyService_args&);
  DiagService_destroyService_args& operator=(const DiagService_destroyService_args&);
  DiagService_destroyService_args() {
  }

  virtual ~DiagService_destroyService_args() noexcept;

  bool operator == (const DiagService_destroyService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiagService_destroyService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_destroyService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_destroyService_pargs {
 public:


  virtual ~DiagService_destroyService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_destroyService_result__isset {
  _DiagService_destroyService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_destroyService_result__isset;

class DiagService_destroyService_result {
 public:

  DiagService_destroyService_result(const DiagService_destroyService_result&);
  DiagService_destroyService_result& operator=(const DiagService_destroyService_result&);
  DiagService_destroyService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_destroyService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_destroyService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_destroyService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_destroyService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_destroyService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_destroyService_presult__isset {
  _DiagService_destroyService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_destroyService_presult__isset;

class DiagService_destroyService_presult {
 public:


  virtual ~DiagService_destroyService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_destroyService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_sendRawRequest_args__isset {
  _DiagService_sendRawRequest_args__isset() : request(false), returnConfig(false), timeout(false) {}
  bool request :1;
  bool returnConfig :1;
  bool timeout :1;
} _DiagService_sendRawRequest_args__isset;

class DiagService_sendRawRequest_args {
 public:

  DiagService_sendRawRequest_args(const DiagService_sendRawRequest_args&);
  DiagService_sendRawRequest_args& operator=(const DiagService_sendRawRequest_args&);
  DiagService_sendRawRequest_args() : request(), timeout(0) {
  }

  virtual ~DiagService_sendRawRequest_args() noexcept;
  std::string request;
   ::Uts::DiagReturns returnConfig;
  int32_t timeout;

  _DiagService_sendRawRequest_args__isset __isset;

  void __set_request(const std::string& val);

  void __set_returnConfig(const  ::Uts::DiagReturns& val);

  void __set_timeout(const int32_t val);

  bool operator == (const DiagService_sendRawRequest_args & rhs) const
  {
    if (!(request == rhs.request))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const DiagService_sendRawRequest_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_sendRawRequest_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_sendRawRequest_pargs {
 public:


  virtual ~DiagService_sendRawRequest_pargs() noexcept;
  const std::string* request;
  const  ::Uts::DiagReturns* returnConfig;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_sendRawRequest_result__isset {
  _DiagService_sendRawRequest_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_sendRawRequest_result__isset;

class DiagService_sendRawRequest_result {
 public:

  DiagService_sendRawRequest_result(const DiagService_sendRawRequest_result&);
  DiagService_sendRawRequest_result& operator=(const DiagService_sendRawRequest_result&);
  DiagService_sendRawRequest_result() {
  }

  virtual ~DiagService_sendRawRequest_result() noexcept;
   ::Uts::DiagPacket success;
   ::Uts::AppException e;

  _DiagService_sendRawRequest_result__isset __isset;

  void __set_success(const  ::Uts::DiagPacket& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_sendRawRequest_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_sendRawRequest_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_sendRawRequest_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_sendRawRequest_presult__isset {
  _DiagService_sendRawRequest_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_sendRawRequest_presult__isset;

class DiagService_sendRawRequest_presult {
 public:


  virtual ~DiagService_sendRawRequest_presult() noexcept;
   ::Uts::DiagPacket* success;
   ::Uts::AppException e;

  _DiagService_sendRawRequest_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_sendRawRequestAsync_args__isset {
  _DiagService_sendRawRequestAsync_args__isset() : request(false) {}
  bool request :1;
} _DiagService_sendRawRequestAsync_args__isset;

class DiagService_sendRawRequestAsync_args {
 public:

  DiagService_sendRawRequestAsync_args(const DiagService_sendRawRequestAsync_args&);
  DiagService_sendRawRequestAsync_args& operator=(const DiagService_sendRawRequestAsync_args&);
  DiagService_sendRawRequestAsync_args() : request() {
  }

  virtual ~DiagService_sendRawRequestAsync_args() noexcept;
  std::string request;

  _DiagService_sendRawRequestAsync_args__isset __isset;

  void __set_request(const std::string& val);

  bool operator == (const DiagService_sendRawRequestAsync_args & rhs) const
  {
    if (!(request == rhs.request))
      return false;
    return true;
  }
  bool operator != (const DiagService_sendRawRequestAsync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_sendRawRequestAsync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_sendRawRequestAsync_pargs {
 public:


  virtual ~DiagService_sendRawRequestAsync_pargs() noexcept;
  const std::string* request;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_sendRawRequestAsync_result__isset {
  _DiagService_sendRawRequestAsync_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_sendRawRequestAsync_result__isset;

class DiagService_sendRawRequestAsync_result {
 public:

  DiagService_sendRawRequestAsync_result(const DiagService_sendRawRequestAsync_result&);
  DiagService_sendRawRequestAsync_result& operator=(const DiagService_sendRawRequestAsync_result&);
  DiagService_sendRawRequestAsync_result() : success(0) {
  }

  virtual ~DiagService_sendRawRequestAsync_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DiagService_sendRawRequestAsync_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_sendRawRequestAsync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_sendRawRequestAsync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_sendRawRequestAsync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_sendRawRequestAsync_presult__isset {
  _DiagService_sendRawRequestAsync_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_sendRawRequestAsync_presult__isset;

class DiagService_sendRawRequestAsync_presult {
 public:


  virtual ~DiagService_sendRawRequestAsync_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DiagService_sendRawRequestAsync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_sendRequest_args__isset {
  _DiagService_sendRequest_args__isset() : requestType(false), requestIdOrName(false), fieldList(false), returnConfig(false), timeout(false) {}
  bool requestType :1;
  bool requestIdOrName :1;
  bool fieldList :1;
  bool returnConfig :1;
  bool timeout :1;
} _DiagService_sendRequest_args__isset;

class DiagService_sendRequest_args {
 public:

  DiagService_sendRequest_args(const DiagService_sendRequest_args&);
  DiagService_sendRequest_args& operator=(const DiagService_sendRequest_args&);
  DiagService_sendRequest_args() : requestType(( ::Uts::DiagPacketType::type)0), requestIdOrName(), fieldList(), timeout(0) {
  }

  virtual ~DiagService_sendRequest_args() noexcept;
   ::Uts::DiagPacketType::type requestType;
  std::string requestIdOrName;
  std::string fieldList;
   ::Uts::DiagReturns returnConfig;
  int32_t timeout;

  _DiagService_sendRequest_args__isset __isset;

  void __set_requestType(const  ::Uts::DiagPacketType::type val);

  void __set_requestIdOrName(const std::string& val);

  void __set_fieldList(const std::string& val);

  void __set_returnConfig(const  ::Uts::DiagReturns& val);

  void __set_timeout(const int32_t val);

  bool operator == (const DiagService_sendRequest_args & rhs) const
  {
    if (!(requestType == rhs.requestType))
      return false;
    if (!(requestIdOrName == rhs.requestIdOrName))
      return false;
    if (!(fieldList == rhs.fieldList))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const DiagService_sendRequest_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_sendRequest_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_sendRequest_pargs {
 public:


  virtual ~DiagService_sendRequest_pargs() noexcept;
  const  ::Uts::DiagPacketType::type* requestType;
  const std::string* requestIdOrName;
  const std::string* fieldList;
  const  ::Uts::DiagReturns* returnConfig;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_sendRequest_result__isset {
  _DiagService_sendRequest_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_sendRequest_result__isset;

class DiagService_sendRequest_result {
 public:

  DiagService_sendRequest_result(const DiagService_sendRequest_result&);
  DiagService_sendRequest_result& operator=(const DiagService_sendRequest_result&);
  DiagService_sendRequest_result() {
  }

  virtual ~DiagService_sendRequest_result() noexcept;
   ::Uts::DiagPacket success;
   ::Uts::AppException e;

  _DiagService_sendRequest_result__isset __isset;

  void __set_success(const  ::Uts::DiagPacket& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_sendRequest_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_sendRequest_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_sendRequest_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_sendRequest_presult__isset {
  _DiagService_sendRequest_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_sendRequest_presult__isset;

class DiagService_sendRequest_presult {
 public:


  virtual ~DiagService_sendRequest_presult() noexcept;
   ::Uts::DiagPacket* success;
   ::Uts::AppException e;

  _DiagService_sendRequest_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_sendRequestAsync_args__isset {
  _DiagService_sendRequestAsync_args__isset() : requestType(false), requestIdOrName(false), fieldList(false) {}
  bool requestType :1;
  bool requestIdOrName :1;
  bool fieldList :1;
} _DiagService_sendRequestAsync_args__isset;

class DiagService_sendRequestAsync_args {
 public:

  DiagService_sendRequestAsync_args(const DiagService_sendRequestAsync_args&);
  DiagService_sendRequestAsync_args& operator=(const DiagService_sendRequestAsync_args&);
  DiagService_sendRequestAsync_args() : requestType(( ::Uts::DiagPacketType::type)0), requestIdOrName(), fieldList() {
  }

  virtual ~DiagService_sendRequestAsync_args() noexcept;
   ::Uts::DiagPacketType::type requestType;
  std::string requestIdOrName;
  std::string fieldList;

  _DiagService_sendRequestAsync_args__isset __isset;

  void __set_requestType(const  ::Uts::DiagPacketType::type val);

  void __set_requestIdOrName(const std::string& val);

  void __set_fieldList(const std::string& val);

  bool operator == (const DiagService_sendRequestAsync_args & rhs) const
  {
    if (!(requestType == rhs.requestType))
      return false;
    if (!(requestIdOrName == rhs.requestIdOrName))
      return false;
    if (!(fieldList == rhs.fieldList))
      return false;
    return true;
  }
  bool operator != (const DiagService_sendRequestAsync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_sendRequestAsync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_sendRequestAsync_pargs {
 public:


  virtual ~DiagService_sendRequestAsync_pargs() noexcept;
  const  ::Uts::DiagPacketType::type* requestType;
  const std::string* requestIdOrName;
  const std::string* fieldList;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_sendRequestAsync_result__isset {
  _DiagService_sendRequestAsync_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_sendRequestAsync_result__isset;

class DiagService_sendRequestAsync_result {
 public:

  DiagService_sendRequestAsync_result(const DiagService_sendRequestAsync_result&);
  DiagService_sendRequestAsync_result& operator=(const DiagService_sendRequestAsync_result&);
  DiagService_sendRequestAsync_result() : success(0) {
  }

  virtual ~DiagService_sendRequestAsync_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _DiagService_sendRequestAsync_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_sendRequestAsync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_sendRequestAsync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_sendRequestAsync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_sendRequestAsync_presult__isset {
  _DiagService_sendRequestAsync_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_sendRequestAsync_presult__isset;

class DiagService_sendRequestAsync_presult {
 public:


  virtual ~DiagService_sendRequestAsync_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _DiagService_sendRequestAsync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_getResponseAsync_args__isset {
  _DiagService_getResponseAsync_args__isset() : transactionId(false), returnConfig(false), timeout(false) {}
  bool transactionId :1;
  bool returnConfig :1;
  bool timeout :1;
} _DiagService_getResponseAsync_args__isset;

class DiagService_getResponseAsync_args {
 public:

  DiagService_getResponseAsync_args(const DiagService_getResponseAsync_args&);
  DiagService_getResponseAsync_args& operator=(const DiagService_getResponseAsync_args&);
  DiagService_getResponseAsync_args() : transactionId(0), timeout(0) {
  }

  virtual ~DiagService_getResponseAsync_args() noexcept;
  int64_t transactionId;
   ::Uts::DiagReturns returnConfig;
  int32_t timeout;

  _DiagService_getResponseAsync_args__isset __isset;

  void __set_transactionId(const int64_t val);

  void __set_returnConfig(const  ::Uts::DiagReturns& val);

  void __set_timeout(const int32_t val);

  bool operator == (const DiagService_getResponseAsync_args & rhs) const
  {
    if (!(transactionId == rhs.transactionId))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const DiagService_getResponseAsync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getResponseAsync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_getResponseAsync_pargs {
 public:


  virtual ~DiagService_getResponseAsync_pargs() noexcept;
  const int64_t* transactionId;
  const  ::Uts::DiagReturns* returnConfig;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getResponseAsync_result__isset {
  _DiagService_getResponseAsync_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getResponseAsync_result__isset;

class DiagService_getResponseAsync_result {
 public:

  DiagService_getResponseAsync_result(const DiagService_getResponseAsync_result&);
  DiagService_getResponseAsync_result& operator=(const DiagService_getResponseAsync_result&);
  DiagService_getResponseAsync_result() {
  }

  virtual ~DiagService_getResponseAsync_result() noexcept;
   ::Uts::DiagPacket success;
   ::Uts::AppException e;

  _DiagService_getResponseAsync_result__isset __isset;

  void __set_success(const  ::Uts::DiagPacket& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_getResponseAsync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_getResponseAsync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getResponseAsync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getResponseAsync_presult__isset {
  _DiagService_getResponseAsync_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getResponseAsync_presult__isset;

class DiagService_getResponseAsync_presult {
 public:


  virtual ~DiagService_getResponseAsync_presult() noexcept;
   ::Uts::DiagPacket* success;
   ::Uts::AppException e;

  _DiagService_getResponseAsync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_getAllResponsesAsync_args__isset {
  _DiagService_getAllResponsesAsync_args__isset() : transactionId(false), returnConfig(false), timeout(false) {}
  bool transactionId :1;
  bool returnConfig :1;
  bool timeout :1;
} _DiagService_getAllResponsesAsync_args__isset;

class DiagService_getAllResponsesAsync_args {
 public:

  DiagService_getAllResponsesAsync_args(const DiagService_getAllResponsesAsync_args&);
  DiagService_getAllResponsesAsync_args& operator=(const DiagService_getAllResponsesAsync_args&);
  DiagService_getAllResponsesAsync_args() : transactionId(0), timeout(0) {
  }

  virtual ~DiagService_getAllResponsesAsync_args() noexcept;
  int64_t transactionId;
   ::Uts::DiagReturns returnConfig;
  int32_t timeout;

  _DiagService_getAllResponsesAsync_args__isset __isset;

  void __set_transactionId(const int64_t val);

  void __set_returnConfig(const  ::Uts::DiagReturns& val);

  void __set_timeout(const int32_t val);

  bool operator == (const DiagService_getAllResponsesAsync_args & rhs) const
  {
    if (!(transactionId == rhs.transactionId))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const DiagService_getAllResponsesAsync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getAllResponsesAsync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_getAllResponsesAsync_pargs {
 public:


  virtual ~DiagService_getAllResponsesAsync_pargs() noexcept;
  const int64_t* transactionId;
  const  ::Uts::DiagReturns* returnConfig;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getAllResponsesAsync_result__isset {
  _DiagService_getAllResponsesAsync_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getAllResponsesAsync_result__isset;

class DiagService_getAllResponsesAsync_result {
 public:

  DiagService_getAllResponsesAsync_result(const DiagService_getAllResponsesAsync_result&);
  DiagService_getAllResponsesAsync_result& operator=(const DiagService_getAllResponsesAsync_result&);
  DiagService_getAllResponsesAsync_result() {
  }

  virtual ~DiagService_getAllResponsesAsync_result() noexcept;
  std::vector< ::Uts::DiagPacket>  success;
   ::Uts::AppException e;

  _DiagService_getAllResponsesAsync_result__isset __isset;

  void __set_success(const std::vector< ::Uts::DiagPacket> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_getAllResponsesAsync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_getAllResponsesAsync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getAllResponsesAsync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getAllResponsesAsync_presult__isset {
  _DiagService_getAllResponsesAsync_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getAllResponsesAsync_presult__isset;

class DiagService_getAllResponsesAsync_presult {
 public:


  virtual ~DiagService_getAllResponsesAsync_presult() noexcept;
  std::vector< ::Uts::DiagPacket> * success;
   ::Uts::AppException e;

  _DiagService_getAllResponsesAsync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_createDataQueue_args__isset {
  _DiagService_createDataQueue_args__isset() : queueName(false), filter(false), returnConfig(false) {}
  bool queueName :1;
  bool filter :1;
  bool returnConfig :1;
} _DiagService_createDataQueue_args__isset;

class DiagService_createDataQueue_args {
 public:

  DiagService_createDataQueue_args(const DiagService_createDataQueue_args&);
  DiagService_createDataQueue_args& operator=(const DiagService_createDataQueue_args&);
  DiagService_createDataQueue_args() : queueName() {
  }

  virtual ~DiagService_createDataQueue_args() noexcept;
  std::string queueName;
   ::Uts::DiagPacketFilter filter;
   ::Uts::DiagReturnConfig returnConfig;

  _DiagService_createDataQueue_args__isset __isset;

  void __set_queueName(const std::string& val);

  void __set_filter(const  ::Uts::DiagPacketFilter& val);

  void __set_returnConfig(const  ::Uts::DiagReturnConfig& val);

  bool operator == (const DiagService_createDataQueue_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    if (!(filter == rhs.filter))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const DiagService_createDataQueue_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_createDataQueue_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_createDataQueue_pargs {
 public:


  virtual ~DiagService_createDataQueue_pargs() noexcept;
  const std::string* queueName;
  const  ::Uts::DiagPacketFilter* filter;
  const  ::Uts::DiagReturnConfig* returnConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_createDataQueue_result__isset {
  _DiagService_createDataQueue_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_createDataQueue_result__isset;

class DiagService_createDataQueue_result {
 public:

  DiagService_createDataQueue_result(const DiagService_createDataQueue_result&);
  DiagService_createDataQueue_result& operator=(const DiagService_createDataQueue_result&);
  DiagService_createDataQueue_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_createDataQueue_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_createDataQueue_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_createDataQueue_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_createDataQueue_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_createDataQueue_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_createDataQueue_presult__isset {
  _DiagService_createDataQueue_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_createDataQueue_presult__isset;

class DiagService_createDataQueue_presult {
 public:


  virtual ~DiagService_createDataQueue_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_createDataQueue_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_createDataQueueWithAnnotations_args__isset {
  _DiagService_createDataQueueWithAnnotations_args__isset() : queueName(false), filter(false), annotationsFilter(false), returnConfig(false) {}
  bool queueName :1;
  bool filter :1;
  bool annotationsFilter :1;
  bool returnConfig :1;
} _DiagService_createDataQueueWithAnnotations_args__isset;

class DiagService_createDataQueueWithAnnotations_args {
 public:

  DiagService_createDataQueueWithAnnotations_args(const DiagService_createDataQueueWithAnnotations_args&);
  DiagService_createDataQueueWithAnnotations_args& operator=(const DiagService_createDataQueueWithAnnotations_args&);
  DiagService_createDataQueueWithAnnotations_args() : queueName() {
  }

  virtual ~DiagService_createDataQueueWithAnnotations_args() noexcept;
  std::string queueName;
   ::Uts::DiagPacketFilter filter;
   ::Uts::AnnotationPacketFilter annotationsFilter;
   ::Uts::DiagReturnConfig returnConfig;

  _DiagService_createDataQueueWithAnnotations_args__isset __isset;

  void __set_queueName(const std::string& val);

  void __set_filter(const  ::Uts::DiagPacketFilter& val);

  void __set_annotationsFilter(const  ::Uts::AnnotationPacketFilter& val);

  void __set_returnConfig(const  ::Uts::DiagReturnConfig& val);

  bool operator == (const DiagService_createDataQueueWithAnnotations_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    if (!(filter == rhs.filter))
      return false;
    if (!(annotationsFilter == rhs.annotationsFilter))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const DiagService_createDataQueueWithAnnotations_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_createDataQueueWithAnnotations_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_createDataQueueWithAnnotations_pargs {
 public:


  virtual ~DiagService_createDataQueueWithAnnotations_pargs() noexcept;
  const std::string* queueName;
  const  ::Uts::DiagPacketFilter* filter;
  const  ::Uts::AnnotationPacketFilter* annotationsFilter;
  const  ::Uts::DiagReturnConfig* returnConfig;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_createDataQueueWithAnnotations_result__isset {
  _DiagService_createDataQueueWithAnnotations_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_createDataQueueWithAnnotations_result__isset;

class DiagService_createDataQueueWithAnnotations_result {
 public:

  DiagService_createDataQueueWithAnnotations_result(const DiagService_createDataQueueWithAnnotations_result&);
  DiagService_createDataQueueWithAnnotations_result& operator=(const DiagService_createDataQueueWithAnnotations_result&);
  DiagService_createDataQueueWithAnnotations_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_createDataQueueWithAnnotations_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_createDataQueueWithAnnotations_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_createDataQueueWithAnnotations_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_createDataQueueWithAnnotations_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_createDataQueueWithAnnotations_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_createDataQueueWithAnnotations_presult__isset {
  _DiagService_createDataQueueWithAnnotations_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_createDataQueueWithAnnotations_presult__isset;

class DiagService_createDataQueueWithAnnotations_presult {
 public:


  virtual ~DiagService_createDataQueueWithAnnotations_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_createDataQueueWithAnnotations_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_removeDataQueue_args__isset {
  _DiagService_removeDataQueue_args__isset() : queueName(false) {}
  bool queueName :1;
} _DiagService_removeDataQueue_args__isset;

class DiagService_removeDataQueue_args {
 public:

  DiagService_removeDataQueue_args(const DiagService_removeDataQueue_args&);
  DiagService_removeDataQueue_args& operator=(const DiagService_removeDataQueue_args&);
  DiagService_removeDataQueue_args() : queueName() {
  }

  virtual ~DiagService_removeDataQueue_args() noexcept;
  std::string queueName;

  _DiagService_removeDataQueue_args__isset __isset;

  void __set_queueName(const std::string& val);

  bool operator == (const DiagService_removeDataQueue_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    return true;
  }
  bool operator != (const DiagService_removeDataQueue_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_removeDataQueue_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_removeDataQueue_pargs {
 public:


  virtual ~DiagService_removeDataQueue_pargs() noexcept;
  const std::string* queueName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_removeDataQueue_result__isset {
  _DiagService_removeDataQueue_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_removeDataQueue_result__isset;

class DiagService_removeDataQueue_result {
 public:

  DiagService_removeDataQueue_result(const DiagService_removeDataQueue_result&);
  DiagService_removeDataQueue_result& operator=(const DiagService_removeDataQueue_result&);
  DiagService_removeDataQueue_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_removeDataQueue_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_removeDataQueue_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_removeDataQueue_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_removeDataQueue_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_removeDataQueue_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_removeDataQueue_presult__isset {
  _DiagService_removeDataQueue_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_removeDataQueue_presult__isset;

class DiagService_removeDataQueue_presult {
 public:


  virtual ~DiagService_removeDataQueue_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_removeDataQueue_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_clearDataQueue_args__isset {
  _DiagService_clearDataQueue_args__isset() : queueName(false) {}
  bool queueName :1;
} _DiagService_clearDataQueue_args__isset;

class DiagService_clearDataQueue_args {
 public:

  DiagService_clearDataQueue_args(const DiagService_clearDataQueue_args&);
  DiagService_clearDataQueue_args& operator=(const DiagService_clearDataQueue_args&);
  DiagService_clearDataQueue_args() : queueName() {
  }

  virtual ~DiagService_clearDataQueue_args() noexcept;
  std::string queueName;

  _DiagService_clearDataQueue_args__isset __isset;

  void __set_queueName(const std::string& val);

  bool operator == (const DiagService_clearDataQueue_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    return true;
  }
  bool operator != (const DiagService_clearDataQueue_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_clearDataQueue_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_clearDataQueue_pargs {
 public:


  virtual ~DiagService_clearDataQueue_pargs() noexcept;
  const std::string* queueName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_clearDataQueue_result__isset {
  _DiagService_clearDataQueue_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_clearDataQueue_result__isset;

class DiagService_clearDataQueue_result {
 public:

  DiagService_clearDataQueue_result(const DiagService_clearDataQueue_result&);
  DiagService_clearDataQueue_result& operator=(const DiagService_clearDataQueue_result&);
  DiagService_clearDataQueue_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_clearDataQueue_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_clearDataQueue_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_clearDataQueue_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_clearDataQueue_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_clearDataQueue_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_clearDataQueue_presult__isset {
  _DiagService_clearDataQueue_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_clearDataQueue_presult__isset;

class DiagService_clearDataQueue_presult {
 public:


  virtual ~DiagService_clearDataQueue_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_clearDataQueue_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_getDataQueueItems_args__isset {
  _DiagService_getDataQueueItems_args__isset() : queueName(false), count(false), timeout(false) {}
  bool queueName :1;
  bool count :1;
  bool timeout :1;
} _DiagService_getDataQueueItems_args__isset;

class DiagService_getDataQueueItems_args {
 public:

  DiagService_getDataQueueItems_args(const DiagService_getDataQueueItems_args&);
  DiagService_getDataQueueItems_args& operator=(const DiagService_getDataQueueItems_args&);
  DiagService_getDataQueueItems_args() : queueName(), count(0), timeout(0) {
  }

  virtual ~DiagService_getDataQueueItems_args() noexcept;
  std::string queueName;
  int32_t count;
  int32_t timeout;

  _DiagService_getDataQueueItems_args__isset __isset;

  void __set_queueName(const std::string& val);

  void __set_count(const int32_t val);

  void __set_timeout(const int32_t val);

  bool operator == (const DiagService_getDataQueueItems_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    if (!(count == rhs.count))
      return false;
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const DiagService_getDataQueueItems_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getDataQueueItems_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_getDataQueueItems_pargs {
 public:


  virtual ~DiagService_getDataQueueItems_pargs() noexcept;
  const std::string* queueName;
  const int32_t* count;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getDataQueueItems_result__isset {
  _DiagService_getDataQueueItems_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getDataQueueItems_result__isset;

class DiagService_getDataQueueItems_result {
 public:

  DiagService_getDataQueueItems_result(const DiagService_getDataQueueItems_result&);
  DiagService_getDataQueueItems_result& operator=(const DiagService_getDataQueueItems_result&);
  DiagService_getDataQueueItems_result() {
  }

  virtual ~DiagService_getDataQueueItems_result() noexcept;
  std::vector< ::Uts::DiagPacket>  success;
   ::Uts::AppException e;

  _DiagService_getDataQueueItems_result__isset __isset;

  void __set_success(const std::vector< ::Uts::DiagPacket> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_getDataQueueItems_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_getDataQueueItems_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getDataQueueItems_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getDataQueueItems_presult__isset {
  _DiagService_getDataQueueItems_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getDataQueueItems_presult__isset;

class DiagService_getDataQueueItems_presult {
 public:


  virtual ~DiagService_getDataQueueItems_presult() noexcept;
  std::vector< ::Uts::DiagPacket> * success;
   ::Uts::AppException e;

  _DiagService_getDataQueueItems_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_getDataQueueItemsWithAnnotations_args__isset {
  _DiagService_getDataQueueItemsWithAnnotations_args__isset() : queueName(false), count(false), timeout(false) {}
  bool queueName :1;
  bool count :1;
  bool timeout :1;
} _DiagService_getDataQueueItemsWithAnnotations_args__isset;

class DiagService_getDataQueueItemsWithAnnotations_args {
 public:

  DiagService_getDataQueueItemsWithAnnotations_args(const DiagService_getDataQueueItemsWithAnnotations_args&);
  DiagService_getDataQueueItemsWithAnnotations_args& operator=(const DiagService_getDataQueueItemsWithAnnotations_args&);
  DiagService_getDataQueueItemsWithAnnotations_args() : queueName(), count(0), timeout(0) {
  }

  virtual ~DiagService_getDataQueueItemsWithAnnotations_args() noexcept;
  std::string queueName;
  int32_t count;
  int32_t timeout;

  _DiagService_getDataQueueItemsWithAnnotations_args__isset __isset;

  void __set_queueName(const std::string& val);

  void __set_count(const int32_t val);

  void __set_timeout(const int32_t val);

  bool operator == (const DiagService_getDataQueueItemsWithAnnotations_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    if (!(count == rhs.count))
      return false;
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const DiagService_getDataQueueItemsWithAnnotations_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getDataQueueItemsWithAnnotations_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_getDataQueueItemsWithAnnotations_pargs {
 public:


  virtual ~DiagService_getDataQueueItemsWithAnnotations_pargs() noexcept;
  const std::string* queueName;
  const int32_t* count;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getDataQueueItemsWithAnnotations_result__isset {
  _DiagService_getDataQueueItemsWithAnnotations_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getDataQueueItemsWithAnnotations_result__isset;

class DiagService_getDataQueueItemsWithAnnotations_result {
 public:

  DiagService_getDataQueueItemsWithAnnotations_result(const DiagService_getDataQueueItemsWithAnnotations_result&);
  DiagService_getDataQueueItemsWithAnnotations_result& operator=(const DiagService_getDataQueueItemsWithAnnotations_result&);
  DiagService_getDataQueueItemsWithAnnotations_result() {
  }

  virtual ~DiagService_getDataQueueItemsWithAnnotations_result() noexcept;
  std::vector<DataQueuePacket>  success;
   ::Uts::AppException e;

  _DiagService_getDataQueueItemsWithAnnotations_result__isset __isset;

  void __set_success(const std::vector<DataQueuePacket> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_getDataQueueItemsWithAnnotations_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_getDataQueueItemsWithAnnotations_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getDataQueueItemsWithAnnotations_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getDataQueueItemsWithAnnotations_presult__isset {
  _DiagService_getDataQueueItemsWithAnnotations_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getDataQueueItemsWithAnnotations_presult__isset;

class DiagService_getDataQueueItemsWithAnnotations_presult {
 public:


  virtual ~DiagService_getDataQueueItemsWithAnnotations_presult() noexcept;
  std::vector<DataQueuePacket> * success;
   ::Uts::AppException e;

  _DiagService_getDataQueueItemsWithAnnotations_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_addDataQueueFilter_args__isset {
  _DiagService_addDataQueueFilter_args__isset() : queueName(false), filter(false) {}
  bool queueName :1;
  bool filter :1;
} _DiagService_addDataQueueFilter_args__isset;

class DiagService_addDataQueueFilter_args {
 public:

  DiagService_addDataQueueFilter_args(const DiagService_addDataQueueFilter_args&);
  DiagService_addDataQueueFilter_args& operator=(const DiagService_addDataQueueFilter_args&);
  DiagService_addDataQueueFilter_args() : queueName() {
  }

  virtual ~DiagService_addDataQueueFilter_args() noexcept;
  std::string queueName;
   ::Uts::DiagPacketFilter filter;

  _DiagService_addDataQueueFilter_args__isset __isset;

  void __set_queueName(const std::string& val);

  void __set_filter(const  ::Uts::DiagPacketFilter& val);

  bool operator == (const DiagService_addDataQueueFilter_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    if (!(filter == rhs.filter))
      return false;
    return true;
  }
  bool operator != (const DiagService_addDataQueueFilter_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_addDataQueueFilter_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_addDataQueueFilter_pargs {
 public:


  virtual ~DiagService_addDataQueueFilter_pargs() noexcept;
  const std::string* queueName;
  const  ::Uts::DiagPacketFilter* filter;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_addDataQueueFilter_result__isset {
  _DiagService_addDataQueueFilter_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_addDataQueueFilter_result__isset;

class DiagService_addDataQueueFilter_result {
 public:

  DiagService_addDataQueueFilter_result(const DiagService_addDataQueueFilter_result&);
  DiagService_addDataQueueFilter_result& operator=(const DiagService_addDataQueueFilter_result&);
  DiagService_addDataQueueFilter_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_addDataQueueFilter_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_addDataQueueFilter_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_addDataQueueFilter_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_addDataQueueFilter_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_addDataQueueFilter_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_addDataQueueFilter_presult__isset {
  _DiagService_addDataQueueFilter_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_addDataQueueFilter_presult__isset;

class DiagService_addDataQueueFilter_presult {
 public:


  virtual ~DiagService_addDataQueueFilter_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_addDataQueueFilter_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_removeDataQueueFilter_args__isset {
  _DiagService_removeDataQueueFilter_args__isset() : queueName(false), filter(false) {}
  bool queueName :1;
  bool filter :1;
} _DiagService_removeDataQueueFilter_args__isset;

class DiagService_removeDataQueueFilter_args {
 public:

  DiagService_removeDataQueueFilter_args(const DiagService_removeDataQueueFilter_args&);
  DiagService_removeDataQueueFilter_args& operator=(const DiagService_removeDataQueueFilter_args&);
  DiagService_removeDataQueueFilter_args() : queueName() {
  }

  virtual ~DiagService_removeDataQueueFilter_args() noexcept;
  std::string queueName;
   ::Uts::DiagPacketFilter filter;

  _DiagService_removeDataQueueFilter_args__isset __isset;

  void __set_queueName(const std::string& val);

  void __set_filter(const  ::Uts::DiagPacketFilter& val);

  bool operator == (const DiagService_removeDataQueueFilter_args & rhs) const
  {
    if (!(queueName == rhs.queueName))
      return false;
    if (!(filter == rhs.filter))
      return false;
    return true;
  }
  bool operator != (const DiagService_removeDataQueueFilter_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_removeDataQueueFilter_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_removeDataQueueFilter_pargs {
 public:


  virtual ~DiagService_removeDataQueueFilter_pargs() noexcept;
  const std::string* queueName;
  const  ::Uts::DiagPacketFilter* filter;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_removeDataQueueFilter_result__isset {
  _DiagService_removeDataQueueFilter_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_removeDataQueueFilter_result__isset;

class DiagService_removeDataQueueFilter_result {
 public:

  DiagService_removeDataQueueFilter_result(const DiagService_removeDataQueueFilter_result&);
  DiagService_removeDataQueueFilter_result& operator=(const DiagService_removeDataQueueFilter_result&);
  DiagService_removeDataQueueFilter_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_removeDataQueueFilter_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_removeDataQueueFilter_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_removeDataQueueFilter_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_removeDataQueueFilter_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_removeDataQueueFilter_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_removeDataQueueFilter_presult__isset {
  _DiagService_removeDataQueueFilter_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_removeDataQueueFilter_presult__isset;

class DiagService_removeDataQueueFilter_presult {
 public:


  virtual ~DiagService_removeDataQueueFilter_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_removeDataQueueFilter_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_setLoggingMask_args__isset {
  _DiagService_setLoggingMask_args__isset() : maskFileContent(false), format(false) {}
  bool maskFileContent :1;
  bool format :1;
} _DiagService_setLoggingMask_args__isset;

class DiagService_setLoggingMask_args {
 public:

  DiagService_setLoggingMask_args(const DiagService_setLoggingMask_args&);
  DiagService_setLoggingMask_args& operator=(const DiagService_setLoggingMask_args&);
  DiagService_setLoggingMask_args() : maskFileContent(), format(( ::Uts::LogMaskFormat::type)0) {
  }

  virtual ~DiagService_setLoggingMask_args() noexcept;
  std::string maskFileContent;
   ::Uts::LogMaskFormat::type format;

  _DiagService_setLoggingMask_args__isset __isset;

  void __set_maskFileContent(const std::string& val);

  void __set_format(const  ::Uts::LogMaskFormat::type val);

  bool operator == (const DiagService_setLoggingMask_args & rhs) const
  {
    if (!(maskFileContent == rhs.maskFileContent))
      return false;
    if (!(format == rhs.format))
      return false;
    return true;
  }
  bool operator != (const DiagService_setLoggingMask_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setLoggingMask_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_setLoggingMask_pargs {
 public:


  virtual ~DiagService_setLoggingMask_pargs() noexcept;
  const std::string* maskFileContent;
  const  ::Uts::LogMaskFormat::type* format;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setLoggingMask_result__isset {
  _DiagService_setLoggingMask_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setLoggingMask_result__isset;

class DiagService_setLoggingMask_result {
 public:

  DiagService_setLoggingMask_result(const DiagService_setLoggingMask_result&);
  DiagService_setLoggingMask_result& operator=(const DiagService_setLoggingMask_result&);
  DiagService_setLoggingMask_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_setLoggingMask_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_setLoggingMask_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_setLoggingMask_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_setLoggingMask_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setLoggingMask_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setLoggingMask_presult__isset {
  _DiagService_setLoggingMask_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setLoggingMask_presult__isset;

class DiagService_setLoggingMask_presult {
 public:


  virtual ~DiagService_setLoggingMask_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_setLoggingMask_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class DiagService_getQShrinkState_args {
 public:

  DiagService_getQShrinkState_args(const DiagService_getQShrinkState_args&);
  DiagService_getQShrinkState_args& operator=(const DiagService_getQShrinkState_args&);
  DiagService_getQShrinkState_args() {
  }

  virtual ~DiagService_getQShrinkState_args() noexcept;

  bool operator == (const DiagService_getQShrinkState_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const DiagService_getQShrinkState_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getQShrinkState_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_getQShrinkState_pargs {
 public:


  virtual ~DiagService_getQShrinkState_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getQShrinkState_result__isset {
  _DiagService_getQShrinkState_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getQShrinkState_result__isset;

class DiagService_getQShrinkState_result {
 public:

  DiagService_getQShrinkState_result(const DiagService_getQShrinkState_result&);
  DiagService_getQShrinkState_result& operator=(const DiagService_getQShrinkState_result&);
  DiagService_getQShrinkState_result() : success(( ::Uts::QShrink4DownloadState::type)0) {
  }

  virtual ~DiagService_getQShrinkState_result() noexcept;
   ::Uts::QShrink4DownloadState::type success;
   ::Uts::AppException e;

  _DiagService_getQShrinkState_result__isset __isset;

  void __set_success(const  ::Uts::QShrink4DownloadState::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_getQShrinkState_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_getQShrinkState_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_getQShrinkState_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_getQShrinkState_presult__isset {
  _DiagService_getQShrinkState_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_getQShrinkState_presult__isset;

class DiagService_getQShrinkState_presult {
 public:


  virtual ~DiagService_getQShrinkState_presult() noexcept;
   ::Uts::QShrink4DownloadState::type* success;
   ::Uts::AppException e;

  _DiagService_getQShrinkState_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_loadQShrinkFile_args__isset {
  _DiagService_loadQShrinkFile_args__isset() : pathName(false) {}
  bool pathName :1;
} _DiagService_loadQShrinkFile_args__isset;

class DiagService_loadQShrinkFile_args {
 public:

  DiagService_loadQShrinkFile_args(const DiagService_loadQShrinkFile_args&);
  DiagService_loadQShrinkFile_args& operator=(const DiagService_loadQShrinkFile_args&);
  DiagService_loadQShrinkFile_args() : pathName() {
  }

  virtual ~DiagService_loadQShrinkFile_args() noexcept;
  std::string pathName;

  _DiagService_loadQShrinkFile_args__isset __isset;

  void __set_pathName(const std::string& val);

  bool operator == (const DiagService_loadQShrinkFile_args & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    return true;
  }
  bool operator != (const DiagService_loadQShrinkFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_loadQShrinkFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_loadQShrinkFile_pargs {
 public:


  virtual ~DiagService_loadQShrinkFile_pargs() noexcept;
  const std::string* pathName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_loadQShrinkFile_result__isset {
  _DiagService_loadQShrinkFile_result__isset() : e(false) {}
  bool e :1;
} _DiagService_loadQShrinkFile_result__isset;

class DiagService_loadQShrinkFile_result {
 public:

  DiagService_loadQShrinkFile_result(const DiagService_loadQShrinkFile_result&);
  DiagService_loadQShrinkFile_result& operator=(const DiagService_loadQShrinkFile_result&);
  DiagService_loadQShrinkFile_result() {
  }

  virtual ~DiagService_loadQShrinkFile_result() noexcept;
   ::Uts::AppException e;

  _DiagService_loadQShrinkFile_result__isset __isset;

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_loadQShrinkFile_result & rhs) const
  {
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_loadQShrinkFile_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_loadQShrinkFile_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_loadQShrinkFile_presult__isset {
  _DiagService_loadQShrinkFile_presult__isset() : e(false) {}
  bool e :1;
} _DiagService_loadQShrinkFile_presult__isset;

class DiagService_loadQShrinkFile_presult {
 public:


  virtual ~DiagService_loadQShrinkFile_presult() noexcept;
   ::Uts::AppException e;

  _DiagService_loadQShrinkFile_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_setWcdmaProtocolRevision_args__isset {
  _DiagService_setWcdmaProtocolRevision_args__isset() : revision(false) {}
  bool revision :1;
} _DiagService_setWcdmaProtocolRevision_args__isset;

class DiagService_setWcdmaProtocolRevision_args {
 public:

  DiagService_setWcdmaProtocolRevision_args(const DiagService_setWcdmaProtocolRevision_args&);
  DiagService_setWcdmaProtocolRevision_args& operator=(const DiagService_setWcdmaProtocolRevision_args&);
  DiagService_setWcdmaProtocolRevision_args() : revision(( ::Uts::WcdmaProtocolRevision::type)0) {
  }

  virtual ~DiagService_setWcdmaProtocolRevision_args() noexcept;
   ::Uts::WcdmaProtocolRevision::type revision;

  _DiagService_setWcdmaProtocolRevision_args__isset __isset;

  void __set_revision(const  ::Uts::WcdmaProtocolRevision::type val);

  bool operator == (const DiagService_setWcdmaProtocolRevision_args & rhs) const
  {
    if (!(revision == rhs.revision))
      return false;
    return true;
  }
  bool operator != (const DiagService_setWcdmaProtocolRevision_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setWcdmaProtocolRevision_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_setWcdmaProtocolRevision_pargs {
 public:


  virtual ~DiagService_setWcdmaProtocolRevision_pargs() noexcept;
  const  ::Uts::WcdmaProtocolRevision::type* revision;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setWcdmaProtocolRevision_result__isset {
  _DiagService_setWcdmaProtocolRevision_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setWcdmaProtocolRevision_result__isset;

class DiagService_setWcdmaProtocolRevision_result {
 public:

  DiagService_setWcdmaProtocolRevision_result(const DiagService_setWcdmaProtocolRevision_result&);
  DiagService_setWcdmaProtocolRevision_result& operator=(const DiagService_setWcdmaProtocolRevision_result&);
  DiagService_setWcdmaProtocolRevision_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_setWcdmaProtocolRevision_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_setWcdmaProtocolRevision_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_setWcdmaProtocolRevision_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_setWcdmaProtocolRevision_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setWcdmaProtocolRevision_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setWcdmaProtocolRevision_presult__isset {
  _DiagService_setWcdmaProtocolRevision_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setWcdmaProtocolRevision_presult__isset;

class DiagService_setWcdmaProtocolRevision_presult {
 public:


  virtual ~DiagService_setWcdmaProtocolRevision_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_setWcdmaProtocolRevision_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_setCdmaProtocolRevision_args__isset {
  _DiagService_setCdmaProtocolRevision_args__isset() : revision(false) {}
  bool revision :1;
} _DiagService_setCdmaProtocolRevision_args__isset;

class DiagService_setCdmaProtocolRevision_args {
 public:

  DiagService_setCdmaProtocolRevision_args(const DiagService_setCdmaProtocolRevision_args&);
  DiagService_setCdmaProtocolRevision_args& operator=(const DiagService_setCdmaProtocolRevision_args&);
  DiagService_setCdmaProtocolRevision_args() : revision(( ::Uts::CdmaProtocolRevision::type)0) {
  }

  virtual ~DiagService_setCdmaProtocolRevision_args() noexcept;
   ::Uts::CdmaProtocolRevision::type revision;

  _DiagService_setCdmaProtocolRevision_args__isset __isset;

  void __set_revision(const  ::Uts::CdmaProtocolRevision::type val);

  bool operator == (const DiagService_setCdmaProtocolRevision_args & rhs) const
  {
    if (!(revision == rhs.revision))
      return false;
    return true;
  }
  bool operator != (const DiagService_setCdmaProtocolRevision_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setCdmaProtocolRevision_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_setCdmaProtocolRevision_pargs {
 public:


  virtual ~DiagService_setCdmaProtocolRevision_pargs() noexcept;
  const  ::Uts::CdmaProtocolRevision::type* revision;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setCdmaProtocolRevision_result__isset {
  _DiagService_setCdmaProtocolRevision_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setCdmaProtocolRevision_result__isset;

class DiagService_setCdmaProtocolRevision_result {
 public:

  DiagService_setCdmaProtocolRevision_result(const DiagService_setCdmaProtocolRevision_result&);
  DiagService_setCdmaProtocolRevision_result& operator=(const DiagService_setCdmaProtocolRevision_result&);
  DiagService_setCdmaProtocolRevision_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_setCdmaProtocolRevision_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_setCdmaProtocolRevision_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_setCdmaProtocolRevision_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_setCdmaProtocolRevision_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setCdmaProtocolRevision_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setCdmaProtocolRevision_presult__isset {
  _DiagService_setCdmaProtocolRevision_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setCdmaProtocolRevision_presult__isset;

class DiagService_setCdmaProtocolRevision_presult {
 public:


  virtual ~DiagService_setCdmaProtocolRevision_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_setCdmaProtocolRevision_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_setPilotInc_args__isset {
  _DiagService_setPilotInc_args__isset() : pilotInc(false) {}
  bool pilotInc :1;
} _DiagService_setPilotInc_args__isset;

class DiagService_setPilotInc_args {
 public:

  DiagService_setPilotInc_args(const DiagService_setPilotInc_args&);
  DiagService_setPilotInc_args& operator=(const DiagService_setPilotInc_args&);
  DiagService_setPilotInc_args() : pilotInc(0) {
  }

  virtual ~DiagService_setPilotInc_args() noexcept;
  int16_t pilotInc;

  _DiagService_setPilotInc_args__isset __isset;

  void __set_pilotInc(const int16_t val);

  bool operator == (const DiagService_setPilotInc_args & rhs) const
  {
    if (!(pilotInc == rhs.pilotInc))
      return false;
    return true;
  }
  bool operator != (const DiagService_setPilotInc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setPilotInc_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_setPilotInc_pargs {
 public:


  virtual ~DiagService_setPilotInc_pargs() noexcept;
  const int16_t* pilotInc;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setPilotInc_result__isset {
  _DiagService_setPilotInc_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setPilotInc_result__isset;

class DiagService_setPilotInc_result {
 public:

  DiagService_setPilotInc_result(const DiagService_setPilotInc_result&);
  DiagService_setPilotInc_result& operator=(const DiagService_setPilotInc_result&);
  DiagService_setPilotInc_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_setPilotInc_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_setPilotInc_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_setPilotInc_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_setPilotInc_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setPilotInc_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setPilotInc_presult__isset {
  _DiagService_setPilotInc_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setPilotInc_presult__isset;

class DiagService_setPilotInc_presult {
 public:


  virtual ~DiagService_setPilotInc_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_setPilotInc_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_setLoggingMaskFromFilter_args__isset {
  _DiagService_setLoggingMaskFromFilter_args__isset() : filter(false) {}
  bool filter :1;
} _DiagService_setLoggingMaskFromFilter_args__isset;

class DiagService_setLoggingMaskFromFilter_args {
 public:

  DiagService_setLoggingMaskFromFilter_args(const DiagService_setLoggingMaskFromFilter_args&);
  DiagService_setLoggingMaskFromFilter_args& operator=(const DiagService_setLoggingMaskFromFilter_args&);
  DiagService_setLoggingMaskFromFilter_args() {
  }

  virtual ~DiagService_setLoggingMaskFromFilter_args() noexcept;
   ::Uts::DiagPacketFilter filter;

  _DiagService_setLoggingMaskFromFilter_args__isset __isset;

  void __set_filter(const  ::Uts::DiagPacketFilter& val);

  bool operator == (const DiagService_setLoggingMaskFromFilter_args & rhs) const
  {
    if (!(filter == rhs.filter))
      return false;
    return true;
  }
  bool operator != (const DiagService_setLoggingMaskFromFilter_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setLoggingMaskFromFilter_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_setLoggingMaskFromFilter_pargs {
 public:


  virtual ~DiagService_setLoggingMaskFromFilter_pargs() noexcept;
  const  ::Uts::DiagPacketFilter* filter;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setLoggingMaskFromFilter_result__isset {
  _DiagService_setLoggingMaskFromFilter_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setLoggingMaskFromFilter_result__isset;

class DiagService_setLoggingMaskFromFilter_result {
 public:

  DiagService_setLoggingMaskFromFilter_result(const DiagService_setLoggingMaskFromFilter_result&);
  DiagService_setLoggingMaskFromFilter_result& operator=(const DiagService_setLoggingMaskFromFilter_result&);
  DiagService_setLoggingMaskFromFilter_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~DiagService_setLoggingMaskFromFilter_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _DiagService_setLoggingMaskFromFilter_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_setLoggingMaskFromFilter_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_setLoggingMaskFromFilter_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setLoggingMaskFromFilter_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setLoggingMaskFromFilter_presult__isset {
  _DiagService_setLoggingMaskFromFilter_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setLoggingMaskFromFilter_presult__isset;

class DiagService_setLoggingMaskFromFilter_presult {
 public:


  virtual ~DiagService_setLoggingMaskFromFilter_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _DiagService_setLoggingMaskFromFilter_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_resetHealthReportCounters_args__isset {
  _DiagService_resetHealthReportCounters_args__isset() : subsystem(false) {}
  bool subsystem :1;
} _DiagService_resetHealthReportCounters_args__isset;

class DiagService_resetHealthReportCounters_args {
 public:

  DiagService_resetHealthReportCounters_args(const DiagService_resetHealthReportCounters_args&);
  DiagService_resetHealthReportCounters_args& operator=(const DiagService_resetHealthReportCounters_args&);
  DiagService_resetHealthReportCounters_args() : subsystem((Subsystem::type)0) {
  }

  virtual ~DiagService_resetHealthReportCounters_args() noexcept;
  Subsystem::type subsystem;

  _DiagService_resetHealthReportCounters_args__isset __isset;

  void __set_subsystem(const Subsystem::type val);

  bool operator == (const DiagService_resetHealthReportCounters_args & rhs) const
  {
    if (!(subsystem == rhs.subsystem))
      return false;
    return true;
  }
  bool operator != (const DiagService_resetHealthReportCounters_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_resetHealthReportCounters_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_resetHealthReportCounters_pargs {
 public:


  virtual ~DiagService_resetHealthReportCounters_pargs() noexcept;
  const Subsystem::type* subsystem;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_resetHealthReportCounters_result__isset {
  _DiagService_resetHealthReportCounters_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_resetHealthReportCounters_result__isset;

class DiagService_resetHealthReportCounters_result {
 public:

  DiagService_resetHealthReportCounters_result(const DiagService_resetHealthReportCounters_result&);
  DiagService_resetHealthReportCounters_result& operator=(const DiagService_resetHealthReportCounters_result&);
  DiagService_resetHealthReportCounters_result() : success((HealthReportConfigureStatus::type)0) {
  }

  virtual ~DiagService_resetHealthReportCounters_result() noexcept;
  HealthReportConfigureStatus::type success;
   ::Uts::AppException e;

  _DiagService_resetHealthReportCounters_result__isset __isset;

  void __set_success(const HealthReportConfigureStatus::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_resetHealthReportCounters_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_resetHealthReportCounters_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_resetHealthReportCounters_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_resetHealthReportCounters_presult__isset {
  _DiagService_resetHealthReportCounters_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_resetHealthReportCounters_presult__isset;

class DiagService_resetHealthReportCounters_presult {
 public:


  virtual ~DiagService_resetHealthReportCounters_presult() noexcept;
  HealthReportConfigureStatus::type* success;
   ::Uts::AppException e;

  _DiagService_resetHealthReportCounters_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _DiagService_setHealthReportTimer_args__isset {
  _DiagService_setHealthReportTimer_args__isset() : subsystem(false), timer(false) {}
  bool subsystem :1;
  bool timer :1;
} _DiagService_setHealthReportTimer_args__isset;

class DiagService_setHealthReportTimer_args {
 public:

  DiagService_setHealthReportTimer_args(const DiagService_setHealthReportTimer_args&);
  DiagService_setHealthReportTimer_args& operator=(const DiagService_setHealthReportTimer_args&);
  DiagService_setHealthReportTimer_args() : subsystem((Subsystem::type)0), timer(0) {
  }

  virtual ~DiagService_setHealthReportTimer_args() noexcept;
  Subsystem::type subsystem;
  int32_t timer;

  _DiagService_setHealthReportTimer_args__isset __isset;

  void __set_subsystem(const Subsystem::type val);

  void __set_timer(const int32_t val);

  bool operator == (const DiagService_setHealthReportTimer_args & rhs) const
  {
    if (!(subsystem == rhs.subsystem))
      return false;
    if (!(timer == rhs.timer))
      return false;
    return true;
  }
  bool operator != (const DiagService_setHealthReportTimer_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setHealthReportTimer_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class DiagService_setHealthReportTimer_pargs {
 public:


  virtual ~DiagService_setHealthReportTimer_pargs() noexcept;
  const Subsystem::type* subsystem;
  const int32_t* timer;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setHealthReportTimer_result__isset {
  _DiagService_setHealthReportTimer_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setHealthReportTimer_result__isset;

class DiagService_setHealthReportTimer_result {
 public:

  DiagService_setHealthReportTimer_result(const DiagService_setHealthReportTimer_result&);
  DiagService_setHealthReportTimer_result& operator=(const DiagService_setHealthReportTimer_result&);
  DiagService_setHealthReportTimer_result() : success((HealthReportConfigureStatus::type)0) {
  }

  virtual ~DiagService_setHealthReportTimer_result() noexcept;
  HealthReportConfigureStatus::type success;
   ::Uts::AppException e;

  _DiagService_setHealthReportTimer_result__isset __isset;

  void __set_success(const HealthReportConfigureStatus::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const DiagService_setHealthReportTimer_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const DiagService_setHealthReportTimer_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagService_setHealthReportTimer_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _DiagService_setHealthReportTimer_presult__isset {
  _DiagService_setHealthReportTimer_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _DiagService_setHealthReportTimer_presult__isset;

class DiagService_setHealthReportTimer_presult {
 public:


  virtual ~DiagService_setHealthReportTimer_presult() noexcept;
  HealthReportConfigureStatus::type* success;
   ::Uts::AppException e;

  _DiagService_setHealthReportTimer_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class DiagServiceClient : virtual public DiagServiceIf {
 public:
  DiagServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  DiagServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle);
  void send_initializeServiceByProtocol(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_initializeServiceByProtocol();
   ::Uts::ErrorCode::type initializeServiceWithOptions(const DiagConnectionOptions& diagConnectionOptions);
  void send_initializeServiceWithOptions(const DiagConnectionOptions& diagConnectionOptions);
   ::Uts::ErrorCode::type recv_initializeServiceWithOptions();
   ::Uts::ErrorCode::type destroyService();
  void send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService();
  void sendRawRequest( ::Uts::DiagPacket& _return, const std::string& request, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void send_sendRawRequest(const std::string& request, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void recv_sendRawRequest( ::Uts::DiagPacket& _return);
  int64_t sendRawRequestAsync(const std::string& request);
  void send_sendRawRequestAsync(const std::string& request);
  int64_t recv_sendRawRequestAsync();
  void sendRequest( ::Uts::DiagPacket& _return, const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void send_sendRequest(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void recv_sendRequest( ::Uts::DiagPacket& _return);
  int64_t sendRequestAsync(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList);
  void send_sendRequestAsync(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList);
  int64_t recv_sendRequestAsync();
  void getResponseAsync( ::Uts::DiagPacket& _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void send_getResponseAsync(const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void recv_getResponseAsync( ::Uts::DiagPacket& _return);
  void getAllResponsesAsync(std::vector< ::Uts::DiagPacket> & _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void send_getAllResponsesAsync(const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void recv_getAllResponsesAsync(std::vector< ::Uts::DiagPacket> & _return);
   ::Uts::ErrorCode::type createDataQueue(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::DiagReturnConfig& returnConfig);
  void send_createDataQueue(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::DiagReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createDataQueue();
   ::Uts::ErrorCode::type createDataQueueWithAnnotations(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::AnnotationPacketFilter& annotationsFilter, const  ::Uts::DiagReturnConfig& returnConfig);
  void send_createDataQueueWithAnnotations(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::AnnotationPacketFilter& annotationsFilter, const  ::Uts::DiagReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createDataQueueWithAnnotations();
   ::Uts::ErrorCode::type removeDataQueue(const std::string& queueName);
  void send_removeDataQueue(const std::string& queueName);
   ::Uts::ErrorCode::type recv_removeDataQueue();
   ::Uts::ErrorCode::type clearDataQueue(const std::string& queueName);
  void send_clearDataQueue(const std::string& queueName);
   ::Uts::ErrorCode::type recv_clearDataQueue();
  void getDataQueueItems(std::vector< ::Uts::DiagPacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout);
  void send_getDataQueueItems(const std::string& queueName, const int32_t count, const int32_t timeout);
  void recv_getDataQueueItems(std::vector< ::Uts::DiagPacket> & _return);
  void getDataQueueItemsWithAnnotations(std::vector<DataQueuePacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout);
  void send_getDataQueueItemsWithAnnotations(const std::string& queueName, const int32_t count, const int32_t timeout);
  void recv_getDataQueueItemsWithAnnotations(std::vector<DataQueuePacket> & _return);
   ::Uts::ErrorCode::type addDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter);
  void send_addDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter);
   ::Uts::ErrorCode::type recv_addDataQueueFilter();
   ::Uts::ErrorCode::type removeDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter);
  void send_removeDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter);
   ::Uts::ErrorCode::type recv_removeDataQueueFilter();
   ::Uts::ErrorCode::type setLoggingMask(const std::string& maskFileContent, const  ::Uts::LogMaskFormat::type format);
  void send_setLoggingMask(const std::string& maskFileContent, const  ::Uts::LogMaskFormat::type format);
   ::Uts::ErrorCode::type recv_setLoggingMask();
   ::Uts::QShrink4DownloadState::type getQShrinkState();
  void send_getQShrinkState();
   ::Uts::QShrink4DownloadState::type recv_getQShrinkState();
  void loadQShrinkFile(const std::string& pathName);
  void send_loadQShrinkFile(const std::string& pathName);
  void recv_loadQShrinkFile();
   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const  ::Uts::WcdmaProtocolRevision::type revision);
  void send_setWcdmaProtocolRevision(const  ::Uts::WcdmaProtocolRevision::type revision);
   ::Uts::ErrorCode::type recv_setWcdmaProtocolRevision();
   ::Uts::ErrorCode::type setCdmaProtocolRevision(const  ::Uts::CdmaProtocolRevision::type revision);
  void send_setCdmaProtocolRevision(const  ::Uts::CdmaProtocolRevision::type revision);
   ::Uts::ErrorCode::type recv_setCdmaProtocolRevision();
   ::Uts::ErrorCode::type setPilotInc(const int16_t pilotInc);
  void send_setPilotInc(const int16_t pilotInc);
   ::Uts::ErrorCode::type recv_setPilotInc();
   ::Uts::ErrorCode::type setLoggingMaskFromFilter(const  ::Uts::DiagPacketFilter& filter);
  void send_setLoggingMaskFromFilter(const  ::Uts::DiagPacketFilter& filter);
   ::Uts::ErrorCode::type recv_setLoggingMaskFromFilter();
  HealthReportConfigureStatus::type resetHealthReportCounters(const Subsystem::type subsystem);
  void send_resetHealthReportCounters(const Subsystem::type subsystem);
  HealthReportConfigureStatus::type recv_resetHealthReportCounters();
  HealthReportConfigureStatus::type setHealthReportTimer(const Subsystem::type subsystem, const int32_t timer);
  void send_setHealthReportTimer(const Subsystem::type subsystem, const int32_t timer);
  HealthReportConfigureStatus::type recv_setHealthReportTimer();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class DiagServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<DiagServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (DiagServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeServiceByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeServiceWithOptions(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_destroyService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendRawRequest(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendRawRequestAsync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendRequest(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendRequestAsync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getResponseAsync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getAllResponsesAsync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createDataQueue(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createDataQueueWithAnnotations(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeDataQueue(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_clearDataQueue(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDataQueueItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDataQueueItemsWithAnnotations(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_addDataQueueFilter(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_removeDataQueueFilter(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setLoggingMask(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getQShrinkState(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_loadQShrinkFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setWcdmaProtocolRevision(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setCdmaProtocolRevision(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setPilotInc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setLoggingMaskFromFilter(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_resetHealthReportCounters(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setHealthReportTimer(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  DiagServiceProcessor(::std::shared_ptr<DiagServiceIf> iface) :
    iface_(iface) {
    processMap_["getLastError"] = &DiagServiceProcessor::process_getLastError;
    processMap_["getDevice"] = &DiagServiceProcessor::process_getDevice;
    processMap_["initializeService"] = &DiagServiceProcessor::process_initializeService;
    processMap_["initializeServiceByProtocol"] = &DiagServiceProcessor::process_initializeServiceByProtocol;
    processMap_["initializeServiceWithOptions"] = &DiagServiceProcessor::process_initializeServiceWithOptions;
    processMap_["destroyService"] = &DiagServiceProcessor::process_destroyService;
    processMap_["sendRawRequest"] = &DiagServiceProcessor::process_sendRawRequest;
    processMap_["sendRawRequestAsync"] = &DiagServiceProcessor::process_sendRawRequestAsync;
    processMap_["sendRequest"] = &DiagServiceProcessor::process_sendRequest;
    processMap_["sendRequestAsync"] = &DiagServiceProcessor::process_sendRequestAsync;
    processMap_["getResponseAsync"] = &DiagServiceProcessor::process_getResponseAsync;
    processMap_["getAllResponsesAsync"] = &DiagServiceProcessor::process_getAllResponsesAsync;
    processMap_["createDataQueue"] = &DiagServiceProcessor::process_createDataQueue;
    processMap_["createDataQueueWithAnnotations"] = &DiagServiceProcessor::process_createDataQueueWithAnnotations;
    processMap_["removeDataQueue"] = &DiagServiceProcessor::process_removeDataQueue;
    processMap_["clearDataQueue"] = &DiagServiceProcessor::process_clearDataQueue;
    processMap_["getDataQueueItems"] = &DiagServiceProcessor::process_getDataQueueItems;
    processMap_["getDataQueueItemsWithAnnotations"] = &DiagServiceProcessor::process_getDataQueueItemsWithAnnotations;
    processMap_["addDataQueueFilter"] = &DiagServiceProcessor::process_addDataQueueFilter;
    processMap_["removeDataQueueFilter"] = &DiagServiceProcessor::process_removeDataQueueFilter;
    processMap_["setLoggingMask"] = &DiagServiceProcessor::process_setLoggingMask;
    processMap_["getQShrinkState"] = &DiagServiceProcessor::process_getQShrinkState;
    processMap_["loadQShrinkFile"] = &DiagServiceProcessor::process_loadQShrinkFile;
    processMap_["setWcdmaProtocolRevision"] = &DiagServiceProcessor::process_setWcdmaProtocolRevision;
    processMap_["setCdmaProtocolRevision"] = &DiagServiceProcessor::process_setCdmaProtocolRevision;
    processMap_["setPilotInc"] = &DiagServiceProcessor::process_setPilotInc;
    processMap_["setLoggingMaskFromFilter"] = &DiagServiceProcessor::process_setLoggingMaskFromFilter;
    processMap_["resetHealthReportCounters"] = &DiagServiceProcessor::process_resetHealthReportCounters;
    processMap_["setHealthReportTimer"] = &DiagServiceProcessor::process_setHealthReportTimer;
  }

  virtual ~DiagServiceProcessor() {}
};

class DiagServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  DiagServiceProcessorFactory(const ::std::shared_ptr< DiagServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< DiagServiceIfFactory > handlerFactory_;
};

class DiagServiceMultiface : virtual public DiagServiceIf {
 public:
  DiagServiceMultiface(std::vector<std::shared_ptr<DiagServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~DiagServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<DiagServiceIf> > ifaces_;
  DiagServiceMultiface() {}
  void add(::std::shared_ptr<DiagServiceIf> iface) {
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

   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initializeServiceByProtocol(protocolHandle);
    }
    return ifaces_[i]->initializeServiceByProtocol(protocolHandle);
  }

   ::Uts::ErrorCode::type initializeServiceWithOptions(const DiagConnectionOptions& diagConnectionOptions) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->initializeServiceWithOptions(diagConnectionOptions);
    }
    return ifaces_[i]->initializeServiceWithOptions(diagConnectionOptions);
  }

   ::Uts::ErrorCode::type destroyService() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->destroyService();
    }
    return ifaces_[i]->destroyService();
  }

  void sendRawRequest( ::Uts::DiagPacket& _return, const std::string& request, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendRawRequest(_return, request, returnConfig, timeout);
    }
    ifaces_[i]->sendRawRequest(_return, request, returnConfig, timeout);
    return;
  }

  int64_t sendRawRequestAsync(const std::string& request) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendRawRequestAsync(request);
    }
    return ifaces_[i]->sendRawRequestAsync(request);
  }

  void sendRequest( ::Uts::DiagPacket& _return, const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendRequest(_return, requestType, requestIdOrName, fieldList, returnConfig, timeout);
    }
    ifaces_[i]->sendRequest(_return, requestType, requestIdOrName, fieldList, returnConfig, timeout);
    return;
  }

  int64_t sendRequestAsync(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendRequestAsync(requestType, requestIdOrName, fieldList);
    }
    return ifaces_[i]->sendRequestAsync(requestType, requestIdOrName, fieldList);
  }

  void getResponseAsync( ::Uts::DiagPacket& _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getResponseAsync(_return, transactionId, returnConfig, timeout);
    }
    ifaces_[i]->getResponseAsync(_return, transactionId, returnConfig, timeout);
    return;
  }

  void getAllResponsesAsync(std::vector< ::Uts::DiagPacket> & _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getAllResponsesAsync(_return, transactionId, returnConfig, timeout);
    }
    ifaces_[i]->getAllResponsesAsync(_return, transactionId, returnConfig, timeout);
    return;
  }

   ::Uts::ErrorCode::type createDataQueue(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::DiagReturnConfig& returnConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createDataQueue(queueName, filter, returnConfig);
    }
    return ifaces_[i]->createDataQueue(queueName, filter, returnConfig);
  }

   ::Uts::ErrorCode::type createDataQueueWithAnnotations(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::AnnotationPacketFilter& annotationsFilter, const  ::Uts::DiagReturnConfig& returnConfig) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createDataQueueWithAnnotations(queueName, filter, annotationsFilter, returnConfig);
    }
    return ifaces_[i]->createDataQueueWithAnnotations(queueName, filter, annotationsFilter, returnConfig);
  }

   ::Uts::ErrorCode::type removeDataQueue(const std::string& queueName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeDataQueue(queueName);
    }
    return ifaces_[i]->removeDataQueue(queueName);
  }

   ::Uts::ErrorCode::type clearDataQueue(const std::string& queueName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->clearDataQueue(queueName);
    }
    return ifaces_[i]->clearDataQueue(queueName);
  }

  void getDataQueueItems(std::vector< ::Uts::DiagPacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDataQueueItems(_return, queueName, count, timeout);
    }
    ifaces_[i]->getDataQueueItems(_return, queueName, count, timeout);
    return;
  }

  void getDataQueueItemsWithAnnotations(std::vector<DataQueuePacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDataQueueItemsWithAnnotations(_return, queueName, count, timeout);
    }
    ifaces_[i]->getDataQueueItemsWithAnnotations(_return, queueName, count, timeout);
    return;
  }

   ::Uts::ErrorCode::type addDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->addDataQueueFilter(queueName, filter);
    }
    return ifaces_[i]->addDataQueueFilter(queueName, filter);
  }

   ::Uts::ErrorCode::type removeDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->removeDataQueueFilter(queueName, filter);
    }
    return ifaces_[i]->removeDataQueueFilter(queueName, filter);
  }

   ::Uts::ErrorCode::type setLoggingMask(const std::string& maskFileContent, const  ::Uts::LogMaskFormat::type format) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setLoggingMask(maskFileContent, format);
    }
    return ifaces_[i]->setLoggingMask(maskFileContent, format);
  }

   ::Uts::QShrink4DownloadState::type getQShrinkState() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getQShrinkState();
    }
    return ifaces_[i]->getQShrinkState();
  }

  void loadQShrinkFile(const std::string& pathName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->loadQShrinkFile(pathName);
    }
    ifaces_[i]->loadQShrinkFile(pathName);
  }

   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const  ::Uts::WcdmaProtocolRevision::type revision) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setWcdmaProtocolRevision(revision);
    }
    return ifaces_[i]->setWcdmaProtocolRevision(revision);
  }

   ::Uts::ErrorCode::type setCdmaProtocolRevision(const  ::Uts::CdmaProtocolRevision::type revision) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setCdmaProtocolRevision(revision);
    }
    return ifaces_[i]->setCdmaProtocolRevision(revision);
  }

   ::Uts::ErrorCode::type setPilotInc(const int16_t pilotInc) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setPilotInc(pilotInc);
    }
    return ifaces_[i]->setPilotInc(pilotInc);
  }

   ::Uts::ErrorCode::type setLoggingMaskFromFilter(const  ::Uts::DiagPacketFilter& filter) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setLoggingMaskFromFilter(filter);
    }
    return ifaces_[i]->setLoggingMaskFromFilter(filter);
  }

  HealthReportConfigureStatus::type resetHealthReportCounters(const Subsystem::type subsystem) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->resetHealthReportCounters(subsystem);
    }
    return ifaces_[i]->resetHealthReportCounters(subsystem);
  }

  HealthReportConfigureStatus::type setHealthReportTimer(const Subsystem::type subsystem, const int32_t timer) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setHealthReportTimer(subsystem, timer);
    }
    return ifaces_[i]->setHealthReportTimer(subsystem, timer);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class DiagServiceConcurrentClient : virtual public DiagServiceIf {
 public:
  DiagServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  DiagServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle);
  int32_t send_initializeServiceByProtocol(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_initializeServiceByProtocol(const int32_t seqid);
   ::Uts::ErrorCode::type initializeServiceWithOptions(const DiagConnectionOptions& diagConnectionOptions);
  int32_t send_initializeServiceWithOptions(const DiagConnectionOptions& diagConnectionOptions);
   ::Uts::ErrorCode::type recv_initializeServiceWithOptions(const int32_t seqid);
   ::Uts::ErrorCode::type destroyService();
  int32_t send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService(const int32_t seqid);
  void sendRawRequest( ::Uts::DiagPacket& _return, const std::string& request, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  int32_t send_sendRawRequest(const std::string& request, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void recv_sendRawRequest( ::Uts::DiagPacket& _return, const int32_t seqid);
  int64_t sendRawRequestAsync(const std::string& request);
  int32_t send_sendRawRequestAsync(const std::string& request);
  int64_t recv_sendRawRequestAsync(const int32_t seqid);
  void sendRequest( ::Uts::DiagPacket& _return, const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  int32_t send_sendRequest(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void recv_sendRequest( ::Uts::DiagPacket& _return, const int32_t seqid);
  int64_t sendRequestAsync(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList);
  int32_t send_sendRequestAsync(const  ::Uts::DiagPacketType::type requestType, const std::string& requestIdOrName, const std::string& fieldList);
  int64_t recv_sendRequestAsync(const int32_t seqid);
  void getResponseAsync( ::Uts::DiagPacket& _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  int32_t send_getResponseAsync(const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void recv_getResponseAsync( ::Uts::DiagPacket& _return, const int32_t seqid);
  void getAllResponsesAsync(std::vector< ::Uts::DiagPacket> & _return, const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  int32_t send_getAllResponsesAsync(const int64_t transactionId, const  ::Uts::DiagReturns& returnConfig, const int32_t timeout);
  void recv_getAllResponsesAsync(std::vector< ::Uts::DiagPacket> & _return, const int32_t seqid);
   ::Uts::ErrorCode::type createDataQueue(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::DiagReturnConfig& returnConfig);
  int32_t send_createDataQueue(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::DiagReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createDataQueue(const int32_t seqid);
   ::Uts::ErrorCode::type createDataQueueWithAnnotations(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::AnnotationPacketFilter& annotationsFilter, const  ::Uts::DiagReturnConfig& returnConfig);
  int32_t send_createDataQueueWithAnnotations(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter, const  ::Uts::AnnotationPacketFilter& annotationsFilter, const  ::Uts::DiagReturnConfig& returnConfig);
   ::Uts::ErrorCode::type recv_createDataQueueWithAnnotations(const int32_t seqid);
   ::Uts::ErrorCode::type removeDataQueue(const std::string& queueName);
  int32_t send_removeDataQueue(const std::string& queueName);
   ::Uts::ErrorCode::type recv_removeDataQueue(const int32_t seqid);
   ::Uts::ErrorCode::type clearDataQueue(const std::string& queueName);
  int32_t send_clearDataQueue(const std::string& queueName);
   ::Uts::ErrorCode::type recv_clearDataQueue(const int32_t seqid);
  void getDataQueueItems(std::vector< ::Uts::DiagPacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout);
  int32_t send_getDataQueueItems(const std::string& queueName, const int32_t count, const int32_t timeout);
  void recv_getDataQueueItems(std::vector< ::Uts::DiagPacket> & _return, const int32_t seqid);
  void getDataQueueItemsWithAnnotations(std::vector<DataQueuePacket> & _return, const std::string& queueName, const int32_t count, const int32_t timeout);
  int32_t send_getDataQueueItemsWithAnnotations(const std::string& queueName, const int32_t count, const int32_t timeout);
  void recv_getDataQueueItemsWithAnnotations(std::vector<DataQueuePacket> & _return, const int32_t seqid);
   ::Uts::ErrorCode::type addDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter);
  int32_t send_addDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter);
   ::Uts::ErrorCode::type recv_addDataQueueFilter(const int32_t seqid);
   ::Uts::ErrorCode::type removeDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter);
  int32_t send_removeDataQueueFilter(const std::string& queueName, const  ::Uts::DiagPacketFilter& filter);
   ::Uts::ErrorCode::type recv_removeDataQueueFilter(const int32_t seqid);
   ::Uts::ErrorCode::type setLoggingMask(const std::string& maskFileContent, const  ::Uts::LogMaskFormat::type format);
  int32_t send_setLoggingMask(const std::string& maskFileContent, const  ::Uts::LogMaskFormat::type format);
   ::Uts::ErrorCode::type recv_setLoggingMask(const int32_t seqid);
   ::Uts::QShrink4DownloadState::type getQShrinkState();
  int32_t send_getQShrinkState();
   ::Uts::QShrink4DownloadState::type recv_getQShrinkState(const int32_t seqid);
  void loadQShrinkFile(const std::string& pathName);
  int32_t send_loadQShrinkFile(const std::string& pathName);
  void recv_loadQShrinkFile(const int32_t seqid);
   ::Uts::ErrorCode::type setWcdmaProtocolRevision(const  ::Uts::WcdmaProtocolRevision::type revision);
  int32_t send_setWcdmaProtocolRevision(const  ::Uts::WcdmaProtocolRevision::type revision);
   ::Uts::ErrorCode::type recv_setWcdmaProtocolRevision(const int32_t seqid);
   ::Uts::ErrorCode::type setCdmaProtocolRevision(const  ::Uts::CdmaProtocolRevision::type revision);
  int32_t send_setCdmaProtocolRevision(const  ::Uts::CdmaProtocolRevision::type revision);
   ::Uts::ErrorCode::type recv_setCdmaProtocolRevision(const int32_t seqid);
   ::Uts::ErrorCode::type setPilotInc(const int16_t pilotInc);
  int32_t send_setPilotInc(const int16_t pilotInc);
   ::Uts::ErrorCode::type recv_setPilotInc(const int32_t seqid);
   ::Uts::ErrorCode::type setLoggingMaskFromFilter(const  ::Uts::DiagPacketFilter& filter);
  int32_t send_setLoggingMaskFromFilter(const  ::Uts::DiagPacketFilter& filter);
   ::Uts::ErrorCode::type recv_setLoggingMaskFromFilter(const int32_t seqid);
  HealthReportConfigureStatus::type resetHealthReportCounters(const Subsystem::type subsystem);
  int32_t send_resetHealthReportCounters(const Subsystem::type subsystem);
  HealthReportConfigureStatus::type recv_resetHealthReportCounters(const int32_t seqid);
  HealthReportConfigureStatus::type setHealthReportTimer(const Subsystem::type subsystem, const int32_t timer);
  int32_t send_setHealthReportTimer(const Subsystem::type subsystem, const int32_t timer);
  HealthReportConfigureStatus::type recv_setHealthReportTimer(const int32_t seqid);
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
