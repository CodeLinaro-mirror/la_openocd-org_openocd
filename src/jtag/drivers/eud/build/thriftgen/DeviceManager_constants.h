/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DeviceManager_CONSTANTS_H
#define DeviceManager_CONSTANTS_H

#include "DeviceManager_types.h"

namespace Uts {

class DeviceManagerConstants {
 public:
  DeviceManagerConstants();

  std::string DEVICE_MANAGER_SERVICE_NAME;
};

extern const DeviceManagerConstants g_DeviceManager_constants;

} // namespace

#endif
