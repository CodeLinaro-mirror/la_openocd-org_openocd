/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudTraceService_H
#define EudTraceService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "EudTraceService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class EudTraceServiceIf {
 public:
  virtual ~EudTraceServiceIf() {}
  virtual  ::Uts::ErrorCode::type openTrace() = 0;
  virtual  ::Uts::ErrorCode::type setChunkSizes(const int32_t chukSize, const int32_t maxChunks) = 0;
  virtual  ::Uts::ErrorCode::type setOutputDir(const std::string& outputDir) = 0;
  virtual  ::Uts::ErrorCode::type getOutputDir(const std::string& outputDir, const std::vector<int32_t> & pStringSize) = 0;
  virtual  ::Uts::ErrorCode::type setTimeoutMS(const int32_t timeoutMs) = 0;
  virtual  ::Uts::ErrorCode::type setTransferLength(const int32_t transferLength) = 0;
  virtual  ::Uts::ErrorCode::type closeTrace() = 0;
  virtual  ::Uts::ErrorCode::type flushTrace() = 0;
  virtual  ::Uts::ErrorCode::type reInitTrace() = 0;
  virtual  ::Uts::ErrorCode::type traceReset() = 0;
};

class EudTraceServiceIfFactory {
 public:
  typedef EudTraceServiceIf Handler;

  virtual ~EudTraceServiceIfFactory() {}

  virtual EudTraceServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(EudTraceServiceIf* /* handler */) = 0;
};

class EudTraceServiceIfSingletonFactory : virtual public EudTraceServiceIfFactory {
 public:
  EudTraceServiceIfSingletonFactory(const ::std::shared_ptr<EudTraceServiceIf>& iface) : iface_(iface) {}
  virtual ~EudTraceServiceIfSingletonFactory() {}

  virtual EudTraceServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(EudTraceServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<EudTraceServiceIf> iface_;
};

class EudTraceServiceNull : virtual public EudTraceServiceIf {
 public:
  virtual ~EudTraceServiceNull() {}
   ::Uts::ErrorCode::type openTrace() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setChunkSizes(const int32_t /* chukSize */, const int32_t /* maxChunks */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setOutputDir(const std::string& /* outputDir */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type getOutputDir(const std::string& /* outputDir */, const std::vector<int32_t> & /* pStringSize */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setTimeoutMS(const int32_t /* timeoutMs */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type setTransferLength(const int32_t /* transferLength */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type closeTrace() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type flushTrace() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type reInitTrace() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type traceReset() {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
};


class EudTraceService_openTrace_args {
 public:

  EudTraceService_openTrace_args(const EudTraceService_openTrace_args&);
  EudTraceService_openTrace_args& operator=(const EudTraceService_openTrace_args&);
  EudTraceService_openTrace_args() {
  }

  virtual ~EudTraceService_openTrace_args() noexcept;

  bool operator == (const EudTraceService_openTrace_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudTraceService_openTrace_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_openTrace_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_openTrace_pargs {
 public:


  virtual ~EudTraceService_openTrace_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_openTrace_result__isset {
  _EudTraceService_openTrace_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_openTrace_result__isset;

class EudTraceService_openTrace_result {
 public:

  EudTraceService_openTrace_result(const EudTraceService_openTrace_result&);
  EudTraceService_openTrace_result& operator=(const EudTraceService_openTrace_result&);
  EudTraceService_openTrace_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_openTrace_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_openTrace_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_openTrace_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_openTrace_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_openTrace_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_openTrace_presult__isset {
  _EudTraceService_openTrace_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_openTrace_presult__isset;

class EudTraceService_openTrace_presult {
 public:


  virtual ~EudTraceService_openTrace_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_openTrace_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudTraceService_setChunkSizes_args__isset {
  _EudTraceService_setChunkSizes_args__isset() : chukSize(false), maxChunks(false) {}
  bool chukSize :1;
  bool maxChunks :1;
} _EudTraceService_setChunkSizes_args__isset;

class EudTraceService_setChunkSizes_args {
 public:

  EudTraceService_setChunkSizes_args(const EudTraceService_setChunkSizes_args&);
  EudTraceService_setChunkSizes_args& operator=(const EudTraceService_setChunkSizes_args&);
  EudTraceService_setChunkSizes_args() : chukSize(0), maxChunks(0) {
  }

  virtual ~EudTraceService_setChunkSizes_args() noexcept;
  int32_t chukSize;
  int32_t maxChunks;

  _EudTraceService_setChunkSizes_args__isset __isset;

  void __set_chukSize(const int32_t val);

  void __set_maxChunks(const int32_t val);

  bool operator == (const EudTraceService_setChunkSizes_args & rhs) const
  {
    if (!(chukSize == rhs.chukSize))
      return false;
    if (!(maxChunks == rhs.maxChunks))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_setChunkSizes_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_setChunkSizes_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_setChunkSizes_pargs {
 public:


  virtual ~EudTraceService_setChunkSizes_pargs() noexcept;
  const int32_t* chukSize;
  const int32_t* maxChunks;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_setChunkSizes_result__isset {
  _EudTraceService_setChunkSizes_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_setChunkSizes_result__isset;

class EudTraceService_setChunkSizes_result {
 public:

  EudTraceService_setChunkSizes_result(const EudTraceService_setChunkSizes_result&);
  EudTraceService_setChunkSizes_result& operator=(const EudTraceService_setChunkSizes_result&);
  EudTraceService_setChunkSizes_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_setChunkSizes_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_setChunkSizes_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_setChunkSizes_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_setChunkSizes_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_setChunkSizes_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_setChunkSizes_presult__isset {
  _EudTraceService_setChunkSizes_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_setChunkSizes_presult__isset;

class EudTraceService_setChunkSizes_presult {
 public:


  virtual ~EudTraceService_setChunkSizes_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_setChunkSizes_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudTraceService_setOutputDir_args__isset {
  _EudTraceService_setOutputDir_args__isset() : outputDir(false) {}
  bool outputDir :1;
} _EudTraceService_setOutputDir_args__isset;

class EudTraceService_setOutputDir_args {
 public:

  EudTraceService_setOutputDir_args(const EudTraceService_setOutputDir_args&);
  EudTraceService_setOutputDir_args& operator=(const EudTraceService_setOutputDir_args&);
  EudTraceService_setOutputDir_args() : outputDir() {
  }

  virtual ~EudTraceService_setOutputDir_args() noexcept;
  std::string outputDir;

  _EudTraceService_setOutputDir_args__isset __isset;

  void __set_outputDir(const std::string& val);

  bool operator == (const EudTraceService_setOutputDir_args & rhs) const
  {
    if (!(outputDir == rhs.outputDir))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_setOutputDir_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_setOutputDir_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_setOutputDir_pargs {
 public:


  virtual ~EudTraceService_setOutputDir_pargs() noexcept;
  const std::string* outputDir;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_setOutputDir_result__isset {
  _EudTraceService_setOutputDir_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_setOutputDir_result__isset;

class EudTraceService_setOutputDir_result {
 public:

  EudTraceService_setOutputDir_result(const EudTraceService_setOutputDir_result&);
  EudTraceService_setOutputDir_result& operator=(const EudTraceService_setOutputDir_result&);
  EudTraceService_setOutputDir_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_setOutputDir_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_setOutputDir_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_setOutputDir_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_setOutputDir_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_setOutputDir_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_setOutputDir_presult__isset {
  _EudTraceService_setOutputDir_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_setOutputDir_presult__isset;

class EudTraceService_setOutputDir_presult {
 public:


  virtual ~EudTraceService_setOutputDir_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_setOutputDir_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudTraceService_getOutputDir_args__isset {
  _EudTraceService_getOutputDir_args__isset() : outputDir(false), pStringSize(false) {}
  bool outputDir :1;
  bool pStringSize :1;
} _EudTraceService_getOutputDir_args__isset;

class EudTraceService_getOutputDir_args {
 public:

  EudTraceService_getOutputDir_args(const EudTraceService_getOutputDir_args&);
  EudTraceService_getOutputDir_args& operator=(const EudTraceService_getOutputDir_args&);
  EudTraceService_getOutputDir_args() : outputDir() {
  }

  virtual ~EudTraceService_getOutputDir_args() noexcept;
  std::string outputDir;
  std::vector<int32_t>  pStringSize;

  _EudTraceService_getOutputDir_args__isset __isset;

  void __set_outputDir(const std::string& val);

  void __set_pStringSize(const std::vector<int32_t> & val);

  bool operator == (const EudTraceService_getOutputDir_args & rhs) const
  {
    if (!(outputDir == rhs.outputDir))
      return false;
    if (!(pStringSize == rhs.pStringSize))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_getOutputDir_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_getOutputDir_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_getOutputDir_pargs {
 public:


  virtual ~EudTraceService_getOutputDir_pargs() noexcept;
  const std::string* outputDir;
  const std::vector<int32_t> * pStringSize;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_getOutputDir_result__isset {
  _EudTraceService_getOutputDir_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_getOutputDir_result__isset;

class EudTraceService_getOutputDir_result {
 public:

  EudTraceService_getOutputDir_result(const EudTraceService_getOutputDir_result&);
  EudTraceService_getOutputDir_result& operator=(const EudTraceService_getOutputDir_result&);
  EudTraceService_getOutputDir_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_getOutputDir_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_getOutputDir_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_getOutputDir_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_getOutputDir_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_getOutputDir_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_getOutputDir_presult__isset {
  _EudTraceService_getOutputDir_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_getOutputDir_presult__isset;

class EudTraceService_getOutputDir_presult {
 public:


  virtual ~EudTraceService_getOutputDir_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_getOutputDir_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudTraceService_setTimeoutMS_args__isset {
  _EudTraceService_setTimeoutMS_args__isset() : timeoutMs(false) {}
  bool timeoutMs :1;
} _EudTraceService_setTimeoutMS_args__isset;

class EudTraceService_setTimeoutMS_args {
 public:

  EudTraceService_setTimeoutMS_args(const EudTraceService_setTimeoutMS_args&);
  EudTraceService_setTimeoutMS_args& operator=(const EudTraceService_setTimeoutMS_args&);
  EudTraceService_setTimeoutMS_args() : timeoutMs(0) {
  }

  virtual ~EudTraceService_setTimeoutMS_args() noexcept;
  int32_t timeoutMs;

  _EudTraceService_setTimeoutMS_args__isset __isset;

  void __set_timeoutMs(const int32_t val);

  bool operator == (const EudTraceService_setTimeoutMS_args & rhs) const
  {
    if (!(timeoutMs == rhs.timeoutMs))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_setTimeoutMS_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_setTimeoutMS_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_setTimeoutMS_pargs {
 public:


  virtual ~EudTraceService_setTimeoutMS_pargs() noexcept;
  const int32_t* timeoutMs;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_setTimeoutMS_result__isset {
  _EudTraceService_setTimeoutMS_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_setTimeoutMS_result__isset;

class EudTraceService_setTimeoutMS_result {
 public:

  EudTraceService_setTimeoutMS_result(const EudTraceService_setTimeoutMS_result&);
  EudTraceService_setTimeoutMS_result& operator=(const EudTraceService_setTimeoutMS_result&);
  EudTraceService_setTimeoutMS_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_setTimeoutMS_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_setTimeoutMS_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_setTimeoutMS_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_setTimeoutMS_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_setTimeoutMS_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_setTimeoutMS_presult__isset {
  _EudTraceService_setTimeoutMS_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_setTimeoutMS_presult__isset;

class EudTraceService_setTimeoutMS_presult {
 public:


  virtual ~EudTraceService_setTimeoutMS_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_setTimeoutMS_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _EudTraceService_setTransferLength_args__isset {
  _EudTraceService_setTransferLength_args__isset() : transferLength(false) {}
  bool transferLength :1;
} _EudTraceService_setTransferLength_args__isset;

class EudTraceService_setTransferLength_args {
 public:

  EudTraceService_setTransferLength_args(const EudTraceService_setTransferLength_args&);
  EudTraceService_setTransferLength_args& operator=(const EudTraceService_setTransferLength_args&);
  EudTraceService_setTransferLength_args() : transferLength(0) {
  }

  virtual ~EudTraceService_setTransferLength_args() noexcept;
  int32_t transferLength;

  _EudTraceService_setTransferLength_args__isset __isset;

  void __set_transferLength(const int32_t val);

  bool operator == (const EudTraceService_setTransferLength_args & rhs) const
  {
    if (!(transferLength == rhs.transferLength))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_setTransferLength_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_setTransferLength_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_setTransferLength_pargs {
 public:


  virtual ~EudTraceService_setTransferLength_pargs() noexcept;
  const int32_t* transferLength;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_setTransferLength_result__isset {
  _EudTraceService_setTransferLength_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_setTransferLength_result__isset;

class EudTraceService_setTransferLength_result {
 public:

  EudTraceService_setTransferLength_result(const EudTraceService_setTransferLength_result&);
  EudTraceService_setTransferLength_result& operator=(const EudTraceService_setTransferLength_result&);
  EudTraceService_setTransferLength_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_setTransferLength_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_setTransferLength_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_setTransferLength_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_setTransferLength_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_setTransferLength_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_setTransferLength_presult__isset {
  _EudTraceService_setTransferLength_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_setTransferLength_presult__isset;

class EudTraceService_setTransferLength_presult {
 public:


  virtual ~EudTraceService_setTransferLength_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_setTransferLength_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudTraceService_closeTrace_args {
 public:

  EudTraceService_closeTrace_args(const EudTraceService_closeTrace_args&);
  EudTraceService_closeTrace_args& operator=(const EudTraceService_closeTrace_args&);
  EudTraceService_closeTrace_args() {
  }

  virtual ~EudTraceService_closeTrace_args() noexcept;

  bool operator == (const EudTraceService_closeTrace_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudTraceService_closeTrace_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_closeTrace_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_closeTrace_pargs {
 public:


  virtual ~EudTraceService_closeTrace_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_closeTrace_result__isset {
  _EudTraceService_closeTrace_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_closeTrace_result__isset;

class EudTraceService_closeTrace_result {
 public:

  EudTraceService_closeTrace_result(const EudTraceService_closeTrace_result&);
  EudTraceService_closeTrace_result& operator=(const EudTraceService_closeTrace_result&);
  EudTraceService_closeTrace_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_closeTrace_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_closeTrace_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_closeTrace_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_closeTrace_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_closeTrace_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_closeTrace_presult__isset {
  _EudTraceService_closeTrace_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_closeTrace_presult__isset;

class EudTraceService_closeTrace_presult {
 public:


  virtual ~EudTraceService_closeTrace_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_closeTrace_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudTraceService_flushTrace_args {
 public:

  EudTraceService_flushTrace_args(const EudTraceService_flushTrace_args&);
  EudTraceService_flushTrace_args& operator=(const EudTraceService_flushTrace_args&);
  EudTraceService_flushTrace_args() {
  }

  virtual ~EudTraceService_flushTrace_args() noexcept;

  bool operator == (const EudTraceService_flushTrace_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudTraceService_flushTrace_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_flushTrace_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_flushTrace_pargs {
 public:


  virtual ~EudTraceService_flushTrace_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_flushTrace_result__isset {
  _EudTraceService_flushTrace_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_flushTrace_result__isset;

class EudTraceService_flushTrace_result {
 public:

  EudTraceService_flushTrace_result(const EudTraceService_flushTrace_result&);
  EudTraceService_flushTrace_result& operator=(const EudTraceService_flushTrace_result&);
  EudTraceService_flushTrace_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_flushTrace_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_flushTrace_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_flushTrace_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_flushTrace_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_flushTrace_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_flushTrace_presult__isset {
  _EudTraceService_flushTrace_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_flushTrace_presult__isset;

class EudTraceService_flushTrace_presult {
 public:


  virtual ~EudTraceService_flushTrace_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_flushTrace_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudTraceService_reInitTrace_args {
 public:

  EudTraceService_reInitTrace_args(const EudTraceService_reInitTrace_args&);
  EudTraceService_reInitTrace_args& operator=(const EudTraceService_reInitTrace_args&);
  EudTraceService_reInitTrace_args() {
  }

  virtual ~EudTraceService_reInitTrace_args() noexcept;

  bool operator == (const EudTraceService_reInitTrace_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudTraceService_reInitTrace_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_reInitTrace_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_reInitTrace_pargs {
 public:


  virtual ~EudTraceService_reInitTrace_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_reInitTrace_result__isset {
  _EudTraceService_reInitTrace_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_reInitTrace_result__isset;

class EudTraceService_reInitTrace_result {
 public:

  EudTraceService_reInitTrace_result(const EudTraceService_reInitTrace_result&);
  EudTraceService_reInitTrace_result& operator=(const EudTraceService_reInitTrace_result&);
  EudTraceService_reInitTrace_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_reInitTrace_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_reInitTrace_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_reInitTrace_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_reInitTrace_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_reInitTrace_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_reInitTrace_presult__isset {
  _EudTraceService_reInitTrace_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_reInitTrace_presult__isset;

class EudTraceService_reInitTrace_presult {
 public:


  virtual ~EudTraceService_reInitTrace_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_reInitTrace_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class EudTraceService_traceReset_args {
 public:

  EudTraceService_traceReset_args(const EudTraceService_traceReset_args&);
  EudTraceService_traceReset_args& operator=(const EudTraceService_traceReset_args&);
  EudTraceService_traceReset_args() {
  }

  virtual ~EudTraceService_traceReset_args() noexcept;

  bool operator == (const EudTraceService_traceReset_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const EudTraceService_traceReset_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_traceReset_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class EudTraceService_traceReset_pargs {
 public:


  virtual ~EudTraceService_traceReset_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_traceReset_result__isset {
  _EudTraceService_traceReset_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_traceReset_result__isset;

class EudTraceService_traceReset_result {
 public:

  EudTraceService_traceReset_result(const EudTraceService_traceReset_result&);
  EudTraceService_traceReset_result& operator=(const EudTraceService_traceReset_result&);
  EudTraceService_traceReset_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~EudTraceService_traceReset_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _EudTraceService_traceReset_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const EudTraceService_traceReset_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const EudTraceService_traceReset_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudTraceService_traceReset_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _EudTraceService_traceReset_presult__isset {
  _EudTraceService_traceReset_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _EudTraceService_traceReset_presult__isset;

class EudTraceService_traceReset_presult {
 public:


  virtual ~EudTraceService_traceReset_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _EudTraceService_traceReset_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class EudTraceServiceClient : virtual public EudTraceServiceIf {
 public:
  EudTraceServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  EudTraceServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
   ::Uts::ErrorCode::type openTrace();
  void send_openTrace();
   ::Uts::ErrorCode::type recv_openTrace();
   ::Uts::ErrorCode::type setChunkSizes(const int32_t chukSize, const int32_t maxChunks);
  void send_setChunkSizes(const int32_t chukSize, const int32_t maxChunks);
   ::Uts::ErrorCode::type recv_setChunkSizes();
   ::Uts::ErrorCode::type setOutputDir(const std::string& outputDir);
  void send_setOutputDir(const std::string& outputDir);
   ::Uts::ErrorCode::type recv_setOutputDir();
   ::Uts::ErrorCode::type getOutputDir(const std::string& outputDir, const std::vector<int32_t> & pStringSize);
  void send_getOutputDir(const std::string& outputDir, const std::vector<int32_t> & pStringSize);
   ::Uts::ErrorCode::type recv_getOutputDir();
   ::Uts::ErrorCode::type setTimeoutMS(const int32_t timeoutMs);
  void send_setTimeoutMS(const int32_t timeoutMs);
   ::Uts::ErrorCode::type recv_setTimeoutMS();
   ::Uts::ErrorCode::type setTransferLength(const int32_t transferLength);
  void send_setTransferLength(const int32_t transferLength);
   ::Uts::ErrorCode::type recv_setTransferLength();
   ::Uts::ErrorCode::type closeTrace();
  void send_closeTrace();
   ::Uts::ErrorCode::type recv_closeTrace();
   ::Uts::ErrorCode::type flushTrace();
  void send_flushTrace();
   ::Uts::ErrorCode::type recv_flushTrace();
   ::Uts::ErrorCode::type reInitTrace();
  void send_reInitTrace();
   ::Uts::ErrorCode::type recv_reInitTrace();
   ::Uts::ErrorCode::type traceReset();
  void send_traceReset();
   ::Uts::ErrorCode::type recv_traceReset();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class EudTraceServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<EudTraceServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (EudTraceServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_openTrace(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setChunkSizes(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setOutputDir(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getOutputDir(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setTimeoutMS(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setTransferLength(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_closeTrace(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_flushTrace(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_reInitTrace(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_traceReset(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  EudTraceServiceProcessor(::std::shared_ptr<EudTraceServiceIf> iface) :
    iface_(iface) {
    processMap_["openTrace"] = &EudTraceServiceProcessor::process_openTrace;
    processMap_["setChunkSizes"] = &EudTraceServiceProcessor::process_setChunkSizes;
    processMap_["setOutputDir"] = &EudTraceServiceProcessor::process_setOutputDir;
    processMap_["getOutputDir"] = &EudTraceServiceProcessor::process_getOutputDir;
    processMap_["setTimeoutMS"] = &EudTraceServiceProcessor::process_setTimeoutMS;
    processMap_["setTransferLength"] = &EudTraceServiceProcessor::process_setTransferLength;
    processMap_["closeTrace"] = &EudTraceServiceProcessor::process_closeTrace;
    processMap_["flushTrace"] = &EudTraceServiceProcessor::process_flushTrace;
    processMap_["reInitTrace"] = &EudTraceServiceProcessor::process_reInitTrace;
    processMap_["traceReset"] = &EudTraceServiceProcessor::process_traceReset;
  }

  virtual ~EudTraceServiceProcessor() {}
};

class EudTraceServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  EudTraceServiceProcessorFactory(const ::std::shared_ptr< EudTraceServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< EudTraceServiceIfFactory > handlerFactory_;
};

class EudTraceServiceMultiface : virtual public EudTraceServiceIf {
 public:
  EudTraceServiceMultiface(std::vector<std::shared_ptr<EudTraceServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~EudTraceServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<EudTraceServiceIf> > ifaces_;
  EudTraceServiceMultiface() {}
  void add(::std::shared_ptr<EudTraceServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
   ::Uts::ErrorCode::type openTrace() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->openTrace();
    }
    return ifaces_[i]->openTrace();
  }

   ::Uts::ErrorCode::type setChunkSizes(const int32_t chukSize, const int32_t maxChunks) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setChunkSizes(chukSize, maxChunks);
    }
    return ifaces_[i]->setChunkSizes(chukSize, maxChunks);
  }

   ::Uts::ErrorCode::type setOutputDir(const std::string& outputDir) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setOutputDir(outputDir);
    }
    return ifaces_[i]->setOutputDir(outputDir);
  }

   ::Uts::ErrorCode::type getOutputDir(const std::string& outputDir, const std::vector<int32_t> & pStringSize) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getOutputDir(outputDir, pStringSize);
    }
    return ifaces_[i]->getOutputDir(outputDir, pStringSize);
  }

   ::Uts::ErrorCode::type setTimeoutMS(const int32_t timeoutMs) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setTimeoutMS(timeoutMs);
    }
    return ifaces_[i]->setTimeoutMS(timeoutMs);
  }

   ::Uts::ErrorCode::type setTransferLength(const int32_t transferLength) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setTransferLength(transferLength);
    }
    return ifaces_[i]->setTransferLength(transferLength);
  }

   ::Uts::ErrorCode::type closeTrace() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->closeTrace();
    }
    return ifaces_[i]->closeTrace();
  }

   ::Uts::ErrorCode::type flushTrace() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->flushTrace();
    }
    return ifaces_[i]->flushTrace();
  }

   ::Uts::ErrorCode::type reInitTrace() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->reInitTrace();
    }
    return ifaces_[i]->reInitTrace();
  }

   ::Uts::ErrorCode::type traceReset() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->traceReset();
    }
    return ifaces_[i]->traceReset();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class EudTraceServiceConcurrentClient : virtual public EudTraceServiceIf {
 public:
  EudTraceServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  EudTraceServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
   ::Uts::ErrorCode::type openTrace();
  int32_t send_openTrace();
   ::Uts::ErrorCode::type recv_openTrace(const int32_t seqid);
   ::Uts::ErrorCode::type setChunkSizes(const int32_t chukSize, const int32_t maxChunks);
  int32_t send_setChunkSizes(const int32_t chukSize, const int32_t maxChunks);
   ::Uts::ErrorCode::type recv_setChunkSizes(const int32_t seqid);
   ::Uts::ErrorCode::type setOutputDir(const std::string& outputDir);
  int32_t send_setOutputDir(const std::string& outputDir);
   ::Uts::ErrorCode::type recv_setOutputDir(const int32_t seqid);
   ::Uts::ErrorCode::type getOutputDir(const std::string& outputDir, const std::vector<int32_t> & pStringSize);
  int32_t send_getOutputDir(const std::string& outputDir, const std::vector<int32_t> & pStringSize);
   ::Uts::ErrorCode::type recv_getOutputDir(const int32_t seqid);
   ::Uts::ErrorCode::type setTimeoutMS(const int32_t timeoutMs);
  int32_t send_setTimeoutMS(const int32_t timeoutMs);
   ::Uts::ErrorCode::type recv_setTimeoutMS(const int32_t seqid);
   ::Uts::ErrorCode::type setTransferLength(const int32_t transferLength);
  int32_t send_setTransferLength(const int32_t transferLength);
   ::Uts::ErrorCode::type recv_setTransferLength(const int32_t seqid);
   ::Uts::ErrorCode::type closeTrace();
  int32_t send_closeTrace();
   ::Uts::ErrorCode::type recv_closeTrace(const int32_t seqid);
   ::Uts::ErrorCode::type flushTrace();
  int32_t send_flushTrace();
   ::Uts::ErrorCode::type recv_flushTrace(const int32_t seqid);
   ::Uts::ErrorCode::type reInitTrace();
  int32_t send_reInitTrace();
   ::Uts::ErrorCode::type recv_reInitTrace(const int32_t seqid);
   ::Uts::ErrorCode::type traceReset();
  int32_t send_traceReset();
   ::Uts::ErrorCode::type recv_traceReset(const int32_t seqid);
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
