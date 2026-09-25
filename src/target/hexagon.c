/**************************************************************************
*   Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.     *
*   All rights reserved.                                                   *
*   Confidential and Proprietary - Qualcomm Technologies, Inc.             *
*                                                                          *
***************************************************************************/
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "breakpoints.h"
#include "aarch64.h"
#include "register.h"
#include "target_request.h"
#include "target_type.h"
#include "smp.h"
#include "hexagon.h"
#include "rtos/rtos.h"   /* struct rtos_reg, for the QuRT OS-awareness HW-thread reg hook */
#include "rtos/qurt.h"   /* QuRT walk-enable/stack-walk hooks + hexagon_rtos_* prototypes */
#include <time.h>

extern void decToBinary(unsigned int n, unsigned int binaryNum[]);

static int hexagon_update_modified_vtlb_entry(struct target *target);

// Globals for Profiling 
clock_t start;
clock_t end;
double execution_time=0;

uint64_t loop_count = HEXAGON_DEFAULT_WAIT_LOOP;

#define ClkEnRegs 8

/****************************Global /static variable declartions**************************/

struct hexagon_private_config 
{
    struct adiv5_private_config adiv5_config; 
    struct arm_cti *cti;
    bool   is_hvx_supported;
    bool   is_hmx_supported;
};


static const hexagon_reg hexagon_per_hwt_regs[] = {
/** General Purpose Registers **/ 
    { HEXAGON_R0,          "R0",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R1,          "R1",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R2,          "R2",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R3,          "R3",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R4,          "R4",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R5,          "R5",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R6,          "R6",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R7,          "R7",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R8,          "R8",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R9,          "R9",          32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R10,         "R10",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R11,         "R11",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R12,         "R12",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R13,         "R13",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R14,         "R14",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R15,         "R15",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R16,         "R16",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R17,         "R17",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R18,         "R18",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R19,         "R19",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R20,         "R20",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R21,         "R21",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R22,         "R22",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R23,         "R23",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R24,         "R24",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R25,         "R25",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R26,         "R26",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R27,         "R27",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_R28,         "R28",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_SP,          "R29",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_FP,          "R30",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_LR,          "R31",         32, REG_TYPE_UINT32, "general", "org.gnu.gdb.hexagon.core", NULL},
/** Control Registers **/
    { HEXAGON_SA0,         "SA0",         32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_LC0,         "LC0",         32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_SA1,         "SA1",         32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_LC1,         "LC1",         32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_P30,         "P3:0",        32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
/** C5: reserved **/
    { HEXAGON_C5_RESRV,    "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_M0,          "M0",          32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_M1,          "M1",          32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_USR,         "USR",         32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_PC,          "PC",          32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_UGP,         "UGP",         32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_GP,          "GP",          32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_CS0,         "CS0",         32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_CS1,         "CS1",         32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_UPCYCLLO,    "UPCYCLELO",   32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_UPCYCLHI,    "UPCYCLEHI",   32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_FLMT,        "FLMT",        32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_FKEY,        "FKEY",        32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_PKTCNTLO,    "PKTCNTLO",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_PKTCNTHI,    "PKTCNTHI",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
/** C20-29: reserved **/
    { HEXAGON_C20_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C21_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C22_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C23_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C24_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C25_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C26_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C27_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C28_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_C29_RESRV,   "C5_RESRV",    32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_UTMRLO,      "UTMRLO",      32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_UTMRHI,      "UTMRHI",      32, REG_TYPE_UINT32, "control", "org.gnu.gdb.hexagon.core", NULL},
/** Monitor Mode per-thread Control Registers **/    
    { HEXAGON_SGP0,        "SGP0",        32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_SGP1,        "SGP1",        32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_STID,        "STID",        32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_ELR,         "ELR",         32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_BADVA0,      "BADVA0",      32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_BADVA1,      "BADVA1",      32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_SSR,         "SSR",         32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_CCR,         "CCR",         32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_HTID,        "HTID",        32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_BADVA,       "BADVA",       32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_IMASK,       "IMASK",       32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_GEVB,        "GEVB",        32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
/** S12 - S15: reserved **/
    { HEXAGON_S12_RESRV,   "S12_RESRV",   32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_S13_RESRV,   "S13_RESRV",   32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_S14_RESRV,   "S14_RESRV",   32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_S15_RESRV,   "S15_RESRV",   32, REG_TYPE_UINT32, "monitor", "org.gnu.gdb.hexagon.core", NULL},
};

uint32_t global_reg[HEXAGON_MMODE_GLOBAL_MAX-HEXAGON_MMODE_PERTHRD_MAX]={0};


static const hexagon_reg hexagon_global_regs[] = {
/** Monitor Mode Global Control Registers **/
    { HEXAGON_EVB,       "EVB",       32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_MODECTL,   "MODECTL",   32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_SYSCFG,    "SYSCFG",    32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
/** 19: reserved **/
    { HEXAGON_S19_RESRV, "S19_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_IPENDAD,   "IPENDAD",   32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_VID,       "VID",       32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_VID1,      "VID1",      32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_BESTWAIT,  "BESTWAIT",  32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
/** 24: reserved **/
    { HEXAGON_S24_RESRV, "S24_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_SCHDCFG,   "SCHDCFG",   32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
/** 26: reserved **/    
    { HEXAGON_S26_RESRV, "S26_RESRV", 32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_CFGBASE,   "CFGBASE",   32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_DIAG,      "DIAG",      32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_REV,       "REV",       32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_PCYCLELO,  "PCYCLELO",  32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
    { HEXAGON_PCYCLEHI,  "PCYCLEHI",  32, REG_TYPE_UINT32, "global", "org.gnu.gdb.hexagon.core", NULL},
};

/********************************************/
/** Stuff instruction for register reading **/
/********************************************/


/* R0-R31  registers */
static uint32_t stuff_inst_gpr_read[] = {
        0x6700c029,    /* isdbmbxout = r0  */
        0x6701c029,    /* isdbmbxout = r1  */
        0x6702c029,    /* isdbmbxout = r2  */
        0x6703c029,    /* isdbmbxout = r3  */
        0x6704c029,    /* isdbmbxout = r4  */
        0x6705c029,    /* isdbmbxout = r5  */
        0x6706c029,    /* isdbmbxout = r6  */
        0x6707c029,    /* isdbmbxout = r7  */
        0x6708c029,    /* isdbmbxout = r8  */
        0x6709c029,    /* isdbmbxout = r9  */
        0x670ac029,    /* isdbmbxout = r10 */
        0x670bc029,    /* isdbmbxout = r11 */
        0x670cc029,    /* isdbmbxout = r12 */
        0x670dc029,    /* isdbmbxout = r13 */
        0x670ec029,    /* isdbmbxout = r14 */
        0x670fc029,    /* isdbmbxout = r15 */
        0x6710c029,    /* isdbmbxout = r16 */
        0x6711c029,    /* isdbmbxout = r17 */
        0x6712c029,    /* isdbmbxout = r18 */
        0x6713c029,    /* isdbmbxout = r19 */
        0x6714c029,    /* isdbmbxout = r20 */
        0x6715c029,    /* isdbmbxout = r21 */
        0x6716c029,    /* isdbmbxout = r22 */
        0x6717c029,    /* isdbmbxout = r23 */
        0x6718c029,    /* isdbmbxout = r24 */
        0x6719c029,    /* isdbmbxout = r25 */
        0x671ac029,    /* isdbmbxout = r26 */
        0x671bc029,    /* isdbmbxout = r27 */
        0x671cc029,    /* isdbmbxout = r28 */
        0x671dc029,    /* isdbmbxout = r29 */
        0x671ec029,    /* isdbmbxout = r30 */
        0x671fc029  /* isdbmbxout = r31 */
};

/* Control registers */
static uint32_t stuff_inst_ctrl_reg_read[][2] =  {
        {0x6a00c007,0x6707c029},    /* r7 = sa0, isdbmbxout = r7       */
        {0x6a01c007,0x6707c029},    /* r7 = lc0, isdbmbxout = r7       */
        {0x6a02c007,0x6707c029},    /* r7 = sa1, isdbmbxout = r7       */
        {0x6a03c007,0x6707c029},    /* r7 = lc1, isdbmbxout = r7       */
        {0x6a04c007,0x6707c029},    /* r7 = p3:0 isdbmbxout = r7       */
        {0x0, 0x0},                 /* Invalid: C5 reserved            */
        {0x6a06c007,0x6707c029},    /* r7 = m0,  isdbmbxout = r7       */
        {0x6a07c007,0x6707c029},    /* r7 = m1,  isdbmbxout = r7       */
        {0x6a08c007,0x6707c029},    /* r7 = usr, isdbmbxout = r7       */
        {0x6a09c007,0x6707c029},    /* r7 = pc,  isdbmbxout = r7       */ 
        {0x6a0ac007,0x6707c029},    /* r7 = ugp, isdbmbxout = r7       */
        {0x6a0bc007,0x6707c029},    /* r7 = gp,  isdbmbxout = r7       */
        {0x6a0cc007,0x6707c029},    /* r7 = cs0, isdbmbxout = r7       */
        {0x6a0dc007,0x6707c029},    /* r7 = cs1, isdbmbxout = r7       */
        {0x6a0ec007,0x6707c029},    /* r7 = upcyclelo, isdbmbxout = r7 */
        {0x6a0fc007,0x6707c029},    /* r7 = upcyclehi, isdbmbxout = r7 */
        {0x6a10c007,0x6707c029},    /* r7 = framelimit,isdbmbxout = r7 */
        {0x6a11c007,0x6707c029},    /* r7 = framekey,  isdbmbxout = r7 */
        {0x6a12c007,0x6707c029},    /* r7 = pktcountlo,isdbmbxout = r7 */    
        {0x6a13c007,0x6707c029},    /* r7 = pktcounthi,isdbmbxout = r7 */
        {0x0, 0x0},                 /* Invalid: C20 reserved           */
        {0x0, 0x0},                 /* Invalid: C21 reserved           */
        {0x0, 0x0},                 /* Invalid: C22 reserved           */
        {0x0, 0x0},                 /* Invalid: C23 reserved           */
        {0x0, 0x0},                 /* Invalid: C24 reserved           */
        {0x0, 0x0},                 /* Invalid: C25 reserved           */
        {0x0, 0x0},                 /* Invalid: C26 reserved           */
        {0x0, 0x0},                 /* Invalid: C27 reserved           */
        {0x0, 0x0},                 /* Invalid: C28 reserved           */
        {0x0, 0x0},                 /* Invalid: C29 reserved           */
        {0x6a1ec007,0x6707c029},    /* r7 = utimerlo,  isdbmbxout = r7 */
        {0x6a1fc007,0x6707c029}     /* r7 = utimerhi,  isdbmbxout = r7 */
};

/* Per thread control registers */
static uint32_t stuff_inst_mmode_reg_read[][2] = { 
        {0x6e80c007,0x6707c029},    /* r7 = sgp0, isdbmbxout = r7  */
        {0x6e81c007,0x6707c029},    /* r7 = sgp1, isdbmbxout = r7  */
        {0x6e82c007,0x6707c029},    /* r7 = stid, isdbmbxout = r7  */
        {0x6e83c007,0x6707c029},    /* r7 = elr,  isdbmbxout = r7  */
        {0x6e84c007,0x6707c029},    /* r7 = badva0,isdbmbxout = r7 */
        {0x6e85c007,0x6707c029},    /* r7 = badva1,isdbmbxout = r7 */
        {0x6e86c007,0x6707c029},    /* r7 = ssr,  isdbmbxout = r7  */
        {0x6e87c007,0x6707c029},    /* r7 = ccr,  isdbmbxout = r7  */
        {0x6e88c007,0x6707c029},    /* r7 = htid, isdbmbxout = r7  */
        {0x6e89c007,0x6707c029},    /* r7 = badva,isdbmbxout = r7  */
        {0x6e8ac007,0x6707c029},    /* r7 = imask,isdbmbxout = r7  */
        {0x6e8bc007,0x6707c029},    /* r7 = gevb, isdbmbxout = r7  */
        {0x0, 0x0},                 /* Invalid: S12 reserved       */
        {0x0, 0x0},                 /* Invalid: S13 reserved       */
        {0x0, 0x0},                 /* Invalid: S14 reserved       */
        {0x0, 0x0},                 /* Invalid: S15 reserved       */
};

static  uint32_t stuff_inst_mmode_imask_reg_read[][3] = {
     {0x7800c027,0x6607c007,0x6707c029}, /* r7 = #1, r7 = getimask(r7), isdbmbxout = r7 */
     {0x7800c047,0x6607c007,0x6707c029}, /* r7 = #2, r7 = getimask(r7), isdbmbxout = r7 */
     {0x7800c087,0x6607c007,0x6707c029}, /* r7 = #4, r7 = getimask(r7), isdbmbxout = r7 */
     {0x7800c107,0x6607c007,0x6707c029}, /* r7 = #8, r7 = getimask(r7), isdbmbxout = r7 */
     {0x7800c207,0x6607c007,0x6707c029}, /* r7 = #16,r7 = getimask(r7), isdbmbxout = r7 */
     {0x7800c407,0x6607c007,0x6707c029}  /* r7 = #32,r7 = getimask(r7), isdbmbxout = r7 */

}; 

/* Global control registers */
static uint32_t stuff_inst_global_reg_read[][2] = {
        {0x6e90c007,0x6707c029}, /* r7 = evb, isdbmbxout = r7      */
        {0x6e91c007,0x6707c029}, /* r7 = modectl, isdbmbxout = r7  */
        {0x6e92c007,0x6707c029}, /* r7 = syscfg, isdbmbxout = r7   */
        {0x0, 0x0},              /* Invalid: S19 reserved          */
        {0x6e94c007,0x6707c029}, /* r7 = ipendad, isdbmbxout = r7  */
        {0x6e95c007,0x6707c029}, /* r7 = vid, isdbmbxout = r7      */
        {0x6e96c007,0x6707c029}, /* r7 = vid1, isdbmbxout = r7     */
        {0x6e97c007,0x6707c029}, /* r7 = bestwait, isdbmbxout = r7 */
        {0x0, 0x0},              /* Invalid: S24 reserved          */
        {0x6e99c007,0x6707c029}, /* r7 = schedcfg, isdbmbxout = r7 */
        {0x0, 0x0},              /* Invalid: S26 reserved          */
        {0x6e9bc007,0x6707c029}, /* r7 = cfgbase, isdbmbxout = r7  */
        {0x6e9cc007,0x6707c029}, /* r7 = diag, isdbmbxout = r7     */
        {0x6e9dc007,0x6707c029}, /* r7 = rev, isdbmbxout = r7      */
        {0x6e9ec007,0x6707c029}, /* r7 = pcyclelo, isdbmbxout = r7 */
        {0x6e9fc007,0x6707c029}  /* r7 = pcyclehi, isdbmbxout = r7 */
};
    

#if 0
static uint32_t stuff_inst_sfr[][2] = 
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
#endif

/********************************************/
/** Stuff instruction for register writing **/
/********************************************/

/* R0-R31  registers */
static uint32_t stuff_inst_gpr_write[] = {
        0x6ea8c000,    /* r0  = isdbmbxin */
        0x6ea8c001,    /* r1  = isdbmbxin */
        0x6ea8c002,    /* r2  = isdbmbxin */
        0x6ea8c003,    /* r3  = isdbmbxin */
        0x6ea8c004,    /* r4  = isdbmbxin */
        0x6ea8c005,    /* r5  = isdbmbxin */
        0x6ea8c006,    /* r6  = isdbmbxin */
        0x6ea8c007,    /* r7  = isdbmbxin */
        0x6ea8c008,    /* r8  = isdbmbxin */
        0x6ea8c009,    /* r9  = isdbmbxin */
        0x6ea8c00A,    /* r10 = isdbmbxin */
        0x6ea8c00B,    /* r11 = isdbmbxin */
        0x6ea8c00C,    /* r12 = isdbmbxin */
        0x6ea8c00D,    /* r13 = isdbmbxin */
        0x6ea8c00E,    /* r14 = isdbmbxin */
        0x6ea8c00F,    /* r15 = isdbmbxin */
        0x6ea8c010,    /* r16 = isdbmbxin */
        0x6ea8c011,    /* r17 = isdbmbxin */
        0x6ea8c012,    /* r18 = isdbmbxin */
        0x6ea8c013,    /* r19 = isdbmbxin */
        0x6ea8c014,    /* r20 = isdbmbxin */
        0x6ea8c015,    /* r21 = isdbmbxin */
        0x6ea8c016,    /* r22 = isdbmbxin */
        0x6ea8c017,    /* r23 = isdbmbxin */
        0x6ea8c018,    /* r24 = isdbmbxin */
        0x6ea8c019,    /* r25 = isdbmbxin */
        0x6ea8c01A,    /* r26 = isdbmbxin */
        0x6ea8c01B,    /* r27 = isdbmbxin */
        0x6ea8c01C,    /* r28 = isdbmbxin */
        0x6ea8c01D,    /* r29 = isdbmbxin */
        0x6ea8c01E,    /* r30 = isdbmbxin */
        0x6ea8c01F,    /* r31 = isdbmbxin */
};


/* Control registers */
static uint32_t stuff_inst_ctrl_reg_write[][2] =  {
    {0x6ea8c007, 0x6227c000},    /* r7 = isdbmbxin, sa0 = r7        */
    {0x6ea8c007, 0x6227c001},    /* r7 = isdbmbxin, lc0 = r7        */
    {0x6ea8c007, 0x6227c002},    /* r7 = isdbmbxin, sa1 = r7        */
    {0x6ea8c007, 0x6227c003},    /* r7 = isdbmbxin, lc1 = r7        */
    {0x6ea8c007, 0x6227c004},    /* r7 = isdbmbxin, p3:0 = r7       */
    {0x0, 0x0},                  /* Invalid: C5 reserved            */
    {0x6ea8c007, 0x6227c006},    /* r7 = isdbmbxin, m0 = r7         */
    {0x6ea8c007, 0x6227c007},    /* r7 = isdbmbxin, m1 = r7         */
    {0x6ea8c007, 0x6227c008},    /* r7 = isdbmbxin, usr = r7        */
    {0x6ea8c007, 0x5287c000},    /* r7 = isdbmbxin, jump r7 (PC=r7) */ 
    {0x6ea8c007, 0x6227c00a},    /* r7 = isdbmbxin, ugp = r7        */
    {0x6ea8c007, 0x6227c00b},    /* r7 = isdbmbxin, gp = r7         */
    {0x6ea8c007, 0x6227c00c},    /* r7 = isdbmbxin, cs0 = r7        */
    {0x6ea8c007, 0x6227c00d},    /* r7 = isdbmbxin, cs1 = r7        */
    {0x6ea8c007, 0x6227c00e},    /* r7 = isdbmbxin, upcyclelo = r7  */
    {0x6ea8c007, 0x6227c00f},    /* r7 = isdbmbxin, upcyclehi = r7  */
    {0x6ea8c007, 0x6227c010},    /* r7 = isdbmbxin, framelimit= r7  */
    {0x6ea8c007, 0x6227c011},    /* r7 = isdbmbxin, framekey = r7   */
    {0x6ea8c007, 0x6227c012},    /* r7 = isdbmbxin, pktcountlo = r7 */
    {0x6ea8c007, 0x6227c013},    /* r7 = isdbmbxin, pktcounthi = r7 */
    {0x0, 0x0},                  /* Invalid: C20 reserved           */
    {0x0, 0x0},                  /* Invalid: C21 reserved           */
    {0x0, 0x0},                  /* Invalid: C22 reserved           */
    {0x0, 0x0},                  /* Invalid: C23 reserved           */
    {0x0, 0x0},                  /* Invalid: C24 reserved           */
    {0x0, 0x0},                  /* Invalid: C25 reserved           */
    {0x0, 0x0},                  /* Invalid: C26 reserved           */
    {0x0, 0x0},                  /* Invalid: C27 reserved           */
    {0x0, 0x0},                  /* Invalid: C28 reserved           */
    {0x0, 0x0},                  /* Invalid: C29 reserved           */
    {0x6ea8c007, 0x6227c01e},    /* r7 = isdbmbxin, utimerlo = r7   */
    {0x6ea8c007, 0x6227c01f},    /* r7 = isdbmbxin, utimerhi = r7   */
};


static uint32_t examine_writes_dbg_base[][2] = {
    {HEXAGON_APB_SPACE_UNLOCK, 0xc5acce55},
    {HEXAGON_ISDB_ISDBEN, 0x0000005d},
    {HEXAGON_ISDB_ISDBCFG0, 0x00ffffff},
    {HEXAGON_ISDB_ISDBCFG1, 0xffffffff},
    {HEXAGON_ISDB_ISDBEN, 0x0000004d},
};


static uint32_t examine_writes_etm_base[][2] = {
    {HEXAGON_ETM_CTRL0,             0x00000018},
    {HEXAGON_ETM_TRIG0_SAC0_ADDR,   0x00000000},
    {HEXAGON_ETM_TRIG0_CTRL2,       0x00000000},
    {HEXAGON_ETM_PROF_SRC_CTRL3,    0x00000000},

    {HEXAGON_ETM_ASYNC_PERIOD,      0x00000800},
    {HEXAGON_ETM_ISYNC_PERIOD,      0x00000800},
    {HEXAGON_ETM_GSYNC_PERIOD,      0x000fffff},
    {HEXAGON_ETM_TEST_BUS_CTRL0,    0x00800000},
    {HEXAGON_ETM_TEST_BUS_CTRL1,    0x00000000},
    {HEXAGON_ETM_CTRL1,             0xf0f00008},
    {HEXAGON_ETM_ATID,              0x00000201},
    {HEXAGON_ETM_ATID_TILE1,        0x00000403}
};

# if 0
/* Per thread control registers */
static uint32_t stuff_inst_mmode_reg_write[][2] = { 
    {0x6ea8c007, 0x6707c000},    /* r7 = isdbmbxin, sgp0 = r7      */
    {0x6ea8c007, 0x6707c001},    /* r7 = isdbmbxin, sgp1 = r7      */
    {0x6ea8c007, 0x6707c002},    /* r7 = isdbmbxin, stid = r7      */
    {0x6ea8c007, 0x6707c003},    /* r7 = isdbmbxin, elr = r7       */
    {0x6ea8c007, 0x6707c004},    /* r7 = isdbmbxin, badva0 = r7    */
    {0x6ea8c007, 0x6707c005},    /* r7 = isdbmbxin, badva1 = r7    */
    {0x6ea8c007, 0x6707c006},    /* r7 = isdbmbxin, ssr = r7       */
    {0x6ea8c007, 0x6707c007},    /* r7 = isdbmbxin, ccr = r7       */
    {0x0, 0x0},                  /* Invalid: S12 reserved          */
    {0x0, 0x0},                  /* Invalid: S13 reserved          */
    {0x0, 0x0},                  /* Invalid: S14 reserved          */
    {0x0, 0x0},                  /* Invalid: S15 reserved          */
};
#endif 

/* Per thread control registers */
static uint32_t stuff_inst_global_reg_write[][2] = { 
    {0x6ea8c007, 0x6707c010},    /* r7 = isdbmbxin, evb = r7       */
    {0x0, 0x0},                  /* modectl: read only             */
    {0x6ea8c007, 0x6707c012},    /* r7 = isdbmbxin, syscfg = r7    */
    {0x0, 0x0},                  /* Invalid: S19 reserved          */
    {0x0, 0x0},                  /* ipendad: read only             */
    {0x6ea8c007, 0x6707c015},    /* r7 = isdbmbxin, vid = r7       */
    {0x6ea8c007, 0x6707c016},    /* r7 = isdbmbxin, vid1 = r7      */
    {0x6ea8c007, 0x6707c017},    /* r7 = isdbmbxin, bestwait = r7  */
    {0x0, 0x0},                  /* Invalid: S24 reserved          */
    {0x0, 0x0},                  /* schdcfg: read only             */
    {0x0, 0x0},                  /* Invalid: S26 reserved          */
    {0x0, 0x0},                  /* cfgbase: read only             */
    {0x6ea8c007, 0x6707c01c},    /* r7 = isdbmbxin, diag = r7      */
    {0x0, 0x0},                  /* Rev: read only                 */
    {0x6ea8c007, 0x6707c01e},    /* r7 = isdbmbxin, pcyclelo = r7  */
    {0x6ea8c007, 0x6707c01f},    /* r7 = isdbmbxin, pcyclehi = r7  */
};

/* XML formatting string constant declarations */
static const char *XML_ASID = "<item>\n<column name=\"SPACE ASID\">";
static const char *XML_VPAGE = "</column><column name=\"VPAGE\">";
static const char *XML_PPAGE = "</column><column name=\"PPAGE\">";
static const char *XML_SIZE = "</column><column name=\"SIZE\">";
static const char *XML_R = "</column><column name=\"R\">";
static const char *XML_W = "</column><column name=\"W\">";
static const char *XML_X = "</column><column name=\"X\">";
static const char *XML_CACHE = "</column><column name=\"\tCache Attr\">";
static const char *XML_END = "</column></item>\n";

/* XML formatting string constant declarations */
static const char *XML_INDEX = "<item>\n<column name=\"INDEX\">";
static const char *XML_ASID_MID = "</column><column name=\"ASID\">";
static const char *XML_U = "</column><column name=\"U\">";
static const char *XML_S = "</column><column name=\"S\">";
static const char *XML_V = "</column><column name=\"V\">";
static const char *XML_G = "</column><column name=\"G\">";
static const char *XML_EP = "</column><column name=\"EP\">";
static const char *XML_PPN_MSB = "</column><column name=\"PPNmsb\">";


static int hexagon_get_core_reg(struct reg *reg);
static int hexagon_set_core_reg(struct reg *reg, uint8_t *buf);

static const struct reg_arch_type hexagon_reg_type = {
    .get = hexagon_get_core_reg,
    .set = hexagon_set_core_reg,
};
uint32_t hexagon_r0_used_stuff = 0, hexagon_r1_used_stuff = 0, 
    hexagon_r2_used_stuff = 0, hexagon_r7_used_stuff = 0;
uint32_t hexagon_r30_used_stuff = 0,  hexagon_r31_used_stuff = 0;

#ifdef  _HEXAGON_TARGET_TIME_PROFILING
int64_t hexagon_time_start = 0,hexagon_time_total = 0;
#endif

vtlb_data hexagon_vtlb_data = {0};
tlb_entries * hexagon_vtlb_entries = NULL;
struct adiv5_ap * debug_axi_ap = NULL;
static uint32_t hexagon_syscfg_reg; 

//Global data to store/keep track of the initial PC value once threads are halted through software breakpoint, value are cleared once resume happens.
static uint8_t sbp_step_executed = 0;    //Just a bool variable

static int initConfig(struct hexagon_common *hexagon)
{
    struct hexagon_arch_info *hexa_info;
    uint32_t i;

    LOG_INFO("InitConfig is called here");
    hexa_info = &(hexagon->hexa_info);
    hexagon_config *pHexCfg = &(hexagon->hexa_info.config);


    pHexCfg->pThreadNameArray = malloc((pHexCfg->maxHwThreads + 1) * sizeof(*(pHexCfg->pThreadNameArray)));
    hexa_info->pPerHwThrdReg = (uint32_t(*)[HEXAGON_PER_THREAD_REGS])malloc(pHexCfg->maxHwThreads * sizeof(*(hexa_info->pPerHwThrdReg)));
    // since we need array of pointers, we need size of pointer not integer
    hexa_info->pSbpHaltedThreadsPC = (uint32_t **)malloc(pHexCfg->maxHwThreads * sizeof(uint32_t *));
    pHexCfg->pTlbEntries = (tlb_entries *)malloc(pHexCfg->numTlbEntries * sizeof(tlb_entries));

    if (pHexCfg->pThreadNameArray == NULL || hexa_info->pPerHwThrdReg == NULL || hexa_info->pSbpHaltedThreadsPC == NULL || pHexCfg->pTlbEntries == NULL)
    {
        if (pHexCfg->pThreadNameArray != NULL)
            free(pHexCfg->pThreadNameArray);
            
        if (hexa_info->pPerHwThrdReg != NULL)
            free(hexa_info->pPerHwThrdReg);

        if (hexa_info->pSbpHaltedThreadsPC != NULL)
            free(hexa_info->pSbpHaltedThreadsPC);
        if (pHexCfg->pTlbEntries!= NULL)
            free(pHexCfg->pTlbEntries);
        return ERROR_FAIL;
    }

    /* Robust multi-digit thread names: "HW-Thrd-<index>" for 0..maxHwThreads-1 */
    for (i = 0; i < pHexCfg->maxHwThreads; i++) {
        /* Each element in pThreadNameArray points to a 20-char buffer,
           so ensure we don’t exceed 19 chars + NUL. */
        snprintf(pHexCfg->pThreadNameArray[i], MAX_STR_LEN_THREAD_NAME, "HW-Thrd-%u", i);
    }
    /* The extra slot is reserved for the GLOBAL cache name */
    snprintf(pHexCfg->pThreadNameArray[i], MAX_STR_LEN_THREAD_NAME, "GLOBAL");

    memset(hexa_info->pSbpHaltedThreadsPC, 0, (pHexCfg->maxHwThreads * sizeof(uint32_t *)));
    memset(hexa_info->pPerHwThrdReg, 0, (pHexCfg->maxHwThreads * sizeof(*(hexa_info->pPerHwThrdReg))));
    memset(pHexCfg->pTlbEntries, 0, (pHexCfg->numTlbEntries * sizeof(tlb_entries)));

    hexagon->is_hexagon_untrusted = false;
    hexagon->hexa_info.is_spurious_breakpoint = 1;
    return ERROR_OK;
}

static void deinitConfig(struct hexagon_arch_info *hexa_info)
{
    if (hexa_info->config.pThreadNameArray != NULL)
        free(hexa_info->config.pThreadNameArray);

    if (hexa_info->pPerHwThrdReg != NULL)
        free(hexa_info->pPerHwThrdReg);

    if (hexa_info->pSbpHaltedThreadsPC != NULL)
        free(hexa_info->pSbpHaltedThreadsPC);

    if (hexa_info->config.pTlbEntries != NULL)
        free(hexa_info->config.pTlbEntries);

    return;
}



/****************************Function declartions***********************************************/
static int hexagon_poll(struct target *target);
int  hexagon_arch_state(struct target *target);
static int hexagon_resume(struct target *target, int current, target_addr_t address,
    int handle_breakpoints, int debug_execution);
static int hexagon_step(struct target *target, int current, target_addr_t address,
            int handle_breakpoints);
static int hexagon_halt(struct target *target);
const char *hexagon_get_gdb_arch(struct target *target);
int hexagon_get_gdb_reg_list(struct target *target,
    struct reg **reg_list[], int *reg_list_size,
    enum target_register_class reg_class);

static int hexagon_read_memory(struct target *target, target_addr_t address,
    uint32_t size, uint32_t count, uint8_t *buffer);
static int hexagon_write_memory(struct target *target, target_addr_t address,
    uint32_t size, uint32_t count, const uint8_t *buffer);
static int hexagon_read_buffer (struct target *target, target_addr_t address,
        uint32_t size, uint8_t *buffer);
static int hexagon_write_buffer (struct target *target, target_addr_t address,
        uint32_t size, const uint8_t *buffer);
static int hexagon_add_breakpoint(struct target *target,
    struct breakpoint *breakpoint);
static int hexagon_remove_breakpoint(struct target *target, struct breakpoint *breakpoint);
static int hexagon_target_create(struct target *target, Jim_Interp *interp);
static int hexagon_jim_configure(struct target *target, struct jim_getopt_info *goi);
static int hexagon_init_debug_access(struct target *target);
static int hexagon_examine_first(struct target *target);
static int hexagon_examine(struct target *target);
static int hexagon_init_target(struct command_context *cmd_ctx,
    struct target *target);
static void hexagon_deinit_target(struct target *target);
static int hexagon_virt2phys(struct target *target, target_addr_t virt,
                 target_addr_t *phys);
static int hexagon_mmu(struct target *target, int *enabled);
static int hexagon_init_arch_info(struct target *target,
    struct hexagon_common *hexagon, struct adiv5_dap *dap);
static int hexagon_handle_target_request(void *priv);
static uint64_t hexagon_etm_on(struct target *target);
static void hexagon_wait_loop(void);
void micro_second_sleep(uint32_t microseconds);
static int hexagon_brkpt_setup(struct hexagon_common *hexagon);
static int hexagon_reg_setup(struct hexagon_common *hexagon);
static int hexagon_read_core_reg(struct target *target, struct reg *r, int regnum, uint32_t hwthrd);
static int hexagon_write_core_reg(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
struct reg *hexagon_reg_current(struct hexagon_arch_info *hexa_info, unsigned int regnum, 
    struct reg_cache *cache);
struct reg_cache *hexagon_build_reg_cache(struct target *target, uint32_t hwthrd);
static int hexagon_check_state_one(struct target *target,
                                        uint64_t mask, bool *halted, uint32_t *debug_thread);
int hexagon_read_current_registers(struct target *target, uint32_t hwthrd);
int hexagon_read_tlb_entry(struct target *target);
static void hexagon_update_tlb_entry_in_structure(struct hexagon_arch_info *hexa_info, uint64_t tlb_phy, uint64_t tlb_virtual, uint64_t index);

#ifdef  _HEXAGON_TARGET_TIME_PROFILING
void hexagon_start_time_cal_ms(void);
void hexagon_end_time_cal_ms(void);
#endif
static int hexagon_dump_hwthrd_reg(struct target *target);
int hexagon_read_gpr_registers(struct target *target, uint32_t hwthrd);
int hexagon_read_gpr_for_hwthrd(struct target *target, uint32_t hwthrd_mask);
int hexagon_read_ctrl_registers(struct target *target, uint32_t hwthrd);
int hexagon_read_ctrl_regs_for_hwthrd(struct target *target, uint32_t hwthrd_mask);
int hexagon_read_mmode_registers(struct target *target, uint32_t hwthrd);
int hexagon_read_imask_register(struct target *target, uint32_t hwthrd);

int hexagon_read_global_ctrl_registers(struct target *target);
void hexagon_debug_reason(struct target *target, uint64_t brkptinfo);
static int hexagon_write_gpr_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
static int hexagon_write_ctrl_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
static int hexagon_write_global_ctrl_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value);
unsigned int get_phys_page(unsigned int lo, unsigned int hi, unsigned int mask);
unsigned int get_phys_mask(unsigned int tlblo);
static unsigned int hexagon_ct0(unsigned int d);
static unsigned int hexagon_clrbit(unsigned int d, unsigned int bit);
static unsigned int hexagon_getPhysAddr_v2(uint64_t pg_tlblo, uint64_t pg_tlbhi);
static int hexagon_search_virtadd_in_tlb(struct hexagon_common *hexagon, uint64_t virt, target_addr_t *phys);
static int hexagon_search_virtadd_in_vtlb(struct target *target, uint64_t virt_add, target_addr_t *phys);
static int hexagon_memw_phys_read(struct target *target, target_addr_t phy_address, uint32_t *value);
static int hexagon_translate_va_in_asid(uint32_t asid, uint64_t va, target_addr_t *phys);

static int hexagon_memw_read(struct target *target, uint64_t virt_address, uint32_t *value);
static int hexagon_isdb_cmd_status(struct target *target, uint32_t stuff_inst, uint32_t isdb_mmode_cmd);
static void hexagon_stuff_reg_restore(struct target *target);

static void hexagon_populate_vtlb_entries(struct target *target);
static void hexagon_update_vtlb_entry_in_structure(uint64_t tlb_phy, uint64_t tlb_virtual, uint64_t index);
static void hexagon_populate_vtlb_refresh_entries(struct target *target);
static int hexagon_memw_phys_read_buffer(struct target *target,target_addr_t phy_address, uint32_t size, uint8_t * buffer);
static int hexagon_read_syscfg_register(struct target *target);
static int hexagon_memw_write(struct target *target, uint64_t virt_address, uint32_t value, uint32_t size);
static int hexagon_memw_write_buffer(struct target *target, uint64_t virt_address, uint32_t size, const uint8_t *buffer);
static int hexagon_set_breakpoint(struct target *target, struct breakpoint *breakpoint, uint64_t bpconfig);
static int hexagon_setup_isdb_config(struct target *target, uint64_t old_isdbcfg0, uint8_t hbp_num);
static int hexagon_memw_write_instruction_memory(struct target *target, uint64_t virt_address, uint32_t value, uint8_t flag);
static int hexagon_write_syscfg_register(struct target *target,uint32_t value);
static int hexagon_memwrite_mmu_bypass(struct target *target, uint64_t virt_address, uint32_t value, uint32_t size);
static int hexagon_physical_addr_store(struct target *target, uint64_t virt_addr, uint32_t value, uint32_t size);
static int hexagon_unset_breakpoint(struct target *target, struct breakpoint *breakpoint);
static uint32_t hexagon_print_pc(struct target *target, uint32_t hw_thread);
static int hexagon_read_BRKPT_through_stuff(struct target *target);
static void hexagon_populate_vtlb_data(struct target *target);
static void hexagon_hw_watchdog_disable(struct target *target);
static int hexagon_read_ISDBST(struct target *target, uint32_t *isdbsts);
static int hexagon_poll_mbxout(struct target *target);
static int hexagon_poll_isdbready(struct target *target);
static int hexagon_poll_mbxin(struct target *target);
static bool hexagon_is_mmu_enabled(struct target *target);
static bool hexagon_is_vtlb_initialized(struct target *target);
void print_active_threads(struct target* target);
int get_active_threads(struct target* target);
void print_debug_threads(struct target* target);
int get_debug_threads(struct target* target);
void print_wait_run_threads(struct target* target);
int get_wait_run_threads(struct target* target);
static int hexagon_clear_vtlb_bitmap(struct target *target, bool check_bitmap_cleared);
static int hexagon_update_vtlb_revision(struct target *target);
int hexagon_vtlb_enable_bitmap(struct target *target,
                              uint32_t bitmap_ptr_addr,
                              uint32_t entries_ptr_addr,
                              unsigned int entry_count);
static void hexagon_vtlb_bitmap_logic_enable(struct target *target);
static void hexagon_memory_map_refresh(struct target *target);

/***************************** UNTRUSTED MODE Function declarations ***********************************************/
//   parameters should explicitly specify void to indicate that it takes no arguments.
int hexagon_untrusted_concat_rsp(struct hexagon_common *hexagon);
int hexagon_untrusted_write_to_mailboxin(struct target *target, uint32_t value);
uint64_t min_u(uint64_t a, uint64_t b);
int hexagon_untrusted_read_to_mailboxout(struct target *target, uint32_t *value);
int hexagon_untrusted_poll_isdbst_set_bit(struct target *target, uint8_t bit);

int hexagon_untrusted_poll_isdbst_unset_bit(struct target *target, uint8_t bit);
int send_isdb_interrupt(struct target *target);
int hexagon_untrusted_mode(struct hexagon_common *hexagon);
static uint32_t hexagon_untrusted_convert_essential_header(untrusted_essential header);
void current_debug_thread(struct target *target, uint32_t selected_thread);

static void hexagon_print_vtlb_data(void)
{
    tlb_entries *vtlb_entry = NULL;
    uint64_t idx;
    LOG_DEBUG("Printing the VTLB content");
 
    for (idx=0; idx < hexagon_vtlb_data.valid_vtlb_no_of_entries; idx++)
    {
        vtlb_entry = hexagon_vtlb_entries + idx;
        
        LOG_DEBUG("logical,C:0x%X--0x%X| physical,  A:%d:0x%llX--0x%llX| asid, %d, glb,%d, page_size, 0x%llX,X,%d,R,%d,W,%d,0x%X--0x%X ",  vtlb_entry->virt_add_low, vtlb_entry->virt_add_high, vtlb_entry->asid,
                  vtlb_entry->phy_add_low, vtlb_entry->phy_add_high, vtlb_entry->asid, vtlb_entry->globalbit, (unsigned long long)((vtlb_entry->page_size +1)*4*1024),vtlb_entry->X,vtlb_entry->R,vtlb_entry->W, vtlb_entry->phys_tlb_raw_data, vtlb_entry->virt_tlb_raw_data);
    }
}

/****Pagetable implementation details ******/
uint32_t hexagon_pgsize_encode_to_size[MAX_NUM_SUPPORTED_PAGE_SIZE] = {
    SIZE_4K,
    SIZE_16K,
    SIZE_64K,
    SIZE_256K,
    SIZE_1M,
    SIZE_4M,
    SIZE_16M,
    SIZE_64M,
    SIZE_256M,
    SIZE_1G,
};

/* Global static declarations to be used throughout pagetable algorithm */
static const size_t g_protocol_usable_buf_size =
    MAX_RSP_BUF_SIZE; // max transport buffer size ()from experimentation)
                      // between stub and host/gdb

/**
    Count and return number of trailing zeros in unsigned int d
    @param[in]  d           unsigned int with specific number of trailing zeros

    @return
        number of trailing zeros in unsigned int d input
*/
unsigned int ct0(unsigned int d)
{
    unsigned int bit;
    if(d == 0)
    {
        return 32U;
    }
    for (bit = 0; bit < 32U; bit++) {
        if ((d & ((unsigned int)1U << bit)) != 0U) {
            return bit;
        }
    }
    
    //For avoiding compiler warning
    return 32U;
}

uint32_t hexagon_getAsid_v2(uint32_t pg_tlb)
{
    union pg_tlbhi_t tlb;
    tlb.raw = pg_tlb;
    return tlb.info.asid;
}

uint32_t hexagon_getR_v2(uint32_t pg_tlb)
{
    union pg_tlblo_t tlb;
    tlb.raw = pg_tlb;
    if ((tlb.info.perm & 0x1U) != 0U) {
        return 1;
    } else {
        return 0;
    }
}

uint32_t hexagon_getW_v2(uint32_t pg_tlb)
{
    union pg_tlblo_t tlb;
    tlb.raw = pg_tlb;
    if ((tlb.info.perm & 0x2U) != 0U) {
        return 1;
    } else {
        return 0;
    }
}

uint32_t hexagon_getX_v2(uint32_t pg_tlb)
{
    union pg_tlblo_t tlb;
    tlb.raw = pg_tlb;
    if ((tlb.info.perm & 0x4U) != 0U) {
        return 1;
    } else {
        return 0;
    }
}

uint32_t hexagon_getU_v2(uint32_t pg_tlb)
{
    union pg_tlblo_t tlb;
    tlb.raw = pg_tlb;
    return (tlb.info.usr & 0x1U);
}

static const char *hexagon_printCacheFields_v2(uint32_t pg_tlb)
{
    union pg_tlblo_t tlb;
    tlb.raw = pg_tlb;
    /* Convert cache fields into text */
    switch (tlb.info.cache) {
    case 0:
        return "Cachable, write-back, non-shared, non-L2-cacheable";
    case 1:
        return "Cachable, write-through, non-shared, non-L2-cacheable";
    case 2:
        return "RESERVED";
    case 3:
        return "RESERVED";
    case 4:
        return "Device-type";
    case 5:
        return "Cachable, write-through, non-shared, L2-cacheable";
    case 6:
        return "Uncached, shared";
    case 7:
        return "Cacheable, write-back, non-shared, L2-cacheable";
    case 8:
        return "Cacheable, write-back";
    case 9:
        return "Cacheable, write-through";
    case 10:
        return "Cacheable, write-back";
    case 11:
        return "Cacheable, write-through";
    default:
        return "Unknown";
    }
}

uint32_t hexagon_getVirtAddr_v2(uint32_t pg_tlbhi)
{
    union pg_tlbhi_t tlbhi;
    tlbhi.raw = pg_tlbhi;
    return tlbhi.info.vir_addr;
}

void hexagon_print_single_tlb_entry(int32_t *index,
     tlb_entries *entry, int32_t max_entires, char *op_buf)
{
    unsigned int tlblo = entry->phys_tlb_raw_data;
    unsigned int tlbhi = entry->virt_tlb_raw_data;
    while((tlblo == 0) && (tlbhi == 0))
    {
        *index = *index + 1;
        /* If last entry is empty. we should just return and not update op_buf so that Final packet is sent instead.*/
        if(*index == max_entires)
        {
            return;
        }
        entry = entry + 1;
        tlblo = entry->phys_tlb_raw_data;
        tlbhi = entry->virt_tlb_raw_data;
    }

    uint32_t tlblo_trailing_zeroes = ct0(tlblo);
    /* Overwrite old pagetable data with NULL so it does not appear in final
     * transmission */
    memset(op_buf, 0, MAX_RSP_BUF_SIZE);
    *op_buf = 'm'; // indicate that there is additional data to be transmitted
                   // to host/gdb
    /* Supported max pagesize of 1 GB in v81 doc leads to 9 trialing zeros.*/
    if (tlblo_trailing_zeroes < MAX_NUM_SUPPORTED_PAGE_SIZE) {
        snprintf(op_buf + 1, g_protocol_usable_buf_size,
            "%s%u%s0x%x%s0x%x%s0x%x%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s", XML_INDEX,*index,XML_VPAGE,
            (unsigned int)hexagon_getVirtAddr_v2(tlbhi), XML_PPAGE,
            (unsigned int)hexagon_getPhysAddr_v2(tlblo, tlbhi), XML_SIZE,
            (unsigned int)hexagon_pgsize_encode_to_size[tlblo_trailing_zeroes],XML_ASID_MID,
            (unsigned int)hexagon_getAsid_v2(tlbhi), XML_R, (unsigned int)hexagon_getR_v2(tlblo), XML_W,
            (unsigned int)hexagon_getW_v2(tlblo), XML_X,
            (unsigned int)hexagon_getX_v2(tlblo), XML_U, (unsigned int)(entry->U),XML_CACHE,
            entry->CCCC ,XML_S, (unsigned int)(entry->S),
             XML_V, (unsigned int)(entry->validbit), XML_G, (unsigned int)(entry->globalbit),
             XML_EP, (unsigned int)(entry->EP), XML_PPN_MSB, (unsigned int)(((entry->phy_page)>>23) & 0x1),XML_END);
    } else {
        snprintf(op_buf + 1, g_protocol_usable_buf_size,
            "%s%u%s0x%x%s0x%x%s%s%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s%u%s", XML_INDEX,*index,XML_VPAGE,
            (unsigned int)hexagon_getVirtAddr_v2(tlbhi), XML_PPAGE,
            (unsigned int)hexagon_getPhysAddr_v2(tlblo, tlbhi), XML_SIZE,"\tInvalid size",XML_ASID_MID,
            (unsigned int)hexagon_getAsid_v2(tlbhi), XML_R, (unsigned int)hexagon_getR_v2(tlblo), XML_W,
            (unsigned int)hexagon_getW_v2(tlblo), XML_X,
            (unsigned int)hexagon_getX_v2(tlblo), XML_U, (unsigned int)(entry->U),XML_CACHE,
            entry->CCCC ,XML_S, (unsigned int)(entry->S),
             XML_V, (unsigned int)(entry->validbit), XML_G, (unsigned int)(entry->globalbit),
             XML_EP, (unsigned int)(entry->EP), XML_PPN_MSB, (unsigned int)(((entry->phy_page)>>23) & 0x1),XML_END);
    }

    *index = *index + 1;
    return;
}

void hexagon_print_single_vtlb_entry(
    unsigned int tlblo, unsigned int tlbhi, char *op_buf)
{
    uint32_t tlblo_trailing_zeroes = ct0(tlblo);
    /* Overwrite old pagetable data with NULL so it does not appear in final
     * transmission */
    memset(op_buf, 0, MAX_RSP_BUF_SIZE);
    *op_buf = 'm'; // indicate that there is additional data to be transmitted
                   // to host/gdb
    /* Supported max pagesize of 1 GB in v81 doc leads to 9 trialing zeros.*/
    if (tlblo_trailing_zeroes < MAX_NUM_SUPPORTED_PAGE_SIZE) {
        snprintf(op_buf + 1, g_protocol_usable_buf_size,
            "%s%u%s0x%x%s0x%x%s0x%x%s%u%s%u%s%u%s\t%s%s", XML_ASID,
            (unsigned int)hexagon_getAsid_v2(tlbhi), XML_VPAGE,
            (unsigned int)hexagon_getVirtAddr_v2(tlbhi), XML_PPAGE,
            (unsigned int)hexagon_getPhysAddr_v2(tlblo, tlbhi), XML_SIZE,
            (unsigned int)hexagon_pgsize_encode_to_size[tlblo_trailing_zeroes],
            XML_R, (unsigned int)hexagon_getR_v2(tlblo), XML_W,
            (unsigned int)hexagon_getW_v2(tlblo), XML_X,
            (unsigned int)hexagon_getX_v2(tlblo), XML_CACHE,
            hexagon_printCacheFields_v2(tlblo), XML_END);
    } else {
        snprintf(op_buf + 1, g_protocol_usable_buf_size,
            "%s%u%s0x%x%s0x%x%s%s%s%u%s%u%s%u%s\t%s%s", XML_ASID,
            (unsigned int)hexagon_getAsid_v2(tlbhi), XML_VPAGE,
            (unsigned int)hexagon_getVirtAddr_v2(tlbhi), XML_PPAGE,
            (unsigned int)hexagon_getPhysAddr_v2(tlblo, tlbhi), XML_SIZE,
            "\tInvalid Size", XML_R, (unsigned int)hexagon_getR_v2(tlblo), XML_W,
            (unsigned int)hexagon_getW_v2(tlblo), XML_X,
            (unsigned int)hexagon_getX_v2(tlblo), XML_CACHE,
            hexagon_printCacheFields_v2(tlblo), XML_END);
    }

    return;
}
/* --------------------------------------------------------------
 * Ensure the target’s TLB cache is fresh.
 * -------------------------------------------------------------- */
static int ensure_tlb_fresh(struct target *target)
{
    struct hexagon_common *hexagon   = target_to_hexagon(target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    int retval    = ERROR_OK;

    /* -----------------------------------------------------------------
     * 1.  MMU must be on before we can even try to read TLB entries.
     * ----------------------------------------------------------------- */
    if (!hexagon_is_mmu_enabled(target)) {
        LOG_INFO("MMU not enabled – nothing to report yet");
        return ERROR_OK;               /* not an error, just “no data” */
    }

    /* -----------------------------------------------------------------
     * 2️.  The state machine may request a *forced* refresh (tlb_lldb_query_done).
     * ----------------------------------------------------------------- */
    if (qurt_context) {
        qurt_context->tlb_fetched = false;     /* invalidate any stale cache */

        retval = hexagon_read_tlb_entry(target);
        if (retval != ERROR_OK) {
            LOG_ERROR("Failed to read TLB entries (retval=%d)", retval);
            return retval;                  /* propagate the failure */
        }
        qurt_context->tlb_lldb_query_done = true;     /* we satisfied the request */
    }

    return retval;
}

/*
    Function to handle "tlb" LLDB command state machine and retireve data
    entry by entry.
*/
int handle_tlb_state_machine(struct target *target, const char *packet, char *op_buf)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    tlb_entries *hwtlb_entry = NULL;
    int ret_val = ERROR_OK;

    /*State machine variables.*/
    static uint32_t flag_first_iter = 1;
    static int32_t curr_idx = 0;
    static int32_t hwtlb_entries_total = 0;

    /* --------------------------------------------------------------
     * Make sure the TLB cache is up to date.
     * -------------------------------------------------------------- */
    if (qurt_context->tlb_lldb_query_done == true){
        ret_val = ensure_tlb_fresh(target);
        if (ret_val != ERROR_OK) {
            /* The helper already emitted a helpful log message. */
            return ret_val;                     
        }
    }

    /*********************State machine logic***************
     * curr_idx helps in tracking entry number in vtlb an dtlb tables.
     * but flag_first_iter is required to detect if current iteration is 
     * 1st iteration or not based on which we decied which 1/3 packets will go to
     * LLDB client.
     * Packet 1 - start packet 
     * Packet 2 - data packet for each entry (curr_idx 0 <- >n -1)
     * Packet 3 - Final packet $l\n</os_data>\n
     * 
    */
    /*Start and End packets.*/
    static const char *XML_INTRO_TLB = "m<osdata type=\"tlbinfo\">\n";
    static const char *XML_FINAL = "l\n</osdata>\n";

    if((strncmp(packet, "qXfer:osdata:read:tlbinfo:0,", 28) == 0))
    {
        flag_first_iter = 1;
        curr_idx = 0;
    }
    else
    {
        flag_first_iter = 0;
    }

    hwtlb_entries_total = hexa_info->config.numTlbEntries;
    hwtlb_entry = &(hexa_info->config.pTlbEntries[curr_idx]);
    if(hwtlb_entries_total == 0)
    {
        //gdb send error E01
        ret_val = 01;
        goto RETURN_TLB;
    }
   
    if(flag_first_iter == 1)
    {
        flag_first_iter = 0;
        snprintf(op_buf, strlen(XML_INTRO_TLB),"%s", (char*)XML_INTRO_TLB);
    }
    else
    {
        if(curr_idx < hwtlb_entries_total)
            hexagon_print_single_tlb_entry(&curr_idx, hwtlb_entry, hwtlb_entries_total, op_buf);
        /* Send XML_FINAL packet for last entry.*/
        if((curr_idx == hwtlb_entries_total) && (op_buf[0] == '\0'))
        {
            curr_idx = 0;
            flag_first_iter = 1;
            hwtlb_entries_total = 0;
            snprintf(op_buf,  strlen(XML_FINAL),"%s", (char*)XML_FINAL);
            goto RETURN_TLB;
        }
    }

    RETURN_TLB:
    return ret_val;
}

/*
    Function to handle "pagetable" LLDB command state machine and retireve data
    entry by entry.
*/
int handle_pagetable_state_machine(const char *packet, char *op_buf)
{
    tlb_entries *vtlb_entry = NULL;
    int ret_val = ERROR_OK;
    /*State machine variables.*/
    static uint32_t flag_first_iter = 1;
    static int32_t curr_idx = 0;
    static int32_t vtlb_entries_total = 0;

    /*********************State machine logic***************
     * curr_idx helps in tracking entry number in vtlb an dtlb tables.
     * but flag_first_iter is required to detect if current iteration is 
     * 1st iteration or not based on which we decied which 1/3 packets will go to
     * LLDB client.
     * Packet 1 - start packet 
     * Packet 2 - data packet for each entry (curr_idx 0 <- >n -1)
     * Packet 3 - Final packet $l\n</os_data>\n
     * 
    */

    /*Start and End packets.*/
    static const char *XML_INTRO_PG = "m<osdata type=\"pagetableinfo\">\n";
    static const char *XML_FINAL = "l\n</osdata>\n";

    if((strncmp(packet, "qXfer:osdata:read:pagetable:0,", 30) == 0))
    {
        flag_first_iter = 1;
        curr_idx = 0;
    }
    else
    {
        flag_first_iter = 0;
    }

    vtlb_entries_total = hexagon_vtlb_data.valid_vtlb_no_of_entries;
    vtlb_entry = hexagon_vtlb_entries + curr_idx;
    if((vtlb_entries_total == 0) || (!hexagon_vtlb_entries))
    {
        //gdb send error E01
        ret_val = 01;
        goto RETURN_PG;
    }
   
    if(flag_first_iter == 1)
    {
        flag_first_iter = 0;
        snprintf(op_buf, strlen(XML_INTRO_PG),"%s", (char*)XML_INTRO_PG);
    }
    else
    {
        /* Send XML_FINAL packet for last entry.*/
        if(curr_idx == vtlb_entries_total)
        {
            curr_idx = 0;
            flag_first_iter = 1;
            vtlb_entries_total = 0;
            snprintf(op_buf,  strlen(XML_FINAL),"%s", (char*)XML_FINAL);
            goto RETURN_PG;
        }
        hexagon_print_single_vtlb_entry(
            vtlb_entry->phys_tlb_raw_data, vtlb_entry->virt_tlb_raw_data, op_buf);
        curr_idx++;
    }

    RETURN_PG:
    return ret_val;
}

// 
/**********************************Function Definitions*****************************************/
/* this function is used to fetch SP , PC and FP value for given HW thread from gdb server  */
void hexagon_update_sp_pc_fp_gdb_server(struct target *target, unsigned int hwthrd, unsigned int * pc , 
        unsigned int * fp, unsigned int * sp)
{
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info; 

    *pc = hexa_info->pPerHwThrdReg[hwthrd][HEXAGON_PC];
    *fp = hexa_info->pPerHwThrdReg[hwthrd][HEXAGON_FP];
    *sp = hexa_info->pPerHwThrdReg[hwthrd][HEXAGON_SP];
}

uint32_t  hexagon_no_of_hw_threads(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    uint32_t temp;

    if (hexa_info->multi_thr_enabled)
        temp = hexa_info->config.maxHwThreads;
    else
        temp = 1;
    LOG_DEBUG("hexagon_no_of_hw_threads  = 0x%x  ", temp);

    return temp;
}


static int hexagon_virt2phys(struct target *target, target_addr_t virt, target_addr_t *phys)
{
    struct hexagon_common *hexagon = target_to_hexagon (target);
    uint64_t virt_add = 0;
    int ret_val = 0;
    virt_add = virt;

#ifdef _VTLB_ENABLED
    LOG_DEBUG ("virtual address : 0x%llx ", virt_add);
    bool mmu_enabled = hexagon_is_mmu_enabled(target);
    
    if (mmu_enabled)
    {
        ret_val = hexagon_search_virtadd_in_tlb (hexagon, virt_add, phys);
        if(ret_val == ERROR_OK){
            LOG_DEBUG ("virtual address found in tlb ");
            return ret_val;
        }
    
        ret_val = hexagon_search_virtadd_in_vtlb(target, virt_add, phys);
        if (ret_val == ERROR_OK){
            LOG_DEBUG ("virtual address found in vtlb ");
        }
        LOG_DEBUG ("virtual address : 0x%llx ; physical address :0x%llx", virt_add, *phys);
    }
#endif

    return ret_val;
}


/* this function is use to convert the Virtual address to physical address using TLB entries*/
static int hexagon_search_virtadd_in_tlb(struct hexagon_common *hexagon, uint64_t virt, target_addr_t *phys)
{
    uint32_t i;
    uint64_t offset = 0;
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    for (i=0;  i  <  hexa_info->config.numTlbEntries;  i++)
    {
        if( (virt >= hexa_info->config.pTlbEntries[i].virt_add_low)  &&  (virt <= hexa_info->config.pTlbEntries[i].virt_add_high))
        {
            if(hexa_info->config.pTlbEntries[i].globalbit)
            {
                offset = virt - hexa_info->config.pTlbEntries[i].virt_add_low;
                *phys = hexa_info->config.pTlbEntries[i].phy_add_low + offset;
                LOG_DEBUG("V Bit = 0x%x; G Bit = 0x%x; ASID = 0x%x ", hexa_info->config.pTlbEntries[i].validbit, hexa_info->config.pTlbEntries[i].globalbit, hexa_info->config.pTlbEntries[i].asid );

                LOG_DEBUG("i=%d; virt =0x%llx ; virt_add_low = 0x%x; phy_add_low = 0x%llx  ",i, virt, hexa_info->config.pTlbEntries[i].virt_add_low, hexa_info->config.pTlbEntries[i].phy_add_low);
                LOG_DEBUG("Physical address  = 0x%llx  ",*phys);

                return ERROR_OK;
            }
            else
            {
                offset= virt - hexa_info->config.pTlbEntries[i].virt_add_low;
                *phys = hexa_info->config.pTlbEntries[i].phy_add_low + offset;
                LOG_DEBUG("V Bit = 0x%x; G Bit = 0x%x; ASID = 0x%x ", hexa_info->config.pTlbEntries[i].validbit, hexa_info->config.pTlbEntries[i].globalbit, hexa_info->config.pTlbEntries[i].asid );

                // LOG_DEBUG("Physical address  = 0x%x  ",*phys);
                LOG_DEBUG("i=%d; virt =0x%llx ; virt_add_low = 0x%x; phy_add_low = 0x%llx  ",i, virt, hexa_info->config.pTlbEntries[i].virt_add_low, hexa_info->config.pTlbEntries[i].phy_add_low);
                return ERROR_OK;

            }
        }
    }

    if (i == hexa_info->config.numTlbEntries)
    {
        *phys = 0;
        LOG_DEBUG("Entry not found in TLB for virt address = 0x%llx  ", virt);
        return ERROR_FAIL;
    }

    return ERROR_OK;
}


/* this function is use to convert the Virtual address to physical address using VTLB entries*/
static int hexagon_search_virtadd_in_vtlb(struct target *target, uint64_t virt_add, target_addr_t *phys)
{
    uint64_t offset = 0, i;
    tlb_entries *temp = NULL;

//    hexagon_populate_vtlb_refresh_entries(target);

    if(hexagon_vtlb_data.vtlb_no_of_entries == 0)
    {
        hexagon_populate_vtlb_data(target);
    }
    for (i=0; i  <  hexagon_vtlb_data.valid_vtlb_no_of_entries; i++)
    {
        temp = hexagon_vtlb_entries + i;
        if( virt_add >= temp->virt_add_low  &&  virt_add <= temp->virt_add_high)
        {
            if(temp->globalbit)
            {
                offset= virt_add - temp->virt_add_low;
                *phys = temp->phy_add_low + offset;
                LOG_DEBUG("V Bit = 0x%x; G Bit = 0x%x; ASID = 0x%x ", temp->validbit, temp->globalbit, temp->asid );
                LOG_DEBUG("Physical address  = 0x%x  ", (uint32_t)*phys);
                return ERROR_OK;
            }
            else
            {
                offset= virt_add - temp->virt_add_low;
                *phys = temp->phy_add_low + offset;
                LOG_DEBUG("V Bit = 0x%x; G Bit = 0x%x; ASID = 0x%x ", temp->validbit, temp->globalbit, temp->asid );
                LOG_DEBUG("Physical address  = 0x%x  ", (uint32_t)*phys);
                return ERROR_OK;
            }
        }
    }
    if(i == hexagon_vtlb_data.valid_vtlb_no_of_entries)
    {
        *phys = 0;
        LOG_DEBUG("Entry not found in Vtable virt address  = 0x%llx  ", virt_add);
        return ERROR_FAIL;
    }

    return ERROR_OK;
}

/* This function refresh the VTLB entries in case of Halt / step in etc*/
static void hexagon_populate_vtlb_refresh_entries(struct target *target)
{
    int retval = ERROR_OK;

    LOG_DEBUG("hexagon_populate_vtlb_refresh_entries  Enter");

    if(hexagon_vtlb_data.vtlb_no_of_entries == 0)
    {
            hexagon_populate_vtlb_data(target);
            return;
    }

#ifdef HEXAGON_VTLB_OLD_ARCH
#ifdef HEXAGON_VTLB_AXI
    if(debug_axi_ap == NULL)
        hexagon_initialize_axi_ap(target);

    retval = mem_ap_read_buf(debug_axi_ap,
        (uint8_t *)&hexagon_vtlb_data.vtlb_current_counter, 4, 1, hexagon_vtlb_data.QURTK_vtlb_main_PA-16);
    
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("mem_ap_read_buf API failed to read");
        return;
    }
    if(hexagon_vtlb_data.vtlb_previous_counter == hexagon_vtlb_data.vtlb_current_counter)
    {
        return;
    }
    retval = mem_ap_read_buf(debug_axi_ap,(uint8_t *)&hexagon_vtlb_data.vtlb_no_of_entries, 4, 1,
                            hexagon_vtlb_data.QURTK_VTLB_DATA_PA);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("mem_ap_read_buf API failed to read");
        return;
    }
#endif

#ifdef HEXAGON_VTLB_MEM_PHYS
        hexagon_memw_phys_read(target,hexagon_vtlb_data.QURTK_vtlb_main_PA-16, &hexagon_vtlb_data.vtlb_current_counter);
        if(hexagon_vtlb_data.vtlb_previous_counter == hexagon_vtlb_data.vtlb_current_counter)
        {
            return;
        }
        hexagon_memw_phys_read(target,hexagon_vtlb_data.QURTK_VTLB_DATA_PA, &hexagon_vtlb_data.vtlb_no_of_entries);
#endif

#ifdef HEXAGON_VTLB_MEMW
        hexagon_memw_read(target,hexagon_vtlb_data.QURTK_vtlb_main_VA-16, &hexagon_vtlb_data.vtlb_current_counter);
        if(hexagon_vtlb_data.vtlb_previous_counter == hexagon_vtlb_data.vtlb_current_counter)
        {
            return;
        }
        hexagon_memw_read(target,hexagon_vtlb_data.QURTK_VTLB_DATA_VA, &hexagon_vtlb_data.vtlb_no_of_entries);
#endif
#endif 

#ifdef HEXAGON_VTLB_NEW_ARCH
    // uint64_t output[2] = {0};
    uint32_t output[2] = {0};

    bool vtlb_enabled = hexagon_is_vtlb_initialized(target);
    if (!vtlb_enabled){
        LOG_DEBUG("vtlb not enabled, returning");
        return;
    }
    hexagon_memw_read(target,hexagon_vtlb_data.QURTK_vtlb_main_VA-16,
                        &hexagon_vtlb_data.vtlb_current_counter);
    if(hexagon_vtlb_data.vtlb_previous_counter == hexagon_vtlb_data.vtlb_current_counter)
    {
        return;
    }
    hexagon_memw_read(target,hexagon_vtlb_data.QURTK_vtlb_main_VA, &output[0]);
    hexagon_memw_read(target,hexagon_vtlb_data.QURTK_vtlb_main_VA+4, &output[1]);

    // memcpy(&hexagon_vtlb_data.qurtk_vtlb_main, &output, 8);
    // LOG_DEBUG("hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr = 0x%x ",
    //           hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr);

    hexagon_memw_read(target,hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr, &output[0]);
    hexagon_memw_read(target,hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr+4, &output[1]);
    // memcpy(&hexagon_vtlb_data.qurtk_vtlb_main_next, &output, 8);
    LOG_DEBUG("hexagon_vtlb_data.qurtk_vtlb_main_next.table_entries= 0x%x ",
                hexagon_vtlb_data.qurtk_vtlb_main_next.table_entries);
    hexagon_vtlb_data.vtlb_no_of_entries =  hexagon_vtlb_data.qurtk_vtlb_main_next.table_entries;
#endif


    LOG_DEBUG("hexagon_vtlb_data.vtlb_no_of_entries = 0x%x and retval = %d",hexagon_vtlb_data.vtlb_no_of_entries,retval);

    if (hexagon_vtlb_entries == NULL)
    {
        hexagon_vtlb_entries = malloc(sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
        memset(hexagon_vtlb_entries, 0, sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
    }
    else
    {
        free(hexagon_vtlb_entries);
        hexagon_vtlb_entries = malloc(sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
        memset(hexagon_vtlb_entries, 0, sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
    }
    hexagon_populate_vtlb_entries(target);
    LOG_DEBUG("hexagon_populate_vtlb_refresh_entries  Exit");
}


/* This function used to initialize the AXI-AP */
static void hexagon_initialize_axi_ap(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct adiv5_dap *swddp = hexa_info->dap;
    int retval,i;
    
    LOG_DEBUG("hexagon_initialize_axi_ap  Enter");
    
    if(debug_axi_ap == NULL)
    {
        /* Search for the AXI-AP - it is needed for access to memory */
        retval = dap_find_get_ap(swddp, AP_TYPE_AXI_AP, &debug_axi_ap);
        if (retval != ERROR_OK) 
        {
            for(i=0; i < 10; i++)
            {
                hexagon_wait_loop();
                retval = dap_find_get_ap(swddp, AP_TYPE_AXI_AP, &debug_axi_ap);
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


/* This function populate the VTLB global data like no of entries in VTLB, counter and allocate VTLB memory for entries */
static void hexagon_populate_vtlb_data(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    uint64_t temp, temp1, temp2;
    uint32_t output[2] = {0};

    LOG_DEBUG("hexagon_populate_vtlb_data  Enter");

#ifdef HEXAGON_VTLB_NEW_ARCH

    //QURTK_vtlb_main           D:FE111F5C--FE111F5F

    // uint32_t qurtk_vtlb_main_addr = hexagon_vtlb_data.QURTK_vtlb_main_VA;
    hexagon_vtlb_data.valid_vtlb_no_of_entries = 0;

    LOG_DEBUG("qurtk_vtlb_main_addr   = 0x%x ",qurt_context->qurtk_vtlb_main_addr);
    hexagon_memw_read(target, qurt_context->qurtk_vtlb_main_addr, &hexagon_vtlb_data.QURTK_vtlb_main_VA );
    bool vtlb_enabled = hexagon_is_vtlb_initialized(target);
    if (!vtlb_enabled){
        LOG_DEBUG("vtlb not enabled, returning");
        return;
    }
    
    LOG_DEBUG("hexagon_vtlb_data.QURTK_vtlb_main_VA   = 0x%x ",hexagon_vtlb_data.QURTK_vtlb_main_VA );
    
    hexagon_memw_read(target,hexagon_vtlb_data.QURTK_vtlb_main_VA-16,
                        &hexagon_vtlb_data.vtlb_current_counter);
    hexagon_vtlb_data.vtlb_previous_counter = hexagon_vtlb_data.vtlb_current_counter;
    LOG_DEBUG("vtlb_current_counter = 0x%x ",hexagon_vtlb_data.vtlb_current_counter);

    hexagon_memw_read(target,hexagon_vtlb_data.QURTK_vtlb_main_VA, &output[0]);
    hexagon_memw_read(target,hexagon_vtlb_data.QURTK_vtlb_main_VA+4, &output[1]);

    temp = output[0] >> 8;
        temp1 = (output[1] & 0xFFF)<<24;
    temp2 = temp | temp1;
    hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr = temp2;
    
    // next_table_addr is of type long long unsigned int:36 
    // hence using format specifier llx which is for long long unsigned int (64 bit)
    LOG_DEBUG("hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr = 0x%llx ",
                (unsigned long long)hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr);

    hexagon_memw_read(target,hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr, &output[0]);
    hexagon_memw_read(target,hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr+4, &output[1]);
    //memcpy(&hexagon_vtlb_data.qurtk_vtlb_main_next, &output, 8);

    temp2 = output[1] >>12;
    hexagon_vtlb_data.qurtk_vtlb_main_next.table_entries =  temp2 ;
    
    LOG_DEBUG("hexagon_vtlb_data.qurtk_vtlb_main_next.table_entries= 0x%x ",
                hexagon_vtlb_data.qurtk_vtlb_main_next.table_entries);
    hexagon_vtlb_data.vtlb_no_of_entries =  hexagon_vtlb_data.qurtk_vtlb_main_next.table_entries;

    if (hexagon_vtlb_entries == NULL)
    {
        hexagon_vtlb_entries = malloc(sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
        memset(hexagon_vtlb_entries, 0, sizeof(tlb_entries) * hexagon_vtlb_data.vtlb_no_of_entries);
    }
#endif

    hexagon_populate_vtlb_entries(target);
    qurt_context->vtlb_initialized = true;

    LOG_DEBUG("hexagon_populate_vtlb_data  Exit");
}


/* This function populate the VTLB entries from QURTK_VTLB_DATA*/
static void hexagon_populate_vtlb_entries(struct target *target)
{
    uint32_t output[2] = {0},i,address;
    
    LOG_DEBUG("hexagon_populate_vtlb_entries  Enter");
    
#ifdef    _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
#endif


#ifdef HEXAGON_VTLB_NEW_ARCH
    address =  hexagon_vtlb_data.qurtk_vtlb_main.next_table_addr + 8;
    for (i=0; i < hexagon_vtlb_data.vtlb_no_of_entries; i++)
    {
        hexagon_memw_read(target,address, &output[0]);
        hexagon_memw_read(target,address+4, &output[1]);
        LOG_DEBUG("raw start range = 0x%08x and raw end range  = 0x%08x " , output[0],output[1]);
        hexagon_update_vtlb_entry_in_structure(output[0], output[1],i);
        address= address + 8;
    }

#endif

    hexagon_print_vtlb_data();
    
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    LOG_DEBUG("hexagon_populate_vtlb_entries  Exit");


}


/* this function update the tlb entry in global structure  hexagon_tlb_entries */
static void hexagon_update_vtlb_entry_in_structure(uint64_t tlb_phy, uint64_t tlb_virtual, uint64_t index)
{
    uint64_t mask, size = 0, virt_page = 0, phy_page = 0, virt_add = 0, phy_add =0;
    char * page_size = 0;
    tlb_entries *temp = NULL;
    union pg_tlblo_t  tlblo;
    union pg_tlbhi_t  tlbhi;

    //LOG_DEBUG("hexagon_update_vtlb_entry_in_structure  Enter");
    if ((index >= hexagon_vtlb_data.vtlb_no_of_entries) || (hexagon_vtlb_data.valid_vtlb_no_of_entries >= hexagon_vtlb_data.vtlb_no_of_entries))
    {
        // LOG_DEBUG("Index is greater than hexagon_vtlb_data.vtlb_no_of_entries");
        return;
    }
    virt_page = VIRT_PAGE(tlb_virtual);
    // previously used a mask, here we are right shifting
    // virt_page = tlb_virtual >> 12;

    if(virt_page == 0x0 )
        return;
    tlblo.raw = tlb_phy;
    tlbhi.raw = tlb_virtual;
    virt_add = virt_page << 12;

    phy_page = hexagon_getPhysAddr_v2(tlblo.raw, tlbhi.raw);
    phy_add = phy_page << 12;

    if((virt_add == 0x0) || (phy_add == 0x0) )
    {
        //LOG_DEBUG("Virtual / Physical  address is NULL for raw phy= 0x%08x and raw virtual = 0x%08x " , tlb_phy,tlb_virtual);
        return;
    }

    temp = hexagon_vtlb_entries  + hexagon_vtlb_data.valid_vtlb_no_of_entries;
    mask = get_phys_mask(tlb_phy);
    temp->virt_tlb_raw_data = tlb_virtual;
    temp->phys_tlb_raw_data = tlb_phy;
    temp->phy_page = phy_page; 
    temp->virt_page = virt_page;
    temp->asid = ASID(tlb_virtual);
    LOG_DEBUG("SID = 0x%x ", temp->asid);

    temp->asid = ASID(tlbhi.raw);
    LOG_DEBUG("SID = 0x%x ", temp->asid);

    temp->R = P_READ(tlb_phy);
    temp->W = P_WRITE(tlb_phy);
    temp->X= P_EXEC(tlb_phy);
    temp->U = P_USER(tlb_phy);
    temp->CCCC = P_CCCC(tlb_phy);
    temp->S = P_S(tlb_phy);
    temp->validbit = P_V(tlb_virtual);
    temp->globalbit= P_G(tlb_virtual);
    temp->EP = P_EP(tlb_virtual);
    temp->A1 = P_A1(tlb_virtual);
    temp->A0 = P_A0(tlb_virtual);
    page_size = PAGE_SIZE(tlb_phy, mask);
    hexagon_vtlb_data.valid_vtlb_no_of_entries++;


    if (strcmp(page_size, "4KB") == 0)
    {
        temp->page_size =  HEXAGON_TLB_PAGE_SIZE_4KB;
        size = HEXAGON_PAGE_SIZE_4K -1;
    }
    else if (strcmp(page_size, "16KB") == 0) 
    {
        temp->page_size =  HEXAGON_TLB_PAGE_SIZE_16KB;
        size = HEXAGON_PAGE_SIZE_16K-1;
    }
    else if (strcmp(page_size, "64KB") == 0) 
    {
        temp->page_size =  HEXAGON_TLB_PAGE_SIZE_64KB;
        size = HEXAGON_PAGE_SIZE_64K-1;
    }
    else if (strcmp(page_size, "256KB") == 0) 
    {
        temp->page_size =  HEXAGON_TLB_PAGE_SIZE_256KB;
        size = HEXAGON_PAGE_SIZE_256K-1;
    }
    else if (strcmp(page_size, "1MB") == 0) 
    {
        temp->page_size =  HEXAGON_TLB_PAGE_SIZE_1MB;
        size = HEXAGON_PAGE_SIZE_1M -1;
    }
    else if (strcmp(page_size, "4MB") == 0) 
    {
        temp->page_size =  HEXAGON_TLB_PAGE_SIZE_4MB;
        size = HEXAGON_PAGE_SIZE_4M -1;
    }
    else if (strcmp(page_size, "16MB") == 0) 
    {
        temp->page_size =  HEXAGON_TLB_PAGE_SIZE_16MB;
        size = HEXAGON_PAGE_SIZE_16M -1;
    }

    temp->virt_add_low= virt_add;
    temp->virt_add_high = virt_add + size;

    temp->phy_add_low = (uint64_t) temp->phy_page << 12;
    temp->phy_add_high = (uint64_t) temp->phy_add_low + size;

    LOG_DEBUG("V bit =0x%x G bit = 0x%x ASID = 0x%x ", temp->validbit, temp->globalbit, temp->asid);
    LOG_DEBUG("VA = 0x%x -- 0x%x ; PA = 0x%llx -- 0x%llx", temp->virt_add_low,temp->virt_add_high, temp->phy_add_low,temp->phy_add_high);
}

/* this interface is to read the  memory via memw interface*/
static int hexagon_memw_read(struct target *target, uint64_t virt_address, uint32_t *value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdb_mmode_cmd;
    uint64_t stuff_inst[] = {0x6ea8c000, 0x9180c007, 0x6707c029};
    /* Stuff instruction 0x6ea8c000-->{r0 =isdbmbxin} 0x9180c007-->{r7 = memw(r0+#0) } 0x6707c029-->{isdbmbxout=r7}*/
    int retval = ERROR_OK, i;

    isdb_mmode_cmd = HEXAGON_ISDB_MMODE_CMD;
    // isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF,ISDBCMD_MONITOR_LVL,
                            // ISDBCMD_TNUM_MASK_THREAD(0));

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                            hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN,virt_address);

    if (retval != ERROR_OK) 
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");

    /* Poll ISDB MBXIN for write complete. */
    retval = hexagon_poll_mbxin(target);
    if (retval != ERROR_OK){
        LOG_DEBUG("ISDB MBX_IN not found to be full");
    }

    /*For all elements in stuff_inst array.*/
    for (i=0; i < (int)(sizeof(stuff_inst)/sizeof(stuff_inst[0])); i++)
    {
        retval = hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
        if (retval != ERROR_OK)
        {
            LOG_ERROR("%s failed", __func__);
            return retval;
        }

    }

    retval = hexagon_poll_mbxout(target);
    if (retval != ERROR_OK){
        LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
    }
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, value);

    if (retval != ERROR_OK) 
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed ");
    
    return ERROR_OK;
}

/* RTOS OS-awareness HW-thread register hook (used by src/rtos/qurt.c). Serves
 * the per-HW-thread register list (R0..R31 + PC) straight from the driver's
 * per-HW-thread cache with no target reads / no memw stuffing. Required by
 * OpenOCD's SMP rtos_get_gdb_reg_list, which asks for a register list for
 * every thread. */
int hexagon_rtos_get_hwthread_reg_list(struct target *target, uint32_t tnum,
        struct rtos_reg **reg_list, int *num_regs)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    const int ngp = 32;            /* R0..R31 */
    const int n   = ngp + 1;       /* + PC */

    if (!reg_list || !num_regs)
        return ERROR_FAIL;
    if (tnum >= hexa_info->config.maxHwThreads)
        return ERROR_FAIL;

    struct rtos_reg *out = calloc(n, sizeof(struct rtos_reg));
    if (!out) {
        LOG_ERROR("hexagon_rtos_get_hwthread_reg_list: out of memory");
        return ERROR_FAIL;
    }

    for (int r = 0; r < ngp; r++) {
        uint32_t v = hexa_info->pPerHwThrdReg[tnum][HEXAGON_R0 + r];
        out[r].number = (uint32_t)r;          /* gdb R0..R31 */
        out[r].size   = 32;
        memcpy(out[r].value, &v, sizeof(v));
    }
	/* PC uses gdb WIRE regnum 40 (not 32, which is SA0). */
	uint32_t pc = hexa_info->pPerHwThrdReg[tnum][HEXAGON_PC];
    out[ngp].number = 40;
    out[ngp].size   = 32;
    memcpy(out[ngp].value, &pc, sizeof(pc));

    *reg_list = out;
    *num_regs = n;
    return ERROR_OK;
}

/* Returns the 0-based HW thread number currently selected/halted, so the RTOS
 * layer can mark the right HW thread as "current". */
uint32_t hexagon_rtos_current_hwthread(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    return (uint32_t)hexa_info->thread_id_thread_select;
}

/* Returns true once the driver has populated its software VTLB from the QuRT
 * kernel page tables — a reliable proxy for "QuRT init complete, memw reads of
 * kernel VAs are safe". Used by the RTOS module as the SW-walk auto-enable
 * gate. No target I/O. */
bool hexagon_rtos_vtlb_ready(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    return hexagon->qurt_context.vtlb_initialized;
}

/* Read a 32-bit word from a kernel/island VA via the VTLB-translate + memw_phys
 * path (no core-MMU instruction stuffing). Safe any time after the VTLB is
 * populated. Returns ERROR_FAIL if the VA has no VTLB mapping. */
/* Read a 32-bit word at a kernel virtual address via the software VTLB,
 * bypassing the core's HW MMU. No memw instruction stuffing, no core-state
 * disruption.
 *
 * CONTRACT: `address` MUST be 4-byte aligned. `memw_phys` requires word
 * alignment; if an unaligned VA is passed we align the resulting PA down to
 * the containing 4-byte word (equivalent to reading (address & ~3)). Callers
 * that need a specific byte within a word should read the aligned word and
 * mask/shift themselves (see qurt_read_u8_mmu()). */
int hexagon_rtos_read_u32_phys(struct target *target, target_addr_t address,
        uint32_t *value)
{
    target_addr_t pa = 0;
    /* Kernel VAs are GLOBAL mappings (globalbit=1); passing asid=0 matches them
     * via hexagon_translate_va_in_asid which accepts global entries for any ASID. */
    if (hexagon_translate_va_in_asid(0, (uint64_t)address, &pa) != ERROR_OK) {
        *value = 0;
        return ERROR_FAIL;
    }
    /* Align to 4 bytes (memw_phys requires word alignment). Per the contract
     * above, callers pass an aligned VA so this is normally a no-op; on an
     * unaligned VA we intentionally read the containing word. */
    target_addr_t aligned_pa = pa & ~((target_addr_t)0x3);
    int retval = hexagon_memw_phys_read(target, aligned_pa, value);
    if (retval != ERROR_OK) {
        *value = 0;
        return retval;
    }
    return ERROR_OK;
}

int hexagon_rtos_read_u32(struct target *target, target_addr_t address, uint32_t *value)
{
    uint32_t v = 0;
    int retval = hexagon_memw_read(target, (uint64_t)address, &v);
    /* memw stuffing clobbers r0/r7; restore them so the user-visible register
     * state is not corrupted by our OS-awareness read. */
    hexagon_stuff_reg_restore(target);
    if (retval != ERROR_OK) {
        *value = 0;
        return retval;
    }
    *value = v;
    return ERROR_OK;
}

/* Translate a user VA under a specific QuRT ASID to a physical address using
 * the kernel VTLB. Lets OS-awareness read a parked thread's per-process data
 * (living in a different ASID than the halted HW thread) without faulting the
 * MMU. An entry matches if it is global or its asid == the requested asid and
 * the VA falls in its range; returns ERROR_FAIL if none matches. */
static int hexagon_translate_va_in_asid(uint32_t asid, uint64_t va,
        target_addr_t *phys)
{
    if (!hexagon_vtlb_entries)
        return ERROR_FAIL;

    for (uint32_t i = 0; i < hexagon_vtlb_data.valid_vtlb_no_of_entries; i++) {
        tlb_entries *e = hexagon_vtlb_entries + i;
        if (va < e->virt_add_low || va > e->virt_add_high)
            continue;
        /* global mappings apply to every ASID; otherwise the ASID must match */
        if (!e->globalbit && e->asid != (asid & 0x7f))
            continue;
        *phys = e->phy_add_low + (va - e->virt_add_low);
        return ERROR_OK;
    }
    return ERROR_FAIL;
}

/* Read 'size' bytes from virtual 'address' as seen by the given QuRT ASID,
 * via VTLB translation + memw_phys. Handles arbitrary size/alignment by
 * reading word-aligned and trimming. Returns ERROR_FAIL (without faulting the
 * target) if the VA is not mapped in that ASID's VTLB. */
int hexagon_rtos_read_buffer_asid(struct target *target, uint32_t asid,
        target_addr_t address, uint32_t size, uint8_t *buffer)
{
    if (!buffer)
        return ERROR_FAIL;
    if (size == 0)
        return ERROR_OK;

    target_addr_t aligned = address & ~((target_addr_t)0x3);
    uint32_t lead  = (uint32_t)(address & 0x3);
    uint32_t total = lead + size;
    uint32_t words = (total + 3) / 4;

	for (uint32_t w = 0; w < words; w++) {
		target_addr_t va = aligned + 4 * w;
		target_addr_t pa = 0;
		if (hexagon_translate_va_in_asid(asid, (uint64_t)va, &pa) != ERROR_OK) {
			/* VA not mapped in this ASID -> caller falls back to "NA". */
			LOG_DEBUG("hexagon: asid-read MISS asid=%u va=0x%08x (no VTLB entry) "
			         "vtlb_entries=%u", asid, (unsigned)va,
			         hexagon_vtlb_data.valid_vtlb_no_of_entries);
			return ERROR_FAIL;
		}

		LOG_DEBUG("hexagon: asid-read HIT  asid=%u va=0x%08x -> pa=0x%08x (memw_phys)",
                 asid, (unsigned)va, (unsigned)pa);
        uint32_t v = 0;
        if (hexagon_memw_phys_read(target, pa, &v) != ERROR_OK)
            return ERROR_FAIL;

        for (uint32_t b = 0; b < 4; b++) {
            uint32_t abs_off = w * 4 + b;
            if (abs_off < lead)
                continue;
            uint32_t dst = abs_off - lead;
            if (dst >= size)
                break;
            buffer[dst] = (uint8_t)((v >> (8 * b)) & 0xff);
        }
    }
    return ERROR_OK;
}

static int hexagon_isdb_cmd_status(struct target *target, uint32_t stuff_inst, uint32_t isdb_mmode_cmd){
    struct hexagon_common *hexagon = target_to_hexagon(target);

    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval = 0;
    uint32_t cmd_status = 0, stuff_exception = 0;
    clock_t start_time = clock();
    clock_t elapsed_time_us = 0;
    const clock_t timeout_us = 10; // 10 microseconds timeout
    uint32_t isdbsts = 0;
    uint32_t isdb_prev = 0;

    /* ISDB ready poll for ISDB ready.*/
    retval = hexagon_poll_isdbready(target);
    if (retval != ERROR_OK){
        LOG_DEBUG("ISDB bit not ready");
        LOG_DEBUG("0x%x, 0x%x",stuff_inst, isdb_mmode_cmd);
    }

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                            hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdb_prev);

    if (stuff_inst != 0){
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                            hexa_info->debug_base + HEXAGON_ISDB_STFINST, stuff_inst);
    #ifdef HEXAGON_DEBUG_LOGS
        if (retval != ERROR_OK) 
            LOG_ERROR("HEXAGON_ISDB_STFINST return value is not OK");
    #endif

    }

    if (isdb_mmode_cmd != 0){
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                            hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdb_mmode_cmd);
    #ifdef HEXAGON_DEBUG_LOGS
        if (retval != ERROR_OK) 
            LOG_ERROR("HEXAGON_ISDB_ISDBCMD return value is not OK");
    #endif
    }

    /* Poll until cmd_status is not 0 or timeout */
    do {
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
#ifdef HEXAGON_DEBUG_LOGS
        if (retval != ERROR_OK) 
            LOG_ERROR("hexagon_isdb_cmd_status failed to read ISDBST");
#endif
        // micro_second_sleep(1);

        // Calculate elapsed time in microseconds
        elapsed_time_us = (clock() - start_time)*1000;
        
    } while (isdbsts != isdb_prev && elapsed_time_us < timeout_us);

    cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;
    if (cmd_status != 0) {
        LOG_ERROR("Command failed or timed out!");
        return ERROR_FAIL;
    }

    stuff_exception = isdbsts & ISDBST_STUFF_CMD_STATUS;
    if (stuff_exception) {
        LOG_ERROR("Exception occurred!");
#ifdef HEXAGON_DEBUG_LOGS
        uint32_t num_thrds = hexagon_no_of_hw_threads(target);
        hexagon_read_gpr_registers(target, num_thrds);
        hexagon_read_ctrl_registers(target, num_thrds);
        hexagon_dump_hwthrd_reg(target);
#endif
        return ERROR_FAIL;
    }

    return ERROR_OK;
}
static int hexagon_poll_mbxout(struct target *target){
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval = 0;
    uint32_t cmd_status = 0;
    uint32_t isdbsts;
    int i = 0;

    /* Poll until cmd_status is not 0 or timeout */
    do {
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
        if (retval != ERROR_OK)
            LOG_ERROR("hexagon_isdb_cmd_status failed to read ISDBST");

        cmd_status = (isdbsts & ISDBST_ISDB_MAILBOX_OUT);
        
        // Calculate elapsed time in microseconds
        i++;

    } while (!cmd_status &&  i <= HEXAGON_MAX_REG_RETRY);

    if(!(cmd_status))
        {
        LOG_DEBUG("Mailbox out bit not set");
        return ERROR_FAIL;
    }
    
    return ERROR_OK;

}

static int hexagon_poll_mbxin(struct target *target){
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdbsts;
    int retval = 0;
    uint32_t cmd_status = 0;
    int i = 0;


    /* Poll until cmd_status is not 0 or timeout */
    do {
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
        if (retval != ERROR_OK)
            LOG_ERROR("hexagon_isdb_cmd_status failed to read ISDBST");

        cmd_status = (isdbsts & ISDBST_ISDB_MAILBOX_IN);
        
        // Calculate elapsed time in microseconds
        i++;

    } while (!cmd_status &&  i <= HEXAGON_MAX_REG_RETRY);

    if(!(cmd_status))
    {
        LOG_DEBUG("Mailbox in bit not set iter = %d",i);
        return ERROR_FAIL;
    }
    return ERROR_OK;

}

static int hexagon_poll_isdbready(struct target *target){
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdbsts;
    int retval = 0;
    uint32_t cmd_status = 0;
    int i = 0;
    // clock_t start_time = clock();
    // double elapsed_time_us = 0;
    // const double timeout_us = 5.0; // 50 microseconds timeout

    /* Poll until cmd_status is not 0 or timeout */
    do {
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
        if (retval != ERROR_OK)
            LOG_ERROR("hexagon_isdb_cmd_status failed to read ISDBST");
        cmd_status = (isdbsts & ISDBST_ISDB_READY);
        if(cmd_status)
        {
            break;
    }

        micro_second_sleep(100000);
        // Calculate elapsed time in microseconds
        i++;

    } while (i <= 100);

    if(!(cmd_status))
    {
        LOG_DEBUG("ISDB ready bit not set iter = %d",i);
        return ERROR_FAIL;
    }
    
    return ERROR_OK;

}
// Enable L1 (data & instruction) and L2 caches for the target
static void hexagon_enable_l1_l2_backing_read(struct target *target, uint32_t sys_cfg)
{
    /* -----------------------------------------------------------------
     * 1. Force the L2 cache to be read‑only and write‑allocate.
     *    SYSCFG_L2NRA – No Read‑Allocate for L2
     *    SYSCFG_L2NWA – No Write‑Allocate for L2
     * ----------------------------------------------------------------- */
    sys_cfg |= SYSCFG_L2NRA | SYSCFG_L2NWA;

    /* -----------------------------------------------------------------
     * 2. Ensure L2 write‑back mode is *disabled* (we want write‑through).
     * ----------------------------------------------------------------- */
    sys_cfg &= ~SYSCFG_L2WB;

    /* -----------------------------------------------------------------
     * 3. Enable the L1 data cache.
     * ----------------------------------------------------------------- */
    sys_cfg |= SYSCFG_D_CACHE;   // L1 Data Cache

    /* -----------------------------------------------------------------
     * 4. Optionally enable the L1 instruction cache.
     *    (Most targets need this; keep it enabled unless you have a
     *    specific reason to turn it off.)
     * ----------------------------------------------------------------- */
    sys_cfg |= SYSCFG_I;   // L1 Instruction Cache

    /* -----------------------------------------------------------------
     * 5. Finally, enable the L2 cache itself.
     * ----------------------------------------------------------------- */
    sys_cfg |= SYSCFG_L2CFG;   // L2 Cache enable

    /* -----------------------------------------------------------------
     * 6. Write the updated value back to the target.
     * ----------------------------------------------------------------- */
    hexagon_write_syscfg_register(target, sys_cfg);
}

/* This function is used to read memory word using memw_phys instruction  
    In this function we passed the physical address as an argument*/
static int hexagon_memw_phys_read(struct target *target, target_addr_t phy_address, uint32_t *value)
{
    struct hexagon_common * hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdb_mmode_cmd = HEXAGON_ISDB_MMODE_CMD;
    uint64_t phy_add[2], t_phy_address = 0;
    uint32_t stuff_inst[] = {HEXAGON_STUFF_MBXIN_TO_R0, HEXAGON_STUFF_MBXIN_TO_R1, HEXAGON_STUFF_R7_TO_MEMW_PHYS, 
                    HEXAGON_STUFF_MBXOUT_TO_R7, HEXAGON_STUFF_ISYNC_INST};
    int retval,i;
    /* Stuff Inst  HEXAGON_STUFF_MBXIN_TO_R0 -->{r0 = isdbmbxin} , HEXAGON_STUFF_MBXIN_TO_R1 -->{r1 = isdbmbxin} ,
    HEXAGON_STUFF_R7_TO_MEMW_PHYS -->{r7 = memw_phys(r0,r1)} 0x6707c029-->{isdbmbxout = r7} 
    HEXAGON_STUFF_ISYNC_INST -->{isync} */

    t_phy_address = phy_address;
    if(t_phy_address == 0x0)
    {
        LOG_ERROR("Physical address passed as NULL");
        return ERROR_FAIL;
    }
    hexagon_r0_used_stuff = 1;
        hexagon_r1_used_stuff = 1;
    hexagon_r7_used_stuff = 1;

    phy_add[0] = t_phy_address & 0x7ff;
    phy_add[1] = t_phy_address >> 11;
    LOG_DEBUG("physical address= 0x%llx phy_add[0] = 0x%llx  phy_add[1] = 0x%llx",phy_address, phy_add[0],phy_add[1]);
    
    /* -----------------------------------------------------------------
     *    Read current SYSCFG register. The helper updates
     *    the global `hexagon_syscfg_reg` we copy it into a local variable
     * ----------------------------------------------------------------- */
    hexagon_read_syscfg_register(target);
    uint32_t sys_cfg = hexagon_syscfg_reg;

    hexagon_enable_l1_l2_backing_read(target, sys_cfg);
    
    for (i=0 ; i < 2; i++)
    {
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                            hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN,phy_add[i]);
        if (retval != ERROR_OK) 
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");

        retval = hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_ERROR("%s failed", __func__);
            return retval;
        }
    }
    for (i = 2; i < 4; i++){

        retval = hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_ERROR("%s failed", __func__);
            return retval;
        }
    }

    retval = hexagon_poll_mbxout(target);
    if (retval != ERROR_OK){
        LOG_ERROR("hexagon_poll_mbxout timed out, read failed");
        return retval;
    }
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, value);
    if (retval != ERROR_OK) 
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed ");

    hexagon_write_syscfg_register(target, sys_cfg);
    /* --------------------------------------------------------------------
    * isync - Guarantees that all previous writes(SYSCFG, mailbox, etc.) are
    * globally visible before the next instruction is fetched.
    * --------------------------------------------------------------------*/
    retval = hexagon_isdb_cmd_status(target, stuff_inst[4], isdb_mmode_cmd);
    if (retval != ERROR_OK){
        LOG_ERROR("%s failed", __func__);
        return retval;
    }

    return retval;
}


static int hexagon_remove_breakpoint(struct target *target, struct breakpoint *breakpoint)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    LOG_DEBUG("Entering %s\n",__FUNCTION__);

    if (breakpoint->is_set) 
    {
        hexagon_unset_breakpoint(target, breakpoint);
        if (breakpoint->type == BKPT_HARD)
            hexagon->brp_num_available++;
    }
    return ERROR_OK;
}

static int hexagon_unset_breakpoint(struct target *target, struct breakpoint *breakpoint)
{
    LOG_DEBUG("Entering %s\n",__FUNCTION__);
    int retval;
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
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
            LOG_DEBUG(" %s\t ----------------- %d\n",__FUNCTION__, __LINE__);
            //todo: this condition is true for linked BP, Need to explore more if same is applicable for hexagon??
        } 
        else 
        {
            LOG_DEBUG(" %s\t ----------------- %d\n",__FUNCTION__, __LINE__);
            int brp_i = breakpoint->number;
            if ((brp_i < 0) || (brp_i >= hexagon->brp_num))
            {
                LOG_DEBUG("Invalid BRP number in breakpoint");
                return ERROR_OK;
            }
            LOG_DEBUG("remove hw bp %i control 0x%0" PRIx32 " value 0x%0" PRIx64, brp_i, 
                brp_list[brp_i].control, brp_list[brp_i].value);
            brp_list[brp_i].used = 0;
            brp_list[brp_i].value = 0;
            brp_list[brp_i].control = 0;

            int retrycount = HEXAGON_MAX_BKPT_RETRY;
            retval = ERROR_OK;

            do
            {
                if(brp_i<1)
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

            } while((retval != ERROR_OK) && (retrycount>0));

            if (retval != ERROR_OK) 
            {
                //After 5 retries we are unable to set the HW bp then return from here
                LOG_DEBUG("BRKPTPC write failed after 5 retries 0x%llx", brp_list[brp_i].value);
                return retval;
            }

            //HW breakpoint config/settings
            retval = ERROR_OK;
            retrycount = HEXAGON_MAX_BKPT_RETRY;

            do
            {
                if (brp_i < 1)
                {
                    //todo: Migrate this work to a helper function. //bp_write_helper()
                    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                            hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG0, brp_list[brp_i].control);
                }
                else
                {
                    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                            hexa_info->debug_base + HEXAGON_ISDB_BRKPTCFG1, brp_list[brp_i].control);
                }

                if (retval != ERROR_OK) {
                    LOG_WARNING("BRKPTCFG write failed Error code: %d", retval);
                }
                --retrycount;

            }
            while((retval != ERROR_OK) && (retrycount>0));

            if (retval != ERROR_OK)
            {
                //if after 5 retries we are unable to set the HW bp then return from here
                LOG_DEBUG("BRKPTCFG failed after 5 retries 0x%x", brp_list[brp_i].control);
                return retval;
            }
            breakpoint->is_set = false;
            return ERROR_OK;
        }
    }
    else
    {
        LOG_DEBUG(" %s\t ----------------- %d\n",__FUNCTION__, __LINE__);
        //TODO: Delete sw bp
        union fourbyte val;
        
        val.byte[0] = breakpoint->orig_instr[0];
        val.byte[1] = breakpoint->orig_instr[1];
        val.byte[2] = breakpoint->orig_instr[2];
        val.byte[3] = breakpoint->orig_instr[3];
        
        LOG_DEBUG("Removing brkpt, writing back breakpoint->orig_instr = 0x%x", val.word);
        retval = hexagon_memw_write_instruction_memory(target, breakpoint->address, val.word, 1);    //replacing the original instruction in place of brkpt instruction
        //todo: check the endianness
        if (retval != ERROR_OK) 
            LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK");
    }
    // hexagon_sync(target);



    breakpoint->is_set = 0;
    return ERROR_OK;
}


static int hexagon_add_breakpoint(struct target *target, struct breakpoint *breakpoint)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    uint64_t bpconfig = 0;
    
    bpconfig |=(1<<17);     //BRKPTPC match enable


    if ((breakpoint->type == BKPT_HARD) && (hexagon->brp_num_available  <  1)) 
    {
        LOG_DEBUG("no hardware breakpoint available");
        return ERROR_TARGET_RESOURCE_NOT_AVAILABLE;
    }
    if (breakpoint->type == BKPT_HARD)
        hexagon->brp_num_available--;
    
    return hexagon_set_breakpoint(target, breakpoint, bpconfig);    //address match enable
}

static int hexagon_setup_isdb_config(struct target* target, uint64_t old_isdbcfg0, uint8_t hbp_num)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int32_t isdbcfg0 = old_isdbcfg0 , retval = ERROR_OK;


    isdbcfg0|=0x3f3f3f;
    if (hbp_num == 0)
    {
        isdbcfg0|=(1<<25);      //HW BP0 enable
    }
    else if (hbp_num == 1)
    {
        isdbcfg0|=(1<<26);       //HW BP1 enable
    }
        
    LOG_DEBUG("Writing isdbcfg0...     isdbcfg0 = 0x%x", isdbcfg0);

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_ISDBCFG0, isdbcfg0);
    if (retval != ERROR_OK)
    {
            LOG_DEBUG("ISDBCFG0 write failed 0x%x", isdbcfg0);
            return retval;
    }
    //disabling these lines as T32+EUD HBP logs doesn't do any write on isdbcfg1, Can enable later.
    int32_t isdbcfg1 = 0;
    retval = ERROR_OK;
    isdbcfg1|= 0x3F3F3F00;       //HW break0 & break1 TNUM mask SW Break TNUM Mask

    LOG_DEBUG("Writing isdbcfg1...     isdbcfg1 = 0x%x", isdbcfg1);
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

    
/** Setup hardware Breakpoint Register Pair bpconfig parameter will be considered for setting up on-chip breakpoints, otherwise ignored **/
static int hexagon_set_breakpoint(struct target *target, struct breakpoint *breakpoint, uint64_t bpconfig)
{
    LOG_DEBUG("Entering %s\n",__FUNCTION__);
    int retval;
    int brp_i = 0;
    uint32_t isdbcfg0 = 0;
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct hexagon_brp *brp_list = hexagon->brp_list;
    
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
    LOG_DEBUG("Reading isdbcfg0...     isdbcfg0 = 0x%x", isdbcfg0);

    if (breakpoint->type == BKPT_HARD)
    {
        LOG_DEBUG(" %s\t :-------: %d breakpoint->type == BKPT_HARD",__FUNCTION__, __LINE__);
        if (breakpoint->length != 4)
        {
            LOG_DEBUG("bug: breakpoint length should be 4");    //REVIEW: Not applicable if this check has been already done, also NMI bp address can be VA, VA+ASID, PA.
            return ERROR_FAIL;
        }
        LOG_DEBUG(" %s\t :-------: %d\n",__FUNCTION__, __LINE__);
                
        LOG_DEBUG(" %s\t :-------: %d\t brp_i = %d\n",__FUNCTION__, __LINE__, brp_i);
        LOG_DEBUG(" %s\t :-------: %d\t brp_list = %p\n",__FUNCTION__, __LINE__, (void *) brp_list);
        // trying to print struct hexagon_brp which does not have a valid datatype
        // instead we can print the value of the breakpoint
        LOG_DEBUG(" %s\t :-------: %d\t brp_list[brp_i] = %llx\n",__FUNCTION__, __LINE__, brp_list[brp_i].value);
        LOG_DEBUG(" %s\t :-------: %d\t brp_list[brp_i].used = %x\n",__FUNCTION__, __LINE__, brp_list[brp_i].used);
        
        while ((brp_list[brp_i].used) && (brp_i < hexagon->brp_num))
        { // brp_i < 2; 2 HW BP supported till hexagon V71, should have a MACRO for future versions
            brp_i++;
        }

        if (brp_i >= hexagon->brp_num)
        {
            LOG_DEBUG("ERROR Can't add more HW breakpoints");
            return ERROR_TARGET_RESOURCE_NOT_AVAILABLE;
        }
        breakpoint->is_set = true;        //REVIEW: NMI Significance of breakpoint->is_set field, from the intuition, it should be 1/0. Keeping as it is AARCH64
        breakpoint->number = brp_i;

        brp_list[brp_i].used = 1;
        brp_list[brp_i].value = breakpoint->address & 0xFFFFFFFFFFFFFFFC;        //keeping 64 bit for now, last 2 bit is 0 for 32bit alignment
        brp_list[brp_i].control = bpconfig;                                     //REVIEW: assuming this will hold the value of BRKPTCFG0/1 for HW bp
    
        LOG_DEBUG("set hw bp %i control 0x%0" PRIx32 " value 0x%0" PRIx64, brp_i, 
            brp_list[brp_i].control, brp_list[brp_i].value);

        //TODO: Check if T32 checks for system halted then sets HW BP, or during threads in RUN mode it sets the BP
        int retrycount;
        uint64_t brkptpc, brkptcfg;

        brkptpc = brkptcfg = retrycount = 0;
        retval = ERROR_OK;

        //HW breakpoint PC address write
        retrycount = HEXAGON_MAX_BKPT_RETRY;

        //HW breakpoint config/settings
        retval = ERROR_OK;
        brkptcfg = brp_list[brp_i].control;
        LOG_DEBUG(" %s\t :-------: %d\t :------------: brkptcfg = %llx\n",__FUNCTION__, __LINE__, brkptcfg);
        retrycount = HEXAGON_MAX_BKPT_RETRY;
        
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

        } while ((retval != ERROR_OK) && (retrycount>0));

        if (retval != ERROR_OK)
        {
            //if after 5 retries we are unable to set the HW bp then return from here
            LOG_DEBUG("BRKPTCFG failed after 5 retries 0x%llx", brkptcfg);
            return retval;
        }
            
        brkptpc = brp_list[brp_i].value;
        LOG_DEBUG(" %s\t :-------: %d\t :------------: brkptpc = %llx\n",__FUNCTION__, __LINE__, brkptpc);
        retval = ERROR_OK;
    
        do 
        {
            if (brp_i<1)
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

        } while((retval != ERROR_OK) && (retrycount>0));
            
        if (retval != ERROR_OK)
        {
            //After 5 retries we are unable to set the HW bp then return from here
            LOG_DEBUG("BRKPTPC write failed after 5 retries 0x%llx", brkptpc);
            return retval;
        }
    
//    hexagon_dump_isdb_reg(&hexagon->hexa_info);
//    hexagon_read_BRKPT_through_stuff(target);
    
    } 
    else if (breakpoint->type == BKPT_SOFT)
    {
        retval = ERROR_OK;
        
        uint64_t first_instrn_addr, current_addr;
        uint32_t parse_bits;
        first_instrn_addr = 0;
        current_addr = breakpoint->address;
        uint8_t bkwd_code_arr[4]= {0}, packet_counter = 0;
        union fourbyte  val;
    
        LOG_DEBUG("In software BP ");
        if ((breakpoint->length != 4) && (breakpoint->address == 0))
        {
            LOG_DEBUG("bug: breakpoint length should be 4 for sw breakpoints/address should not be null");
            return ERROR_FAIL;
        }
        LOG_DEBUG("Breakpoint address received from gdb address = 0x%llx", current_addr);

        val.byte[0] = val.byte[1] = val.byte[2] = val.byte[3] = 0;
        //find First instruction in the packet, There's no specific bit pattern for first instruction of current packet,
        //find out last instruction in previous packet & the next instruction will be first instruction of the current packet
        first_instrn_addr = current_addr;
        uint8_t first_instrn_found = 0;
        while(!first_instrn_found)
        {
            packet_counter++;
            first_instrn_addr-=4;    //start looking from the next address from the current instruction
            retval = ERROR_OK;
            retval = hexagon_read_buffer (target, first_instrn_addr, 4, bkwd_code_arr);
        
            if(packet_counter >= 10)
            {
                LOG_DEBUG("First instruction not found after 10 memory read, unable to set software berakpoint");
                return ERROR_FAIL;
            }
            if (retval != ERROR_OK)
            { 
                LOG_DEBUG("hexagon_memw_write_instruction_memory return value is not OK retval = %d", retval);
                continue;
            }
            LOG_DEBUG("the Opcode present at address 0x%llx is 0x%x%x%x%x", \
                first_instrn_addr, bkwd_code_arr[3], bkwd_code_arr[2], bkwd_code_arr[1], bkwd_code_arr[0]);
        
            val.byte[0] = bkwd_code_arr[0];
            val.byte[1] = bkwd_code_arr[1];
            val.byte[2] = bkwd_code_arr[2];
            val.byte[3] = bkwd_code_arr[3];

            // Instruction can be end of packet or duplex
            parse_bits = (val.word & INSTRUCTION_PARSE_FIELD) >> 14;
            if((parse_bits == END_OF_PACKET) || (parse_bits == DUPLEX_PACKET))
            {
                first_instrn_addr+=4;
                LOG_DEBUG("First instruction of the packet found at address 0x%llx", first_instrn_addr);
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
    
        retval = hexagon_memw_write_instruction_memory(target, first_instrn_addr, 0x6c20c000, 0);    //value will be ignored hard coded value is 0x6c20c000    {     brkpt }
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
        // hexagon_sync(target);

        retval = hexagon_read_buffer (target, first_instrn_addr, 4, bkwd_code_arr);


        if (retval != ERROR_OK)
        {
            LOG_DEBUG("hexagon_memw_read_instruction_memory return value is not OK retval = %d", retval);
        }
        LOG_DEBUG("Debug: after writing breakpoint The Opcode present at address 0x%llx is 0x%x%x%x%x", \
            first_instrn_addr, bkwd_code_arr[3], bkwd_code_arr[2], bkwd_code_arr[1], bkwd_code_arr[0]);
        
        //        buf_set_u32(code, 0, 32, opcode);
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
        //        */

        return ERROR_OK;
    }

    return retval;
}


/*This function write to instruction memory in this function if flag is passed as 1 means we are passing the value to write otherwise 
we need to use the brpkt instruction opcode to write into the meory*/

static int hexagon_memw_write_instruction_memory(struct target *target,uint64_t virt_address, uint32_t value, uint8_t flag)
{
    

    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdb_mmode_cmd = HEXAGON_ISDB_MMODE_CMD;
    uint64_t stuff_inst[] = {0x6ea8c000,0x6ea8c007,0xa180c700,0xa000c000,0xa800c000,0x56c0c000,0x57c0c002};
    uint64_t address[2];
    int retval = 0, i = 0;
    // target_addr_t phy_addr =0 ;

    /* Stuff instruction  
    0x6ea8c000-->{r0 = isdbmbxin } 0x6ea8c007-->{r7 = isdbmbxin } 0xa180c700-->{memw(r0+#0) = r7}
    0xa000c000-->{dccleana(r0) } 0xa800c000-->{barrier } 0x56c0c000-->{icinva(r0) } 0x57c0c002-->{isync} */

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
    #endif
    
    LOG_DEBUG("hexagon_memw_write_instruction_memory  Enter");
    
    hexagon_r0_used_stuff = 1;
    hexagon_r7_used_stuff = 1;

    if(!flag)
        value = 0x6c20c000;   //brpkt instruction opcode
    
    address[0]= virt_address;
    address[1]= value;

    LOG_DEBUG("virt_address =  0x%llx and value = 0x%x", virt_address, value);

    for(i = 0;  i < 2;  i++)
    {
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, address[i]);
        if (retval != ERROR_OK){
            LOG_ERROR("hexagon_memw_write_instruction_memory failed due to failure to write mailbox in");
            return retval;
        }

        retval = hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_ERROR("%s failed", __func__);
            return retval;
        }

    }
    
    for(i = 2; i < 7;  i++)
    {
        retval = hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_ERROR("%s failed", __func__);
            return retval;
        }
    }
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
    hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    LOG_DEBUG("hexagon_memw_write_instruction_memory Exit");
    return ERROR_OK;
}


static int hexagon_write_buffer (struct target *target, target_addr_t address,
        uint32_t size, const uint8_t *buffer)
{
    int retval = ERROR_OK;
    target_addr_t phy_addr = 0;

    if(address == 0x0)
    {
        LOG_ERROR("Virtual address passed as NULL");
        return ERROR_FAIL;
    }
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
            hexagon_start_time_cal_ms();
    #endif
    bool mmu_enabled = hexagon_is_mmu_enabled(target);
        
    if (!mmu_enabled)
    {    
        LOG_INFO("writes can be performed only after MMUs are enabled, memory write failed");
        return ERROR_FAIL;
    }

    LOG_DEBUG("address  = 0x%llx and size = %d , phy add = 0x%llx", address,size,phy_addr);
        
    if(retval == ERROR_FAIL)
    {
        LOG_DEBUG("There is no TLB mapping for virtual address    = 0x%llx ", address);
        return retval;
    }
    /* Generic handler for potentially unaligned address and sizes.*/
    retval = hexagon_memw_write_buffer(target, address, size, buffer);
    hexagon_stuff_reg_restore(target);
        
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
            hexagon_end_time_cal_ms();
            LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    return retval;
}


/*this function is use to write memory buffer using memw interface */
/*--------------------------------------------------------------*/
/* Write a buffer of any size to an (potentially unaligned) address */
/*--------------------------------------------------------------*/
static int hexagon_memw_write_buffer(struct target *target,
                                     uint64_t virt_address,
                                     uint32_t size,
                                     const uint8_t *buffer)
{
    uint32_t retval = ERROR_OK;
    const uint8_t *ptr = buffer;
    uint64_t addr = virt_address;
    uint32_t remaining = size;
    uint32_t val = 0;

    /* ---- 1‑byte writes until the address is 4‑byte aligned ---- */
    while ((addr & HEXAGON_MOD_4_BINARY_MASK) && remaining) {
        memcpy(&val, ptr, BYTE_SIZE);
        retval = hexagon_physical_addr_store(target, addr, val, BYTE_SIZE);
        if (retval != ERROR_OK)
            return retval;
        addr   += BYTE_SIZE;
        ptr    += BYTE_SIZE;
        remaining--;
    }

    /* ---- 4‑byte writes for the bulk of the data ---- */
    while (remaining >= WORD_SIZE) {
        memcpy(&val, ptr, WORD_SIZE);
        retval = hexagon_physical_addr_store(target, addr, val, WORD_SIZE);
        if (retval != ERROR_OK)
            return retval;
        addr   += WORD_SIZE;
        ptr    += WORD_SIZE;
        remaining -= WORD_SIZE;
    }

    /* ---- Handle any trailing bytes (< 4) ---- */
    while (remaining) {
        memcpy(&val, ptr, BYTE_SIZE);
        retval = hexagon_physical_addr_store(target, addr, val, BYTE_SIZE);
        if (retval != ERROR_OK)
            return retval;
        addr   += BYTE_SIZE;
        ptr    += BYTE_SIZE;
        remaining--;
    }

    return retval;
}

/*This function used to write memory using memw interface  */
static int hexagon_memw_write(struct target *target,uint64_t virt_address, uint32_t value, uint32_t size)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdb_mmode_cmd = HEXAGON_ISDB_MMODE_CMD, sys_cfg;
    uint32_t stuff_inst[] = {0x6ea8c000, 0x6ea8c007, 0xa180c700, 0xa000c000, 0xa800c000, 0xa840c000};
    // uint32_t stuff_inst[] = {0x6ea8c01f, 0x6ea8c01f, 0xab1edf08, 0x6ea8c01e, 0x6ea8c01f, 0x921ffe1f, 0x671fc029 ,0xa800c000, 0xa840c000 };

    uint64_t address[2];
    int retval,i = 0;

    /* 
    opcodes[0x7190] <+176>:  0x6ea8c01e  {  r30 = isdbmbxin }
    opcodes[0x7194] <+180>:  0x6ea8c01f  {  r31 = isdbmbxin }
    opcodes[0x7198] <+184>:  0xab1edf08  {  memb(r30++#0x1) = r31 }
    opcodes[0x719c] <+188>:  0x6ea8c01e  {  r30 = isdbmbxin }
    opcodes[0x71a0] <+192>:  0x6ea8c01f  {  r31 = isdbmbxin }
    opcodes[0x71a4] <+196>:  0x921ffe1f  {  r31 = memw_phys(r31,r30) }
    opcodes[0x71a8] <+200>:  0x671fc029  {  isdbmbxout = r31 }

    Stuff inst  
    0x6ea8c01f-->{r30 = isdbmbxin }
    0x6ea8c01f-->{r31 = isdbmbxin} 
    0xa180c700-->{memb(r0+#0) = r31 } 
    0xa000c000-->{dccleana(r0) } 0xa800c000-->{barrier } 0xa840c000-->{syncht } 

    Stuff inst  0x6ea8c000-->{r0 = isdbmbxin }0x6ea8c007-->{r7 = isdbmbxin} 
    0xa180c700-->{memw(r0+#0) = r7 } 0xa000c000-->{dccleana(r0) } 0xa800c000-->{barrier } 0xa840c000-->{syncht } 
    */

    LOG_DEBUG("hexagon_memw_write Enter");


    LOG_DEBUG("size is %d", size);

    if(size == 1)
    {
        stuff_inst[2] = 0xa100c700;  /* {memb(r0+#0) = r7} */
        // stuff_inst[2] = 0xab1edf08;
        // LOG_DEBUG("size is %d", size );

        // retval =  hexagon_virt2phys(target, virt_address, &address[0]);        

    }
    if(size == 2)
    {
        stuff_inst[2] = 0xa140c700;  /* {memh(r0+#0) = r7} */
        // LOG_DEBUG("size is %d", size );
        // address[0]= virt_address;ss

    }
    LOG_DEBUG("address is 0x%llx\nvalue to be written is 0x%x", virt_address, value );

    address[0]= virt_address;
    address[1]= value;

    LOG_DEBUG("address[0] = 0x%llx, address[1] = 0x%llx", address[0], address[1]);

    hexagon_r0_used_stuff = 1;
    hexagon_r7_used_stuff = 1;

    retval = hexagon_read_syscfg_register(target);
    if(retval == ERROR_OK){
        sys_cfg = hexagon_syscfg_reg;
        sys_cfg = sys_cfg | SYSCFG_L2NRA | SYSCFG_L2NWA;
        sys_cfg = sys_cfg & ~(SYSCFG_L2WB);
        LOG_DEBUG("Writing value in SYSCFG  = 0x%x ", sys_cfg);
        
        /* Kept commented since we need to find why uncommenting is leading to not reaching main.*/
        //hexagon_write_syscfg_register(target,sys_cfg);
        //hexagon_isdb_cmd_status(target, syncht_opcode, isdb_mmode_cmd);
    } 

    for(i = 0; i < 2;  i++){
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, address[i]);
        LOG_DEBUG ("writing address[i] as 0x%llx", address[i]);
    
        if (retval != ERROR_OK) 
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
        
        hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
    }

    for (i=2; i < 4; i++){

        hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
    }

    LOG_DEBUG("hexagon_memw_write  Exit");
    return ERROR_OK;
}

/*****************************************************************************************
 * hexagon_memwrite_mmu_bypass
 *
 * Description
 * ------------
 * Implements a low‑level memory write using the Hexagon ISDB “stuff” instruction
 * interface while bypassing the MMU.  The routine supports writing a single byte,
 * a half‑word (2 bytes) or a full word (4 bytes) to an arbitrary virtual address.
 *
 * Flow
 * ----
 * 1. Retrieve the Hexagon private data structures from the target.
 * 2. Obtain the DAP pointer (swddp) for later power‑control calls.
 * 3. Prepare the generic ISDB monitor‑mode command (`HEXAGON_ISDB_MMODE_CMD`).
 * 4. Select the appropriate “stuff” opcode for the requested size:
 *      • size == 1 → 0xa100c700   (memb  r0+#0 = r7)
 *      • size == 2 → 0xa140c700   (memh  r0+#0 = r7)
 *      • otherwise   → default 0xa180c700 (memw  r0+#0 = r7)
 * 5. Load the target address and the data value into the ISDB mailbox‑in
 *    registers (`HEXAGON_ISDB_ISDBMBXIN`).  This is performed in two steps:
 *      – address[0] = virt_address
 *      – address[1] = value
 *    Each element is written with `mem_ap_write_atomic_u32`.
 * 6. Mark registers r0 and r7 as “used” by the stuff sequence (`hexagon_r0_used_stuff`,
 *    `hexagon_r7_used_stuff`) so they can be restored later.
 * 7. Execute the prepared stuff instructions:
 *      a) For i = 0,1 – write the mailbox values and issue the corresponding
 *         `hexagon_isdb_cmd_status` to load r0 (address) and r7 (data).
 *      b) For i = 2,3 – perform the actual memory write (`memw`/`memb`/`memh`) and
 *         follow it with an `isync` and a `syncht` to ensure ordering.
 * 8. Return `ERROR_OK` on success or the error code from the first failing
 *    operation.
 *
 * Parameters
 * ----------
 * target        – Pointer to the OpenOCD target structure.
 * virt_address  – Virtual address to write to.
 * value         – 32‑bit value containing the data to be written.
 * size          – Number of bytes to write (1, 2 or 4).  Values other than 1 or 2
 *                 fall back to a 4‑byte word write.
 *
 * Return Value
 * ------------
 * ERROR_OK on success, otherwise an OpenOCD error code (e.g. ERROR_FAIL,
 * ERROR_TIMEOUT, etc.) propagated from the underlying DAP or ISDB operations.
 *
 * Notes
 * -----
 * • The function does **not** perform any alignment checks – the caller must
 *   ensure that `virt_address` is appropriate for the requested `size`.
 * • After the write completes, the caller should invoke `hexagon_stuff_reg_restore`
 *   (or the higher‑level write APIs) to restore the temporary r0/r7 state.
 *****************************************************************************************/
static int hexagon_memwrite_mmu_bypass(struct target *target,uint64_t virt_address, uint32_t value, uint32_t size)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdb_mmode_cmd = HEXAGON_ISDB_MMODE_CMD;
    uint32_t stuff_inst[] = {HEXAGON_STUFF_MBXIN_TO_R0, HEXAGON_STUFF_MBXIN_TO_R7, HEXAGON_STUFF_R7_TO_MEMW, HEXAGON_STUFF_ISYNC_INST, HEXAGON_STUFF_SYNCHT_INST, HEXAGON_STUFF_SYNCHT_INST};

    uint64_t address[2];
    int retval,i = 0;

    /* 
    Stuff inst  HEXAGON_STUFF_MBXIN_TO_R0-->{r0 = isdbmbxin }HEXAGON_STUFF_MBXIN_TO_R7-->{r7 = isdbmbxin} 
    HEXAGON_STUFF_R7_TO_MEMW-->{memw(r0+#0) = r7 } HEXAGON_STUFF_ISYNC_INST-->{isync} HEXAGON_STUFF_BARRIER_INST-->{barrier } HEXAGON_STUFF_SYNCHT_INST-->{syncht } 
    */

    LOG_DEBUG("hexagon_memw_write Enter");


    LOG_DEBUG("size is %d", size);

    if(size == 1)
    {
        stuff_inst[2] = HEXAGON_STUFF_R7_TO_MEMB;  /* {memb(r0+#0) = r7} */
    }
    if(size == 2)
    {
        stuff_inst[2] = HEXAGON_STUFF_R7_TO_MEMH;  /* {memh(r0+#0) = r7} */
    }
    LOG_DEBUG("address is 0x%llx\nvalue to be written is 0x%x", virt_address, value );

    address[0]= virt_address;
    address[1]= value;

    LOG_DEBUG("address[0] = 0x%llx, address[1] = 0x%llx", address[0], address[1]);

    hexagon_r0_used_stuff = 1;
    hexagon_r7_used_stuff = 1;

    for(i = 0; i < 2;  i++){
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, address[i]);
        LOG_DEBUG ("writing address[i] as 0x%llx", address[i]);
    
        if (retval != ERROR_OK) 
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
        
        hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
    }

    for (i=2; i <= 3; i++){

        hexagon_isdb_cmd_status(target, stuff_inst[i], isdb_mmode_cmd);
    }

    LOG_DEBUG("hexagon_memw_write  Exit");
    return ERROR_OK;
}

/*====================================================================*/
/*  Store a word when the physical address is known (or can be      */
/*  obtained from a VA→PA translation).                               */
/*====================================================================*/
/*
 * This routine now **always** forces the MMU off and applies a temporary
 * L2‑cache configuration (no‑read‑allocate, no‑write‑allocate,
 * write‑through) before performing the store.  The original SYSCFG
 * value is restored at the end.
 *
 * Supported configurations:
 *   – MMU OFF, D‑cache ON, L2 ON
 *   – MMU OFF, D‑cache ON, L2 OFF
 *   – MMU OFF, D‑cache OFF, L2 OFF (backing storage)
 *   – The only unsupported case is “MMU OFF, D‑cache OFF, L2 ON”.
 *
 * Steps performed:
 *   1. Read SYSCFG.
 *   2. Reject the unsupported configuration.
 *   3. If MMU is ON, translate VA → PA; otherwise the address is already
 *      physical.
 *   4. Build a temporary SYSCFG that clears the MMU bit and forces the
 *      L2 cache to the required mode.
 *   5. Write the temporary SYSCFG.
 *   6. (No syncht is issued – it is unnecessary for this flow.)
 *   7. Perform the store with `hexagon_memwrite_mmu_bypass`.
 *   8. Restore the original SYSCFG.
 *   9. (No final syncht is issued.)
 *
 * All errors are propagated; if the temporary SYSCFG was written we
 * attempt to restore the original value before returning.
 */
static int hexagon_physical_addr_store(struct target *target,
                                         uint64_t virt_addr,
                                         uint32_t value,
                                         uint32_t size)
{
    int retval = ERROR_OK;
    uint32_t orig_syscfg = 0;          /* SYSCFG saved at entry            */
    uint32_t tmp_syscfg;               /* temporary SYSCFG for the store   */
    /* syncht opcode is no longer used – it has been removed from the flow */
    target_addr_t phys_addr = 0;

    /*-----------------------------------------------------------*/
    /* 1. Read the SYSCFG register                               */
    /*-----------------------------------------------------------*/
    retval = hexagon_read_syscfg_register(target);
    if (retval != ERROR_OK) {
        LOG_DEBUG("Failed to read SYSCFG");
        return retval;
    }
    orig_syscfg = hexagon_syscfg_reg;   /* keep a copy of the original value */

    /*-----------------------------------------------------------*/
    /* 2. Decode cache/MMU bits and reject the only unsupported   */
    /*    configuration (MMU OFF, D‑cache OFF, L2 ON)             */
    /*-----------------------------------------------------------*/
    bool mmu_on    = (orig_syscfg & SYSCFG_MMU_BIT) != 0;          /* SYSCFG[0]  */
    bool dcache_on = (orig_syscfg & SYSCFG_D_CACHE) != 0;          /* SYSCFG[2]  */
    uint32_t l2_cfg = (orig_syscfg >> SYSCFG_L2_CACHE) & SYSCFG_L2_CACHE_BIT_MASK;/* SYSCFG[18:16] */

    if (!dcache_on && l2_cfg != 0) {
        LOG_ERROR(" D‑cache OFF, L2 cache ON Not supported yet");
        return ERROR_FAIL;
    }

    /*-----------------------------------------------------------*/
    /* 3. Translate VA → PA only when MMU is currently ON        */
    /*-----------------------------------------------------------*/
    if (mmu_on) {
        retval = hexagon_virt2phys(target, virt_addr, &phys_addr);
        if (retval != ERROR_OK) {
            LOG_DEBUG("No VA→PA mapping for 0x%llx", virt_addr);
            return retval;
        }
    } else {
        phys_addr = virt_addr;      /* address already physical */
    }

    /*-----------------------------------------------------------*/
    /* 4‑5. Build temporary SYSCFG (MMU forced off, L2 forced to   */
    /*      no‑read‑allocate, no‑write‑allocate, write‑through)   */
    /*-----------------------------------------------------------*/
    tmp_syscfg = orig_syscfg;
    tmp_syscfg &= ~ SYSCFG_MMU_BIT;   /* force MMU off unconditionally */
    tmp_syscfg |=  SYSCFG_L2NRA;   /* L2NRA */
    tmp_syscfg |=  SYSCFG_L2NWA;   /* L2NWA */
    tmp_syscfg &= ~ SYSCFG_L2WB;  /* L2WB  */

    LOG_DEBUG("Original SYSCFG=0x%08x  Temporary SYSCFG=0x%08x",
              orig_syscfg, tmp_syscfg);

    retval = hexagon_write_syscfg_register(target, tmp_syscfg);
    if (retval != ERROR_OK) {
        LOG_DEBUG("Failed to write temporary SYSCFG (0x%08x)", tmp_syscfg);
        return retval;
    }

    /*-----------------------------------------------------------*/
    /* 6. No syncht required – the cache mode change is already   */
    /*    visible to the core for the subsequent store.          */
    /*-----------------------------------------------------------*/

    /*-----------------------------------------------------------*/
    /* 7. Perform the actual store (address is now physical)      */
    /*-----------------------------------------------------------*/
    retval = hexagon_memwrite_mmu_bypass(target, phys_addr, value, size);
    if (retval != ERROR_OK) {
        LOG_DEBUG("memw_write failed for address 0x%llx", phys_addr);
        /* attempt to restore the original SYSCFG before exiting */
        (void)hexagon_write_syscfg_register(target, orig_syscfg);
        return retval;
    }

    /*-----------------------------------------------------------*/
    /* 8‑9. Restore original SYSCFG (no final syncht needed)     */
    /*-----------------------------------------------------------*/
    retval = hexagon_write_syscfg_register(target, orig_syscfg);
    if (retval != ERROR_OK) {
        LOG_DEBUG("Failed to restore original SYSCFG (0x%08x)", orig_syscfg);
        return retval;
    }

    return ERROR_OK;
}


/*================================================================*/
/* hexagon‑untrusted – MMU on‑the‑fly helper                     */
/*================================================================*/

/// Returns *true* when the target’s MMU is enabled.
/// The check is performed by reading the SYSCFG register and
/// applying the mask you supplied: (orig_syscfg & SYSCFG_MMU_BIT) != 0
static bool hexagon_is_mmu_enabled(struct target *target)
{
    uint32_t orig_syscfg = 0;
    int retval;

    /*-----------------------------------------------------------*/
    /* 1. Read the SYSCFG register                               */
    /*-----------------------------------------------------------*/
    retval = hexagon_read_syscfg_register(target);
    if (retval != ERROR_OK) {
        LOG_ERROR("Failed to read SYSCFG (retval=%d)", retval);
        return false;
    }
    orig_syscfg = hexagon_syscfg_reg;   /* keep a copy of the original value */


    /* Apply the mask you gave */
    bool mmu_on = (orig_syscfg & SYSCFG_MMU_BIT) != 0U;  // explicit: nonzero → true

    /* Keep the historic flag in sync for any code that only reads it */
    struct hexagon_common *hexagon = target_to_hexagon(target);
    hexagon->hexa_info.mmu_init = mmu_on;

#ifdef HEXAGON_DEBUG_LOGS
    LOG_DEBUG("MMU is %s (SYSCFG=0x%08x)",
              mmu_on ? "enabled" : "disabled", orig_syscfg);
#endif
    return mmu_on;
}
static int hexagon_clear_vtlb_bitmap(struct target *target, bool check_bitmap_cleared)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    uint32_t bitmap_addr;
    int retval;

    /* Base address contains pointer to bitmap array */
    qurt_context->bitmap_addr = qurt_context->qurtk_vtlb_bitmap;

    retval = hexagon_memw_read(target,
                               qurt_context->bitmap_addr,
                               &bitmap_addr);
    if (retval != ERROR_OK) {
        LOG_ERROR("Failed to read bitmap base address");
        return retval;
    }

    /* Number of 32-bit bitmap words */
    uint32_t bitmap_words =
        hexagon_vtlb_data.vtlb_no_of_entries / 32;

    /* Clear bitmap */
    for (uint32_t i = 0; i < bitmap_words; i++) {
        retval = hexagon_memw_write(target, bitmap_addr, 0x0, 4);
        if (retval != ERROR_OK) {
            LOG_ERROR("Bitmap clear failed at 0x%x", bitmap_addr);
            return retval;
        }
        bitmap_addr += 4;
    }

    /* Verification: re-read and check the bitmap content */
    if (check_bitmap_cleared) {
        /* Re-read base pointer */
        retval = hexagon_memw_read(target,
                                qurt_context->bitmap_addr,
                                &bitmap_addr);
        if (retval != ERROR_OK)
            return retval;

        /* Verify that all entries previously forced to 0 are indeed zero */
        bool all_zero = true;
        uint32_t read_val = 0;
        uint32_t nonzero_count = 0;

        /* bitmap_words should match the count used in the clear loop (~line 3039) */
        for (uint32_t i = 0; i < bitmap_words; i++) {
            retval = hexagon_memw_read(target, bitmap_addr, &read_val);
            if (retval != ERROR_OK)
                return retval;

            if (read_val != 0U) {
                all_zero = false;
                nonzero_count++;
                LOG_DEBUG("VTLB bitmap check: addr=0x%08x val=0x%08x (expected 0)",
                        bitmap_addr, read_val);
            }
            bitmap_addr += 4U;  /* advance to next 32-bit word */
        }

        if (!all_zero) {
            LOG_ERROR("VTLB bitmap clear verification FAILED: %u of %u words non-zero",
                    nonzero_count, bitmap_words);
            return ERROR_FAIL;
        }

        /* Success path print for working case */
        LOG_DEBUG("VTLB bitmap clear verification SUCCESS: all %u entries are zero",
                bitmap_words);
    }

    return ERROR_OK;
}

/* Enablement of bitmap logic will be done from vtlb enable  */
static void hexagon_vtlb_bitmap_logic_enable(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

    if (qurt_context->vtlb_bitmap_logic_init_done){
        LOG_DEBUG("vtlb_bitmap_logic_init_done is done");
        return;
    }
    int retval;

    retval = hexagon_vtlb_enable_bitmap(target,
                                     (uint32_t)qurt_context->bitmap_addr,
                                     (uint32_t)qurt_context->qurtk_vtlb_entries,
                                     hexagon_vtlb_data.vtlb_no_of_entries);
    if (retval != ERROR_OK) {
        LOG_ERROR("hexagon_vtlb_enable_bitmap failed (%d); deferring", retval);
        return; /* do not mark done; we'll try again on a subsequent call */
    }

    retval = hexagon_clear_vtlb_bitmap(target, true);
    if (retval != ERROR_OK) {
        LOG_ERROR("hexagon_clear_vtlb_bitmap failed (%d); deferring", retval);
        return ;
    }

    retval = hexagon_update_vtlb_revision(target);
    if (retval != ERROR_OK) {
        LOG_ERROR("hexagon_update_vtlb_revision failed (%d); deferring", retval);
        return;
    }

    qurt_context->vtlb_bitmap_logic_init_done = true;
    LOG_INFO("VTLB bitmap enabled, cleared, and revision cached (one-time init)");
    
    return;
}

/*====================================================================*/
/*  hexagon_is_vtlb_initialized – check whether the VTLB unit is active   */
/*====================================================================*/
static bool hexagon_is_vtlb_initialized(struct target *target)
{
    struct hexagon_common   *hexagon   = target_to_hexagon(target);
    struct qurt_context_t   *qurt_context      = &hexagon->qurt_context;
    uint32_t                 vtlb_main = 0;
    int                      retval;

    /* --------------------------------------------------------------
     * 1.  The address of the VTLB “main” register is supplied by the
     *     ELF (or by a previous “set” command) and lives in
     *     qctx->qurtk_vtlb_main_addr.
     * -------------------------------------------------------------- */
    if (qurt_context->qurtk_vtlb_main_addr == 0) {
        LOG_DEBUG("VTLB main address not configured – VTLB disabled");
        return false;
    }

    /* --------------------------------------------------------------
     * 2.  Read the VTLB main register through the Hexagon “memw”
     *     instruction helper.  The helper already takes care of any
     *     required MMU‑to‑physical translation, so we can call it
     *     directly.
     * -------------------------------------------------------------- */
    retval = hexagon_memw_read(target,
                               qurt_context->qurtk_vtlb_main_addr,
                               &vtlb_main);
    if (retval != ERROR_OK) {
        LOG_ERROR("Failed to read VTLB main register at 0x%x "
                  "(retval=%d)", qurt_context->qurtk_vtlb_main_addr, retval);
        return false;
    }

    /* --------------------------------------------------------------
     * 3.  Store the value in the global VTLB data structure – this is
     *     what the rest of the code expects (e.g. hexagon_populate_vtlb_*).
     * -------------------------------------------------------------- */
    hexagon_vtlb_data.QURTK_vtlb_main_VA = vtlb_main;

    /* --------------------------------------------------------------
     * 4.  A non‑zero value means the VTLB unit is enabled.
     * -------------------------------------------------------------- */
    if (vtlb_main == 0) {
        LOG_DEBUG("VTLB main register reads 0 - VTLB not enabled");
        return false;
    }

    if (qurt_context->vtlb_initialized == true){
        hexagon_vtlb_bitmap_logic_enable(target);
    }
    LOG_DEBUG("VTLB enabled - QURTK_vtlb_main_VA = 0x%08x", vtlb_main);
    return true;
}

static int hexagon_read_buffer (struct target *target, target_addr_t address,
        uint32_t size, uint8_t *buffer)
{
    int retval = ERROR_OK;
    target_addr_t phy_addr = 0;

#ifdef  HEXAGON_DEBUG_LOGS
    start_buffer = clock();
#endif

    if (!buffer) {
        LOG_ERROR("hexagon_read_buffer: destination buffer is NULL");
        return ERROR_FAIL;
    }
    if (size == 0) {                     
        LOG_DEBUG("hexagon_read_buffer: size == 0 – nothing to read");
        return ERROR_OK;                
    }

    if(address == 0x0){
        LOG_DEBUG("Virtual address passed as NULL");
        return ERROR_FAIL;
    }

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
            hexagon_start_time_cal_ms();
    #endif
    bool mmu_enabled = hexagon_is_mmu_enabled(target);
        
    if (mmu_enabled)
    {
        retval=  hexagon_virt2phys(target, address, &phy_addr);
        if(retval == ERROR_FAIL){
            LOG_DEBUG("There is no TLB mapping for virtual address = 0x%x ", (uint32_t)address);
            return retval;
        }
    }
    else if (!mmu_enabled){
        phy_addr = address;
    }

    /* ---------------------------------------------------------------
    Unified read buffer implementation
    Generic implementation - handles any size request and any address alignment.
    --------------------------------------------------------------- */

    /* Align address down to its 4‑byte word.
    * phy_addr          – original (possibly unaligned) address
    * HEXAGON_MOD_4_BINARY_MASK (0x3) – low‑2 bits = byte offset (0‑3)
    * HEXAGON_ALIGN_MASK ( ~HEXAGON_MOD_4_BINARY_MASK ) – clears those bits
    * Result: greatest address ≤ phy_addr that is a multiple of 4,
    *         i.e. the word‑aligned base address required by Hexagon
    *         word‑access primitives. */
    target_addr_t aligned_addr = phy_addr & ((target_addr_t) HEXAGON_ALIGN_MASK);
    /* Extract the byte offset (0‑3) of phy_addr within its 4‑byte word.
    * HEXAGON_MOD_4_BINARY_MASK (0x3) – isolates the low‑2 bits.
    * Cast to uint32_t because the value always fits in 2 bits. */
    uint32_t offset = (uint32_t)(phy_addr & HEXAGON_MOD_4_BINARY_MASK);   // 0‑3

    /* ---------------------------------------------------------------
    The macro adds 3 (max remainder) then masks off the low two bits,
    yielding the smallest multiple of 4 ≥ (offset+size).
    --------------------------------------------------------------- */
    uint32_t total_len = HEXAGON_ROUND_UP_TO_4(offset + size);   // round‑up to 4 bytes


    /* ---------------------------------------------------------------
    Use a tiny stack buffer (16 bytes = max 4 words) for the common
    small‑read case – zero‑cost allocation, no malloc failure.
    Fall back to malloc only for larger reads.
    --------------------------------------------------------------- */
    uint8_t stack_buf[16];                /* 16‑byte stack buffer */
    uint8_t *tmp_buf = (total_len <= sizeof(stack_buf))
                       ? stack_buf
                       : malloc(total_len);

    if (!tmp_buf) {
        LOG_ERROR("allocation failed in hexagon_read_buffer");
        return ERROR_FAIL;
    }

    /* Bulk read the aligned region */
    retval = hexagon_memw_phys_read_buffer(target, aligned_addr,
                                total_len, tmp_buf);

    /* On exception, timeout, or any error condition, update the register cache
     * with the latest values from the target before returning. */
    if (retval != ERROR_OK)
    {
        LOG_ERROR("%s failed", __func__);
        /* Free only if we actually allocated from the heap */
        if (tmp_buf != stack_buf)
           free(tmp_buf);

        uint32_t num_thrds = hexagon_no_of_hw_threads(target);
        hexagon_read_gpr_registers(target, num_thrds);
        hexagon_read_ctrl_registers(target, num_thrds);
        hexagon_read_mmode_registers(target, num_thrds);
        hexagon_read_global_ctrl_registers(target);
        hexagon_dump_hwthrd_reg(target);
        hexagon_stuff_reg_restore(target);
        return retval;
    }

    /* ---------------------------------------------------------------
        Trim the extra bytes:
        - Leading bytes (0 … offset‑1) are skipped by starting the copy at
            tmp_buf + offset.
        - Trailing bytes (if any) are ignored because we copy only `size`
            bytes. No further action is needed.
   --------------------------------------------------------------- */
    memcpy(buffer, tmp_buf + offset, size);

    LOG_DEBUG("hexagon_read_buffer: requested %u bytes @ 0x%llx "
            "(aligned @ 0x%llx, offset %u, total_len %u)",
            size, phy_addr, aligned_addr, offset, total_len);
                
    /* Free only if we actually allocated from the heap */
    if (tmp_buf != stack_buf) {
        free(tmp_buf);
    }

#ifdef HEXAGON_DEBUG_LOGS
    end_buffer = clock();
    buffer_execution = ((double)(end_buffer - start_buffer))/CLOCKS_PER_SEC;
#endif
    hexagon_stuff_reg_restore(target);

    return retval;
}


/* This function is used to read memory of request size using memw_phys  instruction  
    In this function we passed the physical address as an argument */
static int hexagon_memw_phys_read_buffer(struct target *target,target_addr_t phy_address, uint32_t size, uint8_t * buffer)
{
    uint32_t count, i;
    uint8_t * temp;
    int retval;

    if(phy_address == 0x0)
    {
        LOG_ERROR("Physical address passed as NULL");
        return ERROR_FAIL;
    }
    if ((size % 4) == 0)
    {
        count = size/4;
        temp = buffer;
        for (i=0; i < count; i++)
        {
            // hexagon_memw_phys_read(target, phy_address+ 4*i, (uint64_t*) temp);
            retval = hexagon_memw_phys_read(target, phy_address+ 4*i, (uint32_t *) temp);
            if (retval != ERROR_OK){
                LOG_ERROR("%s failed", __func__);
                return retval;
            }
            temp = temp+4;
        }
    }
    else
    {
        LOG_DEBUG("size is not multiple of 4 bytes");
    }

    return ERROR_OK;
}


static int hexagon_read_syscfg_register(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval = ERROR_OK;
    uint32_t isdb_mmode_cmd;
    uint32_t syscfg_read_opcode = 0x6e92c007, mbxout_opcode = 0x6707c029;
    /*Stuff inst  {r7 = syscfg}  {isdbmbxout = r7} */

    hexagon_r7_used_stuff  = 1;
    //LOG_DEBUG("Enter in hexagon_read_syscfg_register");

    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF,ISDBCMD_MONITOR_LVL,
                            ISDBCMD_TNUM_MASK_THREAD(0));

    hexagon_isdb_cmd_status(target, syscfg_read_opcode, isdb_mmode_cmd);

    hexagon_isdb_cmd_status(target, mbxout_opcode,isdb_mmode_cmd);

    retval = hexagon_poll_mbxout(target);
    if (retval != ERROR_OK){
        LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
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

/* This function is used to write value in syscfg register */
static int hexagon_write_syscfg_register(struct target *target,uint32_t value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval,i;
    uint32_t isdb_mmode_cmd;
    uint32_t stuff_inst[] = {0x6ea8c007  ,0x6707c012,0x57c0c002,0xa840c000};
    /* Stuff instruction  0x6ea8c007-->{r7 = isdbmbxin } 0x6707c012-->{syscfg = r7} 0x57c0c002--> { isync }, 0xa840c000-->  { syncht } */

    hexagon_r7_used_stuff = 1;


    
    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
                                          ISDBCMD_TNUM_MASK_THREAD(0));

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);

    // ISDB MBXIN polling
    retval = hexagon_poll_mbxin(target);
    if (retval != ERROR_OK){
        LOG_DEBUG("ISDB MBX_IN not found to be full");
    }

    if (retval != ERROR_OK) 
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");

    for(i = 0;  i < 4;  i++){
        hexagon_isdb_cmd_status(target, stuff_inst[i],isdb_mmode_cmd);
    }

    return ERROR_OK;
}


static int hexagon_read_memory(struct target *target, target_addr_t address,
    uint32_t size, uint32_t count, uint8_t *buffer)
{
    int retval = ERROR_OK;
    LOG_DEBUG("address  = 0x%llx and size = %u,count=%u  ", address,size,count);
    return retval;
}


static int hexagon_write_memory(struct target *target, target_addr_t address,
    uint32_t size, uint32_t count, const uint8_t *buffer)
{
    int retval = ERROR_OK;
    
    LOG_DEBUG("address  = 0x%llx and size = %u,count=%u  ", address,size,count);
    

    return retval;
}


int hexagon_get_gdb_reg_list(struct target *target,
    struct reg **reg_list[], int *reg_list_size,
    enum target_register_class reg_class)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache, *global;
    
    int i, x;
    
    switch (reg_class) 
    {
        case REG_CLASS_GENERAL:
		{
			uint64_t hwthrd = hexa_info->thread_id_thread_select;

			/* walk to the currently-selected hw thread's cache (0-based) */
			cache = hexa_info->core_cache;
			for (i = 0; (i < hwthrd) && (cache->next != NULL); i++)
				cache = cache->next;

			*reg_list_size = HEXAGON_GPR_REGS + 1;    /* GPRs + PC, for the selected thread only */
			*reg_list = malloc(sizeof(struct reg *) * (*reg_list_size));
			memset(*reg_list, 0, sizeof(struct reg *) * (*reg_list_size));

			x = 0;
			for (i = 0; i < HEXAGON_GPR_REGS; i++)
				(*reg_list)[x++] = hexagon_reg_current(hexa_info, i, cache);

			(*reg_list)[x++] = hexagon_reg_current(hexa_info, HEXAGON_PC, cache);
		}
        return ERROR_OK;
        
        case REG_CLASS_ALL:     
        
                /** dump all registers of all HW thrd */
            *reg_list_size = (HEXAGON_VALID_PER_THREAD_REGS + HEXAGON_VALID_GLOBAL_REGS) 
                                                                    *hexa_info->config.maxHwThreads;
            *reg_list = malloc(sizeof(struct reg *) * (*reg_list_size));
            memset(*reg_list, 0, sizeof(struct reg *) * (*reg_list_size));
            LOG_DEBUG("reg_list_size  is 0x%x, number of threads =0x%x, regs per thread = 0x%x",*reg_list_size, hexa_info->config.maxHwThreads, (HEXAGON_VALID_PER_THREAD_REGS + HEXAGON_VALID_GLOBAL_REGS));
            // LOG_DEBUG("reg_list_size  is 0x%x",*reg_list_size);

        
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
                    if ((i == HEXAGON_S19_RESRV) || (i == HEXAGON_S24_RESRV) || 
                                                            (i == HEXAGON_S26_RESRV))
                        continue;
    
                    (*reg_list)[x++] = hexagon_reg_current(hexa_info, (i - HEXAGON_EVB), global);
                }
    
                cache = cache->next;
            }
            return ERROR_OK;
    
        default:
            LOG_DEBUG("not a valid register class type in query.");
            return ERROR_FAIL;
    }
}


const char *hexagon_get_gdb_arch(struct target *target)
{
    return  "hexagon";
}


static int hexagon_halt(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval = ERROR_OK;
    uint64_t prev_target_state, counter=0, sys_cfg;
    bool halted = false; 
    uint32_t debug_thread = 0;

    int64_t now, then = timeval_ms();
    LOG_DEBUG("hexagon_halt");
    
    if (hexagon->is_hexagon_untrusted == true){
        LOG_DEBUG("There is no need to halt Q6 to perform OEMPD Debug, skipping");
        return ERROR_OK;
    }

    retval = hexagon_check_state_one(target, ISDBST_DEBUG_MODE_STATUS, &halted, &debug_thread);
    if (halted == false)
    {
        retval = hexagon_init_debug_access(target);
        if (retval != ERROR_OK) {
            LOG_DEBUG("hexagon_init_debug_access API  failed");
            return retval;
        }
        prev_target_state = target->state;
        retval = hexagon_check_state_one(target, ISDBST_DEBUG_MODE_STATUS, &halted, &debug_thread);
        if (retval != ERROR_OK) {
            LOG_DEBUG("hexagon_check_state_one API    failed");
            return retval;
        }
        if(halted == true)
        {
            /* We have a halting debug event */
            target->state = TARGET_HALTED;

            hexagon_memory_map_refresh(target);
                    
            LOG_DEBUG("hexagon_halt  target->debug_reason =%d",target->debug_reason);

            hexagon_read_current_registers(target, hexa_info->config.maxHwThreads);
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
        LOG_DEBUG("hexagon_halt foor loop enter");
        if (counter > 20)
            break;
        retval = hexagon_check_state_one(target, ISDBST_DEBUG_MODE_STATUS, &halted, &debug_thread);
        if ((retval != ERROR_OK) || (halted == true))
            break; 
        //then += 50000;
        then += 1000;
        now = timeval_ms();
        if (now > then) {
            retval = ERROR_TARGET_TIMEOUT;
            LOG_DEBUG("target %s timeout in halt, then 0x%llx - now 0x%llx", target_name(target), then, now);
            break;
        }
        counter++;
    }
        /* need to enable this code part later */
    retval = hexagon_read_syscfg_register(target);
    if(retval == ERROR_OK)
    {
        sys_cfg = hexagon_syscfg_reg;
        sys_cfg = sys_cfg | SYSCFG_L2NRA | SYSCFG_L2NWA;
        sys_cfg = sys_cfg & ~(SYSCFG_L2WB);
        //LOG_DEBUG("Writing value in SYSCFG  = 0x%x ", sys_cfg);
        /* Kept commented since we need to find why uncommenting is leading to not reaching main.*/
        //hexagon_write_syscfg_register(target, sys_cfg);
    }

    hexagon_memory_map_refresh(target);

    return retval;
}


#ifdef  _HEXAGON_TARGET_TIME_PROFILING
void hexagon_start_time_cal_ms(void)
{
    hexagon_time_start = timeval_ms();
}


void hexagon_end_time_cal_ms(void)
{
    hexagon_time_total = timeval_ms() - hexagon_time_start;
}
#endif


int hexagon_read_tlb_entry(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    uint32_t read_val[1][2];
    int retval = ERROR_OK;
    uint32_t k=0;
    uint32_t isdb_mmode_cmd = HEXAGON_ISDB_MMODE_CMD;
    
    uint32_t stuff_inst[1][4] ={{0x7800c022,0x6c42c000,0x6700c029,0x6701c029}};
    /*stuff inst 0x7800c022-->{r2 = #1},0x6c42c000-->{r1:0 = tlbr(r2)},0x6700c029-->{isdbmbxout = r0},0x6701c029-->{isdbmbxout = r1 } */
                             
    if (qurt_context->tlb_fetched == true){
        LOG_DEBUG("TLB entries already fetched, skipping");
        return ERROR_OK;
    } 

    hexagon_r0_used_stuff = 1;
    hexagon_r1_used_stuff = 1;
    hexagon_r2_used_stuff = 1;
    
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
            hexagon_start_time_cal_ms();
    #endif
    
    for(k=0; k < hexa_info->config.numTlbEntries; k++){

        hexagon_isdb_cmd_status(target, stuff_inst[0][0] + k*0x20,isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            continue;
        }

        hexagon_isdb_cmd_status(target, stuff_inst[0][1],isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            continue;
        }
                
        hexagon_isdb_cmd_status(target, stuff_inst[0][2],isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            continue;
        }

        retval = hexagon_poll_mbxout(target);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
            continue;
        }
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &read_val[0][0]);
        if (retval != ERROR_OK) 
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", read_val[0][0]);
        }
                
        hexagon_isdb_cmd_status(target, stuff_inst[0][3],isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            continue;
        }
        
        retval = hexagon_poll_mbxout(target);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
            continue;
        }
    
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &read_val[0][1]);
        if (retval != ERROR_OK) 
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", read_val[0][1]);
        }
        hexagon_update_tlb_entry_in_structure(hexa_info, read_val[0][0], read_val[0][1] ,k);
    }

    for (k=0; k < hexa_info->config.numTlbEntries; k++)
    {
        LOG_DEBUG("VA raw = 0x%x --> PA raw  = 0x%x ", \
            hexa_info->config.pTlbEntries[k].virt_tlb_raw_data, hexa_info->config.pTlbEntries[k].phys_tlb_raw_data);

        LOG_DEBUG("VA = 0x%x -- 0x%x and PA = 0x%llx -- 0x%llx CCCC: %x", \
                 hexa_info->config.pTlbEntries[k].virt_add_low, hexa_info->config.pTlbEntries[k].virt_add_high, \
                 hexa_info->config.pTlbEntries[k].phy_add_low, hexa_info->config.pTlbEntries[k].phy_add_high, hexa_info->config.pTlbEntries[k].CCCC);
    }

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
            hexagon_end_time_cal_ms();
            LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    qurt_context->tlb_fetched = true;
    
    return ERROR_OK;
}


static unsigned int hexagon_getPhysAddr_v2(uint64_t pg_tlblo, uint64_t pg_tlbhi)
 {
    union pg_tlblo_t tlblo;
    union pg_tlbhi_t tlbhi;
    tlblo.raw = pg_tlblo;
    tlbhi.raw = pg_tlbhi;

    return ((hexagon_clrbit((unsigned int)tlblo.info.phys_addr + ((unsigned int)tlbhi.info.ep << 24),
                                 (unsigned int)(hexagon_ct0((unsigned int)tlblo.info.phys_addr & 0x7f))) >>
             1) &
            0xffffff);
}


static unsigned int hexagon_clrbit(unsigned int d, unsigned int bit)
{
    
    
     return (d & (~(1<<bit)));
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


/* this function is related to page table and get the mask from physical page */
unsigned int get_phys_mask(unsigned int tlblo)
{
    int i = 0;
    unsigned int mask = 0;

    
    for(i = 0; i <= 7; i++)
    {
        mask |= (0x01 << i);

        // first set bit defines mask and page size
        if(tlblo & (0x01 << i))
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

    
    if(hi & (0x01 << 29))
        pp |= 0x800000;

    // mask page size bits
    pp &= ~(mask >> 1);
    
    
    return pp;
}


/* this function update the tlb entry in global structure  hexagon_tlb_entries */
static void  hexagon_update_tlb_entry_in_structure(struct hexagon_arch_info *hexa_info, uint64_t tlb_phy, uint64_t tlb_virtual, uint64_t index)
{
    uint64_t mask, size = 0, virt_add = 0, phy_add = 0;
    char * page_size;
    static int i;
    union pg_tlblo_t tlblo;
    union pg_tlbhi_t tlbhi;


    if (index >= hexa_info->config.numTlbEntries)
    {
        LOG_DEBUG("Index is greater than HEXAGON_TLB_ENTRIES_NUM");
        return;
    }
    tlblo.raw = tlb_phy;
    tlbhi.raw = tlb_virtual;
    hexa_info->config.pTlbEntries[index].phy_page = hexagon_getPhysAddr_v2(tlb_phy, tlb_virtual);
    hexa_info->config.pTlbEntries[index].virt_page = VIRT_PAGE(tlb_virtual);
    virt_add = hexa_info->config.pTlbEntries[index].virt_page << 12;
    phy_add  = hexa_info->config.pTlbEntries[index].phy_page << 12;

    if ((virt_add == 0x0) || (phy_add == 0x0))
    {
        return;
    }
    if (!i)
    {
        LOG_DEBUG("size of  tlb_entries  = 0x%llx  ", sizeof(tlb_entries));
        i++;
    }
    mask = get_phys_mask(tlb_phy);
    hexa_info->config.pTlbEntries[index].virt_tlb_raw_data = tlb_virtual;
    hexa_info->config.pTlbEntries[index].phys_tlb_raw_data = tlb_phy;
    hexa_info->config.pTlbEntries[index].phy_page = hexagon_getPhysAddr_v2(tlblo.raw, tlbhi.raw );
    hexa_info->config.pTlbEntries[index].virt_page = VIRT_PAGE(tlb_virtual);
    
    hexa_info->config.pTlbEntries[index].asid = ASID(tlb_virtual);
    LOG_DEBUG("SID = 0x%x ", hexa_info->config.pTlbEntries[index].asid);

    hexa_info->config.pTlbEntries[index].asid = ASID(tlbhi.raw);
    LOG_DEBUG("SID = 0x%x ", hexa_info->config.pTlbEntries[index].asid);

    hexa_info->config.pTlbEntries[index].R = P_READ(tlb_phy);
    hexa_info->config.pTlbEntries[index].W = P_WRITE(tlb_phy);
    hexa_info->config.pTlbEntries[index].X= P_EXEC(tlb_phy);
    hexa_info->config.pTlbEntries[index].U = P_USER(tlb_phy);
    hexa_info->config.pTlbEntries[index].CCCC = P_CCCC(tlb_phy);
    hexa_info->config.pTlbEntries[index].S = P_S(tlb_phy);
    hexa_info->config.pTlbEntries[index].validbit = P_V(tlb_virtual);
    hexa_info->config.pTlbEntries[index].globalbit = P_G(tlb_virtual);
    hexa_info->config.pTlbEntries[index].EP = P_EP(tlb_virtual);
    hexa_info->config.pTlbEntries[index].A1 = P_A1(tlb_virtual);
    hexa_info->config.pTlbEntries[index].A0= P_A0(tlb_virtual);
    page_size = PAGE_SIZE(tlb_phy, mask);

    LOG_DEBUG("SID = 0x%x ", hexa_info->config.pTlbEntries[index].asid);
    LOG_DEBUG("virt_add = 0x%llx ", virt_add);
    LOG_DEBUG("phys_add = 0x%llx ", phy_add);
    if (strcmp(page_size, "4KB") == 0)
    {
        hexa_info->config.pTlbEntries[index].page_size =  HEXAGON_TLB_PAGE_SIZE_4KB;
        size = HEXAGON_PAGE_SIZE_4K - 1;
    }
    else if (strcmp(page_size, "16KB") == 0) 
    {
        hexa_info->config.pTlbEntries[index].page_size =  HEXAGON_TLB_PAGE_SIZE_16KB;
        size = HEXAGON_PAGE_SIZE_16K - 1;
    }
    else if (strcmp(page_size, "64KB") == 0) 
    {
        hexa_info->config.pTlbEntries[index].page_size =  HEXAGON_TLB_PAGE_SIZE_64KB;
        size = HEXAGON_PAGE_SIZE_64K - 1;
    }
    else if (strcmp(page_size, "256KB") == 0) 
    {
        hexa_info->config.pTlbEntries[index].page_size =  HEXAGON_TLB_PAGE_SIZE_256KB;
        size = HEXAGON_PAGE_SIZE_256K - 1;
    }
    else if (strcmp(page_size, "1MB") == 0) 
    {
        hexa_info->config.pTlbEntries[index].page_size =  HEXAGON_TLB_PAGE_SIZE_1MB;
        size = HEXAGON_PAGE_SIZE_1M - 1;
    }
    else if (strcmp(page_size, "4MB") == 0)
    {
        hexa_info->config.pTlbEntries[index].page_size =  HEXAGON_TLB_PAGE_SIZE_4MB;
        size = HEXAGON_PAGE_SIZE_4M - 1;
    }
    else if (strcmp(page_size, "16MB") == 0)
    {
        hexa_info->config.pTlbEntries[index].page_size =  HEXAGON_TLB_PAGE_SIZE_16MB;
        size = HEXAGON_PAGE_SIZE_16M - 1;
    }
    hexa_info->config.pTlbEntries[index].virt_add_low = hexa_info->config.pTlbEntries[index].virt_page << 12;
    hexa_info->config.pTlbEntries[index].virt_add_high = hexa_info->config.pTlbEntries[index].virt_add_low + size;
    
    hexa_info->config.pTlbEntries[index].phy_add_low = (uint64_t) hexa_info->config.pTlbEntries[index].phy_page << 12;
    hexa_info->config.pTlbEntries[index].phy_add_high = (uint64_t) (hexa_info->config.pTlbEntries[index].phy_add_low) + size;
    
    LOG_DEBUG("V bit =0x%x G bit = 0x%x ASID = 0x%x ",\
        hexa_info->config.pTlbEntries[index].validbit, hexa_info->config.pTlbEntries[index].globalbit, hexa_info->config.pTlbEntries[index].asid);

    LOG_DEBUG("VA = 0x%x -- 0x%x and PA = 0x%llx -- 0x%llx",\
        hexa_info->config.pTlbEntries[index].virt_add_low,hexa_info->config.pTlbEntries[index].virt_add_high,hexa_info->config.pTlbEntries[index].phy_add_low,hexa_info->config.pTlbEntries[index].phy_add_high);
}

static void hexagon_log_register(const char *thread_name, const char *reg_name, uint8_t *val, int bits)
{
    if (bits == 32)
    {
        LOG_DEBUG("%s : %s = 0x%08x", thread_name, reg_name, *(uint32_t *)val);
    }
    else if (bits == 64)
    {
        LOG_DEBUG("%s : %s = 0x%016llx", thread_name, reg_name, *(uint64_t *)val);
    }
    else if (bits == 128)
    {
        LOG_DEBUG("%s : %s = 0x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
                  thread_name, reg_name,
                  val[15], val[14], val[13], val[12],
                  val[11], val[10], val[9], val[8],
                  val[7], val[6], val[5], val[4],
                  val[3], val[2], val[1], val[0]);
    }
    else
    {
        LOG_DEBUG("%s : %s = [Unsupported width: %d bits]", thread_name, reg_name, bits);
    }
}

static int hexagon_dump_hwthrd_reg(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    struct reg_cache *cache, *global_cache = NULL;
    uint64_t i;
    const char *hw_thread_prefix = "HW-Thrd-";
    size_t prefix_len = sizeof("HW-Thrd-") - 1;

    /* 1) Query active thread bitmask once */
    int active_mask = get_active_threads(target); /* bit i set => thread i is active */

    /* 2) Iterate caches; remember GLOBAL node, skip inactive threads */
    cache = hexa_info->core_cache;
    while (cache != NULL) {
        /* Detect GLOBAL cache by name and remember it (stop per-thread loop) */
        if (strcmp(cache->name,
                   hexa_info->config.pThreadNameArray[hexa_info->config.maxHwThreads]) == 0) {
            global_cache = cache;
            break;
        }
        int thrd_idx = -1;

        /* Parse "HW-Thrd-<index>" robustly (supports index >= 10) */
        if (!strncmp(cache->name, hw_thread_prefix, prefix_len)) {
            thrd_idx = atoi(cache->name + prefix_len);  // robust for multi-digit indices
        }

        /* Skip if we have a valid thread index and it's inactive */
        if (thrd_idx >= 0) {
            if ((active_mask & (1 << thrd_idx)) == 0) {
                cache = cache->next;
                continue; /* inactive -> do not log its registers */
            }
        }

        /* Dump registers for this active thread */
        for (i = 0; i < HEXAGON_PER_THREAD_REGS; i++) {
            hexagon_log_register(cache->name,
                                 cache->reg_list[i].name,
                                 cache->reg_list[i].value,
                                 cache->reg_list[i].size);
        }

        cache = cache->next;
    }

    /* 3) Dump GLOBAL registers safely */
    if (global_cache != NULL) {
        for (i = 0; i < HEXAGON_GLOBAL_REGS; i++) {
            hexagon_log_register(global_cache->name,
                                 global_cache->reg_list[i].name,
                                 global_cache->reg_list[i].value,
                                 global_cache->reg_list[i].size);
        }
    }else{
        LOG_WARNING("GLOBAL reg_cache not found; skipping global register dump");
    }

    LOG_DEBUG("exiting hexagon_dump_hwthrd_reg");
    return ERROR_OK;
}

void print_active_threads(struct target *target){
    uint32_t active_threads;

    active_threads = get_active_threads(target);
    LOG_DEBUG("Active threads =  0x%x", active_threads);

}

int get_active_threads(struct target *target){
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdbst, active_threads;
    int retval;

    if (hexa_info->isdbver == HEXAGON_V81){

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_ISDBST1, &isdbst);

        if (retval != ERROR_OK) 
        {
            LOG_ERROR("HEXAGON_ISDB_ISDBST read failed 0x%x", isdbst);
            return ERROR_OK;
        }

        active_threads = isdbst & ISDBST1_OFF_MODE_STATUS;
    }
    else{
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbst);

        if (retval != ERROR_OK) 
        {
            LOG_ERROR("HEXAGON_ISDB_ISDBST read failed 0x%x", isdbst);
            return ERROR_OK;
        }
        active_threads = (isdbst & ISDBST_OFF_MODE_STATUS) >> ISDBST_OFF_MODE_STATUS_SHIFT;
    }

    return active_threads;
}

void print_debug_threads(struct target *target){
    uint32_t debug_threads;

    debug_threads = get_debug_threads(target);
    LOG_DEBUG("Debug threads =  0x%x", debug_threads);

}

int get_debug_threads(struct target *target){
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdbst, debug_threads;
    int retval;
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbst);

    if (retval != ERROR_OK) 
    {
        LOG_ERROR("HEXAGON_ISDB_ISDBST read failed 0x%x", isdbst);
        return ERROR_OK;
    }

    debug_threads = (isdbst & ISDBST_DEBUG_MODE_STATUS) >> ISDBST_DEBUG_MODE_STATUS_SHIFT;
    return debug_threads;
}

void print_wait_run_threads(struct target *target){
    uint32_t wait_run_threads;

    wait_run_threads = get_wait_run_threads(target);
    LOG_DEBUG("Wait_Run threads =  0x%x", wait_run_threads);

}

int get_wait_run_threads(struct target *target){
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdbst, wait_run_threads;
    int retval;
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbst);

    if (retval != ERROR_OK) 
    {
        LOG_ERROR("HEXAGON_ISDB_ISDBST read failed 0x%x", isdbst);
        return ERROR_OK;
    }

    wait_run_threads = (isdbst & ISDBST_WAITRUN_MODE_STATUS) >> ISDBST_WAITRUN_MODE_STATUS_SHIFT;
    return wait_run_threads;
}

int hexagon_read_gpr_for_hwthrd(struct target *target, uint32_t hwthrd_mask)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval, reg;
    uint32_t hwthrd, maxhwt, isdb_mmode_cmd;

    cache = hexa_info->core_cache;
    maxhwt = hexa_info->config.maxHwThreads;

    /* restore GPR register for specific Hw thread */
    for ( hwthrd = 0; hwthrd < maxhwt; hwthrd++, cache = cache->next){
        if (hwthrd_mask & (1<<hwthrd)){

            isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF,ISDBCMD_MONITOR_LVL,
                                                        ISDBCMD_TNUM_MASK_THREAD(hwthrd));
            for(reg = 0; reg < HEXAGON_GPR_REGS; reg++){
                retval = hexagon_isdb_cmd_status(target, stuff_inst_gpr_read[reg],isdb_mmode_cmd);
                if (retval != ERROR_OK){
                    LOG_ERROR("ISDBcommand failed in user mode; retval =  %d", retval);
                    return retval;
                }
                retval = hexagon_poll_mbxout(target);
                if (retval != ERROR_OK){
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
                    cache->reg_list[reg].valid = false;
                    continue;
                }
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &(hexa_info->pPerHwThrdReg[hwthrd][reg]));
                if (retval != ERROR_OK) {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hexa_info->pPerHwThrdReg[hwthrd][reg]);
                    return retval;
                }
                // Cast to uint8_t * to match the type of cache->reg_list[j].value 
                cache->reg_list[reg].value = (uint8_t *) &hexa_info->pPerHwThrdReg[hwthrd][reg];
                cache->reg_list[reg].valid = true;

                #ifdef  _DEBUG_HEXAGON_
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
                LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, hwthrd, reg);
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", hexa_info->pPerHwThrdReg[hwthrd][reg]);
                #endif
            }
        }
    }

    return ERROR_OK;
}

/** Read registers of the the current context **/
int hexagon_read_gpr_registers(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval, maxhwt, hwt, reg;
    uint32_t active_threads;
    uint32_t isdb_mmode_cmd;
    
    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_gpr_registers entry - hw thrd: %d", hwthrd);
    #endif
    
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
    #endif

    active_threads = get_active_threads(target);

    cache = hexa_info->core_cache;
    maxhwt = hexa_info->config.maxHwThreads;
    
    /* Get registers per Hw thread */
    for(hwt = 0; (hwt < maxhwt) && (cache != NULL); hwt++, cache= cache->next){

        if((1<<hwt) & active_threads){  // if the thread is on, then only read its local registers

            isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF,ISDBCMD_MONITOR_LVL,
                                                        ISDBCMD_TNUM_MASK_THREAD(hwt));

            for(reg = 0; reg < HEXAGON_GPR_REGS; reg++){
                retval = hexagon_isdb_cmd_status(target, stuff_inst_gpr_read[reg],isdb_mmode_cmd);
                if (retval != ERROR_OK){
                    LOG_ERROR("ISDBcommand failed in user mode; retval =  %d", retval);
                    return ERROR_OK;
                }

                retval = hexagon_poll_mbxout(target);
                if (retval != ERROR_OK){
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
                    cache->reg_list[reg].valid = false;
                    continue;
                }
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &(hexa_info->pPerHwThrdReg[hwt][reg]));
                if (retval != ERROR_OK) {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hexa_info->pPerHwThrdReg[hwt][reg]);
                }

                // Cast to uint8_t * to match the type of cache->reg_list[j].value 
                cache->reg_list[reg].value = (uint8_t *) &hexa_info->pPerHwThrdReg[hwt][reg];
                cache->reg_list[reg].valid = true;

                #ifdef  _DEBUG_HEXAGON_
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
                LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", hexa_info->pPerHwThrdReg[x][j]);
                #endif
                }
            }
        }

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    #ifdef  _DEBUG_HEXAGON_
            LOG_DEBUG("hexagon_read_gpr_registers exit - hw thrd: %d", hwthrd);
    #endif

    
    return ERROR_OK;
}


/**
 * @brief Read Hexagon control registers for the hardware thread(s) selected.
 *
 * This function refreshes all valid Hexagon control registers (SA0–CTRL_MAX,
 * excluding reserved registers such as C5 and C20–C29) for each hardware thread
 * whose bit is set in `hwthrd_mask`.
 *
 * It is typically used after a single-step operation to restore only the control
 * registers of the stepped thread, instead of reading all threads' registers.
 *
 *
 * The function:
 *  - Packs an ISDB STUFF command for each selected hardware thread
 *  - Executes the appropriate STUFF instruction sequence to read each control register
 *  - Polls mailbox-out for read completion
 *  - Updates the per-thread register cache (`reg_list[reg]`)
 *
 * @param target        Pointer to the OpenOCD target instance.
 * @param hwthrd_mask   Bitmask specifying which hardware thread(s) to read.
 *                      (bit N set ⇒ read registers for thread N)
 *
 * @return ERROR_OK on success; ERROR_FAIL if any ISDB command fails.
 */

int hexagon_read_ctrl_regs_for_hwthrd(struct target *target, uint32_t hwthrd_mask)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval, reg;
    uint32_t isdb_mmode_cmd, maxhwt, hwthrd;

    cache = hexa_info->core_cache;
    maxhwt = hexa_info->config.maxHwThreads;

    /* restore ctrl registers for specific Hw thread */
    for(hwthrd = 0; hwthrd < maxhwt; hwthrd++, cache = cache->next){

        if (hwthrd_mask & (1<<hwthrd)){

            /* pack the ISDB command for the relevant Hw thread */
            isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF,ISDBCMD_MONITOR_LVL,
                                                        ISDBCMD_TNUM_MASK_THREAD(hwthrd));

            /* Mark r7 as dirty as it is being used for stuff instruction */
            cache->reg_list[HEXAGON_R7].dirty = true;

            for(reg = HEXAGON_SA0; reg < HEXAGON_CTRL_MAX; reg++){
                if ((reg == HEXAGON_C5_RESRV) || (reg >= HEXAGON_C20_RESRV && reg <= HEXAGON_C29_RESRV)){
                    continue;
                }

                retval = hexagon_isdb_cmd_status(target, stuff_inst_ctrl_reg_read[reg-HEXAGON_SA0][0],isdb_mmode_cmd);
                if (retval != ERROR_OK){
                    LOG_ERROR("ISDBcommand failed for instruction: 0x%x; retval =  %d", stuff_inst_ctrl_reg_read[reg-HEXAGON_SA0][0], retval);
                    return retval;
                }
                retval = hexagon_isdb_cmd_status(target, stuff_inst_ctrl_reg_read[reg-HEXAGON_SA0][1],isdb_mmode_cmd);
                if (retval != ERROR_OK){
                    LOG_ERROR("ISDBcommand failed for instruction: 0x%x; retval =  %d", stuff_inst_ctrl_reg_read[reg-HEXAGON_SA0][1], retval);
                    return retval;
                }

                retval = hexagon_poll_mbxout(target);
                if (retval != ERROR_OK){
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
                    cache->reg_list[reg].valid = false;
                    continue;
                }
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &(hexa_info->pPerHwThrdReg[hwthrd][reg]));
                if (retval != ERROR_OK) {
                    LOG_ERROR("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hexa_info->pPerHwThrdReg[hwthrd][reg]);
                    return retval;
                }

                // Cast to uint8_t * to match the type of cache->reg_list[j].value 
                cache->reg_list[reg].value = (uint8_t *) &hexa_info->pPerHwThrdReg[hwthrd][reg];
                cache->reg_list[reg].valid = true;


                #ifdef  _DEBUG_HEXAGON_
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
                LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", hexagon->pPerHwThrdReg[x][j]);
                #endif
            }
        }
    }

    return ERROR_OK;

}

/** Read registers of the the current context **/
int hexagon_read_ctrl_registers(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval;
    uint32_t isdb_mmode_cmd, active_threads, maxhwt, hwt, reg;

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_ctrl_registers entry - hw thrd: %d", hwthrd);
    #endif

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
    #endif

    active_threads = get_active_threads(target);

    cache = hexa_info->core_cache;
    maxhwt = hexa_info->config.maxHwThreads;

    /* Get per Hw thread control registers */
    for(hwt = 0; (hwt < maxhwt) && (cache != NULL); hwt++, cache = cache->next){

        if((1<<hwt) & active_threads){  // if the thread is on, then only read its local registers

            /* pack the ISDB command for the relevant Hw thread */
            isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF,ISDBCMD_MONITOR_LVL,
                                                        ISDBCMD_TNUM_MASK_THREAD(hwt));

            /* Mark r7 as dirty as it is being used for stuff instruction */
            cache->reg_list[HEXAGON_R7].dirty = true;

            for(reg = HEXAGON_SA0; reg < HEXAGON_CTRL_MAX; reg++){
                if ((reg == HEXAGON_C5_RESRV) || (reg >= HEXAGON_C20_RESRV && reg <= HEXAGON_C29_RESRV)){
                    continue;
                }

                retval = hexagon_isdb_cmd_status(target, stuff_inst_ctrl_reg_read[reg-HEXAGON_SA0][0],isdb_mmode_cmd);
                if (retval != ERROR_OK){
                    LOG_ERROR("ISDBcommand failed for instruction: 0x%x; retval =  %d", stuff_inst_ctrl_reg_read[reg-HEXAGON_SA0][0], retval);
                    return ERROR_OK;
                }
                retval = hexagon_isdb_cmd_status(target, stuff_inst_ctrl_reg_read[reg-HEXAGON_SA0][1],isdb_mmode_cmd);
                if (retval != ERROR_OK){
                    LOG_ERROR("ISDBcommand failed for instruction: 0x%x; retval =  %d", stuff_inst_ctrl_reg_read[reg-HEXAGON_SA0][1], retval);
                    return ERROR_OK;
                }

                retval = hexagon_poll_mbxout(target);
                if (retval != ERROR_OK){
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
                    cache->reg_list[reg].valid = false;
                    continue;
                }
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &(hexa_info->pPerHwThrdReg[hwt][reg]));
                if (retval != ERROR_OK) {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hexa_info->pPerHwThrdReg[hwt][reg]);
                }

                // Cast to uint8_t * to match the type of cache->reg_list[j].value 
                cache->reg_list[reg].value = (uint8_t *) &hexa_info->pPerHwThrdReg[hwt][reg];
                cache->reg_list[reg].valid = true;


                #ifdef  _DEBUG_HEXAGON_
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
                LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", hexagon->pPerHwThrdReg[x][j]);
                #endif
            }

        }
    }

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif
    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_ctrl_registers exit - hw thrd: %d", hwthrd);
    #endif

    return ERROR_OK;
        
}


int hexagon_read_mmode_registers(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common    *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval;
    uint32_t isdb_mmode_cmd, active_threads, maxhwt, hwt, reg;

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_mmode_registers entry - hw thrd: %d", hwthrd);
    #endif

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
    #endif

    active_threads = get_active_threads(target);

    cache = hexa_info->core_cache;
    maxhwt = hexa_info->config.maxHwThreads;

    /* Get per Hw thread control registers */
    for(hwt = 0; (hwt < maxhwt) && (cache != NULL); hwt++, cache = cache->next){

        if((1<<hwt) & active_threads){  // if the thread is on, then only read its local registers

            /* pack the ISDB command for the relevant Hw thread */
            isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF,ISDBCMD_MONITOR_LVL,
                                                        ISDBCMD_TNUM_MASK_THREAD(hwt));
            
            /* Mark r7 as dirty as it is being used for stuff instruction */
            cache->reg_list[HEXAGON_R7].dirty = true;

            for(reg = HEXAGON_SGP0; reg < HEXAGON_MMODE_PERTHRD_MAX; reg++){
                if (reg >= HEXAGON_S12_RESRV && reg <= HEXAGON_S15_RESRV){
                    continue;
                }

                retval = hexagon_isdb_cmd_status(target, stuff_inst_mmode_reg_read[reg-HEXAGON_SGP0][0],isdb_mmode_cmd);
                if (retval != ERROR_OK){
                    LOG_ERROR("ISDBcommand failed for instruction: 0x%x; retval =  %d", stuff_inst_mmode_reg_read[reg-HEXAGON_SGP0][0], retval);
                    return ERROR_OK;
                }
                retval = hexagon_isdb_cmd_status(target, stuff_inst_mmode_reg_read[reg-HEXAGON_SGP0][1],isdb_mmode_cmd);
                if (retval != ERROR_OK){
                    LOG_ERROR("ISDBcommand failed for instruction: 0x%x; retval =  %d", stuff_inst_mmode_reg_read[reg-HEXAGON_SGP0][1], retval);
                    return ERROR_OK;
                }

                retval = hexagon_poll_mbxout(target);
                if (retval != ERROR_OK){
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
                    cache->reg_list[reg].valid = false;
                    continue;
                }
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &(hexa_info->pPerHwThrdReg[hwt][reg]));
                if (retval != ERROR_OK) {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hexa_info->pPerHwThrdReg[hwt][reg]);
                }

                // Cast to uint8_t * to match the type of cache->reg_list[j].value 
                cache->reg_list[reg].value = (uint8_t *) &hexa_info->pPerHwThrdReg[hwt][reg];
                cache->reg_list[reg].valid = true;
                        
                #ifdef  _DEBUG_HEXAGON_
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
                LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, x, j);
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", hexa_info->pPerHwThrdReg[x][j]);
                #endif
            }
        }
    }

    hexagon_read_imask_register(target, hwthrd);
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_mmode_registers exit - hw thrd: %d", hwthrd);
    #endif

    
    return ERROR_OK;
}


int hexagon_read_imask_register(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval;
    uint32_t isdb_mmode_cmd, active_threads, maxhwt, hwt;

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_imask_register entry - hw thrd: %d", hwthrd);
    #endif

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
    #endif

    active_threads = get_active_threads(target);    
    
    cache = hexa_info->core_cache;
    maxhwt = hexa_info->config.maxHwThreads;

    /* Get per Hw thread control registers */
    for(hwt = 0; (hwt < maxhwt) && (cache != NULL); hwt++, cache = cache->next){

        if((1<<hwt) & active_threads){  // if the thread is on, then only read its local registers

            isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF,ISDBCMD_MONITOR_LVL,
                                                        ISDBCMD_TNUM_MASK_THREAD(hwt));           

            retval = hexagon_isdb_cmd_status(target, stuff_inst_mmode_imask_reg_read[hwt][0],isdb_mmode_cmd);
            if (retval != ERROR_OK){
                LOG_ERROR("ISDBcommand failed in Monitor mode; retval =  %d", retval);
                return retval;
            }
            retval = hexagon_isdb_cmd_status(target, stuff_inst_mmode_imask_reg_read[hwt][1],isdb_mmode_cmd);
            if (retval != ERROR_OK){
                LOG_ERROR("ISDBcommand failed  in Monitor mode; retval =  %d", retval);
                return retval;
            }
            retval = hexagon_isdb_cmd_status(target, stuff_inst_mmode_imask_reg_read[hwt][2],isdb_mmode_cmd);
            if (retval != ERROR_OK){
                LOG_ERROR("ISDBcommand failed in Monitor mode; retval =  %d", retval);
                return retval;
            }

            retval = hexagon_poll_mbxout(target);
            if (retval != ERROR_OK){
                LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it");
                continue;
            }
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &(hexa_info->pPerHwThrdReg[hwt][HEXAGON_IMASK]));
            if (retval != ERROR_OK) {
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hexa_info->pPerHwThrdReg[hwt][HEXAGON_IMASK]);
            }

            // Cast to uint8_t * to match the type of cache->reg_list[HEXAGON_IMASK].value 
            cache->reg_list[HEXAGON_IMASK].value = (uint8_t *) &hexa_info->pPerHwThrdReg[hwt][HEXAGON_IMASK];
                    

            #ifdef  _DEBUG_HEXAGON_
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
            LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x, thrd = %d, reg = %d", isdbsts, k, HEXAGON_IMASK);
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", gpPerHwThrdReg[k][HEXAGON_IMASK]);
            #endif
        }
    }

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_imask_register exit - hw thrd: %d", hwthrd);
    #endif
    
    return ERROR_OK;    
}

/** Read registers of the the current context **/
int hexagon_read_global_ctrl_registers(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval ,j, x;
    uint32_t isdb_mmode_cmd;

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_global_ctrl_registers  entry");
    #endif

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
    #endif

    /* global */
    cache = hexa_info->core_cache;
    while ((cache->next != NULL))
    {
        cache = cache->next;
    }

    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
                                                ISDBCMD_TNUM_MASK_THREAD(0));
    #ifdef  _DEBUG_HEXAGON_
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

        retval = hexagon_isdb_cmd_status(target, stuff_inst_global_reg_read[j][0],isdb_mmode_cmd);

        if (retval != ERROR_OK)
        {
             LOG_DEBUG("ISDBcommand failed in Monitor mode");
             return ERROR_OK;
        }
        else
        {
            retval = hexagon_isdb_cmd_status(target, stuff_inst_global_reg_read[j][1],isdb_mmode_cmd);

            if (retval != ERROR_OK)
            {
                 LOG_DEBUG("ISDB command failed in monitor mode");
                 return ERROR_OK;
            }
            else
            {            
                retval = hexagon_poll_mbxout(target);
                if (retval != ERROR_OK){
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", x);
                    continue;
                }

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &global_reg[j]);
                if (retval != ERROR_OK) 
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", global_reg[j]);
                }

                // Cast to uint8_t * to match the type of cache->reg_list[j].value 
                cache->reg_list[j].value = (uint8_t *) &global_reg[j];
                cache->reg_list[j].valid = true;
                    

                #ifdef  _DEBUG_HEXAGON_
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
                LOG_DEBUG("ISDBST status after reading MBXOUT = 0x%x,  reg = %d", isdbsts, x);
                LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", global_reg[j]);
                #endif
            }
        }
    }

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_global_ctrl_registers  exit");
    #endif
    return ERROR_OK;    
}


int hexagon_write_hvx_registers(struct target *target, uint32_t value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval, j = 0;
    uint32_t isdb_mmode_cmd;
    uint64_t opcode = 0x19a0e020;

#ifdef _HEXAGON_TARGET_TIME_PROFILING
    hexagon_start_time_cal_ms();
#endif
    


    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
                                               ISDBCMD_TNUM_MASK_THREAD(0));

    for (j = 0; j < 32; j++)
    {
    #ifdef _DEBUG_HEXAGON_
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
        if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
        LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
    #endif
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                         hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, 0x9);
        if (retval != ERROR_OK)
            LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

        retval = hexagon_isdb_cmd_status(target, 0x6ea8c000,isdb_mmode_cmd);

        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDB command failed in monitor mode");
            return ERROR_OK;
        }

        retval = hexagon_isdb_cmd_status(target,  opcode + j,isdb_mmode_cmd);

        if (retval != ERROR_OK)
        {

            LOG_DEBUG("ISDB command failed in monitor  mode");
        }
    }
#ifdef _HEXAGON_TARGET_TIME_PROFILING
    hexagon_end_time_cal_ms();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

    return ERROR_OK;
}


int hexagon_read_hvx_registers(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval, i, j;
    uint32_t isdb_mmode_cmd;
    uint64_t vextract_opcode_v0 = 0x9200c021;
    hexagon_r0_used_stuff = 1;
    hexagon_r1_used_stuff = 1;
    LOG_DEBUG("hexagon_read_hvx_registers  entry");
#ifdef _HEXAGON_TARGET_TIME_PROFILING
    hexagon_start_time_cal_ms();
#endif
    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
                                               ISDBCMD_TNUM_MASK_THREAD(0));
#ifdef _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_hvx_registers   isdb_mmode_cmd = %d ", isdb_mmode_cmd);
#endif
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 16; j++)
        {
            hexa_info->hvx_register[i][j] = 32670;
        }
    }
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 16; j++)
        {
            retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                             hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, j * 4);
            if (retval != ERROR_OK)
                LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");

            retval = hexagon_isdb_cmd_status(target, 0x6ea8c000,isdb_mmode_cmd);

            if (retval != ERROR_OK){
                LOG_DEBUG("ISDB command failed in monitor mode");
            }
            
            retval = hexagon_isdb_cmd_status(target, vextract_opcode_v0 + 100 * i,isdb_mmode_cmd);
            if (retval != ERROR_OK){
                LOG_DEBUG("ISDB command failed in monitor mode");
            }

            retval = hexagon_isdb_cmd_status(target, 0x6701c029,isdb_mmode_cmd);
            if (retval != ERROR_OK){
                LOG_DEBUG("ISDB command failed in monitor mode");
                return ERROR_OK;
            }
            else
            {

                retval = hexagon_poll_mbxout(target);
                if (retval != ERROR_OK){
                    LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
                    continue;
                }
                
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                                hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &hexa_info->hvx_register[i][j]);
                if (retval != ERROR_OK)
                {
                    LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", hexa_info->hvx_register[i][j]);
                }
            }
        }
    }
#ifdef _HEXAGON_TARGET_TIME_PROFILING
    hexagon_end_time_cal_ms();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif
    LOG_DEBUG("******Printing HVX registers*****");
    for (i = 0; i < 32; i++)
    {
        for (j = 0; j < 16; j++)
        {
            LOG_DEBUG("hvx_register[%d][%d]  =  0x%x", i, j, hexa_info->hvx_register[i][j]);
        }
    }
#ifdef _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_read_hvx_registers  exit");
#endif
    return ERROR_OK;
}


int hexagon_read_current_registers(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

    /* read general purpose registers (R0-R1) */
    hexagon_read_gpr_registers(target, hwthrd);

    /* read per thread control registers */
    hexagon_read_ctrl_registers(target, hwthrd);

    /* read per thread monitor mode control registers */
    hexagon_read_mmode_registers(target, hwthrd);

    /* read global control registers */
    hexagon_read_global_ctrl_registers(target);

    LOG_DEBUG("Dumping Registers %s", target_name(target));
    hexagon_dump_hwthrd_reg(target);

    bool mmu_enabled = hexagon_is_mmu_enabled(target);

    if (mmu_enabled == true && qurt_context->tlb_fetched == false)
        hexagon_read_tlb_entry(target);
#ifdef HEXAGON_DEBUG_LOGS
    else
        LOG_DEBUG("TLB entries already fetched, skipping");
#endif
    hexagon_stuff_reg_restore(target);
    
    return ERROR_OK;
}


static uint32_t hexagon_print_pc(struct target *target, uint32_t hw_thread)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    uint32_t i, pc;


    if (hw_thread >= hexa_info->config.maxHwThreads) {
        LOG_DEBUG("Invalid HW thread %u", hw_thread+1);
        return 0;
    }

    /* Walk to the requested HW thread */
    cache = hexa_info->core_cache;
    for (i = 0; i < hw_thread; i++) {
        cache = cache->next;
    }

    pc = *(uint32_t *)(cache->reg_list[HEXAGON_PC].value);

    LOG_DEBUG("PC for HW thread %u (%s:%s) = 0x%x",
              hw_thread, cache->name, cache->reg_list[HEXAGON_PC].name,
              pc);
    return pc;
}


void current_debug_thread (struct target *target, uint32_t selected_thread)
{ 
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    //comes as input from gdb_server with +1
    // debug_thread_id = selected_thread - 1;
    hexa_info->thread_id_thread_select = selected_thread - 1;
    return;
}


static int hexagon_step(struct target *target, int current, target_addr_t address,
            int handle_breakpoints)
{

#ifdef HEXAGON_DEBUG_LOGS
    start = clock();
#endif
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval = ERROR_OK;
    uint32_t isdbcmd;
    uint32_t isdbsts = 0;
    uint32_t thread_mask = 0, hwthrd_mask = 0;

#ifdef HEXAGON_DEBUG_LOGS
    LOG_INFO("Inside Step function");
#endif
    retval = isdbcmd = isdbsts = 0;

    if (target->state != TARGET_HALTED)
    {
        LOG_DEBUG("Step is requested when target is not halted, polling again");
        hexagon_poll(target);
        if (target->state != TARGET_HALTED)
            return ERROR_TARGET_NOT_HALTED;
    }
#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif
    hexagon_stuff_reg_restore(target);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_stuff_reg_restore:  %lf", func_time);
#endif

#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif

    thread_mask |= ISDBCMD_MONITOR_LVL;
    thread_mask |= ISDBCMD_TNUM_MASK_THREAD(hexa_info->thread_id_thread_select);    
    hwthrd_mask = thread_mask >> ISDBCMD_TNUM_SHIFT;
    LOG_DEBUG("hwthrd_mask : 0X%X", hwthrd_mask);

    isdbcmd = ISDBCMD_CMD_ISTEP | thread_mask;
    LOG_DEBUG("isdbcmd : 0X%X", isdbcmd);

    retval = hexagon_isdb_cmd_status(target, 0, isdbcmd);

    if (retval != ERROR_OK){
         LOG_DEBUG("ISDB command failed returning from hexagon_step function ");
         return ERROR_FAIL;
    }
    
#ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif
    
    target->debug_reason = DBG_REASON_SINGLESTEP;
    
    //hexagon_read_current_registers(target, HEXAGON_HW_THREAD0);
#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif    
    /* read general purpose registers (R0-R1) */
    hexagon_read_gpr_for_hwthrd(target, hwthrd_mask);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_read_gpr_registers:  %lf", func_time);
#endif
    
#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif     
    /* Refresh ctrl regs for only the stepped hardware thread to ensure accurate post-step state. */
    hexagon_read_ctrl_regs_for_hwthrd(target, hwthrd_mask);
    
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_read_ctrl_registers:  %lf", func_time);
#endif
    
#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif         
    /* read per thread monitor mode control registers */
    // hexagon_read_mmode_registers(target, gHexConfig.maxHwThreads);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_read_mmode_registers:  %lf", func_time);
#endif

#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif       
    /* read global control registers */
    // hexagon_read_global_ctrl_registers(target);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_read_global_ctrl_registers:  %lf", func_time);
#endif

    /* Restore the register used stuff instruction */
#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif        
    hexagon_stuff_reg_restore(target);
#ifdef HEXAGON_DEBUG_LOGS
    func_end = clock();
    func_time = ((double)(func_end - func_start))/CLOCKS_PER_SEC;
    LOG_INFO("hexagon_stuff_reg_restore:  %lf", func_time);
// #endif

    double before_vtlb;
    end = clock();
    before_vtlb = ((double)(end - start))/CLOCKS_PER_SEC;
    LOG_INFO("before_vtlb:  %lf", before_vtlb);
#endif

#ifdef HEXAGON_DEBUG_LOGS
    func_start = clock();
#endif       

    hexagon_memory_map_refresh(target);

    sbp_step_executed = 1;

    return ERROR_OK;
}

static int hexagon_update_modified_vtlb_entry(struct target *target)
{
    int retval;
    // uint64_t output;
    uint32_t output;
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

    unsigned int vtlb_entry_count = hexagon_vtlb_data.vtlb_no_of_entries;
    uint64_t vtlb_entries_read[vtlb_entry_count];
    unsigned int vtlb_notify_size;
    vtlb_notify_size = (vtlb_entry_count % 32)? ((vtlb_entry_count/32) +1) :  (vtlb_entry_count/32);
    unsigned int bitmap_array_contents[vtlb_notify_size];
    unsigned int size_vtlb_binary = (vtlb_entry_count*4);
    // target_addr_t bitmap_addr_temp ;
    uint32_t bitmap_addr_temp;
    // target_addr_t vtlb_entries_temp;
    uint32_t vtlb_entries_temp;

    unsigned int* final_str = (unsigned int *) calloc(size_vtlb_binary, sizeof(unsigned int));
    unsigned int final_str_ind = 0;

    hexagon_memw_read(target, qurt_context->bitmap_addr, &bitmap_addr_temp);
    for (unsigned int i = 0; i < vtlb_notify_size; i++)
    {   
        hexagon_memw_read(target, bitmap_addr_temp, &output);
        bitmap_array_contents[i] = output;
        bitmap_addr_temp = bitmap_addr_temp + 4;
    } 
#ifdef HEXAGON_DEBUG_LOGS
    LOG_INFO("size of bitmap : %d",sizeof(bitmap_array_contents) / sizeof(bitmap_array_contents[0]));
#endif   
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
    hexagon_memw_read(target, qurt_context->qurtk_vtlb_entries, &vtlb_entries_temp);
    for(unsigned int i = 0; i < size_vtlb_binary; i++)
    {
        if (final_str[i]!=0)
        {   
            if (i < vtlb_entry_count)
            {
                hexagon_memw_read(target, vtlb_entries_temp, &output);
                vtlb_entries_read[i] = output;
                vtlb_entries_temp = vtlb_entries_temp + 4; 
                hexagon_memw_read(target, vtlb_entries_temp, &output);
                vtlb_entries_read[i+1] = output;
                vtlb_entries_temp = vtlb_entries_temp + 4;
            }
            if (i < (sizeof(vtlb_entries_read) / sizeof(vtlb_entries_read[0])))
            {
                hexagon_update_vtlb_entry_in_structure(vtlb_entries_read[i],vtlb_entries_read[i+1],i);
            }
        }
        else
        {
                vtlb_entries_temp = vtlb_entries_temp + 8; 
        }
        i++;
    }
    free(final_str);
    qurt_context->bitmap_addr = qurt_context->qurtk_vtlb_bitmap;
    hexagon_memw_read(target, qurt_context->bitmap_addr, &bitmap_addr_temp);
    for (unsigned int i = 0; i < hexagon_vtlb_data.vtlb_no_of_entries/32; i++)
    {   
        retval = hexagon_memw_write(target, bitmap_addr_temp, 0x0 , 4);
        if (retval != ERROR_OK)
            LOG_DEBUG("bitmap write failed");
        bitmap_addr_temp = bitmap_addr_temp + 4;
    }

    return ERROR_OK;
}


#if 0
static int hexagon_dump_isdb_reg(struct hexagon_arch_info *hexa_info)
{
    uint32_t reg_value;
    int retval = ERROR_OK, i;

    /* dump the all registers */ 
    for (i = 0; i < HEXAGON_MAX_ISDB_REG; i++)
    {
        reg_value = 0;
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + (i*4), &reg_value);

        if (retval != ERROR_OK)
        {
            LOG_DEBUG("ISDB reg(addr: 0x%x) read failed", (i*4));
            return retval;
        }    
        #ifdef  _DEBUG_HEXAGON_
        LOG_DEBUG("ISDB reg dump: ISDB reg(addr: 0x%x) -> 0x%x", reg_value);
        #endif
    }

    return retval;
}
#endif


/* Resume execution of the Hexagon target using ISDB */
static int hexagon_resume(struct target *target, int current, target_addr_t address,
    int handle_breakpoints, int debug_execution)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    uint32_t isdbcmd, isdbsts, thread_mask;
    int retval = ERROR_OK;

    LOG_DEBUG("Entering, Params passed: current=%d address=0x%llx handle_breakpoints=%d debug_execution=%d", 
              current, address, handle_breakpoints, debug_execution);

    /* Log breakpoint registers (informational only) */
    hexagon_read_BRKPT_through_stuff(target);

    hexagon_stuff_reg_restore(target);

    if (target->state != TARGET_HALTED) {
        LOG_DEBUG("Resume is requested when target is not halted, polling again");
        hexagon_poll(target);
        if (target->state != TARGET_HALTED)
            return ERROR_TARGET_NOT_HALTED;
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING
    hexagon_start_time_cal_ms();
#endif

    /* Select thread mask for resume: all threads if MT enabled, else thread 0 */
    if (hexa_info->multi_thr_enabled)
        thread_mask = ISDBCMD_ALL_THREADS_MASK(hexa_info->config.maxHwThreads);
    else
        thread_mask = ISDBCMD_TNUM_MASK_THREAD(0);

    isdbcmd = ISDBCMD_CMD_RESUME | ISDBCMD_MONITOR_LVL | thread_mask;

    LOG_DEBUG("Writing isdbcmd=0x%08x to HEXAGON_ISDB_ISDBCMD to resume target", isdbcmd);

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, 
             hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, 
             isdbcmd);
    if (retval != ERROR_OK) {
        LOG_ERROR("ISDBCMD write failed isdbcmd=0x%08x", isdbcmd);
        return retval;
    }

    /* Read ISDB status after issuing resume command */
    retval = hexagon_read_ISDBST(target, &isdbsts);
    if (retval != ERROR_OK)
        return retval;

    /* ISDBST bit[4] indicates ISDB command status (0 = success, 1 = failed) */
    if(isdbsts & ISDBST_ISDB_CMD_STATUS) {
        LOG_ERROR("ISDB resume command failed, ISDBST=0x%08x", isdbsts);
        return ERROR_FAIL;
    }
    LOG_DEBUG("ISDB resume command successful ");

    /* Bug fix: reset tlb_fetched so TLB is re-read on the next halt */
    qurt_context->tlb_fetched = false;

    /* Update target state after successful resume */
    target->debug_reason = DBG_REASON_NOTHALTED;

    /* Wait for ISDB state to stabilize after resume command */
    hexagon_wait_loop();

    if (!debug_execution) {
        target->state = TARGET_RUNNING;
        target_call_event_callbacks(target, TARGET_EVENT_RESUMED);
    } else {
        target->state = TARGET_DEBUG_RUNNING;
        target_call_event_callbacks(target, TARGET_EVENT_DEBUG_RESUMED);
    }

#ifdef _HEXAGON_TARGET_TIME_PROFILING
    hexagon_end_time_cal_ms();
    LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
#endif

    LOG_DEBUG("Hexagon resumed at PC 0x%08x", hexagon_print_pc(target, hexa_info->thread_id_thread_select));
    return ERROR_OK;
}


static int hexagon_read_BRKPT_through_stuff(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    // uint32_t isdb_mmode_cmd = 0x0;

    int retval = ERROR_OK;
    uint64_t stuff_inst[][4] = {{0x6ea4c007, 0x6707c029},
                        {0x6ea6c007, 0x6707c029},
                        {0x6ea5c007, 0x6707c029},
                        {0x6ea7c007, 0x6707c029}};        //r7=PC0,PC1,CFG0,CFG1; isdbmbxout = r7;
    uint32_t read_val[4] = {};
    uint32_t isdb_mmode_cmd = HEXAGON_ISDB_MMODE_CMD;
    // isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
    //                                             ISDBCMD_TNUM_MASK_THREAD(hwthrd));

    LOG_DEBUG("%s ------ %d\n",__FUNCTION__,__LINE__);
    
    for (int j = 0; j < 4; j++)
    {
        /*there are 2 stuff instruction, here programming first inst */
        retval = hexagon_isdb_cmd_status(target, stuff_inst[j][0],isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            return ERROR_OK;
            }

        retval = hexagon_isdb_cmd_status(target, stuff_inst[j][1],isdb_mmode_cmd);
        if (retval != ERROR_OK){
                LOG_DEBUG("ISDBcommand failed in monitor mode");
                     return ERROR_OK;
                }

        retval = hexagon_poll_mbxout(target);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBST status not set for mailbox so skiping reading it for register R%d", j);
            continue;
        }
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, &read_val[j]);
        if (retval != ERROR_OK) 
        {
            LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", read_val[j]);
        }
    #ifdef  _DEBUG_HEXAGON_
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT value 0x%x", read_val[j]);
        LOG_DEBUG("ISDBST status value after  reading mailbox register 0x%x ", isdbsts);
    #endif
    }
    LOG_DEBUG("BRKPTPC0: 0X%x, BRKPTPC1: 0X%x, BRKPTCFG0: 0X%x, BRKPTCFG1: 0X%x", 
              read_val[0], read_val[1], read_val[2], read_val[3]);

    return ERROR_OK;
}


static int hexagon_check_state_one(struct target *target,
        uint64_t mask, bool *halted, uint32_t *debug_thread)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdbsts = 0;
    int retval;

    if (halted == NULL || debug_thread == NULL )
    {
        LOG_DEBUG(" Fail: halted : %d, debug_thread 0x%x", *halted, *debug_thread);
        return ERROR_FAIL;
    }
    
    /*    Check ISDB status for threads in  debug mode */
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


static int hexagon_debug_entry(struct target *target)
{
    // static uint8_t vtlb_initialized = 0;
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct hexagon_brp *brp_list = hexagon->brp_list;
    struct reg_cache *cache = NULL;
    int retval = ERROR_OK;
    uint32_t brkptinfo = 0, brkptinfo1 = 0;
    uint64_t *thrd_src, thread_pc_value = 0;
    uint64_t hw_brkpt0 = 0, hw_brkpt1 = 0;
    uint32_t hw_thread_idx = 0;
    bool hw_brkpt_hit = false;

    thrd_src = (uint64_t *) malloc (hexa_info->config.maxHwThreads * sizeof(uint64_t));
    if (thrd_src == NULL) {
        LOG_DEBUG("Memory allocation for thrd_src failed");
        return ERROR_FAIL;
    }
    //  initialize thrd_src
    memset(thrd_src, 0, hexa_info->config.maxHwThreads * sizeof(uint64_t));

    LOG_DEBUG("hexagon_debug_entry  %s", target_name(target));
    
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO, &brkptinfo);

    if (retval != ERROR_OK) {
        LOG_DEBUG("BRKPTINFO read failed 0x%x", brkptinfo);
        free(thrd_src);
        return retval;
    }
    
    LOG_DEBUG("TARGET_HALTED, HEXAGON_ISDB_BRKPTINFO = 0x%x \n",brkptinfo);

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO, &brkptinfo);
    if (retval != ERROR_OK) {
        LOG_DEBUG("BRKPTINFO read failed 0x%x", brkptinfo);
        free(thrd_src);
        return retval;
    }

    if (hexa_info->config.maxHwThreads > NUM_HW_THREAD_IN_TILE0) {
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO1, &brkptinfo1);
        if (retval != ERROR_OK) {
            LOG_DEBUG("BRKPTINFO read failed 0x%x", brkptinfo);
            free(thrd_src);
            return retval;
        }    
    }

    for (hw_thread_idx = 0; hw_thread_idx < hexa_info->config.maxHwThreads; hw_thread_idx++) {
        if (hw_thread_idx < NUM_HW_THREAD_IN_TILE0)
            thrd_src[hw_thread_idx] = (brkptinfo >> (hw_thread_idx * BPT_SRC_BITS_PER_THREAD)) & BPT_SRC_MASK;
        else
            thrd_src[hw_thread_idx] = (brkptinfo1 >> ((hw_thread_idx - NUM_HW_THREAD_IN_TILE0) * BPT_SRC_BITS_PER_THREAD)) & BPT_SRC_MASK;
    }
        
    for(hw_thread_idx = 0; hw_thread_idx < hexa_info->config.maxHwThreads; hw_thread_idx++){
            
            LOG_DEBUG("Debug reason  thrd_src[%d]= %llx", hw_thread_idx, thrd_src[hw_thread_idx]);

            switch(thrd_src[hw_thread_idx])
            {
                case 0b000:
                    LOG_DEBUG("Thread num %d has hit Hardware breakpoint 0\n", hw_thread_idx);
                    LOG_INFO("HW Breakpoint 0 hit" );
                    hw_brkpt_hit = true;
                    break;
                    
                case 0b001:
                    LOG_DEBUG("Thread num %d has hit Hardware breakpoint 1\n", hw_thread_idx);
                    LOG_INFO("HW Breakpoint 1 hit" );
                    hw_brkpt_hit = true;
                    break;
                
                case 0b010:
                    LOG_DEBUG("Thread num %d has hexecuted BRKPT instruction\n", hw_thread_idx);
                    LOG_INFO("SW Breakpoint hit" );
                    break;
                    
                case 0b011:
                    LOG_DEBUG("Thread num %d has hit ETM Breakpoint\n", hw_thread_idx);
                    break;
                    
                case 0b100:
                    LOG_DEBUG("Thread num %d has hit APB Breakpoint\n", hw_thread_idx);
                    break;
                    
                case 0b101:
                    LOG_DEBUG("Thread num %d has External breakpoint\n", hw_thread_idx);
                    break;
                    
                default:
                    LOG_DEBUG("Default case: Thread num %d Breakpoint source = %llx\n", hw_thread_idx, thrd_src[hw_thread_idx]);
                    break;        
            }    
        }
    
    /* save the current BP info */
    hexa_info->brkptinfo = brkptinfo;
    
    /* Examine debug reason */
    hexagon_debug_reason(target, thrd_src[0]);
    hexagon_read_current_registers(target, hexa_info->config.maxHwThreads);

    /* Identify thread ID which had hit HW breakpoint */
    if (hw_brkpt_hit)
    {
        cache = hexa_info->core_cache;

        hw_brkpt0 = brp_list[0].value;
        hw_brkpt1 = brp_list[1].value;

        LOG_DEBUG("%s: HW BP0 addr=0x%llx, HW BP1 addr=0x%llx",
                  __FUNCTION__, hw_brkpt0, hw_brkpt1);

        for (hw_thread_idx = 0;
             hw_thread_idx < hexa_info->config.maxHwThreads;
             hw_thread_idx++, cache = cache->next)
        {
            thread_pc_value = *((uint64_t *)cache->reg_list[HEXAGON_PC].value);

            LOG_DEBUG("%s : PC value of HW thread %u : 0x%llx",
                      __FUNCTION__, hw_thread_idx, thread_pc_value);

            /*
             * NOTE:
             * HEXAGON_PC is a 64-bit register that may include non-address metadata
             * in the upper bits (e.g. execution context). Hardware instruction
             * breakpoints are matched only against the instruction address field,
             * which is the lower 32 bits. Therefore, comparison is done on the
             * lower 32 bits of both PC and breakpoint address.
             */

            /* HW Breakpoint 0 */
            if (thrd_src[hw_thread_idx] == 0 && 
                (uint32_t)thread_pc_value == (uint32_t)hw_brkpt0)
            {
                hexa_info->thread_id_thread_select = hw_thread_idx;

                /* Thread IDs are internally 0-based; adjust to 1-based for display */
                LOG_DEBUG("HW breakpoint 0 hit by HW thread %llu",
                          hexa_info->thread_id_thread_select + 1);
                break;
            }
        
            /* HW breakpoint 1 */
            else if (thrd_src[hw_thread_idx] == 1 && 
                (uint32_t)thread_pc_value == (uint32_t)hw_brkpt1)
            {
                hexa_info->thread_id_thread_select = hw_thread_idx;

                /* Thread IDs are internally 0-based; adjust to 1-based for display */
                LOG_DEBUG("HW breakpoint 1 hit by HW thread %llu",
                          hexa_info->thread_id_thread_select + 1);
                break;
            }
        }
    }

    hexagon_memory_map_refresh(target);
    
    //*****************************************************//
    if(((hexa_info->brkptinfo & BRKPTINFO_THREAD0_BRKPT_SOURCE)>>(0)) == HEXA_DBG_SWBRKPT)
    {
        
        LOG_DEBUG("Halted reason HEXA_DBG_SWBRKPT");
        struct breakpoint *current_breakpoint = target->breakpoints;
        uint8_t PC_matched_with_sbp_addr = 0;
        cache = hexa_info->core_cache;
        uint8_t i = 0;

        for( i =0; i < hexa_info->config.maxHwThreads; i++)
        {
            // Assign the address of gpPerHwThrdReg which  is uint32_t * to gpSbpHaltedThreadsPC is uint32_t ** 
            hexa_info->pSbpHaltedThreadsPC[i] = &hexa_info->pPerHwThrdReg[i][HEXAGON_PC];
        }
        
        cache = hexa_info->core_cache;
        while(current_breakpoint != NULL)
        {
        
            LOG_DEBUG("current_breakpoint->address = 0x%llx", current_breakpoint->address);
            LOG_DEBUG("current_breakpoint->type = 0x%x", current_breakpoint->type);
            LOG_DEBUG("current_breakpoint->is_set = 0x%x", current_breakpoint->is_set);
            LOG_DEBUG("current_breakpoint->orig_instr = 0x%hhn", current_breakpoint->orig_instr);
            LOG_DEBUG("current_breakpoint->next = 0x%p", (void *) current_breakpoint->next);
            i = 0;
            cache = hexa_info->core_cache;
            while ( i <  hexa_info->config.maxHwThreads)
            {
                LOG_DEBUG("*((uint64_t*)cache->reg_list[HEXAGON_PC].value) = 0x%p", hexa_info->pSbpHaltedThreadsPC[i]);
                
                /* Identify the HW thread that hit the software breakpoint.
                 * Software breakpoints advance PC by one instruction (PC + 4),
                 * so compare adjusted PC value with breakpoint address.
                 */
                if (*hexa_info->pSbpHaltedThreadsPC[i] == ((current_breakpoint->address) + 4))
                {
                    hexa_info->thread_id_thread_select = i;
                    LOG_INFO("Software breakpoint 0x%llx hit on hw thread : %u", current_breakpoint->address, i+1);
                    LOG_DEBUG("breakpoint address match with PC found in the bp-list, Replacing the original instruction in place of breakpoint");
                    PC_matched_with_sbp_addr = 1;
                    break;
                }
                cache = cache->next;
                i++;
            }
            if(PC_matched_with_sbp_addr)
                break;

            current_breakpoint = current_breakpoint->next;
            LOG_DEBUG("Reached here" );
            
            if(current_breakpoint)
            {
                    LOG_DEBUG("current_breakpoint->address = 0x%llx", current_breakpoint->address);
                    LOG_DEBUG("current_breakpoint->type = 0x%x", current_breakpoint->type);
                    LOG_DEBUG("current_breakpoint->is_set = 0x%x", current_breakpoint->is_set);
                    LOG_DEBUG("current_breakpoint->orig_instr = 0x%hhn", current_breakpoint->orig_instr);
                    LOG_DEBUG("current_breakpoint->next = 0x%p", (void *) current_breakpoint->next);
            }
            LOG_DEBUG("Reached here" );
        }
        if(!PC_matched_with_sbp_addr)
        {
            LOG_DEBUG("breakpoint not found in the list, returning with ERROR_FAIL");
            free(thrd_src);
            return ERROR_FAIL;
        }
        //set PC to PC-4
        retval = hexagon_write_ctrl_register(target, HEXAGON_PC, i, current_breakpoint->address);
        if (retval != ERROR_OK) {
            LOG_DEBUG("hexagon_write_ctrl_register HEXAGON_PC return value is not OK, returning with ERROR_FAIL");
            free(thrd_src);
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
        if (retval != ERROR_OK) {
            LOG_DEBUG("Replacing original instruction, hexagon_memw_write_instruction_memory return value is not OK. Returning with ERROR_FAIL");
            free(thrd_src);
            return ERROR_FAIL;
        }
    }    

    free(thrd_src);
    return ERROR_OK;
}
static void hexagon_memory_map_refresh(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    // struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    bool mmu_enabled = hexagon_is_mmu_enabled(target);
    uint32_t output = 0;    /* Bug fix: initialize to avoid undefined behaviour */

    if (mmu_enabled == true && qurt_context->tlb_fetched == false){
        hexagon_read_tlb_entry(target);
        qurt_context->tlb_lldb_query_done = true;
    }

    if (qurt_context->QURTK_vtlb_revision != 0x0 && qurt_context->vtlb_bitmap_logic_init_done)
    {
        qurt_context->refresh_indicator = qurt_context->QURTK_vtlb_revision;
        hexagon_memw_read (target, qurt_context->refresh_indicator, &output);
        qurt_context->refresh_indicator = output;
        hexagon_memw_read (target, qurt_context->refresh_indicator, &output);
        #ifdef HEXAGON_DEBUG_LOGS
            LOG_INFO("QURTK_vtlb_revision at 0x%x is 0x%x and the previous revision number is 0x%x", qurt_context.refresh_indicator, output, qurt_context.revision_num );
        #endif
    }

    if (mmu_enabled && hexagon_is_vtlb_initialized(target))    /* Bug fix: use cached mmu_enabled */
    {
        if (qurt_context->vtlb_initialized == true)
        {
            // before bitmap array has been read once and cleared, we need to populate all entries once
            if (qurt_context->bitmap_init == false)
            {
                hexagon_populate_vtlb_refresh_entries(target);
                /* Bug fix: mark bitmap as initialized after first full populate.
                 * This is safe because when hexagon_vtlb_enable_bitmap() has not yet
                 * succeeded, vtlb_bitmap_logic_init_done stays false, which means the
                 * revision block is skipped (output stays 0), and revision_num is also 0
                 * (never updated). So the else-if condition (output != revision_num) is
                 * always false, and hexagon_update_modified_vtlb_entry() is never called. */
                qurt_context->bitmap_init = true;
            }
            else if(output != qurt_context->revision_num) 
            {
                qurt_context->revision_num = output;
                LOG_DEBUG("updating modified vtlb entries");

                hexagon_update_modified_vtlb_entry(target);
            }
        }else{
            LOG_INFO("hexagon_populate_vtlb_data");
            hexagon_populate_vtlb_data(target);
        }
    }
    return;
}

void hexagon_debug_reason(struct target *target, uint64_t brkptinfo)
{
    /* Examine debug reason */
    switch (HEXA_DEBUG_ENTRY(brkptinfo)) 
    {
        case HEXA_DBG_EXTBRKPT:    
            target->debug_reason = DBG_REASON_DBGRQ;
            LOG_DEBUG("DBG_REASON_DBGRQ");
            break;
            
        case HEXA_DBG_HWBRKPT0:    
        case HEXA_DBG_HWBRKPT1: 
        case HEXA_DBG_SWBRKPT:
          case HEXA_DBG_ETMBRKPT:
         case HEXA_DBG_APBBRKPT:
            target->debug_reason = DBG_REASON_BREAKPOINT;
            LOG_DEBUG("DBG_REASON_BREAKPOINT");
                break;
        default:
            target->debug_reason = DBG_REASON_UNDEFINED;
            LOG_DEBUG("DBG_REASON_UNDEFINED");
            break;
    }
}


static int hexagon_poll(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    enum target_state prev_target_state;
    int retval = ERROR_OK;
    uint32_t debug_thread = 0;
    bool halted = false;

    if (hexagon->is_hexagon_untrusted == true){
        LOG_DEBUG("There is no need to halt Q6 to perform OEMPD Debug, skipping");
        return ERROR_OK;
    }
    retval = hexagon_check_state_one(target, ISDBST_DEBUG_MODE_STATUS, &halted, &debug_thread);
#ifdef HEXAGON_DEBUG
    LOG_DEBUG("hexagon_check_state_one returned %d",retval);
#endif

    static int cnt = 0;
    if((++cnt % 1000)==0){
        LOG_DEBUG("At FUNCTION:%s\t LINE:%d\n",__FUNCTION__, __LINE__);
    }

    
    if (halted == true) 
    {
        prev_target_state = target->state;
        // if((cnt%500)==0)
        if((cnt%100)==0)
        {
            LOG_DEBUG("At FUNCTION:%s\t LINE:%d, prev_target_state = %d",__FUNCTION__, __LINE__, prev_target_state);

            LOG_DEBUG("At FUNCTION:%s\t LINE:%d, (halted == true)",__FUNCTION__, __LINE__);
        }
        
        if (prev_target_state != TARGET_HALTED) 
        {
            enum target_debug_reason debug_reason = target->debug_reason;
            LOG_DEBUG("At FUNCTION:%s\t LINE:%d, prev_target_state = %d",__FUNCTION__, __LINE__, prev_target_state);
            LOG_DEBUG("At FUNCTION:%s\t LINE:%d, prev_target_state != TARGET_HALTED",__FUNCTION__, __LINE__);
            LOG_DEBUG("At FUNCTION:%s\t LINE:%d, target->debug_reason = %d",__FUNCTION__, __LINE__, debug_reason);

            /* We have a halting debug event */
            target->state = TARGET_HALTED;
            LOG_DEBUG("Target %s halted", target_name(target));
            
            retval = hexagon_debug_entry(target);

            if (retval != ERROR_OK)
                return retval;

            //if (target->smp)
                //hexagon_update_halt_gdb(target, debug_reason);
            LOG_DEBUG("entering switch case, prev state:%s\t LINE:%d, prev_target_state = %d",__FUNCTION__, __LINE__, prev_target_state);

            switch (prev_target_state) 
            {
                case TARGET_RUNNING:
                case TARGET_UNKNOWN:
                case TARGET_RESET:
                    LOG_DEBUG("At FUNCTION:%s\t LINE:%d, Calling target_call_event_callbacks(target, TARGET_EVENT_HALTED)",__FUNCTION__, __LINE__);
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


int  hexagon_arch_state(struct target *target)
{
    assert(target != NULL);
    // return target->arch_info;
#ifdef HEXAGON_DEBUG
    LOG_DEBUG("hexagon_arch_state returning ERROR_OK");
#endif

    return ERROR_OK;
}


/*
 * Basic debug access, very low level assumes state is saved
 */
static int hexagon_init_debug_access(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval = ERROR_OK;
    uint64_t isdbcmd, isdbcsts;
    uint32_t isdbsts = 0, bpinfo =0;

    retval = isdbcmd = isdbsts = isdbcsts = bpinfo = 0;

    LOG_DEBUG("hexagon_init_debug_access");
    // LOG_INFO("%s", target_name(target));

#ifdef HEXAGON_DEBUG
    LOG_DEBUG("Number of threads is %d",gHexConfig.maxHwThreads);
#endif

    uint32_t thread_mask = 0;

    if (hexa_info->multi_thr_enabled){
        thread_mask = ISDBCMD_ALL_THREADS_MASK(hexa_info->config.maxHwThreads);
    }
    else{
        thread_mask = ISDBCMD_TNUM_MASK_THREAD(0);
    }
    // Final ISDB command
    isdbcmd = ISDBCMD_CMD_BREAK | ISDBCMD_MONITOR_LVL | thread_mask;

#ifdef HEXAGON_DEBUG
    LOG_DEBUG("halting with isdbcmd : 0x%x",isdbcmd);
#endif

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBCMD, isdbcmd);
#ifdef HEXAGON_DEBUG
    LOG_DEBUG(" isdbcmd ap write done: 0x%x",isdbcmd);
#endif


    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDCMD write failed 0x%llx", isdbcmd);
        return retval;
    }

        /* Wait for some time  to enable ISDB clk */
    hexagon_wait_loop();
#ifdef HEXAGON_DEBUG
    LOG_DEBUG(" hexagon_wait_loop");
#endif
    /*    Check ISDB status for threads entering debug mode */
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
    if (retval != ERROR_OK)
    {
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
            return retval;
    }
    
    /* check ISDB core status - reset/PC to access ISDB*/
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO, &bpinfo);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBEN read failed 0x%x", bpinfo);
        return retval;
    }
    //LOG_INFO("Finally: ISDBstatus 0x%x, brkpt info 0x%x ", isdbcmd, isdbsts, bpinfo);
    LOG_INFO("Finally: ISDBstatus 0x%x, brkpt info 0x%x ",    isdbsts, bpinfo);
    LOG_INFO("Threads entered debug mode(ISDB status 0x%x)", isdbsts);
    target->debug_reason = DBG_REASON_DBGRQ;
#ifdef HEXAGON_DEBUG
    LOG_DEBUG(" exiting hexagon_init_debug_access");
#endif

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_handle_cache_info_command)
{
#ifdef HEXAGON_DEBUG
    LOG_DEBUG(" hexagon_handle_cache_info_command returning with ERROR OK");
#endif
    //struct target *target = get_current_target(CMD_CTX);
    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_handle_dbginit_command)
{
    struct target *target = get_current_target(CMD_CTX);
    if (!target_was_examined(target))
    {
        LOG_DEBUG("target not examined yet");
        return ERROR_FAIL;
    }
#ifdef HEXAGON_DEBUG
    LOG_DEBUG(" target was examined exiting hexagon_handle_dbginit_command ");
#endif
    return hexagon_init_debug_access(target);
}


COMMAND_HANDLER(hexagon_mask_interrupts_command)
{
    //struct target *target = get_current_target(CMD_CTX);
#ifdef HEXAGON_DEBUG
    LOG_DEBUG(" hexagon_mask_interrupts_command returning with ERROR OK");
#endif
    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_set_QURTK_vtlb_main_command)
{
    struct target *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    target_addr_t addr = 0;

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], addr);
        // hexagon_vtlb_data.QURTK_vtlb_main_VA = addr;
        qurt_context->qurtk_vtlb_main_addr = addr;
        command_print(CMD, " QURTK_vtlb_main = 0x%llx", addr);
        LOG_INFO("QURTK_VTLB_main = 0x%llx", addr);
    }

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_set_qurtk_vtlb_data_command)
{
    target_addr_t addr = 0;

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1) {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], addr);
        hexagon_vtlb_data.QURTK_VTLB_DATA_VA=addr;
        command_print(CMD, "QURTK_VTLB_DATA = 0x%llx", addr);
        LOG_INFO("QURTK_VTLB_DATA = 0x%llx", addr);
    }

    return ERROR_OK;
}

static target_addr_t threads;

COMMAND_HANDLER(hexagon_SetHWthreads)
{
    struct target *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;


    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], threads);
        hexa_info->config.maxHwThreads = threads;
        command_print(CMD, " HEXAGON_MAX_HW_THREADS_MODEM = %d", hexa_info->config.maxHwThreads);
        LOG_INFO("HEXAGON_MAX_HW_THREADS_MODEM = %d", hexa_info->config.maxHwThreads);
    }

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_SetQPSS6WDOGCTL)
{
    struct target *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    target_addr_t WDOG = 0;

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], WDOG);
        hexa_info->config.qpss6WDOGCtl = WDOG;
        command_print(CMD, " HEXAGON_MSS_QDSP6SS_WDOG_CTL = 0x%llx", WDOG);
        LOG_INFO("HEXAGON_MSS_QDSP6SS_WDOG_CTL = 0x%llx", WDOG);
    }

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_SetNumTLBEntries)
{
    struct target *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    target_addr_t numTLB = 0;

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], numTLB);
        hexa_info->config.numTlbEntries = numTLB;
        command_print(CMD, " HEXAGON_TLB_ENTRIES_NUM = %lld", numTLB);
        LOG_INFO("HEXAGON_TLB_ENTRIES_NUM = %lld", numTLB);
    }

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_initConfig)
{
    struct target *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    initConfig(hexagon);
    LOG_INFO("initiating with : ");
    LOG_INFO("HEXAGON_MAX_HW_THREADS_MODEM = %d", hexa_info->config.maxHwThreads);
    LOG_INFO("HEXAGON_TLB_ENTRIES_NUM = %d", hexa_info->config.numTlbEntries);
    LOG_INFO("HEXAGON_MSS_QDSP6SS_WDOG_CTL = 0x%x", hexa_info->config.qpss6WDOGCtl);

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_vtlbRefresh)
{
    struct target *target = get_current_target(CMD_CTX);
    start = clock();
    hexagon_populate_vtlb_refresh_entries(target);
    end = clock();
    execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    LOG_INFO("time taken for refresh_tlb_entries  %lf", execution_time);
    return ERROR_OK;
}   


void decToBinary(unsigned int n, unsigned int binaryNum[])
{
    int i = 0;
    while (n > 0 && i < 32) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
}

/* Reusable core: apply a VTLB bitmap and update entries. */
int hexagon_vtlb_enable_bitmap(struct target *target,
                              uint32_t bitmap_ptr_addr,
                              uint32_t entries_ptr_addr,
                              unsigned int entry_count)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

    if (entry_count == 0)
        return ERROR_OK;

    /* 1) Read the addresses the QuRT layer points us to */
    uint32_t bitmap_base = 0;
    uint32_t entries_base = 0;
    int retval;

    retval = hexagon_memw_read(target, bitmap_ptr_addr, &bitmap_base);
    if (retval != ERROR_OK) 
        return retval;

    retval = hexagon_memw_read(target, entries_ptr_addr, &entries_base);
    if (retval != ERROR_OK) 
        return retval;

    /* 2) Walk each bit in order; for each position we always advance by 8 bytes.
          If bit is set, read two words (lo, hi) and update the VTLB structure. */
    uint32_t bm_word = 0;
    unsigned curr_word_idx = (unsigned)-1; /* force first reload */
    uint32_t read_lo = 0, read_hi = 0;

    for (unsigned idx = 0; idx < entry_count; ++idx) {
        unsigned word_idx = idx / 32u;
        unsigned bit_idx  = idx % 32u;

        if (word_idx != curr_word_idx) {
            /* fetch next bitmap word */
            retval = hexagon_memw_read(target, bitmap_base + (word_idx * 4u), &bm_word);
            if (retval != ERROR_OK) 
                return retval;
            curr_word_idx = word_idx;
        }

        const bool bit_set = ((bm_word >> bit_idx) & 0x1u) != 0u;

        if (bit_set) {
            /* read lo/hi 32-bit words for this entry */
            retval = hexagon_memw_read(target, entries_base, &read_lo);
            if (retval != ERROR_OK) 
                return retval;

            retval = hexagon_memw_read(target, entries_base + 4u, &read_hi);
            if (retval != ERROR_OK) 
                return retval;

            /* push into your global VTLB structure */
            hexagon_update_vtlb_entry_in_structure((uint64_t)read_lo,
                                                   (uint64_t)read_hi,
                                                   (uint64_t)idx);
        }

        /* advance to next pair (8 bytes) unconditionally */
        entries_base += 8u;
    }

    /* Optional: mark bitmap as initialized just like the command did */
    qurt_context->bitmap_init = true;

    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_set_vtlb_params)
{
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;
    target_addr_t vtlb_entries = 0;

    if (CMD_ARGC < 2)
    {
        return ERROR_COMMAND_SYNTAX_ERROR;
    }
    else if (CMD_ARGC == 2)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], qurt_context->bitmap_addr);
        command_print(CMD, " bitmap addr = 0x%llx", qurt_context->bitmap_addr);
        qurt_context->qurtk_vtlb_bitmap = qurt_context->bitmap_addr;
        COMMAND_PARSE_ADDRESS(CMD_ARGV[1], vtlb_entries);
        qurt_context->qurtk_vtlb_entries = vtlb_entries;
        command_print(CMD, " QURTK_vtlb_entries = 0x%llx", vtlb_entries);
    }
    
    return ERROR_OK;
}
/* Core routine to set/read VTLB revision/refresh chain and cache it into qurt_context. */
static int hexagon_update_vtlb_revision(struct target *target)
    {
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

    uint32_t output = 0;

    LOG_INFO("QURTK_vtlb_revision  at = 0x%llx ", qurt_context->QURTK_vtlb_revision);
    hexagon_memw_read (target, qurt_context->QURTK_vtlb_revision, &output);
    qurt_context->refresh_indicator = output;
    hexagon_memw_read (target, qurt_context->refresh_indicator, &output);
    qurt_context->revision_num = output;
    LOG_INFO("revision num is = 0x%x ", qurt_context->revision_num);

    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_set_revision_addr)
{
    target_addr_t input;
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

    if (CMD_ARGC > 1)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], input);
        qurt_context->QURTK_vtlb_revision = input;
        command_print(CMD, " QURTK_vtlb_revision = 0x%llx", qurt_context->QURTK_vtlb_revision);
    }
    return ERROR_OK;
}



COMMAND_HANDLER(hexagon_multi_th_init)
{
    struct target  *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target->arch_info;

    if (CMD_ARGC > 0)
        return ERROR_COMMAND_SYNTAX_ERROR;

    if (CMD_ARGC == 0)
    {
        LOG_INFO("multithreading mode command");

        bool mmu_enabled = hexagon_is_mmu_enabled(target);

        hexagon->hexa_info.mmu_init = mmu_enabled;  
        hexagon->hexa_info.multi_thr_enabled = true;
        LOG_INFO("multi_thr_enabled : %d",hexagon->hexa_info.multi_thr_enabled);

        
        target = get_current_target (CMD_CTX);
        hexagon = target_to_hexagon (target);
        hexagon->hexa_info.config.maxHwThreads = threads;

        command_print(CMD, "vtlb logic and multithreading mode is initialized ");
        LOG_INFO("multithreading mode initialized");
    }

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_refresh_registers)
{
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common *hexagon = target->arch_info;
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    if (CMD_ARGC > 0)
    {
        return ERROR_COMMAND_SYNTAX_ERROR;
    }
    hexagon_read_gpr_registers(target, hexa_info->config.maxHwThreads);
    hexagon_read_ctrl_registers(target, hexa_info->config.maxHwThreads);

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_APB_RW)
{
    uint32_t output;
    int retval;
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common *hexagon = target->arch_info;
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    target_addr_t addr, value;


    if (CMD_ARGC > 2)
        return ERROR_COMMAND_SYNTAX_ERROR;
    else if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], addr);
        command_print(CMD, " reg_addr = 0x%llx",  addr);
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap, addr , &output);
        LOG_INFO("output read is 0x%x", output);
    }
    else if (CMD_ARGC == 2)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], addr);
        command_print(CMD, " reg_addr = 0x%llx", addr);
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap, addr, &output);
        LOG_INFO("output read is 0x%x", output);
        COMMAND_PARSE_ADDRESS(CMD_ARGV[1], value);
        command_print(CMD, " value = 0x%llx", value);
        LOG_INFO("value = 0x%llx ", value);
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, addr, value);
        LOG_INFO("value written is  0x%llx", value);
    }

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    addr, &output);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG ("read failed for addr : 0x%llx", addr);
    }

    LOG_INFO("output read is 0x%x", output);

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_dap_RW)
{
    uint32_t output;
    int retval;
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common *hexagon = target->arch_info;
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    target_addr_t reg_addr, value;

    if (CMD_ARGC > 2)
        return ERROR_COMMAND_SYNTAX_ERROR;
    else if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], reg_addr);
        command_print(CMD, " reg_addr = 0x%llx", hexa_info->debug_base + reg_addr);
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + reg_addr , &output);
        LOG_INFO("output read is 0x%x", output);
    }
    else if (CMD_ARGC == 2)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], reg_addr);
        command_print(CMD, " reg_addr = 0x%llx", hexa_info->debug_base + reg_addr);
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + reg_addr, &output);
        LOG_INFO("output read is 0x%x", output);
        COMMAND_PARSE_ADDRESS(CMD_ARGV[1], value);
        command_print(CMD, " value = 0x%llx", value);
        LOG_INFO("value = 0x%llx ", value);
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + reg_addr, value);
        LOG_INFO("value written is  0x%llx", value);
    }

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + reg_addr, &output);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG ("read failed for addr : 0x%llx", reg_addr);
    }
    LOG_INFO("output read is 0x%x", output);
    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_ReadClkRegs)
{
    struct target *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    target_addr_t Reg_addr[8];
    uint32_t i;

    for (i = 0; i <= 7 ; i++)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[i], Reg_addr[i]);
        hexa_info->config.clkEnAddr[i] = Reg_addr[i];
        command_print(CMD, " Register address = 0x%llx", Reg_addr[i]);
        LOG_INFO("Register address = 0x%llx", Reg_addr[i]);
    }
    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_SetETMclkAddress)
{
    struct target *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    target_addr_t etm_clk_en_Addr=0;

    COMMAND_PARSE_ADDRESS(CMD_ARGV[0], etm_clk_en_Addr);
    hexa_info->etm_base = etm_clk_en_Addr;
    command_print(CMD, " ETM clock enable address = 0x%x", hexa_info->etm_base);
    LOG_INFO(" ETM clock enable address = 0x%x", hexa_info->etm_base);

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_reset_spurious_brkpt)
{
    struct target *target = get_current_target (CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    hexa_info->is_spurious_breakpoint = 1;
    LOG_INFO("is_spurious_breakpoint = 0x%d ", hexa_info->is_spurious_breakpoint);
    return ERROR_OK;
}


COMMAND_HANDLER (hexagon_wait_time)
{    
    target_addr_t input_loop_count;
    if (CMD_ARGC > 2)
        return ERROR_COMMAND_SYNTAX_ERROR;
    else if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], input_loop_count);
        command_print(CMD, " loop count = %lld", input_loop_count);
        loop_count = input_loop_count;
        LOG_INFO("loop count is %lld", loop_count);
    }
    LOG_INFO("loop_count = %lld ", loop_count);
    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_mem_dap)
{
    int retval;
    // clock_t start_buffer, end_buffer;
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common *hexagon = target->arch_info;
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint64_t virt_addr = 0 , phy_addr=0, value = 0;
    uint32_t read_value =  0, isdbsts = 0;


    if (CMD_ARGC > 2)
        return ERROR_COMMAND_SYNTAX_ERROR;
    
    if (CMD_ARGC == 0)
    {
        LOG_INFO ("DUMPING VTLB ENTRIES");
        hexagon_print_vtlb_data();
        LOG_INFO ("DUMPING TLB ENTRIES");
        hexagon_read_tlb_entry(target);
        return ERROR_OK;
    }

    if (CMD_ARGC == 1)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], virt_addr);
        command_print(CMD, " virt_addr = 0x%llx", virt_addr);
        LOG_INFO("virt_addr = 0x%llx ", virt_addr);
        retval =  hexagon_virt2phys(target, virt_addr, &phy_addr);

        hexagon_memw_phys_read(target, phy_addr, &read_value);

        // LOG_INFO (" phy_addr is  : 0x%x", phy_addr);
        LOG_INFO ("0x%llx", phy_addr);

        return ERROR_OK;

    }

    if (CMD_ARGC == 2)
    {
        COMMAND_PARSE_ADDRESS(CMD_ARGV[0], virt_addr);
        command_print(CMD, " virt_addr = 0x%llx", virt_addr);
        LOG_INFO("virt_addr = 0x%llx ", virt_addr);

        COMMAND_PARSE_ADDRESS(CMD_ARGV[1], value);
        command_print(CMD, " value = 0x%llx", value);
        LOG_INFO("value = 0x%llx ", value);
        // retval = hexagon_new_memw_write(target, virt_addr, value, 1);
        retval = hexagon_physical_addr_store(target, virt_addr, value, 1);

        LOG_DEBUG("hexagon_memw_write  Exit");
    }


    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                        hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

    if (retval != ERROR_OK)
            LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    

    return ERROR_OK;
}


COMMAND_HANDLER(hexagon_handle_untrusted_command)
{
    struct target *target = get_current_target(CMD_CTX);
    struct hexagon_common *hexagon = target_to_hexagon (target);

    if (!target_was_examined(target))
    {
        LOG_DEBUG("target not examined yet");
        return ERROR_FAIL;
    }
    return hexagon_untrusted_mode(hexagon);
}


/* Forward declarations for the QuRT enable/disable/status command handlers.
 * Their bodies are defined just after this table, but the table references
 * them, so declare the prototypes first. (COMMAND_HANDLER(name) expands to a
 * function prototype/definition with the standard command-handler signature.) */
COMMAND_HANDLER(hexagon_qurt_enable_cmd);
COMMAND_HANDLER(hexagon_qurt_disable_cmd);
COMMAND_HANDLER(hexagon_qurt_status_cmd);
COMMAND_HANDLER(hexagon_qurt_stack_cmd);
COMMAND_HANDLER(hexagon_qurt_set_offsets_cmd);

static const struct command_registration hexagon_exec_command_handlers[] = {
    {
        .name = "cache_info",
        .handler = hexagon_handle_cache_info_command,
        .mode = COMMAND_EXEC,
        .help = "display information about hexagon caches",
        .usage = "",
    },
    {
        .name = "mem_dap",
        .handler = hexagon_mem_dap,
        .mode = COMMAND_ANY,
        .help = "memw virtual read",
        .usage = "[]",
    },
    {
        .name = "spurious_brkpt_reset",
        .handler = hexagon_reset_spurious_brkpt,
        .mode = COMMAND_EXEC,
        .help = "to help ignore or consider the first breakpoint sent from lldb while establishing gdb connection",
        .usage = "",
    },

    {
        .name = "dbginit",
        .handler = hexagon_handle_dbginit_command,
        .mode = COMMAND_EXEC,
        .help = "Initialize Hexagon debug",
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
        .name = "qurtEnable",
        .handler = hexagon_qurt_enable_cmd,
        .mode = COMMAND_EXEC,
        .help = "Enable QuRT SW-thread awareness walk (run AFTER reaching main/QURTOS_init)",
        .usage = "",
    },
    {
        .name = "qurtDisable",
        .handler = hexagon_qurt_disable_cmd,
        .mode = COMMAND_EXEC,
        .help = "Disable QuRT SW-thread awareness walk (HW threads only)",
        .usage = "",
    },
    {
        .name = "qurtStatus",
        .handler = hexagon_qurt_status_cmd,
        .mode = COMMAND_EXEC,
        .help = "Show whether the QuRT SW-thread walk is enabled",
        .usage = "",
    },
    {
        .name = "qurtStack",
        .handler = hexagon_qurt_stack_cmd,
        .mode = COMMAND_EXEC,
        .help = "Print FRAMEKEY-unscrambled deep backtrace of a parked QuRT SW thread",
        .usage = "<sw_thread_id>",
    },
    {
        .name = "qurtSetOffsets",
        .handler = hexagon_qurt_set_offsets_cmd,
        .mode = COMMAND_ANY,
        /* Push the TCB layout (SIZEOF + per-field offsets) that the lldb-side
         * OSAM has resolved from the ELF's DWARF by struct member NAME. This
         * makes the qurt.c SW walk authoritative across build variants
         * (SIZEOF_TCB 384/448, utcb_name 28/32, ...) without hardcoding
         * anything in the C driver. Invoked automatically by the OSAM init
         * hook -- users should not need to run it manually. */
        .help = "Push DWARF-resolved QuRT TCB offsets to the RTOS backend",
        .usage = "<ctx_size> <prio> <tid> <ugpgp> <hthread> <ssrelr> "
                 "<r0100> <r2928> <r3130> <framelimit> <framekey> "
                 "<guest_info> <utcb_name>",
    },
 
    // {
    //     .name = "mem_dap",
    //     .handler = hexagon_mem_dap,
    //     .mode = COMMAND_ANY,
    //     .help = "memw virtual read",
    //     .usage = "[]",
    // },
    {
        .name = "initConfig",
        .handler = hexagon_initConfig,
        .mode = COMMAND_ANY,
        .help = "Initiate with the set values",
        .usage = "[]",
    },
    {
        .name = "DAP",
        .handler = hexagon_dap_RW,
        .mode = COMMAND_ANY,
        .help = "find modified vtlb",
        .usage = "[]",
    },
    {   
        .name = "RegRefresh",
        .handler = hexagon_refresh_registers,
        .mode = COMMAND_ANY,
        .help = "refresh all registers and system status",
        .usage = "[]",
    },
    {
        .name = "EnableClockRegs",
        .handler = hexagon_ReadClkRegs,
        .mode = COMMAND_ANY,
        .help = "Enable AXI by setting register addresses",
        .usage = "[address1] [address2] [address3] [address4] [address5] [address6] [address7] [address8]",
    },
    {
        .name = "SetEtmClkAddress",
        .handler = hexagon_SetETMclkAddress,
        .mode = COMMAND_ANY,
        .help = "Set ETM addresses",
        .usage = "[address]",
    },
    {
        .name = "multi_th_init",
        .handler = hexagon_multi_th_init,
        .mode = COMMAND_EXEC,
        .help = "vtlb with multithreading mode has been initialized",
        .usage = "",
    },
    {
        .name = "time_delay",
        .handler = hexagon_wait_time,
        .mode = COMMAND_EXEC,
        .help = "delay period between DAP writes to ISDB register writes",
        .usage = "",
    },
    {
        .name = "APB",
        .handler = hexagon_APB_RW,
        .mode = COMMAND_ANY,
        .help = "Reads/Writes via APB",
        .usage = "[]",
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
        .chain = smp_command_handlers,
    },
    COMMAND_REGISTRATION_DONE};

/* QuRT RTOS-awareness enable/disable command hooks and the FRAMEKEY-aware
 * FP-chain stack walker are declared in rtos/qurt.h (implemented in
 * src/rtos/qurt.c). */

COMMAND_HANDLER(hexagon_qurt_enable_cmd)
{
    struct target *target = get_current_target(CMD_CTX);
    if (!target || !target->rtos) {
        command_print(CMD, "qurt: no RTOS attached to target");
        return ERROR_FAIL;
    }
    qurt_set_walk_enabled(target, true);
    command_print(CMD, "qurt: SW-thread walk ENABLED");
    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_qurt_disable_cmd)
{
    struct target *target = get_current_target(CMD_CTX);
    if (!target || !target->rtos) {
        command_print(CMD, "qurt: no RTOS attached to target");
        return ERROR_FAIL;
    }
    qurt_set_walk_enabled(target, false);
    command_print(CMD, "qurt: SW-thread walk DISABLED");
    return ERROR_OK;
}

COMMAND_HANDLER(hexagon_qurt_status_cmd)
{
    struct target *target = get_current_target(CMD_CTX);
    if (!target || !target->rtos) {
        command_print(CMD, "qurt: no RTOS attached to target");
        return ERROR_FAIL;
    }
    command_print(CMD, "qurt: SW-thread walk is %s",
                  qurt_get_walk_enabled(target) ? "ENABLED" : "DISABLED");
    return ERROR_OK;
}

/* hexagon qurtStack <swid> : print the FRAMEKEY-unscrambled deep backtrace of
 * a parked QuRT SW thread (the authoritative trace lldb's native unwinder
 * cannot produce). Symbolize the printed addresses on the host with
 * `image lookup -a <addr>`. */
COMMAND_HANDLER(hexagon_qurt_stack_cmd)
{
    struct target *target = get_current_target(CMD_CTX);
    if (!target || !target->rtos) {
        command_print(CMD, "qurt: no RTOS attached to target");
        return ERROR_FAIL;
    }
    if (CMD_ARGC != 1) {
        command_print(CMD, "usage: hexagon qurtStack <sw_thread_id>");
        return ERROR_COMMAND_SYNTAX_ERROR;
    }
    target_addr_t swid = 0;
    COMMAND_PARSE_ADDRESS(CMD_ARGV[0], swid);
    return qurt_stack_walk(target, (int64_t)swid, CMD);
}

/* hexagon qurtSetOffsets <ctx_size> <prio> <tid> <ugpgp> <hthread> <ssrelr>
 *                        <r0100> <r2928> <r3130> <framelimit> <framekey>
 *                        <guest_info> <utcb_name>
 *
 * Push authoritative TCB layout (SIZEOF and per-field byte offsets) resolved
 * from the ELF's DWARF by struct member NAME into the QuRT RTOS backend.
 * Issued by the lldb-side OSAM init hook (utils.py) via
 *   `process plugin packet monitor hexagon qurtSetOffsets ...`
 * after the ELF has been loaded and BEFORE the first halt-driven
 * qXfer:threads:read, so the SW-thread walk is authoritative from the very
 * first read. Idempotent: pushing again just overwrites and forces a re-cache
 * on the next update.
 *
 * All 13 args are unsigned 32-bit values (context size + 12 offsets). If the
 * target was not created with `-rtos qurt` the command reports an error;
 * the OSAM tolerates that (some sub-targets don't attach a QuRT RTOS). */
COMMAND_HANDLER(hexagon_qurt_set_offsets_cmd)
{
    struct target *target = get_current_target(CMD_CTX);
    if (!target || !target->rtos) {
        command_print(CMD, "qurt: no RTOS attached to target -- "
                           "qurtSetOffsets requires `-rtos qurt` on this target");
        return ERROR_FAIL;
    }
    if (CMD_ARGC != 13) {
        command_print(CMD, "usage: hexagon qurtSetOffsets <ctx_size> "
                           "<prio> <thread_id> <ugpgp> <hthread> <ssrelr> "
                           "<r0100> <r2928> <r3130> <framelimit> <framekey> "
                           "<guest_info> <utcb_name>");
        return ERROR_COMMAND_SYNTAX_ERROR;
    }

    uint32_t v[13];
    for (unsigned i = 0; i < 13; i++)
        COMMAND_PARSE_NUMBER(u32, CMD_ARGV[i], v[i]);

    int retval = qurt_apply_pushed_offsets(target,
            v[0],                  /* context_size                     */
            v[1], v[2], v[3],      /* prio, thread_id, ugpgp           */
            v[4], v[5],            /* hthread, ssrelr                  */
            v[6], v[7], v[8],      /* r0100, r2928, r3130              */
            v[9], v[10],           /* framelimit, framekey             */
            v[11], v[12]);         /* guest_info, utcb_name            */
    if (retval != ERROR_OK) {
        command_print(CMD, "qurt: apply_pushed_offsets failed (retval=%d)",
                      retval);
        return retval;
    }

    command_print(CMD, "qurt: TCB layout pushed (OSAM/DWARF): "
                       "ctx_size=%u prio=%u tid=%u ugpgp=%u hthread=%u "
                       "ssrelr=%u r0100=%u r2928=%u r3130=%u flim=%u "
                       "fkey=%u ginfo=%u utcb=%u",
                  v[0], v[1], v[2], v[3], v[4], v[5],
                  v[6], v[7], v[8], v[9], v[10], v[11], v[12]);
    return ERROR_OK;
}

static const struct command_registration hexagon_command_handlers[] = {
    {
        .name = "hexagon",
        .mode = COMMAND_ANY,
        .help = "hexagon command group",
        .usage = "command <> <>",
        .chain = hexagon_exec_command_handlers,
    },
    COMMAND_REGISTRATION_DONE
};


enum hexagon_cfg_param
{
    CFG_CTI,
    CFG_HVX,   
    CFG_HMX    
};

static const struct jim_nvp nvp_config_opts[] = 
{
    { .name = "-cti",   .value = CFG_CTI },
    { .name = "-hvx",   .value = CFG_HVX },     
    { .name = "-hmx",   .value = CFG_HMX },     
    { .name = NULL,     .value = -1 }
};


static int hexagon_handle_target_request(void *priv)
{
    struct target *target = priv;
    struct hexagon_common *hexagon = target->arch_info;
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t brkptinfo = 0, brkptinfo1 = 0;
    int retval;
    static int cnt = 0;
    uint32_t *thrd_src;

    thrd_src = (uint32_t *) malloc(hexa_info->config.maxHwThreads * sizeof(uint32_t));

    if ((++cnt % 1000) == 0)
        LOG_DEBUG("hexagon_handle_target_request exam=%d dbg=%d state=%d ", target->examined, target->dbg_msg_enabled, target->state); 

    if (target->state == TARGET_HALTED && ((cnt % 200) == 0))
    {
        
        LOG_DEBUG("TARGET_HALTED\n"); 
        // Check the halt reason

        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO, &brkptinfo); 
        if (retval != ERROR_OK) {
            LOG_DEBUG("BRKPTINFO read failed 0x%x", brkptinfo);
            free(thrd_src);
            return retval;
        }

        if (hexa_info->config.maxHwThreads > NUM_HW_THREAD_IN_TILE0) {
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + HEXAGON_ISDB_BRKPTINFO1, &brkptinfo1);
            if (retval != ERROR_OK) {
                LOG_DEBUG("BRKPTINFO read failed 0x%x", brkptinfo);
                free(thrd_src);
                return retval;
            }    
        }

        for (uint32_t i = 0; i < hexa_info->config.maxHwThreads; i++) {
            if (i < NUM_HW_THREAD_IN_TILE0)
                thrd_src[i] = (brkptinfo >> (i * BPT_SRC_BITS_PER_THREAD)) & BPT_SRC_MASK;
            else
                thrd_src[i] = (brkptinfo1 >> ((i - NUM_HW_THREAD_IN_TILE0) * BPT_SRC_BITS_PER_THREAD)) & BPT_SRC_MASK;
        }

        LOG_DEBUG("TARGET_HALTED, HEXAGON_ISDB_BRKPTINFO = 0x%x \n", brkptinfo);

        for (uint32_t i = 0; i < hexa_info->config.maxHwThreads; i++)
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
                    LOG_DEBUG("Thread num %d has executed BRKPT instruction\n", i);
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


static int hexagon_init_arch_info(struct target *target,
    struct hexagon_common *hexagon, struct adiv5_dap *dap)
{
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

    LOG_DEBUG("hexagon_init_arch_info");

    hexagon->common_magic = HEXAGON_COMMON_MAGIC; 


    for (int i =0; i < HEXAGON_PER_THREAD_REGS; i++)
        hexa_info->pPerHwThrdReg = 0x0;

    hexa_info->dap = dap;
    hexa_info->arch_info = hexagon;
    target->arch_info = hexagon;
    hexa_info->target= target;
    hexa_info->mmu_init = false;
    hexa_info->multi_thr_enabled = false;

    memset(global_reg, 0, sizeof(global_reg));   
    target_register_timer_callback(hexagon_handle_target_request, 5,
        TARGET_TIMER_TYPE_PERIODIC, target);

    qurt_context->selected_process = -1;
    qurt_context->bitmap_addr = 0x0;
    qurt_context->total_process = 0;
    qurt_context->refresh_indicator = 0x0;
    qurt_context->revision_num = 0x0;
    qurt_context->hexagon_debug_process_id = 0x2;
    qurt_context->qurtk_vtlb_main_addr = 0x0;
    qurt_context->qurtk_vtlb_entries = 0x0;
    // .bitmap_array_addr = 0x0,
    qurt_context->QURTK_vtlb_revision = 0x0;
    qurt_context->qurtk_vtlb_bitmap = 0x0;
    qurt_context->bitmap_addr = 0x0;
    qurt_context->vtlb_initialized = false;
    qurt_context->bitmap_init = false;
    qurt_context->tlb_fetched = false;
    qurt_context->tlb_lldb_query_done = false;

    return ERROR_OK;
}


static int hexagon_target_create(struct target *target, Jim_Interp *interp)
{

    struct hexagon_private_config *pc = target->private_config;
    struct hexagon_common *hexagon;

    LOG_DEBUG("hexagon_target_create");
    
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


static int hexagon_jim_configure(struct target *target, struct jim_getopt_info *goi)
{
    struct hexagon_private_config *pc;
    struct jim_nvp *n;
    int e;

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
    if (goi->argc > 0) {
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

        case CFG_HMX:
            break;

        case CFG_HVX:
            break;

        default:
            return JIM_CONTINUE;
        }
    }

    return JIM_OK;
}

void micro_second_sleep(uint32_t microseconds) {
    struct timespec sleep_time;
    sleep_time.tv_sec = 0;
    sleep_time.tv_nsec = microseconds * 1000; // convert microseconds to nanoseconds
    nanosleep(&sleep_time, NULL);
}

static void hexagon_wait_loop(void){
     uint16_t i, loop = 0;

    for (i = 0; i < loop_count; i++)
    {
        if ((i % 1000) == 0)
            //LOG_DEBUG("in hexagon_wait_loop()");
            loop++;
    }
}


/* This function enable the ETM */
static uint64_t hexagon_etm_on(struct target *target)
{
    struct hexagon_common *hexagon = target->arch_info;
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    static int initialized;
    uint64_t retval = ERROR_OK;
    uint32_t tmp;

    if(!initialized)
    {
        LOG_INFO("Enabling ETM ");
        tmp = 0x3;
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->etm_base, tmp);

        if (retval != ERROR_OK)
        {
            LOG_DEBUG("unable to enable ETM clk 0x%x", tmp);
            return retval;
        }
        hexagon_wait_loop();
        tmp = 0x1;
        // retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,etm_clk_reset_addr, tmp);
        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->etm_base , tmp);

        if (retval != ERROR_OK)
        {
            LOG_DEBUG("unable to reset ETM 0x%x", tmp);
            return retval;
        }
        hexagon_wait_loop();


        // assert resert
        tmp = 0x1;

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->etm_base + HEXAGON_ETM_RESET, tmp);

        if (retval != ERROR_OK)
        {
            LOG_DEBUG("APB unlock fail");
            return retval;
        }
        hexagon_wait_loop();
        LOG_INFO("After Enabling ETM ");
        retval = mem_ap_read_atomic_u32(hexa_info->debug_ap, hexa_info->etm_base , &tmp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("unable to write to ETM reset 0x%x", tmp);
            return retval;
        }
        LOG_DEBUG("ETM clk 0x%x", tmp);

        // deassert resert
        tmp = 0x0;

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->etm_base + HEXAGON_ETM_RESET, tmp);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("unable to write to ETM reset0x%x", tmp);
            return retval;
        }
        LOG_DEBUG("ETM reset 0x%x", tmp);
        initialized = 1;
    }

    return retval;
}


/*  This function is used to disable the watchdog during debug */
static void hexagon_hw_watchdog_disable(struct target *target)
{
    int retval;
    uint32_t temp;
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;


    LOG_DEBUG("hexagon_hw_watchdog_disable  enter "); 
        
    if(debug_axi_ap == NULL)
        hexagon_initialize_axi_ap(target);

    if(debug_axi_ap == NULL)
    {
        LOG_DEBUG("debug_axi_ap not available so watchdog is not disabled "); 
        return;
    }
    retval = mem_ap_read_buf(debug_axi_ap,(uint8_t *)&temp, 4, 1, hexa_info->config.qpss6WDOGCtl);
    if(retval != ERROR_OK)
        LOG_DEBUG("read api failed"); 
    
    LOG_DEBUG("HEXAGON_QDSP6SS_WDOG_CTL read value  = 0x%x ",temp);
    
    retval = mem_ap_write_atomic_u32(debug_axi_ap,
                hexa_info->config.qpss6WDOGCtl, HEXAGON_MSS_QDSP6SS_WDOG_DISABLE);
    
    if(retval != ERROR_OK)
        LOG_DEBUG("WDOG disabled failed"); 
        
    hexagon_wait_loop();
    retval = mem_ap_read_buf(debug_axi_ap,(uint8_t *)&temp, 4, 1, hexa_info->config.qpss6WDOGCtl);
    if(retval != ERROR_OK)
        LOG_DEBUG("read api failed"); 
    
    LOG_DEBUG("HEXAGON_QDSP6SS_WDOG_CTL  read value after write  = 0x%x ",temp); 
    LOG_INFO("hexagon_hw_watchdog_disable  exit "); 
}

#if 0
/*  This function is used to enable  the clocks  needed for  debug */
static void hexagon_enable_clock(struct target *target)
{
    int retval;
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    LOG_DEBUG("hexagon_enable_clock  enter "); 
        
    if(debug_axi_ap == NULL)
        hexagon_initialize_axi_ap(target);

    if(debug_axi_ap == NULL)
    {
        LOG_DEBUG("debug_axi_ap not available so clock is not enabled "); 
        return;
    }
    retval = mem_ap_write_atomic_u32(debug_axi_ap, hexa_info->config.clkEnAddr[0], 0x20008001);
    if (retval != ERROR_OK)
        LOG_DEBUG("unable to perform enable clock register write");
    retval = mem_ap_write_atomic_u32(debug_axi_ap, hexa_info->config.clkEnAddr[1], 0x20008001);
    if (retval != ERROR_OK)
        LOG_DEBUG("unable to perform enable clock register write");
    retval = mem_ap_write_atomic_u32(debug_axi_ap, hexa_info->config.clkEnAddr[2], 0x1);
    if (retval != ERROR_OK)
        LOG_DEBUG("unable to perform enable clock register write");
    retval = mem_ap_write_atomic_u32(debug_axi_ap, hexa_info->config.clkEnAddr[3], 0x1);
    if (retval != ERROR_OK)
        LOG_DEBUG("unable to perform enable clock register write");
    retval = mem_ap_write_atomic_u32(debug_axi_ap, hexa_info->config.clkEnAddr[4], 0x1);
    if (retval != ERROR_OK)
        LOG_DEBUG("unable to perform enable clock register write");
    retval = mem_ap_write_atomic_u32(debug_axi_ap, hexa_info->config.clkEnAddr[5], 0x1);
    if (retval != ERROR_OK)
        LOG_DEBUG("unable to perform enable clock register write");
    retval = mem_ap_write_atomic_u32(debug_axi_ap, hexa_info->config.clkEnAddr[6], 0x20000001);
    if (retval != ERROR_OK)
        LOG_DEBUG("unable to perform enable clock register write");
    retval = mem_ap_write_atomic_u32(debug_axi_ap, hexa_info->config.clkEnAddr[7], 0x1);
    if (retval != ERROR_OK)
        LOG_DEBUG("unable to perform enable clock register write");

    LOG_INFO("hexagon_enable_clock  exit "); 
}
#endif

static int hexagon_examine_writes(struct target *target) {
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval = 0;

    int num_writes = sizeof(examine_writes_dbg_base) / sizeof(examine_writes_dbg_base[0]);

    for (int i = 0; i < num_writes; i++) {
        uint32_t addr = examine_writes_dbg_base[i][0];
        uint32_t val  = examine_writes_dbg_base[i][1];

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->debug_base + addr, val);
        if (retval != ERROR_OK) {
            LOG_DEBUG("Write failed at address 0x%llx", hexa_info->debug_base + addr);
        }
        LOG_INFO("After writing 0x%llx with value 0x%08x", hexa_info->debug_base + addr, val);
    }
    num_writes = sizeof(examine_writes_etm_base) / sizeof(examine_writes_etm_base[0]);

    for (int i = 0; i < num_writes; i++) {
        uint32_t addr = examine_writes_etm_base[i][0];
        uint32_t val  = examine_writes_etm_base[i][1];

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap, hexa_info->etm_base + addr, val);
        if (retval != ERROR_OK) {
            LOG_DEBUG("Write failed at address 0x%x", hexa_info->etm_base + addr);
        }
        LOG_INFO("After writing 0x%x with value 0x%08x", hexa_info->etm_base + addr, val);
    }
    return ERROR_OK;
}


static int hexagon_examine_first(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_private_config *pc = (struct hexagon_private_config *)target->private_config;

    //LOG_DEBUG("Entering %s\n",__FUNCTION__);

    LOG_DEBUG("Number of bp available brp_num_available= %d", hexagon->brp_num_available);
    LOG_DEBUG("Number of bp available brp_num= %d", hexagon->brp_num);
    LOG_DEBUG("Number of bp available brp_num_context= %d", hexagon->brp_num_context);
    //Hard coding brp_num_available = HEXAGON_MAX_HW_BRKPT for now, need to find a permanent solution. *hexagon = target_to_hexagon(target); should give valid data.
    hexagon->brp_num_available = HEXAGON_MAX_HW_BRKPT;             //this value is constant to future ref
    hexagon->brp_num = HEXAGON_MAX_HW_BRKPT;                        //upon setting/removing HW breakpoint this value will be decreased/increased 
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    //struct hexagon_private_config *pc;
    struct adiv5_dap *swddp = hexa_info->dap;
    int retval = ERROR_OK;
    uint32_t isdben,isdbver,isdbcstat,isdbst, corever, tmp;
    isdben = isdbver = isdbcstat = isdbst = corever = tmp = 0;

    if (!hexa_info->debug_ap) 
    {
        if(pc->adiv5_config.ap_num == DP_APSEL_INVALID) 
        {
            // 1.APB-AB
            /* Search for the APB-AB - it is needed to access debug registers */
            retval = dap_find_get_ap(swddp, AP_TYPE_APB_AP, &hexa_info->debug_ap);
            if (retval != ERROR_OK)
            {
                LOG_DEBUG("Could not find APB-AP for debug access");
                return retval;
            }
        }
        else
        {
            hexa_info->debug_ap = dap_get_ap(swddp, pc->adiv5_config.ap_num);
            if (!hexa_info->debug_ap) {
                LOG_ERROR("Cannot get AP");
                return ERROR_FAIL;
            }
        }
    }

    retval = mem_ap_init(hexa_info->debug_ap);
    if (retval != ERROR_OK) {
        LOG_DEBUG("Could not initialize the APB-AP");
        return retval;
    }

    hexa_info->debug_ap->memaccess_tck = 10;

    if (!target->dbgbase_set) {

        /* TDB */
        uint64_t dbgbase;
        /* Get ROM Table base */
        uint32_t apid;
        int32_t coreidx = target->coreid;
        
        retval = dap_get_debugbase(hexa_info->debug_ap, &dbgbase, &apid);
        if (retval != ERROR_OK)
            return retval;
        /* Lookup 0x15 -- Processor DAP */
        retval = dap_lookup_cs_component(hexa_info->debug_ap, 0x15,
                &hexa_info->debug_base, coreidx);
        if (retval != ERROR_OK)
            return retval;
        LOG_INFO("Detected core %x dbgbase: %llx apid: %x",\
                     coreidx, hexa_info->debug_base, apid);
    } else
        /** debug base = 0x0x86809000 **/
        hexa_info->debug_base = target->dbgbase;

    hexagon_wait_loop();

    /* Unlocking the APB address space by writing to debug base + 0xFB0 with  0xc5acce55 */
    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,hexa_info->debug_base + 0xFB0, 0xc5acce55);
    if(retval != ERROR_OK)
        LOG_DEBUG("hexa_info->debug_base + 0xFB0    write failed"); 
    LOG_INFO("After writing 0x%llx    with value    0xC5ACCE55", hexa_info->debug_base+ 0xFB0); 

    /* Need to wait some time after writing to register to take it effect */
    hexagon_wait_loop(); 

    retval = hexagon_etm_on(target);
    if (retval != ERROR_OK)
        LOG_DEBUG("ETM enablement fail"); 
    
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_ISDBCST, &isdbcstat);
    if (retval != ERROR_OK) {
            LOG_DEBUG("ISDBCST read failed 0x%x", isdbcstat);
        return retval;
    }
    if (isdbcstat == 4)
    {
    LOG_ERROR("Q6 Processor is in reset or power collapse, please wait until the core is active");
    return ERROR_FAIL;
    }
    

        /** check ISDB version details **/
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBVER, &isdbver);
    if (retval != ERROR_OK) {
        LOG_DEBUG("ISDBVER read failed 0x%x", isdbver);
        return retval;
    }
    LOG_DEBUG("ISDBver 0x%x  ", isdbver);
    hexa_info->isdbver = isdbver;

    if (hexa_info->isdbver == HEXAGON_V81)        
        hexagon_examine_writes(target);

        /** check core version details **/
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_COREVER, &corever);
    if (retval != ERROR_OK) {
        LOG_DEBUG("COREVER read failed 0x%x", corever);
        return retval;
    }
    LOG_DEBUG(" core ver 0x%x ", corever);

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
    {     /** trusted, secure, clk on, apb enabl **/
        hexa_info->isdb_enable = true;
        isdben |= ISDBEN_APB_ISDB_EN;
        isdben |= ISDBEN_ISDB_PREVNT_PWRDWN;

        retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_ISDBEN, isdben);
    if (retval != ERROR_OK)
    {
            LOG_DEBUG("ISDBEN write failed 0x%x", isdben);
            return retval;
        }
        LOG_DEBUG("After ISDBEN write  0x%x", isdben);
    }
    else 
    {
        LOG_DEBUG("ISDB is already enabled 0x%x", isdben);
    }


    hexagon_wait_loop();

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBEN, &isdben);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("ISDBEN read failed 0x%x", isdben);
        return retval;
    }
    LOG_DEBUG("After ISDBEN read 0x%x ", isdben);

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbst);
    if (retval != ERROR_OK)
    {
            LOG_DEBUG("ISDB status read failed 0x%x", isdbst);
            return retval;
    }
    LOG_DEBUG("After ISDB status  0x%x ", isdbst);
    
    //---------------Hexagon breakpoint global data structure setup---------------//
    hexagon->brp_num = HEXAGON_MAX_HW_BRKPT;
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
        
    //-----------------------------------------------------------------------//

    //hexagon_setup_isdb_config(target);
    //hexagon breakpoint config setup    

    if((isdben == 0x0) && (isdbver == 0x0) &&  (corever == 0x0))
    {
        LOG_ERROR("Not able to communicate with device , Reboot the device and try again");
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

    hexagon_hw_watchdog_disable(target);
    // LOG_INFO("checking STEP latency issues");
    //hexagon_populate_vtlb_data(target);
    return ERROR_OK;
}


static int hexagon_examine(struct target *target)
{
    int retval = ERROR_OK;

    LOG_DEBUG("hexagon_examine() ");
        
    /* don't re-probe hardware after each reset */
    if (!target_was_examined(target))
        retval = hexagon_examine_first(target);
    
    return retval;
}


static int hexagon_brkpt_setup(struct hexagon_common *hexagon)
{
    int retval = ERROR_OK;

    

    
    return retval;
}


static int hexagon_reg_setup(struct hexagon_common *hexagon)
{
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct hexa_reg *reg = &hexa_info->reg;
    struct target *target = hexa_info->target;
    struct reg_cache *cache;
    struct reg_cache *list = NULL;
    int retval = ERROR_OK;
    uint32_t i;

    

    if (hexa_info->core_cache != NULL)
    {
        LOG_DEBUG("registers are already built...so skipping");
        return ERROR_OK;
    }

    /* no of Hw threads reg + 1 global reg */
    for (i = 0; i <= hexa_info->config.maxHwThreads; i++)
    {
        if ((cache = hexagon_build_reg_cache(target,i)) == NULL)
                return ERROR_FAIL;

        cache->name = hexa_info->config.pThreadNameArray[i];
        LOG_DEBUG("hexagon thread name [i] = %s", hexa_info->config.pThreadNameArray[i]);
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


static int hexagon_get_core_reg(struct reg *reg)
{
    struct hex_reg *arch_info = reg->arch_info; 
    struct target *target = arch_info->target;
    struct hexagon_arch_info *hexa_info = arch_info->hexa_info;

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
    struct hexagon_arch_info *hexa_info = arch_info->hexa_info;
    uint32_t value;
    

    memcpy(&value, buf, 4);
    
    // LOG_INFO("set_core_reg: target state %d, hw-thrd %d, reg %d, value 0x%x",
    //                     target->state, arch_info->hwthrd, arch_info->num, value);
    
    if (target->state != TARGET_HALTED)
        return ERROR_TARGET_NOT_HALTED;

    return hexa_info->write_core_reg(target, arch_info->num, arch_info->hwthrd, value);  
}


/** Builds cache of architecturally defined registers.  */
struct reg_cache *hexagon_build_reg_cache(struct target *target, uint32_t hwthrd)
{
    struct hexagon_common *hexa_common = target_to_hexagon(target);
    struct hexagon_arch_info *hexa = &hexa_common->hexa_info;
    int num_regs;
    struct reg_cache **cache_p = register_get_last_cache_p(&target->reg_cache);
    struct reg_cache *cache;
    struct reg *reg_list;
    struct hex_reg *arch_info;
    struct reg_feature *feature;
    int i;
    
    LOG_DEBUG("hexagon_build_reg_cache enter");
    /* Build the process context cache */
    cache = malloc(sizeof(struct reg_cache));

    if (hwthrd == hexa->config.maxHwThreads+1)
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
            arch_info[i].hwthrd = hexa->config.maxHwThreads;
            arch_info[i].target = target;
            arch_info[i].hexa_info= hexa;
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
            reg_list[i].caller_save = true;    /* gdb defaults to true */
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

        LOG_DEBUG("hexagon_build_reg_cache global reg allocation done");
            
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
            arch_info[i].hexa_info= hexa;
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
            reg_list[i].caller_save = true;    /* gdb defaults to true */
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
            } else
                LOG_DEBUG("unable to allocate reg type list");
            
             }
        
            LOG_DEBUG(" hexagon_build_reg_cache per thread allocation done");
    }

    LOG_DEBUG("hexagon_build_reg_cache exit");

    (*cache_p) = cache;
    return cache;
}


struct reg *hexagon_reg_current(struct hexagon_arch_info *hexa_info, unsigned int regnum,  struct reg_cache *cache)
{
    struct reg *r;

    if (regnum >= HEXAGON_MMODE_GLOBAL_MAX)
        return NULL;
    
    r = cache->reg_list + regnum;  //TDB for all Hw threads.
    return r;
}


static int hexagon_write_core_reg(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval=ERROR_OK;
    uint64_t i;


    

    if (regnum < HEXAGON_R0 || regnum >= HEXAGON_MMODE_GLOBAL_MAX)
        return ERROR_COMMAND_SYNTAX_ERROR;

    #ifdef  _DEBUG_HEXAGON_
        LOG_DEBUG("hexagon_write_core_reg: %d, Thrd: %d, value %d", regnum, hwthrd, value);    
    #endif

    /* Get the register of the requested Hw thread */
    cache = hexa_info->core_cache;
    i= 0;
    while ((cache != NULL) && i < hwthrd)
    {
        cache = cache->next;
        i++;
    }

    /* update the register value locally */
    *((uint8_t*)cache->reg_list[regnum].value) = value;
    cache->reg_list[regnum].dirty = true;
    cache->reg_list[regnum].valid = true;

    #ifdef  _DEBUG_HEXAGON_
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


int hexagon_sync(struct target *target,uint32_t hwthrd)
{
    uint32_t isdb_mmode_cmd, isdbsts,retval;
    uint64_t stuff_inst[] = {0xa840c000,  0x56c0d000, 0x57c0c002 };
    //{0xa840c000 -->{syncht }, 0x56c0d000 -->{ickill}, 0x57c0c002 -->{isync} }
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;

    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
                                                ISDBCMD_TNUM_MASK_THREAD(hwthrd));

    

    for (int i = 0; i < 2; i++) 
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
        retval = isdbsts & ISDBST_ISDB_CMD_STATUS;
        if (retval!=ERROR_OK)
        {
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            return ERROR_FAIL;
        }
    }
    
    return ERROR_OK;
}


static int hexagon_write_global_ctrl_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval , i=0;
    uint32_t isdbsts;
    uint32_t isdb_mmode_cmd;

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_write_global_ctrl_register: hw thrd: %d, regnum %d, value %d", hwthrd, regnum, value);
    #endif

    if ((regnum == HEXAGON_MODECTL) || (regnum == HEXAGON_S19_RESRV) || (regnum == HEXAGON_IPENDAD) || 
        (regnum >= HEXAGON_S24_RESRV && regnum <= HEXAGON_CFGBASE) || ((regnum == HEXAGON_REV)))
    {
        LOG_DEBUG("Invalid: reserved/readonly register : %d", regnum);
        return ERROR_FAIL;
    }
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
    #endif
    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
                                            ISDBCMD_TNUM_MASK_THREAD(hwthrd));

    /* run the 1st instruction */
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);
    if (retval != ERROR_OK) {
        LOG_DEBUG("ISDBST read failed 0x%x", isdbsts);
    }
    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("ISDB status before ISDBMBXIN write 0x%x", isdbsts);
    #endif
    

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);
    if (retval != ERROR_OK) {
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN_CDSP return value is not OK");
    }

    //  ensure that regnum-HEXAGON_SGP0 is not out of bounds before accessing it
    if ((regnum - HEXAGON_SGP0) >= 0 && (regnum - HEXAGON_SGP0) < 16) {

        retval = hexagon_isdb_cmd_status(target, stuff_inst_global_reg_write[regnum-HEXAGON_SGP0][0],isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            return ERROR_OK;
        }
    } else {
        LOG_ERROR("Array index out of bounds: %d", regnum - HEXAGON_SGP0);
    }

        if (isdbsts & ISDBST_ISDB_MAILBOX_IN)
        {
            i = 0;
            while (isdbsts & ISDBST_ISDB_MAILBOX_IN)
            {

                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

                hexagon_wait_loop();
                #ifdef  _DEBUG_HEXAGON_
                LOG_DEBUG("ISDB status read for Mboxin %d time", i);
                #endif
                i++;
                if (i == HEXAGON_MAX_REG_RETRY)
                    break;
            }
            if(isdbsts & ISDBST_ISDB_MAILBOX_IN)
            {
                LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, so write failure for register R%d", regnum);
                return     ERROR_FAIL;    
            }
        }
        /* run the 2nd instruction */
        if ((regnum - HEXAGON_SGP0) >= 0 && (regnum - HEXAGON_SGP0) < 16) {

        retval = hexagon_isdb_cmd_status(target, stuff_inst_global_reg_write[regnum - HEXAGON_SGP0][1],isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBcommand failed in monitor mode");
            return ERROR_OK;
            }

        } else {
            LOG_ERROR("Array index out of bounds: %d", regnum - HEXAGON_SGP0);
        }

    global_reg[regnum-HEXAGON_EVB]  = value;
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif


    
    return ERROR_OK;
}


static int hexagon_write_ctrl_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval , i=0;
    uint32_t isdbsts;
    uint32_t isdb_mmode_cmd;

    #ifdef  _DEBUG_HEXAGON_
    LOG_DEBUG("hexagon_write_ctrl_register: hw thrd: %d, regnum %d, value 0x%x", hwthrd, regnum, value);
    #endif

    if ((regnum == HEXAGON_C5_RESRV) || (regnum >= HEXAGON_C20_RESRV && regnum <= HEXAGON_C20_RESRV))
    {
        LOG_DEBUG("Invalid: reserved register : %d", regnum);
        return ERROR_FAIL;
    }

    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
                    ISDBCMD_TNUM_MASK_THREAD(hwthrd));

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);
    if (retval != ERROR_OK) {
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXIN return value is not OK");
    }

    retval = hexagon_isdb_cmd_status(target, stuff_inst_ctrl_reg_write[regnum-HEXAGON_SA0][0],isdb_mmode_cmd);
    if (retval != ERROR_OK){
        LOG_DEBUG("ISDBcommand failed in monitor mode");
         return ERROR_OK;
    }
    else
    {    
        if(isdbsts & ISDBST_ISDB_MAILBOX_IN)
        {
            i = 0;
            while(isdbsts & ISDBST_ISDB_MAILBOX_IN)
            {
                retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

                hexagon_wait_loop();
                #ifdef  _DEBUG_HEXAGON_
                    LOG_DEBUG("ISDB status read for Mboxin 0x%x time", isdbsts);
                #endif
                    
                i++;
                if (i == HEXAGON_MAX_REG_RETRY)
                    break;
            }
            if(isdbsts & ISDBST_ISDB_MAILBOX_IN)
            {
                LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, write failure for register R%d", regnum);
                return     ERROR_FAIL;
            }
        }

        retval = hexagon_isdb_cmd_status(target, stuff_inst_ctrl_reg_write[regnum-HEXAGON_SA0][1],isdb_mmode_cmd);
        if (retval != ERROR_OK){
            LOG_DEBUG("ISDBcommand failed in monitor mode");
             return ERROR_OK;
        }
    }
    hexa_info->pPerHwThrdReg[hwthrd][regnum] = value;
    
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif


    
    return ERROR_OK;
}


static int hexagon_write_gpr_register(struct target *target, int regnum, uint32_t hwthrd, uint32_t value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval , i=0;
    uint32_t isdbsts;
    uint32_t isdb_mmode_cmd;

    #ifdef  _DEBUG_HEXAGON_
        LOG_DEBUG("hexagon_write_gpr_register: hw thrd: %d, regnum %d, value 0x%x", hwthrd, regnum, value);
    #endif

    isdb_mmode_cmd = hexagon_pack_isdbcmd(ISDBCMD_CMD_STUFF, ISDBCMD_MONITOR_LVL,
                                            ISDBCMD_TNUM_MASK_THREAD(hwthrd));

    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_start_time_cal_ms();
    #endif
    
    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);
    if (retval != ERROR_OK) {
        LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
    }

    retval = hexagon_poll_mbxin(target);
    if (retval != ERROR_OK){
        LOG_DEBUG("ISDB MBX_IN not found to be full");
    }

    retval = hexagon_isdb_cmd_status(target, stuff_inst_gpr_write[regnum],isdb_mmode_cmd);

    /* if isdb_cmd_status 0 in cmd was successfull in case of 1 failed */ 
    // isdb_cmd_status = isdbsts & ISDBST_ISDB_CMD_STATUS;

    if (retval != ERROR_OK){
         LOG_DEBUG("ISDBcommand failed");
         return ERROR_OK;
    }

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
            hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

    if(isdbsts & ISDBST_ISDB_MAILBOX_IN)
    {
        i = 0;
        while (isdbsts & ISDBST_ISDB_MAILBOX_IN)
        {
            retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

            hexagon_wait_loop();
            #ifdef  _DEBUG_HEXAGON_
                LOG_DEBUG("ISDB status read for Mboxin 0x%x time", isdbsts);
            #endif 
                
            i++;
            if (i == HEXAGON_MAX_REG_RETRY)
                break;
        }
        if(isdbsts & ISDBST_ISDB_MAILBOX_IN)
        {
            LOG_DEBUG("ISDBST status not cleared for ISDBMBXIN, write failure for register R%d", regnum);
            return     ERROR_FAIL;    
        }
    }
    hexa_info->pPerHwThrdReg[hwthrd][regnum] = value;
    #ifdef  _HEXAGON_TARGET_TIME_PROFILING
        hexagon_end_time_cal_ms();
        LOG_DEBUG("Total time taken  %" PRId64 "ms", hexagon_time_total);
    #endif

    
    return ERROR_OK;
}


static int hexagon_read_core_reg(struct target *target, struct reg *r, int regnum, uint32_t hwthrd)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache;
    int retval=ERROR_OK;
    uint64_t i;

    

    // LOG_INFO("reading reg:%d, hw_thrd %d ", regnum, hwthrd);

    if (regnum < 0 || regnum >= HEXAGON_MMODE_GLOBAL_MAX)
        return ERROR_COMMAND_SYNTAX_ERROR;

    /* Read the register of the requested Hw thread */
    cache = hexa_info->core_cache;
    i= 0;
    while ((cache->next != NULL) && i < hwthrd)
    {
        cache = cache->next;
        i++;
    }
    r->value = (uint8_t*) cache->reg_list[regnum].value;
    r->valid = true;
    r->dirty = false;


    
    return retval;
}


static int hexagon_init_target(struct command_context *cmd_ctx,
    struct target *target)
{
    LOG_DEBUG(" hexagon_init_target");
    return ERROR_OK;
}


static void hexagon_deinit_target(struct target *target)
{

    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    struct reg_cache *cache, *cache1;
    

    free(hexagon->brp_list);
    free(target->private_config);
    
     cache = cache1= hexa_info->core_cache;
    while(cache != NULL)
    {
        free(cache->reg_list->arch_info);
        free(cache->reg_list);
        cache1 = cache->next;
        free(cache);
        cache = cache1;
    }
    free(hexa_info->core_cache);
    
    free(hexagon);
    deinitConfig(hexa_info);
    
    if(hexagon_vtlb_entries)
        free(hexagon_vtlb_entries);
}

/* Function to read ISDBST register */
static int hexagon_read_ISDBST(struct target *target, uint32_t *isdbst)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval;

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                hexa_info->debug_base + HEXAGON_ISDB_ISDBST, isdbst);

    if (retval != ERROR_OK) {
        LOG_DEBUG("HEXAGON_ISDB_ISDBST read failed, retval=%d", retval);
        return retval;
    }

    LOG_DEBUG("HEXAGON_ISDB_ISDBST value: 0x%08x", *isdbst);
    return ERROR_OK;
}

static int hexagon_mmu(struct target *target, int *enabled)
{
    uint64_t syscfg,retval;

    retval = hexagon_read_syscfg_register(target);
    hexagon_stuff_reg_restore(target);
    if(retval == ERROR_OK)
        syscfg= hexagon_syscfg_reg;
    else
        syscfg = global_reg[2];

    struct hexagon_mmu_common * mmu = (struct hexagon_mmu_common *)&(target_to_hexagon(target)->hexa_info.hexagon_mmu);
    
    if (target->state != TARGET_HALTED) {
        LOG_DEBUG("%s: target %s not halted", __func__, target_name(target));
        return ERROR_TARGET_INVALID;
    }
    LOG_DEBUG("SYSCFG register is  0x%llx", syscfg);
    if(syscfg & 1){
        mmu->mmu_enabled = true;
    }
    
    if(syscfg & (1<<1))
        mmu->instrution_cache_enabled = 1;
    if(syscfg & (1<<2))
        mmu->data_cache_enabled = 1;
    
    *enabled = target_to_hexagon(target)->hexa_info.hexagon_mmu.mmu_enabled;

    return ERROR_OK;
}


/* This function is used to restore r0, r1, r2 and r7 used during stuff instrcution*/
// static void hexagon_stuff_reg_restore(struct target *target)
static void hexagon_stuff_reg_restore(struct target *target)
{
    int retval;
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    
    if(hexagon_r0_used_stuff)
    {
        retval = hexagon_write_gpr_register(target, HEXAGON_R0, HEXAGON_HW_THREAD0, 
                                            hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R0]);
        if(retval == ERROR_OK)
            hexagon_r0_used_stuff = 0;
        else
        {
            retval = hexagon_write_gpr_register(target, HEXAGON_R0, HEXAGON_HW_THREAD0, 
                                            hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R0]);
            if(retval == ERROR_OK)
                hexagon_r0_used_stuff = 0;
            else 
                LOG_DEBUG("Error occured during restoring R0 value used for stuff ");
        }
    }
    if(hexagon_r1_used_stuff)
    {
        retval = hexagon_write_gpr_register(target, HEXAGON_R1, HEXAGON_HW_THREAD0, 
                                       hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R1]);
        if(retval == ERROR_OK)
            hexagon_r1_used_stuff = 0;
        else
        {
            retval = hexagon_write_gpr_register(target, HEXAGON_R1, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R1]);
            if(retval == ERROR_OK)
                hexagon_r1_used_stuff = 0;
            else
                LOG_DEBUG("Error occured during restoring R1 value used for stuff ");
        }
    }
    if(hexagon_r2_used_stuff)
    {
        retval = hexagon_write_gpr_register(target, HEXAGON_R2, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R2]);
        if(retval == ERROR_OK)
            hexagon_r2_used_stuff = 0;
        else
        {
            retval = hexagon_write_gpr_register(target, HEXAGON_R2, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R2]);
            if(retval == ERROR_OK)
                hexagon_r2_used_stuff = 0;
            else
                LOG_DEBUG("Error occured during restoring R2 value used for stuff ");
        }
    }
    if(hexagon_r7_used_stuff)
    {
        retval= hexagon_write_gpr_register(target, HEXAGON_R7, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R7]);
        if(retval == ERROR_OK)
            hexagon_r7_used_stuff = 0;
        else
        {
            retval= hexagon_write_gpr_register(target, HEXAGON_R7, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_R7]);
            if(retval == ERROR_OK)
                hexagon_r7_used_stuff = 0;
            else
                LOG_DEBUG("Error occured during restoring R7 value used for stuff ");
        }
    }
    if(hexagon_r30_used_stuff)
    {
        retval= hexagon_write_gpr_register(target, HEXAGON_FP, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_FP]);
        if(retval == ERROR_OK)
            hexagon_r30_used_stuff = 0;
        else
        {
            retval= hexagon_write_gpr_register(target, HEXAGON_FP, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_FP]);
            if(retval == ERROR_OK)
                hexagon_r30_used_stuff = 0;
            else
                LOG_DEBUG("Error occured during restoring R7 value used for stuff ");
        }
    }
    if(hexagon_r31_used_stuff)
    {
        retval= hexagon_write_gpr_register(target, HEXAGON_LR, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_LR]);
        if(retval == ERROR_OK)
            hexagon_r31_used_stuff = 0;
        else
        {
            retval= hexagon_write_gpr_register(target, HEXAGON_LR, HEXAGON_HW_THREAD0, 
                                        hexa_info->pPerHwThrdReg[HEXAGON_HW_THREAD0][HEXAGON_LR]);
            if(retval == ERROR_OK)
                hexagon_r31_used_stuff = 0;
            else
                LOG_DEBUG("Error occured during restoring R7 value used for stuff ");
        }
    }
    
}


/*================================================================*/
/*hexagon-untrusted code changes*/
/*================================================================*/
int hexagon_untrusted_update_packet(struct target *target, char *packet, int len)
{
    int retval;
    struct hexagon_common *hexagon = target_to_hexagon(target);

    if (packet == NULL)
        return ERROR_FAIL;
    // Adding initial $ to each RSP packet
    hexagon->untrusted_current_state.current_packet[0] = '$';
    for (int i = 1; i <= len; i++)
    {
        hexagon->untrusted_current_state.current_packet[i] = packet[i - 1];
    }
    hexagon->untrusted_current_state.packet_len = len + 1;
    // Updating the end of the string in the RSP packet
    hexagon->untrusted_current_state.current_packet[len + 1] = '\0';
    hexagon->untrusted_current_state.has_packet = true;
    if (hexagon->untrusted_current_state.has_checksum)
    {
        retval = hexagon_untrusted_concat_rsp(hexagon);
        if (retval != ERROR_OK)
            return retval;
    }
    // LOG_INFO("Hexagon untrusted RSP packet : %s\n",hexagon_untrusted_current_state.current_packet);
    return ERROR_OK;
}


/* function hexagon_untrusted_update_packet_checksum
 * args:
 * checksum : it contains the checksum recieved on GDB connection
 *             for the RSP packet.
 */
int hexagon_untrusted_update_packet_checksum(struct target *target, char *checksum)
{
    int retval = 0;
    struct hexagon_common *hexagon = target_to_hexagon(target);

    // LOG_INFO("Hexagon untrusted RSP packet checksum entered\n");

    hexagon->untrusted_current_state.current_checksum[0] = checksum[0];
    hexagon->untrusted_current_state.current_checksum[1] = checksum[1];
    hexagon->untrusted_current_state.has_checksum = true;
    if (hexagon->untrusted_current_state.has_packet)
    {
        retval = hexagon_untrusted_concat_rsp(hexagon);
    }
    // LOG_INFO("Hexagon untrusted RSP packet checksum  exit: %c%c\n",checksum[0],checksum[1]);
    if (retval != ERROR_OK)
        LOG_DEBUG("rsp concatentation failed");
    return ERROR_OK;
}


/* function hexagon_untrusted_concat_rsp
 * This function will concatinate the packet and Checksum
 *    packet after this function will look like in this format
 *    $<packet>#<checksum>
 */
int hexagon_untrusted_concat_rsp(struct hexagon_common *hexagon)
{
    // LOG_DEBUG("Hexagon untrusted concatinated the RSP entered\n");

    if (!(hexagon->untrusted_current_state.has_checksum &&
          hexagon->untrusted_current_state.has_packet))
    {
        LOG_DEBUG("Hexagon untrusted RSP packet or checksum not available\n");
        return ERROR_FAIL;
    }
    int len = hexagon->untrusted_current_state.packet_len;
    hexagon->untrusted_current_state.current_packet[len] = '#';

    hexagon->untrusted_current_state.current_packet[len + 1] =
        hexagon->untrusted_current_state.current_checksum[0];
    hexagon->untrusted_current_state.current_packet[len + 2] =
        hexagon->untrusted_current_state.current_checksum[1];
    hexagon->untrusted_current_state.current_packet[len + 3] = '\0';

    hexagon->untrusted_current_state.packet_len = len + 3;
    hexagon->untrusted_current_state.has_packet = false;
    hexagon->untrusted_current_state.has_checksum = false;
    hexagon->untrusted_current_state.has_rsp = true;
    // LOG_DEBUG("Hexagon untrusted concatinated the RSP : %s\n",
    //                        hexagon_untrusted_current_state.current_packet);

    return ERROR_OK;
}


/* function hexagon_untrusted_write_to_mailboxin
 * writes the 32bit value to the mailboxin register
 * args:
 * target : target variable for accessing the connected target
 * val : value which need to written on the register
 */
int hexagon_untrusted_write_to_mailboxin(struct target *target, uint32_t value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval;
    uint32_t isdbst_after = 0x0;
    uint32_t isdbsts = 0x0;

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

    // retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
    //                                 hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, &isdbmbx);

    // LOG_INFO("ISDBMBX before write to mailbox : 0x%x", isdbmbx);
    LOG_DEBUG("ISDBSTS before write to mailbox : 0x%x", isdbsts);

    retval = mem_ap_write_atomic_u32(hexa_info->debug_ap,
                                     hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXIN, value);


    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBCMD return value is not OK");
        return retval;
    }


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
int hexagon_untrusted_read_to_mailboxout(struct target *target, uint32_t *value)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    int retval;
    uint32_t isdbsts;

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

    LOG_DEBUG("ISDBSTS before read from mailboxout : 0x%x", isdbsts);

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBMBXOUT, value);
    

    if (retval != ERROR_OK)
    {
        LOG_DEBUG("HEXAGON_ISDB_ISDBMBXOUT read failed 0x%x", *value);
        return retval;
    }
    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST, &isdbsts);

    

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
    value |= header.payload_len;
    value = (value << 8) | header.header_len;
    value = (value << 8) | header.protocol;

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
int hexagon_untrusted_poll_isdbst_set_bit(struct target *target, uint8_t bit)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
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
int hexagon_untrusted_poll_isdbst_unset_bit(struct target *target, uint8_t bit)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
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
uint64_t min_u(uint64_t a, uint64_t b)
{
    if (a > b)
        return b;
    return a;
}


/*function
 */
int send_isdb_interrupt(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;
    uint32_t isdb_mmode_cmd = ISDBCMD_CMD_INTRPT | ISDBCMD_MONITOR_LVL;
    uint32_t isdb_cmd_status, isdbsts;
    int retval;

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
    return ERROR_OK;
}


/*function
 */
int hexagon_untrusted_listen_for_rsp(struct target *target, char *s, uint16_t *res_len)
{
    int retval, i = 0;
    uint32_t read_val;
    uint64_t calculated_checksum = 0;
    uint32_t mbxOutVal;
    uint32_t isdbsts = 0;
    untrusted_essential *header;
    struct hexagon_common *hexagon = target_to_hexagon(target);
    struct hexagon_arch_info *hexa_info = &hexagon->hexa_info;


    // fix for checksum mismatch
# if 1
    /* Read the essential header */
    LOG_DEBUG("Reading the essential header...\n");

    retval = mem_ap_read_atomic_u32(hexa_info->debug_ap,
                                    hexa_info->debug_base + HEXAGON_ISDB_ISDBST,  &isdbsts);
    LOG_DEBUG("ISDBST before poll 0x%x", isdbsts);

    retval = hexagon_untrusted_poll_isdbst_unset_bit(target, ISDBST_ISDB_MAILBOX_OUT);
    LOG_DEBUG("ISDBST after poll 0x%x", isdbsts);
#endif


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
        // if(qurt_context.selected_process != read_val){
        //     LOG_DEBUG("Process id is not same!\n");
        //     // return ERROR_FAIL;
        // }
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
        LOG_DEBUG("Error in reading. Checksum don't match!!! read_val : 0x%x calculated_checksum : 0x%llx \n",read_val,calculated_checksum );
        
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
    uint16_t number_of_payload_packets = len / ISDBMAILBOX_SIZE;
    uint32_t pid_s = 0;
    uint32_t rsp_v;
    int retval;
    uint32_t write_value;
    uint32_t buffer, stride;
    uint32_t cha;
    uint16_t i = 0;
    int p = 0;
    uint32_t calculated_checksum = 0;
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

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

    LOG_DEBUG("Packet to be converted is %s",rsppkt);

    // Initializing the payload data structure
    payload->len = number_of_payload_packets;
    payload->bytes_to_read = len;
    payload->payload = (uint32_t *)malloc(sizeof(uint32_t) * number_of_payload_packets);
    
    while (i < payload->bytes_to_read)
    {
        stride = min_u(ISDBMAILBOX_SIZE, payload->bytes_to_read - i);
        buffer = 0x0;
        for (uint32_t j = 0; j < stride; j++)
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
        pid_s = qurt_context->selected_process;
        // LOG_DEBUG("PID set to : %lld",pid_s);
    }


    essential_header->payload_len = payload->bytes_to_read;
    /*Sending the essential header to the ISDBMBXIN*/
    // waiting if already content there
    // retval=hexagon_untrusted_poll_isdbst_set_bit(target,0x2);
    write_value = hexagon_untrusted_convert_essential_header(*(essential_header));
    retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);

    // write crash
    LOG_DEBUG("writing to isdb value 0x%x",write_value);
    retval = hexagon_untrusted_write_to_mailboxin(target, write_value);
    
    

    calculated_checksum += (write_value & 0xff) + ((write_value >> 8) & 0xff) + ((write_value >> 16) & 0xff) + ((write_value >> 24) & 0xff);
    if (retval != ERROR_OK)
    {
        LOG_DEBUG("Unable to send packet on the ISDBMBXIN channel\n");
        return retval;
    }

    retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);
    // write crash
    LOG_DEBUG("writing to isdb value 0x%x",pid_s);
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

        // write crash
        LOG_DEBUG("writing to isdb value 0x%x",rsp_v);
        retval = hexagon_untrusted_write_to_mailboxin(target, rsp_v);
        
        

        calculated_checksum += (rsp_v & 0xff) + ((rsp_v >> 8) & 0xff) + ((rsp_v >> 16) & 0xff) + ((rsp_v >> 24) & 0xff);
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("Unable to send packet on the ISDBMBXIN channel\n");
            return retval;
        }
    }

    
    /*Sending the RSP packet as the payload*/
    for (i = 0; i < payload->len; i++)
    {
        write_value = payload->payload[i];


        retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);

        // write crash
        LOG_DEBUG("writing to isdb value 0x%x",write_value);
        retval = hexagon_untrusted_write_to_mailboxin(target, write_value);
        
        

        calculated_checksum += (write_value & 0xff) + ((write_value >> 8) & 0xff) + ((write_value >> 16) & 0xff) + ((write_value >> 24) & 0xff);
        // // 
        if (retval != ERROR_OK)
        {
            LOG_DEBUG("Unable to send packet on the ISDBMBXIN channel\n");
            return retval;
        }
    }

    /* Sending checksum value */
    calculated_checksum = calculated_checksum % 256;
    retval = hexagon_untrusted_poll_isdbst_set_bit(target, ISDBST_ISDB_MAILBOX_IN);
    // write crash

    LOG_DEBUG("writing to isdb value 0x%x",calculated_checksum);
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
    return strtoul(s + index, NULL, 16);
}


static int load_process_list(char *process_list_response, struct qurt_context_t *qurt_context)
{
    char *ret;
    char *pid_index;
    char *comma_index;
    char *scolon_index;
    char p[16];

    qurt_context->selected_process = -1;
    int r=0x0;
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
            qurt_context->process_list[qurt_context->total_process].pid = convert_to_int(p);
            scolon_index = strchr(comma_index, ':');
            r = strlen(scolon_index) - 1;
            memcpy(qurt_context->process_list[qurt_context->total_process].process_name, scolon_index + 1, r);
            qurt_context->process_list[qurt_context->total_process].process_name[r] = '\0';
            qurt_context->total_process++;
        }
        token = strtok(NULL, ";");
    }
    printf("====================Process Selection Menu====================\n");
    printf("\tProcess Id\tProcess Name\n");


    for (int i = 0; i < qurt_context->total_process; i++)
    {
        printf("\t%u\t\t%s\n", qurt_context->process_list[i].pid, qurt_context->process_list[i].process_name);
    }
    for (int i = 0; i < qurt_context->total_process; i++) 
    {

        if (strcmp(qurt_context->process_list[i].process_name, "_ASID0_") != 0) 
        {
            qurt_context->selected_process = qurt_context->process_list[i].pid;
            LOG_INFO("Selected process to debug is: %s pid : %d \n", qurt_context->process_list[i].process_name, qurt_context->process_list[i].pid);
            break;
        }
    }
    
    if (qurt_context->selected_process == -1)
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
    struct hexagon_common *hexagon = target_to_hexagon (target);
    struct qurt_context_t *qurt_context = &hexagon->qurt_context;

    LOG_DEBUG("untrusted rsp packet forwarding");
    if (!hexagon->untrusted_current_state.has_rsp)
    {
        LOG_DEBUG("RSP packet is not available to forward\n");
        return ERROR_FAIL;
    }
    if (strncmp(hexagon->untrusted_current_state.current_packet, "$QStartNoAckMode", 16) == 0)
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
        retval = load_process_list(s, qurt_context);
        for (int i = 0; i < qurt_context->total_process; i++)
        {
            if (qurt_context->hexagon_debug_process_id ==  qurt_context->process_list[i].pid)
            {
                LOG_DEBUG("Process ID to debug is : %d\n", qurt_context->process_list[i].pid);
                break;
            }
        }
    }
    len = hexagon->untrusted_current_state.packet_len;
    // (char *) and char (*)[1024] point to the start address of the array
    // Cast the address of the array to char * to match the function's expected parameter type
    retval = hexagon_untrusted_send_rsp(target, (char *)&(hexagon->untrusted_current_state.current_packet), len, response, response_len, 1);

    hexagon->untrusted_current_state.has_rsp = false;
    hexagon->untrusted_current_state.has_packet = false;
    hexagon->untrusted_current_state.has_checksum = false;
    return ERROR_OK;
}


int hexagon_untrusted_mode(struct hexagon_common *hexagon)
{
    hexagon->is_hexagon_untrusted = true;
    LOG_DEBUG("Mode changed to hexagon untrusted!\n");
    return ERROR_OK;
}

bool is_hexagon_mode_untrusted(struct target *target)
{
    if (strcmp(target->type->name, "hexagon") == 0)
    {
        struct hexagon_common *hexagon = target_to_hexagon (target);
        // struct hexagon_arch_info *hexa_infoA = &hexagon->hexa_info;
        return hexagon->is_hexagon_untrusted; 
    }

    return false;
}

bool hexagon_is_spurious_breakpoint(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    return hexagon->hexa_info.is_spurious_breakpoint;
}


void hexagon_clear_spurious_breakpoint_flag(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    hexagon->hexa_info.is_spurious_breakpoint = 0;
}

int hexagon_thread_id_thread_select(struct target *target)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    return hexagon->hexa_info.thread_id_thread_select + 1;

}
void hexagon_breakpoint_address_thread_select(struct target *target, uint64_t address)
{
    struct hexagon_common *hexagon = target_to_hexagon(target);
    hexagon->hexa_info.breakpoint_address_thread_select = address;

}

struct target_type hexagon_target = {
    .name = "hexagon",
    .poll = hexagon_poll,
    .arch_state = hexagon_arch_state,
    .target_request_data  = NULL,
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
    .address_bits = NULL
};
