/************************************************************************
 *	Copyright (c) 2023 Qualcomm Innovation Center, Inc.					*
 *	All rights reserved.												*
 *																		*
 *	SPDX-License-Identifier: GPL-2.0-or-later							*
 *																		*
 ************************************************************************/


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

#include "eud/inc/eud_api.h"

#define OPENOCD_ENV 1
#define SWD_BITBANG_CLK_SHFT 0
#define SWD_BITBANG_DI_SHFT 1
#define SWD_BITBANG_RCTLR_SRST_N_SHFT 2
#define SWD_BITBANG_GPIO_DI_OE 3
#define SWD_BITBANG_GPIO_SRST_N_SHFT 4
#define SWD_BITBANG_GPIO_TRST_N_SHFT 5
#define SWD_BITBANG_DAP_TRST_N_SHFT 6
#define EUD_SUCCESS 0

#define FLUSH_OPTION_NULL 0
#define FLUSH_OPTION_TRUE 1

#define EUD_SWD_FREQ_120_MHz 0x0
#define EUD_SWD_FREQ_80_MHz 0x1

#define EUD_RESET_ASSERTED 1
#define DAP_VERSION_ADIV5 5
#define DAP_VERSION_ADIV6 6

#define CTRLSTAT_CHECK_ENABLED 1
#define CTRLSTAT_READ_ENABLED 1

// Supported frequencies
#define EUD_DBG_FREQ_15000_KHZ 15000
#define EUD_DBG_FREQ_10000_KHZ 10000
#define EUD_DBG_FREQ_7500_KHZ 7500
#define EUD_DBG_FREQ_3750_KHZ 3750
#define EUD_DBG_FREQ_1875_KHZ 1875

enum {
	SELECT_EUD_DBG_FREQ_15000_KHZ = 0x2,
	SELECT_EUD_DBG_FREQ_10000_KHZ = 0x3,
	SELECT_EUD_DBG_FREQ_7500_KHZ = 0x4,
	SELECT_EUD_DBG_FREQ_3750_KHZ = 0x5,
	SELECT_EUD_DBG_FREQ_1875_KHZ = 0x6,
};

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

// Function pointers for exported functions in EUD.DLL
// Note: Here f is suffix for functions names exported in EUD.DLL

static SwdEudDevice *gpSWDDevice = NULL;
static uint32_t gDeviceId = 0;

static uint32_t cmd_count = 0;
uint32_t dummy_read;
uint32_t periodic_seq_timeout = 3500;
bool is_pwrupNeeded = false;
uint32_t dap_version = 5;


// qcom added function to get ADI Version in EUD Adapter file
// Need to find a proper way to get ADI Version before upstreaming this change
extern uint32_t get_adi_version(void);

static void trigger_pwr_on_sequence(void);
static void eud_ensure_dbg_sys_pwr_is_on(void);
static EUD_ERR_t handle_SwdAckFault(uint32_t APnDP, uint32_t A2_3, uint32_t *value, bool RnW);

static inline EUD_ERR_t eudWriteWrapper(uint32_t APnDP, uint32_t A2_3, uint32_t val)
{
	 return swd_write(gpSWDDevice, APnDP, A2_3, val);
}

static inline EUD_ERR_t eudReadWrapper(uint32_t APnDP, uint32_t A2_3, uint32_t *readVal)
{
	return swd_read(gpSWDDevice, APnDP, A2_3, readVal);
}

static inline void eudGetJtagIDwrapper(uint32_t *DPIDR)
{
	swd_get_jtag_id(gpSWDDevice, DPIDR);
}

static inline EUD_ERR_t eudBitBangWrapper(uint32_t swd_bitbang_value, uint32_t *return_val)
{
	return swd_bitbang(gpSWDDevice, swd_bitbang_value, return_val);
}

static inline EUD_ERR_t eudSetFrequencyWrapper(uint32_t freqVal)
{
	return swd_set_frequency(gpSWDDevice, freqVal);
}


#ifdef KILLPROCESS
static void kill_process(void);
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
	dap_version = get_adi_version();
	switch (seq)
	{
	case JTAG_TO_SWD:
		LOG_INFO("EUD: switch_seq JTAG_TO_SWD, DAP version = %u (%s)", dap_version,
			(dap_version == DAP_VERSION_ADIV6) ? "ADIv6" :
			(dap_version == DAP_VERSION_ADIV5) ? "ADIv5" : "unknown");
		if(dap_version == DAP_VERSION_ADIV5)
			err = jtag_to_swd_adiv5(gpSWDDevice);
		else if(dap_version == DAP_VERSION_ADIV6)
			err = jtag_to_swd_adiv6(gpSWDDevice);

		if (err != EUD_SUCCESS) {
			LOG_ERROR("EUD: JTAG_TO_SWD switch sequence failed, error code 0x%x", err);
			return ERROR_FAIL;
		}
		LOG_INFO("EUD: SWD connection established");
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

static int eud_swd_run(void)
{
	EUD_ERR_t err = EUD_SUCCESS;

#ifdef EUD_CMD_COUNT_LOGGING

	LOG_DEBUG("eud_swd_run: cmd_count: %d", cmd_count);
#endif

	swd_flush (gpSWDDevice);

	if (err == SWD_ERR_SWD_ACK_FAULT_DETECTED)
	{
		err = handle_SwdAckFault(0, 0, 0, true); // dummy params ok for QUTS
	}

	if (err != EUD_SUCCESS)
	{
		LOG_ERROR("swdflushbuffers FAILED!!");
	}

	return err;
}

static inline void write_abort_1f()
{
	eudWriteWrapper(0, 0, 0x1f); // abort write 0x1f
}

static inline void write_abort_4()
{
	eudWriteWrapper(0, 0, 0x4); // abort write 0x4
}

static void trigger_pwr_on_sequence(void)
{

	EUD_ERR_t err = EUD_SUCCESS;
	uint32_t APnDP = 0;
	uint32_t A2_3 = 0;
	uint32_t val = 0;

	APnDP = 0;
	A2_3 = 1;
	val = 0;

	val = (uint32_t)(0x50000000);
	err = eudWriteWrapper(APnDP, A2_3, val); // write 0x5000000 to ctrl stat

	if (err != EUD_SUCCESS)
	{
		LOG_ERROR("CTRLSTAT Write in triggger sequence FAILED!! %x", err);
	}

	return EUD_SUCCESS;
}

static void eud_ensure_dbg_sys_pwr_is_on(void)
{
	static int call_count = 0, call_count2 = 0;
	EUD_ERR_t err = EUD_SUCCESS;

	if (call_count > 500)
	{
		return;
	}
	else
	{
		call_count++;
	}
	//LOG_DEBUG(" eud_ensure_dbg_sys_pwr_is_on");
	write_abort_4();
	trigger_pwr_on_sequence();
	return;
}

#endif

static EUD_ERR_t handle_SwdAckFault(uint32_t APnDP, uint32_t A2_3, uint32_t *value, bool RnW)
{

	EUD_ERR_t err = EUD_SUCCESS;

	// retry scenario
	write_abort_1f();
	trigger_pwr_on_sequence();
	if (RnW) // Read case
	{
		LOG_DEBUG("Entered read ack fault");
		err = eudReadWrapper(APnDP, A2_3, &value);
	}
	else // write case
	{
		LOG_DEBUG("Entered write ack fault");
		err = eudWriteWrapper(APnDP, A2_3, *value);
	}

	return err;
}

static inline void triggerPeriodicSequence()
{
	if ((periodic_seq_timeout == 0) )
	{
		write_abort_4();
		trigger_pwr_on_sequence();
	}
	else 
	{
		if (cmd_count > periodic_seq_timeout)
		{
			write_abort_4();
			trigger_pwr_on_sequence();
			cmd_count = 0;
		}
	}
}

static void eud_swd_read(uint8_t cmd, uint32_t *value, uint32_t ap_delay_hint)
{
	cmd_count++;
	// LOG_DEBUG("swdread call \n");
	uint32_t APnDP = 0;
	uint32_t A2_3 = 0;
	EUD_ERR_t err = EUD_SUCCESS;

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
	{
		eud_ensure_dbg_sys_pwr_is_on();
		triggerPeriodicSequence();
	}

	/*Below power up request is required & triggered during monitor reset*/
	if (is_pwrupNeeded && !(((APnDP == 0) && ((A2_3 == 0) || (A2_3 == 1)))))
	{
		write_abort_4();
		trigger_pwr_on_sequence();
	}
#endif

	if (value == NULL)
	{
		err = eudReadWrapper(APnDP, A2_3, &dummy_read);

		if (err == SWD_ERR_SWD_ACK_FAULT_DETECTED)
		{
			err = handle_SwdAckFault(APnDP, A2_3, &dummy_read, true);
		}
	}
	else
	{
		err = eudReadWrapper(APnDP, A2_3, value);

		if (err == SWD_ERR_SWD_ACK_FAULT_DETECTED)
		{
			err = handle_SwdAckFault(APnDP, A2_3, value, true);
		}
	}

	if (err != EUD_SUCCESS)
	{
		LOG_ERROR("SWD Read FAILED!!, %X", err);
#ifdef KILLPROCESS
		if (err != SWD_ERR_SWD_ACK_WAIT_DETECTED)
		{
			LOG_ERROR("Going to kill!! , %X", err);
			kill_process();
		}
#endif
	}
	//LOG_DEBUG("swdread  end \n");
	return;
}

static void eud_swd_write(uint8_t cmd, uint32_t value, uint32_t ap_delay_hint)
{
	cmd_count++;
	// LOG_DEBUG("swd write call \n");
	uint32_t APnDP = 0;
	uint32_t A2_3 = 0;
	EUD_ERR_t err;
	// static int j;

	(void)ap_delay_hint;
	APnDP = (cmd >> 1) & 0x1;
	A2_3 = (cmd >> 3) & 0x3;

	if (ap_delay_hint > 0)
	{
		uint32_t i;
		for (i = 0; i < 20000; i++)
		{
		}
	}

#if CTRLSTAT_CHECK_ENABLED

	// Dont touch ctrlstat register, if DAPIDR or ctrlstat is being read
	if (!(((APnDP == 0) && ((A2_3 == 0) || (A2_3 == 1)))))
	{
		eud_ensure_dbg_sys_pwr_is_on();
		triggerPeriodicSequence();
	}

		/*Below power up request is required & triggered during monitor reset*/
	if (is_pwrupNeeded && !(((APnDP == 0) && ((A2_3 == 0) || (A2_3 == 1)))))
	{
		write_abort_4();
		trigger_pwr_on_sequence();
	}
#endif

	// cmd_count += 5;

	// LOG_DEBUG("swd write wrapper call \n");

	err = eudWriteWrapper(APnDP, A2_3, value);

	if (err == SWD_ERR_SWD_ACK_FAULT_DETECTED)
	{
		LOG_DEBUG("swdread wrapper SWD_ERR_SWD_ACK_FAULT_DETECTED \n");
		err = handle_SwdAckFault(APnDP, A2_3, &value, false);
	}

	// LOG_DEBUG("swd write wrapper end \n");

	if (err != EUD_SUCCESS)
		LOG_ERROR("SWD Write FAILED!!");

	// LOG_DEBUG("swd write end \n");
	return;
}

int eud_AssertReset(void)
{
	is_pwrupNeeded = true;
	EUD_ERR_t err;
	uint32_t return_val = 0; // DPIDR = 0;
	uint32_t DPIDR = 0;      // DPIDR = 0;

	eudGetJtagIDwrapper(&DPIDR);

	// Assert reset and tap reset
	uint32_t swd_bitbang_value =
		SWD_BITBANG_CLK_BMSK_DEASSERT +
		SWD_BITBANG_DI_BMSK_DEASSERT +
		SWD_BITBANG_RCTLR_SRST_BMSK_ASSERT + // this is the reset value
		SWD_BITBANG_GPIO_DI_OE_DEASSERT +
		SWD_BITBANG_GPIO_SRST_BMSK_DEASSERT +
		SWD_BITBANG_GPIO_TRST_BMSK_DEASSERT +
		SWD_BITBANG_DAP_TRST_BMSK_ASSERT; // Also reset TAP

	LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper call val: %" PRIu32 " \n", swd_bitbang_value);
	err = eudBitBangWrapper(swd_bitbang_value, &return_val);
	LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper end \n");

	// De-assert tap reset but keep SRST asserted.
	swd_bitbang_value =
		SWD_BITBANG_CLK_BMSK_DEASSERT +
		SWD_BITBANG_DI_BMSK_DEASSERT +
		SWD_BITBANG_RCTLR_SRST_BMSK_ASSERT + // this is the reset value
		SWD_BITBANG_GPIO_DI_OE_DEASSERT +
		SWD_BITBANG_GPIO_SRST_BMSK_DEASSERT +
		SWD_BITBANG_GPIO_TRST_BMSK_DEASSERT +
		SWD_BITBANG_DAP_TRST_BMSK_DEASSERT; // Deassert TAP reset

	LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper call val: %" PRIu32 " \n", swd_bitbang_value);
	err = eudBitBangWrapper(swd_bitbang_value, &return_val);
	LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper end \n");

	if (err != ERROR_OK)
	{
		printf("%s error: line %d\n", __FUNCTION__, __LINE__);
		return err;
	}

	eudGetJtagIDwrapper(&DPIDR);

	if (err = swd_flush(gpSWDDevice))
		return err;

	printf(" From inside assert api, before jtag to swd DPIDR: %x\n", DPIDR);

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

	LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper call val: %" PRIu32 " \n", swd_bitbang_value);
	err = eudBitBangWrapper(swd_bitbang_value, &return_val);
	LOG_DEBUG("OCD: Bitbang eud_AssertReset wrapper end \n");

	is_pwrupNeeded = false;
	for (int i = 0; i < 10; i++)
	{
		trigger_pwr_on_sequence();
	}
	if (err != ERROR_OK)
	{
		printf("%s error: line %d\n", __FUNCTION__, __LINE__);
		return err;
	}

	return err;
}

/**
 * Asserts reset for ADIv6 devices.
 *
 * This function asserts the reset signal for ADIv6 devices, which is used to
 * reset the target device.
 * 
 * @return ERROR_OK on success, or an error code on failure.
 */
int eud_assert_reset_adiv6(void)
{
	is_pwrupNeeded = true;
	EUD_ERR_t err = ERROR_OK;
	uint32_t srst_status = 0;
	uint32_t DPIDR = 0;      // DPIDR = 0;

	LOG_INFO("EUD: ADIv6 SRST assert start (CTL peripheral eud_rctlr_srst_n)");

	eudGetJtagIDwrapper(&DPIDR);

	if (err = swd_flush(gpSWDDevice))
		return err;
	//eud_ctl_check_srst_status(gDeviceId, &srst_status);    //uncomment to read status of the SRST signal for the specified device

	err = eud_ctl_assert_srst(gDeviceId, 1);
	//eud_ctl_check_srst_status(gDeviceId, &srst_status);    //uncomment to read status of the SRST signal for the specified device

	if (err != ERROR_OK)
	{
		LOG_ERROR("EUD: %s failed at line %d, error code 0x%x", __FUNCTION__, __LINE__, err);
		return err;
	}

	eudGetJtagIDwrapper(&DPIDR);

	if (err = swd_flush(gpSWDDevice))
		return err;

	LOG_INFO("EUD: ADIv6 SRST assert done, DPIDR readback = 0x%x", DPIDR);

	return err;
}

/**
 * De-asserts reset for ADIv6 devices.
 *
 * This function de-asserts the reset signal for ADIv6 devices, allowing the
 * target device to resume normal operation.
 *
 * @return ERROR_OK on success, or an error code on failure.
 */
int eud_deassert_reset_adiv6(void)
{
	EUD_ERR_t err = ERROR_OK;

	LOG_INFO("EUD: ADIv6 SRST deassert start (CTL peripheral eud_rctlr_srst_n)");

	if (err = swd_flush(gpSWDDevice))
		return err;
	err = eud_ctl_assert_srst(gDeviceId, 0);

	if (err != ERROR_OK)
	{
		LOG_ERROR("EUD: %s failed at line %d, error code 0x%x", __FUNCTION__, __LINE__, err);
		return err;
	}

	LOG_INFO("EUD: ADIv6 SRST deassert done");

	return err;
}

int eud_reset(int trst, int srst)
{
	LOG_DEBUG("eud_reset call \n");
	int retval = EUD_SUCCESS;
	uint32_t adi_version = get_adi_version();

	LOG_DEBUG("eud_reset call: trst=%d srst=%d, DAP version=%u", trst, srst, adi_version);

	if (srst == EUD_RESET_ASSERTED)
	{
		if(adi_version == DAP_VERSION_ADIV5) {
			retval = eud_AssertReset();
		}
		else if(adi_version == DAP_VERSION_ADIV6) {
			retval = eud_assert_reset_adiv6();
		}

		if (retval)
		{
			LOG_ERROR("EUD: reset assert failed, error code 0x%x", retval);
			return retval;
		}

		LOG_INFO("EUD: reset assert completed successfully");
	}
	else
	{

		if(adi_version == DAP_VERSION_ADIV5) {
			retval = eud_DeAssertReset();
		}
		else if(adi_version == DAP_VERSION_ADIV6) {
			retval = eud_deassert_reset_adiv6();
		}

		if (retval)
		{
			LOG_ERROR("EUD: reset deassert failed, error code 0x%x", retval);
			return retval;
		}

		LOG_INFO("EUD: reset deassert completed successfully");
	}

	return retval;
}


static int eud_khz(int khz, int *speed)
{
	if (khz >= 0 && khz <= EUD_DBG_FREQ_1875_KHZ)
		*speed = SELECT_EUD_DBG_FREQ_1875_KHZ;
	else if (khz > EUD_DBG_FREQ_1875_KHZ && khz <= EUD_DBG_FREQ_3750_KHZ)
		*speed = SELECT_EUD_DBG_FREQ_3750_KHZ;
	else if (khz > EUD_DBG_FREQ_3750_KHZ && khz <= EUD_DBG_FREQ_7500_KHZ)
		*speed = SELECT_EUD_DBG_FREQ_7500_KHZ;
	else if (khz > EUD_DBG_FREQ_7500_KHZ && khz <= EUD_DBG_FREQ_10000_KHZ)
		*speed = SELECT_EUD_DBG_FREQ_10000_KHZ;
	else if (khz > EUD_DBG_FREQ_10000_KHZ && khz <= EUD_DBG_FREQ_15000_KHZ)
		*speed = SELECT_EUD_DBG_FREQ_15000_KHZ;
	else {
		LOG_WARNING(
                "Unsupported adapter speed divider %d, defaulting to %d kHz",
                speed, EUD_DBG_FREQ_1875_KHZ
			);
		*speed = SELECT_EUD_DBG_FREQ_15000_KHZ;
	}

	return ERROR_OK;
}


static int eud_speed_div(int speed, int * const khz)
{
    int status = ERROR_OK;

    /* Defensive check: pointer shall be valid */
    if (khz == NULL)
    {
        status = ERROR_FAIL;
    }
    else
    {
        switch (speed)
        {
            case SELECT_EUD_DBG_FREQ_15000_KHZ:
                *khz = EUD_DBG_FREQ_15000_KHZ;
                break;

            case SELECT_EUD_DBG_FREQ_10000_KHZ:
                *khz = EUD_DBG_FREQ_10000_KHZ;
                break;

            case SELECT_EUD_DBG_FREQ_7500_KHZ:
                *khz = EUD_DBG_FREQ_7500_KHZ;
                break;

            case SELECT_EUD_DBG_FREQ_3750_KHZ:
                *khz = EUD_DBG_FREQ_3750_KHZ;
                break;

            case SELECT_EUD_DBG_FREQ_1875_KHZ:
                *khz = EUD_DBG_FREQ_1875_KHZ;
                break;

            default:
                /* Fallback to a safe default */
                LOG_WARNING(
					"Unsupported adapter speed divider %d, defaulting to %d kHz",
                    *khz, EUD_DBG_FREQ_1875_KHZ);
					
				*khz = EUD_DBG_FREQ_1875_KHZ;
				break;
        }
    }

    return status;
}

static int eud_set_speed(int speed)
{
	EUD_ERR_t err = EUD_SUCCESS;

	err = eudSetFrequencyWrapper(speed);

	if (err != EUD_SUCCESS)
		return ERROR_FAIL;

	return ERROR_OK;
}

static int eud_init(void)
{
	// Read EUD version in use
	uint32_t major_rev = 0;
	uint32_t minor_rev = 0;
	uint32_t spin_rev = 0;
	eud_get_version(&major_rev, &minor_rev, &spin_rev);
	LOG_INFO("Using EUD %u.%u.%u", major_rev, minor_rev, spin_rev);

	return ERROR_OK;
}

static int eud_quit(void)
{
	eud_close_peripheral(gpSWDDevice);
	return ERROR_OK;
}


static int eud_swd_init(void)
{
    EUD_ERR_t err = EUD_SUCCESS;

    uint32_t arr[100] = {0};
    uint32_t len = 0;

    /* EUD may still be re-enumerating on USB right after a PMIC hard reset
     * races with the OpenOCD restart, so retry for a few seconds before
     * giving up. */
    const int64_t timeout_ms = 5000;
    const int64_t retry_interval_ms = 200;
    int64_t deadline = timeval_ms() + timeout_ms;
    int attempt = 0;

    do {
        attempt++;
        len = 0;

        err = get_device_id_array(arr, &len);
        if (err == EUD_SUCCESS && len > 0) {
            LOG_INFO("EUD: found %u device(s), using device id 0x%x", len, arr[0]);

            gDeviceId = arr[0];
            gpSWDDevice = eud_initialize_device_swd(gDeviceId, OPENOCD_ENV, &err);

            if (err == EUD_SUCCESS && gpSWDDevice) {
                LOG_INFO("EUD: SWD peripheral initialized successfully on device id 0x%x (attempt %d)",
                    gDeviceId, attempt);
                return ERROR_OK;
            }

            LOG_ERROR("EUD: eud_initialize_device_swd failed, error code 0x%x", err);

            /* Got a device id but init failed - close any partial handle before retrying */
            if (gpSWDDevice) {
                eud_close_peripheral(gpSWDDevice);
                gpSWDDevice = NULL;
            }
        } else {
            LOG_DEBUG("EUD: get_device_id_array failed, error code 0x%x (no EUD device enumerated?)", err);
        }

        alive_sleep(retry_interval_ms);
    } while (timeval_ms() < deadline);

    LOG_ERROR("EUD: get_device_id_array failed, error code 0x%x (no EUD device enumerated after %d attempts over %" PRId64 "ms)",
        err, attempt, timeout_ms);

    return ERROR_FAIL;
}


#define FLUSH_OPTION_NULL 0
#define FLUSH_OPTION_TRUE 1

COMMAND_HANDLER(eud_trigger_seq)
{
	COMMAND_PARSE_ADDRESS(CMD_ARGV[0], periodic_seq_timeout);
	LOG_INFO("periodic_seq_timeout = 0x%d ", periodic_seq_timeout);
	return ERROR_OK;
}

COMMAND_HANDLER(eud_usb_spoof_attach)
{
    if(gDeviceId == 0)
    {
        LOG_ERROR("EUD Device not enumerated");
        return ERROR_FAIL;
    }
    EUD_ERR_t err = eud_spoof_attach(gDeviceId);
    if(err != EUD_SUCCESS)
    {
        LOG_ERROR("EUD Spoof attach failed");
        return ERROR_FAIL;
    }
    else
    {
        LOG_INFO("EUD USB Spoof attach success");
        return ERROR_OK;
    }
}
COMMAND_HANDLER(eud_usb_spoof_detach)
{
    if(gDeviceId == 0)
    {
        LOG_ERROR("EUD Device not enumerated");
        return ERROR_FAIL;
    }
    EUD_ERR_t err = eud_spoof_detach(gDeviceId);
    if(err != EUD_SUCCESS)
    {
        LOG_ERROR("EUD Spoof Detach failed");
        return ERROR_FAIL;
    }
    else
    {
        LOG_INFO("EUD USB Spoof Detach success");
        return ERROR_OK;
    }
}
static const struct command_registration eud_exec_command_handlers[] = 
{
	{
		.name = "trigger_seq",
		.handler = eud_trigger_seq,
		.mode = COMMAND_EXEC,
		.help = "set periodic trigger frequency",
		.usage = "",
	},
    {
		.name       = "eud_usb_spoof_detach",
		.mode       = COMMAND_EXEC,
		.help       = "EUD spoof detach to enter in CXPC",
        .handler    = eud_usb_spoof_detach,
		.usage      = "",
	},
{
    	.name       = "eud_spoof_attach",
    	.mode       = COMMAND_EXEC,
    	.help       = "EUD spoof attach to enter in CXPC",
    	.handler    = eud_usb_spoof_attach,
   	 	.usage      = "",
},
	COMMAND_REGISTRATION_DONE
};

static const struct command_registration eud_command_handlers[] = {
	{
		.name  = "eud",
		.mode  = COMMAND_ANY,
		.help  = "EUD interface driver commands",
		.chain = eud_exec_command_handlers,
		.usage = "",
	},
	COMMAND_REGISTRATION_DONE,
};


/* The eud driver is used to easily check the code path
 * where the target is unresponsive.
 */
static struct swd_driver eud_swd_driver = 
{
	.init = eud_swd_init,
	.switch_seq = eud_switch_seq,
	.read_reg = eud_swd_read,
	.write_reg = eud_swd_write,
	.run = eud_swd_run,
	.trace = NULL
};

static const char *const eud_transports[] = {"swd", NULL};

struct adapter_driver eud_adapter_driver = {
	.name = "eud",
	.transports = eud_transports,
	.commands = eud_command_handlers,

	.init = eud_init,
	.quit = eud_quit,
	.reset = eud_reset,
	.speed = eud_set_speed,
	.khz = eud_khz,
	.speed_div = eud_speed_div,
	.power_dropout = NULL,
	.srst_asserted = NULL,
	.config_trace = NULL,
	.poll_trace = NULL,
	.swd_ops = &eud_swd_driver,
};
