/**************************************************************************
*   Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*                                                                         *
***************************************************************************/


#include "Constants.h"

namespace Constants
{

#if defined EXTERNAL
	const std::string G_QPROF_PRODUCT_ID = "c9662978-d7b7-11ec-aebb-063166a9270b";
	const std::string G_QPROF_CORE_FEATURE_ID = "c9722109-d7b7-11ec-aebb-063166a9270b";
	const std::string G_QPROF_AIC_FEATURE_ID = "c9722109-d7b7-11ec-aebb-063166a9270b";
	const std::string G_QPROF_MAKENA_FEATURE_ID = "c9722109-d7b7-11ec-aebb-063166a9270b";
#else
	const std::string G_QPROF_PRODUCT_ID = "c9662978-d7b7-11ec-aebb-063166a9270b";
	const std::string G_QPROF_CORE_FEATURE_ID = "c9722109-d7b7-11ec-aebb-063166a9270b";
	const std::string G_QPROF_AIC_FEATURE_ID = "c9722109-d7b7-11ec-aebb-063166a9270b";
	const std::string G_QPROF_MAKENA_FEATURE_ID = "c9722109-d7b7-11ec-aebb-063166a9270b";
#endif


	std::string Constants::getProductId(ProductType type)
	{
		switch (type)
		{
			case ProductType::QPROF_CLI:
				return G_QPROF_PRODUCT_ID;
			default:
				return "";
		}
	}

	std::string Constants::getFeatureId(FeatureType type)
	{
		switch (type)
		{
		case FeatureType::CORE:
			return G_QPROF_CORE_FEATURE_ID;
		case FeatureType::AIC:
			return G_QPROF_AIC_FEATURE_ID;
		case FeatureType::MAKENA:
			return G_QPROF_MAKENA_FEATURE_ID;
		default:
			return "";
		}
	}
}
