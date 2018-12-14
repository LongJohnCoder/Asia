//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		PMU					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D17F0_PMU_R112(A0).doc(final)MOD_PMU.xls
#ifndef _CHX002_D17F0_PMU_H
#define _CHX002_D17F0_PMU_H
//D17F0
#define D17F0_PMU_PM_GENERAL_CFG_1		0x80	//PM General Configuration 1
    #define D17F0_PMU_THRM_SEL			BIT7	//0/x/x/x Reserved
    #define D17F0_PMU_ENSLPBTN			BIT6	//0/0/x/x Enable GPIO12 as SLPBTN#
    #define D17F0_PMU_ENDBUN			BIT5	//1b/1/x/x Power Button De-bounce
    #define D17F0_PMU_ENINH			BIT4	//0/x/x/x Reserved
    #define D17F0_PMU_MON_MSS			BIT3	//0/0/x/x Enable Microsoft Sound Monitor in Audio Access
    #define D17F0_PMU_MON_GAME			BIT2	//0/0/x/x Enable Game Port Monitor in Audio Access
    #define D17F0_PMU_MON_SB			BIT1	//0/0/x/x Enable Sound Blaster Monitor in Audio Access
    #define D17F0_PMU_MON_MIDI			BIT0	//0/0/x/x Enable MIDI Monitor in Audio Access
#define D17F0_PMU_PM_GENERAL_CFG_2		0x81	//PM General Configuration 2
    #define D17F0_PMU_RENIO			BIT7	//0/*/x/x Enable ACPI I/O 
    #define D17F0_PMU_TMRST			BIT6	//0/0/x/x Reserved
    #define D17F0_PMU_TESTIM1TESTTM			(BIT4 + BIT5)	//0/0/x/x Reserved
    #define D17F0_PMU_TMR32			BIT3	//0/0/x/x ACPI Timer with 32-Bit Width Control
    #define D17F0_PMU_ENGPSON			BIT2	//1b/1/x/x Enable RTC Control Signal Gated with PSON (SUSC#) in Soft-Off Mode
    #define D17F0_PMU_STPTB			BIT1	//0/0/x/x Throttle Timer Base Clock Period (for STPCLK#)
    #define D17F0_PMU_TESTPM			BIT0	//0/x/x/x Reserved
#define D17F0_PMU_ACPI_INTR_SEL		0x82	//ACPI Interrupt Select
    #define D17F0_PMU_PWRAT			BIT7	//0/R/x/x ATX / AT Power Indicator
    #define D17F0_PMU_DSUSCO			BIT6	//1b/R/x/x PSON (SUSC#) Current State
    #define D17F0_PMU_RD82_5			BIT5	//0/x/x/x Reserved
    #define D17F0_PMU_PSONVAL			BIT4	//1b/R/x/x SUSC# AC-Power-On Default
    #define D17F0_PMU_SSCI			0xF	//0h/0h/x/x ACPI IRQ Select
#define D17F0_PMU_INTERNAL_TIMER_READ_TEST		0x83	//Internal Timer Read Test
    #define D17F0_PMU_ITRT			0xFF	//0/R/x/x Internal Timer Read Test
#define D17F0_PMU_IRQN_AS_PRIMARY_INTR		0x84	//IRQn as Primary Interrupt
    #define D17F0_PMU_PEIRQ15			BIT15	//0/x/x/x IRQ15 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ14			BIT14	//0/x/x/x IRQ14 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ13			BIT13	//0/x/x/x IRQ13 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ12			BIT12	//0/x/x/x IRQ12 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ11			BIT11	//0/x/x/x IRQ11 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ10			BIT10	//0/x/x/x IRQ10 as Primary Interrupt Channel 
    #define D17F0_PMU_PEIRQ9			BIT9	//0/x/x/x IRQ9 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ8			BIT8	//0/x/x/x IRQ8 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ7			BIT7	//0/x/x/x IRQ7 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ6			BIT6	//0/x/x/x IRQ6 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ5			BIT5	//0/x/x/x IRQ5 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ4			BIT4	//0/x/x/x IRQ4 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ3			BIT3	//0/x/x/x IRQ3 as Primary Interrupt Channel
    #define D17F0_PMU_RS84_2			BIT2	//0/x/x/x Reserved
    #define D17F0_PMU_PEIRQ1			BIT1	//0/x/x/x IRQ1 as Primary Interrupt Channel
    #define D17F0_PMU_PEIRQ0			BIT0	//0/x/x/x IRQ0 as Primary Interrupt Channel
#define D17F0_PMU_IRQN_AS_SECONDARY_INTR		0x86	//IRQn as Secondary Interrupt
    #define D17F0_PMU_SEIRQ15			BIT15	//0/x/x/x IRQ15 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ14			BIT14	//0/x/x/x IRQ14 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ13			BIT13	//0/x/x/x IRQ13 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ12			BIT12	//0/x/x/x IRQ12 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ11			BIT11	//0/x/x/x IRQ11 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ10			BIT10	//0/x/x/x IRQ10 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ9			BIT9	//0/x/x/x IRQ9 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ8			BIT8	//0/x/x/x IRQ8 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ7			BIT7	//0/x/x/x IRQ7 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ6			BIT6	//0/x/x/x IRQ6 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ5			BIT5	//0/x/x/x IRQ5 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ4			BIT4	//0/x/x/x IRQ4 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ3			BIT3	//0/x/x/x IRQ3 as Secondary Interrupt Channel
    #define D17F0_PMU_RS86_2			BIT2	//0/x/x/x Reserved
    #define D17F0_PMU_SEIRQ1			BIT1	//0/x/x/x IRQ1 as Secondary Interrupt Channel
    #define D17F0_PMU_SEIRQ0			BIT0	//0/x/x/x IRQ0 as Secondary Interrupt Channel
#define D17F0_PMU_PM_IO_BASE		0x88	//Power Management I/O Base
    #define D17F0_PMU_PMIOBA			0xFF00	//0/x/x/x ACPI IO Base [15:8]
    #define D17F0_PMU_HW1_7_0			0xFF	//01h/R/x/x Hardwired to 01h
#define D17F0_PMU_AUTO_SWITCHING_PROCESSOR_PWR_STATE		0x8A	//Auto-Switching Processor Power State
    #define D17F0_PMU_ENSC4			BIT7	//0/*/*/* Enable Slow C4 Recovery Mode in Short C4 Setting ((Random))
    #define D17F0_PMU_ENSTPGNTC5			BIT6	//0/x/x/x Reserved
    #define D17F0_PMU_ENC5			BIT5	//0/*/*/* Enable C5 State
    #define D17F0_PMU_PDNC34			BIT4	//0/*/*/* C2 to C3 / C4 Auto Mode 
    #define D17F0_PMU_PUPC2			BIT3	//0/*/*/* C3/C4 to C2 Auto Mode 
    #define D17F0_PMU_BM_STS_DIS			BIT2	//0/*/*/* Bus Master Status Report Disable
    #define D17F0_PMU_AUTODISC4			BIT1	//0/*/*/* C4 to C3 Auto Mode
    #define D17F0_PMU_BMDELAYC34			BIT0	//0/*/*/* Bus Master Request Delay C3/C4 Mode
#define D17F0_PMU_PROCESSOR_PWR_STATE_CTL		0x8B	//Processor Power State Control
    #define D17F0_PMU_ENC5BMBRK			BIT3	//1b/x/x/x Enable C5 State Bus Master can break to C0
    #define D17F0_PMU_ENC6BMBRK			BIT2	//1b/x/x/x Enable C6 State Bus Master can break to C0
    #define D17F0_PMU_ENSTPGNTC6			BIT1	//0/x/x/x Reserved
    #define D17F0_PMU_ENC6			BIT0	//0/*/*/* Enable C6 State
#define D17F0_PMU_HOST_PM_CTL		0x8C	//Host Power Management Control
    #define D17F0_PMU_THRM_DTY			0xF0	//0h/0h/x/x Thermal Duty Cycle
    #define D17F0_PMU_ENTHRM1			BIT3	//0/0/0/0 THRM# Enable
    #define D17F0_PMU_ENPBE			BIT2	//1b/1/1/1 Processor Break Events
    #define D17F0_PMU_DNC3ARB			BIT1	//0b/0/x/x Disable Bus Arbiter C3/C4 Auto Gating ((Random))
    #define D17F0_PMU_DNP1			BIT0	//1b/1/x/x Reserved (Do Not Program)
#define D17F0_PMU_THROTTLE_CLK_STOP_CTL		0x8D	//Throttle / Clock Stop Control
    #define D17F0_PMU_TCNTRST			BIT7	//0/0/x/x Throttle Timer Reset
    #define D17F0_PMU_THTLEN			(BIT5 + BIT6)	//00b/00b/x/x Throttle Timer Counter Width
    #define D17F0_PMU_ENFTHCK			BIT4	//0/x/x/x Use Fast Clock (7.5us) as Throttle Timer Tick 
    #define D17F0_PMU_ENSMIL			BIT3	//1b/1/x/x SMI# Low Level Output 
    #define D17F0_PMU_ENRUNGK			BIT2	//0/x/x/x Reserved
    #define D17F0_PMU_ENC3GK			BIT1	//0/0/0/0 Reserved
    #define D17F0_PMU_ENSUSGK			BIT0	//0/0/0/0 Reserved
#define D17F0_PMU_PM_TIMER_CTL		0x90	//Power Management Timer Control
    #define D17F0_PMU_CNS0S1			(BIT30 + BIT31)	//00b/x/x/x Power Conserve Mode Timer Period
    #define D17F0_PMU_CNSIN			BIT29	//0/0/x/x Power Conserve Mode Status
    #define D17F0_PMU_CNSEN			BIT28	//0/0/x/x Power Conserve Mode
    #define D17F0_PMU_SEVTT0T1			(BIT26 + BIT27)	//00b/x/x/x Secondary Event Timer Count Value
    #define D17F0_PMU_SEVTIN			BIT25	//0/x/x/x Secondary Event Occurred Status
    #define D17F0_PMU_SEVTEN			BIT24	//0/0/x/x Secondary Event Timer Enable
    #define D17F0_PMU_GP1Q0_Q7			0xFF0000	//0/x/x/x GP1 Timer Count Value
    #define D17F0_PMU_GP0Q0_Q7			0xFF00	//0/x/x/x GP0 Timer Count Value
    #define D17F0_PMU_ENGP1			BIT7	//0/0/x/x GP1 Timer Enable
    #define D17F0_PMU_ENGP1AL			BIT6	//0/0/x/x GP1 Timer Automatic Reload
    #define D17F0_PMU_GP1CKS1S0			(BIT4 + BIT5)	//00b/0/x/x GP1 Timer Tick Select
    #define D17F0_PMU_ENGP0			BIT3	//0/0/x/x GP0 Timer Start
    #define D17F0_PMU_ENGP0AL			BIT2	//0/0/x/x GP0 Timer Automatic Reload
    #define D17F0_PMU_GP0CKS1S0			(BIT0 + BIT1)	//00b/0/x/x GP0 Timer Tick Select
#define D17F0_PMU_MISC_CFG_1_PWR_WELL		0x94	//Miscellaneous Configuration 1 (Power Well)
    #define D17F0_PMU_ENRESV1			BIT7	//0/0/0/0 SMBus Slave Clock Select
    #define D17F0_PMU_PWR54B6			BIT6	//0/0/x/x Check Power Button Enable When PWRBTN# Asserted to Resume from STR / STD 
    #define D17F0_PMU_DNSPLLR			BIT5	//0/x/x/x Reserved
    #define D17F0_PMU_GTD2INT			BIT4	//0/0/x/x KBC D2 Command Interrupt Gating
    #define D17F0_PMU_RPUL_VPAD_SDCR			BIT3	//1b/1/x/x Reserved
    #define D17F0_PMU_ENGPO56			BIT2	//0/0/x/x Multi-Function Signal Select: GPO[6:5] vs. SUS[C:B]#
    #define D17F0_PMU_GPO4S1S0			(BIT0 + BIT1)	//00b/0/x/x GPO4 Output Select
#define D17F0_PMU_MISC_CFG_2_PWR_WELL		0x95	//Miscellaneous Configuration 2 (Power Well)
    #define D17F0_PMU_PWR55B7			BIT7	//1b/1/1/1 ¡®SUS[A:C]# De-assertion and PWRGD Active¡¯ to KSTPO_((Internal Signal)) De-assertion Delay Select ((Random))
    #define D17F0_PMU_PWR55B6			BIT6	//1b/1/x/x SUSSTAT#((Internal Signal)) and KSTPO_((Internal Signal)) De-assert Before PWRGD When Resume from STD (SUSC_ de-assert)
    #define D17F0_PMU_PWR55B5			BIT5	//0/0/x/x Keyboard / Mouse Port Swap
    #define D17F0_PMU_DNP1GRST			BIT4	//0/0/x/x PWRGD Reset 
    #define D17F0_PMU_ENGPIO01			BIT3	//0/0/x/x Reserved
    #define D17F0_PMU_DNSMB2			BIT2	//0/0/x/x AOL 2 SMB Slave (through SMB Port 2)
    #define D17F0_PMU_ENGPO4			BIT1	//0/0/x/x Multi-Function Signal Select: GPO4 vs. SUSA# 
    #define D17F0_PMU_ENUSBUP			BIT0	//0/0/x/x USB Wakeup for POS / STR / STD / Soft Off
#define D17F0_PMU_MISC_CFG_3_BATTERY_WELL		0x96	//Miscellaneous Configuration 3 (Battery Well)
    #define D17F0_PMU_ALWAYS0			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define D17F0_PMU_BR96B5			BIT5	//0/x/x/x Reserved
    #define D17F0_PMU_ENAOL2R			BIT4	//0/0/x/x Enable SMB GPOUT6 and GPOUT7 as PWRGD and PWRBTN#
    #define D17F0_PMU_STRFEQ			0xF	//Fh/x/x/x Reserved
#define D17F0_PMU_MISC_CFG_4_PWR_WELL		0x97	//Miscellaneous Configuration 4 (Power Well)
    #define D17F0_PMU_ENPGWAIT			BIT7	//1b/1/x/x Wait for PWRGD Low Before Wake-up during S3/S4 State
    #define D17F0_PMU_ENGPIO23			BIT6	//0/0/x/x Multi-Function Signal Select: (MSDT, MSCK) vs. (GPIO2, GPIO3)
    #define D17F0_PMU_GPI23			BIT5	//0/x/x/x Enable GPI2 and GPI3
    #define D17F0_PMU_PEWKS1PME			BIT4	//1b/1/x/x Enable PCIe PME S1 State Wake Event
    #define D17F0_PMU_PEWKARBEN			BIT3	//0/x/x/x Reserved
    #define D17F0_PMU_DISSUSPUP			BIT2	//0/0/x/x Disable PWRBTN Pull-up
    #define D17F0_PMU_RS97_1			BIT1	//0/x/x/x Reserved
    #define D17F0_PMU_ENGPIO45			BIT0	//0/0/x/x Multi-Function Signal Select: (KBDT, KBCK) / (KBC_CPURST#, A20GATE) vs. (GPIO4, GPIO5)
#define D17F0_PMU_GP2_GP3_TIMER_CTL		0x98	//GP2 / GP3 Timer Control
    #define D17F0_PMU_ENGP3			BIT7	//0/x/x/x GP3 Timer Start
    #define D17F0_PMU_ENGP3AL			BIT6	//0/x/x/x GP3 Timer Automatic Reload
    #define D17F0_PMU_GP3CKS1S0			(BIT4 + BIT5)	//01b/x/x/x GP3 Timer Tick Select
    #define D17F0_PMU_ENGP2			BIT3	//0/x/x/x GP2 Timer Start
    #define D17F0_PMU_ENGP2AL			BIT2	//0/x/x/x GP2 Timer Automatic Reload
    #define D17F0_PMU_GP2CKS1S0			(BIT0 + BIT1)	//00b/x/x/x GP2 Timer Tick Select
#define D17F0_PMU_GP2_TIMER_CNTER		0x99	//GP2 Timer Counter
    #define D17F0_PMU_GP2CNT			0xFF	//0/x/x/x GP2 Timer Counter
#define D17F0_PMU_GP3_TIMER_CNTER		0x9A	//GP3 Timer Counter
    #define D17F0_PMU_GP3CNT			0xFF	//0/x/x/x GP3 Timer Counter
#define D17F0_PMU_BOOT_OPTION_BIT_MASK_ASF		0x9B	//Boot Option Bit Mask (ASF)
    #define D17F0_PMU_PWR5BB7			BIT7	//0/x/x/x Reserved
    #define D17F0_PMU_PWR5BB6			BIT6	//0/0/x/x Lock Sleep Button
    #define D17F0_PMU_PWR5BB5			BIT5	//0/0/x/x Lock Keyboard Controller Access
    #define D17F0_PMU_SB2CPU_SUSST_DIS			BIT4	//1b/x/x/x S3/S4/S5 Handshake Disable
    #define D17F0_PMU_ENUSBDUP			BIT3	//0/x/x/x Reserved
    #define D17F0_PMU_PWR5BB2			BIT2	//0/0/x/x Lock Reset Button
    #define D17F0_PMU_PWR5BB1			BIT1	//0/0/x/x Lock Power Button
    #define D17F0_PMU_ENGPOBC			BIT0	//0/0/x/x Reserved
#define D17F0_PMU_ASF_BYTE_WRITE_CMD		0x9C	//ASF Byte Write Command
    #define D17F0_PMU_ASF_DAT9C			0xFF	//00h/R/x/x Command Decode Table
#define D17F0_PMU_ASF_DATA_MSG_1		0x9D	//ASF Data Message 1
    #define D17F0_PMU_ASF_DAT9D			0xFF	//0/R/x/x ASF Data Message 1
#define D17F0_PMU_ASF_DATA_MSG_2		0x9E	//ASF Data Message 2
    #define D17F0_PMU_ASF_DAT9E			0xFF	//0/R/x/x ASF Data Message 2
#define D17F0_PMU_CR_SDIO_VOLTAGE_CHANGE_FUN		0x9F	//CR / SDIO Voltage Change Function
    #define D17F0_PMU_PWR5FB7			BIT7	//1b/1/x/x KB/MS PAD Pull-up Select
    #define D17F0_PMU_PWR5FB6			BIT6	//0/x/x/x Reserved
    #define D17F0_PMU_PWR5FB5			BIT5	//0/x/x/x Reserved
    #define D17F0_PMU_RCRPADPWDL1RCRPADPWDL0			(BIT3 + BIT4)	//00b/00b/x/x Reserved
    #define D17F0_PMU_RS9F_2			BIT2	//0/0/x/x Reserved
    #define D17F0_PMU_SMBSDMS			(BIT0 + BIT1)	//00b/00b/x/x SMB Slave De-bounce Mode Select
#define D17F0_PMU_BACKDOOR_CTL		0xA0	//Backdoor Control
    #define D17F0_PMU_PDEVID			0xFFFF0000	//0/x/x/x Programmable Device ID
    #define D17F0_PMU_PVDRID			0xFFFF	//0/x/x/x Programmable Vendor ID
#define D17F0_PMU_PM_CAP		0xC0	//Power Management Capability
    #define D17F0_PMU_PMC1			0xFFFF0000	//0002h/R/x/x Power Management Capability
    #define D17F0_PMU_NP			0xFF00	//0/R/x/x Next Pointer
    #define D17F0_PMU_CID			0xFF	//01h/R/x/x Capability ID
#define D17F0_PMU_PM_CAP_Z1		0xC4	//Power Management Capability
    #define D17F0_PMU_PMC1D			0xFF000000	//0/R/x/x Power Management Capability Data
    #define D17F0_PMU_PMC1SR			0xFF0000	//0/R/x/x PM CSR (Certificate Signing Request) P2P Support Extensions
    #define D17F0_PMU_PMC1SRH			0xFFFC	//0/R/x/x PM Control / Status (D0/D3 Only) High
    #define D17F0_PMU_PMC1SRL			(BIT0 + BIT1)	//00b/0/x/x PM Control / Status (D0/D3 Only) Low
#define D17F0_PMU_SMBUS_IO_BASE		0xD0	//SMBus I/O Base
    #define D17F0_PMU_SMBIOA			0xFFF0	//0/x/x/x SMBus I/O Base [15:4] (16-Byte I/O Space)
    #define D17F0_PMU_HW1H_3_0			0xF	//1h/R/x/x Hardwire to 01h
#define D17F0_PMU_SMBUS_HOST_CFG		0xD2	//SMBus Host Configuration
    #define D17F0_PMU_RSD2_7_4			0xF0	//0/R/x/x Reserved
    #define D17F0_PMU_SMBISEL			BIT3	//0/*/*/* SMBus Alert IRQ SCI / SMI Select
    #define D17F0_PMU_SMBK64K			BIT2	//1b/1/x/x SMBus Slave Clock from 128K Source
    #define D17F0_PMU_ENSMBIRQ			BIT1	//0/x/x/x Enable SMBus IRQ
    #define D17F0_PMU_SMBEN			BIT0	//0/x/x/x Enable SMBus Host Controller
#define D17F0_PMU_SMBUS_HOST_SLAVE_CMD		0xD3	//SMBus Host Slave Command
    #define D17F0_PMU_SMBCMD			0xFF	//0/x/x/x SMBus Host Slave Command
#define D17F0_PMU_SMBUS_SLAVE_ADR_FOR_PORT_1		0xD4	//SMBus Slave Address for Port 1
    #define D17F0_PMU_SLVP1			0xFE	//0/x/x/x SMBus Slave Address [7:1] for Port 1
    #define D17F0_PMU_SLVP1RW			BIT0	//0/x/x/x Read / Write for Shadow Port 1
#define D17F0_PMU_SMBUS_SLAVE_ADR_FOR_PORT_2		0xD5	//SMBus Slave Address for Port 2
    #define D17F0_PMU_SLVP2			0xFE	//0/x/x/x SMBus Slave Address [7:1] for Port 2
    #define D17F0_PMU_SLVP2RW			BIT0	//0/x/x/x Read / Write for Shadow Port 2
#define D17F0_PMU_SMBUS_REV_ID		0xD6	//SMBus Revision ID
    #define D17F0_PMU_SMBRID			0xFF	//01h/x/x/x SMBus Revision ID
#define D17F0_PMU_SMBUS_HOST_CLK_SEL_ENABLE		0xD7	//SMBus Host Clock Select Enable
    #define D17F0_PMU_RSD7_7_3			0xF8	//0/x/x/x Reserved
    #define D17F0_PMU_HOST_DYNAMIC_DISABLE			BIT2	//0/x/x/x Host Dynamic Clock Disable
    #define D17F0_PMU_RSD7_1			BIT1	//0/x/x/x Reserved
    #define D17F0_PMU_EN_HST_CLK			BIT0	//0/x/x/x Host Clock Select Enable
#define D17F0_PMU_SMBUS_HOST_CLK_SEL		0xD8	//SMBus Host Clock Select
    #define D17F0_PMU_HST_CLK_SEL			0xFF	//16h/x/x/x SMBus Host Clock Frequency Select
#define D17F0_PMU_PMU_DEBUG_SIGNAL_SEL_CTL		0xDE	//PMU Debug Signal Select Control
    #define D17F0_PMU_PMUDBG2SEL3			BIT7	//0/x/x/x PMU Debug Group2 Select 3
    #define D17F0_PMU_PMUDBG2SEL2			BIT6	//0/x/x/x PMU Debug Group2 Select 2
    #define D17F0_PMU_PMUDBG2SEL1			BIT5	//0/x/x/x PMU Debug Group2 Select 1
    #define D17F0_PMU_PMUDBG2SEL0			BIT4	//0/x/x/x PMU Debug Group2 Select 0
    #define D17F0_PMU_PMUDBGSEL3			BIT3	//0/x/x/x PMU Debug Group1 Select 3
    #define D17F0_PMU_PMUDBGSEL2			BIT2	//0/x/x/x PMU Debug Group1 Select 2
    #define D17F0_PMU_PMUDBGSEL1			BIT1	//0/x/x/x PMU Debug Group1 Select 1
    #define D17F0_PMU_PMUDBGSEL0			BIT0	//0/x/x/x PMU Debug Group1 Select 0
#define D17F0_PMU_MULTI_FUN_SEL_1		0xDF	//Multi-Function Select 1
    #define D17F0_PMU_EN_MCU_JTAG			BIT7	//0/x/x/x Reserved
    #define D17F0_PMU_EN_MCU_INT			BIT6	//0/x/x/x Reserved
    #define D17F0_PMU_EN_CPU_LED			BIT5	//0/x/x/x Enable LED Flash on the Detection of NB System Error 
    #define D17F0_PMU_RSDF_4			BIT4	//0/0/x/x Reserved
    #define D17F0_PMU_RSDF_3			BIT3	//0/0/x/x Reserved
    #define D17F0_PMU_RSDF_2			BIT2	//0/0/x/x Reserved
    #define D17F0_PMU_ENGPIOAB			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D17F0_PMU_SGPI_TRIGGER_MODE_CTL		0xE0	//SGPI Trigger Mode Control
    #define D17F0_PMU_RSE0_7_4			0xF0	//0/x/x/x Reserved
    #define D17F0_PMU_SGPI1_TRGM			(BIT2 + BIT3)	//0/x/x/x SGPI1 Trigger Mode Control
    #define D17F0_PMU_SGPI10_TRGM			(BIT0 + BIT1)	//0/x/x/x SGPI10 Trigger Mode Control
#define D17F0_PMU_INTERNAL_NM_PLL_CTL		0xE2	//Internal NM PLL Control
    #define D17F0_PMU_DNUSBC4			BIT7	//0/0/x/x Inhibit C4 State during USB Isochronous Transaction
    #define D17F0_PMU_DNCSTEP_CLKF			BIT6	//1b/1/x/x Reserved
    #define D17F0_PMU_ENCSTEP12			BIT5	//1b/1/x/x Reserved
    #define D17F0_PMU_ENC1E			BIT4	//0/x/x/x Reserved
    #define D17F0_PMU_ENAGPDRV			BIT3	//0/x/x/X Reserved
    #define D17F0_PMU_RSCI2EN			BIT2	//0/0/x/X Enable Internal Hot Plug to Generate SCI/SMI
    #define D17F0_PMU_RSCI1EN			BIT1	//1b/1/x/X Enable Internal PM_PME to Generate SCI/SMI
    #define D17F0_PMU_AZBFDISC34			BIT0	//0/*/*/* Inhibit C3/C4 State When HD Audio Transfers Big Format Data
#define D17F0_PMU_PULL_UP_OPTION		0xE3	//Pull-up Option
    #define D17F0_PMU_ENSPIBRK			BIT7	//0/x/x/x SPI Bus Master as Break Event ((Random))
    #define D17F0_PMU_VRTMS1			BIT6	//0/0/0/0 Voltage Regulator (VR) Change Timer Select ((Random))
    #define D17F0_PMU_END14EHCIBRK			BIT5	//0/x/x/x D14 EHCI Bus Master as Break Event 
    #define D17F0_PMU_END14UHCIBRK			BIT4	//0/x/x/x D14 UHCI Bus Master as Break Event
    #define D17F0_PMU_ENVARTBRK			BIT3	//0/x/x/x Enable VART Break Event ((Random))
    #define D17F0_PMU_ENPEHPWAK			BIT2	//1b/1/x/x PCIe Hot Plug Wakeup in S1 State
    #define D17F0_PMU_ENPUP_INT			BIT1	//1b/1/x/x Pull-Up Enable for IO Pads (INTR, IGNNE#, A20M#, SMI#, INIT#, FERR#, NMI#) 
    #define D17F0_PMU_ENPUP_PMU			BIT0	//1b/1/x/x Pull-Up Enable for IO Pads (THRMTRIP#, NAP#, DPSLP#, STPCLK#, SLP#)  
#define D17F0_PMU_MULTI_FUN_SEL_2		0xE4	//Multi-Function Select 2
    #define D17F0_PMU_ENFC3			BIT7	//0/*/*/* Enable Short C3/C4 Mode ((Random)) 
    #define D17F0_PMU_ENLPCBRK			BIT6	//0/*/*/* LPC Bus Master as Break Event ((Random))
    #define D17F0_PMU_RSE4_5			BIT5	//0/0/x/x Reserved
    #define D17F0_PMU_ENGPO0			BIT4	//0/0/x/x Multi-Function Signal Select: SPKR vs. GPO0
    #define D17F0_PMU_ENRAIDA1BRK			BIT3	//0/*/*/* RAIDA1 Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENRAIDA0BRK			BIT2	//0/*/*/* RAIDA0 Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENGPO123			BIT1	//0/0/x/x Multi-Function Signal Select: SPI vs. GPIO
    #define D17F0_PMU_ENGPIO36			BIT0	//0/x/x/x Reserved
#define D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1		0xE5	//Cx State Break Event Enable 1
    #define D17F0_PMU_VRTMS			BIT7	//0/*/*/* C4 VR Recovery Latency Selection Bit ((Random)) 
    #define D17F0_PMU_ENAGPBM			BIT6	//1b/1/x/x NM Bus Master ((AGPBZ#)) as Source of Bus Master Status ((BM_STS))
    #define D17F0_PMU_EAPICWK			BIT5	//1b/1/x/x Enable North Module Interrupt to Wake up Cx State 
    #define D17F0_PMU_ENVGATE			BIT4	//0/x/x/x Reserved
    #define D17F0_PMU_DNSPSTP			BIT3	//0/0/x/x CPU Frequency Change
    #define D17F0_PMU_ENPCS10			BIT2	//0/0/x/x PCS1 Chip Select ((Internal signal: PCS1CS)) Output via PDIOW#
    #define D17F0_PMU_ENPCS00			BIT1	//0/0/x/x PCS0 Chip Select ((Internal signal: PCS0CS)) Output via PDIOR#
    #define D17F0_PMU_ENSDC3BRK			BIT0	//0/*/*/* Reserved
#define D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_1_Z1		0xE6	//Cx State Break Event Enable 1
    #define D17F0_PMU_ENIDEBRK			BIT7	//0/*/*/* Parallel IDE/SATA Bus Master as Break Event ((Random))
    #define D17F0_PMU_END16EHCIBRK			BIT6	//0/*/*/* D16 EHCI Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENPCIBRK			BIT5	//0/*/*/* PCI Bus Master as Break Event ((Random))
    #define D17F0_PMU_RSE6_4			BIT4	//0/x/x/x Reserved
    #define D17F0_PMU_ENAGPBRK			BIT3	//0/*/*/* NM Bus Master ((AGPBZ#)) as Break Event ((Random))
    #define D17F0_PMU_ENESPIBRK			BIT2	//0/*/*/* eSPI Bus Master as Break Event
    #define D17F0_PMU_END16UHCIBRK			BIT1	//0/*/*/* D16 UHCI Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENACAZBRK			BIT0	//0/*/*/* HDAC / PCI DMA Bus Master as Break Event ((Random))
#define D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_2		0xE7	//Cx State Break Event Enable 2
    #define D17F0_PMU_ENAPIC_ACT			BIT7	//0/0/x/x Enable APIC Cycle Reflect to All Bus Master Activity Effective Signal ((BMSTR_ACT))
    #define D17F0_PMU_ENAZRECF_ACT			BIT6	//0/0/x/x HD Audio Record FIFO Status Reflect Control
    #define D17F0_PMU_ENAZPLAY_C4PINH			BIT5	//0/x/x/x Reserved
    #define D17F0_PMU_ENAZREC_C4PINH			BIT4	//0/x/x/x Reserved
    #define D17F0_PMU_ENAZCOR_PTR_ACT			BIT3	//0/0/x/x HD Audio CORB / RIRB RW Pointer Compare Reflect to DMA Control
    #define D17F0_PMU_ENAZCOR_ACT			BIT2	//0/0/x/x HD Audio CORB / RIRB Run Bit Reflect to DMA Control
    #define D17F0_PMU_ENAZREC_ACT			BIT1	//0/0/x/x HD Audio Record Run Bit Reflect to DMA Control 
    #define D17F0_PMU_ENAZPLAY_ACT			BIT0	//0/0/x/x HD Audio Play Run Bit Reflect to DMA Control
#define D17F0_PMU_WATCHDOG_TIMER_MEM_BASE		0xE8	//Watchdog Timer Memory Base
    #define D17F0_PMU_WTMB			0xFFFFFF00	//0/x/x/x Watchdog Timer Memory Base [31:8]
    #define D17F0_PMU_HW0H			0xFF	//0/R/x/x Hardwire to 0
#define D17F0_PMU_WATCHDOG_TIMER_CTL_C3_LATENCY_CTL		0xEC	//Watchdog Timer Control & C3 Latency Control
    #define D17F0_PMU_RSEC_7_4			0xF0	//0/x/x/x Reserved
    #define D17F0_PMU_ENXC3			BIT3	//0/*/*/* Extend Delay from SLP# De-assert to STPCLK# De-assert 
    #define D17F0_PMU_ENQC3			BIT2	//0/*/*/* Enable Fast C3 Mode ((Random)) 
    #define D17F0_PMU_ENWDT			BIT1	//0/x/x/x Enable Watch Dog Timer
    #define D17F0_PMU_RENMEM			BIT0	//0/x/x/x Watchdog Timer Memory 
#define D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_3		0xED	//Cx State Break Event Enable 3
    #define D17F0_PMU_ENPEG0BRK			BIT7	//0/*/*/* PCIEG0 Bus Master as Break Event ((Random))
    #define D17F0_PMU_RSED_6			BIT6	//0/*/*/* Reserved
    #define D17F0_PMU_ENPEGBRK			BIT5	//0/*/*/* Reserved
    #define D17F0_PMU_ENPE3BRK			BIT4	//0/*/*/* PCIE3 Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENPE2BRK			BIT3	//0/*/*/* PCIE2 Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENPE1BRK			BIT2	//0/*/*/* PCIE1 Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENPE0BRK			BIT1	//0/*/*/* PCIE0 Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENGFXBRK			BIT0	//0/*/*/* GFX Bus Master as Break Event ((Random))
#define D17F0_PMU_CX_STATE_BREAK_EVENT_ENABLE_4		0xEE	//Cx State Break Event Enable 4
    #define D17F0_PMU_ENPE4BRK			BIT7	//0/*/*/* Reserved
    #define D17F0_PMU_ENPEG7BRK			BIT6	//0/*/*/* Reserved
    #define D17F0_PMU_ENPEG6BRK			BIT5	//0/*/*/* Reserved
    #define D17F0_PMU_ENPEG5BRK			BIT4	//0/*/*/* Reserved
    #define D17F0_PMU_ENPEG4BRK			BIT3	//0/*/*/* Reserved
    #define D17F0_PMU_ENPEG3BRK			BIT2	//0/*/*/* PCIEG3 Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENPEG2BRK			BIT1	//0/*/*/* PCIEG2 Bus Master as Break Event ((Random))
    #define D17F0_PMU_ENPEG1BRK			BIT0	//0/*/*/* PCIEG1 Bus Master as Break Event ((Random))
#define D17F0_PMU_BACKDOOR_CTL_REV_ID		0xF5	//Backdoor Control - Revision ID
    #define D17F0_PMU_RIDRE			0xFF	//00h/00h/x/x Backdoor Revision ID
#define D17F0_PMU_FOUNDRY_ID		0xF7	//Foundry ID
    #define D17F0_PMU_FID			0xFF	//0/R/x/x Foundry ID
#define D17F0_PMU_PROCESSOR_CTL		0xFC	//Processor Control
    #define D17F0_PMU_RSFC_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D17F0_PMU_AZBFDISC4			BIT5	//0/*/*/* Inhibit C4 State When HD Audio Transfers Big Format Data
    #define D17F0_PMU_PRORSMDIS			BIT4	//0/x/0/0 Disable Wakeup Events Before the Assertion of  SB2CPU_DPSLPB/VRDSLP
    #define D17F0_PMU_ENDYNC4			BIT3	//0/*/*/* VRDSLP to SB2CPU_DPSLPB Latency Dynamic Adjust Enable
    #define D17F0_PMU_ENDC31ENDC30			(BIT1 + BIT2)	//0/*/*/* DPSLP# to SLP# Latency Adjustment ((Random))
    #define D17F0_PMU_REVIDSEL			BIT0	//0/0/x/x Reserved
//PMIO
#define PMIO_PM_STA		0x00	//Power Management Status
    #define PMIO_WAKA_STS			BIT15	//0/x/x/x Wakeup Status
    #define PMIO_PCIEWK_STS			BIT14	//0/x/x/x PCIe Wakeup Status
    #define PMIO_RS00_13_12			(BIT12 + BIT13)	//0/R/x/x Reserved
    #define PMIO_PWF_STS			BIT11	//0/x/x/x Power Status
    #define PMIO_RTC_STS			BIT10	//0/x/x/x RTC Alarm Status
    #define PMIO_SBTN_STS			BIT9	//0/x/x/x Sleep Button Status
    #define PMIO_PBTN_STS			BIT8	//0/x/x/x Power Button Status
    #define PMIO_RS00_7_6			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define PMIO_GBL_STS			BIT5	//0/x/x/x Global Status
    #define PMIO_BM_STS			BIT4	//0/x/x/x Bus Master Status
    #define PMIO_RS00_3_1			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define PMIO_TMR_STS			BIT0	//0/x/x/x ACPI Timer Carry Status
#define PMIO_PM_ENABLE		0x02	//Power Management Enable
    #define PMIO_RS03_15			BIT15	//0/R/x/x Reserved
    #define PMIO_PCIEWK_DIS			BIT14	//0/0/x/x Disable PCIe Wakeup
    #define PMIO_RS03_13_11			(BIT11 + BIT12 + BIT13)	//0/R/x/x Reserved
    #define PMIO_RTC_EN			BIT10	//0/0/x/x RTC Alarm Enable
    #define PMIO_SBTN_EN			BIT9	//0/0/x/x Sleep Button Enable
    #define PMIO_PBTN_EN			BIT8	//1b/1/x/x Power Button 
    #define PMIO_RS02_7_6			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define PMIO_GBL_EN			BIT5	//0/x/x/x Global Enable
    #define PMIO_RS02_4_1			0x1E	//0/R/x/x Reserved
    #define PMIO_TMR_EN			BIT0	//0/0/x/x ACPI Timer Enable
#define PMIO_PM_CTL		0x04	//Power Management Control
    #define PMIO_RS05_15			BIT15	//0/x/x/x Reserved
    #define PMIO_SLP_EN			BIT13	//0/x/x/x Sleep Enable
    #define PMIO_SLP_TYP			(BIT10 + BIT11 + BIT12)	//000b/x/x/x Sleep Type
    #define PMIO_RS05_0			BIT8	//0/x/x/x Reserved
    #define PMIO_GBL_RLS			BIT2	//0/x/x/x Global Release
    #define PMIO_BM_RLD			BIT1	//0/x/x/x Bus Master Reload ((Random))
    #define PMIO_SCI_EN			BIT0	//0/x/x/x SCI / SMI Select
#define PMIO_SLOW_C4_C5_ENABLE_AND_WAKEUP_EVENT_CTL		0x06	//Slow C4/C5 Enable and Wakeup Event Control
    #define PMIO_GPIOASLEN			BIT7	//0/x/x/x Enable GPIOA SCI/SMI as Slow Break Event
    #define PMIO_GPIO1SLEN			BIT6	//0/x/x/x Enable GPIO1 SCI/SMI as Slow Break Event
    #define PMIO_GPIO0SLEN			BIT5	//0/x/x/x Enable GPIO0 SCI/SMI as Slow Break Event
    #define PMIO_GPI10SLEN			BIT4	//0/x/x/x Enable GPI10 SCI/SMI as Slow Break Event
    #define PMIO_GPI1SLEN			BIT3	//0/x/x/x Enable GPI1 SCI/SMI as Slow Break Event
    #define PMIO_GPI0SLEN			BIT2	//0/x/x/x Enable GPI0 SCI/SMI as Slow Break Event
    #define PMIO_ENSLC5			BIT1	//0/x/x/x Reserved
    #define PMIO_ENSLC4			BIT0	//0/x/x/x Enable Slow C4 Recovery Latency 
#define PMIO_SLOW_C4_C5_WAKEUP_EVENT_CTL		0x07	//Slow C4/C5 Wakeup Event Control
    #define PMIO_TMRC2SLEN			BIT7	//0/x/x/x Enable TMRC2 IRQ as Slow Break Event
    #define PMIO_TMRC1SLEN			BIT6	//0/x/x/x Enable TMRC1 IRQ as Slow Break Event
    #define PMIO_TMRC0SLEN			BIT5	//0/x/x/x Enable TMRC0 IRQ as Slow Break Event
    #define PMIO_HPET2SLEN			BIT4	//0/x/x/x Enable HPET2 IRQ as Slow Break Event
    #define PMIO_HPET1SLEN			BIT3	//0/x/x/x Enable HPET1 IRQ as Slow Break Event
    #define PMIO_HPET0SLEN			BIT2	//0/x/x/x Enable HPET0 IRQ as Slow Break Event
    #define PMIO_RTCSLEN			BIT1	//0/x/x/x Enable RTCIRQ as Slow Break Event
    #define PMIO_RSV_07_0			BIT0	//0/x/x/x Reserved
#define PMIO_ACPI_TIMER		0x08	//ACPI Timer
    #define PMIO_HTMR_VAL			0xFF000000	//0/R/x/x Extended Timer Value
    #define PMIO_TMR_VAL			0xFFFFFF	//0/R/x/x Timer Value
#define PMIO_CX_STATE_ENTRY_LATENCY_CTL_TIMER		0x0C	//Cx State Entry Latency Control Timer
    #define PMIO_T03TMR			(BIT6 + BIT7)	//0/x/x/x Timer to Control the Latency between the Assertion of SB2CPU_DPSLPB and the Assertion of VRDLSP
    #define PMIO_T02TMR			(BIT4 + BIT5)	//0/x/x/x Timer to Control the Latency between the Assertion of SLP# and the Assertion of SB2CPU_DPSLPB
    #define PMIO_T01TMR			0xF	//0/x/x/x Timer to Control the Latency between STPGNT and the Assertion of SLP#
#define PMIO_C4_STATE_LATENCY_CTL_TIMER		0x0D	//C4 State Latency Control Timer
    #define PMIO_C4T09TMR			0xFF	//0/x/x/x Timer to Control the Latency between the De-assertion of NAP# and the De-assertion of VRDSLP in Slow C4 state
#define PMIO_C5_STATE_LATENCY_CTL_TIMER		0x0E	//C5 State Latency Control Timer
    #define PMIO_C5T09TMR			0xFF	//0/x/x/x Reserved
#define PMIO_CX_STATE_EXIT_LATENCY_CTL_TIMER		0x0F	//Cx State Exit Latency Control Timer
    #define PMIO_T07TMR			(BIT5 + BIT6 + BIT7)	//0/x/x/x Timer to Control the Latency between the De-assertion of SLP# and the De-assertion of STPCLK#
    #define PMIO_T06TMR			0x1F	//0/x/x/x Timer to Control the Latency between the De-assertion of SB2CPU_DPSLPB and the De-assertion of SLP#
#define PMIO_PROCESSOR_CTL		0x10	//Processor Control
    #define PMIO_RS10_11_5			0xFE0	//0/x/x/x Reserved
    #define PMIO_THT_EN			BIT4	//0/x/x/x Throttling Enable
    #define PMIO_THTL_DTY			0xF	//0/x/x/x Throttling Duty Cycle
#define PMIO_PROCESSOR_LEVEL_2		0x14	//Processor Level 2
    #define PMIO_PLVL2			0xFF	//0/x/x/x Processor Level 2 (LVL2)
#define PMIO_PROCESSOR_LEVEL_3		0x15	//Processor Level 3
    #define PMIO_PLVL3			0xFF	//0/x/x/x Processor Level 3 (LVL3)
#define PMIO_PROCESSOR_LEVEL_4		0x16	//Processor Level 4
    #define PMIO_PLVL4			0xFF	//0/x/x/x Processor Level 4 (LVL4)
#define PMIO_PROCESSOR_LEVEL_5		0x17	//Processor Level 5
    #define PMIO_PLVL5			0xFF	//0/x/x/x Processor Level 5 (LVL5)
#define PMIO_PROCESSOR_LEVEL_6		0x18	//Processor Level 6
    #define PMIO_PLVL6			0xFF	//0/x/x/x Processor Level 6 (LVL6)
#define PMIO_GENERAL_PURPOSE_STA		0x20	//General Purpose Status
    #define PMIO_SERR_STS			BIT15	//0/x/x/x Reserved
    #define PMIO_WUSB_STS			BIT14	//0/x/x/x USB and XHCI Wakeup Status
    #define PMIO_ACIN_STS			BIT13	//0/x/x/x HDAC Wakeup Status
    #define PMIO_BATL_STS			BIT12	//0/x/x/x Battery Low Status
    #define PMIO_LID_STS			BIT11	//0/x/x/x LID# Status
    #define PMIO_THRM_STS			BIT10	//0/x/x/x Thermal Detect Status
    #define PMIO_MSPME_STS			BIT9	//0/x/x/x Mouse Controller PME Status
    #define PMIO_RI_STS			BIT8	//0/x/x/x RING# Status
    #define PMIO_GPTTOS			BIT7	//0/x/x/x GP3 Timer Time Out Status
    #define PMIO_INTRU_STS			BIT6	//0/x/x/x INTRUDER# Status
    #define PMIO_PME_STS			BIT5	//0/x/x/x PME# Status
    #define PMIO_ESMI_STS			BIT4	//0/x/x/x EXTSMI# Status
    #define PMIO_IO_TRAP_HIT_STS			BIT3	//0/x/x/x IO trap hit Status
    #define PMIO_KBPME_STS			BIT2	//0/x/x/x Internal KBC (Keyboard Controller) PME Status
    #define PMIO_GPI1_STS			BIT1	//0/x/x/x GPI1 Status
    #define PMIO_GPI0_STS			BIT0	//0/x/x/x GPI0 Status 
#define PMIO_GENERAL_PURPOSE_SCI_RESUME_ENABLE		0x22	//General Purpose SCI / RESUME Enable
    #define PMIO_SERR_SC			BIT15	//0/x/x/x Reserved
    #define PMIO_WUSB_SC			BIT14	//0/x/x/x Enable SCI on USB WAKE and XHCI_SUSPME Event
    #define PMIO_ACIN_SC			BIT13	//0/x/x/x Enable SCI on HDAC Wake-Up Event
    #define PMIO_BATSCIEN			BIT12	//0/x/x/x Enable SCI on BATLOW# Event
    #define PMIO_LID_SC			BIT11	//0/x/x/x Enable SCI on LID# Event
    #define PMIO_THRM_SC			BIT10	//0/x/x/x Enable SCI on THRM# Event
    #define PMIO_MSPME_SC			BIT9	//0/x/x/x Enable SCI on Mouse PME
    #define PMIO_RI_SC			BIT8	//0/x/x/x Enable SCI on RING# Event
    #define PMIO_GP3TO_SC			BIT7	//0/x/x/x Enable SCI on GP3 Timer Timeout
    #define PMIO_INTRU_SC			BIT6	//0/x/x/x Enable SCI on INTRUDER# Event
    #define PMIO_PME_SC			BIT5	//0/x/x/x Enable SCI on PME# Assertion
    #define PMIO_ESMI_SC			BIT4	//0/x/x/x Enable SCI on EXTSMI# Assertion
    #define PMIO_IO_TRAP_HIT_SC			BIT3	//0/x/x/x Enable SCI on IO trap hit Assertion
    #define PMIO_KBPME_SC			BIT2	//0/x/x/x Enable SCI on Internal KBC PME
    #define PMIO_GPI1_SC			BIT1	//0/x/x/x Enable SCI on GPI1 Assertion
    #define PMIO_GPI0_SC			BIT0	//0/x/x/x Enable SCI on GPI0 Assertion
#define PMIO_GENERAL_PURPOSE_SMI_RESUME_ENABLE		0x24	//General Purpose SMI / Resume Enable
    #define PMIO_SERR_SM			BIT15	//0/x/x/x Reserved
    #define PMIO_WUSB_SM			BIT14	//0/x/x/x Enable SMI on USB WAKE and XHCI_SUSPME event
    #define PMIO_ACIN_SM			BIT13	//0/x/x/x Enable SMI on HDAC Wake-Up Event
    #define PMIO_BATSMIEN			BIT12	//0/x/x/x Enable SMI on BATLOW# Event
    #define PMIO_LID_SM			BIT11	//0/x/x/x Enable SMI on LID# Event
    #define PMIO_THRM_SM			BIT10	//0/x/x/x Enable SMI on THRM# Event
    #define PMIO_MSPME_SM			BIT9	//0/x/x/x Enable SMI on Mouse PME
    #define PMIO_RI_SM			BIT8	//0/x/x/x Enable SMI on RING# Event
    #define PMIO_RS24_7			BIT7	//0/x/x/x Reserved
    #define PMIO_INTRU_SM			BIT6	//0/x/x/x Enable SMI on INTRUDER# Event
    #define PMIO_PME_SM			BIT5	//0/x/x/x Enable SMI on PME# Assertion
    #define PMIO_ESMI_SM			BIT4	//0/x/x/x Enable SMI on EXTSMI# Assertion
    #define PMIO_IO_TRAP_HIT_SM			BIT3	//0/x/x/x Enable SMI on IO trap hit Assertion
    #define PMIO_KBPME_SM			BIT2	//0/x/x/x Enable SMI on Internal KBC PME
    #define PMIO_GPI1_SM			BIT1	//0/x/x/x Enable SMI on GPI1
    #define PMIO_GPI0_SM			BIT0	//0/x/x/x Enable SMI on GPI0
#define PMIO_PROCESSOR_CTL_Z1		0x26	//Processor Control
    #define PMIO_RS26_7_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define PMIO_GRUNSTP			BIT4	//0/x/x/x Reserved
    #define PMIO_CKRUN_EN			BIT3	//0/x/x/x Reserved
    #define PMIO_KSTPEN			BIT2	//0/*/*/* Host Clock Stop (SB2CPU_DPSLPB) Control
    #define PMIO_SLPEN			BIT1	//0/*/*/* SLP# Assertion in Processor Level 3 Read
    #define PMIO_ENVRCHG			BIT0	//0/*/*/* Lower CPU Voltage (Activate VRDSLP) during C3 / S1
#define PMIO_C2_DOWN_TO_C3_IDLE_TIMER		0x27	//C2 Down to C3 Idle Timer
    #define PMIO_RS27_7_4			0xF0	//0/R/x/x Reserved
    #define PMIO_C3ID_VAL			0xF	//0/x/x/x Initial Value of Bus Master Idle Timer for C3 State 
#define PMIO_GLOBAL_STA		0x28	//Global Status
    #define PMIO_PCS1_STS			BIT15	//0/x/x/x GPIO Range 1 Access Status
    #define PMIO_PCS0_STS			BIT14	//0/x/x/x GPIO Range 0 Access Status
    #define PMIO_PGP3TM			BIT13	//0/x/x/x GP3 Timer Timeout Status
    #define PMIO_PGP2TM			BIT12	//0/x/x/x GP2 Timer Timeout Status
    #define PMIO_FMSMI_STS			BIT11	//0/x/x/x SERIRQ SMI Status
    #define PMIO_SXSMI_STS			BIT10	//0/x/x/x PMIO Rx5[5] (Sleep Enable) Write Status
    #define PMIO_THRMTRIP_STS			BIT9	//0/x/x/x THRMTRIP# Activity Status
    #define PMIO_KRUN_STS			BIT8	//0/x/x/x Reserved
    #define PMIO_PINT1_STS			BIT7	//0/x/x/x Primary IRQ/INIT/NMI/SMI Resume Status
    #define PMIO_SWSMIS			BIT6	//0/x/x/x Software SMI Status
    #define PMIO_BIOS_STS			BIT5	//0/x/x/x BIOS Status
    #define PMIO_LUSB_STS			BIT4	//0/x/x/x Legacy USB Status
    #define PMIO_PGP1TM			BIT3	//0/x/x/x GP1 Timer Timeout Status
    #define PMIO_PGP0TM			BIT2	//0/x/x/x GP0 Timer Timeout Status
    #define PMIO_PSEVTTM			BIT1	//0/x/x/x Secondary Event Timer Timeout Status
    #define PMIO_PACT_STS			BIT0	//0/x/x/x Primary Activity Status
#define PMIO_GLOBAL_ENABLE		0x2A	//Global Enable
    #define PMIO_PCS1SMEN			BIT15	//0/x/x/x SMI Enable on GPIO Range 1 Access
    #define PMIO_PCS0SMEN			BIT14	//0/x/x/x SMI Enable on GPIO Range 0 Access
    #define PMIO_GP3TMEN			BIT13	//0/x/x/x SMI Enable on GP3 Timer Timeout
    #define PMIO_GP2TMEN			BIT12	//0/x/x/x SMI Enable on GP2 Timer Timeout
    #define PMIO_FMSMIEN			BIT11	//0/x/x/x SMI Enable on SERIRQ SMI
    #define PMIO_ENSXSMI			BIT10	//0/x/x/x SMI Enable on Rx05[5] (SLP_EN) Write
    #define PMIO_THRMTRIP_EN			BIT9	//1b/x/x/x THRMTRIP# Activity Power Off Enable
    #define PMIO_KRUNRSEN			BIT8	//0/x/x/x Reserved
    #define PMIO_IRQRSMEN			BIT7	//0/x/x/x Primary IRQ/INIT/NMI/SMI Resume Enable in POS State
    #define PMIO_SWSMIEN			BIT6	//0/x/x/x SMI Enable on Software SMI
    #define PMIO_BIOS_EN			BIT5	//0/x/x/x SMI Enable on BIOS
    #define PMIO_LUSBEN			BIT4	//0/x/x/x SMI Enable on Legacy USB
    #define PMIO_GP1TMEN			BIT3	//0/x/x/x SMI Enable on GP1 Timer Timeout
    #define PMIO_GP0TMEN			BIT2	//0/x/x/x SMI Enable on GP0 Timer Timeout
    #define PMIO_PSEVTEN			BIT1	//0/x/x/x SMI Enable on Secondary Event Timeout
    #define PMIO_PACEN			BIT0	//0/x/x/x SMI Enable on Primary Activity
#define PMIO_GLOBAL_CTL		0x2C	//Global Control
    #define PMIO_THRMTRIP_SLVSTS			BIT15	//0/x/x/x Slave THRMTRIP# Activity Status
    #define PMIO_THRMTRIP_SLVEN			BIT14	//1b/x/x/x Slave THRMTRIP# Activity Power Off Enable
    #define PMIO_THTL_SEL			BIT13	//0/x/x/x Reserved
    #define PMIO_RS2C_12_11			(BIT11 + BIT12)	//0/x/x/x Reserved
    #define PMIO_ENPDDOFF			BIT10	//0/x/x/x Reserved
    #define PMIO_RS2D_9			BIT9	//0/R/x/x Reserved
    #define PMIO_INSMI			BIT8	//0/x/x/x SMI Active Status
    #define PMIO_RS2C_6			BIT6	//0/x/x/x Reserved
    #define PMIO_BTLGRSM			BIT5	//0/0/x/x Enable Battery Low Resume
    #define PMIO_SMIIG			BIT4	//0/R/x/x Reserved
    #define PMIO_STPHALT			BIT3	//0/R/x/x Reserved
    #define PMIO_GBL_STS_Z1			BIT1	//0/0/x/x BIOS Release
    #define PMIO_SMIEN			BIT0	//0b/*/x/x SMI Enable
#define PMIO_C2_DOWN_TO_C4_IDLE_TIMER		0x2E	//C2 Down to C4 Idle Timer
    #define PMIO_C4ID_VAL			0xFF	//0/x/x/x Initial Value of Bus Master Idle Timer for C4 State 
#define PMIO_SW_SMI_CMD		0x2F	//Software SMI Command
    #define PMIO_SMICMD			0xFF	//0/x/x/x SMI Command
#define PMIO_PRIMARY_ACTIVITY_DETECT_STA		0x30	//Primary Activity Detect Status
    #define PMIO_RS30_31_11			0xFFFFF800	//0/R/x/x Reserved
    #define PMIO_AUD_STS			BIT10	//0/x/x/x Audio Status
    #define PMIO_KBC_STS			BIT9	//0/x/x/x Keyboard Controller Access Status
    #define PMIO_VGA_STS			BIT8	//0/x/x/x VGA Access Status
    #define PMIO_LPT_STS			BIT7	//0/x/x/x LPT Port Status
    #define PMIO_COMB_STS			BIT6	//0/x/x/x Serial Port B Access Status
    #define PMIO_COMA_STS			BIT5	//0/x/x/x Serial Port A Access Status
    #define PMIO_FDC_STS			BIT4	//0/x/x/x Floppy Access Status
    #define PMIO_SIDE_STS			BIT3	//0/x/x/x Reserved
    #define PMIO_PIDE_STS			BIT2	//0/x/x/x Reserved
    #define PMIO_PINT_STS			BIT1	//0/x/x/x Primary Interrupt Activity Status
    #define PMIO_DRQ_STS			BIT0	//0/x/x/x PCI Master Access Status
#define PMIO_PRIMARY_ACTIVITY_DETECT_ENABLE		0x34	//Primary Activity Detect Enable
    #define PMIO_RS34_31_11			0xFFFFF000	//0/R/x/x Reserved
    #define PMIO_RS34_11			BIT11	//0/x/x/x Reserved
    #define PMIO_AUD_EN			BIT10	//0/0/x/x SMI on Audio Status
    #define PMIO_KBC_EN			BIT9	//0/0/x/x SMI on Keyboard Controller Status
    #define PMIO_VGA_EN			BIT8	//0/0/x/x SMI on VGA Status
    #define PMIO_LPT_EN			BIT7	//0/0/x/x SMI on LPT Status
    #define PMIO_COMB_EN			BIT6	//0/0/x/x SMI on Serial Port B Status
    #define PMIO_COMA_EN			BIT5	//0/0/x/x SMI on Serial Port A Status
    #define PMIO_FDC_EN			BIT4	//0/0/x/x SMI on Floppy Status
    #define PMIO_SIDE_EN			BIT3	//0/0/x/x Reserved
    #define PMIO_PIDE_EN			BIT2	//0/0/x/x Reserved
    #define PMIO_PINT_EN			BIT1	//0/0/x/x SMI on Primary IRQ Status
    #define PMIO_DRQ_EN			BIT0	//0/0/x/x SMI on PCI Master Status
#define PMIO_GP_TIMER_RELOAD_ENABLE		0x38	//GP Timer Reload Enable
    #define PMIO_KBC_EN1			BIT7	//0/x/x/x GP1 Timer Reload on KBC Access
    #define PMIO_SIO_EN1			BIT6	//0/x/x/x GP1 Timer Reload on Serial Port Access
    #define PMIO_RS38_5			BIT5	//0/x/x/x Reserved
    #define PMIO_VGA_EN1			BIT4	//0/x/x/x GP1 Timer Reload on VGA Access
    #define PMIO_DRV_EN1			BIT3	//0/x/x/x GP1 Timer Reload on Drive Access
    #define PMIO_PCS1ETM3			BIT2	//0/x/x/x GP3 Timer Reload on GPIO Range 1 Access
    #define PMIO_PCS0ETM2			BIT1	//0/x/x/x GP2 Timer Reload on GPIO Range 0 Access
    #define PMIO_ENGP0PLD			BIT0	//0/x/x/x GP0 Timer Reload on Primary Activity
#define PMIO_GENERAL_PURPOSE_OUTPUT_INPUT		0x3C	//General Purpose Output / Input
    #define PMIO_GPIOO_32_17			0xFFFF0000	//FFFFh/x/x/x General Purpose Output 
    #define PMIO_GPIOI_32_17			0xFFFF	//0000h/R/x/x General Purpose Input
#define PMIO_EXTEND_SMI_IO_TRAP_STA		0x40	//Extend SMI/IO Trap Status
    #define PMIO_SVID_SMI_STS			BIT7	//0/x/x/x SVID SMI Status
    #define PMIO_NB2SB_SMI_STS			BIT6	//0/x/x/x NB2SB_SMI Status
    #define PMIO_VPI2SB_SMISLV_STS			BIT5	//0/x/x/x VPI2SB_SMISLV Status
    #define PMIO_BIOSW_STS			BIT4	//0/x/x/x BIOS Write Access Status
    #define PMIO_GP3TO2A_STS			BIT3	//0/x/x/x GP3 Timer Second Timeout Without Cycles
    #define PMIO_GP3TO2_STS			BIT2	//0/x/x/x GP3 Timer Second Timeout Status
    #define PMIO_PCS3_STS			BIT1	//0/x/x/x GPIO Range 3 Access Status
    #define PMIO_PCS2_STS			BIT0	//0/x/x/x GPIO Range 2 Access Status
#define PMIO_EXTEND_SMI_IO_TRAP_STA_Z1		0x41	//Extend SMI/IO Trap Status
    #define PMIO_CPU2SB_SMI_STS			BIT0	//0/x/x/x CPU2SB SMI Status
#define PMIO_EXTEND_SMI_IO_TRAP_ENABLE		0x42	//Extend SMI/IO Trap Enable
    #define PMIO_RS42_7_4			BIT7	//0/R/x/x Reserved
    #define PMIO_NB2SB_PEEQSMI_SM			BIT6	//0/0/x/x PCIe Gen3 EQ SMI Control Register
    #define PMIO_VPI2SB_SMISLV_SM			BIT5	//0/0/x/x VPI2SB_SMISLV Enable
    #define PMIO_BIOSW_EN			BIT4	//0/0/x/x SMI on BIOS Write Access
    #define PMIO_GP3TO2OVEN			BIT3	//0/0/x/x Override GP3 Timer Second Timeout Reboot
    #define PMIO_GP3TO2EN			BIT2	//1b/*/x/x GP3 Timer Second Timeout Reboot
    #define PMIO_PCS3SMEN			BIT1	//0/0/x/x SMI on GPIO Range 3 Access
    #define PMIO_PCS2SMEN			BIT0	//0/0/x/x SMI on GPIO Range 2 Access
#define PMIO_GLOBAL_TRIGGER_MODE_CTL		0x43	//Global Trigger Mode Control
    #define PMIO_LID_POL			(BIT4 + BIT5)	//0/0/x/x LID# Triggering Polarity
    #define PMIO_THRM_POL			(BIT2 + BIT3)	//0/0/x/x THRM# Triggering Polarity
    #define PMIO_PBTN_POL			(BIT0 + BIT1)	//0/0/x/x Power Button Triggering Polarity
#define PMIO_EXTSMI_AND_MISC_INPUT_VALUE		0x44	//EXTSMI and Miscellaneous Input Value
    #define PMIO_RS44_15_13			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define PMIO_PCSWR			BIT12	//0/R/x/x Latest PCS (PCS0-PCS3) IOR/IOW Status 
    #define PMIO_FM_SMI1			BIT11	//0/R/x/x Serial SMI Status
    #define PMIO_SMBIRQ1			BIT10	//0/R/x/x SMBus host1 IRQ Status
    #define PMIO_SMBIRQ			BIT9	//0/R/x/x SMBus host0 IRQ Status
    #define PMIO_SMBRSM			BIT8	//0/R/x/x SMBus Resume Status
    #define PMIO_RS44_7_0			0xFF	//0/R/x/x Reserved
#define PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_Z1		0x46	//General Purpose Output / Input
    #define PMIO_GPIOO_37_33			0xFF00	//FFh/x/x/x General Purpose Output 
    #define PMIO_GPIOI_37_33			0xFF	//18h/R/x/x General Purpose Input
#define PMIO_GENERAL_PURPOSE_INPUT		0x48	//General Purpose Input
    #define PMIO_GPI_16_0_31_0			0xFFFFFFFF	//10F000F2h/R/x/x General Purpose Input
#define PMIO_GENERAL_PURPOSE_OUTPUT		0x4C	//General Purpose Output
    #define PMIO_GPO31_30			(BIT30 + BIT31)	//11b/x/x/x General Purpose Output
    #define PMIO_RS4C_29_28			(BIT28 + BIT29)	//11b/x/x/x Reserved
    #define PMIO_GPO27			BIT27	//1b/x/x/x General Purpose Output 
    #define PMIO_GPO26_25			(BIT25 + BIT26)	//11b/x/x/x General Purpose Output
    #define PMIO_GPO24_19			0x1F80000	//3Fh/x/x/x General Purpose Output
    #define PMIO_GPO18			BIT18	//1b/x/x/x General Purpose Output
    #define PMIO_GPO17			BIT17	//1b/x/x/x General Purpose Output
    #define PMIO_GPO16_7			0x1FF80	//3FFh/x/x/x General Purpose Output
    #define PMIO_GPO6_0			0x7F	//7Fh/x/x/x General Purpose Output
#define PMIO_GPI_CHANGE_STA		0x50	//GPI Change Status
    #define PMIO_SGPI13_STS			BIT7	//0/x/x/x Pin GPI13 Change Status
    #define PMIO_SGPI12_STS			BIT6	//0/x/x/x Pin GPI12 Change Status
    #define PMIO_SGPIO11_STS			BIT5	//0/x/x/x Pin GPIO11 Change Status
    #define PMIO_SGPIO10_STS			BIT4	//0/x/x/x Pin GPIO10 Change Status
    #define PMIO_SGPIO1_STS			BIT3	//0/x/x/x Pin GPIO1 Change Status
    #define PMIO_SGPIO0_STS			BIT2	//0/x/x/x Pin GPIO0 Change Status
    #define PMIO_SGPI1_STS			BIT1	//0/x/x/x Pin GPI1 Change Status
    #define PMIO_SGPI10_STS			BIT0	//0/x/x/x Pin GPI10 Change Status
#define PMIO_GENERAL_PURPOSE_STA_Z1		0x51	//General Purpose Status
    #define PMIO_NB2SB_SCI_STS			BIT7	//0/x/x/x NB2SB SCI Status
    #define PMIO_SVID_SCI_STS			BIT6	//0/x/x/x SVID SCI Status
    #define PMIO_CPU2SB_SCI_STS			BIT5	//0/x/x/x CPU SCI Status
    #define PMIO_ESPI_PME_SCI_STS			BIT4	//0/x/x/x eSPI PME SCI Status
    #define PMIO_VPI2SB_SCISLV_STS			BIT3	//0/x/x/x VPI2SB_SCISLV status
    #define PMIO_NB_MC_PCIE_STS			BIT2	//0/x/x/x Reserved
    #define PMIO_ASFWK_STS			BIT1	//0/x/x/x ASF Wake-Up Status
    #define PMIO_CPUMCA_STS			BIT0	//0/x/x/x CPUMCA_SMI Status
#define PMIO_GENERAL_PURPOSE_IO_STA_1		0x52	//General Purpose IO Status 1
    #define PMIO_GPIO43_STS			BIT7	//0/x/x/x Reserved
    #define PMIO_GPIO42_STS			BIT6	//0/x/x/x Reserved
    #define PMIO_GPIO41_STS			BIT5	//0/x/x/x Reserved
    #define PMIO_GPIO40_STS			BIT4	//0/x/x/x Pin GPIO40 Change Status
    #define PMIO_GPIO39_STS			BIT3	//0/x/x/x Pin GPIO39 Change Status
    #define PMIO_GPIO38_STS			BIT2	//0/x/x/x Pin GPIO38 Change Status
    #define PMIO_GPIO37_STS			BIT1	//0/x/x/x Pin GPIO37 Change Status
    #define PMIO_GPIO36_STS			BIT0	//0/x/x/x Pin GPIO36 Change Status
#define PMIO_GENERAL_PURPOSE_IO_STA_2		0x53	//General Purpose IO Status 2
    #define PMIO_GPIO51_STS			BIT7	//0/x/x/x Pin GPIO51 Change Status
    #define PMIO_GPIO50_STS			BIT6	//0/x/x/x Pin GPIO50 Change Status
    #define PMIO_GPIO49_STS			BIT5	//0/x/x/x Pin GPIO49 Change Status
    #define PMIO_GPIO48_STS			BIT4	//0/x/x/x Pin GPIO48 Change Status
    #define PMIO_GPIO47_STS			BIT3	//0/x/x/x Pin GPIO47 Change Status
    #define PMIO_GPIO46_STS			BIT2	//0/x/x/x Pin GPIO46 Change Status
    #define PMIO_GPIO45_STS			BIT1	//0/x/x/x Pin GPIO45 Change Status
    #define PMIO_GPIO44_STS			BIT0	//0/x/x/x Pin GPIO44 Change Status
#define PMIO_GENERAL_PURPOSE_IO_STA_3		0x54	//General Purpose IO Status 3
    #define PMIO_ESPI2PMU_GPI_STS			BIT10	//0/x/x/x eSPI GPI Status
    #define PMIO_NB2SB_PEEQSCISMI_STS			BIT9	//0/x/x/x PCIE Gen3 EQ Status
    #define PMIO_SWSCI_STS			BIT8	//0/x/x/X SW Trigger SCI Status
    #define PMIO_ESPI_SCISMI_STS			BIT7	//0/x/x/X eSPI SCI/SMI Status
    #define PMIO_ESPI_WAKE_STS			BIT6	//0/x/x/x eSPI Wake SCI Status
    #define PMIO_GPIO57_STS			BIT5	//0/x/x/x Pin GPIO57 Change Status
    #define PMIO_GPIO56_STS			BIT4	//0/x/x/x Pin GPIO56 Change Status
    #define PMIO_GPIO55_STS			BIT3	//0/x/x/x Pin GPIO55 Change Status
    #define PMIO_GPIO54_STS			BIT2	//0/x/x/x Pin GPIO54 Change Status
    #define PMIO_GPIO53_STS			BIT1	//0/x/x/x Pin GPIO53 Change Status
    #define PMIO_GPIO52_STS			BIT0	//0/x/x/x Pin GPIO52 Change Status
#define PMIO_GPI_SCI_RESUME_ENABLE		0x56	//GPI SCI/RESUME Enable
    #define PMIO_SGPI13_SC			BIT7	//0/0/x/x GPI13 SCI Enable (Not used in this product.)
    #define PMIO_SGPI12_SC			BIT6	//0/0/x/x GPI12 SCI Enable (Not used in this product.)
    #define PMIO_SGPIO11_SC			BIT5	//0/0/x/x GPIO11 SCI Enable
    #define PMIO_SGPIO10_SC			BIT4	//0/0/x/x GPIO10 SCI Enable
    #define PMIO_SGPIO1_SC			BIT3	//0/0/x/x GPIO1 SCI Enable
    #define PMIO_SGPIO0_SC			BIT2	//0/0/x/x GPIO0 SCI Enable
    #define PMIO_SGPI1_SC			BIT1	//0/0/x/x GPI1 SCI Enable
    #define PMIO_SGPI10_SC			BIT0	//0/0/x/x GPI10 SCI Enable
#define PMIO_GENERAL_PURPOSE_SCI_ENABLE		0x57	//General Purpose SCI Enable
    #define PMIO_NB2SB_SCI_SC			BIT7	//0/0/x/x NB2SB_SCI Enable
    #define PMIO_SVID_SCI_SC			BIT6	//0/0/x/x SVID SCI Enable
    #define PMIO_CPU2SB_SCI_SC			BIT5	//0/0/x/x Reserved
    #define PMIO_ESPI_PME_SCI_SC			BIT4	//0/0/x/x ESPI_PME_SCI Enable
    #define PMIO_VPI2SB_SCISLV_SC			BIT3	//0/0/x/x VPI2SB_SCISLV SCI Enable
    #define PMIO_ASF_SC			BIT1	//0/0/x/x SCI Enable on ASF Wake
    #define PMIO_RS54_0			BIT0	//0/R/x/x Reserved
#define PMIO_GENERAL_PURPOSE_IO_SCI_RESUME_ENABLE_1		0x58	//General Purpose IO SCI/Resume Enable 1
    #define PMIO_GPIO43_SC			BIT7	//0/0/x/x Reserved
    #define PMIO_GPIO42_SC			BIT6	//0/0/x/x Reserved
    #define PMIO_GPIO41_SC			BIT5	//0/0/x/x Reserved
    #define PMIO_GPIO40_SC			BIT4	//0/0/x/x GPIO40 SCI Enable
    #define PMIO_GPIO39_SC			BIT3	//0/0/x/x GPIO39 SCI Enable
    #define PMIO_GPIO38_SC			BIT2	//0/0/x/x GPIO38 SCI Enable
    #define PMIO_GPIO37_SC			BIT1	//0/0/x/x GPIO37 SCI Enable
    #define PMIO_GPIO36_SC			BIT0	//0/0/x/x GPIO36 SCI Enable
#define PMIO_GENERAL_PURPOSE_IO_SCI_RESUME_ENABLE_2		0x59	//General Purpose IO SCI/Resume Enable 2
    #define PMIO_GPIO51_SC			BIT7	//0/0/x/x GPIO51 SCI Enable
    #define PMIO_GPIO50_SC			BIT6	//0/0/x/x GPIO50 SCI Enable
    #define PMIO_GPIO49_SC			BIT5	//0/0/x/x GPIO49 SCI Enable
    #define PMIO_GPIO48_SC			BIT4	//0/0/x/x GPIO48 SCI Enable
    #define PMIO_GPIO47_SC			BIT3	//0/0/x/x GPIO47 SCI Enable
    #define PMIO_GPIO46_SC			BIT2	//0/0/x/x GPIO46 SCI Enable
    #define PMIO_GPIO45_SC			BIT1	//0/0/x/x GPIO45 SCI Enable
    #define PMIO_GPIO44_SC			BIT0	//0/0/x/x GPIO44 SCI Enable
#define PMIO_GENERAL_PURPOSE_IO_SCI_RESUME_ENABLE_3		0x5A	//General Purpose IO SCI/Resume Enable 3
    #define PMIO_ESPI2PMU_GPI_SC			BIT10	//0/0/x/x eSPI GPI SCI Enable
    #define PMIO_NB2SB_PEEQSCI_SC			BIT9	//0/0/x/x PCIe Gen3 EQ SCI Control Register
    #define PMIO_SWSCI_SC			BIT8	//0/0/x/x SW SCI Enable
    #define PMIO_ESPI_SCI_SC			BIT7	//0/0/x/x eSPI SCI Enable
    #define PMIO_ESPI_WAKE_SC			BIT6	//0/0/x/x eSPI Wake SCI Enable
    #define PMIO_GPIO57_SC			BIT5	//0/0/x/x GPIO57 SCI Enable
    #define PMIO_GPIO56_SC			BIT4	//0/0/x/x GPIO56 SCI Enable
    #define PMIO_GPIO55_SC			BIT3	//0/0/x/x GPIO55 SCI Enable
    #define PMIO_GPIO54_SC			BIT2	//0/0/x/x GPIO54 SCI Enable
    #define PMIO_GPIO53_SC			BIT1	//0/0/x/x GPIO53 SCI Enable
    #define PMIO_GPIO52_SC			BIT0	//0/0/x/x GPIO52 SCI Enable
#define PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_1_2		0x5C	//Dynamic T05 Latency Control Timer Group 1 - 2
    #define PMIO_T05_1			0xFF	//0/x/x/x The 1st Dynamically T05 Control Value
#define PMIO_SW_SMI_DATA		0x5D	//Software SMI Data
    #define PMIO_SMI_DATA			0xFF	//0/x/x/x Software SMI Data
#define PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_2		0x5E	//Dynamic T05 Latency Control Timer Group 2
    #define PMIO_T05_2			0xFF00	//0/x/x/x The 2nd Dynamically T05 Control Value
    #define PMIO_TC4_2			0xFF	//0/x/x/x The C4 Residency Time Value Corresponding to the 2nd T05 Value
#define PMIO_C4P_STATE_EVENT_ENABLE		0x60	//C4P State Event Enable
    #define PMIO_ENC4P			BIT7	//0/0/0/x Enable to Support PLL Gating State during C4 State ((Random))
    #define PMIO_ENC3P			BIT6	//0/0/x/x Enable to Support PLL Gating during C3 State ((Random))
    #define PMIO_ENVART_BM_RST			BIT5	//0/0/x/x Enable VART Master Reset Bus Master Idle Timer
    #define PMIO_ENVART_INHC4P			BIT4	//0/0/x/x Enable VART Transaction to Inhibit C4P ((Random))
    #define PMIO_ENRTC_C4PPME			BIT3	//0/0/x/x Enable RTC Interrupt to Wake Up C4P State
    #define PMIO_ENCSTATE			BIT2	//0/x/x/x C4PSTP# Output to the Clock Generator
    #define PMIO_ENKB_C4PPME			BIT1	//0/0/x/x Enable Keyboard Interrupt to Wake Up C4P State
    #define PMIO_ENMS_C4PPME			BIT0	//0/0/x/x Enable Mouse Interrupt to Wake Up C4P State
#define PMIO_C4P_STATE_BUS_MASTER_IDLE_TIMER		0x61	//C4P State Bus Master Idle Timer
    #define PMIO_RS61_7_4			0xF0	//0/x/x/x Reserved
    #define PMIO_SLOWINT_GATING_DIS			BIT3	//0/0/x/x Slow Interrupt gating when in C0 
    #define PMIO_BM_IDL_TMR			(BIT0 + BIT1 + BIT2)	//0/R/x/x Current Count Value of the Bus Master Idle Timer
#define PMIO_C4P_STATE_BUS_MASTER_IDLE_VALUE		0x62	//C4P State Bus Master Idle Value
    #define PMIO_RS62_7_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define PMIO_RS62_4			BIT4	//0/x/x/x Reserved
    #define PMIO_RS62_3			BIT3	//0/x/x/x Reserved
    #define PMIO_BM_IDLE_VAL			(BIT0 + BIT1 + BIT2)	//000b/x/x/x Initial Value of the Bus Master Idle Timer ((Random))
#define PMIO_C4P_STATE_H2R_TIMER_VALUE		0x63	//C4P State H2R Timer Value
    #define PMIO_H2R_TMR_VAL			0xFF	//0/0/x/x Initial Value of Resume ((C4H2R_ACK)) Timeout Using 4KHz Clock ((Random))
#define PMIO_C4P_STATE_RELATED_ENABLE		0x64	//C4P State Related Enable
    #define PMIO_RS64_7			BIT7	//0/x/x/x Reserved
    #define PMIO_GP3_TMR_BD			BIT6	//0/x/x/x Reserved
    #define PMIO_RS64_5			BIT5	//0/x/x/x Reserved
    #define PMIO_DISWRR10R11			BIT4	//0/0/x/x PMIO Rx26[4:0] Write Protection Bit
    #define PMIO_RS64_3			BIT3	//0/0/x/x Reserved
    #define PMIO_RS64_2			BIT2	//0/x/x/x Reserved
    #define PMIO_ENSA_PLLD			BIT1	//0/0/x/x Reserved
    #define PMIO_RS64_0			BIT0	//0/x/x/x Reserved
#define PMIO_C4P_STATE_USB_AND_NM_RELATED_ENABLE		0x65	//C4P State USB and NM Related Enable
    #define PMIO_ENAPIC_C4PPME			BIT7	//0/0/x/x APIC Interrupt Wake Up System from C4P State
    #define PMIO_ENPIC_C4PPME			BIT6	//0/0/x/x Enable PIC Wakeup Event in C4P
    #define PMIO_ENUSB_PLLD			BIT5	//0/0/x/x Reserved
    #define PMIO_RS65_4			BIT4	//0/x/x/x Reserved
    #define PMIO_RS65_3			BIT3	//0/x/x/x Reserved
    #define PMIO_RS65_2			BIT2	//0/x/x/x Reserved
    #define PMIO_RS65_1			BIT1	//0/x/x/x Reserved
    #define PMIO_RS65_0			BIT0	//0/x/x/x Reserved
#define PMIO_C4P_STATE_NM_AND_HDAC_RELATED_ENABLE		0x66	//C4P State NM and HDAC Related Enable
    #define PMIO_ENHD_BM_RST			BIT7	//0/0/x/x Reserved
    #define PMIO_ENHD_C4PPME			BIT6	//0/0/x/x Reserved
    #define PMIO_ENNB_PLLG			BIT5	//0/0/x/x NM PLL Gating 
    #define PMIO_ENNB_PLLD			BIT4	//0/0/x/x Reserved
    #define PMIO_ENNB_C4PPME			BIT3	//0/0/x/x Reserved
    #define PMIO_ENNB_BM_RST			BIT2	//0/0/x/x Reserved
    #define PMIO_ENSTPGRESP			BIT1	//0/0/x/x Reserved
    #define PMIO_ENNB_C4D3			BIT0	//0/0/x/x Reserved
#define PMIO_C4P_STATE_IDE_RELATED_ENABLE		0x67	//C4P State IDE Related Enable
    #define PMIO_ENC4P2C2			BIT7	//0/0/x/x Enable C4P State Back to C2 ((Random))
    #define PMIO_ENSPI_BM_RST			BIT6	//0/0/x/x Enable SPI Master Reset Bus Master Idle Timer
    #define PMIO_ENH2R_TMOUT			BIT5	//0/0/x/x Enable C4P State Wakeup for Resume Timeout
    #define PMIO_ENUART_C4PPME			BIT4	//0/0/x/x Enable UART Wakeup Event in C4P State
    #define PMIO_DBG_SEL1DBG_SEL0			(BIT2 + BIT3)	//0/0/x/x Reserved
    #define PMIO_ENIDE_BM_RST			BIT1	//0/0/x/x Reserved
    #define PMIO_ENIDE_C4PPME			BIT0	//0/0/x/x Reserved
#define PMIO_C4P_STATE_OTHER_DEVS_RELATED_ENABLE		0x68	//C4P State Other Devices Related Enable
    #define PMIO_ENPCI_BM_RST			BIT7	//0/0/x/x Reserved
    #define PMIO_PG_STS			BIT6	//0/x/x/x PWRGD Status
    #define PMIO_ENPCI_REQC4PME			BIT5	//0/0/x/x Reserved
    #define PMIO_RS68_4			BIT4	//0/0/x/x Reserved
    #define PMIO_RS68_3			BIT3	//0/0/x/x Reserved
    #define PMIO_RS68_2			BIT2	//0/0/x/x Reserved
    #define PMIO_ENSD_BM_RST			BIT1	//0/0/x/x Reserved
    #define PMIO_ENSD_C4PPME			BIT0	//0/0/x/x Reserved
#define PMIO_CLK_GENERATOR_RESUME_TIMER_VALUE		0x69	//Clock Generator Resume Timer Value
    #define PMIO_RS69_7_4			0xF0	//0/x/x/x Reserved
    #define PMIO_CLKGEN_TMR_VAL			0xF	//0/x/x/x Reserved
#define PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_3		0x6A	//Dynamic T05 Latency Control Timer Group 3
    #define PMIO_T05_3			0xFF00	//0/x/x/x The 3rd Dynamically T05 Control Value
    #define PMIO_TC4_3			0xFF	//0/x/x/x The C4 Residency Time Value Corresponding to the 3rd T05 Value
#define PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_4		0x6C	//Dynamic T05 Latency Control Timer Group 4
    #define PMIO_T05_4			0xFF00	//0/x/x/x The 4th Dynamically T05 Control Value
    #define PMIO_TC4_4			0xFF	//0/x/x/x The C4 Residency Time Value Corresponding to the 4th T05 Value
#define PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_5_1		0x6E	//Dynamic T05 Latency Control Timer Group 5 - 1
    #define PMIO_TC4_5			0xFF	//0/x/x/x The C4 Residency Time Value Corresponding to the 5th T05 Value
#define PMIO_SUSPEND_PWR_DOMAIN		0x6F	//Suspend Power Domain
    #define PMIO_OPWR6FB7			BIT7	//0/x/x/x Reserved
    #define PMIO_RPLLPCIEA			BIT6	//1b/1/x/X Reserved
    #define PMIO_RPLLPCIEB			BIT5	//0/0/x/x Reserved
    #define PMIO_ENPGRSM			BIT4	//1b/x/x/x Reserved
    #define PMIO_ENMASK_MINT			BIT3	//0/x/x/x Mask INTR Before 8259 Initialization Disable
    #define PMIO_SOFTRSM			BIT2	//0/x/x/x Soft Resume
    #define PMIO_ENGPI10			BIT1	//0/0/x/x Multi-Function Signal Select: PEXWAKE# vs. GPI10
    #define PMIO_ENSUSSTAT			BIT0	//0/0/x/x Enable GPO4 to Output NM PLL Stop ((SUSTAT#, Internal Signal))
#define PMIO_C2_RESIDENCY_REG		0x70	//C2 Residency Register
    #define PMIO_C2_RESIDENCY			0xFFFFFF	//0/R/x/x C2 Residency Register
#define PMIO_C3_RESIDENCY_REG		0x74	//C3 Residency Register
    #define PMIO_C3_RESIDENCY			0xFFFFFF	//0/R/x/x C3 Residency Register
#define PMIO_C4_RESIDENCY_REG		0x78	//C4 Residency Register
    #define PMIO_C4_RESIDENCY			0xFFFFFF	//0/R/x/x C4 Residency Register
#define PMIO_RAMBIST_ERR_ADR		0x7C	//RAMBIST Error Address
    #define PMIO_BISTADDR			0xFF	//0/R/x/x BATSRAM Read Address When Mismatch Occurred
#define PMIO_RAMBIST_ERR_DATA		0x7D	//RAMBIST Error Data
    #define PMIO_BISTDATA			0xFF	//0/R/x/x Data Read from BATSRAM When Mismatch Occurred
#define PMIO_BATSRAM_BIST_RELATED		0x7E	//BATSRAM BIST related
    #define PMIO_RS7E_7			BIT7	//0/R/x/x Reserved
    #define PMIO_BISTRST			BIT6	//0/x/x/x RAMBIST Logic Reset
    #define PMIO_BISTERR			BIT5	//0/x/x/x RAMBIST Error
    #define PMIO_BISTRUN			BIT4	//0/R/x/x RAMBIST Is Running
    #define PMIO_BISTFAIL			BIT3	//0/R/x/x RAMBIST Failed
    #define PMIO_BISTDONE			BIT2	//1b/R/x/x RAMBIST Has Finished
    #define PMIO_BISTTRG			BIT1	//0/x/x/x RAMBIST Start
    #define PMIO_BISTEN			BIT0	//0/x/x/x RAMBIST Test Enable
#define PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_5_2		0x7F	//Dynamic T05 Latency Control Timer Group 5 - 2
    #define PMIO_T05_5			0xFF	//0/x/x/x The 5th Dynamically T05 Control Value
#define PMIO_SUSPEND_PWR_DOMAIN_Z1		0x80	//Suspend Power Domain
    #define PMIO_OPWR80B7			BIT7	//0/x/x/x Reserved
    #define PMIO_ECO_SB_28_DIS			BIT6	//0/x/x/x PMU PEXWAKE# Control
    #define PMIO_ECO_SB_25_DIS			BIT5	//0/x/x/x PMU SLP# Control
    #define PMIO_EXTSMISL			BIT4	//0/x/x/x EXTSMI# Trigger Mode 
    #define PMIO_XHCI_EN			BIT3	//1b/x/x/x xHCI Function Enable
    #define PMIO_U2EPHYPWROFF			BIT2	//1b/x/x/x U2EPHY Power Off
    #define PMIO_U2SEL_SUS			BIT1	//1b/x/x/x U2EPHY Control
    #define PMIO_RS80_0			BIT0	//1b/x/x/x Reserved
#define PMIO_XHCI_C4P_RELATED_REGS		0x81	//xHCI C4P Related Registers
    #define PMIO_RS81_7_0			0xFF	//0/x/x/x Reserved
#define PMIO_SLOW_C4_C5_WAKEUP_EVENT_CTL_Z1		0x82	//Slow C4/C5 Wakeup Event Control
    #define PMIO_CTMRST			BIT7	//0/x/x/x Reversed
    #define PMIO_ENACTMR			BIT6	//1b/x/x/x Enable Accurate C3/C4/C5 Resume Latency
    #define PMIO_VSYNSLEN			BIT5	//0/x/x/x Enable VSYNC Interrupt as Source of Slow Break Event
    #define PMIO_GP3TMSLEN			BIT4	//0/x/x/x Enable GP3 Timeout SMI as Slow Break Event
    #define PMIO_GP2TMSLEN			BIT3	//0/x/x/x Enable GP2 Timeout SMI as Slow Break Event
    #define PMIO_GP1TMSLEN			BIT2	//0/x/x/x Enable GP1 Timeout SMI as Slow Break Event
    #define PMIO_GP0TMSLEN			BIT1	//0/x/x/x Enable GP0 Timeout SMI as Slow Break Event
    #define PMIO_GPIOBSLEN			BIT0	//0/x/x/x Enable GPIOB as Slow Break Event
#define PMIO_GENERAL_PURPOSE_OUTPUT_Z1		0x83	//General Purpose Output
    #define PMIO_GPO_40_36			0x1F	//1Fh/x/x/x General Purpose Output
#define PMIO_C4_EXIT_LATENCY_CTL_TIMER		0x84	//C4 Exit Latency Control Timer
    #define PMIO_C4T05_NORMAL			0xFF	//0/x/x/x The Latency between the De-assertion of VRDSLP and the De-assertion of SB2CPU_DPSLPB Control Timer
#define PMIO_C5_EXIT_LATENCY_CTL_TIMER		0x85	//C5 Exit Latency Control Timer
    #define PMIO_C5T05_NORMAL			0xFF	//0/x/x/x The Latency between the De-assertion of VRDSLP and the De-assertion of SB2CPU_DPSLPB Control Timer
#define PMIO_SUSPEND_PWR_DOMAIN_Z2		0x86	//Suspend Power Domain
    #define PMIO_RS86_7			BIT7	//0/x/x/x Reserved
    #define PMIO_SRFACKEN			BIT6	//0/0/x/X Wait DRAM Enter Self Refresh before PCIRST# Assertion 
    #define PMIO_SRFEN			BIT5	//0/0/x/X Trigger DRAM to Enter Self Refresh When Warm Reset Asserted
    #define PMIO_RDISCKE			BIT4	//0/0/x/x Release the PMU Control of DRAM CKE0
    #define PMIO_RCKE3LOWEN			BIT3	//0/0/x/x Keep DRAM CKE3 Pad Low When Dual OS Mode Transfer
    #define PMIO_RCKE2LOWEN			BIT2	//0/0/x/x Keep DRAM CKE2 Pad Low When Dual OS Mode Transfer
    #define PMIO_RCKE1LOWEN			BIT1	//0/0/x/x Keep DRAM CKE1 Pad Low When Dual OS Mode Transfer
    #define PMIO_RCKE0LOWEN			BIT0	//0/0/x/x Keep DRAM CKE0 Pad Low When Dual OS Mode Transfer
#define PMIO_DUAL_OS_DRAM_CKE		0x87	//Dual OS DRAM CKE
    #define PMIO_RCKE7LOWEN			BIT7	//0/0/x/x Keep DRAM CKE7 Pad Low When Dual OS Mode Transfer
    #define PMIO_RCKE6LOWEN			BIT6	//0/0/x/x Keep DRAM CKE6 Pad Low When Dual OS Mode Transfer
    #define PMIO_RCKE5LOWEN			BIT5	//0/0/x/x Keep DRAM CKE5 Pad Low When Dual OS Mode Transfer
    #define PMIO_RCKE4LOWEN			BIT4	//0/0/x/x Keep DRAM CKE4 Pad Low When Dual OS Mode Transfer
#define PMIO_TXT_RELATED_REG		0x88	//TXT Related Register
    #define PMIO_TXT_SRT_STS			BIT1	//0/x/x/x TXT SECRET Status
    #define PMIO_RTC_PWR_STS			BIT0	//1b/x/x/x RTC Battery Status
#define PMIO_RTCOSC_CTL_REG		0x8A	//RTCOSC Control Register
    #define PMIO_SBRTC_DYNCLK_EN			BIT4	//1b/x/x/x Reserved
    #define PMIO_EBMCRTC_DYNCLK_EN			BIT3	//1b/x/x/x Reserved
    #define PMIO_SWMODE			BIT2	//0b/x/x/x Reserved
    #define PMIO_T2XT1X			(BIT0 + BIT1)	//01b/x/x/x Current Mode OSC, Current Control
#define PMIO_ALSMB_CTL_REG		0x8B	//ALSMB Control Register
    #define PMIO_ALSMB_DBG_SEL_G2			(BIT6 + BIT7)	//0/x/x/x ALSMB Debug Group2 Select
    #define PMIO_ALSMB_DBG_EN			BIT5	//0/x/x/x ALSMB Debug Enable
    #define PMIO_ALSMB_DBG_SEL			(BIT3 + BIT4)	//0/x/x/x ALSMB Debug Group Select
    #define PMIO_SMBCKSPD			BIT2	//1b/x/x/x ALSMB Work Clock Speedup Enable
    #define PMIO_CHKSTPEN			BIT1	//1b/x/x/x Check STOPS Enable 
    #define PMIO_ALSMB_SEL			BIT0	//1b/x/x/x ALSMB Design Select
#define PMIO_PAD_CTL_REG_WRITE_DATA		0x8C	//PAD Control Register Write Data
    #define PMIO_PAD_DIN			0xFFFFFFFF	//0/x/x/x PAD Control Register Write Data
#define PMIO_PAD_CTL_REG_READ_DATA		0x90	//PAD Control Register Read Data
    #define PMIO_PAD_DOUT			0xFFFFFFFF	//FFFFFFFFh/x/x/x PAD Control Register Read Data
#define PMIO_PAD_CTL_REG		0x94	//PAD Control Register
    #define PMIO_PAD_WR			BIT31	//0/0/x/x PAD Control Register Write Enable
    #define PMIO_PAD_ADDR			0xFFFFFFF	//0/0/x/x PAD Control Register Address
#define PMIO_ALSMB_CTL_REG_Z1		0x99	//ALSMB Control Register
    #define PMIO_SPEEDUP_CLOCK_SEL			(BIT6 + BIT7)	//0/x/x/x Speedup Clock Select (speedup_clock_sel[1:0])
#define PMIO_PAD_CTL_REG_Z1		0x9A	//PAD Control Register
    #define PMIO_P2G_GPIO36_PU			BIT15	//1b/x/x/x PAD GPIO36 PU Control
    #define PMIO_P2G_GPIO36_PU1			BIT14	//0/x/x/x PAD GPIO36 PU1 Control
    #define PMIO_P2G_GPIO36_PU0			BIT13	//0/x/x/x PAD GPIO36 PU0 Control
    #define PMIO_P2G_GPIO36_PD			BIT12	//0/x/x/x PAD GPIO36 PD Control
    #define PMIO_P2G_GPIO36_TN			BIT11	//0/x/x/x PAD GPIO36 TN Control
    #define PMIO_P2G_GPIO36_2_1_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PAD GPIO36 Control [2:0]
    #define PMIO_P2G_GPIO37_PU			BIT7	//1b/x/x/x PAD GPIO37 PU Control
    #define PMIO_P2G_GPIO37_PU1			BIT6	//0/x/x/x PAD GPIO37 PU1 Control
    #define PMIO_P2G_GPIO37_PU0			BIT5	//0/x/x/x PAD GPIO37 PU0 Control
    #define PMIO_P2G_GPIO37_PD			BIT4	//0/x/x/x PAD GPIO37 PD Control
    #define PMIO_P2G_GPIO37_TN			BIT3	//0/x/x/x PAD GPIO37 TN Control
    #define PMIO_P2G_GPIO37_2_1_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PAD GPIO37 Control [2:0]
#define PMIO_SME_PWR_GATING		0x9E	//SME Power Gating
    #define PMIO_EBMC_CSTMR			0x1F00	//1Fh/*/x/x SME Power Chain Settle Time Bits[10:0]
    #define PMIO_EBMC_CLK_EN			BIT5	//1b/*/x/x Enable SME Clock (eBMC_CLK_EN)
    #define PMIO_EBMC_PWRSTS			(BIT3 + BIT4)	//HwInit/x/x/x Power State of eBMC
    #define PMIO_EBMC_PWRON			BIT2	//0/R/x/x Indication of the Power ON Sequence
    #define PMIO_EBMC_PWROFF			BIT1	//0/R/x/x Indication of the Power Off Sequence
    #define PMIO_EBMC_PWRCTRL			BIT0	//HwInit/x/x/x Power Control for eBMC
#define PMIO_CR_GPIO_PAD_CTL		0xB4	//CR/GPIO Pad Control
    #define PMIO_PAD_GPIO13_2_1_0			(BIT27 + BIT28 + BIT29)	//0/x/x/x GPIO13 Mux Control Bits[2:0]
    #define PMIO_PAD_GPIO12_2_1_0			(BIT24 + BIT25 + BIT26)	//0/x/x/x GPIO12 Mux Control Bits[2:0]
    #define PMIO_PAD_GPIO11_2_1_0			(BIT19 + BIT20 + BIT21)	//0/x/x/x GPIO11 Mux Control Bits[2:0]
    #define PMIO_PAD_GPIO10_2_1_0			(BIT16 + BIT17 + BIT18)	//0/x/x/x GPIO10 Mux Control Bits[2:0]
    #define PMIO_MTACHO_PADEN			BIT7	//0/x/x/x Reserved
    #define PMIO_MPWM_PADEN			BIT6	//0/x/x/x Reserved
    #define PMIO_UART2_PADEN_8PIN			BIT5	//0/x/x/x Reserved
    #define PMIO_UART2_PADEN_4PIN			BIT4	//0/x/x/x Reserved
    #define PMIO_UART2_PADEN_2PIN			BIT3	//0/x/x/x Reserved
    #define PMIO_EBMC_IIC2_PADEN			BIT2	//0/x/x/x Reserved
    #define PMIO_EBMC_IIC1_PADEN			BIT1	//0/x/x/x Reserved
    #define PMIO_EBMC_IIC0_PADEN			BIT0	//0/x/x/x Reserved
#define PMIO_GPIO_PAD_CTL		0xB8	//GPIO Pad Control
    #define PMIO_PAD_GPO40_2_1_0			(BIT27 + BIT28 + BIT29)	//0/x/x/x GPO40 Mux Control Bits[2:0]
    #define PMIO_PAD_GPO39_2_1_0			(BIT24 + BIT25 + BIT26)	//0/x/x/x GPO39 Mux Control Bits[2:0]
    #define PMIO_PAD_GPO38_2_1_0			(BIT19 + BIT20 + BIT21)	//0/x/x/x GPO38 Mux Control Bits[2:0]
    #define PMIO_PAD_GPO37_2_1_0			(BIT16 + BIT17 + BIT18)	//0/x/x/x GPO37 Mux Control Bits[2:0]
    #define PMIO_PAD_GPO36_2_1_0			(BIT11 + BIT12 + BIT13)	//0/x/x/x GPO36 Mux Control Bits[2:0]
    #define PMIO_PAD_GPIO27_2_1_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x GPIO27 Mux Control Bits[2:0]
    #define PMIO_PAD_GPIO26_2_1_0			(BIT3 + BIT4 + BIT5)	//0/x/x/x GPIO26 Mux Control Bits[2:0]
    #define PMIO_PAD_GPIO14_2_1_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x GPIO14 Mux Control Bits[2:0]
#define PMIO_CKGPCI_SMB_PAD_CTL		0xBC	//CKGPCI/SMB Pad Control
    #define PMIO_RSBC_31			BIT31	//0/x/x/x Reserved
    #define PMIO_RSBC_29			BIT29	//0/x/x/x Reserved
    #define PMIO_RSBC_28			BIT28	//0/x/x/x Reserved
    #define PMIO_RSBC_27			BIT27	//0/x/x/x Reserved
    #define PMIO_RSBC_25			BIT25	//0/x/x/x Reserved
    #define PMIO_RSBC_24			BIT24	//0/x/x/x Reserved
    #define PMIO_CLKREQ_PAD_EN6			BIT22	//0/x/x/x PCIe Port 6 CLK Request Control Bit
    #define PMIO_CLKREQ_PAD_EN5			BIT21	//0/x/x/x PCIe Port 5 CLK Request Control Bit
    #define PMIO_CLKREQ_PAD_EN4			BIT20	//0/x/x/x PCIe Port 4 CLK Request Control Bit
    #define PMIO_CLKREQ_PAD_EN3			BIT19	//0/x/x/x PCIe Port 3 CLK Request Control Bit
    #define PMIO_CLKREQ_PAD_EN2			BIT18	//0/x/x/x PCIe Port 2 CLK Request Control Bit
    #define PMIO_CLKREQ_PAD_EN1			BIT17	//0/x/x/x PCIe Port 1 CLK Request Control Bit
    #define PMIO_CLKREQ_PAD_EN0			BIT16	//0/x/x/x PCIe Port 0 CLK Request Control Bit
    #define PMIO_RSBC_15			BIT15	//0/x/x/x Reserved
    #define PMIO_RSBC_14			BIT14	//0/x/x/x Reserved
    #define PMIO_RSBC_13			BIT13	//0/x/x/x Reserved
    #define PMIO_RSBC_12			BIT12	//0/x/x/x Reserved
    #define PMIO_RSBC_11			BIT11	//0/x/x/x Reserved
    #define PMIO_RSBC_10			BIT10	//0/x/x/x Reserved
    #define PMIO_RSBC_9			BIT9	//0/x/x/x Reserved
    #define PMIO_RSBC_8			BIT8	//0/x/x/x Reserved
    #define PMIO_SB_CR_PAD_SEL			BIT5	//0/x/x/x Reserved
    #define PMIO_SDIO_PWREN			BIT4	//0/x/x/x Reserved
    #define PMIO_PCIPMEPU_EN			BIT3	//1b/x/x/x PCI PME# Pull Up Enable
    #define PMIO_PAD_PCI_GPO12			BIT2	//0/x/x/x Enable Pad for GPO12 Usage
    #define PMIO_RSV_BC_1			BIT1	//0/x/x/x Reserved
    #define PMIO_PAD_PCI_GPIO7			BIT0	//0/x/x/x Enable Pad for GPIO7 Usage
#define PMIO_UART_PAD_CTL		0xC0	//UART Pad Control
    #define PMIO_PAD_VRDSLP_GPO7			BIT27	//1b/x/x/x Pad Usage Selection: GPO7 vs VRDSLP
    #define PMIO_PAD_DBGCD_EN			BIT22	//0/x/x/x Reserved
    #define PMIO_PAD_EBMC_UART_8PIN			BIT21	//0/x/x/x Reserved
    #define PMIO_PAD_EBMC_UART_4PIN			BIT20	//0/x/x/x Reserved
    #define PMIO_PAD_EBMC_UART_2PIN			BIT19	//0/x/x/x Reserved
    #define PMIO_UART3_PADEN_8PIN			BIT18	//0/x/x/x Reserved
    #define PMIO_UART3_PADEN_4PIN			BIT17	//0/x/x/x Reserved
    #define PMIO_UART3_PADEN_2PIN			BIT16	//0/x/x/x Reserved
    #define PMIO_RSC0_10			BIT10	//1b/x/x/x Reserved
    #define PMIO_RSC0_9			BIT9	//1b/x/x/x Reserved
    #define PMIO_RSC0_8			BIT8	//1b/x/x/x Reserved
    #define PMIO_RSC0_5			BIT5	//1b/x/x/x Reserved
    #define PMIO_RSC0_4			BIT4	//1b/x/x/x Reserved
    #define PMIO_RSC0_3			BIT3	//1b/x/x/x Reserved
    #define PMIO_RSC0_2			BIT2	//1b/x/x/x Reserved
    #define PMIO_RSC0_1			BIT1	//1b/x/x/x Reserved
    #define PMIO_RSC0_0			BIT0	//1b/x/x/x Reserved
#define PMIO_GPI_SMI_RESUME_ENABLE		0xCB	//GPI SMI/RESUME Enable
    #define PMIO_SGPI13_SM			BIT7	//0/0/x/x GPI13 SMI Enable (Not used in this product)
    #define PMIO_SGPI12_SM			BIT6	//0/0/x/x GPI12 SMI Enable (Not used in this product)
    #define PMIO_SGPIO11_SM			BIT5	//0/0/x/x GPIO11 SMI Enable
    #define PMIO_SGPIO10_SM			BIT4	//0/0/x/x GPIO10 SMI Enable
    #define PMIO_SGPIO1_SM			BIT3	//0/0/x/x GPIO1 SMI Enable
    #define PMIO_SGPIO0_SM			BIT2	//0/0/x/x GPIO0 SMI Enable
    #define PMIO_SGPI1_SM			BIT1	//0/0/x/x GPI1 SMI Enable
    #define PMIO_SGPI10_SM			BIT0	//0/0/x/x GPI10 SMI Enable
#define PMIO_GENERAL_PURPOSE_SMI_ENABLE		0xCC	//General Purpose SMI Enable
    #define PMIO_NB2SB_SMI_SM			BIT7	//0/0/x/x NB2SB_SMI Enable
    #define PMIO_SVID_SMI_SM			BIT6	//0/0/x/x SVID SMI Enable
    #define PMIO_CPU2SB_SMI_SM			BIT5	//0/0/x/x CPU2SB SMI Enable
    #define PMIO_ASF_SM			BIT1	//0/0/x/x SMI Enable on ASF Wake
    #define PMIO_CPUMCA_SM			BIT0	//0/0/x/x Enable SMI on CPUMCA_SMI Assertion
#define PMIO_GENERAL_PURPOSE_IO_SMI_ENABLE_1		0xCD	//General Purpose IO SMI Enable 1
    #define PMIO_GPIO43_SM			BIT7	//0/0/x/x Reserved
    #define PMIO_GPIO42_SM			BIT6	//0/0/x/x Reserved
    #define PMIO_GPIO41_SM			BIT5	//0/0/x/x Reserved
    #define PMIO_GPIO40_SM			BIT4	//0/0/x/x GPIO40 SMI Enable
    #define PMIO_GPIO39_SM			BIT3	//0/0/x/x GPIO39 SMI Enable
    #define PMIO_GPIO38_SM			BIT2	//0/0/x/x GPIO38 SMI Enable
    #define PMIO_GPIO37_SM			BIT1	//0/0/x/x GPIO37 SMI Enable
    #define PMIO_GPIO36_SM			BIT0	//0/0/x/x GPIO36 SMI Enable
#define PMIO_GENERAL_PURPOSE_IO_SMI_ENABLE_2		0xCE	//General Purpose IO SMI Enable 2
    #define PMIO_GPIO51_SM			BIT7	//0/0/x/x GPIO51 SMI Enable
    #define PMIO_GPIO50_SM			BIT6	//0/0/x/x GPIO50 SMI Enable
    #define PMIO_GPIO49_SM			BIT5	//0/0/x/x GPIO49 SMI Enable
    #define PMIO_GPIO48_SM			BIT4	//0/0/x/x GPIO48 SMI Enable
    #define PMIO_GPIO47_SM			BIT3	//0/0/x/x GPIO47 SMI Enable
    #define PMIO_GPIO46_SM			BIT2	//0/0/x/x GPIO46 SMI Enable
    #define PMIO_GPIO45_SM			BIT1	//0/0/x/x GPIO45 SMI Enable
    #define PMIO_GPIO44_SM			BIT0	//0/0/x/x GPIO44 SMI Enable
#define PMIO_GENERAL_PURPOSE_IO_SMI_ENABLE_3		0xCF	//General Purpose IO SMI Enable 3
    #define PMIO_ESPI_SMI_SM			BIT7	//0/0/x/x ESPI_SMI Enable
    #define PMIO_GPIO57_SM			BIT5	//0/0/x/x GPIO57 SMI Enable 
    #define PMIO_GPIO56_SM			BIT4	//0/0/x/x GPIO56 SMI Enable
    #define PMIO_GPIO55_SM			BIT3	//0/0/x/x GPIO55 SMI Enable
    #define PMIO_GPIO54_SM			BIT2	//0/0/x/x GPIO54 SMI Enable
    #define PMIO_GPIO53_SM			BIT1	//0/0/x/x GPIO53 SMI Enable
    #define PMIO_GPIO52_SM			BIT0	//0/0/x/x GPIO52 SMI Enable
#define PMIO_SME_DEBUG_PIN_DEV_ENABLE_REG		0xD0	//SME Debug Pin Device Enable Register
    #define PMIO_EBMCD_DBGS			0xFF	//0/x/x/x SME Device Debug Pin Output Select
#define PMIO_SME_DEBUG_PIN_SEL_REG		0xD1	//SME Debug Pin Select Register
    #define PMIO_EBMC_DBGS			0xFF	//0/x/x/x SME Debug Pin Output Select
#define PMIO_SME_DEBUG_PIN_DEV_ENABLE_REG_Z1		0xD2	//SME Debug Pin Device Enable Register
    #define PMIO_EBMC_DBGEN			BIT0	//0/x/x/x SME Debug Pin Output Enable
#define PMIO_CHX002_DESIGN_BACKDOOR_REG_1		0xD3	//((CHX002)) Design Backdoor Register 1
    #define PMIO_ISOINHC4_SPRC4C5			BIT6	//0/0/x/X ISOINHC4 Separate C4 and C5/C6 Control Register
    #define PMIO_FERRMSK			BIT5	//0/0/x/x Reserved
    #define PMIO_SWSCI_TRG			BIT4	//0/0/x/x SW Trigger SCI Bit
    #define PMIO_ISOINHC4_BD			BIT3	//1b/1/x/X Reserved
    #define PMIO_VRM_STABLE_BD			BIT2	//1b/1/x/X Reserved
    #define PMIO_RSV_D3_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define PMIO_CHX002_DESIGN_BACKDOOR_REG_2		0xD4	//((CHX002)) Design Backdoor Register 2
    #define PMIO_CPU_JTAG_PCIRST_EN			BIT7	//1b/x/x/x CPU_JTAG_PCIRST Function Enable
    #define PMIO_EBMC_PWRBTNEN			BIT6	//1b/x/x/x Reserved
    #define PMIO_ENHPET_C4P			BIT5	//0/x/x/x Reserved
    #define PMIO_ENHPET_C4PME			BIT4	//1b/x/x/X Reserved
    #define PMIO_ENR18C4_FIX			BIT3	//1b/x/x/x Reserved (Do Not Program)
    #define PMIO_TXTSRT_EN			BIT2	//1b/x/x/X TXT.SECRET.STS Implementation Option
    #define PMIO_TXTRST_EN			BIT1	//1b/x/x/x TXT_CMD_RESET Implementation
    #define PMIO_PBTN_EHC			BIT0	//1b/x/x/X PWRBTN Enhance Issue
#define PMIO_DEBUG_SIGNAL_SEL_REG		0xD5	//((CHX002)) Debug Signal Select Register
    #define PMIO_DBGSEL_SBG			BIT15	//0/x/x/X SB Debug Signal Enable
    #define PMIO_DBGSEL_SB24			BIT12	//0/x/x/X SB Debug Signal Group 2 Selection Control Bit[4]
    #define PMIO_DBGSEL_SB23			BIT11	//0/x/x/X SB Debug Signal Group 2 Selection Control Bit[3]
    #define PMIO_DBGSEL_SB22			BIT10	//0/x/x/X SB Debug Signal Group 2 Selection Control Bit[2]
    #define PMIO_DBGSEL_SB21			BIT9	//0/x/x/X SB Debug Signal Group 2 Selection Control Bit[1]
    #define PMIO_DBGSEL_SB20			BIT8	//0/x/x/X SB Debug Signal Group 2 Selection Control Bit[0]
    #define PMIO_DBGSEL_SB14			BIT4	//0/x/x/X SB Debug Signal Group 1 Selection Control Bit[4]
    #define PMIO_DBGSEL_SB13			BIT3	//0/x/x/x SB Debug Signal Group 1 Selection Control Bit[3]
    #define PMIO_DBGSEL_SB12			BIT2	//0/x/x/X SB Debug Signal Group 1 Selection Control Bit[2]
    #define PMIO_DBGSEL_SB11			BIT1	//0/x/x/x SB Debug Signal Group 1 Selection Control Bit[1]
    #define PMIO_DBGSEL_SB10			BIT0	//0/x/x/X SB Debug Signal Group 1 Selection Control Bit[0]
#define PMIO_GENERAL_PURPOSE_INPUT_TRIGGER_MODE		0xD8	//General Purpose Input Trigger Mode
    #define PMIO_GPI1M1_TRG			(BIT30 + BIT31)	//0/x/x/x GPI1 Method 1 Trigger Mode
    #define PMIO_GPI_TGM_14_12_5_0			0x3F000000	//0/x/x/x Bit [29:28]: GPI14
    #define PMIO_GPI_TGM_11_9_5_0			0xFC0000	//0/x/x/x Bit [23:22]: GPI11 (not used in this product)
    #define PMIO_GPI_TGM_8_7_3_0			0x3C000	//0/x/x/x Bit [17:16]: GPI8 (not used in this product)
    #define PMIO_GPI_TGM_6_1_0			(BIT12 + BIT13)	//0/x/x/x Bit [13:12]: GPI6
    #define PMIO_GPI_TGM_5_0_11_0			0xFFF	//0/x/x/x Bit [11:10]: GPI5
#define PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_15_0_TRIGGER_MODE		0xDC	//General Purpose Output / Input 15_0 Trigger Mode
    #define PMIO_GPIO_TGM_15_8_15_0			0xFFFF0000	//0/x/x/x General Purpose Input
    #define PMIO_GPIO_TGM_7_2_11_0			0xFFF0	//0/x/x/x General Purpose Input
    #define PMIO_GPIO_TGM_1_0_3_0			0xF	//0/x/x/x General Purpose Input
#define PMIO_GENERAL_PURPOSE_OUTPUT_INPUT_29_16_TRIGGER_MODE		0xE0	//General Purpose Output / Input 29_16 Trigger Mode
    #define PMIO_RSV_E0_31_28			0xF0000000	//0/x/x/x Reserved
    #define PMIO_GPIO_TGM_29_28_3_0			0xF000000	//0/x/x/x Bit [27:26]: GPIO29
    #define PMIO_GPIO_TGM_27_16_23_0			0xFFFFFF	//0/x/x/x Bit [23:22]: GPIO27
#define PMIO_PCIE_OBFF_CTL_REG		0xE4	//PCIe OBFF Control Register
    #define PMIO_OBFFMSG			BIT2	//0/x/x/x OBFF Message Mode Enable
    #define PMIO_OBFF_EN			BIT1	//0/x/x/x OBFF Enable
    #define PMIO_OBFFMOD			BIT0	//0/x/x/x OBFF Mode Select
#define PMIO_LGY_SEL_CTL_REG		0xE5	//LGY Select Control Register
    #define PMIO_KBDC_LGY_SEL			BIT3	//0/x/x/x KBDC Design Select (KBDC_LGY_SEL)
    #define PMIO_INTC_LGY_SEL			BIT2	//0/x/x/x INTC Design Select (INTC_LGY_SEL)
    #define PMIO_DMAC_LGY_SEL			BIT1	//0/x/x/x DMAC Design Select (DMAC_LGY_SEL)
    #define PMIO_TMRC_LGY_SEL			BIT0	//0/x/x/x TMRC Design Select (TMRC_LGY_SEL)
#define PMIO_LGY_SEL_CTL_REG2		0xE6	//LGY Select Control Register2
#define PMIO_ESPI_SUSPEND_DOMAIN_CTL_REG		0xE7	//eSPI Suspend Domain Control Register
    #define PMIO_ESPI2PMU_GPI_SM			BIT3	//0/x/x/x eSPI GPI SMI Enable
    #define PMIO_ESPI2PMU_GPI_RSTEN			BIT2	//0/x/x/X eSPI GPI Reset Control Register
    #define PMIO_ESPI_PWRRST_EN			BIT1	//0/x/x/x eSPI Power Cycle Reset Control Register
    #define PMIO_ENESPI_SW			BIT0	//0/x/x/x eSPI Enable When eSPI Slave Is SIO 
#define PMIO_IO_TRAP_PCI_DATA		0xE8	//I/O Trap PCI Data
    #define PMIO_PCID			0xFFFFFFFF	//0/R/x/x PCI Data During I/O Trap SMI
#define PMIO_IO_TRAP_PCI_IO_ADR		0xEC	//I/O Trap PCI I/O Address
    #define PMIO_PCIA			0xFFFF	//0/R/x/x PCI Address During I/O Trap SMI
#define PMIO_IO_TRAP_PCI_CMD_BYTE_ENABLE		0xEE	//I/O Trap PCI Command / Byte Enable
    #define PMIO_PCICMD			0xF0	//0/R/x/x PCI Command Type During I/O Trap SMI
    #define PMIO_PCIBE			0xF	//0/R/x/x PCI Byte Enable During I/O Trap SMI
#define PMIO_DYNAMIC_T05_LATENCY_CTL_TIMER_GRP_1_1		0xEF	//Dynamic T05 Latency Control Timer Group 1 - 1
    #define PMIO_TC4_1			0xFF	//0/x/x/x The C4 Residency Time Value Corresponding to the 1st T05 Value
#define PMIO_SVID_STARTUP_DELAY_TIMER		0xF0	//SVID Startup Delay Timer
    #define PMIO_STARTUP_DEL_TIMER			0xFF	//FFh/x/x/x SVID Startup Delay Timer (STARTUP_DEL_TIMER)
#define PMIO_SVID_RESEND_FAIL_STA_VRM0_1_2_4_ERR_STA		0xF1	//SVID Resend Fail Status/VRM0/1/2/4 Error Status
    #define PMIO_RSD_F2_15_13			(BIT13 + BIT14 + BIT15)	//0/x/x/x Reserved
    #define PMIO_SVID_VRM4_PARITY_ERR_STS			BIT12	//0/x/x/x VRM4 Parity Error Status
    #define PMIO_SVID_VRM4_OVER_TEMP_STS			BIT11	//0/x/x/x VRM4 Over Temp Status
    #define PMIO_SVID_VRM4_OVER_CURR_STS			BIT10	//0/x/x/x VRM4 Over Current Status
    #define PMIO_SVID_VRM2_PARITY_ERR_STS			BIT9	//0/x/x/x VRM2 Parity Error Status
    #define PMIO_SVID_VRM2_OVER_TEMP_STS			BIT8	//0/x/x/x VRM2 Over Temp Status
    #define PMIO_SVID_VRM2_OVER_CURR_STS			BIT7	//0/x/x/x VRM2 Over Current Status
    #define PMIO_SVID_VRM1_PARITY_ERR_STS			BIT6	//0/x/x/x VRM1 Parity Error Status
    #define PMIO_SVID_VRM1_OVER_TEMP_STS			BIT5	//0/x/x/x VRM1 Over Temp Status
    #define PMIO_SVID_VRM1_OVER_CURR_STS			BIT4	//0/x/x/x VRM1 Over Current Status
    #define PMIO_SVID_VRM0_PARITY_ERR_STS			BIT3	//0/x/x/x VRM0 Parity Error Status
    #define PMIO_SVID_VRM0_OVER_TEMP_STS			BIT2	//0/x/x/x VRM0 Over Temp Status
    #define PMIO_SVID_VRM0_OVER_CURR_STS			BIT1	//0/x/x/x VRM0 Over Current Status
    #define PMIO_SVID_RSD_FAIL_STS			BIT0	//0/x/x/x SVID Resend Fail Status
#define PMIO_DUAL_SOCKET_CTL1_REG		0xF3	//DUAL-SOCKET Control1 Register
    #define PMIO_RSV_F3_7_2			0xFC	//0/x/x/x Reserved
    #define PMIO_RESUME_IN_EN			BIT1	//0/x/x/x Resume Input From Remote Socket Enable
    #define PMIO_RESUME_OUT_EN			BIT0	//0/x/x/x Resume Output To Remote Socket Enable 
#define PMIO_DUAL_SOCKET_CTL2_REG		0xF4	//DUAL-SOCKET Control2 Register
    #define PMIO_RSV_F4_7			BIT7	//0/x/x/x Reserved
    #define PMIO_SB2VPI_SCISLV_B_EN			BIT6	//0/0/x/x SB2VPI_SCISLV_B Enable Register
    #define PMIO_SB2VPI_SMISLV_B_EN			BIT5	//0/0/x/x SB2VPI_SMISLV_B Enable Register
    #define PMIO_VPI2SB_SCISLV_B_EN			BIT4	//0/0/x/x VPI2SB_SCISLV_B Enable Register
    #define PMIO_VPI2SB_SMISLV_B_EN			BIT3	//0/0/x/x VPI2SB_SMISLV_B Enable Register
    #define PMIO_MSK_BM_STS			BIT2	//0/0/x/x Bus Master Status Control
    #define PMIO_SX_STS			(BIT0 + BIT1)	//0/x/x/x Sx State
#define PMIO_USB_AND_XHCI_WAKEUP_TRIGGER_MODE_CTL_REG		0xF5	//USB and xHCI Wakeup Trigger Mode Control Register
    #define PMIO_WUSB_TRGM			BIT7	//0/x/x/x USB and xHCI Wakeup Status Trigger Mode Control
    #define PMIO_RSV_F5_6			BIT6	//0/x/x/x Reserved
    #define PMIO_RSV_F5_4_0			0x1F	//0/x/x/x Reserved
#define PMIO_SYSTEM_MIN_SLEEP_DELAY_SEL_REG		0xF6	//System Min Sleep Delay Select Register
    #define PMIO_PGWAIT_S1S0			(BIT1 + BIT2)	//10b/x/x/x System Min Sleep Delay Select
    #define PMIO_PGWAIT_SLC_EN			BIT0	//1b/x/x/x System Min Sleep Delay Control Enable
#define PMIO_VPI_TURN_OFF_MSG_REG		0xF7	//VPI Turn Off MSG Register
    #define PMIO_PCIE_PTOMSG_TMROUT_EN			BIT2	//0/x/x/x VPI PME Turn Message Timout Enable
    #define PMIO_PCIE_PTOMSG_EN			BIT1	//1b/x/x/x Reserved
    #define PMIO_RSTBTN_EN			BIT0	//1b/x/x/x Reserved
#define PMIO_CHX002_VDDOFF_GRP_DEBUG_SIGNAL_SEL_REG		0xF8	//CHX002 VDDOFF Group Debug Signal Select Register
    #define PMIO_RDBGVDDOFF_GRP_SEL7_0			0xFF	//0/x/x/x VDD OFF Group Select
#define PMIO_CHX002_VDDOFF_MODE_DEBUG_SIGNAL_SEL_REG		0xF9	//CHX002 VDDOFF Mode Debug Signal Select Register
    #define PMIO_RDBGVDDOFF_MOD_SEL7_0			0xFF	//0/x/x/x VDD OFF Module Select
#define PMIO_CHX002_VDDOFF_MODE_DEBUG_SIGNAL_ENABLE_REG		0xFA	//CHX002 VDDOFF Mode Debug Signal Enable Register
    #define PMIO_RSV_FA_7_1			0xFE	//0/x/x/x Reserved
    #define PMIO_RDBGVDDOFFMODE			BIT0	//0/x/x/x VDD OFF Debugging Mode
//WT-MMIO
#define WTMMIO_WATCHDOG_CTL_STA		0x00	//Watchdog Control / Status
    #define WTMMIO_RS00_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define WTMMIO_TDT			BIT7	//0/x/x/x Watchdog Trigger
    #define WTMMIO_RS00_6_4			(BIT4 + BIT5 + BIT6)	//0/R/x/x Reserved
    #define WTMMIO_WDOG_DISABLE			BIT3	//0/x/x/x Disable Watchdog
    #define WTMMIO_WDOG_ACT			BIT2	//0/x/x/x Watchdog Action
    #define WTMMIO_WDOG_TO			BIT1	//0/x/x/x Watchdog Fired
    #define WTMMIO_WDOG_RUN			BIT0	//0/x/x/x Watchdog Enable
#define WTMMIO_WATCHDOG_COUNT		0x04	//Watchdog Count
    #define WTMMIO_RS04_31_10			0xFFFFFC00	//0/R/x/x Reserved
    #define WTMMIO_WDOG_CNT_IN			0x3FF	//0/x/x/x Count Register
//SMIO
#define SMIO_SMBUS_HOST_STA		0x00	//SMBus Host Status
    #define SMIO_HT_PECERR			BIT7	//0/0/x/x SMB Host PEC Error
    #define SMIO_INUSE			BIT6	//0/x/x/x SMB Semaphore
    #define SMIO_NSMBSRST			BIT5	//0/0/x/x New SMBus Software Reset
    #define SMIO_FAILED			BIT4	//0/0/x/x Failed Bus Transaction
    #define SMIO_BUS_ERR			BIT3	//0/0/x/x Bus Collision
    #define SMIO_DEV_ERR			BIT2	//0/0/x/x Device Error
    #define SMIO_INTER			BIT1	//0/0/x/x SMBus Interrupt
    #define SMIO_HOST_BUSY			BIT0	//0/R/x/x Host Busy
#define SMIO_SMBUS_HOST_SLAVE_STA		0x01	//SMBus Host Slave Status
    #define SMIO_GP_PECERR			BIT7	//0/0/x/x SMB GPIO Slave PEC Error
    #define SMIO_SL_PECERR			BIT6	//0/0/x/x SMB Host Slave PEC Error
    #define SMIO_ALERT_STS			BIT5	//0/x/x/x SMBus Slave Alert Status
    #define SMIO_SHDW2_STS			BIT4	//0/0/x/x Shadow 2 Status
    #define SMIO_SHDW1_STS			BIT3	//0/0/x/x Shadow 1 Status
    #define SMIO_SLV_STS			BIT2	//0/0/x/x Slave Status
    #define SMIO_RS01_1			BIT1	//0/R/x/x Reserved
    #define SMIO_SLV_BSY			BIT0	//0/R/x/x Slave Busy
#define SMIO_SMBUS_HOST_CTL		0x02	//SMBus Host Control
    #define SMIO_HT_PECEN			BIT7	//0/x/x/x PEC Enable
    #define SMIO_START			BIT6	//0/x/x/x Start
    #define SMIO_SMB_CMD_PROT			0x3C	//0000b/x/x/x SMBus Command Protocol
    #define SMIO_KILL			BIT1	//0/x/x/x Kill Transaction in Progress
    #define SMIO_INTEREN			BIT0	//0/x/x/x Interrupt Enable
#define SMIO_SMBUS_HOST_CMD		0x03	//SMBus Host Command
    #define SMIO_HST_CMD			0xFF	//0/x/x/x SMBus Host Command
#define SMIO_SMBUS_HOST_ADR		0x04	//SMBus Host Address
    #define SMIO_SMB_ADRESS			0xFE	//0/x/x/x SMBus Address
    #define SMIO_SMB_RW			BIT0	//0/x/x/x SMBus Read or Write
#define SMIO_SMBUS_HOST_DATA_0		0x05	//SMBus Host Data 0
    #define SMIO_SMBD0			0xFF	//0/x/x/x SMBus Data 0
#define SMIO_SMBUS_HOST_DATA_1		0x06	//SMBus Host Data 1
    #define SMIO_SMBD1			0xFF	//0/x/x/x SMBus Data 1
#define SMIO_SMBUS_HOST_BLOCK_DATA		0x07	//SMBus  Host Block Data
    #define SMIO_BLK_DATA			0xFF	//0/x/x/x SMBus Block Data Byte
#define SMIO_SMBUS_HOST_SLAVE_CTL		0x08	//SMBus Host Slave Control
    #define SMIO_GP_PECEN			BIT7	//0/x/x/x SMBus GPIO Slave PEC Enable
    #define SMIO_SL_PECEN			BIT6	//0/x/x/x SMBus Host Slave PEC Enable
    #define SMIO_PECABORT			BIT5	//0/x/x/x PEC Abort
    #define SMIO_GPIO_EN			BIT4	//0/x/x/x SMBus GPIO Slave Enable 
    #define SMIO_ALERT_EN			BIT3	//0/x/x/x SMB Alert Enable
    #define SMIO_SHDW2_EN			BIT2	//0/x/x/x SMBus Shadow Port 2 Enable
    #define SMIO_SHDW1_EN			BIT1	//0/x/x/x SMBus Shadow Port 1 Enable
    #define SMIO_SLV_EN			BIT0	//0/x/x/x SMBus Slave Enable
#define SMIO_SMBUS_SLAVE_SHADOW_CMD		0x09	//SMBus Slave Shadow Command
    #define SMIO_SHDW_CMD			0xFF	//0/R/x/x Shadow Command
#define SMIO_SMBUS_SLAVE_EVENT		0x0A	//SMBus Slave Event
    #define SMIO_SMB_SLV_EVT			0xFFFF	//0/x/x/x SMBus  Slave Event
#define SMIO_SMBUS_SLAVE_DATA		0x0C	//SMBus Slave Data
    #define SMIO_SMB_SLV_DATA			0xFFFF	//0/R/x/x SMBus Slave Data
#define SMIO_SMBUS_HOST_ALERT_AND_RECODE_BANK_0_SET		0x0E	//SMBus Host Alert and Recode Bank 0 set
    #define SMIO_RSV			0xF8	//0/x/x/x Reserved
    #define SMIO_BANK0_SEL			BIT2	//0/x/x/x Bank 0 Selected or Not (Read_Bank_Addr)
    #define SMIO_HOST_ALERT_STS			BIT1	//0/x/x/x SMBus Host 0 Alert Status
    #define SMIO_HOST_ALERT_EN			BIT0	//0/x/x/x SMBus Host 0 Alert Enable
#define SMIO_SMBUS_GPIO_SLAVE_ADR		0x0F	//SMBus GPIO Slave Address
    #define SMIO_GPIOADD			0xFE	//0/x/x/x SMBus GPIO Slave Address
    #define SMIO_RS0F_0			BIT0	//0/x/x/x Reserved
#endif
