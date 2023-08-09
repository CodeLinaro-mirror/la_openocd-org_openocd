/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "DeviceConfigService_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {

int _kPdcMbnTypeValues[] = {
  PdcMbnType::PDC_CONFIG_TYPE_MODEM_PLATFORM,
  PdcMbnType::PDC_CONFIG_TYPE_MODEM_SW
};
const char* _kPdcMbnTypeNames[] = {
  "PDC_CONFIG_TYPE_MODEM_PLATFORM",
  "PDC_CONFIG_TYPE_MODEM_SW"
};
const std::map<int, const char*> _PdcMbnType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kPdcMbnTypeValues, _kPdcMbnTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const PdcMbnType::type& val) {
  std::map<int, const char*>::const_iterator it = _PdcMbnType_VALUES_TO_NAMES.find(val);
  if (it != _PdcMbnType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const PdcMbnType::type& val) {
  std::map<int, const char*>::const_iterator it = _PdcMbnType_VALUES_TO_NAMES.find(val);
  if (it != _PdcMbnType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kPdcConfigurationTypeValues[] = {
  PdcConfigurationType::SELECTION_MODE,
  PdcConfigurationType::CARRIER,
  PdcConfigurationType::FLEX_MAPPING,
  PdcConfigurationType::REFRESH_MODE,
  PdcConfigurationType::MULTISIM,
  PdcConfigurationType::OS,
  PdcConfigurationType::MARKET,
  PdcConfigurationType::DEPLOYMENT,
  PdcConfigurationType::IMS_FEATURE,
  PdcConfigurationType::VARIANT,
  PdcConfigurationType::COUNTRY
};
const char* _kPdcConfigurationTypeNames[] = {
  "SELECTION_MODE",
  "CARRIER",
  "FLEX_MAPPING",
  "REFRESH_MODE",
  "MULTISIM",
  "OS",
  "MARKET",
  "DEPLOYMENT",
  "IMS_FEATURE",
  "VARIANT",
  "COUNTRY"
};
const std::map<int, const char*> _PdcConfigurationType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(11, _kPdcConfigurationTypeValues, _kPdcConfigurationTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const PdcConfigurationType::type& val) {
  std::map<int, const char*>::const_iterator it = _PdcConfigurationType_VALUES_TO_NAMES.find(val);
  if (it != _PdcConfigurationType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const PdcConfigurationType::type& val) {
  std::map<int, const char*>::const_iterator it = _PdcConfigurationType_VALUES_TO_NAMES.find(val);
  if (it != _PdcConfigurationType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kNvReturnFlagsValues[] = {
  NvReturnFlags::BINARY_PAYLOAD,
  NvReturnFlags::PARSED_TEXT,
  NvReturnFlags::JSON_TEXT,
  NvReturnFlags::VALUE_LIST
};
const char* _kNvReturnFlagsNames[] = {
  "BINARY_PAYLOAD",
  "PARSED_TEXT",
  "JSON_TEXT",
  "VALUE_LIST"
};
const std::map<int, const char*> _NvReturnFlags_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kNvReturnFlagsValues, _kNvReturnFlagsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const NvReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _NvReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _NvReturnFlags_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const NvReturnFlags::type& val) {
  std::map<int, const char*>::const_iterator it = _NvReturnFlags_VALUES_TO_NAMES.find(val);
  if (it != _NvReturnFlags_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kFileSystemValues[] = {
  FileSystem::FS_PRIMARY,
  FileSystem::FS_ALTERNATE
};
const char* _kFileSystemNames[] = {
  "FS_PRIMARY",
  "FS_ALTERNATE"
};
const std::map<int, const char*> _FileSystem_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kFileSystemValues, _kFileSystemNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const FileSystem::type& val) {
  std::map<int, const char*>::const_iterator it = _FileSystem_VALUES_TO_NAMES.find(val);
  if (it != _FileSystem_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const FileSystem::type& val) {
  std::map<int, const char*>::const_iterator it = _FileSystem_VALUES_TO_NAMES.find(val);
  if (it != _FileSystem_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kEfsTypeValues[] = {
  EfsType::DIRECTORY,
  EfsType::FILE,
  EfsType::SYMLINK
};
const char* _kEfsTypeNames[] = {
  "DIRECTORY",
  "FILE",
  "SYMLINK"
};
const std::map<int, const char*> _EfsType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kEfsTypeValues, _kEfsTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const EfsType::type& val) {
  std::map<int, const char*>::const_iterator it = _EfsType_VALUES_TO_NAMES.find(val);
  if (it != _EfsType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const EfsType::type& val) {
  std::map<int, const char*>::const_iterator it = _EfsType_VALUES_TO_NAMES.find(val);
  if (it != _EfsType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


PdcMbnInfo::~PdcMbnInfo() noexcept {
}


void PdcMbnInfo::__set_errorCode(const  ::Uts::ErrorCode::type val) {
  this->errorCode = val;
}

void PdcMbnInfo::__set_type(const int32_t val) {
  this->type = val;
__isset.type = true;
}

void PdcMbnInfo::__set_size(const int32_t val) {
  this->size = val;
__isset.size = true;
}

void PdcMbnInfo::__set_version(const int32_t val) {
  this->version = val;
__isset.version = true;
}

void PdcMbnInfo::__set_baseVersion(const int32_t val) {
  this->baseVersion = val;
__isset.baseVersion = true;
}

void PdcMbnInfo::__set_storageType(const int32_t val) {
  this->storageType = val;
__isset.storageType = true;
}

void PdcMbnInfo::__set_configId(const std::string& val) {
  this->configId = val;
__isset.configId = true;
}

void PdcMbnInfo::__set_description(const std::string& val) {
  this->description = val;
__isset.description = true;
}

void PdcMbnInfo::__set_path(const std::string& val) {
  this->path = val;
__isset.path = true;
}
std::ostream& operator<<(std::ostream& out, const PdcMbnInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t PdcMbnInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->errorCode = ( ::Uts::ErrorCode::type)ecast0;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->type);
          this->__isset.type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->size);
          this->__isset.size = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->version);
          this->__isset.version = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->baseVersion);
          this->__isset.baseVersion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->storageType);
          this->__isset.storageType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->configId);
          this->__isset.configId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->path);
          this->__isset.path = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t PdcMbnInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PdcMbnInfo");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->errorCode);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.type) {
    xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->type);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.size) {
    xfer += oprot->writeFieldBegin("size", ::apache::thrift::protocol::T_I32, 3);
    xfer += oprot->writeI32(this->size);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.version) {
    xfer += oprot->writeFieldBegin("version", ::apache::thrift::protocol::T_I32, 4);
    xfer += oprot->writeI32(this->version);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.baseVersion) {
    xfer += oprot->writeFieldBegin("baseVersion", ::apache::thrift::protocol::T_I32, 5);
    xfer += oprot->writeI32(this->baseVersion);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.storageType) {
    xfer += oprot->writeFieldBegin("storageType", ::apache::thrift::protocol::T_I32, 6);
    xfer += oprot->writeI32(this->storageType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.configId) {
    xfer += oprot->writeFieldBegin("configId", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeBinary(this->configId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.description) {
    xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 8);
    xfer += oprot->writeString(this->description);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.path) {
    xfer += oprot->writeFieldBegin("path", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->path);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PdcMbnInfo &a, PdcMbnInfo &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.type, b.type);
  swap(a.size, b.size);
  swap(a.version, b.version);
  swap(a.baseVersion, b.baseVersion);
  swap(a.storageType, b.storageType);
  swap(a.configId, b.configId);
  swap(a.description, b.description);
  swap(a.path, b.path);
  swap(a.__isset, b.__isset);
}

PdcMbnInfo::PdcMbnInfo(const PdcMbnInfo& other1) {
  errorCode = other1.errorCode;
  type = other1.type;
  size = other1.size;
  version = other1.version;
  baseVersion = other1.baseVersion;
  storageType = other1.storageType;
  configId = other1.configId;
  description = other1.description;
  path = other1.path;
  __isset = other1.__isset;
}
PdcMbnInfo& PdcMbnInfo::operator=(const PdcMbnInfo& other2) {
  errorCode = other2.errorCode;
  type = other2.type;
  size = other2.size;
  version = other2.version;
  baseVersion = other2.baseVersion;
  storageType = other2.storageType;
  configId = other2.configId;
  description = other2.description;
  path = other2.path;
  __isset = other2.__isset;
  return *this;
}
void PdcMbnInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PdcMbnInfo(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "type="; (__isset.type ? (out << to_string(type)) : (out << "<null>"));
  out << ", " << "size="; (__isset.size ? (out << to_string(size)) : (out << "<null>"));
  out << ", " << "version="; (__isset.version ? (out << to_string(version)) : (out << "<null>"));
  out << ", " << "baseVersion="; (__isset.baseVersion ? (out << to_string(baseVersion)) : (out << "<null>"));
  out << ", " << "storageType="; (__isset.storageType ? (out << to_string(storageType)) : (out << "<null>"));
  out << ", " << "configId="; (__isset.configId ? (out << to_string(configId)) : (out << "<null>"));
  out << ", " << "description="; (__isset.description ? (out << to_string(description)) : (out << "<null>"));
  out << ", " << "path="; (__isset.path ? (out << to_string(path)) : (out << "<null>"));
  out << ")";
}


PdcMbnResult::~PdcMbnResult() noexcept {
}


void PdcMbnResult::__set_errorCode(const  ::Uts::ErrorCode::type val) {
  this->errorCode = val;
}

void PdcMbnResult::__set_version(const int32_t val) {
  this->version = val;
__isset.version = true;
}

void PdcMbnResult::__set_frame(const std::string& val) {
  this->frame = val;
__isset.frame = true;
}
std::ostream& operator<<(std::ostream& out, const PdcMbnResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t PdcMbnResult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast3;
          xfer += iprot->readI32(ecast3);
          this->errorCode = ( ::Uts::ErrorCode::type)ecast3;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->version);
          this->__isset.version = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->frame);
          this->__isset.frame = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t PdcMbnResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PdcMbnResult");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->errorCode);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.version) {
    xfer += oprot->writeFieldBegin("version", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32(this->version);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.frame) {
    xfer += oprot->writeFieldBegin("frame", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->frame);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PdcMbnResult &a, PdcMbnResult &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.version, b.version);
  swap(a.frame, b.frame);
  swap(a.__isset, b.__isset);
}

PdcMbnResult::PdcMbnResult(const PdcMbnResult& other4) {
  errorCode = other4.errorCode;
  version = other4.version;
  frame = other4.frame;
  __isset = other4.__isset;
}
PdcMbnResult& PdcMbnResult::operator=(const PdcMbnResult& other5) {
  errorCode = other5.errorCode;
  version = other5.version;
  frame = other5.frame;
  __isset = other5.__isset;
  return *this;
}
void PdcMbnResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PdcMbnResult(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "version="; (__isset.version ? (out << to_string(version)) : (out << "<null>"));
  out << ", " << "frame="; (__isset.frame ? (out << to_string(frame)) : (out << "<null>"));
  out << ")";
}


NvReturns::~NvReturns() noexcept {
}


void NvReturns::__set_flags(const NvReturnFlags::type val) {
  this->flags = val;
}

void NvReturns::__set_fieldQueries(const std::vector<std::string> & val) {
  this->fieldQueries = val;
__isset.fieldQueries = true;
}
std::ostream& operator<<(std::ostream& out, const NvReturns& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t NvReturns::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast6;
          xfer += iprot->readI32(ecast6);
          this->flags = (NvReturnFlags::type)ecast6;
          this->__isset.flags = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->fieldQueries.clear();
            uint32_t _size7;
            ::apache::thrift::protocol::TType _etype10;
            xfer += iprot->readListBegin(_etype10, _size7);
            this->fieldQueries.resize(_size7);
            uint32_t _i11;
            for (_i11 = 0; _i11 < _size7; ++_i11)
            {
              xfer += iprot->readString(this->fieldQueries[_i11]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.fieldQueries = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NvReturns::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("NvReturns");

  xfer += oprot->writeFieldBegin("flags", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->flags);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.fieldQueries) {
    xfer += oprot->writeFieldBegin("fieldQueries", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->fieldQueries.size()));
      std::vector<std::string> ::const_iterator _iter12;
      for (_iter12 = this->fieldQueries.begin(); _iter12 != this->fieldQueries.end(); ++_iter12)
      {
        xfer += oprot->writeString((*_iter12));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NvReturns &a, NvReturns &b) {
  using ::std::swap;
  swap(a.flags, b.flags);
  swap(a.fieldQueries, b.fieldQueries);
  swap(a.__isset, b.__isset);
}

NvReturns::NvReturns(const NvReturns& other13) {
  flags = other13.flags;
  fieldQueries = other13.fieldQueries;
  __isset = other13.__isset;
}
NvReturns& NvReturns::operator=(const NvReturns& other14) {
  flags = other14.flags;
  fieldQueries = other14.fieldQueries;
  __isset = other14.__isset;
  return *this;
}
void NvReturns::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "NvReturns(";
  out << "flags=" << to_string(flags);
  out << ", " << "fieldQueries="; (__isset.fieldQueries ? (out << to_string(fieldQueries)) : (out << "<null>"));
  out << ")";
}


NvData::~NvData() noexcept {
}


void NvData::__set_errorCode(const  ::Uts::ErrorCode::type val) {
  this->errorCode = val;
}

void NvData::__set_payload(const std::string& val) {
  this->payload = val;
__isset.payload = true;
}

void NvData::__set_parsedText(const std::string& val) {
  this->parsedText = val;
__isset.parsedText = true;
}

void NvData::__set_parsedJson(const std::string& val) {
  this->parsedJson = val;
__isset.parsedJson = true;
}

void NvData::__set_valueList(const std::string& val) {
  this->valueList = val;
__isset.valueList = true;
}

void NvData::__set_queryResultJson(const std::string& val) {
  this->queryResultJson = val;
__isset.queryResultJson = true;
}
std::ostream& operator<<(std::ostream& out, const NvData& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t NvData::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast15;
          xfer += iprot->readI32(ecast15);
          this->errorCode = ( ::Uts::ErrorCode::type)ecast15;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->payload);
          this->__isset.payload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->parsedText);
          this->__isset.parsedText = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->parsedJson);
          this->__isset.parsedJson = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->valueList);
          this->__isset.valueList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->queryResultJson);
          this->__isset.queryResultJson = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t NvData::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("NvData");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->errorCode);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.payload) {
    xfer += oprot->writeFieldBegin("payload", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeBinary(this->payload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.parsedText) {
    xfer += oprot->writeFieldBegin("parsedText", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->parsedText);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.parsedJson) {
    xfer += oprot->writeFieldBegin("parsedJson", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->parsedJson);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.valueList) {
    xfer += oprot->writeFieldBegin("valueList", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->valueList);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.queryResultJson) {
    xfer += oprot->writeFieldBegin("queryResultJson", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->queryResultJson);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NvData &a, NvData &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.payload, b.payload);
  swap(a.parsedText, b.parsedText);
  swap(a.parsedJson, b.parsedJson);
  swap(a.valueList, b.valueList);
  swap(a.queryResultJson, b.queryResultJson);
  swap(a.__isset, b.__isset);
}

NvData::NvData(const NvData& other16) {
  errorCode = other16.errorCode;
  payload = other16.payload;
  parsedText = other16.parsedText;
  parsedJson = other16.parsedJson;
  valueList = other16.valueList;
  queryResultJson = other16.queryResultJson;
  __isset = other16.__isset;
}
NvData& NvData::operator=(const NvData& other17) {
  errorCode = other17.errorCode;
  payload = other17.payload;
  parsedText = other17.parsedText;
  parsedJson = other17.parsedJson;
  valueList = other17.valueList;
  queryResultJson = other17.queryResultJson;
  __isset = other17.__isset;
  return *this;
}
void NvData::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "NvData(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "payload="; (__isset.payload ? (out << to_string(payload)) : (out << "<null>"));
  out << ", " << "parsedText="; (__isset.parsedText ? (out << to_string(parsedText)) : (out << "<null>"));
  out << ", " << "parsedJson="; (__isset.parsedJson ? (out << to_string(parsedJson)) : (out << "<null>"));
  out << ", " << "valueList="; (__isset.valueList ? (out << to_string(valueList)) : (out << "<null>"));
  out << ", " << "queryResultJson="; (__isset.queryResultJson ? (out << to_string(queryResultJson)) : (out << "<null>"));
  out << ")";
}


EfsFileAttributes::~EfsFileAttributes() noexcept {
}


void EfsFileAttributes::__set_modifiedTime(const std::string& val) {
  this->modifiedTime = val;
}

void EfsFileAttributes::__set_createdTime(const std::string& val) {
  this->createdTime = val;
}

void EfsFileAttributes::__set_attributes(const std::string& val) {
  this->attributes = val;
}

void EfsFileAttributes::__set_mode(const int32_t val) {
  this->mode = val;
}

void EfsFileAttributes::__set_nLinks(const int32_t val) {
  this->nLinks = val;
}

void EfsFileAttributes::__set_fileSize(const int64_t val) {
  this->fileSize = val;
}
std::ostream& operator<<(std::ostream& out, const EfsFileAttributes& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t EfsFileAttributes::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->modifiedTime);
          this->__isset.modifiedTime = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->createdTime);
          this->__isset.createdTime = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->attributes);
          this->__isset.attributes = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->mode);
          this->__isset.mode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->nLinks);
          this->__isset.nLinks = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->fileSize);
          this->__isset.fileSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EfsFileAttributes::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EfsFileAttributes");

  xfer += oprot->writeFieldBegin("modifiedTime", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->modifiedTime);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("createdTime", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->createdTime);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("attributes", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->attributes);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mode", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->mode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("nLinks", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->nLinks);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("fileSize", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->fileSize);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EfsFileAttributes &a, EfsFileAttributes &b) {
  using ::std::swap;
  swap(a.modifiedTime, b.modifiedTime);
  swap(a.createdTime, b.createdTime);
  swap(a.attributes, b.attributes);
  swap(a.mode, b.mode);
  swap(a.nLinks, b.nLinks);
  swap(a.fileSize, b.fileSize);
  swap(a.__isset, b.__isset);
}

EfsFileAttributes::EfsFileAttributes(const EfsFileAttributes& other18) {
  modifiedTime = other18.modifiedTime;
  createdTime = other18.createdTime;
  attributes = other18.attributes;
  mode = other18.mode;
  nLinks = other18.nLinks;
  fileSize = other18.fileSize;
  __isset = other18.__isset;
}
EfsFileAttributes& EfsFileAttributes::operator=(const EfsFileAttributes& other19) {
  modifiedTime = other19.modifiedTime;
  createdTime = other19.createdTime;
  attributes = other19.attributes;
  mode = other19.mode;
  nLinks = other19.nLinks;
  fileSize = other19.fileSize;
  __isset = other19.__isset;
  return *this;
}
void EfsFileAttributes::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "EfsFileAttributes(";
  out << "modifiedTime=" << to_string(modifiedTime);
  out << ", " << "createdTime=" << to_string(createdTime);
  out << ", " << "attributes=" << to_string(attributes);
  out << ", " << "mode=" << to_string(mode);
  out << ", " << "nLinks=" << to_string(nLinks);
  out << ", " << "fileSize=" << to_string(fileSize);
  out << ")";
}


EfsItem::~EfsItem() noexcept {
}


void EfsItem::__set_type(const EfsType::type val) {
  this->type = val;
}

void EfsItem::__set_name(const std::string& val) {
  this->name = val;
}

void EfsItem::__set_accessible(const bool val) {
  this->accessible = val;
}
std::ostream& operator<<(std::ostream& out, const EfsItem& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t EfsItem::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast20;
          xfer += iprot->readI32(ecast20);
          this->type = (EfsType::type)ecast20;
          this->__isset.type = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->name);
          this->__isset.name = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->accessible);
          this->__isset.accessible = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t EfsItem::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EfsItem");

  xfer += oprot->writeFieldBegin("type", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->type);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("accessible", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool(this->accessible);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EfsItem &a, EfsItem &b) {
  using ::std::swap;
  swap(a.type, b.type);
  swap(a.name, b.name);
  swap(a.accessible, b.accessible);
  swap(a.__isset, b.__isset);
}

EfsItem::EfsItem(const EfsItem& other21) {
  type = other21.type;
  name = other21.name;
  accessible = other21.accessible;
  __isset = other21.__isset;
}
EfsItem& EfsItem::operator=(const EfsItem& other22) {
  type = other22.type;
  name = other22.name;
  accessible = other22.accessible;
  __isset = other22.__isset;
  return *this;
}
void EfsItem::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "EfsItem(";
  out << "type=" << to_string(type);
  out << ", " << "name=" << to_string(name);
  out << ", " << "accessible=" << to_string(accessible);
  out << ")";
}


DeviceConfigConnectionOptions::~DeviceConfigConnectionOptions() noexcept {
}


void DeviceConfigConnectionOptions::__set_diagConnectionOptions(const  ::Uts::DiagConnectionOptions& val) {
  this->diagConnectionOptions = val;
__isset.diagConnectionOptions = true;
}

void DeviceConfigConnectionOptions::__set_qmiConnectionOptions(const  ::Uts::QmiConnectionOptions& val) {
  this->qmiConnectionOptions = val;
__isset.qmiConnectionOptions = true;
}
std::ostream& operator<<(std::ostream& out, const DeviceConfigConnectionOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DeviceConfigConnectionOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->diagConnectionOptions.read(iprot);
          this->__isset.diagConnectionOptions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->qmiConnectionOptions.read(iprot);
          this->__isset.qmiConnectionOptions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DeviceConfigConnectionOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigConnectionOptions");

  if (this->__isset.diagConnectionOptions) {
    xfer += oprot->writeFieldBegin("diagConnectionOptions", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->diagConnectionOptions.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qmiConnectionOptions) {
    xfer += oprot->writeFieldBegin("qmiConnectionOptions", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->qmiConnectionOptions.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DeviceConfigConnectionOptions &a, DeviceConfigConnectionOptions &b) {
  using ::std::swap;
  swap(a.diagConnectionOptions, b.diagConnectionOptions);
  swap(a.qmiConnectionOptions, b.qmiConnectionOptions);
  swap(a.__isset, b.__isset);
}

DeviceConfigConnectionOptions::DeviceConfigConnectionOptions(const DeviceConfigConnectionOptions& other23) {
  diagConnectionOptions = other23.diagConnectionOptions;
  qmiConnectionOptions = other23.qmiConnectionOptions;
  __isset = other23.__isset;
}
DeviceConfigConnectionOptions& DeviceConfigConnectionOptions::operator=(const DeviceConfigConnectionOptions& other24) {
  diagConnectionOptions = other24.diagConnectionOptions;
  qmiConnectionOptions = other24.qmiConnectionOptions;
  __isset = other24.__isset;
  return *this;
}
void DeviceConfigConnectionOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DeviceConfigConnectionOptions(";
  out << "diagConnectionOptions="; (__isset.diagConnectionOptions ? (out << to_string(diagConnectionOptions)) : (out << "<null>"));
  out << ", " << "qmiConnectionOptions="; (__isset.qmiConnectionOptions ? (out << to_string(qmiConnectionOptions)) : (out << "<null>"));
  out << ")";
}


DeviceConfigOptions::~DeviceConfigOptions() noexcept {
}


void DeviceConfigOptions::__set_useDiagForPdc(const bool val) {
  this->useDiagForPdc = val;
__isset.useDiagForPdc = true;
}

void DeviceConfigOptions::__set_xqcnOperationType(const  ::Uts::XqcnOperationType::type val) {
  this->xqcnOperationType = val;
__isset.xqcnOperationType = true;
}

void DeviceConfigOptions::__set_xqcnRestoreOptions(const  ::Uts::XqcnRestoreOptions& val) {
  this->xqcnRestoreOptions = val;
__isset.xqcnRestoreOptions = true;
}

void DeviceConfigOptions::__set_xqcnBackupOptions(const  ::Uts::XqcnBackupOptions& val) {
  this->xqcnBackupOptions = val;
__isset.xqcnBackupOptions = true;
}
std::ostream& operator<<(std::ostream& out, const DeviceConfigOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DeviceConfigOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->useDiagForPdc);
          this->__isset.useDiagForPdc = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast25;
          xfer += iprot->readI32(ecast25);
          this->xqcnOperationType = ( ::Uts::XqcnOperationType::type)ecast25;
          this->__isset.xqcnOperationType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->xqcnRestoreOptions.read(iprot);
          this->__isset.xqcnRestoreOptions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->xqcnBackupOptions.read(iprot);
          this->__isset.xqcnBackupOptions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t DeviceConfigOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigOptions");

  if (this->__isset.useDiagForPdc) {
    xfer += oprot->writeFieldBegin("useDiagForPdc", ::apache::thrift::protocol::T_BOOL, 1);
    xfer += oprot->writeBool(this->useDiagForPdc);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.xqcnOperationType) {
    xfer += oprot->writeFieldBegin("xqcnOperationType", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->xqcnOperationType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.xqcnRestoreOptions) {
    xfer += oprot->writeFieldBegin("xqcnRestoreOptions", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->xqcnRestoreOptions.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.xqcnBackupOptions) {
    xfer += oprot->writeFieldBegin("xqcnBackupOptions", ::apache::thrift::protocol::T_STRUCT, 4);
    xfer += this->xqcnBackupOptions.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DeviceConfigOptions &a, DeviceConfigOptions &b) {
  using ::std::swap;
  swap(a.useDiagForPdc, b.useDiagForPdc);
  swap(a.xqcnOperationType, b.xqcnOperationType);
  swap(a.xqcnRestoreOptions, b.xqcnRestoreOptions);
  swap(a.xqcnBackupOptions, b.xqcnBackupOptions);
  swap(a.__isset, b.__isset);
}

DeviceConfigOptions::DeviceConfigOptions(const DeviceConfigOptions& other26) {
  useDiagForPdc = other26.useDiagForPdc;
  xqcnOperationType = other26.xqcnOperationType;
  xqcnRestoreOptions = other26.xqcnRestoreOptions;
  xqcnBackupOptions = other26.xqcnBackupOptions;
  __isset = other26.__isset;
}
DeviceConfigOptions& DeviceConfigOptions::operator=(const DeviceConfigOptions& other27) {
  useDiagForPdc = other27.useDiagForPdc;
  xqcnOperationType = other27.xqcnOperationType;
  xqcnRestoreOptions = other27.xqcnRestoreOptions;
  xqcnBackupOptions = other27.xqcnBackupOptions;
  __isset = other27.__isset;
  return *this;
}
void DeviceConfigOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DeviceConfigOptions(";
  out << "useDiagForPdc="; (__isset.useDiagForPdc ? (out << to_string(useDiagForPdc)) : (out << "<null>"));
  out << ", " << "xqcnOperationType="; (__isset.xqcnOperationType ? (out << to_string(xqcnOperationType)) : (out << "<null>"));
  out << ", " << "xqcnRestoreOptions="; (__isset.xqcnRestoreOptions ? (out << to_string(xqcnRestoreOptions)) : (out << "<null>"));
  out << ", " << "xqcnBackupOptions="; (__isset.xqcnBackupOptions ? (out << to_string(xqcnBackupOptions)) : (out << "<null>"));
  out << ")";
}

} // namespace
