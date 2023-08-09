/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "DiagService_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {

int _kSubsystemValues[] = {
  Subsystem::MPSS,
  Subsystem::APP,
  Subsystem::LPASS,
  Subsystem::SLPI,
  Subsystem::CDSP,
  Subsystem::NPU,
  Subsystem::AUDIO,
  Subsystem::SENSOR,
  Subsystem::WLAN,
  Subsystem::CHARGER
};
const char* _kSubsystemNames[] = {
  "MPSS",
  "APP",
  "LPASS",
  "SLPI",
  "CDSP",
  "NPU",
  "AUDIO",
  "SENSOR",
  "WLAN",
  "CHARGER"
};
const std::map<int, const char*> _Subsystem_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(10, _kSubsystemValues, _kSubsystemNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const Subsystem::type& val) {
  std::map<int, const char*>::const_iterator it = _Subsystem_VALUES_TO_NAMES.find(val);
  if (it != _Subsystem_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const Subsystem::type& val) {
  std::map<int, const char*>::const_iterator it = _Subsystem_VALUES_TO_NAMES.find(val);
  if (it != _Subsystem_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

int _kHealthReportConfigureStatusValues[] = {
  HealthReportConfigureStatus::INVALID_STATUS,
  HealthReportConfigureStatus::SUCCESS,
  HealthReportConfigureStatus::UNABLE_TO_GENERATE_REQUESTED_HEALTH_REPORT,
  HealthReportConfigureStatus::INVALID_TIMER_UNIT,
  HealthReportConfigureStatus::ERROR_SETTING_TIMER,
  HealthReportConfigureStatus::TIMER_UPDATED_BUT_TIMER_NOT_ENABLED_DUE_TO_LOG_MASK
};
const char* _kHealthReportConfigureStatusNames[] = {
  "INVALID_STATUS",
  "SUCCESS",
  "UNABLE_TO_GENERATE_REQUESTED_HEALTH_REPORT",
  "INVALID_TIMER_UNIT",
  "ERROR_SETTING_TIMER",
  "TIMER_UPDATED_BUT_TIMER_NOT_ENABLED_DUE_TO_LOG_MASK"
};
const std::map<int, const char*> _HealthReportConfigureStatus_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(6, _kHealthReportConfigureStatusValues, _kHealthReportConfigureStatusNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const HealthReportConfigureStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _HealthReportConfigureStatus_VALUES_TO_NAMES.find(val);
  if (it != _HealthReportConfigureStatus_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const HealthReportConfigureStatus::type& val) {
  std::map<int, const char*>::const_iterator it = _HealthReportConfigureStatus_VALUES_TO_NAMES.find(val);
  if (it != _HealthReportConfigureStatus_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


DiagConnectionOptions::~DiagConnectionOptions() noexcept {
}


void DiagConnectionOptions::__set_protocolHandle(const int64_t val) {
  this->protocolHandle = val;
__isset.protocolHandle = true;
}

void DiagConnectionOptions::__set_openQdssPort(const bool val) {
  this->openQdssPort = val;
__isset.openQdssPort = true;
}

void DiagConnectionOptions::__set_enableDefaultQdssConfiguration(const bool val) {
  this->enableDefaultQdssConfiguration = val;
__isset.enableDefaultQdssConfiguration = true;
}

void DiagConnectionOptions::__set_enableHdlcOnly(const bool val) {
  this->enableHdlcOnly = val;
__isset.enableHdlcOnly = true;
}

void DiagConnectionOptions::__set_enableMbnDownload(const bool val) {
  this->enableMbnDownload = val;
__isset.enableMbnDownload = true;
}
std::ostream& operator<<(std::ostream& out, const DiagConnectionOptions& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DiagConnectionOptions::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->openQdssPort);
          this->__isset.openQdssPort = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->enableDefaultQdssConfiguration);
          this->__isset.enableDefaultQdssConfiguration = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->enableHdlcOnly);
          this->__isset.enableHdlcOnly = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->enableMbnDownload);
          this->__isset.enableMbnDownload = true;
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

uint32_t DiagConnectionOptions::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DiagConnectionOptions");

  if (this->__isset.protocolHandle) {
    xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
    xfer += oprot->writeI64(this->protocolHandle);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.openQdssPort) {
    xfer += oprot->writeFieldBegin("openQdssPort", ::apache::thrift::protocol::T_BOOL, 2);
    xfer += oprot->writeBool(this->openQdssPort);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.enableDefaultQdssConfiguration) {
    xfer += oprot->writeFieldBegin("enableDefaultQdssConfiguration", ::apache::thrift::protocol::T_BOOL, 3);
    xfer += oprot->writeBool(this->enableDefaultQdssConfiguration);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.enableHdlcOnly) {
    xfer += oprot->writeFieldBegin("enableHdlcOnly", ::apache::thrift::protocol::T_BOOL, 4);
    xfer += oprot->writeBool(this->enableHdlcOnly);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.enableMbnDownload) {
    xfer += oprot->writeFieldBegin("enableMbnDownload", ::apache::thrift::protocol::T_BOOL, 5);
    xfer += oprot->writeBool(this->enableMbnDownload);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DiagConnectionOptions &a, DiagConnectionOptions &b) {
  using ::std::swap;
  swap(a.protocolHandle, b.protocolHandle);
  swap(a.openQdssPort, b.openQdssPort);
  swap(a.enableDefaultQdssConfiguration, b.enableDefaultQdssConfiguration);
  swap(a.enableHdlcOnly, b.enableHdlcOnly);
  swap(a.enableMbnDownload, b.enableMbnDownload);
  swap(a.__isset, b.__isset);
}

DiagConnectionOptions::DiagConnectionOptions(const DiagConnectionOptions& other0) {
  protocolHandle = other0.protocolHandle;
  openQdssPort = other0.openQdssPort;
  enableDefaultQdssConfiguration = other0.enableDefaultQdssConfiguration;
  enableHdlcOnly = other0.enableHdlcOnly;
  enableMbnDownload = other0.enableMbnDownload;
  __isset = other0.__isset;
}
DiagConnectionOptions& DiagConnectionOptions::operator=(const DiagConnectionOptions& other1) {
  protocolHandle = other1.protocolHandle;
  openQdssPort = other1.openQdssPort;
  enableDefaultQdssConfiguration = other1.enableDefaultQdssConfiguration;
  enableHdlcOnly = other1.enableHdlcOnly;
  enableMbnDownload = other1.enableMbnDownload;
  __isset = other1.__isset;
  return *this;
}
void DiagConnectionOptions::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DiagConnectionOptions(";
  out << "protocolHandle="; (__isset.protocolHandle ? (out << to_string(protocolHandle)) : (out << "<null>"));
  out << ", " << "openQdssPort="; (__isset.openQdssPort ? (out << to_string(openQdssPort)) : (out << "<null>"));
  out << ", " << "enableDefaultQdssConfiguration="; (__isset.enableDefaultQdssConfiguration ? (out << to_string(enableDefaultQdssConfiguration)) : (out << "<null>"));
  out << ", " << "enableHdlcOnly="; (__isset.enableHdlcOnly ? (out << to_string(enableHdlcOnly)) : (out << "<null>"));
  out << ", " << "enableMbnDownload="; (__isset.enableMbnDownload ? (out << to_string(enableMbnDownload)) : (out << "<null>"));
  out << ")";
}


DataQueuePacket::~DataQueuePacket() noexcept {
}


void DataQueuePacket::__set_diagPacket(const  ::Uts::DiagPacket& val) {
  this->diagPacket = val;
__isset.diagPacket = true;
}

void DataQueuePacket::__set_annotationPacket(const  ::Uts::AnnotationPacket& val) {
  this->annotationPacket = val;
__isset.annotationPacket = true;
}
std::ostream& operator<<(std::ostream& out, const DataQueuePacket& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t DataQueuePacket::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->diagPacket.read(iprot);
          this->__isset.diagPacket = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->annotationPacket.read(iprot);
          this->__isset.annotationPacket = true;
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

uint32_t DataQueuePacket::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DataQueuePacket");

  if (this->__isset.diagPacket) {
    xfer += oprot->writeFieldBegin("diagPacket", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->diagPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  if (this->__isset.annotationPacket) {
    xfer += oprot->writeFieldBegin("annotationPacket", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->annotationPacket.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(DataQueuePacket &a, DataQueuePacket &b) {
  using ::std::swap;
  swap(a.diagPacket, b.diagPacket);
  swap(a.annotationPacket, b.annotationPacket);
  swap(a.__isset, b.__isset);
}

DataQueuePacket::DataQueuePacket(const DataQueuePacket& other2) {
  diagPacket = other2.diagPacket;
  annotationPacket = other2.annotationPacket;
  __isset = other2.__isset;
}
DataQueuePacket& DataQueuePacket::operator=(const DataQueuePacket& other3) {
  diagPacket = other3.diagPacket;
  annotationPacket = other3.annotationPacket;
  __isset = other3.__isset;
  return *this;
}
void DataQueuePacket::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "DataQueuePacket(";
  out << "diagPacket="; (__isset.diagPacket ? (out << to_string(diagPacket)) : (out << "<null>"));
  out << ", " << "annotationPacket="; (__isset.annotationPacket ? (out << to_string(annotationPacket)) : (out << "<null>"));
  out << ")";
}

} // namespace
