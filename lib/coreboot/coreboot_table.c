/*
 * Copyright (c) 2017, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <assert.h>
#include <string.h>

#include <drivers/coreboot/cbmem_console.h>
#include <common/debug.h>
#include <lib/coreboot.h>
#include <lib/mmio.h>
#include <lib/xlat_tables/xlat_tables_v2.h>

/*
 * Structures describing coreboot's in-memory descriptor tables. See
 * <coreboot>/src/commonlib/include/commonlib/coreboot_tables.h for
 * canonical implementation.
 */

typedef struct {
	char signature[4];
	uint32_t header_bytes;
	uint32_t header_checksum;
	uint32_t table_bytes;
	uint32_t table_checksum;
	uint32_t table_entries;
} cb_header_t;

typedef enum {
	CB_TAG_SERIAL = 0xf,
	CB_TAG_CBMEM_CONSOLE = 0x17,
	CB_TAG_VBOOT_HANDOFF = 0x20,
} cb_tag_t;

typedef struct __attribute__((__packed__)){
	uint32_t tag;
	uint32_t size;
	union {
		coreboot_serial_t serial;
		uint64_t uint64;
	};
} cb_entry_t;

coreboot_serial_t coreboot_serial;

typedef struct __attribute__((__packed__)){
	uint32_t tag;
	uint32_t size;

	uint64_t range_start;
	uint32_t range_size;
} lb_range_t;

/*
 * The vboot_handoff structure contains the data to be consumed by downstream
 * firmware after firmware selection has been completed. Namely it provides
 * vboot shared data as well as the flags from VbInit.
 */
//#define VB_SHARED_DATA_MIN_SIZE 3072
typedef struct VbInitParams {
	uint32_t deprecated; /* Was init flags */
	uint32_t out_flags;
} VbInitParams;

typedef struct __attribute__((__packed__)){
	VbInitParams init_params;
	uint32_t selected_firmware;
	char shared_data[/* VB_SHARED_DATA_MIN_SIZE */];
} vboot_handoff_t;

static vboot_handoff_t vboot_handoff;


/*
 * The coreboot table is parsed before the MMU is enabled (i.e. with strongly
 * ordered memory), so we cannot make unaligned accesses. The table entries
 * immediately follow one another without padding, so nothing after the header
 * is guaranteed to be naturally aligned. Therefore, we need to define safety
 * functions that can read unaligned integers.
 */
static uint32_t read_le32(uint32_t *p)
{
	uintptr_t addr = (uintptr_t)p;
	return mmio_read_8(addr)		|
	       mmio_read_8(addr + 1) << 8	|
	       mmio_read_8(addr + 2) << 16	|
	       mmio_read_8(addr + 3) << 24;
}
static uint64_t read_le64(uint64_t *p)
{
	return read_le32((void *)p) | (uint64_t)read_le32((void *)p + 4) << 32;
}

static void expand_and_mmap(uintptr_t baseaddr, size_t size)
{
	uintptr_t pageaddr = round_down(baseaddr, PAGE_SIZE);
	size_t expanded = round_up(baseaddr - pageaddr + size, PAGE_SIZE);
	mmap_add_region(pageaddr, pageaddr, expanded,
			MT_MEMORY | MT_RW | MT_NS | MT_EXECUTE_NEVER);
}

static void setup_cbmem_console(uintptr_t baseaddr)
{
	static console_cbmc_t console;
	assert(!console.base);		/* should only have one CBMEM console */

	/* CBMEM console structure stores its size in first header field. */
	uint32_t size = *(uint32_t *)baseaddr;
	expand_and_mmap(baseaddr, size);
	console_cbmc_register(baseaddr, &console);
	console_set_scope(&console.console, CONSOLE_FLAG_BOOT |
					    CONSOLE_FLAG_RUNTIME |
					    CONSOLE_FLAG_CRASH);
}

static void setup_vboot_handoff_info(lb_range_t * range)
{
	if(range) {
		expand_and_mmap((uintptr_t)range, sizeof(lb_range_t));
		expand_and_mmap((uintptr_t)range->range_start, sizeof(vboot_handoff_t));
		if(range->range_size >= sizeof(vboot_handoff_t)) {
			vboot_handoff = *(vboot_handoff_t *)range->range_start;
		}
	}
}

uint32_t coreboot_get_vbinit_out_flag(void)
{
	return vboot_handoff.init_params.out_flags;
}

void coreboot_table_setup(void *base)
{
	cb_header_t *header = base;
	void *ptr;
	int i;

	if (strncmp(header->signature, "LBIO", 4)) {
		ERROR("coreboot table signature corrupt!\n");
		return;
	}

	ptr = base + header->header_bytes;
	for (i = 0; i < header->table_entries; i++) {
		cb_entry_t *entry = ptr;
		lb_range_t *range = ptr;

		if (ptr - base >= header->header_bytes + header->table_bytes) {
			ERROR("coreboot table exceeds its bounds!\n");
			break;
		}

		switch (read_le32(&entry->tag)) {
		case CB_TAG_SERIAL:
			memcpy(&coreboot_serial, &entry->serial,
			       sizeof(coreboot_serial));
			break;
		case CB_TAG_CBMEM_CONSOLE:
			setup_cbmem_console(read_le64(&entry->uint64));
			break;
		case CB_TAG_VBOOT_HANDOFF:
			setup_vboot_handoff_info(range);
			break;
		default:
			/* There are many tags TF doesn't need to care about. */
			break;
		}

		ptr += read_le32(&entry->size);
	}
}
