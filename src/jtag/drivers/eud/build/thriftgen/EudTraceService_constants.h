/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef EudTraceService_CONSTANTS_H
#define EudTraceService_CONSTANTS_H

#include "EudTraceService_types.h"

namespace Uts {

class EudTraceServiceConstants {
 public:
  EudTraceServiceConstants();

  std::string EUD_TRACE_SERVICE_NAME;
};

extern const EudTraceServiceConstants g_EudTraceService_constants;

} // namespace

#endif
