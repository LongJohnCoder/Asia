//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		HPET					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_HPET_R090(A0).doc(final)MOD_HPETCFG.xls
#ifndef _CHX002_HPET_H
#define _CHX002_HPET_H
//HPET-MMIO
#define HPETMMIO_GENERAL_CAPS_AND_ID		0x00	//General Capabilities and ID
    #define HPETMMIO_CLKPERIOD			0xFFFFFFFF00000000	//0429B17Fh/R/x/x Main Counter Tick Period
    #define HPETMMIO_VENDOR_ID			0xFFFF0000	//1106h/x/x/x Vendor ID
    #define HPETMMIO_LEG_RT_CAP			BIT15	//1b/R/x/x LegacyReplacement Route Capable
    #define HPETMMIO_COUNT_SIZE			BIT13	//0/R/x/x Counter Size
    #define HPETMMIO_NUM_TIM_CAP			0x1F00	//02h/R/x/x Number of Timers
    #define HPETMMIO_REV_ID			0xFF	//01h/R/x/x Revision ID
#define HPETMMIO_GENERAL_CFG		0x10	//General Configuration
    #define HPETMMIO_RX010DX			0xFC	//0/x/x/x Reserved
    #define HPETMMIO_LEG_RT_CNF			BIT1	//0/x/x/x LegacyReplacement Route
    #define HPETMMIO_ENABLE_CNF			BIT0	//0/x/x/x Overall Enable
#define HPETMMIO_GENERAL_INTR_STA		0x20	//General Interrupt Status
    #define HPETMMIO_T2_INT_STS			BIT2	//0/x/x/x Timer 2 Interrupt Active
    #define HPETMMIO_T1_INT_STS			BIT1	//0/x/x/x Timer 1 Interrupt Active
    #define HPETMMIO_T0_INT_STS			BIT0	//0/x/x/x Timer 0 Interrupt Active
#define HPETMMIO_MAIN_CNTER_VALUE		0xF0	//Main Counter Value
    #define HPETMMIO_MCT			0xFFFFFFFF	//0/x/x/x Main Counter Value
#define HPETMMIO_TIMER_0_CFG_CAP		0x100	//Timer 0 Configuration & Capability
    #define HPETMMIO_T0_INT_ROUTE_CAP			0xFFFFFFFF00000000	//000F0000h/000f0000h/x/x Timer 0 Interrupt Routing Capability
    #define HPETMMIO_T0_FSB_INT_DEL_CAP			BIT15	//1b/R/x/x Timer 0 FSB Interrupt Delivery
    #define HPETMMIO_T0_FSBEN			BIT14	//0/x/x/x Timer 0 FSB Interrupt Enable
    #define HPETMMIO_T0_INT_R			0x3E00	//0/x/x/x Timer 0 Interrupt Route
    #define HPETMMIO_T0_32MODE_R			BIT8	//0/R/x/x Timer 0 32-Bit Mode
    #define HPETMMIO_T0_VALSET			BIT6	//0/x/x/x Timer 0 Value Set
    #define HPETMMIO_T0_SIZE_CAP			BIT5	//0/R/x/x Timer 0 Size
    #define HPETMMIO_T0_PER_CAP			BIT4	//1b/R/x/x Timer 0 Periodic Interrupt Capable 
    #define HPETMMIO_T0_TYPE			BIT3	//0/x/x/x Timer 0 Type
    #define HPETMMIO_T0_INT_EN			BIT2	//0/x/x/x Timer 0 Interrupt Enable
    #define HPETMMIO_T0_INT_TYPE			BIT1	//0/x/x/x Timer 0 Interrupt Type 
#define HPETMMIO_TIMER_0_COMPARATOR_VALUE		0x108	//Timer 0 Comparator Value
    #define HPETMMIO_T0CPTR			0xFFFFFFFF	//FFFFFFFFh/x/x/x Timer 0 Comparator
#define HPETMMIO_TIMER_0_FSB_INTR_ROUTE_REG		0x110	//Timer 0 FSB Interrupt Route Register
    #define HPETMMIO_T0_FSB_ADDR			0xFFFFFFFF00000000	//0/x/x/x FSB INTR Message Location
    #define HPETMMIO_T0_FSB_VAL			0xFFFFFFFF	//0/x/x/x FSB INTR Message Value
#define HPETMMIO_TIMER_1_CFG_CAP		0x120	//Timer 1 Configuration & Capability
    #define HPETMMIO_T1_INT_ROUTE_CAP			0xFFFFFFFF00000000	//000F0000h/000F0000h/x/x Timer 1 Interrupt Routing Capability
    #define HPETMMIO_T1_FSB_INT_DEL_CAP			BIT15	//1b/R/x/x Timer 1 FSB Interrupt Delivery
    #define HPETMMIO_T1_FSBEN			BIT14	//0/x/x/x Timer 1 FSB Interrupt Enable
    #define HPETMMIO_T1_INT_R			0x3E00	//0/x/x/x Timer 1 Interrupt Route
    #define HPETMMIO_T1_32MODE_R			BIT8	//0/R/x/x Timer1 32-Bit Mode
    #define HPETMMIO_T1_VALSET			BIT6	//0/x/x/x Timer 1 Value Set
    #define HPETMMIO_T1_SIZE_CAP			BIT5	//0/R/x/x Timer1 Size
    #define HPETMMIO_T1_PER_CAP			BIT4	//1b/R/x/x Timer 1 Periodic Interrupt Capable 
    #define HPETMMIO_T1_TYPE			BIT3	//0/x/x/x Timer 1 Type
    #define HPETMMIO_T1_INT_EN			BIT2	//0/x/x/x Timer 1 Interrupt Enable
    #define HPETMMIO_T1_INT_TYPE			BIT1	//0/x/x/x Timer 1 Interrupt Type 
#define HPETMMIO_TIMER_1_COMPARATOR_VALUE		0x128	//Timer 1 Comparator Value
    #define HPETMMIO_T1CPTR			0xFFFFFFFF	//FFFFFFFFh/x/x/x Timer 1 Comparator
#define HPETMMIO_TIMER_1_FSB_INTR_ROUTE_REG		0x130	//Timer 1 FSB Interrupt Route Register
    #define HPETMMIO_T1_FSB_ADDR			0xFFFFFFFF00000000	//0/x/x/x FSB INTR Message Location
    #define HPETMMIO_T1_FSB_VAL			0xFFFFFFFF	//0/x/x/x FSB INTR Message Value
#define HPETMMIO_TIMER_2_CFG_CAP		0x140	//Timer 2 Configuration & Capability
    #define HPETMMIO_T2_INT_ROUTE_CAP			0xFFFFFFFF00000000	//000F0800h/000f0800h/x/x Timer 2 Interrupt Routing Capability
    #define HPETMMIO_T2_FSB_INT_DEL_CAP			BIT15	//1b/R/x/x Timer 2 FSB Interrupt Delivery
    #define HPETMMIO_T2_FSBEN			BIT14	//0/x/x/x Timer 2 FSB Interrupt Enable
    #define HPETMMIO_T2_INT_R			0x3E00	//0/x/x/x Timer 2 Interrupt Route
    #define HPETMMIO_T2_32MODE_R			BIT8	//0/R/x/x Timer 2 32-Bit Mode
    #define HPETMMIO_T2_VALSET			BIT6	//0/x/x/x Timer 2 Value Set
    #define HPETMMIO_T2_SIZE_CAP			BIT5	//0/R/x/x Timer 2 Size
    #define HPETMMIO_T2_PER_CAP			BIT4	//1b/R/x/x Timer 2 Periodic Interrupt Capable 
    #define HPETMMIO_T2_TYPE			BIT3	//0/x/x/x Timer 2 Type
    #define HPETMMIO_T2_INT_EN			BIT2	//0/x/x/x Timer 2 Interrupt Enable
    #define HPETMMIO_T2_INT_TYPE			BIT1	//0/x/x/x Timer 2 Interrupt Type 
#define HPETMMIO_TIMER_2_COMPARATOR_VALUE		0x148	//Timer 2 Comparator Value
    #define HPETMMIO_T2CPTR			0xFFFFFFFF	//FFFFFFFFh/x/x/x Timer 2 Comparator
#define HPETMMIO_TIMER_2_FSB_INTR_ROUTE_REG		0x150	//Timer 2 FSB Interrupt Route Register
    #define HPETMMIO_T2_FSB_ADDR			0xFFFFFFFF00000000	//0/x/x/x FSB INTR Message Location
    #define HPETMMIO_T2_FSB_VAL			0xFFFFFFFF	//0/x/x/x FSB INTR Message Value
#endif
