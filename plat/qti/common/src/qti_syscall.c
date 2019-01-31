/*
 * Copyright (c) 2018, ARM Limited and Contributors. All rights reserved.
 * Copyright (c) 2018-2019, The Linux Foundation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <common/debug.h>
#include <context.h>
#include <xlat_tables_v2.h>
#include <common/runtime_svc.h>
#include <uuid.h>
#include <smccc_helpers.h>
#include <utils_def.h>
#include <plat_qti.h>
#include <qti_secure_io_cfg.h>
#include <qtiseclib_interface.h>


/*----------------------------------------------------------------------------
 * SIP service - SMC function IDs for SiP Service queries
 * -------------------------------------------------------------------------*/
#define	QTI_SIP_SVC_CALL_COUNT_ID			U(0x0200ff00)
#define	QTI_SIP_SVC_UID_ID					U(0x0200ff01)
/*							0x8200ff02 is reserved */
#define	QTI_SIP_SVC_VERSION_ID				U(0x0200ff03)

/*
 * Syscall's to allow Non Secure world accessing peripheral/IO memory
 * those are secure/proteced BUT not required to be secure.
 */
#define	QTI_SIP_SVC_SECURE_IO_READ_ID		U(0x02000501)
#define	QTI_SIP_SVC_SECURE_IO_WRITE_ID		U(0x02000502)

/*
 * Syscall's to assigns a list of intermediate PAs from a
 * source Virtual Machine (VM) to a destination VM.
 */
#define	QTI_SIP_SVC_MEM_ASSIGN_ID			U(0x02000C16)

#define	QTI_SIP_SVC_SECURE_IO_READ_PARAM_ID		U(0x1)
#define	QTI_SIP_SVC_SECURE_IO_WRITE_PARAM_ID	U(0x2)
#define	QTI_SIP_SVC_MEM_ASSIGN_PARAM_ID			U(0x1117)

#define	QTI_SIP_SVC_CALL_COUNT			U(0x3)
#define QTI_SIP_SVC_VERSION_MAJOR		U(0x0)
#define	QTI_SIP_SVC_VERSION_MINOR		U(0x0)


#define	FUNCID_OEN_NUM_MASK  ((FUNCID_OEN_MASK << FUNCID_OEN_SHIFT)\
				|(FUNCID_NUM_MASK << FUNCID_NUM_SHIFT) )

/* QTI SiP Service UUID */
DEFINE_SVC_UUID2(qti_sip_svc_uid,
		0x43864748, 0x217f, 0x41ad, 0xaa, 0x5a,
		0xba, 0xe7, 0x0f, 0xa5, 0x52, 0xaf);


static bool qti_is_secure_io_access_allowed(u_register_t addr)
{
	int i = 0;

	for (i = 0; i < ARRAY_SIZE(qti_secure_io_allowed_regs); i++)
	{
		if ((uintptr_t)addr == qti_secure_io_allowed_regs[i])
		{
			return true;
		}
	}

  return false;
}

static uintptr_t qti_sip_mem_assign(void *handle, uint32_t smc_cc,
									u_register_t x1,
									u_register_t x2,
									u_register_t x3,
									u_register_t x4)
{
	uintptr_t dyn_map_start, dyn_map_end;
	size_t dyn_map_size;
	u_register_t x6, x7, x8;
	int ret = SMC_UNK;
	u_register_t x5 = read_ctx_reg(get_gpregs_ctx(handle), CTX_GPREG_X5);

	do {
		if (SMC_32 == smc_cc) {
			x5 = (uint32_t)x5;
		}
		/* Validate input arg count & retrieve arg3-6 from NS Buffer. */
		if ((QTI_SIP_SVC_MEM_ASSIGN_PARAM_ID != x1) &&
			(0x0 == x5)) {
			break;
		}

		/* Map NS Buffer. */
		dyn_map_start = x5;
		dyn_map_size = (SMC_32 == smc_cc) ? (sizeof(uint32_t) * 4) : (sizeof(uint64_t) * 4);
		if (0 != qti_mmap_add_dynamic_region(dyn_map_start, dyn_map_start,
					dyn_map_size, (MT_NS | MT_RO | MT_EXECUTE_NEVER))) {
			break;
		}
		/* Retrieve indirect args. */
		if (SMC_32 == smc_cc) {
			x6 = *((uint32_t *)x5 + 1);
			x7 = *((uint32_t *)x5 + 2);
			x8 = *((uint32_t *)x5 + 3);
			x5 = *(uint32_t *)x5;
		} else {
			x6 = *((uint64_t *)x5 + 1);
			x7 = *((uint64_t *)x5 + 2);
			x8 = *((uint32_t *)x5 + 3);
			x5 = *(uint64_t *)x5;
		}

		/* Un-Map NS Buffer. */
		if (0 != qti_mmap_remove_dynamic_region(dyn_map_start, dyn_map_size)) {
			break;
		}

		/* Map NS Buffers.
		   arg0,2,4 points to buffers & arg1,3,5 hold sizes.
		   MAP api's fail to map if it's already mapped. Let's
		   find lowest start & highest end address, then map once. */
		dyn_map_start = MIN(x2, x4);
		dyn_map_start = MIN(dyn_map_start, x6);
		dyn_map_end = MAX((x2 + x3), (x4 + x5));
		dyn_map_end = MAX(dyn_map_end, (x6 + x7));
		dyn_map_size = dyn_map_end - dyn_map_start;

		if (0 != qti_mmap_add_dynamic_region(dyn_map_start, dyn_map_start,
					 dyn_map_size, (MT_NS | MT_RO | MT_EXECUTE_NEVER))) {
			break;
		}

		/* Invoke API lib api. */
		ret = qtiseclib_mem_assign(x2, x3, x4, x5, x6, x7, x8);

		/* Un-Map NS Buffers. */
		if (0 != qti_mmap_remove_dynamic_region(dyn_map_start, dyn_map_size)) {
			break;
		}

		if (0 == ret) {
			SMC_RET2(handle, SMC_OK, ret);
		}

	}while(0);

	SMC_RET2(handle, SMC_UNK, ret);
}

/*
 * This function handles QTI specific syscalls. Currently only SiP calls are present.
 * Both FAST & YIELD type call land here.
 */
static uintptr_t qti_sip_handler(uint32_t smc_fid,
				 u_register_t x1,
				 u_register_t x2,
				 u_register_t x3,
				 u_register_t x4,
				 void *cookie, void *handle, u_register_t flags)
{
	uint32_t l_smc_fid = smc_fid & FUNCID_OEN_NUM_MASK;

	if (SMC_32 == GET_SMC_CC(smc_fid)) {
		x1 = (uint32_t)x1;
		x2 = (uint32_t)x2;
		x3 = (uint32_t)x3;
		x4 = (uint32_t)x4;
	}

	switch (l_smc_fid) {
	case QTI_SIP_SVC_CALL_COUNT_ID:
		{
			SMC_RET1(handle, QTI_SIP_SVC_CALL_COUNT);
		}

	case QTI_SIP_SVC_UID_ID:
		{
			/* Return UID to the caller */
			SMC_UUID_RET(handle, qti_sip_svc_uid);
		}

	case QTI_SIP_SVC_VERSION_ID:
		{
			/* Return the version of current implementation */
			SMC_RET2(handle, QTI_SIP_SVC_VERSION_MAJOR,
					 QTI_SIP_SVC_VERSION_MINOR);
		}
	case QTI_SIP_SVC_SECURE_IO_READ_ID:
		{
			if ((QTI_SIP_SVC_SECURE_IO_READ_PARAM_ID == x1) &&
			    qti_is_secure_io_access_allowed(x2)) {
				SMC_RET2(handle, SMC_OK, *((volatile uint32_t*)x2));
			}
			SMC_RET1(handle, SMC_UNK);
		}
	case QTI_SIP_SVC_SECURE_IO_WRITE_ID:
		{
			if ((QTI_SIP_SVC_SECURE_IO_WRITE_PARAM_ID == x1) &&
			    qti_is_secure_io_access_allowed(x2)) {
				*((volatile uint32_t *)x2) = x3;
				SMC_RET1(handle, SMC_OK);
			}
			SMC_RET1(handle, SMC_UNK);
		}
	case QTI_SIP_SVC_MEM_ASSIGN_ID:
		{
			return qti_sip_mem_assign(handle, GET_SMC_CC(smc_fid),
									  x1, x2, x3, x4);
		}
	default:
		{
			SMC_RET1(handle, SMC_UNK);
		}
	}
	return (uintptr_t) handle;
}

/* Define a runtime service descriptor for both fast & yield SiP calls */
DECLARE_RT_SVC(qti_sip_fast_svc, OEN_SIP_START,
	       OEN_SIP_END, SMC_TYPE_FAST, NULL, qti_sip_handler);

DECLARE_RT_SVC(qti_sip_yield_svc, OEN_SIP_START,
	       OEN_SIP_END, SMC_TYPE_YIELD, NULL, qti_sip_handler);
