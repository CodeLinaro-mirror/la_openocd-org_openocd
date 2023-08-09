/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "DeviceConfigService.h"

namespace Uts {


DeviceConfigService_getLastError_args::~DeviceConfigService_getLastError_args() noexcept {
}


uint32_t DeviceConfigService_getLastError_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_getLastError_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getLastError_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getLastError_pargs::~DeviceConfigService_getLastError_pargs() noexcept {
}


uint32_t DeviceConfigService_getLastError_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getLastError_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getLastError_result::~DeviceConfigService_getLastError_result() noexcept {
}


uint32_t DeviceConfigService_getLastError_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_getLastError_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_getLastError_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRUCT, 0);
    xfer += this->success.write(oprot);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getLastError_presult::~DeviceConfigService_getLastError_presult() noexcept {
}


uint32_t DeviceConfigService_getLastError_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_getDevice_args::~DeviceConfigService_getDevice_args() noexcept {
}


uint32_t DeviceConfigService_getDevice_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_getDevice_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getDevice_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getDevice_pargs::~DeviceConfigService_getDevice_pargs() noexcept {
}


uint32_t DeviceConfigService_getDevice_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getDevice_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getDevice_result::~DeviceConfigService_getDevice_result() noexcept {
}


uint32_t DeviceConfigService_getDevice_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->success);
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

uint32_t DeviceConfigService_getDevice_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_getDevice_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
    xfer += oprot->writeI64(this->success);
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


DeviceConfigService_getDevice_presult::~DeviceConfigService_getDevice_presult() noexcept {
}


uint32_t DeviceConfigService_getDevice_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64((*(this->success)));
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


DeviceConfigService_initializeService_args::~DeviceConfigService_initializeService_args() noexcept {
}


uint32_t DeviceConfigService_initializeService_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_initializeService_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_initializeService_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_initializeService_pargs::~DeviceConfigService_initializeService_pargs() noexcept {
}


uint32_t DeviceConfigService_initializeService_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_initializeService_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_initializeService_result::~DeviceConfigService_initializeService_result() noexcept {
}


uint32_t DeviceConfigService_initializeService_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast28;
          xfer += iprot->readI32(ecast28);
          this->success = ( ::Uts::ErrorCode::type)ecast28;
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

uint32_t DeviceConfigService_initializeService_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_initializeService_result");

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


DeviceConfigService_initializeService_presult::~DeviceConfigService_initializeService_presult() noexcept {
}


uint32_t DeviceConfigService_initializeService_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast29;
          xfer += iprot->readI32(ecast29);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast29;
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


DeviceConfigService_initializeServiceByProtocol_args::~DeviceConfigService_initializeServiceByProtocol_args() noexcept {
}


uint32_t DeviceConfigService_initializeServiceByProtocol_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI64(this->diagProtocolHandle);
          this->__isset.diagProtocolHandle = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->qmiProtocolHandle);
          this->__isset.qmiProtocolHandle = true;
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

uint32_t DeviceConfigService_initializeServiceByProtocol_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_initializeServiceByProtocol_args");

  xfer += oprot->writeFieldBegin("diagProtocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->diagProtocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("qmiProtocolHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64(this->qmiProtocolHandle);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_initializeServiceByProtocol_pargs::~DeviceConfigService_initializeServiceByProtocol_pargs() noexcept {
}


uint32_t DeviceConfigService_initializeServiceByProtocol_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_initializeServiceByProtocol_pargs");

  xfer += oprot->writeFieldBegin("diagProtocolHandle", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->diagProtocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("qmiProtocolHandle", ::apache::thrift::protocol::T_I64, 2);
  xfer += oprot->writeI64((*(this->qmiProtocolHandle)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_initializeServiceByProtocol_result::~DeviceConfigService_initializeServiceByProtocol_result() noexcept {
}


uint32_t DeviceConfigService_initializeServiceByProtocol_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast30;
          xfer += iprot->readI32(ecast30);
          this->success = ( ::Uts::ErrorCode::type)ecast30;
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

uint32_t DeviceConfigService_initializeServiceByProtocol_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_initializeServiceByProtocol_result");

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


DeviceConfigService_initializeServiceByProtocol_presult::~DeviceConfigService_initializeServiceByProtocol_presult() noexcept {
}


uint32_t DeviceConfigService_initializeServiceByProtocol_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast31;
          xfer += iprot->readI32(ecast31);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast31;
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


DeviceConfigService_initializeServiceWithOptions_args::~DeviceConfigService_initializeServiceWithOptions_args() noexcept {
}


uint32_t DeviceConfigService_initializeServiceWithOptions_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->connectionOptions.read(iprot);
          this->__isset.connectionOptions = true;
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

uint32_t DeviceConfigService_initializeServiceWithOptions_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_initializeServiceWithOptions_args");

  xfer += oprot->writeFieldBegin("connectionOptions", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->connectionOptions.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_initializeServiceWithOptions_pargs::~DeviceConfigService_initializeServiceWithOptions_pargs() noexcept {
}


uint32_t DeviceConfigService_initializeServiceWithOptions_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_initializeServiceWithOptions_pargs");

  xfer += oprot->writeFieldBegin("connectionOptions", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->connectionOptions)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_initializeServiceWithOptions_result::~DeviceConfigService_initializeServiceWithOptions_result() noexcept {
}


uint32_t DeviceConfigService_initializeServiceWithOptions_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast32;
          xfer += iprot->readI32(ecast32);
          this->success = ( ::Uts::ErrorCode::type)ecast32;
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

uint32_t DeviceConfigService_initializeServiceWithOptions_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_initializeServiceWithOptions_result");

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


DeviceConfigService_initializeServiceWithOptions_presult::~DeviceConfigService_initializeServiceWithOptions_presult() noexcept {
}


uint32_t DeviceConfigService_initializeServiceWithOptions_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast33;
          xfer += iprot->readI32(ecast33);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast33;
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


DeviceConfigService_destroyService_args::~DeviceConfigService_destroyService_args() noexcept {
}


uint32_t DeviceConfigService_destroyService_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_destroyService_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_destroyService_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_destroyService_pargs::~DeviceConfigService_destroyService_pargs() noexcept {
}


uint32_t DeviceConfigService_destroyService_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_destroyService_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_destroyService_result::~DeviceConfigService_destroyService_result() noexcept {
}


uint32_t DeviceConfigService_destroyService_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast34;
          xfer += iprot->readI32(ecast34);
          this->success = ( ::Uts::ErrorCode::type)ecast34;
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

uint32_t DeviceConfigService_destroyService_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_destroyService_result");

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


DeviceConfigService_destroyService_presult::~DeviceConfigService_destroyService_presult() noexcept {
}


uint32_t DeviceConfigService_destroyService_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast35;
          xfer += iprot->readI32(ecast35);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast35;
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


DeviceConfigService_doXqcnOperation_args::~DeviceConfigService_doXqcnOperation_args() noexcept {
}


uint32_t DeviceConfigService_doXqcnOperation_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->deviceConfigOptions.read(iprot);
          this->__isset.deviceConfigOptions = true;
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

uint32_t DeviceConfigService_doXqcnOperation_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_doXqcnOperation_args");

  xfer += oprot->writeFieldBegin("deviceConfigOptions", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->deviceConfigOptions.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_doXqcnOperation_pargs::~DeviceConfigService_doXqcnOperation_pargs() noexcept {
}


uint32_t DeviceConfigService_doXqcnOperation_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_doXqcnOperation_pargs");

  xfer += oprot->writeFieldBegin("deviceConfigOptions", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->deviceConfigOptions)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_doXqcnOperation_result::~DeviceConfigService_doXqcnOperation_result() noexcept {
}


uint32_t DeviceConfigService_doXqcnOperation_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_doXqcnOperation_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_doXqcnOperation_result");

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


DeviceConfigService_doXqcnOperation_presult::~DeviceConfigService_doXqcnOperation_presult() noexcept {
}


uint32_t DeviceConfigService_doXqcnOperation_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_backupToXqcn_args::~DeviceConfigService_backupToXqcn_args() noexcept {
}


uint32_t DeviceConfigService_backupToXqcn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->serviceProgrammingCode);
          this->__isset.serviceProgrammingCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->resetUponCompletion);
          this->__isset.resetUponCompletion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->resetTimeout);
          this->__isset.resetTimeout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->filterFileContents);
          this->__isset.filterFileContents = true;
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

uint32_t DeviceConfigService_backupToXqcn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_backupToXqcn_args");

  xfer += oprot->writeFieldBegin("serviceProgrammingCode", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->serviceProgrammingCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetUponCompletion", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool(this->resetUponCompletion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetTimeout", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->resetTimeout);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("filterFileContents", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->filterFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_backupToXqcn_pargs::~DeviceConfigService_backupToXqcn_pargs() noexcept {
}


uint32_t DeviceConfigService_backupToXqcn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_backupToXqcn_pargs");

  xfer += oprot->writeFieldBegin("serviceProgrammingCode", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->serviceProgrammingCode)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetUponCompletion", ::apache::thrift::protocol::T_BOOL, 2);
  xfer += oprot->writeBool((*(this->resetUponCompletion)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetTimeout", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->resetTimeout)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("filterFileContents", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString((*(this->filterFileContents)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_backupToXqcn_result::~DeviceConfigService_backupToXqcn_result() noexcept {
}


uint32_t DeviceConfigService_backupToXqcn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->success);
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

uint32_t DeviceConfigService_backupToXqcn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_backupToXqcn_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeString(this->success);
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


DeviceConfigService_backupToXqcn_presult::~DeviceConfigService_backupToXqcn_presult() noexcept {
}


uint32_t DeviceConfigService_backupToXqcn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString((*(this->success)));
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


DeviceConfigService_restoreFromXqcn_args::~DeviceConfigService_restoreFromXqcn_args() noexcept {
}


uint32_t DeviceConfigService_restoreFromXqcn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->xqcnFileContents);
          this->__isset.xqcnFileContents = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->serviceProgrammingCode);
          this->__isset.serviceProgrammingCode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->allowEsnMismatch);
          this->__isset.allowEsnMismatch = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->resetUponCompletion);
          this->__isset.resetUponCompletion = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->resetTimeout);
          this->__isset.resetTimeout = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 6:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->filterFileContents);
          this->__isset.filterFileContents = true;
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

uint32_t DeviceConfigService_restoreFromXqcn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_restoreFromXqcn_args");

  xfer += oprot->writeFieldBegin("xqcnFileContents", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->xqcnFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("serviceProgrammingCode", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->serviceProgrammingCode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("allowEsnMismatch", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool(this->allowEsnMismatch);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetUponCompletion", ::apache::thrift::protocol::T_BOOL, 4);
  xfer += oprot->writeBool(this->resetUponCompletion);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetTimeout", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->resetTimeout);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("filterFileContents", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString(this->filterFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_restoreFromXqcn_pargs::~DeviceConfigService_restoreFromXqcn_pargs() noexcept {
}


uint32_t DeviceConfigService_restoreFromXqcn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_restoreFromXqcn_pargs");

  xfer += oprot->writeFieldBegin("xqcnFileContents", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->xqcnFileContents)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("serviceProgrammingCode", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString((*(this->serviceProgrammingCode)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("allowEsnMismatch", ::apache::thrift::protocol::T_BOOL, 3);
  xfer += oprot->writeBool((*(this->allowEsnMismatch)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetUponCompletion", ::apache::thrift::protocol::T_BOOL, 4);
  xfer += oprot->writeBool((*(this->resetUponCompletion)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("resetTimeout", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32((*(this->resetTimeout)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("filterFileContents", ::apache::thrift::protocol::T_STRING, 6);
  xfer += oprot->writeString((*(this->filterFileContents)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_restoreFromXqcn_result::~DeviceConfigService_restoreFromXqcn_result() noexcept {
}


uint32_t DeviceConfigService_restoreFromXqcn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast36;
          xfer += iprot->readI32(ecast36);
          this->success = ( ::Uts::ErrorCode::type)ecast36;
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

uint32_t DeviceConfigService_restoreFromXqcn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_restoreFromXqcn_result");

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


DeviceConfigService_restoreFromXqcn_presult::~DeviceConfigService_restoreFromXqcn_presult() noexcept {
}


uint32_t DeviceConfigService_restoreFromXqcn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast37;
          xfer += iprot->readI32(ecast37);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast37;
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


DeviceConfigService_pdcGetMbnMaxStorage_args::~DeviceConfigService_pdcGetMbnMaxStorage_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnMaxStorage_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast38;
          xfer += iprot->readI32(ecast38);
          this->mbnType = (PdcMbnType::type)ecast38;
          this->__isset.mbnType = true;
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

uint32_t DeviceConfigService_pdcGetMbnMaxStorage_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnMaxStorage_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnMaxStorage_pargs::~DeviceConfigService_pdcGetMbnMaxStorage_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnMaxStorage_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnMaxStorage_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnMaxStorage_result::~DeviceConfigService_pdcGetMbnMaxStorage_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnMaxStorage_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->success);
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

uint32_t DeviceConfigService_pdcGetMbnMaxStorage_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnMaxStorage_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
    xfer += oprot->writeI64(this->success);
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


DeviceConfigService_pdcGetMbnMaxStorage_presult::~DeviceConfigService_pdcGetMbnMaxStorage_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnMaxStorage_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64((*(this->success)));
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


DeviceConfigService_pdcGetMbnStorageUsage_args::~DeviceConfigService_pdcGetMbnStorageUsage_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnStorageUsage_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast39;
          xfer += iprot->readI32(ecast39);
          this->mbnType = (PdcMbnType::type)ecast39;
          this->__isset.mbnType = true;
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

uint32_t DeviceConfigService_pdcGetMbnStorageUsage_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnStorageUsage_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnStorageUsage_pargs::~DeviceConfigService_pdcGetMbnStorageUsage_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnStorageUsage_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnStorageUsage_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnStorageUsage_result::~DeviceConfigService_pdcGetMbnStorageUsage_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnStorageUsage_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->success);
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

uint32_t DeviceConfigService_pdcGetMbnStorageUsage_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnStorageUsage_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
    xfer += oprot->writeI64(this->success);
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


DeviceConfigService_pdcGetMbnStorageUsage_presult::~DeviceConfigService_pdcGetMbnStorageUsage_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnStorageUsage_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64((*(this->success)));
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


DeviceConfigService_pdcGetMbnCount_args::~DeviceConfigService_pdcGetMbnCount_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnCount_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast40;
          xfer += iprot->readI32(ecast40);
          this->mbnType = (PdcMbnType::type)ecast40;
          this->__isset.mbnType = true;
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

uint32_t DeviceConfigService_pdcGetMbnCount_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnCount_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnCount_pargs::~DeviceConfigService_pdcGetMbnCount_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnCount_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnCount_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnCount_result::~DeviceConfigService_pdcGetMbnCount_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnCount_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->success);
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

uint32_t DeviceConfigService_pdcGetMbnCount_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnCount_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
    xfer += oprot->writeI64(this->success);
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


DeviceConfigService_pdcGetMbnCount_presult::~DeviceConfigService_pdcGetMbnCount_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnCount_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64((*(this->success)));
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


DeviceConfigService_pdcGetMbnList_args::~DeviceConfigService_pdcGetMbnList_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnList_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast41;
          xfer += iprot->readI32(ecast41);
          this->mbnType = (PdcMbnType::type)ecast41;
          this->__isset.mbnType = true;
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

uint32_t DeviceConfigService_pdcGetMbnList_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnList_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnList_pargs::~DeviceConfigService_pdcGetMbnList_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnList_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnList_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnList_result::~DeviceConfigService_pdcGetMbnList_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnList_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            uint32_t _size42;
            ::apache::thrift::protocol::TType _etype45;
            xfer += iprot->readListBegin(_etype45, _size42);
            this->success.resize(_size42);
            uint32_t _i46;
            for (_i46 = 0; _i46 < _size42; ++_i46)
            {
              xfer += this->success[_i46].read(iprot);
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

uint32_t DeviceConfigService_pdcGetMbnList_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnList_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector<PdcMbnInfo> ::const_iterator _iter47;
      for (_iter47 = this->success.begin(); _iter47 != this->success.end(); ++_iter47)
      {
        xfer += (*_iter47).write(oprot);
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


DeviceConfigService_pdcGetMbnList_presult::~DeviceConfigService_pdcGetMbnList_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnList_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            uint32_t _size48;
            ::apache::thrift::protocol::TType _etype51;
            xfer += iprot->readListBegin(_etype51, _size48);
            (*(this->success)).resize(_size48);
            uint32_t _i52;
            for (_i52 = 0; _i52 < _size48; ++_i52)
            {
              xfer += (*(this->success))[_i52].read(iprot);
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


DeviceConfigService_pdcGetDefaultMbnInfo_args::~DeviceConfigService_pdcGetDefaultMbnInfo_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetDefaultMbnInfo_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast53;
          xfer += iprot->readI32(ecast53);
          this->mbnType = (PdcMbnType::type)ecast53;
          this->__isset.mbnType = true;
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

uint32_t DeviceConfigService_pdcGetDefaultMbnInfo_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetDefaultMbnInfo_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetDefaultMbnInfo_pargs::~DeviceConfigService_pdcGetDefaultMbnInfo_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetDefaultMbnInfo_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetDefaultMbnInfo_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetDefaultMbnInfo_result::~DeviceConfigService_pdcGetDefaultMbnInfo_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetDefaultMbnInfo_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_pdcGetDefaultMbnInfo_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetDefaultMbnInfo_result");

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


DeviceConfigService_pdcGetDefaultMbnInfo_presult::~DeviceConfigService_pdcGetDefaultMbnInfo_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetDefaultMbnInfo_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_pdcGetMbnId_args::~DeviceConfigService_pdcGetMbnId_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnId_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readBinary(this->mbnContent);
          this->__isset.mbnContent = true;
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

uint32_t DeviceConfigService_pdcGetMbnId_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnId_args");

  xfer += oprot->writeFieldBegin("mbnContent", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeBinary(this->mbnContent);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnId_pargs::~DeviceConfigService_pdcGetMbnId_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnId_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnId_pargs");

  xfer += oprot->writeFieldBegin("mbnContent", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeBinary((*(this->mbnContent)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetMbnId_result::~DeviceConfigService_pdcGetMbnId_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnId_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_pdcGetMbnId_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetMbnId_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_pdcGetMbnId_presult::~DeviceConfigService_pdcGetMbnId_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetMbnId_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_pdcWriteMbn_args::~DeviceConfigService_pdcWriteMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcWriteMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast54;
          xfer += iprot->readI32(ecast54);
          this->mbnType = (PdcMbnType::type)ecast54;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->mbnContent);
          this->__isset.mbnContent = true;
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

uint32_t DeviceConfigService_pdcWriteMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcWriteMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnContent", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->mbnContent);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcWriteMbn_pargs::~DeviceConfigService_pdcWriteMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcWriteMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcWriteMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnContent", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary((*(this->mbnContent)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcWriteMbn_result::~DeviceConfigService_pdcWriteMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcWriteMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          this->success = ( ::Uts::ErrorCode::type)ecast55;
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

uint32_t DeviceConfigService_pdcWriteMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcWriteMbn_result");

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


DeviceConfigService_pdcWriteMbn_presult::~DeviceConfigService_pdcWriteMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcWriteMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast56;
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


DeviceConfigService_pdcReadMbn_args::~DeviceConfigService_pdcReadMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcReadMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast57;
          xfer += iprot->readI32(ecast57);
          this->mbnType = (PdcMbnType::type)ecast57;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->mbnId);
          this->__isset.mbnId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subId);
          this->__isset.subId = true;
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

uint32_t DeviceConfigService_pdcReadMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcReadMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->mbnId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->subId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcReadMbn_pargs::~DeviceConfigService_pdcReadMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcReadMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcReadMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary((*(this->mbnId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->subId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcReadMbn_result::~DeviceConfigService_pdcReadMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcReadMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_pdcReadMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcReadMbn_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_pdcReadMbn_presult::~DeviceConfigService_pdcReadMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcReadMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_pdcRemoveMbn_args::~DeviceConfigService_pdcRemoveMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcRemoveMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast58;
          xfer += iprot->readI32(ecast58);
          this->mbnType = (PdcMbnType::type)ecast58;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->mbnId);
          this->__isset.mbnId = true;
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

uint32_t DeviceConfigService_pdcRemoveMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcRemoveMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->mbnId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcRemoveMbn_pargs::~DeviceConfigService_pdcRemoveMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcRemoveMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcRemoveMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary((*(this->mbnId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcRemoveMbn_result::~DeviceConfigService_pdcRemoveMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcRemoveMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          this->success = ( ::Uts::ErrorCode::type)ecast59;
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

uint32_t DeviceConfigService_pdcRemoveMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcRemoveMbn_result");

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


DeviceConfigService_pdcRemoveMbn_presult::~DeviceConfigService_pdcRemoveMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcRemoveMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast60;
          xfer += iprot->readI32(ecast60);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast60;
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


DeviceConfigService_pdcGetActiveMbn_args::~DeviceConfigService_pdcGetActiveMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetActiveMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast61;
          xfer += iprot->readI32(ecast61);
          this->mbnType = (PdcMbnType::type)ecast61;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subId);
          this->__isset.subId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->slotId);
          this->__isset.slotId = true;
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

uint32_t DeviceConfigService_pdcGetActiveMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetActiveMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->slotId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetActiveMbn_pargs::~DeviceConfigService_pdcGetActiveMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetActiveMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetActiveMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->subId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->slotId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetActiveMbn_result::~DeviceConfigService_pdcGetActiveMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetActiveMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_pdcGetActiveMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetActiveMbn_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_pdcGetActiveMbn_presult::~DeviceConfigService_pdcGetActiveMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetActiveMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_pdcGetPendingMbn_args::~DeviceConfigService_pdcGetPendingMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetPendingMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast62;
          xfer += iprot->readI32(ecast62);
          this->mbnType = (PdcMbnType::type)ecast62;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subId);
          this->__isset.subId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->slotId);
          this->__isset.slotId = true;
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

uint32_t DeviceConfigService_pdcGetPendingMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetPendingMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->slotId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetPendingMbn_pargs::~DeviceConfigService_pdcGetPendingMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetPendingMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetPendingMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->subId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->slotId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetPendingMbn_result::~DeviceConfigService_pdcGetPendingMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetPendingMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_pdcGetPendingMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetPendingMbn_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_pdcGetPendingMbn_presult::~DeviceConfigService_pdcGetPendingMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetPendingMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_pdcValidateMbn_args::~DeviceConfigService_pdcValidateMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcValidateMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast63;
          xfer += iprot->readI32(ecast63);
          this->mbnType = (PdcMbnType::type)ecast63;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->mbnId);
          this->__isset.mbnId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subId);
          this->__isset.subId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->remotePath);
          this->__isset.remotePath = true;
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

uint32_t DeviceConfigService_pdcValidateMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcValidateMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->mbnId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->subId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("remotePath", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString(this->remotePath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcValidateMbn_pargs::~DeviceConfigService_pdcValidateMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcValidateMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcValidateMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary((*(this->mbnId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->subId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("remotePath", ::apache::thrift::protocol::T_STRING, 4);
  xfer += oprot->writeString((*(this->remotePath)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcValidateMbn_result::~DeviceConfigService_pdcValidateMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcValidateMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_pdcValidateMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcValidateMbn_result");

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


DeviceConfigService_pdcValidateMbn_presult::~DeviceConfigService_pdcValidateMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcValidateMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_pdcSelectMbn_args::~DeviceConfigService_pdcSelectMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcSelectMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast64;
          xfer += iprot->readI32(ecast64);
          this->mbnType = (PdcMbnType::type)ecast64;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->mbnId);
          this->__isset.mbnId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subId);
          this->__isset.subId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->slotId);
          this->__isset.slotId = true;
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

uint32_t DeviceConfigService_pdcSelectMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcSelectMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->mbnId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->subId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->slotId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcSelectMbn_pargs::~DeviceConfigService_pdcSelectMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcSelectMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcSelectMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mbnId", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary((*(this->mbnId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->subId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32((*(this->slotId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcSelectMbn_result::~DeviceConfigService_pdcSelectMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcSelectMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast65;
          xfer += iprot->readI32(ecast65);
          this->success = ( ::Uts::ErrorCode::type)ecast65;
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

uint32_t DeviceConfigService_pdcSelectMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcSelectMbn_result");

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


DeviceConfigService_pdcSelectMbn_presult::~DeviceConfigService_pdcSelectMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcSelectMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast66;
          xfer += iprot->readI32(ecast66);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast66;
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


DeviceConfigService_pdcActivateMbn_args::~DeviceConfigService_pdcActivateMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcActivateMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast67;
          xfer += iprot->readI32(ecast67);
          this->mbnType = (PdcMbnType::type)ecast67;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subId);
          this->__isset.subId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->slotId);
          this->__isset.slotId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->mode);
          this->__isset.mode = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 5:
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

uint32_t DeviceConfigService_pdcActivateMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcActivateMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->slotId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mode", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32(this->mode);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("timeout", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32(this->timeout);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcActivateMbn_pargs::~DeviceConfigService_pdcActivateMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcActivateMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcActivateMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->subId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->slotId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("mode", ::apache::thrift::protocol::T_I32, 4);
  xfer += oprot->writeI32((*(this->mode)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("timeout", ::apache::thrift::protocol::T_I32, 5);
  xfer += oprot->writeI32((*(this->timeout)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcActivateMbn_result::~DeviceConfigService_pdcActivateMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcActivateMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast68;
          xfer += iprot->readI32(ecast68);
          this->success = ( ::Uts::ErrorCode::type)ecast68;
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

uint32_t DeviceConfigService_pdcActivateMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcActivateMbn_result");

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


DeviceConfigService_pdcActivateMbn_presult::~DeviceConfigService_pdcActivateMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcActivateMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast69;
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


DeviceConfigService_pdcDeactivateMbn_args::~DeviceConfigService_pdcDeactivateMbn_args() noexcept {
}


uint32_t DeviceConfigService_pdcDeactivateMbn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast70;
          xfer += iprot->readI32(ecast70);
          this->mbnType = (PdcMbnType::type)ecast70;
          this->__isset.mbnType = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subId);
          this->__isset.subId = true;
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

uint32_t DeviceConfigService_pdcDeactivateMbn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcDeactivateMbn_args");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->mbnType);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcDeactivateMbn_pargs::~DeviceConfigService_pdcDeactivateMbn_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcDeactivateMbn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcDeactivateMbn_pargs");

  xfer += oprot->writeFieldBegin("mbnType", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->mbnType)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->subId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcDeactivateMbn_result::~DeviceConfigService_pdcDeactivateMbn_result() noexcept {
}


uint32_t DeviceConfigService_pdcDeactivateMbn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_pdcDeactivateMbn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcDeactivateMbn_result");

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


DeviceConfigService_pdcDeactivateMbn_presult::~DeviceConfigService_pdcDeactivateMbn_presult() noexcept {
}


uint32_t DeviceConfigService_pdcDeactivateMbn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_pdcGetConfiguration_args::~DeviceConfigService_pdcGetConfiguration_args() noexcept {
}


uint32_t DeviceConfigService_pdcGetConfiguration_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->slotId);
          this->__isset.slotId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast73;
          xfer += iprot->readI32(ecast73);
          this->feature = (PdcConfigurationType::type)ecast73;
          this->__isset.feature = true;
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

uint32_t DeviceConfigService_pdcGetConfiguration_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetConfiguration_args");

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->slotId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("feature", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->feature);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetConfiguration_pargs::~DeviceConfigService_pdcGetConfiguration_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcGetConfiguration_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetConfiguration_pargs");

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->slotId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("feature", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->feature)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcGetConfiguration_result::~DeviceConfigService_pdcGetConfiguration_result() noexcept {
}


uint32_t DeviceConfigService_pdcGetConfiguration_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->success);
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

uint32_t DeviceConfigService_pdcGetConfiguration_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcGetConfiguration_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32(this->success);
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


DeviceConfigService_pdcGetConfiguration_presult::~DeviceConfigService_pdcGetConfiguration_presult() noexcept {
}


uint32_t DeviceConfigService_pdcGetConfiguration_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32((*(this->success)));
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


DeviceConfigService_pdcSetConfiguration_args::~DeviceConfigService_pdcSetConfiguration_args() noexcept {
}


uint32_t DeviceConfigService_pdcSetConfiguration_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->slotId);
          this->__isset.slotId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast74;
          xfer += iprot->readI32(ecast74);
          this->feature = (PdcConfigurationType::type)ecast74;
          this->__isset.feature = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->value);
          this->__isset.value = true;
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

uint32_t DeviceConfigService_pdcSetConfiguration_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcSetConfiguration_args");

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->slotId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("feature", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->feature);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->value);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcSetConfiguration_pargs::~DeviceConfigService_pdcSetConfiguration_pargs() noexcept {
}


uint32_t DeviceConfigService_pdcSetConfiguration_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_pdcSetConfiguration_pargs");

  xfer += oprot->writeFieldBegin("slotId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->slotId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("feature", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->feature)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("value", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->value)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_pdcSetConfiguration_result::~DeviceConfigService_pdcSetConfiguration_result() noexcept {
}


uint32_t DeviceConfigService_pdcSetConfiguration_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_pdcSetConfiguration_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_pdcSetConfiguration_result");

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


DeviceConfigService_pdcSetConfiguration_presult::~DeviceConfigService_pdcSetConfiguration_presult() noexcept {
}


uint32_t DeviceConfigService_pdcSetConfiguration_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_nvIsItemSupported_args::~DeviceConfigService_nvIsItemSupported_args() noexcept {
}


uint32_t DeviceConfigService_nvIsItemSupported_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->nvItemNameOrId);
          this->__isset.nvItemNameOrId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
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

uint32_t DeviceConfigService_nvIsItemSupported_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvIsItemSupported_args");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->nvItemNameOrId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvIsItemSupported_pargs::~DeviceConfigService_nvIsItemSupported_pargs() noexcept {
}


uint32_t DeviceConfigService_nvIsItemSupported_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvIsItemSupported_pargs");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->nvItemNameOrId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvIsItemSupported_result::~DeviceConfigService_nvIsItemSupported_result() noexcept {
}


uint32_t DeviceConfigService_nvIsItemSupported_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
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

uint32_t DeviceConfigService_nvIsItemSupported_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_nvIsItemSupported_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
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


DeviceConfigService_nvIsItemSupported_presult::~DeviceConfigService_nvIsItemSupported_presult() noexcept {
}


uint32_t DeviceConfigService_nvIsItemSupported_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
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


DeviceConfigService_nvReadItem_args::~DeviceConfigService_nvReadItem_args() noexcept {
}


uint32_t DeviceConfigService_nvReadItem_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->nvItemNameOrId);
          this->__isset.nvItemNameOrId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->index);
          this->__isset.index = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 4:
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

uint32_t DeviceConfigService_nvReadItem_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvReadItem_args");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->nvItemNameOrId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_BYTE, 3);
  xfer += oprot->writeByte(this->index);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("returnConfig", ::apache::thrift::protocol::T_STRUCT, 4);
  xfer += this->returnConfig.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvReadItem_pargs::~DeviceConfigService_nvReadItem_pargs() noexcept {
}


uint32_t DeviceConfigService_nvReadItem_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvReadItem_pargs");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->nvItemNameOrId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_BYTE, 3);
  xfer += oprot->writeByte((*(this->index)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("returnConfig", ::apache::thrift::protocol::T_STRUCT, 4);
  xfer += (*(this->returnConfig)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvReadItem_result::~DeviceConfigService_nvReadItem_result() noexcept {
}


uint32_t DeviceConfigService_nvReadItem_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_nvReadItem_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_nvReadItem_result");

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


DeviceConfigService_nvReadItem_presult::~DeviceConfigService_nvReadItem_presult() noexcept {
}


uint32_t DeviceConfigService_nvReadItem_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_nvSetItem_args::~DeviceConfigService_nvSetItem_args() noexcept {
}


uint32_t DeviceConfigService_nvSetItem_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->nvItemNameOrId);
          this->__isset.nvItemNameOrId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->valueList);
          this->__isset.valueList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
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

uint32_t DeviceConfigService_nvSetItem_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvSetItem_args");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->nvItemNameOrId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("valueList", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->valueList);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvSetItem_pargs::~DeviceConfigService_nvSetItem_pargs() noexcept {
}


uint32_t DeviceConfigService_nvSetItem_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvSetItem_pargs");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->nvItemNameOrId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("valueList", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString((*(this->valueList)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvSetItem_result::~DeviceConfigService_nvSetItem_result() noexcept {
}


uint32_t DeviceConfigService_nvSetItem_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_nvSetItem_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_nvSetItem_result");

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


DeviceConfigService_nvSetItem_presult::~DeviceConfigService_nvSetItem_presult() noexcept {
}


uint32_t DeviceConfigService_nvSetItem_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_nvSetOtpItem_args::~DeviceConfigService_nvSetOtpItem_args() noexcept {
}


uint32_t DeviceConfigService_nvSetOtpItem_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->nvItemNameOrId);
          this->__isset.nvItemNameOrId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->valueList);
          this->__isset.valueList = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
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

uint32_t DeviceConfigService_nvSetOtpItem_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvSetOtpItem_args");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->nvItemNameOrId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("valueList", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->valueList);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvSetOtpItem_pargs::~DeviceConfigService_nvSetOtpItem_pargs() noexcept {
}


uint32_t DeviceConfigService_nvSetOtpItem_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvSetOtpItem_pargs");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->nvItemNameOrId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("valueList", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString((*(this->valueList)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvSetOtpItem_result::~DeviceConfigService_nvSetOtpItem_result() noexcept {
}


uint32_t DeviceConfigService_nvSetOtpItem_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_nvSetOtpItem_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_nvSetOtpItem_result");

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


DeviceConfigService_nvSetOtpItem_presult::~DeviceConfigService_nvSetOtpItem_presult() noexcept {
}


uint32_t DeviceConfigService_nvSetOtpItem_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_nvGetAllItems_args::~DeviceConfigService_nvGetAllItems_args() noexcept {
}


uint32_t DeviceConfigService_nvGetAllItems_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_nvGetAllItems_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvGetAllItems_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvGetAllItems_pargs::~DeviceConfigService_nvGetAllItems_pargs() noexcept {
}


uint32_t DeviceConfigService_nvGetAllItems_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvGetAllItems_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvGetAllItems_result::~DeviceConfigService_nvGetAllItems_result() noexcept {
}


uint32_t DeviceConfigService_nvGetAllItems_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            uint32_t _size81;
            ::apache::thrift::protocol::TType _etype84;
            xfer += iprot->readListBegin(_etype84, _size81);
            this->success.resize(_size81);
            uint32_t _i85;
            for (_i85 = 0; _i85 < _size81; ++_i85)
            {
              xfer += this->success[_i85].read(iprot);
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

uint32_t DeviceConfigService_nvGetAllItems_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_nvGetAllItems_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector< ::Uts::NvItem> ::const_iterator _iter86;
      for (_iter86 = this->success.begin(); _iter86 != this->success.end(); ++_iter86)
      {
        xfer += (*_iter86).write(oprot);
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


DeviceConfigService_nvGetAllItems_presult::~DeviceConfigService_nvGetAllItems_presult() noexcept {
}


uint32_t DeviceConfigService_nvGetAllItems_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            uint32_t _size87;
            ::apache::thrift::protocol::TType _etype90;
            xfer += iprot->readListBegin(_etype90, _size87);
            (*(this->success)).resize(_size87);
            uint32_t _i91;
            for (_i91 = 0; _i91 < _size87; ++_i91)
            {
              xfer += (*(this->success))[_i91].read(iprot);
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


DeviceConfigService_nvGetItemDefinition_args::~DeviceConfigService_nvGetItemDefinition_args() noexcept {
}


uint32_t DeviceConfigService_nvGetItemDefinition_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->nvItemNameOrId);
          this->__isset.nvItemNameOrId = true;
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

uint32_t DeviceConfigService_nvGetItemDefinition_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvGetItemDefinition_args");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->nvItemNameOrId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvGetItemDefinition_pargs::~DeviceConfigService_nvGetItemDefinition_pargs() noexcept {
}


uint32_t DeviceConfigService_nvGetItemDefinition_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_nvGetItemDefinition_pargs");

  xfer += oprot->writeFieldBegin("nvItemNameOrId", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->nvItemNameOrId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_nvGetItemDefinition_result::~DeviceConfigService_nvGetItemDefinition_result() noexcept {
}


uint32_t DeviceConfigService_nvGetItemDefinition_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->success);
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

uint32_t DeviceConfigService_nvGetItemDefinition_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_nvGetItemDefinition_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeString(this->success);
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


DeviceConfigService_nvGetItemDefinition_presult::~DeviceConfigService_nvGetItemDefinition_presult() noexcept {
}


uint32_t DeviceConfigService_nvGetItemDefinition_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString((*(this->success)));
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


DeviceConfigService_efsHasAlternateFileSystem_args::~DeviceConfigService_efsHasAlternateFileSystem_args() noexcept {
}


uint32_t DeviceConfigService_efsHasAlternateFileSystem_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_efsHasAlternateFileSystem_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsHasAlternateFileSystem_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsHasAlternateFileSystem_pargs::~DeviceConfigService_efsHasAlternateFileSystem_pargs() noexcept {
}


uint32_t DeviceConfigService_efsHasAlternateFileSystem_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsHasAlternateFileSystem_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsHasAlternateFileSystem_result::~DeviceConfigService_efsHasAlternateFileSystem_result() noexcept {
}


uint32_t DeviceConfigService_efsHasAlternateFileSystem_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
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

uint32_t DeviceConfigService_efsHasAlternateFileSystem_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsHasAlternateFileSystem_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
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


DeviceConfigService_efsHasAlternateFileSystem_presult::~DeviceConfigService_efsHasAlternateFileSystem_presult() noexcept {
}


uint32_t DeviceConfigService_efsHasAlternateFileSystem_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
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


DeviceConfigService_efsCreateDirectory_args::~DeviceConfigService_efsCreateDirectory_args() noexcept {
}


uint32_t DeviceConfigService_efsCreateDirectory_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast92;
          xfer += iprot->readI32(ecast92);
          this->efsSystem = (FileSystem::type)ecast92;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsCreateDirectory_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsCreateDirectory_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsCreateDirectory_pargs::~DeviceConfigService_efsCreateDirectory_pargs() noexcept {
}


uint32_t DeviceConfigService_efsCreateDirectory_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsCreateDirectory_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsCreateDirectory_result::~DeviceConfigService_efsCreateDirectory_result() noexcept {
}


uint32_t DeviceConfigService_efsCreateDirectory_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast93;
          xfer += iprot->readI32(ecast93);
          this->success = ( ::Uts::ErrorCode::type)ecast93;
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

uint32_t DeviceConfigService_efsCreateDirectory_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsCreateDirectory_result");

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


DeviceConfigService_efsCreateDirectory_presult::~DeviceConfigService_efsCreateDirectory_presult() noexcept {
}


uint32_t DeviceConfigService_efsCreateDirectory_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast94;
          xfer += iprot->readI32(ecast94);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast94;
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


DeviceConfigService_efsRemoveDirectory_args::~DeviceConfigService_efsRemoveDirectory_args() noexcept {
}


uint32_t DeviceConfigService_efsRemoveDirectory_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast95;
          xfer += iprot->readI32(ecast95);
          this->efsSystem = (FileSystem::type)ecast95;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsRemoveDirectory_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsRemoveDirectory_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsRemoveDirectory_pargs::~DeviceConfigService_efsRemoveDirectory_pargs() noexcept {
}


uint32_t DeviceConfigService_efsRemoveDirectory_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsRemoveDirectory_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsRemoveDirectory_result::~DeviceConfigService_efsRemoveDirectory_result() noexcept {
}


uint32_t DeviceConfigService_efsRemoveDirectory_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast96;
          xfer += iprot->readI32(ecast96);
          this->success = ( ::Uts::ErrorCode::type)ecast96;
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

uint32_t DeviceConfigService_efsRemoveDirectory_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsRemoveDirectory_result");

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


DeviceConfigService_efsRemoveDirectory_presult::~DeviceConfigService_efsRemoveDirectory_presult() noexcept {
}


uint32_t DeviceConfigService_efsRemoveDirectory_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast97;
          xfer += iprot->readI32(ecast97);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast97;
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


DeviceConfigService_efsRemoveTree_args::~DeviceConfigService_efsRemoveTree_args() noexcept {
}


uint32_t DeviceConfigService_efsRemoveTree_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast98;
          xfer += iprot->readI32(ecast98);
          this->efsSytem = (FileSystem::type)ecast98;
          this->__isset.efsSytem = true;
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

uint32_t DeviceConfigService_efsRemoveTree_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsRemoveTree_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSytem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSytem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsRemoveTree_pargs::~DeviceConfigService_efsRemoveTree_pargs() noexcept {
}


uint32_t DeviceConfigService_efsRemoveTree_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsRemoveTree_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSytem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSytem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsRemoveTree_result::~DeviceConfigService_efsRemoveTree_result() noexcept {
}


uint32_t DeviceConfigService_efsRemoveTree_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast99;
          xfer += iprot->readI32(ecast99);
          this->success = ( ::Uts::ErrorCode::type)ecast99;
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

uint32_t DeviceConfigService_efsRemoveTree_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsRemoveTree_result");

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


DeviceConfigService_efsRemoveTree_presult::~DeviceConfigService_efsRemoveTree_presult() noexcept {
}


uint32_t DeviceConfigService_efsRemoveTree_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast100;
          xfer += iprot->readI32(ecast100);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast100;
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


DeviceConfigService_efsGetDirectoryContents_args::~DeviceConfigService_efsGetDirectoryContents_args() noexcept {
}


uint32_t DeviceConfigService_efsGetDirectoryContents_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast101;
          xfer += iprot->readI32(ecast101);
          this->efsSystem = (FileSystem::type)ecast101;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsGetDirectoryContents_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetDirectoryContents_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetDirectoryContents_pargs::~DeviceConfigService_efsGetDirectoryContents_pargs() noexcept {
}


uint32_t DeviceConfigService_efsGetDirectoryContents_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetDirectoryContents_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetDirectoryContents_result::~DeviceConfigService_efsGetDirectoryContents_result() noexcept {
}


uint32_t DeviceConfigService_efsGetDirectoryContents_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            uint32_t _size102;
            ::apache::thrift::protocol::TType _etype105;
            xfer += iprot->readListBegin(_etype105, _size102);
            this->success.resize(_size102);
            uint32_t _i106;
            for (_i106 = 0; _i106 < _size102; ++_i106)
            {
              xfer += this->success[_i106].read(iprot);
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

uint32_t DeviceConfigService_efsGetDirectoryContents_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetDirectoryContents_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_LIST, 0);
    {
      xfer += oprot->writeListBegin(::apache::thrift::protocol::T_STRUCT, static_cast<uint32_t>(this->success.size()));
      std::vector<EfsItem> ::const_iterator _iter107;
      for (_iter107 = this->success.begin(); _iter107 != this->success.end(); ++_iter107)
      {
        xfer += (*_iter107).write(oprot);
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


DeviceConfigService_efsGetDirectoryContents_presult::~DeviceConfigService_efsGetDirectoryContents_presult() noexcept {
}


uint32_t DeviceConfigService_efsGetDirectoryContents_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
            uint32_t _size108;
            ::apache::thrift::protocol::TType _etype111;
            xfer += iprot->readListBegin(_etype111, _size108);
            (*(this->success)).resize(_size108);
            uint32_t _i112;
            for (_i112 = 0; _i112 < _size108; ++_i112)
            {
              xfer += (*(this->success))[_i112].read(iprot);
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


DeviceConfigService_efsPutFile_args::~DeviceConfigService_efsPutFile_args() noexcept {
}


uint32_t DeviceConfigService_efsPutFile_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->buffer);
          this->__isset.buffer = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast113;
          xfer += iprot->readI32(ecast113);
          this->efsSystem = (FileSystem::type)ecast113;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsPutFile_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsPutFile_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("buffer", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary(this->buffer);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsPutFile_pargs::~DeviceConfigService_efsPutFile_pargs() noexcept {
}


uint32_t DeviceConfigService_efsPutFile_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsPutFile_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("buffer", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeBinary((*(this->buffer)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsPutFile_result::~DeviceConfigService_efsPutFile_result() noexcept {
}


uint32_t DeviceConfigService_efsPutFile_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast114;
          xfer += iprot->readI32(ecast114);
          this->success = ( ::Uts::ErrorCode::type)ecast114;
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

uint32_t DeviceConfigService_efsPutFile_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsPutFile_result");

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


DeviceConfigService_efsPutFile_presult::~DeviceConfigService_efsPutFile_presult() noexcept {
}


uint32_t DeviceConfigService_efsPutFile_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast115;
          xfer += iprot->readI32(ecast115);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast115;
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


DeviceConfigService_efsGetFile_args::~DeviceConfigService_efsGetFile_args() noexcept {
}


uint32_t DeviceConfigService_efsGetFile_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast116;
          xfer += iprot->readI32(ecast116);
          this->efsSystem = (FileSystem::type)ecast116;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsGetFile_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFile_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetFile_pargs::~DeviceConfigService_efsGetFile_pargs() noexcept {
}


uint32_t DeviceConfigService_efsGetFile_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFile_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetFile_result::~DeviceConfigService_efsGetFile_result() noexcept {
}


uint32_t DeviceConfigService_efsGetFile_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_efsGetFile_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFile_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_efsGetFile_presult::~DeviceConfigService_efsGetFile_presult() noexcept {
}


uint32_t DeviceConfigService_efsGetFile_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_efsDeleteFile_args::~DeviceConfigService_efsDeleteFile_args() noexcept {
}


uint32_t DeviceConfigService_efsDeleteFile_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast117;
          xfer += iprot->readI32(ecast117);
          this->efsSystem = (FileSystem::type)ecast117;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsDeleteFile_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsDeleteFile_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsDeleteFile_pargs::~DeviceConfigService_efsDeleteFile_pargs() noexcept {
}


uint32_t DeviceConfigService_efsDeleteFile_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsDeleteFile_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsDeleteFile_result::~DeviceConfigService_efsDeleteFile_result() noexcept {
}


uint32_t DeviceConfigService_efsDeleteFile_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_efsDeleteFile_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsDeleteFile_result");

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


DeviceConfigService_efsDeleteFile_presult::~DeviceConfigService_efsDeleteFile_presult() noexcept {
}


uint32_t DeviceConfigService_efsDeleteFile_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_efsRename_args::~DeviceConfigService_efsRename_args() noexcept {
}


uint32_t DeviceConfigService_efsRename_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->existingName);
          this->__isset.existingName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->newName);
          this->__isset.newName = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast120;
          xfer += iprot->readI32(ecast120);
          this->efsSystem = (FileSystem::type)ecast120;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsRename_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsRename_args");

  xfer += oprot->writeFieldBegin("existingName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->existingName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newName", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->newName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsRename_pargs::~DeviceConfigService_efsRename_pargs() noexcept {
}


uint32_t DeviceConfigService_efsRename_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsRename_pargs");

  xfer += oprot->writeFieldBegin("existingName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->existingName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newName", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString((*(this->newName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 3);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsRename_result::~DeviceConfigService_efsRename_result() noexcept {
}


uint32_t DeviceConfigService_efsRename_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast121;
          xfer += iprot->readI32(ecast121);
          this->success = ( ::Uts::ErrorCode::type)ecast121;
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

uint32_t DeviceConfigService_efsRename_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsRename_result");

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


DeviceConfigService_efsRename_presult::~DeviceConfigService_efsRename_presult() noexcept {
}


uint32_t DeviceConfigService_efsRename_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast122;
          xfer += iprot->readI32(ecast122);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast122;
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


DeviceConfigService_efsPathExists_args::~DeviceConfigService_efsPathExists_args() noexcept {
}


uint32_t DeviceConfigService_efsPathExists_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast123;
          xfer += iprot->readI32(ecast123);
          this->efsSystem = (FileSystem::type)ecast123;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsPathExists_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsPathExists_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsPathExists_pargs::~DeviceConfigService_efsPathExists_pargs() noexcept {
}


uint32_t DeviceConfigService_efsPathExists_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsPathExists_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsPathExists_result::~DeviceConfigService_efsPathExists_result() noexcept {
}


uint32_t DeviceConfigService_efsPathExists_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
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

uint32_t DeviceConfigService_efsPathExists_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsPathExists_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
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


DeviceConfigService_efsPathExists_presult::~DeviceConfigService_efsPathExists_presult() noexcept {
}


uint32_t DeviceConfigService_efsPathExists_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
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


DeviceConfigService_efsIsDirectory_args::~DeviceConfigService_efsIsDirectory_args() noexcept {
}


uint32_t DeviceConfigService_efsIsDirectory_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast124;
          xfer += iprot->readI32(ecast124);
          this->efsSystem = (FileSystem::type)ecast124;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsIsDirectory_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsDirectory_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsIsDirectory_pargs::~DeviceConfigService_efsIsDirectory_pargs() noexcept {
}


uint32_t DeviceConfigService_efsIsDirectory_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsDirectory_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsIsDirectory_result::~DeviceConfigService_efsIsDirectory_result() noexcept {
}


uint32_t DeviceConfigService_efsIsDirectory_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
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

uint32_t DeviceConfigService_efsIsDirectory_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsDirectory_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
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


DeviceConfigService_efsIsDirectory_presult::~DeviceConfigService_efsIsDirectory_presult() noexcept {
}


uint32_t DeviceConfigService_efsIsDirectory_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
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


DeviceConfigService_efsIsFile_args::~DeviceConfigService_efsIsFile_args() noexcept {
}


uint32_t DeviceConfigService_efsIsFile_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast125;
          xfer += iprot->readI32(ecast125);
          this->efsSystem = (FileSystem::type)ecast125;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsIsFile_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsFile_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsIsFile_pargs::~DeviceConfigService_efsIsFile_pargs() noexcept {
}


uint32_t DeviceConfigService_efsIsFile_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsFile_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsIsFile_result::~DeviceConfigService_efsIsFile_result() noexcept {
}


uint32_t DeviceConfigService_efsIsFile_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
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

uint32_t DeviceConfigService_efsIsFile_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsFile_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
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


DeviceConfigService_efsIsFile_presult::~DeviceConfigService_efsIsFile_presult() noexcept {
}


uint32_t DeviceConfigService_efsIsFile_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
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


DeviceConfigService_efsGetFileSize_args::~DeviceConfigService_efsGetFileSize_args() noexcept {
}


uint32_t DeviceConfigService_efsGetFileSize_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast126;
          xfer += iprot->readI32(ecast126);
          this->efsSystem = (FileSystem::type)ecast126;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsGetFileSize_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileSize_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetFileSize_pargs::~DeviceConfigService_efsGetFileSize_pargs() noexcept {
}


uint32_t DeviceConfigService_efsGetFileSize_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileSize_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetFileSize_result::~DeviceConfigService_efsGetFileSize_result() noexcept {
}


uint32_t DeviceConfigService_efsGetFileSize_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->success);
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

uint32_t DeviceConfigService_efsGetFileSize_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileSize_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
    xfer += oprot->writeI64(this->success);
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


DeviceConfigService_efsGetFileSize_presult::~DeviceConfigService_efsGetFileSize_presult() noexcept {
}


uint32_t DeviceConfigService_efsGetFileSize_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64((*(this->success)));
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


DeviceConfigService_efsGetAvailableSpace_args::~DeviceConfigService_efsGetAvailableSpace_args() noexcept {
}


uint32_t DeviceConfigService_efsGetAvailableSpace_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast127;
          xfer += iprot->readI32(ecast127);
          this->efsSystem = (FileSystem::type)ecast127;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsGetAvailableSpace_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetAvailableSpace_args");

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetAvailableSpace_pargs::~DeviceConfigService_efsGetAvailableSpace_pargs() noexcept {
}


uint32_t DeviceConfigService_efsGetAvailableSpace_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetAvailableSpace_pargs");

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetAvailableSpace_result::~DeviceConfigService_efsGetAvailableSpace_result() noexcept {
}


uint32_t DeviceConfigService_efsGetAvailableSpace_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->success);
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

uint32_t DeviceConfigService_efsGetAvailableSpace_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetAvailableSpace_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
    xfer += oprot->writeI64(this->success);
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


DeviceConfigService_efsGetAvailableSpace_presult::~DeviceConfigService_efsGetAvailableSpace_presult() noexcept {
}


uint32_t DeviceConfigService_efsGetAvailableSpace_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64((*(this->success)));
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


DeviceConfigService_efsGetFileCheckSum_args::~DeviceConfigService_efsGetFileCheckSum_args() noexcept {
}


uint32_t DeviceConfigService_efsGetFileCheckSum_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast128;
          xfer += iprot->readI32(ecast128);
          this->efsSystem = (FileSystem::type)ecast128;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsGetFileCheckSum_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileCheckSum_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetFileCheckSum_pargs::~DeviceConfigService_efsGetFileCheckSum_pargs() noexcept {
}


uint32_t DeviceConfigService_efsGetFileCheckSum_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileCheckSum_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetFileCheckSum_result::~DeviceConfigService_efsGetFileCheckSum_result() noexcept {
}


uint32_t DeviceConfigService_efsGetFileCheckSum_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_efsGetFileCheckSum_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileCheckSum_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_efsGetFileCheckSum_presult::~DeviceConfigService_efsGetFileCheckSum_presult() noexcept {
}


uint32_t DeviceConfigService_efsGetFileCheckSum_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_efsGetFileAttributes_args::~DeviceConfigService_efsGetFileAttributes_args() noexcept {
}


uint32_t DeviceConfigService_efsGetFileAttributes_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast129;
          xfer += iprot->readI32(ecast129);
          this->efsSystem = (FileSystem::type)ecast129;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_efsGetFileAttributes_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileAttributes_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetFileAttributes_pargs::~DeviceConfigService_efsGetFileAttributes_pargs() noexcept {
}


uint32_t DeviceConfigService_efsGetFileAttributes_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileAttributes_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsGetFileAttributes_result::~DeviceConfigService_efsGetFileAttributes_result() noexcept {
}


uint32_t DeviceConfigService_efsGetFileAttributes_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_efsGetFileAttributes_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsGetFileAttributes_result");

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


DeviceConfigService_efsGetFileAttributes_presult::~DeviceConfigService_efsGetFileAttributes_presult() noexcept {
}


uint32_t DeviceConfigService_efsGetFileAttributes_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_efsIsReady_args::~DeviceConfigService_efsIsReady_args() noexcept {
}


uint32_t DeviceConfigService_efsIsReady_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_efsIsReady_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsReady_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsIsReady_pargs::~DeviceConfigService_efsIsReady_pargs() noexcept {
}


uint32_t DeviceConfigService_efsIsReady_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsReady_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsIsReady_result::~DeviceConfigService_efsIsReady_result() noexcept {
}


uint32_t DeviceConfigService_efsIsReady_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
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

uint32_t DeviceConfigService_efsIsReady_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsIsReady_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
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


DeviceConfigService_efsIsReady_presult::~DeviceConfigService_efsIsReady_presult() noexcept {
}


uint32_t DeviceConfigService_efsIsReady_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
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


DeviceConfigService_createGoldenCopy_args::~DeviceConfigService_createGoldenCopy_args() noexcept {
}


uint32_t DeviceConfigService_createGoldenCopy_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast130;
          xfer += iprot->readI32(ecast130);
          this->efsSystem = (FileSystem::type)ecast130;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_createGoldenCopy_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_createGoldenCopy_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_createGoldenCopy_pargs::~DeviceConfigService_createGoldenCopy_pargs() noexcept {
}


uint32_t DeviceConfigService_createGoldenCopy_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_createGoldenCopy_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_createGoldenCopy_result::~DeviceConfigService_createGoldenCopy_result() noexcept {
}


uint32_t DeviceConfigService_createGoldenCopy_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast131;
          xfer += iprot->readI32(ecast131);
          this->success = ( ::Uts::ErrorCode::type)ecast131;
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

uint32_t DeviceConfigService_createGoldenCopy_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_createGoldenCopy_result");

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


DeviceConfigService_createGoldenCopy_presult::~DeviceConfigService_createGoldenCopy_presult() noexcept {
}


uint32_t DeviceConfigService_createGoldenCopy_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast132;
          xfer += iprot->readI32(ecast132);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast132;
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


DeviceConfigService_createCefsCopy_args::~DeviceConfigService_createCefsCopy_args() noexcept {
}


uint32_t DeviceConfigService_createCefsCopy_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->cefsSavePath);
          this->__isset.cefsSavePath = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast133;
          xfer += iprot->readI32(ecast133);
          this->efsSystem = (FileSystem::type)ecast133;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_createCefsCopy_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_createCefsCopy_args");

  xfer += oprot->writeFieldBegin("cefsSavePath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->cefsSavePath);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_createCefsCopy_pargs::~DeviceConfigService_createCefsCopy_pargs() noexcept {
}


uint32_t DeviceConfigService_createCefsCopy_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_createCefsCopy_pargs");

  xfer += oprot->writeFieldBegin("cefsSavePath", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->cefsSavePath)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_createCefsCopy_result::~DeviceConfigService_createCefsCopy_result() noexcept {
}


uint32_t DeviceConfigService_createCefsCopy_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast134;
          xfer += iprot->readI32(ecast134);
          this->success = ( ::Uts::ErrorCode::type)ecast134;
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

uint32_t DeviceConfigService_createCefsCopy_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_createCefsCopy_result");

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


DeviceConfigService_createCefsCopy_presult::~DeviceConfigService_createCefsCopy_presult() noexcept {
}


uint32_t DeviceConfigService_createCefsCopy_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast135;
          xfer += iprot->readI32(ecast135);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast135;
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


DeviceConfigService_requestPrl_args::~DeviceConfigService_requestPrl_args() noexcept {
}


uint32_t DeviceConfigService_requestPrl_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->index);
          this->__isset.index = true;
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

uint32_t DeviceConfigService_requestPrl_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_requestPrl_args");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_BYTE, 2);
  xfer += oprot->writeByte(this->index);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_requestPrl_pargs::~DeviceConfigService_requestPrl_pargs() noexcept {
}


uint32_t DeviceConfigService_requestPrl_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_requestPrl_pargs");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_BYTE, 2);
  xfer += oprot->writeByte((*(this->index)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_requestPrl_result::~DeviceConfigService_requestPrl_result() noexcept {
}


uint32_t DeviceConfigService_requestPrl_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_requestPrl_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_requestPrl_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_requestPrl_presult::~DeviceConfigService_requestPrl_presult() noexcept {
}


uint32_t DeviceConfigService_requestPrl_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_backupPrl_args::~DeviceConfigService_backupPrl_args() noexcept {
}


uint32_t DeviceConfigService_backupPrl_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_backupPrl_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_backupPrl_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_backupPrl_pargs::~DeviceConfigService_backupPrl_pargs() noexcept {
}


uint32_t DeviceConfigService_backupPrl_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_backupPrl_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_backupPrl_result::~DeviceConfigService_backupPrl_result() noexcept {
}


uint32_t DeviceConfigService_backupPrl_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->success);
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

uint32_t DeviceConfigService_backupPrl_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_backupPrl_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeString(this->success);
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


DeviceConfigService_backupPrl_presult::~DeviceConfigService_backupPrl_presult() noexcept {
}


uint32_t DeviceConfigService_backupPrl_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString((*(this->success)));
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


DeviceConfigService_restorePrl_args::~DeviceConfigService_restorePrl_args() noexcept {
}


uint32_t DeviceConfigService_restorePrl_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->xqcnFileContents);
          this->__isset.xqcnFileContents = true;
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

uint32_t DeviceConfigService_restorePrl_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_restorePrl_args");

  xfer += oprot->writeFieldBegin("xqcnFileContents", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->xqcnFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_restorePrl_pargs::~DeviceConfigService_restorePrl_pargs() noexcept {
}


uint32_t DeviceConfigService_restorePrl_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_restorePrl_pargs");

  xfer += oprot->writeFieldBegin("xqcnFileContents", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->xqcnFileContents)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_restorePrl_result::~DeviceConfigService_restorePrl_result() noexcept {
}


uint32_t DeviceConfigService_restorePrl_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_restorePrl_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_restorePrl_result");

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


DeviceConfigService_restorePrl_presult::~DeviceConfigService_restorePrl_presult() noexcept {
}


uint32_t DeviceConfigService_restorePrl_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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


DeviceConfigService_sendPrl_args::~DeviceConfigService_sendPrl_args() noexcept {
}


uint32_t DeviceConfigService_sendPrl_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_BYTE) {
          xfer += iprot->readByte(this->index);
          this->__isset.index = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 3:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->prlFileContents);
          this->__isset.prlFileContents = true;
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

uint32_t DeviceConfigService_sendPrl_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_sendPrl_args");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_BYTE, 2);
  xfer += oprot->writeByte(this->index);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prlFileContents", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeBinary(this->prlFileContents);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_sendPrl_pargs::~DeviceConfigService_sendPrl_pargs() noexcept {
}


uint32_t DeviceConfigService_sendPrl_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_sendPrl_pargs");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("index", ::apache::thrift::protocol::T_BYTE, 2);
  xfer += oprot->writeByte((*(this->index)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("prlFileContents", ::apache::thrift::protocol::T_STRING, 3);
  xfer += oprot->writeBinary((*(this->prlFileContents)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_sendPrl_result::~DeviceConfigService_sendPrl_result() noexcept {
}


uint32_t DeviceConfigService_sendPrl_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast138;
          xfer += iprot->readI32(ecast138);
          this->success = ( ::Uts::ErrorCode::type)ecast138;
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

uint32_t DeviceConfigService_sendPrl_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_sendPrl_result");

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


DeviceConfigService_sendPrl_presult::~DeviceConfigService_sendPrl_presult() noexcept {
}


uint32_t DeviceConfigService_sendPrl_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast139;
          xfer += iprot->readI32(ecast139);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast139;
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


DeviceConfigService_forceEfsSync_args::~DeviceConfigService_forceEfsSync_args() noexcept {
}


uint32_t DeviceConfigService_forceEfsSync_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          int32_t ecast140;
          xfer += iprot->readI32(ecast140);
          this->efsSystem = (FileSystem::type)ecast140;
          this->__isset.efsSystem = true;
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

uint32_t DeviceConfigService_forceEfsSync_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_forceEfsSync_args");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->pathName);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)this->efsSystem);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_forceEfsSync_pargs::~DeviceConfigService_forceEfsSync_pargs() noexcept {
}


uint32_t DeviceConfigService_forceEfsSync_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_forceEfsSync_pargs");

  xfer += oprot->writeFieldBegin("pathName", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->pathName)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("efsSystem", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((int32_t)(*(this->efsSystem)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_forceEfsSync_result::~DeviceConfigService_forceEfsSync_result() noexcept {
}


uint32_t DeviceConfigService_forceEfsSync_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast141;
          xfer += iprot->readI32(ecast141);
          this->success = ( ::Uts::ErrorCode::type)ecast141;
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

uint32_t DeviceConfigService_forceEfsSync_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_forceEfsSync_result");

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


DeviceConfigService_forceEfsSync_presult::~DeviceConfigService_forceEfsSync_presult() noexcept {
}


uint32_t DeviceConfigService_forceEfsSync_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast142;
          xfer += iprot->readI32(ecast142);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast142;
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


DeviceConfigService_getEsn_args::~DeviceConfigService_getEsn_args() noexcept {
}


uint32_t DeviceConfigService_getEsn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_getEsn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getEsn_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getEsn_pargs::~DeviceConfigService_getEsn_pargs() noexcept {
}


uint32_t DeviceConfigService_getEsn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getEsn_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getEsn_result::~DeviceConfigService_getEsn_result() noexcept {
}


uint32_t DeviceConfigService_getEsn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->success);
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

uint32_t DeviceConfigService_getEsn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_getEsn_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I32, 0);
    xfer += oprot->writeI32(this->success);
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


DeviceConfigService_getEsn_presult::~DeviceConfigService_getEsn_presult() noexcept {
}


uint32_t DeviceConfigService_getEsn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32((*(this->success)));
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


DeviceConfigService_setEsn_args::~DeviceConfigService_setEsn_args() noexcept {
}


uint32_t DeviceConfigService_setEsn_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->esn);
          this->__isset.esn = true;
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

uint32_t DeviceConfigService_setEsn_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_setEsn_args");

  xfer += oprot->writeFieldBegin("esn", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->esn);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_setEsn_pargs::~DeviceConfigService_setEsn_pargs() noexcept {
}


uint32_t DeviceConfigService_setEsn_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_setEsn_pargs");

  xfer += oprot->writeFieldBegin("esn", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->esn)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_setEsn_result::~DeviceConfigService_setEsn_result() noexcept {
}


uint32_t DeviceConfigService_setEsn_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast143;
          xfer += iprot->readI32(ecast143);
          this->success = ( ::Uts::ErrorCode::type)ecast143;
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

uint32_t DeviceConfigService_setEsn_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_setEsn_result");

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


DeviceConfigService_setEsn_presult::~DeviceConfigService_setEsn_presult() noexcept {
}


uint32_t DeviceConfigService_setEsn_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast144;
          xfer += iprot->readI32(ecast144);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast144;
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


DeviceConfigService_getImei_args::~DeviceConfigService_getImei_args() noexcept {
}


uint32_t DeviceConfigService_getImei_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
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

uint32_t DeviceConfigService_getImei_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getImei_args");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getImei_pargs::~DeviceConfigService_getImei_pargs() noexcept {
}


uint32_t DeviceConfigService_getImei_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getImei_pargs");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getImei_result::~DeviceConfigService_getImei_result() noexcept {
}


uint32_t DeviceConfigService_getImei_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_getImei_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_getImei_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_getImei_presult::~DeviceConfigService_getImei_presult() noexcept {
}


uint32_t DeviceConfigService_getImei_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_setImei_args::~DeviceConfigService_setImei_args() noexcept {
}


uint32_t DeviceConfigService_setImei_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readBinary(this->imei);
          this->__isset.imei = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
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

uint32_t DeviceConfigService_setImei_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_setImei_args");

  xfer += oprot->writeFieldBegin("imei", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeBinary(this->imei);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_setImei_pargs::~DeviceConfigService_setImei_pargs() noexcept {
}


uint32_t DeviceConfigService_setImei_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_setImei_pargs");

  xfer += oprot->writeFieldBegin("imei", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeBinary((*(this->imei)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_setImei_result::~DeviceConfigService_setImei_result() noexcept {
}


uint32_t DeviceConfigService_setImei_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast145;
          xfer += iprot->readI32(ecast145);
          this->success = ( ::Uts::ErrorCode::type)ecast145;
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

uint32_t DeviceConfigService_setImei_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_setImei_result");

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


DeviceConfigService_setImei_presult::~DeviceConfigService_setImei_presult() noexcept {
}


uint32_t DeviceConfigService_setImei_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast146;
          xfer += iprot->readI32(ecast146);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast146;
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


DeviceConfigService_getMeid_args::~DeviceConfigService_getMeid_args() noexcept {
}


uint32_t DeviceConfigService_getMeid_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
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

uint32_t DeviceConfigService_getMeid_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getMeid_args");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getMeid_pargs::~DeviceConfigService_getMeid_pargs() noexcept {
}


uint32_t DeviceConfigService_getMeid_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_getMeid_pargs");

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 1);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_getMeid_result::~DeviceConfigService_getMeid_result() noexcept {
}


uint32_t DeviceConfigService_getMeid_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64(this->success);
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

uint32_t DeviceConfigService_getMeid_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_getMeid_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_I64, 0);
    xfer += oprot->writeI64(this->success);
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


DeviceConfigService_getMeid_presult::~DeviceConfigService_getMeid_presult() noexcept {
}


uint32_t DeviceConfigService_getMeid_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_I64) {
          xfer += iprot->readI64((*(this->success)));
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


DeviceConfigService_setMeid_args::~DeviceConfigService_setMeid_args() noexcept {
}


uint32_t DeviceConfigService_setMeid_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readI64(this->meid);
          this->__isset.meid = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_I32) {
          xfer += iprot->readI32(this->subscriptionId);
          this->__isset.subscriptionId = true;
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

uint32_t DeviceConfigService_setMeid_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_setMeid_args");

  xfer += oprot->writeFieldBegin("meid", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64(this->meid);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32(this->subscriptionId);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_setMeid_pargs::~DeviceConfigService_setMeid_pargs() noexcept {
}


uint32_t DeviceConfigService_setMeid_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_setMeid_pargs");

  xfer += oprot->writeFieldBegin("meid", ::apache::thrift::protocol::T_I64, 1);
  xfer += oprot->writeI64((*(this->meid)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("subscriptionId", ::apache::thrift::protocol::T_I32, 2);
  xfer += oprot->writeI32((*(this->subscriptionId)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_setMeid_result::~DeviceConfigService_setMeid_result() noexcept {
}


uint32_t DeviceConfigService_setMeid_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast147;
          xfer += iprot->readI32(ecast147);
          this->success = ( ::Uts::ErrorCode::type)ecast147;
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

uint32_t DeviceConfigService_setMeid_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_setMeid_result");

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


DeviceConfigService_setMeid_presult::~DeviceConfigService_setMeid_presult() noexcept {
}


uint32_t DeviceConfigService_setMeid_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast148;
          xfer += iprot->readI32(ecast148);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast148;
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


DeviceConfigService_checkSpc_args::~DeviceConfigService_checkSpc_args() noexcept {
}


uint32_t DeviceConfigService_checkSpc_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->spc);
          this->__isset.spc = true;
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

uint32_t DeviceConfigService_checkSpc_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_checkSpc_args");

  xfer += oprot->writeFieldBegin("spc", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->spc);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_checkSpc_pargs::~DeviceConfigService_checkSpc_pargs() noexcept {
}


uint32_t DeviceConfigService_checkSpc_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_checkSpc_pargs");

  xfer += oprot->writeFieldBegin("spc", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->spc)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_checkSpc_result::~DeviceConfigService_checkSpc_result() noexcept {
}


uint32_t DeviceConfigService_checkSpc_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
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

uint32_t DeviceConfigService_checkSpc_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_checkSpc_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
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


DeviceConfigService_checkSpc_presult::~DeviceConfigService_checkSpc_presult() noexcept {
}


uint32_t DeviceConfigService_checkSpc_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
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


DeviceConfigService_provisionSpc_args::~DeviceConfigService_provisionSpc_args() noexcept {
}


uint32_t DeviceConfigService_provisionSpc_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += iprot->readString(this->currentSpc);
          this->__isset.currentSpc = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      case 2:
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readString(this->newSpc);
          this->__isset.newSpc = true;
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

uint32_t DeviceConfigService_provisionSpc_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_provisionSpc_args");

  xfer += oprot->writeFieldBegin("currentSpc", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString(this->currentSpc);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newSpc", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString(this->newSpc);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_provisionSpc_pargs::~DeviceConfigService_provisionSpc_pargs() noexcept {
}


uint32_t DeviceConfigService_provisionSpc_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_provisionSpc_pargs");

  xfer += oprot->writeFieldBegin("currentSpc", ::apache::thrift::protocol::T_STRING, 1);
  xfer += oprot->writeString((*(this->currentSpc)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldBegin("newSpc", ::apache::thrift::protocol::T_STRING, 2);
  xfer += oprot->writeString((*(this->newSpc)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_provisionSpc_result::~DeviceConfigService_provisionSpc_result() noexcept {
}


uint32_t DeviceConfigService_provisionSpc_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
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

uint32_t DeviceConfigService_provisionSpc_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_provisionSpc_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
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


DeviceConfigService_provisionSpc_presult::~DeviceConfigService_provisionSpc_presult() noexcept {
}


uint32_t DeviceConfigService_provisionSpc_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
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


DeviceConfigService_efsReadFromModemLog_args::~DeviceConfigService_efsReadFromModemLog_args() noexcept {
}


uint32_t DeviceConfigService_efsReadFromModemLog_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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

uint32_t DeviceConfigService_efsReadFromModemLog_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsReadFromModemLog_args");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsReadFromModemLog_pargs::~DeviceConfigService_efsReadFromModemLog_pargs() noexcept {
}


uint32_t DeviceConfigService_efsReadFromModemLog_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_efsReadFromModemLog_pargs");

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_efsReadFromModemLog_result::~DeviceConfigService_efsReadFromModemLog_result() noexcept {
}


uint32_t DeviceConfigService_efsReadFromModemLog_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary(this->success);
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

uint32_t DeviceConfigService_efsReadFromModemLog_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_efsReadFromModemLog_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_STRING, 0);
    xfer += oprot->writeBinary(this->success);
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


DeviceConfigService_efsReadFromModemLog_presult::~DeviceConfigService_efsReadFromModemLog_presult() noexcept {
}


uint32_t DeviceConfigService_efsReadFromModemLog_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
        if (ftype == ::apache::thrift::protocol::T_STRING) {
          xfer += iprot->readBinary((*(this->success)));
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


DeviceConfigService_configureService_args::~DeviceConfigService_configureService_args() noexcept {
}


uint32_t DeviceConfigService_configureService_args::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          xfer += this->deviceConfigOptions.read(iprot);
          this->__isset.deviceConfigOptions = true;
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

uint32_t DeviceConfigService_configureService_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_configureService_args");

  xfer += oprot->writeFieldBegin("deviceConfigOptions", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->deviceConfigOptions.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_configureService_pargs::~DeviceConfigService_configureService_pargs() noexcept {
}


uint32_t DeviceConfigService_configureService_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("DeviceConfigService_configureService_pargs");

  xfer += oprot->writeFieldBegin("deviceConfigOptions", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->deviceConfigOptions)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


DeviceConfigService_configureService_result::~DeviceConfigService_configureService_result() noexcept {
}


uint32_t DeviceConfigService_configureService_result::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast149;
          xfer += iprot->readI32(ecast149);
          this->success = ( ::Uts::ErrorCode::type)ecast149;
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

uint32_t DeviceConfigService_configureService_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("DeviceConfigService_configureService_result");

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


DeviceConfigService_configureService_presult::~DeviceConfigService_configureService_presult() noexcept {
}


uint32_t DeviceConfigService_configureService_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

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
          int32_t ecast150;
          xfer += iprot->readI32(ecast150);
          (*(this->success)) = ( ::Uts::ErrorCode::type)ecast150;
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

void DeviceConfigServiceClient::getLastError( ::Uts::ErrorType& _return)
{
  send_getLastError();
  recv_getLastError(_return);
}

void DeviceConfigServiceClient::send_getLastError()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getLastError", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getLastError_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_getLastError( ::Uts::ErrorType& _return)
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
  DeviceConfigService_getLastError_presult result;
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

int64_t DeviceConfigServiceClient::getDevice()
{
  send_getDevice();
  return recv_getDevice();
}

void DeviceConfigServiceClient::send_getDevice()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getDevice", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getDevice_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int64_t DeviceConfigServiceClient::recv_getDevice()
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
  if (fname.compare("getDevice") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int64_t _return;
  DeviceConfigService_getDevice_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getDevice failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::initializeService()
{
  send_initializeService();
  return recv_initializeService();
}

void DeviceConfigServiceClient::send_initializeService()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("initializeService", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_initializeService_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_initializeService()
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
  DeviceConfigService_initializeService_presult result;
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

 ::Uts::ErrorCode::type DeviceConfigServiceClient::initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle)
{
  send_initializeServiceByProtocol(diagProtocolHandle, qmiProtocolHandle);
  return recv_initializeServiceByProtocol();
}

void DeviceConfigServiceClient::send_initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("initializeServiceByProtocol", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_initializeServiceByProtocol_pargs args;
  args.diagProtocolHandle = &diagProtocolHandle;
  args.qmiProtocolHandle = &qmiProtocolHandle;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_initializeServiceByProtocol()
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
  if (fname.compare("initializeServiceByProtocol") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_initializeServiceByProtocol_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "initializeServiceByProtocol failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions)
{
  send_initializeServiceWithOptions(connectionOptions);
  return recv_initializeServiceWithOptions();
}

void DeviceConfigServiceClient::send_initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("initializeServiceWithOptions", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_initializeServiceWithOptions_pargs args;
  args.connectionOptions = &connectionOptions;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_initializeServiceWithOptions()
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
  if (fname.compare("initializeServiceWithOptions") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_initializeServiceWithOptions_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "initializeServiceWithOptions failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::destroyService()
{
  send_destroyService();
  return recv_destroyService();
}

void DeviceConfigServiceClient::send_destroyService()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("destroyService", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_destroyService_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_destroyService()
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
  DeviceConfigService_destroyService_presult result;
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

void DeviceConfigServiceClient::doXqcnOperation( ::Uts::DeviceConfigResp& _return, const DeviceConfigOptions& deviceConfigOptions)
{
  send_doXqcnOperation(deviceConfigOptions);
  recv_doXqcnOperation(_return);
}

void DeviceConfigServiceClient::send_doXqcnOperation(const DeviceConfigOptions& deviceConfigOptions)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("doXqcnOperation", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_doXqcnOperation_pargs args;
  args.deviceConfigOptions = &deviceConfigOptions;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_doXqcnOperation( ::Uts::DeviceConfigResp& _return)
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
  if (fname.compare("doXqcnOperation") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_doXqcnOperation_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "doXqcnOperation failed: unknown result");
}

void DeviceConfigServiceClient::backupToXqcn(std::string& _return, const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents)
{
  send_backupToXqcn(serviceProgrammingCode, resetUponCompletion, resetTimeout, filterFileContents);
  recv_backupToXqcn(_return);
}

void DeviceConfigServiceClient::send_backupToXqcn(const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("backupToXqcn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_backupToXqcn_pargs args;
  args.serviceProgrammingCode = &serviceProgrammingCode;
  args.resetUponCompletion = &resetUponCompletion;
  args.resetTimeout = &resetTimeout;
  args.filterFileContents = &filterFileContents;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_backupToXqcn(std::string& _return)
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
  if (fname.compare("backupToXqcn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_backupToXqcn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "backupToXqcn failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents)
{
  send_restoreFromXqcn(xqcnFileContents, serviceProgrammingCode, allowEsnMismatch, resetUponCompletion, resetTimeout, filterFileContents);
  return recv_restoreFromXqcn();
}

void DeviceConfigServiceClient::send_restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("restoreFromXqcn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_restoreFromXqcn_pargs args;
  args.xqcnFileContents = &xqcnFileContents;
  args.serviceProgrammingCode = &serviceProgrammingCode;
  args.allowEsnMismatch = &allowEsnMismatch;
  args.resetUponCompletion = &resetUponCompletion;
  args.resetTimeout = &resetTimeout;
  args.filterFileContents = &filterFileContents;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_restoreFromXqcn()
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
  if (fname.compare("restoreFromXqcn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_restoreFromXqcn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "restoreFromXqcn failed: unknown result");
}

int64_t DeviceConfigServiceClient::pdcGetMbnMaxStorage(const PdcMbnType::type mbnType)
{
  send_pdcGetMbnMaxStorage(mbnType);
  return recv_pdcGetMbnMaxStorage();
}

void DeviceConfigServiceClient::send_pdcGetMbnMaxStorage(const PdcMbnType::type mbnType)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetMbnMaxStorage", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnMaxStorage_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int64_t DeviceConfigServiceClient::recv_pdcGetMbnMaxStorage()
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
  if (fname.compare("pdcGetMbnMaxStorage") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int64_t _return;
  DeviceConfigService_pdcGetMbnMaxStorage_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnMaxStorage failed: unknown result");
}

int64_t DeviceConfigServiceClient::pdcGetMbnStorageUsage(const PdcMbnType::type mbnType)
{
  send_pdcGetMbnStorageUsage(mbnType);
  return recv_pdcGetMbnStorageUsage();
}

void DeviceConfigServiceClient::send_pdcGetMbnStorageUsage(const PdcMbnType::type mbnType)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetMbnStorageUsage", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnStorageUsage_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int64_t DeviceConfigServiceClient::recv_pdcGetMbnStorageUsage()
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
  if (fname.compare("pdcGetMbnStorageUsage") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int64_t _return;
  DeviceConfigService_pdcGetMbnStorageUsage_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnStorageUsage failed: unknown result");
}

int64_t DeviceConfigServiceClient::pdcGetMbnCount(const PdcMbnType::type mbnType)
{
  send_pdcGetMbnCount(mbnType);
  return recv_pdcGetMbnCount();
}

void DeviceConfigServiceClient::send_pdcGetMbnCount(const PdcMbnType::type mbnType)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetMbnCount", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnCount_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int64_t DeviceConfigServiceClient::recv_pdcGetMbnCount()
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
  if (fname.compare("pdcGetMbnCount") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int64_t _return;
  DeviceConfigService_pdcGetMbnCount_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnCount failed: unknown result");
}

void DeviceConfigServiceClient::pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const PdcMbnType::type mbnType)
{
  send_pdcGetMbnList(mbnType);
  recv_pdcGetMbnList(_return);
}

void DeviceConfigServiceClient::send_pdcGetMbnList(const PdcMbnType::type mbnType)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetMbnList", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnList_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_pdcGetMbnList(std::vector<PdcMbnInfo> & _return)
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
  if (fname.compare("pdcGetMbnList") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_pdcGetMbnList_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnList failed: unknown result");
}

void DeviceConfigServiceClient::pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const PdcMbnType::type mbnType)
{
  send_pdcGetDefaultMbnInfo(mbnType);
  recv_pdcGetDefaultMbnInfo(_return);
}

void DeviceConfigServiceClient::send_pdcGetDefaultMbnInfo(const PdcMbnType::type mbnType)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetDefaultMbnInfo", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetDefaultMbnInfo_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_pdcGetDefaultMbnInfo(PdcMbnInfo& _return)
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
  if (fname.compare("pdcGetDefaultMbnInfo") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_pdcGetDefaultMbnInfo_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetDefaultMbnInfo failed: unknown result");
}

void DeviceConfigServiceClient::pdcGetMbnId(std::string& _return, const std::string& mbnContent)
{
  send_pdcGetMbnId(mbnContent);
  recv_pdcGetMbnId(_return);
}

void DeviceConfigServiceClient::send_pdcGetMbnId(const std::string& mbnContent)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetMbnId", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnId_pargs args;
  args.mbnContent = &mbnContent;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_pdcGetMbnId(std::string& _return)
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
  if (fname.compare("pdcGetMbnId") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_pdcGetMbnId_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnId failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent)
{
  send_pdcWriteMbn(mbnType, mbnContent);
  return recv_pdcWriteMbn();
}

void DeviceConfigServiceClient::send_pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcWriteMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcWriteMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnContent = &mbnContent;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_pdcWriteMbn()
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
  if (fname.compare("pdcWriteMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_pdcWriteMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcWriteMbn failed: unknown result");
}

void DeviceConfigServiceClient::pdcReadMbn(std::string& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId)
{
  send_pdcReadMbn(mbnType, mbnId, subId);
  recv_pdcReadMbn(_return);
}

void DeviceConfigServiceClient::send_pdcReadMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcReadMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcReadMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnId = &mbnId;
  args.subId = &subId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_pdcReadMbn(std::string& _return)
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
  if (fname.compare("pdcReadMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_pdcReadMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcReadMbn failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId)
{
  send_pdcRemoveMbn(mbnType, mbnId);
  return recv_pdcRemoveMbn();
}

void DeviceConfigServiceClient::send_pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcRemoveMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcRemoveMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnId = &mbnId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_pdcRemoveMbn()
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
  if (fname.compare("pdcRemoveMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_pdcRemoveMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcRemoveMbn failed: unknown result");
}

void DeviceConfigServiceClient::pdcGetActiveMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId)
{
  send_pdcGetActiveMbn(mbnType, subId, slotId);
  recv_pdcGetActiveMbn(_return);
}

void DeviceConfigServiceClient::send_pdcGetActiveMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetActiveMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetActiveMbn_pargs args;
  args.mbnType = &mbnType;
  args.subId = &subId;
  args.slotId = &slotId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_pdcGetActiveMbn(std::string& _return)
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
  if (fname.compare("pdcGetActiveMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_pdcGetActiveMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetActiveMbn failed: unknown result");
}

void DeviceConfigServiceClient::pdcGetPendingMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId)
{
  send_pdcGetPendingMbn(mbnType, subId, slotId);
  recv_pdcGetPendingMbn(_return);
}

void DeviceConfigServiceClient::send_pdcGetPendingMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetPendingMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetPendingMbn_pargs args;
  args.mbnType = &mbnType;
  args.subId = &subId;
  args.slotId = &slotId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_pdcGetPendingMbn(std::string& _return)
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
  if (fname.compare("pdcGetPendingMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_pdcGetPendingMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetPendingMbn failed: unknown result");
}

void DeviceConfigServiceClient::pdcValidateMbn(PdcMbnResult& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath)
{
  send_pdcValidateMbn(mbnType, mbnId, subId, remotePath);
  recv_pdcValidateMbn(_return);
}

void DeviceConfigServiceClient::send_pdcValidateMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcValidateMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcValidateMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnId = &mbnId;
  args.subId = &subId;
  args.remotePath = &remotePath;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_pdcValidateMbn(PdcMbnResult& _return)
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
  if (fname.compare("pdcValidateMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_pdcValidateMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcValidateMbn failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId)
{
  send_pdcSelectMbn(mbnType, mbnId, subId, slotId);
  return recv_pdcSelectMbn();
}

void DeviceConfigServiceClient::send_pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcSelectMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcSelectMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnId = &mbnId;
  args.subId = &subId;
  args.slotId = &slotId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_pdcSelectMbn()
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
  if (fname.compare("pdcSelectMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_pdcSelectMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcSelectMbn failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout)
{
  send_pdcActivateMbn(mbnType, subId, slotId, mode, timeout);
  return recv_pdcActivateMbn();
}

void DeviceConfigServiceClient::send_pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcActivateMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcActivateMbn_pargs args;
  args.mbnType = &mbnType;
  args.subId = &subId;
  args.slotId = &slotId;
  args.mode = &mode;
  args.timeout = &timeout;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_pdcActivateMbn()
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
  if (fname.compare("pdcActivateMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_pdcActivateMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcActivateMbn failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId)
{
  send_pdcDeactivateMbn(mbnType, subId);
  return recv_pdcDeactivateMbn();
}

void DeviceConfigServiceClient::send_pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcDeactivateMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcDeactivateMbn_pargs args;
  args.mbnType = &mbnType;
  args.subId = &subId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_pdcDeactivateMbn()
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
  if (fname.compare("pdcDeactivateMbn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_pdcDeactivateMbn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcDeactivateMbn failed: unknown result");
}

int32_t DeviceConfigServiceClient::pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature)
{
  send_pdcGetConfiguration(slotId, feature);
  return recv_pdcGetConfiguration();
}

void DeviceConfigServiceClient::send_pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcGetConfiguration", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetConfiguration_pargs args;
  args.slotId = &slotId;
  args.feature = &feature;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int32_t DeviceConfigServiceClient::recv_pdcGetConfiguration()
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
  if (fname.compare("pdcGetConfiguration") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int32_t _return;
  DeviceConfigService_pdcGetConfiguration_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetConfiguration failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value)
{
  send_pdcSetConfiguration(slotId, feature, value);
  return recv_pdcSetConfiguration();
}

void DeviceConfigServiceClient::send_pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("pdcSetConfiguration", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcSetConfiguration_pargs args;
  args.slotId = &slotId;
  args.feature = &feature;
  args.value = &value;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_pdcSetConfiguration()
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
  if (fname.compare("pdcSetConfiguration") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_pdcSetConfiguration_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcSetConfiguration failed: unknown result");
}

bool DeviceConfigServiceClient::nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId)
{
  send_nvIsItemSupported(nvItemNameOrId, subscriptionId);
  return recv_nvIsItemSupported();
}

void DeviceConfigServiceClient::send_nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("nvIsItemSupported", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvIsItemSupported_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool DeviceConfigServiceClient::recv_nvIsItemSupported()
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
  if (fname.compare("nvIsItemSupported") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  DeviceConfigService_nvIsItemSupported_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvIsItemSupported failed: unknown result");
}

void DeviceConfigServiceClient::nvReadItem(NvData& _return, const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig)
{
  send_nvReadItem(nvItemNameOrId, subscriptionId, index, returnConfig);
  recv_nvReadItem(_return);
}

void DeviceConfigServiceClient::send_nvReadItem(const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("nvReadItem", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvReadItem_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.subscriptionId = &subscriptionId;
  args.index = &index;
  args.returnConfig = &returnConfig;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_nvReadItem(NvData& _return)
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
  if (fname.compare("nvReadItem") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_nvReadItem_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvReadItem failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId)
{
  send_nvSetItem(nvItemNameOrId, valueList, subscriptionId);
  return recv_nvSetItem();
}

void DeviceConfigServiceClient::send_nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("nvSetItem", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvSetItem_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.valueList = &valueList;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_nvSetItem()
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
  if (fname.compare("nvSetItem") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_nvSetItem_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvSetItem failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId)
{
  send_nvSetOtpItem(nvItemNameOrId, valueList, subscriptionId);
  return recv_nvSetOtpItem();
}

void DeviceConfigServiceClient::send_nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("nvSetOtpItem", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvSetOtpItem_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.valueList = &valueList;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_nvSetOtpItem()
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
  if (fname.compare("nvSetOtpItem") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_nvSetOtpItem_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvSetOtpItem failed: unknown result");
}

void DeviceConfigServiceClient::nvGetAllItems(std::vector< ::Uts::NvItem> & _return)
{
  send_nvGetAllItems();
  recv_nvGetAllItems(_return);
}

void DeviceConfigServiceClient::send_nvGetAllItems()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("nvGetAllItems", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvGetAllItems_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_nvGetAllItems(std::vector< ::Uts::NvItem> & _return)
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
  if (fname.compare("nvGetAllItems") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_nvGetAllItems_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvGetAllItems failed: unknown result");
}

void DeviceConfigServiceClient::nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId)
{
  send_nvGetItemDefinition(nvItemNameOrId);
  recv_nvGetItemDefinition(_return);
}

void DeviceConfigServiceClient::send_nvGetItemDefinition(const std::string& nvItemNameOrId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("nvGetItemDefinition", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvGetItemDefinition_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_nvGetItemDefinition(std::string& _return)
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
  if (fname.compare("nvGetItemDefinition") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_nvGetItemDefinition_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvGetItemDefinition failed: unknown result");
}

bool DeviceConfigServiceClient::efsHasAlternateFileSystem()
{
  send_efsHasAlternateFileSystem();
  return recv_efsHasAlternateFileSystem();
}

void DeviceConfigServiceClient::send_efsHasAlternateFileSystem()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsHasAlternateFileSystem", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsHasAlternateFileSystem_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool DeviceConfigServiceClient::recv_efsHasAlternateFileSystem()
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
  if (fname.compare("efsHasAlternateFileSystem") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  DeviceConfigService_efsHasAlternateFileSystem_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsHasAlternateFileSystem failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsCreateDirectory(pathName, efsSystem);
  return recv_efsCreateDirectory();
}

void DeviceConfigServiceClient::send_efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsCreateDirectory", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsCreateDirectory_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_efsCreateDirectory()
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
  if (fname.compare("efsCreateDirectory") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_efsCreateDirectory_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsCreateDirectory failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsRemoveDirectory(pathName, efsSystem);
  return recv_efsRemoveDirectory();
}

void DeviceConfigServiceClient::send_efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsRemoveDirectory", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsRemoveDirectory_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_efsRemoveDirectory()
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
  if (fname.compare("efsRemoveDirectory") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_efsRemoveDirectory_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsRemoveDirectory failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem)
{
  send_efsRemoveTree(pathName, efsSytem);
  return recv_efsRemoveTree();
}

void DeviceConfigServiceClient::send_efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsRemoveTree", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsRemoveTree_pargs args;
  args.pathName = &pathName;
  args.efsSytem = &efsSytem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_efsRemoveTree()
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
  if (fname.compare("efsRemoveTree") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_efsRemoveTree_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsRemoveTree failed: unknown result");
}

void DeviceConfigServiceClient::efsGetDirectoryContents(std::vector<EfsItem> & _return, const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsGetDirectoryContents(pathName, efsSystem);
  recv_efsGetDirectoryContents(_return);
}

void DeviceConfigServiceClient::send_efsGetDirectoryContents(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsGetDirectoryContents", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetDirectoryContents_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_efsGetDirectoryContents(std::vector<EfsItem> & _return)
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
  if (fname.compare("efsGetDirectoryContents") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_efsGetDirectoryContents_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetDirectoryContents failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem)
{
  send_efsPutFile(pathName, buffer, efsSystem);
  return recv_efsPutFile();
}

void DeviceConfigServiceClient::send_efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsPutFile", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsPutFile_pargs args;
  args.pathName = &pathName;
  args.buffer = &buffer;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_efsPutFile()
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
  if (fname.compare("efsPutFile") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_efsPutFile_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsPutFile failed: unknown result");
}

void DeviceConfigServiceClient::efsGetFile(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsGetFile(pathName, efsSystem);
  recv_efsGetFile(_return);
}

void DeviceConfigServiceClient::send_efsGetFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsGetFile", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetFile_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_efsGetFile(std::string& _return)
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
  if (fname.compare("efsGetFile") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_efsGetFile_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetFile failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsDeleteFile(pathName, efsSystem);
  return recv_efsDeleteFile();
}

void DeviceConfigServiceClient::send_efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsDeleteFile", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsDeleteFile_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_efsDeleteFile()
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
  if (fname.compare("efsDeleteFile") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_efsDeleteFile_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsDeleteFile failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem)
{
  send_efsRename(existingName, newName, efsSystem);
  return recv_efsRename();
}

void DeviceConfigServiceClient::send_efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsRename", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsRename_pargs args;
  args.existingName = &existingName;
  args.newName = &newName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_efsRename()
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
  if (fname.compare("efsRename") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_efsRename_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsRename failed: unknown result");
}

bool DeviceConfigServiceClient::efsPathExists(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsPathExists(pathName, efsSystem);
  return recv_efsPathExists();
}

void DeviceConfigServiceClient::send_efsPathExists(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsPathExists", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsPathExists_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool DeviceConfigServiceClient::recv_efsPathExists()
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
  if (fname.compare("efsPathExists") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  DeviceConfigService_efsPathExists_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsPathExists failed: unknown result");
}

bool DeviceConfigServiceClient::efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsIsDirectory(pathName, efsSystem);
  return recv_efsIsDirectory();
}

void DeviceConfigServiceClient::send_efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsIsDirectory", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsIsDirectory_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool DeviceConfigServiceClient::recv_efsIsDirectory()
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
  if (fname.compare("efsIsDirectory") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  DeviceConfigService_efsIsDirectory_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsIsDirectory failed: unknown result");
}

bool DeviceConfigServiceClient::efsIsFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsIsFile(pathName, efsSystem);
  return recv_efsIsFile();
}

void DeviceConfigServiceClient::send_efsIsFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsIsFile", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsIsFile_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool DeviceConfigServiceClient::recv_efsIsFile()
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
  if (fname.compare("efsIsFile") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  DeviceConfigService_efsIsFile_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsIsFile failed: unknown result");
}

int64_t DeviceConfigServiceClient::efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsGetFileSize(pathName, efsSystem);
  return recv_efsGetFileSize();
}

void DeviceConfigServiceClient::send_efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsGetFileSize", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetFileSize_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int64_t DeviceConfigServiceClient::recv_efsGetFileSize()
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
  if (fname.compare("efsGetFileSize") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int64_t _return;
  DeviceConfigService_efsGetFileSize_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetFileSize failed: unknown result");
}

int64_t DeviceConfigServiceClient::efsGetAvailableSpace(const FileSystem::type efsSystem)
{
  send_efsGetAvailableSpace(efsSystem);
  return recv_efsGetAvailableSpace();
}

void DeviceConfigServiceClient::send_efsGetAvailableSpace(const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsGetAvailableSpace", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetAvailableSpace_pargs args;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int64_t DeviceConfigServiceClient::recv_efsGetAvailableSpace()
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
  if (fname.compare("efsGetAvailableSpace") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int64_t _return;
  DeviceConfigService_efsGetAvailableSpace_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetAvailableSpace failed: unknown result");
}

void DeviceConfigServiceClient::efsGetFileCheckSum(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsGetFileCheckSum(pathName, efsSystem);
  recv_efsGetFileCheckSum(_return);
}

void DeviceConfigServiceClient::send_efsGetFileCheckSum(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsGetFileCheckSum", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetFileCheckSum_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_efsGetFileCheckSum(std::string& _return)
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
  if (fname.compare("efsGetFileCheckSum") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_efsGetFileCheckSum_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetFileCheckSum failed: unknown result");
}

void DeviceConfigServiceClient::efsGetFileAttributes(EfsFileAttributes& _return, const std::string& pathName, const FileSystem::type efsSystem)
{
  send_efsGetFileAttributes(pathName, efsSystem);
  recv_efsGetFileAttributes(_return);
}

void DeviceConfigServiceClient::send_efsGetFileAttributes(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsGetFileAttributes", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetFileAttributes_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_efsGetFileAttributes(EfsFileAttributes& _return)
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
  if (fname.compare("efsGetFileAttributes") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_efsGetFileAttributes_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetFileAttributes failed: unknown result");
}

bool DeviceConfigServiceClient::efsIsReady()
{
  send_efsIsReady();
  return recv_efsIsReady();
}

void DeviceConfigServiceClient::send_efsIsReady()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsIsReady", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsIsReady_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool DeviceConfigServiceClient::recv_efsIsReady()
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
  if (fname.compare("efsIsReady") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  DeviceConfigService_efsIsReady_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsIsReady failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_createGoldenCopy(pathName, efsSystem);
  return recv_createGoldenCopy();
}

void DeviceConfigServiceClient::send_createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("createGoldenCopy", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_createGoldenCopy_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_createGoldenCopy()
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
  if (fname.compare("createGoldenCopy") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_createGoldenCopy_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "createGoldenCopy failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem)
{
  send_createCefsCopy(cefsSavePath, efsSystem);
  return recv_createCefsCopy();
}

void DeviceConfigServiceClient::send_createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("createCefsCopy", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_createCefsCopy_pargs args;
  args.cefsSavePath = &cefsSavePath;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_createCefsCopy()
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
  if (fname.compare("createCefsCopy") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_createCefsCopy_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "createCefsCopy failed: unknown result");
}

void DeviceConfigServiceClient::requestPrl(std::string& _return, const int32_t subscriptionId, const int8_t index)
{
  send_requestPrl(subscriptionId, index);
  recv_requestPrl(_return);
}

void DeviceConfigServiceClient::send_requestPrl(const int32_t subscriptionId, const int8_t index)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("requestPrl", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_requestPrl_pargs args;
  args.subscriptionId = &subscriptionId;
  args.index = &index;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_requestPrl(std::string& _return)
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
  if (fname.compare("requestPrl") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_requestPrl_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "requestPrl failed: unknown result");
}

void DeviceConfigServiceClient::backupPrl(std::string& _return)
{
  send_backupPrl();
  recv_backupPrl(_return);
}

void DeviceConfigServiceClient::send_backupPrl()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("backupPrl", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_backupPrl_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_backupPrl(std::string& _return)
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
  if (fname.compare("backupPrl") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_backupPrl_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "backupPrl failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::restorePrl(const std::string& xqcnFileContents)
{
  send_restorePrl(xqcnFileContents);
  return recv_restorePrl();
}

void DeviceConfigServiceClient::send_restorePrl(const std::string& xqcnFileContents)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("restorePrl", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_restorePrl_pargs args;
  args.xqcnFileContents = &xqcnFileContents;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_restorePrl()
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
  if (fname.compare("restorePrl") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_restorePrl_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "restorePrl failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents)
{
  send_sendPrl(subscriptionId, index, prlFileContents);
  return recv_sendPrl();
}

void DeviceConfigServiceClient::send_sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("sendPrl", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_sendPrl_pargs args;
  args.subscriptionId = &subscriptionId;
  args.index = &index;
  args.prlFileContents = &prlFileContents;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_sendPrl()
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
  if (fname.compare("sendPrl") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_sendPrl_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "sendPrl failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem)
{
  send_forceEfsSync(pathName, efsSystem);
  return recv_forceEfsSync();
}

void DeviceConfigServiceClient::send_forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("forceEfsSync", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_forceEfsSync_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_forceEfsSync()
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
  if (fname.compare("forceEfsSync") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_forceEfsSync_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "forceEfsSync failed: unknown result");
}

int32_t DeviceConfigServiceClient::getEsn()
{
  send_getEsn();
  return recv_getEsn();
}

void DeviceConfigServiceClient::send_getEsn()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getEsn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getEsn_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int32_t DeviceConfigServiceClient::recv_getEsn()
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
  if (fname.compare("getEsn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int32_t _return;
  DeviceConfigService_getEsn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getEsn failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::setEsn(const int32_t esn)
{
  send_setEsn(esn);
  return recv_setEsn();
}

void DeviceConfigServiceClient::send_setEsn(const int32_t esn)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("setEsn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_setEsn_pargs args;
  args.esn = &esn;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_setEsn()
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
  if (fname.compare("setEsn") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_setEsn_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "setEsn failed: unknown result");
}

void DeviceConfigServiceClient::getImei(std::string& _return, const int32_t subscriptionId)
{
  send_getImei(subscriptionId);
  recv_getImei(_return);
}

void DeviceConfigServiceClient::send_getImei(const int32_t subscriptionId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getImei", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getImei_pargs args;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_getImei(std::string& _return)
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
  if (fname.compare("getImei") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_getImei_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getImei failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::setImei(const std::string& imei, const int32_t subscriptionId)
{
  send_setImei(imei, subscriptionId);
  return recv_setImei();
}

void DeviceConfigServiceClient::send_setImei(const std::string& imei, const int32_t subscriptionId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("setImei", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_setImei_pargs args;
  args.imei = &imei;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_setImei()
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
  if (fname.compare("setImei") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_setImei_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "setImei failed: unknown result");
}

int64_t DeviceConfigServiceClient::getMeid(const int32_t subscriptionId)
{
  send_getMeid(subscriptionId);
  return recv_getMeid();
}

void DeviceConfigServiceClient::send_getMeid(const int32_t subscriptionId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("getMeid", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getMeid_pargs args;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

int64_t DeviceConfigServiceClient::recv_getMeid()
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
  if (fname.compare("getMeid") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  int64_t _return;
  DeviceConfigService_getMeid_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getMeid failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::setMeid(const int64_t meid, const int32_t subscriptionId)
{
  send_setMeid(meid, subscriptionId);
  return recv_setMeid();
}

void DeviceConfigServiceClient::send_setMeid(const int64_t meid, const int32_t subscriptionId)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("setMeid", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_setMeid_pargs args;
  args.meid = &meid;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_setMeid()
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
  if (fname.compare("setMeid") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_setMeid_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "setMeid failed: unknown result");
}

bool DeviceConfigServiceClient::checkSpc(const std::string& spc)
{
  send_checkSpc(spc);
  return recv_checkSpc();
}

void DeviceConfigServiceClient::send_checkSpc(const std::string& spc)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("checkSpc", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_checkSpc_pargs args;
  args.spc = &spc;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool DeviceConfigServiceClient::recv_checkSpc()
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
  if (fname.compare("checkSpc") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  DeviceConfigService_checkSpc_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "checkSpc failed: unknown result");
}

bool DeviceConfigServiceClient::provisionSpc(const std::string& currentSpc, const std::string& newSpc)
{
  send_provisionSpc(currentSpc, newSpc);
  return recv_provisionSpc();
}

void DeviceConfigServiceClient::send_provisionSpc(const std::string& currentSpc, const std::string& newSpc)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("provisionSpc", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_provisionSpc_pargs args;
  args.currentSpc = &currentSpc;
  args.newSpc = &newSpc;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool DeviceConfigServiceClient::recv_provisionSpc()
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
  if (fname.compare("provisionSpc") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  DeviceConfigService_provisionSpc_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "provisionSpc failed: unknown result");
}

void DeviceConfigServiceClient::efsReadFromModemLog(std::string& _return)
{
  send_efsReadFromModemLog();
  recv_efsReadFromModemLog(_return);
}

void DeviceConfigServiceClient::send_efsReadFromModemLog()
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("efsReadFromModemLog", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsReadFromModemLog_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

void DeviceConfigServiceClient::recv_efsReadFromModemLog(std::string& _return)
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
  if (fname.compare("efsReadFromModemLog") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  DeviceConfigService_efsReadFromModemLog_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsReadFromModemLog failed: unknown result");
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::configureService(const DeviceConfigOptions& deviceConfigOptions)
{
  send_configureService(deviceConfigOptions);
  return recv_configureService();
}

void DeviceConfigServiceClient::send_configureService(const DeviceConfigOptions& deviceConfigOptions)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("configureService", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_configureService_pargs args;
  args.deviceConfigOptions = &deviceConfigOptions;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

 ::Uts::ErrorCode::type DeviceConfigServiceClient::recv_configureService()
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
  if (fname.compare("configureService") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
   ::Uts::ErrorCode::type _return;
  DeviceConfigService_configureService_presult result;
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
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "configureService failed: unknown result");
}

bool DeviceConfigServiceProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
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

void DeviceConfigServiceProcessor::process_getLastError(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.getLastError", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.getLastError");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.getLastError");
  }

  DeviceConfigService_getLastError_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.getLastError", bytes);
  }

  DeviceConfigService_getLastError_result result;
  try {
    iface_->getLastError(result.success);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.getLastError");
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
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.getLastError");
  }

  oprot->writeMessageBegin("getLastError", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.getLastError", bytes);
  }
}

void DeviceConfigServiceProcessor::process_getDevice(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.getDevice", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.getDevice");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.getDevice");
  }

  DeviceConfigService_getDevice_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.getDevice", bytes);
  }

  DeviceConfigService_getDevice_result result;
  try {
    result.success = iface_->getDevice();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.getDevice");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("getDevice", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.getDevice");
  }

  oprot->writeMessageBegin("getDevice", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.getDevice", bytes);
  }
}

void DeviceConfigServiceProcessor::process_initializeService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.initializeService", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.initializeService");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.initializeService");
  }

  DeviceConfigService_initializeService_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.initializeService", bytes);
  }

  DeviceConfigService_initializeService_result result;
  try {
    result.success = iface_->initializeService();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.initializeService");
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
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.initializeService");
  }

  oprot->writeMessageBegin("initializeService", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.initializeService", bytes);
  }
}

void DeviceConfigServiceProcessor::process_initializeServiceByProtocol(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.initializeServiceByProtocol", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.initializeServiceByProtocol");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.initializeServiceByProtocol");
  }

  DeviceConfigService_initializeServiceByProtocol_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.initializeServiceByProtocol", bytes);
  }

  DeviceConfigService_initializeServiceByProtocol_result result;
  try {
    result.success = iface_->initializeServiceByProtocol(args.diagProtocolHandle, args.qmiProtocolHandle);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.initializeServiceByProtocol");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("initializeServiceByProtocol", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.initializeServiceByProtocol");
  }

  oprot->writeMessageBegin("initializeServiceByProtocol", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.initializeServiceByProtocol", bytes);
  }
}

void DeviceConfigServiceProcessor::process_initializeServiceWithOptions(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.initializeServiceWithOptions", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.initializeServiceWithOptions");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.initializeServiceWithOptions");
  }

  DeviceConfigService_initializeServiceWithOptions_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.initializeServiceWithOptions", bytes);
  }

  DeviceConfigService_initializeServiceWithOptions_result result;
  try {
    result.success = iface_->initializeServiceWithOptions(args.connectionOptions);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.initializeServiceWithOptions");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("initializeServiceWithOptions", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.initializeServiceWithOptions");
  }

  oprot->writeMessageBegin("initializeServiceWithOptions", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.initializeServiceWithOptions", bytes);
  }
}

void DeviceConfigServiceProcessor::process_destroyService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.destroyService", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.destroyService");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.destroyService");
  }

  DeviceConfigService_destroyService_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.destroyService", bytes);
  }

  DeviceConfigService_destroyService_result result;
  try {
    result.success = iface_->destroyService();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.destroyService");
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
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.destroyService");
  }

  oprot->writeMessageBegin("destroyService", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.destroyService", bytes);
  }
}

void DeviceConfigServiceProcessor::process_doXqcnOperation(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.doXqcnOperation", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.doXqcnOperation");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.doXqcnOperation");
  }

  DeviceConfigService_doXqcnOperation_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.doXqcnOperation", bytes);
  }

  DeviceConfigService_doXqcnOperation_result result;
  try {
    iface_->doXqcnOperation(result.success, args.deviceConfigOptions);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.doXqcnOperation");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("doXqcnOperation", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.doXqcnOperation");
  }

  oprot->writeMessageBegin("doXqcnOperation", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.doXqcnOperation", bytes);
  }
}

void DeviceConfigServiceProcessor::process_backupToXqcn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.backupToXqcn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.backupToXqcn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.backupToXqcn");
  }

  DeviceConfigService_backupToXqcn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.backupToXqcn", bytes);
  }

  DeviceConfigService_backupToXqcn_result result;
  try {
    iface_->backupToXqcn(result.success, args.serviceProgrammingCode, args.resetUponCompletion, args.resetTimeout, args.filterFileContents);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.backupToXqcn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("backupToXqcn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.backupToXqcn");
  }

  oprot->writeMessageBegin("backupToXqcn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.backupToXqcn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_restoreFromXqcn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.restoreFromXqcn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.restoreFromXqcn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.restoreFromXqcn");
  }

  DeviceConfigService_restoreFromXqcn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.restoreFromXqcn", bytes);
  }

  DeviceConfigService_restoreFromXqcn_result result;
  try {
    result.success = iface_->restoreFromXqcn(args.xqcnFileContents, args.serviceProgrammingCode, args.allowEsnMismatch, args.resetUponCompletion, args.resetTimeout, args.filterFileContents);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.restoreFromXqcn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("restoreFromXqcn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.restoreFromXqcn");
  }

  oprot->writeMessageBegin("restoreFromXqcn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.restoreFromXqcn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetMbnMaxStorage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetMbnMaxStorage", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetMbnMaxStorage");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetMbnMaxStorage");
  }

  DeviceConfigService_pdcGetMbnMaxStorage_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetMbnMaxStorage", bytes);
  }

  DeviceConfigService_pdcGetMbnMaxStorage_result result;
  try {
    result.success = iface_->pdcGetMbnMaxStorage(args.mbnType);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetMbnMaxStorage");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetMbnMaxStorage", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetMbnMaxStorage");
  }

  oprot->writeMessageBegin("pdcGetMbnMaxStorage", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetMbnMaxStorage", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetMbnStorageUsage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetMbnStorageUsage", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetMbnStorageUsage");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetMbnStorageUsage");
  }

  DeviceConfigService_pdcGetMbnStorageUsage_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetMbnStorageUsage", bytes);
  }

  DeviceConfigService_pdcGetMbnStorageUsage_result result;
  try {
    result.success = iface_->pdcGetMbnStorageUsage(args.mbnType);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetMbnStorageUsage");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetMbnStorageUsage", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetMbnStorageUsage");
  }

  oprot->writeMessageBegin("pdcGetMbnStorageUsage", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetMbnStorageUsage", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetMbnCount(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetMbnCount", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetMbnCount");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetMbnCount");
  }

  DeviceConfigService_pdcGetMbnCount_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetMbnCount", bytes);
  }

  DeviceConfigService_pdcGetMbnCount_result result;
  try {
    result.success = iface_->pdcGetMbnCount(args.mbnType);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetMbnCount");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetMbnCount", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetMbnCount");
  }

  oprot->writeMessageBegin("pdcGetMbnCount", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetMbnCount", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetMbnList(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetMbnList", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetMbnList");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetMbnList");
  }

  DeviceConfigService_pdcGetMbnList_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetMbnList", bytes);
  }

  DeviceConfigService_pdcGetMbnList_result result;
  try {
    iface_->pdcGetMbnList(result.success, args.mbnType);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetMbnList");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetMbnList", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetMbnList");
  }

  oprot->writeMessageBegin("pdcGetMbnList", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetMbnList", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetDefaultMbnInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetDefaultMbnInfo", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetDefaultMbnInfo");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetDefaultMbnInfo");
  }

  DeviceConfigService_pdcGetDefaultMbnInfo_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetDefaultMbnInfo", bytes);
  }

  DeviceConfigService_pdcGetDefaultMbnInfo_result result;
  try {
    iface_->pdcGetDefaultMbnInfo(result.success, args.mbnType);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetDefaultMbnInfo");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetDefaultMbnInfo", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetDefaultMbnInfo");
  }

  oprot->writeMessageBegin("pdcGetDefaultMbnInfo", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetDefaultMbnInfo", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetMbnId(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetMbnId", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetMbnId");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetMbnId");
  }

  DeviceConfigService_pdcGetMbnId_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetMbnId", bytes);
  }

  DeviceConfigService_pdcGetMbnId_result result;
  try {
    iface_->pdcGetMbnId(result.success, args.mbnContent);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetMbnId");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetMbnId", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetMbnId");
  }

  oprot->writeMessageBegin("pdcGetMbnId", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetMbnId", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcWriteMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcWriteMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcWriteMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcWriteMbn");
  }

  DeviceConfigService_pdcWriteMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcWriteMbn", bytes);
  }

  DeviceConfigService_pdcWriteMbn_result result;
  try {
    result.success = iface_->pdcWriteMbn(args.mbnType, args.mbnContent);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcWriteMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcWriteMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcWriteMbn");
  }

  oprot->writeMessageBegin("pdcWriteMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcWriteMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcReadMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcReadMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcReadMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcReadMbn");
  }

  DeviceConfigService_pdcReadMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcReadMbn", bytes);
  }

  DeviceConfigService_pdcReadMbn_result result;
  try {
    iface_->pdcReadMbn(result.success, args.mbnType, args.mbnId, args.subId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcReadMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcReadMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcReadMbn");
  }

  oprot->writeMessageBegin("pdcReadMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcReadMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcRemoveMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcRemoveMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcRemoveMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcRemoveMbn");
  }

  DeviceConfigService_pdcRemoveMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcRemoveMbn", bytes);
  }

  DeviceConfigService_pdcRemoveMbn_result result;
  try {
    result.success = iface_->pdcRemoveMbn(args.mbnType, args.mbnId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcRemoveMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcRemoveMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcRemoveMbn");
  }

  oprot->writeMessageBegin("pdcRemoveMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcRemoveMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetActiveMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetActiveMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetActiveMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetActiveMbn");
  }

  DeviceConfigService_pdcGetActiveMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetActiveMbn", bytes);
  }

  DeviceConfigService_pdcGetActiveMbn_result result;
  try {
    iface_->pdcGetActiveMbn(result.success, args.mbnType, args.subId, args.slotId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetActiveMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetActiveMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetActiveMbn");
  }

  oprot->writeMessageBegin("pdcGetActiveMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetActiveMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetPendingMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetPendingMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetPendingMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetPendingMbn");
  }

  DeviceConfigService_pdcGetPendingMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetPendingMbn", bytes);
  }

  DeviceConfigService_pdcGetPendingMbn_result result;
  try {
    iface_->pdcGetPendingMbn(result.success, args.mbnType, args.subId, args.slotId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetPendingMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetPendingMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetPendingMbn");
  }

  oprot->writeMessageBegin("pdcGetPendingMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetPendingMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcValidateMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcValidateMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcValidateMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcValidateMbn");
  }

  DeviceConfigService_pdcValidateMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcValidateMbn", bytes);
  }

  DeviceConfigService_pdcValidateMbn_result result;
  try {
    iface_->pdcValidateMbn(result.success, args.mbnType, args.mbnId, args.subId, args.remotePath);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcValidateMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcValidateMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcValidateMbn");
  }

  oprot->writeMessageBegin("pdcValidateMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcValidateMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcSelectMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcSelectMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcSelectMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcSelectMbn");
  }

  DeviceConfigService_pdcSelectMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcSelectMbn", bytes);
  }

  DeviceConfigService_pdcSelectMbn_result result;
  try {
    result.success = iface_->pdcSelectMbn(args.mbnType, args.mbnId, args.subId, args.slotId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcSelectMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcSelectMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcSelectMbn");
  }

  oprot->writeMessageBegin("pdcSelectMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcSelectMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcActivateMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcActivateMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcActivateMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcActivateMbn");
  }

  DeviceConfigService_pdcActivateMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcActivateMbn", bytes);
  }

  DeviceConfigService_pdcActivateMbn_result result;
  try {
    result.success = iface_->pdcActivateMbn(args.mbnType, args.subId, args.slotId, args.mode, args.timeout);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcActivateMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcActivateMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcActivateMbn");
  }

  oprot->writeMessageBegin("pdcActivateMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcActivateMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcDeactivateMbn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcDeactivateMbn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcDeactivateMbn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcDeactivateMbn");
  }

  DeviceConfigService_pdcDeactivateMbn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcDeactivateMbn", bytes);
  }

  DeviceConfigService_pdcDeactivateMbn_result result;
  try {
    result.success = iface_->pdcDeactivateMbn(args.mbnType, args.subId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcDeactivateMbn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcDeactivateMbn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcDeactivateMbn");
  }

  oprot->writeMessageBegin("pdcDeactivateMbn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcDeactivateMbn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcGetConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcGetConfiguration", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcGetConfiguration");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcGetConfiguration");
  }

  DeviceConfigService_pdcGetConfiguration_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcGetConfiguration", bytes);
  }

  DeviceConfigService_pdcGetConfiguration_result result;
  try {
    result.success = iface_->pdcGetConfiguration(args.slotId, args.feature);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcGetConfiguration");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcGetConfiguration", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcGetConfiguration");
  }

  oprot->writeMessageBegin("pdcGetConfiguration", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcGetConfiguration", bytes);
  }
}

void DeviceConfigServiceProcessor::process_pdcSetConfiguration(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.pdcSetConfiguration", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.pdcSetConfiguration");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.pdcSetConfiguration");
  }

  DeviceConfigService_pdcSetConfiguration_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.pdcSetConfiguration", bytes);
  }

  DeviceConfigService_pdcSetConfiguration_result result;
  try {
    result.success = iface_->pdcSetConfiguration(args.slotId, args.feature, args.value);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.pdcSetConfiguration");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("pdcSetConfiguration", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.pdcSetConfiguration");
  }

  oprot->writeMessageBegin("pdcSetConfiguration", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.pdcSetConfiguration", bytes);
  }
}

void DeviceConfigServiceProcessor::process_nvIsItemSupported(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.nvIsItemSupported", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.nvIsItemSupported");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.nvIsItemSupported");
  }

  DeviceConfigService_nvIsItemSupported_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.nvIsItemSupported", bytes);
  }

  DeviceConfigService_nvIsItemSupported_result result;
  try {
    result.success = iface_->nvIsItemSupported(args.nvItemNameOrId, args.subscriptionId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.nvIsItemSupported");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("nvIsItemSupported", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.nvIsItemSupported");
  }

  oprot->writeMessageBegin("nvIsItemSupported", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.nvIsItemSupported", bytes);
  }
}

void DeviceConfigServiceProcessor::process_nvReadItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.nvReadItem", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.nvReadItem");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.nvReadItem");
  }

  DeviceConfigService_nvReadItem_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.nvReadItem", bytes);
  }

  DeviceConfigService_nvReadItem_result result;
  try {
    iface_->nvReadItem(result.success, args.nvItemNameOrId, args.subscriptionId, args.index, args.returnConfig);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.nvReadItem");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("nvReadItem", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.nvReadItem");
  }

  oprot->writeMessageBegin("nvReadItem", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.nvReadItem", bytes);
  }
}

void DeviceConfigServiceProcessor::process_nvSetItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.nvSetItem", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.nvSetItem");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.nvSetItem");
  }

  DeviceConfigService_nvSetItem_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.nvSetItem", bytes);
  }

  DeviceConfigService_nvSetItem_result result;
  try {
    result.success = iface_->nvSetItem(args.nvItemNameOrId, args.valueList, args.subscriptionId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.nvSetItem");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("nvSetItem", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.nvSetItem");
  }

  oprot->writeMessageBegin("nvSetItem", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.nvSetItem", bytes);
  }
}

void DeviceConfigServiceProcessor::process_nvSetOtpItem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.nvSetOtpItem", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.nvSetOtpItem");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.nvSetOtpItem");
  }

  DeviceConfigService_nvSetOtpItem_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.nvSetOtpItem", bytes);
  }

  DeviceConfigService_nvSetOtpItem_result result;
  try {
    result.success = iface_->nvSetOtpItem(args.nvItemNameOrId, args.valueList, args.subscriptionId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.nvSetOtpItem");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("nvSetOtpItem", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.nvSetOtpItem");
  }

  oprot->writeMessageBegin("nvSetOtpItem", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.nvSetOtpItem", bytes);
  }
}

void DeviceConfigServiceProcessor::process_nvGetAllItems(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.nvGetAllItems", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.nvGetAllItems");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.nvGetAllItems");
  }

  DeviceConfigService_nvGetAllItems_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.nvGetAllItems", bytes);
  }

  DeviceConfigService_nvGetAllItems_result result;
  try {
    iface_->nvGetAllItems(result.success);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.nvGetAllItems");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("nvGetAllItems", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.nvGetAllItems");
  }

  oprot->writeMessageBegin("nvGetAllItems", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.nvGetAllItems", bytes);
  }
}

void DeviceConfigServiceProcessor::process_nvGetItemDefinition(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.nvGetItemDefinition", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.nvGetItemDefinition");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.nvGetItemDefinition");
  }

  DeviceConfigService_nvGetItemDefinition_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.nvGetItemDefinition", bytes);
  }

  DeviceConfigService_nvGetItemDefinition_result result;
  try {
    iface_->nvGetItemDefinition(result.success, args.nvItemNameOrId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.nvGetItemDefinition");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("nvGetItemDefinition", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.nvGetItemDefinition");
  }

  oprot->writeMessageBegin("nvGetItemDefinition", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.nvGetItemDefinition", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsHasAlternateFileSystem(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsHasAlternateFileSystem", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsHasAlternateFileSystem");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsHasAlternateFileSystem");
  }

  DeviceConfigService_efsHasAlternateFileSystem_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsHasAlternateFileSystem", bytes);
  }

  DeviceConfigService_efsHasAlternateFileSystem_result result;
  try {
    result.success = iface_->efsHasAlternateFileSystem();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsHasAlternateFileSystem");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsHasAlternateFileSystem", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsHasAlternateFileSystem");
  }

  oprot->writeMessageBegin("efsHasAlternateFileSystem", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsHasAlternateFileSystem", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsCreateDirectory(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsCreateDirectory", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsCreateDirectory");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsCreateDirectory");
  }

  DeviceConfigService_efsCreateDirectory_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsCreateDirectory", bytes);
  }

  DeviceConfigService_efsCreateDirectory_result result;
  try {
    result.success = iface_->efsCreateDirectory(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsCreateDirectory");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsCreateDirectory", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsCreateDirectory");
  }

  oprot->writeMessageBegin("efsCreateDirectory", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsCreateDirectory", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsRemoveDirectory(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsRemoveDirectory", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsRemoveDirectory");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsRemoveDirectory");
  }

  DeviceConfigService_efsRemoveDirectory_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsRemoveDirectory", bytes);
  }

  DeviceConfigService_efsRemoveDirectory_result result;
  try {
    result.success = iface_->efsRemoveDirectory(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsRemoveDirectory");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsRemoveDirectory", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsRemoveDirectory");
  }

  oprot->writeMessageBegin("efsRemoveDirectory", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsRemoveDirectory", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsRemoveTree(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsRemoveTree", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsRemoveTree");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsRemoveTree");
  }

  DeviceConfigService_efsRemoveTree_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsRemoveTree", bytes);
  }

  DeviceConfigService_efsRemoveTree_result result;
  try {
    result.success = iface_->efsRemoveTree(args.pathName, args.efsSytem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsRemoveTree");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsRemoveTree", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsRemoveTree");
  }

  oprot->writeMessageBegin("efsRemoveTree", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsRemoveTree", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsGetDirectoryContents(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsGetDirectoryContents", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsGetDirectoryContents");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsGetDirectoryContents");
  }

  DeviceConfigService_efsGetDirectoryContents_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsGetDirectoryContents", bytes);
  }

  DeviceConfigService_efsGetDirectoryContents_result result;
  try {
    iface_->efsGetDirectoryContents(result.success, args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsGetDirectoryContents");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsGetDirectoryContents", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsGetDirectoryContents");
  }

  oprot->writeMessageBegin("efsGetDirectoryContents", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsGetDirectoryContents", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsPutFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsPutFile", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsPutFile");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsPutFile");
  }

  DeviceConfigService_efsPutFile_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsPutFile", bytes);
  }

  DeviceConfigService_efsPutFile_result result;
  try {
    result.success = iface_->efsPutFile(args.pathName, args.buffer, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsPutFile");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsPutFile", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsPutFile");
  }

  oprot->writeMessageBegin("efsPutFile", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsPutFile", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsGetFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsGetFile", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsGetFile");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsGetFile");
  }

  DeviceConfigService_efsGetFile_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsGetFile", bytes);
  }

  DeviceConfigService_efsGetFile_result result;
  try {
    iface_->efsGetFile(result.success, args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsGetFile");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsGetFile", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsGetFile");
  }

  oprot->writeMessageBegin("efsGetFile", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsGetFile", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsDeleteFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsDeleteFile", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsDeleteFile");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsDeleteFile");
  }

  DeviceConfigService_efsDeleteFile_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsDeleteFile", bytes);
  }

  DeviceConfigService_efsDeleteFile_result result;
  try {
    result.success = iface_->efsDeleteFile(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsDeleteFile");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsDeleteFile", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsDeleteFile");
  }

  oprot->writeMessageBegin("efsDeleteFile", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsDeleteFile", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsRename(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsRename", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsRename");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsRename");
  }

  DeviceConfigService_efsRename_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsRename", bytes);
  }

  DeviceConfigService_efsRename_result result;
  try {
    result.success = iface_->efsRename(args.existingName, args.newName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsRename");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsRename", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsRename");
  }

  oprot->writeMessageBegin("efsRename", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsRename", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsPathExists(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsPathExists", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsPathExists");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsPathExists");
  }

  DeviceConfigService_efsPathExists_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsPathExists", bytes);
  }

  DeviceConfigService_efsPathExists_result result;
  try {
    result.success = iface_->efsPathExists(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsPathExists");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsPathExists", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsPathExists");
  }

  oprot->writeMessageBegin("efsPathExists", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsPathExists", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsIsDirectory(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsIsDirectory", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsIsDirectory");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsIsDirectory");
  }

  DeviceConfigService_efsIsDirectory_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsIsDirectory", bytes);
  }

  DeviceConfigService_efsIsDirectory_result result;
  try {
    result.success = iface_->efsIsDirectory(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsIsDirectory");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsIsDirectory", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsIsDirectory");
  }

  oprot->writeMessageBegin("efsIsDirectory", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsIsDirectory", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsIsFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsIsFile", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsIsFile");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsIsFile");
  }

  DeviceConfigService_efsIsFile_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsIsFile", bytes);
  }

  DeviceConfigService_efsIsFile_result result;
  try {
    result.success = iface_->efsIsFile(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsIsFile");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsIsFile", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsIsFile");
  }

  oprot->writeMessageBegin("efsIsFile", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsIsFile", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsGetFileSize(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsGetFileSize", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsGetFileSize");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsGetFileSize");
  }

  DeviceConfigService_efsGetFileSize_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsGetFileSize", bytes);
  }

  DeviceConfigService_efsGetFileSize_result result;
  try {
    result.success = iface_->efsGetFileSize(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsGetFileSize");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsGetFileSize", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsGetFileSize");
  }

  oprot->writeMessageBegin("efsGetFileSize", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsGetFileSize", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsGetAvailableSpace(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsGetAvailableSpace", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsGetAvailableSpace");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsGetAvailableSpace");
  }

  DeviceConfigService_efsGetAvailableSpace_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsGetAvailableSpace", bytes);
  }

  DeviceConfigService_efsGetAvailableSpace_result result;
  try {
    result.success = iface_->efsGetAvailableSpace(args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsGetAvailableSpace");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsGetAvailableSpace", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsGetAvailableSpace");
  }

  oprot->writeMessageBegin("efsGetAvailableSpace", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsGetAvailableSpace", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsGetFileCheckSum(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsGetFileCheckSum", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsGetFileCheckSum");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsGetFileCheckSum");
  }

  DeviceConfigService_efsGetFileCheckSum_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsGetFileCheckSum", bytes);
  }

  DeviceConfigService_efsGetFileCheckSum_result result;
  try {
    iface_->efsGetFileCheckSum(result.success, args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsGetFileCheckSum");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsGetFileCheckSum", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsGetFileCheckSum");
  }

  oprot->writeMessageBegin("efsGetFileCheckSum", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsGetFileCheckSum", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsGetFileAttributes(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsGetFileAttributes", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsGetFileAttributes");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsGetFileAttributes");
  }

  DeviceConfigService_efsGetFileAttributes_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsGetFileAttributes", bytes);
  }

  DeviceConfigService_efsGetFileAttributes_result result;
  try {
    iface_->efsGetFileAttributes(result.success, args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsGetFileAttributes");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsGetFileAttributes", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsGetFileAttributes");
  }

  oprot->writeMessageBegin("efsGetFileAttributes", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsGetFileAttributes", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsIsReady(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsIsReady", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsIsReady");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsIsReady");
  }

  DeviceConfigService_efsIsReady_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsIsReady", bytes);
  }

  DeviceConfigService_efsIsReady_result result;
  try {
    result.success = iface_->efsIsReady();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsIsReady");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsIsReady", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsIsReady");
  }

  oprot->writeMessageBegin("efsIsReady", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsIsReady", bytes);
  }
}

void DeviceConfigServiceProcessor::process_createGoldenCopy(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.createGoldenCopy", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.createGoldenCopy");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.createGoldenCopy");
  }

  DeviceConfigService_createGoldenCopy_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.createGoldenCopy", bytes);
  }

  DeviceConfigService_createGoldenCopy_result result;
  try {
    result.success = iface_->createGoldenCopy(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.createGoldenCopy");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("createGoldenCopy", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.createGoldenCopy");
  }

  oprot->writeMessageBegin("createGoldenCopy", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.createGoldenCopy", bytes);
  }
}

void DeviceConfigServiceProcessor::process_createCefsCopy(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.createCefsCopy", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.createCefsCopy");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.createCefsCopy");
  }

  DeviceConfigService_createCefsCopy_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.createCefsCopy", bytes);
  }

  DeviceConfigService_createCefsCopy_result result;
  try {
    result.success = iface_->createCefsCopy(args.cefsSavePath, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.createCefsCopy");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("createCefsCopy", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.createCefsCopy");
  }

  oprot->writeMessageBegin("createCefsCopy", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.createCefsCopy", bytes);
  }
}

void DeviceConfigServiceProcessor::process_requestPrl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.requestPrl", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.requestPrl");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.requestPrl");
  }

  DeviceConfigService_requestPrl_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.requestPrl", bytes);
  }

  DeviceConfigService_requestPrl_result result;
  try {
    iface_->requestPrl(result.success, args.subscriptionId, args.index);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.requestPrl");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("requestPrl", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.requestPrl");
  }

  oprot->writeMessageBegin("requestPrl", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.requestPrl", bytes);
  }
}

void DeviceConfigServiceProcessor::process_backupPrl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.backupPrl", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.backupPrl");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.backupPrl");
  }

  DeviceConfigService_backupPrl_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.backupPrl", bytes);
  }

  DeviceConfigService_backupPrl_result result;
  try {
    iface_->backupPrl(result.success);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.backupPrl");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("backupPrl", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.backupPrl");
  }

  oprot->writeMessageBegin("backupPrl", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.backupPrl", bytes);
  }
}

void DeviceConfigServiceProcessor::process_restorePrl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.restorePrl", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.restorePrl");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.restorePrl");
  }

  DeviceConfigService_restorePrl_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.restorePrl", bytes);
  }

  DeviceConfigService_restorePrl_result result;
  try {
    result.success = iface_->restorePrl(args.xqcnFileContents);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.restorePrl");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("restorePrl", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.restorePrl");
  }

  oprot->writeMessageBegin("restorePrl", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.restorePrl", bytes);
  }
}

void DeviceConfigServiceProcessor::process_sendPrl(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.sendPrl", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.sendPrl");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.sendPrl");
  }

  DeviceConfigService_sendPrl_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.sendPrl", bytes);
  }

  DeviceConfigService_sendPrl_result result;
  try {
    result.success = iface_->sendPrl(args.subscriptionId, args.index, args.prlFileContents);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.sendPrl");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("sendPrl", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.sendPrl");
  }

  oprot->writeMessageBegin("sendPrl", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.sendPrl", bytes);
  }
}

void DeviceConfigServiceProcessor::process_forceEfsSync(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.forceEfsSync", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.forceEfsSync");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.forceEfsSync");
  }

  DeviceConfigService_forceEfsSync_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.forceEfsSync", bytes);
  }

  DeviceConfigService_forceEfsSync_result result;
  try {
    result.success = iface_->forceEfsSync(args.pathName, args.efsSystem);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.forceEfsSync");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("forceEfsSync", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.forceEfsSync");
  }

  oprot->writeMessageBegin("forceEfsSync", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.forceEfsSync", bytes);
  }
}

void DeviceConfigServiceProcessor::process_getEsn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.getEsn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.getEsn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.getEsn");
  }

  DeviceConfigService_getEsn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.getEsn", bytes);
  }

  DeviceConfigService_getEsn_result result;
  try {
    result.success = iface_->getEsn();
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.getEsn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("getEsn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.getEsn");
  }

  oprot->writeMessageBegin("getEsn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.getEsn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_setEsn(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.setEsn", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.setEsn");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.setEsn");
  }

  DeviceConfigService_setEsn_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.setEsn", bytes);
  }

  DeviceConfigService_setEsn_result result;
  try {
    result.success = iface_->setEsn(args.esn);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.setEsn");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("setEsn", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.setEsn");
  }

  oprot->writeMessageBegin("setEsn", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.setEsn", bytes);
  }
}

void DeviceConfigServiceProcessor::process_getImei(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.getImei", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.getImei");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.getImei");
  }

  DeviceConfigService_getImei_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.getImei", bytes);
  }

  DeviceConfigService_getImei_result result;
  try {
    iface_->getImei(result.success, args.subscriptionId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.getImei");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("getImei", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.getImei");
  }

  oprot->writeMessageBegin("getImei", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.getImei", bytes);
  }
}

void DeviceConfigServiceProcessor::process_setImei(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.setImei", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.setImei");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.setImei");
  }

  DeviceConfigService_setImei_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.setImei", bytes);
  }

  DeviceConfigService_setImei_result result;
  try {
    result.success = iface_->setImei(args.imei, args.subscriptionId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.setImei");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("setImei", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.setImei");
  }

  oprot->writeMessageBegin("setImei", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.setImei", bytes);
  }
}

void DeviceConfigServiceProcessor::process_getMeid(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.getMeid", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.getMeid");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.getMeid");
  }

  DeviceConfigService_getMeid_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.getMeid", bytes);
  }

  DeviceConfigService_getMeid_result result;
  try {
    result.success = iface_->getMeid(args.subscriptionId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.getMeid");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("getMeid", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.getMeid");
  }

  oprot->writeMessageBegin("getMeid", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.getMeid", bytes);
  }
}

void DeviceConfigServiceProcessor::process_setMeid(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.setMeid", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.setMeid");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.setMeid");
  }

  DeviceConfigService_setMeid_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.setMeid", bytes);
  }

  DeviceConfigService_setMeid_result result;
  try {
    result.success = iface_->setMeid(args.meid, args.subscriptionId);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.setMeid");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("setMeid", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.setMeid");
  }

  oprot->writeMessageBegin("setMeid", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.setMeid", bytes);
  }
}

void DeviceConfigServiceProcessor::process_checkSpc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.checkSpc", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.checkSpc");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.checkSpc");
  }

  DeviceConfigService_checkSpc_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.checkSpc", bytes);
  }

  DeviceConfigService_checkSpc_result result;
  try {
    result.success = iface_->checkSpc(args.spc);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.checkSpc");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("checkSpc", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.checkSpc");
  }

  oprot->writeMessageBegin("checkSpc", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.checkSpc", bytes);
  }
}

void DeviceConfigServiceProcessor::process_provisionSpc(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.provisionSpc", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.provisionSpc");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.provisionSpc");
  }

  DeviceConfigService_provisionSpc_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.provisionSpc", bytes);
  }

  DeviceConfigService_provisionSpc_result result;
  try {
    result.success = iface_->provisionSpc(args.currentSpc, args.newSpc);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.provisionSpc");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("provisionSpc", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.provisionSpc");
  }

  oprot->writeMessageBegin("provisionSpc", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.provisionSpc", bytes);
  }
}

void DeviceConfigServiceProcessor::process_efsReadFromModemLog(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.efsReadFromModemLog", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.efsReadFromModemLog");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.efsReadFromModemLog");
  }

  DeviceConfigService_efsReadFromModemLog_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.efsReadFromModemLog", bytes);
  }

  DeviceConfigService_efsReadFromModemLog_result result;
  try {
    iface_->efsReadFromModemLog(result.success);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.efsReadFromModemLog");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("efsReadFromModemLog", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.efsReadFromModemLog");
  }

  oprot->writeMessageBegin("efsReadFromModemLog", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.efsReadFromModemLog", bytes);
  }
}

void DeviceConfigServiceProcessor::process_configureService(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("DeviceConfigService.configureService", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "DeviceConfigService.configureService");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "DeviceConfigService.configureService");
  }

  DeviceConfigService_configureService_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "DeviceConfigService.configureService", bytes);
  }

  DeviceConfigService_configureService_result result;
  try {
    result.success = iface_->configureService(args.deviceConfigOptions);
    result.__isset.success = true;
  } catch ( ::Uts::AppException &e) {
    result.e = e;
    result.__isset.e = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "DeviceConfigService.configureService");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("configureService", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "DeviceConfigService.configureService");
  }

  oprot->writeMessageBegin("configureService", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "DeviceConfigService.configureService", bytes);
  }
}

::std::shared_ptr< ::apache::thrift::TProcessor > DeviceConfigServiceProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< DeviceConfigServiceIfFactory > cleanup(handlerFactory_);
  ::std::shared_ptr< DeviceConfigServiceIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::std::shared_ptr< ::apache::thrift::TProcessor > processor(new DeviceConfigServiceProcessor(handler));
  return processor;
}

void DeviceConfigServiceConcurrentClient::getLastError( ::Uts::ErrorType& _return)
{
  int32_t seqid = send_getLastError();
  recv_getLastError(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_getLastError()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getLastError", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getLastError_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_getLastError( ::Uts::ErrorType& _return, const int32_t seqid)
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
      DeviceConfigService_getLastError_presult result;
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

int64_t DeviceConfigServiceConcurrentClient::getDevice()
{
  int32_t seqid = send_getDevice();
  return recv_getDevice(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_getDevice()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getDevice", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getDevice_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int64_t DeviceConfigServiceConcurrentClient::recv_getDevice(const int32_t seqid)
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
      if (fname.compare("getDevice") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int64_t _return;
      DeviceConfigService_getDevice_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getDevice failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::initializeService()
{
  int32_t seqid = send_initializeService();
  return recv_initializeService(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_initializeService()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("initializeService", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_initializeService_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_initializeService(const int32_t seqid)
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
      DeviceConfigService_initializeService_presult result;
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

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle)
{
  int32_t seqid = send_initializeServiceByProtocol(diagProtocolHandle, qmiProtocolHandle);
  return recv_initializeServiceByProtocol(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_initializeServiceByProtocol(const int64_t diagProtocolHandle, const int64_t qmiProtocolHandle)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("initializeServiceByProtocol", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_initializeServiceByProtocol_pargs args;
  args.diagProtocolHandle = &diagProtocolHandle;
  args.qmiProtocolHandle = &qmiProtocolHandle;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_initializeServiceByProtocol(const int32_t seqid)
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
      if (fname.compare("initializeServiceByProtocol") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_initializeServiceByProtocol_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "initializeServiceByProtocol failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions)
{
  int32_t seqid = send_initializeServiceWithOptions(connectionOptions);
  return recv_initializeServiceWithOptions(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_initializeServiceWithOptions(const DeviceConfigConnectionOptions& connectionOptions)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("initializeServiceWithOptions", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_initializeServiceWithOptions_pargs args;
  args.connectionOptions = &connectionOptions;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_initializeServiceWithOptions(const int32_t seqid)
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
      if (fname.compare("initializeServiceWithOptions") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_initializeServiceWithOptions_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "initializeServiceWithOptions failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::destroyService()
{
  int32_t seqid = send_destroyService();
  return recv_destroyService(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_destroyService()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("destroyService", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_destroyService_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_destroyService(const int32_t seqid)
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
      DeviceConfigService_destroyService_presult result;
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

void DeviceConfigServiceConcurrentClient::doXqcnOperation( ::Uts::DeviceConfigResp& _return, const DeviceConfigOptions& deviceConfigOptions)
{
  int32_t seqid = send_doXqcnOperation(deviceConfigOptions);
  recv_doXqcnOperation(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_doXqcnOperation(const DeviceConfigOptions& deviceConfigOptions)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("doXqcnOperation", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_doXqcnOperation_pargs args;
  args.deviceConfigOptions = &deviceConfigOptions;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_doXqcnOperation( ::Uts::DeviceConfigResp& _return, const int32_t seqid)
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
      if (fname.compare("doXqcnOperation") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_doXqcnOperation_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "doXqcnOperation failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::backupToXqcn(std::string& _return, const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents)
{
  int32_t seqid = send_backupToXqcn(serviceProgrammingCode, resetUponCompletion, resetTimeout, filterFileContents);
  recv_backupToXqcn(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_backupToXqcn(const std::string& serviceProgrammingCode, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("backupToXqcn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_backupToXqcn_pargs args;
  args.serviceProgrammingCode = &serviceProgrammingCode;
  args.resetUponCompletion = &resetUponCompletion;
  args.resetTimeout = &resetTimeout;
  args.filterFileContents = &filterFileContents;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_backupToXqcn(std::string& _return, const int32_t seqid)
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
      if (fname.compare("backupToXqcn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_backupToXqcn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "backupToXqcn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents)
{
  int32_t seqid = send_restoreFromXqcn(xqcnFileContents, serviceProgrammingCode, allowEsnMismatch, resetUponCompletion, resetTimeout, filterFileContents);
  return recv_restoreFromXqcn(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_restoreFromXqcn(const std::string& xqcnFileContents, const std::string& serviceProgrammingCode, const bool allowEsnMismatch, const bool resetUponCompletion, const int32_t resetTimeout, const std::string& filterFileContents)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("restoreFromXqcn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_restoreFromXqcn_pargs args;
  args.xqcnFileContents = &xqcnFileContents;
  args.serviceProgrammingCode = &serviceProgrammingCode;
  args.allowEsnMismatch = &allowEsnMismatch;
  args.resetUponCompletion = &resetUponCompletion;
  args.resetTimeout = &resetTimeout;
  args.filterFileContents = &filterFileContents;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_restoreFromXqcn(const int32_t seqid)
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
      if (fname.compare("restoreFromXqcn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_restoreFromXqcn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "restoreFromXqcn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

int64_t DeviceConfigServiceConcurrentClient::pdcGetMbnMaxStorage(const PdcMbnType::type mbnType)
{
  int32_t seqid = send_pdcGetMbnMaxStorage(mbnType);
  return recv_pdcGetMbnMaxStorage(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetMbnMaxStorage(const PdcMbnType::type mbnType)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetMbnMaxStorage", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnMaxStorage_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int64_t DeviceConfigServiceConcurrentClient::recv_pdcGetMbnMaxStorage(const int32_t seqid)
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
      if (fname.compare("pdcGetMbnMaxStorage") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int64_t _return;
      DeviceConfigService_pdcGetMbnMaxStorage_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnMaxStorage failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

int64_t DeviceConfigServiceConcurrentClient::pdcGetMbnStorageUsage(const PdcMbnType::type mbnType)
{
  int32_t seqid = send_pdcGetMbnStorageUsage(mbnType);
  return recv_pdcGetMbnStorageUsage(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetMbnStorageUsage(const PdcMbnType::type mbnType)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetMbnStorageUsage", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnStorageUsage_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int64_t DeviceConfigServiceConcurrentClient::recv_pdcGetMbnStorageUsage(const int32_t seqid)
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
      if (fname.compare("pdcGetMbnStorageUsage") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int64_t _return;
      DeviceConfigService_pdcGetMbnStorageUsage_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnStorageUsage failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

int64_t DeviceConfigServiceConcurrentClient::pdcGetMbnCount(const PdcMbnType::type mbnType)
{
  int32_t seqid = send_pdcGetMbnCount(mbnType);
  return recv_pdcGetMbnCount(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetMbnCount(const PdcMbnType::type mbnType)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetMbnCount", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnCount_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int64_t DeviceConfigServiceConcurrentClient::recv_pdcGetMbnCount(const int32_t seqid)
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
      if (fname.compare("pdcGetMbnCount") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int64_t _return;
      DeviceConfigService_pdcGetMbnCount_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnCount failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const PdcMbnType::type mbnType)
{
  int32_t seqid = send_pdcGetMbnList(mbnType);
  recv_pdcGetMbnList(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetMbnList(const PdcMbnType::type mbnType)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetMbnList", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnList_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_pdcGetMbnList(std::vector<PdcMbnInfo> & _return, const int32_t seqid)
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
      if (fname.compare("pdcGetMbnList") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_pdcGetMbnList_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnList failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const PdcMbnType::type mbnType)
{
  int32_t seqid = send_pdcGetDefaultMbnInfo(mbnType);
  recv_pdcGetDefaultMbnInfo(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetDefaultMbnInfo(const PdcMbnType::type mbnType)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetDefaultMbnInfo", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetDefaultMbnInfo_pargs args;
  args.mbnType = &mbnType;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_pdcGetDefaultMbnInfo(PdcMbnInfo& _return, const int32_t seqid)
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
      if (fname.compare("pdcGetDefaultMbnInfo") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_pdcGetDefaultMbnInfo_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetDefaultMbnInfo failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::pdcGetMbnId(std::string& _return, const std::string& mbnContent)
{
  int32_t seqid = send_pdcGetMbnId(mbnContent);
  recv_pdcGetMbnId(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetMbnId(const std::string& mbnContent)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetMbnId", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetMbnId_pargs args;
  args.mbnContent = &mbnContent;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_pdcGetMbnId(std::string& _return, const int32_t seqid)
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
      if (fname.compare("pdcGetMbnId") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_pdcGetMbnId_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetMbnId failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent)
{
  int32_t seqid = send_pdcWriteMbn(mbnType, mbnContent);
  return recv_pdcWriteMbn(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcWriteMbn(const PdcMbnType::type mbnType, const std::string& mbnContent)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcWriteMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcWriteMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnContent = &mbnContent;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_pdcWriteMbn(const int32_t seqid)
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
      if (fname.compare("pdcWriteMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_pdcWriteMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcWriteMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::pdcReadMbn(std::string& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId)
{
  int32_t seqid = send_pdcReadMbn(mbnType, mbnId, subId);
  recv_pdcReadMbn(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcReadMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcReadMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcReadMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnId = &mbnId;
  args.subId = &subId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_pdcReadMbn(std::string& _return, const int32_t seqid)
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
      if (fname.compare("pdcReadMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_pdcReadMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcReadMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId)
{
  int32_t seqid = send_pdcRemoveMbn(mbnType, mbnId);
  return recv_pdcRemoveMbn(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcRemoveMbn(const PdcMbnType::type mbnType, const std::string& mbnId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcRemoveMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcRemoveMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnId = &mbnId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_pdcRemoveMbn(const int32_t seqid)
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
      if (fname.compare("pdcRemoveMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_pdcRemoveMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcRemoveMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::pdcGetActiveMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId)
{
  int32_t seqid = send_pdcGetActiveMbn(mbnType, subId, slotId);
  recv_pdcGetActiveMbn(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetActiveMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetActiveMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetActiveMbn_pargs args;
  args.mbnType = &mbnType;
  args.subId = &subId;
  args.slotId = &slotId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_pdcGetActiveMbn(std::string& _return, const int32_t seqid)
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
      if (fname.compare("pdcGetActiveMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_pdcGetActiveMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetActiveMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::pdcGetPendingMbn(std::string& _return, const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId)
{
  int32_t seqid = send_pdcGetPendingMbn(mbnType, subId, slotId);
  recv_pdcGetPendingMbn(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetPendingMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetPendingMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetPendingMbn_pargs args;
  args.mbnType = &mbnType;
  args.subId = &subId;
  args.slotId = &slotId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_pdcGetPendingMbn(std::string& _return, const int32_t seqid)
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
      if (fname.compare("pdcGetPendingMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_pdcGetPendingMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetPendingMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::pdcValidateMbn(PdcMbnResult& _return, const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath)
{
  int32_t seqid = send_pdcValidateMbn(mbnType, mbnId, subId, remotePath);
  recv_pdcValidateMbn(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcValidateMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const std::string& remotePath)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcValidateMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcValidateMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnId = &mbnId;
  args.subId = &subId;
  args.remotePath = &remotePath;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_pdcValidateMbn(PdcMbnResult& _return, const int32_t seqid)
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
      if (fname.compare("pdcValidateMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_pdcValidateMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcValidateMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId)
{
  int32_t seqid = send_pdcSelectMbn(mbnType, mbnId, subId, slotId);
  return recv_pdcSelectMbn(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcSelectMbn(const PdcMbnType::type mbnType, const std::string& mbnId, const int32_t subId, const int32_t slotId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcSelectMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcSelectMbn_pargs args;
  args.mbnType = &mbnType;
  args.mbnId = &mbnId;
  args.subId = &subId;
  args.slotId = &slotId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_pdcSelectMbn(const int32_t seqid)
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
      if (fname.compare("pdcSelectMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_pdcSelectMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcSelectMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout)
{
  int32_t seqid = send_pdcActivateMbn(mbnType, subId, slotId, mode, timeout);
  return recv_pdcActivateMbn(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcActivateMbn(const PdcMbnType::type mbnType, const int32_t subId, const int32_t slotId, const int32_t mode, const int32_t timeout)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcActivateMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcActivateMbn_pargs args;
  args.mbnType = &mbnType;
  args.subId = &subId;
  args.slotId = &slotId;
  args.mode = &mode;
  args.timeout = &timeout;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_pdcActivateMbn(const int32_t seqid)
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
      if (fname.compare("pdcActivateMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_pdcActivateMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcActivateMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId)
{
  int32_t seqid = send_pdcDeactivateMbn(mbnType, subId);
  return recv_pdcDeactivateMbn(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcDeactivateMbn(const PdcMbnType::type mbnType, const int32_t subId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcDeactivateMbn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcDeactivateMbn_pargs args;
  args.mbnType = &mbnType;
  args.subId = &subId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_pdcDeactivateMbn(const int32_t seqid)
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
      if (fname.compare("pdcDeactivateMbn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_pdcDeactivateMbn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcDeactivateMbn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

int32_t DeviceConfigServiceConcurrentClient::pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature)
{
  int32_t seqid = send_pdcGetConfiguration(slotId, feature);
  return recv_pdcGetConfiguration(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcGetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcGetConfiguration", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcGetConfiguration_pargs args;
  args.slotId = &slotId;
  args.feature = &feature;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int32_t DeviceConfigServiceConcurrentClient::recv_pdcGetConfiguration(const int32_t seqid)
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
      if (fname.compare("pdcGetConfiguration") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int32_t _return;
      DeviceConfigService_pdcGetConfiguration_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcGetConfiguration failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value)
{
  int32_t seqid = send_pdcSetConfiguration(slotId, feature, value);
  return recv_pdcSetConfiguration(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_pdcSetConfiguration(const int32_t slotId, const PdcConfigurationType::type feature, const int32_t value)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("pdcSetConfiguration", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_pdcSetConfiguration_pargs args;
  args.slotId = &slotId;
  args.feature = &feature;
  args.value = &value;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_pdcSetConfiguration(const int32_t seqid)
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
      if (fname.compare("pdcSetConfiguration") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_pdcSetConfiguration_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "pdcSetConfiguration failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

bool DeviceConfigServiceConcurrentClient::nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId)
{
  int32_t seqid = send_nvIsItemSupported(nvItemNameOrId, subscriptionId);
  return recv_nvIsItemSupported(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_nvIsItemSupported(const std::string& nvItemNameOrId, const int32_t subscriptionId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("nvIsItemSupported", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvIsItemSupported_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool DeviceConfigServiceConcurrentClient::recv_nvIsItemSupported(const int32_t seqid)
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
      if (fname.compare("nvIsItemSupported") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      DeviceConfigService_nvIsItemSupported_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvIsItemSupported failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::nvReadItem(NvData& _return, const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig)
{
  int32_t seqid = send_nvReadItem(nvItemNameOrId, subscriptionId, index, returnConfig);
  recv_nvReadItem(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_nvReadItem(const std::string& nvItemNameOrId, const int32_t subscriptionId, const int8_t index, const NvReturns& returnConfig)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("nvReadItem", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvReadItem_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.subscriptionId = &subscriptionId;
  args.index = &index;
  args.returnConfig = &returnConfig;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_nvReadItem(NvData& _return, const int32_t seqid)
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
      if (fname.compare("nvReadItem") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_nvReadItem_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvReadItem failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId)
{
  int32_t seqid = send_nvSetItem(nvItemNameOrId, valueList, subscriptionId);
  return recv_nvSetItem(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_nvSetItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("nvSetItem", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvSetItem_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.valueList = &valueList;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_nvSetItem(const int32_t seqid)
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
      if (fname.compare("nvSetItem") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_nvSetItem_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvSetItem failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId)
{
  int32_t seqid = send_nvSetOtpItem(nvItemNameOrId, valueList, subscriptionId);
  return recv_nvSetOtpItem(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_nvSetOtpItem(const std::string& nvItemNameOrId, const std::string& valueList, const int32_t subscriptionId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("nvSetOtpItem", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvSetOtpItem_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.valueList = &valueList;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_nvSetOtpItem(const int32_t seqid)
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
      if (fname.compare("nvSetOtpItem") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_nvSetOtpItem_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvSetOtpItem failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::nvGetAllItems(std::vector< ::Uts::NvItem> & _return)
{
  int32_t seqid = send_nvGetAllItems();
  recv_nvGetAllItems(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_nvGetAllItems()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("nvGetAllItems", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvGetAllItems_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_nvGetAllItems(std::vector< ::Uts::NvItem> & _return, const int32_t seqid)
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
      if (fname.compare("nvGetAllItems") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_nvGetAllItems_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvGetAllItems failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::nvGetItemDefinition(std::string& _return, const std::string& nvItemNameOrId)
{
  int32_t seqid = send_nvGetItemDefinition(nvItemNameOrId);
  recv_nvGetItemDefinition(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_nvGetItemDefinition(const std::string& nvItemNameOrId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("nvGetItemDefinition", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_nvGetItemDefinition_pargs args;
  args.nvItemNameOrId = &nvItemNameOrId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_nvGetItemDefinition(std::string& _return, const int32_t seqid)
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
      if (fname.compare("nvGetItemDefinition") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_nvGetItemDefinition_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "nvGetItemDefinition failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

bool DeviceConfigServiceConcurrentClient::efsHasAlternateFileSystem()
{
  int32_t seqid = send_efsHasAlternateFileSystem();
  return recv_efsHasAlternateFileSystem(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsHasAlternateFileSystem()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsHasAlternateFileSystem", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsHasAlternateFileSystem_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool DeviceConfigServiceConcurrentClient::recv_efsHasAlternateFileSystem(const int32_t seqid)
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
      if (fname.compare("efsHasAlternateFileSystem") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      DeviceConfigService_efsHasAlternateFileSystem_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsHasAlternateFileSystem failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsCreateDirectory(pathName, efsSystem);
  return recv_efsCreateDirectory(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsCreateDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsCreateDirectory", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsCreateDirectory_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_efsCreateDirectory(const int32_t seqid)
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
      if (fname.compare("efsCreateDirectory") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_efsCreateDirectory_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsCreateDirectory failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsRemoveDirectory(pathName, efsSystem);
  return recv_efsRemoveDirectory(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsRemoveDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsRemoveDirectory", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsRemoveDirectory_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_efsRemoveDirectory(const int32_t seqid)
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
      if (fname.compare("efsRemoveDirectory") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_efsRemoveDirectory_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsRemoveDirectory failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem)
{
  int32_t seqid = send_efsRemoveTree(pathName, efsSytem);
  return recv_efsRemoveTree(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsRemoveTree(const std::string& pathName, const FileSystem::type efsSytem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsRemoveTree", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsRemoveTree_pargs args;
  args.pathName = &pathName;
  args.efsSytem = &efsSytem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_efsRemoveTree(const int32_t seqid)
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
      if (fname.compare("efsRemoveTree") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_efsRemoveTree_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsRemoveTree failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::efsGetDirectoryContents(std::vector<EfsItem> & _return, const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsGetDirectoryContents(pathName, efsSystem);
  recv_efsGetDirectoryContents(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsGetDirectoryContents(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsGetDirectoryContents", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetDirectoryContents_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_efsGetDirectoryContents(std::vector<EfsItem> & _return, const int32_t seqid)
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
      if (fname.compare("efsGetDirectoryContents") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_efsGetDirectoryContents_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetDirectoryContents failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsPutFile(pathName, buffer, efsSystem);
  return recv_efsPutFile(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsPutFile(const std::string& pathName, const std::string& buffer, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsPutFile", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsPutFile_pargs args;
  args.pathName = &pathName;
  args.buffer = &buffer;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_efsPutFile(const int32_t seqid)
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
      if (fname.compare("efsPutFile") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_efsPutFile_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsPutFile failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::efsGetFile(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsGetFile(pathName, efsSystem);
  recv_efsGetFile(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsGetFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsGetFile", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetFile_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_efsGetFile(std::string& _return, const int32_t seqid)
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
      if (fname.compare("efsGetFile") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_efsGetFile_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetFile failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsDeleteFile(pathName, efsSystem);
  return recv_efsDeleteFile(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsDeleteFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsDeleteFile", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsDeleteFile_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_efsDeleteFile(const int32_t seqid)
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
      if (fname.compare("efsDeleteFile") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_efsDeleteFile_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsDeleteFile failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsRename(existingName, newName, efsSystem);
  return recv_efsRename(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsRename(const std::string& existingName, const std::string& newName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsRename", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsRename_pargs args;
  args.existingName = &existingName;
  args.newName = &newName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_efsRename(const int32_t seqid)
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
      if (fname.compare("efsRename") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_efsRename_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsRename failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

bool DeviceConfigServiceConcurrentClient::efsPathExists(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsPathExists(pathName, efsSystem);
  return recv_efsPathExists(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsPathExists(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsPathExists", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsPathExists_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool DeviceConfigServiceConcurrentClient::recv_efsPathExists(const int32_t seqid)
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
      if (fname.compare("efsPathExists") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      DeviceConfigService_efsPathExists_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsPathExists failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

bool DeviceConfigServiceConcurrentClient::efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsIsDirectory(pathName, efsSystem);
  return recv_efsIsDirectory(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsIsDirectory(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsIsDirectory", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsIsDirectory_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool DeviceConfigServiceConcurrentClient::recv_efsIsDirectory(const int32_t seqid)
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
      if (fname.compare("efsIsDirectory") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      DeviceConfigService_efsIsDirectory_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsIsDirectory failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

bool DeviceConfigServiceConcurrentClient::efsIsFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsIsFile(pathName, efsSystem);
  return recv_efsIsFile(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsIsFile(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsIsFile", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsIsFile_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool DeviceConfigServiceConcurrentClient::recv_efsIsFile(const int32_t seqid)
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
      if (fname.compare("efsIsFile") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      DeviceConfigService_efsIsFile_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsIsFile failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

int64_t DeviceConfigServiceConcurrentClient::efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsGetFileSize(pathName, efsSystem);
  return recv_efsGetFileSize(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsGetFileSize(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsGetFileSize", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetFileSize_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int64_t DeviceConfigServiceConcurrentClient::recv_efsGetFileSize(const int32_t seqid)
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
      if (fname.compare("efsGetFileSize") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int64_t _return;
      DeviceConfigService_efsGetFileSize_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetFileSize failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

int64_t DeviceConfigServiceConcurrentClient::efsGetAvailableSpace(const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsGetAvailableSpace(efsSystem);
  return recv_efsGetAvailableSpace(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsGetAvailableSpace(const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsGetAvailableSpace", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetAvailableSpace_pargs args;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int64_t DeviceConfigServiceConcurrentClient::recv_efsGetAvailableSpace(const int32_t seqid)
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
      if (fname.compare("efsGetAvailableSpace") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int64_t _return;
      DeviceConfigService_efsGetAvailableSpace_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetAvailableSpace failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::efsGetFileCheckSum(std::string& _return, const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsGetFileCheckSum(pathName, efsSystem);
  recv_efsGetFileCheckSum(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsGetFileCheckSum(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsGetFileCheckSum", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetFileCheckSum_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_efsGetFileCheckSum(std::string& _return, const int32_t seqid)
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
      if (fname.compare("efsGetFileCheckSum") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_efsGetFileCheckSum_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetFileCheckSum failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::efsGetFileAttributes(EfsFileAttributes& _return, const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_efsGetFileAttributes(pathName, efsSystem);
  recv_efsGetFileAttributes(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsGetFileAttributes(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsGetFileAttributes", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsGetFileAttributes_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_efsGetFileAttributes(EfsFileAttributes& _return, const int32_t seqid)
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
      if (fname.compare("efsGetFileAttributes") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_efsGetFileAttributes_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsGetFileAttributes failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

bool DeviceConfigServiceConcurrentClient::efsIsReady()
{
  int32_t seqid = send_efsIsReady();
  return recv_efsIsReady(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsIsReady()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsIsReady", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsIsReady_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool DeviceConfigServiceConcurrentClient::recv_efsIsReady(const int32_t seqid)
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
      if (fname.compare("efsIsReady") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      DeviceConfigService_efsIsReady_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsIsReady failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_createGoldenCopy(pathName, efsSystem);
  return recv_createGoldenCopy(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_createGoldenCopy(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("createGoldenCopy", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_createGoldenCopy_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_createGoldenCopy(const int32_t seqid)
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
      if (fname.compare("createGoldenCopy") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_createGoldenCopy_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "createGoldenCopy failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem)
{
  int32_t seqid = send_createCefsCopy(cefsSavePath, efsSystem);
  return recv_createCefsCopy(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_createCefsCopy(const std::string& cefsSavePath, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("createCefsCopy", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_createCefsCopy_pargs args;
  args.cefsSavePath = &cefsSavePath;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_createCefsCopy(const int32_t seqid)
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
      if (fname.compare("createCefsCopy") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_createCefsCopy_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "createCefsCopy failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::requestPrl(std::string& _return, const int32_t subscriptionId, const int8_t index)
{
  int32_t seqid = send_requestPrl(subscriptionId, index);
  recv_requestPrl(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_requestPrl(const int32_t subscriptionId, const int8_t index)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("requestPrl", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_requestPrl_pargs args;
  args.subscriptionId = &subscriptionId;
  args.index = &index;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_requestPrl(std::string& _return, const int32_t seqid)
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
      if (fname.compare("requestPrl") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_requestPrl_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "requestPrl failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::backupPrl(std::string& _return)
{
  int32_t seqid = send_backupPrl();
  recv_backupPrl(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_backupPrl()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("backupPrl", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_backupPrl_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_backupPrl(std::string& _return, const int32_t seqid)
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
      if (fname.compare("backupPrl") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_backupPrl_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "backupPrl failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::restorePrl(const std::string& xqcnFileContents)
{
  int32_t seqid = send_restorePrl(xqcnFileContents);
  return recv_restorePrl(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_restorePrl(const std::string& xqcnFileContents)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("restorePrl", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_restorePrl_pargs args;
  args.xqcnFileContents = &xqcnFileContents;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_restorePrl(const int32_t seqid)
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
      if (fname.compare("restorePrl") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_restorePrl_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "restorePrl failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents)
{
  int32_t seqid = send_sendPrl(subscriptionId, index, prlFileContents);
  return recv_sendPrl(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_sendPrl(const int32_t subscriptionId, const int8_t index, const std::string& prlFileContents)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("sendPrl", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_sendPrl_pargs args;
  args.subscriptionId = &subscriptionId;
  args.index = &index;
  args.prlFileContents = &prlFileContents;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_sendPrl(const int32_t seqid)
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
      if (fname.compare("sendPrl") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_sendPrl_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "sendPrl failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t seqid = send_forceEfsSync(pathName, efsSystem);
  return recv_forceEfsSync(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_forceEfsSync(const std::string& pathName, const FileSystem::type efsSystem)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("forceEfsSync", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_forceEfsSync_pargs args;
  args.pathName = &pathName;
  args.efsSystem = &efsSystem;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_forceEfsSync(const int32_t seqid)
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
      if (fname.compare("forceEfsSync") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_forceEfsSync_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "forceEfsSync failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

int32_t DeviceConfigServiceConcurrentClient::getEsn()
{
  int32_t seqid = send_getEsn();
  return recv_getEsn(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_getEsn()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getEsn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getEsn_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int32_t DeviceConfigServiceConcurrentClient::recv_getEsn(const int32_t seqid)
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
      if (fname.compare("getEsn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int32_t _return;
      DeviceConfigService_getEsn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getEsn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::setEsn(const int32_t esn)
{
  int32_t seqid = send_setEsn(esn);
  return recv_setEsn(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_setEsn(const int32_t esn)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("setEsn", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_setEsn_pargs args;
  args.esn = &esn;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_setEsn(const int32_t seqid)
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
      if (fname.compare("setEsn") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_setEsn_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "setEsn failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::getImei(std::string& _return, const int32_t subscriptionId)
{
  int32_t seqid = send_getImei(subscriptionId);
  recv_getImei(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_getImei(const int32_t subscriptionId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getImei", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getImei_pargs args;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_getImei(std::string& _return, const int32_t seqid)
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
      if (fname.compare("getImei") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_getImei_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getImei failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::setImei(const std::string& imei, const int32_t subscriptionId)
{
  int32_t seqid = send_setImei(imei, subscriptionId);
  return recv_setImei(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_setImei(const std::string& imei, const int32_t subscriptionId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("setImei", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_setImei_pargs args;
  args.imei = &imei;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_setImei(const int32_t seqid)
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
      if (fname.compare("setImei") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_setImei_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "setImei failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

int64_t DeviceConfigServiceConcurrentClient::getMeid(const int32_t subscriptionId)
{
  int32_t seqid = send_getMeid(subscriptionId);
  return recv_getMeid(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_getMeid(const int32_t subscriptionId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("getMeid", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_getMeid_pargs args;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

int64_t DeviceConfigServiceConcurrentClient::recv_getMeid(const int32_t seqid)
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
      if (fname.compare("getMeid") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      int64_t _return;
      DeviceConfigService_getMeid_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "getMeid failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::setMeid(const int64_t meid, const int32_t subscriptionId)
{
  int32_t seqid = send_setMeid(meid, subscriptionId);
  return recv_setMeid(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_setMeid(const int64_t meid, const int32_t subscriptionId)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("setMeid", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_setMeid_pargs args;
  args.meid = &meid;
  args.subscriptionId = &subscriptionId;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_setMeid(const int32_t seqid)
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
      if (fname.compare("setMeid") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_setMeid_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "setMeid failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

bool DeviceConfigServiceConcurrentClient::checkSpc(const std::string& spc)
{
  int32_t seqid = send_checkSpc(spc);
  return recv_checkSpc(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_checkSpc(const std::string& spc)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("checkSpc", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_checkSpc_pargs args;
  args.spc = &spc;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool DeviceConfigServiceConcurrentClient::recv_checkSpc(const int32_t seqid)
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
      if (fname.compare("checkSpc") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      DeviceConfigService_checkSpc_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "checkSpc failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

bool DeviceConfigServiceConcurrentClient::provisionSpc(const std::string& currentSpc, const std::string& newSpc)
{
  int32_t seqid = send_provisionSpc(currentSpc, newSpc);
  return recv_provisionSpc(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_provisionSpc(const std::string& currentSpc, const std::string& newSpc)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("provisionSpc", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_provisionSpc_pargs args;
  args.currentSpc = &currentSpc;
  args.newSpc = &newSpc;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool DeviceConfigServiceConcurrentClient::recv_provisionSpc(const int32_t seqid)
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
      if (fname.compare("provisionSpc") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      DeviceConfigService_provisionSpc_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "provisionSpc failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

void DeviceConfigServiceConcurrentClient::efsReadFromModemLog(std::string& _return)
{
  int32_t seqid = send_efsReadFromModemLog();
  recv_efsReadFromModemLog(_return, seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_efsReadFromModemLog()
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("efsReadFromModemLog", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_efsReadFromModemLog_pargs args;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

void DeviceConfigServiceConcurrentClient::recv_efsReadFromModemLog(std::string& _return, const int32_t seqid)
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
      if (fname.compare("efsReadFromModemLog") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      DeviceConfigService_efsReadFromModemLog_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "efsReadFromModemLog failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::configureService(const DeviceConfigOptions& deviceConfigOptions)
{
  int32_t seqid = send_configureService(deviceConfigOptions);
  return recv_configureService(seqid);
}

int32_t DeviceConfigServiceConcurrentClient::send_configureService(const DeviceConfigOptions& deviceConfigOptions)
{
  int32_t cseqid = this->sync_->generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(this->sync_.get());
  oprot_->writeMessageBegin("configureService", ::apache::thrift::protocol::T_CALL, cseqid);

  DeviceConfigService_configureService_pargs args;
  args.deviceConfigOptions = &deviceConfigOptions;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

 ::Uts::ErrorCode::type DeviceConfigServiceConcurrentClient::recv_configureService(const int32_t seqid)
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
      if (fname.compare("configureService") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
       ::Uts::ErrorCode::type _return;
      DeviceConfigService_configureService_presult result;
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
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "configureService failed: unknown result");
    }
    // seqid != rseqid
    this->sync_->updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_->waitForWork(seqid);
  } // end while(true)
}

} // namespace

