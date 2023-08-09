/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudSwdService_H
#define EudSwdService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "EudSwdService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class EudSwdServiceIf {
 public:
  virtual ~EudSwdServiceIf() {}
  virtual  ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t protocolHandle) = 0;
  virtual  ::Uts::ErrorCode::type destroyService() = 0;
  virtual  ::Uts::ErrorCode::type writeRegister(const int32_t startAddress, const std::vector<int32_t> & data, const int32_t ap) = 0;
  virtual void readRegister(std::vector<int32_t> & _return, const int32_t startAddress, const int32_t numBytes, const int32_t ap) = 0;
  virtual int32_t InitSWD(const int32_t dummy) = 0;
  virtual void swdRead_wrapper(BfrTckr& _return, const int32_t apndp, const int32_t A2_3) = 0;
  virtual void swdWrite(BfrTckr& _return, const int32_t APnDP, const int32_t address2To3, const int64_t senddata) = 0;
  virtual void SWDBitbang(std::vector<int32_t> & _return, const int32_t SWDBitValues) = 0;
  virtual void Jtag_to_SWD() = 0;
  virtual void swdFlush(BfrTckr& _return) = 0;
};

class EudSwdServiceIfFactory {
 public:
  typedef EudSwdServiceIf Handler;

  virtual ~EudSwdServiceIfFactory() {}

  virtual EudSwdServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(EudSwdServiceIf* /* handler */) = 0;
};

class EudSwdServiceIfSingletonFactory : virtual public EudSwdServiceIfFactory {
 public:
  EudSwdServiceIfSingletonFactory(const ::std::shared_ptr<EudSwdServiceIf>& iface) : iface_(iface) {}
  virtual ~EudSwdServiceIfSingletonFactory() {}

  virtual EudSwdServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(EudSwdServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<EudSwdServiceIf> iface_;
};

class EudSwdServiceNull : virtual public EudSwdServiceIf {
 public:
  virtual ~EudSwdServiceNull() {}
   ::Uts::ErrorCode::type initializeServiceByProtocol(const int64_t /* protocolHandle */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type destroyService() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type writeRegister(const int32_t /* startAddress */, const std::vector<int32_t> & /* data */, const int32_t /* ap */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void readRegister(std::vector<int32_t> & /* _return */, const int32_t /* startAddress */, const int32_t /* numBytes */, const int32_t /* ap */) {
    return;
  }
  int32_t InitSWD(const int32_t /* dummy */) {
    int32_t _return = 0;
    return _return;
  }
  void swdRead_wrapper(BfrTckr& /* _return */, const int32_t /* apndp */, const int32_t /* A2_3 */) {
    return;
  }
  void swdWrite(BfrTckr& /* _return */, const int32_t /* APnDP */, const int32_t /* address2To3 */, const int64_t /* senddata */) {
    return;
  }
  void SWDBitbang(std::vector<int32_t> & /* _return */, const int32_t /* SWDBitValues */) {
    return;
  }
  void Jtag_to_SWD() {
    return;
  }
  void swdFlush(BfrTckr& /* _return */) {
    return;
  }
};

typedef struct _EudSwdService_initializeServiceByProtocol_args__isset {
  _EudSwdService_initializeServiceByProtocol_args__isset() : protocolHandle(false) {}
  bool protocolHandle :1;
} _EudSwdService_initializeServiceByProtocol_args__isset;

class EudSwdService_initializeServiceByProtocol_args {
 public:

  EudSwdService_initializeServiceByProtocol_args(const EudSwdService_initializeServiceByProtocol_args&);
  EudSwdService_initializeServiceByProtocol_args& operator=(const EudSwdService_initializeServiceByProtocol_args&);
  EudSwdService_initializeServiceByProtocol_args() : protocolHandle(0) {
  }

  virtual ~EudSwdService_initializeServiceByProtocol_args() noexcept;
  int64_t protocolHandle;

  _EudSwdService_initializeServiceByProtocol_args__isset __isset;

  void __set_protocolHandle(const int64_t val);

  bool operator == (const EudSwdService_initializeServiceByProtocol_args & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_initializeServiceByProtocol_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_initializeServiceByProtocol_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_initializeServiceByProtocol_pargs {
 public:


  virtual ~EudSwdService_initializeServiceByProtocol_pargs() noexcept;
  const int64_t* protocolHandle;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_initializeServiceByProtocol_result__isset {
  _EudSwdService_initializeServiceByProtocol_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudSwdService_initializeServiceByProtocol_result__isset;

class EudSwdService_initializeServiceByProtocol_result {
 public:

  EudSwdService_initializeServiceByProtocol_result(const EudSwdService_initializeServiceByProtocol_result&);
  EudSwdService_initializeServiceByProtocol_result& operator=(const EudSwdService_initializeServiceByProtocol_result&);
  EudSwdService_initializeServiceByProtocol_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudSwdService_initializeServiceByProtocol_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudSwdService_initializeServiceByProtocol_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudSwdService_initializeServiceByProtocol_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_initializeServiceByProtocol_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_initializeServiceByProtocol_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_initializeServiceByProtocol_presult__isset {
  _EudSwdService_initializeServiceByProtocol_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudSwdService_initializeServiceByProtocol_presult__isset;

class EudSwdService_initializeServiceByProtocol_presult {
 public:


  virtual ~EudSwdService_initializeServiceByProtocol_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudSwdService_initializeServiceByProtocol_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudSwdService_destroyService_args {
 public:

  EudSwdService_destroyService_args(const EudSwdService_destroyService_args&);
  EudSwdService_destroyService_args& operator=(const EudSwdService_destroyService_args&);
  EudSwdService_destroyService_args() {
  }

  virtual ~EudSwdService_destroyService_args() noexcept;

  bool operator == (const EudSwdService_destroyService_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudSwdService_destroyService_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_destroyService_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_destroyService_pargs {
 public:


  virtual ~EudSwdService_destroyService_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_destroyService_result__isset {
  _EudSwdService_destroyService_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudSwdService_destroyService_result__isset;

class EudSwdService_destroyService_result {
 public:

  EudSwdService_destroyService_result(const EudSwdService_destroyService_result&);
  EudSwdService_destroyService_result& operator=(const EudSwdService_destroyService_result&);
  EudSwdService_destroyService_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudSwdService_destroyService_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudSwdService_destroyService_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudSwdService_destroyService_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_destroyService_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_destroyService_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_destroyService_presult__isset {
  _EudSwdService_destroyService_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudSwdService_destroyService_presult__isset;

class EudSwdService_destroyService_presult {
 public:


  virtual ~EudSwdService_destroyService_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudSwdService_destroyService_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudSwdService_writeRegister_args__isset {
  _EudSwdService_writeRegister_args__isset() : startAddress(false), data(false), ap(false) {}
  bool startAddress :1;
  bool data :1;
  bool ap :1;
} _EudSwdService_writeRegister_args__isset;

class EudSwdService_writeRegister_args {
 public:

  EudSwdService_writeRegister_args(const EudSwdService_writeRegister_args&);
  EudSwdService_writeRegister_args& operator=(const EudSwdService_writeRegister_args&);
  EudSwdService_writeRegister_args() : startAddress(0), ap(0) {
  }

  virtual ~EudSwdService_writeRegister_args() noexcept;
  int32_t startAddress;
  std::vector<int32_t>  data;
  int32_t ap;

  _EudSwdService_writeRegister_args__isset __isset;

  void __set_startAddress(const int32_t val);

  void __set_data(const std::vector<int32_t> & val);

  void __set_ap(const int32_t val);

  bool operator == (const EudSwdService_writeRegister_args & rhs) const
  {
    if (!(startAddress == rhs.startAddress))
      return false;
    if (!(data == rhs.data))
      return false;
    if (!(ap == rhs.ap))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_writeRegister_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_writeRegister_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_writeRegister_pargs {
 public:


  virtual ~EudSwdService_writeRegister_pargs() noexcept;
  const int32_t* startAddress;
  const std::vector<int32_t> * data;
  const int32_t* ap;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_writeRegister_result__isset {
  _EudSwdService_writeRegister_result__isset() : success(false) {}
  bool success :1;
} _EudSwdService_writeRegister_result__isset;

class EudSwdService_writeRegister_result {
 public:

  EudSwdService_writeRegister_result(const EudSwdService_writeRegister_result&);
  EudSwdService_writeRegister_result& operator=(const EudSwdService_writeRegister_result&);
  EudSwdService_writeRegister_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudSwdService_writeRegister_result() noexcept;
   ::Uts::ErrorCode::type success;

  _EudSwdService_writeRegister_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  bool operator == (const EudSwdService_writeRegister_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_writeRegister_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_writeRegister_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_writeRegister_presult__isset {
  _EudSwdService_writeRegister_presult__isset() : success(false) {}
  bool success :1;
} _EudSwdService_writeRegister_presult__isset;

class EudSwdService_writeRegister_presult {
 public:


  virtual ~EudSwdService_writeRegister_presult() noexcept;
   ::Uts::ErrorCode::type* success;

  _EudSwdService_writeRegister_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudSwdService_readRegister_args__isset {
  _EudSwdService_readRegister_args__isset() : startAddress(false), numBytes(false), ap(false) {}
  bool startAddress :1;
  bool numBytes :1;
  bool ap :1;
} _EudSwdService_readRegister_args__isset;

class EudSwdService_readRegister_args {
 public:

  EudSwdService_readRegister_args(const EudSwdService_readRegister_args&);
  EudSwdService_readRegister_args& operator=(const EudSwdService_readRegister_args&);
  EudSwdService_readRegister_args() : startAddress(0), numBytes(0), ap(0) {
  }

  virtual ~EudSwdService_readRegister_args() noexcept;
  int32_t startAddress;
  int32_t numBytes;
  int32_t ap;

  _EudSwdService_readRegister_args__isset __isset;

  void __set_startAddress(const int32_t val);

  void __set_numBytes(const int32_t val);

  void __set_ap(const int32_t val);

  bool operator == (const EudSwdService_readRegister_args & rhs) const
  {
    if (!(startAddress == rhs.startAddress))
      return false;
    if (!(numBytes == rhs.numBytes))
      return false;
    if (!(ap == rhs.ap))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_readRegister_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_readRegister_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_readRegister_pargs {
 public:


  virtual ~EudSwdService_readRegister_pargs() noexcept;
  const int32_t* startAddress;
  const int32_t* numBytes;
  const int32_t* ap;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_readRegister_result__isset {
  _EudSwdService_readRegister_result__isset() : success(false) {}
  bool success :1;
} _EudSwdService_readRegister_result__isset;

class EudSwdService_readRegister_result {
 public:

  EudSwdService_readRegister_result(const EudSwdService_readRegister_result&);
  EudSwdService_readRegister_result& operator=(const EudSwdService_readRegister_result&);
  EudSwdService_readRegister_result() {
  }

  virtual ~EudSwdService_readRegister_result() noexcept;
  std::vector<int32_t>  success;

  _EudSwdService_readRegister_result__isset __isset;

  void __set_success(const std::vector<int32_t> & val);

  bool operator == (const EudSwdService_readRegister_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_readRegister_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_readRegister_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_readRegister_presult__isset {
  _EudSwdService_readRegister_presult__isset() : success(false) {}
  bool success :1;
} _EudSwdService_readRegister_presult__isset;

class EudSwdService_readRegister_presult {
 public:


  virtual ~EudSwdService_readRegister_presult() noexcept;
  std::vector<int32_t> * success;

  _EudSwdService_readRegister_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudSwdService_InitSWD_args__isset {
  _EudSwdService_InitSWD_args__isset() : dummy(false) {}
  bool dummy :1;
} _EudSwdService_InitSWD_args__isset;

class EudSwdService_InitSWD_args {
 public:

  EudSwdService_InitSWD_args(const EudSwdService_InitSWD_args&);
  EudSwdService_InitSWD_args& operator=(const EudSwdService_InitSWD_args&);
  EudSwdService_InitSWD_args() : dummy(0) {
  }

  virtual ~EudSwdService_InitSWD_args() noexcept;
  int32_t dummy;

  _EudSwdService_InitSWD_args__isset __isset;

  void __set_dummy(const int32_t val);

  bool operator == (const EudSwdService_InitSWD_args & rhs) const
  {
    if (!(dummy == rhs.dummy))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_InitSWD_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_InitSWD_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_InitSWD_pargs {
 public:


  virtual ~EudSwdService_InitSWD_pargs() noexcept;
  const int32_t* dummy;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_InitSWD_result__isset {
  _EudSwdService_InitSWD_result__isset() : success(false) {}
  bool success :1;
} _EudSwdService_InitSWD_result__isset;

class EudSwdService_InitSWD_result {
 public:

  EudSwdService_InitSWD_result(const EudSwdService_InitSWD_result&);
  EudSwdService_InitSWD_result& operator=(const EudSwdService_InitSWD_result&);
  EudSwdService_InitSWD_result() : success(0) {
  }

  virtual ~EudSwdService_InitSWD_result() noexcept;
  int32_t success;

  _EudSwdService_InitSWD_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const EudSwdService_InitSWD_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_InitSWD_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_InitSWD_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_InitSWD_presult__isset {
  _EudSwdService_InitSWD_presult__isset() : success(false) {}
  bool success :1;
} _EudSwdService_InitSWD_presult__isset;

class EudSwdService_InitSWD_presult {
 public:


  virtual ~EudSwdService_InitSWD_presult() noexcept;
  int32_t* success;

  _EudSwdService_InitSWD_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudSwdService_swdRead_wrapper_args__isset {
  _EudSwdService_swdRead_wrapper_args__isset() : apndp(false), A2_3(false) {}
  bool apndp :1;
  bool A2_3 :1;
} _EudSwdService_swdRead_wrapper_args__isset;

class EudSwdService_swdRead_wrapper_args {
 public:

  EudSwdService_swdRead_wrapper_args(const EudSwdService_swdRead_wrapper_args&);
  EudSwdService_swdRead_wrapper_args& operator=(const EudSwdService_swdRead_wrapper_args&);
  EudSwdService_swdRead_wrapper_args() : apndp(0), A2_3(0) {
  }

  virtual ~EudSwdService_swdRead_wrapper_args() noexcept;
  int32_t apndp;
  int32_t A2_3;

  _EudSwdService_swdRead_wrapper_args__isset __isset;

  void __set_apndp(const int32_t val);

  void __set_A2_3(const int32_t val);

  bool operator == (const EudSwdService_swdRead_wrapper_args & rhs) const
  {
    if (!(apndp == rhs.apndp))
      return false;
    if (!(A2_3 == rhs.A2_3))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_swdRead_wrapper_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_swdRead_wrapper_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_swdRead_wrapper_pargs {
 public:


  virtual ~EudSwdService_swdRead_wrapper_pargs() noexcept;
  const int32_t* apndp;
  const int32_t* A2_3;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_swdRead_wrapper_result__isset {
  _EudSwdService_swdRead_wrapper_result__isset() : success(false) {}
  bool success :1;
} _EudSwdService_swdRead_wrapper_result__isset;

class EudSwdService_swdRead_wrapper_result {
 public:

  EudSwdService_swdRead_wrapper_result(const EudSwdService_swdRead_wrapper_result&);
  EudSwdService_swdRead_wrapper_result& operator=(const EudSwdService_swdRead_wrapper_result&);
  EudSwdService_swdRead_wrapper_result() {
  }

  virtual ~EudSwdService_swdRead_wrapper_result() noexcept;
  BfrTckr success;

  _EudSwdService_swdRead_wrapper_result__isset __isset;

  void __set_success(const BfrTckr& val);

  bool operator == (const EudSwdService_swdRead_wrapper_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_swdRead_wrapper_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_swdRead_wrapper_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_swdRead_wrapper_presult__isset {
  _EudSwdService_swdRead_wrapper_presult__isset() : success(false) {}
  bool success :1;
} _EudSwdService_swdRead_wrapper_presult__isset;

class EudSwdService_swdRead_wrapper_presult {
 public:


  virtual ~EudSwdService_swdRead_wrapper_presult() noexcept;
  BfrTckr* success;

  _EudSwdService_swdRead_wrapper_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudSwdService_swdWrite_args__isset {
  _EudSwdService_swdWrite_args__isset() : APnDP(false), address2To3(false), senddata(false) {}
  bool APnDP :1;
  bool address2To3 :1;
  bool senddata :1;
} _EudSwdService_swdWrite_args__isset;

class EudSwdService_swdWrite_args {
 public:

  EudSwdService_swdWrite_args(const EudSwdService_swdWrite_args&);
  EudSwdService_swdWrite_args& operator=(const EudSwdService_swdWrite_args&);
  EudSwdService_swdWrite_args() : APnDP(0), address2To3(0), senddata(0) {
  }

  virtual ~EudSwdService_swdWrite_args() noexcept;
  int32_t APnDP;
  int32_t address2To3;
  int64_t senddata;

  _EudSwdService_swdWrite_args__isset __isset;

  void __set_APnDP(const int32_t val);

  void __set_address2To3(const int32_t val);

  void __set_senddata(const int64_t val);

  bool operator == (const EudSwdService_swdWrite_args & rhs) const
  {
    if (!(APnDP == rhs.APnDP))
      return false;
    if (!(address2To3 == rhs.address2To3))
      return false;
    if (!(senddata == rhs.senddata))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_swdWrite_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_swdWrite_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_swdWrite_pargs {
 public:


  virtual ~EudSwdService_swdWrite_pargs() noexcept;
  const int32_t* APnDP;
  const int32_t* address2To3;
  const int64_t* senddata;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_swdWrite_result__isset {
  _EudSwdService_swdWrite_result__isset() : success(false) {}
  bool success :1;
} _EudSwdService_swdWrite_result__isset;

class EudSwdService_swdWrite_result {
 public:

  EudSwdService_swdWrite_result(const EudSwdService_swdWrite_result&);
  EudSwdService_swdWrite_result& operator=(const EudSwdService_swdWrite_result&);
  EudSwdService_swdWrite_result() {
  }

  virtual ~EudSwdService_swdWrite_result() noexcept;
  BfrTckr success;

  _EudSwdService_swdWrite_result__isset __isset;

  void __set_success(const BfrTckr& val);

  bool operator == (const EudSwdService_swdWrite_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_swdWrite_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_swdWrite_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_swdWrite_presult__isset {
  _EudSwdService_swdWrite_presult__isset() : success(false) {}
  bool success :1;
} _EudSwdService_swdWrite_presult__isset;

class EudSwdService_swdWrite_presult {
 public:


  virtual ~EudSwdService_swdWrite_presult() noexcept;
  BfrTckr* success;

  _EudSwdService_swdWrite_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudSwdService_SWDBitbang_args__isset {
  _EudSwdService_SWDBitbang_args__isset() : SWDBitValues(false) {}
  bool SWDBitValues :1;
} _EudSwdService_SWDBitbang_args__isset;

class EudSwdService_SWDBitbang_args {
 public:

  EudSwdService_SWDBitbang_args(const EudSwdService_SWDBitbang_args&);
  EudSwdService_SWDBitbang_args& operator=(const EudSwdService_SWDBitbang_args&);
  EudSwdService_SWDBitbang_args() : SWDBitValues(0) {
  }

  virtual ~EudSwdService_SWDBitbang_args() noexcept;
  int32_t SWDBitValues;

  _EudSwdService_SWDBitbang_args__isset __isset;

  void __set_SWDBitValues(const int32_t val);

  bool operator == (const EudSwdService_SWDBitbang_args & rhs) const
  {
    if (!(SWDBitValues == rhs.SWDBitValues))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_SWDBitbang_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_SWDBitbang_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_SWDBitbang_pargs {
 public:


  virtual ~EudSwdService_SWDBitbang_pargs() noexcept;
  const int32_t* SWDBitValues;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_SWDBitbang_result__isset {
  _EudSwdService_SWDBitbang_result__isset() : success(false) {}
  bool success :1;
} _EudSwdService_SWDBitbang_result__isset;

class EudSwdService_SWDBitbang_result {
 public:

  EudSwdService_SWDBitbang_result(const EudSwdService_SWDBitbang_result&);
  EudSwdService_SWDBitbang_result& operator=(const EudSwdService_SWDBitbang_result&);
  EudSwdService_SWDBitbang_result() {
  }

  virtual ~EudSwdService_SWDBitbang_result() noexcept;
  std::vector<int32_t>  success;

  _EudSwdService_SWDBitbang_result__isset __isset;

  void __set_success(const std::vector<int32_t> & val);

  bool operator == (const EudSwdService_SWDBitbang_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_SWDBitbang_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_SWDBitbang_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_SWDBitbang_presult__isset {
  _EudSwdService_SWDBitbang_presult__isset() : success(false) {}
  bool success :1;
} _EudSwdService_SWDBitbang_presult__isset;

class EudSwdService_SWDBitbang_presult {
 public:


  virtual ~EudSwdService_SWDBitbang_presult() noexcept;
  std::vector<int32_t> * success;

  _EudSwdService_SWDBitbang_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudSwdService_Jtag_to_SWD_args {
 public:

  EudSwdService_Jtag_to_SWD_args(const EudSwdService_Jtag_to_SWD_args&);
  EudSwdService_Jtag_to_SWD_args& operator=(const EudSwdService_Jtag_to_SWD_args&);
  EudSwdService_Jtag_to_SWD_args() {
  }

  virtual ~EudSwdService_Jtag_to_SWD_args() noexcept;

  bool operator == (const EudSwdService_Jtag_to_SWD_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudSwdService_Jtag_to_SWD_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_Jtag_to_SWD_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_Jtag_to_SWD_pargs {
 public:


  virtual ~EudSwdService_Jtag_to_SWD_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_Jtag_to_SWD_result {
 public:

  EudSwdService_Jtag_to_SWD_result(const EudSwdService_Jtag_to_SWD_result&);
  EudSwdService_Jtag_to_SWD_result& operator=(const EudSwdService_Jtag_to_SWD_result&);
  EudSwdService_Jtag_to_SWD_result() {
  }

  virtual ~EudSwdService_Jtag_to_SWD_result() noexcept;

  bool operator == (const EudSwdService_Jtag_to_SWD_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudSwdService_Jtag_to_SWD_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_Jtag_to_SWD_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_Jtag_to_SWD_presult {
 public:


  virtual ~EudSwdService_Jtag_to_SWD_presult() noexcept;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudSwdService_swdFlush_args {
 public:

  EudSwdService_swdFlush_args(const EudSwdService_swdFlush_args&);
  EudSwdService_swdFlush_args& operator=(const EudSwdService_swdFlush_args&);
  EudSwdService_swdFlush_args() {
  }

  virtual ~EudSwdService_swdFlush_args() noexcept;

  bool operator == (const EudSwdService_swdFlush_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudSwdService_swdFlush_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_swdFlush_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudSwdService_swdFlush_pargs {
 public:


  virtual ~EudSwdService_swdFlush_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_swdFlush_result__isset {
  _EudSwdService_swdFlush_result__isset() : success(false) {}
  bool success :1;
} _EudSwdService_swdFlush_result__isset;

class EudSwdService_swdFlush_result {
 public:

  EudSwdService_swdFlush_result(const EudSwdService_swdFlush_result&);
  EudSwdService_swdFlush_result& operator=(const EudSwdService_swdFlush_result&);
  EudSwdService_swdFlush_result() {
  }

  virtual ~EudSwdService_swdFlush_result() noexcept;
  BfrTckr success;

  _EudSwdService_swdFlush_result__isset __isset;

  void __set_success(const BfrTckr& val);

  bool operator == (const EudSwdService_swdFlush_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const EudSwdService_swdFlush_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudSwdService_swdFlush_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudSwdService_swdFlush_presult__isset {
  _EudSwdService_swdFlush_presult__isset() : success(false) {}
  bool success :1;
} _EudSwdService_swdFlush_presult__isset;

class EudSwdService_swdFlush_presult {
 public:


  virtual ~EudSwdService_swdFlush_presult() noexcept;
  BfrTckr* success;

  _EudSwdService_swdFlush_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class EudSwdServiceClient : virtual public EudSwdServiceIf {
 public:
  EudSwdServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  EudSwdServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
   ::Uts::ErrorCode::type writeRegister(const int32_t startAddress, const std::vector<int32_t> & data, const int32_t ap);
  void send_writeRegister(const int32_t startAddress, const std::vector<int32_t> & data, const int32_t ap);
   ::Uts::ErrorCode::type recv_writeRegister();
  void readRegister(std::vector<int32_t> & _return, const int32_t startAddress, const int32_t numBytes, const int32_t ap);
  void send_readRegister(const int32_t startAddress, const int32_t numBytes, const int32_t ap);
  void recv_readRegister(std::vector<int32_t> & _return);
  int32_t InitSWD(const int32_t dummy);
  void send_InitSWD(const int32_t dummy);
  int32_t recv_InitSWD();
  void swdRead_wrapper(BfrTckr& _return, const int32_t apndp, const int32_t A2_3);
  void send_swdRead_wrapper(const int32_t apndp, const int32_t A2_3);
  void recv_swdRead_wrapper(BfrTckr& _return);
  void swdWrite(BfrTckr& _return, const int32_t APnDP, const int32_t address2To3, const int64_t senddata);
  void send_swdWrite(const int32_t APnDP, const int32_t address2To3, const int64_t senddata);
  void recv_swdWrite(BfrTckr& _return);
  void SWDBitbang(std::vector<int32_t> & _return, const int32_t SWDBitValues);
  void send_SWDBitbang(const int32_t SWDBitValues);
  void recv_SWDBitbang(std::vector<int32_t> & _return);
  void Jtag_to_SWD();
  void send_Jtag_to_SWD();
  void recv_Jtag_to_SWD();
  void swdFlush(BfrTckr& _return);
  void send_swdFlush();
  void recv_swdFlush(BfrTckr& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class EudSwdServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<EudSwdServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (EudSwdServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_initializeServiceByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_destroyService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_writeRegister(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_readRegister(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_InitSWD(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_swdRead_wrapper(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_swdWrite(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_SWDBitbang(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_Jtag_to_SWD(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_swdFlush(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  EudSwdServiceProcessor(::std::shared_ptr<EudSwdServiceIf> iface) :
    iface_(iface) {
    processMap_["initializeServiceByProtocol"] = &EudSwdServiceProcessor::process_initializeServiceByProtocol;
    processMap_["destroyService"] = &EudSwdServiceProcessor::process_destroyService;
    processMap_["writeRegister"] = &EudSwdServiceProcessor::process_writeRegister;
    processMap_["readRegister"] = &EudSwdServiceProcessor::process_readRegister;
    processMap_["InitSWD"] = &EudSwdServiceProcessor::process_InitSWD;
    processMap_["swdRead_wrapper"] = &EudSwdServiceProcessor::process_swdRead_wrapper;
    processMap_["swdWrite"] = &EudSwdServiceProcessor::process_swdWrite;
    processMap_["SWDBitbang"] = &EudSwdServiceProcessor::process_SWDBitbang;
    processMap_["Jtag_to_SWD"] = &EudSwdServiceProcessor::process_Jtag_to_SWD;
    processMap_["swdFlush"] = &EudSwdServiceProcessor::process_swdFlush;
  }

  virtual ~EudSwdServiceProcessor() {}
};

class EudSwdServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  EudSwdServiceProcessorFactory(const ::std::shared_ptr< EudSwdServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< EudSwdServiceIfFactory > handlerFactory_;
};

class EudSwdServiceMultiface : virtual public EudSwdServiceIf {
 public:
  EudSwdServiceMultiface(std::vector<std::shared_ptr<EudSwdServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~EudSwdServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<EudSwdServiceIf> > ifaces_;
  EudSwdServiceMultiface() {}
  void add(::std::shared_ptr<EudSwdServiceIf> iface) {
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

   ::Uts::ErrorCode::type writeRegister(const int32_t startAddress, const std::vector<int32_t> & data, const int32_t ap) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->writeRegister(startAddress, data, ap);
    }
    return ifaces_[i]->writeRegister(startAddress, data, ap);
  }

  void readRegister(std::vector<int32_t> & _return, const int32_t startAddress, const int32_t numBytes, const int32_t ap) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->readRegister(_return, startAddress, numBytes, ap);
    }
    ifaces_[i]->readRegister(_return, startAddress, numBytes, ap);
    return;
  }

  int32_t InitSWD(const int32_t dummy) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->InitSWD(dummy);
    }
    return ifaces_[i]->InitSWD(dummy);
  }

  void swdRead_wrapper(BfrTckr& _return, const int32_t apndp, const int32_t A2_3) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->swdRead_wrapper(_return, apndp, A2_3);
    }
    ifaces_[i]->swdRead_wrapper(_return, apndp, A2_3);
    return;
  }

  void swdWrite(BfrTckr& _return, const int32_t APnDP, const int32_t address2To3, const int64_t senddata) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->swdWrite(_return, APnDP, address2To3, senddata);
    }
    ifaces_[i]->swdWrite(_return, APnDP, address2To3, senddata);
    return;
  }

  void SWDBitbang(std::vector<int32_t> & _return, const int32_t SWDBitValues) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->SWDBitbang(_return, SWDBitValues);
    }
    ifaces_[i]->SWDBitbang(_return, SWDBitValues);
    return;
  }

  void Jtag_to_SWD() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->Jtag_to_SWD();
    }
    ifaces_[i]->Jtag_to_SWD();
  }

  void swdFlush(BfrTckr& _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->swdFlush(_return);
    }
    ifaces_[i]->swdFlush(_return);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class EudSwdServiceConcurrentClient : virtual public EudSwdServiceIf {
 public:
  EudSwdServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  EudSwdServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
   ::Uts::ErrorCode::type writeRegister(const int32_t startAddress, const std::vector<int32_t> & data, const int32_t ap);
  int32_t send_writeRegister(const int32_t startAddress, const std::vector<int32_t> & data, const int32_t ap);
   ::Uts::ErrorCode::type recv_writeRegister(const int32_t seqid);
  void readRegister(std::vector<int32_t> & _return, const int32_t startAddress, const int32_t numBytes, const int32_t ap);
  int32_t send_readRegister(const int32_t startAddress, const int32_t numBytes, const int32_t ap);
  void recv_readRegister(std::vector<int32_t> & _return, const int32_t seqid);
  int32_t InitSWD(const int32_t dummy);
  int32_t send_InitSWD(const int32_t dummy);
  int32_t recv_InitSWD(const int32_t seqid);
  void swdRead_wrapper(BfrTckr& _return, const int32_t apndp, const int32_t A2_3);
  int32_t send_swdRead_wrapper(const int32_t apndp, const int32_t A2_3);
  void recv_swdRead_wrapper(BfrTckr& _return, const int32_t seqid);
  void swdWrite(BfrTckr& _return, const int32_t APnDP, const int32_t address2To3, const int64_t senddata);
  int32_t send_swdWrite(const int32_t APnDP, const int32_t address2To3, const int64_t senddata);
  void recv_swdWrite(BfrTckr& _return, const int32_t seqid);
  void SWDBitbang(std::vector<int32_t> & _return, const int32_t SWDBitValues);
  int32_t send_SWDBitbang(const int32_t SWDBitValues);
  void recv_SWDBitbang(std::vector<int32_t> & _return, const int32_t seqid);
  void Jtag_to_SWD();
  int32_t send_Jtag_to_SWD();
  void recv_Jtag_to_SWD(const int32_t seqid);
  void swdFlush(BfrTckr& _return);
  int32_t send_swdFlush();
  void recv_swdFlush(BfrTckr& _return, const int32_t seqid);
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
