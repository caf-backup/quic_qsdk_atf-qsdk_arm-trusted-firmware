/*
 * Copyright (c) 2018, The Linux Foundation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef __QTISECLIB_INTERFACE_H__
#define __QTISECLIB_INTERFACE_H__

#include <stdint.h>
#include <qtiseclib_defs.h>

/*----------------------------------------------------------------------------
 * QTISECLIB Published API's.
 * -------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
 * Assembly API's
 * -------------------------------------------------------------------------*/

/*
 * CPUSS common reset handler for all CPU wake up (both cold & warm boot).
 * Executes on all core. This API assume serialization across CPU
 * already taken care before invoking.
 *
 * Clobbers: x0 - x17, x30
 */
void qtiseclib_cpuss_reset_asm(uint32_t bl31_cold_boot_state);

/*
 * Execute CPU (Kryo3 gold) specific reset handler / system initialization.
 * This takes care of executing required CPU errata's.
 *
 * Clobbers: x0 - x16
 */
void qtiseclib_kryo3_gold_reset_asm(void);

/*
 * Execute CPU (Kryo3 silver) specific reset handler / system initialization.
 * This takes care of executing required CPU errata's.
 *
 * Clobbers: x0 - x16
 */
void qtiseclib_kryo3_silver_reset_asm(void);

/*----------------------------------------------------------------------------
 * C Api's
 * -------------------------------------------------------------------------*/
void qtiseclib_bl31_platform_setup(void);
void qtiseclib_invoke_isr(uint32_t irq, void *handle);
void qtiseclib_sip_syscall(qtiseclib_smc_param_t * p_smcparams,
			   qtiseclib_smc_rsp_t * p_smcrsps);
void qtiseclib_panic(void);

int qtiseclib_psci_init(void);
int qtiseclib_psci_node_power_on(u_register_t mpidr);
void qtiseclib_psci_node_on_finish(const uint8_t * states);
void qtiseclib_psci_cpu_standby(uint8_t pwr_state);
void qtiseclib_psci_node_power_off(const uint8_t * states);
void qtiseclib_psci_node_suspend(const uint8_t * states);
void qtiseclib_psci_node_suspend_finish(const uint8_t * states);
__attribute__((noreturn)) void qtiseclib_psci_system_off(void);
__attribute__((noreturn)) void qtiseclib_psci_system_reset(void);
int qtiseclib_psci_validate_power_state(unsigned int pwr_state, uint8_t * req_state);

#endif /* __QTISECLIB_INTERFACE_H__ */
