/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef UtilityService_CONSTANTS_H
#define UtilityService_CONSTANTS_H

#include "UtilityService_types.h"

namespace Uts {

class UtilityServiceConstants {
 public:
  UtilityServiceConstants();

  std::string UTILITY_SERVICE_NAME;
};

extern const UtilityServiceConstants g_UtilityService_constants;

} // namespace

#endif
