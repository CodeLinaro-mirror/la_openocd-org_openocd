/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DiagService_TYPES_H
#define DiagService_TYPES_H

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

struct Subsystem {
  enum type {
    MPSS = 2098,
    APP = 553,
    LPASS = 3615,
    SLPI = 6705,
    CDSP = 9253,
    NPU = 9764,
    AUDIO = 103,
    SENSOR = 104,
    WLAN = 107,
    CHARGER = 119
  };
};

extern const std::map<int, const char*> _Subsystem_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const Subsystem::type& val);

std::string to_string(const Subsystem::type& val);

struct HealthReportConfigureStatus {
  enum type {
    INVALID_STATUS = -1,
    SUCCESS = 0,
    UNABLE_TO_GENERATE_REQUESTED_HEALTH_REPORT = 1,
    INVALID_TIMER_UNIT = 2,
    ERROR_SETTING_TIMER = 3,
    TIMER_UPDATED_BUT_TIMER_NOT_ENABLED_DUE_TO_LOG_MASK = 4
  };
};

extern const std::map<int, const char*> _HealthReportConfigureStatus_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const HealthReportConfigureStatus::type& val);

std::string to_string(const HealthReportConfigureStatus::type& val);

class DiagConnectionOptions;

class DataQueuePacket;

typedef struct _DiagConnectionOptions__isset {
  _DiagConnectionOptions__isset() : protocolHandle(false), openQdssPort(false), enableDefaultQdssConfiguration(false), enableHdlcOnly(false), enableMbnDownload(false) {}
  bool protocolHandle :1;
  bool openQdssPort :1;
  bool enableDefaultQdssConfiguration :1;
  bool enableHdlcOnly :1;
  bool enableMbnDownload :1;
} _DiagConnectionOptions__isset;

class DiagConnectionOptions : public virtual ::apache::thrift::TBase {
 public:

  DiagConnectionOptions(const DiagConnectionOptions&);
  DiagConnectionOptions& operator=(const DiagConnectionOptions&);
  DiagConnectionOptions() : protocolHandle(0), openQdssPort(0), enableDefaultQdssConfiguration(0), enableHdlcOnly(0), enableMbnDownload(0) {
  }

  virtual ~DiagConnectionOptions() noexcept;
  int64_t protocolHandle;
  bool openQdssPort;
  bool enableDefaultQdssConfiguration;
  bool enableHdlcOnly;
  bool enableMbnDownload;

  _DiagConnectionOptions__isset __isset;

  void __set_protocolHandle(const int64_t val);

  void __set_openQdssPort(const bool val);

  void __set_enableDefaultQdssConfiguration(const bool val);

  void __set_enableHdlcOnly(const bool val);

  void __set_enableMbnDownload(const bool val);

  bool operator == (const DiagConnectionOptions & rhs) const
  {
    if (__isset.protocolHandle != rhs.__isset.protocolHandle)
      return false;
    else if (__isset.protocolHandle && !(protocolHandle == rhs.protocolHandle))
      return false;
    if (__isset.openQdssPort != rhs.__isset.openQdssPort)
      return false;
    else if (__isset.openQdssPort && !(openQdssPort == rhs.openQdssPort))
      return false;
    if (__isset.enableDefaultQdssConfiguration != rhs.__isset.enableDefaultQdssConfiguration)
      return false;
    else if (__isset.enableDefaultQdssConfiguration && !(enableDefaultQdssConfiguration == rhs.enableDefaultQdssConfiguration))
      return false;
    if (__isset.enableHdlcOnly != rhs.__isset.enableHdlcOnly)
      return false;
    else if (__isset.enableHdlcOnly && !(enableHdlcOnly == rhs.enableHdlcOnly))
      return false;
    if (__isset.enableMbnDownload != rhs.__isset.enableMbnDownload)
      return false;
    else if (__isset.enableMbnDownload && !(enableMbnDownload == rhs.enableMbnDownload))
      return false;
    return true;
  }
  bool operator != (const DiagConnectionOptions &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DiagConnectionOptions & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DiagConnectionOptions &a, DiagConnectionOptions &b);

std::ostream& operator<<(std::ostream& out, const DiagConnectionOptions& obj);

typedef struct _DataQueuePacket__isset {
  _DataQueuePacket__isset() : diagPacket(false), annotationPacket(false) {}
  bool diagPacket :1;
  bool annotationPacket :1;
} _DataQueuePacket__isset;

class DataQueuePacket : public virtual ::apache::thrift::TBase {
 public:

  DataQueuePacket(const DataQueuePacket&);
  DataQueuePacket& operator=(const DataQueuePacket&);
  DataQueuePacket() {
  }

  virtual ~DataQueuePacket() noexcept;
   ::Uts::DiagPacket diagPacket;
   ::Uts::AnnotationPacket annotationPacket;

  _DataQueuePacket__isset __isset;

  void __set_diagPacket(const  ::Uts::DiagPacket& val);

  void __set_annotationPacket(const  ::Uts::AnnotationPacket& val);

  bool operator == (const DataQueuePacket & rhs) const
  {
    if (__isset.diagPacket != rhs.__isset.diagPacket)
      return false;
    else if (__isset.diagPacket && !(diagPacket == rhs.diagPacket))
      return false;
    if (__isset.annotationPacket != rhs.__isset.annotationPacket)
      return false;
    else if (__isset.annotationPacket && !(annotationPacket == rhs.annotationPacket))
      return false;
    return true;
  }
  bool operator != (const DataQueuePacket &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const DataQueuePacket & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(DataQueuePacket &a, DataQueuePacket &b);

std::ostream& operator<<(std::ostream& out, const DataQueuePacket& obj);

} // namespace

#endif
