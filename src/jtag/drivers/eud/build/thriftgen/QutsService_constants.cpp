/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "QutsService_constants.h"

namespace Uts {

const QutsServiceConstants g_QutsService_constants;

QutsServiceConstants::QutsServiceConstants() {
  QUTS_REGISTRATION_PORT = 50089;

  UTS_INVALID_LICENSE_ERROR_CODE = -2;

  UTS_DB_UPDATING_ERROR_CODE = -3;

  UTS_TIMEBOMB_TRIGGERED_ERROR_CODE = -4;

  QUTS_SERVICE_NAME = "QUTS Service";

}

} // namespace

