/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudCtlService_H
#define EudCtlService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "EudCtlService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class EudCtlServiceIf {
 public:
  virtual ~EudCtlServiceIf() {}
  virtual  ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type destroyService() = 0;
  virtual  ::Uts::ErrorCode::type enableSwd() = 0;
  virtual  ::Uts::ErrorCode::type disableSwd() = 0;
  virtual  ::Uts::ErrorCode::type spoofAttach() = 0;
  virtual  ::Uts::ErrorCode::type spoofDetach() = 0;
  virtual  ::Uts::ErrorCode::type rebootSoc() = 0;
};

class EudCtlServiceIfFactory {
 public:
  typedef EudCtlServiceIf Handler;

  virtual ~EudCtlServiceIfFactory() {}

  virtual EudCtlServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(EudCtlServiceIf* /* handler */) = 0;
};

class EudCtlServiceIfSingletonFactory : virtual public EudCtlServiceIfFactory {
 public:
  EudCtlServiceIfSingletonFactory(const ::std::shared_ptr<EudCtlServiceIf>& iface) : iface_(iface) {}
  virtual ~EudCtlServiceIfSingletonFactory() {}

  virtual EudCtlServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(EudCtlServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<EudCtlServiceIf> iface_;
};

class EudCtlServiceNull : virtual public EudCtlServiceIf {
 public:
  virtual ~EudCtlServiceNull() {}
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t /* protocolHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type destroyService() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type enableSwd() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type disableSwd() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type spoofAttach() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type spoofDetach() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type rebootSoc() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
};

typedef struct _EudCtlService_initializeServiceByProtocol_args__isset {
  _EudCtlService_initializeServiceByProtocol_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _EudCtlService_initializeServiceByProtocol_args__isset;

class EudCtlService_initializeServiceByProtocol_args {
 public:

  EudCtlService_initializeServiceByProtocol_args(const EudCtlService_initializeServiceByProtocol_args&);
  EudCtlService_initializeServiceByProtocol_args& operator=(const EudCtlService_initializeServiceByProtocol_args&);
  EudCtlService_initializeServiceByProtocol_args() : protocolHandle(0) {
  }

  virtual ~EudCtlService_initializeServiceByProtocol_args() noexcept;
  int64_t protocolHandle;

  _EudCtlService_initializeServiceByProtocol_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const EudCtlService_initializeServiceByProtocol_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const EudCtlService_initializeServiceByProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_initializeServiceByProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudCtlService_initializeServiceByProtocol_pargs {
 public:


  virtual ~EudCtlService_initializeServiceByProtocol_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_initializeServiceByProtocol_result__isset {
  _EudCtlService_initializeServiceByProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_initializeServiceByProtocol_result__isset;

class EudCtlService_initializeServiceByProtocol_result {
 public:

  EudCtlService_initializeServiceByProtocol_result(const EudCtlService_initializeServiceByProtocol_result&);
  EudCtlService_initializeServiceByProtocol_result& operator=(const EudCtlService_initializeServiceByProtocol_result&);
  EudCtlService_initializeServiceByProtocol_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudCtlService_initializeServiceByProtocol_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudCtlService_initializeServiceByProtocol_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudCtlService_initializeServiceByProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudCtlService_initializeServiceByProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_initializeServiceByProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_initializeServiceByProtocol_presult__isset {
  _EudCtlService_initializeServiceByProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_initializeServiceByProtocol_presult__isset;

class EudCtlService_initializeServiceByProtocol_presult {
 public:


  virtual ~EudCtlService_initializeServiceByProtocol_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudCtlService_initializeServiceByProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudCtlService_destroyService_args {
 public:

  EudCtlService_destroyService_args(const EudCtlService_destroyService_args&);
  EudCtlService_destroyService_args& operator=(const EudCtlService_destroyService_args&);
  EudCtlService_destroyService_args() {
  }

  virtual ~EudCtlService_destroyService_args() noexcept;

  bool operator == (const EudCtlService_destroyService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudCtlService_destroyService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_destroyService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudCtlService_destroyService_pargs {
 public:


  virtual ~EudCtlService_destroyService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_destroyService_result__isset {
  _EudCtlService_destroyService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_destroyService_result__isset;

class EudCtlService_destroyService_result {
 public:

  EudCtlService_destroyService_result(const EudCtlService_destroyService_result&);
  EudCtlService_destroyService_result& operator=(const EudCtlService_destroyService_result&);
  EudCtlService_destroyService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudCtlService_destroyService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudCtlService_destroyService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudCtlService_destroyService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudCtlService_destroyService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_destroyService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_destroyService_presult__isset {
  _EudCtlService_destroyService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_destroyService_presult__isset;

class EudCtlService_destroyService_presult {
 public:


  virtual ~EudCtlService_destroyService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudCtlService_destroyService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudCtlService_enableSwd_args {
 public:

  EudCtlService_enableSwd_args(const EudCtlService_enableSwd_args&);
  EudCtlService_enableSwd_args& operator=(const EudCtlService_enableSwd_args&);
  EudCtlService_enableSwd_args() {
  }

  virtual ~EudCtlService_enableSwd_args() noexcept;

  bool operator == (const EudCtlService_enableSwd_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudCtlService_enableSwd_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_enableSwd_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudCtlService_enableSwd_pargs {
 public:


  virtual ~EudCtlService_enableSwd_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_enableSwd_result__isset {
  _EudCtlService_enableSwd_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_enableSwd_result__isset;

class EudCtlService_enableSwd_result {
 public:

  EudCtlService_enableSwd_result(const EudCtlService_enableSwd_result&);
  EudCtlService_enableSwd_result& operator=(const EudCtlService_enableSwd_result&);
  EudCtlService_enableSwd_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudCtlService_enableSwd_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudCtlService_enableSwd_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudCtlService_enableSwd_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudCtlService_enableSwd_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_enableSwd_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_enableSwd_presult__isset {
  _EudCtlService_enableSwd_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_enableSwd_presult__isset;

class EudCtlService_enableSwd_presult {
 public:


  virtual ~EudCtlService_enableSwd_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudCtlService_enableSwd_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudCtlService_disableSwd_args {
 public:

  EudCtlService_disableSwd_args(const EudCtlService_disableSwd_args&);
  EudCtlService_disableSwd_args& operator=(const EudCtlService_disableSwd_args&);
  EudCtlService_disableSwd_args() {
  }

  virtual ~EudCtlService_disableSwd_args() noexcept;

  bool operator == (const EudCtlService_disableSwd_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudCtlService_disableSwd_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_disableSwd_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudCtlService_disableSwd_pargs {
 public:


  virtual ~EudCtlService_disableSwd_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_disableSwd_result__isset {
  _EudCtlService_disableSwd_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_disableSwd_result__isset;

class EudCtlService_disableSwd_result {
 public:

  EudCtlService_disableSwd_result(const EudCtlService_disableSwd_result&);
  EudCtlService_disableSwd_result& operator=(const EudCtlService_disableSwd_result&);
  EudCtlService_disableSwd_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudCtlService_disableSwd_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudCtlService_disableSwd_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudCtlService_disableSwd_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudCtlService_disableSwd_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_disableSwd_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_disableSwd_presult__isset {
  _EudCtlService_disableSwd_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_disableSwd_presult__isset;

class EudCtlService_disableSwd_presult {
 public:


  virtual ~EudCtlService_disableSwd_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudCtlService_disableSwd_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudCtlService_spoofAttach_args {
 public:

  EudCtlService_spoofAttach_args(const EudCtlService_spoofAttach_args&);
  EudCtlService_spoofAttach_args& operator=(const EudCtlService_spoofAttach_args&);
  EudCtlService_spoofAttach_args() {
  }

  virtual ~EudCtlService_spoofAttach_args() noexcept;

  bool operator == (const EudCtlService_spoofAttach_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudCtlService_spoofAttach_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_spoofAttach_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudCtlService_spoofAttach_pargs {
 public:


  virtual ~EudCtlService_spoofAttach_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_spoofAttach_result__isset {
  _EudCtlService_spoofAttach_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_spoofAttach_result__isset;

class EudCtlService_spoofAttach_result {
 public:

  EudCtlService_spoofAttach_result(const EudCtlService_spoofAttach_result&);
  EudCtlService_spoofAttach_result& operator=(const EudCtlService_spoofAttach_result&);
  EudCtlService_spoofAttach_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudCtlService_spoofAttach_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudCtlService_spoofAttach_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudCtlService_spoofAttach_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudCtlService_spoofAttach_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_spoofAttach_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_spoofAttach_presult__isset {
  _EudCtlService_spoofAttach_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_spoofAttach_presult__isset;

class EudCtlService_spoofAttach_presult {
 public:


  virtual ~EudCtlService_spoofAttach_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudCtlService_spoofAttach_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudCtlService_spoofDetach_args {
 public:

  EudCtlService_spoofDetach_args(const EudCtlService_spoofDetach_args&);
  EudCtlService_spoofDetach_args& operator=(const EudCtlService_spoofDetach_args&);
  EudCtlService_spoofDetach_args() {
  }

  virtual ~EudCtlService_spoofDetach_args() noexcept;

  bool operator == (const EudCtlService_spoofDetach_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudCtlService_spoofDetach_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_spoofDetach_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudCtlService_spoofDetach_pargs {
 public:


  virtual ~EudCtlService_spoofDetach_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_spoofDetach_result__isset {
  _EudCtlService_spoofDetach_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_spoofDetach_result__isset;

class EudCtlService_spoofDetach_result {
 public:

  EudCtlService_spoofDetach_result(const EudCtlService_spoofDetach_result&);
  EudCtlService_spoofDetach_result& operator=(const EudCtlService_spoofDetach_result&);
  EudCtlService_spoofDetach_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudCtlService_spoofDetach_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudCtlService_spoofDetach_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudCtlService_spoofDetach_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudCtlService_spoofDetach_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_spoofDetach_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_spoofDetach_presult__isset {
  _EudCtlService_spoofDetach_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_spoofDetach_presult__isset;

class EudCtlService_spoofDetach_presult {
 public:


  virtual ~EudCtlService_spoofDetach_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudCtlService_spoofDetach_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudCtlService_rebootSoc_args {
 public:

  EudCtlService_rebootSoc_args(const EudCtlService_rebootSoc_args&);
  EudCtlService_rebootSoc_args& operator=(const EudCtlService_rebootSoc_args&);
  EudCtlService_rebootSoc_args() {
  }

  virtual ~EudCtlService_rebootSoc_args() noexcept;

  bool operator == (const EudCtlService_rebootSoc_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudCtlService_rebootSoc_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_rebootSoc_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudCtlService_rebootSoc_pargs {
 public:


  virtual ~EudCtlService_rebootSoc_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_rebootSoc_result__isset {
  _EudCtlService_rebootSoc_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_rebootSoc_result__isset;

class EudCtlService_rebootSoc_result {
 public:

  EudCtlService_rebootSoc_result(const EudCtlService_rebootSoc_result&);
  EudCtlService_rebootSoc_result& operator=(const EudCtlService_rebootSoc_result&);
  EudCtlService_rebootSoc_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudCtlService_rebootSoc_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudCtlService_rebootSoc_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudCtlService_rebootSoc_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudCtlService_rebootSoc_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCtlService_rebootSoc_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudCtlService_rebootSoc_presult__isset {
  _EudCtlService_rebootSoc_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudCtlService_rebootSoc_presult__isset;

class EudCtlService_rebootSoc_presult {
 public:


  virtual ~EudCtlService_rebootSoc_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudCtlService_rebootSoc_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class EudCtlServiceClient : virtual public EudCtlServiceIf {
 public:
  EudCtlServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  EudCtlServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle);
  void send_initializeServiceByProtocol(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_initializeServiceByProtocol();
   ::Uts::ErrorCode::type destroyService();
  void send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService();
   ::Uts::ErrorCode::type enableSwd();
  void send_enableSwd();
   ::Uts::ErrorCode::type recv_enableSwd();
   ::Uts::ErrorCode::type disableSwd();
  void send_disableSwd();
   ::Uts::ErrorCode::type recv_disableSwd();
   ::Uts::ErrorCode::type spoofAttach();
  void send_spoofAttach();
   ::Uts::ErrorCode::type recv_spoofAttach();
   ::Uts::ErrorCode::type spoofDetach();
  void send_spoofDetach();
   ::Uts::ErrorCode::type recv_spoofDetach();
   ::Uts::ErrorCode::type rebootSoc();
  void send_rebootSoc();
   ::Uts::ErrorCode::type recv_rebootSoc();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class EudCtlServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<EudCtlServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (EudCtlServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_initializeServiceByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_destroyService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_enableSwd(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_disableSwd(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_spoofAttach(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_spoofDetach(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_rebootSoc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  EudCtlServiceProcessor(::std::shared_ptr<EudCtlServiceIf> iface) :
    iface_(iface) {
    processMap_["initializeServiceByProtocol"] = &EudCtlServiceProcessor::process_initializeServiceByProtocol;
    processMap_["destroyService"] = &EudCtlServiceProcessor::process_destroyService;
    processMap_["enableSwd"] = &EudCtlServiceProcessor::process_enableSwd;
    processMap_["disableSwd"] = &EudCtlServiceProcessor::process_disableSwd;
    processMap_["spoofAttach"] = &EudCtlServiceProcessor::process_spoofAttach;
    processMap_["spoofDetach"] = &EudCtlServiceProcessor::process_spoofDetach;
    processMap_["rebootSoc"] = &EudCtlServiceProcessor::process_rebootSoc;
  }

  virtual ~EudCtlServiceProcessor() {}
};

class EudCtlServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  EudCtlServiceProcessorFactory(const ::std::shared_ptr< EudCtlServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< EudCtlServiceIfFactory > handlerFactory_;
};

class EudCtlServiceMultiface : virtual public EudCtlServiceIf {
 public:
  EudCtlServiceMultiface(std::vector<std::shared_ptr<EudCtlServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~EudCtlServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<EudCtlServiceIf> > ifaces_;
  EudCtlServiceMultiface() {}
  void add(::std::shared_ptr<EudCtlServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
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

   ::Uts::ErrorCode::type enableSwd() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->enableSwd();
    }
    return ifaces_[i]->enableSwd();
  }

   ::Uts::ErrorCode::type disableSwd() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->disableSwd();
    }
    return ifaces_[i]->disableSwd();
  }

   ::Uts::ErrorCode::type spoofAttach() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->spoofAttach();
    }
    return ifaces_[i]->spoofAttach();
  }

   ::Uts::ErrorCode::type spoofDetach() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->spoofDetach();
    }
    return ifaces_[i]->spoofDetach();
  }

   ::Uts::ErrorCode::type rebootSoc() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->rebootSoc();
    }
    return ifaces_[i]->rebootSoc();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class EudCtlServiceConcurrentClient : virtual public EudCtlServiceIf {
 public:
  EudCtlServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  EudCtlServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle);
  int32_t send_initializeServiceByProtocol(const int64_t protocolHandle);
   ::Uts::ErrorCode::type recv_initializeServiceByProtocol(const int32_t seqid);
   ::Uts::ErrorCode::type destroyService();
  int32_t send_destroyService();
   ::Uts::ErrorCode::type recv_destroyService(const int32_t seqid);
   ::Uts::ErrorCode::type enableSwd();
  int32_t send_enableSwd();
   ::Uts::ErrorCode::type recv_enableSwd(const int32_t seqid);
   ::Uts::ErrorCode::type disableSwd();
  int32_t send_disableSwd();
   ::Uts::ErrorCode::type recv_disableSwd(const int32_t seqid);
   ::Uts::ErrorCode::type spoofAttach();
  int32_t send_spoofAttach();
   ::Uts::ErrorCode::type recv_spoofAttach(const int32_t seqid);
   ::Uts::ErrorCode::type spoofDetach();
  int32_t send_spoofDetach();
   ::Uts::ErrorCode::type recv_spoofDetach(const int32_t seqid);
   ::Uts::ErrorCode::type rebootSoc();
  int32_t send_rebootSoc();
   ::Uts::ErrorCode::type recv_rebootSoc(const int32_t seqid);
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
