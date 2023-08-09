/**************************************************************************
*	Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*																		  *
***************************************************************************/

#ifndef OPENOCD_TARGET_HEXAGON_CDSP_H
#define OPENOCD_TARGET_HEXAGON_CDSP_H

#include "armv8.h"

/*******************************Common MACRO for Feature control********************************************/

#if 0
#define _BITRA_TARGET_CDSP
#define _CEDROS_TARGET_CDSP
#define _KODIAK_TARGET_CDSP
#define _VTLB_ENABLED_CDSP
#define _MANNAR_TARGET_CDSP
#define _DEBUG_HEXAGON_CDSP_
#define _AGATTI_TARGET_CDSP
#endif

//#define _BITRA_TARGET_CDSP
#define _KODIAK_TARGET_CDSP
#define _HEXAGON_TARGET_TIME_PROFILING_CDSP

// #define _VTLB_ENABLED_CDSP

/* define this macro when we need to fetch VTLB using AXI */
//#define HEXAGON_VTLB_AXI_CDSP

/* define this macro when we need to fetch VTLB using MEM_PHYS */
#define HEXAGON_VTLB_MEM_PHYS_CDSP

/* define this macro when we need to fetch VTLB using MEMW interface */
//#define HEXAGON_VTLB_MEMW_CDSP



#if defined(_BITRA_TARGET_CDSP)
#define HEXAGON_VTLB_OLD_ARCH_CDSP
#endif

#if defined(_KODIAK_TARGET_CDSP)
#define HEXAGON_VTLB_NEW_ARCH_CDSP
#endif

/***************************************************************************/

#define HEXAGON_COMMON_MAGIC_CDSP 0xD2D2D2D2 //TDB

#define HEXAGON_QDSP6SS_WDOG_DISABLE_CDSP 0x0
#define HEXAGON_QDSP6SS_WDOG_ENABLE_CDSP 0x7

#define HEXAGON_MAX_ISDB_REG_CDSP 17

/** ISDB register offsets w.r.t Hexagon debug_base (Sec:13.5) **/
#define HEXAGON_ISDB_ISDBST_CDSP 0x00
#define HEXAGON_ISDB_ISDBCFG0_CDSP 0x04
#define HEXAGON_ISDB_ISDBCFG1_CDSP 0x08
#define HEXAGON_ISDB_BRKPTINFO_CDSP 0x0C
#define HEXAGON_ISDB_BRKPTPC0_CDSP 0x10
#define HEXAGON_ISDB_BRKPTCFG0_CDSP 0x14
#define HEXAGON_ISDB_BRKPTPC1_CDSP 0x18
#define HEXAGON_ISDB_BRKPTCFG1_CDSP 0x1C
#define HEXAGON_ISDB_STFINST_CDSP 0x20
#define HEXAGON_ISDB_ISDBMBXIN_CDSP 0x24
#define HEXAGON_ISDB_ISDBMBXOUT_CDSP 0x28
#define HEXAGON_ISDB_ISDBCMD_CDSP 0x2C
#define HEXAGON_ISDB_ISDBEN_CDSP 0x30
#define HEXAGON_ISDB_ISDBVER_CDSP 0x34
#define HEXAGON_ISDB_COREVER_CDSP 0x38
#define HEXAGON_ISDB_ISDBGPR_CDSP 0x3C
#define HEXAGON_ISDB_ISDBCST_CDSP 0x40

#define HEXAGON_ALL_ISDB_REG_CDSP 0xAA

/** SYSCFG register field **/
#define SYSCFG_L2NRA_CDSP (0x1 << 22)
#define SYSCFG_L2NWA_CDSP (0x1 << 21)
#define SYSCFG_L2WB_CDSP (0x1 << 23)

/** ISDB status register fields **/
#define ISDBST_ISDB_READY_CDSP (0x1 << 0)
#define ISDBST_ISDB_MAILBOX_OUT_CDSP (0x1 << 1)
#define ISDBST_ISDB_MAILBOX_IN_CDSP (0x1 << 2)
#define ISDBST_ISDB_CMD_STATUS_CDSP (0x1 << 4)
#define ISDBST_STUFF_CMD_STATUS_CDSP (0x1 << 5)
#define ISDBST_DEBUG_MODE_STATUS_CDSP (0xFF << 8)
#define ISDBST_OFF_MODE_STATUS_CDSP (0xF << 16)
#define ISDBST_WAITRUN_MODE_STATUS_CDSP (0xF << 24)

/** ISDB configuration register0 fields **/
#define ISDBCFG0_ETMBRKPT_TNUM_MASK_CDSP (0x3F << 0)
#define ISDBCFG0_EXTBRKPT_TNUM_MASK_CDSP (0xF << 8)
#define ISDBCFG0_EXTRESUME_TNUM_MASK_CDSP (0xF << 16)
#define ISDBCFG0_GLOBAL_INT_DISABLE_CDSP (0x1 << 24)
#define ISDBCFG0_HW_BREAKPOINT0_CDSP (0x1 << 25)
#define ISDBCFG0_HW_BREAKPOINT1_CDSP (0x1 << 26)

/** ISDB configuration register1 fields **/
#define ISDBCFG1_BRK_EVENT_TNUM_MASK_CDSP (0xF << 0)
#define ISDBCFG1_SWBRKPT_TNUM_MASK_CDSP (0xF << 8)
#define ISDBCFG1_BREAK0_TNUM_MASK_CDSP (0xF << 16)
#define ISDBCFG1_BREAK1_TNUM_MASK_CDSP (0xF << 24)

/** Break point information register fields **/
#define BRKPTINFO_THREAD0_BRKPT_SOURCE_CDSP (0x7 << 0)
#define BRKPTINFO_THREAD1_BRKPT_SOURCE_CDSP (0x7 << 3)
#define BRKPTINFO_THREAD2_BRKPT_SOURCE_CDSP (0x7 << 6)
#define BRKPTINFO_THREAD3_BRKPT_SOURCE_CDSP (0x7 << 9)
#define BRKPTINFO_THREAD4_BRKPT_SOURCE_CDSP (0x7 << 12)
#define BRKPTINFO_THREAD5_BRKPT_SOURCE_CDSP (0x7 << 15)

/** Break point PC register fields **/
#define BRKPTPC_0_1_BRKPTPC_CDSP (0x3FFFFFFF << 2)

/** ISDB Command register fields **/
#define ISDBCMD_CMD_BREAK_CDSP (0x1 << 0)
#define ISDBCMD_CMD_RESUME_CDSP (0x2 << 0)
#define ISDBCMD_CMD_ISTEP_CDSP (0x3 << 0)
#define ISDBCMD_CMD_STUFF_CDSP (0x4 << 0)
#define ISDBCMD_CMD_RST_ASSRT_CDSP (0x5 << 0)
#define ISDBCMD_CMD_INTRPT_CDSP (0x6 << 0)
#define ISDBCMD_CMD_RST_RELEASE_CDSP (0x7 << 0)

#define ISDBCMD_USER_LVL_CDSP (0x0 << 6)
#define ISDBCMD_GUEST_LVL_CDSP (0x1 << 6)
#define ISDBCMD_MONITOR_LVL_CDSP (0x2 << 6)
#define ISDBCMD_TNUM_MASK_4_CDSP (0xF << 8)
#define ISDBCMD_TNUM_MASK_6_CDSP (0x3F << 8)
#define ISDBCMD_TNUM_MASK_THREAD_CDSP(A) (0x1 << (8 + A))

/** ISDB Enable register fields **/
#define ISDBEN_APB_ISDB_EN_CDSP (0x1 << 0)
#define ISDBEN_ISDB_CLK_OFF_CDSP (0x1 << 1)
#define ISDBEN_SECURE_EN_CDSP (0x1 << 2)
#define ISDBEN_ISDB_TRUSTED_CDSP (0x1 << 3)
#define ISDBEN_ISDB_PREVNT_PWRDWN_CDSP (0x1 << 4)
#define ISDBEN_SECURITY_DFD_EN_STATUS_CDSP (0x1 << 5)
#define ISDBEN_SECURITY_ETM_EN_STATUS_CDSP (0x1 << 6)

/** ISDB Version register fields **/
#define COREVER_ISA_CDSP (0xFF << 0)
#define COREVER_ID_CDSP (0xFF << 8)
#define COREVER_LAYER_CDSP (0xF << 16)
#define COREVER_UID_CDSP (0xF << 20)
#define COREVER_METAL_CDSP (0xFF << 24)

/** ISDB Core Status register fields **/
#define ISDBCST_ALLWIAT_CDSP (0x1 << 1)
#define ISDBCST_RESET_OR_PC_CDSP (0x1 << 2)
#define ISDBCST_AXIM_BUS_ISO_CDSP (0x1 << 3)
#define ISDBCST_AXIM2_BUS_ISO_CDSP (0x1 << 4)

/** page table related macros **/
#define VIRT_PAGE_CDSP(hi) (hi & 0xfffff)
#define PAGE_VALS_CDSP(lo) (lo == 1 ? "4KB" : (lo == 2 ? "16KB" : (lo == 4 ? "64KB" : (lo == 8 ? "256KB" : (lo == 16 ? "1MB" : (lo == 32 ? "4MB" : "16MB"))))))
#define ASID_CDSP(hi) ((hi >> 20) & 0x7f)
#define P_READ_CDSP(lo) ((lo >> 29) & 0x01)
#define P_WRITE_CDSP(lo) ((lo >> 30) & 0x01)
#define P_EXEC_CDSP(lo) ((lo >> 31) & 0x01)
#define P_USER_CDSP(lo) ((lo >> 28) & 0x01)
#define P_CCCC_CDSP(lo) ((lo >> 24) & 0x0f)
#define P_S_CDSP(lo) ((lo >> 0) & 0x01)
#define P_V_CDSP(hi) ((hi >> 31) & 0x01)
#define P_G_CDSP(hi) ((hi >> 30) & 0x01)
#define P_EP_CDSP(hi) ((hi >> 29) & 0x01)
#define P_A1_CDSP(hi) ((hi >> 28) & 0x01)
#define P_A0_CDSP(hi) ((hi >> 27) & 0x01)

#define PAGE_SIZE_CDSP(lo, mask) PAGE_VALS_CDSP((lo & mask))

#define HEXAGON_PAGE_SIZE_4K_CDSP (0x00001000)
#define HEXAGON_PAGE_SIZE_16K_CDSP (0x00004000)
#define HEXAGON_PAGE_SIZE_64K_CDSP (0x00010000)
#define HEXAGON_PAGE_SIZE_256K_CDSP (0x00040000)
#define HEXAGON_PAGE_SIZE_1M_CDSP (0x00100000)
#define HEXAGON_PAGE_SIZE_4M_CDSP (0x00400000)
#define HEXAGON_PAGE_SIZE_16M_CDSP (0x01000000)

enum hexagon_hw_thread_CDSP
{
    HEXAGON_HW_THREAD0_CDSP = 0,
    HEXAGON_HW_THREAD1_CDSP,
    HEXAGON_HW_THREAD2_CDSP,
    HEXAGON_HW_THREAD3_CDSP,
    HEXAGON_HW_THREAD4_CDSP,
    HEXAGON_HW_THREAD5_CDSP,
    HEXAGON_HW_THREAD_ALL_CDSP
};

enum hexagon_registers_CDSP
{
    /** General Purpose Registers(32) **/
    HEXAGON_R0_CDSP = 0,
    HEXAGON_R1_CDSP,
    HEXAGON_R2_CDSP,
    HEXAGON_R3_CDSP,
    HEXAGON_R4_CDSP,
    HEXAGON_R5_CDSP,
    HEXAGON_R6_CDSP,
    HEXAGON_R7_CDSP,
    HEXAGON_R8_CDSP,
    HEXAGON_R9_CDSP,
    HEXAGON_R10_CDSP,
    HEXAGON_R11_CDSP,
    HEXAGON_R12_CDSP,
    HEXAGON_R13_CDSP,
    HEXAGON_R14_CDSP,
    HEXAGON_R15_CDSP,
    HEXAGON_R16_CDSP,
    HEXAGON_R17_CDSP,
    HEXAGON_R18_CDSP,
    HEXAGON_R19_CDSP,
    HEXAGON_R20_CDSP,
    HEXAGON_R21_CDSP,
    HEXAGON_R22_CDSP,
    HEXAGON_R23_CDSP,
    HEXAGON_R24_CDSP,
    HEXAGON_R25_CDSP,
    HEXAGON_R26_CDSP,
    HEXAGON_R27_CDSP,
    HEXAGON_R28_CDSP,
    HEXAGON_SP_CDSP,
    HEXAGON_FP_CDSP,
    HEXAGON_LR_CDSP = 31,
    HEXAGON_GPR_MAX_CDSP = 32,

    /** Control Registers(32) **/
    HEXAGON_SA0_CDSP = 32,    /* C0  */
    HEXAGON_LC0_CDSP,         /* C1  */
    HEXAGON_SA1_CDSP,         /* C2  */
    HEXAGON_LC1_CDSP,         /* C3  */
    HEXAGON_P30_CDSP,         /* C4  */
    HEXAGON_C5_RESRV_CDSP,    /* C5 - reserved */
    HEXAGON_M0_CDSP,          /* C6  */
    HEXAGON_M1_CDSP,          /* C7  */
    HEXAGON_USR_CDSP,         /* C8  */
    HEXAGON_PC_CDSP,          /* C9  */
    HEXAGON_UGP_CDSP,         /* C10 */
    HEXAGON_GP_CDSP,          /* C11 */
    HEXAGON_CS0_CDSP,         /* C12 */
    HEXAGON_CS1_CDSP,         /* C13 */
    HEXAGON_UPCYCLLO_CDSP,    /* C14 */
    HEXAGON_UPCYCLHI_CDSP,    /* C15 */
    HEXAGON_FLMT_CDSP,        /* C16 */
    HEXAGON_FKEY_CDSP,        /* C17 */
    HEXAGON_PKTCNTLO_CDSP,    /* C18 */
    HEXAGON_PKTCNTHI_CDSP,    /* C19 */
    HEXAGON_C20_RESRV_CDSP,   /* C20 - reserved */
    HEXAGON_C21_RESRV_CDSP,   /* C21 - reserved */
    HEXAGON_C22_RESRV_CDSP,   /* C22 - reserved */
    HEXAGON_C23_RESRV_CDSP,   /* C23 - reserved */
    HEXAGON_C24_RESRV_CDSP,   /* C24 - reserved */
    HEXAGON_C25_RESRV_CDSP,   /* C25 - reserved */
    HEXAGON_C26_RESRV_CDSP,   /* C26 - reserved */
    HEXAGON_C27_RESRV_CDSP,   /* C27 - reserved */
    HEXAGON_C28_RESRV_CDSP,   /* C28 - reserved */
    HEXAGON_C29_RESRV_CDSP,   /* C29 - reserved */
    HEXAGON_UTMRLO_CDSP,      /* C30 */
    HEXAGON_UTMRHI_CDSP = 63, /* C31 */
    HEXAGON_CTRL_MAX_CDSP = 64,

    /** Monitor Mode per-thread Control Registers(16) **/
    HEXAGON_SGP0_CDSP = 64,      /* S0  */
    HEXAGON_SGP1_CDSP,           /* S1  */
    HEXAGON_STID_CDSP,           /* S2  */
    HEXAGON_ELR_CDSP,            /* S3  */
    HEXAGON_BADVA0_CDSP,         /* S4  */
    HEXAGON_BADVA1_CDSP,         /* S5  */
    HEXAGON_SSR_CDSP,            /* S6  */
    HEXAGON_CCR_CDSP,            /* S7  */
    HEXAGON_HTID_CDSP,           /* S8  */
    HEXAGON_BADVA_CDSP,          /* S9  */
    HEXAGON_IMASK_CDSP,          /* S10 */
    HEXAGON_GEVB_CDSP,           /* S11 */
    HEXAGON_S12_RESRV_CDSP,      /* S12 - reserved */
    HEXAGON_S13_RESRV_CDSP,      /* S13 - reserved */
    HEXAGON_S14_RESRV_CDSP,      /* S14 - reserved */
    HEXAGON_S15_RESRV_CDSP = 79, /* S15 - reserved */
    HEXAGON_MMODE_PERTHRD_MAX_CDSP = 80,

    /** Monitor Mode Global Control Registers(16) **/
    HEXAGON_EVB_CDSP = 80,      /* S16 */
    HEXAGON_MODECTL_CDSP,       /* S17 */
    HEXAGON_SYSCFG_CDSP,        /* S18 */
    HEXAGON_S19_RESRV_CDSP,     /* S19 - reserved */
    HEXAGON_IPENDAD_CDSP,       /* S20 */
    HEXAGON_VID_CDSP,           /* S21 */
    HEXAGON_VID1_CDSP,          /* S22 */
    HEXAGON_BESTWAIT_CDSP,      /* S23 */
    HEXAGON_S24_RESRV_CDSP,     /* S24 - reserved  */
    HEXAGON_SCHDCFG_CDSP,       /* S25 */
    HEXAGON_S26_RESRV_CDSP,     /* S26 - reserved  */
    HEXAGON_CFGBASE_CDSP,       /* S27 */
    HEXAGON_DIAG_CDSP,          /* S28 */
    HEXAGON_REV_CDSP,           /* S29 */
    HEXAGON_PCYCLELO_CDSP,      /* S30 */
    HEXAGON_PCYCLEHI_CDSP = 95, /* S31 */
    HEXAGON_MMODE_GLOBAL_MAX_CDSP = 96,

    /** ISDB registers(12) **/
    HEXAGON_ISDBST_CDSP = 96, /* S32 */
    HEXAGON_ISDBCF0_CDSP,     /* S33 */
    HEXAGON_ISDBCFG1_CDSP,    /* S34 */
    HEXAGON_LIVELOCK_CDSP,    /* S35 */
    HEXAGON_BRKPTPC0_CDSP,    /* S36 */
    HEXAGON_BRKPTCFG0_CDSP,   /* S37 */
    HEXAGON_BRKPTPC1_CDSP,    /* S38 */
    HEXAGON_BRKPTCFG1_CDSP,   /* S39 */
    HEXAGON_ISDBMBXIN_CDSP,   /* S40 */
    HEXAGON_ISDBMBXOUT_CDSP,  /* S41 */
    HEXAGON_ISDBEN_CDSP,      /* S42 */
    HEXAGON_ISDBGPR_CDSP,     /* S43 */

    /** Perf Monitor registers(15) **/
    HEXAGON_PMUCNT4_CDSP,    /* S44 */
    HEXAGON_PMUCNT5_CDSP,    /* S45 */
    HEXAGON_PMUCNT6_CDSP,    /* S46 */
    HEXAGON_PMUCNT7_CDSP,    /* S47 */
    HEXAGON_PMUCNT0_CDSP,    /* S48 */
    HEXAGON_PMUCNT1_CDSP,    /* S49 */
    HEXAGON_PMUCNT2_CDSP,    /* S50 */
    HEXAGON_PMUCNT3_CDSP,    /* S51 */
    HEXAGON_PMUEVTCFG_CDSP,  /* S52 */
    HEXAGON_PMUSTID0_CDSP,   /* S53 */
    HEXAGON_PMUEVTCFG1_CDSP, /* S54 */
    HEXAGON_PMUSTID1_CDSP,   /* S55 */
    HEXAGON_TIMERLO_CDSP,    /* S56 */
    HEXAGON_TIMERHI_CDSP,    /* S57 */
    HEXAGON_PMUCFG1_CDSP,    /* S58 */

    HEXAGON_S59_RESRV_CDSP, /* S59 */
    HEXAGON_S60_RESRV_CDSP, /* S60 */
    HEXAGON_S61_RESRV_CDSP, /* S61 */
    HEXAGON_S62_RESRV_CDSP, /* S62 */
    HEXAGON_S63_RESRV_CDSP, /* S63 */

    HEXAGON_LAST_REG_CDSP = 128
};

/* Hexagon Registers info */
#define HEXAGON_GPR_REGS_CDSP HEXAGON_GPR_MAX_CDSP
#define HEXAGON_PER_THREAD_CTRL_REGS_CDSP (HEXAGON_MMODE_PERTHRD_MAX_CDSP - HEXAGON_GPR_MAX_CDSP)
#define HEXAGON_PER_THREAD_REGS_CDSP HEXAGON_MMODE_PERTHRD_MAX_CDSP
#define HEXAGON_GLOBAL_REGS_CDSP (HEXAGON_MMODE_GLOBAL_MAX_CDSP - HEXAGON_MMODE_PERTHRD_MAX_CDSP)
#define HEXAGON_NUM_REGS_CDSP HEXAGON_MMODE_GLOBAL_MAX_CDSP

#define HEXAGON_PER_THREAD_RESV_REGS_CDSP 15
#define HEXAGON_GLOBAL_RESV_REGS_CDSP 3
#define HEXAGON_VALID_PER_THREAD_REGS_CDSP (HEXAGON_MMODE_PERTHRD_MAX_CDSP - HEXAGON_PER_THREAD_RESV_REGS_CDSP)
#define HEXAGON_VALID_GLOBAL_REGS_CDSP (HEXAGON_MMODE_GLOBAL_MAX_CDSP - HEXAGON_MMODE_PERTHRD_MAX_CDSP - HEXAGON_GLOBAL_RESV_REGS_CDSP)

#ifdef _BITRA_TARGET_CDSP
#define HEXAGON_TLB_ENTRIES_NUM_CDSP 128
#endif

#ifdef _KODIAK_TARGET_CDSP
#define HEXAGON_TLB_ENTRIES_NUM_CDSP 128
#endif

//#define hexagon_pack_isdbcmd(cmd, prilvl, thrdmsk) ((cmd) | (prilvl << 6) | (prilvl << 6))
#define hexagon_pack_isdbcmd_cdsp(cmd, prilvl, thrdmsk) ((cmd) | (prilvl) | (thrdmsk))

typedef struct
{
    unsigned id;
    const char *name;
    unsigned bits;
    enum reg_type type;
    const char *group;
    const char *feature;
    struct reg_data_type *data_type;
} hexagon_reg_cdsp;

#define HEXAGON_MAX_HW_BPS_CDSP 2
#define HEXAGON_MAX_SW_BPS_CDSP 8

/******************/
/******************/

#define PAGE_SIZE_4KB_CDSP 0x1000
#define PAGE_SIZE_4KB_LEVEL0_BITS_CDSP 39
#define PAGE_SIZE_4KB_LEVEL1_BITS_CDSP 30
#define PAGE_SIZE_4KB_LEVEL2_BITS_CDSP 21
#define PAGE_SIZE_4KB_LEVEL3_BITS_CDSP 12

#define PAGE_SIZE_4KB_LEVEL0_MASK_CDSP ((0x1FFULL) << PAGE_SIZE_4KB_LEVEL0_BITS_CDSP)
#define PAGE_SIZE_4KB_LEVEL1_MASK_CDSP ((0x1FFULL) << PAGE_SIZE_4KB_LEVEL1_BITS_CDSP)
#define PAGE_SIZE_4KB_LEVEL2_MASK_CDSP ((0x1FFULL) << PAGE_SIZE_4KB_LEVEL2_BITS_CDSP)
#define PAGE_SIZE_4KB_LEVEL3_MASK_CDSP ((0x1FFULL) << PAGE_SIZE_4KB_LEVEL3_BITS_CDSP)

#define PAGE_SIZE_4KB_TRBBASE_MASK_CDSP 0xFFFFFFFFF000

enum hexagon_opcode_cdsp
{
    READ_REG_R0_CDSP,
    READ_REG_R1_CDSP,
    READ_REG_R2_CDSP,
    READ_REG_R3_CDSP,
    READ_REG_R4_CDSP,
    READ_REG_R5_CDSP,
    READ_REG_R6_CDSP,
    READ_REG_R7_CDSP,
    READ_REG_R8_CDSP,
    READ_REG_R9_CDSP,
    READ_REG_R10_CDSP,
    READ_REG_R11_CDSP,
    READ_REG_R12_CDSP,
    READ_REG_R13_CDSP,
    READ_REG_R14_CDSP,
    READ_REG_R15_CDSP,
    READ_REG_R16_CDSP,
    READ_REG_R17_CDSP,
    READ_REG_R18_CDSP,
    READ_REG_R19_CDSP,
    READ_REG_R20_CDSP,
    READ_REG_R21_CDSP,
    READ_REG_R22_CDSP,
    READ_REG_R23_CDSP,
    READ_REG_R24_CDSP,
    READ_REG_R25_CDSP,
    READ_REG_R26_CDSP,
    READ_REG_R27_CDSP,
    READ_REG_R28_CDSP,
    READ_REG_R29_CDSP,
    READ_REG_R30_CDSP,
    READ_REG_R31_CDSP,
    BRKPT_CDSP,
    HEXA_OPCODE_MAX_CDSP
};

static const uint32_t hexagon_opcodes_cdsp[HEXA_OPCODE_MAX_CDSP] = {
    [READ_REG_R0_CDSP] = 0x6700c029,
    [READ_REG_R1_CDSP] = 0x6701c029,
    [READ_REG_R2_CDSP] = 0x6702c029,
    [READ_REG_R3_CDSP] = 0x6703c029,
    [READ_REG_R4_CDSP] = 0x6704c029,
    [READ_REG_R5_CDSP] = 0x6705c029,
    [READ_REG_R6_CDSP] = 0x6706c029,
    [READ_REG_R7_CDSP] = 0x6707c029,
    [READ_REG_R8_CDSP] = 0x6708c029,
    [READ_REG_R9_CDSP] = 0x6709c029,
    [READ_REG_R10_CDSP] = 0x670ac029,
    [READ_REG_R11_CDSP] = 0x670bc029,
    [READ_REG_R12_CDSP] = 0x670cc029,
    [READ_REG_R13_CDSP] = 0x670dc029,
    [READ_REG_R14_CDSP] = 0x670ec029,
    [READ_REG_R15_CDSP] = 0x670fc029,
    [READ_REG_R16_CDSP] = 0x6710c029,
    [READ_REG_R17_CDSP] = 0x6711c029,
    [READ_REG_R18_CDSP] = 0x6712c029,
    [READ_REG_R19_CDSP] = 0x6713c029,
    [READ_REG_R20_CDSP] = 0x6714c029,
    [READ_REG_R21_CDSP] = 0x6715c029,
    [READ_REG_R22_CDSP] = 0x6716c029,
    [READ_REG_R23_CDSP] = 0x6717c029,
    [READ_REG_R24_CDSP] = 0x6718c029,
    [READ_REG_R25_CDSP] = 0x6719c029,
    [READ_REG_R26_CDSP] = 0x671ac029,
    [READ_REG_R27_CDSP] = 0x671bc029,
    [READ_REG_R28_CDSP] = 0x671cc029,
    [READ_REG_R29_CDSP] = 0x671dc029,
    [READ_REG_R30_CDSP] = 0x671ec029,
    [READ_REG_R31_CDSP] = 0x671fc029,
    [BRKPT_CDSP] = 0x6c20c000,
};

/** All H/w threads on some debub reason ? **/
#define HEXA_DEBUG_ENTRY_CDSP(x) (x & 0x7)

/* Cause of entry into debug mode */
#define HEXA_DBG_HWBRKPT0_CDSP (0x0)
#define HEXA_DBG_HWBRKPT1_CDSP (0x1)
#define HEXA_DBG_SWBRKPT_CDSP (0x2)
#define HEXA_DBG_ETMBRKPT_CDSP (0x3)
#define HEXA_DBG_APBBRKPT_CDSP (0x4)
#define HEXA_DBG_EXTBRKPT_CDSP (0x5)

struct hexagon_brp_cdsp
{
    int used;
    int type;
    target_addr_t value;
    uint32_t control;
    uint8_t BRPn;
};

enum hexagon_isrmasking_mode_cdsp
{
    HEXAGON_ISRMASK_OFF_CDSP,
    HEXAGON_ISRMASK_ON_CDSP,
};

union fourbyte_cdsp
{
    uint32_t word;
    uint16_t hword[2];
    uint8_t byte[4];
};

struct hexa_reg_cdsp
{

    /** Invoke before a series of instruction operations */
    int (*prepare)(hexagon_reg_cdsp *);

    /** Invoke after a series of instruction operations */
    int (*finish)(hexagon_reg_cdsp *);

    /** Runs one instruction. */
    int (*instr_execute)(hexagon_reg_cdsp *, uint32_t opcode);

    /** Runs one instruction, writing data to R0 before execution. */
    int (*instr_write_data_r0)(hexagon_reg_cdsp *,
                               uint32_t opcode, uint32_t data);

    /** Runs one instruction, reading data from r0 after execution. */
    int (*instr_read_data_r0)(hexagon_reg_cdsp *,
                              uint32_t opcode, uint32_t *data);

    struct reg *(*hexagon_reg_current_cdsp)(struct hexa_info_cdsp *hexa_info,
                                            unsigned int regnum, struct reg_cache *cache);
};

struct hexa_bp_cdsp
{
    unsigned number;
    uint32_t address;
    uint32_t control;
    /* true if hardware state needs flushing */
    bool dirty;
};

struct hexa_brkpt_cdsp
{
    /* BREAKPOINT SUPPORT */

    /**
     * Enables one breakpoint or watchpoint by writing to the
     * hardware registers.  The specified breakpoint/watchpoint
     * must currently be disabled.  Indices 0..15 are used for
     * breakpoints; indices 16..31 are for watchpoints.
     */
    int (*hwbp_enable)(struct hexa_brkpt_cdsp *, unsigned index_value,
                       uint32_t addr, uint32_t control);

    int (*swbp_enable)(struct hexa_brkpt_cdsp *, unsigned index_value,
                       uint32_t addr, uint32_t control);

    /**
     * Disables one breakpoint or watchpoint by clearing its
     * hardware control registers.  Indices are the same ones
     * accepted by bpwp_enable().
     */
    int (*hwbp_disable)(struct hexa_brkpt_cdsp *, unsigned index_value);
    int (*swbp_disable)(struct hexa_brkpt_cdsp *, unsigned index_value);

    /* The breakpoint and watchpoint arrays are private to the
     * DPM infrastructure.  There are nbp indices in the dbp
     * array.  There are nwp indices in the dwp array.
     */

    unsigned nhwbp;
    struct hexa_bp_cdsp *dhwbp;
    unsigned nswbp;
    struct hexa_bp_cdsp *dswbp;
};

struct hexagon_mmu_common_cdsp
{

    uint32_t mmu_enabled;
    uint32_t instrution_cache_enabled;
    uint32_t data_cache_enabled;
};

struct hexa_info_cdsp
{

    /* Hold the last read ISDB registers values */
    uint32_t isdb_ver;
    uint32_t corever;
    uint32_t isdb_enable;
    uint32_t isdb_status;
    uint32_t isdb_cstatus;
    uint32_t brkptinfo;

    /** Backpointer to the target. */
    struct target *target;

    /** pointer for arch **/
    void *arch_info;

    /** For targets conforming to ARM Debug Interface v5,
     * this handle references the Debug Access Port (DAP)
     * used to make requests to the target.
     */
    struct adiv5_dap *dap;
    uint32_t debug_base;
    struct adiv5_ap *debug_ap;
    struct reg_cache *core_cache;

    /** Handle to the PC; valid in all core modes. */
    struct reg *pc;

    struct hexa_reg_cdsp reg;

    /** Retrieve all Hw thread registers, for display. */
    int (*full_context)(struct target *target);

    /** Retrieve a single Hw thread  register. */
    int (*read_core_reg)(struct target *target, struct reg *r, int regnum, uint32_t hwthrd);
    int (*write_core_reg)(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
    const int *map;
    const uint32_t *opcodes;
    struct hexa_brkpt_cdsp brkpt;
    struct hexagon_mmu_common_cdsp hexagon_mmu;

    /* last run-control command issued to this target (resume, halt, step) */
    enum run_control_op last_run_control_op;
};

struct hexagon_common_cdsp
{

    struct hexa_info_cdsp hexa_info;
    int common_magic;
    /* Context information */
    uint32_t system_control_reg;
    uint32_t system_control_reg_curr;
    /* Breakpoint register pairs */
    int brp_num_context;
    int brp_num;
    int brp_num_available;
    struct hexagon_brp_cdsp *brp_list;
    enum hexagon_isrmasking_mode_cdsp isrmasking_mode;
};

struct hex_reg_cdsp
{
    int num;
    uint32_t hwthrd;
    struct target *target;
    struct hexa_info_cdsp *hexa_info;
    uint8_t value[16];
};

struct hexagon_private_config_cdsp
{
    struct adiv5_private_config adiv5_config;
    struct arm_cti *cti;
};

static inline struct hexagon_common_cdsp *
target_to_hexagon_cdsp(struct target *target)
{
    return container_of(target->arch_info, struct hexagon_common_cdsp, hexa_info);
}

/* this enum for page  size */
enum hexagon_page_size_CDSP
{
    HEXAGON_TLB_PAGE_SIZE_4KB_CDSP,
    HEXAGON_TLB_PAGE_SIZE_16KB_CDSP,
    HEXAGON_TLB_PAGE_SIZE_64KB_CDSP,
    HEXAGON_TLB_PAGE_SIZE_256KB_CDSP,
    HEXAGON_TLB_PAGE_SIZE_1MB_CDSP,
    HEXAGON_TLB_PAGE_SIZE_4MB_CDSP,
    HEXAGON_TLB_PAGE_SIZE_16MB_CDSP,
};

/* data structure contains the data of TLB entry parsing*/

typedef struct
{
    uint64_t phy_add_low;
    uint64_t phy_add_high;
    uint32_t virt_add_low;
    uint32_t virt_add_high;
    uint32_t virt_tlb_raw_data;
    uint32_t phys_tlb_raw_data;
    uint32_t virt_page : 20;
    uint32_t phy_page : 24;
    enum hexagon_page_size_CDSP page_size;
    uint8_t asid : 7;
    uint8_t CCCC : 4;
    uint8_t validbit : 1;
    uint8_t globalbit : 1;
    uint8_t EP : 1;
    uint8_t A0 : 1;
    uint8_t A1 : 1;
    uint8_t S : 1;
    uint8_t R : 1;
    uint8_t W : 1;
    uint8_t X : 1;
    uint8_t U : 1;
} tlb_entries_cdsp __attribute__((packed));

#ifdef HEXAGON_VTLB_NEW_ARCH_CDSP
typedef struct
{
    uint32_t vtlb_version : 4;               // version info
    uint32_t vtlb_table_type : 3;            // Descriptor type
    uint32_t next_table_addr_is_virtual : 1; // next element is virtual or physical
    uint64_t next_table_addr : 36;           // table address where the descriptor type elements start from
    uint32_t table_entries : 20;             // Number of entries of the descriptor type
} qurtk_vtlb_table_descriptor_cdsp __attribute__((packed));
#endif

/* data structure contains the data related to QURTK_vtlb_main for fetching vtlb entries */
typedef struct
{
    uint32_t vtlb_previous_counter;
    uint32_t vtlb_current_counter;
    uint32_t vtlb_no_of_entries;
    uint32_t vtlb_no_of_entries1;
    uint32_t valid_vtlb_no_of_entries;
    uint32_t QURTK_vtlb_main_VA;
    uint32_t QURTK_vtlb_main_PA;
    uint32_t QURTK_VTLB_DATA_VA;
    uint32_t QURTK_VTLB_DATA_PA;
#ifdef HEXAGON_VTLB_NEW_ARCH_CDSP
    qurtk_vtlb_table_descriptor_cdsp qurtk_vtlb_main;
    qurtk_vtlb_table_descriptor_cdsp qurtk_vtlb_main_next;
#endif

} vtlb_data_cdsp __attribute__((packed));

/* data structure for Virtual Page entry parsing */
union pg_tlbhi_t_cdsp
{
    struct
    {
        unsigned int vir_addr : 20;
        unsigned int asid : 7;
        unsigned int a0 : 1;
        unsigned int a1 : 1;
        unsigned int ep : 1;
        unsigned int global : 1;
        unsigned int valid : 1;
    } info;
    unsigned int raw;
} __attribute__((packed));

/* data structure for Physical Page entry parsing */
union pg_tlblo_t_cdsp
{
    struct
    {
        unsigned int phys_addr : 24;
        unsigned int cache : 4;
        unsigned int usr : 1;
        unsigned int perm : 3;
    } info;
    unsigned int raw;
} __attribute__((packed));

#endif /* OPENOCD_TARGET_HEXAGON_H_CDSP */
