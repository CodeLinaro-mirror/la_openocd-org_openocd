/**************************************************************************
 *	Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
 *   All rights reserved.                                                  *
 *   SPDX-License-Identifier: GPL-2.0-or-later                             *
 *																		  *
 ***************************************************************************/

#include <iostream>
#include <stdint.h>
#include "usb.h"
#include "string.h"
#include "TelematicsClient.h"
#include "TelematicsWrapper.h"
#include "LimeClient.h"
#include "LimeWrapper.h"

#include "eud_revision.h"
#define OPENOCD_ENV                             1
#define T32_ENV                                 2
/* EUD Product and Feature IDs */
#define EUD_INTERNAL_ID_KEY (std::string)("EUD_INTERNAL_ID")
#define EUD_EXTERNAL_ID_KEY (std::string)("EUD_EXTERNAL_ID")
#define EUD_INTERNAL_ID_VAL (std::string)("ebe459f6-acca-11e9-84a0-06e1158024a8")
#define EUD_EXTERNAL_ID_VAL (std::string)("bb0b29fe-acc9-11e9-84a0-06e1158024a8")
#define EUD_INTERNAL_CORE_FEATURE_ID_KEY (std::string)("EUD_CORE_FEATURE_ID")
#define EUD_INTERNAL_CORE_FEATURE_ID_VAL (std::string)("ebf9820c-acca-11e9-84a0-06e1158024a8")
#define EUD_EXTERNAL_CORE_FEATURE_ID_KEY EUD_INTERNAL_CORE_FEATURE_ID_KEY
#define EUD_EXTERNAL_CORE_FEATURE_ID_VAL (std::string)("bba3c886-acc9-11e9-84a0-06e1158024a8")
#define EUD_INTERNAL_DIAG_FEATURE_ID_KEY (std::string)("EUD_DIAG_FEATURE_ID")
#define EUD_INTERNAL_DIAG_FEATURE_ID_VAL (std::string)("160159f4-acce-11e9-84a0-06e1158024a8")
#define EUD_EXTERNAL_DIAG_FEATURE_ID_KEY EUD_INTERNAL_DIAG_FEATURE_ID_KEY
#define EUD_EXTERNAL_DIAG_FEATURE_ID_VAL (std::string)("2e7ce69a-acca-11e9-84a0-06e1158024a8")

static std::map<const std::string, std::string> EUD_Int_Feature_IDs, EUD_Ext_Feature_IDs, EUD_Product_IDs;
bool limeTelematicsCheck(const uint32_t &options, uint64_t& limeErrcode);

using namespace std;

// ----------------------------------------------------------------------------
// pLicenseDataInit
//
///
// ----------------------------------------------------------------------------
static void pLicenseDataInit(void)
{
    static bool pInitDone = false;

    if (pInitDone)
        return;
    else
    {
        EUD_Int_Feature_IDs[EUD_INTERNAL_CORE_FEATURE_ID_KEY] = EUD_INTERNAL_CORE_FEATURE_ID_VAL;
        EUD_Int_Feature_IDs[EUD_INTERNAL_DIAG_FEATURE_ID_KEY] = EUD_INTERNAL_DIAG_FEATURE_ID_VAL;
        EUD_Ext_Feature_IDs[EUD_EXTERNAL_CORE_FEATURE_ID_KEY] = EUD_EXTERNAL_CORE_FEATURE_ID_VAL;
        EUD_Ext_Feature_IDs[EUD_EXTERNAL_DIAG_FEATURE_ID_KEY] = EUD_EXTERNAL_DIAG_FEATURE_ID_VAL;
        EUD_Product_IDs[EUD_INTERNAL_ID_KEY] = EUD_INTERNAL_ID_VAL;
        EUD_Product_IDs[EUD_EXTERNAL_ID_KEY] = EUD_EXTERNAL_ID_VAL;
        pInitDone = true;
    }
}

bool limeTelematicsCheck(const uint32_t &options, uint64_t& limeErrcode)
{
    bool has_int_license, has_ext_license = false;
    eLimeReturnCode ClientInitSuccess, ClientIntSuccess, ClientExtSuccess = LIME_LICENSE_UNAVAILABLE;
    pLicenseDataInit();
    /* Initialize the client first */
    char emptyString[] = "";
    ClientInitSuccess = Lime_Initialize(emptyString, emptyString);
    if (ClientInitSuccess != LIME_CLIENT_SUCCESS)
    {
        QCEUD_Print("Lime init failure\n");
        limeErrcode = (uint64_t)ClientInitSuccess;
        return false;
    }

    /* Check Internal License. Assume it will be initialized to an entry in this hash map always. Otherwise, need to check if it exists etc. */
    ClientIntSuccess = Lime_CheckLicense((char *)EUD_Product_IDs[EUD_INTERNAL_ID_KEY].c_str(), (char *)EUD_Int_Feature_IDs[EUD_INTERNAL_CORE_FEATURE_ID_KEY].c_str());
    if (ClientIntSuccess == LIME_CLIENT_SUCCESS)
    {
        QCEUD_Print("Lime int license success\n");
        has_int_license = true;
    }
    else
    {
        limeErrcode = ((uint64_t)ClientIntSuccess & 0xFF);
    }
    /* Check External License*/
    ClientExtSuccess = Lime_CheckLicense((char *)EUD_Product_IDs[EUD_EXTERNAL_ID_KEY].c_str(), (char *)EUD_Ext_Feature_IDs[EUD_EXTERNAL_CORE_FEATURE_ID_KEY].c_str());
    if (ClientExtSuccess == LIME_CLIENT_SUCCESS)
    {
        QCEUD_Print("Lime ext license success\n");
        has_ext_license = true;
    }
    else
    {
        limeErrcode |= (((uint64_t)ClientExtSuccess & 0xFF) << 16);
    }

    if (false == has_int_license && false == has_ext_license)
        return false;

    if (options != OPENOCD_ENV && options != T32_ENV)
    {
        return false;
    }
    else
    {

        string eventId = " ";
        switch (options)
        {
        case OPENOCD_ENV:
            eventId = "OPENOCD";
            break;

        case T32_ENV:
            eventId = "T32_ENV";
            break;

        default:
            eventId = "OPENOCD";
            break;
        }

        eTelematicsReturnCode teleRetVal = TELEMATICS_LICENSE_UNAVAILABLE;
        teleRetVal = Telematics_Initialize((char *)EUD_Product_IDs[EUD_INTERNAL_ID_KEY].c_str(), (char *)EUD_Ext_Feature_IDs[EUD_INTERNAL_CORE_FEATURE_ID_KEY].c_str());

        if (teleRetVal != TELEMATICS_CLIENT_SUCCESS)
        {
            // INFO << "Telematics Intialize failure";
            return false;
        }

        string eventData = "EUD";
        teleRetVal = Telematics_TrackEvent(const_cast<char *>(eventId.c_str()), const_cast<char *>(eventData.c_str()));
        if (teleRetVal != TELEMATICS_CLIENT_SUCCESS)
        {
            // INFO << "Telematics Track event failure";
            return false;
        }
		eventId="EUD_Version";
        eventData = to_string(MAJOR_REV_ID)+"."+to_string(MINOR_REV_ID)+"."+to_string(SPIN_REV_ID) ;
        teleRetVal = Telematics_TrackEvent(const_cast<char *>(eventId.c_str()), const_cast<char *>(eventData.c_str()));
        if (teleRetVal != TELEMATICS_CLIENT_SUCCESS)
        {
            // INFO << "Telematics Track event failure";
            return false;
        }
        string metricId = "QPM-EUD";
        double metricData = 0;
        teleRetVal = Telematics_TrackMetric(const_cast<char *>(metricId.c_str()), metricData);
        if (teleRetVal != TELEMATICS_CLIENT_SUCCESS)
        {
            // INFO << "Telematics Track failure";
            return false;
        }
    }

    return true;
}
