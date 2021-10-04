#
# Copyright (c) 2017-2021, ARM Limited and Contributors. All rights reserved.
#
# SPDX-License-Identifier: BSD-3-Clause
#

ifneq (${SPD},none)
        $(error "Error: SPD and SPM_MM are incompatible build options.")
endif
ifneq (${ARCH},aarch64)
        $(error "Error: SPM_MM is only supported on aarch64.")
endif

SPM_MM_SOURCES	:=	$(addprefix services/std_svc/spm/spm_mm/,	\
			spm_mm_main.c					\
			spm_mm_common.c					\
			spm_mm_xlat.c					\
			spm_mm_setup.c)


# Let the top-level Makefile know that we intend to include a BL32 image
NEED_BL32		:=	yes

# required so that SPM code executing at S-EL0 can access the timer registers
NS_TIMER_SWITCH		:=	1
