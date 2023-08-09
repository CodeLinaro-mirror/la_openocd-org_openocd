/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "ClientCallback_types.h"

#include <algorithm>
#include <ostream>

#include <thrift/TToString.h>

namespace Uts {

int _kMessageLevelValues[] = {
  MessageLevel::INFO,
  MessageLevel::WARNING,
  MessageLevel::EXCEPTION
};
const char* _kMessageLevelNames[] = {
  "INFO",
  "WARNING",
  "EXCEPTION"
};
const std::map<int, const char*> _MessageLevel_VALUES_TO_NAMES(::apache::thrift::TEnumIterator(3, _kMessageLevelValues, _kMessageLevelNames), ::apache::thrift::TEnumIterator(-1, NULL, NULL));

std::ostream& operator<<(std::ostream& out, const MessageLevel::type& val) {
  std::map<int, const char*>::const_iterator it = _MessageLevel_VALUES_TO_NAMES.find(val);
  if (it != _MessageLevel_VALUES_TO_NAMES.end()) {
    out << it->second;
  } else {
    out << static_cast<int>(val);
  }
  return out;
}

std::string to_string(const MessageLevel::type& val) {
  std::map<int, const char*>::const_iterator it = _MessageLevel_VALUES_TO_NAMES.find(val);
  if (it != _MessageLevel_VALUES_TO_NAMES.end()) {
    return std::string(it->second);
  } else {
    return std::to_string(static_cast<int>(val));
  }
}

} // namespace
