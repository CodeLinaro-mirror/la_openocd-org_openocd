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
#include "hexagon_cdsp.h"


# include<time.h>
clock_t start, end, func_start, func_end;
clock_t start_buffer, end_buffer;

double execution=0;
double buffer_execution=0;
uint64_t refresh_indicator;
extern uint64_t thread_id_thread_select;
extern uint64_t breakpoint_address_thread_select;

#if 0
    #define HEXAGON_DEBUG_LOGS
#endif


/****************************Global /static variable declartions**************************/

int hvx_register_cdsp[32][16] = {-1};

uint32_t qurtk_vtlb_main_addr = 0x0; 
target_addr_t qurtk_vtlb_entries = 0x0; 
target_addr_t bitmap_addr ;
target_addr_t QURTK_vtlb_revision=0x0;
uint64_t revision_num;
// target_addr_t vtlb_entries ;
bool bitmap_init=false;
extern void decToBinary(unsigned int n, unsigned int binaryNum[]);
int hexagon_update_modified_vtlb_entry(struct target *target);

typedef struct hexagon_config
{
    uint32_t maxHwThreads;
    uint32_t qpss6WDOGCtl;
    uint32_t numTlbEntries;
} hexagon_config;

hexagon_config gHexConfig_cdsp =
    {
        .maxHwThreads = 6,
        .qpss6WDOGCtl = 0xA384004,
        .numTlbEntries = 128,
};

uint64_t (*gpPerHwThrdReg_cdsp)[HEXAGON_PER_THREAD_REGS_CDSP] = {0};

static uint64_t **gpSbpHaltedThreadsPC_cdsp;

char (*gpHexagonThreadNameArray_cdsp)[20];

tlb_entries_cdsp *gpHexagonTlbEntries_cdsp;

uint64_t qurtk_vtlb_bitmap= 0x0; 


static int initConfig(hexagon_config *pHexCfg)
{
    int i;
    char a = '0';

    LOG_INFO("InitConfig is called here");

    gpHexagonThreadNameArray_cdsp = malloc((pHexCfg->maxHwThreads + 1) * sizeof(*gpHexagonThreadNameArray_cdsp));
    gpPerHwThrdReg_cdsp = (uint64_t(*)[HEXAGON_PER_THREAD_REGS_CDSP])malloc(pHexCfg->maxHwThreads * sizeof(*gpPerHwThrdReg_cdsp));
    gpSbpHaltedThreadsPC_cdsp = (uint64_t **)malloc(pHexCfg->maxHwThreads * sizeof(uint64_t));
    gpHexagonTlbEntries_cdsp = (tlb_entries_cdsp *)malloc(pHexCfg->numTlbEntries * sizeof(tlb_entries_cdsp));

    if (gpHexagonThreadNameArray_cdsp == NULL || gpPerHwThrdReg_cdsp == NULL || gpSbpHaltedThreadsPC_cdsp == NULL || gpHexagonTlbEntries_cdsp == NULL)
    {
        if (gpHexagonThreadNameArray_cdsp != NULL)
            free(gpHexagonThreadNameArray_cdsp);

        if (gpPerHwThrdReg_cdsp != NULL)
            free(gpPerHwThrdReg_cdsp);

        if (gpSbpHaltedThreadsPC_cdsp != NULL)
            free(gpSbpHaltedThreadsPC_cdsp);

        if (gpHexagonTlbEntries_cdsp != NULL)
            free(gpHexagonTlbEntries_cdsp);

        return ERROR_FAIL;
    }

    for (i = 0; i < pHexCfg->maxHwThreads; i++, a++)
    {
        strcpy(gpHexagonThreadNameArray_cdsp[i], "HW-Thrd-");
        gpHexagonThreadNameArray_cdsp[i][8] = a;
        gpHexagonThreadNameArray_cdsp[i][9] = '\0';
    }
    strcpy(gpHexagonThreadNameArray_cdsp[i], "GLOBAL");

    memset(gpSbpHaltedThreadsPC_cdsp, 0, (pHexCfg->maxHwThreads * sizeof(uint64_t)));
    memset(gpPerHwThrdReg_cdsp, 0, (pHexCfg->maxHwThreads * sizeof(*gpPerHwThrdReg_cdsp)));
    memset(gpHexagonTlbEntries_cdsp, 0, (pHexCfg->numTlbEntries * sizeof(tlb_entries_cdsp)));

    return ERROR_OK;
}

static void deinitConfig(hexagon_config *pHexCfg)
{
    if (gpHexagonThreadNameArray_cdsp != NULL)
        free(gpHexagonThreadNameArray_cdsp);

    if (gpPerHwThrdReg_cdsp != NULL)
        free(gpPerHwThrdReg_cdsp);

    if (gpSbpHaltedThreadsPC_cdsp != NULL)
        free(gpSbpHaltedThreadsPC_cdsp);

    if (gpHexagonTlbEntries_cdsp != NULL)
        free(gpHexagonTlbEntries_cdsp);

    return;
}

static const hexagon_reg_cdsp hexagon_per_hwt_regs_cdsp[] = {
    /** General Purpose Registers **/
    {HEXAGON_R0_CDSP, "R0", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R1_CDSP, "R1", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R2_CDSP, "R2", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R3_CDSP, "R3", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R4_CDSP, "R4", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R5_CDSP, "R5", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R6_CDSP, "R6", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R7_CDSP, "R7", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R8_CDSP, "R8", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R9_CDSP, "R9", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R10_CDSP, "R10", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R11_CDSP, "R11", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R12_CDSP, "R12", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R13_CDSP, "R13", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R14_CDSP, "R14", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R15_CDSP, "R15", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R16_CDSP, "R16", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R17_CDSP, "R17", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R18_CDSP, "R18", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R19_CDSP, "R19", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R20_CDSP, "R20", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R21_CDSP, "R21", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R22_CDSP, "R22", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R23_CDSP, "R23", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R24_CDSP, "R24", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R25_CDSP, "R25", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R26_CDSP, "R26", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R27_CDSP, "R27", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_R28_CDSP, "R28", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_SP_CDSP, "R29", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_FP_CDSP, "R30", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_LR_CDSP, "R31", 32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    /** Control Registers **/
    {HEXAGON_SA0_CDSP, "SA0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_LC0_CDSP, "LC0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_SA1_CDSP, "SA1", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_LC1_CDSP, "LC1", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_P30_CDSP, "P3:0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    /** C5: reserved **/
    {HEXAGON_C5_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_M0_CDSP, "M0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_M1_CDSP, "M1", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_USR_CDSP, "USR", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_PC_CDSP, "PC", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_UGP_CDSP, "UGP", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_GP_CDSP, "GP", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_CS0_CDSP, "CS0", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_CS1_CDSP, "CS1", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_UPCYCLLO_CDSP, "UPCYCLELO", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_UPCYCLHI_CDSP, "UPCYCLEHI", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_FLMT_CDSP, "FLMT", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_FKEY_CDSP, "FKEY", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_PKTCNTLO_CDSP, "PKTCNTLO", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_PKTCNTHI_CDSP, "PKTCNTHI", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    /** C20-29: reserved **/
    {HEXAGON_C20_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C21_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C22_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C23_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C24_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C25_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C26_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C27_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C28_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_C29_RESRV_CDSP, "C5_RESRV", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_UTMRLO_CDSP, "UTMRLO", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_UTMRHI_CDSP, "UTMRHI", 32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    /** Monitor Mode per-thread Control Registers **/
    {HEXAGON_SGP0_CDSP, "SGP0", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_SGP1_CDSP, "SGP1", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_STID_CDSP, "STID", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_ELR_CDSP, "ELR", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_BADVA0_CDSP, "BADVA0", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_BADVA1_CDSP, "BADVA1", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_SSR_CDSP, "SSR", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_CCR_CDSP, "CCR", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_HTID_CDSP, "HTID", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_BADVA_CDSP, "BADVA", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_IMASK_CDSP, "IMASK", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_GEVB_CDSP, "GEVB", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    /** S12 - S15: reserved **/
    {HEXAGON_S12_RESRV_CDSP, "S12_RESRV", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_S13_RESRV_CDSP, "S13_RESRV", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_S14_RESRV_CDSP, "S14_RESRV", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_S15_RESRV_CDSP, "S15_RESRV", 32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},

};

uint32_t global_reg_cdsp[HEXAGON_MMODE_GLOBAL_MAX_CDSP-HEXAGON_MMODE_PERTHRD_MAX_CDSP]={0};


static const hexagon_reg_cdsp hexagon_global_regs_cdsp[] = {
    /** Monitor Mode Global Control Registers **/
    {HEXAGON_EVB_CDSP, "EVB", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_MODECTL_CDSP, "MODECTL", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_SYSCFG_CDSP, "SYSCFG", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    /** 19: reserved **/
    {HEXAGON_S19_RESRV_CDSP, "S19_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_IPENDAD_CDSP, "IPENDAD", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_VID_CDSP, "VID", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_VID1_CDSP, "VID1", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_BESTWAIT_CDSP, "BESTWAIT", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    /** 24: reserved **/
    {HEXAGON_S24_RESRV_CDSP, "S24_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_SCHDCFG_CDSP, "SCHDCFG", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    /** 26: reserved **/
    {HEXAGON_S26_RESRV_CDSP, "S26_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_CFGBASE_CDSP, "CFGBASE", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_DIAG_CDSP, "DIAG", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_REV_CDSP, "REV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_PCYCLELO_CDSP, "PCYCLELO", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    {HEXAGON_PCYCLEHI_CDSP, "PCYCLEHI", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
};

/********************************************/
/** Stuff instruction for register reading **/
/********************************************/

/* R0-R31  registers */
uint32_t stuff_inst_gpr_read_cdsp[] = {
	    
        0x6700c029,	/* isdbmbxout = r0  */
		0x6701c029,	/* isdbmbxout = r1  */
		0x6702c029,	/* isdbmbxout = r2  */
		0x6703c029,	/* isdbmbxout = r3  */
		0x6704c029,	/* isdbmbxout = r4  */
		0x6705c029,	/* isdbmbxout = r5  */
		0x6706c029,	/* isdbmbxout = r6  */
		0x6707c029,	/* isdbmbxout = r7  */
		0x6708c029,	/* isdbmbxout = r8  */
		0x6709c029,	/* isdbmbxout = r9  */
		0x670ac029,	/* isdbmbxout = r10 */
		0x670bc029,	/* isdbmbxout = r11 */
		0x670cc029,	/* isdbmbxout = r12 */
		0x670dc029,	/* isdbmbxout = r13 */
		0x670ec029,	/* isdbmbxout = r14 */
		0x670fc029,	/* isdbmbxout = r15 */
		0x6710c029,	/* isdbmbxout = r16 */
		0x6711c029,	/* isdbmbxout = r17 */
		0x6712c029,	/* isdbmbxout = r18 */
		0x6713c029,	/* isdbmbxout = r19 */
		0x6714c029,	/* isdbmbxout = r20 */
		0x6715c029,	/* isdbmbxout = r21 */
		0x6716c029,	/* isdbmbxout = r22 */
		0x6717c029,	/* isdbmbxout = r23 */
		0x6718c029,	/* isdbmbxout = r24 */
		0x6719c029,	/* isdbmbxout = r25 */
		0x671ac029,	/* isdbmbxout = r26 */
		0x671bc029,	/* isdbmbxout = r27 */
		0x671cc029,	/* isdbmbxout = r28 */
		0x671dc029,	/* isdbmbxout = r29 */
		0x671ec029,	/* isdbmbxout = r30 */
		0x671fc029  /* isdbmbxout = r31 */
};

/* Control registers */
uint32_t stuff_inst_ctrl_reg_read_cdsp[][2] =  {
		{0x6a00c007,0x6707c029},	/* r7 = sa0, isdbmbxout = r7 */
		{0x6a01c007,0x6707c029},	/* r7 = lc0, isdbmbxout = r7 */
		{0x6a02c007,0x6707c029}, 	/* r7 = sa1, isdbmbxout = r7 */
		{0x6a03c007,0x6707c029},	/* r7 = lc1, isdbmbxout = r7 */
		{0x6a04c007,0x6707c029}, 	/* r7 = p3:0 isdbmbxout = r7 */
		{0x0, 0x0},					/* Invalid: C5 reserved 	 */
		{0x6a06c007,0x6707c029},	/* r7 = m0,  isdbmbxout = r7 */
		{0x6a07c007,0x6707c029}, 	/* r7 = m1,  isdbmbxout = r7 */
		{0x6a08c007,0x6707c029},	/* r7 = usr, isdbmbxout = r7 */
		{0x6a09c007,0x6707c029},	/* r7 = pc,  isdbmbxout = r7 */ 
		{0x6a0ac007,0x6707c029},	/* r7 = ugp, isdbmbxout = r7 */
		{0x6a0bc007,0x6707c029}, 	/* r7 = gp,  isdbmbxout = r7 */
		{0x6a0cc007,0x6707c029},	/* r7 = cs0, isdbmbxout = r7 */
		{0x6a0dc007,0x6707c029}, 	/* r7 = cs1, isdbmbxout = r7 */
		{0x6a0ec007,0x6707c029}, 	/* r7 = upcyclelo, isdbmbxout = r7 */
		{0x6a0fc007,0x6707c029}, 	/* r7 = upcyclehi, isdbmbxout = r7 */
		{0x6a10c007,0x6707c029}, 	/* r7 = framelimit,isdbmbxout = r7 */
		{0x6a11c007,0x6707c029},  	/* r7 = framekey,  isdbmbxout = r7 */
		{0x6a12c007,0x6707c029},	/* r7 = pktcountlo,isdbmbxout = r7 */	
		{0x6a13c007,0x6707c029}, 	/* r7 = pktcounthi,isdbmbxout = r7 */
		{0x0, 0x0}, 				/* Invalid: C20 reserved 	 */
		{0x0, 0x0}, 				/* Invalid: C21 reserved 	 */
		{0x0, 0x0}, 				/* Invalid: C22 reserved 	 */
		{0x0, 0x0}, 				/* Invalid: C23 reserved 	 */
		{0x0, 0x0}, 				/* Invalid: C24 reserved	 */
		{0x0, 0x0}, 				/* Invalid: C25 reserved	 */
		{0x0, 0x0}, 				/* Invalid: C26 reserved	 */
		{0x0, 0x0}, 				/* Invalid: C27 reserved	 */
		{0x0, 0x0}, 				/* Invalid: C28 reserved	 */
		{0x0, 0x0}, 				/* Invalid: C29 reserved	 */
		{0x6a1ec007,0x6707c029},  	/* r7 = utimerlo,  isdbmbxout = r7 */
		{0x6a1fc007,0x6707c029} 	/* r7 = utimerhi,  isdbmbxout = r7 */
};

/* Per thread control registers */
uint32_t stuff_inst_mmode_reg_read_cdsp[][2] = { 
		{0x6e80c007,0x6707c029},	/* r7 = sgp0, isdbmbxout = r7  */
		{0x6e81c007,0x6707c029},	/* r7 = sgp1, isdbmbxout = r7  */
		{0x6e82c007,0x6707c029}, 	/* r7 = stid, isdbmbxout = r7  */
		{0x6e83c007,0x6707c029},	/* r7 = elr,  isdbmbxout = r7  */
		{0x6e84c007,0x6707c029}, 	/* r7 = badva0,isdbmbxout = r7 */
		{0x6e85c007,0x6707c029},	/* r7 = badva1,isdbmbxout = r7 */
		{0x6e86c007,0x6707c029}, 	/* r7 = ssr,  isdbmbxout = r7  */
		{0x6e87c007,0x6707c029},	/* r7 = ccr,  isdbmbxout = r7  */
		{0x6e88c007,0x6707c029}, 	/* r7 = htid, isdbmbxout = r7  */
		{0x6e89c007,0x6707c029},	/* r7 = badva,isdbmbxout = r7  */
		{0x6e8ac007,0x6707c029}, 	/* r7 = imask,isdbmbxout = r7  */
		{0x6e8bc007,0x6707c029},	/* r7 = gevb, isdbmbxout = r7  */
		{0x0, 0x0}, 			/* Invalid: S12 reserved */
		{0x0, 0x0}, 			/* Invalid: S13 reserved */
		{0x0, 0x0}, 			/* Invalid: S14 reserved */
		{0x0, 0x0}, 			/* Invalid: S15 reserved */		
};

 uint32_t stuff_inst_mmode_imask_reg_read_cdsp[][3] = {
	 {0x7800c027,0x6607c007,0x6707c029}, /* r7 = #1, r7 = getimask(r7), isdbmbxout = r7 */
	 {0x7800c047,0x6607c007,0x6707c029}, /* r7 = #2, r7 = getimask(r7), isdbmbxout = r7 */
	 {0x7800c087,0x6607c007,0x6707c029}, /* r7 = #4, r7 = getimask(r7), isdbmbxout = r7 */
	 {0x7800c107,0x6607c007,0x6707c029}, /* r7 = #8, r7 = getimask(r7), isdbmbxout = r7 */
	 {0x7800c207,0x6607c007,0x6707c029}, /* r7 = #16,r7 = getimask(r7), isdbmbxout = r7 */
	 {0x7800c407,0x6607c007,0x6707c029}  /* r7 = #32,r7 = getimask(r7), isdbmbxout = r7 */
}; 

/* Global control registers */
uint32_t stuff_inst_global_reg_read_cdsp[][2] = {
		{0x6e90c007,0x6707c029}, /* r7 = evb, isdbmbxout = r7 */	
		{0x6e91c007,0x6707c029}, /* r7 = modectl, isdbmbxout = r7 */	
		{0x6e92c007,0x6707c029}, /* r7 = syscfg, isdbmbxout = r7 */	
		{0x0, 0x0}, 			 /* Invalid: S19 reserved	  */			
		{0x6e94c007,0x6707c029}, /* r7 = ipendad, isdbmbxout = r7 */
		{0x6e95c007,0x6707c029}, /* r7 = vid, isdbmbxout = r7 */	
		{0x6e96c007,0x6707c029}, /* r7 = vid1, isdbmbxout = r7 */	
		{0x6e97c007,0x6707c029}, /* r7 = bestwait, isdbmbxout = r7 */
		{0x0, 0x0}, 			 /* Invalid: S24 reserved	  */			
		{0x6e99c007,0x6707c029}, /* r7 = schedcfg, isdbmbxout = r7 */	
		{0x0, 0x0}, 			 /* Invalid: S26 reserved	  */			
		{0x6e9bc007,0x6707c029}, /* r7 = cfgbase, isdbmbxout = r7 */	
		{0x6e9cc007,0x6707c029}, /* r7 = diag, isdbmbxout = r7 */	
		{0x6e9dc007,0x6707c029}, /* r7 = rev, isdbmbxout = r7 */	
		{0x6e9ec007,0x6707c029}, /* r7 = pcyclelo, isdbmbxout = r7 */	
		{0x6e9fc007,0x6707c029}	 /* r7 = pcyclehi, isdbmbxout = r7 */	
};

uint32_t stuff_inst_sfr_cdsp[][2] = 
		{{0x7800c027,0x6607c007},
		 {0x7800c047,0x6607c007},
		 {0x7800c087,0x6607c007},
		 {0x7800c107,0x6607c007},
		 {0x7800c207,0x6607c007},
		 {0x7800c407,0x6607c007},
		 {0x6a0ac007,0x6707c029},
		 {0x6a0bc007,0x6707c029},
		 {0x6e86c007,0x6707c029},
		 {0x6e84c007,0x6707c029},
		 {0x6e85c007,0x6707c029},
		 {0x6e92c007,0x6707c029},
		 {0x6e91c007,0x6707c029},
		 {0x6e9ec007,0x6707c029},
		 {0x6e9fc007,0x6707c029},
		 {0x6e90c007,0x6707c029},
		 {0x6e9cc007,0x6707c029},
		 {0x6e94c007,0x6707c029},
		 {0x6e9dc007,0x6707c029},
		 {0x6e9bc007,0x6707c029}};

/********************************************/
/** Stuff instruction for register writing **/
/********************************************/

/* R0-R31  registers */
uint32_t stuff_inst_gpr_write_cdsp[] = {
	    	0x6ea8c000,	/* r0  = isdbmbxin */
		0x6ea8c001,	/* r1  = isdbmbxin */
		0x6ea8c002,	/* r2  = isdbmbxin */
	    	0x6ea8c003,	/* r3  = isdbmbxin */
		0x6ea8c004,	/* r4  = isdbmbxin */
		0x6ea8c005,	/* r5  = isdbmbxin */
	    	0x6ea8c006,	/* r6  = isdbmbxin */
		0x6ea8c007,	/* r7  = isdbmbxin */
		0x6ea8c008,	/* r8  = isdbmbxin */
	    	0x6ea8c009,	/* r9  = isdbmbxin */
		0x6ea8c00A,	/* r10 = isdbmbxin */
		0x6ea8c00B,	/* r11 = isdbmbxin */
	    	0x6ea8c00C,	/* r12 = isdbmbxin */
		0x6ea8c00D,	/* r13 = isdbmbxin */
		0x6ea8c00E,	/* r14 = isdbmbxin */
	    	0x6ea8c00F,	/* r15 = isdbmbxin */
		0x6ea8c010,	/* r16 = isdbmbxin */
		0x6ea8c011,	/* r17 = isdbmbxin */
		0x6ea8c012,	/* r18 = isdbmbxin */
		0x6ea8c013,	/* r19 = isdbmbxin */
		0x6ea8c014,	/* r20 = isdbmbxin */
		0x6ea8c015,	/* r21 = isdbmbxin */		
		0x6ea8c016,	/* r22 = isdbmbxin */
		0x6ea8c017,	/* r23 = isdbmbxin */
		0x6ea8c018,	/* r24 = isdbmbxin */
		0x6ea8c019,	/* r25 = isdbmbxin */		
		0x6ea8c01A,	/* r26 = isdbmbxin */
		0x6ea8c01B,	/* r27 = isdbmbxin */		
		0x6ea8c01C,	/* r28 = isdbmbxin */
		0x6ea8c01D,	/* r29 = isdbmbxin */
		0x6ea8c01E,	/* r30 = isdbmbxin */
		0x6ea8c01F,	/* r31 = isdbmbxin */	
};

/* Control registers */
uint32_t stuff_inst_ctrl_reg_write_cdsp[][2] =  {
	{0x6ea8c007, 0x6227c000},	/* r7 = isdbmbxin, sa0 = r7 */
	{0x6ea8c007, 0x6227c001},	/* r7 = isdbmbxin, lc0 = r7 */
	{0x6ea8c007, 0x6227c002}, 	/* r7 = isdbmbxin, sa1 = r7 */
	{0x6ea8c007, 0x6227c003}, 	/* r7 = isdbmbxin, lc1 = r7 */
	{0x6ea8c007, 0x6227c004}, 	/* r7 = isdbmbxin, p3:0 = r7*/
	{0x0, 0x0}, 				/* Invalid: C5 reserved */
	{0x6ea8c007, 0x6227c006}, 	/* r7 = isdbmbxin, m0 = r7  */
	{0x6ea8c007, 0x6227c007}, 	/* r7 = isdbmbxin, m1 = r7  */
	{0x6ea8c007, 0x6227c008}, 	/* r7 = isdbmbxin, usr = r7 */
	{0x6ea8c007, 0x5287c000},	/* r7 = isdbmbxin, jump r7 (PC=r7)  */ 
	{0x6ea8c007, 0x6227c00a}, 	/* r7 = isdbmbxin, ugp = r7 */
	{0x6ea8c007, 0x6227c00b}, 	/* r7 = isdbmbxin, gp = r7  */
	{0x6ea8c007, 0x6227c00c}, 	/* r7 = isdbmbxin, cs0 = r7 */
	{0x6ea8c007, 0x6227c00d}, 	/* r7 = isdbmbxin, cs1 = r7 */
	{0x6ea8c007, 0x6227c00e}, 	/* r7 = isdbmbxin, upcyclelo = r7 */
	{0x6ea8c007, 0x6227c00f}, 	/* r7 = isdbmbxin, upcyclehi = r7 */
	{0x6ea8c007, 0x6227c010}, 	/* r7 = isdbmbxin, framelimit= r7 */
	{0x6ea8c007, 0x6227c011}, 	/* r7 = isdbmbxin, framekey = r7 */
	{0x6ea8c007, 0x6227c012},	/* r7 = isdbmbxin, pktcountlo = r7 */
	{0x6ea8c007, 0x6227c013}, 	/* r7 = isdbmbxin, pktcounthi = r7 */
	{0x0, 0x0}, 				/* Invalid: C20 reserved 	 */
	{0x0, 0x0}, 				/* Invalid: C21 reserved 	 */
	{0x0, 0x0}, 				/* Invalid: C22 reserved 	 */
	{0x0, 0x0}, 				/* Invalid: C23 reserved 	 */
	{0x0, 0x0}, 				/* Invalid: C24 reserved	 */
	{0x0, 0x0}, 				/* Invalid: C25 reserved	 */
	{0x0, 0x0}, 				/* Invalid: C26 reserved	 */
	{0x0, 0x0}, 				/* Invalid: C27 reserved	 */
	{0x0, 0x0}, 				/* Invalid: C28 reserved	 */
	{0x0, 0x0}, 				/* Invalid: C29 reserved	 */
	{0x6ea8c007, 0x6227c01e}, 	/* r7 = isdbmbxin, utimerlo = r7  */
	{0x6ea8c007, 0x6227c01f}, 	/* r7 = isdbmbxin, utimerhi = r7 */
};

/* Per thread control registers */
uint32_t stuff_inst_mmode_reg_write_cdsp[][2] = { 
	{0x6ea8c007, 0x6707c000}, 	/* r7 = isdbmbxin, sgp0 = r7 */
	{0x6ea8c007, 0x6707c001}, 	/* r7 = isdbmbxin, sgp1 = r7 */
	{0x6ea8c007, 0x6707c002},	/* r7 = isdbmbxin, stid = r7 */
	{0x6ea8c007, 0x6707c003}, 	/* r7 = isdbmbxin, elr = r7  */
	{0x6ea8c007, 0x6707c004}, 	/* r7 = isdbmbxin, badva0 = r7 */
	{0x6ea8c007, 0x6707c005},	/* r7 = isdbmbxin, badva1 = r7 */
	{0x6ea8c007, 0x6707c006}, 	/* r7 = isdbmbxin, ssr = r7 */
	{0x6ea8c007, 0x6707c007}, 	/* r7 = isdbmbxin, ccr = r7 */
	{0x0, 0x0}, 				/* Invalid: S12 reserved */
	{0x0, 0x0}, 				/* Invalid: S13 reserved */
	{0x0, 0x0}, 				/* Invalid: S14 reserved */
	{0x0, 0x0}, 				/* Invalid: S15 reserved */	
};

/* Per thread control registers */
uint32_t stuff_inst_global_reg_write_cdsp[][2] = {
    {0x6ea8c007, 0x6707c010}, /* r7 = isdbmbxin, evb = r7 */
    {0x0, 0x0},               /* modectl: read only */
    {0x6ea8c007, 0x6707c012}, /* r7 = isdbmbxin, syscfg = r7 */
    {0x0, 0x0},               /* Invalid: S19 reserved */
    {0x0, 0x0},               /* ipendad: read only */
    {0x6ea8c007, 0x6707c015}, /* r7 = isdbmbxin, vid = r7 */
    {0x6ea8c007, 0x6707c016}, /* r7 = isdbmbxin, vid1 = r7 */
    {0x6ea8c007, 0x6707c017}, /* r7 = isdbmbxin, bestwait = r7 */
    {0x0, 0x0},               /* Invalid: S24 reserved */
    {0x0, 0x0},               /* schdcfg: read only */
    {0x0, 0x0},               /* Invalid: S26 reserved */
    {0x0, 0x0},               /* cfgbase: read only  */
    {0x6ea8c007, 0x6707c01c}, /* r7 = isdbmbxin, diag = r7 */
    {0x0, 0x0},               /* Rev: read only */
    {0x6ea8c007, 0x6707c01e}, /* r7 = isdbmbxin, pcyclelo = r7 */
    {0x6ea8c007, 0x6707c01f}, /* r7 = isdbmbxin, pcyclehi = r7 */
};

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

static int hexagon_get_core_reg_cdsp(struct reg *reg);
static int hexagon_set_core_reg_cdsp(struct reg *reg, uint8_t *buf);

static const struct reg_arch_type hexagon_reg_type_cdsp = {
    .get = hexagon_get_core_reg_cdsp,
    .set = hexagon_set_core_reg_cdsp,
};
uint32_t hexagon_r0_used_stuff_cdsp = 0, hexagon_r1_used_stuff_cdsp = 0, 
	hexagon_r2_used_stuff_cdsp = 0, hexagon_r7_used_stuff_cdsp = 0;

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
int64_t hexagon_time_start_cdsp = 0, hexagon_time_total_cdsp = 0;
#endif

vtlb_data_cdsp hexagon_vtlb_data_cdsp = {0};
tlb_entries_cdsp *hexagon_vtlb_entries_cdsp = NULL;
struct adiv5_ap *debug_axi_ap_cdsp = NULL;
static uint32_t hexagon_syscfg_reg_cdsp;

// Global data to store/keep track of the initial PC value once threads are halted through software breakpoint, value are cleared once resume happens.
static uint8_t sbp_step_executed_cdsp = 0; // Just a bool variable

/****************************Function declartions***********************************************/
static int hexagon_poll_cdsp(struct target *target);
int hexagon_arch_state_cdsp(struct target *target);
static int hexagon_resume_cdsp(struct target *target, int current, target_addr_t address,
                               int handle_breakpoints, int debug_execution);
static int hexagon_step_cdsp(struct target *target, int current, target_addr_t address,
                             int handle_breakpoints);
static int hexagon_halt_cdsp(struct target *target);
const char *hexagon_get_gdb_arch_cdsp(struct target *target);
int hexagon_get_gdb_reg_list_cdsp(struct target *target,
                                  struct reg **reg_list[], int *reg_list_size,
                                  enum target_register_class reg_class);

static int hexagon_read_memory_cdsp(struct target *target, target_addr_t address,
                                    uint32_t size, uint32_t count, uint8_t *buffer);
static int hexagon_write_memory_cdsp(struct target *target, target_addr_t address,
                                     uint32_t size, uint32_t count, const uint8_t *buffer);
static int hexagon_read_buffer_cdsp(struct target *target, target_addr_t address,
                                    uint32_t size, uint8_t *buffer);
static int hexagon_write_buffer_cdsp(struct target *target, target_addr_t address,
                                     uint32_t size, const uint8_t *buffer);
static int hexagon_add_breakpoint_cdsp(struct target *target,
                                       struct breakpoint *breakpoint);
static int hexagon_remove_breakpoint_cdsp(struct target *target, struct breakpoint *breakpoint);
static int hexagon_target_create_cdsp(struct target *target, Jim_Interp *interp);
static int hexagon_jim_configure_cdsp(struct target *target, struct jim_getopt_info *goi);
static int hexagon_init_debug_access_cdsp(struct target *target);
static int hexagon_examine_first_cdsp(struct target *target);
static int hexagon_examine_cdsp(struct target *target);
static int hexagon_init_target_cdsp(struct command_context *cmd_ctx,
                                    struct target *target);
static void hexagon_deinit_target_cdsp(struct target *target);
static int hexagon_virt2phys_cdsp(struct target *target, target_addr_t virt,
                                  target_addr_t *phys);
static int hexagon_mmu_cdsp(struct target *target, int *enabled);
static int hexagon_init_arch_info_cdsp(struct target *target,
                                       struct hexagon_common_cdsp *hexagon, struct adiv5_dap *dap);
static int hexagon_handle_target_request_cdsp(void *priv);
static uint64_t hexagon_etm_on_cdsp(struct target *target);
static void hexagon_long_wait_loop_cdsp(void);
static void hexagon_wait_loop_cdsp(void);
static int hexagon_brkpt_setup_cdsp(struct hexagon_common_cdsp *hexagon);
static int hexagon_reg_setup_cdsp(struct hexagon_common_cdsp *hexagon);
static int hexagon_read_core_reg_cdsp(struct target *target, struct reg *r, int regnum, uint32_t hwthrd);
static int hexagon_write_core_reg_cdsp(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
struct reg *hexagon_reg_current_cdsp(struct hexa_info_cdsp *hexa_info, unsigned int regnum,
                                     struct reg_cache *cache);
struct reg_cache *hexagon_build_reg_cache_cdsp(struct target *target, uint32_t hwthrd);
static int hexagon_check_state_one_cdsp(struct target *target,
                                        uint64_t mask, bool *halted, uint64_t *debug_thread);
int hexagon_read_current_registers_cdsp(struct target *target, uint32_t hwthrd);
void hexagon_update_sp_pc_fp_gdb_server_cdsp(unsigned int hwthrd, unsigned int *pc,
                                             unsigned int *fp, unsigned int *sp);
int hexagon_read_tlb_entry_cdsp(struct target *target);
static void hexagon_update_tlb_entry_in_structure_cdsp(uint64_t tlb_phy, uint64_t tlb_virtual, uint64_t index);

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
void hexagon_start_time_cal_ms_cdsp(void);
void hexagon_end_time_cal_ms_cdsp(void);
#endif
static int hexagon_dump_hwthrd_reg_cdsp(struct target *target, uint32_t hwthrd);
int hexagon_read_gpr_registers_cdsp(struct target *target, uint32_t hwthrd);
int hexagon_read_ctrl_registers_cdsp(struct target *target, uint32_t hwthrd);
int hexagon_read_mmode_registers_cdsp(struct target *target, uint32_t hwthrd);
int hexagon_read_imask_register_cdsp(struct target *target, uint32_t hwthrd);
static int hexagon_restore_stuff_used_reg_cdsp(struct target *target);
int hexagon_read_global_ctrl_registers_cdsp(struct target *target);
void hexagon_debug_reason_cdsp(struct target *target, uint64_t brkptinfo);
static int hexagon_write_gpr_register_cdsp(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
static int hexagon_write_ctrl_register_cdsp(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
static int hexagon_write_global_ctrl_register_cdsp(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
unsigned int get_phys_page_cdsp(unsigned int lo, unsigned int hi, unsigned int mask);
unsigned int get_phys_mask_cdsp(unsigned int tlblo);
static unsigned int hexagon_ct0_cdsp(unsigned int d);
static unsigned int hexagon_clrbit_cdsp(unsigned int d, unsigned int bit);
static unsigned int QURT_getPhysAddr_v2_cdsp(uint64_t pg_tlblo, uint64_t pg_tlbhi);
static int hexagon_search_virtadd_in_tlb_cdsp(uint64_t virt, target_addr_t *phys);
static int hexagon_search_virtadd_in_vtlb_cdsp(struct target *target, uint64_t virt_add, target_addr_t *phys);
static void hexagon_memw_phys_read_cdsp(struct target *target, target_addr_t phy_address, uint64_t *value);
static void hexagon_memw_read_cdsp(struct target *target, uint64_t virt_address, uint64_t *value);
static void hexagon_memw_read_buffer_cdsp(struct target *target, uint64_t virt_address, uint32_t size, uint8_t *buffer);
static void hexagon_populate_vtlb_entries_cdsp(struct target *target);
static void hexagon_update_vtlb_entry_in_structure_cdsp(uint64_t tlb_phy, uint64_t tlb_virtual, uint64_t index);
static void hexagon_populate_vtlb_refresh_entries_cdsp(struct target *target);
static void hexagon_stuff_reg_restore_r7_cdsp(struct target *target);
static void hexagon_stuff_reg_restore_r0_r1_r7_cdsp(struct target *target);
static void hexagon_memw_phys_read_buffer_cdsp(struct target *target, target_addr_t phy_address, uint32_t size, uint8_t *buffer);
static int hexagon_write_syscfg_register_cdsp(struct target *target, uint32_t value);
static int hexagon_read_syscfg_register_cdsp(struct target *target);
static int hexagon_memw_write_cdsp(struct target *target, uint64_t virt_address, uint32_t value, uint32_t size);
static int hexagon_memw_write_buffer_cdsp(struct target *target, uint64_t virt_address, uint32_t size, const uint8_t *buffer);
static int hexagon_set_breakpoint_cdsp(struct target *target, struct breakpoint *breakpoint, uint64_t bpconfig);
static int hexagon_setup_isdb_config_cdsp(struct target *target, uint64_t old_isdbcfg0, uint8_t hbp_num);
static int hexagon_memw_write_instruction_memory_cdsp(struct target *target, uint64_t virt_address, uint32_t value, uint8_t flag);
static int hexagon_unset_breakpoint_cdsp(struct target *target, struct breakpoint *breakpoint);
static void hexagon_stuff_reg_restore_r0_r1_r2_r7_cdsp(struct target *target);
static uint64_t hexagon_print_pc_cdsp(struct target *target);
static int hexagon_dump_isdb_reg_cdsp(struct hexa_info_cdsp *hexa_info);
static int hexagon_read_BRKPT_through_stuff_cdsp(struct target *target, uint32_t hwthrd);
static void hexagon_populate_vtlb_data_cdsp(struct target *target);
static void hexagon_print_vtlb_entries_cdsp(void);
uint64_t hexagon_no_of_hw_threads_cdsp(void);
int hexagon_read_hvx_registers_cdsp(struct target *target);
int hexagon_write_hvx_registers_cdsp(struct target *target, uint32_t value);
static void hexagon_hw_watchdog_disable_cdsp(struct target *target);

/**********************************Function Definitions*****************************************/
/* this function is used to fetch SP , PC and FP value for given HW thread from gdb server  */
void hexagon_update_sp_pc_fp_gdb_server_cdsp(unsigned int hwthrd, unsigned int *pc,
                                             unsigned int *fp, unsigned int *sp)
{
    *pc = gpPerHwThrdReg_cdsp[hwthrd][HEXAGON_PC_CDSP];
    *fp = gpPerHwThrdReg_cdsp[hwthrd][HEXAGON_FP_CDSP];
    *sp = gpPerHwThrdReg_cdsp[hwthrd][HEXAGON_SP_CDSP];
}

uint64_t hexagon_no_of_hw_threads_cdsp(void)
{
    int temp = gHexConfig_cdsp.maxHwThreads;
    LOG_DEBUG("hexagon_no_of_hw_threads_cdsp  = 0x%x  ", temp);
    return gHexConfig_cdsp.maxHwThreads;
}

static int hexagon_virt2phys_cdsp(struct target *target, target_addr_t virt, target_addr_t *phys)
{
    int ret_val;
    uint64_t virt_add;
    virt_add = virt;

    //	LOG_DEBUG("virt address  = 0x%x  ", virt_add);

    ret_val = hexagon_search_virtadd_in_tlb_cdsp(virt_add, phys);
    if (ret_val == ERROR_OK)
        return ret_val;
#ifdef _VTLB_ENABLED_CDSP
    ret_val = hexagon_search_virtadd_in_vtlb_cdsp(target, virt_add, phys);
#endif
    return ret_val;
}

/* this function is use to convert the Virtual address to physical address using TLB entries*/
static int hexagon_search_virtadd_in_tlb_cdsp(uint64_t virt, target_addr_t *phys)
{
    int i;
    uint64_t offset = 0;
    uint64_t asid;
    uint64_t temp_phy = 0;

    for (i = 0; i < gHexConfig_cdsp.numTlbEntries; i++)
    {
        if ((virt >= gpHexagonTlbEntries_cdsp[i].virt_add_low) && (virt <= gpHexagonTlbEntries_cdsp[i].virt_add_high))
        {

            if (gpHexagonTlbEntries_cdsp[i].globalbit)
            {
                offset = virt - gpHexagonTlbEntries_cdsp[i].virt_add_low;
                *phys = gpHexagonTlbEntries_cdsp[i].phy_add_low + offset;
                LOG_DEBUG("i=%d; virt =0x%llx ; virt_add_low = 0x%llx; phy_add_low = 0x%llx  ",i, virt, gpHexagonTlbEntries_cdsp[i].virt_add_low, gpHexagonTlbEntries_cdsp[i].phy_add_low);
                LOG_DEBUG("Physical address  = 0x%x  ",*phys);
                return ERROR_OK;
            }
            else
            {
                offset = virt - gpHexagonTlbEntries_cdsp[i].virt_add_low;
                *phys = gpHexagonTlbEntries_cdsp[i].phy_add_low + offset;
                LOG_DEBUG("Physical address  = 0x%x  ",*phys);
                LOG_DEBUG("i=%d; virt =0x%llx ; virt_add_low = 0x%llx; phy_add_low = 0x%llx  ",i, virt, gpHexagonTlbEntries_cdsp[i].virt_add_low, gpHexagonTlbEntries_cdsp[i].phy_add_low);

                return ERROR_OK;
            }
        }
    }
    if (i == gHexConfig_cdsp.numTlbEntries)
    {
        *phys = 0;
        LOG_DEBUG("Entry not found in TLB for virt address = 0x%x  ", virt);
        return ERROR_FAIL;
    }
    return ERROR_OK;
}

/* this function is use to convert the Virtual address to physical address using VTLB entries*/
static int hexagon_search_virtadd_in_vtlb_cdsp(struct target *target, uint64_t virt_add, target_addr_t *phys)
{
    uint64_t offset = 0, i;
    tlb_entries_cdsp *temp = NULL;

    	// hexagon_populate_vtlb_refresh_entries_cdsp(target);
    //	LOG_INFO("hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries = 0x%x  ", hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries);

    if (hexagon_vtlb_data_cdsp.vtlb_no_of_entries == 0)
    {
        hexagon_populate_vtlb_data_cdsp(target);
    }
    for (i = 0; i < hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries; i++)
    {
        temp = hexagon_vtlb_entries_cdsp + i;
        if (virt_add >= temp->virt_add_low && virt_add <= temp->virt_add_high)
        {

            if (temp->globalbit)
            {
                offset = virt_add - temp->virt_add_low;
                *phys = temp->phy_add_low + offset;

                return ERROR_OK;
            }
            else
            {
                offset = virt_add - temp->virt_add_low;
                *phys = temp->phy_add_low + offset;

                return ERROR_OK;
            }
        }
    }
    if (i == hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries)
    {
        *phys = 0;
        LOG_DEBUG("Entry not found in Vtable virt address  = 0x%x  ", virt_add);
        return ERROR_FAIL;
    }
    return ERROR_OK;
}

/* This function refresh the VTLB entries in case of Halt / step in etc*/
static void hexagon_populate_vtlb_refresh_entries_cdsp(struct target *target)
{
    int retval = ERROR_OK;

    LOG_DEBUG("hexagon_populate_vtlb_refresh_entries_cdsp  Enter");

    if (hexagon_vtlb_data_cdsp.vtlb_no_of_entries == 0)
    {
        hexagon_populate_vtlb_data_cdsp(target);
        return;
    }

#ifdef HEXAGON_VTLB_OLD_ARCH_CDSP
#ifdef HEXAGON_VTLB_AXI_CDSP
    if (debug_axi_ap_cdsp == NULL)
        hexagon_initialize_axi_ap_cdsp(target);

    retval = mem_ap_read_buf(debug_axi_ap_cdsp,
                             (uint8_t *)&hexagon_vtlb_data_cdsp.vtlb_current_counter, 4, 1, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_PA - 16);

    if (retval != ERROR_OK)
    {
        LOG_DEBUG("mem_ap_read_buf API failed to read");
        return;
    }
    if (hexagon_vtlb_data_cdsp.vtlb_previous_counter == hexagon_vtlb_data_cdsp.vtlb_current_counter)
    {
        return;
    }
    retval = mem_ap_read_buf(debug_axi_ap_cdsp, (uint8_t *)&hexagon_vtlb_data_cdsp.vtlb_no_of_entries, 4, 1,
                             hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_PA);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("mem_ap_read_buf API failed to read");
        return;
    }
#endif

#ifdef HEXAGON_VTLB_MEM_PHYS_CDSP
    hexagon_memw_phys_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_PA - 16, &hexagon_vtlb_data_cdsp.vtlb_current_counter);
    if (hexagon_vtlb_data_cdsp.vtlb_previous_counter == hexagon_vtlb_data_cdsp.vtlb_current_counter)
    {
        return;
    }
    hexagon_memw_phys_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_PA, &hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
#endif

#ifdef HEXAGON_VTLB_MEMW_CDSP
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA - 16, &hexagon_vtlb_data_cdsp.vtlb_current_counter);
    if (hexagon_vtlb_data_cdsp.vtlb_previous_counter == hexagon_vtlb_data_cdsp.vtlb_current_counter)
    {
        return;
    }
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_VA, &hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
#endif
#endif

#ifdef HEXAGON_VTLB_NEW_ARCH_CDSP
    uint64_t output[2] = {0};

    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA - 16,
                           &hexagon_vtlb_data_cdsp.vtlb_current_counter);
    if (hexagon_vtlb_data_cdsp.vtlb_previous_counter == hexagon_vtlb_data_cdsp.vtlb_current_counter)
    {
        return;
    }
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA, &output[0]);
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA + 4, &output[1]);

    // memcpy(&hexagon_vtlb_data_cdsp.qurtk_vtlb_main, &output, 8);
    // LOG_DEBUG("hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr = 0x%x ",
    //           hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr);

    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr, &output[0]);
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr + 4, &output[1]);
    // memcpy(&hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next, &output, 8);
    LOG_DEBUG("hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next.table_entries= 0x%x ",
              hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next.table_entries);
    hexagon_vtlb_data_cdsp.vtlb_no_of_entries = hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next.table_entries;
#endif

    LOG_DEBUG("hexagon_vtlb_data.vtlb_no_of_entries = 0x%x and retval = %d", hexagon_vtlb_data_cdsp.vtlb_no_of_entries, retval);

    /* updating the TLB entries also here  */
    // hexagon_read_tlb_entry_cdsp(target);

    if (hexagon_vtlb_entries_cdsp == NULL)
    {
        hexagon_vtlb_entries_cdsp = malloc(sizeof(tlb_entries_cdsp) * hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
        memset(hexagon_vtlb_entries_cdsp, 0, sizeof(tlb_entries_cdsp) * hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
    }
    else
    {
        free(hexagon_vtlb_entries_cdsp);
        hexagon_vtlb_entries_cdsp = malloc(sizeof(tlb_entries_cdsp) * hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
        memset(hexagon_vtlb_entries_cdsp, 0, sizeof(tlb_entries_cdsp) * hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
    }
    hexagon_populate_vtlb_entries_cdsp(target);
    LOG_DEBUG("hexagon_populate_vtlb_refresh_entries_cdsp  Exit");
}

/* This function used to initialize the AXI-AP */
static void hexagon_initialize_axi_ap_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct adiv5_dap *swddp = hexa_info->dap;
    int retval, i;

    LOG_DEBUG("hexagon_initialize_axi_ap_cdsp  Enter");
    retval = enable_dbg_sys_pwr(swddp);

    if (debug_axi_ap_cdsp == NULL)
    {
        /* Search for the AXI-AP - it is needed for access to memory */
        retval = dap_find_get_ap(swddp, AP_TYPE_AXI_AP, &debug_axi_ap_cdsp);
        if (retval != ERROR_OK)
        {
            for (i = 0; i < 10; i++)
            {
                hexagon_wait_loop_cdsp();
                retval = dap_find_get_ap(swddp, AP_TYPE_AXI_AP, &debug_axi_ap_cdsp);
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
        retval = mem_ap_init(debug_axi_ap_cdsp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("Could not initialize the AP_TYPE_AXI_AP");
            return;
        }
        debug_axi_ap_cdsp->memaccess_tck = 10;
    }
    LOG_DEBUG("hexagon_initialize_axi_ap  Exit");
}

/* This function populate the VTLB global data like no of entries in VTLB, counter and allocate VTLB memory for entries */
static void hexagon_populate_vtlb_data_cdsp(struct target *target)
{
    int retval;

    LOG_DEBUG("hexagon_populate_vtlb_data  Enter");

#ifdef HEXAGON_VTLB_OLD_ARCH_CDSP

#ifdef HEXAGON_VTLB_AXI_CDSP
    if (debug_axi_ap_cdsp == NULL)
        hexagon_initialize_axi_ap_cdsp(target);
#endif

    hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries = 0;

#ifdef HEXAGON_VTLB_AXI_CDSP
    retval = mem_ap_read_buf(debug_axi_ap_cdsp,
                             (uint8_t *)&hexagon_vtlb_data_cdsp.vtlb_current_counter, 4, 1, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_PA - 16);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("mem_ap_read_buf API failed to read");
        return;
    }
    hexagon_vtlb_data_cdsp.vtlb_previous_counter = hexagon_vtlb_data_cdsp.vtlb_current_counter;
    LOG_DEBUG("vtlb_current_counter = 0x%x and retval = %d", hexagon_vtlb_data_cdsp.vtlb_current_counter, retval);

    retval = mem_ap_read_buf(debug_axi_ap_cdsp, (uint8_t *)&hexagon_vtlb_data_cdsp.vtlb_no_of_entries, 4, 1,
                             hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_PA);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("mem_ap_read_buf API failed to read");
        return;
    }
    LOG_DEBUG("vtlb_no_of_entries = 0x%x and retval = %d", hexagon_vtlb_data_cdsp.vtlb_no_of_entries, retval);
#endif

#ifdef HEXAGON_VTLB_MEM_PHYS_CDSP
    hexagon_memw_phys_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_PA - 16,
                                &hexagon_vtlb_data_cdsp.vtlb_current_counter);
    hexagon_vtlb_data_cdsp.vtlb_previous_counter = hexagon_vtlb_data_cdsp.vtlb_current_counter;
    LOG_DEBUG("vtlb_current_counter = 0x%x ", hexagon_vtlb_data_cdsp.vtlb_current_counter);
    hexagon_memw_phys_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_PA,
                                &hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
    LOG_DEBUG("vtlb_no_of_entries = 0x%x ", hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
#endif

#ifdef HEXAGON_VTLB_MEMW_CDSP
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA - 16,
                           &hexagon_vtlb_data_cdsp.vtlb_current_counter);
    hexagon_vtlb_data_cdsp.vtlb_previous_counter = hexagon_vtlb_data_cdsp.vtlb_current_counter;
    LOG_DEBUG("hexagon_vtlb_data_cdsp.vtlb_current_counter = 0x%x ", hexagon_vtlb_data_cdsp.vtlb_current_counter);
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_VA,
                           &hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
    LOG_DEBUG("hexagon_vtlb_data_cdsp.vtlb_no_of_entries = 0x%x ", hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
#endif
    if (hexagon_vtlb_entries_cdsp == NULL)
    {
        hexagon_vtlb_entries_cdsp = malloc(sizeof(tlb_entries_cdsp) * hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
        memset(hexagon_vtlb_entries_cdsp, 0, sizeof(tlb_entries_cdsp) * hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
    }
#endif

#ifdef HEXAGON_VTLB_NEW_ARCH_CDSP

    // QURTK_vtlb_main 		 	 D:FE01CED8--FE01CEDB

    hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries = 0;
    uint64_t output[2] = {0}, temp, temp1, temp2;

    LOG_DEBUG("qurtk_vtlb_main_addr   = 0x%x ",qurtk_vtlb_main_addr);

    hexagon_memw_read_cdsp(target, qurtk_vtlb_main_addr,
                           &hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA);
    LOG_DEBUG("hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA   = 0x%x ", hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA);

    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA - 16,
                           &hexagon_vtlb_data_cdsp.vtlb_current_counter);
    hexagon_vtlb_data_cdsp.vtlb_previous_counter = hexagon_vtlb_data_cdsp.vtlb_current_counter;
    LOG_DEBUG("vtlb_current_counter = 0x%x ", hexagon_vtlb_data_cdsp.vtlb_current_counter);

    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA, &output[0]);
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA + 4, &output[1]);
    temp = output[0] >> 8;
    temp1 = (output[1] & 0xFFF) << 24;
    temp2 = temp | temp1;
    hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr = temp2;

    // memcpy(&hexagon_vtlb_data_cdsp.qurtk_vtlb_main, &output, 8);
    LOG_DEBUG("hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr = 0x%x ",
              hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr);

    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr, &output[0]);
    hexagon_memw_read_cdsp(target, hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr + 4, &output[1]);
    // memcpy(&hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next, &output, 8);
    temp2 = output[1] >> 12;
    hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next.table_entries = temp2;
    LOG_DEBUG("hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next.table_entries= 0x%x ",
              hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next.table_entries);
    hexagon_vtlb_data_cdsp.vtlb_no_of_entries = hexagon_vtlb_data_cdsp.qurtk_vtlb_main_next.table_entries;

    if (hexagon_vtlb_entries_cdsp == NULL)
    {
        hexagon_vtlb_entries_cdsp = malloc(sizeof(tlb_entries_cdsp) * hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
        memset(hexagon_vtlb_entries_cdsp, 0, sizeof(tlb_entries_cdsp) * hexagon_vtlb_data_cdsp.vtlb_no_of_entries);
    }
#endif

    hexagon_populate_vtlb_entries_cdsp(target);
    LOG_DEBUG("hexagon_populate_vtlb_data_cdsp  Exit");
}

/* This function populate the VTLB entries from QURTK_VTLB_DATA*/
static void hexagon_populate_vtlb_entries_cdsp(struct target *target)
{
    int retval;
    uint32_t output[2] = {0}, i, address;

    LOG_DEBUG("hexagon_populate_vtlb_entries_cdsp  Enter");

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

#ifdef HEXAGON_VTLB_OLD_ARCH_CDSP

#ifdef _BITRA_TARGET_CDSP
    address = hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_PA + 0x40E0;
#ifdef HEXAGON_VTLB_MEMW_CDSP
    address = hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_VA + 0x40E0;
#endif
#endif

#ifdef _CEDROS_TARGET_CDSP
    address = hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_PA + 0x40E0;
#ifdef HEXAGON_VTLB_MEMW_CDSP
    address = hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_VA + 0x40E0;
#endif
#endif

#ifdef HEXAGON_VTLB_AXI_CDSP
    if (debug_axi_ap_cdsp == NULL)
        hexagon_initialize_axi_ap_cdsp(target);
#endif
    hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries = 0;

#ifdef HEXAGON_VTLB_AXI_CDSP
    for (i = 0; i < hexagon_vtlb_data_cdsp.vtlb_no_of_entries; i++)
    {
        retval = mem_ap_read_buf(debug_axi_ap_cdsp, (uint8_t *)&output, 4, 2, address + 8 * i);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("mem_ap_read_buf API failed to read");
            continue;
        }
        hexagon_update_vtlb_entry_in_structure_cdsp(output[0], output[1], i);
    }
#endif

#ifdef HEXAGON_VTLB_MEM_PHYS_CDSP
    for (i = 0; i < hexagon_vtlb_data_cdsp.vtlb_no_of_entries; i++)
    {
        hexagon_memw_phys_read_cdsp(target, address, &output[0]);
        hexagon_memw_phys_read_cdsp(target, address + 4, &output[1]);
        //	LOG_DEBUG("Phy_page = 0x%08x and virtual page  = 0x%08x " , output[0],output[1]);
        hexagon_update_vtlb_entry_in_structure_cdsp(output[0], output[1], i);
        address = address + 8;
    }
#endif

#ifdef HEXAGON_VTLB_MEMW_CDSP
    for (i = 0; i < hexagon_vtlb_data_cdsp.vtlb_no_of_entries; i++)
    {
        hexagon_memw_read_cdsp(target, address, &output[0]);
        hexagon_memw_read_cdsp(target, address + 4, &output[1]);
        //	LOG_DEBUG("Phy_page = 0x%08x and virtual page  = 0x%08x " , output[0],output[1]);
        hexagon_update_vtlb_entry_in_structure_cdsp(output[0], output[1], i);
        address = address + 8;
    }
#endif
#endif

#ifdef HEXAGON_VTLB_NEW_ARCH_CDSP
    address = hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr + 8;
    for (i = 0; i < hexagon_vtlb_data_cdsp.vtlb_no_of_entries; i++)
    {
        hexagon_memw_read_cdsp(target, address, &output[0]);
        hexagon_memw_read_cdsp(target, address + 4, &output[1]);
        LOG_DEBUG("raw start range = 0x%08x and raw end range  = 0x%08x " , output[0],output[1]);
        hexagon_update_vtlb_entry_in_structure_cdsp(output[0], output[1], i);
        address = address + 8;
    }

#endif

    hexagon_print_vtlb_entries_cdsp();

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif

    LOG_DEBUG("hexagon_populate_vtlb_entries_cdsp  Exit");
}

/* This function print the VTLB entries*/
static void hexagon_print_vtlb_entries_cdsp(void)
{
    tlb_entries_cdsp *temp = NULL;
    uint64_t i;
    LOG_DEBUG("Printing the VTLB content");

    for (i = 0; i < hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries; i++)
    {
        temp = hexagon_vtlb_entries_cdsp + i;
        LOG_DEBUG("VA = 0x%x --> PA = 0x%x ", temp->virt_tlb_raw_data, temp->phys_tlb_raw_data);
        // LOG_DEBUG("VA Page = 0x%08x PA Page =  0x%08x and Page size = %d", temp->virt_page,temp->phy_page,temp->page_size);
        LOG_DEBUG("VA = 0x%08x -- 0x%08x and PA = 0x%llx -- 0x%llx", temp->virt_add_low, temp->virt_add_high,
                  temp->phy_add_low, temp->phy_add_high);
        LOG_DEBUG("phy page = 0x%lx \t virt page = 0x%lx and SID = 0x%lx ", temp->phy_page, temp->virt_page,
                  temp->asid);
    }
}

/* this function update the tlb entry in global structure  hexagon_tlb_entries */
static void hexagon_update_vtlb_entry_in_structure_cdsp(uint64_t tlb_phy, uint64_t tlb_virtual, uint64_t index)
{
    uint64_t mask, size = 0, virt_page, phy_page, virt_add, phy_add;
    uint8_t global_bit;
    char *page_size;
    tlb_entries_cdsp *temp = NULL;
    union pg_tlblo_t_cdsp tlblo;
    union pg_tlbhi_t_cdsp tlbhi;

    uint64_t full_phys_add = 0;

    // LOG_DEBUG("hexagon_update_vtlb_entry_in_structure_cdsp  Enter");
    if ((index >= hexagon_vtlb_data_cdsp.vtlb_no_of_entries) || (hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries >= hexagon_vtlb_data_cdsp.vtlb_no_of_entries))
    {
        // LOG_DEBUG("Index is greater than hexagon_vtlb_data_cdsp.vtlb_no_of_entries");
        return;
    }
    virt_page = VIRT_PAGE_CDSP(tlb_virtual);

    if (virt_page == 0x0)
        return;
    tlblo.raw = tlb_phy;
    tlbhi.raw = tlb_virtual;
    virt_add = virt_page << 12;
    phy_page = QURT_getPhysAddr_v2_cdsp(tlblo.raw, tlbhi.raw);
    phy_add = phy_page << 12;

    if ((virt_add == 0x0) || (phy_add == 0x0))
    {
        // LOG_DEBUG("Virtual / Physical  address is NULL for raw phy= 0x%08x and raw virtual = 0x%08x " , tlb_phy,tlb_virtual);
        return;
    }

    temp = hexagon_vtlb_entries_cdsp + hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries;
    mask = get_phys_mask_cdsp(tlb_phy);
    temp->virt_tlb_raw_data = tlb_virtual;
    temp->phys_tlb_raw_data = tlb_phy;
    temp->phy_page = phy_page;
    temp->virt_page = virt_page;
    temp->asid = ASID_CDSP(tlb_virtual);
    temp->R = P_READ_CDSP(tlb_phy);
    temp->W = P_WRITE_CDSP(tlb_phy);
    temp->X = P_EXEC_CDSP(tlb_phy);
    temp->U = P_USER_CDSP(tlb_phy);
    temp->CCCC = P_CCCC_CDSP(tlb_phy);
    temp->S = P_S_CDSP(tlb_phy);
    temp->validbit = P_V_CDSP(tlb_virtual);
    temp->globalbit = P_G_CDSP(tlb_virtual);
    temp->EP = P_EP_CDSP(tlb_virtual);
    temp->A1 = P_A1_CDSP(tlb_virtual);
    temp->A0 = P_A0_CDSP(tlb_virtual);
    page_size = PAGE_SIZE_CDSP(tlb_phy, mask);
    hexagon_vtlb_data_cdsp.valid_vtlb_no_of_entries++;

    if (strcmp(page_size, "4KB") == 0)
    {
        temp->page_size = HEXAGON_TLB_PAGE_SIZE_4KB_CDSP;
        size = HEXAGON_PAGE_SIZE_4K_CDSP - 1;
    }
    else if (strcmp(page_size, "16KB") == 0)
    {
        temp->page_size = HEXAGON_TLB_PAGE_SIZE_16KB_CDSP;
        size = HEXAGON_PAGE_SIZE_16K_CDSP - 1;
    }
    else if (strcmp(page_size, "64KB") == 0)
    {
        temp->page_size = HEXAGON_TLB_PAGE_SIZE_64KB_CDSP;
        size = HEXAGON_PAGE_SIZE_64K_CDSP - 1;
    }
    else if (strcmp(page_size, "256KB") == 0)
    {
        temp->page_size = HEXAGON_TLB_PAGE_SIZE_256KB_CDSP;
        size = HEXAGON_PAGE_SIZE_256K_CDSP - 1;
    }
    else if (strcmp(page_size, "1MB") == 0)
    {
        temp->page_size = HEXAGON_TLB_PAGE_SIZE_1MB_CDSP;
        size = HEXAGON_PAGE_SIZE_1M_CDSP - 1;
    }
    else if (strcmp(page_size, "4MB") == 0)
    {
        temp->page_size = HEXAGON_TLB_PAGE_SIZE_4MB_CDSP;
        size = HEXAGON_PAGE_SIZE_4M_CDSP - 1;
    }
    else if (strcmp(page_size, "16MB") == 0)
    {
        temp->page_size = HEXAGON_TLB_PAGE_SIZE_16MB_CDSP;
        size = HEXAGON_PAGE_SIZE_16M_CDSP - 1;
    }

    temp->virt_add_low = virt_add;
    temp->virt_add_high = virt_add + size;

    temp->phy_add_low = temp->phy_page << 12;

    temp->phy_add_high = temp->phy_add_low+ size;
    LOG_DEBUG("Phy after left shift = 0x%llx",temp->phy_add_low);
    LOG_DEBUG("Phy page address before shift = 0x%llx",temp->phy_page);
    LOG_DEBUG("index = %d, VA = 0x%lx -- 0x%lx and PA = 0x%llx -- 0x%llx", index, temp->virt_add_low,temp->virt_add_high,temp->phy_add_low,temp->phy_add_high);

    // LOG_DEBUG("hexagon_update_vtlb_entry_in_structure_cdsp Exit");
}

/* this interface is to read thebuffer via memw interface*/
static void hexagon_memw_read_buffer_cdsp(struct target *target, uint64_t virt_address, uint32_t size, uint8_t *buffer)
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
            hexagon_memw_read_cdsp(target, virt_address + 4 * i, (uint64_t *)temp);
            temp = temp + 4;
        }
    }
    else
    {
        LOG_DEBUG("size is not multiple of 4 bytes");
    }
}

/* this interface is to read the  memory via memw interface*/
static void hexagon_memw_read_cdsp(struct target *target, uint64_t virt_address, uint64_t *value)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    uint32_t isdb_mmode_cmd, isdb_cmd_status, isdbsts;
    uint64_t phy_addr;
    uint64_t stuff_inst[] = {0x6ea8c000, 0x9180c007, 0x6707c029};
    /* Stuff instruction 0x6ea8c000-->{r0 =isdbmbxin} 0x9180c007-->{r7 = memw(r0+#0) } 0x6707c029-->{isdbmbxout=r7}*/
    int retval, i;



    isdb_mmode_cmd = 0x184;

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, virt_address);
    

    if (retval != ERROR_OK)
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
    for (i = 0; i < 3; i++)
    {
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP  return value is not OK");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
            return;
        }
    }
    i = 0;
    while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
    {

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        i++;
        if (i == 10)
            break;
    }
    if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
    {
        LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
        return;
    }
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, value);

    LOG_DEBUG("value read from mbx out IS 0x%x",value);

    if (retval != ERROR_OK)
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed ");
}

/* This function is used to read memory word using memw_phys instruction
    In this function we passed the physical address as an argument*/
static void hexagon_memw_phys_read_cdsp(struct target *target, target_addr_t phy_address, uint64_t *value)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status, isdbsts;
    uint64_t phy_add[2], t_phy_address;
    uint32_t stuff_inst[] = {0x6ea8c000, 0x6ea8c001, 0x9200e107, 0x6707c029};
    int retval, i;
    // target_addr_t t_phy_address;

    /* Stuff Inst  0x6ea8c000-->{r0 = isdbmbxin} , 0x6ea8c001-->{r1 = isdbmbxin} ,0x9200e107-->{r7 = memw_phys(r0,r1)}
        0x6707c029-->{isdbmbxout = r7}  */

    t_phy_address = phy_address;
    if (t_phy_address == 0x0)
    {
        LOG_DEBUG("Physical address passed as NULL");
        return;
    }
    hexagon_r0_used_stuff_cdsp = 1;
    hexagon_r1_used_stuff_cdsp = 1;
    hexagon_r7_used_stuff_cdsp = 1;

    phy_add[0] = t_phy_address & 0x7ff;
    phy_add[1] = t_phy_address >> 11;


    LOG_DEBUG("physical address= 0x%llx phy_add[0] = 0x%x  phy_add[1] = 0x%x",phy_address, phy_add[0],phy_add[1]);
    for (i = 0; i < 2; i++)
    {
        /*	
        retval = enable_dbg_sys_pwr(swddp);
        if (retval != ERROR_OK)
                LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
        */

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, phy_add[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN_CDSP return value is not OK");

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDB command failed in monitor mode for i = %d", i);
            return;
        }
    }
    for (i = 2; i < 4; i++)
    {
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDB command failed in monitor mode for i = %d", i);
            return;
        }
    }
    i = 0;
    while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
    {

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        i++;
        if (i == 10)
            break;
        // hexagon_wait_loop_cdsp();
    }
    if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
    {
        LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it isdbsts = 0x%x", isdbsts);
        return;
    }
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, value);
    if (retval != ERROR_OK)
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed ");
}

static int hexagon_remove_breakpoint_cdsp(struct target *target, struct breakpoint *breakpoint)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
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
        hexagon_unset_breakpoint_cdsp(target, breakpoint);
        if (breakpoint->type == BKPT_HARD)
            hexagon->brp_num_available++;
    }
    return ERROR_OK;
}

static int hexagon_unset_breakpoint_cdsp(struct target *target, struct breakpoint *breakpoint)
{
    LOG_DEBUG("Entering %s\n", __FUNCTION__);
    int retval;
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct hexagon_brp_cdsp *brp_list = hexagon->brp_list;

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
            // todo: this condition is true for linked BP, Need to explore more if same is applicable for hexagon??
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
                    // HW BP 0 config
                    // todo: Migrate this work to a helper function. //bp_write_helper()
                    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                     hexa_info->debug_base + HEXAGON_ISDB_BRKPTPC0_CDSP, brp_list[brp_i].value);
                }
                else
                {
                    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                     hexa_info->debug_base + HEXAGON_ISDB_BRKPTPC1_CDSP, brp_list[brp_i].value);
                }

                if (retval != ERROR_OK)
                {
                    LOG_WARNING("BRKPTPC write failed Error code: %d", retval);
                }
                --retrycount;

            } while ((retval != ERROR_OK) && (retrycount > 0));

            if (retval != ERROR_OK)
            {
                // After 5 retries we are unable to set the HW bp then return from here
                LOG_DEBUG("BRKPTPC write failed after 5 retries 0x%llx", brp_list[brp_i].value);
                return retval;
            }

            // HW breakpoint config/settings
            retval = ERROR_OK;
            retrycount = 5;

            do
            {
                if (brp_i < 1)
                {
                    // HW BP 0 config
                    // todo: Migrate this work to a helper function. //bp_write_helper()
                    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                     hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG0_CDSP, brp_list[brp_i].control);
                }
                else
                {
                    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                     hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG1_CDSP, brp_list[brp_i].control);
                }

                if (retval != ERROR_OK)
                {
                    LOG_WARNING("BRKPTCFG write failed Error code: %d", retval);
                }
                --retrycount;

            } while ((retval != ERROR_OK) && (retrycount > 0));

            if (retval != ERROR_OK)
            {
                // if after 5 retries we are unable to set the HW bp then return from here
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
        // TODO: Delete sw bp
        union fourbyte_cdsp val;

        val.byte[0] = breakpoint->orig_instr[0];
        val.byte[1] = breakpoint->orig_instr[1];
        val.byte[2] = breakpoint->orig_instr[2];
        val.byte[3] = breakpoint->orig_instr[3];

        LOG_DEBUG("Removing brkpt, writing back breakpoint->orig_instr = 0x%x", val.word);
        retval = hexagon_memw_write_instruction_memory_cdsp(target, breakpoint->address, val.word, 1); // replacing the original instruction in place of brkpt instruction
        // todo: check the endianness
        if (retval != ERROR_OK)
            LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK");
    }
    breakpoint->is_set = 0;
    return ERROR_OK;
}

static int hexagon_add_breakpoint_cdsp(struct target *target, struct breakpoint *breakpoint)
{
    LOG_DEBUG("Entering %s\n", __FUNCTION__);
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    uint64_t bpconfig = 0;

    bpconfig |= (1 << 17); // BRKPTPC match enable
                           //	bpconfig |=(0xff<<18);	//STID match enable, if not working properly, disable it & retry. Typical STID = 0x00ff00ff
                           //	breakpoint->type = BKPT_SOFT;

    if ((breakpoint->type == BKPT_HARD) && (hexagon->brp_num_available < 1))
    {
        LOG_DEBUG("no hardware breakpoint available");
        return ERROR_TARGET_RESOURCE_NOT_AVAILABLE;
    }
    if (breakpoint->type == BKPT_HARD)
        hexagon->brp_num_available--;

    return hexagon_set_breakpoint_cdsp(target, breakpoint, bpconfig); // address match enable
}

static int hexagon_setup_isdb_config_cdsp(struct target *target, uint64_t old_isdbcfg0, uint8_t hbp_num)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    int32_t isdbcfg0 = old_isdbcfg0, retval = ERROR_OK;

    isdbcfg0 |= 0x3f3f3f;
    if (hbp_num == 0)
    {
        isdbcfg0 |= (1 << 25); // HW BP0 enable
    }
    else if (hbp_num == 1)
    {
        isdbcfg0 |= (1 << 26); // HW BP1 enable
    }

    LOG_DEBUG("Writing isdbcfg0...	 isdbcfg0 = 0x%x", isdbcfg0);

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCFG0_CDSP, isdbcfg0);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBCFG0 write failed 0x%x", isdbcfg0);
        return retval;
    }
    // disabling these lines as T32+EUD HBP logs doesn't do any write on isdbcfg1, Can enable later.
    int32_t isdbcfg1 = 0;
    retval = ERROR_OK;
    isdbcfg1 |= 0x3F3F3F00; // HW break0 & break1 TNUM mask SW Break TNUM Mask

    LOG_DEBUG("Writing isdbcfg1...	 isdbcfg1 = 0x%x", isdbcfg1);
    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCFG1_CDSP, isdbcfg1);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBCFG1 write failed 0x%x", isdbcfg1);
        return retval;
    }
    LOG_DEBUG("Write sccessful for HEXAGON_ISDB_ISDBCFG0 & HEXAGON_ISDB_ISDBCFG1");
    return ERROR_OK;
}

/** Setup hardware Breakpoint Register Pair bpconfig parameter will be considered for setting up on-chip breakpoints, otherwise ignored **/
static int hexagon_set_breakpoint_cdsp(struct target *target, struct breakpoint *breakpoint, uint64_t bpconfig)
{
    LOG_DEBUG("Entering %s\n", __FUNCTION__);
    int retval;
    int brp_i = 0;
    uint64_t control, isdbcfg0 = 0;
    uint8_t byte_addr_select = 0x0F;
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct hexagon_brp_cdsp *brp_list = hexagon->brp_list;
    struct adiv5_dap *swddp = hexa_info->dap;

    if (breakpoint->is_set)
    {
        LOG_WARNING("breakpoint already set");
        return ERROR_OK;
    }

    retval = ERROR_OK;
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBCFG0_CDSP, &isdbcfg0);
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
            LOG_DEBUG("bug: breakpoint length should be 4"); // REVIEW: Not applicable if this check has been already done, also NMI bp address can be VA, VA+ASID, PA.
            return ERROR_FAIL;
        }
        LOG_DEBUG(" %s\t :-------: %d\n", __FUNCTION__, __LINE__);

        uint64_t bpt_value; // REVIEW: can be UINT32 as VA is 32bit, & VA+ASID takes 39 bit. NMI //for now considering only VA without ASID
        LOG_DEBUG(" %s\t :-------: %d\t brp_i = %d\n", __FUNCTION__, __LINE__, brp_i);
        LOG_DEBUG(" %s\t :-------: %d\t brp_list = %x\n", __FUNCTION__, __LINE__, brp_list);
        LOG_DEBUG(" %s\t :-------: %d\t brp_list[brp_i] = %x\n", __FUNCTION__, __LINE__, brp_list[brp_i]);
        LOG_DEBUG(" %s\t :-------: %d\t brp_list[brp_i].used = %d\n", __FUNCTION__, __LINE__, brp_list[brp_i].used);

        while ((brp_list[brp_i].used) && (brp_i < hexagon->brp_num))
        { // brp_i < 2; 2 HW BP supported till hexagon V71, should have a MACRO for future versions
            brp_i++;
        }
        if (brp_i >= hexagon->brp_num)
        {
            LOG_DEBUG("ERROR Can't add more HW breakpoints");
            return ERROR_TARGET_RESOURCE_NOT_AVAILABLE;
        }
        breakpoint->is_set = brp_i + 1; // REVIEW: NMI Significance of breakpoint->is_set field, from the intuition, it should be 1/0. Keeping as it is AARCH64

        brp_list[brp_i].used = 1;
        brp_list[brp_i].value = breakpoint->address & 0xFFFFFFFFFFFFFFFC; // keeping 64 bit for now, last 2 bit is 0 for 32bit alignment
        brp_list[brp_i].control = bpconfig;                               // REVIEW: assuming this will hold the value of BRKPTCFG0/1 for HW bp
                                            //		bpt_value = brp_list[brp_i].value;

        // TODO: Check if T32 checks for system halted then sets HW BP, or during threads in RUN mode it sets the BP
        int retrycount;
        uint64_t brkptpc, brkptcfg;

        brkptpc = brkptcfg = retrycount = 0;
        retval = ERROR_OK;

        // HW breakpoint PC address write
        retrycount = 5;

        /*	retval = enable_dbg_sys_pwr(swddp);
        if (retval != ERROR_OK) {
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
        }*/
        // HW breakpoint config/settings
        retval = ERROR_OK;
        brkptcfg = brp_list[brp_i].control;
        LOG_DEBUG(" %s\t :-------: %d\t :------------: brkptcfg = %x\n", __FUNCTION__, __LINE__, brkptcfg);
        retrycount = 5;

        // retval = enable_dbg_sys_pwr(swddp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
        }
        do
        {
            if (brp_i < 1)
            {
                // HW BP 0 config
                // todo: Migrate this work to a helper function. //bp_write_helper()
                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG0_CDSP, brkptcfg);
            }
            else
            {
                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG1_CDSP, brkptcfg);
            }

            if (retval != ERROR_OK)
            {
                LOG_WARNING("BRKPTCFG write failed Error code: %d", retval);
            }
            --retrycount;

        } while ((retval != ERROR_OK) && (retrycount > 0));

        if (retval != ERROR_OK)
        {
            // if after 5 retries we are unable to set the HW bp then return from here
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
                // HW BP 0 PC
                // todo: Migrate this work to a helper function. //bp_write_helper()
                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_BRKPTPC0_CDSP, brkptpc);
                hexagon_setup_isdb_config_cdsp(target, isdbcfg0, 0);
            }
            else
            {
                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_BRKPTPC1_CDSP, brkptpc);
                hexagon_setup_isdb_config_cdsp(target, isdbcfg0, 1);
            }

            if (retval != ERROR_OK)
            {
                LOG_WARNING("BRKPTPC write failed Error code: %d", retval);
            }
            --retrycount;

        } while ((retval != ERROR_OK) && (retrycount > 0));

        if (retval != ERROR_OK)
        {
            // After 5 retries we are unable to set the HW bp then return from here
            LOG_DEBUG("BRKPTPC write failed after 5 retries 0x%x", brkptpc);
            return retval;
        }

        //	hexagon_dump_isdb_reg(&hexagon->hexa_info);
        //	hexagon_read_BRKPT_through_stuff(target);
    }
    else if (breakpoint->type == BKPT_SOFT)
    {
        retval = ERROR_OK;

        uint64_t first_instrn_addr, current_addr;
        first_instrn_addr = 0;
        current_addr = breakpoint->address;
        //		uint8_t code_arr[20]= {0};
        //		uint8_t fwd_code_arr[4]= {0};
        uint8_t bkwd_code_arr[4] = {0}, packet_counter = 0;
        union fourbyte_cdsp val;

        LOG_DEBUG("In software BP ");
        if ((breakpoint->length != 4) && (breakpoint->address == NULL))
        {
            LOG_DEBUG("bug: breakpoint length should be 4 for sw breakpoints/address should not be null");
            return ERROR_FAIL;
        }
        LOG_DEBUG("Breakpoint address received from gdb address = 0x%x", current_addr);

        val.byte[0] = val.byte[1] = val.byte[2] = val.byte[3] = 0;
        // find First instruction in the packet, There's no specific bit pattern for first instruction of current packet,
        // find out last instruction in previous packet & the next instruction will be first instruction of the current packet
        first_instrn_addr = current_addr;
        uint8_t first_instrn_found = 0;
        while (!first_instrn_found)
        {
            packet_counter++;
            first_instrn_addr -= 4; // start looking from the next address from the current instruction
            retval = ERROR_OK;
            retval = hexagon_read_buffer_cdsp(target, first_instrn_addr, 4, bkwd_code_arr);

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
        retval = hexagon_read_buffer_cdsp(target, first_instrn_addr, 4, bkwd_code_arr);
        if (retval != ERROR_OK)
            LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK retval = %d", retval);

        // replacing first instruction address instead of the breakpoint->address, because once the packet execution will start,
        // instruction decoder will pick up/decode brkpt instruction & assume that it's the only instruction in the packet.
        // so there's no need of replacing the rest of the instructions in the packet

        retval = hexagon_memw_write_instruction_memory_cdsp(target, first_instrn_addr, 0x6c20c000, 0); // value will be ignored hard coded value is 0x6c20c000	{	 brkpt }
        if (retval != ERROR_OK)
            LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK");

        // Modifying the breakpoint attributes passed by GDB.
        // Todo: verify this
        // orig_instr[0-3] = bkwd_code_arr[0-3]
        breakpoint->is_set = 1;
        memcpy(breakpoint->orig_instr, bkwd_code_arr, 4);
        breakpoint->address = first_instrn_addr;

        hexagon_setup_isdb_config_cdsp(target, isdbcfg0, 0xFF);

        // debug purpose to check if the brkpt instruction is written correctly.

        retval = ERROR_OK;
        retval = hexagon_read_buffer_cdsp(target, first_instrn_addr, 4, bkwd_code_arr);

        if (retval != ERROR_OK)
        {
            LOG_DEBUG("hexagon_memw_read_instruction_memory return value is not OK retval = %d", retval);
        }
        LOG_DEBUG("Debug: after writing breakpoint The Opcode present at address 0x%x is 0x%x%x%x%x", first_instrn_addr, bkwd_code_arr[3], bkwd_code_arr[2], bkwd_code_arr[1], bkwd_code_arr[0]);

        //		buf_set_u32(code, 0, 32, opcode);
        /*
         * //TODO: 0x6c20c000  {	brkpt } opcode for brkpt instruction, Prior to this ISDBCFG1[11:8] SWBRKPT TNUM mask should be programmed correctly
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
    return retval;
}

/*This function write to instruction memory in this function if flag is passed as 1 means we are passing the value to write otherwise
we need to use the brpkt instruction opcode to write into the meory*/

static int hexagon_memw_write_instruction_memory_cdsp(struct target *target, uint64_t virt_address, uint32_t value, uint8_t flag)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status, isdbsts;
    uint64_t stuff_inst[] = {0x6ea8c000, 0x6ea8c007, 0xa180c700, 0xa000c000, 0xa800c000, 0x56c0c000, 0x57c0c002};
    uint64_t address[2];
    int retval, i;
    target_addr_t phy_addr = 0;

    /* Stuff instruction
    0x6ea8c000-->{r0 = isdbmbxin } 0x6ea8c007-->{r7 = isdbmbxin } 0xa180c700-->{memw(r0+#0) = r7}
    0xa000c000-->{dccleana(r0) } 0xa800c000-->{barrier } 0x56c0c000-->{icinva(r0) } 0x57c0c002-->{isync} */

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    LOG_DEBUG("hexagon_memw_write_instruction_memory_cdsp  Enter");

    retval = hexagon_virt2phys_cdsp(target, virt_address, &phy_addr);
    if (retval == ERROR_FAIL)
    {
        LOG_DEBUG("There is no TLB mapping for virtual address  = 0x%x ", (uint64_t)address);
        return retval;
    }
    hexagon_r0_used_stuff_cdsp = 1;
    hexagon_r7_used_stuff_cdsp = 1;
    if (!flag)
        value = 0x6c20c000; // brpkt instruction opcode

    address[0] = virt_address;
    address[1] = value;

    LOG_DEBUG("virt_address =  0x%x and value = 0x%x", virt_address, value);
    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK)
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");*/

    for (i = 0; i < 2; i++)
    {
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, address[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
            return ERROR_FAIL;
        }
    }

    for (i = 2; i < 7; i++)
    {
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            return ERROR_FAIL;
        }
    }
#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif

    LOG_DEBUG("hexagon_memw_write_instruction_memory_cdsp Exit");
    return ERROR_OK;
}

static int hexagon_write_buffer_cdsp(struct target *target, target_addr_t address,
                                     uint32_t size, const uint8_t *buffer)
{
    int retval = ERROR_OK;
    target_addr_t phy_addr = 0;
    uint32_t value;

    if (address == 0x0)
    {
        LOG_DEBUG("Virtual address passed as NULL");
        return ERROR_FAIL;
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    retval = hexagon_virt2phys_cdsp(target, address, &phy_addr);
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("address  = 0x%x and size = %u , phy add = 0x%x", (uint64_t)address, size, (uint64_t)phy_addr);
#endif

    if (retval == ERROR_FAIL)
    {
        LOG_DEBUG("There is no TLB mapping for virtual address	= 0x%x ", (uint64_t)address);
        return retval;
    }
    if (size == 3)
    {
        memcpy(&value, buffer, 2);
        retval = hexagon_memw_write_cdsp(target, address, value, 2);
        value = 0;
        memcpy(&value, buffer[2], 1);
        retval = hexagon_memw_write_cdsp(target, address, value, 1);
    }
    else if (size <= 4)
    {
        memcpy(&value, buffer, size);
        retval = hexagon_memw_write_cdsp(target, address, value, size);
    }
    else if ((size % 4) == 0)
    {
        retval = hexagon_memw_write_buffer_cdsp(target, address, size, buffer);
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif
    return retval;
}

/*this function is use to write memory buffer using memw interface */
static int hexagon_memw_write_buffer_cdsp(struct target *target, uint64_t virt_address, uint32_t size, const uint8_t *buffer)
{
    uint32_t count, i, value, retval = ERROR_OK;
    uint8_t *temp;

    count = size / 4;
    temp = buffer;
    for (i = 0; i < count; i++)
    {
        memcpy(&value, temp, 4);
        retval = hexagon_memw_write_cdsp(target, virt_address + 4 * i, value, 4);
        temp = temp + 4;
    }
    return retval;
}

/*This function used to write memory using memw interface  */
static int hexagon_memw_write_cdsp(struct target *target, uint64_t virt_address, uint32_t value, uint32_t size)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status, isdbsts, sys_cfg;
    uint32_t stuff_inst[] = {0x6ea8c000, 0x6ea8c007, 0xa180c700, 0xa000c000, 0xa800c000, 0xa840c000};
    uint64_t address[2];
    int retval, i = 0;

    /* Stuff inst  0x6ea8c000-->{r0 = isdbmbxin }0x6ea8c007-->{r7 = isdbmbxin}
       0xa180c700-->{memw(r0+#0) = r7 } 0xa000c000-->{dccleana(r0) } 0xa800c000-->{barrier } 0xa840c000-->{syncht } */

    LOG_DEBUG("hexagon_memw_write_cdsp Enter");

    if (size == 1)
        stuff_inst[2] = 0xa100c700; /* {memb(r0+#0) = r7} */

    if (size == 2)
        stuff_inst[2] = 0xa140c700; /* {memh(r0+#0) = r7} */

    address[0] = virt_address;
    address[1] = value;

    LOG_DEBUG("value = 0x%x", value);
    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK)
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK"); */

    hexagon_r0_used_stuff_cdsp = 1;
    hexagon_r7_used_stuff_cdsp = 1;

    retval = hexagon_read_syscfg_register_cdsp(target);
    if (retval == ERROR_OK)
    {
        sys_cfg = hexagon_syscfg_reg_cdsp;
        sys_cfg = sys_cfg | SYSCFG_L2NRA_CDSP | SYSCFG_L2NWA_CDSP;
        sys_cfg = sys_cfg & ~(SYSCFG_L2WB_CDSP);
        LOG_DEBUG("Writing value in SYSCFG  = 0x%x ", sys_cfg);
        hexagon_write_syscfg_register_cdsp(target, sys_cfg);
        // hexagon_wait_loop();
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, 0xa840c000);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
            return ERROR_FAIL;
        }
    }
    for (i = 0; i < 2; i++)
    {
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, address[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode for i = %d", i);
            return ERROR_FAIL;
        }
    }
    for (i = 2; i < 6; i++)
    {
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDB command failed in monitor mode");
            return ERROR_FAIL;
        }
    }
    LOG_DEBUG("hexagon_memw_write_cdsp  Exit");
    return ERROR_OK;
}

static int hexagon_read_buffer_cdsp(struct target *target, target_addr_t address,
                                    uint32_t size, uint8_t *buffer)
{
    int retval = ERROR_OK;
    long long int phy_addr = 0;
    uint32_t value;
    long long int temp_phy_addr = 0;

    start_buffer = clock();

    if (address == 0x0)
    {
        LOG_DEBUG("Virtual address passed as NULL");
        return ERROR_FAIL;
    }
#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    retval = hexagon_virt2phys_cdsp(target, address, &phy_addr);
    // LOG_DEBUG("hexagon_read_buffer_cdsp address  = 0x%x and size = %u , phy add = 0x%lx", (uint32_t)address, size, (uint32_t)phy_addr);

    if (retval == ERROR_FAIL)
    {
        LOG_DEBUG("There is no TLB mapping for virtual address	= 0x%x ", (uint32_t)address);
        return retval;
    }

    if (size < 4)
    {
        hexagon_memw_phys_read_cdsp(target, phy_addr, &value);
        	// hexagon_memw_read_cdsp(target, address, &value);
        //	LOG_DEBUG("retrieved value using  hexagon_memw_phys_read for size < 4  = 0x%x ", value);
        switch (size)
        {
        case 1:
            buffer[0] = (uint8_t)(value >> 0);
            break;
        case 2:
            target_buffer_set_u16(target, buffer, value);
            break;
        case 3:
            target_buffer_set_u24(target, buffer, value);
            break;
        }
    }
    else if (size == 4)
    {
        // hexagon_memw_read_cdsp(target, address, &value);
        hexagon_memw_phys_read_cdsp(target, phy_addr, &value);
        //	LOG_DEBUG("retrieved value using  hexagon_memw_phys_read = 0x%x ", value);
        target_buffer_set_u32(target, buffer, value);
    }
    else if ((size % 4) == 0)
    {
        hexagon_memw_phys_read_buffer_cdsp(target, phy_addr, size, buffer);
        // hexagon_memw_read_buffer_cdsp(target, address,size, buffer);
    }


    end_buffer = clock();
    buffer_execution = ((double)(end_buffer - start_buffer))/CLOCKS_PER_SEC;
    LOG_INFO("AFTER read_buffer %lf", buffer_execution);

    return retval;
}

/* This function is used to read memory of request size using memw_phys  instruction
    In this function we passed the physical address as an argument */
static void hexagon_memw_phys_read_buffer_cdsp(struct target *target, target_addr_t phy_address, uint32_t size, uint8_t *buffer)
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
            hexagon_memw_phys_read_cdsp(target, phy_address + 4 * i, (uint64_t *)temp);
            temp = temp + 4;
        }
    }
    else
    {
        LOG_DEBUG("size is not multiple of 4 bytes");
    }
}

static int hexagon_read_syscfg_register_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    int retval, i = 0;
    uint32_t isdbsts,isdb_mmode_cmd, isdb_cmd_status;
    /*Stuff inst  {r7 = syscfg}  {isdbmbxout = r7} */

    hexagon_r7_used_stuff_cdsp = 1;
    // LOG_DEBUG("Enter in hexagon_read_syscfg_register_cdsp");

    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                               ISDBCMD_TNUM_MASK_THREAD_CDSP(0));

    /* Monitor mode */
    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK)
        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");*/

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, 0x6e92c007);
    if (retval != ERROR_OK)
        LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
    if (retval != ERROR_OK)
        LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

    /* wait till the stuff instruction is executed */
    hexagon_wait_loop_cdsp();

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

    /* 0 - cmd sucessfull, 1 - failure */
    isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
    if (isdb_cmd_status)
    {
        LOG_DEBUG("ISDBcommand failed in monitor mode");
        return ERROR_OK;
    }
    /*there are 2 stuff instruction here programming second inst */
    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK)
        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK"); */

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, 0x6707c029);
    if (retval != ERROR_OK)
        LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);

    if (retval != ERROR_OK)
        LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

    /* wait till the stuff instruction is executed */
    hexagon_wait_loop_cdsp();

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

    if (retval != ERROR_OK)
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

    /* 0 - cmd success, 1 - cmd failure */
    isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
    if (isdb_cmd_status)
    {
        LOG_DEBUG("ISDBcommand failed in monitor mode");
        return ERROR_OK;
    }
    while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
    {
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

        //	hexagon_wait_loop_cdsp();

        i++;
        if (i == 10)
            break;
    }

    if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
    {
        LOG_DEBUG("ISDBST status not set for mailbox so skiping reading SYSCFG register ");
        return ERROR_FAIL;
    }
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &hexagon_syscfg_reg_cdsp);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT_CDSP read failed 0x%x", hexagon_syscfg_reg_cdsp);
    }
    // LOG_DEBUG("SYSCFG register value =  0x%x", hexagon_syscfg_reg_cdsp);

    return ERROR_OK;
}

/* This function is used to write value in syscfg register */
static int hexagon_write_syscfg_register_cdsp(struct target *target, uint32_t value)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    int retval, i;
    uint32_t isdbsts;
    uint32_t isdb_mmode_cmd, isdb_cmd_status;
    uint32_t stuff_inst[] = {0x6ea8c007, 0x6707c012, 0x57c0c002, 0xa840c000};
    /* Stuff instruction  0x6ea8c007-->{r7 = isdbmbxin } 0x6707c012-->{syscfg = r7} 0x57c0c002--> { isync }, 0xa840c000-->  { syncht } */

    hexagon_r7_used_stuff_cdsp = 1;
    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                               ISDBCMD_TNUM_MASK_THREAD_CDSP(0));

    /* Monitor mode */
    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK)
        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");*/

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, value);
    if (retval != ERROR_OK)
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN_CDSP return value is not OK");

    for (i = 0; i < 4; i++)
    {
        /*retval = enable_dbg_sys_pwr(swddp);
        if (retval != ERROR_OK)
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK"); */
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[i]);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        /* 0 - cmd sucessfull, 1 - failure */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            return ERROR_FAIL;
        }
    }
    return ERROR_OK;
}

/* This function is used to restore r0, r1, r2 and r7 used during stuff instrcution*/
static void hexagon_stuff_reg_restore_r0_r1_r2_r7_cdsp(struct target *target)
{
    int retval;

    if (hexagon_r0_used_stuff_cdsp)
    {
        retval = hexagon_write_gpr_register_cdsp(target, HEXAGON_R0_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                                 gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R0_CDSP]);
        if (retval == ERROR_OK)
            hexagon_r0_used_stuff_cdsp = 0;
        else
        {
            retval = hexagon_write_gpr_register_cdsp(target, HEXAGON_R0_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                                     gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R0_CDSP]);
            if (retval == ERROR_OK)
                hexagon_r0_used_stuff_cdsp = 0;
            else
                LOG_DEBUG("Error occured during restoring R0 value used for stuff ");
        }
    }
    if (hexagon_r1_used_stuff_cdsp)
    {
        retval = hexagon_write_gpr_register_cdsp(target, HEXAGON_R1_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                                 gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R1_CDSP]);
        if (retval == ERROR_OK)
            hexagon_r1_used_stuff_cdsp = 0;
        else
        {
            retval = hexagon_write_gpr_register_cdsp(target, HEXAGON_R1_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                                     gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R1_CDSP]);
            if (retval == ERROR_OK)
                hexagon_r1_used_stuff_cdsp = 0;
            else
                LOG_DEBUG("Error occured during restoring R1 value used for stuff ");
        }
    }
    if (hexagon_r2_used_stuff_cdsp)
    {
        retval = hexagon_write_gpr_register_cdsp(target, HEXAGON_R2_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                                 gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R2_CDSP]);
        if (retval == ERROR_OK)
            hexagon_r2_used_stuff_cdsp = 0;
        else
        {
            retval = hexagon_write_gpr_register_cdsp(target, HEXAGON_R2_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                                     gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R2_CDSP]);
            if (retval == ERROR_OK)
                hexagon_r2_used_stuff_cdsp = 0;
            else
                LOG_DEBUG("Error occured during restoring R2 value used for stuff ");
        }
    }
    if (hexagon_r7_used_stuff_cdsp)
    {
        retval = hexagon_write_gpr_register_cdsp(target, HEXAGON_R7_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                                 gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R7_CDSP]);
        if (retval == ERROR_OK)
            hexagon_r7_used_stuff_cdsp = 0;
        else
        {
            retval = hexagon_write_gpr_register_cdsp(target, HEXAGON_R7_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                                     gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R7_CDSP]);
            if (retval == ERROR_OK)
                hexagon_r7_used_stuff_cdsp = 0;
            else
                LOG_DEBUG("Error occured during restoring R7 value used for stuff ");
        }
    }
}

/* This function is used to restore r0, r1 and r7 used during stuff */
static void hexagon_stuff_reg_restore_r0_r1_r7_cdsp(struct target *target)
{
    hexagon_write_gpr_register_cdsp(target, HEXAGON_R0_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                    gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R0_CDSP]);
    hexagon_write_gpr_register_cdsp(target, HEXAGON_R1_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                    gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R1_CDSP]);
    hexagon_write_gpr_register_cdsp(target, HEXAGON_R7_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                    gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R7_CDSP]);
}

/* This function is used to restore r7 used during stuff */
static void hexagon_stuff_reg_restore_r7_cdsp(struct target *target)
{
    hexagon_write_gpr_register_cdsp(target, HEXAGON_R7_CDSP, HEXAGON_HW_THREAD0_CDSP,
                                    gpPerHwThrdReg_cdsp[HEXAGON_HW_THREAD0_CDSP][HEXAGON_R7_CDSP]);
}

static int hexagon_read_memory_cdsp(struct target *target, target_addr_t address,
                                    uint32_t size, uint32_t count, uint8_t *buffer)
{
    int retval = ERROR_OK;
    LOG_DEBUG("  address  = 0x%x and size = %u,count=%u  ", (uint64_t)address, size, count);
    return retval;
}

static int hexagon_write_memory_cdsp(struct target *target, target_addr_t address,
                                     uint32_t size, uint32_t count, const uint8_t *buffer)
{
    int retval = ERROR_OK;
    LOG_DEBUG("  address  = 0x%x and size = %u,count=%u  ", (uint64_t)address, size, count);
    return retval;
}

int hexagon_get_gdb_reg_list_cdsp(struct target *target,
                                  struct reg **reg_list[], int *reg_list_size,
                                  enum target_register_class reg_class)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache, *global;

    int i, x;

    //  LOG_DEBUG("hexagon_get_gdb_reg_list_cdsp  enter");
    // LOG_INFO("Creating Hexagon register list for target %s", target_name(target));

    switch (reg_class)
    {
    case REG_CLASS_GENERAL:
        *reg_list_size = HEXAGON_GPR_REGS_CDSP * 2; // try with 1 hw thread.
        *reg_list = malloc(sizeof(struct reg *) * (*reg_list_size));
        memset(*reg_list, 0, sizeof(struct reg *) * (*reg_list_size));
        /* dump GPR for all Hw thread */
        x = 0;
        cache = hexa_info->core_cache;
        while ((cache->next != NULL) && (x < *reg_list_size))
        {
            for (i = 0; i < HEXAGON_GPR_REGS_CDSP; i++)
            {
                (*reg_list)[x++] = hexagon_reg_current_cdsp(hexa_info, i, cache);
            }
            cache = cache->next;
        }
        return ERROR_OK;

    case REG_CLASS_ALL:

        /** dump all registers of all HW thrd */
        *reg_list_size = (HEXAGON_VALID_PER_THREAD_REGS_CDSP + HEXAGON_VALID_GLOBAL_REGS_CDSP) * gHexConfig_cdsp.maxHwThreads;
        *reg_list = malloc(sizeof(struct reg *) * (*reg_list_size));
        memset(*reg_list, 0, sizeof(struct reg *) * (*reg_list_size));
        // LOG_DEBUG("hexagon_get_gdb_reg_list_cdsp  after malloc");

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
            for (i = 0; (i < HEXAGON_PER_THREAD_REGS_CDSP) && (x < *reg_list_size); i++)
            {
                /* skip reserve registers */
                if ((i == HEXAGON_C5_RESRV_CDSP) || (i >= HEXAGON_C20_RESRV_CDSP && i <= HEXAGON_C29_RESRV_CDSP) ||
                    (i >= HEXAGON_S12_RESRV_CDSP && i <= HEXAGON_S15_RESRV_CDSP))
                    continue;

                (*reg_list)[x++] = hexagon_reg_current_cdsp(hexa_info, i, cache);
            }

            /* reg_list[65] - reg_list[77],excluding reserved regs */
            for (; (i < HEXAGON_MMODE_GLOBAL_MAX_CDSP) && (x < *reg_list_size); i++)
            {
                /* skip reserve registers */
                if ((i == HEXAGON_S19_RESRV_CDSP) || (i == HEXAGON_S24_RESRV_CDSP) ||
                    (i == HEXAGON_S26_RESRV_CDSP))
                    continue;

                (*reg_list)[x++] = hexagon_reg_current_cdsp(hexa_info, (i - HEXAGON_EVB_CDSP), global);
            }

            cache = cache->next;
        }
        //	  LOG_INFO("Hexagon.c  hexagon_get_gdb_reg_list_cdsp REG_CLASS_ALL  exit");
        return ERROR_OK;

    default:
        LOG_DEBUG("not a valid register class type in query.");
        return ERROR_FAIL;
    }
}

const char *hexagon_get_gdb_arch_cdsp(struct target *target)
{
    return "hexagon_cdsp";
}

static int hexagon_halt_cdsp(struct target *target)
{
    static uint8_t vtlb_initialized = 0;
    int retval = ERROR_OK;
    uint64_t debug_thread, prev_target_state, counter = 0, sys_cfg;
    bool halted;
    halted = debug_thread = 0;
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;

    int64_t now, then = timeval_ms();
    LOG_DEBUG("hexagon_halt_cdsp");

    // retval = enable_dbg_sys_pwr(swddp);
    retval = hexagon_check_state_one_cdsp(target, ISDBST_DEBUG_MODE_STATUS_CDSP, &halted, &debug_thread);
    if (halted == false)
    {
        retval = hexagon_init_debug_access_cdsp(target);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("hexagon_init_debug_access_cdsp API  failed");
            return retval;
        }
        prev_target_state = target->state;
        retval = hexagon_check_state_one_cdsp(target, ISDBST_DEBUG_MODE_STATUS_CDSP, &halted, &debug_thread);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("hexagon_check_state_one_cdsp API	failed");
            return retval;
        }
        if (halted == true)
        {
            /* We have a halting debug event */
            target->state = TARGET_HALTED;
            // enum target_debug_reason debug_reason = target->debug_reason;

#ifdef _VTLB_ENABLED_CDSP
            if (!vtlb_initialized)
            {
                hexagon_populate_vtlb_data_cdsp(target);
                if (hexagon_vtlb_data_cdsp.vtlb_no_of_entries > 0)
                    vtlb_initialized = 1;
            }
#endif

            LOG_DEBUG("hexagon_halt_cdsp  target->debug_reason =%d", target->debug_reason);
            hexagon_read_current_registers_cdsp(target, gHexConfig_cdsp.maxHwThreads);
            //	LOG_DEBUG("Target %s halted and PC 0x%x", target_name(target),hexagon_print_pc(target));
            LOG_DEBUG("Target %s halted ", target_name(target));

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
        LOG_DEBUG("hexagon_halt_cdsp foor loop enter");
        if (counter > 20)
            break;
        retval = hexagon_check_state_one_cdsp(target, ISDBST_DEBUG_MODE_STATUS_CDSP, &halted, &debug_thread);
        if ((retval != ERROR_OK) || (halted == true))
            break;
        // then += 50000;
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
    /* need to enable this code part later */
    retval = hexagon_read_syscfg_register_cdsp(target);
    if (retval == ERROR_OK)
    {
        sys_cfg = hexagon_syscfg_reg_cdsp;
        sys_cfg = sys_cfg | SYSCFG_L2NRA_CDSP | SYSCFG_L2NWA_CDSP;
        sys_cfg = sys_cfg & ~(SYSCFG_L2WB_CDSP);
        // LOG_DEBUG("Writing value in SYSCFG  = 0x%x ", sys_cfg);
        hexagon_write_syscfg_register_cdsp(target, sys_cfg);
    }
#ifdef _VTLB_ENABLED_CDSP
    if (vtlb_initialized > 1)
    {
        hexagon_populate_vtlb_refresh_entries_cdsp(target);
    }
    else
    {
        if (hexagon_vtlb_data_cdsp.vtlb_no_of_entries > 0)
            vtlb_initialized++;
    }
#endif
    return retval;
}

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
void hexagon_start_time_cal_ms_cdsp(void)
{

    hexagon_time_start_cdsp = timeval_ms();
}

void hexagon_end_time_cal_ms_cdsp(void)
{

    hexagon_time_total_cdsp = timeval_ms() - hexagon_time_start_cdsp;
}
#endif

int hexagon_read_tlb_entry_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    //	struct adiv5_dap *swddp = hexa_info->dap;
    uint32_t isdbsts;
    uint64_t read_val[1][2];
    int retval, i = 0, k = 0;
    uint32_t isdb_mmode_cmd = 0x184, isdb_cmd_status;
    uint32_t stuff_inst[1][4] = {{0x7800c022, 0x6c42c000, 0x6700c029, 0x6701c029}};
    /*stuff inst 0x7800c022-->{r2 = #1},0x6c42c000-->{r1:0 = tlbr(r2)},0x6700c029-->{isdbmbxout = r0},0x6701c029-->{isdbmbxout = r1 } */

    LOG_DEBUG("hexagon_read_tlb_entry_cdsp Enter");

    hexagon_r0_used_stuff_cdsp = 1;
    hexagon_r1_used_stuff_cdsp = 1;
    hexagon_r2_used_stuff_cdsp = 1;

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    for (k = 0; k < gHexConfig_cdsp.numTlbEntries; k++)
    {
        /*	retval = enable_dbg_sys_pwr(swddp);
                if (retval != ERROR_OK) {
                    LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
                }*/
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[0][0] + k * 0x20);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");
        }
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
        }
        
        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            continue;
        }

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[0][1]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        }
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
        }
        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            continue;
        }

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[0][2]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");
        }
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
        }

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        }

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode for k = %d", k);
            continue;
        }
        while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
        {

            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            i++;
            if (i == 10)
                break;
            //	hexagon_wait_loop_cdsp();
        }

        i = 0;
        if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
        {
            LOG_DEBUG("ISDBST status not set for mailbox for k= %d", k);
            continue;
        }

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &read_val[0][0]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT_CDSP read failed 0x%x", read_val[0][0]);
        }

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        // LOG_DEBUG("hexagon_read_tlb_entry  ISDBST status after reading MBXOUT = 0x%x", isdbsts);
        // LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", read_val[0]);

        /* procedure to read the second time mailbox resgiter*/
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[0][3]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");
        }
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
        }

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        }

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode for k = %d", k);
            continue;
        }

        while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
        {
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

            i++;
            if (i == 10)
                break;
            // hexagon_wait_loop_cdsp();
        }
        i = 0;
        if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
        {
            LOG_DEBUG("ISDBST status not set for mailbox for k= %d", k);
            continue;
        }

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &read_val[0][1]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT_CDSP read failed 0x%x", read_val[0][1]);
        }
        hexagon_update_tlb_entry_in_structure_cdsp(read_val[0][0], read_val[0][1], k);
    }
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    LOG_DEBUG("hexagon_read_tlb_entry  ISDBST status after reading MBXOUT = 0x%x", isdbsts);
    // LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", read_val[1]);

    LOG_DEBUG("Printing TLB Entries");
    for (k = 0; k < gHexConfig_cdsp.numTlbEntries; k++)
    {
        LOG_DEBUG("VA raw = 0x%x --> PA raw  = 0x%x ", gpHexagonTlbEntries_cdsp[k].virt_tlb_raw_data, gpHexagonTlbEntries_cdsp[k].phys_tlb_raw_data);
        /*	LOG_DEBUG("VA = 0x%x --> PA = 0x%x and page size = %d", gpHexagonTlbEntries_cdsp[k].virt_page,gpHexagonTlbEntries_cdsp[k].phy_page,
                        gpHexagonTlbEntries_cdsp[k].page_size); */
        LOG_DEBUG("VA = 0x%lx -- 0x%lx and PA = 0x%llx -- 0x%llx", gpHexagonTlbEntries_cdsp[k].virt_add_low,
                  gpHexagonTlbEntries_cdsp[k].virt_add_high, gpHexagonTlbEntries_cdsp[k].phy_add_low, gpHexagonTlbEntries_cdsp[k].phy_add_high);
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif
    LOG_DEBUG("hexagon_read_tlb_entry_cdsp Exit");
    return ERROR_OK;
}

static unsigned int QURT_getPhysAddr_v2_cdsp(uint64_t pg_tlblo, uint64_t pg_tlbhi)
{
    union pg_tlblo_t_cdsp tlblo;
    union pg_tlbhi_t_cdsp tlbhi;
    tlblo.raw = pg_tlblo;
    tlbhi.raw = pg_tlbhi;
    return ((hexagon_clrbit_cdsp((unsigned int)tlblo.info.phys_addr + ((unsigned int)tlbhi.info.ep << 24),
                                 (unsigned int)(hexagon_ct0_cdsp((unsigned int)tlblo.info.phys_addr & 0x7f))) >>
             1) &
            0xffffff);
}

static unsigned int hexagon_clrbit_cdsp(unsigned int d, unsigned int bit)
{
    return (d & (~(1 << bit)));
}

static unsigned int hexagon_ct0_cdsp(unsigned int d)
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

/* this function is related to page table and get the mask from physical page */
unsigned int get_phys_mask_cdsp(unsigned int tlblo)
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

unsigned int get_phys_page_cdsp(unsigned int lo, unsigned int hi, unsigned int mask)
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

/* this function update the tlb entry in global structure  hexagon_tlb_entries */
static void hexagon_update_tlb_entry_in_structure_cdsp(uint64_t tlb_phy, uint64_t tlb_virtual, uint64_t index)
{
    //san:
    uint64_t mask, size = 0, virt_add, phy_add;
    char *page_size;
    static int i;

    union pg_tlblo_t_cdsp tlblo;
    union pg_tlbhi_t_cdsp tlbhi;

    if (index >= gHexConfig_cdsp.numTlbEntries)
    {
        LOG_DEBUG("Index is greater than HEXAGON_TLB_ENTRIES_NUM");
        return;
    }

    tlblo.raw = tlb_phy;
    tlbhi.raw = tlb_virtual;
    gpHexagonTlbEntries_cdsp[index].phy_page = QURT_getPhysAddr_v2_cdsp(tlb_phy, tlb_virtual);
    gpHexagonTlbEntries_cdsp[index].virt_page = VIRT_PAGE_CDSP(tlb_virtual);
    virt_add = gpHexagonTlbEntries_cdsp[index].virt_page << 12;
    phy_add = gpHexagonTlbEntries_cdsp[index].phy_page << 12;
    if ((virt_add == 0x0) || (phy_add == 0x0))
    {
        return;
    }
    // LOG_DEBUG("tlb_phy = 0x%x , tlb_virtual = 0x%x  ", tlblo.raw ,tlbhi.raw  );
    // LOG_DEBUG("tlblo.phys_addr = 0x%x , tlbhi.vir_addr = 0x%x  ", tlblo.info.phys_addr ,tlbhi.info.vir_addr  );
    if (!i)
    {
        LOG_DEBUG("size of  tlb_entries_cdsp  = 0x%x  ", sizeof(tlb_entries_cdsp));
        i++;
    }

    mask = get_phys_mask_cdsp(tlb_phy);
    gpHexagonTlbEntries_cdsp[index].virt_tlb_raw_data = tlb_virtual;
    gpHexagonTlbEntries_cdsp[index].phys_tlb_raw_data = tlb_phy;
    // gpHexagonTlbEntries_cdsp[index].phy_page = get_phys_page(tlb_phy, tlb_virtual, mask);
    gpHexagonTlbEntries_cdsp[index].asid = ASID_CDSP(tlb_virtual);
    gpHexagonTlbEntries_cdsp[index].R = P_READ_CDSP(tlb_phy);
    gpHexagonTlbEntries_cdsp[index].W = P_WRITE_CDSP(tlb_phy);
    gpHexagonTlbEntries_cdsp[index].X = P_EXEC_CDSP(tlb_phy);
    gpHexagonTlbEntries_cdsp[index].U = P_USER_CDSP(tlb_phy);
    gpHexagonTlbEntries_cdsp[index].CCCC = P_CCCC_CDSP(tlb_phy);
    gpHexagonTlbEntries_cdsp[index].S = P_S_CDSP(tlb_phy);
    gpHexagonTlbEntries_cdsp[index].validbit = P_V_CDSP(tlb_virtual);
    gpHexagonTlbEntries_cdsp[index].globalbit = P_G_CDSP(tlb_virtual);
    gpHexagonTlbEntries_cdsp[index].EP = P_EP_CDSP(tlb_virtual);
    gpHexagonTlbEntries_cdsp[index].A1 = P_A1_CDSP(tlb_virtual);
    gpHexagonTlbEntries_cdsp[index].A0 = P_A0_CDSP(tlb_virtual);
    page_size = PAGE_SIZE_CDSP(tlb_phy, mask);

    LOG_DEBUG("SID = 0x%lx ", gpHexagonTlbEntries_cdsp[index].asid);
    LOG_DEBUG("virt_add = 0x%lx ", virt_add);
    LOG_DEBUG("phys_add = 0x%lx ", phy_add);


    //     virt_add = gpHexagonTlbEntries_cdsp[index].virt_page << 12;
    // phy_add = gpHexagonTlbEntries_cdsp[index].phy_page << 12;

    if (strcmp(page_size, "4KB") == 0)
    {
        gpHexagonTlbEntries_cdsp[index].page_size = HEXAGON_TLB_PAGE_SIZE_4KB_CDSP;
        size = HEXAGON_PAGE_SIZE_16K_CDSP - 1;
    }
    else if (strcmp(page_size, "16KB") == 0)
    {
        gpHexagonTlbEntries_cdsp[index].page_size = HEXAGON_TLB_PAGE_SIZE_16KB_CDSP;
        size = HEXAGON_PAGE_SIZE_16K_CDSP - 1;
    }
    else if (strcmp(page_size, "64KB") == 0)
    {
        gpHexagonTlbEntries_cdsp[index].page_size = HEXAGON_TLB_PAGE_SIZE_64KB_CDSP;
        size = HEXAGON_PAGE_SIZE_64K_CDSP - 1;
    }
    else if (strcmp(page_size, "256KB") == 0)
    {
        gpHexagonTlbEntries_cdsp[index].page_size = HEXAGON_TLB_PAGE_SIZE_256KB_CDSP;
        size = HEXAGON_PAGE_SIZE_256K_CDSP - 1;
    }
    else if (strcmp(page_size, "1MB") == 0)
    {
        gpHexagonTlbEntries_cdsp[index].page_size = HEXAGON_TLB_PAGE_SIZE_1MB_CDSP;
        size = HEXAGON_PAGE_SIZE_1M_CDSP - 1;
    }
    else if (strcmp(page_size, "4MB") == 0)
    {
        gpHexagonTlbEntries_cdsp[index].page_size = HEXAGON_TLB_PAGE_SIZE_4MB_CDSP;
        size = HEXAGON_PAGE_SIZE_4M_CDSP - 1;
    }
    else if (strcmp(page_size, "16MB") == 0)
    {
        gpHexagonTlbEntries_cdsp[index].page_size = HEXAGON_TLB_PAGE_SIZE_16MB_CDSP;
        size = HEXAGON_PAGE_SIZE_16M_CDSP - 1;
    }
    gpHexagonTlbEntries_cdsp[index].virt_add_low = gpHexagonTlbEntries_cdsp[index].virt_page << 12;
    gpHexagonTlbEntries_cdsp[index].virt_add_high = gpHexagonTlbEntries_cdsp[index].virt_add_low + size;
    gpHexagonTlbEntries_cdsp[index].phy_add_low = gpHexagonTlbEntries_cdsp[index].phy_page << 12;
	gpHexagonTlbEntries_cdsp[index].phy_add_high = (gpHexagonTlbEntries_cdsp[index].phy_add_low) + size;
    
    LOG_DEBUG("Phy page address left shift = 0x%lx", gpHexagonTlbEntries_cdsp[index].phy_page);

    LOG_DEBUG("Phy page address left shift = 0x%lx", gpHexagonTlbEntries_cdsp[index].phy_add_low);


    LOG_DEBUG("index = %d, VA = 0x%lx -- 0x%lx and PA = 0x%llx -- 0x%llx",index, gpHexagonTlbEntries_cdsp[index].virt_add_low,gpHexagonTlbEntries_cdsp[index].virt_add_high,gpHexagonTlbEntries_cdsp[index].phy_add_low,gpHexagonTlbEntries_cdsp[index].phy_add_high);
}
static int hexagon_dump_hwthrd_reg_cdsp(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;

    struct reg_cache *cache;
    uint64_t i;
    uint64_t current_pc_thread_select;

    if (hwthrd == gHexConfig_cdsp.maxHwThreads)
    {
        /* dump registers for all Hw thread */
        cache = hexa_info->core_cache;
        while (cache->next != NULL)
        {
            for (i = 0; i < HEXAGON_PER_THREAD_REGS_CDSP; i++)
            {
                current_pc_thread_select = *((uint64_t *)cache->reg_list[41].value);

                if ((current_pc_thread_select == breakpoint_address_thread_select))
                {   
                    thread_id_thread_select = *((uint64_t *)cache->reg_list[72].value);
                    
                }
                
                LOG_DEBUG("%s : %s = 0x%x", cache->name,
                          cache->reg_list[i].name, *((uint64_t *)cache->reg_list[i].value));
            }
            cache = cache->next;
        }

        /* dump the global registers */
        for (i = 0; i < HEXAGON_GLOBAL_REGS_CDSP; i++)
        {
            LOG_DEBUG("%s : %s = 0x%x", cache->name,
                      cache->reg_list[i].name, *((uint64_t *)cache->reg_list[i].value));
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

        for (i = 0; i < HEXAGON_PER_THREAD_REGS_CDSP; i++)
        {
            LOG_DEBUG("%s : %s = 0x%x", cache->name,
                      cache->reg_list[i].name, *((uint64_t *)cache->reg_list[i].value));
        }
    }
    LOG_DEBUG("exiting hexagon_dump_hwthrd_reg_cdsp");
    return ERROR_OK;
}

/** Read registers of the the current context **/
int hexagon_read_gpr_registers_cdsp(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    struct reg_cache *cache;
    int retval, j, k = 0, loop, x;
    uint32_t isdb_mmode_cmd, isdb_cmd_status, isdbsts, i = 0;

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_gpr_registers_cdsp entry - hw thrd: %d", hwthrd);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    cache = hexa_info->core_cache;
    if (hwthrd == gHexConfig_cdsp.maxHwThreads)
    {
        loop = gHexConfig_cdsp.maxHwThreads;
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
        isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                                   ISDBCMD_TNUM_MASK_THREAD_CDSP(i));
#ifdef _DEBUG_HEXAGON_CDSP_
        LOG_DEBUG("hexagon_read_gpr_registers  isdb_mmode_cmd = %d and i = %d", isdb_mmode_cmd, i);
#endif

        for (j = 0; j < HEXAGON_GPR_REGS_CDSP; j++)
        {
            /* monitor  mode */
            /*	retval = enable_dbg_sys_pwr(swddp);
                if (retval != ERROR_OK) {
                    LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
                } */

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_gpr_read_cdsp[j]);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");
            }
            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
            }

            /* wait till the stuff instruction is executed */
            hexagon_wait_loop_cdsp();

            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
            }

            /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
            isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

            if (isdb_cmd_status)
            {
                LOG_DEBUG("ISDBcommand failed in user mode");
                return ERROR_OK;
            }
            else
            {
                while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                {
                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

// hexagon_wait_loop_cdsp();
#ifdef _DEBUG_HEXAGON_CDSP_
                    LOG_DEBUG("ISDB status read for Mboxout %d time", j);
#endif

                    k++;
                    if (k == 10)
                        break;
                }
#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
#endif

                k = 0;
                if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                {
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
                    continue;
                }

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &gpPerHwThrdReg_cdsp[x][j]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg_cdsp[x][j]);
                }

                cache->reg_list[j].value = &gpPerHwThrdReg_cdsp[x][j];
                cache->reg_list[j].valid = true;

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg_cdsp[x][j]);
#endif
            }
        }
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_gpr_registers_cdsp exit - hw thrd: %d", hwthrd);
#endif

    return ERROR_OK;
}
/** Read registers of the the current context **/
int hexagon_read_ctrl_registers_cdsp(struct target *target, uint32_t hwthrd)
{

    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    struct reg_cache *cache;
    int retval, j, k, l = 0, x, loop;
    uint32_t isdbsts, i = 0;
    uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_ctrl_registers_cdsp entry - hw thrd: %d", hwthrd);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    cache = hexa_info->core_cache;
    if (hwthrd == gHexConfig_cdsp.maxHwThreads)
    {
        loop = gHexConfig_cdsp.maxHwThreads;
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
        isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                                   ISDBCMD_TNUM_MASK_THREAD_CDSP(i));
#ifdef _DEBUG_HEXAGON_CDSP_
        LOG_DEBUG("hexagon_read_ctrl_registers_cdsp  isdb_mmode_cmd = %d and i = %d", isdb_mmode_cmd, i);
#endif
        /* Mark r7 as dirty as it is being used for stuff instruction */
        cache->reg_list[HEXAGON_R7_CDSP].dirty = true;

        // k = 0;
        for (j = HEXAGON_SA0_CDSP, k = 0; j < HEXAGON_CTRL_MAX_CDSP; j++, k++)
        {

            if ((j == HEXAGON_C5_RESRV_CDSP) || (j >= HEXAGON_C20_RESRV_CDSP && j <= HEXAGON_C29_RESRV_CDSP))
            {
                // k++;
                continue;
            }

            /* Monitor mode */
            /*	retval = enable_dbg_sys_pwr(swddp);
                if (retval != ERROR_OK) {
                    LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
                } */

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_ctrl_reg_read_cdsp[k][0]);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");
            }
            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
            }

            /* wait till the stuff instruction is executed */
            hexagon_wait_loop_cdsp();

            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
            }

            /* 0 - cmd sucessfull, 1 - failure */
            isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
            if (isdb_cmd_status)
            {
                LOG_DEBUG("ISDBcommand failed in Monitor mode");
                return ERROR_OK;
            }
            else
            {
                /*there are 2 stuff instruction here programming second inst */
                /*retval = enable_dbg_sys_pwr(swddp);
                    if (retval != ERROR_OK) {
                        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
                    }*/

                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_ctrl_reg_read_cdsp[k][1]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");
                }

                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
                }

                /* wait till the stuff instruction is executed */
                hexagon_wait_loop_cdsp();

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
                }
#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

                /* 0 - cmd success, 1 - cmd failure */
                isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
                if (isdb_cmd_status)
                {
                    LOG_DEBUG("ISDBcommand failed in Monitor mode");
                    return ERROR_OK;
                }
                else
                {
                    while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                    {
                        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

// hexagon_wait_loop_cdsp();
#ifdef _DEBUG_HEXAGON_CDSP_
                        LOG_DEBUG("ISDB status read for Mboxout %d time", j);
#endif

                        l++;
                        if (l == 10)
                            break;
                    }
#ifdef _DEBUG_HEXAGON_CDSP_
                    LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
#endif

                    l = 0;
                    if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                    {
                        LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
                        continue;
                    }

                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &gpPerHwThrdReg_cdsp[x][j]);
                    if (retval != ERROR_OK)
                    {
                        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT_CDSP read failed 0x%x", gpPerHwThrdReg_cdsp[x][j]);
                    }

                    cache->reg_list[j].value = &gpPerHwThrdReg_cdsp[x][j];
                    cache->reg_list[j].valid = true;

                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

#ifdef _DEBUG_HEXAGON_CDSP_
                    LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg_cdsp[x][j]);
#endif
                }
            }
        }
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_ctrl_registers exit - hw thrd: %d", hwthrd);
#endif
    return ERROR_OK;
}

int hexagon_read_mmode_registers_cdsp(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    struct reg_cache *cache;
    int retval, j, k, l = 0, x, loop;
    uint32_t isdbsts, i = 0;
    uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_mmode_registers_cdsp entry - hw thrd: %d", hwthrd);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    cache = hexa_info->core_cache;
    if (hwthrd == gHexConfig_cdsp.maxHwThreads)
    {
        loop = gHexConfig_cdsp.maxHwThreads;
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
        isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                                   ISDBCMD_TNUM_MASK_THREAD_CDSP(i));
#ifdef _DEBUG_HEXAGON_CDSP_
        LOG_DEBUG("hexagon_read_mmode_registers_cdsp  isdb_mmode_cmd = %d and i = %d", isdb_mmode_cmd, i);
#endif
        /* Mark r7 as dirty as it is being used for stuff instruction */
        cache->reg_list[HEXAGON_R7_CDSP].dirty = true;

        for (j = HEXAGON_SGP0_CDSP, k = 0; j < HEXAGON_MMODE_PERTHRD_MAX_CDSP; j++, k++)
        {
            if (j >= HEXAGON_S12_RESRV_CDSP && j <= HEXAGON_S15_RESRV_CDSP)
            {
                continue;
            }
            /* Monitor mode */
            /*retval = enable_dbg_sys_pwr(swddp);
            if (retval != ERROR_OK) {
                LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
            }*/

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_mmode_reg_read_cdsp[k][0]);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");
            }
            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
            }

            /* wait till the stuff instruction is executed */
            hexagon_wait_loop_cdsp();

            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
            }

            /* 0 - cmd sucessfull, 1 - failure */
            isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
            if (isdb_cmd_status)
            {
                LOG_DEBUG("ISDBcommand failed in Monitor mode");
                return ERROR_OK;
            }
            else
            {
                /*there are 2 stuff instruction here programming second inst */
                /*retval = enable_dbg_sys_pwr(swddp);
                if (retval != ERROR_OK) {
                    LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
                }*/

                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_mmode_reg_read_cdsp[k][1]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
                }

                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
                }

                /* wait till the stuff instruction is executed */
                hexagon_wait_loop_cdsp();

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
                }
#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

                /* 0 - cmd success, 1 - cmd failure */
                isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
                if (isdb_cmd_status)
                {
                    LOG_DEBUG("ISDBcommand failed in monitor  mode");
                    return ERROR_OK;
                }
                else
                {
                    while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                    {
                        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

                        // hexagon_wait_loop_cdsp();

#ifdef _DEBUG_HEXAGON_CDSP_
                        LOG_DEBUG("ISDB status read for Mboxout %d time", j);
#endif

                        l++;
                        if (l == 10)
                            break;
                    }
#ifdef _DEBUG_HEXAGON_CDSP_
                    LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
#endif

                    l = 0;
                    if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                    {
                        LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
                        continue;
                    }

                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &gpPerHwThrdReg_cdsp[x][j]);
                    if (retval != ERROR_OK)
                    {
                        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg_cdsp[x][j]);
                    }

                    cache->reg_list[j].value = &gpPerHwThrdReg_cdsp[x][j];
                    cache->reg_list[j].valid = true;

                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

#ifdef _DEBUG_HEXAGON_CDSP_
                    LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg_cdsp[x][j]);
#endif
                }
            }
        }
    }

    hexagon_read_imask_register_cdsp(target, hwthrd);
#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_mmode_registers exit - hw thrd: %d", hwthrd);
#endif
    return ERROR_OK;
}

int hexagon_read_imask_register_cdsp(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    struct reg_cache *cache;
    int retval, k, l = 0, x, loop;
    uint32_t isdbsts, i = 0;
    uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_imask_register_cdsp entry - hw thrd: %d", hwthrd);
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    cache = hexa_info->core_cache;
    if (hwthrd == gHexConfig_cdsp.maxHwThreads)
    {
        loop = gHexConfig_cdsp.maxHwThreads;
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
        isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                                   ISDBCMD_TNUM_MASK_THREAD_CDSP(k));
        // LOG_DEBUG("hexagon_read_imask_register  isdb_mmode_cmd = %d and i = %d", isdb_mmode_cmd, k);
        /* Monitor mode */
        /*retval = enable_dbg_sys_pwr(swddp);
        if (retval != ERROR_OK) {
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
        }*/

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_mmode_imask_reg_read_cdsp[k][0]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        }
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        }

        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        }

        /* 0 - cmd sucessfull, 1 - failure */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in Monitor mode");
            return ERROR_OK;
        }
        else
        {
            /*there are 2 stuff instruction here programming second inst */
            /*retval = enable_dbg_sys_pwr(swddp);
            if (retval != ERROR_OK) {
                LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
            }*/

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_mmode_imask_reg_read_cdsp[k][1]);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
            }

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
            }

            /* wait till the stuff instruction is executed */
            hexagon_wait_loop_cdsp();

            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
            }
#ifdef _DEBUG_HEXAGON_CDSP_
            LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

            /* 0 - cmd success, 1 - cmd failure */
            isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
            if (isdb_cmd_status)
            {
                LOG_DEBUG("ISDBcommand failed in monitor mode");
                return ERROR_OK;
            }
            else
            {

                /*there are 3 stuff instruction here programming second inst */
                /*	retval = enable_dbg_sys_pwr(swddp);
                if (retval != ERROR_OK) {
                    LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
                } */

                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_mmode_imask_reg_read_cdsp[k][2]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
                }

                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
                }

                /* wait till the stuff instruction is executed */
                hexagon_wait_loop_cdsp();

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
                }
#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

                /* 0 - cmd success, 1 - cmd failure */
                isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
                if (isdb_cmd_status)
                {
                    LOG_DEBUG("ISDBcommand failed in monitor mode");
                    return ERROR_OK;
                }
                else
                {
                    while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                    {
                        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

// hexagon_wait_loop_cdsp();
#ifdef _DEBUG_HEXAGON_CDSP_
                        LOG_DEBUG("ISDB status read for Mboxout %d time", x);
#endif

                        l++;
                        if (l == 10)
                            break;
                    }
#ifdef _DEBUG_HEXAGON_CDSP_
                    LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, k, HEXAGON_IMASK_CDSP);
#endif

                    l = 0;
                    if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                    {
                        LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", HEXAGON_IMASK_CDSP);
                        continue;
                    }

                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &gpPerHwThrdReg_cdsp[k][HEXAGON_IMASK_CDSP]);
                    if (retval != ERROR_OK)
                    {
                        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", gpPerHwThrdReg_cdsp[k][HEXAGON_IMASK_CDSP]);
                    }

                    cache->reg_list[HEXAGON_IMASK_CDSP].value = &gpPerHwThrdReg_cdsp[k][HEXAGON_IMASK_CDSP];

                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
#ifdef _DEBUG_HEXAGON_CDSP_
                    LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, k, HEXAGON_IMASK_CDSP);
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg_cdsp[k][HEXAGON_IMASK_CDSP]);
#endif
                }
            }
        }
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_imask_register_cdsp exit - hw thrd: %d", hwthrd);
#endif
    return ERROR_OK;
}
static int hexagon_restore_stuff_used_reg_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int i = 0;

    LOG_DEBUG("hexagon_restore_stuff_used_reg_cdsp");

    i = 0;
    cache = hexa_info->core_cache;
    while (cache != NULL)
    {
        /* check whether R7 is being used for stuff instruction */
        if (cache->reg_list[HEXAGON_R7_CDSP].dirty == true)
        {
            LOG_DEBUG("Writing modifed R7");

            hexagon_write_core_reg_cdsp(target, HEXAGON_R7_CDSP, i, *((uint64_t *)cache->reg_list[HEXAGON_R7_CDSP].value));
            cache->reg_list[HEXAGON_R7_CDSP].dirty = false;
        }
        cache = cache->next;
        i++;
    }
    return ERROR_OK;
}

/** Read registers of the the current context **/
int hexagon_read_global_ctrl_registers_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    struct reg_cache *cache;
    int retval, j, l = 0, x;
    uint32_t isdb_mmode_cmd, isdb_cmd_status, isdbsts;

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_global_ctrl_registers_cdsp  entry");
#endif

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    /* global */
    cache = hexa_info->core_cache;
    while ((cache->next != NULL))
    {
        cache = cache->next;
    }

    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                               ISDBCMD_TNUM_MASK_THREAD_CDSP(0));
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_global_ctrl_registers_cdsp  isdb_mmode_cmd = %d ", isdb_mmode_cmd);
#endif

    /* Mark r7 as dirty as it is being used for stuff instruction */
    cache->reg_list[HEXAGON_R7_CDSP].dirty = true;

    for (x = HEXAGON_EVB_CDSP, j = 0; x < HEXAGON_MMODE_GLOBAL_MAX_CDSP; x++, j++)
    {
        if ((x == HEXAGON_S19_RESRV_CDSP) || (x == HEXAGON_S24_RESRV_CDSP) || (x == HEXAGON_S26_RESRV_CDSP))
        {
            continue;
        }

        /* Monitor mode */
        /*retval = enable_dbg_sys_pwr(swddp);
        if (retval != ERROR_OK) {
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
        } */

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_global_reg_read_cdsp[j][0]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST_CDSP return value is not OK");
        }
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
        }

        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        }

        /* 0 - cmd sucessfull, 1 - failure */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in Monitor mode");
            return ERROR_OK;
        }
        else
        {
            /*there are 2 stuff instruction here programming second inst */
            /*retval = enable_dbg_sys_pwr(swddp);
            if (retval != ERROR_OK) {
                LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
            } */

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_global_reg_read_cdsp[j][1]);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
            }

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
            }

            /* wait till the stuff instruction is executed */
            hexagon_wait_loop_cdsp();

            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
            }
#ifdef _DEBUG_HEXAGON_CDSP_
            LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

            /* 0 - cmd success, 1 - cmd failure */
            isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
            if (isdb_cmd_status)
            {
                LOG_DEBUG("ISDB command failed in monitor mode");
                return ERROR_OK;
            }
            else
            {
                while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                {
                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

                    //	hexagon_wait_loop_cdsp();

#ifdef _DEBUG_HEXAGON_CDSP_
                    LOG_DEBUG("ISDB status read for Mboxout %d time", x);
#endif

                    l++;
                    if (l == 10)
                        break;
                }

#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, reg = %d", isdbsts, x);
#endif

                l = 0;
                if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                {
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", x);
                    continue;
                }

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &global_reg_cdsp[j]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", global_reg_cdsp[j]);
                }

                cache->reg_list[j].value = &global_reg_cdsp[j];
                cache->reg_list[j].valid = true;

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x,  reg = %d", isdbsts, x);
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", global_reg_cdsp[j]);
#endif
            }
        }
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_global_ctrl_registers_cdsp  exit");
#endif
    return ERROR_OK;
}
/*  Function to write  the HVX registers  */
int hexagon_write_hvx_registers_cdsp(struct target *target, uint32_t value)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    int retval, i = 0, j = 0;
    // uint64_t isdbsts;
    uint32_t isdbsts,isdb_mmode_cmd, isdb_cmd_status;
    uint64_t opcode = 0x19a0e020;
    /*   0x6ea8c000 --> {  r0 = isdbmbxin } , 0x19a0e020 --> {  v0.w = vinsert(r0) } , 0x19a0e021 -->{  v1.w = vinsert(r0) }
      0x19a0e022 --> {v2.w = vinsert(r0) }  0x19a0e023-> {     v3.w = vinsert(r0) }, 0x19a0e03e-->{  v30.w = vinsert(r0) }
    0x19a0e03f --> {   v31.w = vinsert(r0) }*/

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                               ISDBCMD_TNUM_MASK_THREAD_CDSP(0));

    for (j = 0; j < 32; j++)
    {
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, 0x9);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, 0x6ea8c000);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        //	LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");

        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        //	LOG_DEBUG("ISDBST read status after 1st  stuff inst 0x%x", isdbsts);

        /* 0 - cmd success, 1 - cmd failure */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDB command failed in monitor mode");
            return ERROR_OK;
        }

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, opcode + j);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        LOG_DEBUG("ISDB status after opcode + j  write 0x%x", isdbsts);
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");

        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

        // LOG_DEBUG("ISDB status after ISDBCMD write 0x%x", isdbsts);

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDB command failed in monitor  mode");
            // return ERROR_OK;
        }
    }
#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif
    return ERROR_OK;
}

/*  Function to read the HVX registers for CDSP */
int hexagon_read_hvx_registers_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    int retval, i, j, l = 0, x;
    uint32_t isdb_mmode_cmd, isdb_cmd_status, isdbsts;
    uint64_t vextract_opcode_v0 = 0x9200c021;

    /*  
    0x6ea8c000 --> {  r0 = isdbmbxin }  0x9200c021-->{r1 = vextract(v0,r0) }  0x6701c029 --> {  isdbmbxout = r1 }
    0x9200c121 -->{ r1 = vextract(v1,r0)   0x9200c221 --> {  r1 = vextract(v2,r0) }} 0x9200de21  -->{ r1 = vextract(v30,r0) }
    0x9200df21 --> { r1 = vextract(v31,r0) }
    */

    hexagon_r0_used_stuff_cdsp = 1;
    hexagon_r1_used_stuff_cdsp = 1;

    LOG_DEBUG("hexagon_read_hvx_registers_cdsp  entry");

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif
    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                               ISDBCMD_TNUM_MASK_THREAD_CDSP(0));
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_hvx_registers_cdsp   isdb_mmode_cmd = %d ", isdb_mmode_cmd);
#endif

    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 16; j++)
        {
            hvx_register_cdsp[i][j] = 32670;
        }
    }

    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 16; j++)
        {
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

#ifdef _DEBUG_HEXAGON_CDSP_
            LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
#endif

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, j * 4);
            if (retval != ERROR_OK)
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, 0x6ea8c000);
            if (retval != ERROR_OK)
                LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

            hexagon_wait_loop_cdsp();

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, vextract_opcode_v0 + 100 * i);
            if (retval != ERROR_OK)
                LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

            hexagon_wait_loop_cdsp();

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, 0x6701c029);
            if (retval != ERROR_OK)
                LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

            /* wait till the stuff instruction is executed */
            hexagon_wait_loop_cdsp();

            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

#ifdef _DEBUG_HEXAGON_CDSP_
            LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
#endif

            /* 0 - cmd success, 1 - cmd failure */
            isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
            if (isdb_cmd_status)
            {
                LOG_DEBUG("ISDB command failed in monitor mode");
                return ERROR_OK;
            }
            else
            {
                while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                {
                    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
                    l++;
                    if (l == 10)
                        break;
                }
#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDBST status before reading MBXOUT = 0x%x, reg = %d", isdbsts, j);
#endif
                l = 0;
                if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
                {
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
                    continue;
                }
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &hvx_register_cdsp[i][j]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hvx_register_cdsp[i][j]);
                }
            }
        }
    }
#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif

    LOG_DEBUG("******Printing HVX registers*****");
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 16; j++)
        {
            LOG_DEBUG("hvx_register_cdsp[%d][%d]  =  0x%x", i, j, hvx_register_cdsp[i][j]);
        }
    }

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_read_hvx_registers_cdsp  exit");
#endif
    return ERROR_OK;
}

int hexagon_read_current_registers_cdsp(struct target *target, uint32_t hwthrd)
{
    // hexagon_hw_watchdog_disable_cdsp(target);

    /* read general purpose registers (R0-R1) */
    hexagon_read_gpr_registers_cdsp(target, hwthrd);

    /* read per thread control registers */
    hexagon_read_ctrl_registers_cdsp(target, hwthrd);

    /* read per thread monitor mode control registers */
    hexagon_read_mmode_registers_cdsp(target, hwthrd);

    /* read global control registers */
    hexagon_read_global_ctrl_registers_cdsp(target);

    /* Restore the register used stuff instruction */
    hexagon_restore_stuff_used_reg_cdsp(target);

    LOG_DEBUG("Dumping Registers %s", target_name(target));
    hexagon_dump_hwthrd_reg_cdsp(target, gHexConfig_cdsp.maxHwThreads);

    // hexagon_read_hvx_registers_cdsp(target);
    // hexagon_write_hvx_registers_cdsp(target, 9);
    // hexagon_read_hvx_registers_cdsp(target);

    hexagon_read_tlb_entry_cdsp(target);
    return ERROR_OK;
}
static uint64_t hexagon_print_pc_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int i;

    /* dump registers for the requested HW thread */
    cache = hexa_info->core_cache;
    for (i = 0; i < gHexConfig_cdsp.maxHwThreads; i++)
    {
        LOG_DEBUG("Value of PC  %s : %s = 0x%x", cache->name, cache->reg_list[HEXAGON_PC_CDSP].name,
                  *((uint64_t *)cache->reg_list[HEXAGON_PC_CDSP].value));
        cache = cache->next;
    }
    cache = hexa_info->core_cache;
    /* return PC value for HW thread 0 but printing it for all HW thread*/
    return *((uint64_t *)cache->reg_list[HEXAGON_PC_CDSP].value);
}

static int hexagon_step_cdsp(struct target *target, int current, target_addr_t address,
                             int handle_breakpoints)
{
    LOG_DEBUG("Entering..");

    start = clock();
    double func_time;    
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    int retval = ERROR_OK;
    uint64_t isdbcmd, isdbsts, isdb_cmd_status;
    
    uint64_t output;

#ifdef HEXAGON_DEBUG_LOGS
    LOG_INFO("Inside Step function");
#endif

    retval = isdbcmd = isdbsts = 0;

    if (target->state != TARGET_HALTED)
    {
        LOG_DEBUG("Step is requested when target is not halted");
        return ERROR_TARGET_NOT_HALTED;
    }

#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif
    hexagon_stuff_reg_restore_r0_r1_r2_r7_cdsp(target);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_stuff_reg_restore_r0_r1_r2_r7_cdsp:  %lf", func_time);
#endif

#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif    
    hexagon_print_pc_cdsp(target);

#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_print_pc_cdsp:  %lf", func_time);
#endif


    if (gHexConfig_cdsp.maxHwThreads == 4)
    {
        /* Send ISDB command(STEP) to set all thread  */
        isdbcmd |= ISDBCMD_CMD_ISTEP_CDSP;
        isdbcmd |= ISDBCMD_TNUM_MASK_4_CDSP;
    }
    else if (gHexConfig_cdsp.maxHwThreads == 6)
    {
        /* Send ISDB command(STEP) to set all thread  */
        isdbcmd |= ISDBCMD_CMD_ISTEP_CDSP;
        isdbcmd |= ISDBCMD_TNUM_MASK_6_CDSP;
    }

    // retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdbcmd);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDCMD write failed 0x%x", isdbcmd);
        return retval;
    }
    /* Wait for some time  to enable ISDB clk */

    hexagon_wait_loop_cdsp();

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }

    /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
    isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
    if (isdb_cmd_status)
    {
        // LOG_DEBUG("ISDB command failed returning from hexagon_step function ");
        return ERROR_FAIL;
    }

    target->debug_reason = DBG_REASON_SINGLESTEP;

    // hexagon_read_current_registers(target, HEXAGON_HW_THREAD0);
#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif    
    /* read general purpose registers (R0-R1) */
    hexagon_read_gpr_registers_cdsp(target, gHexConfig_cdsp.maxHwThreads);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_read_gpr_registers_cdsp:  %lf", func_time);
#endif


#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif     
    /* read per thread control registers */
    hexagon_read_ctrl_registers_cdsp(target, gHexConfig_cdsp.maxHwThreads);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_read_ctrl_registers_cdsp:  %lf", func_time);
#endif

#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif         
    /* read per thread monitor mode control registers */
    hexagon_read_mmode_registers_cdsp(target, gHexConfig_cdsp.maxHwThreads);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_read_mmode_registers_cdsp:  %lf", func_time);
#endif


#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif       
    /* read global control registers */
    hexagon_read_global_ctrl_registers_cdsp(target);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_read_global_ctrl_registers_cdsp:  %lf", func_time);
#endif


    /* read HVX   registers */
    //	hexagon_read_hvx_registers_cdsp(target);

    /* Restore the register used stuff instruction */

#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif        
    hexagon_restore_stuff_used_reg_cdsp(target);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_restore_stuff_used_reg_cdsp:  %lf", func_time);
#endif
    // start = clock();
    double before_vtlb;
    end = clock();
    before_vtlb = ((double)(end - start))/CLOCKS_PER_SEC;
    LOG_INFO("before_vtlb:  %lf", before_vtlb);

    /* BITMAP array implementation */


    if (QURTK_vtlb_revision != 0x0)
    {
        // uint32_t refresh_indicator ;
        refresh_indicator = QURTK_vtlb_revision;
        // reading the contents of qurtk_vtlb_main_addr-12 and storing it in output
        // 2. To do  : instead of this logic we can use QURTK_vtlb_revision counter has incremented or not
        hexagon_memw_read_cdsp (target, refresh_indicator, &output);
        refresh_indicator = output;
        hexagon_memw_read_cdsp (target, refresh_indicator, &output);
        #ifdef HEXAGON_DEBUG_LOGS
            LOG_INFO("QURTK_vtlb_revision at 0x%x is 0x%x and the previous revision number is 0x%x", refresh_indicator, output, revision_num );
        #endif     


    }



    if (bitmap_init == false) // before bitmap array has been read once and cleared, we need to populate all entries once
    {
#ifdef HEXAGON_DEBUG_LOGS
        LOG_INFO("Populating all entries");
#endif    
        hexagon_populate_vtlb_refresh_entries_cdsp(target);
    }
    else if (output != revision_num) 
    // checking if revision number has incremented
    {
        revision_num = output;

        retval = hexagon_update_modified_vtlb_entry(target);
    }
    else
    {
        LOG_INFO("no vtlb update needed");
    }
    // /* BITMAP array implementation ends here*/



    end = clock();
    execution = ((double)(end - start))/CLOCKS_PER_SEC;
    LOG_INFO("Overall execution:  %lf", execution);

    sbp_step_executed_cdsp = 1;

    return ERROR_OK;
}

int hexagon_update_modified_vtlb_entry(struct target *target)
{
    int retval;

    uint64_t output;
    unsigned int vtlb_entry_count = hexagon_vtlb_data_cdsp.vtlb_no_of_entries;

    //storing the read vtlb entries as an array
    uint64_t vtlb_entries_read[vtlb_entry_count];
    unsigned int vtlb_notify_size;
    // checking if entry count is even, if not we add one to make it even
    vtlb_notify_size = (vtlb_entry_count % 32)? ((vtlb_entry_count/32) +1) :  (vtlb_entry_count/32);

   //storing the read bitmap entries as an array
    unsigned int bitmap_array_contents[vtlb_notify_size];
    //the binary representation will need this size of an array
    unsigned int size_vtlb_binary = (vtlb_entry_count*4);

    char *bits_overall; // string
    uint64_t bit_result [size_vtlb_binary];
   //the first element/pointer to the array will be read and stored in this
    target_addr_t bitmap_addr_temp ;
    //the first element/pointer to the vtlb array will be read and stored in this
    target_addr_t vtlb_entries_temp;

    // uint64_t final_str[size_vtlb_binary];
    unsigned int* final_str = (unsigned int *) calloc(size_vtlb_binary, sizeof(unsigned int));
    //length of the final binary string
    unsigned int final_str_ind = 0;


    //the first element/pointer to the array will be read and stored in bitmap_addr_temp
    hexagon_memw_read_cdsp(target, bitmap_addr, &bitmap_addr_temp);
    
    //  reading the bitmap array, incrementing the array pointer by 4 as each entry is 4 bytes 
    for (unsigned int i = 0; i < vtlb_notify_size; i++)
    {   
        hexagon_memw_read_cdsp(target, bitmap_addr_temp, &output);
        bitmap_array_contents[i] = output;
        bitmap_addr_temp = bitmap_addr_temp + 4;
    } 
#ifdef HEXAGON_DEBUG_LOGS
    LOG_INFO("size of bitmap : %d",sizeof(bitmap_array_contents) / sizeof(bitmap_array_contents[0]));
#endif   


    //  converting decimal to binary storing it as a string so that sequential values of the array entries will have their values retained 
    //  eg bitmap[0] = f;  bitmap[1]=1 then the string will be 1111 1000 (little endian)
    for(unsigned int i = 0; i < (vtlb_notify_size); i++) 
    {
        unsigned int binaryNum[32] = {0};
        decToBinary(bitmap_array_contents[i], binaryNum);
        for(int j = 0; j < 32; j++) 
        {
// #ifdef HEXAGON_DEBUG_LOGS
//             LOG_INFO("bitmap content : bitmap_array_contents[i]:%x, binaryNum[j]:%x, i:%d, j:%d, final_str_ind: %d",bitmap_array_contents[i], binaryNum[j],i,j,final_str_ind);
// #endif   
            final_str[final_str_ind] = binaryNum[j];
            final_str_ind++;
        }
        // LOG_INFO("\n");
    }

    //reading the vtlb entries
    // LOG_INFO("QURTK_vtlb_entries array at = 0x%x ", qurtk_vtlb_entries);

    // vtlb_entries_temp reads the address of first array of vtlb element
    hexagon_memw_read_cdsp(target, qurtk_vtlb_entries, &vtlb_entries_temp);
    // LOG_INFO("QURTK_vtlb_entries temp at = 0x%x ", vtlb_entries_temp);

    
    //  updating entries for the set bits of bitmap array which were stored in binary format into the final_str 
    for(unsigned int i = 0; i < size_vtlb_binary; i++)
    {
        if (final_str[i]!=0)
        {   
            if (i < vtlb_entry_count)
            {
                hexagon_memw_read_cdsp(target, vtlb_entries_temp, &output);
                vtlb_entries_read[i] = output;
                // LOG_INFO("vtlb_entries_read[i] : 0x%x\t", vtlb_entries_read[i]);
                vtlb_entries_temp = vtlb_entries_temp + 4; 

                hexagon_memw_read_cdsp(target, vtlb_entries_temp, &output);
                // hexagon_long_wait_loop_cdsp();
                vtlb_entries_read[i+1] = output;
                // LOG_INFO("vtlb_entries_read[i+1] : 0x%x\t", vtlb_entries_read[i+1]);
                vtlb_entries_temp = vtlb_entries_temp + 4;
            }
            if (i < (sizeof(vtlb_entries_read) / sizeof(vtlb_entries_read[0])))
            {

                hexagon_update_vtlb_entry_in_structure_cdsp(vtlb_entries_read[i],vtlb_entries_read[i+1],i);
            }
        }
        else
        {
                vtlb_entries_temp = vtlb_entries_temp + 8; 
        }
        i++;
        
    }
    free(final_str);
    //resetting the bitmap address to default and clearing it so that we can check again
    bitmap_addr = qurtk_vtlb_bitmap;
    // LOG_INFO("QURTK_vtlb_bitmap array at = 0x%x ", bitmap_addr);    
    hexagon_memw_read_cdsp(target, bitmap_addr, &bitmap_addr_temp);
    // address = hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr + 8;
    for (unsigned int i = 0; i < hexagon_vtlb_data_cdsp.vtlb_no_of_entries/32; i++)
    {   
        retval = hexagon_memw_write_cdsp(target, bitmap_addr_temp, 0x0 , 4);
        bitmap_addr_temp = bitmap_addr_temp + 4;
    } 

    return ERROR_OK;

}

static int hexagon_dump_isdb_reg_cdsp(struct hexa_info_cdsp *hexa_info)
{
    // struct adiv5_dap *swddp = hexa_info->dap;
    uint64_t reg_value;
    int retval = ERROR_OK, i;

    /* dump the all registers */
    // retval = enable_dbg_sys_pwr(swddp);
    for (i = 0; i < HEXAGON_MAX_ISDB_REG_CDSP; i++)
    {
        reg_value = 0;
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + (i * 4), &reg_value);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDB reg(addr: 0x%x) read failed", (i * 4));
            return retval;
        }
#ifdef _DEBUG_HEXAGON_CDSP_
        LOG_DEBUG("ISDB reg dump: ISDB reg(addr: 0x%x) -> 0x%x", reg_value);
#endif
    }
    return retval;
}

static int hexagon_resume_cdsp(struct target *target, int current, target_addr_t address,
                               int handle_breakpoints, int debug_execution)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    int retval = ERROR_OK;
    uint64_t isdbcmd, isdbsts, isdb_cmd_status;
    static int retry_cnt = 0;

    hexagon_dump_isdb_reg_cdsp(&hexagon->hexa_info);

    for (int j = 0; j < gHexConfig_cdsp.maxHwThreads; j++)
    {
        hexagon_read_BRKPT_through_stuff_cdsp(target,j);
    }

    LOG_DEBUG("Entering, Params passed: current = %d  :  address = 0x%llx  :handle_breakpoints = %d  :	debug_execution = %d",
              current, address, handle_breakpoints, debug_execution);
    if (target->state != TARGET_HALTED)
    {
        LOG_DEBUG("Resume is requested when target is not halted");
        return ERROR_TARGET_NOT_HALTED;
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    if (((hexa_info->brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE_CDSP) >> (0)) == HEXA_DBG_SWBRKPT_CDSP)
    {

        LOG_DEBUG("Halted reason HEXA_DBG_SWBRKPT");

        // basic sanity before proceeding
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
            LOG_DEBUG("current_breakpoint->next = 0x%x", current_breakpoint->next);
            i = 0;
            cache = hexa_info->core_cache;
            while ((cache != NULL))
            {
                LOG_DEBUG("*((uint32_t*)cache->reg_list[HEXAGON_PC].value) = 0x%x", *((uint32_t *)cache->reg_list[HEXAGON_PC_CDSP].value));
                if (*((uint32_t *)cache->reg_list[HEXAGON_PC_CDSP].value) == ((current_breakpoint->address)))
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

            //	LOG_DEBUG("Reached here" );
            current_breakpoint = current_breakpoint->next;
            //	LOG_DEBUG("Reached here" );

            if (current_breakpoint)
            {
                LOG_DEBUG("current_breakpoint->address = 0x%llx", current_breakpoint->address);
                LOG_DEBUG("current_breakpoint->type = 0x%x", current_breakpoint->type);
                LOG_DEBUG("current_breakpoint->is_set = 0x%x", current_breakpoint->is_set);
                LOG_DEBUG("current_breakpoint->orig_instr = 0x%x", current_breakpoint->orig_instr);
                LOG_DEBUG("current_breakpoint->next = 0x%x", current_breakpoint->next);
            }
            // LOG_DEBUG("Reached here" );
        }
        if (!PC_matched_with_sbp_addr)
        {
            LOG_DEBUG("breakpoint not found in the list, returning with ERROR_FAIL");
            return ERROR_FAIL;
        }

        if (!PC_matched_with_sbp_addr)
        {
            LOG_DEBUG("bCurrent HWTs PC does not match with SBP address -1, returning with ERROR_FAIL");
            return ERROR_FAIL;
        }
        retval = hexagon_write_ctrl_register_cdsp(target, HEXAGON_PC_CDSP, i, current_breakpoint->address);

        // do a step 0x11 isdbcmd
        if (!sbp_step_executed_cdsp)
        {
            retval = hexagon_step_cdsp(target, 1, 0x00, 0); // current = 1: continue on current pc, otherwise continue at <address> modified the PC so step from the current PC
        }
        if (retval != ERROR_OK)
            LOG_DEBUG("Step command failed");

        // Replace original instrn with brkpt instruction
        retval = ERROR_OK;

        retval = hexagon_memw_write_instruction_memory_cdsp(target, current_breakpoint->address, 0x6c20c000, 0);
        ;
        if (retval != ERROR_OK)
            LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK");
        // continue
        LOG_DEBUG("All steps are successful before continuing in case of sw BP");
    }
retry:
    // Todo: check the position of retry label, in case of very frequent breakpoints, whether it
    //		needs to be placed above the SW preakpoint preprocessing or it's current place, i.e Just before continue cmd

    retval = isdbcmd = isdbsts = isdb_cmd_status = 0;
    hexagon_stuff_reg_restore_r0_r1_r2_r7_cdsp(target);

    if (gHexConfig_cdsp.maxHwThreads == 4)
    {
        /* Send ISDB command(Resume) to resume all halted threads*/
        isdbcmd |= ISDBCMD_CMD_RESUME_CDSP;
        isdbcmd |= ISDBCMD_TNUM_MASK_4_CDSP;
    }
    else if (gHexConfig_cdsp.maxHwThreads == 6)
    {
        /* Send ISDB command(Resume) to resume all halted threads*/
        isdbcmd |= ISDBCMD_CMD_RESUME_CDSP;
        isdbcmd |= ISDBCMD_TNUM_MASK_6_CDSP;
    }

    LOG_DEBUG("Writing HEXAGON_ISDB_ISDBCMD = 0x%x, to resume target", isdbcmd);
    //	retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdbcmd);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDCMD write failed 0x%x", isdbcmd);
        return retval;
    }
    hexagon_long_wait_loop_cdsp();
    hexagon_long_wait_loop_cdsp();
    hexagon_long_wait_loop_cdsp();
    /*	Check ISDB status for threads entering debug mode */
    // retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        return retval;
    }
    LOG_DEBUG("HEXAGON_ISDB_ISDBST value after trying target resume: 0x%x", isdbsts);
    isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
    if (isdb_cmd_status)
    {
        LOG_DEBUG("ISDBcommand for resume failed ");
    }
    /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
    LOG_DEBUG("HEXAGON_ISDB_ISDBCMD write successful for resume");

    uint8_t isdbst_read_retry_cnt = 0;
    while (isdbst_read_retry_cnt < 4)
    {

        if (!((isdbsts & ISDBST_DEBUG_MODE_STATUS_CDSP) >> 8))
        {
            LOG_DEBUG("target resumed; ISDBST_DEBUG_MODE_STATUS is 0x%x", ((isdbsts & ISDBST_DEBUG_MODE_STATUS_CDSP) >> 8));
            LOG_DEBUG("ISDBST_DEBUG_MODE_STATUS value after trying target resume: 0x%x", ((isdbsts & ISDBST_DEBUG_MODE_STATUS_CDSP) >> 8));
            LOG_DEBUG("ISDBST_WAITRUN_MODE_STATUS value after trying target resume: 0x%x", ((isdbsts & ISDBST_WAITRUN_MODE_STATUS_CDSP) >> 24));
            goto resumed;
        }
        // retval = enable_dbg_sys_pwr(swddp);
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        isdbst_read_retry_cnt++;
    }

    LOG_DEBUG("ISDBST_DEBUG_MODE_STATUS value after trying target resume: 0x%x", ((isdbsts & ISDBST_DEBUG_MODE_STATUS_CDSP) >> 8));
    LOG_DEBUG("ISDBST_WAITRUN_MODE_STATUS value after trying target resume: 0x%x", ((isdbsts & ISDBST_WAITRUN_MODE_STATUS_CDSP) >> 24));

    if ((isdbsts & ISDBST_DEBUG_MODE_STATUS_CDSP) >> 8)
    {
        LOG_DEBUG("Unable to resume target; ISDBST_DEBUG_MODE_STATUS is nonzero 0x%x", ((isdbsts & ISDBST_DEBUG_MODE_STATUS_CDSP) >> 8));
        // handle retry here
        retry_cnt++;
        if (retry_cnt < 4)
        {
            goto retry;
        }
        LOG_DEBUG("Unable to resume target After 10 Retry");
        return ERROR_TARGET_FAILURE;
    }
    // LOG_DEBUG("hexagon_halt  target->debug_reason =%d",target->debug_reason);

resumed:
    LOG_DEBUG("Target %s resumed and PC 0x%x", target_name(target), hexagon_print_pc_cdsp(target));
    hexagon_write_syscfg_register_cdsp(target, hexagon_syscfg_reg_cdsp);
    // hexagon_stuff_reg_restore_r7(target);
    hexagon_stuff_reg_restore_r0_r1_r2_r7_cdsp(target);
    target->debug_reason = DBG_REASON_NOTHALTED;

    /* Wait for some time  to enable ISDB clk */
    // hexagon_wait_loop_cdsp();

    if (!debug_execution)
    {
        target->state = TARGET_RUNNING;
        target_call_event_callbacks(target, TARGET_EVENT_RESUMED);
        LOG_DEBUG("target resumed at 0x%" PRIx32, hexagon_print_pc_cdsp(target));
    }
    else
    {
        target->state = TARGET_DEBUG_RUNNING;
        target_call_event_callbacks(target, TARGET_EVENT_DEBUG_RESUMED);
        LOG_DEBUG("target debug resumed at 0x%" PRIx32, hexagon_print_pc_cdsp(target));
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif
    LOG_DEBUG("Exiting %s\n", __FUNCTION__);

    // resetting the global data structures to keep track of Business logic involved in SW BP

    for (int j = 0; j < gHexConfig_cdsp.maxHwThreads; j++)
    {
        gpSbpHaltedThreadsPC_cdsp[j] = 0;
    }

    sbp_step_executed_cdsp = 0;
    return ERROR_OK;
}

static int hexagon_read_BRKPT_through_stuff_cdsp(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    uint32_t isdb_mmode_cmd = 0x0;


    int retval, i = 0;
    uint64_t stuff_inst[][4] = {{0x6ea4c007, 0x6707c029},
                                {0x6ea6c007, 0x6707c029},
                                {0x6ea5c007, 0x6707c029},
                                {0x6ea7c007, 0x6707c029}}; // r7=PC0,PC1,CFG0,CFG1; isdbmbxout = r7;
    uint64_t isdbsts, read_val[4] = {};
    // uint64_t isdb_mmode_cmd = 0x184,size=0,nreg,loop,x;

    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                                ISDBCMD_TNUM_MASK_THREAD_CDSP(hwthrd));

    
    uint64_t isdb_gmode_cmd = 0x144, isdb_cmd_status;

    LOG_DEBUG("%s ------ %d\n", __FUNCTION__, __LINE__);

    /*there are 2 stuff instruction, here programming first inst */
    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK) {
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
    }*/

    for (int j = 0; j < 4; j++)
    {
        /*retval = enable_dbg_sys_pwr(swddp);
        if (retval != ERROR_OK) {
            LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
        }*/
        /*there are 2 stuff instruction, here programming first inst */

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[j][0]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst[j][0],j=%d", j);
        }
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK for stuff_inst[j][0],j=%d", j);
        }

        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        }

        LOG_DEBUG("ISDBST read status after first stuff inst j = %d, 0x%x", j, isdbsts);
        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor  mode");
            /*retval = enable_dbg_sys_pwr(swddp);
            if (retval != ERROR_OK) {
                    LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
            }*/

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[j][0]);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK for stuff_inst[j][0],j=%d", j);
            }
            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_mmode_cmd return value is not OK for stuff_inst[j][0],j=%d", j);
            }
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
            }
            LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
            /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
            isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

            if (isdb_cmd_status)
            {
                LOG_DEBUG("ISDBcommand failed in user mode");
                /* retval = enable_dbg_sys_pwr(swddp);
                if (retval != ERROR_OK) {
                        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
                }*/

                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[j][0]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
                }
                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_mmode_cmd return value is not OK");
                }
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
                }
                LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
                /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
                isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
                if (isdb_cmd_status)
                {
                    LOG_DEBUG("ISDBcommand failed in Guest mode");
                    return ERROR_OK;
                }
            }
        }
        /*there are 2 stuff instruction, here programming second inst */
        /*retval = enable_dbg_sys_pwr(swddp);
        if (retval != ERROR_OK) {
                LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
        }*/

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[j][1]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        }
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        }
        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        }
        LOG_DEBUG("ISDBST read status after 2nd stuff inst 0x%x", isdbsts);
        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            /*retval = enable_dbg_sys_pwr(swddp);
            if (retval != ERROR_OK) {
                    LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
            }*/

            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[j][1]);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
            }
            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_mmode_cmd return value is not OK");
            }

            /* wait till the stuff instruction is executed */
            hexagon_wait_loop_cdsp();

            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
            }
            LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
            /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
            isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

            if (isdb_cmd_status)
            {
                LOG_DEBUG("ISDBcommand failed in user  mode");
                /* retval = enable_dbg_sys_pwr(swddp);
                if (retval != ERROR_OK) {
                        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
                }*/

                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst[j][1]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
                }
                retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                                 hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBCMD isdb_mmode_cmd return value is not OK");
                }

                /* wait till the stuff instruction is executed */
                hexagon_wait_loop_cdsp();

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
                }
                LOG_DEBUG("ISDBST read status 0x%x", isdbsts);
                /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
                isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
                if (isdb_cmd_status)
                {
                    LOG_DEBUG("ISDBcommand failed in Guest  mode");
                    return ERROR_OK;
                }
            }
        }

        /*reading mailboxout status in ISDBST register */
        while (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
        {
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
            /* wait till the stuff instruction is executed */
            // hexagon_wait_loop_cdsp();
            i++;
            if (i == 10)
                break;
        }
        LOG_DEBUG("ISDBST status value before  reading mailbox register 0x%x, i = %d", isdbsts, i);
        i = 0;
        if (!(isdbsts & ISDBST_ISDB_MAILBOX_OUT_CDSP))
        {
            LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for iteration %d", j);
            continue;
        }
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT_CDSP, &read_val[j]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", read_val[j]);
        }
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", read_val[j]);
        LOG_DEBUG("ISDBST status value after  reading mailbox register 0x%x ", isdbsts);
    }
    return ERROR_OK;
}

static int hexagon_check_state_one_cdsp(struct target *target,
                                        uint64_t mask, bool *halted, uint64_t *debug_thread)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct adiv5_dap *swddp = hexa_info->dap;
    uint64_t isdbsts;
    int retval;
    isdbsts = 0;

    // LOG_INFO("hexagon_check_state_one_cdsp");
    if (halted == NULL || debug_thread == NULL)
    {
        LOG_DEBUG(" Fail: halted 0x%x, debug_thread 0x%x", (uint64_t)*halted, *debug_thread);
        return ERROR_FAIL;
    }

    /*	Check ISDB status for threads in  debug mode */
    retval = enable_dbg_sys_pwr(swddp);

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
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
    // LOG_INFO("ISDB STATUS: 0x%x, halted 0x%x, debug_thread 0x%x", isdbsts, *halted, isdbsts);
    /*
    if(!*halted)
    {
        LOG_INFO("ISDB STATUS: 0x%x, halted 0x%x, debug_thread 0x%x", isdbsts, *halted, isdbsts);
    }*/

    return ERROR_OK;
}
static int hexagon_debug_entry_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    int retval = ERROR_OK;
    uint64_t brkptinfo;
    brkptinfo = 0;

    uint64_t *thrd_src;

    thrd_src = (uint64_t *)malloc(gHexConfig_cdsp.maxHwThreads * sizeof(uint64_t));

    LOG_DEBUG("hexagon_debug_entry_cdsp	%s", target_name(target));

    // retval = enable_dbg_sys_pwr(swddp);

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO_CDSP, &brkptinfo);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("BRKPTINFO read failed 0x%x", brkptinfo);
        return retval;
    }

    LOG_DEBUG("TARGET_HALTED, HEXAGON_ISDB_BRKPTINFO = 0x%x \n", brkptinfo);

    if (gHexConfig_cdsp.maxHwThreads == 4)
    {
        thrd_src[0] = ((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE_CDSP) >> (0));
        thrd_src[1] = ((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE_CDSP) >> (3));
        thrd_src[2] = ((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE_CDSP) >> (6));
        thrd_src[3] = ((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE_CDSP) >> (9));
    }
    else if (gHexConfig_cdsp.maxHwThreads == 6)
    {
        thrd_src[0] = ((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE_CDSP) >> (0));
        thrd_src[1] = ((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE_CDSP) >> (3));
        thrd_src[2] = ((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE_CDSP) >> (6));
        thrd_src[3] = ((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE_CDSP) >> (9));
        thrd_src[4] = ((brkptinfo & BRKPTINFO_THREAD4_BRKPT_SOURCE_CDSP) >> (12));
        thrd_src[5] = ((brkptinfo & BRKPTINFO_THREAD5_BRKPT_SOURCE_CDSP) >> (15));
    }

    for (int i = 0; i < gHexConfig_cdsp.maxHwThreads; i++)
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
    // hexagon_debug_reason(target, brkptinfo);

    // Assuming all threads are halted for the same reason.
    hexagon_debug_reason_cdsp(target, thrd_src[0]);
    hexagon_read_current_registers_cdsp(target, gHexConfig_cdsp.maxHwThreads);

    //*****************************************************//
    if (((hexa_info->brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE_CDSP) >> (0)) == HEXA_DBG_SWBRKPT_CDSP)
    {

        LOG_DEBUG("Halted reason HEXA_DBG_SWBRKPT");
        struct breakpoint *current_breakpoint = target->breakpoints;
        uint8_t PC_matched_with_sbp_addr = 0;
        struct reg_cache *cache = hexa_info->core_cache;
        uint8_t i = 0;

        for (i = 0; i < gHexConfig_cdsp.maxHwThreads; i++)
        {
            gpSbpHaltedThreadsPC_cdsp[i] = gpPerHwThrdReg_cdsp[i][HEXAGON_PC_CDSP];
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
            while (i < gHexConfig_cdsp.maxHwThreads)
            {
                LOG_DEBUG("*((uint64_t*)cache->reg_list[HEXAGON_PC].value) = 0x%x", gpSbpHaltedThreadsPC_cdsp[i]);
                if (gpSbpHaltedThreadsPC_cdsp[i] == ((current_breakpoint->address) + 4))
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
        // set PC to PC-4
        retval = hexagon_write_ctrl_register_cdsp(target, HEXAGON_PC_CDSP, i, current_breakpoint->address);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("hexagon_write_ctrl_register HEXAGON_PC return value is not OK, returning with ERROR_FAIL");
            return ERROR_OK;
        }
        // Replace breakpoint instrn with original instruction
        retval = ERROR_OK;
        union fourbyte_cdsp val;

        val.byte[0] = current_breakpoint->orig_instr[0];
        val.byte[1] = current_breakpoint->orig_instr[1];
        val.byte[2] = current_breakpoint->orig_instr[2];
        val.byte[3] = current_breakpoint->orig_instr[3];

        retval = hexagon_memw_write_instruction_memory_cdsp(target, current_breakpoint->address, val.word, 1);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("Replacing original instruction, hexagon_memw_write_instruction_memory_cdsp return value is not OK. Returning with ERROR_FAIL");
            return ERROR_FAIL;
        }
    }

    free(thrd_src);
    return ERROR_OK;
}
void hexagon_debug_reason_cdsp(struct target *target, uint64_t brkptinfo)
{
    /* Examine debug reason */
    switch (HEXA_DEBUG_ENTRY_CDSP(brkptinfo))
    {
    case HEXA_DBG_EXTBRKPT_CDSP:
        target->debug_reason = DBG_REASON_DBGRQ;
        LOG_DEBUG("DBG_REASON_DBGRQ");
        break;

    case HEXA_DBG_HWBRKPT0_CDSP:
    case HEXA_DBG_HWBRKPT1_CDSP:
    case HEXA_DBG_SWBRKPT_CDSP:
    case HEXA_DBG_ETMBRKPT_CDSP:
    case HEXA_DBG_APBBRKPT_CDSP:
        target->debug_reason = DBG_REASON_BREAKPOINT;
        LOG_DEBUG("DBG_REASON_BREAKPOINT");
        break;

    default:
        target->debug_reason = DBG_REASON_UNDEFINED;
        LOG_DEBUG("DBG_REASON_UNDEFINED");
        break;
    }
}

static int hexagon_poll_cdsp(struct target *target)
{
    enum target_state prev_target_state;
    int retval = ERROR_OK;
    uint64_t debug_thread;
    bool halted = false;
    halted = debug_thread = 0;

    // LOG_INFO("hexagon_poll_cdsp");

    retval = hexagon_check_state_one_cdsp(target, ISDBST_DEBUG_MODE_STATUS_CDSP, &halted, &debug_thread);
    // if (retval != ERROR_OK)
    // return retval;
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
            LOG_DEBUG("At FUNCTION:%s\t LINE:%d, target->debug_reason = %d", __FUNCTION__, __LINE__, target->debug_reason);

            /* We have a halting debug event */
            target->state = TARGET_HALTED;
            LOG_DEBUG("Target %s halted", target_name(target));

            retval = hexagon_debug_entry_cdsp(target);
            if (retval != ERROR_OK)
                return retval;

            // if (target->smp)
            // hexagon_update_halt_gdb(target, debug_reason);

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

int hexagon_arch_state_cdsp(struct target *target)
{
    assert(target != NULL);
    // return target->arch_info;
    return ERROR_OK;
}

/*
 * Basic debug access, very low level assumes state is saved
 */
static int hexagon_init_debug_access_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct adiv5_dap *swddp = hexa_info->dap;

    int retval = ERROR_OK;
    uint64_t isdbcmd, isdbsts, isdbcsts, bpinfo;

    retval = isdbcmd = isdbsts = isdbcsts = bpinfo = 0;

    LOG_DEBUG("hexagon_init_debug_access_cdsp");
    LOG_INFO("%s", target_name(target));

    if (gHexConfig_cdsp.maxHwThreads == 4)
    {
        isdbcmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_BREAK_CDSP, ISDBCMD_USER_LVL_CDSP, ISDBCMD_TNUM_MASK_4_CDSP);
    }
    else if (gHexConfig_cdsp.maxHwThreads == 6)
    {
        isdbcmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_BREAK_CDSP, ISDBCMD_USER_LVL_CDSP, ISDBCMD_TNUM_MASK_6_CDSP);
    }
    retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdbcmd);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDCMD write failed 0x%x", isdbcmd);
        return retval;
    }

    /* Wait for some time  to enable ISDB clk */
    hexagon_wait_loop_cdsp();

    /*	Check ISDB status for threads entering debug mode */
    retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        return retval;
    }

    /* check ISDB core status - reset/PC to access ISDB*/
    retval = enable_dbg_sys_pwr(swddp);

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO_CDSP, &bpinfo);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBEN read failed 0x%x", bpinfo);
        return retval;
    }
    // LOG_INFO("Finally: ISDBstatus 0x%x, brkpt info 0x%x ", isdbcmd, isdbsts, bpinfo);
    LOG_INFO("Finally: ISDBstatus 0x%x, brkpt info 0x%x ", isdbsts, bpinfo);
    LOG_INFO("Threads entered debug mode(ISDB status 0x%x)", isdbsts);
    target->debug_reason = DBG_REASON_DBGRQ;
    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_handle_cache_info_command_cdsp)
{
    // struct target *target = get_current_target(CMD_CTX);
    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_handle_dbginit_command_cdsp)
{
    struct target *target = get_current_target(CMD_CTX);
    if (!target_was_examined(target))
    {
        LOG_DEBUG("target not examined yet");
        return ERROR_FAIL;
    }

    return hexagon_init_debug_access_cdsp(target);
}

COMMAND_HANDLER(hexagon_mask_interrupts_command_cdsp)
{
    // struct target *target = get_current_target(CMD_CTX);

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
        // hexagon_vtlb_data_cdsp.QURTK_vtlb_main_VA = addr;
        qurtk_vtlb_main_addr = addr;
        command_print(CMD, " QURTK_vtlb_main = 0x%x", addr);
        LOG_INFO("QURTK_VTLB_main = 0x%x", addr);
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
        hexagon_vtlb_data_cdsp.QURTK_VTLB_DATA_VA = addr;
        command_print(CMD, "QURTK_VTLB_DATA = 0x%x", addr);
        LOG_INFO("QURTK_VTLB_DATA = 0x%x", addr);
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
        gHexConfig_cdsp.maxHwThreads = threads;
        command_print(CMD, " HEXAGON_MAX_HW_THREADS_MODEM_CDSP = %d", threads);
        LOG_INFO("HEXAGON_MAX_HW_THREADS_MODEM_CDSP = %d", threads);
    }

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
        gHexConfig_cdsp.qpss6WDOGCtl = WDOG;
        command_print(CMD, " HEXAGON_QDSP6SS_WDOG_CTL_CDSP = 0x%x", WDOG);
        LOG_INFO("HEXAGON_QDSP6SS_WDOG_CTL_CDSP = 0x%x", WDOG);
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
        gHexConfig_cdsp.numTlbEntries = numTLB;
        command_print(CMD, " HEXAGON_TLB_ENTRIES_NUM_CDSP = %d", numTLB);
        LOG_INFO("HEXAGON_TLB_ENTRIES_NUM_CDSP = %d", numTLB);
    }

    return ERROR_OK;
}
COMMAND_HANDLER(hexagon_initConfig)
{

    initConfig(&gHexConfig_cdsp);
    LOG_INFO("initiating with : ");
    LOG_INFO("HEXAGON_MAX_HW_THREADS_MODEM_CDSP = %d", gHexConfig_cdsp.maxHwThreads);
    LOG_INFO("HEXAGON_TLB_ENTRIES_NUM_CDSP = %d", gHexConfig_cdsp.numTlbEntries);
    LOG_INFO("HEXAGON_QDSP6SS_WDOG_CTL_CDSP = 0x%x", gHexConfig_cdsp.qpss6WDOGCtl);

    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_mem_read)
{
    uint32_t output;
    int retval;

    clock_t start_read, end_read;
    // clock_t start_buffer, end_buffer;
    long double total_time;

    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common_cdsp *hexagon = target->arch_info;
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    target_addr_t virt_addr, phy_addr;

    uint32_t isdbsts;
    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], virt_addr);
        command_print(CMD, " virt_addr = 0x%x", virt_addr);
        LOG_INFO("virt_addr = 0x%x ", virt_addr);
    }
    start_read = clock();

    // retval = hexagon_virt2phys_cdsp(target, virt_addr, &phy_addr);

    hexagon_memw_read_cdsp(target, virt_addr, &output);
    LOG_INFO("output is 0x%x\t", output );
    end_read = clock();

    total_time = ((double)(end_read - start_read))/CLOCKS_PER_SEC;
    LOG_INFO("AFTER memw_read %lf", total_time);

    start_read = clock();


    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);

    end_read = clock();

    total_time = ((long double)(end_read - start_read))/CLOCKS_PER_SEC;
    LOG_INFO("AFTER single DAP read of isdbstatus %lf", total_time);

    total_time = ((long double)(end_read - start_read));
    LOG_INFO("AFTER single DAP read of isdbstatus without converting to seconds %lf", total_time );

    start_read = clock();


    retval = mem_ap_write_atomic_u32(debug_axi_ap_cdsp,
                                     gHexConfig_cdsp.qpss6WDOGCtl, HEXAGON_QDSP6SS_WDOG_DISABLE_CDSP);
    end_read = clock();

    total_time = ((double)(end_read - start_read))/CLOCKS_PER_SEC;
    LOG_INFO("AFTER single DAP write of wdog_disable %lf", total_time);

    total_time = ((long double)(end_read - start_read));
    LOG_INFO("AFTER single DAP read of isdbstatus without converting to seconds %lf", total_time );
    return ERROR_OK;


}

COMMAND_HANDLER(hexagon_vtlbRefresh)
{
    struct target *target = get_current_target(CMD_CTX);
    start = clock();
    // hexagon_read_tlb_entry_cdsp(target);
    hexagon_populate_vtlb_refresh_entries_cdsp(target);


    end = clock();
    execution = ((double)(end - start))/CLOCKS_PER_SEC;
    LOG_INFO("time taken for refresh_tlb_entries  %lf", execution);
    return ERROR_OK;
}   


void decToBinary(unsigned int n, unsigned int binaryNum[])
{
    // counter for binary array
    int i = 0;
    while (n > 0 && i < 32) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
}

COMMAND_HANDLER(hexagon_set_vtlb_params)
{


    //to read the memw results
    uint64_t output;
    int retval;
    unsigned int vtlb_entry_count = hexagon_vtlb_data_cdsp.vtlb_no_of_entries ;
    
    //storing the read vtlb entries as an array
    uint64_t vtlb_entries_read[vtlb_entry_count];
    unsigned int vtlb_notify_size;
    // checking if entry count is even, if not we add one to make it even
    vtlb_notify_size = (vtlb_entry_count%32)? ((vtlb_entry_count/32)+1): vtlb_entry_count/32;

    //storing the read bitmap entries as an array
    unsigned int bitmap_array_contents[vtlb_notify_size];
    //the binary representation will need this size of an array
    unsigned int size_vtlb_binary = (vtlb_entry_count*4);

    char *bits_overall; // string
    uint64_t bit_result[size_vtlb_binary];
    //the first element/pointer to the bitmap array will be read and stored in this
    target_addr_t bitmap_addr_temp ;
    //the first element/pointer to the vtlb array will be read and stored in this
    target_addr_t vtlb_entries_temp;

    // uint64_t final_str[size_vtlb_binary];
    unsigned int* final_str = (unsigned int *)calloc(size_vtlb_binary, sizeof(unsigned int));
    //length of the final binary string
    unsigned int final_str_ind = 0;
    //following initializations to use access hexagon parameters in this command
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common_cdsp *hexagon = target->arch_info;
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;

/* init code*/
    target_addr_t vtlb_entries;
    
    // taking in user input for QURTK_vtlb_bitmap and QURTK_vtlb_entries from the symbols on ukernel elf via lldb commands
    if (CMD_ARGC < 2)
    {
        return ERROR_COMMAND_SYNTAX_ERROR;
    }

    else if (CMD_ARGC == 2)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], bitmap_addr);
        command_print(CMD, " bitmap addr = 0x%x", bitmap_addr);
        qurtk_vtlb_bitmap = bitmap_addr;
        // LOG_INFO("bitmap addr = 0x%x", bitmap_addr);

        COMMAND_PARSE_ADDRESS(CMD_ARGV[1], vtlb_entries);
        qurtk_vtlb_entries = vtlb_entries;
        // vtlb_entries 
        command_print(CMD, " QURTK_vtlb_entries = 0x%x", vtlb_entries);
        // LOG_INFO("QURTK_vtlb_entries = 0x%x", vtlb_entries);
    }
/* init code ends here*/
    // the first element/pointer to the array will be read and stored in bitmap_addr_temp
    hexagon_memw_read_cdsp(target, bitmap_addr, &bitmap_addr_temp);
    
    //  reading the bitmap array, incrementing the array pointer by 4 as each entry is 4 bytes 
    for (unsigned int i = 0; i < vtlb_notify_size; i++)
    {   
        hexagon_memw_read_cdsp(target, bitmap_addr_temp, &output);
        bitmap_array_contents[i] = output;
        // LOG_INFO("bitmap content at 0x%x is 0x%x",bitmap_addr_temp, output);
        bitmap_addr_temp = bitmap_addr_temp + 4;

    } 


    // converting decimal to binary storing it as a string so that sequential values of the array entries will have their values retained 
    // eg bitmap[0] = f;  bitmap[1]=1 then the string will be 1111 1000 (little endian)
    for(unsigned int i = 0; i < (vtlb_notify_size); i++) 
    {
        unsigned int binaryNum[32] = {0};
        decToBinary(bitmap_array_contents[i], binaryNum);
        for(int j = 0; j < 32; j++) 
        {
            final_str[final_str_ind] = binaryNum[j];
            final_str_ind++;
        }
    }

    
    //reading the vtlb entries
    // LOG_INFO("QURTK_vtlb_entries array at = 0x%x ", qurtk_vtlb_entries);

    // vtlb_entries_temp reads the address of first array of vtlb element
    hexagon_memw_read_cdsp(target, qurtk_vtlb_entries, &vtlb_entries_temp);
    // LOG_INFO("QURTK_vtlb_entries temp at = 0x%x ", vtlb_entries_temp);

    
    //  updating entries for the set bits of bitmap array which were stored in binary format into the final_str 
    unsigned int j = 0;
    for(unsigned int i = 0; i < final_str_ind; i++)
    {
        if (final_str[i] !=0)
        {    
            if (i < vtlb_entry_count)
            {
                hexagon_memw_read_cdsp(target, vtlb_entries_temp, &output);
                vtlb_entries_read[i] = output;
                // LOG_INFO("0x%x\t", vtlb_entries_read[i]);
                vtlb_entries_temp = vtlb_entries_temp + 4; 

                hexagon_memw_read_cdsp(target, vtlb_entries_temp, &output);
                vtlb_entries_read[i+1] = output;
                LOG_INFO("0x%x\t", vtlb_entries_read[i+1]);
                vtlb_entries_temp = vtlb_entries_temp + 4;
            }
            if (i < (sizeof(vtlb_entries_read) / sizeof(vtlb_entries_read[0])))
            {

                hexagon_update_vtlb_entry_in_structure_cdsp(vtlb_entries_read[i],vtlb_entries_read[i+1],i);
            }
        }
        else
        {
            vtlb_entries_temp = vtlb_entries_temp + 8;
        }
        i++;
    }
    free(final_str);
    bitmap_init = true;

    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_set_revision_addr)
{
    target_addr_t input;
    uint64_t output;
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common_cdsp *hexagon = target->arch_info;
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;    

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], input);
        QURTK_vtlb_revision = input;
        command_print(CMD, " QURTK_vtlb_revision = 0x%x", QURTK_vtlb_revision);
        // LOG_INFO("QURTK_vtlb_revision = 0x%x", QURTK_vtlb_revision);
    }

    LOG_INFO("QURTK_vtlb_revision  at = 0x%x ", QURTK_vtlb_revision);
    hexagon_memw_read_cdsp (target, QURTK_vtlb_revision, &output);
    refresh_indicator = output;
    hexagon_memw_read_cdsp (target, refresh_indicator, &output);
    revision_num = output;
    LOG_INFO("revision num is = 0x%x ", revision_num);

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_clear_bitmap_array)
{
    uint64_t output;
    int retval;

    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common_cdsp *hexagon = target->arch_info;
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    bitmap_addr = qurtk_vtlb_bitmap;
    target_addr_t bitmap_addr_temp ;


    LOG_INFO("QURTK_vtlb_bitmap array at = 0x%x ", bitmap_addr);

    // for (int i = 0; i < hexagon_vtlb_data_cdsp.vtlb_no_of_entries/32; i++)
    // {
    //     // retval = hexagon_memw_write_cdsp(target, virt_address + 4 * i, value, 4);
    //     retval = hexagon_memw_write_cdsp(target, bitmap_addr, 0x0 , 4);
    //     // retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, bitmap_addr, 0x0);
    //     hexagon_memw_read_cdsp(target, bitmap_addr, &output);

    //     LOG_INFO("0x%x\t", output );
    //     bitmap_addr = bitmap_addr + 4;
    // }    

    
    hexagon_memw_read_cdsp(target, bitmap_addr, &bitmap_addr_temp);
    // address = hexagon_vtlb_data_cdsp.qurtk_vtlb_main.next_table_addr + 8;
    for (unsigned int i = 0; i < hexagon_vtlb_data_cdsp.vtlb_no_of_entries/32; i++)
    {   
        retval = hexagon_memw_write_cdsp(target, bitmap_addr_temp, 0x0 , 4);

        bitmap_addr_temp = bitmap_addr_temp + 4;
    } 
    bitmap_addr = qurtk_vtlb_bitmap;

    hexagon_memw_read_cdsp(target, bitmap_addr, &bitmap_addr_temp);

    for (unsigned int i = 0; i < hexagon_vtlb_data_cdsp.vtlb_no_of_entries/32; i++)
    {   
        hexagon_memw_read_cdsp(target, bitmap_addr_temp, &output);
        LOG_INFO("bitmap content at 0x%x is 0x%x",bitmap_addr_temp, output);

        bitmap_addr_temp = bitmap_addr_temp + 4;
    } 

            // LOG_INFO("bitmap content at 0x%x is 0x%x",bitmap_addr_temp, output);

    return ERROR_OK;
}

static const struct command_registration hexagon_exec_command_handlers_cdsp[] = {
    {
        .name = "cache_info",
        .handler = hexagon_handle_cache_info_command_cdsp,
        .mode = COMMAND_EXEC,
        .help = "display information about hexagon cdsp caches",
        .usage = "",
    },
    {
        .name = "dbginit",
        .handler = hexagon_handle_dbginit_command_cdsp,
        .mode = COMMAND_EXEC,
        .help = "Initialize Hexagon cdsp debug",
        .usage = "",
    },
    {
        .name = "maskisr",
        .handler = hexagon_mask_interrupts_command_cdsp,
        .mode = COMMAND_ANY,
        .help = "mask hexagon cdsp interrupts during single-step",
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
        .usage = "[address]",
    },
    {
        .name = "SetMaxHWThreads",
        .handler = hexagon_SetHWthreads,
        .mode = COMMAND_ANY,
        .help = "Set the maximum number of hardware threads",
        .usage = "[Number]",
    },
    {
        .name = "setRevision",
        .handler = hexagon_set_revision_addr,
        .mode = COMMAND_ANY,
        .help = "Set the revision address",
        .usage = "[Number]",
    },
    {
        .name = "SetWDOGCTL",
        .handler = hexagon_SetQPSS6WDOGCTL,
        .mode = COMMAND_ANY,
        .help = "Set Watchdog Control address",
        .usage = "[address]",
    },
    {
        .name = "SetNumTLBEntries",
        .handler = hexagon_SetNumTLBEntries,
        .mode = COMMAND_ANY,
        .help = "Set Number of TLB Entries",
        .usage = "[Number]",
    },
    {
        .name = "refreshVTLB",
        .handler = hexagon_vtlbRefresh,
        .mode = COMMAND_ANY,
        .help = "Refresh VTLB entries",
        .usage = "[Number]",
    },

    {
        .name = "setVTLBParam",
        .handler = hexagon_set_vtlb_params,
        .mode = COMMAND_ANY,
        .help = "set vtlb entries",
        .usage = "[]",
    },
    {   
        .name = "clear_vtlb_entries",
        .handler = hexagon_clear_bitmap_array,
        .mode = COMMAND_ANY,
        .help = "clear bitmap array",
        .usage = "[]",
    },
    // {   
    //     .name = "find_modified_vtlb",
    //     .handler = hexagon_find_modified_vtlb,
    //     .mode = COMMAND_ANY,
    //     .help = "find modified vtlb",
    //     .usage = "[]",
    // },
    {
        .name = "mem_read",
        .handler = hexagon_mem_read,
        .mode = COMMAND_ANY,
        .help = "memw virtual read",
        .usage = "[]",
    },
    {
        .name = "initConfig",
        .handler = hexagon_initConfig,
        .mode = COMMAND_ANY,
        .help = "Initiate with the set values",
        .usage = "[]",
    },
    {
        .chain = smp_command_handlers,
    },
    COMMAND_REGISTRATION_DONE};

extern const struct command_registration semihosting_common_handlers[];

static const struct command_registration hexagon_command_handlers_cdsp[] = {
    {
        .name = "hexagon_cdsp",
        .mode = COMMAND_ANY,
        .help = "hexagon cdsp command group",
        .usage = "command <> <>",
        .chain = hexagon_exec_command_handlers_cdsp,
    },
    COMMAND_REGISTRATION_DONE};

static int hexagon_handle_target_request_cdsp(void *priv)
{
    struct target *target = priv;
    struct hexagon_common_cdsp *hexagon = target->arch_info;
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    int retval;
    static int cnt = 0;
    uint64_t *thrd_src;

    thrd_src = (uint64_t *)malloc(gHexConfig_cdsp.maxHwThreads * sizeof(uint64_t));

    if ((++cnt % 1000) == 0)
        LOG_DEBUG("hexagon_handle_target_request_cdsp exam=%d dbg=%d state=%d ", target->examined, target->dbg_msg_enabled, target->state);

    if (target->state == TARGET_HALTED && ((cnt % 200) == 0))
    {

        LOG_DEBUG("TARGET_HALTED\n");
        // check the halt reason

        uint64_t brkptinfo = 0;
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO_CDSP, &brkptinfo);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("Could not read brkptinfo, retval = %d", retval);
            return retval;
        }

        LOG_DEBUG("TARGET_HALTED, HEXAGON_ISDB_BRKPTINFO_CDSP = 0x%x \n", brkptinfo);

        if (gHexConfig_cdsp.maxHwThreads == 4)
        {
            thrd_src[0] = ((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE_CDSP) >> (0));
            thrd_src[1] = ((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE_CDSP) >> (3));
            thrd_src[2] = ((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE_CDSP) >> (6));
            thrd_src[3] = ((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE_CDSP) >> (9));
        }
        else if (gHexConfig_cdsp.maxHwThreads == 6)
        {
            thrd_src[0] = ((brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE_CDSP) >> (0));
            thrd_src[1] = ((brkptinfo & BRKPTINFO_THREAD1_BRKPT_SOURCE_CDSP) >> (3));
            thrd_src[2] = ((brkptinfo & BRKPTINFO_THREAD2_BRKPT_SOURCE_CDSP) >> (6));
            thrd_src[3] = ((brkptinfo & BRKPTINFO_THREAD3_BRKPT_SOURCE_CDSP) >> (9));
            thrd_src[4] = ((brkptinfo & BRKPTINFO_THREAD4_BRKPT_SOURCE_CDSP) >> (12));
            thrd_src[5] = ((brkptinfo & BRKPTINFO_THREAD5_BRKPT_SOURCE_CDSP) >> (15));
        }

        for (int i = 0; i < gHexConfig_cdsp.maxHwThreads; i++)
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

    if (!target_was_examined(target))
        return ERROR_OK;
    if (!target->dbg_msg_enabled)
        return ERROR_OK;

    free(thrd_src);
    return ERROR_OK;
}

static int hexagon_init_arch_info_cdsp(struct target *target,
                                       struct hexagon_common_cdsp *hexagon, struct adiv5_dap *dap)
{
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;

    LOG_INFO("hexagon_init_arch_info_cdsp");

    hexagon->common_magic = HEXAGON_COMMON_MAGIC_CDSP;
    hexa_info->dap = dap;
    hexa_info->arch_info = hexagon;
    target->arch_info = hexagon;
    hexa_info->target = target;

    // memset(gpPerHwThrdReg_cdsp, 0, sizeof(gpPerHwThrdReg_cdsp));
    memset(global_reg_cdsp, 0, sizeof(global_reg_cdsp));

    target_register_timer_callback(hexagon_handle_target_request_cdsp, 5,
                                   TARGET_TIMER_TYPE_PERIODIC, target);

    return ERROR_OK;
}

static int hexagon_target_create_cdsp(struct target *target, Jim_Interp *interp)
{

    struct hexagon_private_config_cdsp *pc = target->private_config;
    struct hexagon_common_cdsp *hexagon;
    int retval;

    LOG_INFO("hexagon_target_create_cdsp");

    // initConfig(&gHexConfig_cdsp);

    if (adiv5_verify_config(&pc->adiv5_config) != ERROR_OK)
        return ERROR_FAIL;

    hexagon = calloc(1, sizeof(struct hexagon_common_cdsp));

    if (hexagon == NULL)
    {
        LOG_DEBUG("Out of memory");
        return ERROR_FAIL;
    }

    return hexagon_init_arch_info_cdsp(target, hexagon, pc->adiv5_config.dap);
}

static int hexagon_jim_configure_cdsp(struct target *target, struct jim_getopt_info *goi)
{
    struct hexagon_private_config_cdsp *pc;
    struct jim_nvp *n;
    int e;

    LOG_INFO("hexagon_jim_configure_cdsp");

    pc = (struct hexagon_private_config_cdsp *)target->private_config;
    if (pc == NULL)
    {
        pc = calloc(1, sizeof(struct hexagon_private_config_cdsp));
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

static void hexagon_wait_loop_cdsp(void)
{
    uint16_t i, loop = 0;

    for (i = 0; i < 2000; i++)
    {
        if ((i % 1000) == 0)
            // LOG_DEBUG("in hexagon_wait_loop_cdsp()");
            loop++;
    }
}

static void hexagon_long_wait_loop_cdsp(void)
{
    uint64_t i, loop = 0;

    for (i = 0; i < 10000; i++)
    {
        if ((i % 5000) == 0)
            // LOG_DEBUG("in hexagon_long_wait_loop_cdsp()");
            loop++;
    }
}

/* This function enable the ETM */
static uint64_t hexagon_etm_on_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target->arch_info;
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct adiv5_dap *swddp = hexa_info->dap;
    static int initialized;
    uint64_t retval = ERROR_OK, tmp;

    uint64_t etm_clk_enable_addr = 0x86988000;
    uint64_t etm_clk_reset_addr = 0x86988008;

    if (!initialized)
    {
        retval = enable_dbg_sys_pwr(swddp);
        LOG_INFO("Enabling ETM ");
        tmp = 0x3;
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, etm_clk_enable_addr, tmp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("unable to enable ETM clk 0x%x", tmp);
            return retval;
        }
        //	hexagon_wait_loop_cdsp();
        tmp = 0x1;
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, etm_clk_reset_addr, tmp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("unable to reset ETM 0x%x", tmp);
            return retval;
        }
        //	hexagon_wait_loop_cdsp();
        tmp = 0x0;
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, etm_clk_reset_addr, tmp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("APB unlock fail");
            return retval;
        }
        //	hexagon_wait_loop_cdsp();
        LOG_INFO("After Enabling ETM ");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap, etm_clk_enable_addr, &tmp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("unable to read ETM clk 0x%x", tmp);
            return retval;
        }
        LOG_DEBUG("ETM clk 0x%x", tmp);
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, etm_clk_reset_addr, tmp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("unable to read ETM reset 0x%x", tmp);
            return retval;
        }
        LOG_DEBUG("ETM reset 0x%x", tmp);
        initialized = 1;
    }
    return retval;
}

static int hexagon_examine_first_cdsp(struct target *target)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    LOG_DEBUG("Number of bp available brp_num_available= %d", hexagon->brp_num_available);
    LOG_DEBUG("Number of bp available brp_num= %d", hexagon->brp_num);
    LOG_DEBUG("Number of bp available brp_num_context= %d", hexagon->brp_num_context);
    // Hard coding brp_num_available = 2 for now, need to find a permanent solution. *hexagon = target_to_hexagon(target); should give valid data.
    hexagon->brp_num_available = 2; // this value is constant to future ref
    hexagon->brp_num = 2;           // upon setting/removing HW breakpoint this value will be decreased/increased
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct hexagon_private_config_cdsp *pc;
    struct adiv5_dap *swddp = hexa_info->dap;
    int retval = ERROR_OK;
    uint64_t isdben, isdbver, isdbcstat, isdbst, corever, tmp;
    isdben = isdbver = isdbcstat = isdbst = corever = tmp = 0;

    /* Search for the APB-AB - it is needed to access debug registers */
    retval = dap_find_get_ap(swddp, AP_TYPE_APB_AP, &hexa_info->debug_ap);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("Could not find APB-AP for debug access");
        return retval;
    }

    retval = enable_dbg_sys_pwr(swddp);

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
        uint64_t dbgbase;
        /* Get ROM Table base */
        uint64_t apid;
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

    /* Unlocking the APB address space by writing to debug base + 0xFB0 with  0xc5acce55 */
    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + 0xFB0, 0xc5acce55);
    if (retval != ERROR_OK)
        LOG_DEBUG("hexa_info->debug_base + 0xFB0	write failed");
    LOG_INFO("After writing 0x%x	with value	0xC5ACCE55", hexa_info->debug_base + 0xFB0);

    /* Need to wait some time after writing to register to take it effect */
    hexagon_long_wait_loop_cdsp();

    retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBCST_CDSP, &isdbcstat);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBCST read failed 0x%x", isdbcstat);
        return retval;
    }
    if (isdbcstat == 4)
    {
        LOG_ERROR("CDSP Processor is in reset or power collapse, please wait until the core is active");
        return ERROR_FAIL;
    }

    retval = hexagon_etm_on_cdsp(target);
    if (retval != ERROR_OK)
        LOG_DEBUG("ETM enablement fail");

    /** check ISDB version details **/
    retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBVER_CDSP, &isdbver);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBVER read failed 0x%x", isdbver);
        return retval;
    }
    LOG_DEBUG(" ISDBver 0x%x  ", isdbver);

    /** check core version details **/
    retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_COREVER_CDSP, &corever);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("COREVER read failed 0x%x", corever);
        return retval;
    }
    LOG_DEBUG(" core ver 0x%x ", corever);

    retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBEN_CDSP, &isdben);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBEN read failed 0x%x", isdben);
        return retval;
    }
    LOG_DEBUG("After ISDBEN read 0x%x ", isdben);

    /** check secure_EN, ISDB_trusted to enable APB_ISDB **/
    if (((isdben & ISDBEN_APB_ISDB_EN_CDSP) != ISDBEN_APB_ISDB_EN_CDSP) ||
        ((isdben & ISDBEN_ISDB_PREVNT_PWRDWN_CDSP) != ISDBEN_ISDB_PREVNT_PWRDWN_CDSP))
    { /** trusted, secure, clk on, apb enabl **/
        hexa_info->isdb_enable = true;
        isdben |= ISDBEN_APB_ISDB_EN_CDSP;
        isdben |= ISDBEN_ISDB_PREVNT_PWRDWN_CDSP;

        retval = enable_dbg_sys_pwr(swddp);
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBEN_CDSP, isdben);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBEN write failed 0x%x", isdben);
            return retval;
        }
        LOG_DEBUG("After ISDBEN write  0x%x", (uint64_t)isdben);
    }
    else
    {
        LOG_DEBUG("ISDB is already enabled 0x%x", isdben);
    }

    hexagon_wait_loop_cdsp();

    retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBEN_CDSP, &isdben);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBEN read failed 0x%x", isdben);
        return retval;
    }
    LOG_DEBUG("After ISDBEN read 0x%x ", (uint64_t)isdben);

    retval = enable_dbg_sys_pwr(swddp);

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbst);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDB status read failed 0x%x", isdbst);
        return retval;
    }
    LOG_DEBUG("After ISDB status  0x%x ", isdbst);

    //#if 0

    //---------------Hexagon breakpoint global data structure setup---------------//
    hexagon->brp_num = 2;
    hexagon->brp_num_available = hexagon->brp_num;
    hexagon->brp_list = calloc(hexagon->brp_num, sizeof(struct hexagon_brp_cdsp));
    for (int i = 0; i < hexagon->brp_num; i++)
    {
        hexagon->brp_list[i].used = 0;
        hexagon->brp_list[i].type = BRP_NORMAL;
        hexagon->brp_list[i].value = 0;
        hexagon->brp_list[i].control = 0;
        hexagon->brp_list[i].BRPn = i;
    }

    LOG_DEBUG("Configured %i hw breakpoints", hexagon->brp_num);

    //-----------------------------------------------------------------------//

    // hexagon_setup_isdb_config(target);
    // hexagon breakpoint config setup

    hexa_info->isdb_ver = isdbver;
    hexa_info->corever = corever;
    if ((isdben == 0x0) && (isdbver == 0x0) && (corever == 0x0))
    {
        LOG_ERROR("Not able to communicate with device , Reboot the device and try again");
    }

    LOG_DEBUG("Finally: isdben 0x%x, isdbver 0x%x, corever 0x%x, isdbstatus 0x%x", isdben, isdbver, corever, isdbst);

    /* set up registers, breakpoint */
    retval = hexagon_reg_setup_cdsp(hexagon);
    retval = hexagon_brkpt_setup_cdsp(hexagon);

    target->state = TARGET_UNKNOWN;
    target->debug_reason = DBG_REASON_NOTHALTED;
    hexagon->isrmasking_mode = HEXAGON_ISRMASK_ON_CDSP;
    target_set_examined(target);
    LOG_INFO("%s: examination pass\n", target_name(target));

    hexagon_hw_watchdog_disable_cdsp(target);
    LOG_INFO("checking STEP latency issues");
    // hexagon_populate_vtlb_data(target);
    return ERROR_OK;
}

#if 0
/* This function used to initialize the AXI-AP */
static void hexagon_initialize_axi_ap_cdsp(struct target *target)
{
	struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
	struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;
	int retval,i;
	
	LOG_DEBUG("hexagon_initialize_axi_ap_cdsp  Enter");
	retval = enable_dbg_sys_pwr(swddp);
	
	if(debug_axi_ap_cdsp == NULL)
	{
		/* Search for the AXI-AP - it is needed for access to memory */
		retval = dap_find_get_ap(swddp, AP_TYPE_AXI_AP, &debug_axi_ap_cdsp);
		if (retval != ERROR_OK) 
		{
			for(i=0; i < 10;  i++)
			{
				hexagon_wait_loop();
				retval = dap_find_get_ap(swddp, AP_TYPE_AXI_AP, &debug_axi_ap_cdsp);
				if(retval == ERROR_OK)
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
		retval = mem_ap_init(debug_axi_ap_cdsp);
		if (retval != ERROR_OK) {
			LOG_DEBUG("Could not initialize the AP_TYPE_AXI_AP");
			return;
		}
		debug_axi_ap_cdsp->memaccess_tck = 10;
	}
	LOG_DEBUG("hexagon_initialize_axi_ap_cdsp  Exit");
}
#endif

static void hexagon_hw_watchdog_disable_cdsp(struct target *target)
{
    int retval;
    uint64_t temp;
    uint8_t buffer;

    LOG_DEBUG("hexagon_hw_watchdog_disable_cdsp  enter ");

    if (debug_axi_ap_cdsp == NULL)
        hexagon_initialize_axi_ap_cdsp(target);

    if (debug_axi_ap_cdsp == NULL)
    {
        LOG_DEBUG("debug_axi_ap not available so watchdog is not disabled ");
        return;
    }
    // retval = enable_dbg_sys_pwr(swddp);
    retval = mem_ap_read_buf(debug_axi_ap_cdsp, (uint8_t *)&temp, 4, 1, gHexConfig_cdsp.qpss6WDOGCtl);
    if (retval != ERROR_OK)
        LOG_DEBUG("read api failed");

    LOG_DEBUG("HEXAGON_QDSP6SS_WDOG_CTL_CDSP read value  = 0x%x ", temp);

    retval = mem_ap_write_atomic_u32(debug_axi_ap_cdsp,
                                     gHexConfig_cdsp.qpss6WDOGCtl, HEXAGON_QDSP6SS_WDOG_DISABLE_CDSP);

    if (retval != ERROR_OK)
        LOG_DEBUG("WDOG disabled failed");

    hexagon_wait_loop();
    retval = mem_ap_read_buf(debug_axi_ap_cdsp, (uint8_t *)&temp, 4, 1, gHexConfig_cdsp.qpss6WDOGCtl);
    if (retval != ERROR_OK)
        LOG_DEBUG("read api failed");

    LOG_DEBUG("HEXAGON_MSS_QDSP6SS_WDOG_CTL read value after write  = 0x%x ", temp);
    LOG_INFO("hexagon_hw_watchdog_disable_cdsp  exit ");

#if 0
	struct hexagon_common_cdsp *hexagon = target->arch_info;
	struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
	struct adiv5_dap *swddp = hexa_info->dap;

	LOG_DEBUG("hexagon_hw_watchdog_disable_cdsp  enter "); 

	retval = enable_dbg_sys_pwr(swddp);
	
	retval = mem_ap_read_buf(hexa_info->debug_ap,(uint8_t *)&temp, 4, 1, gHexConfig_cdsp.qpss6WDOGCtl);
	if(retval != ERROR_OK)
		LOG_DEBUG("read api failed"); 
	
	LOG_DEBUG("HEXAGON_QDSP6SS_WDOG_CTL_CDSP read value  = 0x%x ",temp);
	
	retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
				gHexConfig_cdsp.qpss6WDOGCtl, HEXAGON_QDSP6SS_WDOG_DISABLE_CDSP);
	
	if(retval != ERROR_OK)
		LOG_DEBUG("WDOG disabled failed"); 
		
	hexagon_wait_loop_cdsp();
	retval = mem_ap_read_buf(hexa_info->debug_ap,(uint8_t *)&temp, 4, 1, gHexConfig_cdsp.qpss6WDOGCtl);
	if(retval != ERROR_OK)
		LOG_DEBUG("read api failed"); 

	LOG_DEBUG("HEXAGON_QDSP6SS_WDOG_CTL_CDSP read value after write  = 0x%x ",temp); 
	LOG_INFO("hexagon_hw_watchdog_disable_cdsp  exit ");
#endif
}

static int hexagon_examine_cdsp(struct target *target)
{
    int retval = ERROR_OK;

    LOG_DEBUG("hexagon_examine_cdsp() ");

    /* don't re-probe hardware after each reset */
    if (!target_was_examined(target))
        retval = hexagon_examine_first_cdsp(target);

    return retval;
}

static int hexagon_brkpt_setup_cdsp(struct hexagon_common_cdsp *hexagon)
{

    int retval = ERROR_OK;

    return retval;
}
static int hexagon_reg_setup_cdsp(struct hexagon_common_cdsp *hexagon)
{
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct hexa_reg_cdsp *reg = &hexa_info->reg;
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
    for (i = 0; i <= gHexConfig_cdsp.maxHwThreads; i++)
    {
        if ((cache = hexagon_build_reg_cache_cdsp(target, i)) == NULL)
            return ERROR_FAIL;

        cache->name = gpHexagonThreadNameArray_cdsp[i];
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
    hexa_info->read_core_reg = hexagon_read_core_reg_cdsp;
    hexa_info->write_core_reg = hexagon_write_core_reg_cdsp;
    reg->hexagon_reg_current_cdsp = hexagon_reg_current_cdsp;

    return retval;
}

static int hexagon_get_core_reg_cdsp(struct reg *reg)
{
    struct hex_reg_cdsp *arch_info = reg->arch_info;
    struct target *target = arch_info->target;
    struct hexa_info_cdsp *hexa_info = arch_info->hexa_info;

    LOG_DEBUG("get_core_reg: target state %d, hw-thrd %d, reg %d",
              target->state, arch_info->hwthrd, arch_info->num);

    if (target->state != TARGET_HALTED)
        return ERROR_TARGET_NOT_HALTED;

    return hexa_info->read_core_reg(target, reg, arch_info->num, arch_info->hwthrd);
}

static int hexagon_set_core_reg_cdsp(struct reg *reg, uint8_t *buf)
{
    struct hex_reg_cdsp *arch_info = reg->arch_info;
    struct target *target = arch_info->target;
    struct hexa_info_cdsp *hexa_info = arch_info->hexa_info;
    uint32_t value;

    memcpy(&value, buf, 4);

    LOG_INFO("set_core_reg: target state %d, hw-thrd %d, reg %d, value 0x%x",
             target->state, arch_info->hwthrd, arch_info->num, value);

    if (target->state != TARGET_HALTED)
        return ERROR_TARGET_NOT_HALTED;

    return hexa_info->write_core_reg(target, arch_info->num, arch_info->hwthrd, value);
}

/** Builds cache of architecturally defined registers.  */
struct reg_cache *hexagon_build_reg_cache_cdsp(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common_cdsp *hexa_common = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa = &hexa_common->hexa_info;
    int num_regs;
    struct reg_cache **cache_p = register_get_last_cache_p(&target->reg_cache);
    struct reg_cache *cache;
    struct reg *reg_list;
    struct hex_reg_cdsp *arch_info;
    struct reg_feature *feature;
    int i;

    LOG_DEBUG("hexagon_build_reg_cache_cdsp enter");
    /* Build the process context cache */
    cache = malloc(sizeof(struct reg_cache));

    if (hwthrd == gHexConfig_cdsp.maxHwThreads + 1)
    {
        /* Create for global regisers */
        num_regs = HEXAGON_MMODE_GLOBAL_MAX_CDSP - HEXAGON_MMODE_PERTHRD_MAX_CDSP;
        reg_list = calloc(num_regs, sizeof(struct reg));
        arch_info = calloc(num_regs, sizeof(struct hex_reg_cdsp));
        cache->next = NULL;
        cache->reg_list = reg_list;
        cache->num_regs = num_regs;

        for (i = 0; i < num_regs; i++)
        {
            arch_info[i].num = hexagon_global_regs_cdsp[i].id;
            arch_info[i].hwthrd = gHexConfig_cdsp.maxHwThreads;
            arch_info[i].target = target;
            arch_info[i].hexa_info = hexa;
            arch_info[i].value[0] = 0xDE; // default value
            arch_info[i].value[1] = 0xAD; // default value

            reg_list[i].name = hexagon_global_regs_cdsp[i].name;
            reg_list[i].size = hexagon_global_regs_cdsp[i].bits;
            reg_list[i].value = &arch_info[i].value[0];
            reg_list[i].type = &hexagon_reg_type_cdsp;
            reg_list[i].arch_info = &arch_info[i];
            reg_list[i].group = hexagon_global_regs_cdsp[i].group;
            reg_list[i].number = i;
            reg_list[i].exist = true;
            reg_list[i].caller_save = true; /* gdb defaults to true */
            // reg_list[i].valid = true;

            feature = calloc(1, sizeof(struct reg_feature));
            if (feature)
            {
                feature->name = hexagon_global_regs_cdsp[i].feature;
                reg_list[i].feature = feature;
            }
            else
                LOG_DEBUG("unable to allocate feature list");

            reg_list[i].reg_data_type = calloc(1, sizeof(struct reg_data_type));

            if (reg_list[i].reg_data_type)
            {
                reg_list[i].reg_data_type->type = hexagon_global_regs_cdsp[i].type;
            }
            else

                LOG_DEBUG("unable to allocate reg type list");
        }

        LOG_DEBUG("hexagon_build_reg_cache_cdsp global reg allocation done");
    }
    else
    {
        /** Create GPR, CTRL, Monitor Mode (per thread) registers */
        num_regs = HEXAGON_PER_THREAD_REGS_CDSP;
        reg_list = calloc(num_regs, sizeof(struct reg));
        arch_info = calloc(num_regs, sizeof(struct hex_reg_cdsp));
        cache->next = NULL;
        cache->reg_list = reg_list;
        cache->num_regs = num_regs;
        for (i = 0; i < num_regs; i++)
        {
            arch_info[i].num = hexagon_per_hwt_regs_cdsp[i].id;
            arch_info[i].hwthrd = hwthrd;
            arch_info[i].target = target;
            arch_info[i].hexa_info = hexa;
            // arch_info[i].value[0] = 0xDEAD; //default values
            arch_info[i].value[0] = 0xDE; // default value
            arch_info[i].value[1] = 0xAD; // default value
            reg_list[i].name = hexagon_per_hwt_regs_cdsp[i].name;
            reg_list[i].size = hexagon_per_hwt_regs_cdsp[i].bits;
            reg_list[i].value = &arch_info[i].value[0];
            reg_list[i].type = &hexagon_reg_type_cdsp;
            reg_list[i].arch_info = &arch_info[i];

            reg_list[i].group = hexagon_per_hwt_regs_cdsp[i].group;
            reg_list[i].number = i;
            reg_list[i].exist = true;
            reg_list[i].caller_save = true; /* gdb defaults to true */
            // reg_list[i].valid = true;

            feature = calloc(1, sizeof(struct reg_feature));
            if (feature)
            {
                feature->name = hexagon_per_hwt_regs_cdsp[i].feature;
                reg_list[i].feature = feature;
            }
            else
                LOG_DEBUG("unable to allocate feature list");

            reg_list[i].reg_data_type = calloc(1, sizeof(struct reg_data_type));

            if (reg_list[i].reg_data_type)
            {
                reg_list[i].reg_data_type->type = hexagon_per_hwt_regs_cdsp[i].type;
            }
            else
                LOG_DEBUG("unable to allocate reg type list");
        }

        LOG_DEBUG(" hexagon_build_reg_cache_cdsp per thread allocation done");
    }

    LOG_DEBUG("hexagon_build_reg_cache_cdsp exit");

    (*cache_p) = cache;
    return cache;
}

struct reg *hexagon_reg_current_cdsp(struct hexa_info_cdsp *hexa_info, unsigned int regnum, struct reg_cache *cache)
{
    struct reg *r;

    if (regnum >= HEXAGON_MMODE_GLOBAL_MAX_CDSP)
        return NULL;

    r = cache->reg_list + regnum; // TDB for all Hw threads.

    return r;
}

static int hexagon_write_core_reg_cdsp(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval = ERROR_OK;
    uint64_t i;

    if (regnum < HEXAGON_R0_CDSP || regnum >= HEXAGON_MMODE_GLOBAL_MAX_CDSP)
        return ERROR_COMMAND_SYNTAX_ERROR;

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_write_core_reg_cdsp: %d, Thrd: %d, value %d", regnum, hwthrd, value);
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

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("Before writing:%d", regnum);
#endif

    /* Write the register value to device */
    if (regnum < HEXAGON_GPR_MAX_CDSP)
    {
        hexagon_write_gpr_register_cdsp(target, regnum, hwthrd, value);
    }
    else if (regnum < HEXAGON_CTRL_MAX_CDSP)
    {
        hexagon_write_ctrl_register_cdsp(target, regnum, hwthrd, value);
    }
    else if ((regnum < HEXAGON_MMODE_PERTHRD_MAX_CDSP))
    {
        LOG_DEBUG("This reg:%d write is no supported", regnum);
    }
    else if (regnum < HEXAGON_MMODE_GLOBAL_MAX_CDSP)
    {
        hexagon_write_global_ctrl_register_cdsp(target, regnum, hwthrd, value);
    }
    else
    {
        LOG_DEBUG("Invalid register to write reg:%d", regnum);
    }

    return retval;
}
static int hexagon_write_global_ctrl_register_cdsp(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    int retval, i = 0;
    uint32_t isdbsts,isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_write_global_ctrl_register_cdsp: hw thrd: %d, regnum %d, value %d", hwthrd, regnum, value);
#endif

    if ((regnum == HEXAGON_MODECTL_CDSP) || (regnum == HEXAGON_S19_RESRV_CDSP) || (regnum == HEXAGON_IPENDAD_CDSP) ||
        (regnum >= HEXAGON_S24_RESRV_CDSP && regnum <= HEXAGON_CFGBASE_CDSP) || ((regnum == HEXAGON_REV_CDSP)))
    {
        LOG_DEBUG("Invalid: reserved/readonly register : %d", regnum);
        return ERROR_FAIL;
    }
#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif
    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                               ISDBCMD_TNUM_MASK_THREAD_CDSP(hwthrd));

    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK) {
        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
    }*/

    /* run the 1st instruction */
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
#endif

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, value);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN_CDSP return value is not OK");
    }

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP,
                                     stuff_inst_global_reg_write_cdsp[regnum - HEXAGON_SGP0_CDSP][0]);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
    }

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
#endif

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
    }

    /* wait till the stuff instruction is executed */
    hexagon_wait_loop_cdsp();

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
#endif

    /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
    isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

    if (isdb_cmd_status)
    {
        LOG_DEBUG("ISDBcommand failed in monitor  mode");
        return ERROR_OK;
    }
    else
    {
        if (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
        {
            i = 0;
            while (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
            {

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

                hexagon_wait_loop_cdsp();
#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDB status read for Mboxin %d time", i);
#endif
                i++;
                if (i == 10)
                    break;
            }
            if (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
            {
                LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, so write failure for register R%d", regnum);
                return ERROR_FAIL;
            }
        }

        /* run the 2nd instruction */
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP,
                                         stuff_inst_global_reg_write_cdsp[regnum - HEXAGON_SGP0_CDSP][1]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        }

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        }

        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        }

        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;
        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor  mode");
            return ERROR_OK;
        }
    }
    global_reg_cdsp[regnum - HEXAGON_EVB_CDSP] = value;
#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif
    return ERROR_OK;
}

static int hexagon_write_ctrl_register_cdsp(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    int retval, i = 0;

    uint32_t isdbsts,isdb_mmode_cmd, isdb_cmd_status;


#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_write_ctrl_register_cdsp: hw thrd: %d, regnum %d, value 0x%x", hwthrd, regnum, value);
#endif

    if ((regnum == HEXAGON_C5_RESRV_CDSP) || (regnum >= HEXAGON_C20_RESRV_CDSP && regnum <= HEXAGON_C20_RESRV_CDSP))
    {
        LOG_DEBUG("Invalid: reserved register : %d", regnum);
        return ERROR_FAIL;
    }

    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                               ISDBCMD_TNUM_MASK_THREAD_CDSP(hwthrd));

    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK) {
        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
    }*/

    /* run the 1st instruction */
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
#endif

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, value);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN_CDSP return value is not OK");
    }

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP,
                                     stuff_inst_ctrl_reg_write_cdsp[regnum - HEXAGON_SA0_CDSP][0]);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
    }

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
#endif

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
    }

    /* wait till the stuff instruction is executed */
    hexagon_wait_loop_cdsp();

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status after ISDBCMD run 0x%x", isdbsts);
#endif

    /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
    isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

    if (isdb_cmd_status)
    {
        LOG_DEBUG("ISDBcommand failed in monitor  mode");
        return ERROR_OK;
    }
    else
    {
        if (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
        {
            i = 0;
            while (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
            {
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

                hexagon_wait_loop_cdsp();
#ifdef _DEBUG_HEXAGON_CDSP_
                LOG_DEBUG("ISDB status read for Mboxin 0x%x time", isdbsts);
#endif

                i++;
                if (i == 10)
                    break;
            }
            if (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
            {
                LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, write failure for register R%d", regnum);
                return ERROR_FAIL;
            }
        }

        /* run the 2nd instruction */
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP,
                                         stuff_inst_ctrl_reg_write_cdsp[regnum - HEXAGON_SA0_CDSP][1]);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
        }

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        }

        /* wait till the stuff instruction is executed */
        hexagon_wait_loop_cdsp();

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        }
        /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
        isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

        if (isdb_cmd_status)
        {
            LOG_DEBUG("ISDBcommand failed in monitor  mode");
            return ERROR_OK;
        }
    }
    gpPerHwThrdReg_cdsp[hwthrd][regnum] = value;

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif
    return ERROR_OK;
}

static int hexagon_write_gpr_register_cdsp(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    // struct adiv5_dap *swddp = hexa_info->dap;
    int retval, i = 0;
    uint32_t isdbsts;
    uint32_t isdb_mmode_cmd, isdb_cmd_status;

#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("hexagon_write_gpr_register_cdsp: hw thrd: %d, regnum %d, value 0x%x", hwthrd, regnum, value);
#endif
    isdb_mmode_cmd = hexagon_pack_isdbcmd_cdsp(ISDBCMD_CMD_STUFF_CDSP, ISDBCMD_MONITOR_LVL_CDSP,
                                               ISDBCMD_TNUM_MASK_THREAD_CDSP(hwthrd));

#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_start_time_cal_ms_cdsp();
#endif

    /*retval = enable_dbg_sys_pwr(swddp);
    if (retval != ERROR_OK) {
        LOG_DEBUG("enable_dbg_sys_pwr return value is not OK");
    }*/

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
#endif

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN_CDSP, value);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
    }
    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_STFINST_CDSP, stuff_inst_gpr_write_cdsp[regnum]);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_STFINST return value is not OK");
    }

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status after ISDBMBXIN write 0x%x", isdbsts);
#endif

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD_CDSP, isdb_mmode_cmd);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBCMD_CDSP return value is not OK");
    }

    /* wait till the stuff instruction is executed */
    hexagon_wait_loop_cdsp();

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
#ifdef _DEBUG_HEXAGON_CDSP_
    LOG_DEBUG("ISDB status after ISDBCMD write 0x%x", isdbsts);
#endif

    /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */
    isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS_CDSP;

    if (isdb_cmd_status)
    {
        LOG_DEBUG("ISDBcommand failed in user mode");
        return ERROR_OK;
    }
    else if (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
    {
        i = 0;
        while (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
        {
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST_CDSP, &isdbsts);

            hexagon_wait_loop_cdsp();
#ifdef _DEBUG_HEXAGON_CDSP_
            LOG_DEBUG("ISDB status read for Mboxin 0x%x time", isdbsts);
#endif

            i++;
            if (i == 10)
                break;
        }
        if (isdbsts & ISDBST_ISDB_MAILBOX_IN_CDSP)
        {
            LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, write failure for register R%d", regnum);
            return ERROR_FAIL;
        }
    }
    gpPerHwThrdReg_cdsp[hwthrd][regnum] = value;
#ifdef _HEXAGON_TARGET_TIME_PROFILING_CDSP
    hexagon_end_time_cal_ms_cdsp();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total_cdsp);
#endif
    return ERROR_OK;
}

static int hexagon_read_core_reg_cdsp(struct target *target, struct reg *r, int regnum, uint32_t hwthrd)
{
    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval = ERROR_OK;
    uint64_t i;

    LOG_INFO("reading reg:%d, hw_thrd %d ", regnum, hwthrd);

    if (regnum < 0 || regnum >= HEXAGON_MMODE_GLOBAL_MAX_CDSP)
        return ERROR_COMMAND_SYNTAX_ERROR;

    /* Read the register of the requested Hw thread */
    cache = hexa_info->core_cache;
    i = 0;
    while ((cache->next != NULL) && i < hwthrd)
    {
        cache = cache->next;
        i++;
    }
    r->value = (uint64_t *)cache->reg_list[regnum].value;
    r->valid = true;
    r->dirty = false;
    return retval;
}

static int hexagon_init_target_cdsp(struct command_context *cmd_ctx,
                                    struct target *target)
{
    LOG_INFO(" hexagon_init_target_cdsp");

    return ERROR_OK;
}
static void hexagon_deinit_target_cdsp(struct target *target)
{

    struct hexagon_common_cdsp *hexagon = target_to_hexagon_cdsp(target);
    struct hexa_info_cdsp hexa_info = hexagon->hexa_info;
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
    deinitConfig(&gHexConfig_cdsp);

    if (hexagon_vtlb_entries_cdsp)
        free(hexagon_vtlb_entries_cdsp);
}

static int hexagon_mmu_cdsp(struct target *target, int *enabled)
{
    uint64_t syscfg, retval;

    retval = hexagon_read_syscfg_register_cdsp(target);
    hexagon_stuff_reg_restore_r7_cdsp(target);
    if (retval == ERROR_OK)
        syscfg = hexagon_syscfg_reg_cdsp;
    else
        syscfg = global_reg_cdsp[2];

    struct hexagon_mmu_common_cdsp *mmu = (struct hexagon_mmu_common_cdsp *)&(target_to_hexagon_cdsp(target)->hexa_info.hexagon_mmu);

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

    *enabled = target_to_hexagon_cdsp(target)->hexa_info.hexagon_mmu.mmu_enabled;
    return ERROR_OK;
}

struct target_type hexagon_cdsp_target = 
{
    .name = "hexagon_cdsp",
    .poll = hexagon_poll_cdsp,
    .arch_state = hexagon_arch_state_cdsp,
    .target_request_data = NULL,
    .resume = hexagon_resume_cdsp,
    .step = hexagon_step_cdsp,
    .halt = hexagon_halt_cdsp,
    .assert_reset = NULL,
    .deassert_reset = NULL,
    .soft_reset_halt = NULL,
    .get_gdb_arch = hexagon_get_gdb_arch_cdsp,
    .get_gdb_reg_list = hexagon_get_gdb_reg_list_cdsp,
    .get_gdb_reg_list_noread = hexagon_get_gdb_reg_list_cdsp,
    .read_memory = hexagon_read_memory_cdsp,
    .write_memory = hexagon_write_memory_cdsp,
    .read_buffer = hexagon_read_buffer_cdsp,
    .write_buffer = hexagon_write_buffer_cdsp,
    .checksum_memory = NULL,
    .blank_check_memory = NULL,
    .add_breakpoint = hexagon_add_breakpoint_cdsp,
    .add_context_breakpoint = NULL,
    .add_hybrid_breakpoint = NULL,
    .remove_breakpoint = hexagon_remove_breakpoint_cdsp,
    .add_watchpoint = NULL,
    .remove_watchpoint = NULL,
    .hit_watchpoint = NULL,
    .commands = hexagon_command_handlers_cdsp,
    .target_create = hexagon_target_create_cdsp,
    .target_jim_configure = hexagon_jim_configure_cdsp,
    .target_jim_commands = NULL,
    .examine = hexagon_examine_cdsp,
    .init_target = hexagon_init_target_cdsp,
    .deinit_target = hexagon_deinit_target_cdsp,
    .virt2phys = hexagon_virt2phys_cdsp,
    .mmu = hexagon_mmu_cdsp,
    .check_reset = NULL,
    .get_gdb_fileio_info = NULL,
    .gdb_fileio_end = NULL,
    .profiling = NULL,
    .address_bits = NULL
};
