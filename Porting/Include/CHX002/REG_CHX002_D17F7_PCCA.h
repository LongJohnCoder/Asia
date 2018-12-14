//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		PCCA					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D17F7_PCCA_R110(A0).doc(final)MOD_PCCA.xls
#ifndef _CHX002_D17F7_PCCA_H
#define _CHX002_D17F7_PCCA_H
//D17F7
#define D17F7_VID		0x00	//Vendor ID
    #define D17F7_VENDOR_ID			0xFFFF	//1106h/x/x/x VIA Technologies ID Code
#define D17F7_DID		0x02	//Device ID
    #define D17F7_DEVICEID			0xFFFF	//31B7h/x/x/x Device ID
#define D17F7_PCI_CMD		0x04	//PCI Command
    #define D17F7_RFBACK			BIT9	//0/R/x/x Fast Back-to-Back Cycle Enable
    #define D17F7_RSERR			BIT8	//0/0/x/x SERR# Enable
    #define D17F7_RPTYERR			BIT6	//0/x/x/x Parity Error Response
    #define D17F7_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D17F7_RMWINV			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D17F7_RSPCYC			BIT3	//0/R/x/x Respond To Special Cycle
    #define D17F7_RMSTR			BIT2	//0/x/x/x Bus Master
    #define D17F7_RENMEM			BIT1	//0/x/x/x Memory Space Access 
    #define D17F7_RENIO			BIT0	//0/R/x/x I/O Space Access
#define D17F7_PCI_STA		0x06	//PCI Status
    #define D17F7_SPERRS			BIT15	//0/0/x/x Detected Parity Error
    #define D17F7_SERRS			BIT14	//0/0/x/x Signaled System Error (SERR# Asserted)
    #define D17F7_SMABORT			BIT13	//0/0/x/x Received Master-Abort (Except Special Cycle)
    #define D17F7_STABORTM			BIT12	//0/0/x/x Received Target-Abort 
    #define D17F7_STABORTS			BIT11	//0/R/x/x Target-Abort Assertion
    #define D17F7_DEVS_1_0			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D17F7_SDPERRS			BIT8	//0/0/x/x Set When Set or Observed SERR# and Parity Error
    #define D17F7_RFBKS			BIT7	//0/R/x/x Capable of Accepting Fast Back-to-back as a Target
    #define D17F7_RUDF			BIT6	//0/R/x/x Reserved
    #define D17F7_R66M			BIT5	//0/R/x/x 66 MHz Capable
    #define D17F7_RCAP			BIT4	//0/R/x/x Capability List
#define D17F7_REV_ID		0x08	//Revision ID
    #define D17F7_REVISIONID			0xFF	//04h/x/x/x Revision ID
#define D17F7_PCI_HEADER_REGS		0x09	//PCI Header Registers
    #define D17F7_REG0B09			0xFFFFFF	//060000h/R/x/x Class Code
#define D17F7_LATENCY_TIMER		0x0D	//Latency Timer
    #define D17F7_MLT_7_3			0xF8	//1h/1h/x/x PCI Bus Time Slice Bits [7:3] for CPU as A Master (In Unit of PCI Clocks)
    #define D17F7_MLT_2_0			(BIT0 + BIT1 + BIT2)	//0/R/x/x Reserved
#define D17F7_HEADER_TYPE		0x0E	//Header Type
    #define D17F7_HEADERTYPE_CFG1			0xFF	//0/R/x/x Header Type
#define D17F7_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D17F7_BIST			BIT7	//0/R/x/x BIST
#define D17F7_SVID		0x2C	//Subsystem Vendor ID
    #define D17F7_VENDORID			0xFFFF	//1106h/R/x/x Subsystem Vendor ID
#define D17F7_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D17F7_SUBSYSTEMID			0xFFFF	//A353h/R/x/x Subsystem ID
#define D17F7_CAP_POINTER		0x34	//Capability Pointer
    #define D17F7_CAPPTR_7_0			0xFF	//0/R/x/x Capability Pointer 
#define D17F7_RESERVED		0x4C	//Reserved
#define D17F7_RESERVED_Z1		0x4D	//Reserved
#define D17F7_RESERVED_Z2		0x4E	//Reserved
#define D17F7_SOUTH_NORTH_MODULE_IF_CTL		0x4F	//South-North Module Interface Control
    #define D17F7_RCFGINFCTL			BIT7	//0/0/x/x Reserved ((Random))
    #define D17F7_RENPPB			BIT6	//0/x/x/x Reserved
    #define D17F7_RSPECYC_ADDR31			BIT5	//0/x/x/x Reserved
    #define D17F7_MSI_DAT_FORMAT			BIT4	//0/x/x/x MSI Data Format in MSI Cycle
    #define D17F7_RP2CR_RFIFODAT			BIT3	//0/0/x/x Improve P2CR (PCI Master to DRAM Read Cycle) Performance ((Random))
    #define D17F7_RHIDE_IC2P			BIT2	//0/0/x/x Reserved ((Random))
    #define D17F7_RCFGEXT			BIT1	//1b/1/x/x Support Extended Configuration Space Up to 4096 Bytes
    #define D17F7_RP2CFLSH			BIT0	//1b/1/x/x Reserved
#define D17F7_BUS_PRIORITY_OF_SM_PERIPHERAL_DEV_1		0x50	//Bus Priority of SM Peripheral Device 1
    #define D17F7_RCRH			BIT7	//0/x/x/x Reserved
    #define D17F7_RSDH			BIT6	//0/0/x/x HPET Priority ((Random))
    #define D17F7_RSATAH			BIT5	//0/x/x/x USB D14F0 UHCI Priority ((Random))
    #define D17F7_RESPIH			BIT4	//0/0/x/x USB D16F0F1 Priority ((Random))
    #define D17F7_RAZALIAH			BIT3	//1b/1/x/x HDAC Priority
    #define D17F7_RIDEH			BIT2	//0/x/x/x Reserved
    #define D17F7_RMISCH			BIT1	//1b/1/x/x LPC / UART / FIR Priority
    #define D17F7_RPCI1H			BIT0	//0/0/x/x PCI1 Priority ((Random))
#define D17F7_P2P_BRIDGE_RELATED_CTL		0x51	//P2P Bridge Related Control
    #define D17F7_RSUB_DEC_P2P			BIT7	//1b/1/x/x Reserved
    #define D17F7_RUPBYPASS			BIT6	//0/0/x/x Reserved(Do Not Program)
    #define D17F7_RLUPARB1			BIT1	//1b/1/x/x Reserved
    #define D17F7_RSUBDECOD			BIT0	//0/x/x/x Reserved
#define D17F7_CCA_ARBITRATION_OCCUPY_TIMER_CTL		0x52	//CCA Arbitration Occupy Timer Control
    #define D17F7_RSBTIM_3_0			0xF0	//0001b/0001b/x/x SM Internal Device Occupy Timer ((Random))
    #define D17F7_RAZTIM_3_0			0xF	//0001b/0001b/x/x HDAC Occupy Timer ((Random))
#define D17F7_CCA_ARBITRATION_PROMOTE_TIMER_CTL		0x53	//CCA Arbitration Promote Timer Control
    #define D17F7_RSBPTIM_3_0			0xF0	//0001b/0001b/x/x SM Internal Device Promote Timer ((only CHX002, [1:0] Random))
    #define D17F7_RAZPTIM_3_0			0xF	//0001b/0001b/x/x HDAC Promote Timer ((only CHX002, [1:0] Random))
#define D17F7_CCA_REQ_TIMING_OPTION		0x54	//CCA REQ Timing Option
    #define D17F7_RVARTSYNC			BIT7	//0/0/x/x Synchronize VART REQ for Better Timing ((Random))
    #define D17F7_RSPISYNC			BIT6	//0/0/x/x Synchronize SPI REQ for Better Timing ((Random))
    #define D17F7_RCRSYNC			BIT5	//0/0/x/x Reserved
    #define D17F7_RSDIOSYNC			BIT4	//0/0/x/x Reserved in CHX002
    #define D17F7_RUSBSYNC			BIT1	//1b/1/x/x Synchronize eSPI REQ for Better Timing ((Random))
    #define D17F7_RLPCSYNC			BIT0	//0/0/x/x Synchronize LPC / ISA REQ for Better Timing ((Random))
#define D17F7_RIOPU_FOR_PAD		0x55	//RIOPU for PAD
    #define D17F7_RIOPU2			BIT2	//1b/1/x/x IRQ14, PDIOR#, PDIOW# Signal Pad Internal Pull-Up
    #define D17F7_RIOPU1			BIT1	//1b/1/x/x Reserved.  Do Not Program.
    #define D17F7_RIOPU0			BIT0	//1b/1/x/x Reserved
#define D17F7_STRAPPING_PIN_VALUE		0x56	//Strapping Pin Value
    #define D17F7_ENDBGC			BIT7	//HwInit/x/x/x DebugLink Mode Enable Status
    #define D17F7_NFCBIOS			BIT6	//HwInit/x/x/x Reserved
    #define D17F7_ENPCIMASTER			BIT5	//HwInit/x/x/x Reserved
    #define D17F7_ENDBGLINK			BIT4	//HwInit/x/x/x Same as Bit 7 ((ENDBGC))
    #define D17F7_DNCFREQ			BIT3	//HwInit/x/x/x Reserved
    #define D17F7_ENLPCFIRM			BIT2	//HwInit/x/x/x LPC FWH Command
    #define D17F7_DNABOOT			BIT1	//HwInit/x/x/x System Auto Reboot
    #define D17F7_GCLKSEL_GPIO			BIT0	//HwInit/x/x/x NB/SB config path clock selection (for debug only)
#define D17F7_STRAPPING_PIN_VALUE_Z1		0x57	//Strapping Pin Value
    #define D17F7_STRP_VID_VRM			BIT7	//HwInit/x/x/x VRM Type Selection
    #define D17F7_LPCCLK_PH			(BIT5 + BIT6)	//HwInit/x/x/x 2-bits for LPC Clock Phase Adjustment
    #define D17F7_RPLLEAINITCTL_GPIO			BIT4	//HwInit/x/x/x Enable PCIECLK Output Time
    #define D17F7_SB2NB_CLK27M_SEL_1			BIT3	//HwInit/x/x/x Select 27MHz Clock Source
    #define D17F7_DCKINIT_SEL_GPIO			(BIT1 + BIT2)	//HwInit/x/x/x Chipset Initial Clock Frequency Selection
    #define D17F7_STRP_LPC_TRM			BIT0	//HwInit/x/x/x TPM Type Selection
#define D17F7_STRAPPING_PIN_VALUE_Z2		0x58	//Strapping Pin Value
    #define D17F7_STRP_PLLCPUREFSEL_GPIO1			BIT7	//HwInit/x/x/x VPIL Clock Selection
    #define D17F7_STRP_AZ			(BIT5 + BIT6)	//HwInit/x/x/x SPI/LPC/eSPI Selection
    #define D17F7_ENBMCDBG			BIT4	//HwInit/x/x/x Enable SME/MCU Debug Mode When SME Is Disabled
    #define D17F7_RTC2SB_EBMC_DIS			BIT3	//HwInit/x/x/x Disable SME
    #define D17F7_SB2NB_CLK27M_SEL			BIT2	//HwInit/x/x/x Select 27MHz Clock Source
    #define D17F7_ADR_WIDTH_SEL			BIT1	//HwInit/x/x/x SPI 24-bit / 32-bit Address Indication
    #define D17F7_BOOT_BYPASS_ESPI			BIT0	//HwInit/x/x/x Reserved
#define D17F7_STRAPPING_PIN_VALUE_Z3		0x59	//Strapping Pin Value
    #define D17F7_S1MRSTX			BIT7	//HwInit/x/x/x PWRGD to PCIRST# de-assert Latency Control Used only in simulation/ATE.
    #define D17F7_STRP_VRM_NUM			BIT6	//HwInit/x/x/x VRM Number Selection
    #define D17F7_M2_SATA_PCIE_SEL			BIT5	//HwInit/x/x/x Reserved
    #define D17F7_STRP_PHYB_M2			BIT4	//HwInit/x/x/x Indicates if PHYB Will Be Connected to M.2 Device
    #define D17F7_STRP_MST_SLV_SOCKET			BIT3	//HwInit/x/x/x Reserved
    #define D17F7_STRP_DUAL_SOCKET			BIT2	//HwInit/x/x/x Single or Dual-Socket Select
    #define D17F7_STRP_PLLCPUREFSEL_GPIO			BIT1	//HwInit/x/x/x PLLCPU 100MHz Backup Selection for Debug and ATE Test
    #define D17F7_RTC2SB_INTRU_STRP			BIT0	//HwInit/x/x/x RTCOSC SWMODE Control
#define D17F7_STRAPPING_PIN_VALUE_Z4		0x5A	//Strapping Pin Value
    #define D17F7_RSV_5A_7_2			0xF8	//0/x/x/x Reserved
    #define D17F7_STRP_MSPISS2			BIT2	//HwInit/x/x/x SPI/LPC/eSPI Selection
    #define D17F7_STRP_CORECLK_GATE			BIT1	//HwInit/x/x/x Backup Option
    #define D17F7_CPUSELDBGCLK			BIT0	//HwInit/x/x/x CPU Debug Clock Select (for debug only)
#define D17F7_DRAM_ENDING_FOR_BANK_7		0x60	//DRAM Ending for Bank 7
    #define D17F7_REND7_31_24			0xFF	//01h/x/x/x Reserved
#define D17F7_PAGE_C_ROM_SHADOW_CTL		0x61	//Page-C ROM Shadow Control
    #define D17F7_SENCC_1_0			(BIT6 + BIT7)	//00b/x/x/x Reserved
    #define D17F7_SENC8_1_0			(BIT4 + BIT5)	//00b/x/x/x Reserved
    #define D17F7_SENC4_1_0			(BIT2 + BIT3)	//00b/x/x/x Reserved
    #define D17F7_SENC0_1_0			(BIT0 + BIT1)	//00b/x/x/x Reserved
#define D17F7_PAGE_D_ROM_SHADOW_CTL		0x62	//Page-D ROM Shadow Control
    #define D17F7_SENDC_1_0			(BIT6 + BIT7)	//00b/x/x/x Reserved
    #define D17F7_SEND8_1_0			(BIT4 + BIT5)	//00b/x/x/x Reserved
    #define D17F7_SEND4_1_0			(BIT2 + BIT3)	//00b/x/x/x Reserved
    #define D17F7_SEND0_1_0			(BIT0 + BIT1)	//00b/x/x/x Reserved
#define D17F7_PAGE_E_F_ROM_MEM_HOLE_AND_SMI_DECODING		0x63	//Page-E / F ROM, Memory Hole and SMI Decoding
    #define D17F7_SENE_1_0			(BIT6 + BIT7)	//00b/x/x/x Reserved
    #define D17F7_SENF_1_0			(BIT4 + BIT5)	//00b/x/x/x Reserved
    #define D17F7_RHOLE_1_0			(BIT2 + BIT3)	//00b/x/x/x Reserved
    #define D17F7_RABKDOFF			BIT1	//0/x/x/x Reserved
    #define D17F7_RRWABK			BIT0	//0/x/x/x Reserved
#define D17F7_PAGE_E_ROM_SHADOW_CTL		0x64	//Page-E ROM Shadow Control
    #define D17F7_SENEC_1_0			(BIT6 + BIT7)	//00b/x/x/x Reserved
    #define D17F7_SENE8_1_0			(BIT4 + BIT5)	//00b/x/x/x Reserved
    #define D17F7_SENE4_1_0			(BIT2 + BIT3)	//00b/x/x/x Reserved
    #define D17F7_SENE0_1_0			(BIT0 + BIT1)	//00b/x/x/x Reserved
#define D17F7_ISO_FUN		0x65	//ISO Function
    #define D17F7_PM1ISO			BIT7	//0b/x/x/x Reserved
    #define D17F7_MISO			BIT6	//0b/x/x/x ISO Function for LPC
    #define D17F7_VARTISO			BIT5	//0b/x/x/x ISO Function for VART
    #define D17F7_AZISO			BIT4	//0b/x/x/x ISO Function for AZALIA(HDAC)
    #define D17F7_ESPIISO0			BIT3	//0b/x/x/x ISO Function for USB D16F0F1
    #define D17F7_SDIO1			BIT2	//0b/x/x/x ISO Function for HPET
    #define D17F7_SDISO2			BIT1	//0b/x/x/x ISO Function for USB D16F7
    #define D17F7_SDISO3			BIT0	//0b/x/x/x ISO Function for D14F0 UHCI
#define D17F7_ISO_FUN_Z1		0x66	//ISO Function
    #define D17F7_VAS_VID_SEL			BIT5	//0b/x/x/x Reserved
    #define D17F7_PCI2PCI_BRIDGE_EN			BIT4	//0b/x/x/x Reserved
    #define D17F7_UDSO			BIT3	//0b/x/x/x ISO Function for USB D14F7
    #define D17F7_VIOD			BIT2	//0b/x/x/x ISO Function for eSPI
    #define D17F7_SPIISO			BIT1	//0b/x/x/x ISO Function for SPI
    #define D17F7_APICISO			BIT0	//0b/x/x/x ISO Function for APIC
#define D17F7_RESERVED_Z3		0x67	//Reserved
    #define D17F7_C2P_ORG_DUT			BIT0	//0/x/x/x Control C2P Signal Register-in
#define D17F7_RESERVED_Z4		0x68	//Reserved
#define D17F7_RESERVED_Z5		0x69	//Reserved
#define D17F7_RESERVED_Z6		0x6A	//Reserved
#define D17F7_RESERVED_Z7		0x6B	//Reserved
#define D17F7_CPU_TO_PCI_FLOW_CTL_1		0x70	//CPU to PCI Flow Control 1
    #define D17F7_RC2PWB			BIT7	//0/x/1/x CPU to PCI(C2P) Post-Write
    #define D17F7_RP2CRBOFF			BIT6	//0/0/x/x PCI Delay Transaction for Master Read when Timer Time-Out ((Random))
    #define D17F7_REHPRFRP2CPF			(BIT4 + BIT5)	//00b/00b/00b/x PCI Master to DRAM Prefetch Control ((Random))
    #define D17F7_RSLRD			BIT3	//0/0/0/x PCI Delay Transaction for Master Read ((Random))
    #define D17F7_RP2CWMG			BIT2	//0/0/x/x Reserved
    #define D17F7_RDLYT1			BIT1	//0/x/1/x Delay Transaction ((Random))
    #define D17F7_R8QWLN			BIT0	//0/0/x/x Cache Line Size ((Random))
#define D17F7_CPU_TO_PCI_FLOW_CTL_2		0x71	//CPU to PCI Flow Control 2
    #define D17F7_SRRTYS			BIT7	//0/x/x/x Retry Status ((Random))
    #define D17F7_RTMOUT			BIT6	//1b/x/x/x Reserved
    #define D17F7_RRTYCNTRRTYCNT1			(BIT4 + BIT5)	//00b/00b/x/x Retry Count (Before Back Off CPU) ((Random))
    #define D17F7_RSVBST			BIT3	//1b/1/x/x PCI Burst Timeout Enable ((Random))
    #define D17F7_RIDSELSB			BIT2	//0/0/x/x Reserved
    #define D17F7_RTYPE1			BIT1	//0/0/x/x Compatible TYPE#1 Configuration Cycle AD31
    #define D17F7_RIDSEL			BIT0	//0/0/x/x Reserved
#define D17F7_PCI_P2C_READ_CACHING_AND_PREFETCH_CTL		0x72	//PCI P2C Read Caching and Prefetch Control
    #define D17F7_RPDMAXARB			BIT7	//0/x/x/x Reserved
    #define D17F7_AZ_DS_CLKEN			BIT6	//0/x/x/x AZALIA (HDAC) Downstream Clock Enable
    #define D17F7_RCONSRV			BIT5	//1b/1/x/x Reserved
    #define D17F7_RSFLHFRM			BIT3	//1b/1/x/x Reserved
    #define D17F7_RP2CRRS			BIT2	//1b/1/x/x Reserved
    #define D17F7_RPFEN_1_0			(BIT0 + BIT1)	//10b/10b/x/x Reserved
#define D17F7_PCI_MASTER_CTL		0x73	//PCI Master Control
    #define D17F7_PRFH_4K_DISABLE			BIT7	//0/0/x/x Control CCA Cross 4K Pprefetch for Internal Device P2C Read Cycle
    #define D17F7_RMS1WS			BIT6	//0/0/x/x PCI Master 1-Wait State Write ((Random))
    #define D17F7_RMS1RS			BIT5	//0/0/x/x PCI Master 1-Wait State Read ((Random))
    #define D17F7_RP1NOWSC			BIT4	//0/0/x/x Reserved
    #define D17F7_RP2CRB1N			BIT3	//0/0/x/x P2CR Caching Flush by NM Special Cycle((SPCYC)) ((Random))
    #define D17F7_RBROKE			BIT0	//1b/1/x/x Reserved
#define D17F7_SOUTH_NORTH_MODULE_IF_CTL_Z1		0x74	//South-North Module Interface Control
    #define D17F7_RDMCCACLK			BIT7	//0/0/x/x Dynamic CCA Clock Stop
    #define D17F7_RDMPCI1CLK			BIT6	//0/0/0/0 Dynamic PCI1 Clock Stop (Including VKCKG)
    #define D17F7_RLCKFLSH			BIT4	//0/0/x/x Lock Cycle Issued by CPU((LOCKCYC)) Flush P2C Cycles Before C2P
    #define D17F7_RLCKXP2C			BIT3	//1b/1/x/x Reserved
    #define D17F7_RFSBVK			BIT2	//1b/1/x/x APIC FSB Directly Up through CCA (not on PCI) (Random))
#define D17F7_PCI_ARBITRATION_1		0x75	//PCI Arbitration 1
    #define D17F7_RARBT			BIT7	//0/0/x/x Arbitration Mode ((Random))
    #define D17F7_RMLT_2_0			(BIT4 + BIT5 + BIT6)	//000b/000b/x/x Reserved
    #define D17F7_RARB4G			BIT3	//1b/1/x/x PCI Master Time-out / New Grant Mechanism Control
    #define D17F7_RPTMS_2_0			(BIT0 + BIT1 + BIT2)	//111b/111b/x/x PCI Master Bus Timeout
#define D17F7_PCI_ARBITRATION_2		0x76	//PCI Arbitration 2
    #define D17F7_RIO22EN			BIT7	//0/0/x/x IO Port 22 Enable (SM)
    #define D17F7_RGNTPK			BIT6	//1b/1/x/x Reserved
    #define D17F7_RCFARB_1_0			(BIT4 + BIT5)	//01b/1/x/x Reserved
    #define D17F7_RRQ4MP1RRQ4MP0			(BIT2 + BIT3)	//00b/00b/x/x Selected REQ# as REQ4 for PCI1 ((RQ4)) ((Random))
    #define D17F7_RSYNCREQ			BIT1	//0/0/x/x Synchronize REQ before Being Using ((Random))
    #define D17F7_RRQ4HI			BIT0	//0/0/x/x Enable REQ4 for PCI1 ((RQ4)) as High Priority Master 
#define D17F7_SOUTH_MODULE_MISC_CTL		0x77	//South Module Miscellaneous Control
    #define D17F7_ROP2CFLSH			BIT6	//1b/1/x/x Reserved
    #define D17F7_RFFTMR_1_0			(BIT3 + BIT4)	//10b/10b/x/x Reserved
    #define D17F7_GX77_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x Reserved
#define D17F7_PCI_PAD_CTL		0x78	//PCI PAD Control
#define D17F7_PCI_V2X_DATA_STROBE_OUT_DELAY_CTL		0x79	//PCI V2X Data / Strobe Out Delay Control
#define D17F7_PCI_V2X_DEV_CAP		0x7A	//PCI V2X Device Capability
    #define D17F7_RPV2X_CAP			BIT7	//0/0/x/x PREQ's Device Is Capable of V2X
    #define D17F7_RV2X_CAP6			BIT6	//0/0/x/x REQ6's Device Is Capable of V2X
    #define D17F7_RV2X_CAP5			BIT5	//0/0/x/x REQ5's Device Is Capable of V2X
    #define D17F7_RV2X_CAP4			BIT4	//0/0/x/x REQ4's Device Is Capable of V2X
    #define D17F7_RV2X_CAP3			BIT3	//0/0/x/x REQ3's Device Is Capable of V2X
    #define D17F7_RV2X_CAP2			BIT2	//0/0/x/x REQ2's Device Is Capable of V2X
    #define D17F7_RV2X_CAP1			BIT1	//0/0/x/x REQ1's Device Is Capable of V2X
    #define D17F7_RV2X_CAP0			BIT0	//0/0/x/x REQ0's Device Is Capable of V2X
#define D17F7_REQ_STA		0x7B	//REQ Status
    #define D17F7_PREQ_ST			BIT7	//0/0/x/x PREQ Status
    #define D17F7_REQ6_ST			BIT6	//0/0/x/x REQ6 Status
    #define D17F7_REQ5_ST			BIT5	//0/0/x/x REQ5 Status
    #define D17F7_REQ4_ST			BIT4	//0/0/x/x REQ4 Status
    #define D17F7_REQ3_ST			BIT3	//0/0/x/x REQ3 Status
    #define D17F7_REQ2_ST			BIT2	//0/0/x/x REQ2 Status
    #define D17F7_REQ1_ST			BIT1	//0/0/x/x REQ1 Status
    #define D17F7_REQ0_ST			BIT0	//0/0/x/x REQ0 Status
#define D17F7_MSI_RELATED_CTL		0x7C	//MSI Related Control
    #define D17F7_RHIDE_TPM			BIT7	//0/0/x/x Reserved
    #define D17F7_RNMIFSB			BIT2	//0/0/x/x Reserved
    #define D17F7_RUPMSG			BIT1	//1b/1/x/x APIC FSB Is Directly Up Through CCA (not on PCI)
#define D17F7_TEST_MODE_AND_OPERATION		0x7E	//Test Mode ¨C AND Operation
    #define D17F7_ANHIT_4_0			0x1F	//0/x/x/x Reserved 
#define D17F7_TEST_MODE_OR_OPERATION		0x7F	//Test Mode ¨C OR Operation
    #define D17F7_ORHIT_4_0			0x1F	//0/x/x/x Reserved
#define D17F7_CCA_NEW_FEATURE_OPTION		0x80	//CCA New Feature Option
    #define D17F7_RP2CRFLH_3_1			(BIT5 + BIT6 + BIT7)	//001b/1/x/x PCI1 New P2CR Flush Mechanism Control
    #define D17F7_RMERGE_NEW			BIT4	//0/x/x/x Reserved 
    #define D17F7_RPDMA_C3ENARB			BIT3	//0/x/x/x Reserved 
    #define D17F7_RP1RNPW			BIT2	//1b/1/x/x PCI1((P1)) Upstream Read Cycle Does Not Pass Write
    #define D17F7_RAZRNPW			BIT1	//1b/1/x/x HDAC Upstream Read Cycle Does Not Pass Write
    #define D17F7_RAPICFLSAZW			BIT0	//1b/1/x/x APIC Cycle Blocks Upstream Write
#define D17F7_BUS_PRIORITY_OF_SM_PERIPHERAL_DEV_2		0x81	//Bus Priority of SM Peripheral Device 2
    #define D17F7_C2PR_BLOCK_P2C			BIT5	//1b/1/x/x Reserved
    #define D17F7_SLOW_CYC_BLOCK_SEL			BIT4	//0/0/x/x Reserved
    #define D17F7_PM1WCOUNTR_SEL			BIT3	//0/0/x/x Reserved
    #define D17F7_P1G4CRQ_GNT			BIT2	//0/0/x/x Patch for DUAL Address Cycle 
    #define D17F7_RVARTH			BIT1	//1b/1/x/x VART Priority  ((Random))
    #define D17F7_RSPIH			BIT0	//0/0/x/x SPI Priority ((Random))
#define D17F7_CCA_TEST_MODE_ADR_SEL		0x82	//CCA Test Mode Address Selection
    #define D17F7_RCCA_MON_RESULT			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define D17F7_RCCA_MON_MODE			0x3C	//0/x/x/x CCA Interface Monitor Action Selection
    #define D17F7_RPMA_SEL			BIT0	//1b/1/x/x CCA Test Mode Address Selection
#define D17F7_CCA_TEST_MODE_ADR_SEL_Z1		0x83	//CCA Test Mode Address Selection
    #define D17F7_RCCADBG_MODE2_3_0			0xF0	//0/x/x/x CCA Debug Mode2 Signals Selection
    #define D17F7_RCCADBG_MODE_3_0			0xF	//0/x/x/x CCA Debug Mode1 Signals Selection
#define D17F7_READ_PASSES_WRITE_CTL		0x84	//Read Passes Write Control
    #define D17F7_RSPIRPW			BIT6	//0/0/x/x SPI Slave Mode Read Passes Write
    #define D17F7_RCRPW			BIT5	//0/0/x/x Reserved
    #define D17F7_RSRPW			BIT4	//0/0/x/x SDIO Read Passes Write
    #define D17F7_RMRPW			BIT3	//0/0/x/x LPC Read Passes Write
    #define D17F7_RURPW			BIT1	//0/0/x/x eSPI Read Passes Write
    #define D17F7_DIS_AZATEST_NEWPATH			BIT0	//0/0/x/x Reserved
#define D17F7_PCCA_NEW_FEATURE_CTL		0x85	//PCCA New Feature Control
    #define D17F7_RNEW_PCIOE			BIT7	//1b/1/x/x Control Whether PCI Bus¡¯s TRDY, STOP, DEVSEL PAD¡¯s OE To Be Register out
    #define D17F7_RBLK_CFG_NOINRANGE			BIT6	//1b/1/x/x Block Configure Cycle to PCI Bus when the Bus Number Is Not in Secondary PCI Bus Range
    #define D17F7_RMTARD_BLK_REQ			BIT5	//0/0/x/x MTARD (C2P Cycle In Turn Around State) State Blocks CCA to PCI1¡¯s Request
    #define D17F7_RCMPLFUL_BLKREQ			BIT4	//1b/1/x/x WCMPLID (Upstream Write Complete ID) Queue Full Block P2CW Request
    #define D17F7_RDISDMA_REGOUT			BIT3	//0/0/x/x Disable CCA Output to be Register Out ((Random))
    #define D17F7_RDIS_A2FHOLE			BIT2	//0/0/x/x Disable A0000h to FFFFFh Memory Hole
    #define D17F7_RNEW_FIFO_INV			BIT1	//0/0/x/x New P2CR FIFO Invalid Mechanism
    #define D17F7_RAZ2PCI			BIT0	//0/0/x/x Reserved
#define D17F7_PCI_IO_CYCLE_CTL		0x88	//PCI I/O Cycle Control
    #define D17F7_RSDIO2PCI			BIT6	//0/0/x/x Forward SDIO DMA Cycles to the External PCI Bus
    #define D17F7_RLPC2PCI			BIT5	//0/0/x/x Forward LPC DMA Cycles to the External PCI Bus
#define D17F7_PCI_IO_CYCLE_CTL_Z1		0x89	//PCI I/O Cycle Control
    #define D17F7_RNEW_QQDCKDS1			BIT7	//1b/1/x/x Reserved
    #define D17F7_RPWC_FUL_BLKREQ			BIT6	//1b/1/x/x MTXCTL PWCOUNT Full Block WREQ from MTXCTL
    #define D17F7_RSEL_SYNC_WD			BIT3	//1b/1/x/x CCA Use Sync Write Data in Test Path ((Random))
    #define D17F7_RVART2PCI			BIT2	//0/0/x/x Forward VART Mode DMA Cycles to the External PCI Bus
    #define D17F7_RESPI32PCI			BIT1	//0/0/x/x Forward eSPI Device Mode DMA Cycles to the External PCI Bus
    #define D17F7_RSPI2PCI			BIT0	//0/0/x/x Forward SPI DMA Cycles to the External PCI Bus 
#define D17F7_PCI_IO_CYCLE_CTL_Z2		0x8A	//PCI I/O Cycle Control
    #define D17F7_RX2C_SEL			BIT3	//0/0/x/x Subsystem Vendor ID and Subsystem ID selection
    #define D17F7_RUSBDH			BIT2	//0/x/x/x USB D14F7 Priority
    #define D17F7_RUSB2H			BIT1	//0/0/x/x eSPI Priority ((Random))
    #define D17F7_RUSB2SYNC			BIT0	//1b/1/x/x Synchronize eSPI REQ for Better Timing ((Random))
#define D17F7_RESERVED_Z8		0x8B	//Reserved
#define D17F7_RESERVED_Z9		0x8C	//Reserved
#define D17F7_RESERVED_Z10		0x8D	//Reserved
#define D17F7_RESERVED_Z11		0x8E	//Reserved
#define D17F7_RESERVED_Z12		0x8F	//Reserved
#define D17F7_RESERVED_Z13		0x90	//Reserved
#define D17F7_RESERVED_Z14		0x91	//Reserved
#define D17F7_RESERVED_Z15		0x92	//Reserved
#define D17F7_RESERVED_Z16		0x93	//Reserved
#define D17F7_RESERVED_Z17		0x94	//Reserved
#define D17F7_RESERVED_Z18		0x95	//Reserved
#define D17F7_HDAC_EXTENDED_CFG_ADR_SEL		0xD0	//HDAC Extended CFG Address Select
    #define D17F7_RXCFGA_35_28			0xFF	//0/x/x/x Reserved
#define D17F7_HDAC_AND_P2P_RELATED_CTL		0xD1	//HDAC and P2P Related Control
    #define D17F7_C5C6_MSI_BLK_SEL			BIT4	//0/0/x/x AZALIA (HDAC) MSI Cycle Block Select
    #define D17F7_RPEROWEN			BIT3	//0/0/x/x Reserved
    #define D17F7_RDIS_AZ			BIT2	//0/0/x/x Disable HDAC
    #define D17F7_RXCFGM			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D17F7_RESERVED_Z19		0xD2	//Reserved
#define D17F7_RESERVED_Z20		0xD3	//Reserved
#define D17F7_BACKDOOR_REG_FOR_SVID		0xD4	//Backdoor Register for Subsystem Vendor ID
    #define D17F7_BK_VENDORID_15_0			0xFFFF	//0/x/x/x Backdoor Register for Subsystem Vendor ID
#define D17F7_BACKDOOR_REG_FOR_SUBSYSTEM_ID		0xD6	//Backdoor Register for Subsystem ID
    #define D17F7_SUBSYSTEMID_BK_15_0			0xFFFF	//0/x/x/x Backdoor Register for Subsystem ID
#define D17F7_DYNAMIC_CLK_CTL_1		0xE0	//Dynamic Clock Control 1 ((CHX002 Only))
    #define D17F7_RCCA_NEWCLK			BIT7	//1b/1/1/1 CCA New Dynamic Clock Scheme Enable ((Random))
    #define D17F7_RCCA_CLKON			BIT6	//0/0/0/0 CCA Dynamic Clock On ((Random))
    #define D17F7_RGATEMLT7_3			BIT5	//0/0/x/x Reserved. Do not program.
    #define D17F7_RC3RTY			BIT4	//1b/1/x/x Reserved
    #define D17F7_EN_PCT0RDMA			BIT1	//0/x/x/x Reserved
    #define D17F7_EN_PCT0WDMA			BIT0	//1b/1/x/x Enable Output PCT0WDMA to NM
#define D17F7_DYNAMIC_CLK_CTL_2		0xE1	//Dynamic Clock Control 2 (CHX002 Only)
    #define D17F7_RFSBSZ_2_0			(BIT4 + BIT5 + BIT6)	//000b/0/x/x Frame Buffer Size for PCI1 Decode
    #define D17F7_RP2CFLUSH			BIT3	//1b/1/x/x Reserved
    #define D17F7_RBLKAPIC			BIT2	//0/0/x/x Block APIC Cycle with C3 State (C3ARBDIS1) or Lock Cycle Issued by CPU (LOCKCYC)
    #define D17F7_RAZC3			BIT1	//0/0/x/x Block HD Audio Cycle in CCA or at CCA / HD Audio Interface
#define D17F7_DYNAMIC_CLK_CTL_3		0xE2	//Dynamic Clock Control 3 ((CHX002 Only))
    #define D17F7_RDNIFCLKON			BIT4	//0/0/0/0 Downstream Interface((DNIF)) Clock Control
    #define D17F7_RPCI1DNCLKON			BIT3	//0/0/0/0 PCI1 Clock Control
    #define D17F7_RAZDNCLKON			BIT2	//0/0/0/0 Downstream HDAC Clock Control
    #define D17F7_RPSDNCLKON			BIT1	//0/0/0/0 Downstream SM Internal PCI Device ((PCIS)) Clock Control
    #define D17F7_RPCCACLKON			BIT0	//1b/x/x/x Reserved.  Do Not Program.
#define D17F7_PCI1_INTERNAL_33_66MHZ_DYNAMIC_CLK_CTL		0xE3	//PCI1 Internal 33/66MHz Dynamic Clock Control ((CHX002 Only))
    #define D17F7_RP2CRALC			BIT7	//0/0/x/x Reserved
    #define D17F7_RDYCKRDIM			BIT6	//1b/1/x/1 Improve the PCI1 Dynamic Clock
    #define D17F7_RDYCKDGNT			BIT5	//0/0/x/1 PCI1 33/66MHz Dynamic Clock Control ((Random))
    #define D17F7_RTADLATON			BIT4	//1b/1/x/x P2CR Data Timeout Enable ((Random))
    #define D17F7_RTADLATM_2_0			(BIT1 + BIT2 + BIT3)	//111b/111b/x/x P2CR Data Timer (PCI Master TRDY Timeout) ((Random))
    #define D17F7_RP2CBOFFON			BIT0	//0/0/x/x Enable P2C Read Back off ((RP2CBOFF)) Even when Only One PCI Master ((Random))
#define D17F7_LOW_TOP_ADR_LOW		0xE4	//Low Top Address - Low
    #define D17F7_RLTOP_23_20			0xF0	//0/x/x/x Reserved
    #define D17F7_RMEMUNIT_3_0			0xF	//0/x/x/x Reserved
#define D17F7_LOW_TOP_ADR_HIGH		0xE5	//Low Top Address - High
    #define D17F7_RLTOP_31_24			0xFF	//0/x/x/x Reserved 
#define D17F7_SYSTEM_MANAGEMENT_MODE_SMM_AND_APIC_DECODING		0xE6	//System Management Mode (SMM) and APIC Decoding
    #define D17F7_RAPIC2			BIT4	//0/x/x/x Reserved
    #define D17F7_RLAPICEN			BIT3	//0/x/x/x Reserved
    #define D17F7_RTSMMEN			BIT2	//0/x/x/x Reserved
    #define D17F7_RHSMMEN			BIT1	//0/x/x/x Reserved
    #define D17F7_RCSMMEN			BIT0	//1b/1/x/x Reserved
#define D17F7_CCA_DYNAMIC_CLK_DEBUG		0xE7	//CCA Dynamic Clock Debug
    #define D17F7_RP1FLUSH_NEW			BIT7	//0/0/x/x Selection of PCI1 Upstream Read Flush Mechanism
    #define D17F7_RAZ_ADDR_SEL			BIT6	//0/0/x/x Address Selection of Using Which Address to Judge Whether Current Cycle is MSI Cycle from AZ
    #define D17F7_RCCA_RCLKON			BIT5	//0/0/0/0 Upstream Read Logic Clock Enable (debug)
    #define D17F7_RCCA_WCLKON			BIT4	//0/0/0/0 Upstream Write Logic Clock Enable (debug)
    #define D17F7_RMISCCLKON			BIT3	//0/0/0/0 System Management Logic Clock Enable (debug)
    #define D17F7_RAZCLKON			BIT2	//0/0/0/0 HDAC Control Logic Clock Enable (debug)
    #define D17F7_RP1CLKON			BIT1	//0/0/0/0 PCI Control Logic Clock Enable (debug)
    #define D17F7_RSMCLKON			BIT0	//0/0/0/0 Internal Device Control Logic Clock Enable (debug)
#define D17F7_RESERVED_REG		0xF5	//Reserved Register
#define D17F7_PCCA_MODIFICATION_IN_CHX002		0xFB	//PCCA Modification in CHX002
    #define D17F7_MSI_DATA_BASE_BE			BIT1	//0/x/x/x MSI_DATA_BASE_BE
    #define D17F7_NBDBG_EN			BIT0	//0/x/x/x NBDBG_EN
#define D17F7_PCI_BUS_CTL		0xFC	//PCI Bus Control
    #define D17F7_VID_DID_LOCK			BIT7	//0/0/x/x Reserved
    #define D17F7_RCCARCLK_IDLE			BIT6	//1b/1/x/1 Enable CCA Read Clock When The State Machine of MTXCTL Is Not Idle
    #define D17F7_RSDISIRDY			BIT5	//0/0/x/x Reserved
    #define D17F7_RSDISFRM			BIT4	//0/0/x/x Reserved
    #define D17F7_RVWREQ			BIT3	//0/0/x/x Reserved
    #define D17F7_RDIDLOCK_BIT			BIT2	//0/0/x/x Reserved
    #define D17F7_ROABKDOOR			BIT1	//0/0/x/x Reserved
    #define D17F7_RBKDOOR			BIT0	//0/0/x/x Reserved
#define D17F7_PCI1_DEBUG_SIGNAL_SEL		0xFD	//PCI1 Debug Signal Select
    #define D17F7_RPCI1DBG_MODE2_3_0			0xF0	//0/0/x/x PCI Debug Signal Select ((RPCI1DBG_mode2))
    #define D17F7_RPCI1DBG_MODE1_3_0			0xF	//0/0/x/x PCI Debug Signal Select ((RPCI1DBG_mode1))
#define D17F7_DID_BACKDOOR		0xFE	//Device ID Backdoor
    #define D17F7_RBKID			0xFFFF	//0/0/x/x Device ID Back Door Value
#endif
