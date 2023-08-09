/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#ifndef ImageManagementService_CONSTANTS_H
#define ImageManagementService_CONSTANTS_H

#include "ImageManagementService_types.h"

namespace Uts {

class ImageManagementServiceConstants {
 public:
  ImageManagementServiceConstants();

  std::string IMAGE_MANAGEMENT_SERVICE_NAME;
};

extern const ImageManagementServiceConstants g_ImageManagementService_constants;

} // namespace

#endif
