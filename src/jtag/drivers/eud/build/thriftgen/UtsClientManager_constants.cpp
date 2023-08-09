/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "UtsClientManager_constants.h"

namespace Uts {

const UtsClientManagerConstants g_UtsClientManager_constants;

UtsClientManagerConstants::UtsClientManagerConstants() {
  UTS_REGISTRATION_PORT = 50090;

  UTS_REGISTRATION_SERVICE_NAME = "QUTS Registration";

  UTS_INVALID_LICENSE_ERROR_CODE = -2;

  UTS_DB_UPDATING_ERROR_CODE = -3;

  UTS_TIMEBOMB_TRIGGERED_ERROR_CODE = -4;

}

} // namespace

