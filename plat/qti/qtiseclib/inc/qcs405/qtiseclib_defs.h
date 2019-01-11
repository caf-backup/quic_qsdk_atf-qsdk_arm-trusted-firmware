/*
 * Copyright (c) 2018-2019, The Linux Foundation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __QTISECLIB_DEFS_H__
#define __QTISECLIB_DEFS_H__

#include <stdint.h>

#ifndef u_register_t
typedef uintptr_t u_register_t;
#endif

#define QTISECLIB_PLAT_CLUSTER_COUNT	1
#define QTISECLIB_PLAT_CORE_COUNT	8

/* Different Log Level supported in qtiseclib.
   TODO: Currently no filtering done on QTISECLIB logs. */
#define QTISECLIB_LOG_LEVEL_NONE	0
#define QTISECLIB_LOG_LEVEL_ERROR	10
#define QTISECLIB_LOG_LEVEL_NOTICE	20
#define QTISECLIB_LOG_LEVEL_WARNING	30
#define QTISECLIB_LOG_LEVEL_INFO	40
#define QTISECLIB_LOG_LEVEL_VERBOSE	50

#define QTI_GICV3_IRM_PE		0
#define QTI_GICV3_IRM_ANY		1

/* Interrupt number/ID defs. TODO: Chipset specific.
   Need to be feature gurded with Chipset Macro. */
#define QTISECLIB_INT_ID_SEC_WDOG_BARK			(0xD5)
#define QTISECLIB_INT_ID_NON_SEC_WDOG_BITE		(0x24)
#define QTISECLIB_INT_ID_RESET_SGI			(0xf)
#define QTISECLIB_INT_ID_CPU_WAKEUP_SGI			(0x8)

#define QTISECLIB_INT_ID_VMIDMT_ERR_CLT_SEC		(0xE6)
#define QTISECLIB_INT_ID_VMIDMT_ERR_CLT_NONSEC		(0xE7)
#define QTISECLIB_INT_ID_VMIDMT_ERR_CFG_SEC		(0xE8)
#define QTISECLIB_INT_ID_VMIDMT_ERR_CFG_NONSEC		(0xE9)

#define QTISECLIB_INT_ID_XPU_SEC			(0xE3)
#define QTISECLIB_INT_ID_XPU_NON_SEC			(0xE4)

#define QTISECLIB_INT_ID_A1_NOC_ERROR			(0x18B)
#define QTISECLIB_INT_ID_A2_NOC_ERROR			(0x194)
#define QTISECLIB_INT_ID_CONFIG_NOC_ERROR		(0xE2)
#define QTISECLIB_INT_ID_DC_NOC_ERROR			(0x122)
#define QTISECLIB_INT_ID_MEM_NOC_ERROR			(0x6C)
#define QTISECLIB_INT_ID_SYSTEM_NOC_ERROR		(0xC6)
#define QTISECLIB_INT_ID_MMSS_NOC_ERROR			(0xBA)
#define	QTISECLIB_INT_INVALID_INT_NUM			(0xFFFFFFFFU)

/* External CPU Dump Structure - 64 bit EL */
typedef struct
{
	uint64_t x0;
	uint64_t x1;
	uint64_t x2;
	uint64_t x3;
	uint64_t x4;
	uint64_t x5;
	uint64_t x6;
	uint64_t x7;
	uint64_t x8;
	uint64_t x9;
	uint64_t x10;
	uint64_t x11;
	uint64_t x12;
	uint64_t x13;
	uint64_t x14;
	uint64_t x15;
	uint64_t x16;
	uint64_t x17;
	uint64_t x18;
	uint64_t x19;
	uint64_t x20;
	uint64_t x21;
	uint64_t x22;
	uint64_t x23;
	uint64_t x24;
	uint64_t x25;
	uint64_t x26;
	uint64_t x27;
	uint64_t x28;
	uint64_t x29;
	uint64_t x30;
	uint64_t pc;
	uint64_t currentEL;
	uint64_t sp_el3;
	uint64_t elr_el3;
	uint64_t spsr_el3;
	uint64_t sp_el2;
	uint64_t elr_el2;
	uint64_t spsr_el2;
	uint64_t sp_el1;
	uint64_t elr_el1;
	uint64_t spsr_el1;
	uint64_t sp_el0;
	uint64_t __reserved1;
	uint64_t __reserved2;
	uint64_t __reserved3;
	uint64_t __reserved4;
	uint64_t __reserved5;
	uint64_t __reserved6;
	uint64_t __reserved7;
	uint64_t __reserved8;
}qtiseclib_dbg_a64_ctxt_regs_type;

typedef struct qtiseclib_cb_spinlock {
	volatile uint32_t lock;
} qtiseclib_cb_spinlock_t;

typedef enum qtiseclib_mmap_attr_s {
	QTISECLIB_MAP_NS_RO_XN_DATA = 1,
	QTISECLIB_MAP_RW_XN_NC_DATA = 2,
	QTISECLIB_MAP_RW_XN_DATA = 3,
} qtiseclib_mmap_attr_t;

#endif /* __QTISECLIB_DEFS_H__ */