/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "ImageManagementService.h"

namespace Uts {


ImageManagementService_getLastError_args::~ImageManagementService_getLastError_args() noexcept {
}


uint32_t ImageManagementService_getLastError_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ImageManagementService_getLastError_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_getLastError_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getLastError_pargs::~ImageManagementService_getLastError_pargs() noexcept {
}


uint32_t ImageManagementService_getLastError_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_getLastError_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getLastError_result::~ImageManagementService_getLastError_result() noexcept {
}


uint32_t ImageManagementService_getLastError_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->success.read(iprot);
          this->__isset.success = true;
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

uint32_t ImageManagementService_getLastError_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_getLastError_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
    xfer += this->success.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getLastError_presult::~ImageManagementService_getLastError_presult() noexcept {
}


uint32_t ImageManagementService_getLastError_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += (*(this->success)).read(iprot);
          this->__isset.success = true;
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


ImageManagementService_initializeService_args::~ImageManagementService_initializeService_args() noexcept {
}


uint32_t ImageManagementService_initializeService_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ImageManagementService_initializeService_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_initializeService_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_initializeService_pargs::~ImageManagementService_initializeService_pargs() noexcept {
}


uint32_t ImageManagementService_initializeService_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_initializeService_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_initializeService_result::~ImageManagementService_initializeService_result() noexcept {
}


uint32_t ImageManagementService_initializeService_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast54;
          xfer += iprot->readI32(ecast54);
          this->success = ( ::Uts::ErrorCode::type)ecast54;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_initializeService_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_initializeService_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_initializeService_presult::~ImageManagementService_initializeService_presult() noexcept {
}


uint32_t ImageManagementService_initializeService_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast55;
          xfer += iprot->readI32(ecast55);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast55;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_destroyService_args::~ImageManagementService_destroyService_args() noexcept {
}


uint32_t ImageManagementService_destroyService_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ImageManagementService_destroyService_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_destroyService_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_destroyService_pargs::~ImageManagementService_destroyService_pargs() noexcept {
}


uint32_t ImageManagementService_destroyService_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_destroyService_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_destroyService_result::~ImageManagementService_destroyService_result() noexcept {
}


uint32_t ImageManagementService_destroyService_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast56;
          xfer += iprot->readI32(ecast56);
          this->success = ( ::Uts::ErrorCode::type)ecast56;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_destroyService_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_destroyService_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_destroyService_presult::~ImageManagementService_destroyService_presult() noexcept {
}


uint32_t ImageManagementService_destroyService_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast57;
          xfer += iprot->readI32(ecast57);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast57;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_getDeviceImageMode_args::~ImageManagementService_getDeviceImageMode_args() noexcept {
}


uint32_t ImageManagementService_getDeviceImageMode_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ImageManagementService_getDeviceImageMode_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_getDeviceImageMode_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getDeviceImageMode_pargs::~ImageManagementService_getDeviceImageMode_pargs() noexcept {
}


uint32_t ImageManagementService_getDeviceImageMode_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_getDeviceImageMode_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getDeviceImageMode_result::~ImageManagementService_getDeviceImageMode_result() noexcept {
}


uint32_t ImageManagementService_getDeviceImageMode_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast58;
          xfer += iprot->readI32(ecast58);
          this->success = (DeviceImageMode::type)ecast58;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_getDeviceImageMode_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_getDeviceImageMode_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getDeviceImageMode_presult::~ImageManagementService_getDeviceImageMode_presult() noexcept {
}


uint32_t ImageManagementService_getDeviceImageMode_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast59;
          xfer += iprot->readI32(ecast59);
          (*(this->success)) = (DeviceImageMode::type)ecast59;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_transferImages_args::~ImageManagementService_transferImages_args() noexcept {
}


uint32_t ImageManagementService_transferImages_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            this->imageList.clear();
            uint32_t _size60;
            ::apache::thrift::protocol::TType _ktype61;
            ::apache::thrift::protocol::TType _vtype62;
            xfer += iprot->readMapBegin(_ktype61, _vtype62, _size60);
            uint32_t _i64;
            for (_i64 = 0; _i64 < _size60; ++_i64)
            {
              int32_t _key65;
              xfer += iprot->readI32(_key65);
              std::string& _val66 = this->imageList[_key65];
              xfer += iprot->readString(_val66);
            }
            xfer += iprot->readMapEnd();
          }
          this->__isset.imageList = true;
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

uint32_t ImageManagementService_transferImages_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_transferImages_args");

  xfer += oprot->writeFieldBegin("imageList", ::apache::thrift::protocol::T_MAP, 1);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>(this->imageList.size()));
    std::map<int32_t, std::string> ::const_iterator _iter67;
    for (_iter67 = this->imageList.begin(); _iter67 != this->imageList.end(); ++_iter67)
    {
      xfer += oprot->writeI32(_iter67->first);
      xfer += oprot->writeString(_iter67->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_transferImages_pargs::~ImageManagementService_transferImages_pargs() noexcept {
}


uint32_t ImageManagementService_transferImages_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_transferImages_pargs");

  xfer += oprot->writeFieldBegin("imageList", ::apache::thrift::protocol::T_MAP, 1);
  {
    xfer += oprot->writeMapBegin(::apache::thrift::protocol::T_I32, ::apache::thrift::protocol::T_STRING, static_cast<uint32_t>((*(this->imageList)).size()));
    std::map<int32_t, std::string> ::const_iterator _iter68;
    for (_iter68 = (*(this->imageList)).begin(); _iter68 != (*(this->imageList)).end(); ++_iter68)
    {
      xfer += oprot->writeI32(_iter68->first);
      xfer += oprot->writeString(_iter68->second);
    }
    xfer += oprot->writeMapEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_transferImages_result::~ImageManagementService_transferImages_result() noexcept {
}


uint32_t ImageManagementService_transferImages_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->success.read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_transferImages_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_transferImages_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
    xfer += this->success.write(oprot);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_transferImages_presult::~ImageManagementService_transferImages_presult() noexcept {
}


uint32_t ImageManagementService_transferImages_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += (*(this->success)).read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_getDeviceInfo_args::~ImageManagementService_getDeviceInfo_args() noexcept {
}


uint32_t ImageManagementService_getDeviceInfo_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ImageManagementService_getDeviceInfo_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_getDeviceInfo_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getDeviceInfo_pargs::~ImageManagementService_getDeviceInfo_pargs() noexcept {
}


uint32_t ImageManagementService_getDeviceInfo_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_getDeviceInfo_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getDeviceInfo_result::~ImageManagementService_getDeviceInfo_result() noexcept {
}


uint32_t ImageManagementService_getDeviceInfo_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->success.read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_getDeviceInfo_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_getDeviceInfo_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
    xfer += this->success.write(oprot);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getDeviceInfo_presult::~ImageManagementService_getDeviceInfo_presult() noexcept {
}


uint32_t ImageManagementService_getDeviceInfo_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += (*(this->success)).read(iprot);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_collectPblDumpV3_args::~ImageManagementService_collectPblDumpV3_args() noexcept {
}


uint32_t ImageManagementService_collectPblDumpV3_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->pathName);
          this->__isset.pathName = true;
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

uint32_t ImageManagementService_collectPblDumpV3_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_collectPblDumpV3_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectPblDumpV3_pargs::~ImageManagementService_collectPblDumpV3_pargs() noexcept {
}


uint32_t ImageManagementService_collectPblDumpV3_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_collectPblDumpV3_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectPblDumpV3_result::~ImageManagementService_collectPblDumpV3_result() noexcept {
}


uint32_t ImageManagementService_collectPblDumpV3_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast69;
          xfer += iprot->readI32(ecast69);
          this->success = ( ::Uts::ErrorCode::type)ecast69;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_collectPblDumpV3_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_collectPblDumpV3_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectPblDumpV3_presult::~ImageManagementService_collectPblDumpV3_presult() noexcept {
}


uint32_t ImageManagementService_collectPblDumpV3_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast70;
          xfer += iprot->readI32(ecast70);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast70;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_downloadBuild_args::~ImageManagementService_downloadBuild_args() noexcept {
}


uint32_t ImageManagementService_downloadBuild_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->buildPath);
          this->__isset.buildPath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->options.read(iprot);
          this->__isset.options = true;
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

uint32_t ImageManagementService_downloadBuild_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_downloadBuild_args");

  xfer += oprot->writeFieldBegin("buildPath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->buildPath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += this->options.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_downloadBuild_pargs::~ImageManagementService_downloadBuild_pargs() noexcept {
}


uint32_t ImageManagementService_downloadBuild_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_downloadBuild_pargs");

  xfer += oprot->writeFieldBegin("buildPath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->buildPath)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 2);
  xfer += (*(this->options)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_downloadBuild_result::~ImageManagementService_downloadBuild_result() noexcept {
}


uint32_t ImageManagementService_downloadBuild_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast71;
          xfer += iprot->readI32(ecast71);
          this->success = ( ::Uts::ErrorCode::type)ecast71;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_downloadBuild_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_downloadBuild_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_downloadBuild_presult::~ImageManagementService_downloadBuild_presult() noexcept {
}


uint32_t ImageManagementService_downloadBuild_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast72;
          xfer += iprot->readI32(ecast72);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast72;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_collectMemoryDump_args::~ImageManagementService_collectMemoryDump_args() noexcept {
}


uint32_t ImageManagementService_collectMemoryDump_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->pathName);
          this->__isset.pathName = true;
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

uint32_t ImageManagementService_collectMemoryDump_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_collectMemoryDump_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectMemoryDump_pargs::~ImageManagementService_collectMemoryDump_pargs() noexcept {
}


uint32_t ImageManagementService_collectMemoryDump_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_collectMemoryDump_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectMemoryDump_result::~ImageManagementService_collectMemoryDump_result() noexcept {
}


uint32_t ImageManagementService_collectMemoryDump_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast73;
          xfer += iprot->readI32(ecast73);
          this->success = ( ::Uts::ErrorCode::type)ecast73;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_collectMemoryDump_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_collectMemoryDump_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectMemoryDump_presult::~ImageManagementService_collectMemoryDump_presult() noexcept {
}


uint32_t ImageManagementService_collectMemoryDump_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast74;
          xfer += iprot->readI32(ecast74);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast74;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_collectMemoryDumpWithOptions_args::~ImageManagementService_collectMemoryDumpWithOptions_args() noexcept {
}


uint32_t ImageManagementService_collectMemoryDumpWithOptions_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->options.read(iprot);
          this->__isset.options = true;
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

uint32_t ImageManagementService_collectMemoryDumpWithOptions_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_collectMemoryDumpWithOptions_args");

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->options.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectMemoryDumpWithOptions_pargs::~ImageManagementService_collectMemoryDumpWithOptions_pargs() noexcept {
}


uint32_t ImageManagementService_collectMemoryDumpWithOptions_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_collectMemoryDumpWithOptions_pargs");

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->options)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectMemoryDumpWithOptions_result::~ImageManagementService_collectMemoryDumpWithOptions_result() noexcept {
}


uint32_t ImageManagementService_collectMemoryDumpWithOptions_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast75;
          xfer += iprot->readI32(ecast75);
          this->success = ( ::Uts::ErrorCode::type)ecast75;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_collectMemoryDumpWithOptions_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_collectMemoryDumpWithOptions_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_collectMemoryDumpWithOptions_presult::~ImageManagementService_collectMemoryDumpWithOptions_presult() noexcept {
}


uint32_t ImageManagementService_collectMemoryDumpWithOptions_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast76;
          xfer += iprot->readI32(ecast76);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast76;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_startRemoteEfsSync_args::~ImageManagementService_startRemoteEfsSync_args() noexcept {
}


uint32_t ImageManagementService_startRemoteEfsSync_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->pathName);
          this->__isset.pathName = true;
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

uint32_t ImageManagementService_startRemoteEfsSync_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_startRemoteEfsSync_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_startRemoteEfsSync_pargs::~ImageManagementService_startRemoteEfsSync_pargs() noexcept {
}


uint32_t ImageManagementService_startRemoteEfsSync_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_startRemoteEfsSync_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_startRemoteEfsSync_result::~ImageManagementService_startRemoteEfsSync_result() noexcept {
}


uint32_t ImageManagementService_startRemoteEfsSync_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast77;
          xfer += iprot->readI32(ecast77);
          this->success = ( ::Uts::ErrorCode::type)ecast77;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_startRemoteEfsSync_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_startRemoteEfsSync_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_startRemoteEfsSync_presult::~ImageManagementService_startRemoteEfsSync_presult() noexcept {
}


uint32_t ImageManagementService_startRemoteEfsSync_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast78;
          xfer += iprot->readI32(ecast78);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast78;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_stopRemoteEfsSync_args::~ImageManagementService_stopRemoteEfsSync_args() noexcept {
}


uint32_t ImageManagementService_stopRemoteEfsSync_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ImageManagementService_stopRemoteEfsSync_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_stopRemoteEfsSync_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_stopRemoteEfsSync_pargs::~ImageManagementService_stopRemoteEfsSync_pargs() noexcept {
}


uint32_t ImageManagementService_stopRemoteEfsSync_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_stopRemoteEfsSync_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_stopRemoteEfsSync_result::~ImageManagementService_stopRemoteEfsSync_result() noexcept {
}


uint32_t ImageManagementService_stopRemoteEfsSync_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast79;
          xfer += iprot->readI32(ecast79);
          this->success = ( ::Uts::ErrorCode::type)ecast79;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_stopRemoteEfsSync_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_stopRemoteEfsSync_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_stopRemoteEfsSync_presult::~ImageManagementService_stopRemoteEfsSync_presult() noexcept {
}


uint32_t ImageManagementService_stopRemoteEfsSync_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast80;
          xfer += iprot->readI32(ecast80);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast80;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_setDdrStorePath_args::~ImageManagementService_setDdrStorePath_args() noexcept {
}


uint32_t ImageManagementService_setDdrStorePath_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->ddrStorePath);
          this->__isset.ddrStorePath = true;
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

uint32_t ImageManagementService_setDdrStorePath_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_setDdrStorePath_args");

  xfer += oprot->writeFieldBegin("ddrStorePath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->ddrStorePath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_setDdrStorePath_pargs::~ImageManagementService_setDdrStorePath_pargs() noexcept {
}


uint32_t ImageManagementService_setDdrStorePath_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_setDdrStorePath_pargs");

  xfer += oprot->writeFieldBegin("ddrStorePath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->ddrStorePath)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_setDdrStorePath_result::~ImageManagementService_setDdrStorePath_result() noexcept {
}


uint32_t ImageManagementService_setDdrStorePath_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast81;
          xfer += iprot->readI32(ecast81);
          this->success = ( ::Uts::ErrorCode::type)ecast81;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_setDdrStorePath_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_setDdrStorePath_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_setDdrStorePath_presult::~ImageManagementService_setDdrStorePath_presult() noexcept {
}


uint32_t ImageManagementService_setDdrStorePath_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast82;
          xfer += iprot->readI32(ecast82);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast82;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_resetDevice_args::~ImageManagementService_resetDevice_args() noexcept {
}


uint32_t ImageManagementService_resetDevice_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->timeout);
          this->__isset.timeout = true;
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

uint32_t ImageManagementService_resetDevice_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_resetDevice_args");

  xfer += oprot->writeFieldBegin("timeout", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->timeout);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_resetDevice_pargs::~ImageManagementService_resetDevice_pargs() noexcept {
}


uint32_t ImageManagementService_resetDevice_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_resetDevice_pargs");

  xfer += oprot->writeFieldBegin("timeout", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->timeout)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_resetDevice_result::~ImageManagementService_resetDevice_result() noexcept {
}


uint32_t ImageManagementService_resetDevice_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast83;
          xfer += iprot->readI32(ecast83);
          this->success = ( ::Uts::ErrorCode::type)ecast83;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_resetDevice_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_resetDevice_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_resetDevice_presult::~ImageManagementService_resetDevice_presult() noexcept {
}


uint32_t ImageManagementService_resetDevice_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast84;
          xfer += iprot->readI32(ecast84);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast84;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_switchToEdl_args::~ImageManagementService_switchToEdl_args() noexcept {
}


uint32_t ImageManagementService_switchToEdl_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
    xfer += iprot->skip(ftype);
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t ImageManagementService_switchToEdl_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_switchToEdl_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_switchToEdl_pargs::~ImageManagementService_switchToEdl_pargs() noexcept {
}


uint32_t ImageManagementService_switchToEdl_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_switchToEdl_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_switchToEdl_result::~ImageManagementService_switchToEdl_result() noexcept {
}


uint32_t ImageManagementService_switchToEdl_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast85;
          xfer += iprot->readI32(ecast85);
          this->success = ( ::Uts::ErrorCode::type)ecast85;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_switchToEdl_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_switchToEdl_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_switchToEdl_presult::~ImageManagementService_switchToEdl_presult() noexcept {
}


uint32_t ImageManagementService_switchToEdl_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast86;
          xfer += iprot->readI32(ecast86);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast86;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_erasePartition_args::~ImageManagementService_erasePartition_args() noexcept {
}


uint32_t ImageManagementService_erasePartition_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->options.read(iprot);
          this->__isset.options = true;
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

uint32_t ImageManagementService_erasePartition_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_erasePartition_args");

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->options.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_erasePartition_pargs::~ImageManagementService_erasePartition_pargs() noexcept {
}


uint32_t ImageManagementService_erasePartition_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_erasePartition_pargs");

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->options)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_erasePartition_result::~ImageManagementService_erasePartition_result() noexcept {
}


uint32_t ImageManagementService_erasePartition_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast87;
          xfer += iprot->readI32(ecast87);
          this->success = ( ::Uts::ErrorCode::type)ecast87;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_erasePartition_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_erasePartition_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_erasePartition_presult::~ImageManagementService_erasePartition_presult() noexcept {
}


uint32_t ImageManagementService_erasePartition_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast88;
          xfer += iprot->readI32(ecast88);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast88;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_getFlashInfo_args::~ImageManagementService_getFlashInfo_args() noexcept {
}


uint32_t ImageManagementService_getFlashInfo_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->options.read(iprot);
          this->__isset.options = true;
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

uint32_t ImageManagementService_getFlashInfo_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_getFlashInfo_args");

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->options.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getFlashInfo_pargs::~ImageManagementService_getFlashInfo_pargs() noexcept {
}


uint32_t ImageManagementService_getFlashInfo_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_getFlashInfo_pargs");

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->options)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getFlashInfo_result::~ImageManagementService_getFlashInfo_result() noexcept {
}


uint32_t ImageManagementService_getFlashInfo_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->success.clear();
            uint32_t _size89;
            ::apache::thrift::protocol::TType _etype92;
            xfer += iprot->readListBegin(_etype92, _size89);
            this->success.resize(_size89);
            uint32_t _i93;
            for (_i93 = 0; _i93 < _size89; ++_i93)
            {
              xfer += this->success[_i93].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_getFlashInfo_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_getFlashInfo_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector<FlashInfo> ::const_iterator _iter94;
      for (_iter94 = this->success.begin(); _iter94 != this->success.end(); ++_iter94)
      {
        xfer += (*_iter94).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_getFlashInfo_presult::~ImageManagementService_getFlashInfo_presult() noexcept {
}


uint32_t ImageManagementService_getFlashInfo_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            (*(this->success)).clear();
            uint32_t _size95;
            ::apache::thrift::protocol::TType _etype98;
            xfer += iprot->readListBegin(_etype98, _size95);
            (*(this->success)).resize(_size95);
            uint32_t _i99;
            for (_i99 = 0; _i99 < _size95; ++_i99)
            {
              xfer += (*(this->success))[_i99].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_initPartitionTable_args::~ImageManagementService_initPartitionTable_args() noexcept {
}


uint32_t ImageManagementService_initPartitionTable_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->options.read(iprot);
          this->__isset.options = true;
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

uint32_t ImageManagementService_initPartitionTable_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_initPartitionTable_args");

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->options.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_initPartitionTable_pargs::~ImageManagementService_initPartitionTable_pargs() noexcept {
}


uint32_t ImageManagementService_initPartitionTable_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_initPartitionTable_pargs");

  xfer += oprot->writeFieldBegin("options", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->options)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_initPartitionTable_result::~ImageManagementService_initPartitionTable_result() noexcept {
}


uint32_t ImageManagementService_initPartitionTable_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            this->success.clear();
            uint32_t _size100;
            ::apache::thrift::protocol::TType _etype103;
            xfer += iprot->readListBegin(_etype103, _size100);
            this->success.resize(_size100);
            uint32_t _i104;
            for (_i104 = 0; _i104 < _size100; ++_i104)
            {
              xfer += this->success[_i104].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_initPartitionTable_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_initPartitionTable_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector<PartitionInfo> ::const_iterator _iter105;
      for (_iter105 = this->success.begin(); _iter105 != this->success.end(); ++_iter105)
      {
        xfer += (*_iter105).write(oprot);
      }
      xfer += oprot->writeListEnd();
    }
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_initPartitionTable_presult::~ImageManagementService_initPartitionTable_presult() noexcept {
}


uint32_t ImageManagementService_initPartitionTable_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_LIST) {
          {
            (*(this->success)).clear();
            uint32_t _size106;
            ::apache::thrift::protocol::TType _etype109;
            xfer += iprot->readListBegin(_etype109, _size106);
            (*(this->success)).resize(_size106);
            uint32_t _i110;
            for (_i110 = 0; _i110 < _size106; ++_i110)
            {
              xfer += (*(this->success))[_i110].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_readPartitionData_args::~ImageManagementService_readPartitionData_args() noexcept {
}


uint32_t ImageManagementService_readPartitionData_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            this->dataChunks.clear();
            uint32_t _size111;
            ::apache::thrift::protocol::TType _etype114;
            xfer += iprot->readListBegin(_etype114, _size111);
            this->dataChunks.resize(_size111);
            uint32_t _i115;
            for (_i115 = 0; _i115 < _size111; ++_i115)
            {
              xfer += this->dataChunks[_i115].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.dataChunks = true;
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

uint32_t ImageManagementService_readPartitionData_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_readPartitionData_args");

  xfer += oprot->writeFieldBegin("dataChunks", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->dataChunks.size()));
    std::vector<DataChunkOptions> ::const_iterator _iter116;
    for (_iter116 = this->dataChunks.begin(); _iter116 != this->dataChunks.end(); ++_iter116)
    {
      xfer += (*_iter116).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_readPartitionData_pargs::~ImageManagementService_readPartitionData_pargs() noexcept {
}


uint32_t ImageManagementService_readPartitionData_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_readPartitionData_pargs");

  xfer += oprot->writeFieldBegin("dataChunks", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>((*(this->dataChunks)).size()));
    std::vector<DataChunkOptions> ::const_iterator _iter117;
    for (_iter117 = (*(this->dataChunks)).begin(); _iter117 != (*(this->dataChunks)).end(); ++_iter117)
    {
      xfer += (*_iter117).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_readPartitionData_result::~ImageManagementService_readPartitionData_result() noexcept {
}


uint32_t ImageManagementService_readPartitionData_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast118;
          xfer += iprot->readI32(ecast118);
          this->success = ( ::Uts::ErrorCode::type)ecast118;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_readPartitionData_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_readPartitionData_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_readPartitionData_presult::~ImageManagementService_readPartitionData_presult() noexcept {
}


uint32_t ImageManagementService_readPartitionData_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast119;
          xfer += iprot->readI32(ecast119);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast119;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_writePartitionData_args::~ImageManagementService_writePartitionData_args() noexcept {
}


uint32_t ImageManagementService_writePartitionData_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            this->dataChunks.clear();
            uint32_t _size120;
            ::apache::thrift::protocol::TType _etype123;
            xfer += iprot->readListBegin(_etype123, _size120);
            this->dataChunks.resize(_size120);
            uint32_t _i124;
            for (_i124 = 0; _i124 < _size120; ++_i124)
            {
              xfer += this->dataChunks[_i124].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.dataChunks = true;
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

uint32_t ImageManagementService_writePartitionData_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_writePartitionData_args");

  xfer += oprot->writeFieldBegin("dataChunks", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->dataChunks.size()));
    std::vector<DataChunkOptions> ::const_iterator _iter125;
    for (_iter125 = this->dataChunks.begin(); _iter125 != this->dataChunks.end(); ++_iter125)
    {
      xfer += (*_iter125).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_writePartitionData_pargs::~ImageManagementService_writePartitionData_pargs() noexcept {
}


uint32_t ImageManagementService_writePartitionData_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_writePartitionData_pargs");

  xfer += oprot->writeFieldBegin("dataChunks", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>((*(this->dataChunks)).size()));
    std::vector<DataChunkOptions> ::const_iterator _iter126;
    for (_iter126 = (*(this->dataChunks)).begin(); _iter126 != (*(this->dataChunks)).end(); ++_iter126)
    {
      xfer += (*_iter126).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_writePartitionData_result::~ImageManagementService_writePartitionData_result() noexcept {
}


uint32_t ImageManagementService_writePartitionData_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast127;
          xfer += iprot->readI32(ecast127);
          this->success = ( ::Uts::ErrorCode::type)ecast127;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_writePartitionData_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_writePartitionData_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_writePartitionData_presult::~ImageManagementService_writePartitionData_presult() noexcept {
}


uint32_t ImageManagementService_writePartitionData_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast128;
          xfer += iprot->readI32(ecast128);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast128;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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


ImageManagementService_erasePartitionData_args::~ImageManagementService_erasePartitionData_args() noexcept {
}


uint32_t ImageManagementService_erasePartitionData_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            this->dataChunks.clear();
            uint32_t _size129;
            ::apache::thrift::protocol::TType _etype132;
            xfer += iprot->readListBegin(_etype132, _size129);
            this->dataChunks.resize(_size129);
            uint32_t _i133;
            for (_i133 = 0; _i133 < _size129; ++_i133)
            {
              xfer += this->dataChunks[_i133].read(iprot);
            }
            xfer += iprot->readListEnd();
          }
          this->__isset.dataChunks = true;
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

uint32_t ImageManagementService_erasePartitionData_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_erasePartitionData_args");

  xfer += oprot->writeFieldBegin("dataChunks", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->dataChunks.size()));
    std::vector<DataChunkOptions> ::const_iterator _iter134;
    for (_iter134 = this->dataChunks.begin(); _iter134 != this->dataChunks.end(); ++_iter134)
    {
      xfer += (*_iter134).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_erasePartitionData_pargs::~ImageManagementService_erasePartitionData_pargs() noexcept {
}


uint32_t ImageManagementService_erasePartitionData_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("ImageManagementService_erasePartitionData_pargs");

  xfer += oprot->writeFieldBegin("dataChunks", ::apache::thrift::protocol::T_LIST, 1);
  {
    xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>((*(this->dataChunks)).size()));
    std::vector<DataChunkOptions> ::const_iterator _iter135;
    for (_iter135 = (*(this->dataChunks)).begin(); _iter135 != (*(this->dataChunks)).end(); ++_iter135)
    {
      xfer += (*_iter135).write(oprot);
    }
    xfer += oprot->writeListEnd();
  }
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_erasePartitionData_result::~ImageManagementService_erasePartitionData_result() noexcept {
}


uint32_t ImageManagementService_erasePartitionData_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast136;
          xfer += iprot->readI32(ecast136);
          this->success = ( ::Uts::ErrorCode::type)ecast136;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

uint32_t ImageManagementService_erasePartitionData_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("ImageManagementService_erasePartitionData_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32((int32_t)this->success);
    xfer += oprot->writeFieldEnd();
  } else if (this->__isset.e) {
    xfer += oprot->writeFieldBegin("e", ::apache::thrift::protocol::T_STRUCT, 1);
    xfer += this->e.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


ImageManagementService_erasePartitionData_presult::~ImageManagementService_erasePartitionData_presult() noexcept {
}


uint32_t ImageManagementService_erasePartitionData_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 0:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast137;
          xfer += iprot->readI32(ecast137);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast137;
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->e.read(iprot);
          this->__isset.e = true;
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

void ImageManagementServiceClient::getLastError( ::Uts::ErrorType& _return)
{
  send_getLastError();
  recv_getLastError(_return);
}

void ImageManagementServiceClient::send_getLastError()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getLastError", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_getLastError_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ImageManagementServiceClient::recv_getLastError( ::Uts::ErrorType& _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("getLastError") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  ImageManagementService_getLastError_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getLastError failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::initializeService()
{
  send_initializeService();
  return recv_initializeService();
}

void ImageManagementServiceClient::send_initializeService()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("initializeService", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_initializeService_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_initializeService()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("initializeService") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_initializeService_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "initializeService failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::destroyService()
{
  send_destroyService();
  return recv_destroyService();
}

void ImageManagementServiceClient::send_destroyService()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("destroyService", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_destroyService_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_destroyService()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("destroyService") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_destroyService_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "destroyService failed: unknown result");
}

DeviceImageMode::type ImageManagementServiceClient::getDeviceImageMode()
{
  send_getDeviceImageMode();
  return recv_getDeviceImageMode();
}

void ImageManagementServiceClient::send_getDeviceImageMode()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getDeviceImageMode", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_getDeviceImageMode_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

DeviceImageMode::type ImageManagementServiceClient::recv_getDeviceImageMode()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("getDeviceImageMode") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceImageMode::type _return;
  ImageManagementService_getDeviceImageMode_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getDeviceImageMode failed: unknown result");
}

void ImageManagementServiceClient::transferImages(TransferImageResult& _return, const std::map<int32_t, std::string> & imageList)
{
  send_transferImages(imageList);
  recv_transferImages(_return);
}

void ImageManagementServiceClient::send_transferImages(const std::map<int32_t, std::string> & imageList)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("transferImages", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_transferImages_pargs args;
  args.imageList = &imageList;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ImageManagementServiceClient::recv_transferImages(TransferImageResult& _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("transferImages") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  ImageManagementService_transferImages_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "transferImages failed: unknown result");
}

void ImageManagementServiceClient::getDeviceInfo(EdlDeviceInfo& _return)
{
  send_getDeviceInfo();
  recv_getDeviceInfo(_return);
}

void ImageManagementServiceClient::send_getDeviceInfo()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getDeviceInfo", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_getDeviceInfo_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ImageManagementServiceClient::recv_getDeviceInfo(EdlDeviceInfo& _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("getDeviceInfo") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  ImageManagementService_getDeviceInfo_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getDeviceInfo failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::collectPblDumpV3(const std::string& pathName)
{
  send_collectPblDumpV3(pathName);
  return recv_collectPblDumpV3();
}

void ImageManagementServiceClient::send_collectPblDumpV3(const std::string& pathName)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("collectPblDumpV3", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_collectPblDumpV3_pargs args;
  args.pathName = &pathName;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_collectPblDumpV3()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("collectPblDumpV3") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_collectPblDumpV3_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "collectPblDumpV3 failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options)
{
  send_downloadBuild(buildPath, options);
  return recv_downloadBuild();
}

void ImageManagementServiceClient::send_downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("downloadBuild", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_downloadBuild_pargs args;
  args.buildPath = &buildPath;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_downloadBuild()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("downloadBuild") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_downloadBuild_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "downloadBuild failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::collectMemoryDump(const std::string& pathName)
{
  send_collectMemoryDump(pathName);
  return recv_collectMemoryDump();
}

void ImageManagementServiceClient::send_collectMemoryDump(const std::string& pathName)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("collectMemoryDump", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_collectMemoryDump_pargs args;
  args.pathName = &pathName;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_collectMemoryDump()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("collectMemoryDump") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_collectMemoryDump_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "collectMemoryDump failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::collectMemoryDumpWithOptions(const MemoryDumpOptions& options)
{
  send_collectMemoryDumpWithOptions(options);
  return recv_collectMemoryDumpWithOptions();
}

void ImageManagementServiceClient::send_collectMemoryDumpWithOptions(const MemoryDumpOptions& options)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("collectMemoryDumpWithOptions", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_collectMemoryDumpWithOptions_pargs args;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_collectMemoryDumpWithOptions()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("collectMemoryDumpWithOptions") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_collectMemoryDumpWithOptions_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "collectMemoryDumpWithOptions failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::startRemoteEfsSync(const std::string& pathName)
{
  send_startRemoteEfsSync(pathName);
  return recv_startRemoteEfsSync();
}

void ImageManagementServiceClient::send_startRemoteEfsSync(const std::string& pathName)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("startRemoteEfsSync", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_startRemoteEfsSync_pargs args;
  args.pathName = &pathName;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_startRemoteEfsSync()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("startRemoteEfsSync") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_startRemoteEfsSync_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "startRemoteEfsSync failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::stopRemoteEfsSync()
{
  send_stopRemoteEfsSync();
  return recv_stopRemoteEfsSync();
}

void ImageManagementServiceClient::send_stopRemoteEfsSync()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("stopRemoteEfsSync", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_stopRemoteEfsSync_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_stopRemoteEfsSync()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("stopRemoteEfsSync") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_stopRemoteEfsSync_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "stopRemoteEfsSync failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::setDdrStorePath(const std::string& ddrStorePath)
{
  send_setDdrStorePath(ddrStorePath);
  return recv_setDdrStorePath();
}

void ImageManagementServiceClient::send_setDdrStorePath(const std::string& ddrStorePath)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("setDdrStorePath", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_setDdrStorePath_pargs args;
  args.ddrStorePath = &ddrStorePath;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_setDdrStorePath()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("setDdrStorePath") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_setDdrStorePath_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "setDdrStorePath failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::resetDevice(const int32_t timeout)
{
  send_resetDevice(timeout);
  return recv_resetDevice();
}

void ImageManagementServiceClient::send_resetDevice(const int32_t timeout)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("resetDevice", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_resetDevice_pargs args;
  args.timeout = &timeout;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_resetDevice()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("resetDevice") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_resetDevice_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "resetDevice failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::switchToEdl()
{
  send_switchToEdl();
  return recv_switchToEdl();
}

void ImageManagementServiceClient::send_switchToEdl()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("switchToEdl", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_switchToEdl_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_switchToEdl()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("switchToEdl") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_switchToEdl_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "switchToEdl failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::erasePartition(const DownloadBuildOptions& options)
{
  send_erasePartition(options);
  return recv_erasePartition();
}

void ImageManagementServiceClient::send_erasePartition(const DownloadBuildOptions& options)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("erasePartition", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_erasePartition_pargs args;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_erasePartition()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("erasePartition") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_erasePartition_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "erasePartition failed: unknown result");
}

void ImageManagementServiceClient::getFlashInfo(std::vector<FlashInfo> & _return, const DownloadBuildOptions& options)
{
  send_getFlashInfo(options);
  recv_getFlashInfo(_return);
}

void ImageManagementServiceClient::send_getFlashInfo(const DownloadBuildOptions& options)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getFlashInfo", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_getFlashInfo_pargs args;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ImageManagementServiceClient::recv_getFlashInfo(std::vector<FlashInfo> & _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("getFlashInfo") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  ImageManagementService_getFlashInfo_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getFlashInfo failed: unknown result");
}

void ImageManagementServiceClient::initPartitionTable(std::vector<PartitionInfo> & _return, const DownloadBuildOptions& options)
{
  send_initPartitionTable(options);
  recv_initPartitionTable(_return);
}

void ImageManagementServiceClient::send_initPartitionTable(const DownloadBuildOptions& options)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("initPartitionTable", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_initPartitionTable_pargs args;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void ImageManagementServiceClient::recv_initPartitionTable(std::vector<PartitionInfo> & _return)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("initPartitionTable") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  ImageManagementService_initPartitionTable_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    // _return pointer has now been filled
    return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "initPartitionTable failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::readPartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  send_readPartitionData(dataChunks);
  return recv_readPartitionData();
}

void ImageManagementServiceClient::send_readPartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("readPartitionData", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_readPartitionData_pargs args;
  args.dataChunks = &dataChunks;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_readPartitionData()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("readPartitionData") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_readPartitionData_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "readPartitionData failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::writePartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  send_writePartitionData(dataChunks);
  return recv_writePartitionData();
}

void ImageManagementServiceClient::send_writePartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("writePartitionData", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_writePartitionData_pargs args;
  args.dataChunks = &dataChunks;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_writePartitionData()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("writePartitionData") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_writePartitionData_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "writePartitionData failed: unknown result");
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::erasePartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  send_erasePartitionData(dataChunks);
  return recv_erasePartitionData();
}

void ImageManagementServiceClient::send_erasePartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("erasePartitionData", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_erasePartitionData_pargs args;
  args.dataChunks = &dataChunks;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type ImageManagementServiceClient::recv_erasePartitionData()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("erasePartitionData") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  ImageManagementService_erasePartitionData_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  if (result.__isset.e) {
    throw result.e;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "erasePartitionData failed: unknown result");
}

bool ImageManagementServiceProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
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

void ImageManagementServiceProcessor::process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.getLastError", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.getLastError");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.getLastError");
  }

  ImageManagementService_getLastError_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.getLastError", bytes);
  }

  ImageManagementService_getLastError_result result;
  try {
    iface_->getLastError(result.success);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.getLastError");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("getLastError", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.getLastError");
  }

  oprot->writeMessageBegin("getLastError", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.getLastError", bytes);
  }
}

void ImageManagementServiceProcessor::process_initializeService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.initializeService", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.initializeService");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.initializeService");
  }

  ImageManagementService_initializeService_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.initializeService", bytes);
  }

  ImageManagementService_initializeService_result result;
  try {
    result.success = iface_->initializeService();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.initializeService");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("initializeService", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.initializeService");
  }

  oprot->writeMessageBegin("initializeService", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.initializeService", bytes);
  }
}

void ImageManagementServiceProcessor::process_destroyService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.destroyService", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.destroyService");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.destroyService");
  }

  ImageManagementService_destroyService_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.destroyService", bytes);
  }

  ImageManagementService_destroyService_result result;
  try {
    result.success = iface_->destroyService();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.destroyService");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("destroyService", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.destroyService");
  }

  oprot->writeMessageBegin("destroyService", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.destroyService", bytes);
  }
}

void ImageManagementServiceProcessor::process_getDeviceImageMode(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.getDeviceImageMode", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.getDeviceImageMode");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.getDeviceImageMode");
  }

  ImageManagementService_getDeviceImageMode_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.getDeviceImageMode", bytes);
  }

  ImageManagementService_getDeviceImageMode_result result;
  try {
    result.success = iface_->getDeviceImageMode();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.getDeviceImageMode");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("getDeviceImageMode", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.getDeviceImageMode");
  }

  oprot->writeMessageBegin("getDeviceImageMode", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.getDeviceImageMode", bytes);
  }
}

void ImageManagementServiceProcessor::process_transferImages(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.transferImages", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.transferImages");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.transferImages");
  }

  ImageManagementService_transferImages_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.transferImages", bytes);
  }

  ImageManagementService_transferImages_result result;
  try {
    iface_->transferImages(result.success, args.imageList);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.transferImages");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("transferImages", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.transferImages");
  }

  oprot->writeMessageBegin("transferImages", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.transferImages", bytes);
  }
}

void ImageManagementServiceProcessor::process_getDeviceInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.getDeviceInfo", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.getDeviceInfo");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.getDeviceInfo");
  }

  ImageManagementService_getDeviceInfo_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.getDeviceInfo", bytes);
  }

  ImageManagementService_getDeviceInfo_result result;
  try {
    iface_->getDeviceInfo(result.success);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.getDeviceInfo");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("getDeviceInfo", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.getDeviceInfo");
  }

  oprot->writeMessageBegin("getDeviceInfo", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.getDeviceInfo", bytes);
  }
}

void ImageManagementServiceProcessor::process_collectPblDumpV3(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.collectPblDumpV3", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.collectPblDumpV3");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.collectPblDumpV3");
  }

  ImageManagementService_collectPblDumpV3_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.collectPblDumpV3", bytes);
  }

  ImageManagementService_collectPblDumpV3_result result;
  try {
    result.success = iface_->collectPblDumpV3(args.pathName);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.collectPblDumpV3");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("collectPblDumpV3", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.collectPblDumpV3");
  }

  oprot->writeMessageBegin("collectPblDumpV3", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.collectPblDumpV3", bytes);
  }
}

void ImageManagementServiceProcessor::process_downloadBuild(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.downloadBuild", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.downloadBuild");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.downloadBuild");
  }

  ImageManagementService_downloadBuild_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.downloadBuild", bytes);
  }

  ImageManagementService_downloadBuild_result result;
  try {
    result.success = iface_->downloadBuild(args.buildPath, args.options);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.downloadBuild");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("downloadBuild", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.downloadBuild");
  }

  oprot->writeMessageBegin("downloadBuild", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.downloadBuild", bytes);
  }
}

void ImageManagementServiceProcessor::process_collectMemoryDump(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.collectMemoryDump", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.collectMemoryDump");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.collectMemoryDump");
  }

  ImageManagementService_collectMemoryDump_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.collectMemoryDump", bytes);
  }

  ImageManagementService_collectMemoryDump_result result;
  try {
    result.success = iface_->collectMemoryDump(args.pathName);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.collectMemoryDump");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("collectMemoryDump", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.collectMemoryDump");
  }

  oprot->writeMessageBegin("collectMemoryDump", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.collectMemoryDump", bytes);
  }
}

void ImageManagementServiceProcessor::process_collectMemoryDumpWithOptions(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.collectMemoryDumpWithOptions", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.collectMemoryDumpWithOptions");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.collectMemoryDumpWithOptions");
  }

  ImageManagementService_collectMemoryDumpWithOptions_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.collectMemoryDumpWithOptions", bytes);
  }

  ImageManagementService_collectMemoryDumpWithOptions_result result;
  try {
    result.success = iface_->collectMemoryDumpWithOptions(args.options);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.collectMemoryDumpWithOptions");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("collectMemoryDumpWithOptions", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.collectMemoryDumpWithOptions");
  }

  oprot->writeMessageBegin("collectMemoryDumpWithOptions", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.collectMemoryDumpWithOptions", bytes);
  }
}

void ImageManagementServiceProcessor::process_startRemoteEfsSync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.startRemoteEfsSync", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.startRemoteEfsSync");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.startRemoteEfsSync");
  }

  ImageManagementService_startRemoteEfsSync_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.startRemoteEfsSync", bytes);
  }

  ImageManagementService_startRemoteEfsSync_result result;
  try {
    result.success = iface_->startRemoteEfsSync(args.pathName);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.startRemoteEfsSync");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("startRemoteEfsSync", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.startRemoteEfsSync");
  }

  oprot->writeMessageBegin("startRemoteEfsSync", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.startRemoteEfsSync", bytes);
  }
}

void ImageManagementServiceProcessor::process_stopRemoteEfsSync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.stopRemoteEfsSync", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.stopRemoteEfsSync");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.stopRemoteEfsSync");
  }

  ImageManagementService_stopRemoteEfsSync_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.stopRemoteEfsSync", bytes);
  }

  ImageManagementService_stopRemoteEfsSync_result result;
  try {
    result.success = iface_->stopRemoteEfsSync();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.stopRemoteEfsSync");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("stopRemoteEfsSync", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.stopRemoteEfsSync");
  }

  oprot->writeMessageBegin("stopRemoteEfsSync", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.stopRemoteEfsSync", bytes);
  }
}

void ImageManagementServiceProcessor::process_setDdrStorePath(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.setDdrStorePath", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.setDdrStorePath");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.setDdrStorePath");
  }

  ImageManagementService_setDdrStorePath_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.setDdrStorePath", bytes);
  }

  ImageManagementService_setDdrStorePath_result result;
  try {
    result.success = iface_->setDdrStorePath(args.ddrStorePath);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.setDdrStorePath");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("setDdrStorePath", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.setDdrStorePath");
  }

  oprot->writeMessageBegin("setDdrStorePath", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.setDdrStorePath", bytes);
  }
}

void ImageManagementServiceProcessor::process_resetDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.resetDevice", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.resetDevice");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.resetDevice");
  }

  ImageManagementService_resetDevice_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.resetDevice", bytes);
  }

  ImageManagementService_resetDevice_result result;
  try {
    result.success = iface_->resetDevice(args.timeout);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.resetDevice");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("resetDevice", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.resetDevice");
  }

  oprot->writeMessageBegin("resetDevice", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.resetDevice", bytes);
  }
}

void ImageManagementServiceProcessor::process_switchToEdl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.switchToEdl", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.switchToEdl");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.switchToEdl");
  }

  ImageManagementService_switchToEdl_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.switchToEdl", bytes);
  }

  ImageManagementService_switchToEdl_result result;
  try {
    result.success = iface_->switchToEdl();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.switchToEdl");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("switchToEdl", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.switchToEdl");
  }

  oprot->writeMessageBegin("switchToEdl", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.switchToEdl", bytes);
  }
}

void ImageManagementServiceProcessor::process_erasePartition(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.erasePartition", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.erasePartition");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.erasePartition");
  }

  ImageManagementService_erasePartition_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.erasePartition", bytes);
  }

  ImageManagementService_erasePartition_result result;
  try {
    result.success = iface_->erasePartition(args.options);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.erasePartition");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("erasePartition", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.erasePartition");
  }

  oprot->writeMessageBegin("erasePartition", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.erasePartition", bytes);
  }
}

void ImageManagementServiceProcessor::process_getFlashInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.getFlashInfo", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.getFlashInfo");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.getFlashInfo");
  }

  ImageManagementService_getFlashInfo_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.getFlashInfo", bytes);
  }

  ImageManagementService_getFlashInfo_result result;
  try {
    iface_->getFlashInfo(result.success, args.options);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.getFlashInfo");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("getFlashInfo", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.getFlashInfo");
  }

  oprot->writeMessageBegin("getFlashInfo", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.getFlashInfo", bytes);
  }
}

void ImageManagementServiceProcessor::process_initPartitionTable(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.initPartitionTable", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.initPartitionTable");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.initPartitionTable");
  }

  ImageManagementService_initPartitionTable_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.initPartitionTable", bytes);
  }

  ImageManagementService_initPartitionTable_result result;
  try {
    iface_->initPartitionTable(result.success, args.options);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.initPartitionTable");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("initPartitionTable", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.initPartitionTable");
  }

  oprot->writeMessageBegin("initPartitionTable", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.initPartitionTable", bytes);
  }
}

void ImageManagementServiceProcessor::process_readPartitionData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.readPartitionData", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.readPartitionData");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.readPartitionData");
  }

  ImageManagementService_readPartitionData_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.readPartitionData", bytes);
  }

  ImageManagementService_readPartitionData_result result;
  try {
    result.success = iface_->readPartitionData(args.dataChunks);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.readPartitionData");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("readPartitionData", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.readPartitionData");
  }

  oprot->writeMessageBegin("readPartitionData", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.readPartitionData", bytes);
  }
}

void ImageManagementServiceProcessor::process_writePartitionData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.writePartitionData", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.writePartitionData");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.writePartitionData");
  }

  ImageManagementService_writePartitionData_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.writePartitionData", bytes);
  }

  ImageManagementService_writePartitionData_result result;
  try {
    result.success = iface_->writePartitionData(args.dataChunks);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.writePartitionData");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("writePartitionData", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.writePartitionData");
  }

  oprot->writeMessageBegin("writePartitionData", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.writePartitionData", bytes);
  }
}

void ImageManagementServiceProcessor::process_erasePartitionData(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("ImageManagementService.erasePartitionData", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "ImageManagementService.erasePartitionData");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "ImageManagementService.erasePartitionData");
  }

  ImageManagementService_erasePartitionData_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "ImageManagementService.erasePartitionData", bytes);
  }

  ImageManagementService_erasePartitionData_result result;
  try {
    result.success = iface_->erasePartitionData(args.dataChunks);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "ImageManagementService.erasePartitionData");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("erasePartitionData", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "ImageManagementService.erasePartitionData");
  }

  oprot->writeMessageBegin("erasePartitionData", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "ImageManagementService.erasePartitionData", bytes);
  }
}

::std::shared_ptr< ::apache::thrift::TProcessor > ImageManagementServiceProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< ImageManagementServiceIfFactory > cleanup(handlerFactory_);
  ::std::shared_ptr< ImageManagementServiceIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::std::shared_ptr< ::apache::thrift::TProcessor > processor(new ImageManagementServiceProcessor(handler));
  return processor;
}

void ImageManagementServiceConcurrentClient::getLastError( ::Uts::ErrorType& _return)
{
  int32_t seqid = send_getLastError();
  recv_getLastError(_return, seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_getLastError()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getLastError", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_getLastError_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void ImageManagementServiceConcurrentClient::recv_getLastError( ::Uts::ErrorType& _return, const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("getLastError") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      ImageManagementService_getLastError_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getLastError failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::initializeService()
{
  int32_t seqid = send_initializeService();
  return recv_initializeService(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_initializeService()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("initializeService", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_initializeService_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_initializeService(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("initializeService") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_initializeService_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "initializeService failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::destroyService()
{
  int32_t seqid = send_destroyService();
  return recv_destroyService(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_destroyService()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("destroyService", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_destroyService_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_destroyService(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("destroyService") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_destroyService_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "destroyService failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

DeviceImageMode::type ImageManagementServiceConcurrentClient::getDeviceImageMode()
{
  int32_t seqid = send_getDeviceImageMode();
  return recv_getDeviceImageMode(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_getDeviceImageMode()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getDeviceImageMode", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_getDeviceImageMode_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

DeviceImageMode::type ImageManagementServiceConcurrentClient::recv_getDeviceImageMode(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("getDeviceImageMode") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceImageMode::type _return;
      ImageManagementService_getDeviceImageMode_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getDeviceImageMode failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void ImageManagementServiceConcurrentClient::transferImages(TransferImageResult& _return, const std::map<int32_t, std::string> & imageList)
{
  int32_t seqid = send_transferImages(imageList);
  recv_transferImages(_return, seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_transferImages(const std::map<int32_t, std::string> & imageList)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("transferImages", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_transferImages_pargs args;
  args.imageList = &imageList;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void ImageManagementServiceConcurrentClient::recv_transferImages(TransferImageResult& _return, const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("transferImages") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      ImageManagementService_transferImages_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "transferImages failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void ImageManagementServiceConcurrentClient::getDeviceInfo(EdlDeviceInfo& _return)
{
  int32_t seqid = send_getDeviceInfo();
  recv_getDeviceInfo(_return, seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_getDeviceInfo()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getDeviceInfo", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_getDeviceInfo_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void ImageManagementServiceConcurrentClient::recv_getDeviceInfo(EdlDeviceInfo& _return, const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("getDeviceInfo") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      ImageManagementService_getDeviceInfo_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getDeviceInfo failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::collectPblDumpV3(const std::string& pathName)
{
  int32_t seqid = send_collectPblDumpV3(pathName);
  return recv_collectPblDumpV3(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_collectPblDumpV3(const std::string& pathName)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("collectPblDumpV3", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_collectPblDumpV3_pargs args;
  args.pathName = &pathName;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_collectPblDumpV3(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("collectPblDumpV3") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_collectPblDumpV3_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "collectPblDumpV3 failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options)
{
  int32_t seqid = send_downloadBuild(buildPath, options);
  return recv_downloadBuild(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_downloadBuild(const std::string& buildPath, const DownloadBuildOptions& options)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("downloadBuild", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_downloadBuild_pargs args;
  args.buildPath = &buildPath;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_downloadBuild(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("downloadBuild") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_downloadBuild_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "downloadBuild failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::collectMemoryDump(const std::string& pathName)
{
  int32_t seqid = send_collectMemoryDump(pathName);
  return recv_collectMemoryDump(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_collectMemoryDump(const std::string& pathName)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("collectMemoryDump", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_collectMemoryDump_pargs args;
  args.pathName = &pathName;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_collectMemoryDump(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("collectMemoryDump") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_collectMemoryDump_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "collectMemoryDump failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::collectMemoryDumpWithOptions(const MemoryDumpOptions& options)
{
  int32_t seqid = send_collectMemoryDumpWithOptions(options);
  return recv_collectMemoryDumpWithOptions(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_collectMemoryDumpWithOptions(const MemoryDumpOptions& options)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("collectMemoryDumpWithOptions", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_collectMemoryDumpWithOptions_pargs args;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_collectMemoryDumpWithOptions(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("collectMemoryDumpWithOptions") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_collectMemoryDumpWithOptions_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "collectMemoryDumpWithOptions failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::startRemoteEfsSync(const std::string& pathName)
{
  int32_t seqid = send_startRemoteEfsSync(pathName);
  return recv_startRemoteEfsSync(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_startRemoteEfsSync(const std::string& pathName)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("startRemoteEfsSync", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_startRemoteEfsSync_pargs args;
  args.pathName = &pathName;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_startRemoteEfsSync(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("startRemoteEfsSync") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_startRemoteEfsSync_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "startRemoteEfsSync failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::stopRemoteEfsSync()
{
  int32_t seqid = send_stopRemoteEfsSync();
  return recv_stopRemoteEfsSync(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_stopRemoteEfsSync()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("stopRemoteEfsSync", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_stopRemoteEfsSync_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_stopRemoteEfsSync(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("stopRemoteEfsSync") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_stopRemoteEfsSync_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "stopRemoteEfsSync failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::setDdrStorePath(const std::string& ddrStorePath)
{
  int32_t seqid = send_setDdrStorePath(ddrStorePath);
  return recv_setDdrStorePath(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_setDdrStorePath(const std::string& ddrStorePath)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("setDdrStorePath", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_setDdrStorePath_pargs args;
  args.ddrStorePath = &ddrStorePath;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_setDdrStorePath(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("setDdrStorePath") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_setDdrStorePath_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "setDdrStorePath failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::resetDevice(const int32_t timeout)
{
  int32_t seqid = send_resetDevice(timeout);
  return recv_resetDevice(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_resetDevice(const int32_t timeout)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("resetDevice", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_resetDevice_pargs args;
  args.timeout = &timeout;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_resetDevice(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("resetDevice") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_resetDevice_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "resetDevice failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::switchToEdl()
{
  int32_t seqid = send_switchToEdl();
  return recv_switchToEdl(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_switchToEdl()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("switchToEdl", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_switchToEdl_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_switchToEdl(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("switchToEdl") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_switchToEdl_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "switchToEdl failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::erasePartition(const DownloadBuildOptions& options)
{
  int32_t seqid = send_erasePartition(options);
  return recv_erasePartition(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_erasePartition(const DownloadBuildOptions& options)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("erasePartition", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_erasePartition_pargs args;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_erasePartition(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("erasePartition") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_erasePartition_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "erasePartition failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void ImageManagementServiceConcurrentClient::getFlashInfo(std::vector<FlashInfo> & _return, const DownloadBuildOptions& options)
{
  int32_t seqid = send_getFlashInfo(options);
  recv_getFlashInfo(_return, seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_getFlashInfo(const DownloadBuildOptions& options)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getFlashInfo", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_getFlashInfo_pargs args;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void ImageManagementServiceConcurrentClient::recv_getFlashInfo(std::vector<FlashInfo> & _return, const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("getFlashInfo") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      ImageManagementService_getFlashInfo_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getFlashInfo failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void ImageManagementServiceConcurrentClient::initPartitionTable(std::vector<PartitionInfo> & _return, const DownloadBuildOptions& options)
{
  int32_t seqid = send_initPartitionTable(options);
  recv_initPartitionTable(_return, seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_initPartitionTable(const DownloadBuildOptions& options)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("initPartitionTable", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_initPartitionTable_pargs args;
  args.options = &options;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void ImageManagementServiceConcurrentClient::recv_initPartitionTable(std::vector<PartitionInfo> & _return, const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("initPartitionTable") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      ImageManagementService_initPartitionTable_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        // _return pointer has now been filled
        sentry.commit();
        return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "initPartitionTable failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::readPartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t seqid = send_readPartitionData(dataChunks);
  return recv_readPartitionData(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_readPartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("readPartitionData", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_readPartitionData_pargs args;
  args.dataChunks = &dataChunks;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_readPartitionData(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("readPartitionData") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_readPartitionData_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "readPartitionData failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::writePartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t seqid = send_writePartitionData(dataChunks);
  return recv_writePartitionData(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_writePartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("writePartitionData", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_writePartitionData_pargs args;
  args.dataChunks = &dataChunks;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_writePartitionData(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("writePartitionData") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_writePartitionData_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "writePartitionData failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::erasePartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t seqid = send_erasePartitionData(dataChunks);
  return recv_erasePartitionData(seqid);
}

int32_t ImageManagementServiceConcurrentClient::send_erasePartitionData(const std::vector<DataChunkOptions> & dataChunks)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("erasePartitionData", ::apache::thrift::protocol::T_CALL, cseqid);

  ImageManagementService_erasePartitionData_pargs args;
  args.dataChunks = &dataChunks;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type ImageManagementServiceConcurrentClient::recv_erasePartitionData(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(this->sync_.get(), seqid);

  while(true) {
    if(!this->sync_->getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("erasePartitionData") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      ImageManagementService_erasePartitionData_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      if (result.__isset.e) {
        sentry.commit();
        throw result.e;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "erasePartitionData failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

} // namespace

