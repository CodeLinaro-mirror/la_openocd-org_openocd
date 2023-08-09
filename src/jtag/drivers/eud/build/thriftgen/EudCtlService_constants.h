/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudCtlService_CONSTANTS_H
#define EudCtlService_CONSTANTS_H

#include "EudCtlService_types.h"

namespace Uts {

class EudCtlServiceConstants {
 public:
  EudCtlServiceConstants();

  std::string EUD_CTL_SERVICE_NAME;
};

extern const EudCtlServiceConstants g_EudCtlService_constants;

} // namespace

#endif
