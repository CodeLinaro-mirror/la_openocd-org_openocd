/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef UtilityService_H
#define UtilityService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "UtilityService_types.h"

namespace Uts {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class UtilityServiceIf {
 public:
  virtual ~UtilityServiceIf() {}
  virtual void getLastError( ::Uts::ErrorType& _return) = 0;
  virtual void qmiPack(std::string& _return, const std::string& serviceIdOrName, const std::string& messageIdOrName, const std::string& xmlRequest) = 0;
  virtual void qmiUnPack( ::Uts::QmiUnpackReturn& _return, const std::string& serviceIdOrName, const std::string& input) = 0;
  virtual void nvGetAllItems(std::vector< ::Uts::NvItem> & _return) = 0;
  virtual void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId) = 0;
  virtual  ::Uts::ErrorCode::type createDigestsForVipDownload(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath) = 0;
  virtual  ::Uts::ErrorCode::type createDigestsForBuildValidation(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath) = 0;
  virtual void generateCfg(std::string& _return, const  ::Uts::DiagPacketMap& mask, const  ::Uts::LogMaskFormat::type format) = 0;
  virtual void convertToHdf(std::vector<std::string> & _return, const std::vector<std::string> & logFiles, const std::string& saveFolder) = 0;
  virtual void qcnDiff( ::Uts::QcnDiffResult& _return, const std::string& xqcnContents1, const std::string& xqcnContents2, const bool showSame) = 0;
  virtual void extractFromCfg( ::Uts::DiagPacketMap& _return, const std::string& cfgContents, const  ::Uts::LogMaskFormat::type format) = 0;
  virtual void extractFromAwsi( ::Uts::DiagPacketMap& _return, const std::string& awsiContents) = 0;
  virtual int32_t getDiagId(const  ::Uts::DiagPacketType::type packetType, const std::string& idOrName) = 0;
  virtual int32_t getQmiId(const  ::Uts::QmiPacketType::type packetType, const std::string& idOrName) = 0;
  virtual int32_t getSaharaId(const std::string& idOrName) = 0;
  virtual void deserializeXqcnXml( ::Uts::QcnContent& _return, const std::string& xqcnFileContents) = 0;
  virtual void serializeXqcnXml(std::string& _return, const  ::Uts::QcnContent& xqcnContents) = 0;
  virtual void deserializeNvItem(NvParserResult& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const int8_t index, const  ::Uts::NvReturns& returnConfig, const std::string& payload) = 0;
  virtual void serializeNvItem(std::string& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const std::string& valueList) = 0;
  virtual  ::Uts::ErrorCode::type compressEncryptedFile(const std::string& originalFile, const std::string& outputFile) = 0;
  virtual void parseMBN( ::Uts::MbnDiffResult& _return, const std::string& mbnOrXmlPath) = 0;
};

class UtilityServiceIfFactory {
 public:
  typedef UtilityServiceIf Handler;

  virtual ~UtilityServiceIfFactory() {}

  virtual UtilityServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(UtilityServiceIf* /* handler */) = 0;
};

class UtilityServiceIfSingletonFactory : virtual public UtilityServiceIfFactory {
 public:
  UtilityServiceIfSingletonFactory(const ::std::shared_ptr<UtilityServiceIf>& iface) : iface_(iface) {}
  virtual ~UtilityServiceIfSingletonFactory() {}

  virtual UtilityServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(UtilityServiceIf* /* handler */) {}

 protected:
  ::std::shared_ptr<UtilityServiceIf> iface_;
};

class UtilityServiceNull : virtual public UtilityServiceIf {
 public:
  virtual ~UtilityServiceNull() {}
  void getLastError( ::Uts::ErrorType& /* _return */) {
    return;
  }
  void qmiPack(std::string& /* _return */, const std::string& /* serviceIdOrName */, const std::string& /* messageIdOrName */, const std::string& /* xmlRequest */) {
    return;
  }
  void qmiUnPack( ::Uts::QmiUnpackReturn& /* _return */, const std::string& /* serviceIdOrName */, const std::string& /* input */) {
    return;
  }
  void nvGetAllItems(std::vector< ::Uts::NvItem> & /* _return */) {
    return;
  }
  void nvGetItemDefinition(std::string& /* _return */, const std::string& /* nvItemNameOrId */) {
    return;
  }
   ::Uts::ErrorCode::type createDigestsForVipDownload(const std::string& /* buildPath */, const  ::Uts::DownloadBuildOptions& /* options */, const std::string& /* outputPath */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
   ::Uts::ErrorCode::type createDigestsForBuildValidation(const std::string& /* buildPath */, const  ::Uts::DownloadBuildOptions& /* options */, const std::string& /* outputPath */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void generateCfg(std::string& /* _return */, const  ::Uts::DiagPacketMap& /* mask */, const  ::Uts::LogMaskFormat::type /* format */) {
    return;
  }
  void convertToHdf(std::vector<std::string> & /* _return */, const std::vector<std::string> & /* logFiles */, const std::string& /* saveFolder */) {
    return;
  }
  void qcnDiff( ::Uts::QcnDiffResult& /* _return */, const std::string& /* xqcnContents1 */, const std::string& /* xqcnContents2 */, const bool /* showSame */) {
    return;
  }
  void extractFromCfg( ::Uts::DiagPacketMap& /* _return */, const std::string& /* cfgContents */, const  ::Uts::LogMaskFormat::type /* format */) {
    return;
  }
  void extractFromAwsi( ::Uts::DiagPacketMap& /* _return */, const std::string& /* awsiContents */) {
    return;
  }
  int32_t getDiagId(const  ::Uts::DiagPacketType::type /* packetType */, const std::string& /* idOrName */) {
    int32_t _return = 0;
    return _return;
  }
  int32_t getQmiId(const  ::Uts::QmiPacketType::type /* packetType */, const std::string& /* idOrName */) {
    int32_t _return = 0;
    return _return;
  }
  int32_t getSaharaId(const std::string& /* idOrName */) {
    int32_t _return = 0;
    return _return;
  }
  void deserializeXqcnXml( ::Uts::QcnContent& /* _return */, const std::string& /* xqcnFileContents */) {
    return;
  }
  void serializeXqcnXml(std::string& /* _return */, const  ::Uts::QcnContent& /* xqcnContents */) {
    return;
  }
  void deserializeNvItem(NvParserResult& /* _return */, const std::string& /* nvIdOrEfsPath */, const int32_t /* subscriptionId */, const int8_t /* index */, const  ::Uts::NvReturns& /* returnConfig */, const std::string& /* payload */) {
    return;
  }
  void serializeNvItem(std::string& /* _return */, const std::string& /* nvIdOrEfsPath */, const int32_t /* subscriptionId */, const std::string& /* valueList */) {
    return;
  }
   ::Uts::ErrorCode::type compressEncryptedFile(const std::string& /* originalFile */, const std::string& /* outputFile */) {
     ::Uts::ErrorCode::type _return = ( ::Uts::ErrorCode::type)0;
    return _return;
  }
  void parseMBN( ::Uts::MbnDiffResult& /* _return */, const std::string& /* mbnOrXmlPath */) {
    return;
  }
};


class UtilityService_getLastError_args {
 public:

  UtilityService_getLastError_args(const UtilityService_getLastError_args&);
  UtilityService_getLastError_args& operator=(const UtilityService_getLastError_args&);
  UtilityService_getLastError_args() {
  }

  virtual ~UtilityService_getLastError_args() noexcept;

  bool operator == (const UtilityService_getLastError_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const UtilityService_getLastError_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_getLastError_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_getLastError_pargs {
 public:


  virtual ~UtilityService_getLastError_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_getLastError_result__isset {
  _UtilityService_getLastError_result__isset() : success(false) {}
  bool success :1;
} _UtilityService_getLastError_result__isset;

class UtilityService_getLastError_result {
 public:

  UtilityService_getLastError_result(const UtilityService_getLastError_result&);
  UtilityService_getLastError_result& operator=(const UtilityService_getLastError_result&);
  UtilityService_getLastError_result() {
  }

  virtual ~UtilityService_getLastError_result() noexcept;
   ::Uts::ErrorType success;

  _UtilityService_getLastError_result__isset __isset;

  void __set_success(const  ::Uts::ErrorType& val);

  bool operator == (const UtilityService_getLastError_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UtilityService_getLastError_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_getLastError_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_getLastError_presult__isset {
  _UtilityService_getLastError_presult__isset() : success(false) {}
  bool success :1;
} _UtilityService_getLastError_presult__isset;

class UtilityService_getLastError_presult {
 public:


  virtual ~UtilityService_getLastError_presult() noexcept;
   ::Uts::ErrorType* success;

  _UtilityService_getLastError_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_qmiPack_args__isset {
  _UtilityService_qmiPack_args__isset() : serviceIdOrName(false), messageIdOrName(false), xmlRequest(false) {}
  bool serviceIdOrName :1;
  bool messageIdOrName :1;
  bool xmlRequest :1;
} _UtilityService_qmiPack_args__isset;

class UtilityService_qmiPack_args {
 public:

  UtilityService_qmiPack_args(const UtilityService_qmiPack_args&);
  UtilityService_qmiPack_args& operator=(const UtilityService_qmiPack_args&);
  UtilityService_qmiPack_args() : serviceIdOrName(), messageIdOrName(), xmlRequest() {
  }

  virtual ~UtilityService_qmiPack_args() noexcept;
  std::string serviceIdOrName;
  std::string messageIdOrName;
  std::string xmlRequest;

  _UtilityService_qmiPack_args__isset __isset;

  void __set_serviceIdOrName(const std::string& val);

  void __set_messageIdOrName(const std::string& val);

  void __set_xmlRequest(const std::string& val);

  bool operator == (const UtilityService_qmiPack_args & rhs) const
  {
    if (!(serviceIdOrName == rhs.serviceIdOrName))
      return false;
    if (!(messageIdOrName == rhs.messageIdOrName))
      return false;
    if (!(xmlRequest == rhs.xmlRequest))
      return false;
    return true;
  }
  bool operator != (const UtilityService_qmiPack_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_qmiPack_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_qmiPack_pargs {
 public:


  virtual ~UtilityService_qmiPack_pargs() noexcept;
  const std::string* serviceIdOrName;
  const std::string* messageIdOrName;
  const std::string* xmlRequest;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_qmiPack_result__isset {
  _UtilityService_qmiPack_result__isset() : success(false) {}
  bool success :1;
} _UtilityService_qmiPack_result__isset;

class UtilityService_qmiPack_result {
 public:

  UtilityService_qmiPack_result(const UtilityService_qmiPack_result&);
  UtilityService_qmiPack_result& operator=(const UtilityService_qmiPack_result&);
  UtilityService_qmiPack_result() : success() {
  }

  virtual ~UtilityService_qmiPack_result() noexcept;
  std::string success;

  _UtilityService_qmiPack_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const UtilityService_qmiPack_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UtilityService_qmiPack_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_qmiPack_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_qmiPack_presult__isset {
  _UtilityService_qmiPack_presult__isset() : success(false) {}
  bool success :1;
} _UtilityService_qmiPack_presult__isset;

class UtilityService_qmiPack_presult {
 public:


  virtual ~UtilityService_qmiPack_presult() noexcept;
  std::string* success;

  _UtilityService_qmiPack_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_qmiUnPack_args__isset {
  _UtilityService_qmiUnPack_args__isset() : serviceIdOrName(false), input(false) {}
  bool serviceIdOrName :1;
  bool input :1;
} _UtilityService_qmiUnPack_args__isset;

class UtilityService_qmiUnPack_args {
 public:

  UtilityService_qmiUnPack_args(const UtilityService_qmiUnPack_args&);
  UtilityService_qmiUnPack_args& operator=(const UtilityService_qmiUnPack_args&);
  UtilityService_qmiUnPack_args() : serviceIdOrName(), input() {
  }

  virtual ~UtilityService_qmiUnPack_args() noexcept;
  std::string serviceIdOrName;
  std::string input;

  _UtilityService_qmiUnPack_args__isset __isset;

  void __set_serviceIdOrName(const std::string& val);

  void __set_input(const std::string& val);

  bool operator == (const UtilityService_qmiUnPack_args & rhs) const
  {
    if (!(serviceIdOrName == rhs.serviceIdOrName))
      return false;
    if (!(input == rhs.input))
      return false;
    return true;
  }
  bool operator != (const UtilityService_qmiUnPack_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_qmiUnPack_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_qmiUnPack_pargs {
 public:


  virtual ~UtilityService_qmiUnPack_pargs() noexcept;
  const std::string* serviceIdOrName;
  const std::string* input;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_qmiUnPack_result__isset {
  _UtilityService_qmiUnPack_result__isset() : success(false) {}
  bool success :1;
} _UtilityService_qmiUnPack_result__isset;

class UtilityService_qmiUnPack_result {
 public:

  UtilityService_qmiUnPack_result(const UtilityService_qmiUnPack_result&);
  UtilityService_qmiUnPack_result& operator=(const UtilityService_qmiUnPack_result&);
  UtilityService_qmiUnPack_result() {
  }

  virtual ~UtilityService_qmiUnPack_result() noexcept;
   ::Uts::QmiUnpackReturn success;

  _UtilityService_qmiUnPack_result__isset __isset;

  void __set_success(const  ::Uts::QmiUnpackReturn& val);

  bool operator == (const UtilityService_qmiUnPack_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UtilityService_qmiUnPack_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_qmiUnPack_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_qmiUnPack_presult__isset {
  _UtilityService_qmiUnPack_presult__isset() : success(false) {}
  bool success :1;
} _UtilityService_qmiUnPack_presult__isset;

class UtilityService_qmiUnPack_presult {
 public:


  virtual ~UtilityService_qmiUnPack_presult() noexcept;
   ::Uts::QmiUnpackReturn* success;

  _UtilityService_qmiUnPack_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};


class UtilityService_nvGetAllItems_args {
 public:

  UtilityService_nvGetAllItems_args(const UtilityService_nvGetAllItems_args&);
  UtilityService_nvGetAllItems_args& operator=(const UtilityService_nvGetAllItems_args&);
  UtilityService_nvGetAllItems_args() {
  }

  virtual ~UtilityService_nvGetAllItems_args() noexcept;

  bool operator == (const UtilityService_nvGetAllItems_args & /* rhs */) const
  {
    return true;
  }
  bool operator != (const UtilityService_nvGetAllItems_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_nvGetAllItems_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_nvGetAllItems_pargs {
 public:


  virtual ~UtilityService_nvGetAllItems_pargs() noexcept;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_nvGetAllItems_result__isset {
  _UtilityService_nvGetAllItems_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_nvGetAllItems_result__isset;

class UtilityService_nvGetAllItems_result {
 public:

  UtilityService_nvGetAllItems_result(const UtilityService_nvGetAllItems_result&);
  UtilityService_nvGetAllItems_result& operator=(const UtilityService_nvGetAllItems_result&);
  UtilityService_nvGetAllItems_result() {
  }

  virtual ~UtilityService_nvGetAllItems_result() noexcept;
  std::vector< ::Uts::NvItem>  success;
   ::Uts::AppException e;

  _UtilityService_nvGetAllItems_result__isset __isset;

  void __set_success(const std::vector< ::Uts::NvItem> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_nvGetAllItems_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_nvGetAllItems_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_nvGetAllItems_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_nvGetAllItems_presult__isset {
  _UtilityService_nvGetAllItems_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_nvGetAllItems_presult__isset;

class UtilityService_nvGetAllItems_presult {
 public:


  virtual ~UtilityService_nvGetAllItems_presult() noexcept;
  std::vector< ::Uts::NvItem> * success;
   ::Uts::AppException e;

  _UtilityService_nvGetAllItems_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_nvGetItemDefinition_args__isset {
  _UtilityService_nvGetItemDefinition_args__isset() : nvItemNameOrId(false) {}
  bool nvItemNameOrId :1;
} _UtilityService_nvGetItemDefinition_args__isset;

class UtilityService_nvGetItemDefinition_args {
 public:

  UtilityService_nvGetItemDefinition_args(const UtilityService_nvGetItemDefinition_args&);
  UtilityService_nvGetItemDefinition_args& operator=(const UtilityService_nvGetItemDefinition_args&);
  UtilityService_nvGetItemDefinition_args() : nvItemNameOrId() {
  }

  virtual ~UtilityService_nvGetItemDefinition_args() noexcept;
  std::string nvItemNameOrId;

  _UtilityService_nvGetItemDefinition_args__isset __isset;

  void __set_nvItemNameOrId(const std::string& val);

  bool operator == (const UtilityService_nvGetItemDefinition_args & rhs) const
  {
    if (!(nvItemNameOrId == rhs.nvItemNameOrId))
      return false;
    return true;
  }
  bool operator != (const UtilityService_nvGetItemDefinition_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_nvGetItemDefinition_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_nvGetItemDefinition_pargs {
 public:


  virtual ~UtilityService_nvGetItemDefinition_pargs() noexcept;
  const std::string* nvItemNameOrId;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_nvGetItemDefinition_result__isset {
  _UtilityService_nvGetItemDefinition_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_nvGetItemDefinition_result__isset;

class UtilityService_nvGetItemDefinition_result {
 public:

  UtilityService_nvGetItemDefinition_result(const UtilityService_nvGetItemDefinition_result&);
  UtilityService_nvGetItemDefinition_result& operator=(const UtilityService_nvGetItemDefinition_result&);
  UtilityService_nvGetItemDefinition_result() : success() {
  }

  virtual ~UtilityService_nvGetItemDefinition_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _UtilityService_nvGetItemDefinition_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_nvGetItemDefinition_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_nvGetItemDefinition_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_nvGetItemDefinition_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_nvGetItemDefinition_presult__isset {
  _UtilityService_nvGetItemDefinition_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_nvGetItemDefinition_presult__isset;

class UtilityService_nvGetItemDefinition_presult {
 public:


  virtual ~UtilityService_nvGetItemDefinition_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _UtilityService_nvGetItemDefinition_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_createDigestsForVipDownload_args__isset {
  _UtilityService_createDigestsForVipDownload_args__isset() : buildPath(false), options(false), outputPath(false) {}
  bool buildPath :1;
  bool options :1;
  bool outputPath :1;
} _UtilityService_createDigestsForVipDownload_args__isset;

class UtilityService_createDigestsForVipDownload_args {
 public:

  UtilityService_createDigestsForVipDownload_args(const UtilityService_createDigestsForVipDownload_args&);
  UtilityService_createDigestsForVipDownload_args& operator=(const UtilityService_createDigestsForVipDownload_args&);
  UtilityService_createDigestsForVipDownload_args() : buildPath(), outputPath() {
  }

  virtual ~UtilityService_createDigestsForVipDownload_args() noexcept;
  std::string buildPath;
   ::Uts::DownloadBuildOptions options;
  std::string outputPath;

  _UtilityService_createDigestsForVipDownload_args__isset __isset;

  void __set_buildPath(const std::string& val);

  void __set_options(const  ::Uts::DownloadBuildOptions& val);

  void __set_outputPath(const std::string& val);

  bool operator == (const UtilityService_createDigestsForVipDownload_args & rhs) const
  {
    if (!(buildPath == rhs.buildPath))
      return false;
    if (!(options == rhs.options))
      return false;
    if (!(outputPath == rhs.outputPath))
      return false;
    return true;
  }
  bool operator != (const UtilityService_createDigestsForVipDownload_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_createDigestsForVipDownload_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_createDigestsForVipDownload_pargs {
 public:


  virtual ~UtilityService_createDigestsForVipDownload_pargs() noexcept;
  const std::string* buildPath;
  const  ::Uts::DownloadBuildOptions* options;
  const std::string* outputPath;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_createDigestsForVipDownload_result__isset {
  _UtilityService_createDigestsForVipDownload_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_createDigestsForVipDownload_result__isset;

class UtilityService_createDigestsForVipDownload_result {
 public:

  UtilityService_createDigestsForVipDownload_result(const UtilityService_createDigestsForVipDownload_result&);
  UtilityService_createDigestsForVipDownload_result& operator=(const UtilityService_createDigestsForVipDownload_result&);
  UtilityService_createDigestsForVipDownload_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~UtilityService_createDigestsForVipDownload_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _UtilityService_createDigestsForVipDownload_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_createDigestsForVipDownload_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_createDigestsForVipDownload_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_createDigestsForVipDownload_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_createDigestsForVipDownload_presult__isset {
  _UtilityService_createDigestsForVipDownload_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_createDigestsForVipDownload_presult__isset;

class UtilityService_createDigestsForVipDownload_presult {
 public:


  virtual ~UtilityService_createDigestsForVipDownload_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _UtilityService_createDigestsForVipDownload_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_createDigestsForBuildValidation_args__isset {
  _UtilityService_createDigestsForBuildValidation_args__isset() : buildPath(false), options(false), outputPath(false) {}
  bool buildPath :1;
  bool options :1;
  bool outputPath :1;
} _UtilityService_createDigestsForBuildValidation_args__isset;

class UtilityService_createDigestsForBuildValidation_args {
 public:

  UtilityService_createDigestsForBuildValidation_args(const UtilityService_createDigestsForBuildValidation_args&);
  UtilityService_createDigestsForBuildValidation_args& operator=(const UtilityService_createDigestsForBuildValidation_args&);
  UtilityService_createDigestsForBuildValidation_args() : buildPath(), outputPath() {
  }

  virtual ~UtilityService_createDigestsForBuildValidation_args() noexcept;
  std::string buildPath;
   ::Uts::DownloadBuildOptions options;
  std::string outputPath;

  _UtilityService_createDigestsForBuildValidation_args__isset __isset;

  void __set_buildPath(const std::string& val);

  void __set_options(const  ::Uts::DownloadBuildOptions& val);

  void __set_outputPath(const std::string& val);

  bool operator == (const UtilityService_createDigestsForBuildValidation_args & rhs) const
  {
    if (!(buildPath == rhs.buildPath))
      return false;
    if (!(options == rhs.options))
      return false;
    if (!(outputPath == rhs.outputPath))
      return false;
    return true;
  }
  bool operator != (const UtilityService_createDigestsForBuildValidation_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_createDigestsForBuildValidation_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_createDigestsForBuildValidation_pargs {
 public:


  virtual ~UtilityService_createDigestsForBuildValidation_pargs() noexcept;
  const std::string* buildPath;
  const  ::Uts::DownloadBuildOptions* options;
  const std::string* outputPath;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_createDigestsForBuildValidation_result__isset {
  _UtilityService_createDigestsForBuildValidation_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_createDigestsForBuildValidation_result__isset;

class UtilityService_createDigestsForBuildValidation_result {
 public:

  UtilityService_createDigestsForBuildValidation_result(const UtilityService_createDigestsForBuildValidation_result&);
  UtilityService_createDigestsForBuildValidation_result& operator=(const UtilityService_createDigestsForBuildValidation_result&);
  UtilityService_createDigestsForBuildValidation_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~UtilityService_createDigestsForBuildValidation_result() noexcept;
   ::Uts::ErrorCode::type success;
   ::Uts::AppException e;

  _UtilityService_createDigestsForBuildValidation_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_createDigestsForBuildValidation_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_createDigestsForBuildValidation_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_createDigestsForBuildValidation_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_createDigestsForBuildValidation_presult__isset {
  _UtilityService_createDigestsForBuildValidation_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_createDigestsForBuildValidation_presult__isset;

class UtilityService_createDigestsForBuildValidation_presult {
 public:


  virtual ~UtilityService_createDigestsForBuildValidation_presult() noexcept;
   ::Uts::ErrorCode::type* success;
   ::Uts::AppException e;

  _UtilityService_createDigestsForBuildValidation_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_generateCfg_args__isset {
  _UtilityService_generateCfg_args__isset() : mask(false), format(false) {}
  bool mask :1;
  bool format :1;
} _UtilityService_generateCfg_args__isset;

class UtilityService_generateCfg_args {
 public:

  UtilityService_generateCfg_args(const UtilityService_generateCfg_args&);
  UtilityService_generateCfg_args& operator=(const UtilityService_generateCfg_args&);
  UtilityService_generateCfg_args() : format(( ::Uts::LogMaskFormat::type)0) {
  }

  virtual ~UtilityService_generateCfg_args() noexcept;
   ::Uts::DiagPacketMap mask;
   ::Uts::LogMaskFormat::type format;

  _UtilityService_generateCfg_args__isset __isset;

  void __set_mask(const  ::Uts::DiagPacketMap& val);

  void __set_format(const  ::Uts::LogMaskFormat::type val);

  bool operator == (const UtilityService_generateCfg_args & rhs) const
  {
    if (!(mask == rhs.mask))
      return false;
    if (!(format == rhs.format))
      return false;
    return true;
  }
  bool operator != (const UtilityService_generateCfg_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_generateCfg_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_generateCfg_pargs {
 public:


  virtual ~UtilityService_generateCfg_pargs() noexcept;
  const  ::Uts::DiagPacketMap* mask;
  const  ::Uts::LogMaskFormat::type* format;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_generateCfg_result__isset {
  _UtilityService_generateCfg_result__isset() : success(false) {}
  bool success :1;
} _UtilityService_generateCfg_result__isset;

class UtilityService_generateCfg_result {
 public:

  UtilityService_generateCfg_result(const UtilityService_generateCfg_result&);
  UtilityService_generateCfg_result& operator=(const UtilityService_generateCfg_result&);
  UtilityService_generateCfg_result() : success() {
  }

  virtual ~UtilityService_generateCfg_result() noexcept;
  std::string success;

  _UtilityService_generateCfg_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const UtilityService_generateCfg_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UtilityService_generateCfg_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_generateCfg_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_generateCfg_presult__isset {
  _UtilityService_generateCfg_presult__isset() : success(false) {}
  bool success :1;
} _UtilityService_generateCfg_presult__isset;

class UtilityService_generateCfg_presult {
 public:


  virtual ~UtilityService_generateCfg_presult() noexcept;
  std::string* success;

  _UtilityService_generateCfg_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_convertToHdf_args__isset {
  _UtilityService_convertToHdf_args__isset() : logFiles(false), saveFolder(false) {}
  bool logFiles :1;
  bool saveFolder :1;
} _UtilityService_convertToHdf_args__isset;

class UtilityService_convertToHdf_args {
 public:

  UtilityService_convertToHdf_args(const UtilityService_convertToHdf_args&);
  UtilityService_convertToHdf_args& operator=(const UtilityService_convertToHdf_args&);
  UtilityService_convertToHdf_args() : saveFolder() {
  }

  virtual ~UtilityService_convertToHdf_args() noexcept;
  std::vector<std::string>  logFiles;
  std::string saveFolder;

  _UtilityService_convertToHdf_args__isset __isset;

  void __set_logFiles(const std::vector<std::string> & val);

  void __set_saveFolder(const std::string& val);

  bool operator == (const UtilityService_convertToHdf_args & rhs) const
  {
    if (!(logFiles == rhs.logFiles))
      return false;
    if (!(saveFolder == rhs.saveFolder))
      return false;
    return true;
  }
  bool operator != (const UtilityService_convertToHdf_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_convertToHdf_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_convertToHdf_pargs {
 public:


  virtual ~UtilityService_convertToHdf_pargs() noexcept;
  const std::vector<std::string> * logFiles;
  const std::string* saveFolder;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_convertToHdf_result__isset {
  _UtilityService_convertToHdf_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_convertToHdf_result__isset;

class UtilityService_convertToHdf_result {
 public:

  UtilityService_convertToHdf_result(const UtilityService_convertToHdf_result&);
  UtilityService_convertToHdf_result& operator=(const UtilityService_convertToHdf_result&);
  UtilityService_convertToHdf_result() {
  }

  virtual ~UtilityService_convertToHdf_result() noexcept;
  std::vector<std::string>  success;
   ::Uts::AppException e;

  _UtilityService_convertToHdf_result__isset __isset;

  void __set_success(const std::vector<std::string> & val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_convertToHdf_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_convertToHdf_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_convertToHdf_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_convertToHdf_presult__isset {
  _UtilityService_convertToHdf_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_convertToHdf_presult__isset;

class UtilityService_convertToHdf_presult {
 public:


  virtual ~UtilityService_convertToHdf_presult() noexcept;
  std::vector<std::string> * success;
   ::Uts::AppException e;

  _UtilityService_convertToHdf_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_qcnDiff_args__isset {
  _UtilityService_qcnDiff_args__isset() : xqcnContents1(false), xqcnContents2(false), showSame(false) {}
  bool xqcnContents1 :1;
  bool xqcnContents2 :1;
  bool showSame :1;
} _UtilityService_qcnDiff_args__isset;

class UtilityService_qcnDiff_args {
 public:

  UtilityService_qcnDiff_args(const UtilityService_qcnDiff_args&);
  UtilityService_qcnDiff_args& operator=(const UtilityService_qcnDiff_args&);
  UtilityService_qcnDiff_args() : xqcnContents1(), xqcnContents2(), showSame(0) {
  }

  virtual ~UtilityService_qcnDiff_args() noexcept;
  std::string xqcnContents1;
  std::string xqcnContents2;
  bool showSame;

  _UtilityService_qcnDiff_args__isset __isset;

  void __set_xqcnContents1(const std::string& val);

  void __set_xqcnContents2(const std::string& val);

  void __set_showSame(const bool val);

  bool operator == (const UtilityService_qcnDiff_args & rhs) const
  {
    if (!(xqcnContents1 == rhs.xqcnContents1))
      return false;
    if (!(xqcnContents2 == rhs.xqcnContents2))
      return false;
    if (!(showSame == rhs.showSame))
      return false;
    return true;
  }
  bool operator != (const UtilityService_qcnDiff_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_qcnDiff_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_qcnDiff_pargs {
 public:


  virtual ~UtilityService_qcnDiff_pargs() noexcept;
  const std::string* xqcnContents1;
  const std::string* xqcnContents2;
  const bool* showSame;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_qcnDiff_result__isset {
  _UtilityService_qcnDiff_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_qcnDiff_result__isset;

class UtilityService_qcnDiff_result {
 public:

  UtilityService_qcnDiff_result(const UtilityService_qcnDiff_result&);
  UtilityService_qcnDiff_result& operator=(const UtilityService_qcnDiff_result&);
  UtilityService_qcnDiff_result() {
  }

  virtual ~UtilityService_qcnDiff_result() noexcept;
   ::Uts::QcnDiffResult success;
   ::Uts::AppException e;

  _UtilityService_qcnDiff_result__isset __isset;

  void __set_success(const  ::Uts::QcnDiffResult& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_qcnDiff_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_qcnDiff_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_qcnDiff_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_qcnDiff_presult__isset {
  _UtilityService_qcnDiff_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_qcnDiff_presult__isset;

class UtilityService_qcnDiff_presult {
 public:


  virtual ~UtilityService_qcnDiff_presult() noexcept;
   ::Uts::QcnDiffResult* success;
   ::Uts::AppException e;

  _UtilityService_qcnDiff_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_extractFromCfg_args__isset {
  _UtilityService_extractFromCfg_args__isset() : cfgContents(false), format(false) {}
  bool cfgContents :1;
  bool format :1;
} _UtilityService_extractFromCfg_args__isset;

class UtilityService_extractFromCfg_args {
 public:

  UtilityService_extractFromCfg_args(const UtilityService_extractFromCfg_args&);
  UtilityService_extractFromCfg_args& operator=(const UtilityService_extractFromCfg_args&);
  UtilityService_extractFromCfg_args() : cfgContents(), format(( ::Uts::LogMaskFormat::type)0) {
  }

  virtual ~UtilityService_extractFromCfg_args() noexcept;
  std::string cfgContents;
   ::Uts::LogMaskFormat::type format;

  _UtilityService_extractFromCfg_args__isset __isset;

  void __set_cfgContents(const std::string& val);

  void __set_format(const  ::Uts::LogMaskFormat::type val);

  bool operator == (const UtilityService_extractFromCfg_args & rhs) const
  {
    if (!(cfgContents == rhs.cfgContents))
      return false;
    if (!(format == rhs.format))
      return false;
    return true;
  }
  bool operator != (const UtilityService_extractFromCfg_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_extractFromCfg_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_extractFromCfg_pargs {
 public:


  virtual ~UtilityService_extractFromCfg_pargs() noexcept;
  const std::string* cfgContents;
  const  ::Uts::LogMaskFormat::type* format;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_extractFromCfg_result__isset {
  _UtilityService_extractFromCfg_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_extractFromCfg_result__isset;

class UtilityService_extractFromCfg_result {
 public:

  UtilityService_extractFromCfg_result(const UtilityService_extractFromCfg_result&);
  UtilityService_extractFromCfg_result& operator=(const UtilityService_extractFromCfg_result&);
  UtilityService_extractFromCfg_result() {
  }

  virtual ~UtilityService_extractFromCfg_result() noexcept;
   ::Uts::DiagPacketMap success;
   ::Uts::AppException e;

  _UtilityService_extractFromCfg_result__isset __isset;

  void __set_success(const  ::Uts::DiagPacketMap& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_extractFromCfg_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_extractFromCfg_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_extractFromCfg_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_extractFromCfg_presult__isset {
  _UtilityService_extractFromCfg_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_extractFromCfg_presult__isset;

class UtilityService_extractFromCfg_presult {
 public:


  virtual ~UtilityService_extractFromCfg_presult() noexcept;
   ::Uts::DiagPacketMap* success;
   ::Uts::AppException e;

  _UtilityService_extractFromCfg_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_extractFromAwsi_args__isset {
  _UtilityService_extractFromAwsi_args__isset() : awsiContents(false) {}
  bool awsiContents :1;
} _UtilityService_extractFromAwsi_args__isset;

class UtilityService_extractFromAwsi_args {
 public:

  UtilityService_extractFromAwsi_args(const UtilityService_extractFromAwsi_args&);
  UtilityService_extractFromAwsi_args& operator=(const UtilityService_extractFromAwsi_args&);
  UtilityService_extractFromAwsi_args() : awsiContents() {
  }

  virtual ~UtilityService_extractFromAwsi_args() noexcept;
  std::string awsiContents;

  _UtilityService_extractFromAwsi_args__isset __isset;

  void __set_awsiContents(const std::string& val);

  bool operator == (const UtilityService_extractFromAwsi_args & rhs) const
  {
    if (!(awsiContents == rhs.awsiContents))
      return false;
    return true;
  }
  bool operator != (const UtilityService_extractFromAwsi_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_extractFromAwsi_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_extractFromAwsi_pargs {
 public:


  virtual ~UtilityService_extractFromAwsi_pargs() noexcept;
  const std::string* awsiContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_extractFromAwsi_result__isset {
  _UtilityService_extractFromAwsi_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_extractFromAwsi_result__isset;

class UtilityService_extractFromAwsi_result {
 public:

  UtilityService_extractFromAwsi_result(const UtilityService_extractFromAwsi_result&);
  UtilityService_extractFromAwsi_result& operator=(const UtilityService_extractFromAwsi_result&);
  UtilityService_extractFromAwsi_result() {
  }

  virtual ~UtilityService_extractFromAwsi_result() noexcept;
   ::Uts::DiagPacketMap success;
   ::Uts::AppException e;

  _UtilityService_extractFromAwsi_result__isset __isset;

  void __set_success(const  ::Uts::DiagPacketMap& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_extractFromAwsi_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_extractFromAwsi_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_extractFromAwsi_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_extractFromAwsi_presult__isset {
  _UtilityService_extractFromAwsi_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_extractFromAwsi_presult__isset;

class UtilityService_extractFromAwsi_presult {
 public:


  virtual ~UtilityService_extractFromAwsi_presult() noexcept;
   ::Uts::DiagPacketMap* success;
   ::Uts::AppException e;

  _UtilityService_extractFromAwsi_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_getDiagId_args__isset {
  _UtilityService_getDiagId_args__isset() : packetType(false), idOrName(false) {}
  bool packetType :1;
  bool idOrName :1;
} _UtilityService_getDiagId_args__isset;

class UtilityService_getDiagId_args {
 public:

  UtilityService_getDiagId_args(const UtilityService_getDiagId_args&);
  UtilityService_getDiagId_args& operator=(const UtilityService_getDiagId_args&);
  UtilityService_getDiagId_args() : packetType(( ::Uts::DiagPacketType::type)0), idOrName() {
  }

  virtual ~UtilityService_getDiagId_args() noexcept;
   ::Uts::DiagPacketType::type packetType;
  std::string idOrName;

  _UtilityService_getDiagId_args__isset __isset;

  void __set_packetType(const  ::Uts::DiagPacketType::type val);

  void __set_idOrName(const std::string& val);

  bool operator == (const UtilityService_getDiagId_args & rhs) const
  {
    if (!(packetType == rhs.packetType))
      return false;
    if (!(idOrName == rhs.idOrName))
      return false;
    return true;
  }
  bool operator != (const UtilityService_getDiagId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_getDiagId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_getDiagId_pargs {
 public:


  virtual ~UtilityService_getDiagId_pargs() noexcept;
  const  ::Uts::DiagPacketType::type* packetType;
  const std::string* idOrName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_getDiagId_result__isset {
  _UtilityService_getDiagId_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_getDiagId_result__isset;

class UtilityService_getDiagId_result {
 public:

  UtilityService_getDiagId_result(const UtilityService_getDiagId_result&);
  UtilityService_getDiagId_result& operator=(const UtilityService_getDiagId_result&);
  UtilityService_getDiagId_result() : success(0) {
  }

  virtual ~UtilityService_getDiagId_result() noexcept;
  int32_t success;
   ::Uts::AppException e;

  _UtilityService_getDiagId_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_getDiagId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_getDiagId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_getDiagId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_getDiagId_presult__isset {
  _UtilityService_getDiagId_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_getDiagId_presult__isset;

class UtilityService_getDiagId_presult {
 public:


  virtual ~UtilityService_getDiagId_presult() noexcept;
  int32_t* success;
   ::Uts::AppException e;

  _UtilityService_getDiagId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_getQmiId_args__isset {
  _UtilityService_getQmiId_args__isset() : packetType(false), idOrName(false) {}
  bool packetType :1;
  bool idOrName :1;
} _UtilityService_getQmiId_args__isset;

class UtilityService_getQmiId_args {
 public:

  UtilityService_getQmiId_args(const UtilityService_getQmiId_args&);
  UtilityService_getQmiId_args& operator=(const UtilityService_getQmiId_args&);
  UtilityService_getQmiId_args() : packetType(( ::Uts::QmiPacketType::type)0), idOrName() {
  }

  virtual ~UtilityService_getQmiId_args() noexcept;
   ::Uts::QmiPacketType::type packetType;
  std::string idOrName;

  _UtilityService_getQmiId_args__isset __isset;

  void __set_packetType(const  ::Uts::QmiPacketType::type val);

  void __set_idOrName(const std::string& val);

  bool operator == (const UtilityService_getQmiId_args & rhs) const
  {
    if (!(packetType == rhs.packetType))
      return false;
    if (!(idOrName == rhs.idOrName))
      return false;
    return true;
  }
  bool operator != (const UtilityService_getQmiId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_getQmiId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_getQmiId_pargs {
 public:


  virtual ~UtilityService_getQmiId_pargs() noexcept;
  const  ::Uts::QmiPacketType::type* packetType;
  const std::string* idOrName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_getQmiId_result__isset {
  _UtilityService_getQmiId_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_getQmiId_result__isset;

class UtilityService_getQmiId_result {
 public:

  UtilityService_getQmiId_result(const UtilityService_getQmiId_result&);
  UtilityService_getQmiId_result& operator=(const UtilityService_getQmiId_result&);
  UtilityService_getQmiId_result() : success(0) {
  }

  virtual ~UtilityService_getQmiId_result() noexcept;
  int32_t success;
   ::Uts::AppException e;

  _UtilityService_getQmiId_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_getQmiId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_getQmiId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_getQmiId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_getQmiId_presult__isset {
  _UtilityService_getQmiId_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_getQmiId_presult__isset;

class UtilityService_getQmiId_presult {
 public:


  virtual ~UtilityService_getQmiId_presult() noexcept;
  int32_t* success;
   ::Uts::AppException e;

  _UtilityService_getQmiId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_getSaharaId_args__isset {
  _UtilityService_getSaharaId_args__isset() : idOrName(false) {}
  bool idOrName :1;
} _UtilityService_getSaharaId_args__isset;

class UtilityService_getSaharaId_args {
 public:

  UtilityService_getSaharaId_args(const UtilityService_getSaharaId_args&);
  UtilityService_getSaharaId_args& operator=(const UtilityService_getSaharaId_args&);
  UtilityService_getSaharaId_args() : idOrName() {
  }

  virtual ~UtilityService_getSaharaId_args() noexcept;
  std::string idOrName;

  _UtilityService_getSaharaId_args__isset __isset;

  void __set_idOrName(const std::string& val);

  bool operator == (const UtilityService_getSaharaId_args & rhs) const
  {
    if (!(idOrName == rhs.idOrName))
      return false;
    return true;
  }
  bool operator != (const UtilityService_getSaharaId_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_getSaharaId_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_getSaharaId_pargs {
 public:


  virtual ~UtilityService_getSaharaId_pargs() noexcept;
  const std::string* idOrName;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_getSaharaId_result__isset {
  _UtilityService_getSaharaId_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_getSaharaId_result__isset;

class UtilityService_getSaharaId_result {
 public:

  UtilityService_getSaharaId_result(const UtilityService_getSaharaId_result&);
  UtilityService_getSaharaId_result& operator=(const UtilityService_getSaharaId_result&);
  UtilityService_getSaharaId_result() : success(0) {
  }

  virtual ~UtilityService_getSaharaId_result() noexcept;
  int32_t success;
   ::Uts::AppException e;

  _UtilityService_getSaharaId_result__isset __isset;

  void __set_success(const int32_t val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_getSaharaId_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_getSaharaId_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_getSaharaId_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_getSaharaId_presult__isset {
  _UtilityService_getSaharaId_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_getSaharaId_presult__isset;

class UtilityService_getSaharaId_presult {
 public:


  virtual ~UtilityService_getSaharaId_presult() noexcept;
  int32_t* success;
   ::Uts::AppException e;

  _UtilityService_getSaharaId_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_deserializeXqcnXml_args__isset {
  _UtilityService_deserializeXqcnXml_args__isset() : xqcnFileContents(false) {}
  bool xqcnFileContents :1;
} _UtilityService_deserializeXqcnXml_args__isset;

class UtilityService_deserializeXqcnXml_args {
 public:

  UtilityService_deserializeXqcnXml_args(const UtilityService_deserializeXqcnXml_args&);
  UtilityService_deserializeXqcnXml_args& operator=(const UtilityService_deserializeXqcnXml_args&);
  UtilityService_deserializeXqcnXml_args() : xqcnFileContents() {
  }

  virtual ~UtilityService_deserializeXqcnXml_args() noexcept;
  std::string xqcnFileContents;

  _UtilityService_deserializeXqcnXml_args__isset __isset;

  void __set_xqcnFileContents(const std::string& val);

  bool operator == (const UtilityService_deserializeXqcnXml_args & rhs) const
  {
    if (!(xqcnFileContents == rhs.xqcnFileContents))
      return false;
    return true;
  }
  bool operator != (const UtilityService_deserializeXqcnXml_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_deserializeXqcnXml_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_deserializeXqcnXml_pargs {
 public:


  virtual ~UtilityService_deserializeXqcnXml_pargs() noexcept;
  const std::string* xqcnFileContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_deserializeXqcnXml_result__isset {
  _UtilityService_deserializeXqcnXml_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_deserializeXqcnXml_result__isset;

class UtilityService_deserializeXqcnXml_result {
 public:

  UtilityService_deserializeXqcnXml_result(const UtilityService_deserializeXqcnXml_result&);
  UtilityService_deserializeXqcnXml_result& operator=(const UtilityService_deserializeXqcnXml_result&);
  UtilityService_deserializeXqcnXml_result() {
  }

  virtual ~UtilityService_deserializeXqcnXml_result() noexcept;
   ::Uts::QcnContent success;
   ::Uts::AppException e;

  _UtilityService_deserializeXqcnXml_result__isset __isset;

  void __set_success(const  ::Uts::QcnContent& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_deserializeXqcnXml_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_deserializeXqcnXml_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_deserializeXqcnXml_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_deserializeXqcnXml_presult__isset {
  _UtilityService_deserializeXqcnXml_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_deserializeXqcnXml_presult__isset;

class UtilityService_deserializeXqcnXml_presult {
 public:


  virtual ~UtilityService_deserializeXqcnXml_presult() noexcept;
   ::Uts::QcnContent* success;
   ::Uts::AppException e;

  _UtilityService_deserializeXqcnXml_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_serializeXqcnXml_args__isset {
  _UtilityService_serializeXqcnXml_args__isset() : xqcnContents(false) {}
  bool xqcnContents :1;
} _UtilityService_serializeXqcnXml_args__isset;

class UtilityService_serializeXqcnXml_args {
 public:

  UtilityService_serializeXqcnXml_args(const UtilityService_serializeXqcnXml_args&);
  UtilityService_serializeXqcnXml_args& operator=(const UtilityService_serializeXqcnXml_args&);
  UtilityService_serializeXqcnXml_args() {
  }

  virtual ~UtilityService_serializeXqcnXml_args() noexcept;
   ::Uts::QcnContent xqcnContents;

  _UtilityService_serializeXqcnXml_args__isset __isset;

  void __set_xqcnContents(const  ::Uts::QcnContent& val);

  bool operator == (const UtilityService_serializeXqcnXml_args & rhs) const
  {
    if (!(xqcnContents == rhs.xqcnContents))
      return false;
    return true;
  }
  bool operator != (const UtilityService_serializeXqcnXml_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_serializeXqcnXml_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_serializeXqcnXml_pargs {
 public:


  virtual ~UtilityService_serializeXqcnXml_pargs() noexcept;
  const  ::Uts::QcnContent* xqcnContents;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_serializeXqcnXml_result__isset {
  _UtilityService_serializeXqcnXml_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_serializeXqcnXml_result__isset;

class UtilityService_serializeXqcnXml_result {
 public:

  UtilityService_serializeXqcnXml_result(const UtilityService_serializeXqcnXml_result&);
  UtilityService_serializeXqcnXml_result& operator=(const UtilityService_serializeXqcnXml_result&);
  UtilityService_serializeXqcnXml_result() : success() {
  }

  virtual ~UtilityService_serializeXqcnXml_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _UtilityService_serializeXqcnXml_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_serializeXqcnXml_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_serializeXqcnXml_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_serializeXqcnXml_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_serializeXqcnXml_presult__isset {
  _UtilityService_serializeXqcnXml_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_serializeXqcnXml_presult__isset;

class UtilityService_serializeXqcnXml_presult {
 public:


  virtual ~UtilityService_serializeXqcnXml_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _UtilityService_serializeXqcnXml_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_deserializeNvItem_args__isset {
  _UtilityService_deserializeNvItem_args__isset() : nvIdOrEfsPath(false), subscriptionId(false), index(false), returnConfig(false), payload(false) {}
  bool nvIdOrEfsPath :1;
  bool subscriptionId :1;
  bool index :1;
  bool returnConfig :1;
  bool payload :1;
} _UtilityService_deserializeNvItem_args__isset;

class UtilityService_deserializeNvItem_args {
 public:

  UtilityService_deserializeNvItem_args(const UtilityService_deserializeNvItem_args&);
  UtilityService_deserializeNvItem_args& operator=(const UtilityService_deserializeNvItem_args&);
  UtilityService_deserializeNvItem_args() : nvIdOrEfsPath(), subscriptionId(0), index(0), payload() {
  }

  virtual ~UtilityService_deserializeNvItem_args() noexcept;
  std::string nvIdOrEfsPath;
  int32_t subscriptionId;
  int8_t index;
   ::Uts::NvReturns returnConfig;
  std::string payload;

  _UtilityService_deserializeNvItem_args__isset __isset;

  void __set_nvIdOrEfsPath(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  void __set_index(const int8_t val);

  void __set_returnConfig(const  ::Uts::NvReturns& val);

  void __set_payload(const std::string& val);

  bool operator == (const UtilityService_deserializeNvItem_args & rhs) const
  {
    if (!(nvIdOrEfsPath == rhs.nvIdOrEfsPath))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(index == rhs.index))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    if (!(payload == rhs.payload))
      return false;
    return true;
  }
  bool operator != (const UtilityService_deserializeNvItem_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_deserializeNvItem_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_deserializeNvItem_pargs {
 public:


  virtual ~UtilityService_deserializeNvItem_pargs() noexcept;
  const std::string* nvIdOrEfsPath;
  const int32_t* subscriptionId;
  const int8_t* index;
  const  ::Uts::NvReturns* returnConfig;
  const std::string* payload;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_deserializeNvItem_result__isset {
  _UtilityService_deserializeNvItem_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_deserializeNvItem_result__isset;

class UtilityService_deserializeNvItem_result {
 public:

  UtilityService_deserializeNvItem_result(const UtilityService_deserializeNvItem_result&);
  UtilityService_deserializeNvItem_result& operator=(const UtilityService_deserializeNvItem_result&);
  UtilityService_deserializeNvItem_result() {
  }

  virtual ~UtilityService_deserializeNvItem_result() noexcept;
  NvParserResult success;
   ::Uts::AppException e;

  _UtilityService_deserializeNvItem_result__isset __isset;

  void __set_success(const NvParserResult& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_deserializeNvItem_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_deserializeNvItem_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_deserializeNvItem_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_deserializeNvItem_presult__isset {
  _UtilityService_deserializeNvItem_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_deserializeNvItem_presult__isset;

class UtilityService_deserializeNvItem_presult {
 public:


  virtual ~UtilityService_deserializeNvItem_presult() noexcept;
  NvParserResult* success;
   ::Uts::AppException e;

  _UtilityService_deserializeNvItem_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_serializeNvItem_args__isset {
  _UtilityService_serializeNvItem_args__isset() : nvIdOrEfsPath(false), subscriptionId(false), valueList(false) {}
  bool nvIdOrEfsPath :1;
  bool subscriptionId :1;
  bool valueList :1;
} _UtilityService_serializeNvItem_args__isset;

class UtilityService_serializeNvItem_args {
 public:

  UtilityService_serializeNvItem_args(const UtilityService_serializeNvItem_args&);
  UtilityService_serializeNvItem_args& operator=(const UtilityService_serializeNvItem_args&);
  UtilityService_serializeNvItem_args() : nvIdOrEfsPath(), subscriptionId(0), valueList() {
  }

  virtual ~UtilityService_serializeNvItem_args() noexcept;
  std::string nvIdOrEfsPath;
  int32_t subscriptionId;
  std::string valueList;

  _UtilityService_serializeNvItem_args__isset __isset;

  void __set_nvIdOrEfsPath(const std::string& val);

  void __set_subscriptionId(const int32_t val);

  void __set_valueList(const std::string& val);

  bool operator == (const UtilityService_serializeNvItem_args & rhs) const
  {
    if (!(nvIdOrEfsPath == rhs.nvIdOrEfsPath))
      return false;
    if (!(subscriptionId == rhs.subscriptionId))
      return false;
    if (!(valueList == rhs.valueList))
      return false;
    return true;
  }
  bool operator != (const UtilityService_serializeNvItem_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_serializeNvItem_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_serializeNvItem_pargs {
 public:


  virtual ~UtilityService_serializeNvItem_pargs() noexcept;
  const std::string* nvIdOrEfsPath;
  const int32_t* subscriptionId;
  const std::string* valueList;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_serializeNvItem_result__isset {
  _UtilityService_serializeNvItem_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_serializeNvItem_result__isset;

class UtilityService_serializeNvItem_result {
 public:

  UtilityService_serializeNvItem_result(const UtilityService_serializeNvItem_result&);
  UtilityService_serializeNvItem_result& operator=(const UtilityService_serializeNvItem_result&);
  UtilityService_serializeNvItem_result() : success() {
  }

  virtual ~UtilityService_serializeNvItem_result() noexcept;
  std::string success;
   ::Uts::AppException e;

  _UtilityService_serializeNvItem_result__isset __isset;

  void __set_success(const std::string& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_serializeNvItem_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_serializeNvItem_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_serializeNvItem_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_serializeNvItem_presult__isset {
  _UtilityService_serializeNvItem_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_serializeNvItem_presult__isset;

class UtilityService_serializeNvItem_presult {
 public:


  virtual ~UtilityService_serializeNvItem_presult() noexcept;
  std::string* success;
   ::Uts::AppException e;

  _UtilityService_serializeNvItem_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_compressEncryptedFile_args__isset {
  _UtilityService_compressEncryptedFile_args__isset() : originalFile(false), outputFile(false) {}
  bool originalFile :1;
  bool outputFile :1;
} _UtilityService_compressEncryptedFile_args__isset;

class UtilityService_compressEncryptedFile_args {
 public:

  UtilityService_compressEncryptedFile_args(const UtilityService_compressEncryptedFile_args&);
  UtilityService_compressEncryptedFile_args& operator=(const UtilityService_compressEncryptedFile_args&);
  UtilityService_compressEncryptedFile_args() : originalFile(), outputFile() {
  }

  virtual ~UtilityService_compressEncryptedFile_args() noexcept;
  std::string originalFile;
  std::string outputFile;

  _UtilityService_compressEncryptedFile_args__isset __isset;

  void __set_originalFile(const std::string& val);

  void __set_outputFile(const std::string& val);

  bool operator == (const UtilityService_compressEncryptedFile_args & rhs) const
  {
    if (!(originalFile == rhs.originalFile))
      return false;
    if (!(outputFile == rhs.outputFile))
      return false;
    return true;
  }
  bool operator != (const UtilityService_compressEncryptedFile_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_compressEncryptedFile_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_compressEncryptedFile_pargs {
 public:


  virtual ~UtilityService_compressEncryptedFile_pargs() noexcept;
  const std::string* originalFile;
  const std::string* outputFile;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_compressEncryptedFile_result__isset {
  _UtilityService_compressEncryptedFile_result__isset() : success(false) {}
  bool success :1;
} _UtilityService_compressEncryptedFile_result__isset;

class UtilityService_compressEncryptedFile_result {
 public:

  UtilityService_compressEncryptedFile_result(const UtilityService_compressEncryptedFile_result&);
  UtilityService_compressEncryptedFile_result& operator=(const UtilityService_compressEncryptedFile_result&);
  UtilityService_compressEncryptedFile_result() : success(( ::Uts::ErrorCode::type)0) {
  }

  virtual ~UtilityService_compressEncryptedFile_result() noexcept;
   ::Uts::ErrorCode::type success;

  _UtilityService_compressEncryptedFile_result__isset __isset;

  void __set_success(const  ::Uts::ErrorCode::type val);

  bool operator == (const UtilityService_compressEncryptedFile_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UtilityService_compressEncryptedFile_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_compressEncryptedFile_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_compressEncryptedFile_presult__isset {
  _UtilityService_compressEncryptedFile_presult__isset() : success(false) {}
  bool success :1;
} _UtilityService_compressEncryptedFile_presult__isset;

class UtilityService_compressEncryptedFile_presult {
 public:


  virtual ~UtilityService_compressEncryptedFile_presult() noexcept;
   ::Uts::ErrorCode::type* success;

  _UtilityService_compressEncryptedFile_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UtilityService_parseMBN_args__isset {
  _UtilityService_parseMBN_args__isset() : mbnOrXmlPath(false) {}
  bool mbnOrXmlPath :1;
} _UtilityService_parseMBN_args__isset;

class UtilityService_parseMBN_args {
 public:

  UtilityService_parseMBN_args(const UtilityService_parseMBN_args&);
  UtilityService_parseMBN_args& operator=(const UtilityService_parseMBN_args&);
  UtilityService_parseMBN_args() : mbnOrXmlPath() {
  }

  virtual ~UtilityService_parseMBN_args() noexcept;
  std::string mbnOrXmlPath;

  _UtilityService_parseMBN_args__isset __isset;

  void __set_mbnOrXmlPath(const std::string& val);

  bool operator == (const UtilityService_parseMBN_args & rhs) const
  {
    if (!(mbnOrXmlPath == rhs.mbnOrXmlPath))
      return false;
    return true;
  }
  bool operator != (const UtilityService_parseMBN_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_parseMBN_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UtilityService_parseMBN_pargs {
 public:


  virtual ~UtilityService_parseMBN_pargs() noexcept;
  const std::string* mbnOrXmlPath;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_parseMBN_result__isset {
  _UtilityService_parseMBN_result__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_parseMBN_result__isset;

class UtilityService_parseMBN_result {
 public:

  UtilityService_parseMBN_result(const UtilityService_parseMBN_result&);
  UtilityService_parseMBN_result& operator=(const UtilityService_parseMBN_result&);
  UtilityService_parseMBN_result() {
  }

  virtual ~UtilityService_parseMBN_result() noexcept;
   ::Uts::MbnDiffResult success;
   ::Uts::AppException e;

  _UtilityService_parseMBN_result__isset __isset;

  void __set_success(const  ::Uts::MbnDiffResult& val);

  void __set_e(const  ::Uts::AppException& val);

  bool operator == (const UtilityService_parseMBN_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    if (!(e == rhs.e))
      return false;
    return true;
  }
  bool operator != (const UtilityService_parseMBN_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UtilityService_parseMBN_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UtilityService_parseMBN_presult__isset {
  _UtilityService_parseMBN_presult__isset() : success(false), e(false) {}
  bool success :1;
  bool e :1;
} _UtilityService_parseMBN_presult__isset;

class UtilityService_parseMBN_presult {
 public:


  virtual ~UtilityService_parseMBN_presult() noexcept;
   ::Uts::MbnDiffResult* success;
   ::Uts::AppException e;

  _UtilityService_parseMBN_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class UtilityServiceClient : virtual public UtilityServiceIf {
 public:
  UtilityServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  UtilityServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void qmiPack(std::string& _return, const std::string& serviceIdOrName, const std::string& messageIdOrName, const std::string& xmlRequest);
  void send_qmiPack(const std::string& serviceIdOrName, const std::string& messageIdOrName, const std::string& xmlRequest);
  void recv_qmiPack(std::string& _return);
  void qmiUnPack( ::Uts::QmiUnpackReturn& _return, const std::string& serviceIdOrName, const std::string& input);
  void send_qmiUnPack(const std::string& serviceIdOrName, const std::string& input);
  void recv_qmiUnPack( ::Uts::QmiUnpackReturn& _return);
  void nvGetAllItems(std::vector< ::Uts::NvItem> & _return);
  void send_nvGetAllItems();
  void recv_nvGetAllItems(std::vector< ::Uts::NvItem> & _return);
  void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId);
  void send_nvGetItemDefinition(const std::string& nvItemNameOrId);
  void recv_nvGetItemDefinition(std::string& _return);
   ::Uts::ErrorCode::type createDigestsForVipDownload(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath);
  void send_createDigestsForVipDownload(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath);
   ::Uts::ErrorCode::type recv_createDigestsForVipDownload();
   ::Uts::ErrorCode::type createDigestsForBuildValidation(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath);
  void send_createDigestsForBuildValidation(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath);
   ::Uts::ErrorCode::type recv_createDigestsForBuildValidation();
  void generateCfg(std::string& _return, const  ::Uts::DiagPacketMap& mask, const  ::Uts::LogMaskFormat::type format);
  void send_generateCfg(const  ::Uts::DiagPacketMap& mask, const  ::Uts::LogMaskFormat::type format);
  void recv_generateCfg(std::string& _return);
  void convertToHdf(std::vector<std::string> & _return, const std::vector<std::string> & logFiles, const std::string& saveFolder);
  void send_convertToHdf(const std::vector<std::string> & logFiles, const std::string& saveFolder);
  void recv_convertToHdf(std::vector<std::string> & _return);
  void qcnDiff( ::Uts::QcnDiffResult& _return, const std::string& xqcnContents1, const std::string& xqcnContents2, const bool showSame);
  void send_qcnDiff(const std::string& xqcnContents1, const std::string& xqcnContents2, const bool showSame);
  void recv_qcnDiff( ::Uts::QcnDiffResult& _return);
  void extractFromCfg( ::Uts::DiagPacketMap& _return, const std::string& cfgContents, const  ::Uts::LogMaskFormat::type format);
  void send_extractFromCfg(const std::string& cfgContents, const  ::Uts::LogMaskFormat::type format);
  void recv_extractFromCfg( ::Uts::DiagPacketMap& _return);
  void extractFromAwsi( ::Uts::DiagPacketMap& _return, const std::string& awsiContents);
  void send_extractFromAwsi(const std::string& awsiContents);
  void recv_extractFromAwsi( ::Uts::DiagPacketMap& _return);
  int32_t getDiagId(const  ::Uts::DiagPacketType::type packetType, const std::string& idOrName);
  void send_getDiagId(const  ::Uts::DiagPacketType::type packetType, const std::string& idOrName);
  int32_t recv_getDiagId();
  int32_t getQmiId(const  ::Uts::QmiPacketType::type packetType, const std::string& idOrName);
  void send_getQmiId(const  ::Uts::QmiPacketType::type packetType, const std::string& idOrName);
  int32_t recv_getQmiId();
  int32_t getSaharaId(const std::string& idOrName);
  void send_getSaharaId(const std::string& idOrName);
  int32_t recv_getSaharaId();
  void deserializeXqcnXml( ::Uts::QcnContent& _return, const std::string& xqcnFileContents);
  void send_deserializeXqcnXml(const std::string& xqcnFileContents);
  void recv_deserializeXqcnXml( ::Uts::QcnContent& _return);
  void serializeXqcnXml(std::string& _return, const  ::Uts::QcnContent& xqcnContents);
  void send_serializeXqcnXml(const  ::Uts::QcnContent& xqcnContents);
  void recv_serializeXqcnXml(std::string& _return);
  void deserializeNvItem(NvParserResult& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const int8_t index, const  ::Uts::NvReturns& returnConfig, const std::string& payload);
  void send_deserializeNvItem(const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const int8_t index, const  ::Uts::NvReturns& returnConfig, const std::string& payload);
  void recv_deserializeNvItem(NvParserResult& _return);
  void serializeNvItem(std::string& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const std::string& valueList);
  void send_serializeNvItem(const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const std::string& valueList);
  void recv_serializeNvItem(std::string& _return);
   ::Uts::ErrorCode::type compressEncryptedFile(const std::string& originalFile, const std::string& outputFile);
  void send_compressEncryptedFile(const std::string& originalFile, const std::string& outputFile);
   ::Uts::ErrorCode::type recv_compressEncryptedFile();
  void parseMBN( ::Uts::MbnDiffResult& _return, const std::string& mbnOrXmlPath);
  void send_parseMBN(const std::string& mbnOrXmlPath);
  void recv_parseMBN( ::Uts::MbnDiffResult& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class UtilityServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<UtilityServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (UtilityServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_qmiPack(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_qmiUnPack(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_nvGetAllItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_nvGetItemDefinition(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createDigestsForVipDownload(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_createDigestsForBuildValidation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_generateCfg(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_convertToHdf(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_qcnDiff(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_extractFromCfg(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_extractFromAwsi(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getDiagId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getQmiId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_getSaharaId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_deserializeXqcnXml(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_serializeXqcnXml(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_deserializeNvItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_serializeNvItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_compressEncryptedFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_parseMBN(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  UtilityServiceProcessor(::std::shared_ptr<UtilityServiceIf> iface) :
    iface_(iface) {
    processMap_["getLastError"] = &UtilityServiceProcessor::process_getLastError;
    processMap_["qmiPack"] = &UtilityServiceProcessor::process_qmiPack;
    processMap_["qmiUnPack"] = &UtilityServiceProcessor::process_qmiUnPack;
    processMap_["nvGetAllItems"] = &UtilityServiceProcessor::process_nvGetAllItems;
    processMap_["nvGetItemDefinition"] = &UtilityServiceProcessor::process_nvGetItemDefinition;
    processMap_["createDigestsForVipDownload"] = &UtilityServiceProcessor::process_createDigestsForVipDownload;
    processMap_["createDigestsForBuildValidation"] = &UtilityServiceProcessor::process_createDigestsForBuildValidation;
    processMap_["generateCfg"] = &UtilityServiceProcessor::process_generateCfg;
    processMap_["convertToHdf"] = &UtilityServiceProcessor::process_convertToHdf;
    processMap_["qcnDiff"] = &UtilityServiceProcessor::process_qcnDiff;
    processMap_["extractFromCfg"] = &UtilityServiceProcessor::process_extractFromCfg;
    processMap_["extractFromAwsi"] = &UtilityServiceProcessor::process_extractFromAwsi;
    processMap_["getDiagId"] = &UtilityServiceProcessor::process_getDiagId;
    processMap_["getQmiId"] = &UtilityServiceProcessor::process_getQmiId;
    processMap_["getSaharaId"] = &UtilityServiceProcessor::process_getSaharaId;
    processMap_["deserializeXqcnXml"] = &UtilityServiceProcessor::process_deserializeXqcnXml;
    processMap_["serializeXqcnXml"] = &UtilityServiceProcessor::process_serializeXqcnXml;
    processMap_["deserializeNvItem"] = &UtilityServiceProcessor::process_deserializeNvItem;
    processMap_["serializeNvItem"] = &UtilityServiceProcessor::process_serializeNvItem;
    processMap_["compressEncryptedFile"] = &UtilityServiceProcessor::process_compressEncryptedFile;
    processMap_["parseMBN"] = &UtilityServiceProcessor::process_parseMBN;
  }

  virtual ~UtilityServiceProcessor() {}
};

class UtilityServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  UtilityServiceProcessorFactory(const ::std::shared_ptr< UtilityServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::std::shared_ptr< UtilityServiceIfFactory > handlerFactory_;
};

class UtilityServiceMultiface : virtual public UtilityServiceIf {
 public:
  UtilityServiceMultiface(std::vector<std::shared_ptr<UtilityServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~UtilityServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<UtilityServiceIf> > ifaces_;
  UtilityServiceMultiface() {}
  void add(::std::shared_ptr<UtilityServiceIf> iface) {
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

  void qmiPack(std::string& _return, const std::string& serviceIdOrName, const std::string& messageIdOrName, const std::string& xmlRequest) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->qmiPack(_return, serviceIdOrName, messageIdOrName, xmlRequest);
    }
    ifaces_[i]->qmiPack(_return, serviceIdOrName, messageIdOrName, xmlRequest);
    return;
  }

  void qmiUnPack( ::Uts::QmiUnpackReturn& _return, const std::string& serviceIdOrName, const std::string& input) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->qmiUnPack(_return, serviceIdOrName, input);
    }
    ifaces_[i]->qmiUnPack(_return, serviceIdOrName, input);
    return;
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

   ::Uts::ErrorCode::type createDigestsForVipDownload(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createDigestsForVipDownload(buildPath, options, outputPath);
    }
    return ifaces_[i]->createDigestsForVipDownload(buildPath, options, outputPath);
  }

   ::Uts::ErrorCode::type createDigestsForBuildValidation(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->createDigestsForBuildValidation(buildPath, options, outputPath);
    }
    return ifaces_[i]->createDigestsForBuildValidation(buildPath, options, outputPath);
  }

  void generateCfg(std::string& _return, const  ::Uts::DiagPacketMap& mask, const  ::Uts::LogMaskFormat::type format) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->generateCfg(_return, mask, format);
    }
    ifaces_[i]->generateCfg(_return, mask, format);
    return;
  }

  void convertToHdf(std::vector<std::string> & _return, const std::vector<std::string> & logFiles, const std::string& saveFolder) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->convertToHdf(_return, logFiles, saveFolder);
    }
    ifaces_[i]->convertToHdf(_return, logFiles, saveFolder);
    return;
  }

  void qcnDiff( ::Uts::QcnDiffResult& _return, const std::string& xqcnContents1, const std::string& xqcnContents2, const bool showSame) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->qcnDiff(_return, xqcnContents1, xqcnContents2, showSame);
    }
    ifaces_[i]->qcnDiff(_return, xqcnContents1, xqcnContents2, showSame);
    return;
  }

  void extractFromCfg( ::Uts::DiagPacketMap& _return, const std::string& cfgContents, const  ::Uts::LogMaskFormat::type format) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->extractFromCfg(_return, cfgContents, format);
    }
    ifaces_[i]->extractFromCfg(_return, cfgContents, format);
    return;
  }

  void extractFromAwsi( ::Uts::DiagPacketMap& _return, const std::string& awsiContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->extractFromAwsi(_return, awsiContents);
    }
    ifaces_[i]->extractFromAwsi(_return, awsiContents);
    return;
  }

  int32_t getDiagId(const  ::Uts::DiagPacketType::type packetType, const std::string& idOrName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getDiagId(packetType, idOrName);
    }
    return ifaces_[i]->getDiagId(packetType, idOrName);
  }

  int32_t getQmiId(const  ::Uts::QmiPacketType::type packetType, const std::string& idOrName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getQmiId(packetType, idOrName);
    }
    return ifaces_[i]->getQmiId(packetType, idOrName);
  }

  int32_t getSaharaId(const std::string& idOrName) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getSaharaId(idOrName);
    }
    return ifaces_[i]->getSaharaId(idOrName);
  }

  void deserializeXqcnXml( ::Uts::QcnContent& _return, const std::string& xqcnFileContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->deserializeXqcnXml(_return, xqcnFileContents);
    }
    ifaces_[i]->deserializeXqcnXml(_return, xqcnFileContents);
    return;
  }

  void serializeXqcnXml(std::string& _return, const  ::Uts::QcnContent& xqcnContents) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->serializeXqcnXml(_return, xqcnContents);
    }
    ifaces_[i]->serializeXqcnXml(_return, xqcnContents);
    return;
  }

  void deserializeNvItem(NvParserResult& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const int8_t index, const  ::Uts::NvReturns& returnConfig, const std::string& payload) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->deserializeNvItem(_return, nvIdOrEfsPath, subscriptionId, index, returnConfig, payload);
    }
    ifaces_[i]->deserializeNvItem(_return, nvIdOrEfsPath, subscriptionId, index, returnConfig, payload);
    return;
  }

  void serializeNvItem(std::string& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const std::string& valueList) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->serializeNvItem(_return, nvIdOrEfsPath, subscriptionId, valueList);
    }
    ifaces_[i]->serializeNvItem(_return, nvIdOrEfsPath, subscriptionId, valueList);
    return;
  }

   ::Uts::ErrorCode::type compressEncryptedFile(const std::string& originalFile, const std::string& outputFile) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->compressEncryptedFile(originalFile, outputFile);
    }
    return ifaces_[i]->compressEncryptedFile(originalFile, outputFile);
  }

  void parseMBN( ::Uts::MbnDiffResult& _return, const std::string& mbnOrXmlPath) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->parseMBN(_return, mbnOrXmlPath);
    }
    ifaces_[i]->parseMBN(_return, mbnOrXmlPath);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class UtilityServiceConcurrentClient : virtual public UtilityServiceIf {
 public:
  UtilityServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  UtilityServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr<::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
  void qmiPack(std::string& _return, const std::string& serviceIdOrName, const std::string& messageIdOrName, const std::string& xmlRequest);
  int32_t send_qmiPack(const std::string& serviceIdOrName, const std::string& messageIdOrName, const std::string& xmlRequest);
  void recv_qmiPack(std::string& _return, const int32_t seqid);
  void qmiUnPack( ::Uts::QmiUnpackReturn& _return, const std::string& serviceIdOrName, const std::string& input);
  int32_t send_qmiUnPack(const std::string& serviceIdOrName, const std::string& input);
  void recv_qmiUnPack( ::Uts::QmiUnpackReturn& _return, const int32_t seqid);
  void nvGetAllItems(std::vector< ::Uts::NvItem> & _return);
  int32_t send_nvGetAllItems();
  void recv_nvGetAllItems(std::vector< ::Uts::NvItem> & _return, const int32_t seqid);
  void nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId);
  int32_t send_nvGetItemDefinition(const std::string& nvItemNameOrId);
  void recv_nvGetItemDefinition(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type createDigestsForVipDownload(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath);
  int32_t send_createDigestsForVipDownload(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath);
   ::Uts::ErrorCode::type recv_createDigestsForVipDownload(const int32_t seqid);
   ::Uts::ErrorCode::type createDigestsForBuildValidation(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath);
  int32_t send_createDigestsForBuildValidation(const std::string& buildPath, const  ::Uts::DownloadBuildOptions& options, const std::string& outputPath);
   ::Uts::ErrorCode::type recv_createDigestsForBuildValidation(const int32_t seqid);
  void generateCfg(std::string& _return, const  ::Uts::DiagPacketMap& mask, const  ::Uts::LogMaskFormat::type format);
  int32_t send_generateCfg(const  ::Uts::DiagPacketMap& mask, const  ::Uts::LogMaskFormat::type format);
  void recv_generateCfg(std::string& _return, const int32_t seqid);
  void convertToHdf(std::vector<std::string> & _return, const std::vector<std::string> & logFiles, const std::string& saveFolder);
  int32_t send_convertToHdf(const std::vector<std::string> & logFiles, const std::string& saveFolder);
  void recv_convertToHdf(std::vector<std::string> & _return, const int32_t seqid);
  void qcnDiff( ::Uts::QcnDiffResult& _return, const std::string& xqcnContents1, const std::string& xqcnContents2, const bool showSame);
  int32_t send_qcnDiff(const std::string& xqcnContents1, const std::string& xqcnContents2, const bool showSame);
  void recv_qcnDiff( ::Uts::QcnDiffResult& _return, const int32_t seqid);
  void extractFromCfg( ::Uts::DiagPacketMap& _return, const std::string& cfgContents, const  ::Uts::LogMaskFormat::type format);
  int32_t send_extractFromCfg(const std::string& cfgContents, const  ::Uts::LogMaskFormat::type format);
  void recv_extractFromCfg( ::Uts::DiagPacketMap& _return, const int32_t seqid);
  void extractFromAwsi( ::Uts::DiagPacketMap& _return, const std::string& awsiContents);
  int32_t send_extractFromAwsi(const std::string& awsiContents);
  void recv_extractFromAwsi( ::Uts::DiagPacketMap& _return, const int32_t seqid);
  int32_t getDiagId(const  ::Uts::DiagPacketType::type packetType, const std::string& idOrName);
  int32_t send_getDiagId(const  ::Uts::DiagPacketType::type packetType, const std::string& idOrName);
  int32_t recv_getDiagId(const int32_t seqid);
  int32_t getQmiId(const  ::Uts::QmiPacketType::type packetType, const std::string& idOrName);
  int32_t send_getQmiId(const  ::Uts::QmiPacketType::type packetType, const std::string& idOrName);
  int32_t recv_getQmiId(const int32_t seqid);
  int32_t getSaharaId(const std::string& idOrName);
  int32_t send_getSaharaId(const std::string& idOrName);
  int32_t recv_getSaharaId(const int32_t seqid);
  void deserializeXqcnXml( ::Uts::QcnContent& _return, const std::string& xqcnFileContents);
  int32_t send_deserializeXqcnXml(const std::string& xqcnFileContents);
  void recv_deserializeXqcnXml( ::Uts::QcnContent& _return, const int32_t seqid);
  void serializeXqcnXml(std::string& _return, const  ::Uts::QcnContent& xqcnContents);
  int32_t send_serializeXqcnXml(const  ::Uts::QcnContent& xqcnContents);
  void recv_serializeXqcnXml(std::string& _return, const int32_t seqid);
  void deserializeNvItem(NvParserResult& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const int8_t index, const  ::Uts::NvReturns& returnConfig, const std::string& payload);
  int32_t send_deserializeNvItem(const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const int8_t index, const  ::Uts::NvReturns& returnConfig, const std::string& payload);
  void recv_deserializeNvItem(NvParserResult& _return, const int32_t seqid);
  void serializeNvItem(std::string& _return, const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const std::string& valueList);
  int32_t send_serializeNvItem(const std::string& nvIdOrEfsPath, const int32_t subscriptionId, const std::string& valueList);
  void recv_serializeNvItem(std::string& _return, const int32_t seqid);
   ::Uts::ErrorCode::type compressEncryptedFile(const std::string& originalFile, const std::string& outputFile);
  int32_t send_compressEncryptedFile(const std::string& originalFile, const std::string& outputFile);
   ::Uts::ErrorCode::type recv_compressEncryptedFile(const int32_t seqid);
  void parseMBN( ::Uts::MbnDiffResult& _return, const std::string& mbnOrXmlPath);
  int32_t send_parseMBN(const std::string& mbnOrXmlPath);
  void recv_parseMBN( ::Uts::MbnDiffResult& _return, const int32_t seqid);
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
