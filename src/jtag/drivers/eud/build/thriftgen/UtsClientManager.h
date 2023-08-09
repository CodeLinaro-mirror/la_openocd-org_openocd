/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef UtsClientManager_H
#define UtsClientManager_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "UtsClientManager_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class UtsClientManagerIf {
 public:
  virtual ~UtsClientManagerIf() {}
  virtual int32_t registerClient(const std::string& clientName) = 0;
  virtual int32_t registerSecureClient(const  ::Uts::ClientInfo& clientInfo) = 0;
  virtual void getClientNames(std::vector<std::string> & _return) = 0;
};

class UtsClientManagerIfFactory {
 public:
  typedef UtsClientManagerIf Handler;

  virtual ~UtsClientManagerIfFactory() {}

  virtual UtsClientManagerIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(UtsClientManagerIf* /* handler */) = 0;
};

class UtsClientManagerIfSingletonFactory : virtual public UtsClientManagerIfFactory {
 public:
  UtsClientManagerIfSingletonFactory(const ::std::shared_ptr<UtsClientManagerIf>& iface) : iface_(iface) {}
  virtual ~UtsClientManagerIfSingletonFactory() {}

  virtual UtsClientManagerIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(UtsClientManagerIf* /* handler */) {}

 protected:
  ::std::shared_ptr<UtsClientManagerIf> iface_;
};

class UtsClientManagerNull : virtual public UtsClientManagerIf {
 public:
  virtual ~UtsClientManagerNull() {}
  int32_t registerClient(const std::string& /* clientName */) {
    int32_t _return = 0;
    return _return;
  }
  int32_t registerSecureClient(const  ::Uts::ClientInfo& /* clientInfo */) {
    int32_t _return = 0;
    return _return;
  }
  void getClientNames(std::vector<std::string> & /* _return */) {
    return;
  }
};

typedef struct _UtsClientManager_registerClient_args__isset {
  _UtsClientManager_registerClient_args__isset() : clientName(false) {}
  bool clientName :1;
} _UtsClientManager_registerClient_args__isset;

class UtsClientManager_registerClient_args {
 public:

  UtsClientManager_registerClient_args(const UtsClientManager_registerClient_args&);
  UtsClientManager_registerClient_args& operator=(const UtsClientManager_registerClient_args&);
  UtsClientManager_registerClient_args() : clientName() {
  }

  virtual ~UtsClientManager_registerClient_args() noexcept;
  std::string clientName;

  _UtsClientManager_registerClient_args__isset __isset;

  void __set_clientName(const std::string& val);

  bool operator == (const UtsClientManager_registerClient_args & rhs) const
  {
    if (!(clientName == rhs.clientName))
      return false;
    return true;
  }
  bool operator != (const UtsClientManager_registerClient_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtsClientManager_registerClient_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtsClientManager_registerClient_pargs {
 public:


  virtual ~UtsClientManager_registerClient_pargs() noexcept;
  const std::string* clientName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtsClientManager_registerClient_result__isset {
  _UtsClientManager_registerClient_result__isset() : success(false) {}
  bool success :1;
} _UtsClientManager_registerClient_result__isset;

class UtsClientManager_registerClient_result {
 public:

  UtsClientManager_registerClient_result(const UtsClientManager_registerClient_result&);
  UtsClientManager_registerClient_result& operator=(const UtsClientManager_registerClient_result&);
  UtsClientManager_registerClient_result() : success(0) {
  }

  virtual ~UtsClientManager_registerClient_result() noexcept;
  int32_t success;

  _UtsClientManager_registerClient_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const UtsClientManager_registerClient_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UtsClientManager_registerClient_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtsClientManager_registerClient_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtsClientManager_registerClient_presult__isset {
  _UtsClientManager_registerClient_presult__isset() : success(false) {}
  bool success :1;
} _UtsClientManager_registerClient_presult__isset;

class UtsClientManager_registerClient_presult {
 public:


  virtual ~UtsClientManager_registerClient_presult() noexcept;
  int32_t* success;

  _UtsClientManager_registerClient_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtsClientManager_registerSecureClient_args__isset {
  _UtsClientManager_registerSecureClient_args__isset() : clientInfo(false) {}
  bool clientInfo :1;
} _UtsClientManager_registerSecureClient_args__isset;

class UtsClientManager_registerSecureClient_args {
 public:

  UtsClientManager_registerSecureClient_args(const UtsClientManager_registerSecureClient_args&);
  UtsClientManager_registerSecureClient_args& operator=(const UtsClientManager_registerSecureClient_args&);
  UtsClientManager_registerSecureClient_args() {
  }

  virtual ~UtsClientManager_registerSecureClient_args() noexcept;
   ::Uts::ClientInfo clientInfo;

  _UtsClientManager_registerSecureClient_args__isset __isset;

  void __set_clientInfo(const  ::Uts::ClientInfo& val);

  bool operator == (const UtsClientManager_registerSecureClient_args & rhs) const
  {
    if (!(clientInfo == rhs.clientInfo))
      return false;
    return true;
  }
  bool operator != (const UtsClientManager_registerSecureClient_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtsClientManager_registerSecureClient_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtsClientManager_registerSecureClient_pargs {
 public:


  virtual ~UtsClientManager_registerSecureClient_pargs() noexcept;
  const  ::Uts::ClientInfo* clientInfo;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtsClientManager_registerSecureClient_result__isset {
  _UtsClientManager_registerSecureClient_result__isset() : success(false) {}
  bool success :1;
} _UtsClientManager_registerSecureClient_result__isset;

class UtsClientManager_registerSecureClient_result {
 public:

  UtsClientManager_registerSecureClient_result(const UtsClientManager_registerSecureClient_result&);
  UtsClientManager_registerSecureClient_result& operator=(const UtsClientManager_registerSecureClient_result&);
  UtsClientManager_registerSecureClient_result() : success(0) {
  }

  virtual ~UtsClientManager_registerSecureClient_result() noexcept;
  int32_t success;

  _UtsClientManager_registerSecureClient_result__isset __isset;

  void __set_success(const int32_t val);

  bool operator == (const UtsClientManager_registerSecureClient_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UtsClientManager_registerSecureClient_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtsClientManager_registerSecureClient_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtsClientManager_registerSecureClient_presult__isset {
  _UtsClientManager_registerSecureClient_presult__isset() : success(false) {}
  bool success :1;
} _UtsClientManager_registerSecureClient_presult__isset;

class UtsClientManager_registerSecureClient_presult {
 public:


  virtual ~UtsClientManager_registerSecureClient_presult() noexcept;
  int32_t* success;

  _UtsClientManager_registerSecureClient_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class UtsClientManager_getClientNames_args {
 public:

  UtsClientManager_getClientNames_args(const UtsClientManager_getClientNames_args&);
  UtsClientManager_getClientNames_args& operator=(const UtsClientManager_getClientNames_args&);
  UtsClientManager_getClientNames_args() {
  }

  virtual ~UtsClientManager_getClientNames_args() noexcept;

  bool operator == (const UtsClientManager_getClientNames_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const UtsClientManager_getClientNames_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtsClientManager_getClientNames_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtsClientManager_getClientNames_pargs {
 public:


  virtual ~UtsClientManager_getClientNames_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtsClientManager_getClientNames_result__isset {
  _UtsClientManager_getClientNames_result__isset() : success(false) {}
  bool success :1;
} _UtsClientManager_getClientNames_result__isset;

class UtsClientManager_getClientNames_result {
 public:

  UtsClientManager_getClientNames_result(const UtsClientManager_getClientNames_result&);
  UtsClientManager_getClientNames_result& operator=(const UtsClientManager_getClientNames_result&);
  UtsClientManager_getClientNames_result() {
  }

  virtual ~UtsClientManager_getClientNames_result() noexcept;
  std::vector<std::string>  success;

  _UtsClientManager_getClientNames_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  bool operator == (const UtsClientManager_getClientNames_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UtsClientManager_getClientNames_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtsClientManager_getClientNames_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtsClientManager_getClientNames_presult__isset {
  _UtsClientManager_getClientNames_presult__isset() : success(false) {}
  bool success :1;
} _UtsClientManager_getClientNames_presult__isset;

class UtsClientManager_getClientNames_presult {
 public:


  virtual ~UtsClientManager_getClientNames_presult() noexcept;
  std::vector<std::string> * success;

  _UtsClientManager_getClientNames_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class UtsClientManagerClient : virtual public UtsClientManagerIf {
 public:
  UtsClientManagerClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  UtsClientManagerClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void getClientNames(std::vector<std::string> & _return);
  void send_getClientNames();
  void recv_getClientNames(std::vector<std::string> & _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class UtsClientManagerProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<UtsClientManagerIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (UtsClientManagerProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_registerClient(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_registerSecureClient(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getClientNames(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  UtsClientManagerProcessor(::std::shared_ptr<UtsClientManagerIf> iface) :
    iface_(iface) {
    processMap_["registerClient"] = &UtsClientManagerProcessor::process_registerClient;
    processMap_["registerSecureClient"] = &UtsClientManagerProcessor::process_registerSecureClient;
    processMap_["getClientNames"] = &UtsClientManagerProcessor::process_getClientNames;
  }

  virtual ~UtsClientManagerProcessor() {}
};

class UtsClientManagerProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  UtsClientManagerProcessorFactory(const ::std::shared_ptr< UtsClientManagerIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< UtsClientManagerIfFactory > handlerFactory_;
};

class UtsClientManagerMultiface : virtual public UtsClientManagerIf {
 public:
  UtsClientManagerMultiface(std::vector<std::shared_ptr<UtsClientManagerIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~UtsClientManagerMultiface() {}
 protected:
  std::vector<std::shared_ptr<UtsClientManagerIf> > ifaces_;
  UtsClientManagerMultiface() {}
  void add(::std::shared_ptr<UtsClientManagerIf> iface) {
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

  void getClientNames(std::vector<std::string> & _return) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getClientNames(_return);
    }
    ifaces_[i]->getClientNames(_return);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class UtsClientManagerConcurrentClient : virtual public UtsClientManagerIf {
 public:
  UtsClientManagerConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  UtsClientManagerConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
  void getClientNames(std::vector<std::string> & _return);
  int32_t send_getClientNames();
  void recv_getClientNames(std::vector<std::string> & _return, const int32_t seqid);
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
