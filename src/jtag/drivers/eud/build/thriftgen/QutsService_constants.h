/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef QutsService_CONSTANTS_H
#define QutsService_CONSTANTS_H

#include "QutsService_types.h"

namespace Uts {

class QutsServiceConstants {
 public:
  QutsServiceConstants();

  int32_t QUTS_REGISTRATION_PORT;
  int32_t UTS_INVALID_LICENSE_ERROR_CODE;
  int32_t UTS_DB_UPDATING_ERROR_CODE;
  int32_t UTS_TIMEBOMB_TRIGGERED_ERROR_CODE;
  std::string QUTS_SERVICE_NAME;
};

extern const QutsServiceConstants g_QutsService_constants;

} // namespace

#endif
