/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef ImageManagementService_TYPES_H
#define ImageManagementService_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>
#include "Common_types.h"


namespace Uts {

struct DeviceImageMode {
  enum type {
    DEVICE_IMAGE_MODE_NONE = 0,
    DEVICE_IMAGE_MODE_SAHARA_DOWNLOAD = 1,
    DEVICE_IMAGE_MODE_SAHARA_CRASH = 2,
    DEVICE_IMAGE_MODE_SAHARA_EFS_SYNC = 4
  };
};

extern const std::map<int, const char*> _DeviceImageMode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DeviceImageMode::type& val);

std::string to_string(const DeviceImageMode::type& val);

struct MemoryType {
  enum type {
    MEMORY_TYPE_EMMC = 0,
    MEMORY_TYPE_UFS = 1,
    MEMORY_TYPE_NAND = 2,
    MEMORY_TYPE_NVME = 3,
    MEMORY_TYPE_SPINOR = 4,
    MEMORY_TYPE_UNKNOWN = 5
  };
};

extern const std::map<int, const char*> _MemoryType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const MemoryType::type& val);

std::string to_string(const MemoryType::type& val);

struct ValidationMode {
  enum type {
    VALIDATION_MODE_NONE = 0,
    VALIDATION_MODE_BINARY_READBACK = 1,
    VALIDATION_MODE_SHA256_READBACK = 2,
    VALIDATION_MODE_BINARY_READBACK_WITH_DIGESTS_FILE = 3,
    VALIDATION_MODE_SHA256_READBACK_WITH_DIGESTS_FILE = 4
  };
};

extern const std::map<int, const char*> _ValidationMode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ValidationMode::type& val);

std::string to_string(const ValidationMode::type& val);

struct PreservationMode {
  enum type {
    PRESERVATION_NONE = 0,
    PRESERVATION_BACKUP_RESTORE = 1
  };
};

extern const std::map<int, const char*> _PreservationMode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const PreservationMode::type& val);

std::string to_string(const PreservationMode::type& val);

struct DigestHeaderType {
  enum type {
    DIGEST_HEADER_TYPE_NONE = 0,
    DIGEST_HEADER_TYPE_ELF = 1,
    DIGEST_HEADER_TYPE_MBN = 2
  };
};

extern const std::map<int, const char*> _DigestHeaderType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DigestHeaderType::type& val);

std::string to_string(const DigestHeaderType::type& val);

class EdlDeviceInfo;

class TransferImageResult;

class PreservedPartitionInfo;

class PreservationOption;

class DownloadBuildOptions;

class PartitionInfo;

class FlashInfo;

class DataChunkOptions;

class MemoryDumpOptions;

typedef struct _EdlDeviceInfo__isset {
  _EdlDeviceInfo__isset() : serialNumber(false), msmHwId(false) {}
  bool serialNumber :1;
  bool msmHwId :1;
} _EdlDeviceInfo__isset;

class EdlDeviceInfo : public virtual ::apache::thrift::TBase {
 public:

  EdlDeviceInfo(const EdlDeviceInfo&);
  EdlDeviceInfo& operator=(const EdlDeviceInfo&);
  EdlDeviceInfo() : serialNumber(), msmHwId() {
  }

  virtual ~EdlDeviceInfo() noexcept;
  std::string serialNumber;
  std::string msmHwId;

  _EdlDeviceInfo__isset __isset;

  void __set_serialNumber(const std::string& val);

  void __set_msmHwId(const std::string& val);

  bool operator == (const EdlDeviceInfo & rhs) const
  {
    if (!(serialNumber == rhs.serialNumber))
      return false;
    if (!(msmHwId == rhs.msmHwId))
      return false;
    return true;
  }
  bool operator != (const EdlDeviceInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EdlDeviceInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(EdlDeviceInfo &a, EdlDeviceInfo &b);

std::ostream& operator<<(std::ostream& out, const EdlDeviceInfo& obj);

typedef struct _TransferImageResult__isset {
  _TransferImageResult__isset() : errorCode(false), deviceImageMode(false) {}
  bool errorCode :1;
  bool deviceImageMode :1;
} _TransferImageResult__isset;

class TransferImageResult : public virtual ::apache::thrift::TBase {
 public:

  TransferImageResult(const TransferImageResult&);
  TransferImageResult& operator=(const TransferImageResult&);
  TransferImageResult() : errorCode(( ::Uts::ErrorCode::type)0), deviceImageMode((DeviceImageMode::type)0) {
  }

  virtual ~TransferImageResult() noexcept;
   ::Uts::ErrorCode::type errorCode;
  DeviceImageMode::type deviceImageMode;

  _TransferImageResult__isset __isset;

  void __set_errorCode(const  ::Uts::ErrorCode::type val);

  void __set_deviceImageMode(const DeviceImageMode::type val);

  bool operator == (const TransferImageResult & rhs) const
  {
    if (!(errorCode == rhs.errorCode))
      return false;
    if (!(deviceImageMode == rhs.deviceImageMode))
      return false;
    return true;
  }
  bool operator != (const TransferImageResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const TransferImageResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(TransferImageResult &a, TransferImageResult &b);

std::ostream& operator<<(std::ostream& out, const TransferImageResult& obj);

typedef struct _PreservedPartitionInfo__isset {
  _PreservedPartitionInfo__isset() : partitionIndex(false), name(false) {}
  bool partitionIndex :1;
  bool name :1;
} _PreservedPartitionInfo__isset;

class PreservedPartitionInfo : public virtual ::apache::thrift::TBase {
 public:

  PreservedPartitionInfo(const PreservedPartitionInfo&);
  PreservedPartitionInfo& operator=(const PreservedPartitionInfo&);
  PreservedPartitionInfo() : partitionIndex(), name() {
  }

  virtual ~PreservedPartitionInfo() noexcept;
  std::string partitionIndex;
  std::string name;

  _PreservedPartitionInfo__isset __isset;

  void __set_partitionIndex(const std::string& val);

  void __set_name(const std::string& val);

  bool operator == (const PreservedPartitionInfo & rhs) const
  {
    if (!(partitionIndex == rhs.partitionIndex))
      return false;
    if (!(name == rhs.name))
      return false;
    return true;
  }
  bool operator != (const PreservedPartitionInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PreservedPartitionInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PreservedPartitionInfo &a, PreservedPartitionInfo &b);

std::ostream& operator<<(std::ostream& out, const PreservedPartitionInfo& obj);

typedef struct _PreservationOption__isset {
  _PreservationOption__isset() : preservationMode(false), preservedPartitions(false) {}
  bool preservationMode :1;
  bool preservedPartitions :1;
} _PreservationOption__isset;

class PreservationOption : public virtual ::apache::thrift::TBase {
 public:

  PreservationOption(const PreservationOption&);
  PreservationOption& operator=(const PreservationOption&);
  PreservationOption() : preservationMode((PreservationMode::type)0) {
  }

  virtual ~PreservationOption() noexcept;
  PreservationMode::type preservationMode;
  std::vector<PreservedPartitionInfo>  preservedPartitions;

  _PreservationOption__isset __isset;

  void __set_preservationMode(const PreservationMode::type val);

  void __set_preservedPartitions(const std::vector<PreservedPartitionInfo> & val);

  bool operator == (const PreservationOption & rhs) const
  {
    if (!(preservationMode == rhs.preservationMode))
      return false;
    if (__isset.preservedPartitions != rhs.__isset.preservedPartitions)
      return false;
    else if (__isset.preservedPartitions && !(preservedPartitions == rhs.preservedPartitions))
      return false;
    return true;
  }
  bool operator != (const PreservationOption &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PreservationOption & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PreservationOption &a, PreservationOption &b);

std::ostream& operator<<(std::ostream& out, const PreservationOption& obj);

typedef struct _DownloadBuildOptions__isset {
  _DownloadBuildOptions__isset() : memoryType(false), erase(false), rawXmlList(false), patchXmlList(false), firehoseProgPath(false), signedDigestsPath(false), chainedDigestsPath(false), skipSahara(false), readImagesPath(false), ufsProvisioningPath(false), partitionIndexList(false), jsonPath(false), resetAfterDownload(false), maxPayloadSize(false), readImages(false), validationMode(false), edmaPath(false), preservationOption(false), singleImagePath(false), slot(false), digestHeaderType(false), firehoseInitializeTimeInMs(false), validationDigestsPath(false), activePartition(false), firmwarePath(false), downloadRxTimeoutInMs(false) {}
  bool memoryType :1;
  bool erase :1;
  bool rawXmlList :1;
  bool patchXmlList :1;
  bool firehoseProgPath :1;
  bool signedDigestsPath :1;
  bool chainedDigestsPath :1;
  bool skipSahara :1;
  bool readImagesPath :1;
  bool ufsProvisioningPath :1;
  bool partitionIndexList :1;
  bool jsonPath :1;
  bool resetAfterDownload :1;
  bool maxPayloadSize :1;
  bool readImages :1;
  bool validationMode :1;
  bool edmaPath :1;
  bool preservationOption :1;
  bool singleImagePath :1;
  bool slot :1;
  bool digestHeaderType :1;
  bool firehoseInitializeTimeInMs :1;
  bool validationDigestsPath :1;
  bool activePartition :1;
  bool firmwarePath :1;
  bool downloadRxTimeoutInMs :1;
} _DownloadBuildOptions__isset;

class DownloadBuildOptions : public virtual ::apache::thrift::TBase {
 public:

  DownloadBuildOptions(const DownloadBuildOptions&);
  DownloadBuildOptions& operator=(const DownloadBuildOptions&);
  DownloadBuildOptions() : memoryType((MemoryType::type)0), erase(0), firehoseProgPath(), signedDigestsPath(), chainedDigestsPath(), skipSahara(0), readImagesPath(), ufsProvisioningPath(), jsonPath(), resetAfterDownload(0), maxPayloadSize(0), readImages(0), validationMode((ValidationMode::type)0), edmaPath(), singleImagePath(), slot(0), digestHeaderType((DigestHeaderType::type)0), firehoseInitializeTimeInMs(0), validationDigestsPath(), activePartition(0), firmwarePath(), downloadRxTimeoutInMs(0) {
  }

  virtual ~DownloadBuildOptions() noexcept;
  MemoryType::type memoryType;
  bool erase;
  std::vector<std::string>  rawXmlList;
  std::vector<std::string>  patchXmlList;
  std::string firehoseProgPath;
  std::string signedDigestsPath;
  std::string chainedDigestsPath;
  bool skipSahara;
  std::string readImagesPath;
  std::string ufsProvisioningPath;
  std::vector<int32_t>  partitionIndexList;
  std::string jsonPath;
  bool resetAfterDownload;
  int32_t maxPayloadSize;
  bool readImages;
  ValidationMode::type validationMode;
  std::string edmaPath;
  PreservationOption preservationOption;
  std::string singleImagePath;
  int32_t slot;
  DigestHeaderType::type digestHeaderType;
  int32_t firehoseInitializeTimeInMs;
  std::string validationDigestsPath;
  int32_t activePartition;
  std::string firmwarePath;
  int32_t downloadRxTimeoutInMs;

  _DownloadBuildOptions__isset __isset;

  void __set_memoryType(const MemoryType::type val);

  void __set_erase(const bool val);

  void __set_rawXmlList(const std::vector<std::string> & val);

  void __set_patchXmlList(const std::vector<std::string> & val);

  void __set_firehoseProgPath(const std::string& val);

  void __set_signedDigestsPath(const std::string& val);

  void __set_chainedDigestsPath(const std::string& val);

  void __set_skipSahara(const bool val);

  void __set_readImagesPath(const std::string& val);

  void __set_ufsProvisioningPath(const std::string& val);

  void __set_partitionIndexList(const std::vector<int32_t> & val);

  void __set_jsonPath(const std::string& val);

  void __set_resetAfterDownload(const bool val);

  void __set_maxPayloadSize(const int32_t val);

  void __set_readImages(const bool val);

  void __set_validationMode(const ValidationMode::type val);

  void __set_edmaPath(const std::string& val);

  void __set_preservationOption(const PreservationOption& val);

  void __set_singleImagePath(const std::string& val);

  void __set_slot(const int32_t val);

  void __set_digestHeaderType(const DigestHeaderType::type val);

  void __set_firehoseInitializeTimeInMs(const int32_t val);

  void __set_validationDigestsPath(const std::string& val);

  void __set_activePartition(const int32_t val);

  void __set_firmwarePath(const std::string& val);

  void __set_downloadRxTimeoutInMs(const int32_t val);

  bool operator == (const DownloadBuildOptions & rhs) const
  {
    if (!(memoryType == rhs.memoryType))
      return false;
    if (__isset.erase != rhs.__isset.erase)
      return false;
    else if (__isset.erase && !(erase == rhs.erase))
      return false;
    if (__isset.rawXmlList != rhs.__isset.rawXmlList)
      return false;
    else if (__isset.rawXmlList && !(rawXmlList == rhs.rawXmlList))
      return false;
    if (__isset.patchXmlList != rhs.__isset.patchXmlList)
      return false;
    else if (__isset.patchXmlList && !(patchXmlList == rhs.patchXmlList))
      return false;
    if (__isset.firehoseProgPath != rhs.__isset.firehoseProgPath)
      return false;
    else if (__isset.firehoseProgPath && !(firehoseProgPath == rhs.firehoseProgPath))
      return false;
    if (__isset.signedDigestsPath != rhs.__isset.signedDigestsPath)
      return false;
    else if (__isset.signedDigestsPath && !(signedDigestsPath == rhs.signedDigestsPath))
      return false;
    if (__isset.chainedDigestsPath != rhs.__isset.chainedDigestsPath)
      return false;
    else if (__isset.chainedDigestsPath && !(chainedDigestsPath == rhs.chainedDigestsPath))
      return false;
    if (__isset.skipSahara != rhs.__isset.skipSahara)
      return false;
    else if (__isset.skipSahara && !(skipSahara == rhs.skipSahara))
      return false;
    if (__isset.readImagesPath != rhs.__isset.readImagesPath)
      return false;
    else if (__isset.readImagesPath && !(readImagesPath == rhs.readImagesPath))
      return false;
    if (__isset.ufsProvisioningPath != rhs.__isset.ufsProvisioningPath)
      return false;
    else if (__isset.ufsProvisioningPath && !(ufsProvisioningPath == rhs.ufsProvisioningPath))
      return false;
    if (__isset.partitionIndexList != rhs.__isset.partitionIndexList)
      return false;
    else if (__isset.partitionIndexList && !(partitionIndexList == rhs.partitionIndexList))
      return false;
    if (__isset.jsonPath != rhs.__isset.jsonPath)
      return false;
    else if (__isset.jsonPath && !(jsonPath == rhs.jsonPath))
      return false;
    if (__isset.resetAfterDownload != rhs.__isset.resetAfterDownload)
      return false;
    else if (__isset.resetAfterDownload && !(resetAfterDownload == rhs.resetAfterDownload))
      return false;
    if (__isset.maxPayloadSize != rhs.__isset.maxPayloadSize)
      return false;
    else if (__isset.maxPayloadSize && !(maxPayloadSize == rhs.maxPayloadSize))
      return false;
    if (__isset.readImages != rhs.__isset.readImages)
      return false;
    else if (__isset.readImages && !(readImages == rhs.readImages))
      return false;
    if (__isset.validationMode != rhs.__isset.validationMode)
      return false;
    else if (__isset.validationMode && !(validationMode == rhs.validationMode))
      return false;
    if (__isset.edmaPath != rhs.__isset.edmaPath)
      return false;
    else if (__isset.edmaPath && !(edmaPath == rhs.edmaPath))
      return false;
    if (__isset.preservationOption != rhs.__isset.preservationOption)
      return false;
    else if (__isset.preservationOption && !(preservationOption == rhs.preservationOption))
      return false;
    if (__isset.singleImagePath != rhs.__isset.singleImagePath)
      return false;
    else if (__isset.singleImagePath && !(singleImagePath == rhs.singleImagePath))
      return false;
    if (__isset.slot != rhs.__isset.slot)
      return false;
    else if (__isset.slot && !(slot == rhs.slot))
      return false;
    if (__isset.digestHeaderType != rhs.__isset.digestHeaderType)
      return false;
    else if (__isset.digestHeaderType && !(digestHeaderType == rhs.digestHeaderType))
      return false;
    if (__isset.firehoseInitializeTimeInMs != rhs.__isset.firehoseInitializeTimeInMs)
      return false;
    else if (__isset.firehoseInitializeTimeInMs && !(firehoseInitializeTimeInMs == rhs.firehoseInitializeTimeInMs))
      return false;
    if (__isset.validationDigestsPath != rhs.__isset.validationDigestsPath)
      return false;
    else if (__isset.validationDigestsPath && !(validationDigestsPath == rhs.validationDigestsPath))
      return false;
    if (__isset.activePartition != rhs.__isset.activePartition)
      return false;
    else if (__isset.activePartition && !(activePartition == rhs.activePartition))
      return false;
    if (__isset.firmwarePath != rhs.__isset.firmwarePath)
      return false;
    else if (__isset.firmwarePath && !(firmwarePath == rhs.firmwarePath))
      return false;
    if (__isset.downloadRxTimeoutInMs != rhs.__isset.downloadRxTimeoutInMs)
      return false;
    else if (__isset.downloadRxTimeoutInMs && !(downloadRxTimeoutInMs == rhs.downloadRxTimeoutInMs))
      return false;
    return true;
  }
  bool operator != (const DownloadBuildOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DownloadBuildOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DownloadBuildOptions &a, DownloadBuildOptions &b);

std::ostream& operator<<(std::ostream& out, const DownloadBuildOptions& obj);

typedef struct _PartitionInfo__isset {
  _PartitionInfo__isset() : lun(false), name(false), partitionTypeGuid(false), uniquePartitionGuid(false), startingLba(false), endingLba(false), attributes(false) {}
  bool lun :1;
  bool name :1;
  bool partitionTypeGuid :1;
  bool uniquePartitionGuid :1;
  bool startingLba :1;
  bool endingLba :1;
  bool attributes :1;
} _PartitionInfo__isset;

class PartitionInfo : public virtual ::apache::thrift::TBase {
 public:

  PartitionInfo(const PartitionInfo&);
  PartitionInfo& operator=(const PartitionInfo&);
  PartitionInfo() : lun(0), name(), partitionTypeGuid(), uniquePartitionGuid(), startingLba(0), endingLba(0), attributes(0) {
  }

  virtual ~PartitionInfo() noexcept;
  int32_t lun;
  std::string name;
  std::string partitionTypeGuid;
  std::string uniquePartitionGuid;
  int64_t startingLba;
  int64_t endingLba;
  int64_t attributes;

  _PartitionInfo__isset __isset;

  void __set_lun(const int32_t val);

  void __set_name(const std::string& val);

  void __set_partitionTypeGuid(const std::string& val);

  void __set_uniquePartitionGuid(const std::string& val);

  void __set_startingLba(const int64_t val);

  void __set_endingLba(const int64_t val);

  void __set_attributes(const int64_t val);

  bool operator == (const PartitionInfo & rhs) const
  {
    if (!(lun == rhs.lun))
      return false;
    if (!(name == rhs.name))
      return false;
    if (!(partitionTypeGuid == rhs.partitionTypeGuid))
      return false;
    if (!(uniquePartitionGuid == rhs.uniquePartitionGuid))
      return false;
    if (!(startingLba == rhs.startingLba))
      return false;
    if (!(endingLba == rhs.endingLba))
      return false;
    if (!(attributes == rhs.attributes))
      return false;
    return true;
  }
  bool operator != (const PartitionInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PartitionInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PartitionInfo &a, PartitionInfo &b);

std::ostream& operator<<(std::ostream& out, const PartitionInfo& obj);

typedef struct _FlashInfo__isset {
  _FlashInfo__isset() : totalBlocks(false), blockSize(false), pageSize(false), numPhysicalPartitions(false), manufacturerId(false), serialNum(false), fwVersion(false), memType(false), prodName(false) {}
  bool totalBlocks :1;
  bool blockSize :1;
  bool pageSize :1;
  bool numPhysicalPartitions :1;
  bool manufacturerId :1;
  bool serialNum :1;
  bool fwVersion :1;
  bool memType :1;
  bool prodName :1;
} _FlashInfo__isset;

class FlashInfo : public virtual ::apache::thrift::TBase {
 public:

  FlashInfo(const FlashInfo&);
  FlashInfo& operator=(const FlashInfo&);
  FlashInfo() : totalBlocks(), blockSize(), pageSize(), numPhysicalPartitions(), manufacturerId(), serialNum(), fwVersion(), memType(), prodName() {
  }

  virtual ~FlashInfo() noexcept;
  std::string totalBlocks;
  std::string blockSize;
  std::string pageSize;
  std::string numPhysicalPartitions;
  std::string manufacturerId;
  std::string serialNum;
  std::string fwVersion;
  std::string memType;
  std::string prodName;

  _FlashInfo__isset __isset;

  void __set_totalBlocks(const std::string& val);

  void __set_blockSize(const std::string& val);

  void __set_pageSize(const std::string& val);

  void __set_numPhysicalPartitions(const std::string& val);

  void __set_manufacturerId(const std::string& val);

  void __set_serialNum(const std::string& val);

  void __set_fwVersion(const std::string& val);

  void __set_memType(const std::string& val);

  void __set_prodName(const std::string& val);

  bool operator == (const FlashInfo & rhs) const
  {
    if (__isset.totalBlocks != rhs.__isset.totalBlocks)
      return false;
    else if (__isset.totalBlocks && !(totalBlocks == rhs.totalBlocks))
      return false;
    if (__isset.blockSize != rhs.__isset.blockSize)
      return false;
    else if (__isset.blockSize && !(blockSize == rhs.blockSize))
      return false;
    if (__isset.pageSize != rhs.__isset.pageSize)
      return false;
    else if (__isset.pageSize && !(pageSize == rhs.pageSize))
      return false;
    if (__isset.numPhysicalPartitions != rhs.__isset.numPhysicalPartitions)
      return false;
    else if (__isset.numPhysicalPartitions && !(numPhysicalPartitions == rhs.numPhysicalPartitions))
      return false;
    if (__isset.manufacturerId != rhs.__isset.manufacturerId)
      return false;
    else if (__isset.manufacturerId && !(manufacturerId == rhs.manufacturerId))
      return false;
    if (__isset.serialNum != rhs.__isset.serialNum)
      return false;
    else if (__isset.serialNum && !(serialNum == rhs.serialNum))
      return false;
    if (__isset.fwVersion != rhs.__isset.fwVersion)
      return false;
    else if (__isset.fwVersion && !(fwVersion == rhs.fwVersion))
      return false;
    if (__isset.memType != rhs.__isset.memType)
      return false;
    else if (__isset.memType && !(memType == rhs.memType))
      return false;
    if (__isset.prodName != rhs.__isset.prodName)
      return false;
    else if (__isset.prodName && !(prodName == rhs.prodName))
      return false;
    return true;
  }
  bool operator != (const FlashInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FlashInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(FlashInfo &a, FlashInfo &b);

std::ostream& operator<<(std::ostream& out, const FlashInfo& obj);

typedef struct _DataChunkOptions__isset {
  _DataChunkOptions__isset() : partitionIndex(false), startSector(false), sectorCount(false), imagePath(false) {}
  bool partitionIndex :1;
  bool startSector :1;
  bool sectorCount :1;
  bool imagePath :1;
} _DataChunkOptions__isset;

class DataChunkOptions : public virtual ::apache::thrift::TBase {
 public:

  DataChunkOptions(const DataChunkOptions&);
  DataChunkOptions& operator=(const DataChunkOptions&);
  DataChunkOptions() : partitionIndex(0), startSector(), sectorCount(), imagePath() {
  }

  virtual ~DataChunkOptions() noexcept;
  int32_t partitionIndex;
  std::string startSector;
  std::string sectorCount;
  std::string imagePath;

  _DataChunkOptions__isset __isset;

  void __set_partitionIndex(const int32_t val);

  void __set_startSector(const std::string& val);

  void __set_sectorCount(const std::string& val);

  void __set_imagePath(const std::string& val);

  bool operator == (const DataChunkOptions & rhs) const
  {
    if (!(partitionIndex == rhs.partitionIndex))
      return false;
    if (!(startSector == rhs.startSector))
      return false;
    if (__isset.sectorCount != rhs.__isset.sectorCount)
      return false;
    else if (__isset.sectorCount && !(sectorCount == rhs.sectorCount))
      return false;
    if (__isset.imagePath != rhs.__isset.imagePath)
      return false;
    else if (__isset.imagePath && !(imagePath == rhs.imagePath))
      return false;
    return true;
  }
  bool operator != (const DataChunkOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataChunkOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DataChunkOptions &a, DataChunkOptions &b);

std::ostream& operator<<(std::ostream& out, const DataChunkOptions& obj);

typedef struct _MemoryDumpOptions__isset {
  _MemoryDumpOptions__isset() : pathName(false), sectionNameList(false) {}
  bool pathName :1;
  bool sectionNameList :1;
} _MemoryDumpOptions__isset;

class MemoryDumpOptions : public virtual ::apache::thrift::TBase {
 public:

  MemoryDumpOptions(const MemoryDumpOptions&);
  MemoryDumpOptions& operator=(const MemoryDumpOptions&);
  MemoryDumpOptions() : pathName() {
  }

  virtual ~MemoryDumpOptions() noexcept;
  std::string pathName;
  std::vector<std::string>  sectionNameList;

  _MemoryDumpOptions__isset __isset;

  void __set_pathName(const std::string& val);

  void __set_sectionNameList(const std::vector<std::string> & val);

  bool operator == (const MemoryDumpOptions & rhs) const
  {
    if (!(pathName == rhs.pathName))
      return false;
    if (__isset.sectionNameList != rhs.__isset.sectionNameList)
      return false;
    else if (__isset.sectionNameList && !(sectionNameList == rhs.sectionNameList))
      return false;
    return true;
  }
  bool operator != (const MemoryDumpOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const MemoryDumpOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(MemoryDumpOptions &a, MemoryDumpOptions &b);

std::ostream& operator<<(std::ostream& out, const MemoryDumpOptions& obj);

} // namespace

#endif
