/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "EudSwdService_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {


BfrTckr::~BfrTckr() noexcept {
}


void BfrTckr::__set_bfrVector(const std::vector<int64_t> & val) {
  this->bfrVector = val;
}

void BfrTckr::__set_status(const bool val) {
  this->status = val;
}
std::ostream& operator<<(std::ostream& out, const BfrTckr& obj)
{
  obj.printTo(out);
  return out;
}


uint32_t BfrTckr::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;

  bool isset_status = false;

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
            this->bfrVector.clear();
            uint32_t _size0;
            ::apache::thrift::protocol::TType _etype3;
            xfer += iprot->readListBegin(_etype3, _size0);
            this->bfrVector.resize(_size0);
            uint32_t _i4;
            for (_i4 = 0; _i4 < _size0; ++_i4)
            {
              xfer += iprot->readI64(this->bfrVector[_i4]);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.bfrVector = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->status);
          isset_status = true;
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

  if (!isset_status)
    throw TProtocolException(TProtocolException::INVALID_DATA);
  return xfer;
}

uint32_t BfrTckr::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("BfrTckr");

  xfer += oprot->writeFieldBegin("bfrVector", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_I64, static_cast<uint32_t>(this->bfrVector.size()));
    std::vector<int64_t> ::const_iterator _iter5;
    for (_iter5 = this->bfrVector.begin(); _iter5 != this->bfrVector.end(); ++_iter5)
    {
      xfer += oprot->writeI64((*_iter5));
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("status", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->status);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

void swap(BfrTckr &a, BfrTckr &b) {
  using ::std::swap;
  swap(a.bfrVector, b.bfrVector);
  swap(a.status, b.status);
  swap(a.__isset, b.__isset);
}

BfrTckr::BfrTckr(const BfrTckr& other6) {
  bfrVector = other6.bfrVector;
  status = other6.status;
  __isset = other6.__isset;
}
BfrTckr& BfrTckr::operator=(const BfrTckr& other7) {
  bfrVector = other7.bfrVector;
  status = other7.status;
  __isset = other7.__isset;
  return *this;
}
void BfrTckr::printTo(std::ostream& out) const {
  using ::apache::thrift::to_string;
  out << "BfrTckr(";
  out << "bfrVector=" << to_string(bfrVector);
  out << ", " << "status=" << to_string(status);
  out << ")";
}

} // namespace
