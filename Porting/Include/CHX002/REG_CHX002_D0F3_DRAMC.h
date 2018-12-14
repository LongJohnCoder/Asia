//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		DRAMC					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D0F3_DRAMC_R101(A0).doc(final)MOD_D0F3.xls
#ifndef _CHX002_D0F3_DRAMC_H
#define _CHX002_D0F3_DRAMC_H
//D0F3
#define D0F3_VID		0x00	//Vendor ID
    #define D0F3_VENDORID_15_0			0xFFFF	//1106h/x/x/x VIA Technologies ID Code
#define D0F3_DID		0x02	//Device ID
    #define D0F3_DEVICEID_15_0			0xFFFF	//31B2h/x/x/x Device ID
#define D0F3_PCI_CMD		0x04	//PCI Command
    #define D0F3_D0F3_RX04_15_10			0xFC00	//0/R/x/x Reserved
    #define D0F3_RFBACK			BIT9	//0/R/x/x Fast Back-to-Back Cycle Enable
    #define D0F3_RSERR			BIT8	//0/R/x/x SERR# Enable 
    #define D0F3_RSETP			BIT7	//0/R/x/x Address / Data Stepping
    #define D0F3_RPTYERR			BIT6	//0/R/x/x Parity Error Response
    #define D0F3_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D0F3_RMWINV			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D0F3_RSPCYC			BIT3	//0/R/x/x Respond To Special Cycle
    #define D0F3_RMSTR			BIT2	//1b/R/x/x PCI Master Function
    #define D0F3_RENMEM			BIT1	//1b/R/x/x Memory Space Access
    #define D0F3_RENIO			BIT0	//0/R/x/x I/O Space Access
#define D0F3_PCI_STA		0x06	//PCI Status
    #define D0F3_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D0F3_SERRS			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D0F3_SMABORT			BIT13	//0/R/x/x Received Master-Abort (Except Special Cycle)
    #define D0F3_STABORTM			BIT12	//0/R/x/x Received Target-Abort
    #define D0F3_STABORTS			BIT11	//0/R/x/x Target-Abort Assertion
    #define D0F3_DEVS_1_0			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D0F3_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D0F3_RFBKS			BIT7	//0/R/x/x Capable of Accepting Fast Back-to-back as A Target
    #define D0F3_RUDF			BIT6	//0/R/x/x User Definable Features
    #define D0F3_R66M			BIT5	//0/R/x/x 66 MHz Capable
    #define D0F3_RCAP			BIT4	//1b/1b/x/x Support New Capability List
    #define D0F3_D0F3_RX04_19_16			0xF	//0/R/x/x Reserved
#define D0F3_REV_ID		0x08	//Revision ID
    #define D0F3_D0F3_RX08_7_0			0xFF	//04h/x/x/x Revision Code
#define D0F3_CLASS_CODE		0x09	//Class Code
    #define D0F3_D0F3_RX08_31_8			0xFFFFFF	//060000h/x/x/x Class Code
#define D0F3_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D0F3_D0F3_RX0C_7_0			0xFF	//0/x/x/x Cache Line Size
#define D0F3_PCI_MASTER_LATENCY_TIMER		0x0D	//PCI Master Latency Timer
    #define D0F3_D0F3_RX0C_15_8			0xFF	//0/R/x/x Maximum Time Slice for this Function as a Master on the PCI Bus
#define D0F3_HEADER_TYPE		0x0E	//Header Type
    #define D0F3_D0F3_RX0C_23_16			0xFF	//80h/R/x/x Header Type
#define D0F3_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D0F3_BIST_7_0			0xFF	//0/R/x/x BIST Support
#define D0F3_BASE_ADR_REGS_0		0x10	//Base Address Registers 0
    #define D0F3_D0F3_RX10_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 0
#define D0F3_BASE_ADR_REGS_1		0x14	//Base Address Registers 1
    #define D0F3_D0F3_RX14_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 1
#define D0F3_BASE_ADR_REGS_2		0x18	//Base Address Registers 2
    #define D0F3_D0F3_RX18_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 2
#define D0F3_BASE_ADR_REGS_3		0x1C	//Base Address Registers 3
    #define D0F3_D0F3_RX1C_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 3
#define D0F3_BASE_ADR_REGS_4		0x20	//Base Address Registers 4
    #define D0F3_D0F3_RX20_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 4
#define D0F3_BASE_ADR_REGS_5		0x24	//Base Address Registers 5
    #define D0F3_D0F3_RX24_31_0			0xFFFFFFFF	//0/R/x/x Base Address - 5
#define D0F3_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D0F3_D0F3_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D0F3_SVID		0x2C	//Subsystem Vendor ID
    #define D0F3_D0F3_RX2C_15_0			0xFFFF	//0/*/x/x Subsystem Vendor ID
#define D0F3_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D0F3_D0F3_RX2C_31_16			0xFFFF	//0/*/x/x Subsystem ID
#define D0F3_CAP_POINTER		0x34	//Capability Pointer
    #define D0F3_CAPPTR_7_0			0xFF	//40h/40h/x/x Capability List Pointer
#define D0F3_RESERVED		0x35	//Reserved
    #define D0F3_D0F3_RX35_7_0			0xFF	//0/R/x/x Reserved
#define D0F3_RESERVED_Z1		0x36	//Reserved
    #define D0F3_D0F3_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D0F3_RESERVED_Z2		0x37	//Reserved
    #define D0F3_D0F3_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D0F3_RESERVED_Z3		0x38	//Reserved
    #define D0F3_D0F3_RX38_31_0			0xFFFFFFFF	//0/R/x/x Reserved
#define D0F3_INTR_LINE_AND_INTR_PIN		0x3C	//Interrupt Line and Interrupt Pin
    #define D0F3_D0F3_RX3D_7_0			0xFF00	//0/R/x/x Interrupt Pin
    #define D0F3_D0F3_RX3C_7_0			0xFF	//0/R/x/x Interrupt Line
#define D0F3_MINIMUM_GRANT_AND_MAXIMUM_LATENCY		0x3E	//Minimum Grant and Maximum Latency
    #define D0F3_D0F3_RX3F_7_0			0xFF00	//0/R/x/x Maximum Latency
    #define D0F3_D0F3_RX3E_7_0			0xFF	//0/R/x/x Minimum Grant
#define D0F3_PCI_EXPRESS_LIST		0x40	//PCI Express List
    #define D0F3_RX40_15_8			0xFF00	//B0h/B0h/x/x Next Pointer
    #define D0F3_RX40_7_0			0xFF	//10h/10h/x/x Capability ID
#define D0F3_PCI_EXPRESS_CAPS		0x42	//PCI Express Capabilities
    #define D0F3_D0F3_RX42_15_14			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_RX42_13_9			0x3E00	//0/0/x/x Interrupt Message Number
    #define D0F3_RX42_8			BIT8	//0b/0b/x/x Slot Implemented
    #define D0F3_RX42_7_4			0xF0	//0100b/0100b/x/x Device / Port Type
    #define D0F3_RX42_3_0			0xF	//2h/2h/x/x Capability Version Bit
#define D0F3_DEV_CAPS_1		0x44	//Device Capabilities 1
    #define D0F3_D0F3_RX47_7_5			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define D0F3_TBD_27			BIT28	//0/0/x/x Function Level Reset Capability
    #define D0F3_RSV_20			(BIT26 + BIT27)	//0/0/x/x Captured Slot Power Limit Scale
    #define D0F3_RSV_21			0x3FC0000	//0/0/x/x Captured Slot Power Limit Value
    #define D0F3_D0F3_RX46_1_0			(BIT16 + BIT17)	//0/R/x/x Reserved
    #define D0F3_RRBERRP			BIT15	//1b/1/x/x Role-based Error Reporting
    #define D0F3_RSV_23			BIT14	//0/0/x/x Power Indicator Present
    #define D0F3_RSV_24			BIT13	//0/0/x/x Attention Indicator Present
    #define D0F3_RSV_25			BIT12	//0/0/x/x Attention Button Present
    #define D0F3_DAL1AL			(BIT9 + BIT10 + BIT11)	//000b/0/x/x Endpoint L1 Acceptable Latency
    #define D0F3_RSV_44			(BIT6 + BIT7 + BIT8)	//0/0/x/x Endpoint L0s Acceptable Latency
    #define D0F3_DAXTAGF			BIT5	//0/0/x/x Extended Tag Field Supported
    #define D0F3_RSV_26			(BIT3 + BIT4)	//0/0/x/x Phantom Functions Supported
    #define D0F3_DAMPSS			(BIT0 + BIT1 + BIT2)	//000b/000b/x/x Max Payload Size Supported
#define D0F3_DEV_CTL_1		0x48	//Device Control 1
    #define D0F3_D0F3_RX49_7			BIT15	//0/R/x/x Reserved
    #define D0F3_DCMRRS			(BIT12 + BIT13 + BIT14)	//0/0/x/x Max Read Request Size
    #define D0F3_DCENS			BIT11	//0/0/x/x Enable No Snoop
    #define D0F3_DCAPPME			BIT10	//0/0/x/x Auxiliary Power PM Enable
    #define D0F3_DCPFE			BIT9	//0/0/x/x Phantom Functions Enable
    #define D0F3_DCETFE			BIT8	//0/0/x/x Extended Tag Field Enable
    #define D0F3_DCMPS			(BIT5 + BIT6 + BIT7)	//0/0/0/x Max Payload Size
    #define D0F3_DCERO			BIT4	//1b/1/x/x Enable Relaxed Ordering
    #define D0F3_DCURRE			BIT3	//0/0/x/x Unsupported Request Reporting Enable
    #define D0F3_DCFERE			BIT2	//0/0/x/x Fatal Error Reporting Enable
    #define D0F3_DCNFERE			BIT1	//0/0/x/x Non-Fatal Error Reporting Enable
    #define D0F3_DCCERE			BIT0	//0/0/x/x Correctable Error Reporting Enable
#define D0F3_DEV_STA_1		0x4A	//Device Status 1
    #define D0F3_D0F3_RX4B_7_0			0xFF00	//0/R/x/x Reserved
    #define D0F3_D0F3_RX4A_7_6			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define D0F3_DSTP			BIT5	//0/0/x/x Transactions Pending
    #define D0F3_DSAPD			BIT4	//0/0/x/x AUX Power Detected
    #define D0F3_DSURD			BIT3	//0/0/x/x Unsupported Request Detected (TL)
    #define D0F3_DSFED			BIT2	//0/0/x/x Fatal Error Detected (TL)
    #define D0F3_DSNFED			BIT1	//0/0/x/x Non-Fatal Error Detected (TL)
    #define D0F3_DSCED			BIT0	//0/0/x/x Correctable Error Detected (TL)
#define D0F3_LINK_CAPS_1		0x4C	//Link Capabilities 1
    #define D0F3_LKPN			0xFF000000	//0/x/x/x Port Number
    #define D0F3_D0F3_RX4E_7_6			(BIT22 + BIT23)	//0/R/x/x Reserved
    #define D0F3_RLBWNTFC			BIT21	//0b/0b/x/x Link Bandwidth Notification Capability
    #define D0F3_RDL_AR_CAP			BIT20	//0b/0b/x/x Data Link Layer Link Active Reporting Capable
    #define D0F3_RLCASDERC			BIT19	//0b/0b/x/x Surprise Down Error Reporting Capable
    #define D0F3_RLCACPM			BIT18	//0/0/x/x Clock Power Management
    #define D0F3_LKL1EL			(BIT15 + BIT16 + BIT17)	//011b/x/x/x L1 Exit Latency
    #define D0F3_LKL0SE			(BIT12 + BIT13 + BIT14)	//011b/x/x/x L0s Exit Latency
    #define D0F3_LKAPMS			(BIT10 + BIT11)	//11b/11b/x/x Active State Link PM (ASPM) Support
    #define D0F3_LKMLW_5			BIT9	//0/0/x/x Maximum Link Width Bit 5
    #define D0F3_LKMLW_4			BIT8	//0/0/x/x Maximum Link Width Bit 4
    #define D0F3_LKMLW_3			BIT7	//0/0/x/x Maximum Link Width Bit 3
    #define D0F3_LKMLW_2			BIT6	//1b/1b/x/x Maximum Link Width Bit 2
    #define D0F3_LKMLW_1			BIT5	//0/x/x/x Maximum Link Width Bit 1
    #define D0F3_LKMLW_0			BIT4	//0/x/x/x Maximum Link Width Bit 0
    #define D0F3_LKMAXLS_3			BIT3	//0/0/x/x Max Link Speed Bit 3
    #define D0F3_LKMAXLS_2			BIT2	//0/0/x/x Max Link Speed Bit 2
    #define D0F3_LKMAXLS_1			BIT1	//0b/0b/x/x Max Link Speed Bit 1
    #define D0F3_LKMAXLS_0			BIT0	//1b/1b/x/x Max Link Speed Bit 0
#define D0F3_LINK_CTL_1		0x50	//Link Control 1
    #define D0F3_D0F3_RX51_7_4			0xF000	//0/R/x/x Reserved
    #define D0F3_RLABITEN			BIT11	//0/0/x/x Enable Link Autonomous Bandwidth Interrupt
    #define D0F3_RLBMITEN			BIT10	//0/0/x/x Enable Link Bandwidth Management Interrupt
    #define D0F3_RHATNMWD			BIT9	//0/0/x/0 Hardware Autonomous Width Control
    #define D0F3_RLCOCPMEN			BIT8	//0/0/x/x Enable Clock Power Management
    #define D0F3_LCES			BIT7	//0/0/0/x Extended Synch
    #define D0F3_LCCCC			BIT6	//1b/x/x/x Common Clock Configuration
    #define D0F3_LCRL			BIT5	//0/0/x/x Retrain Link
    #define D0F3_LCLD			BIT4	//0/0/x/x Link Disable
    #define D0F3_LCRCB			BIT3	//0/0/x/x Read Completion Boundary
    #define D0F3_D0F3_RX50_2			BIT2	//0/R/x/x Reserved
    #define D0F3_LCAPMS			(BIT0 + BIT1)	//00b/0/0/11 Link Active State PM (ASPM) Control
#define D0F3_LINK_STA_1		0x52	//Link Status 1
    #define D0F3_RLATNMBW			BIT15	//0/0/x/x Link Autonomous Bandwidth Status
    #define D0F3_RLBWMNGT			BIT14	//0/0/x/x Link Bandwidth Management Status
    #define D0F3_DL_ACTIVE			BIT13	//0/x/x/x Data Link Layer Link Active
    #define D0F3_LSSCC			BIT12	//1b/x/x/x Slot Clock Configuration
    #define D0F3_LSLT			BIT11	//0/0/x/x Link Training
    #define D0F3_LSTE			BIT10	//0/0/x/x Training Error
    #define D0F3_TBD_28			BIT9	//0/0/x/x Negotiated Link Width Bit 5
    #define D0F3_LSNLW			0x1F0	//0/0/x/x Negotiated Link Width Bits[4:0]
    #define D0F3_LSLS			0xF	//0/0/x/x Current Link Speed
#define D0F3_SLOT_CAPS_1		0x54	//Slot Capabilities 1
    #define D0F3_SLPSN			0xFFF80000	//0/0/x/x Physical Slot Number; Reserved
    #define D0F3_RSCANCCS			BIT18	//0/0/x/x No Command Completed Support
    #define D0F3_RSCAEMIP			BIT17	//0/0/x/x Electromechanical Interlock Present
    #define D0F3_RSPLS			(BIT15 + BIT16)	//00b/0/x/x Slot Power Limit Scale
    #define D0F3_RSPLV			0x7F80	//0/0/x/x Slot Power Limit Value
    #define D0F3_SCHP_CAP			BIT6	//0/0/x/x Hot-Plug Capable
    #define D0F3_SCHPS			BIT5	//1b/1/x/x Hot-Plug Surprise
    #define D0F3_SCPIP			BIT4	//0/0/x/x Power Indicator Present
    #define D0F3_SCAIP			BIT3	//0/0/x/x Attention Indicator Present
    #define D0F3_RSV_36			BIT2	//0/0/x/x MRL Sensor Present
    #define D0F3_RSV_37			BIT1	//0/0/x/x Power Controller Present
    #define D0F3_SCABP			BIT0	//0/0/x/x Attention Button Present
#define D0F3_SLOT_CTL_1		0x58	//Slot Control 1
    #define D0F3_D0F3_RX59_7_5			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define D0F3_RDLSCHGEN			BIT12	//0/0/x/x Enable Data Link Layer State Change
    #define D0F3_RSCOEMIC			BIT11	//0/0/x/x Electromechanical Interlock Control
    #define D0F3_SCPCC			BIT10	//0/0/x/x Power Controller Control
    #define D0F3_SCPIC			(BIT8 + BIT9)	//00b/0/x/x Power Indicator Control
    #define D0F3_SCAIC			(BIT6 + BIT7)	//00b/0/x/x Attention Indicator Control
    #define D0F3_SCHPIE			BIT5	//0/0/x/x Enable Hot-Plug Interrupt
    #define D0F3_SCCCIE			BIT4	//0/0/x/x Enable Command Completed Interrupt 
    #define D0F3_SCPDCE			BIT3	//0/0/x/x Enable Presence Detect Change
    #define D0F3_RSV_40			BIT2	//0/0/x/x Enable MRL Sensor Change
    #define D0F3_RSV_41			BIT1	//0/0/x/x Enable Power Fault Detected
    #define D0F3_SCABPE			BIT0	//0/0/x/x Enable Attention Button Pressed
#define D0F3_SLOT_STA_1		0x5A	//Slot Status 1
    #define D0F3_RSV_42			0xFE00	//0/R/x/x Reserved
    #define D0F3_RDLSCHG			BIT8	//0/0/x/x Data Link Layer State Changed
    #define D0F3_RSSEMIS			BIT7	//0/0/x/x Electromechanical Interlock Status
    #define D0F3_SPDCST			BIT6	//0/0/x/x Presence Detect State
    #define D0F3_RSV_43			BIT5	//0/0/x/x MRL (Manually Operated Retention Latch) Sensor State
    #define D0F3_SSCC			BIT4	//0/0/x/x Command Completed
    #define D0F3_SPDC			BIT3	//0/0/x/x Presence Detect Change
    #define D0F3_TBD_29			BIT2	//0/0/x/x MRL Sensor Change
    #define D0F3_TBD_30			BIT1	//0/0/x/x Power Fault Detected
    #define D0F3_SSABP			BIT0	//0/0/x/x Attention Button Pressed
#define D0F3_ROOT_CTL		0x5C	//Root Control
    #define D0F3_RSV_5C_5			0xFFE0	//0/R/x/x Reserved
    #define D0F3_RCCRSSVE			BIT4	//0/0/x/x Enable CRS Software Visibility 
    #define D0F3_RCPMEIE			BIT3	//0/0/x/x Enable PME Interrupt
    #define D0F3_RCSEFEE			BIT2	//0/0/x/x Enable System Error on Fatal Error
    #define D0F3_RCSENFEE			BIT1	//0/0/x/x Enable System Error on Non-Fatal Error
    #define D0F3_RCSECEE			BIT0	//0/0/x/x Enable System Error on Correctable Error
#define D0F3_ROOT_CAPS		0x5E	//Root Capabilities
    #define D0F3_RSV_44_5E			0xFFFE	//0/R/x/x Reserved
    #define D0F3_RSCRSSFV			BIT0	//0/0/x/x Configuration Request Retry Status (CRS) Software Visibility
#define D0F3_ROOT_STA		0x60	//Root Status
    #define D0F3_RSV_45			0xFFFC0000	//0/R/x/x Reserved
    #define D0F3_RSPP			BIT17	//0/0/x/x PME Pending
    #define D0F3_RSPS			BIT16	//0/0/x/x PME Status
    #define D0F3_RSPRID			0xFFFF	//0/0/x/x PME Requester ID
#define D0F3_DEV_CAPS_2		0x64	//Device Capabilities 2
    #define D0F3_RSV_64_6			0xFFF00000	//0/R/x/x Reserved
    #define D0F3_ROBFFSP			(BIT18 + BIT19)	//0/0/x/x OBFF Supported
    #define D0F3_RSV_64_12			0x3F000	//0/R/x/x Reserved
    #define D0F3_RLTRSP			BIT11	//0/0/x/x LTR Mechanism Supported
    #define D0F3_RSV_64_10			0x7C0	//0/x/x/x Reserved
    #define D0F3_RARISP			BIT5	//0/0/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define D0F3_TBD_31			BIT4	//1b/1/x/x Completion Timeout Disable Supported
    #define D0F3_TBD_32			0xF	//0/0/x/x Completion Timeout Ranges Supported
#define D0F3_DEV_CTL_2		0x68	//Device Control 2
    #define D0F3_RSV_46			BIT15	//0/R/x/x Reserved
    #define D0F3_ROBFFEN			(BIT13 + BIT14)	//0/0/x/x OBFF Enable
    #define D0F3_RSV_68_11			(BIT11 + BIT12)	//0/R/x/x Reserved
    #define D0F3_RLTREN			BIT10	//0/0/x/x LTR Mechanism Enable
    #define D0F3_RSV_68_6			0x3C0	//0/R/x/x Reserved
    #define D0F3_RARIEN			BIT5	//0/0/x/x Enable ARI Forwarding
    #define D0F3_RDISCPLTM			BIT4	//0/0/0/x Completion Timeout Disable Control
    #define D0F3_TBD_33			0xF	//0/0/x/x Completion Timeout Value
#define D0F3_DEV_STA_2		0x6A	//Device Status 2
    #define D0F3_RSV_47			0xFFFF	//0/R/x/x Reserved
#define D0F3_LINK_CAPS_2		0x6C	//Link Capabilities 2
    #define D0F3_RSV_6C_31			0xFFF80000	//0/R/x/x Reserved
    #define D0F3_RLOW_SKP_REC_SUPPORT_2			BIT18	//0/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F3_RLOW_SKP_REC_SUPPORT_1			BIT17	//0/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F3_RLOW_SKP_REC_SUPPORT_0			BIT16	//1b/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F3_RSV_6C_15			0xF000	//0/R/x/x Reserved
    #define D0F3_RLOW_SKP_GEN_SUPPORT_2			BIT11	//0/x/x/x Lower SKP OS Generation Supported Speeds Vector
    #define D0F3_RLOW_SKP_GEN_SUPPORT_1			BIT10	//0/x/x/X Lower SKP OS Generation Supported Speeds Vector
    #define D0F3_RLOW_SKP_GEN_SUPPORT_0			BIT9	//1b/x/x/X Lower SKP OS Generation Supported Speeds Vector
    #define D0F3_RSV_6C_8			BIT8	//0/0/x/x CrossLink Supported
    #define D0F3_LKMLS_6			BIT7	//0/0/x/x Supported Link Speed Vector Bit 6
    #define D0F3_LKMLS_5			BIT6	//0/0/x/x Supported Link Speed Vector Bit 5
    #define D0F3_LKMLS_4			BIT5	//0/0/x/x Supported Link Speed Vector Bit 4
    #define D0F3_LKMLS_3			BIT4	//0/0/x/x Supported Link Speed Vector Bit 3
    #define D0F3_LKMLS_2			BIT3	//0/0/x/x Supported Link Speed Vector Bit 2, 8.0GT/s
    #define D0F3_LKMLS_1			BIT2	//0/0b/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define D0F3_LKMLS_0			BIT1	//1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s
    #define D0F3_RSV_6C_0			BIT0	//0/R/x/x Reserved
#define D0F3_LINK_CTL_2		0x70	//Link Control 2
    #define D0F3_CMPPSDEEMPHS			0xF000	//0/0/x/x Compliance Preset / De-emphasis
    #define D0F3_RCMPSOS			BIT11	//0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define D0F3_PMDCMPSET			BIT10	//0/0/x/x Modified Compliance Pattern Set Bit
    #define D0F3_TXMGN_2			BIT9	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F3_TXMGN_1			BIT8	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F3_TXMGN_0			BIT7	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F3_SELDEEMPHS			BIT6	//0/0/x/x Selectable De-emphasis
    #define D0F3_RHATNMSD			BIT5	//0/0/x/0 Disable Hardware Autonomous Speed
    #define D0F3_PCMPSET			BIT4	//0/0/x/x Enter Compliance
    #define D0F3_LKTGLS_3			BIT3	//0/0/0/0 Target Link Speed Bit 3
    #define D0F3_LKTGLS_2			BIT2	//0/0/0/0 Target Link Speed Bit 2
    #define D0F3_LKTGLS_1			BIT1	//0/0/0/0 Target Link Speed Bit 1
    #define D0F3_LKTGLS_0			BIT0	//0/0/0/0 Target Link Speed Bit 0
#define D0F3_LINK_STA_2		0x72	//Link Status 2
    #define D0F3_RSV_49			0xFFC0	//0/R/x/x Reserved
    #define D0F3_EQREQ			BIT5	//0/x/x/x Request the Link Equalization Process
    #define D0F3_EQCOMPLE3			BIT4	//0/x/x/x Transmitter Equalization Procedure Completed - Phase 3
    #define D0F3_EQCOMPLE2			BIT3	//0/x/x/x Transmitter Equalization Procedure Completed - Phase 2
    #define D0F3_EQCOMPLE1			BIT2	//0/x/x/x Transmitter Equalization Procedure Completed - Phase 1
    #define D0F3_EQCOMPLE			BIT1	//0/x/x/x Transmitter Equalization Procedure Completed
    #define D0F3_CURDEEMPHS			BIT0	//0/x/x/x Current Link De-emphasis Level
#define D0F3_ELEMENT_SELF_DESCRIPTION		0x78	//Element Self Description
    #define D0F3_D0F3_RX7A_15_0			0xFFFF0000	//0/0/x/x Reserved
    #define D0F3_RPORTNUM_D0F3_7_0			0xFF00	//0Bh/0Bh/x/x Port Number 
    #define D0F3_RX78_7_0			0xFF	//00h/00h/x/x Reserved
#define D0F3_LCU_INITIAL_DATA_PATTERN		0xFC	//LCU Initial Data Pattern
    #define D0F3_RLCUBSTLENGTH_31_0			0xFFFFFFFF	//8h/x/x/x The Burst Length of LCU Write & Read Request
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z1		0x100	//LCU Initial Data Pattern
    #define D0F3_B7L_INIT_7_0			0xFF	//13h/x/x/x The LCU First QW Initial Data Pattern of Bit 7
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z2		0x101	//LCU Initial Data Pattern
    #define D0F3_B6L_INIT_7_0			0xFF	//11h/x/x/x The LCU First QW Initial Data Pattern of Bit 6
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z3		0x102	//LCU Initial Data Pattern
    #define D0F3_B5L_INIT_7_0			0xFF	//0Dh/x/x/x The LCU First QW Initial Data Pattern of Bit 5
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z4		0x103	//LCU Initial Data Pattern
    #define D0F3_B4L_INIT_7_0			0xFF	//0Bh/x/x/x The LCU First QW Initial Data Pattern of Bit 4
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z5		0x104	//LCU Initial Data Pattern
    #define D0F3_B3L_INIT_7_0			0xFF	//07h/x/x/x The LCU First QW Initial Data Pattern of Bit 3
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z6		0x105	//LCU Initial Data Pattern
    #define D0F3_B2L_INIT_7_0			0xFF	//05h/x/x/x The LCU First QW Initial Data Pattern of Bit 2
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z7		0x106	//LCU Initial Data Pattern
    #define D0F3_B1L_INIT_7_0			0xFF	//03h/x/x/x The LCU First QW Initial Data Pattern of Bit 1
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z8		0x107	//LCU Initial Data Pattern
    #define D0F3_B0L_INIT_7_0			0xFF	//02h/x/x/x The LCU First QW Initial Data Pattern of Bit 0
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z9		0x108	//LCU Initial Data Pattern
    #define D0F3_B7H_INIT_7_0			0xFF	//03h/x/x/x The LCU Second QW Initial Data Pattern of Bit 7
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z10		0x109	//LCU Initial Data Pattern
    #define D0F3_B6H_INIT_7_0			0xFF	//04h/x/x/x The LCU Second QW Initial Data Pattern of Bit 6
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z11		0x10A	//LCU Initial Data Pattern
    #define D0F3_B5H_INIT_7_0			0xFF	//06h/x/x/x The LCU Second QW Initial Data Pattern of Bit 5
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z12		0x10B	//LCU Initial Data Pattern
    #define D0F3_B4H_INIT_7_0			0xFF	//08h/x/x/x The LCU Second QW Initial Data Pattern of Bit 4
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z13		0x10C	//LCU initial data pattern
    #define D0F3_B3H_INIT_7_0			0xFF	//0Ch/x/x/x The LCU Second QW Initial Data Pattern of Bit 3
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z14		0x10D	//LCU initial data pattern
    #define D0F3_B2H_INIT_7_0			0xFF	//0Eh/x/x/x The LCU Second QW Initial Data Pattern of Bit 2
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z15		0x10E	//LCU Initial Data Pattern
    #define D0F3_B1H_INIT_7_0			0xFF	//12h/x/x/x The LCU Second QW Initial Data Pattern of Bit 1
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z16		0x10F	//LCU Initial Data Pattern
    #define D0F3_B0H_INIT_7_0			0xFF	//14h/x/x/x The LCU Second QW Initial Data Pattern of Bit 0
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z17		0x110	//LCU Initial Data Pattern
    #define D0F3_B7L2_INIT_7_0			0xFF	//14h/x/x/x The LCU Third QW Initial Data Pattern of Bit 7
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z18		0x111	//LCU Initial Data Pattern
    #define D0F3_B6L2_INIT_7_0			0xFF	//12h/x/x/x The LCU Third QW Initial Data Pattern of Bit 6
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z19		0x112	//LCU Initial Data Pattern
    #define D0F3_B5L2_INIT_7_0			0xFF	//0Eh/x/x/x The LCU Third QW Initial Data Pattern of Bit 5
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z20		0x113	//LCU Initial Data Pattern
    #define D0F3_B4L2_INIT_7_0			0xFF	//0Ch/x/x/x The LCU Third QW Initial Data Pattern of Bit 4
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z21		0x114	//LCU Initial Data Pattern
    #define D0F3_B3L2_INIT_7_0			0xFF	//08h/x/x/x The LCU Third QW Initial Data Pattern of Bit 3
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z22		0x115	//LCU Initial Data Pattern
    #define D0F3_B2L2_INIT_7_0			0xFF	//06h/x/x/x The LCU Third QW Initial Data Pattern of Bit 2
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z23		0x116	//LCU Initial Data Pattern
    #define D0F3_B1L2_INIT_7_0			0xFF	//04h/x/x/x The LCU Third QW Initial Data Pattern of Bit 1
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z24		0x117	//LCU Initial Data Pattern
    #define D0F3_B0L2_INIT_7_0			0xFF	//03h/x/x/x The LCU Third QW Initial Data Pattern of Bit 0
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z25		0x118	//LCU Initial Data Pattern
    #define D0F3_B7H2_INIT_7_0			0xFF	//02h/x/x/x The LCU Forth QW Initial Data Pattern of Bit 7
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z26		0x119	//LCU Initial Data Pattern
    #define D0F3_B6H2_INIT_7_0			0xFF	//03h/x/x/x The LCU Forth QW Initial Data Pattern of Bit 6
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z27		0x11A	//LCU Initial Data Pattern
    #define D0F3_B5H2_INIT_7_0			0xFF	//05h/x/x/x The LCU Forth QW Initial Data Pattern of Bit 5
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z28		0x11B	//LCU Initial Data Pattern
    #define D0F3_B4H2_INIT_7_0			0xFF	//07h/x/x/x The LCU Forth QW Initial Data Pattern of Bit 4
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z29		0x11C	//LCU Initial Data Pattern
    #define D0F3_B3H2_INIT_7_0			0xFF	//0Bh/x/x/x The LCU Forth QW Initial Data Pattern of Bit 3
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z30		0x11D	//LCU Initial Data Pattern
    #define D0F3_B2H2_INIT_7_0			0xFF	//0Dh/x/x/x The LCU Forth QW Initial Data Pattern of Bit 2
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z31		0x11E	//LCU Initial Data Pattern
    #define D0F3_B1H2_INIT_7_0			0xFF	//11h/x/x/x The LCU Forth QW Initial Data Pattern of Bit 1
#define D0F3_LCU_INITIAL_DATA_PATTERN_Z32		0x11F	//LCU Initial Data Pattern
    #define D0F3_B0H2_INIT_7_0			0xFF	//13h/x/x/x The LCU Forth QW Initial Data Pattern of Bit 0
#define D0F3_DRAM_RANK0_BEGINNING_ADR_37_26		0x120	//DRAM Rank0 Beginning Address (37:26)
    #define D0F3_D0F3_RX121_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR0BEG_37_26			0xFFF	//0/0/x/x Virtual Rank 0 Beginning Address
#define D0F3_DRAM_RANK1_BEGINNING_ADR_37_26		0x122	//DRAM Rank1 Beginning Address (37:26)
    #define D0F3_D0F3_RX123B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR1BEG_37_26			0xFFF	//0/0/x/x Virtual Rank 1 Beginning Address
#define D0F3_DRAM_RANK2_BEGINNING_ADR_37_26		0x124	//DRAM Rank2 Beginning Address (37:26)
    #define D0F3_D0F3_RX125B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR2BEG_37_26			0xFFF	//0/0/x/x Virtual Rank 2 Beginning Address
#define D0F3_DRAM_RANK3_BEGINNING_ADR_37_26		0x126	//DRAM Rank3 Beginning Address (37:26)
    #define D0F3_D0F3_RX127B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR3BEG_37_26			0xFFF	//0/0/x/x Virtual Rank 3 Beginning Address
#define D0F3_DRAM_RANK4_BEGINNING_ADR_37_26		0x128	//DRAM Rank4 Beginning Address (37:26)
    #define D0F3_D0F3_RX129B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR4BEG_37_26			0xFFF	//0/0/x/x Virtual Rank 4 Beginning Address
#define D0F3_DRAM_RANK5_BEGINNING_ADR_37_26		0x12A	//DRAM Rank5 Beginning Address (37:26)
    #define D0F3_D0F3_RX12BB_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR5BEG_37_26			0xFFF	//0/0/x/x Virtual Rank 5 Beginning Address
#define D0F3_DRAM_RANK6_BEGINNING_ADR_37_26		0x12C	//DRAM Rank6 Beginning Address (37:26)
    #define D0F3_D0F3_RX12DB_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR6BEG_37_26			0xFFF	//0/0/x/x Virtual Rank 6 Beginning Address
#define D0F3_DRAM_RANK7_BEGINNING_ADR_37_26		0x12E	//DRAM Rank7 Beginning Address (37:26)
    #define D0F3_D0F3_RX12FB_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR7BEG_37_26			0xFFF	//0/0/x/x Virtual Rank 7 Beginning Address
#define D0F3_DRAM_RANK0_ENDING_ADR_37_26		0x130	//DRAM Rank0 Ending Address (37:26)
    #define D0F3_D0F3_RX131B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR0END_37_26			0xFFF	//0/0/x/x Virtual Rank 0 Ending Address
#define D0F3_DRAM_RANK1_ENDING_ADR_37_26		0x132	//DRAM Rank1 Ending Address (37:26)
    #define D0F3_D0F3_RX133B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR1END_37_26			0xFFF	//0/0/x/x Virtual Rank 1 Ending Address
#define D0F3_DRAM_RANK2_ENDING_ADR_37_26		0x134	//DRAM Rank2 Ending Address (37:26)
    #define D0F3_D0F3_RX135B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR2END_37_26			0xFFF	//0/0/x/x Virtual Rank 2 Ending Address
#define D0F3_DRAM_RANK3_ENDING_ADR_37_26		0x136	//DRAM Rank3 Ending Address (37:26)
    #define D0F3_D0F3_RX137B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR3END_37_26			0xFFF	//0/0/x/x Virtual Rank 3 Ending Address
#define D0F3_DRAM_RANK4_ENDING_ADR_37_26		0x138	//DRAM Rank4 Ending Address (37:26)
    #define D0F3_D0F3_RX139B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR4END_37_26			0xFFF	//0/0/x/x Virtual Rank 4 Ending Address
#define D0F3_DRAM_RANK5_ENDING_ADR_37_26		0x13A	//DRAM Rank5 Ending Address (37:26)
    #define D0F3_D0F3_RX13BB_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR5END_37_26			0xFFF	//0/0/x/x Virtual Rank 5 Ending Address
#define D0F3_DRAM_RANK6_ENDING_ADR_37_26		0x13C	//DRAM Rank6 Ending Address (37:26)
    #define D0F3_D0F3_RX13DB_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR6END_37_26			0xFFF	//0/0/x/x Virtual Rank 6 Ending Address
#define D0F3_DRAM_RANK7_ENDING_ADR_37_26		0x13E	//DRAM Rank7 Ending Address (37:26)
    #define D0F3_D0F3_RX0FB_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDVR7END_37_26			0xFFF	//0/0/x/x Virtual Rank 7 Ending Address
#define D0F3_PHYSICAL_TO_VIRTUAL_RANK_MAPPING		0x148	//Physical-to-Virtual Rank Mapping
    #define D0F3_RDPR3EN			BIT15	//0/*/x/x Enable Physical Rank 3
    #define D0F3_RDPR3VR_2_0			(BIT12 + BIT13 + BIT14)	//011b/*/x/x Virtual Rank Number of Physical Rank 3
    #define D0F3_RDPR2EN			BIT11	//0/*/x/x Enable Physical Rank 2
    #define D0F3_RDPR2VR_2_0			(BIT8 + BIT9 + BIT10)	//010b/*/x/x Virtual Rank Number of Physical Rank 2
    #define D0F3_RDPR1EN			BIT7	//0/*/x/x Enable Physical Rank 1
    #define D0F3_RDPR1VR_2_0			(BIT4 + BIT5 + BIT6)	//001b/*/x/x Virtual Rank Number of Physical Rank 1
    #define D0F3_RDPR0EN			BIT3	//0/*/x/x Enable Physical Rank 0
    #define D0F3_RDPR0VR_2_0			(BIT0 + BIT1 + BIT2)	//000b/*/x/x Virtual Rank Number of Physical Rank 0
#define D0F3_PHYSICAL_TO_VIRTUAL_RANK_MAPPING_Z1		0x14A	//Physical-to-Virtual Rank Mapping
    #define D0F3_RDPR7EN			BIT15	//0/*/x/x Enable Physical Rank 7
    #define D0F3_RDPR7VR_2_0			(BIT12 + BIT13 + BIT14)	//011b/*/x/x Virtual Rank Number of Physical Rank 7
    #define D0F3_RDPR6EN			BIT11	//0/*/x/x Enable Physical Rank 6
    #define D0F3_RDPR6VR_2_0			(BIT8 + BIT9 + BIT10)	//010b/*/x/x Virtual Rank Number of Physical Rank 6
    #define D0F3_RDPR5EN			BIT7	//0/*/x/x Enable Physical Rank 5
    #define D0F3_RDPR5VR_2_0			(BIT4 + BIT5 + BIT6)	//001b/*/x/x Virtual Rank Number of Physical Rank 5
    #define D0F3_RDPR4EN			BIT3	//0/*/x/x Enable Physical Rank 4
    #define D0F3_RDPR4VR_2_0			(BIT0 + BIT1 + BIT2)	//000b/*/x/x Virtual Rank Number of Physical Rank 4
#define D0F3_DRAM_MA_MAP_TYPE		0x14C	//DRAM MA Map Type
    #define D0F3_RSINGLECH			BIT15	//0/x/x/x Dual Channel/Single Channel Decode
    #define D0F3_R2C4RINLVEN			BIT14	//0/0/x/x 2C4R Channel/Rank Enable
    #define D0F3_R2C2RINLVEN			BIT13	//0/x/x/x 2C2R Channel/Rank Enable
    #define D0F3_R2C1RINLVEN			BIT12	//0/0/x/x 2C1R Channel/Rank Enable
    #define D0F3_R1C4RINLVEN			BIT11	//0/0/x/x 1C4R Channel/Rank Enable
    #define D0F3_R1C2RINLVEN			BIT10	//0/0/x/x 1C2R Channel/Rank Enable
    #define D0F3_RBG0DEC			BIT9	//0/x/x/x Bank Group Bit 0 Decode Select
    #define D0F3_RCMD1T			BIT8	//0/x/x/x 1T Command/MA Rate
    #define D0F3_D0F3_RX14D_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RANK_INTERLEAVE_ADR_SEL_BANK_SCRAMBLE		0x14E	//Rank Interleave Address Select / Bank Scramble
    #define D0F3_D0F3_RX14F_15_8			0xFF00	//0/x/x/x Reserved
    #define D0F3_RGMIDDR4EN			BIT7	//1b/1/1/1 GMINT Support DDR4 Enable 
    #define D0F3_RBKSCMB			BIT6	//0/0/x/x Reserved
    #define D0F3_RBKEN_1_0			(BIT4 + BIT5)	//11b/11b/11b/11b Page Number Supported for the Rank
    #define D0F3_D0F3_RX14F_3_0			0xF	//0/x/x/x Reserved
#define D0F3_BANK_INTERLEAVE		0x150	//Bank Interleave
    #define D0F3_D0F3_RX151B_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_RBA1SEL_2_0			(BIT4 + BIT5 + BIT6)	//001b/*/x/x Reserved
    #define D0F3_D0F3_RX151B3			BIT3	//0/0/x/x Reserved
    #define D0F3_RBA0SEL_2_0			(BIT0 + BIT1 + BIT2)	//001b/*/x/x Reserved
#define D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL		0x152	//CPU Direct Access Frame Buffer Control
    #define D0F3_RFBBS_35_21			0xFFFE	//0/*/*/* GFX DVAD Base Address
    #define D0F3_RDFBAEN			BIT0	//0/*/x/x Reserved [EY: Reserved or not?]
#define D0F3_CPU_DIRECT_ACCESS_FRAME_BUFFER_CTL_Z1		0x154	//CPU Direct Access Frame Buffer Control
    #define D0F3_D0F3_RX155_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_RGMITADBYPASS			BIT8	//1b/x/1/x GMINT DVAD Decode Bypass Enable
    #define D0F3_RGFXEN			BIT7	//1b/*/*/* Internal Graphic Controller Enabling
    #define D0F3_RFBSZ_2_0			(BIT4 + BIT5 + BIT6)	//000b/*/*/* Frame Buffer Size Selection
//@self defined macro begin
#define D0F3_RFBSZ_64M	  0x10
#define D0F3_RFBSZ_128M   0x20
#define D0F3_RFBSZ_256M   0x30
#define D0F3_RFBSZ_512M   0x40
//@self defined macro end

    #define D0F3_RFBBS_39_36			0xF	//0/*/*/* GFX DVAD Base Address
#define D0F3_DRAM_ENDING_ADR		0x156	//DRAM Ending Address
    #define D0F3_D0F3_RX157_15_14			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_REND7_37_24			0x3FFF	//HwInit/x/x/x The Address Next to the Last Valid DRAM Address
#define D0F3_SMM_AND_APIC_DECODING		0x158	//SMM and APIC Decoding
    #define D0F3_D0F3_RX159_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_D0F3_RX159_7_6			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F3_RAPICARB			BIT5	//1b/1/*/* APIC Lowest Interrupt Arbitration
    #define D0F3_D0F3_RX159_4_0			0x1F	//0/0/x/x Reserved
#define D0F3_DMA_PROTECTION_CTL		0x15A	//DMA Protection Control
    #define D0F3_D0F3_RX15B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_DPR_SIZE_7_0			0xFF0	//0/*/x/x This is the Size of DPR Region in MB
    #define D0F3_D0F3_RX15BB3			BIT3	//0/0/x/x Reserved
    #define D0F3_DPR_EN			BIT2	//0/*/x/x DPR Enable
    #define D0F3_DPR_STS			BIT1	//0/0/x/x Reserved
    #define D0F3_DPR_LOCK			BIT0	//0/0/x/x Lock Bit to Lock DMA Protection Control
#define D0F3_RDCLKOAPM_RDCLKOBPM		0x15C	//RDCLKOAPM& RDCLKOBPM
    #define D0F3_D0F3_RX15D_15_0			0xFFFF	//0/0/x/x Reserved
#define D0F3_DRAM_ARBITRATION_BANDWIDTH_TIMER_II_I		0x15E	//DRAM Arbitration Bandwidth Timer II/I
    #define D0F3_VDHTIM_3_0			0xF000	//0/0/x/x Reserved
    #define D0F3_VDTIM_3_0			0xF00	//0100b/0100b/x/x DRAM Arbitration Bandwidth Timer - II 
    #define D0F3_HTIM_3_0			0xF0	//1001b/1001b/1001b/x Host Bandwidth Timer
    #define D0F3_GTIM_3_0			0xF	//1101b/1101b/1101b/x PEG Bandwidth Timer
#define D0F3_DRAM_ARBITRATION_PARKING_PRIORITY_PROMOTION_TIMER_BANDWIDTH_TIMER_III		0x160	//DRAM Arbitration Parking/Priority Promotion Timer & Bandwidth Timer III
    #define D0F3_D0F3_RX161B15			BIT15	//0/0/x/x Reserved
    #define D0F3_RDARB_2_0			(BIT12 + BIT13 + BIT14)	//0/0/0/x Arbitration Parking Policy
    #define D0F3_PTIM_3_0			0xF00	//0/0/1101b/x Priority Promotion Timer
    #define D0F3_VHTIM_3_0			0xF0	//0100b/0100b/x/x GFX High Priority Bandwidth Timer
    #define D0F3_VTIM_3_0			0xF	//0100b/0100b/x/x GFX Bandwidth Timer
#define D0F3_DRAM_BUS_TOGGLE_REDUCTION_CTL_BY_DIMM_TEMPERATURE_SENSOR		0x162	//DRAM Bus Toggle Reduction Control by DIMM Temperature Sensor
    #define D0F3_D0F3_RX163B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RTEMPNUM2_6_0			0x7F00	//0/0/*/* Reduce DRAM Bus Request Rate
    #define D0F3_RTEMPCNTEN			BIT7	//0/0/*/* Reduce DRAM Bus Request when Temperature Is High
    #define D0F3_RTEMPNUM_6_0			0x7F	//0/0/*/* Reduce DRAM Bus Request Rate
#define D0F3_DRAM_ADR_OFFSET_AND_HIGH_PRIORY_REQ_MASK		0x164	//DRAM Address Offset and High Priory Request Mask
    #define D0F3_RVPRIVADS			BIT15	//0/0/x/x GFX High Priority Arbitration When There Is Request
    #define D0F3_RMASKCPUH			BIT14	//0/0/x/x CPU High Priority Request Mask
    #define D0F3_RMASKAGPH			BIT13	//0/0/x/x PXP High Priority Request Mask
    #define D0F3_RMASKVDEH			BIT12	//0/0/x/x FSBC High Priority Request Mask
    #define D0F3_D0F3_RX165_11_10			(BIT10 + BIT11)	//0/0/x/x Reserved
    #define D0F3_RDMQUESIZE_1_0			(BIT8 + BIT9)	//0/0/x/x DMQUE size select
    #define D0F3_D0F3_RX165_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_DRAMC_REQ_REORDER_CTL_I_DRAM_REQ_CTL		0x166	//DRAMC Request Reorder Control I &DRAM Request Control
    #define D0F3_RAUTO_PRE_REQ			BIT15	//0/0/0/x Auto-Precharge Enable when in DMREQ Request Are All Page Conflict of the Scheduled Bank
    #define D0F3_RINORDER			BIT14	//0/0/1/x DMQUE Command in Order
    #define D0F3_RBYPASS1TEN			BIT13	//0/0/x/x Bypass Reorder Queue Pipe 1T or Not
    #define D0F3_RNOMG8QW			BIT12	//1b/1/1/x DRAMC 8QW Write Request Distant Merge
    #define D0F3_RWMERGEEN			BIT11	//0/0/1/x DRAMC Write Request Merge Enable
    #define D0F3_RDISVMERGE			BIT10	//1b/1/x/x GFX Cycle Meger for Write Cycle Enable
    #define D0F3_RWTAGPIPE			BIT9	//0/0/*/x One More Pipe When Generating Read Pointer for Write Data FIFO in DRAMC
    #define D0F3_RDRAMCBPSOEN			BIT8	//0/0/0/0 Write Data FIFO Power Control
    #define D0F3_D0F3_RX167B7			BIT7	//0/0/x/x Reserved
    #define D0F3_RBYPASSRDQEN			BIT6	//0/0/1/1 Reorder Queue Bypass Enable
    #define D0F3_RCHLVCTL_1_0			(BIT4 + BIT5)	//0/0/x/x Internal Graphic Channel Control
    #define D0F3_RFLOATDIMCLK			BIT3	//1b/1/x/0 Float DIMM Clock when All Rank Enter Self Refresh
    #define D0F3_REF_STP1			BIT2	//0/0/x/x Disable Auto Refresh Counter When in Self-refresh Mode
    #define D0F3_RNEWCHDEC			BIT1	//1b/1/1/1 Channel Decode Select
    #define D0F3_RINREQ_BLOCK			BIT0	//0/0/x/x Block DRAM Exit Self-refresh When Enter S3
#define D0F3_DRAMC_REQ_REORDER_CTL_III_II		0x168	//DRAMC Request Reorder Control III/II
    #define D0F3_RAGELIMIT_3_0			0xF000	//4h/4h/*/x The Maximum Number of a Read Request Being Bypassed in Reordered Request Queue ((DMREQ))
    #define D0F3_RWFLUSHEND_3_0			0xF00	//2h/2h/*/x Left Request in Write Request Queue
    #define D0F3_RBYPASS_CNT			0xF0	//0/0/0/x Request Max Bypass Read Reorder Queue Count
    #define D0F3_RNO_BYPASS_CNT			0xF	//0/0/0/x Normal Request Flush Count When Bypass Request Pending
#define D0F3_DRAMC_WRITE_MERGE_CTL_II_I		0x16A	//DRAMC Write Merge Control II/I
    #define D0F3_RWMEXPNB_3_0			0xF000	//8h/8h/*/x The End Point of Write Request Waiting for Merge
    #define D0F3_RWMTIM_3_0			0xF00	//8h/8h/*/x The Stop Point of Write Request Waiting for Merge <RWMTIM>
    #define D0F3_D0F3_RX16B_7_6			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F3_RWREXPTIM_5_0			0x3F	//36h/36h/36h/x Reordered Request Queue ((DMREQ)) Write Queue Serve Max Number When Write Not Hit
#define D0F3_DRAM_PIPELINE_TURN_AROUND_SETTING		0x16C	//DRAM Pipeline Turn-Around Setting
    #define D0F3_D0F3_RX16DB7			BIT15	//0/0/x/x Reserved
    #define D0F3_RFW2W_2_0			(BIT12 + BIT13 + BIT14)	//0/0/x/x Back-to-Back Write to Different Ranks 
    #define D0F3_D0F3_RX16DB3			BIT11	//0/0/x/x Reserved
    #define D0F3_RFR2R_2_0			(BIT8 + BIT9 + BIT10)	//0/0/x/x Fast Read-to-Read Turn Around for Different Ranks
    #define D0F3_D0F3_RX16CB7			BIT7	//0/0/x/x Reserved
    #define D0F3_RFR2W_2_0			(BIT4 + BIT5 + BIT6)	//010b/x/x/x Fast Read-to-Write Turn Around
    #define D0F3_D0F3_RX16CB3			BIT3	//0/0/x/x Reserved
    #define D0F3_RFW2R_2_0			(BIT0 + BIT1 + BIT2)	//001b/1/x/x Fast Write-to-Read Turn Around
#define D0F3_DRAMC_PAGE_CTL_DRAMC_PAGE_ALL_CTL		0x16E	//DRAMC Page Control &DRAMC Page ALL Control
    #define D0F3_RPGTIM_3_0			0xF000	//0/0/0/0 Expiration Time for the Page Register Life Timer
    #define D0F3_RPGEN			BIT11	//1b/1b/1/x Multiple Page Mode
    #define D0F3_RNONPGMEN			BIT10	//0/0/0/1 Support Dynamic Page Mode - Non Page Mode Change
    #define D0F3_D0F3_RX16F_9_7			(BIT7 + BIT8 + BIT9)	//0/0/x/x Reserved
    #define D0F3_RPGSCLSAL_6_0			0x7F	//0000000b/0000000b/0000100b/x DRAM Expired Page Threshold
#define D0F3_DRAM_BUS_TOGGLE_REDUCTION_CTL_BY_DDR_IO_TEMPERATURE_SENSOR		0x170	//DRAM Bus Toggle Reduction Control by DDR IO Temperature Sensor
    #define D0F3_RTHERMALEN			BIT7	//0/0/*/* Reduce DRAM Bus Request when Temperature Is High
    #define D0F3_RTHERMALNUM_6_0			0x7F	//0/0/*/* Reduce DRAM Bus Request Rate
#define D0F3_MERGE_RELATED_CTL		0x171	//Merge Related Control
    #define D0F3_D0F3_RX171B_7_4			0xF0	//0/0/x/x Reserved
    #define D0F3_RMWCTL3			BIT3	//0/0/x/x Memory Write Merge Function Related Register
    #define D0F3_RMWCTL_2_1			(BIT1 + BIT2)	//0/0/x/x Reserved
    #define D0F3_RMWCTL0			BIT0	//0/0/1/1 New Read Modify Write Feature Open When RMWCTL0=1
#define D0F3_PAD_CTL_DRAM_DATA_BURST_CTL		0x172	//Pad Control &DRAM Data Burst Control
    #define D0F3_RDPR7EN_FLOAT			BIT15	//1b/1/x/* Control Float CS/CKE when Physic Rank 7 Is Disabled
    #define D0F3_RDPR6EN_FLOAT			BIT14	//1b/1/x/* Control Float CS/CKE when Physic Rank 6 Is Disabled
    #define D0F3_RDPR5EN_FLOAT			BIT13	//1b/1/x/* Control Float CS/CKE when Physic Rank 5 Is Disabled
    #define D0F3_RDPR4EN_FLOAT			BIT12	//1b/1/x/* Control Float CS/CKE when Physic Rank 4 Is Disabled
    #define D0F3_RDPR3EN_FLOAT			BIT11	//1b/1/x/* Control Float CS/CKE when Physic Rank 3 Is Disabled
    #define D0F3_RDPR2EN_FLOAT			BIT10	//1b/1/x/* Control Float CS/CKE when Physic Rank 2 Is Disabled
    #define D0F3_RDPR1EN_FLOAT			BIT9	//1b/1/x/* Control Float CS/CKE when Physic Rank 1 Is Disabled
    #define D0F3_RDPR0EN_FLOAT			BIT8	//1b/1/x/* Control Float CS/CKE when Physic Rank 0 Is Disabled
    #define D0F3_D0F3_RX173B7			BIT7	//0/0/x/x Reserved
    #define D0F3_RDMBL8			BIT6	//1b/1b/1b/1b SDRAM Effective Burst Length
    #define D0F3_RDMBCOTF			BIT5	//0/0/0/0 DDR4 Burst Chop On-The-Fly
    #define D0F3_RDMWROD			BIT4	//1b/1b/1b/1b Write Burst Reordering
    #define D0F3_RDSIENEXT_1_0			(BIT2 + BIT3)	//11b/11b/11b/11b Extend Internal Signals for RX Capture Range (DQS Input Enable) for Channel A
    #define D0F3_RDSIENEXT_CHB_1_0			(BIT0 + BIT1)	//11b/11b/11b/11b Extend Internal Signals for RX Capture Range (DQS Input Enable) for Channel B
#define D0F3_READ_WRITE_DATA_PHASE_CTL		0x174	//Read/Write Data Phase Control
    #define D0F3_D0F3_RX175_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RDRPH_CHB_2_0			(BIT5 + BIT6 + BIT7)	//0/0/*/x MD Input Data Push Timing Control -- CHB
    #define D0F3_RDWADV_1_0			(BIT3 + BIT4)	//0/0/*/x Early DQ/DQS Output for Write Cycles
    #define D0F3_RDRPH_2_0			(BIT0 + BIT1 + BIT2)	//0/0/*/x MD Input Data Push Timing Control -- CHA
#define D0F3_BY_RANK_SELF_REFRESH_RELATED_REGS_II_I		0x176	//By-Rank Self Refresh Related Registers II/I
    #define D0F3_RREFGFX_RK3			BIT15	//0/0/1/0 Check Vertical Blank of GFX for Rank3 to Do By-Rank Self Refresh
    #define D0F3_RREFPMU_RK3			BIT14	//0/0/1/0 Check C3/C4 State and DRAM idle status of PMU for Rank 3 to Do By-Rank Self Refresh
    #define D0F3_RREFGFX_RK2			BIT13	//0/0/1/0 Check Vertical Blank of GFX for Rank2 to Do By-Rank Self Refresh
    #define D0F3_RREFPMU_RK2			BIT12	//0/0/1/0 Check C3/C4 State and DRAM idle status of PMU for Rank2 to Do By-Rank Self Refresh
    #define D0F3_RREFGFX_RK1			BIT11	//0/0/1/0 Check Vertical Blank of GFX for Rank1 to Do By-Rank Self Refresh
    #define D0F3_RREFPMU_RK1			BIT10	//0/0/1/0 Check C3/C4 State and DRAM idle status of PMU for Rank1 to Do By-Rank Self Refresh
    #define D0F3_RREFGFX_RK0			BIT9	//0/0/1/0 Check Vertical Blank of GFX for Rank0 to Do By-Rank Self Refresh
    #define D0F3_RREFPMU_RK0			BIT8	//0/0/1/0 Check C3/C4 State and DRAM idle status of PMU for Rank0 to Do By-Rank Self Refresh
    #define D0F3_RSFREFRK7EN			BIT7	//0/0/0/1* By-Rank Self Refresh for Rank 7
    #define D0F3_RSFREFRK6EN			BIT6	//0/0/0/1* By-Rank Self Refresh for Rank 6
    #define D0F3_RSFREFRK5EN			BIT5	//0/0/0/1* By-Rank Self Refresh for Rank 5
    #define D0F3_RSFREFRK4EN			BIT4	//0/0/0/1* By-Rank Self Refresh for Rank 4
    #define D0F3_RSFREFRK3EN			BIT3	//0/0/0/1* By-Rank Self Refresh for Rank 3
    #define D0F3_RSFREFRK2EN			BIT2	//0/0/0/1* By-Rank Self Refresh for Rank 2
    #define D0F3_RSFREFRK1EN			BIT1	//0/0/0/1* By-Rank Self Refresh for Rank 1
    #define D0F3_RSFREFRK0EN			BIT0	//0/0/0/1* By-Rank Self Refresh for Rank 0
#define D0F3_PM_DURING_SELF_REFRESH_BY_RANK_SELF_REFRESH_RELATED_REGS_III		0x178	//Power Management during Self-Refresh &By-Rank Self Refresh Related Registers III
    #define D0F3_RRASA7TNOSRFPM			BIT15	//0/0/1/1 Behavior Control for MCS3# of Channel B
    #define D0F3_RRASA6TNOSRFPM			BIT14	//0/0/1/1 Behavior Control for MCS2# of Channel B
    #define D0F3_RRASA5TNOSRFPM			BIT13	//0/0/1/1 Behavior Control for MCS1# of Channel B
    #define D0F3_RRASA4TNOSRFPM			BIT12	//0/0/1/1 Behavior Control for MCS0# of Channel B
    #define D0F3_RRASA3TNOSRFPM			BIT11	//0/0/1/1 Behavior Control for MCS3# of Channel A
    #define D0F3_RRASA2TNOSRFPM			BIT10	//0/0/1/1 Behavior Control for MCS2# of Channel A
    #define D0F3_RRASA1TNOSRFPM			BIT9	//0/0/1/1 Behavior Control for MCS1# of Channel A
    #define D0F3_RRASA0TNOSRFPM			BIT8	//0/0/1/1 Behavior Control for MCS0# of Channel A
    #define D0F3_RPAIRREFOUT			BIT7	//1b/1/x/x MODT Constraint for Exiting By-Rank Self Refresh 
    #define D0F3_RPAIRREF			BIT6	//1b/1/x/x MODT Constraint for Entering and Exiting By-Rank Self Refresh 
    #define D0F3_RENTERREF_2_0			(BIT3 + BIT4 + BIT5)	//010b/010b/x/x The Number of Auto-Refresh while Rank Is Idle to Trigger Self Refresh
    #define D0F3_D0F3_RX179_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x Reserved
#define D0F3_REFRESH_CTL_PM_DURING_SELF_REFRESH		0x17A	//Refresh Control &Power Management during Self-Refresh
    #define D0F3_RPRPRI			BIT15	//1b/1/1/x High Priority Refresh Request
    #define D0F3_REFBST			BIT14	//0/0/x/x Burst Refresh
    #define D0F3_REFCOMPACT0			BIT13	//1b/1/1/1 Compact Refresh Mode
    #define D0F3_RPRVPRI			BIT12	//0/0/x/x Enable GMINT Promote High Priority Request
    #define D0F3_REFBST8			BIT11	//0/0/x/x Burst Refresh Improve; Reserved
    #define D0F3_D0F3_RX17B_10_8			(BIT8 + BIT9 + BIT10)	//0/0/x/x Reserved
    #define D0F3_DISCKE_RK7			BIT7	//HwInit/x/x/x Rank7 Enter By-Rank Self Refresh
    #define D0F3_DISCKE_RK6			BIT6	//HwInit/x/x/x Rank6 Enter By-Rank Self Refresh
    #define D0F3_DISCKE_RK5			BIT5	//HwInit/x/x/x Rank5 Enter By-Rank Self Refresh
    #define D0F3_DISCKE_RK4			BIT4	//HwInit/x/x/x Rank4 Enter By-rank Self Refresh
    #define D0F3_DISCKE_RK3			BIT3	//HwInit/x/x/x Rank3 Enter By-Rank Self Refresh
    #define D0F3_DISCKE_RK2			BIT2	//HwInit/x/x/x Rank2 Enter By-Rank Self Refresh
    #define D0F3_DISCKE_RK1			BIT1	//HwInit/x/x/x Rank1 Enter By-Rank Self Refresh
    #define D0F3_DISCKE_RK0			BIT0	//HwInit/x/x/x Rank0 Enter By-Rank Self Refresh
#define D0F3_BY_RANK_AUTO_REFRESH_CTL_BY_RANK_SELF_REFRESH_RELATED_REGS_II		0x17C	//By-Rank Auto Refresh Control &By-Rank Self Refresh Related Registers II
    #define D0F3_D0F3_RX17DB_15_8			0xFF00	//0/0/0/x Reserved
    #define D0F3_RREFGFX_RK7			BIT7	//0/0/1/0 Check Vertical Blank of GFX for Rank7 to Do By-Rank Self Refresh
    #define D0F3_RREFPMU_RK7			BIT6	//0/0/1/0 Check C3/C4 State of PMU for Rank7 to Do By-Rank Self Refresh
    #define D0F3_RREFGFX_RK6			BIT5	//0/0/1/0 Check Vertical Blank of GFX for Rank6 to Do By-Rank Self Refresh
    #define D0F3_RREFPMU_RK6			BIT4	//0/0/1/0 Check C3/C4 State of PMU for Rank6 to Do By-Rank Self Refresh
    #define D0F3_RREFGFX_RK5			BIT3	//0/0/1/0 Check Vertical Blank of GFX for Rank5 to Do By-Rank Self Refresh
    #define D0F3_RREFPMU_RK5			BIT2	//0/0/1/0 Check C3/C4 State of PMU for Rank5 to Do By-Rank Self Refresh
    #define D0F3_RREFGFX_RK4			BIT1	//0/0/1/0 Check Vertical Blank of GFX for Rank4 to Do By-Rank Self Refresh
    #define D0F3_RREFPMU_RK4			BIT0	//0/0/1/0 Check C3/C4 State of PMU for Rank4 to Do By-Rank Self Refresh
#define D0F3_DRAM_TIMING_FOR_ALL_RANKS_I_II		0x180	//DRAM Timing for All Ranks I/II
    #define D0F3_RWRCOV_3_0			0xF0000000	//0/0/x/x Write Recovery Time (tWR)These bits defined the minimum latency from a a Write command to Precharge.
    #define D0F3_RTRTP_3_0			0xF000000	//0/0/x/x Read to Pre-charge Delay (tRTP)
    #define D0F3_D0F3_RX182B7			BIT23	//0/0/x/x RESERVED
    #define D0F3_RTRP_4_0			0x7C0000	//0/0/x/x Pre-charge Period (tRP)These bits defined the minimum latency from a Pre-charge command to an Active command.
    #define D0F3_RTRCD_4_0			0x3E000	//0/0/x/x Active to Read/Write Delay (tRCD)These bits defined the minimum latency from an Active command to a Read/Write command.
    #define D0F3_RCL_4_0			0x1F00	//0/0/x/x CAS Latency
    #define D0F3_RTCKE_2_0			(BIT5 + BIT6 + BIT7)	//0/0/x/x CKE Assertion Minimum Pulse Width
    #define D0F3_RCWL_4_0			0x1F	//0/0/x/x CAS Latency for Write Cycle
#define D0F3_DRAM_TIMING_FOR_ALL_RANKS_III		0x184	//DRAM Timing for All Ranks III
    #define D0F3_RTFAWX_3_0			0xF000	//0/0/x/x Bias of Four Activate Window (tFAW)
    #define D0F3_D0F3_RX32B11			BIT11	//0/0/x/x Reserved
    #define D0F3_RTRRD_2_0			(BIT8 + BIT9 + BIT10)	//0/0/x/x Active-to-Active Period (tRRD)
    #define D0F3_RTRAS_6_0			0xFE	//0/0/x/x Active to Pre-charge ( tRAS )
    #define D0F3_D0F3_RX184B0			BIT0	//0/0/x/x Reserved
#define D0F3_DRAM_TIMING_FOR_ALL_RANKS_IV_V		0x186	//DRAM Timing for All Ranks IV/V
    #define D0F3_D0F3_RX187B15			BIT15	//0/0/*/* Reserved
    #define D0F3_RTRFC_6_0			0x7F00	//0/0/x/x Refresh-to-Active or Refresh-to-Refresh (tRFC)
    #define D0F3_RT8BKEN			BIT7	//1b/1/1/1 8-Bank Device Timing Constraint
    #define D0F3_D0F3_RX187B6			BIT6	//0/0/x/x Reserved
    #define D0F3_RTRPA_2_0			(BIT3 + BIT4 + BIT5)	//0/0/x/x Pre-charge All Period (Especially for 8-bank Devices)
    #define D0F3_RTWTR_2_0			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Write to Read Command Delay (tWTR)
#define D0F3_REFRESH_CNTER_DRAM_TIMING_FOR_ALL_RANKS_IX		0x188	//Refresh Counter &DRAM Timing for All Ranks -IX
    #define D0F3_REFC_7_0			0xFF00	//0/0/x/x Refresh Counter
    #define D0F3_RTXSR_1_0			(BIT6 + BIT7)	//01b/x/x/x Minimum Latency from the Exiting of Self Refresh to Any Command
    #define D0F3_RTXSREXT_5_0			0x3F	//0/0/x/x Add TXSR Margin after 512T Has Been Satisfied.
#define D0F3_DRAM_TIMING_FOR_ALL_RANKS_X		0x18A	//DRAM Timing for All Ranks - X
    #define D0F3_RZQCSEN			BIT15	//1b/1/x/x Short ZQ Calibration
    #define D0F3_RTXPD_2_0			(BIT12 + BIT13 + BIT14)	//0/0/x/x Minimum Latency from Power Down Exit to Any Command 
    #define D0F3_RZQCSNUM_11_0			0xFFF	//0/0/*/* ZQCS Period
#define D0F3_DDR4_TIMING_FOR_ALL_RANKS_II_I		0x18C	//DDR4 Timing for All Ranks II/I
    #define D0F3_RTWTR_SG_3_0			0xF000	//0/0/x/x Write to Read Command Delay for the Same Bank Group(tWTR_L-tWTR_S)When working with DDR4, these bits defined the latency from an CAS command to a CAS command that access the same bank group. 
    #define D0F3_D0F3_RX18CB_11			BIT11	//0/0/x/x Reserved
    #define D0F3_RCAL_2_0			(BIT8 + BIT9 + BIT10)	//0/0/x/x CS to Command/Address LatencyWhen work with DDR4, DRAM controller can issue real command and address after CS assert, these bits decide the latency.
    #define D0F3_D0F3_RX18CB7			BIT7	//0/0/x/x RCCDL8T
    #define D0F3_D0F3_RX18CB6			BIT6	//0/0/x/x RCCDL6T
    #define D0F3_RTRRD_SG_2_0			(BIT3 + BIT4 + BIT5)	//0/0/x/x Active to Active command Delay for the Same Bank Group(tRRD_L-tRRD_S)
    #define D0F3_RTCCD_SG_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x Read/Write to Read/Write Delay for the Same Bank Group(tCCD_L-tCCD_S)When working with DDR4, these bits defined the latency from an CAS command to a CAS command that access the same bank group. The latency tCCD_L= tCCD_S + RTCCD_SG
#define D0F3_RETRY_MIRROR_SETTING_DDR4_SPECIAL_REFRESH_CMD_TIMING		0x18E	//Retry Mirror Setting & DDR4 Special Refresh Command Timing
    #define D0F3_D0F3_RX18F_15_10			0xFC00	//0/0/x/x Reserved
    #define D0F3_RRPRE_ODT			BIT9	//0/0/x/x DDR4 ODT Control
    #define D0F3_RRETRYMIR			BIT8	//0/0/x/x Mirror MA for RK1 When Retry
    #define D0F3_D0F3_RX18FB_7_4			0xF0	//0/0/0/0 Reserved
    #define D0F3_RDIFFBG_DELY_CAL_CHA_1_0			(BIT2 + BIT3)	//0/0/x/x Addition Delay for Diff Bankgroup(1XCLK) for Calibration
    #define D0F3_RDIFFBG_DELY_CAL_CHB_1_0			(BIT0 + BIT1)	//0/0/x/x Addition Delay for Diff Bankgroup(1XCLK) for Calibration
#define D0F3_DRAM_ODT_LOOKUP_TABLE_FOR_CHN_B_A		0x190	//DRAM ODT Lookup Table for Channel B&A
    #define D0F3_RDPR7ODT_1_0			(BIT14 + BIT15)	//0/0/*/* MODT Signal Active Selections When Accessing Rank 7
    #define D0F3_RDPR6ODT_1_0			(BIT12 + BIT13)	//0/0/*/* MODT Signal Active Selections When Accessing Rank 6
    #define D0F3_RDPR5ODT_1_0			(BIT10 + BIT11)	//0/0/*/* MODT Signal Active Selections When Accessing Rank 5
    #define D0F3_RDPR4ODT_1_0			(BIT8 + BIT9)	//0/0/*/* MODT Signal Active Selections When Accessing Rank 4
    #define D0F3_RDPR3ODT_1_0			(BIT6 + BIT7)	//0/0/*/* MODT Signal Active Selections When Accessing Rank 3
    #define D0F3_RDPR2ODT_1_0			(BIT4 + BIT5)	//0/0/*/* MODT Signal Active Selections When Accessing Rank 2
    #define D0F3_RDPR1ODT_1_0			(BIT2 + BIT3)	//0/0/*/* MODT Signal Active Selections When Accessing Rank 1
    #define D0F3_RDPR0ODT_1_0			(BIT0 + BIT1)	//0/0/*/* MODT Signal Active Selections When Accessing Rank 0
#define D0F3_DRAM_ODT_AND_MISCELLANEOUS_CONTROL		0x192	//DDR4 DRAM ODT and Miscellaneous Control
    #define D0F3_RODT2TDELAYW			BIT15	//0/x/x/x Delay of MODT Assertion for Write Cycles
    #define D0F3_RODT2TEXTNW			BIT14	//0/x/x/x Extension of MODT Assertion for Write Cycles
    #define D0F3_RODT2TDELAYR			BIT13	//0/x/x/x Delay of MODT Assertion for Read Cycles
    #define D0F3_RODT2TEXTNR			BIT12	//0/x/x/x Extension of MODT Assertion for Read Cycles
    #define D0F3_RDQSDFB			BIT11	//1b/1/x/x Differential DQS Input for Channel B; Reserved
    #define D0F3_RDQSDFA			BIT10	//1b/1/x/x Differential DQS Input for Channel A; Reserved
    #define D0F3_RPREODT_1_0			(BIT8 + BIT9)	//01b/x/x/x Head Extension of MODT Assertion for Read/Write Cycles
    #define D0F3_RODTEN			BIT7	//1b/1/1/1 MODT Main Control
    #define D0F3_RLEADINGOE2T			BIT6	//1b/1/x/x LEADINGOE 1T Early
    #define D0F3_RLEADINGOE05T			BIT5	//0/0/x/x LEADINGOE 0.5T Delay
    #define D0F3_RODTTAR_2_0			(BIT2 + BIT3 + BIT4)	//001b/x/*/* Extra MD Bus Turn Around Cycles for MODT Assertion
    #define D0F3_RDMWLPR_1_0			(BIT0 + BIT1)	//0/x/*/* DRAM Ranks for Returning DQ0 When in Write Leveling Mode
#define D0F3_DRAM_TYPE_DRAM_INIT_CTL		0x194	//DRAM Type & DRAM Initialization Control
    #define D0F3_RDDR3EN			BIT15	//0b/0b/x/x DDR Type Support Bit 1
    #define D0F3_RDDR4EN			BIT14	//1b/1b/x/x DDR Type Support Bit 
    #define D0F3_MEMTYPE			BIT13	//HwInit/x/x/x DRAM Type
    #define D0F3_RDM32BSEL			BIT12	//0/0/x/x Calibration Bit Select Under 32B Mode; Reserved
    #define D0F3_RSCRMBLEN			BIT11	//0/0/*/* Data Scrambling Control
    #define D0F3_RDMAMIR			BIT10	//0/x/*/* MA SWAP for MRS Programming
    #define D0F3_RDYNCKE_BYRANK			BIT9	//0/0/x/x BYRANK DYNCKE Enable
    #define D0F3_RMEMRSTN_CHB			BIT8	//0/x/*/* DDR4 Memory Reset for Channel B
    #define D0F3_RDQSIADJ			BIT7	//0/x/x/x DLL Adjustment for DQS Input
    #define D0F3_RDQSOADJ			BIT6	//0/x/x/x DLL Adjustment for DQS Output
    #define D0F3_RMEMRSTN			BIT5	//0/x/*/* DDR4 Memory Reset
    #define D0F3_RDLLRSTN			BIT4	//1b/x/*/* DLL Manual Reset
    #define D0F3_RDMSZDET			BIT3	//0/0/0/0 Enable Memory Size Detection, A32/A16 Swap
    #define D0F3_RSDM_2_0			(BIT0 + BIT1 + BIT2)	//000b/x/*/* Operation Mode for Software DDR Initialization
//@self defined macro begin
#define D0F3_RSDM_NORMAL	0
#define D0F3_RSDM_NOP	1
#define D0F3_RSDM_PREA	2
#define D0F3_RSDM_MRS	3
#define D0F3_RSDM_CBR	4
#define D0F3_RSDM_ZQCL	6
//@self defined macro end
#define D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_II_I		0x196	//DRAM Mode Register Sets (MRS) Hardware Based Programming for Initialization II/I
    #define D0F3_RDMINIT_STATUS_CHB			BIT15	//HwInit/x/x/x Hardware Contolled Initialization Status Bit for Channel B
    #define D0F3_RDMINIT_CHB			BIT14	//0/*/*/* DRAM MRS Hardware Programming Trigger for Channel B
    #define D0F3_RDMRRTTWR_2_0			(BIT11 + BIT12 + BIT13)	//0/x/*/* Dynamic ODT Bits for MRS Hardware Programming
//@self defined macro begin
#define D0F3_WR_RTT_DIS 	0
#define D0F3_WR_RTT_120OHM	BIT11 
#define D0F3_WR_RTT_240OHM	BIT12
#define D0F3_WR_RTT_HIZ 	BIT11|BIT12 
#define D0F3_WR_RTT_80OHM	BIT13
//@self defined macro end
    #define D0F3_RHRDLLRST			BIT10	//0/x/*/* DLL Reset for Low Frequency Working Mode 
    #define D0F3_RDMRSRT			BIT9	//0/x/*/* Refresh Rate Bit for MRS Hardware Programming
    #define D0F3_RDMRASR			BIT8	//0/x/*/* Auto Self Refresh Bit for MRS Hardware Programming
    #define D0F3_RDMINIT_BYRANK			BIT7	//0/x/*/* By-rank Hardware Initialization Control
    #define D0F3_RDMRRTT_2_0			(BIT4 + BIT5 + BIT6)	//0/x/*/* ODT Strength Bits for MRS Hardware Programming.
//@self defined macro begin
#define D0F3_NOM_RTT_DIS	 0
#define D0F3_NOM_RTT_60OHM	 BIT4
#define D0F3_NOM_RTT_120OHM  BIT5 
#define D0F3_NOM_RTT_40OHM	 BIT4|BIT5 
#define D0F3_NOM_RTT_240OHM  BIT6 
#define D0F3_NOM_RTT_48OHM	 BIT6|BIT4 
#define D0F3_NOM_RTT_80OHM	 BIT6|BIT5
#define D0F3_NOM_RTT_34OHM	 BIT6|BIT5|BIT4 
//@self defined macro end
    #define D0F3_RDMRODS_1_0			(BIT2 + BIT3)	//0/x/*/* Output Drive Strength Bits for MRS Hardware Programming
    #define D0F3_RDMINIT_STATUS			BIT1	//HwInit/x/x/x Hardware Contolled Initialization Status Bit for Channel A
    #define D0F3_RDMINIT			BIT0	//0/0/*/* DRAM MRS Hardware Programming Trigger for Channel A
#define D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_IV_III		0x198	//DRAM Mode Register Sets (MRS) Hardware-Based Programming for Initialization IV/III
    #define D0F3_RTCREN			BIT15	//0/0/*/* Temperature Controlled Refresh Mode for MRS Hardware Programming
    #define D0F3_RTCRRANGE			BIT14	//0/0/*/* Temperature Controlled Refresh Range for MRS Hardware Programming
    #define D0F3_RRDBIEN			BIT13	//0/0/x/x Data Bus Inversion (DBI) - Read DBI Enable
    #define D0F3_RWDBIEN			BIT12	//0/0/0/* Data Bus Inversion (DBI) - Write DBI Enable
    #define D0F3_RCAPARPEN			BIT11	//0/0/*/* CA Parity Persistent Error Mode
    #define D0F3_RPARK_RTT_2_0			(BIT8 + BIT9 + BIT10)	//0/0/*/* Parked ODT Value (RTT_Park)
//@self defined macro begin
#define D0F3_PARK_RTT_DIS	  0
#define D0F3_PARK_RTT_60OHM   BIT8
#define D0F3_PARK_RTT_120OHM  BIT9 
#define D0F3_PARK_RTT_40OHM   BIT8|BIT9 
#define D0F3_PARK_RTT_240OHM  BIT10 
#define D0F3_PARK_RTT_48OHM   BIT10|BIT8 
#define D0F3_PARK_RTT_80OHM   BIT10|BIT9
#define D0F3_PARK_RTT_34OHM   BIT10|BIT9|BIT8 
//@self defined macro end
    #define D0F3_RCRCEN			BIT7	//0/0/*/* RESERVED
    #define D0F3_RMPRRD_FORMAT			BIT6	//0/0/*/* Multipurpose register(MPR) - Read format for MRS Hardware Programming
    #define D0F3_RWCL_1_0			(BIT4 + BIT5)	//0/0/x/x Write CMD latency when CRC/DM enable for MRS Hardware Programming
    #define D0F3_RTSSEN			BIT3	//0/0/0/* Temperature sensor status for MRS Hardware Programming
    #define D0F3_RWPRE			BIT2	//0/0/*/* Write Preamble for MRS Hardware Programming
    #define D0F3_RRPRE			BIT1	//0/0/*/* Read Preamble for for MRS Hardware Programming
    #define D0F3_RINVREF_MON			BIT0	//0/0/*/* Internal Vref Monitor for MRS Hardware Programming
#define D0F3_DRAM_MODE_REG_SETS_MRS_HW_BASED_PROGRAMMING_FOR_INIT_V		0x19A	//DRAM Mode Register Sets (MRS) Hardware-Based Programming for Initialization V
    #define D0F3_D0F3_RX198B_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RODTBUFEN			BIT7	//0/0/*/* ODT Input Buffer for Power-down for MRS Hardware Programming
    #define D0F3_RCAPL_2_0			(BIT4 + BIT5 + BIT6)	//0/0/*/* CA Parity Latency Mode for MRS Hardware Programming
    #define D0F3_RPDAEN			BIT3	//0/0/x/x Reserved
    #define D0F3_RNODQMEN			BIT2	//1b/1/1/1 No DQM Mode
    #define D0F3_RRDFIFOEN			BIT1	//0/0/x/x CPU Read Data FIFO Enable
    #define D0F3_RDM3DS			BIT0	//0/0/x/x Reserved
#define D0F3_RESERVED_Z4		0x19C	//Reserved
    #define D0F3_D0F3_RX19D_15_0			0xFFFF	//0/0/x/x Reserved
#define D0F3_DRAM_RETRY_CTL_II_I		0x19E	//DRAM Retry Control II/I
    #define D0F3_RTPAR_ALERT_ON_4_0			0xF800	//0/0/x/x Reserved
    #define D0F3_RDYRETRYPM			BIT10	//0/x/x/x Reserved
    #define D0F3_RRETRY_NOBLOCK			BIT9	//0/x/x/x Reserved
    #define D0F3_D0F3_RX19FB8			BIT8	//0/0/x/x Reserved
    #define D0F3_RRETRYEN_CHA			BIT7	//0/0/x/x Reserved
    #define D0F3_RRETRYEN_CHB			BIT6	//0/0/x/x Reserved
    #define D0F3_RTCRC_ON_5_0			0x3F	//0/x/x/x Reserved
#define D0F3_RETRY_ERR_ENABLE_CTL		0x1A0	//Retry Error Enable Control
    #define D0F3_RCRC_RPEN			BIT15	//0/0/x/x Reserved
    #define D0F3_RCAP_RPEN			BIT14	//0/0/x/x Reserved
    #define D0F3_RMCASBECC_EN			BIT13	//0/0/x/x MCA Report Single Bit Error Enable
    #define D0F3_RMCAMBECC_EN			BIT12	//0/0/x/x MCA Report Multi Bit Error Enable
    #define D0F3_RDRAMC_SMI_SEFS			BIT11	//0/0/x/x Single Bit ECC Report SMI Enable
    #define D0F3_RDRAMC_SMI_MEFS			BIT10	//0/0/x/x Multi Bit ECC Report SMI Enable
    #define D0F3_RDRAMC_SMI_CRC			BIT9	//0/0/x/x Reserved
    #define D0F3_RDRAMC_SMI_PAR			BIT8	//0/0/x/x Reserved
    #define D0F3_RDRAMC_NMI_SEFS			BIT7	//0/0/x/x Single Bit ECC Report NMI Enable
    #define D0F3_RDRAMC_NMI_MEFS			BIT6	//0/0/x/x Multi Bit ECC Report NMI Enable
    #define D0F3_RDRAMC_NMI_CRC			BIT5	//0/0/x/x Reserved
    #define D0F3_RDRAMC_NMI_PAR			BIT4	//0/0/x/x Reserved
    #define D0F3_RDRAMC_SCI_SEFS			BIT3	//0/0/x/x Single Bit ECC Report SCI Enable
    #define D0F3_RDRAMC_SCI_MEFS			BIT2	//0/0/x/x Multi Bit ECC Report SCI Enable
    #define D0F3_RDRAMC_SCI_CRC			BIT1	//0/0/x/x Reserved
    #define D0F3_RDRAMC_SCI_PAR			BIT0	//0/0/x/x Reserved
#define D0F3_RETRY_ERR_ENABLE_CTL_Z1		0x1A2	//Retry Error Enable Control
    #define D0F3_RERRSTATRK_CHA_1_0			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_RERRSEL_CHA			BIT13	//0/x/x/x Reserved
    #define D0F3_D0F3_RX1A38_12_4			0x1FF0	//0/0/x/x Reserved
    #define D0F3_RCACPE_EN			BIT3	//0/0/x/x Reserved
    #define D0F3_RCACRCE_EN			BIT2	//0/0/x/x Reserved
    #define D0F3_RCAPERF_EN			BIT1	//0/0/x/x Reserved
    #define D0F3_RCACRCRF_EN			BIT0	//0/0/x/x Reserved
#define D0F3_CHN_A_B_RETRY_ERR_LOG		0x1A4	//Channel A/B Retry Error Log
    #define D0F3_D0F3_RX1A5_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RERRCLR_CRC			BIT13	//0/0/x/x Reserved
    #define D0F3_RERRCLR_PAR			BIT12	//0/0/x/x Reserved
    #define D0F3_RERRSTAT_CHA_I_9_2			0xFF0	//0/x/x/x Reserved
    #define D0F3_RERRSTS_PAR_CHB			BIT3	//0/x/x/x Reserved
    #define D0F3_RERRSTS_CRC_CHB			BIT2	//0/x/x/x Reserved
    #define D0F3_RERRSTS_PAR_CHA			BIT1	//0/x/x/x Reserved
    #define D0F3_RERRSTS_CRC_CHA			BIT0	//0/x/x/x Reserved
#define D0F3_CHN_A_B_RETRY_ERR_LOG_Z1		0x1A6	//Channel A/B Retry Error Log
    #define D0F3_RERRSTATRK_CHB_1_0			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_RERRSEL_CHB			BIT13	//0/0/x/x Reserved
    #define D0F3_D0F3_RX1A7_12_8			0x1F00	//0/0/x/x Reserved
    #define D0F3_RERRSTAT_CHB_I_9_2			0xFF	//0/x/x/x Reserved
#define D0F3_MAX_PWR_SAVING_DOWN_CTL		0x1A8	//Max Power Saving Down Control
    #define D0F3_D0F3_RX1A9_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RMPSMOD_EN_CHA			BIT7	//0/0/x/x Reserved
    #define D0F3_RMPSMOD_EX_CHA			BIT6	//0/0/x/x Reserved
    #define D0F3_RMPSMOD_EN_CHB			BIT5	//0/0/x/x Reserved
    #define D0F3_RMPSMOD_EX_CHB			BIT4	//0/0/x/x Reserved
    #define D0F3_D0F3_RX1A9_3_0			0xF	//0/0/x/x Reserved
#define D0F3_DDR4_DEV_CTL		0x1AA	//DDR4 Device Control
    #define D0F3_D0F3_RX1AB_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RDMX16_A			BIT7	//0/0/x/x DDR4 X16 Device for Channel A
    #define D0F3_RDMX8_A			BIT6	//1b/1/x/x DDR4 X8 Device for Channel A
    #define D0F3_RDMX4_A			BIT5	//0/0/x/x Reserved
    #define D0F3_RCKE_MAN_CHB			BIT4	//0/0/x/x CKE Control Mode Selection
    #define D0F3_RDMX16_B			BIT3	//0/0/x/x DDR4 X16 Device for Channel B
    #define D0F3_RDMX8_B			BIT2	//1b/1/x/x DDR4 X8 Device for Channel B
    #define D0F3_RDMX4_B			BIT1	//0/0/x/x Reserved
    #define D0F3_RCKE_MAN			BIT0	//0/0/x/x CKE Control Mode Selection
#define D0F3_CHN_A_RETRY_ERR_LOG		0x1AC	//Channel A Retry Error Log
    #define D0F3_D0F3_RX1ACB_31_0			0xFFFFFFFF	//0/x/x/X Reserved
#define D0F3_CHN_B_RETRY_ERR_LOG		0x1B0	//Channel B Retry Error Log
    #define D0F3_D0F3_RX1B0B_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define D0F3_SW_CKE_CTL		0x1B4	//Software CKE Control
    #define D0F3_D0F3_RX1B5_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RCKE7_VAL			BIT7	//0/0/x/x When RCKE_MAN = 1, CKE7 Is Controlled by This Register Value Programmed by Software
    #define D0F3_RCKE6_VAL			BIT6	//0/0/x/x When RCKE_MAN = 1, CKE6 Is Controlled by This Register Value Programmed by Software
    #define D0F3_RCKE5_VAL			BIT5	//0/0/x/x When RCKE_MAN = 1, CKE5 Is Controlled by This Register Value Programmed by Software
    #define D0F3_RCKE4_VAL			BIT4	//0/0/x/x When RCKE_MAN = 1, CKE4 Is Controlled by This Register Value Programmed by Software
    #define D0F3_RCKE3_VAL			BIT3	//0/0/x/x When RCKE_MAN = 1, CKE3 Is Controlled by This Register Value Programmed by Software
    #define D0F3_RCKE2_VAL			BIT2	//0/0/x/x When RCKE_MAN = 1, CKE2 Is Controlled by This Register Value Programmed By Software
    #define D0F3_RCKE1_VAL			BIT1	//0/0/x/x When RCKE_MAN = 1, CKE1 Is Controlled by This Register Value Programmed by Software
    #define D0F3_RCKE0_VAL			BIT0	//0/0/x/x When RCKE_MAN = 1, CKE0 Is Controlled by This Register Value Programmed by Software
#define D0F3_ECC_CTL_1_ECC_ERR_STA		0x1B6	//ECC Control 1& ECC Error Status
    #define D0F3_RSUE			BIT15	//0/0/x/x Multi Bit Error Report Enable
    #define D0F3_RSCE			BIT14	//0/0/x/x Single Bit Error Report Enable
    #define D0F3_RECCEN			BIT13	//0/0/x/x ECC Enable
    #define D0F3_RFBECCEN			BIT12	//0/0/x/x GFX SL ECC Enable
    #define D0F3_RERREN			BIT11	//0/0/x/x Reserved
    #define D0F3_RERRADDREN			BIT10	//0/0/x/x Reserved
    #define D0F3_D0F3_RX1B7B9			BIT9	//0/0/x/x Select Byte8 Pattern of Write Engine
    #define D0F3_RSCUEN			BIT8	//0/0/x/x Reserved
    #define D0F3_RSUE_STATUS			BIT7	//0/0/x/x Multi Bit Error Status Enable
    #define D0F3_RSCE_STATUS			BIT6	//0/0/x/x Single Bit Error Status Enable
    #define D0F3_RTQWSTBDEN			BIT5	//0/0/x/x Reserved
    #define D0F3_RSCURED			BIT4	//0/0/x/x Reserved
    #define D0F3_RMEFS_CHB			BIT3	//0/0/x/x Multi Bit Data Error Status - CHB
    #define D0F3_RSEFS_CHB			BIT2	//0/0/x/x Single Bit Data Error Status - CHB
    #define D0F3_RMEFS_CHA			BIT1	//0/0/x/x Multi Bit Data Error Status - CHA
    #define D0F3_RSEFS_CHA			BIT0	//0/0/x/x Single Bit Data Error Status - CHA
#define D0F3_ECC_ERR_REPORT_PATTERN		0x1B8	//ECC ERROR Report Pattern
    #define D0F3_SYNDRM_CHA_7_0			0xFF00	//HwInit/x/x/x ECC ERROR Syndrome Bit - CHA
    #define D0F3_SYNDRM_CHB_7_0			0xFF	//HwInit/x/x/x ECC ERROR Syndrome Bit - CHB
#define D0F3_ECC_CTL_2		0x1BA	//ECC Control 2
    #define D0F3_RERRADDR_35_20			0xFFFF	//0/0/x/x Reserved
#define D0F3_ECC_CTL_2_Z1		0x1BC	//ECC Control 2
    #define D0F3_RERRADDR_19_4			0xFFFF	//0/0/x/x Reserved
#define D0F3_ECC_CTL_3		0x1BE	//ECC Control 3
    #define D0F3_D0F3_RX1BF_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RERR2B			BIT7	//0/0/x/x Reserved
    #define D0F3_RERRB_6_0			0x7F	//0/0/x/x Reserved
#define D0F3_ECC_ERR_SYNDROME_MULIT_BIT		0x1C0	//ECC ERROR Syndrome Mulit Bit
    #define D0F3_RMSMDRM_CHA_7_0			0xFF00	//HwInit/x/x/x ECC ERROR Syndrome Mulit Bit - Channel A
    #define D0F3_RMSMDRM_CHB_7_0			0xFF	//HwInit/x/x/x ECC ERROR Syndrome Mulit Bit - Channel B
#define D0F3_MASTERCTL_ECC_BYTE_SEL		0x1C2	//MasterControl ECC Byte Select
    #define D0F3_RDN_RT_3_0			0xF000	//0/0/x/x Reserved
    #define D0F3_RUP_RT_3_0			0xF00	//0/0/x/x Reserved
    #define D0F3_RECC_BYTE_SEL			BIT7	//0/0/x/x Master Control ECC Byte Select
    #define D0F3_RFQDNEN			BIT6	//0/0/x/x Reserved
    #define D0F3_D0F3_RX1C3B5			BIT5	//0/0/x/x Reserved
    #define D0F3_RTIM_NUM_4_0			0x1F	//0/0/x/x Reserved
#define D0F3_PDA_CTL_CHA_CHB		0x1C4	//PDA Control CHA/CHB
    #define D0F3_RPDA_B_7_0			0xFF00	//0/0/x/x PDA Mode DQ Control for CHA Byte[7:0]
    #define D0F3_RPDA_A_7_0			0xFF	//0/0/x/x PDA Mode DQ Control for CHB Byte[7:0]
#define D0F3_PDA_MODE_CTL_ECC		0x1C6	//PDA Mode Control&ECC
    #define D0F3_RDIMM_STAB_7_0			0xFF00	//0/0/x/x RDIMM Stabilization Time, the Input Clock Must Be Stable for a Time before Any Access to the Device Takes Place (1X CLK)
    #define D0F3_RDISRMW			BIT7	//0/0/x/x Disable Read Modify Write
    #define D0F3_D0F3_RX1C7_6_3			0x78	//0/0/0/0 Reserved
    #define D0F3_RECCERINJ			BIT2	//0/0/x/x ECC ERROR Injection with Partial Write 
    #define D0F3_RPDA_B8			BIT1	//0/0/x/x PDA Mode DQ Control for CHA Byte8
    #define D0F3_RPDA_A8			BIT0	//0/0/x/x PDA Mode DQ Control for CHA Byte8
#define D0F3_MD_MDQS_INPUT_TIMING_CTL_READ_LEVELING_RETURNED_DATA_MODE		0x1C8	//MD/MDQS Input Timing Control &Read Leveling Returned Data Mode
    #define D0F3_RDMRLEN			BIT15	//0/0/x/x Read Leveling Enable
    #define D0F3_D0F3_RX1C9B14			BIT14	//0/0/x/x Reserved
    #define D0F3_RSCNDSIT			BIT13	//0/x/x/x Reserved
    #define D0F3_RSETDSIT			BIT12	//0b/0/x/x Reserved
    #define D0F3_D0F3_RX1C9B11			BIT11	//0/0/x/x Reserved
    #define D0F3_RDLLDSIDLY			BIT10	//0/0/x/x Reserved
    #define D0F3_RSCNDSIDLY			BIT9	//0/x/x/x Reserved
    #define D0F3_D0F3_RX1C9B8			BIT8	//0/0/x/x Reserved
    #define D0F3_RDRLDQPAT			BIT7	//1b/1/x/x Reserved
    #define D0F3_RNEWRDLEVEL			BIT6	//0/0/x/x Reserved
    #define D0F3_D0F3_RX1C9_5_0			0x3F	//0/x/x/x Reserved
#define D0F3_MDQS_OUTPUT_CTL_MD_MDQS_OUTPUT_TIMING_CTL		0x1CA	//MDQS Output Control &MD/MDQS Output Timing Control
    #define D0F3_D0F3_RX1CB_15_13			(BIT13 + BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_RDSOPRE			BIT12	//0/x/*/* Reserved
    #define D0F3_RDSOLNGPREEN			BIT11	//0/x/*/* Reserved
    #define D0F3_RDQOLNGPRE			BIT10	//0/x/*/* Reserved
    #define D0F3_RDSOLNGPRE_1_0			(BIT8 + BIT9)	//0/x/*/* MDQS Earlier Output Enable Selections
    #define D0F3_D0F3_RX1CBB7			BIT7	//0/0/x/x Reserved
    #define D0F3_RSCNTXCLKS			BIT6	//0/x/x/x Reserved
    #define D0F3_D0F3_RX1CB_5_4			(BIT4 + BIT5)	//0/0/x/x Reserved
    #define D0F3_RDMWLEN			BIT3	//0/x/x/x Reserved
    #define D0F3_RSCNTXCLKD			BIT2	//0/x/x/x Reserved
    #define D0F3_RSETTXCLK_DCLKS			BIT1	//0b/0/x/x Reserved
    #define D0F3_RSETTXCLK_DCLKD			BIT0	//0b/0/x/x Reserved
#define D0F3_WRITE_LEVELING_ERR_LOG_GRP_DLL_CTL		0x1CC	//Write Leveling Error Log &GRP_DLL Control
    #define D0F3_D0F3_RX1CF_15_13			(BIT13 + BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_RDRAMCKEN			BIT12	//0/0/1/1 DRAMC Channel Dynamic Clock Enable
    #define D0F3_WLVL_FOUND_B8			BIT11	//HwInit/x/x/x Status of CalibrationUsing Write Leveling for Channel B
    #define D0F3_WLVL_FOUND_A8			BIT10	//HwInit/x/x/x Status of CalibrationUsing Write Leveling for  Channel A
    #define D0F3_WLVL_ERR_B8			BIT9	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A8			BIT8	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_D0F3_RX1CDB_7_4			0xF0	//0/0/x/x Reserved
    #define D0F3_RTSNUM_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x Reserved
    #define D0F3_RTSRSTEN			BIT0	//0/0/x/x Reserved
#define D0F3_WLVL_STA		0x1D8	//WLVL Status
    #define D0F3_WLVL_ERR_B7			BIT15	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_B6			BIT14	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_B5			BIT13	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_B4			BIT12	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_B3			BIT11	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_B2			BIT10	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_B1			BIT9	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_B0			BIT8	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A7			BIT7	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A6			BIT6	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A5			BIT5	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A4			BIT4	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A3			BIT3	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A2			BIT2	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A1			BIT1	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
    #define D0F3_WLVL_ERR_A0			BIT0	//HwInit/x/x/x ERROR Status of Calibration Using Write Leveling
#define D0F3_DRAMC_SUBMODULE_DYNAMIC_CLK_CTL		0x1DA	//DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB15			BIT15	//0/0/1/1 DRAMC Dynamic Clock Control
    #define D0F3_D0F3_RX1DB14			BIT14	//0/0/1/1 DRAMC Dynamic Clock Control
    #define D0F3_D0F3_RX1DB13			BIT13	//0/0/1/1 DRAMC Dynamic Clock Control
    #define D0F3_D0F3_RX1DB12			BIT12	//0/0/1/1 DRAMC Dynamic Clock Control
    #define D0F3_D0F3_RX1DB11			BIT11	//0/0/1/1 DRAMC Dynamic Clock Control
    #define D0F3_D0F3_RX1DB10			BIT10	//0/0/1/1 DRAMC Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_9			BIT9	//0/0/x/x ACT And PRE Will Block CMD for 2T CMD Generate
    #define D0F3_D0F3_RX1DB_8			BIT8	//0/0/1/1 DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_7			BIT7	//0/0/1/1 DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_6			BIT6	//0/0/1/1 DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_5			BIT5	//0/0/1/1 DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_4			BIT4	//0/0/x/x DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_3			BIT3	//0/0/1/1 DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_2			BIT2	//0/0/1/1 DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_1			BIT1	//0/0/1/1 DRAMC Submodule Dynamic Clock Control
    #define D0F3_D0F3_RX1DB_0			BIT0	//0/0/1/1 DRAMC Submodule Dynamic Clock Control
#define D0F3_MISC_CTL_FOR_CALIBRATION		0x1DC	//Misc. Control for Calibration
    #define D0F3_D0F3_RX1DD_15_6			0xFFC0	//0/0/x/x Reserved
    #define D0F3_RDTDMTGB			BIT5	//0/0/x/x MDQM Toggle on Memory Write for I/O Calibration
    #define D0F3_RDMTSWRB			BIT4	//0/0/x/x Trigger Memory Write Cycle; 
    #define D0F3_RDMTSRDB			BIT3	//0/0/x/x Trigger Memory Read Cycle
    #define D0F3_RDTDMTGA			BIT2	//0/0/x/x MDQM Toggle on Memory Write for I/O Calibration
    #define D0F3_RDMTSWRA			BIT1	//0/0/x/x Trigger Memory Write Cycle; 
    #define D0F3_RDMTSRDA			BIT0	//0/0/x/x Trigger Memory Read Cycle
#define D0F3_IO_CALIBRATION_ADR_STEP_SETTING_I		0x1DE	//I/O Calibration Address Step Setting I
    #define D0F3_RTSA_STP_OS_27_12			0xFFFF	//0/0/x/x Address Step Between 2 Calibration Round (WriteRead)
#define D0F3_IO_CALIBRATION_ADR_STEP_SETTING_II		0x1E0	//I/O Calibration Address Step Setting II
    #define D0F3_RTSA_STP_18_3			0xFFFF	//0/0/x/x Address Step Between 2 Continuous Request During 1 Round of Calibration (Either Read or Write)
#define D0F3_INTERNAL_ODT_CTL_DDR_AUTO_COMPENSATION_CTL		0x1E2	//Internal ODT Control &DDR Auto Compensation Control
    #define D0F3_RPADODTEN			BIT15	//0/x/*/* Chip Internal ODT Dynamic On/Off Enable - Channel A
    #define D0F3_RPADODTAON			BIT14	//0/x/*/* reserved
    #define D0F3_RPADODTEN_CHB			BIT13	//0/x/*/* Chip Internal ODT Dynamic On/Off Enable - Channel B
    #define D0F3_RPADODTAON_CHB			BIT12	//0/x/*/* Reserved
    #define D0F3_D0F3_RX61_11_1			0xFFE	//0/0/x/x Reserved
    #define D0F3_D0F3_RX610			BIT0	//0/0/x/x Control ODT_PHASE
#define D0F3_TEST_RESERVED		0x1F2	//Test - Reserved
    #define D0F3_D0F3_RX1F3_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_D0F3_RX1F3B7			BIT7	//0/0/x/x Reserved
    #define D0F3_RHRDLLRSTDLLRESET			BIT6	//0/0/x/x Reserved
    #define D0F3_RCKETST			BIT5	//0/0/x/x Test Mode to Eliminate 200T for 1st DRAM Access
    #define D0F3_D0F3_RX1F3B_4_0			0x1F	//0/0/x/x Reserved
#define D0F3_MEM_CLK_OUTPUT_ENABLE_FOR_CHN_A_B		0x1F4	//Memory Clock Output Enable for Channel A/B
    #define D0F3_D0F3_RX1F5_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RMCLKBEN_3_0			0xF0	//1111b/1111b/x/x Output Enable for Memory Clock Pin - Channel B
    #define D0F3_RMCLKAEN_3_0			0xF	//1111b/1111b/x/x Output Enable for Memory Clock Pin - Channel A
#define D0F3_STA_OF_CALIBRATION_USING_WRITE_LEVELING		0x1F6	//Status of Calibration Using Write Leveling
    #define D0F3_WLVL_FOUND_B_7_0			0xFF00	//HwInit/x/x/x Status of Calibration Using Write Leveling
    #define D0F3_WLVL_FOUND_A_7_0			0xFF	//HwInit/x/x/x Status of Calibration Using Write Leveling
#define D0F3_DDRPHY_CTL_MISC_CTL		0x1F8	//DDRPHY Control & Miscellaneous Control
    #define D0F3_D0F3_RX1F9_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RAUTOPRE			BIT7	//0/0/0/0 Auto-Precharge for CPU Write-Back
    #define D0F3_RDIPNRZ			BIT6	//1b/1/1/1 DRAM Side Input Pointer Non-Return-Zero Mode
    #define D0F3_RVGAEN			BIT5	//1b/x/*/* Conventional VGA Paths for Internal Integrated GFX
    #define D0F3_D0F3_RX1F9_4_0			0x1F	//0/0/x/x Reserved
#define D0F3_ECC_ERR_REPORT		0x218	//ECC Error Report
    #define D0F3_D0F3_RX7C_15_14			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_SDAS_CHA_36_35			(BIT12 + BIT13)	//HwInit/0/x/x Signle Bit ECC Error Address - CHA
    #define D0F3_SDAS_CHB_36_35			(BIT10 + BIT11)	//HwInit/0/x/x Signle Bit ECC Error Address - CHB
    #define D0F3_D0F3_RX7C_9_0			0x3FF	//0/0/x/x Reserved
#define D0F3_ECC_ERR_REPORT_ADR_CHA		0x21A	//ECC Error Report Address CHA
    #define D0F3_SDAS_CHA_18_3			0xFFFF	//HwInit/0/x/x Signle Bit ECC Error Address - CHA
#define D0F3_ECC_ERR_REPORT_ADR_CHA_Z1		0x21C	//ECC Error Report Address CHA
    #define D0F3_SDAS_CHA_34_19			0xFFFF	//HwInit/0/x/x Signle Bit ECC Error Address - CHA
#define D0F3_ECC_ERR_REPORT_ADR_CHB		0x21E	//ECC Error Report Address CHB
    #define D0F3_SDAS_CHB_18_3			0xFFFF	//HwInit/0/x/x Signle Bit ECC Error Address - CHB
#define D0F3_ECC_ERR_REPORT_ADR_CHB_Z1		0x220	//ECC Error Report Address CHB
    #define D0F3_SDAS_CHB_34_19			0xFFFF	//HwInit/0/x/x Signle Bit ECC Error Address - CHB
#define D0F3_ECC_ERR_REPORT_Z1		0x222	//ECC Error Report
    #define D0F3_D0F3_RX223B_15_6			0xFFC0	//0/0/x/x Reserved
    #define D0F3_MCDAS_CHA_36_35			(BIT4 + BIT5)	//HwInit/0/x/x Mutiple Bit ECC Error Address - CHA
    #define D0F3_MCDAS_CHB_36_35			(BIT2 + BIT3)	//HwInit/0/x/x Mutiple Bit ECC Error Address - CHB
    #define D0F3_D0F3_RX223B_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D0F3_ECC_ERR_REPORT_Z2		0x224	//ECC Error Report
    #define D0F3_MCDAS_CHA_18_3			0xFFFF	//HwInit/0/x/x Mutiple Bit ECC Error Address - CHA
#define D0F3_ECC_ERR_REPORT_Z3		0x226	//ECC Error Report
    #define D0F3_MCDAS_CHA_34_19			0xFFFF	//HwInit/0/x/x Mutiple Bit ECC Error Address - CHA
#define D0F3_ECC_ERR_REPORT_Z4		0x228	//ECC Error Report
    #define D0F3_MCDAS_CHB_18_3			0xFFFF	//HwInit/0/x/x Mutiple Bit ECC Error Address - CHB
#define D0F3_ECC_ERR_REPORT_Z5		0x22A	//ECC Error Report
    #define D0F3_MCDAS_CHB_34_19			0xFFFF	//HwInit/0/x/x Mutiple Bit ECC Error Address - CHB
#define D0F3_ECC_RANK_INF_FOR_CHA_CHB		0x22C	//ECC RANK INF for CHA/CHB
    #define D0F3_D0F3_RX22D_15_14			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_MCDBKS_CHA_2_0			(BIT11 + BIT12 + BIT13)	//HwInit/0/x/x Rank Address of First Uncorrectable Error for CHA
    #define D0F3_SDBKS_CHA_2_0			(BIT8 + BIT9 + BIT10)	//HwInit/0/x/x Rank Address of First Correctable Error for CHA
    #define D0F3_D0F3_RX22D_7_6			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F3_MCDBKS_CHB_2_0			(BIT3 + BIT4 + BIT5)	//HwInit/0/x/x Rank Address of First Uncorrectable Error for CHB
    #define D0F3_SDBKS_CHB_2_0			(BIT0 + BIT1 + BIT2)	//HwInit/0/x/x Rank Address of First Correctable Error for CHB
#define D0F3_RESERVED_Z5		0x22E	//RESERVED
    #define D0F3_D0F3_RX22FB_15_0			0xFFFF	//0/0/x/x Reserved
#define D0F3_PATROL_BEGIN_ADR_CHN_B		0x230	//Patrol Begin Address Channel B
    #define D0F3_RPATROL_ADDR_BEG_CHB_36_26			0xFFE0	//0/0/x/x Patrol Request Begin Address CHB
    #define D0F3_RPATROL_ADDR_EN_CHB			BIT4	//0/0/x/x Patrol Address Enable CHB
    #define D0F3_RCS_MAN			BIT3	//0/0/x/x Chip Select Manual Control CHA
    #define D0F3_RCS_MAN_CHB			BIT2	//0/0/x/x Chip Select Manual Control CHB
    #define D0F3_D0F3_RX231B1			BIT1	//0/0/x/x Reserved
    #define D0F3_RCMDFLAGDIS			BIT0	//0/0/x/x Reserved
#define D0F3_PATROL_END_ADR_CHN_B		0x232	//Patrol End Address Channel B
    #define D0F3_RPATROL_ADDR_END_CHB_36_26			0xFFE0	//0/0/x/x Patrol Request End Address CHB
    #define D0F3_D0F3_RX233H_4_0			0x1F	//0/0/x/x Reserved
#define D0F3_RRANK_DELA_RCS		0x234	//RRANK_DELA&RCS
    #define D0F3_RRANK_DELAY_3_0			0xF000	//0/0/x/x Per-Rank Delay for Read
    #define D0F3_RRANK_DELAY_W_3_0			0xF00	//0/0/x/x Per-Rank Delay for Write
    #define D0F3_RCS_VAL_7_0			0xFF	//FFh/ffh/x/x Chip Select Manual Value
#define D0F3_RM2I_UNMATC_CHA		0x236	//RM2I_UNMATC CHA
    #define D0F3_D0F3_RX237B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_M2I_UNMATCH_A8			BIT8	//HwInit/0/x/x HW Calibration Match Result - Byte 8 CHA
    #define D0F3_M2I_UNMATCH_A_7_0			0xFF	//HwInit/0/x/x HW Calibration Match Result - Byte 0-7 CHA
#define D0F3_RM2I_UNMATC_CHB		0x238	//RM2I_UNMATC CHB
    #define D0F3_D0F3_RX239B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_M2I_UNMATCH_B8			BIT8	//HwInit/0/x/x HW Calibration Match Result - Byte 8 CHB
    #define D0F3_M2I_UNMATCH_B_7_0			0xFF	//HwInit/0/x/x HW Calibration Match Result - Byte 0-7 CHB
#define D0F3_RPSTODT		0x23A	//RPSTODT
    #define D0F3_RPSTODTW_1_0			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F3_RRKSELEN			BIT5	//0/0/x/x By Rank Delay/ODT Control Enable
    #define D0F3_D0F3_RX23BH_4_0			0x1F	//0/0/x/x Reserved
#define D0F3_DQ_TO_DQS_PHASE_OFFSET_DURING_TX_CLKS_CALIBRATION		0x23B	//DQ to DQS Phase Offset during TX CLKS Calibration
    #define D0F3_D0F3_RX23BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RTXDS2DQPH_5_0			0x3F	//20h/x/x/x DQ to DQS Phase Offset during TX CLKS Calibration
#define D0F3_START_ADR_FOR_IO_CALIBRATION		0x23C	//Start Address for I/O Calibration
    #define D0F3_RDMTSA_10_3			0xFF	//0/x/x/x Start Address for I/O Calibration
#define D0F3_START_ADR_FOR_IO_CALIBRATION_Z1		0x23D	//Start Address for I/O Calibration
    #define D0F3_RDMTSA_18_11			0xFF	//0/x/x/x Start Address for I/O Calibration
#define D0F3_START_ADR_FOR_IO_CALIBRATION_Z2		0x23E	//Start Address for I/O Calibration
    #define D0F3_D0F3_RX23FB_15_13			(BIT13 + BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RDMTSA_31_19			0x1FFF	//0/x/x/x Address of I/O Calibration
#define D0F3_RM2IL_COMP		0x240	//RM2IL_COMP
    #define D0F3_D0F3_RX241B_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RM2IL_COMP_Z1			BIT7	//0/0/x/x If Compare Raising Edge When Do HW Calibration
    #define D0F3_RM2IH_COMP			BIT6	//0/0/x/x If Compare Falling Edge When Do HW Calibration
    #define D0F3_RCALIX4EN			BIT5	//0/0/x/x Calibration for X4 Mode
    #define D0F3_RDMLCUEN			BIT4	//0/0/x/x Control to RX FIFO Reset, Set to 1 When Do TX DQS/DQ Calibration
    #define D0F3_RSETIOREG			BIT3	//0/0/x/x Reserved
    #define D0F3_RTSWR_1_0			(BIT1 + BIT2)	//0/0/x/x SW Calibration RW Control
    #define D0F3_RADDRLOOPEN			BIT0	//1b/1b/x/x Control the Address Change Mode of LCU
#define D0F3_SW_REQ_NUM		0x242	//SW_REQ_NUM
    #define D0F3_D0F3_RX243B_15_6			0xFFC0	//0/0/x/x Reserved
    #define D0F3_DMIOSEL_BIT_5_0			0x3F	//0/0/x/x RX DQSI/TX DQ Per Bit Register, Used to Select Which Bit High and Low Bound Result to Be Output from DMIOREG_BIT[11:0]_Ax
#define D0F3_ALERT_RELATED		0x244	//Alert Related
    #define D0F3_D0F3_RX245_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_RERRSCREN			BIT8	//0/0/x/x Srub Request Enable
    #define D0F3_RALERT_CLR_CHA			BIT7	//0/0/x/x Reserved
    #define D0F3_RALERT_CLR_CHB			BIT6	//0/0/x/x Reserved
    #define D0F3_ALERT_FATAL_CHA			BIT5	//0/0/x/x Reserved
    #define D0F3_ALERT_FATAL_CHB			BIT4	//0/0/x/x Reserved
    #define D0F3_RRKSWAPEN_CHA			BIT3	//0/0/x/x RK0/RK1 is DQswap or Not for DIMM CHA
    #define D0F3_RRKSWAPEN_CHB			BIT2	//0/0/x/x RK0/RK1 is DQswap or Not for DIMM CHB
    #define D0F3_RCHDECODE			BIT1	//0/0/x/x Reserved
    #define D0F3_D0F3_RX245B0			BIT0	//0/0/x/x Reserved
#define D0F3_MISC_CTL		0x246	//Misc Control
    #define D0F3_D0F3_RX247_15_8			0xFF00	//0/0/x/X Reserved
    #define D0F3_RFSBCHIGH			BIT7	//0/0/x/x FSBC Has High Priority for Write Request
    #define D0F3_RBSIDE			BIT6	//0/0/x/x Bside Selection for RDIMM
    #define D0F3_RODTEN_SREFX			BIT5	//0/x/x/x ODT Control When in Self-refresh
    #define D0F3_RSWINIT_CAL			BIT4	//1b/1/x/x When Working in Software Init with Enable the CAL
    #define D0F3_RSWINIT_CLR			BIT3	//0/0/x/x Control If Internal CAL Settingis Cleared By Hardwire Initial
    #define D0F3_D0F3_RX247B_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x Reserved
#define D0F3_RERR_ENA_CHN_A_BIT_8_0		0x248	//RERR_ENA Channel A Bit[8:0]
    #define D0F3_RERR_ENA_7_0			0xFF00	//FFh/ffh/x/x If Read MPR from Byte [7:0] CHA When DDR4 Error Retry
    #define D0F3_D0F3_RX249_7_1			0xFE	//0/0/x/x Reserved
    #define D0F3_RERR_ENA8			BIT0	//1b/1/x/x If Read MPR from Byte 8 CHA When DDR4 Error Retry
#define D0F3_RERR_ENA_CHN_B_BIT_8_0		0x24A	//RERR_ENA Channel B Bit[8:0]
    #define D0F3_RERR_ENB_7_0			0xFF00	//FFh/ffh/x/x If Read MPR from Byte [7:0] CHB When DDR4 Error Retry
    #define D0F3_D0F3_RX24B_7_1			0xFE	//0/0/x/x Reserved
    #define D0F3_RERR_ENB8			BIT0	//1b/1/x/x If Read MPR from Byte 8 CHB When DDR4 Error Retry
#define D0F3_RCRCMAA15_TO_RCRCMAA0O		0x24C	//RCRCMAA15 to RCRCMAA0O
    #define D0F3_RCRCMAAO_15_10			0xFC00	//0/0/x/x Reserved
    #define D0F3_RCRCMAAO_9_0			0x3FF	//0/0/x/x Reserved
#define D0F3_PATROL_BEGIN_ADR_CHN_A		0x24E	//Patrol Begin Address Channel A
    #define D0F3_RPATROL_ADDR_BEG_36_26			0xFFE0	//0/0/x/x Patrol Request Begin Address
    #define D0F3_RSCREN			BIT4	//0/0/x/x Patrol Scrub Control
    #define D0F3_RSCREN_CHB			BIT3	//0/0/x/x Patrol Scrub Control
    #define D0F3_RPATROL_ADDR_EN			BIT2	//0/0/x/x Patrol Address Enable
    #define D0F3_D0F3_RX24F2_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D0F3_PATROL_END_ADR_CHN_A		0x250	//Patrol End Address Channel A
    #define D0F3_RPATROL_ADDR_END_36_26			0xFFE0	//0/0/x/x Patrol Request End Address
    #define D0F3_D0F3_RX251B4			BIT4	//0/0/x/x Reserved
    #define D0F3_RSCRCNT_3_0			0xF	//0/0/x/x Patrol Scrub Time Slot
#define D0F3_RM2IL		0x252	//RM2IL
    #define D0F3_D0F3_RX253B_15_0			0xFFFF	//0/0/x/x Reserved
#define D0F3_DDR4_MA_DECODE		0x254	//DDR4 MA Decode
    #define D0F3_D0F3_RX255B_15_6			0xFFC0	//0/0/x/x Reserved
    #define D0F3_RPARMAA_EN_RETRY			BIT5	//0/0/x/x Reserved
    #define D0F3_RCRCMAA_EN_RETRY			BIT4	//0/0/x/x Reserved
    #define D0F3_RPARMAA_EN			BIT3	//0/0/x/x Reserved
    #define D0F3_RCRCMAA_EN			BIT2	//0/0/x/x Reserved
    #define D0F3_RBASEL18			BIT1	//0/0/x/x Reserved
    #define D0F3_RBASEL16			BIT0	//0/0/x/x Reserved
#define D0F3_REG_RSCNDSIT_CHA_REG_RSCNDSIT_CHB		0x256	//reg_RSCNDSIT_CHA &reg_RSCNDSIT_CHB
    #define D0F3_D0F3_RX257B_15_14			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_REG_RSCNDSIT_CHA			BIT13	//0/0/x/x Trigger CHA RDSIT Calibration
    #define D0F3_REG_RSCNDSIDLY_CHA			BIT12	//0/0/x/x Trigger CHA DQSI Calibration
    #define D0F3_REG_RSCNTXCLKS_CHA			BIT11	//0/0/x/x Trigger TX DQS LCU Calibration
    #define D0F3_REG_RDMWLEN_CHA			BIT10	//0/0/x/x Trigger WLVL
    #define D0F3_REG_RSCNTXCLKD_CHA			BIT9	//0/0/x/x Trigger TX DQ LCU Calibration
    #define D0F3_D0F3_RX257B_8_6			(BIT6 + BIT7 + BIT8)	//0/0/x/x Reserved
    #define D0F3_REG_RSCNDSIT_CHB			BIT5	//0/0/x/x Trigger CHB RDSIT Calibration
    #define D0F3_REG_RSCNDSIDLY_CHB			BIT4	//0/0/x/x Trigger CHB DQSI Calibration
    #define D0F3_REG_RSCNTXCLKS_CHB			BIT3	//0/0/x/x Trigger CHB TX DQS LCU Calibration
    #define D0F3_REG_RDMWLEN_CHB			BIT2	//0/0/x/x Trigger CHB TX WLVL Calibration
    #define D0F3_REG_RSCNTXCLKD_CHB			BIT1	//0/0/x/x Trigger CHB TX DQ LCU Calibration
    #define D0F3_D0F3_RX257B0			BIT0	//0/0/x/x Reserved
#define D0F3_MODE_X4		0x258	//MODE_X4
    #define D0F3_D0F3_RX259_15_6			0xFFC0	//0/0/x/x Reserved
    #define D0F3_RTNIDSIT_X4			BIT5	//0/0/x/x Reserved
    #define D0F3_RDSIDLY_X4			BIT4	//0/0/x/x Reserved
    #define D0F3_RDCLKSPHA_X4			BIT3	//0/0/x/x Reserved
    #define D0F3_RDCLKSWLVL_X4			BIT2	//0/0/x/x Reserved
    #define D0F3_RDCLKDPHA_X4			BIT1	//0/0/x/x Reserved
    #define D0F3_RWLVLMODE_X4			BIT0	//0/0/x/x Reserved
#define D0F3_TNI_STEP		0x25A	//TNI_STEP
    #define D0F3_D0F3_RX25B_15_7			0xFF80	//0/0/x/x Reserved
    #define D0F3_RTNI_STEP_6_0			0x7F	//0/0/x/x TNI Step When Do HW Calibration
#define D0F3_DQSO_STEP_DQSI_STEP		0x25C	//DQSO_STEP&DQSI_STEP
    #define D0F3_D0F3_RX25DB15			BIT15	//0/0/x/x Reserved
    #define D0F3_RDQSO_STEP_6_0			0x7F00	//0/0/x/x DQS Step When Do HW Calibration
    #define D0F3_D0F3_RX25CB7			BIT7	//0/0/x/x Reserved
    #define D0F3_RDQSI_STEP_6_0			0x7F	//0/0/x/x DQSI Step When do HW Calibration
#define D0F3_DQO_STEP		0x25E	//DQO_STEP
    #define D0F3_D0F3_RX25FB_15_7			0xFF80	//0/0/x/x Reserved
    #define D0F3_RDQO_STEP_6_0			0x7F	//0/0/x/x DQ Step When Do HW Calibration
#define D0F3_ADJUST_DQSIEN_FOR_TNI_BEGIN_AND_END_RANGE		0x260	//Adjust DQSIEN for TNI Begin and End Range
    #define D0F3_D0F3_RX260B_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RTNIDSIT_WOS_END_3_0			0xF0	//0/0/x/x The Upper Limit of Scan Range of RX DQSIEN Whole T Delay during Calibration
    #define D0F3_RTNIDSIT_WOS_BEG_3_0			0xF	//0/0/x/x The Lower Limit of Scan Range of RX DQSIEN Whole T Delay during Calibration
#define D0F3_SCAN_TX_DCLKS_DCLKD_WORK_RANGE		0x262	//Scan TX DCLKS/DCLKD Work Range
    #define D0F3_REG_RSCNTXCLKD_FINE2_CHB			BIT15	//0/x/x/x Start to Scan TX DCLKD Per Bit Work Range Step2
    #define D0F3_RDWADVOS_2_0_END			(BIT12 + BIT13 + BIT14)	//0/x/x/x The Upper Limit of Scan Range of SDHX Whole T Delay during Calibration
    #define D0F3_REG_RSCNTXCLKD_FINE2_CHA			BIT11	//0/x/x/x Start to Scan TX DCLKD Per Bit Work Range Step2
    #define D0F3_RDWADVOS_2_0_BEG			(BIT8 + BIT9 + BIT10)	//0/x/x/x The Lower Limit of Scan Range of SDHX Whole T Delay during Calibration
    #define D0F3_REG_RSCNTXCLKD_FINE1_CHB			BIT7	//0/x/x/x Start to Scan TX DCLKD Per Bit Work Range Step1
    #define D0F3_REG_RSCNTXCLKD_FINE1_CHA			BIT6	//0/x/x/x Start to Scan TX DCLKD Per Bit Work Range Step1
    #define D0F3_D0F3_RX263B5			BIT5	//0/x/x/x Reserved
    #define D0F3_DMIOSEL_4_0			0x1F	//0/x/x/x Select Which HW Calibration Result to Be Output from DMIOREG[7:0]_Ax
#define D0F3_SW_PATTERN0_1_SEL_WHEN_SW_WRITE_DATA_REG		0x264	//SW Pattern0/1 Sel When Software Write Data Register
    #define D0F3_RTXSWPATINSEL			BIT7	//0/0/x/x Reserved
    #define D0F3_RTXSWPATPTR_2_0			(BIT4 + BIT5 + BIT6)	//0/0/x/x Reserved
    #define D0F3_D0F3_RX91DH_3_0			0xF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE0		0x265	//SW Pattern Data Input Byte0
    #define D0F3_RTXSWPAT0_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE1		0x266	//SW Pattern Data Input Byte1
    #define D0F3_RTXSWPAT1_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE2		0x267	//SW Pattern Data Input Byte2
    #define D0F3_RTXSWPAT2_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE3		0x268	//SW Pattern Data Input Byte3
    #define D0F3_RTXSWPAT3_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE4		0x269	//SW Pattern Data Input Byte4
    #define D0F3_RTXSWPAT4_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE5		0x26A	//SW Pattern Data Input Byte5
    #define D0F3_RTXSWPAT5_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE6		0x26B	//SW Pattern Data Input Byte6
    #define D0F3_RTXSWPAT6_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE7		0x26C	//SW Pattern Data Input Byte7
    #define D0F3_RTXSWPAT7_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_BYTE8		0x26D	//SW Pattern Data Input Byte8
    #define D0F3_RTXSWPAT8_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_SW_PATTERN_DATA_INPUT_9		0x26E	//SW Pattern Data Input 9
    #define D0F3_RTXSWPAT9_7_0			0xFF	//0/0/x/x SW Pattern Data Input
#define D0F3_RESERVED_Z6		0x26F	//Reserved
    #define D0F3_D0F3_RX26FB_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RTXSWPAT_A_B		0x270	//RTXSWPAT A-B
    #define D0F3_RTXSWPATB_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RTXSWPATA_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RTXSWPAT_C_D		0x272	//RTXSWPAT C-D
    #define D0F3_RTXSWPATD_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RTXSWPATC_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RTXSWPAT_E_F		0x274	//RTXSWPAT E-F
    #define D0F3_RTXSWPATF_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RTXSWPATE_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RTXSWPAT		0x276	//RTXSWPAT_
    #define D0F3_D0F3_RX277B_15_3			0xFFF8	//0/0/x/x Reserved
    #define D0F3_RSWPATSTEP_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x Reserved
#define D0F3_RRXSWPAT_A_B		0x278	//RRXSWPAT A-B
    #define D0F3_RRXSWPATB_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RRXSWPATA_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RRXSWPAT_C_D		0x27A	//RRXSWPAT C-D
    #define D0F3_RRXSWPATD_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RRXSWPATC_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RRXSWPAT_A_F		0x27C	//RRXSWPAT A-F
    #define D0F3_RRXSWPATF_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RRXSWPATE_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RRXSWPAT_0_1		0x27E	//RRXSWPAT 0-1
    #define D0F3_RRXSWPAT1_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RRXSWPAT0_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RRXSWPAT_2_5		0x280	//RRXSWPAT 2-5
    #define D0F3_RRXSWPAT5_7_0			0xFF000000	//0/0/x/x Reserved
    #define D0F3_RRXSWPAT4_7_0			0xFF0000	//0/0/x/x Reserved
    #define D0F3_RRXSWPAT3_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RRXSWPAT2_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RRXSWPAT_6_9		0x284	//RRXSWPAT 6-9
    #define D0F3_RRXSWPAT9_7_0			0xFF000000	//0/0/x/x Reserved
    #define D0F3_RRXSWPAT8_7_0			0xFF0000	//0/0/x/x Reserved
    #define D0F3_RRXSWPAT7_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RRXSWPAT6_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN0_ADDR		0x288	//SW Pattern0 Addr
    #define D0F3_RSWPATD0_ADDR_31_24			0xFF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN0_ADDR_Z1		0x289	//SW Pattern0 Addr
    #define D0F3_RSWPATD0_ADDR_23_16			0xFF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN0_ADDR_Z2		0x28A	//SW Pattern0 Addr
    #define D0F3_RSWPATD0_ADDR_15_8			0xFF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN0_ADDR_Z3		0x28B	//SW Pattern0 Addr
    #define D0F3_RSWPATD0_ADDR_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN1_ADDR		0x28C	//SW Pattern1 Addr
    #define D0F3_RSWPATD1_ADDR_31_24			0xFF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN1_ADDR_Z1		0x28D	//SW Pattern1 Addr
    #define D0F3_RSWPATD1_ADDR_23_16			0xFF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN1_ADDR_Z2		0x28E	//SW Pattern1 Addr
    #define D0F3_RSWPATD1_ADDR_15_8			0xFF	//0/0/x/x Reserved
#define D0F3_SW_PATTERN1_ADDR_Z3		0x28F	//SW Pattern1 Addr
    #define D0F3_RSWPATD1_ADDR_7_0			0xFF	//0/0/x/x Reserved
#define D0F3_RDSITADD_CHA		0x290	//RDSITADD CHA
    #define D0F3_RDSITADD_1_0_A3			(BIT6 + BIT7)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_A2			(BIT4 + BIT5)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_A1			(BIT2 + BIT3)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_A0			(BIT0 + BIT1)	//0/0/x/x Add Extra TNI Delay Control
#define D0F3_RDSITADD_CHA_Z1		0x291	//RDSITADD CHA
    #define D0F3_RDSITADD_1_0_A7			(BIT6 + BIT7)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_A6			(BIT4 + BIT5)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_A5			(BIT2 + BIT3)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_A4			(BIT0 + BIT1)	//0/0/x/x Add Extra TNI Delay Control
#define D0F3_RDSITADD_CHA_Z2		0x292	//RDSITADD CHA
    #define D0F3_D0F3_RX932H_7_2			0xFC	//0/0/x/x Reserved
    #define D0F3_RDSITADD_1_0_A8			(BIT0 + BIT1)	//0/0/x/x Add Extra TNI Delay Control
#define D0F3_RDSITADD_CHB		0x293	//RDSITADD CHB
    #define D0F3_RDSITADD_1_0_B3			(BIT6 + BIT7)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_B2			(BIT4 + BIT5)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_B1			(BIT2 + BIT3)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_B0			(BIT0 + BIT1)	//0/0/x/x Add Extra TNI Delay Control
#define D0F3_RDSITADD_CHB_Z1		0x294	//RDSITADD CHB
    #define D0F3_RDSITADD_1_0_B7			(BIT6 + BIT7)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_B6			(BIT4 + BIT5)	//0/0/x/x Add Extra TNI Delay Control
    #define D0F3_RDSITADD_1_0_B5			(BIT2 + BIT3)	//0/0/x/x Add Extra TNI delay control
    #define D0F3_RDSITADD_1_0_B4			(BIT0 + BIT1)	//0/0/x/x Add Extra TNI Delay Control
#define D0F3_RDSITADD_CHB_Z2		0x295	//RDSITADD CHB
    #define D0F3_D0F3_RX935H_7_2			0xFC	//0/0/x/x Reserved
    #define D0F3_RDSITADD_1_0_B8			(BIT0 + BIT1)	//0/0/x/x Add Extra TNI Delay Control
#define D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE		0x296	//Start Address for Memory Write/Read Engine
    #define D0F3_RSRW_ADDR_10_3			0xFF	//0/x/x/x Start Address for Memory Write/Read Engine
#define D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE_Z1		0x297	//Start Address for Memory Write/Read Engine
    #define D0F3_RSRW_ADDR_18_11			0xFF	//0/x/x/x Start Address for Memory Write/Read Engine
#define D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE_Z2		0x298	//Start Address for Memory Write/Read Engine
    #define D0F3_RSRW_ADDR_26_19			0xFF	//0/x/x/x Start Address for Memory Write/Read Engine
#define D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE_Z3		0x299	//Start Address for Memory Write/Read Engine
    #define D0F3_RSRW_ADDR_34_27			0xFF	//0/x/x/x Start Address for Memory Write/Read Engine
#define D0F3_START_ADR_FOR_MEM_WRITE_READ_ENGINE_Z4		0x29A	//Start Address for Memory Write/Read Engine
    #define D0F3_D0F3_RX29AB_7_3			0xF8	//0/x/x/x Reserved
    #define D0F3_RSRW_ADDR_37_35			(BIT0 + BIT1 + BIT2)	//0/x/x/x Start Address for Memory Write/Read Engine
#define D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE		0x29B	//8QW Request Number for Memory Write/Read Engine
    #define D0F3_RSRW_LENGTH_7_0			0xFF	//0/x/x/x Request Number for Memory Write/Read Engine
#define D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE_Z1		0x29C	//8QW Request Number for Memory Write/Read Engine
    #define D0F3_RSRW_LENGTH_15_8			0xFF	//0/x/x/x Request Number for Memory Write/Read Engine
#define D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE_Z2		0x29D	//8QW Request Number for Memory Write/Read Engine
    #define D0F3_RSRW_LENGTH_23_16			0xFF	//0/x/x/x Request Number for Memory Write/Read Engine
#define D0F3_8QW_REQ_NUM_FOR_MEM_WRITE_READ_ENGINE_Z3		0x29E	//8QW Request Number for Memory Write/Read Engine
    #define D0F3_RSRW_LENGTH_31_24			0xFF	//0/x/x/x Request Number for Memory Write/Read Engine
#define D0F3_REG_RSRD_REG_RSWR_FOR_MEM_WRITE_READ_ENGINE		0x29F	//reg_RSRD & reg_RSWR for Memory Write/Read Engine
    #define D0F3_D0F3_RX29FB_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_REG_RSRD_CHB			BIT3	//0/x/x/x Trigger CHB Memory Engine 8QW Read Requests
    #define D0F3_REG_RSWR_CHB			BIT2	//0/x/x/x Trigger CHB Memory Engine 8QW Write Requests
    #define D0F3_REG_RSRD			BIT1	//0/x/x/x Trigger CHA Memory Engine 8QW Read Requests
    #define D0F3_REG_RSWR			BIT0	//0/x/x/x Trigger CHA Memory Engine 8QW Write Requests
#define D0F3_ERR_ADR_FOR_MEM_READ_ENGINE		0x2A0	//ERROR Address for Memory Read Engine
    #define D0F3_RSER_ADDR_34_3			0xFFFFFFFF	//HwInit/x/x/x The QW Address in Which ERROR Occurs
#define D0F3_ERR_ADR_FOR_MEM_READ_ENGINE_Z1		0x2A4	//ERROR Address for Memory Read Engine
    #define D0F3_D0F3_RX2A4B_7_3			0xF8	//0/x/x/x Reserved
    #define D0F3_RSER_ADDR_37_35			(BIT0 + BIT1 + BIT2)	//HwInit/x/x/x The QW Address Wherer ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE		0x2A5	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK0_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE_Z1		0x2A6	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK1_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE_Z2		0x2A7	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK2_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE_Z3		0x2A8	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK3_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE_Z4		0x2A9	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK4_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE_Z5		0x2AA	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK5_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE_Z6		0x2AB	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK6_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE_Z7		0x2AC	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK7_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_ERR_BIT_FOR_MEM_READ_ENGINE_Z8		0x2AD	//ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK8_7_0			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE		0x2AE	//Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_7_0			0xFF	//0/x/x/x Data Pattern0 For Memory Write/Read Engine
#define D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2AF	//Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_15_8			0xFF	//0/x/x/x Data Pattern0 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2B0	//Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_23_16			0xFF	//0/x/x/x Data Pattern0 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE_Z3		0x2B1	//Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_31_24			0xFF	//0/x/x/x Data Pattern0 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE_Z4		0x2B2	//Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_39_32			0xFF	//0/x/x/x Data Pattern0 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE_Z5		0x2B3	//Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_47_40			0xFF	//0/x/x/x Data Pattern0 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE_Z6		0x2B4	//Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_55_48			0xFF	//0/x/x/x Data Pattern0 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE_Z7		0x2B5	//Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_63_56			0xFF	//0/x/x/x Data Pattern0 for Memory Write/Read Engine
#define D0F3_ECC_RESULT_OF_DATA_PATTERN0_FOR_MEM_WRITE_READ_ENGINE		0x2B6	//ECC Result of Data Pattern0 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT0_71_64			0xFF	//0/x/x/x ECC Result of Data Pattern0
#define D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE		0x2B7	//Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_7_0			0xFF	//0/x/x/x Data Pattern1 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2B8	//Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_15_8			0xFF	//0/x/x/x Data Pattern1 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2B9	//Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_23_16			0xFF	//0/x/x/x Data Pattern1 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE_Z3		0x2BA	//Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_31_24			0xFF	//0/x/x/x Data Pattern1 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE_Z4		0x2BB	//Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_39_32			0xFF	//0/x/x/x Data Pattern1 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE_Z5		0x2BC	//Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_47_40			0xFF	//0/x/x/x Data Pattern1 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE_Z6		0x2BD	//Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_55_48			0xFF	//0/x/x/x Data Pattern1 for Memory Write/Read Engine
#define D0F3_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE_Z7		0x2BE	//Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_63_56			0xFF	//0/x/x/x Data Pattern1 for Memory Write/Read Engine
#define D0F3_ECC_RESULT_OF_DATA_PATTERN1_FOR_MEM_WRITE_READ_ENGINE		0x2BF	//ECC Result of Data Pattern1 for Memory Write/Read Engine
    #define D0F3_RSDATAPAT1_71_64			0xFF	//0/x/x/x ECC Result of Data Pattern1
//CFG9
#define CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE		0x2C0	//Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_7_0			0xFF	//0/x/x/x Data PATtern2 for MEMORY WRITE/READ Engine
#define CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2C1	//Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_15_8			0xFF	//0/x/x/x Data Pattern2 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2C2	//Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_23_16			0xFF	//0/x/x/x Data Pattern2 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE_Z3		0x2C3	//Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_31_24			0xFF	//0/x/x/x Data Pattern2 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE_Z4		0x2C4	//Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_39_32			0xFF	//0/x/x/x Data Pattern2 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE_Z5		0x2C5	//Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_47_40			0xFF	//0/x/x/x Data Pattern2 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE_Z6		0x2C6	//Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_55_48			0xFF	//0/x/x/x Data Pattern2 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE_Z7		0x2C7	//Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_63_56			0xFF	//0/x/x/x Data Pattern2 for Memory Write/Read Engine
#define CFG9_ECC_RESULT_OF_DATA_PATTERN2_FOR_MEM_WRITE_READ_ENGINE		0x2C8	//ECC Result of Data Pattern2 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT2_71_64			0xFF	//0/x/x/x ECC Result Of Data Pattern2
#define CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE		0x2C9	//Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_7_0			0xFF	//0/x/x/x Data Pattern3 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2CA	//Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_15_8			0xFF	//0/x/x/x Data Pattern3 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2CB	//Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_23_16			0xFF	//0/x/x/x Data Pattern3 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z3		0x2CC	//Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_31_24			0xFF	//0/x/x/x Data Pattern3 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z4		0x2CD	//Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_39_32			0xFF	//0/x/x/x Data Pattern3 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z5		0x2CE	//Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_47_40			0xFF	//0/x/x/x Data Pattern3 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z6		0x2CF	//Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_55_48			0xFF	//0/x/x/x Data Pattern3 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z7		0x2D0	//Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_63_56			0xFF	//0/x/x/x Data Pattern3 for Memory Write/Read Engine
#define CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE		0x2D1	//ECC Result Of Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT3_71_64			0xFF	//0/x/x/x ECC Result of Data Pattern3
#define CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE		0x2D2	//Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_7_0			0xFF	//0/x/x/x Data Pattern4 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2D3	//Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_15_8			0xFF	//0/x/x/x Data Pattern4 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2D4	//Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_23_16			0xFF	//0/x/x/x Data Pattern4 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE_Z3		0x2D5	//Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_31_24			0xFF	//0/x/x/x Data Pattern4 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE_Z4		0x2D6	//Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_39_32			0xFF	//0/x/x/x Data Pattern4 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE_Z5		0x2D7	//Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_47_40			0xFF	//0/x/x/x Data Pattern4 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE_Z6		0x2D8	//Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_55_48			0xFF	//0/x/x/x Data Pattern4 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE_Z7		0x2D9	//Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_63_56			0xFF	//0/x/x/x Data Pattern4 for Memory Write/Read Engine
#define CFG9_ECC_RESULT_OF_DATA_PATTERN4_FOR_MEM_WRITE_READ_ENGINE		0x2DA	//ECC Result of Data Pattern4 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT4_71_64			0xFF	//0/x/x/x ECC Result of Data Pattern4
#define CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE		0x2DB	//Data Pattern5 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_7_0			0xFF	//0/x/x/x Data Pattern5 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2DC	//Data Pattern5 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_15_8			0xFF	//0/x/x/x Data Pattern5 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2DD	//Data Pattern5 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_23_16			0xFF	//0/x/x/x Data Pattern5 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE_Z3		0x2DE	//Data Pattern5 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_31_24			0xFF	//0/x/x/x Data Pattern5 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE_Z4		0x2DF	//Data Pattern5 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_39_32			0xFF	//0/x/x/x Data Pattern5 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE_Z5		0x2E0	//Data Pattern5 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_47_40			0xFF	//0/x/x/x Data Pattern5 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE_Z6		0x2E1	//Data Pattern5 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_55_48			0xFF	//0/x/x/x Data Pattern5 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN5_FOR_MEM_WRITE_READ_ENGINE_Z7		0x2E2	//Data Pattern5 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_63_56			0xFF	//0/x/x/x Data Pattern5 for Memory Write/Read Engine
#define CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2E3	//ECC Result of Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT5_71_64			0xFF	//0/x/x/x ECC Result of Data Pattern5
#define CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE		0x2E4	//Data Pattern6 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_7_0			0xFF	//0/x/x/x Data Pattern6 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2E5	//Data Pattern6 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_15_8			0xFF	//0/x/x/x Data Pattern6 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2E6	//Data Pattern6 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_23_16			0xFF	//0/x/x/x Data Pattern6 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE_Z3		0x2E7	//Data Pattern6 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_31_24			0xFF	//0/x/x/x Data Pattern6 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE_Z4		0x2E8	//Data Pattern6 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_39_32			0xFF	//0/x/x/x Data Pattern6 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE_Z5		0x2E9	//Data Pattern6 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_47_40			0xFF	//0/x/x/x Data Pattern6 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE_Z6		0x2EA	//Data Pattern6 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_55_48			0xFF	//0/x/x/x Data Pattern6 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN6_FOR_MEM_WRITE_READ_ENGINE_Z7		0x2EB	//Data Pattern6 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_63_56			0xFF	//0/x/x/x Data Pattern6 for Memory Write/Read Engine
#define CFG9_ECC_RESULT_OF_DATA_PATTERN3_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2EC	//ECC Result of Data Pattern3 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT6_71_64			0xFF	//0/x/x/x ECC Result of Data Pattern6
#define CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE		0x2ED	//Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_7_0			0xFF	//0/x/x/x Data Pattern7 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE_Z1		0x2EE	//Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_15_8			0xFF	//0/x/x/x Data Pattern7 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE_Z2		0x2EF	//Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_23_16			0xFF	//0/x/x/x Data Pattern7 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE_Z3		0x2F0	//Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_31_24			0xFF	//0/x/x/x Data Pattern7 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE_Z4		0x2F1	//Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_39_32			0xFF	//0/x/x/x Data Pattern7 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE_Z5		0x2F2	//Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_47_40			0xFF	//0/x/x/x Data Pattern7 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE_Z6		0x2F3	//Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_55_48			0xFF	//0/x/x/x Data Pattern7 for Memory Write/Read Engine
#define CFG9_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE_Z7		0x2F4	//Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_63_56			0xFF	//0/x/x/x Data Pattern7 for Memory Write/Read Engine
#define CFG9_ECC_RESULT_OF_DATA_PATTERN7_FOR_MEM_WRITE_READ_ENGINE		0x2F5	//ECC result Of Data Pattern7 for Memory Write/Read Engine
    #define CFG9_RSDATAPAT7_71_64			0xFF	//0/x/x/x ECC Result of Data Pattern7
//D0F3
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A		0x2F6	//Comparison Pattern for MPR0 Side A
    #define D0F3_RM2IH_7_0			0xFF00	//0/0/x/x Comparation Data for MPR0 Side A during Read Leveling
    #define D0F3_RM2IL_7_0			0xFF	//0/0/x/x Comparation Data for MPR0 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A_Z1		0x2F8	//Comparison Pattern for MPR0 Side A
    #define D0F3_RM2I2H_7_0			0xFF00	//0/0/x/x Comparation Data for MPR0 Side A during Read Leveling
    #define D0F3_RM2I2L_7_0			0xFF	//0/0/x/x Comparation Data for MPR0 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A_Z2		0x2FA	//Comparison Pattern for MPR0 Side A
    #define D0F3_RM2I3L_7_0			0xFF	//0/x/x/x Comparison Data for MPR0 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A_Z3		0x2FB	//Comparison Pattern for MPR0 Side A
    #define D0F3_RM2I3H_7_0			0xFF	//ffh/x/x/x Comparison Data for MPR0 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A_Z4		0x2FC	//Comparison Pattern for MPR0 Side A
    #define D0F3_RM2I4L_7_0			0xFF	//0/x/x/x Comparison Data for MPR0 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_A_Z5		0x2FD	//Comparison Pattern for MPR0 Side A
    #define D0F3_RM2I4H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR0 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A		0x2FE	//Comparison Pattern for MPR1 Side A
    #define D0F3_RP1M2IL_7_0			0xFF	//0/x/x/x Comparison Data for MPR1 Side A during Read Leveling.
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_Z1		0x2FF	//Comparison Pattern for MPR1 Side A
    #define D0F3_RP1M2IH_7_0			0xFF	//0/x/x/x Comparison Data for MPR1 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_Z2		0x300	//Comparison Pattern for MPR1 Side A
    #define D0F3_RP1M2I2L_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR1 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_Z3		0x301	//Comparison Pattern for MPR1 Side A
    #define D0F3_RP1M2I2H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR1 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_Z4		0x302	//Comparison Pattern for MPR1 Side A
    #define D0F3_RP1M2I3L_7_0			0xFF	//0/x/x/x Comparison Data for MPR1 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_Z5		0x303	//Comparison Pattern for MPR1 Side A
    #define D0F3_RP1M2I3H_7_0			0xFF	//0/x/x/x Comparison Data for MPR1 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_Z6		0x304	//Comparison Pattern for MPR1 Side A
    #define D0F3_RP1M2I4L_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR1 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_Z7		0x305	//Comparison Pattern for MPR1 Side A
    #define D0F3_RP1M2I4H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR1 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A		0x306	//Comparison Pattern for MPR2 Side A
    #define D0F3_RP2M2IL_7_0			0xFF	//0/x/x/x Comparison Data for MPR2 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A_Z1		0x307	//Comparison Pattern for MPR2 Side A
    #define D0F3_RP2M2IH_7_0			0xFF	//0/x/x/x Comparison Data for MPR2 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A_Z2		0x308	//Comparison Pattern for MPR2 Side A
    #define D0F3_RP2M2I2L_7_0			0xFF	//0/x/x/x Comparison Data For MPR2 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A_Z3		0x309	//Comparison Pattern for MPR2 Side A
    #define D0F3_RP2M2I2H_7_0			0xFF	//0/x/x/x Comparison Data For MPR2 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A_Z4		0x30A	//Comparison Pattern for MPR2 Side A
    #define D0F3_RP2M2I3L_7_0			0xFF	//FFh/x/x/x Comparison Data For MPR2 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A_Z5		0x30B	//Comparison Pattern for MPR2 Side A
    #define D0F3_RP2M2I3H_7_0			0xFF	//FFh/x/x/x Comparison Data For MPR2 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A_Z6		0x30C	//Comparison Pattern for MPR2 Side A
    #define D0F3_RP2M2I4L_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR2 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_A_Z7		0x30D	//Comparison Pattern for MPR2 Side A
    #define D0F3_RP2M2I4H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR2 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A		0x30E	//Comparison Pattern for MPR3 Side A
    #define D0F3_RP3M2IL_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A_Z1		0x30F	//Comparison Pattern for MPR3 Side A
    #define D0F3_RP3M2IH_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A_Z2		0x310	//Comparison Pattern for MPR3 Side A
    #define D0F3_RP3M2I2L_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A_Z3		0x311	//Comparison Pattern for MPR3 Side A
    #define D0F3_RP3M2I2H_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A_Z4		0x312	//Comparison Pattern for MPR3 Side A
    #define D0F3_RP3M2I3L_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A_Z5		0x313	//Comparison Pattern for MPR3 Side A
    #define D0F3_RP3M2I3H_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A_Z6		0x314	//Comparison Pattern for MPR3 Side A
    #define D0F3_RP3M2I4L_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_A_Z7		0x315	//Comparison Pattern for MPR3 Side A
    #define D0F3_RP3M2I4H_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side A during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B		0x316	//Comparison Pattern for MPR0 Side B
    #define D0F3_RBM2IH_7_0			0xFF00	//0/0/x/x Comparation Data for Read Leveling
    #define D0F3_RBM2IL_7_0			0xFF	//0/0/x/x Comparation Data for Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B_Z1		0x318	//Comparison Pattern for MPR0 Side B
    #define D0F3_RBM2I2H_7_0			0xFF00	//0/0/x/x Comparation Data for Read Leveling
    #define D0F3_RBM2I2L_7_0			0xFF	//0/0/x/x Comparation Data for Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B_Z2		0x31A	//Comparison Pattern for MPR0 Side B
    #define D0F3_RBM2I3L_7_0			0xFF	//0/x/x/x Comparison Data for MPR0 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B_Z3		0x31B	//Comparison Pattern for MPR0 Side B
    #define D0F3_RBM2I3H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR0 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B_Z4		0x31C	//Comparison Pattern for MPR0 Side B
    #define D0F3_RBM2I4L_7_0			0xFF	//0/x/x/x Comparison Data for MPR0 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR0_SIDE_B_Z5		0x31D	//Comparison Pattern for MPR0 Side B
    #define D0F3_RBM2I4H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR0 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B		0x31E	//Comparison Pattern for MPR1 Side A Side B
    #define D0F3_RBP1M2IL_7_0			0xFF	//0/x/x/x Comparison Data for MPR1 Side A Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B_Z1		0x31F	//Comparison Pattern for MPR1 Side A Side B
    #define D0F3_RBP1M2IH_7_0			0xFF	//0/x/x/x Comparison Data for MPR1 Side A Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B_Z2		0x320	//Comparison Pattern for MPR1 Side A Side B
    #define D0F3_RBP1M2I2L_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR1 Side A Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B_Z3		0x321	//Comparison Pattern for MPR1 Side A Side B
    #define D0F3_RBP1M2I2H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR1 Side A Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B_Z4		0x322	//Comparison Pattern for MPR1 Side A Side B
    #define D0F3_RBP1M2I3L_7_0			0xFF	//0/x/x/x Comparison Data for MPR1 Side A Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B_Z5		0x323	//Comparison Pattern for MPR1 Side A Side B
    #define D0F3_RBP1M2I3H_7_0			0xFF	//0/x/x/x Comparison Data for MPR1 Side A Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B_Z6		0x324	//Comparison Pattern for MPR1 Side A Side B
    #define D0F3_RBP1M2I4L_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR1 Side A Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR1_SIDE_A_SIDE_B_Z7		0x325	//Comparison Pattern for MPR1 Side A Side B
    #define D0F3_RBP1M2I4H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR1 Side A Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B		0x326	//Comparison Pattern for MPR2 Side B
    #define D0F3_RBP2M2IL_7_0			0xFF	//0/x/x/x Comparison Data for MPR2 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B_Z1		0x327	//Comparison Pattern for MPR2 Side B
    #define D0F3_RBP2M2IH_7_0			0xFF	//0/x/x/x Comparison Data for MPR2 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B_Z2		0x328	//Comparison Pattern for MPR2 Side B
    #define D0F3_RBP2M2I2L_7_0			0xFF	//0/x/x/x Comparison Data for MPR2 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B_Z3		0x329	//Comparison Pattern for MPR2 Side B
    #define D0F3_RBP2M2I2H_7_0			0xFF	//0/x/x/x Comparison Data for MPR2 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B_Z4		0x32A	//Comparison Pattern for MPR2 Side B
    #define D0F3_RBP2M2I3L_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR2 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B_Z5		0x32B	//Comparison Pattern for MPR2 Side B
    #define D0F3_RBP2M2I3H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR2 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B_Z6		0x32C	//Comparison Pattern for MPR2 Side B
    #define D0F3_RBP2M2I4L_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR2 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR2_SIDE_B_Z7		0x32D	//Comparison Pattern for MPR2 Side B
    #define D0F3_RBP2M2I4H_7_0			0xFF	//FFh/x/x/x Comparison Data for MPR2 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B		0x32E	//Comparison Pattern for MPR3 Side B
    #define D0F3_RBP3M2IL_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z1		0x32F	//Comparison Pattern for MPR3 Side B
    #define D0F3_RBP3M2IH_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z2		0x330	//Comparison Pattern for MPR3 Side B
    #define D0F3_RBP3M2I2L_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z3		0x331	//Comparison Pattern for MPR3 Side B
    #define D0F3_RBP3M2I2H_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z4		0x332	//Comparison Pattern for MPR3 Side B
    #define D0F3_RBP3M2I3L_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z5		0x333	//Comparison Pattern for MPR3 Side B
    #define D0F3_RBP3M2I3H_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z6		0x334	//Comparison Pattern for MPR3 Side B
    #define D0F3_RBP3M2I4L_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z7		0x335	//Comparison Pattern for MPR3 Side B
    #define D0F3_RBP3M2I4H_7_0			0xFF	//0/x/x/x Comparison Data for MPR3 Side B during Read Leveling
#define D0F3_COMPARISON_PATTERN_FOR_MPR3_SIDE_B_Z8		0x336	//Comparison Pattern for MPR3 Side B
    #define D0F3_D0F3_RX337B_15_9			0xFE00	//0/x/x/x Reserved
    #define D0F3_RB_8_0_SIDE			0x1FF	//0/x/x/x 0-8bytes on a Rank Located at Different Side of the Rank
#define D0F3_END_POINTER_FOR_EVERY_WHOLE_T_WHEN_DO_HW_CALIBRATION		0x338	//End Pointer for Every Whole T When Do HW Calibration
    #define D0F3_D0F3_RX339B_15_2			0xFFFC	//0/x/x/x Reserved
    #define D0F3_RENDPTR_1_0			(BIT0 + BIT1)	//00b/x/x/x End Pointer for Every Whole T When Do HW Calibration
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A		0x33A	//HW Calibration Result for Byte0 Channel A
    #define D0F3_DMIOREG_15_0_A0			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte0
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE1_CHN_A		0x33C	//HW Calibration Result for Byte1 Channel A
    #define D0F3_DMIOREG_15_0_A1			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte1
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE2_CHN_A		0x33E	//HW Calibration Result for Byte2 Channel A
    #define D0F3_DMIOREG_15_0_A2			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte2
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE3_CHN_A		0x340	//HW Calibration Result for Byte3 Channel A
    #define D0F3_DMIOREG_15_0_A3			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte3
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE4_CHN_A		0x342	//HW Calibration Result for Byte4 Channel A
    #define D0F3_DMIOREG_15_0_A4			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte4
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE5_CHN_A		0x344	//HW Calibration Result for Byte5 Channel A
    #define D0F3_DMIOREG_15_0_A5			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte5
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE6_CHN_A		0x346	//HW Calibration Result for Byte6 Channel A
    #define D0F3_DMIOREG_15_0_A6			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte6
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE7_CHN_A		0x348	//HW Calibration Result for Byte7 Channel A
    #define D0F3_DMIOREG_15_0_A7			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte7
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE8_CHN_A		0x34A	//HW Calibration Result for Byte8 Channel A
    #define D0F3_DMIOREG_15_0_A8			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte8
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B		0x34C	//HW Calibration Result for Byte0 Channel B
    #define D0F3_DMIOREG_15_0_B0			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte0
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE1_CHN_B		0x34E	//HW Calibration Result for Byte1 Channel B
    #define D0F3_DMIOREG_15_0_B1			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte1
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE2_CHN_B		0x350	//HW Calibration Result for Byte2 Channel B
    #define D0F3_DMIOREG_15_0_B2			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte2
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE3_CHN_B		0x352	//HW Calibration Result for Byte3 Channel B
    #define D0F3_DMIOREG_15_0_B3			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte3
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE4_CHN_B		0x354	//HW Calibration Result for Byte4 Channel B
    #define D0F3_DMIOREG_15_0_B4			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte4
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE5_CHN_B		0x356	//HW Calibration Result for Byte5 Channel B
    #define D0F3_DMIOREG_15_0_B5			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte5
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE6_CHN_B		0x358	//HW Calibration Result for Byte6 Channel B
    #define D0F3_DMIOREG_15_0_B6			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte6
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE7_CHN_B		0x35A	//HW Calibration Result for Byte7 Channel B
    #define D0F3_DMIOREG_15_0_B7			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte7
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE8_CHN_B		0x35C	//HW Calibration Result for Byte8 Channel B
    #define D0F3_DMIOREG_15_0_B8			0xFFFF	//HwInit/x/x/x HW Calibration Result for Byte8
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_A_Z1		0x35E	//HW Calibration Result for Byte0 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A0			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 0
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE1_CHN_A_Z1		0x360	//HW Calibration Result for Byte1 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A1			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 1
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE2_CHN_A_Z1		0x362	//HW Calibration Result for Byte2 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A2			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 2
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE3_CHN_A_Z1		0x364	//HW Calibration Result for Byte3 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A3			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 3
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE4_CHN_A_Z1		0x366	//HW Calibration Result for Byte4 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A4			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 4
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE5_CHN_A_Z1		0x368	//HW Calibration Result for Byte5 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A5			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 5
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE6_CHN_A_Z1		0x36A	//HW Calibration Result for Byte6 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A6			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 6
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE7_CHN_A_Z1		0x36C	//HW Calibration Result for Byte7 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A7			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 7
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE8_CHN_A_Z1		0x36E	//HW Calibration Result for Byte8 Channel A
    #define D0F3_DMIOREG_BIT_15_0_A8			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 8
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE0_CHN_B_Z1		0x370	//HW Calibration Result for Byte0 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B0			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 0
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE1_CHN_B_Z1		0x372	//HW Calibration Result for Byte1 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B1			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 1
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE2_CHN_B_Z1		0x374	//HW Calibration Result for Byte2 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B2			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 2
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE3_CHN_B_Z1		0x376	//HW Calibration Result for Byte3 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B3			0xFFFF	//HwInit/x/x/x HW Calibration Result For Bit Of Byte 3
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE4_CHN_B_Z1		0x378	//HW Calibration Result for Byte4 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B4			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 4
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE5_CHN_B_Z1		0x37A	//HW Calibration Result for Byte5 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B5			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 5
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE6_CHN_B_Z1		0x37C	//HW Calibration Result for Byte6 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B6			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 6
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE7_CHN_B_Z1		0x37E	//HW Calibration Result for Byte7 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B7			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 7
#define D0F3_HW_CALIBRATION_RESULT_FOR_BYTE8_CHN_B_Z1		0x380	//HW Calibration Result for Byte8 Channel B
    #define D0F3_DMIOREG_BIT_15_0_B8			0xFFFF	//HwInit/x/x/x HW Calibration Result for Bit of Byte 8
#define D0F3_CALIBRATION_BURN_IN_MODE_CHN_A		0x382	//Calibration Burn-in Mode Channel A
    #define D0F3_RSCAN_END_5_0			0xFC00	//3Fh/x/x/x The Upper Limit of Scan Range for All Clock Phase Adjust Registers
    #define D0F3_RCAL_BURN_IN_CHA			BIT9	//0/x/x/x Start Calibration Burn-in Mode
    #define D0F3_RCAL_BURN_IN_FAIL_A_8_0			0x1FF	//HwInit/x/x/x Record Calibration Burn-in Fail
#define D0F3_CALIBRATION_BURN_IN_MODE_CHN_B		0x384	//Calibration Burn-in Mode Channel B
    #define D0F3_D0F3_RX385B_15_10			0xFC00	//0/x/x/x Reserved
    #define D0F3_RCAL_BURN_IN_CHB			BIT9	//0/x/x/x Start Calibration burn-in Mode
    #define D0F3_RCAL_BURN_IN_FAIL_B_8_0			0x1FF	//HwInit/x/x/x Record Calibration Burn-in Fail
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_CHN_A		0x386	//Internal Clock PI Phase Control Channel A
    #define D0F3_RLONGBST			BIT7	//0/x/x/x Long Burst Read/Write Enable
    #define D0F3_RFILTEREN			BIT6	//0/x/x/x If Filer 4 0 In LCU Pattern
    #define D0F3_PH_DCLKO_CHA_5_0			0x3F	//0/x/x/x PH_DCLKO[5:0] Internal DCLKO Phase Control For Channel A 
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_CHN_B		0x387	//Internal Clock PI Phase Control Channel B
    #define D0F3_D0F3_RX387B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_DCLKO_CHB_5_0			0x3F	//0/x/x/x PH_DCLKO[5:0] Internal DCLKO Phase Control For Channel B
#define D0F3_CHB_ERR_ADR_FOR_MEM_READ_ENGINE		0x388	//CHB ERROR Address for Memory Read Engine
    #define D0F3_RSER_ADDR_34_3_CHB			0xFFFFFFFF	//HwInit/x/x/x The QW Address Where ERROR Occurs
#define D0F3_CHB_ERR_ADR_FOR_MEM_READ_ENGINE_Z1		0x38C	//CHB ERROR Address for Memory Read Engine
    #define D0F3_D0F3_RX38CB_7_3			0xF8	//0/x/x/x Reserved
    #define D0F3_RSER_ADDR_37_35_CHB			(BIT0 + BIT1 + BIT2)	//HwInit/x/x/x The QW Address in Which ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE		0x38D	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK0_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE_Z1		0x38E	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK1_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE_Z2		0x38F	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK2_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE_Z3		0x390	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK3_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE_Z4		0x391	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK4_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE_Z5		0x392	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK5_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE_Z6		0x393	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK6_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE_Z7		0x394	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK7_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_CHB_ERR_BIT_FOR_MEM_READ_ENGINE_Z8		0x395	//CHB ERROR Bit for Memory Read Engine
    #define D0F3_RSCHK8_7_0_CHB			0xFF	//HwInit/x/x/x The Bit Where ERROR Occurs
#define D0F3_SCAN_TIMES_FOR_EVERY_PTR		0x396	//Scan Times For Every PTR
    #define D0F3_D0F3_RX397B_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_RWLBSTNUM_7_0			0xFF	//8h/x/x/x Scan Times for Every PTR of Write Leveling
#define D0F3_CMPEN_ALWAYS_ON_CHN_A		0x398	//CMPEN Always On Channel A
    #define D0F3_RDIMM			BIT15	//0/x/x/x DIMM Type
    #define D0F3_RDQSCAL			BIT14	//0/x/x/x DQS Calibration Mode Select 
    #define D0F3_RDQCAL			BIT13	//0/x/x/x DQ Calibration Mode Select 
    #define D0F3_RTNICAL			BIT12	//0/x/x/x TNI Calibration Mode Select 
    #define D0F3_RDSICAL			BIT11	//0/x/x/x DSI Calibration Mode Select 
    #define D0F3_RDQBITCAL			BIT10	//0/x/x/x Per BIT Calibration Mode Select 
    #define D0F3_RDQIEN			BIT9	//0/x/x/x DQ Enable
    #define D0F3_RDSIEN			BIT8	//0/x/x/x DS Enable
    #define D0F3_RDSODTON			BIT7	//0/x/x/x DS ODT ON
    #define D0F3_RDQODTON			BIT6	//0/x/x/x DQ ODT ON
    #define D0F3_RDDRX4			BIT5	//0/x/x/x DDR X4 
    #define D0F3_RCMPENDQ_ON			BIT4	//0/x/x/x DQ Pad comppd Control
    #define D0F3_RCMPENDQS_ON			BIT3	//0/x/x/x DQS Pad comppd Control
    #define D0F3_RCMPEN_ALWSON			BIT2	//0/x/x/x CMPEN Always On
    #define D0F3_RODTLAT1			BIT1	//0/x/x/x ODT Pin Latency Control
    #define D0F3_RODTLAT0			BIT0	//0/x/x/x ODT Pin Latency Control
#define D0F3_CMPEN_ALWAYS_ON_CHN_B		0x39A	//CMPEN Always On Channel B
    #define D0F3_RTIMCHKSEL			BIT15	//0/x/x/x Select Timing Check Option
    #define D0F3_RDQSCAL_CHB			BIT14	//0/x/x/x DQS Calibration Mode Select
    #define D0F3_RDQCAL_CHB			BIT13	//0/x/x/x DQ Calibration Mode Select
    #define D0F3_RTNICAL_CHB			BIT12	//0/x/x/x TNI Calibration Mode Select
    #define D0F3_RDSICAL_CHB			BIT11	//0/x/x/x DSI Calibration Mode Select
    #define D0F3_RDQBITCAL_CHB			BIT10	//0/x/x/x Per BIT Calibration Mode Select
    #define D0F3_D0F3_RX39AB_9_0			0x3FF	//0/x/x/x Reserved
#define D0F3_RID_DID_RVENDOR_LOCK_BIT		0x39C	//RID/DID/RVENDOR LOCK BIT
    #define D0F3_D0F3_RX39DB_15_8			0xFF00	//0/0/x/x Reserved
    #define D0F3_D0F3_RX39CB_7_4			0xF0	//0/0/x/x Reserved
    #define D0F3_D0F3_RX39CB3			BIT3	//0/0/x/x RID D0F3 Lock Bit
    #define D0F3_D0F3_RX39CB2			BIT2	//0/0/x/x DID D0F3 Lock Bit
    #define D0F3_RVENDOR_D0F3_LOCK			BIT1	//0/x/x/x RVENDOR_D0F3_LOCK
    #define D0F3_RCLASS_CODE_LOCK_D0F3			BIT0	//0/x/x/x CLASS_CODE_LOCK_D0F3
#define D0F3_PLLIN_CTL		0x39E	//PLLIN Control
    #define D0F3_D0F3_RX39FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPLLIN_CKOUT_EN2			BIT13	//1b/x/x/x Enable PLLIN Clock2/3 Output
    #define D0F3_RPLLIN_CKOUT_EN1			BIT12	//1b/x/x/x Enable PLLIN Clock1 Output
    #define D0F3_RICPSEL_PLLIN_3_0			0xF00	//0101b/x/x/x Charge Pump Current Selection
    #define D0F3_RREFDLY_SEL_PLLIN_3_0			0xF0	//0/x/x/x REFCLKIN Delay Setting
    #define D0F3_RFBDLY_SEL_PLLIN_3_0			0xF	//0/x/x/x PLL Internal FBCLK Delay Setting
#define D0F3_PLLIN_CTL_Z1		0x3A0	//PLLIN Control
    #define D0F3_RDIV_M_PLLIN_7_0			0xFF00	//16h/x/x/x PLL Integer Division Setting
    #define D0F3_RFVCO_TUNE_ABS_PLLIN_3_0			0xF0	//0/x/x/x PLL Internal Analog Test Or Debug Settings
    #define D0F3_RFVCO_TUNE_TC_PLLIN_3_0			0xF	//0/x/x/x PLL Internal Analog Test Or Debug Settings
#define D0F3_PLLIN_CTL_Z2		0x3A2	//PLLIN Control
    #define D0F3_D0F3_RX3A3B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RCKOUT2_DIVN_PLLIN_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Reserved
    #define D0F3_D0F3_RX3A3B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RCKOUT1_DIVN_PLLIN_2_0			(BIT8 + BIT9 + BIT10)	//001b/x/x/x Clock1 Output Division Ratio
    #define D0F3_D0F3_RXB3A2_7_0			0xFF	//0/x/x/x Reserved
#define D0F3_PLLIN_CTL_Z3		0x3A4	//PLLIN Control
    #define D0F3_D0F3_RX3A5_15_4			0xFFF0	//0/x/x/x Reseved
    #define D0F3_RPLLIN_DS_FBT_3_0			0xF	//8h/x/x/x Delay Setting for PLLIN_FBCLKIN When Reference Clock from CLK_TP/CLK_TN and TSTMODE =1
#define D0F3_PLLINDDR_CTL		0x3A6	//PLLINDDR Control
    #define D0F3_D0F3_RX3A7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPLLINDDR_CKOUT_EN2			BIT13	//1b/x/x/x Enable PLLINDDR Clock2 Output
    #define D0F3_RPLLINDDR_CKOUT_EN1			BIT12	//1b/x/x/x Enable PLLINDDR Clock1 Output
    #define D0F3_RICPSEL_PLLINDDR_3_0			0xF00	//0101b/x/x/x Charge Pump Current Selection
    #define D0F3_RREFDLY_SEL_PLLINDDR_3_0			0xF0	//0/x/x/x REFCLKIN Delay Setting
    #define D0F3_RFBDLY_SEL_PLLINDDR_3_0			0xF	//0100b/x/x/x PLL Internal FBCLK Delay Setting
#define D0F3_PLLINDDR_CTL_Z1		0x3A8	//PLLINDDR control
    #define D0F3_RDIV_M_PLLINDDR_7_0			0xFF00	//16h/x/x/x PLL Integer Division Setting
    #define D0F3_RFVCO_TUNE_ABS_PLLINDDR_3_0			0xF0	//0/x/x/x PLL Internal Analog Test Or Debug Settings
    #define D0F3_RFVCO_TUNE_TC_PLLINDDR_3_0			0xF	//0/x/x/x PLL Internal Analog Test Or Debug Settings
#define D0F3_PLLINDDR_CTL_Z2		0x3AA	//PLLINDDR Control
    #define D0F3_D0F3_RX3ABB7			BIT15	//0/x/x/x Reserved
    #define D0F3_RCKOUT2_DIVN_PLLINDDR_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x Reserved
    #define D0F3_D0F3_RX39BB4			BIT11	//0/x/x/x Reserved
    #define D0F3_RCKOUT1_DIVN_PLLINDDR_2_0			(BIT8 + BIT9 + BIT10)	//001b/x/x/x Clock1 Output Division Ratio
    #define D0F3_D0F3_RX3AAB_7_0			0xFF	//0/x/x/x Reserved
#define D0F3_PLLINDDR_CTL_Z3		0x3AC	//PLLINDDR Control
    #define D0F3_D0F3_RX3ADB_15_13			(BIT13 + BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RFB_CD_EN			BIT12	//0/x/x/x Enable RX Delay Compensate When in Test Mode
    #define D0F3_RPLLINDDR_DS_FBT_3_0			0xF00	//1000b/x/x/x Delay Setting for PLLINDDR_FBCLKIN When Reference Clock from CLK_TP/CLK_TN and TSTMODE =1
    #define D0F3_RPLLIN_TNO_P			BIT7	//0/x/x/x TX Output Tri-states Enable for CLK_TP
    #define D0F3_RPLLIN_TNO_N			BIT6	//0/x/x/x TX Output Tri-states Enable for CLK_TN
    #define D0F3_RPLLIN_TXMODE			BIT5	//0/x/x/x TX Mode Setting
    #define D0F3_RPLLIN_TS_SEL_3_0			0x1E	//0/x/x/x Select Test Signal for TSTPad TX Output to Board
    #define D0F3_RPLLIN_TNI			BIT0	//0/x/x/x RX Enable 
#define D0F3_WCLK_PTR_LOG_CHA		0x3AE	//WCLK_PTR_LOG CHA
    #define D0F3_D0F3_RX3AF_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RHWSWPATSEL			BIT7	//0/0/x/x When Doing TX Cali, SW/HW Pattern Select
    #define D0F3_D0F3_RX3AE_6_5			(BIT5 + BIT6)	//0/x/x/x Reserved
    #define D0F3_RSETDSIDLY			BIT4	//1b/1/x/x DQSI Delay Setting Manual Mode -- CHA
    #define D0F3_RSCRAM_LFREQ			BIT3	//0/0/x/x Scramble Latency
    #define D0F3_RRXPIPE2T			BIT2	//0/0/x/x RX Control
    #define D0F3_D0F3_RX3AFB_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D0F3_DDPHY_BIST_CALIBRATION		0x3B0	//DDPHY BIST Calibration
    #define D0F3_D0F3_RX3B0_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RDDRPHYBIST_VOSCHG_MODE			BIT11	//0/0/x/x Trigger Parse VOS Mode
    #define D0F3_RCAL_STEP_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x Used in DDRPHYBIST Calib Mode, to Control DCLKD/S RXDQS PH Change Step
    #define D0F3_RCAL_BIST_PHY_SEL_3_0			0xF0	//0/x/x/x Select DDRPHYBIST Calib Result
    #define D0F3_RCAL_MODE_2_0			(BIT1 + BIT2 + BIT3)	//0/0/x/x DDRPHYBIST Calib Mode
    #define D0F3_RDDRPHYBIST_CAL_EN			BIT0	//0/0/x/x Enable DDRPHYBIST Calibration
#define D0F3_DDPHY_BIST_CALIBRATION_Z1		0x3B2	//DDPHY BIST Calibration
    #define D0F3_D0F3_RX3B2B_15_6			0xFFC0	//0/0/x/x Reserved
    #define D0F3_RCAL_PH_DCLKS_5_0			0x3F	//0/0/x/x DDRPHYBIST Calib Search Start Point of DCLKS
#define D0F3_DDPHY_BIST_CALIBRATION_Z2		0x3B4	//DDPHY BIST Calibration
    #define D0F3_D0F3_RX3B4B_15_14			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F3_RCAL_PH_DQSP_5_0			0x3F00	//0/x/x/x DDRPHYBIST Calib Search Start Point of RX DQSP
    #define D0F3_D0F3_RX3B4B_7_6			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F3_RCAL_PH_DQSN_5_0			0x3F	//0/0/x/x DDRPHYBIST Calib Search Start Point of RX DQSN
#define D0F3_DDPHY_BIST_CALIBRATION_Z3		0x3B6	//DDPHY BIST Calibration
    #define D0F3_D0F3_RX3B6B15			BIT15	//0/0/x/x Reserved
    #define D0F3_RDCLKS_VOS_2_0			(BIT12 + BIT13 + BIT14)	//0/0/x/x DCLKS VOS Start Point in Parse vos DDRPHYBIST and DDRPHYBIST Calib
    #define D0F3_D0F3_RX3B7B11			BIT11	//0/0/x/x Reserved
    #define D0F3_RDCLKD_VOS_2_0			(BIT8 + BIT9 + BIT10)	//0/0/x/x DCLKD VOS Start Point in Parse VOS DDRPHYBIST and DDRPHYBIST Calib
    #define D0F3_D0F3_RX3B6B_7_6			(BIT6 + BIT7)	//0/0/x/x Reserved
    #define D0F3_RCAL_PH_DCLKD_5_0			0x3F	//0/0/x/x DDRPHYBIST Calib Search Start Point of DCLKD
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A		0x3B8	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3B8B_15_10			0xFC00	//0/x/x/x Reserved
    #define D0F3_CAL_BIST_DONE_CHA			BIT9	//HwInit/x/x/x Bist Calibration Done
    #define D0F3_CAL_BIST_PASS_OFFSET_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 1st Result: Pass Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z1		0x3BA	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3BAB_15_9			0xFE00	//0/x/x/x Reserved
    #define D0F3_CAL_BIST_FAIL_OFFSET_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 1st Result: Pass Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z2		0x3BC	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3BDB_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_CAL_BIST_PASS_OFFSET2ND_CHA_8_0			0x1FF	//HwInit/X/x/x DDRPHYBIST 2nd Result: Pass Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z3		0x3BE	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3BBB_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_CAL_BIST_FAIL_OFFSET2ND_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 2nd Result: Fail Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z4		0x3C0	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3C1B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_CAL_BIST_PASS_OFFSET3RD_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 3rd Result: Pass Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z5		0x3C2	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3C3B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_CAL_BIST_FAIL_OFFSET3RD_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 3rd Result: Pass Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z6		0x3C4	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3C5B_15_10			0xFC00	//0/0/x/x Reserved
    #define D0F3_VOSCHG_DONE_CHA			BIT9	//HwInit/x/x/x DDRPHYBIST Parse VOS Done
    #define D0F3_BIST_PASS1ST_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=1
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z7		0x3C6	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3C7B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS2ND_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=2
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z8		0x3C8	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3C9B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS3RD_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=3
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z9		0x3CA	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3CBB_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS4TH_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=4
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z10		0x3CC	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3CDB_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS5TH_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=5
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z11		0x3CE	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3CFB_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS6TH_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=6
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_A_Z12		0x3D0	//DDPHY BIST Calibration for Channel A
    #define D0F3_D0F3_RX3D1B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS7TH_CHA_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=7
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B		0x3D2	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3D3B_15_10			0xFC00	//0/0/x/x Reserved
    #define D0F3_CAL_BIST_DONE_CHB			BIT9	//HwInit/x/x/x BIST Calibration Done
    #define D0F3_CAL_BIST_PASS_OFFSET_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 1st Result: Pass Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z1		0x3D4	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3D5B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_CAL_BIST_FAIL_OFFSET_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 1st Result: Fail Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z2		0x3D6	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3D7B_15_9			0xFE00	//0/x/x/x Reserved
    #define D0F3_CAL_BIST_PASS_OFFSET2ND_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 2nd Result: Pass Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z3		0x3D8	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3D9B_15_9			0xFE00	//0/x/x/x Reserved
    #define D0F3_CAL_BIST_FAIL_OFFSET2ND_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 2nd Result: Fail Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z4		0x3DA	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3DBB_15_9			0xFE00	//0/x/x/x Reserved
    #define D0F3_CAL_BIST_PASS_OFFSET3RD_CHB_5_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 3rd Result: Pass Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z5		0x3DC	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3DDB_15_9			0xFE00	//0/x/x/x Reserved
    #define D0F3_CAL_BIST_FAIL_OFFSET3RD_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST 3rd Result: Fail Point Offset
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z6		0x3DE	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3E0B_15_10			0xFC00	//0/0/x/x Reserved
    #define D0F3_VOSCHG_DONE_CHB			BIT9	//HwInit/x/x/x DDRPHYBIST Parse VOS Done
    #define D0F3_BIST_PASS1ST_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=1
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z7		0x3E0	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3E2B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS2ND_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=2
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z8		0x3E2	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3E4B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS3RD_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=3
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z9		0x3E4	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3E5B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS4TH_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=4
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z10		0x3E6	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3E7B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS5TH_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=5
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z11		0x3E8	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3E9B_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS6TH_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=6
#define D0F3_DDPHY_BIST_CALIBRATION_FOR_CHN_B_Z12		0x3EA	//DDPHY BIST Calibration for Channel B
    #define D0F3_D0F3_RX3EBB_15_9			0xFE00	//0/0/x/x Reserved
    #define D0F3_BIST_PASS7TH_CHB_8_0			0x1FF	//HwInit/x/x/x DDRPHYBIST Result When DCLKD VOS=7
#define D0F3_PLL_OK_AND_VCDL_ENABLE		0x3EC	//PLL OK and VCDL Enable
    #define D0F3_D0F3_RX3EC			0xFF00	//0/x/x/x Reserved
    #define D0F3_DLL_EN_A			BIT7	//0/x/x/x CHA DDRPHY VCDL Enable
    #define D0F3_DLL_EN_B			BIT6	//0/x/x/x CHB DDRPHY VCDL Enable
    #define D0F3_RDLL_EN			BIT5	//0/x/x/x CHA DIMM CLK/CS/CMD/MA VCDL Enable
    #define D0F3_RDLL_EN_CHB			BIT4	//0/x/x/x CHB DIMM CLK/CS/CMD/MA VCDL Enable
    #define D0F3_RPLLIN_PU			BIT3	//0/x/x/x PLLIN Power Up
    #define D0F3_RPLLIN_RST			BIT2	//0/x/x/x PLLIN Reset :
    #define D0F3_RPLLINDDR_PU			BIT1	//0/x/x/x PLLINDDR Power Up
    #define D0F3_RPLLINDDR_RST			BIT0	//0/x/x/x PLLINDDR Reset :
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_A		0x400	//Internal Clock PI Phase Control Byte0 Channel A
    #define D0F3_PIEN_A_DCLKO			BIT15	//1b/x/x/x Internal DCLKO PI Enable PHY A
    #define D0F3_RCKLN_DCLKO_DDR_A			BIT14	//0/0/1/1 Dynmic Clock Control for DCLKO Channel A
    #define D0F3_PH_A0_DCLKO_5_0			0x3F00	//0/x/x/x PH_A0_DCLKO[5:0] Internal DCLKO Phase Control PHY A0
    #define D0F3_PIEN_A_DCLKOP			BIT7	//1b/x/x/x Internal DCLKOP PI Enable PHY A0
    #define D0F3_RCKLN_DCLKO_DDR_B			BIT6	//0/x/1/1 Dynmic Clock Control for DCLKO Channel B
    #define D0F3_PH_A0_DCLKOP_5_0			0x3F	//0/x/x/x PH_A0_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A0
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE1_CHN_A		0x402	//Internal Clock PI Phase Control Byte1 Channel A
    #define D0F3_RDCLKP_EN_A			BIT15	//1b/x/x/x DCLKP Enable
    #define D0F3_RDCLKN_EN_A			BIT14	//1b/x/x/x DCLKN Enable
    #define D0F3_PH_A1_DCLKO_5_0			0x3F00	//0/x/x/x PH_A1_DCLKO[5:0] Internal DCLKO Phase Control PHY A1
    #define D0F3_RCKLN_DCLK_B			BIT7	//0/x/1/1 Dynmic Clock Control for DCLK Channel B
    #define D0F3_RCKLN_DCLK_A			BIT6	//0/x/1/1 Dynmic Clock Control for DCLK Channel A
    #define D0F3_PH_A1_DCLKOP_5_0			0x3F	//0/x/x/x PH_A1_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A1
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE2_CHN_A		0x404	//Internal Clock PI Phase Control Byte2 Channel A
    #define D0F3_RDCLK800P_EN_A			BIT15	//1b/x/x/x DCLK800P Enable
    #define D0F3_RDCLK800N_EN_A			BIT14	//1b/x/x/x DCLK800N Enable
    #define D0F3_PH_A2_DCLKO_5_0			0x3F00	//0/x/x/x PH_A2_DCLKO[5:0] Internal DCLKO Phase Control PHY A2
    #define D0F3_RCKLN_DCLK800_B			BIT7	//0/x/1/1 Dynmic Clock Control for DCLK800 Channel B
    #define D0F3_RCKLN_DCLK800_A			BIT6	//0/x/1/1 Dynmic Clock Control for DCLK800 Channel A
    #define D0F3_PH_A2_DCLKOP_5_0			0x3F	//0/x/x/x PH_A2_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A2
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE3_CHN_A		0x406	//Internal Clock PI Phase Control Byte3 Channel A
    #define D0F3_RCKLN_DIV_CHB			BIT15	//0/0/1/1 Dynmic Clock Control for DIV Channel B
    #define D0F3_RCKLN_DIV_CHA			BIT14	//0/0/1/1 Dynmic Clock Control for DIV Channel A
    #define D0F3_PH_A3_DCLKO_5_0			0x3F00	//0/x/x/x PH_A3_DCLKO[5:0] Internal DCLKO Phase Control PHY A3
    #define D0F3_RCKLN_SCMDB			BIT7	//0/x/1/1 Dynmic Clock Control for SCMD Channel B
    #define D0F3_RCKLN_SCMDA			BIT6	//0/x/1/1 Dynmic Clock Control for SCMD Channel A
    #define D0F3_PH_A3_DCLKOP_5_0			0x3F	//0/x/x/x PH_A3_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A3
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE4_CHN_A		0x408	//Internal Clock PI Phase Control Byte4 Channel A
    #define D0F3_RCKLN_MCSB			BIT15	//0/0/1/1 Dynmic Clock Control for MCS Channel B
    #define D0F3_RCKLN_MCSA			BIT14	//0/0/1/1 Dynmic Clock Control for MCS Channel A
    #define D0F3_PH_A4_DCLKO_5_0			0x3F00	//0/x/x/x PH_A4_DCLKO[5:0] Internal DCLKO Phase Control PHY A4
    #define D0F3_D0F3_RX409B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_A4_DCLKOP_5_0			0x3F	//0/x/x/x PH_A4_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A4
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE5_CHN_A		0x40A	//Internal Clock PI Phase Control Byte5 Channel A
    #define D0F3_D0F3_RX40BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_A5_DCLKO_5_0			0x3F00	//0/x/x/x PH_A5_DCLKO[5:0] Internal DCLKO Phase Control PHY A5
    #define D0F3_D0F3_RX40BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_A5_DCLKOP_5_0			0x3F	//0/x/x/x PH_A5_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A5
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE6_CHN_A		0x40C	//Internal Clock PI Phase Control Byte6 Channel A
    #define D0F3_D0F3_RX40DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_A6_DCLKO_5_0			0x3F00	//0/x/x/x PH_A6_DCLKO[5:0] Internal DCLKO Phase Control PHY A6
    #define D0F3_D0F3_RX40DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_A6_DCLKOP_5_0			0x3F	//0/x/x/x PH_A6_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A6
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE7_CHN_A		0x40E	//Internal Clock PI Phase Control Byte7 Channel A
    #define D0F3_D0F3_RX40FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_A7_DCLKO_5_0			0x3F00	//0/x/x/x PH_A7_DCLKO[5:0] Internal DCLKO Phase Control PHY A7
    #define D0F3_D0F3_RX40FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_A7_DCLKOP_5_0			0x3F	//0/x/x/x PH_A7_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A7
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE8_CHN_A		0x410	//Internal Clock PI Phase Control Byte8 Channel A
    #define D0F3_D0F3_RX411B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_A8_DCLKO_5_0			0x3F00	//0/x/x/x PH_A8_DCLKO[5:0] Internal DCLKO Phase Control PHY A8
    #define D0F3_D0F3_RX411B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_A8_DCLKOP_5_0			0x3F	//0/x/x/x PH_A8_DCLKOP[5:0] Internal DCLKOP Phase Control PHY A8
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE0_CHN_B		0x412	//Internal Clock PI Phase Control Byte0 Channel B
    #define D0F3_PIEN_B_DCLKO			BIT15	//1b/x/x/x Internal DCLKO PI Enable PHY B0
    #define D0F3_D0F3_RX413B14			BIT14	//0/x/x/x Reserved
    #define D0F3_PH_B0_DCLKO_5_0			0x3F00	//0/x/x/x PH_B0_DCLKO[5:0] Internal DCLKO Phase Control PHY B0
    #define D0F3_PIEN_B_DCLKOP			BIT7	//1b/x/x/x Internal DCLKOP PI Enable PHY B0
    #define D0F3_D0F3_RX413B6			BIT6	//0/x/x/x Reserved
    #define D0F3_PH_B0_DCLKOP_5_0			0x3F	//0/x/x/x PH_B0_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B0
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE1_CHN_B		0x414	//Internal Clock PI Phase Control Byte1 Channel B
    #define D0F3_RDCLKP_EN_B			BIT15	//1b/x/x/x DCLKP Enable
    #define D0F3_RDCLKN_EN_B			BIT14	//1b/x/x/x DCLKN Enable
    #define D0F3_PH_B1_DCLKO_5_0			0x3F00	//0/x/x/x PH_B1_DCLKO[5:0] Internal DCLKO Phase Control PHY B1
    #define D0F3_D0F3_RX415B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_B1_DCLKOP_5_0			0x3F	//0/x/x/x PH_B1_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B1
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE2_CHN_B		0x416	//Internal Clock PI Phase Control Byte2 Channel B
    #define D0F3_RDCLK800P_EN_B			BIT15	//1b/x/x/x DCLK800P Enable
    #define D0F3_RDCLK800N_EN_B			BIT14	//1b/x/x/x DCLK800N Enable
    #define D0F3_PH_B2_DCLKO_5_0			0x3F00	//0/x/x/x PH_B2_DCLKO[5:0] Internal DCLKO Phase Control PHY B2
    #define D0F3_D0F3_RX417B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_B2_DCLKOP_5_0			0x3F	//0/x/x/x PH_B2_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B2
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE3_CHN_B		0x418	//Internal Clock PI Phase Control Byte3 Channel B
    #define D0F3_D0F3_RX419B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_B3_DCLKO_5_0			0x3F00	//0/x/x/x PH_B3_DCLKO[5:0] Internal DCLKO Phase Control PHY B3
    #define D0F3_D0F3_RX419B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_B3_DCLKOP_5_0			0x3F	//0/x/x/x PH_B3_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B3
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE4_CHN_B		0x41A	//Internal Clock PI Phase Control Byte4 Channel B
    #define D0F3_D0F3_RX41BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_B4_DCLKO_5_0			0x3F00	//0/x/x/x PH_B4_DCLKO[5:0] Internal DCLKO Phase Control PHY B4
    #define D0F3_D0F3_RX41BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_B4_DCLKOP_5_0			0x3F	//0/x/x/x PH_B4_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B4
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE5_CHN_B		0x41C	//Internal Clock PI Phase Control Byte5 Channel B
    #define D0F3_D0F3_RX41DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_B5_DCLKO_5_0			0x3F00	//0/x/x/x PH_B5_DCLKO[5:0] Internal DCLKO Phase Control PHY B5
    #define D0F3_D0F3_RX41DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_B5_DCLKOP_5_0			0x3F	//0/x/x/x PH_B5_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B5
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE6_CHN_B		0x41E	//Internal Clock PI Phase Control Byte6 Channel B
    #define D0F3_D0F3_RX41FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_B6_DCLKO_5_0			0x3F00	//0/x/x/x PH_B6_DCLKO[5:0] Internal DCLKO Phase Control PHY B6
    #define D0F3_D0F3_RX41FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_B6_DCLKOP_5_0			0x3F	//0/x/x/x PH_B6_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B6
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE7_CHN_B		0x420	//Internal Clock PI Phase Control Byte7 Channel B
    #define D0F3_D0F3_RX421B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_B7_DCLKO_5_0			0x3F00	//0/x/x/x PH_B7_DCLKO[5:0] Internal DCLKO Phase Control PHY B7
    #define D0F3_D0F3_RX421B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_B7_DCLKOP_5_0			0x3F	//0/x/x/x PH_B7_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B7
#define D0F3_INTERNAL_CLK_PI_PHASE_CTL_BYTE8_CHN_B		0x422	//Internal Clock PI Phase Control Byte8 Channel B
    #define D0F3_D0F3_RX423B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_PH_B8_DCLKO_5_0			0x3F00	//0/x/x/x PH_B8_DCLKO[5:0] Internal DCLKO Phase Control PHY B8
    #define D0F3_D0F3_RX423B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_PH_B8_DCLKOP_5_0			0x3F	//0/x/x/x PH_B8_DCLKOP[5:0] Internal DCLKOP Phase Control PHY B8
#define D0F3_TX_CLK_PI_PHASE_CTL_A0_A1_CHN_A		0x424	//TX Clock PI Phase Control A0/A1 Channel A
    #define D0F3_PIEN_A_DCLKD			BIT15	//1b/x/x/x TX DQ PI Enable PHY A
    #define D0F3_PIEN_A_DCLKD_TEST			BIT14	//0/x/x/x TX DQ PI Enable For Channel A Clock Test
    #define D0F3_RPH_A1_DCLKD_5_0			0x3F00	//0/x/x/x PH_A1_DCLKD[5:0] TX DQ Phase Control PHY A1
    #define D0F3_D0F3_RX425B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DCLKD_5_0			0x3F	//0/x/x/x PH_A0_DCLKD[5:0] TX DQ Phase Control PHY A0
#define D0F3_TX_CLK_PI_PHASE_CTL_A2_A3_CHN_A		0x426	//TX Clock PI Phase Control A2/A3 Channel A
    #define D0F3_D0F3_RX427B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DCLKD_5_0			0x3F00	//0/x/x/x PH_A3_DCLKD[5:0] TX DQ Phase Control PHY A3
    #define D0F3_D0F3_RX426B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DCLKD_5_0			0x3F	//0/x/x/x PH_A2_DCLKD[5:0] TX DQ Phase Control PHY A2
#define D0F3_TX_CLK_PI_PHASE_CTL_A4_A5_CHN_A		0x428	//TX Clock PI Phase Control A4/A5 Channel A
    #define D0F3_D0F3_RX429B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DCLKD_5_0			0x3F00	//0/x/x/x PH_A5_DCLKD[5:0] TX DQ Phase Control PHY A5
    #define D0F3_D0F3_RX428B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DCLKD_5_0			0x3F	//0/x/x/x PH_A4_DCLKD[5:0] TX DQ Phase Control PHY A4
#define D0F3_TX_CLK_PI_PHASE_CTL_A6_A7_CHN_A		0x42A	//TX Clock PI Phase Control A6/A7 Channel A
    #define D0F3_D0F3_RX42BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DCLKD_5_0			0x3F00	//0/x/x/x PH_A6_DCLKD[5:0] TX DQ Phase Control PHY A6
    #define D0F3_D0F3_RX42BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DCLKD_5_0			0x3F	//0/x/x/x PH_A7_DCLKD[5:0] TX DQ Phase Control PHY A4
#define D0F3_TX_CLK_PI_PHASE_CTL_A8_CHN_A		0x42C	//TX Clock PI Phase Control A8 Channel A
    #define D0F3_D0F3_RX42DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DCLKD_5_0			0x3F00	//0/x/x/x PH_A8_DCLKD[5:0] TX DQ Phase Control PHY A8
    #define D0F3_D0F3_RX42DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A_DCLKD_TEST_5_0			0x3F	//0/x/x/x PH_A_DCLKD[5:0] TX DQ Phase Control for channel for test clock 
#define D0F3_TX_CLK_PI_PHASE_CTL_B0_B1_CHN_B		0x42E	//TX Clock PI Phase Control B0/B1 Channel B
    #define D0F3_PIEN_B_DCLKD			BIT15	//1b/x/x/x TX DQ PI Enable PHY B
    #define D0F3_PIEN_B_DCLKD_TEST			BIT14	//0/x/x/x TX DQ PI Enable PHY B
    #define D0F3_RPH_B1_DCLKD_5_0			0x3F00	//0/x/x/x PH_B1_DCLKD[5:0] TX DQ Phase Control PHY B1
    #define D0F3_D0F3_RX42FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DCLKD_5_0			0x3F	//0/x/x/x PH_B0_DCLKD[5:0] TX DQ Phase Control PHY B0
#define D0F3_TX_CLK_PI_PHASE_CTL_B2_B3_CHN_B		0x430	//TX Clock PI Phase Control B2/B3 Channel B
    #define D0F3_D0F3_RX431B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DCLKD_5_0			0x3F00	//0/x/x/x PH_B3_DCLKD[5:0] TX DQ Phase Control PHY B3
    #define D0F3_D0F3_RX431B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DCLKD_5_0			0x3F	//0/x/x/x PH_B2_DCLKD[5:0] TX DQ Phase Control PHY B2
#define D0F3_TX_CLK_PI_PHASE_CTL_B4_B5_CHN_B		0x432	//TX Clock PI Phase Control B4/B5 Channel B
    #define D0F3_D0F3_RX433B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DCLKD_5_0			0x3F00	//0/x/x/x PH_B5_DCLKD[5:0] TX DQ Phase Control PHY B5
    #define D0F3_D0F3_RX433B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DCLKD_5_0			0x3F	//0/x/x/x PH_B4_DCLKD[5:0] TX DQ Phase Control PHY B4
#define D0F3_TX_CLK_PI_PHASE_CTL_B6_B7_CHN_B		0x434	//TX Clock PI Phase Control B6/B7 Channel B
    #define D0F3_D0F3_RX435B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DCLKD_5_0			0x3F00	//0/x/x/x PH_B6_DCLKD[5:0] TX DQ Phase Control PHY B6
    #define D0F3_D0F3_RX434B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DCLKD_5_0			0x3F	//0/x/x/x PH_B7_DCLKD[5:0] TX DQ Phase Control PHY B4
#define D0F3_TX_CLK_PI_PHASE_CTL_B8_CHN_B		0x436	//TX Clock PI Phase Control B8 Channel B
    #define D0F3_D0F3_RX437B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DCLKD_5_0			0x3F00	//0/x/x/x PH_B8_DCLKD[5:0] TX DQ Phase Control PHY B8
    #define D0F3_D0F3_RX436B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B_DCLKD_TEST_5_0			0x3F	//0/x/x/x PH_B_DCLKD[5:0] TX DQ Phase Control for channel B Clock Test 
#define D0F3_TX_CLK_PI_PHASE_CTL_A0_A1_CHN_A_Z1		0x438	//TX Clock PI Phase Control A0/A1 Channel A
    #define D0F3_PIEN_A_DCLKS			BIT15	//1b/x/x/x TX DQS PI Enable PHY A
    #define D0F3_PIEN_A_DCLKS_TEST			BIT14	//0/x/x/x TX DQS PI Enable for Channel A Clock Test
    #define D0F3_RPH_A1_DCLKS_5_0			0x3F00	//0/x/x/x PH_A1_DCLKS[5:0] TX DQS Phase Control PHY A1
    #define D0F3_D0F3_RX439B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DCLKS_5_0			0x3F	//0/x/x/x PH_A0_DCLKS[5:0] TX DQS Phase Control PHY A0
#define D0F3_TX_CLK_PI_PHASE_CTL_A2_A3_CHN_A_Z1		0x43A	//TX Clock PI Phase Control A2/A3 Channel A
    #define D0F3_D0F3_RX43BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DCLKS_5_0			0x3F00	//0/x/x/x PH_A3_DCLKS[5:0] TX DQS Phase Control PHY A3
    #define D0F3_D0F3_RX43BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DCLKS_5_0			0x3F	//0/x/x/x PH_A2_DCLKS[5:0] TX DQS Phase Control PHY A2
#define D0F3_TX_CLK_PI_PHASE_CTL_A4_A5_CHN_A_Z1		0x43C	//TX Clock PI Phase Control A4/A5 Channel A
    #define D0F3_D0F3_RX43DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DCLKS_5_0			0x3F00	//0/x/x/x PH_A5_DCLKS[5:0] TX DQS Phase Control PHY A5
    #define D0F3_D0F3_RX43DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DCLKS_5_0			0x3F	//0/x/x/x PH_A4_DCLKS[5:0] TX DQS Phase Control PHY A4
#define D0F3_TX_CLK_PI_PHASE_CTL_A6_A7_CHN_A_Z1		0x43E	//TX Clock PI Phase Control A6/A7 Channel A
    #define D0F3_D0F3_RX43FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DCLKS_5_0			0x3F00	//0/x/x/x PH_A6_DCLKS[5:0] TX DQS Phase Control PHY A6
    #define D0F3_D0F3_RX43EB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DCLKS_5_0			0x3F	//0/x/x/x PH_A7_DCLKS[5:0] TX DQS Phase Control PHY A4
#define D0F3_TX_CLK_PI_PHASE_CTL_A8_CHN_A_Z1		0x440	//TX Clock PI Phase Control A8 Channel A
    #define D0F3_D0F3_RX441B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DCLKS_5_0			0x3F00	//0/x/x/x PH_A8_DCLKS[5:0] TX DQS Phase Control PHY A8
    #define D0F3_D0F3_RX440B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A_DCLKS_TEST_5_0			0x3F	//0/x/x/x PH_A_DCLKS[5:0] TX DQS Phase Control for Channel A Clock Test
#define D0F3_TX_CLK_PI_PHASE_CTL_B0_B1_CHN_B_Z1		0x442	//TX Clock PI Phase Control B0/B1 Channel B
    #define D0F3_PIEN_B_DCLKS			BIT15	//1b/x/x/x TX DQ PI Enable PHY B
    #define D0F3_PIEN_B_DCLKS_TEST			BIT14	//0/x/x/x TX DQ PI Enable PHY B
    #define D0F3_RPH_B1_DCLKS_5_0			0x3F00	//0/x/x/x PH_B1_DCLKS[5:0] TX DQS Phase Control PHY B1
    #define D0F3_D0F3_RX443B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DCLKS_5_0			0x3F	//0/x/x/x PH_B0_DCLKS[5:0] TX DQS Phase Control PHY B0
#define D0F3_TX_CLK_PI_PHASE_CTL_B2_B3_CHN_B_Z1		0x444	//TX Clock PI Phase Control B2/B3 Channel B
    #define D0F3_D0F3_RX445B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DCLKS_5_0			0x3F00	//0/x/x/x PH_B3_DCLKS[5:0] TX DQS Phase Control PHY B3
    #define D0F3_D0F3_RX445B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DCLKS_5_0			0x3F	//0/x/x/x PH_B2_DCLKS[5:0] TX DQS Phase Control PHY B2
#define D0F3_TX_CLK_PI_PHASE_CTL_B4_B5_CHN_B_Z1		0x446	//TX Clock PI Phase Control B4/B5 Channel B
    #define D0F3_D0F3_RX447B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DCLKS_5_0			0x3F00	//0/x/x/x PH_B5_DCLKS[5:0] TX DQS Phase Control PHY B5
    #define D0F3_D0F3_RX446B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DCLKS_5_0			0x3F	//0/x/x/x PH_B4_DCLKS[5:0] TX DQS Phase Control PHY B4
#define D0F3_TX_CLK_PI_PHASE_CTL_B6_B7_CHN_B_Z1		0x448	//TX Clock PI Phase Control B6/B7 Channel B
    #define D0F3_D0F3_RX449B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DCLKS_5_0			0x3F00	//0/x/x/x PH_B6_DCLKS[5:0] TX DQS Phase Control PHY B6
    #define D0F3_D0F3_RX448B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DCLKS_5_0			0x3F	//0/x/x/x PH_B7_DCLKS[5:0] TX DQS Phase Control PHY B4
#define D0F3_TX_CLK_PI_PHASE_CTL_B8_CHN_B_Z1		0x44A	//TX Clock PI Phase Control B8 Channel B
    #define D0F3_D0F3_RX44BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DCLKS_5_0			0x3F00	//0/x/x/x PH_B8_DCLKS[5:0] TX DQS Phase Control PHY B8
    #define D0F3_D0F3_RX44BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B_DCLKS_TEST_5_0			0x3F	//0/x/x/x PH_B_DCLKS[5:0] TX DQS Phase Control for Channel B Clock Test 
#define D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK0_CHN_A		0x46C	//RX Clock PI Phase Control A1/A0 RANK0 Channel A
    #define D0F3_PIEN_A_DCLKDSI			BIT15	//1b/x/x/x RX Input Enable PI Enable PHY A
    #define D0F3_TNI_SEL_A			BIT14	//0/x/x/x Channel A DDRPHY TNI Pre-amble Calibration for DQS High or Low Selection
    #define D0F3_RPH_A1_DCLKDSI_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A1
    #define D0F3_D0F3_RX46DB7			BIT7	//0/x/x/x Reserved
    #define D0F3_PIEN_A_DCLKDSI_TEST			BIT6	//0/x/x/x RX Input Enable PI Enable for Channel A Clock Test
    #define D0F3_RPH_A0_DCLKDSI_5_0_RK0			0x3F	//0/x/x/x PH_A0_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A0
#define D0F3_RX_CLK_PI_PHASE_CTL_A3_A2_RANK0_CHN_A		0x46E	//RX Clock PI Phase Control A3/A2 RANK0 Channel A
    #define D0F3_D0F3_RX46FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DCLKDSI_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A3
    #define D0F3_D0F3_RX46FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DCLKDSI_5_0_RK0			0x3F	//0/x/x/x PH_A2_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A2
#define D0F3_RX_CLK_PI_PHASE_CTL_A5_A4_RANK0_CHN_A		0x470	//RX Clock PI Phase Control A5/A4 RANK0 Channel A
    #define D0F3_D0F3_RX471B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DCLKDSI_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A5
    #define D0F3_D0F3_RX471B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DCLKDSI_5_0_RK0			0x3F	//0/x/x/x PH_A4_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A4
#define D0F3_RX_CLK_PI_PHASE_CTL_A7_A6_RANK0_CHN_A		0x472	//RX Clock PI Phase Control A7/A6 RANK0 Channel A
    #define D0F3_D0F3_RX473B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DCLKDSI_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A7
    #define D0F3_D0F3_RX473B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DCLKDSI_5_0_RK0			0x3F	//0/x/x/x PH_A6_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A6
#define D0F3_RX_CLK_PI_PHASE_CTL_A8_RANK0_CHN_A		0x474	//RX Clock PI Phase Control A8 RANK0 Channel A
    #define D0F3_D0F3_RX475B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DCLKDSI_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A8
    #define D0F3_D0F3_RX475B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A_DCLKDSI_TEST_5_0			0x3F	//0/x/x/x PH_A_DCLKDSI[5:0] RX Input Enable PI Phase Control For Channel A Clock Test
#define D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK1_CHN_A		0x476	//RX Clock PI Phase Control A1/A0 RANK1 Channel A
    #define D0F3_D0F3_RX46DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DCLKDSI_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A1
    #define D0F3_D0F3_RX477B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DCLKDSI_5_0_RK1			0x3F	//0/x/x/x PH_A0_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A0
#define D0F3_RX_CLK_PI_PHASE_CTL_A3_A2_RANK1_CHN_A		0x478	//RX Clock PI Phase Control A3/A2 RANK1 Channel A
    #define D0F3_D0F3_RX479B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DCLKDSI_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A3
    #define D0F3_D0F3_RX479B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DCLKDSI_5_0_RK1			0x3F	//0/x/x/x PH_A2_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A2
#define D0F3_RX_CLK_PI_PHASE_CTL_A5_A4_RANK1_CHN_A		0x47A	//RX Clock PI Phase Control A5/A4 RANK1 Channel A
    #define D0F3_D0F3_RX47BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DCLKDSI_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A5
    #define D0F3_D0F3_RX47BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DCLKDSI_5_0_RK1			0x3F	//0/x/x/x PH_A4_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A4
#define D0F3_RX_CLK_PI_PHASE_CTL_A7_A6_RANK1_CHN_A		0x47C	//RX Clock PI Phase Control A7/A6 RANK1 Channel A
    #define D0F3_D0F3_RX47DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DCLKDSI_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A7
    #define D0F3_D0F3_RX47DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DCLKDSI_5_0_RK1			0x3F	//0/x/x/x PH_A6_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A6
#define D0F3_RX_CLK_PI_PHASE_CTL_A8_RANK1_CHN_A		0x47E	//RX Clock PI Phase Control A8 RANK1 Channel A
    #define D0F3_D0F3_RX47FB15			BIT15	//0/x/x/x Reserved
    #define D0F3_RTNI_SEL_A8			BIT14	//0/x/x/x the register control the TNI rank select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RPH_A8_DCLKDSI_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A8
    #define D0F3_RTNI_SEL_A_7_0			0xFF	//0/x/x/x the register control the TNI rank select delay or not,the function just like RRANK_DELAY(RX234):
#define D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK2_CHN_A		0x480	//RX Clock PI Phase Control A1/A0 RANK2 Channel A
    #define D0F3_D0F3_RX481B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DCLKDSI_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A1
    #define D0F3_D0F3_RX481B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DCLKDSI_5_0_RK2			0x3F	//0/x/x/x PH_A0_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A0
#define D0F3_RX_CLK_PI_PHASE_CTL_A3_A2_RANK2_CHN_A		0x482	//RX Clock PI Phase Control A3/A2 RANK2 Channel A
    #define D0F3_D0F3_RX483B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DCLKDSI_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A3
    #define D0F3_D0F3_RX483B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DCLKDSI_5_0_RK2			0x3F	//0/x/x/x PH_A2_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A2
#define D0F3_RX_CLK_PI_PHASE_CTL_A5_A4_RANK2_CHN_A		0x484	//RX Clock PI Phase Control A5/A4 RANK2 Channel A
    #define D0F3_D0F3_RX485B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DCLKDSI_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A5
    #define D0F3_D0F3_RX485B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DCLKDSI_5_0_RK2			0x3F	//0/x/x/x PH_A4_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A4
#define D0F3_RX_CLK_PI_PHASE_CTL_A7_A6_RANK2_CHN_A		0x486	//RX Clock PI Phase Control A7/A6 RANK2 Channel A
    #define D0F3_D0F3_RX487B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DCLKDSI_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A7
    #define D0F3_D0F3_RX487B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DCLKDSI_5_0_RK2			0x3F	//0/x/x/x PH_A6_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A6
#define D0F3_RX_CLK_PI_PHASE_CTL_A8_RANK2_CHN_A		0x488	//RX Clock PI Phase Control A8 RANK2 Channel A
    #define D0F3_D0F3_RX489B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DCLKDSI_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A8
    #define D0F3_D0F3_RX488B_7_0			0xFF	//0/x/x/x Reserved
#define D0F3_RX_CLK_PI_PHASE_CTL_A1_A0_RANK3_CHN_A		0x48A	//RX Clock PI Phase Control A1/A0 RANK3 Channel A
    #define D0F3_D0F3_RX48BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DCLKDSI_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A1
    #define D0F3_D0F3_RX48BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DCLKDSI_5_0_RK3			0x3F	//0/x/x/x PH_A0_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A0
#define D0F3_RX_CLK_PI_PHASE_CTL_A3_A2_RANK3_CHN_A		0x48C	//RX Clock PI Phase Control A3/A2 RANK3 Channel A
    #define D0F3_D0F3_RX48DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DCLKDSI_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A3
    #define D0F3_D0F3_RX48DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DCLKDSI_5_0_RK3			0x3F	//0/x/x/x PH_A2_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A2
#define D0F3_RX_CLK_PI_PHASE_CTL_A5_A4_RANK3_CHN_A		0x48E	//RX Clock PI Phase Control A5/A4 RANK3 Channel A
    #define D0F3_D0F3_RX48FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DCLKDSI_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A5
    #define D0F3_D0F3_RX48FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DCLKDSI_5_0_RK3			0x3F	//0/x/x/x PH_A4_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A4
#define D0F3_RX_CLK_PI_PHASE_CTL_A7_A6_RANK3_CHN_A		0x490	//RX Clock PI Phase Control A7/A6 RANK3 Channel A
    #define D0F3_D0F3_RX491B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DCLKDSI_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A7
    #define D0F3_D0F3_RX491B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DCLKDSI_5_0_RK3			0x3F	//0/x/x/x PH_A6_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A6
#define D0F3_RX_CLK_PI_PHASE_CTL_A8_RANK3_CHN_A		0x492	//RX Clock PI Phase Control A8 RANK3 Channel A
    #define D0F3_D0F3_RX493B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DCLKDSI_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY A8
    #define D0F3_D0F3_RX492B_7_0			0xFF	//0/x/x/x Reserved
#define D0F3_RX_CLK_PI_PHASE_CTL_B1_B0_RANK4_CHN_B		0x494	//RX Clock PI Phase Control B1/B0 RANK4 Channel B
    #define D0F3_PIEN_B_DCLKDSI			BIT15	//1b/x/x/x RX Input Enable PI Enable PHY B
    #define D0F3_TNI_SEL_B			BIT14	//0/x/x/x Channel B DDRPHY TNI pre-amble Calibration For DQS High or Low Selection
    #define D0F3_RPH_B1_DCLKDSI_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B1
    #define D0F3_D0F3_RX494B7			BIT7	//0/x/x/x Reserved
    #define D0F3_PIEN_B_DCLKDSI_TEST			BIT6	//0/x/x/x RX Input Enable PI Enable for Channel B Clock Test
    #define D0F3_RPH_B0_DCLKDSI_5_0_RK4			0x3F	//0/x/x/x PH_B0_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B0
#define D0F3_RX_CLK_PI_PHASE_CTL_B3_B2_RANK4_CHN_B		0x496	//RX Clock PI Phase Control B3/B2 RANK4 Channel B
    #define D0F3_D0F3_RX497B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DCLKDSI_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B3
    #define D0F3_D0F3_RX496B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DCLKDSI_5_0_RK4			0x3F	//0/x/x/x PH_B2_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B2
#define D0F3_RX_CLK_PI_PHASE_CTL_B5_B4_RANK4_CHN_B		0x498	//RX Clock PI Phase Control B5/B4 RANK4 Channel B
    #define D0F3_D0F3_RX499B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DCLKDSI_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B5
    #define D0F3_D0F3_RX498B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DCLKDSI_5_0_RK4			0x3F	//0/x/x/x PH_B4_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B4
#define D0F3_RX_CLK_PI_PHASE_CTL_B7_B6_RANK4_CHN_B		0x49A	//RX Clock PI Phase Control B7/B6 RANK4 Channel B
    #define D0F3_D0F3_RX49BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DCLKDSI_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B7
    #define D0F3_D0F3_RX49AB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DCLKDSI_5_0_RK4			0x3F	//0/x/x/x PH_B6_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B6
#define D0F3_RX_CLK_PI_PHASE_CTL_B8_RANK4_CHN_B		0x49C	//RX Clock PI Phase Control B8 RANK4 Channel B
    #define D0F3_D0F3_RX49DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DCLKDSI_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B8
    #define D0F3_D0F3_RX49CB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B_DCLKDSI_TEST_5_0			0x3F	//0/x/x/x PH_B_DCLKDSI[5:0] RX Input Enable PI Phase Control For Channel B Clock Test
#define D0F3_RX_CLK_PI_PHASE_CTL_B1_B0_RANK5_CHN_B		0x49E	//RX Clock PI Phase Control B1/B0 RANK5 Channel B
    #define D0F3_D0F3_RX49FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DCLKDSI_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B1
    #define D0F3_D0F3_RX49EB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DCLKDSI_5_0_RK5			0x3F	//0/x/x/x PH_B0_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B0
#define D0F3_RX_CLK_PI_PHASE_CTL_B3_B2_RANK5_CHN_B		0x4A0	//RX Clock PI Phase Control B3/B2 RANK5 Channel B
    #define D0F3_D0F3_RX4A1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DCLKDSI_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B3
    #define D0F3_D0F3_RX4A0B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DCLKDSI_5_0_RK5			0x3F	//0/x/x/x PH_B2_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B2
#define D0F3_RX_CLK_PI_PHASE_CTL_B5_B4_RANK5_CHN_B		0x4A2	//RX Clock PI Phase Control B5/B4 RANK5 Channel B
    #define D0F3_D0F3_RX4A3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DCLKDSI_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B5
    #define D0F3_D0F3_RX4A2B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DCLKDSI_5_0_RK5			0x3F	//0/x/x/x PH_B4_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B4
#define D0F3_RX_CLK_PI_PHASE_CTL_B7_B6_RANK5_CHN_B		0x4A4	//RX Clock PI Phase Control B7/B6 RANK5 Channel B
    #define D0F3_D0F3_RX4A5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DCLKDSI_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B7
    #define D0F3_D0F3_RX4A4B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DCLKDSI_5_0_RK5			0x3F	//0/x/x/x PH_B6_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B6
#define D0F3_RX_CLK_PI_PHASE_CTL_B8_RANK5_CHN_B		0x4A6	//RX Clock PI Phase Control B8 RANK5 Channel B
    #define D0F3_D0F3_RX4A7B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RTNI_SEL_B8			BIT14	//0/x/x/x the register control the TNI rank select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RPH_B8_DCLKDSI_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B8
    #define D0F3_RTNI_SEL_B_7_0			0xFF	//0/x/x/x the register control the TNI rank select delay or not,the function just like RRANK_DELAY(RX234):
#define D0F3_RX_CLK_PI_PHASE_CTL_B1_B0_RANK6_CHN_B		0x4A8	//RX Clock PI Phase Control B1/B0 RANK6 Channel B
    #define D0F3_D0F3_RX4A9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DCLKDSI_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B1
    #define D0F3_D0F3_RX4A8B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DCLKDSI_5_0_RK6			0x3F	//0/x/x/x PH_B0_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B0
#define D0F3_RX_CLK_PI_PHASE_CTL_B3_B2_RANK6_CHN_B		0x4AA	//RX Clock PI Phase Control B3/B2 RANK6 Channel B
    #define D0F3_D0F3_RX4ABB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DCLKDSI_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B3
    #define D0F3_D0F3_RX4AAB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DCLKDSI_5_0_RK6			0x3F	//0/x/x/x PH_B2_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B2
#define D0F3_RX_CLK_PI_PHASE_CTL_B5_B4_RANK6_CHN_B		0x4AC	//RX Clock PI Phase Control B5/B4 RANK6 Channel B
    #define D0F3_D0F3_RX4ADB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DCLKDSI_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B5
    #define D0F3_D0F3_RX4ADB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DCLKDSI_5_0_RK6			0x3F	//0/x/x/x PH_B4_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B4
#define D0F3_RX_CLK_PI_PHASE_CTL_B7_B6_RANK6_CHN_B		0x4AE	//RX Clock PI Phase Control B7/B6 RANK6 Channel B
    #define D0F3_D0F3_RX4AFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DCLKDSI_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B7
    #define D0F3_D0F3_RX4AFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DCLKDSI_5_0_RK6			0x3F	//0/x/x/x PH_B6_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B6
#define D0F3_RX_CLK_PI_PHASE_CTL_B8_RANK6_CHN_B		0x4B0	//RX Clock PI Phase Control B8 RANK6 Channel B
    #define D0F3_D0F3_RX4B1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DCLKDSI_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B8
    #define D0F3_D0F3_RX4B1B_7_0			0xFF	//0/x/x/x Reserved
#define D0F3_RX_CLK_PI_PHASE_CTL_B1_B0_RANK7_CHN_B		0x4B2	//RX Clock PI Phase Control B1/B0 RANK7 Channel B
    #define D0F3_D0F3_RX4B3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DCLKDSI_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B1
    #define D0F3_D0F3_RX4B3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DCLKDSI_5_0_RK7			0x3F	//0/x/x/x PH_B0_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B0
#define D0F3_RX_CLK_PI_PHASE_CTL_B3_B2_RANK7_CHN_B		0x4B4	//RX Clock PI Phase Control B3/B2 RANK7 Channel B
    #define D0F3_D0F3_RX4B5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DCLKDSI_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B3
    #define D0F3_D0F3_RX4B4B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DCLKDSI_5_0_RK7			0x3F	//0/x/x/x PH_B2_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B2
#define D0F3_RX_CLK_PI_PHASE_CTL_B5_B4_RANK7_CHN_B		0x4B6	//RX Clock PI Phase Control B5/B4 RANK7 Channel B
    #define D0F3_D0F3_RX4B7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DCLKDSI_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B5
    #define D0F3_D0F3_RX4B6B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DCLKDSI_5_0_RK7			0x3F	//0/x/x/x PH_B4_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B4
#define D0F3_RX_CLK_PI_PHASE_CTL_B7_B6_RANK7_CHN_B		0x4B8	//RX Clock PI Phase Control B7/B6 RANK7 Channel B
    #define D0F3_D0F3_RX4B9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DCLKDSI_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B7
    #define D0F3_D0F3_RX4B8B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DCLKDSI_5_0_RK7			0x3F	//0/x/x/x PH_B6_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B6
#define D0F3_RX_CLK_PI_PHASE_CTL_B8_RANK7_CHN_B		0x4BA	//RX Clock PI Phase Control B8 RANK7 Channel B
    #define D0F3_D0F3_RX4BBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DCLKDSI_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DCLKDSI[5:0] RX Input Enable PI Phase Control PHY B8
    #define D0F3_D0F3_RX4BAB_7_0			0xFF	//0/x/x/x Reserved
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_0_CHN_A		0x4FC	//RX DQS PI Phase Control A0 RANK0 Bit 0 Channel A
    #define D0F3_PIEN_A_DQS			BIT15	//1b/x/x/x RX DQS Phase Control Enable
    #define D0F3_PIEN_A_DQS_X4			BIT14	//1b/x/x/x RX DQS Phase Control Enable for High 4 Bit
    #define D0F3_RPH_A0_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A0_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX4FDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A0_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_1_CHN_A		0x4FE	//RX DQS PI Phase Control A0 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX4FFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A0_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX4FFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A0_DQS1N[5:0] : RX DQSN Phase Control For DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_2_CHN_A		0x500	//RX DQS PI Phase Control A0 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX501B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A0_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX501B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A0_DQS2N[5:0] : RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_3_CHN_A		0x502	//RX DQS PI Phase Control A0 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX503B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A0_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX503B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A0_DQS3N[5:0] : RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_4_CHN_A		0x504	//RX DQS PI Phase Control A0 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX505B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A0_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX505B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A0_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_5_CHN_A		0x506	//RX DQS PI Phase Control A0 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX507B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A0_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX507B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A0_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_6_CHN_A		0x508	//RX DQS PI Phase Control A0 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX509B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A0_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX509B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A0_DQS6N[5:0]  RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK0_BIT_7_CHN_A		0x50A	//RX DQS PI Phase Control A0 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX50BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A0_DQS7P[5:0] : RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX50BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A0_DQS7N[5:0] : RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK0_BIT_0_CHN_A		0x50C	//RX DQS PI Phase Control A1 RANK0 Bit 0 Channel A
    #define D0F3_D0F3_RX50DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DQS0P[5:0] : RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX50DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A1_DQS0N[5:0] : RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK0_BIT_1_CHN_A		0x50E	//RX DQS PI Phase Control A1 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX50FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX50FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A1_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK0_BIT_2_CHN_A		0x510	//RX DQS PI Phase Control A1 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX511B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX511B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A1_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK0_BIT_3_CHN_A		0x512	//RX DQS PI Phase Control A1 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX513B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX513B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A1_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK0_BIT_4_CHN_A		0x514	//RX DQS PI Phase Control A1 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX515B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX515B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A1_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK0_BIT_5_CHN_A		0x516	//RX DQS PI Phase Control A1 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX517B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX517B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A1_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK0_BIT_6_CHN_A		0x518	//RX DQS PI Phase Control A1 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX519B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX519B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A1_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK0_BIT_7_CHN_A		0x51A	//RX DQS PI Phase Control A1 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX51BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A1_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX51BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A1_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK0_BIT_0_CHN_A		0x51C	//RX DQS PI Phase Control A2 RANK0 Bit 0 Channel A
    #define D0F3_D0F3_RX51DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A2_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX51DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A2_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK0_BIT_1_CHN_A		0x51E	//RX DQS PI Phase Control A2 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX51FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A2_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX51FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A2_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK0_BIT_2_CHN_A		0x520	//RX DQS PI Phase Control A2 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX521B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A2_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX521B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A2_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK0_BIT_3_CHN_A		0x522	//RX DQS PI Phase Control A2 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX523B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A2_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX523B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A2_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK0_BIT_4_CHN_A		0x524	//RX DQS PI Phase Control A2 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX525B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A2_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX525B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A2_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK0_BIT_5_CHN_A		0x526	//RX DQS PI Phase Control A2 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX527B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A2_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX527B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A2_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK0_BIT_6_CHN_A		0x528	//RX DQS PI Phase Control A2 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX529B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A2_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX529B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A2_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK0_BIT_7_CHN_A		0x52A	//RX DQS PI Phase Control A2 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX52BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A2_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX52BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A2_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK0_BIT_0_CHN_A		0x52C	//RX DQS PI Phase Control A3 RANK0 Bit 0 Channel A
    #define D0F3_D0F3_RX52DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX52DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A3_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK0_BIT_1_CHN_A		0x52E	//RX DQS PI Phase Control A3 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX52FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX52FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A3_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK0_BIT_2_CHN_A		0x530	//RX DQS PI Phase Control A3 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX531B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX531B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A3_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK0_BIT_3_CHN_A		0x532	//RX DQS PI Phase Control A3 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX533B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX533B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A3_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK0_BIT_4_CHN_A		0x534	//RX DQS PI Phase Control A3 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX535B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX535B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A3_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK0_BIT_5_CHN_A		0x536	//RX DQS PI Phase Control A3 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX537B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX537B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A3_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK0_BIT_6_CHN_A		0x538	//RX DQS PI Phase Control A3 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX539B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX539B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A3_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK0_BIT_7_CHN_A		0x53A	//RX DQS PI Phase Control A3 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX53BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A3_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX53BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A3_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK0_BIT_0_CHN_A		0x53C	//RX DQS PI Phase Control A4 RANK0 Bit 0 Channel A
    #define D0F3_D0F3_RX53DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A4_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX53DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A4_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK0_BIT_1_CHN_A		0x53E	//RX DQS PI Phase Control A4 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX53FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A4_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX53FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A4_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK0_BIT_2_CHN_A		0x540	//RX DQS PI Phase Control A4 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX541B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A4_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX541B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A4_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK0_BIT_3_CHN_A		0x542	//RX DQS PI Phase Control A4 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX543B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A4_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX543B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A4_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK0_BIT_4_CHN_A		0x544	//RX DQS PI Phase Control A4 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX545B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A4_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX545B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A4_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK0_BIT_5_CHN_A		0x546	//RX DQS PI Phase Control A4 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX547B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A4_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX547B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A4_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK0_BIT_6_CHN_A		0x548	//RX DQS PI Phase Control A4 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX549B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A4_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX549B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A4_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK0_BIT_7_CHN_A		0x54A	//RX DQS PI Phase Control A4 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX54BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A4_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX54BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A4_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK0_BIT_0_CHN_A		0x54C	//RX DQS PI Phase Control A5 RANK0 Bit 0 Channel A
    #define D0F3_D0F3_RX54DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX54DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A5_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK0_BIT_1_CHN_A		0x54E	//RX DQS PI Phase Control A5 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX54FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX54FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A5_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK0_BIT_2_CHN_A		0x550	//RX DQS PI Phase Control A5 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX551B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX551B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A5_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK0_BIT_3_CHN_A		0x552	//RX DQS PI Phase Control A5 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX553B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX553B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A5_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK0_BIT_4_CHN_A		0x554	//RX DQS PI Phase Control A5 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX555B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX555B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A5_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK0_BIT_5_CHN_A		0x556	//RX DQS PI Phase Control A5 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX557B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX557B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A5_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK0_BIT_6_CHN_A		0x558	//RX DQS PI Phase Control A5 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX559B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX559B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A5_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK0_BIT_7_CHN_A		0x55A	//RX DQS PI Phase Control A5 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX55BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A5_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX55BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A5_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK0_BIT_0_CHN_A		0x55C	//RX DQS PI Phase Control A6 RANK0 Bit 0 Channel A
    #define D0F3_D0F3_RX55DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A6_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX55DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A6_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK0_BIT_1_CHN_A		0x55E	//RX DQS PI Phase Control A6 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX55FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A6_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX55FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A6_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK0_BIT_2_CHN_A		0x560	//RX DQS PI Phase Control A6 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX561B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A6_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX561B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A6_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK0_BIT_3_CHN_A		0x562	//RX DQS PI Phase Control A6 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX563B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A6_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX563B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A6_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK0_BIT_4_CHN_A		0x564	//RX DQS PI Phase Control A6 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX565B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A6_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX565B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A6_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK0_BIT_5_CHN_A		0x566	//RX DQS PI Phase Control A6 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX567B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A6_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX567B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A6_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK0_BIT_6_CHN_A		0x568	//RX DQS PI Phase Control A6 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX569B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A6_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX569B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A6_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK0_BIT_7_CHN_A		0x56A	//RX DQS PI Phase Control A6 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX56BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A6_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX56BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A6_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK0_BIT_0_CHN_A		0x56C	//RX DQS PI Phase Control A7 RANK0 Bit 0 Channel A
    #define D0F3_D0F3_RX56DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX56DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A7_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK0_BIT_1_CHN_A		0x56E	//RX DQS PI Phase Control A7 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX56FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX56FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A7_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK0_BIT_2_CHN_A		0x570	//RX DQS PI Phase Control A7 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX571B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX571B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A7_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK0_BIT_3_CHN_A		0x572	//RX DQS PI Phase Control A7 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX573B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX573B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A7_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK0_BIT_4_CHN_A		0x574	//RX DQS PI Phase Control A7 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX575B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX575B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A7_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK0_BIT_5_CHN_A		0x576	//RX DQS PI Phase Control A7 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX577B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX577B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A7_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK0_BIT_6_CHN_A		0x578	//RX DQS PI Phase Control A7 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX579B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX579B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A7_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK0_BIT_7_CHN_A		0x57A	//RX DQS PI Phase Control A7 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX57BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A7_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX57BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A7_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK0_BIT_0_CHN_A		0x57C	//RX DQS PI Phase Control A8 RANK0 Bit 0 Channel A
    #define D0F3_D0F3_RX57DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS0P_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX57DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS0N_5_0_RK0			0x3F	//0/x/x/x PH_A8_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK0_BIT_1_CHN_A		0x57E	//RX DQS PI Phase Control A8 RANK0 Bit 1 Channel A
    #define D0F3_D0F3_RX57FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS1P_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX57FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS1N_5_0_RK0			0x3F	//0/x/x/x PH_A8_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK0_BIT_2_CHN_A		0x580	//RX DQS PI Phase Control A8 RANK0 Bit 2 Channel A
    #define D0F3_D0F3_RX581B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS2P_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX581B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS2N_5_0_RK0			0x3F	//0/x/x/x PH_A8_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK0_BIT_3_CHN_A		0x582	//RX DQS PI Phase Control A8 RANK0 Bit 3 Channel A
    #define D0F3_D0F3_RX583B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS3P_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX583B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS3N_5_0_RK0			0x3F	//0/x/x/x PH_A8_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK0_BIT_4_CHN_A		0x584	//RX DQS PI Phase Control A8 RANK0 Bit 4 Channel A
    #define D0F3_D0F3_RX585B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS4P_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX585B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS4N_5_0_RK0			0x3F	//0/x/x/x PH_A8_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK0_BIT_5_CHN_A		0x586	//RX DQS PI Phase Control A8 RANK0 Bit 5 Channel A
    #define D0F3_D0F3_RX587B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS5P_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX587B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS5N_5_0_RK0			0x3F	//0/x/x/x PH_A8_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK0_BIT_6_CHN_A		0x588	//RX DQS PI Phase Control A8 RANK0 Bit 6 Channel A
    #define D0F3_D0F3_RX589B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS6P_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX589B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS6N_5_0_RK0			0x3F	//0/x/x/x PH_A8_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK0_BIT_7_CHN_A		0x58A	//RX DQS PI Phase Control A8 RANK0 Bit 7 Channel A
    #define D0F3_D0F3_RX58BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS7P_5_0_RK0			0x3F00	//0/x/x/x PH_A8_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX58BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS7N_5_0_RK0			0x3F	//0/x/x/x PH_A8_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK1_BIT_0_CHN_A		0x58C	//RX DQS PI Phase Control A0 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX58DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A0_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX58DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A0_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK1_BIT_1_CHN_A		0x58E	//RX DQS PI Phase Control A0 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX58FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A0_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX58FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A0_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK1_BIT_2_CHN_A		0x590	//RX DQS PI Phase Control A0 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX591B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A0_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX591B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A0_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK1_BIT_3_CHN_A		0x592	//RX DQS PI Phase Control A0 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX593B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A0_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX593B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A0_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK1_BIT_4_CHN_A		0x594	//RX DQS PI Phase Control A0 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX595B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A0_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX595B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A0_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK1_BIT_5_CHN_A		0x596	//RX DQS PI Phase Control A0 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX597B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A0_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX597B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A0_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK1_BIT_6_CHN_A		0x598	//RX DQS PI Phase Control A0 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX599B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A0_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX599B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A0_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK1_BIT_7_CHN_A		0x59A	//RX DQS PI Phase Control A0 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX59BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A0_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX59BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A0_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK1_BIT_0_CHN_A		0x59C	//RX DQS PI Phase Control A1 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX59DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX59DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A1_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK1_BIT_1_CHN_A		0x59E	//RX DQS PI Phase Control A1 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX59FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX59FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A1_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK1_BIT_2_CHN_A		0x5A0	//RX DQS PI Phase Control A1 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX5A1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX5A1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A1_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK1_BIT_3_CHN_A		0x5A2	//RX DQS PI Phase Control A1 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX5A3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX5A3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A1_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK1_BIT_4_CHN_A		0x5A4	//RX DQS PI Phase Control A1 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX5A5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX5A5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A1_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK1_BIT_5_CHN_A		0x5A6	//RX DQS PI Phase Control A1 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX5A7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX5A7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A1_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK1_BIT_6_CHN_A		0x5A8	//RX DQS PI Phase Control A1 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX5A9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX5A9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A1_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK1_BIT_7_CHN_A		0x5AA	//RX DQS PI Phase Control A1 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX5ABB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A1_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX5ABB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A1_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK1_BIT_0_CHN_A		0x5AC	//RX DQS PI Phase Control A2 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX5ADB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A2_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX5ADB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A2_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK1_BIT_1_CHN_A		0x5AE	//RX DQS PI Phase Control A2 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX5AFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A2_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX5AFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A2_DQS1N[5:0]: RX DQSN Phase Control For DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK1_BIT_2_CHN_A		0x5B0	//RX DQS PI Phase Control A2 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX5B1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A2_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX5B1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A2_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK1_BIT_3_CHN_A		0x5B2	//RX DQS PI Phase Control A2 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX5B3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A2_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX5B3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A2_DQS3N[5:0] : RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK1_BIT_4_CHN_A		0x5B4	//RX DQS PI Phase Control A2 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX5B5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A2_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX5B5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A2_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK1_BIT_5_CHN_A		0x5B6	//RX DQS PI Phase Control A2 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX5B7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A2_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX5B7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A2_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK1_BIT_6_CHN_A		0x5B8	//RX DQS PI Phase Control A2 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX5B9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A2_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX5B9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A2_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK1_BIT_7_CHN_A		0x5BA	//RX DQS PI Phase Control A2 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX5BBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A2_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX5BBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A2_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK1_BIT_0_CHN_A		0x5BC	//RX DQS PI Phase Control A3 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX5BDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX5BDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A3_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK1_BIT_1_CHN_A		0x5BE	//RX DQS PI Phase Control A3 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX5BFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX5BFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A3_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK1_BIT_2_CHN_A		0x5C0	//RX DQS PI Phase Control A3 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX5C1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX5C1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A3_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK1_BIT_3_CHN_A		0x5C2	//RX DQS PI Phase Control A3 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX5C3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX5C3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A3_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK1_BIT_4_CHN_A		0x5C4	//RX DQS PI Phase Control A3 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX5C5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX5C5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A3_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK1_BIT_5_CHN_A		0x5C6	//RX DQS PI Phase Control A3 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX5C7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX5C7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A3_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK1_BIT_6_CHN_A		0x5C8	//RX DQS PI Phase Control A3 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX5C9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX5C9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A3_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK1_BIT_7_CHN_A		0x5CA	//RX DQS PI Phase Control A3 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX5CBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A3_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX5CBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A3_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK1_BIT_0_CHN_A		0x5CC	//RX DQS PI Phase Control A4 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX5CDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A4_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX5CDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A4_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK1_BIT_1_CHN_A		0x5CE	//RX DQS PI Phase Control A4 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX5CFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A4_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX5CFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A4_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK1_BIT_2_CHN_A		0x5D0	//RX DQS PI Phase Control A4 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX5D1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A4_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX5D1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A4_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK1_BIT_3_CHN_A		0x5D2	//RX DQS PI Phase Control A4 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX5D3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A4_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX5D3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A4_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK1_BIT_4_CHN_A		0x5D4	//RX DQS PI Phase Control A4 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX5D5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A4_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX5D5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A4_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK1_BIT_5_CHN_A		0x5D6	//RX DQS PI Phase Control A4 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX5D7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A4_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX5D7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A4_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK1_BIT_6_CHN_A		0x5D8	//RX DQS PI Phase Control A4 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX5D9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A4_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX5D9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A4_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK1_BIT_7_CHN_A		0x5DA	//RX DQS PI Phase Control A4 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX5DBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A4_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX5DBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A4_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK1_BIT_0_CHN_A		0x5DC	//RX DQS PI Phase Control A5 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX5DDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX5DDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A5_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK1_BIT_1_CHN_A		0x5DE	//RX DQS PI Phase Control A5 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX5DFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX5DFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A5_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK1_BIT_2_CHN_A		0x5E0	//RX DQS PI Phase Control A5 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX5E1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX5E1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A5_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK1_BIT_3_CHN_A		0x5E2	//RX DQS PI Phase Control A5 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX5E3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX5E3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A5_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK1_BIT_4_CHN_A		0x5E4	//RX DQS PI Phase Control A5 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX5E5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX5E5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A5_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK1_BIT_5_CHN_A		0x5E6	//RX DQS PI Phase Control A5 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX5E7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX5E7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A5_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK1_BIT_6_CHN_A		0x5E8	//RX DQS PI Phase Control A5 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX5E9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX5E9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A5_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK1_BIT_7_CHN_A		0x5EA	//RX DQS PI Phase Control A5 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX5EBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A5_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX5EBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A5_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK1_BIT_0_CHN_A		0x5EC	//RX DQS PI Phase Control A6 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX5EDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A6_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX5EDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A6_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK1_BIT_1_CHN_A		0x5EE	//RX DQS PI Phase Control A6 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX5EFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A6_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX5EFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A6_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK1_BIT_2_CHN_A		0x5F0	//RX DQS PI Phase Control A6 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX5F1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A6_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX5F1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A6_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK1_BIT_3_CHN_A		0x5F2	//RX DQS PI Phase Control A6 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX5F3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A6_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX5F3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A6_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK1_BIT_4_CHN_A		0x5F4	//RX DQS PI Phase Control A6 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX5F5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A6_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX5F5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A6_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK1_BIT_5_CHN_A		0x5F6	//RX DQS PI Phase Control A6 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX5F7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A6_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX5F7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A6_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK1_BIT_6_CHN_A		0x5F8	//RX DQS PI Phase Control A6 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX5F9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A6_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX5F9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A6_DQS6N[5:0]: RX DQSN Phase Control gor DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK1_BIT_7_CHN_A		0x5FA	//RX DQS PI Phase Control A6 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX5FBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A6_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX5FBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A6_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK1_BIT_0_CHN_A		0x5FC	//RX DQS PI Phase Control A7 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX5FDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX5FDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A7_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK1_BIT_1_CHN_A		0x5FE	//RX DQS PI Phase Control A7 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX5FFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX5FFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A7_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK1_BIT_2_CHN_A		0x600	//RX DQS PI Phase Control A7 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX601B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX601B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A7_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK1_BIT_3_CHN_A		0x602	//RX DQS PI Phase Control A7 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX603B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX603B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A7_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK1_BIT_4_CHN_A		0x604	//RX DQS PI Phase Control A7 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX605B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX605B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A7_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK1_BIT_5_CHN_A		0x606	//RX DQS PI Phase Control A7 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX607B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX607B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A7_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK1_BIT_6_CHN_A		0x608	//RX DQS PI Phase Control A7 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX609B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX609B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A7_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK1_BIT_7_CHN_A		0x60A	//RX DQS PI Phase Control A7 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX60BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A7_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX60BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A7_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK1_BIT_0_CHN_A		0x60C	//RX DQS PI Phase Control A8 RANK1 Bit 0 Channel A
    #define D0F3_D0F3_RX60DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS0P_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX60DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS0N_5_0_RK1			0x3F	//0/x/x/x PH_A8_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK1_BIT_1_CHN_A		0x60E	//RX DQS PI Phase Control A8 RANK1 Bit 1 Channel A
    #define D0F3_D0F3_RX60FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS1P_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX60FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS1N_5_0_RK1			0x3F	//0/x/x/x PH_A8_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK1_BIT_2_CHN_A		0x610	//RX DQS PI Phase Control A8 RANK1 Bit 2 Channel A
    #define D0F3_D0F3_RX611B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS2P_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX611B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS2N_5_0_RK1			0x3F	//0/x/x/x PH_A8_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK1_BIT_3_CHN_A		0x612	//RX DQS PI Phase Control A8 RANK1 Bit 3 Channel A
    #define D0F3_D0F3_RX613B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS3P_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX613B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS3N_5_0_RK1			0x3F	//0/x/x/x PH_A8_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK1_BIT_4_CHN_A		0x614	//RX DQS PI Phase Control A8 RANK1 Bit 4 Channel A
    #define D0F3_D0F3_RX615B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS4P_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DQS4P[5:0]: RX DQSP PHASE CONtrol for DQ BIT 4
    #define D0F3_D0F3_RX615B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS4N_5_0_RK1			0x3F	//0/x/x/x PH_A8_DQS4N[5:0]: RX DQSN PHASE CONtrol for DQ BIT 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK1_BIT_5_CHN_A		0x616	//RX DQS PI Phase Control A8 RANK1 Bit 5 Channel A
    #define D0F3_D0F3_RX617B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS5P_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX617B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS5N_5_0_RK1			0x3F	//0/x/x/x PH_A8_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK1_BIT_6_CHN_A		0x618	//RX DQS PI Phase Control A8 RANK1 Bit 6 Channel A
    #define D0F3_D0F3_RX619B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS6P_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX619B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS6N_5_0_RK1			0x3F	//0/x/x/x PH_A8_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK1_BIT_7_CHN_A		0x61A	//RX DQS PI Phase Control A8 RANK1 Bit 7 Channel A
    #define D0F3_D0F3_RX61BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS7P_5_0_RK1			0x3F00	//0/x/x/x PH_A8_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX61BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS7N_5_0_RK1			0x3F	//0/x/x/x PH_A8_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK2_BIT_0_CHN_A		0x61C	//RX DQS PI Phase Control A0 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX61DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A0_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX61DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A0_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK2_BIT_1_CHN_A		0x61E	//RX DQS PI Phase Control A0 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX61FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A0_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX61FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A0_DQS1N[5:0] : RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK2_BIT_2_CHN_A		0x620	//RX DQS PI Phase Control A0 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX621B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A0_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX621B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A0_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK2_BIT_3_CHN_A		0x622	//RX DQS PI Phase Control A0 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX623B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A0_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX623B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A0_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK2_BIT_4_CHN_A		0x624	//RX DQS PI Phase Control A0 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX625B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A0_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX625B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A0_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK2_BIT_5_CHN_A		0x626	//RX DQS PI Phase Control A0 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX627B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A0_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX627B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A0_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK2_BIT_6_CHN_A		0x628	//RX DQS PI Phase Control A0 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX629B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A0_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX629B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A0_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK2_BIT_7_CHN_A		0x62A	//RX DQS PI Phase Control A0 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX62BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A0_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX62BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A0_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK2_BIT_0_CHN_A		0x62C	//RX DQS PI Phase Control A1 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX62DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX62DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A1_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK2_BIT_1_CHN_A		0x62E	//RX DQS PI Phase Control A1 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX62FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX62FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A1_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK2_BIT_2_CHN_A		0x630	//RX DQS PI Phase Control A1 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX631B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX631B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A1_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK2_BIT_3_CHN_A		0x632	//RX DQS PI Phase Control A1 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX633B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX633B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A1_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK2_BIT_4_CHN_A		0x634	//RX DQS PI Phase Control A1 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX635B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX635B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A1_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK2_BIT_5_CHN_A		0x636	//RX DQS PI Phase Control A1 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX637B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX637B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A1_DQS5N[5:0]: RX DQSN Phase Control for DQ bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK2_BIT_6_CHN_A		0x638	//RX DQS PI Phase Control A1 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX639B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX639B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A1_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK2_BIT_7_CHN_A		0x63A	//RX DQS PI Phase Control A1 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX63BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A1_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX63BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A1_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK2_BIT_0_CHN_A		0x63C	//RX DQS PI Phase Control A2 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX63DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A2_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX63DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A2_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK2_BIT_1_CHN_A		0x63E	//RX DQS PI Phase Control A2 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX63FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A2_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX63FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A2_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK2_BIT_2_CHN_A		0x640	//RX DQS PI Phase Control A2 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX641B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A2_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX641B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A2_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK2_BIT_3_CHN_A		0x642	//RX DQS PI Phase Control A2 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX643B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A2_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX643B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A2_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK2_BIT_4_CHN_A		0x644	//RX DQS PI Phase Control A2 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX645B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A2_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX645B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A2_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK2_BIT_5_CHN_A		0x646	//RX DQS PI Phase Control A2 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX647B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A2_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX647B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A2_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK2_BIT_6_CHN_A		0x648	//RX DQS PI Phase Control A2 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX649B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A2_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX649B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A2_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK2_BIT_7_CHN_A		0x64A	//RX DQS PI Phase Control A2 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX64BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A2_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX64BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A2_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK2_BIT_0_CHN_A		0x64C	//RX DQS PI Phase Control A3 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX64DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX64DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A3_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK2_BIT_1_CHN_A		0x64E	//RX DQS PI Phase Control A3 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX64FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX64FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A3_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK2_BIT_2_CHN_A		0x650	//RX DQS PI Phase Control A3 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX651B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX651B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A3_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK2_BIT_3_CHN_A		0x652	//RX DQS PI Phase Control A3 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX653B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX653B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A3_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK2_BIT_4_CHN_A		0x654	//RX DQS PI Phase Control A3 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX655B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX655B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A3_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK2_BIT_5_CHN_A		0x656	//RX DQS PI Phase Control A3 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX657B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX657B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A3_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK2_BIT_6_CHN_A		0x658	//RX DQS PI Phase Control A3 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX659B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX659B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A3_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK2_BIT_7_CHN_A		0x65A	//RX DQS PI Phase Control A3 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX65BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A3_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX65BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A3_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK2_BIT_0_CHN_A		0x65C	//RX DQS PI Phase Control A4 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX65DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A4_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX65DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A4_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK2_BIT_1_CHN_A		0x65E	//RX DQS PI Phase Control A4 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX65FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A4_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX65FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A4_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK2_BIT_2_CHN_A		0x660	//RX DQS PI Phase Control A4 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX661B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A4_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX661B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A4_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK2_BIT_3_CHN_A		0x662	//RX DQS PI Phase Control A4 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX663B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A4_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX663B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A4_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK2_BIT_4_CHN_A		0x664	//RX DQS PI Phase Control A4 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX665B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A4_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX665B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A4_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK2_BIT_5_CHN_A		0x666	//RX DQS PI Phase Control A4 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX667B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A4_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX667B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A4_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK2_BIT_6_CHN_A		0x668	//RX DQS PI Phase Control A4 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX669B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A4_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX669B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A4_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK2_BIT_7_CHN_A		0x66A	//RX DQS PI Phase Control A4 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX66BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A4_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX66BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A4_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK2_BIT_0_CHN_A		0x66C	//RX DQS PI Phase Control A5 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX66DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX66DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A5_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK2_BIT_1_CHN_A		0x66E	//RX DQS PI Phase Control A5 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX66FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX66FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A5_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK2_BIT_2_CHN_A		0x670	//RX DQS PI Phase Control A5 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX671B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX671B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A5_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK2_BIT_3_CHN_A		0x672	//RX DQS PI Phase Control A5 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX673B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX673B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A5_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK2_BIT_4_CHN_A		0x674	//RX DQS PI Phase Control A5 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX675B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX675B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A5_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK2_BIT_5_CHN_A		0x676	//RX DQS PI Phase Control A5 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX677B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX677B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A5_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK2_BIT_6_CHN_A		0x678	//RX DQS PI Phase Control A5 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX679B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX679B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A5_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK2_BIT_7_CHN_A		0x67A	//RX DQS PI Phase Control A5 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX67BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A5_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX67BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A5_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK2_BIT_0_CHN_A		0x67C	//RX DQS PI Phase Control A6 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX67DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A6_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX67DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A6_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK2_BIT_1_CHN_A		0x67E	//RX DQS PI Phase Control A6 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX67FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A6_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX67FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A6_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK2_BIT_2_CHN_A		0x680	//RX DQS PI Phase Control A6 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX681B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A6_DQS2P[5:0]: RX DQSP Phase Control for DQ bit 2
    #define D0F3_D0F3_RX681B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A6_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK2_BIT_3_CHN_A		0x682	//RX DQS PI Phase Control A6 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX683B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A6_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX683B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A6_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK2_BIT_4_CHN_A		0x684	//RX DQS PI Phase Control A6 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX685B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A6_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX685B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A6_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK2_BIT_5_CHN_A		0x686	//RX DQS PI Phase Control A6 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX687B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A6_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX687B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A6_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK2_BIT_6_CHN_A		0x688	//RX DQS PI Phase Control A6 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX689B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A6_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX689B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A6_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK2_BIT_7_CHN_A		0x68A	//RX DQS PI Phase Control A6 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX68BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A6_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX68BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A6_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK2_BIT_0_CHN_A		0x68C	//RX DQS PI Phase Control A7 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX68DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX68DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A7_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK2_BIT_1_CHN_A		0x68E	//RX DQS PI Phase Control A7 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX68FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX68FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A7_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK2_BIT_2_CHN_A		0x690	//RX DQS PI Phase Control A7 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX691B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX691B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A7_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK2_BIT_3_CHN_A		0x692	//RX DQS PI Phase Control A7 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX693B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX693B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A7_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK2_BIT_4_CHN_A		0x694	//RX DQS PI Phase Control A7 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX695B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX695B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A7_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK2_BIT_5_CHN_A		0x696	//RX DQS PI Phase Control A7 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX697B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX697B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A7_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK2_BIT_6_CHN_A		0x698	//RX DQS PI Phase Control A7 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX699B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX699B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A7_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK2_BIT_7_CHN_A		0x69A	//RX DQS PI Phase Control A7 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX69BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A7_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX69BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A7_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK2_BIT_0_CHN_A		0x69C	//RX DQS PI Phase Control A8 RANK2 Bit 0 Channel A
    #define D0F3_D0F3_RX69DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS0P_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX69DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS0N_5_0_RK2			0x3F	//0/x/x/x PH_A8_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK2_BIT_1_CHN_A		0x69E	//RX DQS PI Phase Control A8 RANK2 Bit 1 Channel A
    #define D0F3_D0F3_RX69FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS1P_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX69FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS1N_5_0_RK2			0x3F	//0/x/x/x PH_A8_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK2_BIT_2_CHN_A		0x6A0	//RX DQS PI Phase Control A8 RANK2 Bit 2 Channel A
    #define D0F3_D0F3_RX6A1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS2P_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX6A1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS2N_5_0_RK2			0x3F	//0/x/x/x PH_A8_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK2_BIT_3_CHN_A		0x6A2	//RX DQS PI Phase Control A8 RANK2 Bit 3 Channel A
    #define D0F3_D0F3_RX6A3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS3P_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX6A3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS3N_5_0_RK2			0x3F	//0/x/x/x PH_A8_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK2_BIT_4_CHN_A		0x6A4	//RX DQS PI Phase Control A8 RANK2 Bit 4 Channel A
    #define D0F3_D0F3_RX6A5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS4P_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX6A5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS4N_5_0_RK2			0x3F	//0/x/x/x PH_A8_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK2_BIT_5_CHN_A		0x6A6	//RX DQS PI Phase Control A8 RANK2 Bit 5 Channel A
    #define D0F3_D0F3_RX6A7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS5P_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX6A7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS5N_5_0_RK2			0x3F	//0/x/x/x PH_A8_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK2_BIT_6_CHN_A		0x6A8	//RX DQS PI Phase Control A8 RANK2 Bit 6 Channel A
    #define D0F3_D0F3_RX6A9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS6P_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX6A9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS6N_5_0_RK2			0x3F	//0/x/x/x PH_A8_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK2_BIT_7_CHN_A		0x6AA	//RX DQS PI Phase Control A8 RANK2 Bit 7 Channel A
    #define D0F3_D0F3_RX6ABB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS7P_5_0_RK2			0x3F00	//0/x/x/x PH_A8_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX6ABB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS7N_5_0_RK2			0x3F	//0/x/x/x PH_A8_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK3_BIT_0_CHN_A		0x6AC	//RX DQS PI Phase Control A0 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX6ADB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A0_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX6ADB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A0_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK3_BIT_1_CHN_A		0x6AE	//RX DQS PI Phase Control A0 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX6AFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A0_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX6AFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A0_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK3_BIT_2_CHN_A		0x6B0	//RX DQS PI Phase Control A0 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX6B1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A0_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX6B1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A0_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK3_BIT_3_CHN_A		0x6B2	//RX DQS PI Phase Control A0 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX6B3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A0_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX6B3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A0_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK3_BIT_4_CHN_A		0x6B4	//RX DQS PI Phase Control A0 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX6B5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A0_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX6B5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A0_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK3_BIT_5_CHN_A		0x6B6	//RX DQS PI Phase Control A0 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX6B7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A0_DQS5P[5:0] : RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX6B7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A0_DQS5N[5:0] : RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK3_BIT_6_CHN_A		0x6B8	//RX DQS PI Phase Control A0 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX6B9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A0_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX6B9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A0_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A0_RANK3_BIT_7_CHN_A		0x6BA	//RX DQS PI Phase Control A0 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX6BBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A0_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX6BBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A0_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A0_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK3_BIT_0_CHN_A		0x6BC	//RX DQS PI Phase Control A1 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX6BDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX6BDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A1_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK3_BIT_1_CHN_A		0x6BE	//RX DQS PI Phase Control A1 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX6BFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX6BFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A1_DQS1N[5:0]: RX DQSN phase control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK3_BIT_2_CHN_A		0x6C0	//RX DQS PI Phase Control A1 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX6C1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX6C1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A1_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK3_BIT_3_CHN_A		0x6C2	//RX DQS PI Phase Control A1 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX6C3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX6C3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A1_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK3_BIT_4_CHN_A		0x6C4	//RX DQS PI Phase Control A1 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX6C5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX6C5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A1_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK3_BIT_5_CHN_A		0x6C6	//RX DQS PI Phase Control A1 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX6C7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX6C7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A1_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK3_BIT_6_CHN_A		0x6C8	//RX DQS PI Phase Control A1 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX6C9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX6C9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A1_DQS6N[5:0] : RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A1_RANK3_BIT_7_CHN_A		0x6CA	//RX DQS PI Phase Control A1 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX6CBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A1_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX6CBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A1_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A1_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK3_BIT_0_CHN_A		0x6CC	//RX DQS PI Phase Control A2 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX6CDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A2_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX6CDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A2_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK3_BIT_1_CHN_A		0x6CE	//RX DQS PI Phase Control A2 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX6CFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A2_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX6CFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A2_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK3_BIT_2_CHN_A		0x6D0	//RX DQS PI Phase Control A2 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX6D1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A2_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX6D1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A2_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK3_BIT_3_CHN_A		0x6D2	//RX DQS PI Phase Control A2 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX6D3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A2_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX6D3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A2_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK3_BIT_4_CHN_A		0x6D4	//RX DQS PI Phase Control A2 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX6D5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A2_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX6D5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A2_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK3_BIT_5_CHN_A		0x6D6	//RX DQS PI Phase Control A2 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX6D7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A2_DQS5P[5:0]: RX DQSP phase Control for DQ Bit 5
    #define D0F3_D0F3_RX6D7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A2_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK3_BIT_6_CHN_A		0x6D8	//RX DQS PI Phase Control A2 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX6D9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A2_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX6D9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A2_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A2_RANK3_BIT_7_CHN_A		0x6DA	//RX DQS PI Phase Control A2 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX6DBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A2_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX6DBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A2_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A2_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK3_BIT_0_CHN_A		0x6DC	//RX DQS PI Phase Control A3 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX6DDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX6DDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A3_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK3_BIT_1_CHN_A		0x6DE	//RX DQS PI Phase Control A3 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX6DFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DQS1P[5:0] : RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX6DFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A3_DQS1N[5:0] : RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK3_BIT_2_CHN_A		0x6E0	//RX DQS PI Phase Control A3 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX6E1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DQS2P[5:0] : RX DQSP phase Control for DQ Bit 2
    #define D0F3_D0F3_RX6E1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A3_DQS2N[5:0] : RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK3_BIT_3_CHN_A		0x6E2	//RX DQS PI Phase Control A3 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX6E3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX6E3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A3_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK3_BIT_4_CHN_A		0x6E4	//RX DQS PI Phase Control A3 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX6E5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX6E5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A3_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK3_BIT_5_CHN_A		0x6E6	//RX DQS PI Phase Control A3 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX6E7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DQS5P[5:0] : RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX6E7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A3_DQS5N[5:0] : RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK3_BIT_6_CHN_A		0x6E8	//RX DQS PI Phase Control A3 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX6E9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX6E9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A3_DQS6N[5:0]: RX DQSN Phase Control for DQ bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A3_RANK3_BIT_7_CHN_A		0x6EA	//RX DQS PI Phase Control A3 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX6EBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A3_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX6EBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A3_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A3_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK3_BIT_0_CHN_A		0x6EC	//RX DQS PI Phase Control A4 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX6EDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A4_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX6EDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A4_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK3_BIT_1_CHN_A		0x6EE	//RX DQS PI Phase Control A4 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX6EFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A4_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX6EFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A4_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK3_BIT_2_CHN_A		0x6F0	//RX DQS PI Phase Control A4 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX6F1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A4_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX6F1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A4_DQS2N[5:0]: RX DQSN Phase Control For DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK3_BIT_3_CHN_A		0x6F2	//RX DQS PI Phase Control A4 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX6F3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A4_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX6F3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A4_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK3_BIT_4_CHN_A		0x6F4	//RX DQS PI Phase Control A4 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX6F5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A4_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX6F5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A4_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK3_BIT_5_CHN_A		0x6F6	//RX DQS PI Phase Control A4 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX6F7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A4_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX6F7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A4_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK3_BIT_6_CHN_A		0x6F8	//RX DQS PI Phase Control A4 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX6F9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A4_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX6F9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A4_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A4_RANK3_BIT_7_CHN_A		0x6FA	//RX DQS PI Phase Control A4 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX6FBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A4_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX6FBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A4_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A4_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK3_BIT_0_CHN_A		0x6FC	//RX DQS PI Phase Control A5 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX6FDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX6FDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A5_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK3_BIT_1_CHN_A		0x6FE	//RX DQS PI Phase Control A5 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX6FFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX6FFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A5_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK3_BIT_2_CHN_A		0x700	//RX DQS PI Phase Control A5 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX701B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX701B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A5_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK3_BIT_3_CHN_A		0x702	//RX DQS PI Phase Control A5 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX703B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX703B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A5_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK3_BIT_4_CHN_A		0x704	//RX DQS PI Phase Control A5 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX705B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX705B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A5_DQS4N[5:0] : RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK3_BIT_5_CHN_A		0x706	//RX DQS PI Phase Control A5 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX707B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DQS5P[5:0] : RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX707B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A5_DQS5N[5:0] : RX DQSN phase control for DQ bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK3_BIT_6_CHN_A		0x708	//RX DQS PI Phase Control A5 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX709B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX709B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A5_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A5_RANK3_BIT_7_CHN_A		0x70A	//RX DQS PI Phase Control A5 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX70BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A5_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX70BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A5_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A5_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK3_BIT_0_CHN_A		0x70C	//RX DQS PI Phase Control A6 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX70DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A6_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX70DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A6_DQS0N[5:0]: RX DQSN Phase Control for DQ bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK3_BIT_1_CHN_A		0x70E	//RX DQS PI Phase Control A6 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX70FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A6_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX70FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A6_DQS1N[5:0] : RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK3_BIT_2_CHN_A		0x710	//RX DQS PI Phase Control A6 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX711B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A6_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX711B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A6_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK3_BIT_3_CHN_A		0x712	//RX DQS PI Phase Control A6 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX713B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A6_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX713B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A6_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK3_BIT_4_CHN_A		0x714	//RX DQS PI PHASE Control A6 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX715B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A6_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX715B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A6_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK3_BIT_5_CHN_A		0x716	//RX DQS PI Phase Control A6 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX717B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A6_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX717B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A6_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK3_BIT_6_CHN_A		0x718	//RX DQS PI Phase Control A6 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX719B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A6_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX719B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A6_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A6_RANK3_BIT_7_CHN_A		0x71A	//RX DQS PI Phase Control A6 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX71BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A6_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX71BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A6_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A6_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK3_BIT_0_CHN_A		0x71C	//RX DQS PI Phase Control A7 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX71DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX71DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A7_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK3_BIT_1_CHN_A		0x71E	//RX DQS PI Phase Control A7 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX71FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX71FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A7_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK3_BIT_2_CHN_A		0x720	//RX DQS PI Phase Control A7 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX721B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX721B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A7_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK3_BIT_3_CHN_A		0x722	//RX DQS PI Phase Control A7 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX723B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX723B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A7_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK3_BIT_4_CHN_A		0x724	//RX DQS PI Phase Control A7 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX725B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX725B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A7_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK3_BIT_5_CHN_A		0x726	//RX DQS PI Phase Control A7 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX727B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DQS5P[5:0] : RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX727B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A7_DQS5N[5:0] : RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK3_BIT_6_CHN_A		0x728	//RX DQS PI Phase Control A7 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX729B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX729B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A7_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A7_RANK3_BIT_7_CHN_A		0x72A	//RX DQS PI Phase Control A7 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX72BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A7_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX72BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A7_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A7_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK3_BIT_0_CHN_A		0x72C	//RX DQS PI Phase Control A8 RANK3 Bit 0 Channel A
    #define D0F3_D0F3_RX72DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS0P_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX72DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS0N_5_0_RK3			0x3F	//0/x/x/x PH_A8_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK3_BIT_1_CHN_A		0x72E	//RX DQS PI Phase Control A8 RANK3 Bit 1 Channel A
    #define D0F3_D0F3_RX72FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS1P_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX72FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS1N_5_0_RK3			0x3F	//0/x/x/x PH_A8_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK3_BIT_2_CHN_A		0x730	//RX DQS PI Phase Control A8 RANK3 Bit 2 Channel A
    #define D0F3_D0F3_RX731B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS2P_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX731B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS2N_5_0_RK3			0x3F	//0/x/x/x PH_A8_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK3_BIT_3_CHN_A		0x732	//RX DQS PI Phase Control A8 RANK3 Bit 3 Channel A
    #define D0F3_D0F3_RX733B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS3P_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX733B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS3N_5_0_RK3			0x3F	//0/x/x/x PH_A8_DQS3N[5:0]: RX DQSN Phase Control For DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK3_BIT_4_CHN_A		0x734	//RX DQS PI Phase Control A8 RANK3 Bit 4 Channel A
    #define D0F3_D0F3_RX735B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS4P_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX735B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS4N_5_0_RK3			0x3F	//0/x/x/x PH_A8_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK3_BIT_5_CHN_A		0x736	//RX DQS PI Phase Control A8 RANK3 Bit 5 Channel A
    #define D0F3_D0F3_RX737B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS5P_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX737B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS5N_5_0_RK3			0x3F	//0/x/x/x PH_A8_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK3_BIT_6_CHN_A		0x738	//RX DQS PI Phase Control A8 RANK3 Bit 6 Channel A
    #define D0F3_D0F3_RX739B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS6P_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX739B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS6N_5_0_RK3			0x3F	//0/x/x/x PH_A8_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_A8_RANK3_BIT_7_CHN_A		0x73A	//RX DQS PI Phase Control A8 RANK3 Bit 7 Channel A
    #define D0F3_D0F3_RX73BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS7P_5_0_RK3			0x3F00	//0/x/x/x PH_A8_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX73BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_A8_DQS7N_5_0_RK3			0x3F	//0/x/x/x PH_A8_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK4_BIT_0_CHN_B		0x73C	//RX DQS PI Phase Control B0 RANK4 Bit 0 Channel B
    #define D0F3_PIEN_B_DQS			BIT15	//1b/x/x/x RX DQS Phase Control Enable
    #define D0F3_PIEN_B_DQS_X4			BIT14	//1b/x/x/x RX DQS Phase Control Enable fro High 4 bit
    #define D0F3_RPH_B0_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B0_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX73DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B0_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK4_BIT_1_CHN_B		0x73E	//RX DQS PI Phase Control B0 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX73FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B0_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX73FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B0_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK4_BIT_2_CHN_B		0x740	//RX DQS PI Phase Control B0 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX741B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B0_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX741B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B0_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK4_BIT_3_CHN_B		0x742	//RX DQS PI Phase Control B0 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX743B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B0_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX743B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B0_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK4_BIT_4_CHN_B		0x744	//RX DQS PI Phase Control B0 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX745B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B0_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX745B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B0_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK4_BIT_5_CHN_B		0x746	//RX DQS PI Phase Control B0 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX747B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B0_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX747B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B0_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK4_BIT_6_CHN_B		0x748	//RX DQS PI Phase Control B0 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX749B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B0_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX749B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B0_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK4_BIT_7_CHN_B		0x74A	//RX DQS PI Phase Control B0 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX74BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B0_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX74BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B0_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK4_BIT_0_CHN_B		0x74C	//RX DQS PI Phase Control B1 RANK4 Bit 0 Channel B
    #define D0F3_D0F3_RX74DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX74DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B1_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK4_BIT_1_CHN_B		0x74E	//RX DQS PI Phase Control B1 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX74FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX74FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B1_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK4_BIT_2_CHN_B		0x750	//RX DQS PI Phase Control B1 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX751B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX751B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B1_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK4_BIT_3_CHN_B		0x752	//RX DQS PI Phase Control B1 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX753B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX753B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B1_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK4_BIT_4_CHN_B		0x754	//RX DQS PI Phase Control B1 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX755B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX755B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B1_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK4_BIT_5_CHN_B		0x756	//RX DQS PI Phase Control B1 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX757B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX757B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B1_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK4_BIT_6_CHN_B		0x758	//RX DQS PI Phase Control B1 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX759B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX759B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B1_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK4_BIT_7_CHN_B		0x75A	//RX DQS PI Phase Control B1 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX75BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B1_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX75BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B1_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK4_BIT_0_CHN_B		0x75C	//RX DQS PI Phase Control B2 RANK4 Bit 0 Channel B
    #define D0F3_D0F3_RX75DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B2_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX75DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B2_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK4_BIT_1_CHN_B		0x75E	//RX DQS PI Phase Control B2 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX75FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B2_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX75FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B2_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK4_BIT_2_CHN_B		0x760	//RX DQS PI Phase Control B2 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX761B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B2_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX761B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B2_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK4_BIT_3_CHN_B		0x762	//RX DQS PI Phase Control B2 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX763B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B2_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX763B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B2_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK4_BIT_4_CHN_B		0x764	//RX DQS PI Phase Control B2 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX765B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B2_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX765B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B2_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK4_BIT_5_CHN_B		0x766	//RX DQS PI Phase Control B2 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX767B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B2_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX767B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B2_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK4_BIT_6_CHN_B		0x768	//RX DQS PI Phase Control B2 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX769B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B2_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX769B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B2_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK4_BIT_7_CHN_B		0x76A	//RX DQS PI Phase Control B2 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX76BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B2_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX76BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B2_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK4_BIT_0_CHN_B		0x76C	//RX DQS PI Phase Control B3 RANK4 Bit 0 Channel B
    #define D0F3_D0F3_RX76DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX76DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B3_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK4_BIT_1_CHN_B		0x76E	//RX DQS PI Phase Control B3 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX76FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX76FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B3_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK4_BIT_2_CHN_B		0x770	//RX DQS PI Phase Control B3 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX771B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX771B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B3_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK4_BIT_3_CHN_B		0x772	//RX DQS PI Phase Control B3 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX773B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX773B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B3_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK4_BIT_4_CHN_B		0x774	//RX DQS PI Phase Control B3 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX775B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX775B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B3_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK4_BIT_5_CHN_B		0x776	//RX DQS PI Phase Control B3 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX777B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DQS5P[5:0]: RX DQSP Phase Control for DQ bit 5
    #define D0F3_D0F3_RX777B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B3_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK4_BIT_6_CHN_B		0x778	//RX DQS PI Phase Control B3 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX779B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX779B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B3_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK4_BIT_7_CHN_B		0x77A	//RX DQS PI Phase Control B3 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX77BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B3_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX77BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B3_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK4_BIT_0_CHN_B		0x77C	//RX DQS PI Phase Control B4 RANK4 Bit 0 Channel B
    #define D0F3_D0F3_RX77DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B4_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX77DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B4_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK4_BIT_1_CHN_B		0x77E	//RX DQS PI Phase Control B4 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX77FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B4_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX77FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B4_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK4_BIT_2_CHN_B		0x780	//RX DQS PI Phase Control B4 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX781B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B4_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX781B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B4_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK4_BIT_3_CHN_B		0x782	//RX DQS PI Phase Control B4 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX783B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B4_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX783B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B4_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK4_BIT_4_CHN_B		0x784	//RX DQS PI Phase Control B4 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX785B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B4_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX785B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B4_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK4_BIT_5_CHN_B		0x786	//RX DQS PI Phase Control B4 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX787B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B4_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX787B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B4_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK4_BIT_6_CHN_B		0x788	//RX DQS PI Phase Control B4 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX789B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B4_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX789B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B4_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK4_BIT_7_CHN_B		0x78A	//RX DQS PI Phase Control B4 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX78BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B4_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX78BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B4_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK4_BIT_0_CHN_B		0x78C	//RX DQS PI Phase Control B5 RANK4 Bit 0 Channel B
    #define D0F3_D0F3_RX78DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX78DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B5_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK4_BIT_1_CHN_B		0x78E	//RX DQS PI Phase Control B5 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX78FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX78FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B5_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK4_BIT_2_CHN_B		0x790	//RX DQS PI Phase Control B5 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX791B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX791B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B5_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK4_BIT_3_CHN_B		0x792	//RX DQS PI Phase Control B5 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX793B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX793B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B5_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK4_BIT_4_CHN_B		0x794	//RX DQS PI Phase Control B5 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX795B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX795B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B5_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK4_BIT_5_CHN_B		0x796	//RX DQS PI Phase Control B5 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX797B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX797B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B5_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK4_BIT_6_CHN_B		0x798	//RX DQS PI Phase Control B5 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX799B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX799B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B5_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK4_BIT_7_CHN_B		0x79A	//RX DQS PI Phase Control B5 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX79BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B5_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX79BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B5_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK4_BIT_0_CHN_B		0x79C	//RX DQS PI Phase Control B6 RANK4 Bit 0 Channel B
    #define D0F3_D0F3_RX79DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B6_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX79DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B6_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK4_BIT_1_CHN_B		0x79E	//RX DQS PI Phase Control B6 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX79FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B6_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX79FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B6_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK4_BIT_2_CHN_B		0x7A0	//RX DQS PI Phase Control B6 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX7A1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B6_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX7A1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B6_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK4_BIT_3_CHN_B		0x7A2	//RX DQS PI Phase Control B6 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX7A3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B6_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX7A3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B6_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK4_BIT_4_CHN_B		0x7A4	//RX DQS PI Phase Control B6 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX7A5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B6_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX7A5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B6_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK4_BIT_5_CHN_B		0x7A6	//RX DQS PI Phase Control B6 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX7A7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B6_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX7A7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B6_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK4_BIT_6_CHN_B		0x7A8	//RX DQS PI Phase Control B6 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX7A9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B6_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX7A9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B6_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK4_BIT_7_CHN_B		0x7AA	//RX DQS PI Phase Control B6 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX7ABB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B6_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX7ABB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B6_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK4_BIT_0_CHN_B		0x7AC	//RX DQS PI Phase Control B7 RANK4 Bit 0 Channel B
    #define D0F3_D0F3_RX7ADB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX7ADB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B7_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK4_BIT_1_CHN_B		0x7AE	//RX DQS PI Phase Control B7 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX7AFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX7AFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B7_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK4_BIT_2_CHN_B		0x7B0	//RX DQS PI Phase Control B7 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX7B1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DQS2P[5:0]: RX DQSP Phase Control For DQ Bit 2
    #define D0F3_D0F3_RX7B1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B7_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK4_BIT_3_CHN_B		0x7B2	//RX DQS PI Phase Control B7 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX7B3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX7B3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B7_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK4_BIT_4_CHN_B		0x7B4	//RX DQS PI Phase Control B7 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX7B5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX7B5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B7_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK4_BIT_5_CHN_B		0x7B6	//RX DQS PI Phase Control B7 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX7B7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX7B7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B7_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK4_BIT_6_CHN_B		0x7B8	//RX DQS PI Phase Control B7 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX7B9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX7B9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B7_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK4_BIT_7_CHN_B		0x7BA	//RX DQS PI Phase Control B7 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX7BBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B7_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX7BBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B7_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK4_BIT_0_CHN_B		0x7BC	//RX DQS PI Phase Control B8 RANK4 Bit 0 Channel B
    #define D0F3_D0F3_RX7BDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS0P_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX7BDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS0N_5_0_RK4			0x3F	//0/x/x/x PH_B8_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK4_BIT_1_CHN_B		0x7BE	//RX DQS PI Phase Control B8 RANK4 Bit 1 Channel B
    #define D0F3_D0F3_RX7BFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS1P_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX7BFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS1N_5_0_RK4			0x3F	//0/x/x/x PH_B8_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK4_BIT_2_CHN_B		0x7C0	//RX DQS PI Phase Control B8 RANK4 Bit 2 Channel B
    #define D0F3_D0F3_RX7C1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS2P_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX7C1B_7_6			(BIT6 + BIT7)	//0/x/x/X Reserved
    #define D0F3_RPH_B8_DQS2N_5_0_RK4			0x3F	//0/x/x/x PH_B8_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK4_BIT_3_CHN_B		0x7C2	//RX DQS PI Phase Control B8 RANK4 Bit 3 Channel B
    #define D0F3_D0F3_RX7C3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS3P_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX7C3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS3N_5_0_RK4			0x3F	//0/x/x/x PH_B8_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK4_BIT_4_CHN_B		0x7C4	//RX DQS PI Phase Control B8 RANK4 Bit 4 Channel B
    #define D0F3_D0F3_RX7C5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS4P_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX7C5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS4N_5_0_RK4			0x3F	//0/x/x/x PH_B8_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK4_BIT_5_CHN_B		0x7C6	//RX DQS PI Phase Control B8 RANK4 Bit 5 Channel B
    #define D0F3_D0F3_RX7C7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS5P_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX7C7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS5N_5_0_RK4			0x3F	//0/x/x/x PH_B8_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK4_BIT_6_CHN_B		0x7C8	//RX DQS PI Phase Control B8 RANK4 Bit 6 Channel B
    #define D0F3_D0F3_RX7C9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS6P_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX7C9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS6N_5_0_RK4			0x3F	//0/x/x/x PH_B8_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK4_BIT_7_CHN_B		0x7CA	//RX DQS PI Phase Control B8 RANK4 Bit 7 Channel B
    #define D0F3_D0F3_RX7CBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS7P_5_0_RK4			0x3F00	//0/x/x/x PH_B8_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX7CBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS7N_5_0_RK4			0x3F	//0/x/x/x PH_B8_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK5_BIT_0_CHN_B		0x7CC	//RX DQS PI Phase Control B0 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX7CDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B0_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX7CDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B0_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK5_BIT_1_CHN_B		0x7CE	//RX DQS PI Phase Control B0 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX7CFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B0_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX7CFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B0_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK5_BIT_2_CHN_B		0x7D0	//RX DQS PI Phase Control B0 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX7D1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B0_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX7D1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B0_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK5_BIT_3_CHN_B		0x7D2	//RX DQS PI Phase Control B0 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX7D3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B0_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX7D3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B0_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK5_BIT_4_CHN_B		0x7D4	//RX DQS PI Phase Control B0 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX7D5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B0_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX7D5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B0_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK5_BIT_5_CHN_B		0x7D6	//RX DQS PI Phase Control B0 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX7D7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B0_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX7D7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B0_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK5_BIT_6_CHN_B		0x7D8	//RX DQS PI Phase Control B0 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX7D9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B0_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX7D9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B0_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK5_BIT_7_CHN_B		0x7DA	//RX DQS PI Phase Control B0 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX7DBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B0_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX7DBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B0_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK5_BIT_0_CHN_B		0x7DC	//RX DQS PI Phase Control B1 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX7DDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX7DDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B1_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK5_BIT_1_CHN_B		0x7DE	//RX DQS PI Phase Control B1 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX7DFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX7DFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B1_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK5_BIT_2_CHN_B		0x7E0	//RX DQS PI Phase Control B1 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX7E1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX7E1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B1_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK5_BIT_3_CHN_B		0x7E2	//RX DQS PI Phase Control B1 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX7E3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX7E3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B1_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK5_BIT_4_CHN_B		0x7E4	//RX DQS PI Phase Control B1 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX7E5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX7E5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B1_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK5_BIT_5_CHN_B		0x7E6	//RX DQS PI Phase Control B1 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX7E7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX7E7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B1_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK5_BIT_6_CHN_B		0x7E8	//RX DQS PI Phase Control B1 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX7E9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX7E9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B1_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK5_BIT_7_CHN_B		0x7EA	//RX DQS PI Phase Control B1 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX7EBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B1_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX7EBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B1_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK5_BIT_0_CHN_B		0x7EC	//RX DQS PI Phase Control B2 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX7EDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B2_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX7EDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B2_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK5_BIT_1_CHN_B		0x7EE	//RX DQS PI Phase Control B2 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX7EFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B2_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX7EFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B2_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK5_BIT_2_CHN_B		0x7F0	//RX DQS PI Phase Control B2 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX7F1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B2_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX7F1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B2_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK5_BIT_3_CHN_B		0x7F2	//RX DQS PI Phase Control B2 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX7F3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B2_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX7F3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B2_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK5_BIT_4_CHN_B		0x7F4	//RX DQS PI Phase Control B2 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX7F5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B2_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX7F5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B2_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK5_BIT_5_CHN_B		0x7F6	//RX DQS PI Phase Control B2 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX7F7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B2_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX7F7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B2_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK5_BIT_6_CHN_B		0x7F8	//RX DQS PI Phase Control B2 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX7F9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B2_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX7F9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B2_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK5_BIT_7_CHN_B		0x7FA	//RX DQS PI Phase Control B2 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX7FBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B2_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX7FBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B2_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK5_BIT_0_CHN_B		0x7FC	//RX DQS PI Phase Control B3 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX7FDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX7FDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B3_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK5_BIT_1_CHN_B		0x7FE	//RX DQS PI Phase Control B3 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX7FFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX7FFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B3_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK5_BIT_2_CHN_B		0x800	//RX DQS PI Phase Control B3 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX801B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DQS2P[5:0]: RX DQSP Phase Control For DQ Bit 2
    #define D0F3_D0F3_RX801B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B3_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK5_BIT_3_CHN_B		0x802	//RX DQS PI Phase Control B3 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX803B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX803B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B3_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK5_BIT_4_CHN_B		0x804	//RX DQS PI Phase Control B3 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX805B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX805B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B3_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK5_BIT_5_CHN_B		0x806	//RX DQS PI Phase Control B3 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX807B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX807B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B3_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK5_BIT_6_CHN_B		0x808	//RX DQS PI Phase Control B3 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX809B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX809B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B3_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK5_BIT_7_CHN_B		0x80A	//RX DQS PI Phase Control B3 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX80BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B3_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX80BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B3_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK5_BIT_0_CHN_B		0x80C	//RX DQS PI Phase Control B4 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX80DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B4_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX80DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B4_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK5_BIT_1_CHN_B		0x80E	//RX DQS PI Phase Control B4 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX80FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B4_DQS1P[5:0]: RX DQSP Phase Control for DQ bit 1
    #define D0F3_D0F3_RX80FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B4_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK5_BIT_2_CHN_B		0x810	//RX DQS PI Phase Control B4 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX811B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B4_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX811B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B4_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK5_BIT_3_CHN_B		0x812	//RX DQS PI Phase Control B4 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX813B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B4_DQS3P[5:0] : RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX813B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B4_DQS3N[5:0] : RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK5_BIT_4_CHN_B		0x814	//RX DQS PI Phase Control B4 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX815B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B4_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX815B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B4_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK5_BIT_5_CHN_B		0x816	//RX DQS PI Phase Control B4 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX817B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B4_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX817B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B4_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK5_BIT_6_CHN_B		0x818	//RX DQS PI Phase Control B4 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX819B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B4_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX819B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B4_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK5_BIT_7_CHN_B		0x81A	//RX DQS PI Phase Control B4 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX81BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B4_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX81BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B4_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK5_BIT_0_CHN_B		0x81C	//RX DQS PI Phase Control B5 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX81DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX81DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B5_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK5_BIT_1_CHN_B		0x81E	//RX DQS PI Phase Control B5 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX81FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX81FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B5_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK5_BIT_2_CHN_B		0x820	//RX DQS PI Phase Control B5 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX821B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX821B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B5_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK5_BIT_3_CHN_B		0x822	//RX DQS PI Phase Control B5 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX823B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX823B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B5_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK5_BIT_4_CHN_B		0x824	//RX DQS PI Phase Control B5 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX825B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX825B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B5_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK5_BIT_5_CHN_B		0x826	//RX DQS PI Phase Control B5 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX827B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX827B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B5_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK5_BIT_6_CHN_B		0x828	//RX DQS PI Phase Control B5 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX829B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX829B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B5_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK5_BIT_7_CHN_B		0x82A	//RX DQS PI Phase Control B5 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX82BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B5_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX82BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B5_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK5_BIT_0_CHN_B		0x82C	//RX DQS PI Phase Control B6 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX82DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B6_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX82DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B6_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK5_BIT_1_CHN_B		0x82E	//RX DQS PI Phase Control B6 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX82FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B6_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX82FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B6_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK5_BIT_2_CHN_B		0x830	//RX DQS PI Phase Control B6 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX831B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B6_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX831B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B6_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK5_BIT_3_CHN_B		0x832	//RX DQS PI Phase Control B6 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX833B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B6_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX833B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B6_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK5_BIT_4_CHN_B		0x834	//RX DQS PI Phase Control B6 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX835B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B6_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX835B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B6_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK5_BIT_5_CHN_B		0x836	//RX DQS PI Phase Control B6 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX837B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B6_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX837B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B6_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK5_BIT_6_CHN_B		0x838	//RX DQS PI Phase Control B6 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX839B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B6_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX839B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B6_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK5_BIT_7_CHN_B		0x83A	//RX DQS PI Phase Control B6 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX83BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B6_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX83BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B6_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK5_BIT_0_CHN_B		0x83C	//RX DQS PI Phase Control B7 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX83DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX83DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B7_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK5_BIT_1_CHN_B		0x83E	//RX DQS PI Phase Control B7 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX83FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX83FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B7_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK5_BIT_2_CHN_B		0x840	//RX DQS PI Phase Control B7 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX841B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX841B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B7_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK5_BIT_3_CHN_B		0x842	//RX DQS PI Phase Control B7 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX843B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX843B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B7_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK5_BIT_4_CHN_B		0x844	//RX DQS PI Phase Control B7 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX845B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX845B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B7_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK5_BIT_5_CHN_B		0x846	//RX DQS PI Phase Control B7 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX847B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX847B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B7_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK5_BIT_6_CHN_B		0x848	//RX DQS PI Phase Control B7 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX849B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX849B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B7_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK5_BIT_7_CHN_B		0x84A	//RX DQS PI Phase Control B7 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX84BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B7_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX84BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B7_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK5_BIT_0_CHN_B		0x84C	//RX DQS PI Phase Control B8 RANK5 Bit 0 Channel B
    #define D0F3_D0F3_RX84DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS0P_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX84DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS0N_5_0_RK5			0x3F	//0/x/x/x PH_B8_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK5_BIT_1_CHN_B		0x84E	//RX DQS PI Phase Control B8 RANK5 Bit 1 Channel B
    #define D0F3_D0F3_RX84FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS1P_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX84FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS1N_5_0_RK5			0x3F	//0/x/x/x PH_B8_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK5_BIT_2_CHN_B		0x850	//RX DQS PI Phase Control B8 RANK5 Bit 2 Channel B
    #define D0F3_D0F3_RX851B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS2P_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX851B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS2N_5_0_RK5			0x3F	//0/x/x/x PH_B8_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK5_BIT_3_CHN_B		0x852	//RX DQS PI Phase Control B8 RANK5 Bit 3 Channel B
    #define D0F3_D0F3_RX853B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS3P_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX853B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS3N_5_0_RK5			0x3F	//0/x/x/x PH_B8_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK5_BIT_4_CHN_B		0x854	//RX DQS PI Phase Control B8 RANK5 Bit 4 Channel B
    #define D0F3_D0F3_RX855B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS4P_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX855B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS4N_5_0_RK5			0x3F	//0/x/x/x PH_B8_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK5_BIT_5_CHN_B		0x856	//RX DQS PI Phase Control B8 RANK5 Bit 5 Channel B
    #define D0F3_D0F3_RX857B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS5P_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX857B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS5N_5_0_RK5			0x3F	//0/x/x/x PH_B8_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK5_BIT_6_CHN_B		0x858	//RX DQS PI Phase Control B8 RANK5 Bit 6 Channel B
    #define D0F3_D0F3_RX859B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS6P_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX859B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS6N_5_0_RK5			0x3F	//0/x/x/x PH_B8_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK5_BIT_7_CHN_B		0x85A	//RX DQS PI Phase Control B8 RANK5 Bit 7 Channel B
    #define D0F3_D0F3_RX85BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS7P_5_0_RK5			0x3F00	//0/x/x/x PH_B8_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX85BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS7N_5_0_RK5			0x3F	//0/x/x/x PH_B8_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK6_BIT_0_CHN_B		0x85C	//RX DQS PI Phase Control B0 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX85DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B0_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX85DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B0_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK6_BIT_1_CHN_B		0x85E	//RX DQS PI Phase Control B0 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX85FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B0_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX85FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B0_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK6_BIT_2_CHN_B		0x860	//RX DQS PI Phase Control B0 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX861B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B0_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX861B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B0_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK6_BIT_3_CHN_B		0x862	//RX DQS PI Phase Control B0 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX863B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B0_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX863B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B0_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK6_BIT_4_CHN_B		0x864	//RX DQS PI Phase Control B0 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX865B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B0_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX865B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B0_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK6_BIT_5_CHN_B		0x866	//RX DQS PI Phase Control B0 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX867B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B0_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX867B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B0_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK6_BIT_6_CHN_B		0x868	//RX DQS PI Phase Control B0 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX869B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B0_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX869B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B0_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK6_BIT_7_CHN_B		0x86A	//RX DQS PI Phase Control B0 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX86BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B0_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX86BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B0_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK6_BIT_0_CHN_B		0x86C	//RX DQS PI Phase Control B1 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX86DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX86DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B1_DQS0N[5:0]: RX DQSN Phase Control for DQ bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK6_BIT_1_CHN_B		0x86E	//RX DQS PI Phase Control B1 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX86FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX86FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B1_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK6_BIT_2_CHN_B		0x870	//RX DQS PI Phase Control B1 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX871B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX871B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B1_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK6_BIT_3_CHN_B		0x872	//RX DQS PI Phase Control B1 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX873B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX873B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B1_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK6_BIT_4_CHN_B		0x874	//RX DQS PI Phase Control B1 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX875B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX875B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B1_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK6_BIT_5_CHN_B		0x876	//RX DQS PI Phase Control B1 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX877B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX877B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B1_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK6_BIT_6_CHN_B		0x878	//RX DQS PI Phase Control B1 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX879B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX879B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B1_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK6_BIT_7_CHN_B		0x87A	//RX DQS PI Phase Control B1 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX87BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B1_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX87BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B1_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK6_BIT_0_CHN_B		0x87C	//RX DQS PI Phase Control B2 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX87DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B2_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX87DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B2_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK6_BIT_1_CHN_B		0x87E	//RX DQS PI Phase Control B2 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX87FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B2_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX87FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B2_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK6_BIT_2_CHN_B		0x880	//RX DQS PI Phase Control B2 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX881B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B2_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX881B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B2_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK6_BIT_3_CHN_B		0x882	//RX DQS PI Phase Control B2 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX883B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B2_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX883B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B2_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK6_BIT_4_CHN_B		0x884	//RX DQS PI Phase Control B2 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX885B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B2_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX885B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B2_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK6_BIT_5_CHN_B		0x886	//RX DQS PI Phase Control B2 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX887B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B2_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX887B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B2_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK6_BIT_6_CHN_B		0x888	//RX DQS PI Phase Control B2 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX889B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B2_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX889B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B2_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK6_BIT_7_CHN_B		0x88A	//RX DQS PI Phase Control B2 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX88BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B2_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX88BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B2_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK6_BIT_0_CHN_B		0x88C	//RX DQS PI Phase Control B3 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX88DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX88DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B3_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK6_BIT_1_CHN_B		0x88E	//RX DQS PI Phase Control B3 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX88FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX88FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B3_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK6_BIT_2_CHN_B		0x890	//RX DQS PI Phase Control B3 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX891B_15_14			(BIT14 + BIT15)	//0/x/x/X Reserved
    #define D0F3_RPH_B3_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX891B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B3_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK6_BIT_3_CHN_B		0x892	//RX DQS PI Phase Control B3 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX893B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX893B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B3_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK6_BIT_4_CHN_B		0x894	//RX DQS PI Phase Control B3 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX895B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX895B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B3_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK6_BIT_5_CHN_B		0x896	//RX DQS PI Phase Control B3 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX897B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX897B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B3_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK6_BIT_6_CHN_B		0x898	//RX DQS PI Phase Control B3 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX899B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX899B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B3_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK6_BIT_7_CHN_B		0x89A	//RX DQS PI Phase Control B3 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX89BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B3_DQS7P[5:0] : RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX89BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B3_DQS7N[5:0] : RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK6_BIT_0_CHN_B		0x89C	//RX DQS PI Phase Control B4 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX89DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B4_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX89DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B4_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK6_BIT_1_CHN_B		0x89E	//RX DQS PI Phase Control B4 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX89FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B4_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX89FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B4_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK6_BIT_2_CHN_B		0x8A0	//RX DQS PI Phase Control B4 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX8A1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B4_DQS2P[5:0]: RX DQSP phase control for DQ Bit 2
    #define D0F3_D0F3_RX8A1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B4_DQS2N[5:0]: RX DQSN phase control for DQ bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK6_BIT_3_CHN_B		0x8A2	//RX DQS PI Phase Control B4 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX8A3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B4_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX8A3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B4_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK6_BIT_4_CHN_B		0x8A4	//RX DQS PI Phase Control B4 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX8A5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B4_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX8A5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B4_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK6_BIT_5_CHN_B		0x8A6	//RX DQS PI Phase Control B4 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX8A7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B4_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX8A7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B4_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK6_BIT_6_CHN_B		0x8A8	//RX DQS PI Phase Control B4 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX8A9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B4_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX8A9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B4_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK6_BIT_7_CHN_B		0x8AA	//RX DQS PI Phase Control B4 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX8ABB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B4_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX8ABB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B4_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK6_BIT_0_CHN_B		0x8AC	//RX DQS PI Phase Control B5 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX8ADB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX8ADB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B5_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK6_BIT_1_CHN_B		0x8AE	//RX DQS PI Phase Control B5 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX8AFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX8AFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B5_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK6_BIT_2_CHN_B		0x8B0	//RX DQS PI Phase Control B5 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX8B1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX8B1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B5_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK6_BIT_3_CHN_B		0x8B2	//RX DQS PI Phase Control B5 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX8B3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX8B3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B5_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK6_BIT_4_CHN_B		0x8B4	//RX DQS PI Phase Control B5 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX8B5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX8B5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B5_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK6_BIT_5_CHN_B		0x8B6	//RX DQS PI Phase Control B5 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX8B7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX8B7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B5_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK6_BIT_6_CHN_B		0x8B8	//RX DQS PI Phase Control B5 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX8B9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX8B9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B5_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK6_BIT_7_CHN_B		0x8BA	//RX DQS PI Phase Control B5 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX8BBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B5_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX8BBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B5_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK6_BIT_0_CHN_B		0x8BC	//RX DQS PI Phase Control B6 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX8BDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B6_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX8BDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B6_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK6_BIT_1_CHN_B		0x8BE	//RX DQS PI Phase Control B6 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX8BFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B6_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX8BFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B6_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK6_BIT_2_CHN_B		0x8C0	//RX DQS PI Phase Control B6 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX8C1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B6_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX8C1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B6_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK6_BIT_3_CHN_B		0x8C2	//RX DQS PI Phase Control B6 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX8C3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B6_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX8C3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B6_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK6_BIT_4_CHN_B		0x8C4	//RX DQS PI Phase Control B6 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX8C5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B6_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX8C5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B6_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK6_BIT_5_CHN_B		0x8C6	//RX DQS PI Phase Control B6 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX8C7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B6_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX8C7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B6_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK6_BIT_6_CHN_B		0x8C8	//RX DQS PI Phase Control B6 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX8C9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B6_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX8C9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B6_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK6_BIT_7_CHN_B		0x8CA	//RX DQS PI Phase Control B6 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX8CBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B6_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX8CBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B6_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK6_BIT_0_CHN_B		0x8CC	//RX DQS PI Phase Control B7 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX8CDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX8CDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B7_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK6_BIT_1_CHN_B		0x8CE	//RX DQS PI Phase Control B7 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX8CFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX8CFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B7_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK6_BIT_2_CHN_B		0x8D0	//RX DQS PI Phase Control B7 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX8D1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX8D1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B7_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK6_BIT_3_CHN_B		0x8D2	//RX DQS PI Phase Control B7 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX8D3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX8D3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B7_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK6_BIT_4_CHN_B		0x8D4	//RX DQS PI Phase Control B7 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX8D5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX8D5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B7_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK6_BIT_5_CHN_B		0x8D6	//RX DQS PI Phase Control B7 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX8D7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX8D7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B7_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK6_BIT_6_CHN_B		0x8D8	//RX DQS PI Phase Control B7 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX8D9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX8D9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B7_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK6_BIT_7_CHN_B		0x8DA	//RX DQS PI Phase Control B7 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX8DBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B7_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX8DBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B7_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK6_BIT_0_CHN_B		0x8DC	//RX DQS PI Phase Control B8 RANK6 Bit 0 Channel B
    #define D0F3_D0F3_RX8DDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS0P_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX8DDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS0N_5_0_RK6			0x3F	//0/x/x/x PH_B8_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK6_BIT_1_CHN_B		0x8DE	//RX DQS PI Phase Control B8 RANK6 Bit 1 Channel B
    #define D0F3_D0F3_RX8DFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS1P_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX8DFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS1N_5_0_RK6			0x3F	//0/x/x/x PH_B8_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK6_BIT_2_CHN_B		0x8E0	//RX DQS PI Phase Control B8 RANK6 Bit 2 Channel B
    #define D0F3_D0F3_RX8E1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS2P_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX8E1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS2N_5_0_RK6			0x3F	//0/x/x/x PH_B8_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK6_BIT_3_CHN_B		0x8E2	//RX DQS PI Phase Control B8 RANK6 Bit 3 Channel B
    #define D0F3_D0F3_RX8E3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS3P_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX8E3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS3N_5_0_RK6			0x3F	//0/x/x/x PH_B8_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK6_BIT_4_CHN_B		0x8E4	//RX DQS PI Phase Control B8 RANK6 Bit 4 Channel B
    #define D0F3_D0F3_RX8E5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS4P_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX8E5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS4N_5_0_RK6			0x3F	//0/x/x/x PH_B8_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK6_BIT_5_CHN_B		0x8E6	//RX DQS PI Phase Control B8 RANK6 Bit 5 Channel B
    #define D0F3_D0F3_RX8E7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS5P_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX8E7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS5N_5_0_RK6			0x3F	//0/x/x/x PH_B8_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK6_BIT_6_CHN_B		0x8E8	//RX DQS PI Phase Control B8 RANK6 Bit 6 Channel B
    #define D0F3_D0F3_RX8E9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS6P_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX8E9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS6N_5_0_RK6			0x3F	//0/x/x/x PH_B8_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK6_BIT_7_CHN_B		0x8EA	//RX DQS PI Phase Control B8 RANK6 Bit 7 Channel B
    #define D0F3_D0F3_RX8EBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS7P_5_0_RK6			0x3F00	//0/x/x/x PH_B8_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX8EBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS7N_5_0_RK6			0x3F	//0/x/x/x PH_B8_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK7_BIT_0_CHN_B		0x8EC	//RX DQS PI Phase Control B0 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX8EDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B0_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX8EDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B0_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK7_BIT_1_CHN_B		0x8EE	//RX DQS PI Phase Control B0 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX8EFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B0_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX8EFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B0_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK7_BIT_2_CHN_B		0x8F0	//RX DQS PI Phase Control B0 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX8F1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B0_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX8F1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B0_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK7_BIT_3_CHN_B		0x8F2	//RX DQS PI Phase Control B0 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX8F3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B0_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX8F3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B0_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK7_BIT_4_CHN_B		0x8F4	//RX DQS PI Phase Control B0 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX8F5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B0_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX8F5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B0_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK7_BIT_5_CHN_B		0x8F6	//RX DQS PI Phase Control B0 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX8F7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B0_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX8F7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B0_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK7_BIT_6_CHN_B		0x8F8	//RX DQS PI Phase Control B0 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX8F9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B0_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX8F9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B0_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B0_RANK7_BIT_7_CHN_B		0x8FA	//RX DQS PI Phase Control B0 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX8FBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B0_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX8FBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B0_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B0_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK7_BIT_0_CHN_B		0x8FC	//RX DQS PI Phase Control B1 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX8FDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX8FDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B1_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK7_BIT_1_CHN_B		0x8FE	//RX DQS PI Phase Control B1 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX8FFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX8FFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B1_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK7_BIT_2_CHN_B		0x900	//RX DQS PI Phase Control B1 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX901B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX901B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B1_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK7_BIT_3_CHN_B		0x902	//RX DQS PI Phase Control B1 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX903B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX903B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B1_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK7_BIT_4_CHN_B		0x904	//RX DQS PI Phase Control B1 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX905B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX905B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B1_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK7_BIT_5_CHN_B		0x906	//RX DQS PI Phase Control B1 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX907B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX907B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B1_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK7_BIT_6_CHN_B		0x908	//RX DQS PI Phase Control B1 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX909B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX909B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B1_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B1_RANK7_BIT_7_CHN_B		0x90A	//RX DQS PI Phase Control B1 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX90BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B1_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX90BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B1_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B1_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK7_BIT_0_CHN_B		0x90C	//RX DQS PI Phase Control B2 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX90DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B2_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX90DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B2_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK7_BIT_1_CHN_B		0x90E	//RX DQS PI Phase Control B2 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX90FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B2_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX90FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B2_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK7_BIT_2_CHN_B		0x910	//RX DQS PI Phase Control B2 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX911B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B2_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX911B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B2_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK7_BIT_3_CHN_B		0x912	//RX DQS PI Phase Control B2 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX913B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B2_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX913B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B2_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK7_BIT_4_CHN_B		0x914	//RX DQS PI Phase Control B2 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX915B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B2_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX915B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B2_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK7_BIT_5_CHN_B		0x916	//RX DQS PI Phase Control B2 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX917B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B2_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX917B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B2_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK7_BIT_6_CHN_B		0x918	//RX DQS PI Phase Control B2 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX919B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B2_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX919B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B2_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B2_RANK7_BIT_7_CHN_B		0x91A	//RX DQS PI Phase Control B2 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX91BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B2_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX91BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B2_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B2_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK7_BIT_0_CHN_B		0x91C	//RX DQS PI Phase Control B3 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX91DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX91DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B3_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK7_BIT_1_CHN_B		0x91E	//RX DQS PI Phase Control B3 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX91FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX91FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B3_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK7_BIT_2_CHN_B		0x920	//RX DQS PI Phase Control B3 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX921B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX921B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B3_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK7_BIT_3_CHN_B		0x922	//RX DQS PI Phase Control B3 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX923B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX923B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B3_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK7_BIT_4_CHN_B		0x924	//RX DQS PI Phase Control B3 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX925B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX925B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B3_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK7_BIT_5_CHN_B		0x926	//RX DQS PI Phase Control B3 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX927B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX927B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B3_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK7_BIT_6_CHN_B		0x928	//RX DQS PI Phase Control B3 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX929B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX929B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B3_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B3_RANK7_BIT_7_CHN_B		0x92A	//RX DQS PI Phase Control B3 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX92BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B3_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX92BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B3_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B3_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK7_BIT_0_CHN_B		0x92C	//RX DQS PI Phase Control B4 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX92DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B4_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX92DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B4_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK7_BIT_1_CHN_B		0x92E	//RX DQS PI Phase Control B4 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX92FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B4_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX92FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B4_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK7_BIT_2_CHN_B		0x930	//RX DQS PI Phase Control B4 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX931B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B4_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX931B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B4_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK7_BIT_3_CHN_B		0x932	//RX DQS PI Phase Control B4 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX933B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B4_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX933B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B4_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK7_BIT_4_CHN_B		0x934	//RX DQS PI Phase Control B4 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX935B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B4_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX935B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B4_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK7_BIT_5_CHN_B		0x936	//RX DQS PI Phase Control B4 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX937B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B4_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX937B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B4_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK7_BIT_6_CHN_B		0x938	//RX DQS PI Phase Control B4 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX939B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B4_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX939B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B4_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B4_RANK7_BIT_7_CHN_B		0x93A	//RX DQS PI Phase Control B4 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX93BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B4_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX93BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B4_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B4_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK7_BIT_0_CHN_B		0x93C	//RX DQS PI Phase Control B5 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX93DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX93DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B5_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK7_BIT_1_CHN_B		0x93E	//RX DQS PI Phase Control B5 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX93FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX93FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B5_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK7_BIT_2_CHN_B		0x940	//RX DQS PI Phase Control B5 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX941B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX941B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B5_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK7_BIT_3_CHN_B		0x942	//RX DQS PI Phase Control B5 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX943B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX943B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B5_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK7_BIT_4_CHN_B		0x944	//RX DQS PI Phase Control B5 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX945B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX945B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B5_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK7_BIT_5_CHN_B		0x946	//RX DQS PI Phase Control B5 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX947B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX947B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B5_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK7_BIT_6_CHN_B		0x948	//RX DQS PI Phase Control B5 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX949B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX949B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B5_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B5_RANK7_BIT_7_CHN_B		0x94A	//RX DQS PI Phase Control B5 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX94BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B5_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX94BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B5_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B5_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK7_BIT_0_CHN_B		0x94C	//RX DQS PI Phase Control B6 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX94DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B6_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX94DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B6_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK7_BIT_1_CHN_B		0x94E	//RX DQS PI Phase Control B6 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX94FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B6_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX94FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B6_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK7_BIT_2_CHN_B		0x950	//RX DQS PI Phase Control B6 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX951B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B6_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX951B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B6_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK7_BIT_3_CHN_B		0x952	//RX DQS PI Phase Control B6 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX953B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B6_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX953B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B6_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK7_BIT_4_CHN_B		0x954	//RX DQS PI Phase Control B6 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX955B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B6_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX955B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B6_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK7_BIT_5_CHN_B		0x956	//RX DQS PI Phase Control B6 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX957B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B6_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX957B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B6_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK7_BIT_6_CHN_B		0x958	//RX DQS PI Phase Control B6 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX959B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B6_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX959B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B6_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B6_RANK7_BIT_7_CHN_B		0x95A	//RX DQS PI Phase Control B6 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX95BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B6_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX95BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B6_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B6_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK7_BIT_0_CHN_B		0x95C	//RX DQS PI Phase Control B7 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX95DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX95DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B7_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK7_BIT_1_CHN_B		0x95E	//RX DQS PI Phase Control B7 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX95FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX95FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B7_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK7_BIT_2_CHN_B		0x960	//RX DQS PI Phase Control B7 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX961B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX961B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B7_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK7_BIT_3_CHN_B		0x962	//RX DQS PI Phase Control B7 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX963B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX963B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B7_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK7_BIT_4_CHN_B		0x964	//RX DQS PI Phase Control B7 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX965B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX965B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B7_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK7_BIT_5_CHN_B		0x966	//RX DQS PI Phase Control B7 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX967B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX967B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B7_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK7_BIT_6_CHN_B		0x968	//RX DQS PI Phase Control B7 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX969B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX969B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B7_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B7_RANK7_BIT_7_CHN_B		0x96A	//RX DQS PI Phase Control B7 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX96BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B7_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX96BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B7_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B7_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK7_BIT_0_CHN_B		0x96C	//RX DQS PI Phase Control B8 RANK7 Bit 0 Channel B
    #define D0F3_D0F3_RX96DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS0P_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DQS0P[5:0]: RX DQSP Phase Control for DQ Bit 0
    #define D0F3_D0F3_RX96DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS0N_5_0_RK7			0x3F	//0/x/x/x PH_B8_DQS0N[5:0]: RX DQSN Phase Control for DQ Bit 0
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK7_BIT_1_CHN_B		0x96E	//RX DQS PI Phase Control B8 RANK7 Bit 1 Channel B
    #define D0F3_D0F3_RX96FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS1P_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DQS1P[5:0]: RX DQSP Phase Control for DQ Bit 1
    #define D0F3_D0F3_RX96FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS1N_5_0_RK7			0x3F	//0/x/x/x PH_B8_DQS1N[5:0]: RX DQSN Phase Control for DQ Bit 1
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK7_BIT_2_CHN_B		0x970	//RX DQS PI Phase Control B8 RANK7 Bit 2 Channel B
    #define D0F3_D0F3_RX971B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS2P_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DQS2P[5:0]: RX DQSP Phase Control for DQ Bit 2
    #define D0F3_D0F3_RX971B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS2N_5_0_RK7			0x3F	//0/x/x/x PH_B8_DQS2N[5:0]: RX DQSN Phase Control for DQ Bit 2
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK7_BIT_3_CHN_B		0x972	//RX DQS PI Phase Control B8 RANK7 Bit 3 Channel B
    #define D0F3_D0F3_RX973B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS3P_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DQS3P[5:0]: RX DQSP Phase Control for DQ Bit 3
    #define D0F3_D0F3_RX973B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS3N_5_0_RK7			0x3F	//0/x/x/x PH_B8_DQS3N[5:0]: RX DQSN Phase Control for DQ Bit 3
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK7_BIT_4_CHN_B		0x974	//RX DQS PI Phase Control B8 RANK7 Bit 4 Channel B
    #define D0F3_D0F3_RX975B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS4P_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DQS4P[5:0]: RX DQSP Phase Control for DQ Bit 4
    #define D0F3_D0F3_RX975B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS4N_5_0_RK7			0x3F	//0/x/x/x PH_B8_DQS4N[5:0]: RX DQSN Phase Control for DQ Bit 4
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK7_BIT_5_CHN_B		0x976	//RX DQS PI Phase Control B8 RANK7 Bit 5 Channel B
    #define D0F3_D0F3_RX977B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS5P_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DQS5P[5:0]: RX DQSP Phase Control for DQ Bit 5
    #define D0F3_D0F3_RX977B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS5N_5_0_RK7			0x3F	//0/x/x/x PH_B8_DQS5N[5:0]: RX DQSN Phase Control for DQ Bit 5
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK7_BIT_6_CHN_B		0x978	//RX DQS PI Phase Control B8 RANK7 Bit 6 Channel B
    #define D0F3_D0F3_RX979B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS6P_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DQS6P[5:0]: RX DQSP Phase Control for DQ Bit 6
    #define D0F3_D0F3_RX979B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS6N_5_0_RK7			0x3F	//0/x/x/x PH_B8_DQS6N[5:0]: RX DQSN Phase Control for DQ Bit 6
#define D0F3_RX_DQS_PI_PHASE_CTL_B8_RANK7_BIT_7_CHN_B		0x97A	//RX DQS PI Phase Control B8 RANK7 Bit 7 Channel B
    #define D0F3_D0F3_RX97BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS7P_5_0_RK7			0x3F00	//0/x/x/x PH_B8_DQS7P[5:0]: RX DQSP Phase Control for DQ Bit 7
    #define D0F3_D0F3_RX97BB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RPH_B8_DQS7N_5_0_RK7			0x3F	//0/x/x/x PH_B8_DQS7N[5:0]: RX DQSN Phase Control for DQ Bit 7
#define D0F3_RX_PER_BIT_DELAY_A0_BIT_0_1_2_3_CHN_A		0x97C	//RX Per Bit Delay A0 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A0_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for bit 3
    #define D0F3_RPH_A0_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A0_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_A0_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A0_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A0_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A0_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A0_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A0_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A0_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_A0_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A0_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A0_BIT_4_5_6_7_CHN_A		0x97E	//RX Per Bit Delay A0 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A0_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A0_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A0_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A0_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A0_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A0_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A0_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A0_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A0_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A0_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A0_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A0_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_A1_BIT_0_1_2_3_CHN_A		0x980	//RX Per Bit Delay A1 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A1_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_A1_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A1_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_A1_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A1_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A1_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A1_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A1_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A1_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A1_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_A1_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A1_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A1_BIT_4_5_6_7_CHN_A		0x982	//RX Per Bit Delay A1 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A1_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A1_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A1_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A1_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A1_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A1_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A1_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A1_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A1_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A1_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A1_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A1_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_A2_BIT_0_1_2_3_CHN_A		0x984	//RX Per Bit Delay A2 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A2_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_A2_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A2_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_A2_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A2_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A2_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A2_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A2_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A2_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A2_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_A2_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A2_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A2_BIT_4_5_6_7_CHN_A		0x986	//RX Per Bit Delay A2 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A2_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A2_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A2_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A2_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A2_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A2_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A2_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A2_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A2_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A2_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A2_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A2_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_A3_BIT_0_1_2_3_CHN_A		0x988	//RX Per Bit Delay A3 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A3_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_A3_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A3_DQ3_[2:0] DQ Delay Setting for bit 3
    #define D0F3_MUXEN_A3_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A3_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A3_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A3_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A3_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A3_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A3_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_A3_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A3_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A3_BIT_4_5_6_7_CHN_A		0x98A	//RX Per Bit Delay A3 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A3_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A3_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A3_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A3_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A3_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A3_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A3_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A3_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A3_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A3_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A3_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A3_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_A4_BIT_0_1_2_3_CHN_A		0x98C	//RX Per Bit Delay A4 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A4_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_A4_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A4_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_A4_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A4_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A4_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A4_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A4_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A4_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A4_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_A4_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A4_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A4_BIT_4_5_6_7_CHN_A		0x98E	//RX Per Bit Delay A4 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A4_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A4_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A4_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A4_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A4_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A4_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A4_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A4_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A4_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A4_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A4_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A4_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_A5_BIT_0_1_2_3_CHN_A		0x990	//RX Per Bit Delay A5 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A5_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_A5_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A5_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_A5_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A5_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A5_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A5_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A5_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A5_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A5_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_A5_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A5_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A5_BIT_4_5_6_7_CHN_A		0x992	//RX Per Bit Delay A5 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A5_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A5_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A5_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A5_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A5_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A5_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A5_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A5_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A5_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A5_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A5_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A5_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_A6_BIT_0_1_2_3_CHN_A		0x994	//RX Per Bit Delay A6 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A6_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_A6_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A6_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_A6_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A6_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A6_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A6_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A6_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A6_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A6_DQ0			BIT3	//1b/x/x/x RX DQ delay MUX enable for bit 0
    #define D0F3_RPH_A6_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A6_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A6_BIT_4_5_6_7_CHN_A		0x996	//RX Per Bit Delay A6 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A6_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A6_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A6_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A6_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A6_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A6_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A6_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A6_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A6_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A6_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A6_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A6_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_A7_BIT_0_1_2_3_CHN_A		0x998	//RX Per Bit Delay A7 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A7_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_A7_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A7_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_A7_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A7_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A7_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A7_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A7_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A7_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A7_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_A7_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A7_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A7_BIT_4_5_6_7_CHN_A		0x99A	//RX Per Bit Delay A7 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A7_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A7_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A7_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A7_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A7_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A7_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A7_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A7_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A7_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A7_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A7_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A7_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_A8_BIT_0_1_2_3_CHN_A		0x99C	//RX Per Bit Delay A8 Bit 0/1/2/3 Channel A
    #define D0F3_MUXEN_A8_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_A8_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A8_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_A8_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_A8_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A8_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_A8_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_A8_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A8_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_A8_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_A8_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A8_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_A8_BIT_4_5_6_7_CHN_A		0x99E	//RX Per Bit Delay A8 Bit 4/5/6/7 Channel A
    #define D0F3_MUXEN_A8_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_A8_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_A8_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_A8_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_A8_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_A8_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_A8_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_A8_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_A8_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_A8_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_A8_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_A8_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B0_BIT_0_1_2_3_CHN_B		0x9A0	//RX Per Bit Delay B0 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B0_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B0_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B0_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B0_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B0_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B0_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B0_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B0_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B0_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B0_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B0_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B0_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B0_BIT_4_5_6_7_CHN_B		0x9A2	//RX Per Bit Delay B0 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B0_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B0_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B0_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B0_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B0_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B0_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B0_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B0_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B0_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B0_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B0_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B0_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B1_BIT_0_1_2_3_CHN_B		0x9A4	//RX Per Bit Delay B1 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B1_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B1_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B1_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B1_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B1_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B1_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B1_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B1_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B1_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B1_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B1_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B1_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B1_BIT_4_5_6_7_CHN_B		0x9A6	//RX Per Bit Delay B1 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B1_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B1_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B1_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B1_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B1_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B1_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B1_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B1_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B1_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B1_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B1_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B1_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B2_BIT_0_1_2_3_CHN_B		0x9A8	//RX Per Bit Delay B2 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B2_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B2_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B2_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B2_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B2_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B2_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B2_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B2_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B2_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B2_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B2_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B2_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B2_BIT_4_5_6_7_CHN_B		0x9AA	//RX Per Bit Delay B2 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B2_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B2_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B2_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B2_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B2_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B2_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B2_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B2_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B2_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B2_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B2_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B2_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B3_BIT_0_1_2_3_CHN_B		0x9AC	//RX Per Bit Delay B3 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B3_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B3_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B3_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B3_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B3_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B3_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B3_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B3_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B3_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B3_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B3_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B3_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B3_BIT_4_5_6_7_CHN_B		0x9AE	//RX Per Bit Delay B3 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B3_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B3_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B3_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B3_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B3_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B3_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B3_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B3_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B3_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B3_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B3_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B3_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B4_BIT_0_1_2_3_CHN_B		0x9B0	//RX Per Bit Delay B4 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B4_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B4_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B4_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B4_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B4_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B4_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B4_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B4_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B4_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B4_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B4_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B4_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B4_BIT_4_5_6_7_CHN_B		0x9B2	//RX Per Bit Delay B4 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B4_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B4_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B4_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B4_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B4_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B4_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B4_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B4_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B4_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B4_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B4_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B4_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B5_BIT_0_1_2_3_CHN_B		0x9B4	//RX Per Bit Delay B5 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B5_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B5_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B5_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B5_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B5_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B5_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B5_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B5_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B5_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B5_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B5_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B5_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B5_BIT_4_5_6_7_CHN_B		0x9B6	//RX Per Bit Delay B5 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B5_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B5_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B5_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B5_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B5_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B5_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B5_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B5_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B5_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B5_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B5_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B5_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B6_BIT_0_1_2_3_CHN_B		0x9B8	//RX Per Bit Delay B6 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B6_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B6_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B6_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B6_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B6_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B6_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B6_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B6_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B6_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B6_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B6_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B6_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B6_BIT_4_5_6_7_CHN_B		0x9BA	//RX Per Bit Delay B6 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B6_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B6_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B6_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B6_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B6_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B6_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B6_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B6_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B6_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B6_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B6_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B6_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B7_BIT_0_1_2_3_CHN_B		0x9BC	//RX Per Bit Delay B7 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B7_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B7_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B7_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B7_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B7_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B7_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B7_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B7_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B7_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B7_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B7_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B7_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B7_BIT_4_5_6_7_CHN_B		0x9BE	//RX Per Bit Delay B7 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B7_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B7_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B7_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B7_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B7_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B7_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B7_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B7_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B7_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B7_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B7_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B7_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_RX_PER_BIT_DELAY_B8_BIT_0_1_2_3_CHN_B		0x9C0	//RX Per Bit Delay B8 Bit 0/1/2/3 Channel B
    #define D0F3_MUXEN_B8_DQ3			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 3
    #define D0F3_RPH_B8_DQ3_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B8_DQ3_[2:0] DQ Delay Setting for Bit 3
    #define D0F3_MUXEN_B8_DQ2			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 2
    #define D0F3_RPH_B8_DQ2_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B8_DQ2_[2:0] DQ Delay Setting for Bit 2
    #define D0F3_MUXEN_B8_DQ1			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 1
    #define D0F3_RPH_B8_DQ1_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B8_DQ1_[2:0] DQ Delay Setting for Bit 1
    #define D0F3_MUXEN_B8_DQ0			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 0
    #define D0F3_RPH_B8_DQ0_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B8_DQ0_[2:0] DQ Delay Setting for Bit 0
#define D0F3_RX_PER_BIT_DELAY_B8_BIT_4_5_6_7_CHN_B		0x9C2	//RX Per Bit Delay B8 Bit 4/5/6/7 Channel B
    #define D0F3_MUXEN_B8_DQ7			BIT15	//1b/x/x/x RX DQ Delay MUX Enable for Bit 7
    #define D0F3_RPH_B8_DQ7_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x PH_B8_DQ7_[2:0] DQ Delay Setting for Bit 7
    #define D0F3_MUXEN_B8_DQ6			BIT11	//1b/x/x/x RX DQ Delay MUX Enable for Bit 6
    #define D0F3_RPH_B8_DQ6_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x PH_B8_DQ6_[2:0] DQ Delay Setting for Bit 6
    #define D0F3_MUXEN_B8_DQ5			BIT7	//1b/x/x/x RX DQ Delay MUX Enable for Bit 5
    #define D0F3_RPH_B8_DQ5_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x PH_B8_DQ5_[2:0] DQ Delay Setting for Bit 5
    #define D0F3_MUXEN_B8_DQ4			BIT3	//1b/x/x/x RX DQ Delay MUX Enable for Bit 4
    #define D0F3_RPH_B8_DQ4_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x PH_B8_DQ4_[2:0] DQ Delay Setting for Bit 4
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A0_BIT_0_1_2_3_CHN_A		0x9C4	//TX DQ Per-bit Register Setting A0 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A0_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A0_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A0_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A0_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A0_BIT_4_5_6_7_CHN_A		0x9C6	//TX DQ Per-bit Register Setting A0 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A0_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A0_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A0_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A0_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A1_BIT_0_1_2_3_CHN_A		0x9C8	//TX DQ Per-bit Register Setting A1 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A1_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A1_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A1_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A1_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 pad DH/DL to IO delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A1_BIT_4_5_6_7_CHN_A		0x9CA	//TX DQ Per-bit Register Setting A1 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A1_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A1_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A1_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A1_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A2_BIT_0_1_2_3_CHN_A		0x9CC	//TX DQ Per-bit Register Setting A2 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A2_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A2_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A2_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO delay
    #define D0F3_RDLY_A2_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A2_BIT_4_5_6_7_CHN_A		0x9CE	//TX DQ Per-bit Register Setting A2 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A2_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A2_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A2_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A2_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A3_BIT_0_1_2_3_CHN_A		0x9D0	//TX DQ Per-bit Register Setting A3 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A3_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A3_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A3_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A3_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A3_BIT_4_5_6_7_CHN_A		0x9D2	//TX DQ Per-bit Register Setting A3 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A3_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A3_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A3_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A3_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 pad DH/DL to IO delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A4_BIT_0_1_2_3_CHN_A		0x9D4	//TX DQ Per-bit Register Setting A4 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A4_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A4_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A4_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A4_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A4_BIT_4_5_6_7_CHN_A		0x9D6	//TX DQ Per-bit Register Setting A4 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A4_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A4_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A4_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A4_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A5_BIT_0_1_2_3_CHN_A		0x9D8	//TX DQ Per-bit Register Setting A5 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A5_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A5_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A5_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A5_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A5_BIT_4_5_6_7_CHN_A		0x9DA	//TX DQ Per-bit Register Setting A5 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A5_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A5_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 pad DH/DL to IO delay
    #define D0F3_RDLY_A5_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A5_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A6_BIT_0_1_2_3_CHN_A		0x9DC	//TX DQ Per-bit Register Setting A6 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A6_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A6_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A6_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A6_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A6_BIT_4_5_6_7_CHN_A		0x9DE	//TX DQ Per-bit Register Setting A6 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A6_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A6_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A6_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A6_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A7_BIT_0_1_2_3_CHN_A		0x9E0	//TX DQ Per-bit Register Setting A7 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A7_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A7_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A7_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A7_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A7_BIT_4_5_6_7_CHN_A		0x9E2	//TX DQ Per-bit Register Setting A7 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A7_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A7_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A7_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A7_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A8_BIT_0_1_2_3_CHN_A		0x9E4	//TX DQ Per-bit Register Setting A8 Bit 0/1/2/3 Channel A
    #define D0F3_RDLY_A8_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3,Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A8_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2,Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A8_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1,Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A8_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0,Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_A8_BIT_4_5_6_7_CHN_A		0x9E6	//TX DQ Per-bit Register Setting A8 Bit 4/5/6/7 Channel A
    #define D0F3_RDLY_A8_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A8_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A8_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_A8_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B0_BIT_0_1_2_3_CHN_B		0x9E8	//TX DQ Per-bit Register Setting B0 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B0_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B0_DQ2_3_0			0xF00	//0/x/x/x DQ per bit deskew setting for bit2, Define bdddrdq_S24 pad DH/DL to IO delay
    #define D0F3_RDLY_B0_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B0_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B0_BIT_4_5_6_7_CHN_B		0x9EA	//TX DQ Per-bit Register Setting B0 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B0_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B0_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B0_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B0_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B1_BIT_0_1_2_3_CHN_B		0x9EC	//TX DQ Per-bit Register Setting B1 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B1_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B1_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B1_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B1_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B1_BIT_4_5_6_7_CHN_B		0x9EE	//TX DQ Per-bit Register Setting B1 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B1_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B1_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B1_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B1_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B2_BIT_0_1_2_3_CHN_B		0x9F0	//TX DQ Per-bit Register Setting B2 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B2_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B2_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B2_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B2_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B2_BIT_4_5_6_7_CHN_B		0x9F2	//TX DQ Per-bit Register Setting B2 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B2_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B2_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B2_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B2_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B3_BIT_0_1_2_3_CHN_B		0x9F4	//TX DQ Per-bit Register Setting B3 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B3_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B3_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B3_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B3_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B3_BIT_4_5_6_7_CHN_B		0x9F6	//TX DQ Per-bit Register Setting B3 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B3_DQ7_3_0			0xF000	//0/x/x/x DQ per bit deskew setting for bit7,define bdddrdq_S24 pad DH/DL to IO delay
    #define D0F3_RDLY_B3_DQ6_3_0			0xF00	//0/x/x/x DQ per bit deskew setting for bit6,define bdddrdq_S24 pad DH/DL to IO delay
    #define D0F3_RDLY_B3_DQ5_3_0			0xF0	//0/x/x/x DQ per bit deskew setting for bit5,define bdddrdq_S24 pad DH/DL to IO delay
    #define D0F3_RDLY_B3_DQ4_3_0			0xF	//0/x/x/x DQ per bit deskew setting for bit4,define bdddrdq_S24 pad DH/DL to IO delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B4_BIT_0_1_2_3_CHN_B		0x9F8	//TX DQ Per-bit Register Setting B4 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B4_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B4_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B4_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B4_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B4_BIT_4_5_6_7_CHN_B		0x9FA	//TX DQ Per-bit Register Setting B4 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B4_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B4_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B4_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B4_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B5_BIT_0_1_2_3_CHN_B		0x9FC	//TX DQ Per-bit Register Setting B5 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B5_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B5_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B5_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B5_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B5_BIT_4_5_6_7_CHN_B		0x9FE	//TX DQ Per-bit Register Setting B5 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B5_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B5_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B5_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B5_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B6_BIT_0_1_2_3_CHN_B		0xA00	//TX DQ Per-bit Register Setting B6 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B6_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B6_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B6_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B6_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B6_BIT_4_5_6_7_CHN_B		0xA02	//TX DQ Per-bit Register Setting B6 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B6_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B6_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B6_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B6_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B7_BIT_0_1_2_3_CHN_B		0xA04	//TX DQ Per-bit Register Setting B7 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B7_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B7_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B7_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B7_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B7_BIT_4_5_6_7_CHN_B		0xA06	//TX DQ Per-bit Register Setting B7 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B7_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B7_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B7_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B7_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B8_BIT_0_1_2_3_CHN_B		0xA08	//TX DQ Per-bit Register Setting B8 Bit 0/1/2/3 Channel B
    #define D0F3_RDLY_B8_DQ3_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit3, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B8_DQ2_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit2, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B8_DQ1_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit1, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B8_DQ0_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit0, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_TX_DQ_PER_BIT_REG_SETTING_B8_BIT_4_5_6_7_CHN_B		0xA0A	//TX DQ Per-bit Register Setting B8 Bit 4/5/6/7 Channel B
    #define D0F3_RDLY_B8_DQ7_3_0			0xF000	//0/x/x/x DQ Per Bit Deskew Setting for Bit7, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B8_DQ6_3_0			0xF00	//0/x/x/x DQ Per Bit Deskew Setting for Bit6, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B8_DQ5_3_0			0xF0	//0/x/x/x DQ Per Bit Deskew Setting for Bit5, Define bdddrdq_S24 Pad DH/DL to IO Delay
    #define D0F3_RDLY_B8_DQ4_3_0			0xF	//0/x/x/x DQ Per Bit Deskew Setting for Bit4, Define bdddrdq_S24 Pad DH/DL to IO Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK0_A0_A1_A2_A3_CHN_A		0xA0C	//RX Whole T Timing Control RANK0 A0/A1/A2/A3 Channel A
    #define D0F3_RDSIADVOS_3_0_A3_RK0			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_A3 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A2_RK0			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_A2 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A1_RK0			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_A1 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A0_RK0			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A0 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK0_A4_A5_A6_A7_CHN_A		0xA0E	//RX Whole T Timing Control RANK0 A4/A5/A6/A7 Channel A
    #define D0F3_RDSIADVOS_3_0_A7_RK0			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_A7 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A6_RK0			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_A6 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A5_RK0			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_A5 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A4_RK0			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A4 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK0_A8_CHN_A		0xA10	//RX Whole T Timing Control RANK0 A8 Channel A
    #define D0F3_D0F3_RXA11B_15_4			0xFFF0	//0/x/x/x Reserved
    #define D0F3_RDSIADVOS_3_0_A8_RK0			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A8 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK1_A0_A1_A2_A3_CHN_A		0xA12	//RX Whole T Timing Control RANK1 A0/A1/A2/A3 Channel A
    #define D0F3_RDSIADVOS_3_0_A3_RK1			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_A3 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A2_RK1			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_A2 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A1_RK1			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_A1 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A0_RK1			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A0 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK1_A4_A5_A6_A7_CHN_A		0xA14	//RX Whole T Timing Control RANK1 A4/A5/A6/A7 Channel A
    #define D0F3_RDSIADVOS_3_0_A7_RK1			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_A7 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A6_RK1			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_A6 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A5_RK1			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_A5 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A4_RK1			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A4 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK1_A8_CHN_A		0xA16	//RX Whole T timing Control RANK1 A8 Channel A
    #define D0F3_D0F3_RXA17B_15_4			0xFFF0	//0/x/x/x Reserved
    #define D0F3_RDSIADVOS_3_0_A8_RK1			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A8 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK2_A0_A1_A2_A3_CHN_A		0xA18	//RX whole T timing control RANK2 A0/A1/A2/A3 channel A
    #define D0F3_RDSIADVOS_3_0_A3_RK2			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_A3 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A2_RK2			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_A2 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A1_RK2			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_A1 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A0_RK2			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A0 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK2_A4_A5_A6_A7_CHN_A		0xA1A	//RX Whole T Timing Control RANK2 A4/A5/A6/A7 Channel A
    #define D0F3_RDSIADVOS_3_0_A7_RK2			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_A7 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A6_RK2			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_A6 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A5_RK2			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_A5 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A4_RK2			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A4 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK2_A8_CHN_A		0xA1C	//RX Whole T Timing Control RANK2 A8 Channel A
    #define D0F3_D0F3_RXA1DB_15_4			0xFFF0	//0/x/x/x Reserved
    #define D0F3_RDSIADVOS_3_0_A8_RK2			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A8 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK3_A0_A1_A2_A3_CHN_A		0xA1E	//RX Whole T Timing Control RANK3 A0/A1/A2/A3 Channel A
    #define D0F3_RDSIADVOS_3_0_A3_RK3			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_A3 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A2_RK3			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_A2 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A1_RK3			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_A1 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A0_RK3			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A0 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK3_A4_A5_A6_A7_CHN_A		0xA20	//RX Whole T Timing Control RANK3 A4/A5/A6/A7 Channel A
    #define D0F3_RDSIADVOS_3_0_A7_RK3			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_A7 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A6_RK3			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_A6 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A5_RK3			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_A5 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_A4_RK3			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A4 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK3_A8_CHN_A		0xA22	//RX Whole T Timing Control RANK3 A8 Channel A
    #define D0F3_D0F3_RXA23B_15_4			0xFFF0	//0/x/x/x Reserved
    #define D0F3_RDSIADVOS_3_0_A8_RK3			0xF	//0001b/x/x/x RDSIADVOS[3:0]_A8 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK4_B0_B1_B2_B3_CHN_B		0xA24	//RX Whole T Timing Control RANK4 B0/B1/B2/B3 Channel B
    #define D0F3_RDSIADVOS_3_0_B3_RK4			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_B3 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B2_RK4			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_B2 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B1_RK4			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_B1 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B0_RK4			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B0 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK4_B4_B5_B6_B7_CHN_B		0xA26	//RX Whole T Timing Control RANK4 B4/B5/B6/B7 Channel B
    #define D0F3_RDSIADVOS_3_0_B7_RK4			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_B7 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B6_RK4			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_B6 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B5_RK4			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_B5 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B4_RK4			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B4 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK4_B8_CHN_B		0xA28	//RX Whole T Timing Control RANK4 B8 Channel B
    #define D0F3_D0F3_RXA29B_15_4			0xFFF0	//0/x/x/x Reserved
    #define D0F3_RDSIADVOS_3_0_B8_RK4			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B8 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK5_B0_B1_B2_B3_CHN_B		0xA2A	//RX Whole T Timing Control RANK5 B0/B1/B2/B3 Channel B
    #define D0F3_RDSIADVOS_3_0_B3_RK5			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_B3 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B2_RK5			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_B2 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B1_RK5			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_B1 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B0_RK5			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B0 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK5_B4_B5_B6_B7_CHN_B		0xA2C	//RX Whole T Timing Control RANK5 B4/B5/B6/B7 Channel B
    #define D0F3_RDSIADVOS_3_0_B7_RK5			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_B7 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B6_RK5			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_B6 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B5_RK5			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_B5 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B4_RK5			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B4 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK5_B8_CHN_B		0xA2E	//RX Whole T Timing Control RANK5 B8 Channel B
    #define D0F3_D0F3_RXA2FB_15_4			0xFFF0	//0/x/x/x Reserved
    #define D0F3_RDSIADVOS_3_0_B8_RK5			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B8 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK6_B0_B1_B2_B3_CHN_B		0xA30	//RX Whole T Timing Control RANK6 B0/B1/B2/B3 Channel B
    #define D0F3_RDSIADVOS_3_0_B3_RK6			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_B3 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B2_RK6			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_B2 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B1_RK6			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_B1 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B0_RK6			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B0 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK6_B4_B5_B6_B7_CHN_B		0xA32	//RX Whole T Timing Control RANK6 B4/B5/B6/B7 Channel B
    #define D0F3_RDSIADVOS_3_0_B7_RK6			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_B7 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B6_RK6			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_B6 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B5_RK6			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_B5 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B4_RK6			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B4 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK6_B8_CHN_B		0xA34	//RX Whole T Timing Control RANK6 B8 Channel B
    #define D0F3_D0F3_RXA35B_15_4			0xFFF0	//0/x/x/x Reserved
    #define D0F3_RDSIADVOS_3_0_B8_RK6			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B8 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK7_B0_B1_B2_B3_CHN_B		0xA36	//RX Whole T Timing Control RANK7 B0/B1/B2/B3 Channel B
    #define D0F3_RDSIADVOS_3_0_B3_RK7			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_B3 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B2_RK7			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_B2 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B1_RK7			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_B1 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B0_RK7			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B0 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK7_B4_B5_B6_B7_CHN_B		0xA38	//RX Whole T Timing Control RANK7 B4/B5/B6/B7 Channel B
    #define D0F3_RDSIADVOS_3_0_B7_RK7			0xF000	//0001b/x/x/x RDSIADVOS[3:0]_B7 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B6_RK7			0xF00	//0001b/x/x/x RDSIADVOS[3:0]_B6 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B5_RK7			0xF0	//0001b/x/x/x RDSIADVOS[3:0]_B5 RX TNI Delay
    #define D0F3_RDSIADVOS_3_0_B4_RK7			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B4 RX TNI Delay
#define D0F3_RX_WHOLE_T_TIMING_CTL_RANK7_B8_CHN_B		0xA3A	//RX Whole T Timing Control RANK7 B8 Channel B
    #define D0F3_D0F3_RXA3BB_15_4			0xFFF0	//0/x/x/x Reserved
    #define D0F3_RDSIADVOS_3_0_B8_RK7			0xF	//0001b/x/x/x RDSIADVOS[3:0]_B8 RX TNI Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_A0_A1_CHN_A		0xA3C	//TX Whole T Timing Control A0/A1 Channel A
    #define D0F3_D0F3_RXA3DB15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A1			(BIT12 + BIT13 + BIT14)	//001b/x/x/x RDSADVOS[2:0]_A1 TX DQS Delay
    #define D0F3_D0F3_RXA3DB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_A1			(BIT8 + BIT9 + BIT10)	//001b/x/x/x RDWADVOS[2:0]_A1 TX DQ Delay
    #define D0F3_D0F3_RXA3DB7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A0			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_A0 TX DQS Delay
    #define D0F3_D0F3_RXA3DB3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_A0			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_A0 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_A2_A3_CHN_A		0xA3E	//TX Whole T Timing Control A2/A3 Channel A
    #define D0F3_D0F3_RXA3FB15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A3			(BIT12 + BIT13 + BIT14)	//001b/x/x/x RDSADVOS[2:0]_A3 TX DQS Delay
    #define D0F3_D0F3_RXA3FB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_A3			(BIT8 + BIT9 + BIT10)	//001b/x/x/x RDWADVOS[2:0]_A3 TX DQ Delay
    #define D0F3_D0F3_RXA3FB7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A2			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_A2 TX DQS Delay
    #define D0F3_RDQSOEDD_MUX			BIT3	//0/x/x/x Select for DQSOEDDQ/DQSOEDDQ_Q
    #define D0F3_RDWADVOS_2_0_A2			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_A2 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_A4_A5_CHN_A		0xA40	//TX Whole T Timing Control A4/A5 Channel A
    #define D0F3_D0F3_RXA41B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A5			(BIT12 + BIT13 + BIT14)	//001b/x/x/x RDSADVOS[2:0]_A5 TX DQS Delay
    #define D0F3_D0F3_RXA41B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_A5			(BIT8 + BIT9 + BIT10)	//001b/x/x/x RDWADVOS[2:0]_A5 TX DQ Delay
    #define D0F3_D0F3_RXA41B7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A4			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_A4 TX DQS Delay
    #define D0F3_D0F3_RXA41B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_A4			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_A4 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_A6_A7_CHN_A		0xA42	//TX Whole T Timing Control A6/A7 Channel A
    #define D0F3_D0F3_RXA43B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A7			(BIT12 + BIT13 + BIT14)	//001b/x/x/x RDSADVOS[2:0]_A7 TX DQS Delay
    #define D0F3_D0F3_RXA43B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_A7			(BIT8 + BIT9 + BIT10)	//001b/x/x/x RDWADVOS[2:0]_A7 TX DQ Delay
    #define D0F3_D0F3_RXA43B7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A6			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_A6 TX DQS Delay
    #define D0F3_D0F3_RXA43B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_A6			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_A6 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_A8_CHN_A		0xA44	//TX Whole T Timing Control A8 Channel A
    #define D0F3_D0F3_RXA45B_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_A8			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_A8 TX DQS Delay
    #define D0F3_D0F3_RXA45B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_A8			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_A8 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_B0_B1_CHN_B		0xA46	//TX Whole T Timing Control B0/B1 Channel B
    #define D0F3_D0F3_RXA47B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B1			(BIT12 + BIT13 + BIT14)	//001b/x/x/x RDSADVOS[2:0]_B1 TX DQS Delay
    #define D0F3_D0F3_RXA47B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B1			(BIT8 + BIT9 + BIT10)	//001b/x/x/x RDWADVOS[2:0]_B1 TX DQ Delay
    #define D0F3_D0F3_RXA47B7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B0			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_B0 TX DQS Delay
    #define D0F3_D0F3_RXA47B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B0			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_B0 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_B2_B3_CHN_B		0xA48	//TX Whole T Timing Control B2/B3 Channel B
    #define D0F3_D0F3_RXA49B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B3			(BIT12 + BIT13 + BIT14)	//001b/x/x/x RDSADVOS[2:0]_B3 TX DQS Delay
    #define D0F3_D0F3_RXA49B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B3			(BIT8 + BIT9 + BIT10)	//001b/x/x/x RDWADVOS[2:0]_B3 TX DQ Delay
    #define D0F3_D0F3_RXA49B7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B2			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_B2 TX DQS Delay
    #define D0F3_D0F3_RXA49B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B2			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_B2 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_B4_B5_CHN_B		0xA4A	//TX Whole T Timing Control B4/B5 Channel B
    #define D0F3_D0F3_RXA4BB15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B5			(BIT12 + BIT13 + BIT14)	//001b/x/x/x RDSADVOS[2:0]_B5 TX DQS Delay
    #define D0F3_D0F3_RXA4BB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B5			(BIT8 + BIT9 + BIT10)	//001b/x/x/x RDWADVOS[2:0]_B5 TX DQ Delay
    #define D0F3_D0F3_RXA4BB7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B4			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_B4 TX DQS Delay
    #define D0F3_D0F3_RXA4BB3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B4			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_B4 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_B6_B7_CHN_B		0xA4C	//TX Whole T Timing Control B6/B7 Channel B
    #define D0F3_D0F3_RXA4DB15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B7			(BIT12 + BIT13 + BIT14)	//001b/x/x/x RDSADVOS[2:0]_B7 TX DQS Delay
    #define D0F3_D0F3_RXA4DB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B7			(BIT8 + BIT9 + BIT10)	//001b/x/x/x RDWADVOS[2:0]_B7 TX DQ Delay
    #define D0F3_D0F3_RXA4DB7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B6			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_B6 TX DQS Delay
    #define D0F3_D0F3_RXA4DB3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B6			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_B6 TX DQ Delay
#define D0F3_TX_WHOLE_T_TIMING_CTL_B8_CHN_B		0xA4E	//TX Whole T Timing Control B8 Channel B
    #define D0F3_D0F3_RXA4FB_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_RDSADVOS_2_0_B8			(BIT4 + BIT5 + BIT6)	//001b/x/x/x RDSADVOS[2:0]_B8 TX DQS Delay
    #define D0F3_D0F3_RXA4FB3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDWADVOS_2_0_B8			(BIT0 + BIT1 + BIT2)	//001b/x/x/x RDWADVOS[2:0]_B8 TX DQ Delay
#define D0F3_DQ_REG_SETTING_A0_CHN_A		0xA50	//DQ Register Setting A0 Channel A
    #define D0F3_DQ_A0_PS_3_0			0xF000	//0/x/x/x DQ_A0_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A0_NS_3_0			0xF00	//0/x/x/x DQ_A0_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A0_PS_3_0			0xF0	//0/x/x/x DQS_A0_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A0_NS_3_0			0xF	//0/x/x/x DQS_A0_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A1_CHN_A		0xA52	//DQ Register Setting A1 Channel A
    #define D0F3_DQ_A1_PS_3_0			0xF000	//0/x/x/x DQ_A1_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A1_NS_3_0			0xF00	//0/x/x/x DQ_A1_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A1_PS_3_0			0xF0	//0/x/x/x DQS_A1_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A1_NS_3_0			0xF	//0/x/x/x DQS_A1_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A2_CHN_A		0xA54	//DQ Register Setting A2 Channel A
    #define D0F3_DQ_A2_PS_3_0			0xF000	//0/x/x/x DQ_A2_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A2_NS_3_0			0xF00	//0/x/x/x DQ_A2_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A2_PS_3_0			0xF0	//0/x/x/x DQS_A2_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A2_NS_3_0			0xF	//0/x/x/x DQS_A2_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A3_CHN_A		0xA56	//DQ Register Setting A3 Channel A
    #define D0F3_DQ_A3_PS_3_0			0xF000	//0/x/x/x DQ_A3_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A3_NS_3_0			0xF00	//0/x/x/x DQ_A3_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A3_PS_3_0			0xF0	//0/x/x/x DQS_A3_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A3_NS_3_0			0xF	//0/x/x/x DQS_A3_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A4_CHN_A		0xA58	//DQ Register Setting A4 Channel A
    #define D0F3_DQ_A4_PS_3_0			0xF000	//0/x/x/x DQ_A4_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A4_NS_3_0			0xF00	//0/x/x/x DQ_A4_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A4_PS_3_0			0xF0	//0/x/x/x DQS_A4_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A4_NS_3_0			0xF	//0/x/x/x DQS_A4_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A5_CHN_A		0xA5A	//DQ Register Setting A5 Channel A
    #define D0F3_DQ_A5_PS_3_0			0xF000	//0/x/x/x DQ_A5_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A5_NS_3_0			0xF00	//0/x/x/x DQ_A5_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A5_PS_3_0			0xF0	//0/x/x/x DQS_A5_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A5_NS_3_0			0xF	//0/x/x/x DQS_A5_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A6_CHN_A		0xA5C	//DQ Register Setting A6 Channel A
    #define D0F3_DQ_A6_PS_3_0			0xF000	//0/x/x/x DQ_A6_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A6_NS_3_0			0xF00	//0/x/x/x DQ_A6_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A6_PS_3_0			0xF0	//0/x/x/x DQS_A6_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A6_NS_3_0			0xF	//0/x/x/x DQS_A6_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A7_CHN_A		0xA5E	//DQ Register Setting A7 Channel A
    #define D0F3_DQ_A7_PS_3_0			0xF000	//0/x/x/x DQ_A7_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A7_NS_3_0			0xF00	//0/x/x/x DQ_A7_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A7_PS_3_0			0xF0	//0/x/x/x DQS_A7_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A7_NS_3_0			0xF	//0/x/x/x DQS_A7_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A8_CHN_A		0xA60	//DQ Register Setting A8 Channel A
    #define D0F3_DQ_A8_PS_3_0			0xF000	//0/x/x/x DQ_A8_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_A8_NS_3_0			0xF00	//0/x/x/x DQ_A8_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_A8_PS_3_0			0xF0	//0/x/x/x DQS_A8_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_A8_NS_3_0			0xF	//0/x/x/x DQS_A8_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B0_CHN_B		0xA62	//DQ Register Setting B0 Channel B
    #define D0F3_DQ_B0_PS_3_0			0xF000	//0/x/x/x DQ_B0_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B0_NS_3_0			0xF00	//0/x/x/x DQ_B0_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B0_PS_3_0			0xF0	//0/x/x/x DQS_B0_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B0_NS_3_0			0xF	//0/x/x/x DQS_B0_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B1_CHN_B		0xA64	//DQ Register Setting B1 Channel B
    #define D0F3_DQ_B1_PS_3_0			0xF000	//0/x/x/x DQ_B1_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B1_NS_3_0			0xF00	//0/x/x/x DQ_B1_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B1_PS_3_0			0xF0	//0/x/x/x DQS_B1_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B1_NS_3_0			0xF	//0/x/x/x DQS_B1_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B2_CHN_B		0xA66	//DQ Register Setting B2 Channel B
    #define D0F3_DQ_B2_PS_3_0			0xF000	//0/x/x/x DQ_B2_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B2_NS_3_0			0xF00	//0/x/x/x DQ_B2_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B2_PS_3_0			0xF0	//0/x/x/x DQS_B2_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B2_NS_3_0			0xF	//0/x/x/x DQS_B2_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B3_CHN_B		0xA68	//DQ Register Setting B3 Channel B
    #define D0F3_DQ_B3_PS_3_0			0xF000	//0/x/x/x DQ_B3_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B3_NS_3_0			0xF00	//0/x/x/x DQ_B3_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B3_PS_3_0			0xF0	//0/x/x/x DQS_B3_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B3_NS_3_0			0xF	//0/x/x/x DQS_B3_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B4_CHN_B		0xA6A	//DQ Register Setting B4 Channel B
    #define D0F3_DQ_B4_PS_3_0			0xF000	//0/x/x/x DQ_B4_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B4_NS_3_0			0xF00	//0/x/x/x DQ_B4_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B4_PS_3_0			0xF0	//0/x/x/x DQS_B4_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B4_NS_3_0			0xF	//0/x/x/x DQS_B4_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B5_CHN_B		0xA6C	//DQ Register Setting B5 Channel B
    #define D0F3_DQ_B5_PS_3_0			0xF000	//0/x/x/x DQ_B5_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B5_NS_3_0			0xF00	//0/x/x/x DQ_B5_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B5_PS_3_0			0xF0	//0/x/x/x DQS_B5_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B5_NS_3_0			0xF	//0/x/x/x DQS_B5_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B6_CHN_B		0xA6E	//DQ Register Setting B6 Channel B
    #define D0F3_DQ_B6_PS_3_0			0xF000	//0/x/x/x DQ_B6_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B6_NS_3_0			0xF00	//0/x/x/x DQ_B6_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B6_PS_3_0			0xF0	//0/x/x/x DQS_B6_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B6_NS_3_0			0xF	//0/x/x/x DQS_B6_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B7_CHN_B		0xA70	//DQ Register Setting B7 Channel B
    #define D0F3_DQ_B7_PS_3_0			0xF000	//0/x/x/x DQ_B7_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B7_NS_3_0			0xF00	//0/x/x/x DQ_B7_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B7_PS_3_0			0xF0	//0/x/x/x DQS_B7_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B7_NS_3_0			0xF	//0/x/x/x DQS_B7_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_B8_CHN_B		0xA72	//DQ Register Setting B8 Channel B
    #define D0F3_DQ_B8_PS_3_0			0xF000	//0/x/x/x DQ_B8_PS[3:0] DQ P Driving Control
    #define D0F3_DQ_B8_NS_3_0			0xF00	//0/x/x/x DQ_B8_NS[3:0] DQ N Driving Control
    #define D0F3_DQS_B8_PS_3_0			0xF0	//0/x/x/x DQS_B8_PS[3:0] DQ P Driving Control
    #define D0F3_DQS_B8_NS_3_0			0xF	//0/x/x/x DQS_B8_NS[3:0] DQ N Driving Control
#define D0F3_DQ_REG_SETTING_A0_CHN_A_Z1		0xA74	//DQ Register Setting A0 Channel A
    #define D0F3_DQ_SET_A0_P_3_0			0xF000	//0/x/x/x DQ_SET_A0_P[3:0] EQ_SET_P Control for bdddrdq PHY A0
    #define D0F3_DQ_SET_A0_N_3_0			0xF00	//0/x/x/x DQ_SET_A0_N[3:0] EQ_SET_N Control for bdddrdq PHY A0
    #define D0F3_DQS_SET_A0_P_3_0			0xF0	//0/x/x/x DQS_SET_A0_P[3:0] EQ_SET_P Control for bdddrdqs PHY A0
    #define D0F3_DQS_SET_A0_N_3_0			0xF	//0/x/x/x DQS_SET_A0_N[3:0] EQ_SET_N Control for bdddrdqs PHY A0
#define D0F3_DQ_REG_SETTING_A1_CHN_A_Z1		0xA76	//DQ Register Setting A1 Channel A
    #define D0F3_DQ_SET_A1_P_3_0			0xF000	//0/x/x/x DQ_SET_A1_P[3:0] EQ_SET_P CONtrol for bdddrdq PHY A1
    #define D0F3_DQ_SET_A1_N_3_0			0xF00	//0/x/x/x DQ_SET_A1_N[3:0] EQ_SET_N CONtrol for bdddrdq PHY A1
    #define D0F3_DQS_SET_A1_P_3_0			0xF0	//0/x/x/x DQS_SET_A1_P[3:0] EQ_SET_P CONtrol for bdddrdqs PHY A1
    #define D0F3_DQS_SET_A1_N_3_0			0xF	//0/x/x/x DQS_SET_A1_N[3:0] EQ_SET_N CONtrol for bdddrdqs PHY A1
#define D0F3_DQ_REG_SETTING_A2_CHN_A_Z1		0xA78	//DQ Register Setting A2 Channel A
    #define D0F3_DQ_SET_A2_P_3_0			0xF000	//0/x/x/x DQ_SET_A2_P[3:0] EQ_SET_P Control for bdddrdq PHY A2
    #define D0F3_DQ_SET_A2_N_3_0			0xF00	//0/x/x/x DQ_SET_A2_N[3:0] EQ_SET_N Control for bdddrdq PHY A2
    #define D0F3_DQS_SET_A2_P_3_0			0xF0	//0/x/x/x DQS_SET_A2_P[3:0] EQ_SET_P Control for bdddrdqs PHY A2
    #define D0F3_DQS_SET_A2_N_3_0			0xF	//0/x/x/x DQS_SET_A2_N[3:0] EQ_SET_N Control for bdddrdqs PHY A2
#define D0F3_DQ_REG_SETTING_A3_CHN_A_Z1		0xA7A	//DQ Register Setting A3 Channel A
    #define D0F3_DQ_SET_A3_P_3_0			0xF000	//0/x/x/x DQ_SET_A3_P[3:0] EQ_SET_P Control for bdddrdq PHY A3
    #define D0F3_DQ_SET_A3_N_3_0			0xF00	//0/x/x/x DQ_SET_A3_N[3:0] EQ_SET_N Control for bdddrdq PHY A3
    #define D0F3_DQS_SET_A3_P_3_0			0xF0	//0/x/x/x DQS_SET_A3_P[3:0] EQ_SET_P Control for bdddrdqs PHY A3
    #define D0F3_DQS_SET_A3_N_3_0			0xF	//0/x/x/x DQS_SET_A3_N[3:0] EQ_SET_N Control for bdddrdqs PHY A3
#define D0F3_DQ_REG_SETTING_A4_CHN_A_Z1		0xA7C	//DQ Register Setting A4 Channel A
    #define D0F3_DQ_SET_A4_P_3_0			0xF000	//0/x/x/x DQ_SET_A4_P[3:0] EQ_SET_P Control for bdddrdq PHY A4
    #define D0F3_DQ_SET_A4_N_3_0			0xF00	//0/x/x/x DQ_SET_A4_N[3:0] EQ_SET_N Control for bdddrdq PHY A4
    #define D0F3_DQS_SET_A4_P_3_0			0xF0	//0/x/x/x DQS_SET_A4_P[3:0] EQ_SET_P Control for bdddrdqs PHY A4
    #define D0F3_DQS_SET_A4_N_3_0			0xF	//0/x/x/x DQS_SET_A4_N[3:0] EQ_SET_N Control for bdddrdqs PHY A4
#define D0F3_DQ_REG_SETTING_A5_CHN_A_Z1		0xA7E	//DQ Register Setting A5 Channel A
    #define D0F3_DQ_SET_A5_P_3_0			0xF000	//0/x/x/x DQ_SET_A5_P[3:0] EQ_SET_P Control for bdddrdq PHY A5
    #define D0F3_DQ_SET_A5_N_3_0			0xF00	//0/x/x/x DQ_SET_A5_N[3:0] EQ_SET_N Control for bdddrdq PHY A5
    #define D0F3_DQS_SET_A5_P_3_0			0xF0	//0/x/x/x DQS_SET_A5_P[3:0] EQ_SET_P Control for bdddrdqs PHY A5
    #define D0F3_DQS_SET_A5_N_3_0			0xF	//0/x/x/x DQS_SET_A5_N[3:0] EQ_SET_N Control for bdddrdqs PHY A5
#define D0F3_DQ_REG_SETTING_A6_CHN_A_Z1		0xA80	//DQ Register Setting A6 Channel A
    #define D0F3_DQ_SET_A6_P_3_0			0xF000	//0/x/x/x DQ_SET_A6_P[3:0] EQ_SET_P Control for bdddrdq PHY A6
    #define D0F3_DQ_SET_A6_N_3_0			0xF00	//0/x/x/x DQ_SET_A6_N[3:0] EQ_SET_N Control for bdddrdq PHY A6
    #define D0F3_DQS_SET_A6_P_3_0			0xF0	//0/x/x/x DQS_SET_A6_P[3:0] EQ_SET_P Control for bdddrdqs PHY A6
    #define D0F3_DQS_SET_A6_N_3_0			0xF	//0/x/x/x DQS_SET_A6_N[3:0] EQ_SET_N Control for bdddrdqs PHY A6
#define D0F3_DQ_REG_SETTING_A7_CHN_A_Z1		0xA82	//DQ Register Setting A7 Channel A
    #define D0F3_DQ_SET_A7_P_3_0			0xF000	//0/x/x/x DQ_SET_A7_P[3:0] EQ_SET_P Control for bdddrdq PHY A7
    #define D0F3_DQ_SET_A7_N_3_0			0xF00	//0/x/x/x DQ_SET_A7_N[3:0] EQ_SET_N Control for bdddrdq PHY A7
    #define D0F3_DQS_SET_A7_P_3_0			0xF0	//0/x/x/x DQS_SET_A7_P[3:0] EQ_SET_P Control for bdddrdqs PHY A7
    #define D0F3_DQS_SET_A7_N_3_0			0xF	//0/x/x/x DQS_SET_A7_N[3:0] EQ_SET_N Control for bdddrdqs PHY A7
#define D0F3_DQ_REG_SETTING_A8_CHN_A_Z1		0xA84	//DQ Register Setting A8 Channel A
    #define D0F3_DQ_SET_A8_P_3_0			0xF000	//0/x/x/x DQ_SET_A8_P[3:0] EQ_SET_P Control for bdddrdq PHY A8
    #define D0F3_DQ_SET_A8_N_3_0			0xF00	//0/x/x/x DQ_SET_A8_N[3:0] EQ_SET_N Control for bdddrdq PHY A8
    #define D0F3_DQS_SET_A8_P_3_0			0xF0	//0/x/x/x DQS_SET_A8_P[3:0] EQ_SET_P Control for bdddrdqs PHY A8
    #define D0F3_DQS_SET_A8_N_3_0			0xF	//0/x/x/x DQS_SET_A8_N[3:0] EQ_SET_N Control for bdddrdqs PHY A8
#define D0F3_DQ_REG_SETTING_B0_CHN_B_Z1		0xA86	//DQ Register Setting B0 Channel B
    #define D0F3_DQ_SET_B0_P_3_0			0xF000	//0/x/x/x DQ_SET_B0_P[3:0] EQ_SET_P Control for bdddrdq PHY B0
    #define D0F3_DQ_SET_B0_N_3_0			0xF00	//0/x/x/x DQ_SET_B0_N[3:0] EQ_SET_N Control for bdddrdq PHY B0
    #define D0F3_DQS_SET_B0_P_3_0			0xF0	//0/x/x/x DQS_SET_B0_P[3:0] EQ_SET_P Control for bdddrdqs PHY B0
    #define D0F3_DQS_SET_B0_N_3_0			0xF	//0/x/x/x DQS_SET_B0_N[3:0] EQ_SET_N Control for bdddrdqs PHY B0
#define D0F3_DQ_REG_SETTING_B1_CHN_B_Z1		0xA88	//DQ Register Setting B1 Channel B
    #define D0F3_DQ_SET_B1_P_3_0			0xF000	//0/x/x/x DQ_SET_B1_P[3:0] EQ_SET_P Control for bdddrdq PHY B1
    #define D0F3_DQ_SET_B1_N_3_0			0xF00	//0/x/x/x DQ_SET_B1_N[3:0] EQ_SET_N Control for bdddrdq PHY B1
    #define D0F3_DQS_SET_B1_P_3_0			0xF0	//0/x/x/x DQS_SET_B1_P[3:0] EQ_SET_P Control for bdddrdqs PHY B1
    #define D0F3_DQS_SET_B1_N_3_0			0xF	//0/x/x/x DQS_SET_B1_N[3:0] EQ_SET_N Control for bdddrdqs PHY B1
#define D0F3_DQ_REG_SETTING_B2_CHN_B_Z1		0xA8A	//DQ Register Setting B2 Channel B
    #define D0F3_DQ_SET_B2_P_3_0			0xF000	//0/x/x/x DQ_SET_B2_P[3:0] EQ_SET_P Control for bdddrdq PHY B2
    #define D0F3_DQ_SET_B2_N_3_0			0xF00	//0/x/x/x DQ_SET_B2_N[3:0] EQ_SET_N Control for bdddrdq PHY B2
    #define D0F3_DQS_SET_B2_P_3_0			0xF0	//0/x/x/x DQS_SET_B2_P[3:0] EQ_SET_P Control for bdddrdqs PHY B2
    #define D0F3_DQS_SET_B2_N_3_0			0xF	//0/x/x/x DQS_SET_B2_N[3:0] EQ_SET_N Control for bdddrdqs PHY B2
#define D0F3_DQ_REG_SETTING_B3_CHN_B_Z1		0xA8C	//DQ Register Setting B3 Channel B
    #define D0F3_DQ_SET_B3_P_3_0			0xF000	//0/x/x/x DQ_SET_B3_P[3:0] EQ_SET_P Control for bdddrdq PHY B3
    #define D0F3_DQ_SET_B3_N_3_0			0xF00	//0/x/x/x DQ_SET_B3_N[3:0] EQ_SET_N Control for bdddrdq PHY B3
    #define D0F3_DQS_SET_B3_P_3_0			0xF0	//0/x/x/x DQS_SET_B3_P[3:0] EQ_SET_P Control for bdddrdqs PHY B3
    #define D0F3_DQS_SET_B3_N_3_0			0xF	//0/x/x/x DQS_SET_B3_N[3:0] EQ_SET_N Control for bdddrdqs PHY B3
#define D0F3_DQ_REG_SETTING_B4_CHN_B_Z1		0xA8E	//DQ Register Setting B4 Channel B
    #define D0F3_DQ_SET_B4_P_3_0			0xF000	//0/x/x/x DQ_SET_B4_P[3:0] EQ_SET_P Control for bdddrdq PHY B4
    #define D0F3_DQ_SET_B4_N_3_0			0xF00	//0/x/x/x DQ_SET_B4_N[3:0] EQ_SET_N Control for bdddrdq PHY B4
    #define D0F3_DQS_SET_B4_P_3_0			0xF0	//0/x/x/x DQS_SET_B4_P[3:0] EQ_SET_P Control for bdddrdqs PHY B4
    #define D0F3_DQS_SET_B4_N_3_0			0xF	//0/x/x/x DQS_SET_B4_N[3:0] EQ_SET_N Control for bdddrdqs PHY B4
#define D0F3_DQ_REG_SETTING_B5_CHN_B_Z1		0xA90	//DQ Register Setting B5 Channel B
    #define D0F3_DQ_SET_B5_P_3_0			0xF000	//0/x/x/x DQ_SET_B5_P[3:0] EQ_SET_P Control for bdddrdq PHY B5
    #define D0F3_DQ_SET_B5_N_3_0			0xF00	//0/x/x/x DQ_SET_B5_N[3:0] EQ_SET_N Control for bdddrdq PHY B5
    #define D0F3_DQS_SET_B5_P_3_0			0xF0	//0/x/x/x DQS_SET_B5_P[3:0] EQ_SET_P Control for bdddrdqs PHY B5
    #define D0F3_DQS_SET_B5_N_3_0			0xF	//0/x/x/x DQS_SET_B5_N[3:0] EQ_SET_N Control for bdddrdqs PHY B5
#define D0F3_DQ_REG_SETTING_B6_CHN_B_Z1		0xA92	//DQ Register Setting B6 Channel B
    #define D0F3_DQ_SET_B6_P_3_0			0xF000	//0/x/x/x DQ_SET_B6_P[3:0] EQ_SET_P Control for bdddrdq PHY B6
    #define D0F3_DQ_SET_B6_N_3_0			0xF00	//0/x/x/x DQ_SET_B6_N[3:0] EQ_SET_N Control for bdddrdq PHY B6
    #define D0F3_DQS_SET_B6_P_3_0			0xF0	//0/x/x/x DQS_SET_B6_P[3:0] EQ_SET_P Control for bdddrdqs PHY B6
    #define D0F3_DQS_SET_B6_N_3_0			0xF	//0/x/x/x DQS_SET_B6_N[3:0] EQ_SET_N Control for bdddrdqs PHY B6
#define D0F3_DQ_REG_SETTING_B7_CHN_B_Z1		0xA94	//DQ Register Setting B7 Channel B
    #define D0F3_DQ_SET_B7_P_3_0			0xF000	//0/x/x/x DQ_SET_B7_P[3:0] EQ_SET_P Control for bdddrdq PHY B7
    #define D0F3_DQ_SET_B7_N_3_0			0xF00	//0/x/x/x DQ_SET_B7_N[3:0] EQ_SET_N Control for bdddrdq PHY B7
    #define D0F3_DQS_SET_B7_P_3_0			0xF0	//0/x/x/x DQS_SET_B7_P[3:0] EQ_SET_P Control for bdddrdqs PHY B7
    #define D0F3_DQS_SET_B7_N_3_0			0xF	//0/x/x/x DQS_SET_B7_N[3:0] EQ_SET_N Control for bdddrdqs PHY B7
#define D0F3_DQ_REG_SETTING_B8_CHN_B_Z1		0xA96	//DQ Register Setting B8 Channel B
    #define D0F3_DQ_SET_B8_P_3_0			0xF000	//0/x/x/x DQ_SET_B8_P[3:0] EQ_SET_P Control for bdddrdq PHY B8
    #define D0F3_DQ_SET_B8_N_3_0			0xF00	//0/x/x/x DQ_SET_B8_N[3:0] EQ_SET_N Control for bdddrdq PHY B8
    #define D0F3_DQS_SET_B8_P_3_0			0xF0	//0/x/x/x DQS_SET_B8_P[3:0] EQ_SET_P Control for bdddrdqs PHY B8
    #define D0F3_DQS_SET_B8_N_3_0			0xF	//0/x/x/x DQS_SET_B8_N[3:0] EQ_SET_N Control for bdddrdqs PHY B8
#define D0F3_VREF_CTL_A0_CHN_A		0xA98	//Vref Control A0 Channel A
    #define D0F3_VREFF3_A0_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A0_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A0_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A0_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A0_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A0_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A0_CTRL_3_0			0xF	//0/x/x/x VREFF0_A0_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A0_CHN_A_Z1		0xA9A	//Vref Control A0 Channel A
    #define D0F3_VREFF7_A0_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A0_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A0_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A0_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A0_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A0_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A0_CTRL_3_0			0xF	//0/x/x/x VREFF4_A0_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A0_CHN_A_Z2		0xA9C	//Vref Control A0 Channel A
    #define D0F3_D0F3_RXA9DB15			BIT15	//0/x/x/x Reserved
    #define D0F3_VREF_A_MODE2			BIT14	//0/x/x/x VREF Control for Channel A
    #define D0F3_VREFC_A0_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A0_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXA9DB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A0_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A0_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_A1_CHN_A		0xA9E	//Vref Control A1 Channel A
    #define D0F3_VREFF3_A1_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A1_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A1_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A1_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A1_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A1_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A1_CTRL_3_0			0xF	//0/x/x/x VREFF0_A1_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A1_CHN_A_Z1		0xAA0	//Vref Control A1 Channel A
    #define D0F3_VREFF7_A1_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A1_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A1_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A1_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A1_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A1_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A1_CTRL_3_0			0xF	//0/x/x/x VREFF4_A1_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A1_CHN_A_Z2		0xAA2	//Vref Control A1 Channel A
    #define D0F3_D0F3_RXAA3B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_A1_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A1_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAA3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A1_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A1_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_A2_CHN_A		0xAA4	//Vref Control A2 Channel A
    #define D0F3_VREFF3_A2_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A2_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A2_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A2_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A2_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A2_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A2_CTRL_3_0			0xF	//0/x/x/x VREFF0_A2_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A2_CHN_A_Z1		0xAA6	//Vref Control A2 Channel A
    #define D0F3_VREFF7_A2_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A2_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A2_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A2_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A2_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A2_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A2_CTRL_3_0			0xF	//0/x/x/x VREFF4_A2_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A2_CHN_A_Z2		0xAA8	//Vref Control A2 Channel A
    #define D0F3_D0F3_RXAA9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_A2_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A2_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAA9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A2_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A2_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_A3_CHN_A		0xAAA	//Vref Control A3 Channel A
    #define D0F3_VREFF3_A3_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A3_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A3_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A3_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A3_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A3_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A3_CTRL_3_0			0xF	//0/x/x/x VREFF0_A3_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A3_CHN_A_Z1		0xAAC	//Vref Control A3 Channel A
    #define D0F3_VREFF7_A3_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A3_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A3_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A3_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A3_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A3_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A3_CTRL_3_0			0xF	//0/x/x/x VREFF4_A3_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A3_CHN_A_Z2		0xAAE	//Vref Control A3 Channel A
    #define D0F3_D0F3_RXAAFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_A3_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A3_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAAFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A3_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A3_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_A4_CHN_A		0xAB0	//Vref Control A4 Channel A
    #define D0F3_VREFF3_A4_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A4_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A4_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A4_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A4_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A4_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A4_CTRL_3_0			0xF	//0/x/x/x VREFF0_A4_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A4_CHN_A_Z1		0xAB2	//Vref Control A4 Channel A
    #define D0F3_VREFF7_A4_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A4_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A4_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A4_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A4_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A4_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A4_CTRL_3_0			0xF	//0/x/x/x VREFF4_A4_CTRL[3:0] VREF control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A4_CHN_A_Z2		0xAB4	//Vref Control A4 Channel A
    #define D0F3_D0F3_RXAB5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_A4_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A4_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAB5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A4_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A4_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_A5_CHN_A		0xAB6	//Vref Control A5 Channel A
    #define D0F3_VREFF3_A5_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A5_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A5_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A5_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A5_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A5_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A5_CTRL_3_0			0xF	//0/x/x/x VREFF0_A5_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A5_CHN_A_Z1		0xAB8	//Vref Control A5 Channel A
    #define D0F3_VREFF7_A5_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A5_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A5_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A5_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A5_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A5_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A5_CTRL_3_0			0xF	//0/x/x/x VREFF4_A5_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A5_CHN_A_Z2		0xABA	//Vref Control A5 Channel A
    #define D0F3_D0F3_RXABBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_A5_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A5_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXABBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A5_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A5_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_A6_CHN_A		0xABC	//Vref Control A6 Channel A
    #define D0F3_VREFF3_A6_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A6_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A6_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A6_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A6_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A6_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A6_CTRL_3_0			0xF	//0/x/x/x VREFF0_A6_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A6_CHN_A_Z1		0xABE	//Vref Control A6 Channel A
    #define D0F3_VREFF7_A6_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A6_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A6_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A6_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A6_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A6_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A6_CTRL_3_0			0xF	//0/x/x/x VREFF4_A6_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A6_CHN_A_Z2		0xAC0	//Vref Control A6 Channel A
    #define D0F3_D0F3_RXAC1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_A6_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A6_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAC1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A6_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A6_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_A7_CHN_A		0xAC2	//Vref Control A7 Channel A
    #define D0F3_VREFF3_A7_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A7_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A7_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A7_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A7_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A7_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A7_CTRL_3_0			0xF	//0/x/x/x VREFF0_A7_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A7_CHN_A_Z1		0xAC4	//Vref Control A7 Channel A
    #define D0F3_VREFF7_A7_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A7_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A7_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A7_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A7_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A7_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A7_CTRL_3_0			0xF	//0/x/x/x VREFF4_A7_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A7_CHN_A_Z2		0xAC6	//Vref Control A7 Channel A
    #define D0F3_D0F3_RXAC7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_A7_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A7_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAC7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A7_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A7_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_A8_CHN_A		0xAC8	//Vref Control A8 Channel A
    #define D0F3_VREFF3_A8_CTRL_3_0			0xF000	//0/x/x/x VREFF3_A8_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_A8_CTRL_3_0			0xF00	//0/x/x/x VREFF2_A8_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_A8_CTRL_3_0			0xF0	//0/x/x/x VREFF1_A8_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_A8_CTRL_3_0			0xF	//0/x/x/x VREFF0_A8_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_A8_CHN_A_Z1		0xACA	//Vref Control A8 Channel A
    #define D0F3_VREFF7_A8_CTRL_3_0			0xF000	//0/x/x/x VREFF7_A8_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_A8_CTRL_3_0			0xF00	//0/x/x/x VREFF6_A8_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_A8_CTRL_3_0			0xF0	//0/x/x/x VREFF5_A8_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_A8_CTRL_3_0			0xF	//0/x/x/x VREFF4_A8_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_A8_CHN_A_Z2		0xACC	//Vref Control A8 Channel A
    #define D0F3_D0F3_RXACDB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_A8_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_A8_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXACDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_A8_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_A8_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B0_CHN_B		0xACE	//Vref Control B0 Channel B
    #define D0F3_VREFF3_B0_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B0_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B0_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B0_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B0_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B0_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B0_CTRL_3_0			0xF	//0/x/x/x VREFF0_B0_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B0_CHN_B_Z1		0xAD0	//Vref Control B0 Channel B
    #define D0F3_VREFF7_B0_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B0_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B0_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B0_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B0_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B0_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B0_CTRL_3_0			0xF	//0/x/x/x VREFF4_B0_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B0_CHN_B_Z2		0xAD2	//Vref Control B0 Channel B
    #define D0F3_D0F3_RXAD3B15			BIT15	//0/x/x/x Reserved
    #define D0F3_VREF_B_MODE2			BIT14	//0/x/x/x VREF Control for Channel B
    #define D0F3_VREFC_B0_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B0_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAD3B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B0_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B0_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B1_CHN_B		0xAD4	//Vref Control B1 Channel B
    #define D0F3_VREFF3_B1_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B1_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B1_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B1_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B1_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B1_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B1_CTRL_3_0			0xF	//0/x/x/x VREFF0_B1_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B1_CHN_B_Z1		0xAD6	//Vref Control B1 Channel B
    #define D0F3_VREFF7_B1_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B1_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B1_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B1_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B1_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B1_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B1_CTRL_3_0			0xF	//0/x/x/x VREFF4_B1_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B1_CHN_B_Z2		0xAD8	//Vref Control B1 Channel B
    #define D0F3_D0F3_RXAD9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_B1_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B1_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAD9B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B1_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B1_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B2_CHN_B		0xADA	//Vref Control B2 Channel B
    #define D0F3_VREFF3_B2_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B2_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B2_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B2_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B2_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B2_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B2_CTRL_3_0			0xF	//0/x/x/x VREFF0_B2_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B2_CHN_B_Z1		0xADC	//Vref Control B2 Channel B
    #define D0F3_VREFF7_B2_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B2_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B2_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B2_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B2_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B2_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B2_CTRL_3_0			0xF	//0/x/x/x VREFF4_B2_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B2_CHN_B_Z2		0xADE	//Vref Control B2 Channel B
    #define D0F3_D0F3_RXADFB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_B2_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B2_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXADFB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B2_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B2_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B3_CHN_B		0xAE0	//Vref Control B3 Channel B
    #define D0F3_VREFF3_B3_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B3_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B3_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B3_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B3_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B3_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B3_CTRL_3_0			0xF	//0/x/x/x VREFF0_B3_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B3_CHN_B_Z1		0xAE2	//Vref Control B3 Channel B
    #define D0F3_VREFF7_B3_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B3_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B3_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B3_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B3_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B3_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B3_CTRL_3_0			0xF	//0/x/x/x VREFF4_B3_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B3_CHN_B_Z2		0xAE4	//Vref Control B3 Channel B
    #define D0F3_D0F3_RXAE5B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_B3_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B3_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAE5B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B3_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B3_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B4_CHN_B		0xAE6	//Vref Control B4 Channel B
    #define D0F3_VREFF3_B4_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B4_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B4_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B4_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B4_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B4_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B4_CTRL_3_0			0xF	//0/x/x/x VREFF0_B4_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B4_CHN_B_Z1		0xAE8	//Vref Control B4 Channel B
    #define D0F3_VREFF7_B4_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B4_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B4_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B4_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B4_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B4_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B4_CTRL_3_0			0xF	//0/x/x/x VREFF4_B4_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B4_CHN_B_Z2		0xAEA	//Vref Control B4 Channel B
    #define D0F3_D0F3_RXAEBB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_B4_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B4_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAEBB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B4_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B4_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B5_CHN_B		0xAEC	//Vref Control B5 Channel B
    #define D0F3_VREFF3_B5_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B5_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B5_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B5_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B5_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B5_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B5_CTRL_3_0			0xF	//0/x/x/x VREFF0_B5_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B5_CHN_B_Z1		0xAEE	//Vref Control B5 Channel B
    #define D0F3_VREFF7_B5_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B5_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B5_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B5_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B5_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B5_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B5_CTRL_3_0			0xF	//0/x/x/x VREFF4_B5_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B5_CHN_B_Z2		0xAF0	//Vref Control B5 Channel B
    #define D0F3_D0F3_RXAF1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_B5_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B5_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAF1B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B5_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B5_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B6_CHN_B		0xAF2	//Vref Control B6 Channel B
    #define D0F3_VREFF3_B6_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B6_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B6_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B6_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B6_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B6_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B6_CTRL_3_0			0xF	//0/x/x/x VREFF0_B6_CTRL[3:0] VREF Control For Bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B6_CHN_B_Z1		0xAF4	//Vref Control B6 Channel B
    #define D0F3_VREFF7_B6_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B6_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B6_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B6_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B6_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B6_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B6_CTRL_3_0			0xF	//0/x/x/x VREFF4_B6_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B6_CHN_B_Z2		0xAF6	//Vref Control B6 Channel B
    #define D0F3_D0F3_RXAF7B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_B6_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B6_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAF7B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B6_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B6_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B7_CHN_B		0xAF8	//Vref Control B7 Channel B
    #define D0F3_VREFF3_B7_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B7_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B7_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B7_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B7_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B7_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B7_CTRL_3_0			0xF	//0/x/x/x VREFF0_B7_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B7_CHN_B_Z1		0xAFA	//Vref Control B7 Channel B
    #define D0F3_VREFF7_B7_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B7_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B7_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B7_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B7_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B7_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B7_CTRL_3_0			0xF	//0/x/x/x VREFF4_B7_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B7_CHN_B_Z2		0xAFC	//Vref Control B7 Channel B
    #define D0F3_D0F3_RXAFCB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_B7_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B7_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXAFDB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B7_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B7_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_VREF_CTL_B8_CHN_B		0xAFE	//Vref Control B8 Channel B
    #define D0F3_VREFF3_B8_CTRL_3_0			0xF000	//0/x/x/x VREFF3_B8_CTRL[3:0] VREF Control for bdddrdq Bit DQ3
    #define D0F3_VREFF2_B8_CTRL_3_0			0xF00	//0/x/x/x VREFF2_B8_CTRL[3:0] VREF Control for bdddrdq Bit DQ2
    #define D0F3_VREFF1_B8_CTRL_3_0			0xF0	//0/x/x/x VREFF1_B8_CTRL[3:0] VREF Control for bdddrdq Bit DQ1
    #define D0F3_VREFF0_B8_CTRL_3_0			0xF	//0/x/x/x VREFF0_B8_CTRL[3:0] VREF Control for bdddrdq Bit DQ0
#define D0F3_VREF_CTL_B8_CHN_B_Z1		0xB00	//Vref Control B8 Channel B
    #define D0F3_VREFF7_B8_CTRL_3_0			0xF000	//0/x/x/x VREFF7_B8_CTRL[3:0] VREF Control for bdddrdq Bit DQ7
    #define D0F3_VREFF6_B8_CTRL_3_0			0xF00	//0/x/x/x VREFF6_B8_CTRL[3:0] VREF Control for bdddrdq Bit DQ6
    #define D0F3_VREFF5_B8_CTRL_3_0			0xF0	//0/x/x/x VREFF5_B8_CTRL[3:0] VREF Control for bdddrdq Bit DQ5
    #define D0F3_VREFF4_B8_CTRL_3_0			0xF	//0/x/x/x VREFF4_B8_CTRL[3:0] VREF Control for bdddrdq Bit DQ4
#define D0F3_VREF_CTL_B8_CHN_B_Z2		0xB02	//Vref Control B8 Channel B
    #define D0F3_D0F3_RXB03B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_VREFC_B8_CTRLH_5_0			0x3F00	//0/x/x/x VREFFC_B8_CTRL[5:0] VREFC Control for padVCC4_MEM
    #define D0F3_D0F3_RXB03B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_VREFC_B8_CTRLL_5_0			0x3F	//0/x/x/x VREFFC_B8_CTRL[5:0] VREFC Control for padVCC4_MEM
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_CHN_A		0xB04	//ADLL_S24+MUX_PI for TX Channel A
    #define D0F3_D0F3_RXB05B15			BIT15	//0/x/x/x Reserved
    #define D0F3_DLL_A_CKRANGE_2_0			(BIT12 + BIT13 + BIT14)	//111b/x/x/x Select Corresponding Setting for Different DCLK Frequency
    #define D0F3_D0F3_RXB05B11			BIT11	//0/x/x/x Reserved
    #define D0F3_DLL_A_REFDLY_2_0			(BIT8 + BIT9 + BIT10)	//011b/x/x/x ADLL reference  Clock Delay Setting to Correct Delay Line
    #define D0F3_VCDL_BYPASS_A			BIT7	//0/x/x/x Bypass PHYA VCDL for Function Test on ATE
    #define D0F3_DLL_A_V2VSEL_2_0			(BIT4 + BIT5 + BIT6)	//100b/x/x/x Tuning Voltage Range of BIASP/BIASN for Analog Delay Line
    #define D0F3_DLL_A_BWSEL_1_0			(BIT2 + BIT3)	//01b/x/x/x Tuning Charge Current Value for Charge Pump in ADLL to Tuning Bandwidth
    #define D0F3_RDLL_A_WEAKLOCK			BIT1	//0/x/x/x Weak Lock Control for Lower Power
    #define D0F3_DLL_A_WEAKLOCK_GATE			BIT0	//0/x/x/x Gating DCLK When DLL_WEAKLOCK Enable
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_CHN_B		0xB16	//ADLL_S24+MUX_PI for TX Channel B
    #define D0F3_D0F3_RXB17B15			BIT15	//0/x/x/x Reserved
    #define D0F3_DLL_B_CKRANGE_2_0			(BIT12 + BIT13 + BIT14)	//111b/x/x/x Select Corresponding Setting for Different DCLK Frequency
    #define D0F3_D0F3_RXB17B11			BIT11	//0/x/x/x Reserved
    #define D0F3_DLL_B_REFDLY_2_0			(BIT8 + BIT9 + BIT10)	//011b/x/x/x ADLL reference  Clock Delay Setting to Correct Delay Line
    #define D0F3_VCDL_BYPASS_B			BIT7	//0/x/x/x Bypass PHYA VCDL for Function Test on ATE
    #define D0F3_DLL_B_V2VSEL_2_0			(BIT4 + BIT5 + BIT6)	//100b/x/x/x Tuning Voltage Range of BIASP/BIASN for Analog Delay Line
    #define D0F3_DLL_B_BWSEL_1_0			(BIT2 + BIT3)	//01b/x/x/x Tuning Charge Current Value for Charge Pump in ADLL to Tuning Bandwidth
    #define D0F3_RDLL_B_WEAKLOCK			BIT1	//0/x/x/x Weak Lock Control for Lower Power
    #define D0F3_DLL_B_WEAKLOCK_GATE			BIT0	//0/x/x/x Gating DCLK When DLL_WEAKLOCK Enable
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_A0_A1_CHN_A		0xB26	//ADLL_S24+MUX_PI for TX A0/A1 Channel A
    #define D0F3_DCLK800_A1_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY A1 VCDL 800M Clock Duty Tuning ss corner setup=10ps
    #define D0F3_DCLK800_A1_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY A1 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A1_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY A1 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A1_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY A1 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_A0_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A0 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_A0_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A0 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A0_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A0 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A0_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A0 VCDL 1600M Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_A2_A3_CHN_A		0xB28	//ADLL_S24+MUX_PI for TX A2/A3 Channel A
    #define D0F3_DCLK800_A3_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY A3 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_A3_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY A3 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A3_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY A3 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A3_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY A3 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_A2_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A2 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_A2_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A2 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A2_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A2 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A2_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A2 VCDL 1600M Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_A5_A4_CHN_A		0xB2A	//ADLL_S24+MUX_PI for TX A5/A4 Channel A
    #define D0F3_DCLK800_A5_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY A5 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_A5_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY A5 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A5_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY A5 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A5_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY A5 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_A4_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A4 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_A4_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A4 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A4_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A4 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A4_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A4 VCDL 1600M Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_A7_A6_CHN_A		0xB2C	//ADLL_S24+MUX_PI for TX A7/A6 Channel A
    #define D0F3_DCLK800_A7_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY A7 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_A7_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY A7 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A7_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY A7 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A7_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY A7 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_A6_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A6 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_A6_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A6 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A6_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A6 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A6_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A6 VCDL 1600M Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_A8_B8_CHN_A_B		0xB2E	//ADLL_S24+MUX_PI for TX A8/B8 Channel A/B
    #define D0F3_DCLK800_B8_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY B8 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B8_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY B8 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B8_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY B8 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B8_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY B8 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_A8_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A8 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_A8_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A8 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_A8_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A8 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_A8_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A8 VCDL 1600M Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_B0_B1_CHN_B		0xB30	//ADLL_S24+MUX_PI for TX B0/B1 Channel B
    #define D0F3_DCLK800_B1_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY B1 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B1_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY B1 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B1_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY B1 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B1_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY B1 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_B0_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B0 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B0_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B0 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B0_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B0 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B0_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B0 VCDL 1600M Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_B2_B3_CHN_B		0xB32	//ADLL_S24+MUX_PI for TX B2/B3 Channel B
    #define D0F3_DCLK800_B3_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY B3 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B3_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY B3 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B3_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY B3 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B3_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY B3 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_B2_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B2 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B2_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B2 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B2_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B2 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B2_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B2 VCDL 1600M Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_B5_B4_CHN_B		0xB34	//ADLL_S24+MUX_PI for TX B5/B4 Channel B
    #define D0F3_DCLK800_B5_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY B5 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B5_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY B5 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B5_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY B5 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B5_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY B5 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_B4_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B4 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B4_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B4 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B4_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B4 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B4_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B4 VCDL 1600M Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_TX_B7_B6_CHN_B		0xB36	//ADLL_S24+MUX_PI for TX B7/B6 Channel B
    #define D0F3_DCLK800_B7_SRCTRL_1_0			(BIT14 + BIT15)	//0/x/x/x PHY B7 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B7_SFCTRL_1_0			(BIT12 + BIT13)	//0/x/x/x PHY B7 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B7_SRCTRL_1_0			(BIT10 + BIT11)	//0/x/x/x PHY B7 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B7_SFCTRL_1_0			(BIT8 + BIT9)	//0/x/x/x PHY B7 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK800_B6_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B6 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK800_B6_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B6 VCDL 800M Clock Duty Tuning
    #define D0F3_DCLK1600_B6_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B6 VCDL 1600M Clock Duty Tuning
    #define D0F3_DCLK1600_B6_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B6 VCDL 1600M Clock Duty Tuning
#define D0F3_RXDIO_CTL_REG_A0_CHN_A		0xB3C	//RXDIO Control Register A0 Channel A
    #define D0F3_RXSAMPLER_A0_EN			BIT15	//0/x/x/x PHY A0 RX Sampler Enable
    #define D0F3_CNT_A0_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A0 FIFO
    #define D0F3_PD_BIAS_A0			BIT12	//1b/x/x/x Power down Control of PHY A0 Ibias
    #define D0F3_PD_VREF_A0			BIT11	//1b/x/x/x Power down control of PHY A0 VREF
    #define D0F3_VREF_MODE_A0			BIT10	//0/x/x/x PHY A0 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_A0			BIT9	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A0			BIT8	//1b/x/x/x PHY A0 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A0			BIT7	//0/x/x/x PHY A0 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A0_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A0_TUNE_5_0			0x3F	//0/x/x/x PHY A0 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_A1_CHN_A		0xB3E	//RXDIO Control Register A1 Channel A
    #define D0F3_RXSAMPLER_A1_EN			BIT15	//0/x/x/x PHY A1 RX Sampler Enable
    #define D0F3_CNT_A1_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A1 FIFO
    #define D0F3_PD_BIAS_A1			BIT12	//1b/x/x/x Power down Control of PHY A1 Ibias
    #define D0F3_PD_VREF_A1			BIT11	//1b/x/x/x Power down Control of PHY A1 VREF
    #define D0F3_VREF_MODE_A1			BIT10	//0/x/x/x PHY A1 VREF Mode Selection
    #define D0F3_VREF_OVERLAP_A1			BIT9	//0/x/x/x PHY A1 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A1			BIT8	//1b/x/x/x PHY A1 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A1			BIT7	//0/x/x/x PHY A1 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A1_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A1_TUNE_5_0			0x3F	//0/x/x/x PHY A1 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_A2_CHN_A		0xB40	//RXDIO Control Register A2 Channel A
    #define D0F3_RXSAMPLER_A2_EN			BIT15	//0/x/x/x PHY A2 RX Sampler Enable
    #define D0F3_CNT_A2_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A2 FIFO
    #define D0F3_PD_BIAS_A2			BIT12	//1b/x/x/x Power down Control of PHY A2 Ibias
    #define D0F3_PD_VREF_A2			BIT11	//1b/x/x/x Power down Control of PHY A2 VREF
    #define D0F3_VREF_MODE_A2			BIT10	//0/x/x/x PHY A2 VREF Mode Selection
    #define D0F3_VREF_OVERLAP_A2			BIT9	//0/x/x/x PHY A2 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A2			BIT8	//1b/x/x/x PHY A2 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A2			BIT7	//0/x/x/x PHY A2 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A2_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A2_TUNE_5_0			0x3F	//0/x/x/x PHY A2 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_A3_CHN_A		0xB42	//RXDIO Control Register A3 Channel A
    #define D0F3_RXSAMPLER_A3_EN			BIT15	//0/x/x/x PHY A3 RX Sampler Enable
    #define D0F3_CNT_A3_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A3 FIFO
    #define D0F3_PD_BIAS_A3			BIT12	//1b/x/x/x Power down Control of PHY A3 Ibias
    #define D0F3_PD_VREF_A3			BIT11	//1b/x/x/x Power down Control of PHY A3 VREF
    #define D0F3_VREF_MODE_A3			BIT10	//0/x/x/x PHY A3 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_A3			BIT9	//0/x/x/x PHY A3 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A3			BIT8	//1b/x/x/x PHY A3 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A3			BIT7	//0/x/x/x PHY A3 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A3_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A3_TUNE_5_0			0x3F	//0/x/x/x PHY A3 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_A4_CHN_A		0xB44	//RXDIO Control Register A4 Channel A
    #define D0F3_RXSAMPLER_A4_EN			BIT15	//0/x/x/x PHY A4 RX Sampler Enable
    #define D0F3_CNT_A4_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A4 FIFO
    #define D0F3_PD_BIAS_A4			BIT12	//1b/x/x/x Power down Control of PHY A4 Ibias
    #define D0F3_PD_VREF_A4			BIT11	//1b/x/x/x Power down Control of PHY A4 VREF
    #define D0F3_VREF_MODE_A4			BIT10	//0/x/x/x PHY A4 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_A4			BIT9	//0/x/x/x PHY A4 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A4			BIT8	//1b/x/x/x PHY A4 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A4			BIT7	//0/x/x/x PHY A4 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A4_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A4_TUNE_5_0			0x3F	//0/x/x/x PHY A4 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_A5_CHN_A		0xB46	//RXDIO Control Register A5 Channel A
    #define D0F3_RXSAMPLER_A5_EN			BIT15	//0/x/x/x PHY A5 RX Sampler Enable
    #define D0F3_CNT_A5_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A5 FIFO
    #define D0F3_PD_BIAS_A5			BIT12	//1b/x/x/x Power down Control of PHY A5 Ibias
    #define D0F3_PD_VREF_A5			BIT11	//1b/x/x/x Power down Control of PHY A5 VREF
    #define D0F3_VREF_MODE_A5			BIT10	//0/x/x/x PHY A5 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_A5			BIT9	//0/x/x/x PHY A5 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A5			BIT8	//1b/x/x/x PHY A5 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A5			BIT7	//0/x/x/x PHY A5 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A5_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A5_TUNE_5_0			0x3F	//0/x/x/x PHY A5 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_A6_CHN_A		0xB48	//RXDIO Control Register A6 Channel A
    #define D0F3_RXSAMPLER_A6_EN			BIT15	//0/x/x/x PHY A6 RX Sampler Enable
    #define D0F3_CNT_A6_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A6 FIFO
    #define D0F3_PD_BIAS_A6			BIT12	//1b/x/x/x Power down Control of PHY A6 Ibias
    #define D0F3_PD_VREF_A6			BIT11	//1b/x/x/x Power down Control of PHY A6 VREF
    #define D0F3_VREF_MODE_A6			BIT10	//0/x/x/x PHY A6 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_A6			BIT9	//0/x/x/x PHY A6 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A6			BIT8	//1b/x/x/x PHY A6 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A6			BIT7	//0/x/x/x PHY A6 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A6_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A6_TUNE_5_0			0x3F	//0/x/x/x PHY A6 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_A7_CHN_A		0xB4A	//RXDIO Control Register A7 Channel A
    #define D0F3_RXSAMPLER_A7_EN			BIT15	//0/x/x/x PHY A7 RX Sampler Enable
    #define D0F3_CNT_A7_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A7 FIFO
    #define D0F3_PD_BIAS_A7			BIT12	//1b/x/x/x Power down Control of PHY A7 Ibias
    #define D0F3_PD_VREF_A7			BIT11	//1b/x/x/x Power down Control of PHY A7 VREF
    #define D0F3_VREF_MODE_A7			BIT10	//0/x/x/x PHY A7 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_A7			BIT9	//0/x/x/x PHY A7 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A7			BIT8	//1b/x/x/x PHY A7 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A7			BIT7	//0/x/x/x PHY A7 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A7_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A7_TUNE_5_0			0x3F	//0/x/x/x PHY A7 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_A8_CHN_B		0xB4C	//RXDIO Control Register A8 Channel B
    #define D0F3_RXSAMPLER_A8_EN			BIT15	//0/x/x/x PHY A8 RX Sampler Enable
    #define D0F3_CNT_A8_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to A8 FIFO
    #define D0F3_PD_BIAS_A8			BIT12	//1b/x/x/x Power down Control of PHY A8 Ibias
    #define D0F3_PD_VREF_A8			BIT11	//1b/x/x/x Power down Control of PHY A8 VREF
    #define D0F3_VREF_MODE_A8			BIT10	//0/x/x/x PHY A8 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_A8			BIT9	//0/x/x/x PHY A8 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_A8			BIT8	//1b/x/x/x PHY A8 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_A8			BIT7	//0/x/x/x PHY A8 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_A8_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_A8_TUNE_5_0			0x3F	//0/x/x/x PHY A8 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B0_CHN_B		0xB4E	//RXDIO Control Register B0 Channel B
    #define D0F3_RXSAMPLER_B0_EN			BIT15	//0/x/x/x PHY B0 RX Sampler Enable
    #define D0F3_CNT_B0_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B0 FIFO
    #define D0F3_PD_BIAS_B0			BIT12	//1b/x/x/x Power down Control of PHY B0 Ibias
    #define D0F3_PD_VREF_B0			BIT11	//1b/x/x/x Power down Control of PHY B0 VREF
    #define D0F3_VREF_MODE_B0			BIT10	//0/x/x/x PHY B0 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_B0			BIT9	//0/x/x/x PHY B0 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B0			BIT8	//1b/x/x/x PHY B0 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B0			BIT7	//0/x/x/x PHY B0 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B0_TEST			BIT6	//0/x/x/x PHY A0 Overlap mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_B0_TUNE_5_0			0x3F	//0/x/x/x PHY B0 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B1_CHN_B		0xB50	//RXDIO Control Register B1 Channel B
    #define D0F3_RXSAMPLER_B1_EN			BIT15	//0/x/x/x PHY B1 RX Sampler Enable
    #define D0F3_CNT_B1_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B1 FIFO
    #define D0F3_PD_BIAS_B1			BIT12	//1b/x/x/x Power down Control of PHY B1 Ibias
    #define D0F3_PD_VREF_B1			BIT11	//1b/x/x/x Power down Control of PHY B1 VREF
    #define D0F3_VREF_MODE_B1			BIT10	//0/x/x/x PHY B1 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_B1			BIT9	//0/x/x/x PHY B1 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B1			BIT8	//1b/x/x/x PHY B1 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B1			BIT7	//0/x/x/x PHY B1 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B1_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_B1_TUNE_5_0			0x3F	//0/x/x/x PHY B1 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B2_CHN_B		0xB52	//RXDIO Control Register B2 Channel B
    #define D0F3_RXSAMPLER_B2_EN			BIT15	//0/x/x/x PHY B2 RX Sampler Enable
    #define D0F3_CNT_B2_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B2 FIFO
    #define D0F3_PD_BIAS_B2			BIT12	//1b/x/x/x Power down Control of PHY B2 Ibias
    #define D0F3_PD_VREF_B2			BIT11	//1b/x/x/x Power down Control of PHY B2 VREF
    #define D0F3_VREF_MODE_B2			BIT10	//0/x/x/x PHY B2 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_B2			BIT9	//0/x/x/x PHY B2 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B2			BIT8	//1b/x/x/x PHY B2 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B2			BIT7	//0/x/x/x PHY B2 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B2_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_B2_TUNE_5_0			0x3F	//0/x/x/x PHY B2 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B3_CHN_B		0xB54	//RXDIO Control Register B3 Channel B
    #define D0F3_RXSAMPLER_B3_EN			BIT15	//0/x/x/x PHY B3 RX Sampler Enable
    #define D0F3_CNT_B3_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B3 FIFO
    #define D0F3_PD_BIAS_B3			BIT12	//1b/x/x/x Power down Control of PHY B3 Ibias
    #define D0F3_PD_VREF_B3			BIT11	//1b/x/x/x Power down Control of PHY B3 VREF
    #define D0F3_VREF_MODE_B3			BIT10	//0/x/x/x PHY B3 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_B3			BIT9	//0/x/x/x PHY B3 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B3			BIT8	//1b/x/x/x PHY B3 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B3			BIT7	//0/x/x/x PHY B3 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B3_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_B3_TUNE_5_0			0x3F	//0/x/x/x PHY B3 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B4_CHN_B		0xB56	//RXDIO Control Register B4 Channel B
    #define D0F3_RXSAMPLER_B4_EN			BIT15	//0/x/x/x PHY B4 RX Sampler Enable
    #define D0F3_CNT_B4_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B4 FIFO
    #define D0F3_PD_BIAS_B4			BIT12	//1b/x/x/x Power down Control of PHY B4 Ibias
    #define D0F3_PD_VREF_B4			BIT11	//1b/x/x/x Power down Control of PHY B4 VREF
    #define D0F3_VREF_MODE_B4			BIT10	//0/x/x/x PHY B4 VREF Mode Selection
    #define D0F3_VREF_OVERLAP_B4			BIT9	//0/x/x/x PHY B4 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B4			BIT8	//1b/x/x/x PHY B4 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B4			BIT7	//0/x/x/x PHY B4 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B4_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_B4_TUNE_5_0			0x3F	//0/x/x/x PHY B4 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B5_CHN_B		0xB58	//RXDIO Control Register B5 Channel B
    #define D0F3_RXSAMPLER_B5_EN			BIT15	//0/x/x/x PHY B5 RX Sampler Enable
    #define D0F3_CNT_B5_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B5 FIFO
    #define D0F3_PD_BIAS_B5			BIT12	//1b/x/x/x Power down Control of PHY B5 Ibias
    #define D0F3_PD_VREF_B5			BIT11	//1b/x/x/x Power down Control of PHY B5 VREF
    #define D0F3_VREF_MODE_B5			BIT10	//0/x/x/x PHY B5 VREF Mode Selection
    #define D0F3_VREF_OVERLAP_B5			BIT9	//0/x/x/x PHY B5 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B5			BIT8	//1b/x/x/x PHY B5 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B5			BIT7	//0/x/x/x PHY B5 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B5_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_B5_TUNE_5_0			0x3F	//0/x/x/x PHY B5 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B6_CHN_B		0xB5A	//RXDIO Control Register B6 Channel B
    #define D0F3_RXSAMPLER_B6_EN			BIT15	//0/x/x/x PHY B6 RX Sampler Enable
    #define D0F3_CNT_B6_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B6 FIFO
    #define D0F3_PD_BIAS_B6			BIT12	//1b/x/x/x Power down Control of PHY B6 Ibias.
    #define D0F3_PD_VREF_B6			BIT11	//1b/x/x/x Power down Control of PHY B6 VREF
    #define D0F3_VREF_MODE_B6			BIT10	//0/x/x/x PHY B6 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_B6			BIT9	//0/x/x/x PHY B6 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B6			BIT8	//1b/x/x/x PHY B6 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B6			BIT7	//0/x/x/x PHY B6 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B6_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for clock test
    #define D0F3_CTLE_B6_TUNE_5_0			0x3F	//0/x/x/x PHY B6 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B7_CHN_B		0xB5C	//RXDIO Control Register B7 Channel B
    #define D0F3_RXSAMPLER_B7_EN			BIT15	//0/x/x/x PHY B7 RX Sampler Enable
    #define D0F3_CNT_B7_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B7 FIFO
    #define D0F3_PD_BIAS_B7			BIT12	//1b/x/x/x Power down Control of PHY B7 Ibias
    #define D0F3_PD_VREF_B7			BIT11	//1b/x/x/x Power down Control of PHY B7 VREF
    #define D0F3_VREF_MODE_B7			BIT10	//0/x/x/x PHY B7 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_B7			BIT9	//0/x/x/x PHY B7 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B7			BIT8	//1b/x/x/x PHY B7 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B7			BIT7	//0/x/x/x PHY B7 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B7_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_B7_TUNE_5_0			0x3F	//0/x/x/x PHY B7 DQ RX EQ Tuning
#define D0F3_RXDIO_CTL_REG_B8_CHN_B		0xB5E	//RXDIO Control Register B8 Channel B
    #define D0F3_RXSAMPLER_B8_EN			BIT15	//0/x/x/x PHY B8 RX Sampler Enable
    #define D0F3_CNT_B8_DQSOPN_1_0			(BIT13 + BIT14)	//01b/x/x/x Delay of DQSP/DQSN by Sampler to B8 FIFO
    #define D0F3_PD_BIAS_B8			BIT12	//1b/x/x/x Power down Control of PHY B8 Ibias
    #define D0F3_PD_VREF_B8			BIT11	//1b/x/x/x Power down Control of PHY B8 VREF
    #define D0F3_VREF_MODE_B8			BIT10	//0/x/x/x PHY B8 VREF Mode Selection 
    #define D0F3_VREF_OVERLAP_B8			BIT9	//0/x/x/x PHY B8 Overlap Mode for VREF Calibration
    #define D0F3_BIASEN_B8			BIT8	//1b/x/x/x PHY B8 Power down of RX Comparator Bias
    #define D0F3_CTLE_EN_B8			BIT7	//0/x/x/x PHY B8 DQ EQ Enable
    #define D0F3_VREF_OVERLAP_B8_TEST			BIT6	//0/x/x/x PHY A0 Overlap Mode for VREF Calibration for Clock Test
    #define D0F3_CTLE_B8_TUNE_5_0			0x3F	//0/x/x/x PHY B8 DQ RX EQ Tuning
#define D0F3_BDDDRDQ_CTL_REG_A0_CHN_A		0xB60	//Bdddrdq Control Register A0 Channel A
    #define D0F3_DDRMODE_1_0_A			(BIT14 + BIT15)	//11b/x/x/x DDR Mode Select
    #define D0F3_DE_1_0_EN_A0			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A0_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A0_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A0_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A0_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A1_CHN_A		0xB62	//Bdddrdq Control Register A1 Channel A
    #define D0F3_D0F3_RXB63B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_A1			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A1_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A1_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A1_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A1_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A2_CHN_A		0xB64	//Bdddrdq Control Register A2 Channel A
    #define D0F3_D0F3_RXB65B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_A2			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A2_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A2_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A2_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A2_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A3_CHN_A		0xB66	//Bdddrdq Control Register A3 Channel A
    #define D0F3_D0F3_RXB67B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_A3			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A3_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A3_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A3_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A3_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A4_CHN_A		0xB68	//Bdddrdq Control Register A4 Channel A
    #define D0F3_D0F3_RXB69B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_A4			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A4_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A4_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A4_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A4_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A5_CHN_A		0xB6A	//Bdddrdq Control Register A5 Channel A
    #define D0F3_D0F3_RXB6BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_A5			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A5_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A5_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A5_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A5_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A6_CHN_A		0xB6C	//Bdddrdq Control Register A6 Channel A
    #define D0F3_D0F3_RXB6DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_A6			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A6_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A6_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A6_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A6_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A7_CHN_A		0xB6E	//Bdddrdq Control Register A7 Channel A
    #define D0F3_D0F3_RXB6FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_A7			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A7_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A7_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A7_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A7_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A8_CHN_A		0xB70	//Bdddrdq Control Register A8 Channel A
    #define D0F3_D0F3_RXB671_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_A8			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_A8_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_A8_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_A8_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_A8_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B0_CHN_B		0xB72	//Bdddrdq Control Register B0 Channel B
    #define D0F3_DDRMODE_1_0_B			(BIT14 + BIT15)	//11b/x/x/x DDR Mode Select
    #define D0F3_DE_1_0_EN_B0			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B0_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B0_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B0_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B0_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B1_CHN_B		0xB74	//Bdddrdq Control Register B1 Channel B
    #define D0F3_D0F3_RXB75B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_B1			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B1_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B1_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B1_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B1_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B2_CHN_B		0xB76	//Bdddrdq Control Register B2 Channel B
    #define D0F3_D0F3_RXB77B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_B2			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B2_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B2_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B2_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B2_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B3_CHN_B		0xB78	//Bdddrdq Control Register B3 Channel B
    #define D0F3_D0F3_RXB79B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_B3			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B3_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B3_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B3_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B3_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B4_CHN_B		0xB7A	//Bdddrdq Control Register B4 Channel B
    #define D0F3_D0F3_RXB7BB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_B4			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B4_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B4_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B4_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B4_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B5_CHN_B		0xB7C	//Bdddrdq Control Register B5 Channel B
    #define D0F3_D0F3_RXB7DB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_B5			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B5_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B5_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B5_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B5_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B6_CHN_B		0xB7E	//Bdddrdq Control Register B6 Channel B
    #define D0F3_D0F3_RXB7FB_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_B6			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B6_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B6_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B6_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B6_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B7_CHN_B		0xB80	//Bdddrdq Control Register B7 Channel B
    #define D0F3_D0F3_RXB81B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_B7			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B7_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B7_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B7_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B7_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_B8_CHN_B		0xB82	//Bdddrdq Control Register B8 Channel B
    #define D0F3_D0F3_RXB83B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_DE_1_0_EN_B8			(BIT12 + BIT13)	//0/x/x/x DQ TX EQ Setting
    #define D0F3_DQS_DRVMODE_B8_P_2_0			(BIT9 + BIT10 + BIT11)	//110b/x/x/x DQS Output Pull up Resistance
    #define D0F3_DQS_DRVMODE_B8_N_2_0			(BIT6 + BIT7 + BIT8)	//110b/x/x/x DQS Output Pull down Resistance
    #define D0F3_DQ_DRVMODE_B8_P_2_0			(BIT3 + BIT4 + BIT5)	//110b/x/x/x DQ Output Pull up Resistance
    #define D0F3_DQ_DRVMODE_B8_N_2_0			(BIT0 + BIT1 + BIT2)	//110b/x/x/x DQ Output Pull down Resistance
#define D0F3_BDDDRDQ_CTL_REG_A0_CHN_A_Z1		0xB84	//Bdddrdq Control Register A0 Channel A
    #define D0F3_D0F3_RXB85B15			BIT15	//0/x/x/x Reserved
    #define D0F3_ODTMODE_2_0_A			(BIT12 + BIT13 + BIT14)	//0/x/x/x ODT Mode Select
    #define D0F3_VREF_SEL_A			BIT11	//1b/x/x/x VREF Selection
    #define D0F3_D0F3_RXB85B11			BIT10	//0/x/x/x Reserved
    #define D0F3_RXMODE_1_0_A			(BIT8 + BIT9)	//0/x/x/x Internal VREF Range Select for RX
    #define D0F3_VREF_TST_EN_A0			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A0			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB85B_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A0			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_A2_A1_CHN_A		0xB86	//Bdddrdq Control Register A2/A1 Channel A
    #define D0F3_VREF_TST_EN_A2			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A2			(BIT12 + BIT13 + BIT14)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB87B_11_10			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A2			(BIT8 + BIT9)	//0/x/x/x IREF for Test
    #define D0F3_VREF_TST_EN_A1			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A1			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB87B_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A1			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_A4_A3_CHN_A		0xB88	//Bdddrdq Control Register A4/A3 Channel A
    #define D0F3_VREF_TST_EN_A4			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A4			(BIT12 + BIT13 + BIT14)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB89B_11_10			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A4			(BIT8 + BIT9)	//0/x/x/x IREF for Test
    #define D0F3_VREF_TST_EN_A3			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A3			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB89B_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A3			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_A6_A5_CHN_A		0xB8A	//Bdddrdq Control Register A6/A5 Channel A
    #define D0F3_VREF_TST_EN_A6			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A6			(BIT12 + BIT13 + BIT14)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB8BB_11_10			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A6			(BIT8 + BIT9)	//0/x/x/x IREF for Test
    #define D0F3_VREF_TST_EN_A5			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A5			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB8BB_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A5			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_A8_A7_CHN_A		0xB8C	//Bdddrdq Control Register A8/A7 Channel A
    #define D0F3_VREF_TST_EN_A8			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A8			(BIT12 + BIT13 + BIT14)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB8DB_11_10			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A8			(BIT8 + BIT9)	//0/x/x/x IREF for Test
    #define D0F3_VREF_TST_EN_A7			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_A7			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB8DB_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_A7			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_B0_CHN_B_Z1		0xB8E	//Bdddrdq Control Register B0 Channel B
    #define D0F3_D0F3_RXB8FB15			BIT15	//0/x/x/x Reserved
    #define D0F3_ODTMODE_2_0_B			(BIT12 + BIT13 + BIT14)	//0/x/x/x ODT Mode Select
    #define D0F3_VREF_SEL_B			BIT11	//1b/x/x/x VREF Selection
    #define D0F3_D0F3_RXB8FB11			BIT10	//0/x/x/x Reserved
    #define D0F3_RXMODE_1_0_B			(BIT8 + BIT9)	//0/x/x/x Internal VREF Range Select for RX
    #define D0F3_VREF_TST_EN_B0			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B0			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB8FB_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B0			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_B2_B1_CHN_B		0xB90	//Bdddrdq Control Register B2/B1 Channel B
    #define D0F3_VREF_TST_EN_B2			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B2			(BIT12 + BIT13 + BIT14)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB91B_11_10			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B2			(BIT8 + BIT9)	//0/x/x/x IREF for Test
    #define D0F3_VREF_TST_EN_B1			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B1			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB91B_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B1			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_B4_B3_CHN_B		0xB92	//Bdddrdq Control Register B4/B3 Channel B
    #define D0F3_VREF_TST_EN_B4			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B4			(BIT12 + BIT13 + BIT14)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB93B_11_10			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B4			(BIT8 + BIT9)	//0/x/x/x IREF for Test
    #define D0F3_VREF_TST_EN_B3			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B3			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB93B_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B3			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_B6_B5_CHN_B		0xB94	//Bdddrdq Control Register B6/B5 Channel B
    #define D0F3_VREF_TST_EN_B6			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B6			(BIT12 + BIT13 + BIT14)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB95B_11_10			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B6			(BIT8 + BIT9)	//0/x/x/x IREF for Test
    #define D0F3_VREF_TST_EN_B5			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B5			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB95B_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B5			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_BDDDRDQ_CTL_REG_B8_B7_CHN_B		0xB96	//Bdddrdq Control Register B8/B7 Channel B
    #define D0F3_VREF_TST_EN_B8			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B8			(BIT12 + BIT13 + BIT14)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB97B_11_10			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B8			(BIT8 + BIT9)	//0/x/x/x IREF for Test
    #define D0F3_VREF_TST_EN_B7			BIT7	//0/x/x/x Test Mode Enable
    #define D0F3_VREF_TST_2_0_B7			(BIT4 + BIT5 + BIT6)	//0/x/x/x VREF for Test
    #define D0F3_D0F3_RXB97B_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D0F3_IREF_TST_1_0_B7			(BIT0 + BIT1)	//0/x/x/x IREF for Test
#define D0F3_MCLKOA_PHASE_CTL_CHN_A		0xBB0	//MCLKOA Phase Control Channel A
    #define D0F3_D0F3_RXBB1B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_MCLKOA_5_0_1			0x3F00	//0/x/x/x PH_MCLKOA[5:0]1  DIMM1 clock PI Phase Control 
    #define D0F3_D0F3_RXBB1B7			BIT7	//0/x/x/x Reserved
    #define D0F3_PIEN_MCLKOA			BIT6	//1b/x/x/x MCLKOA Phase Control Enable 
    #define D0F3_RPH_MCLKOA_5_0_0			0x3F	//0/x/x/x PH_MCLKOA[5:0]0  DIMM0 clock PI Phase Control 
#define D0F3_MCLKOA_PHASE_CTL_CHN_A_Z1		0xBB2	//MCLKOA Phase Control Channel A
    #define D0F3_D0F3_RXBB3B_15_0			0xFFFF	//0/x/x/x Reserved
#define D0F3_MCSA_PHASE_CTL_CHN_A		0xBB4	//MCSA Phase Control Channel A
    #define D0F3_D0F3_RXBB5B15			BIT15	//0/x/x/x Reserved
    #define D0F3_PIEN_MCSA			BIT14	//1b/x/x/x MCSA Phase Control Enable
    #define D0F3_RPH_MCSA_5_0			0x3F00	//0/x/x/x PH_MCSA[5:0]  chipselec  PI Phase Control 
    #define D0F3_D0F3_RXBB5B7			BIT7	//0/x/x/x Reserved
    #define D0F3_PIEN_SCMDA			BIT6	//1b/x/x/x SCMDA Phase Control Enable
    #define D0F3_RPH_SCMDA_5_0			0x3F	//0/x/x/x PH_SCMDA[5:0]  cmd  PI Phase Control 
#define D0F3_MCKEA_PHASE_CTL_CHN_A		0xBB6	//MCKEA Phase Control Channel A
    #define D0F3_D0F3_RXBB7B_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_PIEN_MCKEA			BIT6	//1b/x/x/x MCKEA Phase Control Enable 
    #define D0F3_RPH_MCKEA_5_0			0x3F	//0/x/x/x PH_MCKEA[5:0]  Input Enable PI Phase Control 
#define D0F3_MCLKOB_PHASE_CTL_CHN_B		0xBB8	//MCLKOB Phase Control Channel B
    #define D0F3_D0F3_RXBB9B_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define D0F3_RPH_MCLKOB_5_0_1			0x3F00	//0/x/x/x PH_MCLKOB[5:0]1  DIMM1 clock PI Phase Control 
    #define D0F3_D0F3_RXBB9B7			BIT7	//0/x/x/x Reserved
    #define D0F3_PIEN_MCLKOB			BIT6	//1b/x/x/x MCLKOB Phase Control Enable 
    #define D0F3_RPH_MCLKOB_5_0_0			0x3F	//0/x/x/x PH_MCLKOB[5:0]0  DIMM0 clock  PI Phase Control 
#define D0F3_MCLKOB_PHASE_CTL_CHN_B_Z1		0xBBA	//MCLKOB Phase Control Channel B
    #define D0F3_D0F3_RXBBBB_15_0			0xFFFF	//0/x/x/x Reserved
#define D0F3_MCSB_PHASE_CTL_CHN_B		0xBBC	//MCSB Phase Control Channel B
    #define D0F3_D0F3_RXBBDB15			BIT15	//0/x/x/x Reserved
    #define D0F3_PIEN_MCSB			BIT14	//1b/x/x/x MCSB Phase Control Enable 
    #define D0F3_RPH_MCSB_5_0			0x3F00	//0/x/x/x PH_MCSB[5:0]  chipselect PI Phase Control 
    #define D0F3_D0F3_RXBBDB7			BIT7	//0/x/x/x Reserved
    #define D0F3_PIEN_SCMDB			BIT6	//1b/x/x/x SCMDB Phase Control Enable 
    #define D0F3_RPH_SCMDB_5_0			0x3F	//0/x/x/x PH_SCMDB[5:0]  cmd PI Phase Control 
#define D0F3_MCKEB_PHASE_CTL_CHN_B		0xBBE	//MCKEB Phase Control Channel B
    #define D0F3_D0F3_RXBBFB_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_PIEN_MCKEB			BIT6	//1b/x/x/x MCKEB Phase Control Enable 
    #define D0F3_RPH_MCKEB_5_0			0x3F	//0/x/x/x PH_MCKEB[5:0]  Input Enable PI Phase Control 
#define D0F3_DIMM_CLK_DUTY_CTL_FOR_CHN_A		0xBC0	//DIMM Clock Duty Control for Channel A
    #define D0F3_RDCLKO3S_1_0_F			(BIT14 + BIT15)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO3S_1_0_R			(BIT12 + BIT13)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO2S_1_0_F			(BIT10 + BIT11)	//0/x/x/x DIMM Clock Duty Control, increasing S1F/S0F or Decreasing S1R/S0R To Output Different Clock Duty
    #define D0F3_RDCLKO2S_1_0_R			(BIT8 + BIT9)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO1S_1_0_F			(BIT6 + BIT7)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO1S_1_0_R			(BIT4 + BIT5)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO0S_1_0_F			(BIT2 + BIT3)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO0S_1_0_R			(BIT0 + BIT1)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
#define D0F3_DIMM_CLK_DUTY_CTL_FOR_CHN_B		0xBC2	//DIMM Clock Duty Control for Channel B
    #define D0F3_RDCLKO7S_1_0_F			(BIT14 + BIT15)	//0/x/x/x DIMM Clock Duty Control, increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO7S_1_0_R			(BIT12 + BIT13)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO6S_1_0_F			(BIT10 + BIT11)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO6S_1_0_R			(BIT8 + BIT9)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO5S_1_0_F			(BIT6 + BIT7)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO5S_1_0_R			(BIT4 + BIT5)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO4S_1_0_F			(BIT2 + BIT3)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
    #define D0F3_RDCLKO4S_1_0_R			(BIT0 + BIT1)	//0/x/x/x DIMM Clock Duty Control, Increasing S1F/S0F or Decreasing S1R/S0R to Output Different Clock Duty
#define D0F3_DLL_FUN_FOR_CHN_A		0xBC4	//DLL Function for Channel A
    #define D0F3_D0F3_RXBC5B_15_0			0xFFFF	//0/x/x/x Reserved
#define D0F3_BDDDRDQ_S24_TEST_ENABLE_FUN		0xBC6	//bdddrdq_S24 Test Enable Function
    #define D0F3_DDR_B_7_0_PAD_INLP			0xFF00	//0/x/x/x Test Mode Enable
    #define D0F3_DDR_A_7_0_PAD_INLP			0xFF	//0/x/x/x Test Mode Enable
#define D0F3_BDDDRDQ_S24_TEST_ENABLE_FUN_Z1		0xBC8	//bdddrdq_S24 Test Enable Function
    #define D0F3_DDR_B8_PAD_INLP			BIT15	//0/x/x/x Test Mode Enable
    #define D0F3_DDR_A8_PAD_INLP			BIT14	//0/x/x/x Test Mode Enable
    #define D0F3_D0F3_RXBC8B_13_0			0x3FFF	//0/x/x/x Reserved
#define D0F3_TMON_DDR_ANALOG_IP_OUTPUT		0xBCA	//TMON_DDR Analog IP Output
    #define D0F3_TMON_RSV00			0xFE	//0/x/x/x Reserved
    #define D0F3_TM_DATAOUT			BIT0	//HwInit/x/x/x Sigma Delta Converter Digital Output
#define D0F3_TMON_DDR_ANALOG_IP_CTL_REG_PART_1		0xBCB	//TMON_DDR Analog IP control Register Part 1
    #define D0F3_TMON_RSV01			BIT7	//0/x/x/x Reserved
    #define D0F3_TM_GV_2_0			(BIT4 + BIT5 + BIT6)	//011b/x/x/x 2 Bit Input Thermometer Encoder to Match ¡°tmsense¡± Current Select Set
    #define D0F3_TM_MODE			BIT3	//0/x/x/x Together with TM_SEL<2:0> for ADC Monitor Voltage Select
    #define D0F3_TM_CE			BIT2	//1b/x/x/x High Active, Enable Internal op for Optimize ¡°its¡± Current Sense Accuracy
    #define D0F3_TM_DIFFEN			BIT1	//0/x/x/x When=0, Disable Currnet Source Diff Module, Current Source Only from Internal Input 36uA
    #define D0F3_TM_MODE_SEL			BIT0	//0/x/x/x TM_MODE_SEL = 0, tmon_ddr work in ¡®voltage mode¡¯
#define D0F3_RESERVED_CTL_PIN_FOR_TMOR_DDR		0xBCC	//Reserved Control Pin for TMOR_DDR
    #define D0F3_TM_RSV_31_0			0xFFFFFFFF	//0/x/x/x Reserved Control Pin for TMON_DDR
#define D0F3_TMON_DDR_CTL_REG_PART_3		0xBD0	//TMON_DDR Control Register Part 3
    #define D0F3_TM_SELX_5_0			0xFC000000	//0/x/x/x Mux Select Signal from TM_XV<8:0> vVSUS Voltage or 3 tmsenses ¡®Voltage Mode¡¯ and ¡®Current Mode¡¯ Sensor vbe Voltage
    #define D0F3_TM_CLKOUT_EDGE_SEL			BIT25	//0/x/x/x tm_clkout Edge Select
    #define D0F3_TM_LDO_PU			BIT24	//1b/x/x/x Internal LDO Control Pin
    #define D0F3_TM_LDO_BYPASS			BIT23	//0/x/x/x Refer the Description of TM_LDO_PU
    #define D0F3_TM_SS_DMODE			BIT22	//0/x/x/x When High Active, Thermal Diode Voltage Fast Stable to 573mv (pnp junction voltage in 1.05v/tt/90c)
    #define D0F3_TMON_RSV0A			BIT21	//0/x/x/x Reserved
    #define D0F3_TM_TEST_MODE_20_0			0x1FFFFF	//0/x/x/x Test Control Pin
#define D0F3_TMON_DDR_ANALOG_IP_CTL_REG_PART_2		0xBD4	//TMON_DDR Analog IP Control Register Part 2
    #define D0F3_TM_ADC_MODE			BIT15	//0/x/x/x Internal Sigma Delta ADC Test Enable Control
    #define D0F3_TM_GI_6_0			0x7F00	//4Ch/x/x/x Sigma Delta Convertor Internal Integrator Cap Value Select
    #define D0F3_TM_ADC_FB_DELAY			BIT7	//0/x/x/x Sigma Delta ADC Option, Select Feedback 1-bit DA Delay
    #define D0F3_TM_LPF_SEL			BIT6	//0/x/x/x Select Thermal Voltage Signal through Low Pass Filter Or Not
    #define D0F3_TM_NANALOGRST			BIT5	//1b/x/x/x Internal Bandgap Module Reset PinReset bandgap output to 'Vbe'
    #define D0F3_TM_BG_PDB			BIT4	//1b/x/x/x Bandgap Enable
    #define D0F3_TMON_RSV02			BIT3	//0/x/x/x Reserved
    #define D0F3_TM_CLKSEL_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x Select Internal Osc Clock Signal for Sigma Delta Convertor0
#define D0F3_RESERVED_CTL_PIN_FOR_TM_SENSE		0xBD6	//Reserved Control Pin for TM Sense
    #define D0F3_TM_SS_RSV_15_0			0xFFFF	//0/x/x/x Reserved Control Pin for TM Sense
#define D0F3_RESERVED_CTL_PIN_FOR_TM_SENSE_Z1		0xBD8	//Reserved Control Pin for TM Sense
    #define D0F3_RTM_CLKOUT_CNT_19_16			0xF000	//0/x/x/x TM_CLKOUT Counter
    #define D0F3_RTM_T_THD_19_16			0xF00	//0/x/x/x Temperature Threshold
    #define D0F3_TMON_RSV0E			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_TM_TRIM_5_0			0x3F	//20h/x/x/x One-point Calibration for Local Sensor
#define D0F3_TMON_DDR_TM_CLKOUT_CNTER_TIMES		0xBDA	//TMON_DDR TM_CLKOUT Counter Times
    #define D0F3_RTM_CLKOUT_CNT_15_0			0xFFFF	//7D0h/x/x/x TM_CLKOUT counter
#define D0F3_TMON_DDR_TEMPERATURE_THRESHOLD		0xBDC	//TMON_DDR Temperature Threshold
    #define D0F3_RTM_T_THD_15_0			0xFFFF	//64h/x/x/x Temperature Threshold
#define D0F3_TMON_DDR_CTL_REG_PART_3_Z1		0xBDE	//TMON_DDR Control Register Part 3
    #define D0F3_RTM_RD_D2_SEL_7_0			0xFF00	//FFh/x/x/x Read D2_x
    #define D0F3_RTM_STEP3_ONCE			BIT7	//0/x/x/x Do Step 3 Once after Power onWhen set to 1, controller will only run step 3 after power on.
    #define D0F3_RTM_RSV0F			0x78	//0/x/x/x Reserved
    #define D0F3_RTM_DYNPM			BIT2	//0/0/1/1 DDRIO tmon Controller Dynamic Clock Control
    #define D0F3_RTM_USE_D3_CAL_Q			BIT1	//0/x/x/x Use D3 to Calculate Q Denominator
    #define D0F3_RTM_DDR_EN			BIT0	//0/x/x/x TM_DDR Enable
#define D0F3_TMON_DDR_S24_C0_VALUE		0xBE0	//TMON_DDR_S24 C0 Value
    #define D0F3_TMON_RSV_C0_31_28			0xF0000000	//0/x/x/x Reserved
    #define D0F3_RTM_C0_27_0			0xFFFFFFF	//FFFEB0Fh/x/x/x The C0 Value Uses in Step 7 in TMON_DDR_S24
#define D0F3_TMON_DDR_S24_C1_VALUE		0xBE4	//TMON_DDR_S24 C1 Value
    #define D0F3_TMON_RSV_C1_31_28			0xF0000000	//0/x/x/x Reserved
    #define D0F3_RTM_C1_27_0			0xFFFFFFF	//93B6h/x/x/x The C1 Value Uses in step 7 in TMON_DDR_S24
#define D0F3_TMON_DDR_S24_C2_VALUE		0xBE8	//TMON_DDR_S24 C2 Value
    #define D0F3_TMON_RSV_C2_31_28			0xF0000000	//0/x/x/x Reserved
    #define D0F3_RTM_C2_27_0			0xFFFFFFF	//FFED063h/x/x/x The C2 Value Uses in Step 7 in TMON_DDR_S24
#define D0F3_TMON_DDR_S24_C3_VALUE		0xBEC	//TMON_DDR_S24 C3 Value
    #define D0F3_TMON_RSV_C3_31_28			0xF0000000	//0/x/x/x Reserved
    #define D0F3_RTM_C3_27_0			0xFFFFFFF	//18D92h/x/x/x The C3 Value Uses in Step 7 in TMON_DDR_S24
#define D0F3_TMON_DDR_S24_C4_VALUE		0xBF0	//TMON_DDR_S24 C4 Value
    #define D0F3_TMON_RSV_C4_31_28			0xF0000000	//0/x/x/x Reserved
    #define D0F3_RTM_C4_27_0			0xFFFFFFF	//FFF1B9Fh/x/x/x The C4 Value Uses in Step 7 in TMON_DDR_S24
#define D0F3_RESULT_DATA_AT_STEP_2		0xC08	//Result Data at Step 2
    #define D0F3_TMON_RSV_D0_31_20			0xFFF00000	//0/x/x/x Reserved
    #define D0F3_RTM_D0_19_0			0xFFFFF	//HwInit/x/x/x The Result Data at Step 2
#define D0F3_RESULT_DATA_AT_STEP_3		0xC0C	//Result Data at Step 3
    #define D0F3_TMON_RSV_D1_31_20			0xFFF00000	//0/x/x/x Reserved
    #define D0F3_RTM_D1_19_0			0xFFFFF	//HwInit/x/x/x The Result Data at Step 3
#define D0F3_RESULT_DATA_AT_STEP_4		0xC10	//Result Data at Step 4
    #define D0F3_TMON_RSV_D2_31_20			0xFFF00000	//0/x/x/x Reserved
    #define D0F3_RTM_D2_19_0			0xFFFFF	//HwInit/x/x/x The Result Data at Step 4
#define D0F3_RESULT_DATA_AT_STEP_5		0xC14	//Result Data at Step 5
    #define D0F3_TMON_RSV_D3_31_20			0xFFF00000	//0/x/x/x Reserved
    #define D0F3_RTM_D3_19_0			0xFFFFF	//HwInit/x/x/x The Result Data at Step 5
#define D0F3_RESULT_DATA_AT_STEP_6		0xC18	//Result Data at Step 6
    #define D0F3_TMON_RSV_QV_31_16			0xFFFF0000	//0/x/x/x Reserved
    #define D0F3_RTM_Q_V_15_0			0xFFFF	//HwInit/x/x/x The Result Data at Step 6
#define D0F3_RESULT_DATA_AT_STEP_7		0xC1C	//Result Data at Step 7
    #define D0F3_TMON_RSV_TV_S7_31_20			0xFFF00000	//0/x/x/x Reserved
    #define D0F3_RTM_T_V_19_0			0xFFFFF	//HwInit/x/x/x The Result Data at Step 7
#define D0F3_PAD_DRIVING_TEST		0xC20	//Pad Driving Test
    #define D0F3_D0F3_RXC0F_7_1			0xFE000000	//0/x/x/x Reserved
    #define D0F3_RDLL_LOCKOK_DDRPHYA_8_0			0x1FF0000	//HwInit/x/x/x DLL_LOCKOK Value of DDRPHYA0
    #define D0F3_RDLL_LOCKOK_VCDL_CA			BIT15	//HwInit/x/x/x DLL_LOCKOK Value of VCDL_CA
    #define D0F3_RDLL_LOCKOK_VCDL_CA_CHB			BIT14	//HwInit/x/x/x DLL_LOCKOK Value of VCDL_CA for channel B
    #define D0F3_D0F3_RXC0D_5_1			0x3E00	//0/x/x/X Reserved
    #define D0F3_RDCLKO_SYNC_DDRPHYA_8_0			0x1FF	//HwInit/x/x/x DCLKO_SYNC Value of DDRPHYA0
#define D0F3_PAD_DRIVING_TEST_Z1		0xC24	//Pad Driving Test
    #define D0F3_D0F3_RXC13_7_1			0xFE000000	//0/x/x/x Reserved
    #define D0F3_RDLL_LOCKOK_DDRPHYB_8_0			0x1FF0000	//HwInit/x/x/x DLL_LOCKOK Value of DDRPHYA0
    #define D0F3_D0F3_RXC11_7_1			0xFE00	//0/x/x/x Reserved
    #define D0F3_RDCLKO_SYNC_DDRPHYB_8_0			0x1FF	//HwInit/x/x/x DCLKO_SYNC Value of DDRPHYA0
#define D0F3_PLLIN_COMP_ESD		0xC2C	//PLLIN_COMP_ESD
    #define D0F3_RPLLIN_PLLOK			BIT15	//HwInit/x/x/x PLLIN_PLLOK Value of PLLIN_COMP_ESD
    #define D0F3_RPLLINDDR_PLLOK			BIT14	//HwInit/x/x/x PLLINDDR_PLLOK Value of PLLIN_COMP_ESD
    #define D0F3_RNSO3			BIT13	//HwInit/x/x/x NSO[3:0] Value of PLLIN_COMP_ESD
    #define D0F3_RNSO2			BIT12	//HwInit/x/x/x NSO[3:0] Value of PLLIN_COMP_ESD
    #define D0F3_RNSO1			BIT11	//HwInit/x/x/x NSO[3:0] Value of PLLIN_COMP_ESD
    #define D0F3_RNSO0			BIT10	//HwInit/x/x/x NSO[3:0] Value of PLLIN_COMP_ESD
    #define D0F3_RPSO3			BIT9	//HwInit/x/x/x PSO[3:0] Value of PLLIN_COMP_ESD
    #define D0F3_RPSO2			BIT8	//HwInit/x/x/x PSO[3:0] Value of PLLIN_COMP_ESD
    #define D0F3_RPSO1			BIT7	//HwInit/x/x/x PSO[3:0] Value of PLLIN_COMP_ESD
    #define D0F3_RPSO0			BIT6	//HwInit/x/x/x PSO[3:0] Value of PLLIN_COMP_ESD
    #define D0F3_RODTPOK			BIT5	//HwInit/x/x/x ODTPOK Value of PLLIN_COMP_ESD
    #define D0F3_RODTNOK			BIT4	//HwInit/x/x/x ODTNOK Value of PLLIN_COMP_ESD
    #define D0F3_RAUTO			BIT3	//0/x/x/x Auto Compensation Function Enable Signal
    #define D0F3_RFRZ			BIT2	//0/x/x/x Freeze Output Setting
    #define D0F3_REG_RMSETDONE			BIT1	//0/x/x/x CHA DIO BUS Counter Trigger
    #define D0F3_REG_RMSETDONE_CHB			BIT0	//0/x/x/x CHB DIO BUS Counter Trigger
#define D0F3_CMD_PAD_CTL_CHN_A		0xC2E	//Command Pad Control Channel A
    #define D0F3_D0F3_RXC1BB15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_CSA_P_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x MCS
    #define D0F3_D0F3_RXC1BB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_CSA_N_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x MCS
    #define D0F3_D0F3_RXC1BB7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_CLKA_P_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x MCLK
    #define D0F3_D0F3_RXC1BB3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_CLKA_N_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x MCLK
#define D0F3_CMD_PAD_CTL_CHN_A_Z1		0xC30	//Command Pad Control Channel A
    #define D0F3_D0F3_RXC1DB_15_11			0xF800	//0/x/x/x Reserved
    #define D0F3_RREFSETA_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x Adjust RX Duty
    #define D0F3_D0F3_RXC1DB7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_MAA_P_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x MA / CMD / ODT etc
    #define D0F3_D0F3_RXC1DB3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_MAA_N_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x MA / CMD / ODT etc
#define D0F3_CMD_PAD_CTL_CHN_A_Z2		0xC32	//Command Pad Control Channel A
    #define D0F3_RMAADVP_3_0			0xF000	//1000b/x/x/x Four Bits Driving Setting for PMOS Pulling up for ACT/MBG/MBA/MAA Pad
    #define D0F3_RMAADVN_3_0			0xF00	//1000b/x/x/x Four Bits Driving Setting for NMOS Pulling down for ACT/MBG/MBA/MAA Pad
    #define D0F3_RDCLKDVPA_3_0			0xF0	//1000b/x/x/x Four Bits Driving Setting for PMOS Pulling up for MCLK Pad
    #define D0F3_RDCLKDVNA_3_0			0xF	//1000b/x/x/x Four Bits Driving Setting for NMOS Pulling down for MCLK Pad
#define D0F3_CMD_PAD_CTL_CHN_A_CHN_B		0xC34	//Command Pad Control Channel A/Channel B
    #define D0F3_RCSDVPB_3_0			0xF000	//0/x/x/x Four Bits Driving Setting for PMOS Pulling up for ACT/MBG/MBA/MAA Pad
    #define D0F3_RCSDVNB_3_0			0xF00	//0/x/x/x Four Bits Driving Setting for NMOS Pulling down for ACT/MBG/MBA/MAA Pad
    #define D0F3_RCSDVPA_3_0			0xF0	//0/x/x/x Four Bits Driving Setting for PMOS Pulling up for ACT/MBG/MBA/MAA Pad
    #define D0F3_RCSDVNA_3_0			0xF	//0/x/x/x Four Bits Driving Setting for NMOS Pulling down for ACT/MBG/MBA/MAA Pad
#define D0F3_CMD_PAD_CTL_CHN_B		0xC36	//Command Pad Control Channel B
    #define D0F3_D0F3_RXC23B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_CSB_P_2_0			(BIT12 + BIT13 + BIT14)	//0/x/x/x MCS 
    #define D0F3_D0F3_RXC23B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_CSB_N_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x MCS
    #define D0F3_D0F3_RXC23B7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_CLKB_P_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x MCLK
    #define D0F3_D0F3_RXC23B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_CLKB_N_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x MCLK
#define D0F3_CMD_PAD_CTL_CHN_B_Z1		0xC38	//Command Pad Control Channel B
    #define D0F3_D0F3_RXC25B_15_11			0xF800	//0/x/x/x Reserved
    #define D0F3_RREFSETB_2_0			(BIT8 + BIT9 + BIT10)	//0/x/x/x Adjust RX Duty
    #define D0F3_D0F3_RXC25B7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_MAB_P_2_0			(BIT4 + BIT5 + BIT6)	//0/x/x/x MA / CMD / ODT etc
    #define D0F3_D0F3_RXC25B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDRVMODE_MAB_N_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x MA / CMD / ODT etc
#define D0F3_CMD_PAD_CTL_CHN_B_Z2		0xC3A	//Command Pad Control Channel B
    #define D0F3_RMABDVP_3_0			0xF000	//1000b/x/x/x Four Bits Driving Setting for PMOS Pulling up for ACTB/MBGB/MBAB/MAB Pad
    #define D0F3_RMABDVN_3_0			0xF00	//1000b/x/x/x Four Bits Driving Setting for NMOS Pulling down for ACTB/MBGB/MBAB/MAB Pad
    #define D0F3_RDCLKDVPB_3_0			0xF0	//1000b/x/x/x Four BITS DRIVING SETTing for PMOS PUlling up for MCLKB PAD
    #define D0F3_RDCLKDVNB_3_0			0xF	//1000b/x/x/x Four Bits Driving Setting for NMOS Pulling down for MCLKB Pad
#define D0F3_CMD_PAD_CTL_CHN_A_Z3		0xC3C	//Command Pad Control Channel A
    #define D0F3_RDCLKA1SR_1_0			(BIT6 + BIT7)	//0/x/x/x Two bits Output Delay Programmable Control Signals for rising Timing for pbdclk_S24 
    #define D0F3_RDCLKA1SF_1_0			(BIT4 + BIT5)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Falling Timing for pbdclk_S24
    #define D0F3_RDCLKA0SR_1_0			(BIT2 + BIT3)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Rising Timing for pbdclk_S24
    #define D0F3_RDCLKA0SF_1_0			(BIT0 + BIT1)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Falling Timing for pbdclk_S24
#define D0F3_CMD_PAD_CTL_CHN_A_Z4		0xC3D	//Command Pad Control Channel A
    #define D0F3_RDCLKA3SR_1_0			(BIT6 + BIT7)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Rising Timing for pbdclk_S24
    #define D0F3_RDCLKA3SF_1_0			(BIT4 + BIT5)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Falling Timing for pbdclk_S24
    #define D0F3_RDCLKA2SR_1_0			(BIT2 + BIT3)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Rising Timing for pbdclk_S24
    #define D0F3_RDCLKA2SF_1_0			(BIT0 + BIT1)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Falling Timing for pbdclk_S24
#define D0F3_CMD_PAD_CTL_CHN_B_Z3		0xC3E	//Command Pad Control Channel B
    #define D0F3_RDCLKB1SR_1_0			(BIT6 + BIT7)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Rising Timing for pbdclk_S24
    #define D0F3_RDCLKB1SF_1_0			(BIT4 + BIT5)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Falling Timing for pbdclk_S24
    #define D0F3_RDCLKB0SR_1_0			(BIT2 + BIT3)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Rising Timing for pbdclk_S24
    #define D0F3_RDCLKB0SF_1_0			(BIT0 + BIT1)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Falling Timing for pbdclk_S24
#define D0F3_CMD_PAD_CTL_CHN_B_Z4		0xC3F	//Command Pad Control Channel B
    #define D0F3_RDCLKB3SR_1_0			(BIT6 + BIT7)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Rising Timing for pbdclk_S24
    #define D0F3_RDCLKB3SF_1_0			(BIT4 + BIT5)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Falling Timing for pbdclk_S24
    #define D0F3_RDCLKB2SR_1_0			(BIT2 + BIT3)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Rising Timing for pbdclk_S24
    #define D0F3_RDCLKB2SF_1_0			(BIT0 + BIT1)	//0/x/x/x Two Bits Output Delay Programmable Control Signals for Falling Timing for pbdclk_S24
#define D0F3_DCLKD_DQSI_AUTO_SEL		0xC40	//DCLKD& DQSI Auto Select
    #define D0F3_D0F3_RXC2DB_7_0			0xFF00	//0/0/x/x Reserved
    #define D0F3_RDQSADV_AUTO			BIT7	//0/0/x/x CHA DQS Driving Auto Mode
    #define D0F3_RDQSBDV_AUTO			BIT6	//0/0/x/x CHB DQS Driving Auto Mode
    #define D0F3_RMAADV_AUTO			BIT5	//0/0/x/x CHA MA Pad Driving Auto Mode 
    #define D0F3_RMABDV_AUTO			BIT4	//0/0/x/x CHB MA Driving Auto Mode 
    #define D0F3_RDCLKADV_AUTO			BIT3	//0/0/x/x DIMM CLK Pad Driving Auto Select for CHA
    #define D0F3_RDCLKBDV_AUTO			BIT2	//0/0/x/x DIMM CLK Pad Driving Auto Select for CHB
    #define D0F3_RDQADV_AUTO			BIT1	//0/0/x/x DQ/DQS Pad Driving Auto Select for CHA
    #define D0F3_RDQBDV_AUTO			BIT0	//0/0/x/x DQ/DQS Pad Driving Auto Select for CHB
#define D0F3_VCDL_FUN_FOR_CHN_A		0xC42	//VCDL Function for Channel A
    #define D0F3_D0F3_RXC2FB15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDLL_CKRANGE_2_0			(BIT12 + BIT13 + BIT14)	//111b/x/x/x Select Corresponding Setting for Different DCLK Frequency
    #define D0F3_D0F3_RXC2FB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDLL_WEAKLOCK			BIT10	//0/x/x/x Weak Lock Control for Lower Power
    #define D0F3_RDLL_BWSEL_1_0			(BIT8 + BIT9)	//01b/x/x/x Tuning Charge Current Value for Charge Pump in ADLL to Tuning Bandwidth
    #define D0F3_D0F3_RXC2FB7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDLL_REFDLY_2_0			(BIT4 + BIT5 + BIT6)	//011b/x/x/x 3 Bit Delay Setting to Correct Delay Line in ADLL Loop
    #define D0F3_RVCDL_BYPASS			BIT3	//0/x/x/x Bypass VCDL for Function Test on ATE
    #define D0F3_RDLL_V2VSEL_2_0			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Tuning Voltage Range of BIASP/BIASN for Analog Delay Line
#define D0F3_VCDL_FUN_FOR_CHN_B		0xC44	//VCDL Function for Channel B
    #define D0F3_D0F3_RXC31B15			BIT15	//0/x/x/x Reserved
    #define D0F3_RDLL_CKRANGE_2_0_CHB			(BIT12 + BIT13 + BIT14)	//111b/x/x/x Select Corresponding Setting for Different DCLK Frequency
    #define D0F3_RDLL_WEAKLOCK_CHB			BIT11	//0/x/x/x Weak Lock Control for Lower Power
    #define D0F3_D0F3_RXC31B10			BIT10	//0/x/x/x Reserved
    #define D0F3_RDLL_BWSEL_1_0_CHB			(BIT8 + BIT9)	//01b/x/x/x Tuning Charge Current Value for Charge Pump in ADLL to Tuning Bandwidth
    #define D0F3_RVCDL_BYPASS_CHB			BIT7	//0/x/x/x Bypass VCDL for Function Test on ATE
    #define D0F3_RDLL_REFDLY_2_0_CHB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x 3 Bit Delay Setting to Correct Delay Line in ADLL Loop
    #define D0F3_D0F3_RXC31B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDLL_V2VSEL_2_0_CHB			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Tuning Voltage Range of BIASP/BIASN for Analog Delay Line
#define D0F3_VCDL_FUN		0xC46	//VCDL Function
    #define D0F3_D0F3_RXC47B_7_0			0xFF00	//0/x/x/x Reserved
    #define D0F3_D0F3_RXC46B7			BIT7	//0/x/x/x Reserved
    #define D0F3_RDLL_FBDLY_2_0			(BIT4 + BIT5 + BIT6)	//011b/x/x/x 3 Bit Delay Setting To Correct Delay Line in ADLL Loop
    #define D0F3_D0F3_RXC46B3			BIT3	//0/x/x/x Reserved
    #define D0F3_RDLL_FBDLY_2_0_CHB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x 3 Bit Delay Setting to Correct Delay Line in ADLL Loop
#define D0F3_DIMM_CMD_RELATED_CLK_SEL		0xC48	//DIMM CMD Related Clock Select
    #define D0F3_D0F3_RXC49B_15_12			0xF000	//0/0/x/x Reserved
    #define D0F3_RLEADINGOE4T			BIT11	//0b/0/x/x Control LEADINGOE Early than HEAD2
    #define D0F3_RLEADINGOE3T			BIT10	//0b/0/x/x Control LEADINGOE Early than HEAD2
    #define D0F3_RDCLKCKEB_SEL			BIT9	//0/0/x/x Channel B CKE Clock Select
    #define D0F3_RDCLKCSB_SEL			BIT8	//0/0/x/x Channel B CS Clock Select
    #define D0F3_RDCLKSCMDB_SEL			BIT7	//0/0/x/x Channel B CMD Clock Select
    #define D0F3_RDCLKOBD2_SEL			BIT6	//0/0/x/x Channel B DIMM1 Clock Select
    #define D0F3_RDCLKOBD0_SEL			BIT5	//0/0/x/x Channel B DIMM0 Clock Select
    #define D0F3_RDCLKCKEA_SEL			BIT4	//0/0/x/x Channel B CKE Clock Select
    #define D0F3_RDCLKCSA_SEL			BIT3	//0/0/x/x Channel A CS Clock Select
    #define D0F3_RDCLKSCMDA_SEL			BIT2	//0/0/x/x Channel A CMD Clock Select
    #define D0F3_RDCLKOAD2_SEL			BIT1	//0/0/x/x Channel A DIMM1 Clock Select
    #define D0F3_RDCLKOAD0_SEL			BIT0	//0/0/x/x Channel A DIMM0 Clock Select
#define D0F3_AUTO_COMP_RELATED_CTL		0xC4A	//Auto Comp Related Control
    #define D0F3_RCOMP_CNT_15_0			0xFFFF	//03EBh/3EBh/x/x Define the Number of Clocks between to Auto Comp Value
#define D0F3_AUTO_COMP_RELATED_CTL_Z1		0xC4C	//Auto Comp Related Control
    #define D0F3_RCOMP_TO_CNT_7_0			0xFF00	//32h/x/x/x DDRCOMP Setting Max Counter
    #define D0F3_RFRZ_IDLE_CTRL			BIT7	//0/0/x/x Idle Freeze Control
    #define D0F3_RODT_FLAG			BIT6	//0/0/x/x If odtok Can¡¯t Enable, Should Set This Register to Enable Counter
    #define D0F3_RTHIRD_EN			BIT5	//0/0/x/x DDRCOMP Enable for Third Method
    #define D0F3_RCOMP_TIME_EN			BIT4	//0/0/x/x Enable for a Certain Time to Get a Value
    #define D0F3_RREF_DIFF_3_0			0xF	//Fh/Fh/x/x This Register Used for Refresh Signal to Expand in Different Frequency
#define D0F3_AUTO_COMP_RELATED_CTL_Z2		0xC4E	//Auto Comp Related Control
    #define D0F3_RCOMP_THRE_40_7_0			0xFF00	//14h/14h/x/x Percent of Total Counter < 1 Default 40%
    #define D0F3_RCOMP_THRE_7_0			0xFF	//23h/23h/x/x Percent of Total Counter < 1 Default 70%
#define D0F3_AUTO_COMP_RELATED_CTL_Z3		0xC50	//Auto Comp Related Control
    #define D0F3_RODT_WAIT_CNT_15_0			0xFFFF	//19C8h/x/x/x If odtok Cannot Enable, Should Want 100us After Reset = 1
#define D0F3_DDR_BYTECLK_BUF_S24_CKOUT1_CHN_A		0xC52	//DDR_BYTECLK_BUF_S24 CKOUT1 Channel A
    #define D0F3_RTUNE_3_0_CKOUT1_A			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC52B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT1_A			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC52B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT1_A			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT1_A			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT1_A			BIT3	//0/x/x/x Power Gating Option for CKOUT1; Reserved
    #define D0F3_RBIASEN_CKOUT1_A			BIT2	//0/x/x/x Bias Current Enable for CKOUT1
    #define D0F3_RCKNEN_CKOUT1_A			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT1
    #define D0F3_RCKPEN_CKOUT1_A			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT1
#define D0F3_DDR_BYTECLK_BUF2_S24_CKOUT1_CHN_A_FOR_BYTE0_1_2_3_8		0xC54	//DDR_BYTECLK_BUF2_S24 CKOUT1 Channel A for Byte0/1/2/3/8
    #define D0F3_RTUNE_3_0_CKOUT1_BUF2_A_L			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC54B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT1_BUF2_A_L			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC54B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT1_BUF2_A_L			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT1_BUF2_A_L			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT1_BUF2_A_L			BIT3	//0/x/x/x Power Gating Option for CKOUT1; Reserved
    #define D0F3_RBIASEN_CKOUT1_BUF2_A_L			BIT2	//0/x/x/x Bias Current Enable for CKOUT1
    #define D0F3_RCKNEN_CKOUT1_BUF2_A_L			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT1
    #define D0F3_RCKPEN_CKOUT1_BUF2_A_L			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT1
#define D0F3_DDR_BYTECLK_BUF2_S24_CKOUT1_CHN_A_FOR_BYTE4_5_6_7		0xC56	//DDR_BYTECLK_BUF2_S24 CKOUT1 Channel A for Byte4/5/6/7
    #define D0F3_RTUNE_3_0_CKOUT1_BUF2_A_H			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC56B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT1_BUF2_A_H			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC56B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT1_BUF2_A_H			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT1_BUF2_A_H			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT1_BUF2_A_H			BIT3	//0/x/x/x Power Gating Option for CKOUT1; Reserved
    #define D0F3_RBIASEN_CKOUT1_BUF2_A_H			BIT2	//0/x/x/x Bias Current Enable for CKOUT1
    #define D0F3_RCKNEN_CKOUT1_BUF2_A_H			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT1
    #define D0F3_RCKPEN_CKOUT1_BUF2_A_H			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT1
#define D0F3_DDR_BYTECLK_BUF_S24_CKOUT1_CHN_B		0xC58	//DDR_BYTECLK_BUF_S24 CKOUT1 Channel B
    #define D0F3_RTUNE_3_0_CKOUT1_B			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC59B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT1_B			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC59B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT1_B			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT1_B			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT1_B			BIT3	//0/x/x/x Power Gating Option for CKOUT1; Reserved
    #define D0F3_RBIASEN_CKOUT1_B			BIT2	//0/x/x/x Bias Current Enable for CKOUT1
    #define D0F3_RCKNEN_CKOUT1_B			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT1
    #define D0F3_RCKPEN_CKOUT1_B			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT1
#define D0F3_DDR_BYTECLK_BUF2_S24_CKOUT1_CHN_B_FOR_BYTE0_1_2_3_8		0xC5A	//DDR_BYTECLK_BUF2_S24 CKOUT1 Channel B for Byte0/1/2/3/8
    #define D0F3_RTUNE_3_0_CKOUT1_BUF2_B_L			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC5AB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT1_BUF2_B_L			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC5AB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT1_BUF2_B_L			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT1_BUF2_B_L			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT1_BUF2_B_L			BIT3	//0/x/x/x Power Gating Option for CKOUT1; Reserved
    #define D0F3_RBIASEN_CKOUT1_BUF2_B_L			BIT2	//0/x/x/x Bias Current Enable for CKOUT1
    #define D0F3_RCKNEN_CKOUT1_BUF2_B_L			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT1
    #define D0F3_RCKPEN_CKOUT1_BUF2_B_L			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT1
#define D0F3_DDR_BYTECLK_BUF2_S24_CKOUT1_CHN_B_FOR_BYTE4_5_6_7		0xC5C	//DDR_BYTECLK_BUF2_S24 CKOUT1 Channel B for Byte4/5/6/7
    #define D0F3_RTUNE_3_0_CKOUT1_BUF2_B_H			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC5CB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT1_BUF2_B_H			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC5CB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT1_BUF2_B_H			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT1_BUF2_B_H			BIT4	//0/x/x/x PTAT current enable
    #define D0F3_RPWEN_CKOUT1_BUF2_B_H			BIT3	//0/x/x/x Power Gating Option for CKOUT1; Reserved
    #define D0F3_RBIASEN_CKOUT1_BUF2_B_H			BIT2	//0/x/x/x Bias Current Enable for CKOUT1
    #define D0F3_RCKNEN_CKOUT1_BUF2_B_H			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT1
    #define D0F3_RCKPEN_CKOUT1_BUF2_B_H			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT1
#define D0F3_DDR_BYTECLK_BUF_S24_CKOUT3_CHN_A		0xC5E	//DDR_BYTECLK_BUF_S24 CKOUT3 Channel A
    #define D0F3_RTUNE_3_0_CKOUT3_A			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC5FB11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT3_A			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC5FB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT3_A			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT3_A			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT3_A			BIT3	//0/x/x/x Power Gating Option for CKOUT3; Reserved
    #define D0F3_RBIASEN_CKOUT3_A			BIT2	//0/x/x/x Bias Current Enable for CKOUT3
    #define D0F3_RCKNEN_CKOUT3_A			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT3
    #define D0F3_RCKPEN_CKOUT3_A			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT3
#define D0F3_DDR_BYTECLK_BUF2_S24_CKOUT3_CHN_A_FOR_BYTE0_1_2_3_8		0xC60	//DDR_BYTECLK_BUF2_S24 CKOUT3 Channel A for Byte0/1/2/3/8
    #define D0F3_RTUNE_3_0_CKOUT3_BUF2_A_L			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC61B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT3_BUF2_A_L			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC61B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT3_BUF2_A_L			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT3_BUF2_A_L			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT3_BUF2_A_L			BIT3	//0/x/x/x Power Gating Option for CKOUT3; Reserved
    #define D0F3_RBIASEN_CKOUT3_BUF2_A_L			BIT2	//0/x/x/x Bias Current Enable for CKOUT3
    #define D0F3_RCKNEN_CKOUT3_BUF2_A_L			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT3
    #define D0F3_RCKPEN_CKOUT3_BUF2_A_L			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT3
#define D0F3_DDR_BYTECLK_BUF2_S24_CKOUT3_CHN_A_FOR_BYTE4_5_6_7		0xC62	//DDR_BYTECLK_BUF2_S24 CKOUT3 Channel A for Byte4/5/6/7
    #define D0F3_RTUNE_3_0_CKOUT3_BUF2_A_H			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC62B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT3_BUF2_A_H			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC62B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT3_BUF2_A_H			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT3_BUF2_A_H			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT3_BUF2_A_H			BIT3	//0/x/x/x Power Gating Option for CKOUT3; Reserved
    #define D0F3_RBIASEN_CKOUT3_BUF2_A_H			BIT2	//0/x/x/x Bias current Enable for CKOUT3
    #define D0F3_RCKNEN_CKOUT3_BUF2_A_H			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT3
    #define D0F3_RCKPEN_CKOUT3_BUF2_A_H			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT3
#define D0F3_DDR_BYTECLK_BUF_S24_CKOUT3_CHN_B		0xC64	//DDR_BYTECLK_BUF_S24 CKOUT3 Channel B
    #define D0F3_RTUNE_3_0_CKOUT3_B			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC64B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT3_B			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC64B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT3_B			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT3_B			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT3_B			BIT3	//0/x/x/x Power Gating Option for CKOUT3; Reserved
    #define D0F3_RBIASEN_CKOUT3_B			BIT2	//0/x/x/x Bias Current Enable for CKOUT3
    #define D0F3_RCKNEN_CKOUT3_B			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT3
    #define D0F3_RCKPEN_CKOUT3_B			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT3
#define D0F3_DDR_BYTECLK_BUF2_S24_CKOUT3_CHN_B_FOR_BYTE0_1_2_3_8		0xC66	//DDR_BYTECLK_BUF2_S24 CKOUT3 Channel B for Byte0/1/2/3/8
    #define D0F3_RTUNE_3_0_CKOUT3_BUF2_B_L			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC66B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT3_BUF2_B_L			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC66B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT3_BUF2_B_L			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT3_BUF2_B_L			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT3_BUF2_B_L			BIT3	//0/x/x/x Power Gating Option for CKOUT3; Reserved
    #define D0F3_RBIASEN_CKOUT3_BUF2_B_L			BIT2	//0/x/x/x Bias Current Enable for CKOUT3
    #define D0F3_RCKNEN_CKOUT3_BUF2_B_L			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT3
    #define D0F3_RCKPEN_CKOUT3_BUF2_B_L			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT3
#define D0F3_DDR_BYTECLK_BUF2_S24_CKOUT3_CHN_B_FOR_BYTE4_5_6_7		0xC68	//DDR_BYTECLK_BUF2_S24 CKOUT3 Channel B for Byte4/5/6/7
    #define D0F3_RTUNE_3_0_CKOUT3_BUF2_B_H			0xF000	//0/x/x/x ajust DDR_BYTECLK_BUF_S24 delay
    #define D0F3_D0F3_RXC68B11			BIT11	//0/x/x/x Reserved
    #define D0F3_RDRV_2_0_CKOUT3_BUF2_B_H			(BIT8 + BIT9 + BIT10)	//0/x/x/x Buffer Current Setting; Reserved
    #define D0F3_D0F3_RXC68B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F3_RDIGBUFEN_CKOUT3_BUF2_B_H			BIT5	//0/x/x/x Change the Structure of Buffer from Analog to Digital
    #define D0F3_RPTATEN_CKOUT3_BUF2_B_H			BIT4	//0/x/x/x PTAT Current Enable
    #define D0F3_RPWEN_CKOUT3_BUF2_B_H			BIT3	//0/x/x/x Power gating option for CKOUT3; Reserved
    #define D0F3_RBIASEN_CKOUT3_BUF2_B_H			BIT2	//0/x/x/x Bias Current Enable for CKOUT3
    #define D0F3_RCKNEN_CKOUT3_BUF2_B_H			BIT1	//1b/x/x/x Negative Clock Gating for CKOUT3
    #define D0F3_RCKPEN_CKOUT3_BUF2_B_H			BIT0	//1b/x/x/x Positive Clock Gating for CKOUT3
#define D0F3_ADLL_FEEDBACK_CLK_DELAY_SETTING_TO_CORRECT_DELAY_LINE		0xC6A	//ADLL Feedback Clock Delay Setting to Correct Delay Line
    #define D0F3_D0F3_RXC50B_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DLL_A_RFBDLY_2_0			(BIT4 + BIT5 + BIT6)	//011b/x/x/x ADLL Feedback Clock Delay Setting to Correct Delay Line
    #define D0F3_D0F3_RXC50B3			BIT3	//0/x/x/x Reserved
    #define D0F3_DLL_B_RFBDLY_2_0			(BIT0 + BIT1 + BIT2)	//011b/x/x/x ADLL Feedback Clock Delay Setting to Correct Delay Line
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A0_CHN_A		0xC6C	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A0 Channel A
    #define D0F3_DCLKOP_A0_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A0 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A0_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A0 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_A0_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A0 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A0_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A0 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A0_CHN_A		0xC6D	//ADLL_S24+MUX_PI for DCLKD/DCLKS A0 Channel A
    #define D0F3_DCLKD_A0_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A0 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A0_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A0 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A0_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A0 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A0_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A0 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A0_CHN_A		0xC6E	//ADLL_S24+MUX_PI for DCLKDSI A0 Channel A
    #define D0F3_D0F3_RXC6EB7			BIT7	//0/x/x/x Reserved
    #define D0F3_RBUFRX_DIGBUFEN_A			BIT6	//0/x/x/x DCLKP/N & DCLK800P/N Mode
    #define D0F3_RBUFRX_BIASEN_A			BIT5	//1b/x/x/x Enable DCLKP/N & DCLK800P/N Bias Current
    #define D0F3_RBUFRX_PATEN_A			BIT4	//0/x/x/x Select Current of PTAT or BUFRX_IBP100U_IN
    #define D0F3_DCLKDSI_A0_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A0 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A0_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A0 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A1_CHN_A		0xC6F	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A1 Channel A
    #define D0F3_DCLKOP_A1_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A1 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A1_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A1 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_A1_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A1 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A1_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A1 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A1_CHN_A		0xC70	//ADLL_S24+MUX_PI for DCLKD/DCLKS A1 channel A
    #define D0F3_DCLKD_A1_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A1 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A1_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A1 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A1_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A1 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A1_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A1 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A1_CHN_A		0xC71	//ADLL_S24+MUX_PI for DCLKDSI A1 Channel A
    #define D0F3_D0F3_RXC71B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_A1_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A1 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A1_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A1 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A2_CHN_A		0xC72	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A2 Channel A
    #define D0F3_DCLKOP_A2_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A2 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A2_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A2 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_A2_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A2 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A2_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A2 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A2_CHN_A		0xC73	//ADLL_S24+MUX_PI for DCLKD/DCLKS A2 Channel A
    #define D0F3_DCLKD_A2_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A2 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A2_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A2 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A2_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A2 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A2_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A2 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A2_CHN_A		0xC74	//ADLL_S24+MUX_PI for DCLKDSI A2 Channel A
    #define D0F3_D0F3_RXC74B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_A2_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A2 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A2_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A2 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A3_CHN_A		0xC75	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A3 Channel A
    #define D0F3_DCLKOP_A3_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A3 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A3_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A3 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_A3_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A3 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A3_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A3 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A3_CHN_A		0xC76	//ADLL_S24+MUX_PI for DCLKD/DCLKS A3 Channel A
    #define D0F3_DCLKD_A3_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A3 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A3_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A3 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A3_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A3 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A3_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A3 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A3_CHN_A		0xC77	//ADLL_S24+MUX_PI for DCLKDSI A3 Channel A
    #define D0F3_D0F3_RXC77B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_A3_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A3 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A3_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A3 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A4_CHN_A		0xC78	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A4 Channel A
    #define D0F3_DCLKOP_A4_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A4 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A4_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A4 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_A4_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A4 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A4_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A4 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A4_CHN_A		0xC79	//ADLL_S24+MUX_PI for DCLKD/DCLKS A4 Channel A
    #define D0F3_DCLKD_A4_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A4 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A4_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A4 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A4_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A4 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A4_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A4 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A4_CHN_A		0xC7A	//ADLL_S24+MUX_PI for DCLKDSI A4 Channel A
    #define D0F3_D0F3_RXC7AB_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_A4_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A4 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A4_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A4 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A5_CHN_A		0xC7B	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A5 Channel A
    #define D0F3_DCLKOP_A5_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A5 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A5_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A5 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_A5_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A5 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A5_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A5 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A5_CHN_A		0xC7C	//ADLL_S24+MUX_PI for DCLKD/DCLKS A5 Channel A
    #define D0F3_DCLKD_A5_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A5 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A5_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A5 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A5_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A5 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A5_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A5 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A5_CHN_A		0xC7D	//ADLL_S24+MUX_PI for DCLKDSI A5 Channel A
    #define D0F3_D0F3_RXC7DB_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_A5_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A5 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A5_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A5 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A6_CHN_A		0xC7E	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A6 Channel A
    #define D0F3_DCLKOP_A6_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A6 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A6_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A6 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_A6_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A6 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A6_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A6 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A6_CHN_A		0xC7F	//ADLL_S24+MUX_PI for DCLKD/DCLKS A6 Channel A
    #define D0F3_DCLKD_A6_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A6 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A6_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A6 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A6_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A6 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A6_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A6 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A6_CHN_A		0xC80	//ADLL_S24+MUX_PI for DCLKDSI A6 Channel A
    #define D0F3_D0F3_RXC80B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_A6_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A6 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A6_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A6 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A7_CHN_A		0xC81	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A7 Channel A
    #define D0F3_DCLKOP_A7_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A7 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A7_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A7 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_A7_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A7 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A7_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A7 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A7_CHN_A		0xC82	//ADLL_S24+MUX_PI for DCLKD/DCLKS A7 Channel A
    #define D0F3_DCLKD_A7_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A7 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A7_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A7 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A7_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A7 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A7_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A7 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A7_CHN_A		0xC83	//ADLL_S24+MUX_PI for DCLKDSI A7 Channel A
    #define D0F3_D0F3_RXC83B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_A7_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A7 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A7_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A7 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_A8_CHN_A		0xC84	//ADLL_S24+MUX_PI for DCLKO/DCLKOP A8 Channel A
    #define D0F3_DCLKOP_A8_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A8 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_A8_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A8 VCDL DCLKOP clock Duty Tuning
    #define D0F3_DCLKO_A8_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A8 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_A8_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A8 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_A8_CHN_A		0xC85	//ADLL_S24+MUX_PI for DCLKD/DCLKS A8 Channel A
    #define D0F3_DCLKD_A8_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY A8 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_A8_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY A8 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_A8_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A8 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_A8_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A8 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_A8_CHN_A		0xC86	//ADLL_S24+MUX_PI for DCLKDSI A8 Channel A
    #define D0F3_D0F3_RXC86B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_A8_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY A8 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_A8_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY A8 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B0_CHN_B		0xC87	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B0 Channel B
    #define D0F3_DCLKOP_B0_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B0 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B0_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B0 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B0_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B0 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B0_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B0 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B0_CHN_B		0xC88	//ADLL_S24+MUX_PI for DCLKD/DCLKS B0 Channel B
    #define D0F3_DCLKD_B0_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B0 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B0_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B0 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B0_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B0 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B0_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B0 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B0_CHN_B		0xC89	//ADLL_S24+MUX_PI for DCLKDSI B0 Channel B
    #define D0F3_D0F3_RXC89B7			BIT7	//0/x/x/x Reserved
    #define D0F3_RBUFRX_DIGBUFEN_B			BIT6	//0/x/x/x DCLKP/N & DCLK800P/N Mode
    #define D0F3_RBUFRX_BIASEN_B			BIT5	//1b/x/x/x Enable DCLKP/N & DCLK800P/N Bias Current
    #define D0F3_RBUFRX_PATEN_B			BIT4	//0/x/x/x Select Current of PTAT or BUFRX_IBP100U_IN
    #define D0F3_DCLKDSI_B0_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B0 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B0_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B0 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B1_CHN_B		0xC8A	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B1 Channel B
    #define D0F3_DCLKOP_B1_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B1 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B1_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B1 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B1_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B1 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B1_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B1 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B1_CHN_B		0xC8B	//ADLL_S24+MUX_PI for DCLKD/DCLKS B1 Channel B
    #define D0F3_DCLKD_B1_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B1 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B1_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B1 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B1_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B1 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B1_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B1 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B1_CHN_B		0xC8C	//ADLL_S24+MUX_PI for DCLKDSI B1 Channel B
    #define D0F3_D0F3_RXC8CB_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_B1_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B1 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B1_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B1 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B2_CHN_B		0xC8D	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B2 Channel B
    #define D0F3_DCLKOP_B2_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B2 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B2_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B2 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B2_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B2 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B2_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B2 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B2_CHN_B		0xC8E	//ADLL_S24+MUX_PI for DCLKD/DCLKS B2 Channel B
    #define D0F3_DCLKD_B2_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B2 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B2_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B2 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B2_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B2 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B2_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B2 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B2_CHN_B		0xC8F	//ADLL_S24+MUX_PI for DCLKDSI B2 Channel B
    #define D0F3_D0F3_RXC8FB_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_B2_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B2 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B2_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B2 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B3_CHN_B		0xC90	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B3 Channel B
    #define D0F3_DCLKOP_B3_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B3 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B3_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B3 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B3_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B3 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B3_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B3 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B3_CHN_B		0xC91	//ADLL_S24+MUX_PI for DCLKD/DCLKS B3 Channel B
    #define D0F3_DCLKD_B3_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B3 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B3_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B3 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B3_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B3 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B3_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B3 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B3_CHN_B		0xC92	//ADLL_S24+MUX_PI for DCLKDSI B3 Channel B
    #define D0F3_D0F3_RXC92B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_B3_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B3 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B3_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B3 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B4_CHN_B		0xC93	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B4 Channel B
    #define D0F3_DCLKOP_B4_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B4 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B4_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B4 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B4_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B4 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B4_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B4 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B4_CHN_B		0xC94	//ADLL_S24+MUX_PI for DCLKD/DCLKS B4 Channel B
    #define D0F3_DCLKD_B4_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B4 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B4_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B4 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B4_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B4 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B4_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B4 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B4_CHN_B		0xC95	//ADLL_S24+MUX_PI for DCLKDSI B4 Channel B
    #define D0F3_D0F3_RXC95B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_B4_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B4 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B4_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B4 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B5_CHN_B		0xC96	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B5 Channel B
    #define D0F3_DCLKOP_B5_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B5 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B5_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B5 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B5_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B5 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B5_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B5 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B5_CHN_B		0xC97	//ADLL_S24+MUX_PI for DCLKD/DCLKS B5 Channel B
    #define D0F3_DCLKD_B5_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B5 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B5_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B5 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B5_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B5 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B5_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B5 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B5_CHN_B		0xC98	//ADLL_S24+MUX_PI for DCLKDSI B5 Channel B
    #define D0F3_D0F3_RXC98B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_B5_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B5 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B5_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B5 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B6_CHN_B		0xC99	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B6 Channel B
    #define D0F3_DCLKOP_B6_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B6 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B6_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B6 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B6_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B6 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B6_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B6 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B6_CHN_B		0xC9A	//ADLL_S24+MUX_PI for DCLKD/DCLKS B6 Channel B
    #define D0F3_DCLKD_B6_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B6 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B6_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B6 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B6_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B6 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B6_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B6 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B6_CHN_B		0xC9B	//ADLL_S24+MUX_PI for DCLKDSI B6 Channel B
    #define D0F3_D0F3_RXC9BB_7_4			0xF0	//0/x/x/x reserved
    #define D0F3_DCLKDSI_B6_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B6 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B6_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B6 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B7_CHN_B		0xC9C	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B7 Channel B
    #define D0F3_DCLKOP_B7_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B7 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B7_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B7 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B7_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B7 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B7_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B7 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B7_CHN_B		0xC9D	//ADLL_S24+MUX_PI for DCLKD/DCLKS B7 Channel B
    #define D0F3_DCLKD_B7_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B7 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B7_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B7 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B7_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B7 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B7_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B7 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B7_CHN_B		0xC9E	//ADLL_S24+MUX_PI for DCLKDSI B7 Channel B
    #define D0F3_D0F3_RXC9EB_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_B7_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B7 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B7_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B7 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKO_DCLKOP_B8_CHN_B		0xC9F	//ADLL_S24+MUX_PI for DCLKO/DCLKOP B8 channel B
    #define D0F3_DCLKOP_B8_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B8 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKOP_B8_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B8 VCDL DCLKOP Clock Duty Tuning
    #define D0F3_DCLKO_B8_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B8 VCDL DCLKO Clock Duty Tuning
    #define D0F3_DCLKO_B8_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B8 VCDL DCLKO Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKD_DCLKS_B8_CHN_B		0xCA0	//ADLL_S24+MUX_PI for DCLKD/DCLKS B8 channel B
    #define D0F3_DCLKD_B8_SRCTRL_1_0			(BIT6 + BIT7)	//0/x/x/x PHY B8 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKD_B8_SFCTRL_1_0			(BIT4 + BIT5)	//0/x/x/x PHY B8 VCDL DCLKD Clock Duty Tuning
    #define D0F3_DCLKS_B8_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B8 VCDL DCLKS Clock Duty Tuning
    #define D0F3_DCLKS_B8_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B8 VCDL DCLKS Clock Duty Tuning
#define D0F3_ADLL_S24_MUX_PI_FOR_DCLKDSI_B8_CHN_B		0xCA1	//ADLL_S24+MUX_PI for DCLKDSI B8 Channel B
    #define D0F3_D0F3_RXCA1B_7_4			0xF0	//0/x/x/x Reserved
    #define D0F3_DCLKDSI_B8_SRCTRL_1_0			(BIT2 + BIT3)	//0/x/x/x PHY B8 VCDL DCLKDSI Clock Duty Tuning
    #define D0F3_DCLKDSI_B8_SFCTRL_1_0			(BIT0 + BIT1)	//0/x/x/x PHY B8 VCDL DCLKDSI Clock Duty Tuning
#define D0F3_DDRPHY_A0_RESERVED_REG		0xCA2	//DDRPHY A0 Reserved Register
    #define D0F3_DDRPHY_A0_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A0_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A0_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A0_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A0_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_A1_RESERVED_REG		0xCA4	//DDRPHY A1 Reserved Register
    #define D0F3_DDRPHY_A1_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A1_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A1_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A1_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A1_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_A2_RESERVED_REG		0xCA6	//DDRPHY A2 Reserved Register
    #define D0F3_DDRPHY_A2_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A2_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A2_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A2_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A2_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_A3_RESERVED_REG		0xCA8	//DDRPHY A3 Reserved Register
    #define D0F3_DDRPHY_A3_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A3_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A3_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A3_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A3_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_A4_RESERVED_REG		0xCAA	//DDRPHY A4 Reserved Register
    #define D0F3_DDRPHY_A4_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A4_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A4_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A4_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A4_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_A5_RESERVED_REG		0xCAC	//DDRPHY A5 Reserved Register
    #define D0F3_DDRPHY_A5_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A5_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A5_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A5_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A5_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_A6_RESERVED_REG		0xCAE	//DDRPHY A6 Reserved Register
    #define D0F3_DDRPHY_A6_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A6_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A6_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A6_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A6_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_A7_RESERVED_REG		0xCB0	//DDRPHY A7 Reserved Register
    #define D0F3_DDRPHY_A7_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A7_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A7_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A7_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A7_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_A8_RESERVED_REG		0xCB2	//DDRPHY A8 Reserved Register
    #define D0F3_DDRPHY_A8_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A8_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_A8_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_A8_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_A8_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B0_RESERVED_REG		0xCB4	//DDRPHY B0 Reserved Register
    #define D0F3_DDRPHY_B0_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B0_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B0_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B0_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B0_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B1_RESERVED_REG		0xCB6	//DDRPHY B1 Reserved Register
    #define D0F3_DDRPHY_B1_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B1_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B1_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B1_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B1_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B2_RESERVED_REG		0xCB8	//DDRPHY B2 Reserved Register
    #define D0F3_DDRPHY_B2_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B2_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B2_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B2_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B2_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B3_RESERVED_REG		0xCBA	//DDRPHY B3 Reserved Register
    #define D0F3_DDRPHY_B3_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B3_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B3_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B3_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B3_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B4_RESERVED_REG		0xCBC	//DDRPHY B4 Reserved Register
    #define D0F3_DDRPHY_B4_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B4_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B4_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B4_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B4_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B5_RESERVED_REG		0xCBE	//DDRPHY B5 Reserved Register
    #define D0F3_DDRPHY_B5_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B5_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B5_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B5_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B5_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B6_RESERVED_REG		0xCC0	//DDRPHY B6 Reserved Register
    #define D0F3_DDRPHY_B6_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B6_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B6_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B6_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B6_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B7_RESERVED_REG		0xCC2	//DDRPHY B7 Reserved Register
    #define D0F3_DDRPHY_B7_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B7_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B7_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B7_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B7_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRPHY_B8_RESERVED_REG		0xCC4	//DDRPHY B8 Reserved Register
    #define D0F3_DDRPHY_B8_REV_15_7			0xFF80	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B8_REV_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Debug signal control.
    #define D0F3_DDRPHY_B8_REV3			BIT3	//0/x/x/x Reserved
    #define D0F3_DDRPHY_B8_REV_2_1			(BIT1 + BIT2)	//0/x/x/x used for de-glitch enable of TX clock phase change ( DCLKO/DCLKOP/DCLKD/DCLKS/DCLKDSI)
    #define D0F3_DDRPHY_B8_REV0			BIT0	//0/x/x/x Connect to VCDL_BYTE DLL_CP_EN, used to enable bias current advanced by DLL_EN.
#define D0F3_DDRIO_CHN_A_B_DYNAMIC_CTL		0xCC6	//DDRIO Channel A/B Dynamic Control
    #define D0F3_RBGB0_INIT_SEL			BIT15	//0/0/x/x reserved
    #define D0F3_RMIR_INIT_CHB			BIT14	//0/0/x/x reserved
    #define D0F3_RBGB1_INIT_SEL			BIT13	//0/0/x/x reserved
    #define D0F3_RBSIDE_INIT_CHB			BIT12	//0/0/x/x reserved
    #define D0F3_RRKSEL_B8_DQS_1_0			(BIT10 + BIT11)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_A8_DQS_1_0			(BIT8 + BIT9)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_D0F3_RXCC6B7			BIT7	//0/0/x/x Reserved
    #define D0F3_RRPRE_ODT_2T			BIT6	//0/0/x/x DDR4 ODT Control
    #define D0F3_RBGA0_INIT_SEL			BIT5	//0/0/x/x reserved
    #define D0F3_RMIR_INIT			BIT4	//0/0/x/x reserved
    #define D0F3_RBGA1_INIT_SEL			BIT3	//0/0/x/x reserved
    #define D0F3_RBSIDE_INIT			BIT2	//0/0/x/x reserved
    #define D0F3_RDCLKOAPM			BIT1	//0/0/1/1 Channel A Control Dynamic Clock
    #define D0F3_RDCLKOBPM			BIT0	//0/0/1/1 Channel B Control Dynamic Clock
#define D0F3_DDRPHY_DQS_RANK_SEL_CTL		0xCC8	//DDRPHY DQS Rank Select Control
    #define D0F3_RRKSEL_A7_DQS_1_0			(BIT14 + BIT15)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_A6_DQS_1_0			(BIT12 + BIT13)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_A5_DQS_1_0			(BIT10 + BIT11)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_A4_DQS_1_0			(BIT8 + BIT9)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_A3_DQS_1_0			(BIT6 + BIT7)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_A2_DQS_1_0			(BIT4 + BIT5)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_A1_DQS_1_0			(BIT2 + BIT3)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_A0_DQS_1_0			(BIT0 + BIT1)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
#define D0F3_DDRPHY_DQS_RANK_SEL_CTL_Z1		0xCCA	//DDRPHY DQS Rank Select Control
    #define D0F3_RRKSEL_B7_DQS_1_0			(BIT14 + BIT15)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_B6_DQS_1_0			(BIT12 + BIT13)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_B5_DQS_1_0			(BIT10 + BIT11)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_B4_DQS_1_0			(BIT8 + BIT9)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_B3_DQS_1_0			(BIT6 + BIT7)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_B2_DQS_1_0			(BIT4 + BIT5)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_B1_DQS_1_0			(BIT2 + BIT3)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
    #define D0F3_RRKSEL_B0_DQS_1_0			(BIT0 + BIT1)	//0/0/0/0 The Register Control DDRPHY DQS Phase Rank Select delay or not,the function just like RRANK_DELAY(RX234):
#define D0F3_DDRPHY_DQS_RANK_SEL_CTL_Z2		0xCCC	//DDRPHY DQS Rank Select Control
    #define D0F3_D0F3_RXCCCB_15_4			0xFFF0	//0/0/0/0 Reserved
    #define D0F3_RCLK_DEBUG_MODE			BIT3	//0/0/0/0 Select Clock for Pad to debug
    #define D0F3_RDBG_CKOUT_2_0			(BIT0 + BIT1 + BIT2)	//0/0/0/0 Debug Clock Select
#endif
