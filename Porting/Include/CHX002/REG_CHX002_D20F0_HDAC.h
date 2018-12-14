//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		HDAC					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D20F0_HDAC_R102(A0).doc(final)MOD_AZCFG.xls
#ifndef _CHX002_D20F0_HDAC_H
#define _CHX002_D20F0_HDAC_H
//D20F0
#define D20F0_VID		0x00	//Vendor ID
    #define D20F0_VID_Z1			0xFFFF	//1106h/x/x/x Vendor ID Code
#define D20F0_DID		0x02	//Device ID
    #define D20F0_DID_Z1			0xFFFF	//3288h/x/x/x Device ID
#define D20F0_PCI_CMD		0x04	//PCI Command
    #define D20F0_INT_DIS			BIT10	//0/0/x/x Interrupt Control
    #define D20F0_BME			BIT2	//0/0/x/x Bus Master
    #define D20F0_AZMSE			BIT1	//0/0/x/x Memory Space Access
#define D20F0_PCI_STA		0x06	//PCI Status
    #define D20F0_CAPABILITY_LIST			BIT4	//1b/R/x/x Capability List
    #define D20F0_AZ_INT			BIT3	//0/R/x/x Interrupt Status
#define D20F0_REV_ID		0x08	//Revision ID
    #define D20F0_RID			0xFF	//20h/x/x/x Revision ID
#define D20F0_CLASS_CODE		0x09	//Class Code
    #define D20F0_CLASS_CODE_Z1			0xFFFFFF	//040300h/x/x/x Class Code
#define D20F0_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D20F0_CLS			0xFF	//0/x/x/x Cache Line Size
#define D20F0_LATENCY_TIMER		0x0D	//Latency Timer
#define D20F0_HEADER_TYPE		0x0E	//Header Type
#define D20F0_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
#define D20F0_HDAC_LOWER_BASE_ADR		0x10	//HDAC Lower Base Address
    #define D20F0_AZLBA			0xFFFFC000	//0/x/x/x HDAC Lower Base Address
    #define D20F0_SUPP64_PCIE			(BIT1 + BIT2)	//10b/R/x/x Reserved (Do Not Program)
#define D20F0_HDAC_UPPER_BASE_ADR		0x14	//HDAC Upper Base Address
    #define D20F0_AZUBA			0xFFFFFFFF	//0/x/x/x HDAC Upper Base Address
#define D20F0_SVID		0x2C	//Subsystem Vendor ID
    #define D20F0_SVID_Z1			0xFFFF	//1106h/1106h/x/x Subsystem Vendor ID
#define D20F0_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D20F0_SID			0xFFFF	//3288h/3288h/x/x Subsystem ID
#define D20F0_EXPANSION_ROM		0x30	//Expansion ROM
#define D20F0_CAP_POINTER		0x34	//Capability Pointer
    #define D20F0_CAP_PTR			0xFF	//50h/R/x/x Capability Pointer
#define D20F0_INTR_LINE		0x3C	//Interrupt Line
    #define D20F0_INT_LN			0xFF	//0/x/x/x Interrupt Line
#define D20F0_INTR_PIN		0x3D	//Interrupt Pin
    #define D20F0_INT_PIN			0xFF	//01h/R/x/x Interrupt Pin
#define D20F0_MINIMUM_GRANT_PERIOD		0x3E	//Minimum Grant Period
#define D20F0_MAXIMUM_LATENCY		0x3F	//Maximum Latency
#define D20F0_BACK_DOOR_ENABLE		0x40	//Back Door Enable
    #define D20F0_CFGRX40H_7			BIT7	//0/x/x/x Reserved
    #define D20F0_EN_FLRCAP			BIT6	//0/x/x/x FLR Capability Enable
    #define D20F0_EN149W			BIT5	//0/0/x/x Reserved
    #define D20F0_EN_ECR			BIT4	//1b/1/x/x Reserved ((Random))
    #define D20F0_ENSDFIFOSZW			BIT3	//0/x/x/x Reserved
    #define D20F0_EN142W			BIT2	//0/0/x/x Reserved
    #define D20F0_EN136W			BIT1	//0/0/x/x Reserved
    #define D20F0_EN2CW			BIT0	//0/0/x/x Subsystem ID / Subsystem Vender ID Back Door Enable
#define D20F0_HDAC_CTL		0x41	//HDAC Control
    #define D20F0_DBG_EN			BIT2	//0/0/x/x Reserved
    #define D20F0_SKIPINIT			BIT1	//0/0/x/x Reserved
    #define D20F0_DYNSTOP			BIT0	//0/0/1/1 HDAC Dynamic Stop ((Random))
#define D20F0_BACK_DOOR		0x42	//Back Door
    #define D20F0_AZ_SNOOP			BIT7	//1b/1/0/0 Back Door for HDAC DMA Cycle Going Snoop Path or Non-snoop Path
    #define D20F0_SRAMCLK_GATE_BY_RWEN			BIT6	//0/x/x/0 Back Door to Enable SRAM Write Clock Gated by Write Enable and Read Clock Gated by Read Enable
    #define D20F0_AZINT_ROUTING			BIT5	//0/0/x/x Back Door for HDAC Interrupt Routing
    #define D20F0_DMA_POS_SWI			BIT4	//0/0/x/x Backdoor for DMA Position
    #define D20F0_THRE_SW_E			BIT3	//0/0/x/1 Playback Stream FIFO Threshold Switch Enable ((Random))
    #define D20F0_C4_SAFETY_FRAME_2_0			(BIT0 + BIT1 + BIT2)	//010b/010b/x/x C4 Safety Frame for Playback Stream FIFO Threshold Switch ((Random))
#define D20F0_BACK_DOOR_Z1		0x43	//Back Door
    #define D20F0_AZDBG_SEL1			0xF8	//0/x/x/X Reserved
    #define D20F0_C3_SAFETY_FRAME_2_0			(BIT0 + BIT1 + BIT2)	//0/0/x/X C3 Safety Frame for Playback Stream FIFO Threshold Switch ((Random))
#define D20F0_TRAFFIC_CLASS_SEL		0x44	//Traffic Class Select
#define D20F0_BACK_DOOR_Z2		0x45	//Back Door
    #define D20F0_INHIBIT_C3_BYTE			0xFF	//0/x/x/x The minimum out stream format (in bytes) that are inhibit to enter C3. 
#define D20F0_BACK_DOOR_Z3		0x46	//Back Door
    #define D20F0_INHIBIT_C4_BYTE			0xFF	//0/x/x/x The minimum out stream format (in bytes) that are inhibit to enter C4. 
#define D20F0_DEBUG_SIGNAL_SEL		0x48	//Debug Signal Select
    #define D20F0_SW_DID_RID_LOCK			BIT7	//0/x/x/x Reserved
    #define D20F0_RUPBYPASS			BIT6	//0/0/x/x Zpmtff Bypass Enable for Testing 
    #define D20F0_RHDAC2MCUPM			BIT5	//0/0/1/1 HDAC2PXP Module Dynamic Clock Enable 
    #define D20F0_CFGRX48H_4_0			0x1F	//0/x/x/x Reserved
#define D20F0_HDAC_SRC_ID		0x49	//HDAC Source ID
    #define D20F0_HDAC_SOURCEID			0xFFFF	//00A0h/x/x/x HDAC Source ID
#define D20F0_DEBUG_SIGNAL_SEL_Z1		0x4B	//Debug Signal Select
    #define D20F0_CFGRX4BH_7_3			0xF8	//0/x/x/x Reserved
    #define D20F0_TXP_MEANING			(BIT1 + BIT2)	//0/0/x/x TXP_meaning
    #define D20F0_FORCE_FLR_EN			BIT0	//0/0/0/0 force_FLR_en
#define D20F0_PCI_PM_CAPS_ID		0x50	//PCI Power Management Capabilities ID
    #define D20F0_MSI_POINTER			0xFF00	//60h/R/x/x Next Capability Pointer
    #define D20F0_PM_CAP			0xFF	//01h/R/x/x PCI Power Management Capability
#define D20F0_PCI_PM_CAPS		0x52	//PCI Power Management Capabilities
    #define D20F0_PME_ASSERT			0xF800	//19h/R/x/x PME# Can Be Generated from D3 
    #define D20F0_D2_SUPPORT			BIT10	//0/R/x/x D2 State Supported
    #define D20F0_D1_SUPPORT			BIT9	//0/R/x/x D1 State Supported
    #define D20F0_MAX_CURRENT			(BIT6 + BIT7 + BIT8)	//001b/R/x/x Report D3 Max Suspend Current
    #define D20F0_SPECIFIC_INITIAL			BIT5	//0/R/x/x Device-Specific Initialization Requirement
    #define D20F0_PCIP			(BIT0 + BIT1 + BIT2)	//010b/R/x/x PCI Power Support
//B0D20F0
#define B0D20F0_PM_CTL_AND_STA		0x54	//Power Management Control and Status
    #define B0D20F0_PMES			BIT15	//0/x/x/x PME Status
    #define B0D20F0_PMEE			BIT8	//0/x/x/x PME Enable
    #define B0D20F0_PS			(BIT0 + BIT1)	//00b/00b/x/x Power State
//D20F0
#define D20F0_MSI_CAP_ID		0x60	//MSI Capability ID
    #define D20F0_PCIE_POINTER			0xFF00	//70h/R/x/x Next Capability Pointer
    #define D20F0_MSI_CAPABILITY			0xFF	//05h/x/x/x MSI Capability
#define D20F0_MSI_MSG_CTL		0x62	//MSI Message Control
    #define D20F0_ADD_64			BIT7	//1b/x/x/x 64-Bit Address Capability
    #define D20F0_ME			BIT0	//0/x/x/x MSI Enable ((Random))
#define D20F0_MSI_MSG_LOWER_ADR		0x64	//MSI Message Lower Address
    #define D20F0_MLA			0xFFFFFFFC	//0/x/x/x Message Lower Address
#define D20F0_MSI_MSG_UPPER_ADR		0x68	//MSI Message Upper Address
    #define D20F0_MUA			0xFFFFFFFF	//0/x/x/x Message Upper Address
#define D20F0_MSI_DATA		0x6C	//MSI Data
    #define D20F0_MD			0xFFFF	//0/x/x/x Data Used for MSI Message
#define D20F0_MSI_REPEAT_GENERATE		0x6E	//MSI Repeat Generate
    #define D20F0_MSI_RE_WIDTH			0xFE	//0/x/x/x MSI Repeat Width
    #define D20F0_MSI_RE_ENABLE			BIT0	//0/x/x/x MSI Repeat Enable
#define D20F0_PCI_EXPRESS_CAP_ID		0x70	//PCI Express Capability ID
    #define D20F0_PCIE_CAPABILITY			0xFF	//10h/R/x/x PCI Express Capability
#define D20F0_PCI_EXPRESS_CAP		0x72	//PCI Express Capability
    #define D20F0_DEVICE_TYP			0xFF	//91h/R/x/x Capability Version #1
#define D20F0_DEV_CAPS		0x74	//Device Capabilities
    #define D20F0_FLR_CAPABILITY			BIT28	//1b/R/x/x Function Level Reset Capability
#define D20F0_DEV_CTL		0x78	//Device Control
    #define D20F0_FLR			BIT15	//0/x/x/x Initiate FLR
#define D20F0_DEV_STA		0x7A	//Device Status
    #define D20F0_AUX_PD			BIT4	//1b/R/x/x AUX Power Detected
#define D20F0_VIRTUAL_CHN_ENHANCED_CAP		0x100	//Virtual Channel Enhanced Capability
    #define D20F0_VNXT_CAPABILITY_PTR			0xFFF00000	//130h/R/x/x Next Capability Pointer
    #define D20F0_REVISION			0xF0000	//1h/R/x/x Capability Structure Revision
    #define D20F0_CID			0xFFFF	//0002h/R/x/x Extended Capability ID
#define D20F0_PORT_VC_CAP_1		0x104	//Port VC Capability 1
#define D20F0_PORT_VC_CAP_2		0x108	//Port VC Capability 2
#define D20F0_PORT_VC_CTL		0x10C	//Port VC Control
#define D20F0_PORT_VC_STA		0x10E	//Port VC Status
#define D20F0_VC0_RESRC_CAP		0x110	//VC0 Resource Capability
#define D20F0_VC0_RESRC_CTL		0x114	//VC0 Resource Control
    #define D20F0_VC0_EN			BIT31	//1b/x/x/x VC0 Enable
    #define D20F0_CFGRX114H			0xFE	//7Fh/x/x/x TC/VC0 Map
    #define D20F0_VC0_MAP			BIT0	//1b/x/x/x TC/VC0 Map
#define D20F0_VC0_RESRC_STA		0x11A	//VC0 Resource Status
#define D20F0_ROOT_COMPLEX_LINK_DECLARATION_ENHANCED_CAP_HEADER_REG		0x130	//Root Complex Link Declaration Enhanced Capability Header Register
    #define D20F0_RNXT_CAPABILITY_PTR			0xFFFF0000	//0001h/R/x/x Next Capability
    #define D20F0_PCIE_CID			0xFFFF	//0005h/R/x/x PCI Express Extended Capability ID
#define D20F0_ELEMENT_SELF_DESCRIPTION		0x134	//Element Self Description
    #define D20F0_CFGRX137H			0xFF000000	//0Fh/0Fh/x/x Port Number
    #define D20F0_CFGRX136H			0xFF0000	//01h/01h/x/x Component ID
    #define D20F0_LINK_NUM			0xFF00	//01h/x/x/x Number of Link Entries
#define D20F0_LINK_DESCRIPTION		0x140	//Link Description
    #define D20F0_CFGRX142H			0xFF0000	//01h/01h/x/x Component ID
    #define D20F0_LINK_VALID			BIT0	//1b/R/x/x Link Valid
#define D20F0_LINK_LOWER_ADR		0x148	//Link Lower Address
    #define D20F0_CFGRX14BHCFGRX14AHCFGRX149H			0xFFFFF000	//HwInit/x/x/x Link Lower Address
#define D20F0_LINK_UPPER_ADR		0x14C	//Link Upper Address
    #define D20F0_CFGRX14CH			0xF	//HwInit/x/x/x Link Upper Address
//HDAC-MMIO
#define HDACMMIO_GLOBAL_CAPS_GCAP		0x00	//Global Capabilities - GCAP
    #define HDACMMIO_OSS			0xF000	//4h/R/x/x Number of Output Streams Supported
    #define HDACMMIO_ISS			0xF00	//4h/R/x/x Number of Input Streams Supported
    #define HDACMMIO_BSS			0xF8	//0/R/x/x Number of Bidirectional Streams Supported
    #define HDACMMIO_NSDO			BIT1	//0/R/x/x Number of Serial Data Out Signals
    #define HDACMMIO_SUPP64_MM			BIT0	//1b/R/x/x 64-Bit Address Supported
#define HDACMMIO_VER_NUM		0x02	//Version Number
    #define HDACMMIO_VMAJ			0xFF00	//01h/R/x/x Major Version
    #define HDACMMIO_VMIN			0xFF	//0/R/x/x Minor Version
#define HDACMMIO_PAYLOAD_CAP		0x04	//Payload Capability
    #define HDACMMIO_INPAY			0xFFFF0000	//001Dh/R/x/x Input Payload Capability
    #define HDACMMIO_OUTPAY			0xFFFF	//003Ch/R/x/x Output Payload Capability
#define HDACMMIO_GLOBAL_CTL_GCTL		0x08	//Global Control - GCTL
    #define HDACMMIO_UNSOL			BIT8	//0/x/x/x Accept Unsolicited Response Enable ((Random))
    #define HDACMMIO_FCNTRL			BIT1	//0/x/x/x Flush Control
    #define HDACMMIO_CRST			BIT0	//HwInit/x/x/x Controller Reset
#define HDACMMIO_WAKE_ENABLE_WAKEEN		0x0C	//Wake Enable - WAKEEN
    #define HDACMMIO_SDI1WENSDI0WEN			(BIT0 + BIT1)	//0/x/x/x AZSDIN Wake Enable Flags
#define HDACMMIO_AZSDIN_STATE_CHANGE_STA_STATESTS		0x0E	//AZSDIN State Change Status - STATESTS
    #define HDACMMIO_SDI1WAKESDI0WAKE			(BIT0 + BIT1)	//0/x/x/x AZSDIN State Change Status Flags
#define HDACMMIO_GLOBAL_STA_GSTS		0x10	//Global Status - GSTS
    #define HDACMMIO_FSTS			BIT1	//0/x/x/x Flush Status
#define HDACMMIO_STREAM_PAYLOAD_CAP		0x18	//Stream Payload Capability
    #define HDACMMIO_OUTSTRMPAY			0xFFFF0000	//001Dh/R/x/x Input Stream Payload Capability
    #define HDACMMIO_INSTRMPAY			0xFFFF	//003Ch/R/x/x Output Stream Payload Capability
#define HDACMMIO_INTR_CTL_INTCTL		0x20	//Interrupt Control - INTCTL
    #define HDACMMIO_GIE			BIT31	//0/x/x/x Global Interrupt Enable ((Random))
    #define HDACMMIO_CIE			BIT30	//0/x/x/x Controller Interrupt Enable ((Random))
    #define HDACMMIO_SIE_7_4			0xF0	//0/x/x/x Stream Interrupt Enable - for Output Stream [3:0] ((Random))
    #define HDACMMIO_SIE_3_0			0xF	//0/x/x/x Stream Interrupt Enable - for Input Stream [3:0] ((Random))
#define HDACMMIO_INTR_STA_INTSTS		0x24	//Interrupt Status - INTSTS
    #define HDACMMIO_GIS			BIT31	//0/x/x/x Global Interrupt Status
    #define HDACMMIO_CIS			BIT30	//0/x/x/x Controller Interrupt Status
    #define HDACMMIO_SIS_7_4			0xF0	//0/x/x/x Stream Interrupt Status - for Output Stream [3:0]
    #define HDACMMIO_SIS_3_0			0xF	//0/x/x/x Stream Interrupt Status - for Input Stream [3:0]
#define HDACMMIO_WALL_CLK_CNTER		0x30	//Wall Clock Counter
    #define HDACMMIO_WCOUNTER			0xFFFFFFFF	//0/x/x/x Wall Clock Counter
#define HDACMMIO_STREAM_SYNCHRONIZATION_SSYNC		0x38	//Stream Synchronization - SSYNC
    #define HDACMMIO_SSYNC_7_4			0xF0	//0/x/x/x Stream Synchronization Bits - for Output Stream [3:0] ((Random))
    #define HDACMMIO_SSYNC_3_0			0xF	//0/x/x/x Stream Synchronization Bits - for Input Stream [3:0] ((Random))
#define HDACMMIO_CORB_LOWER_BASE_ADR_CORBLBASE		0x40	//CORB Lower Base Address - CORBLBASE
    #define HDACMMIO_CORBLBASE			0xFFFFFF80	//0/x/x/x CORB Lower Base Address
#define HDACMMIO_CORB_UPPER_BASE_ADR_CORBUBASE		0x44	//CORB Upper Base Address - CORBUBASE
    #define HDACMMIO_CORBUBASE			0xFFFFFFFF	//0/x/x/x CORB Upper Base Address
#define HDACMMIO_CORB_WRITE_POINTER		0x48	//CORB Write Pointer
    #define HDACMMIO_CORBWP			0xFF	//0/x/x/x CORB Write Pointer ((Random))
#define HDACMMIO_CORB_READ_POINTER		0x4A	//CORB Read Pointer
    #define HDACMMIO_CORBRPRST			BIT15	//0/x/x/x CORB Read Pointer Reset
    #define HDACMMIO_CORBRP			0xFF	//0/x/x/x CORB Read Pointer
#define HDACMMIO_CORB_CTL_CORBCTL		0x4C	//CORB Control - CORBCTL
    #define HDACMMIO_CORBRUN			BIT1	//0/x/x/x Enable CORB DMA Engine
    #define HDACMMIO_CMEIE			BIT0	//0/x/x/x CORB Memory Error Interrupt Enable ((Random))
#define HDACMMIO_CORB_STA_CORBSTS		0x4D	//CORB Status - CORBSTS
    #define HDACMMIO_CMEI			BIT0	//0/x/x/x CORB Memory Error Indication
#define HDACMMIO_CORB_SIZE_CORBSIZE		0x4E	//CORB Size - CORBSIZE
    #define HDACMMIO_CORBSZCAP			0xF0	//4h/R/x/x CORB Size Capability
    #define HDACMMIO_CORBSIZE			(BIT0 + BIT1)	//10b/R/x/x CORB Size
#define HDACMMIO_RIRB_LOWER_BASE_ADR_RIRBLBASE		0x50	//RIRB Lower Base Address - RIRBLBASE
    #define HDACMMIO_RIRBLBASE			0xFFFFFF80	//0/x/x/x RIRB Lower Base Address
#define HDACMMIO_RIRB_UPPER_BASE_ADR_RIRBUBASE		0x54	//RIRB Upper Base Address - RIRBUBASE
    #define HDACMMIO_RIRBUBASE			0xFFFFFFFF	//0/x/x/x RIRB Upper Base Address
#define HDACMMIO_RIRB_WRITE_POINTER_RIRBWP		0x58	//RIRB Write Pointer - RIRBWP
    #define HDACMMIO_RIRBWPRST			BIT15	//0/x/x/x RIRB Write Pointer Reset
    #define HDACMMIO_RIRBWP			0xFF	//0/x/x/x RIRB Write Pointer
#define HDACMMIO_RESPONSE_INTR_COUNT_RINTCNT		0x5A	//Response Interrupt Count - RINTCNT
    #define HDACMMIO_RINTCNT			0xFF	//00h/x/x/x Response Interrupt Count - N Response ((Random))
#define HDACMMIO_RIRB_CTL_RIRBCTL		0x5C	//RIRB Control - RIRBCTL
    #define HDACMMIO_RIRBOIC			BIT2	//0/x/x/x Response Overrun Interrupt Control ((Random))
    #define HDACMMIO_RIRBDMAEN			BIT1	//0/x/x/x Enable RIRB DMA Engine
    #define HDACMMIO_RINTCTL			BIT0	//0/x/x/x Response Interrupt Control ((Random))
#define HDACMMIO_RIRB_STA_RIRBSTS		0x5D	//RIRB Status - RIRBSTS
    #define HDACMMIO_RIRBOIS			BIT2	//0/x/x/x Response Overrun Interrupt Status
    #define HDACMMIO_RINTFL			BIT0	//0/x/x/x Response Interrupt
#define HDACMMIO_RIRB_SIZE_RIRBSIZE		0x5E	//RIRB Size - RIRBSIZE
    #define HDACMMIO_RIRBSZCAP			0xF0	//0100b/R/x/x RIRB Size Capability
    #define HDACMMIO_RIRBSIZE			(BIT0 + BIT1)	//10b/R/x/x RIRB Size
#define HDACMMIO_IMMEDIATE_CMD_INPUT_OUTPUT_IF		0x60	//Immediate Command Input / Output Interface
    #define HDACMMIO_ICW			0xFFFFFFFF	//0/x/x/x Immediate Command Write
#define HDACMMIO_IMMEDIATE_RESPONSE_INPUT_IF		0x64	//Immediate Response Input Interface
    #define HDACMMIO_IRR			0xFFFFFFFF	//0/x/x/x Immediate Response Read 
#define HDACMMIO_IMMEDIATE_CMD_STA		0x68	//Immediate Command Status
    #define HDACMMIO_IRRADD			0xF0	//0/x/x/x Immediate Response Result Address
    #define HDACMMIO_IRRUNSOL			BIT3	//0/x/x/x Immediate Response Result Unsolicited
    #define HDACMMIO_ICVER			BIT2	//1b/x/x/x Immediate Command Version
    #define HDACMMIO_IRV			BIT1	//0/x/x/x Immediate Result Valid
    #define HDACMMIO_ICB			BIT0	//0/x/x/x Immediate Command Busy
#define HDACMMIO_DMA_POSITION_LOWER_BASE_ADR_DPLBASE		0x70	//DMA Position Lower Base Address - DPLBASE
    #define HDACMMIO_DPLBASE			0xFFFFFF80	//0/x/x/x DMA Position Lower Base Address
    #define HDACMMIO_DPBE			BIT0	//0/x/x/x DMA Position Buffer Enable ((Random))
#define HDACMMIO_DMA_POSITION_UPPER_BASE_ADR_DPUBASE		0x74	//DMA Position Upper Base Address - DPUBASE
    #define HDACMMIO_DPUBASE			0xFFFFFFFF	//0/x/x/x DMA Position Upper Base Address
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CTL_D_INPUT_STREAM_0		0x80	//HDAC Stream Descriptor Control D) - Input Stream 0
    #define HDACMMIO_SID			0xF00000	//0h/x/x/x Stream ID
    #define HDACMMIO_DIR			BIT19	//0/R/x/x Bidirectional Direction Control
    #define HDACMMIO_TP			BIT18	//0/x/x/x Traffic Priority
    #define HDACMMIO_STRIPE			(BIT16 + BIT17)	//00b/R/x/x Stripe Control
    #define HDACMMIO_DEIE			BIT4	//0/x/x/x Descriptor Error Interrupt Enable ((Random))
    #define HDACMMIO_FEIE			BIT3	//0/x/x/x FIFO Error Interrupt Enable ((Random))
    #define HDACMMIO_IOCE			BIT2	//0/x/x/x Interrupt On Completion Enable ((Random))
    #define HDACMMIO_RUN			BIT1	//0/x/x/x Stream Run
    #define HDACMMIO_SRST			BIT0	//0/x/x/x Stream Reset
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CTL_D_INPUT_STREAM_1		0xA0	//HDAC Stream Descriptor Control D) - Input Stream 1
    #define HDACMMIO_SID_Z1			0xF00000	//0h/x/x/x Stream ID
    #define HDACMMIO_DIR_Z1			BIT19	//0/R/x/x Bidirectional Direction Control
    #define HDACMMIO_TP_Z1			BIT18	//0/x/x/x Traffic Priority
    #define HDACMMIO_STRIPE_Z1			(BIT16 + BIT17)	//00b/R/x/x Stripe Control
    #define HDACMMIO_DEIE_Z1			BIT4	//0/x/x/x Descriptor Error Interrupt Enable ((Random))
    #define HDACMMIO_FEIE_Z1			BIT3	//0/x/x/x FIFO Error Interrupt Enable ((Random))
    #define HDACMMIO_IOCE_Z1			BIT2	//0/x/x/x Interrupt On Completion Enable ((Random))
    #define HDACMMIO_RUN_Z1			BIT1	//0/x/x/x Stream Run
    #define HDACMMIO_SRST_Z1			BIT0	//0/x/x/x Stream Reset
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CTL_D_INPUT_STREAM_2		0xC0	//HDAC Stream Descriptor Control D) - Input Stream 2
    #define HDACMMIO_SID_Z2			0xF00000	//0h/x/x/x Stream ID
    #define HDACMMIO_DIR_Z2			BIT19	//0/R/x/x Bidirectional Direction Control
    #define HDACMMIO_TP_Z2			BIT18	//0/x/x/x Traffic Priority
    #define HDACMMIO_STRIPE_Z2			(BIT16 + BIT17)	//00b/R/x/x Stripe Control
    #define HDACMMIO_DEIE_Z2			BIT4	//0/x/x/x Descriptor Error Interrupt Enable ((Random))
    #define HDACMMIO_FEIE_Z2			BIT3	//0/x/x/x FIFO Error Interrupt Enable ((Random))
    #define HDACMMIO_IOCE_Z2			BIT2	//0/x/x/x Interrupt On Completion Enable ((Random))
    #define HDACMMIO_RUN_Z2			BIT1	//0/x/x/x Stream Run
    #define HDACMMIO_SRST_Z2			BIT0	//0/x/x/x Stream Reset
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CTL_D_INPUT_STREAM_3		0xE0	//HDAC Stream Descriptor Control D) - Input Stream 3
    #define HDACMMIO_SID_Z3			0xF00000	//0h/x/x/x Stream ID
    #define HDACMMIO_DIR_Z3			BIT19	//0/R/x/x Bidirectional Direction Control
    #define HDACMMIO_TP_Z3			BIT18	//0/x/x/x Traffic Priority
    #define HDACMMIO_STRIPE_Z3			(BIT16 + BIT17)	//00b/R/x/x Stripe Control
    #define HDACMMIO_DEIE_Z3			BIT4	//0/x/x/x Descriptor Error Interrupt Enable ((Random))
    #define HDACMMIO_FEIE_Z3			BIT3	//0/x/x/x FIFO Error Interrupt Enable ((Random))
    #define HDACMMIO_IOCE_Z3			BIT2	//0/x/x/x Interrupt On Completion Enable ((Random))
    #define HDACMMIO_RUN_Z3			BIT1	//0/x/x/x Stream Run
    #define HDACMMIO_SRST_Z3			BIT0	//0/x/x/x Stream Reset
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CTL_D_OUTPUT_STREAM_0		0x100	//HDAC Stream Descriptor Control D) - Output Stream 0
    #define HDACMMIO_SID_Z4			0xF00000	//0h/x/x/x Stream ID
    #define HDACMMIO_DIR_Z4			BIT19	//0/R/x/x Bidirectional Direction Control
    #define HDACMMIO_TP_Z4			BIT18	//0/x/x/x Traffic Priority
    #define HDACMMIO_STRIPE_Z4			(BIT16 + BIT17)	//00b/R/x/x Stripe Control
    #define HDACMMIO_DEIE_Z4			BIT4	//0/x/x/x Descriptor Error Interrupt Enable ((Random))
    #define HDACMMIO_FEIE_Z4			BIT3	//0/x/x/x FIFO Error Interrupt Enable ((Random))
    #define HDACMMIO_IOCE_Z4			BIT2	//0/x/x/x Interrupt On Completion Enable ((Random))
    #define HDACMMIO_RUN_Z4			BIT1	//0/x/x/x Stream Run
    #define HDACMMIO_SRST_Z4			BIT0	//0/x/x/x Stream Reset
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CTL_D_OUTPUT_STREAM_1		0x120	//HDAC Stream Descriptor Control D) - Output Stream 1
    #define HDACMMIO_SID_Z5			0xF00000	//0h/x/x/x Stream ID
    #define HDACMMIO_DIR_Z5			BIT19	//0/R/x/x Bidirectional Direction Control
    #define HDACMMIO_TP_Z5			BIT18	//0/x/x/x Traffic Priority
    #define HDACMMIO_STRIPE_Z5			(BIT16 + BIT17)	//00b/R/x/x Stripe Control
    #define HDACMMIO_DEIE_Z5			BIT4	//0/x/x/x Descriptor Error Interrupt Enable ((Random))
    #define HDACMMIO_FEIE_Z5			BIT3	//0/x/x/x FIFO Error Interrupt Enable ((Random))
    #define HDACMMIO_IOCE_Z5			BIT2	//0/x/x/x Interrupt On Completion Enable ((Random))
    #define HDACMMIO_RUN_Z5			BIT1	//0/x/x/x Stream Run
    #define HDACMMIO_SRST_Z5			BIT0	//0/x/x/x Stream Reset
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CTL_D_OUTPUT_STREAM_2		0x140	//HDAC Stream Descriptor Control D) - Output Stream 2
    #define HDACMMIO_SID_Z6			0xF00000	//0h/x/x/x Stream ID
    #define HDACMMIO_DIR_Z6			BIT19	//0/R/x/x Bidirectional Direction Control
    #define HDACMMIO_TP_Z6			BIT18	//0/x/x/x Traffic Priority
    #define HDACMMIO_STRIPE_Z6			(BIT16 + BIT17)	//00b/R/x/x Stripe Control
    #define HDACMMIO_DEIE_Z6			BIT4	//0/x/x/x Descriptor Error Interrupt Enable ((Random))
    #define HDACMMIO_FEIE_Z6			BIT3	//0/x/x/x FIFO Error Interrupt Enable ((Random))
    #define HDACMMIO_IOCE_Z6			BIT2	//0/x/x/x Interrupt On Completion Enable ((Random))
    #define HDACMMIO_RUN_Z6			BIT1	//0/x/x/x Stream Run
    #define HDACMMIO_SRST_Z6			BIT0	//0/x/x/x Stream Reset
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CTL_D_OUTPUT_STREAM_3		0x160	//HDAC Stream Descriptor Control D) - Output Stream 3
    #define HDACMMIO_SID_Z7			0xF00000	//0h/x/x/x Stream ID
    #define HDACMMIO_DIR_Z7			BIT19	//0/R/x/x Bidirectional Direction Control
    #define HDACMMIO_TP_Z7			BIT18	//0/x/x/x Traffic Priority
    #define HDACMMIO_STRIPE_Z7			(BIT16 + BIT17)	//00b/R/x/x Stripe Control
    #define HDACMMIO_DEIE_Z7			BIT4	//0/x/x/x Descriptor Error Interrupt Enable ((Random))
    #define HDACMMIO_FEIE_Z7			BIT3	//0/x/x/x FIFO Error Interrupt Enable ((Random))
    #define HDACMMIO_IOCE_Z7			BIT2	//0/x/x/x Interrupt On Completion Enable ((Random))
    #define HDACMMIO_RUN_Z7			BIT1	//0/x/x/x Stream Run
    #define HDACMMIO_SRST_Z7			BIT0	//0/x/x/x Stream Reset
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_STA_D_INPUT_STREAM_0		0x83	//HDAC Stream Descriptor Status D) - Input Stream 0
    #define HDACMMIO_FIFORDY			BIT5	//0/x/x/x FIFO Ready
    #define HDACMMIO_DESE			BIT4	//0/x/x/x Descriptor Error
    #define HDACMMIO_FIFOE			BIT3	//0/x/x/x FIFO Error
    #define HDACMMIO_BCIS			BIT2	//0/x/x/x Buffer Completion Interrupt Status
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_STA_D_INPUT_STREAM_1		0xA3	//HDAC Stream Descriptor Status D) - Input Stream 1
    #define HDACMMIO_FIFORDY_Z1			BIT5	//0/x/x/x FIFO Ready
    #define HDACMMIO_DESE_Z1			BIT4	//0/x/x/x Descriptor Error
    #define HDACMMIO_FIFOE_Z1			BIT3	//0/x/x/x FIFO Error
    #define HDACMMIO_BCIS_Z1			BIT2	//0/x/x/x Buffer Completion Interrupt Status
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_STA_D_INPUT_STREAM_2		0xC3	//HDAC Stream Descriptor Status D) - Input Stream 2
    #define HDACMMIO_FIFORDY_Z2			BIT5	//0/x/x/x FIFO Ready
    #define HDACMMIO_DESE_Z2			BIT4	//0/x/x/x Descriptor Error
    #define HDACMMIO_FIFOE_Z2			BIT3	//0/x/x/x FIFO Error
    #define HDACMMIO_BCIS_Z2			BIT2	//0/x/x/x Buffer Completion Interrupt Status
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_STA_D_INPUT_STREAM_3		0xE3	//HDAC Stream Descriptor Status D) - Input Stream 3
    #define HDACMMIO_FIFORDY_Z3			BIT5	//0/x/x/x FIFO Ready
    #define HDACMMIO_DESE_Z3			BIT4	//0/x/x/x Descriptor Error
    #define HDACMMIO_FIFOE_Z3			BIT3	//0/x/x/x FIFO Error
    #define HDACMMIO_BCIS_Z3			BIT2	//0/x/x/x Buffer Completion Interrupt Status
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_STA_D_OUTPUT_STREAM_0		0x103	//HDAC Stream Descriptor Status D) - Output Stream 0
    #define HDACMMIO_FIFORDY_Z4			BIT5	//0/x/x/x FIFO Ready
    #define HDACMMIO_DESE_Z4			BIT4	//0/x/x/x Descriptor Error
    #define HDACMMIO_FIFOE_Z4			BIT3	//0/x/x/x FIFO Error
    #define HDACMMIO_BCIS_Z4			BIT2	//0/x/x/x Buffer Completion Interrupt Status
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_STA_D_OUTPUT_STREAM_1		0x123	//HDAC Stream Descriptor Status D) - Output Stream 1
    #define HDACMMIO_FIFORDY_Z5			BIT5	//0/x/x/x FIFO Ready
    #define HDACMMIO_DESE_Z5			BIT4	//0/x/x/x Descriptor Error
    #define HDACMMIO_FIFOE_Z5			BIT3	//0/x/x/x FIFO Error
    #define HDACMMIO_BCIS_Z5			BIT2	//0/x/x/x Buffer Completion Interrupt Status
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_STA_D_OUTPUT_STREAM_2		0x143	//HDAC Stream Descriptor Status D) - Output Stream 2
    #define HDACMMIO_FIFORDY_Z6			BIT5	//0/x/x/x FIFO Ready
    #define HDACMMIO_DESE_Z6			BIT4	//0/x/x/x Descriptor Error
    #define HDACMMIO_FIFOE_Z6			BIT3	//0/x/x/x FIFO Error
    #define HDACMMIO_BCIS_Z6			BIT2	//0/x/x/x Buffer Completion Interrupt Status
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_STA_D_OUTPUT_STREAM_3		0x163	//HDAC Stream Descriptor Status D) - Output Stream 3
    #define HDACMMIO_FIFORDY_Z7			BIT5	//0/x/x/x FIFO Ready
    #define HDACMMIO_DESE_Z7			BIT4	//0/x/x/x Descriptor Error
    #define HDACMMIO_FIFOE_Z7			BIT3	//0/x/x/x FIFO Error
    #define HDACMMIO_BCIS_Z7			BIT2	//0/x/x/x Buffer Completion Interrupt Status
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_D_INPUT_STREAM_0		0x84	//HDAC Stream Descriptor Link Position in Buffer D) - Input Stream 0
    #define HDACMMIO_LPIB			0xFFFFFFFF	//0/x/x/x Link Position in Buffer
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_D_INPUT_STREAM_1		0xA4	//HDAC Stream Descriptor Link Position in Buffer D) - Input Stream 1
    #define HDACMMIO_LPIB_Z1			0xFFFFFFFF	//0/x/x/x Link Position in Buffer
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_D_INPUT_STREAM_2		0xC4	//HDAC Stream Descriptor Link Position in Buffer D) - Input Stream 2
    #define HDACMMIO_LPIB_Z2			0xFFFFFFFF	//0/x/x/x Link Position in Buffer
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_D_INPUT_STREAM_3		0xE4	//HDAC Stream Descriptor Link Position in Buffer D) - Input Stream 3
    #define HDACMMIO_LPIB_Z3			0xFFFFFFFF	//0/x/x/x Link Position in Buffer
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_D_OUTPUT_STREAM_0		0x104	//HDAC Stream Descriptor Link Position in Buffer D) - Output Stream 0
    #define HDACMMIO_LPIB_Z4			0xFFFFFFFF	//0/x/x/x Link Position in Buffer
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_D_OUTPUT_STREAM_1		0x124	//HDAC Stream Descriptor Link Position in Buffer D) - Output Stream 1
    #define HDACMMIO_LPIB_Z5			0xFFFFFFFF	//0/x/x/x Link Position in Buffer
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_D_OUTPUT_STREAM_2		0x144	//HDAC Stream Descriptor Link Position in Buffer D) -Output Stream 2
    #define HDACMMIO_LPIB_Z6			0xFFFFFFFF	//0/x/x/x Link Position in Buffer
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_D_OUTPUT_STREAM_3		0x164	//HDAC Stream Descriptor Link Position in Buffer D) - Output Stream 3
    #define HDACMMIO_LPIB_Z7			0xFFFFFFFF	//0/x/x/x Link Position in Buffer
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CYCLIC_BUFFER_LEN_D_INPUT_STREAM_0		0x88	//HDAC Stream Descriptor Cyclic Buffer Length D) - Input Stream 0
    #define HDACMMIO_CBL			0xFFFFFFFF	//0/x/x/x Cyclic Buffer Length ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CYCLIC_BUFFER_LEN_D_INPUT_STREAM_1		0xA8	//HDAC Stream Descriptor Cyclic Buffer Length D) - Input Stream 1
    #define HDACMMIO_CBL_Z1			0xFFFFFFFF	//0/x/x/x Cyclic Buffer Length ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CYCLIC_BUFFER_LEN_D_INPUT_STREAM_2		0xC8	//HDAC Stream Descriptor Cyclic Buffer Length D) - Input Stream 2
    #define HDACMMIO_CBL_Z2			0xFFFFFFFF	//0/x/x/x Cyclic Buffer Length ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CYCLIC_BUFFER_LEN_D_INPUT_STREAM_3		0xE8	//HDAC Stream Descriptor Cyclic Buffer Length D) - Input Stream 3
    #define HDACMMIO_CBL_Z3			0xFFFFFFFF	//0/x/x/x Cyclic Buffer Length ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CYCLIC_BUFFER_LEN_D_OUTPUT_STREAM_0		0x108	//HDAC Stream Descriptor Cyclic Buffer Length D) - Output Stream 0
    #define HDACMMIO_CBL_Z4			0xFFFFFFFF	//0/x/x/x Cyclic Buffer Length ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CYCLIC_BUFFER_LEN_D_OUTPUT_STREAM_1		0x128	//HDAC Stream Descriptor Cyclic Buffer Length D) - Output Stream 1
    #define HDACMMIO_CBL_Z5			0xFFFFFFFF	//0/x/x/x Cyclic Buffer Length ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CYCLIC_BUFFER_LEN_D_OUTPUT_STREAM_2		0x148	//HDAC Stream Descriptor Cyclic Buffer Length D) - Output Stream 2
    #define HDACMMIO_CBL_Z6			0xFFFFFFFF	//0/x/x/x Cyclic Buffer Length ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_CYCLIC_BUFFER_LEN_D_OUTPUT_STREAM_3		0x168	//HDAC Stream Descriptor Cyclic Buffer Length D) - Output Stream 3
    #define HDACMMIO_CBL_Z7			0xFFFFFFFF	//0/x/x/x Cyclic Buffer Length ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LAST_VALID_INDEX_HDAC_MMIO_D_INPUT_STREAM_0		0x8C	//HDAC Stream Descriptor Last Valid Index (HDAC-MMIO) D) - Input Stream 0
    #define HDACMMIO_LVI			0xFF	//0/x/x/x Last Valid Index ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LAST_VALID_INDEX_HDAC_MMIO_D_INPUT_STREAM_1		0xAC	//HDAC Stream Descriptor Last Valid Index (HDAC-MMIO) D) - Input Stream 1
    #define HDACMMIO_LVI_Z1			0xFF	//0/x/x/x Last Valid Index ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LAST_VALID_INDEX_HDAC_MMIO_D_INPUT_STREAM_2		0xCC	//HDAC Stream Descriptor Last Valid Index (HDAC-MMIO) D) - Input Stream 2
    #define HDACMMIO_LVI_Z2			0xFF	//0/x/x/x Last Valid Index ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LAST_VALID_INDEX_HDAC_MMIO_D_INPUT_STREAM_3		0xEC	//HDAC Stream Descriptor Last Valid Index (HDAC-MMIO) D) - Input Stream 3
    #define HDACMMIO_LVI_Z3			0xFF	//0/x/x/x Last Valid Index ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LAST_VALID_INDEX_HDAC_MMIO_D_OUTPUT_STREAM_0		0x10C	//HDAC Stream Descriptor Last Valid Index (HDAC-MMIO) D) - Output Stream 0
    #define HDACMMIO_LVI_Z4			0xFF	//0/x/x/x Last Valid Index ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LAST_VALID_INDEX_HDAC_MMIO_D_OUTPUT_STREAM_1		0x12C	//HDAC Stream Descriptor Last Valid Index (HDAC-MMIO) D) - Output Stream 1
    #define HDACMMIO_LVI_Z5			0xFF	//0/x/x/x Last Valid Index ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LAST_VALID_INDEX_HDAC_MMIO_D_OUTPUT_STREAM_2		0x14C	//HDAC Stream Descriptor Last Valid Index (HDAC-MMIO) D) - Output Stream 2
    #define HDACMMIO_LVI_Z6			0xFF	//0/x/x/x Last Valid Index ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LAST_VALID_INDEX_HDAC_MMIO_D_OUTPUT_STREAM_3		0x16C	//HDAC Stream Descriptor Last Valid Index (HDAC-MMIO) D) - Output Stream 3
    #define HDACMMIO_LVI_Z7			0xFF	//0/x/x/x Last Valid Index ((Random))
#define HDACMMIO_HDAC_INPUT_STREAM_DESCRIPTOR_FIFO_SIZE_D_INPUT_STREAM_0		0x90	//HDAC Input Stream Descriptor FIFO Size D) - Input Stream 0
    #define HDACMMIO_FIFOSZ			0xFF	//60h/x/x/x FIFO Size ((Random))
#define HDACMMIO_HDAC_INPUT_STREAM_DESCRIPTOR_FIFO_SIZE_D_INPUT_STREAM_1		0xB0	//HDAC Input Stream Descriptor FIFO Size D) -Input Stream 1
    #define HDACMMIO_FIFOSZ_Z1			0xFF	//60h/x/x/x FIFO Size ((Random))
#define HDACMMIO_HDAC_INPUT_STREAM_DESCRIPTOR_FIFO_SIZE_D_INPUT_STREAM_2		0xD0	//HDAC Input Stream Descriptor FIFO Size D) - Input Stream 2
    #define HDACMMIO_FIFOSZ_Z2			0xFF	//60h/x/x/x FIFO Size ((Random))
#define HDACMMIO_HDAC_INPUT_STREAM_DESCRIPTOR_FIFO_SIZE_D_INPUT_STREAM_3		0xF0	//HDAC Input Stream Descriptor FIFO Size D) - Input Stream 3
    #define HDACMMIO_FIFOSZ_Z3			0xFF	//60h/x/x/x FIFO Size ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_FORMAT_D_INPUT_STREAM_0		0x92	//HDAC Stream Descriptor Format D) - Input Stream 0
    #define HDACMMIO_BASE			BIT14	//0/x/x/x Sample Base Rate ((Random))
    #define HDACMMIO_MUL			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Sample Base Rate Multiple ((Random))
    #define HDACMMIO_DIV			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Sample Base Rate Divisor ((Random))
    #define HDACMMIO_VIOD			BIT7	//0/x/x/x Reserved
    #define HDACMMIO_BITS			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Bits Per Sample ((Random))
    #define HDACMMIO_CHNO			0xF	//0/x/x/x Number of Channels ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_FORMAT_D_INPUT_STREAM_1		0xB2	//HDAC Stream Descriptor Format D) - Input Stream 1
    #define HDACMMIO_BASE_Z1			BIT14	//0/x/x/x Sample Base Rate ((Random))
    #define HDACMMIO_MUL_Z1			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Sample Base Rate Multiple ((Random))
    #define HDACMMIO_DIV_Z1			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Sample Base Rate Divisor ((Random))
    #define HDACMMIO_VIOD_Z1			BIT7	//0/x/x/x Reserved
    #define HDACMMIO_BITS_Z1			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Bits Per Sample ((Random))
    #define HDACMMIO_CHNO_Z1			0xF	//0/x/x/x Number of Channels ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_FORMAT_D_INPUT_STREAM_2		0xD2	//HDAC Stream Descriptor Format D) - Input Stream 2
    #define HDACMMIO_BASE_Z2			BIT14	//0/x/x/x Sample Base Rate ((Random))
    #define HDACMMIO_MUL_Z2			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Sample Base Rate Multiple ((Random))
    #define HDACMMIO_DIV_Z2			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Sample Base Rate Divisor ((Random))
    #define HDACMMIO_VIOD_Z2			BIT7	//0/x/x/x Reserved
    #define HDACMMIO_BITS_Z2			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Bits Per Sample ((Random))
    #define HDACMMIO_CHNO_Z2			0xF	//0/x/x/x Number of Channels ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_FORMAT_D_INPUT_STREAM_3		0xF2	//HDAC Stream Descriptor Format D) - Input Stream 3
    #define HDACMMIO_BASE_Z3			BIT14	//0/x/x/x Sample Base Rate ((Random))
    #define HDACMMIO_MUL_Z3			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Sample Base Rate Multiple ((Random))
    #define HDACMMIO_DIV_Z3			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Sample Base Rate Divisor ((Random))
    #define HDACMMIO_VIOD_Z3			BIT7	//0/x/x/x Reserved
    #define HDACMMIO_BITS_Z3			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Bits Per Sample ((Random))
    #define HDACMMIO_CHNO_Z3			0xF	//0/x/x/x Number of Channels ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_FORMAT_D_OUTPUT_STREAM_0		0x112	//HDAC Stream Descriptor Format D) - Output Stream 0
    #define HDACMMIO_BASE_Z4			BIT14	//0/x/x/x Sample Base Rate ((Random))
    #define HDACMMIO_MUL_Z4			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Sample Base Rate Multiple ((Random))
    #define HDACMMIO_DIV_Z4			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Sample Base Rate Divisor ((Random))
    #define HDACMMIO_VIOD_Z4			BIT7	//0/x/x/x Reserved
    #define HDACMMIO_BITS_Z4			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Bits Per Sample ((Random))
    #define HDACMMIO_CHNO_Z4			0xF	//0/x/x/x Number of Channels ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_FORMAT_D_OUTPUT_STREAM_1		0x132	//HDAC Stream Descriptor Format D) - Output Stream 1
    #define HDACMMIO_BASE_Z5			BIT14	//0/x/x/x Sample Base Rate ((Random))
    #define HDACMMIO_MUL_Z5			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Sample Base Rate Multiple ((Random))
    #define HDACMMIO_DIV_Z5			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Sample Base Rate Divisor ((Random))
    #define HDACMMIO_VIOD_Z5			BIT7	//0/x/x/x Reserved
    #define HDACMMIO_BITS_Z5			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Bits Per Sample ((Random))
    #define HDACMMIO_CHNO_Z5			0xF	//0/x/x/x Number of Channels ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_FORMAT_D_OUTPUT_STREAM_2		0x152	//HDAC Stream Descriptor Format D) - Output Stream 2
    #define HDACMMIO_BASE_Z6			BIT14	//0/x/x/x Sample Base Rate ((Random))
    #define HDACMMIO_MUL_Z6			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Sample Base Rate Multiple ((Random))
    #define HDACMMIO_DIV_Z6			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Sample Base Rate Divisor ((Random))
    #define HDACMMIO_VIOD_Z6			BIT7	//0/x/x/x Reserved
    #define HDACMMIO_BITS_Z6			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Bits Per Sample ((Random))
    #define HDACMMIO_CHNO_Z6			0xF	//0/x/x/x Number of Channels ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_FORMAT_D_OUTPUT_STREAM_3		0x172	//HDAC Stream Descriptor Format D) - Output Stream 3
    #define HDACMMIO_BASE_Z7			BIT14	//0/x/x/x Sample Base Rate ((Random))
    #define HDACMMIO_MUL_Z7			(BIT11 + BIT12 + BIT13)	//000b/x/x/x Sample Base Rate Multiple ((Random))
    #define HDACMMIO_DIV_Z7			(BIT8 + BIT9 + BIT10)	//000b/x/x/x Sample Base Rate Divisor ((Random))
    #define HDACMMIO_VIOD_Z7			BIT7	//0/x/x/x Reserved
    #define HDACMMIO_BITS_Z7			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Bits Per Sample ((Random))
    #define HDACMMIO_CHNO_Z7			0xF	//0/x/x/x Number of Channels ((Random))
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_BDL_POINTER_LOWER_BASE_ADR_D_INPUT_STREAM_0		0x98	//HDAC Stream Descriptor BDL Pointer Lower Base Address D) - Input Stream 0
    #define HDACMMIO_BDLLBASE			0xFFFFFF80	//0/x/x/x Buffer Descriptor List (BDL) Lower Base Address
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_BDL_POINTER_LOWER_BASE_ADR_D_INPUT_STREAM_1		0xB8	//HDAC Stream Descriptor BDL Pointer Lower Base Address D) - Input Stream 1
    #define HDACMMIO_BDLLBASE_Z1			0xFFFFFF80	//0/x/x/x Buffer Descriptor List (BDL) Lower Base Address
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_BDL_POINTER_LOWER_BASE_ADR_D_INPUT_STREAM_2		0xD8	//HDAC Stream Descriptor BDL Pointer Lower Base Address D) - Input Stream 2
    #define HDACMMIO_BDLLBASE_Z2			0xFFFFFF80	//0/x/x/x Buffer Descriptor List (BDL) Lower Base Address
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_BDL_POINTER_LOWER_BASE_ADR_D_INPUT_STREAM_3		0xF8	//HDAC Stream Descriptor BDL Pointer Lower Base Address D) - Input Stream 3
    #define HDACMMIO_BDLLBASE_Z3			0xFFFFFF80	//0/x/x/x Buffer Descriptor List (BDL) Lower Base Address
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_BDL_POINTER_LOWER_BASE_ADR_D_OUTPUT_STREAM_0		0x118	//HDAC Stream Descriptor BDL Pointer Lower Base Address D) - Output Stream 0
    #define HDACMMIO_BDLLBASE_Z4			0xFFFFFF80	//0/x/x/x Buffer Descriptor List (BDL) Lower Base Address
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_BDL_POINTER_LOWER_BASE_ADR_D_OUTPUT_STREAM_1		0x138	//HDAC Stream Descriptor BDL Pointer Lower Base Address D) - Output Stream 1
    #define HDACMMIO_BDLLBASE_Z5			0xFFFFFF80	//0/x/x/x Buffer Descriptor List (BDL) Lower Base Address
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_BDL_POINTER_LOWER_BASE_ADR_D_OUTPUT_STREAM_2		0x158	//HDAC Stream Descriptor BDL Pointer Lower Base Address D) - Output Stream 2
    #define HDACMMIO_BDLLBASE_Z6			0xFFFFFF80	//0/x/x/x Buffer Descriptor List (BDL) Lower Base Address
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_BDL_POINTER_LOWER_BASE_ADR_D_OUTPUT_STREAM_3		0x178	//HDAC Stream Descriptor BDL Pointer Lower Base Address D) - Output Stream 3
    #define HDACMMIO_BDLLBASE_Z7			0xFFFFFF80	//0/x/x/x Buffer Descriptor List (BDL) Lower Base Address
#define HDACMMIO_STREAM_DESCRIPTOR_BDL_POINTER_UPPER_BASE_ADR_D_INPUT_STREAM_0		0x9C	//Stream Descriptor BDL Pointer Upper Base Address D) -Input Stream 0
    #define HDACMMIO_BDLUBASE			0xFFFFFFFF	//0/x/x/x Buffer Descriptor List Upper Base Address
#define HDACMMIO_STREAM_DESCRIPTOR_BDL_POINTER_UPPER_BASE_ADR_D_INPUT_STREAM_1		0xBC	//Stream Descriptor BDL Pointer Upper Base Address D) - Input Stream 1
    #define HDACMMIO_BDLUBASE_Z1			0xFFFFFFFF	//0/x/x/x Buffer Descriptor List Upper Base Address
#define HDACMMIO_STREAM_DESCRIPTOR_BDL_POINTER_UPPER_BASE_ADR_D_INPUT_STREAM_2		0xDC	//Stream Descriptor BDL Pointer Upper Base Address D) - Input Stream 2
    #define HDACMMIO_BDLUBASE_Z2			0xFFFFFFFF	//0/x/x/x Buffer Descriptor List Upper Base Address
#define HDACMMIO_STREAM_DESCRIPTOR_BDL_POINTER_UPPER_BASE_ADR_D_INPUT_STREAM_3		0xFC	//Stream Descriptor BDL Pointer Upper Base Address D) - Input Stream 3
    #define HDACMMIO_BDLUBASE_Z3			0xFFFFFFFF	//0/x/x/x Buffer Descriptor List Upper Base Address
#define HDACMMIO_STREAM_DESCRIPTOR_BDL_POINTER_UPPER_BASE_ADR_D_OUTPUT_STREAM_0		0x11C	//Stream Descriptor BDL Pointer Upper Base Address D) - Output Stream 0
    #define HDACMMIO_BDLUBASE_Z4			0xFFFFFFFF	//0/x/x/x Buffer Descriptor List Upper Base Address
#define HDACMMIO_STREAM_DESCRIPTOR_BDL_POINTER_UPPER_BASE_ADR_D_OUTPUT_STREAM_1		0x13C	//Stream Descriptor BDL Pointer Upper Base Address D) - Output Stream 1
    #define HDACMMIO_BDLUBASE_Z5			0xFFFFFFFF	//0/x/x/x Buffer Descriptor List Upper Base Address
#define HDACMMIO_STREAM_DESCRIPTOR_BDL_POINTER_UPPER_BASE_ADR_D_OUTPUT_STREAM_2		0x15C	//Stream Descriptor BDL Pointer Upper Base Address D) - Output Stream 2
    #define HDACMMIO_BDLUBASE_Z6			0xFFFFFFFF	//0/x/x/x Buffer Descriptor List Upper Base Address
#define HDACMMIO_STREAM_DESCRIPTOR_BDL_POINTER_UPPER_BASE_ADR_D_OUTPUT_STREAM_3		0x17C	//Stream Descriptor BDL Pointer Upper Base Address D) - Output Stream 3
    #define HDACMMIO_BDLUBASE_Z7			0xFFFFFFFF	//0/x/x/x Buffer Descriptor List Upper Base Address
#define HDACMMIO_HDAC_OUTPUT_STREAM_DESCRIPTOR_FIFO_SIZE_D_OUTPUT_STREAM_0		0x110	//HDAC Output Stream Descriptor FIFO Size D) - Output Stream 0
    #define HDACMMIO_FIFOSZ_Z4			0x7FF	//040h/400h/x/x FIFO Size ((Random))
#define HDACMMIO_HDAC_OUTPUT_STREAM_DESCRIPTOR_FIFO_SIZE_D_OUTPUT_STREAM_1		0x130	//HDAC Output Stream Descriptor FIFO Size D) - Output Stream 1
    #define HDACMMIO_FIFOSZ_Z5			0x7FF	//040h/400h/x/x FIFO Size ((Random))
#define HDACMMIO_HDAC_OUTPUT_STREAM_DESCRIPTOR_FIFO_SIZE_D_OUTPUT_STREAM_2		0x150	//HDAC Output Stream Descriptor FIFO Size D) - Output Stream 2
    #define HDACMMIO_FIFOSZ_Z6			0x7FF	//040h/400h/x/x FIFO Size ((Random))
#define HDACMMIO_HDAC_OUTPUT_STREAM_DESCRIPTOR_FIFO_SIZE_D_OUTPUT_STREAM_3		0x170	//HDAC Output Stream Descriptor FIFO Size D) - Output Stream 3
    #define HDACMMIO_FIFOSZ_Z7			0x7FF	//040h/400h/x/x FIFO Size ((Random))
#define HDACMMIO_WALL_CLK_CNTER_ALIAS_WALCLKA		0x2030	//Wall Clock Counter Alias - WALCLKA
    #define HDACMMIO_WCOUNTER_Z1			0xFFFFFFFF	//0/x/x/x Wall Clock Counter Alias
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_ALIAS_D_INPUT_STREAM_0		0x2084	//HDAC Stream Descriptor Link Position in Buffer Alias D) - Input Stream 0
    #define HDACMMIO_LPIB_Z8			0xFFFFFFFF	//0/x/x/x Link Position in Buffer Alias
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_ALIAS_D_INPUT_STREAM_1		0x20A4	//HDAC Stream Descriptor Link Position in Buffer Alias D) - Input Stream 1
    #define HDACMMIO_LPIB_Z9			0xFFFFFFFF	//0/x/x/x Link Position in Buffer Alias
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_ALIAS_D_INPUT_STREAM_2		0x20C4	//HDAC Stream Descriptor Link Position in Buffer Alias D) - Input Stream 2
    #define HDACMMIO_LPIB_Z10			0xFFFFFFFF	//0/x/x/x Link Position in Buffer Alias
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_ALIAS_D_INPUT_STREAM_3		0x20E4	//HDAC Stream Descriptor Link Position in Buffer Alias D) - Input Stream 3
    #define HDACMMIO_LPIB_Z11			0xFFFFFFFF	//0/x/x/x Link Position in Buffer Alias
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_ALIAS_D_OUTPUT_STREAM_0		0x2104	//HDAC Stream Descriptor Link Position in Buffer Alias D) - Output Stream 0
    #define HDACMMIO_LPIB_Z12			0xFFFFFFFF	//0/x/x/x Link Position in Buffer Alias
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_ALIAS_D_OUTPUT_STREAM_1		0x2124	//HDAC Stream Descriptor Link Position in Buffer Alias D) - Output Stream 1
    #define HDACMMIO_LPIB_Z13			0xFFFFFFFF	//0/x/x/x Link Position in Buffer Alias
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_ALIAS_D_OUTPUT_STREAM_2		0x2144	//HDAC Stream Descriptor Link Position in Buffer Alias D) - Output Stream 2
    #define HDACMMIO_LPIB_Z14			0xFFFFFFFF	//0/x/x/x Link Position in Buffer Alias
#define HDACMMIO_HDAC_STREAM_DESCRIPTOR_LINK_POSITION_IN_BUFFER_ALIAS_D_OUTPUT_STREAM_3		0x2164	//HDAC Stream Descriptor Link Position in Buffer Alias D) - Output Stream 3
    #define HDACMMIO_LPIB_Z15			0xFFFFFFFF	//0/x/x/x Link Position in Buffer Alias
#endif
