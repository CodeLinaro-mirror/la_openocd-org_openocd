/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DeviceManager_TYPES_H
#define DeviceManager_TYPES_H

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

struct OperatingMode {
  enum type {
    MODE_NONE = -1,
    OFFLINE_ANALOG = 0,
    OFFLINE_DIGITAL = 1,
    OFFLINE_FACTORY_TEST = 3,
    ONLINE = 4,
    LOW_POWER = 5,
    POWER_OFF = 6,
    OFFLINE = 7,
    RESET = 8,
    NET_TEST_GW = 9,
    OFFLINE_IF_NOT_FTM = 10,
    ONLINE_TX_DISABLED = 11
  };
};

extern const std::map<int, const char*> _OperatingMode_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const OperatingMode::type& val);

std::string to_string(const OperatingMode::type& val);

class OperatingModeInfo;

class SpcStatus;

typedef struct _OperatingModeInfo__isset {
  _OperatingModeInfo__isset() : errorType(false), operatingMode(false) {}
  bool errorType :1;
  bool operatingMode :1;
} _OperatingModeInfo__isset;

class OperatingModeInfo : public virtual ::apache::thrift::TBase {
 public:

  OperatingModeInfo(const OperatingModeInfo&);
  OperatingModeInfo& operator=(const OperatingModeInfo&);
  OperatingModeInfo() : operatingMode((OperatingMode::type)0) {
  }

  virtual ~OperatingModeInfo() noexcept;
   ::Uts::ErrorType errorType;
  OperatingMode::type operatingMode;

  _OperatingModeInfo__isset __isset;

  void __set_errorType(const  ::Uts::ErrorType& val);

  void __set_operatingMode(const OperatingMode::type val);

  bool operator == (const OperatingModeInfo & rhs) const
  {
    if (!(errorType == rhs.errorType))
      return false;
    if (__isset.operatingMode != rhs.__isset.operatingMode)
      return false;
    else if (__isset.operatingMode && !(operatingMode == rhs.operatingMode))
      return false;
    return true;
  }
  bool operator != (const OperatingModeInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const OperatingModeInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(OperatingModeInfo &a, OperatingModeInfo &b);

std::ostream& operator<<(std::ostream& out, const OperatingModeInfo& obj);

typedef struct _SpcStatus__isset {
  _SpcStatus__isset() : errorType(false), status(false) {}
  bool errorType :1;
  bool status :1;
} _SpcStatus__isset;

class SpcStatus : public virtual ::apache::thrift::TBase {
 public:

  SpcStatus(const SpcStatus&);
  SpcStatus& operator=(const SpcStatus&);
  SpcStatus() : status(0) {
  }

  virtual ~SpcStatus() noexcept;
   ::Uts::ErrorType errorType;
  bool status;

  _SpcStatus__isset __isset;

  void __set_errorType(const  ::Uts::ErrorType& val);

  void __set_status(const bool val);

  bool operator == (const SpcStatus & rhs) const
  {
    if (!(errorType == rhs.errorType))
      return false;
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const SpcStatus &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const SpcStatus & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(SpcStatus &a, SpcStatus &b);

std::ostream& operator<<(std::ostream& out, const SpcStatus& obj);

} // namespace

#endif
