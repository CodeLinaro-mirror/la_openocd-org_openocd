/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "UtilityService_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {


NvParserResult::~NvParserResult() noexcept {
}


void NvParserResult::__set_nvId(const int32_t val) {
  this->nvId = val;
}

void NvParserResult::__set_data(const  ::Uts::NvData& val) {
  this->data = val;
__isset.data = true;
}
std::ostream& operator<<(std::ostream& out, const NvParserResult& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t NvParserResult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->nvId);
          this->__isset.nvId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->data.read(iprot);
          this->__isset.data = true;
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

uint32_t NvParserResult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("NvParserResult");

  xfer += oprot->writeFieldBegin("nvId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->nvId);
  xfer += oprot->writeFieldEnd();

  if (this->__isset.data) {
    xfer += oprot->writeFieldBegin("data", ::apache::thrift::protocol::T_STRUCT, 2);
    xfer += this->data.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(NvParserResult &a, NvParserResult &b) {
  using ::std::swap;
  swap(a.nvId, b.nvId);
  swap(a.data, b.data);
  swap(a.__isset, b.__isset);
}

NvParserResult::NvParserResult(const NvParserResult& other0) {
  nvId = other0.nvId;
  data = other0.data;
  __isset = other0.__isset;
}
NvParserResult& NvParserResult::operator=(const NvParserResult& other1) {
  nvId = other1.nvId;
  data = other1.data;
  __isset = other1.__isset;
  return *this;
}
void NvParserResult::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "NvParserResult(";
  out << "nvId=" << to_string(nvId);
  out << ", " << "data="; (__isset.data ? (out << to_string(data)) : (out << "<null>"));
  out << ")";
}

} // namespace
