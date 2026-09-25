/***************************************************************************
 *   Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.    *
 *   All rights reserved.                                                  *
 *   Confidential and Proprietary - Qualcomm Technologies, Inc.            *
 ***************************************************************************/

/***************************************************************************
 *   QuRT (Hexagon) RTOS awareness - register stacking builder             *
 *                                                                         *
 *   Translates the runtime-resolved QuRT TCB context offsets into a       *
 *   struct rtos_register_stacking that rtos_generic_stack_read() can use  *
 *   to recover a software thread's register set for unwinding.            *
 *                                                                         *
 *   Unlike a classic RTOS stacking (registers saved on the thread stack), *
 *   QuRT stores the saved context inside the TCB at fixed offsets. We      *
 *   therefore set stack_growth_direction such that no auto-adjust of the  *
 *   "stack pointer" is done, and we feed the TCB pointer in as the        *
 *   "stack pointer" so each register offset is read relative to the TCB.  *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "rtos.h"
#include "rtos_qurt_stackings.h"
#include "helper/log.h"

/*
 * NOTE: stacking->stack_registers_size is a uint8_t (max 255) in
 * struct rtos_register_stacking, but the QuRT TCB register offsets extend
 * past 255 (r4/r5 at 280/284). Therefore qurt_get_thread_reg_list() does
 * NOT use rtos_generic_stack_read(); it reads each register directly from
 * the TCB. This field is consequently unused for QuRT, so we set it to a
 * benign in-range value purely to populate the struct (avoids the uint8_t
 * overflow warning that a 512 literal would trigger).
 */
#define QURT_TCB_CONTEXT_READ_SIZE   255

/*
 * register layout:
 *   IMPORTANT - the QuRT TCB does NOT store r0..r31 as a contiguous block.
 *   The registers are saved as 64-bit pairs scattered across the TCB at the
 *   byte offsets listed in osam/hexagon_sim/include/consts_autogen.h
 *   (CONTEXT_r0100, CONTEXT_r0302, CONTEXT_r0504, ...). The pair bases are
 *   NOT monotonic, so a simple "r0100 + 4*k" formula is wrong.
 *
 *   This table is the per-register byte offset from the TCB base, taken
 *   verbatim from consts_autogen.h (QURT Kernel ver. 04.05.08, SIZEOF_TCB
 *   = 448). Each pair "rNNMM" places the even register at base+0 and the
 *   odd register at base+4:
 *     r0100=200 r0302=192 r0504=280 r0706=272 r0908=152 r1110=144
 *     r1312=136 r1514=128 r1716=112 r1918=104 r2120=96  r2322=88
 *     r2524=264 r2726=256 r2928=80  r3130=72
 *   sp = r29 = r2928+4 = 84, fp = r30 = r3130 = 72, lr = r31 = r3130+4 = 76,
 *   pc = elr = ssrelr = 64.
 *
 * We express every register offset relative to the TCB base (fed in as the
 * "stack pointer"), with calculate_process_stack = NULL so the generic
 * reader treats the supplied pointer as the read base.
 */

static const uint16_t QURT_REG_WIDTH_BITS = 32;

/* Byte offset of each Hexagon GP register r0..r31 within the QuRT TCB.
 * Indexed by register number. Mirrors consts_autogen.h CONTEXT_rNNMM. */
static const signed short qurt_tcb_reg_offset[32] = {
	[QURT_HEX_R0]  = 200,
	[QURT_HEX_R1]  = 204,
	[QURT_HEX_R2]  = 192,
	[QURT_HEX_R3]  = 196,
	[QURT_HEX_R4]  = 280,
	[QURT_HEX_R5]  = 284,
	[QURT_HEX_R6]  = 272,
	[QURT_HEX_R7]  = 276,
	[QURT_HEX_R8]  = 152,
	[QURT_HEX_R9]  = 156,
	[QURT_HEX_R10] = 144,
	[QURT_HEX_R11] = 148,
	[QURT_HEX_R12] = 136,
	[QURT_HEX_R13] = 140,
	[QURT_HEX_R14] = 128,
	[QURT_HEX_R15] = 132,
	[QURT_HEX_R16] = 112,
	[QURT_HEX_R17] = 116,
	[QURT_HEX_R18] = 104,
	[QURT_HEX_R19] = 108,
	[QURT_HEX_R20] =  96,
	[QURT_HEX_R21] = 100,
	[QURT_HEX_R22] =  88,
	[QURT_HEX_R23] =  92,
	[QURT_HEX_R24] = 264,
	[QURT_HEX_R25] = 268,
	[QURT_HEX_R26] = 256,
	[QURT_HEX_R27] = 260,
	[QURT_HEX_R28] =  80,
	[QURT_HEX_R29] =  84,   /* sp */
	[QURT_HEX_R30] =  72,   /* fp */
	[QURT_HEX_R31] =  76,   /* lr */
};

int qurt_build_hexagon_stacking(const struct qurt_context_offsets *off,
		struct rtos_register_stacking *stacking,
		struct stack_register_offset *reg_offsets)
{
	if (!off || !off->valid || !stacking || !reg_offsets) {
		LOG_ERROR("qurt: cannot build stacking - offsets not resolved");
		return ERROR_FAIL;
	}

	/* r0 .. r31 from the explicit (non-contiguous) TCB offset table. */
	for (int k = 0; k <= 31; k++) {
		reg_offsets[k].number     = (unsigned short)(QURT_HEX_R0 + k);
		reg_offsets[k].offset     = qurt_tcb_reg_offset[k];
		reg_offsets[k].width_bits = QURT_REG_WIDTH_BITS;
	}

	/* If the runtime-resolved anchors differ from the compiled table
	 * (e.g. a future kernel exports CONTEXT_* symbols), honour them for the
	 * pair bases we track explicitly. */
	reg_offsets[28].offset = (signed short)(off->r2928);       /* r28 */
	reg_offsets[29].offset = (signed short)(off->r2928 + 4);   /* r29 = sp */
	reg_offsets[QURT_HEX_R30].offset = (signed short)(off->r3130);     /* fp */
	reg_offsets[QURT_HEX_R31].offset = (signed short)(off->r3130 + 4); /* lr */

	/* pc = elr (from ssrelr).
	 * IMPORTANT: the gdb/lldb WIRE register number for Hexagon PC is 40
	 * (r0..r31 = 0..31, then the control block: SA0=32, LC0=33, SA1=34,
	 * LC1=35, P3:0=36, M0=37?, ... ; empirically confirmed via lldb
	 * `register info pc` -> "(R40)"). It is NOT 32 (=SA0). Supplying PC at
	 * the array index QURT_HEX_PC (32) made lldb write our PC value into SA0
	 * and leave the real PC unset, so every frame #0 showed a stale shared
	 * value. Use the true wire number 40 here. */
	reg_offsets[QURT_HEX_PC].number     = 40;
	reg_offsets[QURT_HEX_PC].offset     = (signed short)(off->ssrelr);
	reg_offsets[QURT_HEX_PC].width_bits = QURT_REG_WIDTH_BITS;

	stacking->stack_registers_size   = QURT_TCB_CONTEXT_READ_SIZE;
	stacking->stack_growth_direction = -1;
	stacking->num_output_registers   = QURT_HEX_NUM_GP_REGS;
	stacking->calculate_process_stack = NULL;
	stacking->register_offsets        = reg_offsets;

	return ERROR_OK;
}
