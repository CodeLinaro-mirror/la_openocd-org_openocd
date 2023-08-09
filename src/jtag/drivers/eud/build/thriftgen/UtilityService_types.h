/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef UtilityService_TYPES_H
#define UtilityService_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <functional>
#include <memory>
#include "Common_types.h"
#include "ImageManagementService_types.h"
#include "DeviceConfigService_types.h"


namespace Uts {

class NvParserResult;

typedef struct _NvParserResult__isset {
  _NvParserResult__isset() : nvId(false), data(false) {}
  bool nvId :1;
  bool data :1;
} _NvParserResult__isset;

class NvParserResult : public virtual ::apache::thrift::TBase {
 public:

  NvParserResult(const NvParserResult&);
  NvParserResult& operator=(const NvParserResult&);
  NvParserResult() : nvId(0) {
  }

  virtual ~NvParserResult() noexcept;
  int32_t nvId;
   ::Uts::NvData data;

  _NvParserResult__isset __isset;

  void __set_nvId(const int32_t val);

  void __set_data(const  ::Uts::NvData& val);

  bool operator == (const NvParserResult & rhs) const
  {
    if (!(nvId == rhs.nvId))
      return false;
    if (__isset.data != rhs.__isset.data)
      return false;
    else if (__isset.data && !(data == rhs.data))
      return false;
    return true;
  }
  bool operator != (const NvParserResult &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const NvParserResult & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(NvParserResult &a, NvParserResult &b);

std::ostream& operator<<(std::ostream& out, const NvParserResult& obj);

} // namespace

#endif
