/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/

#pragma once
#include <iostream>

namespace Constants
{
	enum class ProductType
	{
		QPROF_CLI
	};

	enum class FeatureType
	{
		CORE,
		AIC,
		MAKENA
	};

	class Constants
	{
	public:
		static std::string getProductId(ProductType type);
		static std::string getFeatureId(FeatureType type);
	};
}

