/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "ClientCallback.h"

namespace Uts {


ClientCallback_onMessage_args::~ClientCallback_onMessage_args() noexcept {
}


uint32_t ClientCallback_onMessage_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          this->level = (MessageLevel::type)ecast0;
          this->__isset.level = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->location);
          this->__isset.location = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->title);
          this->__isset.title = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->description);
          this->__isset.description = true;
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

uint32_t ClientCallback_onMessage_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onMessage_args");

  xfer += oprot->writeFieldBegin("level", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->level);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("location", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->location);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("title", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->title);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->description);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onMessage_pargs::~ClientCallback_onMessage_pargs() noexcept {
}


uint32_t ClientCallback_onMessage_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onMessage_pargs");

  xfer += oprot->writeFieldBegin("level", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->level)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("location", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString((*(this->location)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("title", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString((*(this->title)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("description", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString((*(this->description)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDeviceConnected_args::~ClientCallback_onDeviceConnected_args() noexcept {
}


uint32_t ClientCallback_onDeviceConnected_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->deviceInfo.read(iprot);
          this->__isset.deviceInfo = true;
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

uint32_t ClientCallback_onDeviceConnected_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDeviceConnected_args");

  xfer += oprot->writeFieldBegin("deviceInfo", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->deviceInfo.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDeviceConnected_pargs::~ClientCallback_onDeviceConnected_pargs() noexcept {
}


uint32_t ClientCallback_onDeviceConnected_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDeviceConnected_pargs");

  xfer += oprot->writeFieldBegin("deviceInfo", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->deviceInfo)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDeviceDisconnected_args::~ClientCallback_onDeviceDisconnected_args() noexcept {
}


uint32_t ClientCallback_onDeviceDisconnected_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->deviceInfo.read(iprot);
          this->__isset.deviceInfo = true;
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

uint32_t ClientCallback_onDeviceDisconnected_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDeviceDisconnected_args");

  xfer += oprot->writeFieldBegin("deviceInfo", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->deviceInfo.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDeviceDisconnected_pargs::~ClientCallback_onDeviceDisconnected_pargs() noexcept {
}


uint32_t ClientCallback_onDeviceDisconnected_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDeviceDisconnected_pargs");

  xfer += oprot->writeFieldBegin("deviceInfo", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->deviceInfo)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDeviceModeChange_args::~ClientCallback_onDeviceModeChange_args() noexcept {
}


uint32_t ClientCallback_onDeviceModeChange_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI64(this->deviceHandle);
          this->__isset.deviceHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast1;
          xfer += iprot->readI32(ecast1);
          this->newMode = ( ::Uts::DeviceMode::type)ecast1;
          this->__isset.newMode = true;
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

uint32_t ClientCallback_onDeviceModeChange_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDeviceModeChange_args");

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->deviceHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newMode", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->newMode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDeviceModeChange_pargs::~ClientCallback_onDeviceModeChange_pargs() noexcept {
}


uint32_t ClientCallback_onDeviceModeChange_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDeviceModeChange_pargs");

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->deviceHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newMode", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->newMode)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolAdded_args::~ClientCallback_onProtocolAdded_args() noexcept {
}


uint32_t ClientCallback_onProtocolAdded_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->deviceInfo.read(iprot);
          this->__isset.deviceInfo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->protocolInfo.read(iprot);
          this->__isset.protocolInfo = true;
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

uint32_t ClientCallback_onProtocolAdded_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolAdded_args");

  xfer += oprot->writeFieldBegin("deviceInfo", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->deviceInfo.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolInfo", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->protocolInfo.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolAdded_pargs::~ClientCallback_onProtocolAdded_pargs() noexcept {
}


uint32_t ClientCallback_onProtocolAdded_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolAdded_pargs");

  xfer += oprot->writeFieldBegin("deviceInfo", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->deviceInfo)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolInfo", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += (*(this->protocolInfo)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolRemoved_args::~ClientCallback_onProtocolRemoved_args() noexcept {
}


uint32_t ClientCallback_onProtocolRemoved_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->deviceInfo.read(iprot);
          this->__isset.deviceInfo = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->protocolInfo.read(iprot);
          this->__isset.protocolInfo = true;
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

uint32_t ClientCallback_onProtocolRemoved_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolRemoved_args");

  xfer += oprot->writeFieldBegin("deviceInfo", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->deviceInfo.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolInfo", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->protocolInfo.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolRemoved_pargs::~ClientCallback_onProtocolRemoved_pargs() noexcept {
}


uint32_t ClientCallback_onProtocolRemoved_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolRemoved_pargs");

  xfer += oprot->writeFieldBegin("deviceInfo", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->deviceInfo)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolInfo", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += (*(this->protocolInfo)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolStateChange_args::~ClientCallback_onProtocolStateChange_args() noexcept {
}


uint32_t ClientCallback_onProtocolStateChange_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast2;
          xfer += iprot->readI32(ecast2);
          this->newState = ( ::Uts::ProtocolState::type)ecast2;
          this->__isset.newState = true;
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

uint32_t ClientCallback_onProtocolStateChange_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolStateChange_args");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newState", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->newState);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolStateChange_pargs::~ClientCallback_onProtocolStateChange_pargs() noexcept {
}


uint32_t ClientCallback_onProtocolStateChange_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolStateChange_pargs");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newState", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->newState)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolFlowControlStatusChange_args::~ClientCallback_onProtocolFlowControlStatusChange_args() noexcept {
}


uint32_t ClientCallback_onProtocolFlowControlStatusChange_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast3;
          xfer += iprot->readI32(ecast3);
          this->dir = ( ::Uts::Direction::type)ecast3;
          this->__isset.dir = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast4;
          xfer += iprot->readI32(ecast4);
          this->newStatus = ( ::Uts::FlowControlStatus::type)ecast4;
          this->__isset.newStatus = true;
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

uint32_t ClientCallback_onProtocolFlowControlStatusChange_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolFlowControlStatusChange_args");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dir", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->dir);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newStatus", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)this->newStatus);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolFlowControlStatusChange_pargs::~ClientCallback_onProtocolFlowControlStatusChange_pargs() noexcept {
}


uint32_t ClientCallback_onProtocolFlowControlStatusChange_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolFlowControlStatusChange_pargs");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("dir", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->dir)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newStatus", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)(*(this->newStatus)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolLockStatusChange_args::~ClientCallback_onProtocolLockStatusChange_args() noexcept {
}


uint32_t ClientCallback_onProtocolLockStatusChange_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->newStatus.read(iprot);
          this->__isset.newStatus = true;
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

uint32_t ClientCallback_onProtocolLockStatusChange_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolLockStatusChange_args");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newStatus", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->newStatus.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolLockStatusChange_pargs::~ClientCallback_onProtocolLockStatusChange_pargs() noexcept {
}


uint32_t ClientCallback_onProtocolLockStatusChange_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolLockStatusChange_pargs");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newStatus", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += (*(this->newStatus)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolMbnDownloadStatusChange_args::~ClientCallback_onProtocolMbnDownloadStatusChange_args() noexcept {
}


uint32_t ClientCallback_onProtocolMbnDownloadStatusChange_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->newStatus.read(iprot);
          this->__isset.newStatus = true;
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

uint32_t ClientCallback_onProtocolMbnDownloadStatusChange_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolMbnDownloadStatusChange_args");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newStatus", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->newStatus.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onProtocolMbnDownloadStatusChange_pargs::~ClientCallback_onProtocolMbnDownloadStatusChange_pargs() noexcept {
}


uint32_t ClientCallback_onProtocolMbnDownloadStatusChange_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onProtocolMbnDownloadStatusChange_pargs");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newStatus", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += (*(this->newStatus)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onClientCloseRequest_args::~ClientCallback_onClientCloseRequest_args() noexcept {
}


uint32_t ClientCallback_onClientCloseRequest_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->closeReason.read(iprot);
          this->__isset.closeReason = true;
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

uint32_t ClientCallback_onClientCloseRequest_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onClientCloseRequest_args");

  xfer += oprot->writeFieldBegin("closeReason", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->closeReason.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onClientCloseRequest_pargs::~ClientCallback_onClientCloseRequest_pargs() noexcept {
}


uint32_t ClientCallback_onClientCloseRequest_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onClientCloseRequest_pargs");

  xfer += oprot->writeFieldBegin("closeReason", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->closeReason)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onMissingQShrinkHashFile_args::~ClientCallback_onMissingQShrinkHashFile_args() noexcept {
}


uint32_t ClientCallback_onMissingQShrinkHashFile_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->missingFileGuid);
          this->__isset.missingFileGuid = true;
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

uint32_t ClientCallback_onMissingQShrinkHashFile_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onMissingQShrinkHashFile_args");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("missingFileGuid", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->missingFileGuid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onMissingQShrinkHashFile_pargs::~ClientCallback_onMissingQShrinkHashFile_pargs() noexcept {
}


uint32_t ClientCallback_onMissingQShrinkHashFile_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onMissingQShrinkHashFile_pargs");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("missingFileGuid", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString((*(this->missingFileGuid)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onLogSessionMissingQShrinkHashFile_args::~ClientCallback_onLogSessionMissingQShrinkHashFile_args() noexcept {
}


uint32_t ClientCallback_onLogSessionMissingQShrinkHashFile_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->logSessionInstance);
          this->__isset.logSessionInstance = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->missingFileGuid);
          this->__isset.missingFileGuid = true;
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

uint32_t ClientCallback_onLogSessionMissingQShrinkHashFile_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onLogSessionMissingQShrinkHashFile_args");

  xfer += oprot->writeFieldBegin("logSessionInstance", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->logSessionInstance);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("missingFileGuid", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->missingFileGuid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onLogSessionMissingQShrinkHashFile_pargs::~ClientCallback_onLogSessionMissingQShrinkHashFile_pargs() noexcept {
}


uint32_t ClientCallback_onLogSessionMissingQShrinkHashFile_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onLogSessionMissingQShrinkHashFile_pargs");

  xfer += oprot->writeFieldBegin("logSessionInstance", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->logSessionInstance)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("missingFileGuid", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString((*(this->missingFileGuid)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onAsyncResponse_args::~ClientCallback_onAsyncResponse_args() noexcept {
}


uint32_t ClientCallback_onAsyncResponse_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->transactionId);
          this->__isset.transactionId = true;
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

uint32_t ClientCallback_onAsyncResponse_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onAsyncResponse_args");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("transactionId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->transactionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onAsyncResponse_pargs::~ClientCallback_onAsyncResponse_pargs() noexcept {
}


uint32_t ClientCallback_onAsyncResponse_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onAsyncResponse_pargs");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("transactionId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->transactionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDataQueueUpdated_args::~ClientCallback_onDataQueueUpdated_args() noexcept {
}


uint32_t ClientCallback_onDataQueueUpdated_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->queueName);
          this->__isset.queueName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->queueSize);
          this->__isset.queueSize = true;
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

uint32_t ClientCallback_onDataQueueUpdated_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDataQueueUpdated_args");

  xfer += oprot->writeFieldBegin("queueName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->queueName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("queueSize", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->queueSize);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDataQueueUpdated_pargs::~ClientCallback_onDataQueueUpdated_pargs() noexcept {
}


uint32_t ClientCallback_onDataQueueUpdated_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDataQueueUpdated_pargs");

  xfer += oprot->writeFieldBegin("queueName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->queueName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("queueSize", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->queueSize)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDataViewUpdated_args::~ClientCallback_onDataViewUpdated_args() noexcept {
}


uint32_t ClientCallback_onDataViewUpdated_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->viewSize);
          this->__isset.viewSize = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->finished);
          this->__isset.finished = true;
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

uint32_t ClientCallback_onDataViewUpdated_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDataViewUpdated_args");

  xfer += oprot->writeFieldBegin("viewName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->viewName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("viewSize", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->viewSize);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("finished", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool(this->finished);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDataViewUpdated_pargs::~ClientCallback_onDataViewUpdated_pargs() noexcept {
}


uint32_t ClientCallback_onDataViewUpdated_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDataViewUpdated_pargs");

  xfer += oprot->writeFieldBegin("viewName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->viewName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("viewSize", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->viewSize)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("finished", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool((*(this->finished)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onServiceAvailable_args::~ClientCallback_onServiceAvailable_args() noexcept {
}


uint32_t ClientCallback_onServiceAvailable_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->serviceName);
          this->__isset.serviceName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->deviceHandle);
          this->__isset.deviceHandle = true;
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

uint32_t ClientCallback_onServiceAvailable_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onServiceAvailable_args");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->serviceName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->deviceHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onServiceAvailable_pargs::~ClientCallback_onServiceAvailable_pargs() noexcept {
}


uint32_t ClientCallback_onServiceAvailable_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onServiceAvailable_pargs");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->serviceName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->deviceHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onServiceEnded_args::~ClientCallback_onServiceEnded_args() noexcept {
}


uint32_t ClientCallback_onServiceEnded_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->serviceName);
          this->__isset.serviceName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->deviceHandle);
          this->__isset.deviceHandle = true;
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

uint32_t ClientCallback_onServiceEnded_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onServiceEnded_args");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->serviceName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->deviceHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onServiceEnded_pargs::~ClientCallback_onServiceEnded_pargs() noexcept {
}


uint32_t ClientCallback_onServiceEnded_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onServiceEnded_pargs");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->serviceName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->deviceHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onServiceEvent_args::~ClientCallback_onServiceEvent_args() noexcept {
}


uint32_t ClientCallback_onServiceEvent_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->serviceName);
          this->__isset.serviceName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->eventId);
          this->__isset.eventId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->eventDescription);
          this->__isset.eventDescription = true;
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

uint32_t ClientCallback_onServiceEvent_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onServiceEvent_args");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->serviceName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->eventId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventDescription", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString(this->eventDescription);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onServiceEvent_pargs::~ClientCallback_onServiceEvent_pargs() noexcept {
}


uint32_t ClientCallback_onServiceEvent_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onServiceEvent_pargs");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->serviceName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventId", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->eventId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventDescription", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeString((*(this->eventDescription)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onImageManagementServiceEvent_args::~ClientCallback_onImageManagementServiceEvent_args() noexcept {
}


uint32_t ClientCallback_onImageManagementServiceEvent_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->serviceName);
          this->__isset.serviceName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->deviceHandle);
          this->__isset.deviceHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->eventId);
          this->__isset.eventId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->eventDescription);
          this->__isset.eventDescription = true;
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

uint32_t ClientCallback_onImageManagementServiceEvent_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onImageManagementServiceEvent_args");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->serviceName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->deviceHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventId", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->eventId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventDescription", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->eventDescription);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onImageManagementServiceEvent_pargs::~ClientCallback_onImageManagementServiceEvent_pargs() noexcept {
}


uint32_t ClientCallback_onImageManagementServiceEvent_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onImageManagementServiceEvent_pargs");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->serviceName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->deviceHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventId", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64((*(this->eventId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventDescription", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString((*(this->eventDescription)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDeviceConfigServiceEvent_args::~ClientCallback_onDeviceConfigServiceEvent_args() noexcept {
}


uint32_t ClientCallback_onDeviceConfigServiceEvent_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->serviceName);
          this->__isset.serviceName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->deviceHandle);
          this->__isset.deviceHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->eventId);
          this->__isset.eventId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->eventDescription);
          this->__isset.eventDescription = true;
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

uint32_t ClientCallback_onDeviceConfigServiceEvent_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDeviceConfigServiceEvent_args");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->serviceName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->deviceHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventId", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64(this->eventId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventDescription", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString(this->eventDescription);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDeviceConfigServiceEvent_pargs::~ClientCallback_onDeviceConfigServiceEvent_pargs() noexcept {
}


uint32_t ClientCallback_onDeviceConfigServiceEvent_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDeviceConfigServiceEvent_pargs");

  xfer += oprot->writeFieldBegin("serviceName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->serviceName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("deviceHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->deviceHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 3);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventId", ::apache::thrift::protocol::T_I64, 4);
  xfer += oprot->writeI64((*(this->eventId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("eventDescription", ::apache::thrift::protocol::T_STRING, 5);
  xfer += oprot->writeString((*(this->eventDescription)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onQShrinkStateUpdated_args::~ClientCallback_onQShrinkStateUpdated_args() noexcept {
}


uint32_t ClientCallback_onQShrinkStateUpdated_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast5;
          xfer += iprot->readI32(ecast5);
          this->newState = ( ::Uts::QShrink4DownloadState::type)ecast5;
          this->__isset.newState = true;
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

uint32_t ClientCallback_onQShrinkStateUpdated_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onQShrinkStateUpdated_args");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newState", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->newState);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onQShrinkStateUpdated_pargs::~ClientCallback_onQShrinkStateUpdated_pargs() noexcept {
}


uint32_t ClientCallback_onQShrinkStateUpdated_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onQShrinkStateUpdated_pargs");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newState", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->newState)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDecryptionKeyStatusUpdate_args::~ClientCallback_onDecryptionKeyStatusUpdate_args() noexcept {
}


uint32_t ClientCallback_onDecryptionKeyStatusUpdate_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->keyInfo.read(iprot);
          this->__isset.keyInfo = true;
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

uint32_t ClientCallback_onDecryptionKeyStatusUpdate_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDecryptionKeyStatusUpdate_args");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("keyInfo", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->keyInfo.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onDecryptionKeyStatusUpdate_pargs::~ClientCallback_onDecryptionKeyStatusUpdate_pargs() noexcept {
}


uint32_t ClientCallback_onDecryptionKeyStatusUpdate_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onDecryptionKeyStatusUpdate_pargs");

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("keyInfo", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += (*(this->keyInfo)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args::~ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args() noexcept {
}


uint32_t ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->logSesssionInstance);
          this->__isset.logSesssionInstance = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->protocolHandle);
          this->__isset.protocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->keyInfo.read(iprot);
          this->__isset.keyInfo = true;
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

uint32_t ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args");

  xfer += oprot->writeFieldBegin("logSesssionInstance", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->logSesssionInstance);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->protocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("keyInfo", ::apache::thrift::protocol::T_STRUCT, 3);
  xfer += this->keyInfo.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ClientCallback_onLogSessionDecryptionKeyStatusUpdate_pargs::~ClientCallback_onLogSessionDecryptionKeyStatusUpdate_pargs() noexcept {
}


uint32_t ClientCallback_onLogSessionDecryptionKeyStatusUpdate_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ClientCallback_onLogSessionDecryptionKeyStatusUpdate_pargs");

  xfer += oprot->writeFieldBegin("logSesssionInstance", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->logSesssionInstance)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("protocolHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->protocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("keyInfo", ::apache::thrift::protocol::T_STRUCT, 3);
  xfer += (*(this->keyInfo)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void ClientCallbackClient::onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description)
{
  send_onMessage(level, location, title, description);
}

void ClientCallbackClient::send_onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onMessage", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onMessage_pargs args;
  args.level = &level;
  args.location = &location;
  args.title = &title;
  args.description = &description;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo)
{
  send_onDeviceConnected(deviceInfo);
}

void ClientCallbackClient::send_onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onDeviceConnected", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDeviceConnected_pargs args;
  args.deviceInfo = &deviceInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo)
{
  send_onDeviceDisconnected(deviceInfo);
}

void ClientCallbackClient::send_onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onDeviceDisconnected", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDeviceDisconnected_pargs args;
  args.deviceInfo = &deviceInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode)
{
  send_onDeviceModeChange(deviceHandle, newMode);
}

void ClientCallbackClient::send_onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onDeviceModeChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDeviceModeChange_pargs args;
  args.deviceHandle = &deviceHandle;
  args.newMode = &newMode;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo)
{
  send_onProtocolAdded(deviceInfo, protocolInfo);
}

void ClientCallbackClient::send_onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onProtocolAdded", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolAdded_pargs args;
  args.deviceInfo = &deviceInfo;
  args.protocolInfo = &protocolInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo)
{
  send_onProtocolRemoved(deviceInfo, protocolInfo);
}

void ClientCallbackClient::send_onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onProtocolRemoved", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolRemoved_pargs args;
  args.deviceInfo = &deviceInfo;
  args.protocolInfo = &protocolInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState)
{
  send_onProtocolStateChange(protocolHandle, newState);
}

void ClientCallbackClient::send_onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onProtocolStateChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolStateChange_pargs args;
  args.protocolHandle = &protocolHandle;
  args.newState = &newState;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus)
{
  send_onProtocolFlowControlStatusChange(protocolHandle, dir, newStatus);
}

void ClientCallbackClient::send_onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onProtocolFlowControlStatusChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolFlowControlStatusChange_pargs args;
  args.protocolHandle = &protocolHandle;
  args.dir = &dir;
  args.newStatus = &newStatus;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus)
{
  send_onProtocolLockStatusChange(protocolHandle, newStatus);
}

void ClientCallbackClient::send_onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onProtocolLockStatusChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolLockStatusChange_pargs args;
  args.protocolHandle = &protocolHandle;
  args.newStatus = &newStatus;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus)
{
  send_onProtocolMbnDownloadStatusChange(protocolHandle, newStatus);
}

void ClientCallbackClient::send_onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onProtocolMbnDownloadStatusChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolMbnDownloadStatusChange_pargs args;
  args.protocolHandle = &protocolHandle;
  args.newStatus = &newStatus;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason)
{
  send_onClientCloseRequest(closeReason);
}

void ClientCallbackClient::send_onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onClientCloseRequest", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onClientCloseRequest_pargs args;
  args.closeReason = &closeReason;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid)
{
  send_onMissingQShrinkHashFile(protocolHandle, missingFileGuid);
}

void ClientCallbackClient::send_onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onMissingQShrinkHashFile", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onMissingQShrinkHashFile_pargs args;
  args.protocolHandle = &protocolHandle;
  args.missingFileGuid = &missingFileGuid;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid)
{
  send_onLogSessionMissingQShrinkHashFile(logSessionInstance, protocolHandle, missingFileGuid);
}

void ClientCallbackClient::send_onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onLogSessionMissingQShrinkHashFile", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onLogSessionMissingQShrinkHashFile_pargs args;
  args.logSessionInstance = &logSessionInstance;
  args.protocolHandle = &protocolHandle;
  args.missingFileGuid = &missingFileGuid;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId)
{
  send_onAsyncResponse(protocolHandle, transactionId);
}

void ClientCallbackClient::send_onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onAsyncResponse", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onAsyncResponse_pargs args;
  args.protocolHandle = &protocolHandle;
  args.transactionId = &transactionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onDataQueueUpdated(const std::string& queueName, const int32_t queueSize)
{
  send_onDataQueueUpdated(queueName, queueSize);
}

void ClientCallbackClient::send_onDataQueueUpdated(const std::string& queueName, const int32_t queueSize)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onDataQueueUpdated", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDataQueueUpdated_pargs args;
  args.queueName = &queueName;
  args.queueSize = &queueSize;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished)
{
  send_onDataViewUpdated(viewName, viewSize, finished);
}

void ClientCallbackClient::send_onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onDataViewUpdated", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDataViewUpdated_pargs args;
  args.viewName = &viewName;
  args.viewSize = &viewSize;
  args.finished = &finished;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle)
{
  send_onServiceAvailable(serviceName, deviceHandle);
}

void ClientCallbackClient::send_onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onServiceAvailable", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onServiceAvailable_pargs args;
  args.serviceName = &serviceName;
  args.deviceHandle = &deviceHandle;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onServiceEnded(const std::string& serviceName, const int64_t deviceHandle)
{
  send_onServiceEnded(serviceName, deviceHandle);
}

void ClientCallbackClient::send_onServiceEnded(const std::string& serviceName, const int64_t deviceHandle)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onServiceEnded", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onServiceEnded_pargs args;
  args.serviceName = &serviceName;
  args.deviceHandle = &deviceHandle;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription)
{
  send_onServiceEvent(serviceName, eventId, eventDescription);
}

void ClientCallbackClient::send_onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onServiceEvent", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onServiceEvent_pargs args;
  args.serviceName = &serviceName;
  args.eventId = &eventId;
  args.eventDescription = &eventDescription;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
{
  send_onImageManagementServiceEvent(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
}

void ClientCallbackClient::send_onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onImageManagementServiceEvent", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onImageManagementServiceEvent_pargs args;
  args.serviceName = &serviceName;
  args.deviceHandle = &deviceHandle;
  args.protocolHandle = &protocolHandle;
  args.eventId = &eventId;
  args.eventDescription = &eventDescription;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
{
  send_onDeviceConfigServiceEvent(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
}

void ClientCallbackClient::send_onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onDeviceConfigServiceEvent", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDeviceConfigServiceEvent_pargs args;
  args.serviceName = &serviceName;
  args.deviceHandle = &deviceHandle;
  args.protocolHandle = &protocolHandle;
  args.eventId = &eventId;
  args.eventDescription = &eventDescription;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState)
{
  send_onQShrinkStateUpdated(protocolHandle, newState);
}

void ClientCallbackClient::send_onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onQShrinkStateUpdated", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onQShrinkStateUpdated_pargs args;
  args.protocolHandle = &protocolHandle;
  args.newState = &newState;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo)
{
  send_onDecryptionKeyStatusUpdate(protocolHandle, keyInfo);
}

void ClientCallbackClient::send_onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onDecryptionKeyStatusUpdate", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDecryptionKeyStatusUpdate_pargs args;
  args.protocolHandle = &protocolHandle;
  args.keyInfo = &keyInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ClientCallbackClient::onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo)
{
  send_onLogSessionDecryptionKeyStatusUpdate(logSesssionInstance, protocolHandle, keyInfo);
}

void ClientCallbackClient::send_onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("onLogSessionDecryptionKeyStatusUpdate", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onLogSessionDecryptionKeyStatusUpdate_pargs args;
  args.logSesssionInstance = &logSesssionInstance;
  args.protocolHandle = &protocolHandle;
  args.keyInfo = &keyInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool ClientCallbackProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

void ClientCallbackProcessor::process_onMessage(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onMessage", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onMessage");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onMessage");
  }

  ClientCallback_onMessage_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onMessage", bytes);
  }

  try {
    iface_->onMessage(args.level, args.location, args.title, args.description);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onMessage");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onMessage");
  }

  return;
}

void ClientCallbackProcessor::process_onDeviceConnected(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onDeviceConnected", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onDeviceConnected");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onDeviceConnected");
  }

  ClientCallback_onDeviceConnected_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onDeviceConnected", bytes);
  }

  try {
    iface_->onDeviceConnected(args.deviceInfo);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onDeviceConnected");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onDeviceConnected");
  }

  return;
}

void ClientCallbackProcessor::process_onDeviceDisconnected(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onDeviceDisconnected", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onDeviceDisconnected");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onDeviceDisconnected");
  }

  ClientCallback_onDeviceDisconnected_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onDeviceDisconnected", bytes);
  }

  try {
    iface_->onDeviceDisconnected(args.deviceInfo);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onDeviceDisconnected");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onDeviceDisconnected");
  }

  return;
}

void ClientCallbackProcessor::process_onDeviceModeChange(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onDeviceModeChange", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onDeviceModeChange");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onDeviceModeChange");
  }

  ClientCallback_onDeviceModeChange_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onDeviceModeChange", bytes);
  }

  try {
    iface_->onDeviceModeChange(args.deviceHandle, args.newMode);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onDeviceModeChange");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onDeviceModeChange");
  }

  return;
}

void ClientCallbackProcessor::process_onProtocolAdded(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onProtocolAdded", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onProtocolAdded");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onProtocolAdded");
  }

  ClientCallback_onProtocolAdded_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onProtocolAdded", bytes);
  }

  try {
    iface_->onProtocolAdded(args.deviceInfo, args.protocolInfo);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onProtocolAdded");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onProtocolAdded");
  }

  return;
}

void ClientCallbackProcessor::process_onProtocolRemoved(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onProtocolRemoved", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onProtocolRemoved");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onProtocolRemoved");
  }

  ClientCallback_onProtocolRemoved_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onProtocolRemoved", bytes);
  }

  try {
    iface_->onProtocolRemoved(args.deviceInfo, args.protocolInfo);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onProtocolRemoved");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onProtocolRemoved");
  }

  return;
}

void ClientCallbackProcessor::process_onProtocolStateChange(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onProtocolStateChange", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onProtocolStateChange");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onProtocolStateChange");
  }

  ClientCallback_onProtocolStateChange_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onProtocolStateChange", bytes);
  }

  try {
    iface_->onProtocolStateChange(args.protocolHandle, args.newState);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onProtocolStateChange");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onProtocolStateChange");
  }

  return;
}

void ClientCallbackProcessor::process_onProtocolFlowControlStatusChange(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onProtocolFlowControlStatusChange", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onProtocolFlowControlStatusChange");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onProtocolFlowControlStatusChange");
  }

  ClientCallback_onProtocolFlowControlStatusChange_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onProtocolFlowControlStatusChange", bytes);
  }

  try {
    iface_->onProtocolFlowControlStatusChange(args.protocolHandle, args.dir, args.newStatus);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onProtocolFlowControlStatusChange");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onProtocolFlowControlStatusChange");
  }

  return;
}

void ClientCallbackProcessor::process_onProtocolLockStatusChange(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onProtocolLockStatusChange", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onProtocolLockStatusChange");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onProtocolLockStatusChange");
  }

  ClientCallback_onProtocolLockStatusChange_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onProtocolLockStatusChange", bytes);
  }

  try {
    iface_->onProtocolLockStatusChange(args.protocolHandle, args.newStatus);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onProtocolLockStatusChange");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onProtocolLockStatusChange");
  }

  return;
}

void ClientCallbackProcessor::process_onProtocolMbnDownloadStatusChange(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onProtocolMbnDownloadStatusChange", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onProtocolMbnDownloadStatusChange");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onProtocolMbnDownloadStatusChange");
  }

  ClientCallback_onProtocolMbnDownloadStatusChange_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onProtocolMbnDownloadStatusChange", bytes);
  }

  try {
    iface_->onProtocolMbnDownloadStatusChange(args.protocolHandle, args.newStatus);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onProtocolMbnDownloadStatusChange");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onProtocolMbnDownloadStatusChange");
  }

  return;
}

void ClientCallbackProcessor::process_onClientCloseRequest(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onClientCloseRequest", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onClientCloseRequest");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onClientCloseRequest");
  }

  ClientCallback_onClientCloseRequest_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onClientCloseRequest", bytes);
  }

  try {
    iface_->onClientCloseRequest(args.closeReason);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onClientCloseRequest");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onClientCloseRequest");
  }

  return;
}

void ClientCallbackProcessor::process_onMissingQShrinkHashFile(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onMissingQShrinkHashFile", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onMissingQShrinkHashFile");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onMissingQShrinkHashFile");
  }

  ClientCallback_onMissingQShrinkHashFile_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onMissingQShrinkHashFile", bytes);
  }

  try {
    iface_->onMissingQShrinkHashFile(args.protocolHandle, args.missingFileGuid);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onMissingQShrinkHashFile");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onMissingQShrinkHashFile");
  }

  return;
}

void ClientCallbackProcessor::process_onLogSessionMissingQShrinkHashFile(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onLogSessionMissingQShrinkHashFile", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onLogSessionMissingQShrinkHashFile");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onLogSessionMissingQShrinkHashFile");
  }

  ClientCallback_onLogSessionMissingQShrinkHashFile_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onLogSessionMissingQShrinkHashFile", bytes);
  }

  try {
    iface_->onLogSessionMissingQShrinkHashFile(args.logSessionInstance, args.protocolHandle, args.missingFileGuid);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onLogSessionMissingQShrinkHashFile");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onLogSessionMissingQShrinkHashFile");
  }

  return;
}

void ClientCallbackProcessor::process_onAsyncResponse(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onAsyncResponse", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onAsyncResponse");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onAsyncResponse");
  }

  ClientCallback_onAsyncResponse_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onAsyncResponse", bytes);
  }

  try {
    iface_->onAsyncResponse(args.protocolHandle, args.transactionId);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onAsyncResponse");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onAsyncResponse");
  }

  return;
}

void ClientCallbackProcessor::process_onDataQueueUpdated(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onDataQueueUpdated", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onDataQueueUpdated");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onDataQueueUpdated");
  }

  ClientCallback_onDataQueueUpdated_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onDataQueueUpdated", bytes);
  }

  try {
    iface_->onDataQueueUpdated(args.queueName, args.queueSize);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onDataQueueUpdated");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onDataQueueUpdated");
  }

  return;
}

void ClientCallbackProcessor::process_onDataViewUpdated(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onDataViewUpdated", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onDataViewUpdated");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onDataViewUpdated");
  }

  ClientCallback_onDataViewUpdated_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onDataViewUpdated", bytes);
  }

  try {
    iface_->onDataViewUpdated(args.viewName, args.viewSize, args.finished);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onDataViewUpdated");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onDataViewUpdated");
  }

  return;
}

void ClientCallbackProcessor::process_onServiceAvailable(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onServiceAvailable", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onServiceAvailable");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onServiceAvailable");
  }

  ClientCallback_onServiceAvailable_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onServiceAvailable", bytes);
  }

  try {
    iface_->onServiceAvailable(args.serviceName, args.deviceHandle);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onServiceAvailable");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onServiceAvailable");
  }

  return;
}

void ClientCallbackProcessor::process_onServiceEnded(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onServiceEnded", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onServiceEnded");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onServiceEnded");
  }

  ClientCallback_onServiceEnded_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onServiceEnded", bytes);
  }

  try {
    iface_->onServiceEnded(args.serviceName, args.deviceHandle);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onServiceEnded");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onServiceEnded");
  }

  return;
}

void ClientCallbackProcessor::process_onServiceEvent(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onServiceEvent", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onServiceEvent");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onServiceEvent");
  }

  ClientCallback_onServiceEvent_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onServiceEvent", bytes);
  }

  try {
    iface_->onServiceEvent(args.serviceName, args.eventId, args.eventDescription);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onServiceEvent");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onServiceEvent");
  }

  return;
}

void ClientCallbackProcessor::process_onImageManagementServiceEvent(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onImageManagementServiceEvent", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onImageManagementServiceEvent");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onImageManagementServiceEvent");
  }

  ClientCallback_onImageManagementServiceEvent_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onImageManagementServiceEvent", bytes);
  }

  try {
    iface_->onImageManagementServiceEvent(args.serviceName, args.deviceHandle, args.protocolHandle, args.eventId, args.eventDescription);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onImageManagementServiceEvent");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onImageManagementServiceEvent");
  }

  return;
}

void ClientCallbackProcessor::process_onDeviceConfigServiceEvent(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onDeviceConfigServiceEvent", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onDeviceConfigServiceEvent");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onDeviceConfigServiceEvent");
  }

  ClientCallback_onDeviceConfigServiceEvent_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onDeviceConfigServiceEvent", bytes);
  }

  try {
    iface_->onDeviceConfigServiceEvent(args.serviceName, args.deviceHandle, args.protocolHandle, args.eventId, args.eventDescription);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onDeviceConfigServiceEvent");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onDeviceConfigServiceEvent");
  }

  return;
}

void ClientCallbackProcessor::process_onQShrinkStateUpdated(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onQShrinkStateUpdated", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onQShrinkStateUpdated");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onQShrinkStateUpdated");
  }

  ClientCallback_onQShrinkStateUpdated_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onQShrinkStateUpdated", bytes);
  }

  try {
    iface_->onQShrinkStateUpdated(args.protocolHandle, args.newState);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onQShrinkStateUpdated");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onQShrinkStateUpdated");
  }

  return;
}

void ClientCallbackProcessor::process_onDecryptionKeyStatusUpdate(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onDecryptionKeyStatusUpdate", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onDecryptionKeyStatusUpdate");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onDecryptionKeyStatusUpdate");
  }

  ClientCallback_onDecryptionKeyStatusUpdate_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onDecryptionKeyStatusUpdate", bytes);
  }

  try {
    iface_->onDecryptionKeyStatusUpdate(args.protocolHandle, args.keyInfo);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onDecryptionKeyStatusUpdate");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onDecryptionKeyStatusUpdate");
  }

  return;
}

void ClientCallbackProcessor::process_onLogSessionDecryptionKeyStatusUpdate(int32_t, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol*, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ClientCallback.onLogSessionDecryptionKeyStatusUpdate", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ClientCallback.onLogSessionDecryptionKeyStatusUpdate");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ClientCallback.onLogSessionDecryptionKeyStatusUpdate");
  }

  ClientCallback_onLogSessionDecryptionKeyStatusUpdate_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ClientCallback.onLogSessionDecryptionKeyStatusUpdate", bytes);
  }

  try {
    iface_->onLogSessionDecryptionKeyStatusUpdate(args.logSesssionInstance, args.protocolHandle, args.keyInfo);
  } catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ClientCallback.onLogSessionDecryptionKeyStatusUpdate");
    }
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->asyncComplete(ctx, "ClientCallback.onLogSessionDecryptionKeyStatusUpdate");
  }

  return;
}

::std::shared_ptr< ::apache::thrift::TProcessor > ClientCallbackProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< ClientCallbackIfFactory > cleanup(handlerFactory_);
  ::std::shared_ptr< ClientCallbackIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::std::shared_ptr< ::apache::thrift::TProcessor > processor(new ClientCallbackProcessor(handler));
  return processor;
}

void ClientCallbackConcurrentClient::onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description)
{
  send_onMessage(level, location, title, description);
}

void ClientCallbackConcurrentClient::send_onMessage(const MessageLevel::type level, const std::string& location, const std::string& title, const std::string& description)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onMessage", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onMessage_pargs args;
  args.level = &level;
  args.location = &location;
  args.title = &title;
  args.description = &description;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo)
{
  send_onDeviceConnected(deviceInfo);
}

void ClientCallbackConcurrentClient::send_onDeviceConnected(const  ::Uts::DeviceInfo& deviceInfo)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onDeviceConnected", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDeviceConnected_pargs args;
  args.deviceInfo = &deviceInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo)
{
  send_onDeviceDisconnected(deviceInfo);
}

void ClientCallbackConcurrentClient::send_onDeviceDisconnected(const  ::Uts::DeviceInfo& deviceInfo)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onDeviceDisconnected", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDeviceDisconnected_pargs args;
  args.deviceInfo = &deviceInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode)
{
  send_onDeviceModeChange(deviceHandle, newMode);
}

void ClientCallbackConcurrentClient::send_onDeviceModeChange(const int64_t deviceHandle, const  ::Uts::DeviceMode::type newMode)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onDeviceModeChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDeviceModeChange_pargs args;
  args.deviceHandle = &deviceHandle;
  args.newMode = &newMode;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo)
{
  send_onProtocolAdded(deviceInfo, protocolInfo);
}

void ClientCallbackConcurrentClient::send_onProtocolAdded(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onProtocolAdded", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolAdded_pargs args;
  args.deviceInfo = &deviceInfo;
  args.protocolInfo = &protocolInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo)
{
  send_onProtocolRemoved(deviceInfo, protocolInfo);
}

void ClientCallbackConcurrentClient::send_onProtocolRemoved(const  ::Uts::DeviceInfo& deviceInfo, const  ::Uts::ProtocolInfo& protocolInfo)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onProtocolRemoved", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolRemoved_pargs args;
  args.deviceInfo = &deviceInfo;
  args.protocolInfo = &protocolInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState)
{
  send_onProtocolStateChange(protocolHandle, newState);
}

void ClientCallbackConcurrentClient::send_onProtocolStateChange(const int64_t protocolHandle, const  ::Uts::ProtocolState::type newState)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onProtocolStateChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolStateChange_pargs args;
  args.protocolHandle = &protocolHandle;
  args.newState = &newState;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus)
{
  send_onProtocolFlowControlStatusChange(protocolHandle, dir, newStatus);
}

void ClientCallbackConcurrentClient::send_onProtocolFlowControlStatusChange(const int64_t protocolHandle, const  ::Uts::Direction::type dir, const  ::Uts::FlowControlStatus::type newStatus)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onProtocolFlowControlStatusChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolFlowControlStatusChange_pargs args;
  args.protocolHandle = &protocolHandle;
  args.dir = &dir;
  args.newStatus = &newStatus;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus)
{
  send_onProtocolLockStatusChange(protocolHandle, newStatus);
}

void ClientCallbackConcurrentClient::send_onProtocolLockStatusChange(const int64_t protocolHandle, const  ::Uts::LockStatus& newStatus)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onProtocolLockStatusChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolLockStatusChange_pargs args;
  args.protocolHandle = &protocolHandle;
  args.newStatus = &newStatus;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus)
{
  send_onProtocolMbnDownloadStatusChange(protocolHandle, newStatus);
}

void ClientCallbackConcurrentClient::send_onProtocolMbnDownloadStatusChange(const int64_t protocolHandle, const  ::Uts::MbnDownloadStatus& newStatus)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onProtocolMbnDownloadStatusChange", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onProtocolMbnDownloadStatusChange_pargs args;
  args.protocolHandle = &protocolHandle;
  args.newStatus = &newStatus;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason)
{
  send_onClientCloseRequest(closeReason);
}

void ClientCallbackConcurrentClient::send_onClientCloseRequest(const  ::Uts::ClientCloseReason& closeReason)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onClientCloseRequest", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onClientCloseRequest_pargs args;
  args.closeReason = &closeReason;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid)
{
  send_onMissingQShrinkHashFile(protocolHandle, missingFileGuid);
}

void ClientCallbackConcurrentClient::send_onMissingQShrinkHashFile(const int64_t protocolHandle, const std::string& missingFileGuid)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onMissingQShrinkHashFile", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onMissingQShrinkHashFile_pargs args;
  args.protocolHandle = &protocolHandle;
  args.missingFileGuid = &missingFileGuid;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid)
{
  send_onLogSessionMissingQShrinkHashFile(logSessionInstance, protocolHandle, missingFileGuid);
}

void ClientCallbackConcurrentClient::send_onLogSessionMissingQShrinkHashFile(const std::string& logSessionInstance, const int64_t protocolHandle, const std::string& missingFileGuid)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onLogSessionMissingQShrinkHashFile", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onLogSessionMissingQShrinkHashFile_pargs args;
  args.logSessionInstance = &logSessionInstance;
  args.protocolHandle = &protocolHandle;
  args.missingFileGuid = &missingFileGuid;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId)
{
  send_onAsyncResponse(protocolHandle, transactionId);
}

void ClientCallbackConcurrentClient::send_onAsyncResponse(const int64_t protocolHandle, const int64_t transactionId)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onAsyncResponse", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onAsyncResponse_pargs args;
  args.protocolHandle = &protocolHandle;
  args.transactionId = &transactionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onDataQueueUpdated(const std::string& queueName, const int32_t queueSize)
{
  send_onDataQueueUpdated(queueName, queueSize);
}

void ClientCallbackConcurrentClient::send_onDataQueueUpdated(const std::string& queueName, const int32_t queueSize)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onDataQueueUpdated", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDataQueueUpdated_pargs args;
  args.queueName = &queueName;
  args.queueSize = &queueSize;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished)
{
  send_onDataViewUpdated(viewName, viewSize, finished);
}

void ClientCallbackConcurrentClient::send_onDataViewUpdated(const std::string& viewName, const int32_t viewSize, const bool finished)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onDataViewUpdated", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDataViewUpdated_pargs args;
  args.viewName = &viewName;
  args.viewSize = &viewSize;
  args.finished = &finished;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle)
{
  send_onServiceAvailable(serviceName, deviceHandle);
}

void ClientCallbackConcurrentClient::send_onServiceAvailable(const std::string& serviceName, const int64_t deviceHandle)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onServiceAvailable", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onServiceAvailable_pargs args;
  args.serviceName = &serviceName;
  args.deviceHandle = &deviceHandle;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onServiceEnded(const std::string& serviceName, const int64_t deviceHandle)
{
  send_onServiceEnded(serviceName, deviceHandle);
}

void ClientCallbackConcurrentClient::send_onServiceEnded(const std::string& serviceName, const int64_t deviceHandle)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onServiceEnded", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onServiceEnded_pargs args;
  args.serviceName = &serviceName;
  args.deviceHandle = &deviceHandle;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription)
{
  send_onServiceEvent(serviceName, eventId, eventDescription);
}

void ClientCallbackConcurrentClient::send_onServiceEvent(const std::string& serviceName, const int64_t eventId, const std::string& eventDescription)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onServiceEvent", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onServiceEvent_pargs args;
  args.serviceName = &serviceName;
  args.eventId = &eventId;
  args.eventDescription = &eventDescription;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
{
  send_onImageManagementServiceEvent(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
}

void ClientCallbackConcurrentClient::send_onImageManagementServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onImageManagementServiceEvent", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onImageManagementServiceEvent_pargs args;
  args.serviceName = &serviceName;
  args.deviceHandle = &deviceHandle;
  args.protocolHandle = &protocolHandle;
  args.eventId = &eventId;
  args.eventDescription = &eventDescription;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
{
  send_onDeviceConfigServiceEvent(serviceName, deviceHandle, protocolHandle, eventId, eventDescription);
}

void ClientCallbackConcurrentClient::send_onDeviceConfigServiceEvent(const std::string& serviceName, const int64_t deviceHandle, const int64_t protocolHandle, const int64_t eventId, const std::string& eventDescription)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onDeviceConfigServiceEvent", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDeviceConfigServiceEvent_pargs args;
  args.serviceName = &serviceName;
  args.deviceHandle = &deviceHandle;
  args.protocolHandle = &protocolHandle;
  args.eventId = &eventId;
  args.eventDescription = &eventDescription;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState)
{
  send_onQShrinkStateUpdated(protocolHandle, newState);
}

void ClientCallbackConcurrentClient::send_onQShrinkStateUpdated(const int64_t protocolHandle, const  ::Uts::QShrink4DownloadState::type newState)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onQShrinkStateUpdated", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onQShrinkStateUpdated_pargs args;
  args.protocolHandle = &protocolHandle;
  args.newState = &newState;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo)
{
  send_onDecryptionKeyStatusUpdate(protocolHandle, keyInfo);
}

void ClientCallbackConcurrentClient::send_onDecryptionKeyStatusUpdate(const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onDecryptionKeyStatusUpdate", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onDecryptionKeyStatusUpdate_pargs args;
  args.protocolHandle = &protocolHandle;
  args.keyInfo = &keyInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

void ClientCallbackConcurrentClient::onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo)
{
  send_onLogSessionDecryptionKeyStatusUpdate(logSesssionInstance, protocolHandle, keyInfo);
}

void ClientCallbackConcurrentClient::send_onLogSessionDecryptionKeyStatusUpdate(const std::string& logSesssionInstance, const int64_t protocolHandle, const  ::Uts::KeyInfo& keyInfo)
{
  int32_t cseqid = 0;
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("onLogSessionDecryptionKeyStatusUpdate", ::apache::thrift::protocol::T_ONEWAY, cseqid);

  ClientCallback_onLogSessionDecryptionKeyStatusUpdate_pargs args;
  args.logSesssionInstance = &logSesssionInstance;
  args.protocolHandle = &protocolHandle;
  args.keyInfo = &keyInfo;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
}

} // namespace

