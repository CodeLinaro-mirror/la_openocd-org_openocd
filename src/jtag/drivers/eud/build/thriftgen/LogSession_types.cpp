/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "LogSession_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {

int _kIndexTypeValues[] = {
  IndexType::PROTOCOL_INDEX,
  IndexType::SESSION_INDEX,
  IndexType::DATA_VIEW_INDEX
};
const char* _kIndexTypeNames[] = {
  "PROTOCOL_INDEX",
  "SESSION_INDEX",
  "DATA_VIEW_INDEX"
};
const std::map<int, const char*> _IndexType_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kIndexTypeValues, _kIndexTypeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const IndexType::type& val) {
  std::map<int, const char*>::const_iterator it = _IndexType_VALUES_TO_NAMES.find(val);
  if (it != _IndexType_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const IndexType::type& val) {
  std::map<int, const char*>::const_iterator it = _IndexType_VALUES_TO_NAMES.find(val);
  if (it != _IndexType_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kDataViewServiceEventValues[] = {
  DataViewServiceEvent::INITIALIZE,
  DataViewServiceEvent::SAVE_ITEMS_BY_VIEW_INDEX,
  DataViewServiceEvent::PERCENT_OF_TOTAL_PACKETS_PROCESSED,
  DataViewServiceEvent::TIMESTAMP_SORTING_PROGRESS
};
const char* _kDataViewServiceEventNames[] = {
  "INITIALIZE",
  "SAVE_ITEMS_BY_VIEW_INDEX",
  "PERCENT_OF_TOTAL_PACKETS_PROCESSED",
  "TIMESTAMP_SORTING_PROGRESS"
};
const std::map<int, const char*> _DataViewServiceEvent_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(4, _kDataViewServiceEventValues, _kDataViewServiceEventNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const DataViewServiceEvent::type& val) {
  std::map<int, const char*>::const_iterator it = _DataViewServiceEvent_VALUES_TO_NAMES.find(val);
  if (it != _DataViewServiceEvent_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const DataViewServiceEvent::type& val) {
  std::map<int, const char*>::const_iterator it = _DataViewServiceEvent_VALUES_TO_NAMES.find(val);
  if (it != _DataViewServiceEvent_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kViewConfigurationUpdateValues[] = {
  ViewConfigurationUpdate::ADD_NEW_CONFIG_ITEMS,
  ViewConfigurationUpdate::REPLACE_CURRENT_CONFIG_ITEMS,
  ViewConfigurationUpdate::REMOVE_SELECTED_CONFIG_ITEMS
};
const char* _kViewConfigurationUpdateNames[] = {
  "ADD_NEW_CONFIG_ITEMS",
  "REPLACE_CURRENT_CONFIG_ITEMS",
  "REMOVE_SELECTED_CONFIG_ITEMS"
};
const std::map<int, const char*> _ViewConfigurationUpdate_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kViewConfigurationUpdateValues, _kViewConfigurationUpdateNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ViewConfigurationUpdate::type& val) {
  std::map<int, const char*>::const_iterator it = _ViewConfigurationUpdate_VALUES_TO_NAMES.find(val);
  if (it != _ViewConfigurationUpdate_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ViewConfigurationUpdate::type& val) {
  std::map<int, const char*>::const_iterator it = _ViewConfigurationUpdate_VALUES_TO_NAMES.find(val);
  if (it != _ViewConfigurationUpdate_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


PacketRange::~PacketRange() noexcept {
}


void PacketRange::__set_indexType(const IndexType::type val) {
  this->indexType = val;
__isset.indexType = true;
}

void PacketRange::__set_beginIndex(const int64_t val) {
  this->beginIndex = val;
__isset.beginIndex = true;
}

void PacketRange::__set_endIndex(const int64_t val) {
  this->endIndex = val;
__isset.endIndex = true;
}

void PacketRange::__set_count(const int64_t val) {
  this->count = val;
__isset.count = true;
}

void PacketRange::__set_dataViewIndexes(const std::vector<int64_t> & val) {
  this->dataViewIndexes = val;
__isset.dataViewIndexes = true;
}
std::ostream& operator<<(std::ostream& out, const PacketRange& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t PacketRange::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          this->indexType = (IndexType::type)ecast0;
          this->__isset.indexType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->beginIndex);
          this->__isset.beginIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->endIndex);
          this->__isset.endIndex = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->count);
          this->__isset.count = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->dataViewIndexes.clear();
            uint32_t _size1;
            ::apache::thrift::protocol::TType _etype4;
            xfer += iprot->readListBegin(_etype4, _size1);
            this->dataViewIndexes.resize(_size1);
            uint32_t _i5;
            for (_i5 = 0; _i5 < _size1; ++_i5)
            {
              xfer += iprot->readI64(this->dataViewIndexes[_i5]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.dataViewIndexes = true;
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

uint32_t PacketRange::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PacketRange");

  if (this->__isset.indexType) {
    xfer += oprot->writeFieldBegin("indexType", ::apache::thrift::protocol::T_I32, 1);
    xfer += oprot->writeI32((int32_t)this->indexType);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.beginIndex) {
    xfer += oprot->writeFieldBegin("beginIndex", ::apache::thrift::protocol::T_I64, 2);
    xfer += oprot->writeI64(this->beginIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.endIndex) {
    xfer += oprot->writeFieldBegin("endIndex", ::apache::thrift::protocol::T_I64, 3);
    xfer += oprot->writeI64(this->endIndex);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.count) {
    xfer += oprot->writeFieldBegin("count", ::apache::thrift::protocol::T_I64, 4);
    xfer += oprot->writeI64(this->count);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.dataViewIndexes) {
    xfer += oprot->writeFieldBegin("dataViewIndexes", ::apache::thrift::protocol::T_LIST, 5);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->dataViewIndexes.size()));
      std::vector<int64_t> ::const_iterator _iter6;
      for (_iter6 = this->dataViewIndexes.begin(); _iter6 != this->dataViewIndexes.end(); ++_iter6)
      {
        xfer += oprot->writeI64((*_iter6));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PacketRange &a, PacketRange &b) {
  using ::std::swap;
  swap(a.indexType, b.indexType);
  swap(a.beginIndex, b.beginIndex);
  swap(a.endIndex, b.endIndex);
  swap(a.count, b.count);
  swap(a.dataViewIndexes, b.dataViewIndexes);
  swap(a.__isset, b.__isset);
}

PacketRange::PacketRange(const PacketRange& other7) {
  indexType = other7.indexType;
  beginIndex = other7.beginIndex;
  endIndex = other7.endIndex;
  count = other7.count;
  dataViewIndexes = other7.dataViewIndexes;
  __isset = other7.__isset;
}
PacketRange& PacketRange::operator=(const PacketRange& other8) {
  indexType = other8.indexType;
  beginIndex = other8.beginIndex;
  endIndex = other8.endIndex;
  count = other8.count;
  dataViewIndexes = other8.dataViewIndexes;
  __isset = other8.__isset;
  return *this;
}
void PacketRange::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PacketRange(";
  out << "indexType="; (__isset.indexType ? (out << to_string(indexType)) : (out << "<null>"));
  out << ", " << "beginIndex="; (__isset.beginIndex ? (out << to_string(beginIndex)) : (out << "<null>"));
  out << ", " << "endIndex="; (__isset.endIndex ? (out << to_string(endIndex)) : (out << "<null>"));
  out << ", " << "count="; (__isset.count ? (out << to_string(count)) : (out << "<null>"));
  out << ", " << "dataViewIndexes="; (__isset.dataViewIndexes ? (out << to_string(dataViewIndexes)) : (out << "<null>"));
  out << ")";
}


DataPacketFilter::~DataPacketFilter() noexcept {
}


void DataPacketFilter::__set_protocolHandleList(const std::vector<int64_t> & val) {
  this->protocolHandleList = val;
}

void DataPacketFilter::__set_protocolRange(const std::map<int64_t, PacketRange> & val) {
  this->protocolRange = val;
__isset.protocolRange = true;
}

void DataPacketFilter::__set_diagFilter(const  ::Uts::DiagPacketFilter& val) {
  this->diagFilter = val;
__isset.diagFilter = true;
}

void DataPacketFilter::__set_qmiFilter(const  ::Uts::QmiPacketFilter& val) {
  this->qmiFilter = val;
__isset.qmiFilter = true;
}

void DataPacketFilter::__set_adbFilter(const  ::Uts::AdbPacketFilter& val) {
  this->adbFilter = val;
__isset.adbFilter = true;
}

void DataPacketFilter::__set_saharaFilter(const  ::Uts::SaharaPacketFilter& val) {
  this->saharaFilter = val;
__isset.saharaFilter = true;
}

void DataPacketFilter::__set_fastbootFilter(const  ::Uts::FastbootPacketFilter& val) {
  this->fastbootFilter = val;
__isset.fastbootFilter = true;
}

void DataPacketFilter::__set_nmeaFilter(const  ::Uts::NmeaPacketFilter& val) {
  this->nmeaFilter = val;
__isset.nmeaFilter = true;
}

void DataPacketFilter::__set_annotationsFilter(const  ::Uts::AnnotationPacketFilter& val) {
  this->annotationsFilter = val;
__isset.annotationsFilter = true;
}

void DataPacketFilter::__set_qdssFilter(const  ::Uts::QdssPacketFilter& val) {
  this->qdssFilter = val;
__isset.qdssFilter = true;
}

void DataPacketFilter::__set_registerMaskToDevice(const bool val) {
  this->registerMaskToDevice = val;
__isset.registerMaskToDevice = true;
}

void DataPacketFilter::__set_dunFilter(const  ::Uts::DunPacketFilter& val) {
  this->dunFilter = val;
__isset.dunFilter = true;
}

void DataPacketFilter::__set_eudFilter(const  ::Uts::EudPacketFilter& val) {
  this->eudFilter = val;
__isset.eudFilter = true;
}

void DataPacketFilter::__set_protoBufFilter(const  ::Uts::ProtoBufPacketFilter& val) {
  this->protoBufFilter = val;
__isset.protoBufFilter = true;
}

void DataPacketFilter::__set_telnetFilter(const  ::Uts::TelnetPacketFilter& val) {
  this->telnetFilter = val;
__isset.telnetFilter = true;
}
std::ostream& operator<<(std::ostream& out, const DataPacketFilter& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DataPacketFilter::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->protocolHandleList.clear();
            uint32_t _size9;
            ::apache::thrift::protocol::TType _etype12;
            xfer += iprot->readListBegin(_etype12, _size9);
            this->protocolHandleList.resize(_size9);
            uint32_t _i13;
            for (_i13 = 0; _i13 < _size9; ++_i13)
            {
              xfer += iprot->readI64(this->protocolHandleList[_i13]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.protocolHandleList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->protocolRange.clear();
            uint32_t _size14;
            ::apache::thrift::protocol::TType _ktype15;
            ::apache::thrift::protocol::TType _vtype16;
            xfer += iprot->readMapBegin(_ktype15, _vtype16, _size14);
            uint32_t _i18;
            for (_i18 = 0; _i18 < _size14; ++_i18)
            {
              int64_t _key19;
              xfer += iprot->readI64(_key19);
              PacketRange& _val20 = this->protocolRange[_key19];
              xfer += _val20.read(iprot);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.protocolRange = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->diagFilter.read(iprot);
          this->__isset.diagFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->qmiFilter.read(iprot);
          this->__isset.qmiFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->adbFilter.read(iprot);
          this->__isset.adbFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->saharaFilter.read(iprot);
          this->__isset.saharaFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->fastbootFilter.read(iprot);
          this->__isset.fastbootFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->nmeaFilter.read(iprot);
          this->__isset.nmeaFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->annotationsFilter.read(iprot);
          this->__isset.annotationsFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->qdssFilter.read(iprot);
          this->__isset.qdssFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->registerMaskToDevice);
          this->__isset.registerMaskToDevice = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->dunFilter.read(iprot);
          this->__isset.dunFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->eudFilter.read(iprot);
          this->__isset.eudFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->protoBufFilter.read(iprot);
          this->__isset.protoBufFilter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 15:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->telnetFilter.read(iprot);
          this->__isset.telnetFilter = true;
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

uint32_t DataPacketFilter::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DataPacketFilter");

  xfer += oprot->writeFieldBegin("protocolHandleList", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->protocolHandleList.size()));
    std::vector<int64_t> ::const_iterator _iter21;
    for (_iter21 = this->protocolHandleList.begin(); _iter21 != this->protocolHandleList.end(); ++_iter21)
    {
      xfer += oprot->writeI64((*_iter21));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  if (this->__isset.protocolRange) {
    xfer += oprot->writeFieldBegin("protocolRange", ::apache::thrift::protocol::T_MAP, 2);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I64, ::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->protocolRange.size()));
      std::map<int64_t, PacketRange> ::const_iterator _iter22;
      for (_iter22 = this->protocolRange.begin(); _iter22 != this->protocolRange.end(); ++_iter22)
      {
        xfer += oprot->writeI64(_iter22->first);
        xfer += _iter22->second.write(oprot);
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.diagFilter) {
    xfer += oprot->writeFieldBegin("diagFilter", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->diagFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qmiFilter) {
    xfer += oprot->writeFieldBegin("qmiFilter", ::apache::thrift::protocol::T_STRUCT, 4);
    xfer += this->qmiFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.adbFilter) {
    xfer += oprot->writeFieldBegin("adbFilter", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->adbFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.saharaFilter) {
    xfer += oprot->writeFieldBegin("saharaFilter", ::apache::thrift::protocol::T_STRUCT, 6);
    xfer += this->saharaFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.fastbootFilter) {
    xfer += oprot->writeFieldBegin("fastbootFilter", ::apache::thrift::protocol::T_STRUCT, 7);
    xfer += this->fastbootFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.nmeaFilter) {
    xfer += oprot->writeFieldBegin("nmeaFilter", ::apache::thrift::protocol::T_STRUCT, 8);
    xfer += this->nmeaFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.annotationsFilter) {
    xfer += oprot->writeFieldBegin("annotationsFilter", ::apache::thrift::protocol::T_STRUCT, 9);
    xfer += this->annotationsFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qdssFilter) {
    xfer += oprot->writeFieldBegin("qdssFilter", ::apache::thrift::protocol::T_STRUCT, 10);
    xfer += this->qdssFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.registerMaskToDevice) {
    xfer += oprot->writeFieldBegin("registerMaskToDevice", ::apache::thrift::protocol::T_BOOL, 11);
    xfer += oprot->writeBool(this->registerMaskToDevice);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.dunFilter) {
    xfer += oprot->writeFieldBegin("dunFilter", ::apache::thrift::protocol::T_STRUCT, 12);
    xfer += this->dunFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.eudFilter) {
    xfer += oprot->writeFieldBegin("eudFilter", ::apache::thrift::protocol::T_STRUCT, 13);
    xfer += this->eudFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protoBufFilter) {
    xfer += oprot->writeFieldBegin("protoBufFilter", ::apache::thrift::protocol::T_STRUCT, 14);
    xfer += this->protoBufFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.telnetFilter) {
    xfer += oprot->writeFieldBegin("telnetFilter", ::apache::thrift::protocol::T_STRUCT, 15);
    xfer += this->telnetFilter.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DataPacketFilter &a, DataPacketFilter &b) {
  using ::std::swap;
  swap(a.protocolHandleList, b.protocolHandleList);
  swap(a.protocolRange, b.protocolRange);
  swap(a.diagFilter, b.diagFilter);
  swap(a.qmiFilter, b.qmiFilter);
  swap(a.adbFilter, b.adbFilter);
  swap(a.saharaFilter, b.saharaFilter);
  swap(a.fastbootFilter, b.fastbootFilter);
  swap(a.nmeaFilter, b.nmeaFilter);
  swap(a.annotationsFilter, b.annotationsFilter);
  swap(a.qdssFilter, b.qdssFilter);
  swap(a.registerMaskToDevice, b.registerMaskToDevice);
  swap(a.dunFilter, b.dunFilter);
  swap(a.eudFilter, b.eudFilter);
  swap(a.protoBufFilter, b.protoBufFilter);
  swap(a.telnetFilter, b.telnetFilter);
  swap(a.__isset, b.__isset);
}

DataPacketFilter::DataPacketFilter(const DataPacketFilter& other23) {
  protocolHandleList = other23.protocolHandleList;
  protocolRange = other23.protocolRange;
  diagFilter = other23.diagFilter;
  qmiFilter = other23.qmiFilter;
  adbFilter = other23.adbFilter;
  saharaFilter = other23.saharaFilter;
  fastbootFilter = other23.fastbootFilter;
  nmeaFilter = other23.nmeaFilter;
  annotationsFilter = other23.annotationsFilter;
  qdssFilter = other23.qdssFilter;
  registerMaskToDevice = other23.registerMaskToDevice;
  dunFilter = other23.dunFilter;
  eudFilter = other23.eudFilter;
  protoBufFilter = other23.protoBufFilter;
  telnetFilter = other23.telnetFilter;
  __isset = other23.__isset;
}
DataPacketFilter& DataPacketFilter::operator=(const DataPacketFilter& other24) {
  protocolHandleList = other24.protocolHandleList;
  protocolRange = other24.protocolRange;
  diagFilter = other24.diagFilter;
  qmiFilter = other24.qmiFilter;
  adbFilter = other24.adbFilter;
  saharaFilter = other24.saharaFilter;
  fastbootFilter = other24.fastbootFilter;
  nmeaFilter = other24.nmeaFilter;
  annotationsFilter = other24.annotationsFilter;
  qdssFilter = other24.qdssFilter;
  registerMaskToDevice = other24.registerMaskToDevice;
  dunFilter = other24.dunFilter;
  eudFilter = other24.eudFilter;
  protoBufFilter = other24.protoBufFilter;
  telnetFilter = other24.telnetFilter;
  __isset = other24.__isset;
  return *this;
}
void DataPacketFilter::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DataPacketFilter(";
  out << "protocolHandleList=" << to_string(protocolHandleList);
  out << ", " << "protocolRange="; (__isset.protocolRange ? (out << to_string(protocolRange)) : (out << "<null>"));
  out << ", " << "diagFilter="; (__isset.diagFilter ? (out << to_string(diagFilter)) : (out << "<null>"));
  out << ", " << "qmiFilter="; (__isset.qmiFilter ? (out << to_string(qmiFilter)) : (out << "<null>"));
  out << ", " << "adbFilter="; (__isset.adbFilter ? (out << to_string(adbFilter)) : (out << "<null>"));
  out << ", " << "saharaFilter="; (__isset.saharaFilter ? (out << to_string(saharaFilter)) : (out << "<null>"));
  out << ", " << "fastbootFilter="; (__isset.fastbootFilter ? (out << to_string(fastbootFilter)) : (out << "<null>"));
  out << ", " << "nmeaFilter="; (__isset.nmeaFilter ? (out << to_string(nmeaFilter)) : (out << "<null>"));
  out << ", " << "annotationsFilter="; (__isset.annotationsFilter ? (out << to_string(annotationsFilter)) : (out << "<null>"));
  out << ", " << "qdssFilter="; (__isset.qdssFilter ? (out << to_string(qdssFilter)) : (out << "<null>"));
  out << ", " << "registerMaskToDevice="; (__isset.registerMaskToDevice ? (out << to_string(registerMaskToDevice)) : (out << "<null>"));
  out << ", " << "dunFilter="; (__isset.dunFilter ? (out << to_string(dunFilter)) : (out << "<null>"));
  out << ", " << "eudFilter="; (__isset.eudFilter ? (out << to_string(eudFilter)) : (out << "<null>"));
  out << ", " << "protoBufFilter="; (__isset.protoBufFilter ? (out << to_string(protoBufFilter)) : (out << "<null>"));
  out << ", " << "telnetFilter="; (__isset.telnetFilter ? (out << to_string(telnetFilter)) : (out << "<null>"));
  out << ")";
}


DataPacket::~DataPacket() noexcept {
}


void DataPacket::__set_protocolHandle(const int64_t val) {
  this->protocolHandle = val;
}

void DataPacket::__set_diagPacket(const  ::Uts::DiagPacket& val) {
  this->diagPacket = val;
__isset.diagPacket = true;
}

void DataPacket::__set_qmiPacket(const  ::Uts::QmiPacket& val) {
  this->qmiPacket = val;
__isset.qmiPacket = true;
}

void DataPacket::__set_adbPacket(const  ::Uts::AdbPacket& val) {
  this->adbPacket = val;
__isset.adbPacket = true;
}

void DataPacket::__set_saharaPacket(const  ::Uts::SaharaPacket& val) {
  this->saharaPacket = val;
__isset.saharaPacket = true;
}

void DataPacket::__set_fastbootPacket(const  ::Uts::FastbootPacket& val) {
  this->fastbootPacket = val;
__isset.fastbootPacket = true;
}

void DataPacket::__set_adplPacket(const  ::Uts::AdplPacket& val) {
  this->adplPacket = val;
__isset.adplPacket = true;
}

void DataPacket::__set_nmeaPacket(const  ::Uts::NmeaPacket& val) {
  this->nmeaPacket = val;
__isset.nmeaPacket = true;
}

void DataPacket::__set_annotationPacket(const  ::Uts::AnnotationPacket& val) {
  this->annotationPacket = val;
__isset.annotationPacket = true;
}

void DataPacket::__set_qdssPacket(const  ::Uts::QdssPacket& val) {
  this->qdssPacket = val;
__isset.qdssPacket = true;
}

void DataPacket::__set_dunPacket(const  ::Uts::DunPacket& val) {
  this->dunPacket = val;
__isset.dunPacket = true;
}

void DataPacket::__set_eudPacket(const  ::Uts::EudPacket& val) {
  this->eudPacket = val;
__isset.eudPacket = true;
}

void DataPacket::__set_protoBufPacket(const  ::Uts::ProtoBufPacket& val) {
  this->protoBufPacket = val;
__isset.protoBufPacket = true;
}

void DataPacket::__set_telnetPacket(const  ::Uts::TelnetPacket& val) {
  this->telnetPacket = val;
__isset.telnetPacket = true;
}
std::ostream& operator<<(std::ostream& out, const DataPacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DataPacket::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->diagPacket.read(iprot);
          this->__isset.diagPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->qmiPacket.read(iprot);
          this->__isset.qmiPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->adbPacket.read(iprot);
          this->__isset.adbPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->saharaPacket.read(iprot);
          this->__isset.saharaPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->fastbootPacket.read(iprot);
          this->__isset.fastbootPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->adplPacket.read(iprot);
          this->__isset.adplPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->nmeaPacket.read(iprot);
          this->__isset.nmeaPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->annotationPacket.read(iprot);
          this->__isset.annotationPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->qdssPacket.read(iprot);
          this->__isset.qdssPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->dunPacket.read(iprot);
          this->__isset.dunPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->eudPacket.read(iprot);
          this->__isset.eudPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 13:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->protoBufPacket.read(iprot);
          this->__isset.protoBufPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 14:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->telnetPacket.read(iprot);
          this->__isset.telnetPacket = true;
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

uint32_t DataPacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DataPacket");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.diagPacket) {
    xfer += oprot->writeFieldBegin("diagPacket", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->diagPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qmiPacket) {
    xfer += oprot->writeFieldBegin("qmiPacket", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->qmiPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.adbPacket) {
    xfer += oprot->writeFieldBegin("adbPacket", ::apache::thrift::protocol::T_STRUCT, 4);
    xfer += this->adbPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.saharaPacket) {
    xfer += oprot->writeFieldBegin("saharaPacket", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->saharaPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.fastbootPacket) {
    xfer += oprot->writeFieldBegin("fastbootPacket", ::apache::thrift::protocol::T_STRUCT, 6);
    xfer += this->fastbootPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.adplPacket) {
    xfer += oprot->writeFieldBegin("adplPacket", ::apache::thrift::protocol::T_STRUCT, 7);
    xfer += this->adplPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.nmeaPacket) {
    xfer += oprot->writeFieldBegin("nmeaPacket", ::apache::thrift::protocol::T_STRUCT, 8);
    xfer += this->nmeaPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.annotationPacket) {
    xfer += oprot->writeFieldBegin("annotationPacket", ::apache::thrift::protocol::T_STRUCT, 9);
    xfer += this->annotationPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qdssPacket) {
    xfer += oprot->writeFieldBegin("qdssPacket", ::apache::thrift::protocol::T_STRUCT, 10);
    xfer += this->qdssPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.dunPacket) {
    xfer += oprot->writeFieldBegin("dunPacket", ::apache::thrift::protocol::T_STRUCT, 11);
    xfer += this->dunPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.eudPacket) {
    xfer += oprot->writeFieldBegin("eudPacket", ::apache::thrift::protocol::T_STRUCT, 12);
    xfer += this->eudPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protoBufPacket) {
    xfer += oprot->writeFieldBegin("protoBufPacket", ::apache::thrift::protocol::T_STRUCT, 13);
    xfer += this->protoBufPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.telnetPacket) {
    xfer += oprot->writeFieldBegin("telnetPacket", ::apache::thrift::protocol::T_STRUCT, 14);
    xfer += this->telnetPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DataPacket &a, DataPacket &b) {
  using ::std::swap;
  swap(a.protocolHandle, b.protocolHandle);
  swap(a.diagPacket, b.diagPacket);
  swap(a.qmiPacket, b.qmiPacket);
  swap(a.adbPacket, b.adbPacket);
  swap(a.saharaPacket, b.saharaPacket);
  swap(a.fastbootPacket, b.fastbootPacket);
  swap(a.adplPacket, b.adplPacket);
  swap(a.nmeaPacket, b.nmeaPacket);
  swap(a.annotationPacket, b.annotationPacket);
  swap(a.qdssPacket, b.qdssPacket);
  swap(a.dunPacket, b.dunPacket);
  swap(a.eudPacket, b.eudPacket);
  swap(a.protoBufPacket, b.protoBufPacket);
  swap(a.telnetPacket, b.telnetPacket);
  swap(a.__isset, b.__isset);
}

DataPacket::DataPacket(const DataPacket& other25) {
  protocolHandle = other25.protocolHandle;
  diagPacket = other25.diagPacket;
  qmiPacket = other25.qmiPacket;
  adbPacket = other25.adbPacket;
  saharaPacket = other25.saharaPacket;
  fastbootPacket = other25.fastbootPacket;
  adplPacket = other25.adplPacket;
  nmeaPacket = other25.nmeaPacket;
  annotationPacket = other25.annotationPacket;
  qdssPacket = other25.qdssPacket;
  dunPacket = other25.dunPacket;
  eudPacket = other25.eudPacket;
  protoBufPacket = other25.protoBufPacket;
  telnetPacket = other25.telnetPacket;
  __isset = other25.__isset;
}
DataPacket& DataPacket::operator=(const DataPacket& other26) {
  protocolHandle = other26.protocolHandle;
  diagPacket = other26.diagPacket;
  qmiPacket = other26.qmiPacket;
  adbPacket = other26.adbPacket;
  saharaPacket = other26.saharaPacket;
  fastbootPacket = other26.fastbootPacket;
  adplPacket = other26.adplPacket;
  nmeaPacket = other26.nmeaPacket;
  annotationPacket = other26.annotationPacket;
  qdssPacket = other26.qdssPacket;
  dunPacket = other26.dunPacket;
  eudPacket = other26.eudPacket;
  protoBufPacket = other26.protoBufPacket;
  telnetPacket = other26.telnetPacket;
  __isset = other26.__isset;
  return *this;
}
void DataPacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DataPacket(";
  out << "protocolHandle=" << to_string(protocolHandle);
  out << ", " << "diagPacket="; (__isset.diagPacket ? (out << to_string(diagPacket)) : (out << "<null>"));
  out << ", " << "qmiPacket="; (__isset.qmiPacket ? (out << to_string(qmiPacket)) : (out << "<null>"));
  out << ", " << "adbPacket="; (__isset.adbPacket ? (out << to_string(adbPacket)) : (out << "<null>"));
  out << ", " << "saharaPacket="; (__isset.saharaPacket ? (out << to_string(saharaPacket)) : (out << "<null>"));
  out << ", " << "fastbootPacket="; (__isset.fastbootPacket ? (out << to_string(fastbootPacket)) : (out << "<null>"));
  out << ", " << "adplPacket="; (__isset.adplPacket ? (out << to_string(adplPacket)) : (out << "<null>"));
  out << ", " << "nmeaPacket="; (__isset.nmeaPacket ? (out << to_string(nmeaPacket)) : (out << "<null>"));
  out << ", " << "annotationPacket="; (__isset.annotationPacket ? (out << to_string(annotationPacket)) : (out << "<null>"));
  out << ", " << "qdssPacket="; (__isset.qdssPacket ? (out << to_string(qdssPacket)) : (out << "<null>"));
  out << ", " << "dunPacket="; (__isset.dunPacket ? (out << to_string(dunPacket)) : (out << "<null>"));
  out << ", " << "eudPacket="; (__isset.eudPacket ? (out << to_string(eudPacket)) : (out << "<null>"));
  out << ", " << "protoBufPacket="; (__isset.protoBufPacket ? (out << to_string(protoBufPacket)) : (out << "<null>"));
  out << ", " << "telnetPacket="; (__isset.telnetPacket ? (out << to_string(telnetPacket)) : (out << "<null>"));
  out << ")";
}


PacketReturnConfig::~PacketReturnConfig() noexcept {
}


void PacketReturnConfig::__set_diagConfig(const  ::Uts::DiagReturnConfig& val) {
  this->diagConfig = val;
__isset.diagConfig = true;
}

void PacketReturnConfig::__set_qmiConfig(const  ::Uts::QmiReturnConfig& val) {
  this->qmiConfig = val;
__isset.qmiConfig = true;
}

void PacketReturnConfig::__set_adbConfig(const  ::Uts::AdbReturnConfig& val) {
  this->adbConfig = val;
__isset.adbConfig = true;
}

void PacketReturnConfig::__set_saharaConfig(const  ::Uts::SaharaReturnConfig& val) {
  this->saharaConfig = val;
__isset.saharaConfig = true;
}

void PacketReturnConfig::__set_fastbootConfig(const  ::Uts::FastbootReturnConfig& val) {
  this->fastbootConfig = val;
__isset.fastbootConfig = true;
}

void PacketReturnConfig::__set_adplConfig(const  ::Uts::AdplReturnConfig& val) {
  this->adplConfig = val;
__isset.adplConfig = true;
}

void PacketReturnConfig::__set_nmeaConfig(const  ::Uts::NmeaReturnConfig& val) {
  this->nmeaConfig = val;
__isset.nmeaConfig = true;
}

void PacketReturnConfig::__set_qdssConfig(const  ::Uts::QdssReturnConfig& val) {
  this->qdssConfig = val;
__isset.qdssConfig = true;
}

void PacketReturnConfig::__set_dunConfig(const  ::Uts::DunReturnConfig& val) {
  this->dunConfig = val;
__isset.dunConfig = true;
}

void PacketReturnConfig::__set_eudConfig(const  ::Uts::EudReturnConfig& val) {
  this->eudConfig = val;
__isset.eudConfig = true;
}

void PacketReturnConfig::__set_protoBufConfig(const  ::Uts::ProtoBufReturnConfig& val) {
  this->protoBufConfig = val;
__isset.protoBufConfig = true;
}

void PacketReturnConfig::__set_telnetConfig(const  ::Uts::TelnetReturnConfig& val) {
  this->telnetConfig = val;
__isset.telnetConfig = true;
}
std::ostream& operator<<(std::ostream& out, const PacketReturnConfig& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t PacketReturnConfig::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->diagConfig.read(iprot);
          this->__isset.diagConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->qmiConfig.read(iprot);
          this->__isset.qmiConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->adbConfig.read(iprot);
          this->__isset.adbConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->saharaConfig.read(iprot);
          this->__isset.saharaConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->fastbootConfig.read(iprot);
          this->__isset.fastbootConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->adplConfig.read(iprot);
          this->__isset.adplConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 7:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->nmeaConfig.read(iprot);
          this->__isset.nmeaConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 8:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->qdssConfig.read(iprot);
          this->__isset.qdssConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 9:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->dunConfig.read(iprot);
          this->__isset.dunConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 10:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->eudConfig.read(iprot);
          this->__isset.eudConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 11:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->protoBufConfig.read(iprot);
          this->__isset.protoBufConfig = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 12:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->telnetConfig.read(iprot);
          this->__isset.telnetConfig = true;
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

uint32_t PacketReturnConfig::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("PacketReturnConfig");

  if (this->__isset.diagConfig) {
    xfer += oprot->writeFieldBegin("diagConfig", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->diagConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qmiConfig) {
    xfer += oprot->writeFieldBegin("qmiConfig", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->qmiConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.adbConfig) {
    xfer += oprot->writeFieldBegin("adbConfig", ::apache::thrift::protocol::T_STRUCT, 3);
    xfer += this->adbConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.saharaConfig) {
    xfer += oprot->writeFieldBegin("saharaConfig", ::apache::thrift::protocol::T_STRUCT, 4);
    xfer += this->saharaConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.fastbootConfig) {
    xfer += oprot->writeFieldBegin("fastbootConfig", ::apache::thrift::protocol::T_STRUCT, 5);
    xfer += this->fastbootConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.adplConfig) {
    xfer += oprot->writeFieldBegin("adplConfig", ::apache::thrift::protocol::T_STRUCT, 6);
    xfer += this->adplConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.nmeaConfig) {
    xfer += oprot->writeFieldBegin("nmeaConfig", ::apache::thrift::protocol::T_STRUCT, 7);
    xfer += this->nmeaConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.qdssConfig) {
    xfer += oprot->writeFieldBegin("qdssConfig", ::apache::thrift::protocol::T_STRUCT, 8);
    xfer += this->qdssConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.dunConfig) {
    xfer += oprot->writeFieldBegin("dunConfig", ::apache::thrift::protocol::T_STRUCT, 9);
    xfer += this->dunConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.eudConfig) {
    xfer += oprot->writeFieldBegin("eudConfig", ::apache::thrift::protocol::T_STRUCT, 10);
    xfer += this->eudConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.protoBufConfig) {
    xfer += oprot->writeFieldBegin("protoBufConfig", ::apache::thrift::protocol::T_STRUCT, 11);
    xfer += this->protoBufConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.telnetConfig) {
    xfer += oprot->writeFieldBegin("telnetConfig", ::apache::thrift::protocol::T_STRUCT, 12);
    xfer += this->telnetConfig.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(PacketReturnConfig &a, PacketReturnConfig &b) {
  using ::std::swap;
  swap(a.diagConfig, b.diagConfig);
  swap(a.qmiConfig, b.qmiConfig);
  swap(a.adbConfig, b.adbConfig);
  swap(a.saharaConfig, b.saharaConfig);
  swap(a.fastbootConfig, b.fastbootConfig);
  swap(a.adplConfig, b.adplConfig);
  swap(a.nmeaConfig, b.nmeaConfig);
  swap(a.qdssConfig, b.qdssConfig);
  swap(a.dunConfig, b.dunConfig);
  swap(a.eudConfig, b.eudConfig);
  swap(a.protoBufConfig, b.protoBufConfig);
  swap(a.telnetConfig, b.telnetConfig);
  swap(a.__isset, b.__isset);
}

PacketReturnConfig::PacketReturnConfig(const PacketReturnConfig& other27) {
  diagConfig = other27.diagConfig;
  qmiConfig = other27.qmiConfig;
  adbConfig = other27.adbConfig;
  saharaConfig = other27.saharaConfig;
  fastbootConfig = other27.fastbootConfig;
  adplConfig = other27.adplConfig;
  nmeaConfig = other27.nmeaConfig;
  qdssConfig = other27.qdssConfig;
  dunConfig = other27.dunConfig;
  eudConfig = other27.eudConfig;
  protoBufConfig = other27.protoBufConfig;
  telnetConfig = other27.telnetConfig;
  __isset = other27.__isset;
}
PacketReturnConfig& PacketReturnConfig::operator=(const PacketReturnConfig& other28) {
  diagConfig = other28.diagConfig;
  qmiConfig = other28.qmiConfig;
  adbConfig = other28.adbConfig;
  saharaConfig = other28.saharaConfig;
  fastbootConfig = other28.fastbootConfig;
  adplConfig = other28.adplConfig;
  nmeaConfig = other28.nmeaConfig;
  qdssConfig = other28.qdssConfig;
  dunConfig = other28.dunConfig;
  eudConfig = other28.eudConfig;
  protoBufConfig = other28.protoBufConfig;
  telnetConfig = other28.telnetConfig;
  __isset = other28.__isset;
  return *this;
}
void PacketReturnConfig::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "PacketReturnConfig(";
  out << "diagConfig="; (__isset.diagConfig ? (out << to_string(diagConfig)) : (out << "<null>"));
  out << ", " << "qmiConfig="; (__isset.qmiConfig ? (out << to_string(qmiConfig)) : (out << "<null>"));
  out << ", " << "adbConfig="; (__isset.adbConfig ? (out << to_string(adbConfig)) : (out << "<null>"));
  out << ", " << "saharaConfig="; (__isset.saharaConfig ? (out << to_string(saharaConfig)) : (out << "<null>"));
  out << ", " << "fastbootConfig="; (__isset.fastbootConfig ? (out << to_string(fastbootConfig)) : (out << "<null>"));
  out << ", " << "adplConfig="; (__isset.adplConfig ? (out << to_string(adplConfig)) : (out << "<null>"));
  out << ", " << "nmeaConfig="; (__isset.nmeaConfig ? (out << to_string(nmeaConfig)) : (out << "<null>"));
  out << ", " << "qdssConfig="; (__isset.qdssConfig ? (out << to_string(qdssConfig)) : (out << "<null>"));
  out << ", " << "dunConfig="; (__isset.dunConfig ? (out << to_string(dunConfig)) : (out << "<null>"));
  out << ", " << "eudConfig="; (__isset.eudConfig ? (out << to_string(eudConfig)) : (out << "<null>"));
  out << ", " << "protoBufConfig="; (__isset.protoBufConfig ? (out << to_string(protoBufConfig)) : (out << "<null>"));
  out << ", " << "telnetConfig="; (__isset.telnetConfig ? (out << to_string(telnetConfig)) : (out << "<null>"));
  out << ")";
}


ClientSessionInfo::~ClientSessionInfo() noexcept {
}


void ClientSessionInfo::__set_clientId(const int32_t val) {
  this->clientId = val;
}

void ClientSessionInfo::__set_sessionName(const std::string& val) {
  this->sessionName = val;
}
std::ostream& operator<<(std::ostream& out, const ClientSessionInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t ClientSessionInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->clientId);
          this->__isset.clientId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->sessionName);
          this->__isset.sessionName = true;
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

uint32_t ClientSessionInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientSessionInfo");

  xfer += oprot->writeFieldBegin("clientId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->clientId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("sessionName", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->sessionName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(ClientSessionInfo &a, ClientSessionInfo &b) {
  using ::std::swap;
  swap(a.clientId, b.clientId);
  swap(a.sessionName, b.sessionName);
  swap(a.__isset, b.__isset);
}

ClientSessionInfo::ClientSessionInfo(const ClientSessionInfo& other29) {
  clientId = other29.clientId;
  sessionName = other29.sessionName;
  __isset = other29.__isset;
}
ClientSessionInfo& ClientSessionInfo::operator=(const ClientSessionInfo& other30) {
  clientId = other30.clientId;
  sessionName = other30.sessionName;
  __isset = other30.__isset;
  return *this;
}
void ClientSessionInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "ClientSessionInfo(";
  out << "clientId=" << to_string(clientId);
  out << ", " << "sessionName=" << to_string(sessionName);
  out << ")";
}


DiagLogSessionInformation::~DiagLogSessionInformation() noexcept {
}


void DiagLogSessionInformation::__set_packetId(const std::map< ::Uts::DiagPacketType::type, std::vector< ::Uts::DiagIdFilterItem> > & val) {
  this->packetId = val;
__isset.packetId = true;
}

void DiagLogSessionInformation::__set_subscriptionId(const std::vector<int32_t> & val) {
  this->subscriptionId = val;
__isset.subscriptionId = true;
}

void DiagLogSessionInformation::__set_miscellaneousId(const std::vector<int32_t> & val) {
  this->miscellaneousId = val;
__isset.miscellaneousId = true;
}

void DiagLogSessionInformation::__set_variantIdPacketIdMap(const std::map<int32_t, std::set<int64_t> > & val) {
  this->variantIdPacketIdMap = val;
__isset.variantIdPacketIdMap = true;
}

void DiagLogSessionInformation::__set_bIncludeAnnotation(const bool val) {
  this->bIncludeAnnotation = val;
__isset.bIncludeAnnotation = true;
}
std::ostream& operator<<(std::ostream& out, const DiagLogSessionInformation& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagLogSessionInformation::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->packetId.clear();
            uint32_t _size31;
            ::apache::thrift::protocol::TType _ktype32;
            ::apache::thrift::protocol::TType _vtype33;
            xfer += iprot->readMapBegin(_ktype32, _vtype33, _size31);
            uint32_t _i35;
            for (_i35 = 0; _i35 < _size31; ++_i35)
            {
               ::Uts::DiagPacketType::type _key36;
              int32_t ecast38;
              xfer += iprot->readI32(ecast38);
              _key36 = ( ::Uts::DiagPacketType::type)ecast38;
              std::vector< ::Uts::DiagIdFilterItem> & _val37 = this->packetId[_key36];
              {
                _val37.clear();
                uint32_t _size39;
                ::apache::thrift::protocol::TType _etype42;
                xfer += iprot->readListBegin(_etype42, _size39);
                _val37.resize(_size39);
                uint32_t _i43;
                for (_i43 = 0; _i43 < _size39; ++_i43)
                {
                  xfer += _val37[_i43].read(iprot);
                }
                xfer += iprot->readListEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.packetId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->subscriptionId.clear();
            uint32_t _size44;
            ::apache::thrift::protocol::TType _etype47;
            xfer += iprot->readListBegin(_etype47, _size44);
            this->subscriptionId.resize(_size44);
            uint32_t _i48;
            for (_i48 = 0; _i48 < _size44; ++_i48)
            {
              xfer += iprot->readI32(this->subscriptionId[_i48]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->miscellaneousId.clear();
            uint32_t _size49;
            ::apache::thrift::protocol::TType _etype52;
            xfer += iprot->readListBegin(_etype52, _size49);
            this->miscellaneousId.resize(_size49);
            uint32_t _i53;
            for (_i53 = 0; _i53 < _size49; ++_i53)
            {
              xfer += iprot->readI32(this->miscellaneousId[_i53]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.miscellaneousId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_MAP) {
          {
            this->variantIdPacketIdMap.clear();
            uint32_t _size54;
            ::apache::thrift::protocol::TType _ktype55;
            ::apache::thrift::protocol::TType _vtype56;
            xfer += iprot->readMapBegin(_ktype55, _vtype56, _size54);
            uint32_t _i58;
            for (_i58 = 0; _i58 < _size54; ++_i58)
            {
              int32_t _key59;
              xfer += iprot->readI32(_key59);
              std::set<int64_t> & _val60 = this->variantIdPacketIdMap[_key59];
              {
                _val60.clear();
                uint32_t _size61;
                ::apache::thrift::protocol::TType _etype64;
                xfer += iprot->readSetBegin(_etype64, _size61);
                uint32_t _i65;
                for (_i65 = 0; _i65 < _size61; ++_i65)
                {
                  int64_t _elem66;
                  xfer += iprot->readI64(_elem66);
                  _val60.insert(_elem66);
                }
                xfer += iprot->readSetEnd();
              }
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.variantIdPacketIdMap = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->bIncludeAnnotation);
          this->__isset.bIncludeAnnotation = true;
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

uint32_t DiagLogSessionInformation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagLogSessionInformation");

  if (this->__isset.packetId) {
    xfer += oprot->writeFieldBegin("packetId", ::apache::thrift::protocol::T_MAP, 1);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_LIST, static_cast<uint32_t>(this->packetId.size()));
      std::map< ::Uts::DiagPacketType::type, std::vector< ::Uts::DiagIdFilterItem> > ::const_iterator _iter67;
      for (_iter67 = this->packetId.begin(); _iter67 != this->packetId.end(); ++_iter67)
      {
        xfer += oprot->writeI32((int32_t)_iter67->first);
        {
          xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(_iter67->second.size()));
          std::vector< ::Uts::DiagIdFilterItem> ::const_iterator _iter68;
          for (_iter68 = _iter67->second.begin(); _iter68 != _iter67->second.end(); ++_iter68)
          {
            xfer += (*_iter68).write(oprot);
          }
          xfer += oprot->writeListEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.subscriptionId) {
    xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_LIST, 2);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->subscriptionId.size()));
      std::vector<int32_t> ::const_iterator _iter69;
      for (_iter69 = this->subscriptionId.begin(); _iter69 != this->subscriptionId.end(); ++_iter69)
      {
        xfer += oprot->writeI32((*_iter69));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.miscellaneousId) {
    xfer += oprot->writeFieldBegin("miscellaneousId", ::apache::thrift::protocol::T_LIST, 3);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I32, static_cast<uint32_t>(this->miscellaneousId.size()));
      std::vector<int32_t> ::const_iterator _iter70;
      for (_iter70 = this->miscellaneousId.begin(); _iter70 != this->miscellaneousId.end(); ++_iter70)
      {
        xfer += oprot->writeI32((*_iter70));
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.variantIdPacketIdMap) {
    xfer += oprot->writeFieldBegin("variantIdPacketIdMap", ::apache::thrift::protocol::T_MAP, 4);
    {
      xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_SET, static_cast<uint32_t>(this->variantIdPacketIdMap.size()));
      std::map<int32_t, std::set<int64_t> > ::const_iterator _iter71;
      for (_iter71 = this->variantIdPacketIdMap.begin(); _iter71 != this->variantIdPacketIdMap.end(); ++_iter71)
      {
        xfer += oprot->writeI32(_iter71->first);
        {
          xfer += oprot->writeSetBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(_iter71->second.size()));
          std::set<int64_t> ::const_iterator _iter72;
          for (_iter72 = _iter71->second.begin(); _iter72 != _iter71->second.end(); ++_iter72)
          {
            xfer += oprot->writeI64((*_iter72));
          }
          xfer += oprot->writeSetEnd();
        }
      }
      xfer += oprot->writeMapEnd();
    }
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.bIncludeAnnotation) {
    xfer += oprot->writeFieldBegin("bIncludeAnnotation", ::apache::thrift::protocol::T_BOOL, 5);
    xfer += oprot->writeBool(this->bIncludeAnnotation);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagLogSessionInformation &a, DiagLogSessionInformation &b) {
  using ::std::swap;
  swap(a.packetId, b.packetId);
  swap(a.subscriptionId, b.subscriptionId);
  swap(a.miscellaneousId, b.miscellaneousId);
  swap(a.variantIdPacketIdMap, b.variantIdPacketIdMap);
  swap(a.bIncludeAnnotation, b.bIncludeAnnotation);
  swap(a.__isset, b.__isset);
}

DiagLogSessionInformation::DiagLogSessionInformation(const DiagLogSessionInformation& other73) {
  packetId = other73.packetId;
  subscriptionId = other73.subscriptionId;
  miscellaneousId = other73.miscellaneousId;
  variantIdPacketIdMap = other73.variantIdPacketIdMap;
  bIncludeAnnotation = other73.bIncludeAnnotation;
  __isset = other73.__isset;
}
DiagLogSessionInformation& DiagLogSessionInformation::operator=(const DiagLogSessionInformation& other74) {
  packetId = other74.packetId;
  subscriptionId = other74.subscriptionId;
  miscellaneousId = other74.miscellaneousId;
  variantIdPacketIdMap = other74.variantIdPacketIdMap;
  bIncludeAnnotation = other74.bIncludeAnnotation;
  __isset = other74.__isset;
  return *this;
}
void DiagLogSessionInformation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagLogSessionInformation(";
  out << "packetId="; (__isset.packetId ? (out << to_string(packetId)) : (out << "<null>"));
  out << ", " << "subscriptionId="; (__isset.subscriptionId ? (out << to_string(subscriptionId)) : (out << "<null>"));
  out << ", " << "miscellaneousId="; (__isset.miscellaneousId ? (out << to_string(miscellaneousId)) : (out << "<null>"));
  out << ", " << "variantIdPacketIdMap="; (__isset.variantIdPacketIdMap ? (out << to_string(variantIdPacketIdMap)) : (out << "<null>"));
  out << ", " << "bIncludeAnnotation="; (__isset.bIncludeAnnotation ? (out << to_string(bIncludeAnnotation)) : (out << "<null>"));
  out << ")";
}


LogSessionInformation::~LogSessionInformation() noexcept {
}


void LogSessionInformation::__set_diagLogSessionInformation(const DiagLogSessionInformation& val) {
  this->diagLogSessionInformation = val;
__isset.diagLogSessionInformation = true;
}
std::ostream& operator<<(std::ostream& out, const LogSessionInformation& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t LogSessionInformation::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->diagLogSessionInformation.read(iprot);
          this->__isset.diagLogSessionInformation = true;
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

uint32_t LogSessionInformation::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("LogSessionInformation");

  if (this->__isset.diagLogSessionInformation) {
    xfer += oprot->writeFieldBegin("diagLogSessionInformation", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->diagLogSessionInformation.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(LogSessionInformation &a, LogSessionInformation &b) {
  using ::std::swap;
  swap(a.diagLogSessionInformation, b.diagLogSessionInformation);
  swap(a.__isset, b.__isset);
}

LogSessionInformation::LogSessionInformation(const LogSessionInformation& other75) {
  diagLogSessionInformation = other75.diagLogSessionInformation;
  __isset = other75.__isset;
}
LogSessionInformation& LogSessionInformation::operator=(const LogSessionInformation& other76) {
  diagLogSessionInformation = other76.diagLogSessionInformation;
  __isset = other76.__isset;
  return *this;
}
void LogSessionInformation::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "LogSessionInformation(";
  out << "diagLogSessionInformation="; (__isset.diagLogSessionInformation ? (out << to_string(diagLogSessionInformation)) : (out << "<null>"));
  out << ")";
}


DataViewInfo::~DataViewInfo() noexcept {
}


void DataViewInfo::__set_viewName(const std::string& val) {
  this->viewName = val;
}

void DataViewInfo::__set_filter(const DataPacketFilter& val) {
  this->filter = val;
}

void DataViewInfo::__set_returnConfig(const PacketReturnConfig& val) {
  this->returnConfig = val;
}
std::ostream& operator<<(std::ostream& out, const DataViewInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DataViewInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->viewName);
          this->__isset.viewName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->filter.read(iprot);
          this->__isset.filter = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->returnConfig.read(iprot);
          this->__isset.returnConfig = true;
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

uint32_t DataViewInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DataViewInfo");

  xfer += oprot->writeFieldBegin("viewName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->viewName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("filter", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->filter.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("returnConfig", ::apache::thrift::protocol::T_STRUCT, 3);
  xfer += this->returnConfig.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DataViewInfo &a, DataViewInfo &b) {
  using ::std::swap;
  swap(a.viewName, b.viewName);
  swap(a.filter, b.filter);
  swap(a.returnConfig, b.returnConfig);
  swap(a.__isset, b.__isset);
}

DataViewInfo::DataViewInfo(const DataViewInfo& other77) {
  viewName = other77.viewName;
  filter = other77.filter;
  returnConfig = other77.returnConfig;
  __isset = other77.__isset;
}
DataViewInfo& DataViewInfo::operator=(const DataViewInfo& other78) {
  viewName = other78.viewName;
  filter = other78.filter;
  returnConfig = other78.returnConfig;
  __isset = other78.__isset;
  return *this;
}
void DataViewInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DataViewInfo(";
  out << "viewName=" << to_string(viewName);
  out << ", " << "filter=" << to_string(filter);
  out << ", " << "returnConfig=" << to_string(returnConfig);
  out << ")";
}

} // namespace
