//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		PCIUART					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D10F0-F1_PCIUART_R104(A0).doc(final)MOD_VARTCFG.xls
#ifndef _CHX002_D10F0F1_PCIUART_H
#define _CHX002_D10F0F1_PCIUART_H
//D10F0-F1
#define D10F0F1_VID		0x00	//Vendor ID
    #define D10F0F1_UARTVID			0xFFFF	//1106h/x/x/x Vendor ID
#define D10F0F1_DID		0x02	//Device ID
    #define D10F0F1_UARTDEVID			0xFFFF	//F410h/x/x/x Device ID
#define D10F0F1_PCI_CMD		0x04	//PCI Command
    #define D10F0F1_INTR_DIS			BIT10	//0/0/x/x Interrupt Disable
    #define D10F0F1_FB2BKENR			BIT9	//0/R/x/x Fast Back to Back 
    #define D10F0F1_SERREN			BIT8	//0/R/x/x SERR# Enable 
    #define D10F0F1_ADSTEP			BIT7	//0/R/x/x Address Stepping 
    #define D10F0F1_RPTYERR			BIT6	//0/R/x/x Parity Error Response
    #define D10F0F1_VGASNP			BIT5	//0/R/x/x VGA Palette Snooping
    #define D10F0F1_MMWI			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D10F0F1_SPCYL			BIT3	//0/R/x/x Respond to Special Cycle
    #define D10F0F1_BMASTREN			BIT2	//0/0/x/x Bus Master
    #define D10F0F1_MMSPACE			BIT1	//0/0/x/x Memory Space Access
    #define D10F0F1_IOSPACE			BIT0	//0/0/x/x I/O Space Access
#define D10F0F1_PCI_STA		0x06	//PCI Status
    #define D10F0F1_PARERR			BIT15	//0/R/x/x Detect Parity Error
    #define D10F0F1_TSERRS			BIT14	//0/x/x/x Signaled System Error (SERR#)
    #define D10F0F1_TMABORTS			BIT13	//0/x/x/x Received Master Abort
    #define D10F0F1_TTABORTR			BIT12	//0/x/x/x Received Target Abort
    #define D10F0F1_STABORT			BIT11	//0/R/x/x Signaled Target Abort
    #define D10F0F1_DEVS			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D10F0F1_DPARD			BIT8	//0/R/x/x Data Parity Detected
    #define D10F0F1_FB2BCAP			BIT7	//0/R/x/x Fast Back-to-Back Capability
    #define D10F0F1_CAPLST			BIT4	//1b/R/x/x Capability List
    #define D10F0F1_UARTIRQACT			BIT3	//0/R/x/x Interrupt Status
#define D10F0F1_REV_ID		0x08	//Revision ID
    #define D10F0F1_UARTREVID			0xFF	//04h/x/x/x Revision ID
#define D10F0F1_CLASS_CODE		0x09	//Class Code
    #define D10F0F1_UARTCLS_COD			0xFFFFFF	//070002h/R/x/x Class Code
#define D10F0F1_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D10F0F1_CACHLINE			0xFF	//0/0/08h/08h Cache Line Size
#define D10F0F1_LATENCY_TIMER		0x0D	//Latency Timer
    #define D10F0F1_LAT_TM			0xFF	//16h/16h/20h/20h Latency Timer
#define D10F0F1_HEADER_TYPE		0x0E	//Header Type
    #define D10F0F1_HDTYPE			0xFF	//80h/R/x/x Header Type 
#define D10F0F1_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
    #define D10F0F1_BIST			0xFF	//00h/R/x/x BIST
#define D10F0F1_PCI_UART_MMIO_REG_BASE_ADR		0x10	//PCI UART MMIO Register Base Address
    #define D10F0F1_MMBA			0xFFFFFF00	//0/x/x/x PCI UART MMIO Register Base Address [31:8]
#define D10F0F1_PCI_UART_IO_REG_BASE_ADR		0x14	//PCI UART IO Register Base Address
    #define D10F0F1_IOBA			0xFFFFFFF8	//0/x/x/x PCI UART IO Register Base Address [31:3]
    #define D10F0F1_IOBA_FLAG			BIT0	//1b/x/x/x Reserved
#define D10F0F1_SVID		0x2C	//Subsystem Vendor ID
    #define D10F0F1_SUBVID			0xFFFF	//1D17h/1106h/x/x Subsystem Vendor
#define D10F0F1_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D10F0F1_SUBSID			0xFFFF	//F410h/F410h/x/x Subsystem ID
#define D10F0F1_CAP_POINTER		0x34	//Capability Pointer
    #define D10F0F1_CLP			0xFF	//80h/R/x/x Capability List Pointer
#define D10F0F1_INTR_LINE		0x3C	//Interrupt Line
    #define D10F0F1_INTLN			0xF	//0000b/x/x/x Interrupt Line Selection ((Random))
#define D10F0F1_INTR_PIN_D10F0		0x3D	//Interrupt Pin (D10F0)
    #define D10F0F1_U0_INTLINE			0xFF	//01h/R/x/x Interrupt Pin
#define D10F0F1_UARTCFG_BAKUP_REG		0x70	//UARTCFG Bakup Register
    #define D10F0F1_RX73_7_1			0xFE000000	//0/x/x/x Reserved
    #define D10F0F1_FUNC_SWAP			BIT24	//0/x/x/x Reserved
    #define D10F0F1_RX72_7_1			0xFE0000	//0/x/x/x Reserved
    #define D10F0F1_INTTYPE			BIT16	//0/0/0/0 Interrupt Type Select ((Random))
    #define D10F0F1_UART_DYNAMIC_EN			BIT15	//0/x/0/0 PCI-UART Dynamic Clock Enable
    #define D10F0F1_UART_CLOCK_DIS			BIT14	//0/x/0/0 PCI-UART All Clock Disable
    #define D10F0F1_BMS_FUN_DIS			BIT13	//0/x/x/x Reserved
    #define D10F0F1_C2PR_FLUSH_P2CW_BACKDOOR			BIT12	//0/x/x/x c2pr_flush_p2cw_backdoor
    #define D10F0F1_RX71_3_2			(BIT10 + BIT11)	//0/x/x/x Reserved
    #define D10F0F1_DBGSEL1			BIT9	//0/x/x/x Reserved
    #define D10F0F1_DBGSEL0			BIT8	//0/x/x/x Reserved
    #define D10F0F1_PCI_DYNAMIC_EN			BIT7	//0/x/0/0 PCI_dynamic_EN
    #define D10F0F1_RXDMA_REQ_ERR_BACKDOOR			BIT6	//0/x/x/x RXDMA Request Error Backdoor
    #define D10F0F1_C2PR_RM_CDC_BACKDOOR			BIT5	//0/x/0/x C2PR Performance Backdoor
    #define D10F0F1_FLR_EN_BACKDOOR			BIT4	//0/x/x/x FLR Enable Backdoor
    #define D10F0F1_A1_ECO_BACKDOOR			BIT3	//0/x/x/x Reserved
    #define D10F0F1_UART_CLR_EMPTY_BACKDOOR			BIT2	//0/x/x/x Reserved
    #define D10F0F1_INTG_PCOM			BIT1	//0/x/x/x Reserved
    #define D10F0F1_PCOM_EN			BIT0	//0/x/x/x PCI Compatible Mode Enable ((Random))
#define D10F0F1_PM_CAP_ID		0x80	//Power Management Capability ID
    #define D10F0F1_PM_CID			0xFF	//01h/R/x/x Power Management Capability ID
#define D10F0F1_NEXT_ITEM_POINTER		0x81	//Next Item Pointer
    #define D10F0F1_NIP			0xFF	//88h/R/x/x Next Item Pointer: Null
#define D10F0F1_PM_CAP		0x82	//Power Management Capability
    #define D10F0F1_PME_SPT			0xF800	//1Fh/x/x/x PME# Support
    #define D10F0F1_D2_SPT			BIT10	//1b/x/x/x D2 Support
    #define D10F0F1_D1_SPT			BIT9	//1b/x/x/x D1 Support
    #define D10F0F1_AUX_CUR			(BIT6 + BIT7 + BIT8)	//111b/x/x/x Aux Current (Maximum Current Required)
    #define D10F0F1_DSI			BIT5	//0/x/x/x Device Specific Initialization <DSI>
    #define D10F0F1_PME_CLK			BIT3	//0/x/x/x PME# Clock
    #define D10F0F1_PME_VER			(BIT0 + BIT1 + BIT2)	//010b/x/x/x Version
#define D10F0F1_PM_CAP_CTL_STA		0x84	//Power Management Capability Control / Status
    #define D10F0F1_PME_STS			BIT15	//0/x/x/x PME# Status
    #define D10F0F1_DATA_SCALE			(BIT13 + BIT14)	//0/x/x/x Reserved
    #define D10F0F1_DATA_SEL			0x1E00	//0/x/x/x Reserved
    #define D10F0F1_PME_EN			BIT8	//0/x/x/x PME# Assertion
    #define D10F0F1_PWR_STATE			(BIT0 + BIT1)	//00b/x/x/x Device Status Control
#define D10F0F1_PCI_UART_FLR_CTL_AND_STA		0x88	//PCI UART FLR Control and Status
    #define D10F0F1_AF_STR_LEN			0xFF000000	//03h/R/x/x AF Structure Length
    #define D10F0F1_FLR_AF_STR_LEN			0xFF0000	//06h/R/x/x FLR AF Structure Length
    #define D10F0F1_FLR_CAP_ID			0xFF	//13h/x/x/X FLR Capability CAP ID
#define D10F0F1_PCI_UART_FLR_CTL_AND_STA_Z1		0x8C	//PCI UART FLR Control and Status
    #define D10F0F1_VD_EN_LOCK			BIT19	//0/x/x/x Reserved
    #define D10F0F1_PIO_BACKDOOR			BIT18	//0/x/x/x PIO Mode Backdoor Register
    #define D10F0F1_VD_ID_SEL			BIT17	//0/x/x/x Reserved
    #define D10F0F1_FLR_EN			BIT16	//1b/x/x/x FLR Enable Bit
    #define D10F0F1_TP			BIT8	//0/x/x/x Transaction Pending Status Bit
    #define D10F0F1_INITIATE			BIT0	//0/x/x/x Fuction Level Reset
#define D10F0F1_BACK_DOOR_CTL_REG		0xF0	//Back Door Control Register
    #define D10F0F1_SSIDEN			BIT1	//0/x/x/x Subsystem ID Register RW Control Backdoor
    #define D10F0F1_SVIDEN			BIT0	//0/x/x/x Subsystem VendorID Register RW Control Backdoor
//D10F0
#define D10F0_UART0_SRC_ID_REG		0xF4	//UART0 Source ID Register
    #define D10F0_UART0_SID			0xFFFF	//0050h/x/x/x UART0 Source ID
//D10F1
    #define D10F1_UART1_SID			0xFFFF	//0051h/x/x/x UART1 Source ID
//PCI UART-MMIO
#define PCI_UARTMMIO_RECEIVER_BUFFER_RBUF_FOR_READ_WHEN_DLAB_RX03_7_0		0x00	//Receiver Buffer (RBUF) - For Read When DLAB (Rx03[7]) = 0
    #define PCI_UARTMMIO_RBUF			0xFF	//0/x/x/x Receiver Buffer
#define PCI_UARTMMIO_INTR_ENABLE_REG_IER_WHEN_DLAB_0		0x01	//Interrupt Enable Register (IER) - When DLAB = 0
    #define PCI_UARTMMIO_MSI_EN			BIT3	//0/x/x/x Modem Status Interrupt Enable
    #define PCI_UARTMMIO_RLSI_EN			BIT2	//0/x/x/x Receiver Line Status Interrupt Enable
    #define PCI_UARTMMIO_THRE_EN			BIT1	//0/x/x/x Transmitter Holding Register Empty Interrupt Enable
    #define PCI_UARTMMIO_RDAI_EN			BIT0	//0/x/x/x Received Data Available Interrupt Enable
#define PCI_UARTMMIO_INTR_IDENTIFICATION_REG_IIR		0x02	//Interrupt Identification Register (IIR)
    #define PCI_UARTMMIO_FIFO_USE			(BIT6 + BIT7)	//0/R/x/x FIFO Buffer Status
    #define PCI_UARTMMIO_TOINT			BIT3	//0/R/x/x Time-out Interrupt Pending
    #define PCI_UARTMMIO_INT_STS			(BIT1 + BIT2)	//0/x/x/x Interrupt Occurred Status
    #define PCI_UARTMMIO_INTPEND			BIT0	//1b/R/x/x Interrupt Pending Status
#define PCI_UARTMMIO_LINE_CTL_REG_LCR		0x03	//Line Control Register (LCR)
    #define PCI_UARTMMIO_DLAB			BIT7	//0/x/x/x Divisor Latch Access Bit <DLAB> or Transceiver Buffer Control 
    #define PCI_UARTMMIO_BREAKEN			BIT6	//0/x/x/x Set Break Enable
    #define PCI_UARTMMIO_PARITY			(BIT3 + BIT4 + BIT5)	//0/x/x/x Parity Selection ((Random))
    #define PCI_UARTMMIO_STOPLEN			BIT2	//0/x/x/x Stop Bit Length ((Random))
    #define PCI_UARTMMIO_WORDLEN			(BIT0 + BIT1)	//0/x/x/x Word Length ((Random))
#define PCI_UARTMMIO_MODEM_CTL_REG_MCR		0x04	//Modem Control Register (MCR)
    #define PCI_UARTMMIO_LOOPBACK			BIT4	//0/x/x/x Loopback Mode
    #define PCI_UARTMMIO_AUX2			BIT3	//0/x/x/x Aux Output 2
    #define PCI_UARTMMIO_AUX1			BIT2	//0/x/x/x Aux Output 1
    #define PCI_UARTMMIO_FORCE_RTS			BIT1	//0/x/x/x Force Request to Send
    #define PCI_UARTMMIO_FORCE_DTR			BIT0	//0/x/x/x Force Data Terminal Ready
#define PCI_UARTMMIO_LINE_STA_REG_LSR		0x05	//Line Status Register (LSR)
    #define PCI_UARTMMIO_RFIFO_ERR			BIT7	//0/R/x/x Error in Receiver FIFO
    #define PCI_UARTMMIO_EDHR			BIT6	//1b/R/x/x Empty Data Holding Registers
    #define PCI_UARTMMIO_ETHR			BIT5	//1b/R/x/x Empty Transmitter Holding Register
    #define PCI_UARTMMIO_BREAK			BIT4	//0/R/x/x Break Interrupt
    #define PCI_UARTMMIO_FRAME_ERR			BIT3	//0/R/x/x Framing Error
    #define PCI_UARTMMIO_PAR_ERR			BIT2	//0/R/x/x Parity Error
    #define PCI_UARTMMIO_OVERRUN			BIT1	//0/R/x/x Overrun Error
    #define PCI_UARTMMIO_DR			BIT0	//0/R/x/x Data Ready
#define PCI_UARTMMIO_MODEM_STA_REG_MSR		0x06	//Modem Status Register (MSR)
    #define PCI_UARTMMIO_CD			BIT7	//0/R/x/x Carrier Detect
    #define PCI_UARTMMIO_RI			BIT6	//0/R/x/x Ring Indicator
    #define PCI_UARTMMIO_DSR			BIT5	//0/R/x/x Data Set Ready
    #define PCI_UARTMMIO_CTS			BIT4	//0/R/x/x Clear To Send
    #define PCI_UARTMMIO_DEL_DCD			BIT3	//0/R/x/x Delta Data Carrier Detect
    #define PCI_UARTMMIO_TERI			BIT2	//0/R/x/x Trailing Edge Ring Indicator
    #define PCI_UARTMMIO_DEL_DSR			BIT1	//0/R/x/x Delta Data Set Ready
    #define PCI_UARTMMIO_DEL_CTS			BIT0	//0/R/x/x Delta Clear to Send
#define PCI_UARTMMIO_SCRATCH_REG		0x07	//Scratch Register
    #define PCI_UARTMMIO_SCRATCHR			0xFF	//0/x/x/x Scratch Register
#define PCI_UARTMMIO_PCI_UART_FIFO_WRITE_ACCESS		0x10	//PCI UART FIFO Write Access
    #define PCI_UARTMMIO_PIOFIFOW			0xFFFFFFFF	//0/x/x/x PCI UART FIFO Write Access
#define PCI_UARTMMIO_PCI_UART_FIFO_READ_ACCESS		0x14	//PCI UART FIFO Read Access
    #define PCI_UARTMMIO_PIOFIFOR			0xFFFFFFFF	//0/x/x/x PCI UART FIFO Read Access
#define PCI_UARTMMIO_PCI_UART_RECEIVED_DATA_LEN		0x18	//PCI UART Received Data Length
    #define PCI_UARTMMIO_RFIFOLENG			0xF0000	//0/R/x/x PCI UART Receiver FIFO Length
    #define PCI_UARTMMIO_PIORFIFOLEN			0xFFFF	//0/x/x/x PCI UART Received Data Length
#define PCI_UARTMMIO_PCI_UART_DMA_A_ADR_FOR_TRANSMISSION		0x20	//PCI UART DMA-A Address for Transmission
    #define PCI_UARTMMIO_TXDMA_BAA			0xFFFFFFFF	//0/x/x/x PCI UART DMA-A Start Address for Transmission ((Random))
#define PCI_UARTMMIO_PCI_UART_DMA_A_DATA_LEN_FOR_TRANSMISSION		0x24	//PCI UART DMA-A Data Length for Transmission
    #define PCI_UARTMMIO_TXDMA_DLA			0xFFFF	//0/x/x/x PCI UART DMA-A Data Length for TX ((Random))
#define PCI_UARTMMIO_PCI_UART_DMA_B_ADR_FOR_TRANSMISSION		0x28	//PCI UART DMA-B Address for Transmission
    #define PCI_UARTMMIO_TXDMA_BAB			0xFFFFFFFF	//0/x/x/x PCI UART DMA-B Start Address for Transmission ((Random))
#define PCI_UARTMMIO_PCI_UART_DMA_B_DATA_LEN_FOR_TRANSMISSION		0x2C	//PCI UART DMA-B Data Length for Transmission
    #define PCI_UARTMMIO_TXDMA_DLB			0xFFFF	//0/x/x/x PCI UART DMA-B Data Length for Transmitter((Random))
#define PCI_UARTMMIO_PCI_UART_TRANSMITTER_CTL_REG		0x30	//PCI UART Transmitter Control Register
    #define PCI_UARTMMIO_TXDMA_OSIVAL			0xFFFF0000	//0/x/x/x Transmitter DMA One-shot Timer Value ((Random))
    #define PCI_UARTMMIO_TXDMA_OSIEN			BIT8	//0/x/x/x Transmitter DMA One-shot Timer Enable ((Random))
    #define PCI_UARTMMIO_TX_FLOWCREN			BIT1	//0/x/x/x Transmitter Flow Control Enable ((Random))
    #define PCI_UARTMMIO_TXDMAEN			BIT0	//0/x/x/x Transmitter DMA Enable
#define PCI_UARTMMIO_PCI_UART_DMA_A_ADR_FOR_RECEIVING		0x40	//PCI UART DMA-A Address for Receiving
    #define PCI_UARTMMIO_RXDMA_BAA			0xFFFFFFFF	//0/x/x/x PCI UART DMA-A Start Address for Receiving ((Random))
#define PCI_UARTMMIO_PCI_UART_DMA_A_DATA_LEN_FOR_RECEIVING		0x44	//PCI UART DMA-A Data Length for Receiving
    #define PCI_UARTMMIO_RXDMA_DLA			0xFFFF	//0/x/x/x PCI UART DMA-A Data Length for Receiving ((Random))
#define PCI_UARTMMIO_PCI_UART_DMA_B_ADR_FOR_RECEIVING		0x48	//PCI UART DMA-B Address for Receiving
    #define PCI_UARTMMIO_RXDMA_BAB			0xFFFFFFFF	//0/x/x/x PCI UART DMA-B Start Address for Receiving ((Random))
#define PCI_UARTMMIO_PCI_UART_DMA_B_DATA_LEN_FOR_RECEIVING		0x4C	//PCI UART DMA-B Data Length for Receiving
    #define PCI_UARTMMIO_RXDMA_DLB			0xFFFF	//0/x/x/x PCI UART DMA-B Data Length for Receiving ((Random))
#define PCI_UARTMMIO_PCI_UART_RECEIVER_DMA_CTL_LOW		0x50	//PCI UART Receiver DMA Control Low
    #define PCI_UARTMMIO_RXDMAOSIVAL			0xFFFF0000	//0/x/x/x Receiver DMA One-shot Timer Value ((Random))
    #define PCI_UARTMMIO_RXOSI_EN			BIT8	//0/x/x/x Receiver DMA One-shot Timer Enable ((Random))
    #define PCI_UARTMMIO_RXFCTRL			BIT1	//0/x/x/x Receiver Flow Control Enable ((Random))
    #define PCI_UARTMMIO_RXDMA_EN			BIT0	//0/x/x/x Receiver DMA Enable
#define PCI_UARTMMIO_PCI_UART_RECEIVER_DMA_CTL_HIGH		0x54	//PCI UART Receiver DMA Control High
    #define PCI_UARTMMIO_TO_VAL			0xFFF00000	//FFFh/x/x/x DMA Timeout Value ((Random))
    #define PCI_UARTMMIO_TO_EN			BIT19	//0/0/1*/1* DMA Timeout Event Enable
    #define PCI_UARTMMIO_UREQ_LVL			0x1E00	//0/x/x/x Urgent DMA Request Level ((Random))
    #define PCI_UARTMMIO_UREQ_CR			BIT8	//0/x/x/x Urgent DMA Request Level Control
    #define PCI_UARTMMIO_NREQ_LVL			0x1E	//0/x/x/x Normal DMA Request Level ((Random))
    #define PCI_UARTMMIO_NREQ_CR			BIT0	//0/x/x/x Normal DMA Request Level Control
#define PCI_UARTMMIO_PCI_UART_HIGH_BAUD_RATE_CTL_LOW		0x58	//PCI UART High Baud Rate Control Low
    #define PCI_UARTMMIO_HPCR			0xF	//0/x/x/x PCI UART Baud Rate Multiplier ((Random))
#define PCI_UARTMMIO_PCI_UART_HIGH_BAUD_RATE_CTL_HIGH		0x5C	//PCI UART High Baud Rate Control High
#define PCI_UARTMMIO_PCI_UART_TXDMA_CURRENT_ADR		0x60	//PCI UART TXDMA Current Address
    #define PCI_UARTMMIO_DMACURAD			0xFFFFFFFF	//0/R/x/x PCI UART TXDMA Current Address
#define PCI_UARTMMIO_PCI_UART_TXDMA_CURRENT_LEN		0x64	//PCI UART TXDMA Current Length
    #define PCI_UARTMMIO_TDMAACURLEN			0xFFFF0000	//0/R/x/x PCI UART TXDMA A Current Length
    #define PCI_UARTMMIO_TDMABCURLEN			0xFFFF	//0/R/x/x PCI UART TXDMA B Current Length
#define PCI_UARTMMIO_PCI_UART_RXDMA_CURRENT_ADR		0x68	//PCI UART RXDMA Current Address
    #define PCI_UARTMMIO_RDMACURAD			0xFFFFFFFF	//0/R/x/x PCI UART RXDMA Current Address 
#define PCI_UARTMMIO_PCI_UART_RXDMA_CURRENT_LEN		0x6C	//PCI UART RXDMA Current Length
    #define PCI_UARTMMIO_RDMABCURLEN			0xFFFF0000	//0/R/x/x PCI UART RXDMA_B Current Length
    #define PCI_UARTMMIO_RDMAACURLEN			0xFFFF	//0/R/x/x PCI UART RXDMA_A Current Length
#define PCI_UARTMMIO_PCI_UART_DMA_STA		0x70	//PCI UART DMA Status
    #define PCI_UARTMMIO_RXDMA_STA			(BIT2 + BIT3)	//0/R/x/x RXDMA State
    #define PCI_UARTMMIO_TXDMA_STA			(BIT0 + BIT1)	//0/R/x/x TXDMA State
#define PCI_UARTMMIO_PCI_UART_NORMAL_INTR_ENABLE_DMA_MODE		0x78	//PCI UART Normal Interrupt Enable DMA Mode
    #define PCI_UARTMMIO_ROSINT			BIT7	//0/x/x/x Receiver One-shot Interrupt Enable
    #define PCI_UARTMMIO_TOSINT			BIT6	//0/x/x/x Transmitter One-shot Interrupt Enable
    #define PCI_UARTMMIO_PARINT			BIT5	//0/x/x/x Parity Check Error Interrupt Enable
    #define PCI_UARTMMIO_OVERINT			BIT4	//0/x/x/x FIFO Overrun Interrupt Enable
    #define PCI_UARTMMIO_RCOMINT			BIT3	//0/x/x/x Data Receiving Complete Interrupt Enable
    #define PCI_UARTMMIO_RXINT			BIT2	//0/x/x/x DMA Receiving Interrupt Enable
    #define PCI_UARTMMIO_TCOMINT			BIT1	//0/x/x/x Data Transmission Complete Interrupt Enable
    #define PCI_UARTMMIO_TXINT			BIT0	//0/x/x/x DMA Transmission Interrupt Enable
#define PCI_UARTMMIO_PCI_UART_NORMAL_INTR_STA_UNDER_DMA		0x7C	//PCI UART Normal Interrupt Status Under DMA
    #define PCI_UARTMMIO_OVERSTS			BIT9	//0/x/x/x FIFO Overrun Interrupt
    #define PCI_UARTMMIO_PARSTS			BIT8	//0/x/x/x Parity Check Error
    #define PCI_UARTMMIO_ROSINT_STS			BIT7	//0/x/x/x Receiver One-shot Interrupt
    #define PCI_UARTMMIO_RCOMINT_STS			BIT6	//0/x/x/x Data Receiving Complete Interrupt
    #define PCI_UARTMMIO_RXINTB_STS			BIT5	//0/x/x/x DMA-B Receiving Interrupt
    #define PCI_UARTMMIO_RXINTA_STS			BIT4	//0/x/x/x DMA-A Receiving Interrupt
    #define PCI_UARTMMIO_TOSINT_STS			BIT3	//0/x/x/x Transmitter One-shot Interrupt
    #define PCI_UARTMMIO_TCOMINT_STS			BIT2	//0/x/x/x Data Transmission Complete Interrupt
    #define PCI_UARTMMIO_TXINTB_STS			BIT1	//0/x/x/x DMA-B Transmission Interrupt
    #define PCI_UARTMMIO_TXINTA_STS			BIT0	//0/x/x/x DMA-A Transmission Interrupt
#endif
