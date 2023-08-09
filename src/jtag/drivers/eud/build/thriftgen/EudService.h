/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudService_H
#define EudService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "EudService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class EudServiceIf {
 public:
  virtual ~EudServiceIf() {}
  virtual void getLastError( ::Uts::ErrorType& _return) = 0;
  virtual int64_t getDevice() = 0;
  virtual  ::Uts::ErrorCode::type initializeService() = 0;
  virtual  ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type destroyService() = 0;
  virtual void sendCommand(const EudCmdInfo& eudCmdInfo) = 0;
  virtual void sendRawRequest( ::Uts::EudPacket& _return, const std::string& request, const  ::Uts::EudReturnConfig& returnConfig, const int32_t timeout) = 0;
  virtual int64_t sendRawRequestAsync(const std::string& request) = 0;
  virtual  ::Uts::EudPeripheralType::type GetEudPeripheralType(const int64_t protocolHandle) = 0;
};

class EudServiceIfFactory {
 public:
  typedef EudServiceIf Handler;

  virtual ~EudServiceIfFactory() {}

  virtual EudServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(EudServiceIf* /* handler */) = 0;
};

class EudServiceIfSingletonFactory : virtual public EudServiceIfFactory {
 public:
  EudServiceIfSingletonFactory(const ::std::shared_ptr<EudServiceIf>& iface) : iface_(iface) {}
  virtual ~EudServiceIfSingletonFactory() {}

  virtual EudServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(EudServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<EudServiceIf> iface_;
};

class EudServiceNull : virtual public EudServiceIf {
 public:
  virtual ~EudServiceNull() {}
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
   ::Uts::ErrorCode::type destroyService() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void sendCommand(const EudCmdInfo& /* eudCmdInfo */) {
    return;
  }
  void sendRawRequest( ::Uts::EudPacket& /* _return */, const std::string& /* request */, const  ::Uts::EudReturnConfig& /* returnConfig */, const int32_t /* timeout */) {
    return;
  }
  int64_t sendRawRequestAsync(const std::string& /* request */) {
    int64_t _return = 0;
    return _return;
  }
   ::Uts::EudPeripheralType::type GetEudPeripheralType(const int64_t /* protocolHandle */) {
     ::Uts::EudPeripheralType::type _return = ( ::Uts::EudPeripheralType::type)0;
    return _return;
  }
};


class EudService_getLastError_args {
 public:

  EudService_getLastError_args(const EudService_getLastError_args&);
  EudService_getLastError_args& operator=(const EudService_getLastError_args&);
  EudService_getLastError_args() {
  }

  virtual ~EudService_getLastError_args() noexcept;

  bool operator == (const EudService_getLastError_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudService_getLastError_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_getLastError_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_getLastError_pargs {
 public:


  virtual ~EudService_getLastError_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_getLastError_result__isset {
  _EudService_getLastError_result__isset() : success(false) {}
  bool success :1;
} _EudService_getLastError_result__isset;

class EudService_getLastError_result {
 public:

  EudService_getLastError_result(const EudService_getLastError_result&);
  EudService_getLastError_result& operator=(const EudService_getLastError_result&);
  EudService_getLastError_result() {
  }

  virtual ~EudService_getLastError_result() noexcept;
   ::Uts::ErrorType success;

  _EudService_getLastError_result__isset __isset;

  void __set_success(const  ::Uts::ErrorType& val);

  bool operator == (const EudService_getLastError_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const EudService_getLastError_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_getLastError_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_getLastError_presult__isset {
  _EudService_getLastError_presult__isset() : success(false) {}
  bool success :1;
} _EudService_getLastError_presult__isset;

class EudService_getLastError_presult {
 public:


  virtual ~EudService_getLastError_presult() noexcept;
   ::Uts::ErrorType* success;

  _EudService_getLastError_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudService_getDevice_args {
 public:

  EudService_getDevice_args(const EudService_getDevice_args&);
  EudService_getDevice_args& operator=(const EudService_getDevice_args&);
  EudService_getDevice_args() {
  }

  virtual ~EudService_getDevice_args() noexcept;

  bool operator == (const EudService_getDevice_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudService_getDevice_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_getDevice_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_getDevice_pargs {
 public:


  virtual ~EudService_getDevice_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_getDevice_result__isset {
  _EudService_getDevice_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_getDevice_result__isset;

class EudService_getDevice_result {
 public:

  EudService_getDevice_result(const EudService_getDevice_result&);
  EudService_getDevice_result& operator=(const EudService_getDevice_result&);
  EudService_getDevice_result() : success(0) {
  }

  virtual ~EudService_getDevice_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _EudService_getDevice_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudService_getDevice_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudService_getDevice_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_getDevice_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_getDevice_presult__isset {
  _EudService_getDevice_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_getDevice_presult__isset;

class EudService_getDevice_presult {
 public:


  virtual ~EudService_getDevice_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _EudService_getDevice_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudService_initializeService_args {
 public:

  EudService_initializeService_args(const EudService_initializeService_args&);
  EudService_initializeService_args& operator=(const EudService_initializeService_args&);
  EudService_initializeService_args() {
  }

  virtual ~EudService_initializeService_args() noexcept;

  bool operator == (const EudService_initializeService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudService_initializeService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_initializeService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_initializeService_pargs {
 public:


  virtual ~EudService_initializeService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_initializeService_result__isset {
  _EudService_initializeService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_initializeService_result__isset;

class EudService_initializeService_result {
 public:

  EudService_initializeService_result(const EudService_initializeService_result&);
  EudService_initializeService_result& operator=(const EudService_initializeService_result&);
  EudService_initializeService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudService_initializeService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudService_initializeService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudService_initializeService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudService_initializeService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_initializeService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_initializeService_presult__isset {
  _EudService_initializeService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_initializeService_presult__isset;

class EudService_initializeService_presult {
 public:


  virtual ~EudService_initializeService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudService_initializeService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudService_initializeServiceByProtocol_args__isset {
  _EudService_initializeServiceByProtocol_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _EudService_initializeServiceByProtocol_args__isset;

class EudService_initializeServiceByProtocol_args {
 public:

  EudService_initializeServiceByProtocol_args(const EudService_initializeServiceByProtocol_args&);
  EudService_initializeServiceByProtocol_args& operator=(const EudService_initializeServiceByProtocol_args&);
  EudService_initializeServiceByProtocol_args() : protocolHandle(0) {
  }

  virtual ~EudService_initializeServiceByProtocol_args() noexcept;
  int64_t protocolHandle;

  _EudService_initializeServiceByProtocol_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const EudService_initializeServiceByProtocol_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const EudService_initializeServiceByProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_initializeServiceByProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_initializeServiceByProtocol_pargs {
 public:


  virtual ~EudService_initializeServiceByProtocol_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_initializeServiceByProtocol_result__isset {
  _EudService_initializeServiceByProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_initializeServiceByProtocol_result__isset;

class EudService_initializeServiceByProtocol_result {
 public:

  EudService_initializeServiceByProtocol_result(const EudService_initializeServiceByProtocol_result&);
  EudService_initializeServiceByProtocol_result& operator=(const EudService_initializeServiceByProtocol_result&);
  EudService_initializeServiceByProtocol_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudService_initializeServiceByProtocol_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudService_initializeServiceByProtocol_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudService_initializeServiceByProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudService_initializeServiceByProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_initializeServiceByProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_initializeServiceByProtocol_presult__isset {
  _EudService_initializeServiceByProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_initializeServiceByProtocol_presult__isset;

class EudService_initializeServiceByProtocol_presult {
 public:


  virtual ~EudService_initializeServiceByProtocol_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudService_initializeServiceByProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudService_destroyService_args {
 public:

  EudService_destroyService_args(const EudService_destroyService_args&);
  EudService_destroyService_args& operator=(const EudService_destroyService_args&);
  EudService_destroyService_args() {
  }

  virtual ~EudService_destroyService_args() noexcept;

  bool operator == (const EudService_destroyService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudService_destroyService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_destroyService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_destroyService_pargs {
 public:


  virtual ~EudService_destroyService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_destroyService_result__isset {
  _EudService_destroyService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_destroyService_result__isset;

class EudService_destroyService_result {
 public:

  EudService_destroyService_result(const EudService_destroyService_result&);
  EudService_destroyService_result& operator=(const EudService_destroyService_result&);
  EudService_destroyService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudService_destroyService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudService_destroyService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudService_destroyService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudService_destroyService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_destroyService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_destroyService_presult__isset {
  _EudService_destroyService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_destroyService_presult__isset;

class EudService_destroyService_presult {
 public:


  virtual ~EudService_destroyService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudService_destroyService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudService_sendCommand_args__isset {
  _EudService_sendCommand_args__isset() : eudCmdInfo(false) {}
  bool eudCmdInfo :1;
} _EudService_sendCommand_args__isset;

class EudService_sendCommand_args {
 public:

  EudService_sendCommand_args(const EudService_sendCommand_args&);
  EudService_sendCommand_args& operator=(const EudService_sendCommand_args&);
  EudService_sendCommand_args() {
  }

  virtual ~EudService_sendCommand_args() noexcept;
  EudCmdInfo eudCmdInfo;

  _EudService_sendCommand_args__isset __isset;

  void __set_eudCmdInfo(const EudCmdInfo& val);

  bool operator == (const EudService_sendCommand_args & rhs) const
  {
    if (!(eudCmdInfo == rhs.eudCmdInfo))
      return false;
    return true;
  }
  bool operator != (const EudService_sendCommand_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_sendCommand_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_sendCommand_pargs {
 public:


  virtual ~EudService_sendCommand_pargs() noexcept;
  const EudCmdInfo* eudCmdInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_sendCommand_result__isset {
  _EudService_sendCommand_result__isset() : e(false) {}
  bool e :1;
} _EudService_sendCommand_result__isset;

class EudService_sendCommand_result {
 public:

  EudService_sendCommand_result(const EudService_sendCommand_result&);
  EudService_sendCommand_result& operator=(const EudService_sendCommand_result&);
  EudService_sendCommand_result() {
  }

  virtual ~EudService_sendCommand_result() noexcept;
   ::Uts::AppException e;

  _EudService_sendCommand_result__isset __isset;

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudService_sendCommand_result & rhs) const
  {
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudService_sendCommand_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_sendCommand_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_sendCommand_presult__isset {
  _EudService_sendCommand_presult__isset() : e(false) {}
  bool e :1;
} _EudService_sendCommand_presult__isset;

class EudService_sendCommand_presult {
 public:


  virtual ~EudService_sendCommand_presult() noexcept;
   ::Uts::AppException e;

  _EudService_sendCommand_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudService_sendRawRequest_args__isset {
  _EudService_sendRawRequest_args__isset() : request(false), returnConfig(false), timeout(false) {}
  bool request :1;
  bool returnConfig :1;
  bool timeout :1;
} _EudService_sendRawRequest_args__isset;

class EudService_sendRawRequest_args {
 public:

  EudService_sendRawRequest_args(const EudService_sendRawRequest_args&);
  EudService_sendRawRequest_args& operator=(const EudService_sendRawRequest_args&);
  EudService_sendRawRequest_args() : request(), timeout(0) {
  }

  virtual ~EudService_sendRawRequest_args() noexcept;
  std::string request;
   ::Uts::EudReturnConfig returnConfig;
  int32_t timeout;

  _EudService_sendRawRequest_args__isset __isset;

  void __set_request(const std::string& val);

  void __set_returnConfig(const  ::Uts::EudReturnConfig& val);

  void __set_timeout(const int32_t val);

  bool operator == (const EudService_sendRawRequest_args & rhs) const
  {
    if (!(request == rhs.request))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    if (!(timeout == rhs.timeout))
      return false;
    return true;
  }
  bool operator != (const EudService_sendRawRequest_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_sendRawRequest_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_sendRawRequest_pargs {
 public:


  virtual ~EudService_sendRawRequest_pargs() noexcept;
  const std::string* request;
  const  ::Uts::EudReturnConfig* returnConfig;
  const int32_t* timeout;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_sendRawRequest_result__isset {
  _EudService_sendRawRequest_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_sendRawRequest_result__isset;

class EudService_sendRawRequest_result {
 public:

  EudService_sendRawRequest_result(const EudService_sendRawRequest_result&);
  EudService_sendRawRequest_result& operator=(const EudService_sendRawRequest_result&);
  EudService_sendRawRequest_result() {
  }

  virtual ~EudService_sendRawRequest_result() noexcept;
   ::Uts::EudPacket success;
   ::Uts::AppException e;

  _EudService_sendRawRequest_result__isset __isset;

  void __set_success(const  ::Uts::EudPacket& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudService_sendRawRequest_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudService_sendRawRequest_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_sendRawRequest_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_sendRawRequest_presult__isset {
  _EudService_sendRawRequest_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_sendRawRequest_presult__isset;

class EudService_sendRawRequest_presult {
 public:


  virtual ~EudService_sendRawRequest_presult() noexcept;
   ::Uts::EudPacket* success;
   ::Uts::AppException e;

  _EudService_sendRawRequest_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudService_sendRawRequestAsync_args__isset {
  _EudService_sendRawRequestAsync_args__isset() : request(false) {}
  bool request :1;
} _EudService_sendRawRequestAsync_args__isset;

class EudService_sendRawRequestAsync_args {
 public:

  EudService_sendRawRequestAsync_args(const EudService_sendRawRequestAsync_args&);
  EudService_sendRawRequestAsync_args& operator=(const EudService_sendRawRequestAsync_args&);
  EudService_sendRawRequestAsync_args() : request() {
  }

  virtual ~EudService_sendRawRequestAsync_args() noexcept;
  std::string request;

  _EudService_sendRawRequestAsync_args__isset __isset;

  void __set_request(const std::string& val);

  bool operator == (const EudService_sendRawRequestAsync_args & rhs) const
  {
    if (!(request == rhs.request))
      return false;
    return true;
  }
  bool operator != (const EudService_sendRawRequestAsync_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_sendRawRequestAsync_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_sendRawRequestAsync_pargs {
 public:


  virtual ~EudService_sendRawRequestAsync_pargs() noexcept;
  const std::string* request;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_sendRawRequestAsync_result__isset {
  _EudService_sendRawRequestAsync_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_sendRawRequestAsync_result__isset;

class EudService_sendRawRequestAsync_result {
 public:

  EudService_sendRawRequestAsync_result(const EudService_sendRawRequestAsync_result&);
  EudService_sendRawRequestAsync_result& operator=(const EudService_sendRawRequestAsync_result&);
  EudService_sendRawRequestAsync_result() : success(0) {
  }

  virtual ~EudService_sendRawRequestAsync_result() noexcept;
  int64_t success;
   ::Uts::AppException e;

  _EudService_sendRawRequestAsync_result__isset __isset;

  void __set_success(const int64_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudService_sendRawRequestAsync_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudService_sendRawRequestAsync_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_sendRawRequestAsync_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_sendRawRequestAsync_presult__isset {
  _EudService_sendRawRequestAsync_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_sendRawRequestAsync_presult__isset;

class EudService_sendRawRequestAsync_presult {
 public:


  virtual ~EudService_sendRawRequestAsync_presult() noexcept;
  int64_t* success;
   ::Uts::AppException e;

  _EudService_sendRawRequestAsync_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudService_GetEudPeripheralType_args__isset {
  _EudService_GetEudPeripheralType_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _EudService_GetEudPeripheralType_args__isset;

class EudService_GetEudPeripheralType_args {
 public:

  EudService_GetEudPeripheralType_args(const EudService_GetEudPeripheralType_args&);
  EudService_GetEudPeripheralType_args& operator=(const EudService_GetEudPeripheralType_args&);
  EudService_GetEudPeripheralType_args() : protocolHandle(0) {
  }

  virtual ~EudService_GetEudPeripheralType_args() noexcept;
  int64_t protocolHandle;

  _EudService_GetEudPeripheralType_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const EudService_GetEudPeripheralType_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const EudService_GetEudPeripheralType_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_GetEudPeripheralType_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudService_GetEudPeripheralType_pargs {
 public:


  virtual ~EudService_GetEudPeripheralType_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_GetEudPeripheralType_result__isset {
  _EudService_GetEudPeripheralType_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_GetEudPeripheralType_result__isset;

class EudService_GetEudPeripheralType_result {
 public:

  EudService_GetEudPeripheralType_result(const EudService_GetEudPeripheralType_result&);
  EudService_GetEudPeripheralType_result& operator=(const EudService_GetEudPeripheralType_result&);
  EudService_GetEudPeripheralType_result() : success(( ::Uts::EudPeripheralType::type)0) {
  }

  virtual ~EudService_GetEudPeripheralType_result() noexcept;
   ::Uts::EudPeripheralType::type success;
   ::Uts::AppException e;

  _EudService_GetEudPeripheralType_result__isset __isset;

  void __set_success(const  ::Uts::EudPeripheralType::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudService_GetEudPeripheralType_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudService_GetEudPeripheralType_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudService_GetEudPeripheralType_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudService_GetEudPeripheralType_presult__isset {
  _EudService_GetEudPeripheralType_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudService_GetEudPeripheralType_presult__isset;

class EudService_GetEudPeripheralType_presult {
 public:


  virtual ~EudService_GetEudPeripheralType_presult() noexcept;
   ::Uts::EudPeripheralType::type* success;
   ::Uts::AppException e;

  _EudService_GetEudPeripheralType_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class EudServiceClient : virtual public EudServiceIf {
 public:
  EudServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  EudServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
   ::Uts::ErrorCode::type destroyService();
  void send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService();
  void sendCommand(const EudCmdInfo& eudCmdInfo);
  void send_sendCommand(const EudCmdInfo& eudCmdInfo);
  void recv_sendCommand();
  void sendRawRequest( ::Uts::EudPacket& _return, const std::string& request, const  ::Uts::EudReturnConfig& returnConfig, const int32_t timeout);
  void send_sendRawRequest(const std::string& request, const  ::Uts::EudReturnConfig& returnConfig, const int32_t timeout);
  void recv_sendRawRequest( ::Uts::EudPacket& _return);
  int64_t sendRawRequestAsync(const std::string& request);
  void send_sendRawRequestAsync(const std::string& request);
  int64_t recv_sendRawRequestAsync();
   ::Uts::EudPeripheralType::type GetEudPeripheralType(const int64_t protocolHandle);
  void send_GetEudPeripheralType(const int64_t protocolHandle);
   ::Uts::EudPeripheralType::type recv_GetEudPeripheralType();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class EudServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<EudServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (EudServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_initializeServiceByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_destroyService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendCommand(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendRawRequest(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_sendRawRequestAsync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_GetEudPeripheralType(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  EudServiceProcessor(::std::shared_ptr<EudServiceIf> iface) :
    iface_(iface) {
    processMap_["getLastError"] = &EudServiceProcessor::process_getLastError;
    processMap_["getDevice"] = &EudServiceProcessor::process_getDevice;
    processMap_["initializeService"] = &EudServiceProcessor::process_initializeService;
    processMap_["initializeServiceByProtocol"] = &EudServiceProcessor::process_initializeServiceByProtocol;
    processMap_["destroyService"] = &EudServiceProcessor::process_destroyService;
    processMap_["sendCommand"] = &EudServiceProcessor::process_sendCommand;
    processMap_["sendRawRequest"] = &EudServiceProcessor::process_sendRawRequest;
    processMap_["sendRawRequestAsync"] = &EudServiceProcessor::process_sendRawRequestAsync;
    processMap_["GetEudPeripheralType"] = &EudServiceProcessor::process_GetEudPeripheralType;
  }

  virtual ~EudServiceProcessor() {}
};

class EudServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  EudServiceProcessorFactory(const ::std::shared_ptr< EudServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< EudServiceIfFactory > handlerFactory_;
};

class EudServiceMultiface : virtual public EudServiceIf {
 public:
  EudServiceMultiface(std::vector<std::shared_ptr<EudServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~EudServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<EudServiceIf> > ifaces_;
  EudServiceMultiface() {}
  void add(::std::shared_ptr<EudServiceIf> iface) {
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

   ::Uts::ErrorCode::type destroyService() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->destroyService();
    }
    return ifaces_[i]->destroyService();
  }

  void sendCommand(const EudCmdInfo& eudCmdInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->sendCommand(eudCmdInfo);
    }
    ifaces_[i]->sendCommand(eudCmdInfo);
  }

  void sendRawRequest( ::Uts::EudPacket& _return, const std::string& request, const  ::Uts::EudReturnConfig& returnConfig, const int32_t timeout) {
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

   ::Uts::EudPeripheralType::type GetEudPeripheralType(const int64_t protocolHandle) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetEudPeripheralType(protocolHandle);
    }
    return ifaces_[i]->GetEudPeripheralType(protocolHandle);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class EudServiceConcurrentClient : virtual public EudServiceIf {
 public:
  EudServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  EudServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
   ::Uts::ErrorCode::type destroyService();
  int32_t send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService(const int32_t seqid);
  void sendCommand(const EudCmdInfo& eudCmdInfo);
  int32_t send_sendCommand(const EudCmdInfo& eudCmdInfo);
  void recv_sendCommand(const int32_t seqid);
  void sendRawRequest( ::Uts::EudPacket& _return, const std::string& request, const  ::Uts::EudReturnConfig& returnConfig, const int32_t timeout);
  int32_t send_sendRawRequest(const std::string& request, const  ::Uts::EudReturnConfig& returnConfig, const int32_t timeout);
  void recv_sendRawRequest( ::Uts::EudPacket& _return, const int32_t seqid);
  int64_t sendRawRequestAsync(const std::string& request);
  int32_t send_sendRawRequestAsync(const std::string& request);
  int64_t recv_sendRawRequestAsync(const int32_t seqid);
   ::Uts::EudPeripheralType::type GetEudPeripheralType(const int64_t protocolHandle);
  int32_t send_GetEudPeripheralType(const int64_t protocolHandle);
   ::Uts::EudPeripheralType::type recv_GetEudPeripheralType(const int32_t seqid);
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
