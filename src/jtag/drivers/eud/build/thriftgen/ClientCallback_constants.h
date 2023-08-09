/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef ClientCallback_CONSTANTS_H
#define ClientCallback_CONSTANTS_H

#include "ClientCallback_types.h"

namespace Uts {

class ClientCallbackConstants {
 public:
  ClientCallbackConstants();

  std::string CLIENT_CALLBACK_SERVICE_NAME;
};

extern const ClientCallbackConstants g_ClientCallback_constants;

} // namespace

#endif
