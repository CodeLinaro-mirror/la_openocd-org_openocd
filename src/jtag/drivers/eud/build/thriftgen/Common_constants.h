/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef Common_CONSTANTS_H
#define Common_CONSTANTS_H

#include "Common_types.h"

namespace Uts {

class CommonConstants {
 public:
  CommonConstants();

  int64_t INVALID_PROTOCOL_HANDLE;
};

extern const CommonConstants g_Common_constants;

} // namespace

#endif
