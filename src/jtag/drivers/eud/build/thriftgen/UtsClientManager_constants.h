/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef UtsClientManager_CONSTANTS_H
#define UtsClientManager_CONSTANTS_H

#include "UtsClientManager_types.h"

namespace Uts {

class UtsClientManagerConstants {
 public:
  UtsClientManagerConstants();

  int32_t UTS_REGISTRATION_PORT;
  std::string UTS_REGISTRATION_SERVICE_NAME;
  int32_t UTS_INVALID_LICENSE_ERROR_CODE;
  int32_t UTS_DB_UPDATING_ERROR_CODE;
  int32_t UTS_TIMEBOMB_TRIGGERED_ERROR_CODE;
};

extern const UtsClientManagerConstants g_UtsClientManager_constants;

} // namespace

#endif
