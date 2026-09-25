/***************************************************************************
 *   Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.    *
 *   All rights reserved.                                                  *
 *   Confidential and Proprietary - Qualcomm Technologies, Inc.            *
 ***************************************************************************/

/***************************************************************************
 *   QuRT (Hexagon DSP) RTOS awareness for OpenOCD                         *
 *                                                                         *
 *   Exposes two tiers of threads to gdb/lldb: Hexagon hardware threads    *
 *   (TNUM 0..N-1) and QuRT software threads (one per active TCB). The tier *
 *   is encoded in the threadid (bit 30 = HW). SW-thread register sets are  *
 *   recovered from the saved context stored inside each TCB.              *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "target/target.h"
#include "rtos.h"
#include "helper/log.h"
#include "helper/types.h"
#include "helper/command.h"
#include "server/gdb_server.h"   /* get_target_from_connection() for the
				  * gdb_target_for_threadid validator hook */
#include "rtos_qurt_stackings.h"
#include "qurt.h"                 /* module macros, constants, public API and
				  * the hexagon OS-awareness read hooks */

/* ------------------------------------------------------------------ */
/* symbol table                                                       */
/* ------------------------------------------------------------------ */
enum qurt_symbol_index {
	QSYM_QURT_HAS_INITTED = 0,
	QSYM_TCB_LIST,
	QSYM_CONTEXT_SIZE,
	QSYM_MAX_THREADS,
	QSYM_MAX_HTHREADS,
	QSYM_IDLE_THREAD,
	/* optional */
	QSYM_TCB_LIST_TCM,
	QSYM_MAX_THREADS_TCM,
	/* context offsets (QuRT absolute symbols; optional - if any are
	 * missing we fall back to compiled defaults) */
	QSYM_CONTEXT_PRIO,
	QSYM_CONTEXT_THREAD_ID,
	QSYM_CONTEXT_UGPGP,
	QSYM_CONTEXT_HTHREAD,
	QSYM_CONTEXT_SSRELR,
	QSYM_CONTEXT_R0100,
	QSYM_CONTEXT_R2928,
	QSYM_CONTEXT_R3130,
	QSYM_CONTEXT_FRAMELIMIT,
	QSYM_CONTEXT_FRAMEKEY,
	QSYM_CONTEXT_GUEST_INFO,
	QSYM_OFFSET_UTCB_THREAD_NAME,
	QSYM_COUNT
};

struct qurt_symbol {
	const char *name;
	bool optional;
};

/* Symbol names exported by the QuRT kernel that OpenOCD asks gdb to resolve.
 * The CONTEXT_* per-field offsets are optional (not exported by this kernel);
 * qurt_default_offsets is used as the fallback. */
static const struct qurt_symbol qurt_symbol_list[] = {
	[QSYM_QURT_HAS_INITTED]        = { "qurt_has_initted",            false },
	[QSYM_TCB_LIST]                = { "QURTK_thread_contexts",       false },
	[QSYM_CONTEXT_SIZE]            = { "QURTK_CONTEXT_SIZE",          false },
	[QSYM_MAX_THREADS]             = { "QURTK_MAX_THREADS",           false },
	[QSYM_MAX_HTHREADS]            = { "QURTK_MAX_HTHREADS",          false },
	[QSYM_IDLE_THREAD]             = { "QURTK_idle_context",          true  },
	[QSYM_TCB_LIST_TCM]            = { "QURTK_thread_contexts_tcm",   true  },
	[QSYM_MAX_THREADS_TCM]         = { "QURTK_MAX_THREADS_IN_TCM",    true  },
	[QSYM_CONTEXT_PRIO]            = { "CONTEXT_prio",                true  },
	[QSYM_CONTEXT_THREAD_ID]       = { "CONTEXT_thread_id",           true  },
	[QSYM_CONTEXT_UGPGP]           = { "CONTEXT_ugpgp",               true  },
	[QSYM_CONTEXT_HTHREAD]         = { "CONTEXT_hthread",             true  },
	[QSYM_CONTEXT_SSRELR]          = { "CONTEXT_ssrelr",              true  },
	[QSYM_CONTEXT_R0100]           = { "CONTEXT_r0100",               true  },
	[QSYM_CONTEXT_R2928]           = { "CONTEXT_r2928",               true  },
	[QSYM_CONTEXT_R3130]           = { "CONTEXT_r3130",               true  },
	[QSYM_CONTEXT_FRAMELIMIT]      = { "CONTEXT_framelimit",          true  },
	[QSYM_CONTEXT_FRAMEKEY]        = { "CONTEXT_framekey",            true  },
	[QSYM_CONTEXT_GUEST_INFO]      = { "CONTEXT_guest_info",          true  },
	[QSYM_OFFSET_UTCB_THREAD_NAME] = { "OFFSET_UTCB_thread_name",     true  },
};

/* Default TCB context field offsets (bytes from TCB base), mirroring the QuRT
 * kernel consts_autogen.h (SIZEOF_TCB = 448). Used when the kernel does not
 * export the per-field CONTEXT_* offsets as runtime symbols. */
static const struct qurt_context_offsets qurt_default_offsets = {
	.prio       = 36,
	.thread_id  = 32,
	.ugpgp      = 120,
	.hthread    = 42,
	.ssrelr     = 64,
	.r0100      = 200,
	.r2928      = 80,
	.r3130      = 72,
	.framelimit = 240,
	.framekey   = 244,
	.utcb_name  = 28,
	.guest_info = 16,        /* CONTEXT_guest_info (consts_autogen.h)     */
	.valid      = true,
};

/* Test the QuRT "phv" priority/valid word (CONTEXT_prio): the valid flag is
 * bit QURT_PHV_VALID_BIT_SHIFT. A TCB is active only when this bit is set. */
static inline bool qurt_phv_valid(uint32_t phv)
{
	if (phv == QURT_PHV_INVALID_SENTINEL)
		return false;
	return ((phv >> QURT_PHV_VALID_BIT_SHIFT) & 0x1u) != 0;
}

/* ------------------------------------------------------------------ */
/* per-target private state                                           */
/* ------------------------------------------------------------------ */
struct qurt_params {
	bool                         constants_cached;
	uint32_t                     context_size;
	uint32_t                     max_threads;
	uint32_t                     max_hthreads;
	uint32_t                     max_threads_tcm;
	target_addr_t                tcb_list_head;
	target_addr_t                tcb_list_tcm_head;
	target_addr_t                idle_thread;

	struct qurt_context_offsets  off;

	/* stacking built from off; storage owned here */
	struct rtos_register_stacking stacking;
	struct stack_register_offset  reg_offsets[QURT_HEX_NUM_GP_REGS];

	/* maps a sw thread_id -> its TCB address, rebuilt every update */
	struct {
		uint32_t      swid;
		target_addr_t tcb;
		uint32_t      hthread;   /* < max_hthreads => running */
	} *swmap;
	int              swmap_count;

	/* current halted HW thread number (filled by update). */
	int              halted_hw; 

	/* Latched true the first time we halt at a genuine code breakpoint
	 * (main / QURTOS_init / any user breakpoint). Until then we never issue
	 * the instruction-stuffing (memw) reads that the SW-thread walk needs,
	 * so QuRT init is never disturbed (target reliably reaches main). */
	bool             walk_enabled;

	/* Set true once the lldb-side OSAM has pushed authoritative TCB
	 * layout via `hexagon qurtSetOffsets` (see qurt_apply_pushed_offsets).
	 * When set, qurt_cache_constants trusts p->off/p->context_size as-is
	 * and does NOT fall back to qurt_default_offsets or the compiled
	 * QURT_DEFAULT_CONTEXT_SIZE. Prevents the SIZEOF_TCB=384-vs-448 /
	 * utcb_name=28-vs-32 hazards on builds whose kernel does not export
	 * the CONTEXT_* absolute symbols. */
	bool             offsets_pushed;
};

/* forward declarations */
static bool qurt_detect_rtos(struct target *target);
static int  qurt_create(struct target *target);
static int  qurt_update_threads(struct rtos *rtos);
static int  qurt_get_thread_reg_list(struct rtos *rtos, int64_t thread_id,
		struct rtos_reg **reg_list, int *num_regs);
static int  qurt_get_symbol_list_to_lookup(struct symbol_table_elem *symbol_list[]);
static int  qurt_clean(struct target *target);
/* installed as rtos->gdb_target_for_threadid in qurt_create(); defined below
 * (after qurt_tcb_for_swid) but used above it, so forward-declare it here. */
static int  qurt_gdb_target_for_threadid(struct connection *connection,
		int64_t thread_id, struct target **p_target);

const struct rtos_type qurt_rtos = {
	.name                      = "qurt",
	.detect_rtos               = qurt_detect_rtos,
	.create                    = qurt_create,
	.update_threads            = qurt_update_threads,
	.get_thread_reg_list       = qurt_get_thread_reg_list,
	.get_symbol_list_to_lookup = qurt_get_symbol_list_to_lookup,
	.clean                     = qurt_clean,
};

/* ------------------------------------------------------------------ */
/* helpers                                                            */
/* ------------------------------------------------------------------ */

static symbol_address_t qsym(struct rtos *rtos, enum qurt_symbol_index i)
{
	if (!rtos->symbols)
		return 0;
	return rtos->symbols[i].address;
}

/* ------------------------------------------------------------------ */
/* Manual enable control (driven by a target command)                 */
/* ------------------------------------------------------------------ */
/* Enable/disable the SW-thread walk. Exported so the hexagon command handlers
 * (qurtEnable/qurtDisable/qurtStatus) can drive it. The walk stays off by
 * default and is only turned on once the target is halted post-init, since it
 * relies on the memw path that is unsafe during QuRT init. */
void qurt_set_walk_enabled(struct target *target, bool enabled)
{
	if (!target || !target->rtos || !target->rtos->rtos_specific_params)
		return;
	struct qurt_params *p = target->rtos->rtos_specific_params;
	p->walk_enabled = enabled;
	LOG_INFO("qurt: SW-thread walk %s by command",
		 enabled ? "ENABLED" : "DISABLED");

	/* Refresh the thread list immediately so the SW walk takes effect now,
	 * since gdb/lldb only re-query the list on the next target stop. */
	if (enabled && target->state == TARGET_HALTED)
		qurt_update_threads(target->rtos);
}

bool qurt_get_walk_enabled(struct target *target)
{
	if (!target || !target->rtos || !target->rtos->rtos_specific_params)
		return false;
	struct qurt_params *p = target->rtos->rtos_specific_params;
	return p->walk_enabled;
}

/* ------------------------------------------------------------------ */
/* Memory access helpers                                               */
/* ------------------------------------------------------------------ */
/* CRITICAL SAFETY NOTES -- do not use these helpers interchangeably.
 *
 *  qurt_read_u32()      : Plain target_* path. NO instruction stuffing, NO
 *                         core-state disruption. Safe to call at any time,
 *                         including during QuRT init before the target has
 *                         reached main. May return 0 for kernel/island VAs
 *                         that are not yet software-VTLB-mapped. USE FROM
 *                         the poll / detect / TCB-walk paths that run on
 *                         every halt-poll.
 *
 *  qurt_read_u32_mmu()  : Prefers the VTLB-translate + memw_phys physical
 *                         path (safe, non-disruptive); falls back to the
 *                         memw-virtual instruction-stuffing path if the VA
 *                         has no VTLB entry. The fallback stuffs 'memw'
 *                         into the halted core and CLOBBERS r0/r7 (restored
 *                         via hexagon_stuff_reg_restore, but still disturbs
 *                         core state briefly). It MUST NOT be called during
 *                         QuRT init -- doing so wedges the target and it
 *                         never reaches main. Only safe once the SW-thread
 *                         walk is gated on (i.e. VTLB ready, post-init).
 *                         USE for explicit user-driven operations on
 *                         parked threads (register reconstruction, stack
 *                         walk, etc.).
 *
 *  qurt_read_u8_mmu()   : Same safety constraints as qurt_read_u32_mmu()
 *                         (calls the same underlying memw path). Used for
 *                         non-word-aligned TCB fields (e.g. hthread).
 */

/* Side-effect-free read (plain target_* path) for use on the poll/detect/walk
 * path, where instruction stuffing would disturb QuRT init. May yield 0 for
 * kernel/island VAs that are not yet software-VTLB-mapped. */
static int qurt_read_u32(struct rtos *rtos, target_addr_t address, uint32_t *value)
{
	return target_read_u32(rtos->target, address, value);
}

/* Kernel-VA read preferring the VTLB-translate + memw_phys physical path (no
 * core-state disruption), falling back to the memw-virtual path if the VA has
 * no VTLB entry. */
static int qurt_read_u32_mmu(struct rtos *rtos, target_addr_t address, uint32_t *value)
{
	int retval = hexagon_rtos_read_u32_phys(rtos->target, address, value);
	if (retval == ERROR_OK)
		return ERROR_OK;
	return hexagon_rtos_read_u32(rtos->target, address, value);
}

/* Read a single byte from a (possibly unaligned) kernel address. The memw
 * path requires 4-byte alignment, so read the containing aligned word and
 * extract the byte (some TCB fields, e.g. hthread, are not word-aligned). */
static int qurt_read_u8_mmu(struct rtos *rtos, target_addr_t address, uint8_t *value)
{
	target_addr_t aligned = address & ~((target_addr_t)0x3);
	uint32_t w = 0;
	int retval = hexagon_rtos_read_u32(rtos->target, aligned, &w);
	if (retval != ERROR_OK) {
		*value = 0;
		return retval;
	}
	*value = (uint8_t)((w >> (8 * (address & 0x3))) & 0xff);
	return ERROR_OK;
}

/* NOTE: a plain (current-ASID) buffer read helper used to live here, but all
 * buffer reads now go through the ASID-aware path (hexagon_rtos_read_buffer_asid)
 * so per-process data is read in the owning thread's address space. The plain
 * helper was removed to avoid an unused-function warning. */

/* Resolve and cache the kernel-wide constants and context offsets. */
static int qurt_cache_constants(struct rtos *rtos)
{
	struct qurt_params *p = rtos->rtos_specific_params;
	int retval;
	uint32_t v;

	if (p->constants_cached)
		return ERROR_OK;

	/* TCB list head: the symbol TCB_LIST holds the *address* of the list
	 * pointer; the OSAM does m->par_tcblist = DreadLong(TCB_LIST). */
	if (qsym(rtos, QSYM_TCB_LIST) == 0) {
		LOG_ERROR("qurt: TCB_LIST symbol not resolved");
		return ERROR_FAIL;
	}
	retval = qurt_read_u32_mmu(rtos, qsym(rtos, QSYM_TCB_LIST), &v);
	if (retval != ERROR_OK) {
		LOG_ERROR("qurt: READ-PATH FAIL: deref TCB_LIST @0x%" TARGET_PRIxADDR
			  " returned retval=%d", qsym(rtos, QSYM_TCB_LIST), retval);
		return retval;
	}
	p->tcb_list_head = v;
	LOG_DEBUG("qurt: read-path TCB_LIST sym=0x%" TARGET_PRIxADDR " -> head=0x%08" PRIx32,
		 qsym(rtos, QSYM_TCB_LIST), v);

	/* CONTEXT_SIZE / MAX_THREADS / MAX_HTHREADS are kernel data variables read
	 * from memory; some live in island memory and may read 0, in which case we
	 * fall back to the compiled QuRT defaults so detection still proceeds.
	 *
	 * If offsets_pushed is set the lldb-side OSAM has already installed the
	 * authoritative context_size (resolved from the ELF's DWARF by struct
	 * NAME, so per-build correct). Trust it and skip the kernel-memory read
	 * + compiled-default fallback below -- those are known to be wrong on
	 * the SIZEOF_TCB=384 build variants when this branch runs. */
	if (p->offsets_pushed) {
		LOG_INFO("qurt: using pushed context_size=0x%" PRIx32 " (OSAM/DWARF)",
			 p->context_size);
	} else {
	v = 0;
	qurt_read_u32_mmu(rtos, qsym(rtos, QSYM_CONTEXT_SIZE), &v);
	LOG_DEBUG("qurt: read-path CONTEXT_SIZE sym=0x%" TARGET_PRIxADDR " -> 0x%08" PRIx32,
		 qsym(rtos, QSYM_CONTEXT_SIZE), v);
	p->context_size = v;
	if (p->context_size == 0 ||
	    p->context_size > QURT_MAX_PLAUSIBLE_CONTEXT_SIZE) {
		LOG_WARNING("qurt: CONTEXT_SIZE read as 0x%" PRIx32 ", using default %u",
			    p->context_size, QURT_DEFAULT_CONTEXT_SIZE);
		p->context_size = QURT_DEFAULT_CONTEXT_SIZE;
	}
	}

	v = 0;
	qurt_read_u32_mmu(rtos, qsym(rtos, QSYM_MAX_THREADS), &v);
	LOG_DEBUG("qurt: read-path MAX_THREADS sym=0x%" TARGET_PRIxADDR " -> %u",
		 qsym(rtos, QSYM_MAX_THREADS), v);
	p->max_threads = v;

	v = 0;
	qurt_read_u32_mmu(rtos, qsym(rtos, QSYM_MAX_HTHREADS), &v);
	LOG_DEBUG("qurt: read-path MAX_HTHREADS sym=0x%" TARGET_PRIxADDR " -> %u",
		 qsym(rtos, QSYM_MAX_HTHREADS), v);
	p->max_hthreads = v;
	if (p->max_hthreads == 0 || p->max_hthreads > QURT_ABS_MAX_HW) {
		LOG_WARNING("qurt: MAX_HTHREADS read as %u, using default %u",
			    p->max_hthreads, QURT_DEFAULT_MAX_HTHREADS);
		p->max_hthreads = QURT_DEFAULT_MAX_HTHREADS;
	}

	p->max_threads_tcm = 0;
	if (qsym(rtos, QSYM_MAX_THREADS_TCM) != 0 &&
	    qurt_read_u32_mmu(rtos, qsym(rtos, QSYM_MAX_THREADS_TCM), &v) == ERROR_OK)
		p->max_threads_tcm = v;
	/* Clamp the TCM count exactly like max_threads/max_hthreads below: a bad
	 * read (e.g. 0xffffffff from unmapped island memory) would otherwise make
	 * the TCM walk (qurt_walk_tcb_region) iterate ~4e9 times and write past the
	 * thread_details[]/swmap[] arrays, which are sized on the CLAMPED count. */
	if (p->max_threads_tcm > QURT_ABS_MAX_THREADS)
		p->max_threads_tcm = QURT_ABS_MAX_THREADS;

	p->tcb_list_tcm_head = 0;
	if (qsym(rtos, QSYM_TCB_LIST_TCM) != 0 &&
	    qurt_read_u32_mmu(rtos, qsym(rtos, QSYM_TCB_LIST_TCM), &v) == ERROR_OK)
		p->tcb_list_tcm_head = v;

	p->idle_thread = qsym(rtos, QSYM_IDLE_THREAD);

	/* sanity-clamp the thread count (context_size/max_hthreads already
	 * defaulted above). */
	if (p->max_threads == 0 || p->max_threads > QURT_ABS_MAX_THREADS)
		p->max_threads = QURT_ABS_MAX_THREADS;

	/* Resolve CONTEXT_* offsets: if QuRT exports them as absolute symbols,
	 * their *address* is the offset value. Otherwise use defaults.
	 *
	 * When offsets_pushed is set the lldb-side OSAM has already populated
	 * p->off with authoritative values resolved from the ELF's DWARF (by
	 * struct member NAME, so guaranteed correct for this build's
	 * QURTK_thread_context layout). Do NOT clobber those with the compiled
	 * qurt_default_offsets or with kernel-symbol-derived values -- either
	 * source can be wrong (defaults are wrong on utcb_name=32 builds; the
	 * CONTEXT_* absolute symbols aren't exported by every kernel). */
	struct qurt_context_offsets *o = &p->off;
	if (!p->offsets_pushed) {
		*o = qurt_default_offsets;

		if (qsym(rtos, QSYM_CONTEXT_PRIO))      o->prio       = qsym(rtos, QSYM_CONTEXT_PRIO);
		if (qsym(rtos, QSYM_CONTEXT_THREAD_ID)) o->thread_id  = qsym(rtos, QSYM_CONTEXT_THREAD_ID);
		if (qsym(rtos, QSYM_CONTEXT_UGPGP))     o->ugpgp      = qsym(rtos, QSYM_CONTEXT_UGPGP);
		if (qsym(rtos, QSYM_CONTEXT_HTHREAD))   o->hthread    = qsym(rtos, QSYM_CONTEXT_HTHREAD);
		if (qsym(rtos, QSYM_CONTEXT_SSRELR))    o->ssrelr     = qsym(rtos, QSYM_CONTEXT_SSRELR);
		if (qsym(rtos, QSYM_CONTEXT_R0100))     o->r0100      = qsym(rtos, QSYM_CONTEXT_R0100);
		if (qsym(rtos, QSYM_CONTEXT_R2928))     o->r2928      = qsym(rtos, QSYM_CONTEXT_R2928);
		if (qsym(rtos, QSYM_CONTEXT_R3130))     o->r3130      = qsym(rtos, QSYM_CONTEXT_R3130);
		if (qsym(rtos, QSYM_CONTEXT_FRAMELIMIT))o->framelimit = qsym(rtos, QSYM_CONTEXT_FRAMELIMIT);
		if (qsym(rtos, QSYM_CONTEXT_FRAMEKEY))  o->framekey   = qsym(rtos, QSYM_CONTEXT_FRAMEKEY);
		if (qsym(rtos, QSYM_CONTEXT_GUEST_INFO))o->guest_info = qsym(rtos, QSYM_CONTEXT_GUEST_INFO);
		if (qsym(rtos, QSYM_OFFSET_UTCB_THREAD_NAME))
			o->utcb_name = qsym(rtos, QSYM_OFFSET_UTCB_THREAD_NAME);
		o->valid = true;
	} else {
		LOG_INFO("qurt: using pushed CONTEXT_* offsets (OSAM/DWARF): "
			 "prio=%u tid=%u ugpgp=%u hthread=%u ssrelr=%u r0100=%u r2928=%u "
			 "r3130=%u flim=%u fkey=%u ginfo=%u utcb=%u",
			 o->prio, o->thread_id, o->ugpgp, o->hthread, o->ssrelr,
			 o->r0100, o->r2928, o->r3130, o->framelimit, o->framekey,
			 o->guest_info, o->utcb_name);
	}

	/* build the stacking from the resolved offsets */
	retval = qurt_build_hexagon_stacking(o, &p->stacking, p->reg_offsets);
	if (retval != ERROR_OK)
		return retval;

	p->constants_cached = true;
	LOG_DEBUG("qurt: cached constants ctx_size=0x%" PRIx32
		  " max_threads=%u max_hthreads=%u tcb_head=0x%" TARGET_PRIxADDR,
		  p->context_size, p->max_threads, p->max_hthreads, p->tcb_list_head);
	return ERROR_OK;
}

/* Derive a thread's QuRT ASID from its saved SSR, exactly like the QuRT T32
 * OSAM (TaskSpaceId): ssr = *(tcb + CONTEXT_ssrelr + 4); asid = (ssr>>8)&0x3f.
 * The SSR lives in the TCB (a kernel VA) so this read is always safe. */
static uint32_t qurt_thread_asid(struct rtos *rtos, target_addr_t tcb)
{
	struct qurt_params *p = rtos->rtos_specific_params;
	uint32_t ssr = 0;
	if (qurt_read_u32_mmu(rtos, tcb + p->off.ssrelr + QURT_SSR_OFFSET_FROM_ELR,
			&ssr) != ERROR_OK)
		return 0;
	return (ssr >> QURT_SSR_ASID_SHIFT) & QURT_SSR_ASID_MASK;
}

/* Read a 16-byte thread name from the UTCB pointed at by a TCB.
 *
 * The UTCB is a per-process user VA living in this thread's own ASID. To read
 * it without page-faulting (the thread may belong to a different process than
 * the one currently mapped on the halted HW thread), we mirror the QuRT T32
 * OSAM MagicToName: resolve the thread's ASID from its SSR, then read the UTCB
 * through the ASID-aware VTLB->physical path (hexagon_rtos_read_buffer_asid).
 * If the UTCB is not mapped in that ASID we fall back to "NA". */
static char *qurt_read_thread_name(struct rtos *rtos, target_addr_t tcb)
{
	struct qurt_params *p = rtos->rtos_specific_params;
	uint32_t utcb = 0;
	char namebuf[20];

	if (p->idle_thread && tcb == p->idle_thread)
		return strdup("IDLE THREAD");

	/* utcb pointer is stored in the TCB (kernel VA) -> safe read. */
	int urv = qurt_read_u32_mmu(rtos,
			tcb + p->off.ugpgp + QURT_UTCB_PTR_OFFSET_FROM_UGPGP, &utcb);
	LOG_DEBUG("qurt: name-read tcb=0x%08x utcb-ptr@+%u rv=%d utcb=0x%08" PRIx32,
		 (unsigned)tcb, p->off.ugpgp + QURT_UTCB_PTR_OFFSET_FROM_UGPGP,
		 urv, utcb);
	if (urv != ERROR_OK || utcb == 0)
		return strdup("NA");

	uint32_t asid = qurt_thread_asid(rtos, tcb);
	LOG_DEBUG("qurt: name-read tcb=0x%08x asid=%u utcb=0x%08" PRIx32
		 " name_va=0x%08" PRIx32, (unsigned)tcb, asid, utcb,
		 (uint32_t)(utcb + p->off.utcb_name));

	memset(namebuf, 0, sizeof(namebuf));
	/* Read the name from the UTCB in the thread's OWN ASID (VTLB-translated +
	 * memw_phys). This works for parked threads in other processes and does
	 * not fault the target. */
	if (hexagon_rtos_read_buffer_asid(rtos->target, asid,
			utcb + p->off.utcb_name, QURT_UTCB_NAME_LEN,
			(uint8_t *)namebuf) != ERROR_OK)
		return strdup("NA");
	namebuf[QURT_UTCB_NAME_LEN] = 0;
	if (namebuf[0] == 0)
		return strdup("NA");

	/* The 16 raw UTCB bytes are attacker/uninitialized-data controlled and are
	 * later folded verbatim into the qXfer:threads:read XML via xml_printf
	 * (which does NOT escape). A stray '<', '>', '&', '"' or '\'' -- or any
	 * non-printable byte -- would produce malformed XML and make strict IDE
	 * parsers (VS Code / gdb) drop the whole thread panel. Replace anything
	 * that isn't a safe printable ASCII char with '_'. Truncate at the first
	 * NUL so we keep the intended C-string name. */
	for (int i = 0; i < QURT_UTCB_NAME_LEN && namebuf[i]; i++) {
		unsigned char ch = (unsigned char)namebuf[i];
		if (ch < 0x20 || ch > 0x7e ||
		    ch == '<' || ch == '>' || ch == '&' || ch == '"' || ch == '\'')
			namebuf[i] = '_';
	}
	return strdup(namebuf);
}

/* Return the 0-based HW thread the hexagon driver currently has halted,
 * or -1 if unknown. */
static int qurt_current_hw_thread(struct rtos *rtos)
{
	if (!rtos || !rtos->target)
		return -1;
	return (int)hexagon_rtos_current_hwthread(rtos->target);
}

/* ------------------------------------------------------------------ */
/* rtos_type callbacks                                                */
/* ------------------------------------------------------------------ */

static int qurt_create(struct target *target)
{
	struct qurt_params *p = calloc(1, sizeof(*p));
	if (!p) {
		LOG_ERROR("qurt: out of memory");
		return ERROR_FAIL;
	}
	p->constants_cached = false;
	p->halted_hw = -1;
	p->walk_enabled = false;
	target->rtos->rtos_specific_params = p;
	/* Install our thread-id validator so malformed/stale ids are rejected
	 * (see qurt_gdb_target_for_threadid). Without this the gdb_server vCont
	 * path would accept bogus ids and emit synthetic stop-replies. */
	target->rtos->gdb_target_for_threadid = qurt_gdb_target_for_threadid;
	/* Seed current_thread to HW0 so the initial qC reports a thread-id that
	 * will exist in the published thread list (keeps IDE indexing 1-based). */
	target->rtos->current_thread = QURT_TID_HW(0);
	target->rtos->thread_details = NULL;
	target->rtos->thread_count = 0;
	LOG_INFO("qurt: OS awareness created for target %s", target_name(target));
	return ERROR_OK;
}

static int qurt_clean(struct target *target)
{
	if (!target->rtos)
		return ERROR_OK;
	struct qurt_params *p = target->rtos->rtos_specific_params;
	if (p) {
		/* Reset per-gdb-connection transient state, but DO NOT free the
		 * rtos_specific_params struct itself.
		 *
		 * CRITICAL (regression fix): gdb_new_connection() calls
		 * rtos->type->clean() on EVERY new gdb connection (see
		 * gdb_server.c:gdb_new_connection), whereas qurt_create() runs only
		 * ONCE, at `-rtos qurt` target-create time. A prior review-addressal
		 * commit (7c82c66) changed this to free(p) + NULL "to fix a leak" --
		 * but that freed the struct on the SECOND gdb connection (e.g. the
		 * adsp gdb server on port 3001 opening after the apss server on 2000).
		 * Every subsequent qurt callback (qurt_update_threads,
		 * qurt_get_thread_reg_list, qurt_gdb_target_for_threadid, ...) then saw
		 * rtos_specific_params == NULL and either early-failed with
		 * uninitialised out-params (stack garbage -> "undefined debug reason /
		 * target needs reset") or dereferenced NULL. That broke reaching main
		 * and the whole thread list.
		 *
		 * The struct is owned for the lifetime of the target (allocated once in
		 * qurt_create); the small one-time allocation is acceptable and is the
		 * same lifetime model other RTOS backends use. Only reset the transient
		 * session state here so a reopened gdb connection re-caches cleanly. */
		free(p->swmap);
		p->swmap = NULL;
		p->swmap_count = 0;
		p->constants_cached = false;   /* re-read after reset */
	}
	rtos_free_threadlist(target->rtos);
	return ERROR_OK;
}

static bool qurt_detect_rtos(struct target *target)
{
	struct rtos *rtos = target->rtos;
	if (!rtos || !rtos->symbols)
		return false;

	/* mandatory symbols present? */
	if (rtos->symbols[QSYM_TCB_LIST].address == 0 ||
	    rtos->symbols[QSYM_QURT_HAS_INITTED].address == 0)
		return false;

	/* qurt_has_initted == 1 ?
	 * Use the SAFE (non-stuffing) read here: detect runs from gdb qSymbol
	 * handling which can occur while QuRT is still initializing. If the flag
	 * lives in a kernel VA not yet readable by the software path it reads 0,
	 * and we simply report "not up yet" — we must NOT stuff instructions at
	 * this point. */
	uint32_t initted = 0;
	if (qurt_read_u32(rtos, rtos->symbols[QSYM_QURT_HAS_INITTED].address,
			&initted) != ERROR_OK)
		return false;

	if (initted != 1) {
		LOG_DEBUG("qurt: qurt_has_initted=%u (not yet up)", initted);
		return false;
	}

	LOG_INFO("qurt: detected QuRT (qurt_has_initted=1)");
	return true;
}

static int qurt_get_symbol_list_to_lookup(struct symbol_table_elem *symbol_list[])
{
	*symbol_list = calloc(QSYM_COUNT + 1, sizeof(struct symbol_table_elem));
	if (!*symbol_list) {
		LOG_ERROR("qurt: out of memory");
		return ERROR_FAIL;
	}
	for (int i = 0; i < QSYM_COUNT; i++) {
		(*symbol_list)[i].symbol_name = qurt_symbol_list[i].name;
		(*symbol_list)[i].optional    = qurt_symbol_list[i].optional;
	}
	/* terminator already zeroed by calloc */
	return ERROR_OK;
}

/* Walk one TCB array region, appending active threads to the rtos thread
 * list and the swmap. *idx is the running write index into thread_details. */
static int qurt_walk_tcb_region(struct rtos *rtos, target_addr_t head,
		uint32_t count, int *idx, int *swmap_idx)
{
	struct qurt_params *p = rtos->rtos_specific_params;
	target_addr_t tcb = head;

	for (uint32_t i = 0; i < count; i++, tcb += p->context_size) {
		uint32_t phv = 0;
		int prv = qurt_read_u32_mmu(rtos, tcb + p->off.prio, &phv);
		bool phv_ok = qurt_phv_valid(phv);
		if (i < 4)
			LOG_DEBUG("qurt: read-path TCB[%u] @0x%08x prio@+%u rv=%d phv=0x%08" PRIx32
				 " valid=%d", i, (unsigned)tcb, p->off.prio, prv, phv,
				 phv_ok ? 1 : 0);
		if (prv != ERROR_OK)
			continue;
		if (!phv_ok)
			continue;

		/* Check the thread_id read: if it silently failed, swid would stay 0
		 * and two failed TCBs would both map to swid=0 in the swmap, so
		 * qurt_tcb_for_swid() would return the wrong TCB for a gdb reg query.
		 * Skip the TCB on failure rather than publish a colliding id. */
		uint32_t swid = 0;
		if (qurt_read_u32_mmu(rtos, tcb + p->off.thread_id, &swid) != ERROR_OK)
			continue;

		/* hthread is a single byte at a non-word-aligned offset, so use the
		 * aligned byte reader to avoid an unaligned-load exception.
		 * qurt_read_u8_mmu() writes *value=0 on failure, which would look like
		 * "running on HW0" -- restore the 0xff "parked/unknown" sentinel on a
		 * failed read so we don't mislabel a parked thread as running. */
		uint8_t hthread8 = 0xff;
		if (qurt_read_u8_mmu(rtos, tcb + p->off.hthread, &hthread8) != ERROR_OK)
			hthread8 = 0xff;
		uint32_t hthread = hthread8;
		bool running = (hthread < p->max_hthreads);

		uint32_t prio = phv & QURT_PHV_PRIO_MASK;

		struct thread_detail *td = &rtos->thread_details[*idx];
		td->threadid       = QURT_TID_SW(swid);
		td->exists         = true;
		td->core_id        = running ? (int)hthread : QURT_CORE_SW_PARK;
		td->handle         = (uint64_t)tcb;
		td->tier           = "sw";
		td->hide_from_cli  = false;

		/* Read the thread name from its per-process UTCB in the thread's own
		 * ASID (returns "NA" if unmapped). */
		char *real_name = qurt_read_thread_name(rtos, tcb);

		/* Encode tier + scheduling state into the DAP-visible thread name,
		 * since DAP shows only a single Thread.name string in the tree. */
		char display[96];
		if (running)
			snprintf(display, sizeof(display),
				 "[SW] %-16s RUN@HW%02u pri=%u tcb=0x%08x",
				 real_name ? real_name : "?", hthread, prio,
				 (unsigned)tcb);
		else
			snprintf(display, sizeof(display),
				 "[SW] %-16s PARKED   pri=%u tcb=0x%08x",
				 real_name ? real_name : "?", prio, (unsigned)tcb);
		td->thread_name_str = strdup(display);

		/* Compact form for gdb's "extra info" column ('info threads'). */
		char extra[160];
		if (running)
			snprintf(extra, sizeof(extra),
				 "SW pri=%u RUN on HW%u tcb=0x%08x",
				 prio, hthread, (unsigned)tcb);
		else
			snprintf(extra, sizeof(extra),
				 "SW pri=%u WAIT/READY tcb=0x%08x",
				 prio, (unsigned)tcb);
		td->extra_info_str = strdup(extra);

		/* record in swmap */
		p->swmap[*swmap_idx].swid    = swid;
		p->swmap[*swmap_idx].tcb     = tcb;
		p->swmap[*swmap_idx].hthread = hthread;
		(*swmap_idx)++;

		LOG_DEBUG("qurt: SW thread published swid=0x%" PRIx32 " (%s) tcb=0x%08x %s",
			 swid, real_name ? real_name : "?",
			 (unsigned)tcb,
			 running ? "RUNNING" : "PARKED");

		/* real_name is already copied into thread_name_str; free the original
		 * to avoid a per-thread leak. */
		free(real_name);

		(*idx)++;
	}
	return ERROR_OK;
}

static int qurt_update_threads(struct rtos *rtos)
{
	struct qurt_params *p;
	int retval;

	if (!rtos || !rtos->rtos_specific_params)
		return ERROR_FAIL;
	p = rtos->rtos_specific_params;

	if (!rtos->symbols) {
		LOG_DEBUG("qurt: symbols not resolved yet, deferring thread update");
		return ERROR_OK;
	}

	/* Only walk kernel structures while halted; the reads may stuff memw and
	 * would disturb a running/initializing target. */
	if (rtos->target->state != TARGET_HALTED) {
		LOG_DEBUG("qurt: target not halted (state=%d), skipping thread update",
			  rtos->target->state);
		return ERROR_OK;
	}

	/* Auto-enable gate: stay passive (HW threads only) until QuRT init is
	 * complete, since the SW walk's memw stuffing would wedge init otherwise.
	 * Enable the walk once the hexagon driver reports its software VTLB is
	 * populated (a side-effect-free cached-bool check that means init is done). */
	if (!p->walk_enabled) {
		if (hexagon_rtos_vtlb_ready(rtos->target)) {
			p->walk_enabled = true;
			LOG_INFO("qurt: auto-enabled SW-thread walk (VTLB ready)");
		}
	}

	if (p->walk_enabled) {
		retval = qurt_cache_constants(rtos);
		if (retval != ERROR_OK) {
			/* Transient failure (e.g. QuRT symbols not resolved yet). Fall
			 * back to publishing HW threads only and clear walk_enabled so the
			 * walk is retried on the next halt — never return early, or the HW
			 * tier would be lost and 'thread list' would show nothing. */
			LOG_WARNING("qurt: cache_constants failed (retval=%d); publishing "
				    "HW threads only this round (will retry SW walk next halt)",
				    retval);
			p->walk_enabled = false;
		}
	}

	/* wipe previous list */
	rtos_free_threadlist(rtos);
	free(p->swmap);
	p->swmap = NULL;
	p->swmap_count = 0;

	/* HW-thread count is always known once the walk is enabled; before that
	 * the kernel constants are 0, so fall back to defaults so the HW tier is
	 * still published (and we never size a zero/garbage allocation). */
	uint32_t hw_count   = p->walk_enabled ? p->max_hthreads
					      : QURT_DEFAULT_MAX_HTHREADS;
	uint32_t sw_capacity = p->walk_enabled ? p->max_threads : 0;

	/* Pre-count active SW threads so we can size allocations.
	 * Cheap upper bound = max_threads. */
	/* Threads live in TWO regions: the "main" contexts array and (optionally)
	 * a TCM contexts array; max_threads is the TOTAL and max_threads_tcm is
	 * the TCM subset. So the main region holds (max_threads - max_threads_tcm)
	 * slots. If the TCM region already covers every thread (max_threads <=
	 * max_threads_tcm) the main region is EMPTY -- must be 0, not max_threads,
	 * or the walk overruns thread_details[] which was sized on max_threads. */
	uint32_t sw_region_count = (p->max_threads > p->max_threads_tcm)
				 ? (p->max_threads - p->max_threads_tcm) : 0;

	int max_entries = (int)hw_count + (int)sw_capacity;
	if (max_entries <= 0)
		max_entries = QURT_DEFAULT_MAX_HTHREADS;
	rtos->thread_details = calloc(max_entries, sizeof(struct thread_detail));
	if (!rtos->thread_details) {
		LOG_ERROR("qurt: out of memory (thread_details)");
		return ERROR_FAIL;
	}
	p->swmap = calloc(sw_capacity ? sw_capacity : 1, sizeof(*p->swmap));
	if (!p->swmap) {
		LOG_ERROR("qurt: out of memory (swmap)");
		free(rtos->thread_details);
		rtos->thread_details = NULL;
		return ERROR_FAIL;
	}

	int idx = 0;
	int swmap_idx = 0;

	/* ---- HW tier ----
	 * Publish each HW thread with a "[HWnn]" name (and "(active)" on the halted
	 * one), encoding the tier in the DAP-visible name since DAP has no tier
	 * grouping. */
	p->halted_hw = qurt_current_hw_thread(rtos);
	for (uint32_t h = 0; h < hw_count; h++) {
		struct thread_detail *td = &rtos->thread_details[idx];
		td->threadid       = QURT_TID_HW(h);
		td->exists         = true;
		td->core_id        = (int)h;
		/* Offset the handle by 1 so HW thread 0 gets a non-zero handle. The
		 * XML emitter only prints handle= when it is non-zero, so a 0 handle
		 * on HW0 alone would make its qXfer XML asymmetric (missing handle=)
		 * versus HW1..HWn -- IDEs that key stop-reply->row correlation on
		 * handle then misbehave specifically on HW0. */
		td->handle         = (uint64_t)h + 1;
		td->tier           = "hw";
		td->hide_from_cli  = false;

		char nm[32];
		if (p->halted_hw >= 0 && (uint32_t)p->halted_hw == h)
			snprintf(nm, sizeof(nm), "[HW%02u] (active)", h);
		else
			snprintf(nm, sizeof(nm), "[HW%02u]", h);
		td->thread_name_str = strdup(nm);
		td->extra_info_str  = strdup("HW thread");
		idx++;
	}

	/* ---- SW tier (only once the walk is enabled = post-init breakpoint) ---- */
	if (p->walk_enabled) {
		/* main TCB region */
		qurt_walk_tcb_region(rtos, p->tcb_list_head, sw_region_count, &idx, &swmap_idx);
		/* TCM TCB region (if any) */
		if (p->max_threads_tcm && p->tcb_list_tcm_head)
			qurt_walk_tcb_region(rtos, p->tcb_list_tcm_head, p->max_threads_tcm,
					     &idx, &swmap_idx);
	}

	rtos->thread_count = idx;
	p->swmap_count = swmap_idx;

	/* ---- current thread ---- */
	/* The SW thread currently scheduled on the halted HW thread becomes
	 * current_thread; if none found, use the halted HW thread itself. */
	rtos->current_thread = QURT_TID_HW(p->halted_hw >= 0 ? p->halted_hw : 0);
	for (int i = 0; i < p->swmap_count; i++) {
		if (p->swmap[i].hthread == (uint32_t)p->halted_hw) {
			rtos->current_thread = QURT_TID_SW(p->swmap[i].swid);
			break;
		}
	}

	/* Promoted to INFO so the SW-walk result (how many TCBs were found valid)
	 * is visible at the default log level for bring-up. */
	LOG_DEBUG("qurt: published %d threads (%u HW + %d SW), current=0x%" PRIx64,
		  rtos->thread_count, hw_count, swmap_idx,
		  (uint64_t)rtos->current_thread);
	return ERROR_OK;
}

/* Find the TCB for a given SW threadid using the swmap built in update. */
static target_addr_t qurt_tcb_for_swid(struct qurt_params *p, uint32_t swid,
		uint32_t *hthread_out)
{
	for (int i = 0; i < p->swmap_count; i++) {
		if (p->swmap[i].swid == swid) {
			if (hthread_out)
				*hthread_out = p->swmap[i].hthread;
			return p->swmap[i].tcb;
		}
	}
	return 0;
}

/* Validate a gdb thread_id against the currently-published thread list and,
 * on success, hand back the target that should service operations for it.
 *
 * Installed as rtos->gdb_target_for_threadid in qurt_create(). The default
 * rtos_target_for_threadid() (rtos.c) accepts ANY thread_id unconditionally;
 * with that in place, gdb_server.c's vCont handler treats a malformed/stale id
 * (e.g. `vCont;s:0`, `vCont;s:ffff`) as valid and emits a synthetic stop-reply
 * for a non-existent thread. By rejecting ids that are neither a valid HW tnum
 * nor a swid present in the current swmap, gdb gets a proper "invalid thread"
 * error instead of a fabricated stop. All served operations use the single
 * Hexagon target itself (per-thread selection is internal to the driver). */
static int qurt_gdb_target_for_threadid(struct connection *connection,
		int64_t thread_id, struct target **p_target)
{
	struct target *target = get_target_from_connection(connection);
	if (!target || !target->rtos || !target->rtos->rtos_specific_params)
		return ERROR_FAIL;
	struct qurt_params *p = target->rtos->rtos_specific_params;

	bool valid = false;
	if (QURT_TID_IS_HW(thread_id)) {
		uint32_t tnum = QURT_TID_PAYLOAD(thread_id);
		/* Accept any HW tnum within the published HW-thread count. Before the
		 * walk is enabled max_hthreads is 0, so also accept the default 12. */
		uint32_t hw_count = p->max_hthreads ? p->max_hthreads
						    : QURT_DEFAULT_MAX_HTHREADS;
		valid = (tnum < hw_count);
	} else {
		uint32_t swid = QURT_TID_PAYLOAD(thread_id);
		valid = (qurt_tcb_for_swid(p, swid, NULL) != 0);
	}

	if (!valid) {
		LOG_DEBUG("qurt: rejecting unknown thread_id 0x%" PRIx64, thread_id);
		return ERROR_FAIL;
	}

	*p_target = target;
	return ERROR_OK;
}

static int qurt_get_thread_reg_list(struct rtos *rtos, int64_t thread_id,
		struct rtos_reg **reg_list, int *num_regs)
{
	struct qurt_params *p;

	if (!rtos || !rtos->rtos_specific_params)
		return ERROR_FAIL;
	p = rtos->rtos_specific_params;

#if QURT_PASSIVE_TEST
	/* DIAGNOSTIC: never reconstruct anything; always defer to the live
	 * register path (no memw). */
	(void)reg_list;
	(void)num_regs;
	return ERROR_FAIL;
#endif

	if (QURT_TID_IS_HW(thread_id)) {
		/* HW tier: serve the register set from the hexagon driver's cached
		 * per-HW-thread registers (no target reads). Required for every HW
		 * thread on this SMP target, or the whole register fetch aborts. */
		uint32_t tnum = QURT_TID_PAYLOAD(thread_id);
		return hexagon_rtos_get_hwthread_reg_list(rtos->target, tnum,
				reg_list, num_regs);
	}

	/* SW tier */
	uint32_t swid = QURT_TID_PAYLOAD(thread_id);
	uint32_t hthread = 0xff;
	target_addr_t tcb = qurt_tcb_for_swid(p, swid, &hthread);
	LOG_DEBUG("qurt: get_thread_reg_list SW swid=0x%" PRIx32 " tcb=0x%08x hthread=%u max_hth=%u",
		 swid, (unsigned)tcb, hthread, p->max_hthreads);
	if (tcb == 0) {
		/* Not an error: gdb/lldb may query a stale/default thread id
		 * (e.g. 0x1) before our thread list is published. Let the gdb
		 * layer fall back to the live register path. */
		LOG_DEBUG("qurt: SW swid=0x%" PRIx32 " NOT in list -> defer to live path", swid);
		return ERROR_FAIL;
	}

	if (hthread < p->max_hthreads) {
		/* Thread is currently running on a HW thread -> its live
		 * registers are the truth. Defer to the live path. */
		LOG_DEBUG("qurt: SW swid=0x%" PRIx32 " RUNNING on HW%u -> defer to live path "
			 "(framekey NOT supplied; lldb uses live key)", swid, hthread);
		return ERROR_FAIL;
	}

	/* Not running: reconstruct registers directly from the TCB at their
	 * (non-contiguous) byte offsets. rtos_generic_stack_read() is not used
	 * because its uint8_t size field can't cover offsets past 255. */
	{
		const int ngp = QURT_HEX_NUM_GP_REGS;   /* r0..r31 + pc */
		/* +1 for FRAMEKEY (lets lldb unscramble the parked thread's stack;
		 * see QURT_HEX_GDB_FRAMEKEY). */
		const int n = ngp + 1;
		struct rtos_reg *out = calloc(n, sizeof(struct rtos_reg));
		if (!out) {
			LOG_ERROR("qurt: out of memory (reg_list)");
			return ERROR_FAIL;
		}

		/* This runs only when the user has actively selected a parked SW
		 * thread while halted post-init, so the memw HW-MMU read is safe
		 * here and is required to read the TCB's kernel VA. If a register
		 * read fails we must NOT silently report 0 (gdb would show a bogus
		 * R31=0 etc.); surface the failure so gdb falls back to the live
		 * path or reports an error instead of trusting fabricated zeros. */
		for (int k = 0; k < ngp; k++) {
			const struct stack_register_offset *ro = &p->stacking.register_offsets[k];
			uint32_t val = 0;

			out[k].number = ro->number;
			out[k].size   = ro->width_bits;
			if (ro->offset >= 0 &&
			    qurt_read_u32_mmu(rtos, tcb + (uint32_t)ro->offset, &val) != ERROR_OK) {
				LOG_ERROR("qurt: reg reconstruct read failed at tcb=0x%08x off=%d "
					  "-> not reporting fabricated registers", (unsigned)tcb,
					  ro->offset);
				free(out);
				return ERROR_FAIL;
			}
			memcpy(out[k].value, &val, sizeof(val));
		}

		/* Append the parked thread's SAVED framekey so lldb can unscramble
		 * its kernel stack frames (the user->kernel boundary frame still
		 * needs the OS-aware walker for full fidelity). */
		uint32_t framekey = 0;
		if (p->off.framekey)
			qurt_read_u32_mmu(rtos, tcb + p->off.framekey, &framekey);
		out[ngp].number = QURT_HEX_GDB_FRAMEKEY;
		out[ngp].size   = 32;
		memcpy(out[ngp].value, &framekey, sizeof(framekey));
		LOG_DEBUG("qurt: parked sw thread tcb=0x%08x framekey=0x%08" PRIx32
			 " supplied to unwinder (R%d)", (unsigned)tcb, framekey,
			 QURT_HEX_GDB_FRAMEKEY);

		*reg_list = out;
		*num_regs = n;
		return ERROR_OK;
	}
}

/* ------------------------------------------------------------------ */
/* FRAMEKEY-aware FP-chain stack walker (Route B)                      */
/* ------------------------------------------------------------------ */
/* Print a deep backtrace of a parked QuRT SW thread. lldb's own unwinder only
 * has the live HW thread's framekey and so cannot unscramble a parked thread's
 * return addresses; here we walk the FP chain and unscramble each frame with
 * the thread's saved kernel/user framekeys ourselves. Addresses are printed
 * raw for the host debugger to symbolize. */

/* Kernel/user classification for the FP-chain walk.
 *
 * We must decide, per frame, whether to unscramble the saved return address
 * with the thread's KERNEL framekey (fkey) or its USER framekey (fkey_usr).
 * The QuRT T32 OSAM keys this off the qurtos_trap1_return boundary symbol,
 * but OpenOCD has no symbol table, so we classify by VA region instead.
 *
 * IMPORTANT (cross-target genericity): the kernel VA region base differs per
 * Hexagon subsystem and per SoC (ADSP, CDSP, MPSS, NSP all differ; e.g. one
 * build's kernel code sits at 0xf0......, another's UKERNEL at 0xfe......).
 * We therefore do NOT hardcode a base. Instead we derive it at walk time from
 * the parked thread's OWN saved PC/LR, which are stored UNSCRAMBLED in the TCB
 * (CONTEXT_ssrelr / CONTEXT_r3130+4) and, for a thread parked inside the
 * kernel, point into the kernel text region. We align that address down to a
 * coarse region granule to obtain a per-build kernel base. If neither PC nor
 * LR looks like a plausible code address, we fall back to the thread's saved
 * stack-limit bound (CONTEXT_framelimit) purely for loop termination and skip
 * the kernel/user key switch (single-key walk). No VA constant is baked in.
 * The region granule (QURT_KERNEL_REGION_GRANULE) is defined in qurt.h. */

/* Derive a per-build kernel VA base from a known-kernel address (the parked
 * thread's saved PC or LR). Returns 0 if the address is implausible. */
static uint32_t qurt_kernel_va_base_from(uint32_t known_kernel_addr)
{
	/* A plausible code address is non-zero and not obviously a small
	 * integer / sentinel. Align down to the region granule so any address
	 * within the same 256 MB window maps to the same base. */
	if (known_kernel_addr < QURT_KERNEL_REGION_GRANULE)
		return 0;
	return known_kernel_addr & ~(QURT_KERNEL_REGION_GRANULE - 1u);
}

int qurt_stack_walk(struct target *target, int64_t swid,
		struct command_invocation *cmd)
{
	if (!target || !target->rtos || !target->rtos->rtos_specific_params) {
		command_print(cmd, "qurt: no RTOS/params");
		return ERROR_FAIL;
	}
	struct rtos *rtos = target->rtos;
	struct qurt_params *p = rtos->rtos_specific_params;

	if (!p->walk_enabled || !p->constants_cached) {
		command_print(cmd, "qurt: walk not enabled / constants not cached "
				   "(run qurtEnable first)");
		return ERROR_FAIL;
	}

	uint32_t hthread = 0xff;
	target_addr_t tcb = qurt_tcb_for_swid(p, (uint32_t)swid, &hthread);
	if (tcb == 0) {
		command_print(cmd, "qurt: SW thread id %" PRId64 " not found", swid);
		return ERROR_FAIL;
	}

	/* Only parked threads have a usable saved context in their TCB. If the
	 * thread is currently scheduled on a HW core (hthread < max_hthreads) its
	 * saved TCB context is stale (the live regs are the truth). Mirror the
	 * guard in qurt_get_thread_reg_list() and refuse rather than emit a
	 * backtrace built from never-saved context. */
	if (hthread < p->max_hthreads) {
		command_print(cmd, "qurt: SW thread id %" PRId64 " is RUNNING on HW%u; "
			      "use 'thread backtrace' on the live HW thread instead",
			      swid, hthread);
		return ERROR_FAIL;
	}

	/* Read the parked thread's saved PC/FP/LR/framekeys. These reads are
	 * error-checked as a block: if any fails, walking from a zero PC/FP would
	 * emit a bogus backtrace, so surface the failure to the caller instead. */
	uint32_t pc = 0, fp = 0, lr = 0, fkey = 0, guest_info = 0, fkey_usr = 0;
	if (qurt_read_u32_mmu(rtos, tcb + p->off.ssrelr,    &pc) != ERROR_OK ||
	    qurt_read_u32_mmu(rtos, tcb + p->off.r3130,     &fp) != ERROR_OK ||
	    qurt_read_u32_mmu(rtos, tcb + p->off.r3130 + 4, &lr) != ERROR_OK) {
		command_print(cmd, "qurt: failed to read saved PC/FP/LR from tcb=0x%08x",
			      (unsigned)tcb);
		return ERROR_FAIL;
	}
	if (p->off.framekey &&
	    qurt_read_u32_mmu(rtos, tcb + p->off.framekey, &fkey) != ERROR_OK) {
		command_print(cmd, "qurt: failed to read framekey from tcb=0x%08x",
			      (unsigned)tcb);
		return ERROR_FAIL;
	}

	/* user frame key (fkey_usr), per OSAM GetContext:
	 *   gi = *(tcb + guest_info);
	 *   if (gi) fkey_usr = *( gi - 20 );    (20 = QDI_CTXT_SIZE - FKEYLIMIT - 4)
	 * These are best-effort: fkey_usr is only needed for the kernel->user
	 * boundary frame, so a failed read here just leaves fkey_usr=0 and we do
	 * a single-key walk rather than aborting the whole backtrace. */
	if (p->off.guest_info) {
		if (qurt_read_u32_mmu(rtos, tcb + p->off.guest_info, &guest_info) == ERROR_OK
		    && guest_info)
			qurt_read_u32_mmu(rtos, guest_info - QURT_FKEY_USR_BACKOFF, &fkey_usr);
	}

	/* Derive the per-build kernel VA base from this thread's OWN saved
	 * PC/LR (stored unscrambled in the TCB). A thread parked inside the
	 * kernel has a kernel-region PC; use it, else fall back to LR. If both
	 * are implausible, kernel_va_base stays 0 and we do a single-key walk
	 * (no kernel/user switch) — correct for a fully-user or fully-kernel
	 * thread and never worse than a hardcoded constant. This keeps the
	 * walker correct across ADSP/CDSP/MPSS/NSP without any baked-in VA. */
	uint32_t kernel_va_base = qurt_kernel_va_base_from(pc);
	if (kernel_va_base == 0)
		kernel_va_base = qurt_kernel_va_base_from(lr);

	/* Read the thread's stack-limit bound (CONTEXT_framelimit) for loop
	 * termination: a valid FP must stay at/above the stack limit. 0 means
	 * "unknown" -> we skip the bound check and rely on fp==0 / fp-not-moving. */
	uint32_t stack_limit = 0;
	if (p->off.framelimit)
		qurt_read_u32_mmu(rtos, tcb + p->off.framelimit, &stack_limit);

	command_print(cmd, "QuRT stack for SW thread %" PRId64 " (tcb=0x%08x):",
		      swid, (unsigned)tcb);
	command_print(cmd, "  fkey=0x%08" PRIx32 " fkey_usr=0x%08" PRIx32
		      " fp=0x%08" PRIx32 " kbase=0x%08" PRIx32 " slimit=0x%08" PRIx32,
		      fkey, fkey_usr, fp, kernel_va_base, stack_limit);
	command_print(cmd, "  #0  0x%08" PRIx32, pc);
	command_print(cmd, "  #1  0x%08" PRIx32, lr);

	/* Only the FIRST frame is de-duped; a legitimate
	 * genuine recursion deeper in the chain is preserved. */
	uint32_t last_emitted = lr;
	bool in_user = false;
	int frame = 2;
	for (int depth = 0; depth < QURT_STACK_MAX_FRAMES; depth++) {
		if (fp == 0)
			break;

		uint32_t raw = 0;
		if (qurt_read_u32_mmu(rtos, fp + 4, &raw) != ERROR_OK) {
			command_print(cmd, "  (read failed at fp+4=0x%08" PRIx32 ")", fp + 4);
			break;
		}

		/* Unscramble with the current key. The QuRT scheme scrambles the
		 * saved return address with the KERNEL framekey while in kernel
		 * frames and with the USER framekey once execution crosses back to
		 * the user side. The T32 OSAM detects that boundary via a symbol;
		 * OpenOCD has no symbol table, so we detect it by region using the
		 * per-build kernel base derived above. */
		uint32_t key = in_user ? fkey_usr : fkey;
		uint32_t ret = raw ^ key;

		/* Boundary detection: if we have a kernel base and a user key, and
		 * the kernel-key result does NOT land in the kernel region, this is
		 * the kernel->user transition frame — re-derive with the user key
		 * and stay in user mode for the remaining frames. When kernel_va_base
		 * is 0 (couldn't be derived) we skip the switch (single-key walk). */
		if (!in_user && fkey_usr && kernel_va_base &&
		    (ret & ~(QURT_KERNEL_REGION_GRANULE - 1u)) != kernel_va_base) {
			in_user = true;
			ret = raw ^ fkey_usr;
		}

		/* Suppress only the first recovered frame when it repeats the LR
		 * already printed as #1 (the LR-in-[fp+4] seam described above). */
		if (!(depth == 0 && ret == last_emitted)) {
			command_print(cmd, "  #%d  0x%08" PRIx32, frame, ret);
			frame++;
		}
		last_emitted = ret;

		uint32_t next_fp = 0;
		if (qurt_read_u32_mmu(rtos, fp, &next_fp) != ERROR_OK)
			break;
		if (next_fp == 0 || next_fp == fp)
			break;
		/* FP must climb monotonically; if it ever goes backwards the chain
		 * is corrupt. Also bound by the thread's stack limit when known
		 * (mirrors the T32 walker's stack_limit termination). */
		if (next_fp < fp)
			break;
		if (stack_limit && next_fp < stack_limit)
			break;
		fp = next_fp;
	}

	command_print(cmd, "  (end; host: use 'image lookup -a <addr>' to symbolize)");
	return ERROR_OK;
}

/* ------------------------------------------------------------------ */
/* OSAM-driven TCB-layout push (DWARF-authoritative offsets)          */
/* ------------------------------------------------------------------ */
/* Called from the `hexagon qurtSetOffsets` command handler in hexagon.c,
 * which is issued by the lldb-side OSAM (utils.py) once the ELF has been
 * loaded. The OSAM resolves the TCB layout from the ELF's DWARF by struct
 * member NAME (e.g. FindFirstType("QURTK_thread_context").GetByteSize(),
 * get_struct_field_offset(struct_type, "prio"), etc.) so this is the
 * authoritative, per-build source of truth -- immune to the SIZEOF_TCB
 * 384-vs-448 and utcb_name 28-vs-32 hazards the hardcoded defaults have.
 *
 * The command fires AFTER the ELF+DWARF are loaded (types resolvable in
 * lldb) and BEFORE the first halt-driven qXfer:threads:read (when
 * qurt_update_threads first uses these offsets), so ordering is safe --
 * see qurt_cache_constants which gates on p->offsets_pushed.
 *
 * Idempotent: pushing again just overwrites and re-triggers cache rebuild
 * on the next qurt_cache_constants call.
 *
 * If no RTOS is attached (target created without -rtos qurt) returns
 * ERROR_FAIL; the caller (command handler) then reports the error to lldb. */
int qurt_apply_pushed_offsets(struct target *target,
		uint32_t context_size,
		uint32_t prio, uint32_t thread_id, uint32_t ugpgp,
		uint32_t hthread, uint32_t ssrelr,
		uint32_t r0100, uint32_t r2928, uint32_t r3130,
		uint32_t framelimit, uint32_t framekey,
		uint32_t guest_info, uint32_t utcb_name)
{
	if (!target || !target->rtos || !target->rtos->rtos_specific_params) {
		LOG_ERROR("qurt: apply_pushed_offsets: no RTOS/params (target=%p rtos=%p)",
			  (void *)target,
			  target ? (void *)target->rtos : NULL);
		return ERROR_FAIL;
	}
	struct qurt_params *p = target->rtos->rtos_specific_params;

	p->context_size    = context_size;
	p->off.prio        = prio;
	p->off.thread_id   = thread_id;
	p->off.ugpgp       = ugpgp;
	p->off.hthread     = hthread;
	p->off.ssrelr      = ssrelr;
	p->off.r0100       = r0100;
	p->off.r2928       = r2928;
	p->off.r3130       = r3130;
	p->off.framelimit  = framelimit;
	p->off.framekey    = framekey;
	p->off.guest_info  = guest_info;
	p->off.utcb_name   = utcb_name;
	p->off.valid       = true;

	p->offsets_pushed  = true;

	/* Force re-cache on the next update so the pushed values take effect and
	 * the stacking is rebuilt from them (rather than serving stale cached
	 * values from before the push). */
	p->constants_cached = false;

	LOG_INFO("qurt: applied pushed TCB layout (OSAM/DWARF): "
		 "ctx_size=%u prio=%u tid=%u ugpgp=%u hthread=%u ssrelr=%u "
		 "r0100=%u r2928=%u r3130=%u flim=%u fkey=%u ginfo=%u utcb=%u",
		 context_size, prio, thread_id, ugpgp, hthread, ssrelr,
		 r0100, r2928, r3130, framelimit, framekey, guest_info, utcb_name);

	/* If the target is already halted and the walk is enabled, refresh the
	 * thread list right now so a subsequent qXfer:threads:read sees the
	 * corrected layout without waiting for another user-visible stop. */
	if (target->state == TARGET_HALTED && p->walk_enabled)
		qurt_update_threads(target->rtos);

	return ERROR_OK;
}


