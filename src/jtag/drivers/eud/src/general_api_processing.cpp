/*************************************************************************
* 
* Copyright (c) 2025 Qualcomm Innovation Center, Inc. All rights reserved.
* SPDX-License-Identifier: GPL-2.0 OR BSD-3-Clause
*
* File: 
*   general_api_processing.cpp
*
* Description:                                                              
*   CPP source file for EUD Jtag general APIs
*
***************************************************************************/
// #include "eud_api.h"
#include "com_eud.h"
#include "ctl_eud.h"
#include "jtag_eud.h"
#include "swd_eud.h"
#include "trc_eud.h"
#include "usb.h"
#include "device_manager.h"
#ifdef EUD_WIN_ENV
#include <Windows.h>
#else
#include <unistd.h>
#endif
extern "C" CtlEudDevice* eud_initialize_device_ctl (uint32_t deviceID, uint32_t options, EUD_ERR_t * errcode);
/*
 * How long (ms) to wait for EUD CTL to re-enumerate on USB after a
 * device reboot (e.g. PMIC hard reset) before giving up on sending
 * the SWD-disable command.
 *
 * Why this is needed:
 *   When a PMIC hard reset fires, EUD USB disconnects from the host.
 *   OpenOCD detects the SWD failure, raises SIGINT, and the normal
 *   shutdown path calls eud_close_peripheral().  At that point EUD is
 *   still disconnected, so eud_initialize_device_ctl() fails, and
 *   toggle_peripheral(DISABLE) is never sent.  EUD then re-enumerates
 *   after the device reboots with SWD_PERIPH_EN still set to 1, so the
 *   SWD node stays visible in Windows Device Manager — unlike a clean
 *   "shutdown" where the disable command is sent successfully.
 *
 *   The fix: retry the CTL open until EUD re-enumerates, then send the
 *   disable command.  This makes crash behaviour identical to clean
 *   shutdown from Device Manager's perspective.
 */
#define EUD_CLOSE_PERIPH_TIMEOUT_MS  8000   /* 8 s — covers full device boot */
#define EUD_CLOSE_PERIPH_RETRY_MS     200   /* poll every 200 ms             */
// EXPORT EUD_ERR_t eud_close_peripheral(PVOID* handle_p) {
extern "C" EUD_ERR_t eud_close_peripheral(PVOID* handle_p) {
    EUD_ERR_t err = EUD_SUCCESS;
    if (handle_p == NULL){
        return eud_set_last_error(EUD_ERR_BAD_HANDLE_PARAMETER);
    }
    uint32_t devicetype = ((EudDevice*)handle_p)->device_type_;
    uint32_t device_id  = ((EudDevice*)handle_p)->device_id_;
    uint32_t options    = 0;
    /* CTL peripheral has no sub-peripheral to disable — just free it. */
    if (devicetype == DEVICETYPE_EUD_CTL){
        delete ((EudDevice*)(handle_p));
        return EUD_SUCCESS;
    }
    /*
     * Retry loop: wait for EUD CTL to become available on USB.
     *
     * Normal (clean shutdown) case:
     *   EUD is still connected → first attempt succeeds immediately,
     *   elapsed_ms == 0, no delay at all.
     *
     * Crash (PMIC reset) case:
     *   EUD is disconnected → retries every 200 ms until EUD
     *   re-enumerates after the device reboots, then sends DISABLE.
     */
    CtlEudDevice* ctl_handle_p = NULL;
    int elapsed_ms = 0;
    while (elapsed_ms <= EUD_CLOSE_PERIPH_TIMEOUT_MS) {
        ctl_handle_p = eud_initialize_device_ctl(device_id, options, &err);
        if (ctl_handle_p != NULL && err == EUD_SUCCESS)
            break;  /* CTL is available — proceed with disable */
        /* First failure: log once so the reason is visible in the log. */
        if (elapsed_ms == 0) {
            QCEUD_Print("eud_close_peripheral: CTL open failed (err=0x%x), "
                        "EUD may be re-enumerating after device reboot. "
                        "Waiting up to %d ms...\n",
                        err, EUD_CLOSE_PERIPH_TIMEOUT_MS);
        }
        if (ctl_handle_p != NULL) {
            delete ctl_handle_p;
            ctl_handle_p = NULL;
        }
#ifdef EUD_WIN_ENV
        Sleep(EUD_CLOSE_PERIPH_RETRY_MS);
#else
        usleep((useconds_t)EUD_CLOSE_PERIPH_RETRY_MS * 1000);
#endif
        elapsed_ms += EUD_CLOSE_PERIPH_RETRY_MS;
    }
    if (ctl_handle_p == NULL || err != EUD_SUCCESS) {
        /*
         * EUD did not come back within the timeout.
         * Free the software handle but warn — the SWD node will remain
         * in Device Manager until the next clean OpenOCD shutdown.
         */
        QCEUD_Print("eud_close_peripheral: EUD CTL not available after "
                    "%d ms. SWD peripheral NOT disabled in hardware. "
                    "SWD node will remain in Device Manager.\n",
                    EUD_CLOSE_PERIPH_TIMEOUT_MS);
        delete ((EudDevice*)(handle_p));
        return err;
    }
    if (elapsed_ms > 0) {
        QCEUD_Print("eud_close_peripheral: CTL available after %d ms, "
                    "sending DISABLE command.\n", elapsed_ms);
    }
    /*
     * Send the DISABLE command.
     * This writes CTL_PAYLOAD_SWDOFF (= 0) to the EUD CTL register,
     * clearing SWD_PERIPH_EN.  EUD will then remove the SWD USB node
     * from the host — identical to what happens on a clean shutdown.
     */
    err = toggle_peripheral(ctl_handle_p, device_id, devicetype, DISABLE);
    if (err != EUD_SUCCESS) {
        QCEUD_Print("eud_close_peripheral: toggle_peripheral DISABLE "
                    "failed (err=0x%x)\n", err);
    }
    delete ((EudDevice*)(handle_p));
    delete ctl_handle_p;
    return err;
}

//===---------------------------------------------------------------------===//
//
// External API functions
//
//===---------------------------------------------------------------------===//

EUD_ERR_t
JTAG_EUD_Bitbang(   JtagEudDevice* jtg_handle_p, 
                    uint32_t tdi, 
                    uint32_t tms, 
                    uint32_t tck, 
                    uint32_t trst, 
                    uint32_t srst, 
                    uint32_t enable){
    

    if (jtg_handle_p == NULL){
        return eud_set_last_error(EUD_ERR_BAD_HANDLE_PARAMETER);
    }
    //return JtagEudDevice::Instance()->BitBang(tdi, tms, tck, trst, srst, enable);
    return jtg_handle_p->BitBang(tdi, tms, tck, trst, srst, enable);
}

EUD_ERR_t
JTAG_EUD_Scan(  JtagEudDevice* jtg_handle_p, 
                uint8_t *tms_raw, 
                uint8_t *tdi_raw, 
                uint8_t *tdo_raw, 
                uint32_t scan_length)
{
    

    if (jtg_handle_p == NULL){
        return eud_set_last_error(EUD_ERR_BAD_HANDLE_PARAMETER);
    }
    //return JtagEudDevice::Instance()->JtagScan(tms_raw, tdi_raw, tdo_raw, scan_length);
    return jtg_handle_p->JtagScan(tms_raw, tdi_raw, tdo_raw, scan_length);
}


EUD_ERR_t JTAG_CM_Read_Register(    JtagEudDevice* jtg_handle_p, 
                                    uint32_t * reg_addr, 
                                    uint32_t * rd_data){
    

    if (jtg_handle_p == NULL){
        return eud_set_last_error(EUD_ERR_BAD_HANDLE_PARAMETER);
    }

    return jtg_handle_p->JtagCmReadRegister(reg_addr, rd_data);

}

EUD_ERR_t JTAG_CM_Write_Register(   JtagEudDevice* jtg_handle_p, 
                                    unsigned * reg_addr, 
                                    uint32_t * reg_data){
    

    if (jtg_handle_p == NULL){
        return eud_set_last_error(EUD_ERR_BAD_HANDLE_PARAMETER);
    }

    return jtg_handle_p->JtagCmWriteRegister(reg_addr, reg_data);
}
