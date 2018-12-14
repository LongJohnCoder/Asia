//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		VPIL					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D7F0_VPIL_R102(A0).doc(final)(D7F0,PE0) .xls
#ifndef _CHX002_D7F0_VPIL_H
#define _CHX002_D7F0_VPIL_H
//D7F0
#define D7F0_VID		0x00	//Vendor ID
    #define D7F0_VENDORID			0xFFFF	//1106h/x/x/x Vendor ID
#define D7F0_DID		0x02	//Device ID
    #define D7F0_TBD_G0			0xFFFF	//91C1h/x/x/x Device ID
#define D7F0_PCI_CMD		0x04	//PCI Command
    #define D7F0_RSV_0			0xF800	//0/R/x/x Reserved
    #define D7F0_RINTDIS			BIT10	//0/0/x/x Interrupt Disable
    #define D7F0_RSV_1			BIT9	//0/R/x/x Fast Back-to-Back Transaction Enable
    #define D7F0_RSERR			BIT8	//0/x/x/x SERR# Enable
    #define D7F0_RSV_2			BIT7	//0/R/x/x Address / Data Stepping
    #define D7F0_RPTYERR			BIT6	//0/0/x/x Parity Error Response
    #define D7F0_RSV_3			BIT5	//0/R/x/x VGA Palette Snooping
    #define D7F0_RX004_4			BIT4	//0/x/x/x Memory Write and Invalidate
    #define D7F0_RX004_3			BIT3	//0/x/x/x Response to Special Cycle
    #define D7F0_RMSTR			BIT2	//0/x/x/x Bus Master Enable
    #define D7F0_RENMEM			BIT1	//0/x/x/x Memory Space
    #define D7F0_RENIO			BIT0	//0/x/x/x I/O Space
#define D7F0_PCI_STA		0x06	//PCI Status
    #define D7F0_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D7F0_SERRS			BIT14	//0/0/x/x Signaled System Error
    #define D7F0_SMABORT			BIT13	//0/R/x/x Received Master Abort
    #define D7F0_STABORTM			BIT12	//0/R/x/x Received Target Abort
    #define D7F0_STABORTS			BIT11	//0/R/x/x Signaled Target Abort
    #define D7F0_RSV_5			(BIT9 + BIT10)	//0/R/x/x DEVSEL# Timing
    #define D7F0_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D7F0_RSV_6			BIT7	//0/R/x/x Capability of Accepting Fast Back-to-back as a Target
    #define D7F0_RX004_14			BIT6	//0/x/x/x User Definable Features
    #define D7F0_RX004_13			BIT5	//0/x/x/x 66 MHz Capable
    #define D7F0_RCAP			BIT4	//1b/R/x/x Capabilities List
    #define D7F0_SINTSTT			BIT3	//0/x/x/x Interrupt Status
    #define D7F0_RSV_7			(BIT0 + BIT1 + BIT2)	//0/R/x/x Reserved
#define D7F0_REV_ID		0x08	//Revision ID
    #define D7F0_TBD_4			0xFF	//0/x/x/x Revision Code
#define D7F0_CLASS_CODE		0x09	//Class Code
    #define D7F0_TBD_5_23_0			0xFFFFFF	//088000h/x/x/x Class Code
#define D7F0_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D7F0_RSV_8			0xFF	//0/x/x/x Cache Line Size
#define D7F0_MASTER_LATENCY_TIMER		0x0D	//Master Latency Timer
    #define D7F0_RSV_9			0xFF	//0/R/x/x Master Latency Timer
#define D7F0_HEADER_TYPE		0x0E	//Header Type
    #define D7F0_RSV_0E			0xFF	//0/x/x/x Header Type Code
#define D7F0_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D7F0_TBD_7			0xFF	//0/R/x/x BIST Support
#define D7F0_BASE_ADR_REGS_0		0x10	//Base Address Registers 0
    #define D7F0_RX10_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 0
#define D7F0_BASE_ADR_REGS_1		0x14	//Base Address Registers 1
    #define D7F0_RX14_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 1
#define D7F0_BASE_ADR_REGS_2		0x18	//Base Address Registers 2
    #define D7F0_RX18_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 2
#define D7F0_BASE_ADR_REGS_3		0x1C	//Base Address Registers 3
    #define D7F0_RX1C_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 3
#define D7F0_BASE_ADR_REGS_4		0x20	//Base Address Registers 4
    #define D7F0_RX20_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 4
#define D7F0_BASE_ADR_REGS_5		0x24	//Base Address Registers 5
    #define D7F0_RX24_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 5
#define D7F0_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D7F0_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D7F0_SVID		0x2C	//Subsystem Vendor ID
    #define D7F0_RX2C_15_0			0xFFFF	//0/X/x/x Subsystem Vendor ID
#define D7F0_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D7F0_RX2C_31_16			0xFFFF	//0/x/x/x Subsystem ID
#define D7F0_EXPANSION_ROM_BASE_ADR		0x30	//Expansion ROM Base Address
    #define D7F0_RX30_31_0			0xFFFFFFFF	//0/R/x/x Expansion ROM Base Address
#define D7F0_CAP_POINTER		0x34	//Capability Pointer
    #define D7F0_TBD_16			0xFF	//40h/40h/x/x Capability Pointer
#define D7F0_RESERVED		0x35	//Reserved
    #define D7F0_RX35_7_0			0xFF	//0/R/x/x Reserved
#define D7F0_RESERVED_Z1		0x36	//Reserved
    #define D7F0_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D7F0_RESERVED_Z2		0x37	//Reserved
    #define D7F0_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D7F0_INTR_LINE_AND_INTR_PIN		0x3C	//Interrupt Line and Interrupt Pin
    #define D7F0_RINTLN			0xFF	//0/x/x/x Interrupt Line
#define D7F0_INTR_PIN		0x3D	//Interrupt Pin
    #define D7F0_RX03C_15_11			0xF8	//0/x/x/x Reserved
    #define D7F0_TBD_17			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Interrupt Pin
#define D7F0_MINIMUM_GRANT_AND_MAXIMUM_LATENCY		0x3E	//Minimum Grant and Maximum Latency
    #define D7F0_RX3C_31_24			0xFF00	//0/R/x/x Maximum Latency
    #define D7F0_RX3C_23_16			0xFF	//0/R/x/x Minimum Grant
#define D7F0_PCI_EXPRESS_LIST		0x40	//PCI Express List
    #define D7F0_TBD_24			0xFF00	//A0h/A0h/x/x Next Pointer
    #define D7F0_TBD_25			0xFF	//10h/10h/x/x Capability ID
#define D7F0_PCI_EXPRESS_CAPS_D7F0		0x42	//PCI Express Capabilities (D7F0)
    #define D7F0_RSV_42_15			BIT15	//0/R/x/x Reserved
    #define D7F0_RTCSEN			BIT14	//0/0/x/x Reserved
    #define D7F0_XINTMNO			0x3E00	//0/0/x/x Interrupt Message Number; Reserved
    #define D7F0_XSLIMP			BIT8	//0/0/x/x Slot Implemented DAL1AL; Reserved
    #define D7F0_XDPTYPE			0xF0	//1001b/1001b/x/x Device / Port Type; Reserved
    #define D7F0_PCIE_VER			0xF	//2h/0/x/x Capability Version
#define D7F0_DEV_CAPS_1		0x44	//Device Capabilities 1
    #define D7F0_RSV_19			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define D7F0_TBD_27			BIT28	//0/0/x/x Function Level Reset Capability
    #define D7F0_RSV_20			(BIT26 + BIT27)	//0/R/x/x Captured Slot Power Limit Scale
    #define D7F0_RSV_21			0x3FC0000	//0/R/x/x Captured Slot Power Limit Value
    #define D7F0_RSV_22			(BIT16 + BIT17)	//0/R/x/x Reserved
    #define D7F0_RRBERRP			BIT15	//1b/1/x/x Role-based Error Reporting
    #define D7F0_RSV_23			BIT14	//0/R/x/x Power Indicator Present
    #define D7F0_RSV_24			BIT13	//0/R/x/x Attention Indicator Present
    #define D7F0_RSV_25			BIT12	//0/R/x/x Attention Button Present
    #define D7F0_DAL1AL			(BIT9 + BIT10 + BIT11)	//000b/0/x/x Endpoint L1 Acceptable Latency; Reserved
    #define D7F0_RSV_44			(BIT6 + BIT7 + BIT8)	//0/R/x/x Endpoint L0s Acceptable Latency
    #define D7F0_DAXTAGF			BIT5	//0/0/x/x Extended Tag Field Supported; Reserved
    #define D7F0_RSV_26			(BIT3 + BIT4)	//0/R/x/x Phantom Functions Supported
    #define D7F0_DAMPSS			(BIT0 + BIT1 + BIT2)	//000b/1/x/x Max Payload Size Supported
#define D7F0_DEV_CTL_1		0x48	//Device Control 1
    #define D7F0_RSV_27			BIT15	//0/R/x/x Reserved
    #define D7F0_DCMRRS			(BIT12 + BIT13 + BIT14)	//0/R/x/x Max Read Request Size
    #define D7F0_DCENS			BIT11	//0/0/x/x Enable No Snoop
    #define D7F0_DCAPPME			BIT10	//0/x/x/x Auxiliary Power PM Enable
    #define D7F0_DCPFE			BIT9	//0/R/x/x Phantom Functions Enable
    #define D7F0_DCETFE			BIT8	//0/0/x/x Extended Tag Field Enable
    #define D7F0_DCMPS			(BIT5 + BIT6 + BIT7)	//0/000*/001*/x Max Payload Size
    #define D7F0_DCERO			BIT4	//0/0/x/x Enable Relaxed Ordering
    #define D7F0_DCURRE			BIT3	//0/0/x/x Unsupported Request Reporting Enable
    #define D7F0_DCFERE			BIT2	//0/0/x/x Fatal Error Reporting Enable
    #define D7F0_DCNFERE			BIT1	//0/0/x/x Non-Fatal Error Reporting Enable
    #define D7F0_DCCERE			BIT0	//0/0/x/x Correctable Error Reporting Enable
#define D7F0_DEV_STA_1		0x4A	//Device Status 1
    #define D7F0_RSV_4B			0xFFC0	//0/R/x/x Reserved
    #define D7F0_DSTP			BIT5	//0/x/x/x Transactions Pending
    #define D7F0_DSAPD			BIT4	//0/0/x/x AUX Power Detected
    #define D7F0_DSURD			BIT3	//0/0/x/x Unsupported Request Detected (TL)
    #define D7F0_DSFED			BIT2	//0/0/x/x Fatal Error Detected (TL)
    #define D7F0_DSNFED			BIT1	//0/0/x/x Non-Fatal Error Detected (TL)
    #define D7F0_DSCED			BIT0	//0/0/x/x Correctable Error Detected (TL)
#define D7F0_LINK_CAPS_1_D7F0_RESERVED_FOR_INTERNAL_REFERENCE		0x4C	//Link Capabilities 1 (D7F0) (Reserved for internal reference)
    #define D7F0_LKPN			0xFF000000	//01h/01h/x/x Port Number
    #define D7F0_RSV_28G			BIT23	//0/R/x/x Reserved
    #define D7F0_ASPMOPTCOMP			BIT22	//1b/1/x/x ASPM Optionality Compliance 
    #define D7F0_RLBWNTFC			BIT21	//1b/1/x/x Link Bandwidth Notification Capability
    #define D7F0_RDL_AR_CAP			BIT20	//1b/1/x/x Data Link Layer Link Active Reporting Capable
    #define D7F0_RLCASDERC			BIT19	//1b/1/x/x Surprise Down Error Reporting Capable
    #define D7F0_RLCACPM			BIT18	//0/0/x/x Clock Power Management
    #define D7F0_LKL1EL			(BIT15 + BIT16 + BIT17)	//011b/x/x/x L1 Exit Latency
    #define D7F0_LKL0SE			(BIT12 + BIT13 + BIT14)	//HwInit/x/x/x L0s Exit Latency
    #define D7F0_LKAPMS			(BIT10 + BIT11)	//11b/11/x/x Active State Link PM (ASPM) Support
    #define D7F0_LKMLW_5			BIT9	//0/0/x/x Maximum Link Width Bit 5
    #define D7F0_LKMLW_4			BIT8	//HwInit/x/x/x Maximum Link Width Bit 4
    #define D7F0_LKMLW_3			BIT7	//HwInit/x/x/x Maximum Link Width Bit 3
    #define D7F0_LKMLW_2			BIT6	//0/x/x/x Maximum Link Width Bit 2
    #define D7F0_LKMLW_1			BIT5	//0/0/x/x Maximum Link Width Bit 1
    #define D7F0_LKMLW_0			BIT4	//0/0/x/x Maximum Link Width Bit 0
    #define D7F0_LKMAXLS_3			BIT3	//0/0/x/x Max Link Speed Bit 3 
    #define D7F0_LKMAXLS_2			BIT2	//0/0/x/x Max Link Speed Bit 2
    #define D7F0_LKMAXLS_1			BIT1	//1b/1/x/x Max Link Speed Bit 1
    #define D7F0_LKMAXLS_0			BIT0	//1b/1/x/x Max Link Speed Bit 0
#define D7F0_LINK_CTL_1_RESERVED_FOR_INTERNAL_REFERENCE		0x50	//Link Control 1 (Reserved for internal reference)
    #define D7F0_RSV_32			0xF000	//0/R/x/x Reserved
    #define D7F0_RLABITEN			BIT11	//0/0/x/x Enable Link Autonom ous Bandwidth Interrupt
    #define D7F0_RLBMITEN			BIT10	//0/0/x/x Enable Link Bandwidth Management Interrupt
    #define D7F0_RHATNMWD			BIT9	//0/0/x/0 Hardware Autonomous Width Control
    #define D7F0_RLCOCPMEN			BIT8	//0/R/x/x Enable Clock Power Management
    #define D7F0_LCES			BIT7	//0/0/0/x Extended Synch
    #define D7F0_LCCCC			BIT6	//1b/x/x/x Common Clock Configuration
    #define D7F0_LCRL			BIT5	//0/0/x/x Retrain Link
    #define D7F0_LCLD			BIT4	//0/0/x/x Link Disable
    #define D7F0_LCRCB			BIT3	//0/0/x/x Read Completion Boundary
    #define D7F0_RSV_33			BIT2	//0/R/x/x Reserved
    #define D7F0_LCAPMS			(BIT0 + BIT1)	//00b/00*/00*/11* Link Active State PM (ASPM) Control
#define D7F0_LINK_STA_1_RESERVED_FOR_INTERNAL_REFERENCE		0x52	//Link Status 1 (Reserved for internal reference)
    #define D7F0_RLATNMBW			BIT15	//0/0/x/x Link Autonomous Bandwidth Status
    #define D7F0_RLBWMNGT			BIT14	//0/0/x/x Link Bandwidth Management Status
    #define D7F0_DL_ACTIVE			BIT13	//HwInit/x/x/x Data Link Layer Link Active
    #define D7F0_LSSCC			BIT12	//1b/x/x/x Slot Clock Configuration
    #define D7F0_LSLT			BIT11	//HwInit/x/x/x Link Training
    #define D7F0_LSTE			BIT10	//HwInit/x/x/x Training Error
    #define D7F0_TBD_28			BIT9	//0/R/x/x Negotiated Link Width Bit 5
    #define D7F0_LSNLW			0x1F0	//HwInit/x/x/x Negotiated Link Width Bits[4:0]
    #define D7F0_LSLS			0xF	//HwInit/x/x/x Current Link Speed
#define D7F0_SLOT_CAPS_1_RESERVED_FOR_INTERNAL_REFERENCE		0x54	//Slot Capabilities 1 (Reserved for internal reference)
    #define D7F0_SLPSN			0xFFF80000	//0/0/x/x Physical Slot Number; Reserved
    #define D7F0_RSCANCCS			BIT18	//0/0/x/x No Command Completed Support
    #define D7F0_RSCAEMIP			BIT17	//0/0/x/x Electromechanical Interlock Present
    #define D7F0_RSPLS			(BIT15 + BIT16)	//0/0/x/x Slot Power Limit Scale
    #define D7F0_RSPLV			0x7F80	//0/0/x/x Slot Power Limit Value
    #define D7F0_SCHP_CAP			BIT6	//0/0/x/x Hot-Plug Capable
    #define D7F0_SCHPS			BIT5	//1b/1/x/x Hot-Plug Surprise
    #define D7F0_SCPIP			BIT4	//0/0/x/x Power Indicator Present
    #define D7F0_SCAIP			BIT3	//0/0/x/x Attention Indicator Present
    #define D7F0_RSV_36			BIT2	//0/R/x/x MRL Sensor Present
    #define D7F0_RSV_37			BIT1	//0/R/x/x Power Controller Present
    #define D7F0_SCABP			BIT0	//0/0/x/x Attention Button Present
#define D7F0_SLOT_CTL_1_RESERVED_FOR_INTERNAL_REFERENCE		0x58	//Slot Control 1 (Reserved for internal reference)
    #define D7F0_RSV_39			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define D7F0_RDLSCHGEN			BIT12	//0/0/x/x Enable Data Link Layer State Change
    #define D7F0_RSCOEMIC			BIT11	//0/R/x/x Electromechanical Interlock Control
    #define D7F0_SCPCC			BIT10	//0/0/x/x Power Controller Control
    #define D7F0_SCPIC			(BIT8 + BIT9)	//00b/0/x/x Power Indicator Control
    #define D7F0_SCAIC			(BIT6 + BIT7)	//00b/0/x/x Attention Indicator Control
    #define D7F0_SCHPIE			BIT5	//0/0/x/x Enable Hot-Plug Interrupt
    #define D7F0_SCCCIE			BIT4	//0/0/x/x Enable Command Completed Interrupt 
    #define D7F0_SCPDCE			BIT3	//0/0/x/x Enable Presence Detect Change
    #define D7F0_RSV_40			BIT2	//0/R/x/x Enable MRL Sensor Change
    #define D7F0_RSV_41			BIT1	//0/R/x/x Enable Power Fault Detected
    #define D7F0_SCABPE			BIT0	//0/0/x/x Enable Attention Button Pressed
#define D7F0_SLOT_STA_1_RESERVED_FOR_INTERNAL_REFERENCE		0x5A	//Slot Status 1 (Reserved for internal reference)
    #define D7F0_RSV_42			0xFE00	//0/R/x/x Reserved
    #define D7F0_RDLSCHG			BIT8	//0/0/x/x Data Link Layer State Changed
    #define D7F0_RSSEMIS			BIT7	//0/R/x/x Electromechanical Interlock Status
    #define D7F0_SPDCST			BIT6	//HwInit/x/x/x Presence Detect State
    #define D7F0_RSV_43			BIT5	//0/R/x/x MRL (Manually Operated Retention Latch) Sensor State
    #define D7F0_SSCC			BIT4	//0/0/x/x Command Completed
    #define D7F0_SPDC			BIT3	//0/0/x/x Reserved for VPI
    #define D7F0_TBD_29			BIT2	//0/R/x/x MRL Sensor Change
    #define D7F0_TBD_30			BIT1	//0/R/x/x Power Fault Detected
    #define D7F0_SSABP			BIT0	//0/0/x/x Attention Button Pressed
#define D7F0_ROOT_CTL_RESERVED_FOR_INTERNAL_REFERENCE		0x5C	//Root Control (Reserved for internal reference)
    #define D7F0_RSV_5C_5			0xFFE0	//0/R/x/x Reserved
    #define D7F0_RCCRSSVE			BIT4	//0/0/x/x Enable CRS Software Visibility 
    #define D7F0_RCPMEIE			BIT3	//0/0/x/x Enable PME Interrupt
    #define D7F0_RCSEFEE			BIT2	//0/0/x/x Enable System Error on Fatal Error
    #define D7F0_RCSENFEE			BIT1	//0/0/x/x Enable System Error on Non-Fatal Error
    #define D7F0_RCSECEE			BIT0	//0/0/x/x Enable System Error on Correctable Error
#define D7F0_ROOT_CAPS_RESERVED_FOR_INTERNAL_REFERENCE		0x5E	//Root Capabilities (Reserved for internal reference)
    #define D7F0_RSV_44_5E			0xFFFE	//0/R/x/x Reserved
    #define D7F0_RSCRSSFV			BIT0	//0/0/x/x Configuration Request Retry Status (CRS) Software Visibility
#define D7F0_ROOT_STA_RESERVED_FOR_INTERNAL_REFERENCE		0x60	//Root Status (Reserved for internal reference)
    #define D7F0_RSV_45			0xFFFC0000	//0/R/x/x Reserved
    #define D7F0_RSPP			BIT17	//HwInit/x/x/x PME Pending
    #define D7F0_RSPS			BIT16	//0/0/x/x PME Status
    #define D7F0_RSPRID			0xFFFF	//HwInit/x/x/x PME Requester ID
#define D7F0_DEV_CAPS_2		0x64	//Device Capabilities 2
    #define D7F0_RSV_64_6			0xFFF00000	//0/R/x/x Reserved
    #define D7F0_ROBFFSP			(BIT18 + BIT19)	//0/0/x/x OBFF Supported
    #define D7F0_RSV_64_12			0x3F000	//0/R/x/x Reserved
    #define D7F0_RLTRSP			BIT11	//0/0/x/x LTR Mechanism Supported
    #define D7F0_RSV_64_10			0x7C0	//0/x/x/x Reserved
    #define D7F0_RARISP			BIT5	//0/0/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define D7F0_TBD_31			BIT4	//0/1/x/x Completion Timeout Disable Supported
    #define D7F0_TBD_32			0xF	//0/R/x/x Completion Timeout Ranges Supported
#define D7F0_DEV_CTL_2		0x68	//Device Control 2
    #define D7F0_RSV_46			BIT15	//0/R/x/x Reserved
    #define D7F0_ROBFFEN			(BIT13 + BIT14)	//0/0/x/x OBFF Enable
    #define D7F0_RSV_68_11			(BIT11 + BIT12)	//0/R/x/x Reserved
    #define D7F0_RLTREN			BIT10	//0/0/x/x LTR Mechanism Enable
    #define D7F0_RSV_68_6			0x3C0	//0/R/x/x Reserved
    #define D7F0_RARIEN			BIT5	//0/0/x/x Enable ARI Forwarding
    #define D7F0_RDISCPLTM			BIT4	//0/0/0/x Completion Timeout  Disable Control
    #define D7F0_TBD_33			0xF	//0/R/x/x Completion Timeout Value
#define D7F0_DEV_STA_2		0x6A	//Device Status 2
    #define D7F0_RSV_47			0xFFFF	//0/R/x/x Reserved
#define D7F0_LINK_CAPS_2_RESERVED_FOR_INTERNAL_REFERENCE		0x6C	//Link Capabilities 2 (Reserved for internal reference)
    #define D7F0_RSV_6C_31			0xFFF80000	//0/R/x/x Reserved
    #define D7F0_RLOW_SKP_REC_SUPPORT			(BIT16 + BIT17 + BIT18)	//111b/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D7F0_RSV_6C_15			0xF000	//0/R/x/x Reserved
    #define D7F0_RLOW_SKP_GEN_SUPPORT			(BIT9 + BIT10 + BIT11)	//111b/x/x/x Lower SKP OS Generation Supported Speeds Vector
    #define D7F0_RSV_6C_8			BIT8	//0/R/x/x CrossLink Supported
    #define D7F0_LKMLS_6			BIT7	//0b/R/x/x Supported Link Speed Vector Bit 6
    #define D7F0_LKMLS_5			BIT6	//0b/R/x/x Supported Link Speed Vector Bit 5
    #define D7F0_LKMLS_4			BIT5	//0b/R/x/x Supported Link Speed Vector Bit 4
    #define D7F0_LKMLS_3			BIT4	//0b/R/x/x Supported Link Speed Vector Bit 3
    #define D7F0_LKMLS_2			BIT3	//1b/1b/x/x Supported Link Speed Vector Bit 2, 8.0GT/s
    #define D7F0_LKMLS_1			BIT2	//1b/1b/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define D7F0_LKMLS_0			BIT1	//1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s
    #define D7F0_RSV_6C_0			BIT0	//0/R/x/x Reserved
#define D7F0_LINK_CTL_2_D7F0_RESERVED_FOR_INTERNAL_REFERENCE		0x70	//Link Control 2 (D7F0) (Reserved for internal reference)
    #define D7F0_CMPPSDEEMPHS			0xF000	//0/0/x/x Compliance Preset/De-emphasis
    #define D7F0_RCMPSOS			BIT11	//0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define D7F0_PMDCMPSET			BIT10	//0/0/x/x Modified Compliance Pattern Set Bit
    #define D7F0_TXMGN_2			BIT9	//0/*0/x/x Transmit Voltage Margin Setting
    #define D7F0_TXMGN_1			BIT8	//0/*0/x/x Transmit Voltage Margin Setting
    #define D7F0_TXMGN_0			BIT7	//0/*0/x/x Transmit Voltage Margin Setting
    #define D7F0_SELDEEMPHS			BIT6	//0/*0/x/x Selectable De-emphasis
    #define D7F0_RHATNMSD			BIT5	//0/0/x/0 Disable Hardware Autonomous Speed
    #define D7F0_PCMPSET			BIT4	//0/0/x/x Enter Compliance
    #define D7F0_LKTGLS_3			BIT3	//0/0/0/0 Target Link Speed Bit 3
    #define D7F0_LKTGLS_2			BIT2	//0/0/0/0 Target Link Speed Bit 2
    #define D7F0_LKTGLS_1			BIT1	//0/0/0/0 Target Link Speed Bit 1
    #define D7F0_LKTGLS_0			BIT0	//1b/1/1/1 Target Link Speed Bit 0
#define D7F0_LINK_STA_2RESERVED_FOR_INTERNAL_REFERENCE		0x72	//Link Status 2(Reserved for internal reference)
    #define D7F0_RSV_49			0xFFC0	//0/R/x/x Reserved
    #define D7F0_EQREQ			BIT5	//0/x/x/x Request Link Equalization Process
    #define D7F0_EQCOMPLE3			BIT4	//HwInit/x/x/x Phase 3 Transmitter Equalization Procedure Completion
    #define D7F0_EQCOMPLE2			BIT3	//HwInit/x/x/x Phase 2 of the Transmitter Equalization Procedure Completion
    #define D7F0_EQCOMPLE1			BIT2	//HwInit/x/x/x Phase 1 of the Transmitter Equalization Procedure Completion
    #define D7F0_EQCOMPLE			BIT1	//HwInit/x/x/x Transmitter Equalization Procedure Completion
    #define D7F0_CURDEEMPHS			BIT0	//HwInit/x/x/x Current Link De-emphasis Level
#define D7F0_SLOT_CAPS_2RESERVED_FOR_INTERNAL_REFERENCE		0x74	//Slot Capabilities 2(Reserved for internal reference)
    #define D7F0_RSV_50			0xFFFFFFFF	//0/R/x/x Reserved
#define D7F0_SLOT_CTL_2RESERVED_FOR_INTERNAL_REFERENCE		0x78	//Slot Control 2(Reserved for internal reference)
    #define D7F0_RSV_51			0xFFFF	//0/R/x/x Reserved
#define D7F0_SLOT_STA_2RESERVED_FOR_INTERNAL_REFERENCE		0x7A	//Slot Status 2(Reserved for internal reference)
    #define D7F0_RSV_52			0xFFFF	//0/R/x/x Reserved
#define D7F0_VENDOR_CTLRESERVED_FOR_INTERNAL_REFERENCE		0x7C	//Vendor Control(Reserved for internal reference)
    #define D7F0_RSV_7C			0xFFFFFFFC	//0/R/x/x Reserved
    #define D7F0_DID_RID_LOCK_BIT			BIT1	//0/0/x/x Reserved
    #define D7F0_D7F0_VID_DID_LOCK_BIT			BIT0	//0/x/x/x Reserved
#define D7F0_PM_CAPS		0xA0	//Power Management Capabilities
    #define D7F0_PMCPME			0xF8000000	//0/0/x/x PME Support
    #define D7F0_PMCD2S			BIT26	//0/0/x/x D2 Support
    #define D7F0_PMCD1S			BIT25	//0/0/x/x D1 Support
    #define D7F0_PMCAUXC			(BIT22 + BIT23 + BIT24)	//0/0/x/x AUX Current
    #define D7F0_PMCDSI			BIT21	//1b/1/x/x Device Specific Initialization
    #define D7F0_RSV_53			(BIT19 + BIT20)	//0/R/x/x Reserved
    #define D7F0_TBD_34			(BIT16 + BIT17 + BIT18)	//010b/R/x/x Version
    #define D7F0_TBD_35			0xFF00	//0/0/x/x Next Capability Pointer
    #define D7F0_TBD_36			0xFF	//01h/R/x/x Capability ID
#define D7F0_PM_STA_CTL		0xA4	//Power Management Status / Control
    #define D7F0_TBD_37			0xFF000000	//0/R/x/x Power Management Data
    #define D7F0_TBD_38			BIT23	//0/x/x/x Enable Bus Power / Clock Control
    #define D7F0_TBD_39			BIT22	//0/x/x/x B2 / B3 Support
    #define D7F0_RSV_54			0x3F0000	//0/R/x/x Reserved
    #define D7F0_PMESD			BIT15	//0/0/x/x PME Status
    #define D7F0_TBD_40			(BIT13 + BIT14)	//0/R/x/x Data Scale
    #define D7F0_TBD_41			0x1E00	//0/R/x/x Data Select
    #define D7F0_PMEEN			BIT8	//0/0/x/x PME Enable
    #define D7F0_RSV_55			0xFC	//0/R/x/x Reserved
    #define D7F0_PWSD			(BIT0 + BIT1)	//00b/0/x/x Power State
#define D7F0_RESERVED_Z3		0xD0	//Reserved
    #define D7F0_RSV_D3			0xFFFFFFFF	//0/R/x/x Reserved
#define D7F0_RESERVED_Z4		0xD4	//Reserved
    #define D7F0_RSV_D5			0xFFFFFFFF	//0/x/x/x Reserved
#define D7F0_ADVANCED_ERR_REPORTING_ENHANCED_CAP_HEADER		0x100	//Advanced Error Reporting Enhanced Capability Header
    #define D7F0_TBD_54			0xFFF00000	//0/0/x/x Next Capability Offset
    #define D7F0_TBD_55			0xF0000	//1h/R/x/x Capability Version
    #define D7F0_TBD_56			0xFFFF	//0001h/R/x/x PCI Express Extended Capability ID
#define D7F0_UNCORRECTABLE_ERR_STA		0x104	//Uncorrectable Error Status
    #define D7F0_RSV_59			0xFFC00000	//0/R/x/x Reserved
    #define D7F0_UEACSVIO			BIT21	//0/R/x/x ACS Violation Status (TL)
    #define D7F0_UESUR			BIT20	//0/0/x/x Unsupported Request Error Status (TL)
    #define D7F0_UESECRC			BIT19	//0/0/x/x ECRC Error Status (TL)
    #define D7F0_UESMTLP			BIT18	//0/0/x/x Malformed TLP Status (TL)
    #define D7F0_UESRO			BIT17	//0/0/x/x Receiver Overflow Status (TL)
    #define D7F0_UESUC			BIT16	//0/0/x/x Unexpected Completion Status (TL) *
    #define D7F0_UESCA			BIT15	//0/0/x/x Completer Abort Status (TL)
    #define D7F0_UESCT			BIT14	//0/0/x/x Completion Timeout Status (TL) *
    #define D7F0_UESFCP			BIT13	//0/0/x/x Flow Control Protocol Error Status (TL)
    #define D7F0_UESPTLP			BIT12	//0/0/x/x Poisoned TLP Status (TL) *
    #define D7F0_RSV_60			0xFC0	//0/R/x/x Reserved
    #define D7F0_RUESSDES			BIT5	//0/0/x/x Surprise Down Error Status
    #define D7F0_UESDLP			BIT4	//0/0/x/x Data Link Protocol Error Status (DLL)
    #define D7F0_RSV_61			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D7F0_UEST			BIT0	//0/0/x/x Training Error Status (PHY)
#define D7F0_UNCORRECTABLE_ERR_MASK		0x108	//Uncorrectable Error Mask
    #define D7F0_RSV_1100			0xFFC00000	//0/R/x/x Reserved
    #define D7F0_UEMACSVIO			BIT21	//0/R/x/x ACS Violation Mask (TL)
    #define D7F0_UEMUR			BIT20	//0/0/x/x Unsupported Request Error Mask (TL) *
    #define D7F0_UEMECRC			BIT19	//0/0/x/x ECRC Error Mask (TL)
    #define D7F0_UEMMTLP			BIT18	//0/0/x/x Malformed TLP Mask (TL) *
    #define D7F0_UEMRO			BIT17	//0/0/x/x Receiver Overflow Mask (TL) *
    #define D7F0_UEMUC			BIT16	//0/0/x/x Unexpected Completion Mask (TL) *
    #define D7F0_UEMCA			BIT15	//0/0/x/x Completed Abort Mask (TL)
    #define D7F0_UEMCT			BIT14	//0/0/x/x Completion Timeout Mask (TL) *
    #define D7F0_UEMFCP			BIT13	//0/0/x/x Flow Control Protocol Error Mask (TL) *
    #define D7F0_UEMPTLP			BIT12	//0/0/x/x Poisoned TLP Mask (TL) *
    #define D7F0_RSV_1101			0xFC0	//0/R/x/x Reserved
    #define D7F0_RUEMSDEM			BIT5	//0/0/x/x Surprise Down Error Mask (DLL) *
    #define D7F0_UEMDLP			BIT4	//0/0/x/x Data Link Protocol Error Mask (DLL) *
    #define D7F0_RSV_62			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D7F0_UEMST			BIT0	//0/0/x/x Training Error Mask (PHY) *
#define D7F0_UNCORRECTABLE_ERR_SEVERITY		0x10C	//Uncorrectable Error Severity
    #define D7F0_RSV_63			0xFFC00000	//0/R/x/x Reserved
    #define D7F0_USVACSVIO			BIT21	//0/R/x/x ACS Violation Severity (TL)
    #define D7F0_USVUR			BIT20	//0/0/x/x Unsupported Request Error Severity (TL) *
    #define D7F0_USVECRC			BIT19	//0/0/x/x ECRC Error Severity (TL)
    #define D7F0_USVMTLP			BIT18	//1b/1/x/x Malformed TLP Severity (TL) *
    #define D7F0_USVRO			BIT17	//1b/1/x/x Receiver Overflow Error Severity (TL) *
    #define D7F0_USVUC			BIT16	//0/0/x/x Unexpected Completion Error Severity (TL) *
    #define D7F0_USVCA			BIT15	//0/0/x/x Completed Abort Error Severity (TL)
    #define D7F0_USVCT			BIT14	//0/0/x/x Completion Timeout Error Severity (TL) *
    #define D7F0_USVFCP			BIT13	//1b/1/x/x Flow Control Protocol Error Severity (TL) *
    #define D7F0_USVPTLP			BIT12	//0/0/x/x Poisoned TLP Severity (TL) *
    #define D7F0_RSV_64			0xFC0	//0/R/x/x Reserved
    #define D7F0_RUSVSDES			BIT5	//1b/1/x/x Surprise Down Error Severity *
    #define D7F0_USVDLP			BIT4	//1b/1/x/x Data Link Protocol Error Severity (DLL) *
    #define D7F0_RSV_65			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D7F0_USVT			BIT0	//1b/1/x/x Training Error Severity (PHY) *
#define D7F0_CORRECTABLE_ERR_STA		0x110	//Correctable Error Status
    #define D7F0_RSV_66			0xFFFFC000	//0/R/x/x Reserved
    #define D7F0_RCESANFES			BIT13	//0/0/x/x Advisory Non-Fatal Error Status
    #define D7F0_CRRTT			BIT12	//0/0/x/x Replay Timer Timeout Status (DLL)
    #define D7F0_RSV_67			(BIT9 + BIT10 + BIT11)	//0/R/x/x Reserved
    #define D7F0_CRRR			BIT8	//0/0/x/x REPLAY_NUM Rollover Status (DLL)
    #define D7F0_CRBDLLP			BIT7	//0/0/x/x Bad Data Link Layer Packet (DLLP) Status (DLL)
    #define D7F0_CRBTLP			BIT6	//0/0/x/x Bad TLP Status (DLL)
    #define D7F0_RSV_68			0x3E	//0/R/x/x Reserved
    #define D7F0_CRRCVR			BIT0	//0/0/x/x Receiver Error Status (PHY)
#define D7F0_CORRECTABLE_ERR_MASK		0x114	//Correctable Error Mask
    #define D7F0_RSV_69			0xFFFFC000	//0/R/x/x Reserved
    #define D7F0_RCEMANFEM			BIT13	//1b/1/x/x Advisory Non-Fatal Error Mask *
    #define D7F0_CMRTT			BIT12	//0/0/x/x Replay Timer Timeout Mask (DLL) *
    #define D7F0_RSV_70			(BIT9 + BIT10 + BIT11)	//0/R/x/x Reserved
    #define D7F0_CMRR			BIT8	//0/0/x/x REPLAY_NUM Rollover Mask (DLL) *
    #define D7F0_CMBDLLP			BIT7	//0/0/x/x Bad DLLP Mask (DLL) *
    #define D7F0_CMBTLP			BIT6	//0/0/x/x Bad TLP Mask (DLL) *
    #define D7F0_RSV_71			0x3E	//0/R/x/x Reserved
    #define D7F0_CMRCVR			BIT0	//0/0/x/x Receiver Error Mask (PHY) *
#define D7F0_ADVANCED_ERR_CAPS_AND_CTL		0x118	//Advanced Error Capabilities and Control
    #define D7F0_RSV_72			0xFFFFFE00	//0/R/x/x Reserved
    #define D7F0_ECRCCHKEN			BIT8	//0/0/x/x ECRC Check Enable (TL)
    #define D7F0_ECRCCHKCA			BIT7	//0/R/x/x ECRC Check Capable (TL)
    #define D7F0_ECRCGENEN			BIT6	//0/0/x/x ECRC Generation Enable (TL)
    #define D7F0_ECRCGENCA			BIT5	//0/R/x/x ECRC Generation Capable (TL)
    #define D7F0_ECRCFEPTR			0x1F	//0/0/x/x First Error Pointer (TL)
#define D7F0_HEADER_LOG_1ST_DW		0x11C	//Header Log 1st DW
    #define D7F0_HLR1			0xFFFFFFFF	//0/R/x/x Header Log Register 1st DW
#define D7F0_HEADER_LOG_2ND_DW		0x120	//Header Log 2nd DW
    #define D7F0_HLR2			0xFFFFFFFF	//0/R/x/x Header Log Register 2nd DW
#define D7F0_HEADER_LOG_3RD_DW		0x124	//Header Log 3rd DW
    #define D7F0_HLR3			0xFFFFFFFF	//0/R/x/x Header Log Register 3rd DW
#define D7F0_HEADER_LOG_4TH_DW		0x128	//Header Log 4th DW
    #define D7F0_HLR4			0xFFFFFFFF	//0/R/x/x Header Log Register 4th DW
#define D7F0_ROOT_ERR_CMD		0x12C	//Root Error Command
    #define D7F0_RSV_73			0xFFFFFFF8	//0/R/x/x Reserved
    #define D7F0_RECF			BIT2	//0/0/x/x Enable Fatal Error Reporting *
    #define D7F0_RECNF			BIT1	//0/0/x/x Enable Non-Fatal Error Reporting *
    #define D7F0_RECC			BIT0	//0/0/x/x Enable Correctable Error Reporting *
#define D7F0_ROOT_ERR_STA		0x130	//Root Error Status
    #define D7F0_RESAEIMN			0xF8000000	//0/x/x/x Advanced Error Interrupt Message Number (TL)
    #define D7F0_RSV_74			0x7FFFF80	//0/R/x/x Reserved
    #define D7F0_RESFRV			BIT6	//0/0/x/x Fatal Error Messages Received (TL)
    #define D7F0_RESNFRV			BIT5	//0/0/x/x Non-Fatal Error Messages Received (TL)
    #define D7F0_RESFFRV			BIT4	//0/0/x/x First Uncorrectable Fatal Error Message Received (TL)
    #define D7F0_RESMF			BIT3	//0/0/x/x Multiple ERR_FATAL/NONFATAL Received (TL)
    #define D7F0_RESSF			BIT2	//0/0/x/x ERR_FATAL/NONFATAL Received (TL)
    #define D7F0_RESMC			BIT1	//0/0/x/x Multiple ERR_COR Received (TL)
    #define D7F0_RESSC			BIT0	//0/0/x/x ERR_COR Received (TL)
#define D7F0_ERR_SRC_IDENTIFICATION		0x134	//Error Source Identification
    #define D7F0_ESIF			0xFFFF0000	//0/R/x/x ERR_FATAL / NONFATAL Source Identification (TL)
    #define D7F0_ESIC			0xFFFF	//0/R/x/x ERR_COR Source Identification (TL)
#define D7F0_ERR_SRC_IDENTIFICATION_Z1		0x138	//Error Source Identification
    #define D7F0_RSV_138			0xFE	//0/x/x/x Reserved
    #define D7F0_RVPILMCARPTEN			BIT0	//1b/1b/x/x MCA ERROR Report Enable
#define D7F0_RESERVED_Z5		0x139	//Reserved
    #define D7F0_RSV_139			0xFF	//0/x/x/x Reserved
#define D7F0_RESERVED_Z6		0x13A	//Reserved
    #define D7F0_RSV_13A			0xFF	//0/x/x/x Reserved
#define D7F0_RESERVED_Z7		0x13B	//Reserved
    #define D7F0_RSV_13B			0xFF	//0/x/x/x Reserved
#define D7F0_ROOT_COMPLEX_LINK_DECLARATION_CAPS_HEADER		0x170	//Root Complex Link Declaration Capabilities Header
    #define D7F0_RX170_31_20			0xFFF00000	//0/R/x/x Next Capability Offset
    #define D7F0_RX170_19_16			0xF0000	//1h/R/x/x Capability Version
    #define D7F0_RX170_15_0			0xFFFF	//0005h/R/x/x PCI Express Extended Capability ID
#define D7F0_ELEMENT_SELF_DESCRIPTION_D7F0		0x174	//Element Self Description (D7F0)
    #define D7F0_RX174_31_24			0xFF000000	//01h/01h/x/x Port Number 
    #define D7F0_RX174_23_16			0xFF0000	//01h/01h/x/x Component ID
    #define D7F0_RX174_15_8			0xFF00	//01h/01h/x/x Number of Link Entries
    #define D7F0_RX174_7_4			0xF0	//0/x/x/x Reserved
    #define D7F0_RX174_3_0			0xF	//0/x/x/x Element Type
#define D7F0_UPSTREAM_LINK_DESCRIPTOR		0x180	//Upstream Link Descriptor
    #define D7F0_RX180_31_24			0xFF000000	//00h/00h/x/x Target Port Number
    #define D7F0_RX180_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define D7F0_RX180_15_3			0xFFF8	//0/0/x/x Reserved
    #define D7F0_RX180_2			BIT2	//0/0/x/x Associate RCRB Header
    #define D7F0_RX180_1			BIT1	//0/0/x/x Link Type
    #define D7F0_RX180_0			BIT0	//1b/1/x/x Link Valid
#define D7F0_UPSTREAM_LINK_LOWER_BASE_ADR_FOR_RCRB_H_63_12		0x188	//Upstream Link Lower Base Address for RCRB-H[63:12]
    #define D7F0_RXRCRBHA_31_12			0xFFFFF000	//0/x/x/x Lower Link Address Bit[31:12]
    #define D7F0_RX188_11_0			0xFFF	//0/x/x/x Lower Link Address Bit[11:0]
#define D7F0_UPSTREAM_LINK_UPPER_BASE_ADR_FOR_RCRB_H_63_12		0x18C	//Upstream Link Upper Base Address for RCRB-H[63:12]
    #define D7F0_RX18C_31_4			0xFFFFFF00	//0/x/x/x Upper Link Address Bit[63:40]
    #define D7F0_RXRCRBHA_39_32			0xFF	//0/x/x/x Upper Link Address Bit[39:32]
#define D7F0_GENERAL_CTL_1		0x1C0	//General Control 1
    #define D7F0_QKTMOUT			BIT7	//0/0/x/x Quick Timeout Counter Setting
    #define D7F0_DIS_SCRMBL			BIT6	//0/0/x/x Disable Data Scrambling / Descrambling
    #define D7F0_LPBK_SEL			(BIT3 + BIT4 + BIT5)	//000b/0/x/x Loopback Mode Selection
    #define D7F0_COMDET_WINDOW			(BIT0 + BIT1 + BIT2)	//011b/011b/x/x COMMA Detection Window
#define D7F0_GENERAL_CTL_2		0x1C1	//General Control 2
    #define D7F0_RSV_1C1_7			BIT7	//0/0/x/x Reserved
    #define D7F0_RHATNMWE			BIT6	//0/0/x/x Reserved
    #define D7F0_RHATNMSE			BIT5	//1b/1b/x/x Enable Hardware Autonomous Speed
    #define D7F0_SKPNEGO			0x1F	//00000b/0/x/x PHY Lane Configuration Setting
#define D7F0_MAC_AND_PCS		0x1C2	//MAC and PCS
    #define D7F0_REBRSTEN			BIT7	//1b/1/x/x Enable Reset of Elastic Buffer When Rx1C3 ((PHYLS_STATE)) Is in the State of No Need to Transferring Data
    #define D7F0_RSTRXEB			BIT6	//0/0/x/x Reset Elastic Buffer; Reserved
    #define D7F0_RLNRDTOEN			BIT5	//0/x/x/x Reserved
    #define D7F0_RCVDOUT_SET			BIT4	//0/0/x/x Bypass PHYES Device Detection in Detect Phase of LTSSM
    #define D7F0_RPOLL24MS			BIT3	//0/0/x/x State Machine LTSSM Exit Polling.Active
    #define D7F0_RIGNIDL			BIT2	//1b/1/x/x Wait IDL Ordered Set or Electrical Idle When L1/L23 Entry
    #define D7F0_RRDCHKEN			BIT1	//1b/1/x/x Enable Disparity Check
    #define D7F0_RDET12MS			BIT0	//1b/1/x/x State Machine ???Link Training and Status State Machine (LTSSM)??ид Control 
#define D7F0_PHYLS_LTSSM_STATE		0x1C3	//PHYLS LTSSM State
    #define D7F0_PHYLS_STATE			0xFF	//HwInit/x/x/x PHYLS LTSSM State
#define D7F0_EB_BASE_CTL		0x1C4	//EB_BASE Control
    #define D7F0_RSV_1C4			0xFFFFF000	//0/0/x/x Reserved
    #define D7F0_RSV_1C4_11			BIT11	//0/0/x/x Reserved
    #define D7F0_EB_BASE_G3			(BIT8 + BIT9 + BIT10)	//110b/110b/x/x Gen3 TX Asynchronous FIFO Base
    #define D7F0_RSV_1C4_7			BIT7	//0/0/x/x Reserved
    #define D7F0_EB_BASE_G2			(BIT4 + BIT5 + BIT6)	//110b/110b/x/x Gen2 TX Asynchronous FIFO Base
    #define D7F0_RSV_1C4_3			BIT3	//0/0/x/x Reserved
    #define D7F0_EB_BASE_G1			(BIT0 + BIT1 + BIT2)	//011b/011b/x/x Gen1 TX Asynchronous FIFO Base
#define D7F0_SKP_ORDERED_SET_CTL		0x1C8	//SKP Ordered Set Control
    #define D7F0_RDEVDISCRMEN			BIT7	//0/0/x/x Enable Device Issuing Disable Scrambling Capability
    #define D7F0_R64TS2SEND			BIT6	//0/0/x/x TS2 Send Control during Speed Change
    #define D7F0_RSPEEDWAIT			BIT5	//0/0/x/x Wait EIOS before Change State from Recovery_RcvrCfg to Recovery_Speed
    #define D7F0_RDSKWERREN			BIT4	//0/0/x/x Deskew Error Report Enable
    #define D7F0_RDISRCVR			BIT3	//1b/1/x/x Disable Receiver Error Report 
    #define D7F0_RFIXSCRMBLDIS			BIT2	//0/0/x/x Link Scramble Disable Bit Sampled Control
    #define D7F0_R1530SKP			BIT1	//0/0/x/x Enable SKP Ordered-Set Scheduling of 4.72us or 6.12us
    #define D7F0_R118SKP			BIT0	//0/0/x/x Enable SKP Ordered-Set Scheduling to Match the Clock Difference of 5600ppm
#define D7F0_UNRELIABLE_LINK_STA		0x1C9	//Unreliable Link Status
    #define D7F0_TBD_1C9_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D7F0_UNRL_X8			BIT4	//HwInit/x/x/x X8 Link Width Unreliable Status
    #define D7F0_UNRL_X4			BIT3	//HwInit/x/x/x X4 Link Width Unreliable Status
    #define D7F0_UNRL_X2			BIT2	//HwInit/x/x/x X2 Link Width Unreliable Status
    #define D7F0_UNRL_G3			BIT1	//HwInit/x/x/x Gen3 Link Speed Unreliable Status
    #define D7F0_UNRL_G2			BIT0	//HwInit/x/x/x Gen2 Link Speed Unreliable Status
#define D7F0_RESERVED_Z8		0x1CA	//Reserved
    #define D7F0_TBD_1CB			0xFFFF	//0/R/x/x Reserved
#define D7F0_SYSTEM_DEBUG_REG_D7F0_D3F0		0x1CC	//System Debug Register (D7F0, D3F0)
    #define D7F0_RSV_137			BIT7	//0/R/x/x Reserved
    #define D7F0_RDESKEW			(BIT4 + BIT5 + BIT6)	//HwInit/x/x/x The De-skew Result from the Lane Selected by LANESEL
    #define D7F0_RSV_138_Z1			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D7F0_RTBEBERR			BIT0	//0/0/x/x The 10b/8b Decode Error Status from the Lane Selected by LANESEL
#define D7F0_MAC		0x1CD	//MAC
    #define D7F0_RFTSTR			(BIT6 + BIT7)	//0/0/x/x Number of FTS Ordered Sent in L0s Exit Sequence with N_FTS in the Received Training Sequence
    #define D7F0_RSKPSPD			BIT5	//0/0/x/x Skip Speed Negotiation and Get to Target Speed Directly
    #define D7F0_RLNRVSL			BIT4	//0/0/x/x Lane Reversal Support
    #define D7F0_RWDCONFIG			BIT3	//0/0/x/1 Support Width Change in Configuration State 
    #define D7F0_RSV_1CD_2			BIT2	//0/0/x/x Reserved
    #define D7F0_RINFEIDL			BIT1	//1b/1/x/x Inferred Electrical Idle
    #define D7F0_RQKTXG			BIT0	//0/0/1/x Downstream TX Arbitration between DLLM and PHYLS
#define D7F0_PCS_AND_PMA_1		0x1CE	//PCS and PMA 1
    #define D7F0_RSPDP0			BIT7	//0/0/x/x Transmitter Power State Setting When Link Speed Is Changed
    #define D7F0_RVCOSTB			(BIT4 + BIT5 + BIT6)	//001b/1/x/x CDR VCO Stabilization Time
    #define D7F0_DRTERM			BIT3	//0/0/x/x Receiver Termination Disable
    #define D7F0_RLOWSWN			BIT2	//0/*0/x/x Enable Low Swing Mode 
    #define D7F0_RQKALGN			BIT1	//0/0/1/x Quick Byte Alignment Support
    #define D7F0_RQKCNV			BIT0	//0/0/1/x Quick Phase Conversion Support
#define D7F0_PCS_AND_PMA_2		0x1CF	//PCS and PMA 2
    #define D7F0_RSV_159			0xFC	//0/0/x/x Reserved
    #define D7F0_ENDEEMPHS			BIT1	//0/*0/x/x Enforce De-emphasis Level with Selectable De-emphasis Value
    #define D7F0_RFLOWSWN			BIT0	//0/*0/x/x Far-End Low Swing Adjustment
#define D7F0_PM_UNIT_PMU_CTL		0x1D0	//Power Management Unit (PMU) Control
    #define D7F0_RATREQEN			BIT7	//0/0/x/x Enable PHY Layer Automatic Change Speed / Width Request
    #define D7F0_RPTOFF			(BIT4 + BIT5 + BIT6)	//101b/101b/x/x Timeout Period
    #define D7F0_RSPDCLRPM			BIT3	//1b/1/x/x Enable Clearing the PM Cycles Requested by the Device in Speed Negotiation Process
    #define D7F0_RBDLLPEN			BIT2	//1b/1/x/x Retrain Link When Bad DLLP Is Checked
    #define D7F0_LCLPBK			BIT1	//0/0/x/x Link Loopback
    #define D7F0_LCRCNFG			BIT0	//0/0/x/x Link Reconfigure Link Width
#define D7F0_PMU_TIMEOUT_AND_PMU_CTL		0x1D1	//PMU Timeout and PMU Control
    #define D7F0_UFTMERR			BIT7	//0/x/x/x Error Status Report When Entering L1 Fails
    #define D7F0_RSV_144			BIT6	//0/0/x/x Reserved
    #define D7F0_UFTIME			(BIT4 + BIT5)	//11b/11b/x/x Electrical Idle Waiting Period before Moving to L1 State (after issue ACK to the L1 request from the device).
    #define D7F0_RPMUERRRETRAINEN			BIT3	//1b/1/x/x Enable PMU Initiate Error Recovery
    #define D7F0_RPMACKL1			BIT2	//0/0/x/x Enable PM_Request_Ack DLLP Generation When the CPL TLP Is Put Inside PM_Enter_L1 Sequences; Reserved
    #define D7F0_RPMETOFF			BIT1	//0/0/x/x Triggering Sending PME_TURN_OFF Messages
    #define D7F0_RPMEACK			BIT0	//0/0/x/x PME_TO_ACK Acknowledge Status for VPIL Master
#define D7F0_PMU_L0S_IDLE_TIMEOUT		0x1D2	//PMU L0s Idle Timeout
    #define D7F0_L0SLIM			0xFF	//07h/07h/ffh/0 L0s Timer Limitation
#define D7F0_PMU_L1_IDLE_TIMEOUT		0x1D3	//PMU L1 Idle Timeout
    #define D7F0_ASL1LIM			0xFF	//0Fh/0fh/ffh/0 Active State L1 Timer Limitation
#define D7F0_PMC_EXPRESS_MSG_STA		0x1D8	//PMC Express Message Status
    #define D7F0_RR2AER			BIT7	//0/R/x/x Reserved
    #define D7F0_RCFGCPLFLUSHMSI			BIT6	//1b/1b/x/x RCFGCPLFlushMSI
    #define D7F0_RUNRL_MCA_UC_EN			BIT5	//0/0/x/x The Link Unreliable Report as Correctable or Un-Correctable
    #define D7F0_RDIS_MESC_WK			BIT4	//0/0/0/0 PCIe Wakeup C4P Control
    #define D7F0_RSV_146			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define D7F0_RMSGSIMT			BIT0	//0/0/x/x VPIL MSGC Timer Value for Simulation
#define D7F0_VPIL_MSI_TIMEOUT_CTL		0x1D9	//VPIL MSI Timeout Control
    #define D7F0_RVPILMSITOEN			BIT7	//0/0/x/x VPIL MSI Timeout Enable
    #define D7F0_RVPILMSITIMERV			0x7F	//0/0/x/x VPIL MSI Timeout Timer
#define D7F0_VPIL_SMI_NMI_SCI_CTL_1		0x1DA	//VPIL SMI/NMI/SCI Control 1
    #define D7F0_CORERR_SMI_EN			BIT7	//0/0/x/x Correctable Error Mapping to SMI Enable
    #define D7F0_CORERR_NMI_EN			BIT6	//0/0/x/x Correctable Error Mapping to NMI Enable
    #define D7F0_CORERR_SCI_EN			BIT5	//0/0/x/x Correctable Error Mapping to SCI Enable
    #define D7F0_NFTERR_SMI_EN			BIT4	//0/0/x/x Non Fatal Error Mapping to SMI Enable
    #define D7F0_NFTERR_NMI_EN			BIT3	//0/0/x/x Non Fatal Error Mapping to NMI Enable
    #define D7F0_NFTERR_SCI_EN			BIT2	//0/0/x/x Non Fatal Error Mapping to SCI Enable
    #define D7F0_FTERR_SMI_EN			BIT1	//0/0/x/x Fatal Error Mapping to SMI Enable
    #define D7F0_FTERR_NMI_EN			BIT0	//0/0/x/x Fatal Error Mapping to NMI Enable
#define D7F0_VPIL_SMI_NMI_SCI_CTL_2		0x1DB	//VPIL SMI/NMI/SCI Control 2
    #define D7F0_FTERR_SCI_EN			BIT7	//0/0/x/x Fatal Error Mapping to SCI Enable
    #define D7F0_RVPIL_ERR_EBMC_EN			BIT6	//0/0/x/x Report VPIL Error to SME Enable
    #define D7F0_RSV_1DB5			BIT5	//0/0/x/x Reserved
    #define D7F0_RSV_1DB			0x1F	//0/0/x/x Reserved
#define D7F0_VPIL_REQ_ID		0x1DC	//VPIL Request ID
    #define D7F0_RVPISID			0xFFFF	//38h/38h/x/x VPIL Request ID
#define D7F0_VPIL_REQ_ID_Z1		0x1DE	//VPIL Request ID
    #define D7F0_LKBWCHG_SMI_EN			BIT15	//0/0/x/x Link Bandwidth Change Mapping to SMI Enable
    #define D7F0_LKBWCHG_NMI_EN			BIT14	//0/0/x/x Link Bandwidth Change Mapping to NMI Enable
    #define D7F0_LKBWCHG_SCI_EN			BIT13	//0/0/x/x Link Bandwidth Change Mapping to SCI Enable
    #define D7F0_DLSCHG_SMI_EN			BIT12	//0/0/x/x Link State Change Mapping to SMI Enable
    #define D7F0_DLSCHG_NMI_EN			BIT11	//0/0/x/x Link State Change Mapping to NMI Enable
    #define D7F0_DLSCHG_SCI_EN			BIT10	//0/0/x/x Link State Change Mapping to SCI Enable
    #define D7F0_EQREQ_SMI_EN			BIT9	//0/0/x/x EQREQ Mapping to SMI Enable
    #define D7F0_EQREQ_NMI_EN			BIT8	//0/0/x/x EQREQ Change Mapping to NMI Enable
    #define D7F0_EQREQ_SCI_EN			BIT7	//0/0/x/x EQREQ Change Mapping to SCI Enable
    #define D7F0_RSV_1DE6_1			0x7E	//0/0/x/x Reserved
    #define D7F0_RVPISID_LOCK_BIT			BIT0	//0/x/x/x VPIL Request ID Lock Bit
#define D7F0_TARGET_LINK_WIDTH_D7F0		0x1E0	//Target Link Width (D7F0)
    #define D7F0_RSV_1E0			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D7F0_LKTLW_4			BIT4	//HwInit/x/x/x Target Link Width Bit 4
    #define D7F0_LKTLW_3			BIT3	//HwInit/x/x/x Target Link Width Bit 3
    #define D7F0_LKTLW_2			BIT2	//0/0/x/x Target Link Width Bit 2
    #define D7F0_LKTLW_1			BIT1	//0/0/x/x Target Link Width Bit 1
    #define D7F0_LKTLW_0			BIT0	//0/0/x/x Target Link Width Bit 0
#define D7F0_PERCENTAGE_OF_NON_IDLE_PNI_CNTER_SETTING		0x1E1	//Percentage of Non-Idle (PNI) Counter Setting
    #define D7F0_RPNISTLM			0xF0	//0001b/1/x/x Delay Duration that the PNI Counter Will Start After Entering L0 State(Reserved)
    #define D7F0_RPNIDUR			0xF	//0010b/0010b/x/x Evaluation Period of PNI Calculation(Reserved)
#define D7F0_PNI_ALGORITHM_SETTINGS		0x1E2	//PNI Algorithm Settings
    #define D7F0_RPNI90CL			0xF0	//0010b/0010b/0/11 Logic Idle Percentage of PNI_90 Calculation(Reserved)
    #define D7F0_RPNI30CL			0xF	//0010b/0010b/11/0 Logic Idle Percentage of PNI_30 Calculation(Reserved)
#define D7F0_GEN2_MAC_ENHANCEMENT		0x1E3	//GEN2 MAC Enhancement
    #define D7F0_RCMPRCV			BIT7	//0/0/x/x Compliance Receive Bit Setting in Transmitting TS1 Ordered Sets
    #define D7F0_RUPMAXCFG			BIT6	//0/0/1/0 Link Width Selection
    #define D7F0_REQLZTM			(BIT4 + BIT5)	//10b/10b/x/x Equalizer Tuning Timeout Setting
    #define D7F0_RPDDNCFG			BIT3	//0/0/x/1 Power Down Unintended TX to Down Configure Link Width When LTSSM Is in Configuration State
    #define D7F0_RDOWNCFG			BIT2	//1b/1/x/x Electrical Idle Detection Behavior in Inactive Lanes When LTSSM Is in Configuration.Linkwidth.Start State
    #define D7F0_RIGNEQLZ			BIT1	//0/0/x/x Waiting Condition of Equalizer Tuning Timeout When LTSSM Is to Be Changed:
    #define D7F0_RWDEARLY			BIT0	//1b/1/x/x Enable of TXs in Inactive Lanes to Upconfigure Link Width When LTSSM Is in Configuration and Recovery State
#define D7F0_SPEED_MANAGEMENT		0x1E4	//Speed Management
    #define D7F0_RSPFLCLR			BIT7	//0/0/x/x Reserved
    #define D7F0_RSCFLSET			0x7F	//00h/0/x/x Number of Permitted Speed Negotiation
#define D7F0_LINK_WIDTH_NEGOTIATION		0x1E5	//Link Width Negotiation
    #define D7F0_RWDFLCLR			BIT7	//0/0/x/x Reserved
    #define D7F0_RWCFLSET			0x7F	//0/0/x/x Number of Permitted Link Width Negotiation
#define D7F0_LINK_BANDWIDTH_CHANGE_FAIL_STA_D7F0		0x1E6	//Link Bandwidth Change Fail Status (D7F0)
    #define D7F0_RSV_1E6			BIT7	//0/0/x/x Reserved
    #define D7F0_WDFLX8			BIT6	//HwInit/x/x/x Internal ???width_fail_field??ид Status for X8 Link width.
    #define D7F0_WDFLX4			BIT5	//HwInit/x/x/x Internal ???width_fail_field??ид Status for X4 Link width.
    #define D7F0_WDFLX2			BIT4	//HwInit/x/x/x Internal ???width_fail_field??ид Status for X2 Link width.
    #define D7F0_RSV_1E6_1			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define D7F0_SPFLG2			BIT0	//HwInit/x/x/x Internal ???speed_fail_field??ид Status for Gen2 Link speed.
#define D7F0_BANDWIDTH_PWR_ARBITRATION		0x1E7	//Bandwidth Power Arbitration
    #define D7F0_RSV_1E7			0xFE	//0/0/x/x Reserved
    #define D7F0_RWIDLKHOT			BIT0	//1b/1/x/x Priority Control When Hardware Auto Bandwidth Change Is Enabled for Power Saving
#define D7F0_AGGRESSIVE_PM		0x1E8	//Aggressive Power Management
    #define D7F0_RRXEIDPD			BIT7	//0/0/x/1 PCIE EPHY Receiver Electrical Idle Detector Power Down Control
    #define D7F0_RL1DYNPMG2			BIT6	//0/0/x/1 Enable L1 MPLL Power Down in GEN2 Speed
    #define D7F0_RLNCLKPM			BIT5	//0/0/1/1 Enable Clock Gating on Unused Lanes in a Multilane Link
    #define D7F0_RLNPWR			BIT4	//0/0/1/1 Enable Power down on Unused Lanes in a Multilane Link
    #define D7F0_RDSKWPM			BIT3	//0/0/1/1 Enable Aggressive Power Management in RX Path to Data Link Layer Module (DLLM)
    #define D7F0_RDEVDETPM			BIT2	//0/0/1/1 Enable Aggressive Power Management When No Device Plug
    #define D7F0_RPDL2			BIT1	//0/0/x/x Enable PHYES Level 2 Power Down
    #define D7F0_RL1TPLLPD			BIT0	//0/0/0/*1 Turn off TPLL When in L1 State
#define D7F0_LKTGLS_INTER_AND_NEED_EQTS		0x1E9	//LKTGLS_INTER and NEED_EQTS
    #define D7F0_RSV_1EA			0xF8	//0/0/x/x Reserved
    #define D7F0_LKTGLS_INTER			(BIT1 + BIT2)	//01b/01b/x/x LKTGLS Internal
    #define D7F0_NEED_EQTS			BIT0	//0/0/x/x EQTS Control Register
#define D7F0_RESERVED_Z9		0x1EA	//Reserved
    #define D7F0_TBD_1EA			0xFE	//0/R/x/x Reserved
    #define D7F0_LTSSM_SW_RESET			BIT0	//0/x/x/x LTSSM Software Reset
#define D7F0_RESERVED_Z10		0x1EB	//Reserved
    #define D7F0_SPDTM_SEL			0xF0	//0/x/x/x Timer Control for Waiting in RECOVERY_SPEED State
    #define D7F0_TBD_1EB			(BIT1 + BIT2 + BIT3)	//0/R/x/x Reserved
    #define D7F0_SPD_CHG_ARBEN			BIT0	//0/x/x/x Speed Change Arbitration Enable Bit
#define D7F0_REPEAT_CNTER_OF_THE_TEST_PATTERN		0x1F0	//Repeat Counter of the Test Pattern
    #define D7F0_RPTNUM			0xFF	//00h/0/x/X Repeat Counter of the Test Pattern (as selected in Rx1F2[7:4] ((MODESEL_PE0_[3:0])) )
#define D7F0_TEST_PATTERN_SEL		0x1F1	//Test Pattern Selection
    #define D7F0_MODESEL			0xF0	//0010b/0010b/x/X Test Pattern Select
    #define D7F0_LANESEL			0xF	//0/0/x/x Select Lane for Test and debug
#define D7F0_USER_DEFINED_TEST_PATTERN_1		0x1F2	//User Defined Test Pattern 1
    #define D7F0_SPTPTXD_15_0			0xFFFF	//0/0/x/x User Defined Test Pattern Bits [15:0]
#define D7F0_USER_DEFINED_TEST_PATTERN_2		0x1F4	//User Defined Test Pattern 2
    #define D7F0_SPTPTXD_31_16			0xFFFF	//0/0/x/x User Defined Test Pattern Bits [31:16]
#define D7F0_USER_DEFINED_TEST_PATTERN_2_Z1		0x1F6	//User Defined Test Pattern 2
    #define D7F0_SPTPTXD_47_32			0xFFFF	//0/0/x/x User Defined Test Pattern Bits [47:32]
#define D7F0_USER_DEFINED_TEST_PATTERN_2_Z2		0x1F8	//User Defined Test Pattern 2
    #define D7F0_SPTPTXD_63_48			0xFFFF	//0/0/x/x User Defined Test Pattern Bits [63:49]
#define D7F0_USER_DEFINED_TEST_PATTERN_2_Z3		0x1FA	//User Defined Test Pattern 2
    #define D7F0_SPTPTXD_79_64			0xFFFF	//0/0/x/x User Defined Test Pattern Bits [79:64]
#define D7F0_TEST_MODE_CTL_1		0x1FC	//Test Mode Control 1
    #define D7F0_EPHYTST			BIT7	//0/0/x/x Enable Electrical PHY Test Mode 
    #define D7F0_RSV_1FC_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define D7F0_RSV_1FC_3			BIT3	//0/0/x/x Reserved
    #define D7F0_EPHYBISTER_CLRAR_EACH_PAT			BIT2	//0/0/x/x EPHYBISTER_CLRAR_EACH_PAT_
    #define D7F0_EPHYBISTER_NOCOMP_FIRST			BIT1	//0/0/x/x EPHYBISTER_NOCOMP_FIRST_
    #define D7F0_EPHYBISTER_CLRAR			BIT0	//0/0/x/x EPHYBISTER_CLRAR_
#define D7F0_BIST_STA_RXD_1		0x1FD	//BIST Status RXD 1
    #define D7F0_RSV_1FD			0xF0	//0/0/x/x Reserved
    #define D7F0_TPHYRXD_19_16			0xF	//HwInit/x/x/x Received Symbol
#define D7F0_BIST_STA_RXD_2		0x1FE	//BIST Status RXD 2
    #define D7F0_TPHYRXD_15_0			0xFFFF	//HwInit/x/x/x Transmitted Symbol 
#define D7F0_PHY_BIST_CNTER_TEST_MODE		0x200	//PHY BIST Counter Test Mode
    #define D7F0_EPHYERRCNT			0xFFFF	//HwInit/x/x/x PHY BIST Period Electrical PHY Test Error
#define D7F0_PHY_RECEIVER_ERR_CNTER_CTL		0x202	//PHY Receiver Error Counter Control
    #define D7F0_RRCVECNTEN			BIT7	//0/0/x/x Enable Receiver Error Counter
    #define D7F0_RSV_202_6			BIT6	//0/0/x/x Reserved
    #define D7F0_RECNTST			BIT5	//0/0/x/x Receiver Error Counter Manual Start Control
    #define D7F0_RECNTSTSET			BIT4	//0/0/x/x Enable Receiver Error Counter Manual Start
    #define D7F0_RSV_202_5			(BIT2 + BIT3)	//0/0/x/x Reserved
    #define D7F0_RECNTEND			BIT1	//0/0/x/x Receiver Error Counter Manual End Control
    #define D7F0_RECNTENDSET			BIT0	//0/0/x/x Enable Receiver Error Counter Manual End
#define D7F0_RESERVED_Z11		0x203	//Reserved
    #define D7F0_RSV_201			0xFF	//0/x/x/x Reserved
#define D7F0_PHY_TRANSMIT_ERR_CNTER_CTL		0x204	//PHY Transmit Error Counter Control
    #define D7F0_CMPTECNT			0xFF	//HwInit/x/x/x Error Count in Transmitted Modified Compliance Pattern
#define D7F0_PHY_RECEIVE_ERR_CNTER_CTL		0x205	//PHY Receive Error Counter Control
    #define D7F0_CMPRECNT			0xFF	//HwInit/x/x/x Error Count in Received Modified Compliance Pattern
#define D7F0_RESERVED_Z12		0x206	//Reserved
    #define D7F0_RSV_206			0xFF	//0/x/x/x Reserved
#define D7F0_RESERVED_Z13		0x207	//Reserved
    #define D7F0_RSV_207			0xFF	//0/x/x/x Reserved
#define D7F0_TEST_MODE_CTL_2		0x208	//Test Mode Control 2
    #define D7F0_RSV_160			(BIT29 + BIT30 + BIT31)	//0/0/x/x Reserved
    #define D7F0_RLPBKDIF			BIT28	//0/0/x/x All Lanes in a Link Loopback Configuration Setting Control
    #define D7F0_RSKPINTST			BIT27	//0/0/x/x SKP Ordered Set Insertion Control in EPHYTST Data Test Pattern
    #define D7F0_RECNTBIST			BIT26	//0/0/x/x Error Count Counts Option   Data Mismatch Result or RXSTATUS Result
    #define D7F0_PWRTRSET			(BIT24 + BIT25)	//00b/0/x/x Transmit and Receiver Power State Setting Options
    #define D7F0_RSV_204_23_0			0xFFFFFF	//0/0/x/x Reserved
#define D7F0_TEST_PATTERN_SEL_2		0x20C	//Test Pattern Selection 2
    #define D7F0_MODESEL_DIF			0xF0	//0000b/0/x/x Different Pattern Selection 
    #define D7F0_RSV_163			0xF	//0/x/x/x Reserved
#define D7F0_TEST_PATTERN_SEL_3		0x20D	//Test Pattern Selection 3
    #define D7F0_LANESEL_DIF			0xFFFF	//0/0/x/x Select Lanes with Different Pattern
#define D7F0_RESERVED_Z14		0x20F	//Reserved
    #define D7F0_RSV_20F			0xFF	//0/x/x/x Reserved
#define D7F0_BIST_STA_TXD		0x210	//BIST Status TXD
    #define D7F0_RSV_20C_31			0xFE000000	//0/R/x/x Reserved
    #define D7F0_EPHYBISTER			BIT24	//HwInit/x/x/x Electrical PHY Built-In Self Test Error of Symbol Comparison
    #define D7F0_RSV_20C_22			0xF00000	//0/0/x/x Reserved
    #define D7F0_TPHYTXD			0xFFFFF	//HwInit/x/x/x Transmitted Symbol 
#define D7F0_PEXC_PM_CTL_1		0x230	//PEXC Power Management Control 1
    #define D7F0_RPMUDMCLK			BIT7	//0/0/1/1 Dynamic Clock Power Management for PMU Transmission
    #define D7F0_RDLTXDMCLK			BIT6	//0/0/1/1 Dynamic Stop for EDCLK for Downstream Packets in DLL
    #define D7F0_RDLRXDMCLK			BIT5	//0/0/1/1 Dynamic Stop for EDCLK for Upstream Packets in DLL of VPIL
    #define D7F0_RTLRTYDBXPM			BIT4	//0/0/1/1 Dynamic Stop for ETCLK_PEG for Downstream Retry FIFO of VPIL
    #define D7F0_RTLSNOPPM			BIT3	//0/0/1/1 Reserved.
    #define D7F0_RTLNSNOPPM			BIT2	//0/0/1/1 Reserved
    #define D7F0_RTLDNDBXPM			BIT1	//0/0/1/1 Reserved
    #define D7F0_RTLUPDBXPM			BIT0	//0/0/1/1 Reserved
#define D7F0_PEXC_PM_CTL_2		0x231	//PEXC Power Management Control 2
    #define D7F0_RTLUPPM			BIT7	//0/0/1/1 Reserved
    #define D7F0_RTLDNPM			BIT6	//0/0/1/1 Reserved
    #define D7F0_RTLRTYPM			BIT5	//0/0/1/1 Reserved
    #define D7F0_RTLLNKPM			BIT4	//0/0/1/1 Reserved
    #define D7F0_RPEPM			BIT3	//0/0/1/1 Dynamic Clock Stop Control for ETCLK at VPI
    #define D7F0_RTLRCVPM			BIT2	//0/0/1/1 Reserved
    #define D7F0_RMESCDPM			BIT1	//0/0/1/1 Dynamic Stop for ECLK in MSGC for VPIL
    #define D7F0_RMESCGPM			BIT0	//0/0/1/1 Dynamic Stop for ACLK in MSGC for VPIL
#define D7F0_PEXC_PM_CTL_3		0x232	//PEXC Power Management Control 3
    #define D7F0_RSV_222			0xF8	//0/0/X/x Reserved
    #define D7F0_RTXCDCDYNPM			BIT2	//0/0/1/1 Dynamic Stop for EPCLK at TXCDC
    #define D7F0_RPHYPM			BIT1	//0/0/1/1 Dynamic Stop for EPCLK at VPI Physical Layer
    #define D7F0_RL1DYNPM			BIT0	//0/0/1/1 Clock Stop at L1 state for VPI 
#define D7F0_PEXC_PM_CTL_4		0x233	//PEXC Power Management Control 4
    #define D7F0_RSV_223			BIT7	//0/0/x/x Reserved
    #define D7F0_RDYNMESCPM			BIT6	//0/0/1/1 Dynamic Clocks Control for VPIL MESC
    #define D7F0_RSTPGNTGPM			BIT5	//0/0/1/1 Dynamic Clocks Control for VPIL STPGNT module??гдs GCLK
    #define D7F0_RSTPGNTDPM			BIT4	//0/0/1/1 Dynamic Clocks Control for VPIL STPGNT Module??гдs DCLK
    #define D7F0_RCNTPM			BIT3	//0/0/1/1 Dynamic Stop for Clocks for Internal Counters
    #define D7F0_RSYNCPM			BIT2	//0/0/1/1 Dynamic Stop for Clocks for Configuration Registers Updates
    #define D7F0_RLKACTPM			BIT1	//0/0/1/1 Dynamic Stop for Clocks for Link Status Changes 
    #define D7F0_RSTPGNTPM			BIT0	//0/0/1/1 Dynamic Stop for Clocks for Stop Grant Cycle Handling in MSGC
#define D7F0_PCIE_ARBITRATION_CTL		0x234	//PCIE Arbitration Control
    #define D7F0_RDISP2PZLW			BIT7	//1b/1/x/x Reserved
    #define D7F0_RARBDYNPM			BIT6	//0/0/1/1 DYNCLK Enable in VPIL
    #define D7F0_RARBDYNPMUP			BIT5	//0/0/1/1 Upstream Issue DYNCLK Enable in VPIL
    #define D7F0_RARBDYNPMDN			BIT4	//0/0/1/1 Downstream Issue DYNCLK Enable in VPIL
    #define D7F0_RPEARBWDDELAY			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define D7F0_RTOTESTEN			BIT0	//0/0/x/x RTOTESTEN; Reserved
#define D7F0_ATS_INVALIDATE_TIMEOUT_CTL		0x235	//ATS Invalidate Timeout Control
    #define D7F0_RMSGINVTOV			0xFF	//40h/40h/x/x ATS Invalidate Timeout Control; Reserved
#define D7F0_ATS_INVALIDATE_TIMEOUT_CTL_AND_DLLP_CTL_AND_MSG_LINK_DOWN_CTL		0x236	//ATS Invalidate Timeout Control and DLLP Control and MSG Link Down Control
    #define D7F0_RSV_236			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D7F0_MSG_DLDOWN_KEEP			BIT4	//1b/1b/x/x MSG Info Will Not Be Cleared to Deassert under DLDown
    #define D7F0_ACKPNDEN			BIT3	//1b/1b/x/x Ack Response Response Immediately, But Not Just Under Ack Latency Timer
    #define D7F0_FCUPNDEN			BIT2	//1b/1b/x/x FCU Response Response Immediately, But Not Just under FCU Latency Timer
    #define D7F0_RDNCFGNFLUSH			BIT1	//0/0/x/x Reserved
    #define D7F0_RARBDYNPMAT			BIT0	//0/0/1/1 Reserved
#define D7F0_SLAVE_VPI_MUX_AND_FCU_MASK_REG_CTL_AND_TXVNMIN_CNTER_ENABLE		0x237	//Slave VPI MUX and FCU MASK Register Control and TXVNMIN Counter Enable
    #define D7F0_TXVNMINWCNT_EN			BIT7	//1b/1b/1b/x TXVNMINWCNT Enable
    #define D7F0_FCU_REG_EN			BIT6	//1b/1b/1b/x FCU MASK Register Control
    #define D7F0_VPI2CPUREGEN			BIT5	//0/0/X/x VPI2CPU Register Enable
    #define D7F0_NMI_BYPASS			BIT4	//1b/1b/X/X CPU NMI Input Select
    #define D7F0_SMI_B_BYPASS			BIT3	//1b/1b/X/X CPU SMI_B Input Select
    #define D7F0_INIT_B_BYPASS			BIT2	//1b/1b/X/X CPU INIT_B Input Select
    #define D7F0_INTR_BYPASS			BIT1	//1b/1b/X/X CPU INTR Input Select
    #define D7F0_IGNNE_B_BYPASS			BIT0	//1b/1b/x/X CPU IGNNE_B Input Select
#define D7F0_FCI_INIT_CREDIT_VALUE_CTL		0x238	//FCI INIT Credit Value Control
    #define D7F0_REQFCICREDIT_1_0			(BIT6 + BIT7)	//11b/11b/X/X REQ FCI Value Control
    #define D7F0_SRQFCICREDIT_1_0			(BIT4 + BIT5)	//11b/11b/X/X SRQ FCI Value Control
    #define D7F0_SRPFCICREDIT_1_0			(BIT2 + BIT3)	//11b/11b/X/X SRP FCI Value Control
    #define D7F0_DATFCICREDIT_1_0			(BIT0 + BIT1)	//11b/11b/x/X DAT FCI Value Control
#define D7F0_FCI_INIT_CREDIT_VALUE_CTL_CONT_AND_RX_HP_FCU_HP_TIMER_ENABLE		0x239	//FCI INIT Credit Value Control Cont. and RX HP/ FCU HP Timer Enable
    #define D7F0_TBD_226			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define D7F0_FCUHPEN			BIT5	//1b/1b/x/x TX FCU HP Timer Enable
    #define D7F0_HPTIMEN			BIT4	//1b/1b/X/x RX High Priority Timer Enable
    #define D7F0_WCPFCICREDIT_1_0			(BIT2 + BIT3)	//11b/11b/X/X WCP FCI Value Control
    #define D7F0_MSGFCICREDIT_1_0			(BIT0 + BIT1)	//11b/11b/x/X MSG FCI Value Control
#define D7F0_FCU_HP_TIMER_LIMIT		0x23A	//FCU HP Timer Limit
    #define D7F0_FCUHPMAX_7_0			0xFF	//3h/3h/x/X TX FCU HP Timer Maximum
#define D7F0_TXBUF_CACHE_LEVEL_CTL_AND_QUICKLY_ACK_OPTION_AND_VPI_PCIE_MODE_NEW_CTL		0x23B	//TXBUF Cache Level Control and Quickly Ack Option and VPI PCIE Mode New Control
    #define D7F0_THD_23B			(BIT5 + BIT6 + BIT7)	//0/0/x/X Reserved
    #define D7F0_VPI_PCIEMODE			BIT4	//0b/0b/x/x VPI PCIE Mode
    #define D7F0_ACKPERF			BIT3	//0b/0b/x/x Reply Ack at Once When a Mew TLP Is Received, for one-way Performance Check
    #define D7F0_BUFREV_EN			BIT2	//0b/0b/x/x Register Control Enable
    #define D7F0_BUFPND_1_0			(BIT0 + BIT1)	//10b/10b/x/x TXBUF Cache Level 
#define D7F0_RX_MSG_TOKEN_TIMER_LIMIT		0x23C	//RX MSG TOKEN Timer Limit
    #define D7F0_RXMSGTOKENMAX_7_0			0xFF	//20h/20h/x/X RX MSG TOKEN Timer Maximum
#define D7F0_TXVNMINWCNT_CNTER_LIMIT		0x23D	//TXVNMINWCNT Counter Limit
    #define D7F0_TXVNMINWCNT_7_0			0xFF	//FFh/FFh/x/X TXVNMIN Weight Count
#define D7F0_PMC_ACK_CNTER_LIMIT		0x23E	//PMC Ack Counter Limit
    #define D7F0_PMC_ACK_TM_7_0			0xFF	//0Ch/0Ch/x/X PMC_Ack Request Frequency Control
#define D7F0_PCIE_DEBUG_SIGNAL_SEL_FOR_GRP0		0x240	//PCIE Debug Signal Selection for Group0
    #define D7F0_RSV_230_2			0xFC000000	//0/x/x/x Reserved
    #define D7F0_PCIE_DBG_SEL0_19_10			0x3FF0000	//0/0/x/x Reserved 
    #define D7F0_RSV_230_1			0xFC00	//0/X/x/x Reserved
    #define D7F0_PCIE_DBG_SEL0_9_0			0x3FF	//0/0/x/x Reserved 
#define D7F0_PCIE_DEBUG_SIGNAL_SEL_FOR_GRP1		0x244	//PCIE Debug Signal Selection for Group1
    #define D7F0_RSV_234_2			0xFC000000	//0/x/x/x Reserved
    #define D7F0_PCIE_DBG_SEL1_19_10			0x3FF0000	//0/0/x/x Reserved 
    #define D7F0_RSV_234_1			0xFC00	//0/x/x/x Reserved
    #define D7F0_PCIE_DBG_SEL1_9_0			0x3FF	//0/0/x/x Reserved 
#define D7F0_PCIE_DEBUG_MODE_HEADER_REG_CTL_GRP1		0x248	//PCIE Debug Mode Header Register Control Group1
    #define D7F0_PCIEMODEDW1B0_7_0			0xFF000000	//00000000b/00000000b/x/x PCIE MODE DW1 Byte0 Value
    #define D7F0_PCIEMODEDW0B2_7_0			0xFF0000	//00000000b/00000000b/x/x PCIE MODE DW0 Byte2 Value
    #define D7F0_PCIEMODEDW0B1_7_0			0xFF00	//00000000b/00000000b/x/x PCIE MODE DW0 Byte1 Value
    #define D7F0_PCIEMODEDW0B0_7_0			0xFF	//01000000b/01000000b/x/x PCIE MODE DW0 Byte0 Value
#define D7F0_PCIE_DEBUG_MODE_HEADER_REG_CTL_GRP2		0x24C	//PCIE Debug Mode Header Register Control Group2
    #define D7F0_PCIEMODEDW2B0_7_0			0xFF000000	//00000000b/00000000b/x/x PCIE MODE DW2 Byte0 Value
    #define D7F0_PCIEMODEDW1B3_7_0			0xFF0000	//00000000b/00000000b/x/x PCIE MODE DW1 Byte3 Value
    #define D7F0_PCIEMODEDW1B2_7_0			0xFF00	//00000000b/00000000b/x/x PCIE MODE DW1 Byte2 Value
    #define D7F0_PCIEMODEDW1B1_7_0			0xFF	//00000000b/00000000b/x/x PCIE MODE DW1 Byte1 Value
#define D7F0_PCIE_DEBUG_MODE_HEADER_REG_CTL_GRP3		0x250	//PCIE Debug Mode Header Register Control Group3
    #define D7F0_RSV_234_0			0xFE000000	//0000000b/0000000b/x/x Reserved
    #define D7F0_PCIEMODEADDR_REG			BIT24	//0b/0b/x/x PCIE MODE Header Address Register Control
    #define D7F0_PCIEMODEDW2B3_7_0			0xFF0000	//00000000b/00000000b/x/x PCIE MODE DW2 Byte3 Value
    #define D7F0_PCIEMODEDW2B2_7_0			0xFF00	//00000000b/00000000b/x/x PCIE MODE DW2 Byte2 Value
    #define D7F0_PCIEMODEDW2B1_7_0			0xFF	//00000000b/00000000b/x/x PCIE MODE DW2 Byte1 Value
#define D7F0_MISC_CTL		0x290	//Misc. Control
    #define D7F0_RSV_290_7			0xFFFFC000	//0/0/x/x Reserved
    #define D7F0_RL0_EIEOS_EN			BIT13	//0/0/x/x Send EIEOS in L0 State
    #define D7F0_RSKPOS_EN			BIT12	//0/0/x/x Add SKPOS in TX Data
    #define D7F0_RRXPOL			BIT11	//0/0/x/x Manual Set RX Polarity Value
    #define D7F0_RRXPOL_EN			BIT10	//0/0/x/x Manual Set RX Polarity Enable
    #define D7F0_L12L0LAT			(BIT8 + BIT9)	//0/0/x/x Downstream Cycles Triggered C2P Cycles; Reserved
    #define D7F0_RCLEAR_PMC_EN			BIT7	//1b/1/x/x Clear PMC_BLKTLP in Non L0 State
    #define D7F0_L11_EXIT_SEL			(BIT5 + BIT6)	//0/x/x/x L1 Substate Exit Select
    #define D7F0_RWTEXEPH23			BIT4	//0/0/x/x Want Exe EQ Phase 2 and 3
    #define D7F0_RXDEID_L1_SEL			0xF	//0/x/x/x RX EIDLE Detecter Periodical Power down Select; Reserved
#define D7F0_TX_IDLEOS_CTL_GEN1		0x294	//TX IDLEOS Control Gen1
    #define D7F0_RSV_294_21			0xFFE00000	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_MIN_G1			0x1F0000	//1Fh/x/x/x TX-IDLE_MIN in PCIe Spec
    #define D7F0_RSV_294_15			BIT15	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_SET_TO_IDLE_G1			0x7F00	//30h/x/x/x TX Electrical Counter, When Timeout, TX Set to Electrical Idle
    #define D7F0_RSV_294_7			BIT7	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_OS_WAIT_MIN_G1			0x7F	//40h/x/x/x TX Idleos Counter, Keep Sending Idleos Before TX Enter L0s/L1
#define D7F0_TX_IDLEOS_CTL_GEN2		0x298	//TX IDLEOS Control Gen2
    #define D7F0_RSV_298_21			0xFFE00000	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_MIN_G2			0x1F0000	//1fh/x/x/x TX-IDLE_MIN in PCIe Spec
    #define D7F0_RSV_298_15			BIT15	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_SET_TO_IDLE_G2			0x7F00	//20h/x/x/x TX Electrical Counter, When Timeout, TX Set to Electrical Idle
    #define D7F0_RSV_298_7			BIT7	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_OS_WAIT_MIN_G2			0x7F	//30h/x/x/x TX Idleos Counter, Keep Sending Idleos Before TX Enter L0s/L1
#define D7F0_TX_IDLEOS_CTL_GEN3		0x29C	//TX IDLEOS Control Gen3
    #define D7F0_RSV_29C_21			0xFFE00000	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_MIN_G3			0x1F0000	//1Fh/x/x/x TX-IDLE_MIN in PCIe Spec
    #define D7F0_RSV_29C_15			BIT15	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_SET_TO_IDLE_G3			0x7F00	//20h/x/x/x TX Electrical Counter, When Timeout, TX Set to Electrcail Idle
    #define D7F0_RSV_29C_7			BIT7	//0/0/x/x Reserved
    #define D7F0_T_TX_IDLE_OS_WAIT_MIN_G3			0x7F	//30h/x/x/x TX Idleos Counter, Keep Sending Idleos Before TX Enter L0s/L1
#define D7F0_SECONDARY_PCI_EXPRESS_EXTENDED_CAP		0x2A0	//Secondary PCI Express Extended Capability
    #define D7F0_TBD_2A0_3120			0xFFF00000	//0/R/x/x Next Capability Offset
    #define D7F0_TBD_2A0_1916			0xF0000	//1h/R/x/x Capability Version
    #define D7F0_TBD_2A0_1500			0xFFFF	//0019h/R/x/x PCI Express Extended Capability ID
#define D7F0_LINK_CTL_3_REG		0x2A4	//Link Control 3 Register
    #define D7F0_TBD_2A4_12			0xFFFFF000	//0/R/x/x Reserved
    #define D7F0_RLOW_SKP_EN			(BIT9 + BIT10 + BIT11)	//0/x/x/x Enable Lower SKP OS Generation Vector
    #define D7F0_TBD_2A4_2			0x1FC	//0/x/x/x Reserved
    #define D7F0_EQINTEN			BIT1	//0/x/x/x Link Equalization Request Interrupt Enable
    #define D7F0_PERFORMEQ			BIT0	//0/x/x/x Perform Equalization
#define D7F0_LANE_ERR_STA_REG		0x2A8	//Lane Error Status Register
    #define D7F0_TBD_2A8_72			0xFFFFFF00	//0/R/x/x Reserved
    #define D7F0_LANEERR07			BIT7	//0/0/x/x Lane Error Status Bits
    #define D7F0_LANEERR06			BIT6	//0/0/x/x Lane Error Status Bits
    #define D7F0_LANEERR05			BIT5	//0/0/x/x Lane Error Status Bits
    #define D7F0_LANEERR04			BIT4	//0/0/x/x Lane Error Status Bits
    #define D7F0_LANEERR03			BIT3	//0/0/x/x Lane Error Status Bits
    #define D7F0_LANEERR02			BIT2	//0/0/x/x Lane Error Status Bits
    #define D7F0_LANEERR01			BIT1	//0/0/x/x Lane Error Status Bits
    #define D7F0_LANEERR00			BIT0	//0/0/x/x Lane Error Status Bits
#define D7F0_LANE_EQUALIZATION_CTL_REG		0x2AC	//Lane Equalization Control Register
    #define D7F0_TBD_2AC_31			BIT31	//0/R/x/x Reserved
    #define D7F0_EPRXPRESET01			(BIT28 + BIT29 + BIT30)	//HwInit/x/x/x Lane 1 Upstream Port Receiver Preset Hint
    #define D7F0_EPTXPRESET01			0xF000000	//HwInit/x/x/x Lane 1 Upstream Port Transmitter Preset 
    #define D7F0_TBD_2AC_23			BIT23	//0/R/x/x Reserved
    #define D7F0_RXPRESET01			(BIT20 + BIT21 + BIT22)	//HwInit/x/x/x Lane1 Downstream Port Receiver Preset Hint
    #define D7F0_TXPRESET01			0xF0000	//HwInit/x/x/x Lane 1 Downstream Port Transmitter Preset 
    #define D7F0_TBD_2AC_15			BIT15	//0/R/x/x Reserved
    #define D7F0_EPRXPRESET00			(BIT12 + BIT13 + BIT14)	//HwInit/x/x/x Lane 0 Upstream Port Receiver Preset Hint
    #define D7F0_EPTXPRESET00			0xF00	//HwInit/x/x/x Lane 0 Upstream Port Transmitter Preset 
    #define D7F0_TBD_2AC_7			BIT7	//0/R/x/x Reserved
    #define D7F0_RXPRESET00			(BIT4 + BIT5 + BIT6)	//HwInit/x/x/x Lane 0 Downstream Port Receiver Preset Hint
    #define D7F0_TXPRESET00			0xF	//HwInit/x/x/x Lane 0 Downstream Port Transmitter Preset 
#define D7F0_LANE_EQUALIZATION_CTL_REG_Z1		0x2B0	//Lane Equalization Control Register
    #define D7F0_TBD_2B0_31			BIT31	//0/R/x/x Reserved
    #define D7F0_EPRXPRESET03			(BIT28 + BIT29 + BIT30)	//HwInit/x/x/x Lane 3 Upstream Port Receiver Preset Hint
    #define D7F0_EPTXPRESET03			0xF000000	//HwInit/x/x/x Lane 3 Upstream Port Transmitter Preset 
    #define D7F0_TBD_2B0_23			BIT23	//0/R/x/x Reserved
    #define D7F0_RXPRESET03			(BIT20 + BIT21 + BIT22)	//HwInit/x/x/x Lane3 Downstream Port Receiver Preset Hint
    #define D7F0_TXPRESET03			0xF0000	//HwInit/x/x/x Lane 3 Downstream Port Transmitter Preset 
    #define D7F0_TBD_2B0_15			BIT15	//0/R/x/x Reserved
    #define D7F0_EPRXPRESET02			(BIT12 + BIT13 + BIT14)	//HwInit/x/x/x Lane 2 Upstream Port Receiver Preset Hint
    #define D7F0_EPTXPRESET02			0xF00	//HwInit/x/x/x Lane 2 Upstream Port Transmitter Preset 
    #define D7F0_TBD_2B0_7			BIT7	//0/R/x/x Reserved
    #define D7F0_RXPRESET02			(BIT4 + BIT5 + BIT6)	//HwInit/x/x/x Lane 2 Downstream Port Receiver Preset Hint
    #define D7F0_TXPRESET02			0xF	//HwInit/x/x/x Lane 2 Downstream Port Transmitter Preset 
#define D7F0_LANE_EQUALIZATION_CTL_REG_Z2		0x2B4	//Lane Equalization Control Register
    #define D7F0_TBD_2B4_31			BIT31	//0/R/x/x Reserved
    #define D7F0_EPRXPRESET05			(BIT28 + BIT29 + BIT30)	//HwInit/x/x/x Lane 5 Upstream Port Receiver Preset Hint
    #define D7F0_EPTXPRESET05			0xF000000	//HwInit/x/x/x Lane 5 Upstream Port Transmitter Preset 
    #define D7F0_TBD_2B4_23			BIT23	//0/R/x/x Reserved
    #define D7F0_RXPRESET05			(BIT20 + BIT21 + BIT22)	//HwInit/x/x/x Lane5 Downstream Port Receiver Preset Hint
    #define D7F0_TXPRESET05			0xF0000	//HwInit/x/x/x Lane 5 Downstream Port Transmitter Preset 
    #define D7F0_TBD_2B4_15			BIT15	//0/R/x/x Reserved
    #define D7F0_EPRXPRESET04			(BIT12 + BIT13 + BIT14)	//HwInit/x/x/x Lane 4 Upstream Port Receiver Preset Hint
    #define D7F0_EPTXPRESET04			0xF00	//HwInit/x/x/x Lane 4 Upstream Port Transmitter Preset 
    #define D7F0_TBD_2B4_7			BIT7	//0/R/x/x Reserved
    #define D7F0_RXPRESET04			(BIT4 + BIT5 + BIT6)	//HwInit/x/x/x Lane 4 Downstream Port Receiver Preset Hint
    #define D7F0_TXPRESET04			0xF	//HwInit/x/x/x Lane 4 Downstream Port Transmitter Preset 
#define D7F0_LANE_EQUALIZATION_CTL_REG_Z3		0x2B8	//Lane Equalization Control Register
    #define D7F0_TBD_2B8_31			BIT31	//0/R/x/x Reserved
    #define D7F0_EPRXPRESET07			(BIT28 + BIT29 + BIT30)	//HwInit/x/x/x Lane 7 Upstream Port Receiver Preset Hint
    #define D7F0_EPTXPRESET07			0xF000000	//HwInit/x/x/x Lane 7 Upstream Port Transmitter Preset 
    #define D7F0_TBD_2B8_23			BIT23	//0/R/x/x Reserved
    #define D7F0_RXPRESET07			(BIT20 + BIT21 + BIT22)	//HwInit/x/x/x Lane7 Downstream Port Receiver Preset Hint
    #define D7F0_TXPRESET07			0xF0000	//HwInit/x/x/x Lane 7 Downstream Port Transmitter Preset 
    #define D7F0_TBD_2B8_15			BIT15	//0/R/x/x Reserved
    #define D7F0_EPRXPRESET06			(BIT12 + BIT13 + BIT14)	//HwInit/x/x/x Lane 6 Upstream Port Receiver Preset Hint
    #define D7F0_EPTXPRESET06			0xF00	//HwInit/x/x/x Lane 0 Upstream Port Transmitter Preset 
    #define D7F0_TBD_2B8_7			BIT7	//0/R/x/x Reserved
    #define D7F0_RXPRESET06			(BIT4 + BIT5 + BIT6)	//HwInit/x/x/x Lane 6 Downstream Port Receiver Preset Hint
    #define D7F0_TXPRESET06			0xF	//HwInit/x/x/x Lane 6 Downstream Port Transmitter Preset 
#define D7F0_L1_PM_SUBSTATES_EXTENDED_CAP		0x2C0	//L1 PM Substates Extended Capability
    #define D7F0_TBD_2B0_3120			0xFFF00000	//0/R/x/x Next Capability Offset
    #define D7F0_TBD_2B0_1916			0xF0000	//1h/R/x/x Capability Version
    #define D7F0_TBD_2B0_1500			0xFFFF	//001Eh/R/x/x PCI Express Extended Capability ID
#define D7F0_L1_PM_SUBSTATES_CAPS_REG		0x2C4	//L1 PM Substates Capabilities Register
    #define D7F0_TBD_2C4_24			0xFF000000	//0/R/x/x Reserved
    #define D7F0_PORT_T_POWER_ON_VALUE			0xF80000	//00111b/x/x/x Port T_POWER_ON Value 
    #define D7F0_TBD_2C4_18			BIT18	//0/R/x/x Reserved
    #define D7F0_PORT_T_POWER_ON_SCALE			(BIT16 + BIT17)	//01b/x/x/x Port T_POWER_ON Scale 
    #define D7F0_PORT_CM_RESTORE_TIME			0xFF00	//4h/x/x/x Port Common_Mode_Restore_Time 
    #define D7F0_TBD_2C4_5			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D7F0_L1_SUB_SUPPORT			BIT4	//1b/x/x/x L1 PM Substates Supported 
    #define D7F0_ASPML11_SUPPORT			BIT3	//1b/x/x/x ASPM L1.1 Supported
    #define D7F0_ASPML12_SUPPORT			BIT2	//1b/x/x/x ASPM L1.2 Supported
    #define D7F0_PML11_SUPPORT			BIT1	//1b/x/x/x PCI-PM L1.1 Supported
    #define D7F0_PML12_SUPPORT			BIT0	//1b/x/x/x PCI-PM L1.2 Supported
#define D7F0_L1_PM_SUBSTATES_CTL_1_REG		0x2C8	//L1 PM Substates Control 1 Register
    #define D7F0_TBD_2C8_31			0xFFFFFFF0	//0/R/x/x Reserved
    #define D7F0_ASPML11_EN			BIT3	//0/x/x/x ASPM L1.1 Enable
    #define D7F0_TBD_2C8_2			BIT2	//0/R/x/x Reserved
    #define D7F0_PML11_EN			BIT1	//0/x/x/x PCI-PM L1.1 Enable
    #define D7F0_TBD_2C8_0			BIT0	//0/R/x/x Reserved
#define D7F0_L1_PM_SUBSTATES_CTL_2_REG		0x2CC	//L1 PM Substates Control 2 Register
    #define D7F0_TBD_2BD			0xFFFFFF00	//0/R/x/x Reserved
    #define D7F0_T_POWER_ON_VALUE			0xF8	//00111b/x/x/x T_POWER_ON Value 
    #define D7F0_TBD_2BC			BIT2	//0/R/x/x Reserved
    #define D7F0_T_POWER_ON_SCALE			(BIT0 + BIT1)	//01b/x/x/x T_POWER_ON Scale 
#define D7F0_VPIL_PORT_ERR_STA		0x300	//VPIL Port Error Status
    #define D7F0_VPIL_ERR			BIT7	//0/0/x/x VPIL Port Error Detected
    #define D7F0_RSV_300			0x7F	//0/x/x/x Reserved
#define D7F0_VPIL_PORT_ERR_CTL		0x301	//VPIL Port Error Control
    #define D7F0_RSV_301_7			BIT7	//0/0/0/0 Reserved
    #define D7F0_RX301_6_4			(BIT5 + BIT6)	//0/x/x/x Reserved
    #define D7F0_RPEEIEN			BIT4	//0/0/0/0 VPIL Hard Error Injection Enable
    #define D7F0_RSV_301_3_0			0xF	//0/0/x/x Reserved
#define D7F0_RESERVED_Z15		0x302	//Reserved
    #define D7F0_RSV_302			0xFFFF	//0/x/x/x Reserved
#define D7F0_VPIL_HARD_ERR_INJECTION_TRIGGER_REGS		0x304	//VPIL Hard Error Injection Trigger Registers
    #define D7F0_RLBWMNGT_EI			BIT31	//0/0/x/0 Link Bandwidth Management Event Injection
    #define D7F0_RLATNMBW_EI			BIT30	//0/0/x/0 Link Autonomous Bandwidth Event Injection
    #define D7F0_RDLSCHG_EI			BIT29	//0/0/x/0 Data Link States Change Event Injection
    #define D7F0_REQREQ_EI			BIT28	//0/0/x/0 EQREQ Event Injection
    #define D7F0_RUNRL_X8_EI			BIT27	//0/0/x/0 X8 Link Width Unreliable Status Error Injection
    #define D7F0_RUNRL_X4_EI			BIT26	//0/0/x/0 X4 Link Width Unreliable Status Error Injection
    #define D7F0_RUNRL_X2_EI			BIT25	//0/0/x/0 X2 Link Width Unreliable Status Error Injection
    #define D7F0_RUNRL_G3_EI			BIT24	//0/0/x/0 G3 Link Width Unreliable Status Error Injection
    #define D7F0_RUNRL_G2_EI			BIT23	//0/0/x/0 G2 Link Width Unreliable Status Error Injection
    #define D7F0_RPLTMO_EI			BIT22	//0/0/x/0 Trigger Replay Timeout Error Injection
    #define D7F0_RX304_21			BIT21	//0/x/x/x Reserved
    #define D7F0_RPLNUMRO_EI			BIT20	//0/0/x/x Trigger REPLAY NUM Rollover Error Injection
    #define D7F0_BADDLLP_EI			BIT19	//0/0/x/x Trigger Bad DLLPError Injection
    #define D7F0_BADTLP_EI			BIT18	//0/0/x/x Trigger Bad TLPError Injection
    #define D7F0_RX304_17			BIT17	//0/x/x/x Reserved
    #define D7F0_RCVERR_EI			BIT16	//0/0/x/x Trigger Receiver Error Injection
    #define D7F0_RX304_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D7F0_UR_EI			BIT13	//0/0/x/x Trigger Unsupported Request Error Injection
    #define D7F0_RX304_12			BIT12	//0/x/x/x Reserved
    #define D7F0_RX304_11			BIT11	//0/0/x/x Reserved
    #define D7F0_RCVO_EI			BIT10	//0/0/x/x Trigger Receiver Overflow Error Injection
    #define D7F0_RX304_9			BIT9	//0/0/x/x Reserved
    #define D7F0_RX304_8			BIT8	//0/0/x/x Reserved
    #define D7F0_RX304_7			BIT7	//0/0/x/x Reserved
    #define D7F0_FCPE_EI			BIT6	//0/0/x/x Trigger Flow Control Protocol Error Injection
    #define D7F0_RX304_5			BIT5	//0/0/x/x Reserved
    #define D7F0_RX304_4			BIT4	//0/x/x/x Reserved
    #define D7F0_SDN_EI			BIT3	//0/0/x/x Trigger Surprise Down Error Injection
    #define D7F0_DLLPE_EI			BIT2	//0/0/x/x Trigger Data Link Layer Protocol Error Injection
    #define D7F0_RX304_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D7F0_UNRELIABLE_LINK_MANAGEMENT		0x400	//Unreliable Link Management
    #define D7F0_RUNRLCLR			BIT7	//0/0/x/x Reserved
    #define D7F0_RSPDUNRL			BIT6	//1b/1/1/x Priority Control When the Link is Unstable
    #define D7F0_RTLPRSCNT			(BIT4 + BIT5)	//00b/00b/00b/x Limitation of Transmitter Replays the TLP with the Same Sequence Number
    #define D7F0_RRXNAKCNT			(BIT2 + BIT3)	//00b/00b/00b/x Limitation of Receiver Receives the TLP with the Same Sequence Number and LCRC Error or All the TLP in Device??гдs Retry Buffer Have Been Replayed with LCRC ERROR
    #define D7F0_RUNRLEN_RX			BIT1	//0/0/1/x Enable Receiver Link Unreliable Detection
    #define D7F0_RUNRLEN_TX			BIT0	//0/0/1/x Enable Transmitter Link Unreliable Detection
#define D7F0_RXFC_HP_STA_MANAGEMENT		0x401	//RXFC HP Status Management
    #define D7F0_RSV_118			BIT7	//0/0/x/x Reserved
    #define D7F0_RXFCHPCNT_5_0			0x7E	//3Fh/3Fh/0h/x Counter for Update RXFC Data Path to HP, Data Will Be Blocked and RXFC Will Be Pushed to HIF Firstly One Time When the Timer Reach the Limitation and RXFCCNTEN Is Enable
    #define D7F0_RXFCCNTEN			BIT0	//0b/0b/0b/x Enable for Update RXFC to HP from the Arbitration with RX Data
#define D7F0_FLOW_CTL_INIT_FCI_FLOW_CTL_UNIT_FCU_CTL_AND_STA		0x402	//Flow Control Initialization (FCI) / Flow Control Unit (FCU) Control and Status
    #define D7F0_RFRTMDERR			BIT7	//0/0/x/x FCI / FCU Timeout Status
    #define D7F0_RFRTMEN			BIT6	//1b/1/1/x FCI / FCU Receive Timer Enable
    #define D7F0_RFRTMLM			BIT5	//0/0/0/x FCI / FCU Receive Timer Limit
    #define D7F0_RFRTMDLP			BIT4	//0/0/1/x FCI / FCU Receive Timer Reset Control
    #define D7F0_RSV_119			(BIT2 + BIT3)	//0/0/x/x Reserved
    #define D7F0_RASL1TMFCI			BIT1	//1b/1/x/x FCI Finish with DL_ASL1 Control
    #define D7F0_RDLFCUDMCLK			BIT0	//0/0/1/1 FCU Dynamic Clock Stop Function Control
#define D7F0_REPLAY_TIMER_CTL		0x403	//Replay Timer Control
    #define D7F0_RRTCTL			(BIT6 + BIT7)	//10b/10b/10b/x Replay Timer Control While Rewind
    #define D7F0_RSV_120			(BIT3 + BIT4 + BIT5)	//0/0/x/x Reserved
    #define D7F0_RNREVLD			(BIT0 + BIT1 + BIT2)	//001b/001b/000b/x Count of Replay Timer Expired during RxL0s (Receiver in L0s State) Before Resending the TLP
#define D7F0_ARBITRATION_CTL		0x404	//Arbitration Control
    #define D7F0_RSV_121			0xF8	//0/0/x/x Reserved
    #define D7F0_RDLARB			(BIT0 + BIT1 + BIT2)	//000b/000b/111b/x Data Link TX Packets Arbitration Scheme
#define D7F0_FCU_CTL		0x405	//FCU Control
    #define D7F0_RSV_122			BIT7	//0/0/x/x Reserved
    #define D7F0_RFCUCTL			BIT6	//0/0/0/x FCU Timer Control
    #define D7F0_RACKCLPS			(BIT4 + BIT5)	//01b/01b/01b/x ACK Minimum Latency Control
    #define D7F0_RSV_123			(BIT2 + BIT3)	//0/0/x/x Reserved
    #define D7F0_RFCIENDC			BIT1	//0/0/0/x FCI Process End Condition
    #define D7F0_RFCIFREQ			BIT0	//0/0/0/x VC1 FCI Data Link Layer Packet (DLLP) Transmission Scheme
#define D7F0_TRANSACTION_LINK_LAYER_CHECKING_CTL		0x406	//Transaction / Link Layer Checking Control
    #define D7F0_RNAKFLGEN			BIT7	//0/0/0/x Nak_Scheduled Flag Control
    #define D7F0_RRCVTLTM			(BIT5 + BIT6)	//01b/1/1/x TLP Receiving Timer
    #define D7F0_RFASTHPOP			BIT4	//0/0/0/0 The First Downstream TLP Is Popped Out from TL 1T Earlier
    #define D7F0_RDISPMCACKRST			BIT3	//1b/1/x/x Enable the Receive Buffer Controller ((RXBCTL)) Reset Scheme When PM_Request_Ack DLLP Sequences Are Generated
    #define D7F0_RSV_124			(BIT1 + BIT2)	//0/0/x/x Reserved
    #define D7F0_RLCRCCHK			BIT0	//1b/1/1/x LCRC Check Control
#define D7F0_FCU_CTL_Z1		0x407	//FCU Control
    #define D7F0_RSV_125			0xF0	//0/0/x/x Reserved
    #define D7F0_RPFCUCTL			(BIT2 + BIT3)	//00b/00b/10b/x Update FCU According to TRANS FIFO Status
    #define D7F0_RNFCUCTL			(BIT0 + BIT1)	//00b/00b/11b/x Update FCU According to TRANS FIFO Status
#define D7F0_DATA_LINK_LAYER_HEADER_POSITION		0x408	//Data Link Layer Header Position
    #define D7F0_RSV_126			0xFE	//0/0/x/x Reserved
    #define D7F0_RSDPLN0			BIT0	//1b/1/1/x Data Link Layer Header Position
#define D7F0_RESERVED_Z16		0x409	//Reserved
    #define D7F0_RSV_126_1			0xFF	//0/x/x/x Reserved
#define D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X16_X8		0x40A	//Ack / Nak Latency Timer Limit for X16 / X8
    #define D7F0_RACKLTLM_L			0xFF	//06h/06h/06h/x Timer Limit for Ack / Nak Latency Timer and Update FC Latency Timer (in unit of 250MHz) for X16/X8
#define D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X4_X2		0x40B	//Ack / Nak Latency Timer Limit for X4 / X2
    #define D7F0_RACKLTLM_M			0xFF	//0Bh/0Bh/0Bh/x Timer Limit for Ack / Nak Latency Timer and Update FC Latency Timer (in unit of 250MHz) for X4/X2
#define D7F0_ACK_NAK_LATENCY_TIMER_LIMIT_FOR_X1		0x40C	//Ack / Nak Latency Timer Limit for X1
    #define D7F0_RACKLTLM_S			0xFF	//10h/10h/10h/x Timer Limit for Ack / Nak Latency Timer and Update FC Latency Timer (in unit of 250MHz) for X1
#define D7F0_REPLAY_TIMER_LIMIT_FOR_X32_X16		0x40D	//Replay Timer Limit for X32/X16
    #define D7F0_RRPLYTM_L			0xFF	//40h/40h/40h/x Replay Timer Limit for X16 /X8(in unit of 250MHz)
#define D7F0_REPLAY_TIMER_LIMIT_FOR_X8_X4		0x40E	//Replay Timer Limit for X8 / X4
    #define D7F0_RRPLYTM_M			0xFF	//80h/80h/80h/x Replay Timer Limit for X4 / X2 (in unit of 250MHz)
#define D7F0_REPLAY_TIMER_LIMIT_FOR_X2_X1		0x40F	//Replay Timer Limit for X2 / X1
    #define D7F0_RRPLYTM_S			0xFF	//F0h/F0h/F0h/x Replay Timer Limit for X1 (in unit of 250MHz)
#define D7F0_MOVE_CPU_DATA_FROM_VNA_TO_VN0		0x410	//Move CPU Data from VNA to VN0
    #define D7F0_RSV_322			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D7F0_RWCPMOVE			BIT4	//0/0/x/x Movement of WCP from VNA to VN0; Reserved
    #define D7F0_RMSGMOVE			BIT3	//0/0/x/x Movement of MSG from VNA to VN0; Reserved
    #define D7F0_RREQMOVE			BIT2	//0/0/x/x Movement of REQ from VNA to VN0; Reserved
    #define D7F0_RSRQMOVE			BIT1	//0/0/x/x Movement of SRQ from VNA to VN0; Reserved
    #define D7F0_RDATMOVE			BIT0	//0/0/x/x Movement of DAT from VNA to VN0; Reserved
#define D7F0_PUSH_CPU_DATA_INTO_VN0_VNA		0x411	//Push CPU Data into VN0/VNA
    #define D7F0_RSV_323			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D7F0_RWCP2VN0			BIT4	//1b/1/x/x Pushing of WCP packet into VN; Reserved
    #define D7F0_RMSG2VN0			BIT3	//1b/1/x/x Pushing of MSG packet into VN; Reserved
    #define D7F0_RREQ2VN0			BIT2	//1b/1/x/x Pushing of REQ packet into VN; Reserved
    #define D7F0_RSRQ2VN0			BIT1	//1b/1/x/x Pushing of SRQ packet into VN; Reserved
    #define D7F0_RDAT2VN0			BIT0	//1b/1/x/x Pushing of DAT packet into VN; Reserved
#define D7F0_WEIGHT_OF_EIGHT_TX_VN_CHN_FOR_ARBITRATION		0x412	//Weight of Eight TX VN Channel for Arbitration
    #define D7F0_RTXWCPWT			(BIT14 + BIT15)	//00b/0/x/x Tx VN0 WCP Weight
    #define D7F0_RTXPMMWT			(BIT12 + BIT13)	//00b/0/x/x Tx VN0 PMM Weight
    #define D7F0_RTXVNAWT			(BIT10 + BIT11)	//00b/0/x/x Tx VN0 VNA Weight; Reserved
    #define D7F0_RTXMSGWT			(BIT8 + BIT9)	//00b/0/x/x Tx VN0 MSG Weight
    #define D7F0_RTXREQWT			(BIT6 + BIT7)	//00b/0/x/x Tx VN0 REQ Weight
    #define D7F0_RTXSRQWT			(BIT4 + BIT5)	//00b/0/x/x Tx VN0 SRQ Weight
    #define D7F0_RTXDATWT			(BIT2 + BIT3)	//00b/0/x/x Tx VN0 DAT weight
    #define D7F0_RTXSRPWT			(BIT0 + BIT1)	//00b/0/x/x Tx VN0 SRP weight
#define D7F0_WEIGHT_OF_EIGHT_RX_VN_CHN_FOR_ARBITRATION		0x414	//Weight of Eight Rx VN Channel for Arbitration
    #define D7F0_RRXWCPWT			(BIT14 + BIT15)	//00b/0/x/x Rx VN0 WCP Weight
    #define D7F0_RRXPMMWT			(BIT12 + BIT13)	//00b/0/x/x Reserved (Rx VN0 PMM Weight)
    #define D7F0_RRXVNAWT			(BIT10 + BIT11)	//00b/0/x/x Rx VN0 VNA Weight; Reserved
    #define D7F0_RRXMSGWT			(BIT8 + BIT9)	//00b/0/x/x Rx VN0 MSG Weight
    #define D7F0_RRXREQWT			(BIT6 + BIT7)	//00b/0/x/x Rx VN0 REQ Weight
    #define D7F0_RRXSRQWT			(BIT4 + BIT5)	//00b/0/x/x Rx VN0 SRQ Weight
    #define D7F0_RRXDATWT			(BIT2 + BIT3)	//00b/0/x/x Rx VN0 DAT Weight
    #define D7F0_RRXSRPWT			(BIT0 + BIT1)	//00b/0/x/x Rx VN0 SRP Weight
#define D7F0_TIMER_CTL_FOR_BASIC_TX_VN_ARBITRATION		0x416	//Timer Control for Basic Tx VN Arbitration
    #define D7F0_RSV_324			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D7F0_RVNPRIOTOP			BIT4	//1b/1/1/x Top Priority When Timer RVNWAITTM Expired
    #define D7F0_RTXWCNTCLRTM			(BIT2 + BIT3)	//00b/0/x/x Timer Limit for Clearing WCnt
    #define D7F0_RTXVNPNDTM			(BIT0 + BIT1)	//10b/10b/10b/x Timer Limit for VN Request Being Pending for Arbitration
#define D7F0_TIMER_CTL_FOR_BASIC_RX_VN_ARBITRATION		0x417	//Timer Control for Basic Rx VN Arbitration
    #define D7F0_RSV_325			0xF0	//0/R/x/x Reserved
    #define D7F0_RRXWCNTCLRTM			(BIT2 + BIT3)	//00b/0/x/x Timer Limit for Clearing WCnt
    #define D7F0_RRXVNPNDTM			(BIT0 + BIT1)	//00b/0/x/x Timer Limit for VN Request Being Pending for Arbitration
#define D7F0_ENTRY_0_7_OF_THE_ARBITRATION_TABLE		0x418	//Entry 0-7 of the Arbitration Table
    #define D7F0_RARBTBENT07			(BIT21 + BIT22 + BIT23)	//111b/111b/x/x Arbitration Table Entry 7
    #define D7F0_RARBTBENT06			(BIT18 + BIT19 + BIT20)	//110b/110b/x/x Arbitration Table Entry 6
    #define D7F0_RARBTBENT05			(BIT15 + BIT16 + BIT17)	//101b/101b/x/x Arbitration Table Entry 5
    #define D7F0_RARBTBENT04			(BIT12 + BIT13 + BIT14)	//100b/100b/x/x Arbitration Table Entry 4
    #define D7F0_RARBTBENT03			(BIT9 + BIT10 + BIT11)	//011b/011b/x/x Arbitration Table Entry 3
    #define D7F0_RARBTBENT02			(BIT6 + BIT7 + BIT8)	//010b/010b/x/x Arbitration Table Entry 2
    #define D7F0_RARBTBENT01			(BIT3 + BIT4 + BIT5)	//001b/1/x/x Arbitration Table Entry 1
    #define D7F0_RARBTBENT00			(BIT0 + BIT1 + BIT2)	//000b/0/x/x Arbitration Table Entry 0
#define D7F0_RESERVED_Z17		0x41B	//Reserved
    #define D7F0_RSV_326			0xFF	//0/R/x/x Reserved
#define D7F0_ENTRY_8_15_OF_THE_ARBITRATION_TABLE		0x41C	//Entry 8-15 of the Arbitration Table
    #define D7F0_RARBTBENT15			(BIT21 + BIT22 + BIT23)	//111b/111b/x/x Arbitration Table Entry 15
    #define D7F0_RARBTBENT14			(BIT18 + BIT19 + BIT20)	//110b/110b/x/x Arbitration Table Entry 14
    #define D7F0_RARBTBENT13			(BIT15 + BIT16 + BIT17)	//101b/101b/x/x Arbitration Table Entry 13
    #define D7F0_RARBTBENT12			(BIT12 + BIT13 + BIT14)	//100b/100b/x/x Arbitration Table Entry 12
    #define D7F0_RARBTBENT11			(BIT9 + BIT10 + BIT11)	//011b/011b/x/x Arbitration Table Entry 11
    #define D7F0_RARBTBENT10			(BIT6 + BIT7 + BIT8)	//010b/010b/x/x Arbitration Table Entry 10
    #define D7F0_RARBTBENT09			(BIT3 + BIT4 + BIT5)	//001b/1/x/x Arbitration Table Entry 9
    #define D7F0_RARBTBENT08			(BIT0 + BIT1 + BIT2)	//000b/0/x/x Arbitration Table Entry 8
#define D7F0_RESERVED_Z18		0x41F	//Reserved
    #define D7F0_RSV_327			0xFF	//0/R/x/x Reserved
#define D7F0_ENTRY_16_23_OF_THE_ARBITRATION_TABLE		0x420	//Entry 16-23 of the Arbitration Table
    #define D7F0_RARBTBENT23			(BIT21 + BIT22 + BIT23)	//111b/111b/x/x Arbitration Table Entry 23
    #define D7F0_RARBTBENT22			(BIT18 + BIT19 + BIT20)	//110b/110b/x/x Arbitration Table Entry 22
    #define D7F0_RARBTBENT21			(BIT15 + BIT16 + BIT17)	//101b/101b/x/x Arbitration Table Entry 21
    #define D7F0_RARBTBENT20			(BIT12 + BIT13 + BIT14)	//100b/100b/x/x Arbitration Table Entry 20
    #define D7F0_RARBTBENT19			(BIT9 + BIT10 + BIT11)	//011b/011b/x/x Arbitration Table Entry 19
    #define D7F0_RARBTBENT18			(BIT6 + BIT7 + BIT8)	//010b/010b/x/x Arbitration Table Entry 18
    #define D7F0_RARBTBENT17			(BIT3 + BIT4 + BIT5)	//001b/1/x/x Arbitration Table Entry 17
    #define D7F0_RARBTBENT16			(BIT0 + BIT1 + BIT2)	//000b/0/x/x Arbitration Table Entry 16
#define D7F0_RESERVED_Z19		0x423	//Reserved
    #define D7F0_RSV_328			0xFF	//0/R/x/x Reserved
#define D7F0_ENTRY_24_31_OF_THE_ARBITRATION_TABLE		0x424	//Entry 24-31 of the Arbitration Table
    #define D7F0_RARBTBENT31			(BIT21 + BIT22 + BIT23)	//111b/111b/x/x Arbitration Table Entry 31
    #define D7F0_RARBTBENT30			(BIT18 + BIT19 + BIT20)	//110b/110b/x/x Arbitration Table Entry 30
    #define D7F0_RARBTBENT29			(BIT15 + BIT16 + BIT17)	//101b/101b/x/x Arbitration Table Entry 29
    #define D7F0_RARBTBENT28			(BIT12 + BIT13 + BIT14)	//100b/100b/x/x Arbitration Table Entry 28
    #define D7F0_RARBTBENT27			(BIT9 + BIT10 + BIT11)	//011b/011b/x/x Arbitration Table Entry 27
    #define D7F0_RARBTBENT26			(BIT6 + BIT7 + BIT8)	//010b/010b/x/x Arbitration Table Entry 26
    #define D7F0_RARBTBENT25			(BIT3 + BIT4 + BIT5)	//001b/1/x/x Arbitration Table Entry 25
    #define D7F0_RARBTBENT24			(BIT0 + BIT1 + BIT2)	//000b/0/x/x Arbitration Table Entry 24
#define D7F0_RESERVED_Z20		0x427	//Reserved
    #define D7F0_RSV_329			0xFF	//0/R/x/x Reserved
#define D7F0_TOKEN_BUCKET_DEPTH_FOR_SRC_RATE_LIMITING_ARBITRATION		0x428	//Token Bucket Depth for Source Rate Limiting Arbitration
    #define D7F0_RWCPTBDPT			(BIT14 + BIT15)	//00b/0/x/x WCP Token Bucket Depth (DW)
    #define D7F0_RPMMTBDPT			(BIT12 + BIT13)	//00b/0/x/x PMM Token Bucket Depth (DW)
    #define D7F0_RMSGTBDPT			(BIT10 + BIT11)	//00b/0/x/x MSG Token Bucket Depth (DW)
    #define D7F0_RDATTBDPT			(BIT8 + BIT9)	//00b/0/x/x DAT Token Bucket Depth (DW)
    #define D7F0_RSRQTBDPT			(BIT6 + BIT7)	//00b/0/x/x SRQ Token Bucket Depth (DW)
    #define D7F0_RVNATBDPT			(BIT4 + BIT5)	//00b/0/x/x VNA Token Bucket Depth (DW); Reserved
    #define D7F0_RSRPTBDPT			(BIT2 + BIT3)	//00b/0/x/x SRP Token Bucket Depth (DW)
    #define D7F0_RREQTBDPT			(BIT0 + BIT1)	//00b/0/x/x REQ Token Bucket Depth (DW)
#define D7F0_TOKEN_BUCKET_INJECTION_PERIOD_FOR_SRC_RATE_LIMITING_ARBITRATION		0x42A	//Token Bucket Injection Period for Source Rate Limiting Arbitration
    #define D7F0_RWCPTBIPR			(BIT14 + BIT15)	//00b/0/x/x WCP Token Bucket Injection Period (T)
    #define D7F0_RPMMTBIPR			(BIT12 + BIT13)	//00b/0/x/x PMM Token Bucket Injection Period (T)
    #define D7F0_RMSGTBIPR			(BIT10 + BIT11)	//00b/0/x/x MSG Token Bucket Injection Period (T)
    #define D7F0_RDATTBIPR			(BIT8 + BIT9)	//00b/0/x/x DAT Token Bucket Injection Period (T)
    #define D7F0_RSRQTBIPR			(BIT6 + BIT7)	//00b/0/x/x SRQ Token Bucket Injection Period (T)
    #define D7F0_RVNATBIPR			(BIT4 + BIT5)	//00b/0/x/x VNA Token Bucket Injection Period (T); Reserved
    #define D7F0_RSRPTBIPR			(BIT2 + BIT3)	//00b/0/x/x SRP Token Bucket Injection Period (T)
    #define D7F0_RREQTBIPR			(BIT0 + BIT1)	//00b/0/x/x REQ Token Bucket Injection Period (T)
#define D7F0_TOKEN_BUCKET_INJECTION_RATE_FOR_SRC_RATE_LIMITING_ARBITRATION		0x42C	//Token Bucket Injection Rate for Source Rate Limiting Arbitration
    #define D7F0_RWCPTBIRT			(BIT14 + BIT15)	//00b/0/x/x WCP Token Bucket Injection Rate (DW/RSRPINJPR)
    #define D7F0_RPMMTBIRT			(BIT12 + BIT13)	//00b/0/x/x PMM Token Bucket Injection Rate (DW/RSRPINJPR)
    #define D7F0_RMSGTBIRT			(BIT10 + BIT11)	//00b/0/x/x MSG Token Bucket Injection Rate (DW/RSRPINJPR)
    #define D7F0_RDATTBIRT			(BIT8 + BIT9)	//00b/0/x/x DAT Token Bucket Injection Rate (DW/RSRPINJPR)
    #define D7F0_RSRQTBIRT			(BIT6 + BIT7)	//00b/0/x/x SRQ Token Bucket Injection Rate (DW/RSRPINJPR)
    #define D7F0_RVNATBIRT			(BIT4 + BIT5)	//00b/0/x/x VNA Token Bucket Injection Rate (DW/RSRPINJPR); Reserved
    #define D7F0_RSRPTBIRT			(BIT2 + BIT3)	//00b/0/x/x SRP Token Bucket Injection Rate (DW/RSRPINJPR)
    #define D7F0_RREQTBIRT			(BIT0 + BIT1)	//00b/0/x/x REQ Token Bucket Injection Rate (DW/RSRPINJPR)
#define D7F0_ARBITRATION_METHOD_FOR_VN_CHNS		0x42E	//Arbitration Method for VN Channels
    #define D7F0_RVNARBMTD_PMM			(BIT14 + BIT15)	//10b/10b/x/x Arbitration Method for VN0 PMM Packet
    #define D7F0_RVNARBMTD_MSG			(BIT12 + BIT13)	//10b/10b/x/x Arbitration Method for VN0 Message Packet
    #define D7F0_RVNARBMTD_WCP			(BIT10 + BIT11)	//10b/10b/x/x Arbitration Method for VN0 Write Completion
    #define D7F0_RVNARBMTD_DAT			(BIT8 + BIT9)	//10b/10b/x/x Arbitration Method for VN0 Data packet
    #define D7F0_RVNARBMTD_VNA			(BIT6 + BIT7)	//10b/10b/x/x Arbitration Method for VNA Channel; Reserved
    #define D7F0_RVNARBMTD_SRQ			(BIT4 + BIT5)	//10b/10b/x/x Arbitration Method for VN0 Snoop Request
    #define D7F0_RVNARBMTD_SRP			(BIT2 + BIT3)	//10b/10b/x/x Arbitration Method for VN0 Snoop Response
    #define D7F0_RVNARBMTD_REQ			(BIT0 + BIT1)	//10b/10b/x/x Arbitration Method for VN0 Normal Request
#define D7F0_VPI_LINK_GLOBAL_DYNAMIC_CLK_CTL		0x430	//VPI Link Global Dynamic Clock Control
    #define D7F0_RSV_331			0xF0	//0/R/x/x Reserved
    #define D7F0_RDYNPMRX			BIT3	//0/0/x/x Receive Virtual Channel Controller Dynamic Clock Enable
    #define D7F0_RDYNPMTX			BIT2	//0/0/1/1 Transmit Virtual Channel Controller Dynamic Clock Enable
    #define D7F0_RDYNPMFC			BIT1	//0/0/0/x Flow Control Dynamic Clock Enable
    #define D7F0_RDYNPM			BIT0	//0/0/x/x Global Dynamic Clock Enable
#define D7F0_VPI_LINK_TRANSMIT_VIRTUAL_CHN_CTL_DYNAMIC_CLK_CTL		0x431	//VPI Link Transmit Virtual Channel Control Dynamic Clock Control
    #define D7F0_RDYNPMTXVNA			BIT7	//0/0/0/x Transmit VNA Controller Dynamic Clock Enable
    #define D7F0_RDYNPMTXPMM			BIT6	//0/0/0/x Transmit VN0 PM Message Controller Dynamic Clock Enable
    #define D7F0_RDYNPMTXWCP			BIT5	//0/0/0/x Transmit VN0 Write Completion Controller Dynamic Clock Enable
    #define D7F0_RDYNPMTXMSG			BIT4	//0/0/0/x Transmit VN0 Message Controller Dynamic Clock Enable
    #define D7F0_RDYNPMTXDAT			BIT3	//0/0/0/x Transmit VN0 Data Controller Dynamic Clock Enable
    #define D7F0_RDYNPMTXSRQ			BIT2	//0/0/0/x Transmit VN0 Snoop Request Controller Dynamic Clock Enable
    #define D7F0_RDYNPMTXSRP			BIT1	//0/0/0/x Transmit VN0 Snoop Response Controller Dynamic Clock Enable
    #define D7F0_RDYNPMTXREQ			BIT0	//0/0/0/x Transmit VN0 Request Controller Dynamic Clock Enable
#define D7F0_VPI_LINK_RECEIVE_VIRTUAL_CHN_CTL_DYNAMIC_CLK_CTL		0x432	//VPI Link Receive Virtual Channel Control Dynamic Clock Control
    #define D7F0_RDYNPMRXVNA			BIT7	//0/0/0/x Receive VNA Controller Dynamic Clock Enable
    #define D7F0_RDYNPMRXPMM			BIT6	//0/0/0/x Receive VN0 PM Message Controller Dynamic Clock Enable
    #define D7F0_RDYNPMRXWCP			BIT5	//0/0/0/x Receive VN0 Write Completion Controller Dynamic Clock Enable
    #define D7F0_RDYNPMRXMSG			BIT4	//0/0/0/x Receive VN0 Message Controller Dynamic Clock Enable
    #define D7F0_RDYNPMRXDAT			BIT3	//0/0/0/x Receive VN0 Data Controller Dynamic Clock Enable
    #define D7F0_RDYNPMRXSRQ			BIT2	//0/0/0/x Receive VN0 Snoop Request Controller Dynamic Clock Enable
    #define D7F0_RDYNPMRXSRP			BIT1	//0/0/0/x Receive VN0 Snoop Response Controller Dynamic Clock Enable
    #define D7F0_RDYNPMRXREQ			BIT0	//0/0/0/x Receive VN0 Request Controller Dynamic Clock Enable
#define D7F0_RESERVED_Z21		0x433	//Reserved
    #define D7F0_RSV_332			0xFC	//0/R/x/x Reserved
    #define D7F0_DLSRAMTIE0			BIT1	//0/x/x/x DL SRAM TIE 0
    #define D7F0_VPI_MODE			BIT0	//0/0/x/x Reserved
#define D7F0_RX_BLOCK_ARBITRATION_REQ_HP_TIMER_LIMIT		0x434	//RX Block Arbitration REQ HP Timer Limit
    #define D7F0_REQ_HPMAX_7_0			0xFF	//0Ch/ch/x/x REQ Request Get the High Priority on RX Part When the Timer Is Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_SRQ_HP_TIMER_LIMIT		0x435	//RX Block Arbitration SRQ HP Timer Limit
    #define D7F0_SRQ_HPMAX_7_0			0xFF	//0Ch/ch/x/x SRQ Request Get the high priority on RX Part When the Timer Is Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_SRP_HP_TIMER_LIMIT		0x436	//RX Block Arbitration SRP HP Timer Limit
    #define D7F0_SRP_HPMAX_7_0			0xFF	//0Ch/ch/x/x SRP Request Get the High Priority on RX Part When the Timer Is Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_DAT_HP_TIMER_LIMIT		0x437	//RX Block Arbitration DAT HP Timer Limit
    #define D7F0_DAT_HPMAX_7_0			0xFF	//0Ch/ch/x/X DAT Request Get the High Priority on RX Part When the Timer Is Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_WCP_HP_TIMER_LIMIT		0x438	//RX Block Arbitration WCP HP Timer Limit
    #define D7F0_WCP_HPMAX_7_0			0xFF	//0Ch/ch/x/X WCP Request Get the high priority on RX Part When the Timer Is Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_MSG_HP_TIMER_LIMIT		0x439	//RX Block Arbitration MSG HP Timer Limit
    #define D7F0_MSG_HPMAX_7_0			0xFF	//0Ch/ch/x/X MSG Request Get The High Priority on RX Part When the Timer Is Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_CREDIT_HP_TIMER_LIMIT		0x43A	//RX Block Arbitration Credit HP Timer Limit
    #define D7F0_CRD_HPMAX_7_0			0xFF	//0Ch/ch/x/x Credit Request Get The High Priority on RX Part When the Timer Is Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_REQ_HP_OCCUPY_TIMER_LIMIT		0x43B	//RX Block Arbitration REQ HP Occupy Timer Limit
    #define D7F0_REQ_HPOMAX_7_0			0xFF	//03h/3h/x/x REQ Request Release the high priority on RX Part When the HP Occupy Timer Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_SRQ_HP_OCCUPY_TIMER_LIMIT		0x43C	//RX Block Arbitration SRQ HP Occupy Timer Limit
    #define D7F0_SRQ_HPOMAX_7_0			0xFF	//03h/3h/x/x SRQ Request Release the high priority on RX part When the HP Occupy Timer Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_SRP_HP_OCCUPY_TIMER_LIMIT		0x43D	//RX Block Arbitration SRP HP Occupy Timer Limit
    #define D7F0_SRP_HPOMAX_7_0			0xFF	//03h/3h/x/x SRP Request Release the High Priority on RX Part When the HP Occupy Timer Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_DAT_HP_OCCUPY_TIMER_LIMIT		0x43E	//RX Block Arbitration DAT HP Occupy Timer Limit
    #define D7F0_DAT_HPOMAX_7_0			0xFF	//03h/3h/x/x DAT Request Release the High Priority on RX Part When the HP Occupy Timer Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_WCP_HP_OCCUPY_TIMER_LIMIT		0x43F	//RX Block Arbitration WCP HP Occupy Timer Limit
    #define D7F0_WCP_HPOMAX_7_0			0xFF	//03h/3h/x/x WCP Request Release the High Priority on RX Part When the HP Occupy Timer Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_MSG_HP_OCCUPY_TIMER_LIMIT		0x440	//RX Block Arbitration MSG HP Occupy Timer Limit
    #define D7F0_MSG_HPOMAX_7_0			0xFF	//03h/3h/x/x MSG Request Release the High Priority on RX Part When the HP Occupy Timer Get the Limit
#define D7F0_RX_BLOCK_ARBITRATION_CREDIT_HP_OCCUPY_TIMER_LIMIT		0x441	//RX Block Arbitration Credit HP Occupy Timer Limit
    #define D7F0_CRD_HPOMAX_7_0			0xFF	//03h/3h/x/x Credit Request Release the High Priority on RX Part When the HP Occupy Timer Get the Limit
#define D7F0_TX_REQ_FCI_INIT_REG_CTL		0x442	//TX REQ FCI Init Register Control
    #define D7F0_TXREQHFCI_3_0			0xF0	//4h/4h/4h/X REQ HEADER FCI Value Register Control
    #define D7F0_TXREQDFCI_3_0			0xF	//4h/4h/4h/x REQ DATA FCI Value Register Control
#define D7F0_TX_SRP_FCI_INIT_REG_CTL		0x443	//TX SRP FCI Init Register Control
    #define D7F0_TXSRPHFCI_3_0			0xF0	//4h/4h/4h/X SRP HEADER FCI Value Register Control
    #define D7F0_TXSRPDFCI_3_0			0xF	//4h/4h/4h/x SRP DATA FCI Value Register Control
#define D7F0_TX_SRQ_FCI_INIT_REG_CTL		0x444	//TX SRQ FCI Init Register Control
    #define D7F0_TXSRQHFCI_3_0			0xF0	//4h/4h/4h/X SRQ HEADER FCI Value Register Control
    #define D7F0_TXSRQDFCI_3_0			0xF	//4h/4h/4h/x SRQ DATA FCI Value Register Control
#define D7F0_TX_DAT_FCI_INIT_REG_CTL		0x445	//TX DAT FCI Init Register Control
    #define D7F0_TXDATHFCI_3_0			0xF0	//4h/4h/4h/X DAT HEADER FCI Value Register Control
    #define D7F0_TXDATDFCI_3_0			0xF	//4h/4h/4h/x DAT DATA FCI Value Register Control
#define D7F0_TX_WCP_FCI_INIT_REG_CTL		0x446	//TX WCP FCI Init Register Control
    #define D7F0_TXWCPHFCI_3_0			0xF0	//4h/4h/4h/X WCP HEADER FCI Value Register Control
    #define D7F0_TXWCPDFCI_3_0			0xF	//4h/4h/4h/x WCP DATA FCI Value Register Control
#define D7F0_TX_MSG_FCI_INIT_REG_CTL		0x447	//TX MSG FCI Init Register Control
    #define D7F0_TXMSGHFCI_3_0			0xF0	//4h/4h/4h/X MSG HEADER FCI Value Register Control
    #define D7F0_TXMSGDFCI_3_0			0xF	//4h/4h/4h/x MSG DATA FCI Value Register Control
#define D7F0_SRQ_AND_REQ_FCU_UPDATE_WITH_EACH_TYPE_MASK_CNTER_CTL		0x448	//SRQ and REQ FCU Update with Each Type Mask Counter Control
    #define D7F0_FCU_REQ_MASKCNTLM_3_0			0xF0	//1h/1h/1h/X REQ FCU Mask Counter Limit
    #define D7F0_FCU_SRQ_MASKCNTLM_3_0			0xF	//2h/2h/2h/x SRQ FCU Mask Counter Limit
#define D7F0_DAT_AND_MSG_FCU_UPDATE_WITH_EACH_TYPE_MASK_CNTER_CTL		0x449	//DAT and MSG FCU Update with Each Type Mask Counter Control
    #define D7F0_FCU_MSG_MASKCNTLM_3_0			0xF0	//2h/2h/2h/X MSG FCU Mask Counter Limit
    #define D7F0_FCU_DAT_MASKCNTLM_3_0			0xF	//2h/2h/2h/x DAT FCU Mask Counter Limit
#define D7F0_WCP_FCU_UPDATE_WITH_EACH_TYPE_MASK_CNTER_CTL		0x44A	//WCP FCU Update with Each Type Mask Counter Control
    #define D7F0_RSV_44A			0xF0	//0/x/x/X Reserved
    #define D7F0_FCU_WCP_MASKCNTLM_3_0			0xF	//2h/2h/2h/x WCP FCU Mask Counter Limit
//PCIEPHYCFG
#define VPIPHYCFG_EPHY_ENTERING_TEST_MODE		0x500	//EPHY Entering Test Mode
    #define VPIPHYCFG_RSV_500_4			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP_MPLLPD_X8B			BIT3	//0/0/x/x Force Power Down EPHY MPLL
    #define VPIPHYCFG_RSV_500_2			BIT2	//0/0/x/x Reserved
    #define VPIPHYCFG_FHP_EPHYMSTEN_X8B			BIT1	//0/0/x/x Force to Turn on All Functions in Master Block when EPHY Testing
    #define VPIPHYCFG_RSV_500_0			BIT0	//0/0/x/x Reserved
#define VPIPHYCFG_TPLL_TURN_OFF		0x501	//TPLL Turn off
    #define VPIPHYCFG_RSV_501			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_RTPLL1PD_G2			BIT5	//0/x/x/x TPLL0 Gating
    #define VPIPHYCFG_RTPLL0PD_G3			BIT4	//0/x/x/x TPLL1 Gating
    #define VPIPHYCFG_RTPLL1_TIMER_LIM			(BIT2 + BIT3)	//01b/x/x/x TPLL1 Timer Limit
    #define VPIPHYCFG_RTPLL0_TIMER_LIM			(BIT0 + BIT1)	//01b/x/x/x TPLL0 Timer Limit
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_ENABLE_LANE00_07		0x502	//TX Swing Maunal Set Enable Lane00 ~ 07
    #define VPIPHYCFG_FRP07_PCIE_TXEQSET_EN			BIT7	//0/0/x/x PCIe TX Swing and EQ Manual Set Enable
    #define VPIPHYCFG_FRP06_PCIE_TXEQSET_EN			BIT6	//0/0/x/x PCIe TX Swing and EQ Manual Set Enable
    #define VPIPHYCFG_FRP05_PCIE_TXEQSET_EN			BIT5	//0/0/x/x PCIe TX Swing and EQ Manual Set Enable
    #define VPIPHYCFG_FRP04_PCIE_TXEQSET_EN			BIT4	//0/0/x/x PCIe TX Swing and EQ Manual Set Enable
    #define VPIPHYCFG_FRP03_PCIE_TXEQSET_EN			BIT3	//0/0/x/x PCIe TX Swing and EQ Manual Set Enable
    #define VPIPHYCFG_FRP02_PCIE_TXEQSET_EN			BIT2	//0/0/x/x PCIe TX Swing and EQ Manual Set Enable
    #define VPIPHYCFG_FRP01_PCIE_TXEQSET_EN			BIT1	//0/0/x/x PCIe TX Swing and EQ Manual Set Enable
    #define VPIPHYCFG_FRP00_PCIE_TXEQSET_EN			BIT0	//0/0/x/x PCIe TX Swing and EQ Manual Set Enable
#define VPIPHYCFG_FHP_TPLLPD_TPLL_PWR_DOWN		0x503	//FHP TPLLPD (TPLL Power Down)
    #define VPIPHYCFG_RSV_503_4			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP1_TPLLPD_X8B			BIT3	//0/0/x/x EPHYC TPLL 1 Power Down Control
    #define VPIPHYCFG_FHP0_TPLLPD_X8B			BIT2	//0/0/x/x EPHYC TPLL 0 Power Down Control
    #define VPIPHYCFG_RSV_503_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define VPIPHYCFG_PWR_STATE_CTL_FOR_LANE00		0x510	//Power State Control for Lane00
    #define VPIPHYCFG_RSV_510_7			BIT7	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP00_TXEIDLESETB			BIT6	//0/0/x/x TX Electrical Idle Control
    #define VPIPHYCFG_FRP00_TXEIDLESETEN			BIT5	//0/0/x/x External Register of TX Electrical Idle Register Set
    #define VPIPHYCFG_FRP00_TXPWRSET_3_0			0x1E	//0/0/x/x TX Power Status Set
    #define VPIPHYCFG_FRP00_TXPWRSETEN			BIT0	//0/0/x/x TX Power Status Set Enable
#define VPIPHYCFG_PWR_STATE_CTL_FOR_LANE01		0x511	//Power State Control for Lane01
    #define VPIPHYCFG_RSV_511_7			BIT7	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP01_TXEIDLESETB			BIT6	//0/0/x/x TX Electrical Idle Control
    #define VPIPHYCFG_FRP01_TXEIDLESETEN			BIT5	//0/0/x/x External Register of TX Electrical Idle Register Set
    #define VPIPHYCFG_FRP01_TXPWRSET_3_0			0x1E	//0/0/x/x TX Power Status Set
    #define VPIPHYCFG_FRP01_TXPWRSETEN			BIT0	//0/0/x/x TX Power Status Set Enable
#define VPIPHYCFG_PWR_STATE_CTL_FOR_LANE02		0x512	//Power State Control for Lane02
    #define VPIPHYCFG_RSV_512_7			BIT7	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP02_TXEIDLESETB			BIT6	//0/0/x/x TX Electrical Idle Control
    #define VPIPHYCFG_FRP02_TXEIDLESETEN			BIT5	//0/0/x/x External Register of TX Electrical Idle Register Set
    #define VPIPHYCFG_FRP02_TXPWRSET_3_0			0x1E	//0/0/x/x TX Power Status Set
    #define VPIPHYCFG_FRP02_TXPWRSETEN			BIT0	//0/0/x/x TX Power Status Set Enable
#define VPIPHYCFG_PWR_STATE_CTL_FOR_LANE03		0x513	//Power State Control for Lane03
    #define VPIPHYCFG_RSV_513_7			BIT7	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP03_TXEIDLESETB			BIT6	//0/0/x/x TX Electrical Idle Control
    #define VPIPHYCFG_FRP03_TXEIDLESETEN			BIT5	//0/0/x/x External Register of TX Electrical Idle Register Set
    #define VPIPHYCFG_FRP03_TXPWRSET_3_0			0x1E	//0/0/x/x TX Power Status Set
    #define VPIPHYCFG_FRP03_TXPWRSETEN			BIT0	//0/0/x/x TX Power Status Set Enable
#define VPIPHYCFG_PWR_STATE_CTL_FOR_LANE04		0x514	//Power State Control for Lane04
    #define VPIPHYCFG_RSV_514_7			BIT7	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP04_TXEIDLESETB			BIT6	//0/0/x/x TX Electrical Idle Control
    #define VPIPHYCFG_FRP04_TXEIDLESETEN			BIT5	//0/0/x/x External Register of TX Electrical Idle Register Set
    #define VPIPHYCFG_FRP04_TXPWRSET_3_0			0x1E	//0/0/x/x TX Power Status Set
    #define VPIPHYCFG_FRP04_TXPWRSETEN			BIT0	//0/0/x/x TX Power Status Set Enable
#define VPIPHYCFG_PWR_STATE_CTL_FOR_LANE05		0x515	//Power State Control for Lane05
    #define VPIPHYCFG_RSV_515_7			BIT7	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP05_TXEIDLESETB			BIT6	//0/0/x/x TX Electrical Idle Control
    #define VPIPHYCFG_FRP05_TXEIDLESETEN			BIT5	//0/0/x/x External Register of TX Electrical Idle Register Set
    #define VPIPHYCFG_FRP05_TXPWRSET_3_0			0x1E	//0/0/x/x TX Power Status Set
    #define VPIPHYCFG_FRP05_TXPWRSETEN			BIT0	//0/0/x/x TX Power Status Set Enable
#define VPIPHYCFG_PWR_STATE_CTL_FOR_LANE06		0x516	//Power State Control for Lane06
    #define VPIPHYCFG_RSV_516_7			BIT7	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP06_TXEIDLESETB			BIT6	//0/0/x/x TX Electrical Idle Control
    #define VPIPHYCFG_FRP06_TXEIDLESETEN			BIT5	//0/0/x/x External Register of TX Electrical Idle Register Set
    #define VPIPHYCFG_FRP06_TXPWRSET_3_0			0x1E	//0/0/x/x TX Power Status Set
    #define VPIPHYCFG_FRP06_TXPWRSETEN			BIT0	//0/0/x/x TX Power Status Set Enable
#define VPIPHYCFG_PWR_STATE_CTL_FOR_LANE07		0x517	//Power State Control for Lane07
    #define VPIPHYCFG_RSV_517_7			BIT7	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP07_TXEIDLESETB			BIT6	//0/0/x/x TX Electrical Idle Control
    #define VPIPHYCFG_FRP07_TXEIDLESETEN			BIT5	//0/0/x/x External Register of TX Electrical Idle Register Set
    #define VPIPHYCFG_FRP07_TXPWRSET_3_0			0x1E	//0/0/x/x TX Power Status Set
    #define VPIPHYCFG_FRP07_TXPWRSETEN			BIT0	//0/0/x/x TX Power Status Set Enable
#define VPIPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE00		0x520	//CM and DT Driver Speed Set Lane00
    #define VPIPHYCFG_RSV_520			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP00_SPEEDSET_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Speed Manual Set Register
    #define VPIPHYCFG_FRP00_SPEEDSETEN			BIT0	//0/0/x/x Speed Manual Set Enable
#define VPIPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE01		0x521	//CM and DT Driver Speed Set Lane01
    #define VPIPHYCFG_RSV_521			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP01_SPEEDSET_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Speed Manual Set Register
    #define VPIPHYCFG_FRP01_SPEEDSETEN			BIT0	//0/0/x/x Speed Manual Set Enable
#define VPIPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE02		0x522	//CM and DT Driver Speed Set Lane02
    #define VPIPHYCFG_RSV_522			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP02_SPEEDSET_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Speed Manual Set Register
    #define VPIPHYCFG_FRP02_SPEEDSETEN			BIT0	//0/0/x/x Speed Manual Set Enable
#define VPIPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE03		0x523	//CM and DT Driver Speed Set Lane03
    #define VPIPHYCFG_RSV_523			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP03_SPEEDSET_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Speed Manual Set Register
    #define VPIPHYCFG_FRP03_SPEEDSETEN			BIT0	//0/0/x/x Speed Manual Set Enable
#define VPIPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE04		0x524	//CM and DT Driver Speed Set Lane04
    #define VPIPHYCFG_RSV_524			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP04_SPEEDSET_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Speed Manual Set Register
    #define VPIPHYCFG_FRP04_SPEEDSETEN			BIT0	//0/0/x/x Speed Manual Set Enable
#define VPIPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE05		0x525	//CM and DT Driver Speed Set Lane05
    #define VPIPHYCFG_RSV_525			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP05_SPEEDSET_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Speed Manual Set Register
    #define VPIPHYCFG_FRP05_SPEEDSETEN			BIT0	//0/0/x/x Speed Manual Set Enable
#define VPIPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE06		0x526	//CM and DT Driver Speed Set Lane06
    #define VPIPHYCFG_RSV_526			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP06_SPEEDSET_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Speed Manual Set Register
    #define VPIPHYCFG_FRP06_SPEEDSETEN			BIT0	//0/0/x/x Speed Manual Set Enable
#define VPIPHYCFG_CM_AND_DT_DRIVER_SPEED_SET_LANE07		0x527	//CM and DT Driver Speed Set Lane07
    #define VPIPHYCFG_RSV_527			0xF0	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP07_SPEEDSET_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Speed Manual Set Register
    #define VPIPHYCFG_FRP07_SPEEDSETEN			BIT0	//0/0/x/x Speed Manual Set Enable
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_LANE00		0x530	//TX Swing Maunal Set Lane00
    #define VPIPHYCFG_FRP00_PCIE_TXEQSET_7_0			0xFF	//0/0/x/x TX Swing Maunal Setting
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_LANE01		0x531	//TX Swing Maunal Set Lane01
    #define VPIPHYCFG_FRP01_PCIE_TXEQSET_7_0			0xFF	//0/0/x/x TX Swing Maunal Setting
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_LANE02		0x532	//TX Swing Maunal Set Lane02
    #define VPIPHYCFG_FRP02_PCIE_TXEQSET_7_0			0xFF	//0/0/x/x TX Swing Maunal Setting
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_LANE03		0x533	//TX Swing Maunal Set Lane03
    #define VPIPHYCFG_FRP03_PCIE_TXEQSET_7_0			0xFF	//0/0/x/x TX Swing Maunal Setting
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_LANE04		0x534	//TX Swing Maunal Set Lane04
    #define VPIPHYCFG_FRP04_PCIE_TXEQSET_7_0			0xFF	//0/0/x/x TX Swing Maunal Setting
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_LANE05		0x535	//TX Swing Maunal Set Lane05
    #define VPIPHYCFG_FRP05_PCIE_TXEQSET_7_0			0xFF	//0/0/x/x TX Swing Maunal Setting
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_LANE06		0x536	//TX Swing Maunal Set Lane06
    #define VPIPHYCFG_FRP06_PCIE_TXEQSET_7_0			0xFF	//0/0/x/x TX Swing Maunal Setting
#define VPIPHYCFG_TX_SWING_MAUNAL_SET_LANE07		0x537	//TX Swing Maunal Set Lane07
    #define VPIPHYCFG_FRP07_PCIE_TXEQSET_7_0			0xFF	//0/0/x/x TX Swing Maunal Setting
#define VPIPHYCFG_RX_PWR_STATE_CTL_LANE00		0x540	//RX Power State Control Lane00
    #define VPIPHYCFG_RSV_540			0xF8	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP00_RXPWRSETEN			BIT2	//0/0/x/x RX Power Status Set Enable
    #define VPIPHYCFG_FRP00_RXPWRSET_1_0			(BIT0 + BIT1)	//0/0/x/x RX Power Status Set
#define VPIPHYCFG_RX_PWR_STATE_CTL_LANE01		0x541	//RX Power State Control Lane01
    #define VPIPHYCFG_RSV_541			0xF8	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP01_RXPWRSETEN			BIT2	//0/0/x/x RX Power Status Set Enable
    #define VPIPHYCFG_FRP01_RXPWRSET_1_0			(BIT0 + BIT1)	//0/0/x/x RX Power Status Set
#define VPIPHYCFG_RX_PWR_STATE_CTL_LANE02		0x542	//RX Power State Control Lane02
    #define VPIPHYCFG_RSV_542			0xF8	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP02_RXPWRSETEN			BIT2	//0/0/x/x RX Power Status Set Enable
    #define VPIPHYCFG_FRP02_RXPWRSET_1_0			(BIT0 + BIT1)	//0/0/x/x RX Power Status Set
#define VPIPHYCFG_RX_PWR_STATE_CTL_LANE03		0x543	//RX Power State Control Lane03
    #define VPIPHYCFG_RSV_543			0xF8	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP03_RXPWRSETEN			BIT2	//0/0/x/x RX Power Status Set Enable
    #define VPIPHYCFG_FRP03_RXPWRSET_1_0			(BIT0 + BIT1)	//0/0/x/x RX Power Status Set
#define VPIPHYCFG_RX_PWR_STATE_CTL_LANE04		0x544	//RX Power State Control Lane04
    #define VPIPHYCFG_RSV_544			0xF8	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP04_RXPWRSETEN			BIT2	//0/0/x/x RX Power Status Set Enable
    #define VPIPHYCFG_FRP04_RXPWRSET_1_0			(BIT0 + BIT1)	//0/0/x/x RX Power Status Set
#define VPIPHYCFG_RX_PWR_STATE_CTL_LANE05		0x545	//RX Power State Control Lane05
    #define VPIPHYCFG_RSV_545			0xF8	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP05_RXPWRSETEN			BIT2	//0/0/x/x RX Power Status Set Enable
    #define VPIPHYCFG_FRP05_RXPWRSET_1_0			(BIT0 + BIT1)	//0/0/x/x RX Power Status Set
#define VPIPHYCFG_RX_PWR_STATE_CTL_LANE06		0x546	//RX Power State Control Lane06
    #define VPIPHYCFG_RSV_546			0xF8	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP06_RXPWRSETEN			BIT2	//0/0/x/x RX Power Status Set Enable
    #define VPIPHYCFG_FRP06_RXPWRSET_1_0			(BIT0 + BIT1)	//0/0/x/x RX Power Status Set
#define VPIPHYCFG_RX_PWR_STATE_CTL_LANE07		0x547	//RX Power State Control Lane07
    #define VPIPHYCFG_RSV_547			0xF8	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP07_RXPWRSETEN			BIT2	//0/0/x/x RX Power Status Set Enable
    #define VPIPHYCFG_FRP07_RXPWRSET_1_0			(BIT0 + BIT1)	//0/0/x/x RX Power Status Set
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN1_LANE00		0x550	//Low Power Exit Latency Gen1 Lane00
    #define VPIPHYCFG_RSV_550			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP00_P1EXT_G1_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP00_P0SP2EXT_G1_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN1_LANE01		0x551	//Low Power Exit Latency Gen1 Lane01
    #define VPIPHYCFG_RSV_551			(BIT6 + BIT7)	//0/X/x/x Reserved
    #define VPIPHYCFG_FRP01_P1EXT_G1_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP01_P0SP2EXT_G1_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN1_LANE02		0x552	//Low Power Exit Latency Gen1 Lane02
    #define VPIPHYCFG_RSV_552			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP02_P1EXT_G1_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP02_P0SP2EXT_G1_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN1_LANE03		0x553	//Low Power Exit Latency Gen1 Lane03
    #define VPIPHYCFG_RSV_553			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP03_P1EXT_G1_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP03_P0SP2EXT_G1_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN1_LANE04		0x554	//Low Power Exit Latency Gen1 Lane04
    #define VPIPHYCFG_RSV_554			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP04_P1EXT_G1_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP04_P0SP2EXT_G1_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN1_LANE05		0x555	//Low Power Exit Latency Gen1 Lane05
    #define VPIPHYCFG_RSV_555			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP05_P1EXT_G1_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP05_P0SP2EXT_G1_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN1_LANE06		0x556	//Low Power Exit Latency Gen1 Lane06
    #define VPIPHYCFG_RSV_556			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP06_P1EXT_G1_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP06_P0SP2EXT_G1_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN1_LANE07		0x557	//Low Power Exit Latency Gen1 Lane07
    #define VPIPHYCFG_RSV_557			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP07_P1EXT_G1_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP07_P0SP2EXT_G1_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN2_LANE00		0x560	//Low Power Exit Latency Gen2 Lane00
    #define VPIPHYCFG_RSV_560			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP00_P1EXT_G2_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP00_P0SP2EXT_G2_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN2_LANE01		0x561	//Low Power Exit Latency Gen2 Lane01
    #define VPIPHYCFG_RSV_561			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP01_P1EXT_G2_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP01_P0SP2EXT_G2_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN2_LANE02		0x562	//Low Power Exit Latency Gen2 Lane02
    #define VPIPHYCFG_RSV_562			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP02_P1EXT_G2_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP02_P0SP2EXT_G2_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN2_LANE03		0x563	//Low Power Exit Latency Gen2 Lane03
    #define VPIPHYCFG_RSV_563			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP03_P1EXT_G2_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP03_P0SP2EXT_G2_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN2_LANE04		0x564	//Low Power Exit Latency Gen2 Lane04
    #define VPIPHYCFG_RSV_564			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP04_P1EXT_G2_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP04_P0SP2EXT_G2_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN2_LANE05		0x565	//Low Power Exit Latency Gen2 Lane05
    #define VPIPHYCFG_RSV_565			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP05_P1EXT_G2_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP05_P0SP2EXT_G2_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN2_LANE06		0x566	//Low Power Exit Latency Gen2 Lane06
    #define VPIPHYCFG_RSV_566			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP06_P1EXT_G2_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP06_P0SP2EXT_G2_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN2_LANE07		0x567	//Low Power Exit Latency Gen2 Lane07
    #define VPIPHYCFG_RSV_567			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP07_P1EXT_G2_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP07_P0SP2EXT_G2_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN3_LANE00		0x570	//Low Power Exit Latency Gen3 Lane00
    #define VPIPHYCFG_RSV_570			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP00_P1EXT_G3_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP00_P0SP2EXT_G3_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN3_LANE01		0x571	//Low Power Exit Latency Gen3 Lane01
    #define VPIPHYCFG_RSV_571			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP01_P1EXT_G3_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP01_P0SP2EXT_G3_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN3_LANE02		0x572	//Low Power Exit Latency Gen3 Lane02
    #define VPIPHYCFG_RSV_572			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP02_P1EXT_G3_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP02_P0SP2EXT_G3_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN3_LANE03		0x573	//Low Power Exit Latency Gen3 Lane03
    #define VPIPHYCFG_RSV_573			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP03_P1EXT_G3_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP03_P0SP2EXT_G3_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN3_LANE04		0x574	//Low Power Exit Latency Gen3 Lane04
    #define VPIPHYCFG_RSV_574			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP04_P1EXT_G3_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP04_P0SP2EXT_G3_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN3_LANE05		0x575	//Low Power Exit Latency Gen3 Lane05
    #define VPIPHYCFG_RSV_575			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP05_P1EXT_G3_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP05_P0SP2EXT_G3_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN3_LANE06		0x576	//Low Power Exit Latency Gen3 Lane06
    #define VPIPHYCFG_RSV_576			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP06_P1EXT_G3_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP06_P0SP2EXT_G3_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LOW_PWR_EXIT_LATENCY_GEN3_LANE07		0x577	//Low Power Exit Latency Gen3 Lane07
    #define VPIPHYCFG_RSV_577			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FRP07_P1EXT_G3_2_0			(BIT3 + BIT4 + BIT5)	//100b/100b/x/x ExitLatency P1 Exit Latency
    #define VPIPHYCFG_FRP07_P0SP2EXT_G3_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x ExitLatency P0s Exit Latency
#define VPIPHYCFG_LEQ_DC_GAIN_OUTPUT_LANE_00		0x580	//LEQ DC Gain Output Lane 00
    #define VPIPHYCFG_RSV_580			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP00_DCOUT			0x1F	//HwInit/x/x/x LEQ DC Gain Output
#define VPIPHYCFG_LEQ_HF_GAIN_OUTPUT_LANE_00		0x581	//LEQ HF Gain Output Lane 00
    #define VPIPHYCFG_RSV_581			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP00_HFOUT			0x1F	//HwInit/x/x/x LEQ HF Gain Output
#define VPIPHYCFG_LEQ_OFFSET_OUTPUT_LANE_00		0x582	//LEQ Offset Output Lane 00
    #define VPIPHYCFG_RSV_582			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP00_OSOUT			0x1F	//HwInit/x/x/x LEQ OS Gain Output
#define VPIPHYCFG_LEQ_WEIGHT1_OUTPUT_LANE_00		0x583	//LEQ Weight1 Output Lane 00
    #define VPIPHYCFG_RSV_583			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP00_W1OUT			0x1F	//HwInit/x/x/x DFE Weight1 Output
#define VPIPHYCFG_LEQ_WEIGHT2_OUTPUT_LANE_00		0x584	//LEQ Weight2 Output Lane 00
    #define VPIPHYCFG_RSV_584			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP00_W2OUT			0x1F	//HwInit/x/x/x DFE Weight2 Output
#define VPIPHYCFG_RESERVED		0x585	//Reserved
    #define VPIPHYCFG_RSV_585			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z1		0x586	//Reserved
    #define VPIPHYCFG_RSV_586			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z2		0x587	//Reserved
    #define VPIPHYCFG_RSV_587			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE_00		0x588	//FAR-END Device Full Swing Value Lane 00
    #define VPIPHYCFG_RSV_588			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_FS_00			0x3F	//HwInit/x/x/x FAR-END Device Full Swing Value
#define VPIPHYCFG_FAR_END_DEV_LOW_FREQUENCY_VALUE_LANE_00		0x589	//FAR-END Device Low Frequency Value Lane 00
    #define VPIPHYCFG_RSV_589			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_LF_00			0x3F	//HwInit/x/x/x FAR-END Device Low Frequency Value
#define VPIPHYCFG_FAREND_TX_PRESET_LANE_00		0x58A	//FAREND_TX_PRESET Lane 00
    #define VPIPHYCFG_RSV_58A			0xF0	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_TX_PRESET_00			0xF	//HwInit/x/x/x Farend TX_PRESET
#define VPIPHYCFG_FAREND_PRE_CURSOR_LANE_00		0x58B	//FAREND_PRE_CURSOR Lane 00
    #define VPIPHYCFG_RSV_58B			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_PRE_CURSOR_00			0x3F	//HwInit/x/x/x Farend PRE_CURSOR
#define VPIPHYCFG_FAREND_CURSOR_LANE_00		0x58C	//FAREND_CURSOR Lane 00
    #define VPIPHYCFG_RSV_58C			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_CURSOR_00			0x3F	//HwInit/x/x/x Farend Cursor
#define VPIPHYCFG_FAREND_POST_CURSOR_LANE_00		0x58D	//FAREND_POST_CURSOR Lane 00
    #define VPIPHYCFG_RSV_58D			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_POST_CURSOR_00			0x3F	//HwInit/x/x/x Farend POST_CURSOR
#define VPIPHYCFG_BIT_ERR_RATE_LANE_00		0x58E	//BIT_ERROR_RATE Lane 00
    #define VPIPHYCFG_BIT_ERROR_RATE_00			0xFF	//HwInit/x/x/x Bit Error Rate
#define VPIPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_LANE_00		0x58F	//Farend Use TX Preset and RCV Lane 00
    #define VPIPHYCFG_RSV_58F			0xFC	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_USE_TX_PRESET_00			BIT1	//HwInit/x/x/x Farend Use TX Preset
    #define VPIPHYCFG_FAREND_RCV_00			BIT0	//HwInit/x/x/x Farend RCV
#define VPIPHYCFG_LEQ_DC_GAIN_OUTPUT_LANE_01		0x590	//LEQ DC Gain Output Lane 01
    #define VPIPHYCFG_RSV_590			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP01_DCOUT			0x1F	//HwInit/x/x/x LEQ DC Gain Output
#define VPIPHYCFG_LEQ_HF_GAIN_OUTPUT_LANE_01		0x591	//LEQ HF Gain Output Lane 01
    #define VPIPHYCFG_RSV_591			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP01_HFOUT			0x1F	//HwInit/x/x/x LEQ HF Gain Output
#define VPIPHYCFG_LEQ_OFFSET_OUTPUT_LANE_01		0x592	//LEQ Offset Output Lane 01
    #define VPIPHYCFG_RSV_592			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP01_OSOUT			0x1F	//HwInit/x/x/x LEQ OS Gain Output
#define VPIPHYCFG_LEQ_WEIGHT1_OUTPUT_LANE_01		0x593	//LEQ Weight1 Output Lane 01
    #define VPIPHYCFG_RSV_593			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP01_W1OUT			0x1F	//HwInit/x/x/x DFE Weight1 Output
#define VPIPHYCFG_LEQ_WEIGHT2_OUTPUT_LANE_01		0x594	//LEQ Weight2 Output Lane 01
    #define VPIPHYCFG_RSV_594			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP01_W2OUT			0x1F	//HwInit/x/x/x DFE Weight2 Output
#define VPIPHYCFG_RESERVED_Z3		0x595	//Reserved
    #define VPIPHYCFG_RSV_595			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z4		0x596	//Reserved
    #define VPIPHYCFG_RSV_596			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z5		0x597	//Reserved
    #define VPIPHYCFG_RSV_597			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE_01		0x598	//FAR-END Device Full Swing Value Lane 01
    #define VPIPHYCFG_RSV_598			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_FS_01			0x3F	//HwInit/x/x/x FAR-END Device Full Swing Value
#define VPIPHYCFG_FAR_END_DEV_LOW_FREQUENCY_VALUE_LANE_01		0x599	//FAR-END Device Low Frequency Value Lane 01
    #define VPIPHYCFG_RSV_599			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_LF_01			0x3F	//HwInit/x/x/x FAR-END Device Low Frequency Value
#define VPIPHYCFG_FAREND_TX_PRESET_LANE_01		0x59A	//FAREND_TX_PRESET Lane 01
    #define VPIPHYCFG_RSV_59A			0xF0	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_TX_PRESET_01			0xF	//HwInit/x/x/x Farend TX_PRESET
#define VPIPHYCFG_FAREND_PRE_CURSOR_LANE_01		0x59B	//FAREND_PRE_CURSOR Lane 01
    #define VPIPHYCFG_RSV_59B			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_PRE_CURSOR_01			0x3F	//HwInit/x/x/x Farend PRE_CURSOR
#define VPIPHYCFG_FAREND_CURSOR_LANE_01		0x59C	//FAREND_CURSOR Lane 01
    #define VPIPHYCFG_RSV_59C			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_CURSOR_01			0x3F	//HwInit/x/x/x Farend Cursor
#define VPIPHYCFG_FAREND_POST_CURSOR_LANE_01		0x59D	//FAREND_POST_CURSOR Lane 01
    #define VPIPHYCFG_RSV_59D			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_POST_CURSOR_01			0x3F	//HwInit/x/x/x Farend POST_CURSOR
#define VPIPHYCFG_BIT_ERR_RATE_LANE_01		0x59E	//BIT_ERROR_RATE Lane 01
    #define VPIPHYCFG_BIT_ERROR_RATE_01			0xFF	//HwInit/x/x/x Bit Error Rate
#define VPIPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_LANE_01		0x59F	//Farend Use TX Preset and RCV Lane 01
    #define VPIPHYCFG_RSV_59F			0xFC	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_USE_TX_PRESET_01			BIT1	//HwInit/x/x/x Farend Use TX Preset
    #define VPIPHYCFG_FAREND_RCV_01			BIT0	//HwInit/x/x/x Farend RCV
#define VPIPHYCFG_LEQ_DC_GAIN_OUTPUT_LANE_02		0x5A0	//LEQ DC Gain Output Lane 02
    #define VPIPHYCFG_RSV_5A0			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP02_DCOUT			0x1F	//HwInit/x/x/x LEQ DC Gain Output
#define VPIPHYCFG_LEQ_HF_GAIN_OUTPUT_LANE_02		0x5A1	//LEQ HF Gain Output Lane 02
    #define VPIPHYCFG_RSV_5A1			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP02_HFOUT			0x1F	//HwInit/x/x/x LEQ HF Gain Output
#define VPIPHYCFG_LEQ_OFFSET_OUTPUT_LANE_02		0x5A2	//LEQ Offset Output Lane 02
    #define VPIPHYCFG_RSV_5A2			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP02_OSOUT			0x1F	//HwInit/x/x/x LEQ OS Gain Output
#define VPIPHYCFG_LEQ_WEIGHT1_OUTPUT_LANE_02		0x5A3	//LEQ Weight1 Output Lane 02
    #define VPIPHYCFG_RSV_5A3			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP02_W1OUT			0x1F	//HwInit/x/x/x DFE Weight1 Output
#define VPIPHYCFG_LEQ_WEIGHT2_OUTPUT_LANE_02		0x5A4	//LEQ Weight2 Output Lane 02
    #define VPIPHYCFG_RSV_5A4			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP02_W2OUT			0x1F	//HwInit/x/x/x DFE Weight2 Output
#define VPIPHYCFG_RESERVED_Z6		0x5A5	//Reserved
    #define VPIPHYCFG_RSV_5A5			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z7		0x5A6	//Reserved
    #define VPIPHYCFG_RSV_5A6			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z8		0x5A7	//Reserved
    #define VPIPHYCFG_RSV_5A7			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE_02		0x5A8	//FAR-END Device Full Swing Value Lane 02
    #define VPIPHYCFG_RSV_5A8			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_FS_02			0x3F	//HwInit/x/x/x FAR-END Device Full Swing Value
#define VPIPHYCFG_FAR_END_DEV_LOW_FREQUENCY_VALUE_LANE_02		0x5A9	//FAR-END Device Low Frequency Value Lane 02
    #define VPIPHYCFG_RSV_5A9			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_LF_02			0x3F	//HwInit/x/x/x FAR-END Device Low Frequency Value
#define VPIPHYCFG_FAREND_TX_PRESET_LANE_02		0x5AA	//FAREND_TX_PRESET Lane 02
    #define VPIPHYCFG_RSV_5AA			0xF0	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_TX_PRESET_02			0xF	//HwInit/x/x/x Farend TX_PRESET
#define VPIPHYCFG_FAREND_PRE_CURSOR_LANE_02		0x5AB	//FAREND_PRE_CURSOR Lane 02
    #define VPIPHYCFG_RSV_5AB			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_PRE_CURSOR_02			0x3F	//HwInit/x/x/x Farend PRE_CURSOR
#define VPIPHYCFG_FAREND_CURSOR_LANE_02		0x5AC	//FAREND_CURSOR Lane 02
    #define VPIPHYCFG_RSV_5AC			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_CURSOR_02			0x3F	//HwInit/x/x/x Farend Cursor
#define VPIPHYCFG_FAREND_POST_CURSOR_LANE_02		0x5AD	//FAREND_POST_CURSOR Lane 02
    #define VPIPHYCFG_RSV_5AD			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_POST_CURSOR_02			0x3F	//HwInit/x/x/x Farend POST_CURSOR
#define VPIPHYCFG_BIT_ERR_RATE_LANE_02		0x5AE	//BIT_ERROR_RATE Lane 02
    #define VPIPHYCFG_BIT_ERROR_RATE_02			0xFF	//HwInit/x/x/x Bit Error Rate
#define VPIPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_LANE_02		0x5AF	//Farend Use TX Preset and RCV Lane 02
    #define VPIPHYCFG_RSV_5AF			0xFC	//0/R/x/x reserved
    #define VPIPHYCFG_FAREND_USE_TX_PRESET_02			BIT1	//HwInit/x/x/x Farend Use TX Preset
    #define VPIPHYCFG_FAREND_RCV_02			BIT0	//HwInit/x/x/x Farend RCV
#define VPIPHYCFG_LEQ_DC_GAIN_OUTPUT_LANE_03		0x5B0	//LEQ DC Gain Output Lane 03
    #define VPIPHYCFG_RSV_5B0			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP03_DCOUT			0x1F	//HwInit/x/x/x LEQ DC Gain Output
#define VPIPHYCFG_LEQ_HF_GAIN_OUTPUT_LANE_03		0x5B1	//LEQ HF Gain Output Lane 03
    #define VPIPHYCFG_RSV_5B1			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP03_HFOUT			0x1F	//HwInit/x/x/x LEQ HF Gain Output
#define VPIPHYCFG_LEQ_OFFSET_OUTPUT_LANE_03		0x5B2	//LEQ Offset Output Lane 03
    #define VPIPHYCFG_RSV_5B2			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP03_OSOUT			0x1F	//HwInit/x/x/x LEQ OS Gain Output
#define VPIPHYCFG_LEQ_WEIGHT1_OUTPUT_LANE_03		0x5B3	//LEQ Weight1 Output Lane 03
    #define VPIPHYCFG_RSV_5B3			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP03_W1OUT			0x1F	//HwInit/x/x/x DFE Weight1 Output
#define VPIPHYCFG_LEQ_WEIGHT2_OUTPUT_LANE_03		0x5B4	//LEQ Weight2 Output Lane 03
    #define VPIPHYCFG_RSV_5B4			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP03_W2OUT			0x1F	//HwInit/x/x/x DFE Weight2 Output
#define VPIPHYCFG_RESERVED_Z9		0x5B5	//Reserved
    #define VPIPHYCFG_RSV_5B5			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z10		0x5B6	//Reserved
    #define VPIPHYCFG_RSV_5B6			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z11		0x5B7	//Reserved
    #define VPIPHYCFG_RSV_5B7			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE_03		0x5B8	//FAR-END Device Full Swing Value Lane 03
    #define VPIPHYCFG_RSV_5B8			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_FS_03			0x3F	//HwInit/x/x/x FAR-END Device Full Swing Value
#define VPIPHYCFG_FAR_END_DEV_LOW_FREQUENCY_VALUE_LANE_03		0x5B9	//FAR-END Device Low Frequency Value Lane 03
    #define VPIPHYCFG_RSV_5B9			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_LF_03			0x3F	//HwInit/x/x/x FAR-END Device Low Frequency Value
#define VPIPHYCFG_FAREND_TX_PRESET_LANE_03		0x5BA	//FAREND_TX_PRESET Lane 03
    #define VPIPHYCFG_RSV_5BA			0xF0	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_TX_PRESET_03			0xF	//HwInit/x/x/x Farend TX_PRESET
#define VPIPHYCFG_FAREND_PRE_CURSOR_LANE_03		0x5BB	//FAREND_PRE_CURSOR Lane 03
    #define VPIPHYCFG_RSV_5BB			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_PRE_CURSOR_03			0x3F	//HwInit/x/x/x Farend PRE_CURSOR
#define VPIPHYCFG_FAREND_CURSOR_LANE_03		0x5BC	//FAREND_CURSOR Lane 03
    #define VPIPHYCFG_RSV_5BC			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_CURSOR_03			0x3F	//HwInit/x/x/x Farend Cursor
#define VPIPHYCFG_FAREND_POST_CURSOR_LANE_03		0x5BD	//FAREND_POST_CURSOR Lane 03
    #define VPIPHYCFG_RSV_5BD			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_POST_CURSOR_03			0x3F	//HwInit/x/x/x Farend POST_CURSOR
#define VPIPHYCFG_BIT_ERR_RATE_LANE_03		0x5BE	//BIT_ERROR_RATE Lane 03
    #define VPIPHYCFG_BIT_ERROR_RATE_03			0xFF	//HwInit/x/x/x Bit Error Rate
#define VPIPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_LANE_03		0x5BF	//Farend Use TX Preset and RCV Lane 03
    #define VPIPHYCFG_RSV_5BF			0xFC	//0/R/x/x reserved
    #define VPIPHYCFG_FAREND_USE_TX_PRESET_03			BIT1	//HwInit/x/x/x Farend Use TX Preset
    #define VPIPHYCFG_FAREND_RCV_03			BIT0	//HwInit/x/x/x Farend RCV
#define VPIPHYCFG_LEQ_DC_GAIN_OUTPUT_LANE_04		0x5C0	//LEQ DC Gain Output Lane 04
    #define VPIPHYCFG_RSV_5C0			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP04_DCOUT			0x1F	//HwInit/x/x/x LEQ DC Gain Output
#define VPIPHYCFG_LEQ_HF_GAIN_OUTPUT_LANE_04		0x5C1	//LEQ HF Gain Output Lane 04
    #define VPIPHYCFG_RSV_5C1			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP04_HFOUT			0x1F	//HwInit/x/x/x LEQ HF Gain Output
#define VPIPHYCFG_LEQ_OFFSET_OUTPUT_LANE_04		0x5C2	//LEQ Offset Output Lane 04
    #define VPIPHYCFG_RSV_5C2			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP04_OSOUT			0x1F	//HwInit/x/x/x LEQ OS Gain Output
#define VPIPHYCFG_LEQ_WEIGHT1_OUTPUT_LANE_04		0x5C3	//LEQ Weight1 Output Lane 04
    #define VPIPHYCFG_RSV_5C3			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP04_W1OUT			0x1F	//HwInit/x/x/x DFE Weight1 Output
#define VPIPHYCFG_LEQ_WEIGHT2_OUTPUT_LANE_04		0x5C4	//LEQ Weight2 Output Lane 04
    #define VPIPHYCFG_RSV_5C4			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP04_W2OUT			0x1F	//HwInit/x/x/x DFE Weight2 Output
#define VPIPHYCFG_RESERVED_Z12		0x5C5	//Reserved
    #define VPIPHYCFG_RSV_5C5			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z13		0x5C6	//Reserved
    #define VPIPHYCFG_RSV_5C6			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z14		0x5C7	//Reserved
    #define VPIPHYCFG_RSV_5C7			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE_04		0x5C8	//FAR-END Device Full Swing Value Lane 04
    #define VPIPHYCFG_RSV_5C8			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_FS_04			0x3F	//HwInit/x/x/x FAR-END Device Full Swing Value
#define VPIPHYCFG_FAR_END_DEV_LOW_FREQUENCY_VALUE_LANE_04		0x5C9	//FAR-END Device Low Frequency Value Lane 04
    #define VPIPHYCFG_RSV_5C9			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_LF_04			0x3F	//HwInit/x/x/x FAR-END Device Low Frequency Value
#define VPIPHYCFG_FAREND_TX_PRESET_LANE_04		0x5CA	//FAREND_TX_PRESET Lane 04
    #define VPIPHYCFG_RSV_5CA			0xF0	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_TX_PRESET_04			0xF	//HwInit/x/x/x Farend TX_PRESET
#define VPIPHYCFG_FAREND_PRE_CURSOR_LANE_04		0x5CB	//FAREND_PRE_CURSOR Lane 04
    #define VPIPHYCFG_RSV_5CB			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_PRE_CURSOR_04			0x3F	//HwInit/x/x/x Farend PRE_CURSOR
#define VPIPHYCFG_FAREND_CURSOR_LANE_04		0x5CC	//FAREND_CURSOR Lane 04
    #define VPIPHYCFG_RSV_5CC			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_CURSOR_04			0x3F	//HwInit/x/x/x Farend Cursor
#define VPIPHYCFG_FAREND_POST_CURSOR_LANE_04		0x5CD	//FAREND_POST_CURSOR Lane 04
    #define VPIPHYCFG_RSV_5CD			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_POST_CURSOR_04			0x3F	//HwInit/x/x/x Farend POST_CURSOR
#define VPIPHYCFG_BIT_ERR_RATE_LANE_04		0x5CE	//BIT_ERROR_RATE Lane 04
    #define VPIPHYCFG_BIT_ERROR_RATE_04			0xFF	//HwInit/x/x/x Bit Error Rate
#define VPIPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_LANE_04		0x5CF	//Farend Use TX Preset and RCV Lane 04
    #define VPIPHYCFG_RSV_5CF			0xFC	//0/R/x/x reserved
    #define VPIPHYCFG_FAREND_USE_TX_PRESET_04			BIT1	//HwInit/x/x/x Farend Use TX Preset
    #define VPIPHYCFG_FAREND_RCV_04			BIT0	//HwInit/x/x/x Farend RCV
#define VPIPHYCFG_LEQ_DC_GAIN_OUTPUT_LANE_05		0x5D0	//LEQ DC Gain Output Lane 05
    #define VPIPHYCFG_RSV_5D0			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP05_DCOUT			0x1F	//HwInit/x/x/x LEQ DC Gain Output
#define VPIPHYCFG_LEQ_HF_GAIN_OUTPUT_LANE_05		0x5D1	//LEQ HF Gain Output Lane 05
    #define VPIPHYCFG_RSV_5D1			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP05_HFOUT			0x1F	//HwInit/x/x/x LEQ HF Gain Output
#define VPIPHYCFG_LEQ_OFFSET_OUTPUT_LANE_05		0x5D2	//LEQ Offset Output Lane 05
    #define VPIPHYCFG_RSV_5D2			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP05_OSOUT			0x1F	//HwInit/x/x/x LEQ OS Gain Output
#define VPIPHYCFG_LEQ_WEIGHT1_OUTPUT_LANE_05		0x5D3	//LEQ Weight1 Output Lane 05
    #define VPIPHYCFG_RSV_5D3			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP05_W1OUT			0x1F	//HwInit/x/x/x DFE Weight1 Output
#define VPIPHYCFG_LEQ_WEIGHT2_OUTPUT_LANE_05		0x5D4	//LEQ Weight2 Output Lane 05
    #define VPIPHYCFG_RSV_5D4			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP05_W2OUT			0x1F	//HwInit/x/x/x DFE Weight2 Output
#define VPIPHYCFG_RESERVED_Z15		0x5D5	//Reserved
    #define VPIPHYCFG_RSV_5D5			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z16		0x5D6	//Reserved
    #define VPIPHYCFG_RSV_5D6			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z17		0x5D7	//Reserved
    #define VPIPHYCFG_RSV_5D7			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE_05		0x5D8	//FAR-END Device Full Swing Value Lane 05
    #define VPIPHYCFG_RSV_5D8			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_FS_05			0x3F	//HwInit/x/x/x FAR-END Device Full Swing Value
#define VPIPHYCFG_FAR_END_DEV_LOW_FREQUENCY_VALUE_LANE_05		0x5D9	//FAR-END Device Low Frequency Value Lane 05
    #define VPIPHYCFG_RSV_5D9			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_LF_05			0x3F	//HwInit/x/x/x FAR-END Device Low Frequency Value
#define VPIPHYCFG_FAREND_TX_PRESET_LANE_05		0x5DA	//FAREND_TX_PRESET Lane 05
    #define VPIPHYCFG_RSV_5DA			0xF0	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_TX_PRESET_05			0xF	//HwInit/x/x/x Farend TX_PRESET
#define VPIPHYCFG_FAREND_PRE_CURSOR_LANE_05		0x5DB	//FAREND_PRE_CURSOR Lane 05
    #define VPIPHYCFG_RSV_5DB			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_PRE_CURSOR_05			0x3F	//HwInit/x/x/x Farend PRE_CURSOR
#define VPIPHYCFG_FAREND_CURSOR_LANE_05		0x5DC	//FAREND_CURSOR Lane 05
    #define VPIPHYCFG_RSV_5DC			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_CURSOR_05			0x3F	//HwInit/x/x/x Farend Cursor
#define VPIPHYCFG_FAREND_POST_CURSOR_LANE_05		0x5DD	//FAREND_POST_CURSOR Lane 05
    #define VPIPHYCFG_RSV_5DD			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_POST_CURSOR_05			0x3F	//HwInit/x/x/x Farend POST_CURSOR
#define VPIPHYCFG_BIT_ERR_RATE_LANE_05		0x5DE	//BIT_ERROR_RATE Lane 05
    #define VPIPHYCFG_BIT_ERROR_RATE_05			0xFF	//HwInit/x/x/x Bit Error Rate
#define VPIPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_LANE_05		0x5DF	//Farend Use TX Preset and RCV Lane 05
    #define VPIPHYCFG_RSV_5DF			0xFC	//0/R/x/x reserved
    #define VPIPHYCFG_FAREND_USE_TX_PRESET_05			BIT1	//HwInit/x/x/x Farend Use TX Preset
    #define VPIPHYCFG_FAREND_RCV_05			BIT0	//HwInit/x/x/x Farend RCV
#define VPIPHYCFG_LEQ_DC_GAIN_OUTPUT_LANE_06		0x5E0	//LEQ DC Gain Output Lane 06
    #define VPIPHYCFG_RSV_5E0			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP06_DCOUT			0x1F	//HwInit/x/x/x LEQ DC Gain Output
#define VPIPHYCFG_LEQ_HF_GAIN_OUTPUT_LANE_06		0x5E1	//LEQ HF Gain Output Lane 06
    #define VPIPHYCFG_RSV_5E1			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP06_HFOUT			0x1F	//HwInit/x/x/x LEQ HF Gain Output
#define VPIPHYCFG_LEQ_OFFSET_OUTPUT_LANE_06		0x5E2	//LEQ Offset Output Lane 06
    #define VPIPHYCFG_RSV_5E2			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP06_OSOUT			0x1F	//HwInit/x/x/x LEQ OS Gain Output
#define VPIPHYCFG_LEQ_WEIGHT1_OUTPUT_LANE_06		0x5E3	//LEQ Weight1 Output Lane 06
    #define VPIPHYCFG_RSV_5E3			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP06_W1OUT			0x1F	//HwInit/x/x/x DFE Weight1 Output
#define VPIPHYCFG_LEQ_WEIGHT2_OUTPUT_LANE_06		0x5E4	//LEQ Weight2 Output Lane 06
    #define VPIPHYCFG_RSV_5E4			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP06_W2OUT			0x1F	//HwInit/x/x/x DFE Weight2 Output
#define VPIPHYCFG_RESERVED_Z18		0x5E5	//Reserved
    #define VPIPHYCFG_RSV_5E5			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z19		0x5E6	//Reserved
    #define VPIPHYCFG_RSV_5E6			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z20		0x5E7	//Reserved
    #define VPIPHYCFG_RSV_5E7			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE_06		0x5E8	//FAR-END Device Full Swing Value Lane 06
    #define VPIPHYCFG_RSV_5E8			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_FS_06			0x3F	//HwInit/x/x/x FAR-END Device Full Swing Value
#define VPIPHYCFG_FAR_END_DEV_LOW_FREQUENCY_VALUE_LANE_06		0x5E9	//FAR-END Device Low Frequency Value Lane 06
    #define VPIPHYCFG_RSV_5E9			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_LF_06			0x3F	//HwInit/x/x/x FAR-END Device Low Frequency Value
#define VPIPHYCFG_FAREND_TX_PRESET_LANE_06		0x5EA	//FAREND_TX_PRESET Lane 06
    #define VPIPHYCFG_RSV_5EA			0xF0	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_TX_PRESET_06			0xF	//HwInit/x/x/x Farend TX_PRESET
#define VPIPHYCFG_FAREND_PRE_CURSOR_LANE_06		0x5EB	//FAREND_PRE_CURSOR Lane 06
    #define VPIPHYCFG_RSV_5EB			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_PRE_CURSOR_06			0x3F	//HwInit/x/x/x Farend PRE_CURSOR
#define VPIPHYCFG_FAREND_CURSOR_LANE_06		0x5EC	//FAREND_CURSOR Lane 06
    #define VPIPHYCFG_RSV_5EC			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_CURSOR_06			0x3F	//HwInit/x/x/x Farend Cursor
#define VPIPHYCFG_FAREND_POST_CURSOR_LANE_06		0x5ED	//FAREND_POST_CURSOR Lane 06
    #define VPIPHYCFG_RSV_5ED			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_POST_CURSOR_06			0x3F	//HwInit/x/x/x Farend POST_CURSOR
#define VPIPHYCFG_BIT_ERR_RATE_LANE_06		0x5EE	//BIT_ERROR_RATE Lane 06
    #define VPIPHYCFG_BIT_ERROR_RATE_06			0xFF	//HwInit/x/x/x Bit Error Rate
#define VPIPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_LANE_06		0x5EF	//Farend Use TX Preset and RCV Lane 06
    #define VPIPHYCFG_RSV_5EF			0xFC	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_USE_TX_PRESET_06			BIT1	//HwInit/x/x/x Farend Use TX Preset
    #define VPIPHYCFG_FAREND_RCV_06			BIT0	//HwInit/x/x/x Farend RCV
#define VPIPHYCFG_LEQ_DC_GAIN_OUTPUT_LANE_07		0x5F0	//LEQ DC Gain Output Lane 07
    #define VPIPHYCFG_RSV_5F0			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP07_DCOUT			0x1F	//HwInit/x/x/x LEQ DC Gain Output
#define VPIPHYCFG_LEQ_HF_GAIN_OUTPUT_LANE_07		0x5F1	//LEQ HF Gain Output Lane 07
    #define VPIPHYCFG_RSV_5F1			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP07_HFOUT			0x1F	//HwInit/x/x/x LEQ HF Gain Output
#define VPIPHYCFG_LEQ_OFFSET_OUTPUT_LANE_07		0x5F2	//LEQ Offset Output Lane 07
    #define VPIPHYCFG_RSV_5F2			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP07_OSOUT			0x1F	//HwInit/x/x/x LEQ OS Gain Output
#define VPIPHYCFG_LEQ_WEIGHT1_OUTPUT_LANE_07		0x5F3	//LEQ Weight1 Output Lane 07
    #define VPIPHYCFG_RSV_5F3			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP07_W1OUT			0x1F	//HwInit/x/x/x DFE Weight1 Output
#define VPIPHYCFG_LEQ_WEIGHT2_OUTPUT_LANE_07		0x5F4	//LEQ Weight2 Output Lane 07
    #define VPIPHYCFG_RSV_5F4			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_EP07_W2OUT			0x1F	//HwInit/x/x/x DFE Weight2 Output
#define VPIPHYCFG_RESERVED_Z21		0x5F5	//Reserved
    #define VPIPHYCFG_RSV_5F5			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z22		0x5F6	//Reserved
    #define VPIPHYCFG_RSV_5F6			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_RESERVED_Z23		0x5F7	//Reserved
    #define VPIPHYCFG_RSV_5F7			0xFF	//0/R/x/x Reserved
#define VPIPHYCFG_FAR_END_DEV_FULL_SWING_VALUE_LANE_07		0x5F8	//FAR-END Device Full Swing Value Lane 07
    #define VPIPHYCFG_RSV_5F8			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_FS_07			0x3F	//HwInit/x/x/x FAR-END Device Full Swing Value
#define VPIPHYCFG_FAR_END_DEV_LOW_FREQUENCY_VALUE_LANE_07		0x5F9	//FAR-END Device Low Frequency Value Lane 07
    #define VPIPHYCFG_RSV_5F9			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_LF_07			0x3F	//HwInit/x/x/x FAR-END Device Low Frequency Value
#define VPIPHYCFG_FAREND_TX_PRESET_LANE_07		0x5FA	//FAREND_TX_PRESET Lane 07
    #define VPIPHYCFG_RSV_5FA			0xF0	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_TX_PRESET_07			0xF	//HwInit/x/x/x Farend TX_PRESET
#define VPIPHYCFG_FAREND_PRE_CURSOR_LANE_07		0x5FB	//FAREND_PRE_CURSOR Lane 07
    #define VPIPHYCFG_RSV_5FB			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_PRE_CURSOR_07			0x3F	//HwInit/x/x/x Farend PRE_CURSOR
#define VPIPHYCFG_FAREND_CURSOR_LANE_07		0x5FC	//FAREND_CURSOR Lane 07
    #define VPIPHYCFG_RSV_5FC			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_CURSOR_07			0x3F	//HwInit/x/x/x Farend Cursor
#define VPIPHYCFG_FAREND_POST_CURSOR_LANE_07		0x5FD	//FAREND_POST_CURSOR Lane 07
    #define VPIPHYCFG_RSV_5FD			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define VPIPHYCFG_FAREND_POST_CURSOR_07			0x3F	//HwInit/x/x/x Farend POST_CURSOR
#define VPIPHYCFG_BIT_ERR_RATE_LANE_07		0x5FE	//BIT_ERROR_RATE Lane 07
    #define VPIPHYCFG_BIT_ERROR_RATE_07			0xFF	//HwInit/x/x/x Bit Error Rate
#define VPIPHYCFG_FAREND_USE_TX_PRESET_AND_RCV_LANE_07		0x5FF	//Farend Use TX Preset and RCV Lane 07
    #define VPIPHYCFG_RSV_5FF			0xFC	//0/R/x/x reserved
    #define VPIPHYCFG_FAREND_USE_TX_PRESET_07			BIT1	//HwInit/x/x/x Farend Use TX Preset
    #define VPIPHYCFG_FAREND_RCV_07			BIT0	//HwInit/x/x/x Farend RCV
#define VPIPHYCFG_VPI_PEMCU_BIOS_REG		0x600	//VPI PEMCU BIOS Register
    #define VPIPHYCFG_RSV_600			0xFE	//0/0/x/x Reserved
    #define VPIPHYCFG_R_PEMCU_BIOS			BIT0	//0/0/x/x Reserved
#define VPIPHYCFG_VPI_PEMCU_BIOS_REG_Z1		0x601	//VPI PEMCU BIOS Register
    #define VPIPHYCFG_RSV_601			0xFF	//0/0/x/x Reserved
#define VPIPHYCFG_VPI_PEMCU_BIOS_REG_Z2		0x602	//VPI PEMCU BIOS Register
    #define VPIPHYCFG_RSV_602			0xFF	//0/0/x/x Reserved
#define VPIPHYCFG_VPI_PEMCU_BIOS_REG_Z3		0x603	//VPI PEMCU BIOS Register
    #define VPIPHYCFG_RSV_603			0xFF	//0/0/x/x Reserved
#define VPIPHYCFG_MCU_SET_PRESET_LANE_00		0x700	//MCU Set Preset Lane_00
    #define VPIPHYCFG_RSV_700			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_USE_PRESET_00			BIT4	//0/x/x/x Use Cursor Setting or PRESET Setting
    #define VPIPHYCFG_MCU_TX_PRESET_00			0xF	//0/x/x/x TX_PRESET Value when Doing EQ
#define VPIPHYCFG_MCU_SET_PRE_CURSOR_LANE_00		0x701	//MCU Set Pre-cursor Lane_00
    #define VPIPHYCFG_RSV_701			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_PRE_CURSOR_00			0x3F	//0/x/x/x MCU Set Pre-cursor
#define VPIPHYCFG_MCU_SET_CURSOR_LANE_00		0x702	//MCU Set Cursor Lane_00
    #define VPIPHYCFG_RSV_702			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CURSOR_00			0x3F	//0/x/x/x MCU Set Cursor
#define VPIPHYCFG_MCU_SET_POST_CURSOR_LANE_00		0x703	//MCU Set Post-cursor Lane_00
    #define VPIPHYCFG_RSV_703			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_POST_CURSOR_00			0x3F	//0/x/x/x MCU Set Post-cursor
#define VPIPHYCFG_MCU_SET_PRESET_LANE_01		0x710	//MCU Set Preset Lane_01
    #define VPIPHYCFG_RSV_710			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_USE_PRESET_01			BIT4	//0/x/x/x Use Cursor Setting or PRESET Setting
    #define VPIPHYCFG_MCU_TX_PRESET_01			0xF	//0/x/x/x TX_PRESET Value when Doing EQ
#define VPIPHYCFG_MCU_SET_PRE_CURSOR_LANE_01		0x711	//MCU Set Pre-cursor Lane_01
    #define VPIPHYCFG_RSV_711			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_PRE_CURSOR_01			0x3F	//0/x/x/x MCU Set Pre-cursor
#define VPIPHYCFG_MCU_SET_CURSOR_LANE_01		0x712	//MCU Set Cursor Lane_01
    #define VPIPHYCFG_RSV_712			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CURSOR_01			0x3F	//0/x/x/x MCU Set Cursor
#define VPIPHYCFG_MCU_SET_POST_CURSOR_LANE_01		0x713	//MCU Set Post-cursor Lane_01
    #define VPIPHYCFG_RSV_713			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_POST_CURSOR_01			0x3F	//0/x/x/x MCU Set Post-cursor
#define VPIPHYCFG_MCU_SET_PRESET_LANE_02		0x720	//MCU Set Preset Lane_02
    #define VPIPHYCFG_RSV_720			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_USE_PRESET_02			BIT4	//0/x/x/x Use Cursor Setting or PRESET Setting
    #define VPIPHYCFG_MCU_TX_PRESET_02			0xF	//0/x/x/x TX_PRESET Value when Doing EQ
#define VPIPHYCFG_MCU_SET_PRE_CURSOR_LANE_02		0x721	//MCU Set Pre-cursor Lane_02
    #define VPIPHYCFG_RSV_721			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_PRE_CURSOR_02			0x3F	//0/x/x/x MCU Set Pre-cursor
#define VPIPHYCFG_MCU_SET_CURSOR_LANE_02		0x722	//MCU Set Cursor Lane_02
    #define VPIPHYCFG_RSV_722			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CURSOR_02			0x3F	//0/x/x/x MCU Set Cursor
#define VPIPHYCFG_MCU_SET_POST_CURSOR_LANE_02		0x723	//MCU Set Post-cursor Lane_02
    #define VPIPHYCFG_RSV_723			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_POST_CURSOR_02			0x3F	//0/x/x/x MCU Set Post-cursor
#define VPIPHYCFG_MCU_SET_PRESET_LANE_03		0x730	//MCU Set Preset Lane_03
    #define VPIPHYCFG_RSV_730			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_USE_PRESET_03			BIT4	//0/x/x/x Use Cursor Setting or PRESET Setting
    #define VPIPHYCFG_MCU_TX_PRESET_03			0xF	//0/x/x/x TX_PRESET Value when Doing EQ
#define VPIPHYCFG_MCU_SET_PRE_CURSOR_LANE_03		0x731	//MCU Set Pre-cursor Lane_03
    #define VPIPHYCFG_RSV_731			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_PRE_CURSOR_03			0x3F	//0/x/x/x MCU Set Pre-cursor
#define VPIPHYCFG_MCU_SET_CURSOR_LANE_03		0x732	//MCU Set Cursor Lane_03
    #define VPIPHYCFG_RSV_732			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CURSOR_03			0x3F	//0/x/x/x MCU Set Cursor
#define VPIPHYCFG_MCU_SET_POST_CURSOR_LANE_03		0x733	//MCU Set Post-cursor Lane_03
    #define VPIPHYCFG_RSV_733			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_POST_CURSOR_03			0x3F	//0/x/x/x MCU Set Post-cursor
#define VPIPHYCFG_MCU_SET_PRESET_LANE_04		0x740	//MCU Set Preset Lane_04
    #define VPIPHYCFG_RSV_740			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_USE_PRESET_04			BIT4	//0/x/x/x Use Cursor Setting or PRESET Setting
    #define VPIPHYCFG_MCU_TX_PRESET_04			0xF	//0/x/x/x TX_PRESET Value when Doing EQ
#define VPIPHYCFG_MCU_SET_PRE_CURSOR_LANE_04		0x741	//MCU Set Pre-cursor Lane_04
    #define VPIPHYCFG_RSV_741			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_PRE_CURSOR_04			0x3F	//0/x/x/x MCU Set Pre-cursor
#define VPIPHYCFG_MCU_SET_CURSOR_LANE_04		0x742	//MCU Set Cursor Lane_04
    #define VPIPHYCFG_RSV_742			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CURSOR_04			0x3F	//0/x/x/x MCU Set Cursor
#define VPIPHYCFG_MCU_SET_POST_CURSOR_LANE_04		0x743	//MCU Set Post-cursor Lane_04
    #define VPIPHYCFG_RSV_743			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_POST_CURSOR_04			0x3F	//0/x/x/x MCU Set Post-cursor
#define VPIPHYCFG_MCU_SET_PRESET_LANE_05		0x750	//MCU Set Preset Lane_05
    #define VPIPHYCFG_RSV_750			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_USE_PRESET_05			BIT4	//0/x/x/x Use Cursor Setting or PRESET Setting
    #define VPIPHYCFG_MCU_TX_PRESET_05			0xF	//0/x/x/x TX_PRESET Value When Doing EQ
#define VPIPHYCFG_MCU_SET_PRE_CURSOR_LANE_05		0x751	//MCU Set Pre-cursor Lane_05
    #define VPIPHYCFG_RSV_751			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_PRE_CURSOR_05			0x3F	//0/x/x/x MCU Set Pre-cursor
#define VPIPHYCFG_MCU_SET_CURSOR_LANE_05		0x752	//MCU Set Cursor Lane_05
    #define VPIPHYCFG_RSV_752			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CURSOR_05			0x3F	//0/x/x/x MCU Set Cursor
#define VPIPHYCFG_MCU_SET_POST_CURSOR_LANE_05		0x753	//MCU Set Post-cursor Lane_05
    #define VPIPHYCFG_RSV_753			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_POST_CURSOR_05			0x3F	//0/x/x/x MCU Set Post-cursor
#define VPIPHYCFG_MCU_SET_PRESET_LANE_06		0x760	//MCU Set Preset Lane_06
    #define VPIPHYCFG_RSV_760			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_USE_PRESET_06			BIT4	//0/x/x/x Use Cursor Setting or PRESET Setting
    #define VPIPHYCFG_MCU_TX_PRESET_06			0xF	//0/x/x/x TX_PRESET Value When Doing EQ
#define VPIPHYCFG_MCU_SET_PRE_CURSOR_LANE_06		0x761	//MCU Set Pre-cursor Lane_06
    #define VPIPHYCFG_RSV_761			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_PRE_CURSOR_06			0x3F	//0/x/x/x MCU Set Pre-cursor
#define VPIPHYCFG_MCU_SET_CURSOR_LANE_06		0x762	//MCU Set Cursor Lane_06
    #define VPIPHYCFG_RSV_762			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CURSOR_06			0x3F	//0/x/x/x MCU Set Cursor
#define VPIPHYCFG_MCU_SET_POST_CURSOR_LANE_06		0x763	//MCU Set Post-cursor Lane_06
    #define VPIPHYCFG_RSV_763			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_POST_CURSOR_06			0x3F	//0/x/x/x MCU Set Post-cursor
#define VPIPHYCFG_MCU_SET_PRESET_LANE_07		0x770	//MCU Set Preset Lane_07
    #define VPIPHYCFG_RSV_770			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_USE_PRESET_07			BIT4	//0/x/x/x Use Cursor Setting or PRESET Setting
    #define VPIPHYCFG_MCU_TX_PRESET_07			0xF	//0/x/x/x TX_PRESET Value when Doing EQ
#define VPIPHYCFG_MCU_SET_PRE_CURSOR_LANE_07		0x771	//MCU Set Pre-cursor Lane_07
    #define VPIPHYCFG_RSV_771			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_PRE_CURSOR_07			0x3F	//0/x/x/x MCU Set Pre-cursor
#define VPIPHYCFG_MCU_SET_CURSOR_LANE_07		0x772	//MCU Set Cursor Lane_07
    #define VPIPHYCFG_RSV_772			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CURSOR_07			0x3F	//0/x/x/x MCU Set Cursor
#define VPIPHYCFG_MCU_SET_POST_CURSOR_LANE_07		0x773	//MCU Set Post-cursor Lane_07
    #define VPIPHYCFG_RSV_773			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_POST_CURSOR_07			0x3F	//0/x/x/x MCU Set Post-cursor
#define VPIPHYCFG_INT_TO_MCU		0x800	//INT to MCU
    #define VPIPHYCFG_RSV_800			0xFC	//0/x/x/x Reserved
    #define VPIPHYCFG_EP_EQ_REQ			BIT1	//0/x/x/x End Point Device Want To Do EQ Interrupt Bit
    #define VPIPHYCFG_PF_EQ_REQ			BIT0	//0/x/x/x Request EQ Service Interrupt Bit
#define VPIPHYCFG_MCU_CHANGE_EQ_SETTING		0x801	//MCU Change EQ Setting
    #define VPIPHYCFG_RSV_801			0xFE	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_CHANGE_EQ			BIT0	//0/X/x/x MCU Change Preset or Cursor 
#define VPIPHYCFG_MCU_RESET_EQ_TUNING		0x802	//MCU Reset EQ Tuning
    #define VPIPHYCFG_RSV_802			0xFC	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_EQTNEN			BIT1	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_P1_OR_EQTNRSTB			BIT0	//1b/x/x/x MCU Sets RXPWR into P1 or Controls EQTNRSTB to Reset EQ Tuning.
#define VPIPHYCFG_MCU_SET_EQ_TUNING		0x803	//MCU Set EQ Tuning
    #define VPIPHYCFG_RSV_803			0xFE	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_EQCTL_SEL			BIT0	//0/x/x/x EQ Active Method Select
#define VPIPHYCFG_MCU_WORK_FINISH		0x804	//MCU Work Finish
    #define VPIPHYCFG_RSV_807			0xFFFFFE00	//0/x/x/x Reserved
    #define VPIPHYCFG_EQ_RESULT_DONE			BIT8	//HwInit/x/x/x EQ Result Is Ready for MCU
    #define VPIPHYCFG_RSV_C64			0xFE	//0/x/x/x Reserved
    #define VPIPHYCFG_MCU_DONE			BIT0	//0/x/x/x When MCU EQ Job Finishes, Write 1
#define VPIPHYCFG_MCU_INT_EQ_ENABLE		0x808	//MCU INT_EQ Enable
    #define VPIPHYCFG_RSV_808			0xFE	//0/x/x/x Reserved
    #define VPIPHYCFG_PF_EQ_REQ_EN			BIT0	//1b/x/x/x MCU INT_EQ Enable 
#define VPIPHYCFG_R_EQPH1_BER		0x809	//R_EQPH1_BER
    #define VPIPHYCFG_RSV_809			0xFE	//0/R/x/x Reserved
    #define VPIPHYCFG_R_EQPH1_BER_Z1			BIT0	//1b/x/x/x Check More Data in EQ Phase 1, so MCU Can Get Real Bit Error Rate in Phase 2
#define VPIPHYCFG_RESERVED_Z24		0x80A	//Reserved
    #define VPIPHYCFG_RSV_80A			0xFF	//0/x/x/x Reserved
#define VPIPHYCFG_LINK_AND_EP_EQ_REQ		0x80B	//Link and EP EQ REQ
    #define VPIPHYCFG_RSV_80B			0xFC	//0/x/x/x Reserved
    #define VPIPHYCFG_LINK_EQ_REQ			BIT1	//0/x/x/x Link EQ REQ 
    #define VPIPHYCFG_RSV_80B_0			BIT0	//0/x/x/x Reserved
#define VPIPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE_00		0x810	//Equalization Control Register Original Value Lane_00
    #define VPIPHYCFG_RSV_811			BIT15	//0/0/x/x Reserved
    #define VPIPHYCFG_USRXPRESETHITORG_00			(BIT12 + BIT13 + BIT14)	//111b/111b/x/x Upstream RX Preset Hint Original Value
    #define VPIPHYCFG_USTXPRESETORG_00			0xF00	//1111b/1111b/x/x Upstream TX Preset Original Value
    #define VPIPHYCFG_RSV_810			BIT7	//0/0/x/x Reserved
    #define VPIPHYCFG_DSRXPRESETHINTORG_00			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x Downstream RX Preset Hint Original Value
    #define VPIPHYCFG_DSTXPRESETORG_00			0xF	//1111b/1111b/x/x Downstream TX Preset Original Value
#define VPIPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE_01		0x812	//Equalization Control Register Original Value Lane_01
    #define VPIPHYCFG_RSV_813			BIT15	//0/0/x/x Reserved
    #define VPIPHYCFG_USRXPRESETHITORG_01			(BIT12 + BIT13 + BIT14)	//111b/111b/x/x Upstream RX Preset Hint Original Value
    #define VPIPHYCFG_USTXPRESETORG_01			0xF00	//1111b/1111b/x/x Upstream TX Preset Original Value
    #define VPIPHYCFG_RSV_812			BIT7	//0/0/x/x Reserved
    #define VPIPHYCFG_DSRXPRESETHINTORG_01			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x Downstream RX Preset Hint Original Value
    #define VPIPHYCFG_DSTXPRESETORG_01			0xF	//1111b/1111b/x/x Downstream TX Preset Original Value
#define VPIPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE_02		0x814	//Equalization Control Register Original Value Lane_02
    #define VPIPHYCFG_RSV_815			BIT15	//0/0/x/x Reserved
    #define VPIPHYCFG_USRXPRESETHITORG_02			(BIT12 + BIT13 + BIT14)	//111b/111b/x/x Upstream RX Preset Hint Original Value
    #define VPIPHYCFG_USTXPRESETORG_02			0xF00	//1111b/1111b/x/x Upstream TX Preset Original Value
    #define VPIPHYCFG_RSV_814			BIT7	//0/0/x/x Reserved
    #define VPIPHYCFG_DSRXPRESETHINTORG_02			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x Downstream RX Preset Hint Original Value
    #define VPIPHYCFG_DSTXPRESETORG_02			0xF	//1111b/1111b/x/x Downstream TX Preset Original Value
#define VPIPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE_03		0x816	//Equalization Control Register Original Value Lane_03
    #define VPIPHYCFG_RSV_817			BIT15	//0/0/x/x Reserved
    #define VPIPHYCFG_USRXPRESETHITORG_03			(BIT12 + BIT13 + BIT14)	//111b/111b/x/x Upstream RX Preset Hint Original Value
    #define VPIPHYCFG_USTXPRESETORG_03			0xF00	//1111b/1111b/x/x Upstream TX Preset Original Value
    #define VPIPHYCFG_RSV_816			BIT7	//0/0/x/x Reserved
    #define VPIPHYCFG_DSRXPRESETHINTORG_03			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x Downstream RX Preset Hint Original Value
    #define VPIPHYCFG_DSTXPRESETORG_03			0xF	//1111b/1111b/x/x Downstream TX Preset Original Value
#define VPIPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE_04		0x818	//Equalization Control Register Original Value Lane_04
    #define VPIPHYCFG_RSV_819			BIT15	//0/0/x/x Reserved
    #define VPIPHYCFG_USRXPRESETHITORG_04			(BIT12 + BIT13 + BIT14)	//111b/111b/x/x Upstream RX Preset Hint Original Value
    #define VPIPHYCFG_USTXPRESETORG_04			0xF00	//1111b/1111b/x/x Upstream TX Preset Original Value
    #define VPIPHYCFG_RSV_818			BIT7	//0/0/x/x Reserved
    #define VPIPHYCFG_DSRXPRESETHINTORG_04			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x Downstream RX Preset Hint Original Value
    #define VPIPHYCFG_DSTXPRESETORG_04			0xF	//1111b/1111b/x/x Downstream TX Preset Original Value
#define VPIPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE_05		0x81A	//Equalization Control Register Original Value Lane_05
    #define VPIPHYCFG_RSV_81B			BIT15	//0/0/x/x Reserved
    #define VPIPHYCFG_USRXPRESETHITORG_05			(BIT12 + BIT13 + BIT14)	//111b/111b/x/x Upstream RX Preset Hint Original Value
    #define VPIPHYCFG_USTXPRESETORG_05			0xF00	//1111b/1111b/x/x Upstream TX Preset Original Value
    #define VPIPHYCFG_RSV_81A			BIT7	//0/0/x/x Reserved
    #define VPIPHYCFG_DSRXPRESETHINTORG_05			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x Downstream RX Preset Hint Original Value
    #define VPIPHYCFG_DSTXPRESETORG_05			0xF	//1111b/1111b/x/x Downstream TX Preset Original Value
#define VPIPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE_06		0x81C	//Equalization Control Register Original Value Lane_06
    #define VPIPHYCFG_RSV_81D			BIT15	//0/0/x/x Reserved
    #define VPIPHYCFG_USRXPRESETHITORG_06			(BIT12 + BIT13 + BIT14)	//111b/111b/x/x Upstream RX Preset Hint Original Value
    #define VPIPHYCFG_USTXPRESETORG_06			0xF00	//1111b/1111b/x/x Upstream TX Preset Original Value
    #define VPIPHYCFG_RSV_81C			BIT7	//0/0/x/x Reserved
    #define VPIPHYCFG_DSRXPRESETHINTORG_06			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x Downstream RX Preset Hint Original Value
    #define VPIPHYCFG_DSTXPRESETORG_06			0xF	//1111b/1111b/x/x Downstream TX Preset Original Value
#define VPIPHYCFG_EQUALIZATION_CTL_REG_ORIGINAL_VALUE_LANE_07		0x81E	//Equalization Control Register Original Value Lane_07
    #define VPIPHYCFG_RSV_81F			BIT15	//0/0/x/x Reserved
    #define VPIPHYCFG_USRXPRESETHITORG_07			(BIT12 + BIT13 + BIT14)	//111b/111b/x/x Upstream RX Preset Hint Original Value
    #define VPIPHYCFG_USTXPRESETORG_07			0xF00	//1111b/1111b/x/x Upstream TX Preset Original Value
    #define VPIPHYCFG_RSV_81E			BIT7	//0/0/x/x Reserved
    #define VPIPHYCFG_DSRXPRESETHINTORG_07			(BIT4 + BIT5 + BIT6)	//111b/111b/x/x Downstream RX Preset Hint Original Value
    #define VPIPHYCFG_DSTXPRESETORG_07			0xF	//1111b/1111b/x/x Downstream TX Preset Original Value
#define VPIPHYCFG_RCHX002_R		0x820	//RCHX002 R
    #define VPIPHYCFG_RSV_820			0xFC	//0/x/x/x Reserved
    #define VPIPHYCFG_RHNRECOV			BIT1	//0/x/x/x Hotreset/Disable/Loopback in TS
    #define VPIPHYCFG_REQ2FBRECP			BIT0	//0/x/x/x Feedback USE_PRESET Flag during EQ Phase 2
#define VPIPHYCFG_RESERVED_Z25		0x821	//Reserved
    #define VPIPHYCFG_RSV_821			0xFF	//0/x/x/x Reserved
#define VPIPHYCFG_RESERVED_Z26		0x822	//Reserved
    #define VPIPHYCFG_RSV_822			0xFF	//0/x/x/x Reserved
#define VPIPHYCFG_RESERVED_Z27		0x823	//Reserved
    #define VPIPHYCFG_RSV_823			0xFF	//0/x/x/x Reserved
#define VPIPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE_00		0x840	//EPHY MACRO Test Mode Control for Lane 00
    #define VPIPHYCFG_RSV_840			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP00_RDETEN			BIT4	//0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define VPIPHYCFG_FHP00_TXRDETPDB			BIT3	//0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define VPIPHYCFG_FHP00_RXHZ			BIT2	//0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP00_TXHZ			BIT1	//0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP00_RXDEIDPDB			BIT0	//0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define VPIPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE_01		0x841	//EPHY MACRO Test Mode Control for Lane 01
    #define VPIPHYCFG_RSV_841			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP01_RDETEN			BIT4	//0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define VPIPHYCFG_FHP01_TXRDETPDB			BIT3	//0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define VPIPHYCFG_FHP01_RXHZ			BIT2	//0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP01_TXHZ			BIT1	//0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP01_RXDEIDPDB			BIT0	//0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define VPIPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE_02		0x842	//EPHY MACRO Test Mode Control for Lane 02
    #define VPIPHYCFG_RSV_842			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP02_RDETEN			BIT4	//0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define VPIPHYCFG_FHP02_TXRDETPDB			BIT3	//0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define VPIPHYCFG_FHP02_RXHZ			BIT2	//0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP02_TXHZ			BIT1	//0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP02_RXDEIDPDB			BIT0	//0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define VPIPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE_03		0x843	//EPHY MACRO Test Mode Control for Lane 03
    #define VPIPHYCFG_RSV_843			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP03_RDETEN			BIT4	//0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define VPIPHYCFG_FHP03_TXRDETPDB			BIT3	//0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define VPIPHYCFG_FHP03_RXHZ			BIT2	//0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP03_TXHZ			BIT1	//0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP03_RXDEIDPDB			BIT0	//0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define VPIPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE_04		0x844	//EPHY MACRO Test Mode Control for Lane 04
    #define VPIPHYCFG_RSV_844			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP04_RDETEN			BIT4	//0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define VPIPHYCFG_FHP04_TXRDETPDB			BIT3	//0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define VPIPHYCFG_FHP04_RXHZ			BIT2	//0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP04_TXHZ			BIT1	//0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP04_RXDEIDPDB			BIT0	//0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define VPIPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE_05		0x845	//EPHY MACRO Test Mode Control for Lane 05
    #define VPIPHYCFG_RSV_845			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP05_RDETEN			BIT4	//0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define VPIPHYCFG_FHP05_TXRDETPDB			BIT3	//0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define VPIPHYCFG_FHP05_RXHZ			BIT2	//0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP05_TXHZ			BIT1	//0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP05_RXDEIDPDB			BIT0	//0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define VPIPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE_06		0x846	//EPHY MACRO Test Mode Control for Lane 06
    #define VPIPHYCFG_RSV_846			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP06_RDETEN			BIT4	//0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define VPIPHYCFG_FHP06_TXRDETPDB			BIT3	//0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define VPIPHYCFG_FHP06_RXHZ			BIT2	//0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP06_TXHZ			BIT1	//0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP06_RXDEIDPDB			BIT0	//0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#define VPIPHYCFG_EPHY_MACRO_TEST_MODE_CTL_FOR_LANE_07		0x847	//EPHY MACRO Test Mode Control for Lane 07
    #define VPIPHYCFG_RSV_847			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define VPIPHYCFG_FHP07_RDETEN			BIT4	//0/0/x/x EPHY TX Receiver Detect Enable Control in MACRO Test Mode
    #define VPIPHYCFG_FHP07_TXRDETPDB			BIT3	//0/0/x/x EPHY TX Receiver Detect Power Down Control in MACRO Test Mode
    #define VPIPHYCFG_FHP07_RXHZ			BIT2	//0/0/x/x EPHY RXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP07_TXHZ			BIT1	//0/0/x/x EPHY TXHZ Control in MACRO Test Mode
    #define VPIPHYCFG_FHP07_RXDEIDPDB			BIT0	//0/0/x/x EPHY RX Electrical Idle Detect Power Down Control in MACRO Test Mode
#endif
