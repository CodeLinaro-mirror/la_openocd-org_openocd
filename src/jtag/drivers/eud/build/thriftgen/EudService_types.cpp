/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "EudService_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {


EudCmdInfo::~EudCmdInfo() noexcept {
}


void EudCmdInfo::__set_opcode(const int32_t val) {
  this->opcode = val;
}

void EudCmdInfo::__set_data(const int32_t val) {
  this->data = val;
}

void EudCmdInfo::__set_payload(const int32_t val) {
  this->payload = val;
}
std::ostream& operator<<(std::ostream& out, const EudCmdInfo& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t EudCmdInfo::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->opcode);
          this->__isset.opcode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->data);
          this->__isset.data = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->payload);
          this->__isset.payload = true;
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

uint32_t EudCmdInfo::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("EudCmdInfo");

  xfer += oprot->writeFieldBegin("opcode", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->opcode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->data);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("payload", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->payload);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(EudCmdInfo &a, EudCmdInfo &b) {
  using ::std::swap;
  swap(a.opcode, b.opcode);
  swap(a.data, b.data);
  swap(a.payload, b.payload);
  swap(a.__isset, b.__isset);
}

EudCmdInfo::EudCmdInfo(const EudCmdInfo& other0) {
  opcode = other0.opcode;
  data = other0.data;
  payload = other0.payload;
  __isset = other0.__isset;
}
EudCmdInfo& EudCmdInfo::operator=(const EudCmdInfo& other1) {
  opcode = other1.opcode;
  data = other1.data;
  payload = other1.payload;
  __isset = other1.__isset;
  return *this;
}
void EudCmdInfo::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "EudCmdInfo(";
  out << "opcode=" << to_string(opcode);
  out << ", " << "data=" << to_string(data);
  out << ", " << "payload=" << to_string(payload);
  out << ")";
}

} // namespace
