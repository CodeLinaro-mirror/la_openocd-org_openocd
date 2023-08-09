/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef QutsService_H
#define QutsService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "QutsService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class QutsServiceIf {
 public:
  virtual ~QutsServiceIf() {}
  virtual int32_t registerClient(const std::string& clientName) = 0;
  virtual int32_t registerSecureClient(const  ::Uts::ClientInfo& clientInfo) = 0;
  virtual int32_t getQutsApplicationPort() = 0;
  virtual  ::Uts::ErrorCode::type registerAutomationPort(const std::string& appName, const int32_t automationPort) = 0;
  virtual  ::Uts::ErrorCode::type unRegisterAutomationPort(const std::string& appName, const int32_t automationPort) = 0;
  virtual bool runLoopback() = 0;
};

class QutsServiceIfFactory {
 public:
  typedef QutsServiceIf Handler;

  virtual ~QutsServiceIfFactory() {}

  virtual QutsServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(QutsServiceIf* /* handler */) = 0;
};

class QutsServiceIfSingletonFactory : virtual public QutsServiceIfFactory {
 public:
  QutsServiceIfSingletonFactory(const ::std::shared_ptr<QutsServiceIf>& iface) : iface_(iface) {}
  virtual ~QutsServiceIfSingletonFactory() {}

  virtual QutsServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(QutsServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<QutsServiceIf> iface_;
};

class QutsServiceNull : virtual public QutsServiceIf {
 public:
  virtual ~QutsServiceNull() {}
  int32_t registerClient(const std::string& /* clientName */) {
    int32_t _return = 0;
    return _return;
  }
  int32_t registerSecureClient(const  ::Uts::ClientInfo& /* clientInfo */) {
    int32_t _return = 0;
    return _return;
  }
  int32_t getQutsApplicationPort() {
    int32_t _return = 0;
    return _return;
  }
   ::Uts::ErrorCode::type registerAutomationPort(const std::string& /* appName */, const int32_t /* automationPort */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type unRegisterAutomationPort(const std::string& /* appName */, const int32_t /* automationPort */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  bool runLoopback() {
    bool _return = false;
    return _return;
  }
};

typedef struct _QutsService_registerClient_args__isset {
  _QutsService_registerClient_args__isset() : clientName(false) {}
  bool clientName :1;
} _QutsService_registerClient_args__isset;

class QutsService_registerClient_args {
 public:

  QutsService_registerClient_args(const QutsService_registerClient_args&);
  QutsService_registerClient_args& operator=(const QutsService_registerClient_args&);
  QutsService_registerClient_args() : clientName() {
  }

  virtual ~QutsService_registerClient_args() noexcept;
  std::string clientName;

  _QutsService_registerClient_args__isset __isset;

  void __set_clientName(const std::string& val);

  bool operator == (const QutsService_registerClient_args & rhs) const
  {
    if (!(clientName == rhs.clientName))
      return false;
    return true;
  }
  bool operator != (const QutsService_registerClient_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_registerClient_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QutsService_registerClient_pargs {
 public:


  virtual ~QutsService_registerClient_pargs() noexcept;
  const std::string* clientName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_registerClient_result__isset {
  _QutsService_registerClient_result__isset() : success(false) {}
  bool success :1;
} _QutsService_registerClient_result__isset;

class QutsService_registerClient_result {
 public:

  QutsService_registerClient_result(const QutsService_registerClient_result&);
  QutsService_registerClient_result& operator=(const QutsService_registerClient_result&);
  QutsService_registerClient_result() : success(0) {
  }

  virtual ~QutsService_registerClient_result() noexcept;
  int32_t success;

  _QutsService_registerClient_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const QutsService_registerClient_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QutsService_registerClient_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_registerClient_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_registerClient_presult__isset {
  _QutsService_registerClient_presult__isset() : success(false) {}
  bool success :1;
} _QutsService_registerClient_presult__isset;

class QutsService_registerClient_presult {
 public:


  virtual ~QutsService_registerClient_presult() noexcept;
  int32_t* success;

  _QutsService_registerClient_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QutsService_registerSecureClient_args__isset {
  _QutsService_registerSecureClient_args__isset() : clientInfo(false) {}
  bool clientInfo :1;
} _QutsService_registerSecureClient_args__isset;

class QutsService_registerSecureClient_args {
 public:

  QutsService_registerSecureClient_args(const QutsService_registerSecureClient_args&);
  QutsService_registerSecureClient_args& operator=(const QutsService_registerSecureClient_args&);
  QutsService_registerSecureClient_args() {
  }

  virtual ~QutsService_registerSecureClient_args() noexcept;
   ::Uts::ClientInfo clientInfo;

  _QutsService_registerSecureClient_args__isset __isset;

  void __set_clientInfo(const  ::Uts::ClientInfo& val);

  bool operator == (const QutsService_registerSecureClient_args & rhs) const
  {
    if (!(clientInfo == rhs.clientInfo))
      return false;
    return true;
  }
  bool operator != (const QutsService_registerSecureClient_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_registerSecureClient_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QutsService_registerSecureClient_pargs {
 public:


  virtual ~QutsService_registerSecureClient_pargs() noexcept;
  const  ::Uts::ClientInfo* clientInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_registerSecureClient_result__isset {
  _QutsService_registerSecureClient_result__isset() : success(false) {}
  bool success :1;
} _QutsService_registerSecureClient_result__isset;

class QutsService_registerSecureClient_result {
 public:

  QutsService_registerSecureClient_result(const QutsService_registerSecureClient_result&);
  QutsService_registerSecureClient_result& operator=(const QutsService_registerSecureClient_result&);
  QutsService_registerSecureClient_result() : success(0) {
  }

  virtual ~QutsService_registerSecureClient_result() noexcept;
  int32_t success;

  _QutsService_registerSecureClient_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const QutsService_registerSecureClient_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QutsService_registerSecureClient_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_registerSecureClient_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_registerSecureClient_presult__isset {
  _QutsService_registerSecureClient_presult__isset() : success(false) {}
  bool success :1;
} _QutsService_registerSecureClient_presult__isset;

class QutsService_registerSecureClient_presult {
 public:


  virtual ~QutsService_registerSecureClient_presult() noexcept;
  int32_t* success;

  _QutsService_registerSecureClient_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class QutsService_getQutsApplicationPort_args {
 public:

  QutsService_getQutsApplicationPort_args(const QutsService_getQutsApplicationPort_args&);
  QutsService_getQutsApplicationPort_args& operator=(const QutsService_getQutsApplicationPort_args&);
  QutsService_getQutsApplicationPort_args() {
  }

  virtual ~QutsService_getQutsApplicationPort_args() noexcept;

  bool operator == (const QutsService_getQutsApplicationPort_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const QutsService_getQutsApplicationPort_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_getQutsApplicationPort_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QutsService_getQutsApplicationPort_pargs {
 public:


  virtual ~QutsService_getQutsApplicationPort_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_getQutsApplicationPort_result__isset {
  _QutsService_getQutsApplicationPort_result__isset() : success(false) {}
  bool success :1;
} _QutsService_getQutsApplicationPort_result__isset;

class QutsService_getQutsApplicationPort_result {
 public:

  QutsService_getQutsApplicationPort_result(const QutsService_getQutsApplicationPort_result&);
  QutsService_getQutsApplicationPort_result& operator=(const QutsService_getQutsApplicationPort_result&);
  QutsService_getQutsApplicationPort_result() : success(0) {
  }

  virtual ~QutsService_getQutsApplicationPort_result() noexcept;
  int32_t success;

  _QutsService_getQutsApplicationPort_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const QutsService_getQutsApplicationPort_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QutsService_getQutsApplicationPort_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_getQutsApplicationPort_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_getQutsApplicationPort_presult__isset {
  _QutsService_getQutsApplicationPort_presult__isset() : success(false) {}
  bool success :1;
} _QutsService_getQutsApplicationPort_presult__isset;

class QutsService_getQutsApplicationPort_presult {
 public:


  virtual ~QutsService_getQutsApplicationPort_presult() noexcept;
  int32_t* success;

  _QutsService_getQutsApplicationPort_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QutsService_registerAutomationPort_args__isset {
  _QutsService_registerAutomationPort_args__isset() : appName(false), automationPort(false) {}
  bool appName :1;
  bool automationPort :1;
} _QutsService_registerAutomationPort_args__isset;

class QutsService_registerAutomationPort_args {
 public:

  QutsService_registerAutomationPort_args(const QutsService_registerAutomationPort_args&);
  QutsService_registerAutomationPort_args& operator=(const QutsService_registerAutomationPort_args&);
  QutsService_registerAutomationPort_args() : appName(), automationPort(0) {
  }

  virtual ~QutsService_registerAutomationPort_args() noexcept;
  std::string appName;
  int32_t automationPort;

  _QutsService_registerAutomationPort_args__isset __isset;

  void __set_appName(const std::string& val);

  void __set_automationPort(const int32_t val);

  bool operator == (const QutsService_registerAutomationPort_args & rhs) const
  {
    if (!(appName == rhs.appName))
      return false;
    if (!(automationPort == rhs.automationPort))
      return false;
    return true;
  }
  bool operator != (const QutsService_registerAutomationPort_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_registerAutomationPort_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QutsService_registerAutomationPort_pargs {
 public:


  virtual ~QutsService_registerAutomationPort_pargs() noexcept;
  const std::string* appName;
  const int32_t* automationPort;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_registerAutomationPort_result__isset {
  _QutsService_registerAutomationPort_result__isset() : success(false) {}
  bool success :1;
} _QutsService_registerAutomationPort_result__isset;

class QutsService_registerAutomationPort_result {
 public:

  QutsService_registerAutomationPort_result(const QutsService_registerAutomationPort_result&);
  QutsService_registerAutomationPort_result& operator=(const QutsService_registerAutomationPort_result&);
  QutsService_registerAutomationPort_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~QutsService_registerAutomationPort_result() noexcept;
   ::Uts::ErrorCode::type success;

  _QutsService_registerAutomationPort_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  bool operator == (const QutsService_registerAutomationPort_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QutsService_registerAutomationPort_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_registerAutomationPort_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_registerAutomationPort_presult__isset {
  _QutsService_registerAutomationPort_presult__isset() : success(false) {}
  bool success :1;
} _QutsService_registerAutomationPort_presult__isset;

class QutsService_registerAutomationPort_presult {
 public:


  virtual ~QutsService_registerAutomationPort_presult() noexcept;
   ::Uts::ErrorCode::type* success;

  _QutsService_registerAutomationPort_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _QutsService_unRegisterAutomationPort_args__isset {
  _QutsService_unRegisterAutomationPort_args__isset() : appName(false), automationPort(false) {}
  bool appName :1;
  bool automationPort :1;
} _QutsService_unRegisterAutomationPort_args__isset;

class QutsService_unRegisterAutomationPort_args {
 public:

  QutsService_unRegisterAutomationPort_args(const QutsService_unRegisterAutomationPort_args&);
  QutsService_unRegisterAutomationPort_args& operator=(const QutsService_unRegisterAutomationPort_args&);
  QutsService_unRegisterAutomationPort_args() : appName(), automationPort(0) {
  }

  virtual ~QutsService_unRegisterAutomationPort_args() noexcept;
  std::string appName;
  int32_t automationPort;

  _QutsService_unRegisterAutomationPort_args__isset __isset;

  void __set_appName(const std::string& val);

  void __set_automationPort(const int32_t val);

  bool operator == (const QutsService_unRegisterAutomationPort_args & rhs) const
  {
    if (!(appName == rhs.appName))
      return false;
    if (!(automationPort == rhs.automationPort))
      return false;
    return true;
  }
  bool operator != (const QutsService_unRegisterAutomationPort_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_unRegisterAutomationPort_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QutsService_unRegisterAutomationPort_pargs {
 public:


  virtual ~QutsService_unRegisterAutomationPort_pargs() noexcept;
  const std::string* appName;
  const int32_t* automationPort;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_unRegisterAutomationPort_result__isset {
  _QutsService_unRegisterAutomationPort_result__isset() : success(false) {}
  bool success :1;
} _QutsService_unRegisterAutomationPort_result__isset;

class QutsService_unRegisterAutomationPort_result {
 public:

  QutsService_unRegisterAutomationPort_result(const QutsService_unRegisterAutomationPort_result&);
  QutsService_unRegisterAutomationPort_result& operator=(const QutsService_unRegisterAutomationPort_result&);
  QutsService_unRegisterAutomationPort_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~QutsService_unRegisterAutomationPort_result() noexcept;
   ::Uts::ErrorCode::type success;

  _QutsService_unRegisterAutomationPort_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  bool operator == (const QutsService_unRegisterAutomationPort_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QutsService_unRegisterAutomationPort_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_unRegisterAutomationPort_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_unRegisterAutomationPort_presult__isset {
  _QutsService_unRegisterAutomationPort_presult__isset() : success(false) {}
  bool success :1;
} _QutsService_unRegisterAutomationPort_presult__isset;

class QutsService_unRegisterAutomationPort_presult {
 public:


  virtual ~QutsService_unRegisterAutomationPort_presult() noexcept;
   ::Uts::ErrorCode::type* success;

  _QutsService_unRegisterAutomationPort_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class QutsService_runLoopback_args {
 public:

  QutsService_runLoopback_args(const QutsService_runLoopback_args&);
  QutsService_runLoopback_args& operator=(const QutsService_runLoopback_args&);
  QutsService_runLoopback_args() {
  }

  virtual ~QutsService_runLoopback_args() noexcept;

  bool operator == (const QutsService_runLoopback_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const QutsService_runLoopback_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_runLoopback_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class QutsService_runLoopback_pargs {
 public:


  virtual ~QutsService_runLoopback_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_runLoopback_result__isset {
  _QutsService_runLoopback_result__isset() : success(false) {}
  bool success :1;
} _QutsService_runLoopback_result__isset;

class QutsService_runLoopback_result {
 public:

  QutsService_runLoopback_result(const QutsService_runLoopback_result&);
  QutsService_runLoopback_result& operator=(const QutsService_runLoopback_result&);
  QutsService_runLoopback_result() : success(0) {
  }

  virtual ~QutsService_runLoopback_result() noexcept;
  bool success;

  _QutsService_runLoopback_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const QutsService_runLoopback_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const QutsService_runLoopback_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const QutsService_runLoopback_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _QutsService_runLoopback_presult__isset {
  _QutsService_runLoopback_presult__isset() : success(false) {}
  bool success :1;
} _QutsService_runLoopback_presult__isset;

class QutsService_runLoopback_presult {
 public:


  virtual ~QutsService_runLoopback_presult() noexcept;
  bool* success;

  _QutsService_runLoopback_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class QutsServiceClient : virtual public QutsServiceIf {
 public:
  QutsServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  QutsServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  int32_t registerClient(const std::string& clientName);
  void send_registerClient(const std::string& clientName);
  int32_t recv_registerClient();
  int32_t registerSecureClient(const  ::Uts::ClientInfo& clientInfo);
  void send_registerSecureClient(const  ::Uts::ClientInfo& clientInfo);
  int32_t recv_registerSecureClient();
  int32_t getQutsApplicationPort();
  void send_getQutsApplicationPort();
  int32_t recv_getQutsApplicationPort();
   ::Uts::ErrorCode::type registerAutomationPort(const std::string& appName, const int32_t automationPort);
  void send_registerAutomationPort(const std::string& appName, const int32_t automationPort);
   ::Uts::ErrorCode::type recv_registerAutomationPort();
   ::Uts::ErrorCode::type unRegisterAutomationPort(const std::string& appName, const int32_t automationPort);
  void send_unRegisterAutomationPort(const std::string& appName, const int32_t automationPort);
   ::Uts::ErrorCode::type recv_unRegisterAutomationPort();
  bool runLoopback();
  void send_runLoopback();
  bool recv_runLoopback();
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class QutsServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<QutsServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (QutsServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_registerClient(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_registerSecureClient(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getQutsApplicationPort(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_registerAutomationPort(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_unRegisterAutomationPort(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_runLoopback(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  QutsServiceProcessor(::std::shared_ptr<QutsServiceIf> iface) :
    iface_(iface) {
    processMap_["registerClient"] = &QutsServiceProcessor::process_registerClient;
    processMap_["registerSecureClient"] = &QutsServiceProcessor::process_registerSecureClient;
    processMap_["getQutsApplicationPort"] = &QutsServiceProcessor::process_getQutsApplicationPort;
    processMap_["registerAutomationPort"] = &QutsServiceProcessor::process_registerAutomationPort;
    processMap_["unRegisterAutomationPort"] = &QutsServiceProcessor::process_unRegisterAutomationPort;
    processMap_["runLoopback"] = &QutsServiceProcessor::process_runLoopback;
  }

  virtual ~QutsServiceProcessor() {}
};

class QutsServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  QutsServiceProcessorFactory(const ::std::shared_ptr< QutsServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< QutsServiceIfFactory > handlerFactory_;
};

class QutsServiceMultiface : virtual public QutsServiceIf {
 public:
  QutsServiceMultiface(std::vector<std::shared_ptr<QutsServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~QutsServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<QutsServiceIf> > ifaces_;
  QutsServiceMultiface() {}
  void add(::std::shared_ptr<QutsServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t registerClient(const std::string& clientName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->registerClient(clientName);
    }
    return ifaces_[i]->registerClient(clientName);
  }

  int32_t registerSecureClient(const  ::Uts::ClientInfo& clientInfo) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->registerSecureClient(clientInfo);
    }
    return ifaces_[i]->registerSecureClient(clientInfo);
  }

  int32_t getQutsApplicationPort() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getQutsApplicationPort();
    }
    return ifaces_[i]->getQutsApplicationPort();
  }

   ::Uts::ErrorCode::type registerAutomationPort(const std::string& appName, const int32_t automationPort) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->registerAutomationPort(appName, automationPort);
    }
    return ifaces_[i]->registerAutomationPort(appName, automationPort);
  }

   ::Uts::ErrorCode::type unRegisterAutomationPort(const std::string& appName, const int32_t automationPort) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->unRegisterAutomationPort(appName, automationPort);
    }
    return ifaces_[i]->unRegisterAutomationPort(appName, automationPort);
  }

  bool runLoopback() {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->runLoopback();
    }
    return ifaces_[i]->runLoopback();
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class QutsServiceConcurrentClient : virtual public QutsServiceIf {
 public:
  QutsServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  QutsServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
  int32_t registerClient(const std::string& clientName);
  int32_t send_registerClient(const std::string& clientName);
  int32_t recv_registerClient(const int32_t seqid);
  int32_t registerSecureClient(const  ::Uts::ClientInfo& clientInfo);
  int32_t send_registerSecureClient(const  ::Uts::ClientInfo& clientInfo);
  int32_t recv_registerSecureClient(const int32_t seqid);
  int32_t getQutsApplicationPort();
  int32_t send_getQutsApplicationPort();
  int32_t recv_getQutsApplicationPort(const int32_t seqid);
   ::Uts::ErrorCode::type registerAutomationPort(const std::string& appName, const int32_t automationPort);
  int32_t send_registerAutomationPort(const std::string& appName, const int32_t automationPort);
   ::Uts::ErrorCode::type recv_registerAutomationPort(const int32_t seqid);
   ::Uts::ErrorCode::type unRegisterAutomationPort(const std::string& appName, const int32_t automationPort);
  int32_t send_unRegisterAutomationPort(const std::string& appName, const int32_t automationPort);
   ::Uts::ErrorCode::type recv_unRegisterAutomationPort(const int32_t seqid);
  bool runLoopback();
  int32_t send_runLoopback();
  bool recv_runLoopback(const int32_t seqid);
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
