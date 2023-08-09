/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudSwdService_TYPES_H
#define EudSwdService_TYPES_H

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

class BfrTckr;

typedef struct _BfrTckr__isset {
  _BfrTckr__isset() : bfrVector(false) {}
  bool bfrVector :1;
} _BfrTckr__isset;

class BfrTckr : public virtual ::apache::thrift::TBase {
 public:

  BfrTckr(const BfrTckr&);
  BfrTckr& operator=(const BfrTckr&);
  BfrTckr() : status(0) {
  }

  virtual ~BfrTckr() noexcept;
  std::vector<int64_t>  bfrVector;
  bool status;

  _BfrTckr__isset __isset;

  void __set_bfrVector(const std::vector<int64_t> & val);

  void __set_status(const bool val);

  bool operator == (const BfrTckr & rhs) const
  {
    if (!(bfrVector == rhs.bfrVector))
      return false;
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const BfrTckr &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BfrTckr & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(BfrTckr &a, BfrTckr &b);

std::ostream& operator<<(std::ostream& out, const BfrTckr& obj);

} // namespace

#endif
