/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DeviceConfigService_TYPES_H
#define DeviceConfigService_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>
#include "Common_types.h"
#include "DiagService_types.h"


namespace Uts {

struct PdcMbnType {
  enum type {
    PDC_CONFIG_TYPE_MODEM_PLATFORM = 0,
    PDC_CONFIG_TYPE_MODEM_SW = 1
  };
};

extern const std::map<int, const char*> _PdcMbnType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const PdcMbnType::type& val);

std::string to_string(const PdcMbnType::type& val);

struct PdcConfigurationType {
  enum type {
    SELECTION_MODE = 0,
    CARRIER = 1,
    FLEX_MAPPING = 2,
    REFRESH_MODE = 3,
    MULTISIM = 4,
    OS = 5,
    MARKET = 6,
    DEPLOYMENT = 7,
    IMS_FEATURE = 8,
    VARIANT = 9,
    COUNTRY = 10
  };
};

extern const std::map<int, const char*> _PdcConfigurationType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const PdcConfigurationType::type& val);

std::string to_string(const PdcConfigurationType::type& val);

struct NvReturnFlags {
  enum type {
    BINARY_PAYLOAD = 1,
    PARSED_TEXT = 2,
    JSON_TEXT = 3,
    VALUE_LIST = 4
  };
};

extern const std::map<int, const char*> _NvReturnFlags_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const NvReturnFlags::type& val);

std::string to_string(const NvReturnFlags::type& val);

struct FileSystem {
  enum type {
    FS_PRIMARY = 0,
    FS_ALTERNATE = 1
  };
};

extern const std::map<int, const char*> _FileSystem_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const FileSystem::type& val);

std::string to_string(const FileSystem::type& val);

struct EfsType {
  enum type {
    DIRECTORY = 0,
    FILE = 1,
    SYMLINK = 2
  };
};

extern const std::map<int, const char*> _EfsType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const EfsType::type& val);

std::string to_string(const EfsType::type& val);

class PdcMbnInfo;

class PdcMbnResult;

class NvReturns;

class NvData;

class EfsFileAttributes;

class EfsItem;

class DeviceConfigConnectionOptions;

class DeviceConfigOptions;

typedef struct _PdcMbnInfo__isset {
  _PdcMbnInfo__isset() : errorCode(false), type(false), size(false), version(false), baseVersion(false), storageType(false), configId(false), description(false), path(false) {}
  bool errorCode :1;
  bool type :1;
  bool size :1;
  bool version :1;
  bool baseVersion :1;
  bool storageType :1;
  bool configId :1;
  bool description :1;
  bool path :1;
} _PdcMbnInfo__isset;

class PdcMbnInfo : public virtual ::apache::thrift::TBase {
 public:

  PdcMbnInfo(const PdcMbnInfo&);
  PdcMbnInfo& operator=(const PdcMbnInfo&);
  PdcMbnInfo() : errorCode(( ::Uts::ErrorCode::type)0), type(0), size(0), version(0), baseVersion(0), storageType(0), configId(), description(), path() {
  }

  virtual ~PdcMbnInfo() noexcept;
   ::Uts::ErrorCode::type errorCode;
  int32_t type;
  int32_t size;
  int32_t version;
  int32_t baseVersion;
  int32_t storageType;
  std::string configId;
  std::string description;
  std::string path;

  _PdcMbnInfo__isset __isset;

  void __set_errorCode(const  ::Uts::ErrorCode::type val);

  void __set_type(const int32_t val);

  void __set_size(const int32_t val);

  void __set_version(const int32_t val);

  void __set_baseVersion(const int32_t val);

  void __set_storageType(const int32_t val);

  void __set_configId(const std::string& val);

  void __set_description(const std::string& val);

  void __set_path(const std::string& val);

  bool operator == (const PdcMbnInfo & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (__isset.type != rhs.__isset.type)
      return false;
    else if (__isset.type && !(type == rhs.type))
      return false;
    if (__isset.size != rhs.__isset.size)
      return false;
    else if (__isset.size && !(size == rhs.size))
      return false;
    if (__isset.version != rhs.__isset.version)
      return false;
    else if (__isset.version && !(version == rhs.version))
      return false;
    if (__isset.baseVersion != rhs.__isset.baseVersion)
      return false;
    else if (__isset.baseVersion && !(baseVersion == rhs.baseVersion))
      return false;
    if (__isset.storageType != rhs.__isset.storageType)
      return false;
    else if (__isset.storageType && !(storageType == rhs.storageType))
      return false;
    if (__isset.configId != rhs.__isset.configId)
      return false;
    else if (__isset.configId && !(configId == rhs.configId))
      return false;
    if (__isset.description != rhs.__isset.description)
      return false;
    else if (__isset.description && !(description == rhs.description))
      return false;
    if (__isset.path != rhs.__isset.path)
      return false;
    else if (__isset.path && !(path == rhs.path))
      return false;
    return true;
  }
  bool operator != (const PdcMbnInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PdcMbnInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PdcMbnInfo &a, PdcMbnInfo &b);

std::ostream& operator<<(std::ostream& out, const PdcMbnInfo& obj);

typedef struct _PdcMbnResult__isset {
  _PdcMbnResult__isset() : errorCode(false), version(false), frame(false) {}
  bool errorCode :1;
  bool version :1;
  bool frame :1;
} _PdcMbnResult__isset;

class PdcMbnResult : public virtual ::apache::thrift::TBase {
 public:

  PdcMbnResult(const PdcMbnResult&);
  PdcMbnResult& operator=(const PdcMbnResult&);
  PdcMbnResult() : errorCode(( ::Uts::ErrorCode::type)0), version(0), frame() {
  }

  virtual ~PdcMbnResult() noexcept;
   ::Uts::ErrorCode::type errorCode;
  int32_t version;
  std::string frame;

  _PdcMbnResult__isset __isset;

  void __set_errorCode(const  ::Uts::ErrorCode::type val);

  void __set_version(const int32_t val);

  void __set_frame(const std::string& val);

  bool operator == (const PdcMbnResult & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (__isset.version != rhs.__isset.version)
      return false;
    else if (__isset.version && !(version == rhs.version))
      return false;
    if (__isset.frame != rhs.__isset.frame)
      return false;
    else if (__isset.frame && !(frame == rhs.frame))
      return false;
    return true;
  }
  bool operator != (const PdcMbnResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PdcMbnResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PdcMbnResult &a, PdcMbnResult &b);

std::ostream& operator<<(std::ostream& out, const PdcMbnResult& obj);

typedef struct _NvReturns__isset {
  _NvReturns__isset() : flags(false), fieldQueries(false) {}
  bool flags :1;
  bool fieldQueries :1;
} _NvReturns__isset;

class NvReturns : public virtual ::apache::thrift::TBase {
 public:

  NvReturns(const NvReturns&);
  NvReturns& operator=(const NvReturns&);
  NvReturns() : flags((NvReturnFlags::type)0) {
  }

  virtual ~NvReturns() noexcept;
  NvReturnFlags::type flags;
  std::vector<std::string>  fieldQueries;

  _NvReturns__isset __isset;

  void __set_flags(const NvReturnFlags::type val);

  void __set_fieldQueries(const std::vector<std::string> & val);

  bool operator == (const NvReturns & rhs) const
  {
    if (!(flags == rhs.flags))
      return false;
    if (__isset.fieldQueries != rhs.__isset.fieldQueries)
      return false;
    else if (__isset.fieldQueries && !(fieldQueries == rhs.fieldQueries))
      return false;
    return true;
  }
  bool operator != (const NvReturns &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NvReturns & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(NvReturns &a, NvReturns &b);

std::ostream& operator<<(std::ostream& out, const NvReturns& obj);

typedef struct _NvData__isset {
  _NvData__isset() : errorCode(false), payload(false), parsedText(false), parsedJson(false), valueList(false), queryResultJson(false) {}
  bool errorCode :1;
  bool payload :1;
  bool parsedText :1;
  bool parsedJson :1;
  bool valueList :1;
  bool queryResultJson :1;
} _NvData__isset;

class NvData : public virtual ::apache::thrift::TBase {
 public:

  NvData(const NvData&);
  NvData& operator=(const NvData&);
  NvData() : errorCode(( ::Uts::ErrorCode::type)0), payload(), parsedText(), parsedJson(), valueList(), queryResultJson() {
  }

  virtual ~NvData() noexcept;
   ::Uts::ErrorCode::type errorCode;
  std::string payload;
  std::string parsedText;
  std::string parsedJson;
  std::string valueList;
  std::string queryResultJson;

  _NvData__isset __isset;

  void __set_errorCode(const  ::Uts::ErrorCode::type val);

  void __set_payload(const std::string& val);

  void __set_parsedText(const std::string& val);

  void __set_parsedJson(const std::string& val);

  void __set_valueList(const std::string& val);

  void __set_queryResultJson(const std::string& val);

  bool operator == (const NvData & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (__isset.payload != rhs.__isset.payload)
      return false;
    else if (__isset.payload && !(payload == rhs.payload))
      return false;
    if (__isset.parsedText != rhs.__isset.parsedText)
      return false;
    else if (__isset.parsedText && !(parsedText == rhs.parsedText))
      return false;
    if (__isset.parsedJson != rhs.__isset.parsedJson)
      return false;
    else if (__isset.parsedJson && !(parsedJson == rhs.parsedJson))
      return false;
    if (__isset.valueList != rhs.__isset.valueList)
      return false;
    else if (__isset.valueList && !(valueList == rhs.valueList))
      return false;
    if (__isset.queryResultJson != rhs.__isset.queryResultJson)
      return false;
    else if (__isset.queryResultJson && !(queryResultJson == rhs.queryResultJson))
      return false;
    return true;
  }
  bool operator != (const NvData &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NvData & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(NvData &a, NvData &b);

std::ostream& operator<<(std::ostream& out, const NvData& obj);

typedef struct _EfsFileAttributes__isset {
  _EfsFileAttributes__isset() : modifiedTime(false), createdTime(false), attributes(false), mode(false), nLinks(false), fileSize(false) {}
  bool modifiedTime :1;
  bool createdTime :1;
  bool attributes :1;
  bool mode :1;
  bool nLinks :1;
  bool fileSize :1;
} _EfsFileAttributes__isset;

class EfsFileAttributes : public virtual ::apache::thrift::TBase {
 public:

  EfsFileAttributes(const EfsFileAttributes&);
  EfsFileAttributes& operator=(const EfsFileAttributes&);
  EfsFileAttributes() : modifiedTime(), createdTime(), attributes(), mode(0), nLinks(0), fileSize(0) {
  }

  virtual ~EfsFileAttributes() noexcept;
  std::string modifiedTime;
  std::string createdTime;
  std::string attributes;
  int32_t mode;
  int32_t nLinks;
  int64_t fileSize;

  _EfsFileAttributes__isset __isset;

  void __set_modifiedTime(const std::string& val);

  void __set_createdTime(const std::string& val);

  void __set_attributes(const std::string& val);

  void __set_mode(const int32_t val);

  void __set_nLinks(const int32_t val);

  void __set_fileSize(const int64_t val);

  bool operator == (const EfsFileAttributes & rhs) const
  {
    if (!(modifiedTime == rhs.modifiedTime))
      return false;
    if (!(createdTime == rhs.createdTime))
      return false;
    if (!(attributes == rhs.attributes))
      return false;
    if (!(mode == rhs.mode))
      return false;
    if (!(nLinks == rhs.nLinks))
      return false;
    if (!(fileSize == rhs.fileSize))
      return false;
    return true;
  }
  bool operator != (const EfsFileAttributes &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EfsFileAttributes & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(EfsFileAttributes &a, EfsFileAttributes &b);

std::ostream& operator<<(std::ostream& out, const EfsFileAttributes& obj);

typedef struct _EfsItem__isset {
  _EfsItem__isset() : type(false), name(false), accessible(false) {}
  bool type :1;
  bool name :1;
  bool accessible :1;
} _EfsItem__isset;

class EfsItem : public virtual ::apache::thrift::TBase {
 public:

  EfsItem(const EfsItem&);
  EfsItem& operator=(const EfsItem&);
  EfsItem() : type((EfsType::type)0), name(), accessible(0) {
  }

  virtual ~EfsItem() noexcept;
  EfsType::type type;
  std::string name;
  bool accessible;

  _EfsItem__isset __isset;

  void __set_type(const EfsType::type val);

  void __set_name(const std::string& val);

  void __set_accessible(const bool val);

  bool operator == (const EfsItem & rhs) const
  {
    if (!(type == rhs.type))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(accessible == rhs.accessible))
      return false;
    return true;
  }
  bool operator != (const EfsItem &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EfsItem & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(EfsItem &a, EfsItem &b);

std::ostream& operator<<(std::ostream& out, const EfsItem& obj);

typedef struct _DeviceConfigConnectionOptions__isset {
  _DeviceConfigConnectionOptions__isset() : diagConnectionOptions(false), qmiConnectionOptions(false) {}
  bool diagConnectionOptions :1;
  bool qmiConnectionOptions :1;
} _DeviceConfigConnectionOptions__isset;

class DeviceConfigConnectionOptions : public virtual ::apache::thrift::TBase {
 public:

  DeviceConfigConnectionOptions(const DeviceConfigConnectionOptions&);
  DeviceConfigConnectionOptions& operator=(const DeviceConfigConnectionOptions&);
  DeviceConfigConnectionOptions() {
  }

  virtual ~DeviceConfigConnectionOptions() noexcept;
   ::Uts::DiagConnectionOptions diagConnectionOptions;
   ::Uts::QmiConnectionOptions qmiConnectionOptions;

  _DeviceConfigConnectionOptions__isset __isset;

  void __set_diagConnectionOptions(const  ::Uts::DiagConnectionOptions& val);

  void __set_qmiConnectionOptions(const  ::Uts::QmiConnectionOptions& val);

  bool operator == (const DeviceConfigConnectionOptions & rhs) const
  {
    if (__isset.diagConnectionOptions != rhs.__isset.diagConnectionOptions)
      return false;
    else if (__isset.diagConnectionOptions && !(diagConnectionOptions == rhs.diagConnectionOptions))
      return false;
    if (__isset.qmiConnectionOptions != rhs.__isset.qmiConnectionOptions)
      return false;
    else if (__isset.qmiConnectionOptions && !(qmiConnectionOptions == rhs.qmiConnectionOptions))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigConnectionOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigConnectionOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DeviceConfigConnectionOptions &a, DeviceConfigConnectionOptions &b);

std::ostream& operator<<(std::ostream& out, const DeviceConfigConnectionOptions& obj);

typedef struct _DeviceConfigOptions__isset {
  _DeviceConfigOptions__isset() : useDiagForPdc(false), xqcnOperationType(false), xqcnRestoreOptions(false), xqcnBackupOptions(false) {}
  bool useDiagForPdc :1;
  bool xqcnOperationType :1;
  bool xqcnRestoreOptions :1;
  bool xqcnBackupOptions :1;
} _DeviceConfigOptions__isset;

class DeviceConfigOptions : public virtual ::apache::thrift::TBase {
 public:

  DeviceConfigOptions(const DeviceConfigOptions&);
  DeviceConfigOptions& operator=(const DeviceConfigOptions&);
  DeviceConfigOptions() : useDiagForPdc(0), xqcnOperationType(( ::Uts::XqcnOperationType::type)0) {
  }

  virtual ~DeviceConfigOptions() noexcept;
  bool useDiagForPdc;
   ::Uts::XqcnOperationType::type xqcnOperationType;
   ::Uts::XqcnRestoreOptions xqcnRestoreOptions;
   ::Uts::XqcnBackupOptions xqcnBackupOptions;

  _DeviceConfigOptions__isset __isset;

  void __set_useDiagForPdc(const bool val);

  void __set_xqcnOperationType(const  ::Uts::XqcnOperationType::type val);

  void __set_xqcnRestoreOptions(const  ::Uts::XqcnRestoreOptions& val);

  void __set_xqcnBackupOptions(const  ::Uts::XqcnBackupOptions& val);

  bool operator == (const DeviceConfigOptions & rhs) const
  {
    if (__isset.useDiagForPdc != rhs.__isset.useDiagForPdc)
      return false;
    else if (__isset.useDiagForPdc && !(useDiagForPdc == rhs.useDiagForPdc))
      return false;
    if (__isset.xqcnOperationType != rhs.__isset.xqcnOperationType)
      return false;
    else if (__isset.xqcnOperationType && !(xqcnOperationType == rhs.xqcnOperationType))
      return false;
    if (__isset.xqcnRestoreOptions != rhs.__isset.xqcnRestoreOptions)
      return false;
    else if (__isset.xqcnRestoreOptions && !(xqcnRestoreOptions == rhs.xqcnRestoreOptions))
      return false;
    if (__isset.xqcnBackupOptions != rhs.__isset.xqcnBackupOptions)
      return false;
    else if (__isset.xqcnBackupOptions && !(xqcnBackupOptions == rhs.xqcnBackupOptions))
      return false;
    return true;
  }
  bool operator != (const DeviceConfigOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DeviceConfigOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DeviceConfigOptions &a, DeviceConfigOptions &b);

std::ostream& operator<<(std::ostream& out, const DeviceConfigOptions& obj);

} // namespace

#endif
