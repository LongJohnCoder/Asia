//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		PCIE					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from 7.xls
// CJW-20180818: IRS version:R100
#ifndef _CHX002_D3D5F1_PCIE_H
#define _CHX002_D3D5F1_PCIE_H
//(D5F1,PE7)
#define D3D5F1_VID		0x00	//Vendor ID
    #define D3D5F1_VENDORID			0xFFFF	//1106h/x/x/x Vendor ID
#define D3D5F1_DID		0x02	//Device ID
    #define D3D5F1_TBD_G3			0xFFFF	//071Eh/x/x/x Device ID
#define D3D5F1_PCI_CMD		0x04	//PCI Command
    #define D3D5F1_RSV_0			0xF800	//0/R/x/x Reserved
    #define D3D5F1_RINTDIS			BIT10	//0/0/x/x Interrupt Disable
    #define D3D5F1_RSV_1			BIT9	//0/R/x/x Fast Back-to-back Transaction Enable
    #define D3D5F1_RSERR			BIT8	//0/x/x/x SERR# Enable
    #define D3D5F1_RSV_2			BIT7	//0/R/x/x Address / Data Stepping
    #define D3D5F1_RPTYERR			BIT6	//0/0/x/x Parity Error Response
    #define D3D5F1_RSV_3			BIT5	//0/R/x/x VGA Palette Snooping
    #define D3D5F1_RX004_4			BIT4	//0/x/x/x Memory Write and Invalidate
    #define D3D5F1_RX004_3			BIT3	//0/x/x/x Response to Special Cycle
    #define D3D5F1_RMSTR			BIT2	//0/x/x/x Bus Master Enable
    #define D3D5F1_RENMEM			BIT1	//0/x/x/x Memory Space
    #define D3D5F1_RENIO			BIT0	//0/x/x/x I/O Space
#define D3D5F1_PCI_STA		0x06	//PCI Status
    #define D3D5F1_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D3D5F1_SERRS			BIT14	//0/0/x/x Signaled System Error
    #define D3D5F1_SMABORT			BIT13	//0/R/x/x Received Master Abort
    #define D3D5F1_STABORTM			BIT12	//0/R/x/x Received Target Abort
    #define D3D5F1_STABORTS			BIT11	//0/R/x/x Signaled Target Abort
    #define D3D5F1_RSV_5			(BIT9 + BIT10)	//0/R/x/x DEVSEL# Timing
    #define D3D5F1_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D3D5F1_RSV_6			BIT7	//0/R/x/x Capability of Accepting Fast Back-to-back as a Target
    #define D3D5F1_RX004_14			BIT6	//0/x/x/x User Definable Features
    #define D3D5F1_RX004_13			BIT5	//0/x/x/x 66 MHz Capable
    #define D3D5F1_RCAP			BIT4	//1b/R/x/x Capabilities List
    #define D3D5F1_SINTSTT			BIT3	//HwInit/x/x/x Interrupt Status
    #define D3D5F1_RSV_7			(BIT0 + BIT1 + BIT2)	//0/R/x/x Reserved
#define D3D5F1_REV_ID		0x08	//Revision ID
    #define D3D5F1_TBD_4			0xFF	//01h/x/x/x Revision Code
#define D3D5F1_CLASS_CODE		0x09	//Class Code
    #define D3D5F1_TBD_5_23_0			0xFFFFFF	//060400h/R/x/x Class Code
#define D3D5F1_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D3D5F1_RSV_8			0xFF	//0/x/x/x Cache Line Size
#define D3D5F1_MASTER_LATENCY_TIMER		0x0D	//Master Latency Timer
    #define D3D5F1_RSV_9			0xFF	//0/R/x/x Master Latency Timer
#define D3D5F1_HEADER_TYPE		0x0E	//Header Type
    #define D3D5F1_TBD_0E_7			0xFF	//81h/R/x/x Header Type Code
#define D3D5F1_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D3D5F1_TBD_7			0xFF	//0/R/x/x BIST Support
#define D3D5F1_LOWER_BASE_ADR		0x10	//Lower Base Address
    #define D3D5F1_TBD_8			0xFFFFFFFF	//0/R/x/x Lower Base Address
#define D3D5F1_UPPER_BASE_ADR		0x14	//Upper Base Address
    #define D3D5F1_TBD_9			0xFFFFFFFF	//0/R/x/x Upper Base Address
#define D3D5F1_PRIMARY_BUS_NUM		0x18	//Primary Bus Number
    #define D3D5F1_PBN			0xFF	//0/x/x/x Primary Bus Number
#define D3D5F1_SECONDARY_BUS_NUM		0x19	//Secondary Bus Number
    #define D3D5F1_SBN			0xFF	//0/x/x/x Secondary Bus Number
#define D3D5F1_SUBORDINATE_BUS_NUM		0x1A	//Subordinate Bus Number
    #define D3D5F1_SSBN			0xFF	//0/x/x/x Subordinate Bus Number
#define D3D5F1_SECONDARY_LATENCY_TIMER		0x1B	//Secondary Latency Timer
    #define D3D5F1_RX018_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D3D5F1_IO_BASE		0x1C	//I/O Base
    #define D3D5F1_RIOBS_15_12			0xF0	//Fh/x/x/x I/O Base (AD[15:12] - Inclusive)
    #define D3D5F1_TBD_10			0xF	//0/R/x/x I/O Addressing Capability
#define D3D5F1_IO_LIMIT		0x1D	//I/O Limit
    #define D3D5F1_RIOLM_15_12			0xF0	//0/x/x/x I/O Limit (AD[15:12] - Inclusive)
    #define D3D5F1_TBD_11			0xF	//0/R/x/x I/O Addressing Capability
#define D3D5F1_SECONDARY_STA		0x1E	//Secondary Status
    #define D3D5F1_SSPERRS			BIT15	//0/0/x/x Detected Parity Error
    #define D3D5F1_SSERRS			BIT14	//0/0/x/x Received System Error
    #define D3D5F1_SSMABORT			BIT13	//0/0/x/x Received Master Abort
    #define D3D5F1_SSTABORTM			BIT12	//0/0/x/x Received Target Abort
    #define D3D5F1_RSV_1E_5			BIT11	//0/x/x/x Signaled Target Abort
    #define D3D5F1_RX01C_26_25			(BIT9 + BIT10)	//0/x/x/x DEVSEL Timing
    #define D3D5F1_SSDPERRS			BIT8	//0/0/x/x Master Data Parity Error
    #define D3D5F1_RX01C_23			BIT7	//0/x/x/x Fast Back-to-Back Capable
    #define D3D5F1_RX01C_22			BIT6	//0/x/x/x Reserved
    #define D3D5F1_RX01C_21			BIT5	//0/x/x/x 66MHz Capability
    #define D3D5F1_RX01C_20_16			0x1F	//0/x/x/x Reserved
#define D3D5F1_MEM_BASE		0x20	//Memory Base
    #define D3D5F1_RM1BS_31_20			0xFFF0	//FFFh/x/x/x Memory Base (AD[31:20] - Inclusive)
    #define D3D5F1_RSV_11			0xF	//0/R/x/x Reserved
#define D3D5F1_MEM_LIMIT		0x22	//Memory Limit
    #define D3D5F1_RM1LM_31_20			0xFFF0	//0/x/x/x Memory Limit (AD[31:20] - Inclusive)
    #define D3D5F1_RSV_12			0xF	//0/R/x/x Reserved
#define D3D5F1_PREFETCHABLE_MEM_BASE		0x24	//Prefetchable Memory Base
    #define D3D5F1_RM2BS_31_20			0xFFF0	//FFFh/x/x/x Prefetchable Memory Base AD[31:20]
    #define D3D5F1_RSV_13			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D3D5F1_TBD_12			BIT0	//1b/R/x/x 64 Bits Addressing for Prefetchable Memory Base
#define D3D5F1_PREFETCHABLE_MEM_LIMIT		0x26	//Prefetchable Memory Limit
    #define D3D5F1_RM2LM_31_20			0xFFF0	//0/x/x/x Prefetchable Memory Limit AD[31:20]
    #define D3D5F1_RSV_14			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D3D5F1_TBD_13			BIT0	//1b/R/x/x 64 Bits Addressing for Prefetchable Memory  Limit
#define D3D5F1_PREFETCHABLE_MEM_BASE_UPPER_32_BITS		0x28	//Prefetchable Memory Base Upper 32 bits
    #define D3D5F1_RSV_15			0xFFFFFF00	//0/x/x/x Prefetchable Memory Base Upper bit[63:40]
    #define D3D5F1_RM3BS_39_32			0xFF	//0/x/x/x Prefetchable Memory Base Upper Bit[39:32]
#define D3D5F1_PREFETCHABLE_MEM_LIMIT_UPPER_32_BITS		0x2C	//Prefetchable Memory Limit Upper 32 Bits
    #define D3D5F1_RSV_16			0xFFFFFF00	//0/x/x/x Prefetchable Memory Limit Upper Bit[63:40]
    #define D3D5F1_RM3LM_39_32			0xFF	//0/x/x/x Prefetchable Memory Limit Upper Bit[39:32]
#define D3D5F1_IO_BASE_UPPER		0x30	//I/O Base Upper
    #define D3D5F1_TBD_14			0xFFFF	//0/R/x/x I/O Base Upper 16 Bits Address
#define D3D5F1_IO_LIMIT_UPPER		0x32	//I/O  Limit Upper
    #define D3D5F1_TBD_15			0xFFFF	//0/R/x/x I/O Limit Upper 16 Bits Address
#define D3D5F1_CAP_POINTER		0x34	//Capability Pointer
    #define D3D5F1_TBD_16			0xFF	//40h/40h/x/x Capability Pointer
#define D3D5F1_RESERVED		0x35	//Reserved
    #define D3D5F1_TBD_16_1			0xFFFFFF	//0/x/x/x Reserved
#define D3D5F1_INTR_LINE		0x3C	//Interrupt Line
    #define D3D5F1_RINTLN			0xFF	//0/x/x/x Interrupt Line
#define D3D5F1_INTR_PIN		0x3D	//Interrupt Pin
    #define D3D5F1_RX03C_15_11			0xF8	//0/x/x/x Reserved
    #define D3D5F1_TBD_17			(BIT0 + BIT1 + BIT2)	//010b/x/x/x Interrupt Pin
#define D3D5F1_BRIDGE_CTL		0x3E	//Bridge Control
    #define D3D5F1_RSV_17			0xF000	//0/R/x/x Reserved
    #define D3D5F1_RX03C_27			BIT11	//0/x/x/x Discard Timer SERR# Enable
    #define D3D5F1_RX03C_26			BIT10	//0/x/x/x Discard Timer Status
    #define D3D5F1_RX03C_25			BIT9	//0/x/x/x Secondary Discard Timer
    #define D3D5F1_RX03C_24			BIT8	//0/x/x/x Primary Discard Timer
    #define D3D5F1_RX03C_23			BIT7	//0/x/x/x Fast Back-to-Back Enable
    #define D3D5F1_RSRST			BIT6	//0/x/x/x Secondary Bus Reset
    #define D3D5F1_RSV_18			BIT5	//0/R/x/x Master Abort Mode
    #define D3D5F1_RVGA16			BIT4	//0/x/x/x Base VGA 16 Bits Decode
    #define D3D5F1_RVGA			BIT3	//0/x/x/x VGA Compatible I/O and Memory Address Range
    #define D3D5F1_RISA			BIT2	//0/x/x/x Block/Forward ISA I/O Cycles
    #define D3D5F1_RSERRFWD			BIT1	//0/x/x/x SERR Enable
    #define D3D5F1_RPTYERRTLP			BIT0	//0/x/x/x Parity Error Response Enable
#define D3D5F1_PCI_EXPRESS_LIST		0x40	//PCI Express List
    #define D3D5F1_TBD_24			0xFF00	//A0h/A0h/x/x Next Pointer
    #define D3D5F1_TBD_25			0xFF	//10h/10h/x/x Capability ID
#define D3D5F1_PCI_EXPRESS_CAPS		0x42	//PCI Express Capabilities
    #define D3D5F1_RSV_42_15			BIT15	//0/R/x/x Reserved
    #define D3D5F1_RTCSEN			BIT14	//0/0/x/x Reserved
    #define D3D5F1_XINTMNO			0x3E00	//0/0/x/x Interrupt Message Number
    #define D3D5F1_XSLIMP			BIT8	//1b/1/x/x Slot Implemented
    #define D3D5F1_XDPTYPE			0xF0	//0100b/0100b/x/x Device / Port Type
    #define D3D5F1_PCIE_VER_3			BIT3	//0/0/x/x Capability Version Bit 3
    #define D3D5F1_PCIE_VER_2			BIT2	//0/0/x/x Capability Version Bit 2
    #define D3D5F1_PCIE_VER_1			BIT1	//1b/x/x/x Capability Version Bit 1
    #define D3D5F1_PCIE_VER_0			BIT0	//0/x/x/x Capability Version Bit 0
#define D3D5F1_DEV_CAPS_1		0x44	//Device Capabilities 1
    #define D3D5F1_RSV_19			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define D3D5F1_TBD_27			BIT28	//0/0/x/x Function Level Reset Capability
    #define D3D5F1_RSV_20			(BIT26 + BIT27)	//0/R/x/x Captured Slot Power Limit Scale
    #define D3D5F1_RSV_21			0x3FC0000	//0/R/x/x Captured Slot Power Limit Value
    #define D3D5F1_RSV_22			(BIT16 + BIT17)	//0/R/x/x Reserved
    #define D3D5F1_RRBERRP			BIT15	//1b/1/x/x Role-based Error Reporting
    #define D3D5F1_RSV_23			BIT14	//0/R/x/x Power Indicator Present
    #define D3D5F1_RSV_24			BIT13	//0/R/x/x Attention Indicator Present
    #define D3D5F1_RSV_25			BIT12	//0/R/x/x Attention Button Present
    #define D3D5F1_DAL1AL			(BIT9 + BIT10 + BIT11)	//000b/0/x/x Endpoint L1 Acceptable Latency
    #define D3D5F1_RSV_44			(BIT6 + BIT7 + BIT8)	//0/R/x/x Endpoint L0s Acceptable Latency
    #define D3D5F1_DAXTAGF			BIT5	//0/0/x/x Extended Tag Field Supported
    #define D3D5F1_RSV_26			(BIT3 + BIT4)	//0/R/x/x Phantom Functions Supported
    #define D3D5F1_DAMPSS			(BIT0 + BIT1 + BIT2)	//001b/001b/x/x Max Payload Size Supported
#define D3D5F1_DEV_CTL_1		0x48	//Device Control 1
    #define D3D5F1_RSV_27			BIT15	//0/R/x/x Reserved
    #define D3D5F1_DCMRRS			(BIT12 + BIT13 + BIT14)	//0/R/x/x Max Read Request Size
    #define D3D5F1_DCENS			BIT11	//0/0/x/x Enable No Snoop
    #define D3D5F1_DCAPPME			BIT10	//0/x/x/x Auxiliary Power PM Enable
    #define D3D5F1_DCPFE			BIT9	//0/R/x/x Phantom Functions Enable
    #define D3D5F1_DCETFE			BIT8	//0/0/x/x Extended Tag Field Enable
    #define D3D5F1_DCMPS			(BIT5 + BIT6 + BIT7)	//0/000*/001*/x Max Payload Size
    #define D3D5F1_DCERO			BIT4	//1b/1/x/x Enable Relaxed Ordering
    #define D3D5F1_DCURRE			BIT3	//0/0/x/x Unsupported Request Reporting Enable
    #define D3D5F1_DCFERE			BIT2	//0/0/x/x Fatal Error Reporting Enable
    #define D3D5F1_DCNFERE			BIT1	//0/0/x/x Non-Fatal Error Reporting Enable
    #define D3D5F1_DCCERE			BIT0	//0/0/x/x Correctable Error Reporting Enable
#define D3D5F1_DEV_STA_1		0x4A	//Device Status 1
    #define D3D5F1_RSV_4B			0xFFC0	//0/R/x/x Reserved
    #define D3D5F1_DSTP			BIT5	//HwInit/x/x/x Transactions Pending
    #define D3D5F1_DSAPD			BIT4	//0/0/x/x AUX Power Detected
    #define D3D5F1_DSURD			BIT3	//0/0/x/x Unsupported Request Detected (TL)
    #define D3D5F1_DSFED			BIT2	//0/0/x/x Fatal Error Detected (TL)
    #define D3D5F1_DSNFED			BIT1	//0/0/x/x Non-Fatal Error Detected (TL)
    #define D3D5F1_DSCED			BIT0	//0/0/x/x Correctable Error Detected (TL)
#define D3D5F1_LINK_CAPS_1_D4F0		0x4C	//Link Capabilities 1
    #define D3D5F1_LKPN			0xFF000000	//08h/x/x/x Port Number
    #define D3D5F1_RSV_31			(BIT22 + BIT23)	//0/R/x/x Reserved
    #define D3D5F1_RLBWNTFC			BIT21	//1b/1/x/x Link Bandwidth Notification Capability
    #define D3D5F1_RDL_AR_CAP			BIT20	//1b/1/x/x Data Link Layer Link Active Reporting Capable
    #define D3D5F1_RLCASDERC			BIT19	//1b/1/x/x Surprise Down Error Reporting Capable
    #define D3D5F1_RLCACPM			BIT18	//0/R/x/x Clock Power Management
    #define D3D5F1_LKL1EL			(BIT15 + BIT16 + BIT17)	//011b/x/x/x L1 Exit Latency
    #define D3D5F1_LKL0SE			(BIT12 + BIT13 + BIT14)	//HwInit/x/x/x L0s Exit Latency
    #define D3D5F1_LKAPMS			(BIT10 + BIT11)	//0/0/0/11b Active State Link PM (ASPM) Support
    #define D3D5F1_LKMLW_5			BIT9	//0/0/x/x Maximum Link Width Bit 5
    #define D3D5F1_LKMLW_4			BIT8	//0/0/x/x Maximum Link Width Bit 4
    #define D3D5F1_LKMLW_3			BIT7	//0/0/x/x Maximum Link Width Bit 3
    #define D3D5F1_LKMLW_2			BIT6	//0/0/x/x Maximum Link Width Bit 2
    #define D3D5F1_LKMLW_1			BIT5	//0/x/x/x Maximum Link Width Bit 1
    #define D3D5F1_LKMLW_0			BIT4	//HwInit/x/x/x Maximum Link Width Bit 0
    #define D3D5F1_LKMAXLS_3			BIT3	//0/0/x/x Max Link Speed Bit 3 
    #define D3D5F1_LKMAXLS_2			BIT2	//0/0/x/x Max Link Speed Bit 2
    #define D3D5F1_LKMAXLS_1			BIT1	//HwInit/1/x/x Max Link Speed Bit 1
    #define D3D5F1_LKMAXLS_0			BIT0	//HwInit/1/x/x Max Link Speed Bit 0
#define D3D5F1_LINK_CTL_1		0x50	//Link Control 1
    #define D3D5F1_RSV_32			0xF000	//0/R/x/x Reserved
    #define D3D5F1_RLABITEN			BIT11	//0/0/x/x Enable Link Autonomous Bandwidth Interrupt
    #define D3D5F1_RLBMITEN			BIT10	//0/0/x/x Enable Link Bandwidth Management Interrupt
    #define D3D5F1_RHATNMWD			BIT9	//0/0/x/0 Hardware Autonomous Width Control
    #define D3D5F1_RLCOCPMEN			BIT8	//0/R/x/x Enable Clock Power Management
    #define D3D5F1_LCES			BIT7	//0/0/0/x Extended Synch
    #define D3D5F1_LCCCC			BIT6	//0/x/x/x Common Clock Configuration
    #define D3D5F1_LCRL			BIT5	//0/0/x/x Retrain Link
    #define D3D5F1_LCLD			BIT4	//0/0/x/x Link Disable
    #define D3D5F1_LCRCB			BIT3	//0/0/x/x Read Completion Boundary
    #define D3D5F1_RSV_33			BIT2	//0/R/x/x Reserved
    #define D3D5F1_LCAPMS			(BIT0 + BIT1)	//00b/00*/00*/11* Link Active State PM (ASPM) Control
#define D3D5F1_LINK_STA_1		0x52	//Link Status 1
    #define D3D5F1_RLATNMBW			BIT15	//0/0/x/x Link Autonomous Bandwidth Status
    #define D3D5F1_RLBWMNGT			BIT14	//0/0/x/x Link Bandwidth Management Status
    #define D3D5F1_DL_ACTIVE			BIT13	//HwInit/x/x/x Data Link Layer Link Active
    #define D3D5F1_LSSCC			BIT12	//1b/x/x/x Slot Clock Configuration
    #define D3D5F1_LSLT			BIT11	//HwInit/x/x/x Link Training
    #define D3D5F1_LSTE			BIT10	//HwInit/x/x/x Training Error
    #define D3D5F1_TBD_28			BIT9	//0/R/x/x Negotiated Link Width Bit 5
    #define D3D5F1_LSNLW			0x1F0	//HwInit/x/x/x Negotiated Link Width Bits[4:0]
    #define D3D5F1_LSLS			0xF	//HwInit/x/x/x Current Link Speed
#define D3D5F1_SLOT_CAPS_1		0x54	//Slot Capabilities 1
    #define D3D5F1_SLPSN			0xFFF80000	//0/0/x/x Physical Slot Number; Reserved
    #define D3D5F1_RSCANCCS			BIT18	//0/0/x/x No Command Completed Support
    #define D3D5F1_RSCAEMIP			BIT17	//0/0/x/x Electromechanical Interlock Present
    #define D3D5F1_RSPLS			(BIT15 + BIT16)	//0/0/x/x Slot Power Limit Scale
    #define D3D5F1_RSPLV			0x7F80	//0/0/x/x Slot Power Limit Value
    #define D3D5F1_SCHP_CAP			BIT6	//0/0/x/x Hot-Plug Capable
    #define D3D5F1_SCHPS			BIT5	//1b/1/x/x Hot-Plug Surprise
    #define D3D5F1_SCPIP			BIT4	//0/0/x/x Power Indicator Present
    #define D3D5F1_SCAIP			BIT3	//0/0/x/x Attention Indicator Present
    #define D3D5F1_RSV_36			BIT2	//0/R/x/x MRL Sensor Present
    #define D3D5F1_RSV_37			BIT1	//0/R/x/x Power Controller Present
    #define D3D5F1_SCABP			BIT0	//0/0/x/x Attention Button Present
#define D3D5F1_SLOT_CTL_1		0x58	//Slot Control 1
    #define D3D5F1_RSV_39			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define D3D5F1_RDLSCHGEN			BIT12	//0/0/x/x Enable Data Link Layer State Change
    #define D3D5F1_RSCOEMIC			BIT11	//0/R/x/x Electromechanical Interlock Control
    #define D3D5F1_SCPCC			BIT10	//0/0/x/x Power Controller Control
    #define D3D5F1_SCPIC			(BIT8 + BIT9)	//00b/0/x/x Power Indicator Control
    #define D3D5F1_SCAIC			(BIT6 + BIT7)	//00b/0/x/x Attention Indicator Control
    #define D3D5F1_SCHPIE			BIT5	//0/0/x/x Enable Hot-Plug Interrupt
    #define D3D5F1_SCCCIE			BIT4	//0/0/x/x Enable Command Completed Interrupt
    #define D3D5F1_SCPDCE			BIT3	//0/0/x/x Enable Presence Detect Change
    #define D3D5F1_RSV_40			BIT2	//0/R/x/x Enable MRL Sensor Change
    #define D3D5F1_RSV_41			BIT1	//0/R/x/x Enable Power Fault Detected
    #define D3D5F1_SCABPE			BIT0	//0/0/x/x Enable Attention Button Pressed
#define D3D5F1_SLOT_STA_1		0x5A	//Slot Status 1
    #define D3D5F1_RSV_42			0xFE00	//0/R/x/x Reserved
    #define D3D5F1_RDLSCHG			BIT8	//0/0/x/x Data Link Layer State Changed
    #define D3D5F1_RSSEMIS			BIT7	//0/R/x/x Electromechanical Interlock Status
    #define D3D5F1_SPDCST			BIT6	//HwInit/x/x/x Presence Detect State
    #define D3D5F1_RSV_43			BIT5	//0/R/x/x MRL (Manually Operated Retention Latch) Sensor State
    #define D3D5F1_SSCC			BIT4	//0/0/x/x Command Completed
    #define D3D5F1_SPDC			BIT3	//0/0/x/x Presence Detect Change
    #define D3D5F1_TBD_29			BIT2	//0/R/x/x MRL Sensor Change
    #define D3D5F1_TBD_30			BIT1	//0/R/x/x Power Fault Detected
    #define D3D5F1_SSABP			BIT0	//0/0/x/x Attention Button Pressed
#define D3D5F1_ROOT_CTL		0x5C	//Root Control
    #define D3D5F1_RSV_5C_5			0xFFE0	//0/R/x/x Reserved
    #define D3D5F1_RCCRSSVE			BIT4	//0/0/x/x Enable CRS Software Visibility
    #define D3D5F1_RCPMEIE			BIT3	//0/0/x/x Enable PME Interrupt
    #define D3D5F1_RCSEFEE			BIT2	//0/0/x/x Enable System Error on Fatal Error
    #define D3D5F1_RCSENFEE			BIT1	//0/0/x/x Enable System Error on Non-Fatal Error
    #define D3D5F1_RCSECEE			BIT0	//0/0/x/x Enable System Error on Correctable Error
#define D3D5F1_ROOT_CAPS		0x5E	//Root Capabilities
    #define D3D5F1_RSV_44_5E			0xFFFE	//0/R/x/x Reserved
    #define D3D5F1_RSCRSSFV			BIT0	//0/0/x/x Configuration Request Retry Status (CRS) Software Visibility
#define D3D5F1_ROOT_STA		0x60	//Root Status
    #define D3D5F1_RSV_45			0xFFFC0000	//0/R/x/x Reserved
    #define D3D5F1_RSPP			BIT17	//HwInit/x/x/x PME Pending
    #define D3D5F1_RSPS			BIT16	//0/0/x/x PME Status
    #define D3D5F1_RSPRID			0xFFFF	//HwInit/x/x/x PME Requester ID
#define D3D5F1_DEV_CAPS_2		0x64	//Device Capabilities 2
    #define D3D5F1_RSV_64_6			0xFFF00000	//0/R/x/x Reserved
    #define D3D5F1_ROBFFSP			(BIT18 + BIT19)	//0/0/x/x OBFF Supported
    #define D3D5F1_RSV_64_12			0x3F000	//0/R/x/x Reserved
    #define D3D5F1_RLTRSP			BIT11	//0/0/x/x LTR Mechanism Supported
    #define D3D5F1_RSV_64_10			0x7C0	//0/x/x/x Reserved
    #define D3D5F1_RARISP			BIT5	//0/0/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define D3D5F1_TBD_31			BIT4	//1b/1/x/x Completion Timeout Disable Supported
    #define D3D5F1_TBD_32			0xF	//0/R/x/x Completion Timeout Ranges Supported
#define D3D5F1_DEV_CTL_2		0x68	//Device Control 2
    #define D3D5F1_RSV_46			BIT15	//0/R/x/x Reserved
    #define D3D5F1_ROBFFEN			(BIT13 + BIT14)	//0/0/x/x OBFF Enable
    #define D3D5F1_RSV_68_11			(BIT11 + BIT12)	//0/R/x/x Reserved
    #define D3D5F1_RLTREN			BIT10	//0/0/x/x LTR Mechanism Enable
    #define D3D5F1_RSV_68_6			0x3C0	//0/R/x/x Reserved
    #define D3D5F1_RARIEN			BIT5	//0/0/x/x Enable ARI Forwarding
    #define D3D5F1_RDISCPLTM			BIT4	//0/0/0/x Completion Timeout  Disable Control
    #define D3D5F1_TBD_33			0xF	//0/R/x/x Completion Timeout Value
#define D3D5F1_DEV_STA_2		0x6A	//Device Status 2
    #define D3D5F1_RSV_47			0xFFFF	//0/R/x/x Reserved
#define D3D5F1_LINK_CAPS_2_D4F0		0x6C	//Link Capabilities 2
    #define D3D5F1_RSV_6C_31			0xFFF80000	//0/R/x/x Reserved
    #define D3D5F1_RLOW_SKP_REC_SUPPORT			(BIT16 + BIT17 + BIT18)	//000b/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D3D5F1_RSV_6C_15			0xF000	//0/R/x/x Reserved
    #define D3D5F1_RLOW_SKP_GEN_SUPPORT_2			BIT11	//HwInit/x/x/x Lower SKP OS Generation Supported Speeds Vector
    #define D3D5F1_RLOW_SKP_GEN_SUPPORT_1			BIT10	//HwInit/x/x/X Lower SKP OS Generation Supported Speeds Vector
    #define D3D5F1_RLOW_SKP_GEN_SUPPORT_0			BIT9	//1b/x/x/X Lower SKP OS Generation Supported Speeds Vector
    #define D3D5F1_RSV_6C_8			BIT8	//0/R/x/x CrossLink Supported
    #define D3D5F1_LKMLS_6			BIT7	//0b/R/x/x Supported Link Speed Vector Bit 6
    #define D3D5F1_LKMLS_5			BIT6	//0b/R/x/x Supported Link Speed Vector Bit 5
    #define D3D5F1_LKMLS_4			BIT5	//0b/R/x/x Supported Link Speed Vector Bit 4
    #define D3D5F1_LKMLS_3			BIT4	//0b/R/x/x Supported Link Speed Vector Bit 3
    #define D3D5F1_LKMLS_2			BIT3	//HwInit/1b/x/x Supported Link Speed Vector Bit 2, 8.0GT/s
    #define D3D5F1_LKMLS_1			BIT2	//HwInit/1b/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define D3D5F1_LKMLS_0			BIT1	//1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s
    #define D3D5F1_RSV_6C_0			BIT0	//0/R/x/x Reserved
#define D3D5F1_LINK_CTL_2_D4F0		0x70	//Link Control 2
    #define D3D5F1_CMPPSDEEMPHS			0xF000	//0/0/x/x Compliance Preset / De-emphasis
    #define D3D5F1_RCMPSOS			BIT11	//0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define D3D5F1_PMDCMPSET			BIT10	//0/0/x/x Modified Compliance Pattern Set Bit
    #define D3D5F1_TXMGN_2			BIT9	//0/*0/x/x Transmit Voltage Margin Setting
    #define D3D5F1_TXMGN_1			BIT8	//0/*0/x/x Transmit Voltage Margin Setting
    #define D3D5F1_TXMGN_0			BIT7	//0/*0/x/x Transmit Voltage Margin Setting
    #define D3D5F1_SELDEEMPHS			BIT6	//0/*0/x/x Selectable De-emphasis
    #define D3D5F1_RHATNMSD			BIT5	//0/0/x/0 Disable Hardware Autonomous Speed
    #define D3D5F1_PCMPSET			BIT4	//0/0/x/x Enter Compliance
    #define D3D5F1_LKTGLS_3			BIT3	//0/0/0/0 Target Link Speed Bit 3
    #define D3D5F1_LKTGLS_2			BIT2	//0/0/0/0 Target Link Speed Bit 2
    #define D3D5F1_LKTGLS_1			BIT1	//HwInit/x/1/0 Target Link Speed Bit 1
    #define D3D5F1_LKTGLS_0			BIT0	//HwInit/x/1/1 Target Link Speed Bit 0
#define D3D5F1_LINK_STA_2		0x72	//Link Status 2
    #define D3D5F1_RSV_49			0xFFC0	//0/R/x/x Reserved
    #define D3D5F1_EQREQ			BIT5	//0/x/x/x Request the Link Equalization Process
    #define D3D5F1_EQCOMPLE3			BIT4	//HwInit/x/x/x Transmitter Equalization Procedure Completed -Phase 3
    #define D3D5F1_EQCOMPLE2			BIT3	//HwInit/x/x/x Transmitter Equalization Procedure Completed -Phase 2
    #define D3D5F1_EQCOMPLE1			BIT2	//HwInit/x/x/x Transmitter Equalization Procedure Completed -Phase 1
    #define D3D5F1_EQCOMPLE			BIT1	//HwInit/x/x/x Transmitter Equalization Procedure Completed
    #define D3D5F1_CURDEEMPHS			BIT0	//HwInit/x/x/x Current Link De-emphasis Level
#define D3D5F1_SLOT_CAPS_2		0x74	//Slot Capabilities 2
    #define D3D5F1_RSV_50			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_SLOT_CTL_2		0x78	//Slot Control 2
    #define D3D5F1_RSV_51			0xFFFF	//0/R/x/x Reserved
#define D3D5F1_SLOT_STA_2		0x7A	//Slot Status 2
    #define D3D5F1_RSV_52			0xFFFF	//0/R/x/x Reserved
#define D3D5F1_VENDOR_CTL		0x7C	//Vendor Control
    #define D3D5F1_RSV_7C			0xFFFFFFFE	//0/R/x/x Reserved
    #define D3D5F1_D5F1_VID_DID_LOCK_BIT			BIT0	//0/x/x/x Reserved
#define D3D5F1_PM_CAPS		0xA0	//Power Management Capabilities
    #define D3D5F1_PMCPME			0xF8000000	//11001b/19h/x/x PME Support
    #define D3D5F1_PMCD2S			BIT26	//0/0/x/x D2 Support
    #define D3D5F1_PMCD1S			BIT25	//0/0/x/x D1 Support
    #define D3D5F1_PMCAUXC			(BIT22 + BIT23 + BIT24)	//0/0/x/x AUX Current
    #define D3D5F1_PMCDSI			BIT21	//1b/1/x/x Device Specific Initialization
    #define D3D5F1_RSV_53			(BIT19 + BIT20)	//0/R/x/x Reserved
    #define D3D5F1_TBD_34			(BIT16 + BIT17 + BIT18)	//010b/R/x/x Version
    #define D3D5F1_TBD_35			0xFF00	//B0h/R/x/x Next Capability Pointer
    #define D3D5F1_TBD_36			0xFF	//01h/R/x/x Capability ID
#define D3D5F1_PM_STA_CTL		0xA4	//Power Management Status / Control
    #define D3D5F1_TBD_37			0xFF000000	//0/R/x/x Power Management Data
    #define D3D5F1_TBD_38			BIT23	//0/x/x/x Enable Bus Power / Clock Control
    #define D3D5F1_TBD_39			BIT22	//0/x/x/x B2 / B3 Support
    #define D3D5F1_RSV_54			0x3F0000	//0/R/x/x Reserved
    #define D3D5F1_PMESD			BIT15	//0/0/x/x PME Status
    #define D3D5F1_TBD_40			(BIT13 + BIT14)	//0/R/x/x Data Scale
    #define D3D5F1_TBD_41			0x1E00	//0/R/x/x Data Select
    #define D3D5F1_PMEEN			BIT8	//0/0/x/x PME Enable
    #define D3D5F1_RSV_55			0xFC	//0/R/x/x Reserved
    #define D3D5F1_PWSD			(BIT0 + BIT1)	//00b/0/x/x Power State
#define D3D5F1_MSI_CAP_SUPPORT		0xB0	//MSI Capability Support
    #define D3D5F1_RSV_56			0xFE000000	//0/R/x/x Reserved
    #define D3D5F1_TBD_42			BIT24	//1b/1/x/x Supports Per-vector Masking Capability
    #define D3D5F1_TBD_43			BIT23	//1b/1/x/x Supports 64-bit Message Address Only
    #define D3D5F1_RMSINUM			(BIT20 + BIT21 + BIT22)	//000b/0/x/x Multiple Message Enable
    #define D3D5F1_RMSICAP			(BIT17 + BIT18 + BIT19)	//000b/0/x/x Multiple Message Capable 
    #define D3D5F1_RMSIEN			BIT16	//0/0/x/x MSI Enable
    #define D3D5F1_TBD_44			0xFF00	//E0h/R/x/x Next Capability Pointer
    #define D3D5F1_TBD_45			0xFF	//05h/R/x/x Capability ID
#define D3D5F1_SYSTEM_SPECIFIED_MSG_ADR_LOW		0xB4	//System-specified Message Address  Low
    #define D3D5F1_RMSIA_31_2			0xFFFFFFFC	//0/0/x/x System-specified Message Address Bit [31:2]
    #define D3D5F1_TBD_46			(BIT0 + BIT1)	//0/R/x/x System-specified Message Address Bit [1:0]
#define D3D5F1_SYSTEM_SPECIFIED_MSG_ADR_HIGH		0xB8	//System-specified Message Address High
    #define D3D5F1_RMSIA_63_32			0xFFFFFFFF	//0/0/x/x System-specified Message Address Bit [63:32]
#define D3D5F1_MSG_DATA		0xBC	//Message Data
    #define D3D5F1_RMSID			0xFFFF	//0/0/x/x Message Data
#define D3D5F1_RESERVED_Z1		0xBE	//Reserved
    #define D3D5F1_RSV_BFBE			0xFFFF	//0/x/x/x Reserved
#define D3D5F1_MSG_MASK_CTL		0xC0	//Message Mask Control
    #define D3D5F1_RSV_57			0xFFFFFFFE	//0/R/x/x Reserved
    #define D3D5F1_RMSIMSK			BIT0	//0/0/x/x Mask Bit for Message 0
#define D3D5F1_MSG_PENDING_STA		0xC4	//Message Pending Status
    #define D3D5F1_RSV_58			0xFFFFFFFE	//0/R/x/x Reserved
    #define D3D5F1_RMSIPDNG			BIT0	//HwInit/x/x/x Pending Bit for Message 0
#define D3D5F1_RESERVED_Z2		0xD0	//Reserved
    #define D3D5F1_RSV_D0			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_RESERVED_Z3		0xD4	//Reserved
    #define D3D5F1_RSV_D5			0xFFFFFFFF	//0/x/x/x Reserved
#define D3D5F1_NEXT_POINTER		0xE0	//Next Pointer
    #define D3D5F1_TBD_47			0xFF00	//0/R/x/x Next Pointer
    #define D3D5F1_TBD_48			0xFF	//0Dh/R/x/x Capability ID
#define D3D5F1_RESERVED_Z4		0xE2	//Reserved
    #define D3D5F1_TBD_47_1			0xFFFF	//0/R/x/x Reserved
#define D3D5F1_SVID_CTL		0xE4	//Subsystem Vendor ID Control
    #define D3D5F1_TBD_49			0xFFFF	//1106h/1106h/x/x Subsystem Vendor ID
#define D3D5F1_SUBSYSTEM_ID_CTL		0xE6	//Subsystem ID Control
    #define D3D5F1_TBD_53			0xFFFF	//071Eh/071eh/x/x Subsystem ID
#define D3D5F1_ADVANCED_ERR_REPORTING_ENHANCED_CAP_HEADER		0x100	//Advanced Error Reporting Enhanced Capability Header
    #define D3D5F1_TBD_54			0xFFF00000	//140h/R/x/x Next Capability Offset
    #define D3D5F1_TBD_55			0xF0000	//1h/R/x/x Capability Version
    #define D3D5F1_TBD_56			0xFFFF	//0001h/R/x/x PCI Express Extended Capability ID
#define D3D5F1_UNCORRECTABLE_ERR_STA		0x104	//Uncorrectable Error Status
    #define D3D5F1_RSV_59			0xFFC00000	//0/R/x/x Reserved
    #define D3D5F1_UEACSVIO			BIT21	//0/R/x/x ACS Violation Status (TL)
    #define D3D5F1_UESUR			BIT20	//0/0/x/x Unsupported Request Error Status (TL)
    #define D3D5F1_UESECRC			BIT19	//0/0/x/x ECRC Error Status (TL)
    #define D3D5F1_UESMTLP			BIT18	//0/0/x/x Malformed TLP Status (TL)
    #define D3D5F1_UESRO			BIT17	//0/0/x/x Receiver Overflow Status (TL)
    #define D3D5F1_UESUC			BIT16	//0/0/x/x Unexpected Completion Status (TL) *
    #define D3D5F1_UESCA			BIT15	//0/0/x/x Completer Abort Status (TL)
    #define D3D5F1_UESCT			BIT14	//0/0/x/x Completion Timeout Status (TL) *
    #define D3D5F1_UESFCP			BIT13	//0/0/x/x Flow Control Protocol Error Status (TL)
    #define D3D5F1_UESPTLP			BIT12	//0/0/x/x Poisoned TLP Status (TL) *
    #define D3D5F1_RSV_60			0xFC0	//0/R/x/x Reserved
    #define D3D5F1_RUESSDES			BIT5	//0/0/x/x Surprise Down Error Status
    #define D3D5F1_UESDLP			BIT4	//0/0/x/x Data Link Protocol Error Status (DLL)
    #define D3D5F1_RSV_61			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D3D5F1_UEST			BIT0	//0/0/x/x Training Error Status (PHY)
#define D3D5F1_UNCORRECTABLE_ERR_MASK		0x108	//Uncorrectable Error Mask
    #define D3D5F1_RSV_1100			0xFFC00000	//0/R/x/x Reserved
    #define D3D5F1_UEMACSVIO			BIT21	//0/R/x/x ACS Violation Mask (TL)
    #define D3D5F1_UEMUR			BIT20	//0/0/x/x Unsupported Request Error Mask (TL) *
    #define D3D5F1_UEMECRC			BIT19	//0/0/x/x ECRC Error Mask (TL)
    #define D3D5F1_UEMMTLP			BIT18	//0/0/x/x Malformed TLP Mask (TL) *
    #define D3D5F1_UEMRO			BIT17	//0/0/x/x Receiver Overflow Mask (TL) *
    #define D3D5F1_UEMUC			BIT16	//0/0/x/x Unexpected Completion Mask (TL) *
    #define D3D5F1_UEMCA			BIT15	//0/0/x/x Completed Abort Mask (TL)
    #define D3D5F1_UEMCT			BIT14	//0/0/x/x Completion Timeout Mask (TL) *
    #define D3D5F1_UEMFCP			BIT13	//0/0/x/x Flow Control Protocol Error Mask (TL) *
    #define D3D5F1_UEMPTLP			BIT12	//0/0/x/x Poisoned TLP Mask (TL) *
    #define D3D5F1_RSV_1101			0xFC0	//0/R/x/x Reserved
    #define D3D5F1_RUEMSDEM			BIT5	//0/0/x/x Surprise Down Error Mask (DLL) *
    #define D3D5F1_UEMDLP			BIT4	//0/0/x/x Data Link Protocol Error Mask (DLL) *
    #define D3D5F1_RSV_62			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D3D5F1_UEMST			BIT0	//0/0/x/x Training Error Mask (PHY) *
#define D3D5F1_UNCORRECTABLE_ERR_SEVERITY		0x10C	//Uncorrectable Error Severity
    #define D3D5F1_RSV_63			0xFFC00000	//0/R/x/x Reserved
    #define D3D5F1_USVACSVIO			BIT21	//0/R/x/x ACS Violation Severity (TL)
    #define D3D5F1_USVUR			BIT20	//0/0/x/x Unsupported Request Error Severity (TL) *
    #define D3D5F1_USVECRC			BIT19	//0/0/x/x ECRC Error Severity (TL)
    #define D3D5F1_USVMTLP			BIT18	//1b/1/x/x Malformed TLP Severity (TL) *
    #define D3D5F1_USVRO			BIT17	//1b/1/x/x Receiver Overflow Error Severity (TL) *
    #define D3D5F1_USVUC			BIT16	//0/0/x/x Unexpected Completion Error Severity (TL) *
    #define D3D5F1_USVCA			BIT15	//0/0/x/x Completed Abort Error Severity (TL)
    #define D3D5F1_USVCT			BIT14	//0/0/x/x Completion Timeout Error Severity (TL) *
    #define D3D5F1_USVFCP			BIT13	//1b/1/x/x Flow Control Protocol Error Severity (TL) *
    #define D3D5F1_USVPTLP			BIT12	//0/0/x/x Poisoned TLP Severity (TL) *
    #define D3D5F1_RSV_64			0xFC0	//0/R/x/x Reserved
    #define D3D5F1_RUSVSDES			BIT5	//1b/1/x/x Surprise Down Error Severity *
    #define D3D5F1_USVDLP			BIT4	//1b/1/x/x Data Link Protocol Error Severity (DLL) *
    #define D3D5F1_RSV_65			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D3D5F1_USVT			BIT0	//1b/1/x/x Training Error Severity (PHY) *
#define D3D5F1_CORRECTABLE_ERR_STA		0x110	//Correctable Error Status
    #define D3D5F1_RSV_66			0xFFFFC000	//0/R/x/x Reserved
    #define D3D5F1_RCESANFES			BIT13	//0/0/x/x Advisory Non-Fatal Error Status
    #define D3D5F1_CRRTT			BIT12	//0/0/x/x Replay Timer Timeout Status (DLL)
    #define D3D5F1_RSV_67			(BIT9 + BIT10 + BIT11)	//0/R/x/x Reserved
    #define D3D5F1_CRRR			BIT8	//0/0/x/x REPLAY_NUM Rollover Status (DLL)
    #define D3D5F1_CRBDLLP			BIT7	//0/0/x/x Bad Data Link Layer Packet (DLLP) Status (DLL)
    #define D3D5F1_CRBTLP			BIT6	//0/0/x/x Bad TLP Status (DLL)
    #define D3D5F1_RSV_68			0x3E	//0/R/x/x Reserved
    #define D3D5F1_CRRCVR			BIT0	//0/0/x/x Receiver Error Status (PHY)
#define D3D5F1_CORRECTABLE_ERR_MASK		0x114	//Correctable Error Mask
    #define D3D5F1_RSV_69			0xFFFFC000	//0/R/x/x Reserved
    #define D3D5F1_RCEMANFEM			BIT13	//1b/1/x/x Advisory Non-Fatal Error Mask *
    #define D3D5F1_CMRTT			BIT12	//0/0/x/x Replay Timer Timeout Mask (DLL) *
    #define D3D5F1_RSV_70			(BIT9 + BIT10 + BIT11)	//0/R/x/x Reserved
    #define D3D5F1_CMRR			BIT8	//0/0/x/x REPLAY_NUM Rollover Mask (DLL) *
    #define D3D5F1_CMBDLLP			BIT7	//0/0/x/x Bad DLLP Mask (DLL) *
    #define D3D5F1_CMBTLP			BIT6	//0/0/x/x Bad TLP Mask (DLL) *
    #define D3D5F1_RSV_71			0x3E	//0/R/x/x Reserved
    #define D3D5F1_CMRCVR			BIT0	//0/0/x/x Receiver Error Mask (PHY) *
#define D3D5F1_ADVANCED_ERR_CAPS_AND_CTL		0x118	//Advanced Error Capabilities and Control
    #define D3D5F1_RSV_72			0xFFFFFE00	//0/R/x/x Reserved
    #define D3D5F1_ECRCCHKEN			BIT8	//0/0/x/x ECRC Check Enable (TL)
    #define D3D5F1_ECRCCHKCA			BIT7	//0/R/x/x ECRC Check Capable (TL)
    #define D3D5F1_ECRCGENEN			BIT6	//0/0/x/x ECRC Generation Enable (TL)
    #define D3D5F1_ECRCGENCA			BIT5	//0/R/x/x ECRC Generation Capable (TL)
    #define D3D5F1_ECRCFEPTR			0x1F	//0/0/x/x First Error Pointer (TL)
#define D3D5F1_HEADER_LOG_1ST_DW		0x11C	//Header Log 1st DW
    #define D3D5F1_HLR1			0xFFFFFFFF	//0/R/x/x Header Log Register 1st DW
#define D3D5F1_HEADER_LOG_2ND_DW		0x120	//Header Log 2nd DW
    #define D3D5F1_HLR2			0xFFFFFFFF	//0/R/x/x Header Log Register 2nd DW
#define D3D5F1_HEADER_LOG_3RD_DW		0x124	//Header Log 3rd DW
    #define D3D5F1_HLR3			0xFFFFFFFF	//0/R/x/x Header Log Register 3rd DW
#define D3D5F1_HEADER_LOG_4TH_DW		0x128	//Header Log 4th DW
    #define D3D5F1_HLR4			0xFFFFFFFF	//0/R/x/x Header Log Register 4th DW
#define D3D5F1_ROOT_ERR_CMD		0x12C	//Root Error Command
    #define D3D5F1_RSV_73			0xFFFFFFF8	//0/R/x/x Reserved
    #define D3D5F1_RECF			BIT2	//0/0/x/x Enable Fatal Error Reporting *
    #define D3D5F1_RECNF			BIT1	//0/0/x/x Enable Non-Fatal Error Reporting *
    #define D3D5F1_RECC			BIT0	//0/0/x/x Enable Correctable Error Reporting *
#define D3D5F1_ROOT_ERR_STA		0x130	//Root Error Status
    #define D3D5F1_RESAEIMN			0xF8000000	//0/x/x/x Advanced Error Interrupt Message Number (TL)
    #define D3D5F1_RSV_74			0x7FFFF80	//0/R/x/x Reserved
    #define D3D5F1_RESFRV			BIT6	//0/0/x/x Fatal Error Messages Received (TL)
    #define D3D5F1_RESNFRV			BIT5	//0/0/x/x Non-Fatal Error Messages Received (TL)
    #define D3D5F1_RESFFRV			BIT4	//0/0/x/x First Uncorrectable Fatal Error Message Received (TL)
    #define D3D5F1_RESMF			BIT3	//0/0/x/x Multiple ERR_FATAL/NONFATAL Received (TL)
    #define D3D5F1_RESSF			BIT2	//0/0/x/x ERR_FATAL/NONFATAL Received (TL)
    #define D3D5F1_RESMC			BIT1	//0/0/x/x Multiple ERR_COR Received (TL)
    #define D3D5F1_RESSC			BIT0	//0/0/x/x ERR_COR Received (TL)
#define D3D5F1_ERR_SRC_IDENTIFICATION		0x134	//Error Source Identification
    #define D3D5F1_ESIF			0xFFFF0000	//0/R/x/x ERR_FATAL / NONFATAL Source Identification (TL)
    #define D3D5F1_ESIC			0xFFFF	//0/R/x/x ERR_COR Source Identification (TL)
#define D3D5F1_ERR_DLLP_LOG		0x138	//Error DLLP Log
    #define D3D5F1_DL_ERR_DLLP			0xFFFFFFFF	//0/R/x/x Error DLLP Log
#define D3D5F1_VIRTUAL_CHN_ENHANCED_CAP		0x140	//Virtual Channel Enhanced Capability
    #define D3D5F1_RX140_31_20			0xFFF00000	//170h/R/x/x Next Capability Offset
    #define D3D5F1_RX140_19_16			0xF0000	//1h/R/x/x Capability Version
    #define D3D5F1_RX140_15_0			0xFFFF	//0002h/R/x/x PCI Express Extended Capability ID
#define D3D5F1_PORT_VC_CAP_1		0x144	//Port VC Capability 1
    #define D3D5F1_RX144_31_12			0xFFFFF000	//0/x/x/x Reserved
    #define D3D5F1_RX144_11_10			(BIT10 + BIT11)	//0/R/x/x Port Arbitration Table Entry Size
    #define D3D5F1_RX144_9_8			(BIT8 + BIT9)	//0/R/x/x Reference Clock
    #define D3D5F1_RX144_7			BIT7	//0/x/x/x Reserved
    #define D3D5F1_VCALPEC_2_0			(BIT4 + BIT5 + BIT6)	//0/R/x/x Low Priority Extended VC Count
    #define D3D5F1_RX144_3			BIT3	//0/x/x/x Reserved
    #define D3D5F1_VCAEVCC_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x Extended VC Count
#define D3D5F1_PORT_VC_CAP_2		0x148	//Port VC Capability 2
    #define D3D5F1_RX148_31_24			0xFF000000	//00h/R/x/x VC Arbitration Table Offset
    #define D3D5F1_RX148_23_8			0xFFFF00	//0/x/x/x Reserved
    #define D3D5F1_RX148_7_0			0xFF	//0/R/x/x VC Arbitration Capability
#define D3D5F1_PORT_VC_CTL		0x14C	//Port VC Control
    #define D3D5F1_RX14C_15_4			0xFFF0	//0/x/x/x Reserved
    #define D3D5F1_RX14C_3_1			(BIT1 + BIT2 + BIT3)	//0/0/x/x VC Arbitration Select
    #define D3D5F1_RX14C_0			BIT0	//0/R/x/x Load VC Arbitration Table
#define D3D5F1_PORT_VC_STA		0x14E	//Port VC Status
    #define D3D5F1_RX14C_31_17			0xFFFE	//0/x/x/x Reserved
    #define D3D5F1_RX14C_16			BIT0	//0/R/x/x VC Arbitration Table Status
#define D3D5F1_VC0_RESRC_CAP		0x150	//VC0 Resource Capability
    #define D3D5F1_RX150_31_24			0xFF000000	//00h/R/x/x Port Arbitration Table Offset (VC0)
    #define D3D5F1_RX150_23			BIT23	//0/x/x/x Reserved
    #define D3D5F1_VCRAMTS0_6_0			0x7F0000	//0/R/x/x Maximum Time Slots (TL)
    #define D3D5F1_VCRARST0			BIT15	//0/R/x/x Reject Snoop Transactions
    #define D3D5F1_RX150_14			BIT14	//0/R/x/x Undefined
    #define D3D5F1_RX150_13_8			0x3F00	//0/x/x/x Reserved
    #define D3D5F1_RX150_7_0			0xFF	//0/R/x/x Port Arbitration Capability
#define D3D5F1_VC0_RESRC_CTL		0x154	//VC0 Resource Control
    #define D3D5F1_VCROEN0			BIT31	//1b/R/x/x VC Enable
    #define D3D5F1_RX154_30_27			0x78000000	//0/x/x/x Reserved
    #define D3D5F1_VCROID0_2_0			(BIT24 + BIT25 + BIT26)	//0/R/x/x VC ID
    #define D3D5F1_RX154_23_20			0xF00000	//0/x/x/x Reserved
    #define D3D5F1_RX154_19_17			(BIT17 + BIT18 + BIT19)	//0/0/x/x Port Arbitration Select
    #define D3D5F1_RX154_16			BIT16	//0/R/x/x Load Port Arbitration Table
    #define D3D5F1_RX154_15_8			0xFF00	//0/x/x/x Reserved
    #define D3D5F1_VCROMAP0_7_1			0xFE	//7Fh/7Fh/7Fh/7Fh TC1/TC2/TC3/TC4/TC5/TC6/TC7 Mapping to VC0
    #define D3D5F1_VCROMAP0_0			BIT0	//1b/R/x/x TC0 Mapping to VC0
#define D3D5F1_VC0_RESRC_STA		0x158	//VC0 Resource Status
    #define D3D5F1_RX158_31_18			0xFFFC0000	//0/R/x/x Reserved
    #define D3D5F1_VCRSNP0			BIT17	//HwInit/x/x/x VC Negotiation Pending (TL)
    #define D3D5F1_RX158_16			BIT16	//0/R/x/x Port Arbitration Table Status
    #define D3D5F1_RX158_15_0			0xFFFF	//0/x/x/x Reserved
#define D3D5F1_ROOT_COMPLEX_LINK_DECLARATION_CAPS_HEADER		0x170	//Root Complex Link Declaration Capabilities Header
    #define D3D5F1_RX170_31_20			0xFFF00000	//2A0h/R/x/x Next Capability Offset
    #define D3D5F1_RX170_19_16			0xF0000	//1h/R/x/x Capability Version
    #define D3D5F1_RX170_15_0			0xFFFF	//0005h/R/x/x PCI Express Extended Capability ID
#define D3D5F1_ELEMENT_SELF_DESCRIPTION		0x174	//Element Self Description
    #define D3D5F1_RX174_31_24			0xFF000000	//08h/08h/x/x Port Number (Root Port Graphics)
    #define D3D5F1_RX174_23_16			0xFF0000	//01h/01h/x/x Component ID
    #define D3D5F1_RX174_15_8			0xFF00	//01h/01h/x/x Number of Link Entries
    #define D3D5F1_RX174_7_4			0xF0	//0/x/x/x Reserved
    #define D3D5F1_RX174_3_0			0xF	//0/R/x/x Element Type
#define D3D5F1_UPSTREAM_LINK_DESCRIPTOR		0x180	//Upstream Link Descriptor
    #define D3D5F1_RX180_31_24			0xFF000000	//00h/00h/x/x Target Port Number
    #define D3D5F1_RX180_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define D3D5F1_RX180_15_3			0xFFF8	//0/0/x/x Reserved
    #define D3D5F1_RX180_2			BIT2	//0/0/x/x Associate RCRB Header
    #define D3D5F1_RX180_1			BIT1	//0/0/x/x Link Type
    #define D3D5F1_RX180_0			BIT0	//1b/1/x/x Link Valid
#define D3D5F1_UPSTREAM_LINK_LOWER_BASE_ADR_FOR_RCRB_H_63_12		0x188	//Upstream Link Lower Base Address for RCRB-H[63:12]
    #define D3D5F1_RXRCRBHA_31_12			0xFFFFF000	//HwInit/x/x/x Lower Link Address - Bit[31:12]
    #define D3D5F1_RX188_11_0			0xFFF	//0h/x/x/x Lower Link Address - Bit[11:0]
#define D3D5F1_UPSTREAM_LINK_UPPER_BASE_ADR_FOR_RCRB_H_63_12		0x18C	//Upstream Link Upper Base Address for RCRB-H[63:12]
    #define D3D5F1_RX18C_31_4			0xFFFFFF00	//0/x/x/x Upper Link Address - Bit[63:40]
    #define D3D5F1_RXRCRBHA_39_32			0xFF	//HwInit/x/x/x Upper Link Address - Bit[39:32]
#define D3D5F1_DOWNSTREAM_CTL_1		0x1A0	//Downstream Control 1
    #define D3D5F1_RDNTC1			BIT7	//0/0/x/x Downstream Cycles Have Traffic Class TC1
    #define D3D5F1_RDNNS			BIT6	//0/0/x/x Downstream Cycles Have Attribute ¡°No Snoop¡± Set
    #define D3D5F1_RDNRO			BIT5	//0/0/x/x Downstream Cycles Have Attribute ¡°Relaxed Ordering¡± Set
    #define D3D5F1_RLOCK			BIT4	//1b/1b/1b/1b Downstream Lock Cycle Support
    #define D3D5F1_RDNRRA			BIT3	//0/0/0/x Downstream Arbitration Scheme
    #define D3D5F1_RDISTRDY			BIT2	//0/0/0/x SBDBG Mode Trdy Mask Disable
    #define D3D5F1_RDISRTY			BIT1	//0/0/0/x SBDBG Mode Retry Buffur Disenable
    #define D3D5F1_RPIPE			BIT0	//1b/1b/1b/x Downstream Pipeline
#define D3D5F1_DOWNSTREAM_CTL_2		0x1A1	//Downstream Control 2
    #define D3D5F1_RCRS			BIT7	//0/x/x/x Downstream Configuration Completion Status
    #define D3D5F1_RX1A1_6			BIT6	//0/0/x/x Reserved
    #define D3D5F1_RDNCPLINFC			BIT5	//0/0/x/x For the Data Return of Upstream Read Requests
    #define D3D5F1_RPOFFINFC			BIT4	//1b/1/1/x Disable Downstream PH Credit Check for PME_TURN_OFF Message
    #define D3D5F1_RCPRTMTST			BIT3	//0/0/x/x Enable ¡°C2P Read Completion Timer for Vector Development Mode¡±
    #define D3D5F1_RCPRTM			(BIT0 + BIT1 + BIT2)	//010b/010b/010b/x C2P Read Completion Timeout Timer
#define D3D5F1_DOWNSTREAM_CTL_3		0x1A2	//Downstream Control 3
    #define D3D5F1_RTRANS2TFIX			BIT7	//1b/1/*0/x Downstream Ordering Queue Timing Option
    #define D3D5F1_RPDNARBTIM			(BIT4 + BIT5 + BIT6)	//011b/011b/011b/x Waiting Time for GNT Timer in Priority Arbitration Mode
    #define D3D5F1_RFASTRO			BIT3	//0/0/1/x Enable Fast Reorder
    #define D3D5F1_RNPBLKL1			BIT2	//1b/1/0/0 Pending C2P NP Completion Cycle to Block L1 Entry
    #define D3D5F1_RPDNARB			(BIT0 + BIT1)	//00b/0/0/x Downstream Arbitration Parking
#define D3D5F1_DOWNSTREAM_CTL_4		0x1A3	//Downstream Control 4
    #define D3D5F1_RRTYQSIZE_3_0			0xF0	//0111b/0111b/0111b/x Retry Buffer Level
    #define D3D5F1_RRTYTMO			BIT3	//1b/1/x/x Downstream Read Retry Time Out Control in DL_Down State
    #define D3D5F1_RX1A3_2_1			(BIT1 + BIT2)	//0/x/x/x Reserved
    #define D3D5F1_RRTYNPRD			BIT0	//0/0/x/x Downstream Read Cycle Retry
#define D3D5F1_UPSTREAM_CTL		0x1A4	//Upstream Control
    #define D3D5F1_RUHIA0			BIT7	//0/0/0/0 Upstream Address A39-A31 Forced to 0
    #define D3D5F1_RRADSW4RDY			BIT6	//1b/1/0/x Upstream Read Wait till Upstream Write Data Send Out
    #define D3D5F1_RMALTLP			BIT5	//0/0/0/x Upstream Checking Malformed TLP through ¡°Byte Enable Rule¡± and ¡°Over 4K Boundary Rule¡±
    #define D3D5F1_RPWFLSH			BIT4	//1b/1/1/1 Downstream Read Wait till the Upstream Write Flushed
    #define D3D5F1_RINFFC			BIT3	//1b/1/1/x Infinite Flow Control
    #define D3D5F1_RPTLPUR			BIT2	//0/0/0/0 Report Poison TLP as Uncorrectable Error
    #define D3D5F1_RNSVC1			BIT1	//0/0/1/x Reserved
    #define D3D5F1_RRASW4RDY			BIT0	//0/0/x/x Reserved
#define D3D5F1_CREDIT_ADVERTISEMENT_CTL_1		0x1A5	//Credit Advertisement Control 1
    #define D3D5F1_RPDCREDIT_3_0			0xF0	//0111b/0111b/0111b/x Upstream Posted (Write) Data FIFO Size and the Initial PD Credit Value
    #define D3D5F1_RPHCREDIT_3_0			0xF	//0011b/0011b/0011b/x Upstream PH Header Queues Size and the Initial PH Credit
#define D3D5F1_CREDIT_ADVERTISEMENT_CTL_2		0x1A6	//Credit Advertisement Control 2
    #define D3D5F1_RNPHCDINF			BIT7	//0/0/0/x Upstream Non-Posted Header Credit Infinite Mode Control
    #define D3D5F1_RX1A4_22_20			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define D3D5F1_RNPHCREDIT_3_0			0xF	//0011b/0011b/0011b/x Upstream Non-Posted Request Queue Size and Initial NPH Credit Value
#define D3D5F1_UPSTREAM_PERFORMANCE_CTL_1		0x1A7	//Upstream Performance Control 1(D3F0,D3F1,D3F2,D3F3,D4F0,D4F1,D5F0,D5F1)
    #define D3D5F1_RDISCRDCALF			BIT7	//0/0/x/x Disable FCU Calculate Gating
    #define D3D5F1_RRFFPOPEARLY_X4			BIT6	//0/0/x/x Upstream Read FIFO Entry Release Timing For X4
    #define D3D5F1_RRFFPOPEARLY_X2X1			BIT5	//0/0/x/x Upstream Read FIFO Entry Release Timing For X2X1
    #define D3D5F1_RRFFPOPEARLY			BIT4	//0/0/0/x Upstream Read FIFO Entry Release Timing
    #define D3D5F1_RCPLW4RDY			BIT3	//1b/1/1/1 Downstream Read Data Wait for Previous Upstream Write Complete
    #define D3D5F1_RUPINORDER			BIT2	//1b/1/1/x No-Snoop Path Upstream Request Read and Write Orders
    #define D3D5F1_RX1A7_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D3D5F1_COMPLETION_TIMEOUT_CTL		0x1A8	//Completion Timeout Control
    #define D3D5F1_RPHYRSTMER			BIT7	//0/0/x/x C2P Completion Timeout Method When PHY Retrains or Configures
    #define D3D5F1_RX1A8_6			BIT6	//0/x/x/x Reserved
    #define D3D5F1_RCFGRTYTIM			(BIT4 + BIT5)	//00b/0/0/x Downstream Configuration Retry Request Timing after Receiving CRS Completion
    #define D3D5F1_RX1A8_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D3D5F1_RCFGTM			(BIT0 + BIT1)	//01b/01b/01b/x Configuration Request Timeout Timer
#define D3D5F1_CRS_RETRY_CTL		0x1A9	//CRS Retry Control
    #define D3D5F1_RX1A9_7_1			0xFE	//0/0/x/x Reserved
    #define D3D5F1_RRTYCRSEN			BIT0	//0/0/0/x Enable CRS Retry Mechanism
#define D3D5F1_UPSTREAM_PERFORMANCE_CTL_2		0x1AA	//Upstream Performance Control 2
    #define D3D5F1_RX1AA_7			BIT7	//0/0/x/x Reserved
    #define D3D5F1_RPHFCUEN			BIT6	//1b/1/x/1 UpdateFC-P Generation to the Endpoint for Upstream Write TLPs 
    #define D3D5F1_RX1AA_5_4			BIT5	//0/0/x/x Reserved
    #define D3D5F1_RTANBYPASS			BIT4	//1b/1/*0/x TA Path Enable
    #define D3D5F1_RRTYQEMPNB			(BIT2 + BIT3)	//00b/0/0/x Number of TLPs in Retry Buffer Header Queue for the Condition of Retry Buffer Header Queue Almost Empty
    #define D3D5F1_RCPL2MERGE			BIT1	//0/0/0/x The 1st and 2nd Completion Merge Control for PCI-to-CPU Read (P2CR)
    #define D3D5F1_RMSI_MULV			BIT0	//0/0/0/0 Multi-vector MSI Data Support
#define D3D5F1_TRANS_BACKUP_REGS		0x1AB	//TRANS Backup Registers
    #define D3D5F1_RBAK_DLRXACT			BIT7	//0/0/0/0 Backup UPECLK2X¡¯s Behavior to Original Design in PEXC 
    #define D3D5F1_RBAK_MSG_NA			BIT6	//0/0/0/0 Bug Fixing
    #define D3D5F1_RDIS_MESC_WK			BIT5	//0/0/0/0 PCIE Wakeup C4P Control
    #define D3D5F1_RUPCPL_DWPTR_RST			BIT4	//0/0/0/0 UP CPL Backup for Link Downstream
    #define D3D5F1_TRANS_RSV_REG_1_3_0			0xF	//0/0/0/0 TRANS Reserve Registers
#define D3D5F1_TRANS_RTA_REGS		0x1AC	//TRANS RTA Registers
    #define D3D5F1_RX1AD_7_5			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D3D5F1_RTACACHEINV			BIT5	//0/0/0/0 TRANS Cache Invalid
    #define D3D5F1_RTA_PFEN			BIT4	//0/0/0/0 TRANS RTA Prefetch Enable Registers
    #define D3D5F1_RTA_PFCNT			(BIT2 + BIT3)	//0/0/0/0 TRANS RTA PFTCNT Registers
    #define D3D5F1_RTA_PFTRIG			(BIT0 + BIT1)	//0/0/0/0 TRANS RTA PFTRIG Registers
#define D3D5F1_TRANS_ISO_REGS_1		0x1AD	//TRANS ISO Registers 1
    #define D3D5F1_RISOBNB			0xFF	//00000111b/00000111b/0/0 TRANS ISO BUS NUMBER Register
#define D3D5F1_TRANS_ISO_REG_2		0x1AE	//TRANS ISO Register 2
    #define D3D5F1_RP2CMSIFLUSHUPW			BIT7	//0/0/0/0 TRANS UPW MSI Flush P2CW CPL Control Register
    #define D3D5F1_RMSGCMSIFLUSHUPW			BIT6	//0/0/0/0 TRANS MSGC MSI Flush P2CW CPL Control Register
    #define D3D5F1_RCRSWPTRADD			BIT5	//1b/1b/1b/1b TRANS CRS Cpl Downstream Read Data FIFO Wptr Add Control Register
    #define D3D5F1_RNPNCDC			BIT4	//0/0/0/0 TRANS Downstream Non-post  Read Request Check Upstream Data Credit Control Register
    #define D3D5F1_RISOEN			BIT3	//0/0/0/0 TRANS ISO Enable Register
    #define D3D5F1_RISOTC			(BIT0 + BIT1 + BIT2)	//111b/111b/0/0 TRANS ISO TC Register
#define D3D5F1_MSG_PENDING_STA_Z1		0x1AF	//Message Pending Status
    #define D3D5F1_RSV_1AF			0xFF	//0/R/x/x Reserved
#define D3D5F1_UNRELIABLE_LINK_MANAGEMENT		0x1B0	//Unreliable Link Management
    #define D3D5F1_RUNRLCLR			BIT7	//0/0/x/x Reserved
    #define D3D5F1_RSPDUNRL			BIT6	//1b/1/1/x Priority Control When the Link is Unstable
    #define D3D5F1_RTLPRSCNT			(BIT4 + BIT5)	//00b/00b/00b/x Limitation of Transmitter Replays the TLP with the Same Sequence Number
    #define D3D5F1_RRXNAKCNT			(BIT2 + BIT3)	//00b/00b/00b/x Limitation of Receiver Receives the TLP with the Same Sequence Number and LCRC Error or All the TLP in Device¡¯s Retry Buffer Have Been Replayed with LCRC ERROR
    #define D3D5F1_RUNRLEN_RX			BIT1	//0/0/1/x Enable Receiver Link Unreliable Detection
    #define D3D5F1_RUNRLEN_TX			BIT0	//0/0/1/x Enable Transmitter Link Unreliable Detection
#define D3D5F1_REPLAY_TIMER_LIMIT		0x1B1	//Replay Timer Limit
    #define D3D5F1_RSV_1B1			0xFE	//0/0/x/x Reserved
    #define D3D5F1_RL0SRPLCNT			BIT0	//0/0/1/x Replay Timer of DLLM Will Count When PHYLS Status Is  in L0s State
#define D3D5F1_FLOW_CTL_INIT_FCI_FLOW_CTL_UNIT_FCU_CTL_AND_STA		0x1B2	//Flow Control Initialization (FCI) / Flow Control Unit (FCU) Control and Status
    #define D3D5F1_RFRTMDERR			BIT7	//0/0/x/x FCI / FCU Timeout Status
    #define D3D5F1_RFRTMEN			BIT6	//1b/1/1/x FCI / FCU Receive Timer Enable
    #define D3D5F1_RFRTMLM			BIT5	//0/0/0/x FCI / FCU Receive Timer Limit
    #define D3D5F1_RFRTMDLP			BIT4	//0/0/1/x FCI / FCU Receive Timer Reset Control
    #define D3D5F1_RSV_119			(BIT2 + BIT3)	//0/0/x/x Reserved
    #define D3D5F1_RASL1TMFCI			BIT1	//1b/1/x/x FCI Finish with DL_ASL1 Control
    #define D3D5F1_RDLFCUDMCLK			BIT0	//0/0/1/1 FCU Dynamic Clock Stop Function Control
#define D3D5F1_REPLAY_TIMER_CTL		0x1B3	//Replay Timer Control
    #define D3D5F1_RRTCTL			(BIT6 + BIT7)	//10b/10b/10b/x Replay Timer Control While Rewind
    #define D3D5F1_RSV_120			(BIT3 + BIT4 + BIT5)	//0/0/x/x Reserved
    #define D3D5F1_RNREVLD			(BIT0 + BIT1 + BIT2)	//011b/011b/000b/x Count of Replay Timer Expired during RxL0s (Receiver in L0s State) Before Resending the TLP
#define D3D5F1_ARBITRATION_CTL		0x1B4	//Arbitration Control
    #define D3D5F1_RSV_121			0xF8	//0/0/x/x Reserved
    #define D3D5F1_RDLARB			(BIT0 + BIT1 + BIT2)	//000b/000b/111b/x Data Link TX Packets Arbitration Scheme
#define D3D5F1_FCU_CTL		0x1B5	//FCU Control
    #define D3D5F1_RSV_122			BIT7	//0/0/x/x Reserved
    #define D3D5F1_RFCUCTL			BIT6	//0/0/0/x FCU Timer Control
    #define D3D5F1_RACKCLPS			(BIT4 + BIT5)	//01b/01b/01b/x ACK Minimum Latency Control
    #define D3D5F1_RSV_123			(BIT2 + BIT3)	//0/0/x/x Reserved
    #define D3D5F1_RFCIENDC			BIT1	//0/0/0/x FCI Process End Condition
    #define D3D5F1_RFCIFREQ			BIT0	//0/0/0/x VC1 FCI Data Link Layer Packet (DLLP) Transmission Scheme
#define D3D5F1_TRANSACTION_LINK_LAYER_CHECKING_CTL		0x1B6	//Transaction / Link Layer Checking Control
    #define D3D5F1_RNAKFLGEN			BIT7	//0/0/0/x Nak_Scheduled Flag Control
    #define D3D5F1_RRCVTLTM			(BIT5 + BIT6)	//01b/01b/01b/x TLP Receiving Timer
    #define D3D5F1_RFASTHPOP			BIT4	//0/0/0/0 The First Downstream TLP Is Popped Out from TL 1T Earlier
    #define D3D5F1_RDISPMCACKRST			BIT3	//1b/1/x/x Enable the Receive Buffer Controller ((RXBCTL)) Reset Scheme When PM_Request_Ack DLLP Sequences Are Generated
    #define D3D5F1_RSV_124			(BIT1 + BIT2)	//0/0/x/x Reserved
    #define D3D5F1_RLCRCCHK			BIT0	//1b/1/1/x LCRC Check Control
#define D3D5F1_FCU_CTL_Z1		0x1B7	//FCU Control
    #define D3D5F1_RSV_125			0xF0	//0/0/x/x Reserved
    #define D3D5F1_RPFCUCTL			(BIT2 + BIT3)	//00b/00b/10b/x Update FCU According to TRANS FIFO Status
    #define D3D5F1_RNFCUCTL			(BIT0 + BIT1)	//00b/00b/11b/x Update FCU According to TRANS FIFO Status
#define D3D5F1_DATA_LINK_LAYER_HEADER_POSITION		0x1B8	//Data Link Layer Header Position
    #define D3D5F1_RSV_126			0xFE	//0/0/x/x Reserved
    #define D3D5F1_RSDPLN0			BIT0	//0/0/0/x Data Link Layer Header Position
#define D3D5F1_RESERVED_Z5		0x1B9	//Reserved
    #define D3D5F1_RSV_126_1			0xFC	//0/x/x/x Reserved
    #define D3D5F1_RENDINVD			BIT1	//0/0/x/x When Receive TLP with THD but Miss END, Invalde this Cycle
    #define D3D5F1_RTHDINVD			BIT0	//1b/1/x/x When Two DHD/THD before END, Invalde the Second DHD/THD
#define D3D5F1_RESERVED_Z6		0x1BA	//Reserved
    #define D3D5F1_RSV_1BA			0xFF	//0/0/x/x Reserved
#define D3D5F1_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X8_X4		0x1BB	//Ack / Nak Latency Timer Limit for X8 / X4
    #define D3D5F1_RACKLTLM_M			0xFF	//12h/12h/12h/x Timer Limit for Ack / Nak Latency Timer and Update FC Latency Timer (in unit of 250MHz) for X8 / X4
#define D3D5F1_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X2_X1		0x1BC	//Ack / Nak Latency Timer Limit for X2 / X1
    #define D3D5F1_RACKLTLM_S			0xFF	//3Bh/3Bh/3Bh/x Timer Limit for Ack / Nak Latency Timer and Update FC Latency Timer (in unit of 250MHz) for X2 / X1
#define D3D5F1_RESERVED_Z7		0x1BD	//Reserved
    #define D3D5F1_RSV_1BD			0xFF	//0/0/x/x Reserved
#define D3D5F1_REPLAY_TIMER_LIMIT_FOR_X8_X4		0x1BE	//Replay Timer Limit for X8 / X4
    #define D3D5F1_RRPLYTM_M			0xFF	//3Fh/3fh/3fh/x Replay Timer Limit  for X8 / X4 (in unit of 250MHz)
#define D3D5F1_REPLAY_TIMER_LIMIT_FOR_X2_X1		0x1BF	//Replay Timer Limit for X2 / X1
    #define D3D5F1_RRPLYTM_S			0xFF	//AFh/afh/afh/x Replay Timer Limit  for X2 / X1 (in unit of 250MHz)
#define D3D5F1_GENERAL_CTL_1		0x1C0	//General Control 1
    #define D3D5F1_QKTMOUT			BIT7	//0/0/x/x Quick Timeout Counter Setting
    #define D3D5F1_DIS_SCRMBL			BIT6	//0/0/x/x Disable Data Scrambling / Descrambling
    #define D3D5F1_LPBK_SEL			(BIT3 + BIT4 + BIT5)	//000b/0/x/x Loopback Mode Selection
    #define D3D5F1_COMDET_WINDOW			(BIT0 + BIT1 + BIT2)	//011b/011b/x/x COMMA Detection Window
#define D3D5F1_GENERAL_CTL_2		0x1C1	//General Control 2
    #define D3D5F1_RSV_1C1_7			BIT7	//0/0/x/x Reserved
    #define D3D5F1_RHATNMWE			BIT6	//0/0/x/x Reserved
    #define D3D5F1_RHATNMSE			BIT5	//1b/1/x/x Reserved
    #define D3D5F1_SKPNEGO			0x1F	//00000b/0/x/x PHY Lane Configuration Setting
#define D3D5F1_MAC_AND_PCS		0x1C2	//MAC and PCS
    #define D3D5F1_REBRSTEN			BIT7	//1b/1/x/x Enable Reset of Elastic Buffer When Rx1C3 (PHYLS_STATE) Is in the State of No Need to Transferring Data
    #define D3D5F1_RSTRXEB			BIT6	//0/0/x/x Reset Elastic Buffer
    #define D3D5F1_RLNRDTOEN			BIT5	//0/x/x/x Reserved
    #define D3D5F1_RCVDOUT_SET			BIT4	//0/0/x/x Bypass PHYES Device Detection in Detect Phase of LTSSM
    #define D3D5F1_RPOLL24MS			BIT3	//0/0/x/x State Machine LTSSM Exit Polling.Active
    #define D3D5F1_RIGNIDL			BIT2	//1b/1/x/x Wait IDL Ordered Set or Electrical Idle When L1/L23 Entry
    #define D3D5F1_RRDCHKEN			BIT1	//1b/1/x/x Enable Disparity Check
    #define D3D5F1_RDET12MS			BIT0	//1b/1/x/x State Machine ¡°Link Training and Status State Machine (LTSSM)¡± Control 
#define D3D5F1_PHYLS_LTSSM_STATE		0x1C3	//PHYLS LTSSM State
    #define D3D5F1_PHYLS_STATE			0xFF	//HwInit/x/x/x PHYLS LTSSM State
#define D3D5F1_ELASTIC_BUFFER_BASE_REGS		0x1C4	//Elastic Buffer Base Registers
    #define D3D5F1_RSV_1C4_7			0xF8	//0/0/x/x Reserved
    #define D3D5F1_EB_BASE			(BIT0 + BIT1 + BIT2)	//110b/110b/x/x Elastic Buffer Base Register 
#define D3D5F1_RESERVED_Z8		0x1C5	//Reserved
    #define D3D5F1_TBD_1C5			0xFF	//0/R/x/x Reserved
#define D3D5F1_RESERVED_Z9		0x1C6	//Reserved
    #define D3D5F1_TBD_1C6			0xFF	//0/R/x/x Reserved
#define D3D5F1_RESERVED_Z10		0x1C7	//Reserved
    #define D3D5F1_TBD_1C7			0xFF	//0/R/x/x Reserved
#define D3D5F1_SKP_ORDERED_SET_CTL		0x1C8	//SKP Ordered Set Control
    #define D3D5F1_RDEVDISCRMEN			BIT7	//0/0/x/x It is Used to Enable Device Issuing Disable Scrambling Capability
    #define D3D5F1_R64TS2SEND			BIT6	//0/0/x/x TS2 Send Control during Speed Change
    #define D3D5F1_RSPEEDWAIT			BIT5	//0/0/x/x Wait EIOS before Change State from Recovery_RcvrCfg to Recovery_Speed
    #define D3D5F1_RDSKWERREN			BIT4	//0/0/x/x Deskew Error Report Enable
    #define D3D5F1_RDISRCVR			BIT3	//1b/1/x/x Disable Receiver Error Report
    #define D3D5F1_RFIXSCRMBLDIS			BIT2	//0/0/x/x Link Scramble Disable Bit Sampled Control
    #define D3D5F1_R1530SKP			BIT1	//0/0/x/x Enable SKP Ordered-Set Scheduling of 4.72us or 6.12us
    #define D3D5F1_R118SKP			BIT0	//0/0/x/x Enable SKP Ordered-Set Scheduling to Match the Clock Difference of 5600ppm
#define D3D5F1_UNRELIABLE_LINK_STA		0x1C9	//Unreliable Link Status
    #define D3D5F1_TBD_1C9_5			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D3D5F1_UNRL_G3			BIT4	//HwInit/x/x/x Gen3 Link Speed Unreliable Status
    #define D3D5F1_TBD_1C9_1			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D3D5F1_UNRL_G2			BIT0	//HwInit/x/x/x Gen2 Link Speed Unreliable Status
#define D3D5F1_RESERVED_Z11		0x1CA	//Reserved
    #define D3D5F1_TBD_1CB			0xFFFF	//0/R/x/x Reserved
#define D3D5F1_SYSTEM_DEBUG_REG		0x1CC	//System Debug Register
    #define D3D5F1_RSV_139			BIT7	//0/R/x/x Reserved
    #define D3D5F1_RSV_140			(BIT4 + BIT5 + BIT6)	//0/R/x/x Reserved
    #define D3D5F1_RSV_141			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D3D5F1_RSV_142			BIT0	//0/R/x/x Reserved
#define D3D5F1_MAC		0x1CD	//MAC
    #define D3D5F1_RFTSTR			(BIT6 + BIT7)	//0/0/x/x Number of FTS Ordered Sent in L0s Exit Sequence with N_FTS in the Received Training Sequence
    #define D3D5F1_RSKPSPD			BIT5	//0/0/x/x Skip Speed Negotiation and Get to Target Speed Directly
    #define D3D5F1_RLNRVSL			BIT4	//0/0/x/x Lane Reversal Support
    #define D3D5F1_RWDCONFIG			BIT3	//0/0/x/1 Support Width Change in Configuration State 
    #define D3D5F1_RSV_1CD_2			BIT2	//0/0/x/x Reserved
    #define D3D5F1_RINFEIDL			BIT1	//1b/1/x/x Inferred Electrical Idle in GEN2 State Transition
    #define D3D5F1_RQKTXG			BIT0	//0/0/1/x Downstream TX Arbitration between DLLM and PHYLS
#define D3D5F1_PCS_AND_PMA_1		0x1CE	//PCS and PMA 1
    #define D3D5F1_RSPDP0			BIT7	//0/0/x/x Transmitter Power State Setting When Link Speed Is Changed
    #define D3D5F1_RVCOSTB			(BIT4 + BIT5 + BIT6)	//001b/001b/x/x CDR VCO Stabilization Time
    #define D3D5F1_DRTERM			BIT3	//0/0/x/x Receiver Termination Disable
    #define D3D5F1_RLOWSWN			BIT2	//0/*0/x/x Enable Low Swing Mode 
    #define D3D5F1_RQKALGN			BIT1	//0/0/1/x Quick Byte Alignment Support
    #define D3D5F1_RQKCNV			BIT0	//0/0/1/x Quick Phase Conversion Support
#define D3D5F1_PCS_AND_PMA_2		0x1CF	//PCS and PMA 2
    #define D3D5F1_RSV_159			0xFC	//0/0/x/x Reserved
    #define D3D5F1_ENDEEMPHS			BIT1	//0/*0/x/x Enforce De-emphasis Level with Selectable De-emphasis Value
    #define D3D5F1_RFLOWSWN			BIT0	//0/*0/x/x Far-end Low Swing Adjustment
#define D3D5F1_PM_UNIT_PMU_CTL		0x1D0	//Power Management Unit (PMU) Control
    #define D3D5F1_RATREQEN			BIT7	//0/0/x/x Enable PHY Layer Automatic Change Speed / Width Request
    #define D3D5F1_RPTOFF			(BIT4 + BIT5 + BIT6)	//101b/101b/x/x Timeout Period
    #define D3D5F1_RSPDCLRPM			BIT3	//1b/1/x/x Enable Clearing the PM Cycles Requested by the Device in Speed Negotiation Process
    #define D3D5F1_RBDLLPEN			BIT2	//1b/1/x/x Retrain Link When Bad DLLP is Checked
    #define D3D5F1_LCLPBK			BIT1	//0/0/x/x Link Loopback
    #define D3D5F1_LCRCNFG			BIT0	//0/0/x/x Link Reconfigure Link Width
#define D3D5F1_PMU_TIMEOUT_AND_PMU_CTL		0x1D1	//PMU Timeout and PMU Control
    #define D3D5F1_UFTMERR			BIT7	//0/x/x/x Error Status Report When Entering L1 Fails
    #define D3D5F1_RSV_144			BIT6	//0/0/x/x Reserved
    #define D3D5F1_UFTIME			(BIT4 + BIT5)	//11b/11b/x/x Electrical Idle Waiting Period before Moving to L1 State (after issue ACK to the L1 Request from the device)
    #define D3D5F1_RPMUERRRETRAINEN			BIT3	//1b/1/x/x Enable PMU Initiate Error Recovery
    #define D3D5F1_RPMACKL1			BIT2	//0/0/x/x Enable PM_Request_Ack DLLP Generation When the CPL TLP Is Put Inside PM_Enter_L1 Sequences
    #define D3D5F1_RSV_1D1_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D3D5F1_PMU_L0S_IDLE_TIMEOUT		0x1D2	//PMU L0s Idle Timeout
    #define D3D5F1_L0SLIM			0xFF	//03h/03h/ffh/0 L0s Timer Limitation
#define D3D5F1_PMU_L1_IDLE_TIMEOUT		0x1D3	//PMU L1 Idle Timeout
    #define D3D5F1_ASL1LIM			0xFF	//04h/04h/ffh/0 Active State L1 Timer Limitation
#define D3D5F1_PMC_EXPRESS_MSG_STA		0x1D8	//PMC Express Message Status
    #define D3D5F1_RR2AER			BIT7	//0/R/x/x Reserved
    #define D3D5F1_RSV_146			0x7F	//0/0/x/x Reserved
#define D3D5F1_MSGC_TIMEOUT_CTL		0x1D9	//MSGC Timeout Control
    #define D3D5F1_RTME			BIT7	//0/0/x/x MSI Request Timeout Retry Enable
    #define D3D5F1_RTMCNT			0x7F	//01h/01h/x/x MSI Request Timeout Interval 
#define D3D5F1_MSGC_ECO_ITEM		0x1DA	//MSGC ECO ITEM
    #define D3D5F1_RSV_1DA			0xFFFE	//0/x/x/x Reserved
    #define D3D5F1_RRMVMSK			BIT0	//0/0/x/x Advisory Non-Fatal Error whether Mask by Uncorrectable Error Mask Bit
#define D3D5F1_TARGET_LINK_WIDTH		0x1E0	//Target Link Width
    #define D3D5F1_RSV_147			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D3D5F1_LKTLW_4			BIT4	//0/0/x/x Target Link Width Bit 4
    #define D3D5F1_LKTLW_3			BIT3	//0/0/x/x Target Link Width Bit 3
    #define D3D5F1_LKTLW_2			BIT2	//0/0/x/x Target Link Width Bit 2
    #define D3D5F1_LKTLW_1			BIT1	//0/0/x/x Target Link Width Bit 1
    #define D3D5F1_LKTLW_0			BIT0	//HwInit/x/x/x Target Link Width Bit 0
#define D3D5F1_PERCENTAGE_OF_NON_IDLE_PNI_CNTER_SETTING		0x1E1	//Percentage of Non-Idle (PNI) Counter Setting
    #define D3D5F1_RPNISTLM			0xF0	//0001b/0001b/x/x Delay Duration that the PNI Counter Will Start After Entering L0 State
    #define D3D5F1_RPNIDUR			0xF	//0010b/0010b/x/x Evaluation Period of PNI Calculation
#define D3D5F1_PNI_ALGORITHM_SETTINGS		0x1E2	//PNI Algorithm Settings
    #define D3D5F1_RPNI90CL			0xF0	//0010b/0010b/0000b/0011b Logic Idle Percentage of PNI_90 Calculation
    #define D3D5F1_RPNI30CL			0xF	//0010b/0010b/0011b/0000b Logic Idle Percentage of PNI_30 Calculation
#define D3D5F1_GEN2_MAC_ENHANCEMENT		0x1E3	//GEN2 MAC Enhancement
    #define D3D5F1_RCMPRCV			BIT7	//0/0/x/x Compliance Receive Bit Setting in Transmitting TS1 Ordered Sets
    #define D3D5F1_RUPMAXCFG			BIT6	//0/0/1/0 Link Width Selection
    #define D3D5F1_REQLZTM			(BIT4 + BIT5)	//10b/*10b/x/x Equalizer Tuning Timeout Setting
    #define D3D5F1_RPDDNCFG			BIT3	//0/0/x/x Power Down Unintended TX to Down Configure Link Width When LTSSM Is in Configuration State
    #define D3D5F1_RDOWNCFG			BIT2	//1b/1/x/x Electrical Idle Detection Behavior in Inactive Lanes When LTSSM Is in Configuration.Linkwidth.Start State
    #define D3D5F1_RIGNEQLZ			BIT1	//0/0/x/x Waiting Condition of Equalizer Tuning Timeout when LTSSM Is to Be Changed
    #define D3D5F1_RWDEARLY			BIT0	//1b/1/x/x Enable of TXs in Inactive Lanes to Upconfigure Link Width when LTSSM Is in Configuration and Recovery State
#define D3D5F1_SPEED_MANAGEMENT		0x1E4	//Speed Management
    #define D3D5F1_RSPFLCLR			BIT7	//0/0/x/x Reserved
    #define D3D5F1_RSCFLSET			0x7F	//00h/0/x/x Number of Permitted Speed Negotiation
#define D3D5F1_LINK_WIDTH_NEGOTIATION		0x1E5	//Link Width Negotiation
    #define D3D5F1_RWDFLCLR			BIT7	//0/0/x/x Reserved
    #define D3D5F1_RWCFLSET			0x7F	//0/0/x/x Number of Permitted Link Width Negotiation
#define D3D5F1_LINK_BANDWIDTH_CHANGE_FAIL_STA		0x1E6	//Link Bandwidth Change Fail Status
    #define D3D5F1_RSV_1E6_3			0xFE	//0/0/x/x Reserved
    #define D3D5F1_SPFLG2			BIT0	//HwInit/x/x/x Internal ¡°speed_fail_field¡± Status for Gen2 Link Speed
#define D3D5F1_BANDWIDTH_PWR_ARBITRATION		0x1E7	//Bandwidth Power Arbitration
    #define D3D5F1_RSV_1E7			0xFE	//0/0/x/x Reserved
    #define D3D5F1_RWIDLKHOT			BIT0	//1b/1/x/x Priority Control when Hardware Auto Bandwidth Change is Enabled for Power Saving
#define D3D5F1_AGGRESSIVE_PM		0x1E8	//Aggressive Power Management
    #define D3D5F1_RRXEIDPD			BIT7	//0/0/x/1 PCIE EPHY Receiver Electrical Idle Detector Power Down Control
    #define D3D5F1_RL1DYNPMG2			BIT6	//0/0/x/1 Enable L1 MPLL Power Down in GEN2 Speed
    #define D3D5F1_RLNCLKPM			BIT5	//0/0/1/1 Enable Clock Gating on Unused Lanes in a Multilane Link
    #define D3D5F1_RLNPWR			BIT4	//0/0/1/1 Enable Power Down on Unused Lanes in a Multilane Link
    #define D3D5F1_RDSKWPM			BIT3	//0/0/1/1 Enable Aggressive Power Management in RX Path to Data Link Layer Module (DLLM)
    #define D3D5F1_RDEVDETPM			BIT2	//0/0/1/1 Enable Aggressive Power Management when No Device Plug
    #define D3D5F1_RPDL2			BIT1	//0/0/x/x Enable PHYES Level 2 Power Down
    #define D3D5F1_RL1TPLLPD			BIT0	//0/0/0/*1 Turn off TPLL When in L1 State
#define D3D5F1_LKTGLS_INTER_AND_NEED_EQTS		0x1E9	//LKTGLS_ INTER  and NEED_EQTS
    #define D3D5F1_RSV_1E9			0xF8	//0/0/x/x Reserved
    #define D3D5F1_LKTGLS_INTER			(BIT1 + BIT2)	//10b/10b/x/x Real Target Link Speed
    #define D3D5F1_NEED_EQTS			BIT0	//0/0/x/x EQTS Control Register
#define D3D5F1_CLKREQ_SEL		0x1EA	//CLKREQ_SEL
    #define D3D5F1_RSV_1EA			0xFFF0	//0/x/x/x Reserved
    #define D3D5F1_CLKREQ_SEL_Z1			0xF	//1111b/x/x/x CLKREQ_SEL for PE7
#define D3D5F1_LTSSM_SW_RST_D3F0		0x1EC	//LTSSM_SW_RST
    #define D3D5F1_RSV_1EC			0xFE	//0/x/x/x Reserved
    #define D3D5F1_LTSSM_SW_RESET			BIT0	//0b/x/x/x LTSSM Software Reset
#define D3D5F1_RESERVED_Z12		0x1ED	//Reserved
    #define D3D5F1_RSV_1ED			0xFF	//0/x/x/x Reserved
#define D3D5F1_RESERVED_Z13		0x1EE	//Reserved
    #define D3D5F1_RSV_1EE			0xFF	//0/x/x/x Reserved
#define D3D5F1_RESERVED_Z14		0x1EF	//Reserved
    #define D3D5F1_RSV_1EF			0xFF	//0/x/x/x Reserved
#define D3D5F1_RESERVED_Z15		0x1F0	//Reserved
    #define D3D5F1_RSV_1F0			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z16		0x1F1	//Reserved
    #define D3D5F1_RSV_1F1			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z17		0x1F2	//Reserved
    #define D3D5F1_RSV_1F2			0xFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z18		0x1F4	//Reserved
    #define D3D5F1_RSV_1F4			0xFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z19		0x1F6	//Reserved
    #define D3D5F1_RSV_1F6			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z20		0x1F7	//Reserved
    #define D3D5F1_RSV_1F7			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z21		0x1F8	//Reserved
    #define D3D5F1_RSV_1F8			0xFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z22		0x1FA	//Reserved
    #define D3D5F1_RSV_1FA			0xFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z23		0x1FC	//Reserved
    #define D3D5F1_RSV_1FC			0xFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z24		0x1FE	//Reserved
    #define D3D5F1_RSV_1FE			0xFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z25		0x200	//Reserved
    #define D3D5F1_RSV_200			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z26		0x201	//Reserved
    #define D3D5F1_RSV_201			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z27		0x202	//Reserved
    #define D3D5F1_RSV_202			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z28		0x203	//Reserved
    #define D3D5F1_RSV_203			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z29		0x204	//Reserved
    #define D3D5F1_RSV_160			0xFC000000	//0/0/x/x Reserved
    #define D3D5F1_PWRTRSET			(BIT24 + BIT25)	//00b/0/x/x Transmit and Receiver Power State Setting Options
    #define D3D5F1_RSV_204_23_0			0xFFFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z30		0x208	//Reserved
    #define D3D5F1_RSV_208			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z31		0x209	//Reserved
    #define D3D5F1_RSV_209			0xFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z32		0x20B	//Reserved
    #define D3D5F1_RSV_20A			0xFF	//0/x/x/x Reserved
#define D3D5F1_RESERVED_Z33		0x20C	//Reserved
    #define D3D5F1_RSV_20C			0xFFFFFFFF	//0/0/x/x Reserved
#define D3D5F1_PEXC_PM_CTL_1		0x230	//PEXC Power Management Control 1
    #define D3D5F1_RPMUDMCLK			BIT7	//0/0/1/1 Dynamic Clock Power Management for PMU Transmission
    #define D3D5F1_RDLTXDMCLK			BIT6	//0/0/1/1 Dynamic Stop for EDCLK for Downstream Packets in DLL
    #define D3D5F1_RDLRXDMCLK			BIT5	//0/0/1/1 Dynamic Stop for EDCLK for Upstream Packets in DLL of RP
    #define D3D5F1_RTLRTYDBXPM			BIT4	//0/0/1/1 Dynamic Stop for ETCLK for Downstream Retry FIFO of RP
    #define D3D5F1_RTLSNOPPM			BIT3	//0/0/1/1 Dynamic Stop for ETCLK for Upstream Snoop Data Handling of RP
    #define D3D5F1_RTLNSNOPPM			BIT2	//0/0/1/1 TL Dynamic Clock Control for Non-snoop Path
    #define D3D5F1_RTLDNDBXPM			BIT1	//0/0/1/1 Dynamic Stop for ETCLK for Downstream Data FIFO of RP
    #define D3D5F1_RTLUPDBXPM			BIT0	//0/0/1/1 Dynamic Stop for ETCLK for Upstream Data FIFO of RP
#define D3D5F1_PM_CTL_2		0x231	//Power Management Control 2
    #define D3D5F1_RTLUPPM			BIT7	//0/0/1/1 Dynamic Stop for ETCLK for Upstream Paths of RP
    #define D3D5F1_RTLDNPM			BIT6	//0/0/1/1 Dynamic Clock Power Management for Downstream
    #define D3D5F1_RTLRTYPM			BIT5	//0/0/1/1 Dynamic Stop for ETCLK for Downstream Retry Path of RP
    #define D3D5F1_RTLLNKPM			BIT4	//0/0/1/1 Dynamic Clock Power Management for Link Up or Down Case 
    #define D3D5F1_RPEPM			BIT3	//0/0/1/1 Dynamic Clock Stop Control for ETCLK at PCIe Root Port
    #define D3D5F1_RTLRCVPM			BIT2	//0/0/1/1 Dynamic Stop for ETCLK for Upstream Interface of RP
    #define D3D5F1_RMESCDPM			BIT1	//0/0/1/1 Dynamic Stop for ECLK in MSGC for PCIe RP
    #define D3D5F1_RMESCGPM			BIT0	//0/0/1/1 Dynamic Stop for GCLK in MSGC for PCIe RP1
#define D3D5F1_PEXC_PM_CTL_3		0x232	//PEXC Power Management Control 3
    #define D3D5F1_RSV_222			0xFC	//0/0/x/x Reserved
    #define D3D5F1_RPHYPM			BIT1	//0/0/1/1 Dynamic Stop for EPCLK at PCIe Physical Layer
    #define D3D5F1_RL1DYNPM			BIT0	//0/0/1/1 Clock Stop at L1 State for PCIe Root Port 
#define D3D5F1_RESERVED_Z34		0x233	//Reserved
    #define D3D5F1_RSV_223			0xFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z35		0x240	//Reserved
    #define D3D5F1_RSV_230			0xFFFFFFFF	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z36		0x244	//Reserved
    #define D3D5F1_RSV_234			0xFFFFFFFF	//0/0/x/x Reserved
#define D3D5F1_MISC_CTL		0x290	//MISC Control
    #define D3D5F1_RSV_290_11			0xFFFFF800	//0/0/x/x Reserved
    #define D3D5F1_RTIMER_LIMI_RCOV			(BIT8 + BIT9 + BIT10)	//0/x/x/x Time Stay at Recovery.Speed state
    #define D3D5F1_RSV_290_7			BIT7	//0/0/x/x Rescerved
    #define D3D5F1_L11_EXIT_SEL			(BIT5 + BIT6)	//00b/x/x/x L1 Substate Exit Select
    #define D3D5F1_RWTEXEPH23			BIT4	//0/x/x/x Want Execute EQ Phase 2 and 3
    #define D3D5F1_RXDEID_L1_SEL			0xF	//0/x/x/x Rx Eidle Detecter Periodical Power Down Select in L1
#define D3D5F1_RXPOL_CTL		0x294	//RXPOL Control
    #define D3D5F1_RSV_294_7			0xFFFFFFFC	//0/0/x/x Reserved
    #define D3D5F1_RRXPOL_EN			BIT1	//0b/0/x/x Enable Manul Set RXPOL
    #define D3D5F1_RRXPOL			BIT0	//0b/x/x/x Manul Set RXPOL
#define D3D5F1_SCI_FOR_RECEIVED_REDO_EQ_REQ		0x298	//SCI for Received REDO EQ Request
    #define D3D5F1_RSV_298_5			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D3D5F1_REEQ_SCI_STATUS			BIT4	//0/0/x/x SCI Status for Received Re-do EQ Request
    #define D3D5F1_RSV_298_1			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define D3D5F1_REEQ_SCI_EN			BIT0	//0/0/x/x SCI Enable for Received Re-do EQ Request
#define D3D5F1_SMI_FOR_RECEIVED_REDO_EQ_REQ		0x299	//SMI for Received REDO EQ Request
    #define D3D5F1_RSV_299_5			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D3D5F1_REEQ_SMI_STATUS			BIT4	//0/0/x/x SMI Status for Received Re-do EQ Request
    #define D3D5F1_RSV_299_1			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define D3D5F1_REEQ_SMI_EN			BIT0	//0/0/x/x SMI Enable for Received Re-do EQ Request
#define D3D5F1_SERR_NMI_SMI_SCI_CTL		0x29A	//SERR NMI/SMI/SCI Control
    #define D3D5F1_RSV_29A			0xFE00	//0/x/x/x Reserved
    #define D3D5F1_FTERR_SCI_EN			BIT8	//0/0/x/x Fatal Error SCI Enable
    #define D3D5F1_FTERR_SMI_EN			BIT7	//0/0/x/x Fatal Error SMI Enable
    #define D3D5F1_FTERR_NMI_EN			BIT6	//0/0/x/x Fatal Error NMI Enable
    #define D3D5F1_NFTERR_SCI_EN			BIT5	//0/0/x/x Non Fatal Error SCI Enable
    #define D3D5F1_NFTERR_SMI_EN			BIT4	//0/0/x/x Non Fatal Error SMI Enable
    #define D3D5F1_NFTERR_NMI_EN			BIT3	//0/0/x/x Non Fatal Error NMI Enable
    #define D3D5F1_CORERR_SCI_EN			BIT2	//0/0/x/x Correctable Error SCI Enable
    #define D3D5F1_CORERR_SMI_EN			BIT1	//0/0/x/x Correctable Error SMI Enable
    #define D3D5F1_CORERR_NMI_EN			BIT0	//0/0/x/x Correctable Error NMI Enable
#define D3D5F1_EIDLE_DETECT_ENABLE_IN_POLLING_ACTIVE		0x29C	//EIDLE detect Enable in Polling.Active
    #define D3D5F1_RSV_29C			0xFE	//0/0/x/x Reserved
    #define D3D5F1_EIDLEDET_EN			BIT0	//0/0/x/x EIDLE Detect Enable in Polling.Active State
#define D3D5F1_RESERVED_Z37		0x29D	//Reserved
    #define D3D5F1_RSV_29D			0xFE	//0/0/x/x Reserved
    #define D3D5F1_C			BIT0	//0/0/x/x Reserved
#define D3D5F1_RESERVED_Z38		0x29E	//Reserved
    #define D3D5F1_TBD_29E			0xFFFF	//0/R/x/x Reserved
#define D3D5F1_SECONDARY_PCI_EXPRESS_EXTENDED_CAP		0x2A0	//Secondary PCI Express Extended Capability
    #define D3D5F1_TBD_2A0_3120			0xFFF00000	//2D0h/R/x/x Next Capability Offset
    #define D3D5F1_TBD_2A0_1916			0xF0000	//1h/R/x/x Capability Version
    #define D3D5F1_TBD_2A0_1500			0xFFFF	//0019h/R/x/x PCI Express Extended Capability ID
#define D3D5F1_LINK_CTL_3_REG		0x2A4	//Link Control 3 Register
    #define D3D5F1_TBD_2A4_12			0xFFFFF000	//0/R/x/x Reserved
    #define D3D5F1_RLOW_SKP_EN			(BIT9 + BIT10 + BIT11)	//0/x/x/x Enable Lower SKP OS Generation Vector
    #define D3D5F1_TBD_2A4_2			0x1FC	//0/x/x/x Reserved
    #define D3D5F1_EQINTEN			BIT1	//0/x/x/x Link Equalization Request Interrupt Enable
    #define D3D5F1_PERFORMEQ			BIT0	//0/x/x/x Perform Equalization
#define D3D5F1_LANE_ERR_STA_REG		0x2A8	//Lane Error Status Register
    #define D3D5F1_TBD_2A8_72			0xFFFFFFFE	//0/R/x/x Reserved
    #define D3D5F1_LANEERR00			BIT0	//0/0/x/x Lane Error Status Bits
#define D3D5F1_LANE_EQUALIZATION_CTL_REG		0x2AC	//Lane Equalization Control Register
    #define D3D5F1_TBD_2AC_31			0xFFFF0000	//0/R/x/x Reserved
    #define D3D5F1_TBD_2AC_15			BIT15	//0/R/x/x Reserved
    #define D3D5F1_EPRXPRESET00			(BIT12 + BIT13 + BIT14)	//HwInit/x/x/x Lane 0 Upstream Port Receiver Preset Hint
    #define D3D5F1_EPTXPRESET00			0xF00	//HwInit/x/x/x Lane 0 Upstream Port Transmitter Preset 
    #define D3D5F1_TBD_2AC_7			BIT7	//0/R/x/x Reserved
    #define D3D5F1_RXPRESET00			(BIT4 + BIT5 + BIT6)	//HwInit/x/x/x Lane 0 Downstream Port Receiver Preset Hint
    #define D3D5F1_TXPRESET00			0xF	//HwInit/x/x/x Lane 0 Downstream Port Transmitter Preset 
#define D3D5F1_LANE_EQUALIZATION_CTL_REG_Z1		0x2B0	//Lane Equalization Control Register
    #define D3D5F1_TBD_2B0			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_LANE_EQUALIZATION_CTL_REG_Z2		0x2B4	//Lane Equalization Control Register
    #define D3D5F1_TBD_2B4			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_LANE_EQUALIZATION_CTL_REG_Z3		0x2B8	//Lane Equalization Control Register
    #define D3D5F1_TBD_2B8			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_LANE_EQUALIZATION_CTL_REG_Z4		0x2BC	//Lane Equalization Control Register
    #define D3D5F1_TBD_2BC			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_LANE_EQUALIZATION_CTL_REG_Z5		0x2C0	//Lane Equalization Control Register
    #define D3D5F1_TBD_2C0			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_LANE_EQUALIZATION_CTL_REG_Z6		0x2C4	//Lane Equalization Control Register
    #define D3D5F1_TBD_2C4			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_LANE_EQUALIZATION_CTL_REG_Z7		0x2C8	//Lane Equalization Control Register
    #define D3D5F1_TBD_2C8			0xFFFFFFFF	//0/R/x/x Reserved
#define D3D5F1_L1_PM_SUBSTATES_EXTENDED_CAP		0x2D0	//L1 PM Substates Extended Capability
    #define D3D5F1_TBD_2D0_3120			0xFFF00000	//0/R/x/x Next Capability Offset
    #define D3D5F1_TBD_2D0_1916			0xF0000	//1h/R/x/x Capability Version
    #define D3D5F1_TBD_2D0_1500			0xFFFF	//001Eh/R/x/x PCI Express Extended Capability ID - This Field is a PCI-SIG 
#define D3D5F1_L1_PM_SUBSTATES_CAPS_REG		0x2D4	//L1 PM Substates Capabilities Register
    #define D3D5F1_TBD_2D4_24			0xFF000000	//0/R/x/x Reserved
    #define D3D5F1_PORT_T_POWER_ON_VALUE			0xF80000	//00111b/x/x/x Port T_POWER_ON Value
    #define D3D5F1_TBD_2D4_18			BIT18	//0/R/x/x Reserved
    #define D3D5F1_PORT_T_POWER_ON_SCALE			(BIT16 + BIT17)	//01b/x/x/x Port T_POWER_ON Scale
    #define D3D5F1_PORT_CM_RESTORE_TIME			0xFF00	//4h/x/x/x Port Common_Mode_Restore_Time
    #define D3D5F1_TBD_2C4_5			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D3D5F1_L1_SUB_SUPPORT			BIT4	//1b/x/x/x L1 PM Substates Supported
    #define D3D5F1_ASPML11_SUPPORT			BIT3	//1b/x/x/x ASPM L1.1 Supported
    #define D3D5F1_ASPML12_SUPPORT			BIT2	//1b/x/x/x ASPM L1.2 Supported
    #define D3D5F1_PML11_SUPPORT			BIT1	//1b/x/x/x PCI-PM L1.1 Supported
    #define D3D5F1_PML12_SUPPORT			BIT0	//1b/x/x/x PCI-PM L1.2 Supported
#define D3D5F1_L1_PM_SUBSTATES_CTL_1_REG		0x2D8	//L1 PM Substates Control 1 Register
    #define D3D5F1_TBD_2D8_31			0xFFFFFFF0	//0/R/x/x Reserved
    #define D3D5F1_ASPML11_EN			BIT3	//0/x/x/x ASPM L1.1 Enable
    #define D3D5F1_TBD_2D8_2			BIT2	//0/R/x/x Reserved
    #define D3D5F1_PML11_EN			BIT1	//0/x/x/x PCI-PM L1.1 Enable
    #define D3D5F1_TBD_2D8_0			BIT0	//0/R/x/x Reserved
#define D3D5F1_L1_PM_SUBSTATES_CTL_2_REG		0x2DC	//L1 PM Substates Control 2 Register
    #define D3D5F1_TBD_2BD			0xFFFFFF00	//0/R/x/x Reserved
    #define D3D5F1_T_POWER_ON_VALUE			0xF8	//00111b/x/x/x T_POWER_ON Value
    #define D3D5F1_TBD_2BC_Z1			BIT2	//0/R/x/x Reserved
    #define D3D5F1_T_POWER_ON_SCALE			(BIT0 + BIT1)	//01b/x/x/x T_POWER_ON Scale
#define D3D5F1_SID_OF_PCIE_ROOT_PORT		0x2E0	//SID of PCIE Root Port
    #define D3D5F1_RBNB			0xFF000000	//00h/x/x/x Bus Number of SID of PCIE Root Port
    #define D3D5F1_RDVNB			0xF80000	//00101b/x/x/x Device Number of SID of PCIE Root Port
    #define D3D5F1_RFNB			(BIT16 + BIT17 + BIT18)	//001b/x/x/x Function Number of SID of PCIE Root Port
    #define D3D5F1_TBD_2E0_1			0xFFFE	//0/x/x/x Reserved
    #define D3D5F1_SID_LOCKBIT			BIT0	//0/x/x/x Reserved 
#endif
