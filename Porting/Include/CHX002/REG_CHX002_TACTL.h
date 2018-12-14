//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		TACTL_RCRBV					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_TACTL_RCRB-V_R100.doc(final)MOD_TA.xls
#ifndef _CHX002_TACTL_RCRBV_H
#define _CHX002_TACTL_RCRBV_H
//TACTL
#define TACTL_VER_REG		0x00	//Version Register
    #define TACTL_RX00_31_8			0xFFFFFF00	//0h/R/x/x Reserved
    #define TACTL_RTAMAXVERS			0xF0	//1h/1h/x/x MAX: Major Version Number
    #define TACTL_RTAMINVERS			0xF	//0h/0h/x/x MIN: Minor Version Number
#define TACTL_CAP_REG		0x08	//Capability Register
    #define TACTL_RFRO_7_0			0xFF000000	//10h/10h/x/x FRO: Fault-recording Register Offset
    #define TACTL_RISOCH			BIT23	//0b/0b/x/x ISOCH: Isochrony
    #define TACTL_RZLR			BIT22	//0b/0b/x/x ZLR: Zero Length Read
    #define TACTL_RMGAW_5_0			0x3F0000	//26h/26h/x/x MGAW: Maximum Guest Address Width
    #define TACTL_RX08_15_13			(BIT13 + BIT14 + BIT15)	//000b/000b/x/x Reserved
    #define TACTL_RSAGAW_4_0			0x1F00	//02h/02h/x/x SAGAW: Supported Adjusted Guest Address Widths
    #define TACTL_RTACM			BIT7	//0b/0b/x/x CM: Caching Mode
    #define TACTL_RPHMR			BIT6	//1b/1b/x/x PHMR: Protected High-Memory Region
    #define TACTL_RPLMR			BIT5	//1b/1b/x/x PLMR: Protected Low-Memory Region
    #define TACTL_RRWBF			BIT4	//0b/0b/x/x RWBF: Required Write-Buffer Flushing
    #define TACTL_RAFL			BIT3	//0b/0b/x/x AFL: Advanced Fault Logging
    #define TACTL_RTAND_2_0			(BIT0 + BIT1 + BIT2)	//010b/010b/x/x ND: Number of Domains Supported
#define TACTL_CAP_REG_Z1		0x0C	//Capability Register
    #define TACTL_RX0C_31_24			0xFF000000	//0h/R/x/x Reserved
    #define TACTL_RDRDS			BIT23	//1b/1b/x/x DRD: DMA Read Draining
    #define TACTL_RDWDS			BIT22	//1b/1b/x/x DWD: DMA Write Draining
    #define TACTL_RMAMV_5_0			0x3F0000	//09h/09h/x/x MAMV: Maximum Address Mask Value
    #define TACTL_RNFR_7_0			0xFF00	//07h/07h/x/x NFR: Number of Fault- recording Registers
    #define TACTL_RPSI			BIT7	//1b/1b/x/x PSI: Page Selective Invalidation
    #define TACTL_RX0C_6			BIT6	//0b/R/x/x Reserved
    #define TACTL_RSPS_3_0			0x3C	//0h/0h/x/x SPS: Super-Page Support
    #define TACTL_RFRO_9_8			(BIT0 + BIT1)	//00b/00b/x/x FRO: Fault-recording Register Offset
#define TACTL_EXTENDED_CAP_REG		0x10	//Extended Capability Register
    #define TACTL_RX10_31_24			0xFF000000	//0h/R/x/x Reserved
    #define TACTL_RMHMV			0xF00000	//Fh/Fh/x/x MHMV: Maximum Handle Mask Value
    #define TACTL_RX10_19_18			(BIT18 + BIT19)	//00b/R/x/x Reserved
    #define TACTL_RIRO			0x3FF00	//20h/20h/x/x IRO: IOTLB Register Offset
    #define TACTL_RSC			BIT7	//1b/1b/x/x SC: Snoop Control
    #define TACTL_RPT			BIT6	//1b/1b/x/x PT: Pass Through
    #define TACTL_RX10_5			BIT5	//0b/R/x/x Reserved
    #define TACTL_REIM			BIT4	//0b/0b/x/x EIM: Extended Interrupt Mode
    #define TACTL_RTAIR			BIT3	//1b/1b/x/x IR: Interrupt Remapping Support
    #define TACTL_RTADI			BIT2	//1b/1b/x/x DI: Device IOTLB support
    #define TACTL_RTAQI			BIT1	//1b/1b/x/x QI: Queued Invalidation support
    #define TACTL_RTAC			BIT0	//1b/1b/x/x C: Coherency
#define TACTL_EXTENDED_CAP_REG_Z1		0x14	//Extended Capability Register
    #define TACTL_RX14_31_0			0xFFFFFFFF	//0h/R/x/x Reserved
#define TACTL_GLOBAL_CMD_REG		0x18	//Global Command Register
    #define TACTL_RTATE			BIT31	//0b/0b/x/x TE: Translation Enable
    #define TACTL_RTARTP			BIT30	//0b/0b/x/x SRTP: Set Root Table Pointer
    #define TACTL_RSFL			BIT29	//0b/0b/x/x SFL: Set Fault Log
    #define TACTL_REAFL			BIT28	//0b/0b/x/x EAFL: Enable Advanced Fault Logging
    #define TACTL_RTAWBF			BIT27	//0b/0b/x/x WBF: Write Buffer Flush
    #define TACTL_RTAQIE			BIT26	//0b/0b/x/x QIE: Queued Invalidation Enable
    #define TACTL_RTAIRE			BIT25	//0b/0b/x/x IRE: Interrupt Remapping Enable
    #define TACTL_RTAIRTP			BIT24	//0b/0b/x/x SIRTP: Set Interrupt Remap Table Pointer
    #define TACTL_RTACFI			BIT23	//0b/0b/x/x CFI: Compatibility Format Interrupt
    #define TACTL_RX18_22_0			0x7FFFFF	//0/0/x/x Reserved
#define TACTL_GLOBAL_STA_REG		0x1C	//Global Status Register
    #define TACTL_RTATES			BIT31	//HwInit/0/x/x TES: Translation Enable Status
    #define TACTL_RTARTPS			BIT30	//HwInit/0/x/x RTPS: Root Table Pointer Status
    #define TACTL_RTAFLS			BIT29	//HwInit/0/x/x FLS: Fault Log Status
    #define TACTL_RTAAFLS			BIT28	//HwInit/0/x/x AFLS: Advanced Fault Logging Status
    #define TACTL_RTAWBFS			BIT27	//HwInit/0/x/x WBFS: Write Buffer Flush Status
    #define TACTL_RTAQIES			BIT26	//HwInit/0/x/x QIES: Queued Invalidation Enable Status
    #define TACTL_RTAIRES			BIT25	//HwInit/0/x/x IRES: Interrupt Remapping Enable Status
    #define TACTL_RTAIRTPS			BIT24	//HwInit/0/x/x IRTPS: Interrupt Remapping Table Pointer Status
    #define TACTL_RTACFIS			BIT23	//HwInit/0/x/x CFIS: Compatibility Format Interrupt Status
    #define TACTL_RX1C_22_0			0x7FFFFF	//0h/0h/x/x Reserved
#define TACTL_ROOT_ENTRY_TABLE_ADR_REG		0x20	//Root-Entry Table Address Register
    #define TACTL_RTARTA_31_12			0xFFFFF000	//0h/0h/x/x RTA: Root Table Address
    #define TACTL_RX24_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_ROOT_ENTRY_TABLE_ADR_REG_Z1		0x24	//Root-Entry Table Address Register
    #define TACTL_RTARTA_63_32			0xFFFFFFFF	//0h/0h/x/x RTA: Root Table Address
#define TACTL_CONTEXT_CMD_REG		0x28	//Context Command Register
    #define TACTL_RTASID_15_0			0xFFFF0000	//0h/0h/x/x SID: Source-ID
    #define TACTL_RTADID_15_0			0xFFFF	//0h/0h/x/x DID: Domain-ID
#define TACTL_CONTEXT_CMD_REG_Z1		0x2C	//Context Command Register
    #define TACTL_RTAICC			BIT31	//0/0/x/x ICC: Invalidate Context-Cache
    #define TACTL_RTACIRG_1_0			(BIT29 + BIT30)	//00b/00b/x/x CIRG: Context Invalidation Request Granularity
    #define TACTL_RTACAIG_1_0			(BIT27 + BIT28)	//HwInit/00b/x/x CAIG: Context Actual Invalidation Granularity
    #define TACTL_RX2C_26_2			0x7FFFFFC	//0h/0h/x/x Reserved
    #define TACTL_RTAFM_1_0			(BIT0 + BIT1)	//00b/00b/x/x FM: Function Mask
#define TACTL_RESERVED		0x30	//Reserved
    #define TACTL_RX30_31_0			0xFFFFFFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_STA_REG		0x34	//Fault Status Register
    #define TACTL_RX34_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRI_7_3			0xF800	//0h/x/x/x FRI: Fault Record Index
    #define TACTL_RTAFRI_2_0			(BIT8 + BIT9 + BIT10)	//000b/x/x/x FRI: Fault Record Index
    #define TACTL_RX34_7			BIT7	//0b/0b/x/x Reserved
    #define TACTL_RTAITE			BIT6	//0b/0b/x/x ITE: Invalidation Time-out Error
    #define TACTL_RTAICE			BIT5	//0b/0b/x/x ICE: Invalidation Completion Error
    #define TACTL_RTAIQE			BIT4	//0b/0b/x/x IQE: Invalidation Queue Error
    #define TACTL_RX34_3			BIT3	//0b/0b/x/x Reserved
    #define TACTL_RX34_2			BIT2	//0b/0b/x/x Reserved
    #define TACTL_RTAPPF			BIT1	//0b/x/x/x PPF: Primary Pending Fault
    #define TACTL_RTAPFO			BIT0	//0b/0b/x/x PFO: Fault Overflow
#define TACTL_FAULT_EVENT_CTL_REG		0x38	//Fault Event Control Register
    #define TACTL_RTAIM			BIT31	//1b/1b/x/x IM: Interrupt Mask
    #define TACTL_RTAIP_I			BIT30	//HwInit/0b/x/x IP: Interrupt Pending
    #define TACTL_RX38_29_0			0x3FFFFFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_EVENT_DATA_REG		0x3C	//Fault Event Data Register
    #define TACTL_RX3C_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAIMD_15_0			0xFFFF	//0h/0h/x/X IMD: Interrupt Message data
#define TACTL_FAULT_EVENT_ADR_REG		0x40	//Fault Event Address Register
    #define TACTL_RTAMA_31_2			0xFFFFFFFC	//0h/0h/x/x MA: Message address
    #define TACTL_RX40_1_0			(BIT0 + BIT1)	//00b/00b/x/x Reserved
#define TACTL_FAULT_EVENT_UPPER_ADR_REG		0x44	//Fault Event Upper Address Register
    #define TACTL_RX44_31_0			0xFFFFFFFF	//0h/0h/x/x Reserved
#define TACTL_PROTECTED_MEM_ENABLE_REG		0x64	//Protected Memory Enable Register
    #define TACTL_RTAEPM			BIT31	//0b/0b/x/x EPM: Enable Protected Memory
    #define TACTL_RX64_30_1			0x7FFFFFFE	//0h/0h/x/x Reserved
    #define TACTL_RTAPRS			BIT0	//HwInit/0b/x/x PRS: Protected Region Status
#define TACTL_PROTECTED_LOW_MEM_BASE_REG		0x68	//Protected Low-Memory Base Register
    #define TACTL_RTAPLMB_31_20			0xFFF00000	//0h/0h/x/x PLMB: Protected Low-Memory Base
    #define TACTL_RX68_19_0			0xFFFFF	//0h/0h/x/x Reserved
#define TACTL_PROTECTED_LOW_MEM_LIMIT_REG		0x6C	//Protected Low-Memory Limit Register
    #define TACTL_RTAPLML_31_20			0xFFF00000	//0h/0h/x/x PLML: Protected Low-Memory Limit
    #define TACTL_RX6C_19_0			0xFFFFF	//0h/0h/x/x Reserved
#define TACTL_PROTECTED_HIGH_MEM_BASE_REG		0x70	//Protected High-Memory Base Register
    #define TACTL_RTAPHMB_31_20			0xFFF00000	//0h/0h/x/x PHMB: Protected High-Memory Base
    #define TACTL_RX70_19_0			0xFFFFF	//0h/0h/x/x Reserved
#define TACTL_PROTECTED_HIGH_MEM_BASE_REG_Z1		0x74	//Protected High-Memory Base Register
    #define TACTL_RTAPHMB_63_32			0xFFFFFFFF	//0h/0h/x/x PHMB: Protected High-Memory Base
#define TACTL_PROTECTED_HIGH_MEM_LIMIT_REG		0x78	//Protected High-Memory Limit Register
    #define TACTL_RTAPHML_31_20			0xFFF00000	//0h/0h/x/x PHML: Protected High-Memory Limit
    #define TACTL_RX78_19_0			0xFFFFF	//0h/0h/x/x Reserved
#define TACTL_PROTECTED_HIGH_MEM_LIMIT_REG_Z1		0x7C	//Protected High-Memory Limit Register
    #define TACTL_RTAPHML_63_32			0xFFFFFFFF	//0h/0h/x/x PHML: Protected High-Memory Limit
#define TACTL_INVALIDATION_QUEUE_HEAD_REG		0x80	//Invalidation Queue Head Register
    #define TACTL_RX80_31_19			0xFFF80000	//0h/0h/x/x Reserved
    #define TACTL_RTAQH_14_0_I			0x7FFF0	//HwInit/0h/x/x QH: Queue Head
    #define TACTL_RX80_3_0			0xF	//0h/0h/x/x Reserved
#define TACTL_INVALIDATION_QUEUE_HEAD_REG_Z1		0x84	//Invalidation Queue Head Register
    #define TACTL_RX84_31_0			0xFFFFFFFF	//0h/0h/x/x Reserved
#define TACTL_INVALIDATION_QUEUE_TAIL_REG		0x88	//Invalidation Queue Tail Register
    #define TACTL_RX88_31_19			0xFFF80000	//0h/0h/x/x Reserved
    #define TACTL_RTAQT_14_0			0x7FFF0	//0h/0h/x/x QT: Queue Tail
    #define TACTL_RX88_3_0			0xF	//0h/0h/x/x Reserved
#define TACTL_INVALIDATION_QUEUE_TAIL_REG_Z1		0x8C	//Invalidation Queue Tail Register
    #define TACTL_RX8C_31_0			0xFFFFFFFF	//0h/0h/x/x Reserved
#define TACTL_INVALIDATION_QUEUE_ADR_REG		0x90	//Invalidation Queue Address Register
    #define TACTL_RTAIQA_31_12			0xFFFFF000	//0h/0h/x/x IQA: InvalidatioQueue Base Address 
    #define TACTL_RX90_11_3			0xFF8	//0h/0h/x/x Reserved
    #define TACTL_RTAQS_2_0			(BIT0 + BIT1 + BIT2)	//000b/000b/x/x QS: Queue Size
#define TACTL_INVALIDATION_QUEUE_ADR_REG_Z1		0x94	//Invalidation Queue Address Register
    #define TACTL_RTAIQA_63_32			0xFFFFFFFF	//0h/0h/x/x IQA: InvalidatioQueue Base Address 
#define TACTL_INVALIDATION_COMPLETION_STA_REG		0x9C	//Invalidation Completion status Register
    #define TACTL_RX9C_31_1			0xFFFFFFFE	//0h/0h/x/x Reserved
    #define TACTL_RTAIWC			BIT0	//0b/0b/x/x IWC: Invalidation Wait Descriptor Complete
#define TACTL_INVALIDATION_EVENT_CTL_REG		0xA0	//Invalidation Event Control Register
    #define TACTL_RTAIVLDIM			BIT31	//1b/1b/x/x IM: Interrupt Mask
    #define TACTL_RTAIVLDIP_I			BIT30	//HwInit/0b/x/x IP: Interrupt Pending
    #define TACTL_RXA0_29_0			0x3FFFFFFF	//0h/0h/x/x Reserved
#define TACTL_INVALIDATION_EVENT_DATA_REG		0xA4	//Invalidation Event Data Register
    #define TACTL_RXA4_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAIVLDIMD_15_0			0xFFFF	//0h/0h/x/x IMD: Interrupt Message Data
#define TACTL_INVALIDATION_EVENT_ADR_REG		0xA8	//Invalidation Event Address Register
    #define TACTL_RTAIVLDMA_31_2			0xFFFFFFFC	//0h/0h/x/x MA: Message address
    #define TACTL_RXA8_1_0			(BIT0 + BIT1)	//00b/00b/x/x Reserved
#define TACTL_INTR_REMAPPING_TABLE_ADR_REG		0xB8	//Interrupt Remapping Table Address Register
    #define TACTL_RTAIRTA_31_12			0xFFFFF000	//0h/0h/x/x IRTA: Interrupt Remapping Table Address
    #define TACTL_RTAEIME			BIT11	//0b/0b/x/x EIME: Extended Interrupt Mode Enable
    #define TACTL_RXB8_10_4			0x7F0	//0h/0h/x/x Reserved
    #define TACTL_RTAIRS_3_0			0xF	//0h/0h/x/x S: Size
#define TACTL_INTR_REMAPPING_TABLE_ADR_REG_Z1		0xBC	//Interrupt Remapping Table Address Register
    #define TACTL_RTAIRTA_63_32			0xFFFFFFFF	//0h/0h/x/x IRTA: Interrupt Remapping Table Address
#define TACTL_FAULT_STA_RECORDING_REG		0xC0	//Fault Status Recording Register
    #define TACTL_RXC0_31_8			0xFFFFFF80	//0/0/x/x Reserved
    #define TACTL_RFRQCNT_3_0			0x78	//0h/x/x/x Reserved
    #define TACTL_RFRQWPTR_2_0			(BIT0 + BIT1 + BIT2)	//000b/x/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_0		0x100	//Fault Recording Register[0]
    #define TACTL_RTAFRFI0_31_12			0xFFFFF000	//0/x/x/x FI: Fault Info
    #define TACTL_RX100_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_0_Z1		0x104	//Fault Recording Register[0]
    #define TACTL_RTAFRFI0_63_32			0xFFFFFFFF	//0h/x/x/x FI: Fault Info, High 32 bit
#define TACTL_FAULT_RECORDING_REG_0_Z2		0x108	//Fault Recording Register[0]
    #define TACTL_RX108_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRSID0_15_0			0xFFFF	//0h/x/x/x SID: Source Identifier
#define TACTL_FAULT_RECORDING_REG_0_Z3		0x10C	//Fault Recording Register[0]
    #define TACTL_RTAFRF0			BIT31	//0b/0b/x/x F: Fault
    #define TACTL_RTAFRT0			BIT30	//0b/x/x/x T: Type
    #define TACTL_RTAFRAT0_1_0			(BIT28 + BIT29)	//0/x/x/x AT: Address Type
    #define TACTL_RX10C_27_8			0xFFFFF00	//0h/0h/x/x Reserved
    #define TACTL_RTAFRFR0_7_0			0xFF	//0h/x/x/x FR: Fault Reason
#define TACTL_FAULT_RECORDING_REG_1		0x110	//Fault Recording Register[1]
    #define TACTL_RTAFRFI1_31_12			0xFFFFF000	//0/x/x/x FI: Fault Info
    #define TACTL_RX110_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_1_Z1		0x114	//Fault Recording Register[1]
    #define TACTL_RTAFRFI1_63_32			0xFFFFFFFF	//0h/x/x/x FI: Fault Info, High 32 bit
#define TACTL_FAULT_RECORDING_REG_1_Z2		0x118	//Fault Recording Register[1]
    #define TACTL_RX118_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRSID1_15_0			0xFFFF	//0h/x/x/x SID: Source Identifier
#define TACTL_FAULT_RECORDING_REG_1_Z3		0x11C	//Fault Recording Register[1]
    #define TACTL_RTAFRF1			BIT31	//0b/0b/x/x F: Fault
    #define TACTL_RTAFRT1			BIT30	//0b/x/x/x T: Type
    #define TACTL_RTAFRAT1_1_0			(BIT28 + BIT29)	//0/x/x/x AT: Address Type
    #define TACTL_RX11C_27_8			0xFFFFF00	//0h/0h/x/x Reserved
    #define TACTL_RTAFRFR1_7_0			0xFF	//0h/x/x/x FR: Fault Reason
#define TACTL_FAULT_RECORDING_REG_2		0x120	//Fault Recording Register[2]
    #define TACTL_RTAFRFI2_31_12			0xFFFFF000	//0/x/x/x FI: Fault Info
    #define TACTL_RX120_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_2_Z1		0x124	//Fault Recording Register[2]
    #define TACTL_RTAFRFI2_63_32			0xFFFFFFFF	//0h/x/x/x FI: Fault Info, High 32 bit
#define TACTL_FAULT_RECORDING_REG_2_Z2		0x128	//Fault Recording Register[2]
    #define TACTL_RX128_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRSID2_15_0			0xFFFF	//0h/x/x/x SID: Source Identifier
#define TACTL_FAULT_RECORDING_REG_2_Z3		0x12C	//Fault Recording Register[2]
    #define TACTL_RTAFRF2			BIT31	//0b/0b/x/x F: Fault
    #define TACTL_RTAFRT2			BIT30	//0b/x/x/x T: Type
    #define TACTL_RTAFRAT2_1_0			(BIT28 + BIT29)	//0/x/x/x AT: Address Type
    #define TACTL_RX12C_27_8			0xFFFFF00	//0h/0h/x/x Reserved
    #define TACTL_RTAFRFR2_7_0			0xFF	//0h/x/x/x FR: Fault Reason
#define TACTL_FAULT_RECORDING_REG_3		0x130	//Fault Recording Register[3]
    #define TACTL_RTAFRFI3_31_12			0xFFFFF000	//0/x/x/x FI: Fault Info
    #define TACTL_RX130_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_3_Z1		0x134	//Fault Recording Register[3]
    #define TACTL_RTAFRFI3_63_32			0xFFFFFFFF	//0h/x/x/x FI: Fault Info, High 32 bit
#define TACTL_FAULT_RECORDING_REG_3_Z2		0x138	//Fault Recording Register[3]
    #define TACTL_RX138_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRSID3_15_0			0xFFFF	//0h/x/x/x SID: Source Identifier
#define TACTL_FAULT_RECORDING_REG_3_Z3		0x13C	//Fault Recording Register[3]
    #define TACTL_RTAFRF3			BIT31	//0b/0b/x/x F: Fault
    #define TACTL_RTAFRT3			BIT30	//0b/x/x/x T: Type
    #define TACTL_RTAFRAT3_1_0			(BIT28 + BIT29)	//0/x/x/x AT: Address Type
    #define TACTL_RX13C_27_8			0xFFFFF00	//0h/0h/x/x Reserved
    #define TACTL_RTAFRFR3_7_0			0xFF	//0h/x/x/x FR: Fault Reason
#define TACTL_FAULT_RECORDING_REG_4		0x140	//Fault Recording Register[4]
    #define TACTL_RTAFRFI4_31_12			0xFFFFF000	//0/x/x/x FI: Fault Info
    #define TACTL_RX140_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_4_Z1		0x144	//Fault Recording Register[4]
    #define TACTL_RTAFRFI4_63_32			0xFFFFFFFF	//0h/x/x/x FI: Fault Info, High 32 bit
#define TACTL_FAULT_RECORDING_REG_4_Z2		0x148	//Fault Recording Register[4]
    #define TACTL_RX148_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRSID4_15_0			0xFFFF	//0h/x/x/x SID: Source Identifier
#define TACTL_FAULT_RECORDING_REG_4_Z3		0x14C	//Fault Recording Register[4]
    #define TACTL_RTAFRF4			BIT31	//0b/0b/x/x F: Fault
    #define TACTL_RTAFRT4			BIT30	//0b/x/x/x T: Type
    #define TACTL_RTAFRAT4_1_0			(BIT28 + BIT29)	//0/x/x/x AT: Address Type
    #define TACTL_RX14C_27_8			0xFFFFF00	//0h/0h/x/x Reserved
    #define TACTL_RTAFRFR4_7_0			0xFF	//0h/x/x/x FR: Fault Reason
#define TACTL_FAULT_RECORDING_REG_5		0x150	//Fault Recording Register[5]
    #define TACTL_RTAFRFI5_31_12			0xFFFFF000	//0/x/x/x FI: Fault Info
    #define TACTL_RX150_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_5_Z1		0x154	//Fault Recording Register[5]
    #define TACTL_RTAFRFI5_63_32			0xFFFFFFFF	//0h/x/x/x FI: Fault Info, High 32 bit
#define TACTL_FAULT_RECORDING_REG_5_Z2		0x158	//Fault Recording Register[5]
    #define TACTL_RX158_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRSID5_15_0			0xFFFF	//0h/x/x/x SID: Source Identifier
#define TACTL_FAULT_RECORDING_REG_5_Z3		0x15C	//Fault Recording Register[5]
    #define TACTL_RTAFRF5			BIT31	//0b/0b/x/x F: Fault
    #define TACTL_RTAFRT5			BIT30	//0b/x/x/x T: Type
    #define TACTL_RTAFRAT5_1_0			(BIT28 + BIT29)	//0/x/x/x AT: Address Type
    #define TACTL_RLX15C_27_8			0xFFFFF00	//0h/0h/x/x Reserved
    #define TACTL_RTAFRFR5_7_0			0xFF	//0h/x/x/x FR: Fault Reason
#define TACTL_FAULT_RECORDING_REG_6		0x160	//Fault Recording Register[6]
    #define TACTL_RTAFRFI6_31_12			0xFFFFF000	//0/x/x/x FI: Fault Info
    #define TACTL_RX160_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_6_Z1		0x164	//Fault Recording Register[6]
    #define TACTL_RTAFRFI6_63_32			0xFFFFFFFF	//0h/x/x/x FI: Fault Info, High 32 bit
#define TACTL_FAULT_RECORDING_REG_6_Z2		0x168	//Fault Recording Register[6]
    #define TACTL_RX168_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRSID6_15_0			0xFFFF	//0h/x/x/x SID: Source Identifier
#define TACTL_FAULT_RECORDING_REG_6_Z3		0x16C	//Fault Recording Register[6]
    #define TACTL_RTAFRF6			BIT31	//0b/0b/x/x F: Fault
    #define TACTL_RTAFRT6			BIT30	//0b/x/x/x T: Type
    #define TACTL_RTAFRAT6_1_0			(BIT28 + BIT29)	//0/x/x/x AT: Address Type
    #define TACTL_RX16C_27_8			0xFFFFF00	//0h/0h/x/x Reserved
    #define TACTL_RTAFRFR6_7_0			0xFF	//0h/x/x/x FR: Fault Reason
#define TACTL_FAULT_RECORDING_REG_7		0x170	//Fault Recording Register[7]
    #define TACTL_RTAFRFI7_31_12			0xFFFFF000	//0/x/x/x FI: Fault Info
    #define TACTL_RX170_11_0			0xFFF	//0h/0h/x/x Reserved
#define TACTL_FAULT_RECORDING_REG_7_Z1		0x174	//Fault Recording Register[7]
    #define TACTL_RTAFRFI7_63_32			0xFFFFFFFF	//0h/x/x/x FI: Fault Info, High 32 bit
#define TACTL_FAULT_RECORDING_REG_7_Z2		0x178	//Fault Recording Register[7]
    #define TACTL_RX178_31_16			0xFFFF0000	//0h/0h/x/x Reserved
    #define TACTL_RTAFRSID7_15_0			0xFFFF	//0h/x/x/x SID: Source Identifier
#define TACTL_FAULT_RECORDING_REG_7_Z3		0x17C	//Fault Recording Register[7]
    #define TACTL_RTAFRF7			BIT31	//0b/0b/x/x F: Fault
    #define TACTL_RTAFRT7			BIT30	//0b/x/x/x T: Type
    #define TACTL_RTAFRAT7_1_0			(BIT28 + BIT29)	//0/x/x/x AT: Address Type
    #define TACTL_RX17C_27_8			0xFFFFF00	//0h/0h/x/x Reserved
    #define TACTL_RTAFRFR7_7_0			0xFF	//0h/x/x/x FR: Fault Reason
#define TACTL_IOTLB_INVALIDATION_ADR_REG		0x200	//IOTLB Invalidation Address Register
    #define TACTL_RIOTLBIVLDADDR_31_12			0xFFFFF000	//0h/0h/x/x ADDR: Address
    #define TACTL_RX200_11_7			0xF80	//0h/0h/x/x Reserved
    #define TACTL_RIOTLBIVLDIH			BIT6	//0b/0b/x/x IH: InvalidationHint
    #define TACTL_RIOTLBIVLDAM_5_0			0x3F	//0h/0h/x/x AM: Address Mask
#define TACTL_IOTLB_INVALIDATION_ADR_REG_Z1		0x204	//IOTLB Invalidation Address Register
    #define TACTL_RIOTLBIVLDADDR_63_32			0xFFFFFFFF	//0h/0h/x/x ADDR: Address
#define TACTL_IOTLB_INVALIDATION_REG		0x208	//IOTLB Invalidation Register
    #define TACTL_RX208_31_0			0xFFFFFFFF	//0h/0h/x/x Reserved
#define TACTL_IOTLB_INVALIDATION_REG_Z1		0x20C	//IOTLB Invalidation Register
    #define TACTL_RIOTLBIVLDIVT			BIT31	//0b/0b/x/x IVT: Invalidate IOTLB
    #define TACTL_RX20C_30			BIT30	//0b/0b/x/x Reserved
    #define TACTL_RIOTLBIVLDIIRG_1_0			(BIT28 + BIT29)	//00b/00b/x/x IIRG: IOTLB Invalidation Request Granularity
    #define TACTL_RX20C_27			BIT27	//0b/0b/x/x Reserved
    #define TACTL_RIOTLBIVLDIAIG_1_0			(BIT25 + BIT26)	//HwInit/00b/x/x IAIG: IOTLB Actual Invalidation Granularity
    #define TACTL_RX20C_6_0			0x1FC0000	//0h/0h/x/x Reserved
    #define TACTL_RIOTLBIVLDDR			BIT17	//0b/0b/x/x DR: Drain Reads
    #define TACTL_RIOTLBIVLDDW			BIT16	//0b/0b/x/x DW: Drain Writes
    #define TACTL_RIOTLBIVLDDID_15_0			0xFFFF	//0h/0h/x/x DID: Domain-ID
#endif
