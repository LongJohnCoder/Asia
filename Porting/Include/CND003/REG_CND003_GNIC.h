//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_GNIC_R100.doc.
#ifndef IRS_CND003_GNIC_R100_H
#define IRS_CND003_GNIC_R100_H
// D13F0
#define D13F0_VENDER_ID_AND_DID 0x0 // Vender ID and Device ID
    #define D13F0_DID   0xFFFF0000  // 9180h/x/x/x Device ID
    #define D13F0_VID   0xFFFF      // 1106h/x/x/x Vender ID
#define D13F0_DEV_CMD_AND_STA 0x4 // Device Command and Status
    #define D13F0_DPE       BIT31           // 0/0/x/x Detected Parity Error
    #define D13F0_SSE       BIT30           // 0/0/x/x Signaled System Error
    #define D13F0_RMA       BIT29           // 0/0/x/x Received Master Abort
    #define D13F0_RTA       BIT28           // 0/0/x/x Received Target Abort
    #define D13F0_STA       BIT27           // 0/0/x/x Signaled Target Abort
    #define D13F0_DEVSELT   (BIT25 + BIT26) // 0/R/x/x DEVSEL Timing
    #define D13F0_MDPE      BIT24           // 0/0/x/x Master Data Parity Error
    #define D13F0_FBBTC     BIT23           // 0/R/x/x Fast Back-to-Back Transaction Cap
    #define D13F0_C66M      BIT21           // 0/R/x/x 66MHz Capable
    #define D13F0_CAPL      BIT20           // 1b/R/x/x Capabilities List
    #define D13F0_INTS      BIT19           // 0/x/x/x Interrupt Status
    #define D13F0_INTD      BIT10           // 0/*0/x/x Interrupt Disable
    #define D13F0_FBBE      BIT9            // 0/R/x/x Fast Back-to-Back Enable
    #define D13F0_SERRE     BIT8            // 0/0/x/x SERR Enable
    #define D13F0_IDSELS    BIT7            // 0/R/x/x IDSEL Stepping
    #define D13F0_PER       BIT6            // 0/0/x/x Parity ErrorResponse
    #define D13F0_VGAPS     BIT5            // 0/R/x/x VGA Palette Snoop
    #define D13F0_MWI       BIT4            // 0/R/x/x Memory Write and Invalidate
    #define D13F0_SCE       BIT3            // 0/R/x/x Special Cycle Enable
    #define D13F0_BME       BIT2            // 0/*/x/x Bus Master Enable
    #define D13F0_MEMS      BIT1            // 0/*/x/x Memory Space
    #define D13F0_IOS       BIT0            // 0/*/x/x IO Space
#define D13F0_DIDENTIFICATION 0x8 // Device Identification
    #define D13F0_CLASC 0xFFFFFF00  // 020000h/R/x/x Class Code
    #define D13F0_RID   0xFF        // 0/R/x/x Revision ID
#define D13F0_MISC_REGS 0xC // Misc Registers
    #define D13F0_BIST  0xFF000000  // 0/R/x/x BIST
    #define D13F0_HDRT  0xFF0000    // 0/R/x/x Header Type
    #define D13F0_MLT   0xFF00      // 0/R/x/x Master Latency Timer
    #define D13F0_CLS   0xFF        // 0/x/x/x Cache Line Size
#define D13F0_CSR_IO_MAPPED_BASE_ADDR_REGS 0x10 // CSR IO Mapped Base Addr Registers
    #define D13F0_IOBA1 0xFFFFFFE0  // 0/x/x/x CSR IO Mapped Base Addr[31:5]?32Byte?
    #define D13F0_IOBA0 0x1F        // 00001b/R/x/x CSR IO Mapped Base Addr[4:0]
#define D13F0_CSR_MEM_MAPPED_BASE_ADDR_REGS 0x14 // CSR MEM Mapped Base Addr Registers
    #define D13F0_MMBLA3    0xFFFFF000      // 0/x/x/x CSR MEM Mapped Base Addr[31:12]?4K Byte?
    #define D13F0_MMBLA2    0xFF8           // 0/R/x/x CSR MEM Mapped Base Addr[11:0]
    #define D13F0_MMBLA1    BIT2            // 0/R/x/x CSR MEM Bar Bit Length Selection, it?s configurable by EEPROM.
    #define D13F0_MMBLA0    (BIT0 + BIT1)   // 0/R/x/x CSR MEM Mapped Base Addr[1:0]
#define D13F0_CSR_MEM_MAPPED_BASE_HIGH_ADDR_REGS 0x18 // CSR MEM Mapped Base High Addr Registers
    #define D13F0_MMBHA D13F0_CSR_MEM_MAPPED_BASE_HIGH_ADDR_REGS // 0/x/x/x CSR MEM Mapped Base High Addr[63:32]
#define D13F0_MSI_X_MEM_MAPPED_BASE_ADDR_REGS 0x1C // MSI-X MEM Mapped Base Addr Registers
    #define D13F0_MSIXMBAH  0xFFFFE000  // 0/x/x/x MSI-X MEM Mapped Base Addr[31:13]?8K Byte?
    #define D13F0_MSIXMBAL  0x1FFF      // 0/R/x/x MSI-X MEM Mapped Base Addr[12:0]
#define D13F0_SVID_AND_SSID_REGS 0x2C // Subsystem Vendor ID and Subsystem ID Registers
    #define D13F0_SID   0xFFFF0000  // 0130h/x/x/x Subsystem ID
    #define D13F0_SVID  0xFFFF      // 1106h/x/x/x Subsystem Vendor ID
#define D13F0_EXPANSION_ROM_BASE_ADR 0x30 // Expansion ROM Base Address
    #define D13F0_EXPROM    0xFFFFE000  // 0/x/x/x EXPANSION ROM Base Address
    #define D13F0_ROMBSEN   BIT0        // 0/0/x/x EXPANSION ROM enable bit
#define D13F0_CAP_PTR 0x34 // Capability Pointer
    #define D13F0_CP    0xFF        // 50h/R/x/x Capability Pointer
#define D13F0_DEV_CMD 0x3C // Device Command
    #define D13F0_MAXL  0xFF000000  // 0/R/x/x Max_Lat
    #define D13F0_MING  0xFF0000    // 0/R/x/x Min_Gnt
    #define D13F0_INTP  0xFF00      // 1h/R/x/x Interrupt Pin
    #define D13F0_INTL  0xFF        // 0/x/x/x Interrupt Line
#define D13F0_PM_CAP 0x50 // PM Capability
    #define D13F0_PMES  0xF8000000              // 10000b/R/x/x PME Support (eeprom)
    #define D13F0_D2S   BIT26                   // 0/R/x/x D2 Support (eeprom)
    #define D13F0_D1S   BIT25                   // 0/R/x/x D1 Support (eeprom)
    #define D13F0_AUXC  (BIT22 + BIT23 + BIT24) // 0/R/x/x AUX Current (eeprom)
    #define D13F0_DSI   BIT21                   // 0/R/x/x Device Specific Initialization (DSI) (eeprom)
    #define D13F0_PMEC  BIT19                   // 0/R/x/x PME Clock
    #define D13F0_VER   (BIT16 + BIT17 + BIT18) // 010b/R/x/x Version
    #define D13F0_NXTP0 0xFF00                  // C0h/R/x/x Next PTR
    #define D13F0_CID0  0xFF                    // 1h/R/x/x Capability ID
#define D13F0_PM_STA_CTL 0x54 // PM Status Control
    #define D13F0_DATA  0xFF000000      // 0/R/x/x Data
    #define D13F0_BPCE  BIT23           // 0/R/x/x Bus Power/Clock Control Enable
    #define D13F0_BS    BIT22           // 0/R/x/x B2/B3 Support
    #define D13F0_PMEST BIT15           // 0/x/x/x PME Status
    #define D13F0_DSC   (BIT13 + BIT14) // 0/R/x/x Data Scale
    #define D13F0_DSE   0x1E00          // 0/R/x/x Data Select
    #define D13F0_PMEE  BIT8            // 0/x/x/x PME Enable
    #define D13F0_PSTAT (BIT0 + BIT1)   // 0/0/x/x Power State
#define D13F0_MODE_REG 0x60 // Mode Register
    #define D13F0_MIION     BIT26           // 0/x/x/x Option to detecting GMII.RXER
    #define D13F0_PCEROPT   BIT23           // 0/x/x/x Take PCI Bus Error as a Fatal Error and shut down from software control
    #define D13F0_TXQ16     BIT22           // 0/x/x/x Tx write-back queue control
    #define D13F0_QPKTDIS   BIT21           // 0/x/x/x Disable Transmit Frame Queuing
    #define D13F0_TCPLSOPT  BIT16           // 0/x/x/x TCP large send field update disable, hardware will not update related...
    #define D13F0_MSI64     BIT5            // 0/x/x/x Reserved
    #define D13F0_MSIBDIS   BIT4            // 0/x/x/x Reserved
    #define D13F0_MSIXBDIS  BIT3            // 0/x/x/x Reserved
    #define D13F0_SVIDLK    BIT2            // 0/x/x/x Reserved
    #define D13F0_DRIDLK    BIT1            // 0/x/x/x Reserved
    #define D13F0_VIDLK     BIT0            // 0/x/x/x Reserved
#define D13F0_MSI_CTL_REG_STRUCTURE 0xC0 // MSI Control Register Structure
    #define D13F0_PVMC  BIT24                   // 1b/R/x/x PVM capable(Per Vector Mask)
    #define D13F0_BAC64 BIT23                   // 0/R/x/x 64 bit address capable
    #define D13F0_MME   (BIT20 + BIT21 + BIT22) // 0/x/x/x Multiple Message Enable
    #define D13F0_MMC   (BIT17 + BIT18 + BIT19) // 011b/R/x/x Multiple Message Capable
    #define D13F0_MSIE  BIT16                   // 0/x/x/x MSI Enable
    #define D13F0_NXT2  0xFF00                  // E0h/R/x/x Next PTR
    #define D13F0_CID2  0xFF                    // 5h/R/x/x Capability ID
#define D13F0_MSI_LOW_ADR 0xC4 // MSI Low Address
    #define D13F0_MSILA 0xFFFFFFFC      // 0/x/x/x MSI Low Address
#define D13F0_MSI_HIGH_ADR 0xC8 // MSI High Address
    #define D13F0_MSIHA D13F0_MSI_HIGH_ADR // 0/x/x/x MSI High Address
#define D13F0_MSI_DATA_REG 0xCC // MSI Data Register
    #define D13F0_MSIDR 0xFFFF      // 0/x/x/x MSI Data Register
#define D13F0_MSI_MASK 0xD0 // MSI Mask
    #define D13F0_MSIMH 0xFFFFFF00  // 0/R/x/x MSI Mask
    #define D13F0_MSIML 0xFF        // 0/x/x/x MSI Mask
#define D13F0_MSI_PENDING 0xD4 // MSI Pending
    #define D13F0_MSIP D13F0_MSI_PENDING // 0/R/x/x MSI Pending
#define D13F0_MSI_X_CAP_STRUCTURE1 0xE0 // MSI-X Capability Structure1
    #define D13F0_MSIXEN    BIT31                   // 0/x/x/x MSI-X Enable
    #define D13F0_FUNMSK    BIT30                   // 0/x/x/x Function Mask
    #define D13F0_TABSZ     0x7FF0000               // 7h/R/x/x Table Size
    #define D13F0_NPTR      0xFF00                  // 0/R/x/x Next PTR
    #define D13F0_CAPID     0xFF                    // 11h/R/x/x Capability ID
#define D13F0_MSI_X_CAP_STRUCTURE2 0xE4 // MSI-X Capability Structure2
    #define D13F0_TABO      0xFFFFFFF8              // 0/R/x/x Table offset
    #define D13F0_TABBIR    (BIT0 + BIT1 + BIT2)    // 011b/R/x/x Table BIR
#define D13F0_MSI_X_CAP_STRUCTURE3 0xE8 // MSI-X Capability Structure3
    #define D13F0_PBAO      0xFFFFFFF8              // 200h/R/x/x PBA offset
    #define D13F0_PBABIR    (BIT0 + BIT1 + BIT2)    // 011b/R/x/x PBA BIR
// GNIC_MMIO
#define GNICMMIO_ETHERNET_NODE_ADR_REG_PAR0_PAR3 0x0 // Ethernet Node Address Register (PAR0~PAR3)
    #define GNICMMIO_PAR3   0xFF000000  // 0/x/x/x Ethernet node ID [47:0], which is split to 6 bytes: PAR0 ~ PAR5.
    #define GNICMMIO_PAR2   0xFF0000    // 0/x/x/x Ethernet node ID [47:0], which is split to 6 bytes: PAR0 ~ PAR5.
    #define GNICMMIO_PAR1   0xFF00      // 0/x/x/x Ethernet node ID [47:0], which is split to 6 bytes: PAR0 ~ PAR5.
    #define GNICMMIO_PAR0   0xFF        // 0/x/x/x Ethernet node ID [47:0], which is split to 6 bytes: PAR0 ~ PAR5.
#define GNICMMIO_TRANSMIT_CTL_AND_RECEIVE_CTL_REG_TCR_RCR 0x4 // Transmit Control and Receive Control Register (TCR RCR)
    #define GNICMMIO_TB2BDIS    BIT31           // 0/x/0/x Frame bursting disable in 1000Mbps mode (TB2BDIS)
    #define GNICMMIO_RRCO       BIT28           // 0/x/x/x Read Request Clear Option
    #define GNICMMIO_COLTMC     (BIT26 + BIT27) // 0/x/x/x Collision retry control before abort current transmission. (COLTMC)
    #define GNICMMIO_LB         (BIT24 + BIT25) // 0/0/x/x Internal/External loopback control (LB)
    #define GNICMMIO_AS         BIT23           // 0/x/x/x Accept symbol error packet with good CRC (AS)
    #define GNICMMIO_AP         BIT22           // 0/*/x/x Accept packet through perfect-filtering. Leave the receive type statu...
    #define GNICMMIO_AL         BIT21           // 0/*/x/x Accept long packet, 1518/1522 (if contain TAG) (AL)
    #define GNICMMIO_PROM       BIT20           // 0/*/x/x Promiscuous mode. Accept all physical address packets (PROM)
    #define GNICMMIO_AB         BIT19           // 0/*/x/x Accept broadcast packet (AB)
    #define GNICMMIO_AM         BIT18           // 0/*/x/x Accept multicast packet (AM)
    #define GNICMMIO_AR         BIT17           // 0/*/x/x Accept runt packet (AR)
    #define GNICMMIO_SEP        BIT16           // 0/x/x/x Accept addressed packet with CRC error (SEP)
    #define GNICMMIO_PAR5       0xFF00          // 0/x/x/x Ethernet node ID [47:0],  which is split to 6 bytes: PAR0 ~ PAR5. Thi...
    #define GNICMMIO_PAR4       0xFF            // 0/x/x/x Ethernet node ID [47:0],  which is split to 6 bytes: PAR0 ~ PAR5. Thi...
#define GNICMMIO_GLOBAL_CMD_REG_CR0_CR1_CR2_CR3 0x8 // Global Command Register (CR0 CR1 CR2 CR3)
    #define GNICMMIO_GSPRST     BIT31           // 0/0/x/x Software generated force suspend reset for diagnosis purpose only.  (...
    #define GNICMMIO_FOSRST     BIT30           // 0/x/x/x Force exit software stop without waiting for safestate.  (FOSRST)
    #define GNICMMIO_FPHYRST    BIT29           // 0/x/x/x To be deleted.
    #define GNICMMIO_DIAG       BIT28           // 0/0/x/x DIAG
    #define GNICMMIO_SMBRST     BIT27           // 0/x/x/x Force smbus internal reset (SMBRST)
    #define GNICMMIO_INTPCTL    BIT26           // 0/x/x/x Enable interrupt pending hold-off timer control (INTPCTL)
    #define GNICMMIO_GINTMSK1   BIT25           // 0/*/x/x Global interrupt mask 1. Disable INTA# generation from all ISR bits. ...
    #define GNICMMIO_GINTMSK0   BIT24           // 0/*/x/x Software control multiple level interrupt mask 0. disable INTA# gener...
    #define GNICMMIO_XONEN      BIT23           // 0/x/x/x IEEE 802.3x, XON/XOFF mode enable (XONEN)
    #define GNICMMIO_FDXTFCEN   BIT22           // 0/x/x/x Full-duplex flow control TX enabled (FDXTFCEN)
    #define GNICMMIO_FDXRFCEN   BIT21           // 0/x/x/x Full-duplex flow control RX enabled (FDXRFCEN)
    #define GNICMMIO_HDXFCEN    BIT20           // 0/x/x/x Half-duplex flow control enabled (HDXFCEN)
    #define GNICMMIO_XHITH      (BIT18 + BIT19) // 0/x/x/x Transmit XON frame high threshold (XHITH)
    #define GNICMMIO_XLITH      (BIT16 + BIT17) // 0/x/x/x Transmit pause frame low threshold (XLITH)
    #define GNICMMIO_SFRST      BIT15           // 0/0/x/x Software reset. Clear by itself after internal logic reach a safe sta...
    #define GNICMMIO_TM1EN      BIT14           // 0/*/x/x Enable periodic software timer counting (TM1EN)
    #define GNICMMIO_TM0EN      BIT13           // 0/*/x/x Enable single-shot software timer counting (TM0EN)
    #define GNICMMIO_MDISAB     BIT10           // 0/x/x/x Disable accept broadcast packet when AM = 1 (MDISAB)
    #define GNICMMIO_JBO_SP     BIT9            // 1b/x/x/x Jumbo packet enable threshold in SF mode (JBO_SP)
    #define GNICMMIO_DISAU      BIT8            // 0/*/x/x Unicast reception disable (DISAU)
    #define GNICMMIO_TXON       BIT3            // 0/*1/x/x Transmit process enable check the relationship with TD RUN bits (TXON)
    #define GNICMMIO_RXON       BIT2            // 0/*1/x/x Receive process enable, check the relationship with RD RUN bits (RXON)
    #define GNICMMIO_STOP       BIT1            // 1b/*/x/x Stop NIC, reset STRT, set while S_RST/H_RST (STOP)
    #define GNICMMIO_STRT       BIT0            // 0/*/x/x Start NIC, reset while stop or S_RST/H_RST. To turn on TXON/RXON,  ST...
#define GNICMMIO_GLOBAL_CMD_REG_CLEAR_PORT_CR0_C_CR1_C_CR2_C_CR3_C 0xC // Global Command Register Clear Port (CR0.c CR1.c  CR2.c CR3.c)
    #define GNICMMIO_GSPRSTC    BIT31           // 0/0/x/x Clear Software generated force suspend reset for diagnosis purpose on...
    #define GNICMMIO_FOSRSTC    BIT30           // 0/x/x/x Clear Force exit software stop without waiting for safestate.  (FOSRST)
    #define GNICMMIO_FPHYRSTC   BIT29           // 0/x/x/x To be deleted.
    #define GNICMMIO_DIAGC      BIT28           // 0/x/x/x Clear DIAG
    #define GNICMMIO_SMBRSTC    BIT27           // 0/x/x/x Clear Force smbus internal reset (SMBRST)
    #define GNICMMIO_INTPCTLC   BIT26           // 0/x/x/x Clear Enable interrupt pending hold-off timer control (INTPCTL)
    #define GNICMMIO_GINTMSK1C  BIT25           // 0/*/x/x Clear Global interrupt mask 1. Disable INTA# generation from all ISR ...
    #define GNICMMIO_GINTMSK0C  BIT24           // 0/*/x/x Clear Software control multiple level interrupt mask 0. disable INTA#...
    #define GNICMMIO_XONENC     BIT23           // 0/x/x/x Clear IEEE 802.3x, XON/XOFF mode enable (XONEN)
    #define GNICMMIO_FDXTFCENC  BIT22           // 0/x/x/x Clear Full-duplex flow control TX enabled (FDXTFCEN)
    #define GNICMMIO_FDXRFCENC  BIT21           // 0/x/x/x Clear Full-duplex flow control RX enabled (FDXRFCEN)
    #define GNICMMIO_HDXFCENC   BIT20           // 0/x/x/x Clear Half-duplex flow control enabled (HDXFCEN)
    #define GNICMMIO_XHITHC     (BIT18 + BIT19) // 0/x/x/x Clear Transmit XON frame high threshold (XHITH)
    #define GNICMMIO_XLITHC     (BIT16 + BIT17) // 0/x/x/x Clear Transmit pause frame low threshold (XLITH)
    #define GNICMMIO_SFRSTC     BIT15           // 0/0/x/x Clear Software reset. Clear by itself after internal logic reach a sa...
    #define GNICMMIO_TM1ENC     BIT14           // 0/*/x/x Clear Enable periodic software timer counting (TM0EN)
    #define GNICMMIO_TM0ENC     BIT13           // 0/*/x/x Clear Enable single-shot software timer counting (TM0EN)
    #define GNICMMIO_MDISABC    BIT10           // 0/x/x/x Clear Disable accept broadcast packet when AM = 1 (MDISAB)
    #define GNICMMIO_JBO_SPC    BIT9            // 1b/x/x/x Clear Jumbo packet enable threshold in SF mode (JBO_SP)
    #define GNICMMIO_DISAUC     BIT8            // 0/*/x/x Clear Unicast reception disable (DISAU)
    #define GNICMMIO_TXONC      BIT3            // 0/*1/x/x Clear Transmit process enable check the relationship with TD RUN bit...
    #define GNICMMIO_RXONC      BIT2            // 0/*1/x/x Clear Receive process enable, check the relationship with RD RUN bit...
    #define GNICMMIO_STOPC      BIT1            // 1b/*0/x/x Clear Stop NIC, reset STRT, set while S_RST/H_RST (STOP)
    #define GNICMMIO_STRTC      BIT0            // 0/*1/x/x Clear Start NIC, reset while stop or S_RST/H_RST. To turn on TXON/RX...
#define GNICMMIO_MULTICAST_HASHING_TABLE_REG_MAR0_3 0x10 // Multicast Hashing Table Register (MAR0~3)
    #define GNICMMIO_MAR3   0xFF000000  // 0/x/x/x Multicast hashing table Part3.
    #define GNICMMIO_MAR2   0xFF0000    // 0/x/x/x Multicast hashing table Part2.
    #define GNICMMIO_MAR1   0xFF00      // 0/x/x/x Multicast hashing table Part1.
    #define GNICMMIO_MAR0   0xFF        // 0/x/x/x Multicast hashing table Part0.
#define GNICMMIO_MULTICAST_HASHING_TABLE_REG_MAR4_7 0x14 // Multicast Hashing Table Register (MAR4~7)
    #define GNICMMIO_MAR7   0xFF000000  // 0/x/x/x Multicast hashing table Part7.
    #define GNICMMIO_MAR6   0xFF0000    // 0/x/x/x Multicast hashing table Part6.
    #define GNICMMIO_MAR5   0xFF00      // 0/x/x/x Multicast hashing table Part5.
    #define GNICMMIO_MAR4   0xFF        // 0/x/x/x Multicast hashing table Part4.
#define GNICMMIO_TX_RX_DESCRIPTOR_BASE_ADR_HIGH_REG_DESCBASE_HI 0x18 // Tx/Rx Descriptor Base Address High Register(DescBase.Hi)
    #define GNICMMIO_DESCBASEHI GNICMMIO_TX_RX_DESCRIPTOR_BASE_ADR_HIGH_REG_DESCBASE_HI // 0/x/x/x Tx/Rx descriptor high address (DescBaseHi[63:32]).
#define GNICMMIO_TX_RX_COMMON_DATA_BUFFER_BASE_ADR_HIGH_REG_DATABUFBASE_HI 0x1C // Tx/Rx Common Data Buffer Base Address High Register(DataBufBase.Hi)
    #define GNICMMIO_DATABUFBASEHI  0xFFFF      // 0/x/x/x Reserved
#define GNICMMIO_INTR_CTL_REG_ISR_CTL_TXE_SR_RXE_SR 0x20 // Interrupt Control Register(ISR_CTL TXE_SR RXE_SR)
    #define GNICMMIO_RFDBS0     BIT27           // 0/0/x/x Rx queue0 FIFO DMA experience Host bus error. Write 1 clear the bit. ...
    #define GNICMMIO_RDWBS0     BIT26           // 0/0/x/x RD queue0 write back host bus Error. Write 1 clear the bit. Write 0 r...
    #define GNICMMIO_RDRBS0     BIT25           // 0/0/x/x RD queue0 Fetch host bus Error. Write 1 clear the bit. Write 0 remain...
    #define GNICMMIO_RDSTR0     BIT24           // 0/0/x/x RD queue0 structure Error. Write 1 clear the bit. Write 0 remain unch...
    #define GNICMMIO_TFDBS      BIT19           // 0/0/x/x Transmit FIFO DMA bus error (TFDBS)
    #define GNICMMIO_TDWBS      BIT18           // 0/0/x/x TD write back host bus error (TDWBS)
    #define GNICMMIO_TDRBS      BIT17           // 0/0/x/x TD descriptor fetch host bus error (TDRBS)
    #define GNICMMIO_TDSTR      BIT16           // 0/0/x/x TD structure Error (TDSTR)
    #define GNICMMIO_UDPINTS    BIT15           // 0/x/x/x User define interrupt set port (UDPINT.s)
    #define GNICMMIO_TSUPPDIS   BIT14           // 0/x/x/x Tx interrupt suppression feature (TSUPP_DIS)
    #define GNICMMIO_RSUPPDIS   BIT13           // 0/x/x/x Rx interrupt suppression feature (RSUPP_DIS)
    #define GNICMMIO_PMSK       (BIT11 + BIT12) // 0/x/x/x Effective when GintMsk is enable, these setting control interrupt hol...
    #define GNICMMIO_INTPENDING BIT10           // 0/R/x/x Hardware hold-off interrupt pending status (INT_Pending)
    #define GNICMMIO_HCRELOAD   BIT9            // 0/x/x/x In this mode, INTHOTMR is reloaded when HFLD bit in ISR2 is set (HC_R...
    #define GNICMMIO_SCRELOAD   BIT8            // 0/x/x/x Reload of SC value. (SC_RELOAD)
    #define GNICMMIO_INTHOTMR   0xFF            // 0/x/x/x INTHOTMR. Counter values to prevent interrupt assertion for a program...
#define GNICMMIO_INTR_STA_REG_ISR0_ISR1_ISR2_ISR3 0x24 // Interrupt Status Register(ISR0 ISR1 ISR2 ISR3)
    #define GNICMMIO_ISR3       BIT31           // 0/R/x/x Interrupt Source indication.( ISR3)
    #define GNICMMIO_ISR2       BIT30           // 0/R/x/x Interrupt Source indication.( ISR2)
    #define GNICMMIO_ISR1       BIT29           // 0/R/x/x Interrupt Source indication.( ISR1)
    #define GNICMMIO_ISR0       BIT28           // 0/R/x/x Interrupt Source indication.( ISR0)
    #define GNICMMIO_TXSTLI     BIT25           // 0/R/x/x Transmission DMA stall in TXE_SR
    #define GNICMMIO_RXSTL0I    BIT24           // 0/R/x/x Receive DMA stall in RXE_SR
    #define GNICMMIO_UDPI       BIT22           // 0/x/x/x User defined, software driven interrupt for diagnosis. Set by 0x20bit 15
    #define GNICMMIO_MIBFI      BIT21           // 0/x/x/x MIB counter near full.
    #define GNICMMIO_SHDNII     BIT20           // 0/x/x/x Software shutdown complete. Set by 0x08bit 31 GSPRST.
    #define GNICMMIO_PHYI       BIT19           // 0/x/x/x While PHYINTEN enabled, this bit show phy interrupt event occurred.
    #define GNICMMIO_PWEI       BIT18           // 0/x/x/x Wake up power events reporting status for test purpose.
    #define GNICMMIO_TMR1I      BIT17           // 0/x/x/x Programmable software timer 1 expired interrupt status.
    #define GNICMMIO_TMR0I      BIT16           // 0/x/x/x Programmable software timer 0 expired interrupt status.
    #define GNICMMIO_SRCI       BIT15           // 0/x/x/x Port Status change.
    #define GNICMMIO_LSTPE0I    BIT14           // 0/x/x/x RD0 list is using up warning.
    #define GNICMMIO_LSTE0I     BIT13           // 0/x/x/x Receive descriptor0 (RD0) is used up.
    #define GNICMMIO_OVFI       BIT12           // 0/x/x/x Receive FIFO overflow, some receive packets might be lost in this case.
    #define GNICMMIO_FLONI      BIT11           // 0/x/x/x Receive flow control mechanism turn on status as a notification to dr...
    #define GNICMMIO_RACEI      BIT10           // 0/x/x/x Receive FIFO Packet list queue overflow. (RACEI)
    #define GNICMMIO_RCABT      BIT9            // 0/x/x/x P2C read master abort indication.
    #define GNICMMIO_PRXI       BIT8            // 0/x/x/x Combination results of PRXnI (PRXI),HW Set
    #define GNICMMIO_PTXNI      0xF0            // 0/x/x/x Transmit service complete status in TD queue #3/2/1/0. Write 1 will c...
    #define GNICMMIO_PTXI       BIT3            // 0/x/x/x Combination results of PTXnI (PTXI),HW set
    #define GNICMMIO_PRX0I      BIT2            // 0/x/x/x Receive service complete status in RD queue 0.
    #define GNICMMIO_PPTXI      BIT1            // 0/x/x/x High priority transmit interrupt service request. PTXnI will also be ...
    #define GNICMMIO_PPRX0I     BIT0            // 0/x/x/x Queue 0 High priority receive interrupt service request. PRX0I will a...
#define GNICMMIO_INTR_ENABLE_REG_MASK_IMR0_IMR1_IMR2_IMR3 0x28 // Interrupt Enable Register(Mask) (IMR0 IMR1 IMR2 IMR3)
    #define GNICMMIO_IMR0 GNICMMIO_INTR_ENABLE_REG_MASK_IMR0_IMR1_IMR2_IMR3 // 0/x/x/x Interrupt source enable control, it is mapping to Rx027-024[31:0].
#define GNICMMIO_INTR_ENABLE_CLEAR_REG_MASK_IMR0C_IMR1C_IMR2C_IMR3C 0x2C // Interrupt Enable Clear Register(Mask) (IMR0c IMR1c IMR2c IMR3c)
    #define GNICMMIO_IMR0C GNICMMIO_INTR_ENABLE_CLEAR_REG_MASK_IMR0C_IMR1C_IMR2C_IMR3C // 0/x/x/x Clear Interrupt source enable control bit, it is mapping to Rx027-024...
#define GNICMMIO_TX_DESCRIPTOR_CTL_STA_REG_TDCSR 0x30 // Tx Descriptor Control Status Register(TDCSR)
    #define GNICMMIO_DEAD3  BIT15       // 0/0/x/x Indicate TD queue #3 encounters error conditions (set by HW, reset by...
    #define GNICMMIO_WAK3   BIT14       // 0/x/x/x Wake up TD queue #3 to see if there is unprocessed descriptor (set by...
    #define GNICMMIO_ACT3   BIT13       // 0/x/x/x Indicate the end of TD queue #3 has not been reached when processing ...
    #define GNICMMIO_RUN3   BIT12       // 0/x/x/x Enable TD queue #3 to operate (set and reset by SW)
    #define GNICMMIO_DEAD2  BIT11       // 0/0/x/x Indicate TD queue #2 encounters error conditions (set by HW, reset by...
    #define GNICMMIO_WAK2   BIT10       // 0/x/x/x Wake up TD queue #2 to see if there is unprocessed descriptor (set by...
    #define GNICMMIO_ACT2   BIT9        // 0/x/x/x Indicate the end of TD queue #2 has not been reached when processing ...
    #define GNICMMIO_RUN2   BIT8        // 0/x/x/x Enable TD queue #2 to operate (set and reset by SW)
    #define GNICMMIO_DEAD1  BIT7        // 0/0/x/x Indicate TD queue #1 encounters error conditions (set by HW, reset by...
    #define GNICMMIO_WAK1   BIT6        // 0/x/x/x Wake up TD queue #1 to see if there is unprocessed descriptor (set by...
    #define GNICMMIO_ACT1   BIT5        // 0/x/x/x Indicate the end of TD queue #1 has not been reached when processing ...
    #define GNICMMIO_RUN1   BIT4        // 0/x/x/x Enable TD queue #1 to operate (set and reset by SW)
    #define GNICMMIO_DEAD0  BIT3        // 0/0/x/x Indicate TD queue #0 encounters error conditions (set by HW, reset by...
    #define GNICMMIO_WAK0   BIT2        // 0/x/x/x Wake up TD queue #0 to see if there is unprocessed descriptor (set by...
    #define GNICMMIO_ACT0   BIT1        // 0/x/x/x Indicate the end of TD queue #0 has not been reached when processing ...
    #define GNICMMIO_RUN0   BIT0        // 0/x/x/x Enable TD queue #0 to operate (set and reset by SW)
#define GNICMMIO_TX_DESCRIPTOR_CTL_STA_REG_CLEAR_TDCSR_C 0x34 // Tx Descriptor Control Status Register Clear (TDCSR.c)
    #define GNICMMIO_DEAD3C BIT15       // 0/x/x/x Indicate TD queue #3 encounters error conditions (set by HW, reset by...
    #define GNICMMIO_WAK3C  BIT14       // 0/x/x/x Wake up TD queue #3 to see if there is unprocessed descriptor (set by...
    #define GNICMMIO_ACT3C  BIT13       // 0/x/x/x Indicate the end of TD queue #3 has not been reached when processing ...
    #define GNICMMIO_RUN3C  BIT12       // 0/x/x/x Enable TD queue #3 to operate (set and reset by SW), It is to clear t...
    #define GNICMMIO_DEAD2C BIT11       // 0/x/x/x Indicate TD queue #2 encounters error conditions (set by HW, reset by...
    #define GNICMMIO_WAK2C  BIT10       // 0/x/x/x Wake up TD queue #2 to see if there is unprocessed descriptor (set by...
    #define GNICMMIO_ACT2C  BIT9        // 0/x/x/x Indicate the end of TD queue #2 has not been reached when processing ...
    #define GNICMMIO_RUN2C  BIT8        // 0/x/x/x Enable TD queue #2 to operate (set and reset by SW) , It is to clear ...
    #define GNICMMIO_DEAD1C BIT7        // 0/x/x/x Indicate TD queue #1 encounters error conditions (set by HW, reset by...
    #define GNICMMIO_WAK1C  BIT6        // 0/x/x/x Wake up TD queue #1 to see if there is unprocessed descriptor (set by...
    #define GNICMMIO_ACT1C  BIT5        // 0/x/x/x Indicate the end of TD queue #1 has not been reached when processing ...
    #define GNICMMIO_RUN1C  BIT4        // 0/x/x/x Enable TD queue #1 to operate (set and reset by SW) , It is to clear ...
    #define GNICMMIO_DEAD0C BIT3        // 0/x/x/x Indicate TD queue #0 encounters error conditions (set by HW, reset by...
    #define GNICMMIO_WAK0C  BIT2        // 0/x/x/x Wake up TD queue #0 to see if there is unprocessed descriptor (set by...
    #define GNICMMIO_ACT0C  BIT1        // 0/x/x/x Indicate the end of TD queue #0 has not been reached when processing ...
    #define GNICMMIO_RUN0C  BIT0        // 0/x/x/x Enable TD queue #0 to operate (set and reset by SW) , It is to clear ...
#define GNICMMIO_PENDING_TIMER_FOR_TX_QUEUE_RX_QUEUE_EMPTY_INTR_TQETMR_RQETMR 0x3C // Pending Timer For Tx Queue/Rx Queue Empty Interrupt(TQETMR RQETMR)
    #define GNICMMIO_RQETMS (BIT30 + BIT31) // 0/x/x/x Strapping by J_EEFAST, if J_EEFAST = 1, the resolution is 50ns; if J_...
    #define GNICMMIO_RQETMR 0x3F000000      // 0/x/x/x Pending time count
    #define GNICMMIO_TQETMS (BIT22 + BIT23) // 0/x/x/x Strapping by J_EEFAST, if J_EEFAST = 1, the resolution is 50ns; if J_...
    #define GNICMMIO_TQETMR 0x3F0000        // 0/x/x/x Pending time count
#define GNICMMIO_TX_DESCRIPTOR_0_BASE_ADR_LOW_REG_TDBASE0_LO 0x40 // Tx Descriptor 0 Base Address Low  Register(TdBase0.Lo)
    #define GNICMMIO_TDBASE0LO  0xFFFFFFC0  // 0/x/x/x TD #0 base address low. (TdBase0.Lo[31:6])
#define GNICMMIO_TX_DESCRIPTOR_1_BASE_ADR_LOW_REG_TDBASE1_LO 0x44 // Tx Descriptor 1 Base Address Low Register(TdBase1.Lo)
    #define GNICMMIO_TDBASE1LO  0xFFFFFFC0  // 0/x/x/x TD #1 base address low. (TdBase1.Lo[31:6])
#define GNICMMIO_TX_DESCRIPTOR_2_BASE_ADR_LOW_REG_TDBASE2_LO 0x48 // Tx Descriptor 2 Base Address Low Register(TdBase2.Lo)
    #define GNICMMIO_TDBASE2LO  0xFFFFFFC0  // 0/x/x/x TD #2 base address low. (TdBase2.Lo[31:6])
#define GNICMMIO_TX_DESCRIPTOR_3_BASE_ADR_LOW_REG_TDBASE3_LO 0x4C // Tx Descriptor 3 Base Address Low Register(TdBase3.Lo)
    #define GNICMMIO_TDBASE3LO  0xFFFFFFC0  // 0/x/x/x TD #3 base address low. (TdBase3.Lo[31:6])
#define GNICMMIO_TX_DESCRIPTOR_REG_TD 0x50 // Tx Descriptor Register (TD)
    #define GNICMMIO_TDCSIZE    0xFFF0000   // 0/x/x/x 12 bits of TD list length in each TD queue.
#define GNICMMIO_CURRENT_TX_DESCRIPTOR_INDEX_0_1_REG 0x54 // Current Tx Descriptor Index 0 ,1 Register
    #define GNICMMIO_TDINDEX1   0xFFF0000   // 0/x/x/x Current indexed TD in queue #1. Cross top while reach the TDCSIZE def...
    #define GNICMMIO_TDINDEX0   0xFFF       // 0/x/x/x Current indexed TD in queue #0. Cross top while reach the TDCSIZE def...
#define GNICMMIO_CURRENT_TX_DESCRIPTOR_INDEX_2_3_REG 0x58 // Current Tx Descriptor Index. 2,3 Register
    #define GNICMMIO_TDINDEX3   0xFFF0000   // 0/x/x/x Current indexed TD in queue #3. Cross top while reach the TDCSIZE def...
    #define GNICMMIO_TDINDEX2   0xFFF       // 0/x/x/x Current indexed TD in queue #2. Cross top while reach the TDCSIZE def...
#define GNICMMIO_TX_PROGRAMABLE_PAUSE_FRAME_TIMER_REG 0x5C // Tx Programable Pause Frame Timer Register
    #define GNICMMIO_TXPUTM_15_0    0xFFFF      // 0/x/x/x Software programmed Pause Frame Timer in transmitted pause frame.
#define GNICMMIO_TX_CTL_AND_FIFO_TEST_CTL_CMD_REG 0x64 // TX Control and FIFO Test Control Command  Register
    #define GNICMMIO_TRSTPTR    BIT28                   // 0/x/x/x TRSTPTR
    #define GNICMMIO_TSTXPOP    BIT27                   // 0/x/x/x TSTXPOP
    #define GNICMMIO_TXCOLABT   BIT26                   // 0/x/x/x TXCOLABT
    #define GNICMMIO_TXDONE     BIT25                   // 0/x/x/x TXDONE
    #define GNICMMIO_TXRETRY    BIT24                   // 0/x/x/x TXRETRY.
#define GNICMMIO_RX_CTL_AND_FIFO_TEST_CTL_CMD_REG 0x68 // RX Control and FIFO Test Control Command  Register
    #define GNICMMIO_RRSTPTR    BIT28                   // 0/x/x/x RRSTPTR reset rxfifoc pointer. (BNRY/CURR/FCOUNT)
    #define GNICMMIO_TSTRPSH    BIT27                   // 0/x/x/x TSTRPSH
    #define GNICMMIO_RXBAKOUT   BIT26                   // 0/x/x/x RXBAKOUT
    #define GNICMMIO_RXEOF      BIT25                   // 0/x/x/x RXEOF.
    #define GNICMMIO_RXSOF      BIT24                   // 0/x/x/x RXSOF.
    #define GNICMMIO_FFDUMP     BIT17                   // 0/x/x/x In FIFO test mode, enable dumping sequence to flush sram data out.
    #define GNICMMIO_FIFOTEST   BIT16                   // 0/x/x/x turn on FIFO test mode
    #define GNICMMIO_AITRPKT    BIT13                   // 0/x/x/x A-CAM enable Interesting Packet segment.
    #define GNICMMIO_AITR16     BIT12                   // 0/x/x/x Interesting packet segment in A-CAM size option. Available only while...
    #define GNICMMIO_PCAMBIST   BIT9                    // 0/R/x/x After enable PCAMBISTGO, this bit will show CAMBIST status,  ?1? : su...
    #define GNICMMIO_PCAMBISTGO BIT8                    // 0/0/x/x PCIE set CAMBIST GO
#define GNICMMIO_TX_RX_SRAM_BIST_CTL_AND_STAREG_BCSR 0x80 // Tx/Rx SRAM Bist Control and StatusRegister (BCSR)
    #define GNICMMIO_SWOLTAG    BIT28                   // 0/x/x/x SWOLTAG.Software WOL Tag.
    #define GNICMMIO_STKDS      (BIT24 + BIT25)         // 0/x/x/x STKDS[1:0]
    #define GNICMMIO_DSINI      BIT23                   // 0/R/x/x DSI(RE)
    #define GNICMMIO_D2_DIS     BIT22                   // 0/R/x/x D2_Dis(RE)
    #define GNICMMIO_D1_DIS     BIT21                   // 0/R/x/x D1_Dis(RE)
    #define GNICMMIO_D3C_EN     BIT20                   // 1b/R/x/x D3c_En(RE)
    #define GNICMMIO_D3H_EN     BIT19                   // 0/R/x/x D3h_En(RE)
    #define GNICMMIO_D2_EN      BIT18                   // 0/R/x/x D2_En(RE)
    #define GNICMMIO_D1_EN      BIT17                   // 0/R/x/x D1_En(RE)
    #define GNICMMIO_D0_EN      BIT16                   // 0/R/x/x D0_En(RE)
    #define GNICMMIO_TFOK       BIT11                   // 0/R/x/x TFOK
    #define GNICMMIO_RFOK       BIT10                   // 0/R/x/x RFOK
    #define GNICMMIO_TFDONE     BIT9                    // 0/R/x/x TFDONE
    #define GNICMMIO_RFDONE     BIT8                    // 0/R/x/x RFDONE
    #define GNICMMIO_BITMAP     BIT7                    // 0/x/x/x BITMAP
    #define GNICMMIO_RFBISTGO   BIT6                    // 0/x/x/x RFBISTGO
    #define GNICMMIO_TFBISTGO   BIT5                    // 0/x/x/x TFBISTGO
    #define GNICMMIO_BSERRX     BIT4                    // 0/x/x/x Reserved.
    #define GNICMMIO_BSERTX     BIT3                    // 0/x/x/x Reserved.
    #define GNICMMIO_BISTEN     BIT0                    // 0/x/x/x Reserved
#define GNICMMIO_MIB_CTL_AND_STA_REG_MIBCSR 0x84 // MIB Control and Status Register (MIBCSR)
    #define GNICMMIO_MAINVER    0xF00000    // 1h/R/x/x 4-bit  status to indicate V.GHCI main version part, (Main_ver.x)
    #define GNICMMIO_SUBVER     0xF0000     // 0/R/x/x 4-bit status to indicate V.GHCI sub version part  (x.Sub_ver)
    #define GNICMMIO_SFU        0xFF00      // 0/x/x/x 8 bit EEPROM loaded data. Leave for Software Usage
    #define GNICMMIO_MIBISTOK   BIT7        // 0/R/x/x MIBISTOK(RW0U)
    #define GNICMMIO_MBISTGO    BIT6        // 0/x/x/x MBISTGO
    #define GNICMMIO_MIBINC     BIT5        // 0/x/x/x MIBINC
    #define GNICMMIO_MIBHI      BIT4        // 0/x/x/x MIBHI
    #define GNICMMIO_MIBFREEZE  BIT3        // 1b/x/x/x MIBFREEZE
    #define GNICMMIO_MIBFLUSH   BIT2        // 0/x/x/x MIBFLUSH 
    #define GNICMMIO_MBTRINI    BIT1        // 0/x/x/x MBTRINI
    #define GNICMMIO_MIBCLR     BIT0        // 0/x/x/x MIBCLR 
#define GNICMMIO_MIB_CTL_DATA_AND_ADR_OUTPUT_PORT_REG_MIBDATA 0x88 // MIB Control Data and Address Output Port Register (MIBDATA)
    #define GNICMMIO_MIB_PTR    0xFF000000  // 0/R/x/x MIB_Ptr 
    #define GNICMMIO_MIB_DATA   0xFFFFFF    // 0/R/x/x MIB_Data 
#define GNICMMIO_FLUSH_ROM_CTL_REG_FRCR 0x8C // Flush ROM Control Register (FRCR)
    #define GNICMMIO_BPMD_W     0xFF000000  // 0/x/x/x BPMD_w 
    #define GNICMMIO_FREHA      0xFF0000    // 0/x/x/x Reserved
    #define GNICMMIO_BPMA_15_0  0xFFFF      // 0/x/x/x BPMA[15:0]
#define GNICMMIO_FLUSH_ROM_CTL_AND_STA_REG_FRCSR 0x90 // Flush ROM Control and Status Register (FRCSR)
    #define GNICMMIO_SPIDPM     BIT31       // 0/x/x/x SPIDPM  equal to (bit[31] & !bit[28])
    #define GNICMMIO_EMBP       BIT30       // 0/x/x/x EMBP
    #define GNICMMIO_RELOAD     BIT29       // 0/x/x/x RELOAD
    #define GNICMMIO_DPM        BIT28       // 0/x/x/x DPM
    #define GNICMMIO_ECS        BIT27       // 0/x/x/x ECS
    #define GNICMMIO_ECK        BIT26       // 0/x/x/x ECK
    #define GNICMMIO_EDI        BIT25       // 0/x/x/x EDI
    #define GNICMMIO_EDO        BIT24       // 0/R/x/x EDO
    #define GNICMMIO_EECHKSUM   0xFF0000    // 0/R/x/x EEChkSum.
    #define GNICMMIO_BPMD_R     0xFF00      // 0/R/x/x BPMD_r. 
    #define GNICMMIO_BPDNE      BIT7        // 1b/x/x/x Reserved
#define GNICMMIO_EEPROM_REG_FRCR 0x94 // EEPROM  Register (FRCR)
    #define GNICMMIO_EDONE      BIT31                   // 1b/R/x/x EDONE (RU)
    #define GNICMMIO_EWDIS      BIT27                   // 0/x/x/x EWDIS
    #define GNICMMIO_EWEN       BIT26                   // 0/x/x/x EWEN
    #define GNICMMIO_EWR        BIT25                   // 0/x/x/x EWR
    #define GNICMMIO_ERD        BIT24                   // 0/x/x/x ERD
    #define GNICMMIO_EEADDR_7_0 0xFF0000                // 0/x/x/x EEADDR[7:0] 
    #define GNICMMIO_EE_RD_DATA 0xFFFF                  // 0/R/x/x EE_RD_DATA
#define GNICMMIO_JUMPER_STRAPPING_STA_REG_FRCR 0x98 // Jumper Strapping Status Register (FRCR)
    #define GNICMMIO_GSUSPRZ    BIT15       // 1b/R/x/x Reserved
    #define GNICMMIO_J_EEDIS    BIT13       // 1b/R/x/x J_EEDIS
    #define GNICMMIO_J_EEFAST   BIT11       // 0/R/x/x J_EEFAST
    #define GNICMMIO_J_VEESEL   BIT10       // 0/R/x/x J_VEESEL. 
#define GNICMMIO_CHIP_OPERATION_AND_DIAGNOSE_REG 0x9C // Chip Operation and Diagnose Register
    #define GNICMMIO_FCGMII     BIT31                   // 0/x/x/x FCGMII
    #define GNICMMIO_FCFDX      BIT30                   // 0/x/x/x FCFDX
    #define GNICMMIO_FC10M      BIT29                   // 0/x/x/x FC10M
    #define GNICMMIO_FCMODE     BIT28                   // 0/x/x/x FCMODE
    #define GNICMMIO_TM1US      BIT26                   // 0/x/x/x TM1US    
    #define GNICMMIO_TM0US      BIT25                   // 0/x/x/x TM0US   
    #define GNICMMIO_PHYINTEN   BIT24                   // 0/x/x/x PHYINTEN 
    #define GNICMMIO_MIIDIAG    BIT23                   // 0/x/x/x MIIDIAG
    #define GNICMMIO_MIIPRR     BIT22                   // 0/x/x/x MIIPRR
    #define GNICMMIO_PXEDBG     BIT21                   // 0/x/x/x Reserved
    #define GNICMMIO_PMCDIAG    BIT20                   // 0/x/x/x PMCDIAG
    #define GNICMMIO_FPSTIME    BIT19                   // 0/x/x/x FPSTIME 
    #define GNICMMIO_ACPFRM     BIT18                   // 0/x/x/x ACPFRM  
    #define GNICMMIO_PXE_INTCHK BIT17                   // 0/x/x/x Reserved
    #define GNICMMIO_PXE_INTMER BIT16                   // 0/x/x/x Reserved
    #define GNICMMIO_HBDIS      BIT15                   // 0/x/x/x HBDIS
    #define GNICMMIO_FOCOL      BIT14                   // 0/x/x/x FOCOL  
    #define GNICMMIO_BKOFF      BIT13                   // 0/x/x/x BKOFF
    #define GNICMMIO_PTNCERR    BIT11                   // 0/x/x/x Pattern_check_error  
    #define GNICMMIO_TG_EXTLBK  BIT10                   // 0/x/x/x TG_EXTLBK  
    #define GNICMMIO_RXLNPF     BIT9                    // 0/x/x/x RXLNPF 
    #define GNICMMIO_RXFULL     BIT8                    // 0/x/x/x RXFULL
    #define GNICMMIO_SRAMJBOSZ  (BIT6 + BIT7)           // 0/x/x/x Reserved
    #define GNICMMIO_RTBISTOK   BIT5                    // 0/x/x/x Reserved
    #define GNICMMIO_EEPR       BIT4                    // 0/R/x/x EEPR     
    #define GNICMMIO_PMU10      BIT0                    // 0/x/x/x PMU10   
#define GNICMMIO_WAKE_ON_LAN_EVENT_STA_SET_REG_WOLSR0_S 0xA0 // Wake On Lan Event Status Set Register  (WOLSR0.s)
    #define GNICMMIO_PMEOVR     BIT31   // 0/x/x/x PMEOVR.
    #define GNICMMIO_SAM        BIT29   // 0/x/x/x SAM.
    #define GNICMMIO_SAB        BIT28   // 0/x/x/x SAB.
    #define GNICMMIO_SMIIACC    BIT27   // 0/x/x/x Reserved.
    #define GNICMMIO_DLRSTOPT   BIT26   // 0/x/x/x Reserved.
    #define GNICMMIO_SMIIPLSC   BIT25   // 1b/x/x/x Reserved.
    #define GNICMMIO_PHYEVTEN   BIT24   // 0/x/x/x PHYEVTEN. 
    #define GNICMMIO_PHYPWOPT   BIT23   // 0/x/x/x Reserved.
    #define GNICMMIO_PCISTICK   BIT22   // 0/x/x/x Reserved.
    #define GNICMMIO_WOLTYPE    BIT21   // 0/x/x/x Reserved.
    #define GNICMMIO_LEGCYWOL   BIT20   // 0/x/x/x Reserved.
    #define GNICMMIO_PME_SR     BIT19   // 0/x/x/x PME_SR
    #define GNICMMIO_PME_EN     BIT18   // 0/x/x/x PME_EN
    #define GNICMMIO_LINKOFFEN  BIT11   // 0/x/x/x LinkOffEn.  
    #define GNICMMIO_LINKONEN   BIT10   // 0/x/x/x LinkOnEn.  
    #define GNICMMIO_MAGICEN    BIT9    // 0/x/x/x MagicEn.   
    #define GNICMMIO_UNIQEN     BIT8    // 0/x/x/x UniQEN.    
    #define GNICMMIO_PTNMH7     BIT7    // 0/x/x/x PTNMH7.  
    #define GNICMMIO_PTNMH6     BIT6    // 0/x/x/x PTNMH6.  
    #define GNICMMIO_PTNMH5     BIT5    // 0/x/x/x PTNMH5.  
    #define GNICMMIO_PTNMH4     BIT4    // 0/x/x/x PTNMH4.  
    #define GNICMMIO_PTNMH3     BIT3    // 0/x/x/x PTNMH3.  
    #define GNICMMIO_PTNMH2     BIT2    // 0/x/x/x PTNMH2.  
    #define GNICMMIO_PTNMH1     BIT1    // 0/x/x/x PTNMH1.  
    #define GNICMMIO_PTNMH0     BIT0    // 0/x/x/x PTNMH0.  
#define GNICMMIO_WAKE_ON_LAN_EVENT_STA_CLEAR_REG_WOLSR0_C 0xA4 // Wake On Lan Event Status Clear Register  (WOLSR0.c)
    #define GNICMMIO_PMEOVRB    BIT31   // 0/x/x/x PMEOVR.
    #define GNICMMIO_SAMB       BIT29   // 0/x/x/x SAM.
    #define GNICMMIO_SABB       BIT28   // 0/x/x/x SAB.
    #define GNICMMIO_SMIIACCB   BIT27   // 0/x/x/x Reserved.
    #define GNICMMIO_DLRSTOPTB  BIT26   // 0/x/x/x DLRSTOPT. 
    #define GNICMMIO_SMIIPLSCB  BIT25   // 1b/x/x/x SMIIPLSC   
    #define GNICMMIO_PHYEVTENB  BIT24   // 0/x/x/x PHYEVTEN. 
    #define GNICMMIO_PHYPWOPTB  BIT23   // 0/x/x/x Reserved
    #define GNICMMIO_PCISTICKB  BIT22   // 0/x/x/x PCISTICK.
    #define GNICMMIO_WOLTYPEB   BIT21   // 0/x/x/x WOLTYPE.
    #define GNICMMIO_LEGCYWOLB  BIT20   // 0/x/x/x LEGCYWOL. 
    #define GNICMMIO_PME_SRB    BIT19   // 0/x/x/x PME_SR
    #define GNICMMIO_PME_ENB    BIT18   // 0/x/x/x PME_EN
    #define GNICMMIO_LINKOFFENB BIT11   // 0/x/x/x LinkOffEn.  
    #define GNICMMIO_LINKONENB  BIT10   // 0/x/x/x LinkOnEn.  
    #define GNICMMIO_MAGICENB   BIT9    // 0/x/x/x MagicEn.   
    #define GNICMMIO_UNIQENB    BIT8    // 0/x/x/x UniQEN.    
    #define GNICMMIO_PTNMH7B    BIT7    // 0/x/x/x PTNMH7.  
    #define GNICMMIO_PTNMH6B    BIT6    // 0/x/x/x PTNMH6.  
    #define GNICMMIO_PTNMH5B    BIT5    // 0/x/x/x PTNMH5.  
    #define GNICMMIO_PTNMH4B    BIT4    // 0/x/x/x PTNMH4.  
    #define GNICMMIO_PTNMH3B    BIT3    // 0/x/x/x PTNMH3.  
    #define GNICMMIO_PTNMH2B    BIT2    // 0/x/x/x PTNMH2.  
    #define GNICMMIO_PTNMH1B    BIT1    // 0/x/x/x PTNMH1.  
    #define GNICMMIO_PTNMH0B    BIT0    // 0/x/x/x PTNMH0.  
#define GNICMMIO_WAKE_ON_LAN_EVENT_STA_CTL_REG 0xA8 // Wake-On-Lan Event Status Control Register
    #define GNICMMIO_LINKOFFINT BIT11       // 0/x/x/x WOL event detected for link on to link fail
    #define GNICMMIO_LINKONINT  BIT10       // 0/x/x/x WOL event detected for link fail to link on
    #define GNICMMIO_MAGNICINT  BIT9        // 0/x/x/x WOL event detected for magic packet
    #define GNICMMIO_UNIQENINT  BIT8        // 0/x/x/x WOL event detected for receiving an unicast packet with recognized Et...
    #define GNICMMIO_PTNMH7INT  BIT7        // 0/x/x/x WOL event detected of Patten Match, pattern #7
    #define GNICMMIO_PTNMH6INT  BIT6        // 0/x/x/x WOL event detected of Patten Match, pattern #6
    #define GNICMMIO_PTNMH5INT  BIT5        // 0/x/x/x WOL event detected of Patten Match, pattern #5
    #define GNICMMIO_PTNMH4INT  BIT4        // 0/x/x/x WOL event detected of Patten Match, pattern #4
    #define GNICMMIO_PTNMH3INT  BIT3        // 0/x/x/x WOL event detected of Patten Match, pattern #3
    #define GNICMMIO_PTNMH2INT  BIT2        // 0/x/x/x WOL event detected of Patten Match, pattern #2
    #define GNICMMIO_PTNMH1INT  BIT1        // 0/x/x/x WOL event detected of Patten Match, pattern #1
    #define GNICMMIO_PTNMH0INT  BIT0        // 0/x/x/x WOL event detected of Patten Match, pattern #0
#define GNICMMIO_WAKE_ON_LAN_EVENT_STA_CTL_CLEAR_REG 0xAC // Wake-On-Lan Event Status Control Clear Register
    #define GNICMMIO_LINKOFFINTB    BIT11       // 0/x/x/x WOL event detected for link on to link fail
    #define GNICMMIO_LINKONINTB     BIT10       // 0/x/x/x WOL event detected for link fail to link on
    #define GNICMMIO_MAGNICINTB     BIT9        // 0/x/x/x WOL event detected for magic packet
    #define GNICMMIO_UNIQENINTB     BIT8        // 0/x/x/x WOL event detected for receiving an unicast packet with recognized Et...
    #define GNICMMIO_PTNMH7INTB     BIT7        // 0/x/x/x WOL event detected of Patten Match, pattern #7
    #define GNICMMIO_PTNMH6INTB     BIT6        // 0/x/x/x WOL event detected of Patten Match, pattern #6
    #define GNICMMIO_PTNMH5INTB     BIT5        // 0/x/x/x WOL event detected of Patten Match, pattern #5
    #define GNICMMIO_PTNMH4INTB     BIT4        // 0/x/x/x WOL event detected of Patten Match, pattern #4
    #define GNICMMIO_PTNMH3INTB     BIT3        // 0/x/x/x WOL event detected of Patten Match, pattern #3
    #define GNICMMIO_PTNMH2INTB     BIT2        // 0/x/x/x WOL event detected of Patten Match, pattern #2
    #define GNICMMIO_PTNMH1INTB     BIT1        // 0/x/x/x WOL event detected of Patten Match, pattern #1
    #define GNICMMIO_PTNMH0INTB     BIT0        // 0/x/x/x WOL event detected of Patten Match, pattern #0
#define GNICMMIO_GRPS_OF_16_BITS_CRC_REG0 0xB0 // Groups of 16-bits CRC Register0
    #define GNICMMIO_PMGCRC1    0xFFFF0000  // ffffh/x/x/x Pattern Match Group 1 CRC16 value
    #define GNICMMIO_PMGCRC0    0xFFFF      // ffffh/x/x/x Pattern Match Group 0 CRC16 value
#define GNICMMIO_GRPS_OF_16_BITS_CRC_REG1 0xB4 // Groups of 16-bits CRC Register1
    #define GNICMMIO_PMGCRC3    0xFFFF0000  // ffffh/x/x/x Pattern Match Group 3 CRC16 value
    #define GNICMMIO_PMGCRC2    0xFFFF      // ffffh/x/x/x Pattern Match Group 2 CRC16 value
#define GNICMMIO_GRPS_OF_16_BITS_CRC_REG2 0xB8 // Groups of 16-bits CRC Register2
    #define GNICMMIO_PMGCRC5    0xFFFF0000  // ffffh/x/x/x Pattern Match Group 5 CRC16 value
    #define GNICMMIO_PMGCRC4    0xFFFF      // ffffh/x/x/x Pattern Match Group 4 CRC16 value
#define GNICMMIO_GRPS_OF_16_BITS_CRC_REG3 0xBC // Groups of 16-bits CRC Register3
    #define GNICMMIO_PMGCRC7    0xFFFF0000  // ffffh/x/x/x Pattern Match Group 7 CRC16 value
    #define GNICMMIO_PMGCRC6    0xFFFF      // ffffh/x/x/x Pattern Match Group 6 CRC16 value
#define GNICMMIO_INTR_MODERATION_EXTREME_LEVEL_REG 0x108 // Interrupt Moderation Extreme Level Register
    #define GNICMMIO_MTEXT GNICMMIO_INTR_MODERATION_EXTREME_LEVEL_REG // 0/x/x/x MIB Traffic Extreme Threshold
#define GNICMMIO_INTR_MODERATION_HIGH_LEVEL_REG 0x10C // Interrupt Moderation High Level Register
    #define GNICMMIO_MTHIG GNICMMIO_INTR_MODERATION_HIGH_LEVEL_REG // 0/x/x/x MIB Traffic High Threshold
#define GNICMMIO_INTR_MODERATION_LOW_LEVEL_REG 0x110 // Interrupt Moderation Low Level Register
    #define GNICMMIO_MTLOW GNICMMIO_INTR_MODERATION_LOW_LEVEL_REG // 0/x/x/x MIB Traffic Low Threshold
#define GNICMMIO_INTR_MODERATION_MINIMAL_LEVEL_REG 0x114 // Interrupt Moderation Minimal Level Register
    #define GNICMMIO_MTMIN GNICMMIO_INTR_MODERATION_MINIMAL_LEVEL_REG // 0/x/x/x MIB Traffic Minimal Threshold
#define GNICMMIO_TSUPPTHR_THRESHOLD_REG0 0x118 // TSUPPTHR Threshold Register0
    #define GNICMMIO_TSUEXT 0xFF000000  // 0/x/x/x TSUPPTHR Extreme Threshold
    #define GNICMMIO_TSUHIG 0xFF0000    // 0/x/x/x TSUPPTHR High Threshold
    #define GNICMMIO_TSUMED 0xFF00      // 0/x/x/x TSUPPTHR Medium Threshold
    #define GNICMMIO_TSULOW 0xFF        // 0/x/x/x TSUPPTHR Low Threshold
#define GNICMMIO_TSUPPTHR_THRESHOLD_REG1 0x11C // TSUPPTHR Threshold Register1
    #define GNICMMIO_TSUMIN 0xFF        // 0/x/x/x TSUPPTHR Minimal Threshold
#define GNICMMIO_RSUPPTHR_THRESHOLD_REG0 0x120 // RSUPPTHR Threshold Register0
    #define GNICMMIO_RSUEXT 0xFF000000  // 0/x/x/x RSUPPTHR Extreme Threshold
    #define GNICMMIO_RSUHIG 0xFF0000    // 0/x/x/x RSUPPTHR High Threshold
    #define GNICMMIO_RSUMED 0xFF00      // 0/x/x/x RSUPPTHR Medium Threshold
    #define GNICMMIO_RSULOW 0xFF        // 0/x/x/x RSUPPTHR Low Threshold
#define GNICMMIO_RSUPPTHR_THRESHOLD_REG1 0x124 // RSUPPTHR Threshold Register1
    #define GNICMMIO_RSUMIN 0xFF        // 0/x/x/x RSUPPTHR Minimal Threshold
#define GNICMMIO_INTR_MODERATION_TIMER_VALUE_CFG_REG 0x128 // Interrupt Moderation Timer Value Config Register
    #define GNICMMIO_INTMTIM GNICMMIO_INTR_MODERATION_TIMER_VALUE_CFG_REG // 0/x/x/x Interrupt Moderation timer value config register
#define GNICMMIO_RECEIVE_SIDE_SCALING_CMD_REG 0x12C // Receive Side Scaling Command Register
    #define GNICMMIO_MRQE   (BIT30 + BIT31)         // 0/R/x/x Receive Side Scaling Function Enable
    #define GNICMMIO_HFTP   0x3FF00000              // 0/R/x/x The usage of Hash Functions could be controlled by these bits. If set...
    #define GNICMMIO_ITI    (BIT13 + BIT14 + BIT15) // 0/R/x/x Indirection Table Index
#define GNICMMIO_INDIRECTION_TABLE_REG0 0x130 // Indirection Table Register0
    #define GNICMMIO_ENTRY3 (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY2 (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY1 (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY0 (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG1 0x134 // Indirection Table Register1
    #define GNICMMIO_ENTRY7 (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY6 (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY5 (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY4 (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG2 0x138 // Indirection Table Register2
    #define GNICMMIO_ENTRY11    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY10    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY9     (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY8     (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG3 0x13C // Indirection Table Register3
    #define GNICMMIO_ENTRY15    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY14    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY13    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY12    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG4 0x140 // Indirection Table Register4
    #define GNICMMIO_ENTRY19    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY18    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY17    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY16    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG5 0x144 // Indirection Table Register5
    #define GNICMMIO_ENTRY23    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY22    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY21    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY20    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG6 0x148 // Indirection Table Register6
    #define GNICMMIO_ENTRY27    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY26    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY25    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY24    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG7 0x14C // Indirection Table Register7
    #define GNICMMIO_ENTRY31    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY30    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY29    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY28    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG8 0x150 // Indirection Table Register8
    #define GNICMMIO_ENTRY35    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY34    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY33    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY32    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG9 0x154 // Indirection Table Register9
    #define GNICMMIO_ENTRY39    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY38    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY37    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY36    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG10 0x158 // Indirection Table Register10
    #define GNICMMIO_ENTRY43    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY42    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY41    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY40    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG11 0x15C // Indirection Table Register11
    #define GNICMMIO_ENTRY47    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY46    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY45    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY44    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG12 0x160 // Indirection Table Register12
    #define GNICMMIO_ENTRY51    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY50    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY49    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY48    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG13 0x164 // Indirection Table Register13
    #define GNICMMIO_ENTRY55    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY54    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY53    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY52    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG14 0x168 // Indirection Table Register14
    #define GNICMMIO_ENTRY59    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY58    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY57    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY56    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG15 0x16C // Indirection Table Register15
    #define GNICMMIO_ENTRY63    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY62    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY61    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY60    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG16 0x170 // Indirection Table Register16
    #define GNICMMIO_ENTRY67    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY66    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY65    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY64    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG17 0x174 // Indirection Table Register17
    #define GNICMMIO_ENTRY71    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY70    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY69    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY68    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG18 0x178 // Indirection Table Register18
    #define GNICMMIO_ENTRY75    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY74    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY73    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY72    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG19 0x17C // Indirection Table Register19
    #define GNICMMIO_ENTRY79    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY78    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY77    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY76    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG20 0x180 // Indirection Table Register20
    #define GNICMMIO_ENTRY83    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY82    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY81    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY80    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG21 0x184 // Indirection Table Register21
    #define GNICMMIO_ENTRY87    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY86    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY85    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY84    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG22 0x188 // Indirection Table Register22
    #define GNICMMIO_ENTRY91    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY90    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY89    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY88    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG23 0x18C // Indirection Table Register23
    #define GNICMMIO_ENTRY95    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY94    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY93    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY92    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG24 0x190 // Indirection Table Register24
    #define GNICMMIO_ENTRY99    (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY98    (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY97    (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY96    (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG25 0x194 // Indirection Table Register25
    #define GNICMMIO_ENTRY103   (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY102   (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY101   (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY100   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG26 0x198 // Indirection Table Register26
    #define GNICMMIO_ENTRY107   (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY106   (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY105   (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY104   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG27 0x19C // Indirection Table Register27
    #define GNICMMIO_ENTRY111   (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY110   (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY109   (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY108   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG28 0x1A0 // Indirection Table Register28
    #define GNICMMIO_ENTRY115   (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY114   (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY113   (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY112   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG29 0x1A4 // Indirection Table Register29
    #define GNICMMIO_ENTRY119   (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY118   (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY117   (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY116   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG30 0x1A8 // Indirection Table Register30
    #define GNICMMIO_ENTRY123   (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY122   (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY121   (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY120   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_INDIRECTION_TABLE_REG31 0x1AC // Indirection Table Register31
    #define GNICMMIO_ENTRY127   (BIT24 + BIT25 + BIT26) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY126   (BIT16 + BIT17 + BIT18) // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY125   (BIT8 + BIT9 + BIT10)   // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
    #define GNICMMIO_ENTRY124   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Determines physical queue index n (n = 0,1,2,3,4,5,6,7)
#define GNICMMIO_RSS_RANDOM_KEY_REG0 0x1B0 // RSS Random Key Register0
    #define GNICMMIO_RSSK_B3    0xFF000000  // DAh/R/x/x Receive Side Scaling Random Key K[3]
    #define GNICMMIO_RSSK_B2    0xFF0000    // 56h/R/x/x Receive Side Scaling Random Key K[2]
    #define GNICMMIO_RSSK_B1    0xFF00      // 5Ah/R/x/x Receive Side Scaling Random Key K[1]
    #define GNICMMIO_RSSK_B0    0xFF        // 6Dh/R/x/x Receive Side Scaling Random Key K[0]
#define GNICMMIO_RSS_RANDOM_KEY_REG1 0x1B4 // RSS Random Key Register1
    #define GNICMMIO_RSSK_B7    0xFF000000  // C2 h/R/x/x Receive Side Scaling Random Key K[7]
    #define GNICMMIO_RSSK_B6    0xFF0000    // 0Eh/R/x/x Receive Side Scaling Random Key K[6]
    #define GNICMMIO_RSSK_B5    0xFF00      // 5Bh/R/x/x Receive Side Scaling Random Key K[5]
    #define GNICMMIO_RSSK_B4    0xFF        // 25h/R/x/x Receive Side Scaling Random Key K[4]
#define GNICMMIO_RSS_RANDOM_KEY_REG2 0x1B8 // RSS Random Key Register2
    #define GNICMMIO_RSSK_B11   0xFF000000  // 3Dh/R/x/x Receive Side Scaling Random Key K[11]
    #define GNICMMIO_RSSK_B10   0xFF0000    // 25h/R/x/x Receive Side Scaling Random Key K[10]
    #define GNICMMIO_RSSK_B9    0xFF00      // 67h/R/x/x Receive Side Scaling Random Key K[9]
    #define GNICMMIO_RSSK_B8    0xFF        // 41h/R/x/x Receive Side Scaling Random Key K[8]
#define GNICMMIO_RSS_RANDOM_KEY_REG3 0x1BC // RSS Random Key Register3
    #define GNICMMIO_RSSK_B15   0xFF000000  // B0h/R/x/x Receive Side Scaling Random Key K[15]
    #define GNICMMIO_RSSK_B14   0xFF0000    // 8Fh/R/x/x Receive Side Scaling Random Key K[14]
    #define GNICMMIO_RSSK_B13   0xFF00      // A3h/R/x/x Receive Side Scaling Random Key K[13]
    #define GNICMMIO_RSSK_B12   0xFF        // 43h/R/x/x Receive Side Scaling Random Key K[12]
#define GNICMMIO_RSS_RANDOM_KEY_REG4 0x1C0 // RSS Random Key Register4
    #define GNICMMIO_RSSK_B19   0xFF000000  // CBh/R/x/x Receive Side Scaling Random Key K[19]
    #define GNICMMIO_RSSK_B18   0xFF0000    // 2Bh/R/x/x Receive Side Scaling Random Key K[18]
    #define GNICMMIO_RSSK_B17   0xFF00      // CAh/R/x/x Receive Side Scaling Random Key K[17]
    #define GNICMMIO_RSSK_B16   0xFF        // D0h/R/x/x Receive Side Scaling Random Key K[16]
#define GNICMMIO_RSS_RANDOM_KEY_REG5 0x1C4 // RSS Random Key Register5
    #define GNICMMIO_RSSK_B23   0xFF000000  // B4h/R/x/x Receive Side Scaling Random Key K[23]
    #define GNICMMIO_RSSK_B22   0xFF0000    // 30h/R/x/x Receive Side Scaling Random Key K[22]
    #define GNICMMIO_RSSK_B21   0xFF00      // 7Bh/R/x/x Receive Side Scaling Random Key K[21]
    #define GNICMMIO_RSSK_B20   0xFF        // AEh/R/x/x Receive Side Scaling Random Key K[20]
#define GNICMMIO_RSS_RANDOM_KEY_REG6 0x1C8 // RSS Random Key Register6
    #define GNICMMIO_RSSK_B27   0xFF000000  // A3h/R/x/x Receive Side Scaling Random Key K[27]
    #define GNICMMIO_RSSK_B26   0xFF0000    // 2Dh/R/x/x Receive Side Scaling Random Key K[26]
    #define GNICMMIO_RSSK_B25   0xFF00      // CBh/R/x/x Receive Side Scaling Random Key K[25]
    #define GNICMMIO_RSSK_B24   0xFF        // 77h/R/x/x Receive Side Scaling Random Key K[24]
#define GNICMMIO_RSS_RANDOM_KEY_REG7 0x1CC // RSS Random Key Register7
    #define GNICMMIO_RSSK_B31   0xFF000000  // 0Ch/R/x/x Receive Side Scaling Random Key K[31]
    #define GNICMMIO_RSSK_B30   0xFF0000    // F2h/R/x/x Receive Side Scaling Random Key K[30]
    #define GNICMMIO_RSSK_B29   0xFF00      // 30h/R/x/x Receive Side Scaling Random Key K[29]
    #define GNICMMIO_RSSK_B28   0xFF        // 80h/R/x/x Receive Side Scaling Random Key K[28]
#define GNICMMIO_RSS_RANDOM_KEY_REG8 0x1D0 // RSS Random Key Register8
    #define GNICMMIO_RSSK_B35   0xFF000000  // 3Bh/R/x/x Receive Side Scaling Random Key K[35]
    #define GNICMMIO_RSSK_B34   0xFF0000    // B7h/R/x/x Receive Side Scaling Random Key K[34]
    #define GNICMMIO_RSSK_B33   0xFF00      // 42h/R/x/x Receive Side Scaling Random Key K[33]
    #define GNICMMIO_RSSK_B32   0xFF        // 6Ah/R/x/x Receive Side Scaling Random Key K[32]
#define GNICMMIO_RSS_RANDOM_KEY_REG9 0x1D4 // RSS Random Key Register9
    #define GNICMMIO_RSSK_B39   0xFF000000  // FAh/R/x/x Receive Side Scaling Random Key K[39]
    #define GNICMMIO_RSSK_B38   0xFF0000    // 01h/R/x/x Receive Side Scaling Random Key K[38]
    #define GNICMMIO_RSSK_B37   0xFF00      // ACh/R/x/x Receive Side Scaling Random Key K[37]
    #define GNICMMIO_RSSK_B36   0xFF        // BEh/R/x/x Receive Side Scaling Random Key K[36]
#define GNICMMIO_RX_DESCRIPTOR_INDEX_REG_RX1INDX_RX0INDX 0x1D8 // Rx Descriptor Index Register(RX1INDX RX0INDX)
    #define GNICMMIO_RD1INDX    0xFFFF0000  // 0/x/x/x RD1 index, it will cross top while reach the RDCSIZE defined in offse...
    #define GNICMMIO_RD0INDX    0xFFFF      // 0/x/x/x RD0 index, it will cross top while reach the RDCSIZE defined in offse...
#define GNICMMIO_RX_DESCRIPTOR_INDEX_REG_RX3INDX_RX2INDX 0x1DC // Rx Descriptor Index Register(RX3INDX RX2INDX)
    #define GNICMMIO_RD3INDX    0xFFFF0000  // 0/x/x/x RD3 index, it will cross top while reach the RDCSIZE defined in offse...
    #define GNICMMIO_RD2INDX    0xFFFF      // 0/x/x/x RD2 index, it will cross top while reach the RDCSIZE defined in offse...
#define GNICMMIO_RX_DESCRIPTOR_INDEX_REG_RX5INDX_RX4INDX 0x1E0 // Rx Descriptor Index Register(RX5INDX RX4INDX)
    #define GNICMMIO_RD5INDX    0xFFFF0000  // 0/x/x/x RD5 index, it will cross top while reach the RDCSIZE defined in offse...
    #define GNICMMIO_RD4INDX    0xFFFF      // 0/x/x/x RD4 index, it will cross top while reach the RDCSIZE defined in offse...
#define GNICMMIO_RX_DESCRIPTOR_INDEX_REG_RX7INDX_RX6INDX 0x1E4 // Rx Descriptor Index Register(RX7INDX RX6INDX)
    #define GNICMMIO_RD7INDX    0xFFFF0000  // 0/x/x/x RD7 index, it will cross top while reach the RDCSIZE defined in offse...
    #define GNICMMIO_RD6INDX    0xFFFF      // 0/x/x/x RD6 index, it will cross top while reach the RDCSIZE defined in offse...
#define GNICMMIO_NEW_FEATURE_OPTION_REG 0x1E8 // New Feature Option Register
    #define GNICMMIO_MSI1E1R    BIT31   // 0/*0/x/x MSI one event one request function enable
    #define GNICMMIO_MSIPC      BIT30   // 0/*/x/x MSI pending bit clear after sending enable
    #define GNICMMIO_INTMOD     BIT29   // 0/*/x/x New Interrupt Moderation enable
    #define GNICMMIO_TXQEDIS    BIT28   // 0/0/x/x TX TDQEISET control bit, TX queue interrupt disable.
    #define GNICMMIO_RXQEDIS    BIT27   // 0/0/x/x RX RDQEISET control bit, RX queue interrupt disable.
    #define GNICMMIO_AUTOPAD    BIT26   // 1b/1/x/x Auto Padding enable bit, 
    #define GNICMMIO_VTAGCLR    BIT25   // 0/0/x/x VLAN tag clear by each packet.
    #define GNICMMIO_VTAGPD     BIT24   // 0/x/x/x VLAN priority DO NOT clear RD pending timer control.
    #define GNICMMIO_PXRIXEN    BIT23   // 0/x/x/x prxix_opt.
    #define GNICMMIO_LENTPEN    BIT22   // 0/x/x/x len_tp_en.
    #define GNICMMIO_TRFABTO    BIT21   // 0/x/x/x trfabt_opt.
    #define GNICMMIO_V4UDPRV    BIT20   // 0/x/x/x v4udp_rv.
#define GNICMMIO_RX_QUEUE_0_7_DESCRIPTOR_CTL_STA_REG_RDCSR 0x1EC // Rx Queue 0~7 Descriptor Control Status Register(RDCSR)
    #define GNICMMIO_R7DEAD BIT31   // 0/0/x/x Indicate RD queue#7 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R7WAK  BIT30   // 0/x/x/x Wake RD queue#7 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R7ACK  BIT29   // 0/x/x/x Indicate RD queue#7 list end has not been reached when processing des...
    #define GNICMMIO_R7RUN  BIT28   // 0/x/x/x Enable RD queue#7 to operate (set and reset by SW)
    #define GNICMMIO_R6DEAD BIT27   // 0/0/x/x Indicate RD queue#6 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R6WAK  BIT26   // 0/x/x/x Wake RD queue#6 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R6ACK  BIT25   // 0/x/x/x Indicate RD queue#6 list end has not been reached when processing des...
    #define GNICMMIO_R6RUN  BIT24   // 0/x/x/x Enable RD queue#6 to operate (set and reset by SW)
    #define GNICMMIO_R5DEAD BIT23   // 0/0/x/x Indicate RD queue#5 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R5WAK  BIT22   // 0/x/x/x Wake RD queue#5 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R5ACK  BIT21   // 0/x/x/x Indicate RD queue#5 list end has not been reached when processing des...
    #define GNICMMIO_R5RUN  BIT20   // 0/x/x/x Enable RD queue#5 to operate (set and reset by SW)
    #define GNICMMIO_R4DEAD BIT19   // 0/0/x/x Indicate RD queue#4 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R4WAK  BIT18   // 0/x/x/x Wake RD queue#4 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R4ACK  BIT17   // 0/x/x/x Indicate RD queue#4 list end has not been reached when processing des...
    #define GNICMMIO_R4RUN  BIT16   // 0/x/x/x Enable RD queue#4 to operate (set and reset by SW)
    #define GNICMMIO_R3DEAD BIT15   // 0/0/x/x Indicate RD queue#3 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R3WAK  BIT14   // 0/x/x/x Wake RD queue#3 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R3ACK  BIT13   // 0/x/x/x Indicate RD queue#3 list end has not been reached when processing des...
    #define GNICMMIO_R3RUN  BIT12   // 0/x/x/x Enable RD queue#3 to operate (set and reset by SW)
    #define GNICMMIO_R2DEAD BIT11   // 0/0/x/x Indicate RD queue#2 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R2WAK  BIT10   // 0/x/x/x Wake RD queue#2 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R2ACK  BIT9    // 0/x/x/x Indicate RD queue#2 list end has not been reached when processing des...
    #define GNICMMIO_R2RUN  BIT8    // 0/x/x/x Enable RD queue#2 to operate (set and reset by SW)
    #define GNICMMIO_R1DEAD BIT7    // 0/0/x/x Indicate RD queue#1 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R1WAK  BIT6    // 0/x/x/x Wake RD queue#1 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R1ACK  BIT5    // 0/x/x/x Indicate RD queue#1 list end has not been reached when processing des...
    #define GNICMMIO_R1RUN  BIT4    // 0/x/x/x Enable RD queue#1 to operate (set and reset by SW)
    #define GNICMMIO_R0DEAD BIT3    // 0/0/x/x Indicate RD queue#0 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R0WAK  BIT2    // 0/x/x/x Wake RD queue#0 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R0ACK  BIT1    // 0/x/x/x Indicate RD queue#0 list end has not been reached when processing des...
    #define GNICMMIO_R0RUN  BIT0    // 0/x/x/x Enable RD queue#0 to operate (set and reset by SW)
#define GNICMMIO_RX_QUEUE_0_7_DESCRIPTOR_CTL_STA_CLEAR_REG_RDCSRC 0x1F0 // Rx Queue 0~7 Descriptor Control Status Clear Register(RDCSRc)
    #define GNICMMIO_R7DEADC    BIT31   // 0/x/x/x Indicate RD queue#7 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R7WAKC     BIT30   // 0/x/x/x Wake RD queue#7 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R7ACKC     BIT29   // 0/x/x/x Indicate RD queue#7 list end has not been reached when processing des...
    #define GNICMMIO_R7RUNC     BIT28   // 0/x/x/x Enable RD queue#7 to operate (set and reset by SW) , It is to clear t...
    #define GNICMMIO_R6DEADC    BIT27   // 0/x/x/x Indicate RD queue#6 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R6WAKC     BIT26   // 0/x/x/x Wake RD queue#6 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R6ACKC     BIT25   // 0/x/x/x Indicate RD queue#6 list end has not been reached when processing des...
    #define GNICMMIO_R6RUNC     BIT24   // 0/x/x/x Enable RD queue#6 to operate (set and reset by SW) , It is to clear t...
    #define GNICMMIO_R5DEADC    BIT23   // 0/x/x/x Indicate RD queue#5 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R5WAKC     BIT22   // 0/x/x/x Wake RD queue#5 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R5ACKC     BIT21   // 0/x/x/x Indicate RD queue#5 list end has not been reached when processing des...
    #define GNICMMIO_R5RUNC     BIT20   // 0/x/x/x Enable RD queue#5 to operate (set and reset by SW) , It is to clear t...
    #define GNICMMIO_R4DEADC    BIT19   // 0/x/x/x Indicate RD queue#4 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R4WAKC     BIT18   // 0/x/x/x Wake RD queue#4 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R4ACKC     BIT17   // 0/x/x/x Indicate RD queue#4 list end has not been reached when processing des...
    #define GNICMMIO_R4RUNC     BIT16   // 0/x/x/x Enable RD queue#4 to operate (set and reset by SW) , It is to clear t...
    #define GNICMMIO_R3DEADC    BIT15   // 0/x/x/x Indicate RD queue#3 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R3WAKC     BIT14   // 0/x/x/x Wake RD queue#3 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R3ACKC     BIT13   // 0/x/x/x Indicate RD queue#3 list end has not been reached when processing des...
    #define GNICMMIO_R3RUNC     BIT12   // 0/x/x/x Enable RD queue#3 to operate (set and reset by SW) , It is to clear t...
    #define GNICMMIO_R2DEADC    BIT11   // 0/x/x/x Indicate RD queue#2 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R2WAKC     BIT10   // 0/x/x/x Wake RD queue#2 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R2ACKC     BIT9    // 0/x/x/x Indicate RD queue#2 list end has not been reached when processing des...
    #define GNICMMIO_R2RUNC     BIT8    // 0/x/x/x Enable RD queue#2 to operate (set and reset by SW) , It is to clear t...
    #define GNICMMIO_R1DEADC    BIT7    // 0/x/x/x Indicate RD queue#1 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R1WAKC     BIT6    // 0/x/x/x Wake RD queue#1 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R1ACKC     BIT5    // 0/x/x/x Indicate RD queue#1 list end has not been reached when processing des...
    #define GNICMMIO_R1RUNC     BIT4    // 0/x/x/x Enable RD queue#1 to operate (set and reset by SW) , It is to clear t...
    #define GNICMMIO_R0DEADC    BIT3    // 0/x/x/x Indicate RD queue#0 encounters error conditions. (set by HW, reset by...
    #define GNICMMIO_R0WAKC     BIT2    // 0/x/x/x Wake RD queue#0 to see if there is unprocessed descriptor (set by SW,...
    #define GNICMMIO_R0ACKC     BIT1    // 0/x/x/x Indicate RD queue#0 list end has not been reached when processing des...
    #define GNICMMIO_R0RUNC     BIT0    // 0/x/x/x Enable RD queue#0 to operate (set and reset by SW), It is to clear th...
#define GNICMMIO_RX_QUEUE_0DESCRIPTOR_BASE_ADR_LOW_REG_RXDSBASE_LO 0x1F4 // Rx Queue#0Descriptor Base Address Low Register(RxDsBase.Lo)
    #define GNICMMIO_RX0DSBASELO    0xFFFFFFC0  // 0/x/x/x RD queue#0 base address low. (RxDsBase.Lo[31:6])
#define GNICMMIO_RX_QUEUE_1DESCRIPTOR_BASE_ADR_LOW_REG_RXDSBASE_LO 0x1F8 // Rx Queue#1Descriptor Base Address Low Register(RxDsBase.Lo)
    #define GNICMMIO_RX1DSBASELO    0xFFFFFFC0  // 0/x/x/x RD queue#1 base address low. (RxDsBase.Lo[31:6])
#define GNICMMIO_RX_QUEUE_2DESCRIPTOR_BASE_ADR_LOW_REG_RXDSBASE_LO 0x1FC // Rx Queue#2Descriptor Base Address Low Register(RxDsBase.Lo)
    #define GNICMMIO_RX2DSBASELO    0xFFFFFFC0  // 0/x/x/x RD queue#2 base address low. (RxDsBase.Lo[31:6])
#define GNICMMIO_RX_QUEUE_3DESCRIPTOR_BASE_ADR_LOW_REG_RXDSBASE_LO 0x200 // Rx Queue#3Descriptor Base Address Low Register(RxDsBase.Lo)
    #define GNICMMIO_RX3DSBASELO    0xFFFFFFC0  // 0/x/x/x RD queue#3 base address low. (RxDsBase.Lo[31:6])
#define GNICMMIO_RX_QUEUE_4DESCRIPTOR_BASE_ADR_LOW_REG_RXDSBASE_LO 0x204 // Rx Queue#4Descriptor Base Address Low Register(RxDsBase.Lo)
    #define GNICMMIO_RX4DSBASELO    0xFFFFFFC0  // 0/x/x/x RD queue#4 base address low. (RxDsBase.Lo[31:6])
#define GNICMMIO_RX_QUEUE_5DESCRIPTOR_BASE_ADR_LOW_REG_RXDSBASE_LO 0x208 // Rx Queue#5Descriptor Base Address Low Register(RxDsBase.Lo)
    #define GNICMMIO_RX5DSBASELO    0xFFFFFFC0  // 0/x/x/x RD queue#5 base address low. (RxDsBase.Lo[31:6])
#define GNICMMIO_RX_QUEUE_6DESCRIPTOR_BASE_ADR_LOW_REG_RXDSBASE_LO 0x20C // Rx Queue#6Descriptor Base Address Low Register(RxDsBase.Lo)
    #define GNICMMIO_RX6DSBASELO    0xFFFFFFC0  // 0/x/x/x RD queue#6 base address low. (RxDsBase.Lo[31:6])
#define GNICMMIO_RX_QUEUE_7DESCRIPTOR_BASE_ADR_LOW_REG_RXDSBASE_LO 0x210 // Rx Queue#7Descriptor Base Address Low Register(RxDsBase.Lo)
    #define GNICMMIO_RX7DSBASELO    0xFFFFFFC0  // 0/x/x/x RD queue#7 base address low. (RxDsBase.Lo[31:6])
#define GNICMMIO_RX_DESCRIPTOR_1_0_REG_RD_1_0_SIZE 0x214 // Rx Descriptor 1,0 Register (RD 1/0 Size)
    #define GNICMMIO_RD1CSIZE   0xFFFF0000  // 0/x/x/x RD queue#1  list length
    #define GNICMMIO_RD0CSIZE   0xFFFF      // 0/x/x/x RD queue#0  list length
#define GNICMMIO_RX_DESCRIPTOR_3_2_REG_RD_3_2_SIZE 0x218 // Rx Descriptor 3,2 Register (RD 3/2 Size)
    #define GNICMMIO_RD3CSIZE   0xFFFF0000  // 0/x/x/x RD queue#3  list length
    #define GNICMMIO_RD2CSIZE   0xFFFF      // 0/x/x/x RD queue#2  list length
#define GNICMMIO_RX_DESCRIPTOR_5_4_REG_RD_5_4_SIZE 0x21C // Rx Descriptor 5,4 Register (RD 5/4 Size)
    #define GNICMMIO_RD5CSIZE   0xFFFF0000  // 0/x/x/x RD queue#5  list length
    #define GNICMMIO_RD4CSIZE   0xFFFF      // 0/x/x/x RD queue#4  list length
#define GNICMMIO_RX_DESCRIPTOR_7_6_REG_RD_7_6_SIZE 0x220 // Rx Descriptor 7,6 Register (RD 7/6 Size)
    #define GNICMMIO_RD7CSIZE   0xFFFF0000  // 0/x/x/x RD queue#7  list length
    #define GNICMMIO_RD6CSIZE   0xFFFF      // 0/x/x/x RD queue#6  list length
#define GNICMMIO_RX_QUEUE_1_0_DESCRIPTOR_RESIDUE_CNT_REG 0x224 // Rx Queue #1,0 Descriptor Residue Count Register
    #define GNICMMIO_R1BRDU 0xFFFF0000  // 0/x/x/x Rx Queue#1 Descriptor buffer residue counts.
    #define GNICMMIO_R0BRDU 0xFFFF      // 0/x/x/x Rx Queue#0 Descriptor buffer residue counts.
#define GNICMMIO_RX_QUEUE_3_2_DESCRIPTOR_RESIDUE_CNT_REG 0x228 // Rx Queue #3,2 Descriptor Residue Count Register
    #define GNICMMIO_R3BRDU 0xFFFF0000  // 0/x/x/x Rx Queue#3 Descriptor buffer residue counts.
    #define GNICMMIO_R2BRDU 0xFFFF      // 0/x/x/x Rx Queue#2 Descriptor buffer residue counts.
#define GNICMMIO_RX_QUEUE_5_4_DESCRIPTOR_RESIDUE_CNT_REG 0x22C // Rx Queue #5,4 Descriptor Residue Count Register
    #define GNICMMIO_R5BRDU 0xFFFF0000  // 0/x/x/x Rx Queue5 Descriptor buffer residue counts.
    #define GNICMMIO_R4BRDU 0xFFFF      // 0/x/x/x Rx Queue#4 Descriptor buffer residue counts.
#define GNICMMIO_RX_QUEUE_7_6_DESCRIPTOR_RESIDUE_CNT_REG 0x230 // Rx Queue #7,6 Descriptor Residue Count Register
    #define GNICMMIO_R7BRDU 0xFFFF0000  // 0/x/x/x Rx Queue#7 Descriptor buffer residue counts.
    #define GNICMMIO_R6BRDU 0xFFFF      // 0/x/x/x Rx Queue#6 Descriptor buffer residue counts.
#define GNICMMIO_TX_RX_INTR_SUPPRESSION_THRESHOLD_REG 0x234 // Tx/Rx Interrupt Suppression Threshold Register
    #define GNICMMIO_TSUPPTHR   0xFF000000  // 4h/x/x/x TSUPPTHR. Tx interrupt-suppression threshold register. While tx int-...
    #define GNICMMIO_RSUPPTHR   0xFF0000    // 4h/x/x/x RSUPPTHR. Rx interrupt-suppression threshold register. While rx int-...
#define GNICMMIO_A_CAM_DATA_REG01A 0x238 // A-CAM Data Register01A
    #define GNICMMIO_ACAM1A GNICMMIO_A_CAM_DATA_REG01A // 0/x/x/x A-CAM Data1[31:0]
#define GNICMMIO_A_CAM_DATA_REG01B 0x23C // A-CAM Data Register01B
    #define GNICMMIO_ACAM1B 0xFFFF      // 0/X/x/x A-CAM Data1[47:32]
#define GNICMMIO_A_CAM_DATA_REG02A 0x240 // A-CAM Data Register02A
    #define GNICMMIO_ACAM2A GNICMMIO_A_CAM_DATA_REG02A // 0/X/x/x A-CAM Data2[31:0]
#define GNICMMIO_A_CAM_DATA_REG02B 0x244 // A-CAM Data Register02B
    #define GNICMMIO_ACAM2B 0xFFFF      // 0/X/x/x A-CAM Data2[47:32]
#define GNICMMIO_A_CAM_DATA_REG03A 0x248 // A-CAM Data Register03A
    #define GNICMMIO_ACAM3A GNICMMIO_A_CAM_DATA_REG03A // 0/X/x/x A-CAM Data3[31:0]
#define GNICMMIO_A_CAM_DATA_REG_03B 0x24C // A-CAM Data Register 03B
    #define GNICMMIO_ACAM3B 0xFFFF      // 0/X/x/x A-CAM Data3[47:32]
#define GNICMMIO_A_CAM_DATA_REG04A 0x250 // A-CAM Data Register04A
    #define GNICMMIO_ACAM4A GNICMMIO_A_CAM_DATA_REG04A // 0/X/x/x A-CAM Data4[31:0]
#define GNICMMIO_A_CAM_DATA_REG04B 0x254 // A-CAM Data Register04B
    #define GNICMMIO_ACAM4B 0xFFFF      // 0/x/x/x A-CAM Data4[47:32]
#define GNICMMIO_A_CAM_DATA_REG05A 0x258 // A-CAM Data Register05A
    #define GNICMMIO_ACAM5A GNICMMIO_A_CAM_DATA_REG05A // 0/x/x/x A-CAM Data5[31:0]
#define GNICMMIO_A_CAM_DATA_REG05B 0x25C // A-CAM Data Register05B
    #define GNICMMIO_ACAM5B 0xFFFF      // 0/x/x/x A-CAM Data5[47:32]
#define GNICMMIO_A_CAM_DATA_REG06A 0x260 // A-CAM Data Register06A
    #define GNICMMIO_ACAM6A GNICMMIO_A_CAM_DATA_REG06A // 0/x/x/x A-CAM Data6[31:0]
#define GNICMMIO_A_CAM_DATA_REG06B 0x264 // A-CAM Data Register06B
    #define GNICMMIO_ACAM6B 0xFFFF      // 0/x/x/x A-CAM Data6[47:32]
#define GNICMMIO_A_CAM_DATA_REG07A 0x268 // A-CAM Data Register07A
    #define GNICMMIO_ACAM7A GNICMMIO_A_CAM_DATA_REG07A // 0/x/x/x A-CAM Data7[31:0]
#define GNICMMIO_A_CAM_DATA_REG07B 0x26C // A-CAM Data Register07B
    #define GNICMMIO_ACAM7B 0xFFFF      // 0/x/x/x A-CAM Data7[47:32]
#define GNICMMIO_A_CAM_DATA_REG08A 0x270 // A-CAM Data Register08A
    #define GNICMMIO_ACAM8A GNICMMIO_A_CAM_DATA_REG08A // 0/x/x/x A-CAM Data8[31:0]
#define GNICMMIO_A_CAM_DATA_REG08B 0x274 // A-CAM Data Register08B
    #define GNICMMIO_ACAM8B 0xFFFF      // 0/x/x/x A-CAM Data8[47:32]
#define GNICMMIO_A_CAM_DATA_REG09A 0x278 // A-CAM Data Register09A
    #define GNICMMIO_ACAM9A GNICMMIO_A_CAM_DATA_REG09A // 0/x/x/x A-CAM Data9[31:0]
#define GNICMMIO_A_CAM_DATA_REG09B 0x27C // A-CAM Data Register09B
    #define GNICMMIO_ACAM9B 0xFFFF      // 0/x/x/x A-CAM Data9[47:32]
#define GNICMMIO_A_CAM_DATA_REG10A 0x280 // A-CAM Data Register10A
    #define GNICMMIO_ACAM10A GNICMMIO_A_CAM_DATA_REG10A // 0/x/x/x A-CAM Data10[31:0]
#define GNICMMIO_A_CAM_DATA_REG10B 0x284 // A-CAM Data Register10B
    #define GNICMMIO_ACAM10B    0xFFFF      // 0/x/x/x A-CAM Data10[47:32]
#define GNICMMIO_A_CAM_DATA_REG11A 0x288 // A-CAM Data Register11A
    #define GNICMMIO_ACAM11A GNICMMIO_A_CAM_DATA_REG11A // 0/x/x/x A-CAM Data11[31:0]
#define GNICMMIO_A_CAM_DATA_REG11B 0x28C // A-CAM Data Register11B
    #define GNICMMIO_ACAM11B    0xFFFF      // 0/x/x/x A-CAM Data11[47:32]
#define GNICMMIO_A_CAM_DATA_REG12A 0x290 // A-CAM Data Register12A
    #define GNICMMIO_ACAM12A GNICMMIO_A_CAM_DATA_REG12A // 0/x/x/x A-CAM Data12[31:0]
#define GNICMMIO_A_CAM_DATA_REG12B 0x294 // A-CAM Data Register12B
    #define GNICMMIO_ACAM12B    0xFFFF      // 0/x/x/x A-CAM Data12[47:32]
#define GNICMMIO_A_CAM_DATA_REG13A 0x298 // A-CAM Data Register13A
    #define GNICMMIO_ACAM13A GNICMMIO_A_CAM_DATA_REG13A // 0/x/x/x A-CAM Data13[31:0]
#define GNICMMIO_A_CAM_DATA_REG13B 0x29C // A-CAM Data Register13B
    #define GNICMMIO_ACAM13B    0xFFFF      // 0/x/x/x A-CAM Data13[47:32]
#define GNICMMIO_A_CAM_DATA_REG14A 0x2A0 // A-CAM Data Register14A
    #define GNICMMIO_ACAM14A GNICMMIO_A_CAM_DATA_REG14A // 0/x/x/x A-CAM Data14[31:0]
#define GNICMMIO_A_CAM_DATA_REG14B 0x2A4 // A-CAM Data Register14B
    #define GNICMMIO_ACAM14B    0xFFFF      // 0/x/x/x A-CAM Data14[47:32]
#define GNICMMIO_A_CAM_DATA_REG15A 0x2A8 // A-CAM Data Register15A
    #define GNICMMIO_ACAM15A GNICMMIO_A_CAM_DATA_REG15A // 0/x/x/x A-CAM Data15[31:0]
#define GNICMMIO_A_CAM_DATA_REG15B 0x2AC // A-CAM Data Register15B
    #define GNICMMIO_ACAM15B    0xFFFF      // 0/x/x/x A-CAM Data15[47:32]
#define GNICMMIO_A_CAM_DATA_REG16A 0x2B0 // A-CAM Data Register16A
    #define GNICMMIO_ACAM16A GNICMMIO_A_CAM_DATA_REG16A // 0/x/x/x A-CAM Data16[31:0]
#define GNICMMIO_A_CAM_DATA_REG16B 0x2B4 // A-CAM Data Register16B
    #define GNICMMIO_ACAM16B    0xFFFF      // 0/x/x/x A-CAM Data16[47:32]
#define GNICMMIO_A_CAM_DATA_REG17A 0x2B8 // A-CAM Data Register17A
    #define GNICMMIO_ACAM17A GNICMMIO_A_CAM_DATA_REG17A // 0/x/x/x A-CAM Data17[31:0]
#define GNICMMIO_A_CAM_DATA_REG17B 0x2BC // A-CAM Data Register17B
    #define GNICMMIO_ACAM17B    0xFFFF      // 0/x/x/x A-CAM Data17[47:32]
#define GNICMMIO_A_CAM_DATA_REG18A 0x2C0 // A-CAM Data Register18A
    #define GNICMMIO_ACAM18A GNICMMIO_A_CAM_DATA_REG18A // 0/x/x/x A-CAM Data18[31:0]
#define GNICMMIO_A_CAM_DATA_REG18B 0x2C4 // A-CAM Data Register18B
    #define GNICMMIO_ACAM18B    0xFFFF      // 0/x/x/x A-CAM Data18[47:32]
#define GNICMMIO_A_CAM_DATA_REG19A 0x2C8 // A-CAM Data Register19A
    #define GNICMMIO_ACAM19A GNICMMIO_A_CAM_DATA_REG19A // 0/x/x/x A-CAM Data19[31:0]
#define GNICMMIO_A_CAM_DATA_REG19B 0x2CC // A-CAM Data Register19B
    #define GNICMMIO_ACAM19B    0xFFFF      // 0/x/x/x A-CAM Data19[47:32]
#define GNICMMIO_A_CAM_DATA_REG20A 0x2D0 // A-CAM Data Register20A
    #define GNICMMIO_ACAM20A GNICMMIO_A_CAM_DATA_REG20A // 0/x/x/x A-CAM Data20[31:0]
#define GNICMMIO_A_CAM_DATA_REG20B 0x2D4 // A-CAM Data Register20B
    #define GNICMMIO_ACAM20B    0xFFFF      // 0/x/x/x A-CAM Data20[47:32]
#define GNICMMIO_A_CAM_DATA_REG21A 0x2D8 // A-CAM Data Register21A
    #define GNICMMIO_ACAM21A GNICMMIO_A_CAM_DATA_REG21A // 0/x/x/x A-CAM Data21[31:0]
#define GNICMMIO_A_CAM_DATA_REG21B 0x2DC // A-CAM Data Register21B
    #define GNICMMIO_ACAM21B    0xFFFF      // 0/x/x/x A-CAM Data21[47:32]
#define GNICMMIO_A_CAM_DATA_REG22A 0x2E0 // A-CAM Data Register22A
    #define GNICMMIO_ACAM22A GNICMMIO_A_CAM_DATA_REG22A // 0/x/x/x A-CAM Data22[31:0]
#define GNICMMIO_A_CAM_DATA_REG22B 0x2E4 // A-CAM Data Register22B
    #define GNICMMIO_ACAM22B    0xFFFF      // 0/x/x/x A-CAM Data22[47:32]
#define GNICMMIO_A_CAM_DATA_REG23A 0x2E8 // A-CAM Data Register23A
    #define GNICMMIO_ACAM23A GNICMMIO_A_CAM_DATA_REG23A // 0/x/x/x A-CAM Data23[31:0]
#define GNICMMIO_A_CAM_DATA_REG23B 0x2EC // A-CAM Data Register23B
    #define GNICMMIO_ACAM23B    0xFFFF      // 0/x/x/x A-CAM Data23[47:32]
#define GNICMMIO_A_CAM_DATA_REG24A 0x2F0 // A-CAM Data Register24A
    #define GNICMMIO_ACAM24A GNICMMIO_A_CAM_DATA_REG24A // 0/x/x/x A-CAM Data24[31:0]
#define GNICMMIO_A_CAM_DATA_REG24B 0x2F4 // A-CAM Data Register24B
    #define GNICMMIO_ACAM24B    0xFFFF      // 0/x/x/x A-CAM Data24[47:32]
#define GNICMMIO_A_CAM_DATA_REG25A 0x2F8 // A-CAM Data Register25A
    #define GNICMMIO_ACAM25A GNICMMIO_A_CAM_DATA_REG25A // 0/x/x/x A-CAM Data25[31:0]
#define GNICMMIO_A_CAM_DATA_REG25B 0x2FC // A-CAM Data Register25B
    #define GNICMMIO_ACAM25B    0xFFFF      // 0/x/x/x A-CAM Data25[47:32]
#define GNICMMIO_A_CAM_DATA_REG26A 0x300 // A-CAM Data Register26A
    #define GNICMMIO_ACAM26A GNICMMIO_A_CAM_DATA_REG26A // 0/x/x/x A-CAM Data26[31:0]
#define GNICMMIO_A_CAM_DATA_REG26B 0x304 // A-CAM Data Register26B
    #define GNICMMIO_ACAM26B    0xFFFF      // 0/x/x/x A-CAM Data26[47:32]
#define GNICMMIO_A_CAM_DATA_REG27A 0x308 // A-CAM Data Register27A
    #define GNICMMIO_ACAM27A GNICMMIO_A_CAM_DATA_REG27A // 0/x/x/x A-CAM Data27[31:0]
#define GNICMMIO_A_CAM_DATA_REG27B 0x30C // A-CAM Data Register27B
    #define GNICMMIO_ACAM27B    0xFFFF      // 0/x/x/x A-CAM Data27[47:32]
#define GNICMMIO_A_CAM_DATA_REG28A 0x310 // A-CAM Data Register28A
    #define GNICMMIO_ACAM28A GNICMMIO_A_CAM_DATA_REG28A // 0/x/x/x A-CAM Data28[31:0]
#define GNICMMIO_A_CAM_DATA_REG28B 0x314 // A-CAM Data Register28B
    #define GNICMMIO_ACAM28B    0xFFFF      // 0/x/x/x A-CAM Data28[47:32]
#define GNICMMIO_A_CAM_DATA_REG29A 0x318 // A-CAM Data Register29A
    #define GNICMMIO_ACAM29A GNICMMIO_A_CAM_DATA_REG29A // 0/x/x/x A-CAM Data29[31:0]
#define GNICMMIO_A_CAM_DATA_REG29B 0x31C // A-CAM Data Register29B
    #define GNICMMIO_ACAM29B    0xFFFF      // 0/x/x/x A-CAM Data29[47:32]
#define GNICMMIO_A_CAM_DATA_REG30A 0x320 // A-CAM Data Register30A
    #define GNICMMIO_ACAM30A GNICMMIO_A_CAM_DATA_REG30A // 0/x/x/x A-CAM Data30[31:0]
#define GNICMMIO_A_CAM_DATA_REG30B 0x324 // A-CAM Data Register30B
    #define GNICMMIO_ACAM30B    0xFFFF      // 0/x/x/x A-CAM Data30[47:32]
#define GNICMMIO_A_CAM_DATA_REG31A 0x328 // A-CAM Data Register31A
    #define GNICMMIO_ACAM31A GNICMMIO_A_CAM_DATA_REG31A // 0/x/x/x A-CAM Data31[31:0]
#define GNICMMIO_A_CAM_DATA_REG31B 0x32C // A-CAM Data Register31B
    #define GNICMMIO_ACAM31B    0xFFFF      // 0/x/x/x A-CAM Data31[47:32]
#define GNICMMIO_A_CAM_DATA_REG32A 0x330 // A-CAM Data Register32A
    #define GNICMMIO_ACAM32A GNICMMIO_A_CAM_DATA_REG32A // 0/x/x/x A-CAM Data32[31:0]
#define GNICMMIO_A_CAM_DATA_REG32B 0x334 // A-CAM Data Register32B
    #define GNICMMIO_ACAM32B    0xFFFF      // 0/x/x/x A-CAM Data32[47:32]
#define GNICMMIO_A_CAM_DATA_REG33A 0x338 // A-CAM Data Register33A
    #define GNICMMIO_ACAM33A GNICMMIO_A_CAM_DATA_REG33A // 0/x/x/x A-CAM Data33[31:0]
#define GNICMMIO_A_CAM_DATA_REG33B 0x33C // A-CAM Data Register33B
    #define GNICMMIO_ACAM33B    0xFFFF      // 0/x/x/x A-CAM Data33[47:32]
#define GNICMMIO_A_CAM_DATA_REG34A 0x340 // A-CAM Data Register34A
    #define GNICMMIO_ACAM34A GNICMMIO_A_CAM_DATA_REG34A // 0/x/x/x A-CAM Data34[31:0]
#define GNICMMIO_A_CAM_DATA_REG34B 0x344 // A-CAM Data Register34B
    #define GNICMMIO_ACAM34B    0xFFFF      // 0/x/x/x A-CAM Data34[47:32]
#define GNICMMIO_A_CAM_DATA_REG35A 0x348 // A-CAM Data Register35A
    #define GNICMMIO_ACAM35A GNICMMIO_A_CAM_DATA_REG35A // 0/x/x/x A-CAM Data35[31:0]
#define GNICMMIO_A_CAM_DATA_REG35B 0x34C // A-CAM Data Register35B
    #define GNICMMIO_ACAM35B    0xFFFF      // 0/x/x/x A-CAM Data35[47:32]
#define GNICMMIO_A_CAM_DATA_REG36A 0x350 // A-CAM Data Register36A
    #define GNICMMIO_ACAM36A GNICMMIO_A_CAM_DATA_REG36A // 0/x/x/x A-CAM Data36[31:0]
#define GNICMMIO_A_CAM_DATA_REG36B 0x354 // A-CAM Data Register36B
    #define GNICMMIO_ACAM36B    0xFFFF      // 0/x/x/x A-CAM Data36[47:32]
#define GNICMMIO_A_CAM_DATA_REG37A 0x358 // A-CAM Data Register37A
    #define GNICMMIO_ACAM37A GNICMMIO_A_CAM_DATA_REG37A // 0/x/x/x A-CAM Data37[31:0]
#define GNICMMIO_A_CAM_DATA_REG37B 0x35C // A-CAM Data Register37B
    #define GNICMMIO_ACAM37B    0xFFFF      // 0/x/x/x A-CAM Data37[47:32]
#define GNICMMIO_A_CAM_DATA_REG38A 0x360 // A-CAM Data Register38A
    #define GNICMMIO_ACAM38A GNICMMIO_A_CAM_DATA_REG38A // 0/X/x/x A-CAM Data38[31:0]
#define GNICMMIO_A_CAM_DATA_REG38B 0x364 // A-CAM Data Register38B
    #define GNICMMIO_ACAM38B    0xFFFF      // 0/X/x/x A-CAM Data38[47:32]
#define GNICMMIO_A_CAM_DATA_REG39A 0x368 // A-CAM Data Register39A
    #define GNICMMIO_ACAM39A GNICMMIO_A_CAM_DATA_REG39A // 0/X/x/x A-CAM Data39[31:0]
#define GNICMMIO_A_CAM_DATA_REG39B 0x36C // A-CAM Data Register39B
    #define GNICMMIO_ACAM39B    0xFFFF      // 0/X/x/x A-CAM Data39[47:32]
#define GNICMMIO_A_CAM_DATA_REG40A 0x370 // A-CAM Data Register40A
    #define GNICMMIO_ACAM40A GNICMMIO_A_CAM_DATA_REG40A // 0/X/x/x A-CAM Data40[31:0]
#define GNICMMIO_A_CAM_DATA_REG40B 0x374 // A-CAM Data Register40B
    #define GNICMMIO_ACAM40B    0xFFFF      // 0/X/x/x A-CAM Data40[47:32]
#define GNICMMIO_A_CAM_DATA_REG41A 0x378 // A-CAM Data Register41A
    #define GNICMMIO_ACAM41A GNICMMIO_A_CAM_DATA_REG41A // 0/X/x/x A-CAM Data41[31:0]
#define GNICMMIO_A_CAM_DATA_REG41B 0x37C // A-CAM Data Register41B
    #define GNICMMIO_ACAM41B    0xFFFF      // 0/X/x/x A-CAM Data41[47:32]
#define GNICMMIO_A_CAM_DATA_REG42A 0x380 // A-CAM Data Register42A
    #define GNICMMIO_ACAM42A GNICMMIO_A_CAM_DATA_REG42A // 0/X/x/x A-CAM Data42[31:0]
#define GNICMMIO_A_CAM_DATA_REG42B 0x384 // A-CAM Data Register42B
    #define GNICMMIO_ACAM42B    0xFFFF      // 0/X/x/x A-CAM Data42[47:32]
#define GNICMMIO_A_CAM_DATA_REG43A 0x388 // A-CAM Data Register43A
    #define GNICMMIO_ACAM43A GNICMMIO_A_CAM_DATA_REG43A // 0/X/x/x A-CAM Data43[31:0]
#define GNICMMIO_A_CAM_DATA_REG43B 0x38C // A-CAM Data Register43B
    #define GNICMMIO_ACAM43B    0xFFFF      // 0/X/x/x A-CAM Data43[47:32]
#define GNICMMIO_A_CAM_DATA_REG44A 0x390 // A-CAM Data Register44A
    #define GNICMMIO_ACAM44A GNICMMIO_A_CAM_DATA_REG44A // 0/X/x/x A-CAM Data44[31:0]
#define GNICMMIO_A_CAM_DATA_REG44B 0x394 // A-CAM Data Register44B
    #define GNICMMIO_ACAM44B    0xFFFF      // 0/X/x/x A-CAM Data44[47:32]
#define GNICMMIO_A_CAM_DATA_REG45A 0x398 // A-CAM Data Register45A
    #define GNICMMIO_ACAM45A GNICMMIO_A_CAM_DATA_REG45A // 0/X/x/x A-CAM Data45[31:0]
#define GNICMMIO_A_CAM_DATA_REG45B 0x39C // A-CAM Data Register45B
    #define GNICMMIO_ACAM45B    0xFFFF      // 0/X/x/x A-CAM Data45[47:32]
#define GNICMMIO_A_CAM_DATA_REG46A 0x3A0 // A-CAM Data Register46A
    #define GNICMMIO_ACAM46A GNICMMIO_A_CAM_DATA_REG46A // 0/X/x/x A-CAM Data46[31:0]
#define GNICMMIO_A_CAM_DATA_REG46B 0x3A4 // A-CAM Data Register46B
    #define GNICMMIO_ACAM46B    0xFFFF      // 0/X/x/x A-CAM Data46[47:32]
#define GNICMMIO_A_CAM_DATA_REG47A 0x3A8 // A-CAM Data Register47A
    #define GNICMMIO_ACAM47A GNICMMIO_A_CAM_DATA_REG47A // 0/X/x/x A-CAM Data47[31:0]
#define GNICMMIO_A_CAM_DATA_REG47B 0x3AC // A-CAM Data Register47B
    #define GNICMMIO_ACAM47B    0xFFFF      // 0/X/x/x A-CAM Data47[47:32]
#define GNICMMIO_A_CAM_DATA_REG48A 0x3B0 // A-CAM Data Register48A
    #define GNICMMIO_ACAM48A GNICMMIO_A_CAM_DATA_REG48A // 0/X/x/x A-CAM Data48[31:0]
#define GNICMMIO_A_CAM_DATA_REG48B 0x3B4 // A-CAM Data Register48B
    #define GNICMMIO_ACAM48B    0xFFFF      // 0/X/x/x A-CAM Data48[47:32]
#define GNICMMIO_A_CAM_DATA_REG49A 0x3B8 // A-CAM Data Register49A
    #define GNICMMIO_ACAM49A GNICMMIO_A_CAM_DATA_REG49A // 0/X/x/x A-CAM Data49[31:0]
#define GNICMMIO_A_CAM_DATA_REG49B 0x3BC // A-CAM Data Register49B
    #define GNICMMIO_ACAM49B    0xFFFF      // 0/X/x/x A-CAM Data49[47:32]
#define GNICMMIO_A_CAM_DATA_REG50A 0x3C0 // A-CAM Data Register50A
    #define GNICMMIO_ACAM50A GNICMMIO_A_CAM_DATA_REG50A // 0/X/x/x A-CAM Data50[31:0]
#define GNICMMIO_A_CAM_DATA_REG50B 0x3C4 // A-CAM Data Register50B
    #define GNICMMIO_ACAM50B    0xFFFF      // 0/X/x/x A-CAM Data50[47:32]
#define GNICMMIO_A_CAM_DATA_REG51A 0x3C8 // A-CAM Data Register51A
    #define GNICMMIO_ACAM51A GNICMMIO_A_CAM_DATA_REG51A // 0/X/x/x A-CAM Data51[31:0]
#define GNICMMIO_A_CAM_DATA_REG51B 0x3CC // A-CAM Data Register51B
    #define GNICMMIO_ACAM51B    0xFFFF      // 0/X/x/x A-CAM Data51[47:32]
#define GNICMMIO_A_CAM_DATA_REG52A 0x3D0 // A-CAM Data Register52A
    #define GNICMMIO_ACAM52A GNICMMIO_A_CAM_DATA_REG52A // 0/X/x/x A-CAM Data52[31:0]
#define GNICMMIO_A_CAM_DATA_REG52B 0x3D4 // A-CAM Data Register52B
    #define GNICMMIO_ACAM52B    0xFFFF      // 0/X/x/x A-CAM Data52[47:32]
#define GNICMMIO_A_CAM_DATA_REG53A 0x3D8 // A-CAM Data Register53A
    #define GNICMMIO_ACAM53A GNICMMIO_A_CAM_DATA_REG53A // 0/X/x/x A-CAM Data53[31:0]
#define GNICMMIO_A_CAM_DATA_REG53B 0x3DC // A-CAM Data Register53B
    #define GNICMMIO_ACAM53B    0xFFFF      // 0/X/x/x A-CAM Data53[47:32]
#define GNICMMIO_A_CAM_DATA_REG54A 0x3E0 // A-CAM Data Register54A
    #define GNICMMIO_ACAM54A GNICMMIO_A_CAM_DATA_REG54A // 0/X/x/x A-CAM Data54[31:0]
#define GNICMMIO_A_CAM_DATA_REG54B 0x3E4 // A-CAM Data Register54B
    #define GNICMMIO_ACAM54B    0xFFFF      // 0/X/x/x A-CAM Data54[47:32]
#define GNICMMIO_A_CAM_DATA_REG55A 0x3E8 // A-CAM Data Register55A
    #define GNICMMIO_ACAM55A GNICMMIO_A_CAM_DATA_REG55A // 0/X/x/x A-CAM Data55[31:0]
#define GNICMMIO_A_CAM_DATA_REG55B 0x3EC // A-CAM Data Register55B
    #define GNICMMIO_ACAM55B    0xFFFF      // 0/X/x/x A-CAM Data55[47:32]
#define GNICMMIO_A_CAM_DATA_REG56A 0x3F0 // A-CAM Data Register56A
    #define GNICMMIO_ACAM56A GNICMMIO_A_CAM_DATA_REG56A // 0/X/x/x A-CAM Data56[31:0]
#define GNICMMIO_A_CAM_DATA_REG56B 0x3F4 // A-CAM Data Register56B
    #define GNICMMIO_ACAM56B    0xFFFF      // 0/X/x/x A-CAM Data56[47:32]
#define GNICMMIO_A_CAM_DATA_REG57A 0x3F8 // A-CAM Data Register57A
    #define GNICMMIO_ACAM57A GNICMMIO_A_CAM_DATA_REG57A // 0/X/x/x A-CAM Data57[31:0]
#define GNICMMIO_A_CAM_DATA_REG57B 0x3FC // A-CAM Data Register57B
    #define GNICMMIO_ACAM57B    0xFFFF      // 0/X/x/x A-CAM Data57[47:32]
#define GNICMMIO_A_CAM_DATA_REG58A 0x400 // A-CAM Data Register58A
    #define GNICMMIO_ACAM58A GNICMMIO_A_CAM_DATA_REG58A // 0/X/x/x A-CAM Data58[31:0]
#define GNICMMIO_A_CAM_DATA_REG58B 0x404 // A-CAM Data Register58B
    #define GNICMMIO_ACAM58B    0xFFFF      // 0/X/x/x A-CAM Data58[47:32]
#define GNICMMIO_A_CAM_DATA_REG59A 0x408 // A-CAM Data Register59A
    #define GNICMMIO_ACAM59A GNICMMIO_A_CAM_DATA_REG59A // 0/X/x/x A-CAM Data59[31:0]
#define GNICMMIO_A_CAM_DATA_REG59B 0x40C // A-CAM Data Register59B
    #define GNICMMIO_ACAM59B    0xFFFF      // 0/X/x/x A-CAM Data59[47:32]
#define GNICMMIO_A_CAM_DATA_REG60A 0x410 // A-CAM Data Register60A
    #define GNICMMIO_ACAM60A GNICMMIO_A_CAM_DATA_REG60A // 0/X/x/x A-CAM Data60[31:0]
#define GNICMMIO_A_CAM_DATA_REG60B 0x414 // A-CAM Data Register60B
    #define GNICMMIO_ACAM60B    0xFFFF      // 0/X/x/x A-CAM Data60[47:32]
#define GNICMMIO_A_CAM_DATA_REG61A 0x418 // A-CAM Data Register61A
    #define GNICMMIO_ACAM61A GNICMMIO_A_CAM_DATA_REG61A // 0/X/x/x A-CAM Data61[31:0]
#define GNICMMIO_A_CAM_DATA_REG61B 0x41C // A-CAM Data Register61B
    #define GNICMMIO_ACAM61B    0xFFFF      // 0/X/x/x A-CAM Data61[47:32]
#define GNICMMIO_A_CAM_DATA_REG62A 0x420 // A-CAM Data Register62A
    #define GNICMMIO_ACAM62A GNICMMIO_A_CAM_DATA_REG62A // 0/X/x/x A-CAM Data62[31:0]
#define GNICMMIO_A_CAM_DATA_REG62B 0x424 // A-CAM Data Register62B
    #define GNICMMIO_ACAM62B    0xFFFF      // 0/X/x/x A-CAM Data62[47:32]
#define GNICMMIO_A_CAM_DATA_REG63A 0x428 // A-CAM Data Register63A
    #define GNICMMIO_ACAM63A GNICMMIO_A_CAM_DATA_REG63A // 0/X/x/x A-CAM Data63[31:0]
#define GNICMMIO_A_CAM_DATA_REG63B 0x42C // A-CAM Data Register63B
    #define GNICMMIO_ACAM63B    0xFFFF      // 0/X/x/x A-CAM Data63[47:32]
#define GNICMMIO_A_CAM_DATA_REG64A 0x430 // A-CAM Data Register64A
    #define GNICMMIO_ACAM64A GNICMMIO_A_CAM_DATA_REG64A // 0/X/x/x A-CAM Data64[31:0]
#define GNICMMIO_A_CAM_DATA_REG64B 0x434 // A-CAM Data Register64B
    #define GNICMMIO_ACAM64B    0xFFFF      // 0/X/x/x A-CAM Data64[47:32]
#define GNICMMIO_V_CAM_DATA_REG01 0x438 // V-CAM Data Register01
    #define GNICMMIO_VCAM1  0xFFF       // 0/X/x/x V-CAM Data1
#define GNICMMIO_V_CAM_DATA_REG02 0x43C // V-CAM Data Register02
    #define GNICMMIO_VCAM2  0xFFF       // 0/X/x/x V-CAM Data2
#define GNICMMIO_V_CAM_DATA_REG03 0x440 // V-CAM Data Register03
    #define GNICMMIO_VCAM3  0xFFF       // 0/X/x/x V-CAM Data3
#define GNICMMIO_V_CAM_DATA_REG04 0x444 // V-CAM Data Register04
    #define GNICMMIO_VCAM4  0xFFF       // 0/X/x/x V-CAM Data4
#define GNICMMIO_V_CAM_DATA_REG05 0x448 // V-CAM Data Register05
    #define GNICMMIO_VCAM5  0xFFF       // 0/X/x/x V-CAM Data5
#define GNICMMIO_V_CAM_DATA_REG06 0x44C // V-CAM Data Register06
    #define GNICMMIO_VCAM6  0xFFF       // 0/X/x/x V-CAM Data6
#define GNICMMIO_V_CAM_DATA_REG07 0x450 // V-CAM Data Register07
    #define GNICMMIO_VCAM7  0xFFF       // 0/X/x/x V-CAM Data7
#define GNICMMIO_V_CAM_DATA_REG08 0x454 // V-CAM Data Register08
    #define GNICMMIO_VCAM8  0xFFF       // 0/X/x/x V-CAM Data8
#define GNICMMIO_V_CAM_DATA_REG09 0x458 // V-CAM Data Register09
    #define GNICMMIO_VCAM9  0xFFF       // 0/X/x/x V-CAM Data9
#define GNICMMIO_V_CAM_DATA_REG10 0x45C // V-CAM Data Register10
    #define GNICMMIO_VCAM10 0xFFF       // 0/X/x/x V-CAM Data10
#define GNICMMIO_V_CAM_DATA_REG11 0x460 // V-CAM Data Register11
    #define GNICMMIO_VCAM11 0xFFF       // 0/X/x/x V-CAM Data11
#define GNICMMIO_V_CAM_DATA_REG12 0x464 // V-CAM Data Register12
    #define GNICMMIO_VCAM12 0xFFF       // 0/X/x/x V-CAM Data12
#define GNICMMIO_V_CAM_DATA_REG13 0x468 // V-CAM Data Register13
    #define GNICMMIO_VCAM13 0xFFF       // 0/X/x/x V-CAM Data13
#define GNICMMIO_V_CAM_DATA_REG14 0x46C // V-CAM Data Register14
    #define GNICMMIO_VCAM14 0xFFF       // 0/X/x/x V-CAM Data14
#define GNICMMIO_V_CAM_DATA_REG15 0x470 // V-CAM Data Register15
    #define GNICMMIO_VCAM15 0xFFF       // 0/X/x/x V-CAM Data15
#define GNICMMIO_V_CAM_DATA_REG16 0x474 // V-CAM Data Register16
    #define GNICMMIO_VCAM16 0xFFF       // 0/X/x/x V-CAM Data16
#define GNICMMIO_V_CAM_DATA_REG17 0x478 // V-CAM Data Register17
    #define GNICMMIO_VCAM17 0xFFF       // 0/X/x/x V-CAM Data17
#define GNICMMIO_V_CAM_DATA_REG18 0x47C // V-CAM Data Register18
    #define GNICMMIO_VCAM18 0xFFF       // 0/X/x/x V-CAM Data18
#define GNICMMIO_V_CAM_DATA_REG19 0x480 // V-CAM Data Register19
    #define GNICMMIO_VCAM19 0xFFF       // 0/X/x/x V-CAM Data19
#define GNICMMIO_V_CAM_DATA_REG20 0x484 // V-CAM Data Register20
    #define GNICMMIO_VCAM20 0xFFF       // 0/X/x/x V-CAM Data20
#define GNICMMIO_V_CAM_DATA_REG21 0x488 // V-CAM Data Register21
    #define GNICMMIO_VCAM21 0xFFF       // 0/X/x/x V-CAM Data21
#define GNICMMIO_V_CAM_DATA_REG22 0x48C // V-CAM Data Register22
    #define GNICMMIO_VCAM22 0xFFF       // 0/X/x/x V-CAM Data22
#define GNICMMIO_V_CAM_DATA_REG23 0x490 // V-CAM Data Register23
    #define GNICMMIO_VCAM23 0xFFF       // 0/X/x/x V-CAM Data23
#define GNICMMIO_V_CAM_DATA_REG24 0x494 // V-CAM Data Register24
    #define GNICMMIO_VCAM24 0xFFF       // 0/X/x/x V-CAM Data24
#define GNICMMIO_V_CAM_DATA_REG25 0x498 // V-CAM Data Register25
    #define GNICMMIO_VCAM25 0xFFF       // 0/X/x/x V-CAM Data25
#define GNICMMIO_V_CAM_DATA_REG26 0x49C // V-CAM Data Register26
    #define GNICMMIO_VCAM26 0xFFF       // 0/X/x/x V-CAM Data26
#define GNICMMIO_V_CAM_DATA_REG27 0x4A0 // V-CAM Data Register27
    #define GNICMMIO_VCAM27 0xFFF       // 0/X/x/x V-CAM Data27
#define GNICMMIO_V_CAM_DATA_REG28 0x4A4 // V-CAM Data Register28
    #define GNICMMIO_VCAM28 0xFFF       // 0/X/x/x V-CAM Data28
#define GNICMMIO_V_CAM_DATA_REG29 0x4A8 // V-CAM Data Register29
    #define GNICMMIO_VCAM29 0xFFF       // 0/X/x/x V-CAM Data29
#define GNICMMIO_V_CAM_DATA_REG30 0x4AC // V-CAM Data Register30
    #define GNICMMIO_VCAM30 0xFFF       // 0/X/x/x V-CAM Data30
#define GNICMMIO_V_CAM_DATA_REG31 0x4B0 // V-CAM Data Register31
    #define GNICMMIO_VCAM31 0xFFF       // 0/X/x/x V-CAM Data31
#define GNICMMIO_V_CAM_DATA_REG32 0x4B4 // V-CAM Data Register32
    #define GNICMMIO_VCAM32 0xFFF       // 0/X/x/x V-CAM Data32
#define GNICMMIO_V_CAM_DATA_REG33 0x4B8 // V-CAM Data Register33
    #define GNICMMIO_VCAM33 0xFFF       // 0/X/x/x V-CAM Data33
#define GNICMMIO_V_CAM_DATA_REG34 0x4BC // V-CAM Data Register34
    #define GNICMMIO_VCAM34 0xFFF       // 0/X/x/x V-CAM Data34
#define GNICMMIO_V_CAM_DATA_REG35 0x4C0 // V-CAM Data Register35
    #define GNICMMIO_VCAM35 0xFFF       // 0/X/x/x V-CAM Data35
#define GNICMMIO_V_CAM_DATA_REG36 0x4C4 // V-CAM Data Register36
    #define GNICMMIO_VCAM36 0xFFF       // 0/X/x/x V-CAM Data36
#define GNICMMIO_V_CAM_DATA_REG37 0x4C8 // V-CAM Data Register37
    #define GNICMMIO_VCAM37 0xFFF       // 0/X/x/x V-CAM Data37
#define GNICMMIO_V_CAM_DATA_REG38 0x4CC // V-CAM Data Register38
    #define GNICMMIO_VCAM38 0xFFF       // 0/X/x/x V-CAM Data38
#define GNICMMIO_V_CAM_DATA_REG39 0x4D0 // V-CAM Data Register39
    #define GNICMMIO_VCAM39 0xFFF       // 0/X/x/x V-CAM Data39
#define GNICMMIO_V_CAM_DATA_REG40 0x4D4 // V-CAM Data Register40
    #define GNICMMIO_VCAM40 0xFFF       // 0/X/x/x V-CAM Data40
#define GNICMMIO_V_CAM_DATA_REG41 0x4D8 // V-CAM Data Register41
    #define GNICMMIO_VCAM41 0xFFF       // 0/X/x/x V-CAM Data41
#define GNICMMIO_V_CAM_DATA_REG42 0x4DC // V-CAM Data Register42
    #define GNICMMIO_VCAM42 0xFFF       // 0/X/x/x V-CAM Data42
#define GNICMMIO_V_CAM_DATA_REG43 0x4E0 // V-CAM Data Register43
    #define GNICMMIO_VCAM43 0xFFF       // 0/X/x/x V-CAM Data43
#define GNICMMIO_V_CAM_DATA_REG44 0x4E4 // V-CAM Data Register44
    #define GNICMMIO_VCAM44 0xFFF       // 0/X/x/x V-CAM Data44
#define GNICMMIO_V_CAM_DATA_REG45 0x4E8 // V-CAM Data Register45
    #define GNICMMIO_VCAM45 0xFFF       // 0/X/x/x V-CAM Data45
#define GNICMMIO_V_CAM_DATA_REG46 0x4EC // V-CAM Data Register46
    #define GNICMMIO_VCAM46 0xFFF       // 0/X/x/x V-CAM Data46
#define GNICMMIO_V_CAM_DATA_REG47 0x4F0 // V-CAM Data Register47
    #define GNICMMIO_VCAM47 0xFFF       // 0/X/x/x V-CAM Data47
#define GNICMMIO_V_CAM_DATA_REG48 0x4F4 // V-CAM Data Register48
    #define GNICMMIO_VCAM48 0xFFF       // 0/X/x/x V-CAM Data48
#define GNICMMIO_V_CAM_DATA_REG49 0x4F8 // V-CAM Data Register49
    #define GNICMMIO_VCAM49 0xFFF       // 0/X/x/x V-CAM Data49
#define GNICMMIO_V_CAM_DATA_REG50 0x4FC // V-CAM Data Register50
    #define GNICMMIO_VCAM50 0xFFF       // 0/X/x/x V-CAM Data50
#define GNICMMIO_V_CAM_DATA_REG51 0x500 // V-CAM Data Register51
    #define GNICMMIO_VCAM51 0xFFF       // 0/X/x/x V-CAM Data51
#define GNICMMIO_V_CAM_DATA_REG52 0x504 // V-CAM Data Register52
    #define GNICMMIO_VCAM52 0xFFF       // 0/X/x/x V-CAM Data52
#define GNICMMIO_V_CAM_DATA_REG53 0x508 // V-CAM Data Register53
    #define GNICMMIO_VCAM53 0xFFF       // 0/X/x/x V-CAM Data53
#define GNICMMIO_V_CAM_DATA_REG54 0x50C // V-CAM Data Register54
    #define GNICMMIO_VCAM54 0xFFF       // 0/X/x/x V-CAM Data54
#define GNICMMIO_V_CAM_DATA_REG55 0x510 // V-CAM Data Register55
    #define GNICMMIO_VCAM55 0xFFF       // 0/X/x/x V-CAM Data55
#define GNICMMIO_V_CAM_DATA_REG56 0x514 // V-CAM Data Register56
    #define GNICMMIO_VCAM56 0xFFF       // 0/X/x/x V-CAM Data56
#define GNICMMIO_V_CAM_DATA_REG57 0x518 // V-CAM Data Register57
    #define GNICMMIO_VCAM57 0xFFF       // 0/X/x/x V-CAM Data57
#define GNICMMIO_V_CAM_DATA_REG58 0x51C // V-CAM Data Register58
    #define GNICMMIO_VCAM58 0xFFF       // 0/X/x/x V-CAM Data58
#define GNICMMIO_V_CAM_DATA_REG59 0x520 // V-CAM Data Register59
    #define GNICMMIO_VCAM59 0xFFF       // 0/X/x/x V-CAM Data59
#define GNICMMIO_V_CAM_DATA_REG60 0x524 // V-CAM Data Register60
    #define GNICMMIO_VCAM60 0xFFF       // 0/X/x/x V-CAM Data60
#define GNICMMIO_V_CAM_DATA_REG61 0x528 // V-CAM Data Register61
    #define GNICMMIO_VCAM61 0xFFF       // 0/X/x/x V-CAM Data61
#define GNICMMIO_V_CAM_DATA_REG62 0x52C // V-CAM Data Register62
    #define GNICMMIO_VCAM62 0xFFF       // 0/X/x/x V-CAM Data62
#define GNICMMIO_V_CAM_DATA_REG63 0x530 // V-CAM Data Register63
    #define GNICMMIO_VCAM63 0xFFF       // 0/X/x/x V-CAM Data63
#define GNICMMIO_V_CAM_DATA_REG64 0x534 // V-CAM Data Register64
    #define GNICMMIO_VCAM64 0xFFF       // 0/x/x/x V-CAM Data64
#define GNICMMIO_A_CAM_MASK_REG01 0x538 // A-CAM Mask Register01
    #define GNICMMIO_ACAMM1 GNICMMIO_A_CAM_MASK_REG01 // 0/x/x/x A-CAM mask bit
#define GNICMMIO_A_CAM_MASK_REG02 0x53C // A-CAM Mask Register02
    #define GNICMMIO_ACAMM2 GNICMMIO_A_CAM_MASK_REG02 // 0/x/x/x A-CAM mask bit
#define GNICMMIO_V_CAM_MASK_REG01 0x540 // V-CAM Mask Register01
    #define GNICMMIO_VCAMM1 GNICMMIO_V_CAM_MASK_REG01 // 0/x/x/x V-CAM mask bit
#define GNICMMIO_V_CAM_MASK_REG02 0x544 // V-CAM Mask Register02
    #define GNICMMIO_VCAMM2 GNICMMIO_V_CAM_MASK_REG02 // 0/x/x/x V-CAM mask bit
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG1 0x550 // 8 Groups of 128-bits CRC Register1
    #define GNICMMIO_PMGBM1 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG1 // 0/x/x/x Pattern Match Group 0 bit mask [31:0]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG2 0x554 // 8 Groups of 128-bits CRC Register2
    #define GNICMMIO_PMGBM2 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG2 // 0/x/x/x Pattern Match Group 0 bit mask [63:32]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG3 0x558 // 8 Groups of 128-bits CRC Register3
    #define GNICMMIO_PMGBM3 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG3 // 0/x/x/x Pattern Match Group 0 bit mask [95:64]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG4 0x55C // 8 Groups of 128-bits CRC Register4
    #define GNICMMIO_PMGBM4 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG4 // 0/x/x/x Pattern Match Group 0 bit mask [127:96]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG5 0x560 // 8 Groups of 128-bits CRC Register5
    #define GNICMMIO_PMGBM5 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG5 // 0/x/x/x Pattern Match Group 1 bit mask [31:0]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG6 0x564 // 8 Groups of 128-bits CRC Register6
    #define GNICMMIO_PMGBM6 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG6 // 0/x/x/x Pattern Match Group 1 bit mask [63:32]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG7 0x568 // 8 Groups of 128-bits CRC Register7
    #define GNICMMIO_PMGBM7 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG7 // 0/x/x/x Pattern Match Group 1 bit mask [95:64]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG8 0x56C // 8 Groups of 128-bits CRC Register8
    #define GNICMMIO_PMGBM8 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG8 // 0/x/x/x Pattern Match Group 1 bit mask [127:96]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG9 0x570 // 8 Groups of 128-bits CRC Register9
    #define GNICMMIO_PMGBM9 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG9 // 0/x/x/x Pattern Match Group 2 bit mask [31:0]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG10 0x574 // 8 Groups of 128-bits CRC Register10
    #define GNICMMIO_PMGBM10 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG10 // 0/x/x/x Pattern Match Group 2 bit mask [63:32]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG11 0x578 // 8 Groups of 128-bits CRC Register11
    #define GNICMMIO_PMGBM11 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG11 // 0/x/x/x Pattern Match Group 2 bit mask [95:64]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG12 0x57C // 8 Groups of 128-bits CRC Register12
    #define GNICMMIO_PMGBM12 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG12 // 0/x/x/x Pattern Match Group 2 bit mask [127:96]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG13 0x580 // 8 Groups of 128-bits CRC Register13
    #define GNICMMIO_PMGBM13 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG13 // 0/x/x/x Pattern Match Group 3 bit mask [31:0]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG14 0x584 // 8 Groups of 128-bits CRC Register14
    #define GNICMMIO_PMGBM14 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG14 // 0/x/x/x Pattern Match Group 3 bit mask [63:32]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG15 0x588 // 8 Groups of 128-bits CRC Register15
    #define GNICMMIO_PMGBM15 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG15 // 0/x/x/x Pattern Match Group 3 bit mask [95:64]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG16 0x58C // 8 Groups of 128-bits CRC Register16
    #define GNICMMIO_PMGBM16 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG16 // 0/x/x/x Pattern Match Group 3 bit mask [127:96]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG17 0x590 // 8 Groups of 128-bits CRC Register17
    #define GNICMMIO_PMGBM17 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG17 // 0/x/x/x Pattern Match Group 4 bit mask [31:0]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG18 0x594 // 8 Groups of 128-bits CRC Register18
    #define GNICMMIO_PMGBM18 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG18 // 0/x/x/x Pattern Match Group 4 bit mask [63:32]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG19 0x598 // 8 Groups of 128-bits CRC Register19
    #define GNICMMIO_PMGBM19 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG19 // 0/x/x/x Pattern Match Group 4 bit mask [95:64]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG20 0x59C // 8 Groups of 128-bits CRC Register20
    #define GNICMMIO_PMGBM20 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG20 // 0/x/x/x Pattern Match Group 4 bit mask [127:96]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG21 0x5A0 // 8 Groups of 128-bits CRC Register21
    #define GNICMMIO_PMGBM21 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG21 // 0/x/x/x Pattern Match Group 5 bit mask [31:0]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG22 0x5A4 // 8 Groups of 128-bits CRC Register22
    #define GNICMMIO_PMGBM22 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG22 // 0/x/x/x Pattern Match Group 5 bit mask [63:32]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG23 0x5A8 // 8 Groups of 128-bits CRC Register23
    #define GNICMMIO_PMGBM23 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG23 // 0/x/x/x Pattern Match Group 5 bit mask [95:64]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG24 0x5AC // 8 Groups of 128-bits CRC Register24
    #define GNICMMIO_PMGBM24 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG24 // 0/x/x/x Pattern Match Group 5 bit mask [127:96]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG25 0x5B0 // 8 Groups of 128-bits CRC Register25
    #define GNICMMIO_PMGBM25 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG25 // 0/x/x/x Pattern Match Group 6 bit mask [31:0]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG26 0x5B4 // 8 Groups of 128-bits CRC Register26
    #define GNICMMIO_PMGBM26 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG26 // 0/x/x/x Pattern Match Group 6 bit mask [63:32]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG27 0x5B8 // 8 Groups of 128-bits CRC Register27
    #define GNICMMIO_PMGBM27 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG27 // 0/x/x/x Pattern Match Group 6 bit mask [95:64]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG28 0x5BC // 8 Groups of 128-bits CRC Register28
    #define GNICMMIO_PMGBM28 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG28 // 0/x/x/x Pattern Match Group 6 bit mask [127:96]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG29 0x5C0 // 8 Groups of 128-bits CRC Register29
    #define GNICMMIO_PMGBM29 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG29 // 0/x/x/x Pattern Match Group 7 bit mask [31:0]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG30 0x5C4 // 8 Groups of 128-bits CRC Register30
    #define GNICMMIO_PMGBM30 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG30 // 0/x/x/x Pattern Match Group 7 bit mask [63:32]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG31 0x5C8 // 8 Groups of 128-bits CRC Register31
    #define GNICMMIO_PMGBM31 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG31 // 0/x/x/x Pattern Match Group 7 bit mask [95:64]
#define GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG32 0x5CC // 8 Groups of 128-bits CRC Register32
    #define GNICMMIO_PMGBM32 GNICMMIO_8_GRPS_OF_128_BITS_CRC_REG32 // 0/x/x/x Pattern Match Group 7 bit mask [127:96]
#define GNICMMIO_DEBUG_SIGNAL_GRP_SEL 0x5D4 // debug signal group selection
    #define GNICMMIO_DBGSEL 0xFF        // 0/x/x/x DBG_SEL
#define GNICMMIO_INNER_STRAPPING_OPTIONAL_CFG_CTL 0x5D8 // inner strapping / optional configuration control
    #define GNICMMIO_REVOPT     0xF000      // 0/x/x/x Reserved for future use.
    #define GNICMMIO_VSANOPT    BIT11       // 0/x/x/x VLAN + LLC/SNAP option for ARP/NS offload
    #define GNICMMIO_SANOPT     BIT10       // 0/x/x/x LLC/SNAP option for ARP/NS offload
    #define GNICMMIO_VANOPT     BIT9        // 0/x/x/x VLAN option for ARP/NS offload
    #define GNICMMIO_MACMABP    BIT8        // 1b/x/x/x MACMABP
    #define GNICMMIO_IPG2TMHE   BIT3        // 0/x/x/x IPG2TMHE
    #define GNICMMIO_WOLENG     BIT2        // 0/x/x/x WOLENGAT
    #define GNICMMIO_SUSVEES    BIT1        // 0/x/x/x J_VEESEL
    #define GNICMMIO_SUSEFAST   BIT0        // 0/x/x/x J_EEFAST
#define GNICMMIO_DYNAMIC_CLK_CTL 0x5DC // dynamic clock control
    #define GNICMMIO_REFDCKEN   BIT7        // 0/0/x/1 REFDCLK_EN
    #define GNICMMIO_XMDCKEN    BIT6        // 0/0/x/1 XMDCLK_EN
    #define GNICMMIO_EEDCKEN    BIT5        // 0/0/x/1 EEDCLK_EN
    #define GNICMMIO_TXDCLKEN   BIT4        // 0/0/x/1 TXDCLK_EN
    #define GNICMMIO_RXDCLKEN   BIT3        // 0/0/x/1 RXDCLK_EN
    #define GNICMMIO_TMCLKEN    BIT2        // 0/0/x/1 TXDMCLK_EN
    #define GNICMMIO_RMCLKEN    BIT1        // 0/0/x/1 RXDMCLK_EN
    #define GNICMMIO_DMCLKEN    BIT0        // 0/0/x/1 DNDCLK_EN
#define GNICMMIO_DELAY_COMP_SETLECTION 0x5E0 // delay comp setlection
    #define GNICMMIO_DIOTXSEL   0xF0        // 4h/x/x/x dio_tx_sel
    #define GNICMMIO_DIORXSEL   0xF         // 4h/x/x/x dio_rx_sel
#define GNICMMIO_DELAY_COMP_CNTER_0_3 0x5E4 // delay comp counter 0_3
    #define GNICMMIO_DIOCNT3    0xFF000000  // 0/x/x/x dio_cntr3
    #define GNICMMIO_DIOCNT2    0xFF0000    // 0/x/x/x dio_cntr2
    #define GNICMMIO_DIOCNT1    0xFF00      // 0/x/x/x dio_cntr1
    #define GNICMMIO_DIOCNT0    0xFF        // FFh/x/x/x dio_cntr0
#define GNICMMIO_DELAY_COMP_CNTER_4_7 0x5E8 // delay comp counter 4_7
    #define GNICMMIO_DIOCNT7    0xFF000000  // 0/x/x/x dio_cntr7
    #define GNICMMIO_DIOCNT6    0xFF0000    // 0/x/x/x dio_cntr6
    #define GNICMMIO_DIOCNT5    0xFF00      // 0/x/x/x dio_cntr5
    #define GNICMMIO_DIOCNT4    0xFF        // FFh/x/x/x dio_cntr4
#define GNICMMIO_ARP_NS_FEATURE_ENABLE 0x600 // ARP/NS feature enable
    #define GNICMMIO_NSEN   BIT1        // 0/x/x/x NS enable
    #define GNICMMIO_ARPEN  BIT0        // 0/x/x/x Arp enable
#define GNICMMIO_ARP_LOCAL_IPV4_ADR 0x604 // ARP local ipv4 address
    #define GNICMMIO_ARPLCIPA GNICMMIO_ARP_LOCAL_IPV4_ADR // 0/x/x/x Local ipv4 address for arp response
#define GNICMMIO_ARP_REMOTE_IPV4_ADR 0x608 // ARP Remote ipv4 address
    #define GNICMMIO_ARPRMIPA GNICMMIO_ARP_REMOTE_IPV4_ADR // 0/x/x/x Remote ipv4 address for arp response
#define GNICMMIO_NS_REMOTE_IPV6_ADR_BIT_31_TO_0 0x610 // NS remote ipv6 address bit 31 to 0
    #define GNICMMIO_NSRMA0 GNICMMIO_NS_REMOTE_IPV6_ADR_BIT_31_TO_0 // 0/x/x/x Remote ipv6 address [31:0] for NS response
#define GNICMMIO_NS_REMOTE_IPV6_ADR_BIT_63_TO_32 0x614 // NS remote ipv6 address bit 63 to 32
    #define GNICMMIO_NSRMA1 GNICMMIO_NS_REMOTE_IPV6_ADR_BIT_63_TO_32 // 0/x/x/x Remote ipv6 address [63:32] for NS response
#define GNICMMIO_NS_REMOTE_IPV6_ADR_BIT_95_TO_64 0x618 // NS remote ipv6 address bit 95 to 64
    #define GNICMMIO_NSRMA2 GNICMMIO_NS_REMOTE_IPV6_ADR_BIT_95_TO_64 // 0/x/x/x Remote ipv6 address [95:64] for NS response
#define GNICMMIO_NS_REMOTE_IPV6_ADR_BIT_127_TO_96 0x61C // NS remote ipv6 address bit 127 to 96
    #define GNICMMIO_NSRMA3 GNICMMIO_NS_REMOTE_IPV6_ADR_BIT_127_TO_96 // 0/x/x/x Remote ipv6 address [127:96] for NS response
#define GNICMMIO_NS_SOLICITED_IPV6_ADR_0_BIT_31_TO_0 0x620 // NS solicited ipv6 address 0 bit 31 to 0
    #define GNICMMIO_NSSL0A0 GNICMMIO_NS_SOLICITED_IPV6_ADR_0_BIT_31_TO_0 // 0/x/x/x Solicited ipv6 address 0 [31:0] for NS response
#define GNICMMIO_NS_SOLICITED_IPV6_ADR_0_BIT_63_TO_32 0x624 // NS solicited ipv6 address 0 bit 63 to 32
    #define GNICMMIO_NSSL0A1 GNICMMIO_NS_SOLICITED_IPV6_ADR_0_BIT_63_TO_32 // 0/x/x/x Solicited ipv6 address 0 [63:32] for NS response
#define GNICMMIO_NS_SOLICITED_IPV6_ADR_0_BIT_95_TO_64 0x628 // NS solicited ipv6 address 0 bit 95 to 64
    #define GNICMMIO_NSSL0A2 GNICMMIO_NS_SOLICITED_IPV6_ADR_0_BIT_95_TO_64 // 0/x/x/x Solicited ipv6 address 0 [95:64] for NS response
#define GNICMMIO_NS_SOLICITED_IPV6_ADR_0_BIT_127_TO_96 0x62C // NS solicited ipv6 address 0 bit 127 to 96
    #define GNICMMIO_NSSL0A3 GNICMMIO_NS_SOLICITED_IPV6_ADR_0_BIT_127_TO_96 // 0/x/x/x Solicited ipv6 address 0 [127:96] for NS response
#define GNICMMIO_NS_SOLICITED_IPV6_ADR_1_BIT_31_TO_0 0x630 // NS solicited ipv6 address 1 bit 31 to 0
    #define GNICMMIO_NSSL1A0 GNICMMIO_NS_SOLICITED_IPV6_ADR_1_BIT_31_TO_0 // 0/x/x/x Solicited ipv6 address 1 [31:0] for NS response
#define GNICMMIO_NS_SOLICITED_IPV6_ADR_1_BIT_63_TO_32 0x634 // NS solicited ipv6 address 1 bit 63 to 32
    #define GNICMMIO_NSSL1A1 GNICMMIO_NS_SOLICITED_IPV6_ADR_1_BIT_63_TO_32 // 0/x/x/x Solicited ipv6 address 1 [63:32] for NS response
#define GNICMMIO_NS_SOLICITED_IPV6_ADR_1_BIT_95_TO_64 0x638 // NS solicited ipv6 address 1 bit 95 to 64
    #define GNICMMIO_NSSL1A2 GNICMMIO_NS_SOLICITED_IPV6_ADR_1_BIT_95_TO_64 // 0/x/x/x Solicited ipv6 address 1 [95:64] for NS response
#define GNICMMIO_NS_SOLICITED_IPV6_ADR_1_BIT_127_TO_96 0x63C // NS solicited ipv6 address 1 bit 127 to 96
    #define GNICMMIO_NSSL1A3 GNICMMIO_NS_SOLICITED_IPV6_ADR_1_BIT_127_TO_96 // 0/x/x/x Solicited ipv6 address 1 [127:96] for NS response
#define GNICMMIO_NS_TARGET_0_IPV6_ADR_0_BIT_31_TO_0 0x640 // NS target 0 ipv6 address 0 bit 31 to 0
    #define GNICMMIO_NST00A0 GNICMMIO_NS_TARGET_0_IPV6_ADR_0_BIT_31_TO_0 // 0/x/x/x Target 0 ipv6 address 0 [31:0] for NS response
#define GNICMMIO_NS_TARGET_0_IPV6_ADR_0_BIT_63_TO_32 0x644 // NS target 0 ipv6 address 0 bit 63 to 32
    #define GNICMMIO_NST00A1 GNICMMIO_NS_TARGET_0_IPV6_ADR_0_BIT_63_TO_32 // 0/x/x/x Target 0 ipv6 address 0 [63:32] for NS response
#define GNICMMIO_NS_TARGET_0_IPV6_ADR_0_BIT_95_TO_64 0x648 // NS target 0 ipv6 address 0 bit 95 to 64
    #define GNICMMIO_NST00A2 GNICMMIO_NS_TARGET_0_IPV6_ADR_0_BIT_95_TO_64 // 0/x/x/x Target 0 ipv6 address 0 [95:64] for NS response
#define GNICMMIO_NS_TARGET_0_IPV6_ADR_0_BIT_127_TO_96 0x64C // NS target 0 ipv6 address 0 bit 127 to 96
    #define GNICMMIO_NST00A3 GNICMMIO_NS_TARGET_0_IPV6_ADR_0_BIT_127_TO_96 // 0/x/x/x Target 0 ipv6 address 0 [127:96] for NS response
#define GNICMMIO_NS_TARGET_0_IPV6_ADR_1_BIT_31_TO_0 0x650 // NS target 0 ipv6 address 1 bit 31 to 0
    #define GNICMMIO_NST01A0 GNICMMIO_NS_TARGET_0_IPV6_ADR_1_BIT_31_TO_0 // 0/x/x/x Target 0 ipv6 address 1 [31:0] for NS response
#define GNICMMIO_NS_TARGET_0_IPV6_ADR_1_BIT_63_TO_32 0x654 // NS target 0 ipv6 address 1 bit 63 to 32
    #define GNICMMIO_NST01A1 GNICMMIO_NS_TARGET_0_IPV6_ADR_1_BIT_63_TO_32 // 0/x/x/x Target 0 ipv6 address 1 [63:32] for NS response
#define GNICMMIO_NS_TARGET_0_IPV6_ADR_1_BIT_95_TO_64 0x658 // NS target 0 ipv6 address 1 bit 95 to 64
    #define GNICMMIO_NST01A2 GNICMMIO_NS_TARGET_0_IPV6_ADR_1_BIT_95_TO_64 // 0/x/x/x Target 0 ipv6 address 1 [95:64] for NS response
#define GNICMMIO_NS_TARGET_0_IPV6_ADR_1_BIT_127_TO_96 0x65C // NS target 0 ipv6 address 1 bit 127 to 96
    #define GNICMMIO_NST01A3 GNICMMIO_NS_TARGET_0_IPV6_ADR_1_BIT_127_TO_96 // 0/x/x/x Target 0 ipv6 address 1 [127:96] for NS response
#define GNICMMIO_NS_TARGET_1_IPV6_ADR_0_BIT_31_TO_0 0x660 // NS target 1 ipv6 address 0 bit 31 to 0
    #define GNICMMIO_NST10A0 GNICMMIO_NS_TARGET_1_IPV6_ADR_0_BIT_31_TO_0 // 0/x/x/x Target 1 ipv6 address 0 [31:0] for NS response
#define GNICMMIO_NS_TARGET_1_IPV6_ADR_0_BIT_63_TO_32 0x664 // NS target 1 ipv6 address 0 bit 63 to 32
    #define GNICMMIO_NST10A1 GNICMMIO_NS_TARGET_1_IPV6_ADR_0_BIT_63_TO_32 // 0/x/x/x Target 1 ipv6 address 0 [63:32] for NS response
#define GNICMMIO_NS_TARGET_1_IPV6_ADR_0_BIT_95_TO_64 0x668 // NS target 1 ipv6 address 0 bit 95 to 64
    #define GNICMMIO_NST10A2 GNICMMIO_NS_TARGET_1_IPV6_ADR_0_BIT_95_TO_64 // 0/x/x/x Target 1 ipv6 address 0 [95:64] for NS response
#define GNICMMIO_NS_TARGET_1_IPV6_ADR_0_BIT_127_TO_96 0x66C // NS target 1 ipv6 address 0 bit 127 to 96
    #define GNICMMIO_NST10A3 GNICMMIO_NS_TARGET_1_IPV6_ADR_0_BIT_127_TO_96 // 0/x/x/x Target 1 ipv6 address 0 [127:96] for NS response
#define GNICMMIO_NS_TARGET_1_IPV6_ADR_1_BIT_31_TO_0 0x670 // NS target 1 ipv6 address 1 bit 31 to 0
    #define GNICMMIO_NST11A0 GNICMMIO_NS_TARGET_1_IPV6_ADR_1_BIT_31_TO_0 // 0/x/x/x Target 1 ipv6 address 1 [31:0] for NS response
#define GNICMMIO_NS_TARGET_1_IPV6_ADR_1_BIT_63_TO_32 0x674 // NS target 1 ipv6 address 1 bit 63 to 32
    #define GNICMMIO_NST11A1 GNICMMIO_NS_TARGET_1_IPV6_ADR_1_BIT_63_TO_32 // 0/x/x/x Target 1 ipv6 address 1 [63:32] for NS response
#define GNICMMIO_NS_TARGET_1_IPV6_ADR_1_BIT_95_TO_64 0x678 // NS target 1 ipv6 address 1 bit 95 to 64
    #define GNICMMIO_NST11A2 GNICMMIO_NS_TARGET_1_IPV6_ADR_1_BIT_95_TO_64 // 0/x/x/x Target 1 ipv6 address 1 [95:64] for NS response
#define GNICMMIO_NS_TARGET_1_IPV6_ADR_1_BIT_127_TO_96 0x67C // NS target 1 ipv6 address 1 bit 127 to 96
    #define GNICMMIO_NST11A3 GNICMMIO_NS_TARGET_1_IPV6_ADR_1_BIT_127_TO_96 // 0/x/x/x Target 1 ipv6 address 1 [127:96] for NS response
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG0 0x700 // RSS Random Key Shadow Register0
    #define GNICMMIO_RSSK_SDB3  0xFF000000  // DAh/x/x/x Receive Side Scaling Random Key K[3]
    #define GNICMMIO_RSSK_SDB2  0xFF0000    // 56h/x/x/x Receive Side Scaling Random Key K[2]
    #define GNICMMIO_RSSK_SDB1  0xFF00      // 5Ah/x/x/x Receive Side Scaling Random Key K[1]
    #define GNICMMIO_RSSK_SDB0  0xFF        // 6Dh/x/x/x Receive Side Scaling Random Key K[0]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG1 0x704 // RSS Random Key Shadow Register1
    #define GNICMMIO_RSSK_SDB7  0xFF000000  // C2h/x/x/x Receive Side Scaling Random Key K[7]
    #define GNICMMIO_RSSK_SDB6  0xFF0000    // 0Eh/x/x/x Receive Side Scaling Random Key K[6]
    #define GNICMMIO_RSSK_SDB5  0xFF00      // 5Bh/x/x/x Receive Side Scaling Random Key K[5]
    #define GNICMMIO_RSSK_SDB4  0xFF        // 25h/x/x/x Receive Side Scaling Random Key K[4]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG2 0x708 // RSS Random Key Shadow Register2
    #define GNICMMIO_RSSK_SDB11 0xFF000000  // 3Dh/x/x/x Receive Side Scaling Random Key K[11]
    #define GNICMMIO_RSSK_SDB10 0xFF0000    // 25h/x/x/x Receive Side Scaling Random Key K[10]
    #define GNICMMIO_RSSK_SDB9  0xFF00      // 67h/x/x/x Receive Side Scaling Random Key K[9]
    #define GNICMMIO_RSSK_SDB8  0xFF        // 41h/x/x/x Receive Side Scaling Random Key K[8]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG3 0x70C // RSS Random Key Shadow Register3
    #define GNICMMIO_RSSK_SDB15 0xFF000000  // B0h/x/x/x Receive Side Scaling Random Key K[15]
    #define GNICMMIO_RSSK_SDB14 0xFF0000    // 8Fh/x/x/x Receive Side Scaling Random Key K[14]
    #define GNICMMIO_RSSK_SDB13 0xFF00      // A3h/x/x/x Receive Side Scaling Random Key K[13]
    #define GNICMMIO_RSSK_SDB12 0xFF        // 43h/x/x/x Receive Side Scaling Random Key K[12]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG4 0x710 // RSS Random Key Shadow Register4
    #define GNICMMIO_RSSK_SDB19 0xFF000000  // CBh/x/x/x Receive Side Scaling Random Key K[19]
    #define GNICMMIO_RSSK_SDB18 0xFF0000    // 2Bh/x/x/x Receive Side Scaling Random Key K[18]
    #define GNICMMIO_RSSK_SDB17 0xFF00      // CAh/x/x/x Receive Side Scaling Random Key K[17]
    #define GNICMMIO_RSSK_SDB16 0xFF        // D0h/x/x/x Receive Side Scaling Random Key K[16]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG5 0x714 // RSS Random Key Shadow Register5
    #define GNICMMIO_RSSK_SDB23 0xFF000000  // B4h/x/x/x Receive Side Scaling Random Key K[23]
    #define GNICMMIO_RSSK_SDB22 0xFF0000    // 30h/x/x/x Receive Side Scaling Random Key K[22]
    #define GNICMMIO_RSSK_SDB21 0xFF00      // 7Bh/x/x/x Receive Side Scaling Random Key K[21]
    #define GNICMMIO_RSSK_SDB20 0xFF        // AEh/x/x/x Receive Side Scaling Random Key K[20]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG6 0x718 // RSS Random Key Shadow Register6
    #define GNICMMIO_RSSK_SDB27 0xFF000000  // A3h/x/x/x Receive Side Scaling Random Key K[27]
    #define GNICMMIO_RSSK_SDB26 0xFF0000    // 2Dh/x/x/x Receive Side Scaling Random Key K[26]
    #define GNICMMIO_RSSK_SDB25 0xFF00      // CBh/x/x/x Receive Side Scaling Random Key K[25]
    #define GNICMMIO_RSSK_SDB24 0xFF        // 77h/x/x/x Receive Side Scaling Random Key K[24]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG7 0x71C // RSS Random Key Shadow Register7
    #define GNICMMIO_RSSK_SDB31 0xFF000000  // 0Ch/x/x/x Receive Side Scaling Random Key K[31]
    #define GNICMMIO_RSSK_SDB30 0xFF0000    // F2h/x/x/x Receive Side Scaling Random Key K[30]
    #define GNICMMIO_RSSK_SDB29 0xFF00      // 30h/x/x/x Receive Side Scaling Random Key K[29]
    #define GNICMMIO_RSSK_SDB28 0xFF        // 80h/x/x/x Receive Side Scaling Random Key K[28]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG8 0x720 // RSS Random Key Shadow Register8
    #define GNICMMIO_RSSK_SDB35 0xFF000000  // 3Bh/x/x/x Receive Side Scaling Random Key K[35]
    #define GNICMMIO_RSSK_SDB34 0xFF0000    // B7h/x/x/x Receive Side Scaling Random Key K[34]
    #define GNICMMIO_RSSK_SDB33 0xFF00      // 42h/x/x/x Receive Side Scaling Random Key K[33]
    #define GNICMMIO_RSSK_SDB32 0xFF        // 6Ah/x/x/x Receive Side Scaling Random Key K[32]
#define GNICMMIO_RSS_RANDOM_KEY_SHADOW_REG9 0x724 // RSS Random Key Shadow Register9
    #define GNICMMIO_RSSK_SDB39 0xFF000000  // FAh/x/x/x Receive Side Scaling Random Key K[39]
    #define GNICMMIO_RSSK_SDB38 0xFF0000    // 01h/x/x/x Receive Side Scaling Random Key K[38]
    #define GNICMMIO_RSSK_SDB37 0xFF00      // ACh/x/x/x Receive Side Scaling Random Key K[37]
    #define GNICMMIO_RSSK_SDB36 0xFF        // BEh/x/x/x Receive Side Scaling Random Key K[36]
#define GNICMMIO_RECEIVE_SIDE_SCALING_CMD_SHADOW_REG 0x728 // Receive Side Scaling Command Shadow Register
    #define GNICMMIO_SDMRQE (BIT30 + BIT31)         // 0/x/x/x Receive Side Scaling Function Shadow Enable
    #define GNICMMIO_SDHFTP 0x3F000000              // 0/x/x/x The usage of Hash Functions could be controlled by these bits. If set...
    #define GNICMMIO_SDITI  (BIT13 + BIT14 + BIT15) // 0/x/x/x Indirection Table Index
    #define GNICMMIO_RSS_SL BIT0                    // 0/x/x/x RSS Select Register
#define GNICMMIO_INTR_STA_ISR4_ISR5_ISR6 0x750 // Interrupt Status (ISR4, ISR5, ISR6)
    #define GNICMMIO_ISRNEW6    BIT31                   // 0/R/x/x Interrupt Source indication.( ISR6)
    #define GNICMMIO_ISRNEW5    BIT30                   // 0/R/x/x Interrupt Source indication.( ISR5)
    #define GNICMMIO_ISRNEW4    BIT29                   // 0/R/x/x Interrupt Source indication.( ISR4)
    #define GNICMMIO_LSTPE3I    BIT20                   // 0/x/x/x RD3 List is using up warning. write ?1? will clear this bit , write ?...
    #define GNICMMIO_PRX3I      BIT19                   // 0/x/x/x Receive service complete status in RD queue 3.
    #define GNICMMIO_LSTE3I     BIT18                   // 0/x/x/x Receive descriptor3 (RD3) is used up.
    #define GNICMMIO_PPRX3I     BIT17                   // 0/x/x/x Queue 3 High priority receive interrupt service request. PRX3I will a...
    #define GNICMMIO_RXSTL3I    BIT16                   // 0/R/x/x Receive DMA stall in RXE_SR
    #define GNICMMIO_LSTPE2I    BIT12                   // 0/x/x/x RD2 List is using up warning. write ?1? will clear this bit , write ?...
    #define GNICMMIO_PRX2I      BIT11                   // 0/x/x/x Receive service complete status in RD queue 2.
    #define GNICMMIO_LSTE2I     BIT10                   // 0/x/x/x Receive descriptor2 (RD2) is used up.
    #define GNICMMIO_PPRX2I     BIT9                    // 0/x/x/x Queue 2 High priority receive interrupt service request. PRX2I will a...
    #define GNICMMIO_RXSTL2I    BIT8                    // 0/R/x/x Receive DMA stall in RXE_SR
    #define GNICMMIO_LSTPE1I    BIT4                    // 0/x/x/x RD1 List is using up warning. write ?1? will clear this bit , write ?...
    #define GNICMMIO_PRX1I      BIT3                    // 0/x/x/x Receive service complete status in RD queue 1.
    #define GNICMMIO_LSTE1I     BIT2                    // 0/x/x/x Receive descriptor1 (RD1) is used up.
    #define GNICMMIO_PPRX1I     BIT1                    // 0/x/x/x Queue 1 High priority receive interrupt service request. PRX1I will a...
    #define GNICMMIO_RXSTL1I    BIT0                    // 0/R/x/x Receive DMA stall in RXE_SR
#define GNICMMIO_INTR_STA_ISR7_ISR8_ISR9 0x754 // Interrupt Status (ISR7, ISR8, ISR9)
    #define GNICMMIO_ISRNEW9    BIT31                   // 0/R/x/x Interrupt Source indication.( ISR9)
    #define GNICMMIO_ISRNEW8    BIT30                   // 0/R/x/x Interrupt Source indication.( ISR8)
    #define GNICMMIO_ISRNEW7    BIT29                   // 0/R/x/x Interrupt Source indication.( ISR7)
    #define GNICMMIO_LSTPE6I    BIT20                   // 0/x/x/x RD6 List is using up warning. write ?1? will clear this bit , write ?...
    #define GNICMMIO_PRX6I      BIT19                   // 0/x/x/x Receive service complete status in RD queue 6.
    #define GNICMMIO_LSTE6I     BIT18                   // 0/x/x/x Receive descriptor6 (RD6) is used up.
    #define GNICMMIO_PPRX6I     BIT17                   // 0/x/x/x Queue 6 High priority receive interrupt service request. PRX6I will a...
    #define GNICMMIO_RXSTL6I    BIT16                   // 0/R/x/x Receive DMA stall in RXE_SR
    #define GNICMMIO_LSTPE5I    BIT12                   // 0/x/x/x RD5 List is using up warning. write ?1? will clear this bit , write ?...
    #define GNICMMIO_PRX5I      BIT11                   // 0/x/x/x Receive service complete status in RD queue 5.
    #define GNICMMIO_LSTE5I     BIT10                   // 0/x/x/x Receive descriptor5 (RD5) is used up.
    #define GNICMMIO_PPRX5I     BIT9                    // 0/x/x/x Queue 5 High priority receive interrupt service request. PRX5I will a...
    #define GNICMMIO_RXSTL5I    BIT8                    // 0/R/x/x Receive DMA stall in RXE_SR
    #define GNICMMIO_LSTPE4I    BIT4                    // 0/x/x/x RD4 List is using up warning. write ?1? will clear this bit , write ?...
    #define GNICMMIO_PRX4I      BIT3                    // 0/x/x/x Receive service complete status in RD queue 4.
    #define GNICMMIO_LSTE4I     BIT2                    // 0/x/x/x Receive descriptor4 (RD4) is used up.
    #define GNICMMIO_PPRX4I     BIT1                    // 0/x/x/x Queue 4 High priority receive interrupt service request. PRX4I will a...
    #define GNICMMIO_RXSTL4I    BIT0                    // 0/R/x/x Receive DMA stall in RXE_SR
#define GNICMMIO_INTR_STA_ISR10 0x758 // Interrupt Status (ISR10)
    #define GNICMMIO_ISRNEW10   BIT31       // 0/R/x/x Interrupt Source indication.( ISR10)
    #define GNICMMIO_LSTPE7I    BIT4        // 0/x/x/x RD7 List is using up warning. write ?1? will clear this bit , write ?...
    #define GNICMMIO_PRX7I      BIT3        // 0/x/x/x Receive service complete status in RD queue 7.
    #define GNICMMIO_LSTE7I     BIT2        // 0/x/x/x Receive descriptor7 (RD7) is used up.
    #define GNICMMIO_PPRX7I     BIT1        // 0/x/x/x Queue 7 High priority receive interrupt service request. PRX7I will a...
    #define GNICMMIO_RXSTL7I    BIT0        // 0/R/x/x Receive DMA stall in RXE_SR
#define GNICMMIO_INTR_ENABLE_REG_MASK_IMR4_IMR5_IMR6 0x75C // Interrupt Enable Register(Mask) (IMR4 IMR5 IMR6)
    #define GNICMMIO_IMR1 GNICMMIO_INTR_ENABLE_REG_MASK_IMR4_IMR5_IMR6 // 0/x/x/x Interrupt source enable control, it is mapping to Rx753-750[31:0].
#define GNICMMIO_INTR_ENABLE_REG_MASK_IMR7_IMR8_IMR9 0x760 // Interrupt Enable Register(Mask) (IMR7 IMR8 IMR9)
    #define GNICMMIO_IMR2 GNICMMIO_INTR_ENABLE_REG_MASK_IMR7_IMR8_IMR9 // 0/x/x/x Interrupt source enable control, it is mapping to Rx757-754[31:0].
#define GNICMMIO_INTR_ENABLE_REG_MASK_IMR10 0x764 // Interrupt Enable Register(Mask) (IMR10)
    #define GNICMMIO_IMR3 GNICMMIO_INTR_ENABLE_REG_MASK_IMR10 // 0/x/x/x Interrupt source enable control, it is mapping to Rx75B-758[31:0].
#define GNICMMIO_INTR_ENABLE_CLEAR_REG_MASK_IMR4C_IMR5C_IMR6C 0x768 // Interrupt Enable Clear Register(Mask) (IMR4c IMR5c IMR6c)
    #define GNICMMIO_IMR1C GNICMMIO_INTR_ENABLE_CLEAR_REG_MASK_IMR4C_IMR5C_IMR6C // 0/x/x/x Clear Interrupt source enable control bit, it is mapping to Rx753-750...
#define GNICMMIO_INTR_ENABLE_CLEAR_REG_MASK_IMR7C_IMR8C_IMR9C 0x76C // Interrupt Enable Clear Register(Mask) (IMR7c IMR8c IMR9c)
    #define GNICMMIO_IMR2C GNICMMIO_INTR_ENABLE_CLEAR_REG_MASK_IMR7C_IMR8C_IMR9C // 0/x/x/x Clear Interrupt source enable control bit, it is mapping to Rx757-754...
#define GNICMMIO_INTR_ENABLE_CLEAR_REG_MASK_IMR10C 0x770 // Interrupt Enable Clear Register(Mask) (IMR10c)
    #define GNICMMIO_IMR3C GNICMMIO_INTR_ENABLE_CLEAR_REG_MASK_IMR10C // 0/x/x/x Clear Interrupt source enable control bit, it is mapping to Rx75B-758...
#define GNICMMIO_INTR_CTL_REG_RX_QUEUE1_7RXE_SR 0x774 // Interrupt Control Register(rx queue1~7RXE_SR)
    #define GNICMMIO_RFDBS7 BIT27       // 0/0/x/x Rx queue7 FIFO DMA experience Host bus error. Write 1 clear the bit. ...
    #define GNICMMIO_RDWBS7 BIT26       // 0/0/x/x RD queue7 write back host bus Error. Write 1 clear the bit. Write 0 r...
    #define GNICMMIO_RDRBS7 BIT25       // 0/0/x/x RD queue7 Fetch host bus Error. Write 1 clear the bit. Write 0 remain...
    #define GNICMMIO_RDSTR7 BIT24       // 0/0/x/x RD queue7 structure Error. Write 1 clear the bit. Write 0 remain unch...
    #define GNICMMIO_RFDBS6 BIT23       // 0/0/x/x Rx queue6 FIFO DMA experience Host bus error. Write 1 clear the bit. ...
    #define GNICMMIO_RDWBS6 BIT22       // 0/0/x/x RD queue6 write back host bus Error. Write 1 clear the bit. Write 0 r...
    #define GNICMMIO_RDRBS6 BIT21       // 0/0/x/x RD queue6 Fetch host bus Error. Write 1 clear the bit. Write 0 remain...
    #define GNICMMIO_RDSTR6 BIT20       // 0/0/x/x RD queue6 structure Error. Write 1 clear the bit. Write 0 remain unch...
    #define GNICMMIO_RFDBS5 BIT19       // 0/0/x/x Rx queue5 FIFO DMA experience Host bus error. Write 1 clear the bit. ...
    #define GNICMMIO_RDWBS5 BIT18       // 0/0/x/x RD queue5 write back host bus Error. Write 1 clear the bit. Write 0 r...
    #define GNICMMIO_RDRBS5 BIT17       // 0/0/x/x RD queue5 Fetch host bus Error. Write 1 clear the bit. Write 0 remain...
    #define GNICMMIO_RDSTR5 BIT16       // 0/0/x/x RD queue5 structure Error. Write 1 clear the bit. Write 0 remain unch...
    #define GNICMMIO_RFDBS4 BIT15       // 0/0/x/x Rx queue4 FIFO DMA experience Host bus error. Write 1 clear the bit. ...
    #define GNICMMIO_RDWBS4 BIT14       // 0/0/x/x RD queue4 write back host bus Error. Write 1 clear the bit. Write 0 r...
    #define GNICMMIO_RDRBS4 BIT13       // 0/0/x/x RD queue4 Fetch host bus Error. Write 1 clear the bit. Write 0 remain...
    #define GNICMMIO_RDSTR4 BIT12       // 0/0/x/x RD queue4 structure Error. Write 1 clear the bit. Write 0 remain unch...
    #define GNICMMIO_RFDBS3 BIT11       // 0/0/x/x Rx queue3 FIFO DMA experience Host bus error. Write 1 clear the bit. ...
    #define GNICMMIO_RDWBS3 BIT10       // 0/0/x/x RD queue3 write back host bus Error. Write 1 clear the bit. Write 0 r...
    #define GNICMMIO_RDRBS3 BIT9        // 0/0/x/x RD queue3 Fetch host bus Error. Write 1 clear the bit. Write 0 remain...
    #define GNICMMIO_RDSTR3 BIT8        // 0/0/x/x RD queue3 structure Error. Write 1 clear the bit. Write 0 remain unch...
    #define GNICMMIO_RFDBS2 BIT7        // 0/0/x/x Rx queue2 FIFO DMA experience Host bus error. Write 1 clear the bit. ...
    #define GNICMMIO_RDWBS2 BIT6        // 0/0/x/x RD queue2 write back host bus Error. Write 1 clear the bit. Write 0 r...
    #define GNICMMIO_RDRBS2 BIT5        // 0/0/x/x RD queue2 Fetch host bus Error. Write 1 clear the bit. Write 0 remain...
    #define GNICMMIO_RDSTR2 BIT4        // 0/0/x/x RD queue2 structure Error. Write 1 clear the bit. Write 0 remain unch...
    #define GNICMMIO_RFDBS1 BIT3        // 0/0/x/x Rx queue1 FIFO DMA experience Host bus error. Write 1 clear the bit. ...
    #define GNICMMIO_RDWBS1 BIT2        // 0/0/x/x RD queue1 write back host bus Error. Write 1 clear the bit. Write 0 r...
    #define GNICMMIO_RDRBS1 BIT1        // 0/0/x/x RD queue1 Fetch host bus Error. Write 1 clear the bit. Write 0 remain...
    #define GNICMMIO_RDSTR1 BIT0        // 0/0/x/x RD queue1 structure Error. Write 1 clear the bit. Write 0 remain unch...
#define GNICMMIO_INTERNAL_FUNAL_CTL_REGS 0x7D8 // Internal functional control registers
    #define GNICMMIO_MSIXRDS    BIT16       // 1b/1/x/x SW reset DO NOT clear MSI-X registers control bit.
#define GNICMMIO_DATA_PATH_DELAY_INNER_CTL 0x7E0 // data path delay inner control
    #define GNICMMIO_TFLTC3 0xF00       // 0111b/x/x/x Reserved
    #define GNICMMIO_TFLTC2 0xF0        // 0111b/x/x/x Reserved
    #define GNICMMIO_TFLTC1 0xF         // 0111b/x/x/x Reserved
#define GNICMMIO_MAX_PAYLOAD_SIZE_AND_MAX_RD_REQ_SIZE_INNER_CTL 0x7E4 // max payload size and max rd req size inner control
    #define GNICMMIO_FCMRPS BIT8                    // 0/x/x/x FC_MRS_MPS.
    #define GNICMMIO_MRSCAP (BIT3 + BIT4 + BIT5)    // 0/x/x/x MRS_CAP
    #define GNICMMIO_MPSCAP (BIT0 + BIT1 + BIT2)    // 0/x/x/x MPS_CAP
#define GNICMMIO_TEST_USE_ONLY_0 0x7F0 // test use only 0
    #define GNICMMIO_GNICTST0 GNICMMIO_TEST_USE_ONLY_0 // 0/x/x/x For test 0
#define GNICMMIO_TEST_USE_ONLY_1 0x7F4 // test use only 1
    #define GNICMMIO_GNICTST1 GNICMMIO_TEST_USE_ONLY_1 // 0/x/x/x For test 1
#define GNICMMIO_TEST_USE_ONLY_2 0x7F8 // test use only 2
    #define GNICMMIO_GNICTST2 GNICMMIO_TEST_USE_ONLY_2 // 0/x/x/x For test 2
#define GNICMMIO_TEST_USE_ONLY_3 0x7FC // test use only 3
    #define GNICMMIO_GNICTST3 GNICMMIO_TEST_USE_ONLY_3 // 0/x/x/x For test 3
// GNIC_MSI-X
#define GNICMSIX_MSI_X_ENTRY0_LOW_ADR 0x0 // MSI-X Entry0 Low Address
    #define GNICMSIX_ENT0LA 0xFFFFFFFC      // 0/x/x/x MSI-X entry0 Low Address System-specified message high address
#define GNICMSIX_MSI_X_ENTRY0_HIGH_ADR 0x4 // MSI-X Entry0 High Address
    #define GNICMSIX_ENT0HA GNICMSIX_MSI_X_ENTRY0_HIGH_ADR // 0/x/x/x MSI-X entry0 High Address system-specified message high address
#define GNICMSIX_MSI_X_ENTRY0_DATA_REG 0x8 // MSI-X Entry0 Data Register
    #define GNICMSIX_ENT0D GNICMSIX_MSI_X_ENTRY0_DATA_REG // 0/x/x/x MSI-X entry0 Data Register System-specified message data.
#define GNICMSIX_MSI_X_ENTRY0_VECTOR_CTL_REG 0xC // MSI-X Entry0 Vector Control Register
    #define GNICMSIX_ENT0M  BIT0        // 0/x/x/x MSI-X entry0 Mask bit
#define GNICMSIX_MSI_X_ENTRY1_LOW_ADR 0x10 // MSI-X Entry1 Low Address
    #define GNICMSIX_ENT1LA 0xFFFFFFFC      // 0/x/x/x MSI-X entry1 Low Address System-specified message high address
#define GNICMSIX_MSI_X_ENTRY1_HIGH_ADR 0x14 // MSI-X Entry1 High Address
    #define GNICMSIX_ENT1HA GNICMSIX_MSI_X_ENTRY1_HIGH_ADR // 0/x/x/x MSI-X entry1 High Address system-specified message high address
#define GNICMSIX_MSI_X_ENTRY1_DATA_REG 0x18 // MSI-X Entry1 Data Register
    #define GNICMSIX_ENT1D GNICMSIX_MSI_X_ENTRY1_DATA_REG // 0/x/x/x MSI-X entry1 Data Register System-specified message data.
#define GNICMSIX_MSI_X_ENTRY1_VECTOR_CTL_REG 0x1C // MSI-X Entry1 Vector Control Register
    #define GNICMSIX_ENT1M  BIT0        // 0/x/x/x MSI-X entry1 Mask bit
#define GNICMSIX_MSI_X_ENTRY2_LOW_ADR 0x20 // MSI-X Entry2 Low Address
    #define GNICMSIX_ENT2LA 0xFFFFFFFC      // 0/x/x/x MSI-X entry2 Low Address System-specified message high address
#define GNICMSIX_MSI_X_ENTRY2_HIGH_ADR 0x24 // MSI-X Entry2 High Address
    #define GNICMSIX_ENT2HA GNICMSIX_MSI_X_ENTRY2_HIGH_ADR // 0/x/x/x MSI-X entry2 High Address system-specified message high address
#define GNICMSIX_MSI_X_ENTRY2_DATA_REG 0x28 // MSI-X Entry2 Data Register
    #define GNICMSIX_ENT2D GNICMSIX_MSI_X_ENTRY2_DATA_REG // 0/x/x/x MSI-X entry2 Data Register System-specified message data.
#define GNICMSIX_MSI_X_ENTRY2_VECTOR_CTL_REG 0x2C // MSI-X Entry2 Vector Control Register
    #define GNICMSIX_ENT2M  BIT0        // 0/x/x/x MSI-X entry2 Mask bit
#define GNICMSIX_MSI_X_ENTRY3_LOW_ADR 0x30 // MSI-X Entry3 Low Address
    #define GNICMSIX_MSIXLA 0xFFFFFFFC      // 0/x/x/x MSI-X entry3 Low Address System-specified message high address
#define GNICMSIX_MSI_X_ENTRY3_HIGH_ADR 0x34 // MSI-X Entry3 High Address
    #define GNICMSIX_ENT3HA GNICMSIX_MSI_X_ENTRY3_HIGH_ADR // 0/x/x/x MSI-X entry3 High Address system-specified message high address
#define GNICMSIX_MSI_X_ENTRY3_DATA_REG 0x38 // MSI-X Entry3 Data Register
    #define GNICMSIX_ENT3D GNICMSIX_MSI_X_ENTRY3_DATA_REG // 0/x/x/x MSI-X entry3 Data Register System-specified message data.
#define GNICMSIX_MSI_X_ENTRY3_VECTOR_CTL_REG 0x3C // MSI-X Entry3 Vector Control Register
    #define GNICMSIX_ENT3M  BIT0        // 0/x/x/x MSI-X entry3 Mask bit
#define GNICMSIX_MSI_X_ENTRY4_LOW_ADR 0x40 // MSI-X Entry4 Low Address
    #define GNICMSIX_ENT4LA 0xFFFFFFFC      // 0/x/x/x MSI-X entry4 Low Address System-specified message high address
#define GNICMSIX_MSI_X_ENTRY4_HIGH_ADR 0x44 // MSI-X Entry4 High Address
    #define GNICMSIX_ENT4HA GNICMSIX_MSI_X_ENTRY4_HIGH_ADR // 0/x/x/x MSI-X entry4 High Address system-specified message high address
#define GNICMSIX_MSI_X_ENTRY4_DATA_REG 0x48 // MSI-X Entry4 Data Register
    #define GNICMSIX_ENT4D GNICMSIX_MSI_X_ENTRY4_DATA_REG // 0/x/x/x MSI-X entry4 Data Register System-specified message data.
#define GNICMSIX_MSI_X_ENTRY4_VECTOR_CTL_REG 0x4C // MSI-X Entry4 Vector Control Register
    #define GNICMSIX_ENT4M  BIT0        // 0/x/x/x MSI-X entry4 Mask bit
#define GNICMSIX_MSI_X_ENTRY5_LOW_ADR 0x50 // MSI-X Entry5 Low Address
    #define GNICMSIX_ENT5LA 0xFFFFFFFC      // 0/x/x/x MSI-X entry5 Low Address System-specified message high address
#define GNICMSIX_MSI_X_ENTRY5_HIGH_ADR 0x54 // MSI-X Entry5 High Address
    #define GNICMSIX_ENT5HA GNICMSIX_MSI_X_ENTRY5_HIGH_ADR // 0/x/x/x MSI-X entry5 High Address system-specified message high address
#define GNICMSIX_MSI_X_ENTRY5_DATA_REG 0x58 // MSI-X Entry5 Data Register
    #define GNICMSIX_ENT5D GNICMSIX_MSI_X_ENTRY5_DATA_REG // 0/x/x/x MSI-X entry5 Data Register System-specified message data.
#define GNICMSIX_MSI_X_ENTRY5_VECTOR_CTL_REG 0x5C // MSI-X Entry5 Vector Control Register
    #define GNICMSIX_ENT5M  BIT0        // 0/x/x/x MSI-X entry5 Mask bit
#define GNICMSIX_MSI_X_ENTRY6_LOW_ADR 0x60 // MSI-X Entry6 Low Address
    #define GNICMSIX_ENT6LA 0xFFFFFFFC      // 0/x/x/x MSI-X entry6 Low Address System-specified message high address
#define GNICMSIX_MSI_X_ENTRY6_HIGH_ADR 0x64 // MSI-X Entry6 High Address
    #define GNICMSIX_ENT6HA GNICMSIX_MSI_X_ENTRY6_HIGH_ADR // 0/x/x/x MSI-X entry6 High Address system-specified message high address
#define GNICMSIX_MSI_X_ENTRY6_DATA_REG 0x68 // MSI-X Entry6 Data Register
    #define GNICMSIX_ENT6D GNICMSIX_MSI_X_ENTRY6_DATA_REG // 0/x/x/x MSI-X entry6 Data Register System-specified message data.
#define GNICMSIX_MSI_X_ENTRY6_VECTOR_CTL_REG 0x6C // MSI-X Entry6 Vector Control Register
    #define GNICMSIX_ENT6M  BIT0        // 0/x/x/x MSI-X entry6 Mask bit
#define GNICMSIX_MSI_X_ENTRY7_LOW_ADR 0x70 // MSI-X Entry7 Low Address
    #define GNICMSIX_ENT7LA 0xFFFFFFFC      // 0/x/x/x MSI-X entry7 Low Address System-specified message high address
#define GNICMSIX_MSI_X_ENTRY7_HIGH_ADR 0x74 // MSI-X Entry7 High Address
    #define GNICMSIX_ENT7HA GNICMSIX_MSI_X_ENTRY7_HIGH_ADR // 0/x/x/x MSI-X entry7 High Address system-specified message high address
#define GNICMSIX_MSI_X_ENTRY7_DATA_REG 0x78 // MSI-X Entry7 Data Register
    #define GNICMSIX_ENT7D GNICMSIX_MSI_X_ENTRY7_DATA_REG // 0/x/x/x MSI-X entry7 Data Register System-specified message data.
#define GNICMSIX_MSI_X_ENTRY7_VECTOR_CTL_REG 0x7C // MSI-X Entry7 Vector Control Register
    #define GNICMSIX_ENT7M  BIT0        // 0/x/x/x MSI-X entry7 Mask bit
#define GNICMSIX_MSI_X_PENDING_BIT_REG 0x1000 // MSI-X Pending Bit Register
    #define GNICMSIX_MSIXPB 0xFF        // 0/x/x/x Pending Bits
#define GNICMSIX_MSI_X_PENDING_BIT_REG_Z1 0x1004 // MSI-X Pending Bit Register
// GNIC_IO
#define GNICIO_IO_SPACE_REG 0x0 // IO Space Register
    #define GNICIO_IOADDR GNICIO_IO_SPACE_REG // 0/x/x/x Index port register.
#define GNICIO_IO_WRITE_DATA_REG 0x4 // IO Write Data Register
    #define GNICIO_IOWDATA GNICIO_IO_WRITE_DATA_REG // 0/x/x/x Write Data Port. 
#define GNICIO_IO_READ_DATA_REG 0x8 // IO Read Data Register
    #define GNICIO_IORDATA GNICIO_IO_READ_DATA_REG // 0/x/x/x Read Data Port. 
#define GNICIO_IO_CMD_REG 0xC // IO Command Register
    #define GNICIO_CMDDONE  BIT31       // 1b/x/x/x Command Done. 
    #define GNICIO_IOWBE    0xF00       // 0/x/x/x IO cycle write byte enable
    #define GNICIO_RWCMD    BIT0        // 0/x/x/x Read/Write Command 
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(5.0.0.0)
// Pls contact PLW to report Irs2h bugs.
