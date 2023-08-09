/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "ImageManagementService_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {

int _kDeviceImageModeValues[] = {
  DeviceImageMode::DEVICE_IMAGE_MODE_NONE,
  DeviceImageMode::DEVICE_IMAGE_MODE_SAHARA_DOWNLOAD,
  DeviceImageMode::DEVICE_IMAGE_MODE_SAHARA_CRASH,
  DeviceImageMode::DEVICE_IMAGE_MODE_SAHARA_EFS_SYNC
};
const char* _kDeviceImageModeNames[] = {
  "DEVICE_IMAGE_MODE_NONE",
  "DEVICE_IMAGE_MODE_SAHARA_DOWNLOAD",
  "DEVICE_IMAGE_MODE_SAHARA_CRASH",
  "DEVICE_IMAGE_MODE_SAHARA_EFS_SYNC"
};
const std::map<int, const char*> _DeviceImageMode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kDeviceImageModeValues, _kDeviceImageModeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DeviceImageMode::type& val) {
  std::map<int, const char*>::const_iterator it = _DeviceImageMode_VALUES_TO_NAMES.find(val);
  if (it != _DeviceImageMode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DeviceImageMode::type& val) {
  std::map<int, const char*>::const_iterator it = _DeviceImageMode_VALUES_TO_NAMES.find(val);
  if (it != _DeviceImageMode_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kMemoryTypeValues[] = {
  MemoryType::MEMORY_TYPE_EMMC,
  MemoryType::MEMORY_TYPE_UFS,
  MemoryType::MEMORY_TYPE_NAND,
  MemoryType::MEMORY_TYPE_NVME,
  MemoryType::MEMORY_TYPE_SPINOR,
  MemoryType::MEMORY_TYPE_UNKNOWN
};
const char* _kMemoryTypeNames[] = {
  "MEMORY_TYPE_EMMC",
  "MEMORY_TYPE_UFS",
  "MEMORY_TYPE_NAND",
  "MEMORY_TYPE_NVME",
  "MEMORY_TYPE_SPINOR",
  "MEMORY_TYPE_UNKNOWN"
};
const std::map<int, const char*> _MemoryType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(6, _kMemoryTypeValues, _kMemoryTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const MemoryType::type& val) {
  std::map<int, const char*>::const_iterator it = _MemoryType_VALUES_TO_NAMES.find(val);
  if (it != _MemoryType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const MemoryType::type& val) {
  std::map<int, const char*>::const_iterator it = _MemoryType_VALUES_TO_NAMES.find(val);
  if (it != _MemoryType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kValidationModeValues[] = {
  ValidationMode::VALIDATION_MODE_NONE,
  ValidationMode::VALIDATION_MODE_BINARY_READBACK,
  ValidationMode::VALIDATION_MODE_SHA256_READBACK,
  ValidationMode::VALIDATION_MODE_BINARY_READBACK_WITH_DIGESTS_FILE,
  ValidationMode::VALIDATION_MODE_SHA256_READBACK_WITH_DIGESTS_FILE
};
const char* _kValidationModeNames[] = {
  "VALIDATION_MODE_NONE",
  "VALIDATION_MODE_BINARY_READBACK",
  "VALIDATION_MODE_SHA256_READBACK",
  "VALIDATION_MODE_BINARY_READBACK_WITH_DIGESTS_FILE",
  "VALIDATION_MODE_SHA256_READBACK_WITH_DIGESTS_FILE"
};
const std::map<int, const char*> _ValidationMode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(5, _kValidationModeValues, _kValidationModeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ValidationMode::type& val) {
  std::map<int, const char*>::const_iterator it = _ValidationMode_VALUES_TO_NAMES.find(val);
  if (it != _ValidationMode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ValidationMode::type& val) {
  std::map<int, const char*>::const_iterator it = _ValidationMode_VALUES_TO_NAMES.find(val);
  if (it != _ValidationMode_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kPreservationModeValues[] = {
  PreservationMode::PRESERVATION_NONE,
  PreservationMode::PRESERVATION_BACKUP_RESTORE
};
const char* _kPreservationModeNames[] = {
  "PRESERVATION_NONE",
  "PRESERVATION_BACKUP_RESTORE"
};
const std::map<int, const char*> _PreservationMode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(2, _kPreservationModeValues, _kPreservationModeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const PreservationMode::type& val) {
  std::map<int, const char*>::const_iterator it = _PreservationMode_VALUES_TO_NAMES.find(val);
  if (it != _PreservationMode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const PreservationMode::type& val) {
  std::map<int, const char*>::const_iterator it = _PreservationMode_VALUES_TO_NAMES.find(val);
  if (it != _PreservationMode_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDigestHeaderTypeValues[] = {
  DigestHeaderType::DIGEST_HEADER_TYPE_NONE,
  DigestHeaderType::DIGEST_HEADER_TYPE_ELF,
  DigestHeaderType::DIGEST_HEADER_TYPE_MBN
};
const char* _kDigestHeaderTypeNames[] = {
  "DIGEST_HEADER_TYPE_NONE",
  "DIGEST_HEADER_TYPE_ELF",
  "DIGEST_HEADER_TYPE_MBN"
};
const std::map<int, const char*> _DigestHeaderType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kDigestHeaderTypeValues, _kDigestHeaderTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DigestHeaderType::type& val) {
  std::map<int, const char*>::const_iterator it = _DigestHeaderType_VALUES_TO_NAMES.find(val);
  if (it != _DigestHeaderType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DigestHeaderType::type& val) {
  std::map<int, const char*>::const_iterator it = _DigestHeaderType_VALUES_TO_NAMES.find(val);
  if (it != _DigestHeaderType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


EdlDeviceInfo::~EdlDeviceInfo() noexcept {
}


void EdlDeviceInfo::__set_serialNumber(const std::string& val) {
  this->serialNumber = val;
}

void EdlDeviceInfo::__set_msmHwId(const std::string& val) {
  this->msmHwId = val;
}
std::ostream& operator<<(std::ostream& out, const EdlDeviceInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t EdlDeviceInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->serialNumber);
          this->__isset.serialNumber = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->msmHwId);
          this->__isset.msmHwId = true;
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

uint32_t EdlDeviceInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EdlDeviceInfo");

  xfer += oprot->writeFieldBegin("serialNumber", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->serialNumber);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("msmHwId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->msmHwId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EdlDeviceInfo &a, EdlDeviceInfo &b) {
  using ::std::swap;
  swap(a.serialNumber, b.serialNumber);
  swap(a.msmHwId, b.msmHwId);
  swap(a.__isset, b.__isset);
}

EdlDeviceInfo::EdlDeviceInfo(const EdlDeviceInfo& other0) {
  serialNumber = other0.serialNumber;
  msmHwId = other0.msmHwId;
  __isset = other0.__isset;
}
EdlDeviceInfo& EdlDeviceInfo::operator=(const EdlDeviceInfo& other1) {
  serialNumber = other1.serialNumber;
  msmHwId = other1.msmHwId;
  __isset = other1.__isset;
  return *this;
}
void EdlDeviceInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "EdlDeviceInfo(";
  out << "serialNumber=" << to_string(serialNumber);
  out << ", " << "msmHwId=" << to_string(msmHwId);
  out << ")";
}


TransferImageResult::~TransferImageResult() noexcept {
}


void TransferImageResult::__set_errorCode(const  ::Uts::ErrorCode::type val) {
  this->errorCode = val;
}

void TransferImageResult::__set_deviceImageMode(const DeviceImageMode::type val) {
  this->deviceImageMode = val;
}
std::ostream& operator<<(std::ostream& out, const TransferImageResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t TransferImageResult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast2;
          xfer += iprot->readI32(ecast2);
          this->errorCode = ( ::Uts::ErrorCode::type)ecast2;
          this->__isset.errorCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast3;
          xfer += iprot->readI32(ecast3);
          this->deviceImageMode = (DeviceImageMode::type)ecast3;
          this->__isset.deviceImageMode = true;
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

uint32_t TransferImageResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("TransferImageResult");

  xfer += oprot->writeFieldBegin("errorCode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->errorCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceImageMode", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->deviceImageMode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(TransferImageResult &a, TransferImageResult &b) {
  using ::std::swap;
  swap(a.errorCode, b.errorCode);
  swap(a.deviceImageMode, b.deviceImageMode);
  swap(a.__isset, b.__isset);
}

TransferImageResult::TransferImageResult(const TransferImageResult& other4) {
  errorCode = other4.errorCode;
  deviceImageMode = other4.deviceImageMode;
  __isset = other4.__isset;
}
TransferImageResult& TransferImageResult::operator=(const TransferImageResult& other5) {
  errorCode = other5.errorCode;
  deviceImageMode = other5.deviceImageMode;
  __isset = other5.__isset;
  return *this;
}
void TransferImageResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "TransferImageResult(";
  out << "errorCode=" << to_string(errorCode);
  out << ", " << "deviceImageMode=" << to_string(deviceImageMode);
  out << ")";
}


PreservedPartitionInfo::~PreservedPartitionInfo() noexcept {
}


void PreservedPartitionInfo::__set_partitionIndex(const std::string& val) {
  this->partitionIndex = val;
}

void PreservedPartitionInfo::__set_name(const std::string& val) {
  this->name = val;
}
std::ostream& operator<<(std::ostream& out, const PreservedPartitionInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t PreservedPartitionInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->partitionIndex);
          this->__isset.partitionIndex = true;
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
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t PreservedPartitionInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PreservedPartitionInfo");

  xfer += oprot->writeFieldBegin("partitionIndex", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->partitionIndex);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PreservedPartitionInfo &a, PreservedPartitionInfo &b) {
  using ::std::swap;
  swap(a.partitionIndex, b.partitionIndex);
  swap(a.name, b.name);
  swap(a.__isset, b.__isset);
}

PreservedPartitionInfo::PreservedPartitionInfo(const PreservedPartitionInfo& other6) {
  partitionIndex = other6.partitionIndex;
  name = other6.name;
  __isset = other6.__isset;
}
PreservedPartitionInfo& PreservedPartitionInfo::operator=(const PreservedPartitionInfo& other7) {
  partitionIndex = other7.partitionIndex;
  name = other7.name;
  __isset = other7.__isset;
  return *this;
}
void PreservedPartitionInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PreservedPartitionInfo(";
  out << "partitionIndex=" << to_string(partitionIndex);
  out << ", " << "name=" << to_string(name);
  out << ")";
}


PreservationOption::~PreservationOption() noexcept {
}


void PreservationOption::__set_preservationMode(const PreservationMode::type val) {
  this->preservationMode = val;
}

void PreservationOption::__set_preservedPartitions(const std::vector<PreservedPartitionInfo> & val) {
  this->preservedPartitions = val;
__isset.preservedPartitions = true;
}
std::ostream& operator<<(std::ostream& out, const PreservationOption& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t PreservationOption::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast8;
          xfer += iprot->readI32(ecast8);
          this->preservationMode = (PreservationMode::type)ecast8;
          this->__isset.preservationMode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->preservedPartitions.clear();
            uint32_t _size9;
            ::apache::thrift::protocol::TType _etype12;
            xfer += iprot->readListBegin(_etype12, _size9);
            this->preservedPartitions.resize(_size9);
            uint32_t _i13;
            for (_i13 = 0; _i13 < _size9; ++_i13)
            {
              xfer += this->preservedPartitions[_i13].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.preservedPartitions = true;
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

uint32_t PreservationOption::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PreservationOption");

  xfer += oprot->writeFieldBegin("preservationMode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->preservationMode);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.preservedPartitions) {
    xfer += oprot->writeFieldBegin("preservedPartitions", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->preservedPartitions.size()));
      std::vector<PreservedPartitionInfo> ::const_iterator _iter14;
      for (_iter14 = this->preservedPartitions.begin(); _iter14 != this->preservedPartitions.end(); ++_iter14)
      {
        xfer += (*_iter14).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PreservationOption &a, PreservationOption &b) {
  using ::std::swap;
  swap(a.preservationMode, b.preservationMode);
  swap(a.preservedPartitions, b.preservedPartitions);
  swap(a.__isset, b.__isset);
}

PreservationOption::PreservationOption(const PreservationOption& other15) {
  preservationMode = other15.preservationMode;
  preservedPartitions = other15.preservedPartitions;
  __isset = other15.__isset;
}
PreservationOption& PreservationOption::operator=(const PreservationOption& other16) {
  preservationMode = other16.preservationMode;
  preservedPartitions = other16.preservedPartitions;
  __isset = other16.__isset;
  return *this;
}
void PreservationOption::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PreservationOption(";
  out << "preservationMode=" << to_string(preservationMode);
  out << ", " << "preservedPartitions="; (__isset.preservedPartitions ? (out << to_string(preservedPartitions)) : (out << "<null>"));
  out << ")";
}


DownloadBuildOptions::~DownloadBuildOptions() noexcept {
}


void DownloadBuildOptions::__set_memoryType(const MemoryType::type val) {
  this->memoryType = val;
}

void DownloadBuildOptions::__set_erase(const bool val) {
  this->erase = val;
__isset.erase = true;
}

void DownloadBuildOptions::__set_rawXmlList(const std::vector<std::string> & val) {
  this->rawXmlList = val;
__isset.rawXmlList = true;
}

void DownloadBuildOptions::__set_patchXmlList(const std::vector<std::string> & val) {
  this->patchXmlList = val;
__isset.patchXmlList = true;
}

void DownloadBuildOptions::__set_firehoseProgPath(const std::string& val) {
  this->firehoseProgPath = val;
__isset.firehoseProgPath = true;
}

void DownloadBuildOptions::__set_signedDigestsPath(const std::string& val) {
  this->signedDigestsPath = val;
__isset.signedDigestsPath = true;
}

void DownloadBuildOptions::__set_chainedDigestsPath(const std::string& val) {
  this->chainedDigestsPath = val;
__isset.chainedDigestsPath = true;
}

void DownloadBuildOptions::__set_skipSahara(const bool val) {
  this->skipSahara = val;
__isset.skipSahara = true;
}

void DownloadBuildOptions::__set_readImagesPath(const std::string& val) {
  this->readImagesPath = val;
__isset.readImagesPath = true;
}

void DownloadBuildOptions::__set_ufsProvisioningPath(const std::string& val) {
  this->ufsProvisioningPath = val;
__isset.ufsProvisioningPath = true;
}

void DownloadBuildOptions::__set_partitionIndexList(const std::vector<int32_t> & val) {
  this->partitionIndexList = val;
__isset.partitionIndexList = true;
}

void DownloadBuildOptions::__set_jsonPath(const std::string& val) {
  this->jsonPath = val;
__isset.jsonPath = true;
}

void DownloadBuildOptions::__set_resetAfterDownload(const bool val) {
  this->resetAfterDownload = val;
__isset.resetAfterDownload = true;
}

void DownloadBuildOptions::__set_maxPayloadSize(const int32_t val) {
  this->maxPayloadSize = val;
__isset.maxPayloadSize = true;
}

void DownloadBuildOptions::__set_readImages(const bool val) {
  this->readImages = val;
__isset.readImages = true;
}

void DownloadBuildOptions::__set_validationMode(const ValidationMode::type val) {
  this->validationMode = val;
__isset.validationMode = true;
}

void DownloadBuildOptions::__set_edmaPath(const std::string& val) {
  this->edmaPath = val;
__isset.edmaPath = true;
}

void DownloadBuildOptions::__set_preservationOption(const PreservationOption& val) {
  this->preservationOption = val;
__isset.preservationOption = true;
}

void DownloadBuildOptions::__set_singleImagePath(const std::string& val) {
  this->singleImagePath = val;
__isset.singleImagePath = true;
}

void DownloadBuildOptions::__set_slot(const int32_t val) {
  this->slot = val;
__isset.slot = true;
}

void DownloadBuildOptions::__set_digestHeaderType(const DigestHeaderType::type val) {
  this->digestHeaderType = val;
__isset.digestHeaderType = true;
}

void DownloadBuildOptions::__set_firehoseInitializeTimeInMs(const int32_t val) {
  this->firehoseInitializeTimeInMs = val;
__isset.firehoseInitializeTimeInMs = true;
}

void DownloadBuildOptions::__set_validationDigestsPath(const std::string& val) {
  this->validationDigestsPath = val;
__isset.validationDigestsPath = true;
}

void DownloadBuildOptions::__set_activePartition(const int32_t val) {
  this->activePartition = val;
__isset.activePartition = true;
}

void DownloadBuildOptions::__set_firmwarePath(const std::string& val) {
  this->firmwarePath = val;
__isset.firmwarePath = true;
}

void DownloadBuildOptions::__set_downloadRxTimeoutInMs(const int32_t val) {
  this->downloadRxTimeoutInMs = val;
__isset.downloadRxTimeoutInMs = true;
}
std::ostream& operator<<(std::ostream& out, const DownloadBuildOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DownloadBuildOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast17;
          xfer += iprot->readI32(ecast17);
          this->memoryType = (MemoryType::type)ecast17;
          this->__isset.memoryType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->erase);
          this->__isset.erase = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->rawXmlList.clear();
            uint32_t _size18;
            ::apache::thrift::protocol::TType _etype21;
            xfer += iprot->readListBegin(_etype21, _size18);
            this->rawXmlList.resize(_size18);
            uint32_t _i22;
            for (_i22 = 0; _i22 < _size18; ++_i22)
            {
              xfer += iprot->readString(this->rawXmlList[_i22]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.rawXmlList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->patchXmlList.clear();
            uint32_t _size23;
            ::apache::thrift::protocol::TType _etype26;
            xfer += iprot->readListBegin(_etype26, _size23);
            this->patchXmlList.resize(_size23);
            uint32_t _i27;
            for (_i27 = 0; _i27 < _size23; ++_i27)
            {
              xfer += iprot->readString(this->patchXmlList[_i27]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.patchXmlList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->firehoseProgPath);
          this->__isset.firehoseProgPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->signedDigestsPath);
          this->__isset.signedDigestsPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->chainedDigestsPath);
          this->__isset.chainedDigestsPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->skipSahara);
          this->__isset.skipSahara = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->readImagesPath);
          this->__isset.readImagesPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->ufsProvisioningPath);
          this->__isset.ufsProvisioningPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->partitionIndexList.clear();
            uint32_t _size28;
            ::apache::thrift::protocol::TType _etype31;
            xfer += iprot->readListBegin(_etype31, _size28);
            this->partitionIndexList.resize(_size28);
            uint32_t _i32;
            for (_i32 = 0; _i32 < _size28; ++_i32)
            {
              xfer += iprot->readI32(this->partitionIndexList[_i32]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.partitionIndexList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->jsonPath);
          this->__isset.jsonPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->resetAfterDownload);
          this->__isset.resetAfterDownload = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->maxPayloadSize);
          this->__isset.maxPayloadSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 15:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->readImages);
          this->__isset.readImages = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 16:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast33;
          xfer += iprot->readI32(ecast33);
          this->validationMode = (ValidationMode::type)ecast33;
          this->__isset.validationMode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 17:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->edmaPath);
          this->__isset.edmaPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 18:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->preservationOption.read(iprot);
          this->__isset.preservationOption = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 19:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->singleImagePath);
          this->__isset.singleImagePath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 20:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->slot);
          this->__isset.slot = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 21:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast34;
          xfer += iprot->readI32(ecast34);
          this->digestHeaderType = (DigestHeaderType::type)ecast34;
          this->__isset.digestHeaderType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 22:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->firehoseInitializeTimeInMs);
          this->__isset.firehoseInitializeTimeInMs = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 23:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->validationDigestsPath);
          this->__isset.validationDigestsPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 24:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->activePartition);
          this->__isset.activePartition = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 25:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->firmwarePath);
          this->__isset.firmwarePath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 26:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->downloadRxTimeoutInMs);
          this->__isset.downloadRxTimeoutInMs = true;
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

uint32_t DownloadBuildOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DownloadBuildOptions");

  xfer += oprot->writeFieldBegin("memoryType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->memoryType);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.erase) {
    xfer += oprot->writeFieldBegin("erase", ::apache::thrift::protocol::T_BOOL, 2);
    xfer += oprot->writeBool(this->erase);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.rawXmlList) {
    xfer += oprot->writeFieldBegin("rawXmlList", ::apache::thrift::protocol::T_LIST, 3);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->rawXmlList.size()));
      std::vector<std::string> ::const_iterator _iter35;
      for (_iter35 = this->rawXmlList.begin(); _iter35 != this->rawXmlList.end(); ++_iter35)
      {
        xfer += oprot->writeString((*_iter35));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.patchXmlList) {
    xfer += oprot->writeFieldBegin("patchXmlList", ::apache::thrift::protocol::T_LIST, 4);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->patchXmlList.size()));
      std::vector<std::string> ::const_iterator _iter36;
      for (_iter36 = this->patchXmlList.begin(); _iter36 != this->patchXmlList.end(); ++_iter36)
      {
        xfer += oprot->writeString((*_iter36));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.firehoseProgPath) {
    xfer += oprot->writeFieldBegin("firehoseProgPath", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->firehoseProgPath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.signedDigestsPath) {
    xfer += oprot->writeFieldBegin("signedDigestsPath", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->signedDigestsPath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.chainedDigestsPath) {
    xfer += oprot->writeFieldBegin("chainedDigestsPath", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->chainedDigestsPath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.skipSahara) {
    xfer += oprot->writeFieldBegin("skipSahara", ::apache::thrift::protocol::T_BOOL, 8);
    xfer += oprot->writeBool(this->skipSahara);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.readImagesPath) {
    xfer += oprot->writeFieldBegin("readImagesPath", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->readImagesPath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.ufsProvisioningPath) {
    xfer += oprot->writeFieldBegin("ufsProvisioningPath", ::apache::thrift::protocol::T_STRING, 10);
    xfer += oprot->writeString(this->ufsProvisioningPath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.partitionIndexList) {
    xfer += oprot->writeFieldBegin("partitionIndexList", ::apache::thrift::protocol::T_LIST, 11);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->partitionIndexList.size()));
      std::vector<int32_t> ::const_iterator _iter37;
      for (_iter37 = this->partitionIndexList.begin(); _iter37 != this->partitionIndexList.end(); ++_iter37)
      {
        xfer += oprot->writeI32((*_iter37));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.jsonPath) {
    xfer += oprot->writeFieldBegin("jsonPath", ::apache::thrift::protocol::T_STRING, 12);
    xfer += oprot->writeString(this->jsonPath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.resetAfterDownload) {
    xfer += oprot->writeFieldBegin("resetAfterDownload", ::apache::thrift::protocol::T_BOOL, 13);
    xfer += oprot->writeBool(this->resetAfterDownload);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.maxPayloadSize) {
    xfer += oprot->writeFieldBegin("maxPayloadSize", ::apache::thrift::protocol::T_I32, 14);
    xfer += oprot->writeI32(this->maxPayloadSize);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.readImages) {
    xfer += oprot->writeFieldBegin("readImages", ::apache::thrift::protocol::T_BOOL, 15);
    xfer += oprot->writeBool(this->readImages);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.validationMode) {
    xfer += oprot->writeFieldBegin("validationMode", ::apache::thrift::protocol::T_I32, 16);
    xfer += oprot->writeI32((int32_t)this->validationMode);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.edmaPath) {
    xfer += oprot->writeFieldBegin("edmaPath", ::apache::thrift::protocol::T_STRING, 17);
    xfer += oprot->writeString(this->edmaPath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.preservationOption) {
    xfer += oprot->writeFieldBegin("preservationOption", ::apache::thrift::protocol::T_STRUCT, 18);
    xfer += this->preservationOption.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.singleImagePath) {
    xfer += oprot->writeFieldBegin("singleImagePath", ::apache::thrift::protocol::T_STRING, 19);
    xfer += oprot->writeString(this->singleImagePath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.slot) {
    xfer += oprot->writeFieldBegin("slot", ::apache::thrift::protocol::T_I32, 20);
    xfer += oprot->writeI32(this->slot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.digestHeaderType) {
    xfer += oprot->writeFieldBegin("digestHeaderType", ::apache::thrift::protocol::T_I32, 21);
    xfer += oprot->writeI32((int32_t)this->digestHeaderType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.firehoseInitializeTimeInMs) {
    xfer += oprot->writeFieldBegin("firehoseInitializeTimeInMs", ::apache::thrift::protocol::T_I32, 22);
    xfer += oprot->writeI32(this->firehoseInitializeTimeInMs);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.validationDigestsPath) {
    xfer += oprot->writeFieldBegin("validationDigestsPath", ::apache::thrift::protocol::T_STRING, 23);
    xfer += oprot->writeString(this->validationDigestsPath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.activePartition) {
    xfer += oprot->writeFieldBegin("activePartition", ::apache::thrift::protocol::T_I32, 24);
    xfer += oprot->writeI32(this->activePartition);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.firmwarePath) {
    xfer += oprot->writeFieldBegin("firmwarePath", ::apache::thrift::protocol::T_STRING, 25);
    xfer += oprot->writeString(this->firmwarePath);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.downloadRxTimeoutInMs) {
    xfer += oprot->writeFieldBegin("downloadRxTimeoutInMs", ::apache::thrift::protocol::T_I32, 26);
    xfer += oprot->writeI32(this->downloadRxTimeoutInMs);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DownloadBuildOptions &a, DownloadBuildOptions &b) {
  using ::std::swap;
  swap(a.memoryType, b.memoryType);
  swap(a.erase, b.erase);
  swap(a.rawXmlList, b.rawXmlList);
  swap(a.patchXmlList, b.patchXmlList);
  swap(a.firehoseProgPath, b.firehoseProgPath);
  swap(a.signedDigestsPath, b.signedDigestsPath);
  swap(a.chainedDigestsPath, b.chainedDigestsPath);
  swap(a.skipSahara, b.skipSahara);
  swap(a.readImagesPath, b.readImagesPath);
  swap(a.ufsProvisioningPath, b.ufsProvisioningPath);
  swap(a.partitionIndexList, b.partitionIndexList);
  swap(a.jsonPath, b.jsonPath);
  swap(a.resetAfterDownload, b.resetAfterDownload);
  swap(a.maxPayloadSize, b.maxPayloadSize);
  swap(a.readImages, b.readImages);
  swap(a.validationMode, b.validationMode);
  swap(a.edmaPath, b.edmaPath);
  swap(a.preservationOption, b.preservationOption);
  swap(a.singleImagePath, b.singleImagePath);
  swap(a.slot, b.slot);
  swap(a.digestHeaderType, b.digestHeaderType);
  swap(a.firehoseInitializeTimeInMs, b.firehoseInitializeTimeInMs);
  swap(a.validationDigestsPath, b.validationDigestsPath);
  swap(a.activePartition, b.activePartition);
  swap(a.firmwarePath, b.firmwarePath);
  swap(a.downloadRxTimeoutInMs, b.downloadRxTimeoutInMs);
  swap(a.__isset, b.__isset);
}

DownloadBuildOptions::DownloadBuildOptions(const DownloadBuildOptions& other38) {
  memoryType = other38.memoryType;
  erase = other38.erase;
  rawXmlList = other38.rawXmlList;
  patchXmlList = other38.patchXmlList;
  firehoseProgPath = other38.firehoseProgPath;
  signedDigestsPath = other38.signedDigestsPath;
  chainedDigestsPath = other38.chainedDigestsPath;
  skipSahara = other38.skipSahara;
  readImagesPath = other38.readImagesPath;
  ufsProvisioningPath = other38.ufsProvisioningPath;
  partitionIndexList = other38.partitionIndexList;
  jsonPath = other38.jsonPath;
  resetAfterDownload = other38.resetAfterDownload;
  maxPayloadSize = other38.maxPayloadSize;
  readImages = other38.readImages;
  validationMode = other38.validationMode;
  edmaPath = other38.edmaPath;
  preservationOption = other38.preservationOption;
  singleImagePath = other38.singleImagePath;
  slot = other38.slot;
  digestHeaderType = other38.digestHeaderType;
  firehoseInitializeTimeInMs = other38.firehoseInitializeTimeInMs;
  validationDigestsPath = other38.validationDigestsPath;
  activePartition = other38.activePartition;
  firmwarePath = other38.firmwarePath;
  downloadRxTimeoutInMs = other38.downloadRxTimeoutInMs;
  __isset = other38.__isset;
}
DownloadBuildOptions& DownloadBuildOptions::operator=(const DownloadBuildOptions& other39) {
  memoryType = other39.memoryType;
  erase = other39.erase;
  rawXmlList = other39.rawXmlList;
  patchXmlList = other39.patchXmlList;
  firehoseProgPath = other39.firehoseProgPath;
  signedDigestsPath = other39.signedDigestsPath;
  chainedDigestsPath = other39.chainedDigestsPath;
  skipSahara = other39.skipSahara;
  readImagesPath = other39.readImagesPath;
  ufsProvisioningPath = other39.ufsProvisioningPath;
  partitionIndexList = other39.partitionIndexList;
  jsonPath = other39.jsonPath;
  resetAfterDownload = other39.resetAfterDownload;
  maxPayloadSize = other39.maxPayloadSize;
  readImages = other39.readImages;
  validationMode = other39.validationMode;
  edmaPath = other39.edmaPath;
  preservationOption = other39.preservationOption;
  singleImagePath = other39.singleImagePath;
  slot = other39.slot;
  digestHeaderType = other39.digestHeaderType;
  firehoseInitializeTimeInMs = other39.firehoseInitializeTimeInMs;
  validationDigestsPath = other39.validationDigestsPath;
  activePartition = other39.activePartition;
  firmwarePath = other39.firmwarePath;
  downloadRxTimeoutInMs = other39.downloadRxTimeoutInMs;
  __isset = other39.__isset;
  return *this;
}
void DownloadBuildOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DownloadBuildOptions(";
  out << "memoryType=" << to_string(memoryType);
  out << ", " << "erase="; (__isset.erase ? (out << to_string(erase)) : (out << "<null>"));
  out << ", " << "rawXmlList="; (__isset.rawXmlList ? (out << to_string(rawXmlList)) : (out << "<null>"));
  out << ", " << "patchXmlList="; (__isset.patchXmlList ? (out << to_string(patchXmlList)) : (out << "<null>"));
  out << ", " << "firehoseProgPath="; (__isset.firehoseProgPath ? (out << to_string(firehoseProgPath)) : (out << "<null>"));
  out << ", " << "signedDigestsPath="; (__isset.signedDigestsPath ? (out << to_string(signedDigestsPath)) : (out << "<null>"));
  out << ", " << "chainedDigestsPath="; (__isset.chainedDigestsPath ? (out << to_string(chainedDigestsPath)) : (out << "<null>"));
  out << ", " << "skipSahara="; (__isset.skipSahara ? (out << to_string(skipSahara)) : (out << "<null>"));
  out << ", " << "readImagesPath="; (__isset.readImagesPath ? (out << to_string(readImagesPath)) : (out << "<null>"));
  out << ", " << "ufsProvisioningPath="; (__isset.ufsProvisioningPath ? (out << to_string(ufsProvisioningPath)) : (out << "<null>"));
  out << ", " << "partitionIndexList="; (__isset.partitionIndexList ? (out << to_string(partitionIndexList)) : (out << "<null>"));
  out << ", " << "jsonPath="; (__isset.jsonPath ? (out << to_string(jsonPath)) : (out << "<null>"));
  out << ", " << "resetAfterDownload="; (__isset.resetAfterDownload ? (out << to_string(resetAfterDownload)) : (out << "<null>"));
  out << ", " << "maxPayloadSize="; (__isset.maxPayloadSize ? (out << to_string(maxPayloadSize)) : (out << "<null>"));
  out << ", " << "readImages="; (__isset.readImages ? (out << to_string(readImages)) : (out << "<null>"));
  out << ", " << "validationMode="; (__isset.validationMode ? (out << to_string(validationMode)) : (out << "<null>"));
  out << ", " << "edmaPath="; (__isset.edmaPath ? (out << to_string(edmaPath)) : (out << "<null>"));
  out << ", " << "preservationOption="; (__isset.preservationOption ? (out << to_string(preservationOption)) : (out << "<null>"));
  out << ", " << "singleImagePath="; (__isset.singleImagePath ? (out << to_string(singleImagePath)) : (out << "<null>"));
  out << ", " << "slot="; (__isset.slot ? (out << to_string(slot)) : (out << "<null>"));
  out << ", " << "digestHeaderType="; (__isset.digestHeaderType ? (out << to_string(digestHeaderType)) : (out << "<null>"));
  out << ", " << "firehoseInitializeTimeInMs="; (__isset.firehoseInitializeTimeInMs ? (out << to_string(firehoseInitializeTimeInMs)) : (out << "<null>"));
  out << ", " << "validationDigestsPath="; (__isset.validationDigestsPath ? (out << to_string(validationDigestsPath)) : (out << "<null>"));
  out << ", " << "activePartition="; (__isset.activePartition ? (out << to_string(activePartition)) : (out << "<null>"));
  out << ", " << "firmwarePath="; (__isset.firmwarePath ? (out << to_string(firmwarePath)) : (out << "<null>"));
  out << ", " << "downloadRxTimeoutInMs="; (__isset.downloadRxTimeoutInMs ? (out << to_string(downloadRxTimeoutInMs)) : (out << "<null>"));
  out << ")";
}


PartitionInfo::~PartitionInfo() noexcept {
}


void PartitionInfo::__set_lun(const int32_t val) {
  this->lun = val;
}

void PartitionInfo::__set_name(const std::string& val) {
  this->name = val;
}

void PartitionInfo::__set_partitionTypeGuid(const std::string& val) {
  this->partitionTypeGuid = val;
}

void PartitionInfo::__set_uniquePartitionGuid(const std::string& val) {
  this->uniquePartitionGuid = val;
}

void PartitionInfo::__set_startingLba(const int64_t val) {
  this->startingLba = val;
}

void PartitionInfo::__set_endingLba(const int64_t val) {
  this->endingLba = val;
}

void PartitionInfo::__set_attributes(const int64_t val) {
  this->attributes = val;
}
std::ostream& operator<<(std::ostream& out, const PartitionInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t PartitionInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->lun);
          this->__isset.lun = true;
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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->partitionTypeGuid);
          this->__isset.partitionTypeGuid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->uniquePartitionGuid);
          this->__isset.uniquePartitionGuid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->startingLba);
          this->__isset.startingLba = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->endingLba);
          this->__isset.endingLba = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->attributes);
          this->__isset.attributes = true;
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

uint32_t PartitionInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PartitionInfo");

  xfer += oprot->writeFieldBegin("lun", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->lun);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("name", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->name);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("partitionTypeGuid", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->partitionTypeGuid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("uniquePartitionGuid", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->uniquePartitionGuid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("startingLba", ::apache::thrift::protocol::T_I64, 5);
  xfer += oprot->writeI64(this->startingLba);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("endingLba", ::apache::thrift::protocol::T_I64, 6);
  xfer += oprot->writeI64(this->endingLba);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("attributes", ::apache::thrift::protocol::T_I64, 7);
  xfer += oprot->writeI64(this->attributes);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PartitionInfo &a, PartitionInfo &b) {
  using ::std::swap;
  swap(a.lun, b.lun);
  swap(a.name, b.name);
  swap(a.partitionTypeGuid, b.partitionTypeGuid);
  swap(a.uniquePartitionGuid, b.uniquePartitionGuid);
  swap(a.startingLba, b.startingLba);
  swap(a.endingLba, b.endingLba);
  swap(a.attributes, b.attributes);
  swap(a.__isset, b.__isset);
}

PartitionInfo::PartitionInfo(const PartitionInfo& other40) {
  lun = other40.lun;
  name = other40.name;
  partitionTypeGuid = other40.partitionTypeGuid;
  uniquePartitionGuid = other40.uniquePartitionGuid;
  startingLba = other40.startingLba;
  endingLba = other40.endingLba;
  attributes = other40.attributes;
  __isset = other40.__isset;
}
PartitionInfo& PartitionInfo::operator=(const PartitionInfo& other41) {
  lun = other41.lun;
  name = other41.name;
  partitionTypeGuid = other41.partitionTypeGuid;
  uniquePartitionGuid = other41.uniquePartitionGuid;
  startingLba = other41.startingLba;
  endingLba = other41.endingLba;
  attributes = other41.attributes;
  __isset = other41.__isset;
  return *this;
}
void PartitionInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PartitionInfo(";
  out << "lun=" << to_string(lun);
  out << ", " << "name=" << to_string(name);
  out << ", " << "partitionTypeGuid=" << to_string(partitionTypeGuid);
  out << ", " << "uniquePartitionGuid=" << to_string(uniquePartitionGuid);
  out << ", " << "startingLba=" << to_string(startingLba);
  out << ", " << "endingLba=" << to_string(endingLba);
  out << ", " << "attributes=" << to_string(attributes);
  out << ")";
}


FlashInfo::~FlashInfo() noexcept {
}


void FlashInfo::__set_totalBlocks(const std::string& val) {
  this->totalBlocks = val;
__isset.totalBlocks = true;
}

void FlashInfo::__set_blockSize(const std::string& val) {
  this->blockSize = val;
__isset.blockSize = true;
}

void FlashInfo::__set_pageSize(const std::string& val) {
  this->pageSize = val;
__isset.pageSize = true;
}

void FlashInfo::__set_numPhysicalPartitions(const std::string& val) {
  this->numPhysicalPartitions = val;
__isset.numPhysicalPartitions = true;
}

void FlashInfo::__set_manufacturerId(const std::string& val) {
  this->manufacturerId = val;
__isset.manufacturerId = true;
}

void FlashInfo::__set_serialNum(const std::string& val) {
  this->serialNum = val;
__isset.serialNum = true;
}

void FlashInfo::__set_fwVersion(const std::string& val) {
  this->fwVersion = val;
__isset.fwVersion = true;
}

void FlashInfo::__set_memType(const std::string& val) {
  this->memType = val;
__isset.memType = true;
}

void FlashInfo::__set_prodName(const std::string& val) {
  this->prodName = val;
__isset.prodName = true;
}
std::ostream& operator<<(std::ostream& out, const FlashInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t FlashInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->totalBlocks);
          this->__isset.totalBlocks = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->blockSize);
          this->__isset.blockSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->pageSize);
          this->__isset.pageSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->numPhysicalPartitions);
          this->__isset.numPhysicalPartitions = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->manufacturerId);
          this->__isset.manufacturerId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->serialNum);
          this->__isset.serialNum = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->fwVersion);
          this->__isset.fwVersion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->memType);
          this->__isset.memType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->prodName);
          this->__isset.prodName = true;
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

uint32_t FlashInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FlashInfo");

  if (this->__isset.totalBlocks) {
    xfer += oprot->writeFieldBegin("totalBlocks", ::apache::thrift::protocol::T_STRING, 1);
    xfer += oprot->writeString(this->totalBlocks);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.blockSize) {
    xfer += oprot->writeFieldBegin("blockSize", ::apache::thrift::protocol::T_STRING, 2);
    xfer += oprot->writeString(this->blockSize);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.pageSize) {
    xfer += oprot->writeFieldBegin("pageSize", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->pageSize);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.numPhysicalPartitions) {
    xfer += oprot->writeFieldBegin("numPhysicalPartitions", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->numPhysicalPartitions);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.manufacturerId) {
    xfer += oprot->writeFieldBegin("manufacturerId", ::apache::thrift::protocol::T_STRING, 5);
    xfer += oprot->writeString(this->manufacturerId);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.serialNum) {
    xfer += oprot->writeFieldBegin("serialNum", ::apache::thrift::protocol::T_STRING, 6);
    xfer += oprot->writeString(this->serialNum);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.fwVersion) {
    xfer += oprot->writeFieldBegin("fwVersion", ::apache::thrift::protocol::T_STRING, 7);
    xfer += oprot->writeString(this->fwVersion);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.memType) {
    xfer += oprot->writeFieldBegin("memType", ::apache::thrift::protocol::T_STRING, 8);
    xfer += oprot->writeString(this->memType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.prodName) {
    xfer += oprot->writeFieldBegin("prodName", ::apache::thrift::protocol::T_STRING, 9);
    xfer += oprot->writeString(this->prodName);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(FlashInfo &a, FlashInfo &b) {
  using ::std::swap;
  swap(a.totalBlocks, b.totalBlocks);
  swap(a.blockSize, b.blockSize);
  swap(a.pageSize, b.pageSize);
  swap(a.numPhysicalPartitions, b.numPhysicalPartitions);
  swap(a.manufacturerId, b.manufacturerId);
  swap(a.serialNum, b.serialNum);
  swap(a.fwVersion, b.fwVersion);
  swap(a.memType, b.memType);
  swap(a.prodName, b.prodName);
  swap(a.__isset, b.__isset);
}

FlashInfo::FlashInfo(const FlashInfo& other42) {
  totalBlocks = other42.totalBlocks;
  blockSize = other42.blockSize;
  pageSize = other42.pageSize;
  numPhysicalPartitions = other42.numPhysicalPartitions;
  manufacturerId = other42.manufacturerId;
  serialNum = other42.serialNum;
  fwVersion = other42.fwVersion;
  memType = other42.memType;
  prodName = other42.prodName;
  __isset = other42.__isset;
}
FlashInfo& FlashInfo::operator=(const FlashInfo& other43) {
  totalBlocks = other43.totalBlocks;
  blockSize = other43.blockSize;
  pageSize = other43.pageSize;
  numPhysicalPartitions = other43.numPhysicalPartitions;
  manufacturerId = other43.manufacturerId;
  serialNum = other43.serialNum;
  fwVersion = other43.fwVersion;
  memType = other43.memType;
  prodName = other43.prodName;
  __isset = other43.__isset;
  return *this;
}
void FlashInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "FlashInfo(";
  out << "totalBlocks="; (__isset.totalBlocks ? (out << to_string(totalBlocks)) : (out << "<null>"));
  out << ", " << "blockSize="; (__isset.blockSize ? (out << to_string(blockSize)) : (out << "<null>"));
  out << ", " << "pageSize="; (__isset.pageSize ? (out << to_string(pageSize)) : (out << "<null>"));
  out << ", " << "numPhysicalPartitions="; (__isset.numPhysicalPartitions ? (out << to_string(numPhysicalPartitions)) : (out << "<null>"));
  out << ", " << "manufacturerId="; (__isset.manufacturerId ? (out << to_string(manufacturerId)) : (out << "<null>"));
  out << ", " << "serialNum="; (__isset.serialNum ? (out << to_string(serialNum)) : (out << "<null>"));
  out << ", " << "fwVersion="; (__isset.fwVersion ? (out << to_string(fwVersion)) : (out << "<null>"));
  out << ", " << "memType="; (__isset.memType ? (out << to_string(memType)) : (out << "<null>"));
  out << ", " << "prodName="; (__isset.prodName ? (out << to_string(prodName)) : (out << "<null>"));
  out << ")";
}


DataChunkOptions::~DataChunkOptions() noexcept {
}


void DataChunkOptions::__set_partitionIndex(const int32_t val) {
  this->partitionIndex = val;
}

void DataChunkOptions::__set_startSector(const std::string& val) {
  this->startSector = val;
}

void DataChunkOptions::__set_sectorCount(const std::string& val) {
  this->sectorCount = val;
__isset.sectorCount = true;
}

void DataChunkOptions::__set_imagePath(const std::string& val) {
  this->imagePath = val;
__isset.imagePath = true;
}
std::ostream& operator<<(std::ostream& out, const DataChunkOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DataChunkOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->partitionIndex);
          this->__isset.partitionIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->startSector);
          this->__isset.startSector = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->sectorCount);
          this->__isset.sectorCount = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->imagePath);
          this->__isset.imagePath = true;
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

uint32_t DataChunkOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DataChunkOptions");

  xfer += oprot->writeFieldBegin("partitionIndex", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->partitionIndex);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("startSector", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->startSector);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.sectorCount) {
    xfer += oprot->writeFieldBegin("sectorCount", ::apache::thrift::protocol::T_STRING, 3);
    xfer += oprot->writeString(this->sectorCount);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.imagePath) {
    xfer += oprot->writeFieldBegin("imagePath", ::apache::thrift::protocol::T_STRING, 4);
    xfer += oprot->writeString(this->imagePath);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DataChunkOptions &a, DataChunkOptions &b) {
  using ::std::swap;
  swap(a.partitionIndex, b.partitionIndex);
  swap(a.startSector, b.startSector);
  swap(a.sectorCount, b.sectorCount);
  swap(a.imagePath, b.imagePath);
  swap(a.__isset, b.__isset);
}

DataChunkOptions::DataChunkOptions(const DataChunkOptions& other44) {
  partitionIndex = other44.partitionIndex;
  startSector = other44.startSector;
  sectorCount = other44.sectorCount;
  imagePath = other44.imagePath;
  __isset = other44.__isset;
}
DataChunkOptions& DataChunkOptions::operator=(const DataChunkOptions& other45) {
  partitionIndex = other45.partitionIndex;
  startSector = other45.startSector;
  sectorCount = other45.sectorCount;
  imagePath = other45.imagePath;
  __isset = other45.__isset;
  return *this;
}
void DataChunkOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DataChunkOptions(";
  out << "partitionIndex=" << to_string(partitionIndex);
  out << ", " << "startSector=" << to_string(startSector);
  out << ", " << "sectorCount="; (__isset.sectorCount ? (out << to_string(sectorCount)) : (out << "<null>"));
  out << ", " << "imagePath="; (__isset.imagePath ? (out << to_string(imagePath)) : (out << "<null>"));
  out << ")";
}


MemoryDumpOptions::~MemoryDumpOptions() noexcept {
}


void MemoryDumpOptions::__set_pathName(const std::string& val) {
  this->pathName = val;
}

void MemoryDumpOptions::__set_sectionNameList(const std::vector<std::string> & val) {
  this->sectionNameList = val;
__isset.sectionNameList = true;
}
std::ostream& operator<<(std::ostream& out, const MemoryDumpOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t MemoryDumpOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->pathName);
          this->__isset.pathName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->sectionNameList.clear();
            uint32_t _size46;
            ::apache::thrift::protocol::TType _etype49;
            xfer += iprot->readListBegin(_etype49, _size46);
            this->sectionNameList.resize(_size46);
            uint32_t _i50;
            for (_i50 = 0; _i50 < _size46; ++_i50)
            {
              xfer += iprot->readString(this->sectionNameList[_i50]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.sectionNameList = true;
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

uint32_t MemoryDumpOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("MemoryDumpOptions");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.sectionNameList) {
    xfer += oprot->writeFieldBegin("sectionNameList", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->sectionNameList.size()));
      std::vector<std::string> ::const_iterator _iter51;
      for (_iter51 = this->sectionNameList.begin(); _iter51 != this->sectionNameList.end(); ++_iter51)
      {
        xfer += oprot->writeString((*_iter51));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(MemoryDumpOptions &a, MemoryDumpOptions &b) {
  using ::std::swap;
  swap(a.pathName, b.pathName);
  swap(a.sectionNameList, b.sectionNameList);
  swap(a.__isset, b.__isset);
}

MemoryDumpOptions::MemoryDumpOptions(const MemoryDumpOptions& other52) {
  pathName = other52.pathName;
  sectionNameList = other52.sectionNameList;
  __isset = other52.__isset;
}
MemoryDumpOptions& MemoryDumpOptions::operator=(const MemoryDumpOptions& other53) {
  pathName = other53.pathName;
  sectionNameList = other53.sectionNameList;
  __isset = other53.__isset;
  return *this;
}
void MemoryDumpOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "MemoryDumpOptions(";
  out << "pathName=" << to_string(pathName);
  out << ", " << "sectionNameList="; (__isset.sectionNameList ? (out << to_string(sectionNameList)) : (out << "<null>"));
  out << ")";
}

} // namespace
