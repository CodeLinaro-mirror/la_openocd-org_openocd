/**************************************************************************
*	Copyright (c) 2023 Qualcomm Innovation Center, Inc.                   *
*   All rights reserved.                                                  * 
*   SPDX-License-Identifier: GPL-2.0-or-later                             * 
*																		  *
***************************************************************************/

#ifndef OPENOCD_TARGET_HEXAGON_ADSP_H
#define OPENOCD_TARGET_HEXAGON_ADSP_H

#include "armv8.h"

/*******************************Common MACRO for Feature control********************************************/

#if 0
#define _BITRA_TARGET_ADSP
#define _CEDROS_TARGET_ADSP
#define _KODIAK_TARGET_ADSP
#define _VTLB_ENABLED_ADSP
#define _MANNAR_TARGET_ADSP
#define _DEBUG_HEXAGON_ADSP_
#define _AGATTI_TARGET_ADSP
#endif

#define _VTLB_ENABLED_ADSP
#define _KODIAK_TARGET_ADSP
//#define _BITRA_TARGET_ADSP
//#define _HEXAGON_TARGET_TIME_PROFILING_ADSP
//#define _VTLB_ENABLED_CDSP
/* define this macro when we need to fetch VTLB using AXI */
//#define HEXAGON_VTLB_AXI_ADSP
/* define this macro when we need to fetch VTLB using MEM_PHYS */
#define HEXAGON_VTLB_MEM_PHYS_ADSP

/* define this macro when we need to fetch VTLB using MEMW interface */
//#define HEXAGON_VTLB_MEMW_ADSP 

#if defined(_BITRA_TARGET_ADSP)
  #define HEXAGON_VTLB_OLD_ARCH_ADSP
#endif

#if defined(_KODIAK_TARGET_ADSP)
  #define HEXAGON_VTLB_NEW_ARCH_ADSP
#endif


/***************************************************************************/


#define HEXAGON_COMMON_MAGIC_ADSP 0xD2D2D2D2   //TDB

/* HEXAGON_MSS_QDSP6SS_WDOG_CTL value is same for Kodiak , Cedros and BITRA */
#define  HEXAGON_MSS_QDSP6SS_WDOG_DISABLE_ADSP  0x0
#define  HEXAGON_MSS_QDSP6SS_WDOG_ENABLE_ADSP   0x7



#define HEXAGON_MAX_ISDB_REG_ADSP 17

/** ISDB register offsets w.r.t Hexagon debug_base (Sec:13.5) **/
#define HEXAGON_ISDB_ISDBST_ADSP            0x00
#define HEXAGON_ISDB_ISDBCFG0_ADSP          0x04
#define HEXAGON_ISDB_ISDBCFG1_ADSP          0x08
#define HEXAGON_ISDB_BRKPTINFO_ADSP         0x0C
#define HEXAGON_ISDB_BRKPTPC0_ADSP          0x10
#define HEXAGON_ISDB_BRKPTCFG0_ADSP         0x14
#define HEXAGON_ISDB_BRKPTPC1_ADSP          0x18
#define HEXAGON_ISDB_BRKPTCFG1_ADSP         0x1C
#define HEXAGON_ISDB_STFINST_ADSP           0x20
#define HEXAGON_ISDB_ISDBMBXIN_ADSP         0x24
#define HEXAGON_ISDB_ISDBMBXOUT_ADSP        0x28
#define HEXAGON_ISDB_ISDBCMD_ADSP           0x2C
#define HEXAGON_ISDB_ISDBEN_ADSP            0x30
#define HEXAGON_ISDB_ISDBVER_ADSP           0x34
#define HEXAGON_ISDB_COREVER_ADSP           0x38
#define HEXAGON_ISDB_ISDBGPR_ADSP           0x3C
#define HEXAGON_ISDB_ISDBCST_ADSP           0x40

#define HEXAGON_ALL_ISDB_REG_ADSP           0xAA

/** SYSCFG register field **/
#define SYSCFG_L2NRA_ADSP                   (0x1 << 22)
#define SYSCFG_L2NWA_ADSP                   (0x1 << 21)
#define SYSCFG_L2WB_ADSP                    (0x1 << 23)


/** ISDB status register fields **/
#define ISDBST_ISDB_READY_ADSP              (0x1 << 0)
#define ISDBST_ISDB_MAILBOX_OUT_ADSP        (0x1 << 1)
#define ISDBST_ISDB_MAILBOX_IN_ADSP         (0x1 << 2)
#define ISDBST_ISDB_CMD_STATUS_ADSP         (0x1 << 4)
#define ISDBST_STUFF_CMD_STATUS_ADSP        (0x1 << 5)
#define ISDBST_DEBUG_MODE_STATUS_ADSP       (0xFF << 8)
#define ISDBST_OFF_MODE_STATUS_ADSP         (0xF << 16)
#define ISDBST_WAITRUN_MODE_STATUS_ADSP     (0xF << 24)

/** ISDB configuration register0 fields **/
#define ISDBCFG0_ETMBRKPT_TNUM_MASK_ADSP    (0x3F << 0)
#define ISDBCFG0_EXTBRKPT_TNUM_MASK_ADSP    (0xF << 8)
#define ISDBCFG0_EXTRESUME_TNUM_MASK_ADSP   (0xF << 16)
#define ISDBCFG0_GLOBAL_INT_DISABLE_ADSP    (0x1 << 24)
#define ISDBCFG0_HW_BREAKPOINT0_ADSP        (0x1 << 25)
#define ISDBCFG0_HW_BREAKPOINT1_ADSP        (0x1 << 26)


/** ISDB configuration register1 fields **/
#define ISDBCFG1_BRK_EVENT_TNUM_MASK_ADSP   (0xF << 0)
#define ISDBCFG1_SWBRKPT_TNUM_MASK_ADSP     (0xF << 8)
#define ISDBCFG1_BREAK0_TNUM_MASK_ADSP      (0xF << 16)
#define ISDBCFG1_BREAK1_TNUM_MASK_ADSP      (0xF << 24)


/** Break point information register fields **/
#define BRKPTINFO_THREAD0_BRKPT_SOURCE_ADSP (0x7 << 0)
#define BRKPTINFO_THREAD1_BRKPT_SOURCE_ADSP (0x7 << 3)
#define BRKPTINFO_THREAD2_BRKPT_SOURCE_ADSP (0x7 << 6)
#define BRKPTINFO_THREAD3_BRKPT_SOURCE_ADSP (0x7 << 9)
#define BRKPTINFO_THREAD4_BRKPT_SOURCE_ADSP (0x7 << 12)
#define BRKPTINFO_THREAD5_BRKPT_SOURCE_ADSP (0x7 << 15)

/** Break point PC register fields **/
#define BRKPTPC_0_1_BRKPTPC_ADSP        (0x3FFFFFFF << 2)

/** ISDB Command register fields **/
#define ISDBCMD_CMD_BREAK_ADSP              (0x1 << 0)
#define ISDBCMD_CMD_RESUME_ADSP             (0x2 << 0)
#define ISDBCMD_CMD_ISTEP_ADSP              (0x3 << 0)
#define ISDBCMD_CMD_STUFF_ADSP              (0x4 << 0)
#define ISDBCMD_CMD_RST_ASSRT_ADSP          (0x5 << 0)
#define ISDBCMD_CMD_INTRPT_ADSP             (0x6 << 0)
#define ISDBCMD_CMD_RST_RELEASE_ADSP        (0x7 << 0)

#define ISDBCMD_USER_LVL_ADSP               (0x0 << 6)
#define ISDBCMD_GUEST_LVL_ADSP              (0x1 << 6)
#define ISDBCMD_MONITOR_LVL_ADSP            (0x2 << 6)
#define ISDBCMD_TNUM_MASK_4_ADSP            (0xF << 8)
#define ISDBCMD_TNUM_MASK_6_ADSP            (0x3F << 8)
#define ISDBCMD_TNUM_MASK_THREAD_ADSP(A)    (0x1 << (8+A))
 

/** ISDB Enable register fields **/
#define ISDBEN_APB_ISDB_EN_ADSP             (0x1 << 0)
#define ISDBEN_ISDB_CLK_OFF_ADSP            (0x1 << 1)
#define ISDBEN_SECURE_EN_ADSP               (0x1 << 2)
#define ISDBEN_ISDB_TRUSTED_ADSP            (0x1 << 3)
#define ISDBEN_ISDB_PREVNT_PWRDWN_ADSP      (0x1 << 4)
#define ISDBEN_SECURITY_DFD_EN_STATUS_ADSP  (0x1 << 5)
#define ISDBEN_SECURITY_ETM_EN_STATUS_ADSP  (0x1 << 6)


/** ISDB Version register fields **/
#define COREVER_ISA_ADSP            (0xFF << 0)
#define COREVER_ID_ADSP             (0xFF << 8)
#define COREVER_LAYER_ADSP          (0xF << 16)
#define COREVER_UID_ADSP            (0xF << 20)
#define COREVER_METAL_ADSP          (0xFF << 24)



/** ISDB Core Status register fields **/
#define ISDBCST_ALLWIAT_ADSP        (0x1 << 1)
#define ISDBCST_RESET_OR_PC_ADSP    (0x1 << 2)
#define ISDBCST_AXIM_BUS_ISO_ADSP   (0x1 << 3)
#define ISDBCST_AXIM2_BUS_ISO_ADSP  (0x1 << 4)

/** page table related macros **/
#define VIRT_PAGE_ADSP(hi)  (hi & 0xfffff)
#define PAGE_VALS_ADSP(lo)  (lo == 1 ? "4KB" : (lo == 2 ? "16KB" : (lo == 4 ? "64KB" : (lo == 8 ? "256KB" : (lo == 16 ? "1MB" : (lo == 32 ? "4MB" : "16MB"))))))
#define ASID_ADSP(hi)       ((hi >> 20) & 0x7f)
#define P_READ_ADSP(lo)     ((lo >> 29) & 0x01)
#define P_WRITE_ADSP(lo)    ((lo >> 30) & 0x01)
#define P_EXEC_ADSP(lo)     ((lo >> 31) & 0x01)
#define P_USER_ADSP(lo)     ((lo >> 28) & 0x01)
#define P_CCCC_ADSP(lo)     ((lo >> 24) & 0x0f)
#define P_S_ADSP(lo)        ((lo >> 0) & 0x01)
#define P_V_ADSP(hi)        ((hi >> 31) & 0x01)
#define P_G_ADSP(hi)        ((hi >> 30) & 0x01)
#define P_EP_ADSP(hi)       ((hi >> 29) & 0x01)
#define P_A1_ADSP(hi)       ((hi >> 28) & 0x01)
#define P_A0_ADSP(hi)       ((hi >> 27) & 0x01)

#define PAGE_SIZE_ADSP(lo, mask)  PAGE_VALS_ADSP((lo & mask))

#define HEXAGON_PAGE_SIZE_4K_ADSP         (0x00001000)
#define HEXAGON_PAGE_SIZE_16K_ADSP        (0x00004000)
#define HEXAGON_PAGE_SIZE_64K_ADSP        (0x00010000)
#define HEXAGON_PAGE_SIZE_256K_ADSP       (0x00040000)
#define HEXAGON_PAGE_SIZE_1M_ADSP         (0x00100000)
#define HEXAGON_PAGE_SIZE_4M_ADSP         (0x00400000)
#define HEXAGON_PAGE_SIZE_16M_ADSP        (0x01000000)


enum hexagon_hw_thread_ADSP {
    HEXAGON_HW_THREAD0_ADSP=0,
    HEXAGON_HW_THREAD1_ADSP,
    HEXAGON_HW_THREAD2_ADSP,
    HEXAGON_HW_THREAD3_ADSP,
    HEXAGON_HW_THREAD4_ADSP,
    HEXAGON_HW_THREAD5_ADSP,
    HEXAGON_HW_THREAD_ALL_ADSP
};

enum hexagon_registers_ADSP {
/** General Purpose Registers(32) **/ 
    HEXAGON_R0_ADSP = 0,
    HEXAGON_R1_ADSP,
    HEXAGON_R2_ADSP,
    HEXAGON_R3_ADSP,
    HEXAGON_R4_ADSP,
    HEXAGON_R5_ADSP,
    HEXAGON_R6_ADSP,
    HEXAGON_R7_ADSP,
    HEXAGON_R8_ADSP,
    HEXAGON_R9_ADSP,
    HEXAGON_R10_ADSP,
    HEXAGON_R11_ADSP,
    HEXAGON_R12_ADSP,
    HEXAGON_R13_ADSP,
    HEXAGON_R14_ADSP,
    HEXAGON_R15_ADSP,
    HEXAGON_R16_ADSP,
    HEXAGON_R17_ADSP,
    HEXAGON_R18_ADSP,
    HEXAGON_R19_ADSP,
    HEXAGON_R20_ADSP,
    HEXAGON_R21_ADSP,
    HEXAGON_R22_ADSP,
    HEXAGON_R23_ADSP,
    HEXAGON_R24_ADSP,
    HEXAGON_R25_ADSP,
    HEXAGON_R26_ADSP,
    HEXAGON_R27_ADSP,
    HEXAGON_R28_ADSP,
    HEXAGON_SP_ADSP,
    HEXAGON_FP_ADSP,
    HEXAGON_LR_ADSP      = 31,
    HEXAGON_GPR_MAX_ADSP = 32,

/** Control Registers(32) **/
    HEXAGON_SA0_ADSP = 32,      /* C0  */
    HEXAGON_LC0_ADSP,           /* C1  */
    HEXAGON_SA1_ADSP,           /* C2  */
    HEXAGON_LC1_ADSP,           /* C3  */
    HEXAGON_P30_ADSP,           /* C4  */
    HEXAGON_C5_RESRV_ADSP,      /* C5 - reserved */
    HEXAGON_M0_ADSP,            /* C6  */
    HEXAGON_M1_ADSP,            /* C7  */
    HEXAGON_USR_ADSP,           /* C8  */
    HEXAGON_PC_ADSP,            /* C9  */
    HEXAGON_UGP_ADSP,           /* C10 */
    HEXAGON_GP_ADSP,            /* C11 */
    HEXAGON_CS0_ADSP,           /* C12 */
    HEXAGON_CS1_ADSP,           /* C13 */
    HEXAGON_UPCYCLLO_ADSP,      /* C14 */
    HEXAGON_UPCYCLHI_ADSP,      /* C15 */
    HEXAGON_FLMT_ADSP,          /* C16 */
    HEXAGON_FKEY_ADSP,          /* C17 */
    HEXAGON_PKTCNTLO_ADSP,      /* C18 */
    HEXAGON_PKTCNTHI_ADSP,      /* C19 */
    HEXAGON_C20_RESRV_ADSP,     /* C20 - reserved */
    HEXAGON_C21_RESRV_ADSP,     /* C21 - reserved */
    HEXAGON_C22_RESRV_ADSP,     /* C22 - reserved */
    HEXAGON_C23_RESRV_ADSP,     /* C23 - reserved */
    HEXAGON_C24_RESRV_ADSP,     /* C24 - reserved */
    HEXAGON_C25_RESRV_ADSP,     /* C25 - reserved */
    HEXAGON_C26_RESRV_ADSP,     /* C26 - reserved */
    HEXAGON_C27_RESRV_ADSP,     /* C27 - reserved */
    HEXAGON_C28_RESRV_ADSP,     /* C28 - reserved */
    HEXAGON_C29_RESRV_ADSP,     /* C29 - reserved */        
    HEXAGON_UTMRLO_ADSP,        /* C30 */
    HEXAGON_UTMRHI_ADSP = 63,   /* C31 */
    HEXAGON_CTRL_MAX_ADSP = 64,

/** Monitor Mode per-thread Control Registers(16) **/   
    HEXAGON_SGP0_ADSP = 64,     /* S0  */
    HEXAGON_SGP1_ADSP,          /* S1  */
    HEXAGON_STID_ADSP,          /* S2  */
    HEXAGON_ELR_ADSP,           /* S3  */
    HEXAGON_BADVA0_ADSP,        /* S4  */
    HEXAGON_BADVA1_ADSP,        /* S5  */
    HEXAGON_SSR_ADSP,           /* S6  */
    HEXAGON_CCR_ADSP,           /* S7  */
    HEXAGON_HTID_ADSP,          /* S8  */
    HEXAGON_BADVA_ADSP,         /* S9  */
    HEXAGON_IMASK_ADSP,         /* S10 */
    HEXAGON_GEVB_ADSP,          /* S11 */
    HEXAGON_S12_RESRV_ADSP,     /* S12 - reserved */
    HEXAGON_S13_RESRV_ADSP,     /* S13 - reserved */
    HEXAGON_S14_RESRV_ADSP,     /* S14 - reserved */
    HEXAGON_S15_RESRV_ADSP = 79,/* S15 - reserved */    
    HEXAGON_MMODE_PERTHRD_MAX_ADSP = 80,

/** Monitor Mode Global Control Registers(16) **/
    HEXAGON_EVB_ADSP = 80,      /* S16 */
    HEXAGON_MODECTL_ADSP,       /* S17 */
    HEXAGON_SYSCFG_ADSP,        /* S18 */
    HEXAGON_S19_RESRV_ADSP,     /* S19 - reserved */
    HEXAGON_IPENDAD_ADSP,       /* S20 */
    HEXAGON_VID_ADSP,           /* S21 */
    HEXAGON_VID1_ADSP,          /* S22 */
    HEXAGON_BESTWAIT_ADSP,      /* S23 */
    HEXAGON_S24_RESRV_ADSP,     /* S24 - reserved  */
    HEXAGON_SCHDCFG_ADSP,       /* S25 */
    HEXAGON_S26_RESRV_ADSP,     /* S26 - reserved  */
    HEXAGON_CFGBASE_ADSP,       /* S27 */
    HEXAGON_DIAG_ADSP,          /* S28 */
    HEXAGON_REV_ADSP,           /* S29 */
    HEXAGON_PCYCLELO_ADSP,      /* S30 */
    HEXAGON_PCYCLEHI_ADSP = 95, /* S31 */
    HEXAGON_MMODE_GLOBAL_MAX_ADSP = 96,

/** ISDB registers(12) **/
    HEXAGON_ISDBST_ADSP = 96,   /* S32 */
    HEXAGON_ISDBCF0_ADSP,       /* S33 */
    HEXAGON_ISDBCFG1_ADSP,      /* S34 */
    HEXAGON_LIVELOCK_ADSP,      /* S35 */
    HEXAGON_BRKPTPC0_ADSP,      /* S36 */
    HEXAGON_BRKPTCFG0_ADSP,     /* S37 */
    HEXAGON_BRKPTPC1_ADSP,      /* S38 */
    HEXAGON_BRKPTCFG1_ADSP,     /* S39 */
    HEXAGON_ISDBMBXIN_ADSP,     /* S40 */
    HEXAGON_ISDBMBXOUT_ADSP,    /* S41 */
    HEXAGON_ISDBEN_ADSP,        /* S42 */
    HEXAGON_ISDBGPR_ADSP,       /* S43 */

/** Perf Monitor registers(15) **/
    HEXAGON_PMUCNT4_ADSP,       /* S44 */
    HEXAGON_PMUCNT5_ADSP,       /* S45 */
    HEXAGON_PMUCNT6_ADSP,       /* S46 */
    HEXAGON_PMUCNT7_ADSP,       /* S47 */
    HEXAGON_PMUCNT0_ADSP,       /* S48 */
    HEXAGON_PMUCNT1_ADSP,       /* S49 */
    HEXAGON_PMUCNT2_ADSP,       /* S50 */
    HEXAGON_PMUCNT3_ADSP,       /* S51 */
    HEXAGON_PMUEVTCFG_ADSP,     /* S52 */
    HEXAGON_PMUSTID0_ADSP,      /* S53 */
    HEXAGON_PMUEVTCFG1_ADSP,    /* S54 */
    HEXAGON_PMUSTID1_ADSP,      /* S55 */   
    HEXAGON_TIMERLO_ADSP,       /* S56 */
    HEXAGON_TIMERHI_ADSP,       /* S57 */
    HEXAGON_PMUCFG1_ADSP,       /* S58 */
    
    HEXAGON_S59_RESRV_ADSP,     /* S59 */
    HEXAGON_S60_RESRV_ADSP,     /* S60 */
    HEXAGON_S61_RESRV_ADSP,     /* S61 */
    HEXAGON_S62_RESRV_ADSP,     /* S62 */
    HEXAGON_S63_RESRV_ADSP,     /* S63 */

    HEXAGON_LAST_REG_ADSP = 128
};


/* Hexagon Registers info */
#define HEXAGON_GPR_REGS_ADSP   HEXAGON_GPR_MAX_ADSP
#define HEXAGON_PER_THREAD_CTRL_REGS_ADSP (HEXAGON_MMODE_PERTHRD_MAX_ADSP - HEXAGON_GPR_MAX_ADSP)
#define HEXAGON_PER_THREAD_REGS_ADSP HEXAGON_MMODE_PERTHRD_MAX_ADSP
#define HEXAGON_GLOBAL_REGS_ADSP (HEXAGON_MMODE_GLOBAL_MAX_ADSP - HEXAGON_MMODE_PERTHRD_MAX_ADSP)
#define HEXAGON_NUM_REGS_ADSP HEXAGON_MMODE_GLOBAL_MAX_ADSP

#define HEXAGON_PER_THREAD_RESV_REGS_ADSP 15
#define HEXAGON_GLOBAL_RESV_REGS_ADSP 3
#define HEXAGON_VALID_PER_THREAD_REGS_ADSP (HEXAGON_MMODE_PERTHRD_MAX_ADSP - HEXAGON_PER_THREAD_RESV_REGS_ADSP)
#define HEXAGON_VALID_GLOBAL_REGS_ADSP (HEXAGON_MMODE_GLOBAL_MAX_ADSP-HEXAGON_MMODE_PERTHRD_MAX_ADSP - HEXAGON_GLOBAL_RESV_REGS_ADSP)


#define hexagon_pack_isdbcmd_adsp(cmd, prilvl, thrdmsk) ((cmd) | (prilvl) | (thrdmsk))


typedef struct {
    unsigned id;
    const char *name;
    unsigned bits;
    enum reg_type type;
    const char *group;
    const char *feature;
    struct reg_data_type *data_type;
} hexagon_reg_adsp;


#define HEXAGON_MAX_HW_BPS_ADSP 2
#define HEXAGON_MAX_SW_BPS_ADSP 8



/******************/
/******************/

#define PAGE_SIZE_4KB_ADSP          0x1000
#define PAGE_SIZE_4KB_LEVEL0_BITS_ADSP  39
#define PAGE_SIZE_4KB_LEVEL1_BITS_ADSP  30
#define PAGE_SIZE_4KB_LEVEL2_BITS_ADSP  21
#define PAGE_SIZE_4KB_LEVEL3_BITS_ADSP  12

#define PAGE_SIZE_4KB_LEVEL0_MASK_ADSP  ((0x1FFULL) << PAGE_SIZE_4KB_LEVEL0_BITS_ADSP)
#define PAGE_SIZE_4KB_LEVEL1_MASK_ADSP  ((0x1FFULL) << PAGE_SIZE_4KB_LEVEL1_BITS_ADSP)
#define PAGE_SIZE_4KB_LEVEL2_MASK_ADSP  ((0x1FFULL) << PAGE_SIZE_4KB_LEVEL2_BITS_ADSP)
#define PAGE_SIZE_4KB_LEVEL3_MASK_ADSP  ((0x1FFULL) << PAGE_SIZE_4KB_LEVEL3_BITS_ADSP)

#define PAGE_SIZE_4KB_TRBBASE_MASK_ADSP 0xFFFFFFFFF000


enum hexagon_opcode_adsp {
    READ_REG_R0_ADSP,
    READ_REG_R1_ADSP,
    READ_REG_R2_ADSP,
    READ_REG_R3_ADSP,
    READ_REG_R4_ADSP,
    READ_REG_R5_ADSP,
    READ_REG_R6_ADSP,
    READ_REG_R7_ADSP,
    READ_REG_R8_ADSP,
    READ_REG_R9_ADSP,
    READ_REG_R10_ADSP,
    READ_REG_R11_ADSP,
    READ_REG_R12_ADSP,
    READ_REG_R13_ADSP,
    READ_REG_R14_ADSP,
    READ_REG_R15_ADSP,
    READ_REG_R16_ADSP,
    READ_REG_R17_ADSP,
    READ_REG_R18_ADSP,
    READ_REG_R19_ADSP,
    READ_REG_R20_ADSP,
    READ_REG_R21_ADSP,
    READ_REG_R22_ADSP,
    READ_REG_R23_ADSP,
    READ_REG_R24_ADSP,
    READ_REG_R25_ADSP,
    READ_REG_R26_ADSP,
    READ_REG_R27_ADSP,
    READ_REG_R28_ADSP,
    READ_REG_R29_ADSP,
    READ_REG_R30_ADSP,
    READ_REG_R31_ADSP,
    BRKPT_ADSP,
    HEXA_OPCODE_MAX_ADSP
};




static const uint32_t hexagon_opcodes_adsp[HEXA_OPCODE_MAX_ADSP] = {
        [READ_REG_R0_ADSP]  = 0x6700c029,
        [READ_REG_R1_ADSP]  = 0x6701c029,
        [READ_REG_R2_ADSP]  = 0x6702c029,
        [READ_REG_R3_ADSP]  = 0x6703c029,
        [READ_REG_R4_ADSP]  = 0x6704c029,
        [READ_REG_R5_ADSP]  = 0x6705c029,
        [READ_REG_R6_ADSP]  = 0x6706c029,
        [READ_REG_R7_ADSP]  = 0x6707c029,
        [READ_REG_R8_ADSP]  = 0x6708c029,
        [READ_REG_R9_ADSP]  = 0x6709c029,
        [READ_REG_R10_ADSP] = 0x670ac029,
        [READ_REG_R11_ADSP] = 0x670bc029,
        [READ_REG_R12_ADSP] = 0x670cc029,
        [READ_REG_R13_ADSP] = 0x670dc029,
        [READ_REG_R14_ADSP] = 0x670ec029,
        [READ_REG_R15_ADSP] = 0x670fc029,
        [READ_REG_R16_ADSP] = 0x6710c029,
        [READ_REG_R17_ADSP] = 0x6711c029,
        [READ_REG_R18_ADSP] = 0x6712c029,
        [READ_REG_R19_ADSP] = 0x6713c029,
        [READ_REG_R20_ADSP] = 0x6714c029,
        [READ_REG_R21_ADSP] = 0x6715c029,
        [READ_REG_R22_ADSP] = 0x6716c029,
        [READ_REG_R23_ADSP] = 0x6717c029,
        [READ_REG_R24_ADSP] = 0x6718c029,
        [READ_REG_R25_ADSP] = 0x6719c029,
        [READ_REG_R26_ADSP] = 0x671ac029,
        [READ_REG_R27_ADSP] = 0x671bc029,
        [READ_REG_R28_ADSP] = 0x671cc029,
        [READ_REG_R29_ADSP] = 0x671dc029,
        [READ_REG_R30_ADSP] = 0x671ec029,
        [READ_REG_R31_ADSP] = 0x671fc029,
        [BRKPT_ADSP]            = 0x6c20c000,
};

/** All H/w threads on some debub reason ? **/
#define HEXA_DEBUG_ENTRY_ADSP(x) (x & 0x7)

/* Cause of entry into debug mode */
#define HEXA_DBG_HWBRKPT0_ADSP      (0x0)
#define HEXA_DBG_HWBRKPT1_ADSP      (0x1)
#define HEXA_DBG_SWBRKPT_ADSP       (0x2)
#define HEXA_DBG_ETMBRKPT_ADSP      (0x3)
#define HEXA_DBG_APBBRKPT_ADSP      (0x4)
#define HEXA_DBG_EXTBRKPT_ADSP      (0x5)


struct hexagon_brp_adsp {
    int used;
    int type;
    target_addr_t value;
    uint32_t control;
    uint8_t BRPn;
};


enum hexagon_isrmasking_mode_adsp {
    HEXAGON_ISRMASK_OFF_ADSP,
    HEXAGON_ISRMASK_ON_ADSP,
};

union fourbyte_adsp {
  uint32_t word;
  uint16_t hword[2];
  uint8_t  byte[4];
};


struct hexa_reg_adsp {

    /** Invoke before a series of instruction operations */
    int (*prepare)( hexagon_reg_adsp *);

    /** Invoke after a series of instruction operations */
    int (*finish)( hexagon_reg_adsp *);

    /** Runs one instruction. */
    int (*instr_execute)( hexagon_reg_adsp *, uint32_t opcode);

    /** Runs one instruction, writing data to R0 before execution. */
    int (*instr_write_data_r0)( hexagon_reg_adsp *,
            uint32_t opcode, uint32_t data);


    /** Runs one instruction, reading data from r0 after execution. */
    int (*instr_read_data_r0)( hexagon_reg_adsp *,
            uint32_t opcode, uint32_t *data);


    struct reg *(*hexagon_reg_current_adsp)(struct hexa_info_adsp *hexa_info,
            unsigned int regnum, struct reg_cache *cache);
};


struct hexa_bp_adsp {
    unsigned number;
    uint32_t address;
    uint32_t control;
    /* true if hardware state needs flushing */
    bool dirty;
};


struct hexa_brkpt_adsp {
    /* BREAKPOINT SUPPORT */

    /**
     * Enables one breakpoint or watchpoint by writing to the
     * hardware registers.  The specified breakpoint/watchpoint
     * must currently be disabled.  Indices 0..15 are used for
     * breakpoints; indices 16..31 are for watchpoints.
     */
    int (*hwbp_enable)(struct hexa_brkpt_adsp *, unsigned index_value,
            uint32_t addr, uint32_t control);

    int (*swbp_enable)(struct hexa_brkpt_adsp *, unsigned index_value,
            uint32_t addr, uint32_t control);

    /**
     * Disables one breakpoint or watchpoint by clearing its
     * hardware control registers.  Indices are the same ones
     * accepted by bpwp_enable().
     */
    int (*hwbp_disable)(struct hexa_brkpt_adsp *, unsigned index_value);
    int (*swbp_disable)(struct hexa_brkpt_adsp *, unsigned index_value);

    /* The breakpoint and watchpoint arrays are private to the
     * DPM infrastructure.  There are nbp indices in the dbp
     * array.  There are nwp indices in the dwp array.
     */

    unsigned nhwbp;
    struct hexa_bp_adsp *dhwbp;
    unsigned nswbp;
    struct hexa_bp_adsp *dswbp;
};


struct hexagon_mmu_common_adsp {
    
    uint32_t mmu_enabled;
    uint32_t instrution_cache_enabled;
    uint32_t data_cache_enabled;
};

struct hexa_info_adsp {

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

    struct hexa_reg_adsp reg;

    /** Retrieve all Hw thread registers, for display. */
    int (*full_context)(struct target *target);

    /** Retrieve a single Hw thread  register. */
    int (*read_core_reg)(struct target *target, struct reg *r, int regnum, uint32_t hwthrd);
    int (*write_core_reg)(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
    const int *map;
    const uint32_t *opcodes;
    struct hexa_brkpt_adsp brkpt;
    struct hexagon_mmu_common_adsp hexagon_mmu;

    /* last run-control command issued to this target (resume, halt, step) */
    enum run_control_op last_run_control_op;
};


struct hexagon_common_adsp {

    struct hexa_info_adsp hexa_info;
    int common_magic;
    /* Context information */
    uint32_t system_control_reg;
    uint32_t system_control_reg_curr;
    /* Breakpoint register pairs */
    int brp_num_context;
    int brp_num;
    int brp_num_available;
    struct hexagon_brp_adsp *brp_list;
    enum hexagon_isrmasking_mode_adsp isrmasking_mode;
};

struct hex_reg_adsp {
    int num;
    uint32_t hwthrd;
    struct target *target;
    struct hexa_info_adsp *hexa_info;
    uint8_t value[16];
};

struct hexagon_private_config_adsp {
    struct adiv5_private_config adiv5_config;
    struct arm_cti *cti;
};


static inline struct hexagon_common_adsp *
target_to_hexagon_adsp(struct target *target)
{
    return container_of(target->arch_info, struct hexagon_common_adsp, hexa_info);
}

/* this enum for page  size */
enum hexagon_page_size_ADSP
{
    HEXAGON_TLB_PAGE_SIZE_4KB_ADSP,
    HEXAGON_TLB_PAGE_SIZE_16KB_ADSP,
    HEXAGON_TLB_PAGE_SIZE_64KB_ADSP,
    HEXAGON_TLB_PAGE_SIZE_256KB_ADSP,
    HEXAGON_TLB_PAGE_SIZE_1MB_ADSP,
    HEXAGON_TLB_PAGE_SIZE_4MB_ADSP,
    HEXAGON_TLB_PAGE_SIZE_16MB_ADSP,
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
    uint32_t phy_page  : 24;
    enum hexagon_page_size_ADSP page_size;
    uint8_t asid : 7;
    uint8_t CCCC : 4;
    uint8_t validbit  : 1;
    uint8_t globalbit : 1;
    uint8_t EP : 1;
    uint8_t A0 : 1;
    uint8_t A1 : 1;
    uint8_t S  : 1;
    uint8_t R  : 1;
    uint8_t W  : 1;
    uint8_t X  : 1;
    uint8_t U  : 1;
} tlb_entries_adsp;

#ifdef HEXAGON_VTLB_NEW_ARCH_ADSP
typedef struct    
{
     unsigned vtlb_version:4;                  // version info
     unsigned vtlb_table_type:3;               // Descriptor type
     unsigned next_table_addr_is_virtual:1;    // next element is virtual or physical
     unsigned long long next_table_addr:36;    // table address where the descriptor type elements start from
     unsigned table_entries:20;                // Number of entries of the descriptor type
} qurtk_vtlb_table_descriptor_adsp;
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
    #ifdef HEXAGON_VTLB_NEW_ARCH_ADSP
    qurtk_vtlb_table_descriptor_adsp qurtk_vtlb_main;
    qurtk_vtlb_table_descriptor_adsp qurtk_vtlb_main_next;
    #endif
   
}vtlb_data_adsp;

/* data structure for Virtual Page entry parsing */
union pg_tlbhi_t_adsp{
    struct{
        unsigned int vir_addr   :20;
        unsigned int asid    :7;
        unsigned int a0      :1;
        unsigned int a1      :1;
        unsigned int ep      :1;
        unsigned int global  :1;
        unsigned int valid   :1;
    } info;
    unsigned int raw;
};

/* data structure for Physical Page entry parsing */
union pg_tlblo_t_adsp{
    struct{
        unsigned int phys_addr  :24;
        unsigned int cache      :4;
        unsigned int usr        :1;
        unsigned int perm       :3;
    } info;
    unsigned int raw;
};

#endif  /* OPENOCD_TARGET_HEXAGON_H_ADSP */
