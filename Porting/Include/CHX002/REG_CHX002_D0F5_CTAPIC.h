//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		CTAPIC					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D0F5_CTAPIC_R103(A0).doc(final)MOD_D0F5.xls
#ifndef _CHX002_D0F5_CTAPIC_H
#define _CHX002_D0F5_CTAPIC_H
//D0F5
#define D0F5_VID		0x00	//Vendor ID
    #define D0F5_VENDORID_15_0			0xFFFF	//1106h/x/x/x Vendor ID
#define D0F5_DID		0x02	//Device ID
    #define D0F5_DEVID_15_0			0xFFFF	//31B4h/x/x/x Device ID
#define D0F5_PCI_CMD		0x04	//PCI Command
    #define D0F5_RX04_15_10			0xFC00	//0/R/x/x Reserved
    #define D0F5_RFBACK			BIT9	//0/R/x/x Fast Back-to-back Cycle Enable
    #define D0F5_RSERR			BIT8	//0/R/x/x SERR# Enable
    #define D0F5_RSETP			BIT7	//0/R/x/x Address/Data Stepping
    #define D0F5_RPTYERR			BIT6	//0/0/x/x Parity Error Response
    #define D0F5_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D0F5_RMWINV			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D0F5_RSPCYC			BIT3	//0/R/x/x Respond to Special Cycle
    #define D0F5_RMSTR			BIT2	//1b/R/x/x PCI Master Function
    #define D0F5_RENMEM			BIT1	//1b/R/x/x Memory Space Access
    #define D0F5_RENIO			BIT0	//0/R/x/x I/O Space Access
#define D0F5_PCI_STA		0x06	//PCI Status
    #define D0F5_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D0F5_SERRS			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D0F5_SMABORT			BIT13	//0/R/x/x Received Master-abort (Except Special Cycle)
    #define D0F5_STABORTM			BIT12	//0/R/x/x Received Target-abort
    #define D0F5_STABORTS			BIT11	//0/R/x/x Target-abort Assertion
    #define D0F5_DEVS_1_0			(BIT9 + BIT10)	//0/R/x/x DEVSEL# Timing
    #define D0F5_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D0F5_RFBKS			BIT7	//0/R/x/x Capable of Accepting Fast Back-to-back as a Target
    #define D0F5_RUDF			BIT6	//0/R/x/x User Definable Features
    #define D0F5_R66M			BIT5	//0/R/x/x 66MHz Capability
    #define D0F5_RCAP			BIT4	//1b/R/x/x Support New Capability List
    #define D0F5_RX04_19_16			0xF	//0/R/x/x Reserved
#define D0F5_REV_ID		0x08	//Revision ID
    #define D0F5_RX08_7_0			0xFF	//04h/x/x/x Revision Code
#define D0F5_CLASS_CODE		0x09	//Class Code
    #define D0F5_CLASSCODE			0xFFFFFF	//060000h/x/x/x Class Code
#define D0F5_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D0F5_RX0C_7_0			0xFF	//0/x/x/x Cache Line Size
#define D0F5_MASTER_LATENCY_TIMER		0x0D	//Master Latency Timer
    #define D0F5_RX0C_15_8			0xFF	//0/R/x/x Maximum Time Slice for this Function as a Master on the PCI Bus
#define D0F5_HEADER_TYPE		0x0E	//Header Type
    #define D0F5_RX0C_23_16			0xFF	//80h/80h/x/x Header Type
#define D0F5_BUILD_IN_SELF_TEST_BIST		0x0F	//Build In Self Test (BIST)
    #define D0F5_RX0C_31_24			0xFF	//0/R/x/x BIST Support
#define D0F5_BASE_ADR_REGS_0		0x10	//Base Address Registers 0
    #define D0F5_RX10_31_0			0xFFFFFFFF	//0/R/x/x Base Address 0
#define D0F5_BASE_ADR_REGS_1		0x14	//Base Address Registers 1
    #define D0F5_RX14_31_0			0xFFFFFFFF	//0/R/x/x Base Address 1
#define D0F5_BASE_ADR_REGS_2		0x18	//Base Address Registers 2
    #define D0F5_RX18_31_0			0xFFFFFFFF	//0/R/x/x Base Address 2
#define D0F5_BASE_ADR_REGS_3		0x1C	//Base Address Registers 3
    #define D0F5_RX1C_31_0			0xFFFFFFFF	//0/R/x/x Base Address 3
#define D0F5_BASE_ADR_REGS_4		0x20	//Base Address Registers 4
    #define D0F5_RX20_31_0			0xFFFFFFFF	//0/R/x/x Base Address 4
#define D0F5_BASE_ADR_REGS_5		0x24	//Base Address Registers 5
    #define D0F5_RX24_31_0			0xFFFFFFFF	//0/R/x/x Base Address 5
#define D0F5_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D0F5_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D0F5_SVID		0x2C	//Subsystem Vendor ID
    #define D0F5_RX2C_15_0			0xFFFF	//0/x/x/x Subsystem Vendor ID
#define D0F5_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D0F5_RX2C_31_16			0xFFFF	//0/x/x/x Subsystem ID
#define D0F5_CAP_POINTER		0x34	//Capability Pointer
    #define D0F5_CAPPTR_7_0			0xFF	//40h/40h/x/x Capability Pointer
#define D0F5_RESERVED		0x35	//Reserved
    #define D0F5_RX35_7_0			0xFF	//0/0/x/x Reserved
#define D0F5_RESERVED_Z1		0x36	//Reserved
    #define D0F5_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D0F5_RESERVED_Z2		0x37	//Reserved
    #define D0F5_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D0F5_INTR_LINE_AND_INTR_PIN		0x3C	//Interrupt Line and Interrupt Pin
    #define D0F5_RX3C_15_8			0xFF00	//0/R/x/x Interrupt Pin
    #define D0F5_RX3C_7_0			0xFF	//0/R/x/x Interrupt Line
#define D0F5_MINIMUM_GRANT_AND_MAXIMUM_LATENCY		0x3E	//Minimum Grant and Maximum Latency
    #define D0F5_RX3C_31_24			0xFF00	//0/R/x/x Maximum Latency
    #define D0F5_RX3C_23_16			0xFF	//0/R/x/x Minimum Grant
#define D0F5_PCI_EXPRESS_LIST		0x40	//PCI Express List
    #define D0F5_RX40_15_8			0xFF00	//F8h/F8h/x/x Next Pointer
    #define D0F5_RX40_7_0			0xFF	//10h/10h/x/x Capability ID
#define D0F5_PCI_EXPRESS_CAPS		0x42	//PCI Express Capabilities
    #define D0F5_RX42_15_14			(BIT14 + BIT15)	//0/0/x/x Reserved
    #define D0F5_RX42_13_9			0x3E00	//0/0/x/x Interrupt Message Number
    #define D0F5_RX42_8			BIT8	//0b/0b/x/x Slot Implemented
    #define D0F5_RX42_7_4			0xF0	//0100b/0100b/x/x Device / Port Type
    #define D0F5_RX42_3_0			0xF	//2h/2h/x/x Capability Version Bit
#define D0F5_DEV_CAPS_1		0x44	//Device Capabilities 1
    #define D0F5_RSV_19			(BIT29 + BIT30 + BIT31)	//0/R/x/x Reserved
    #define D0F5_TBD_27			BIT28	//0/0/x/x Function Level Reset Capability
    #define D0F5_RSV_20			(BIT26 + BIT27)	//0/0/x/x Captured Slot Power Limit Scale
    #define D0F5_RSV_21			0x3FC0000	//0/0/x/x Captured Slot Power Limit Value
    #define D0F5_RSV_22			(BIT16 + BIT17)	//0/R/x/x Reserved
    #define D0F5_RRBERRP			BIT15	//1b/1/x/x Role-based Error Reporting
    #define D0F5_RSV_23			BIT14	//0/0/x/x Power Indicator Present
    #define D0F5_RSV_24			BIT13	//0/0/x/x Attention Indicator Present
    #define D0F5_RSV_25			BIT12	//0/0/x/x Attention Button Present
    #define D0F5_DAL1AL			(BIT9 + BIT10 + BIT11)	//000b/0/x/x Endpoint L1 Acceptable Latency
    #define D0F5_RSV_44			(BIT6 + BIT7 + BIT8)	//0/0/x/x Endpoint L0s Acceptable Latency
    #define D0F5_DAXTAGF			BIT5	//0/0/x/x Extended Tag Field Supported
    #define D0F5_RSV_26			(BIT3 + BIT4)	//0/0/x/x Phantom Functions Supported
    #define D0F5_DAMPSS			(BIT0 + BIT1 + BIT2)	//000b/000b/x/x Max Payload Size Supported
#define D0F5_DEV_CTL_1		0x48	//Device Control 1
    #define D0F5_RSV_27			BIT15	//0/R/x/x Reserved
    #define D0F5_DCMRRS			(BIT12 + BIT13 + BIT14)	//0/0/x/x Max Read Request Size
    #define D0F5_DCENS			BIT11	//0/0/x/x Enable No Snoop
    #define D0F5_DCAPPME			BIT10	//0/0/x/x Auxiliary Power PM Enable
    #define D0F5_DCPFE			BIT9	//0/0/x/x Phantom Functions Enable
    #define D0F5_DCETFE			BIT8	//0/0/x/x Extended Tag Field Enable
    #define D0F5_DCMPS			(BIT5 + BIT6 + BIT7)	//0/0/0/x Max Payload Size
    #define D0F5_DCERO			BIT4	//1b/1/x/x Enable Relaxed Ordering
    #define D0F5_DCURRE			BIT3	//0/0/x/x Unsupported Request Reporting Enable
    #define D0F5_DCFERE			BIT2	//0/0/x/x Fatal Error Reporting Enable
    #define D0F5_DCNFERE			BIT1	//0/0/x/x Non-Fatal Error Reporting Enable
    #define D0F5_DCCERE			BIT0	//0/0/x/x Correctable Error Reporting Enable
#define D0F5_DEV_STA_1		0x4A	//Device Status 1
    #define D0F5_RSV_4B			0xFFC0	//0/R/x/x Reserved
    #define D0F5_DSTP			BIT5	//0/0/x/x Transactions Pending
    #define D0F5_DSAPD			BIT4	//0/0/x/x AUX Power Detected
    #define D0F5_DSURD			BIT3	//0/0/x/x Unsupported Request Detected (TL)
    #define D0F5_DSFED			BIT2	//0/0/x/x Fatal Error Detected (TL)
    #define D0F5_DSNFED			BIT1	//0/0/x/x Non-Fatal Error Detected (TL)
    #define D0F5_DSCED			BIT0	//0/0/x/x Correctable Error Detected (TL)
#define D0F5_LINK_CAPS_1		0x4C	//Link Capabilities 1
    #define D0F5_LKPN			0xFF000000	//0Ch/x/x/x Port Number
    #define D0F5_RSV_31			(BIT22 + BIT23)	//0/R/x/x Reserved
    #define D0F5_RLBWNTFC			BIT21	//0/0b/x/x Link Bandwidth Notification Capability
    #define D0F5_RDL_AR_CAP			BIT20	//0/0b/x/x Data Link Layer Link Active Reporting Capable
    #define D0F5_RLCASDERC			BIT19	//0/0b/x/x Surprise Down Error Reporting Capable
    #define D0F5_RLCACPM			BIT18	//0/0/x/x Clock Power Management
    #define D0F5_LKL1EL			(BIT15 + BIT16 + BIT17)	//011b/x/x/x L1 Exit Latency
    #define D0F5_LKL0SE			(BIT12 + BIT13 + BIT14)	//011b/x/x/x L0s Exit Latency
    #define D0F5_LKAPMS			(BIT10 + BIT11)	//11b/11b/x/x Active State Link PM (ASPM) Support
    #define D0F5_LKMLW_5			BIT9	//0/0/x/x Maximum Link Width Bit 5
    #define D0F5_LKMLW_4			BIT8	//0/0/x/x Maximum Link Width Bit 4
    #define D0F5_LKMLW_3			BIT7	//0/0/x/x Maximum Link Width Bit 3
    #define D0F5_LKMLW_2			BIT6	//1b/1b/x/x Maximum Link Width Bit 2
    #define D0F5_LKMLW_1			BIT5	//0/x/x/x Maximum Link Width Bit 1
    #define D0F5_LKMLW_0			BIT4	//0/x/x/x Maximum Link Width Bit 0
    #define D0F5_LKMAXLS_3			BIT3	//0/0/x/x Max Link Speed Bit 3 
    #define D0F5_LKMAXLS_2			BIT2	//0/0/x/x Max Link Speed Bit 2
    #define D0F5_LKMAXLS_1			BIT1	//0/0b/x/x Max Link Speed Bit 1
    #define D0F5_LKMAXLS_0			BIT0	//1b/1b/x/x Max Link Speed Bit 0
#define D0F5_LINK_CTL_1		0x50	//Link Control 1
    #define D0F5_RSV_32			0xF000	//0/R/x/x Reserved
    #define D0F5_RLABITEN			BIT11	//0/0/x/x Enable Link Autonomous Bandwidth Interrupt
    #define D0F5_RLBMITEN			BIT10	//0/0/x/x Enable Link Bandwidth Management Interrupt
    #define D0F5_RHATNMWD			BIT9	//0/0/x/0 Hardware Autonomous Width Control
    #define D0F5_RLCOCPMEN			BIT8	//0/0/x/x Enable Clock Power Management
    #define D0F5_LCES			BIT7	//0/0/0/x Extended Synch
    #define D0F5_LCCCC			BIT6	//1b/x/x/x Common Clock Configuration
    #define D0F5_LCRL			BIT5	//0/0/x/x Retrain Link
    #define D0F5_LCLD			BIT4	//0/0/x/x Link Disable
    #define D0F5_LCRCB			BIT3	//0/0/x/x Read Completion Boundary
    #define D0F5_RSV_33			BIT2	//0/R/x/x Reserved
    #define D0F5_LCAPMS			(BIT0 + BIT1)	//00b/0/0/11 Link Active State PM (ASPM) Control
#define D0F5_LINK_STA_1		0x52	//Link Status 1
    #define D0F5_RLATNMBW			BIT15	//0/0/x/x Link Autonomous Bandwidth Status
    #define D0F5_RLBWMNGT			BIT14	//0/0/x/x Link Bandwidth Management Status
    #define D0F5_DL_ACTIVE			BIT13	//0/x/x/x Data Link Layer Link Active
    #define D0F5_LSSCC			BIT12	//1b/x/x/x Slot Clock Configuration
    #define D0F5_LSLT			BIT11	//0/0/x/x Link Training
    #define D0F5_LSTE			BIT10	//0/0/x/x Training Error
    #define D0F5_TBD_28			BIT9	//0/0/x/x Negotiated Link Width Bit 5
    #define D0F5_LSNLW			0x1F0	//0/0/x/x Negotiated Link Width Bits[4:0]
    #define D0F5_LSLS			0xF	//0/0/x/x Current Link Speed
#define D0F5_SLOT_CAPS_1		0x54	//Slot Capabilities 1
    #define D0F5_SLPSN			0xFFF80000	//0/0/x/x Physical Slot Number; Reserved
    #define D0F5_RSCANCCS			BIT18	//0/0/x/x No Command Completed Support
    #define D0F5_RSCAEMIP			BIT17	//0/0/x/x Electromechanical Interlock Present
    #define D0F5_RSPLS			(BIT15 + BIT16)	//00b/0/x/x Slot Power Limit Scale
    #define D0F5_RSPLV			0x7F80	//0/0/x/x Slot Power Limit Value
    #define D0F5_SCHP_CAP			BIT6	//0/0/x/x Hot-Plug Capable
    #define D0F5_SCHPS			BIT5	//1b/1/x/x Hot-Plug Surprise
    #define D0F5_SCPIP			BIT4	//0/0/x/x Power Indicator Present
    #define D0F5_SCAIP			BIT3	//0/0/x/x Attention Indicator Present
    #define D0F5_RSV_36			BIT2	//0/0/x/x MRL Sensor Present
    #define D0F5_RSV_37			BIT1	//0/0/x/x Power Controller Present
    #define D0F5_SCABP			BIT0	//0/0/x/x Attention Button Present
#define D0F5_SLOT_CTL_1		0x58	//Slot Control 1
    #define D0F5_RSV_39			(BIT13 + BIT14 + BIT15)	//0/R/x/x Reserved
    #define D0F5_RDLSCHGEN			BIT12	//0/0/x/x Enable Data Link Layer State Change
    #define D0F5_RSCOEMIC			BIT11	//0/0/x/x Electromechanical Interlock Control
    #define D0F5_SCPCC			BIT10	//0/0/x/x Power Controller Control
    #define D0F5_SCPIC			(BIT8 + BIT9)	//00b/0/x/x Power Indicator Control
    #define D0F5_SCAIC			(BIT6 + BIT7)	//00b/0/x/x Attention Indicator Control
    #define D0F5_SCHPIE			BIT5	//0/0/x/x Enable Hot-Plug Interrupt
    #define D0F5_SCCCIE			BIT4	//0/0/x/x Enable Command Completed Interrupt 
    #define D0F5_SCPDCE			BIT3	//0/0/x/x Enable Presence Detect Change
    #define D0F5_RSV_40			BIT2	//0/0/x/x Enable MRL Sensor Change
    #define D0F5_RSV_41			BIT1	//0/0/x/x Enable Power Fault Detected
    #define D0F5_SCABPE			BIT0	//0/0/x/x Enable Attention Button Pressed
#define D0F5_SLOT_STA_1		0x5A	//Slot Status 1
    #define D0F5_RSV_42			0xFE00	//0/R/x/x Reserved
    #define D0F5_RDLSCHG			BIT8	//0/0/x/x Data Link Layer State Changed
    #define D0F5_RSSEMIS			BIT7	//0/0/x/x Electromechanical Interlock Status
    #define D0F5_SPDCST			BIT6	//0/0/x/x Presence Detect State
    #define D0F5_RSV_43			BIT5	//0/0/x/x MRL (Manually Operated Retention Latch) Sensor State
    #define D0F5_SSCC			BIT4	//0/0/x/x Command Completed
    #define D0F5_SPDC			BIT3	//0/0/x/x Presence Detect Change
    #define D0F5_TBD_29			BIT2	//0/0/x/x MRL Sensor Change
    #define D0F5_TBD_30			BIT1	//0/0/x/x Power Fault Detected
    #define D0F5_SSABP			BIT0	//0/0/x/x Attention Button Pressed
#define D0F5_ROOT_CTL		0x5C	//Root Control
    #define D0F5_RSV_5C_5			0xFFE0	//0/R/x/x Reserved
    #define D0F5_RCCRSSVE			BIT4	//0/0/x/x Enable CRS Software Visibility 
    #define D0F5_RCPMEIE			BIT3	//0/0/x/x Enable PME Interrupt
    #define D0F5_RCSEFEE			BIT2	//0/0/x/x Enable System Error on Fatal Error
    #define D0F5_RCSENFEE			BIT1	//0/0/x/x Enable System Error on Non-Fatal Error
    #define D0F5_RCSECEE			BIT0	//0/0/x/x Enable System Error on Correctable Error
#define D0F5_ROOT_CAPS		0x5E	//Root Capabilities
    #define D0F5_RSV_44_5E			0xFFFE	//0/R/x/x Reserved
    #define D0F5_RSCRSSFV			BIT0	//0/0/x/x Configuration Request Retry Status (CRS) Software Visibility
#define D0F5_ROOT_STA		0x60	//Root Status
    #define D0F5_RSV_45			0xFFFC0000	//0/R/x/x Reserved
    #define D0F5_RSPP			BIT17	//0/0/x/x PME Pending
    #define D0F5_RSPS			BIT16	//0/0/x/x PME Status
    #define D0F5_RSPRID			0xFFFF	//0/0/x/x PME Requester ID
#define D0F5_DEV_CAPS_2		0x64	//Device Capabilities 2
    #define D0F5_RSV_64_6			0xFFF00000	//0/R/x/x Reserved
    #define D0F5_ROBFFSP			(BIT18 + BIT19)	//0/0/x/x OBFF Supported
    #define D0F5_RSV_64_12			0x3F000	//0/R/x/x Reserved
    #define D0F5_RLTRSP			BIT11	//0/0/x/x LTR Mechanism Supported
    #define D0F5_RSV_64_10			0x7C0	//0/x/x/x Reserved
    #define D0F5_RARISP			BIT5	//0/0/x/x Alternative Routing-ID Interpretation (ARI) Forwarding Supported
    #define D0F5_TBD_31			BIT4	//1b/1/x/x Completion Timeout Disable Supported
    #define D0F5_TBD_32			0xF	//0/0/x/x Completion Timeout Ranges Supported
#define D0F5_DEV_CTL_2		0x68	//Device Control 2
    #define D0F5_RSV_46			BIT15	//0/R/x/x Reserved
    #define D0F5_ROBFFEN			(BIT13 + BIT14)	//0/0/x/x OBFF Enable
    #define D0F5_RSV_68_11			(BIT11 + BIT12)	//0/R/x/x Reserved
    #define D0F5_RLTREN			BIT10	//0/0/x/x LTR Mechanism Enable
    #define D0F5_RSV_68_6			0x3C0	//0/R/x/x Reserved
    #define D0F5_RARIEN			BIT5	//0/0/x/x Enable ARI Forwarding
    #define D0F5_RDISCPLTM			BIT4	//0/0/0/x Completion Timeout  Disable Control
    #define D0F5_TBD_33			0xF	//0/0/x/x Completion Timeout Value
#define D0F5_DEV_STA_2		0x6A	//Device Status 2
    #define D0F5_RSV_47			0xFFFF	//0/R/x/x Reserved
#define D0F5_LINK_CAPS_2		0x6C	//Link Capabilities 2
    #define D0F5_RSV_6C_31			0xFFF80000	//0/R/x/x Reserved
    #define D0F5_RLOW_SKP_REC_SUPPORT_2			BIT18	//0/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F5_RLOW_SKP_REC_SUPPORT_1			BIT17	//0/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F5_RLOW_SKP_REC_SUPPORT_0			BIT16	//1b/x/x/X Lower SKP OS Reception Supported Speeds Vector
    #define D0F5_RSV_6C_15			0xF000	//0/R/x/x Reserved
    #define D0F5_RLOW_SKP_GEN_SUPPORT_2			BIT11	//0/x/x/x Lower SKP OS Generation Supported Speeds Vector
    #define D0F5_RLOW_SKP_GEN_SUPPORT_1			BIT10	//0/x/x/X Lower SKP OS Generation Supported Speeds Vector
    #define D0F5_RLOW_SKP_GEN_SUPPORT_0			BIT9	//1b/x/x/X Lower SKP OS Generation Supported Speeds Vector
    #define D0F5_RSV_6C_8			BIT8	//0/0/x/x CrossLink Supported
    #define D0F5_LKMLS_6			BIT7	//0/0/x/x Supported Link Speed Vector Bit 6
    #define D0F5_LKMLS_5			BIT6	//0/0/x/x Supported Link Speed Vector Bit 5
    #define D0F5_LKMLS_4			BIT5	//0/0/x/x Supported Link Speed Vector Bit 4
    #define D0F5_LKMLS_3			BIT4	//0/0/x/x Supported Link Speed Vector Bit 3
    #define D0F5_LKMLS_2			BIT3	//0/0/x/x Supported Link Speed Vector Bit 2, 8.0GT/s
    #define D0F5_LKMLS_1			BIT2	//0/0b/x/x Supported Link Speed Vector Bit 1, 5.0GT/s
    #define D0F5_LKMLS_0			BIT1	//1b/1b/x/x Supported Link Speed Vector Bit 0, 2.5 GT/s
    #define D0F5_RSV_6C_0			BIT0	//0/R/x/x Reserved
#define D0F5_LINK_CTL_2		0x70	//Link Control 2
    #define D0F5_CMPPSDEEMPHS			0xF000	//0/0/x/x Compliance Preset / De-emphasis
    #define D0F5_RCMPSOS			BIT11	//0/0/x/x SKP Ordered Set (SOS) Transmission between Compliance Patterns
    #define D0F5_PMDCMPSET			BIT10	//0/0/x/x Modified Compliance Pattern Set Bit
    #define D0F5_TXMGN_2			BIT9	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F5_TXMGN_1			BIT8	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F5_TXMGN_0			BIT7	//0/0/x/x Transmit Voltage Margin Setting
    #define D0F5_SELDEEMPHS			BIT6	//0/0/x/x Selectable De-emphasis
    #define D0F5_RHATNMSD			BIT5	//0/0/x/0 Disable Hardware Autonomous Speed
    #define D0F5_PCMPSET			BIT4	//0/0/x/x Enter Compliance
    #define D0F5_LKTGLS_3			BIT3	//0/0/0/0 Target Link Speed Bit 3
    #define D0F5_LKTGLS_2			BIT2	//0/0/0/0 Target Link Speed Bit 2
    #define D0F5_LKTGLS_1			BIT1	//0/0/0/0 Target Link Speed Bit 1
    #define D0F5_LKTGLS_0			BIT0	//0/0/0/0 Target Link Speed Bit 0
#define D0F5_LINK_STA_2		0x72	//Link Status 2
    #define D0F5_RSV_49			0xFFC0	//0/R/x/x Reserved
    #define D0F5_EQREQ			BIT5	//0/x/x/x Request the Link Equalization Process
    #define D0F5_EQCOMPLE3			BIT4	//0/x/x/x Transmitter Equalization Procedure Completed -Phase 3
    #define D0F5_EQCOMPLE2			BIT3	//0/x/x/x Transmitter Equalization Procedure Completed -Phase 2
    #define D0F5_EQCOMPLE1			BIT2	//0/x/x/x Transmitter Equalization Procedure Completed -Phase 1
    #define D0F5_EQCOMPLE			BIT1	//0/x/x/x Transmitter Equalization Procedure Completed
    #define D0F5_CURDEEMPHS			BIT0	//0/x/x/x Current Link De-emphasis Level
#define D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_UPSIDE_NEAR_CPUIF_1		0x80	//Traffic Flow Control - Upstream Control (Upside Near CPUIF) 1
    #define D0F5_RAHCI_CONV_BYPASS			BIT7	//0/0/0/0 AHCI CDC Bypass 
    #define D0F5_RTPQSTPCLK			BIT6	//0/0/x/x Reserved
    #define D0F5_RMSIFLSH			BIT5	//1b/1/1/1 Upstream MSI Cycles Flush of the Queued PCIe Non-snoop Upstream Write Cycle
    #define D0F5_RTLRD_PIPE			BIT4	//0/0/0/0 Upstream Read Data Pipe in the Interface with CPUIF
    #define D0F5_RTPQ1T			BIT3	//0/0/1/x Upstream Request 1T Earlier
    #define D0F5_RISOHP			BIT2	//1b/1/x/x Enable Upstream ISO Cycle High Priority
    #define D0F5_RUPRRDY1			BIT1	//1b/1/1/x Upstream Read Data Returning Path
    #define D0F5_RTUPMSIDEC			BIT0	//1b/1/x/x Upstream MSI Address FEEx_xxxxh Decoding
#define D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_UPSIDE_NEAR_CPUIF_2		0x81	//Traffic Flow Control - Upstream Control (Upside Near CPUIF) 2
    #define D0F5_RAPICX			BIT7	//0/0/0/x Reserved
    #define D0F5_RMSIFLHUPW_GFX			BIT6	//1b/1/1/x GFX MSI Flush Upstream Write
    #define D0F5_RP2P4QW			BIT5	//1b/1/1/x Peer-to-peer 4QW Write Cycle Support
    #define D0F5_RP2P8QW			BIT4	//1b/1/1/x Peer-to-peer 8QW Access Capability
    #define D0F5_RINTFLHUPW_GFX			BIT3	//1b/1/1/x GFX Interrupt Flush Upstream Write
    #define D0F5_RPERPSH1T			BIT2	//0/0/1/x Reducing 1T Latency for PCIe Upstream Read RPSH
    #define D0F5_RMIDQBYPASS			BIT1	//0/0/1/x Bypass MIDQ when IOV Is Disabled
    #define D0F5_RP2PRNTRIGAGPBZ			BIT0	//0/0/x/x Peer-to-peer Read Cycle to Trigger AGPBUSY
#define D0F5_UPSTREAM_MIDQ_DYNAMIC_CLK_CTL		0x82	//Upstream MIDQ Dynamic Clock Control
    #define D0F5_RAHMIDQDYN			BIT7	//0/0/1/1 AHCI MIDQ Dynamic Clock Enable
    #define D0F5_RATMIDQDYN			BIT6	//0/0/1/1 APIC MIDQ Dynamic Clock Enable
    #define D0F5_RGFXMIDQDYN			BIT5	//0/0/1/1 GFX MIDQ Dynamic Clock Enable
    #define D0F5_RPCT0MIDQDYN			BIT4	//0/0/1/1 PCCA MIDQ Dynamic Clock Enable
    #define D0F5_RPCIEMIDQDYN			BIT3	//0/0/1/1 PCIe MIDQ Dynamic Clock Enable
    #define D0F5_RPEMCUMIDQDYN			BIT2	//0/0/1/1 PEMCU MIDQ Dynamic Clock Enable
    #define D0F5_RRAIDMIDQDYN			BIT1	//0/x/x/x Reserved
    #define D0F5_RXHMIDQDYN			BIT0	//0/0/1/1 xHCI MIDQ Dynamic Clock Enable
#define D0F5_TA_HIGH_PRIORITY_SET		0x83	//TA High Priority Set
    #define D0F5_RX80_31_27			0xF8	//0/x/x/x Reserved
    #define D0F5_RPEXTQUECLKSEL			BIT2	//0/0/1/1 PEXTWQUE or PEXTRQUE CLK Selection
    #define D0F5_RMSIDTRKCLKSEL			BIT1	//0/0/1/1 MSI Data Tracking Module Dynamic Clock Enable
    #define D0F5_RTARHP			BIT0	//1b/1/x/x TA High Priority Set
#define D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_SM_1		0x84	//Traffic Flow Control - Upstream Control (Downside Near SM) 1
    #define D0F5_RP2P1ABORT			BIT7	//1b/1/x/x Abortion of Peer-to-peer Cycles Issued to South Module
    #define D0F5_RPCT0SH			BIT6	//1b/1/1/x High Priority to SM Request
    #define D0F5_RHMCUSPRI			BIT5	//0/0/x/x MCU Upstream Request High Priority
    #define D0F5_RPCT0RDMAHP			BIT4	//1b/1b/x/x PCCA Read DMA Cycle Has Higher Priority than Write Cycle
    #define D0F5_REBMCBLOCK			BIT3	//1b/*1b/x/x Blocking XHCIMCU DMA Cycles
    #define D0F5_D0F5_RX84B2			BIT2	//0/*0/x/x Lock_bit for XHCIMCU BLOCK
    #define D0F5_RTLWC_PIPE			BIT1	//1b/1/1/1 Upstream Write Completion Pipe
    #define D0F5_RMCUTRFDVADBYPASS			BIT0	//0/0/x/x Reserved
#define D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_SM_2		0x85	//Traffic Flow Control - Upstream Control (Downside Near SM) 2
    #define D0F5_RAHUSSH			BIT7	//1b/1/1/x High Priority from AHCI to SM Request
    #define D0F5_RXHUSSH			BIT6	//1b/1/1/x High Priority from xHCI to SM Request
    #define D0F5_RTLWCTRDY_ABT			BIT5	//1b/1/x/x Abort TLWCTRDY by Upstream Write Abort Cycle
    #define D0F5_RUP_ABT_BLK_EN			BIT4	//0/0/x/x Abort TPQPush by Upstream Abort Cycle
    #define D0F5_RVPISH			BIT3	//1b/1/1/x High Priority from VPI to SM Request
    #define D0F5_RX85_2			BIT2	//0/x/x/x Reserved
    #define D0F5_RX85_1			BIT1	//0/x/x/x Reserved
    #define D0F5_RX85_0			BIT0	//0/x/x/x Reserved
#define D0F5_TRAFFIC_FLOW_CTL_UPSTREAM_CTL_DOWNSIDE_NEAR_GFX		0x86	//Traffic Flow Control - Upstream Control (Downside Near GFX)
    #define D0F5_RX86_7			BIT7	//0/x/x/x Reserved
    #define D0F5_RX86_6			BIT6	//0/x/x/x Reserved
    #define D0F5_RUSREQH			BIT5	//0/0/x/x Strict Priority to GFXCTL Upstream Request Strobe (USREQ) from Internal GFXCTL (IGFX)
    #define D0F5_RX86_4			BIT4	//0/x/x/x Reserved
    #define D0F5_RDFSBFLP2			BIT3	//1b/1/1/1 Reserved
    #define D0F5_RX86_2			BIT2	//0/x/x/x DeviceID/RevisionID Lock Bit
    #define D0F5_RUSBYPASS			BIT1	//0/0/1/x Add 1T Latency for Upstream Request from GFXCTL
    #define D0F5_RUS2QWMERGE			BIT0	//0/0/1/x Merge for Upstream Write Requests from GFXCTL
#define D0F5_DEV_READ_REQ_QUEUE_READ_REQ_DELAY_1T_FROM_WRITE_REQ		0x87	//Device Read Request Queue, Read Request Delay 1T from Write Request
    #define D0F5_RX87_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F5_RPEV0RQBYPASS			BIT5	//0/0/x/x RADS and Address Bypass RQ for PCIe Path
    #define D0F5_RAHCIRQBYPASS			BIT4	//0/0/x/x RADS and Address Bypass RQ for RAIDA1
    #define D0F5_RXHCIRQBYPASS			BIT3	//0/0/x/x RADS and Address Bypass RQ for VPI
    #define D0F5_RPCT0RQBYPASS			BIT2	//0/0/x/x RADS and Address Bypass RQ for PCCA
    #define D0F5_RRAIDRQBYPASS			BIT1	//0/0/x/x RADS and Address Bypass RQ for RAIDA0
    #define D0F5_RPEMCURQBYPASS			BIT0	//0/0/x/x RADS and Address Bypass RQ for PEMCU
#define D0F5_TRAFFIC_FLOW_CTL_DOWNSTREAM_CTL_DOWNSIDE_NEAR_PCIE		0x88	//Traffic Flow Control - Downstream Control (Downside Near PCIe)
    #define D0F5_RX88_7			BIT7	//0/x/x/x Reserved
    #define D0F5_RPEV1RDY1TE			BIT6	//0/0/1/x Reserved
    #define D0F5_RX88_5			BIT5	//0/x/x/x Reserved
    #define D0F5_RPCRNFLHPPR			BIT4	//1b/1/1/x Ordering Rule for Upstream Read from PCIe
    #define D0F5_RPEQ1T			BIT3	//0/0/1/x Reducing 1T Latency for PCIe Upstream Requests
    #define D0F5_RPXPPLL1OFF			BIT2	//1b/1/x/x Blocking Upstream PCIe Cycles
    #define D0F5_RADNCF8			BIT1	//1b/1/x/x Generate the CF8 Cycle before Normal CFC Cycle when the Normal CFG Cycle Is Interrupted by MMIO CFG Cycle
    #define D0F5_RX88_0			BIT0	//0/x/x/x Reserved
#define D0F5_FUN_ISSUE		0x89	//Function Issue
    #define D0F5_RX89_7_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F5_RPXPMSI_FLUSH_P2CW_EN			BIT4	//0/x/x/x PXPTRF MSI Flush P2CW
    #define D0F5_RGFXMSI_FLUSH_P2CW_EN			BIT3	//0/x/x/x PXPTRF MSI Flush P2CW
    #define D0F5_UPRRDYQFULL_EN			BIT2	//0/0/0/0 UPRRDYQFull Enable
    #define D0F5_UPWRDYQFULL_EN			BIT1	//1b/1/1/1 UPWRDYQFull Enable
    #define D0F5_PIPE_WRDYQ_FULL_EN			BIT0	//0/0/0/0 PIPE_WRDYQ_Full Enable
#define D0F5_RESERVED_Z3		0x8A	//Reserved
    #define D0F5_RX8A_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_NO_SNOOP_PATH_ARBITRATION_TIMER_XHMCU_AND_AZMCU		0x8B	//No Snoop Path Arbitration Timer (XHMCU and AZMCU)
    #define D0F5_RXHMCUTM_3_0			0xF0	//0100b/100/x/x XHMCU Request Path Occupy Timer
    #define D0F5_RAZMCUTM_3_0			0xF	//0100b/100/x/x AZMCU Request Path Occupy Timer
#define D0F5_SEL_OF_ISO_AND_PRIORITY_IMPLEMENTATION_PCCA_AND_PCIE		0x8C	//Selection of ISO and Priority Implementation (PCCA and PCIe)
    #define D0F5_RPCT0RISOSEL			BIT7	//1b/1/x/x PCT0 Read ISO Selection
    #define D0F5_RPCT0RPRISEL			BIT6	//0/0/x/x PCT0 Read HP Selection
    #define D0F5_RPCT0WISOSEL			BIT5	//1b/1/x/x PCT0 Write ISO Selection
    #define D0F5_RPCT0WPRISEL			BIT4	//0/0/x/x PCT0 Write HP Selection
    #define D0F5_RPEV0RISOSEL			BIT3	//1b/1/x/x PEV0 Read ISO Selection
    #define D0F5_RPEV0RPRISEL			BIT2	//0/0/x/x PEV0 Read HP Selection
    #define D0F5_RPEV0WISOSEL			BIT1	//1b/1/x/x PEV0 Write ISO Selection
    #define D0F5_RPEV0WPRISEL			BIT0	//0/0/x/x PEV0 Write HP Selection
#define D0F5_SEL_OF_ISO_AND_PRIORITY_IMPLEMENTATION_RAID1_AND_VPI		0x8D	//Selection of ISO and Priority Implementation (RAID1 and VPI)
    #define D0F5_RAHCIRISOSEL			BIT7	//1b/1/x/x RAID1 Read ISO Selection
    #define D0F5_RAHCIRPRISEL			BIT6	//0/0/x/x RAID1 Read HP Selection
    #define D0F5_RAHCIWISOSEL			BIT5	//1b/1/x/x RAID1 Write ISO Selection
    #define D0F5_RAHCIWPRISEL			BIT4	//0/0/x/x RAID1 Write HP Selection
    #define D0F5_RXHCIRISOSEL			BIT3	//1b/1/x/x VPI Read ISO Selection
    #define D0F5_RXHCIRPRISEL			BIT2	//0/0/x/x VPI Read HP Selection
    #define D0F5_RVPIWISOSEL			BIT1	//1b/1/x/x VPI Write ISO Selection
    #define D0F5_RVPIWPRISEL			BIT0	//0/0/x/x VPI Write HP Selection
#define D0F5_SEL_OF_ISO_AND_PRIORITY_IMPLEMENTATION_PEMCU_AND_RAID		0x8E	//Selection of ISO and Priority Implementation (PEMCU and RAID)
    #define D0F5_RPEMCURISOSEL			BIT7	//1b/1/x/x PEMCU Read ISO Selection
    #define D0F5_RPEMCURPRISEL			BIT6	//0/0/x/x PEMCU Read HP Selection
    #define D0F5_RPEMCUWISOSEL			BIT5	//1b/1/x/x PEMCU Write ISO Selection
    #define D0F5_RPEMCUWPRISEL			BIT4	//0/0/x/x PEMCU Write HP Selection
    #define D0F5_RRAIDRISOSEL			BIT3	//1b/1/x/x RAID Read ISO Selection
    #define D0F5_RRAIDRPRISEL			BIT2	//0/0/x/x RAID Read HP Selection
    #define D0F5_RRAIDWISOSEL			BIT1	//1b/1/x/x RAID Write ISO Selection
    #define D0F5_RRAIDWPRISEL			BIT0	//0/0/x/x RAID Write HP Selection
#define D0F5_RESERVED_SBDBGC_DEBUG_MODE_SEL		0x8F	//Reserved ((SBDBGC Debug Mode Selection))
    #define D0F5_RPCCAOUTARB_1_0			(BIT6 + BIT7)	//00b/0/x/x Reserved
    #define D0F5_RXHOUTARB_1_0			(BIT4 + BIT5)	//00b/0/x/x Reserved
    #define D0F5_RAHOUTARB_1_0			(BIT2 + BIT3)	//00b/0/x/x Reserved
    #define D0F5_RXHSAMPSEL			BIT1	//0/0/x/x Reserved
    #define D0F5_RAHSAMPSEL			BIT0	//0/0/x/x Reserved
#define D0F5_XHCI_UPSTREAM_ARBITRATION_TIMER_UFXH		0x90	//xHCI Upstream Arbitration Timer ((UFXH))
    #define D0F5_UFXHOCTM_3_0			0xF0	//0100b/100/x/x xHCI Upstream Arbitration Occupy Timer
    #define D0F5_UFXHPMTM_3_0			0xF	//0100b/100/x/x xHCI Upstream Arbitration Promote Timer
#define D0F5_GFXCTL_UPSTREAM_ARBITRATION_TIMER_UFEUMA		0x91	//GFXCTL Upstream Arbitration Timer ((UFEUMA))
    #define D0F5_UFEUMAOCTM_3_0			0xF0	//0100b/100/x/x GFX Upstream Request Path Occupy Timer
    #define D0F5_UFEUMAPMTM_3_0			0xF	//0010b/10/x/x GFX Upstream Request Path Promote Timer
#define D0F5_SB_UPSTREAM_ARBITRATION_TIMER_UFPSB		0x92	//SB Upstream Arbitration Timer ((UFPSB))
    #define D0F5_UFPSBOCTM_3_0			0xF0	//0100b/100/x/x SM Request Path Occupy Timer
    #define D0F5_UFPSBPMTM_3_0			0xF	//0100b/100/x/x SM Request Path Promote Timer
#define D0F5_PCIE_VC0_PATH_ARBITRATION_TIMER_UPPE0		0x93	//PCIe VC0 Path Arbitration Timer ((UPPE0))
    #define D0F5_UFPEV0OCTM_3_0			0xF0	//0100b/100/x/x PCIe VC0 Request Path Occupy Timer
    #define D0F5_UFPEV0PMTM_3_0			0xF	//0100b/100/x/x PCIe VC0 Request Path Promote Timer
#define D0F5_SM_PATH_ARBITRATION_TIMER_UFPCT0		0x94	//SM Path Arbitration Timer ((UFPCT0))
    #define D0F5_UFPCT0OCTM_3_0			0xF0	//0100b/100/x/x PCT0 Request Path Occupy Timer
    #define D0F5_UFPCT0PMTM_3_0			0xF	//0100b/100/x/x PCT0 Request Path Promote Timer
#define D0F5_IO_APIC_PATH_ARBITRATION_TIMER_UFAP		0x95	//IO APIC Path Arbitration Timer ((UFAP))
    #define D0F5_UFAPOCTM_3_0			0xF0	//0100b/0100b/x/x IO APIC Occupancy Timer (in Unit of Host Frequency)
    #define D0F5_UFAPPMTM_3_0			0xF	//0/x/x/x IO APIC Promote Timer (in Unit of Host Frequency)
#define D0F5_IPI_PATH_ARBITRATION_TIMER_UFIPI		0x96	//IPI Path Arbitration Timer ((UFIPI))
    #define D0F5_UFIPIOCTM_3_0			0xF0	//0/x/x/x IPI Occupancy Timer (in Unit of Host Frequency)
    #define D0F5_UFIPIPMTM_3_0			0xF	//0/x/x/x IPI Promote Timer (in Unit of Host Frequency)
#define D0F5_REMAPPING_PRE_FETCH_CTL		0x97	//Remapping Pre-fetch Control
    #define D0F5_RPXPPREFC			BIT7	//0/0/x/x Traffic Pre-fetch Enable
    #define D0F5_RPXPPREFCCNT_1_0			(BIT5 + BIT6)	//00b/0/x/x Traffic Pre-fetch Occupy Select
    #define D0F5_RPXPPREFCEND_1_0			(BIT3 + BIT4)	//00b/0/x/x Traffic Pre-fetch Address Range Select
    #define D0F5_RX97_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x Reserved
#define D0F5_GFX_P2P_PATH_ARBITRATION_TIMER		0x98	//GFX P2P Path Arbitration Timer
    #define D0F5_PPUSOCTM_3_0			0xF0	//0100b/100/x/x GFX P2P Arbitration Occupancy Timer (in Unit of HCLK)
    #define D0F5_PPUSPMTM_3_0			0xF	//0100b/100/x/x GFX P2P Arbitration Promote Timer (in Unit of HCLK)
#define D0F5_ARBITER_DISABLE_OCCUPY_TIMER		0x99	//Arbiter Disable Occupy Timer
    #define D0F5_RX99_7_4			0xF0	//0/0/x/x Reserved
    #define D0F5_RARBDIS_TIM_3_0			0xF	//1100b/1100/1100/1100 Reserved
#define D0F5_RESERVED_OCCUPANCY_TIMER_FOR_CMD_BANDWIDTH_TO_VD		0x9A	//Reserved ((Occupancy Timer for Command Bandwidth to VD))
    #define D0F5_RVDOCTM_3_0			0xF0	//0/0/x/x Reserved
    #define D0F5_RCBOCTM_3_0			0xF	//0/0/x/x Reserved
#define D0F5_RESERVED_PRIORITY_PROMOTION_TIMER_FOR_CMD_TO_VD		0x9B	//Reserved ((Priority Promotion Timer for Command to VD))
    #define D0F5_RVDPMTM_3_0			0xF0	//0/0/x/x Reserved
    #define D0F5_RCBPMTM_3_0			0xF	//0/0/x/x Reserved
#define D0F5_AHCI_UPSTREAM_ARBITRATION_TIMER_UFAH		0x9C	//AHCI Upstream Arbitration Timer ((UFAH))
    #define D0F5_UFAHOCTM_3_0			0xF0	//0100b/100/x/x AHCI Upstream Arbitration Occupy Timer
    #define D0F5_UFAHPMTM_3_0			0xF	//0100b/100/x/x AHCI Upstream Arbitration Promote Timer
#define D0F5_TACTL_UPSTREAM_ARBITRATION_TIMER_UFTA		0x9D	//TACTL Upstream Arbitration Timer ((UFTA))
    #define D0F5_UFTAOCTM_3_0			0xF0	//0100b/100/x/x TACTL Upstream Arbitration Occupy Timer
    #define D0F5_UFTAPMTM_3_0			0xF	//0100b/100/x/x TACTL Upstream Arbitration Promote Timer
#define D0F5_SM_PATH_ARBITRATION_TIMER_PEMCU		0x9E	//SM Path Arbitration Timer (PEMCU)
    #define D0F5_UFPEMCUCTM_3_0			0xF0	//0100b/100/x/x PEMCU Request Path Occupy Timer
    #define D0F5_UFPEMCUPMTM_3_0			0xF	//0100b/100/x/x PEMCU Request Path Promote Timer
#define D0F5_SM_PATH_ARBITRATION_TIMER_RAIDA		0x9F	//SM Path Arbitration Timer (RAIDA)
    #define D0F5_UFRAIDCTM_3_0			0xF0	//0100b/100/x/x RAIDA Request Path Occupy Timer
    #define D0F5_UFRAIDPMTM_3_0			0xF	//0100b/100/x/x PEMCU Request Path Promote Timer
#define D0F5_PCIE_PMU_STA_1		0xA0	//PCIe PMU Status 1
    #define D0F5_RSCI1EN			BIT7	//1b/1/x/x PCI Express PME SCI (System Control Interrupt to Indicate Power Management Event) Activation Control
    #define D0F5_RSCI2EN			BIT6	//1b/1/x/x PCI Express Hot-Plug SCI (System Control Interrupt to Indicate Hot-Plug Event) Activation Control
    #define D0F5_RPMEACK_PEG0			BIT5	//0/0/x/x PME_TO_ACK Acknowledge Status for RP4
    #define D0F5_RPMEACK_PEG1			BIT4	//0/0/x/x PME_TO_ACK Acknowledge Status for RP5
    #define D0F5_RPMEACK_PE3			BIT3	//0/0/x/x PME_TO_ACK Acknowledge Status for RP3
    #define D0F5_RPMEACK_PE2			BIT2	//0/0/x/x PME_TO_ACK Acknowledge Status for RP2
    #define D0F5_RPMEACK_PE1			BIT1	//0/0/x/x PME_TO_ACK Acknowledge Status for RP1
    #define D0F5_RPMEACK_PE0			BIT0	//0/0/x/x PME_TO_ACK Acknowledge Status for RP0
#define D0F5_PCIE_PMU_STA_2		0xA1	//PCIe PMU Status 2
    #define D0F5_RPM_PME			BIT7	//HwInit/x/x/x PM_PME Message Status
    #define D0F5_D0F5_RXA0_14			BIT6	//0/x/x/x Reserved
    #define D0F5_RHP_SCI2			BIT5	//HwInit/x/x/x Hot Plug Event Status
    #define D0F5_RXA0_4			BIT4	//0/x/x/x Reserved
    #define D0F5_RXA0_3			BIT3	//0/x/x/x Reserved
    #define D0F5_RPMEACK_PEG3			BIT2	//0/0/x/x PME_TO_ACK Acknowledge Status for RP7
    #define D0F5_RPMEACK_PEG2			BIT1	//0/0/x/x PME_TO_ACK Acknowledge Status for RP6
    #define D0F5_RPMEACK_PEG			BIT0	//0/x/x/x Reserved 
#define D0F5_ACPI_IO_BASE_ADR_BIT_15_8		0xA2	//ACPI IO Base Address - Bit[15:8]
    #define D0F5_RIOWS345A_15_8			0xFF	//00h/x/x/x ACPI IO Base Address - Bits [15:8]
#define D0F5_STPGNT_CYCLE_CTL		0xA3	//STPGNT Cycle Control
    #define D0F5_RIOWS345A_7			BIT7	//0/0/x/x ACPI IO Base Address - Bit [7]
    #define D0F5_RXA0_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define D0F5_RMSCMD_2_0			(BIT1 + BIT2 + BIT3)	//0/*000/x/x Number of STPGNT Cycles for Assertion of SLP#
    #define D0F5_RSTPGHLD			BIT0	//0b/0/x/x Holding STPGNT for Entering Sleeping Mode
#define D0F5_PMU_CTL		0xF0	//PMU Control
    #define D0F5_RPMETOFF			BIT7	//0/0/x/x Triggering Sending PME_TURN_OFF Messages
    #define D0F5_RXF0_D0F5_6_3			0x78	//0/x/x/x Reserved
    #define D0F5_D0F5_RXF0B2			BIT2	//0/x/x/x Control whether the VID Register Is Writable in TXT Configuration Register
    #define D0F5_RXF0_D0F5_1			BIT1	//0/x/x/x Reserved
    #define D0F5_RPEROWEN			BIT0	//0/0/x/x Reserved
#define D0F5_FIX_DESIGN_ISSUE		0xF1	//Fix Design Issue
    #define D0F5_RXF17			BIT7	//1b/1/1/1 New TLID Decode
    #define D0F5_RXF16			BIT6	//0/0/0/0 Block P2P Cycle
    #define D0F5_RXF15			BIT5	//0/0/0/0 Shadow Write Block Next Configure Cycle
    #define D0F5_RXF14			BIT4	//0/0/0/0 Ignore GFX ACK for STPGNT
    #define D0F5_RMMCFG_RTRDY_DOWN_NEW			BIT3	//0/0/0/0 MMCFGCTL RTRDY_DOWN Control
    #define D0F5_RMMCFG_RTRDY_DOWN_REG_NEW			BIT2	//0/0/0/0 MMCFGCTL RTRDY_DOWN_reg Control
    #define D0F5_RMMCFG_WIRDY_DOWN_NEW			BIT1	//0/0/0/0 MMCFGCTL WIRDY_DOWN Control
    #define D0F5_RMMCFG_WIRDY_DOWN_REG_NEW			BIT0	//0/0/0/0 MMCFGCTL WIRDY_DOWN_reg Control
#define D0F5_PCIE_DEVS_REG_SPACE		0xF2	//PCIe Devices Register Space
    #define D0F5_RXF2_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_REQ_CNTER_FOR_UPSTREAM_CYCLE		0xF3	//Request Counter for Upstream Cycle
    #define D0F5_RXF3_7_1			0xFE	//0/x/x/x Reserved
    #define D0F5_RUPREQCNT			BIT0	//1b/1/x/x Request Counter for Upstream Cycle
#define D0F5_DEV_EXIST_REG_SPACE		0xF4	//Device Exist Register Space
    #define D0F5_RXF4_31_7			0xFFF00000	//0/x/x/x Reserved
    #define D0F5_RDV5F1CYCABT			BIT19	//1b/1/x/x To Device 5 Function 1 Cycle Aborts or Not (Port 7)
    #define D0F5_RDV5F0CYCABT			BIT18	//1b/1/x/x To Device 5 Function 0 Cycle Aborts or Not (Port 6)
    #define D0F5_RDV4F1CYCABT			BIT17	//1b/1/x/x To Device 4 Function 1 Cycle Aborts or Not (Port 5)
    #define D0F5_RDV4F0CYCABT			BIT16	//1b/1/x/x To Device 4 Function 0 Cycle Aborts or Not (Port 4)
    #define D0F5_RDV3F3CYCABT			BIT15	//1b/1/x/x To Device 3 Function 3 Cycle Aborts or Not (Port 3)
    #define D0F5_RDV3F2CYCABT			BIT14	//1b/1/x/x To Device 3 Function 2 Cycle Aborts or Not (Port 2)
    #define D0F5_RDV3F1CYCABT			BIT13	//1b/1/x/x To Device 3 Function 1 Cycle Aborts or Not (Port 1)
    #define D0F5_RDV3F0CYCABT			BIT12	//1b/1/x/x To Device 3 Function 0 Cycle Aborts or Not (Port 0)
    #define D0F5_RDV2F0CYCABT			BIT11	//0/0/0/0 To Device 2 Function 0 Cycle Aborts or Not (Port G)
    #define D0F5_RDV5F1EXST			BIT10	//HwInit/x/x/x Existence of PCI D5F1 (Port 7)
    #define D0F5_RDV5F0EXST			BIT9	//HwInit/x/x/x Existence of PCI D5F0 (Port 6)
    #define D0F5_RDV4F1EXST			BIT8	//HwInit/x/x/x Existence of PCI D4F1 (Port 5)
    #define D0F5_RDV4F0EXST			BIT7	//HwInit/x/x/x Existence of PCI D4F0 (Port 4)
    #define D0F5_RDV3F3EXST			BIT6	//HwInit/x/x/x Existence of PCI D3F3 (Port 3)
    #define D0F5_RDV3F2EXST			BIT5	//HwInit/x/x/x Existence of PCI D3F2 (Port 2)
    #define D0F5_RDV3F1EXST			BIT4	//HwInit/x/x/x Existence of PCI D3F1 (Port 1)
    #define D0F5_RDV3F0EXST			BIT3	//HwInit/x/x/x Existence of PCI D3F0 (Port 0)
    #define D0F5_RDV2F0EXST			BIT2	//0/0/0/0 Existence of PCI D2F0
    #define D0F5_RONBDC			BIT1	//1b/1/x/x Enable of On-board Decode for AHCI/xHCI
    #define D0F5_RDV7F0EXST			BIT0	//HwInit/x/x/x Existence of PCI D7F0
#define D0F5_PM_CAPS		0xF8	//Power Management Capabilities
    #define D0F5_PMCPME			0xF8000000	//11001b/19h/x/x PME Support
    #define D0F5_PMCD2S			BIT26	//0/0/x/x D2 Support
    #define D0F5_PMCD1S			BIT25	//0/0/x/x D1 Support
    #define D0F5_PMCAUXC			(BIT22 + BIT23 + BIT24)	//0/0/x/x AUX Current
    #define D0F5_PMCDSI			BIT21	//1b/1/x/x Device Specific Initialization
    #define D0F5_RSV_53			(BIT19 + BIT20)	//0/R/x/x Reserved
    #define D0F5_TBD_34			(BIT16 + BIT17 + BIT18)	//010b/010b/x/x Version
    #define D0F5_TBD_35			0xFF00	//00h/00h/x/x Next Capability Pointer
    #define D0F5_TBD_36			0xFF	//01h/01h/x/x Capability ID
#define D0F5_PM_STA_CTL		0xFC	//Power Management Status / Control
    #define D0F5_TBD_37			0xFF000000	//0/R/x/x Power Management Data
    #define D0F5_TBD_38			BIT23	//0/x/x/x Enable Bus Power / Clock Control
    #define D0F5_TBD_39			BIT22	//0/x/x/x B2 / B3 Support
    #define D0F5_RSV_54			0x3F0000	//0/R/x/x Reserved
    #define D0F5_PMESD			BIT15	//0/0/x/x PME Status
    #define D0F5_TBD_40			(BIT13 + BIT14)	//0/0/x/x Data Scale
    #define D0F5_TBD_41			0x1E00	//0/0/x/x Data Select
    #define D0F5_PMEEN			BIT8	//0/0/x/x PME Enable
    #define D0F5_RSV_55			0xFC	//0/R/x/x Reserved
    #define D0F5_PWSD			(BIT0 + BIT1)	//00b/0/x/x Power State
#define D0F5_ROOT_COMPLEX_LINK_DECLARATION_CAPS_HEADER		0x100	//Root Complex Link Declaration Capabilities Header
    #define D0F5_RX100_31_20			0xFFF00000	//000h/R/x/x Next Capability Offset
    #define D0F5_RX100_19_16			0xF0000	//1h/R/x/x Capability Version
    #define D0F5_RX100_15_0			0xFFFF	//0005h/R/x/x PCI Express Extended Capability ID
#define D0F5_ELEMENT_SELF_DESCRIPTION		0x104	//Element Self Description
    #define D0F5_RPORTNUM_D0F5_7_0			0xFF000000	//0Ch/0Ch/x/x Port Number 
    #define D0F5_COMPONENT_ID			0xFF0000	//01h/01h/x/x Component ID
    #define D0F5_NUMBER_LINK_ENTRIES			0xFF00	//01h/01h/x/x Number of Link Entries
    #define D0F5_RX104_7_4			0xF0	//0/x/x/x Reserved
    #define D0F5_ELEMENT_TYPE			0xF	//0/x/x/x Element Type
//D0F0
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
//D0F5
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_PCCA		0x120	//Upstream Cycle Request Counter - PCCA
    #define D0F5_RPCT0REQCNT_31_0			0xFFFFFFFF	//HwInit/x/x/x Request Counter for PCCA Upstream Cycle
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_AHCI		0x124	//Upstream Cycle Request Counter - AHCI
    #define D0F5_RAHUSREQCNT_31_0			0xFFFFFFFF	//HwInit/x/x/x Request Counter for AHCI Upstream Cycle
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_XHCI		0x128	//Upstream Cycle Request Counter - xHCI
    #define D0F5_RXHUSREQCNT_31_0			0xFFFFFFFF	//HwInit/x/x/x Request Counter for xHCI Upstream Cycle
#define D0F5_RESERVED_Z4		0x12C	//Reserved
    #define D0F5_RX12C_31_0			0xFFFFFFFF	//0/0/x/x Reserved
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_GFX		0x130	//Upstream Cycle Request Counter - GFX
    #define D0F5_RGFXREQCNT_31_0			0xFFFFFFFF	//HwInit/x/x/x Request Counter for GFX Upstream Cycle
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_PCIE_1		0x134	//Upstream Cycle Request Counter - PCIe - 1
    #define D0F5_RPEREQCNT_31_0			0xFFFFFFFF	//HwInit/x/x/x Request Counter for PCIe Port 0 Upstream Cycle
#define D0F5_PCIE_EPHY_BASE_ADR		0x138	//PCIe EPHY Base Address
    #define D0F5_RPCIEPHYCFGBASE_39_14			0xFFFFFFC0	//0/x/x/x PCIe EPHY Base Address
    #define D0F5_RX138_5_0			0x3F	//0/0/x/x Reserved
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_PCIE_5		0x13C	//Upstream Cycle Request Counter - PCIe - 5
    #define D0F5_RX13C_31_0			0xFFFFFFFF	//0/0/x/x Reserved
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_CTLLER_PCIE_1		0x140	//Upstream Cycle Request Counter Controller - PCIe - 1
    #define D0F5_RPEREQCNT_CTRL_1_0			(BIT6 + BIT7)	//0/0/x/x PCIe Upstream Request Counter Controller
    #define D0F5_RX140_5_0			0x3F	//0/0/x/x Reserved
#define D0F5_SBDBG_USE		0x141	//SBDBG Use
    #define D0F5_RX141_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F5_RX141_5			BIT5	//0/x/x/x SBDBG xHCI Upstream Read Data Counter Bit 3
    #define D0F5_RX141_4			BIT4	//0/x/x/x SBDBG xHCI Upstream Read Data Counter Bit 2
    #define D0F5_RX141_3			BIT3	//0/x/x/x SBDBG AHCI Upstream Read Data Counter Bit 3
    #define D0F5_RX141_2			BIT2	//0/x/x/x SBDBG AHCI Upstream Read Data Counter Bit 2
    #define D0F5_RX141_1			BIT1	//0/x/x/x SBDBG PCCA Upstream Read Data Counter Bit 3
    #define D0F5_RX141_0			BIT0	//0/x/x/x SBDBG PCCA Upstream Read Data Counter Bit 2
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_CTLLER_SM		0x142	//Upstream Cycle Request Counter Controller - SM
    #define D0F5_RPCT0REQCNT_CTRL_1_0			(BIT6 + BIT7)	//0/0/x/x PCCA Upstream Request Counter Controller
    #define D0F5_RAHUSREQCNT_CTRL_1_0			(BIT4 + BIT5)	//0/0/x/x AHCI Upstream Request Counter Controller
    #define D0F5_RXHUSREQCNT_CTRL_1_0			(BIT2 + BIT3)	//0/0/x/x xHCI Upstream Request Counter Controller
    #define D0F5_RX142_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D0F5_UPSTREAM_CYCLE_REQ_CNTER_CTLLER_GFX		0x143	//Upstream Cycle Request Counter Controller - GFX
    #define D0F5_RGFXREQCNT_CTRL_1_0			(BIT6 + BIT7)	//0/0/x/x GFX Upstream Request Counter Controller
    #define D0F5_RPEMCUREQCNT_CTRL_1_0			(BIT4 + BIT5)	//0/0/x/x PEMCU Upstream Request Counter Controller
    #define D0F5_RRAIDREQCNT_CTRL_1_0			(BIT2 + BIT3)	//0/0/x/x Reserved
    #define D0F5_RVPIREQCNT_CTRL_1_0			(BIT0 + BIT1)	//0/0/x/x VPI Upstream Request Counter Controller
#define D0F5_RAID0_RELATED		0x144	//RAID0 Related
    #define D0F5_UFRAID0CTM_3_0			0xF000	//0100b/100/x/x RAID0 Request Path Occupy Timer
    #define D0F5_UFRAID0PMTM_3_0			0xF00	//0100b/100/x/x RAID0 Request Path Promote Timer
    #define D0F5_RRAID0REQCNT_CTRL_1_0			(BIT6 + BIT7)	//0/0/x/x RAID0 Upstream Request Counter Controller
    #define D0F5_RRAID0RISOSEL			BIT5	//1b/1/x/x RAID0 Read ISO Selection
    #define D0F5_RRAID0RPRISEL			BIT4	//0/0/x/x RAID0 Read HP Selection
    #define D0F5_RRAID0WISOSEL			BIT3	//1b/1/x/x RAID0 Write ISO Selection
    #define D0F5_RRAID0WPRISEL			BIT2	//0/0/x/x RAID0 Write HP Selection
    #define D0F5_RRAID0MIDQDYN			BIT1	//0/0/1/1 RAID0 MIDQ Dynamic Clock Enable
    #define D0F5_RRAID0RQBYPASS			BIT0	//0b/0/x/x RRAID0RQBYPASS
#define D0F5_RAID1_RELATED		0x146	//RAID1 Related
    #define D0F5_UFRAID1CTM_3_0			0xF000	//0100b/100/x/x RAID1 Request Path Occupy Timer
    #define D0F5_UFRAID1PMTM_3_0			0xF00	//0100b/100/x/x RAID1 Request Path Promote Timer
    #define D0F5_RRAID1REQCNT_CTRL_1_0			(BIT6 + BIT7)	//0/0/x/x RAID1 Upstream Request Counter Controller
    #define D0F5_RRAID1RISOSEL			BIT5	//1b/1/x/x RAID1 Read ISO Selection
    #define D0F5_RRAID1RPRISEL			BIT4	//0/0/x/x RAID1 Read HP Selection
    #define D0F5_RRAID1WISOSEL			BIT3	//1b/1/x/x RAID1 Write ISO Selection
    #define D0F5_RRAID1WPRISEL			BIT2	//0/0/x/x RAID1 Write HP Selection
    #define D0F5_RRAID1MIDQDYN			BIT1	//0/0/1/1 RAID1 MIDQ Dynamic Clock Enable
    #define D0F5_RRAID1RQBYPASS			BIT0	//0b/0/x/x RRAID1RQBYPASS
#define D0F5_APICX_UPSTREAM_CYCLE_SID		0x148	//APICX Upstream Cycle SID
    #define D0F5_RPAPBUSNUM_7_0			0xFF00	//0/0/x/x APICX Bus Number
    #define D0F5_RPAPDVNUM_4_0			0xF8	//0/0/x/x APICX Device Number
    #define D0F5_RPAPFUNNUM_2_0			(BIT0 + BIT1 + BIT2)	//101b/101b/x/x APICX Function Number
#define D0F5_LOCK_CTL_AND_OTHERS		0x14A	//Lock Control and Others
    #define D0F5_D0F5_RX14AB7			BIT7	//0/x/x/x Reserved
    #define D0F5_RLOCK_ORG			BIT6	//0/0/0/0 Original Lock Control
    #define D0F5_RTXTEN			BIT5	//1b/1b/x/x PXPTRF TXT Function Enable
    #define D0F5_D0F5_RX14AB4			BIT4	//0/0/x/x PXPTRF TXT Function Lock
    #define D0F5_RX14A_3			BIT3	//0/0/x/x Reserved
    #define D0F5_RX14A_2			BIT2	//0/0/x/x Reserved
    #define D0F5_RPCIEIOW_PIPE			BIT1	//1b/1b/1b/1b PCIe Downstream IOW Pipe
    #define D0F5_RPCIERD_PIPE			BIT0	//1b/1b/1b/1b PCIe Downstream Read Pipe
#define D0F5_DYNAMIC_CLK_OF_DBX_DOWNSTREAM_WRITE_FIFO		0x14B	//Dynamic Clock of DBX Downstream Write FIFO
    #define D0F5_RDYN_WCLK_EN_MCA			BIT7	//0/0/1b/1b MCA Downstream Write Data FIFO Dynamic Clock Enable
    #define D0F5_RVPIIOW_PIPE			BIT6	//1b/1b/1b/1b VPI Downstream IOW Pipe
    #define D0F5_RVPIRD_PIPE			BIT5	//1b/1b/1b/1b VPI Downstream read Pipe
    #define D0F5_RDYN_WCLK_EN_VPI			BIT4	//0/0/1b/1b VPI Downstream Write Data FIFO Dynamic Clock Enable
    #define D0F5_RDYN_WCLK_EN_APICX			BIT3	//0/0/1b/1b APICX Downstream Write Data FIFO Dynamic Clock Enable
    #define D0F5_RDYN_WCLK_EN_GFX			BIT2	//0/0/1b/1b GFX Downstream Write Data FIFO Dynamic Clock Enable
    #define D0F5_RDYN_WCLK_EN_PCCA			BIT1	//0/0/1b/1b PCCA Downstream Write Data FIFO Dynamic Clock Enable
    #define D0F5_RDYN_WCLK_EN_PCIE			BIT0	//0/0/1b/1b PCIe Downstream Write Data FIFO Dynamic Clock Enable
#define D0F5_MCA_REG_BASE_ADR		0x14C	//MCA Register Base Address
    #define D0F5_RX14C_31_30			(BIT30 + BIT31)	//0/0/x/x Reserved
    #define D0F5_D0F5_RX14CB29			BIT29	//0/x/x/x MCAMMIO_BASE_lock_bit
    #define D0F5_RMCAMMIO_BASE_EN			BIT28	//0/x/x/x MCA Decode Enable
    #define D0F5_RMCAMMIO_BASE_39_12			0xFFFFFFF	//0/x/x/x MCA Register Base Address
#define D0F5_SB_APIC_ADR_XY		0x150	//SB APIC Address xy
    #define D0F5_RLGAX_SB_19_16			0xF0	//0/0/0/0 SB APIC Legacy Address Range - x
    #define D0F5_RLGAY_SB_15_12			0xF	//0/0/0/0 SB APIC Legacy Address Range - y
#define D0F5_SB_APIC_ADR_Z		0x151	//SB APIC Address z
    #define D0F5_RX151_7_4			0xF0	//0/x/x/x Reserved
    #define D0F5_RLGAZ_SB_11_8			0xF	//0/0/0/0 SB APIC Legacy Address Range - z
#define D0F5_DYNAMIC_CLK_OF_DBX_DOWNSTREAM_WRITE_FIFO_PART_2		0x152	//Dynamic Clock of DBX Downstream Write FIFO part 2
    #define D0F5_RX152_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F5_RXHCIWISOSEL			BIT5	//0/0/x/x xHCI Write ISO Selection
    #define D0F5_RXHCIWPRISEL			BIT4	//0/0/x/x xHCI Write HP Selection
    #define D0F5_RXHIOW_PIPE			BIT3	//0/0/0/0 xHCI Downstream IOW Pipe
    #define D0F5_RXHRD_PIPE			BIT2	//0/0/0/0 xHCI Downstream read Pipe
    #define D0F5_RDYN_WCLK_EN_AHCI			BIT1	//0/0/1b/1b AHCI Downstream Write Data FIFO Dynamic Clock Enable
    #define D0F5_RDYN_WCLK_EN_XHCI			BIT0	//0/0/1b/1b xHCI Downstream Write Data FIFO Dynamic Clock Enable
#define D0F5_GFX_BUS_NUM		0x153	//GFX Bus Number
    #define D0F5_RGFX_BUSNUM			0xFF	//0/0/x/x GFX Bus Number 
#define D0F5_GFX_DEV_NUM		0x154	//GFX Dev Number
    #define D0F5_RGFX_DEVNUM			0xF8	//00001b/1/x/x GFX Dev Number 
    #define D0F5_RX154_2			BIT2	//0/0/x/x Reserved
    #define D0F5_RX154_1			BIT1	//0/0/x/x Reserved
    #define D0F5_D0F5_RX154B0			BIT0	//0/x/x/x Reserved
#define D0F5_ISO_AND_PRIORITY_CYCLE_CTL		0x155	//ISO and Priority Cycle Control
    #define D0F5_RTLPRI_EN			BIT7	//0/0/x/x PXPTRF --- CPUIF Interface Priority Enable
    #define D0F5_RTLPRI_PRI_EN			BIT6	//0/0/x/x PXPTRF High Priority Enable
    #define D0F5_RTLPRI_ISO_EN			BIT5	//0/0/x/x PXPTRF ISO Enable
    #define D0F5_RTPQUE_PRI_EN			BIT4	//0/0/x/x TPQUE High Priority Enable
    #define D0F5_RTPQUE_ISO_EN			BIT3	//0/0/x/x TPQUE ISO Enable
    #define D0F5_RPEV0WREQ_ISO_EN			BIT2	//0/0/x/x PEV0WREQC ISO Trigger TLRPI Enable
    #define D0F5_RPEV0RREQ_ISO_EN			BIT1	//0/0/x/x PEV0RREQC ISO Trigger TLPRI Enable
    #define D0F5_RPEV0MIDQ_ISO_EN			BIT0	//0/0/x/x PEV0 MIDQ ISO Trigger TLPRI Enable
#define D0F5_RESERVED_Z5		0x156	//Reserved
    #define D0F5_RX156_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z6		0x157	//Reserved
    #define D0F5_RX157_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_TACTL_PRIORITY_CTL		0x160	//TACTL Priority Control
    #define D0F5_RTAPEHP			BIT7	//1b/1/1/x High Priority from PCIe to TACTL Request
    #define D0F5_RTAPXHHP			BIT6	//1b/1/1/x High Priority from xHCI to TACTL Request
    #define D0F5_RTAPAHHP			BIT5	//1b/1/1/x High Priority from AHCI to TACTL Request
    #define D0F5_RTAPPCHP			BIT4	//1b/1/1/x High Priority from PCCA to TACTL Request
    #define D0F5_RTAPGHP			BIT3	//1b/1/1/x High Priority from GFX to TACTL Request
    #define D0F5_RTAPXPPEHP			BIT2	//1b/1/1/x High Priority from PCIe¡¯s MSI Remapping Cycle to TACTL Request
    #define D0F5_RTAPAPHP			BIT1	//1b/1/1/x High Priority from APICX to TACTL Request
    #define D0F5_RTAPPEMCUHP			BIT0	//1b/1/1/x High Priority from PEMCU to TACTL Request
#define D0F5_TACTL_ARBITRATION_CTL_0		0x161	//TACTL Arbitration Control 0
    #define D0F5_RPETAOCTM_3_0			0xF0	//0100b/100/x/x PCIe for TA Arbitration Occupy Timer
    #define D0F5_RPETAPMTM_3_0			0xF	//0100b/100/x/x PCIe for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_1		0x162	//TACTL Arbitration Control 1
    #define D0F5_RPXHTAOCTM_3_0			0xF0	//0100b/100/x/x xHCI for TA Arbitration Occupy Timer
    #define D0F5_RPXHTAPMTM_3_0			0xF	//0100b/100/x/x xHCI for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_2		0x163	//TACTL Arbitration Control 2
    #define D0F5_RPAHTAOCTM_3_0			0xF0	//0100b/100/x/x AHCI for TA Arbitration Occupy Timer
    #define D0F5_RPAHTAPMTM_3_0			0xF	//0100b/100/x/x AHCI for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_3		0x164	//TACTL Arbitration Control 3
    #define D0F5_RPPCTAOCTM_3_0			0xF0	//0100b/100/x/x PCCA for TA Arbitration Occupy Timer
    #define D0F5_RPPCTAPMTM_3_0			0xF	//0100b/100/x/x PCCA for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_4		0x165	//TACTL Arbitration Control 4
    #define D0F5_RPGTAOCTM_3_0			0xF0	//0100b/100/x/x GFX for TA Arbitration Occupy Timer
    #define D0F5_RPGTAPMTM_3_0			0xF	//0100b/100/x/x GFX for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_5		0x166	//TACTL Arbitration Control 5
    #define D0F5_RPXPPETAOCTM_3_0			0xF0	//0100b/100/x/x PCIe MSI CYCLE for TA Arbitration Occupy Timer
    #define D0F5_RPXPPETAPMTM_3_0			0xF	//0100b/100/x/x PCIe MSI CYCLE for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_6		0x167	//TACTL Arbitration Control 6
    #define D0F5_RPAPTAOCTM_3_0			0xF0	//0100b/100/x/x APICX for TA Arbitration Occupy Timer
    #define D0F5_RPAPTAPMTM_3_0			0xF	//0100b/100/x/x APICX for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_7		0x168	//TACTL Arbitration Control 7
    #define D0F5_RPPEMCUTAOCTM_3_0			0xF0	//0100b/100/x/x PEMCU for TA Arbitration Occupy Timer
    #define D0F5_RPPEMCUTAPMTM_3_0			0xF	//0100b/100/x/x PEMCU for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_8		0x169	//TACTL Arbitration Control 8
    #define D0F5_RPRAID0TAOCTM_3_0			0xF0	//0100b/100/x/x RAIDA 0 for TA Arbitration Occupy Timer
    #define D0F5_RPRAID0TAPMTM_3_0			0xF	//0100b/100/x/x RAIDA 0 for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_9		0x16A	//TACTL Arbitration Control 9
    #define D0F5_RCMPOCTM_3_0			0xF0	//0100b/100/x/x DMA Request of Address Remapping for TA Upstream Arbitration Occupy Timer
    #define D0F5_RCMPPMTM_3_0			0xF	//0100b/100/x/x DMA Request of Address Remapping for TA Upstream Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_10		0x16B	//TACTL Arbitration Control 10
    #define D0F5_RMSIOCTM_3_0			0xF0	//0100b/100/x/x MSI Request for TA Upstream Arbitration Occupy Timer
    #define D0F5_RMSIPMTM_3_0			0xF	//0100b/100/x/x MSI Request for TA Upstream Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_11		0x16C	//TACTL Arbitration Control 11
    #define D0F5_RINVOCTM_3_0			0xF0	//0100b/100/x/x Invalidation Request for TA Upstream Arbitration Occupy Timer
    #define D0F5_RINVPMTM_3_0			0xF	//0100b/100/x/x Invalidation Request for TA Upstream Arbitration Promote Timer
#define D0F5_IOV_ENABLE		0x16D	//IOV Enable
    #define D0F5_RSV_5BH_7			BIT7	//0/0/x/x Reserved
    #define D0F5_RTAMSIFLUSHEN			BIT6	//0/0/x/x MSIFLUSHEN
    #define D0F5_RTAPVPIHP			BIT5	//1b/1/1/x High Priority from VPI to TACTL Request
    #define D0F5_RTAPRAID0HP			BIT4	//1b/1/1/x High Priority from RAIDA0 to TACTL Request
    #define D0F5_RTAPRAID1HP			BIT3	//1b/1/1/x High Priority from RAIDA1 to TACTL Request
    #define D0F5_RINVFLH			BIT2	//0/0/x/x TACTL Invalidation Command Flush Upstream DMA Cycle Control
    #define D0F5_RENIOVTL			BIT1	//0/0/x/x IOV Is Supported or Not
    #define D0F5_RATSENABLE			BIT0	//0/0/x/x PCIe Supports ¡°Device of IOV Capability¡± or Not
#define D0F5_TACTL_LRU_CTL_0		0x16E	//TACTL LRU Control 0
    #define D0F5_RCONTCHISO			BIT7	//1b/1/1/x Context Cache ISO LRU Support
    #define D0F5_RPDE1CHISO			BIT6	//1b/1/1/x PDE1 Cache ISO LRU Support
    #define D0F5_RPDE1CHISOTMCNT_1_0			(BIT4 + BIT5)	//00b/0/x/x PDE1 Cache ISO Entry Timeout Control
    #define D0F5_RPDE1CHISORSTCTL			BIT3	//1b/1/1/x PDE1 Cache ISO Entry Reset when Time Out
    #define D0F5_RPDE2CHISO			BIT2	//1b/1/1/x PDE2 Cache ISO LRU Support
    #define D0F5_RPDE2CHISOTMCNT_1_0			(BIT0 + BIT1)	//00b/0/x/x PDE2 Cache ISO Entry Timeout Control
#define D0F5_TACTL_LRU_CTL_1		0x16F	//TACTL LRU Control 1
    #define D0F5_RCONTCHISORSTCTL			BIT7	//1b/1/1/x PDE1 Cache ISO Entry Reset when Time Out
    #define D0F5_RCONTCHISOTMCNT_1_0			(BIT5 + BIT6)	//00b/0/x/x PDE1 Cache ISO Entry Timeout Control
    #define D0F5_RPDE2CHISORSTCTL			BIT4	//1b/1/1/x PDE2 Cache ISO Entry Reset when Time Out
    #define D0F5_RIOTLBCHISO			BIT3	//1b/1/1/x IOTLB Cache ISO LRU Support
    #define D0F5_RIOTLBCHISOTMCNT_1_0			(BIT1 + BIT2)	//00b/0/x/x IOTLB Cache ISO Entry Timeout Control
    #define D0F5_RIOTLBCHISORSTCTL			BIT0	//1b/1/1/x IOTLB Cache ISO Entry Reset when Time Out
#define D0F5_TACTL_ARBITRATION_CTL_12		0x170	//TACTL Arbitration Control 12
    #define D0F5_RPRAID1TAOCTM_3_0			0xF0	//0100b/100/x/x RAIDA1 for TA Arbitration Occupy Timer
    #define D0F5_RPRAID1TAPMTM_3_0			0xF	//0100b/100/x/x RAIDA1 for TA Arbitration Promote Timer
#define D0F5_TACTL_ARBITRATION_CTL_13		0x171	//TACTL Arbitration Control 13
    #define D0F5_RPVPITAOCTM_3_0			0xF0	//0100b/100/x/x VPI for TA Arbitration Occupy Timer
    #define D0F5_RPVPITAPMTM_3_0			0xF	//0100b/100/x/x VPI for TA Arbitration Promote Timer
#define D0F5_TACTL_RELATED		0x172	//TACTL Related
    #define D0F5_RX172_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F5_RTAPCIEISOEN			BIT5	//0/0/x/x TACTL ISO Request Control Register for PCIe 
    #define D0F5_RENTACACHE_PDE1			BIT4	//1b/1/1/x TA Internal Cache Control for PDE1
    #define D0F5_RENTACACHE_PDE2			BIT3	//1b/1/1/x TA Internal Cache Control for PDE2
    #define D0F5_RENTACACHE_IOTLB			BIT2	//1b/1/1/x TA Internal Cache Control for IOTLB
    #define D0F5_RENTACACHE_IRTE			BIT1	//1b/1/1/x TA Internal Cache Control for IRTE
    #define D0F5_RTATMOCKMOD			BIT0	//0/0/0/x Cache ISO Time Out Counter Work Mode
#define D0F5_RHIT_FLAG_ENABLE		0x173	//RHIT_FLAG Enable
    #define D0F5_RHIT_FLAG_EN_APICX			BIT7	//1b/1b/1b/1b MIDQ Cache Enable for APICX Path
    #define D0F5_RHIT_FLAG_EN_PEV0			BIT6	//1b/1b/1b/1b MIDQ Cache Enable for PCIe Path
    #define D0F5_RHIT_FLAG_EN_PCT0			BIT5	//1b/1b/1b/1b MIDQ Cache Enable for PCCA Path
    #define D0F5_RHIT_FLAG_EN_GFX			BIT4	//1b/1b/1b/1b MIDQ Cache Enable for GFX Path
    #define D0F5_RHIT_FLAG_EN_PEMCU			BIT3	//1b/1b/1b/1b MIDQ Cache Enable for PEMCU Path
    #define D0F5_RHIT_FLAG_EN_VPI			BIT2	//1b/1b/1b/1b MIDQ Cache Enable for VPI Path
    #define D0F5_RHIT_FLAG_EN_RAID0			BIT1	//1b/1b/1b/1b MIDQ Cache Enable for RAID0 Path
    #define D0F5_RHIT_FLAG_EN_RAID1			BIT0	//1b/1b/1b/1b MIDQ Cache Enable for RAID1 Path
#define D0F5_RHIT_FLAG_ENABLE_PART_2		0x174	//RHIT_FLAG Enable Part 2
    #define D0F5_RX174_7_2			0xFC	//0/x/x/x Reserved
    #define D0F5_RHIT_FLAG_EN_AHCI			BIT1	//1b/1b/1b/1b MIDQ Cache Enable for AHCI Path
    #define D0F5_RHIT_FLAG_EN_XHCI			BIT0	//1b/1b/1b/1b MIDQ Cache Enable for xHCI Path
#define D0F5_RESERVED_Z7		0x175	//Reserved
    #define D0F5_RX175_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z8		0x176	//Reserved
    #define D0F5_RX176_7_0			0xFF	//0/R/x/x Reserved
#define D0F5_RESERVED_Z9		0x177	//Reserved
    #define D0F5_RX177_7_0			0xFF	//0/R/x/x Reserved
#define D0F5_APIC_ACCESS_CTL		0x240	//APIC Access Control
    #define D0F5_RLGAPIC			BIT7	//1b/1/x/x IO APIC Enable
    #define D0F5_RAPIC_DEC_DUAL			BIT6	//1b/1/1/1 APIC New Decode ((for CHX002))
    #define D0F5_RIRQDMSI			BIT5	//0/0/x/x Issuing MSI Cycles for the IRQ De-assertion
    #define D0F5_RAPIC_LDTM			BIT4	//0/0/x/x Reserved
    #define D0F5_RLGAX_19_16			0xF	//Ch/Ch/x/x APIC Legacy Address Range - x
#define D0F5_NB_IOAPIC_ADR_RANGE		0x241	//NB IOAPIC Address Range
    #define D0F5_RLGAY_15_12			0xF0	//0/0/x/x APIC Legacy Address Range - y
    #define D0F5_RLGAZ_11_8			0xF	//0/0/x/x APIC Legacy Address Range - z
#define D0F5_APIC_INTR_CTL_1		0x242	//APIC Interrupt Control 1
    #define D0F5_RX242_7_4			0xF0	//0/x/x/x Reserved
    #define D0F5_RC3EN			BIT3	//0/0/x/x IRQ Transparent Mode
    #define D0F5_RMSI_FORMAT_EN			BIT2	//1b/1/1/1 APICX MSI Cycle Format Control
    #define D0F5_RX242_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D0F5_APIC_ROUTING_CTL_FOR_PE5_PE6		0x243	//APIC routing Control for PE5, PE6
    #define D0F5_RROUTING_PEG2_1_0			(BIT6 + BIT7)	//0/0/x/x RROUTING_PEG2_
    #define D0F5_RROUTING_PEG3_1_0			(BIT4 + BIT5)	//01b/01b/x/x RROUTING_PEG3_
    #define D0F5_RROUTING_PEG_1_0			(BIT2 + BIT3)	//10b/10b/x/x Reserved
    #define D0F5_RBLOCKNB2VIC			BIT1	//0/0/0/0 Reserved
    #define D0F5_RX243_0			BIT0	//0/x/x/x Reserved
#define D0F5_APIC_INTR_CTL_2		0x244	//APIC Interrupt Control 2
    #define D0F5_RX244_7_4			0xF0	//0/x/x/x Reserved
    #define D0F5_D0F5_RX244_3			BIT3	//0/x/x/x Reserved
    #define D0F5_D0F5_RX244_2			BIT2	//0/x/x/x Reserved
    #define D0F5_RX244_1			BIT1	//0/x/x/x Reserved
    #define D0F5_RX244_0			BIT0	//0/x/x/x Reserved
#define D0F5_RESERVED_Z10		0x245	//Reserved
    #define D0F5_RX244_15_8			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z11		0x246	//Reserved
    #define D0F5_RX244_23_16			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z12		0x247	//Reserved
    #define D0F5_RX244_31_24			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z13		0x248	//Reserved
    #define D0F5_RX248_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z14		0x249	//Reserved
    #define D0F5_RX249_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z15		0x24A	//Reserved
    #define D0F5_RX24A_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z16		0x24B	//Reserved
    #define D0F5_RX24B_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_Z17		0x24C	//Reserved
    #define D0F5_RX24C_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_REG_CTL_1		0x24D	//Reserved Register Control 1
    #define D0F5_RX24C_15			BIT7	//0/x/x/x Reserved
    #define D0F5_RX24C_14_12			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define D0F5_RX24C_11_8			0xF	//0/x/x/x Reserved
#define D0F5_RESERVED_REG_CTL_2		0x24E	//Reserved Register Control 2
    #define D0F5_RX24C_31_16			0xFFFF	//0/x/x/x Reserved
#define D0F5_CFG_CYCLE_CTL_1		0x260	//Configuration Cycle Control 1
    #define D0F5_RMMCFG_SEL			BIT7	//1b/1/1/1 Extend Configuration Cycle Decoding
    #define D0F5_D0F5_RX260B6			BIT6	//0/x/x/x CLASS_CODE_LOCK_D0F5
    #define D0F5_RCFGWSDHABT			BIT5	//1b/1/x/x Abort Data to Device when Configuration Cycle Shadow Hit in VKCFG
    #define D0F5_RCF8PBEW			BIT4	//1b/1/x/x CF8 Byte Write Enable
    #define D0F5_RDV0CFG			BIT3	//0/0/0/0 Configuration Cycles to the Secondary Bus behind the P2P Bridge
    #define D0F5_D0F5_RX260B2			BIT2	//0/x/x/x Reserved
    #define D0F5_RXCFGM_1_0			(BIT0 + BIT1)	//11b/11/x/x Extended Configuration Space Access 
#define D0F5_CFG_CYCLE_CTL_2		0x261	//Configuration Cycle Control 2
    #define D0F5_RXCFGA_35_28			0xFF	//0Eh/x/x/x Addressing for Memory Mapped Configuration Access
#define D0F5_CFG_CYCLE_CTL_3		0x262	//Configuration Cycle Control 3
    #define D0F5_RX262_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D0F5_RXCFGA_39_36			0x3C	//0/x/x/x Addressing for Memory Mapped Configuration Access
    #define D0F5_RCFG2SB_D1F2_7			BIT1	//0/0/x/x Forward D1F2-F7 Configuration Cycle to GFX or SM
    #define D0F5_RCFG2SB_D1F1			BIT0	//0/0/x/x Forward D1F1 Configuration Cycle to GFX or SM
#define D0F5_CFG_CYCLE_CTL_4		0x263	//Configuration Cycle Control 4
    #define D0F5_RXCFGA_27_24			0xF0	//0/x/x/x Addressing for Memory Mapped Configuration Access
    #define D0F5_RX263_3			BIT3	//0/x/x/x Reserved
    #define D0F5_RXCFGSZ_2_0			(BIT0 + BIT1 + BIT2)	//100b/100b/x/x Memory Mapped Configuration Space Size Control
#define D0F5_TRAFFIC_FLOW_CTL_DOWNSTREAM_CTL_UPSIDE_NEAR_CPUIF		0x264	//Traffic Flow Control - Downstream Control (Upside Near CPUIF)
    #define D0F5_RLTPIPE			BIT7	//1b/x/x/x Reserved (Do Not Program)
    #define D0F5_RCP1RBLCP			BIT6	//1b/1/x/x Hold the Downstream Cycle on Non-posted Cycle to South Module
    #define D0F5_RCP1IOWBLCP			BIT5	//0/0/x/x Holding the Downstream Cycle One Clock Earlier on Non-posted Cycle to SM Module
    #define D0F5_RPCWFLSH			BIT4	//1b/1/1/1 Downstream Cycles to Flush Upstream Write
    #define D0F5_RNEWLOCKFLHP2CW			BIT3	//0/0/x/x How Many Cycle Will Be Flushed after a LOCK Read Is Received
    #define D0F5_RL2RQ			BIT2	//1b/1/*1/x Downstream Read Request Level
    #define D0F5_RTDNIWRDY			BIT1	//0/0/0/x Downstream Write Request Timing
    #define D0F5_RTDNODR			BIT0	//0/0/0/x In Order Downstream Cycles
#define D0F5_TERFF_CLK_SEL_INTERNAL_BLOCK_CTL		0x265	//TERFF Clock Select, Internal Block Control
    #define D0F5_RNP_PIPE_EN			BIT7	//1b/1b/1b/1b Downstream Non-post Pipe Enable
    #define D0F5_RX265_6			BIT6	//0/x/x/x Reserved
    #define D0F5_RSTOPREQ_P1_IOWEND			BIT5	//1b/1b/1b/1b Block Wait P1 IOWEND
    #define D0F5_RPOSTWR_BLK_CFG			BIT4	//0/0/x/x Block Configuration Cycle for C2P Write
    #define D0F5_RPOSTWR_BLK_ENABLEREQ			BIT3	//1b/1/1/1 Block ENABLEREQ Cycle for C2P Write
    #define D0F5_RPOSTWR_BLK_STOPREQ			BIT2	//1b/1/1/1 Block STOPREQ Cycle for C2P Write
    #define D0F5_RPOSTWR_BLK_LOCKRD			BIT1	//0/0/x/x Block Lock Read Cycle for C2P Write
    #define D0F5_RTERFFCLKSEL			BIT0	//1b/1/1/1 TERFF Module Dynamic Clock Enable
#define D0F5_PXPTRF_RELATED_REG		0x266	//PXPTRF Related Register
    #define D0F5_RX266_15_3			0xFFF8	//0/x/x/x Reserved
    #define D0F5_RTDADS1TE_PE			BIT2	//0/0/1/x Reduce 1T for Downstream PCIe Request CDC Output
    #define D0F5_RDNRFIFO_1T			BIT1	//1b/1/0/x Downstream Read Data Push CDC Register Out
    #define D0F5_MODE333_ORG			BIT0	//1b/x/x/x Reserved (Do Not Program)
#define D0F5_RCRB_H_BASE_ADR		0x268	//RCRB-H Base Address
    #define D0F5_RX268_31_28			0xF0000000	//0/x/x/x Reserved
    #define D0F5_RXRCRBHA_OUT_39_12			0xFFFFFFF	//0/x/x/x Base Address [39:12] of RCRB-H
#define D0F5_TACTL_BASE_ADR		0x26C	//TACTL Base Address
    #define D0F5_D0F5_RX26CB31			BIT31	//0/x/x/x Lock Bit for TACTL Base Address
    #define D0F5_RX26C_30_28			(BIT28 + BIT29 + BIT30)	//0/x/x/x Reserved
    #define D0F5_RXRCRBVA_39_12			0xFFFFFFF	//0/x/x/x Base Address [39:12] of TACTL (TACTL_BAR)
#define D0F5_TRAFFIC_FLOW_CTL_DOWNSTREAM_CTL_DOWNSIDE_NEAR_GFX_1		0x270	//Traffic Flow Control - Downstream Control (Downside Near GFX) 1
    #define D0F5_RVGANONSPLIT			BIT7	//1b/1/1/1 Central Traffic Controller ((PXPTRF)) Split QW VGA Memory Cycle to DW Cycle ((RVGANONSPLIT))
    #define D0F5_RHDWSWAP			BIT6	//1b/1/1/1 Swap the High DW to Low DW Request for Downstream Request to GFX Whose Low DW Is Invalid
    #define D0F5_RSPW_BLK_EN			BIT5	//0/0/0/0 Block Invalid Sparse Write Cycle to GFXCTL
    #define D0F5_RX270_4			BIT4	//0/x/x/x Reserved
    #define D0F5_RX270_3			BIT3	//0/x/x/x Reserved
    #define D0F5_RDSIWRDY			BIT2	//0/0/0/0 Downstream Write Data Timing to GFXCTL
    #define D0F5_RPCWNFLSHP2			BIT1	//0/0/0/0 Downstream C2GFX Read Cycle Flush Upstream GFX2C Write Cycle
    #define D0F5_RX270_0			BIT0	//0/x/x/x Reserved
#define D0F5_TRAFFIC_FLOW_CTL_DOWNSTREAM_CTL_DOWNSIDE_NEAR_GFX_2		0x271	//Traffic Flow Control - Downstream Control (Downside Near GFX) 2
    #define D0F5_RX271_7			BIT7	//0/x/x/x Reserved
    #define D0F5_RX271_6			BIT6	//0/x/x/x Reserved
    #define D0F5_RX271_5			BIT5	//0/x/x/x Reserved
    #define D0F5_RX271_4			BIT4	//0/x/x/x Reserved
    #define D0F5_RX271_3			BIT3	//0/x/x/x Reserved
    #define D0F5_RX271_2			BIT2	//0/x/x/x Reserved
    #define D0F5_RGFXQ1T			BIT1	//0/x/x/x Reducing 1T Latency for GFX Upstream Requests
    #define D0F5_RTDNIWRDY1TP2			BIT0	//0/x/x/x Reducing 1T Initial Latency for Downstream Write Data to GFX
#define D0F5_CPUIF_FUN		0x272	//CPUIF Function
    #define D0F5_RX272_7			BIT7	//0/x/x/x Reserved
    #define D0F5_RX272_6			BIT6	//0/x/x/x CPUIF Lock Control Register.
    #define D0F5_RIORACROSS4BD			BIT5	//0/0/x/x CPUIF Depart IO Read Cycle across 4B Boundary to 2 IOR Cycle Disable
    #define D0F5_RCREDI_UPFRQ_1_0			(BIT3 + BIT4)	//10b/x/x/x The Frequency CPUIF Update the Credit that HIF Can Send C2P Write Data
    #define D0F5_RCPUIFC2P2FLUSHC2M_EN			BIT2	//1b/1/x/x C2P2 Flush C2M Enable Signal for CPUIF
    #define D0F5_RTAD_EN			BIT1	//1b/1/x/x DVAD Function Enable
    #define D0F5_RTADERRTOMCA_EN			BIT0	//1b/1/x/x DVAD Report Error to MCA Enable
#define D0F5_PXPTRF_RELATED_REG_CFG_READ_FLUSH_UPSTREAM_WRITE_FOR_DEV		0x273	//PXPTRF Related Register (Configuration Read Flush Upstream Write for Device)
    #define D0F5_RNPEQ_C2RAID1_MMIO_FLUSH_EN			BIT7	//1b/1/1/1 Read RAID1 MMIO Register Flush RAID1 Upstream Write
    #define D0F5_RNPEQ_C2RAID0_MMIO_FLUSH_EN			BIT6	//1b/1/1/1 Read RAID0 MMIO Register Flush RAID0 Upstream Write
    #define D0F5_RSPCYC_ABORT			BIT5	//1b/1/1/1 Abort Special Cycle
    #define D0F5_RD8F0_EN			BIT4	//1b/1/1/1 Enable RAID0 Configuration Space (D8F0)
    #define D0F5_RD9F0_EN			BIT3	//1b/1/1/1 Enable RAID1 Configuration Space (D9F0)
    #define D0F5_RNPEQ_C2RAID1_CFG_FLUSH_EN			BIT2	//1b/1/1/1 Read RAID1 Register Flush RAID1 Upstream Write
    #define D0F5_RNPEQ_C2RAID0_CFG_FLUSH_EN			BIT1	//1b/1/1/1 Read RAID0 Register Flush RAID0 Upstream Write
    #define D0F5_RNPEQ_C2TA_CFG_FLUSH_EN			BIT0	//1b/1/1/1 Read TACTL Register Flush TACTL Upstream Write
#define D0F5_TRAFFIC_FLOW_CTL_DOWNSTREAM_CTL_DOWNSIDE_NEAR_PCIE_1		0x274	//Traffic Flow Control - Downstream Control (Downside Near PCIe) 1
    #define D0F5_RD0F7_EN			BIT7	//0/0/0/0 Enable Configuration Cycle (D0F7)
    #define D0F5_RNPEQ_C2P2_FLUSH_EN			BIT6	//1b/1/1/1 NPEQ C2P2 Read Cycle Completion Flush GFX P2C Write Enable
    #define D0F5_RTDNIWRDY1T			BIT5	//0/0/1/x Reducing 1T Initial Latency for Downstream Write Data to PCIe
    #define D0F5_RNPEQ_C2PR_FLUSH_EN			BIT4	//0/0/0/0 C2P Read Flush P2C Write in NPEQ
    #define D0F5_RPXPEPLLOFF			BIT3	//0/x/x/x Block Downstream Cycles to PCIe
    #define D0F5_RNPEQ_ABRT_EARLY			BIT2	//0/0/0/0 NPEQ Read Abort Early
    #define D0F5_RTXRTRDY_EN			BIT1	//0/0/x/x TXRTRDY Always on Enable
    #define D0F5_RCPRNFLHNCW			BIT0	//1b/1/1/1 C2PR Not Flush Non-snoop Path Upstream Write Cycle
#define D0F5_CPUIF_REG_FOR_FPGA_DEBUG_1		0x275	//CPUIF register for FPGA DEBUG 1
    #define D0F5_RFPGA_MATCHADDR_23_0			0xFFFFFF	//0/0/x/x RFPGA_MATCHADDR
#define D0F5_CPUIF_REG_FOR_FPGA_DEBUG_2		0x278	//CPUIF register for FPGA DEBUG 2
    #define D0F5_RFPGADEBUG32_SELECT_7_0			0xFF	//0/0/x/x Select 32 Bits out of 256-bit Data
#define D0F5_CPUIF_REG_FOR_FPGA_DEBUG_3		0x279	//CPUIF register for FPGA DEBUG 3
    #define D0F5_RFPGADEBUG16_SELECT_7_0			0xFF	//0/0/x/x Select 16 Bits out of 128-bit Data
#define D0F5_DOWNSTREAM_ARBITRATION_OCCUPANCY_TIME_1		0x27A	//Downstream Arbitration - Occupancy Time 1
    #define D0F5_RTDNPWTIM_3_0			0xF0	//0100b/100/x/x Minimum Occupancy Time for Peer-to-peer Downstream Write Request
    #define D0F5_RTDNPRTIM_3_0			0xF	//0010b/10/x/x Minimum Occupancy Time for Peer-to-peer Downstream Read Request
#define D0F5_DOWNSTREAM_ARBITRATION_OCCUPANCY_TIME_2		0x27B	//Downstream Arbitration - Occupancy Time 2
    #define D0F5_RTDNFPTIM_3_0			0xF0	//0100b/100/x/x Minimum Occupancy Time for FSBC Downstream Request
    #define D0F5_RTDNHTIM_3_0			0xF	//0100b/100/x/x Minimum Occupancy Time for CPU Downstream Request
#define D0F5_LOCK_CTL_AND_OTHERS_Z1		0x27C	//Lock Control and Others
    #define D0F5_RLOCK_PASS_TACTL_1			BIT7	//1b/1b/1b/1b Block TACTL before PXPTRF Finish Lock Read
    #define D0F5_RLOCK_PASS_TACTL_2			BIT6	//0/0/0/0 Block TACTL before PXPTRF EnableReq
    #define D0F5_RLOCK_BLK_C2P_EN			BIT5	//0/0/0/0 Block Downstream Cycle before PXPTRF Finish StopReq
    #define D0F5_RLOCK_READ_BLK_C2P_ALL_EN			BIT4	//0/0/0/0 Block Downstream Cycle if PXPTRF Receive Lock Read
    #define D0F5_RCF8_RELOAD_MM			BIT3	//1b/1b/1b/1b Reserved
    #define D0F5_RCF8_RELOAD_FPMM			BIT2	//1b/1b/1b/1b Reserved
    #define D0F5_RCF8_RDH_SEL			BIT1	//1b/1b/1b/1b CF8 Read Data Select for High DW
    #define D0F5_RCF8_RDL_SEL			BIT0	//1b/1b/1b/1b CF8 Read Data Select for Low DW
#define D0F5_REG_FOR_DESIGN_ISSUE_1		0x27D	//Register for Design Issue 1
    #define D0F5_RBUS_RCRB			0xFF	//0/0/0/0 PXPTRF internal bus number of RCRB
#define D0F5_REG_FOR_DESIGN_ISSUE_2		0x27E	//Register for Design Issue 2
    #define D0F5_RDEV_RCRB			0xF8	//1fh/1fh/1fh/1fh PXPTRF internal device number of RCRB
    #define D0F5_RFUN_RCRB			(BIT0 + BIT1 + BIT2)	//111b/111b/111b/111b PXPTRF internal function number of RCRB
#define D0F5_REG_FOR_DESIGN_ISSUE		0x27F	//Register for Design Issue
    #define D0F5_RX27F_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_VPI_UPSTREAM_ARBITRATION_TIMER_UFXH		0x280	//VPI Upstream Arbitration Timer ((UFXH))
    #define D0F5_UFVPIOCTM_3_0			0xF0	//0100b/100/x/x VPI Upstream Arbitration Occupy Timer
    #define D0F5_UFVPIPMTM_3_0			0xF	//0100b/100/x/x VPI Upstream Arbitration Promote Timer
#define D0F5_REG_FOR_PXPTRF_1		0x281	//Register for PXPTRF 1
    #define D0F5_RX281_7_1			0xFE	//0/x/x/x Reserved
    #define D0F5_RVPIMIDQDYN			BIT0	//0/x/1b/1b Reserved
#define D0F5_RESERVED_REG_FOR_PXPTRF_2		0x282	//Reserved Register for PXPTRF 2
    #define D0F5_RX282_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_REG_FOR_PXPTRF_3		0x283	//Reserved Register for PXPTRF 3
    #define D0F5_RX283_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_BYPASS_TO_REDUCE_1T_PIPE_OR_PXPTRF_1		0x284	//Bypass to Reduce 1T Pipe or PXPTRF 1
    #define D0F5_RBYPASS_AHUSWQPUSHX			BIT7	//1b/x/1b/x AHUSWQPushX Bypass
    #define D0F5_RBYPASS_PEV0WFFPSH_DFF			BIT6	//1b/x/1b/x PEV0WFFPSH_DFF Bypass
    #define D0F5_RBYPASS_PCT0RQPUSHX			BIT5	//1b/x/1b/x PCT0RQPushX Bypass
    #define D0F5_RBYPASS_PCT0WQPUSHX			BIT4	//1b/x/1b/x PCT0WQPushX Bypass
    #define D0F5_RBYPASS_PCT0WFFPSH_DFF			BIT3	//1b/x/1b/x PCT0WFFPSH_DFF Bypass
    #define D0F5_RBYPASS_XHUSRQPUSHX			BIT2	//1b/x/1b/x XHUSRQPushX Bypass
    #define D0F5_RBYPASS_XHUSWQPUSHX			BIT1	//1b/x/1b/x XHUSWQPushX Bypass
    #define D0F5_RBYPASS_XHUSWFFPSH_DFF			BIT0	//1b/x/1b/x XHUSWFFPSH_DFF Bypass
#define D0F5_BYPASS_TO_REDUCE_1T_PIPE_OR_PXPTRF_2		0x285	//Bypass to Reduce 1T Pipe or PXPTRF 2
    #define D0F5_RBYPASS_AHUSRQPUSH			BIT7	//1b/x/1b/x AHUSRQPush Bypass
    #define D0F5_RBYPASS_AHUSWQPUSH			BIT6	//1b/x/1b/x AHUSWQPush Bypass
    #define D0F5_RBYPASS_AHUSRQPUSHX			BIT5	//1b/x/1b/x AHUSRQPushX Bypass
    #define D0F5_RBYPASS_AHUSWFFPSH_DFF			BIT4	//1b/x/1b/x AHUSWFFPSH_DFF Bypass
    #define D0F5_RBYPASS_USRDPSH			BIT3	//1b/x/1b/x USRDPSH Bypass
    #define D0F5_RX285_2_0			(BIT0 + BIT1 + BIT2)	//0/x/x/x Reserved
#define D0F5_RESERVED_REG_FOR_PXPTRF_4		0x286	//Reserved Register for PXPTRF 4
    #define D0F5_RX286_7_0			0xFF	//0/x/x/x Reserved
#define D0F5_RESERVED_REG_FOR_PXPTRF_5		0x287	//Reserved Register for PXPTRF 5
    #define D0F5_RX287_7_0			0xFF	//0/x/x/x Reserved
#endif
