/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef UtsClientManager_TYPES_H
#define UtsClientManager_TYPES_H

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

struct ClientPortOffsets {
  enum type {
    PORT_DEVICE_MANAGER_SERVER = 0,
    PORT_CALLBACK_CLIENT = 1,
    PORT_PLUG_IN_OFFSET = 10
  };
};

extern const std::map<int, const char*> _ClientPortOffsets_VALUES_TO_NAMES;

std::ostream& operator<<(std::ostream& out, const ClientPortOffsets::type& val);

std::string to_string(const ClientPortOffsets::type& val);

} // namespace

#endif
