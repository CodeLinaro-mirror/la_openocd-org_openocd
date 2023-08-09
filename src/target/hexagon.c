/**************************************************************************
*	Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*																		  *
***************************************************************************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
 
#include "breakpoints.h"
#include "aarch64.h"
#include "register.h"
#include "target_request.h"
#include "target_type.h"
#include "armv8_opcodes.h"
#include "armv8_cache.h"
#include "arm_semihosting.h"
#include "jtag/interface.h"
#include "smp.h"
#include <helper/time_support.h>
#include "arm_adi_v5.h"
#include "jtag/swd.h"
#include "hexagon.h"
#define RSPVERSION 0x1

typedef struct hexagon_config
{
	uint32_t maxHwThreads;
	uint32_t etmClkenAddr;
	uint32_t etmResetAddr;
	uint32_t qpss6WDOGCtl;
	uint32_t numTlbEntries;
}hexagon_config;

hexagon_config gHexConfig =
{
	.maxHwThreads  = 6,
	.etmClkenAddr  = 0x86808000,
	.etmResetAddr  = 0x86808008,
	.qpss6WDOGCtl  = 0x4104004,
	.numTlbEntries = 192,
};


static uint8_t sbp_step_executed = 0; //Just a bool variable

//Global data to store/keep track of the initial PC value once threads are halted through software breakpoint, value are cleared once resume happens.
static uint32_t **gpSbpHaltedThreadsPC;
uint32_t (*gpPerHwThrdReg) [HEXAGON_PER_THREAD_REGS]={0};
char  (*gpHexagonThreadNameArray)[20];

extern bool is_hexagon_untrusted = false;
static const hexagon_reg hexagon_per_hwt_regs[] = {
	/** General Purpose Registers **/
	{HEXAGON_R0, "R0", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R1, "R1", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R2, "R2", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R3, "R3", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R4, "R4", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R5, "R5", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R6, "R6", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R7, "R7", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R8, "R8", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R9, "R9", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R10, "R10", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R11, "R11", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R12, "R12", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R13, "R13", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R14, "R14", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R15, "R15", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R16, "R16", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R17, "R17", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R18, "R18", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
		{HEXAGON_R19, "R19", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R20, "R20", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R21, "R21", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R22, "R22", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R23, "R23", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R24, "R24", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R25, "R25", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R26, "R26", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R27, "R27", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_R28, "R28", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_SP, "R29", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_FP, "R30", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_LR, "R31", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
	/** Control Registers **/
	{HEXAGON_SA0, "SA0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_LC0, "LC0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_SA1, "SA1", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_LC1, "LC1", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_P30, "P3:0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	/** C5: reserved **/
	{HEXAGON_C5_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_M0, "M0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_M1, "M1", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_USR, "USR", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_PC, "PC", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_UGP, "UGP", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_GP, "GP", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_CS0, "CS0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_CS1, "CS1", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_UPCYCLLO, "UPCYCLELO", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_UPCYCLHI, "UPCYCLEHI", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_FLMT, "FLMT", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_FKEY, "FKEY", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_PKTCNTLO, "PKTCNTLO", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_PKTCNTHI, "PKTCNTHI", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	/** C20-29: reserved **/
	{HEXAGON_C20_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C21_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C22_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C23_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C24_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C25_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C26_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C27_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C28_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_C29_RESRV, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_UTMRLO, "UTMRLO", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_UTMRHI, "UTMRHI", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
	/** Monitor Mode per-thread Control Registers **/
	{HEXAGON_SGP0, "SGP0", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_SGP1, "SGP1", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_STID, "STID", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_ELR, "ELR", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_BADVA0, "BADVA0", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_BADVA1, "BADVA1", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_SSR, "SSR", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_CCR, "CCR", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_HTID, "HTID", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_BADVA, "BADVA", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_IMASK, "IMASK", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_GEVB, "GEVB", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	/** S12 - S15: reserved **/
	{HEXAGON_S12_RESRV, "S12_RESRV", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_S13_RESRV, "S13_RESRV", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_S14_RESRV, "S14_RESRV", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_S15_RESRV, "S15_RESRV", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},

};

uint32_t global_reg[HEXAGON_MMODE_GLOBAL_MAX - HEXAGON_MMODE_PERTHRD_MAX] = {0};

static const hexagon_reg hexagon_global_regs[] = {
	/** Monitor Mode Global Control Registers **/
	{HEXAGON_EVB, "EVB", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_MODECTL, "MODECTL", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_SYSCFG, "SYSCFG", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	/** 19: reserved **/
	{HEXAGON_S19_RESRV, "S19_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_IPENDAD, "IPENDAD", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_VID, "VID", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_VID1, "VID1", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_BESTWAIT, "BESTWAIT", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	/** 24: reserved **/
	{HEXAGON_S24_RESRV, "S24_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_SCHDCFG, "SCHDCFG", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	/** 26: reserved **/
	{HEXAGON_S26_RESRV, "S26_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_CFGBASE, "CFGBASE", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_DIAG, "DIAG", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_REV, "REV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_PCYCLELO, "PCYCLELO", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
	{HEXAGON_PCYCLEHI, "PCYCLEHI", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
};

/********************************************/
/** Stuff instruction for register reading **/
/********************************************/

/* R0-R31  registers */
uint32_t stuff_inst_gpr_read[] = {
	0x6700c029, /* isdbmbxout = r0  */
	0x6701c029, /* isdbmbxout = r1  */
	0x6702c029, /* isdbmbxout = r2  */
	0x6703c029, /* isdbmbxout = r3  */
	0x6704c029, /* isdbmbxout = r4  */
	0x6705c029, /* isdbmbxout = r5  */
	0x6706c029, /* isdbmbxout = r6  */
	0x6707c029, /* isdbmbxout = r7  */
	0x6708c029, /* isdbmbxout = r8  */
	0x6709c029, /* isdbmbxout = r9  */
	0x670ac029, /* isdbmbxout = r10 */
	0x670bc029, /* isdbmbxout = r11 */
	0x670cc029, /* isdbmbxout = r12 */
	0x670dc029, /* isdbmbxout = r13 */
	0x670ec029, /* isdbmbxout = r14 */
	0x670fc029, /* isdbmbxout = r15 */
	0x6710c029, /* isdbmbxout = r16 */
	0x6711c029, /* isdbmbxout = r17 */
	0x6712c029, /* isdbmbxout = r18 */
	0x6713c029, /* isdbmbxout = r19 */
	0x6714c029, /* isdbmbxout = r20 */
	0x6715c029, /* isdbmbxout = r21 */
	0x6716c029, /* isdbmbxout = r22 */
	0x6717c029, /* isdbmbxout = r23 */
	0x6718c029, /* isdbmbxout = r24 */
	0x6719c029, /* isdbmbxout = r25 */
	0x671ac029, /* isdbmbxout = r26 */
	0x671bc029, /* isdbmbxout = r27 */
	0x671cc029, /* isdbmbxout = r28 */
	0x671dc029, /* isdbmbxout = r29 */
	0x671ec029, /* isdbmbxout = r30 */
	0x671fc029	/* isdbmbxout = r31 */
};

/* Control registers */
uint32_t stuff_inst_ctrl_reg_read[][2] = {
	{0x6a00c007, 0x6707c029}, /* r7 = sa0, isdbmbxout = r7 */
	{0x6a01c007, 0x6707c029}, /* r7 = lc0, isdbmbxout = r7 */
	{0x6a02c007, 0x6707c029}, /* r7 = sa1, isdbmbxout = r7 */
	{0x6a03c007, 0x6707c029}, /* r7 = lc1, isdbmbxout = r7 */
	{0x6a04c007, 0x6707c029}, /* r7 = p3:0 isdbmbxout = r7 */
	{0x0, 0x0},				  /* Invalid: C5 reserved 	 */
	{0x6a06c007, 0x6707c029}, /* r7 = m0,  isdbmbxout = r7 */
	{0x6a07c007, 0x6707c029}, /* r7 = m1,  isdbmbxout = r7 */
	{0x6a08c007, 0x6707c029}, /* r7 = usr, isdbmbxout = r7 */
	{0x6a09c007, 0x6707c029}, /* r7 = pc,  isdbmbxout = r7 */
	{0x6a0ac007, 0x6707c029}, /* r7 = ugp, isdbmbxout = r7 */
	{0x6a0bc007, 0x6707c029}, /* r7 = gp,  isdbmbxout = r7 */
	{0x6a0cc007, 0x6707c029}, /* r7 = cs0, isdbmbxout = r7 */
	{0x6a0dc007, 0x6707c029}, /* r7 = cs1, isdbmbxout = r7 */
	{0x6a0ec007, 0x6707c029}, /* r7 = upcyclelo, isdbmbxout = r7 */
	{0x6a0fc007, 0x6707c029}, /* r7 = upcyclehi, isdbmbxout = r7 */
	{0x6a10c007, 0x6707c029}, /* r7 = framelimit,isdbmbxout = r7 */
	{0x6a11c007, 0x6707c029}, /* r7 = framekey,  isdbmbxout = r7 */
	{0x6a12c007, 0x6707c029}, /* r7 = pktcountlo,isdbmbxout = r7 */
	{0x6a13c007, 0x6707c029}, /* r7 = pktcounthi,isdbmbxout = r7 */
	{0x0, 0x0},				  /* Invalid: C20 reserved 	 */
	{0x0, 0x0},				  /* Invalid: C21 reserved 	 */
	{0x0, 0x0},				  /* Invalid: C22 reserved 	 */
	{0x0, 0x0},				  /* Invalid: C23 reserved 	 */
	{0x0, 0x0},				  /* Invalid: C24 reserved	 */
	{0x0, 0x0},				  /* Invalid: C25 reserved	 */
	{0x0, 0x0},				  /* Invalid: C26 reserved	 */
	{0x0, 0x0},				  /* Invalid: C27 reserved	 */
	{0x0, 0x0},				  /* Invalid: C28 reserved	 */
	{0x0, 0x0},				  /* Invalid: C29 reserved	 */
	{0x6a1ec007, 0x6707c029}, /* r7 = utimerlo,  isdbmbxout = r7 */
	{0x6a1fc007, 0x6707c029}  /* r7 = utimerhi,  isdbmbxout = r7 */
};

/* Per thread control registers */
uint32_t stuff_inst_mmode_reg_read[][2] = {
	{0x6e80c007, 0x6707c029}, /* r7 = sgp0, isdbmbxout = r7  */
	{0x6e81c007, 0x6707c029}, /* r7 = sgp1, isdbmbxout = r7  */
	{0x6e82c007, 0x6707c029}, /* r7 = stid, isdbmbxout = r7  */
	{0x6e83c007, 0x6707c029}, /* r7 = elr,  isdbmbxout = r7  */
	{0x6e84c007, 0x6707c029}, /* r7 = badva0,isdbmbxout = r7 */
	{0x6e85c007, 0x6707c029}, /* r7 = badva1,isdbmbxout = r7 */
	{0x6e86c007, 0x6707c029}, /* r7 = ssr,  isdbmbxout = r7  */
	{0x6e87c007, 0x6707c029}, /* r7 = ccr,  isdbmbxout = r7  */
	{0x6e88c007, 0x6707c029}, /* r7 = htid, isdbmbxout = r7  */
	{0x6e89c007, 0x6707c029}, /* r7 = badva,isdbmbxout = r7  */
	{0x6e8ac007, 0x6707c029}, /* r7 = imask,isdbmbxout = r7  */
	{0x6e8bc007, 0x6707c029}, /* r7 = gevb, isdbmbxout = r7  */
	{0x0, 0x0},				  /* Invalid: S12 reserved */
	{0x0, 0x0},				  /* Invalid: S13 reserved */
	{0x0, 0x0},				  /* Invalid: S14 reserved */
	{0x0, 0x0},				  /* Invalid: S15 reserved */
};

uint32_t stuff_inst_mmode_imask_reg_read[][3] = {
	{0x7800c027, 0x6607c007, 0x6707c029}, /* r7 = #1, r7 = getimask(r7), isdbmbxout = r7 */
	{0x7800c047, 0x6607c007, 0x6707c029}, /* r7 = #2, r7 = getimask(r7), isdbmbxout = r7 */
	{0x7800c087, 0x6607c007, 0x6707c029}, /* r7 = #4, r7 = getimask(r7), isdbmbxout = r7 */
	{0x7800c107, 0x6607c007, 0x6707c029}, /* r7 = #8, r7 = getimask(r7), isdbmbxout = r7 */
	{0x7800c207, 0x6607c007, 0x6707c029}, /* r7 = #16,r7 = getimask(r7), isdbmbxout = r7 */
	{0x7800c407, 0x6607c007, 0x6707c029}  /* r7 = #32,r7 = getimask(r7), isdbmbxout = r7 */
};

/* Global control registers */
uint32_t stuff_inst_global_reg_read[][2] = {
	{0x6e90c007, 0x6707c029}, /* r7 = evb, isdbmbxout = r7 */
	{0x6e91c007, 0x6707c029}, /* r7 = modectl, isdbmbxout = r7 */
	{0x6e92c007, 0x6707c029}, /* r7 = syscfg, isdbmbxout = r7 */
	{0x0, 0x0},				  /* Invalid: S19 reserved	  */
	{0x6e94c007, 0x6707c029}, /* r7 = ipendad, isdbmbxout = r7 */
	{0x6e95c007, 0x6707c029}, /* r7 = vid, isdbmbxout = r7 */
	{0x6e96c007, 0x6707c029}, /* r7 = vid1, isdbmbxout = r7 */
	{0x6e97c007, 0x6707c029}, /* r7 = bestwait, isdbmbxout = r7 */
	{0x0, 0x0},				  /* Invalid: S24 reserved	  */
	{0x6e99c007, 0x6707c029}, /* r7 = schedcfg, isdbmbxout = r7 */
	{0x0, 0x0},				  /* Invalid: S26 reserved	  */
	{0x6e9bc007, 0x6707c029}, /* r7 = cfgbase, isdbmbxout = r7 */
	{0x6e9cc007, 0x6707c029}, /* r7 = diag, isdbmbxout = r7 */
	{0x6e9dc007, 0x6707c029}, /* r7 = rev, isdbmbxout = r7 */
	{0x6e9ec007, 0x6707c029}, /* r7 = pcyclelo, isdbmbxout = r7 */
	{0x6e9fc007, 0x6707c029}  /* r7 = pcyclehi, isdbmbxout = r7 */
};

uint32_t stuff_inst_sfr[][2] =
	{{0x7800c027, 0x6607c007},
	 {0x7800c047, 0x6607c007},
	 {0x7800c087, 0x6607c007},
	 {0x7800c107, 0x6607c007},
	 {0x7800c207, 0x6607c007},
	 {0x7800c407, 0x6607c007},
	 {0x6a0ac007, 0x6707c029},
	 {0x6a0bc007, 0x6707c029},
	 {0x6e86c007, 0x6707c029},
	 {0x6e84c007, 0x6707c029},
	 {0x6e85c007, 0x6707c029},
	 {0x6e92c007, 0x6707c029},
	 {0x6e91c007, 0x6707c029},
	 {0x6e9ec007, 0x6707c029},
	 {0x6e9fc007, 0x6707c029},
	 {0x6e90c007, 0x6707c029},
	 {0x6e9cc007, 0x6707c029},
	 {0x6e94c007, 0x6707c029},
	 {0x6e9dc007, 0x6707c029},
	 {0x6e9bc007, 0x6707c029}};

/********************************************/
/** Stuff instruction for register writing **/
/********************************************/

/* R0-R31  registers */
uint32_t stuff_inst_gpr_write[] = {
	0x6ea8c000, /* r0  = isdbmbxin */
	0x6ea8c001, /* r1  = isdbmbxin */
	0x6ea8c002, /* r2  = isdbmbxin */
	0x6ea8c003, /* r3  = isdbmbxin */
	0x6ea8c004, /* r4  = isdbmbxin */
	0x6ea8c005, /* r5  = isdbmbxin */
	0x6ea8c006, /* r6  = isdbmbxin */
	0x6ea8c007, /* r7  = isdbmbxin */
	0x6ea8c008, /* r8  = isdbmbxin */
	0x6ea8c009, /* r9  = isdbmbxin */
	0x6ea8c00A, /* r10 = isdbmbxin */
	0x6ea8c00B, /* r11 = isdbmbxin */
	0x6ea8c00C, /* r12 = isdbmbxin */
	0x6ea8c00D, /* r13 = isdbmbxin */
	0x6ea8c00E, /* r14 = isdbmbxin */
	0x6ea8c00F, /* r15 = isdbmbxin */
	0x6ea8c010, /* r16 = isdbmbxin */
	0x6ea8c011, /* r17 = isdbmbxin */
	0x6ea8c012, /* r18 = isdbmbxin */
	0x6ea8c013, /* r19 = isdbmbxin */
	0x6ea8c014, /* r20 = isdbmbxin */
	0x6ea8c015, /* r21 = isdbmbxin */
	0x6ea8c016, /* r22 = isdbmbxin */
	0x6ea8c017, /* r23 = isdbmbxin */
	0x6ea8c018, /* r24 = isdbmbxin */
	0x6ea8c019, /* r25 = isdbmbxin */
	0x6ea8c01A, /* r26 = isdbmbxin */
	0x6ea8c01B, /* r27 = isdbmbxin */
	0x6ea8c01C, /* r28 = isdbmbxin */
	0x6ea8c01D, /* r29 = isdbmbxin */
	0x6ea8c01E, /* r30 = isdbmbxin */
	0x6ea8c01F, /* r31 = isdbmbxin */
};

/* Control registers */
uint32_t stuff_inst_ctrl_reg_write[][2] = {
	{0x6ea8c007, 0x6227c000}, /* r7 = isdbmbxin, sa0 = r7 */
	{0x6ea8c007, 0x6227c001}, /* r7 = isdbmbxin, lc0 = r7 */
	{0x6ea8c007, 0x6227c002}, /* r7 = isdbmbxin, sa1 = r7 */
	{0x6ea8c007, 0x6227c003}, /* r7 = isdbmbxin, lc1 = r7 */
	{0x6ea8c007, 0x6227c004}, /* r7 = isdbmbxin, p3:0 = r7*/
	{0x0, 0x0},				  /* Invalid: C5 reserved */
	{0x6ea8c007, 0x6227c006}, /* r7 = isdbmbxin, m0 = r7  */
	{0x6ea8c007, 0x6227c007}, /* r7 = isdbmbxin, m1 = r7  */
	{0x6ea8c007, 0x6227c008}, /* r7 = isdbmbxin, usr = r7 */
	{0x6ea8c007, 0x5287c000}, /* r7 = isdbmbxin, jump r7 (PC=r7)  */
	{0x6ea8c007, 0x6227c00a}, /* r7 = isdbmbxin, ugp = r7 */
	{0x6ea8c007, 0x6227c00b}, /* r7 = isdbmbxin, gp = r7  */
	{0x6ea8c007, 0x6227c00c}, /* r7 = isdbmbxin, cs0 = r7 */
	{0x6ea8c007, 0x6227c00d}, /* r7 = isdbmbxin, cs1 = r7 */
	{0x6ea8c007, 0x6227c00e}, /* r7 = isdbmbxin, upcyclelo = r7 */
	{0x6ea8c007, 0x6227c00f}, /* r7 = isdbmbxin, upcyclehi = r7 */
	{0x6ea8c007, 0x6227c010}, /* r7 = isdbmbxin, framelimit= r7 */
	{0x6ea8c007, 0x6227c011}, /* r7 = isdbmbxin, framekey = r7 */
	{0x6ea8c007, 0x6227c012}, /* r7 = isdbmbxin, pktcountlo = r7 */
	{0x6ea8c007, 0x6227c013}, /* r7 = isdbmbxin, pktcounthi = r7 */
	{0x0, 0x0},				  /* Invalid: C20 reserved 	 */
	{0x0, 0x0},				  /* Invalid: C21 reserved 	 */
	{0x0, 0x0},				  /* Invalid: C22 reserved 	 */
	{0x0, 0x0},				  /* Invalid: C23 reserved 	 */
	{0x0, 0x0},				  /* Invalid: C24 reserved	 */
	{0x0, 0x0},				  /* Invalid: C25 reserved	 */
	{0x0, 0x0},				  /* Invalid: C26 reserved	 */
	{0x0, 0x0},				  /* Invalid: C27 reserved	 */
	{0x0, 0x0},				  /* Invalid: C28 reserved	 */
	{0x0, 0x0},				  /* Invalid: C29 reserved	 */
	{0x6ea8c007, 0x6227c01e}, /* r7 = isdbmbxin, utimerlo = r7  */
	{0x6ea8c007, 0x6227c01f}, /* r7 = isdbmbxin, utimerhi = r7 */
};

/* Per thread control registers */
uint32_t stuff_inst_mmode_reg_write[][2] = {
	{0x6ea8c007, 0x6707c000}, /* r7 = isdbmbxin, sgp0 = r7 */
	{0x6ea8c007, 0x6707c001}, /* r7 = isdbmbxin, sgp1 = r7 */
	{0x6ea8c007, 0x6707c002}, /* r7 = isdbmbxin, stid = r7 */
	{0x6ea8c007, 0x6707c003}, /* r7 = isdbmbxin, elr = r7  */
	{0x6ea8c007, 0x6707c004}, /* r7 = isdbmbxin, badva0 = r7 */
	{0x6ea8c007, 0x6707c005}, /* r7 = isdbmbxin, badva1 = r7 */
	{0x6ea8c007, 0x6707c006}, /* r7 = isdbmbxin, ssr = r7 */
	{0x6ea8c007, 0x6707c007}, /* r7 = isdbmbxin, ccr = r7 */
	{0x0, 0x0},				  /* Invalid: S12 reserved */
	{0x0, 0x0},				  /* Invalid: S13 reserved */
	{0x0, 0x0},				  /* Invalid: S14 reserved */
	{0x0, 0x0},				  /* Invalid: S15 reserved */
};

/* Per thread control registers */
uint32_t stuff_inst_global_reg_write[][2] = {
	{0x6ea8c007, 0x6707c010}, /* r7 = isdbmbxin, evb = r7 */
	{0x0, 0x0},				  /* modectl: read only */
	{0x6ea8c007, 0x6707c012}, /* r7 = isdbmbxin, syscfg = r7 */
	{0x0, 0x0},				  /* Invalid: S19 reserved */
	{0x0, 0x0},				  /* ipendad: read only */
	{0x6ea8c007, 0x6707c015}, /* r7 = isdbmbxin, vid = r7 */
	{0x6ea8c007, 0x6707c016}, /* r7 = isdbmbxin, vid1 = r7 */
	{0x6ea8c007, 0x6707c017}, /* r7 = isdbmbxin, bestwait = r7 */
	{0x0, 0x0},				  /* Invalid: S24 reserved */
	{0x0, 0x0},				  /* schdcfg: read only */
	{0x0, 0x0},				  /* Invalid: S26 reserved */
	{0x0, 0x0},				  /* cfgbase: read only  */
	{0x6ea8c007, 0x6707c01c}, /* r7 = isdbmbxin, diag = r7 */
	{0x0, 0x0},				  /* Rev: read only */
	{0x6ea8c007, 0x6707c01e}, /* r7 = isdbmbxin, pcyclelo = r7 */
	{0x6ea8c007, 0x6707c01f}, /* r7 = isdbmbxin, pcyclehi = r7 */
};

enum restart_mode
{
	RESTART_LAZY,
	RESTART_SYNC,
};

enum halt_mode
{
	HALT_LAZY,
	HALT_SYNC,
};

struct hexagon_private_config
{
	struct adiv5_private_config adiv5_config;
	struct arm_cti *cti;
};

int hexagon_arch_state(struct target *target);
void hexagon_wait_loop(void);
void hexagon_long_wait_loop(void);
static int hexagon_poll(struct target *target);
static int hexagon_debug_entry(struct target *target);
static int hexagon_check_state_one(struct target *target, uint32_t mask, bool *halted, uint32_t *debug_thread);
static int hexagon_add_breakpoint(struct target *target, struct breakpoint *breakpoint);
static int hexagon_set_breakpoint(struct target *target, struct breakpoint *breakpoint, uint32_t bpconfig);
static int hexagon_unset_breakpoint(struct target *target, struct breakpoint *breakpoint);
static int hexagon_remove_breakpoint(struct target *target, struct breakpoint *breakpoint);
static int hexagon_read_current_registers(struct target *target, uint32_t hwthrd);
static int hexagon_read_core_reg(struct target *target, struct reg *reg, int regnum, uint32_t hwthrd);
static int hexagon_write_core_reg(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
static int hexagon_read_isdb_reg(struct hexa_info *hexa_info, uint32_t isdb_reg, uint32_t *value);
static int hexagon_write_isdb_reg(struct hexa_info *hexa_info, uint32_t isdb_reg, uint32_t value);
static int hexagon_get_core_reg(struct reg *reg);
static int hexagon_set_core_reg(struct reg *reg, uint8_t *buf);
struct reg *hexagon_reg_current(struct hexa_info *hexa_info, unsigned int regnum, struct reg_cache *cache);
struct reg_cache *hexagon_build_reg_cache(struct target *target, uint32_t hwthrd);
static int hexagon_write_ctrl_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
static int hexagon_write_gpr_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
static int hexagon_write_global_ctrl_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
static int hexagon_dump_hwthrd_reg(struct target *target, uint32_t hwthrd);
static int hexagon_dump_isdb_reg(struct hexa_info *hexa_info);
static int hexagon_restore_stuff_used_reg(struct target *target);
static int hexagon_resume(struct target *target, int current, target_addr_t address, int handle_breakpoints, int debug_execution);
static int hexagon_step(struct target *target, int current, target_addr_t address, int handle_breakpoints);
static uint32_t hexagon_print_pc(struct target *target);
static int hexagon_init_debug_access(struct target *target);
unsigned int get_phys_page(unsigned int lo, unsigned int hi, unsigned int mask);
unsigned int get_phys_mask(unsigned int tlblo);
static void hexagon_update_tlb_entry_in_structure(uint32_t tlb_phy, uint32_t tlb_virtual, uint32_t index);
static void hexagon_populate_vtlb_data(struct target *target);
static void hexagon_update_vtlb_entry_in_structure(uint32_t tlb_phy, uint32_t tlb_virtual, uint32_t index);
static void hexagon_populate_vtlb_entries(struct target *target);
static void hexagon_initialize_axi_ap(struct target *target);
static int hexagon_read_memory(struct target *target, target_addr_t address,
							   uint32_t size, uint32_t count, uint8_t *buffer);
static int hexagon_write_memory(struct target *target, target_addr_t address,
								uint32_t size, uint32_t count, const uint8_t *buffer);
static int hexagon_read_buffer(struct target *target, target_addr_t address,
							   uint32_t size, uint8_t *buffer);
static int hexagon_write_buffer(struct target *target, target_addr_t address,
								uint32_t size, const uint8_t *buffer);
static int hexagon_mmu(struct target *target, int *enabled);
static int hexagon_virt2phys(struct target *target, target_addr_t virt, target_addr_t *phys);
static void hexagon_populate_vtlb_refresh_entries(struct target *target);
static void hexagon_enable_dbg_sys_pwr(struct target *target);
static void hexagon_print_vtlb_entries(void);
static int hexagon_search_virtadd_in_tlb(uint32_t virt, target_addr_t *phys);
static int hexagon_search_virtadd_in_vtlb(struct target *target, uint32_t virt_add, target_addr_t *phys);
static void hexagon_memw_phys_read(struct target *target, target_addr_t phy_address, uint32_t *value);
static int hexagon_read_syscfg_register(struct target *target);
static int hexagon_write_syscfg_register(struct target *target, uint32_t value);
static int hexagon_memw_write(struct target *target, uint32_t virt_address, uint32_t value, uint32_t size);
static unsigned int QURT_getPhysAddr_v2(uint32_t pg_tlblo, uint32_t pg_tlbhi);
static unsigned int hexagon_clrbit(unsigned int d, unsigned int bit);
static unsigned int hexagon_ct0(unsigned int d);
static uint32_t hexagon_etm_on(struct target *target);
static int hexagon_memw_write_instruction_memory(struct target *target, uint32_t virt_address, uint32_t value, uint8_t flag);
static int hexagon_execute_Isync(struct target *target);
static int hexagon_setup_isdb_config(struct target *target, uint32_t old_isdbcfg0, uint8_t hbp_num);
static int hexagon_read_BRKPT_through_stuff(struct target *target);
static void hexagon_hw_watchdog_disable(struct target *target);
static void hexagon_memw_read(struct target *target, uint32_t virt_address, uint32_t *value);
static void hexagon_memw_read_buffer(struct target *target, uint32_t virt_address, uint32_t size, uint8_t *buffer);
static int hexagon_memw_write_buffer(struct target *target, uint32_t virt_address, uint32_t size, const uint8_t *buffer);
void hexagon_update_sp_pc_fp_gdb_server(unsigned int hwthrd, unsigned int *pc, unsigned int *fp, unsigned int *sp);
static void hexagon_stuff_reg_restore_r0_r1_r7(struct target *target);
static void hexagon_stuff_reg_restore_r7(struct target *target);
static void hexagon_stuff_reg_restore_r0_r1_r2_r7(struct target *target);
uint32_t hexagon_no_of_hw_threads(void);

/*
Sending RSP packet from OpenOCD to target via mailbox registers
*/
untrusted_mode hexagon_untrusted_current_state;
static int hexagon_untrusted_concat_rsp();
static int hexagon_untrusted_write_to_mailboxin(struct target *target, uint32_t value);
static uint32_t min_u(uint32_t a, uint32_t b);
static int hexagon_untrusted_read_to_mailboxout(struct target *target, uint32_t *value);
static int hexagon_untrusted_poll_isdbst_set_bit(struct target *target, uint8_t bit);

static int hexagon_untrusted_poll_isdbst_unset_bit(struct target *target, uint8_t bit);
static int send_isdb_interrupt(struct target *target);
static int hexagon_untrusted_mode();
/*Hexagon untrusted Global variables start*/
bool is_hexagon_trusted = false;
bool once_flag = false;
uint32_t hexagon_debug_process_id = 0x2;
/*Hexagon untrusted Global variables end*/
// secure_debug_1 ends

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
void hexagon_start_time_cal_ms(void);
void hexagon_end_time_cal_ms(void);
#endif

static const struct reg_arch_type hexagon_reg_type = {
	.get = hexagon_get_core_reg,
	.set = hexagon_set_core_reg,
};

static uint32_t hexagon_syscfg_reg;

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
int64_t hexagon_time_start = 0, hexagon_time_total = 0;
#endif

struct adiv5_ap *debug_axi_ap = NULL;
vtlb_data hexagon_vtlb_data = {0};
tlb_entries *hexagon_vtlb_entries = NULL;
uint32_t hexagon_r0_used_stuff = 0, hexagon_r1_used_stuff = 0, hexagon_r2_used_stuff = 0, hexagon_r7_used_stuff = 0;

tlb_entries *gpHexagonTlbEntries;

static int initConfig(hexagon_config *pHexCfg)
{
	int i;
	char a = '0';

    gpHexagonThreadNameArray = malloc((pHexCfg->maxHwThreads + 1) * sizeof(*gpHexagonThreadNameArray));
    gpPerHwThrdReg = (uint32_t(*)[HEXAGON_PER_THREAD_REGS])malloc(pHexCfg->maxHwThreads * sizeof(*gpPerHwThrdReg));
    gpSbpHaltedThreadsPC = (uint32_t **)malloc(pHexCfg->maxHwThreads * sizeof(uint32_t));
	gpHexagonTlbEntries  = (tlb_entries*) malloc (pHexCfg->numTlbEntries * sizeof(tlb_entries));

	if (gpHexagonThreadNameArray == NULL  ||  gpPerHwThrdReg == NULL  ||  gpSbpHaltedThreadsPC == NULL  ||  gpHexagonTlbEntries == NULL)
    {
        if (gpHexagonThreadNameArray != NULL)
            free(gpHexagonThreadNameArray);

        if (gpPerHwThrdReg != NULL)
            free(gpPerHwThrdReg);

        if (gpSbpHaltedThreadsPC != NULL)
            free(gpSbpHaltedThreadsPC);

        if (gpHexagonTlbEntries != NULL)
            free(gpHexagonTlbEntries);

        return ERROR_FAIL;
    }
	for (i = 0; i < pHexCfg->maxHwThreads; i++, a++)
	{
		strcpy(gpHexagonThreadNameArray[i], "HW-Thrd-");
		gpHexagonThreadNameArray[i][8] = a;
		gpHexagonThreadNameArray[i][9] = '\0';
	}
	strcpy(gpHexagonThreadNameArray[i], "GLOBAL");

	memset(gpSbpHaltedThreadsPC, 0, (pHexCfg->maxHwThreads * sizeof(uint32_t)));
	memset (gpPerHwThrdReg, 0, (pHexCfg->maxHwThreads * sizeof(*gpPerHwThrdReg)));
	memset (gpHexagonTlbEntries, 0, (pHexCfg->numTlbEntries * sizeof(tlb_entries)));
	return 0;
}

static void deinitConfig(hexagon_config *pHexCfg)
{
    // regthrd_call

    if (gpHexagonThreadNameArray != NULL)
        free(gpHexagonThreadNameArray);

    if (gpPerHwThrdReg != NULL)
        free(gpPerHwThrdReg);

    if (gpSbpHaltedThreadsPC != NULL)
        free(gpSbpHaltedThreadsPC);

    if (gpHexagonTlbEntries != NULL)
        free(gpHexagonTlbEntries);

    return;
}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
void hexagon_start_time_cal_ms(void)
{

	hexagon_time_start = timeval_ms();
}

void hexagon_end_time_cal_ms(void)
{

	hexagon_time_total = timeval_ms() - hexagon_time_start;
}
#endif

/* this function is used to fetch SP , PC and FP value for given HW thread from gdb server  */
void hexagon_update_sp_pc_fp_gdb_server(unsigned int hwthrd, unsigned int *pc, unsigned int *fp, unsigned int *sp)
{
	*pc = gpPerHwThrdReg[hwthrd][HEXAGON_PC];
	*fp = gpPerHwThrdReg[hwthrd][HEXAGON_FP];
	*sp = gpPerHwThrdReg[hwthrd][HEXAGON_SP];
}

uint32_t hexagon_no_of_hw_threads(void)
{
	return gHexConfig.maxHwThreads;
}

static unsigned int QURT_getPhysAddr_v2(uint32_t pg_tlblo, uint32_t pg_tlbhi)
{
	union pg_tlblo_t tlblo;
	union pg_tlbhi_t tlbhi;
	tlblo.raw = pg_tlblo;
	tlbhi.raw = pg_tlbhi;
	return ((hexagon_clrbit((unsigned int)tlblo.info.phys_addr + ((unsigned int)tlbhi.info.ep << 24), (unsigned int)(hexagon_ct0((unsigned int)tlblo.info.phys_addr & 0x7f))) >> 1) & 0xffffff);
}

static unsigned int hexagon_clrbit(unsigned int d, unsigned int bit)
{
	return (d & (~(1 << bit)));
}

static unsigned int hexagon_ct0(unsigned int d)
{
	int i;
	for (i = 0; i < 32; i++)
	{
		if ((d & (1 << i)) != 0)
		{
			return i;
		}
	}
	return 32;
}

/* this interface is to read the TCM memory via memw interface*/
static void hexagon_memw_read_buffer(struct target *target, uint32_t virt_address, uint32_t size, uint8_t *buffer)
{
	uint32_t count, i;
	uint8_t *temp;

	if (virt_address == 0x0)
	{
		LOG_DEBUG("virt_address address passed as NULL");
		return;
	}
	if ((size % 4) == 0)
	{
		count = size / 4;
		temp = buffer;
		for (i = 0; i < count; i++)
		{
			hexagon_memw_read(target, virt_address + 4 * i, (uint32_t *)temp);
			temp = temp + 4;
		}
	}
	else
	{
		LOG_DEBUG("size is not multiple of 4 bytes");
	}
}

/* this interface is to read the TCM memory via memw interface*/
static void hexagon_memw_read(struct target *target, uint32_t virt_address, uint32_t *value)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status, isdbsts;
	uint32_t stuff_inst[] = {0x6ea8c000, 0x9180c007, 0x6707c029};
	/* Stuff instruction 0x6ea8c000-->{r0 =isdbmbxin} 0x9180c007-->{r7 = memw(r0+#0) } 0x6707c029-->{isdbmbxout=r7}*/
	int retval, i;
	uint32_t r0, r7;

	hexagon_r0_used_stuff = 1;
	hexagon_r7_used_stuff = 1;

	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, virt_address);
	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
	for (i = 0; i < 3; i++)
	{
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
			return;
		}
	}
	i = 0;
	while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
	{

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		i++;
		if (i == 100)
			break;
	}
	if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
	{
		LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
		return;
	}
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, value);
	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed ");
}

/* This function is used to write value in syscfg register */
static int hexagon_write_syscfg_register(struct target *target, uint32_t value)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval, i;
	uint32_t isdbsts;
	uint32_t isdb_mmode_cmd, isdb_cmd_status;
	uint32_t stuff_inst[] = {0x6ea8c007, 0x6707c012, 0x57c0c002, 0xa840c000};
	/* Stuff instruction  0x6ea8c007-->{r7 = isdbmbxin } 0x6707c012-->{syscfg = r7} 0x57c0c002--> { isync }, 0xa840c000-->  { syncht } */

	hexagon_r7_used_stuff = 1;
	isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(0));

	/* Monitor mode */
	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);
	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

	for (i = 0; i < 4; i++)
	{
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* 0 - cmd sucessfull, 1 - failure */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode");
			return ERROR_FAIL;
		}
	}
	return ERROR_OK;
}

static int hexagon_read_syscfg_register(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval, i = 0;
	uint32_t isdbsts;
	uint32_t isdb_mmode_cmd, isdb_cmd_status;
	/*Stuff inst  {r7 = syscfg}  {isdbmbxout = r7} */

	hexagon_r7_used_stuff = 1;
	//LOG_DEBUG("Enter in hexagon_read_syscfg_register");

	isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(0));

	/* Monitor mode */
	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_STFINST, 0x6e92c007);
	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

	/* wait till the stuff instruction is executed */
	hexagon_wait_loop();

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

	/* 0 - cmd sucessfull, 1 - failure */
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDBcommand failed in monitor mode");
		return ERROR_OK;
	}
	/*there are 2 stuff instruction here programming second inst */
	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_STFINST, 0x6707c029);
	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);

	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

	/* wait till the stuff instruction is executed */
	hexagon_wait_loop();

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

	if (retval != ERROR_OK)
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

	/* 0 - cmd success, 1 - cmd failure */
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDBcommand failed in monitor mode");
		return ERROR_OK;
	}
	while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
	{
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

		hexagon_wait_loop();

		i++;
		if (i == 10)
			break;
	}

	if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
	{
		LOG_DEBUG("ISDBST status not set for mailbox so skiping reading SYSCFG register ");
		return ERROR_FAIL;
	}
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &hexagon_syscfg_reg);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hexagon_syscfg_reg);
	}
	//LOG_DEBUG("SYSCFG register value =  0x%x", hexagon_syscfg_reg);

	return ERROR_OK;
}

static int hexagon_virt2phys(struct target *target, target_addr_t virt,
							 target_addr_t *phys)
{
	int ret_val;
	uint32_t virt_add;

	virt_add = virt;

	//	LOG_DEBUG("virt address  = 0x%x  ", virt_add);

	ret_val = hexagon_search_virtadd_in_tlb(virt_add, phys);
	if (ret_val == ERROR_OK)
		return ret_val;
#ifdef _VTLB_ENABLED_
	ret_val = hexagon_search_virtadd_in_vtlb(target, virt_add, phys);
#endif
	return ret_val;
}

/* this function is use to convert the Virtual address to physical address using VTLB entries*/
static int hexagon_search_virtadd_in_vtlb(struct target *target, uint32_t virt_add, target_addr_t *phys)
{
	uint32_t offset = 0, i;
	tlb_entries *temp = NULL;
	uint64_t asid;

	//	hexagon_populate_vtlb_refresh_entries(target);
	//	LOG_INFO("hexagon_vtlb_data.valid_vtlb_no_of_entries = 0x%x  ", hexagon_vtlb_data.valid_vtlb_no_of_entries);

	if (hexagon_vtlb_data.vtlb_no_of_entries == 0)
	{
		hexagon_populate_vtlb_data(target);
	}

	for (i = 0; i < hexagon_vtlb_data.valid_vtlb_no_of_entries; i++)
	{
		temp = hexagon_vtlb_entries + i;
		if (virt_add >= temp->virt_add_low && virt_add <= temp->virt_add_high)
		{
			if (temp->globalbit)
			{
				offset = virt_add - temp->virt_add_low;
				*phys = temp->phy_add_low + offset;
				//	LOG_DEBUG("Physical address  = 0x%x  ", (uint32_t)*phys);
				return ERROR_OK;
			}
			else
			{
				offset = virt_add - temp->virt_add_low;
				*phys = temp->phy_add_low + offset;
			}
		}
	}
	if (i == hexagon_vtlb_data.valid_vtlb_no_of_entries)
	{
		*phys = 0;
		//	LOG_DEBUG("Entry not found in Vtable virt address  = 0x%x  ", virt_add);
		return ERROR_FAIL;
	}
	return ERROR_OK;
}

/* this function is use to convert the Virtual address to physical address using TLB entries*/
static int hexagon_search_virtadd_in_tlb(uint32_t virt, target_addr_t *phys)
{
	int i;
	uint32_t offset = 0;
	uint64_t asid;

	for (i = 0; i < gHexConfig.numTlbEntries; i++)
	{
		if ((virt >= gpHexagonTlbEntries[i].virt_add_low) && (virt <= gpHexagonTlbEntries[i].virt_add_high))
		{
			if (gpHexagonTlbEntries[i].globalbit)
			{
				offset = virt - gpHexagonTlbEntries[i].virt_add_low;
				*phys = gpHexagonTlbEntries[i].phy_add_low + offset;
				//	LOG_DEBUG("Physical address  = 0x%x  ", (uint32_t)*phys);
				return ERROR_OK;
			}
			else
			{
				offset = virt - gpHexagonTlbEntries[i].virt_add_low;
				*phys = gpHexagonTlbEntries[i].phy_add_low + offset;
			}
		}
	}
	if (i == gHexConfig.numTlbEntries)
	{
		*phys = 0;
		//LOG_DEBUG("Entry not found in TLB for virt address = 0x%x  ", virt);
		return ERROR_FAIL;
	}
	return ERROR_OK;
}

/* This function is used to read memory of request size using memw_phys  instruction  
	In this function we passed the physical address as an argument */

static void hexagon_memw_phys_read_buffer(struct target *target, target_addr_t phy_address, uint32_t size, uint8_t *buffer)
{
	uint32_t count, i;
	uint8_t *temp;

	if (phy_address == 0x0)
	{
		LOG_DEBUG("Physical address passed as NULL");
		return;
	}

	if ((size % 4) == 0)
	{
		count = size / 4;
		temp = buffer;
		for (i = 0; i < count; i++)
		{
			hexagon_memw_phys_read(target, phy_address + 4 * i, (uint32_t *)temp);
			temp = temp + 4;
		}
	}
	else
	{
		LOG_DEBUG("size is not multiple of 4 bytes");
	}
}

/*This function write to instruction memory in this function if flag is passed as 1 means we are passing the value to write otherwise 
we need to use the brpkt instruction opcode to write into the meory*/

static int hexagon_memw_write_instruction_memory(struct target *target, uint32_t virt_address, uint32_t value, uint8_t flag)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status, isdbsts;
	uint32_t stuff_inst[] = {0x6ea8c000, 0x6ea8c007, 0xa180c700, 0xa000c000, 0xa800c000, 0x56c0c000, 0x57c0c002};
	uint32_t address[2];
	int retval, i;
	target_addr_t phy_addr = 0;
	uint32_t r0, r7;

	/* Stuff instruction  
	0x6ea8c000-->{r0 = isdbmbxin } 0x6ea8c007-->{r7 = isdbmbxin } 0xa180c700-->{memw(r0+#0) = r7}
	0xa000c000-->{dccleana(r0) } 0xa800c000-->{barrier } 0x56c0c000-->{icinva(r0) } 0x57c0c002-->{isync} */

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	LOG_DEBUG("hexagon_memw_write_instruction_memory Enter");

	retval = hexagon_virt2phys(target, virt_address, &phy_addr);
	if (retval == ERROR_FAIL)
	{
		LOG_DEBUG("There is no TLB mapping for virtual address  = 0x%x ", (uint32_t)virt_address);
		return retval;
	}
	hexagon_r0_used_stuff = 1;
	hexagon_r7_used_stuff = 1;
	if (!flag)
		value = 0x6c20c000; //brpkt instruction opcode

	address[0] = virt_address;
	address[1] = value;

	LOG_DEBUG("value = 0x%x", value);
	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");

	for (i = 0; i < 2; i++)
	{
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, address[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
			return ERROR_FAIL;
		}
	}

	for (i = 2; i < 7; i++)
	{
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode");
			return ERROR_FAIL;
		}
	}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

	LOG_DEBUG("hexagon_memw_write_instruction_memory Exit");
	return ERROR_OK;
}

/*This function used to write memory using memw interface  */
static int hexagon_memw_write(struct target *target, uint32_t virt_address, uint32_t value, uint32_t size)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status, isdbsts, sys_cfg;
	uint32_t stuff_inst[] = {0x6ea8c000, 0x6ea8c007, 0xa180c700, 0xa000c000, 0xa800c000, 0xa840c000};
	uint32_t address[2];
	int retval, i = 0;
	uint32_t r0, r7;

	/* Stuff inst  0x6ea8c000-->{r0 = isdbmbxin }0x6ea8c007-->{r7 = isdbmbxin} 
	   0xa180c700-->{memw(r0+#0) = r7 } 0xa000c000-->{dccleana(r0) } 0xa800c000-->{barrier } 0xa840c000-->{syncht } */

	LOG_DEBUG("hexagon_memw_write Enter");

	if (size == 1)
		stuff_inst[2] = 0xa100c700; /* {memb(r0+#0) = r7} */

	if (size == 2)
		stuff_inst[2] = 0xa140c700; /* {memh(r0+#0) = r7} */

	address[0] = virt_address;
	address[1] = value;

	LOG_DEBUG("value = 0x%x", value);
	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");

	hexagon_r0_used_stuff = 1;
	hexagon_r7_used_stuff = 1;

	retval = hexagon_read_syscfg_register(target);
	if (retval == ERROR_OK)
	{
		sys_cfg = hexagon_syscfg_reg;
		sys_cfg = sys_cfg | SYSCFG_L2NRA | SYSCFG_L2NWA;
		sys_cfg = sys_cfg & ~(SYSCFG_L2WB);
		LOG_DEBUG("Writing value in SYSCFG  = 0x%x ", sys_cfg);
		hexagon_write_syscfg_register(target, sys_cfg);
		//hexagon_wait_loop();
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, 0xa840c000);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
			return ERROR_FAIL;
		}
		hexagon_read_syscfg_register(target);
	}

	for (i = 0; i < 2; i++)
	{
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, address[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
			return ERROR_FAIL;
		}
	}
	for (i = 2; i < 6; i++)
	{
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode");
			return ERROR_FAIL;
		}
	}
	LOG_DEBUG("hexagon_memw_write Exit");

	return ERROR_OK;
}

/* This function is used to restore r0, r1, r2 and r7 used during stuff instrcution*/
static void hexagon_stuff_reg_restore_r0_r1_r2_r7(struct target *target)
{
	int retval;

	if (hexagon_r0_used_stuff)
	{
		retval = hexagon_write_gpr_register(target, HEXAGON_R0, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R0]);
		if (retval == ERROR_OK)
			hexagon_r0_used_stuff = 0;
		else
		{
			retval = hexagon_write_gpr_register(target, HEXAGON_R0, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R0]);
			if (retval == ERROR_OK)
				hexagon_r0_used_stuff = 0;
			else
				LOG_DEBUG("Error occured during restoring R0 value used for stuff ");
		}
	}
	if (hexagon_r1_used_stuff)
	{
		retval = hexagon_write_gpr_register(target, HEXAGON_R1, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R1]);
		if (retval == ERROR_OK)
			hexagon_r1_used_stuff = 0;
		else
		{
			retval = hexagon_write_gpr_register(target, HEXAGON_R1, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R1]);
			if (retval == ERROR_OK)
				hexagon_r1_used_stuff = 0;
			else
				LOG_DEBUG("Error occured during restoring R1 value used for stuff ");
		}
	}
	if (hexagon_r2_used_stuff)
	{
		retval = hexagon_write_gpr_register(target, HEXAGON_R2, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R2]);
		if (retval == ERROR_OK)
			hexagon_r2_used_stuff = 0;
		else
		{
			retval = hexagon_write_gpr_register(target, HEXAGON_R2, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R2]);
			if (retval == ERROR_OK)
				hexagon_r2_used_stuff = 0;
			else
				LOG_DEBUG("Error occured during restoring R2 value used for stuff ");
		}
	}
	if (hexagon_r7_used_stuff)
	{
		retval = hexagon_write_gpr_register(target, HEXAGON_R7, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R7]);
		if (retval == ERROR_OK)
			hexagon_r7_used_stuff = 0;
		else
		{
			retval = hexagon_write_gpr_register(target, HEXAGON_R7, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R7]);
			if (retval == ERROR_OK)
				hexagon_r7_used_stuff = 0;
			else
				LOG_DEBUG("Error occured during restoring R7 value used for stuff ");
		}
	}
}

/* This function is used to restore r0, r1 and r7 used during stuff */
static void hexagon_stuff_reg_restore_r0_r1_r7(struct target *target)
{
	hexagon_write_gpr_register(target, HEXAGON_R0, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R0]);
	hexagon_write_gpr_register(target, HEXAGON_R1, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R1]);
	hexagon_write_gpr_register(target, HEXAGON_R7, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R7]);
}

/* This function is used to restore r7 used during stuff */
static void hexagon_stuff_reg_restore_r7(struct target *target)
{
	hexagon_write_gpr_register(target, HEXAGON_R7, HEXAGON_HW_THREAD0, gpPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R7]);
}

/* This function is used to read memory word using memw_phys instruction  
	In this function we passed the physical address as an argument*/
static void hexagon_memw_phys_read(struct target *target, target_addr_t phy_address, uint32_t *value)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status, isdbsts, phy_add[2], t_phy_address;
	uint32_t stuff_inst[] = {0x6ea8c000, 0x6ea8c001, 0x9200e107, 0x6707c029};
	int retval, i;
	uint32_t r0, r1, r7;

	/* Stuff Inst  0x6ea8c000-->{r0 = isdbmbxin} , 0x6ea8c001-->{r1 = isdbmbxin} ,0x9200e107-->{r7 = memw_phys(r0,r1)}
		0x6707c029-->{isdbmbxout = r7}  */

	t_phy_address = phy_address;
	if (t_phy_address == 0x0)
	{
		LOG_DEBUG("Physical address passed as NULL");
		return;
	}
	hexagon_r0_used_stuff = 1;
	hexagon_r1_used_stuff = 1;
	hexagon_r7_used_stuff = 1;

	phy_add[0] = t_phy_address & 0x7ff;
	phy_add[1] = t_phy_address >> 11;
	//LOG_DEBUG("physical address= 0x%x phy_add[0] = 0x%x  phy_add[1] = 0x%x",(uint32_t)phy_address, phy_add[0],phy_add[1]);

	for (i = 0; i < 2; i++)
	{
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, phy_add[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
			return;
		}
	}
	for (i = 2; i < 4; i++)
	{
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
			return;
		}
	}
	i = 0;
	while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
	{

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		i++;
		if (i == 100)
			break;
		//hexagon_wait_loop();
	}
	if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
	{
		LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it isdbsts = 0x%x", isdbsts);
		return;
	}
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, value);
	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed ");
}

static int hexagon_read_buffer(struct target *target, target_addr_t address,
							   uint32_t size, uint8_t *buffer)
{
	int retval = ERROR_OK;
	target_addr_t phy_addr = 0;
	uint32_t value, sys_cfg;

	if (address == 0x0)
	{
		LOG_DEBUG("Virtual address passed as NULL");
		return ERROR_FAIL;
	}
#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	retval = hexagon_virt2phys(target, address, &phy_addr);
	//LOG_DEBUG("hexagon_read_buffer address  = 0x%x and size = %u , phy add = 0x%x", (uint32_t)address,size,(uint32_t)phy_addr);

	if (retval == ERROR_FAIL)
	{
		LOG_DEBUG("There is no TLB mapping for virtual address  = 0x%x ", (uint32_t)address);
		return retval;
	}


	retval = hexagon_read_syscfg_register(target);
	if (retval == ERROR_OK)
	{
		sys_cfg = hexagon_syscfg_reg;
		sys_cfg = sys_cfg | SYSCFG_L2NRA | SYSCFG_L2NWA;
		sys_cfg = sys_cfg & ~(SYSCFG_L2WB);
		// LOG_DEBUG("Writing value in SYSCFG  = 0x%x ", sys_cfg);
		hexagon_write_syscfg_register(target, sys_cfg);
		hexagon_wait_loop();
		hexagon_read_syscfg_register(target);
	}

	if (size < 4)
	{
		hexagon_memw_phys_read(target, phy_addr, &value);
		//	LOG_DEBUG("retrieved value using  hexagon_memw_phys_read for size < 4  = 0x%x ", value);
		switch (size)
		{
		case 1:
			//target_buffer_set_u8(target, buffer, value);
			buffer[0] = (uint8_t)(value >> 0);
			break;
		case 2:
			target_buffer_set_u16(target, buffer, value);
			break;
		case 3:
			target_buffer_set_u24(target, buffer, value);
			break;
		}
		hexagon_write_syscfg_register(target, hexagon_syscfg_reg);
		return retval;
	}
	else if (size == 4)
	{
		hexagon_memw_phys_read(target, phy_addr, &value);
		//	LOG_DEBUG("retrieved value using  hexagon_memw_phys_read = 0x%x ", value);
		target_buffer_set_u32(target, buffer, value);
		hexagon_write_syscfg_register(target, hexagon_syscfg_reg);
		return retval;
	}
	else if ((size % 4) == 0)
	{
		hexagon_memw_phys_read_buffer(target, phy_addr, size, buffer);
		hexagon_write_syscfg_register(target, hexagon_syscfg_reg);
		return retval;
	}
#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

	return retval;
}

static int hexagon_write_buffer(struct target *target, target_addr_t address,
								uint32_t size, const uint8_t *buffer)
{
	int retval = ERROR_OK;
	target_addr_t phy_addr = 0;
	uint32_t value, count;

	if (address == 0x0)
	{
		LOG_DEBUG("Virtual address passed as NULL");
		return ERROR_FAIL;
	}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	retval = hexagon_virt2phys(target, address, &phy_addr);
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_write_buffer address  = 0x%x and size = %u , phy add = 0x%x", (uint32_t)address, size, (uint32_t)phy_addr);
#endif

	if (retval == ERROR_FAIL)
	{
		LOG_DEBUG("There is no TLB mapping for virtual address  = 0x%x ", (uint32_t)address);
		return retval;
	}

	if (size == 3)
	{
		memcpy(&value, (const void *)buffer, 2);
		retval = hexagon_memw_write(target, address, value, 2);
		value = 0;
		memcpy(&value, (const void *)&buffer[2], 1);
		retval = hexagon_memw_write(target, address, value, 1);
		//return retval;
	}
	else if (size <= 4)
	{
		memcpy(&value, (const void *)buffer, size);
		retval = hexagon_memw_write(target, address, value, size);
		//return retval;
	}
	else if ((size % 4) == 0)
	{
		retval = hexagon_memw_write_buffer(target, address, size, buffer);
		//return retval;
	}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif
	return retval;
}
/*this function is use to write memory buffer using memw interface */
static int hexagon_memw_write_buffer(struct target *target, uint32_t virt_address, uint32_t size, const uint8_t *buffer)
{
	uint32_t count, i, value, retval = ERROR_OK;
	uint8_t *temp;

	count = size / 4;
	temp = buffer;

	for (i = 0; i < count; i++)
	{
		memcpy(&value, temp, 4);
		retval = hexagon_memw_write(target, virt_address + 4 * i, value, 4);
		temp = temp + 4;
	}
	return retval;
}

static int hexagon_read_memory(struct target *target, target_addr_t address,
							   uint32_t size, uint32_t count, uint8_t *buffer)
{
	int retval = ERROR_OK;
	LOG_DEBUG("hexagon_read_memory  address  = 0x%x and size = %u,count=%u  ", (uint32_t)address, size, count);
	return retval;
}

static int hexagon_write_memory(struct target *target, target_addr_t address,
								uint32_t size, uint32_t count, const uint8_t *buffer)
{
	int retval = ERROR_OK;
	LOG_DEBUG("hexagon_write_memory  address  = 0x%x and size = %u,count=%u  ", (uint32_t)address, size, count);
	return retval;
}

void hexagon_wait_loop(void)
{
	uint16_t i, loop = 0;

	for (i = 0; i < 2000; i++)
	{
		if ((i % 1000) == 0)
			//LOG_DEBUG("in hexagon_wait_loop()");
			loop++;
	}
}

void hexagon_long_wait_loop(void)
{
	uint32_t i, loop = 0;

	for (i = 0; i < 10000; i++)
	{
		if ((i % 5000) == 0)
			LOG_DEBUG("in hexagon_long_wait_loop()");
		loop++;
	}
}

/*
 * Hexagon Breakpoint and watchpoint functions
 */

/*
 * Setup hardware Breakpoint Register Pair
 * bpconfig parameter will be considered for setting up on-chip breakpoints, otherwise ignored
*/
static int hexagon_set_breakpoint(struct target *target,
								  struct breakpoint *breakpoint, uint32_t bpconfig)
{
	LOG_DEBUG("Entering %s\n", __FUNCTION__);
	int retval;
	int brp_i = 0;
	uint32_t isdbcfg0 = 0;
	//	uint8_t byte_addr_select = 0x0F;
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct hexagon_brp *brp_list = hexagon->brp_list;
	struct adiv5_dap *swddp = hexa_info->dap;

	if (breakpoint->is_set)
	{
		LOG_WARNING("breakpoint already set");
		return ERROR_OK;
	}

	retval = ERROR_OK;
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBCFG0, &isdbcfg0);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBCFG0 read failed 0x%x", isdbcfg0);
		return retval;
	}
	LOG_DEBUG("Reading isdbcfg0...	 isdbcfg0 = 0x%x", isdbcfg0);

	if (breakpoint->type == BKPT_HARD)
	{

		LOG_DEBUG(" %s\t :-------: %d breakpoint->type == BKPT_HARD", __FUNCTION__, __LINE__);
		if (breakpoint->length != 4)
		{
			LOG_DEBUG("bug: breakpoint length should be 4"); //REVIEW: Not applicable if this check has been already done, also NMI bp address can be VA, VA+ASID, PA.
			return ERROR_FAIL;
		}
		LOG_DEBUG(" %s\t :-------: %d\n", __FUNCTION__, __LINE__);

		//		uint32_t bpt_value;				//REVIEW: can be UINT32 as VA is 32bit, & VA+ASID takes 39 bit. NMI //for now considering only VA without ASID
		LOG_DEBUG(" %s\t :-------: %d\t brp_i = %d\n", __FUNCTION__, __LINE__, brp_i);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list = %x\n", __FUNCTION__, __LINE__, brp_list);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[brp_i] = %x\n", __FUNCTION__, __LINE__, brp_list[brp_i]);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[brp_i].used = %d\n", __FUNCTION__, __LINE__, brp_list[brp_i].used);

		while ((brp_list[brp_i].used) && (brp_i < hexagon->brp_num))
		{ //brp_i < 2; 2 HW BP supported till hexagon V71, should have a MACRO for future versions
			brp_i++;
		}
		if (brp_i >= hexagon->brp_num)
		{
			LOG_DEBUG("ERROR Can't add more HW breakpoints");
			return ERROR_TARGET_RESOURCE_NOT_AVAILABLE;
		}
		breakpoint->is_set = brp_i + 1; //REVIEW: NMI Significance of breakpoint->is_set field, from the intuition, it should be 1/0. Keeping as it is AARCH64

		brp_list[brp_i].used = 1;
		brp_list[brp_i].value = breakpoint->address & 0xFFFFFFFFFFFFFFFC; //keeping 64 bit for now, last 2 bit is 0 for 32bit alignment
		brp_list[brp_i].control = bpconfig;								  //REVIEW: assuming this will hold the value of BRKPTCFG0/1 for HW bp
																		  //		bpt_value = brp_list[brp_i].value;

		//TODO: Check if T32 checks for system halted then sets HW BP, or during threads in RUN mode it sets the BP
		int retrycount;
		uint32_t brkptpc, brkptcfg;

		brkptpc = brkptcfg = retrycount = 0;
		retval = ERROR_OK;

		//HW breakpoint PC address write
		retrycount = 5;

		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}
		//HW breakpoint config/settings
		retval = ERROR_OK;
		brkptcfg = brp_list[brp_i].control;
		LOG_DEBUG(" %s\t :-------: %d\t :------------: brkptcfg = %x\n", __FUNCTION__, __LINE__, brkptcfg);
		retrycount = 5;

		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}
		do
		{
			if (brp_i < 1)
			{
				//HW BP 0 config
				//todo: Migrate this work to a helper function. //bp_write_helper()
				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG0, brkptcfg);
			}
			else
			{
				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG1, brkptcfg);
			}

			if (retval != ERROR_OK)
			{
				LOG_WARNING("BRKPTCFG write failed Error code: %d", retval);
			}
			--retrycount;

		} while ((retval != ERROR_OK) && (retrycount > 0));

		if (retval != ERROR_OK)
		{
			//if after 5 retries we are unable to set the HW bp then return from here
			LOG_DEBUG("BRKPTCFG failed after 5 retries 0x%x", brkptcfg);
			return retval;
		}

		brkptpc = brp_list[brp_i].value;
		LOG_DEBUG(" %s\t :-------: %d\t :------------: brkptpc = %x\n", __FUNCTION__, __LINE__, brkptpc);
		retval = ERROR_OK;

		do
		{
			if (brp_i < 1)
			{
				//HW BP 0 PC
				//todo: Migrate this work to a helper function. //bp_write_helper()
				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_BRKPTPC0, brkptpc);
				hexagon_setup_isdb_config(target, isdbcfg0, 0);
			}
			else
			{
				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_BRKPTPC1, brkptpc);
				hexagon_setup_isdb_config(target, isdbcfg0, 1);
			}

			if (retval != ERROR_OK)
			{
				LOG_WARNING("BRKPTPC write failed Error code: %d", retval);
			}
			--retrycount;

		} while ((retval != ERROR_OK) && (retrycount > 0));

		if (retval != ERROR_OK)
		{
			//After 5 retries we are unable to set the HW bp then return from here
			LOG_DEBUG("BRKPTPC write failed after 5 retries 0x%x", brkptpc);
			return retval;
		}

		//	hexagon_dump_isdb_reg(&hexagon->hexa_info);
		hexagon_read_BRKPT_through_stuff(target);

		//debug logs, to be disabled later
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[0] = %x\n", __FUNCTION__, __LINE__, brp_list[0]);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[0].type = %d\n", __FUNCTION__, __LINE__, brp_list[0].type);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[0].value = %llx\n", __FUNCTION__, __LINE__, brp_list[0].value);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[0].used = %d\n", __FUNCTION__, __LINE__, brp_list[0].used);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[0].control = %x\n", __FUNCTION__, __LINE__, brp_list[0].control);

		LOG_DEBUG(" %s\t :-------: %d\t brp_list[1] = %x\n", __FUNCTION__, __LINE__, brp_list[1]);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[1].type = %d\n", __FUNCTION__, __LINE__, brp_list[1].type);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[1].value = %llx\n", __FUNCTION__, __LINE__, brp_list[1].value);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[1].used = %d\n", __FUNCTION__, __LINE__, brp_list[1].used);
		LOG_DEBUG(" %s\t :-------: %d\t brp_list[1].control = %x\n", __FUNCTION__, __LINE__, brp_list[1].control);

		return ERROR_OK;
	}
	else if (breakpoint->type == BKPT_SOFT)
	{
		retval = ERROR_OK;

		uint32_t first_instrn_addr, current_addr;
		first_instrn_addr = 0;
		current_addr = breakpoint->address;
		//		uint8_t code_arr[20]= {0};
		//		uint8_t fwd_code_arr[4]= {0};
		uint8_t bkwd_code_arr[4] = {0}, packet_counter = 0;
		union fourbyte val;

		LOG_DEBUG("In software BP ");
		//	if ((breakpoint->length != 4) && (breakpoint->address == NULL)){
		if ((breakpoint->length != 4) && (current_addr == NULL))
		{
			LOG_DEBUG("bug: breakpoint length should be 4 for sw breakpoints/address should not be null");
			return ERROR_FAIL;
		}
		LOG_DEBUG("Breakpoint address received from gdb address = 0x%x", current_addr);

		val.byte[0] = val.byte[1] = val.byte[2] = val.byte[3] = 0;
		//find First instruction in the packet, There's no specific bit pattern for first instruction of current packet,
		//find out last instruction in previous packet & the next instruction will be first instruction of the current packet
		first_instrn_addr = current_addr;
		uint8_t first_instrn_found = 0;
		while (!first_instrn_found)
		{
			packet_counter++;
			first_instrn_addr -= 4; //start looking from the next address from the current instruction
			retval = ERROR_OK;
			retval = hexagon_read_buffer(target, first_instrn_addr, 4, bkwd_code_arr);

			if (packet_counter >= 10)
			{
				LOG_DEBUG("First instruction not found after 10 memory read, unable to set software berakpoint");
				return ERROR_FAIL;
			}
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK retval = %d", retval);
				continue;
			}
			LOG_DEBUG("the Opcode present at address 0x%x is 0x%x%x%x%x", first_instrn_addr, bkwd_code_arr[3], bkwd_code_arr[2], bkwd_code_arr[1], bkwd_code_arr[0]);

			val.byte[0] = bkwd_code_arr[0];
			val.byte[1] = bkwd_code_arr[1];
			val.byte[2] = bkwd_code_arr[2];
			val.byte[3] = bkwd_code_arr[3];

			if (((val.word & (3 << 14)) >> 14) == 0b11)
			{
				first_instrn_addr += 4;
				LOG_DEBUG("First instruction of the packet found at address 0x%x", first_instrn_addr);
				first_instrn_found = 1;
			}
		}

		retval = ERROR_OK;
		retval = hexagon_read_buffer(target, first_instrn_addr, 4, bkwd_code_arr);
		if (retval != ERROR_OK)
			LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK retval = %d", retval);

		//replacing first instruction address instead of the breakpoint->address, because once the packet execution will start,
		//instruction decoder will pick up/decode brkpt instruction & assume that it's the only instruction in the packet.
		//so there's no need of replacing the rest of the instructions in the packet

		retval = hexagon_memw_write_instruction_memory(target, first_instrn_addr, 0x6c20c000, 0); //value will be ignored hard coded value is 0x6c20c000  {    brkpt }
		if (retval != ERROR_OK)
			LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK");

		//Modifying the breakpoint attributes passed by GDB.
		//Todo: verify this
		//orig_instr[0-3] = bkwd_code_arr[0-3]
		breakpoint->is_set = 1;
		memcpy(breakpoint->orig_instr, bkwd_code_arr, 4);
		breakpoint->address = first_instrn_addr;

		hexagon_setup_isdb_config(target, isdbcfg0, 0xFF);

		//debug purpose to check if the brkpt instruction is written correctly.

		retval = ERROR_OK;
		retval = hexagon_read_buffer(target, first_instrn_addr, 4, bkwd_code_arr);

		if (retval != ERROR_OK)
		{
			LOG_DEBUG("hexagon_memw_read_instruction_memory return value is not OK retval = %d", retval);
		}
		LOG_DEBUG("Debug: after writing breakpoint The Opcode present at address 0x%x is 0x%x%x%x%x", first_instrn_addr, bkwd_code_arr[3], bkwd_code_arr[2], bkwd_code_arr[1], bkwd_code_arr[0]);

		//		buf_set_u32(code, 0, 32, opcode);
		/*
		 * //TODO: 0x6c20c000  {    brkpt } opcode for brkpt instruction, Prior to this ISDBCFG1[11:8] SWBRKPT TNUM mask should be programmed correctly
		//todo: following sequence is followed for setting a sw bp
		//1. Read sysconfig to determine the cache status l1, l2 enabled/disabled??
		//2. Imp bits L2CFG?? L2NWA?? L2NRA?? L2WB??
		 * Implement read_memory(target, address, size, count, buffer);
		 * 13.8.2.1.3 Reading from L1 data cache plus L2 cache plus backing memory
			Load data and return the cached copy if a hit, and the bus copy if a miss, but do not allocate a line
			on a miss. This allows the debugger to non-intrusively inspect the processor�s view of the data. To
			perform this task, the debugger is to use the following procedure:
			1. Set (1) the SYSCFG[L2NRA] bit to force no-read-allocate in L2 cache.
			2. Set (1) the SYSCFG[L2NWA] bit to force no-write-allocate in L2 cache.
			3. Clear (0) the SYSCFG[L2WB] bit to force write-through in L2 cache.
			4. Ensure that the L1 and L2 caches are enabled.
			5. Execute a memw_phys instruction to read the physical address.
			6. This instruction returns the version in cache if found, but it does not allocate a line if missed.
			Because L1 cache and L2 cache are disabled, it reads the backing store.
		//3. replace PC/symbol address opcode with "brkpt"
		//4. Program ISDBCFG1[11:8] sw bp TNUM mask
		//5. resume the threads.
		 *
		 * To Keep In Mind:
		 * brkpt instructions cannot be packetized with other instructions.
		 *
		 *
//		*/

		return ERROR_OK;
	}

	return ERROR_OK;
}

static int hexagon_unset_breakpoint(struct target *target, struct breakpoint *breakpoint)
{
	LOG_DEBUG("Entering %s\n", __FUNCTION__);
	int retval;
	struct hexagon_common *hexagon = target_to_hexagon(target);
	//	struct hexagon_common *hexagon = target->arch_info;
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct hexagon_brp *brp_list = hexagon->brp_list;

	if (!breakpoint->is_set)
	{
		LOG_WARNING("breakpoint not set");
		return ERROR_OK;
	}

	if (breakpoint->type == BKPT_HARD)
	{
		if ((breakpoint->address != 0) && (breakpoint->asid != 0))
		{
			LOG_DEBUG(" %s\t ----------------- %d\n", __FUNCTION__, __LINE__);
			//todo: this condition is true for linked BP, Need to explore more if same is applicable for hexagon??
		}
		else
		{
			LOG_DEBUG(" %s\t ----------------- %d\n", __FUNCTION__, __LINE__);
			int brp_i = breakpoint->is_set - 1;
			if ((brp_i < 0) || (brp_i >= hexagon->brp_num))
			{
				LOG_DEBUG("Invalid BRP number in breakpoint");
				return ERROR_OK;
			}
			//			LOG_DEBUG("rbp %i control 0x%0" PRIx32 " value 0x%0" PRIx64, brp_i,
			//				brp_list[brp_i].control, brp_list[brp_i].value);
			brp_list[brp_i].used = 0;
			brp_list[brp_i].value = 0;
			brp_list[brp_i].control = 0;

			int retrycount = 5;
			retval = ERROR_OK;

			do
			{
				if (brp_i < 1)
				{
					//HW BP 0 config
					//todo: Migrate this work to a helper function. //bp_write_helper()
					retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
													 hexa_info->debug_base + HEXAGON_ISDB_BRKPTPC0, brp_list[brp_i].value);
				}
				else
				{
					retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
													 hexa_info->debug_base + HEXAGON_ISDB_BRKPTPC1, brp_list[brp_i].value);
				}

				if (retval != ERROR_OK)
				{
					LOG_WARNING("BRKPTPC write failed Error code: %d", retval);
				}
				--retrycount;

			} while ((retval != ERROR_OK) && (retrycount > 0));

			if (retval != ERROR_OK)
			{
				//After 5 retries we are unable to set the HW bp then return from here
				LOG_DEBUG("BRKPTPC write failed after 5 retries 0x%llx", brp_list[brp_i].value);
				return retval;
			}

			//HW breakpoint config/settings
			retval = ERROR_OK;
			retrycount = 5;

			do
			{
				if (brp_i < 1)
				{
					//HW BP 0 config
					//todo: Migrate this work to a helper function. //bp_write_helper()
					retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
													 hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG0, brp_list[brp_i].control);
				}
				else
				{
					retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
													 hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG1, brp_list[brp_i].control);
				}

				if (retval != ERROR_OK)
				{
					LOG_WARNING("BRKPTCFG write failed Error code: %d", retval);
				}
				--retrycount;

			} while ((retval != ERROR_OK) && (retrycount > 0));

			if (retval != ERROR_OK)
			{
				//if after 5 retries we are unable to set the HW bp then return from here
				LOG_DEBUG("BRKPTCFG failed after 5 retries 0x%x", brp_list[brp_i].control);
				return retval;
			}
			breakpoint->is_set = 0;
			return ERROR_OK;
		}
	}
	else
	{
		LOG_DEBUG(" %s\t ----------------- %d\n", __FUNCTION__, __LINE__);
		//TODO: Delete sw bp
		union fourbyte val;

		val.byte[0] = breakpoint->orig_instr[0];
		val.byte[1] = breakpoint->orig_instr[1];
		val.byte[2] = breakpoint->orig_instr[2];
		val.byte[3] = breakpoint->orig_instr[3];

		LOG_DEBUG("Removing brkpt, writing back breakpoint->orig_instr = 0x%x", val.word);
		retval = hexagon_memw_write_instruction_memory(target, breakpoint->address, val.word, 1); //replacing the original instruction in place of brkpt instruction
		//todo: check the endianness
		if (retval != ERROR_OK)
			LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK");
	}
	breakpoint->is_set = 0;

	return ERROR_OK;
}

static int hexagon_add_breakpoint(struct target *target,
								  struct breakpoint *breakpoint)
{
	LOG_DEBUG("Entering %s\n", __FUNCTION__);
	struct hexagon_common *hexagon = target_to_hexagon(target);
	uint32_t bpconfig = 0;

	bpconfig |= (1 << 17); //BRKPTPC match enable
						   //	bpconfig |=(0xff<<18);	//STID match enable, if not working properly, disable it & retry. Typical STID = 0x00ff00ff

	//	breakpoint->type = BKPT_SOFT;

	if ((breakpoint->type == BKPT_HARD) && (hexagon->brp_num_available < 1))
	{
		LOG_DEBUG("no hardware breakpoint available");
		return ERROR_TARGET_RESOURCE_NOT_AVAILABLE;
	}

	if (breakpoint->type == BKPT_HARD)
		hexagon->brp_num_available--;

	return hexagon_set_breakpoint(target, breakpoint, bpconfig); //address match enable
}

static int hexagon_remove_breakpoint(struct target *target, struct breakpoint *breakpoint)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	LOG_DEBUG("Entering %s\n", __FUNCTION__);

#if 0
/* It is perfectly possible to remove breakpoints while the target is running */
	if (target->state != TARGET_HALTED) {
		LOG_WARNING("target not halted");
		return ERROR_TARGET_NOT_HALTED;
	}
#endif

	if (breakpoint->is_set)
	{
		hexagon_unset_breakpoint(target, breakpoint);
		if (breakpoint->type == BKPT_HARD)
			hexagon->brp_num_available++;
	}

	return ERROR_OK;
}

static int hexagon_read_isdb_reg(struct hexa_info *hexa_info, uint32_t isdb_reg, uint32_t *value)
{
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval = ERROR_OK;

	/* read the requested register */
	*value = 0;
	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + isdb_reg, value);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDB reg(addr: 0x%x) read failed", isdb_reg);
		return retval;
	}

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("read ISDB reg(addr: 0x%x) -> 0x%x", *value);
#endif

	return ERROR_OK;
}

static int hexagon_write_isdb_reg(struct hexa_info *hexa_info, uint32_t isdb_reg, uint32_t value)
{
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval = ERROR_OK;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("write ISDB reg(addr: 0x%x) -> 0x%x", value);
#endif

	/* write the requested register */
	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + isdb_reg, value);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDB reg(addr: 0x%x) write failed", isdb_reg);
		return retval;
	}
	return ERROR_OK;
}

static int hexagon_dump_isdb_reg(struct hexa_info *hexa_info)
{
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t reg_value;
	;
	int retval = ERROR_OK, i;

	/* dump the all registers */
	retval = enable_dbg_sys_pwr(swddp);
	for (i = 0; i < HEXAGON_MAX_ISDB_REG; i++)
	{
		reg_value = 0;
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + (i * 4), &reg_value);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDB reg(addr: 0x%x) read failed", (i * 4));
			return retval;
		}
#ifdef _DEBUG_HEXAGON_C_
		LOG_DEBUG("ISDB reg dump: ISDB reg(addr: 0x%x) -> 0x%x", reg_value);
#endif
	}
	return retval;
}

static int hexagon_write_global_ctrl_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval, i = 0;
	uint32_t isdbsts;
	uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_write_global_ctrl_register: hw thrd: %d, regnum %d, value %d", hwthrd, regnum, value);
#endif

	if ((regnum == HEXAGON_MODECTL) || (regnum == HEXAGON_S19_RESRV) || (regnum == HEXAGON_IPENDAD) ||
		(regnum >= HEXAGON_S24_RESRV && regnum <= HEXAGON_CFGBASE) || ((regnum == HEXAGON_REV)))
	{
		LOG_DEBUG("Invalid: reserved/readonly register : %d", regnum);
		return ERROR_FAIL;
	}
#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif
	isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));

	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
	}

	/* run the 1st instruction */
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
#endif

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
	}

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_global_reg_write[regnum - HEXAGON_SGP0][0]);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
	}

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
#endif

	//hexagon_wait_loop();

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
	}

	/* wait till the stuff instruction is executed */
	hexagon_wait_loop();

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
#endif

	/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDBcommand failed in monitor  mode");
		return ERROR_OK;
	}
	else
	{
		if (isdbsts & ISDBST_ISDB_MAILBOX_IN)
		{
			i = 0;
			while (isdbsts & ISDBST_ISDB_MAILBOX_IN)
			{

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

				hexagon_wait_loop();
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDB status read for Mboxin %d time", i);
#endif
				i++;
				if (i == 10)
					break;
			}
			if (isdbsts & ISDBST_ISDB_MAILBOX_IN)
			{
				LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, so write failure for register R%d", regnum);
				return ERROR_FAIL;
			}
		}

		/* run the 2nd instruction */
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_global_reg_write[regnum - HEXAGON_SGP0][1]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor  mode");
			return ERROR_OK;
		}
	}
	global_reg[regnum - HEXAGON_EVB] = value;
#if 0
	hexagon_wait_loop();
	hexagon_read_register(target, regnum, hwthrd);
	LOG_DEBUG("after read register value =  0x%x ", global_reg[regnum-HEXAGON_EVB]);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif
	return ERROR_OK;
}

static int hexagon_write_gpr_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval, i = 0;
	uint32_t isdbsts;
	uint32_t isdb_umode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_write_gpr_register: hw thrd: %d, regnum %d, value 0x%x", hwthrd, regnum, value);
#endif
	LOG_DEBUG("hexagon_write_gpr_register: hw thrd: %d, regnum %d, value 0x%x", hwthrd, regnum, value);
	LOG_DEBUG("R30 =  0x%x  R31 =  0x%x", gpPerHwThrdReg[0][30], gpPerHwThrdReg[0][31]);

	isdb_umode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
	}

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
#endif

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
	}
	//hexagon_wait_loop();

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_gpr_write[regnum]);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
	}

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
#endif

	//hexagon_wait_loop();

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
	}

	/* wait till the stuff instruction is executed */
	hexagon_wait_loop();

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status after ISDBCMD write 0x%x", isdbsts);
#endif

	/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDBcommand failed in user mode");
		return ERROR_OK;
	}
	else if (isdbsts & ISDBST_ISDB_MAILBOX_IN)
	{
		i = 0;
		while (isdbsts & ISDBST_ISDB_MAILBOX_IN)
		{

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

			hexagon_wait_loop();
#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDB status read for Mboxin 0x%x time", isdbsts);
#endif

			i++;
			if (i == 10)
				break;
		}
		if (isdbsts & ISDBST_ISDB_MAILBOX_IN)
		{
			LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, write failure for register R%d", regnum);
			return ERROR_FAIL;
		}
	}
	gpPerHwThrdReg[hwthrd][regnum] = value;
#if 0
	hexagon_wait_loop();
	hexagon_read_register(target, regnum, hwthrd);
	LOG_DEBUG("after read register value =  0x%x ", gpPerHwThrdReg[hwthrd][regnum]);
#endif
#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif
	return ERROR_OK;
}

static int hexagon_write_ctrl_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval, i = 0;
	uint32_t isdbsts;
	uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_write_ctrl_register: hw thrd: %d, regnum %d, value 0x%x", hwthrd, regnum, value);
#endif

	if ((regnum == HEXAGON_C5_RESRV) || (regnum >= HEXAGON_C20_RESRV && regnum <= HEXAGON_C20_RESRV))
	{
		LOG_DEBUG("Invalid: reserved register : %d", regnum);
		return ERROR_FAIL;
	}

	isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));

	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
	}

	/* run the 1st instruction */
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
#endif

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
	}

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_ctrl_reg_write[regnum - HEXAGON_SA0][0]);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
	}

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
#endif

	//hexagon_wait_loop();

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
	}

	/* wait till the stuff instruction is executed */
	hexagon_wait_loop();

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("ISDB status after ISDBCMD run 0x%x", isdbsts);
#endif

	/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDBcommand failed in monitor  mode");
		return ERROR_OK;
	}
	else
	{
		if (isdbsts & ISDBST_ISDB_MAILBOX_IN)
		{
			i = 0;
			while (isdbsts & ISDBST_ISDB_MAILBOX_IN)
			{

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

				hexagon_wait_loop();
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDB status read for Mboxin 0x%x time", isdbsts);
#endif

				i++;
				if (i == 10)
					break;
			}
			if (isdbsts & ISDBST_ISDB_MAILBOX_IN)
			{
				LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, write failure for register R%d", regnum);
				return ERROR_FAIL;
			}
		}

		/* run the 2nd instruction */
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_ctrl_reg_write[regnum - HEXAGON_SA0][1]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor  mode");
			return ERROR_OK;
		}
	}
	gpPerHwThrdReg[hwthrd][regnum] = value;
#if 0
	hexagon_wait_loop();
	hexagon_read_register(target, regnum, hwthrd);
	LOG_DEBUG("after read register value =  0x%x ", gpPerHwThrdReg[hwthrd][regnum]);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif
	return ERROR_OK;
}

static int hexagon_write_core_reg(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct reg_cache *cache;
	int retval = ERROR_OK;
	uint32_t i;

	if (regnum < HEXAGON_R0 || regnum >= HEXAGON_MMODE_GLOBAL_MAX)
		return ERROR_COMMAND_SYNTAX_ERROR;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_write_core_reg:%d, Thrd: %d, value %d", regnum, hwthrd, value);
#endif

	/* Get the register of the requested Hw thread */
	cache = hexa_info->core_cache;
	i = 0;
	while ((cache != NULL) && i < hwthrd)
	{
		cache = cache->next;
		i++;
	}

	/* update the register value locally */
	*((uint8_t *)cache->reg_list[regnum].value) = value;
	cache->reg_list[regnum].dirty = true;
	cache->reg_list[regnum].valid = true;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("Before writing:%d", regnum);
#endif

	/* Write the register value to device */
	if (regnum < HEXAGON_GPR_MAX)
	{
		hexagon_write_gpr_register(target, regnum, hwthrd, value);
	}
	else if (regnum < HEXAGON_CTRL_MAX)
	{
		hexagon_write_ctrl_register(target, regnum, hwthrd, value);
	}
	else if ((regnum < HEXAGON_MMODE_PERTHRD_MAX))
	{
		LOG_DEBUG("This reg:%d write is no supported", regnum);
	}
	else if (regnum < HEXAGON_MMODE_GLOBAL_MAX)
	{
		hexagon_write_global_ctrl_register(target, regnum, hwthrd, value);
	}
	else
	{
		LOG_DEBUG("Invalid register to write reg:%d", regnum);
	}

	return retval;
}

static int hexagon_read_core_reg(struct target *target, struct reg *r, int regnum, uint32_t hwthrd)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct reg_cache *cache;
	int retval = ERROR_OK;
	uint32_t i;

	LOG_INFO("reading reg:%d, hw_thrd %d ", regnum, hwthrd);

	if (regnum < 0 || regnum >= HEXAGON_MMODE_GLOBAL_MAX)
		return ERROR_COMMAND_SYNTAX_ERROR;

	/* Read the register of the requested Hw thread */
	cache = hexa_info->core_cache;
	i = 0;
	while ((cache->next != NULL) && i < hwthrd)
	{
		cache = cache->next;
		i++;
	}

	r->value = (uint32_t *)cache->reg_list[regnum].value;
	r->valid = true;
	r->dirty = false;

	return retval;
}

static int hexagon_dump_hwthrd_reg(struct target *target, uint32_t hwthrd)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;

	struct reg_cache *cache;
	uint32_t i;

	if (hwthrd == gHexConfig.maxHwThreads)
	{
		/* dump registers for all Hw thread */
		cache = hexa_info->core_cache;
		while (cache->next != NULL)
		{
			for (i = 0; i < HEXAGON_PER_THREAD_REGS; i++)
			{
				LOG_DEBUG("%s : %s = 0x%x", cache->name,
						  cache->reg_list[i].name, *((uint32_t *)cache->reg_list[i].value));
			}
			cache = cache->next;
		}

		/* dump the global registers */
		for (i = 0; i < HEXAGON_GLOBAL_REGS; i++)
		{
			LOG_DEBUG("%s : %s = 0x%x", cache->name,
					  cache->reg_list[i].name, *((uint32_t *)cache->reg_list[i].value));
		}
	}
	else
	{
		/* dump registers for the requested Hw thread */
		cache = hexa_info->core_cache;
		i = 0;
		while ((cache != NULL) && i < hwthrd)
		{
			cache = cache->next;
			i++;
		}

		for (i = 0; i < HEXAGON_PER_THREAD_REGS; i++)
		{
			LOG_DEBUG("%s : %s = 0x%x", cache->name,
					  cache->reg_list[i].name, *((uint32_t *)cache->reg_list[i].value));
		}
	}

	LOG_DEBUG("exiting	hexagon_dump_hwthrd_reg");

	return ERROR_OK;
}

static int hexagon_reg_setup(struct hexagon_common *hexagon)
{
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct hexa_reg *reg = &hexa_info->reg;
	struct target *target = hexa_info->target;
	struct reg_cache *cache;
	struct reg_cache *list = NULL;
	int retval = ERROR_OK, i;

	if (hexa_info->core_cache != NULL)
	{
		LOG_DEBUG("registers are already built...so skipping");
		return ERROR_OK;
	}

	/* 6 Hw threads reg + 1 global reg */
	for (i = 0; i <= gHexConfig.maxHwThreads; i++)
	{
		if ((cache = hexagon_build_reg_cache(target, i)) == NULL)
			return ERROR_FAIL;

		cache->name = gpHexagonThreadNameArray[i];
		if (hexa_info->core_cache == NULL)
		{
			hexa_info->core_cache = cache;
		}
		else
		{
			list->next = cache;
		}
		list = cache;
	}
	hexa_info->full_context = NULL;
	hexa_info->read_core_reg = hexagon_read_core_reg;
	hexa_info->write_core_reg = hexagon_write_core_reg;
	reg->hexagon_reg_current = hexagon_reg_current;

	return retval;
}

/** Read registers of the the current context **/
int hexagon_read_sfr_registers(struct target *target, uint32_t hwthrd)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	struct reg_cache *cache;
	int retval, j, loop, x, nreg;
	uint32_t isdb_mmode_cmd, isdb_umode_cmd, isdb_gmode_cmd, isdb_cmd_status, i = 0;
	uint32_t isdbsts, read_val[20] = {0};
	const char *reg[] = {"IMASK0", "IMASK1", "IMASK2", "IMASK3", "IMASK4", "IMASK5", "UGP", "GP", "SSR", "BADVA0", "BADVA1", "SYSCFG",
						 "MODECTL", "PCYCLELO", "PCYCLEHI", "EVB", "DIAG", "IPENDAD", "REV", "CFGBASE"};

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_sfr_registers enter- %d", hwthrd);
#endif

	cache = hexa_info->core_cache;
	if (hwthrd == gHexConfig.maxHwThreads)
	{
		loop = gHexConfig.maxHwThreads;
		if (gHexConfig.maxHwThreads == 6)
		{
			isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_6);
			isdb_umode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_USER_LVL, ISDBCMD_TNUM_MASK_6);
			isdb_gmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_GUEST_LVL, ISDBCMD_TNUM_MASK_6);
		}
		else if (gHexConfig.maxHwThreads == 4)
		{
			isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_4);
			isdb_umode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_USER_LVL, ISDBCMD_TNUM_MASK_4);
			isdb_gmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_GUEST_LVL, ISDBCMD_TNUM_MASK_4);
		}
	}
	else
	{
		loop = 1;

		i = 0;
		while ((cache != NULL) && i < hwthrd)
		{
			cache = cache->next;
			i++;
		}

		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));
		isdb_umode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_USER_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));
		isdb_gmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_GUEST_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));
	}

	//	nreg = HEXAGON_CTRL_MNTR_REGS;
	nreg = 20;
	;

	/* Get registers per Hw thread */
	for (x = 0; x < loop && cache != NULL; x++, cache = cache->next)
	{
		for (j = 0; j < nreg; j++)
		{
			/*there are 2 stuff instruction, here programming first inst */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_sfr[j][0]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst[j][0],j=%d", j);
			}
			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK for stuff_inst[j][0],j=%d", j);
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}

#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST read status after first stuff inst j = %d, 0x%x", j, isdbsts);
#endif

			/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

			if (isdb_cmd_status)
			{
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBcommand failed in monitor  mode");
#endif
				retval = enable_dbg_sys_pwr(swddp);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_sfr[j][0]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst[j][0],j=%d", j);
				}
				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_umode_cmd return value is not OK for stuff_inst[j][0],j=%d", j);
				}
				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
				}
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
#endif

				/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
				isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

				if (isdb_cmd_status)
				{
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBcommand failed in user mode");
#endif

					retval = enable_dbg_sys_pwr(swddp);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
					}

					retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
													 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_sfr[j][0]);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
					}
					retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
													 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_gmode_cmd);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_gmode_cmd return value is not OK");
					}
					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
					}
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
#endif

					/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
					isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
					if (isdb_cmd_status)
					{
						LOG_DEBUG("ISDBcommand failed in Guest mode");
						return ERROR_OK;
					}
				}
			}

			/*there are 2 stuff instruction, here programming second inst */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_sfr[j][1]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}
			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}
#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

			/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in monitor  mode");
				retval = enable_dbg_sys_pwr(swddp);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_sfr[j][1]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
				}
				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_umode_cmd return value is not OK");
				}

				/* wait till the stuff instruction is executed */
				hexagon_wait_loop();

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
				}
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
#endif
				/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
				isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

				if (isdb_cmd_status)
				{
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBcommand failed in user  mode");
#endif
					retval = enable_dbg_sys_pwr(swddp);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
					}

					retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
													 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_sfr[j][1]);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
					}
					retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
													 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_gmode_cmd);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_gmode_cmd return value is not OK");
					}

					/* wait till the stuff instruction is executed */
					hexagon_wait_loop();

					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
					}
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
#endif
					/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
					isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
					if (isdb_cmd_status)
					{
						LOG_DEBUG("ISDBcommand failed in Guest  mode");
						return ERROR_OK;
					}
				}
			}

			/*reading mailboxout status in ISDBST register */
			while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
			{
				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

				/* wait till the stuff instruction is executed */
				hexagon_wait_loop();

				i++;
				if (i == 100)
					break;
			}
#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST status value before  reading mailbox register 0x%x, i = %d", isdbsts, i);
#endif
			i = 0;
			if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
			{
				LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for resgiter %s", reg[j]);
				continue;
			}
			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &read_val[j]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", read_val[j]);
			}
			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", read_val[j]);
			LOG_DEBUG("ISDBST status value after  reading mailbox register 0x%x ", isdbsts);
#endif
		}
	}

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_sfr_registers exit");
#endif

	return ERROR_OK;
}

/** Read registers of the the current context **/
int hexagon_read_ctrl_registers(struct target *target, uint32_t hwthrd)
{

	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	struct reg_cache *cache;
	int retval, j, k, l = 0, x, loop;
	uint32_t isdbsts, i = 0;
	uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_ctrl_registers entry - hw thrd: %d", hwthrd);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	cache = hexa_info->core_cache;
	if (hwthrd == gHexConfig.maxHwThreads)
	{
		loop = gHexConfig.maxHwThreads;
		i = 0;
	}
	else
	{
		loop = 1;
		i = 0;
		while ((cache != NULL) && i < hwthrd)
		{
			cache = cache->next;
			i++;
		}
	}

	/* Get per Hw thread control registers */
	for (x = 0; x < loop && cache != NULL; x++, i++, cache = cache->next)
	{
		/* pack the ISDB command for the relevant Hw thread */
		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(i));
#ifdef _DEBUG_HEXAGON_C_
		LOG_DEBUG("hexagon_read_ctrl_registers  isdb_mmode_cmd = %d and i = %d", isdb_mmode_cmd, i);
#endif
		/* Mark r7 as dirty as it is being used for stuff instruction */
		cache->reg_list[HEXAGON_R7].dirty = true;

		//k = 0;
		for (j = HEXAGON_SA0, k = 0; j < HEXAGON_CTRL_MAX; j++, k++)
		{

			if ((j == HEXAGON_C5_RESRV) || (j >= HEXAGON_C20_RESRV && j <= HEXAGON_C29_RESRV))
			{
				//k++;
				continue;
			}

			/* Monitor mode */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_ctrl_reg_read[k][0]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}
			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}

			/* 0 - cmd sucessfull, 1 - failure */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in Monitor mode");
				return ERROR_OK;
			}
			else
			{
				/*there are 2 stuff instruction here programming second inst */
				retval = enable_dbg_sys_pwr(swddp);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_ctrl_reg_read[k][1]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
				}

				/* wait till the stuff instruction is executed */
				hexagon_wait_loop();

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
				}
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

				/* 0 - cmd success, 1 - cmd failure */
				isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
				if (isdb_cmd_status)
				{
					LOG_DEBUG("ISDBcommand failed in Monitor mode");
					return ERROR_OK;
				}
				else
				{
					while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
					{
						retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
														hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

						hexagon_wait_loop();
#ifdef _DEBUG_HEXAGON_C_
						LOG_DEBUG("ISDB status read for Mboxout %d time", j);
#endif

						l++;
						if (l == 10)
							break;
					}
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
#endif

					l = 0;
					if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
					{
						LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
						continue;
					}

					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &gpPerHwThrdReg[x][j]);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg[x][j]);
					}

					cache->reg_list[j].value = &gpPerHwThrdReg[x][j];
					cache->reg_list[j].valid = true;

					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
					LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg[x][j]);
#endif
				}
			}

			//k++;
		}
	}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_ctrl_registers exit - hw thrd: %d", hwthrd);
#endif
	return ERROR_OK;
}

int hexagon_read_imask_register(struct target *target, uint32_t hwthrd)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	struct reg_cache *cache;
	int retval, k, l = 0, x, loop;
	uint32_t isdbsts, i = 0;
	uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_imask_register entry - hw thrd: %d", hwthrd);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	cache = hexa_info->core_cache;
	if (hwthrd == gHexConfig.maxHwThreads)
	{
		loop = gHexConfig.maxHwThreads;
		k = 0;
	}
	else
	{
		loop = 1;

		i = 0;
		while ((cache != NULL) && i < hwthrd)
		{
			cache = cache->next;
			i++;
		}
		k = i;
	}

	/* Get per Hw thread control registers */
	for (x = 0, k = 0; x < loop && cache != NULL; x++, cache = cache->next, k++)
	{

		/* pack the ISDB command for the relevant Hw thread */
		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(k));
		//LOG_DEBUG("hexagon_read_imask_register  isdb_mmode_cmd = %d and i = %d", isdb_mmode_cmd, k);
		/* Monitor mode */
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_mmode_imask_reg_read[k][0]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* 0 - cmd sucessfull, 1 - failure */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in Monitor mode");
			return ERROR_OK;
		}
		else
		{
			/*there are 2 stuff instruction here programming second inst */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_mmode_imask_reg_read[k][1]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}
#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

			/* 0 - cmd success, 1 - cmd failure */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in monitor mode");
				return ERROR_OK;
			}
			else
			{

				/*there are 3 stuff instruction here programming second inst */
				retval = enable_dbg_sys_pwr(swddp);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_mmode_imask_reg_read[k][2]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
				}

				/* wait till the stuff instruction is executed */
				hexagon_wait_loop();

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
				}
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

				/* 0 - cmd success, 1 - cmd failure */
				isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
				if (isdb_cmd_status)
				{
					LOG_DEBUG("ISDBcommand failed in monitor mode");
					return ERROR_OK;
				}
				else
				{
					while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
					{
						retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
														hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

						hexagon_wait_loop();
#ifdef _DEBUG_HEXAGON_C_
						LOG_DEBUG("ISDB status read for Mboxout %d time", x);
#endif

						l++;
						if (l == 10)
							break;
					}
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, k, HEXAGON_IMASK);
#endif

					l = 0;
					if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
					{
						LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", HEXAGON_IMASK);
						continue;
					}

					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &gpPerHwThrdReg[k][HEXAGON_IMASK]);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg[k][HEXAGON_IMASK]);
					}

					cache->reg_list[HEXAGON_IMASK].value = &gpPerHwThrdReg[k][HEXAGON_IMASK];

					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, k, HEXAGON_IMASK);
					LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg[k][HEXAGON_IMASK]);
#endif
				}
			}
		}
	}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_imask_register exit - hw thrd: %d", hwthrd);
#endif
	return ERROR_OK;
}

int hexagon_read_mmode_registers(struct target *target, uint32_t hwthrd)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	struct reg_cache *cache;
	int retval, j, k, l = 0, x, loop;
	uint32_t isdbsts, i = 0;
	uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_mmode_registers entry - hw thrd: %d", hwthrd);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	cache = hexa_info->core_cache;
	if (hwthrd == gHexConfig.maxHwThreads)
	{
		loop = gHexConfig.maxHwThreads;
		i = 0;
	}
	else
	{
		loop = 1;

		i = 0;
		while ((cache != NULL) && i < hwthrd)
		{
			cache = cache->next;
			i++;
		}
	}

	/* Get per Hw thread control registers */
	for (x = 0; x < loop && cache != NULL; x++, i++, cache = cache->next)
	{
		/* pack the ISDB command for the relevant Hw thread */
		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(i));
#ifdef _DEBUG_HEXAGON_C_
		LOG_DEBUG("hexagon_read_mmode_registers  isdb_mmode_cmd = %d and i = %d", isdb_mmode_cmd, i);
#endif
		/* Mark r7 as dirty as it is being used for stuff instruction */
		cache->reg_list[HEXAGON_R7].dirty = true;

		for (j = HEXAGON_SGP0, k = 0; j < HEXAGON_MMODE_PERTHRD_MAX; j++, k++)
		{
			if (j >= HEXAGON_S12_RESRV && j <= HEXAGON_S15_RESRV)
			{
				continue;
			}
			/* Monitor mode */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_mmode_reg_read[k][0]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}
			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}

			/* 0 - cmd sucessfull, 1 - failure */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in Monitor mode");
				return ERROR_OK;
			}
			else
			{
				/*there are 2 stuff instruction here programming second inst */
				retval = enable_dbg_sys_pwr(swddp);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_mmode_reg_read[k][1]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
				}

				/* wait till the stuff instruction is executed */
				hexagon_wait_loop();

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
				}
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

				/* 0 - cmd success, 1 - cmd failure */
				isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
				if (isdb_cmd_status)
				{
					LOG_DEBUG("ISDBcommand failed in monitor  mode");
					return ERROR_OK;
				}
				else
				{
					while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
					{
						retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
														hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

						hexagon_wait_loop();

#ifdef _DEBUG_HEXAGON_C_
						LOG_DEBUG("ISDB status read for Mboxout %d time", j);
#endif

						l++;
						if (l == 10)
							break;
					}
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
#endif

					l = 0;
					if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
					{
						LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
						continue;
					}

					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &gpPerHwThrdReg[x][j]);
					if (retval != ERROR_OK)
					{
						LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg[x][j]);
					}

					cache->reg_list[j].value = &gpPerHwThrdReg[x][j];
					cache->reg_list[j].valid = true;

					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
					LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg[x][j]);
#endif
				}
			}
		}
	}

	hexagon_read_imask_register(target, hwthrd);
#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_mmode_registers exit - hw thrd: %d", hwthrd);
#endif
	return ERROR_OK;
}

/** Read registers of the the current context **/
int hexagon_read_global_ctrl_registers(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	struct reg_cache *cache;
	int retval, j, l = 0, x;
	uint32_t isdb_mmode_cmd, isdb_cmd_status, isdbsts;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_global_ctrl_registers entry");
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	/* global */
	cache = hexa_info->core_cache;
	while ((cache->next != NULL))
	{
		cache = cache->next;
	}

	isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(0));
#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_global_ctrl_registers  isdb_mmode_cmd = %d ", isdb_mmode_cmd);
#endif

	/* Mark r7 as dirty as it is being used for stuff instruction */
	cache->reg_list[HEXAGON_R7].dirty = true;

	for (x = HEXAGON_EVB, j = 0; x < HEXAGON_MMODE_GLOBAL_MAX; x++, j++)
	{
		if ((x == HEXAGON_S19_RESRV) || (x == HEXAGON_S24_RESRV) || (x == HEXAGON_S26_RESRV))
		{
			continue;
		}

		/* Monitor mode */
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_global_reg_read[j][0]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* 0 - cmd sucessfull, 1 - failure */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in Monitor mode");
			return ERROR_OK;
		}
		else
		{
			/*there are 2 stuff instruction here programming second inst */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_global_reg_read[j][1]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}
#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

			/* 0 - cmd success, 1 - cmd failure */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in monitor mode");
				return ERROR_OK;
			}
			else
			{
				while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

					hexagon_wait_loop();

#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDB status read for Mboxout %d time", x);
#endif

					l++;
					if (l == 10)
						break;
				}

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, reg = %d", isdbsts, x);
#endif

				l = 0;
				if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", x);
					continue;
				}

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &global_reg[j]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", global_reg[j]);
				}

				cache->reg_list[j].value = &global_reg[j];
				cache->reg_list[j].valid = true;

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x,  reg = %d", isdbsts, x);
				LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", global_reg[j]);
#endif
			}
		}
	}

	/*for (j=0; j<HEXAGON_MMODE_GLOBAL_MAX-HEXAGON_MMODE_PERTHRD_MAX; j++)
	{
		LOG_DEBUG("Value of  global_reg[%d] =  0x%x ",j,global_reg[j]);
		LOG_DEBUG("cache->reg_list[j].value = 0x%x",*((uint32_t *)cache->reg_list[j].value));
	}*/

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_global_ctrl_registers exit");
#endif
	return ERROR_OK;
}

/** Read registers of the the current context **/
int hexagon_read_register(struct target *target, enum hexagon_registers reg, uint32_t hwthrd)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	struct reg_cache *cache;
	int retval, k = 0, l = 0;
	uint32_t isdb_mmode_cmd, isdb_cmd_status, isdbsts, i = 0;

	LOG_DEBUG("hexagon_read_register: reg: %d, hw thrd: %d", reg, hwthrd);

	cache = hexa_info->core_cache;
	if (hwthrd == gHexConfig.maxHwThreads)
	{
		LOG_DEBUG("Invalid hw-thrd %d", hwthrd);
		return ERROR_FAIL;
	}
	else
	{
		i = 0;
		while ((cache != NULL) && i < hwthrd)
		{
			cache = cache->next;
			i++;
		}
	}

	if (reg >= HEXAGON_R0 && reg < HEXAGON_GPR_MAX)
	{
		/* GPR register */
		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));
		//	LOG_INFO(" isdb_mmode_cmd = %d and reg = %d", isdb_mmode_cmd, reg);

		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_gpr_read[reg - HEXAGON_R0]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in user mode");
			return ERROR_OK;
		}
		else
		{
			while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
			{
				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

				hexagon_wait_loop();

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDB status read for Mboxout %d time", k);
#endif

				k++;
				if (k == 10)
					break;
			}

#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, hwthrd, reg);
#endif

			if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
			{
				LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", reg);
				return ERROR_FAIL;
			}

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &gpPerHwThrdReg[hwthrd][reg]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg[hwthrd][reg]);
			}

			cache->reg_list[reg].value = &gpPerHwThrdReg[hwthrd][reg];
			cache->reg_list[reg].valid = true;

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, hwthrd, reg);
			LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg[hwthrd][reg]);
#endif
		}
	}
	else if (reg >= HEXAGON_SA0 && reg < HEXAGON_CTRL_MAX)
	{
		/* Control register */
		/* pack the ISDB command for the relevant Hw thread */
		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));

		//	LOG_INFO("isdb_mmode_cmd = %d and reg = %d", isdb_mmode_cmd, reg);

		/* Mark r7 as dirty as it is being used for stuff instruction */
		cache->reg_list[HEXAGON_R7].dirty = true;

		if ((reg == HEXAGON_C5_RESRV) || (reg >= HEXAGON_C20_RESRV && reg <= HEXAGON_C29_RESRV))
		{
			LOG_DEBUG("Invalid: Reserved register: %d", reg);
			return ERROR_FAIL;
		}

		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_ctrl_reg_read[reg - HEXAGON_SA0][0]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* 0 - cmd sucessfull, 1 - failure */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in Monitor mode");
			return ERROR_OK;
		}
		else
		{
			/*there are 2 stuff instruction here programming second inst */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_ctrl_reg_read[reg - HEXAGON_SA0][1]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}

#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

			/* 0 - cmd success, 1 - cmd failure */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in Monitor mode");
				return ERROR_OK;
			}
			else
			{
				while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

					hexagon_wait_loop();

#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDB status read for Mboxout %d time", l);
#endif

					l++;
					if (l == 10)
						break;
				}

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, hwthrd, reg);
#endif

				if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", reg);
					return ERROR_FAIL;
				}

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &gpPerHwThrdReg[hwthrd][reg]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg[hwthrd][reg]);
				}

				cache->reg_list[reg].value = &gpPerHwThrdReg[hwthrd][reg];
				cache->reg_list[reg].valid = true;

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, hwthrd, reg);
				LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", &gpPerHwThrdReg[hwthrd][reg]);
#endif
			}
		}
	}
	else if (reg >= HEXAGON_SGP0 && reg < HEXAGON_MMODE_PERTHRD_MAX)
	{
		/* Monitor mode register */
		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(hwthrd));

		//	LOG_INFO("isdb_mmode_cmd = %d and reg = %d", isdb_mmode_cmd, reg);

		/* Mark r7 as dirty as it is being used for stuff instruction */
		cache->reg_list[HEXAGON_R7].dirty = true;

		if (reg >= HEXAGON_S12_RESRV && reg <= HEXAGON_S15_RESRV)
		{
			LOG_DEBUG("Invalid: Reserved register: %d", reg);
			return ERROR_FAIL;
		}

		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_mmode_reg_read[reg - HEXAGON_SGP0][0]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* 0 - cmd sucessfull, 1 - failure */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in Monitor mode");
			return ERROR_OK;
		}
		else
		{
			/*there are 2 stuff instruction here programming second inst */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_mmode_reg_read[reg - HEXAGON_SGP0][1]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}

#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

			/* 0 - cmd success, 1 - cmd failure */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in monitor  mode");
				return ERROR_OK;
			}
			else
			{
				while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

					hexagon_wait_loop();

#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDB status read for Mboxout %d time", k);
#endif

					k++;
					if (k == 10)
						break;
				}

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, hwthrd, reg);
#endif

				if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", reg);
					return ERROR_FAIL;
				}

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &gpPerHwThrdReg[hwthrd][reg]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg[hwthrd][reg]);
				}

				cache->reg_list[reg].value = &gpPerHwThrdReg[hwthrd][reg];
				cache->reg_list[reg].valid = true;

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, hwthrd, reg);
				LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg[hwthrd][reg]);
#endif
			}
		}
	}
	else if (reg >= HEXAGON_EVB && reg < HEXAGON_MMODE_GLOBAL_MAX)
	{
		/* global register */
		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(0));

		LOG_INFO(" isdb_mmode_cmd = %d ", isdb_mmode_cmd);

		if ((reg == HEXAGON_S19_RESRV) || (reg == HEXAGON_S24_RESRV) || (reg == HEXAGON_S26_RESRV))
		{
			LOG_DEBUG("Invalid: Reserved register: %d", reg);
			return ERROR_FAIL;
		}

		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_global_reg_read[reg - HEXAGON_EVB][0]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* 0 - cmd sucessfull, 1 - failure */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in Monitor mode");
			return ERROR_OK;
		}
		else
		{
			/*there are 2 stuff instruction here programming second inst */
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_global_reg_read[reg - HEXAGON_EVB][1]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}
#ifdef _DEBUG_HEXAGON_C_
			LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

			/* 0 - cmd success, 1 - cmd failure */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in monitor mode");
				return ERROR_OK;
			}
			else
			{
				while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

					hexagon_wait_loop();

#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDB status read for Mboxout %d time", k);
#endif

					k++;
					if (k == 10)
						break;
				}

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, reg = %d", isdbsts, reg);
#endif

				l = 0;
				if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", reg);
					return ERROR_FAIL;
				}

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &global_reg[reg - HEXAGON_EVB]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", global_reg[reg - HEXAGON_EVB]);
				}

				cache->reg_list[reg].value = &global_reg[reg - HEXAGON_EVB];
				cache->reg_list[reg].valid = true;

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x,  reg = %d", isdbsts, reg);
				LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", global_reg[reg - HEXAGON_EVB]);
#endif
			}
		}
	}
	else
	{
		LOG_DEBUG("Invalid reg %d ", reg);
		return ERROR_FAIL;
	}

	return ERROR_OK;
}

/** Read registers of the the current context **/
int hexagon_read_gpr_registers(struct target *target, uint32_t hwthrd)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	struct reg_cache *cache;
	int retval, j, k = 0, loop, x;
	uint32_t isdb_mmode_cmd, isdb_cmd_status, isdbsts, i = 0;

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_gpr_registers entry - hw thrd: %d", hwthrd);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	cache = hexa_info->core_cache;
	if (hwthrd == gHexConfig.maxHwThreads)
	{
		loop = gHexConfig.maxHwThreads;
		i = 0;
	}
	else
	{
		loop = 1;
		i = 0;
		while ((cache != NULL) && i < hwthrd)
		{
			cache = cache->next;
			i++;
		}
	}

	/* Get registers per Hw thread */
	for (x = 0; x < loop && cache != NULL; x++, i++, cache = cache->next)
	{
		/* pack the ISDB command for the relevant Hw thread */
		isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(i));
#ifdef _DEBUG_HEXAGON_C_
		LOG_DEBUG("hexagon_read_gpr_registers  isdb_mmode_cmd = %d and i = %d", isdb_mmode_cmd, i);
#endif

		for (j = 0; j < HEXAGON_GPR_REGS; j++)
		{

			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst_gpr_read[j]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}
			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}

			/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in user mode");
				return ERROR_OK;
			}
			else
			{
				while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{

					retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
													hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

					hexagon_wait_loop();
#ifdef _DEBUG_HEXAGON_C_
					LOG_DEBUG("ISDB status read for Mboxout %d time", j);
#endif

					k++;
					if (k == 10)
						break;
				}
#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
#endif

				k = 0;
				if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
				{
					LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
					continue;
				}

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &gpPerHwThrdReg[x][j]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg[x][j]);
				}

				cache->reg_list[j].value = &gpPerHwThrdReg[x][j];
				cache->reg_list[j].valid = true;

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

#ifdef _DEBUG_HEXAGON_C_
				LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
				LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg[x][j]);
#endif
			}
		}
	}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

#ifdef _DEBUG_HEXAGON_C_
	LOG_DEBUG("hexagon_read_gpr_registers exit - hw thrd: %d", hwthrd);
#endif

	return ERROR_OK;
}

static int hexagon_restore_stuff_used_reg(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct reg_cache *cache;
	int i = 0;

	LOG_DEBUG("hexagon_restore_stuff_used_reg");

	i = 0;
	cache = hexa_info->core_cache;
	while (cache != NULL)
	{
		/* check whether R7 is being used for stuff instruction */
		if (cache->reg_list[HEXAGON_R7].dirty == true)
		{
			LOG_DEBUG("Writing modifed R7");

			hexagon_write_core_reg(target, HEXAGON_R7, i, *((uint32_t *)cache->reg_list[HEXAGON_R7].value));
			cache->reg_list[HEXAGON_R7].dirty = false;
		}
		cache = cache->next;
		i++;
	}

	return ERROR_OK;
}

/* This function used to initialize the AXI-AP */
static void hexagon_initialize_axi_ap(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval, i;

	LOG_DEBUG("hexagon_initialize_axi_ap  Enter");
	retval = enable_dbg_sys_pwr(swddp);

	if (debug_axi_ap == NULL)
	{
		/* Search for the AXI-AP - it is needed for access to memory */
		retval = dap_find_get_ap(swddp, AP_TYPE_AXI_AP, &debug_axi_ap);
		if (retval != ERROR_OK)
		{
			for (i = 0; i < 10; i++)
			{
				hexagon_wait_loop();
				retval = dap_find_get_ap(swddp, AP_TYPE_AXI_AP, &debug_axi_ap);
				if (retval == ERROR_OK)
					break;
			}
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("Could not find AP_TYPE_AXI_AP for debug access");
				LOG_DEBUG("Critical connection Error, Please reboot the device and try to attach again");
				return;
			}
		}

		retval = enable_dbg_sys_pwr(swddp);
		retval = mem_ap_init(debug_axi_ap);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("Could not initialize the AP_TYPE_AXI_AP");
			return;
		}
		debug_axi_ap->memaccess_tck = 10;
	}
	LOG_DEBUG("hexagon_initialize_axi_ap  Exit");
}

/* This function used to make sure that system debug power domain is on */
static void hexagon_enable_dbg_sys_pwr(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	int retval = ERROR_OK;
	struct adiv5_dap *swddp = hexa_info->dap;

	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("enable_dbg_sys_pwr api returned value is not OK");
		return;
	}
}

/* This function refresh the VTLB entries in case of Halt / step in etc*/
static void hexagon_populate_vtlb_refresh_entries(struct target *target)
{
	int retval = ERROR_OK;

	LOG_DEBUG("hexagon_populate_vtlb_refresh_entries  Enter");

	if (hexagon_vtlb_data.vtlb_no_of_entries == 0)
	{
		hexagon_populate_vtlb_data(target);
		return;
	}

#ifdef HEXAGON_VTLB_AXI
	if (debug_axi_ap == NULL)
		hexagon_initialize_axi_ap(target);
	hexagon_enable_dbg_sys_pwr(target);

	retval = mem_ap_read_buf(debug_axi_ap,
							 (uint8_t *)&hexagon_vtlb_data.vtlb_current_counter, 4, 1, hexagon_vtlb_data.QURTK_vtlb_main_PA - 16);

	if (retval != ERROR_OK)
	{
		LOG_DEBUG("mem_ap_read_buf API failed to read");
		return;
	}
	if (hexagon_vtlb_data.vtlb_previous_counter == hexagon_vtlb_data.vtlb_current_counter)
	{
		return;
	}
	hexagon_enable_dbg_sys_pwr(target);
	retval = mem_ap_read_buf(debug_axi_ap, (uint8_t *)&hexagon_vtlb_data.vtlb_no_of_entries, 4, 1, hexagon_vtlb_data.QURTK_VTLB_DATA_PA);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("mem_ap_read_buf API failed to read");
		return;
	}
#endif

#ifdef HEXAGON_VTLB_MEM_PHYS
	hexagon_memw_phys_read(target, hexagon_vtlb_data.QURTK_vtlb_main_PA - 16, &hexagon_vtlb_data.vtlb_current_counter);
	if (hexagon_vtlb_data.vtlb_previous_counter == hexagon_vtlb_data.vtlb_current_counter)
	{
		return;
	}
	hexagon_memw_phys_read(target, hexagon_vtlb_data.QURTK_VTLB_DATA_PA, &hexagon_vtlb_data.vtlb_no_of_entries);
#endif

#ifdef HEXAGON_VTLB_MEMW
	hexagon_memw_read(target, hexagon_vtlb_data.QURTK_vtlb_main_VA - 16, &hexagon_vtlb_data.vtlb_current_counter);
	if (hexagon_vtlb_data.vtlb_previous_counter == hexagon_vtlb_data.vtlb_current_counter)
	{
		return;
	}
	hexagon_memw_read(target, hexagon_vtlb_data.QURTK_VTLB_DATA_VA, &hexagon_vtlb_data.vtlb_no_of_entries);
#endif

	LOG_DEBUG("hexagon_vtlb_data.vtlb_no_of_entries = 0x%x and retval = %d", hexagon_vtlb_data.vtlb_no_of_entries, retval);

	/* updating the TLB entries also here  */
	//hexagon_read_tlb_entry(target);

	if (hexagon_vtlb_entries == NULL)
	{
		hexagon_vtlb_entries = malloc(sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
		memset(hexagon_vtlb_entries, 0, sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
	}
	else
	{
		free(hexagon_vtlb_entries);
		hexagon_vtlb_entries = NULL;
		hexagon_vtlb_entries = malloc(sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
		memset(hexagon_vtlb_entries, 0, sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
	}
	hexagon_populate_vtlb_entries(target);
	LOG_DEBUG("hexagon_populate_vtlb_refresh_entries  Exit");
}

/* This function populate the VTLB global data like no of entries in VTLB, counter and allocate VTLB memory for entries */
static void hexagon_populate_vtlb_data(struct target *target)
{
	LOG_DEBUG("hexagon_populate_vtlb_data  Enter");

	/*if(hexagon_vtlb_data.QURTK_VTLB_DATA_VA != 0)
		return;*/

#ifdef HEXAGON_VTLB_AXI
	if (debug_axi_ap == NULL)
		hexagon_initialize_axi_ap(target);
#endif

	hexagon_enable_dbg_sys_pwr(target);

	hexagon_vtlb_data.valid_vtlb_no_of_entries = 0;
	hexagon_enable_dbg_sys_pwr(target);

#ifdef HEXAGON_VTLB_AXI
	retval = mem_ap_read_buf(debug_axi_ap,
							 (uint8_t *)&hexagon_vtlb_data.vtlb_current_counter, 4, 1, hexagon_vtlb_data.QURTK_vtlb_main_PA - 16);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("mem_ap_read_buf API failed to read");
		return;
	}
	hexagon_vtlb_data.vtlb_previous_counter = hexagon_vtlb_data.vtlb_current_counter;
	LOG_DEBUG("hexagon_vtlb_data.vtlb_current_counter = 0x%x and retval = %d", hexagon_vtlb_data.vtlb_current_counter, retval);

	hexagon_enable_dbg_sys_pwr(target);
	retval = mem_ap_read_buf(debug_axi_ap, (uint8_t *)&hexagon_vtlb_data.vtlb_no_of_entries, 4, 1, hexagon_vtlb_data.QURTK_VTLB_DATA_PA);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("mem_ap_read_buf API failed to read");
		return;
	}
	LOG_DEBUG("hexagon_vtlb_data.vtlb_no_of_entries = 0x%x and retval = %d", hexagon_vtlb_data.vtlb_no_of_entries, retval);
#endif

#ifdef HEXAGON_VTLB_MEM_PHYS
	hexagon_memw_phys_read(target, hexagon_vtlb_data.QURTK_vtlb_main_PA - 16, &hexagon_vtlb_data.vtlb_current_counter);
	hexagon_vtlb_data.vtlb_previous_counter = hexagon_vtlb_data.vtlb_current_counter;
	LOG_DEBUG("hexagon_vtlb_data.vtlb_current_counter = 0x%x ", hexagon_vtlb_data.vtlb_current_counter);
	hexagon_memw_phys_read(target, hexagon_vtlb_data.QURTK_VTLB_DATA_PA, &hexagon_vtlb_data.vtlb_no_of_entries);
	LOG_DEBUG("hexagon_vtlb_data.vtlb_no_of_entries = 0x%x ", hexagon_vtlb_data.vtlb_no_of_entries);
#endif

#ifdef HEXAGON_VTLB_MEMW
	hexagon_memw_read(target, hexagon_vtlb_data.QURTK_vtlb_main_VA - 16, &hexagon_vtlb_data.vtlb_current_counter);
	hexagon_vtlb_data.vtlb_previous_counter = hexagon_vtlb_data.vtlb_current_counter;
	LOG_DEBUG("hexagon_vtlb_data.vtlb_current_counter = 0x%x ", hexagon_vtlb_data.vtlb_current_counter);
	hexagon_memw_read(target, hexagon_vtlb_data.QURTK_VTLB_DATA_VA, &hexagon_vtlb_data.vtlb_no_of_entries);
	LOG_DEBUG("hexagon_vtlb_data.vtlb_no_of_entries = 0x%x ", hexagon_vtlb_data.vtlb_no_of_entries);

#endif

	// need to check this logic later to read below memory and assign specific bits to members

	/* retval = mem_ap_read_buf(debug_ap,
		(uint8_t *)&hexagon_vtlb_data.vtlb_no_of_entries1, 4, 1, hexagon_vtlb_data.QURTK_VTLB_DATA_PA + 0x60DD);

	LOG_DEBUG("hexagon_vtlb_data.vtlb_no_of_entries1 = 0x%x and retval = %d",hexagon_vtlb_data.vtlb_no_of_entries1,retval); */
	if (hexagon_vtlb_entries == NULL)
	{
		hexagon_vtlb_entries = malloc(sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
		memset(hexagon_vtlb_entries, 0, sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
	}
	hexagon_populate_vtlb_entries(target);
	LOG_DEBUG("hexagon_populate_vtlb_data  Exit");
}

/* This function populate the VTLB entries from QURTK_VTLB_DATA*/
static void hexagon_populate_vtlb_entries(struct target *target)
{

	uint32_t output[2] = {0}, i, address;



#ifdef _KODIAK_TARGET_
	address = hexagon_vtlb_data.QURTK_VTLB_DATA_PA + 0x40E0;
#ifdef HEXAGON_VTLB_MEMW
	address = hexagon_vtlb_data.QURTK_VTLB_DATA_VA + 0x40E0;
#endif
#endif

	LOG_DEBUG("hexagon_populate_vtlb_entries  Enter");

#ifdef HEXAGON_VTLB_AXI
	if (debug_axi_ap == NULL)
		hexagon_initialize_axi_ap(target);
#endif
	hexagon_enable_dbg_sys_pwr(target);
	hexagon_vtlb_data.valid_vtlb_no_of_entries = 0;

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

#ifdef HEXAGON_VTLB_AXI
	for (i = 0; i < hexagon_vtlb_data.vtlb_no_of_entries; i++)
	{
		hexagon_enable_dbg_sys_pwr(target);
		retval = mem_ap_read_buf(debug_axi_ap, (uint8_t *)&output, 4, 2, address + 8 * i);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("mem_ap_read_buf API failed to read");
			continue;
		}
		hexagon_update_vtlb_entry_in_structure(output[0], output[1], i);
	}
#endif

#ifdef HEXAGON_VTLB_MEM_PHYS
	for (i = 0; i < hexagon_vtlb_data.vtlb_no_of_entries; i++)
	{
		hexagon_memw_phys_read(target, address, &output[0]);
		hexagon_memw_phys_read(target, address + 4, &output[1]);
		//	LOG_DEBUG("Phy_page = 0x%08x and virtual page  = 0x%08x " , output[0],output[1]);
		hexagon_update_vtlb_entry_in_structure(output[0], output[1], i);
		address = address + 8;
	}
#endif

#ifdef HEXAGON_VTLB_MEMW
	for (i = 0; i < hexagon_vtlb_data.vtlb_no_of_entries; i++)
	{
		hexagon_memw_read(target, address, &output[0]);
		hexagon_memw_read(target, address + 4, &output[1]);
		//	LOG_DEBUG("Phy_page = 0x%08x and virtual page  = 0x%08x " , output[0],output[1]);
		hexagon_update_vtlb_entry_in_structure(output[0], output[1], i);
		address = address + 8;
	}
#endif

	hexagon_print_vtlb_entries();

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

	LOG_DEBUG("hexagon_populate_vtlb_entries  Exit");
}
/* This function print the VTLB entries*/
static void hexagon_print_vtlb_entries(void)
{
	tlb_entries *temp = NULL;
	uint32_t i;
	LOG_DEBUG("Printing the VTLB content");

	for (i = 0; i < hexagon_vtlb_data.valid_vtlb_no_of_entries; i++)
	{
		temp = hexagon_vtlb_entries + i;
		/*LOG_DEBUG("VA = 0x%x --> PA = 0x%x ", temp->virt_tlb_raw_data,temp->phys_tlb_raw_data);
		LOG_DEBUG("VA Page = 0x%08x PA Page =  0x%08x and Page size = %d", temp->virt_page,temp->phy_page,temp->page_size);*/
		LOG_DEBUG("VA = 0x%08x -- 0x%08x and PA = 0x%08x -- 0x%08x", temp->virt_add_low, temp->virt_add_high,
				  (uint32_t)temp->phy_add_low, (uint32_t)temp->phy_add_high);
	}
}

/* this function update the tlb entry in global structure  gpHexagonTlbEntries */
static void hexagon_update_vtlb_entry_in_structure(uint32_t tlb_phy, uint32_t tlb_virtual, uint32_t index)
{
	uint32_t mask, size = 0, virt_page, phy_page, virt_add, phy_add;
	uint8_t global_bit;
	char *page_size;
	tlb_entries *temp = NULL;
	union pg_tlblo_t tlblo;
	union pg_tlbhi_t tlbhi;

	//LOG_DEBUG("hexagon_update_vtlb_entry_in_structure  Enter");
	if ((index >= hexagon_vtlb_data.vtlb_no_of_entries) || (hexagon_vtlb_data.valid_vtlb_no_of_entries >= hexagon_vtlb_data.vtlb_no_of_entries))
	{
		LOG_DEBUG("Index is greate than hexagon_vtlb_data.vtlb_no_of_entries");
		return;
	}
	virt_page = VIRT_PAGE(tlb_virtual);
	global_bit = P_G(tlb_virtual);
	/*if(!global_bit)
		return; */
	if (virt_page == 0x0)
		return;
	tlblo.raw = tlb_phy;
	tlbhi.raw = tlb_virtual;
	virt_add = virt_page << 12;
	//phy_page = get_phys_page(tlb_phy, tlb_virtual, mask);
	phy_page = QURT_getPhysAddr_v2(tlblo.raw, tlbhi.raw);
	phy_add = phy_page << 12;

	if ((virt_add == 0x0) || (phy_add == 0x0))
	{
		LOG_DEBUG("Virtual / Physical  address is NULL for raw phy= 0x%08x and raw virtual = 0x%08x ", tlb_phy, tlb_virtual);
		return;
	}

	//temp = hexagon_vtlb_entries+index;
	temp = hexagon_vtlb_entries + hexagon_vtlb_data.valid_vtlb_no_of_entries;
	mask = get_phys_mask(tlb_phy);
	temp->virt_tlb_raw_data = tlb_virtual;
	temp->phys_tlb_raw_data = tlb_phy;
	//temp->phy_page = get_phys_page(tlb_phy, tlb_virtual, mask);
	temp->phy_page = phy_page;
	//temp->virt_page = VIRT_PAGE(tlb_virtual);
	temp->virt_page = virt_page;
	temp->asid = ASID(tlb_virtual);
	temp->R = P_READ(tlb_phy);
	temp->W = P_WRITE(tlb_phy);
	temp->X = P_EXEC(tlb_phy);
	temp->U = P_USER(tlb_phy);
	temp->CCCC = P_CCCC(tlb_phy);
	temp->S = P_S(tlb_phy);
	temp->validbit = P_V(tlb_virtual);
	//temp->globalbit = P_G(tlb_virtual);
	temp->globalbit = global_bit;
	temp->EP = P_EP(tlb_virtual);
	temp->A1 = P_A1(tlb_virtual);
	temp->A0 = P_A0(tlb_virtual);
	page_size = PAGE_SIZE(tlb_phy, mask);
	hexagon_vtlb_data.valid_vtlb_no_of_entries++;

	if (strcmp(page_size, "4KB") == 0)
	{
		temp->page_size = HEXAGON_TLB_PAGE_SIZE_4KB;
		size = HEXAGON_PAGE_SIZE_4K - 1;
	}
	else if (strcmp(page_size, "16KB") == 0)
	{
		temp->page_size = HEXAGON_TLB_PAGE_SIZE_16KB;
		size = HEXAGON_PAGE_SIZE_16K - 1;
	}
	else if (strcmp(page_size, "64KB") == 0)
	{
		temp->page_size = HEXAGON_TLB_PAGE_SIZE_64KB;
		size = HEXAGON_PAGE_SIZE_64K - 1;
	}
	else if (strcmp(page_size, "256KB") == 0)
	{
		temp->page_size = HEXAGON_TLB_PAGE_SIZE_256KB;
		size = HEXAGON_PAGE_SIZE_256K - 1;
	}
	else if (strcmp(page_size, "1MB") == 0)
	{
		temp->page_size = HEXAGON_TLB_PAGE_SIZE_1MB;
		size = HEXAGON_PAGE_SIZE_1M - 1;
	}
	else if (strcmp(page_size, "4MB") == 0)
	{
		temp->page_size = HEXAGON_TLB_PAGE_SIZE_4MB;
		size = HEXAGON_PAGE_SIZE_4M - 1;
	}
	else if (strcmp(page_size, "16MB") == 0)
	{
		temp->page_size = HEXAGON_TLB_PAGE_SIZE_16MB;
		size = HEXAGON_PAGE_SIZE_16M - 1;
	}

	temp->virt_add_low = virt_add;
	temp->virt_add_high = virt_add + size;

	temp->phy_add_low = temp->phy_page << 12;
	temp->phy_add_high = temp->phy_add_low + size;
	//LOG_DEBUG("index = %d, VA = 0x%08x -- 0x%08x and PA = 0x%08x -- 0x%08x",index, temp->virt_add_low,temp->virt_add_high,temp->phy_add_low,temp->phy_add_high);
	//LOG_DEBUG("hexagon_update_vtlb_entry_in_structure Exit");
}

/* this function is related to page table and get the mask from physical page */
unsigned int get_phys_mask(unsigned int tlblo)
{
	int i = 0;
	unsigned int mask = 0;

	for (i = 0; i <= 7; i++)
	{
		mask |= (0x01 << i);

		// first set bit defines mask and page size
		if (tlblo & (0x01 << i))
		{
			return mask;
		}
	}

	return 0;
}

/* this function is related to page table and get the physical page */

unsigned int get_phys_page(unsigned int lo, unsigned int hi, unsigned int mask)
{
	// get bits [34:12] defined at [23:1]
	unsigned int pp = ((lo >> 1) & 0x7fffff);
	// add bit [35]
	if (hi & (0x01 << 29))
		pp |= 0x800000;

	// mask page size bits
	pp &= ~(mask >> 1);

	return pp;
}

/* this function update the tlb entry in global structure  gpHexagonTlbEntries */
static void hexagon_update_tlb_entry_in_structure(uint32_t tlb_phy, uint32_t tlb_virtual, uint32_t index)
{
	uint32_t mask, size = 0;
	char *page_size;
	union pg_tlblo_t tlblo;
	union pg_tlbhi_t tlbhi;

	if (index >= gHexConfig.numTlbEntries)
	{
		LOG_DEBUG("Index is greate than gHexConfig.numTlbEntries");
		return;
	}

	tlblo.raw = tlb_phy;
	tlbhi.raw = tlb_virtual;
	mask = get_phys_mask(tlb_phy);
	gpHexagonTlbEntries[index].virt_tlb_raw_data = tlb_virtual;
	gpHexagonTlbEntries[index].phys_tlb_raw_data = tlb_phy;
	//gpHexagonTlbEntries[index].phy_page = get_phys_page(tlb_phy, tlb_virtual, mask);
	gpHexagonTlbEntries[index].phy_page = QURT_getPhysAddr_v2(tlblo.raw, tlbhi.raw);
	gpHexagonTlbEntries[index].virt_page = VIRT_PAGE(tlb_virtual);
	gpHexagonTlbEntries[index].asid = ASID(tlb_virtual);
	gpHexagonTlbEntries[index].R = P_READ(tlb_phy);
	gpHexagonTlbEntries[index].W = P_WRITE(tlb_phy);
	gpHexagonTlbEntries[index].X = P_EXEC(tlb_phy);
	gpHexagonTlbEntries[index].U = P_USER(tlb_phy);
	gpHexagonTlbEntries[index].CCCC = P_CCCC(tlb_phy);
	gpHexagonTlbEntries[index].S = P_S(tlb_phy);
	gpHexagonTlbEntries[index].validbit = P_V(tlb_virtual);
	gpHexagonTlbEntries[index].globalbit = P_G(tlb_virtual);
	gpHexagonTlbEntries[index].EP = P_EP(tlb_virtual);
	gpHexagonTlbEntries[index].A1 = P_A1(tlb_virtual);
	gpHexagonTlbEntries[index].A0 = P_A0(tlb_virtual);
	page_size = PAGE_SIZE(tlb_phy, mask);

	if (strcmp(page_size, "4KB") == 0)
	{
		gpHexagonTlbEntries[index].page_size = HEXAGON_TLB_PAGE_SIZE_4KB;
		size = HEXAGON_PAGE_SIZE_16K - 1;
	}
	else if (strcmp(page_size, "16KB") == 0)
	{
		gpHexagonTlbEntries[index].page_size = HEXAGON_TLB_PAGE_SIZE_16KB;
		size = HEXAGON_PAGE_SIZE_16K - 1;
	}
	else if (strcmp(page_size, "64KB") == 0)
	{
		gpHexagonTlbEntries[index].page_size = HEXAGON_TLB_PAGE_SIZE_64KB;
		size = HEXAGON_PAGE_SIZE_64K - 1;
	}
	else if (strcmp(page_size, "256KB") == 0)
	{
		gpHexagonTlbEntries[index].page_size = HEXAGON_TLB_PAGE_SIZE_256KB;
		size = HEXAGON_PAGE_SIZE_256K - 1;
	}
	else if (strcmp(page_size, "1MB") == 0)
	{
		gpHexagonTlbEntries[index].page_size = HEXAGON_TLB_PAGE_SIZE_1MB;
		size = HEXAGON_PAGE_SIZE_1M - 1;
	}
	else if (strcmp(page_size, "4MB") == 0)
	{
		gpHexagonTlbEntries[index].page_size = HEXAGON_TLB_PAGE_SIZE_4MB;
		size = HEXAGON_PAGE_SIZE_4M - 1;
	}
	else if (strcmp(page_size, "16MB") == 0)
	{
		gpHexagonTlbEntries[index].page_size = HEXAGON_TLB_PAGE_SIZE_16MB;
		size = HEXAGON_PAGE_SIZE_16M - 1;
	}

	gpHexagonTlbEntries[index].virt_add_low = gpHexagonTlbEntries[index].virt_page << 12;
	gpHexagonTlbEntries[index].virt_add_high = gpHexagonTlbEntries[index].virt_add_low + size;

	gpHexagonTlbEntries[index].phy_add_low = gpHexagonTlbEntries[index].phy_page << 12;
	gpHexagonTlbEntries[index].phy_add_high = gpHexagonTlbEntries[index].phy_add_low + size;
}

int hexagon_read_tlb_entry(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t isdbsts, read_val[1][2];
	int retval, i = 0, k = 0;
	uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status;
	uint32_t stuff_inst[1][4] = {{0x7800c022, 0x6c42c000, 0x6700c029, 0x6701c029}};

	/*stuff inst 0x7800c022-->{r2 = #1},0x6c42c000-->{r1:0 = tlbr(r2)},0x6700c029-->{isdbmbxout = r0},0x6701c029-->{isdbmbxout = r1 } */
	uint32_t r0, r1, r2;

	LOG_DEBUG("hexagon_read_tlb_entry Enter");

	hexagon_r0_used_stuff = 1;
	hexagon_r1_used_stuff = 1;
	hexagon_r2_used_stuff = 1;

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	for (k = 0; k < gHexConfig.numTlbEntries; k++)
	{
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[0][0] + k * 0x20);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}
		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode");
			//return ERROR_FAIL;
			continue;
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[0][1]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}
		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode");
			//return ERROR_FAIL;
			continue;
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[0][2]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode for k = %d", k);
			//return ERROR_FAIL;
			continue;
		}
		while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
		{

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

			i++;
			if (i == 100)
				break;
			hexagon_wait_loop();
		}

		i = 0;
		if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
		{
			LOG_DEBUG("ISDBST status not set for mailbox for k= %d", k);
			//return ERROR_FAIL;
			continue;
		}

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &read_val[0][0]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", read_val[0][0]);
		}

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		//LOG_DEBUG("hexagon_read_tlb_entry  ISDBST status after reading MBXOUT = 0x%x", isdbsts);
		//LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", read_val[0]);

		/* procedure to read the second time mailbox resgiter*/
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[0][3]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode for k = %d", k);
			//return ERROR_FAIL;
			continue;
		}

		while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
		{

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

			i++;
			if (i == 100)
				break;
			hexagon_wait_loop();
		}
		i = 0;
		if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
		{
			LOG_DEBUG("ISDBST status not set for mailbox for k= %d", k);
			//return ERROR_FAIL;
			continue;
		}

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &read_val[0][1]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", read_val[0][1]);
		}
		hexagon_update_tlb_entry_in_structure(read_val[0][0], read_val[0][1], k);
	}
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	LOG_DEBUG("hexagon_read_tlb_entry  ISDBST status after reading MBXOUT = 0x%x", isdbsts);
	//LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", read_val[1]);
	//	#if 0
	LOG_DEBUG("Printing TLB Entries");
	for (k = 0; k < gHexConfig.numTlbEntries; k++)
	{
		/*	LOG_DEBUG("VA raw = 0x%x --> PA raw  = 0x%x ", gpHexagonTlbEntries[k].virt_tlb_raw_data,gpHexagonTlbEntries[k].phys_tlb_raw_data);
			    LOG_DEBUG("VA = 0x%x --> PA = 0x%x and page size = %d", gpHexagonTlbEntries[k].virt_page,gpHexagonTlbEntries[k].phy_page,
					gpHexagonTlbEntries[k].page_size);*/
		LOG_DEBUG("VA = 0x%08x -- 0x%08x and PA = 0x%08x -- 0x%08x", gpHexagonTlbEntries[k].virt_add_low,
				  gpHexagonTlbEntries[k].virt_add_high, (uint32_t)gpHexagonTlbEntries[k].phy_add_low, (uint32_t)gpHexagonTlbEntries[k].phy_add_high);
	}
	//#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif
	LOG_DEBUG("hexagon_read_tlb_entry Exit");
	return ERROR_OK;
}

/** Read registers of the the current context **/
int hexagon_read_current_registers(struct target *target, uint32_t hwthrd)
{

	/* read general purpose registers (R0-R1) */
	hexagon_read_gpr_registers(target, hwthrd);

	/* read per thread control registers */
	hexagon_read_ctrl_registers(target, hwthrd);

	/* read per thread monitor mode control registers */
	hexagon_read_mmode_registers(target, hwthrd);

	/* read global control registers */
	hexagon_read_global_ctrl_registers(target);

	/* Restore the register used stuff instruction */
	hexagon_restore_stuff_used_reg(target);

	LOG_DEBUG("Dumping Registers %s", target_name(target));
	//hexagon_dump_hwthrd_reg(target, 0);
	hexagon_dump_hwthrd_reg(target, gHexConfig.maxHwThreads);

	hexagon_read_tlb_entry(target);
	return ERROR_OK;
}

static int hexagon_brkpt_setup(struct hexagon_common *hexagon)
{
	int retval = ERROR_OK;

	//TDB
	return retval;
}

static void hexagon_hw_watchdog_disable(struct target *target)
{
	int retval;
	uint32_t temp;
	uint8_t buffer;

	LOG_DEBUG("hexagon_hw_watchdog_disable  enter ");

	if (debug_axi_ap == NULL)
		hexagon_initialize_axi_ap(target);

	if (debug_axi_ap == NULL)
	{
		LOG_DEBUG("debug_axi_ap not available so watchdog is not disabled ");
		return;
	}
	hexagon_enable_dbg_sys_pwr(target);
	retval = mem_ap_read_buf(debug_axi_ap, (uint8_t *)&temp, 4, 1, gHexConfig.qpss6WDOGCtl);
	if (retval != ERROR_OK)
		LOG_DEBUG("read api failed");

	LOG_DEBUG("HEXAGON_MSS_QDSP6SS_WDOG_CTL read value  = 0x%x ", temp);

	retval = mem_ap_write_atomic_u32(debug_axi_ap,
									 gHexConfig.qpss6WDOGCtl, HEXAGON_MSS_QDSP6SS_WDOG_DISABLE);

	if (retval != ERROR_OK)
		LOG_DEBUG("WDOG disabled failed");

	hexagon_wait_loop();
	retval = mem_ap_read_buf(debug_axi_ap, (uint8_t *)&temp, 4, 1, gHexConfig.qpss6WDOGCtl);
	if (retval != ERROR_OK)
		LOG_DEBUG("read api failed");

	LOG_DEBUG("HEXAGON_MSS_QDSP6SS_WDOG_CTL read value after write  = 0x%x ", temp);

#ifdef _BITRA_TARGET_
	/* g_sleepAllowLowPowerModes  write this with value 0 to disable sleep */
	buffer = 0;
	mem_ap_write_buf(debug_axi_ap, &buffer, 1, 1, 0x92EE3414);

	/* dog_hal_disable_for_bringup write this value with 1  */
	buffer = 1;
	mem_ap_write_buf(debug_axi_ap, &buffer, 1, 1, 0x9AF8F801);

	/* dog_disable_pd_grace_timer write this value with 1  */
	mem_ap_write_buf(debug_axi_ap, &buffer, 1, 1, 0x9368715A);

	/* dog_virtual_disable write this value with 1  */
	mem_ap_write_buf(debug_axi_ap, &buffer, 1, 1, 0x93687159);

	/* dog_hb_disable write this value with 1  */
	mem_ap_write_buf(debug_axi_ap, &buffer, 1, 1, 0x93687158);
#endif

	LOG_INFO("hexagon_hw_watchdog_disable  exit ");
}

static int hexagon_halt(struct target *target)
{
	if (is_hexagon_untrusted == true)
	{
		return ERROR_OK;
	}
	static uint8_t vtlb_initialized = 0;
	int retval = ERROR_OK;
	uint32_t debug_thread, prev_target_state, counter = 0, sys_cfg;
	bool halted;
	halted = debug_thread = 0;

	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	/* test code*/
	struct adiv5_dap *swddp = hexa_info->dap;

	int64_t now, then = timeval_ms();
	LOG_DEBUG("hexagon_halt");

	retval = enable_dbg_sys_pwr(swddp);
	retval = hexagon_check_state_one(target, ISDBST_DEBUG_MODE_STATUS, &halted, &debug_thread);
	if (halted == false)
	{
		retval = hexagon_init_debug_access(target);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("hexagon_init_debug_access API  failed");
			return retval;
		}
		prev_target_state = target->state;
		retval = hexagon_check_state_one(target, ISDBST_DEBUG_MODE_STATUS, &halted, &debug_thread);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("hexagon_check_state_one API  failed");
			return retval;
		}
		if (halted == true)
		{
			/* We have a halting debug event */
			target->state = TARGET_HALTED;
//enum target_debug_reason debug_reason = target->debug_reason;
#ifdef _VTLB_ENABLED_
			if (!vtlb_initialized)
			{
				hexagon_populate_vtlb_data(target);
				if (hexagon_vtlb_data.vtlb_no_of_entries > 0)
					vtlb_initialized = 1;
			}
#endif

			LOG_DEBUG("hexagon_halt  target->debug_reason =%d", target->debug_reason);
			hexagon_read_current_registers(target, gHexConfig.maxHwThreads);
			LOG_DEBUG("Target %s halted and PC 0x%x", target_name(target), hexagon_print_pc(target));

			if (retval != ERROR_OK)
				return retval;
			switch (prev_target_state)
			{
			case TARGET_RUNNING:
			case TARGET_UNKNOWN:
			case TARGET_RESET:
				target_call_event_callbacks(target, TARGET_EVENT_HALTED);
				break;
			case TARGET_DEBUG_RUNNING:
				target_call_event_callbacks(target, TARGET_EVENT_DEBUG_HALTED);
				break;
			default:
				target_call_event_callbacks(target, TARGET_EVENT_HALTED);
				break;
			}
		}
	}

	for (;;)
	{
		LOG_DEBUG("hexagon_halt foor loop enter");
		if (counter > 20)
			break;
		retval = hexagon_check_state_one(target, ISDBST_DEBUG_MODE_STATUS, &halted, &debug_thread);
		if ((retval != ERROR_OK) || (halted == true))
			break;
		//then += 50000;
		then += 1000;
		now = timeval_ms();
		if (now > then)
		{
			retval = ERROR_TARGET_TIMEOUT;
			LOG_DEBUG("target %s timeout in halt, then 0x%llx - now 0x%llx", target_name(target), then, now);
			break;
		}
		counter++;
	}

	retval = hexagon_read_syscfg_register(target);
	if (retval == ERROR_OK)
	{
		sys_cfg = hexagon_syscfg_reg;
		sys_cfg = sys_cfg | SYSCFG_L2NRA | SYSCFG_L2NWA;
		sys_cfg = sys_cfg & ~(SYSCFG_L2WB);
		//LOG_DEBUG("Writing value in SYSCFG  = 0x%x ", sys_cfg);
		hexagon_write_syscfg_register(target, sys_cfg);
	}
#ifdef _VTLB_ENABLED_
	if (vtlb_initialized > 1)
	{
		hexagon_populate_vtlb_refresh_entries(target);
	}
	else
	{
		if (hexagon_vtlb_data.vtlb_no_of_entries > 0)
			vtlb_initialized++;
	}
#endif

	return retval;
}

static int hexagon_resume(struct target *target, int current, target_addr_t address, int handle_breakpoints, int debug_execution)
{

	LOG_DEBUG("Entering, Params passed: current = %d  :  address = 0x%llx  :  handle_breakpoints = %d  :  debug_execution = %d", current, address, handle_breakpoints, debug_execution);
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval = ERROR_OK, j;
	uint32_t isdbcmd, isdbsts, isdb_cmd_status;
	static int retry_cnt = 0;

	hexagon_dump_isdb_reg(&hexagon->hexa_info);
	hexagon_read_BRKPT_through_stuff(target);

	if (target->state != TARGET_HALTED)
	{
		LOG_DEBUG("Resume is requested when target is not halted");
		return ERROR_TARGET_NOT_HALTED;
	}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif

	if (((hexa_info->brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE) >> (0)) == HEXA_DBG_SWBRKPT)
	{

		//uint32_t PC = 0;

		LOG_DEBUG("Halted reason HEXA_DBG_SWBRKPT");

		//basic sanity before proceeding

		//uint8_t pc_found_in_bp = 0;
		struct breakpoint *current_breakpoint = target->breakpoints;
		uint8_t PC_matched_with_sbp_addr = 0;
		struct reg_cache *cache = hexa_info->core_cache;
		uint8_t i = 0;

		while (current_breakpoint != NULL)
		{

			LOG_DEBUG("current_breakpoint->address = 0x%llx", current_breakpoint->address);
			LOG_DEBUG("current_breakpoint->type = 0x%x", current_breakpoint->type);
			LOG_DEBUG("current_breakpoint->is_set = 0x%x", current_breakpoint->is_set);
			LOG_DEBUG("current_breakpoint->orig_instr = 0x%hhn", current_breakpoint->orig_instr);
			LOG_DEBUG("current_breakpoint->next = 0x%u", current_breakpoint->next);
			i = 0;
			cache = hexa_info->core_cache;
			while ((cache != NULL))
			{
				LOG_DEBUG("*((uint32_t*)cache->reg_list[HEXAGON_PC].value) = 0x%x", *((uint32_t *)cache->reg_list[HEXAGON_PC].value));
				if (*((uint32_t *)cache->reg_list[HEXAGON_PC].value) == ((current_breakpoint->address) + 4))
				{
					LOG_DEBUG("breakpoint address match with PC found in the bp-list, Replacing the original instruction in place of breakpoint");
					PC_matched_with_sbp_addr = 1;
					break;
				}

				cache = cache->next;
				i++;
			}
			if (PC_matched_with_sbp_addr)
				break;

			LOG_DEBUG("Reached here");

			/*	
			if(current_breakpoint->address == PC){
				//breakpoint found in the list
				LOG_DEBUG("breakpoint found in the list, continuing resume");
				pc_found_in_bp = 1;
				break;
			}
		*/
			current_breakpoint = current_breakpoint->next;
			LOG_DEBUG("Reached here");

			if (current_breakpoint)
			{
				LOG_DEBUG("current_breakpoint->address = 0x%llx", current_breakpoint->address);
				LOG_DEBUG("current_breakpoint->type = 0x%x", current_breakpoint->type);
				LOG_DEBUG("current_breakpoint->is_set = 0x%x", current_breakpoint->is_set);
				LOG_DEBUG("current_breakpoint->orig_instr = 0x%hhn", current_breakpoint->orig_instr);
				LOG_DEBUG("current_breakpoint->next = 0x%u", current_breakpoint->next);
			}
			LOG_DEBUG("Reached here");
		}
		if (!PC_matched_with_sbp_addr)
		{
			LOG_DEBUG("breakpoint not found in the list, returning with ERROR_FAIL");
			return ERROR_FAIL;
		}
		//set PC to PC-4

		//todo: Complete this LOC
		//PC = current_breakpoint->address;
		/*
		retval = ERROR_OK;
		uint8_t PC_matched_with_sbp_addr = 0;
		struct reg_cache *cache = hexa_info->core_cache;
		uint8_t i = 0;
		while ((cache != NULL) && i < gHexConfig.maxHwThreads)
		{
			
			if(cache->reg_list[HEXAGON_PC].value == ((current_breakpoint->address)+4)){
				PC_matched_with_sbp_addr = 1;
				break;
			}
				
			cache = cache->next;
			i++;
		}
		*/

		if (!PC_matched_with_sbp_addr)
		{
			LOG_DEBUG("bCurrent HWTs PC does not match with SBP address -1, returning with ERROR_FAIL");
			return ERROR_FAIL;
		}
		retval = hexagon_write_ctrl_register(target, HEXAGON_PC, i, current_breakpoint->address);
		//Replace breakpoint instrn with original instruction
		//retval = ERROR_OK;
		//union fourbyte val;

		//val.byte[0] = current_breakpoint->orig_instr[0];
		//val.byte[1] = current_breakpoint->orig_instr[1];
		//val.byte[2] = current_breakpoint->orig_instr[2];
		//val.byte[3] = current_breakpoint->orig_instr[3];

		//retval = hexagon_memw_write_instruction_memory(target, current_breakpoint->address, val.word, 1);
		//if (retval != ERROR_OK)
		//	LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK");
		//EDIT TILL THIS POINT
		//do a step 0x11 isdbcmd
		// retval = ERROR_OK;
		if (!sbp_step_executed)
		{
			retval = hexagon_step(target, 1, 0x00, 0); //current = 1: continue on current pc, otherwise continue at <address> modified the PC so step from the current PC
		}
		if (retval != ERROR_OK)
			LOG_DEBUG("Step command failed");

		//Replace original instrn with brkpt instruction
		retval = ERROR_OK;

		retval = hexagon_memw_write_instruction_memory(target, current_breakpoint->address, 0x6c20c000, 0);
		;
		if (retval != ERROR_OK)
			LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK");
		//continue
		LOG_DEBUG("All steps are successful before continuing in case of sw BP");
	}
retry:
	//Todo: check the position of retry label, in case of very frequent breakpoints, whether it
	//		needs to be placed above the SW preakpoint preprocessing or it's current place, i.e Just before continue cmd

	retval = isdbcmd = isdbsts = isdb_cmd_status = 0;
	hexagon_stuff_reg_restore_r0_r1_r2_r7(target);

	/* Send ISDB command(Resume) to resume all halted threads*/
	isdbcmd |= ISDBCMD_CMD_RESUME;
	if (gHexConfig.maxHwThreads == 6)
		isdbcmd |= ISDBCMD_TNUM_MASK_6;
	else if (gHexConfig.maxHwThreads == 4)
		isdbcmd |= ISDBCMD_TNUM_MASK_4;

	LOG_DEBUG("Writing HEXAGON_ISDB_ISDBCMD = 0x%x, to resume target", isdbcmd);
	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdbcmd);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDCMD write failed 0x%x", isdbcmd);
		return retval;
	}
	hexagon_long_wait_loop();
	hexagon_long_wait_loop();
	hexagon_long_wait_loop();
	/*	Check ISDB status for threads entering debug mode */
	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		return retval;
	}
	LOG_DEBUG("HEXAGON_ISDB_ISDBST value after trying target resume: 0x%x", isdbsts);
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDBcommand for resume failed ");
	}
	/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
	LOG_DEBUG("HEXAGON_ISDB_ISDBCMD write successful for resume");

	uint8_t isdbst_read_retry_cnt = 0;
	while (isdbst_read_retry_cnt < 4)
	{

		if (!((isdbsts & ISDBST_DEBUG_MODE_STATUS) >> 8))
		{
			LOG_DEBUG("target resumed; ISDBST_DEBUG_MODE_STATUS is 0x%x", ((isdbsts & ISDBST_DEBUG_MODE_STATUS) >> 8));
			LOG_DEBUG("ISDBST_DEBUG_MODE_STATUS value after trying target resume: 0x%x", ((isdbsts & ISDBST_DEBUG_MODE_STATUS) >> 8));
			LOG_DEBUG("ISDBST_WAITRUN_MODE_STATUS value after trying target resume: 0x%x", ((isdbsts & ISDBST_WAITRUN_MODE_STATUS) >> 24));
			goto resumed;
		}
		retval = enable_dbg_sys_pwr(swddp);
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		isdbst_read_retry_cnt++;
	}

	LOG_DEBUG("ISDBST_DEBUG_MODE_STATUS value after trying target resume: 0x%x", ((isdbsts & ISDBST_DEBUG_MODE_STATUS) >> 8));
	LOG_DEBUG("ISDBST_WAITRUN_MODE_STATUS value after trying target resume: 0x%x", ((isdbsts & ISDBST_WAITRUN_MODE_STATUS) >> 24));

	if ((isdbsts & ISDBST_DEBUG_MODE_STATUS) >> 8)
	{
		LOG_DEBUG("Unable to resume target; ISDBST_DEBUG_MODE_STATUS is nonzero 0x%x", ((isdbsts & ISDBST_DEBUG_MODE_STATUS) >> 8));
		//handle retry here
		retry_cnt++;
		if (retry_cnt < 4)
		{
			goto retry;
		}
		LOG_DEBUG("Unable to resume target After 10 Retry");
		//hexagon_dump_isdb_reg(&hexagon->hexa_info);
		//hexagon_read_BRKPT_through_stuff(target);
		//LOG_DEBUG("hexagon_resume  target->debug_reason =%d",target->debug_reason);
		//hexagon_read_current_registers(target, HEXAGON_HW_THREAD0);
		//LOG_DEBUG("Target %s halted and PC 0x%x", target_name(target),hexagon_print_pc(target));
		return ERROR_TARGET_FAILURE;
	}
	//LOG_DEBUG("hexagon_halt  target->debug_reason =%d",target->debug_reason);
	//hexagon_read_current_registers(target, HEXAGON_HW_THREAD0);
resumed:
	LOG_DEBUG("Target %s resumed and PC 0x%x", target_name(target), hexagon_print_pc(target));
	hexagon_write_syscfg_register(target, hexagon_syscfg_reg);
	//hexagon_stuff_reg_restore_r7(target);
	hexagon_stuff_reg_restore_r0_r1_r2_r7(target);
	target->debug_reason = DBG_REASON_NOTHALTED;

	/* Wait for some time  to enable ISDB clk */
	//hexagon_wait_loop();

	if (!debug_execution)
	{
		target->state = TARGET_RUNNING;
		target_call_event_callbacks(target, TARGET_EVENT_RESUMED);
		LOG_DEBUG("target resumed at 0x%" PRIx32, hexagon_print_pc(target));
	}
	else
	{
		target->state = TARGET_DEBUG_RUNNING;
		target_call_event_callbacks(target, TARGET_EVENT_DEBUG_RESUMED);
		LOG_DEBUG("target debug resumed at 0x%" PRIx32, hexagon_print_pc(target));
	}

	LOG_DEBUG("Exiting %s\n", __FUNCTION__);
#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

	//resetting the global data structures to keep track of Business logic involved in SW BP
	/*gpSbpHaltedThreadsPC[0] = 0;
	gpSbpHaltedThreadsPC[1] = 0;
	gpSbpHaltedThreadsPC[2] = 0;
	gpSbpHaltedThreadsPC[3] = 0;
	gpSbpHaltedThreadsPC[4] = 0;
	gpSbpHaltedThreadsPC[5] = 0; */
	for (j = 0; j < gHexConfig.maxHwThreads; j++)
	{
		gpSbpHaltedThreadsPC[j] = 0;
	}

	sbp_step_executed = 0;
	return ERROR_OK;
}

static int hexagon_step(struct target *target, int current, target_addr_t address,
						int handle_breakpoints)
{
	LOG_DEBUG("Entering..");
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval = ERROR_OK;
	uint32_t isdbcmd, isdbsts, isdb_cmd_status;

	retval = isdbcmd = isdbsts = 0;

	if (target->state != TARGET_HALTED)
	{
		LOG_DEBUG("Step is requested when target is not halted");
		return ERROR_TARGET_NOT_HALTED;
	}
	hexagon_stuff_reg_restore_r0_r1_r2_r7(target);
#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_start_time_cal_ms();
#endif
	hexagon_print_pc(target);

	/* Send ISDB command(STEP) to set all thread  */
	isdbcmd |= ISDBCMD_CMD_ISTEP;
	if (gHexConfig.maxHwThreads == 6)
		isdbcmd |= ISDBCMD_TNUM_MASK_6;
	else if (gHexConfig.maxHwThreads == 4)
		isdbcmd |= ISDBCMD_TNUM_MASK_4;

	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdbcmd);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDCMD write failed 0x%x", isdbcmd);
		return retval;
	}
	/* Wait for some time  to enable ISDB clk */
	hexagon_wait_loop();

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}

	/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDB command failed returning from hexagon_step function ");
		return ERROR_FAIL;
	}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_
	hexagon_end_time_cal_ms();
	LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

	target->debug_reason = DBG_REASON_SINGLESTEP;

	//hexagon_read_current_registers(target, HEXAGON_HW_THREAD0);

	/* read general purpose registers (R0-R1) */
	hexagon_read_gpr_registers(target, gHexConfig.maxHwThreads);

	/* read per thread control registers */
	hexagon_read_ctrl_registers(target, gHexConfig.maxHwThreads);

	/* read per thread monitor mode control registers */
	hexagon_read_mmode_registers(target, gHexConfig.maxHwThreads);

	/* read global control registers */
	hexagon_read_global_ctrl_registers(target);

	/* Restore the register used stuff instruction */
	hexagon_restore_stuff_used_reg(target);

	hexagon_print_pc(target);
#ifdef _VTLB_ENABLED_
	hexagon_populate_vtlb_refresh_entries(target);
#endif

	sbp_step_executed = 1;
	return ERROR_OK;
}

static uint32_t hexagon_print_pc(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct reg_cache *cache;
	int i;

	/* dump registers for the requested HW thread */
	cache = hexa_info->core_cache;
	for (i = 0; i < gHexConfig.maxHwThreads; i++)
	{
		LOG_DEBUG("Value of PC  %s : %s = 0x%x", cache->name, cache->reg_list[HEXAGON_PC].name, *((uint32_t *)cache->reg_list[HEXAGON_PC].value));
		cache = cache->next;
	}
	cache = hexa_info->core_cache;
	/* return PC value for HW thread 0 but printing it for all HW thread*/
	return *((uint32_t *)cache->reg_list[HEXAGON_PC].value);
}

void hexagon_debug_reason(struct target *target, uint32_t brkptinfo)
{

	/* Examine debug reason */
	switch (HEXA_DEBUG_ENTRY(brkptinfo))
	{
	case HEXA_DBG_EXTBRKPT:
		target->debug_reason = DBG_REASON_DBGRQ;
		break;
	case HEXA_DBG_HWBRKPT0:
	case HEXA_DBG_HWBRKPT1:
	case HEXA_DBG_SWBRKPT:
	case HEXA_DBG_ETMBRKPT:
	case HEXA_DBG_APBBRKPT:
		target->debug_reason = DBG_REASON_BREAKPOINT;
		break;
	default:
		target->debug_reason = DBG_REASON_UNDEFINED;
		break;
	}
}

//static int hexagon_get_core_reg(struct reg *reg, int regnum, uint32_t hwthrd)
static int hexagon_get_core_reg(struct reg *reg)
{
	//struct hexa_info *hexa_info = reg->arch_info;
	struct hex_reg *arch_info = reg->arch_info;
	struct target *target = arch_info->target;
	struct hexa_info *hexa_info = arch_info->hexa_info;

	LOG_DEBUG("get_core_reg: target state %d, hw-thrd %d, reg %d",
			  target->state, arch_info->hwthrd, arch_info->num);

	if (target->state != TARGET_HALTED)
		return ERROR_TARGET_NOT_HALTED;

	return hexa_info->read_core_reg(target, reg, arch_info->num, arch_info->hwthrd);
}

static int hexagon_set_core_reg(struct reg *reg, uint8_t *buf)
{
	struct hex_reg *arch_info = reg->arch_info;
	struct target *target = arch_info->target;
	struct hexa_info *hexa_info = arch_info->hexa_info;
	uint32_t value;

	memcpy(&value, buf, 4);

	LOG_INFO("set_core_reg: target state %d, hw-thrd %d, reg %d, value 0x%x",
			 target->state, arch_info->hwthrd, arch_info->num, value);

	if (target->state != TARGET_HALTED)
		return ERROR_TARGET_NOT_HALTED;

	return hexa_info->write_core_reg(target, arch_info->num, arch_info->hwthrd, value);
}

/** Builds cache of architecturally defined registers.  */
struct reg_cache *hexagon_build_reg_cache(struct target *target, uint32_t hwthrd)
{
	struct hexagon_common *hexa_common = target_to_hexagon(target);
	struct hexa_info *hexa = &hexa_common->hexa_info;
	int num_regs;
	//int per_thread_num_regs = HEXAGON_PER_THREAD_REGS;
	//int global_num_regs = HEXAGON_GLOBAL_REGS;
	struct reg_cache **cache_p = register_get_last_cache_p(&target->reg_cache);
	struct reg_cache *cache;
	struct reg *reg_list;
	struct hex_reg *arch_info;
	struct reg_feature *feature;
	int i;

	LOG_DEBUG("Hexagon.c  hexagon_build_reg_cache enter");
	/* Build the process context cache */
	cache = malloc(sizeof(struct reg_cache));
	//cache->name = "HW-";
	//cache->next = NULL;
	//cache->reg_list = reg_list;
	//cache->num_regs = num_regs;

	if (hwthrd == gHexConfig.maxHwThreads+1)
	{
		/* Create for global regisers */
		num_regs = HEXAGON_MMODE_GLOBAL_MAX - HEXAGON_MMODE_PERTHRD_MAX;
		reg_list = calloc(num_regs, sizeof(struct reg));
		arch_info = calloc(num_regs, sizeof(struct hex_reg));
		cache->next = NULL;
		cache->reg_list = reg_list;
		cache->num_regs = num_regs;

		for (i = 0; i < num_regs; i++)
		{
			arch_info[i].num = hexagon_global_regs[i].id;
			arch_info[i].hwthrd = gHexConfig.maxHwThreads;
			arch_info[i].target = target;
			arch_info[i].hexa_info = hexa;
			arch_info[i].value[0] = 0xDE; //default value
			arch_info[i].value[1] = 0xAD; //default value

			reg_list[i].name = hexagon_global_regs[i].name;
			reg_list[i].size = hexagon_global_regs[i].bits;
			reg_list[i].value = &arch_info[i].value[0];
			reg_list[i].type = &hexagon_reg_type;
			reg_list[i].arch_info = &arch_info[i];
			reg_list[i].group = hexagon_global_regs[i].group;
			reg_list[i].number = i;
			reg_list[i].exist = true;
			reg_list[i].caller_save = true; /* gdb defaults to true */
			//reg_list[i].valid = true;

			feature = calloc(1, sizeof(struct reg_feature));
			if (feature)
			{
				feature->name = hexagon_global_regs[i].feature;
				reg_list[i].feature = feature;
			}
			else
				LOG_DEBUG("unable to allocate feature list");

			reg_list[i].reg_data_type = calloc(1, sizeof(struct reg_data_type));

			if (reg_list[i].reg_data_type)
			{
				reg_list[i].reg_data_type->type = hexagon_global_regs[i].type;
			}
			else

				LOG_DEBUG("unable to allocate reg type list");
		}

		LOG_DEBUG("Hexagon.c  hexagon_build_reg_cache global reg allocation done");
	}
	else
	{
		/** Create GPR, CTRL, Monitor Mode (per thread) registers */
		num_regs = HEXAGON_PER_THREAD_REGS;
		reg_list = calloc(num_regs, sizeof(struct reg));
		arch_info = calloc(num_regs, sizeof(struct hex_reg));
		cache->next = NULL;
		cache->reg_list = reg_list;
		cache->num_regs = num_regs;
		for (i = 0; i < num_regs; i++)
		{

			arch_info[i].num = hexagon_per_hwt_regs[i].id;
			arch_info[i].hwthrd = hwthrd;
			arch_info[i].target = target;
			arch_info[i].hexa_info = hexa;
			//arch_info[i].value[0] = 0xDEAD; //default values
			arch_info[i].value[0] = 0xDE; //default value
			arch_info[i].value[1] = 0xAD; //default value

			reg_list[i].name = hexagon_per_hwt_regs[i].name;
			reg_list[i].size = hexagon_per_hwt_regs[i].bits;
			reg_list[i].value = &arch_info[i].value[0];
			reg_list[i].type = &hexagon_reg_type;
			reg_list[i].arch_info = &arch_info[i];

			reg_list[i].group = hexagon_per_hwt_regs[i].group;
			reg_list[i].number = i;
			reg_list[i].exist = true;
			reg_list[i].caller_save = true; /* gdb defaults to true */
			//reg_list[i].valid = true;

			feature = calloc(1, sizeof(struct reg_feature));
			if (feature)
			{
				feature->name = hexagon_per_hwt_regs[i].feature;
				reg_list[i].feature = feature;
			}
			else
				LOG_DEBUG("unable to allocate feature list");

			reg_list[i].reg_data_type = calloc(1, sizeof(struct reg_data_type));

			if (reg_list[i].reg_data_type)
			{
				reg_list[i].reg_data_type->type = hexagon_per_hwt_regs[i].type;
			}
			else
				LOG_DEBUG("unable to allocate reg type list");
		}

		LOG_DEBUG("Hexagon.c  hexagon_build_reg_cache per thread allocation done");
	}

	LOG_DEBUG("Hexagon.c hexagon_build_reg_cache exit");

	(*cache_p) = cache;
	return cache;
}

struct reg *hexagon_reg_current(struct hexa_info *hexa_info, unsigned int regnum, struct reg_cache *cache)
{
	struct reg *r;

	if (regnum >= HEXAGON_MMODE_GLOBAL_MAX)
		return NULL;

	r = cache->reg_list + regnum; //TDB for all Hw threads.

	//LOG_DEBUG("reg_current:  regnum %d, cache* 0x%x r* 0x%x", regnum, cache, r);
	//LOG_DEBUG("%s : %s = 0x%x", cache->name, r->name, *((uint32_t*)r->value));

	return r;
}

int hexagon_get_gdb_reg_list(struct target *target, struct reg **reg_list[], int *reg_list_size, enum target_register_class reg_class)
{

	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct reg_cache *cache, *global;

	int i, x;

	//  LOG_DEBUG("Hexagon.c  hexagon_get_gdb_reg_list  enter");
	//LOG_INFO("Creating Hexagon register list for target %s", target_name(target));

	switch (reg_class)
	{
	case REG_CLASS_GENERAL:
		/** dump GPR of all Hw thrd */
		//*reg_list_size = HEXAGON_GPR_REGS * HEXAGON_HW_THREAD_ALL;
		*reg_list_size = HEXAGON_GPR_REGS * 2; //try with 1 hw thread.
			//LOG_INFO("hexagon_get_gdb_reg_list  reg_list_size %d size %lld", *reg_list_size, (sizeof(struct reg *) * (*reg_list_size)));

		*reg_list = malloc(sizeof(struct reg *) * (*reg_list_size));
		memset(*reg_list, 0, sizeof(struct reg *) * (*reg_list_size));
		//LOG_DEBUG("hexagon_get_gdb_reg_list  after malloc");

		/* dump GPR for all Hw thread */
		x = 0;
		cache = hexa_info->core_cache;
		while ((cache->next != NULL) && (x < *reg_list_size))
		{
			for (i = 0; i < HEXAGON_GPR_REGS; i++)
			{
				(*reg_list)[x++] = hexagon_reg_current(hexa_info, i, cache);
			}
			cache = cache->next;
		}
		// LOG_INFO("Hexagon.c  hexagon_get_gdb_reg_list  REG_CLASS_GENERAL  exit");

		return ERROR_OK;

	case REG_CLASS_ALL:

		/** dump all registers of all HW thrd */
		*reg_list_size = (HEXAGON_VALID_PER_THREAD_REGS + HEXAGON_VALID_GLOBAL_REGS) * gHexConfig.maxHwThreads;
		//LOG_INFO("hexagon_get_gdb_reg_list	reg_list_size %d, size %lld", *reg_list_size, (sizeof(struct reg *) * (*reg_list_size)));

		*reg_list = malloc(sizeof(struct reg *) * (*reg_list_size));
		memset(*reg_list, 0, sizeof(struct reg *) * (*reg_list_size));
		//LOG_DEBUG("hexagon_get_gdb_reg_list  after malloc");

		/* go to the global register node */
		global = hexa_info->core_cache;
		while (global->next != NULL)
		{
			global = global->next;
		}

		/* dump per thread + global registers for all Hw threads */
		x = 0;
		cache = hexa_info->core_cache;
		while ((cache->next != NULL) && (x < *reg_list_size))
		{
			/* reg_list[0] - reg_list[64],excluding reserved regs */
			for (i = 0; (i < HEXAGON_PER_THREAD_REGS) && (x < *reg_list_size); i++)
			{
				/* skip reserve registers */
				if ((i == HEXAGON_C5_RESRV) || (i >= HEXAGON_C20_RESRV && i <= HEXAGON_C29_RESRV) ||
					(i >= HEXAGON_S12_RESRV && i <= HEXAGON_S15_RESRV))
					continue;

				(*reg_list)[x++] = hexagon_reg_current(hexa_info, i, cache);
			}

			/* reg_list[65] - reg_list[77],excluding reserved regs */
			for (; (i < HEXAGON_MMODE_GLOBAL_MAX) && (x < *reg_list_size); i++)
			{
				/* skip reserve registers */
				if ((i == HEXAGON_S19_RESRV) || (i == HEXAGON_S24_RESRV) || (i == HEXAGON_S26_RESRV))
					continue;

				(*reg_list)[x++] = hexagon_reg_current(hexa_info, (i - HEXAGON_EVB), global);
			}

			cache = cache->next;
		}
		//    LOG_INFO("Hexagon.c  hexagon_get_gdb_reg_list REG_CLASS_ALL  exit");
		return ERROR_OK;

	default:
		LOG_DEBUG("not a valid register class type in query.");
		return ERROR_FAIL;
	}
}

static int hexagon_debug_entry(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	//struct adiv5_dap *swddp = hexa_info->dap;
	int retval = ERROR_OK, i;
	uint32_t brkptinfo = 0;
	// uint32_t thrd_src[gHexConfig.maxHwThreads];
	uint32_t *thrd_src;

	LOG_DEBUG("hexagon_debug_entry  %s", target_name(target));

	thrd_src  = (uint32_t*) malloc (gHexConfig.maxHwThreads *sizeof (uint32_t));
	if(thrd_src == NULL)
		return ERROR_FAIL;

	//retval = enable_dbg_sys_pwr(swddp);

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO, &brkptinfo);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("BRKPTINFO read failed 0x%x", brkptinfo);
		return retval;
	}

	LOG_DEBUG("TARGET_HALTED, HEXAGON_ISDB_BRKPTINFO = 0x%x \n", brkptinfo);

	/*uint32_t thrd_src[6] = 	{
									((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE)>>(0)),
									((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE)>>(3)),
									((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE)>>(6)),
									((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE)>>(9)),
									((brkptinfo & BRKPTINFO_THREAD4_BRKPT_SOURCE)>>(12)),
									((brkptinfo & BRKPTINFO_THREAD5_BRKPT_SOURCE)>>(15))
								}; */
	if (gHexConfig.maxHwThreads == 4)
	{
		thrd_src[0] = ((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE) >> (0));
		thrd_src[1] = ((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE) >> (3));
		thrd_src[2] = ((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE) >> (6));
		thrd_src[3] = ((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE) >> (9));
	}
	else if (gHexConfig.maxHwThreads == 6)
	{
		thrd_src[0] = ((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE) >> (0));
		thrd_src[1] = ((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE) >> (3));
		thrd_src[2] = ((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE) >> (6));
		thrd_src[3] = ((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE) >> (9));
		thrd_src[4] = ((brkptinfo & BRKPTINFO_THREAD4_BRKPT_SOURCE) >> (12));
		thrd_src[5] = ((brkptinfo & BRKPTINFO_THREAD5_BRKPT_SOURCE) >> (15));
	}

	for (i = 0; i < gHexConfig.maxHwThreads; i++)
	{

		LOG_DEBUG("Debug reason  thrd_src[%d]= %x", i, thrd_src[i]);

		switch (thrd_src[i])
		{

		case 0b000:
			LOG_DEBUG("Thread num %d has hit Hardware breakpoint 0\n", i);
			LOG_INFO("HW Breakpoint 0 hit");
			break;

		case 0b001:
			LOG_DEBUG("Thread num %d has hit Hardware breakpoint 1\n", i);
			LOG_INFO("HW Breakpoint 1 hit");
			break;

		case 0b010:
			LOG_DEBUG("Thread num %d has hexecuted BRKPT instruction\n", i);
			LOG_INFO("SW Breakpoint hit");
			break;

		case 0b011:
			LOG_DEBUG("Thread num %d has hit ETM Breakpoint\n", i);
			break;

		case 0b100:
			LOG_DEBUG("Thread num %d has hit APB Breakpoint\n", i);
			break;

		case 0b101:
			LOG_DEBUG("Thread num %d has External breakpoint\n", i);
			break;

		default:
			LOG_DEBUG("Default case: Thread num %d Breakpoint source = %x\n", i, thrd_src[i]);
			break;
		}
	}

	/* save the current BP info */
	hexa_info->brkptinfo = brkptinfo;

	/* Examine debug reason */
	//hexagon_debug_reason(target, brkptinfo);

	//Assuming all threads are halted for the same reason.
	hexagon_debug_reason(target, thrd_src[0]);
	free (thrd_src);

	hexagon_read_current_registers(target, gHexConfig.maxHwThreads);

	//*****************************************************//
	if (((hexa_info->brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE) >> (0)) == HEXA_DBG_SWBRKPT)
	{

		//	uint32_t PC = 0;

		LOG_DEBUG("Halted reason HEXA_DBG_SWBRKPT");

		//basic sanity before proceeding

		//uint8_t pc_found_in_bp = 0;
		struct breakpoint *current_breakpoint = target->breakpoints;
		uint8_t PC_matched_with_sbp_addr = 0;
		struct reg_cache *cache = hexa_info->core_cache;
		uint8_t i = 0;
		// while (i<6){
		// gpSbpHaltedThreadsPC[i] = *((uint32_t*)cache->reg_list[HEXAGON_PC].value);
		// i++;
		// }

		/*gpSbpHaltedThreadsPC[0] = gpPerHwThrdReg[0][HEXAGON_PC];
		gpSbpHaltedThreadsPC[1] = gpPerHwThrdReg[1][HEXAGON_PC];
		gpSbpHaltedThreadsPC[2] = gpPerHwThrdReg[2][HEXAGON_PC];
		gpSbpHaltedThreadsPC[3] = gpPerHwThrdReg[3][HEXAGON_PC];
		gpSbpHaltedThreadsPC[4] = gpPerHwThrdReg[4][HEXAGON_PC];
		gpSbpHaltedThreadsPC[5] = gpPerHwThrdReg[5][HEXAGON_PC]; */

		for (i = 0; i < gHexConfig.maxHwThreads; i++)
		{
			gpSbpHaltedThreadsPC[i] = gpPerHwThrdReg[i][HEXAGON_PC];
		}

		cache = hexa_info->core_cache;

		while (current_breakpoint != NULL)
		{

			LOG_DEBUG("current_breakpoint->address = 0x%llx", current_breakpoint->address);
			LOG_DEBUG("current_breakpoint->type = 0x%x", current_breakpoint->type);
			LOG_DEBUG("current_breakpoint->is_set = 0x%x", current_breakpoint->is_set);
			LOG_DEBUG("current_breakpoint->orig_instr = 0x%hhn", current_breakpoint->orig_instr);
			LOG_DEBUG("current_breakpoint->next = 0x%u", current_breakpoint->next);
			i = 0;
			cache = hexa_info->core_cache;
			while ((i < gHexConfig.maxHwThreads))
			{
				LOG_DEBUG("*((uint32_t*)cache->reg_list[HEXAGON_PC].value) = 0x%x", gpSbpHaltedThreadsPC[i]);
				if (gpSbpHaltedThreadsPC[i] == ((current_breakpoint->address) + 4))
				{
					LOG_DEBUG("breakpoint address match with PC found in the bp-list, Replacing the original instruction in place of breakpoint");
					PC_matched_with_sbp_addr = 1;
					break;
				}

				cache = cache->next;
				i++;
			}
			if (PC_matched_with_sbp_addr)
				break;

			//			LOG_DEBUG("Reached here" );

			/*	
			if(current_breakpoint->address == PC){
				//breakpoint found in the list
				LOG_DEBUG("breakpoint found in the list, continuing resume");
				pc_found_in_bp = 1;
				break;
			}
		*/
			current_breakpoint = current_breakpoint->next;
			LOG_DEBUG("Reached here");

			if (current_breakpoint)
			{
				LOG_DEBUG("current_breakpoint->address = 0x%llx", current_breakpoint->address);
				LOG_DEBUG("current_breakpoint->type = 0x%x", current_breakpoint->type);
				LOG_DEBUG("current_breakpoint->is_set = 0x%x", current_breakpoint->is_set);
				LOG_DEBUG("current_breakpoint->orig_instr = 0x%hhn", current_breakpoint->orig_instr);
				LOG_DEBUG("current_breakpoint->next = 0x%u", current_breakpoint->next);
			}
			LOG_DEBUG("Reached here");
		}
		if (!PC_matched_with_sbp_addr)
		{
			LOG_DEBUG("breakpoint not found in the list, returning with ERROR_FAIL");
			return ERROR_FAIL;
		}
		//set PC to PC-4
		retval = hexagon_write_ctrl_register(target, HEXAGON_PC, i, current_breakpoint->address);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("hexagon_write_ctrl_register HEXAGON_PC return value is not OK, returning with ERROR_FAIL");
			//return ERROR_FAIL;
			return ERROR_OK;
		}
		//Replace breakpoint instrn with original instruction
		retval = ERROR_OK;
		union fourbyte val;

		val.byte[0] = current_breakpoint->orig_instr[0];
		val.byte[1] = current_breakpoint->orig_instr[1];
		val.byte[2] = current_breakpoint->orig_instr[2];
		val.byte[3] = current_breakpoint->orig_instr[3];

		retval = hexagon_memw_write_instruction_memory(target, current_breakpoint->address, val.word, 1);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("Replacing original instruction, hexagon_memw_write_instruction_memory return value is not OK. Returning with ERROR_FAIL");
			return ERROR_FAIL;
		}
	}
	//*****************************************************//

	//retval = hexagon_read_current_registers(target,gHexConfig.maxHwThreads);

	//if (retval == ERROR_OK && hexagon->post_debug_entry)
	//	retval = hexagon->post_debug_entry(target);

	return ERROR_OK;
}

static int hexagon_check_state_one(struct target *target,
								   uint32_t mask, bool *halted, uint32_t *debug_thread)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;

	uint32_t isdbsts;
	int retval;
	isdbsts = 0;

	//LOG_INFO("hexagon_check_state_one");
	if (halted == NULL || debug_thread == NULL)
	{
		LOG_DEBUG(" Fail: halted 0x%x, debug_thread 0x%x", (uint32_t)*halted, *debug_thread);
		return ERROR_FAIL;
	}

	/*	Check ISDB status for threads in  debug mode */
	retval = enable_dbg_sys_pwr(swddp);

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		return retval;
	}

	if (halted)
	{
		*debug_thread = (isdbsts & mask) >> 8;
		*halted = (*debug_thread) > 0 ? true : false;
	}
	//LOG_INFO("ISDB STATUS: 0x%x, halted 0x%x, debug_thread 0x%x", isdbsts, *halted, isdbsts);
	/*
	if(!*halted)
	{
		LOG_INFO("ISDB STATUS: 0x%x, halted 0x%x, debug_thread 0x%x", isdbsts, *halted, isdbsts); 
	}*/

	return ERROR_OK;
}

static int hexagon_poll(struct target *target)
{
	if (is_hexagon_untrusted == true)
	{
		return ERROR_OK;
	}
	enum target_state prev_target_state;
	int retval = ERROR_OK;
	uint32_t debug_thread;
	bool halted = false;
	halted = debug_thread = 0;

	//LOG_INFO("hexagon_poll");

	retval = hexagon_check_state_one(target, ISDBST_DEBUG_MODE_STATUS, &halted, &debug_thread);
	//if (retval != ERROR_OK)
	//return retval;
	static int cnt = 0;
	if ((++cnt % 2000) == 0)
	{
		LOG_DEBUG("At FUNCTION:%s\t LINE:%d\n", __FUNCTION__, __LINE__);
	}

	if (halted == true)
	{
		prev_target_state = target->state;

		if ((cnt % 500) == 0)
		{
			LOG_DEBUG("At FUNCTION:%s\t LINE:%d, (halted == true)", __FUNCTION__, __LINE__);
		}

		if (prev_target_state != TARGET_HALTED)
		{
			enum target_debug_reason debug_reason = target->debug_reason;
			LOG_DEBUG("At FUNCTION:%s\t LINE:%d, prev_target_state = %d", __FUNCTION__, __LINE__, prev_target_state);
			LOG_DEBUG("At FUNCTION:%s\t LINE:%d, prev_target_state != TARGET_HALTED", __FUNCTION__, __LINE__);
			LOG_DEBUG("At FUNCTION:%s\t LINE:%d, target->debug_reason = %d", __FUNCTION__, __LINE__, debug_reason);

			/* We have a halting debug event */
			target->state = TARGET_HALTED;
			LOG_DEBUG("Target %s halted", target_name(target));

			retval = hexagon_debug_entry(target);
			if (retval != ERROR_OK)
				return retval;

			//if (target->smp)
			//hexagon_update_halt_gdb(target, debug_reason);

			switch (prev_target_state)
			{
			case TARGET_RUNNING:
			case TARGET_UNKNOWN:
			case TARGET_RESET:
				LOG_DEBUG("At FUNCTION:%s\t LINE:%d, Calling target_call_event_callbacks(target, TARGET_EVENT_HALTED)", __FUNCTION__, __LINE__);
				target_call_event_callbacks(target, TARGET_EVENT_HALTED);
				break;
			case TARGET_DEBUG_RUNNING:
				target_call_event_callbacks(target, TARGET_EVENT_DEBUG_HALTED);
				break;
			default:
				break;
			}
		}
	}
	else
	{
		target->state = TARGET_RUNNING;
	}

	return retval;
}

/*
 * Basic debug access, very low level assumes state is saved
 */
static int hexagon_init_debug_access(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;

	int retval = ERROR_OK;
	uint32_t isdbcmd, isdbsts, isdbcsts, bpinfo;

	retval = isdbcmd = isdbsts = isdbcsts = bpinfo = 0;

	LOG_DEBUG("hexagon_init_debug_access");
	LOG_INFO("%s", target_name(target));

	/*   Send ISDB command(BREAK) to set all thread into debug mode */
	//	isdbcmd |= ISDBCMD_CMD_BREAK;
	//	isdbcmd |= ISDBCMD_TNUM_MASK_6;
	if (gHexConfig.maxHwThreads == 6)
		isdbcmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_BREAK, ISDBCMD_USER_LVL, ISDBCMD_TNUM_MASK_6);
	else if (gHexConfig.maxHwThreads == 4)
		isdbcmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_BREAK, ISDBCMD_USER_LVL, ISDBCMD_TNUM_MASK_4);

	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdbcmd);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDCMD write failed 0x%x", isdbcmd);
		return retval;
	}

	/* Wait for some time  to enable ISDB clk */
	hexagon_wait_loop();

	/*	Check ISDB status for threads entering debug mode */
	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		return retval;
	}

	/* check ISDB core status - reset/PC to access ISDB*/
	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO, &bpinfo);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBEN read failed 0x%x", bpinfo);
		return retval;
	}

	//LOG_INFO("Finally: ISDBstatus 0x%x, brkpt info 0x%x ", isdbcmd, isdbsts, bpinfo);
	LOG_INFO("Finally: ISDBstatus 0x%x, brkpt info 0x%x ", isdbsts, bpinfo);
	LOG_INFO("Threads entered debug mode(ISDB status 0x%x)", isdbsts);

	target->debug_reason = DBG_REASON_DBGRQ;
	return ERROR_OK;
}

static int hexagon_handle_target_request(void *priv)
{
	struct target *target = priv;
	struct hexagon_common *hexagon = target->arch_info;
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	int retval, i;
	static int cnt = 0;

	uint32_t *thrd_src;

	thrd_src = ( uint32_t *) malloc ( gHexConfig.maxHwThreads * sizeof( uint32_t ));

	if ((++cnt % 1000) == 0)
		LOG_DEBUG("hexagon.c  hexagon_handle_target_request exam=%d dbg=%d state=%d ", target->examined, target->dbg_msg_enabled, target->state);

	if (target->state == TARGET_HALTED && ((cnt % 200) == 0))
	{

		LOG_DEBUG("TARGET_HALTED\n");
		//check the halt reason

		uint32_t brkptinfo = 0;
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO, &brkptinfo);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("Could not read brkptinfo, retval = %d", retval);
			return retval;
		}

		LOG_DEBUG("TARGET_HALTED, HEXAGON_ISDB_BRKPTINFO = 0x%x \n", brkptinfo);

		/*	uint32_t thrd_src[6] = 	{
										((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE)>>(0)),
										((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE)>>(3)),
										((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE)>>(6)),
										((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE)>>(9)),
										((brkptinfo & BRKPTINFO_THREAD4_BRKPT_SOURCE)>>(12)),
										((brkptinfo & BRKPTINFO_THREAD5_BRKPT_SOURCE)>>(15))
									}; */
		if (gHexConfig.maxHwThreads == 4)
		{
			thrd_src[0] = ((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE) >> (0));
			thrd_src[1] = ((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE) >> (3));
			thrd_src[2] = ((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE) >> (6));
			thrd_src[3] = ((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE) >> (9));
		}
		else if (gHexConfig.maxHwThreads == 6)
		{
			thrd_src[0] = ((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE) >> (0));
			thrd_src[1] = ((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE) >> (3));
			thrd_src[2] = ((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE) >> (6));
			thrd_src[3] = ((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE) >> (9));
			thrd_src[4] = ((brkptinfo & BRKPTINFO_THREAD4_BRKPT_SOURCE) >> (12));
			thrd_src[5] = ((brkptinfo & BRKPTINFO_THREAD5_BRKPT_SOURCE) >> (15));
		}

		for (i = 0; i < gHexConfig.maxHwThreads; i++)
		{

			LOG_DEBUG("Debug reason  thrd_src[%d]= %x", i, thrd_src[i]);

			switch (thrd_src[i])
			{

			case 0b000:
				LOG_DEBUG("Thread num %d has hit Hardware breakpoint 0\n", i);
				target->debug_reason = DBG_REASON_BREAKPOINT;
				break;

			case 0b001:
				LOG_DEBUG("Thread num %d has hit Hardware breakpoint 1\n", i);
				target->debug_reason = DBG_REASON_BREAKPOINT;
				break;

			case 0b010:
				LOG_DEBUG("Thread num %d has hexecuted BRKPT instruction\n", i);
				target->debug_reason = DBG_REASON_BREAKPOINT;
				break;

			case 0b011:
				LOG_DEBUG("Thread num %d has hit ETM Breakpoint\n", i);
				break;

			case 0b100:
				LOG_DEBUG("Thread num %d has hit APB Breakpoint\n", i);
				break;

			case 0b101:
				LOG_DEBUG("Thread num %d has External breakpoint\n", i);
				break;

			default:
				LOG_DEBUG("Default case: Thread num %d Breakpoint source = %x\n", i, thrd_src[i]);
				break;
			}
		}

	}

	free ( thrd_src );

	if (!target_was_examined(target))
		return ERROR_OK;
	if (!target->dbg_msg_enabled)
		return ERROR_OK;

	return ERROR_OK;
}

/* This function enable the ETM */
static uint32_t hexagon_etm_on(struct target *target)
{
	struct hexagon_common *hexagon = target->arch_info;
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t retval = ERROR_OK, tmp;


	retval = enable_dbg_sys_pwr(swddp);
	LOG_INFO("Unlocking ISDB-APB interface");
	LOG_INFO("Enabling ETM ");
	tmp = 0x3;
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, gHexConfig.etmClkenAddr, tmp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("unable to enable ETM clk 0x%x", tmp);
		return retval;
	}
	hexagon_wait_loop();
	tmp = 0x1;
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, gHexConfig.etmResetAddr, tmp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("unable to reset ETM 0x%x", tmp);
		return retval;
	}
	hexagon_wait_loop();
	tmp = 0x0;
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, gHexConfig.etmResetAddr, tmp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("APB unlock fail");
		return retval;
	}
	hexagon_wait_loop();
	LOG_INFO("After Enabling ETM ");
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap, gHexConfig.etmClkenAddr, &tmp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("unable to read ETM clk 0x%x", tmp);
		return retval;
	}
	LOG_DEBUG("ETM clk 0x%x", tmp);
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, gHexConfig.etmResetAddr, tmp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("unable to read ETM reset 0x%x", tmp);
		return retval;
	}
	LOG_DEBUG("ETM reset 0x%x", tmp);

	return retval;
}

static int hexagon_examine_first(struct target *target)
{

	struct hexagon_common *hexagon = target_to_hexagon(target);
	LOG_DEBUG("Number of bp available brp_num_available= %d", hexagon->brp_num_available);
	LOG_DEBUG("Number of bp available brp_num= %d", hexagon->brp_num);
	LOG_DEBUG("Number of bp available brp_num_context= %d", hexagon->brp_num_context);
	//Hard coding brp_num_available = 2 for now, need to find a permanent solution. *hexagon = target_to_hexagon(target); should give valid data.
	hexagon->brp_num_available = 2; //this value is constant to future ref
	hexagon->brp_num = 2;			//upon setting/removing HW breakpoint this value will be decreased/increased
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	//struct hexagon_private_config *pc;
	struct adiv5_dap *swddp = hexa_info->dap;



	int retval = ERROR_OK;
	uint32_t isdben, isdbver, isdbcstat, isdbst, corever, tmp;
	isdben = isdbver = isdbcstat = isdbst = corever = tmp = 0;
    // 1.APB-AB
	/* Search for the APB-AB - it is needed to access debug registers */
	retval = dap_find_get_ap(swddp, AP_TYPE_APB_AP, &hexa_info->debug_ap);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("Could not find APB-AP for debug access");
		return retval;
	}

	retval = enable_dbg_sys_pwr(swddp);
    // 2.memp_ap_init
	retval = mem_ap_init(hexa_info->debug_ap);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("Could not initialize the APB-AP");
		return retval;
	}

	hexa_info->debug_ap->memaccess_tck = 10;

	if (!target->dbgbase_set)
	{

		/* TDB */
		uint32_t dbgbase;
		/* Get ROM Table base */
		uint32_t apid;
		int32_t coreidx = target->coreid;

		retval = dap_get_debugbase(hexa_info->debug_ap, &dbgbase, &apid);
		if (retval != ERROR_OK)
			return retval;
		/* Lookup 0x15 -- Processor DAP */
		retval = dap_lookup_cs_component(hexa_info->debug_ap, 0x15,
										 &hexa_info->debug_base, &coreidx);
		if (retval != ERROR_OK)
			return retval;
		LOG_INFO("Detected core %" PRId32 " dbgbase: %08" PRIx32
				 " apid: %08" PRIx32,
				 coreidx, hexa_info->debug_base, apid);
	}
	else
		/** debug base = 0x0x86809000 **/
		hexa_info->debug_base = target->dbgbase;

	retval = hexagon_etm_on(target);
	if (retval != ERROR_OK)
		LOG_DEBUG("ETM enablement fail");

	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBCST, &isdbcstat);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBCST read failed 0x%x", isdbcstat);
		return retval;
	}
	LOG_DEBUG("isdbcstat  value =  0x%x", isdbcstat);
	if (isdbcstat == 4)
	{
		LOG_DEBUG("Modem Processor is in reset or power collapse, please wait until the core is active");
		// return ERROR_FAIL;
	}

	/** check ISDB version details **/
	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBVER, &isdbver);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBVER read failed 0x%x", isdbver);
		return retval;
	}
	LOG_DEBUG(" ISDBver 0x%x  ", isdbver);

	/** check core version details **/
	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_COREVER, &corever);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("COREVER read failed 0x%x", corever);
		return retval;
	}
	LOG_DEBUG(" core ver 0x%x ", corever);

	//LOG_DEBUG("After ISDBCST read 0x%x  addr=0x%x last_read=0x%x", isdbcstat, (uint32_t)&isdbcstat,*swddp->last_read);

	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBEN, &isdben);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBEN read failed 0x%x", isdben);
		return retval;
	}
	LOG_DEBUG("After ISDBEN read 0x%x ", isdben);

	/** check secure_EN, ISDB_trusted to enable APB_ISDB **/
	if (((isdben & ISDBEN_APB_ISDB_EN) != ISDBEN_APB_ISDB_EN) ||
		((isdben & ISDBEN_ISDB_PREVNT_PWRDWN) != ISDBEN_ISDB_PREVNT_PWRDWN))
	{ /** trusted, secure, clk on, apb enabl **/
		hexa_info->isdb_enable = true;
		isdben |= ISDBEN_APB_ISDB_EN;
		isdben |= ISDBEN_ISDB_PREVNT_PWRDWN;

		retval = enable_dbg_sys_pwr(swddp);
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBEN, isdben);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBEN write failed 0x%x", isdben);
			return retval;
		}
		LOG_DEBUG("After ISDBEN write  0x%x", (uint32_t)isdben);
	}
	else
	{
		LOG_DEBUG("ISDB is already enabled 0x%x", isdben);
	}

	hexagon_wait_loop();

	/** Read the ISDBEN register **/
	//LOG_INFO("Before ISDBEN read 0x%x addr=0x%x last_read=0x%x", isdben, &isdben, swddp->last_read);

	retval = enable_dbg_sys_pwr(swddp);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBEN, &isdben);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBEN read failed 0x%x", isdben);
		return retval;
	}
	LOG_DEBUG("After ISDBEN read 0x%x ", (uint32_t)isdben);

	/** check isdb status details **/
	//LOG_INFO("Before ISDB status  0x%x add=0x%x last_read=0x%x", corever, &corever, swddp->last_read);

	retval = enable_dbg_sys_pwr(swddp);

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbst);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDB status read failed 0x%x", isdbst);
		return retval;
	}
	LOG_DEBUG("After ISDB status  0x%x ", isdbst);
#if 0
	retval = mem_ap_read_buf(hexa_info->debug_ap,(uint8_t *)&tmp, 4, 1, gHexConfig.qpss6WDOGCtl);
		if(retval != ERROR_OK)
			LOG_DEBUG("read api failed"); 
		
		LOG_DEBUG("HEXAGON_MSS_QDSP6SS_WDOG_CTL read value	= 0x%x ",tmp);
		
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
					gHexConfig.qpss6WDOGCtl, HEXAGON_MSS_QDSP6SS_WDOG_DISABLE);
		
		if(retval != ERROR_OK)
			LOG_DEBUG("WDOG disabled failed"); 
			
		hexagon_wait_loop();
		retval = mem_ap_read_buf(hexa_info->debug_ap,(uint8_t *)&tmp, 4, 1, gHexConfig.qpss6WDOGCtl);
		if(retval != ERROR_OK)
			LOG_DEBUG("read api failed"); 
		
		LOG_DEBUG("HEXAGON_MSS_QDSP6SS_WDOG_CTL read value after write	= 0x%x ",tmp);
#endif

	hexagon->brp_num = 2;
	hexagon->brp_num_available = hexagon->brp_num;
	hexagon->brp_list = calloc(hexagon->brp_num, sizeof(struct hexagon_brp));
	for (int i = 0; i < hexagon->brp_num; i++)
	{
		hexagon->brp_list[i].used = 0;
		hexagon->brp_list[i].type = BRP_NORMAL;
		hexagon->brp_list[i].value = 0;
		hexagon->brp_list[i].control = 0;
		hexagon->brp_list[i].BRPn = i;
	}

	LOG_DEBUG("Configured %i hw breakpoints", hexagon->brp_num);

	hexa_info->isdb_ver = isdbver;
	hexa_info->corever = corever;
	if ((isdben == 0x0) && (isdbver == 0x0) && (corever == 0x0))
	{
		LOG_ERROR("There is problem with setup, reboot the device and try again");
		return ERROR_FAIL;
	}

	LOG_DEBUG("Finally: isdben 0x%x, isdbver 0x%x, corever 0x%x, isdbstatus 0x%x", isdben, isdbver, corever, isdbst);

	/* set up registers, breakpoint */
	retval = hexagon_reg_setup(hexagon);
	retval = hexagon_brkpt_setup(hexagon);

	target->state = TARGET_UNKNOWN;
	target->debug_reason = DBG_REASON_NOTHALTED;
	hexagon->isrmasking_mode = HEXAGON_ISRMASK_ON;
	target_set_examined(target);
	LOG_INFO("%s: examination pass\n", target_name(target));

    // hexagon_hw_watchdog_disable(target);

	//hexagon_populate_vtlb_data(target);
	return ERROR_OK;
}

static int hexagon_examine(struct target *target)
{
	int retval = ERROR_OK;
	/* hexagon untrusted flag*/

	LOG_DEBUG("hexagon_examine() ");

	/* don't re-probe hardware after each reset */
	if (!target_was_examined(target))
		retval = hexagon_examine_first(target);

	//Disabling this code as upon openocd start GDB sends hexagon-halt & part of it, hexagon_init_debug_access will be called.
	/* Configure core debug access */
	//if (retval == ERROR_OK)
	//	retval = hexagon_init_debug_access(target);

	return retval;
}

/*
 *	Hexagon target creation and initialization
 */

static int hexagon_init_target(struct command_context *cmd_ctx, struct target *target)
{
	LOG_INFO("Hexagon.c  hexagon_init_target");
	return ERROR_OK;
}

static int hexagon_init_arch_info(struct target *target,
								  struct hexagon_common *hexagon, struct adiv5_dap *dap)
{
	struct hexa_info *hexa_info = &hexagon->hexa_info;

	LOG_INFO("Hexagon.c  hexagon_init_arch_info");

	hexagon->common_magic = HEXAGON_COMMON_MAGIC; //TDB
	hexa_info->dap = dap;
	hexa_info->arch_info = hexagon;
	target->arch_info = hexagon;
	hexa_info->target = target;
    // memset(gpPerHwThrdReg, 0, sizeof(gpPerHwThrdReg));
	memset(global_reg, 0, sizeof(global_reg));

	target_register_timer_callback(hexagon_handle_target_request, 5,
								   TARGET_TIMER_TYPE_PERIODIC, target);

	return ERROR_OK;
}

static int hexagon_target_create(struct target *target, Jim_Interp *interp)
{
	struct hexagon_private_config *pc = target->private_config;
	struct hexagon_common *hexagon;

	LOG_INFO("hexagon.c  hexagon_target_create");

	if (adiv5_verify_config(&pc->adiv5_config) != ERROR_OK)
		return ERROR_FAIL;

	hexagon = calloc(1, sizeof(struct hexagon_common));
	if (hexagon == NULL)
	{
		LOG_DEBUG("Out of memory");
		return ERROR_FAIL;
	}

	return hexagon_init_arch_info(target, hexagon, pc->adiv5_config.dap);
}

static void hexagon_deinit_target(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info hexa_info = hexagon->hexa_info;
	struct reg_cache *cache, *cache1;

	free(hexagon->brp_list);
	free(target->private_config);

	cache = cache1 = hexa_info.core_cache;
	while (cache != NULL)
	{
		free(cache->reg_list->arch_info);
		free(cache->reg_list);
		cache1 = cache->next;
		free(cache);
		cache = cache1;
	}
	free(hexa_info.core_cache);
	free(hexagon);
	if (hexagon_vtlb_entries)
		free(hexagon_vtlb_entries);
    free(hexagon);
    deinitConfig(&gHexConfig);
}

static int hexagon_mmu(struct target *target, int *enabled)
{
	//uint32_t syscfg = global_reg[2];
	uint32_t syscfg, retval;

	retval = hexagon_read_syscfg_register(target);
	hexagon_stuff_reg_restore_r7(target);
	if (retval == ERROR_OK)
		syscfg = hexagon_syscfg_reg;
	else
		syscfg = global_reg[2];

	struct hexagon_mmu_common *mmu = (struct hexagon_mmu_common *)&(target_to_hexagon(target)->hexa_info.hexagon_mmu);

	if (target->state != TARGET_HALTED)
	{
		LOG_DEBUG("%s: target %s not halted", __func__, target_name(target));
		return ERROR_TARGET_INVALID;
	}
	LOG_DEBUG("SYSCFG register is  0x%x", syscfg);
	if (syscfg & 1)
		mmu->mmu_enabled = 1;
	if (syscfg & (1 << 1))
		mmu->instrution_cache_enabled = 1;
	if (syscfg & (1 << 2))
		mmu->data_cache_enabled = 1;

	*enabled = target_to_hexagon(target)->hexa_info.hexagon_mmu.mmu_enabled;
	return ERROR_OK;
}

int hexagon_arch_state(struct target *target)
{
	assert(target != NULL);
	//return target->arch_info;

	return ERROR_OK;
}

/*
 * private target configuration items
 */
enum aarch64_cfg_param
{
	CFG_CTI,
};

static const struct jim_nvp nvp_config_opts[] = {
	{.name = "-cti", .value = CFG_CTI},
	{.name = NULL, .value = -1}};

static int hexagon_jim_configure(struct target *target, struct jim_getopt_info *goi)
{
	struct hexagon_private_config *pc;
	struct jim_nvp *n;
	int e;

	LOG_INFO("hexagon_jim_configure");

	pc = (struct hexagon_private_config *)target->private_config;
	if (pc == NULL)
	{
		pc = calloc(1, sizeof(struct hexagon_private_config));
		target->private_config = pc;
	}

	/*
	 * Call adiv5_jim_configure() to parse the common DAP options
	 * It will return JIM_CONTINUE if it didn't find any known
	 * options, JIM_OK if it correctly parsed the topmost option
	 * and JIM_ERR if an error occured during parameter evaluation.
	 * For JIM_CONTINUE, we check our own params.
	 */
	e = adiv5_jim_configure(target, goi);
	if (e != JIM_CONTINUE)
		return e;

	/* parse config or cget options ... */
	if (goi->argc > 0)
	{
		Jim_SetEmptyResult(goi->interp);

		/* check first if topmost item is for us */
		e = jim_nvp_name2value_obj(goi->interp, nvp_config_opts,
								   goi->argv[0], &n);
		if (e != JIM_OK)
			return JIM_CONTINUE;

		e = jim_getopt_obj(goi, NULL);
		if (e != JIM_OK)
			return e;

		switch (n->value)
		{
		case CFG_CTI:
		{
			if (goi->isconfigure)
			{
				Jim_Obj *o_cti;
				struct arm_cti *cti;
				e = jim_getopt_obj(goi, &o_cti);
				if (e != JIM_OK)
					return e;
				cti = cti_instance_by_jim_obj(goi->interp, o_cti);
				if (cti == NULL)
				{
					Jim_SetResultString(goi->interp, "CTI name invalid!", -1);
					return JIM_ERR;
				}
				pc->cti = cti;
			}
			else
			{
				if (goi->argc != 0)
				{
					Jim_WrongNumArgs(goi->interp,
									 goi->argc, goi->argv,
									 "NO PARAMS");
					return JIM_ERR;
				}

				if (pc == NULL || pc->cti == NULL)
				{
					Jim_SetResultString(goi->interp, "CTI not configured", -1);
					return JIM_ERR;
				}
				Jim_SetResultString(goi->interp, arm_cti_name(pc->cti), -1);
			}
			break;
		}

		default:
			return JIM_CONTINUE;
		}
	}

	return JIM_OK;
}

COMMAND_HANDLER(hexagon_handle_cache_info_command)
{
	struct target *target = get_current_target(CMD_CTX);
	struct armv8_common *armv8 = target_to_armv8(target);

	return armv8_handle_cache_info_command(CMD,
										   &armv8->armv8_mmu.armv8_cache);
}

COMMAND_HANDLER(hexagon_handle_untrusted_command)
{
	struct target *target = get_current_target(CMD_CTX);
	if (!target_was_examined(target))
	{
		LOG_DEBUG("target not examined yet");
		return ERROR_FAIL;
	}
	return hexagon_untrusted_mode();
}
COMMAND_HANDLER(hexagon_handle_dbginit_command)
{
	struct target *target = get_current_target(CMD_CTX);
	if (!target_was_examined(target))
	{
		LOG_DEBUG("target not examined yet");
		return ERROR_FAIL;
	}

	return hexagon_init_debug_access(target);
}

COMMAND_HANDLER(hexagon_mask_interrupts_command)
{
	struct target *target = get_current_target(CMD_CTX);
	struct aarch64_common *aarch64 = target_to_aarch64(target);

	static const struct jim_nvp nvp_maskisr_modes[] = {
		{.name = "off", .value = AARCH64_ISRMASK_OFF},
		{.name = "on", .value = AARCH64_ISRMASK_ON},
		{.name = NULL, .value = -1},
	};
	const struct jim_nvp *n;

	if (CMD_ARGC > 0)
	{
		n = jim_nvp_name2value_simple(nvp_maskisr_modes, CMD_ARGV[0]);
		if (n->name == NULL)
		{
			LOG_DEBUG("Unknown parameter: %s - should be off or on", CMD_ARGV[0]);
			return ERROR_COMMAND_SYNTAX_ERROR;
		}

		aarch64->isrmasking_mode = n->value;
	}

	n = jim_nvp_value2name_simple(nvp_maskisr_modes, aarch64->isrmasking_mode);
	command_print(CMD, "aarch64 interrupt mask %s", n->name);

	return ERROR_OK;
}
COMMAND_HANDLER(hexagon_set_QURTK_vtlb_main_command)
{
	target_addr_t addr = 0;

	if (CMD_ARGC > 1)
		return ERROR_COMMAND_SYNTAX_ERROR;

	if (CMD_ARGC == 1)
	{
		COMMAND_PARSE_ADDRESS(CMD_ARGV[0], addr);
		hexagon_vtlb_data.QURTK_vtlb_main_VA = addr;
		command_print(CMD, " QURTK_vtlb_main = 0x%x", addr);
		LOG_INFO("QURTK_vtlb_main = 0x % x ", addr);
	}

	return ERROR_OK;
}
COMMAND_HANDLER(hexagon_set_qurtk_vtlb_data_command)
{
	target_addr_t addr = 0;

	if (CMD_ARGC > 1)
		return ERROR_COMMAND_SYNTAX_ERROR;

	if (CMD_ARGC == 1)
	{
		COMMAND_PARSE_ADDRESS(CMD_ARGV[0], addr);
		hexagon_vtlb_data.QURTK_VTLB_DATA_VA = addr;
		command_print(CMD, "QURTK_VTLB_DATA = 0x%x", addr);
		LOG_INFO("QURTK_VTLB_DATA = 0x % x ", addr);
	}

	return ERROR_OK;
}
COMMAND_HANDLER(hexagon_SetETMclkAddress)
{
    target_addr_t etm_clk_en_Addr=0;
    target_addr_t etm_clk_Res_Addr = 0;

    COMMAND_PARSE_ADDRESS(CMD_ARGV[0], etm_clk_en_Addr);
    gHexConfig.etmClkenAddr = etm_clk_en_Addr;
    command_print(CMD, " ETM clock enable address = 0x%x", gHexConfig.etmClkenAddr);
    LOG_INFO(" ETM clock enable address = 0x%x", gHexConfig.etmClkenAddr);
    COMMAND_PARSE_ADDRESS(CMD_ARGV[1], etm_clk_Res_Addr);
    gHexConfig.etmResetAddr = etm_clk_Res_Addr;
    command_print(CMD, " ETM clock Reset address = 0x%x", gHexConfig.etmResetAddr);
    LOG_INFO(" ETM clock reset address = 0x%x", gHexConfig.etmResetAddr);

    // }

    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_SetQPSS6WDOGCTL)
{
    target_addr_t WDOG = 0;

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], WDOG);
        gHexConfig.qpss6WDOGCtl = WDOG;
        command_print(CMD, " HEXAGON_QDSP6SS_WDOG_CTL = 0x%x", gHexConfig.qpss6WDOGCtl);
        LOG_INFO("HEXAGON_QDSP6SS_WDOG_CTL = 0x%x", gHexConfig.qpss6WDOGCtl);
    }

    return ERROR_OK;
}
COMMAND_HANDLER(hexagon_SetHWthreads)
{
   target_addr_t threads = 0;

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], threads);
        gHexConfig.maxHwThreads = threads;
        command_print(CMD, " HEXAGON_MAX_HW_THREADS_MODEM = %d", threads);
        LOG_INFO("HEXAGON_MAX_HW_THREADS_MODEM = %d", threads);
    }

    return ERROR_OK;
}
COMMAND_HANDLER(hexagon_SetNumTLBEntries)
{
    target_addr_t numTLB = 0;

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], numTLB);
        gHexConfig.numTlbEntries = numTLB;
        command_print(CMD, " HEXAGON_TLB_ENTRIES_NUM = %d", numTLB);
        LOG_INFO("HEXAGON_TLB_ENTRIES_NUM = %d", numTLB);
    }

    return ERROR_OK;
}
COMMAND_HANDLER(hexagon_initConfig)
{
    initConfig(&gHexConfig);
    LOG_INFO("initiating with : ");
    LOG_INFO("HEXAGON_MAX_HW_THREADS_MODEM = %d", gHexConfig.maxHwThreads);
    LOG_INFO("HEXAGON_TLB_ENTRIES_NUM = %d", gHexConfig.numTlbEntries);
    LOG_INFO("HEXAGON_QDSP6SS_WDOG_CTL = 0x%x", gHexConfig.qpss6WDOGCtl);

    return ERROR_OK;
}
// hexagon_ISDBmbx_test

COMMAND_HANDLER(hexagon_ISDBmbx_test)
{
	//isdbmbxin,value
	//stf opcode
	//stf cmd
	//isdbmbxout

	uint32_t input = 0;
	struct target *target = get_current_target(CMD_CTX);
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t isdb_mmode_cmd, isdb_cmd_status;
	uint32_t isdbsts;
	/* Stuff instruction  0x6ea8c007-->{ isdbmbxin to r7 } 0x6707c029-->{ r7 to isdbmbxout} */

	uint32_t stuff_inst[] = {0x6ea8c007, 0x6707c029};
	uint32_t retval;

	if (CMD_ARGC > 1)
		return ERROR_COMMAND_SYNTAX_ERROR;

	if (CMD_ARGC == 1)
	{
		COMMAND_PARSE_ADDRESS(CMD_ARGV[0], input);
		// command_print(CMD, " INPUT  to ISDBMBX is  = 0x%x", input);
		LOG_INFO("INPUT  to ISDBMBX  = 0x%x", input);
	}

	// struct target *target = get_current_target(CMD_CTX);
	// uint32_t input=0x101;
	uint32_t output=0;
	hexagon_untrusted_write_to_mailboxin(target, input);
	hexagon_long_wait_loop();

	isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL, ISDBCMD_TNUM_MASK_THREAD(0));

	for (int i=0; i<2; i++ )
	{
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[i]);

		if (retval != ERROR_OK)
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
			/* wait till the stuff instruction is executed */
		hexagon_long_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		// if (retval != ERROR_OK)
		LOG_DEBUG("ISDBST : 0x%x", isdbsts);
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode");
			return ERROR_FAIL;
		}
	}
	/* 0 - cmd sucessfull, 1 - failure */
	// retval = hexagon_untrusted_poll_isdbst_unset_bit(target, ISDBST_ISDB_MAILBOX_OUT);
	retval = hexagon_untrusted_read_to_mailboxout(target, &output);
	LOG_INFO("OUTPUT  from ISDBMBX is  = 0x%x", output);

	return ERROR_OK;
}

uint64_t reg_addr=0x0;
COMMAND_HANDLER(hexagon_APB_access)
{
	uint64_t reg_offset = 0,value=0;
	
	struct target *target = get_current_target(CMD_CTX);
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t retval;

	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
	if (CMD_ARGC > 2)
		return ERROR_COMMAND_SYNTAX_ERROR;

	COMMAND_PARSE_ADDRESS(CMD_ARGV[0], reg_offset);
	reg_addr = reg_offset;
	if (CMD_ARGC == 2)
	{
		COMMAND_PARSE_ADDRESS(CMD_ARGV[1], value);

		// command_print(CMD, " INPUT  to ISDBMBX is  = 0x%x", input);
		LOG_INFO("INPUT  to APB write is address  = 0x%x \t value = 0x%x", reg_addr, value);

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + reg_addr, value);
		hexagon_wait_loop();

		if (retval != ERROR_OK)
			LOG_DEBUG("APB write was unsuccessful \n");
	}
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + reg_addr, &value);
	LOG_INFO("OUTPUT  from APB read at address  = 0x%x  is value = 0x%x", reg_addr, value);

	/* wait till the stuff instruction is executed */
	hexagon_wait_loop();

	return ERROR_OK;
}
static const struct command_registration hexagon_exec_command_handlers[] = {
	{
		.name = "cache_info",
		.handler = hexagon_handle_cache_info_command,
		.mode = COMMAND_EXEC,
		.help = "display information about hexagon caches",
		.usage = "",
	},
	{
		.name = "dbginit",
		.handler = hexagon_handle_dbginit_command,
		.mode = COMMAND_EXEC,
		.help = "Initialize Hexagon debug",
		.usage = "",
	},
	/*Hexagon untrusted mode*/
	{
		.name = "untrusted",
		.handler = hexagon_handle_untrusted_command,
		.mode = COMMAND_EXEC,
		.help = "Initialize Hexagon in untrusted mode",
		.usage = "",
	},
	{
		.name = "maskisr",
		.handler = hexagon_mask_interrupts_command,
		.mode = COMMAND_ANY,
		.help = "mask hexagon interrupts during single-step",
		.usage = "['on'|'off']",
	},
	{
		.name = "SetVTLBMainAddress",
		.handler = hexagon_set_QURTK_vtlb_main_command,
		.mode = COMMAND_ANY,
		.help = "Return vtlb main address from the elf file",
		.usage = "[address]",
	},
	{
		.name = "SetVTLBDataAddress",
		.handler = hexagon_set_qurtk_vtlb_data_command,
		.mode = COMMAND_ANY,
		.help = "Return vtlb data address from the elf file",
		.usage = "[address] [address]",
	},
	{
		.name = "SetMaxHWThreads",
		.handler = hexagon_SetHWthreads,
		.mode = COMMAND_ANY,
		.help = "Set the maximum number of hardware threads",
		.usage = "[Number]",
	},
	{
		.name = "SetNumTLBEntries",
		.handler = hexagon_SetNumTLBEntries,
		.mode = COMMAND_ANY,
		.help = "Set Number of TLB Entries",
		.usage = "[Number]",
	},
	{
		.name = "SetEtmClkAddress",
		.handler = hexagon_SetETMclkAddress,
		.mode = COMMAND_ANY,
		.help = "Set ETM addresses",
		.usage = "[address]",
	},
	{
		.name = "initConfig",
		.handler = hexagon_initConfig,
		.mode = COMMAND_ANY,
		.help = "Return vtlb data address from the elf file",
		.usage = "[address]",

	},
	{
		.name = "SetWDOGCTL",
		.handler = hexagon_SetQPSS6WDOGCTL,
		.mode = COMMAND_ANY,
		.help = "Set Watchdog Control address",
		.usage = "[address]",
	},
	{
		.name = "mailbox",
		.handler = hexagon_ISDBmbx_test,
		.mode = COMMAND_ANY,
		.help = "test the ISDB mbx implementation",
		.usage = "[address]",
	},
	{
		.name = "APB",
		.handler = hexagon_APB_access,
		.mode = COMMAND_ANY,
		.help = "read/write via APB\n without value this command performs a read",
		.usage = "[address] [value]",
	},
	{
		.chain = smp_command_handlers,
	},

	COMMAND_REGISTRATION_DONE};

extern const struct command_registration semihosting_common_handlers[];

static const struct command_registration hexagon_command_handlers[] = {
	{
		.name = "hexagon",
		.mode = COMMAND_ANY,
		.help = "hexagon command group",
		.usage = "command <> <>",
		.chain = hexagon_exec_command_handlers,
	},
	COMMAND_REGISTRATION_DONE};

const char *hexagon_get_gdb_arch(struct target *target)
{
	return "Hexagon";
}

static int hexagon_execute_Isync(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;

	int retval, i = 0, j, loop, x, nreg;
	uint32_t stuff_inst = 0x57c0c002; //hello[0x60e4] <+4>:    0x57c0c002  {    isync }

	uint32_t isdbsts, size = 0;
	uint32_t isdb_mmode_cmd = 0x184, isdb_umode_cmd = 0x104, isdb_gmode_cmd = 0x144, isdb_cmd_status;

	/*there are 2 stuff instruction, here programming first inst */
	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
	}

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst = 0x57c0c002");
	}
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD & isdb_mmode_cmd return value is not OK for stuff_inst = 0x57c0c002");
	}

	/* wait till the stuff instruction is executed */
	hexagon_wait_loop();

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
	}

	LOG_DEBUG("ISDBST read status after stuff_inst = 0x57c0c002, 0x%x", isdbsts);
	/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDBcommand failed in monitor  mode");
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst = 0x57c0c002");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_umode_cmd return value is not OK for stuff_inst = 0x57c0c002");
		}
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}
		LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in user mode");
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst = 0x57c0c002");
			}
			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_gmode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_umode_cmd return value is not OK for stuff_inst = 0x57c0c002");
			}
			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}
			LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
			/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in Guest mode");
				return ERROR_OK;
			}
		}
	}
}

static int hexagon_setup_isdb_config(struct target *target, uint32_t old_isdbcfg0, uint8_t hbp_num)
{

	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	int32_t isdbcfg0 = old_isdbcfg0, result = 0, retval = ERROR_OK;

	isdbcfg0 |= 0x3f3f3f;
	if (hbp_num == 0)
	{
		isdbcfg0 |= (1 << 25); //HW BP0 enable
	}
	else if (hbp_num == 1)
	{
		isdbcfg0 |= (1 << 26); //HW BP1 enable
	}

	LOG_DEBUG("Writing isdbcfg0...	 isdbcfg0 = 0x%x", isdbcfg0);

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCFG0, isdbcfg0);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBCFG0 write failed 0x%x", isdbcfg0);
		return retval;
	}

	//disabling these lines as T32+EUD HBP logs dowsn't do any write on isdbcfg1, Can enable later.

	int32_t isdbcfg1 = 0;
	retval = ERROR_OK;

	isdbcfg1 |= 0x3F3F3F00; //HW break0 & break1 TNUM mask SW Break TNUM Mask

	LOG_DEBUG("Writing isdbcfg1...	 isdbcfg1 = 0x%x", isdbcfg1);
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCFG1, isdbcfg1);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBCFG1 write failed 0x%x", isdbcfg1);
		return retval;
	}

	LOG_DEBUG("Write sccessful for HEXAGON_ISDB_ISDBCFG0 & HEXAGON_ISDB_ISDBCFG1");
	return ERROR_OK;
}

static int hexagon_read_BRKPT_through_stuff(struct target *target)
{
	LOG_DEBUG("%s ------ %d\n", __FUNCTION__, __LINE__);
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;

	int retval, i = 0, loop, x, nreg;
	uint32_t stuff_inst[][4] = {{0x6ea4c007, 0x6707c029},
								{0x6ea6c007, 0x6707c029},
								{0x6ea5c007, 0x6707c029},
								{0x6ea7c007, 0x6707c029}}; //r7=PC0,PC1,CFG0,CFG1; isdbmbxout = r7;

	uint32_t isdbsts, size = 0, read_val[4] = {};
	uint32_t isdb_mmode_cmd = 0x184, isdb_umode_cmd = 0x104, isdb_gmode_cmd = 0x144, isdb_cmd_status;

	/*there are 2 stuff instruction, here programming first inst */
	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
	}

	for (int j = 0; j < 4; j++)
	{
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}
		/*there are 2 stuff instruction, here programming first inst */

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[j][0]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst[j][0],j=%d", j);
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK for stuff_inst[j][0],j=%d", j);
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}

		LOG_DEBUG("ISDBST read status after first stuff inst j = %d, 0x%x", j, isdbsts);
		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor  mode");
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[j][0]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst[j][0],j=%d", j);
			}
			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_umode_cmd return value is not OK for stuff_inst[j][0],j=%d", j);
			}
			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}
			LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
			/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in user mode");
				retval = enable_dbg_sys_pwr(swddp);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[j][0]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
				}
				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_gmode_cmd);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_gmode_cmd return value is not OK");
				}
				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
				}
				LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
				/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
				isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
				if (isdb_cmd_status)
				{
					LOG_DEBUG("ISDBcommand failed in Guest mode");
					return ERROR_OK;
				}
			}
		}

		/*there are 2 stuff instruction, here programming second inst */
		retval = enable_dbg_sys_pwr(swddp);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
		}

		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[j][1]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
		}
		retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
										 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		}

		/* wait till the stuff instruction is executed */
		hexagon_wait_loop();

		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		}
		LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
		/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
		isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
		if (isdb_cmd_status)
		{
			LOG_DEBUG("ISDBcommand failed in monitor mode");
			retval = enable_dbg_sys_pwr(swddp);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
			}

			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[j][1]);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
			}
			retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
											 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_umode_cmd);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_umode_cmd return value is not OK");
			}

			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();

			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			if (retval != ERROR_OK)
			{
				LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
			}
			LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
			/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
			isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

			if (isdb_cmd_status)
			{
				LOG_DEBUG("ISDBcommand failed in user  mode");
				retval = enable_dbg_sys_pwr(swddp);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
				}

				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst[j][1]);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
				}
				retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
												 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_gmode_cmd);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_gmode_cmd return value is not OK");
				}

				/* wait till the stuff instruction is executed */
				hexagon_wait_loop();

				retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
												hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
				if (retval != ERROR_OK)
				{
					LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
				}
				LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
				/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
				isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
				if (isdb_cmd_status)
				{
					LOG_DEBUG("ISDBcommand failed in Guest  mode");
					return ERROR_OK;
				}
			}
		}

		/*reading mailboxout status in ISDBST register */
		while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
		{
			retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
											hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
			/* wait till the stuff instruction is executed */
			hexagon_wait_loop();
			i++;
			if (i == 100)
				break;
		}
		LOG_DEBUG("ISDBST status value before  reading mailbox register 0x%x, i = %d", isdbsts, i);
		i = 0;
		if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT))
		{
			LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for iteration %d", j);
			continue;
		}
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &read_val[j]);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", read_val[j]);
		}
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", read_val[j]);
		LOG_DEBUG("ISDBST status value after  reading mailbox register 0x%x ", isdbsts);
	}

	return ERROR_OK;
}
/*================================================================*/
/*hexagon-untrusted code changes*/
/*================================================================*/

process_pd process_list[4];
uint16_t total_process = 0;
int selected_process = -1;
/* function hexagon_untrusted_update_packet
 *args:
 *	packet : character pointer pointin to the string of the RSP packet
 *	len : length of the packet
 */
int hexagon_untrusted_update_packet(char *packet, int len)
{
	int retval;
	if (packet == NULL)
		return ERROR_FAIL;
	// Adding initial $ to each RSP packet
	hexagon_untrusted_current_state.current_packet[0] = '$';
	for (int i = 1; i <= len; i++)
	{
		hexagon_untrusted_current_state.current_packet[i] = packet[i - 1];
	}
	hexagon_untrusted_current_state.packet_len = len + 1;
	// Updating the end of the string in the RSP packet
	hexagon_untrusted_current_state.current_packet[len + 1] = '\0';
	hexagon_untrusted_current_state.has_packet = true;
	if (hexagon_untrusted_current_state.has_checksum)
	{
		retval = hexagon_untrusted_concat_rsp();
		if (retval != ERROR_OK)
			return retval;
	}
	// LOG_INFO("Hexagon untrusted RSP packet : %s\n",hexagon_untrusted_current_state.current_packet);
	return ERROR_OK;
}

/* function hexagon_untrusted_update_packet_checksum
 * args:
 * checksum : it contains the checksum recieved on GDB connection
 *			 for the RSP packet.
 */
int hexagon_untrusted_update_packet_checksum(char *checksum)
{
	int retval;
	// LOG_INFO("Hexagon untrusted RSP packet checksum entered\n");

	hexagon_untrusted_current_state.current_checksum[0] = checksum[0];
	hexagon_untrusted_current_state.current_checksum[1] = checksum[1];
	hexagon_untrusted_current_state.has_checksum = true;
	if (hexagon_untrusted_current_state.has_packet)
	{
		retval = hexagon_untrusted_concat_rsp();
	}
	// LOG_INFO("Hexagon untrusted RSP packet checksum  exit: %c%c\n",checksum[0],checksum[1]);
	return ERROR_OK;
}
/* function hexagon_untrusted_concat_rsp
 * This function will concatinate the packet and Checksum
 *	packet after this function will look like in this format
 *	$<packet>#<checksum>
 */
static int hexagon_untrusted_concat_rsp()
{
	// LOG_DEBUG("Hexagon untrusted concatinated the RSP entered\n");

	if (!(hexagon_untrusted_current_state.has_checksum &&
		  hexagon_untrusted_current_state.has_packet))
	{
		LOG_DEBUG("Hexagon untrusted RSP packet or checksum not available\n");
		return ERROR_FAIL;
	}
	int len = hexagon_untrusted_current_state.packet_len;
	hexagon_untrusted_current_state.current_packet[len] = '#';

	hexagon_untrusted_current_state.current_packet[len + 1] =
		hexagon_untrusted_current_state.current_checksum[0];
	hexagon_untrusted_current_state.current_packet[len + 2] =
		hexagon_untrusted_current_state.current_checksum[1];
	hexagon_untrusted_current_state.current_packet[len + 3] = '\0';

	hexagon_untrusted_current_state.packet_len = len + 3;
	hexagon_untrusted_current_state.has_packet = false;
	hexagon_untrusted_current_state.has_checksum = false;
	hexagon_untrusted_current_state.has_rsp = true;
	// LOG_DEBUG("Hexagon untrusted concatinated the RSP : %s\n",
	//						hexagon_untrusted_current_state.current_packet);

	return ERROR_OK;
}

/* function hexagon_untrusted_write_to_mailboxin
 * writes the 32bit value to the mailboxin register
 * args:
 * target : target variable for accessing the connected target
 * val : value which need to written on the register
 */
static int hexagon_untrusted_write_to_mailboxin(struct target *target, uint32_t value)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;

	int retval, i = 0;
	uint32_t isdbst_after = 0x0;
	uint32_t isdbsts = 0x0;
	uint32_t isdbmbx = 0x0;

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

	// retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
	// 								hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, &isdbmbx);

	// LOG_INFO("ISDBMBX before write to mailbox : 0x%x", isdbmbx);
	LOG_DEBUG("ISDBSTS before write to mailbox : 0x%x", isdbsts);

	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);

	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
		return retval;
	}

	// retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
	// 								hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, &isdbmbx);

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbst_after);

	// LOG_INFO("ISDBMBX after write to mailbox : 0x%x", isdbmbx);
	LOG_DEBUG("ISDBSTS after write to mailbox : 0x%x", isdbst_after);

	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbst_after);
		return retval;
	}
	retval = send_isdb_interrupt(target);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("Unable to Interrupt!\n");
		return retval;
	}
	return ERROR_OK;
}

/*function hexagon_untrusted_read_to_mailboxout
 * this function will write the 32bit value to the ISDBMAILBOXOUT register
 * args
 * target : target variable to access the connected target
 * value :  value to be written to the register
 */
static int hexagon_untrusted_read_to_mailboxout(struct target *target, uint32_t *value)
{

	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	int retval, i = 0;
	uint32_t isdbsts;

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

	LOG_DEBUG("ISDBSTS before read from mailboxout : 0x%x", isdbsts);

	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, value);
	// LOG_INFO("VALUE : 0x%x", value);

	if (retval != ERROR_OK)
	{
		LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", *value);
		return retval;
	}
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

	LOG_DEBUG("ISDBSTS after read from mailboxout : 0x%x", isdbsts);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
		return retval;
	}
	retval = send_isdb_interrupt(target);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("Unable to Interrupt!\n");
		return retval;
	}
	return ERROR_OK;
}

/*function hexagon_untrusted_convert_essential_header
 * convert the essential header information to the 32bit integer
 * args
 * header: essential header structure containing the info
 */
static uint32_t hexagon_untrusted_convert_essential_header(untrusted_essential header)
{
	uint32_t value = 0x0;
	value = ((((value|=header.payload_len) << 8)| header.header_len) << 8) | header.protocol;
	
	// value |= header.payload_len;
	// // LOG_DEBUG("Header payload is %u\n",header.payload_len);
	// value = value << 8;
	// value |= header.header_len;
	// value = value << 8;
	// value |= header.protocol;
	// // LOG_DEBUG("Converted essential header is %u\n",value);
	return value;
}

/*function hexagon_untrusted_convert_to_essential_header
 * convert 32bit integer to the essential header information
 * args
 * val : 32bit value to convert
 * header: essential header structure pointer to store result
 */
static int hexagon_untrusted_convert_to_essential_header(uint32_t val, untrusted_essential *header)
{
	// LOG_DEBUG("value before conversion is %u\n",val);
	header->protocol = (uint8_t)(val & 0xff);
	val >>= 8;
	header->header_len = (uint8_t)(val & 0xff);
	val >>= 8;
	header->payload_len = (uint16_t)(val & 0xffff);
	return ERROR_OK;
}
/* function
 */
static int hexagon_untrusted_poll_isdbst_set_bit(struct target *target, uint8_t bit)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	uint32_t isdbsts, check_bit = 0x1;
	int retval;
	while (check_bit > 0)
	{
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("Unable to read ISDBST register.\n");
			return retval;
		}
		check_bit = isdbsts & bit;
	}
	return ERROR_OK;
}

/* function
 */
static int hexagon_untrusted_poll_isdbst_unset_bit(struct target *target, uint8_t bit)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t isdbsts, check_bit = 0x0;
	int retval;
	while (check_bit == 0)
	{
		retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
										hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
		if (retval != ERROR_OK)
		{
			LOG_ERROR("Unable to read ISDBST register.\n");
			return retval;
		}
		check_bit = isdbsts & bit;
	}
	return ERROR_OK;
}
/* function

*/
static uint32_t min_u(uint32_t a, uint32_t b)
{
	if (a > b)
		return b;
	return a;
}
/*function
 */
static int send_isdb_interrupt(struct target *target)
{
	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	uint32_t isdb_mmode_cmd = ISDBCMD_CMD_INTRPT | ISDBCMD_MONITOR_LVL;
	uint32_t isdb_cmd_status, isdbsts;
	int retval;
	retval = enable_dbg_sys_pwr(swddp);
	if (retval != ERROR_OK)
		LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
									 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
	if (retval != ERROR_OK)
		LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
	if (retval != ERROR_OK)
		LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

	/* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
	isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
	if (isdb_cmd_status)
	{
		LOG_DEBUG("ISDBcommand failed to interrupt");
		return ERROR_FAIL;
	}
	LOG_DEBUG("Raised Interrupt successfully!\n");
	// hexagon_long_wait_loop();
	return ERROR_OK;
}

/*function
 */
int hexagon_untrusted_listen_for_rsp(struct target *target, char *s, uint16_t *res_len)
{
	int retval, i = 0;
	uint32_t read_val;
	uint32_t calculated_checksum = 0;
	untrusted_essential *header;
	uint32_t mbxOutVal=0;

	struct hexagon_common *hexagon = target_to_hexagon(target);
	struct hexa_info *hexa_info = &hexagon->hexa_info;

	/* Read the essential header */
	LOG_DEBUG("Reading the essential header...\n");
	// retval = hexagon_untrusted_poll_isdbst_unset_bit(target, ISDBST_ISDB_MAILBOX_OUT);
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + ISDBST_ISDB_MAILBOX_OUT, &mbxOutVal);

	LOG_DEBUG("Mailbox out value is :0x%x\n",mbxOutVal);

	retval = hexagon_untrusted_read_to_mailboxout(target, &read_val);
	calculated_checksum += (read_val & 0xff) + ((read_val >> 8) & 0xff) + ((read_val >> 16) & 0xff) + ((read_val >> 24) & 0xff);
	
	retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
									hexa_info->debug_base + ISDBST_ISDB_MAILBOX_OUT, &mbxOutVal);

	LOG_DEBUG("Mailbox out value is :0x%x\n", mbxOutVal);
	LOG_DEBUG("Successfully read the essential header!\n");
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("Error in reading the ISDBMailboxout register\n");
		return retval;
	}
	header = (untrusted_essential *)malloc(sizeof(untrusted_essential));

	retval = hexagon_untrusted_convert_to_essential_header(read_val, header);
	
	/* Read process ID */
	if (header->header_len >= 8)
	{
		retval = hexagon_untrusted_poll_isdbst_unset_bit(target, ISDBST_ISDB_MAILBOX_OUT);
		retval = hexagon_untrusted_read_to_mailboxout(target, &read_val);
		calculated_checksum += (read_val & 0xff) + ((read_val >> 8) & 0xff) + ((read_val >> 16) & 0xff) + ((read_val >> 24) & 0xff);
		LOG_DEBUG("Successfully read the process id header!\n");
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("Error in reading the ISDBMailboxout register\n");
			return retval;
		}
		if(selected_process != read_val){
			LOG_DEBUG("Process id is not same!\n");
			return ERROR_FAIL;
		}
	}

	uint16_t len = (header->payload_len / ISDBMAILBOX_SIZE);
	if ((header->payload_len % ISDBMAILBOX_SIZE) != 0)
	{
		len += 1;
	}
	char *rsp_packet;
	uint16_t current = 0;
	rsp_packet = (char *)malloc(sizeof(char) * header->payload_len);

	for (i = 0; i < len; i++)
	{

		retval = hexagon_untrusted_poll_isdbst_unset_bit(target, ISDBST_ISDB_MAILBOX_OUT);
		retval = hexagon_untrusted_read_to_mailboxout(target, &read_val);
		calculated_checksum += (read_val & 0xff) + ((read_val >> 8) & 0xff) + ((read_val >> 16) & 0xff) + ((read_val >> 24) & 0xff);
		for (int j = 0; j < 4; j++)
		{
			char c = (char)(read_val & 0xff);
			rsp_packet[current] = c;
			read_val >>= 8;
			current++;
		}
	}

	calculated_checksum = calculated_checksum % 256;
	retval = hexagon_untrusted_poll_isdbst_unset_bit(target, ISDBST_ISDB_MAILBOX_OUT);
	retval = hexagon_untrusted_read_to_mailboxout(target, &read_val);
	if (read_val != calculated_checksum)
	{
		LOG_DEBUG("Error in reading. Checksum don't match!!!\n");
		return -1;
	}

	*res_len = header->payload_len;
	memcpy(s, rsp_packet, *res_len);

	free(rsp_packet);
	return ERROR_OK;
}

static int hexagon_untrusted_send_rsp(struct target *target, char *rsppkt, uint16_t len, char *response, uint16_t *response_len, int header_len)
{
	untrusted_payload *payload;
	untrusted_essential *essential_header;
	uint32_t val;
	uint16_t number_of_payload_packets = len / ISDBMAILBOX_SIZE;
	uint32_t pid_s;
	uint32_t rsp_v;
	int retval;
	uint32_t write_value;
	uint32_t buffer, stride;
	uint32_t cha;
	int i = 0, p = 0;
	uint32_t calculated_checksum = 0;

	if (len % ISDBMAILBOX_SIZE != 0)
	{
		number_of_payload_packets += 1;
	}

	essential_header = (untrusted_essential *)malloc(sizeof(untrusted_essential));
	if (essential_header == NULL)
	{
		LOG_DEBUG("Insufficient memory\n");
		return ERROR_FAIL;
	}

	payload = (untrusted_payload *)malloc(sizeof(untrusted_payload));
	if (payload == NULL)
	{
		LOG_DEBUG("Insufficient memory\n");
		return ERROR_FAIL;
	}
	// Initializing the payload data structure
	payload->len = number_of_payload_packets;
	payload->bytes_to_read = len;
	payload->payload = (uint32_t *)malloc(sizeof(uint32_t) * number_of_payload_packets);
	
	while (i < payload->bytes_to_read)
	{
		stride = min_u(ISDBMAILBOX_SIZE, payload->bytes_to_read - i);
		buffer = 0x0;
		for (int j = 0; j < stride; j++)
		{
			cha = (uint32_t)rsppkt[i + j];
			buffer |= (cha << (8 * j));
		}
		i += ISDBMAILBOX_SIZE;
		payload->payload[p++] = buffer;
	}
	essential_header->protocol = UNTRUSTED_PROTOCOL_VERSION;
	if (header_len == -1)
	{
		essential_header->header_len = 12;
		pid_s = 0xFFFFFFFF;
		rsp_v = RSPVERSION;
	}
	else
	{
		essential_header->header_len = 8;
		pid_s = selected_process;
	}
	essential_header->payload_len = payload->bytes_to_read;
	/*Sending the essential header to the ISDBMBXIN*/
	// waiting if already content there
	// retval=hexagon_untrusted_poll_isdbst_set_bit(target,0x2);
	write_value = hexagon_untrusted_convert_essential_header(*(essential_header));
	retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);
	retval = hexagon_untrusted_write_to_mailboxin(target, write_value);
	calculated_checksum += (write_value & 0xff) + ((write_value >> 8) & 0xff) + ((write_value >> 16) & 0xff) + ((write_value >> 24) & 0xff);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("Unable to send packet on the ISDBMBXIN channel\n");
		return retval;
	}

	retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);
	retval = hexagon_untrusted_write_to_mailboxin(target, pid_s);
	calculated_checksum += (pid_s & 0xff) + ((pid_s >> 8) & 0xff) + ((pid_s >> 16) & 0xff) + ((pid_s >> 24) & 0xff);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("Unable to send packet on the ISDBMBXIN channel\n");
		return retval;
	}

	if (essential_header->header_len == 12)
	{
		retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);
		retval = hexagon_untrusted_write_to_mailboxin(target, rsp_v);
		calculated_checksum += (rsp_v & 0xff) + ((rsp_v >> 8) & 0xff) + ((rsp_v >> 16) & 0xff) + ((rsp_v >> 24) & 0xff);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("Unable to send packet on the ISDBMBXIN channel\n");
			return retval;
		}
	}

	
	/*Sending the RSP packet as the payload*/
	for (int i = 0; i < payload->len; i++)
	{
		write_value = payload->payload[i];
		retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);
		retval = hexagon_untrusted_write_to_mailboxin(target, write_value);
		calculated_checksum += (write_value & 0xff) + ((write_value >> 8) & 0xff) + ((write_value >> 16) & 0xff) + ((write_value >> 24) & 0xff);
		// hexagon_wait_loop();
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("Unable to send packet on the ISDBMBXIN channel\n");
			return retval;
		}
	}

	/* Sending checksum value */
	calculated_checksum = calculated_checksum % 256;
	retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);
	retval = hexagon_untrusted_write_to_mailboxin(target, calculated_checksum);
	if (retval != ERROR_OK)
	{
		LOG_DEBUG("Unable to send checksum packet on the ISDBMBXIN channel\n");
		return retval;
	}

	free(payload->payload);
	free(payload);
	free(essential_header);

	LOG_DEBUG("Listening for the RSP...\n");
	retval = hexagon_untrusted_listen_for_rsp(target, response, response_len);

	return ERROR_OK;
}

static int convert_to_int(char *s)
{
	int len = strlen(s);
	int index = -1;
	for (int i = 0; i < len; i++)
	{
		if (s[i] != '0')
		{
			index = i;
			break;
		}
	}
	if (index == -1)
		return 0;
	return strtoul(s + index, NULL, 10);
}
static int load_process_list(char *process_list_response)
{
	char *ret;
	int c_pid = 0;
	char *pid_index;
	char *comma_index;
	char *scolon_index;
	char p[16];
	int pname_index = 0;
	int spid;
	selected_process = -1;
	int r=0x0;
	char line[256];
	char *token = strtok(process_list_response, ";");
	while (token != NULL)
	{
		ret = strstr(token, "pid");
		if (ret)
		{
			pid_index = strchr(token, ':');
			comma_index = strchr(token, ',');
			r = strlen(pid_index) - 1 - strlen(comma_index);
			memcpy(p, pid_index + 1, r);
			p[r] = '\0';
			process_list[total_process].pid = convert_to_int(p);
			scolon_index = strchr(comma_index, ':');
			r = strlen(scolon_index) - 1;
			memcpy(process_list[total_process].process_name, scolon_index + 1, r);
			process_list[total_process].process_name[r] = '\0';
			total_process++;
		}
		token = strtok(NULL, ";");
	}
	printf("====================Process Selection Menu====================\n");
	printf("\tProcess Id\tProcess Name\n");

	for (int i = 0; i < total_process; i++)
	{
		printf("\t%u\t\t%s\n", process_list[i].pid, process_list[i].process_name);
	}
	printf("Enter the process ID to debug: \n");
	if (fgets(line, sizeof(line), stdin))
	{
		if (1 == sscanf(line, "%d", &spid))
		{
			for (int i = 0; i < total_process; i++)
			{
				if (process_list[i].pid == spid)
				{
					selected_process = spid;
					printf("Selected process to debug is : %s\n", process_list[i].process_name);
					break;
				}
			}
		}
	}

	if (selected_process == -1)
	{
		printf("\nError: No process is selected for debugging!\n");
		return ERROR_FAIL;
	}
	return ERROR_OK;
}
/* function

*/
int hexagon_untrusted_forward_rsp(struct target *target, char *response, uint16_t *response_len)
{
	int retval;
	uint16_t len;
	if (!hexagon_untrusted_current_state.has_rsp)
	{
		LOG_DEBUG("RSP packet is not available to forward\n");
		return ERROR_FAIL;
	}
	if (strncmp(hexagon_untrusted_current_state.current_packet, "$QStartNoAckMode", 16) == 0)
	{
		char s[256];
		uint16_t res_len = 0x0;
		
		retval = hexagon_untrusted_send_rsp(target, "$qProcessList#ec", 17, s, &res_len, -1);
		if (retval != ERROR_OK)
		{
			LOG_DEBUG("Not able to send initial process packet!\n");
			return retval;
		}

		LOG_DEBUG("Response recieved from qprocesslist is:  %s and the length is:  %u\n", s, res_len);
		retval = load_process_list(s);
		for (int i = 0; i < total_process; i++)
		{
			if (hexagon_debug_process_id == process_list[i].pid)
			{
				LOG_DEBUG("Process ID to debug is : %d\n", process_list[i].pid);
				break;
			}
		}
	}
	len = hexagon_untrusted_current_state.packet_len;
	retval = hexagon_untrusted_send_rsp(target, &(hexagon_untrusted_current_state.current_packet), len, response, response_len, 1);

	hexagon_untrusted_current_state.has_rsp = false;
	hexagon_untrusted_current_state.has_packet = false;
	hexagon_untrusted_current_state.has_checksum = false;
	return ERROR_OK;
}
static int hexagon_untrusted_mode()
{
	is_hexagon_untrusted = true;
	LOG_DEBUG("Mode changed to hexagon untrusted!\n");
	return ERROR_OK;
}
/*hexagon-untrusted code changes end*/

struct target_type hexagon_target = {
	.name = "hexagon",
	.poll = hexagon_poll,
	.arch_state = hexagon_arch_state,
	.target_request_data = NULL,
	.resume = hexagon_resume,
	.step = hexagon_step,
	.halt = hexagon_halt,
	.assert_reset = NULL,
	.deassert_reset = NULL,
	.soft_reset_halt = NULL,
	.get_gdb_arch = hexagon_get_gdb_arch,
	.get_gdb_reg_list = hexagon_get_gdb_reg_list,
	.get_gdb_reg_list_noread = hexagon_get_gdb_reg_list,
	.read_memory = hexagon_read_memory,
	.write_memory = hexagon_write_memory,
	.read_buffer = hexagon_read_buffer,
	.write_buffer = hexagon_write_buffer,
	.checksum_memory = NULL,
	.blank_check_memory = NULL,
	.add_breakpoint = hexagon_add_breakpoint,
	.add_context_breakpoint = NULL,
	.add_hybrid_breakpoint = NULL,
	.remove_breakpoint = hexagon_remove_breakpoint,
	.add_watchpoint = NULL,
	.remove_watchpoint = NULL,
	.hit_watchpoint = NULL,
	.commands = hexagon_command_handlers,
	.target_create = hexagon_target_create,
	.target_jim_configure = hexagon_jim_configure,
	.target_jim_commands = NULL,
	.examine = hexagon_examine,
	.init_target = hexagon_init_target,
	.deinit_target = hexagon_deinit_target,
	.virt2phys = hexagon_virt2phys,
	.mmu = hexagon_mmu,
	.check_reset = NULL,
	.get_gdb_fileio_info = NULL,
	.gdb_fileio_end = NULL,
	.profiling = NULL,
	.address_bits = NULL};
