/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#include "DeviceConfigService_constants.h"

namespace Uts {

const DeviceConfigServiceConstants g_DeviceConfigService_constants;

DeviceConfigServiceConstants::DeviceConfigServiceConstants() {
  DEVICE_CONFIG_SERVICE_NAME = "Device Config Service";

  PDC_CONFIGURATION_VALUE_INVALID = -1;

  NO_SUBSCRIPTION_ID = -1;

}

} // namespace

