// This file is auto converted by ZX Irs2h from IRS_CHX001_D10F0-F3_PCIUART_R100(A0).doc.
#ifndef IRS_CHX001_D10F0_F3_PCIUART_R100_A0__H
#define IRS_CHX001_D10F0_F3_PCIUART_R100_A0__H
// D10F0-F3
#define D10F0F3_VID 0x0 // Vendor ID
    #define D10F0F3_UARTVID D10F0F3_VID // 1106h/R/x/x Vendor ID
#define D10F0F3_DID 0x2 // Device ID
    #define D10F0F3_UARTDEVID D10F0F3_DID // F410h/R/x/x Device ID
#define D10F0F3_PCI_CMD 0x4 // PCI Command
    #define D10F0F3_INTR_DIS    BIT10   // 0/0/x/x Interrupt Disable
    #define D10F0F3_FB2BKENR    BIT9    // 0/R/x/x Fast Back to Back 
    #define D10F0F3_SERREN      BIT8    // 0/R/x/x SERR# Enable 
    #define D10F0F3_ADSTEP      BIT7    // 0/R/x/x Address Stepping 
    #define D10F0F3_RPTYERR     BIT6    // 0/R/x/x Parity Error Response
    #define D10F0F3_VGASNP      BIT5    // 0/R/x/x VGA Palette Snooping
    #define D10F0F3_MMWI        BIT4    // 0/R/x/x Memory Write and Invalidate
    #define D10F0F3_SPCYL       BIT3    // 0/R/x/x Respond to Special Cycle
    #define D10F0F3_BMASTREN    BIT2    // 0/0/x/x Bus Master
    #define D10F0F3_MMSPACE     BIT1    // 0/0/x/x Memory Space Access
    #define D10F0F3_IOSPACE     BIT0    // 0/0/x/x I/O Space Access
#define D10F0F3_PCI_STA 0x6 // PCI Status
    #define D10F0F3_PARERR      BIT15                   // 0/R/x/x Detect Parity Error
    #define D10F0F3_TSERRS      BIT14                   // 0/x/x/x Signaled System Error (SERR#)
    #define D10F0F3_TMABORTS    BIT13                   // 0/x/x/x Received Master Abort
    #define D10F0F3_TTABORTR    BIT12                   // 0/x/x/x Received Target Abort
    #define D10F0F3_STABORT     BIT11                   // 0/R/x/x Signaled Target Abort
    #define D10F0F3_DEVS        (BIT9 + BIT10)          // 01b/R/x/x DEVSEL# Timing
    #define D10F0F3_DPARD       BIT8                    // 0/R/x/x Data Parity Detected
    #define D10F0F3_FB2BCAP     BIT7                    // 0/R/x/x Fast Back-to-Back Capability
    #define D10F0F3_CAPLST      BIT4                    // 1b/R/x/x Capability List
    #define D10F0F3_UARTIRQACT  BIT3                    // 0/R/x/x Interrupt Status
#define D10F0F3_REV_ID 0x8 // Revision ID
    #define D10F0F3_UARTREVID D10F0F3_REV_ID // 04h/R/x/x Revision ID
#define D10F0F3_CLASS_CODE 0x9 // Class Code
    #define D10F0F3_UARTCLS_COD D10F0F3_CLASS_CODE // 07 0002h/R/x/x Class Code
#define D10F0F3_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define D10F0F3_CACHLINE D10F0F3_CACHE_LINE_SIZE // 0/0/08h/08h Cache Line Size
#define D10F0F3_LATENCY_TIMER 0xD // Latency Timer
    #define D10F0F3_LAT_TM D10F0F3_LATENCY_TIMER // 16h/16h/20h/20h Latency Timer
#define D10F0F3_HDR_TYPE 0xE // Header Type
    #define D10F0F3_HDTYPE D10F0F3_HDR_TYPE // 80h/R/x/x Header Type 
#define D10F0F3_BIST 0xF // Built In Self Test (BIST)
    #define D10F0F3_BIST_Z1 D10F0F3_BIST // 00h/R/x/x BIST
#define D10F0F3_PCI_UART_MMIO_REG_BASE_ADR 0x10 // PCI UART MMIO Register Base Address
    #define D10F0F3_MMBA    0xFFFFFF00  // 0/x/x/x PCI UART MMIO Register Base Address [31:8]
#define D10F0F3_PCI_UART_IO_REG_BASE_ADR 0x14 // PCI UART IO Register Base Address
    #define D10F0F3_IOBA        0xFFFFFFF8      // 0/x/x/x PCI UART IO Register Base Address [31:3]
    #define D10F0F3_IOBA_FLAG   BIT0            // 1b/x/x/x Reserved
#define D10F0F3_SVID 0x2C // Subsystem Vendor ID
    #define D10F0F3_SUBVID D10F0F3_SVID // 1106h/1106h/x/x Subsystem Vendor
#define D10F0F3_SSID 0x2E // Subsystem ID
    #define D10F0F3_SUBSID D10F0F3_SSID // F410h/F410h/x/x Subsystem ID
#define D10F0F3_CAP_PTR 0x34 // Capability Pointer
    #define D10F0F3_CLP D10F0F3_CAP_PTR // 80h/R/x/x Capability List Pointer
#define D10F0F3_INTR_LINE 0x3C // Interrupt Line
    #define D10F0F3_INTLN   0xF     // 0000b/x/x/x Interrupt Line Selection ((Random))
#define D10F0F3_INTR_PIN_D10F0 0x3D // Interrupt Pin (D10F0)
    #define D10F0F3_U0_INTLINE D10F0F3_INTR_PIN_D10F0 // 01h/R/x/x Interrupt Pin 
#define D10F0F3_UARTCFG_BAKUP_REG 0x70 // UARTCFG Bakup Register
    #define D10F0F3_U3_INTLINE              0xFE000000  // 0/x/x/x Reserved
    #define D10F0F3_FUNC_SWAP               BIT24       // 0/x/x/x Function Swap Enable ((Random))
    #define D10F0F3_INTTYPE                 BIT16       // 0/0/0/0 Interrupt Type Select ((Random))
    #define D10F0F3_UART_DYNAMIC_EN         BIT15       // 0/x/x/x PCI-UART Dynamic Clock Enable 
    #define D10F0F3_DBGSEL1                 BIT9        // 0/x/x/x Reserved
    #define D10F0F3_DBGSEL0                 BIT8        // 0/x/x/x Reserved
    #define D10F0F3_UART_CLR_EMPTY_BACKDOOR BIT2        // 0/x/x/x Reserved
    #define D10F0F3_INTG_PCOM               BIT1        // 0/x/x/x Reserved
    #define D10F0F3_PCOM_EN                 BIT0        // 0/x/x/x PCI Compatible Mode Enable ((Random))
#define D10F0F3_PM_CAP_ID 0x80 // Power Management Capability ID
    #define D10F0F3_PM_CID D10F0F3_PM_CAP_ID // 01h/R/x/x Power Management Capability ID
#define D10F0F3_NEXT_ITEM_PTR 0x81 // Next Item Pointer
    #define D10F0F3_NIP D10F0F3_NEXT_ITEM_PTR // 88h/R/x/x Next Item Pointer: Null
#define D10F0F3_PM_CAP 0x82 // Power Management Capability
    #define D10F0F3_PME_SPT 0xF800                  // 1Fh/x/x/x PME# Support
    #define D10F0F3_D2_SPT  BIT10                   // 1b/x/x/x D2 Support
    #define D10F0F3_D1_SPT  BIT9                    // 1b/x/x/x D1 Support
    #define D10F0F3_AUX_CUR (BIT6 + BIT7 + BIT8)    // 111b/x/x/x Aux Current (Maximum Current Required)
    #define D10F0F3_DSI     BIT5                    // 0/x/x/x Device Specific Initialization <DSI>
    #define D10F0F3_PME_CLK BIT3                    // 0/x/x/x PME# Clock
    #define D10F0F3_PME_VER (BIT0 + BIT1 + BIT2)    // 010b/x/x/x Version
#define D10F0F3_PM_CAP_CTL_STA 0x84 // Power Management Capability Control / Status
    #define D10F0F3_PME_STS     BIT15           // 0/x/x/x PME# Status
    #define D10F0F3_DATA_SCALE  (BIT13 + BIT14) // 0/x/x/x Reserved
    #define D10F0F3_DATA_SEL    0x1E00          // 0/x/x/x Reserved
    #define D10F0F3_PME_EN      BIT8            // 0/x/x/x PME# Assertion
    #define D10F0F3_PWR_STATE   (BIT0 + BIT1)   // 00b/x/x/x Device Status Control
#define D10F0F3_PCI_UART_FLR_CTL_AND_STA 0x88 // PCI UART FLR Control and Status
    #define D10F0F3_AF_STR_LEN      0xFF000000  // 03h/R/x/x AF Structure Length
    #define D10F0F3_FLR_AF_STR_LEN  0xFF0000    // 06h/R/x/x FLR AF Structure Length
    #define D10F0F3_FLR_CAP_ID      0xFF        // 13h/x/x/X FLR Capability CAP ID
#define D10F0F3_PCI_UART_FLR_CTL_AND_STA_Z1 0x8C // PCI UART FLR Control and Status
    #define D10F0F3_VD_EN_LOCK      BIT19       // 0/x/x/x Reserved
    #define D10F0F3_PIO_BACKDOOR    BIT18       // 0/x/x/x PIO Mode Backdoor Register
    #define D10F0F3_VD_ID_SEL       BIT17       // 0/x/x/x Reserved
    #define D10F0F3_FLR_EN          BIT16       // 1b/x/x/x FLR Enable Bit
    #define D10F0F3_TP              BIT8        // 0/x/x/x Transaction Pending Status Bit
    #define D10F0F3_INITIATE        BIT0        // 0/x/x/x Fuction Level Reset
#define D10F0F3_BACK_DOOR_CTL_REG 0xF0 // Back Door Control Register
    #define D10F0F3_SSIDEN  BIT1        // 0/x/x/x Subsystem ID Register RW Control Backdoor
    #define D10F0F3_SVIDEN  BIT0        // 0/x/x/x Subsystem VendorID Register RW Control Backdoor
// D10F0-F0
#define D10F0F0_UART0_SRC_ID_REG 0xF4 // UART0 Source ID Register
    #define D10F0F0_UART0_SID D10F0F0_UART0_SRC_ID_REG // 0050h/x/x/x UART0 Source ID
// D10F0-F1
#define D10F0F1_UART1_SRC_ID_REG 0xF4 // UART1 Source ID Register
    #define D10F0F1_UART1_SID D10F0F1_UART1_SRC_ID_REG // 0051h/x/x/x UART1 Source ID
// D10F0-F2
#define D10F0F2_UART2_SRC_ID_REG 0xF4 // UART2 Source ID Register
    #define D10F0F2_UART2_SID D10F0F2_UART2_SRC_ID_REG // 0052h/x/x/x UART2 Source ID
// D10F0-F3
#define D10F0F3_UART3_SRC_ID_REG 0xF4 // UART3 Source ID Register
    #define D10F0F3_UART3_SID D10F0F3_UART3_SRC_ID_REG // 0053h/x/x/x UART0 Source ID
// PCI UART-MMIO
#define PCIUARTMMIO_RECEIVER_BUFFER_RBUF_FOR_READ_WHEN_DLAB_RX03_7_0 0x0 // Receiver Buffer (RBUF) ? For Read When DLAB (Rx03[7]) = 0
    #define PCIUARTMMIO_RBUF PCIUARTMMIO_RECEIVER_BUFFER_RBUF_FOR_READ_WHEN_DLAB_RX03_7_0 // 0/x/x/x Receiver Buffer
#define PCIUARTMMIO_INTR_ENABLE_REG_IER_WHEN_DLAB_0 0x1 // Interrupt Enable Register (IER) ? When DLAB = 0
    #define PCIUARTMMIO_MSI_EN  BIT3    // 0/x/x/x Modem Status Interrupt Enable
    #define PCIUARTMMIO_RLSI_EN BIT2    // 0/x/x/x Receiver Line Status Interrupt Enable
    #define PCIUARTMMIO_THRE_EN BIT1    // 0/x/x/x Transmitter Holding Register Empty Interrupt Enable
    #define PCIUARTMMIO_RDAI_EN BIT0    // 0/x/x/x Received Data Available Interrupt Enable
#define PCIUARTMMIO_INTR_IDENTIFICATION_REG_IIR_WHEN_DLAB_0 0x2 // Interrupt Identification Register (IIR) ? When DLAB = 0
    #define PCIUARTMMIO_FIFO_USE    (BIT6 + BIT7)   // 0/R/x/x FIFO Buffer Status
    #define PCIUARTMMIO_TOINT       BIT3            // 0/R/x/x Time-out Interrupt Pending
    #define PCIUARTMMIO_INT_STS     (BIT1 + BIT2)   // 0/x/x/x Interrupt Occurred Status
    #define PCIUARTMMIO_INTPEND     BIT0            // 1b/R/x/x Interrupt Pending Status
#define PCIUARTMMIO_LINE_CTL_REG_LCR 0x3 // Line Control Register (LCR)
    #define PCIUARTMMIO_DLAB    BIT7                    // 0/x/x/x Divisor Latch Access Bit <DLAB> or Transceiver Buffer Control 
    #define PCIUARTMMIO_BREAKEN BIT6                    // 0/x/x/x Set Break Enable
    #define PCIUARTMMIO_PARITY  (BIT3 + BIT4 + BIT5)    // 0/x/x/x Parity Selection ((Random))
    #define PCIUARTMMIO_STOPLEN BIT2                    // 0/x/x/x Stop Bit Length ((Random))
    #define PCIUARTMMIO_WORDLEN (BIT0 + BIT1)           // 0/x/x/x Word Length ((Random))
#define PCIUARTMMIO_MODEM_CTL_REG_MCR 0x4 // Modem Control Register (MCR)
    #define PCIUARTMMIO_LOOPBACK    BIT4                    // 0/x/x/x Loopback Mode
    #define PCIUARTMMIO_AUX2        BIT3                    // 0/x/x/x Aux Output 2
    #define PCIUARTMMIO_AUX1        BIT2                    // 0/x/x/x Aux Output 1
    #define PCIUARTMMIO_FORCE_RTS   BIT1                    // 0/x/x/x Force Request to Send
    #define PCIUARTMMIO_FORCE_DTR   BIT0                    // 0/x/x/x Force Data Terminal Ready
#define PCIUARTMMIO_LINE_STA_REG_LSR 0x5 // Line Status Register (LSR)
    #define PCIUARTMMIO_RFIFO_ERR   BIT7    // 0/R/x/x Error in Receiver FIFO
    #define PCIUARTMMIO_EDHR        BIT6    // 1b/R/x/x Empty Data Holding Registers
    #define PCIUARTMMIO_ETHR        BIT5    // 1b/R/x/x Empty Transmitter Holding Register
    #define PCIUARTMMIO_BREAK       BIT4    // 0/R/x/x Break Interrupt
    #define PCIUARTMMIO_FRAME_ERR   BIT3    // 0/R/x/x Framing Error
    #define PCIUARTMMIO_PAR_ERR     BIT2    // 0/R/x/x Parity Error
    #define PCIUARTMMIO_OVERRUN     BIT1    // 0/R/x/x Overrun Error
    #define PCIUARTMMIO_DR          BIT0    // 0/R/x/x Data Ready
#define PCIUARTMMIO_MODEM_STA_REG_MSR 0x6 // Modem Status Register (MSR)
    #define PCIUARTMMIO_CD      BIT7    // 0/R/x/x Carrier Detect
    #define PCIUARTMMIO_RI      BIT6    // 0/R/x/x Ring Indicator
    #define PCIUARTMMIO_DSR     BIT5    // 0/R/x/x Data Set Ready
    #define PCIUARTMMIO_CTS     BIT4    // 0/R/x/x Clear To Send
    #define PCIUARTMMIO_DEL_DCD BIT3    // 0/R/x/x Delta Data Carrier Detect
    #define PCIUARTMMIO_TERI    BIT2    // 0/R/x/x Trailing Edge Ring Indicator
    #define PCIUARTMMIO_DEL_DSR BIT1    // 0/R/x/x Delta Data Set Ready
    #define PCIUARTMMIO_DEL_CTS BIT0    // 0/R/x/x Delta Clear to Send
#define PCIUARTMMIO_SCRATCH_REG 0x7 // Scratch Register
    #define PCIUARTMMIO_SCRATCHR PCIUARTMMIO_SCRATCH_REG // 0/x/x/x Scratch Register
#define PCIUARTMMIO_PCI_UART_FIFO_WRITE_ACCESS 0x10 // PCI UART FIFO Write Access
    #define PCIUARTMMIO_PIOFIFOW PCIUARTMMIO_PCI_UART_FIFO_WRITE_ACCESS // 0/x/x/x PCI UART FIFO Write Access
#define PCIUARTMMIO_PCI_UART_FIFO_READ_ACCESS 0x14 // PCI UART FIFO Read Access
    #define PCIUARTMMIO_PIOFIFOR PCIUARTMMIO_PCI_UART_FIFO_READ_ACCESS // 0/x/x/x PCI UART FIFO Read Access
#define PCIUARTMMIO_PCI_UART_RECEIVED_DATA_LEN 0x18 // PCI UART Received Data Length
    #define PCIUARTMMIO_RFIFOLENG   0xF0000     // 0/R/x/x PCI UART Receiver FIFO Length
    #define PCIUARTMMIO_PIORFIFOLEN 0xFFFF      // 0/x/x/x PCI UART Received Data Length
#define PCIUARTMMIO_PCI_UART_DMA_A_ADR_FOR_TRANSMISSION 0x20 // PCI UART DMA-A Address for Transmission
    #define PCIUARTMMIO_TXDMA_BAA PCIUARTMMIO_PCI_UART_DMA_A_ADR_FOR_TRANSMISSION // 0/x/x/x PCI UART DMA-A Start Address for Transmission ((Random))
#define PCIUARTMMIO_PCI_UART_DMA_A_DATA_LEN_FOR_TRANSMISSION 0x24 // PCI UART DMA-A Data Length for Transmission
    #define PCIUARTMMIO_TXDMA_DLA   0xFFFF      // 0/x/x/x PCI UART DMA-A Data Length for TX ((Random))
#define PCIUARTMMIO_PCI_UART_DMA_B_ADR_FOR_TRANSMISSION 0x28 // PCI UART DMA-B Address for Transmission
    #define PCIUARTMMIO_TXDMA_BAB PCIUARTMMIO_PCI_UART_DMA_B_ADR_FOR_TRANSMISSION // 0/x/x/x PCI UART DMA-B Start Address for Transmission ((Random))
#define PCIUARTMMIO_PCI_UART_DMA_B_DATA_LEN_FOR_TRANSMISSION 0x2C // PCI UART DMA-B Data Length for Transmission
    #define PCIUARTMMIO_TXDMA_DLB   0xFFFF      // 0/x/x/x PCI UART DMA-B Data Length for Transmitter((Random))
#define PCIUARTMMIO_PCI_UART_TRANSMITTER_CTL_REG 0x30 // PCI UART Transmitter Control Register
    #define PCIUARTMMIO_TXDMA_OSIVAL    0xFFFF0000  // 0/x/x/x Transmitter DMA One-shot Timer Value ((Random))
    #define PCIUARTMMIO_TXDMA_OSIEN     BIT8        // 0/x/x/x Transmitter DMA One-shot Timer Enable ((Random))
    #define PCIUARTMMIO_TX_FLOWCREN     BIT1        // 0/x/x/x Transmitter Flow Control Enable ((Random))
    #define PCIUARTMMIO_TXDMAEN         BIT0        // 0/x/x/x Transmitter DMA Enable
#define PCIUARTMMIO_PCI_UART_DMA_A_ADR_FOR_RECEIVING 0x40 // PCI UART DMA-A Address for Receiving
    #define PCIUARTMMIO_RXDMA_BAA PCIUARTMMIO_PCI_UART_DMA_A_ADR_FOR_RECEIVING // 0/x/x/x PCI UART DMA-A Start Address for Receiving ((Random))
#define PCIUARTMMIO_PCI_UART_DMA_A_DATA_LEN_FOR_RECEIVING 0x44 // PCI UART DMA-A Data Length for Receiving
    #define PCIUARTMMIO_RXDMA_DLA   0xFFFF      // 0/x/x/x PCI UART DMA-A Data Length for Receiving ((Random))
#define PCIUARTMMIO_PCI_UART_DMA_B_ADR_FOR_RECEIVING 0x48 // PCI UART DMA-B Address for Receiving
    #define PCIUARTMMIO_RXDMA_BAB PCIUARTMMIO_PCI_UART_DMA_B_ADR_FOR_RECEIVING // 0/x/x/x PCI UART DMA-B Start Address for Receiving ((Random))
#define PCIUARTMMIO_PCI_UART_DMA_B_DATA_LEN_FOR_RECEIVING 0x4C // PCI UART DMA-B Data Length for Receiving
    #define PCIUARTMMIO_RXDMA_DLB   0xFFFF      // 0/x/x/x PCI UART DMA-B Data Length for Receiving ((Random))
#define PCIUARTMMIO_PCI_UART_RECEIVER_DMA_CTL_LOW 0x50 // PCI UART Receiver DMA Control Low
    #define PCIUARTMMIO_RXDMAOSIVAL 0xFFFF0000  // 0/x/x/x Receiver DMA One-shot Timer Value ((Random))
    #define PCIUARTMMIO_RXOSI_EN    BIT8        // 0/x/x/x Receiver DMA One-shot Timer Enable ((Random))
    #define PCIUARTMMIO_RXFCTRL     BIT1        // 0/x/x/x Receiver Flow Control Enable ((Random))
    #define PCIUARTMMIO_RXDMA_EN    BIT0        // 0/x/x/x Receiver DMA Enable
#define PCIUARTMMIO_PCI_UART_RECEIVER_DMA_CTL_HIGH 0x54 // PCI UART Receiver DMA Control High
    #define PCIUARTMMIO_TO_VAL      0xFFF00000              // FFFh/x/x/x DMA Timeout Value ((Random))
    #define PCIUARTMMIO_TO_EN       BIT19                   // 0/0/1*/1* DMA Timeout Event Enable
    #define PCIUARTMMIO_UREQ_LVL    0x1E00                  // 0/x/x/x Urgent DMA Request Level ((Random))
    #define PCIUARTMMIO_UREQ_CR     BIT8                    // 0/x/x/x Urgent DMA Request Level Control
    #define PCIUARTMMIO_NREQ_LVL    0x1E                    // 0/x/x/x Normal DMA Request Level ((Random))
    #define PCIUARTMMIO_NREQ_CR     BIT0                    // 0/x/x/x Normal DMA Request Level Control
#define PCIUARTMMIO_PCI_UART_HIGH_BAUD_RATE_CTL_LOW 0x58 // PCI UART High Baud Rate Control Low
    #define PCIUARTMMIO_HPCR    0xF         // 0/x/x/x PCI UART Baud Rate Multiplier ((Random))
#define PCIUARTMMIO_PCI_UART_TXDMA_CURRENT_ADR 0x60 // PCI UART TXDMA Current Address
    #define PCIUARTMMIO_DMACURAD PCIUARTMMIO_PCI_UART_TXDMA_CURRENT_ADR // 0/R/x/x PCI UART TXDMA Current Address
#define PCIUARTMMIO_PCI_UART_TXDMA_CURRENT_LEN 0x64 // PCI UART TXDMA Current Length
    #define PCIUARTMMIO_TDMAACURLEN 0xFFFF0000  // 0/R/x/x PCI UART TXDMA A Current Length
    #define PCIUARTMMIO_TDMABCURLEN 0xFFFF      // 0/R/x/x PCI UART TXDMA B Current Length
#define PCIUARTMMIO_PCI_UART_RXDMA_CURRENT_ADR 0x68 // PCI UART RXDMA Current Address
    #define PCIUARTMMIO_RDMACURAD PCIUARTMMIO_PCI_UART_RXDMA_CURRENT_ADR // 0/R/x/x PCI UART RXDMA Current Address 
#define PCIUARTMMIO_PCI_UART_RXDMA_CURRENT_LEN 0x6C // PCI UART RXDMA Current Length
    #define PCIUARTMMIO_RDMABCURLEN 0xFFFF0000  // 0/R/x/x PCI UART RXDMA_B Current Length
    #define PCIUARTMMIO_RDMAACURLEN 0xFFFF      // 0/R/x/x PCI UART RXDMA_A Current Length
#define PCIUARTMMIO_PCI_UART_DMA_STA 0x70 // PCI UART DMA Status
    #define PCIUARTMMIO_RXDMA_STA   (BIT2 + BIT3)   // 0/R/x/x RXDMA State
    #define PCIUARTMMIO_TXDMA_STA   (BIT0 + BIT1)   // 0/R/x/x TXDMA State
#define PCIUARTMMIO_PCI_UART_NORMAL_INTR_ENABLE_DMA_MODE 0x78 // PCI UART Normal Interrupt Enable DMA Mode
    #define PCIUARTMMIO_ROSINT  BIT7        // 0/x/x/x Receiver One-shot Interrupt Enable
    #define PCIUARTMMIO_TOSINT  BIT6        // 0/x/x/x Transmitter One-shot Interrupt Enable
    #define PCIUARTMMIO_PARINT  BIT5        // 0/x/x/x Parity Check Error Interrupt Enable
    #define PCIUARTMMIO_OVERINT BIT4        // 0/x/x/x FIFO Overrun Interrupt Enable
    #define PCIUARTMMIO_RCOMINT BIT3        // 0/x/x/x Data Receiving Complete Interrupt Enable
    #define PCIUARTMMIO_RXINT   BIT2        // 0/x/x/x DMA Receiving Interrupt Enable
    #define PCIUARTMMIO_TCOMINT BIT1        // 0/x/x/x Data Transmission Complete Interrupt Enable
    #define PCIUARTMMIO_TXINT   BIT0        // 0/x/x/x DMA Transmission Interrupt Enable
#define PCIUARTMMIO_PCI_UART_NORMAL_INTR_STA_UNDER_DMA 0x7C // PCI UART Normal Interrupt Status Under DMA
    #define PCIUARTMMIO_OVERSTS     BIT9        // 0/x/x/x FIFO Overrun Interrupt
    #define PCIUARTMMIO_PARSTS      BIT8        // 0/x/x/x Parity Check Error
    #define PCIUARTMMIO_ROSINT_STS  BIT7        // 0/x/x/x Receiver One-shot Interrupt
    #define PCIUARTMMIO_RCOMINT_STS BIT6        // 0/x/x/x Data Receiving Complete Interrupt
    #define PCIUARTMMIO_RXINTB_STS  BIT5        // 0/x/x/x DMA-B Receiving Interrupt
    #define PCIUARTMMIO_RXINTA_STS  BIT4        // 0/x/x/x DMA-A Receiving Interrupt
    #define PCIUARTMMIO_TOSINT_STS  BIT3        // 0/x/x/x Transmitter One-shot Interrupt
    #define PCIUARTMMIO_TCOMINT_STS BIT2        // 0/x/x/x Data Transmission Complete Interrupt
    #define PCIUARTMMIO_TXINTB_STS  BIT1        // 0/x/x/x DMA-B Transmission Interrupt
    #define PCIUARTMMIO_TXINTA_STS  BIT0        // 0/x/x/x DMA-A Transmission Interrupt
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CND001(1.00)
// Pls contact PLW to report Irs2h bugs.
