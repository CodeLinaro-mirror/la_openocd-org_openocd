/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudService_TYPES_H
#define EudService_TYPES_H

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

class EudCmdInfo;

typedef struct _EudCmdInfo__isset {
  _EudCmdInfo__isset() : opcode(false), data(false), payload(false) {}
  bool opcode :1;
  bool data :1;
  bool payload :1;
} _EudCmdInfo__isset;

class EudCmdInfo : public virtual ::apache::thrift::TBase {
 public:

  EudCmdInfo(const EudCmdInfo&);
  EudCmdInfo& operator=(const EudCmdInfo&);
  EudCmdInfo() : opcode(0), data(0), payload(0) {
  }

  virtual ~EudCmdInfo() noexcept;
  int32_t opcode;
  int32_t data;
  int32_t payload;

  _EudCmdInfo__isset __isset;

  void __set_opcode(const int32_t val);

  void __set_data(const int32_t val);

  void __set_payload(const int32_t val);

  bool operator == (const EudCmdInfo & rhs) const
  {
    if (!(opcode == rhs.opcode))
      return false;
    if (!(data == rhs.data))
      return false;
    if (!(payload == rhs.payload))
      return false;
    return true;
  }
  bool operator != (const EudCmdInfo &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const EudCmdInfo & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(EudCmdInfo &a, EudCmdInfo &b);

std::ostream& operator<<(std::ostream& out, const EudCmdInfo& obj);

} // namespace

#endif
