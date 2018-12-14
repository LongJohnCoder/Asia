//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		ESPI					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D11F0_eSPI_R100(A0).doc(final)MOD_ESPICFG.xls
#ifndef _CHX002_D11F0_ESPI_H
#define _CHX002_D11F0_ESPI_H
//D11F0
#define D11F0_VID		0x00	//Vendor ID
    #define D11F0_VID_Z1			0xFFFF	//1D17h/x/x/x Vendor ID
#define D11F0_DID		0x02	//Device ID
    #define D11F0_DID_Z1			0xFFFF	//9300h/x/x/x Device ID
#define D11F0_PCI_CMD		0x04	//PCI Command
    #define D11F0_INT_DIS			BIT10	//0/0/x/x Interrupt Control
    #define D11F0_BME			BIT2	//0/x/x/x Bus Master
    #define D11F0_ESPIMSE			BIT1	//0/x/x/x Memory Space Access
#define D11F0_PCI_STA		0x06	//PCI Status
    #define D11F0_DEVSEL_TIMING			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D11F0_CAPABILITY_LIST			BIT4	//1b/R/x/x Capability List
    #define D11F0_ESPI_INT			BIT3	//0/R/x/x Interrupt Status
#define D11F0_REV_ID		0x08	//Revision ID
    #define D11F0_RID			0xFF	//00h/x/x/x Revision ID
#define D11F0_CLASS_CODE		0x09	//Class Code
    #define D11F0_CLASS_CODE_Z1			0xFFFFFF	//088000h/R/x/x Class Code
#define D11F0_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D11F0_CLS			0xFF	//0/x/x/x Cache Line Size
#define D11F0_LATENCY_TIMER		0x0D	//Latency Timer
#define D11F0_HEADER_TYPE		0x0E	//Header Type
#define D11F0_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
#define D11F0_ESPI_LOWER_BASE_ADR		0x10	//eSPI Lower Base Address
    #define D11F0_ESPILBA			0xFFFFF000	//0/x/x/x eSPI Lower Base Address
#define D11F0_SVID		0x2C	//Subsystem Vendor ID
    #define D11F0_SVID_Z1			0xFFFF	//1106h/1106h/x/x Subsystem Vendor ID
#define D11F0_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D11F0_SID			0xFFFF	//9300h/9300h/x/x Subsystem ID
#define D11F0_EXPANSION_ROM		0x30	//Expansion ROM
#define D11F0_CAP_POINTER		0x34	//Capability Pointer
    #define D11F0_CAP_PTR			0xFF	//50h/R/x/x Capability Pointer
#define D11F0_INTR_LINE		0x3C	//Interrupt Line
    #define D11F0_INT_LN			0xFF	//0/x/x/x Interrupt Line
#define D11F0_INTR_PIN		0x3D	//Interrupt Pin
    #define D11F0_INT_PIN			0xFF	//01h/R/x/x Interrupt Pin
#define D11F0_MINIMUM_GRANT_PERIOD		0x3E	//Minimum Grant Period
#define D11F0_MAXIMUM_LATENCY		0x3F	//Maximum Latency
#define D11F0_BACK_DOOR_ENABLE		0x40	//Back Door Enable
    #define D11F0_SW_DID_RID_LOCK			BIT7	//0/1/x/x Reserved
    #define D11F0_EN_FLRCAP			BIT6	//0/x/x/x Reserved
    #define D11F0_SW_VID_LOCK			BIT5	//0/1/x/x Reserved
    #define D11F0_SW_TP_POSTED_PASS_SW_NON_POSTED_EN			BIT4	//1b/1/x/x SW Transparent MEMW Cycle Pass SW Triggered Non-posted Transaction Enable
    #define D11F0_FLASH_COMPL_LTMPS_SPLIT_EN			BIT3	//1b/x/x/x For eSPI Slave¡¯s Flash Access Channel Request Length + Address Cross MPS Boundary, HW Split Completion to eSPI Slave Enable
    #define D11F0_EN09W			BIT1	//0/0/x/x Class Code Back Door Enable
    #define D11F0_EN2CW			BIT0	//0/0/x/x Subsystem ID / Subsystem Vender ID Back Door Enable
#define D11F0_ESPI_CTL		0x41	//eSPI Control
    #define D11F0_SPI_EBMC_CLK_DYN_EN			BIT6	//0/x/1/1 ESPIFLASH_CTL submodule spi_ebmc_clk Dynamic Clock Enable ((Random))
    #define D11F0_SPI_CFGCLK_DYN_EN			BIT5	//0/x/1/1 ESPIFLASH_CTL submodule spi_cfgclk Dynamic Clock Enable ((Random))
    #define D11F0_EBMCCLK_DYN_EN			BIT4	//0/x/1/1 eBMC Dynamic Clock Enable ((Random))
    #define D11F0_SPICLK_DYN_EN			BIT3	//0/x/1/1 SPICLK Dynamic Clock Enable ((Random))
    #define D11F0_PCICLK_DYN_EN			BIT2	//0/x/1/1 PCICLK Dynamic Clock Enable ((Random))
    #define D11F0_CCACLK_DYN_EN			BIT1	//0/x/1/1 CCACLK Dynamic Clock Enable ((Random))
#define D11F0_ESPI_CTL_Z1		0x42	//eSPI Control
    #define D11F0_ESPICLK_DYN_EN			BIT6	//0/x/1/1 Other Submodule eSPICLK Dynamic Clock Enable ((Random))
    #define D11F0_BUSCTL_ESPICLK_DYN_EN			BIT5	//0/x/1/1 Espi_busctl Submodule eSPICLK Dynamic Clock Enable ((Random))
    #define D11F0_PO_FSM_ESPICLK_DYN_EN			BIT4	//0/x/1/1 Espi_po_fsm Submodule eSPICLK Dynamic Clock Enable ((Random))
    #define D11F0_FLASHCTL_ESPICLK_DYN_EN			BIT3	//0/x/1/1 Espi_flashctl Submodule eSPICLK Dynamic Clock Enable ((Random))
    #define D11F0_REDUNDANT			BIT2	//0/x/1/x Reserved
    #define D11F0_VWCTL_ESPICLK_DYN_EN			BIT1	//0/x/1/1 Espi_vwctl Submodule eSPICLK Dynamic Clock Enable ((Random))
    #define D11F0_PRCTL_ESPICLK_DYN_EN			BIT0	//0/x/1/1 Espi_prctl Submodule eSPICLK Dynamic Clock Enable ((Random))
#define D11F0_ESPI_INPUT_DATA_SAMPLE_CLK_SEL		0x43	//eSPI Input Data Sample Clock Select
    #define D11F0_ESPICLK_DELAY_SEL			0xF	//0/x/x/x Receiver 1st dff Clock Delay Phase Select
#define D11F0_ESPI_REDUNDANT_REGS_1		0x44	//eSPI Redundant Registers 1
    #define D11F0_DBG_GRP_SEL_SEL			BIT15	//0/x/x/x Redundant Registers for ECO
    #define D11F0_DBG_GRP_SEL_REG			0x3FF	//0/x/x/x Redundant Registers for ECO
#define D11F0_ESPI_REDUNDANT_REGS_2		0x46	//eSPI Redundant Registers 2
    #define D11F0_DBG_GRP_G2_SEL_SEL			BIT15	//0/x/x/x Redundant Registers for ECO
    #define D11F0_DBG_GRP_G2_SEL_REG			0x3FF	//0/x/x/x Redundant Registers for ECO
#define D11F0_ESPI_SRC_ID		0x48	//eSPI Source ID
    #define D11F0_ESPI_SOURCEID			0xFFFF	//0058h/x/x/x eSPI Source ID for IOV SID Decode
#define D11F0_BACK_DOOR_ENABLE_Z1		0x4A	//Back Door Enable
    #define D11F0_VW_EN_DISABLE_BEHAVIOR			BIT15	//0/x/x/x Option to Fix the Behavior When ¡°Master Virtual Wire Channel Enable (MMIO Rx68[4])¡± is 0
    #define D11F0_SW_TP_NP_DISCARD_DUE_TO_FLASH_ONGOING_CONDITION_UPDATE			BIT14	//0/x/x/x Option to Decide When to Abort SW Transparent Cycle When It Meets Flash Channel Transaction
    #define D11F0_STOP_PER_CMD_WHEN_PCIRST_ASSERT			BIT13	//0/x/x/x Stop the Current Peripheral CMD before Core Power Is off by HW
    #define D11F0_AUTO_SWITCH_FREQ_EN			BIT12	//0/x/x/x Enable Automatically Send a Switch clk Freq to 13.5M CMD to eSPI Slave just before Core Power Is off by HW
    #define D11F0_MSI_FLUSH_P2CW_EN			BIT11	//0/x/x/x MSI Flush P2CW Enable
    #define D11F0_SWITCH_FREQ_DURING_OOB_FLASH_CMD			BIT10	//0/x/x/x Switch CLK Freq to 13.5M When Flash Channel CMD Is On-going and Core Power Is off
    #define D11F0_REDUNDANT_REG0			(BIT8 + BIT9)	//0/x/x/x Redundant Registers for ECO
    #define D11F0_SW_TP_NP_DISCARD_EN_WHEN_FLASH_ON_GOING			BIT7	//0/x/x/x Abort SW Transparent Non-posted Cycle When Flash Channel Transaction Is On-going
    #define D11F0_SW_TP_NP_DISCARD_EN_WHEN_SW_HANDLE			BIT6	//0/x/x/x Abort SW Transparent Non-posted Cycle When D11F0 Rx4A[0] is 1 and It Is the Duration When It Needs SW to Handle the SW Issued Non-posted Transaction
    #define D11F0_PKT_OR_DMA_ADDRESS			BIT5	//0/x/x/x GET_NP and GET_PC Use PKT Address or DMA Base Address Register as DMA Address in DMA Mode
    #define D11F0_ESPIRST_EN_WHEN_FLR			BIT4	//0/x/x/x Whether eSPI Bus Is Reset When FLR Is Initiated
    #define D11F0_ESPIRST_EN_WHEN_CRST			BIT3	//0/x/x/x Whether eSPI Bus Is Reset When CRST Is Initiated
    #define D11F0_PR_ENABLE_EN			BIT2	//0/x/x/x Auto Issue Peripheral Channel Enable CMD and Polling  Peripheral Channel Ready Status CMD When SW Transparent Cycle Meets Peripheral Channel not Ready
    #define D11F0_SW_TP_NP_DISCARD_EN			BIT1	//0/x/x/x Abort SW Transparent Non-posted Cycle When pc_avail Is 1 and It¡¯s not eSPI SW Issued Non-Posted Transaction On-going 
    #define D11F0_PUT_NON_POSTED_SW_HANDLE_EN			BIT0	//0/x/x/x Enable SW Handle after Trigger Non-posted CMD and before Get 1st Completion from Slave
#define D11F0_ESPI_SLAVE_IRQ_CTL		0x4C	//eSPI Slave IRQ Control
    #define D11F0_ESPI_SLV_IRQ_INVERT			0xFFFF0000	//0/x/x/x eSPI Slave IRQ15
    #define D11F0_ESPI_SLV_IRQ_GATING			0xFFFF	//FFFFh/x/x/x eSPI Slave IRQ15
#define D11F0_PCI_PM_CAPS_ID		0x50	//PCI Power Management Capabilities ID
    #define D11F0_MSI_POINTER			0xFF00	//60h/R/x/x Next Capability Pointer
    #define D11F0_PM_CAP			0xFF	//01h/R/x/x PCI Power Management Capability
#define D11F0_PCI_PM_CAPS		0x52	//PCI Power Management Capabilities
    #define D11F0_PME_ASSERT			0xF800	//19h/R/x/x PME# Can Be Generated from D3 
    #define D11F0_D2_SUPPORT			BIT10	//0/R/x/x D2 State Supported
    #define D11F0_D1_SUPPORT			BIT9	//0/R/x/x D1 State Supported
    #define D11F0_MAX_CURRENT			(BIT6 + BIT7 + BIT8)	//001b/R/x/x Report D3 Max Suspend Current
    #define D11F0_SPECIFIC_INITIAL			BIT5	//0/R/x/x Device-Specific Initialization Requirement
    #define D11F0_PCIP			(BIT0 + BIT1 + BIT2)	//010b/R/x/x PCI Power Support
//B0D11F0
#define B0D11F0_PM_CTL_AND_STA		0x54	//Power Management Control and Status
    #define B0D11F0_PMES			BIT15	//0/x/x/x PME Status
    #define B0D11F0_PMEE			BIT8	//0/x/x/x PME Enable
    #define B0D11F0_PS			(BIT0 + BIT1)	//00b/00b/x/x Power State
//D11F0
#define D11F0_MSI_CAP_ID		0x60	//MSI Capability ID
    #define D11F0_PCIE_POINTER			0xFF00	//70h/R/x/x Next Capability Pointer
    #define D11F0_MSI_CAPABILITY			0xFF	//05h/R/x/x MSI Capability
#define D11F0_MSI_MSG_CTL		0x62	//MSI Message Control
    #define D11F0_ADD_64			BIT7	//1b/R/x/x 64-Bit Address Capability
    #define D11F0_ME			BIT0	//0/x/x/x MSI Enable ((Random))
#define D11F0_MSI_MSG_LOWER_ADR		0x64	//MSI Message Lower Address
    #define D11F0_MLA			0xFFFFFFFC	//0/x/x/x Message Lower Address
#define D11F0_MSI_MSG_UPPER_ADR		0x68	//MSI Message Upper Address
    #define D11F0_MUA			0xFFFFFFFF	//0/x/x/x Message Upper Address
#define D11F0_MSI_DATA		0x6C	//MSI Data
    #define D11F0_MD			0xFFFF	//0/x/x/x Data Used for MSI Message
#define D11F0_MSI_TIMEOUT		0x6E	//MSI Timeout
    #define D11F0_MSI_TIMEOUT_VALUE			0x7F00	//0/x/x/x MSI Timeout Value
    #define D11F0_MSI_TIMEOUT_EN			BIT0	//0/x/x/x MSI Timeout Enable
#define D11F0_ESPI_FUN_LEVEL_RESET_FLR		0x70	//eSPI Function Level Reset (FLR)
    #define D11F0_FLR_CAP			BIT25	//1b/R/x/x FLR Capability
    #define D11F0_TXP_CAP			BIT24	//1b/R/x/x TXP Capability
    #define D11F0_FLR_LEN			0xFF0000	//06h/R/x/x FLR Length (FLR_LEN)
    #define D11F0_FLRID_15_8			0xFF00	//0/R/x/x Next Capability Pointer
    #define D11F0_FLRID_7_0			0xFF	//13h/R/x/x FLR Capabilities ID
#define D11F0_ESPI_FUN_LEVEL_RESET_FLR_Z1		0x74	//eSPI Function Level Reset (FLR)
    #define D11F0_FLR			BIT0	//0/x/x/x Initiate FLR
#define D11F0_ESPI_FUN_LEVEL_RESET_FLR_Z2		0x75	//eSPI Function Level Reset (FLR)
    #define D11F0_TXP			BIT0	//0/R/x/x Transaction Pending
//eSPI-MMIO
#define ESPIMMIO_RESET		0x00	//Reset
    #define ESPIMMIO_CRST			BIT1	//0/x/x/x eSPI Controller Reset
    #define ESPIMMIO_PIN_RST			BIT0	//0/x/x/x eSPI Reset# Pin Reset
#define ESPIMMIO_PERIPHERAL_CHN_CMD_OPCODE		0x04	//Peripheral Channel Command Opcode
    #define ESPIMMIO_SW_TX_LEN			0xFFF00000	//0/x/x/x Length Field in Command Header
    #define ESPIMMIO_SW_TX_TAG			0xF0000	//0/x/x/x Tag Field in Command Header
    #define ESPIMMIO_SW_TX_CYCLE_TYPE			0xFF00	//0/x/x/x Cycle Type Field in Command Header
    #define ESPIMMIO_SW_CMD_OP			0xFF	//0/x/x/x Command Opcode
#define ESPIMMIO_LOWER_ADR_FIELD_IN_PERIPHERAL_CHN_CMD_HEADER		0x08	//Lower Address Field in Peripheral Channel Command Header
    #define ESPIMMIO_SW_TX_ADDR_31_0			0xFFFFFFFF	//0/x/x/x Lower 32-bit Address Field in Command Header
#define ESPIMMIO_UPPER_ADR_FIELD_IN_PERIPHERAL_CHN_CMD_HEADER		0x0C	//Upper Address Field in Peripheral Channel Command Header
    #define ESPIMMIO_SW_TX_ADDR_63_32			0xFFFFFFFF	//0/x/x/x Upper 32-bit Address Field in Command Header
#define ESPIMMIO_MSG_CODE_FIELD_IN_PERIPHERAL_CHN_CMD_HEADER		0x10	//Message Code Field in Peripheral Channel Command Header
    #define ESPIMMIO_SW_TX_MSG_CODE			0xFF	//0/x/x/x Message Code Field in Command Header
#define ESPIMMIO_MSG_DATA_FIELD_IN_PERIPHERAL_CHN_CMD		0x14	//Message data Field in Peripheral Channel Command
    #define ESPIMMIO_SW_TX_MSG_BYTE3			0xFF000000	//0/x/x/x Message Specific Byte3 Field in Command Data
    #define ESPIMMIO_SW_TX_MSG_BYTE2			0xFF0000	//0/x/x/x Message Specific Byte2 Field in Command Data
    #define ESPIMMIO_SW_TX_MSG_BYTE1			0xFF00	//0/x/x/x Message Specific Byte1 Field in Command Data
    #define ESPIMMIO_SW_TX_MSG_BYTE0			0xFF	//0/x/x/x Message Specific Byte0 Feld in Command Data
#define ESPIMMIO_SHORT_DATA_IN_CMD		0x18	//Short Data in Command
    #define ESPIMMIO_SW_TX_SHORT_DATA			0xFFFFFFFF	//0/x/x/x Data in PUT*SHORT Command
#define ESPIMMIO_ADR_IN_SET_GET_CONFIGURATIN_CMD		0x1C	//Address in SET/GET_CONFIGURATIN Command
    #define ESPIMMIO_SW_TX_CONFIG_ADDR			0xFFFF	//0/x/x/x Address in SET/GET_CONFIGURATIN Command
#define ESPIMMIO_DATA_IN_SET_CONFIGURATIN_CMD		0x20	//Data in SET_CONFIGURATIN Command
    #define ESPIMMIO_SW_TX_CONFIG_DATA			0xFFFFFFFF	//0/x/x/x Data in SET_CONFIGURATIN Command
#define ESPIMMIO_SW_TRIGGERED_CHN_INDEPENDENT_PERIPHERAL_CHN_VIRTUAL_WIRE_CHN_RESPONSE_OPCODE		0x24	//SW Triggered Channel Independent / Peripheral Channel / Virtual Wire Channel Response Opcode
    #define ESPIMMIO_SW_RX_LEN			0xFFF00000	//0/R/x/x Length Field in Response Header for SW Triggered Peripheral Channel Command
    #define ESPIMMIO_SW_RX_TAG			0xF0000	//0/R/x/x Tag Field in Response Header for SW Triggered Peripheral Channel Command
    #define ESPIMMIO_SW_RX_CYCLE_TYPE			0xFF00	//0/R/x/x Cycle Type Field in Response Header for SW Triggered Peripheral Channel Command
    #define ESPIMMIO_SW_RSP_OP			0xFF	//0/R/x/x Response Opcode for SW Triggered Channel Independent / Peripheral Channel / Virtual Wire Channel Command
#define ESPIMMIO_LOWER_ADR_FIELD_IN_SW_TRIGGERED_CHN_INDEPENDENT_AND_PERIPHERAL_CHN_RESPONSE_HEADER		0x28	//Lower Address Field in SW Triggered Channel Independent and Peripheral Channel Response Header
    #define ESPIMMIO_SW_RX_ADDR_31_0			0xFFFFFFFF	//0/R/x/x Lower 32-bit Address Field in Response Header for SW Triggered Peripheral Channel Command
#define ESPIMMIO_UPPER_ADR_FIELD_IN_SW_TRIGGERED_CHN_INDEPENDENT_AND_PERIPHERAL_CHN_RESPONSE_HEADER		0x2C	//Upper Address Field in SW Triggered Channel Independent and Peripheral Channel Response Header
    #define ESPIMMIO_SW_RX_ADDR_63_32			0xFFFFFFFF	//0/R/x/x Upper 32-bit Address Field in Response Header for SW Triggered Peripheral Channel Command
#define ESPIMMIO_MSG_CODE_FIELD_IN_SW_TRIGGERED_PERIPHERAL_CHN_RESPONSE_HEADER		0x30	//Message Code Field in SW Triggered Peripheral Channel response Header
    #define ESPIMMIO_SW_RX_MSG_CODE			0xFF	//0/R/x/x Message Code Field in Response Header for SW Triggered Peripheral Channel Command
#define ESPIMMIO_MSG_DATA_FIELD_IN_SW_TRIGGERED_PERIPHERAL_CHN_RESPONSE		0x34	//Message data Field in SW Triggered Peripheral Channel Response
    #define ESPIMMIO_SW_RX_MSG_BYTE3			0xFF000000	//0/R/x/x Message Specific Byte 3 Field in Response Data for SW Triggered Peripheral Channel Command
    #define ESPIMMIO_SW_RX_MSG_BYTE2			0xFF0000	//0/R/x/x Message Specific Byte 2 Field in Response Data for SW Triggered Peripheral Channel Command
    #define ESPIMMIO_SW_RX_MSG_BYTE1			0xFF00	//0/R/x/x Message Specific Byte 1 Field in Response Data for SW Triggered Peripheral Channel Command
    #define ESPIMMIO_SW_RX_MSG_BYTE0			0xFF	//0/R/x/x Message Specific Byte 0 Field in Response Data for SW Triggered Peripheral Channel Command
#define ESPIMMIO_SHORT_DATA_IN_SW_TRIGGERED_PERIPHERAL_CHN_RESPONSE		0x38	//Short Data in SW Triggered Peripheral Channel response
    #define ESPIMMIO_SW_RX_SHORT_DATA			0xFFFFFFFF	//0/R/x/x Data in PUT*SHORT Response for SW Triggered Peripheral Channel Command
#define ESPIMMIO_STA_IN_SW_TRIGGERED_CHN_INDEPENDENT_PERIPHERAL_CHN_VIRTUAL_WIRE_CHN_RESPONSE		0x3C	//Status in SW Triggered Channel Independent / Peripheral Channel / Virtual Wire Channel Response
    #define ESPIMMIO_SW_RX_STATUS			0xFFFF	//30fh/R/x/x Status in Response for SW Triggered Channel Independent / Peripheral Channel / Virtual Wire Channel command
#define ESPIMMIO_DATA_IN_SW_TRIGGERED_GET_CONFIGURATIN_RESPONSE		0x40	//Data in SW Triggered GET_CONFIGURATIN Response
    #define ESPIMMIO_SW_RX_CONFIG_DATA			0xFFFFFFFF	//0/R/x/x Data in Response for SW Triggered GET_CONFIGURATIN Command
#define ESPIMMIO_DMA_LOWER_BASE_ADR		0x50	//DMA Lower Base Address
    #define ESPIMMIO_DMA_ADDR_31_0			0xFFFFFFFF	//0/x/x/x DMA Lower Base Address
#define ESPIMMIO_DMA_UPPER_BASE_ADR		0x54	//DMA Upper Base Address
    #define ESPIMMIO_REDUN			0x3F00	//0/x/x/x Reserved
    #define ESPIMMIO_DMA_ADDR_39_32			0xFF	//0/x/x/x DMA Upper Base Address
#define ESPIMMIO_DATA_BUFFER_PORT_IN_PIO_MODE		0x58	//Data Buffer Port in PIO Mode
    #define ESPIMMIO_DATA_BUF			0xFFFFFFFF	//0/x/x/x Data Buffer Port in PIO Mode
#define ESPIMMIO_DMA_MODE		0x5C	//DMA Mode
    #define ESPIMMIO_DMA_MODE_Z1			BIT0	//1b/x/x/x DMA Mode
#define ESPIMMIO_DMA_POINTER_LOWER_BITS		0x60	//DMA Pointer Lower Bits
    #define ESPIMMIO_DMA_POINTER_31_0			0xFFFFFFFF	//0/R/x/x DMA Pointer Lower 32 Bits
#define ESPIMMIO_BUFFER_POINTER_UPPER_BITS		0x64	//Buffer Pointer Upper Bits
    #define ESPIMMIO_DMA_POINTER_39_32			0x3FFF	//0/R/x/x DMA Pointer Upper Bits
#define ESPIMMIO_VW_CTL		0x68	//VW Control
    #define ESPIMMIO_ESPI_VW_EN			BIT4	//1b/x/x/x Master Virtual Wire Channel Enable
    #define ESPIMMIO_ESPI_VW_GPI_RST_SEL			BIT3	//0/x/x/x GPI Reset Source Select
    #define ESPIMMIO_ESPI_VW_SUSPEND_SW_TRIGGEREN			BIT2	//0/x/x/x S3/S4/S5/SUS_STAT VW Packet Trigger by SW or HW
    #define ESPIMMIO_ESPI_VW_NMI_SW_TRIGGEREN			BIT1	//0/x/x/x NMIOUT VW Packet Trigger by SW or HW
    #define ESPIMMIO_ESPI_VW_SMI_SW_TRIGGEREN			BIT0	//0/x/x/x SMIOUT VW Packet Trigger by SW or HW
#define ESPIMMIO_NMIOUT_VW_CTL		0x69	//NMIOUT VW Control
    #define ESPIMMIO_ESPI_VW_NMIOUT_HW			BIT1	//0/R/x/x HW NMIOUT Value
    #define ESPIMMIO_ESPI_VW_NMIOUT_SW			BIT0	//0/x/x/x Trigger NMIOUT VW Packet
#define ESPIMMIO_SMIOUT_VW_CTL		0x6A	//SMIOUT VW Control
    #define ESPIMMIO_ESPI_VW_SMIOUT_HW			BIT1	//0/R/x/x HW SMIOUT Value
    #define ESPIMMIO_ESPI_VW_SMIOUT_SW			BIT0	//0/x/x/x Trigger SMIOUT VW Packet
#define ESPIMMIO_HOST_RST_WARN_VW_CTL		0x6B	//HOST_RST_WARN VW Control
    #define ESPIMMIO_ESPI_VW_HOST_RST_WARN			BIT0	//0/x/x/x Trigger HOST_RST_WARN VW Packet
#define ESPIMMIO_S3_VW_CTL		0x6C	//S3 VW Control
    #define ESPIMMIO_ESPI_VW_S3_HW			BIT1	//0/R/x/x HW S3 Value
    #define ESPIMMIO_ESPI_VW_S3_SW			BIT0	//0/x/x/x Trigger S3 VW Packet
#define ESPIMMIO_S4_VW_CTL		0x6D	//S4 VW Control
    #define ESPIMMIO_ESPI_VW_S4_HW			BIT1	//0/R/x/x HW S4 Value
    #define ESPIMMIO_ESPI_VW_S4_SW			BIT0	//0/x/x/x Trigger S4 VW Packet
#define ESPIMMIO_S5_VW_CTL		0x6E	//S5 VW Control
    #define ESPIMMIO_ESPI_VW_S5_HW			BIT1	//0/R/x/x HW S5 Value
    #define ESPIMMIO_ESPI_VW_S5_SW			BIT0	//0/x/x/x Trigger S5 VW Packet
#define ESPIMMIO_SUS_STAT_VW_CTL		0x6F	//SUS_STAT VW Control
    #define ESPIMMIO_ESPI_VW_SUST_HW			BIT1	//0/R/x/x HW SUS_STAT Value
    #define ESPIMMIO_ESPI_VW_SUST_SW			BIT0	//0/x/x/x Trigger SUS_STAT VW Packet
#define ESPIMMIO_GPO_INDEX_AND_DATA_TO_SEND		0x70	//GPO Index and Data to Send
    #define ESPIMMIO_ESPI_VW_GPO_DATA			0xFF00	//0/x/x/x GPO Data to Send
    #define ESPIMMIO_ESPI_VW_GPO_INDEX			0xFF	//0/x/x/x GPO Index to Send
#define ESPIMMIO_ESPI_PWR_ON_RESULT_AND_SLAVE_EVENT_STA		0x74	//eSPI Power On Result and Slave Event Status
    #define ESPIMMIO_PO_SEQ_DONE			BIT7	//HwInit/x/x/x HW Auto Power on Sequence Finish (In Bypass eSPI mode, this bit is 1)
    #define ESPIMMIO_RCIN_STS			BIT6	//1b/R/x/x eSPI Slave RCIN# Status
    #define ESPIMMIO_BOOTSTATUS_STS			BIT5	//HwInit/x/x/x eSPI Slave SLAVE_BOOT_LOAD_STATUS Status
    #define ESPIMMIO_BOOTDONE_STS			BIT4	//HwInit/x/x/x Espi slave SLAVE_BOOT_LOAD_DONE Status
    #define ESPIMMIO_PO_RSP_ERR			BIT3	//HwInit/x/x/x There Is rsp Error during HW Auto Power on Sequence
    #define ESPIMMIO_VW_SUPPORTED			BIT2	//HwInit/x/x/x Virtual Wire Channel Is Supported by Slave during HW auto Power on Sequence
    #define ESPIMMIO_NO_ESPI_SLV			BIT1	//HwInit/x/x/x No eSPI Slave Detected during HW Auto Power on Sequence
    #define ESPIMMIO_PO_SEQ_OK			BIT0	//HwInit/x/x/x HW Auto Power on Sequence Success
#define ESPIMMIO_ESPI_SLAVE_EVENT_STA		0x78	//eSPI Slave Event Status
    #define ESPIMMIO_HOST_RST_ACK_STS			BIT3	//0/x/x/x eSPI Slave HOST_RST_ACK Status
    #define ESPIMMIO_SMI_STS			BIT2	//0/x/x/x eSPI Slave SMI# Status
    #define ESPIMMIO_SCI_STS			BIT1	//0/x/x/x eSPI Slave SCI# Status
    #define ESPIMMIO_WAKE_STS			BIT0	//0/x/x/x eSPI Slave Wake# Status
#define ESPIMMIO_ESPI_SLAVE_EVENT_SCI_SMI_ENABLE		0x7C	//eSPI Slave Event SCI/SMI Enable
    #define ESPIMMIO_HOST_RST_ACK_IRQ_EN			BIT4	//0/x/x/x eSPI Slave HOST_RST_ACK Generate SCI/SMI Interrupt Enable
    #define ESPIMMIO_RCIN_EN			BIT3	//0/x/x/x Enable eSPI Slave RCIN# Sent to CPU
    #define ESPIMMIO_SMI_SMIEN			BIT2	//0/x/x/x Enable  eSPI Slave SMI# Assertion Pass to PMU
    #define ESPIMMIO_SCI_SCIEN			BIT1	//0/x/x/x Enable eSPI Slave SCI# Assertion Pass to PMU
    #define ESPIMMIO_WAKE_EN			BIT0	//0/x/x/x Enable eSPI Slave Wake# Pass to PMU
#define ESPIMMIO_GPI_CHANGE_COUNT_REG		0x80	//GPI Change Count Register
    #define ESPIMMIO_ESPI_VW_GPI_UPDATE_CNT			(BIT0 + BIT1 + BIT2)	//0/R/x/x GPI Change Count
#define ESPIMMIO_VIRTUAL_WIRE_COUNT_RECEIVED		0x84	//Virtual Wire Count Received
    #define ESPIMMIO_RX_VW_CNT			0xFF	//0/R/x/x Virtual Wire Count Received
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_AND_DATA_RECEIVED		0x90	//Virtual Wire Index and Data Received
    #define ESPIMMIO_RX_VW_DATA_2			0xFF000000	//0/R/x/x 2nd Virtual Wire Data Received
    #define ESPIMMIO_RX_VW_INDEX_2			0xFF0000	//0/R/x/x 2nd Virtual Wire Index Received
    #define ESPIMMIO_RX_VW_DATA_1			0xFF00	//HwInit/x/x/x 1st Virtual Wire Data Received
    #define ESPIMMIO_RX_VW_INDEX_1			0xFF	//HwInit/x/x/x 1st Virtual Wire Index Received
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_AND_DATA_RECEIVED_Z1		0x94	//Virtual Wire Index and Data Received
    #define ESPIMMIO_RX_VW_DATA_4			0xFF000000	//0/R/x/x 4th Virtual Wire Data Received
    #define ESPIMMIO_RX_VW_INDEX_4			0xFF0000	//0/R/x/x 4th Virtual Wire Index Received
    #define ESPIMMIO_RX_VW_DATA_3			0xFF00	//0/R/x/x 3rd Virtual Wire Data Received
    #define ESPIMMIO_RX_VW_INDEX_3			0xFF	//0/R/x/x 3rd Virtual Wire Index Received
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_AND_DATA_RECEIVED_Z2		0x98	//Virtual Wire Index and Data Received
    #define ESPIMMIO_RX_VW_DATA_6			0xFF000000	//0/R/x/x 6th Virtual Wire Data Received
    #define ESPIMMIO_RX_VW_INDEX_6			0xFF0000	//0/R/x/x 6th Virtual Wire Index Received
    #define ESPIMMIO_RX_VW_DATA_5			0xFF00	//0/R/x/x 5th Virtual Wire Data Received
    #define ESPIMMIO_RX_VW_INDEX_5			0xFF	//0/R/x/x 5th Virtual Wire Index Received
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_AND_DATA_RECEIVED_Z3		0x9C	//Virtual Wire Index and Data Received
    #define ESPIMMIO_RX_VW_DATA_8			0xFF000000	//0/R/x/x 8th Virtual Wire Data Received
    #define ESPIMMIO_RX_VW_INDEX_8			0xFF0000	//0/R/x/x 8th Virtual Wire Index Received
    #define ESPIMMIO_RX_VW_DATA_7			0xFF00	//0/R/x/x 7th Virtual Wire Data Received
    #define ESPIMMIO_RX_VW_INDEX_7			0xFF	//0/R/x/x 7th Virtual Wire Index Received
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_135_128		0xA0	//Virtual Wire Index 255~128¡¯s Data Value D) - Virtual Wire Index 135~128
    #define ESPIMMIO_GPI_VALUE			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_143_136		0xA4	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 143~136
    #define ESPIMMIO_GPI_VALUE_Z1			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_151_144		0xA8	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 151~144
    #define ESPIMMIO_GPI_VALUE_Z2			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_159_152		0xAC	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 159~152
    #define ESPIMMIO_GPI_VALUE_Z3			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_167_160		0xB0	//Virtual Wire Index 255~128¡¯s Data Value D) - Virtual Wire Index 167~160
    #define ESPIMMIO_GPI_VALUE_Z4			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_175_168		0xB4	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 175~168
    #define ESPIMMIO_GPI_VALUE_Z5			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_183_176		0xB8	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 183~176
    #define ESPIMMIO_GPI_VALUE_Z6			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_191_184		0xBC	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 191~184
    #define ESPIMMIO_GPI_VALUE_Z7			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_199_192		0xC0	//Virtual Wire Index 255~128¡¯s Data Value D) - Virtual Wire Index 199~192
    #define ESPIMMIO_GPI_VALUE_Z8			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_207_200		0xC4	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 207~200
    #define ESPIMMIO_GPI_VALUE_Z9			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_215_208		0xC8	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 215~208
    #define ESPIMMIO_GPI_VALUE_Z10			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_223_216		0xCC	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 223~216
    #define ESPIMMIO_GPI_VALUE_Z11			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_231_224		0xD0	//Virtual Wire Index 255~128¡¯s Data Value D) - Virtual Wire Index 231~224
    #define ESPIMMIO_GPI_VALUE_Z12			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_239_232		0xD4	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 239~232
    #define ESPIMMIO_GPI_VALUE_Z13			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_247_240		0xD8	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 247~240
    #define ESPIMMIO_GPI_VALUE_Z14			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_VIRTUAL_WIRE_INDEX_255_128_S_DATA_VALUE_D_VIRTUAL_WIRE_INDEX_255_248		0xDC	//Virtual Wire Index 255~128¡¯s Data Value D) -Virtual Wire Index 255~248
    #define ESPIMMIO_GPI_VALUE_Z15			0xFFFFFFFF	//0/R/x/x Virtual Wire Index 128+8n+7
#define ESPIMMIO_CAP		0x100	//Capability
    #define ESPIMMIO_FBES			(BIT28 + BIT29 + BIT30)	//001b/R/x/x Flash Block Erase Size in Master Attached Flash Sharing Scheme 
    #define ESPIMMIO_FMPS			(BIT24 + BIT25 + BIT26)	//HwInit/x/x/x Flash Access Channel Maximum Payload Size Selected 
    #define ESPIMMIO_FMRRS			(BIT20 + BIT21 + BIT22)	//HwInit/x/x/x Flash Access Channel Maximum Read Request Size
    #define ESPIMMIO_REDUNDANT2			(BIT16 + BIT17 + BIT18)	//001b/R/x/x Reserved
    #define ESPIMMIO_PMPS			(BIT12 + BIT13 + BIT14)	//001b/R/x/x Peripheral Channel Maximum Payload Size Selected
    #define ESPIMMIO_PMRRS			(BIT8 + BIT9 + BIT10)	//001b/R/x/x Peripheral Channel Maximum Read Request Size 
    #define ESPIMMIO_CRC_EN			BIT5	//0/R/x/x CRC Checking Enable
    #define ESPIMMIO_IO_MODE			(BIT3 + BIT4)	//HwInit/x/x/x I/O Mode
    #define ESPIMMIO_FREQUENCY			(BIT0 + BIT1 + BIT2)	//0/R/x/x Operating Frequency
#define ESPIMMIO_SW_TRIGGERED_TRANSACTION_STA		0x110	//SW Triggered Transaction Status
    #define ESPIMMIO_P_UNEXPECTED_COMPL			BIT22	//0/x/x/x SW Triggered Peripheral Channel Unexpected Completion  (completion without non-posted request) Received Status
    #define ESPIMMIO_GET_OWNERSHIP_DONE			BIT21	//0/x/x/x eSPI SW Get Ownership Status
    #define ESPIMMIO_DATA_RDY_STATUS			BIT20	//0/x/x/x Data Ready Status for PIO Read
    #define ESPIMMIO_PC_FREE_TIMEOUT			BIT19	//0/x/x/x PC_FREE Timeout Status
    #define ESPIMMIO_PC_AVAIL_TIMEOUT			BIT18	//0/x/x/x PC_AVAIL Timeout Status
    #define ESPIMMIO_NP_AVAIL_STS			BIT17	//0/x/x/x NP_AVAIL Assert Status
    #define ESPIMMIO_PC_AVAIL_STS			BIT16	//0/x/x/x PC_AVAIL Assert Status
    #define ESPIMMIO_NP_FREE_STS			BIT15	//0/x/x/x NP_FREE Assert Status
    #define ESPIMMIO_PC_FREE_STS			BIT14	//0/x/x/x PC_FREE Assert Status
    #define ESPIMMIO_DMARD_DONE			BIT13	//0/x/x/x DMA Read Done Status
    #define ESPIMMIO_DMAWR_DONE			BIT12	//0/x/x/x DMA Write Done Status
    #define ESPIMMIO_P_INVALID_TAG			BIT11	//0/x/x/x SW Triggered Peripheral Channel Completion with Invalid Tag Received Status
    #define ESPIMMIO_P_UNSCCESS_COMPL			BIT10	//0/x/x/x SW Triggered Peripheral Channel Unsuccessful Completion Received Status 
    #define ESPIMMIO_P_ADDR_LEN_CROSS_4K			BIT9	//0/x/x/x SW Triggered Peripheral Channel (Address + Length) Crosses 4KB (aligned) Boundary Status
    #define ESPIMMIO_P_RRS_MT_PMRRS			BIT8	//0/x/x/x SW Triggered Peripheral Channel Read Request size > Max Read Request Size (aligned) Status
    #define ESPIMMIO_P_LEN_MT_PMPS			BIT7	//0/x/x/x SW Triggered Peripheral Channel Payload length > Max Payload Size (aligned) Status
    #define ESPIMMIO_SW_RSP_OP_NONFATAL_ERR			BIT6	//0/x/x/x NONFATAL_ERROR Response Code Status for SW Triggered Transaction  (by writing MMIO Rx04h register)
    #define ESPIMMIO_SW_RSP_OP_FATAL_ERR			BIT5	//0/x/x/x FATAL_ERROR Response Code Status for SW Triggered Transaction  (by writing MMIO Rx04h register)
    #define ESPIMMIO_SW_NO_RSP			BIT4	//0/x/x/x No Response Status (After Initialization Phase) for SW Triggered Transaction  (by writing MMIO Rx04h register)
    #define ESPIMMIO_SW_CRC_ERR_STS			BIT3	//0/x/x/x Response CRC Error Status for SW Triggered Transaction (by writing MMIO Rx04h register)
    #define ESPIMMIO_SW_INVALID_CYCLE_TYPE			BIT2	//0/x/x/x Invalid Cycle Type Status for SW Triggered Transaction  (by writing MMIO Rx04h register)
    #define ESPIMMIO_SW_INVALID_RSP_OP			BIT1	//0/x/x/x Invalid Response Code Status for SW Triggered Transaction  (by writing MMIO Rx04h register)
    #define ESPIMMIO_REC_DONE			BIT0	//0/x/x/x SW Triggered Transaction (by writing MMIO Rx04h register) Done on eSPI Bus Status
#define ESPIMMIO_VW_CHN_TRANSACTION_STA		0x114	//VW Channel Transaction Status
    #define ESPIMMIO_VW_REC_DONE			BIT11	//HwInit/x/x/x VW Transaction Done on eSPI Bus Status (for debug purpose)
    #define ESPIMMIO_SW_VW_REC_DONE			BIT10	//0/x/x/x SW Triggered VW Transaction Done on eSPI Bus Status
    #define ESPIMMIO_ERROR_NONFATAL_VW			BIT9	//0/x/x/x Receive ERROR NON FATAL Virtual Wire Status
    #define ESPIMMIO_ERROR_FATAL_VW			BIT8	//0/x/x/x Receive ERROR FATAL Virtual Wire Status
    #define ESPIMMIO_VW_CNT_ERR			BIT7	//0/x/x/x Virtual Wire Channel  Count > Max Virtual Wire Count Status
    #define ESPIMMIO_VW_RSP_OP_NONFATAL_ERR			BIT6	//0/x/x/x NONFATAL_ERROR Response Code Status for VW Channel Transaction
    #define ESPIMMIO_VW_RSP_OP_FATAL_ERR			BIT5	//0/x/x/x FATAL_ERROR Response Code Status for VW Channel Transaction
    #define ESPIMMIO_VW_NO_RSP			BIT4	//0/x/x/x No Response Status (After Initialization Phase) for VW Channel Transaction
    #define ESPIMMIO_VW_CRC_ERR_STS			BIT3	//0/x/x/x Response CRC Error Status for VW Channel Transaction
    #define ESPIMMIO_VW_INVALID_RSP_OP			BIT1	//0/x/x/x Invalid Response Code Status for VW Channel Transaction
    #define ESPIMMIO_GPI_REC_DONE			BIT0	//0/x/x/x GPI Receive Done Status
#define ESPIMMIO_HW_AUTO_ISSUED_GET_STA_TRANSACTION_STA		0x116	//HW Auto Issued GET_STATUS Transaction Status
    #define ESPIMMIO_HW_GET_STATUS_RSP_OP_NONFATAL_ERR			BIT6	//0/x/x/x NONFATAL_ERROR Response Code Status for Hardware Auto Issued GET_STATUS Transaction
    #define ESPIMMIO_HW_GET_STATUS_RSP_OP_FATAL_ERR			BIT5	//0/x/x/x FATAL_ERROR Response Code Status for Hardware Auto Issued GET_STATUS Transaction
    #define ESPIMMIO_HW_GET_STATUS_NO_RSP			BIT4	//0/x/x/x No Response Status (After Initialization Phase) for Hardware Auto Issued GET_STATUS Transaction
    #define ESPIMMIO_HW_GET_STATUS_CRC_ERR_STS			BIT3	//0/x/x/x Response CRC Error Status for Hardware Auto Issued GET_STATUS Transaction
    #define ESPIMMIO_HW_GET_STATUS_INVALID_RSP_OP			BIT1	//0/x/x/x Invalid Response Code Status for Hardware Auto Issued GET_STATUS Transaction
#define ESPIMMIO_FLASH_CHN_TRANSACTION_STA		0x118	//Flash Channel Transaction Status
    #define ESPIMMIO_FLASH_INVALID_TAG			BIT11	//0/x/x/x Flash Channel Completion with Invalid Tag Received Status
    #define ESPIMMIO_FLASH_UNSCCESS_COMPL			BIT10	//0/x/x/x Flash Channel Unsuccessful Completion Received Status
    #define ESPIMMIO_FLASH_ERASE_LENTH_ERR			BIT9	//0/x/x/x Flash Erase Length is More than 2
    #define ESPIMMIO_FLASH_RRS_MT_FMRRS			BIT8	//0/x/x/x Flash Access Channel Read Request Size > Max Read Request Size Status
    #define ESPIMMIO_FLASH_LEN_MT_FMPS			BIT7	//0/x/x/x Flash Access Channel Payload Length > Max Payload Size Status
    #define ESPIMMIO_FLASH_RSP_OP_NONFATAL_ERR			BIT6	//0/x/x/x NONFATAL_ERROR Response Code Status for Flash Channel Transaction
    #define ESPIMMIO_FLASH_RSP_OP_FATAL_ERR			BIT5	//0/x/x/x FATAL_ERROR Response Code Status for Flash Channel Transaction
    #define ESPIMMIO_FLASH_NO_RSP			BIT4	//0/x/x/x No Response Status (After Initialization Phase) for Flash Channel Transaction
    #define ESPIMMIO_FLASH_CRC_ERR_STS			BIT3	//0/x/x/x Response CRC Error Status for Flash Channel Transaction
    #define ESPIMMIO_FLASH_INVALID_CYCLE_TYPE			BIT2	//0/x/x/x Invalid Cycle Type Status for Flash Channel Transaction
    #define ESPIMMIO_FLASH_INVALID_RSP_OP			BIT1	//0/x/x/x Invalid Response Code Status for Flash Channel Transaction
#define ESPIMMIO_OTHER_INTR_STA		0x11C	//Other Interrupt Status
    #define ESPIMMIO_SW_TP_NP_FREE_TIMEOUT			BIT26	//0/x/x/x SW Transparent Cycle NP_FREE Timeout Status
    #define ESPIMMIO_SW_TP_PC_FREE_TIMEOUT			BIT25	//0/x/x/x SW Transparent Cycle PC_FREE Timeout Status
    #define ESPIMMIO_SW_TP_PC_AVAIL_TIMEOUT			BIT24	//0/x/x/x SW Transparent Cycle PC_AVAIL Timeout Status
    #define ESPIMMIO_SW_TP_UNSCCESS_COMPL			BIT23	//0/x/x/x SW Transparent Cycle Unsuccessful Completion Received Status 
    #define ESPIMMIO_SW_TP_RSP_OP_NONFATAL_ERR			BIT22	//0/x/x/x NONFATAL_ERROR Response Code Status for SW Transparent Cycle
    #define ESPIMMIO_SW_TP_RSP_OP_FATAL_ERR			BIT21	//0/x/x/x FATAL_ERROR Response Code Status for SW Transparent Cycle
    #define ESPIMMIO_SW_TP_NO_RSP			BIT20	//0/x/x/x No Response Status (After Initialization Phase) for SW Transparent Cycle
    #define ESPIMMIO_SW_TP_CRC_ERR_STS			BIT19	//0/x/x/x Response CRC Error Status for SW Transparent Cycle
    #define ESPIMMIO_SW_TP_INVALID_CYCLE_TYPE			BIT18	//0/x/x/x Invalid Cycle Type Status for SW Transparent Cycle
    #define ESPIMMIO_SW_TP_INVALID_RSP_OP			BIT17	//0/x/x/x Invalid Response Code Status for SW Transparent Cycle
    #define ESPIMMIO_RESET_DEASSERT_BY_SLAVE			BIT13	//0/x/x/x Slave De-assert eSPI Reset# Pin
    #define ESPIMMIO_SW_TP_FAIL			BIT12	//0/x/x/x SW Transparent Cycle Fail because eSPI Slave Assert eSPI Reset# Pin
    #define ESPIMMIO_FLASH_FAIL			BIT11	//0/x/x/x eSPI Flash Channel Transfer Fail  because eSPI Slave Assert eSPI Reset# Pin
    #define ESPIMMIO_VW_FAIL			BIT10	//0/x/x/x eSPI Virtual Wire Channel Transfer Fail  because eSPI Slave Assert eSPI Reset# Pin
    #define ESPIMMIO_SW_FAIL			BIT9	//0/x/x/x SW Triggered Transfer Fail  because eSPI Slave Assert eSPI Reset# Pin
    #define ESPIMMIO_RESET_ASSERT_BY_SLAVE			BIT8	//0/x/x/x eSPI Reset# Pin is Asserted by eSPI Slave Status
#define ESPIMMIO_SW_TRIGGERED_TRANSACTION_GENERATE_SCI_SMI_NMI_INTR_ENABLE		0x120	//SW Triggered Transaction Generate SCI/SMI/NMI/Interrupt Enable
    #define ESPIMMIO_P_UNEXPECTED_COMPL_IRQ_EN			BIT22	//0/x/x/x SW triggered Peripheral Channel Unexpected Completion (completion without non-posted request) Received Generate SCI/SMI/interrupt Enable
    #define ESPIMMIO_GET_OWNERSHIP_DONE_IRQ_EN			BIT21	//0/x/x/x eSPI SW Get Ownership Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_DATA_RDY_IRQ_EN			BIT20	//0/x/x/x Data Ready for PIO Read Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_PC_FREE_TIMEOUT_IRQ_EN			BIT19	//0/x/x/x PC_FREE Timeout Generate SCI/SMI/Interrupt Enable 
    #define ESPIMMIO_PC_AVAIL_TIMEOUT_IRQ_EN			BIT18	//0/x/x/x PC_AVAIL Timeout Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_NP_AVAIL_IRQ_EN			BIT17	//0/x/x/x NP_AVAIL Assert Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_PC_AVAIL_IRQ_EN			BIT16	//0/x/x/x PC_AVAIL Assert Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_NP_FREE_IRQ_EN			BIT15	//0/x/x/x NP_FREE Assert Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_PC_FREE_IRQ_EN			BIT14	//0/x/x/x PC_FREE Assert Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_DMARD_DONE_IRQ_EN			BIT13	//0/x/x/x DMA Read Done Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_DMAWR_DONE_IRQ_EN			BIT12	//0/x/x/x DMA Write Done Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_P_INVALID_TAG_IRQ_EN			BIT11	//0/x/x/x SW Triggered Peripheral Channel Completion with Invalid Tag Received Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_P_UNSCCESS_COMPL_IRQ_EN			BIT10	//0/x/x/x SW Triggered Peripheral Channel Unsuccessful Completion Received Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_P_ADDR_LEN_CROSS_4K_IRQ_EN			BIT9	//0/x/x/x SW Triggered Peripheral Channel (Address + Length) Crosses 4KB (aligned) Boundary Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_P_RRS_MT_PMRRS_IRQ_EN			BIT8	//0/x/x/x SW Triggered Peripheral Channel Read Request Size > Max Read Request Size (aligned) Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_P_LEN_MT_PMPS_IRQ_EN			BIT7	//0/x/x/x SW Triggered Peripheral Channel Payload length > Max Payload Size (aligned) Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_SW_RSP_OP_NONFATAL_ERR_IRQ_EN			BIT6	//0/x/x/x NONFATAL_ERROR Response Code for SW Triggered Transaction  (by writing MMIO Rx04h register) Generate SCI/SMI/Interrupt Enable 
    #define ESPIMMIO_SW_RSP_OP_FATAL_ERR_IRQ_EN			BIT5	//0/x/x/x FATAL_ERROR Response Code for SW Triggered Transaction  (by writing MMIO Rx04h register) Generate SCI/SMI/NMI Enable 
    #define ESPIMMIO_SW_NO_RSP_IRQ_EN			BIT4	//0/x/x/x No Response for SW Triggered Transaction Generate (by writing MMIO Rx04h register) SCI/SMI/NMI Enable (After initialization phase)
    #define ESPIMMIO_SW_CRC_ERR_IRQ_EN			BIT3	//0/x/x/x Response CRC Error for SW Triggered Transaction  (by writing MMIO Rx04h register) Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_SW_INVALID_CYCLE_TYPE_IRQ_EN			BIT2	//0/x/x/x Invalid Cycle Type for SW Triggered Transaction  (by writing MMIO Rx04h register) Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_SW_INVALID_RSP_OP_IRQ_EN			BIT1	//0/x/x/x Invalid Response Code for SW Triggered Transaction  (by writing MMIO Rx04h register) Generate SCI/SMI/NMI Enable 
    #define ESPIMMIO_REC_DONE_IRQ_EN			BIT0	//0/x/x/x SW Triggered Transaction (by writing MMIO Rx04h register) Done on eSPI Bus Generate SCI/SMI/Interrupt Enable
#define ESPIMMIO_VW_CHN_TRANSACTION_GENERATE_SCI_SMI_NMI_INTR_ENABLE		0x124	//VW Channel Transaction Generate SCI/SMI/NMI/Interrupt Enable
    #define ESPIMMIO_VW_REC_DONE_IRQ_EN			BIT11	//0/x/x/x VW Transaction Done on eSPI Bus Generate SCI/SMI/I0nterrupt Enable  (for debug purpose)
    #define ESPIMMIO_SW_VW_REC_DONE_IRQ_EN			BIT10	//0/x/x/x SW Triggered VW Transaction Done on eSPI Bus Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_ERROR_NONFATAL_VW_IRQ_EN			BIT9	//0/x/x/x Receive ERROR NON FATAL Virtual Wire Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_ERROR_FATAL_VW_IRQ_EN			BIT8	//0/x/x/x Receive ERROR FATAL Virtual Wire Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_VW_CNT_MT_MCNT_IRQ_EN			BIT7	//0/x/x/x Virtual Wire Channel  Count > Max Virtual Wire Count generate SCI/SMI/NMI Enable
    #define ESPIMMIO_VW_RSP_OP_NONFATAL_ERR_IRQ_EN			BIT6	//0/x/x/x NONFATAL_ERROR Response Code for VW Channel Transaction Generate SCI/SMI/Interrupt Enable 
    #define ESPIMMIO_VW_RSP_OP_FATAL_ERR_IRQ_EN			BIT5	//0/x/x/x FATAL_ERROR Response Code for VW Channel Transaction Generate SCI/SMI/NMI Enable 
    #define ESPIMMIO_VW_NO_RSP_IRQ_EN			BIT4	//0/x/x/x No Response for VW Channel Transaction Generate SCI/SMI/NMI Enable (After initialization phase)
    #define ESPIMMIO_VW_CRC_ERR_IRQ_EN			BIT3	//0/x/x/x Response CRC Error for VW Channel Transaction Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_VW_INVALID_RSP_OP_IRQ_EN			BIT1	//0/x/x/x Invalid Response Code for VW Channel Transaction Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_GPI_REC_DONE_IRQ_EN			BIT0	//0/x/x/x GPI Receive Done Generate SCI/SMI/Interrupt Enable
#define ESPIMMIO_HW_AUTO_ISSUED_GET_STA_TRANSACTION_GENERATE_SCI_SMI_NMI_INTR_ENABLE		0x126	//HW Auto Issued GET_STATUS Transaction Generate SCI/SMI/NMI/Interrupt Enable
    #define ESPIMMIO_HW_GET_STATUS_RSP_OP_NONFATAL_ERR_IRQ_EN			BIT6	//0/x/x/x NONFATAL_ERROR Response Code for Hardware Auto Issued GET_STATUS Transaction Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_HW_GET_STATUS_RSP_OP_FATAL_ERR_IRQ_EN			BIT5	//0/x/x/x FATAL_ERROR Response Code for Hardware Auto Issued GET_STATUS Transaction Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_HW_GET_STATUS_NO_RSP_IRQ_EN			BIT4	//0/x/x/x No Response (After Initialization Phase) for Hardware Auto Issued GET_STATUS Transaction Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_HW_GET_STATUS_CRC_ERR_STS_IRQ_EN			BIT3	//0/x/x/x Response CRC Error for Hardware Auto Issued GET_STATUS Transaction Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_HW_GET_STATUS_INVALID_RSP_OP_IRQ_EN			BIT1	//0/x/x/x Invalid Response Code for Hardware auto Issued GET_STATUS Transaction Generate SCI/SMI/NMI Enable
#define ESPIMMIO_FLASH_CHN_TRANSACTION_GENERATE_SCI_SMI_NMI_INTR_ENABLE		0x128	//Flash Channel Transaction Generate SCI/SMI/NMI/Interrupt Enable
    #define ESPIMMIO_FLASH_INVALID_TAG_IRQ_EN			BIT11	//0/x/x/x Flash Channel Completion with Invalid Tag Received Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_FLASH_UNSCCESS_COMPL_IRQ_EN			BIT10	//0/x/x/x Flash Channel Unsuccessful Completion Received Generate SCI/SMI/Interrupt Enable 
    #define ESPIMMIO_FLASH_ERASE_LENTH_ERR_IRQ_EN			BIT9	//0/x/x/x Flash Erase Length Is More Than 2 Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_FLASH_RRS_MT_FMRRS_IRQ_EN			BIT8	//0/x/x/x Flash Access Channel Read Request Size > Max Read Request Size Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_FLASH_LEN_MT_FMPS_IRQ_EN			BIT7	//0/x/x/x Flash Access Channel Payload length > Max Payload Size Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_FLASH_RSP_OP_NONFATAL_ERR_IRQ_EN			BIT6	//0/x/x/x NONFATAL_ERROR Response Code for Flash Channel Transaction Generate SCI/SMI/Interrupt Enable 
    #define ESPIMMIO_FLASH_RSP_OP_FATAL_ERR_IRQ_EN			BIT5	//0/x/x/x FATAL_ERROR Response Code for Flash Channel Transaction Generate SCI/SMI/NMI Enable 
    #define ESPIMMIO_FLASH_NO_RSP_IRQ_EN			BIT4	//0/x/x/x No Response for Flash Channel Transaction Generate SCI/SMI/NMI Enable (After Initialization Phase)
    #define ESPIMMIO_FLASH_CRC_ERR_IRQ_EN			BIT3	//0/x/x/x Response CRC Error for Flash Channel Transaction Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_FLASH_INVALID_CYCLE_TYPE_IRQ_EN			BIT2	//0/x/x/x Invalid Cycle Type for Flash Channel Transaction Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_FLASH_INVALID_RSP_OP_IRQ_EN			BIT1	//0/x/x/x Invalid Response Code for Flash Channel Transaction Generate SCI/SMI/NMI Enable
#define ESPIMMIO_OTHER_INTR_GENERATE_SCI_SMI_NMI_INTR_ENABLE		0x12C	//Other Interrupt Generate SCI/SMI/NMI/Interrupt Enable
    #define ESPIMMIO_SW_TP_NP_FREE_TIMEOUT_IRQ_EN			BIT26	//0/x/x/x SW Transparent Cycle NP_FREE Timeout Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_SW_TP_PC_FREE_TIMEOUT_IRQ_EN			BIT25	//0/x/x/x SW Transparent Cycle PC_FREE Timeout Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_SW_TP_PC_AVAIL_TIMEOUT_IRQ_EN			BIT24	//0/x/x/x SW Transparent Cycle PC_AVAIL Timeout Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_SW_TP_UNSCCESS_COMPL_IRQ_EN			BIT23	//0/x/x/x SW Transparent Cycle Unsuccessful Completion Received  Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_SW_TP_RSP_OP_NONFATAL_ERR_IRQ_EN			BIT22	//0/x/x/x NONFATAL_ERROR Response Code for SW Transparent Cycle Generate SCI/SMI/Interrupt Enable 
    #define ESPIMMIO_SW_TP_RSP_OP_FATAL_ERR_IRQ_EN			BIT21	//0/x/x/x FATAL_ERROR Response Code for SW Transparent Cycle Generate SCI/SMI/NMI Enable 
    #define ESPIMMIO_SW_TP_NO_RSP_IRQ_EN			BIT20	//0/x/x/x No Response for SW Transparent Cycle Generate SCI/SMI/NMI Enable £¨After initialization phase)
    #define ESPIMMIO_SW_TP_CRC_ERR_IRQ_EN			BIT19	//0/x/x/x Response CRC Error for SW Transparent Cycle Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_SW_TP_INVALID_CYCLE_TYPE_IRQ_EN			BIT18	//0/x/x/x Invalid Cycle Type for SW Transparent Cycle Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_SW_TP_INVALID_RSP_OP_IRQ_EN			BIT17	//0/x/x/x Invalid Response Code for SW Transparent Cycle Generate SCI/SMI/NMI Enable
    #define ESPIMMIO_RESET_DEASSERT_BY_SLAVE_IRQ_EN			BIT13	//0/x/x/x Slave De-assert eSPI Reset# Pin Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_SW_TP_FAIL_IRQ_EN			BIT12	//0/x/x/x SW Transparent Cycle Fail Because eSPI Slave Assert eSPI Reset# Pin Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_FLASH_FAIL_IRQ_EN			BIT11	//0/x/x/x eSPI Flash Channel Transfer Fail Because eSPI Slave Assert eSPI Reset# Pin Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_VW_FAIL_IRQ_EN			BIT10	//0/x/x/x eSPI Virtual Wire Channel Transfer Fail Because eSPI Slave Assert eSPI Reset# Pin Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_SW_FAIL_IRQ_EN			BIT9	//0/x/x/x SW Triggered Transfer Fail Because eSPI Slave Assert eSPI Reset# Pin Generate SCI/SMI/Interrupt Enable
    #define ESPIMMIO_RESET_ASSERT_BY_SLAVE_IRQ_EN			BIT8	//0/x/x/x eSPI Reset# Pin Is Asserted by eSPI Slave Status Generate SCI/SMI/Interrupt Enable
#define ESPIMMIO_SCI_SMI_NMI_INTR_ENABLE		0x130	//SCI/SMI/NMI/Interrupt Enable
    #define ESPIMMIO_ESPI_NMI_EN			BIT4	//0/x/x/x eSPI NMI Enable
    #define ESPIMMIO_INTERRUPT_SMI_SCI_SELECT			(BIT2 + BIT3)	//0/x/x/x Interrupt/SMI/SCI Select for Non-fatal Error and Interrupt Event When MSI Is Disabled (D11F0 Rx62[0])
    #define ESPIMMIO_NMI_SMI_SCI_SELECT			(BIT0 + BIT1)	//0/x/x/x NMI/SMI/SCI/Interrupt Select for Fatal Error When MSI Is Disabled (D11F0 Rx62[0])
#define ESPIMMIO_INTR_TYPE		0x132	//Interrupt Type
    #define ESPIMMIO_FATAL_ERR			BIT10	//0/R/x/x Fatal Error Happens
    #define ESPIMMIO_NON_FATAL_ERR			BIT9	//0/R/x/x Non-fatal Error Happens
    #define ESPIMMIO_IRQ_EVENT			BIT8	//0/R/x/x Interrupt Event  Happens
    #define ESPIMMIO_SW_TP_TRANSFER			BIT4	//0/R/x/x SW Transparent Cycle Which Generates the Interrupt Event or Non-fatal Error or Fatal Error (Some bits in MMIO Rx11C[24:17, 12] are asserted and its corresponding interrupt enable bit is set to 1.)
    #define ESPIMMIO_FLASH_CHANNEL			BIT3	//0/R/x/x Flash Channel Which Generates the Interrupt Event or Non-fatal Error or Fatal Error
    #define ESPIMMIO_GET_STATUS			BIT2	//0/R/x/x Hardware Auto Issued GET_STATUS Which Generates the Interrupt Event or Non-fatal Error or Fatal Error
    #define ESPIMMIO_VW_CHANNEL			BIT1	//0/R/x/x Virtual Wire Channel Which Generates the Interrupt Event or Non-fatal Error or Fatal Error (Some bits in MMIO Rx78[10,7:6] / Rx114-115 / Rx11C[10] are asserted and its corresponding interrupt enable bit is set to 1.)
    #define ESPIMMIO_SW_TRIGGERED_CMD			BIT0	//0/R/x/x SW Triggered Transaction Which Generates the Interrupt Event or Non-fatal Error or Fatal Error
#define ESPIMMIO_PC_AVAIL_PC_FREE_TIMEOUT_ENABLE		0x134	//PC_AVAIL/PC_FREE TIMEOUT Enable
    #define ESPIMMIO_TIMEOUT_ENABLE			BIT0	//0/x/x/x PC_AVAIL/PC_FREE TIMEOUT Enable
#define ESPIMMIO_PC_AVAIL_PC_FREE_TIMEOUT_VALUE		0x138	//PC_AVAIL/PC_FREE TIMEOUT VALUE
    #define ESPIMMIO_TIMEOUT_VALUE			0xFFFFFFFF	//00000000h/x/x/x PC_AVAIL/PC_FREE TIMEOUT Value (eSPI Operating Clock Cycle Number)
#define ESPIMMIO_SW_TRANSPARENT_CYCLE_FAIL_RETRY		0x13C	//SW Transparent Cycle Fail Retry
    #define ESPIMMIO_SW_TP_FAIL_RETRY_EN			BIT7	//0/x/x/x SW Transparent Cycle Fail Retry Enable
    #define ESPIMMIO_SW_TP_FAIL_RETRY_TIMES			(BIT0 + BIT1 + BIT2)	//0/x/x/x SW Transparent Cycle Fail Retry Times
#define ESPIMMIO_GET_RELEASE_OWNERSHIP		0x140	//Get / Release Ownership
    #define ESPIMMIO_RELEASE_OWNERSHIP			BIT1	//0/x/x/x Release Ownership
    #define ESPIMMIO_GET_OWNERSHIP			BIT0	//0/x/x/x Get Ownership
#define ESPIMMIO_FLASH_SHARING_MODE		0x160	//Flash Sharing Mode
    #define ESPIMMIO_ESPI_SLV_ATTACH_MODE			BIT1	//HwInit/x/x/x Slave Attached Flash Sharing Mode
    #define ESPIMMIO_ESPI_MST_ATTACH_MODE			BIT0	//HwInit/x/x/x Master Attached Flash Sharing Mode
#define ESPIMMIO_RESPONSE_OPCODE		0x174	//Response Opcode
    #define ESPIMMIO_RX_LEN			0xFFF00000	//0/R/x/x Length Field in Response Header
    #define ESPIMMIO_RX_TAG			0xF0000	//0/R/x/x Tag Field in Response Header
    #define ESPIMMIO_RX_CYCLE_TYPE			0xFF00	//0/R/x/x Cycle Type Field in Response Header
    #define ESPIMMIO_RSP_OP			0xFF	//HwInit/x/x/x Response Opcode
#define ESPIMMIO_LOWER_ADR_FIELD_IN_RESPONSE_HEADER		0x178	//Lower Address Field in Response Header
    #define ESPIMMIO_RX_ADDR_31_0			0xFFFFFFFF	//0/R/x/x Lower 32-bit Address Field in Response Reader
#define ESPIMMIO_UPPER_ADR_FIELD_IN_RESPONSE_HEADER		0x17C	//Upper Address Field in Response Header
    #define ESPIMMIO_RX_ADDR_63_32			0xFFFFFFFF	//0/R/x/x Upper 32-bit Address Field in Response Header
#define ESPIMMIO_SHORT_DATA_IN_RESPONSE		0x188	//Short Data in Response
    #define ESPIMMIO_RX_SHORT_DATA			0xFFFFFFFF	//0/R/x/x Data in PUT*SHORT Response
#define ESPIMMIO_STA_IN_RESPONSE		0x18C	//Status in Response
    #define ESPIMMIO_RX_STATUS			0xFFFF	//30fh/R/x/x Status in Response
#define ESPIMMIO_DATA_IN_GET_CONFIGURATIN_RESPONSE		0x190	//Data in GET_CONFIGURATIN Response
    #define ESPIMMIO_RX_CONFIG_DATA			0xFFFFFFFF	//HwInit/x/x/x Data in GET_CONFIGURATIN Response
#define ESPIMMIO_OFFSET_ADR_200H_ESPI_MMIO_VW_GPI0_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_D_VW_GPI0_SCI_SMI_ENABLE		0x200	//Offset Address: 200h (ESPI-MMIO) - VW GPI0 SCI/SMI EnableVW GPI SCI/SMI Enable D) - VW GPI0 SCI/SMI Enable
    #define ESPIMMIO_GPI_SMI_EN			BIT3	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_GPI_SCI_EN			BIT2	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_TRIGGER_MODE			(BIT0 + BIT1)	//0/x/x/x Trigger Mode for VW GPIn (n:0
#define ESPIMMIO_OFFSET_ADR_201H_ESPI_MMIO_VW_GPI1_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_D_VW_GPI1_SCI_SMI_ENABLE		0x201	//Offset Address: 201h (ESPI-MMIO) - VW GPI1 SCI/SMI EnableVW GPI SCI/SMI Enable D) - VW GPI1 SCI/SMI Enable
    #define ESPIMMIO_GPI_SMI_EN_Z1			BIT3	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_GPI_SCI_EN_Z1			BIT2	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_TRIGGER_MODE_Z1			(BIT0 + BIT1)	//0/x/x/x Trigger Mode for VW GPIn (n:0
#define ESPIMMIO_OFFSET_ADR_202H_ESPI_MMIO_VW_GPI2_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_D_VW_GPI2_SCI_SMI_ENABLE		0x202	//Offset Address: 202h (ESPI-MMIO) - VW GPI2 SCI/SMI EnableVW GPI SCI/SMI Enable D) - VW GPI2 SCI/SMI Enable
    #define ESPIMMIO_GPI_SMI_EN_Z2			BIT3	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_GPI_SCI_EN_Z2			BIT2	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_TRIGGER_MODE_Z2			(BIT0 + BIT1)	//0/x/x/x Trigger Mode for VW GPIn (n:0
#define ESPIMMIO_OFFSET_ADR_203H_ESPI_MMIO_VW_GPI3_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_D_VW_GPI3_SCI_SMI_ENABLE		0x203	//Offset Address: 203h (ESPI-MMIO) - VW GPI3 SCI/SMI EnableVW GPI SCI/SMI Enable D) - VW GPI3 SCI/SMI Enable
    #define ESPIMMIO_GPI_SMI_EN_Z3			BIT3	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_GPI_SCI_EN_Z3			BIT2	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_TRIGGER_MODE_Z3			(BIT0 + BIT1)	//0/x/x/x Trigger Mode for VW GPIn (n:0
#define ESPIMMIO_OFFSET_ADR_204H_ESPI_MMIO_VW_GPI4_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_D_VW_GPI4_SCI_SMI_ENABLE		0x204	//Offset Address: 204h (ESPI-MMIO) - VW GPI4 SCI/SMI EnableVW GPI SCI/SMI Enable D) - VW GPI4 SCI/SMI Enable
    #define ESPIMMIO_GPI_SMI_EN_Z4			BIT3	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_GPI_SCI_EN_Z4			BIT2	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_TRIGGER_MODE_Z4			(BIT0 + BIT1)	//0/x/x/x Trigger Mode for VW GPIn (n:0
#define ESPIMMIO_OFFSET_ADR_205H_ESPI_MMIO_VW_GPI5_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_D_VW_GPI5_SCI_SMI_ENABLE		0x205	//Offset Address: 205h (ESPI-MMIO) - VW GPI5 SCI/SMI EnableVW GPI SCI/SMI Enable D) - VW GPI5 SCI/SMI Enable
    #define ESPIMMIO_GPI_SMI_EN_Z5			BIT3	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_GPI_SCI_EN_Z5			BIT2	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_TRIGGER_MODE_Z5			(BIT0 + BIT1)	//0/x/x/x Trigger Mode for VW GPIn (n:0
#define ESPIMMIO_OFFSET_ADR_206H_ESPI_MMIO_VW_GPI6_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_D_VW_GPI6_SCI_SMI_ENABLE		0x206	//Offset Address: 206h (ESPI-MMIO) - VW GPI6 SCI/SMI EnableVW GPI SCI/SMI Enable D) - VW GPI6 SCI/SMI Enable
    #define ESPIMMIO_GPI_SMI_EN_Z6			BIT3	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_GPI_SCI_EN_Z6			BIT2	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_TRIGGER_MODE_Z6			(BIT0 + BIT1)	//0/x/x/x Trigger Mode for VW GPIn (n:0
#define ESPIMMIO_OFFSET_ADR_207H_ESPI_MMIO_VW_GPI7_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_D_VW_GPI7_SCI_SMI_ENABLEVW_GPI_SCI_SMI_ENABLE_DEFAULT_VALUE_00H		0x207	//Offset Address: 207h (ESPI-MMIO) - VW GPI7 SCI/SMI EnableVW GPI SCI/SMI Enable D) - VW GPI7 SCI/SMI EnableVW GPI SCI/SMI Enable Default Value: 00h
    #define ESPIMMIO_GPI_SMI_EN_Z7			BIT3	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_GPI_SCI_EN_Z7			BIT2	//0/x/x/x Enable  eSPI Slave VW GPIn (n:0
    #define ESPIMMIO_TRIGGER_MODE_Z7			(BIT0 + BIT1)	//0/x/x/x Trigger Mode for VW GPIn (n:0
#define ESPIMMIO_VW_GPI_SCI_SMI_STA		0x208	//VW GPI SCI/SMI Status
    #define ESPIMMIO_GPI_STS			0xFF	//0/x/x/x VW GPI7
#define ESPIMMIO_SW_TRANSPARENT_CYCLE_NP_FREE_PC_FREE_TIMEOUT_ENABLE		0x210	//SW Transparent Cycle NP_FREE/PC_FREE TIMEOUT Enable
    #define ESPIMMIO_NP_FREE_OR_PC_FREE_TIMEOUT_ENABLE			BIT0	//0/x/x/x SW Transparent Cycle NP_FREE/PC_FREE TIMEOUT Enable
#define ESPIMMIO_SW_TRANSPARENT_CYCLE_NP_FREE_PC_FREE_TIMEOUT_VALUE		0x214	//SW Transparent Cycle NP_FREE/PC_FREE TIMEOUT Value
    #define ESPIMMIO_NP_FREE_OR_PC_FREETIMEOUT_VALUE			0xFFFFFFFF	//00000000h/x/x/x SW Transparent Cycle NP_FREE/PC_FREE TIMEOUT Value (eSPI Operating Clock Cycle Number)
#endif
