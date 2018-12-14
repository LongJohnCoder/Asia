//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		GFXACCESSANDDEBUGGINGCTRL					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D0F0_GfxAccessAndDebuggingCtrl_R102(A0).doc(final)MOD_D0F0.xls
#ifndef _CHX002_D0F0_GFXACCESSANDDEBUGGINGCTRL_H
#define _CHX002_D0F0_GFXACCESSANDDEBUGGINGCTRL_H
//D0F0
#define D0F0_VID		0x00	//Vendor ID
    #define D0F0_VENDORID_15_0			0xFFFF	//1106h/x/x/x Vendor ID
#define D0F0_DID		0x02	//Device ID
    #define D0F0_DEVID_15_0			0xFFFF	//1003h/x/x/x Device ID
#define D0F0_PCI_CMD		0x04	//PCI Command
    #define D0F0_RX04_15_10			0xFC00	//0/R/x/x Reserved
    #define D0F0_RFBACK			BIT9	//0/R/x/x Fast Back-to-Back Cycle Enable
    #define D0F0_RSERR			BIT8	//0/R/x/x SERR# Enable 
    #define D0F0_RSETP			BIT7	//0/R/x/x Address/Data Stepping
    #define D0F0_RPTYERR			BIT6	//0/0/x/x Parity Error Response
    #define D0F0_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D0F0_RMWINV			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D0F0_RSPCYC			BIT3	//0/R/x/x Respond To Special Cycle
    #define D0F0_RMSTR			BIT2	//1b/1/x/x PCI Master Function
    #define D0F0_RENMEM			BIT1	//1b/1/x/x Memory Space Access
    #define D0F0_RENIO			BIT0	//0/R/x/x I/O Space Access
#define D0F0_PCI_STA		0x06	//PCI Status
    #define D0F0_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D0F0_SERRS			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D0F0_SMABORT			BIT13	//0/R/x/x Received Master-Abort (Except Special Cycle)
    #define D0F0_STABORTM			BIT12	//0/R/x/x Received Target-Abort
    #define D0F0_STABORTS			BIT11	//0/R/x/x Target-Abort Assertion
    #define D0F0_DEVS_1_0			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D0F0_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D0F0_RFBKS			BIT7	//0/R/x/x Capable of Accepting Fast Back-to-Back as A Target
    #define D0F0_RUDF			BIT6	//0/R/x/x User Definable Features
    #define D0F0_R66M			BIT5	//0/R/x/x 66 MHz Capable
    #define D0F0_RCAP			BIT4	//1b/1b/x/x Support New Capability List
    #define D0F0_RX04_19_16			0xF	//0/R/x/x Reserved
#define D0F0_REV_ID		0x08	//Revision ID
    #define D0F0_RX08_7_0			0xFF	//80h/x/x/x Chip Revision Code
#define D0F0_CLASS_CODE		0x09	//Class Code
    #define D0F0_CLASSCODE_23_0			0xFFFFFF	//060000h/x/x/x Class Code
#define D0F0_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D0F0_RX0C_7_0			0xFF	//0/x/x/x Cache Line Size
#define D0F0_PCI_MASTER_LATENCY_TIMER		0x0D	//PCI Master Latency Timer
    #define D0F0_MLT_7_3			0xF8	//0/x/x/x Maximum Time Slice for CPU as a Master on the PCI Bus
    #define D0F0_MLT_2_0			(BIT0 + BIT1 + BIT2)	//0/R/x/x Bits [2:0] of the Maximum Time Slice for CPU as a Master on the PCI Bus
#define D0F0_HEADER_TYPE		0x0E	//Header Type
    #define D0F0_TBD_EH7			BIT7	//1b/R/x/x Header Type
    #define D0F0_TBD_EH0			0x7F	//0/R/x/x Header Type
#define D0F0_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D0F0_RX0C_31_24			0xFF	//0/R/x/x BIST Support
#define D0F0_BASE_ADR_REGS_0		0x10	//Base Address Registers 0
    #define D0F0_RX10_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 0
#define D0F0_BASE_ADR_REGS_1		0x14	//Base Address Registers 1
    #define D0F0_RX14_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 1
#define D0F0_BASE_ADR_REGS_2		0x18	//Base Address Registers 2
    #define D0F0_RX18_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 2
#define D0F0_BASE_ADR_REGS_3		0x1C	//Base Address Registers 3
    #define D0F0_RX1C_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 3
#define D0F0_BASE_ADR_REGS_4		0x20	//Base Address Registers 4
    #define D0F0_RX20_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 4
#define D0F0_BASE_ADR_REGS_5		0x24	//Base Address Registers 5
    #define D0F0_RX24_31_0			0xFFFFFFFF	//0/R/x/x Base Address Registers 5
#define D0F0_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D0F0_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D0F0_SVID		0x2C	//Subsystem Vendor ID
    #define D0F0_RX2C_15_0			0xFFFF	//0/X/x/x Subsystem Vendor ID
#define D0F0_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D0F0_RX2C_31_16			0xFFFF	//0/x/x/x Subsystem ID
#define D0F0_EXPANSION_ROM_BASE_ADR		0x30	//Expansion ROM Base Address
    #define D0F0_RX30_31_0			0xFFFFFFFF	//0/R/x/x Expansion ROM Base Address
#define D0F0_CAP_POINTER		0x34	//Capability Pointer
    #define D0F0_CAPPTR_7_0			0xFF	//40h/40h/x/x Capability Pointer
#define D0F0_RESERVED		0x35	//Reserved
    #define D0F0_RX35_7_0			0xFF	//0/R/x/x Reserved
#define D0F0_RESERVED_Z1		0x36	//Reserved
    #define D0F0_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D0F0_RESERVED_Z2		0x37	//Reserved
    #define D0F0_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D0F0_INTR_LINE_AND_INTR_PIN		0x3C	//Interrupt Line and Interrupt Pin
    #define D0F0_RX3C_15_8			0xFF00	//0/R/x/x Interrupt Pin
    #define D0F0_RX3C_7_0			0xFF	//0/R/x/x Interrupt Line
#define D0F0_MINIMUM_GRANT_AND_MAXIMUM_LATENCY		0x3E	//Minimum Grant and Maximum Latency
    #define D0F0_RX3C_31_24			0xFF00	//0/R/x/x Maximum Latency
    #define D0F0_RX3C_23_16			0xFF	//0/R/x/x Minimum Grant
#define D0F0_PCI_EXPRESS_LIST		0x40	//PCI Express List
    #define D0F0_RX40_15_8			0xFF00	//88h/88h/x/x Next Pointer
    #define D0F0_RX40_7_0			0xFF	//10h/10h/x/x Capability ID
#define D0F0_PCI_EXPRESS_CAPS		0x42	//PCI Express Capabilities
    #define D0F0_RX42_15_14			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F0_RX42_13_9			0x3E00	//0/0/x/x Interrupt Message Number
    #define D0F0_RX42_8			BIT8	//0/0b/x/x Slot Implemented
    #define D0F0_RX42_7_4			0xF0	//0100b/0100b/x/x Device / Port Type
    #define D0F0_RX42_3_0			0xF	//2h/2h/x/x Capability Version Bit
#define D0F0_DEV_CAPS_1		0x44	//Device Capabilities 1
    #define D0F0_RSV_19			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define D0F0_TBD_27			BIT28	//0/0/x/x Function Level Reset Capability
    #define D0F0_RSV_20			(BIT26 + BIT27)	//0/0/x/x Captured Slot Power Limit Scale
    #define D0F0_RSV_21			0x3FC0000	//0/0/x/x Captured Slot Power Limit Value
    #define D0F0_RSV_22			(BIT16 + BIT17)	//0/R/x/x Reserved
    #define D0F0_RRBERRP			BIT15	//1b/1/x/x Role-based Error Reporting
    #define D0F0_RSV_23			BIT14	//0/0/x/x Power Indicator Present
    #define D0F0_RSV_24			BIT13	//0/0/x/x Attention Indicator Present
    #define D0F0_RSV_25			BIT12	//0/0/x/x Attention Button Present
    #define D0F0_DAL1AL			(BIT9 + BIT10 + BIT11)	//000b/0/x/x Endpoint L1 Acceptable Latency
    #define D0F0_RSV_44			(BIT6 + BIT7 + BIT8)	//0/0/x/x Endpoint L0s Acceptable Latency
    #define D0F0_DAXTAGF			BIT5	//0/0/x/x Extended Tag Field Supported
    #define D0F0_RSV_26			(BIT3 + BIT4)	//0/0/x/x Phantom Functions Supported
    #define D0F0_DAMPSS			(BIT0 + BIT1 + BIT2)	//000b/000b/x/x Max Payload Size Supported
#define D0F0_DEV_CTL_1		0x48	//Device Control 1
    #define D0F0_RSV_27			BIT15	//0/R/x/x Reserved
    #define D0F0_DCMRRS			(BIT12 + BIT13 + BIT14)	//0/0/x/x Max Read Request Size
    #define D0F0_DCENS			BIT11	//0/0/x/x Enable No Snoop
    #define D0F0_DCAPPME			BIT10	//0/0/x/x Auxiliary Power PM Enable
    #define D0F0_DCPFE			BIT9	//0/0/x/x Phantom Functions Enable
    #define D0F0_DCETFE			BIT8	//0/0/x/x Extended Tag Field Enable
    #define D0F0_DCMPS			(BIT5 + BIT6 + BIT7)	//0/0/0/x Max Payload Size
    #define D0F0_DCERO			BIT4	//1b/1/x/x Enable Relaxed Ordering
    #define D0F0_DCURRE			BIT3	//0/0/x/x Unsupported Request Reporting Enable
    #define D0F0_DCFERE			BIT2	//0/0/x/x Fatal Error Reporting Enable
    #define D0F0_DCNFERE			BIT1	//0/0/x/x Non-Fatal Error Reporting Enable
    #define D0F0_DCCERE			BIT0	//0/0/x/x Correctable Error Reporting Enable
#define D0F0_DEV_STA_1		0x4A	//Device Status 1
    #define D0F0_RSV_4B			0xFFC0	//0/R/x/x Reserved
    #define D0F0_DSTP			BIT5	//0/0/x/x Transactions Pending
    #define D0F0_DSAPD			BIT4	//0/0/x/x AUX Power Detected
    #define D0F0_DSURD			BIT3	//0/0/x/x Unsupported Request Detected (TL)
    #define D0F0_DSFED			BIT2	//0/0/x/x Fatal Error Detected (TL)
    #define D0F0_DSNFED			BIT1	//0/0/x/x Non-Fatal Error Detected (TL)
    #define D0F0_DSCED			BIT0	//0/0/x/x Correctable Error Detected (TL)
#define D0F0_LINK_CAPS_1		0x4C	//Link Capabilities 1
    #define D0F0_LKPN			0xFF000000	//0Ah/x/x/x Port Number
    #define D0F0_RSV_31			(BIT22 + BIT23)	//0/R/x/x Reserved
    #define D0F0_RLBWNTFC			BIT21	//0/0b/x/x Link Bandwidth Notification Capability
    #define D0F0_RDL_AR_CAP			BIT20	//0/0b/x/x Data Link Layer Link Active Reporting Capable
    #define D0F0_RLCASDERC			BIT19	//0/0b/x/x Surprise Down Error Reporting Capable
    #define D0F0_RLCACPM			BIT18	//0/0/x/x Clock Power Management
    #define D0F0_LKL1EL			(BIT15 + BIT16 + BIT17)	//011b/x/x/x L1 Exit Latency
    #define D0F0_LKL0SE			(BIT12 + BIT13 + BIT14)	//011b/x/x/x L0s Exit Latency
    #define D0F0_LKAPMS			(BIT10 + BIT11)	//11b/11b/x/x Active State Link PM (ASPM) Support
    #define D0F0_LKMLW_5			BIT9	//0/0/x/x Maximum Link Width Bit 5
    #define D0F0_LKMLW_4			BIT8	//0/0/x/x Maximum Link Width Bit 4
    #define D0F0_LKMLW_3			BIT7	//0/0/x/x Maximum Link Width Bit 3
    #define D0F0_LKMLW_2			BIT6	//1b/1b/x/x Maximum Link Width Bit 2
    #define D0F0_LKMLW_1			BIT5	//0/x/x/x Maximum Link Width Bit 1
    #define D0F0_LKMLW_0			BIT4	//0/x/x/x Maximum Link Width Bit 0
    #define D0F0_LKMAXLS_3			BIT3	//0/0/x/x Max Link Speed Bit 3 
    #define D0F0_LKMAXLS_2			BIT2	//0/0/x/x Max Link Speed Bit 2
    #define D0F0_LKMAXLS_1			BIT1	//0b/0b/x/x Max Link Speed Bit 1
    #define D0F0_LKMAXLS_0			BIT0	//1b/1b/x/x Max Link Speed Bit 0
#define D0F0_LINK_CTL_1		0x50	//Link Control 1
    #define D0F0_RSV_32			0xF000	//0/R/x/x Reserved
    #define D0F0_RLABITEN			BIT11	//0/0/x/x Enable Link Autonomous Bandwidth Interrupt
    #define D0F0_RLBMITEN			BIT10	//0/0/x/x Enable Link Bandwidth Management Interrupt
    #define D0F0_RHATNMWD			BIT9	//0/0/x/0 Hardware Autonomous Width Control
    #define D0F0_RLCOCPMEN			BIT8	//0/0/x/x Enable Clock Power Management
    #define D0F0_LCES			BIT7	//0/0/0/x Extended Synch
    #define D0F0_LCCCC			BIT6	//1b/x/x/x Common Clock Configuration
    #define D0F0_LCRL			BIT5	//0/0/x/x Retrain Link
    #define D0F0_LCLD			BIT4	//0/0/x/x Link Disable
    #define D0F0_LCRCB			BIT3	//0/0/x/x Read Completion Boundary
    #define D0F0_RSV_33			BIT2	//0/R/x/x Reserved
    #define D0F0_LCAPMS			(BIT0 + BIT1)	//00b/00b/00b/00b Link Active State PM (ASPM) Control
#define D0F0_LINK_STA_1		0x52	//Link Status 1
    #define D0F0_RLATNMBW			BIT15	//0/0/x/x Link Autonomous Bandwidth Status
    #define D0F0_RLBWMNGT			BIT14	//0/0/x/x Link Bandwidth Management Status
    #define D0F0_DL_ACTIVE			BIT13	//0/x/x/x Data Link Layer Link Active
    #define D0F0_LSSCC			BIT12	//1b/x/x/x Slot Clock Configuration
    #define D0F0_LSLT			BIT11	//0/0/x/x Link Training
    #define D0F0_LSTE			BIT10	//0/0/x/x Training Error
    #define D0F0_TBD_28			BIT9	//0/0/x/x Negotiated Link Width Bit 5
    #define D0F0_LSNLW			0x1F0	//0/0/x/x Negotiated Link Width Bits[4:0]
    #define D0F0_LSLS			0xF	//0/0/x/x Current Link Speed
#define D0F0_SLOT_CAPS_1		0x54	//Slot Capabilities 1
    #define D0F0_SLPSN			0xFFF80000	//0/0/x/x Physical Slot Number; Reserved
    #define D0F0_RSCANCCS			BIT18	//0/0/x/x No Command Completed Support
    #define D0F0_RSCAEMIP			BIT17	//0/0/x/x Electromechanical Interlock Present
    #define D0F0_RSPLS			(BIT15 + BIT16)	//00b/0/x/x Slot Power Limit Scale
    #define D0F0_RSPLV			0x7F80	//0/0/x/x Slot Power Limit Value
    #define D0F0_SCHP_CAP			BIT6	//0/0/x/x Hot-Plug Capable
    #define D0F0_SCHPS			BIT5	//1b/1/x/x Hot-Plug Surprise
    #define D0F0_SCPIP			BIT4	//0/0/x/x Power Indicator Present
    #define D0F0_SCAIP			BIT3	//0/0/x/x Attention Indicator Present
    #define D0F0_RSV_36			BIT2	//0/0/x/x MRL Sensor Present
    #define D0F0_RSV_37			BIT1	//0/0/x/x Power Controller Present
    #define D0F0_SCABP			BIT0	//0/0/x/x Attention Button Present
#define D0F0_SLOT_CTL_1		0x58	//Slot Control 1
    #define D0F0_RSV_39			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define D0F0_RDLSCHGEN			BIT12	//0/0/x/x Enable Data Link Layer State Change
    #define D0F0_RSCOEMIC			BIT11	//0/0/x/x Electromechanical Interlock Control
    #define D0F0_SCPCC			BIT10	//0/0/x/x Power Controller Control
    #define D0F0_SCPIC			(BIT8 + BIT9)	//00b/0/x/x Power Indicator Control
    #define D0F0_SCAIC			(BIT6 + BIT7)	//00b/0/x/x Attention Indicator Control
    #define D0F0_SCHPIE			BIT5	//0/0/x/x Enable Hot-Plug Interrupt
    #define D0F0_SCCCIE			BIT4	//0/0/x/x Enable Command Completed Interrupt 
    #define D0F0_SCPDCE			BIT3	//0/0/x/x Enable Presence Detect Change
    #define D0F0_RSV_40			BIT2	//0/0/x/x Enable MRL Sensor Change
    #define D0F0_RSV_41			BIT1	//0/0/x/x Enable Power Fault Detected
    #define D0F0_SCABPE			BIT0	//0/0/x/x Enable Attention Button Pressed
#define D0F0_SLOT_STA_1		0x5A	//Slot Status 1
    #define D0F0_RSV_42			0xFE00	//0/R/x/x Reserved
    #define D0F0_RDLSCHG			BIT8	//0/0/x/x Data Link Layer State Changed
    #define D0F0_RSSEMIS			BIT7	//0/0/x/x Electromechanical Interlock Status
    #define D0F0_SPDCST			BIT6	//0/0/x/x Presence Detect State
    #define D0F0_RSV_43			BIT5	//0/0/x/x MRL (Manually Operated Retention Latch) Sensor State
    #define D0F0_SSCC			BIT4	//0/0/x/x Command Completed
    #define D0F0_SPDC			BIT3	//0/0/x/x Presence Detect Change
    #define D0F0_TBD_29			BIT2	//0/0/x/x MRL Sensor Change
    #define D0F0_TBD_30			BIT1	//0/0/x/x Power Fault Detected
    #define D0F0_SSABP			BIT0	//0/0/x/x Attention Button Pressed
#define D0F0_ROOT_CTL		0x5C	//Root Control
    #define D0F0_RSV_5C_5			0xFFE0	//0/R/x/x Reserved
    #define D0F0_RCCRSSVE			BIT4	//0/0/x/x Enable CRS Software Visibility 
    #define D0F0_RCPMEIE			BIT3	//0/0/x/x Enable PME Interrupt
    #define D0F0_RCSEFEE			BIT2	//0/0/x/x Enable System Error on Fatal Error
    #define D0F0_RCSENFEE			BIT1	//0/0/x/x Enable System Error on Non-Fatal Error
    #define D0F0_RCSECEE			BIT0	//0/0/x/x Enable System Error on Correctable Error
#define D0F0_ROOT_CAPS		0x5E	//Root Capabilities
    #define D0F0_RSV_44_5E			0xFFFE	//0/R/x/x Reserved
    #define D0F0_RSCRSSFV			BIT0	//0/0/x/x Configuration Request Retry Status (CRS) Software Visibility
#define D0F0_ROOT_STA		0x60	//Root Status
    #define D0F0_RSV_45			0xFFFC0000	//0/R/x/x Reserved
    #define D0F0_RSPP			BIT17	//0/0/x/x PME Pending
    #define D0F0_RSPS			BIT16	//0/0/x/x PME Status
    #define D0F0_RSPRID			0xFFFF	//0/0/x/x PME Requester ID
#define D0F0_DEV_CAPS_2		0x64	//Device Capabilities 2
    #define D0F0_RSV_64_6			0xFFF00000	//0/R/x/x Reserved
    #define D0F0_ROBFFSP			(BIT18 + BIT19)	//0/0/x/x OBFF Supported
    #define D0F0_RSV_64_12			0x3F000	//0/R/x/x Reserved
    #define D0F0_RLTRSP			BIT11	//0/0/x/x LTR Mechanism Supported
    #define D0F0_RSV_64_10			0x7C0	//0/x/x/x Reserved
    #define D0F0_RARISP			BIT5	//0/0/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define D0F0_TBD_31			BIT4	//1b/1/x/x Completion Timeout Disable Supported
    #define D0F0_TBD_32			0xF	//0/0/x/x Completion Timeout Ranges Supported
#define D0F0_DEV_CTL_2		0x68	//Device Control 2
    #define D0F0_RSV_46			BIT15	//0/R/x/x Reserved
    #define D0F0_ROBFFEN			(BIT13 + BIT14)	//0/0/x/x OBFF Enable
    #define D0F0_RSV_68_11			(BIT11 + BIT12)	//0/R/x/x Reserved
    #define D0F0_RLTREN			BIT10	//0/0/x/x LTR Mechanism Enable
    #define D0F0_RSV_68_6			0x3C0	//0/R/x/x Reserved
    #define D0F0_RARIEN			BIT5	//0/0/x/x Enable ARI Forwarding
    #define D0F0_RDISCPLTM			BIT4	//0/0/0/x Completion Timeout Disable Control
    #define D0F0_TBD_33			0xF	//0/0/x/x Completion Timeout Value
#define D0F0_DEV_STA_2		0x6A	//Device Status 2
    #define D0F0_RSV_47			0xFFFF	//0/R/x/x Reserved
#define D0F0_LINK_CAPS_2		0x6C	//Link Capabilities 2
    #define D0F0_RSV_6C_31			0xFFF80000	//0/R/x/x Reserved
    #define D0F0_RLOW_SKP_REC_SUPPORT_2			BIT18	//0/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F0_RLOW_SKP_REC_SUPPORT_1			BIT17	//0/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F0_RLOW_SKP_REC_SUPPORT_0			BIT16	//1b/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F0_RSV_6C_15			0xF000	//0/R/x/x Reserved
    #define D0F0_RLOW_SKP_GEN_SUPPORT_2			BIT11	//0/x/x/x Lower SKP OS Generation Supported Speeds Vector
    #define D0F0_RLOW_SKP_GEN_SUPPORT_1			BIT10	//0/x/x/X Lower SKP OS Generation Supported Speeds Vector
    #define D0F0_RLOW_SKP_GEN_SUPPORT_0			BIT9	//1b/x/x/X Lower SKP OS Generation Supported Speeds Vector
    #define D0F0_RSV_6C_8			BIT8	//0/0/x/x CrossLink Supported
    #define D0F0_LKMLS_6			BIT7	//0/0/x/x Supported Link Speed Vector Bit 6
    #define D0F0_LKMLS_5			BIT6	//0/0/x/x Supported Link Speed Vector Bit 5
    #define D0F0_LKMLS_4			BIT5	//0/0/x/x Supported Link Speed Vector Bit 4
    #define D0F0_LKMLS_3			BIT4	//0/0/x/x Supported Link Speed Vector Bit 3
    #define D0F0_LKMLS_2			BIT3	//0/0/x/x Supported Link Speed Vector Bit 2, 8.0GT/s
    #define D0F0_LKMLS_1			BIT2	//0/0b/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define D0F0_LKMLS_0			BIT1	//1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s
    #define D0F0_RSV_6C_0			BIT0	//0/R/x/x Reserved
#define D0F0_LINK_CTL_2		0x70	//Link Control 2
    #define D0F0_CMPPSDEEMPHS			0xF000	//0/0/x/x Compliance Preset / De-emphasis
    #define D0F0_RCMPSOS			BIT11	//0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define D0F0_PMDCMPSET			BIT10	//0/0/x/x Modified Compliance Pattern Set Bit
    #define D0F0_TXMGN_2			BIT9	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F0_TXMGN_1			BIT8	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F0_TXMGN_0			BIT7	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F0_SELDEEMPHS			BIT6	//0/0/x/x Selectable De-emphasis
    #define D0F0_RHATNMSD			BIT5	//0/0/x/0 Disable Hardware Autonomous Speed
    #define D0F0_PCMPSET			BIT4	//0/0/x/x Enter Compliance
    #define D0F0_LKTGLS_3			BIT3	//0/0/0/0 Target Link Speed Bit 3
    #define D0F0_LKTGLS_2			BIT2	//0/0/0/0 Target Link Speed Bit 2
    #define D0F0_LKTGLS_1			BIT1	//0/0/0/0 Target Link Speed Bit 1
    #define D0F0_LKTGLS_0			BIT0	//0/0/0/0 Target Link Speed Bit 0
#define D0F0_LINK_STA_2		0x72	//Link Status 2
    #define D0F0_RSV_49			0xFFC0	//0/R/x/x Reserved
    #define D0F0_EQREQ			BIT5	//0/x/x/x Request the Link Equalization Process
    #define D0F0_EQCOMPLE3			BIT4	//0/x/x/x Transmitter Equalization Procedure Completed -Phase 3
    #define D0F0_EQCOMPLE2			BIT3	//0/x/x/x Transmitter Equalization Procedure Completed -Phase 2
    #define D0F0_EQCOMPLE1			BIT2	//0/x/x/x Transmitter Equalization Procedure Completed -Phase 1
    #define D0F0_EQCOMPLE			BIT1	//0/x/x/x Transmitter Equalization Procedure Completed
    #define D0F0_CURDEEMPHS			BIT0	//0/x/x/x Current Link De-emphasis Level
#define D0F0_RESERVED_INTERNAL_RW		0x80	//Reserved ((Internal-RW))
    #define D0F0_RSV_80H			0xFFFF	//0/0/x/x Reserved
#define D0F0_CPU_CORE_NUM_ROMSIP_CTL_FOR_DEBUG		0x82	//CPU Core Number ROMSIP Control for Debug
    #define D0F0_MODE333			BIT7	//0/x/x/x Downstream IOWEND CDC Register Out
    #define D0F0_RLTPIPE			BIT6	//0/x/x/x Downstream Requests Pipe in the Interface with CPUIF
    #define D0F0_RCFGA_SEL			BIT5	//0/x/x/x CFGA select bypass CDC
    #define D0F0_RSV_ROMSIP_82_4			BIT4	//0/x/x/x Reserved
    #define D0F0_ROMSIP_CPU_CORE_NUM_3_0			0xF	//0/x/x/x CPU Core Number Setting (For debug only)
#define D0F0_MULT_FUN_CTL		0x83	//Multiple Function Control
    #define D0F0_RVPI_FUSE			BIT7	//HwInit/x/x/x VPI Function Enable/Disable for Dual Socket
    #define D0F0_RSME_FUSE			BIT6	//HwInit/x/x/x SME Function Enable/Disable for TXT Usage
    #define D0F0_RFSBC_FUSE			BIT5	//HwInit/x/x/x FSBC Function Enable/Disable for TXT Usage
    #define D0F0_RECC_FUSE			BIT4	//HwInit/x/x/x ECC Function Enable/Disable
    #define D0F0_D0F0_RX83B3			BIT3	//0/x/x/x RCLASS_CODE_LOCK_D0F0
    #define D0F0_D0F0_RX83B2			BIT2	//0/x/x/x RVID_DID_LOCK_D0F0
    #define D0F0_D0F0_RX83B1			BIT1	//0/x/x/x RDID_RID_LOCK_D0F0
    #define D0F0_MFUNC			BIT0	//1b/1/1/1 Multi-Function Support
#define D0F0_DEBUG_SIGNAL_PATTERN_SET		0x84	//Debug Signal Pattern Set
    #define D0F0_RDBGPATTERN_31_0			0xFFFFFFFF	//55555555h/x/x/x Debug Signal Pattern
#define D0F0_PM_CAPS		0x88	//Power Management Capabilities
    #define D0F0_PMCPME			0xF8000000	//11001b/19h/x/x PME Support
    #define D0F0_PMCD2S			BIT26	//0/0/x/x D2 Support
    #define D0F0_PMCD1S			BIT25	//0/0/x/x D1 Support
    #define D0F0_PMCAUXC			(BIT22 + BIT23 + BIT24)	//0/0/x/x AUX Current
    #define D0F0_PMCDSI			BIT21	//1b/1/x/x Device Specific Initialization
    #define D0F0_RSV_53			(BIT19 + BIT20)	//0/R/x/x Reserved
    #define D0F0_TBD_34			(BIT16 + BIT17 + BIT18)	//010b/010b/x/x Version
    #define D0F0_TBD_35			0xFF00	//00h/00h/x/x Next Capability Pointer
    #define D0F0_TBD_36			0xFF	//01h/01h/x/x Capability ID
#define D0F0_PM_STA_CTL		0x8C	//Power Management Status / Control
    #define D0F0_TBD_37			0xFF000000	//0/R/x/x Power Management Data
    #define D0F0_TBD_38			BIT23	//0/x/x/x Enable Bus Power / Clock Control
    #define D0F0_TBD_39			BIT22	//0/x/x/x B2 / B3 Support
    #define D0F0_RSV_54			0x3F0000	//0/R/x/x Reserved
    #define D0F0_PMESD			BIT15	//0/0/x/x PME Status
    #define D0F0_TBD_40			(BIT13 + BIT14)	//0/0/x/x Data Scale
    #define D0F0_TBD_41			0x1E00	//0/0/x/x Data Select
    #define D0F0_PMEEN			BIT8	//0/0/x/x PME Enable
    #define D0F0_RSV_55			0xFC	//0/R/x/x Reserved
    #define D0F0_PWSD			(BIT0 + BIT1)	//00b/0/x/x Power State
#define D0F0_SHADOW_REG_FOR_D15F0_SATA_RX13_RX10		0x90	//Shadow Register for D15F0 (SATA) Rx13~Rx10
    #define D0F0_RX90_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_D15F0_W1FXA_15_4			0xFFF0	//01Fh/x/x/x Shadow Register for an 8-byte I/O Address Space of D15F0; IO Port Address [15:4]((Random))
    #define D0F0_D15F0_W1FXA_3			BIT3	//0/x/x/x Shadow Register for an 8-byte I/O Address Space of D15F0; IO Port Address [3]
    #define D0F0_D15F0_W1FXA_2_0			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Shadow Register for an 8-byte I/O Address Space of D15F0; IO Port Address [2:0]
#define D0F0_SHADOW_REG_FOR_D15F0_SATA_RX17_RX14		0x94	//Shadow Register for D15F0 (SATA) Rx17~Rx14
    #define D0F0_RX94_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_D15F0_W3FXA_15_4			0xFFF0	//03Fh/x/x/x Shadow Register for a 4-byte I/O Address Space of D15F0; IO Port Address [15:4]((Random))
    #define D0F0_D15F0_W3FXA_3_2			(BIT2 + BIT3)	//01b/x/x/x Shadow Register for a 4-byte I/O Address Space of D15F0; IO Port Address [3:2]
    #define D0F0_D15F0_W3FXA_1_0			(BIT0 + BIT1)	//01b/x/x/x Shadow Register for a 4-byte I/O Address Space of D15F0; IO Port Address [1:0]
#define D0F0_SHADOW_REG_FOR_D15F0_SATA_RX1B_RX18		0x98	//Shadow Register for D15F0 (SATA) Rx1B~Rx18
    #define D0F0_D15F0_W1FXB_31_16			0xFFFF0000	//0000h/x/x/x Shadow Register for MSIX_TBASE Space of D15F0; MEM Address [31:16]((Random)) 
    #define D0F0_D15F0_W1FXB_15_4			0xFFF0	//017h/x/x/x Shadow Register for an 8-byte I/O Address Space of D15F0; IO Port Address [15:4]((Random))
    #define D0F0_D15F0_W1FXB_3			BIT3	//0/x/x/x Shadow Register for an 8-byte I/O Address Space of D15F0; IO Port Address [3]
    #define D0F0_D15F0_W1FXB_2_0			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Shadow Register for an 8-byte I/O Address Space of D15F0; IO Port Address [2:0]
#define D0F0_SHADOW_REG_FOR_D15F0_SATA_RX1F_RX1C		0x9C	//Shadow Register for D15F0 (SATA) Rx1F~Rx1C
    #define D0F0_D15F0_W3FXB_31_16			0xFFFF0000	//0000h/x/x/x Shadow Register for MSIX_PBASE Address Space of D15F0; MEM Address [31:16]((Random))
    #define D0F0_D15F0_W3FXB_15_4			0xFFF0	//037h/x/x/x Shadow Register for a 4-byte I/O Address Space of D15F0; IO Port Address [15:4]((Random))
    #define D0F0_D15F0_W3FXB_3_2			(BIT2 + BIT3)	//01b/x/x/x Shadow Register for a 4-byte I/O Address Space of D15F0; IO Port Address [3:2]
    #define D0F0_D15F0_W3FXB_1_0			(BIT0 + BIT1)	//01b/x/x/x Shadow Register for a 4-byte I/O Address Space of D15F0; IO Port Address [1:0]
#define D0F0_SHADOW_REG_FOR_D15F0_SATA_RX23_RX20		0xA0	//Shadow Register for D15F0 (SATA) Rx23~Rx20
    #define D0F0_RXA0_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_D15F0_WCTL_15_4			0xFFF0	//CC0h/x/x/x Shadow Register for a 16-byte I/O Address Space of D15F0; IO Port Address [15:4]((Random))
    #define D0F0_D15F0_WCTL_3_0			0xF	//0001b/x/x/x Shadow Register for a 16-byte I/O Address Space of D15F0; IO Port Address [3:0]
#define D0F0_SHADOW_REG_FOR_D15F0_SATA_RX27_RX24		0xA4	//Shadow Register for D15F0 (SATA) Rx27~Rx24
    #define D0F0_D15F0_AHCIBASE_31_10			0xFFFFFC00	//0/x/x/x Shadow Register for Base Address of Register Memory Space of D15F0
    #define D0F0_RXA4_9_4			0x3F0	//0/x/x/x Reserved
    #define D0F0_RXA4_3			BIT3	//0/x/x/x Shadow Register for D15F0 Rx24[3]
    #define D0F0_RXA4_2_1			(BIT1 + BIT2)	//0/x/x/x Shadow Register for D15F0 Rx24[2:1]
    #define D0F0_RXA4_0			BIT0	//0/x/x/x Shadow Register for D15F0 Rx24[0]
#define D0F0_PCIE_INTR_ROUTING_SEL_0		0xAC	//PCIe Interrupt Routing Selection 0
    #define D0F0_RMSGCINTRT_PE0_1_0			(BIT6 + BIT7)	//11b/11b/x/x PCIe Port 0 Interrupt Routing 0
    #define D0F0_RMSGCINTRT_PE1_1_0			(BIT4 + BIT5)	//11b/11b/x/x PCIe Port 1 Interrupt Routing 0
    #define D0F0_RMSGCINTRT_PE2_1_0			(BIT2 + BIT3)	//11b/11b/x/x PCIe Port 2 Interrupt Routing 0
    #define D0F0_RMSGCINTRT_PE3_1_0			(BIT0 + BIT1)	//11b/11b/x/x PCIe Port 3 Interrupt Routing 0
#define D0F0_PCIE_INTR_ROUTING_SEL_1		0xAD	//PCIe Interrupt Routing Selection 1
    #define D0F0_RINTRT_PE0_1_0			(BIT6 + BIT7)	//00b/00b/x/x PCIe Port 0 Interrupt Routing 1
    #define D0F0_RINTRT_PE1_1_0			(BIT4 + BIT5)	//00b/00b/x/x PCIe Port 1 Interrupt Routing 1
    #define D0F0_RINTRT_PE2_1_0			(BIT2 + BIT3)	//00b/00b/x/x PCIe Port 2 Interrupt Routing 1
    #define D0F0_RINTRT_PE3_1_0			(BIT0 + BIT1)	//00b/00b/x/x PCIe Port 3 Interrupt Routing 1
#define D0F0_PCIE_INTR_ROUTING_SEL_2		0xAE	//PCIe Interrupt Routing Selection 2
    #define D0F0_RMSGCINTRT_PEG0_1_0			(BIT6 + BIT7)	//11b/11b/x/x PCIe Port G0 Interrupt Routing 0
    #define D0F0_RMSGCINTRT_PEG1_1_0			(BIT4 + BIT5)	//11b/11b/x/x PCIe Port G1 Interrupt Routing 0
    #define D0F0_RINTRT_PEG0_1_0			(BIT2 + BIT3)	//00b/00b/x/x PCIe Port G0 Interrupt Routing 1
    #define D0F0_RINTRT_PEG1_1_0			(BIT0 + BIT1)	//00b/00b/x/x PCIe Port G1 Interrupt Routing 1
#define D0F0_USINTA_USINTB_ROUTING_SEL		0xAF	//USINTA & USINTB Routing Selection
    #define D0F0_RXAF_7_4			0xF0	//0/x/x/x Reserved
    #define D0F0_RGFXINTAIRQ			BIT3	//0/0/x/x GFX Interrupt Routing to APICX Controlling
    #define D0F0_RGFXINTBIRQ			BIT2	//0/0/x/x GFX Interrupt Routing to APICX Controlling
    #define D0F0_RGFXINTRT_1_0			(BIT0 + BIT1)	//00b/0/x/x Route GFX Interrupts to SM Controller
#define D0F0_XHCI_SHADOW_REGS_1_D18F0_RX13_RX10		0xB0	//xHCI Shadow Registers 1 D18F0 Rx13~Rx10
    #define D0F0_RMXHBS_31_12			0xFFFFF000	//00000h/R/x/x xHCI Base Address
    #define D0F0_RSV_B0H			0xFFF	//0/R/x/x Reserved
#define D0F0_XHCI_SHADOW_REGS_2_D18F0_RX17_RX14		0xB4	//xHCI Shadow Registers 2 D18F0 Rx17~Rx14
    #define D0F0_RMXHBS_63_32			0xFFFFFFFF	//00000000h/R/x/x xHCI Base Address
#define D0F0_GRAPHICS_MEM_AND_IO_SPACE_ACCESS_CTL_SHADOW_D1F0_RX04		0xC0	//Graphics Memory and IO Space Access Control Shadow D1F0 Rx04
    #define D0F0_RSV_C0H			0xFC	//0/R/x/x Reserved
    #define D0F0_RENMEM2			BIT1	//0/R/x/x Shadow Register for Memory Space Access of D1F0
    #define D0F0_RENIO2			BIT0	//0/R/x/x Shadow Register for I/O Space Access of D1F0
#define D0F0_RESERVED_INTERNAL_RW_Z1		0xC1	//Reserved ((Internal-RW))
    #define D0F0_RSV_C1H			0xFFFFFF	//0/0/x/x Reserved
#define D0F0_GFX_CTL		0xC4	//GFX Control
    #define D0F0_RSV_C4H			0xFFF0	//0/0/x/x Reserved
    #define D0F0_RGFX_LOCK			BIT3	//0/0/x/x RGFX_LOCK
    #define D0F0_RADDR_MAP_LOCK			BIT2	//0/0/x/x RADDR_MAP_LOCK
    #define D0F0_RGFXNSEN			BIT1	//1b/1b/x/x GFX Non Snoop Path Enable
    #define D0F0_RGFXNSENLOCK			BIT0	//0/0/x/x The Lock Bit for RGFXNSEN
#define D0F0_LEGACY_SPACE_ACCESS_CTL		0xC6	//Legacy Space Access Control
    #define D0F0_RSV_C6H2			0xFC	//0/0/x/x Reserved
    #define D0F0_RMDA			BIT1	//0/0/x/x MDA Resource Location
    #define D0F0_D0F0_RSV_C6H0			BIT0	//0/0/x/x Reserved
#define D0F0_RESERVED_INTERNAL_RW_Z2		0xC7	//Reserved ((Internal-RW))
    #define D0F0_RSV_C7H			0xFF	//0/0/x/x Reserved
#define D0F0_GFX_SHADOW_MEM_BASE_0_AND_MMIO_D1F0_RX13_RX10		0xC8	//GFX Shadow Memory Base 0 and MMIO D1F0 Rx13~Rx10
    #define D0F0_RM0BS_31_0			0xFFFFFFFF	//FFF00000h/R/x/x GFX¡¯s Memory Base 0 Address [31:0] for MMIO
#define D0F0_GFX_ROM_BASE_ADR		0xCC	//GFX ROM Base Address
    #define D0F0_RM1BS_31_0			0xFFFFFFFF	//0/R/x/x Reserved
#define D0F0_GFX_SHADOW_MEM_BASE_1_S_L_AND_LOW_ADR_D1F0_RX17_RX14		0xD8	//GFX Shadow Memory Base 1 - S.L. and Low Address D1F0 Rx17~Rx14
    #define D0F0_RM2BS_31_0			0xFFFFFFFF	//FFF00000h/R/x/x GFX¡¯s Memory Base 1 Address [31:0] for S.L.
#define D0F0_GFX_SHADOW_MEM_BASE_1_S_L_AND_HIGH_ADR_D1F0_RX1B_RX18		0xDC	//GFX Shadow Memory Base 1 - S.L. and High Address D1F0 Rx1B~Rx18
    #define D0F0_RM2BS_63_32			0xFFFFFFFF	//00000000h/R/x/x GFX¡¯s Memory Base 1 Address [63:32] for S.L.
#define D0F0_SHADOW_REGS_FOR_D1F0_GFX_PM_STA_RXE0		0xE0	//Shadow Registers for D1F0 GFX Power Management Status RxE0
    #define D0F0_RSV_E0H			0xFC	//0/R/x/x Reserved
    #define D0F0_RGFXPS_1_0			(BIT0 + BIT1)	//00b/R/x/x Device Power State
#define D0F0_RESERVED_INTERNAL_RW_Z3		0xE1	//Reserved ((Internal-RW))
    #define D0F0_RSV_E1H			0xFFFFFF	//0/0/x/x Reserved
#define D0F0_SHADOW_REGS_FOR_D1F1_HDAC_LOWER_BASE_ADR_RX13_RX10		0xE4	//Shadow Registers for D1F1 HDAC Lower Base Address Rx13~Rx10
    #define D0F0_RM0BS_HDMI_31_0			0xFFFFFFFF	//FFF00000h/R/x/x Memory Base 0 Address[31:0] for HDAC
#define D0F0_SHADOW_REGS_FOR_D1F1_HDMI_PM_STA_RXE0		0xE8	//Shadow Registers for D1F1 HDMI Power Management Status RxE0
    #define D0F0_RSV_E8H			0xFC	//0/R/x/x Reserved
    #define D0F0_RHDMIPS_1_0			(BIT0 + BIT1)	//00b/R/x/x Device Power State
#define D0F0_RESERVED_INTERNAL_RW_Z4		0xE9	//Reserved ((Internal-RW))
    #define D0F0_RSV_E9H			0xFFFFFF	//0/0/x/x Reserved
#define D0F0_SHADOW_REGS_FOR_D1F1_HD_AUDIO_HDMI_RX04		0xEC	//Shadow Registers for D1F1 HD Audio (HDMI) Rx04
    #define D0F0_RSV_ECH			0xFC	//0/R/x/x Reserved
    #define D0F0_RENMEM3			BIT1	//0/R/x/x Memory Space Access
    #define D0F0_RENIO3			BIT0	//0/R/x/x I/O Space Access
#define D0F0_RESERVED_INTERNAL_RW_Z5		0xED	//Reserved ((Internal-RW))
    #define D0F0_RSV_EDH			0xFFFFFF	//0/0/x/x Reserved
#define D0F0_X14_EPHY_CTL		0xF0	//X14 EPHY Control
    #define D0F0_FHP0_MPLL_FLAGCK_EN_X14			BIT7	//0/0/x/x Enable MPLL Flag Function when in Debug Mode
    #define D0F0_FHP0_MPLL_LOCK_EN_X14			BIT6	//0/0/x/x Overwrite MPLL Lock Flag Setting
    #define D0F0_FHP0_CTSCLKSEL_X14			BIT5	//0/0/x/x Selecte CTSCLK Source. 
    #define D0F0_FHP0_REFCLK_SEL_X14			BIT4	//0/0/x/x Manual Setting for Selecting Internal or External Clock
    #define D0F0_FHP0_BG_TRIM_X14_2_0			(BIT1 + BIT2 + BIT3)	//100b/100b/x/x Fine Tune Bandgap Setting
    #define D0F0_FHP0_EPHYMSTEN_X14			BIT0	//0/0/x/x Force to Turn on All Functions in Master Block when EPHY0s Testing
#define D0F0_X14_EPHY_CTL_Z1		0xF1	//X14 EPHY Control
    #define D0F0_FHP0_MPLL_FSEL_X14_2_0			(BIT5 + BIT6 + BIT7)	//0/0/x/x MPLL VCO Frequency Tuning
    #define D0F0_FHP0_MPLL_OP_X14			BIT4	//0/0/x/x MPLL Operation Mode for Debugging
    #define D0F0_FHP0_MPLL_CP_X14_3_0			0xF	//0011b/0011b/x/x MPLL CP Current Setting
#define D0F0_X2_EPHY_CTL		0xF2	//X2 EPHY Control
    #define D0F0_FHP0_MPLL_FLAGCK_EN_X2			BIT7	//0/0/x/x Enable MPLL Flag Function when in Debug Mode
    #define D0F0_FHP0_MPLL_LOCK_EN_X2			BIT6	//0/0/x/x Overwrite MPLL Lock Flag Setting
    #define D0F0_FHP0_CTSCLKSEL_X2			BIT5	//0/0/x/x Selecte CTSCLK Source
    #define D0F0_FHP0_REFCLK_SEL_X2			BIT4	//0/0/x/x Manual Setting for Selecting Internal or External Clock
    #define D0F0_FHP0_BG_TRIM_X2_2_0			(BIT1 + BIT2 + BIT3)	//100b/100b/x/x Fine Tune Bandgap Setting
    #define D0F0_FHP0_EPHYMSTEN_X2			BIT0	//0/0/x/x Force to Turn on All Functions in Master Block when EPHY0s Testing
#define D0F0_X2_EPHY_CTL_Z1		0xF3	//X2 EPHY Control
    #define D0F0_FHP0_MPLL_FSEL_X2_2_0			(BIT5 + BIT6 + BIT7)	//0/0/x/x MPLL VCO Frequency Tuning
    #define D0F0_FHP0_MPLL_OP_X2			BIT4	//0/0/x/x MPLL Operation Mode for Debugging
    #define D0F0_FHP0_MPLL_CP_X2_3_0			0xF	//0011b/0011b/x/x MPLL CP Current Setting
#define D0F0_EPHY_CTL		0xF4	//EPHY Control
    #define D0F0_FHP0_REFCLKPS_SEL_X2			BIT15	//0/x/x/x Manual Setting for Selecting Internal Reference clock source for X2 EPHY
    #define D0F0_FHP0_IPTATUNE_X2_2_0			(BIT12 + BIT13 + BIT14)	//0/0/x/x Internal Current Source Value Tuning
    #define D0F0_FHP0_MPLLPD_X2			BIT11	//0/0/x/x MPLL PD for X2 EPHY
    #define D0F0_FHP0_IPTUNE_X2_2_0			(BIT8 + BIT9 + BIT10)	//0/0/x/x Internal Current Source Value Tuning
    #define D0F0_FHP0_REFCLKPS_SEL_X14			BIT7	//0/x/x/x Manual Setting for Selecting Internal Reference Clock Source for X14 EPHY
    #define D0F0_FHP0_IPTATUNE_X14_2_0			(BIT4 + BIT5 + BIT6)	//0/0/x/x Internal Current Source Value Tuning
    #define D0F0_FHP0_MPLLPD_X14			BIT3	//0/0/x/x MPLL PD for X14 EPHY
    #define D0F0_FHP0_IPTUNE_X14_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x Internal Current Source Value Tuning
#define D0F0_EPHY_CTL_Z1		0xF6	//EPHY Control
    #define D0F0_PCIESATAEPHY_CFGDONE			BIT15	//0/x/x/x PCIE EPHY Configuration Done
    #define D0F0_U3EPHY_CFGDONE			BIT14	//0/x/x/x USB3 EPHYConfiguartion Done
    #define D0F0_RDISPEXC_X14			BIT13	//0/0/x/x Disable PCIe_EPHY_X14
    #define D0F0_RDISPEXC_X2			BIT12	//0/0/x/x Disable PCIe_EPHY_X2
    #define D0F0_RSTRAPRW			BIT11	//0/0/x/x Reserved
    #define D0F0_RWAKEEN			BIT10	//0/x/x/x PCI Express Wake (by PME or Hotplug) Activation Control
    #define D0F0_RFIXPCIEHOTPLUG			BIT9	//0/0/x/x Reserved
    #define D0F0_RDISPEXC			BIT8	//0/0/x/x Disable PCIe_EPHY
    #define D0F0_FHP0_MPLL_DELAY_X2_3_0			0xF0	//0001b/0001b/x/x MPLL Feedback Divider Delay Setting
    #define D0F0_FHP0_MPLL_DELAY_X14_3_0			0xF	//0001b/0001b/x/x MPLL Feedback Divider Delay Setting
#define D0F0_PCIE_ROMSIP_REGS		0xF8	//PCIe ROMSIP Registers
    #define D0F0_LTSSM_SW_RESET_EN_PE0			BIT23	//0/x/x/x PCIe Port 0 LTSSM Control
    #define D0F0_LTSSM_SW_RESET_EN_PE1			BIT22	//0/x/x/x PCIe Port 1 LTSSM Control
    #define D0F0_LTSSM_SW_RESET_EN_PE2			BIT21	//0/x/x/x PCIe Port 2 LTSSM Control
    #define D0F0_LTSSM_SW_RESET_EN_PE3			BIT20	//0/x/x/x PCIe Port 3 LTSSM Control
    #define D0F0_LTSSM_SW_RESET_EN_PEG0			BIT19	//0/x/x/x PCIe Port G0 LTSSM Control
    #define D0F0_LTSSM_SW_RESET_EN_PEG1			BIT18	//0/x/x/x PCIe Port G1 LTSSM Control
    #define D0F0_PE0_REVISION_1_0			(BIT16 + BIT17)	//0/x/x/x PCIe Revision Selection (GEN1 GEN2 or GEN3) for Port 0
    #define D0F0_PE1_REVISION_1_0			(BIT14 + BIT15)	//0/x/x/x PCIe Revision Selection (GEN1 GEN2 or GEN3) for Port 1
    #define D0F0_PE2_REVISION_1_0			(BIT12 + BIT13)	//0/x/x/x PCIe Revision Selection (GEN1 GEN2 or GEN3) for Port 2
    #define D0F0_PE3_REVISION_1_0			(BIT10 + BIT11)	//0/x/x/x PCIe Revision Selection(GEN1 GEN2 or GEN3) for Port 3
    #define D0F0_PEG0_REVISION_1_0			(BIT8 + BIT9)	//0/x/x/x PCIe Revision Selection (GEN1 GEN2 or GEN3) for Port G0
    #define D0F0_PEG1_REVISION_1_0			(BIT6 + BIT7)	//0/x/x/x PCIe Revision Selection (GEN1 GEN2 or GEN3) for Port G1
    #define D0F0_PEG2_REVISION_1_0			(BIT4 + BIT5)	//0/x/x/x PCIe Revision Selection (GEN1 GEN2 or GEN3) for Port G2
    #define D0F0_PEG3_REVISION_1_0			(BIT2 + BIT3)	//0/x/x/x PCIe Revision Selection (GEN1 GEN2 or GEN3) for Port G3
    #define D0F0_RSV_F8_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D0F0_PCIE_ROMSIP_REGS_Z1		0xFB	//PCIe ROMSIP Registers
    #define D0F0_LTSSM_SW_RESET_EN_PEG2			BIT7	//0/x/x/x PCIe Port G2 LTSSM Control
    #define D0F0_LTSSM_SW_RESET_EN_PEG3			BIT6	//0/x/x/x PCIe Port G3 LTSSM Control
    #define D0F0_RSV_FB			(BIT4 + BIT5)	//0/0/x/x Reserved
    #define D0F0_RPCIESATACFG_3_0			0xF	//0/x/x/x PCIe PHY Configuration
#define D0F0_USB3_EPHY_CTL		0xFC	//USB3 EPHY control
    #define D0F0_R_D0F0_FC_7_4			0xF0	//0/R/x/x Reserved
    #define D0F0_REPHY_CLK100_EN			BIT3	//0/x/x/x PCIe/SATA EPHY Internal Reference Clock Enable
    #define D0F0_R_D0F0_FC_2			BIT2	//0/R/x/x Reserved
    #define D0F0_NB2XH_FHP0_REFCLK_SEL			BIT1	//0/x/x/x Manual Setting for Selecting Internal or External Clock
    #define D0F0_NB2XH_FHP0_REFCLKPS_SEL			BIT0	//0/x/x/x Manual Setting for Selecting Internal REFCLK
#define D0F0_GFX_ROMSIP		0xFD	//GFX ROMSIP
    #define D0F0_R_D0F0_FD_7_5			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define D0F0_BIU_STRAP_1			BIT4	//0/x/x/x Power Management D1/D2 Disable
    #define D0F0_BIU_STRAP_0			BIT3	//0/x/x/x HD Audio Enable
    #define D0F0_R_D0F0_FD_2_0			(BIT0 + BIT1 + BIT2)	//0/R/x/x Reserved
#define D0F0_LEGACY_VGA_CYCLE_CTL		0xFE	//Legacy VGA Cycle Control
    #define D0F0_RSV_FEH5			(BIT5 + BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F0_RVGA16B2			BIT4	//1b/1/x/x Enable Base VGA 16-bit Decoding
    #define D0F0_RSV_FEH0			0xF	//0/0/x/x Reserved
#define D0F0_VPI_ROMSIP_REGS		0xFF	//VPI ROMSIP registers
    #define D0F0_R_D0F0_FF_7_1			BIT7	//0/R/x/x Reserved
    #define D0F0_RSV_ROMSIP_FF_6			BIT6	//0/x/x/x Reserved
    #define D0F0_RSV_ROMSIP_FF_5_4			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define D0F0_RSV_FF_3			BIT3	//0/x/x/x Reserved
    #define D0F0_RHSPD_CDC_SYNC_3T			BIT2	//0/x/x/x High Speed CDC Sync 3T Enable
    #define D0F0_LTSSM_SW_RESET_EN_VPI			BIT1	//0/x/x/x VPI  LTSSM Control
    #define D0F0_ROMSIP_VPI_RLNRVSL			BIT0	//0/x/x/x VPI Lane Reversal Select
#define D0F0_ROOT_COMPLEX_LINK_DECLARATION_CAPS_HEADER		0x100	//Root Complex Link Declaration Capabilities Header
    #define D0F0_RX100_31_20			0xFFF00000	//000h/000h/x/x Next Capability Offset
    #define D0F0_RX100_19_16			0xF0000	//1h/1h/x/x Capability Version
    #define D0F0_RX100_15_0			0xFFFF	//0005h/0005h/x/x PCI Express Root Complex Link Declaration Capability ID
#define D0F0_ELEMENT_SELF_DESCRIPTION		0x104	//Element Self Description
    #define D0F0_RPORTNUM_D0F0_7_0			0xFF000000	//0Ah/0Ah/x/x Port Number
    #define D0F0_RX104_23_16			0xFF0000	//01h/01h/x/x Component ID
    #define D0F0_RX104_15_8			0xFF00	//01h/01h/x/x Number of Link Entries
    #define D0F0_RX104_7_4			0xF0	//0/x/x/x Reserved
    #define D0F0_RX104_3_0			0xF	//0/x/x/x Element Type
#define D0F0_UPSTREAM_LINK_DESCRIPTOR		0x110	//Upstream Link Descriptor
    #define D0F0_RX110_31_24			0xFF000000	//00h/00h/x/x Target Port Number
    #define D0F0_RX110_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define D0F0_RX110_15_3			0xFFF8	//0/0/x/x Reserved
    #define D0F0_RX110_2			BIT2	//0/0/x/x Associate RCRB Header
    #define D0F0_RX110_1			BIT1	//0/0/x/x Link Type
    #define D0F0_RX110_0			BIT0	//1b/1/x/x Link Valid
#define D0F0_UPSTREAM_LINK_LOWER_BASE_ADR_FOR_RCRB_H_63_12		0x118	//Upstream Link Lower Base Address for RCRB-H[63:12]
    #define D0F0_RXRCRBHA_31_12			0xFFFFF000	//HwInit/x/x/x Lower Link Address - Bit[31:12]
    #define D0F0_RX118_11_0			0xFFF	//0/x/x/x Lower Link Address - Bit[11:0]
#define D0F0_UPSTREAM_LINK_UPPER_BASE_ADR_FOR_RCRB_H_63_12		0x11C	//Upstream Link Upper Base Address for RCRB-H[63:12]
    #define D0F0_RX11C_31_8			0xFFFFFF00	//0/x/x/x Upper Link Address - Bit[63:40]
    #define D0F0_RXRCRBHA_39_32			0xFF	//HwInit/x/x/x Upper Link Address - Bit[39:32]
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX07_RX04		0x120	//Shadow Register for D3F0 (PCIe Port 0) Rx07~Rx04
    #define D0F0_RX120_31_2			0xFFFFFFFC	//0/R/x/x Reserved
    #define D0F0_RENMEM_PE0_PXP			BIT1	//0/x/x/x Shadow Register for Memory Space Access of D3F0
    #define D0F0_RENIO_PE0_PXP			BIT0	//0/x/x/x Shadow Register for I/O Space Access of D3F0
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX3F_RX3C		0x124	//Shadow Register for D3F0 (PCIe Port 0) Rx3F~Rx3C
    #define D0F0_RX124_31_21			0xFFE00000	//0/R/x/x Reserved
    #define D0F0_RVGA16_PE0_PXP			BIT20	//0/x/x/x Shadow Register for Base VGA 16-bit Decode of D3F0
    #define D0F0_RVGA_PE0_PXP			BIT19	//0/x/x/x Shadow Register for VGA Compatible I/O and Memory Address Range of D3F0
    #define D0F0_RISA_PE0_PXP			BIT18	//0/x/x/x Shadow Register for Block/Forward ISA I/O Cycles of D3F0
    #define D0F0_RX124_17_0			0x3FFFF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX18		0x128	//Shadow Register for D3F0 (PCIe Port 0) Rx18
    #define D0F0_PBN_PE0_PXP_7_0			0xFF	//0/x/x/x Primary Bus Number
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX19		0x129	//Shadow Register for D3F0 (PCIe Port 0) Rx19
    #define D0F0_SBN_PE0_PXP_7_0			0xFF	//0/x/x/x Secondary Bus Number
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX1A		0x12A	//Shadow Register for D3F0 (PCIe Port 0) Rx1A
    #define D0F0_SSBN_PE0_PXP_7_0			0xFF	//0/x/x/x Subordinate Bus Number
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX1B		0x12B	//Shadow Register for D3F0 (PCIe Port 0) Rx1B
    #define D0F0_RX12B_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX1F_RX1C		0x12C	//Shadow Register for D3F0 (PCIe Port 0) Rx1F~Rx1C
    #define D0F0_RX12C_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_RIOLM_PE0_PXP_15_12			0xF000	//0/x/x/x Shadow Register for 4-bit I/O Limit Address Space of D3F0 - Inclusive
    #define D0F0_RX12C_11_8			0xF00	//0/R/x/x Reserved
    #define D0F0_RIOBS_PE0_PXP_15_12			0xF0	//Fh/x/x/x Shadow Register for 4-bit I/O Base Address Space of D3F0 - Inclusive
    #define D0F0_RX12C_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX21_RX20		0x130	//Shadow Register for D3F0 (PCIe Port 0) Rx21~Rx20
    #define D0F0_RM1BS_PE0_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Memory Base Address of D3F0 (AD[31:20] - Inclusive)
    #define D0F0_RX130_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX23_RX22		0x132	//Shadow Register for D3F0 (PCIe Port 0) Rx23~Rx22
    #define D0F0_RM1LM_PE0_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Memory Limit Address of D3F0
    #define D0F0_RX132_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX25_RX24		0x134	//Shadow Register for D3F0 (PCIe Port 0) Rx25~Rx24
    #define D0F0_RM2BS_PE0_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Prefetchable Memory Base Address of D3F0
    #define D0F0_RX134_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX27_RX26		0x136	//Shadow Register for D3F0 (PCIe Port 0) Rx27~Rx26
    #define D0F0_RM2LM_PE0_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Prefetchable Memory Limit Address of D3F0
    #define D0F0_RX136_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX2B_RX28		0x138	//Shadow Register for D3F0 (PCIe Port 0) Rx2B~Rx28
    #define D0F0_RX138_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3BS_PE0_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Base Upper Bit of D3F0
#define D0F0_SHADOW_REG_FOR_D3F0_PCIE_PORT_0_RX2F_RX2C		0x13C	//Shadow Register for D3F0 (PCIe Port 0) Rx2F~Rx2C
    #define D0F0_RX13C_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3LM_PE0_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Limit Upper Bit of D3F0
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX07_RX04		0x140	//Shadow Register for D3F1 (PCIe Port 1) Rx07~Rx04
    #define D0F0_RX140_31_2			0xFFFFFFFC	//0/R/x/x Reserved
    #define D0F0_RENMEM_PE1_PXP			BIT1	//0/x/x/x Shadow Register for Memory Space Access of D3F1
    #define D0F0_RENIO_PE1_PXP			BIT0	//0/x/x/x Shadow Register for I/O Space Access of D3F1
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX3F_RX3C		0x144	//Shadow Register for D3F1 (PCIe Port 1) Rx3F~Rx3C
    #define D0F0_RX144_31_21			0xFFE00000	//0/R/x/x Reserved
    #define D0F0_RVGA16_PE1_PXP			BIT20	//0/x/x/x Shadow Register for Base VGA 16-bit Decode of D3F1
    #define D0F0_RVGA_PE1_PXP			BIT19	//0/x/x/x Shadow Register for VGA Compatible I/O and Memory Address Range of D3F1
    #define D0F0_RISA_PE1_PXP			BIT18	//0/x/x/x Shadow Register for Block/Forward ISA I/O Cycles of D3F1
    #define D0F0_RX144_17_0			0x3FFFF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX18		0x148	//Shadow Register for D3F1 (PCIe Port 1) Rx18
    #define D0F0_PBN_PE1_PXP_7_0			0xFF	//0/x/x/x Primary Bus Number
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX19		0x149	//Shadow Register for D3F1 (PCIe Port 1) Rx19
    #define D0F0_SBN_PE1_PXP_7_0			0xFF	//0/x/x/x Secondary Bus Number
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX1A		0x14A	//Shadow Register for D3F1 (PCIe Port 1) Rx1A
    #define D0F0_SSBN_PE1_PXP_7_0			0xFF	//0/x/x/x Subordinate Bus Number
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX1B		0x14B	//Shadow Register for D3F1 (PCIe Port 1) Rx1B
    #define D0F0_RX14B_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX1F_RX1C		0x14C	//Shadow Register for D3F1 (PCIe Port 1) Rx1F~Rx1C
    #define D0F0_RX14C_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_RIOLM_PE1_PXP_15_12			0xF000	//0/x/x/x Shadow Register for 4-bit I/O Limit Address Space of D3F1 - Inclusive
    #define D0F0_RX14C_11_8			0xF00	//0/R/x/x Reserved
    #define D0F0_RIOBS_PE1_PXP_15_12			0xF0	//Fh/x/x/x Shadow Register for 4-bit I/O Base Address Space of D3F1 - Inclusive
    #define D0F0_RX14C_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX21_RX20		0x150	//Shadow Register for D3F1 (PCIe Port 1) Rx21~Rx20
    #define D0F0_RM1BS_PE1_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Memory Base Address of D3F1 (AD[31:20] - Inclusive)
    #define D0F0_RX150_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX23_RX22		0x152	//Shadow Register for D3F1 (PCIe Port 1) Rx23~Rx22
    #define D0F0_RM1LM_PE1_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Memory Limit Address of D3F1
    #define D0F0_RX152_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX25_RX24		0x154	//Shadow Register for D3F1 (PCIe Port 1) Rx25~Rx24
    #define D0F0_RM2BS_PE1_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Prefetchable Memory Base Address of D3F1
    #define D0F0_RX154_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX27_RX26		0x156	//Shadow Register for D3F1 (PCIe Port 1) Rx27~Rx26
    #define D0F0_RM2LM_PE1_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Prefetchable Memory Limit Address of D3F1
    #define D0F0_RX156_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX2B_RX28		0x158	//Shadow Register for D3F1 (PCIe Port 1) Rx2B~Rx28
    #define D0F0_RX158_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3BS_PE1_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Base Upper Bit of D3F1
#define D0F0_SHADOW_REG_FOR_D3F1_PCIE_PORT_1_RX2F_RX2C		0x15C	//Shadow Register for D3F1 (PCIe Port 1) Rx2F~Rx2C
    #define D0F0_RX15C_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3LM_PE1_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Limit Upper Bit of D3F1
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX07_RX04		0x160	//Shadow Register for D3F2 (PCIe Port 2) Rx07~Rx04
    #define D0F0_RX160_31_2			0xFFFFFFFC	//0/R/x/x Reserved
    #define D0F0_RENMEM_PE2_PXP			BIT1	//0/x/x/x Shadow Register for Memory Space Access of D3F2
    #define D0F0_RENIO_PE2_PXP			BIT0	//0/x/x/x Shadow Register for I/O Space Access of D3F2
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX3F_RX3C		0x164	//Shadow Register for D3F2 (PCIe Port 2) Rx3F~Rx3C
    #define D0F0_RX164_31_21			0xFFE00000	//0/R/x/x Reserved
    #define D0F0_RVGA16_PE2_PXP			BIT20	//0/x/x/x Shadow Register for Base VGA 16-bit Decode of D3F2
    #define D0F0_RVGA_PE2_PXP			BIT19	//0/x/x/x Shadow Register for VGA Compatible I/O and Memory Address Range of D3F2
    #define D0F0_RISA_PE2_PXP			BIT18	//0/x/x/x Shadow Register for Block/Forward ISA I/O Cycles of D3F2
    #define D0F0_RX164_17_0			0x3FFFF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX18		0x168	//Shadow Register for D3F2 (PCIe Port 2) Rx18
    #define D0F0_PBN_PE2_PXP_7_0			0xFF	//0/x/x/x Primary Bus Number
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX19		0x169	//Shadow Register for D3F2 (PCIe Port 2) Rx19
    #define D0F0_SBN_PE2_PXP_7_0			0xFF	//0/x/x/x Secondary Bus Number
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX1A		0x16A	//Shadow Register for D3F2 (PCIe Port 2) Rx1A
    #define D0F0_SSBN_PE2_PXP_7_0			0xFF	//0/x/x/x Subordinate Bus Number
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX1B		0x16B	//Shadow Register for D3F2 (PCIe Port 2) Rx1B
    #define D0F0_RX16B_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX1F_RX1C		0x16C	//Shadow Register for D3F2 (PCIe Port 2) Rx1F~Rx1C
    #define D0F0_RX16C_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_RIOLM_PE2_PXP_15_12			0xF000	//0/x/x/x Shadow Register for 4-bit I/O Limit Address Space of D3F2 - Inclusive
    #define D0F0_RX16C_11_8			0xF00	//0/R/x/x Reserved
    #define D0F0_RIOBS_PE2_PXP_15_12			0xF0	//Fh/x/x/x Shadow Register for 4-bit I/O Base Address Space of D3F2 - Inclusive
    #define D0F0_RX16C_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX21_RX20		0x170	//Shadow Register for D3F2 (PCIe Port 2) Rx21~Rx20
    #define D0F0_RM1BS_PE2_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Memory Base Address of D3F2 (AD[31:20] - Inclusive)
    #define D0F0_RX170_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX23_RX22		0x172	//Shadow Register for D3F2 (PCIe Port 2) Rx23~Rx22
    #define D0F0_RM1LM_PE2_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Memory Limit Address of D3F2
    #define D0F0_RX172_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX25_RX24		0x174	//Shadow Register for D3F2 (PCIe Port 2) Rx25~Rx24
    #define D0F0_RM2BS_PE2_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Prefetchable Memory Base Address of D3F2
    #define D0F0_RX174_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX27_RX26		0x176	//Shadow Register for D3F2 (PCIe Port 2) Rx27~Rx26
    #define D0F0_RM2LM_PE2_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Prefetchable Memory Limit Address of D3F2
    #define D0F0_RX176_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX2B_RX28		0x178	//Shadow Register for D3F2 (PCIe Port 2) Rx2B~Rx28
    #define D0F0_RX178_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3BS_PE2_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Base Upper Bit of D3F2
#define D0F0_SHADOW_REG_FOR_D3F2_PCIE_PORT_2_RX2F_RX2C		0x17C	//Shadow Register for D3F2 (PCIe Port 2) Rx2F~Rx2C
    #define D0F0_RX17C_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3LM_PE2_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Limit Upper Bit of D3F2
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX07_RX04		0x180	//Shadow Register for D3F3 (PCIe Port 3) Rx07~Rx04
    #define D0F0_RX180_31_2			0xFFFFFFFC	//0/R/x/x Reserved
    #define D0F0_RENMEM_PE3_PXP			BIT1	//0/x/x/x Shadow Register for Memory Space Access of D3F3
    #define D0F0_RENIO_PE3_PXP			BIT0	//0/x/x/x Shadow Register for I/O Space Access of D3F3
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX3F_RX3C		0x184	//Shadow Register for D3F3 (PCIe Port 3) Rx3F~Rx3C
    #define D0F0_RX184_31_21			0xFFE00000	//0/R/x/x Reserved
    #define D0F0_RVGA16_PE3_PXP			BIT20	//0/x/x/x Shadow Register for Base VGA 16-bit Decode of D3F3
    #define D0F0_RVGA_PE3_PXP			BIT19	//0/x/x/x Shadow Register for VGA Compatible I/O and Memory Address Range of D3F3
    #define D0F0_RISA_PE3_PXP			BIT18	//0/x/x/x Shadow Register for Block/Forward ISA I/O Cycles of D3F3
    #define D0F0_RX184_17_0			0x3FFFF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX18		0x188	//Shadow Register for D3F3 (PCIe Port 3) Rx18
    #define D0F0_PBN_PE3_PXP_7_0			0xFF	//0/x/x/x Primary Bus Number
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX19		0x189	//Shadow Register for D3F3 (PCIe Port 3) Rx19
    #define D0F0_SBN_PE3_PXP_7_0			0xFF	//0/x/x/x Secondary Bus Number
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX1A		0x18A	//Shadow Register for D3F3 (PCIe Port 3) Rx1A
    #define D0F0_SSBN_PE3_PXP_7_0			0xFF	//0/x/x/x Subordinate Bus Number
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX1B		0x18B	//Shadow Register for D3F3 (PCIe Port 3) Rx1B
    #define D0F0_RX18B_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX1F_RX1C		0x18C	//Shadow Register for D3F3 (PCIe Port 3) Rx1F~Rx1C
    #define D0F0_RX18C_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_RIOLM_PE3_PXP_15_12			0xF000	//0/x/x/x Shadow Register for 4-bit I/O Limit Address Space of D3F3 - Inclusive
    #define D0F0_RX18C_11_8			0xF00	//0/R/x/x Reserved
    #define D0F0_RIOBS_PE3_PXP_15_12			0xF0	//Fh/x/x/x Shadow Register for 4-bit I/O Base Address Space of D3F3 - Inclusive
    #define D0F0_RX18C_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX21_RX20		0x190	//Shadow Register for D3F3 (PCIe Port 3) Rx21~Rx20
    #define D0F0_RM1BS_PE3_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Memory Base Address of D3F3 (AD[31:20] - Inclusive)
    #define D0F0_RX190_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX23_RX22		0x192	//Shadow Register for D3F3 (PCIe Port 3) Rx23~Rx22
    #define D0F0_RM1LM_PE3_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Memory Limit Address of D3F3
    #define D0F0_RX192_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX25_RX24		0x194	//Shadow Register for D3F3 (PCIe Port 3) Rx25~Rx24
    #define D0F0_RM2BS_PE3_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Prefetchable Memory Base Address of D3F3
    #define D0F0_RX194_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX27_RX26		0x196	//Shadow Register for D3F3 (PCIe Port 3) Rx27~Rx26
    #define D0F0_RM2LM_PE3_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Prefetchable Memory Limit Address of D3F3
    #define D0F0_RX196_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX2B_RX28		0x198	//Shadow Register for D3F3 (PCIe Port 3) Rx2B~Rx28
    #define D0F0_RX198_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3BS_PE3_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Base Upper Bit of D3F3
#define D0F0_SHADOW_REG_FOR_D3F3_PCIE_PORT_3_RX2F_RX2C		0x19C	//Shadow Register for D3F3 (PCIe Port 3) Rx2F~Rx2C
    #define D0F0_RX19C_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3LM_PE3_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Limit Upper Bit of D3F3
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX07_RX04		0x1A0	//Shadow Register for D4F1 (PCIe Port G1) Rx07~Rx04
    #define D0F0_RX1A0_31_2			0xFFFFFFFC	//0/R/x/x Reserved
    #define D0F0_RENMEM_PEG1_PXP			BIT1	//0/x/x/x Shadow Register for Memory Space Access of D4F1
    #define D0F0_RENIO_PEG1_PXP			BIT0	//0/x/x/x Shadow Register for I/O Space Access of D4F1
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX3F_RX3C		0x1A4	//Shadow Register for D4F1 (PCIe Port G1) Rx3F~Rx3C
    #define D0F0_RX1A4_31_21			0xFFE00000	//0/R/x/x Reserved
    #define D0F0_RVGA16_PEG1_PXP			BIT20	//0/x/x/x Shadow Register for Base VGA 16-bit Decode of D4F1
    #define D0F0_RVGA_PEG1_PXP			BIT19	//0/x/x/x Shadow Register for VGA Compatible I/O and Memory Address Range of D4F1
    #define D0F0_RISA_PEG1_PXP			BIT18	//0/x/x/x Shadow Register for Block/Forward ISA I/O Cycles of D4F1
    #define D0F0_RX1A4_17_0			0x3FFFF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX18		0x1A8	//Shadow Register for D4F1 (PCIe Port G1) Rx18
    #define D0F0_PBN_PEG1_PXP_7_0			0xFF	//0/x/x/x Primary Bus Number
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX19		0x1A9	//Shadow Register for D4F1 (PCIe Port G1) Rx19
    #define D0F0_SBN_PEG1_PXP_7_0			0xFF	//0/x/x/x Secondary Bus Number
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX1A		0x1AA	//Shadow Register for D4F1 (PCIe Port G1) Rx1A
    #define D0F0_SSBN_PEG1_PXP_7_0			0xFF	//0/x/x/x Subordinate Bus Number
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX1B		0x1AB	//Shadow Register for D4F1 (PCIe Port G1) Rx1B
    #define D0F0_RX1AB_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX1F_RX1C		0x1AC	//Shadow Register for D4F1 (PCIe Port G1) Rx1F~Rx1C
    #define D0F0_RX1AC_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_RIOLM_PEG1_PXP_15_12			0xF000	//0/x/x/x Shadow Register for 4-bit I/O Limit Address Space of D4F1 - Inclusive
    #define D0F0_RX1AC_11_8			0xF00	//0/R/x/x Reserved
    #define D0F0_RIOBS_PEG1_PXP_15_12			0xF0	//Fh/x/x/x Shadow Register for 4-bit I/O Base Address Space of D4F1 - Inclusive
    #define D0F0_RX1AC_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX21_RX20		0x1B0	//Shadow Register for D4F1 (PCIe Port G1) Rx21~Rx20
    #define D0F0_RM1BS_PEG1_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Memory Base Address of D4F1 (AD[31:20] - Inclusive)
    #define D0F0_RX1B0_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX23_RX22		0x1B2	//Shadow Register for D4F1 (PCIe Port G1) Rx23~Rx22
    #define D0F0_RM1LM_PEG1_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Memory Limit Address of D4F1
    #define D0F0_RX1B2_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX25_RX24		0x1B4	//Shadow Register for D4F1 (PCIe Port G1) Rx25~Rx24
    #define D0F0_RM2BS_PEG1_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Prefetchable Memory Base Address of D4F1
    #define D0F0_RX1B4_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX27_RX26		0x1B6	//Shadow Register for D4F1 (PCIe Port G1) Rx27~Rx26
    #define D0F0_RM2LM_PEG1_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Prefetchable Memory Limit Address of D4F1
    #define D0F0_RX1B6_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORT_G1_RX2B_RX28		0x1B8	//Shadow Register for D4F1 (PCIe Port G1) Rx2B~Rx28
    #define D0F0_RX1B8_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3BS_PEG1_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Base Upper Bit of D4F1
#define D0F0_SHADOW_REG_FOR_D4F1_PCIE_PORTG1_RX2F_RX2C		0x1BC	//Shadow Register for D4F1 (PCIe PortG1) Rx2F~Rx2C
    #define D0F0_RX1BC_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3LM_PEG1_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Limit Upper Bit of D4F1
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX07_RX04		0x300	//Shadow Register for D5F0 (PCIe Port G2) Rx07~Rx04
    #define D0F0_RX300_31_2			0xFFFFFFFC	//0/R/x/x Reserved
    #define D0F0_RENMEM_PEG2_PXP			BIT1	//0/x/x/x Shadow Register for Memory Space Access of D5F0
    #define D0F0_RENIO_PEG2_PXP			BIT0	//0/x/x/x Shadow Register for I/O Space Access of D5F0
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX3F_RX3C		0x304	//Shadow Register for D5F0 (PCIe Port G2) Rx3F~Rx3C
    #define D0F0_RX304_31_21			0xFFE00000	//0/R/x/x Reserved
    #define D0F0_RVGA16_PEG2_PXP			BIT20	//0/x/x/x Shadow Register for Base VGA 16-bit Decode of D5F0
    #define D0F0_RVGA_PEG2_PXP			BIT19	//0/x/x/x Shadow Register for VGA Compatible I/O and Memory Address Range of D5F0
    #define D0F0_RISA_PEG2_PXP			BIT18	//0/x/x/x Shadow Register for Block/Forward ISA I/O Cycles of D5F0
    #define D0F0_RX304_17_0			0x3FFFF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX18		0x308	//Shadow Register for D5F0 (PCIe Port G2) Rx18
    #define D0F0_PBN_PEG2_PXP_7_0			0xFF	//0/x/x/x Primary Bus Number
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX19		0x309	//Shadow Register for D5F0 (PCIe Port G2) Rx19
    #define D0F0_SBN_PEG2_PXP_7_0			0xFF	//0/x/x/x Secondary Bus Number
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX1A		0x30A	//Shadow Register for D5F0 (PCIe Port G2) Rx1A
    #define D0F0_SSBN_PEG2_PXP_7_0			0xFF	//0/x/x/x Subordinate Bus Number
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX1B		0x30B	//Shadow Register for D5F0 (PCIe Port G2) Rx1B
    #define D0F0_RX30B_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX1F_RX1C		0x30C	//Shadow Register for D5F0 (PCIe Port G2) Rx1F~Rx1C
    #define D0F0_RX30C_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_RIOLM_PEG2_PXP_15_12			0xF000	//0/x/x/x Shadow Register for 4-bit I/O Limit Address Space of D5F0 - Inclusive
    #define D0F0_RX30C_11_8			0xF00	//0/R/x/x Reserved
    #define D0F0_RIOBS_PEG2_PXP_15_12			0xF0	//Fh/x/x/x Shadow Register for 4-bit I/O Base Address Space of D5F0 - Inclusive
    #define D0F0_RX30C_3_0			0xF	//0/x/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX21_RX20		0x310	//Shadow Register for D5F0 (PCIe Port G2) Rx21~Rx20
    #define D0F0_RM1BS_PEG2_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Memory Base Address of D5F0 (AD[31:20] - Inclusive)
    #define D0F0_RX310_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX23_RX22		0x312	//Shadow Register for D5F0 (PCIe Port G2) Rx23~Rx22
    #define D0F0_RM1LM_PEG2_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Memory Limit Address of D5F0
    #define D0F0_RX312_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX25_RX24		0x314	//Shadow Register for D5F0 (PCIe Port G2) Rx25~Rx24
    #define D0F0_RM2BS_PEG2_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Prefetchable Memory Base Address of D5F0
    #define D0F0_RX314_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX27_RX26		0x316	//Shadow Register for D5F0 (PCIe Port G2) Rx27~Rx26
    #define D0F0_RM2LM_PEG2_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Prefetchable Memory Limit Address of D5F0
    #define D0F0_RX316_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX2B_RX28		0x318	//Shadow Register for D5F0 (PCIe Port G2) Rx2B~Rx28
    #define D0F0_RX318_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3BS_PEG2_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Base Upper Bit of D5F0
#define D0F0_SHADOW_REG_FOR_D5F0_PCIE_PORT_G2_RX2F_RX2C		0x31C	//Shadow Register for D5F0 (PCIe Port G2) Rx2F~Rx2C
    #define D0F0_RX31C_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3LM_PEG2_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Limit Upper Bit of D5F0
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX07_RX04		0x320	//Shadow Register for D5F1 (PCIe Port G3) Rx07~Rx04
    #define D0F0_RX320_31_2			0xFFFFFFFC	//0/R/x/x Reserved
    #define D0F0_RENMEM_PEG3_PXP			BIT1	//0/x/x/x Shadow Register for Memory Space Access of D5F1
    #define D0F0_RENIO_PEG3_PXP			BIT0	//0/x/x/x Shadow Register for I/O Space Access of D5F1
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX3F_RX3C		0x324	//Shadow Register for D5F1 (PCIe Port G3) Rx3F~Rx3C
    #define D0F0_RX324_31_21			0xFFE00000	//0/R/x/x Reserved
    #define D0F0_RVGA16_PEG3_PXP			BIT20	//0/x/x/x Shadow Register for Base VGA 16-bit Decode of D5F1
    #define D0F0_RVGA_PEG3_PXP			BIT19	//0/x/x/x Shadow Register for VGA Compatible I/O and Memory Address Range of D5F1
    #define D0F0_RISA_PEG3_PXP			BIT18	//0/x/x/x Shadow Register for Block/Forward ISA I/O Cycles of D5F1
    #define D0F0_RX324_17_0			0x3FFFF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX18		0x328	//Shadow Register for D5F1 (PCIe Port G3) Rx18
    #define D0F0_PBN_PEG3_PXP_7_0			0xFF	//0/x/x/x Primary Bus Number
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX19		0x329	//Shadow Register for D5F1 (PCIe Port G3) Rx19
    #define D0F0_SBN_PEG3_PXP_7_0			0xFF	//0/x/x/x Secondary Bus Number
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX1A		0x32A	//Shadow Register for D5F1 (PCIe Port G3) Rx1A
    #define D0F0_SSBN_PEG3_PXP_7_0			0xFF	//0/x/x/x Subordinate Bus Number
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX1B		0x32B	//Shadow Register for D5F1 (PCIe Port G3) Rx1B
    #define D0F0_RX32B_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX1F_RX1C		0x32C	//Shadow Register for D5F1 (PCIe Port G3) Rx1F~Rx1C
    #define D0F0_RX32C_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_RIOLM_PEG3_PXP_15_12			0xF000	//0/x/x/x Shadow Register for 4-bit I/O Limit Address Space of D5F1 - Inclusive
    #define D0F0_RX32C_11_8			0xF00	//0/R/x/x Reserved
    #define D0F0_RIOBS_PEG3_PXP_15_12			0xF0	//Fh/x/x/x Shadow Register for 4-bit I/O Base Address Space of D5F1 - Inclusive
    #define D0F0_RX32C_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX21_RX20		0x330	//Shadow Register for D5F1 (PCIe Port G3) Rx21~Rx20
    #define D0F0_RM1BS_PEG3_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Memory Base Address of D5F1 (AD[31:20] - Inclusive)
    #define D0F0_RX330_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX23_RX22		0x332	//Shadow Register for D5F1 (PCIe Port G3) Rx23~Rx22
    #define D0F0_RM1LM_PEG3_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Memory Limit Address of D5F1
    #define D0F0_RX332_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX25_RX24		0x334	//Shadow Register for D5F1 (PCIe Port G3) Rx25~Rx24
    #define D0F0_RM2BS_PEG3_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Prefetchable Memory Base Address of D5F1
    #define D0F0_RX334_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX27_RX26		0x336	//Shadow Register for D5F1 (PCIe Port G3) Rx27~Rx26
    #define D0F0_RM2LM_PEG3_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Prefetchable Memory Limit Address of D5F1
    #define D0F0_RX336_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX2B_RX28		0x338	//Shadow Register for D5F1 (PCIe Port G3) Rx2B~Rx28
    #define D0F0_RX338_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3BS_PEG3_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Base Upper Bit of D5F1
#define D0F0_SHADOW_REG_FOR_D5F1_PCIE_PORT_G3_RX2F_RX2C		0x33C	//Shadow Register for D5F1 (PCIe Port G3) Rx2F~Rx2C
    #define D0F0_RX33C_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3LM_PEG3_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Limit Upper Bit of D5F1
#define D0F0_PCIE_PORT_G2_INTR_ROUTING_SEL		0x360	//PCIe Port G2 Interrupt Routing Selection
    #define D0F0_RX360_7_6			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define D0F0_RINTRTAPIC_PEG2_1_0			(BIT4 + BIT5)	//00b/00b/x/x PCIe Port G2 Interrupt Routing in APIC Mode
    #define D0F0_RINTRT_PEG2_1_0			(BIT2 + BIT3)	//00b/00b/x/x PCIe Port G2 Interrupt Routing in PIC Mode
    #define D0F0_RMSGCINTRT_PEG2_1_0			(BIT0 + BIT1)	//11b/11b/x/x PCIe Port G2 MSG Interrupt Routing
#define D0F0_PCIE_PORT_G3_INTR_ROUTING_SEL		0x361	//PCIe Port G3 Interrupt Routing Selection
    #define D0F0_RX361_7_6			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define D0F0_RINTRTAPIC_PEG3_1_0			(BIT4 + BIT5)	//00b/00b/x/x PCIe Port G3 Interrupt Routing in APIC Mode
    #define D0F0_RINTRT_PEG3_1_0			(BIT2 + BIT3)	//00b/00b/x/x PCIe PortG3 Interrupt Routing in PIC Mode
    #define D0F0_RMSGCINTRT_PEG3_1_0			(BIT0 + BIT1)	//11b/11b/x/x PCIe Port G3 MSG Interrupt Routing
#define D0F0_RESERVED_Z3		0x362	//Reserved
    #define D0F0_RX362_7_0			0xFF	//0/R/x/x Reserved
#define D0F0_RAID0INT_AND_RAID1INT_ROUTING_SEL		0x363	//RAID0INT and RAID1INT Routing Selection
    #define D0F0_RAID0INTIRQ_1_0			(BIT6 + BIT7)	//00b/0/x/x RAID0 Interrupt Routing to APICX Controlling
    #define D0F0_RAID0INTRT_1_0			(BIT4 + BIT5)	//00b/0/x/x Route RAID0 Interrupts to SM Controller
    #define D0F0_RAID1INTIRQ_1_0			(BIT2 + BIT3)	//00b/0/x/x RAID1 Interrupt Routing to APICX Controlling
    #define D0F0_RAID1INTRT_1_0			(BIT0 + BIT1)	//00b/0/x/x Route RAID1 Interrupts to SM Controller
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX07_RX04		0x400	//Shadow Register for D4F0 (PCIe Port G0) Rx07~Rx04
    #define D0F0_RX400_31_2			0xFFFFFFFC	//0/R/x/x Reserved
    #define D0F0_RENMEM_PEG0_PXP			BIT1	//0/x/x/x Shadow Register for Memory Space Access of D4F0
    #define D0F0_RENIO_PEG0_PXP			BIT0	//0/x/x/x Shadow Register for I/O Space Access of D4F0
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX3F_RX3C		0x404	//Shadow Register for D4F0 (PCIe Port G0) Rx3F~Rx3C
    #define D0F0_RX404_31_21			0xFFE00000	//0/R/x/x Reserved
    #define D0F0_RVGA16_PEG0_PXP			BIT20	//0/x/x/x Shadow Register for Base VGA 16-bit Decode of D4F0
    #define D0F0_RVGA_PEG0_PXP			BIT19	//0/x/x/x Shadow Register for VGA Compatible I/O and Memory Address Range of D4F0
    #define D0F0_RISA_PEG0_PXP			BIT18	//0/x/x/x Shadow Register for Block/Forward ISA I/O Cycles of D4F0
    #define D0F0_RX404_17_0			0x3FFFF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX18		0x408	//Shadow Register for D4F0 (PCIe Port G0) Rx18
    #define D0F0_PBN_PEG0_PXP_7_0			0xFF	//0/x/x/x Primary Bus Number
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX19		0x409	//Shadow Register for D4F0 (PCIe Port G0) Rx19
    #define D0F0_SBN_PEG0_PXP_7_0			0xFF	//0/x/x/x Secondary Bus Number
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX1A		0x40A	//Shadow Register for D4F0 (PCIe Port G0) Rx1A
    #define D0F0_SSBN_PEG0_PXP_7_0			0xFF	//0/x/x/x Subordinate Bus Number
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX1B		0x40B	//Shadow Register for D4F0 (PCIe Port G0) Rx1B
    #define D0F0_RX40B_31_24			0xFF	//0/R/x/x Secondary Latency Timer
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX1F_RX1C		0x40C	//Shadow Register for D4F0 (PCIe Port G0) Rx1F~Rx1C
    #define D0F0_RX40C_31_16			0xFFFF0000	//0/R/x/x Reserved
    #define D0F0_RIOLM_PEG0_PXP_15_12			0xF000	//0/x/x/x Shadow Register for 4-bit I/O Limit Address Space of D4F0 - Inclusive
    #define D0F0_RX40C_11_8			0xF00	//0/R/x/x Reserved
    #define D0F0_RIOBS_PEG0_PXP_15_12			0xF0	//Fh/x/x/x Shadow Register for 4-bit I/O Base Address Space of D4F0 - Inclusive
    #define D0F0_RX40C_3_0			0xF	//0/x/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX21_RX20		0x410	//Shadow Register for D4F0 (PCIe Port G0) Rx21~Rx20
    #define D0F0_RM1BS_PEG0_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Memory Base Address of D4F0 (AD[31:20] - Inclusive)
    #define D0F0_RX410_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX23_RX22		0x412	//Shadow Register for D4F0 (PCIe Port G0) Rx23~Rx22
    #define D0F0_RM1LM_PEG0_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Memory Limit Address of D4F0
    #define D0F0_RX412_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX25_RX24		0x414	//Shadow Register for D4F0 (PCIe Port G0) Rx25~Rx24
    #define D0F0_RM2BS_PEG0_PXP_31_20			0xFFF0	//FFFh/x/x/x Shadow Register for Prefetchable Memory Base Address of D4F0
    #define D0F0_RX414_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX27_RX26		0x416	//Shadow Register for D4F0 (PCIe Port G0) Rx27~Rx26
    #define D0F0_RM2LM_PEG0_PXP_31_20			0xFFF0	//0/x/x/x Shadow Register for Prefetchable Memory Limit Address of D4F0
    #define D0F0_RX416_3_0			0xF	//0/R/x/x Reserved
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX2B_RX28		0x418	//Shadow Register for D4F0 (PCIe Port G0) Rx2B~Rx28
    #define D0F0_RX418_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3BS_PEG0_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Base Upper Bit of D4F0
#define D0F0_SHADOW_REG_FOR_D4F0_PCIE_PORT_G0_RX2F_RX2C		0x41C	//Shadow Register for D4F0 (PCIe Port G0) Rx2F~Rx2C
    #define D0F0_RX41C_31_8			0xFFFFFF00	//0/R/x/x Reserved
    #define D0F0_RM3LM_PEG0_PXP_39_32			0xFF	//0/x/x/x Shadow Register for Prefetchable Memory Limit Upper Bit of D4F0
#endif
