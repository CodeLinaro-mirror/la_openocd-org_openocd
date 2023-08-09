/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudService_CONSTANTS_H
#define EudService_CONSTANTS_H

#include "EudService_types.h"

namespace Uts {

class EudServiceConstants {
 public:
  EudServiceConstants();

  std::string EUD_SERVICE_NAME;
};

extern const EudServiceConstants g_EudService_constants;

} // namespace

#endif
