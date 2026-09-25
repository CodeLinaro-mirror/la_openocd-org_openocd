/***************************************************************************
 *   Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.    *
 *   All rights reserved.                                                  *
 *   Confidential and Proprietary - Qualcomm Technologies, Inc.            *
 ***************************************************************************/

/***************************************************************************
 *   QuRT (Hexagon) RTOS awareness - register stacking definitions         *
 *                                                                         *
 *   Describes how a QuRT software thread's saved register context is      *
 *   laid out inside its TCB, so rtos_generic_stack_read() can reconstruct *
 *   the register set for an unwind.                                       *
 ***************************************************************************/

#ifndef OPENOCD_RTOS_RTOS_QURT_STACKINGS_H
#define OPENOCD_RTOS_RTOS_QURT_STACKINGS_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "rtos.h"

/*
 * The QuRT TCB context layout is not a "stack frame" in the classic RTOS
 * sense - the registers are stored at fixed offsets inside the TCB itself.
 * The offsets (CONTEXT_*) are resolved at runtime from QuRT-exported
 * absolute symbols (see qurt.c) and patched into a per-target stacking
 * structure.  This header just declares the builder and the Hexagon GP
 * register numbering used by the gdb register map.
 */

/*
 * Hexagon general-purpose register gdb numbers.
 * These match the order the hexagon target description / gdb expects.
 * r0..r31, then sa0-style control regs we care about for unwinding:
 *   sp = r29, fp = r30, lr = r31, pc, and a few supervisor regs.
 */
enum qurt_hexagon_gdb_regnum {
	QURT_HEX_R0 = 0,
	QURT_HEX_R1,
	QURT_HEX_R2,
	QURT_HEX_R3,
	QURT_HEX_R4,
	QURT_HEX_R5,
	QURT_HEX_R6,
	QURT_HEX_R7,
	QURT_HEX_R8,
	QURT_HEX_R9,
	QURT_HEX_R10,
	QURT_HEX_R11,
	QURT_HEX_R12,
	QURT_HEX_R13,
	QURT_HEX_R14,
	QURT_HEX_R15,
	QURT_HEX_R16,
	QURT_HEX_R17,
	QURT_HEX_R18,
	QURT_HEX_R19,
	QURT_HEX_R20,
	QURT_HEX_R21,
	QURT_HEX_R22,
	QURT_HEX_R23,
	QURT_HEX_R24,
	QURT_HEX_R25,
	QURT_HEX_R26,
	QURT_HEX_R27,
	QURT_HEX_R28,
	QURT_HEX_R29,   /* sp */
	QURT_HEX_R30,   /* fp */
	QURT_HEX_R31,   /* lr */
	QURT_HEX_PC,
	QURT_HEX_NUM_GP_REGS
};

/*
 * Runtime-resolved TCB context offsets. Filled from QuRT absolute symbols
 * (or, as a fallback, from a vendored consts_autogen.h snapshot).
 * All offsets are byte offsets from the start of a TCB.
 */
struct qurt_context_offsets {
	uint32_t prio;          /* CONTEXT_prio       - valid bit + priority */
	uint32_t thread_id;     /* CONTEXT_thread_id  - QuRT sw thread id    */
	uint32_t ugpgp;         /* CONTEXT_ugpgp      - utcb = *(tcb+ugpgp+4)*/
	uint32_t hthread;       /* CONTEXT_hthread    - low byte = HW tnum   */
	uint32_t ssrelr;        /* CONTEXT_ssrelr     - elr/pc, ssr at +4    */
	uint32_t r0100;         /* CONTEXT_r0100      - r0/r1 pair base      */
	uint32_t r2928;         /* CONTEXT_r2928      - r28/r29(sp) pair base*/
	uint32_t r3130;         /* CONTEXT_r3130      - r30(fp)/r31(lr) base */
	uint32_t framelimit;    /* CONTEXT_framelimit - v61+ only (0 if n/a) */
	uint32_t framekey;      /* CONTEXT_framekey   - v61+ only (0 if n/a) */
	uint32_t utcb_name;     /* OFFSET_UTCB_thread_name                   */
	uint32_t guest_info;    /* CONTEXT_guest_info - for user framekey    */
	bool     valid;         /* true once all mandatory offsets resolved  */
};

/*
 * Build a rtos_register_stacking from runtime-resolved offsets.
 * The returned structure is owned by the caller's qurt params (static
 * lifetime per target). reg_offsets buffer must hold QURT_HEX_NUM_GP_REGS
 * entries.
 */
int qurt_build_hexagon_stacking(const struct qurt_context_offsets *off,
		struct rtos_register_stacking *stacking,
		struct stack_register_offset *reg_offsets);

#endif /* OPENOCD_RTOS_RTOS_QURT_STACKINGS_H */
