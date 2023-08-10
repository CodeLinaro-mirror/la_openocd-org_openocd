/**************************************************************************
 *	Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
 *   All rights reserved.                                                  *
 *   SPDX-License-Identifier: GPL-2.0-or-later                             *
 *																		  *
 ***************************************************************************/

// Macro to enable / disable QUTS
#define QUTS_GATEWAY

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#ifndef KILLPROCESS
#define KILLPROCESS
#endif

#ifdef KILLPROCESS
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#endif

#if (defined(__GNUC__) && defined(__unix__))
#include <dlfcn.h>
#endif

#include <jtag/interface.h>
#include "bitbang.h"
#include "hello.h"
#include <helper/time_support.h>

#ifndef QUTS_GATEWAY
#include "internal/EudAPI.h"
#else
typedef int EUD_ERR_t;
#endif

#define SWD_BITBANG_CLK_SHFT 0
#define SWD_BITBANG_DI_SHFT 1
#define SWD_BITBANG_RCTLR_SRST_N_SHFT 2
#define SWD_BITBANG_GPIO_DI_OE 3
#define SWD_BITBANG_GPIO_SRST_N_SHFT 4
#define SWD_BITBANG_GPIO_TRST_N_SHFT 5
#define SWD_BITBANG_DAP_TRST_N_SHFT 6
#define EUD_SUCCESS 0

#define SWD_BITBANG_CLK_BMSK_ASSERT (1 << SWD_BITBANG_CLK_SHFT)
#define SWD_BITBANG_CLK_BMSK_DEASSERT (0 << SWD_BITBANG_CLK_SHFT)

#define SWD_BITBANG_DI_BMSK_ASSERT (1 << SWD_BITBANG_DI_SHFT)
#define SWD_BITBANG_DI_BMSK_DEASSERT (0 << SWD_BITBANG_DI_SHFT)

#define SWD_BITBANG_RCTLR_SRST_BMSK_ASSERT (0 << SWD_BITBANG_RCTLR_SRST_N_SHFT)
#define SWD_BITBANG_RCTLR_SRST_BMSK_DEASSERT (1 << SWD_BITBANG_RCTLR_SRST_N_SHFT)

#define SWD_BITBANG_GPIO_DI_OE_ASSERT (1 << SWD_BITBANG_GPIO_DI_OE)
#define SWD_BITBANG_GPIO_DI_OE_DEASSERT (0 << SWD_BITBANG_GPIO_DI_OE)

#define SWD_BITBANG_GPIO_SRST_BMSK_ASSERT (0 << SWD_BITBANG_GPIO_SRST_N_SHFT)
#define SWD_BITBANG_GPIO_SRST_BMSK_DEASSERT (1 << SWD_BITBANG_GPIO_SRST_N_SHFT)

#define SWD_BITBANG_GPIO_TRST_BMSK_ASSERT (0 << SWD_BITBANG_GPIO_TRST_N_SHFT)
#define SWD_BITBANG_GPIO_TRST_BMSK_DEASSERT (1 << SWD_BITBANG_GPIO_TRST_N_SHFT)

#define SWD_BITBANG_DAP_TRST_BMSK_ASSERT (0 << SWD_BITBANG_DAP_TRST_N_SHFT)
#define SWD_BITBANG_DAP_TRST_BMSK_DEASSERT (1 << SWD_BITBANG_DAP_TRST_N_SHFT)
#define FLUSH_OPTION_NULL 0
#define FLUSH_OPTION_TRUE 1

#if 0
#define EUD_CMD_COUNT_LOGGING 1

#endif
// for unix system dlsym lib API will be used to map to exported functions
#if (defined(__GNUC__) && defined(__unix__))
#define LOAD_EXPORTED_FUNC dlsym
#endif
// for windows system GetProcAddress lib API will be used to map to exported functions
#if defined(__WIN32) || defined(__WIN64)
#define LOAD_EXPORTED_FUNC GetProcAddress
#endif

typedef void swd_eud_device;
typedef void jtg_eud_device;
typedef void ctl_eud_device;

#ifndef QUTS_GATEWAY
// Function pointers for exported functions in EUD.DLL
// Note: Here f is suffix for functions names exported in EUD.DLL
EXPORT EUD_ERR_t SWDSetDelay(swd_eud_device *swd_handle_p, uint32_t delaytime);
EUD_ERR_t (*fSWDBitBang)(swd_eud_device *, uint32_t, uint32_t *);
EUD_ERR_t (*fJTAG_to_SWD)(swd_eud_device *);
EUD_ERR_t (*fSWDSetFrequency)(swd_eud_device *, uint32_t);
EUD_ERR_t (*fSWDRead)(swd_eud_device *, uint32_t, uint32_t, uint32_t *);
EUD_ERR_t (*fSWDWrite)(swd_eud_device *, uint32_t, uint32_t, uint32_t);
EUD_ERR_t (*fSWDRead_NoFlush)(swd_eud_device *, uint32_t, uint32_t, uint32_t *);
EUD_ERR_t (*fSWDWrite_NoFlush)(swd_eud_device *, uint32_t, uint32_t, uint32_t);
EUD_ERR_t (*fswdflushbuffers)(swd_eud_device *, uint32_t);
EUD_ERR_t (*fEUDMSMReset)(uint32_t, uint32_t);
EUD_ERR_t (*fEUD_JTAG_TRST)(jtg_eud_device *);
EUD_ERR_t (*fSWD_GetJTAGID)(swd_eud_device *, uint32_t *);
EUD_ERR_t (*fGetDeviceIDArray)(uint32_t *, uint32_t *);
swd_eud_device *(*fEUDInitializeDeviceSWD)(uint32_t, uint32_t, EUD_ERR_t *);
swd_eud_device *(*fEUDInitializeDeviceJTG)(uint32_t, uint32_t, EUD_ERR_t *);
// EUD library handler
static void *eudLibHandler = NULL;
static swd_eud_device *gpSWDDevice = NULL;
#endif

static uint32_t gDeviceId = 0;
static uint32_t cmd_count;
#define CTRLSTAT_CHECK_ENABLED 1
#define CTRLSTAT_READ_ENABLED 1

#ifdef QUTS_GATEWAY
int EudInitWrapper(void);
int EudSWDInitWrapper(void);
int SwdReadWrapper(uint32_t, uint32_t, uint32_t *);
int SwdWriteWrapper(uint32_t, uint32_t, uint32_t);
int EudQuitWrapper(void);
void Jtag_to_SWD(void);
int SwdFlush(void);
int BitbangWrapper(uint32_t bitBangVal, uint32_t *returnPtr);
#endif

static void kill_process(void);

#ifdef KILLPROCESS
static void kill_process(void)
{
    // pid_t ppid = getppid();
    // pid_t pid  = getpid();
    // LOG_DEBUG ("PPID = %u, PID = %u", ppid, pid);
    // kill (pid, SIGINT);
    raise(SIGINT);
}
#endif

#if 1
int eud_switch_seq(enum swd_special_seq seq)
{
    EUD_ERR_t err = EUD_SUCCESS;
    // LOG_DEBUG("eud_switch_seq\n");
    switch (seq)
    {
    case JTAG_TO_SWD:
#ifndef QUTS_GATEWAY
        err = fJTAG_to_SWD(gpSWDDevice);
#endif
        if (err != EUD_SUCCESS)
            return ERROR_FAIL;
        break;

    case LINE_RESET:
    case SWD_TO_JTAG:
    case SWD_TO_DORMANT:
    case DORMANT_TO_SWD:
    default:
        return ERROR_FAIL;
        break;
    }

    return ERROR_OK;
}
#endif

#if CTRLSTAT_CHECK_ENABLED
#ifdef QUTS_GATEWAY
static int eud_swd_run(void)
{

    EUD_ERR_t err;
    LOG_DEBUG("eud_swd_run APi invoked");

#ifdef EUD_CMD_COUNT_LOGGING

    LOG_DEBUG("eud_swd_run: cmd_count: %d", cmd_count);
#endif

    err = SwdFlush();
    cmd_count = 0;
    if (err != EUD_SUCCESS)
    {
        LOG_ERROR("swdflushbuffers FAILED!!");
    }

    return err;
}
#endif

static void eud_ensure_dbg_sys_pwr_is_on(void)
{

    uint32_t APnDP = 0;
    uint32_t A2_3 = 0;
    EUD_ERR_t err;
    uint32_t val;

#ifdef QUTS_GATEWAY
    static int call_count = 0;

    if (call_count > 2500)
    {
        LOG_DEBUG("Reached 100 count for eud_ensure_dbg_sys_pwr_is_on call");
        return;
    }
    else
        call_count++;
#endif

#if CTRLSTAT_READ_ENABLED

    uint32_t readval = 0, dbg_sys_bits;
    int i = 0;

#endif

    APnDP = 0;
    A2_3 = 1;
    // val=(uint32_t)(0x50000020);  /* changing value from 0x50000020  to 0x50000000 as suggested by Dushyanth*/
    val = (uint32_t)(0x50000000);

    // Writing register: CTRL/STAT register , Write Data : 0x50000020
    // Opcode : a9 - APnDP: 0, RnW: 0, A2_3: 1
    // Write operation to Debug Port Register: 4
    // WriteToDevice 6c07860; Buffer: 0xa920005071; Bytes: 7
    cmd_count += 5;
#ifndef QUTS_GATEWAY
    err = fSWDWrite(gpSWDDevice, APnDP, A2_3, val);
#else

    err = SwdWriteWrapper(APnDP, A2_3, val);
#endif

    if (err != EUD_SUCCESS)
    {

        LOG_ERROR("CTRLSTAT Write FAILED!!");

        return;
    }

#if CTRLSTAT_READ_ENABLED
    // Read
    // Opcode : 8d - APnDP: 0, RnW: 1, A2_3: 1
    // Read operation to Debug Port Register: 4
    // WriteToDevice 6c07860; Buffer: 0x8d71; Bytes: 3

    while (i < 10)
    {
        cmd_count++;
#ifndef QUTS_GATEWAY
        err = fSWDRead(gpSWDDevice, APnDP, A2_3, &readval);

#else
        // LOG_DEBUG(" swdread wrapper call \n");
        err = SwdReadWrapper(APnDP, A2_3, &readval);
        // LOG_DEBUG(" swdread wrapper end \n");
#endif

        /*	if(!i)
            {
                LOG_DEBUG("readval/ CTRLSTAT  = 0x%x and i = %d",readval,i);
            }*/

#ifdef QUTS_GATEWAY // needed for buffer
        err = eud_swd_run();
#endif
        if (err != EUD_SUCCESS)
        {
            LOG_ERROR("CTRLSTAT Read FAILED!!");
#ifdef KILLPROCESS
            kill_process();
#endif
            return;
        }
        i++;
        dbg_sys_bits = readval & (uint32_t)(0xf0000000);

        // if(dbg_sys_bits == (uint32_t)(0xf0000000))
        if ((dbg_sys_bits == (uint32_t)(0xf0000000)) | (dbg_sys_bits == (uint32_t)(0x70000000)))
            break;

        if (i == 10)
        {
            LOG_ERROR("CTRLSTAT read did not return right value even after 10 tries!!");
#ifdef KILLPROCESS
            kill_process();
#endif
        }
    }
#endif
}

#endif

uint32_t dummy_read;
static void eud_swd_read(uint8_t cmd, uint32_t *value, uint32_t ap_delay_hint)
{

    LOG_DEBUG("swdread call \n");
    uint32_t APnDP = 0;
    uint32_t A2_3 = 0;
    EUD_ERR_t err;

    (void)ap_delay_hint;
    APnDP = (cmd >> 1) & 0x1;
    A2_3 = (cmd >> 3) & 0x3;

    if (ap_delay_hint > 0)
    {

        uint32_t i;
        for (i = 0; i < 2000; i++)
        {
        }
    }

#if CTRLSTAT_CHECK_ENABLED
    // Dont touch ctrlstat register, if DAPIDR or ctrlstat is being read
    if (!(((APnDP == 0) && ((A2_3 == 0) || (A2_3 == 1)))))
        eud_ensure_dbg_sys_pwr_is_on();
#endif
    cmd_count++;

#ifdef QUTS_GATEWAY
    if (value == NULL)
    {
        LOG_DEBUG("swdread wrapper call \n");

        err = SwdReadWrapper(APnDP, A2_3, &dummy_read);

        LOG_DEBUG("swdread wrapper end \n");

        if (err != EUD_SUCCESS)
            LOG_ERROR("SWD Read FAILED!!");
#if 0		

		err = eud_swd_run();
		
		if (err != EUD_SUCCESS)
		{
			LOG_ERROR("CTRLSTAT Read Flush FAILED for NULL case!!");
			return;
		}
#endif
        return;
    }
    else
    {

        LOG_DEBUG("swdread wrapper call \n");

        err = SwdReadWrapper(APnDP, A2_3, value);

        LOG_DEBUG("swdread wrapper end \n");
    }
#endif
#ifndef QUTS_GATEWAY
    uint32_t val = 0;
    err = fSWDRead(gpSWDDevice, APnDP, A2_3, &val);
#endif
    if (err != EUD_SUCCESS)
    {
        LOG_ERROR("SWD Read FAILED!!");
#ifdef KILLPROCESS
        kill_process();
#endif
    }
    else
    {
#ifndef QUTS_GATEWAY
        if (value != NULL)
            *value = val;
#endif
    }

    LOG_DEBUG("swdread  end \n");
    return;
}

static void eud_swd_write(uint8_t cmd, uint32_t value, uint32_t ap_delay_hint)
{

    LOG_DEBUG("swd write call \n");
    uint32_t APnDP = 0;
    uint32_t A2_3 = 0;
    EUD_ERR_t err;
    // static int j;

    (void)ap_delay_hint;
    APnDP = (cmd >> 1) & 0x1;
    A2_3 = (cmd >> 3) & 0x3;

#if 0
	if (ap_delay_hint > 0)
      Sleep (1);
#endif

#if 1
    if (ap_delay_hint > 0)
    {

        uint32_t i;
        for (i = 0; i < 20000; i++)
        {
        }
    }
#endif

#if CTRLSTAT_CHECK_ENABLED

    // Dont touch ctrlstat register, if ABORT or ctrlstat register is being written to
    if (!(((APnDP == 0) && ((A2_3 == 0) || (A2_3 == 1)))))
        eud_ensure_dbg_sys_pwr_is_on();
#endif

    cmd_count += 5;
#ifndef QUTS_GATEWAY
    err = fSWDWrite(gpSWDDevice, APnDP, A2_3, value);
#else

    LOG_DEBUG("swd write wrapper call \n");

    err = SwdWriteWrapper(APnDP, A2_3, value);

    LOG_DEBUG("swd write wrapper end \n");

#endif

    if (err != EUD_SUCCESS)
        LOG_ERROR("SWD Write FAILED!!");

    LOG_DEBUG("swd write end \n");
    return;
}

int eud_AssertReset(void)
{
    EUD_ERR_t err;
    uint32_t return_val = 0; // DPIDR = 0;
    uint32_t DPIDR = 0;      // DPIDR = 0;

#ifndef QUTS_GATEWAY
    fSWD_GetJTAGID(gpSWDDevice, &DPIDR);
#endif

    // Assert reset and tap reset
    uint32_t swd_bitbang_value =
        SWD_BITBANG_CLK_BMSK_DEASSERT +
        SWD_BITBANG_DI_BMSK_DEASSERT +
        SWD_BITBANG_RCTLR_SRST_BMSK_ASSERT + // this is the reset value
        SWD_BITBANG_GPIO_DI_OE_DEASSERT +
        SWD_BITBANG_GPIO_SRST_BMSK_DEASSERT +
        SWD_BITBANG_GPIO_TRST_BMSK_DEASSERT +
        SWD_BITBANG_DAP_TRST_BMSK_ASSERT; // Also reset TAP

#ifndef QUTS_GATEWAY
    err = fSWDBitBang(gpSWDDevice, swd_bitbang_value, &return_val);
#else
    LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper call val: %" PRIu32 " \n", swd_bitbang_value);
    err = BitbangWrapper(swd_bitbang_value, &return_val);
    LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper end \n");
#endif
    // De-assert tap reset but keep SRST asserted.
    swd_bitbang_value =
        SWD_BITBANG_CLK_BMSK_DEASSERT +
        SWD_BITBANG_DI_BMSK_DEASSERT +
        SWD_BITBANG_RCTLR_SRST_BMSK_ASSERT + // this is the reset value
        SWD_BITBANG_GPIO_DI_OE_DEASSERT +
        SWD_BITBANG_GPIO_SRST_BMSK_DEASSERT +
        SWD_BITBANG_GPIO_TRST_BMSK_DEASSERT +
        SWD_BITBANG_DAP_TRST_BMSK_DEASSERT; // Deassert TAP reset

#ifndef QUTS_GATEWAY
    err = fSWDBitBang(gpSWDDevice, swd_bitbang_value, &return_val);
#else
    LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper call val: %" PRIu32 " \n", swd_bitbang_value);
    err = BitbangWrapper(swd_bitbang_value, &return_val);
    LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper end \n");
#endif
    if (err != ERROR_OK)
    {
        printf("%s error: line %d\n", __FUNCTION__, __LINE__);
        return err;
    }

#ifndef QUTS_GATEWAY
    fSWD_GetJTAGID(gpSWDDevice, &DPIDR);
#endif

    printf(" From inside assert api, before jtag to swd DPIDR: %x\n", DPIDR);

#ifdef QUTS_GATEWAY
    Jtag_to_SWD();
#endif
#if 0
	err = fJTAG_to_SWD(gpSWDDevice);
	
	if (err != ERROR_OK)
			{
			printf("%s error: line %d\n", __FUNCTION__, __LINE__);
			return err;
		}
#endif
#if 0
	err = fSWD_GetJTAGID(gpSWDDevice, &DPIDR);
     printf(" From inside assert api, after assert DPIDR: %x\n",	DPIDR);	
	if (err != ERROR_OK)
			{
			printf("%s error: line %d\n", __FUNCTION__, __LINE__);
			return err;
		}

#endif

    return err;
}

int eud_DeAssertReset(void)
{
    EUD_ERR_t err;
    uint32_t return_val = 0;
    // deassert reset
    uint32_t swd_bitbang_value =
        SWD_BITBANG_CLK_BMSK_DEASSERT +
        SWD_BITBANG_DI_BMSK_DEASSERT +
        SWD_BITBANG_RCTLR_SRST_BMSK_DEASSERT + // this is thede reset value
        SWD_BITBANG_GPIO_DI_OE_DEASSERT +
        SWD_BITBANG_GPIO_SRST_BMSK_DEASSERT +
        SWD_BITBANG_GPIO_TRST_BMSK_DEASSERT +
        SWD_BITBANG_DAP_TRST_BMSK_DEASSERT;

#ifndef QUTS_GATEWAY
    err = fSWDBitBang(gpSWDDevice, swd_bitbang_value, &return_val);
#else
    LOG_DEBUG("OCD: Bitbang eud_DeAssertReset wrapper call val: %" PRIu32 " \n", swd_bitbang_value);
    err = BitbangWrapper(swd_bitbang_value, &return_val);
    LOG_DEBUG("OCD: Bitbang eud_DeAssertReset wrapper end \n");
#endif
    if (err != ERROR_OK)
    {
        printf("%s error: line %d\n", __FUNCTION__, __LINE__);
        return err;
    }

    return err;
}

int eud_reset(int trst, int srst)
{
    LOG_DEBUG("eud_reset call \n");
    int retval = EUD_SUCCESS;

    if (srst == 1)
    {
        retval = eud_AssertReset();

        if (retval)
        {
            printf("libeud_reset call libusb_AssertReset, error code %x\n", retval);
            return retval;
        }

        printf("libeud_reset call libusb_AssertReset successfully\n");
    }
    else
    {

        retval = eud_DeAssertReset();

        if (retval)
        {
            printf("libeud_reset call libusb_DeAssertReset, error code %x\n", retval);
            return retval;
        }

        printf("libeud_reset call libusb_DeAssertReset successfully\n");
    }

    return retval;
}

#if 0

static int eud_reset(int trst, int srst)
{
	EUD_ERR_t err;

	err = libeud_reset(trst, srst, gpSWDDevice);

	if (err != ERROR_OK)
	{
		LOG_ERROR("eud_reset error\n");
		return err;
	}

#if 0

	if (srst == 1)
	{
		if (gDeviceId != 0)
		{
			err = fEUDMSMReset (gDeviceId, 1000);
			if (err != EUD_SUCCESS)
				return ERROR_FAIL;
		}
	}

	if (trst == 1)
	{
		err = fEUD_JTAG_TRST(gpJTGDevice);
		if (err != EUD_SUCCESS)
			return ERROR_FAIL;
	}
#endif
	return ERROR_OK;
}

#endif

#define EUD_SWD_FREQ_120_MHz 0x0
#define EUD_SWD_FREQ_80_MHz 0x1

static int eud_khz(int khz, int *speed)
{
    // LOG_DEBUG("eud_khz \n");
    if (khz >= 0 && khz <= 1875)
        *speed = 0x6;
    else if (khz > 1875 && khz <= 3750)
        *speed = 0x5;
    else if (khz > 3750 && khz <= 7500)
        *speed = 0x4;
    else if (khz > 7500 && khz <= 10000)
        *speed = 0x3;
    else if (khz > 10000 && khz <= 15000)
        *speed = 0x2;

    // hard code speed to 15 mhz
    //	*speed=2;
    return ERROR_OK;
    /*
        - 0x0:  30 MHz	not supported
        - 0x1:  20 MHz	not supported
        - 0x2:  15 MHz
        - 0x3:  10 MHz
        - 0x4:  7.5 MHz
        - 0x5:  3.75 MHz
        - 0x6:  1.875 MHz
        - 0x7:  938 kHz	not supported
        - 0x8:  469 kHz	not supported
        - 0x9:  234 kHz	not supported
        - 0xA:  117 kHz	not supported
        - 0xB:  59 kHz	not supported
        - 0xC:  30 kHz	not supported
    */

#if 0
	if (khz >= 0  && khz <= 117)
		*jtag_speed = 0xC;     // EUD_SWD_FREQ_0_117_MHz
	else if (khz > 117  && khz <= 234)
		*jtag_speed = 0xB;     // EUD_SWD_FREQ_0_234_MHz
	else if (khz > 234  && khz <= 469)
			*jtag_speed = 0xA; // EUD_SWD_FREQ_0_469_MHz
	else if (khz > 469  && khz <= 938)
			*jtag_speed = 0x9; // EUD_SWD_FREQ_0_938_MHz
	else if (khz > 938  && khz <= 1875)
			*jtag_speed = 0x8; // EUD_SWD_FREQ_1_875_MHz
	else if (khz > 1875  && khz <= 3750)
			*jtag_speed = 0x7; // EUD_SWD_FREQ_3_75_MHz
	else if (khz > 3750  && khz <= 7500)
			*jtag_speed = 0x6; // EUD_SWD_FREQ_7_5_MHz
	else if (khz > 7500  && khz <= 15000)
			*jtag_speed = 0x5; // EUD_SWD_FREQ_15_MHz
	else if (khz > 15000  && khz <= 30000)
			*jtag_speed = 0x4; // EUD_SWD_FREQ_30_MHz
	else if (khz > 30000  && khz <= 40000)
			*jtag_speed = 0x3; // EUD_SWD_FREQ_40_MHz
	else if (khz > 40000  && khz <= 60000)
			*jtag_speed = 0x2; // EUD_SWD_FREQ_60_MHz
	else if (khz > 60000  && khz <= 80000)
			*jtag_speed = 0x1; // EUD_SWD_FREQ_80_MHz
	else if (khz > 80000)
			*jtag_speed = 0x0; // EUD_SWD_FREQ_120_MHz
#endif

    // return ERROR_OK;
}

#if 0
static int eud_speed_div(int speed, int *khz)
{
	if (speed == 0)
		*khz = 0;
	else
		*khz = 64000/speed;

	return ERROR_OK;
}
#endif

static int eud_set_speed(int speed)
{
    // LOG_DEBUG("eud_set_speed call \n");
    EUD_ERR_t err = EUD_SUCCESS;

#ifndef QUTS_GATEWAY
    err = fSWDSetFrequency(gpSWDDevice, 0x2);
#endif

    if (err != EUD_SUCCESS)
        return ERROR_FAIL;

    return ERROR_OK;
}

static int eud_init(void)
{
    // LOG_ERROR("eud init called");
#if 0
    // bitbang_interface = &eud_bitbang;
    EUD_ERR_t err;
    uint32_t arr[100] = {0}, len;

// LIB USB Init???
#ifndef QUTS_GATEWAY
    err = fGetDeviceIDArray(arr, &len);
    if (err == EUD_SUCCESS)
    {
        gDeviceId = arr[0];
        return ERROR_FAIL;
    }
#endif

#endif

#ifdef QUTS_GATEWAY
    LOG_DEBUG("eud init wrapper call");
    // if (ERROR_OK != EudInitWrapper())
    // {
    //     return ERROR_FAIL;
    // }
#endif

    LOG_DEBUG("eud init end");
    return ERROR_OK;
}

static int eud_quit(void)
{

    // LOG_DEBUG("eud_quit call \n");
#ifndef QUTS_GATEWAY
#if defined(__WIN32) || defined(__WIN64)
    FreeLibrary(eudLibHandler);
#endif
#if (defined(__GNUC__) && defined(__unix__))
    dlclose(eudLibHandler);
#endif
#endif

#if 0
	EUD_ERR_t  err;

	if (gpSWDDevice != NULL)
	{
		err = EUDClosePeripheral (gpSWDDevice);
		if (err != EUD_SUCCESS)
			return ERROR_FAIL;
	}
#endif
#ifdef QUTS_GATEWAY
    int err = EudQuitWrapper();
    if (err != ERROR_OK)
        return -1;
#endif
    return ERROR_OK;
}

#ifndef QUTS_GATEWAY
static int eud_lib_init(void)
{
    LOG_DEBUG("eud_lib_init call \n");
    int retStatus = ERROR_FAIL;
#ifndef QUTS_GATEWAY
#if defined(__WIN32) || defined(__WIN64)
    // This will look for specified DLL under current directory or under directories mentioned in %PATH%
    eudLibHandler = LoadLibraryExA(TEXT("EUD.dll"), NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
#endif

#if (defined(__GNUC__) && defined(__unix__))
    // dlopen will look for specified .so file on path listed under LD_LIBRARY_PATH
    // use printenv to check for listed path or set using 'export LD_LIBRARY_PATH=/usr/local/lib:<anotherPath>:$LD_LIBRARY_PATH'
    // Multiple directory path can be added in LD_LIBRARY_PATH
    eudLibHandler = dlopen("libeud.so", RTLD_LAZY);
#endif
#endif
#ifndef QUTS_GATEWAY
    if (NULL != eudLibHandler)
    {
        // Get address of all exported functions needed here

        fSWDBitBang = (EUD_ERR_t(*)(swd_eud_device *, uint32_t, uint32_t *))LOAD_EXPORTED_FUNC(eudLibHandler, "SWDBitBang");

        if (NULL == fSWDBitBang)
        {
            LOG_ERROR("SWDBitBang function not exported");
        }

        fJTAG_to_SWD = (EUD_ERR_t(*)(swd_eud_device *))LOAD_EXPORTED_FUNC(eudLibHandler, "JTAG_to_SWD");
        if (NULL == fJTAG_to_SWD)
        {
            LOG_ERROR("JTAG_to_SWD function not exported");
        }

        fSWDSetFrequency = (EUD_ERR_t(*)(swd_eud_device *, uint32_t))LOAD_EXPORTED_FUNC(eudLibHandler, "SWDSetFrequency");
        if (NULL == fSWDSetFrequency)
        {
            LOG_ERROR("SWDSetFrequency function not exported");
        }

        fSWDRead = (EUD_ERR_t(*)(swd_eud_device *, uint32_t, uint32_t, uint32_t *))LOAD_EXPORTED_FUNC(eudLibHandler, "SWDRead");
        if (NULL == fSWDRead)
        {
            LOG_ERROR("SWDRead function not exported");
        }

        fSWDWrite = (EUD_ERR_t(*)(swd_eud_device *, uint32_t, uint32_t, uint32_t))LOAD_EXPORTED_FUNC(eudLibHandler, "SWDWrite");
        if (NULL == fSWDWrite)
        {
            LOG_ERROR("SWDWrite function not exported");
        }

        fswdflushbuffers = (EUD_ERR_t(*)(swd_eud_device *, uint32_t))LOAD_EXPORTED_FUNC(eudLibHandler, "swdflushbuffers");
        if (NULL == fswdflushbuffers)
        {
            LOG_ERROR("swdflushbuffers function not exported");
        }

        fEUDMSMReset = (EUD_ERR_t(*)(uint32_t, uint32_t))LOAD_EXPORTED_FUNC(eudLibHandler, "EUDMSMReset");
        if (NULL == fEUDMSMReset)
        {
            LOG_ERROR("EUDMSMReset function not exported");
        }

        fEUD_JTAG_TRST = (EUD_ERR_t(*)(jtg_eud_device *))LOAD_EXPORTED_FUNC(eudLibHandler, "EUD_JTAG_TRST");
        if (NULL == fEUD_JTAG_TRST)
        {
            LOG_ERROR("EUD_JTAG_TRST function not exported");
        }

        fSWD_GetJTAGID = (EUD_ERR_t(*)(swd_eud_device *, uint32_t *))LOAD_EXPORTED_FUNC(eudLibHandler, "SWD_GetJTAGID");
        if (NULL == fSWD_GetJTAGID)
        {
            LOG_ERROR("SWD_GetJTAGID function not exported");
        }

        fGetDeviceIDArray = (EUD_ERR_t(*)(uint32_t *, uint32_t *))LOAD_EXPORTED_FUNC(eudLibHandler, "GetDeviceIDArray");
        if (NULL == fGetDeviceIDArray)
        {
            LOG_ERROR("GetDeviceIDArray function not exported");
        }

        fEUDInitializeDeviceSWD = (swd_eud_device * (*)(uint32_t, uint32_t, EUD_ERR_t *)) LOAD_EXPORTED_FUNC(eudLibHandler, "EUDInitializeDeviceSWD");
        if (NULL == fEUDInitializeDeviceSWD)
        {
            LOG_ERROR("EUDInitializeDeviceSWD function not exported");
        }

        retStatus = ERROR_OK;
    }
    else
    {
        LOG_ERROR("Shared Library Not Found");
    }
#endif
    return retStatus;
}
#endif

static int eud_swd_init(void)
{
    // LOG_DEBUG("eud swd init start");
    EUD_ERR_t err = EUD_SUCCESS;
    uint32_t arr[100] = {0};

    // Load EUD executable and exported functions

#ifndef QUTS_GATEWAY
    uint32_t len = 0;
    int initStatus = eud_lib_init();
    if (initStatus != ERROR_OK)
        return initStatus;

    err = fGetDeviceIDArray(arr, &len);
#endif
    if (err != EUD_SUCCESS)
        return ERROR_FAIL;

    gDeviceId = arr[0];
#ifndef QUTS_GATEWAY
    gpSWDDevice = fEUDInitializeDeviceSWD(gDeviceId, 0, &err);
#endif
#ifdef QUTS_GATEWAY
    LOG_DEBUG("eud swd init -eud init wrapper call ");
    EudInitWrapper();
    LOG_DEBUG("eud swd init  wrapper call ");
    err = EudSWDInitWrapper();
#endif
    if (err != EUD_SUCCESS)
        return ERROR_FAIL;
    LOG_DEBUG("eud swd init end");
    return err;
}

#define FLUSH_OPTION_NULL 0
#define FLUSH_OPTION_TRUE 1

#if 0
static int eud_khz(int khz, int *jtag_speed)
{
	*jtag_speed = khz;

	return ERROR_OK;
}
#endif

#ifndef QUTS_GATEWAY
static int eud_swd_run(void)
{

    EUD_ERR_t err = EUD_SUCCESS;
#ifndef QUTS_GATEWAY
    // err = fswdflushbuffers(gpSWDDevice, FLUSH_OPTION_NULL);
#endif
    if (err != EUD_SUCCESS)
    {
        printf("%s: fswdflushbuffers errr code is %x", __func__, err);
    }
    return err;
}
#endif
#if 0

static const struct command_registration eud_command_handlers[] = {
	{
		.name  = "eud",
		.mode  = COMMAND_ANY,
		.help  = "EUD interface driver commands",
		.chain = eud_command_handlers,
		.usage = "",
	},
	COMMAND_REGISTRATION_DONE,
};
#endif

/* The eud driver is used to easily check the code path
 * where the target is unresponsive.
 */
static struct swd_driver eud_swd_driver = {
    .init = eud_swd_init,
    .switch_seq = eud_switch_seq,
    .read_reg = eud_swd_read,
    .write_reg = eud_swd_write,
    .run = eud_swd_run,
    .trace = NULL};

static const char *const eud_transports[] = {"swd", NULL};

struct adapter_driver eud_adapter_driver = {
    .name = "eud",
    .transports = eud_transports,
    .commands = NULL, // eud_command_handlers,

    .init = eud_init,
    .quit = eud_quit,
    .reset = eud_reset,
    .speed = eud_set_speed,
    .khz = eud_khz,
    .speed_div = NULL, // eud_speed_div,
    .power_dropout = NULL,
    .srst_asserted = NULL,
    .config_trace = NULL,
    .poll_trace = NULL,
    .swd_ops = &eud_swd_driver,
};
