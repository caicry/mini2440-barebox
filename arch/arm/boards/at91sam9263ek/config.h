#ifndef __CONFIG_H
#define __CONFIG_H

#define AT91_MAIN_CLOCK		16367660	/* 16.367 MHz crystal */

#define MASTER_PLL_MUL		171
#define MASTER_PLL_DIV		14

/* clocks */
#define CONFIG_SYS_MOR_VAL						\
		(AT91_PMC_MOSCEN |					\
		 (255 << 8))		/* Main Oscillator Start-up Time */
#define CONFIG_SYS_PLLAR_VAL						\
		(AT91_PMC_PLLA_WR_ERRATA | /* Bit 29 must be 1 when prog */ \
		 AT91_PMC_OUT |						\
		 AT91_PMC_PLLCOUNT |	/* PLL Counter */		\
		 (2 << 28) |		/* PLL Clock Frequency Range */	\
		 ((MASTER_PLL_MUL - 1) << 16) | (MASTER_PLL_DIV))

/* PCK/2 = MCK Master Clock from PLLA */
#define	CONFIG_SYS_MCKR1_VAL		\
		(AT91_PMC_CSS_SLOW |	\
		 AT91_PMC_PRES_1 |	\
		 AT91SAM9_PMC_MDIV_2 |	\
		 AT91_PMC_PDIV_1)
/* PCK/2 = MCK Master Clock from PLLA */
#define	CONFIG_SYS_MCKR2_VAL		\
		(AT91_PMC_CSS_PLLA |	\
		 AT91_PMC_PRES_1 |	\
		 AT91SAM9_PMC_MDIV_2 |	\
		 AT91_PMC_PDIV_1)

/* define PDC[31:16] as DATA[31:16] */
#define CONFIG_SYS_PIOD_PDR_VAL1	0xFFFF0000
/* no pull-up for D[31:16] */
#define CONFIG_SYS_PIOD_PPUDR_VAL	0xFFFF0000
/* EBI0_CSA, CS1 SDRAM, CS3 NAND Flash, 3.3V memories */
#define CONFIG_SYS_MATRIX_EBI0CSA_VAL					\
	(AT91_MATRIX_EBI0_DBPUC | AT91_MATRIX_EBI0_VDDIOMSEL_3_3V |	\
	 AT91_MATRIX_EBI0_CS1A_SDRAMC)

/* SDRAM */
/* SDRAMC_TR - Refresh Timer register */
#define CONFIG_SYS_SDRC_TR_VAL1		0x13C
/* SDRAMC_CR - Configuration register*/
#define CONFIG_SYS_SDRC_CR_VAL							\
		(AT91_SDRAMC_NC_9 |						\
		 AT91_SDRAMC_NR_13 |						\
		 AT91_SDRAMC_NB_4 |						\
		 AT91_SDRAMC_CAS_3 |						\
		 AT91_SDRAMC_DBW_32 |						\
		 (1 <<  8) |		/* Write Recovery Delay */		\
		 (7 << 12) |		/* Row Cycle Delay */			\
		 (2 << 16) |		/* Row Precharge Delay */		\
		 (2 << 20) |		/* Row to Column Delay */		\
		 (5 << 24) |		/* Active to Precharge Delay */		\
		 (1 << 28))		/* Exit Self Refresh to Active Delay */

/* Memory Device Register -> SDRAM */
#define CONFIG_SYS_SDRC_MDR_VAL		AT91_SDRAMC_MD_SDRAM
#define CONFIG_SYS_SDRC_TR_VAL2		1200		/* SDRAM_TR */

/* setup SMC0, CS0 (NOR Flash) - 16-bit, 15 WS */
#define CONFIG_SYS_SMC_CS	0
#define CONFIG_SYS_SMC_SETUP_VAL					\
		(AT91_SMC_NWESETUP_(10) | AT91_SMC_NCS_WRSETUP_(10) |	\
		 AT91_SMC_NRDSETUP_(10) | AT91_SMC_NCS_RDSETUP_(10))
#define CONFIG_SYS_SMC_PULSE_VAL					\
		(AT91_SMC_NWEPULSE_(11) | AT91_SMC_NCS_WRPULSE_(11) |	\
		 AT91_SMC_NRDPULSE_(11) | AT91_SMC_NCS_RDPULSE_(11))
#define CONFIG_SYS_SMC_CYCLE_VAL	\
		(AT91_SMC_NWECYCLE_(22) | AT91_SMC_NRDCYCLE_(22))
#define CONFIG_SYS_SMC_MODE_VAL					\
		(AT91_SMC_READMODE | AT91_SMC_WRITEMODE |	\
		 AT91_SMC_DBW_16 |				\
		 AT91_SMC_TDFMODE |				\
		 AT91_SMC_TDF_(6))

/* user reset enable */
#define CONFIG_SYS_RSTC_RMR_VAL			\
		(AT91_RSTC_KEY |		\
		AT91_RSTC_PROCRST |		\
		AT91_RSTC_RSTTYP_WAKEUP |	\
		AT91_RSTC_RSTTYP_WATCHDOG)

/* Disable Watchdog */
#define CONFIG_SYS_WDTC_WDMR_VAL				\
		(AT91_WDT_WDIDLEHLT | AT91_WDT_WDDBGHLT |	\
		 AT91_WDT_WDV |					\
		 AT91_WDT_WDDIS |				\
		 AT91_WDT_WDD)

#endif	/* __CONFIG_H */
