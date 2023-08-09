/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "DeviceManager_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {

int _kOperatingModeValues[] = {
  OperatingMode::MODE_NONE,
  OperatingMode::OFFLINE_ANALOG,
  OperatingMode::OFFLINE_DIGITAL,
  OperatingMode::OFFLINE_FACTORY_TEST,
  OperatingMode::ONLINE,
  OperatingMode::LOW_POWER,
  OperatingMode::POWER_OFF,
  OperatingMode::OFFLINE,
  OperatingMode::RESET,
  OperatingMode::NET_TEST_GW,
  OperatingMode::OFFLINE_IF_NOT_FTM,
  OperatingMode::ONLINE_TX_DISABLED
};
const char* _kOperatingModeNames[] = {
  "MODE_NONE",
  "OFFLINE_ANALOG",
  "OFFLINE_DIGITAL",
  "OFFLINE_FACTORY_TEST",
  "ONLINE",
  "LOW_POWER",
  "POWER_OFF",
  "OFFLINE",
  "RESET",
  "NET_TEST_GW",
  "OFFLINE_IF_NOT_FTM",
  "ONLINE_TX_DISABLED"
};
const std::map<int, const char*> _OperatingMode_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(12, _kOperatingModeValues, _kOperatingModeNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const OperatingMode::type& val) {
  std::map<int, const char*>::const_iterator it = _OperatingMode_VALUES_TO_NAMES.find(val);
  if (it != _OperatingMode_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const OperatingMode::type& val) {
  std::map<int, const char*>::const_iterator it = _OperatingMode_VALUES_TO_NAMES.find(val);
  if (it != _OperatingMode_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}


OperatingModeInfo::~OperatingModeInfo() noexcept {
}


void OperatingModeInfo::__set_errorType(const  ::Uts::ErrorType& val) {
  this->errorType = val;
}

void OperatingModeInfo::__set_operatingMode(const OperatingMode::type val) {
  this->operatingMode = val;
__isset.operatingMode = true;
}
std::ostream& operator<<(std::ostream& out, const OperatingModeInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t OperatingModeInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->errorType.read(iprot);
          this->__isset.errorType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast0;
          xfer += iprot->readI32(ecast0);
          this->operatingMode = (OperatingMode::type)ecast0;
          this->__isset.operatingMode = true;
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

uint32_t OperatingModeInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("OperatingModeInfo");

  xfer += oprot->writeFieldBegin("errorType", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->errorType.write(oprot);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.operatingMode) {
    xfer += oprot->writeFieldBegin("operatingMode", ::apache::thrift::protocol::T_I32, 2);
    xfer += oprot->writeI32((int32_t)this->operatingMode);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(OperatingModeInfo &a, OperatingModeInfo &b) {
  using ::std::swap;
  swap(a.errorType, b.errorType);
  swap(a.operatingMode, b.operatingMode);
  swap(a.__isset, b.__isset);
}

OperatingModeInfo::OperatingModeInfo(const OperatingModeInfo& other1) {
  errorType = other1.errorType;
  operatingMode = other1.operatingMode;
  __isset = other1.__isset;
}
OperatingModeInfo& OperatingModeInfo::operator=(const OperatingModeInfo& other2) {
  errorType = other2.errorType;
  operatingMode = other2.operatingMode;
  __isset = other2.__isset;
  return *this;
}
void OperatingModeInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "OperatingModeInfo(";
  out << "errorType=" << to_string(errorType);
  out << ", " << "operatingMode="; (__isset.operatingMode ? (out << to_string(operatingMode)) : (out << "<null>"));
  out << ")";
}


SpcStatus::~SpcStatus() noexcept {
}


void SpcStatus::__set_errorType(const  ::Uts::ErrorType& val) {
  this->errorType = val;
}

void SpcStatus::__set_status(const bool val) {
  this->status = val;
}
std::ostream& operator<<(std::ostream& out, const SpcStatus& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t SpcStatus::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->errorType.read(iprot);
          this->__isset.errorType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->status);
          this->__isset.status = true;
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

uint32_t SpcStatus::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("SpcStatus");

  xfer += oprot->writeFieldBegin("errorType", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->errorType.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(SpcStatus &a, SpcStatus &b) {
  using ::std::swap;
  swap(a.errorType, b.errorType);
  swap(a.status, b.status);
  swap(a.__isset, b.__isset);
}

SpcStatus::SpcStatus(const SpcStatus& other3) {
  errorType = other3.errorType;
  status = other3.status;
  __isset = other3.__isset;
}
SpcStatus& SpcStatus::operator=(const SpcStatus& other4) {
  errorType = other4.errorType;
  status = other4.status;
  __isset = other4.__isset;
  return *this;
}
void SpcStatus::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "SpcStatus(";
  out << "errorType=" << to_string(errorType);
  out << ", " << "status=" << to_string(status);
  out << ")";
}

} // namespace
