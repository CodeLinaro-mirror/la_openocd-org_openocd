/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef DeviceConfigService_CONSTANTS_H
#define DeviceConfigService_CONSTANTS_H

#include "DeviceConfigService_types.h"

namespace Uts {

class DeviceConfigServiceConstants {
 public:
  DeviceConfigServiceConstants();

  std::string DEVICE_CONFIG_SERVICE_NAME;
  int32_t PDC_CONFIGURATION_VALUE_INVALID;
  int32_t NO_SUBSCRIPTION_ID;
};

extern const DeviceConfigServiceConstants g_DeviceConfigService_constants;

} // namespace

#endif
