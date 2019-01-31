/*
 * Copyright (c) 2015-2018, STMicroelectronics - All Rights Reserved
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef STM32MP1_RCC_H
#define STM32MP1_RCC_H

#include <lib/utils_def.h>

#define RCC_TZCR			U(0x00)
#define RCC_OCENSETR			U(0x0C)
#define RCC_OCENCLRR			U(0x10)
#define RCC_HSICFGR			U(0x18)
#define RCC_CSICFGR			U(0x1C)
#define RCC_MPCKSELR			U(0x20)
#define RCC_ASSCKSELR			U(0x24)
#define RCC_RCK12SELR			U(0x28)
#define RCC_MPCKDIVR			U(0x2C)
#define RCC_AXIDIVR			U(0x30)
#define RCC_APB4DIVR			U(0x3C)
#define RCC_APB5DIVR			U(0x40)
#define RCC_RTCDIVR			U(0x44)
#define RCC_MSSCKSELR			U(0x48)
#define RCC_PLL1CR			U(0x80)
#define RCC_PLL1CFGR1			U(0x84)
#define RCC_PLL1CFGR2			U(0x88)
#define RCC_PLL1FRACR			U(0x8C)
#define RCC_PLL1CSGR			U(0x90)
#define RCC_PLL2CR			U(0x94)
#define RCC_PLL2CFGR1			U(0x98)
#define RCC_PLL2CFGR2			U(0x9C)
#define RCC_PLL2FRACR			U(0xA0)
#define RCC_PLL2CSGR			U(0xA4)
#define RCC_I2C46CKSELR			U(0xC0)
#define RCC_SPI6CKSELR			U(0xC4)
#define RCC_UART1CKSELR			U(0xC8)
#define RCC_RNG1CKSELR			U(0xCC)
#define RCC_CPERCKSELR			U(0xD0)
#define RCC_STGENCKSELR			U(0xD4)
#define RCC_DDRITFCR			U(0xD8)
#define RCC_MP_BOOTCR			U(0x100)
#define RCC_MP_SREQSETR			U(0x104)
#define RCC_MP_SREQCLRR			U(0x108)
#define RCC_MP_GCR			U(0x10C)
#define RCC_MP_APRSTCR			U(0x110)
#define RCC_MP_APRSTSR			U(0x114)
#define RCC_BDCR			U(0x140)
#define RCC_RDLSICR			U(0x144)
#define RCC_APB4RSTSETR			U(0x180)
#define RCC_APB4RSTCLRR			U(0x184)
#define RCC_APB5RSTSETR			U(0x188)
#define RCC_APB5RSTCLRR			U(0x18C)
#define RCC_AHB5RSTSETR			U(0x190)
#define RCC_AHB5RSTCLRR			U(0x194)
#define RCC_AHB6RSTSETR			U(0x198)
#define RCC_AHB6RSTCLRR			U(0x19C)
#define RCC_TZAHB6RSTSETR		U(0x1A0)
#define RCC_TZAHB6RSTCLRR		U(0x1A4)
#define RCC_MP_APB4ENSETR		U(0x200)
#define RCC_MP_APB4ENCLRR		U(0x204)
#define RCC_MP_APB5ENSETR		U(0x208)
#define RCC_MP_APB5ENCLRR		U(0x20C)
#define RCC_MP_AHB5ENSETR		U(0x210)
#define RCC_MP_AHB5ENCLRR		U(0x214)
#define RCC_MP_AHB6ENSETR		U(0x218)
#define RCC_MP_AHB6ENCLRR		U(0x21C)
#define RCC_MP_TZAHB6ENSETR		U(0x220)
#define RCC_MP_TZAHB6ENCLRR		U(0x224)
#define RCC_MP_APB4LPENSETR		U(0x300)
#define RCC_MP_APB4LPENCLRR		U(0x304)
#define RCC_MP_APB5LPENSETR		U(0x308)
#define RCC_MP_APB5LPENCLRR		U(0x30C)
#define RCC_MP_AHB5LPENSETR		U(0x310)
#define RCC_MP_AHB5LPENCLRR		U(0x314)
#define RCC_MP_AHB6LPENSETR		U(0x318)
#define RCC_MP_AHB6LPENCLRR		U(0x31C)
#define RCC_MP_TZAHB6LPENSETR		U(0x320)
#define RCC_MP_TZAHB6LPENCLRR		U(0x324)
#define RCC_BR_RSTSCLRR			U(0x400)
#define RCC_MP_GRSTCSETR		U(0x404)
#define RCC_MP_RSTSCLRR			U(0x408)
#define RCC_MP_IWDGFZSETR		U(0x40C)
#define RCC_MP_IWDGFZCLRR		U(0x410)
#define RCC_MP_CIER			U(0x414)
#define RCC_MP_CIFR			U(0x418)
#define RCC_PWRLPDLYCR			U(0x41C)
#define RCC_MP_RSTSSETR			U(0x420)
#define RCC_MCO1CFGR			U(0x800)
#define RCC_MCO2CFGR			U(0x804)
#define RCC_OCRDYR			U(0x808)
#define RCC_DBGCFGR			U(0x80C)
#define RCC_RCK3SELR			U(0x820)
#define RCC_RCK4SELR			U(0x824)
#define RCC_TIMG1PRER			U(0x828)
#define RCC_TIMG2PRER			U(0x82C)
#define RCC_APB1DIVR			U(0x834)
#define RCC_APB2DIVR			U(0x838)
#define RCC_APB3DIVR			U(0x83C)
#define RCC_PLL3CR			U(0x880)
#define RCC_PLL3CFGR1			U(0x884)
#define RCC_PLL3CFGR2			U(0x888)
#define RCC_PLL3FRACR			U(0x88C)
#define RCC_PLL3CSGR			U(0x890)
#define RCC_PLL4CR			U(0x894)
#define RCC_PLL4CFGR1			U(0x898)
#define RCC_PLL4CFGR2			U(0x89C)
#define RCC_PLL4FRACR			U(0x8A0)
#define RCC_PLL4CSGR			U(0x8A4)
#define RCC_I2C12CKSELR			U(0x8C0)
#define RCC_I2C35CKSELR			U(0x8C4)
#define RCC_SAI1CKSELR			U(0x8C8)
#define RCC_SAI2CKSELR			U(0x8CC)
#define RCC_SAI3CKSELR			U(0x8D0)
#define RCC_SAI4CKSELR			U(0x8D4)
#define RCC_SPI2S1CKSELR		U(0x8D8)
#define RCC_SPI2S23CKSELR		U(0x8DC)
#define RCC_SPI45CKSELR			U(0x8E0)
#define RCC_UART6CKSELR			U(0x8E4)
#define RCC_UART24CKSELR		U(0x8E8)
#define RCC_UART35CKSELR		U(0x8EC)
#define RCC_UART78CKSELR		U(0x8F0)
#define RCC_SDMMC12CKSELR		U(0x8F4)
#define RCC_SDMMC3CKSELR		U(0x8F8)
#define RCC_ETHCKSELR			U(0x8FC)
#define RCC_QSPICKSELR			U(0x900)
#define RCC_FMCCKSELR			U(0x904)
#define RCC_FDCANCKSELR			U(0x90C)
#define RCC_SPDIFCKSELR			U(0x914)
#define RCC_CECCKSELR			U(0x918)
#define RCC_USBCKSELR			U(0x91C)
#define RCC_RNG2CKSELR			U(0x920)
#define RCC_DSICKSELR			U(0x924)
#define RCC_ADCCKSELR			U(0x928)
#define RCC_LPTIM45CKSELR		U(0x92C)
#define RCC_LPTIM23CKSELR		U(0x930)
#define RCC_LPTIM1CKSELR		U(0x934)
#define RCC_APB1RSTSETR			U(0x980)
#define RCC_APB1RSTCLRR			U(0x984)
#define RCC_APB2RSTSETR			U(0x988)
#define RCC_APB2RSTCLRR			U(0x98C)
#define RCC_APB3RSTSETR			U(0x990)
#define RCC_APB3RSTCLRR			U(0x994)
#define RCC_AHB2RSTSETR			U(0x998)
#define RCC_AHB2RSTCLRR			U(0x99C)
#define RCC_AHB3RSTSETR			U(0x9A0)
#define RCC_AHB3RSTCLRR			U(0x9A4)
#define RCC_AHB4RSTSETR			U(0x9A8)
#define RCC_AHB4RSTCLRR			U(0x9AC)
#define RCC_MP_APB1ENSETR		U(0xA00)
#define RCC_MP_APB1ENCLRR		U(0xA04)
#define RCC_MP_APB2ENSETR		U(0xA08)
#define RCC_MP_APB2ENCLRR		U(0xA0C)
#define RCC_MP_APB3ENSETR		U(0xA10)
#define RCC_MP_APB3ENCLRR		U(0xA14)
#define RCC_MP_AHB2ENSETR		U(0xA18)
#define RCC_MP_AHB2ENCLRR		U(0xA1C)
#define RCC_MP_AHB3ENSETR		U(0xA20)
#define RCC_MP_AHB3ENCLRR		U(0xA24)
#define RCC_MP_AHB4ENSETR		U(0xA28)
#define RCC_MP_AHB4ENCLRR		U(0xA2C)
#define RCC_MP_MLAHBENSETR		U(0xA38)
#define RCC_MP_MLAHBENCLRR		U(0xA3C)
#define RCC_MP_APB1LPENSETR		U(0xB00)
#define RCC_MP_APB1LPENCLRR		U(0xB04)
#define RCC_MP_APB2LPENSETR		U(0xB08)
#define RCC_MP_APB2LPENCLRR		U(0xB0C)
#define RCC_MP_APB3LPENSETR		U(0xB10)
#define RCC_MP_APB3LPENCLRR		U(0xB14)
#define RCC_MP_AHB2LPENSETR		U(0xB18)
#define RCC_MP_AHB2LPENCLRR		U(0xB1C)
#define RCC_MP_AHB3LPENSETR		U(0xB20)
#define RCC_MP_AHB3LPENCLRR		U(0xB24)
#define RCC_MP_AHB4LPENSETR		U(0xB28)
#define RCC_MP_AHB4LPENCLRR		U(0xB2C)
#define RCC_MP_AXIMLPENSETR		U(0xB30)
#define RCC_MP_AXIMLPENCLRR		U(0xB34)
#define RCC_MP_MLAHBLPENSETR		U(0xB38)
#define RCC_MP_MLAHBLPENCLRR		U(0xB3C)
#define RCC_VERR			U(0xFF4)
#define RCC_IDR				U(0xFF8)
#define RCC_SIDR			U(0xFFC)

/* Values for RCC_TZCR register */
#define RCC_TZCR_TZEN			BIT(0)

/* Used for most of RCC_<x>SELR registers */
#define RCC_SELR_SRC_MASK		GENMASK(2, 0)
#define RCC_SELR_REFCLK_SRC_MASK	GENMASK(1, 0)
#define RCC_SELR_SRCRDY			BIT(31)

/* Values of RCC_MPCKSELR register */
#define RCC_MPCKSELR_HSI		0x00000000
#define RCC_MPCKSELR_HSE		0x00000001
#define RCC_MPCKSELR_PLL		0x00000002
#define RCC_MPCKSELR_PLL_MPUDIV		0x00000003

/* Values of RCC_ASSCKSELR register */
#define RCC_ASSCKSELR_HSI		0x00000000
#define RCC_ASSCKSELR_HSE		0x00000001
#define RCC_ASSCKSELR_PLL		0x00000002

/* Values of RCC_MSSCKSELR register */
#define RCC_MSSCKSELR_HSI		0x00000000
#define RCC_MSSCKSELR_HSE		0x00000001
#define RCC_MSSCKSELR_CSI		0x00000002
#define RCC_MSSCKSELR_PLL		0x00000003

/* Values of RCC_CPERCKSELR register */
#define RCC_CPERCKSELR_HSI		0x00000000
#define RCC_CPERCKSELR_CSI		0x00000001
#define RCC_CPERCKSELR_HSE		0x00000002

/* Used for most of DIVR register: max div for RTC */
#define RCC_DIVR_DIV_MASK		GENMASK(5, 0)
#define RCC_DIVR_DIVRDY			BIT(31)

/* Masks for specific DIVR registers */
#define RCC_APBXDIV_MASK		GENMASK(2, 0)
#define RCC_MPUDIV_MASK			GENMASK(2, 0)
#define RCC_AXIDIV_MASK			GENMASK(2, 0)

/* Offset between RCC_MP_xxxENSETR and RCC_MP_xxxENCLRR registers */
#define RCC_MP_ENCLRR_OFFSET		U(4)

/* Fields of RCC_BDCR register */
#define RCC_BDCR_LSEON			BIT(0)
#define RCC_BDCR_LSEBYP			BIT(1)
#define RCC_BDCR_LSERDY			BIT(2)
#define RCC_BDCR_LSEDRV_MASK		GENMASK(5, 4)
#define RCC_BDCR_LSEDRV_SHIFT		4
#define RCC_BDCR_LSECSSON		BIT(8)
#define RCC_BDCR_RTCCKEN		BIT(20)
#define RCC_BDCR_RTCSRC_MASK		GENMASK(17, 16)
#define RCC_BDCR_RTCSRC_SHIFT		16
#define RCC_BDCR_VSWRST			BIT(31)

/* Fields of RCC_RDLSICR register */
#define RCC_RDLSICR_LSION		BIT(0)
#define RCC_RDLSICR_LSIRDY		BIT(1)

/* Used for all RCC_PLL<n>CR registers */
#define RCC_PLLNCR_PLLON		BIT(0)
#define RCC_PLLNCR_PLLRDY		BIT(1)
#define RCC_PLLNCR_DIVPEN		BIT(4)
#define RCC_PLLNCR_DIVQEN		BIT(5)
#define RCC_PLLNCR_DIVREN		BIT(6)
#define RCC_PLLNCR_DIVEN_SHIFT		4

/* Used for all RCC_PLL<n>CFGR1 registers */
#define RCC_PLLNCFGR1_DIVM_SHIFT	16
#define RCC_PLLNCFGR1_DIVM_MASK		GENMASK(21, 16)
#define RCC_PLLNCFGR1_DIVN_SHIFT	0
#define RCC_PLLNCFGR1_DIVN_MASK		GENMASK(8, 0)
/* Only for PLL3 and PLL4 */
#define RCC_PLLNCFGR1_IFRGE_SHIFT	24
#define RCC_PLLNCFGR1_IFRGE_MASK	GENMASK(25, 24)

/* Used for all RCC_PLL<n>CFGR2 registers */
#define RCC_PLLNCFGR2_DIVX_MASK		GENMASK(6, 0)
#define RCC_PLLNCFGR2_DIVP_SHIFT	0
#define RCC_PLLNCFGR2_DIVP_MASK		GENMASK(6, 0)
#define RCC_PLLNCFGR2_DIVQ_SHIFT	8
#define RCC_PLLNCFGR2_DIVQ_MASK		GENMASK(14, 8)
#define RCC_PLLNCFGR2_DIVR_SHIFT	16
#define RCC_PLLNCFGR2_DIVR_MASK		GENMASK(22, 16)

/* Used for all RCC_PLL<n>FRACR registers */
#define RCC_PLLNFRACR_FRACV_SHIFT	3
#define RCC_PLLNFRACR_FRACV_MASK	GENMASK(15, 3)
#define RCC_PLLNFRACR_FRACLE		BIT(16)

/* Used for all RCC_PLL<n>CSGR registers */
#define RCC_PLLNCSGR_INC_STEP_SHIFT	16
#define RCC_PLLNCSGR_INC_STEP_MASK	GENMASK(30, 16)
#define RCC_PLLNCSGR_MOD_PER_SHIFT	0
#define RCC_PLLNCSGR_MOD_PER_MASK	GENMASK(12, 0)
#define RCC_PLLNCSGR_SSCG_MODE_SHIFT	15
#define RCC_PLLNCSGR_SSCG_MODE_MASK	BIT(15)

/* Used for RCC_OCENSETR and RCC_OCENCLRR registers */
#define RCC_OCENR_HSION			BIT(0)
#define RCC_OCENR_CSION			BIT(4)
#define RCC_OCENR_HSEON			BIT(8)
#define RCC_OCENR_HSEBYP		BIT(10)
#define RCC_OCENR_HSECSSON		BIT(11)

/* Fields of RCC_OCRDYR register */
#define RCC_OCRDYR_HSIRDY		BIT(0)
#define RCC_OCRDYR_HSIDIVRDY		BIT(2)
#define RCC_OCRDYR_CSIRDY		BIT(4)
#define RCC_OCRDYR_HSERDY		BIT(8)

/* Fields of RCC_DDRITFCR register */
#define RCC_DDRITFCR_DDRC1EN		BIT(0)
#define RCC_DDRITFCR_DDRC1LPEN		BIT(1)
#define RCC_DDRITFCR_DDRC2EN		BIT(2)
#define RCC_DDRITFCR_DDRC2LPEN		BIT(3)
#define RCC_DDRITFCR_DDRPHYCEN		BIT(4)
#define RCC_DDRITFCR_DDRPHYCLPEN	BIT(5)
#define RCC_DDRITFCR_DDRCAPBEN		BIT(6)
#define RCC_DDRITFCR_DDRCAPBLPEN	BIT(7)
#define RCC_DDRITFCR_AXIDCGEN		BIT(8)
#define RCC_DDRITFCR_DDRPHYCAPBEN	BIT(9)
#define RCC_DDRITFCR_DDRPHYCAPBLPEN	BIT(10)
#define RCC_DDRITFCR_DDRCAPBRST		BIT(14)
#define RCC_DDRITFCR_DDRCAXIRST		BIT(15)
#define RCC_DDRITFCR_DDRCORERST		BIT(16)
#define RCC_DDRITFCR_DPHYAPBRST		BIT(17)
#define RCC_DDRITFCR_DPHYRST		BIT(18)
#define RCC_DDRITFCR_DPHYCTLRST		BIT(19)
#define RCC_DDRITFCR_DDRCKMOD_MASK	GENMASK(22, 20)
#define RCC_DDRITFCR_DDRCKMOD_SHIFT	20
#define RCC_DDRITFCR_DDRCKMOD_SSR	0
#define RCC_DDRITFCR_DDRCKMOD_ASR1	BIT(20)
#define RCC_DDRITFCR_DDRCKMOD_HSR1	BIT(21)
#define RCC_DDRITFCR_GSKPCTRL		BIT(24)

/* Fields of RCC_HSICFGR register */
#define RCC_HSICFGR_HSIDIV_MASK		GENMASK(1, 0)

/* Used for RCC_MCO related operations */
#define RCC_MCOCFG_MCOON		BIT(12)
#define RCC_MCOCFG_MCODIV_MASK		GENMASK(7, 4)
#define RCC_MCOCFG_MCODIV_SHIFT		4
#define RCC_MCOCFG_MCOSRC_MASK		GENMASK(2, 0)

/* Fields of RCC_DBGCFGR register */
#define RCC_DBGCFGR_DBGCKEN		BIT(8)

/* RCC register fields for reset reasons */
#define  RCC_MP_RSTSCLRR_PORRSTF	BIT(0)
#define  RCC_MP_RSTSCLRR_BORRSTF	BIT(1)
#define  RCC_MP_RSTSCLRR_PADRSTF	BIT(2)
#define  RCC_MP_RSTSCLRR_HCSSRSTF	BIT(3)
#define  RCC_MP_RSTSCLRR_VCORERSTF	BIT(4)
#define  RCC_MP_RSTSCLRR_MPSYSRSTF	BIT(6)
#define  RCC_MP_RSTSCLRR_IWDG1RSTF	BIT(8)
#define  RCC_MP_RSTSCLRR_IWDG2RSTF	BIT(9)
#define  RCC_MP_RSTSCLRR_STDBYRSTF	BIT(11)
#define  RCC_MP_RSTSCLRR_CSTDBYRSTF	BIT(12)

/* Global Reset Register */
#define RCC_MP_GRSTCSETR_MPSYSRST	BIT(0)

/* Clock Source Interrupt Flag Register */
#define RCC_MP_CIFR_MASK		U(0x110F1F)
#define RCC_MP_CIFR_WKUPF		BIT(20)

/* Stop Request Set Register */
#define RCC_MP_SREQSETR_STPREQ_P0	BIT(0)
#define RCC_MP_SREQSETR_STPREQ_P1	BIT(1)

/* Stop Request Clear Register */
#define RCC_MP_SREQCLRR_STPREQ_P0	BIT(0)
#define RCC_MP_SREQCLRR_STPREQ_P1	BIT(1)

/* Values of RCC_UART24CKSELR register */
#define RCC_UART24CKSELR_HSI		0x00000002

/* Values of RCC_MP_APB1ENSETR register */
#define RCC_MP_APB1ENSETR_UART4EN	BIT(16)

/* Values of RCC_MP_AHB4ENSETR register */
#define RCC_MP_AHB4ENSETR_GPIOGEN	BIT(6)

#endif /* STM32MP1_RCC_H */
