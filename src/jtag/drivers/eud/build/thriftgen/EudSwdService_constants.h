/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudSwdService_CONSTANTS_H
#define EudSwdService_CONSTANTS_H

#include "EudSwdService_types.h"

namespace Uts {

class EudSwdServiceConstants {
 public:
  EudSwdServiceConstants();

  std::string EUD_SWD_SERVICE_NAME;
};

extern const EudSwdServiceConstants g_EudSwdService_constants;

} // namespace

#endif
