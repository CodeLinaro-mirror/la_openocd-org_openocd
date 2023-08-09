/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DiagService_CONSTANTS_H
#define DiagService_CONSTANTS_H

#include "DiagService_types.h"

namespace Uts {

class DiagServiceConstants {
 public:
  DiagServiceConstants();

  std::string DIAG_SERVICE_NAME;
};

extern const DiagServiceConstants g_DiagService_constants;

} // namespace

#endif
