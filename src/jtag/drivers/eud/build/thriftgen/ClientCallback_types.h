/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef ClientCallback_TYPES_H
#define ClientCallback_TYPES_H

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

struct MessageLevel {
  enum type {
    INFO = 0,
    WARNING = 1,
    EXCEPTION = 2
  };
};

extern const std::map<int, const char*> _MessageLevel_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const MessageLevel::type& val);

std::string to_string(const MessageLevel::type& val);

} // namespace

#endif
