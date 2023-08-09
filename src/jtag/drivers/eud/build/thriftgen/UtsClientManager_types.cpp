/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "UtsClientManager_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {

int _kClientPortOffsetsValues[] = {
  ClientPortOffsets::PORT_DEVICE_MANAGER_SERVER,
  ClientPortOffsets::PORT_CALLBACK_CLIENT,
  ClientPortOffsets::PORT_PLUG_IN_OFFSET
};
const char* _kClientPortOffsetsNames[] = {
  "PORT_DEVICE_MANAGER_SERVER",
  "PORT_CALLBACK_CLIENT",
  "PORT_PLUG_IN_OFFSET"
};
const std::map<int, const char*> _ClientPortOffsets_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kClientPortOffsetsValues, _kClientPortOffsetsNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const ClientPortOffsets::type& val) {
  std::map<int, const char*>::const_iterator it = _ClientPortOffsets_VALUES_TO_NAMES.find(val);
  if (it != _ClientPortOffsets_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const ClientPortOffsets::type& val) {
  std::map<int, const char*>::const_iterator it = _ClientPortOffsets_VALUES_TO_NAMES.find(val);
  if (it != _ClientPortOffsets_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

} // namespace
