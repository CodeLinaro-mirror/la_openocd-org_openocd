/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef LogSession_TYPES_H
#define LogSession_TYPES_H

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

struct IndexType {
  enum type {
    PROTOCOL_INDEX = 0,
    SESSION_INDEX = 1,
    DATA_VIEW_INDEX = 2
  };
};

extern const std::map<int, const char*> _IndexType_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const IndexType::type& val);

std::string to_string(const IndexType::type& val);

struct DataViewServiceEvent {
  enum type {
    INITIALIZE = 0,
    SAVE_ITEMS_BY_VIEW_INDEX = 1,
    PERCENT_OF_TOTAL_PACKETS_PROCESSED = 2,
    TIMESTAMP_SORTING_PROGRESS = 3
  };
};

extern const std::map<int, const char*> _DataViewServiceEvent_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const DataViewServiceEvent::type& val);

std::string to_string(const DataViewServiceEvent::type& val);

struct ViewConfigurationUpdate {
  enum type {
    ADD_NEW_CONFIG_ITEMS = 0,
    REPLACE_CURRENT_CONFIG_ITEMS = 1,
    REMOVE_SELECTED_CONFIG_ITEMS = 2
  };
};

extern const std::map<int, const char*> _ViewConfigurationUpdate_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ViewConfigurationUpdate::type& val);

std::string to_string(const ViewConfigurationUpdate::type& val);

class PacketRange;

class DataPacketFilter;

class DataPacket;

class PacketReturnConfig;

class ClientSessionInfo;

class DiagLogSessionInformation;

class LogSessionInformation;

class DataViewInfo;

typedef struct _PacketRange__isset {
  _PacketRange__isset() : indexType(false), beginIndex(false), endIndex(false), count(false), dataViewIndexes(false) {}
  bool indexType :1;
  bool beginIndex :1;
  bool endIndex :1;
  bool count :1;
  bool dataViewIndexes :1;
} _PacketRange__isset;

class PacketRange : public virtual ::apache::thrift::TBase {
 public:

  PacketRange(const PacketRange&);
  PacketRange& operator=(const PacketRange&);
  PacketRange() : indexType((IndexType::type)0), beginIndex(0), endIndex(0), count(0) {
  }

  virtual ~PacketRange() noexcept;
  IndexType::type indexType;
  int64_t beginIndex;
  int64_t endIndex;
  int64_t count;
  std::vector<int64_t>  dataViewIndexes;

  _PacketRange__isset __isset;

  void __set_indexType(const IndexType::type val);

  void __set_beginIndex(const int64_t val);

  void __set_endIndex(const int64_t val);

  void __set_count(const int64_t val);

  void __set_dataViewIndexes(const std::vector<int64_t> & val);

  bool operator == (const PacketRange & rhs) const
  {
    if (__isset.indexType != rhs.__isset.indexType)
      return false;
    else if (__isset.indexType && !(indexType == rhs.indexType))
      return false;
    if (__isset.beginIndex != rhs.__isset.beginIndex)
      return false;
    else if (__isset.beginIndex && !(beginIndex == rhs.beginIndex))
      return false;
    if (__isset.endIndex != rhs.__isset.endIndex)
      return false;
    else if (__isset.endIndex && !(endIndex == rhs.endIndex))
      return false;
    if (__isset.count != rhs.__isset.count)
      return false;
    else if (__isset.count && !(count == rhs.count))
      return false;
    if (__isset.dataViewIndexes != rhs.__isset.dataViewIndexes)
      return false;
    else if (__isset.dataViewIndexes && !(dataViewIndexes == rhs.dataViewIndexes))
      return false;
    return true;
  }
  bool operator != (const PacketRange &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PacketRange & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PacketRange &a, PacketRange &b);

std::ostream& operator<<(std::ostream& out, const PacketRange& obj);

typedef struct _DataPacketFilter__isset {
  _DataPacketFilter__isset() : protocolHandleList(false), protocolRange(false), diagFilter(false), qmiFilter(false), adbFilter(false), saharaFilter(false), fastbootFilter(false), nmeaFilter(false), annotationsFilter(false), qdssFilter(false), registerMaskToDevice(false), dunFilter(false), eudFilter(false), protoBufFilter(false), telnetFilter(false) {}
  bool protocolHandleList :1;
  bool protocolRange :1;
  bool diagFilter :1;
  bool qmiFilter :1;
  bool adbFilter :1;
  bool saharaFilter :1;
  bool fastbootFilter :1;
  bool nmeaFilter :1;
  bool annotationsFilter :1;
  bool qdssFilter :1;
  bool registerMaskToDevice :1;
  bool dunFilter :1;
  bool eudFilter :1;
  bool protoBufFilter :1;
  bool telnetFilter :1;
} _DataPacketFilter__isset;

class DataPacketFilter : public virtual ::apache::thrift::TBase {
 public:

  DataPacketFilter(const DataPacketFilter&);
  DataPacketFilter& operator=(const DataPacketFilter&);
  DataPacketFilter() : registerMaskToDevice(0) {
  }

  virtual ~DataPacketFilter() noexcept;
  std::vector<int64_t>  protocolHandleList;
  std::map<int64_t, PacketRange>  protocolRange;
   ::Uts::DiagPacketFilter diagFilter;
   ::Uts::QmiPacketFilter qmiFilter;
   ::Uts::AdbPacketFilter adbFilter;
   ::Uts::SaharaPacketFilter saharaFilter;
   ::Uts::FastbootPacketFilter fastbootFilter;
   ::Uts::NmeaPacketFilter nmeaFilter;
   ::Uts::AnnotationPacketFilter annotationsFilter;
   ::Uts::QdssPacketFilter qdssFilter;
  bool registerMaskToDevice;
   ::Uts::DunPacketFilter dunFilter;
   ::Uts::EudPacketFilter eudFilter;
   ::Uts::ProtoBufPacketFilter protoBufFilter;
   ::Uts::TelnetPacketFilter telnetFilter;

  _DataPacketFilter__isset __isset;

  void __set_protocolHandleList(const std::vector<int64_t> & val);

  void __set_protocolRange(const std::map<int64_t, PacketRange> & val);

  void __set_diagFilter(const  ::Uts::DiagPacketFilter& val);

  void __set_qmiFilter(const  ::Uts::QmiPacketFilter& val);

  void __set_adbFilter(const  ::Uts::AdbPacketFilter& val);

  void __set_saharaFilter(const  ::Uts::SaharaPacketFilter& val);

  void __set_fastbootFilter(const  ::Uts::FastbootPacketFilter& val);

  void __set_nmeaFilter(const  ::Uts::NmeaPacketFilter& val);

  void __set_annotationsFilter(const  ::Uts::AnnotationPacketFilter& val);

  void __set_qdssFilter(const  ::Uts::QdssPacketFilter& val);

  void __set_registerMaskToDevice(const bool val);

  void __set_dunFilter(const  ::Uts::DunPacketFilter& val);

  void __set_eudFilter(const  ::Uts::EudPacketFilter& val);

  void __set_protoBufFilter(const  ::Uts::ProtoBufPacketFilter& val);

  void __set_telnetFilter(const  ::Uts::TelnetPacketFilter& val);

  bool operator == (const DataPacketFilter & rhs) const
  {
    if (!(protocolHandleList == rhs.protocolHandleList))
      return false;
    if (__isset.protocolRange != rhs.__isset.protocolRange)
      return false;
    else if (__isset.protocolRange && !(protocolRange == rhs.protocolRange))
      return false;
    if (__isset.diagFilter != rhs.__isset.diagFilter)
      return false;
    else if (__isset.diagFilter && !(diagFilter == rhs.diagFilter))
      return false;
    if (__isset.qmiFilter != rhs.__isset.qmiFilter)
      return false;
    else if (__isset.qmiFilter && !(qmiFilter == rhs.qmiFilter))
      return false;
    if (__isset.adbFilter != rhs.__isset.adbFilter)
      return false;
    else if (__isset.adbFilter && !(adbFilter == rhs.adbFilter))
      return false;
    if (__isset.saharaFilter != rhs.__isset.saharaFilter)
      return false;
    else if (__isset.saharaFilter && !(saharaFilter == rhs.saharaFilter))
      return false;
    if (__isset.fastbootFilter != rhs.__isset.fastbootFilter)
      return false;
    else if (__isset.fastbootFilter && !(fastbootFilter == rhs.fastbootFilter))
      return false;
    if (__isset.nmeaFilter != rhs.__isset.nmeaFilter)
      return false;
    else if (__isset.nmeaFilter && !(nmeaFilter == rhs.nmeaFilter))
      return false;
    if (__isset.annotationsFilter != rhs.__isset.annotationsFilter)
      return false;
    else if (__isset.annotationsFilter && !(annotationsFilter == rhs.annotationsFilter))
      return false;
    if (__isset.qdssFilter != rhs.__isset.qdssFilter)
      return false;
    else if (__isset.qdssFilter && !(qdssFilter == rhs.qdssFilter))
      return false;
    if (__isset.registerMaskToDevice != rhs.__isset.registerMaskToDevice)
      return false;
    else if (__isset.registerMaskToDevice && !(registerMaskToDevice == rhs.registerMaskToDevice))
      return false;
    if (__isset.dunFilter != rhs.__isset.dunFilter)
      return false;
    else if (__isset.dunFilter && !(dunFilter == rhs.dunFilter))
      return false;
    if (__isset.eudFilter != rhs.__isset.eudFilter)
      return false;
    else if (__isset.eudFilter && !(eudFilter == rhs.eudFilter))
      return false;
    if (__isset.protoBufFilter != rhs.__isset.protoBufFilter)
      return false;
    else if (__isset.protoBufFilter && !(protoBufFilter == rhs.protoBufFilter))
      return false;
    if (__isset.telnetFilter != rhs.__isset.telnetFilter)
      return false;
    else if (__isset.telnetFilter && !(telnetFilter == rhs.telnetFilter))
      return false;
    return true;
  }
  bool operator != (const DataPacketFilter &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataPacketFilter & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DataPacketFilter &a, DataPacketFilter &b);

std::ostream& operator<<(std::ostream& out, const DataPacketFilter& obj);

typedef struct _DataPacket__isset {
  _DataPacket__isset() : protocolHandle(false), diagPacket(false), qmiPacket(false), adbPacket(false), saharaPacket(false), fastbootPacket(false), adplPacket(false), nmeaPacket(false), annotationPacket(false), qdssPacket(false), dunPacket(false), eudPacket(false), protoBufPacket(false), telnetPacket(false) {}
  bool protocolHandle :1;
  bool diagPacket :1;
  bool qmiPacket :1;
  bool adbPacket :1;
  bool saharaPacket :1;
  bool fastbootPacket :1;
  bool adplPacket :1;
  bool nmeaPacket :1;
  bool annotationPacket :1;
  bool qdssPacket :1;
  bool dunPacket :1;
  bool eudPacket :1;
  bool protoBufPacket :1;
  bool telnetPacket :1;
} _DataPacket__isset;

class DataPacket : public virtual ::apache::thrift::TBase {
 public:

  DataPacket(const DataPacket&);
  DataPacket& operator=(const DataPacket&);
  DataPacket() : protocolHandle(0) {
  }

  virtual ~DataPacket() noexcept;
  int64_t protocolHandle;
   ::Uts::DiagPacket diagPacket;
   ::Uts::QmiPacket qmiPacket;
   ::Uts::AdbPacket adbPacket;
   ::Uts::SaharaPacket saharaPacket;
   ::Uts::FastbootPacket fastbootPacket;
   ::Uts::AdplPacket adplPacket;
   ::Uts::NmeaPacket nmeaPacket;
   ::Uts::AnnotationPacket annotationPacket;
   ::Uts::QdssPacket qdssPacket;
   ::Uts::DunPacket dunPacket;
   ::Uts::EudPacket eudPacket;
   ::Uts::ProtoBufPacket protoBufPacket;
   ::Uts::TelnetPacket telnetPacket;

  _DataPacket__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_diagPacket(const  ::Uts::DiagPacket& val);

  void __set_qmiPacket(const  ::Uts::QmiPacket& val);

  void __set_adbPacket(const  ::Uts::AdbPacket& val);

  void __set_saharaPacket(const  ::Uts::SaharaPacket& val);

  void __set_fastbootPacket(const  ::Uts::FastbootPacket& val);

  void __set_adplPacket(const  ::Uts::AdplPacket& val);

  void __set_nmeaPacket(const  ::Uts::NmeaPacket& val);

  void __set_annotationPacket(const  ::Uts::AnnotationPacket& val);

  void __set_qdssPacket(const  ::Uts::QdssPacket& val);

  void __set_dunPacket(const  ::Uts::DunPacket& val);

  void __set_eudPacket(const  ::Uts::EudPacket& val);

  void __set_protoBufPacket(const  ::Uts::ProtoBufPacket& val);

  void __set_telnetPacket(const  ::Uts::TelnetPacket& val);

  bool operator == (const DataPacket & rhs) const
  {
    if (!(protocolHandle == rhs.protocolHandle))
      return false;
    if (__isset.diagPacket != rhs.__isset.diagPacket)
      return false;
    else if (__isset.diagPacket && !(diagPacket == rhs.diagPacket))
      return false;
    if (__isset.qmiPacket != rhs.__isset.qmiPacket)
      return false;
    else if (__isset.qmiPacket && !(qmiPacket == rhs.qmiPacket))
      return false;
    if (__isset.adbPacket != rhs.__isset.adbPacket)
      return false;
    else if (__isset.adbPacket && !(adbPacket == rhs.adbPacket))
      return false;
    if (__isset.saharaPacket != rhs.__isset.saharaPacket)
      return false;
    else if (__isset.saharaPacket && !(saharaPacket == rhs.saharaPacket))
      return false;
    if (__isset.fastbootPacket != rhs.__isset.fastbootPacket)
      return false;
    else if (__isset.fastbootPacket && !(fastbootPacket == rhs.fastbootPacket))
      return false;
    if (__isset.adplPacket != rhs.__isset.adplPacket)
      return false;
    else if (__isset.adplPacket && !(adplPacket == rhs.adplPacket))
      return false;
    if (__isset.nmeaPacket != rhs.__isset.nmeaPacket)
      return false;
    else if (__isset.nmeaPacket && !(nmeaPacket == rhs.nmeaPacket))
      return false;
    if (__isset.annotationPacket != rhs.__isset.annotationPacket)
      return false;
    else if (__isset.annotationPacket && !(annotationPacket == rhs.annotationPacket))
      return false;
    if (__isset.qdssPacket != rhs.__isset.qdssPacket)
      return false;
    else if (__isset.qdssPacket && !(qdssPacket == rhs.qdssPacket))
      return false;
    if (__isset.dunPacket != rhs.__isset.dunPacket)
      return false;
    else if (__isset.dunPacket && !(dunPacket == rhs.dunPacket))
      return false;
    if (__isset.eudPacket != rhs.__isset.eudPacket)
      return false;
    else if (__isset.eudPacket && !(eudPacket == rhs.eudPacket))
      return false;
    if (__isset.protoBufPacket != rhs.__isset.protoBufPacket)
      return false;
    else if (__isset.protoBufPacket && !(protoBufPacket == rhs.protoBufPacket))
      return false;
    if (__isset.telnetPacket != rhs.__isset.telnetPacket)
      return false;
    else if (__isset.telnetPacket && !(telnetPacket == rhs.telnetPacket))
      return false;
    return true;
  }
  bool operator != (const DataPacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataPacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DataPacket &a, DataPacket &b);

std::ostream& operator<<(std::ostream& out, const DataPacket& obj);

typedef struct _PacketReturnConfig__isset {
  _PacketReturnConfig__isset() : diagConfig(false), qmiConfig(false), adbConfig(false), saharaConfig(false), fastbootConfig(false), adplConfig(false), nmeaConfig(false), qdssConfig(false), dunConfig(false), eudConfig(false), protoBufConfig(false), telnetConfig(false) {}
  bool diagConfig :1;
  bool qmiConfig :1;
  bool adbConfig :1;
  bool saharaConfig :1;
  bool fastbootConfig :1;
  bool adplConfig :1;
  bool nmeaConfig :1;
  bool qdssConfig :1;
  bool dunConfig :1;
  bool eudConfig :1;
  bool protoBufConfig :1;
  bool telnetConfig :1;
} _PacketReturnConfig__isset;

class PacketReturnConfig : public virtual ::apache::thrift::TBase {
 public:

  PacketReturnConfig(const PacketReturnConfig&);
  PacketReturnConfig& operator=(const PacketReturnConfig&);
  PacketReturnConfig() {
  }

  virtual ~PacketReturnConfig() noexcept;
   ::Uts::DiagReturnConfig diagConfig;
   ::Uts::QmiReturnConfig qmiConfig;
   ::Uts::AdbReturnConfig adbConfig;
   ::Uts::SaharaReturnConfig saharaConfig;
   ::Uts::FastbootReturnConfig fastbootConfig;
   ::Uts::AdplReturnConfig adplConfig;
   ::Uts::NmeaReturnConfig nmeaConfig;
   ::Uts::QdssReturnConfig qdssConfig;
   ::Uts::DunReturnConfig dunConfig;
   ::Uts::EudReturnConfig eudConfig;
   ::Uts::ProtoBufReturnConfig protoBufConfig;
   ::Uts::TelnetReturnConfig telnetConfig;

  _PacketReturnConfig__isset __isset;

  void __set_diagConfig(const  ::Uts::DiagReturnConfig& val);

  void __set_qmiConfig(const  ::Uts::QmiReturnConfig& val);

  void __set_adbConfig(const  ::Uts::AdbReturnConfig& val);

  void __set_saharaConfig(const  ::Uts::SaharaReturnConfig& val);

  void __set_fastbootConfig(const  ::Uts::FastbootReturnConfig& val);

  void __set_adplConfig(const  ::Uts::AdplReturnConfig& val);

  void __set_nmeaConfig(const  ::Uts::NmeaReturnConfig& val);

  void __set_qdssConfig(const  ::Uts::QdssReturnConfig& val);

  void __set_dunConfig(const  ::Uts::DunReturnConfig& val);

  void __set_eudConfig(const  ::Uts::EudReturnConfig& val);

  void __set_protoBufConfig(const  ::Uts::ProtoBufReturnConfig& val);

  void __set_telnetConfig(const  ::Uts::TelnetReturnConfig& val);

  bool operator == (const PacketReturnConfig & rhs) const
  {
    if (__isset.diagConfig != rhs.__isset.diagConfig)
      return false;
    else if (__isset.diagConfig && !(diagConfig == rhs.diagConfig))
      return false;
    if (__isset.qmiConfig != rhs.__isset.qmiConfig)
      return false;
    else if (__isset.qmiConfig && !(qmiConfig == rhs.qmiConfig))
      return false;
    if (__isset.adbConfig != rhs.__isset.adbConfig)
      return false;
    else if (__isset.adbConfig && !(adbConfig == rhs.adbConfig))
      return false;
    if (__isset.saharaConfig != rhs.__isset.saharaConfig)
      return false;
    else if (__isset.saharaConfig && !(saharaConfig == rhs.saharaConfig))
      return false;
    if (__isset.fastbootConfig != rhs.__isset.fastbootConfig)
      return false;
    else if (__isset.fastbootConfig && !(fastbootConfig == rhs.fastbootConfig))
      return false;
    if (__isset.adplConfig != rhs.__isset.adplConfig)
      return false;
    else if (__isset.adplConfig && !(adplConfig == rhs.adplConfig))
      return false;
    if (__isset.nmeaConfig != rhs.__isset.nmeaConfig)
      return false;
    else if (__isset.nmeaConfig && !(nmeaConfig == rhs.nmeaConfig))
      return false;
    if (__isset.qdssConfig != rhs.__isset.qdssConfig)
      return false;
    else if (__isset.qdssConfig && !(qdssConfig == rhs.qdssConfig))
      return false;
    if (__isset.dunConfig != rhs.__isset.dunConfig)
      return false;
    else if (__isset.dunConfig && !(dunConfig == rhs.dunConfig))
      return false;
    if (__isset.eudConfig != rhs.__isset.eudConfig)
      return false;
    else if (__isset.eudConfig && !(eudConfig == rhs.eudConfig))
      return false;
    if (__isset.protoBufConfig != rhs.__isset.protoBufConfig)
      return false;
    else if (__isset.protoBufConfig && !(protoBufConfig == rhs.protoBufConfig))
      return false;
    if (__isset.telnetConfig != rhs.__isset.telnetConfig)
      return false;
    else if (__isset.telnetConfig && !(telnetConfig == rhs.telnetConfig))
      return false;
    return true;
  }
  bool operator != (const PacketReturnConfig &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const PacketReturnConfig & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(PacketReturnConfig &a, PacketReturnConfig &b);

std::ostream& operator<<(std::ostream& out, const PacketReturnConfig& obj);

typedef struct _ClientSessionInfo__isset {
  _ClientSessionInfo__isset() : clientId(false), sessionName(false) {}
  bool clientId :1;
  bool sessionName :1;
} _ClientSessionInfo__isset;

class ClientSessionInfo : public virtual ::apache::thrift::TBase {
 public:

  ClientSessionInfo(const ClientSessionInfo&);
  ClientSessionInfo& operator=(const ClientSessionInfo&);
  ClientSessionInfo() : clientId(0), sessionName() {
  }

  virtual ~ClientSessionInfo() noexcept;
  int32_t clientId;
  std::string sessionName;

  _ClientSessionInfo__isset __isset;

  void __set_clientId(const int32_t val);

  void __set_sessionName(const std::string& val);

  bool operator == (const ClientSessionInfo & rhs) const
  {
    if (!(clientId == rhs.clientId))
      return false;
    if (!(sessionName == rhs.sessionName))
      return false;
    return true;
  }
  bool operator != (const ClientSessionInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const ClientSessionInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(ClientSessionInfo &a, ClientSessionInfo &b);

std::ostream& operator<<(std::ostream& out, const ClientSessionInfo& obj);

typedef struct _DiagLogSessionInformation__isset {
  _DiagLogSessionInformation__isset() : packetId(false), subscriptionId(false), miscellaneousId(false), variantIdPacketIdMap(false), bIncludeAnnotation(false) {}
  bool packetId :1;
  bool subscriptionId :1;
  bool miscellaneousId :1;
  bool variantIdPacketIdMap :1;
  bool bIncludeAnnotation :1;
} _DiagLogSessionInformation__isset;

class DiagLogSessionInformation : public virtual ::apache::thrift::TBase {
 public:

  DiagLogSessionInformation(const DiagLogSessionInformation&);
  DiagLogSessionInformation& operator=(const DiagLogSessionInformation&);
  DiagLogSessionInformation() : bIncludeAnnotation(0) {
  }

  virtual ~DiagLogSessionInformation() noexcept;
  std::map< ::Uts::DiagPacketType::type, std::vector< ::Uts::DiagIdFilterItem> >  packetId;
  std::vector<int32_t>  subscriptionId;
  std::vector<int32_t>  miscellaneousId;
  std::map<int32_t, std::set<int64_t> >  variantIdPacketIdMap;
  bool bIncludeAnnotation;

  _DiagLogSessionInformation__isset __isset;

  void __set_packetId(const std::map< ::Uts::DiagPacketType::type, std::vector< ::Uts::DiagIdFilterItem> > & val);

  void __set_subscriptionId(const std::vector<int32_t> & val);

  void __set_miscellaneousId(const std::vector<int32_t> & val);

  void __set_variantIdPacketIdMap(const std::map<int32_t, std::set<int64_t> > & val);

  void __set_bIncludeAnnotation(const bool val);

  bool operator == (const DiagLogSessionInformation & rhs) const
  {
    if (__isset.packetId != rhs.__isset.packetId)
      return false;
    else if (__isset.packetId && !(packetId == rhs.packetId))
      return false;
    if (__isset.subscriptionId != rhs.__isset.subscriptionId)
      return false;
    else if (__isset.subscriptionId && !(subscriptionId == rhs.subscriptionId))
      return false;
    if (__isset.miscellaneousId != rhs.__isset.miscellaneousId)
      return false;
    else if (__isset.miscellaneousId && !(miscellaneousId == rhs.miscellaneousId))
      return false;
    if (__isset.variantIdPacketIdMap != rhs.__isset.variantIdPacketIdMap)
      return false;
    else if (__isset.variantIdPacketIdMap && !(variantIdPacketIdMap == rhs.variantIdPacketIdMap))
      return false;
    if (__isset.bIncludeAnnotation != rhs.__isset.bIncludeAnnotation)
      return false;
    else if (__isset.bIncludeAnnotation && !(bIncludeAnnotation == rhs.bIncludeAnnotation))
      return false;
    return true;
  }
  bool operator != (const DiagLogSessionInformation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagLogSessionInformation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagLogSessionInformation &a, DiagLogSessionInformation &b);

std::ostream& operator<<(std::ostream& out, const DiagLogSessionInformation& obj);

typedef struct _LogSessionInformation__isset {
  _LogSessionInformation__isset() : diagLogSessionInformation(false) {}
  bool diagLogSessionInformation :1;
} _LogSessionInformation__isset;

class LogSessionInformation : public virtual ::apache::thrift::TBase {
 public:

  LogSessionInformation(const LogSessionInformation&);
  LogSessionInformation& operator=(const LogSessionInformation&);
  LogSessionInformation() {
  }

  virtual ~LogSessionInformation() noexcept;
  DiagLogSessionInformation diagLogSessionInformation;

  _LogSessionInformation__isset __isset;

  void __set_diagLogSessionInformation(const DiagLogSessionInformation& val);

  bool operator == (const LogSessionInformation & rhs) const
  {
    if (__isset.diagLogSessionInformation != rhs.__isset.diagLogSessionInformation)
      return false;
    else if (__isset.diagLogSessionInformation && !(diagLogSessionInformation == rhs.diagLogSessionInformation))
      return false;
    return true;
  }
  bool operator != (const LogSessionInformation &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const LogSessionInformation & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(LogSessionInformation &a, LogSessionInformation &b);

std::ostream& operator<<(std::ostream& out, const LogSessionInformation& obj);

typedef struct _DataViewInfo__isset {
  _DataViewInfo__isset() : viewName(false), filter(false), returnConfig(false) {}
  bool viewName :1;
  bool filter :1;
  bool returnConfig :1;
} _DataViewInfo__isset;

class DataViewInfo : public virtual ::apache::thrift::TBase {
 public:

  DataViewInfo(const DataViewInfo&);
  DataViewInfo& operator=(const DataViewInfo&);
  DataViewInfo() : viewName() {
  }

  virtual ~DataViewInfo() noexcept;
  std::string viewName;
  DataPacketFilter filter;
  PacketReturnConfig returnConfig;

  _DataViewInfo__isset __isset;

  void __set_viewName(const std::string& val);

  void __set_filter(const DataPacketFilter& val);

  void __set_returnConfig(const PacketReturnConfig& val);

  bool operator == (const DataViewInfo & rhs) const
  {
    if (!(viewName == rhs.viewName))
      return false;
    if (!(filter == rhs.filter))
      return false;
    if (!(returnConfig == rhs.returnConfig))
      return false;
    return true;
  }
  bool operator != (const DataViewInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataViewInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DataViewInfo &a, DataViewInfo &b);

std::ostream& operator<<(std::ostream& out, const DataViewInfo& obj);

} // namespace

#endif
