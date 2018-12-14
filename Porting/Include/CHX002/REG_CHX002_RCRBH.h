//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_RCRB-H_R101(A0).doc(final)MOD_RCRBH.xls
#ifndef _CHX002_RCRBH_H
#define _CHX002_RCRBH_H
//RCRB-H
#define RCRBH_VIRTUAL_CHN_ENHANCED_CAP_HEADER		0x000	//Virtual Channel Enhanced Capability Header
    #define RCRBH_RX000_31_20			0xFFF00000	//040h/R/x/x Next Capability Offset
    #define RCRBH_RX000_19_16			0xF0000	//1h/R/x/x Capability Version
    #define RCRBH_RX000_15_0			0xFFFF	//0002h/R/x/x PCI Express Extended Capability ID
#define RCRBH_PORT_VC_CAP_1		0x004	//Port VC Capability 1
    #define RCRBH_RX004_31_12			0xFFFFF000	//0/x/x/x Reserved
    #define RCRBH_RX004_11_10			(BIT10 + BIT11)	//10b/R/x/x Port Arbitration Table Entry Size
    #define RCRBH_RX004_9_8			(BIT8 + BIT9)	//0/R/x/x Reference Clock
    #define RCRBH_RX004_7			BIT7	//0/x/x/x Reserved
    #define RCRBH_RLPEC_RCRBH_2_0			(BIT4 + BIT5 + BIT6)	//0/R/x/x Low Priority Extended VC Count
    #define RCRBH_RX004_3			BIT3	//0/x/x/x Reserved
    #define RCRBH_REVCC_RCRBH_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/x Extended VC Count
#define RCRBH_PORT_VC_CAP_2		0x008	//Port VC Capability 2
    #define RCRBH_RX008_31_24			0xFF000000	//0/R/x/x VC Arbitration Table
    #define RCRBH_RX008_23_8			0xFFFF00	//0/x/x/x Reserved
    #define RCRBH_RX008_7_0			0xFF	//01h/R/x/x VC Arbitration Capability
#define RCRBH_PORT_VC_CTL		0x00C	//Port VC Control
    #define RCRBH_RX00C_15_4			0xFFF0	//0/x/x/x Reserved
    #define RCRBH_RX00C_3_1			(BIT1 + BIT2 + BIT3)	//0/0/x/x VC Arbitration Select
    #define RCRBH_RX00C_0			BIT0	//0/R/x/x Load VC Arbitration Table
#define RCRBH_PORT_VC_STA		0x00E	//Port VC Status
    #define RCRBH_RX00C_31_17			0xFFFE	//0/x/x/x Reserved
    #define RCRBH_RX00C_16			BIT0	//0/R/x/x VC Arbitration Table Status
#define RCRBH_VC_RESRC_CAP_VC0		0x010	//VC Resource Capability (VC0)
    #define RCRBH_RX010_31_24			0xFF000000	//0/R/x/x Port Arbitration Table (VC0)
    #define RCRBH_RX010_23			BIT23	//0/x/x/x Reserved
    #define RCRBH_RVCAMTS0_RCRBH_6_0			0x7F0000	//0/R/x/x Maximum Time Slots (TL)
    #define RCRBH_RVCARST0_RCRBH			BIT15	//0/R/x/x Reject Snoop Transactions
    #define RCRBH_RX010_14			BIT14	//0/R/x/x Undefined 
    #define RCRBH_RX010_13_8			0x3F00	//0/x/x/x Reserved
    #define RCRBH_RX010_7_0			0xFF	//01h/R/x/x Port Arbitration Capability
#define RCRBH_VC_RESRC_CTL_VC0		0x014	//VC Resource Control (VC0)
    #define RCRBH_RVCEN0_RCRBH			BIT31	//1b/1/x/x VC Enable
    #define RCRBH_RX014_30_27			0x78000000	//0/x/x/x Reserved
    #define RCRBH_RVCID0_RCRBH_2_0			(BIT24 + BIT25 + BIT26)	//0/R/x/x VC ID
    #define RCRBH_RX014_23_20			0xF00000	//0/x/x/x Reserved
    #define RCRBH_RX014_19_17			(BIT17 + BIT18 + BIT19)	//0/0/x/x Port Arbitration Select
    #define RCRBH_RX014_16			BIT16	//0/R/x/x Load Port Arbitration Table
    #define RCRBH_RX014_15_8			0xFF00	//0/x/x/x Reserved
    #define RCRBH_RVCMAP0_RCRBH_7_1			0xFE	//7Fh/7fh/x/x TC/VC Mapping
    #define RCRBH_RVCMAP0_RCRBH_0			BIT0	//1b/R/x/x TC/VC Mapping
#define RCRBH_VC_RESRC_STA_VC0		0x018	//VC Resource Status (VC0)
    #define RCRBH_RX018_31_18			0xFFFC0000	//0/x/x/x Reserved
    #define RCRBH_VCRSNP0_RCRBH			BIT17	//0/R/x/x VC Negotiation Pending (TL)
    #define RCRBH_RX018_16			BIT16	//0/R/x/x Port Arbitration Table Status
    #define RCRBH_RX018_15_0			0xFFFF	//0/x/x/x Reserved
#define RCRBH_ROOT_COMPLEX_LINK_DECLARATION_CAPS_HEADER		0x040	//Root Complex Link Declaration Capabilities Header
    #define RCRBH_RX040_31_20			0xFFF00000	//0/R/x/x Next Capability
    #define RCRBH_RX040_19_16			0xF0000	//1h/R/x/x Capability Version
    #define RCRBH_RX040_15_0			0xFFFF	//0005h/R/x/x PCI Express Extended Capability ID
#define RCRBH_ELEMENT_SELF_DESCRIPTION		0x044	//Element Self-Description
    #define RCRBH_RRCRBH_PN_7_0			0xFF000000	//0/0/x/x Port Number
    #define RCRBH_RX044_23_16			0xFF0000	//01h/01h/x/x Component ID
    #define RCRBH_RRCRBH_NLE_7_4			0xF000	//00h/01h/x/x Number of Link Entries Bits [7:4]
    #define RCRBH_RRCRBH_NLE3			BIT11	//HwInit/1b/x/x Number of Link Entries Bits [3]
    #define RCRBH_RRCRBH_NLE2			BIT10	//HwInit/x/x/x Number of Link Entries Bit [2]
    #define RCRBH_RRCRBH_NLE1			BIT9	//HwInit/x/x/x Number of Link Entries Bit [1]
    #define RCRBH_RRCRBH_NLE0			BIT8	//HwInit/0/x/x Number of Link Entries Bit [0]
    #define RCRBH_RX044_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_RX044_3_0			0xF	//1h/01h/x/x Element Type
#define RCRBH_PE0_LINK_DESCRIPTION		0x050	//PE0 Link Description
    #define RCRBH_LKPN_PE0_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX050_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX050_15_8			0xFF00	//0/R/x/x Reserved
    #define RCRBH_RX050_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX050_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX050_1			BIT1	//1b/1/x/x Link Type 
    #define RCRBH_LINK_VALID_PE0			BIT0	//HwInit/1/x/x Link Valid
#define RCRBH_PE0_LOWER_BASE_ADR		0x058	//PE0 Lower Base Address
    #define RCRBH_RX058_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX058_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX058_19_15			0xF8000	//03h/03h/x/x Device Number 
    #define RCRBH_RX058_14_12			(BIT12 + BIT13 + BIT14)	//0/0/x/x Function Number 
    #define RCRBH_RX058_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_PE0_UPPER_BASE_ADR		0x05C	//PE0 Upper Base Address
    #define RCRBH_RX05C_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_PE1_LINK_DESCRIPTION		0x060	//PE1 Link Description
    #define RCRBH_LKPN_PE1_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX060_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX060_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX060_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX060_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX060_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_PE1			BIT0	//HwInit/x/x/x Link Valid
#define RCRBH_PE1_LOWER_BASE_ADR		0x068	//PE1 Lower Base Address
    #define RCRBH_RX068_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX068_27_20			0xFF00000	//0/0/x/x Bus Number  
    #define RCRBH_RX068_19_15			0xF8000	//03h/03h/x/x Device Number  
    #define RCRBH_RX068_14_12			(BIT12 + BIT13 + BIT14)	//001b/001b/x/x Function Number  
    #define RCRBH_RX068_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_PE1_UPPER_BASE_ADR		0x06C	//PE1 Upper Base Address
    #define RCRBH_RX06C_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_PE2_LINK_DESCRIPTION		0x070	//PE2 Link Description
    #define RCRBH_LKPN_PE2_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX070_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX070_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX070_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX070_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX070_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_PE2			BIT0	//HwInit/1/x/x Link Valid
#define RCRBH_PE2_LOWER_BASE_ADR		0x078	//PE2 Lower Base Address
    #define RCRBH_RX078_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX078_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX078_19_15			0xF8000	//03h/03h/x/x Device Number 
    #define RCRBH_RX078_14_12			(BIT12 + BIT13 + BIT14)	//010b/010b/x/x Function Number 
    #define RCRBH_RX078_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_PE2_UPPER_BASE_ADR		0x07C	//PE2 Upper Base Address
    #define RCRBH_RX07C_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_PE3_LINK_DESCRIPTION		0x080	//PE3 Link Description
    #define RCRBH_LKPN_PE3_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX080_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX080_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX080_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX080_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX080_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_PE3			BIT0	//HwInit/1/x/x Link Valid 
#define RCRBH_PE3_LOWER_BASE_ADR		0x088	//PE3 Lower Base Address
    #define RCRBH_RX088_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX088_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX088_19_15			0xF8000	//03h/03h/x/x Device Number 
    #define RCRBH_RX088_14_12			(BIT12 + BIT13 + BIT14)	//011b/011b/x/x Function Number  
    #define RCRBH_RX088_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_PE3_UPPER_BASE_ADR		0x08C	//PE3 Upper Base Address
    #define RCRBH_RX08C_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_PE4_LINK_DESCRIPTION		0x090	//PE4 Link Description
    #define RCRBH_LKPN_PE4_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX090_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX090_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX090_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX090_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX090_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_PE4			BIT0	//HwInit/x/x/x Link Valid
#define RCRBH_PE4_LOWER_BASE_ADR		0x098	//PE4 Lower Base Address
    #define RCRBH_RX098_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX098_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX098_19_15			0xF8000	//04h/04h/x/x Device Number 
    #define RCRBH_RX098_14_12			(BIT12 + BIT13 + BIT14)	//000b/0/x/x Function Number  
    #define RCRBH_RX098_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_PE4_UPPER_BASE_ADR		0x09C	//PE4 Upper Base Address
    #define RCRBH_RX09C_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_PE5_LINK_DESCRIPTION		0x0A0	//PE5 Link Description
    #define RCRBH_LKPN_PE5_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX0A0_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX0A0_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX0A0_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX0A0_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX0A0_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_PE5			BIT0	//HwInit/1/x/x Link Valid
#define RCRBH_PE5_LOWER_BASE_ADR		0x0A8	//PE5 Lower Base Address
    #define RCRBH_RX0A8_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX0A8_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX0A8_19_15			0xF8000	//04h/04h/x/x Device Number 
    #define RCRBH_RX0A8_14_12			(BIT12 + BIT13 + BIT14)	//001b/001b/x/x Function Number  
    #define RCRBH_RX0A8_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_PE5_UPPER_BASE_ADR		0x0AC	//PE5 Upper Base Address
    #define RCRBH_RX0AC_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_PE6_LINK_DESCRIPTION		0x0B0	//PE6 Link Description
    #define RCRBH_LKPN_PE6_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX0B0_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX0B0_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX0B0_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX0B0_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX0B0_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_PE6			BIT0	//HwInit/1/x/x Link Valid
#define RCRBH_PE6_LOWER_BASE_ADR		0x0B8	//PE6 Lower Base Address
    #define RCRBH_RX0B8_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX0B8_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX0B8_19_15			0xF8000	//05h/05h/x/x Device Number 
    #define RCRBH_RX0B8_14_12			(BIT12 + BIT13 + BIT14)	//000b/0/x/x Function Number  
    #define RCRBH_RX0B8_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_PE6_UPPER_BASE_ADR		0x0BC	//PE6 Upper Base Address
    #define RCRBH_RX0BC_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_PE7_LINK_DESCRIPTION		0x0C0	//PE7 Link Description
    #define RCRBH_LKPN_PE7_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX0C0_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX0C0_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX0C0_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX0C0_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX0C0_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_PE7			BIT0	//HwInit/1/x/x Link Valid
#define RCRBH_PE7_LOWER_BASE_ADR		0x0C8	//PE7 Lower Base Address
    #define RCRBH_RX0C8_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX0C8_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX0C8_19_15			0xF8000	//05h/05h/x/x Device Number 
    #define RCRBH_RX0C8_14_12			(BIT12 + BIT13 + BIT14)	//001b/001b/x/x Function Number  
    #define RCRBH_RX0C8_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_PE7_UPPER_BASE_ADR		0x0CC	//PE7 Upper Base Address
    #define RCRBH_RX0CC_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_D0F0_LINK_DESCRIPTION		0x0E0	//D0F0 Link Description
    #define RCRBH_RPORTNUM_D0F0_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX0E0_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX0E0_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX0E0_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX0E0_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX0E0_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_D0F0			BIT0	//1b/1/x/x Link Valid
#define RCRBH_D0F0_LOWER_BASE_ADR		0x0E8	//D0F0 Lower Base Address
    #define RCRBH_RX0E8_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX0E8_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX0E8_19_15			0xF8000	//00h/00h/x/x Device Number 
    #define RCRBH_RX0E8_14_12			(BIT12 + BIT13 + BIT14)	//000b/0/x/x Function Number  
    #define RCRBH_RX0E8_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_D0F0_UPPER_BASE_ADR		0x0EC	//D0F0 Upper Base Address
    #define RCRBH_RX0EC_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_D0F3_LINK_DESCRIPTION		0x0F0	//D0F3 Link Description
    #define RCRBH_RPORTNUM_D0F3_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX0F0_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX0F0_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX0F0_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX0F0_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX0F0_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_D0F3			BIT0	//1b/1/x/x Link Valid
#define RCRBH_D0F3_LOWER_BASE_ADR		0x0F8	//D0F3 Lower Base Address
    #define RCRBH_RX0F8_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX0F8_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX0F8_19_15			0xF8000	//00h/00h/x/x Device Number 
    #define RCRBH_RX0F8_14_12			(BIT12 + BIT13 + BIT14)	//011b/011b/x/x Function Number  
    #define RCRBH_RX0F8_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_D0F3_UPPER_BASE_ADR		0x0FC	//D0F3 Upper Base Address
    #define RCRBH_RX0FC_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_D0F5_LINK_DESCRIPTION		0x100	//D0F5 Link Description
    #define RCRBH_RPORTNUM_D0F5_7_0			0xFF000000	//HwInit/x/x/x Target Port Number
    #define RCRBH_RX100_23_16			0xFF0000	//01h/01h/x/x Target Component ID
    #define RCRBH_RX100_15_8			0xFF00	//0/0/x/x Reserved
    #define RCRBH_RX100_7_3			0xF8	//0/0/x/x Reserved
    #define RCRBH_RX100_2			BIT2	//0/0/x/x Associate RCRB Header
    #define RCRBH_RX100_1			BIT1	//1b/1/x/x Link Type
    #define RCRBH_LINK_VALID_D0F5			BIT0	//1b/1/x/x Link Valid
#define RCRBH_D0F5_LOWER_BASE_ADR		0x108	//D0F5 Lower Base Address
    #define RCRBH_RX108_31_28			0xF0000000	//0/0/x/x Reserved
    #define RCRBH_RX108_27_20			0xFF00000	//0/0/x/x Bus Number 
    #define RCRBH_RX108_19_15			0xF8000	//00h/00h/x/x Device Number 
    #define RCRBH_RX108_14_12			(BIT12 + BIT13 + BIT14)	//101b/101b/x/x Function Number  
    #define RCRBH_RX108_11_0			0xFFF	//0/0/x/x Reserved
#define RCRBH_D0F5_UPPER_BASE_ADR		0x10C	//D0F5 Upper Base Address
    #define RCRBH_RX10C_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define RCRBH_PE0_OCCUPANCY_TIMER		0x210	//PE0 Occupancy Timer
    #define RCRBH_RX210_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0P0OCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_PE0_PROMOTE_TIMER		0x211	//PE0 Promote Timer
    #define RCRBH_RX210_15_12			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0P0PMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_PE1_OCCUPANCY_TIMER		0x212	//PE1 Occupancy Timer
    #define RCRBH_RX210_23_20			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0P1OCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_PE1_PROMOTE_TIMER		0x213	//PE1 Promote Timer
    #define RCRBH_RX210_31_28			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0P1PMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_PE2_OCCUPANCY_TIMER		0x214	//PE2 Occupancy Timer
    #define RCRBH_RX214_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0P2OCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_PE2_PROMOTE_TIMER		0x215	//PE2 Promote Timer
    #define RCRBH_RX214_15_12			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0P2PMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_PE3_OCCUPANCY_TIMER		0x216	//PE3 Occupancy Timer
    #define RCRBH_RX214_23_20			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0P3OCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_PE3_PROMOTE_TIMER		0x217	//PE3 Promote Timer
    #define RCRBH_RX214_31_28			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0P3PMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_PE4_OCCUPANCY_TIMER		0x218	//PE4 Occupancy Timer
    #define RCRBH_RX218_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PE4OCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_PE4_PROMOTE_TIMER		0x219	//PE4 Promote Timer
    #define RCRBH_RX219_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PE4PMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_PE5_OCCUPANCY_TIMER		0x21A	//PE5 Occupancy Timer
    #define RCRBH_RX21A_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PE5OCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_PE5_PROMOTE_TIMER		0x21B	//PE5 Promote Timer
    #define RCRBH_RX21B_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PE5PMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_HOST_OCCUPANCY_TIMER		0x21C	//Host Occupancy Timer
    #define RCRBH_RX21C_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_HOSTOCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_HOST_PROMOTE_TIMER		0x21D	//Host Promote Timer
    #define RCRBH_RX21D_15_12			0xF0	//0/x/x/x Reserved
    #define RCRBH_HOSTPMTM_3_0			0xF	//8h/8h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_RESERVED		0x21E	//Reserved
    #define RCRBH_RX21E			0xFFFF	//0/x/x/x Reserved
#define RCRBH_PCIE_VC0_OCCUPANCY_TIMER		0x230	//PCIe VC0 Occupancy Timer
    #define RCRBH_RHPE1SPRI			BIT7	//1b/1b/x/x PCIe High Priority Request Support
    #define RCRBH_RX230_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define RCRBH_UFPEOCTM_3_0			0xF	//0/0/0/x Occupancy Timer (In Unit of Host Frequency)
#define RCRBH_PCIE_VC0_PROMOTE_TIMER		0x231	//PCIe VC0 Promote Timer
    #define RCRBH_RX230_15_12			0xF0	//0/x/x/x Reserved
    #define RCRBH_UFPEPMTM_3_0			0xF	//0/0/0/x Promote Timer (In Unit of Host Frequency)
#define RCRBH_RESERVED_Z1		0x232	//Reserved
    #define RCRBH_RX232_15_0			0xFFFF	//0/x/x/x Reserved
#define RCRBH_GFX_OCCUPANCY_TIMER		0x238	//GFX Occupancy Timer
    #define RCRBH_RGADSH			BIT7	//0/0/1/x Strict Priority to GADS from IGFX
    #define RCRBH_RX238_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define RCRBH_UFGMOCTM_3_0			0xF	//0/0/x/x GFX Occupancy Timer (In Unit of Host Frequency)
#define RCRBH_GFX_PROMOTE_TIMER		0x239	//GFX Promote Timer
    #define RCRBH_RX238_15_12			0xF0	//0/x/x/x Reserved
    #define RCRBH_UFGMPMTM_3_0			0xF	//0/0/x/x GFX Promote Timer (In Unit of Host Frequency)
#define RCRBH_RESERVED_Z2		0x23A	//Reserved
    #define RCRBH_RX23A_15_0			0xFFFF	//0/x/x/x Reserved
#define RCRBH_PE6_OCCUPANCY_TIMER		0x240	//PE6 Occupancy Timer
    #define RCRBH_RX240_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PE6OCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_PE6_PROMOTE_TIMER		0x241	//PE6 Promote Timer
    #define RCRBH_RX241_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PE6PMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_PE7_OCCUPANCY_TIMER		0x242	//PE7 Occupancy Timer
    #define RCRBH_RX242_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PE7OCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_PE7_PROMOTE_TIMER		0x243	//PE7 Promote Timer
    #define RCRBH_RX243_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PE7PMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_MISC_0		0x260	//Misc 0
    #define RCRBH_RX260_7_3			0xF8	//0/x/x/x Reserved
    #define RCRBH_R_PEMCU_ACCESS_ALL			BIT2	//0/x/x/x Reserved
    #define RCRBH_RPE4DBG_PEXC			BIT1	//0/x/x/x PE4 Support NBDC
    #define RCRBH_RPE0DBG_PEXC			BIT0	//0/x/x/x PE0 Support NBDC
#define RCRBH_TA_UPSTREAM_POST_REQ_OCCUPANCY_TIMER		0x280	//TA upstream Post Request Occupancy Timer
    #define RCRBH_RX280_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_UPATPOCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of Host Frequency)
#define RCRBH_TA_UPSTREAM_POST_REQ_PROMOTE_TIMER		0x281	//TA Upstream post Request Promote Timer
    #define RCRBH_RX281_15_12			0xF0	//0/x/x/x Reserved
    #define RCRBH_UPATPPMTM_3_0			0xF	//8h/8h/x/x Promote Timer (In Unit of Host Frequency)
#define RCRBH_TA_UPSTREAM_NON_POST_REQ_OCCUPANCY_TIMER		0x282	//TA upstream Non-Post Request Occupancy Timer
    #define RCRBH_RX282_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_UPATNPOCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of Host Frequency)
#define RCRBH_TA_UPSTREAM_NON_POST_REQ_PROMOTE_TIMER		0x283	//TA Upstream Non-post Request Promote Timer
    #define RCRBH_RX283_15_12			0xF0	//0/x/x/x Reserved
    #define RCRBH_UPATNPPMTM_3_0			0xF	//8h/8h/x/x Promote Timer (In Unit of Host Frequency)
#define RCRBH_TA_UPSTREAM_TRANSLATION_REQ_OCCUPANCY_TIMER		0x284	//TA upstream Translation Request Occupancy Timer
    #define RCRBH_RX284_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_UPATSOCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of Host Frequency)
#define RCRBH_TA_UPSTREAM_TRANSLATION_REQ_PROMOTE_TIMER		0x285	//TA Upstream Translation Request Promote Timer
    #define RCRBH_RX285_15_12			0xF0	//0/x/x/x Reserved
    #define RCRBH_UPATSPMTM_3_0			0xF	//8h/8h/x/x Promote Timer (In Unit of Host Frequency)
#define RCRBH_TA_UPSTREAM_TRANSLATION_REQ_PROMOTE_TIMER_Z1		0x286	//TA Upstream Translation Request Promote Timer
    #define RCRBH_RSV_286			0xFFFF	//0/x/x/x Reserved
#define RCRBH_PCIE_ARBITRATION_CTL_PEARB_DYNAMIC_CLK_ENABLE		0x290	//PCIE Arbitration Control PEARB Dynamic Clock Enable
    #define RCRBH_RDISP2PZLW			BIT7	//1b/1/x/x Downstream ZLW Control in PEARB
    #define RCRBH_RARBDYNPM			BIT6	//0/0/1/1 FACLK ENABLE in PEARB
    #define RCRBH_RARBDYNPMUP			BIT5	//0/0/1/1 Upstream FACLK ENABLE in PEARB
    #define RCRBH_RARBDYNPMDN			BIT4	//0/0/1/1 Downstream FACLK ENABLE in PEARB
    #define RCRBH_RSV_287			(BIT1 + BIT2 + BIT3)	//0/0/X/x Reserved
    #define RCRBH_RTOTESTEN			BIT0	//0/0/x/x Reserved
#define RCRBH_ATS_INVALIDATE_TIMEOUT_CTL		0x291	//ATS Invalidate Timeout Control
    #define RCRBH_RSV_288			0xFC	//0/x/x/x Reserved
    #define RCRBH_RDNCFGNFLUSH			BIT1	//0/0/x/x When the Reg Enable Downstream Read CFG Cycle, Do Not Flush Downstream Write Cycle.
    #define RCRBH_RARBDYNPMAT			BIT0	//0/0/1/1 FACLK for TACTL Module ENABLE in PEARB
#define RCRBH_ATS_INVALIDATE_TIMEOUT_CTL_Z1		0x292	//ATS Invalidate Timeout Control
    #define RCRBH_RMSGINVTOV			0xFF	//40h/40h/x/x ATS Invalidate Timeout Control
#define RCRBH_RESERVED_Z3		0x293	//Reserved
    #define RCRBH_RX293_7_0			0xFF	//0/x/x/x Reserved
#define RCRBH_C2P_RESERVE_TID_ABORT_ENABLE_AND_ISO_EN_AND_ISO_LOCK_ARBITRATION_AND_C2P_NP_PIPE_AND_P2P_ABNORMAL_CYCLE		0x29A	//C2P Reserve TID Abort Enable and ISO EN and ISO Lock Arbitration and C2P NP PIPE and P2P Abnormal Cycle
    #define RCRBH_RX295_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define RCRBH_PEARB_PERF_EN			BIT5	//0/0/1b/x PEARB Upstream Read Performance Option
    #define RCRBH_C2P_REVIDPOP_EN			BIT4	//0/0/x/x C2P Reserved TID Abort
    #define RCRBH_PEARB_ISOEN			BIT3	//1b/1b/X/x PEARB ISO Arbitration Enable in PEARB1
    #define RCRBH_ISOLOCK			BIT2	//0/0/x/x ISO cycle is locked or not in PEARB
    #define RCRBH_TXC2PNPPIPE			BIT1	//1b/1b/x/x C2P NP Cycle Pipe or Not
    #define RCRBH_PEARB_P2SELF_EN			BIT0	//0/0/x/x P2P Abnormal Control
#define RCRBH_C2PCIECFG_OCCUPANCY_TIMER		0x29B	//C2PCIECFG Occupancy Timer
    #define RCRBH_RX29B_7_4			0xF0	//0/x/x/x Reserved
    #define RCRBH_V0PCIECFGCPLOCTM_3_0			0xF	//8h/8h/x/x Occupancy Timer (In Unit of 125MHz)
#define RCRBH_ARBITRATION_CLK_ENABLE_C2PCIECFG_PROMOTE_TIMER		0x29C	//Arbitration Clock Enable & C2PCIECFG Promote Timer
    #define RCRBH_RDYNPMUPWARB			BIT7	//0/0/1/1 PEARB upstream normal write cycle arbitration dynamic clock enable
    #define RCRBH_RDYNPMUPRARB			BIT6	//0/0/1/1 PEARB upstream normal read cycle arbitration dynamic clock enable
    #define RCRBH_RDYNPMATSARB			BIT5	//0/0/1/1 PEARB upstream ATS cycle and INV CPL arbitration dynamic clock enable
    #define RCRBH_RDYNPMDNNPARB			BIT4	//0/0/1/1 PEARB downstream NP cycle CPL arbitration dynamic clock enable
    #define RCRBH_V0PCIECFGCPLPMTM_3_0			0xF	//4h/4h/x/x Promote Timer (In Unit of 125MHz)
#define RCRBH_UPSTREAM_ISO_TIME_OUT_TIMER_PEARB_C2P_PIPE_CTL		0x29D	//Upstream ISO Time-out Timer & PEARB C2P PIPE Control
    #define RCRBH_RX29D_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define RCRBH_PEARB_TXC2PNPPIPE			BIT5	//1b/1b/x/x PEARB C2P NP Cycle Pipe or not
    #define RCRBH_ISOTIMOUT_4_0			0x1F	//8h/8h/x/x Upstream ISO Time-out Timer (In Unit of 125MHz)
#define RCRBH_UPSTREAM_ISO_CLEAR_TIMER		0x29E	//Upstream ISO Clear Timer
    #define RCRBH_RX29E_7_5			(BIT5 + BIT6 + BIT7)	//0/x/x/X Reserved
    #define RCRBH_ISOTIMCLR_4_0			0x1F	//Ch/ch/x/x Upstream ISO Clear Timer (In Unit of 125MHz) 
#define RCRBH_RESERVED_Z4		0x29F	//Reserved
    #define RCRBH_RX29F_7_0			0xFF	//0/x/x/X Reserved
#define RCRBH_PCIE_ROOT_PORT_ERR_STA		0x2A0	//PCIE Root Port Error Status
    #define RCRBH_PE_ERR			BIT7	//0/0/x/x PCIe Root Port Error Detected
    #define RCRBH_RSV_2A0			0x7F	//0/x/x/x Reserved
#define RCRBH_PCIE_ROOT_PORT_ERR_CTL		0x2A1	//PCIe Root Port Error control
    #define RCRBH_RPEERREN			BIT7	//0/0/0/0 Reserved
    #define RCRBH_RX2A1_6_4			(BIT5 + BIT6)	//0/x/x/x Reserved
    #define RCRBH_RPEEIEN			BIT4	//0/0/0/0 PCIe Hard Error Injection Enable
    #define RCRBH_RPEEIEN_SEL_3_0			0xF	//0/0/x/x Root Port Selections for PCIe Hard Error Injection
#define RCRBH_RESERVED_Z5		0x2A2	//Reserved
    #define RCRBH_RSV_2A2			0xFFFF	//0/x/x/x Reserved
#define RCRBH_PCIE_HARD_ERR_INJECTION_TRIGGER_REGS		0x2A4	//PCIe Hard Error Injection Trigger Registers
    #define RCRBH_RX2A4_31_29			(BIT29 + BIT30 + BIT31)	//0/x/x/x Reserved
    #define RCRBH_ERR_FATAL_EI			BIT28	//0/0/x/x Trigger ERR_FATAL Message Injection
    #define RCRBH_ERR_NONFATAL_EI			BIT27	//0/0/x/x Trigger ERR_NONFATAL Message Injection
    #define RCRBH_ERR_COR_EI			BIT26	//0/0/x/x Trigger ERR_COR Message Injection
    #define RCRBH_RX2A4_25_23			(BIT23 + BIT24 + BIT25)	//0/x/x/x Reserved
    #define RCRBH_RPLTMO_EI			BIT22	//0/0/x/0 Trigger Replay Timeout Error Injection
    #define RCRBH_RX2A4_21			BIT21	//0/x/x/x Reserved
    #define RCRBH_RPLNUMRO_EI			BIT20	//0/0/x/x Trigger REPLAY NUM Rollover Error Injection
    #define RCRBH_BADDLLP_EI			BIT19	//0/0/x/x Trigger Bad DLLPError Injection
    #define RCRBH_BADTLP_EI			BIT18	//0/0/x/x Trigger Bad TLPError Injection
    #define RCRBH_RX2A4_17			BIT17	//0/x/x/x Reserved
    #define RCRBH_RCVERR_EI			BIT16	//0/0/x/x Trigger Receiver Error Injection
    #define RCRBH_RX2A4_15_14			(BIT14 + BIT15)	//0/x/x/x Reserved
    #define RCRBH_UR_EI			BIT13	//0/0/x/x Trigger Unsupported Request Error Injection
    #define RCRBH_RX2A4_12			BIT12	//0/x/x/x Reserved
    #define RCRBH_MFTLP_EI			BIT11	//0/0/x/x Trigger Malformed TLPError Injection
    #define RCRBH_RCVO_EI			BIT10	//0/0/x/x Trigger Receiver Overflow Error Injection
    #define RCRBH_UNCPL_EI			BIT9	//0/0/x/x Trigger Unexpected Completion Error Injection
    #define RCRBH_CPLA_EI			BIT8	//0/0/x/x Trigger Completer Abort Error Injection
    #define RCRBH_CPLTMO_EI			BIT7	//0/0/x/x Trigger Completion Timeout Error Injection
    #define RCRBH_FCPE_EI			BIT6	//0/0/x/x Trigger Flow Control Protocol Error Injection
    #define RCRBH_POISONTLP_EI			BIT5	//0/0/x/x Trigger Poisoned TLP Received Error Injection
    #define RCRBH_RX2A4_4			BIT4	//0/x/x/x Reserved
    #define RCRBH_SDN_EI			BIT3	//0/0/x/x Trigger Surprise Down Error Injection
    #define RCRBH_DLLPE_EI			BIT2	//0/0/x/x Trigger Data Link Layer Protocol Error Injection
    #define RCRBH_RX2A4_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define RCRBH_TLP_HEADER_REGS_1ST_DW_FOR_PCIE_HARD_ERR_INJECTION		0x2A8	//TLP Header Registers 1st DW for PCIe Hard Error injection
    #define RCRBH_TLPHDR0_EI_31_0			0xFFFFFFFF	//0/0/x/x TLP Header Registers the first DW (Byte0 - Byte3) for PCIe Hard Error Injection
#define RCRBH_TLP_HEADER_REGS_2ND_DW_FOR_PCIE_HARD_ERR_INJECTION		0x2AC	//TLP Header Registers 2nd DW for PCIe Hard Error injection
    #define RCRBH_TLPHDR1_EI_31_0			0xFFFFFFFF	//0/0/x/x TLP Header Registers the second DW (Byte4 - Byte7) for PCIe Hard Error Injection
#define RCRBH_TLP_HEADER_REGS_3RD_DW_FOR_PCIE_HARD_ERR_INJECTION		0x2B0	//TLP Header Registers 3rd DW for PCIe Hard Error Injection
    #define RCRBH_TLPHDR2_EI_31_0			0xFFFFFFFF	//0/0/x/x TLP Header Registers the Third DW(Byte8 - Byte11) for PCIe Hard Error Injection
#define RCRBH_TLP_HEADER_REGS_4TH_DW_FOR_PCIE_HARD_ERR_INJECTION		0x2B4	//TLP Header Registers 4th DW for PCIe Hard Error Injection
    #define RCRBH_TLPHDR3_EI_31_0			0xFFFFFFFF	//0/0/x/x TLP Header Registers the Fourth DW(Byte12-Byte15) for PCIe Hard Error Injection
#endif

