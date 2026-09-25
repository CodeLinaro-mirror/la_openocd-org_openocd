/***************************************************************************
 *   Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.    *
 *   All rights reserved.                                                  *
 *   Confidential and Proprietary - Qualcomm Technologies, Inc.            *
 ***************************************************************************/

/***************************************************************************
 *   QuRT (Hexagon DSP) RTOS awareness for OpenOCD - shared definitions    *
 *                                                                         *
 *   Public interface for the QuRT RTOS backend (src/rtos/qurt.c):         *
 *     - threadid tier encoding macros                                     *
 *     - kernel/context constants (defaults, clamps, offsets)             *
 *     - the qurt public API consumed by the hexagon target driver        *
 *       (src/target/hexagon.c) and the rtos registry (src/rtos/rtos.c)   *
 *     - the hexagon OS-awareness read hooks consumed by qurt.c            *
 *                                                                         *
 *   Centralising these here (instead of hardcoding literals and ad-hoc    *
 *   extern declarations in the .c files) keeps the magic numbers named    *
 *   and gives every consumer a single, documented header to include.     *
 ***************************************************************************/

#ifndef OPENOCD_RTOS_QURT_H
#define OPENOCD_RTOS_QURT_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdbool.h>
#include <stdint.h>

#include "helper/types.h"        /* target_addr_t */
#include "helper/command.h"      /* struct command_invocation */

struct target;
struct rtos_type;

/* ------------------------------------------------------------------ */
/* diagnostic switch                                                  */
/* ------------------------------------------------------------------ */
/* When 1, the module is fully passive (publishes only HW threads, issues no
 * memw stuffing). Left at 0 for the functional build; the SW-thread walk is
 * instead gated at runtime once QuRT init is complete. */
#define QURT_PASSIVE_TEST 0

/* ------------------------------------------------------------------ */
/* absolute safety clamps                                             */
/* ------------------------------------------------------------------ */
/* Bound the number of TCBs we will ever walk, and HW threads we publish, as a
 * safety net against a corrupt MAX_THREADS / MAX_HTHREADS read. */
#define QURT_ABS_MAX_THREADS 512
#define QURT_ABS_MAX_HW      16

/* ------------------------------------------------------------------ */
/* threadid tier encoding                                             */
/* ------------------------------------------------------------------ */
/* Encode the thread tier in the threadid: bit 30 (0x40000000) = HW thread
 * (payload = TNUM), clear = SW thread (payload = QuRT thread_id). Bit 30 is
 * used rather than bit 63 to keep the id a small positive int64, which the
 * gdb/lldb-dap JSON (VS Code) serializes intact. NOTE: an earlier attempt to
 * use bit 63 caused VS Code's lldb-dap to collapse all HW threads into a
 * single row and emit "Malformed message" errors because the JSON encoder
 * treated the negative int64 as an out-of-range integer -- do NOT revert. */
#define QURT_TID_HW_FLAG     ((int64_t)0x40000000)
#define QURT_TID_PAYLOAD(t)  ((uint32_t)((t) & 0xffffffffULL) & ~((uint32_t)QURT_TID_HW_FLAG))
#define QURT_TID_IS_HW(t)    (((t) & QURT_TID_HW_FLAG) != 0 && \
				(((uint32_t)((t) & 0xffffffffULL) & ~((uint32_t)QURT_TID_HW_FLAG)) < QURT_ABS_MAX_HW))
#define QURT_TID_HW(tnum)    (QURT_TID_HW_FLAG | (int64_t)(uint32_t)(tnum))
#define QURT_TID_SW(swid)    ((int64_t)(uint32_t)(swid))

/* synthetic "core" ids used purely to drive IDE grouping. They are kept
 * distinct from any real HW tnum. A HW thread uses its own tnum as core,
 * sleeping SW threads use QURT_CORE_SW_PARK. */
#define QURT_CORE_SW_PARK    1000   /* sleeping SW threads land here */

/* gdb/lldb register number for the Hexagon FRAMEKEY control register (R48).
 * Hexagon scrambles saved return addresses with FRAMEKEY; supplying a parked
 * thread's SAVED framekey lets lldb's unwinder unscramble its stack. */
#define QURT_HEX_GDB_FRAMEKEY   48

/* ------------------------------------------------------------------ */
/* kernel constant defaults / plausibility bounds                     */
/* ------------------------------------------------------------------ */
/* Compiled fallbacks used when the kernel does not export (or reads back 0
 * for) these constants. Mirror the QuRT kernel consts_autogen.h. */
#define QURT_DEFAULT_CONTEXT_SIZE   448   /* SIZEOF_TCB from consts_autogen.h  */
#define QURT_DEFAULT_MAX_HTHREADS   12    /* QURT_CONFIG_MAX_HTHREADS          */

/* A CONTEXT_SIZE larger than this is treated as an implausible read and the
 * compiled default is used instead. */
#define QURT_MAX_PLAUSIBLE_CONTEXT_SIZE 0x10000

/* ------------------------------------------------------------------ */
/* phv (CONTEXT_prio) word decoding                                   */
/* ------------------------------------------------------------------ */
/* The QuRT "phv" priority/valid word (CONTEXT_prio): the valid flag is bit 8
 * and the priority occupies the low 16 bits. An all-ones word is the
 * uninitialised/invalid sentinel. */
#define QURT_PHV_INVALID_SENTINEL   0xffffffffu
#define QURT_PHV_VALID_BIT_SHIFT    8
#define QURT_PHV_PRIO_MASK          0xffffu

/* ------------------------------------------------------------------ */
/* per-thread field derivations                                       */
/* ------------------------------------------------------------------ */
/* SSR lives at CONTEXT_ssrelr + 4 (elr/pc is at +0). The QuRT ASID is bits
 * [13:8] of the SSR (TaskSpaceId in the T32 OSAM). */
#define QURT_SSR_OFFSET_FROM_ELR    4
#define QURT_SSR_ASID_SHIFT         8
#define QURT_SSR_ASID_MASK          0x3f

/* The UTCB pointer is stored at CONTEXT_ugpgp + 4. */
#define QURT_UTCB_PTR_OFFSET_FROM_UGPGP  4

/* Thread name length read from the UTCB (bytes). */
#define QURT_UTCB_NAME_LEN          16

/* ------------------------------------------------------------------ */
/* QDI guest-context constants (user frame key lookup)                */
/* ------------------------------------------------------------------ */
/* QuRT QDI guest-context constants used to locate the USER frame key for the
 * kernel->user transition during a stack walk (mirrors the T32 OSAM):
 *   fkey_usr = *( *(tcb + guest_info) - 20 ). */
#define QURT_QDI_CTXT_SIZE            32
#define QURT_QDI_CTXT_OFFSET_FKEYLIMIT 8
#define QURT_FKEY_USR_BACKOFF        (QURT_QDI_CTXT_SIZE - QURT_QDI_CTXT_OFFSET_FKEYLIMIT - 4) /* =20 */

/* ------------------------------------------------------------------ */
/* FP-chain stack walker constants                                    */
/* ------------------------------------------------------------------ */
/* Maximum number of frames the FRAMEKEY-aware FP-chain walker will emit. */
#define QURT_STACK_MAX_FRAMES   64

/* Coarse region granule (256 MB) used to derive a per-build kernel VA base
 * from a parked thread's saved PC/LR, so no kernel VA constant is baked in. */
#define QURT_KERNEL_REGION_GRANULE  0x10000000u

/* ------------------------------------------------------------------ */
/* QuRT public API (consumed by hexagon.c command hooks and rtos.c)   */
/* ------------------------------------------------------------------ */
/* The RTOS registry entry (src/rtos/rtos.c pulls this into rtos_types[]). */
extern const struct rtos_type qurt_rtos;

/* Enable/disable the SW-thread walk. Driven by the hexagon command handlers
 * (qurtEnable/qurtDisable/qurtStatus). The walk stays off until enabled here,
 * after the target has reached main, since its memw path is unsafe during
 * QuRT init. */
void qurt_set_walk_enabled(struct target *target, bool enabled);
bool qurt_get_walk_enabled(struct target *target);

/* FRAMEKEY-aware FP-chain stack walker for a parked QuRT SW thread. Prints a
 * correct deep backtrace that lldb's native unwinder cannot produce (it lacks
 * the parked thread's framekey and the kernel->user key switch). */
int qurt_stack_walk(struct target *target, int64_t swid,
		struct command_invocation *cmd);

/* Push TCB layout (SIZEOF and per-field byte offsets) resolved on the lldb
 * host side from the ELF's DWARF, keyed by struct member NAMES. Overrides
 * the compiled qurt_default_offsets so the SW-thread walk is authoritative
 * across QuRT build variants (SIZEOF_TCB 384/448, utcb_name 28/32, etc.)
 * without hardcoding any offset in the C driver. Invoked by the
 * `hexagon qurtSetOffsets` command handler from the lldb-side OSAM init
 * hook (fires after the ELF is loaded and BEFORE the first halt-driven
 * qXfer:threads:read), so qurt_update_threads always sees correct offsets
 * on the first TCB walk. Idempotent -- pushing again just overwrites.
 * Returns ERROR_OK on success, ERROR_FAIL if no RTOS attached. */
int qurt_apply_pushed_offsets(struct target *target,
		uint32_t context_size,
		uint32_t prio, uint32_t thread_id, uint32_t ugpgp,
		uint32_t hthread, uint32_t ssrelr,
		uint32_t r0100, uint32_t r2928, uint32_t r3130,
		uint32_t framelimit, uint32_t framekey,
		uint32_t guest_info, uint32_t utcb_name);

/* ------------------------------------------------------------------ */
/* Hexagon OS-awareness read hooks (implemented in src/target/hexagon.c, */
/* consumed by src/rtos/qurt.c)                                        */
/* ------------------------------------------------------------------ */
/* Reads a kernel/island VA via the HW-MMU `memw` instruction-stuffing path.
 * It clobbers r0/r7 and polls ISDB, so it is only safe post-init on a
 * genuinely halted target, never from the poll/detect/walk path. */
int hexagon_rtos_read_u32(struct target *target, target_addr_t address,
		uint32_t *value);

/* HW-thread register + current-thread hooks. Serve the per-HW-thread register
 * list (r0..r31 + PC) from the driver's cache with no target reads, satisfying
 * OpenOCD's SMP register-fetch path. hexagon_rtos_current_hwthread() returns
 * the currently-halted HW tnum. */
int hexagon_rtos_get_hwthread_reg_list(struct target *target, uint32_t tnum,
		struct rtos_reg **reg_list, int *num_regs);
uint32_t hexagon_rtos_current_hwthread(struct target *target);

/* VTLB readiness query. Returns true once the hexagon driver has populated its
 * software VTLB from QuRT's kernel page tables. Used as the auto-enable gate:
 * VTLB ready -> QuRT init is done -> memw is safe. No target I/O. */
bool hexagon_rtos_vtlb_ready(struct target *target);

/* Physical-path read. Translates a kernel VA to PA using the software VTLB
 * (global entries), then reads via memw_phys. Does NOT go through the core's
 * HW MMU -- no core state disruption. Safe any time after VTLB is populated,
 * even during init. */
int hexagon_rtos_read_u32_phys(struct target *target, target_addr_t address,
		uint32_t *value);

/* ASID-aware read. Translates a user VA under a specific QuRT ASID via the
 * kernel VTLB and reads it through memw_phys, so a parked thread's per-process
 * data (e.g. its UTCB thread name) can be read even though it lives in a
 * different address space than the currently-halted HW thread. Returns
 * ERROR_FAIL (without faulting the target) if the VA is not mapped in that
 * ASID. */
int hexagon_rtos_read_buffer_asid(struct target *target, uint32_t asid,
		target_addr_t address, uint32_t size, uint8_t *buffer);

#endif /* OPENOCD_RTOS_QURT_H */