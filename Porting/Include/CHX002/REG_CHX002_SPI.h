//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		SPI					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_SPI_R101(A0).xls
#ifndef _CHX002_SPI_H
#define _CHX002_SPI_H
//SPI0-MMIO
#define SPI0MMIO_SPI_STA_SPIS		0x00	//SPI Status (SPIS)
    #define SPI0MMIO_CLD			BIT15	//0/0/x/x SPI Configuration Lock-Down 
    #define SPI0MMIO_RESERVED			0x7FC0	//0/x/x/x Reserved
    #define SPI0MMIO_GET_OWNERSHIP_DONE			BIT5	//0/x/x/x SPI SW Get Ownership Status
    #define SPI0MMIO_SPIBIOS			BIT4	//0/R/x/x Strapping Value of BIOS Boot from SPI ROM
    #define SPI0MMIO_BAS			BIT3	//0/0/x/x Blocked Access Status
    #define SPI0MMIO_BUS_CDS			BIT2	//0/0/x/x SPI Bus 0 Cycle Done Status
    #define SPI0MMIO_FEMPTY			BIT1	//1b/R/x/x SPI Bus Internal FIFO Empty Flag
    #define SPI0MMIO_SCIP			BIT0	//0/R/x/x SPI Cycle Progress 
#define SPI0MMIO_SPI_CTL_SPIC		0x02	//SPI Control (SPIC)
    #define SPI0MMIO_SMIEN			BIT15	//0/x/x/x SPI SMI# Enable 
    #define SPI0MMIO_DAC			BIT14	//1b/x/x/x Data Cycle
    #define SPI0MMIO_PORTSEL_1_0			(BIT12 + BIT13)	//00b/x/x/x Bus 0 Port Select[1:0] 
    #define SPI0MMIO_DBC			0xF00	//0/x/x/x Data Byte Count
    #define SPI0MMIO_DACS			BIT7	//0/x/x/x Data Atomic Cycle Sequence
    #define SPI0MMIO_COP			(BIT4 + BIT5 + BIT6)	//0/x/x/x Cycle Opcode Pointer
    #define SPI0MMIO_SPOP			BIT3	//0/x/x/x Sequence Prefix Opcode Pointer
    #define SPI0MMIO_ACS			BIT2	//1b/x/x/x Atomic Cycle Sequence
    #define SPI0MMIO_BUS_SCGO			BIT1	//0/x/x/x SPI Cycle Go 
    #define SPI0MMIO_FREN			BIT0	//0/x/x/x SPI Fast Read Enable 
#define SPI0MMIO_SPI_ADR_SPIA		0x04	//SPI Address (SPIA)
    #define SPI0MMIO_RESERVED_Z1			0xFF000000	//0/x/x/x Reserved
    #define SPI0MMIO_SCA			0xFFFFFF	//0/x/x/x SPI Cycle Address [23:0] ((Random))
#define SPI0MMIO_SPI_DATA_0_REG_SPID0		0x08	//SPI Data 0 Register (SPID0)
    #define SPI0MMIO_SCD_0			0xFFFFFFFFFFFFFFFF	//0/x/x/x SPI Cycle Data[0] ((Random))
#define SPI0MMIO_SPI_DATA_1_REG_SPID1		0x10	//SPI Data 1 Register (SPID1)
    #define SPI0MMIO_SCD_1			0xFFFFFFFFFFFFFFFF	//0/x/x/x SPI Cycle Data[1] ((Random))
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_EXTEND_STA_AND_TAG_REG		0x18	//eSPI Slave Attached Mode Extend Status and Tag Register
    #define SPI0MMIO_TAG0			0xFFFFFF00	//0/x/x/x Tag[95:72]
    #define SPI0MMIO_EXTENDSTATUS			0xFF	//0/x/x/x Extend Status
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_TAG_1_REG		0x1C	//eSPI Slave Attached Mode Tag 1 Register
    #define SPI0MMIO_TAG1			0xFFFFFFFF	//0/x/x/x Tag[71:40]
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_TAG_2_REG		0x20	//eSPI Slave Attached Mode Tag 2 Register
    #define SPI0MMIO_TAG2			0xFFFFFFFF	//0/x/x/x Tag[39:8]
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_TAG_3_REG		0x24	//eSPI Slave Attached Mode Tag 3 Register
    #define SPI0MMIO_TAG3			0xFF000000	//0/x/x/x Tag[7:0]
    #define SPI0MMIO_COUNTERDATA0			0xFFFFFF	//0/x/x/x CounterData[31:8]
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_CNTER_DATA_REG		0x28	//eSPI Slave Attached Mode Counter Data Register
    #define SPI0MMIO_COUNTERDATA1			0xFF000000	//0/x/x/x CounterData[7:0]
    #define SPI0MMIO_SIGNATURE0			0xFFFFFF	//0/x/x/x Signature [255:232]
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_SIGNATURE_1_REG		0x2C	//eSPI Slave Attached Mode Signature 1 Register
    #define SPI0MMIO_SIGNATURE1			0xFFFFFFFF	//0/x/x/x Signature [231:200]
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_SIGNATURE_2_REG		0x30	//eSPI Slave Attached Mode Signature 2 Register
    #define SPI0MMIO_SIGNATURE2			0xFFFFFFFF	//0/x/x/x Signature 1
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_SIGNATURE_3_REG		0x34	//eSPI Slave Attached Mode Signature 3 Register
    #define SPI0MMIO_SIGNATURE3			0xFFFFFFFF	//0/x/x/x Signature 3
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_SIGNATURE_4_REG		0x38	//eSPI Slave Attached Mode Signature 4 Register
    #define SPI0MMIO_SIGNATURE4			0xFFFFFFFF	//0/x/x/x Signature 4
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_SIGNATURE_5_REG		0x3C	//eSPI Slave Attached Mode Signature 5 Register
    #define SPI0MMIO_SIGNATURE5			0xFFFFFFFF	//0/x/x/x Signature 5
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_SIGNATURE_6_REG		0x40	//eSPI Slave Attached Mode Signature 6 Register
    #define SPI0MMIO_SIGNATURE6			0xFFFFFFFF	//0/x/x/x Signature 6
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_SIGNATURE_7_REG		0x44	//eSPI Slave Attached Mode Signature 7 Register
    #define SPI0MMIO_SIGNATURE7			0xFFFFFFFF	//0/x/x/x Signature 7
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_SIGNATURE_8_REG		0x48	//eSPI Slave Attached Mode Signature 8 Register
    #define SPI0MMIO_RESERVED_Z2			0xFFFFFF00	//0/x/x/x Reserved
    #define SPI0MMIO_SIGNATURE8			0xFF	//0/x/x/x Signature 8.
#define SPI0MMIO_SPI_BUS_0_CYCLE_CTL		0x4C	//SPI Bus 0 Cycle Control
    #define SPI0MMIO_LEN_EN			BIT31	//0/x/x/x Bus 0 Length Check Enable
    #define SPI0MMIO_CYC_TYPE			(BIT29 + BIT30)	//00b/x/x/x Bus 0 Cycle Type
    #define SPI0MMIO_RESERVED_Z3			0x1E000000	//0/x/x/x Reserved
    #define SPI0MMIO_R_LEN			0x1FF0000	//0/x/x/x Bus 0 Read Length ((Random))
    #define SPI0MMIO_RESERVED_Z4			0xFE00	//0/x/x/x Reserved
    #define SPI0MMIO_W_LEN			0x1FF	//0/x/x/x Bus 0 Write Length ((Random))
#define SPI0MMIO_BIOS_BASE_ADR_BBAR		0x50	//BIOS Base Address (BBAR)
    #define SPI0MMIO_BBAR			0xFFFFFF00	//0/x/x/x Bottom of System Flash
    #define SPI0MMIO_RESERVED_Z5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define SPI0MMIO_ECO_RST_SEL			BIT4	//0/x/x/x Reserved
    #define SPI0MMIO_HW_AUTO_SWITCH			BIT3	//0/x/x/x Option Bit for HW Auto Switch to PIO Mode and Port Select = 00b in Master Attached Mode
    #define SPI0MMIO_HW_AUTO_RES			BIT2	//0/x/x/x Option Bit for HW Auto Release Ownership Instead of SW
    #define SPI0MMIO_RELEASE_OWNERSHIP			BIT1	//0/x/x/x Release Ownership
    #define SPI0MMIO_GET_OWNERSHIP			BIT0	//0/x/x/x Get Ownership
#define SPI0MMIO_PREFIX_OPCODE_CFG_PREOP		0x54	//Prefix Opcode Configuration (PREOP)
    #define SPI0MMIO_PREOP1			0xFF00	//0/x/x/x Prefix Opcode 1
    #define SPI0MMIO_PREOP0			0xFF	//04h/x/x/x Prefix Opcode 0
#define SPI0MMIO_OPCODE_TYPE_CFG_OPTYPE		0x56	//Opcode Type Configuration (OPTYPE)
    #define SPI0MMIO_OPT7			(BIT14 + BIT15)	//00b/x/x/x Opcode Type7
    #define SPI0MMIO_OPT6			(BIT12 + BIT13)	//00b/x/x/x Opcode Type6
    #define SPI0MMIO_OPT5			(BIT10 + BIT11)	//00b/x/x/x Opcode Type5
    #define SPI0MMIO_OPT4			(BIT8 + BIT9)	//00b/x/x/x Opcode Type4
    #define SPI0MMIO_OPT3			(BIT6 + BIT7)	//00b/x/x/x Opcode Type3
    #define SPI0MMIO_OPT2			(BIT4 + BIT5)	//00b/x/x/x Opcode Type2
    #define SPI0MMIO_OPT1			(BIT2 + BIT3)	//00b/x/x/x Opcode Type1
    #define SPI0MMIO_OPT0			(BIT0 + BIT1)	//00b/x/x/x Opcode Type0
#define SPI0MMIO_OPCODE_MENU_CFG_OPMENU		0x58	//Opcode Menu Configuration (OPMENU)
    #define SPI0MMIO_OP7			0xFF00000000000000	//0/x/x/x Opcode 7
    #define SPI0MMIO_OP6			0xFF000000000000	//0/x/x/x Opcode 6
    #define SPI0MMIO_OP5			0xFF0000000000	//0/x/x/x Opcode 5
    #define SPI0MMIO_OP4			0xFF00000000	//0/x/x/x Opcode 4
    #define SPI0MMIO_OP3			0xFF000000	//0/x/x/x Opcode 3
    #define SPI0MMIO_OP2			0xFF0000	//0/x/x/x Opcode 2
    #define SPI0MMIO_OP1			0xFF00	//0/x/x/x Opcode 1
    #define SPI0MMIO_OP0			0xFF	//0/x/x/x Opcode 0
#define SPI0MMIO_PROTECTED_BIOS_RANGE_0_PBR0		0x60	//Protected BIOS Range 0 (PBR0_B)
    #define SPI0MMIO_WPEN0			BIT31	//0/x/x/x Write Protection Enable
    #define SPI0MMIO_RPEN0			BIT30	//0/x/x/x Read Protection Enable
    #define SPI0MMIO_RESERVED_Z6			BIT29	//0/x/x/x Reserved
    #define SPI0MMIO_ARB_SPI_FLAG_ECO_R2			BIT28	//0/x/x/x Arbitration Bit 
    #define SPI0MMIO_RESERVED_Z7			BIT27	//0/x/x/x Reserved
    #define SPI0MMIO_OPTION2			BIT26	//0/x/x/x Reserved
    #define SPI0MMIO_OPTION1			BIT25	//0/x/x/x Reserved
    #define SPI0MMIO_FR_SPIREG			BIT24	//0/x/x/x SPI Fast Read Enable Bit
    #define SPI0MMIO_RESERVED_Z8			0xF00000	//0/x/x/x Reserved
    #define SPI0MMIO_PRA0			0xFFFFF	//0/x/x/x Protected Range Base
#define SPI0MMIO_PROTECTED_BIOS_RANGE_1_PBR1		0x64	//Protected BIOS Range 1 (PBR1_B)
    #define SPI0MMIO_PBR1			0xFFFFFFFF	//0/x/x/x Register Description Same as Rx63-60 (PBR0_B).
#define SPI0MMIO_PROTECTED_BIOS_RANGE_2_PBR2		0x68	//Protected BIOS Range 2 (PBR2_B)
    #define SPI0MMIO_PBR2			0xFFFFFFFF	//0/x/x/x Register Description Same as Rx63-60 (PBR0_B).
#define SPI0MMIO_SPI_BUS_0_CLK_DIVIDER		0x6C	//SPI Bus 0 Clock Divider
    #define SPI0MMIO_CLKDIV			0xFF	//0/x/*0/x SPI Bus 0 Master Mode Clock Divider Value((Random))
#define SPI0MMIO_SPI_BUS_0_MISC_CTL_1		0x6D	//SPI Bus 0 Miscellaneous Control 1
    #define SPI0MMIO_SPI_48EN			BIT7	//0/x/x/x SPI Bus0 Clock Select 0
    #define SPI0MMIO_DMASEL			BIT6	//0/x/x/x SPI Bus 0 Working Node Select
    #define SPI0MMIO_SPI_66EN			BIT5	//0/x/1/x SPI Bus0 Clock Select 1
    #define SPI0MMIO_INTEN			BIT4	//0/x/x/x SPI Bus 0 Cycle Done Interrupt Enable
    #define SPI0MMIO_DCLKON			BIT3	//0/x/1/1 SPI Bus 0 Dynamic Clock On ((Random))
    #define SPI0MMIO_DCLK_SRAM			BIT2	//0/x/x/1 SPI SRAM Dynamic Clock((Random))
    #define SPI0MMIO_GET_OWNER_INT_EN			BIT1	//0/x/x/x SW Get Ownership Done Interrupt Enable
    #define SPI0MMIO_CPWEN0			BIT0	//0/0/0/0 PIO Mode Command Post Write Enable ((Random))
#define SPI0MMIO_SPI_BUS_0_MISC_CTL_2		0x6E	//SPI Bus 0 Miscellaneous Control 2
    #define SPI0MMIO_PPBUF			BIT7	//0/x/x/x Ping-Pong Buffer Mode Register
    #define SPI0MMIO_DALEN			(BIT5 + BIT6)	//10b/x/10/x Cache Line Size
    #define SPI0MMIO_RFIFOUNDER			BIT4	//0/x/x/x Fix FIFO Underrun Flag Set Condition Incomplete Issue
    #define SPI0MMIO_LNEEN			BIT3	//1b/x/*1/X Latch Master Input Data Edge Selection of Bus CLK
    #define SPI0MMIO_BUSDLYSEL			BIT2	//0b/x/x/x Reserved
    #define SPI0MMIO_SPI_DBG_SEL			(BIT0 + BIT1)	//00b/x/x/x SPIIO_TOP ESPI_IO Debug Signal Group Select
#define SPI0MMIO_SPI_32_BIT_24_BIT_MODE_SEL		0x6F	//SPI 32-bit / 24-bit Mode Select
    #define SPI0MMIO_RESERVED_Z9			0xFE	//0/x/x/x Reserved
    #define SPI0MMIO_ROMSIZE			BIT0	//0/x/x/x Write to Trigger the Switch to 32-bit Mode
#define SPI0MMIO_SPI_BUS_0_INTR_CTL		0x70	//SPI Bus 0 Interrupt Control
    #define SPI0MMIO_DBF_EN			BIT7	//1b/x/x/x Bus 0 DMA Write Buffer Block B (High Half) Full Interrupt Enable
    #define SPI0MMIO_DAF_EN			BIT6	//1b/x/x/x Bus 0 DMA Write Buffer Block A (Low Half) Full Interrupt Enable
    #define SPI0MMIO_DBE_EN			BIT5	//1b/x/x/x Bus 0 DMA Read Buffer Block B (High Half) Empty Interrupt Enable
    #define SPI0MMIO_DAE_EN			BIT4	//1b/x/x/x Bu s0 DMA Read Buffer Block A (Low Half) Empty Interrupt Enable
    #define SPI0MMIO_DU_EN			BIT3	//1b/x/x/x Bus 0 DMA Read Buffer Under Run Interrupt Enable
    #define SPI0MMIO_DO_EN			BIT2	//1b/x/x/x Bus 0 DMA Write Buffer Over Run Interrupt Enable
    #define SPI0MMIO_FU_EN			BIT1	//1b/x/x/x Bus 0 Data FIFO Under Run Interrupt Enable
    #define SPI0MMIO_FO_EN			BIT0	//1b/x/x/x Bus 0 Data FIFO Over Run Interrupt Enable
#define SPI0MMIO_SPI_BUS_0_INTR_STA		0x73	//SPI Bus 0 Interrupt Status
    #define SPI0MMIO_DMAW_BF			BIT7	//0/0/x/x Bus 0 DMA Write Buffer Block B (High Half) Status
    #define SPI0MMIO_DMAW_AF			BIT6	//0/0/x/x Bus 0 DMA Write Buffer Block A (Low Half) Status
    #define SPI0MMIO_DMAR_BE			BIT5	//0/0/x/x Bus 0 DMA Read Buffer Block B (High Half) Status
    #define SPI0MMIO_DMAR_AE			BIT4	//0/0/x/x Bus 0 DMA Read Buffer Block A (Low Half) Status
    #define SPI0MMIO_DMAR_U			BIT3	//0/0/x/x Bus 0 DMA Read Buffer Underrun Status
    #define SPI0MMIO_DMAW_O			BIT2	//0/0/x/x Bus 0 DMA Write Buffer Overrun Status
    #define SPI0MMIO_FIFO_UDER			BIT1	//0/0/x/x Bus 0 Data FIFO Underrun Status
    #define SPI0MMIO_FIFO_OVER			BIT0	//0/0/x/x Bus 0 Data FIFO Overrun Status
#define SPI0MMIO_SPI_BUS_0_DMA_READ_BUFFER_BASE_ADR		0x74	//SPI Bus 0 DMA Read Buffer Base Address
    #define SPI0MMIO_DMAR_BA_31_2			0xFFFFFFFC	//0/x/x/x Bus 0 DMA Read Buffer Base Address[31:2] ((Random))
    #define SPI0MMIO_RESERVED_Z10			(BIT0 + BIT1)	//0/x/x/x Reserved
#define SPI0MMIO_SPI_BUS_0_DMA_WRITE_BUFFER_BASE_ADR		0x78	//SPI Bus 0 DMA Write Buffer Base Address
    #define SPI0MMIO_DMAW_BA_31_2			0xFFFFFFFC	//0/x/x/x Bus 0 DMA Write Buffer Base Address [31:2] ((Random))
    #define SPI0MMIO_RESERVED_Z11			(BIT0 + BIT1)	//0/x/x/x Reserved
#define SPI0MMIO_SPI_BUS_0_DMA_READ_BUFFER_LEN		0x7C	//SPI Bus 0 DMA Read Buffer Length
    #define SPI0MMIO_DMAR_LEN_15_2			0xFFFC	//0/x/x/x Bus 0 DMA Read Buffer Length ((Random))
    #define SPI0MMIO_RESERVED_Z12			(BIT0 + BIT1)	//0/x/x/x Reserved
#define SPI0MMIO_SPI_BUS_0_DMA_WRITE_BUFFER_LEN		0x7E	//SPI Bus 0 DMA Write Buffer Length
    #define SPI0MMIO_DMAW_LEN_15_2			0xFFFC	//0/x/x/x Bus 0 DMA Write Buffer Length ((Random))
    #define SPI0MMIO_RESERVED_Z13			(BIT0 + BIT1)	//0/x/x/x Reserved
#define SPI0MMIO_SPI_BUS_0_DMA_READ_POINTER		0x80	//SPI Bus 0 DMA Read Pointer
    #define SPI0MMIO_DMAR_PTR			0xFFFFFFFF	//0/R/x/x Bus 0 DMA Read Pointer
#define SPI0MMIO_SPI_BUS_0_DMA_WRITE_POINTER		0x84	//SPI Bus 0 DMA Write Pointer
    #define SPI0MMIO_DMAW_PTR			0xFFFFFFFF	//0/R/x/x Bus 0 DMA Write Pointer
#define SPI0MMIO_PROTECTED_BIOS_RANGE3_PBR3_B		0x88	//Protected BIOS Range3 (PBR3_B)
    #define SPI0MMIO_PBR3_B			0xFFFFFFFF	//0/x/x/x Register Description Same as Rx63-60 (PBR0_B).
#define SPI0MMIO_PROTECTED_BIOS_RANGE4_PBR4_B		0x8C	//Protected BIOS Range4 (PBR4_B)
    #define SPI0MMIO_PBR4_B			0xFFFFFFFF	//0/x/x/x Register Description Same as Rx63-60 (PBR0_B)
#define SPI0MMIO_SPI_TARGET_RPMC_TARGET_FLASH_ERASE_BLOCK_SIZE_OP1_2_TRIGGER_REG		0x90	//SPI Target RPMC/Target Flash Erase Block Size/OP1/2 Trigger Register
    #define SPI0MMIO_TARGET_RPMC			0xFC000000	//HwInit/x/x/x Target RPMC Supported
    #define SPI0MMIO_RESERVED_Z14			(BIT24 + BIT25)	//0/x/x/x Reserved
    #define SPI0MMIO_TARGET_EBS			0xFF0000	//HwInit/x/x/x Target Flash Erase Block Size for Master¡¯s Regions
    #define SPI0MMIO_RESERVED_Z15			0xFF00	//0/x/x/x Reserved
    #define SPI0MMIO_RESERVED_Z16			0xF0	//0/x/x/x Reserved
    #define SPI0MMIO_OP2CMD			BIT3	//0/x/x/x OP2 Command Trigger Bit
    #define SPI0MMIO_OP1CMD			BIT2	//0/x/x/x OP1 Command Trigger Bit
    #define SPI0MMIO_RESERVED_Z17			(BIT0 + BIT1)	//0/x/x/x Reserved
#define SPI0MMIO_PROTECTED_BIOS_RANGE0_PBR0_L		0x94	//Protected BIOS Range0 (PBR0_L)
    #define SPI0MMIO_RESERVED_Z18			0xFFF00000	//0/x/x/x Reserved
    #define SPI0MMIO_PBR0_L			0xFFFFF	//0/x/x/x Protected Range Limit
#define SPI0MMIO_PROTECTED_BIOS_RANGE1_PBR1_L		0x98	//Protected BIOS Range1 (PBR1_L)
    #define SPI0MMIO_RESERVED_Z19			0xFFF00000	//0/x/x/x Reserved
    #define SPI0MMIO_PBR1_L			0xFFFFF	//0/x/x/x Protected Range Limit
#define SPI0MMIO_PROTECTED_BIOS_RANGE2_PBR2_L		0x9C	//Protected BIOS Range2 (PBR2_L)
    #define SPI0MMIO_RESERVED_Z20			0xFFF00000	//0/x/x/x Reserved
    #define SPI0MMIO_PBR2_L			0xFFFFF	//0/x/x/x Protected Range Limit
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_0		0xA0	//eSPI Slave Attached Mode OP1 Payload Register 0
    #define SPI0MMIO_DATADW0_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW0
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_1		0xA4	//eSPI Slave Attached Mode OP1 Payload Register 1
    #define SPI0MMIO_DATADW1_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW1
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_2		0xA8	//eSPI Slave Attached Mode OP1 Payload Register 2
    #define SPI0MMIO_DATADW2_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW2
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_3		0xAC	//eSPI Slave Attached Mode OP1 Payload Register 3
    #define SPI0MMIO_DATADW3_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW3
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_4		0xB0	//eSPI Slave Attached Mode OP1 Payload Register 4
    #define SPI0MMIO_DATADW4_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW4
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_5		0xB4	//eSPI Slave Attached Mode OP1 Payload Register 5
    #define SPI0MMIO_DATADW5_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW5
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_6		0xB8	//eSPI Slave Attached Mode OP1 Payload Register 6
    #define SPI0MMIO_DATADW6_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW6
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_7		0xBC	//eSPI Slave Attached Mode OP1 Payload Register 7
    #define SPI0MMIO_DATADW7_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW7
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_8		0xC0	//eSPI Slave Attached Mode OP1 Payload Register 8
    #define SPI0MMIO_DATADW8_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW8
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_9		0xC4	//eSPI Slave Attached Mode OP1 Payload Register 9
    #define SPI0MMIO_DATADW9_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DW9
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_A		0xC8	//eSPI Slave Attached Mode OP1 Payload Register A
    #define SPI0MMIO_DATADWA_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DWA
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_B		0xCC	//eSPI Slave Attached Mode OP1 Payload Register B
    #define SPI0MMIO_DATADWB_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DWB
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_C		0xD0	//eSPI Slave Attached Mode OP1 Payload Register C
    #define SPI0MMIO_DATADWC_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DWC
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_D		0xD4	//eSPI Slave Attached Mode OP1 Payload Register D
    #define SPI0MMIO_DATADWD_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DWD
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_E		0xD8	//eSPI Slave Attached Mode OP1 Payload Register E
    #define SPI0MMIO_DATADWE_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DWE
#define SPI0MMIO_ESPI_SLAVE_ATTACHED_MODE_OP1_PAYLOAD_REG_F		0xDC	//eSPI Slave Attached Mode OP1 Payload Register F
    #define SPI0MMIO_DATADWF_OP1			0xFFFFFFFF	//0/x/x/x eSPI Slave Attached Mode OP1 Payload DWF
#define SPI0MMIO_ESPI_MASTER_SLAVE_ATTACHED_MODE_STA_REG		0xE0	//eSPI Master / Slave Attached Mode Status Register
    #define SPI0MMIO_RESERVED_Z21			0xFFFFFFC0	//0/x/x/x Reserved
    #define SPI0MMIO_SCIP_MST			BIT5	//0/x/x/x SPI-eSPI Cycle Progress in Master Attached Mode
    #define SPI0MMIO_ESPI_MST			BIT4	//0/x/x/x eSPI Master Mode Status Bit
    #define SPI0MMIO_ESPI_SLV			BIT3	//0/x/x/x eSPI Slave Mode Status Bit
    #define SPI0MMIO_SPI_ERR_SLV			BIT2	//0/x/x/x SPI ERR in Slave Mode
    #define SPI0MMIO_CDS_SLV			BIT1	//0/x/x/x SPI Bus 0 Cycle Done Status in Slave Attached Mode
    #define SPI0MMIO_SCIP_SLV			BIT0	//0/x/x/x SPI Cycle Progress in Slave Attached Mode
#define SPI0MMIO_SPI_DEBUG_SIGNAL_SEL_REG		0xE4	//SPI Debug Signal Select Register
    #define SPI0MMIO_RESERVED_2_BITFORECO			0xFE000000	//0/x/x/x Reserved
    #define SPI0MMIO_RESERVED_Z22			BIT24	//0/x/x/x Reserved
    #define SPI0MMIO_DBG_GRP_G2_SEL_REG			0xFF0000	//0/x/x/x SPI Debug Group 2 Select Signal
    #define SPI0MMIO_RESERVED_BITFORECO			0xFE00	//0/x/x/x Reserved
    #define SPI0MMIO_RESERVED_Z23			BIT8	//0/x/x/x Reserved
    #define SPI0MMIO_DBG_GRP_SEL_REG			0xFF	//0/x/x/x SPI Debug Group 1 Select Signal
#define SPI0MMIO_PROTECTED_BIOS_RANGE3_PBR3_L		0xE8	//Protected BIOS Range3 (PBR3_L)
    #define SPI0MMIO_RESERVED_Z24			0xFFF00000	//0/x/x/x Reserved
    #define SPI0MMIO_PBR3_L			0xFFFFF	//0/x/x/x Protected Range Limit
#define SPI0MMIO_PROTECTED_BIOS_RANGE4_PBR4_L		0xEC	//Protected BIOS Range4 (PBR4_L)
    #define SPI0MMIO_RESERVED_Z25			0xFFF00000	//0/x/x/x Reserved
    #define SPI0MMIO_PBR4_L			0xFFFFF	//0/x/x/x Protected Range Limit
#endif
