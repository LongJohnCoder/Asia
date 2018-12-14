//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		ERRRPT					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D0F1_ErrRpt_R101(A0).doc(final)MOD_D0F1.xls
#ifndef _CHX002_D0F1_ERRRPT_H
#define _CHX002_D0F1_ERRRPT_H
//D0F1
#define D0F1_VID		0x00	//Vendor ID
    #define D0F1_VENDORID_15_0			0xFFFF	//1106h/x/x/x Vendor ID
#define D0F1_DID		0x02	//Device ID
    #define D0F1_DEVID_15_0			0xFFFF	//31B0h/x/x/x Device ID
#define D0F1_PCI_CMD		0x04	//PCI Command
    #define D0F1_RX04_15_10			0xFC00	//0/R/x/x Reserved
    #define D0F1_RFBACK			BIT9	//0/R/x/x Fast Back-to-back Cycle Enable
    #define D0F1_RSERR			BIT8	//0/R/x/x SERR# Enable 
    #define D0F1_RSETP			BIT7	//0/R/x/x Address / Data Stepping
    #define D0F1_RPTYERR			BIT6	//0/R/x/x Parity Error Response
    #define D0F1_RVGA			BIT5	//0/R/x/x VGA Palette Snooping
    #define D0F1_RMWINV			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D0F1_RSPCYC			BIT3	//0/R/x/x Respond to Special Cycle
    #define D0F1_RMSTR			BIT2	//1b/R/x/x PCI Master Function
    #define D0F1_RENMEM			BIT1	//1b/R/x/x Memory Space Access
    #define D0F1_RENIO			BIT0	//0/R/x/x I/O Space Access
#define D0F1_PCI_STA		0x06	//PCI Status
    #define D0F1_SPERRS			BIT15	//0/R/x/x Detected Parity Error
    #define D0F1_SERRS			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D0F1_SMABORT			BIT13	//0/R/x/x Received Master-Abort (Except Special Cycle)
    #define D0F1_STABORTM			BIT12	//0/R/x/x Received Target-Abort
    #define D0F1_STABORTS			BIT11	//0/R/x/x Target-Abort Assertion
    #define D0F1_DEVS_1_0			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D0F1_SDPERRS			BIT8	//0/R/x/x Master Data Parity Error
    #define D0F1_RFBKS			BIT7	//0/R/x/x Capable of Accepting Fast Back-to-back as A Target
    #define D0F1_RUDF			BIT6	//0/R/x/x User Definable Features
    #define D0F1_R66M			BIT5	//0/R/x/x 66MHz Capability
    #define D0F1_RCAP			BIT4	//0/R/x/x Support New Capability List
    #define D0F1_RX04_19_16			0xF	//0/R/x/x Reserved
#define D0F1_REV_ID		0x08	//Revision ID
    #define D0F1_RX08_7_0			0xFF	//04h/x/x/x Revision Code
#define D0F1_CLASS_CODE		0x09	//Class Code
    #define D0F1_CLASSCODE_23_0			0xFFFFFF	//060000h/x/x/x Class Code
#define D0F1_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D0F1_RX0C_7_0			0xFF	//0/x/x/x Cache Line Size
#define D0F1_PCI_MASTER_LATENCY_TIMER		0x0D	//PCI Master Latency Timer
    #define D0F1_RX0C_15_8			0xFF	//0/R/x/x Maximum Time Slice for This Function as a Master on the PCI Bus
#define D0F1_HEADER_TYPE		0x0E	//Header Type
    #define D0F1_RX0C_23_16			0xFF	//80h/R/x/x Header Type
#define D0F1_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D0F1_RX0C_31_24			0xFF	//0/R/x/x BIST Support
#define D0F1_CARDBUS_CIS_POINTER		0x28	//CardBus CIS Pointer
    #define D0F1_RX28_31_0			0xFFFFFFFF	//0/R/x/x CardBus CIS Pointer
#define D0F1_SVID		0x2C	//Subsystem Vendor ID
    #define D0F1_RX2C_15_0			0xFFFF	//0/*/x/x Subsystem Vendor ID
#define D0F1_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D0F1_RX2C_31_16			0xFFFF	//0/*/x/x Subsystem ID
#define D0F1_POINTER		0x34	//Pointer
    #define D0F1_RX34_7_0			0xFF	//0/R/x/x Capability List Pointer
#define D0F1_RESERVED		0x35	//Reserved
    #define D0F1_RX35_7_0			0xFF	//0/R/x/x Reserved
#define D0F1_RESERVED_Z1		0x36	//Reserved
    #define D0F1_RX36_7_0			0xFF	//0/R/x/x Reserved
#define D0F1_RESERVED_Z2		0x37	//Reserved
    #define D0F1_RX37_7_0			0xFF	//0/R/x/x Reserved
#define D0F1_INTR_LINE_AND_INTR_PIN		0x3C	//Interrupt Line and Interrupt Pin
    #define D0F1_RX3C_15_8			0xFF00	//0/R/x/x Interrupt Pin
    #define D0F1_RX3C_7_0			0xFF	//0/R/x/x Interrupt Line
#define D0F1_MINIMUM_GRANT_AND_MAXIMUM_LATENCY		0x3E	//Minimum Grant and Maximum Latency
    #define D0F1_RX3C_31_24			0xFF00	//0/R/x/x Maximum Latency
    #define D0F1_RX3C_23_16			0xFF	//0/R/x/x Minimum Grant
#define D0F1_VID_Z1		0x40	//Vendor ID
    #define D0F1_RSV_D0F1_40_7_3			0xF8	//0/0/x/x Reserved
    #define D0F1_D0F1_RX40B2			BIT2	//0/x/x/x RCLASS_CODE_LOCK_D0F1
    #define D0F1_D0F1_RX40B1			BIT1	//0/x/x/x RVID_DID_LOCK_D0F1
    #define D0F1_D0F1_RX40B0			BIT0	//0/x/x/x RDID_RID_LOCK_D0F1
#define D0F1_RESERVED_Z3		0x60	//Reserved
    #define D0F1_RX60			0xFFFF	//0/R/x/x Reserved
#define D0F1_MCA_CTL_FOR_PCIE		0x62	//MCA Control for PCIe
    #define D0F1_RX62			0xFFFF	//0/R/x/x Reserved
#define D0F1_MCA_CTL_FOR_DRAMC_CHA		0x64	//MCA Control for DRAMC CHA
    #define D0F1_RDERRSITH_15_0			0xFFFF	//1FFFh/x/x/x Threshold for DRAMC CHA
#define D0F1_MCA_CTL_FOR_DRAMC_CHB		0x66	//MCA Control for DRAMC CHB
    #define D0F1_RDERRSITH_CHB_15_0			0xFFFF	//1FFFh/x/x/x Threshold for DRAMC CHB
#define D0F1_MCA_CTL_FOR_VPI		0x68	//MCA Control for VPI
    #define D0F1_RVERRSITH_15_0			0xFFFF	//1FFFh/x/x/x Threshold for VPI
#define D0F1_MCA_ERR_CNT_FOR_VPI		0x6A	//MCA ERROR CNT for VPI
    #define D0F1_RVERRSICNT_15_0			0xFFFF	//0h/x/x/x VPI Correctable Error Counter
#define D0F1_MCA_ERR_CNT_FOR_DRAMCA		0x6C	//MCA ERROR CNT for DRAMCA
    #define D0F1_RDERRSICNT_15_0			0xFFFF	//0h/x/x/x DRAMCA Correctable Error Counter
#define D0F1_MCA_ERR_CNT_FOR_DRAMCB		0x6E	//MCA ERROR CNT for DRAMCB
    #define D0F1_RDERRSICNT_CHB_15_0			0xFFFF	//0h/x/x/x DRAMCB Correctable Error Counter
#define D0F1_MCA_ERR_CNT_FOR_PCIE		0x70	//MCA ERROR CNT for PCIe
    #define D0F1_RX70			0xFFFF	//0/R/x/x Reserved
#define D0F1_SNPO_ERR_LOG_CHA		0xE4	//SNPO Error Log CHA
    #define D0F1_RSNPOAERRADDR_31_0			0xFFFFFFFF	//HwInit/x/x/x SNPO Error Address Error Log CHA
#define D0F1_SNPO_ERR_LOG_CHA_Z1		0xE8	//SNPO Error Log CHA
    #define D0F1_RSNPOAERRADDR_39_32			0xFF	//HwInit/x/x/x SNPO Error Address Error Log CHA
#define D0F1_SNPO_ERR_STA_CHA		0xE9	//SNPO Error Status CHA
    #define D0F1_RSNPOAERRSTATUS			BIT7	//0/x/x/x SNPO Address Error Status CHA
    #define D0F1_RXE9_6_3			0x78	//0/R/x/x Reserved
    #define D0F1_RSNPOERRSMIEN			BIT2	//0/x/x/x SNPO Address Error SMI Enable Bit CHA &CHB
    #define D0F1_RSNPOERRNMIEN			BIT1	//0/x/x/x SNPO Address Error NMI Enable CHA &CHB
    #define D0F1_RSNPOERRSCIEN			BIT0	//0/x/x/x SNPO Address Error SCI Enable CHA &CHB
#define D0F1_SNPO_ERR_INJECTION_CHA		0xEA	//SNPO Error Injection CHA
    #define D0F1_RSNPOAERRINJEN			BIT7	//0/x/x/x SNPO Address Error Injection Enable CHA
    #define D0F1_RXEA_6_0			0x7F	//0/R/x/x Reserved
#define D0F1_SNPO_ERR_INJECTION_CHA_Z1		0xEB	//SNPO Error Injection CHA
    #define D0F1_RSNPOAERRINJADDR_39_32			0xFF	//0/x/x/x SNPO Error Address Error Injection Data CHA
#define D0F1_SNPO_ERR_INJECTION_CHA_Z2		0xEC	//SNPO Error Injection CHA
    #define D0F1_RSNPOAERRINJADDR_31_0			0xFFFFFFFF	//0/x/x/x SNPO Error Address Error Injection Data CHA
#define D0F1_SNPO_ERR_LOG_CHB		0xF4	//SNPO Error Log CHB
    #define D0F1_RSNPOBERRADDR_31_0			0xFFFFFFFF	//HwInit/x/x/x SNPO Error Address Error Log CHB
#define D0F1_SNPO_ERR_LOG_CHB_Z1		0xF8	//SNPO Error Log CHB
    #define D0F1_RSNPOBERRADDR_39_32			0xFF	//HwInit/x/x/x SNPO Error Address Error Log CHB
#define D0F1_SNPO_ERR_STA_CHB		0xF9	//SNPO Error Status CHB
    #define D0F1_RSNPOBERRSTATUS			BIT7	//0/x/x/x SNPO Address Error Status CHB
    #define D0F1_RXF9_6_0			0x7F	//0/R/x/x Reserved
#define D0F1_SNPO_ERR_INJECTION_CHB		0xFA	//SNPO Error Injection CHB
    #define D0F1_RSNPOBERRINJEN			BIT7	//0/x/x/x SNPO Address Error Injection Enable CHB
    #define D0F1_RXFA_6_0			0x7F	//0/R/x/x Reserved
#define D0F1_SNPO_ERR_INJECTION_CHB_Z1		0xFB	//SNPO Error Injection CHB
    #define D0F1_RSNPOBERRINJADDR_39_32			0xFF	//0/x/x/x SNPO Error Address Error Injection Data CHB
#define D0F1_SNPO_ERR_INJECTION_CHB_Z2		0xFC	//SNPO Error Injection CHB
    #define D0F1_RSNPOBERRINJADDR_31_0			0xFFFFFFFF	//0/x/x/x SNPO Error Address Error Injection Data CHB
#endif
