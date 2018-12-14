//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************

// This file is auto converted by Irs2h from IRS_CND003_D15F0_SATA.doc.
#ifndef REG_CND003_D15F0_SATA_H
#define REG_CND003_D15F0_SATA_H
// D15F0
#define CND003_D15F0_VID 0x0 // Vendor ID
    #define CND003_D15F0_VENDORID CND003_D15F0_VID // 1106h/x/x/x Vendor ID
#define CND003_D15F0_PCI_CMD_REG 0x4 // PCI Command Register
    #define CND003_D15F0_DISINT        BIT10                   // 0/0/0/0 Interrupt Disable
    #define CND003_D15F0_RPTYERR       BIT6                    // 0/R/x/x Parity Error Response
    #define CND003_D15F0_R04B5         BIT5                    // 0/R/x/x VGA Palette Snooping
    #define CND003_D15F0_R04B4         BIT4                    // 0/R/x/x Memory Write and Invalidate
    #define CND003_D15F0_R04B3         BIT3                    // 0/R/x/x Respond to Special Cycle
    #define CND003_D15F0_BUSMSTR       BIT2                    // 0/1/1/1 Bus Master
    #define CND003_D15F0_PREMMSPACE    BIT1                    // 0/1/1/1 Memory Space Access
    #define CND003_D15F0_PREIOSPACE    BIT0                    // 0/1/1/1 I/O Space Access
#define CND003_D15F0_PCI_CMD_REG_2 0x5
#define CND003_D15F0_PCI_STA_REG 0x6 // PCI Status Register
    #define CND003_D15F0_SATADPE   BIT15                   // 0/R/x/x Detected Parity Error
    #define CND003_D15F0_SSE       BIT14                   // 0/R/x/x Signaled System Error (SERR# Asserted)
    #define CND003_D15F0_RMA       BIT13                   // 0/x/x/x Received Master Abort
    #define CND003_D15F0_RTA       BIT12                   // 0/x/x/x Received Target Abort
    #define CND003_D15F0_TAA       BIT11                   // 0/R/x/x Target-Abort Assertion
    #define CND003_D15F0_DT        (BIT9 + BIT10)          // 01b/R/x/x DEVSEL# Timing
    #define CND003_D15F0_MDPE      BIT8                    // 0/R/x/x Master Data Parity Error
    #define CND003_D15F0_FBTBC     BIT7                    // 1b/R/x/x Fast Back-to-Back Capability
    #define CND003_D15F0_EN66      BIT5                    // 0/R/x/x 66 MHz Capable
    #define CND003_D15F0_PMCL      BIT4                    // 1b/R/x/x Power Management Capability List
    #define CND003_D15F0_INTS      BIT3                    // 0/R/x/x Interrupt Status
#define CND003_D15F0_REV_ID 0x8 // Revision ID
    #define CND003_D15F0_REVID CND003_D15F0_REV_ID // 0/x/x/x Revision ID
#define CND003_D15F0_SUB_CLASS_CODE 0xA // Sub Class Code
    #define CND003_D15F0_SUBCLASS CND003_D15F0_SUB_CLASS_CODE // 01h/R/x/x Sub Class
#define CND003_D15F0_BASE_CLASS_CODE 0xB // Base Class Code
    #define CND003_D15F0_BASECLASS CND003_D15F0_BASE_CLASS_CODE // 01h/R/x/x Base Class
#define CND003_D15F0_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define CND003_D15F0_CACHLINE CND003_D15F0_CACHE_LINE_SIZE // 0/x/x/x Cache Line Size
#define CND003_D15F0_LATENCY_TIMER 0xD // Latency Timer
    #define CND003_D15F0_LATENCYTIMER  0xF0    // 2h/x/x/x Latency Timer
#define CND003_D15F0_HDR_TYPE 0xE // Header Type
#define CND003_D15F0_SVID 0x2C // Subsystem Vendor ID
    #define CND003_D15F0_SVID_Z1 CND003_D15F0_SVID // 1106h/R/x/x Subsystem Vendor ID
#define CND003_D15F0_PM_CAPS_PTR 0x34 // Power Management Capabilities Pointer
    #define CND003_D15F0_FLRCP CND003_D15F0_PM_CAPS_PTR // B0h/R/x/x Function Level Reset Capabilities Pointer
#define CND003_D15F0_INTR_LINE 0x3C // Interrupt Line
    #define CND003_D15F0_SINTLN_7_4        0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_ORG_SINTLN_3_0    0xF     // 0h/x/x/x Reserved
#define CND003_D15F0_INTR_PIN 0x3D // Interrupt Pin
    #define CND003_D15F0_XINTPIN_2_0   (BIT0 + BIT1 + BIT2)    // 001b/R/x/x Interrupt Pin
#define CND003_D15F0_MIN_GRANT 0x3E // Minimum Grant
#define CND003_D15F0_MAX_LATENCY 0x3F // Maximum Latency
    #define CND003_D15F0_MAXLATENCY CND003_D15F0_MAX_LATENCY // 0/R/x/x Maximum Latency
#define CND003_D15F0_SATA_CHN_ENABLE 0x40 // SATA Channel Enable
    #define CND003_D15F0_SA_HBA_RST    BIT3    // 0/x/x/x SATA IDE and RAID Controller HBA Reset
    #define CND003_D15F0_R40B2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_ENBLEA        BIT1    // 1b/1/x/x Primary Channel (SATA) IO Access
    #define CND003_D15F0_ENBLEB        BIT0    // 1b/1/x/x Secondary Channel (SATA) IO Access
#define CND003_D15F0_SATA_INTR 0x41 // SATA Interrupt
    #define CND003_D15F0_R41B7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R41B6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R41B5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_AH_GINTMOD    BIT4    // 1b/1/X/x Block Interrupt Till Read FIFO Empty for A DMA Read for AHCI Mode
    #define CND003_D15F0_R41B3         BIT3    // 0/x/X/x Reserved
    #define CND003_D15F0_R41B2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_GINTMOD       BIT1    // 1b/1/x/x Block Interrupt Till Read FIFO Empty for A DMA Read for SATA IDE/RAI...
    #define CND003_D15F0_R41B0         BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL 0x42 // SATA LINK/PHY and AHCI Port Selection Control
    #define CND003_D15F0_R42B_7_4          0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_SATA_PORT_SEL_3_0 0xF     // 0/x/x/x SATA LINK/PHY and AHCI Port Selection
#define CND003_D15F0_SATA_FIFO_THRESHOLD_CTL 0x43 // SATA FIFO Threshold Control
    #define CND003_D15F0_FFTHRA_3_0    0xF0                    // 0100b/x/x/x Reserved 
    #define CND003_D15F0_R43B3         BIT3                    // 0/x/x/x Reserved
    #define CND003_D15F0_R43B_2_0      (BIT0 + BIT1 + BIT2)    // 100b/x/x/x Reserved
#define CND003_D15F0_MISC_CTL_1 0x44 // Miscellaneous Control 1
    #define CND003_D15F0_SAPIOGCLKEN   BIT7    // 0/0/x/1 Legacy SATA Primary Channel PIOC Downstream GCLK Dynamic Clock Enable
    #define CND003_D15F0_SBPIOGCLKEN   BIT6    // 0/0/x/1 Legacy SATA Secondary Channel PIOC Downstream GCLK Dynamic Clock Enable
    #define CND003_D15F0_R44B5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_WAIT_PHYRDY   BIT4    // 1b/1/x/x Gating Soft Reset When PHY Is Not Ready
    #define CND003_D15F0_R44B3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_FFRDT2        BIT2    // 1b/x/x/x Reserved
    #define CND003_D15F0_R44B1         BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_ENEXITRXREG   BIT0    // 1b/x/x/x Reserved
#define CND003_D15F0_MISC_CTL_2 0x45 // Miscellaneous Control 2
    #define CND003_D15F0_WPSUBCLASS        BIT7            // 0/x/x/x Sub Class (Rx0A) Write Enable
    #define CND003_D15F0_ENSAPIOCLK_GATE   BIT6            // 0/0/x/1 SATA Downstream GCLK Clock Dynamic Enable
    #define CND003_D15F0_ENSTRFUPECLK_GATE BIT5            // 0b/0/x/1 STRFUP ECLK Clock Dynamic Enable
    #define CND003_D15F0_WPINTL            BIT4            // 0b/x/x/x Interrupt Line (Rx3C) Write Enable
    #define CND003_D15F0_R45B_3_2          (BIT2 + BIT3)   // 0/x/x/x Reserved
    #define CND003_D15F0_ENDINT            BIT1            // 1b/1/x/x Flush Read DMA Data After Interrupt
    #define CND003_D15F0_R45B0             BIT0            // 0/x/x/x Reserved
#define CND003_D15F0_MISC_CTL_3 0x46 // Miscellaneous Control 3
    #define CND003_D15F0_ENTP_CKGATE_P3    BIT7    // 0/0/x/1 Secondary Channel Slave Port SA_TPECLK Clock Dynamic Gating Enable
    #define CND003_D15F0_ENTP_CKGATE_P2    BIT6    // 0/0/x/1 Secondary Channel Master Port SA_TPECLK Clock Dynamic Gating Enable
    #define CND003_D15F0_ENTP_CKGATE_P1    BIT5    // 0/0/x/1 Primary Channel Slave Port SA_TPECLK Clock Dynamic Gating Enable
    #define CND003_D15F0_ENTP_CKGATE_P0    BIT4    // 0/0/x/1 Primary Channel Master Port SA_TPECLK Clock Dynamic Gating Enable
    #define CND003_D15F0_R46B2             BIT3    // 0b/x/x/x Reserved
    #define CND003_D15F0_ENSTRFUPCLK_GATE  BIT2    // 0/0/x/1 STRFUP UPCLK Clock Dynamic Gating Enable
    #define CND003_D15F0_R46B1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_R46B0             BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_PORT_MULTIPLIER_PORT_ASSIGNMENT_MISC_CTLS 0x47 // Port Multiplier Port Assignment & MISC Controls
    #define CND003_D15F0_R47B_7_4      0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_R47B3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R47B2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_SELALIGN2OR4  BIT1    // 0/x/x/x Option of Qualifying with Only 2 ALIGNs in OOB Sequencing
    #define CND003_D15F0_DIS_NOUPEREG  BIT0    // 0/x/x/x Update Link and PHY Status for 1st D2H FIS When Software Reset Is In ...
#define CND003_D15F0_SATA_DMAC_ECLK150_GATING 0x48 // SATA DMAC ECLK150 Gating
    #define CND003_D15F0_R48B_7_5              (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_D15F0_R48B4                 BIT4                    // 0/x/x/x Reserved
    #define CND003_D15F0_P3_ENSAECLK150_GATE   BIT3                    // 0/0/x/1 Secondary Channel Slave Port DMAC ECLK150 Gating Enable
    #define CND003_D15F0_P2_ENSAECLK150_GATE   BIT2                    // 0/0/x/1 Secondary Channel Master Port DMAC ECLK150 Gating Enable
    #define CND003_D15F0_P1_ENSAECLK150_GATE   BIT1                    // 0/0/x/1 Primary Channel Slave Port DMAC ECLK150 Gating Enable
    #define CND003_D15F0_P0_ENSAECLK150_GATE   BIT0                    // 0/0/x/1 Primary Channel Master Port DMAC ECLK150 Gating Enable
#define CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG 0x49 // SATA PHY Clock Gating Control Register
    #define CND003_D15F0_R49B7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R49B6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R49B5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R49B4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R49B3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R49B2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R49B1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_ENTXCLK_GATE_PN   BIT0    // 0/0/x/1 Port n PHY Clock Gating (Random)
#define CND003_D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1 0x4A // SATA PHY Clock Gating Control Register
    #define CND003_D15F0_R4AB_7_4  0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_R4AB3     BIT3    // 0/0/x/1 Legacy SATA Secondary Channel (Slave) Hot-plug / Link PM Feature Select
    #define CND003_D15F0_R4AB2     BIT2    // 0/0/x/1 Legacy SATA Secondary Channel (Master) Hot-plug / Link PM Feature Select
    #define CND003_D15F0_R4AB1     BIT1    // 0/0/x/1 Legacy SATA Primary Channel  (Slave) Hot-plug / Link PM Feature Select
    #define CND003_D15F0_R4AB0     BIT0    // 0/0/x/1 Legacy SATA Primary Channel (Master) Hot-plug / Link PM Feature Select
#define CND003_D15F0_SATA_HOT_PLUG_STA 0x4B // SATA Hot Plug Status
    #define CND003_D15F0_P3_PLUG_OUTSTS    BIT7    // 0/x/x/x Secondary Channel Slave Port Plug Out Status
    #define CND003_D15F0_P3_PLUG_INSTS     BIT6    // 0/x/x/x Secondary Channel Slave Port Plug In Status
    #define CND003_D15F0_P2_PLUG_OUTSTS    BIT5    // 0/x/x/x Secondary Channel Master Port Plug Out Status
    #define CND003_D15F0_P2_PLUG_INSTS     BIT4    // 0/x/x/x Secondary Channel Master Port Plug In Status
    #define CND003_D15F0_P1_PLUG_OUTSTS    BIT3    // 0/x/x/x Primary Channel Slave Port Plug Out Status
    #define CND003_D15F0_P1_PLUG_INSTS     BIT2    // 0/x/x/x Primary Channel Slave Port Plug In Status
    #define CND003_D15F0_P0_PLUG_OUTSTS    BIT1    // 0/x/x/x Primary Channel Master Port Plug Out Status
    #define CND003_D15F0_P0_PLUG_INSTS     BIT0    // 0/x/x/x Primary Channel Master Port Plug In Status
#define CND003_D15F0_COLD_PRESENCE_DETECT_SUPPORT 0x4C // Cold Presence Detect Support
    #define CND003_D15F0_R4CB7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R4CB6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R4CB5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R4CB4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R4CB3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R4CB2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_EN_SATA_CPD_PN    BIT1    // 0/x/x/x Port n Cold Present Detect Enable
    #define CND003_D15F0_AHN_SUP_CPD       BIT0    // 0/x/x/x AHCI port n Cold Present Detect Support
#define CND003_D15F0_COLD_PRESENCE_DETECT_STA 0x4D // Cold Presence Detect Status
    #define CND003_D15F0_R4DB7     BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R4DB6     BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R4DB5     BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R4DB4     BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R4DB3     BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R4DB2     BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R4DB1     BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_CPDSTAT   BIT0    // 0/x/x/x Device Exist or Not ? Port n
#define CND003_D15F0_SATA_SPEED_CTL 0x4E // SATA Speed Control
    #define CND003_D15F0_P3_SPD_SCR    (BIT6 + BIT7)   // 10b/x/x/x Secondary Channel Slave Port Speed Enable
    #define CND003_D15F0_P2_SPD_SCR    (BIT4 + BIT5)   // 10b/x/x/x Secondary Channel Master Port Speed Enable
    #define CND003_D15F0_P1_SPD_SCR    (BIT2 + BIT3)   // 10b/x/x/x Primary Channel Slave Port Speed Enable
    #define CND003_D15F0_P0_SPD_SCR    (BIT0 + BIT1)   // 10b/x/x/x Primary Channel Master Port Speed Enable
#define CND003_D15F0_SATA_SPEED_NEGOTIATION_CTL 0x4F // SATA Speed Negotiation Control
    #define CND003_D15F0_R4FB7                 BIT7            // 0/x/x/x Reserved
    #define CND003_D15F0_CONNECTRTY_CNT_1_0    (BIT5 + BIT6)   // 0/x/x/x Do retry at the same SATA Gen speed before drop to the lower Gen spee...
    #define CND003_D15F0_PN_DISREDSPEED        BIT4            // 0/0/x/x PHY Link Speed Negotiation Scheme ? Port n 
    #define CND003_D15F0_CONNECTRTY            BIT3            // 1b/x/x/x Try Current Speed Several Times Before Reducing to Lower Speed  Duri...
    #define CND003_D15F0_CONNECTRTY_DLY_EN_A2  BIT2            // 0/x/x/x SATA Host Drop Speed Internal Time Delay Enable 
    #define CND003_D15F0_CONNECTRTY_DLY_SEL_A2 BIT1            // 0/x/x/x SATA Host Drop Speed Internal Time Delay Selection
    #define CND003_D15F0_R4FB0_A2              BIT0            // 0/x/x/x Reserved
#define CND003_D15F0_SATA_MISC_CTL 0x50 // SATA Miscellaneous Control
    #define CND003_D15F0_R50B7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R50B6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_BMSTATUS_SEL_A    BIT5    // 0/x/x/x Bus Status SGACTV Selection for Primary Channel Master / Slave
    #define CND003_D15F0_BMSTATUS_SEL_B    BIT4    // 0/x/x/x Bus Status SGACTV Selection for Secondary Channel Mster / Slave
    #define CND003_D15F0_ENIRQBYHPA        BIT3    // 0/0/x/x Assert Interrupt to CPU When Either Ports of Primary Channel Have Plu...
    #define CND003_D15F0_ENIRQBYHPB        BIT2    // 0/x/x/x Assert Interrupt to CPU When Either Ports of Secondary Channel Have P...
    #define CND003_D15F0_RSTSHADREG_A      BIT1    // 0/x/x/x Reserved (Do Not Program)
    #define CND003_D15F0_RSTSHADREG_B      BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_PHYRDY_STA_CTL 0x51 // SATA PHYRDY Status Control
    #define CND003_D15F0_R51B7                 BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R51B6                 BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R51B5                 BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R51B4                 BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R51B3                 BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R51B2                 BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R51B1                 BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_ENPHYRDYHLD_HOTPLG    BIT0    // 0/x/x/x PHYRDY Keep High during Hot Plug Out
#define CND003_D15F0_SATA_PERFORMANCE_CTL 0x52 // SATA Performance Control
    #define CND003_D15F0_R52B7         BIT7                    // 0/x/x/x Reserved
    #define CND003_D15F0_PIPELINE_LVL  (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Reserved
    #define CND003_D15F0_ARB_CNT       (BIT1 + BIT2 + BIT3)    // 000b/x/x/x SATA STRFUP Each Port DMA Request Pipe Max Cycle Number Setting
    #define CND003_D15F0_ONLY4QW       BIT0                    // 0/x/0/x Reserved
#define CND003_D15F0_SATA_CMD_CTL_REG 0x53 // SATA Command Control Register
    #define CND003_D15F0_WDCMD                 BIT7            // 0/0/x/x TP Layer Idle for at Least 20us Before the Following Command Being Ex...
    #define CND003_D15F0_CMD_CLKSEL            BIT6            // 0/0/x/x The Least Time TP Layer Should Be Idle Before the Following Command B...
    #define CND003_D15F0_ENAUTOCOMRSTCLRD2H    BIT5            // 1b/1/1/1 Auto-send COMRESET Clear First D2H Signal Enable
    #define CND003_D15F0_ENPWRHOTPLUG          BIT4            // 0/0/x/x Issue COMRESET When SATA Controller Receives COMINIT in Power Mode
    #define CND003_D15F0_R53B3                 BIT3            // 0/x/x/x Reserved
    #define CND003_D15F0_R53B_2_1              (BIT1 + BIT2)   // 00b/x/x/x Reserved
    #define CND003_D15F0_ENPMNAK_CMD_A2        BIT0            // 1b/x/x/x Reject Device Power Request When HW Command Executes
#define CND003_D15F0_RESERVED 0x54 // Reserved
    #define CND003_D15F0_R54B7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R54B6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R54B5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R54B4         BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R54B3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R54B2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R54B1         BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_PN_FORCEDEV   BIT0    // 0/x/x/x Reserved (Do Not Program) 
#define CND003_D15F0_SATA_LINK_CTL_REG_1 0x55 // SATA Link Control Register 1
    #define CND003_D15F0_FIX6COMRESET          BIT7            // 1b/1/x/x Host Always Transmits 6 COMRESET for Power-on Sequence
    #define CND003_D15F0_ENASYNRCOVSTP         BIT6            // 1b/1/x/x Limit Continuous Asynchronous Recovery (AsynRcovery) to Five Times Only
    #define CND003_D15F0_INHIBITC4PSEL         BIT5            // 0/0/x/x Conditions to Allow Back-to-Back Requests of Entering C4P
    #define CND003_D15F0_R55B4                 BIT4            // 0/x/x/x Reserved
    #define CND003_D15F0_R55B3                 BIT3            // 0/x/x/x Reserved
    #define CND003_D15F0_R55B2                 BIT2            // 0/x/x/x Reserved
    #define CND003_D15F0_EQTN_DURATION_MODE    (BIT0 + BIT1)   // 01b/01/x/x EPHY EQTN Duration Control
#define CND003_D15F0_SATA_LINK_CTL_REG_2 0x56 // SATA Link Control Register 2
    #define CND003_D15F0_INITAWAKEUP       BIT7    // 0/0/x/x Await Sync Before Returning to D0 (Ready & Idle)
    #define CND003_D15F0_EN_FREERXCLK      BIT6    // 0/0/x/x Reserved
    #define CND003_D15F0_DIS_RXSCR         BIT5    // 0/0/x/x Receiver Scrambler
    #define CND003_D15F0_DIS_TXSCR         BIT4    // 0/0/x/x Transmitter Scrambler
    #define CND003_D15F0_DIS_ALIGN         BIT3    // 0/0/x/x Align Primitive Transmission
    #define CND003_D15F0_DIS_CONT          BIT2    // 0/0/x/x Continue Primitive Transmission
    #define CND003_D15F0_ENABLE_APPC       BIT1    // 0/0/x/x (ALIGNp + CONTp) Primitives Transmission
    #define CND003_D15F0_ENINIT_WAKEMPLL   BIT0    // 0/0/x/0 Hold Host Command for SATA Port Init Command until MPLL Wake up
#define CND003_D15F0_PHY_TEST_MODE_CTL_1 0x57 // PHY Test Mode Control 1
    #define CND003_D15F0_DXPATTSEL     (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_D15F0_R57B5         BIT5            // 0/x/x/x Reserved
    #define CND003_D15F0_R57B4         BIT4            // 0/x/x/x Reserved
    #define CND003_D15F0_R57B3         BIT3            // 0/x/x/x Reserved
    #define CND003_D15F0_ENC4PHWK      BIT2            // 0/x/x/x Reserved
    #define CND003_D15F0_ENC4PHREDET   BIT1            // 0/x/x/x Reserved
    #define CND003_D15F0_RETRYSEL      BIT0            // 0/x/x/x Reserved
#define CND003_D15F0_PHY_TEST_MODE_CTL_2 0x58 // PHY Test Mode Control 2
    #define CND003_D15F0_TSTMODE   BIT7                    // 0/0/x/x PHY Test Mode Enable
    #define CND003_D15F0_R58B_6_4  (BIT4 + BIT5 + BIT6)    // 0/x/x/x Reserved
    #define CND003_D15F0_MODESEL   0xF                     // 0/x/x/x PHY Test Pattern Select
#define CND003_D15F0_TEST_PATTERN_REPEAT_NUM 0x59 // Test Pattern Repeat Number
    #define CND003_D15F0_REPEATNUM CND003_D15F0_TEST_PATTERN_REPEAT_NUM // 10h/x/x/x Test Pattern Repeat Number
#define CND003_D15F0_PHY_TEST_MODE_CTL_3 0x5A // PHY Test Mode Control 3
    #define CND003_D15F0_ASYNRCOVSUP   BIT7    // 1b/1/x/x Support Asynchronous Recovery Function
    #define CND003_D15F0_R5AB6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R5AB5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R5AB4         BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R5AB3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R5AB2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_SQUELCH_O     BIT1    // 1b/R/x/x PHY RX Status 
    #define CND003_D15F0_PINSWAPMODE_N BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_PHY_TEST_PORT_SEL_AND_MODE_STA 0x5B // PHY Test Port Selection and Mode Status
    #define CND003_D15F0_R5BB_7_4  0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_R5BB3     BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_COMWAKE_O BIT2    // 0/R/x/x PHY RX Status
    #define CND003_D15F0_COMINIT_O BIT1    // 0/R/x/x PHY RX Status
    #define CND003_D15F0_CHKERROR  BIT0    // 1b/R/x/x PHY Status
#define CND003_D15F0_PHY_CTL_REG_1 0x5C // PHY Control Register 1
    #define CND003_D15F0_TOUTOOBX2         BIT7    // 0/x/x/x Select The Number of Consecutive Data Bursts for COMRESET and COMWAKE
    #define CND003_D15F0_R5CB6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R5CB5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R5CB4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R5CB3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R5CB2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R5CB1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_ENPHY_STPCK_PN    BIT0    // 0/0/x/1 SATA Port n PHY Dynamic Clock Gating ((Random)) 
#define CND003_D15F0_PHY_CTL_REG_2 0x5D // PHY Control Register 2
    #define CND003_D15F0_RUNDISPARITY      BIT7    // 0/0/x/x Determine Polarity of the Selected PHY Test Pattern
    #define CND003_D15F0_DBG_GRPSEL_14_8   0x7F    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_PHY_DATA_PATH_DEBUG_SIGNALS_GRPING_AND_RAM_BIST_CTL 0x5E // SATA PHY Data Path Debug Signals Grouping and RAM BIST Control
    #define CND003_D15F0_DBG_GRP_CFGIDX    (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_D15F0_LONGSHORT         BIT4                    // 0/x/x/x Reserved
    #define CND003_D15F0_TPIN_MODE         0xF                     // 0/x/x/x Select which group of the SATA PHY data path debug signals to be mapp...
#define CND003_D15F0_DEBUG_CTL_SEL 0x5F // Debug Control Selection
    #define CND003_D15F0_DBG_GRPSEL_7_0 CND003_D15F0_DEBUG_CTL_SEL // 0/x/x/x Reserved
#define CND003_D15F0_DEBUG_SIGNALS_GRPING_AND_RAM_BIST_CTL 0x60 // Debug Signals Grouping and RAM BIST Control
    #define CND003_D15F0_R60B_7_6              (BIT6 + BIT7)           // 0/x/x/x Reserved
    #define CND003_D15F0_R60B_5_3              (BIT3 + BIT4 + BIT5)    // 0/x/x/x Reserved
    #define CND003_D15F0_TSTRX2TXMODE          BIT2                    // 0/x/x/x Reserved 
    #define CND003_D15F0_EN_POWERMODE_NEW      BIT1                    // 0/x/x/x Reserved
    #define CND003_D15F0_EN_NOTPOWERMODE_OLD   BIT0                    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_CTL_REG_2_PROVIDE_OPTIONS_FOR_RX_RETIMED_LOOPBACK_BIST_L_TEST 0x61 // SATA Control Register 2: Provide Options for Rx Retimed Loopback (BIST_L) Test
    #define CND003_D15F0_GATESQUELCH       BIT7            // 0/x/x/x Reserved.
    #define CND003_D15F0_LBPSEL            BIT6            // 0/0/x/x Select Which LBP Pattern to Use for Testing (Tx)
    #define CND003_D15F0_ENLBRX_RETIME     BIT5            // 0/0/x/x Enable Rx Retimed Loopback Test Mode
    #define CND003_D15F0_ENKEEPALIGN       BIT4            // 0/0/x/x During The BIST_L Loopback, Don?t Delete Any Align Primitive in The R...
    #define CND003_D15F0_ENINSERT2ALIGN    BIT3            // 0/0/x/x Insert Two Align Primitives 
    #define CND003_D15F0_R61B2             BIT2            // 0/x/x/x Reserved
    #define CND003_D15F0_R61B_1_0          (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_D15F0_SATA_CTL_REG_3 0x62 // SATA Control Register 3
    #define CND003_D15F0_ENRSTCDR_BISTL    BIT7            // 0/0/x/x For BIST_L Only: Reset CDR Module When CDR Disperses (Host Rx Disconn...
    #define CND003_D15F0_FORCEPHYRDY       BIT6            // 0/0/x/x Force PHY to PHYRDY State
    #define CND003_D15F0_ENTER_BISTL       BIT5            // 0/0/x/x Force PHY to Enter BIST_L Mode (Without Receiving BIST_L from the Dev...
    #define CND003_D15F0_ENHANCEOOBDET     BIT4            // 0/0/x/x Relax Timing Margin for OOB Detection
    #define CND003_D15F0_PWRTMR_FULLRSTEN  BIT3            // 0/0/x/x Reset Power Management Timer When It Counts to ?hf
    #define CND003_D15F0_NOQPHYRDY         BIT2            // 0/0/x/x Command Handling Policies When PHY Is Not Ready (Downstream)
    #define CND003_D15F0_TXP_SEL           (BIT0 + BIT1)   // 10b/x/x/x Reserved
#define CND003_D15F0_SATA_CTL_REG_4 0x63 // SATA Control Register 4
    #define CND003_D15F0_ENRECOMRST_ERRPRED2H  BIT7    // 1b/x/x/x Resend COMRESET When Recovering Device Error
    #define CND003_D15F0_ENTERTPIDLE_SRST      BIT6    // 1b/x/x/x Reserved
    #define CND003_D15F0_DIS_NIEN_RSTDRVS      BIT5    // 0/0/x/x Reset Drive Select to Master When Change Device Control Register Bit[...
    #define CND003_D15F0_DEVTOCDETEN           BIT4    // 1b/x/x/x Device OOB sequence Time-out clear DEVDET status enable
    #define CND003_D15F0_POUT_CLRDET_EN_A2     BIT3    // 1b/x/x/x Hotplug-out Clear DEVDET Status Enable
    #define CND003_D15F0_HOTPLUG_OP            BIT2    // 1b/x/x/x Reserved
    #define CND003_D15F0_EN_SLU_PLLG           BIT1    // 0/0/x/1 When Slumber, Gate SATA EPHY MPLL/TPLL
    #define CND003_D15F0_EN_SLU_PLLD           BIT0    // 0/0/x/1 Turn Off SATA MPLL/TPLL When Entering Slumber
#define CND003_D15F0_SATA_EPHY_CTL_REG_DATA_0 0x64 // SATA EPHY Control Register Data 0
    #define CND003_D15F0_EPHYREGDATA0_7_0 CND003_D15F0_SATA_EPHY_CTL_REG_DATA_0 // 0/x/x/x 8-bit Data of EPHY Control Register Which Is Linked by EPHY Register ...
#define CND003_D15F0_SATA_EPHY_CTL_REG_DATA_1 0x65 // SATA EPHY Control Register Data 1
    #define CND003_D15F0_EPHYREGDATA1_7_0 CND003_D15F0_SATA_EPHY_CTL_REG_DATA_1 // 0/x/x/x 8-bit Data of EPHY Control Register Which Is Linked by EPHY Register ...
#define CND003_D15F0_SATA_EPHY_CTL_REG_DATA_2 0x66 // SATA EPHY Control Register Data 2
    #define CND003_D15F0_EPHYREGDATA2_7_0 CND003_D15F0_SATA_EPHY_CTL_REG_DATA_2 // 0/x/x/x 8-bit Data of EPHY Control Register Which Is Linked by EPHY Register ...
#define CND003_D15F0_SATA_EPHY_CTL_REG_DATA_3 0x67 // SATA EPHY Control Register Data 3
    #define CND003_D15F0_EPHYREGDATA3_7_0 CND003_D15F0_SATA_EPHY_CTL_REG_DATA_3 // 0/x/x/x 8-bit Data of EPHY Control Register Which Is Linked by EPHY Register ...
#define CND003_D15F0_SATA_EPHY_CTL_REG_PTR 0x68 // SATA EPHY Control Register Pointer
    #define CND003_D15F0_EPHYREGADDR_15_0 CND003_D15F0_SATA_EPHY_CTL_REG_PTR // 0000h/x/x/x EPHY Control Register Address Pointer Low
#define CND003_D15F0_SATA_PHY_MISC_CTL_REGS_1 0x6A // SATA PHY Miscellaneous Control Registers 1
    #define CND003_D15F0_TX2RX_ALIGN_ADD       BIT7            // 0/x/x/x Reserved
    #define CND003_D15F0_RX2TX_ALIGN           BIT6            // 0/x/x/x Reserved
    #define CND003_D15F0_HOSTC4PWK_LATENCY_1_0 (BIT4 + BIT5)   // 11b/x/x/x Reserved
    #define CND003_D15F0_PLLDCOND_DLY_1_0      (BIT2 + BIT3)   // 01b/x/x/x Reserved
    #define CND003_D15F0_R6AB1                 BIT1            // 0/x/x/x Reserved
    #define CND003_D15F0_SATA_OOB_SEL_PN       BIT0            // 0/x/x/x Select the Pattern Sent in OOB ? Port n
#define CND003_D15F0_SATA_PHY_MISC_CTL_REGS_2 0x6B // SATA PHY Miscellaneous Control Registers 2
    #define CND003_D15F0_R6BB7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R6BB6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R6BB5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R6BB4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R6BB3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R6BB2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R6BB1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_RX_TIMER_SEL_PN   BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_PHY_MISC_CTL_REGS_3 0x6C // SATA PHY Miscellaneous Control Registers 3
    #define CND003_D15F0_R6CB7                 BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R6CB6                 BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R6CB5                 BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R6CB4                 BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R6CB3                 BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R6CB2                 BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R6CB1                 BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_ERROR_COUNTER_SEL_PN  BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_PHY_PMP_FILED 0x6D // SATA PHY PMP Filed
    #define CND003_D15F0_P1_CUR_TX_PMP 0xF0    // 0/x/x/x PMP (Port Multiplier Port) Field - Primary Channel Slave Port
    #define CND003_D15F0_P0_CUR_TX_PMP 0xF     // 0/x/x/x PMP (Port Multiplier Port) Field - Primary Channel Master Port
#define CND003_D15F0_SATA_PHY_PMP_FILED_Z1 0x6E // SATA PHY PMP Filed
    #define CND003_D15F0_P3_CUR_TX_PMP 0xF0    // 0/x/x/x PMP (Port Multiplier Port) Field - Secondary Channel Slave Port
    #define CND003_D15F0_P2_CUR_TX_PMP 0xF     // 0/x/x/x PMP (Port Multiplier Port) Field - Secondary Channel Master Port
#define CND003_D15F0_SATA_PHY_PMP_SUPPORT 0x6F // SATA PHY PMP Support
    #define CND003_D15F0_P3_SUP_PMP    BIT7    // 0/x/x/x Enable PMP Support ? Secondary Channel Slave Port
    #define CND003_D15F0_P2_SUP_PMP    BIT6    // 0/x/x/x Enable PMP Support ? Secondary Channel Master Port
    #define CND003_D15F0_P1_SUP_PMP    BIT5    // 0/x/x/x Enable PMP Support ? Primary Channel Slave Port
    #define CND003_D15F0_P0_SUP_PMP    BIT4    // 0/x/x/x Enable PMP Support ? Primary Channel Master Port
    #define CND003_D15F0_R6FB3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R6FB2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R6FB1         BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_R6FB0         BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_AUTO_PARTIAL_TO_SLUMBER_TRANSPORT_SPST_ENABLE 0x70 // SATA Auto Partial to Slumber Transport (SPST) Enable
    #define CND003_D15F0_ENC4P_APST    BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R70B6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R70B5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R70B4         BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R70B3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R70B2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R70B1         BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_PN_ENAPST     BIT0    // 0/x/x/x Auto Partial to Slumber Transport Enable
#define CND003_D15F0_SATA_APST_CLK_SEL 0x71 // SATA APST Clock Selection
    #define CND003_D15F0_SACFGWISO     BIT7    // 0/x/x/x SATA DMA Read (P2C Write) Transfer ISO Priority Set
    #define CND003_D15F0_SACFGRISO     BIT6    // 0/x/x/x SATA DMA Write (P2C Read) Transfer ISO Priority Set
    #define CND003_D15F0_R71B5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_APSTCKSEL_4_0 0x1F    // 0/x/x/x Auto Partial to Slumber Transport Timer Counter Clock Selection
#define CND003_D15F0_SATA_STRFUP_CTL_AND_PMP_ERR_REG 0x72 // SATA STRFUP Control and PMP Error Register
    #define CND003_D15F0_R72B7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R72B6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R72B5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R72B4         BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_SAWPIPE_EN    BIT3    // 0/0/x/x SATA DMA Read (P2C Write) Request Pipe Control
    #define CND003_D15F0_SARPIPE_EN    BIT2    // 0/0/x/x SATA DMA Write (P2C Read) Request Pipe Control
    #define CND003_D15F0_SACFGWHP      BIT1    // 0/x/x/x SATA DMA Read (P2C Write) Transfer High Priority set
    #define CND003_D15F0_SACFGRHP      BIT0    // 0/x/x/x SATA DMA Write(P2C Read) Transfer High Priority Set
#define CND003_D15F0_LEGACY_SATA_PMP_MAP_STA_FOR_PORT_0_PORT_1 0x74 // Legacy SATA PMP Map Status for Port 0 ~ Port 1
    #define CND003_D15F0_P1_SNTF_H 0xFF000000  // 0/x/x/x Reserved
    #define CND003_D15F0_P1_SNTF_L 0xFF0000    // 0/x/X/x Reserved
    #define CND003_D15F0_P0_SNTF_H 0xFF00      // 0/x/X/x Reserved
    #define CND003_D15F0_P0_SNTF_L 0xFF        // 0/x/X/x Reserved
#define CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_DMA_AND_PIO_CMD_BASIC_STA 0x78 // Legacy SATA Secondary Channel Slave Port DMA and PIO Command Basic Status
    #define CND003_D15F0_P3_TXPIODATA_S    BIT7    // 0/x/x/x Port 3 SATA TP Enter TXPIODATA State
    #define CND003_D15F0_P3_RXPIODATA_S    BIT6    // 0/x/x/x Port 3 SATA TP Enter RXPIODATA State
    #define CND003_D15F0_P3_TXDMADATA_S    BIT5    // 0/x/x/x Port 3 SATA TP Enter TXDAMDATA State
    #define CND003_D15F0_P3_RXDMADATA_S    BIT4    // 0/x/x/x Port 3 SATA TP Enter RXDMADATA State
    #define CND003_D15F0_P3_SA_RDMA        BIT3    // 0/x/x/x Port 3 DMA Read Device Cycle Active
    #define CND003_D15F0_P3_SA_WDMA        BIT2    // 0/x/x/x Port 3 DMA Write Device Cycle Active
    #define CND003_D15F0_P3_SGACTV         BIT1    // 0/x/x/x Port 3 SG (Scatter/Gather) Operation Active
    #define CND003_D15F0_P3_EMPTY          BIT0    // 1b/x/x/x Port 3 FIFO Empty Status
#define CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_DMA_AND_PIO_CMD_BASIC_STA 0x79 // Legacy SATA Secondary Channel Master Port DMA and PIO Command Basic Status
    #define CND003_D15F0_P2_TXPIODATA_S    BIT7    // 0/x/x/x Port 2 SATA TP Enter TXPIODATA State
    #define CND003_D15F0_P2_RXPIODATA_S    BIT6    // 0/x/x/x Port 2 SATA TP Enter RXPIODATA State
    #define CND003_D15F0_P2_TXDMADATA_S    BIT5    // 0/x/x/x Port 2 SATA TP Enter TXDAMDATA State
    #define CND003_D15F0_P2_RXDMADATA_S    BIT4    // 0/x/x/x Port 2 SATA TP Enter RXDMADATA State
    #define CND003_D15F0_P2_SA_RDMA        BIT3    // 0/x/x/x Port 2 DMA Read Device Cycle Active
    #define CND003_D15F0_P2_SA_WDMA        BIT2    // 0/x/x/x Port 2 DMA Write Device Cycle Active
    #define CND003_D15F0_P2_SGACTV         BIT1    // 0/x/x/x Port 2 SG (Scatter/Gather) Operation Active
    #define CND003_D15F0_P2_EMPTY          BIT0    // 1b/x/x/x Port 2 FIFO Empty Status
#define CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_DMA_AND_PIO_CMD_BASIC_STA 0x7A // Legacy SATA Primary Channel Slave Port DMA and PIO Command Basic Status
    #define CND003_D15F0_P1_TXPIODATA_S    BIT7    // 0/x/x/x Port 1 SATA TP Enter TXPIODATA State
    #define CND003_D15F0_P1_RXPIODATA_S    BIT6    // 0/x/x/x Port 1 SATA TP Enter RXPIODATA State
    #define CND003_D15F0_P1_TXDMADATA_S    BIT5    // 0/x/x/x Port 1 SATA TP Enter TXDAMDATA State
    #define CND003_D15F0_P1_RXDMADATA_S    BIT4    // 0/x/x/x Port 1 SATA TP Enter RXDMADATA State
    #define CND003_D15F0_P1_SA_RDMA        BIT3    // 0/x/x/x Port 1 DMA Read Device Cycle Active
    #define CND003_D15F0_P1_SA_WDMA        BIT2    // 0/x/x/x Port 1 DMA Write Device Cycle Active
    #define CND003_D15F0_P1_SGACTV         BIT1    // 0/x/x/x Port 1 SG (Scatter/Gather) Operation Active
    #define CND003_D15F0_P1_EMPTY          BIT0    // 1b/x/x/x Port 1 FIFO Empty Status
#define CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_DMA_AND_PIO_CMD_BASIC_STA 0x7B // Legacy SATA Primary Channel Master Port DMA and PIO Command Basic Status
    #define CND003_D15F0_P0_TXPIODATA_S    BIT7    // 0/x/x/x Port 0 SATA TP Enter TXPIODATA State
    #define CND003_D15F0_P0_RXPIODATA_S    BIT6    // 0/x/x/x Port 0 SATA TP Enter RXPIODATA State
    #define CND003_D15F0_P0_TXDMADATA_S    BIT5    // 0/x/x/x Port 0 SATA TP Enter TXDAMDATA State
    #define CND003_D15F0_P0_RXDMADATA_S    BIT4    // 0/x/x/x Port 0 SATA TP Enter RXDMADATA State
    #define CND003_D15F0_P0_SA_RDMA        BIT3    // 0/x/x/x Port 0 DMA Read Device Cycle Active
    #define CND003_D15F0_P0_SA_WDMA        BIT2    // 0/x/x/x Port 0 DMA Write Device Cycle Active
    #define CND003_D15F0_P0_SGACTV         BIT1    // 0/x/x/x Port 0 SG (Scatter/Gather) Operation Active
    #define CND003_D15F0_P0_EMPTY          BIT0    // 1b/x/x/x Port 0 FIFO Empty Status
#define CND003_D15F0_SATA_CTL_REG_5 0x7C // SATA Control Register 5
    #define CND003_D15F0_SRST_DIAGING_EN   BIT7    // 1b/x/x/x Reserved
    #define CND003_D15F0_RESRST_EN         BIT6    // 1b/x/x/x Reserved
    #define CND003_D15F0_W4ALIGNTOUT_EN    BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_R7CB4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_R7CB3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R7CB2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R7CB1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_R7CB0             BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_PHY_STA 0x7D // SATA PHY Status
    #define CND003_D15F0_S_P3_COMINIT  BIT7    // 0/R/x/x PHY Port 3 Receiving COMINIT (See the note below)
    #define CND003_D15F0_S_P3_COMWAKE  BIT6    // 0/R/x/x PHY Port 3 Receiving COMWAKE (See the note below)
    #define CND003_D15F0_S_P2_COMINIT  BIT5    // 0/R/x/x PHY Port 2 Receiving COMINIT (See the note below)
    #define CND003_D15F0_S_P2_COMWAKE  BIT4    // 0/R/x/x PHY Port 2 Receiving COMWAKE (See the note below)
    #define CND003_D15F0_S_P1_COMINIT  BIT3    // 0/R/x/x PHY Port 1 Receiving COMINIT (See the note below)
    #define CND003_D15F0_S_P1_COMWAKE  BIT2    // 0/R/x/x PHY Port 1 Receiving COMWAKE (See the note below)
    #define CND003_D15F0_S_P0_COMINIT  BIT1    // 0/R/x/x PHY Port 0 Receiving COMINIT (See the note below)
    #define CND003_D15F0_S_P0_COMWAKE  BIT0    // 0/R/x/x PHY Port 0 Receiving COMWAKE (See the note below)
#define CND003_D15F0_SATA_PHY_STA_Z1 0x7E // SATA PHY Status
    #define CND003_D15F0_P3_PMPERR BIT7    // 0/x/x/x Secondary Channel Slave Port Multiple Port (PMP) Error Status
    #define CND003_D15F0_P2_PMPERR BIT6    // 0/x/x/x Secondary Channel Master Port Multiple Port (PMP) Error Status
    #define CND003_D15F0_P1_PMPERR BIT5    // 0/x/x/x Primary Channel Slave Port Multiple Port (PMP) Error Status
    #define CND003_D15F0_P0_PMPERR BIT4    // 0/x/x/x Primary Channel Master Port Multiple Port (PMP) Error Status
    #define CND003_D15F0_P3_INTRQ  BIT3    // 0/x/x/x Secondary Channel Slave Port Interrupt Status
    #define CND003_D15F0_P2_INTRQ  BIT2    // 0/x/x/x Secondary Channel Master Port Interrupt Status
    #define CND003_D15F0_P1_INTRQ  BIT1    // 0/x/x/x Primary Channel Slave Port Interrupt Status
    #define CND003_D15F0_P0_INTRQ  BIT0    // 0/x/x/x Primary Channel Master Port Interrupt Status
#define CND003_D15F0_SATA_PHY_PM_MODE_ENTERED_BY_SW_REQ 0x80 // SATA PHY Power Management Mode ? Entered by Software Request
    #define CND003_D15F0_SETSLUM_REQ3  BIT7    // 0/x/x/x For SPM Field (=0010b):
    #define CND003_D15F0_SETPART_REQ3  BIT6    // 0/x/x/x SPM Field (=0001b):
    #define CND003_D15F0_SETSLUM_REQ2  BIT5    // 0/x/x/x For SPM Field (=0010b):
    #define CND003_D15F0_SETPART_REQ2  BIT4    // 0/x/x/x SPM Field (=0001b):
    #define CND003_D15F0_SETSLUM_REQ1  BIT3    // 0/x/x/x For SPM Field (=0010b):
    #define CND003_D15F0_SETPART_REQ1  BIT2    // 0/x/x/x SPM Field (=0001b):
    #define CND003_D15F0_SETSLUM_REQ0  BIT1    // 0/x/x/x SPM Field (=0010b):
    #define CND003_D15F0_SETPART_REQ0  BIT0    // 0/x/x/x SPM Field (=0001b):
#define CND003_D15F0_SATA_TRANSPORT_MISC_CTL 0x81 // SATA Transport Miscellaneous Control
    #define CND003_D15F0_P3_EARLYTPREQ BIT7    // 0/0/1/x Secondary Channel Slave Port Transport Layer to Issue Early Request t...
    #define CND003_D15F0_P2_EARLYTPREQ BIT6    // 0/0/1/x Secondary Channel Master Port Transport Layer to Issue Early Request ...
    #define CND003_D15F0_P1_EARLYTPREQ BIT5    // 0/0/1/x Primary Channel Slave Port Transport Layer to Issue Early Request to ...
    #define CND003_D15F0_P0_EARLYTPREQ BIT4    // 0/0/1/x Primary Channel Master Port Transport Layer to Issue Early Request to...
    #define CND003_D15F0_P3_NOOVER8K   BIT3    // 0/0/X/x Secondary Channel Slave Port Data Size Limit for a Single Data FIS (L...
    #define CND003_D15F0_P2_NOOVER8K   BIT2    // 0/0/x/x Secondary Channel Master Port Data Size Limit for a Single Data FIS (...
    #define CND003_D15F0_P1_NOOVER8K   BIT1    // 0/0/x/x Primary Channel Slave Port Data Size Limit for a Single Data FIS (Leg...
    #define CND003_D15F0_P0_NOOVER8K   BIT0    // 0/0/x/x Primary Channel Master Port Data Size Limit for a Single Data FIS (Le...
#define CND003_D15F0_CHN_TRANSPORT_MISC_CTL 0x82 // Channel TransPort Miscellaneous Control
    #define CND003_D15F0_P3_ENBIST4SLV BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_P2_ENBIST4SLV BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_P1_ENBIST4SLV BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_P0_ENBIST4SLV BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_P3_LESSBUF    BIT3    // 0/0/x/x Secondary Channel Slave Port FIFO Flow Control, Set Water Mark for FI...
    #define CND003_D15F0_P2_LESSBUF    BIT2    // 0/0/x/x Secondary Channel Master Port FIFO Flow Control, Set Water Mark for F...
    #define CND003_D15F0_P1_LESSBUF    BIT1    // 0/0/x/x Primary Channel Slave Port FIFO Flow Control, Set Water Mark for FIFO...
    #define CND003_D15F0_P0_LESSBUF    BIT0    // 0/0/x/x Primary Channel Master Port FIFO Flow Control, Set Water Mark for FIF...
#define CND003_D15F0_SATA_PHY_PM_MODE 0x84 // SATA PHY Power Management Mode
    #define CND003_D15F0_R85B7             BIT7            // 0/x/x/x Reserved
    #define CND003_D15F0_PN_DISPARPWR      (BIT5 + BIT6)   // 11b/11/x/10 Settings for Hardware Timer Activated Partial/Slumber Mode ? Port n
    #define CND003_D15F0_PN_PWRCKSEL_4_0   0x1F            // 10000b/x/0Fh/0Fh For RAID Mode:
#define CND003_D15F0_SECONDARY_CHN_SLAVE_PORT_RESET_STATE_MACHINE_AND_STA_UNDER_SLAVE_MODE 0x85 // Secondary Channel Slave Port Reset State Machine and Status under Slave Mode
    #define CND003_D15F0_P3_RSTSM          0xF0            // 0/x/x/x Port Reset State Mechine
    #define CND003_D15F0_P3_SLV_CRCERR_STS BIT3            // 0/x/x/x Port Memory Read Cycle Is Busy Now When Works as Slave Mode
    #define CND003_D15F0_P3_SLVMEMR_BUSY   BIT2            // 0/x/x/x Port CRC Error Status When Works as Slave Mode
    #define CND003_D15F0_R85B_1_0          (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_D15F0_SECONDARY_CHN_MASTER_PORT_RESET_STATE_MACHINE_AND_STA_UNDER_SLAVE_MODE 0x86 // Secondary Channel Master Port Reset State Machine and Status under Slave Mode
    #define CND003_D15F0_P2_RSTSM          0xF0            // 0/x/x/x Port Reset State Mechine
    #define CND003_D15F0_P2_SLV_CRCERR_STS BIT3            // 0/x/x/x Port Memory read Cycle Is Busy Now When Works as Slave Mode
    #define CND003_D15F0_P2_SLVMEMR_BUSY   BIT2            // 0/x/x/x Port CRC Error Status When Work as Slave Mode
    #define CND003_D15F0_R86B_1_0          (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_D15F0_PRIMARY_CHN_SLAVE_PORT_RESET_STATE_MACHINE_AND_STA_UNDER_SLAVE_MODE 0x87 // Primary Channel Slave Port Reset State Machine and Status under Slave Mode
    #define CND003_D15F0_P1_RSTSM          0xF0            // 0/x/x/x Port Reset State Mechine
    #define CND003_D15F0_P1_SLV_CRCERR_STS BIT3            // 0/x/x/x Port Memory Read Cycle Is Busy Now When Work as Slave Mode
    #define CND003_D15F0_P1_SLVMEMR_BUSY   BIT2            // 0/x/x/x Port CRC Error Status When Works as Slave Mode
    #define CND003_D15F0_R87B_1_0          (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_D15F0_PRIMARY_CHN_MASTER_PORT_RESET_STATE_MACHINE_AND_STA_UNDER_SLAVE_MODE 0x88 // Primary Channel Master Port Reset State Machine and Status under Slave Mode
    #define CND003_D15F0_P0_RSTSM          0xF0            // 0/x/x/x Port Reset State Mechine
    #define CND003_D15F0_P0_SLV_CRCERR_STS BIT3            // 0/x/x/x Port Memory Read Cycle Is Busy Now When Works as Slave Mode
    #define CND003_D15F0_P0_SLVMEMR_BUSY   BIT2            // 0/x/x/x Port CRC Error Status When Works as Slave Mode
    #define CND003_D15F0_R88B_1_0          (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_D15F0_PATA_SATA_MISC_CTLS 0x89 // PATA/SATA Miscellaneous Controls
    #define CND003_D15F0_P3_DIS_W4D2H          BIT7    // 0/0/x/x Secondary Channel Slave Port Pass Command Even without First D2H FIS ...
    #define CND003_D15F0_P2_DIS_W4D2H          BIT6    // 0/0/x/x Secondary Channel Master Port Pass Command Even without First D2H FIS...
    #define CND003_D15F0_P1_DIS_W4D2H          BIT5    // 0/0/x/x Primary Channel Slave Port Pass Command Even without First D2H FIS Is...
    #define CND003_D15F0_P0_DIS_W4D2H          BIT4    // 0/0/x/x Primary Channel Master Port Pass Command Even without First D2H FIS I...
    #define CND003_D15F0_P3_EN_CHKPMP_SWRST    BIT3    // 0/0/x/x Secondary Channel Slave Port Check if PMP Field Is Correct for a Soft...
    #define CND003_D15F0_P2_EN_CHKPMP_SWRST    BIT2    // 0/0/x/x Secondary Channel Master Port Check if PMP Field Is Correct for a Sof...
    #define CND003_D15F0_P1_EN_CHKPMP_SWRST    BIT1    // 0/0/x/x Primary Channel Slave Port Check if PMP Field Is Correct for a Softwa...
    #define CND003_D15F0_P0_EN_CHKPMP_SWRST    BIT0    // 0/0/x/x Primary Channel Master Port Check if PMP Field Is Correct for a Softw...
#define CND003_D15F0_SATA_CTL_REG_4_Z1 0x8A // SATA Control Register 4
    #define CND003_D15F0_R8AB7         BIT7            // 0/x/x/x Reserved
    #define CND003_D15F0_R8AB6         BIT6            // 0/x/x/x Reserved
    #define CND003_D15F0_RSTD2HCKSEL   (BIT4 + BIT5)   // 0/0/x/x Soft Reset Time out Timer Setting
    #define CND003_D15F0_P3_ENRSTTOUT  BIT3            // 0/0/x/x Secondary Channel Slave Port Enable Port Soft Reset Time Out
    #define CND003_D15F0_P2_ENRSTTOUT  BIT2            // 0/0/x/x Secondary Channel Master Port Enable Port Soft Reset Time Out
    #define CND003_D15F0_P1_ENRSTTOUT  BIT1            // 0/0/x/x Primary Channel Slave Port Enable Port Soft Reset Time Out
    #define CND003_D15F0_P0_ENRSTTOUT  BIT0            // 0/0/x/x Primary Channel Master Port Enable Port Soft Reset Time Out
#define CND003_D15F0_SATA_CTL_REG_5_Z1 0x8B // SATA Control Register 5
    #define CND003_D15F0_R8BB7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_OOB2BURST_LEN_EN  BIT6    // 0/x/x/x Check Two Bursts to Judge COMMINIT and COMWAKE When OOB Is Received f...
    #define CND003_D15F0_SPINGPWR_EN       BIT5    // 0/x/x/x Let Spin up Gating TXPWR, RXPWR into TX_P2 / RX_P2
    #define CND003_D15F0_ENASYNR3TIMES     BIT4    // 0/0/x/x Only Try to Re-OOB 3 Times
    #define CND003_D15F0_EN_TPRXRDY2T_2    BIT3    // 0/x/x/X Reserved
    #define CND003_D15F0_R8BB2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_DISHOLD_EXTEND    BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_PMSTATE_MUX_EN    BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_PHY_DRIVE_CTL_WHEN_CHANGE_SRST 0x8C // SATA PHY Drive Control When Change SRST
    #define CND003_D15F0_SADIS_SRST_RSTDRVS    BIT7    // 0/x/x/x Reset Drive Select to Master When Changing Device Control Register Bi...
    #define CND003_D15F0_SADIS_DIAG_RSTDRVS    BIT6    // 0/x/x/x Reset Drive Select to Master When Issuing Diagnostic Command for the ...
    #define CND003_D15F0_SBDIS_SRST_RSTDRVS    BIT5    // 0/x/x/x Reset Drive Select to Master When Changing Device Control Register Bi...
    #define CND003_D15F0_SBDIS_DIAG_RSTDRVS    BIT4    // 0/x/x/x Reset Drive Select to Master When Issuing Diagnostic Command for the ...
    #define CND003_D15F0_R8CB3                 BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_R8CB2                 BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_R8CB1                 BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_SETWAKE_REQN          BIT0    // 0/x/x/x Assert Wakeup (from Partial/Slumber) Request to Port n PHY
#define CND003_D15F0_SATA_TXCDC_CTL 0x8D // SATA TXCDC control
    #define CND003_D15F0_R8DB7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_R8DB6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_R8DB5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_MA_STRICT_EN      BIT4    // 0/x/x/x Downstream Request Master-abort Condition Selection
    #define CND003_D15F0_F_P2CW16QWMAX     BIT3    // 0/x/x/x Force P2C Write Request?S Max Length to 16QW
    #define CND003_D15F0_F_P2CR16QWMAX     BIT2    // 0/x/x/x Force P2C Read Request?S Max Length to 16QW
    #define CND003_D15F0_TXCDC_TXCLKDYNEN  BIT1    // 0/0/1/1 SAPHYB_TXCDC TXCLK Dynamic Clock Enable
    #define CND003_D15F0_TXCDC_FIFORCK_SEL BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_SATA_SPEED_STA_CTL 0x8E // SATA Speed Status Control
    #define CND003_D15F0_LKTXCLRPMEN           BIT7    // 1b/x/x/x Link Tx State clear Partial/Slumber Request Enable
    #define CND003_D15F0_MSIXCAPDIS            BIT6    // 0/x/x/x MSIX Capability Disable
    #define CND003_D15F0_LDPIOCNTRPSEL         BIT5    // 0/x/x/x Use Posedge of LDPIOCNT to Sample Transfer Count Value in PIO SETUP FIS
    #define CND003_D15F0_ENRDMAECFLH           BIT4    // 1b/x/x/x DMA Read finish Clear Flush Enable
    #define CND003_D15F0_MMSI_DISABLE          BIT3    // 0/x/x/x Multiple MSI Disable
    #define CND003_D15F0_TST_EIDLEFORCE0_EN    BIT2    // 0/x/x/x Force RX EIDLE SQUELCH  to 0 when Doing Internal Loop Back Testing.
    #define CND003_D15F0_DMAR_INTG_GB          BIT1    // 0/x/x/x Interrupt Gating Method during DMA Read
    #define CND003_D15F0_SPDCLRSRC_SEL         BIT0    // 0/x/x/x Speed Status Cleared by PHYRDY or DEVDET
#define CND003_D15F0_SATA_PHY_TEST_SIGNALS_OUTPUT_CTL_2 0x8F // SATA PHY Test Signals Output Control 2
    #define CND003_D15F0_SELBISTERR        BIT7            // 0/x/x/x Select BIST Error Signal to Be Output to SATAERR
    #define CND003_D15F0_SELSLVERR         BIT6            // 0/x/x/x Slave Error Selection
    #define CND003_D15F0_R8FB_5_4          (BIT4 + BIT5)   // 0/x/x/x Reserved
    #define CND003_D15F0_SATA_HDIM_BIST    BIT3            // 0/x/x/x Enable HDMI-SATA BIST
    #define CND003_D15F0_MIS_MATCH_CON     BIT2            // 0/x/x/x Phy BIST Pattern Mismatch
    #define CND003_D15F0_R8FB1             BIT1            // 0/x/x/x Reserved
    #define CND003_D15F0_R8FB0             BIT0            // 0/x/x/x Reserved
#define CND003_D15F0_SATA_BIST_ACTIVATE_FIS_DATA_DWORD_1 0x90 // SATA BIST Activate FIS Data Dword 1
    #define CND003_D15F0_BIST_FISDW1 CND003_D15F0_SATA_BIST_ACTIVATE_FIS_DATA_DWORD_1 // 55555555h/x/x/x These four bytes are (part of) the data used for the followi...
#define CND003_D15F0_SATA_BIST_ACTIVATE_FIS_DATA_DWORD_2 0x94 // SATA BIST Activate FIS Data Dword 2
    #define CND003_D15F0_BIST_FISDW2 CND003_D15F0_SATA_BIST_ACTIVATE_FIS_DATA_DWORD_2 // AAAA AAAAh/x/x/x These four bytes contain the bottom half of the data used fo...
#define CND003_D15F0_SATA_BIST_ACTIVATE_FIS_MODES_CMDS_DEFINED_BY_THE_SATA_SPECIFICATION 0x98 // SATA BIST Activate FIS Modes / Commands Defined by the SATA Specification
    #define CND003_D15F0_FAR_TXONLY    BIT7    // 0/x/x/x Far End Transmit Only Mode (BIST_T command)
    #define CND003_D15F0_BYPASS_ALIGN  BIT6    // 0/x/x/x Bypass Transmit ALIGN Primitive (BIST_T option ?a?)
    #define CND003_D15F0_BYPASS_SCR    BIT5    // 0/x/x/x Bypass Scramble (BIST_T option ?s?)
    #define CND003_D15F0_FAR_RETLBK    BIT4    // 0/x/x/x Far End Retimed Loopback (BIST_L command)
    #define CND003_D15F0_FAR_AFEBLK    BIT3    // 0/x/x/x Far End Analog (AFE) Loopback (Not supported)
    #define CND003_D15F0_TXPRIMONLY    BIT2    // 0/x/x/x Primitive Bit (Not supported)
    #define CND003_D15F0_R98B1         BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_VDRTESTMODE   BIT0    // 0/x/x/x Vender Specific Test Mode (Not supported)
#define CND003_D15F0_SATA_BIST_ACTIVATE_FIS_STA 0x99 // SATA BIST Activate FIS Status
    #define CND003_D15F0_LB_BIST_CYC       BIT7                    // 0/R/x/x Selected Port in Receive Loopback Mode (BIST_L)
    #define CND003_D15F0_TXBIST_CYC        BIT6                    // 0/R/x/x Selected port in Transmit Loopback Mode (BIST_T)
    #define CND003_D15F0_TXBIST_ERR_STS    BIT5                    // 0/R/x/x BIST Error Detected for the Selected Port
    #define CND003_D15F0_TXBIST_BSY        BIT4                    // 0/R/x/x ?1? Indicates that the BIST Is Active at the Time of Inquiry for the ...
    #define CND003_D15F0_R99B_3_1          (BIT1 + BIT2 + BIT3)    // 0/x/x/x Reserved
    #define CND003_D15F0_BISTRUN           BIT0                    // 0/x/x/x Send BIST Activate FIS / BIST Status to Port
#define CND003_D15F0_AHCI_BIST_CTL 0x9A // AHCI BIST Control
    #define CND003_D15F0_AH_LB_BIST_CYC    BIT7    // 0/R/x/x AHCI In Receive Loop Back Mode
    #define CND003_D15F0_AH_TXBIST_CYC     BIT6    // 0/R/x/x AHCI In Transmit Loop Back Mode
    #define CND003_D15F0_AH_TXBIST_BSY     BIT5    // 0/R/x/x AHCI BIST Busy Status
    #define CND003_D15F0_AH_TXBIST_ERR     BIT4    // 0/R/x/x AHCI BIST Error Status
    #define CND003_D15F0_R9AB_3_0          0xF     // 0/x/x/x Reserved
#define CND003_D15F0_LEGACY_SATA_PMP_MAP_STA_FOR_PORT_2_PORT_3 0x9C // Legacy SATA PMP Map Status for Port 2 ~ Port 3
    #define CND003_D15F0_P3_SNTF_H 0xFF000000  // 0/x/x/x Reserved
    #define CND003_D15F0_P3_SNTF_L 0xFF0000    // 0/x/X/x Reserved
    #define CND003_D15F0_P2_SNTF_H 0xFF00      // 0/x/X/x Reserved
    #define CND003_D15F0_P2_SNTF_L 0xFF        // 0/x/X/x Reserved
#define CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_STA_SSTA_IN_SATA_SPECIFICATION 0xA0 // Legacy SATA Primary channel master Port Status (SStatus in SATA Specification)
    #define CND003_D15F0_S_P0_GEN_SPD      (BIT4 + BIT5)   // 0/R/x/x The Negotiated Interface Communication Speed Established (SPD Field)
    #define CND003_D15F0_S_P0_PHYSLUMBER   BIT3            // 0/R/x/x Slumber Mode Power Management Status (IPM Field)
    #define CND003_D15F0_S_P0_PHYPARTIAL   BIT2            // 0/R/x/x Partial Mode Power Management Status (IPM Field)
    #define CND003_D15F0_S_P0_PHYRDY       BIT1            // 0/R/x/x PHY Communication Established (DET Field) 
    #define CND003_D15F0_S_P0_DEVDET       BIT0            // 0/R/x/x Device Detected (DET Field)
#define CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_STA_SSTA_IN_SATA_SPECIFICATION 0xA1 // Legacy SATA Primary channel slave Port Status (SStatus in SATA Specification)
    #define CND003_D15F0_S_P1_GEN_SPD      (BIT4 + BIT5)   // 0/R/x/x The Negotiated Interface Communication Speed Established (SPD Field)
    #define CND003_D15F0_S_P1_PHYSLUMBER   BIT3            // 0/R/x/x Slumber Mode Power Management Status (IPM Field)
    #define CND003_D15F0_S_P1_PHYPARTIAL   BIT2            // 0/R/x/x IPM Field: Partial Mode Power Management Status
    #define CND003_D15F0_S_P1_PHYRDY       BIT1            // 0/R/x/x PHY Communication Established (DET Field) 
    #define CND003_D15F0_S_P1_DEVDET       BIT0            // 0/R/x/x Device Detected (DET Field)
#define CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_STA_SSTA_IN_SATA_SPECIFICATION 0xA2 // Legacy SATA secondary channel master Port Status (SStatus in SATA Specification)
    #define CND003_D15F0_S_P2_GEN_SPD      (BIT4 + BIT5)   // 0/R/x/x Reserved
    #define CND003_D15F0_S_P2_PHYSLUMBER   BIT3            // 0/R/x/x Reserved
    #define CND003_D15F0_S_P2_PHYPARTIAL   BIT2            // 0/R/x/x Reserved
    #define CND003_D15F0_S_P2_PHYRDY       BIT1            // 0/R/x/x Reserved
    #define CND003_D15F0_S_P2_DEVDET       BIT0            // 0/R/x/x 
#define CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_STA_SSTA_IN_SATA_SPECIFICATION 0xA3 // Legacy SATA secondary channel slave Port Status (SStatus in SATA Specification)
    #define CND003_D15F0_S_P3_GEN_SPD      (BIT4 + BIT5)   // 0/R/x/x Reserved
    #define CND003_D15F0_S_P3_PHYSLUMBER   BIT3            // 0/R/x/x Reserved
    #define CND003_D15F0_S_P3_PHYPARTIAL   BIT2            // 0/R/x/x Reserved
    #define CND003_D15F0_S_P3_PHYRDY       BIT1            // 0/R/x/x Reserved
    #define CND003_D15F0_S_P3_DEVDET       BIT0            // 0/R/x/x Reserved
#define CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION 0xA4 // Legacy SATA primary channel master Port Control (SControl in SATA Specification)
    #define CND003_D15F0_RA4B_7_4          0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_P0_DISSLUMBER     BIT3    // 1b/1/x/0 For IPM Field = 0010b:
    #define CND003_D15F0_P0_DISPARTIAL     BIT2    // 1b/1/x/0 For IPM Field = 0001b:
    #define CND003_D15F0_P0_DISABLE_SATA   BIT1    // 0/0/x/0 For DET Field = 0100b:
    #define CND003_D15F0_P0_SATAINIT       BIT0    // 0/0/x/x For DET Field = 0001b:
#define CND003_D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION 0xA5 // Legacy SATA primary channel slave Port Control (SControl in SATA Specification)
    #define CND003_D15F0_RA5B_7_4          0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_P1_DISSLUMBER     BIT3    // 1b/1/x/0 For IPM Field = 0010b:
    #define CND003_D15F0_P1_DISPARTIAL     BIT2    // 1b/1/x/0 For IPM Field = 0001b:
    #define CND003_D15F0_P1_DISABLE_SATA   BIT1    // 0/0/x/0 For DET Field = 0100b:
    #define CND003_D15F0_P1_SATAINIT       BIT0    // 0/0/x/0 For DET Field = 0001b:
#define CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION 0xA6 // Legacy SATA secondary channel master Port Control (SControl in SATA Specification)
    #define CND003_D15F0_RA6B_7_4          0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_P2_DISSLUMBER     BIT3    // 1b/1/x/0 Reserved
    #define CND003_D15F0_P2_DISPARTIAL     BIT2    // 1b/1/x/0 Reserved
    #define CND003_D15F0_P2_DISABLE_SATA   BIT1    // 0/0/x/0 Reserved
    #define CND003_D15F0_P2_SATAINIT       BIT0    // 0/0/x/0 Reserved
#define CND003_D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION 0xA7 // Legacy SATA secondry channel slave Port Control (SControl in SATA Specification)
    #define CND003_D15F0_RA7B_7_4          0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_P3_DISSLUMBER     BIT3    // 1b/1/x/0 Reserved
    #define CND003_D15F0_P3_DISPARTIAL     BIT2    // 1b/1/x/0 Reserved
    #define CND003_D15F0_P3_DISABLE_SATA   BIT1    // 0/0/x/0 Reserved
    #define CND003_D15F0_P3_SATAINIT       BIT0    // 0/0/x/0 Reserved
#define CND003_D15F0_LEGACY_SATA_PORT_SERR_REG_DEFINED_IN_SATA_SPECIFICATION 0xA8 // Legacy SATA Port SError Register Defined in SATA Specification
    #define CND003_D15F0_RABB_7_4          0xF0000000  // 0/x/x/x Reserved
    #define CND003_D15F0_SCR_ERROR_STS27   BIT27       // 0/x/x/x Diag Field A bit: Port Selector Presence Detected for the selected port
    #define CND003_D15F0_SCR_ERROR_STS26   BIT26       // 0/x/x/x Diag Field x bit: Exchanged as determined by reception of COMINIT for...
    #define CND003_D15F0_SCR_ERROR_STS25   BIT25       // 0/x/x/x Diag Field F bit: Unrecognized FIS Type for the selected port
    #define CND003_D15F0_SCR_ERROR_STS24   BIT24       // 0/x/x/x Diag Field T bit: Transport State Transition Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS23   BIT23       // 0/x/x/x Diag Field S bit: Link Sequence Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS22   BIT22       // 0/x/x/x Diag Field H bit: Handshake Error fot the selected port
    #define CND003_D15F0_SCR_ERROR_STS21   BIT21       // 0/x/x/x Diag Field C bit: CRC Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS20   BIT20       // 0/x/x/x Diag Field D bit: Disparity Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS19   BIT19       // 0/x/x/x Diag Field B bit: 10B to 8B Decode Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS18   BIT18       // 0/x/x/x Diag Field W bit: COMWAKE Detected for the selected port
    #define CND003_D15F0_SCR_ERROR_STS17   BIT17       // 0/x/x/x Diag Field I bit: PHY Internal Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS16   BIT16       // 0/x/x/x Diag Field N bit: PhyRdy Change for the selected port
    #define CND003_D15F0_RA9B_7_4          0xF000      // 0/x/x/x Reserved
    #define CND003_D15F0_SCR_ERROR_STS11   BIT11       // 0/x/x/x Err Field E bit: Internal Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS10   BIT10       // 0/x/x/x Err Field P bit: Protocol Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS9    BIT9        // 0/x/x/x Err Field C bit: Non-recovered Persistent Communication or Data Integ...
    #define CND003_D15F0_SCR_ERROR_STS8    BIT8        // 0/x/x/x Err Field T bit: Non-recovered Transient Data Integrity Error for the...
    #define CND003_D15F0_RA8B_7_2          0xFC        // 0/x/x/x Reserved
    #define CND003_D15F0_SCR_ERROR_STS1    BIT1        // 0/x/x/x Err Field M bit: Recovered Communications Error for the selected port
    #define CND003_D15F0_SCR_ERROR_STS0    BIT0        // 0/x/x/x Err Field I bit: Recovered Data Integrity Error for the selected port    
#define CND003_D15F0_SATA_FUN_LEVEL_RESET_FLR 0xB0 // SATA Function Level Reset (FLR)
    #define CND003_D15F0_RB3B_7_2      0xFC000000  // 0/x/x/x Reserved
    #define CND003_D15F0_FLR_CAP       BIT25       // 0/x/x/x Set to 1b to Indicate Support of Function Level Reset (FLR)
    #define CND003_D15F0_TP_CAP        BIT24       // 0/x/x/x Set to 1b to Indicate Support of the Transactions Pending(TP) Bit
    #define CND003_D15F0_FLR_LEN       0xFF0000    // 06h/x/x/x FLR Length
    #define CND003_D15F0_FLRID_15_8    0xFF00      // C0h/x/x/X Next Capability Pointer
    #define CND003_D15F0_FLRID_7_0     0xFF        // 13h/x/x/X Capability ID for FLR
#define CND003_D15F0_SATA_FUN_LEVEL_RESET_FLR_2 0xB3
#define CND003_D15F0_SATA_FUN_LEVEL_RESET_FLR_Z1 0xB4 // SATA Function Level Reset (FLR)
    #define CND003_D15F0_INITFLR   BIT0    // 0/x/x/X Function Level Reset Initial
#define CND003_D15F0_SATA_FUN_LEVEL_RESET_FLR_Z2 0xB5 // SATA Function Level Reset (FLR)
    #define CND003_D15F0_TXP   BIT0    // 0/x/x/X Upstream Bus not Idle, or SATA Function Still On-going Indication
#define CND003_D15F0_LEGACY_SATA_OOB_KICK_OFF_CTL 0xB8 // Legacy SATA OOB Kick-Off Control
    #define CND003_D15F0_RB8B7     BIT7            // 0/x/x/x Reserved
    #define CND003_D15F0_RB8B6     BIT6            // 0/x/x/x Reserved
    #define CND003_D15F0_RB8B5     (BIT4 + BIT5)   // 0/x/x/x Reserved
    #define CND003_D15F0_P3_SPINUP BIT3            // 0/x/x/x OOB Kick-Off Control for Secondary Channel Slave Port ((Random))
    #define CND003_D15F0_P2_SPINUP BIT2            // 0/x/x/x OOB Kick-Off Control for Secondary Channel Master Port ((Random))
    #define CND003_D15F0_P1_SPINUP BIT1            // 0/x/x/x OOB Kick-Off Control for Primary Channel Slave Port ((Random))
    #define CND003_D15F0_P0_SPINUP BIT0            // 0/x/x/x OOB Kick-Off Control for Primary Channel Master Port ((Random))
#define CND003_D15F0_INTR_OPTIONAL_REG 0xB9 // Interrupt Optional Register
    #define CND003_D15F0_RB9B_7_3      0xF8                    // 0/x/x/x Reserved
    #define CND003_D15F0_INTPIN_2_0    (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Reserved
#define CND003_D15F0_LED_CTL_OPTIONAL_REG 0xBB // LED Control Optional Register
    #define CND003_D15F0_RBEB_7_4      0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_LED_CTL_3_0   0xF     // 0h/x/x/x SATA LED and Port Status Mapping
#define CND003_D15F0_RESERVED_Z1 0xBC // Reserved
    #define CND003_D15F0_SUBVID_RSV CND003_D15F0_RESERVED_Z1 // 0000h/x/x/x Reserved
#define CND003_D15F0_VID_ENCLOUSER_MANEGEMENT_BUFFER_CTL_OPTIONAL_REG 0xBE // Vendor ID/Enclouser Manegement Buffer Control Optional Register
    #define CND003_D15F0_RBEB_7_5      (BIT5 + BIT6 + BIT7)    // 0/x/x/x Reserved
    #define CND003_D15F0_EM_LOC_SEL    BIT4                    // 0b/x/x/x 0: Enclosure Manegement Buffer Offset is 500h
    #define CND003_D15F0_SUBID_SEL     BIT3                    // 0b/x/x/x Subsystem ID Selection Control
    #define CND003_D15F0_SUBVID_SEL    BIT2                    // 0b/x/x/x Subsystem Vendor ID Selection control
    #define CND003_D15F0_DID_RID_LOCK  BIT1                    // 0b/x/x/x Device ID and Revision ID lock control
    #define CND003_D15F0_VID_LOCK      BIT0                    // 0b/x/x/x VID lock control
#define CND003_D15F0_RESERVED_Z2 0xBF // Reserved
    #define CND003_D15F0_RBFB_7_0 CND003_D15F0_RESERVED_Z2 // 00h/x/x/x Reserved
#define CND003_D15F0_PM_IF_REV 0xC2 // Power Management Interface Revision
    #define CND003_D15F0_PMREV_15_11   0xF800                  // 08h/08h/x/x PSUP, Indicates the States That Can Generate PME#
    #define CND003_D15F0_PMREV_2_0     (BIT0 + BIT1 + BIT2)    // 010b/R/x/x Power Management Interface Revision
#define CND003_D15F0_PM_IF_REV_2 0xC3
#define CND003_D15F0_PM_CAP_STA 0xC4 // Power Management Capability Status
    #define CND003_D15F0_PME_STS       BIT15           // 0/R/x/x PME Status
    #define CND003_D15F0_PME_ENABLE    BIT8            // 0/0/x/x PME Enable
    #define CND003_D15F0_PST1          (BIT0 + BIT1)   // 00b/0/x/x Power Management Capability Status ((Random))
#define CND003_D15F0_PM_CAP_STA_2 0xC5 // Power Management Capability Status
#define CND003_D15F0_DATA_REG_FOR_PM_CAP 0xC6 // Data Register for Power Management Capability
#define CND003_D15F0_SSID_OPTIONAL_REG 0xC8 // Subsystem ID Optional Register
    #define CND003_D15F0_SUBID_BD CND003_D15F0_SSID_OPTIONAL_REG // 0000h/x/x/x Subsystem ID optional register
#define CND003_D15F0_SVID_OPTIONAL_REG 0xCA // Subsystem Vendor ID Optional Register
    #define CND003_D15F0_SUBVID_BD CND003_D15F0_SVID_OPTIONAL_REG // 0000h/x/x/x Subsystem Vendor ID (Rx2C-2D) optional register
#define CND003_D15F0_RESERVED_Z3 0xCC // Reserved
    #define CND003_D15F0_DEVID_AHCI_RSV CND003_D15F0_RESERVED_Z3 // 0000h/x/x/x Reserved
#define CND003_D15F0_RESERVED_Z4 0xCE // Reserved
    #define CND003_D15F0_REVID_RSV CND003_D15F0_RESERVED_Z4 // 0/x/x/x Reserved
#define CND003_D15F0_MISC_REGS 0xD0 // Misc Registers ((382_Rx49))
    #define CND003_D15F0_ENGHCSAECLK_GATE  BIT7    // 0/x/x/1 GHC GCLK Dynamic Clock Enable
    #define CND003_D15F0_ENGHCECLK150_GATE BIT6    // 0/x/x/1 GHC ECLK150 Clock Dynamic Enable
    #define CND003_D15F0_RD0B5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_RD0B4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_RD0B3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_RD0B2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_EN_SCLOCK_GATE    BIT1    // 0/x/x/x SGPIO SClock Dynamic Gating Enable
    #define CND003_D15F0_SOFT_ENAHCI       BIT0    // 0/x/x/x Force Controller AHCI Function
#define CND003_D15F0_AHCI_MISC_REGS 0xD1 // AHCI Misc Registers ((382_Rx4A))
    #define CND003_D15F0_PASS_FIRSTD2HX    BIT7    // 0/0/x/x Always Write First D2H to Memory Region (Test only)
    #define CND003_D15F0_PIPE_RFISMEM      BIT6    // 0/0/x/x Pipeline RFIS to Memory Cycle (Test Only)
    #define CND003_D15F0_SMSI_BYPIS        BIT5    // 0/x/x/x Single MSI Assertion Method
    #define CND003_D15F0_FETCHCFIS64       BIT4    // 0/0/x/x Fetch All 64 Bytes CFIS Field of Command Table
    #define CND003_D15F0_EN_RFISUPDATE     BIT3    // 0/0/x/x AHCI Update Received FIS to Memory Function
    #define CND003_D15F0_EN_DMABCUPDATE    BIT2    // 1b/1/x/x AHCI DMA Update Byte Count Function
    #define CND003_D15F0_RD1B1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_ENCLCACHE         BIT0    // 0/x/x/x AHCI Command List CTBA (Command Table Descriptor Base Address) Cache ...
#define CND003_D15F0_AHCI_DYNAMIC_CLK_ENABLE 0xD2 // AHCI Dynamic Clk Enable
    #define CND003_D15F0_RD2B7 BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_RD2B6 BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_RD2B5 BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_RD2B4 BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_RD2B3 BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_RD2B2 BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_RD2B1 BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_RD2B0 BIT0    // 0/x/x/x Reserved
#define CND003_D15F0_AHCI_TRANSPORT_MISC_CTL 0xD3 // AHCI Transport Misc. Control ((382_Rx52))
    #define CND003_D15F0_AHCI_SGSTOP       BIT7    // 0/0/x/x Software Issued AHCI DMA Stop (Test Mode Only)
    #define CND003_D15F0_AHCI_EARLYTPREQ   BIT6    // 0/0/1/x Transport Issues Early Request to Link for Better Performance
    #define CND003_D15F0_RD3B5             BIT5    // 0/0/x/x Reset AHCI Transport Queue DMA Transfer Count (Test Only)
    #define CND003_D15F0_AHCI_NOOVER8K     BIT4    // 0/0/x/x Signal Data FIS Transmission (AHCI Controller Only)
    #define CND003_D15F0_AHCI_ENBIST4SLV   BIT3    // 0/x/x/x BIST FIS (AHCI Controller Only)
    #define CND003_D15F0_RD3B2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_RD3B1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_AHCI_RSTSHADREG   BIT0    // 0/x/x/x Reset Shadow (Test Mode Only)
#define CND003_D15F0_AHCI_DEV_MODE_TESTING_REG_1_TEST_MODE_ONLY 0xD5 // AHCI Device Mode Testing Register 1 (Test Mode Only)
    #define CND003_D15F0_RD5B7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_RD5B6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_RD5B5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_RD5B4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_RD5B3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_RD5B2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_AH_SLVMEMR_BUSY   BIT1    // 0/x/x/x Port Was Busy on Memory Read Cycle
    #define CND003_D15F0_AH_SLV_CRCERR_STS BIT0    // 0/x/x/x Port CRC Error Status
#define CND003_D15F0_AHCI_GHC_CAP2_OPTIONAL_REGS_AND_SLAVE_TP_REGS 0xD6 // AHCI GHC CAP2 Optional Registers and Slave TP registers
    #define CND003_D15F0_SUP_APST  BIT7    // 1b/x/x/x Set Automatic Partial to Slumber Transitions Function
    #define CND003_D15F0_SUP_NVMP  BIT6    // 0/x/x/x Set NVMHCI Present Function
    #define CND003_D15F0_SUP_BOH   BIT5    // 1b/x/x/x Set BIOS/OS Handoff Function
    #define CND003_D15F0_RD6B4     BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_RD6B_3_0  0xF     // 0/x/x/x Reserved
#define CND003_D15F0_AHCI_PMP_ERR_INTR_AND_ENCLOSURE_MANAGEMENT_OPTIONAL_REG 0xD7 // AHCI PMP_ERR Interrupt and Enclosure Management Optional Register
    #define CND003_D15F0_RD7B7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_RD7B6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_RD7B5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_SUPP_LED_BD   BIT4    // 1b/x/x/x Reserved
    #define CND003_D15F0_SUPP_SAFTE_BD BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_SUPP_SES2_BD  BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_SUPP_SGPIO_BD BIT1    // 1b/x/x/x Reserved
    #define CND003_D15F0_PMPERR_ENN    BIT0    // 0/x/x/x AHCI Portn PMP_ERR Interrupt (AHMMIOP1IS[23]) Guard Bit 
#define CND003_D15F0_SW_CTL_CI_SACT_ENTRY_RESET_TEST_MODE_ONLY 0xD8 // Software Control CI / SACT Entry Reset (Test Mode Only) ((382_Rx82))
    #define CND003_D15F0_SELCI_TAG     BIT7    // 0/x/x/x Indicates Port CI[TAG number] to Be Cleared
    #define CND003_D15F0_SELSACT_TAG   BIT6    // 0/x/x/x Indicates Port SACT[TAG number] to Be Cleared
    #define CND003_D15F0_SOFT_CLRTAG   BIT5    // 0/x/x/x Trigger Port CI/SACT TAG Clear Operation
    #define CND003_D15F0_CLR_TAG_4_0   0x1F    // 0/x/x/x TAG Number to Be Cleared
#define CND003_D15F0_SATA_SLAVE_TP_STA_TEST_MODE_ONLY 0xD9 // SATA Slave TP Status (Test Mode Only)
    #define CND003_D15F0_XSLV_FIS_NUM CND003_D15F0_SATA_SLAVE_TP_STA_TEST_MODE_ONLY // 0/R/x/x Parsing Port FIS Number When in Device Mode
#define CND003_D15F0_AHCI_PORT_IMPLEMENT_REGS 0xDA // AHCI Port Implement Registers
    #define CND003_D15F0_RDAB7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_RDAB6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_RDAB5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_RDAB4         BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_RDAB3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_RDAB2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_RDAB1         BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_PN_PORTIMP    BIT0    // 1b/x/x/x Port n Implemented
#define CND003_D15F0_AHCI_OPTIONAL_REG_AND_DYNAMIC_CTL_REGS 0xDB // AHCI Optional Register and Dynamic Control Registers
    #define CND003_D15F0_RDBB7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_SUP_PIOMDRQ   BIT6    // 1b/1/x/x Set Multiple DRQ Block
    #define CND003_D15F0_SUP_MPS       BIT5    // 1b/x/x/x Set Mechanical Presence Switch Function
    #define CND003_D15F0_SUP_SPINUP    BIT4    // 1b/x/x/x Set AHCI Staggered Spin-up Function
    #define CND003_D15F0_RDBB3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_RDBB2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_MSICAPDIS     BIT1    // 0/x/x/x AHCI MSI Capability Disable Control
    #define CND003_D15F0_SGPIO_INT_EN  BIT0    // 0/0/x/x SGPIO Interrupt Enable
#define CND003_D15F0_AHCI_DYNAMIC_CLK_CTL_REG_1 0xDC // AHCI Dynamic CLK Control Register 1
    #define CND003_D15F0_RDCB7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_RDCB6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_RDCB5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_RDCB4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_RDCB3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_RDCB2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_RDCB1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_EN_SATA_MPS_PN    BIT0    // 0b/x/x/x SATA Port n MPS Enable
#define CND003_D15F0_AHCI_DYNAMIC_CLK_CTL_REG_2 0xDD // AHCI Dynamic CLK Control Register 2
    #define CND003_D15F0_RDDB_7_4          0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_AHN_GCKDYNEN      BIT3    // 0/0/x/1 AHCI Port n Downstream GCLK Dynamic CLK Function Control
    #define CND003_D15F0_AHN_ECKDYNEN      BIT2    // 0/0/x/1 AHCI Port n ECLK150 Dynamic CLK Function Control
    #define CND003_D15F0_AHN_TPECKDYNEN    BIT1    // 0/0/x/1 AHCI Port n TPECLK Dynamic CLK Function Control
    #define CND003_D15F0_AHN_UPCLKDYNEN    BIT0    // 0/0/x/1 AHCI Portn Upstream SAECLK Dynamic CLK Function Control
#define CND003_D15F0_AHCI_CACHE_BIST_CTL 0xDE // AHCI Cache BIST Control
    #define CND003_D15F0_SUP_AHCISPD   0xF0    // 0011b/x/x/x AHCI Port Speed Support
    #define CND003_D15F0_LAT_BIST_ERR  BIT3    // 0/x/x/x AHCI Cache BIST Result
    #define CND003_D15F0_RDEB2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_LAT_BIST_BSY  BIT1    // 0/x/x/x AHCI Cache BIST Process
    #define CND003_D15F0_LAT_BIST_CYC  BIT0    // 0/0/x/x AHCI Cache BIST function Set
#define CND003_D15F0_AHCI_OPTIONAL_REG_0 0xEA // AHCI Optional Register 0
    #define CND003_D15F0_REAB7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_REAB6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_REAB5         BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_REAB4         BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_REAB3         BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_REAB2         BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_REAB1         BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_FBSDEV_SELN   BIT0    // 0/x/x/x Config MPthod for AHCI Port n FBS Port Multiplier Port Value of the N...
#define CND003_D15F0_AHCI_FBS_OPTIONAL_REG_1 0xEB // AHCI FBS Optional Register 1
    #define CND003_D15F0_REBB7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_REBB6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_TRG_SEL_DMA   BIT5    // 0/x/x/x Allow for sending CFIS between DMA Data, such as between DMASETUP and...
    #define CND003_D15F0_P2CRABT_INTEN BIT4    // 0/x/x/x P2C Read master abort PxIS.HBFS status assert enable
    #define CND003_D15F0_SUP_FBSADO    0xF     // 0/x/x/x Set AHCI FBS Active Device Optimization
#define CND003_D15F0_SATA_BACK_OPTIONAL_REGS 0xEC // SATA Back Optional Registers
    #define CND003_D15F0_RECB7             BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_RECB6             BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_RECB5             BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_RECB4             BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_RECB3             BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_RECB2             BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_RECB1             BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_PMACKIND3_ONLY    BIT0    // 0/x/x/x S3/S4 state Acknowledge in D3 State only
#define CND003_D15F0_SATA_CAP_REG_0 0xF0 // SATA Capability Register 0 ((SATACR0))
    #define CND003_D15F0_MAJREV    0xF00000    // 1h/R/x/x Major Revision
    #define CND003_D15F0_MINREV    0xF0000     // 0/R/x/x Minor Revision
    #define CND003_D15F0_NEXT      0xFF00      // 0/R/x/x Next Capability
    #define CND003_D15F0_SATACID   0xFF        // 12h/R/x/x Capability ID
#define CND003_D15F0_SATA_CAP_REG_1 0xF4 // SATA Capability Register 1 ((SATACR1))
    #define CND003_D15F0_BAROFST   0xFFF0      // 004h/R/x/x BAR Offset
    #define CND003_D15F0_BARLOC    0xF         // 8h/R/x/x BAR Location
#define CND003_D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS 0xF8 // AHCI Port Hotplug Optional Registers
    #define CND003_D15F0_SUP_SLPSLUM   BIT7    // 0/x/x/x Device Sleep Can Be Triggerd Only during Slumber Power State
    #define CND003_D15F0_SUP_AGRSLP    BIT6    // 0/x/x/x Aggressive Device Sleep Support
    #define CND003_D15F0_SUP_DEVSLP    BIT5    // 1b/x/x/x Device Sleep Support
    #define CND003_D15F0_PN_HPLUG_CAP  BIT0    // 1b/x/x/x Hot Plug Capable Port
#define CND003_D15F0_AHCI_GHC_CAP_OPTIONAL_REG_0 0xF9 // AHCI GHC CAP Optional Register 0
    #define CND003_D15F0_SUP_64ADR     BIT7    // 1b/x/x/x Set 64-bit Addressing
    #define CND003_D15F0_SUP_CMDQ      BIT6    // 1b/x/x/x Set Native Command Queuing
    #define CND003_D15F0_SUP_SNTF      BIT5    // 1b/x/x/x Set SNotification Register
    #define CND003_D15F0_SUP_LKPWR     BIT4    // 1b/x/x/x Set Aggressive Link Power Management
    #define CND003_D15F0_SUP_LED       BIT3    // 1b/x/x/x Set Activity LED
    #define CND003_D15F0_SUP_RSTBD     BIT2    // 1b/x/x/x Set Command List Override
    #define CND003_D15F0_SUP_AHCIONLY  BIT1    // 0/x/x/x Set AHCI Mode Only
    #define CND003_D15F0_SUP_PMP       BIT0    // 0/x/x/x Set Port Multiplier
#define CND003_D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1 0xFA // AHCI GHC CAP Back Optional Register 1
    #define CND003_D15F0_SUP_FBSS      BIT7            // 0b/x/x/x Set  FIS-based Switching Function
    #define CND003_D15F0_SUP_SLUM      BIT6            // 1b/x/x/x Set Slumber State Capable
    #define CND003_D15F0_SUP_PART      BIT5            // 1b/x/x/x Set Partial State Capable
    #define CND003_D15F0_SUP_CCCS      BIT4            // 1b/x/x/x Set Command Completion Coalescing Function
    #define CND003_D15F0_SUP_EMS       BIT3            // 1b/x/x/x Set Enclosure Management Function
    #define CND003_D15F0_SUP_SXS       BIT2            // 1b/x/x/x Set External SATA Function
    #define CND003_D15F0_SUP_CMDSLOTS  (BIT0 + BIT1)   // 11b/x/x/x Set Number of Command Slots Supported
#define CND003_D15F0_AHCI_GHC_CAP_AND_PORT_OPTIONAL_REG_2 0xFB // AHCI GHC CAP and Port Optional Register 2
    #define CND003_D15F0_RFCB_7_5      (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_D15F0_OFS_DIS       BIT5            // 0/x/x/x AHCI Overflow status (PxIS.OFS) Option bit
    #define CND003_D15F0_AHN_ESP_EN    BIT4            // 0/x/x/x Set AHCI Port n Extenal SATA Port Function
    #define CND003_D15F0_SUP_PORTSNUM  0xF             // 3h/x/x/x Set Number of Ports Supported
#define CND003_D15F0_AHCI_GHC_CAP_AND_PORT_OPTIONAL_REG_3 0xFC // AHCI GHC CAP and Port Optional Register 3
    #define CND003_D15F0_RFDB_7_4      0xF0    // 0/x/x/x Reserved
    #define CND003_D15F0_AHN_SET_SLPDM 0xF     // 0/x/x/x Device Sleep Idle Timeout (DITO) Multiplier for AHCI Port n
#define CND003_D15F0_AHCI_GHC_CAP_AND_PORT_OPTIONAL_REG_4 0xFD // AHCI GHC CAP and Port Optional Register 4
    #define CND003_D15F0_RFEB7     BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_RFEB6     BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_RFEB5     BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0_RFEB4     BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0_RFEB3     BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_RFEB2     BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0_RFEB1     BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0_AH_SLP_EN BIT0    // 0/x/x/x AHCI Portn  Device Sleep Enable
#define CND003_D15F0_SIMULATION_SPEED_UP_CTL 0xFE // Simulation speed up control
    #define CND003_D15F0_RFFB7         BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0_RFFB6         BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0_ASYNSPD       BIT5    // 0/x/x/x Async Recovery Timer clock speed up control for simulation
    #define CND003_D15F0_SPDUPG2TG1    BIT4    // 0/x/x/x OOB sequence and speed negotiation speed up control for simulation
    #define CND003_D15F0_TRDYSPDUP     BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0_INITSPDUP     BIT2    // 0/x/x/x EPHY Bandgap, Reference clock, MPLL, TPLL and RTN initial sequence sp...
    #define CND003_D15F0_AHSIM_ACC     BIT1    // 0/x/x/x AHCI CCC timer and DEVSLP timer acceleration for simulation
    #define CND003_D15F0_FASTDBNC      BIT0    // 0/x/x/x Fast Debounce control for simulation
#define CND003_D15F0_EPHY_DE_GLITCH_FUN_CTL 0xFF // EPHY De-glitch function control
    #define CND003_D15F0_RXEIDLE_FILTER_EN     BIT7            // 0/x/x/x Enable RX EIDLE signal filter function
    #define CND003_D15F0_RXEIDLE_ADDPULSE_EN   BIT6            // 0/x/x/x Host Add pulse in RXEIDLESQDET during speed negotiation at the time d...
    #define CND003_D15F0_RXEIDLE_ERRCHK_EN     BIT5            // 0/x/x/x RXEIDLESQDET de-glitch function using Decode/Disparity Error check me...
    #define CND003_D15F0_RXEIDLE_ERRCHK_TH     (BIT3 + BIT4)   // 10b/x/x/x Decode/Disparity Error threshold
    #define CND003_D15F0_RXEIDLE_ALIGNCHK_EN   BIT2            // 0/x/x/x RXEIDLESQDET de-glitch function using ALIGNp check method enable
    #define CND003_D15F0_RXEIDLE_ALIGNCHK_TH   (BIT0 + BIT1)   // 01b/x/x/x ALIGNp Check Time-out value
// D15F0 SATA EPHY INDEX-DATA
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL 0x1 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP03_RCVDETN_PHYB    BIT7    // 0/x/x/x Port 3 Receiver Detection Flag at TX- 
    #define CND003_D15F0EPHYINDEXDATA_EP03_RCVDETP_PHYB    BIT6    // 0/x/x/x Port 3 Receiver Detection Flag at TX+
    #define CND003_D15F0EPHYINDEXDATA_EP02_RCVDETN_PHYB    BIT5    // 0/x/x/x Port 2 Receiver Detection Flag at TX-
    #define CND003_D15F0EPHYINDEXDATA_EP02_RCVDETP_PHYB    BIT4    // 0/x/x/x Port 2 Receiver Detection Flag at TX+ 
    #define CND003_D15F0EPHYINDEXDATA_EP01_RCVDETN_PHYB    BIT3    // 0/x/x/x Port 1 Receiver Detection Flag at TX-
    #define CND003_D15F0EPHYINDEXDATA_EP01_RCVDETP_PHYB    BIT2    // 0/x/x/x Port 1 Receiver Detection Flag at TX+ 
    #define CND003_D15F0EPHYINDEXDATA_EP00_RCVDETN_PHYB    BIT1    // 0/x/x/x Port 0 Receiver Detection Flag at TX-
    #define CND003_D15F0EPHYINDEXDATA_EP00_RCVDETP_PHYB    BIT0    // 0/x/x/x Port 0 Receiver Detection Flag at TX+ 
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z1 0x2 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP03_RCVDET_PHYB BIT3    // 0/x/x/x PCIe Mode:
    #define CND003_D15F0EPHYINDEXDATA_EP02_RCVDET_PHYB BIT2    // 0/x/x/x PCIe Mode:
    #define CND003_D15F0EPHYINDEXDATA_EP01_RCVDET_PHYB BIT1    // 0/x/x/x PCIe Mode:
    #define CND003_D15F0EPHYINDEXDATA_EP00_RCVDET_PHYB BIT0    // 0/x/x/x PCIe Mode:
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z2 0x3 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TXPWRSETEN_PHYB    BIT3    // 0/x/x/x Port 3 TX Power Status Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TXPWRSETEN_PHYB    BIT2    // 0/x/x/x Port 2 TX Power Status Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TXPWRSETEN_PHYB    BIT1    // 0/x/x/x Port 1 TX Power Status Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TXPWRSETEN_PHYB    BIT0    // 0/x/x/x Port 0 TX Power Status Manual Setting Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z3 0x4 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TXPWRSET_PHYB  0xF0    // 0/x/x/x Port 1 TX Power Status Register Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TXPWRSET_PHYB  0xF     // 0/x/x/x Port 0 TX Power Status Register Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z4 0x5 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TXPWRSET_PHYB  0xF0    // 0/x/x/x Port 3 TX Power Status Register Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TXPWRSET_PHYB  0xF     // 0/x/x/x Port 2 TX Power Status Register Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z5 0x6 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TXEIDLESETEN_PHYB  BIT3    // 0/x/x/x Port 3 TX Electrical Idle Register Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TXEIDLESETEN_PHYB  BIT2    // 0/x/x/x Port 2 TX Electrical Idle Register Set
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TXEIDLESETEN_PHYB  BIT1    // 0/x/x/x Port 1 TX Electrical Idle Register Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TXEIDLESETEN_PHYB  BIT0    // 0/x/x/x Port 0 TX Electrical Idle Register Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z6 0x7 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TXEIDLESETB_PHYB   BIT3    // 0/x/x/x Port 3 TX Electrical Idle Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TXEIDLESETB_PHYB   BIT2    // 0/x/x/x Port 2 TX Electrical Idle Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TXEIDLESETB_PHYB   BIT1    // 0/x/x/x Port 1 TX Electrical Idle Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TXEIDLESETB_PHYB   BIT0    // 0/x/x/x Port 0 TX Electrical Idle Control
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z7 0x8 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_SPEEDSET_PHYB  (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Port 1 Speed Manual Setting Register
    #define CND003_D15F0EPHYINDEXDATA_FRP00_SPEEDSET_PHYB  (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Port 0 Speed Manual Setting Register
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z8 0x9 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_SPEEDSET_PHYB  (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Port 3 Speed Manual Setting Register
    #define CND003_D15F0EPHYINDEXDATA_FRP02_SPEEDSET_PHYB  (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Port 2 Speed Manual Setting Register
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z9 0xA // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_SPEEDSETEN_PHYB    BIT3    // 0/x/x/x Port 3 Speed Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_SPEEDSETEN_PHYB    BIT2    // 0/x/x/x Port 2 Speed Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_SPEEDSETEN_PHYB    BIT1    // 0/x/x/x Port 1 Speed Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_SPEEDSETEN_PHYB    BIT0    // 0/x/x/x Port 0 Speed Manual Setting Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z10 0xB // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_SATA_TXSET_EN_PHYB BIT3    // 0/x/x/x Port 3 SATA TX Swing Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_SATA_TXSET_EN_PHYB BIT2    // 0/x/x/x Port 2 SATA TX Swing Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_SATA_TXSET_EN_PHYB BIT1    // 0/x/x/x Port 1 SATA TX Swing Manual Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_SATA_TXSET_EN_PHYB BIT0    // 0/x/x/x Port 0 SATA TX Swing Manual Setting Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z11 0xC // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_SATA_TXSET_PHYB    (BIT6 + BIT7)   // 0/x/x/x Port 0 SATA TX Swing Manual Setting
    #define CND003_D15F0EPHYINDEXDATA_FRP02_SATA_TXSET_PHYB    (BIT4 + BIT5)   // 0/x/x/x Port 0 SATA TX Swing Manual Setting
    #define CND003_D15F0EPHYINDEXDATA_FRP01_SATA_TXSET_PHYB    (BIT2 + BIT3)   // 0/x/x/x Port 0 SATA TX Swing Manual Setting
    #define CND003_D15F0EPHYINDEXDATA_FRP00_SATA_TXSET_PHYB    (BIT0 + BIT1)   // 0/x/x/x Port 0 SATA TX Swing Manual Setting
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z12 0xD // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP03_EIDLESQSDET_PHYB    BIT3    // 0/x/x/x Port 3 EIDLE/Squelch Detection Flag
    #define CND003_D15F0EPHYINDEXDATA_EP02_EIDLESQSDET_PHYB    BIT2    // 0/x/x/x Port 2 EIDLE/Squelch Detection Flag
    #define CND003_D15F0EPHYINDEXDATA_EP01_EIDLESQSDET_PHYB    BIT1    // 0/x/x/x Port 1 EIDLE/Squelch Detection Flag
    #define CND003_D15F0EPHYINDEXDATA_EP00_EIDLESQSDET_PHYB    BIT0    // 0/x/x/x Port 0 EIDLE/Squelch Detection Flag
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z13 0xE // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_EIDLESQBW_PHYB BIT3    // 0/x/x/x Port 3 EIDLE/Squelch Detection Mode Select
    #define CND003_D15F0EPHYINDEXDATA_FHP02_EIDLESQBW_PHYB BIT2    // 0/x/x/x Port 2 EIDLE/Squelch Detection Mode Select
    #define CND003_D15F0EPHYINDEXDATA_FHP01_EIDLESQBW_PHYB BIT1    // 0/x/x/x Port 1 EIDLE/Squelch Detection Mode Select
    #define CND003_D15F0EPHYINDEXDATA_FHP00_EIDLESQBW_PHYB BIT0    // 0/x/x/x Port 0 EIDLE/Squelch Detection Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z14 0xF // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP01_EIDLESQTH_PHYB (BIT4 + BIT5 + BIT6)    // 010b/x/x/x Port 1 EIDLE Detection Threshold
    #define CND003_D15F0EPHYINDEXDATA_FHP00_EIDLESQTH_PHYB (BIT0 + BIT1 + BIT2)    // 010b/x/x/x Port 0 EIDLE Detection Threshold
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z15 0x10 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_EIDLESQTH_PHYB (BIT4 + BIT5 + BIT6)    // 010b/x/x/x Port 3 EIDLE Detection Threshold
    #define CND003_D15F0EPHYINDEXDATA_FHP02_EIDLESQTH_PHYB (BIT0 + BIT1 + BIT2)    // 010b/x/x/x Port 2 EIDLE Detection Threshold
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z16 0x11 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_RXPWRSETEN_PHYB    BIT3    // 0/x/x/x Port 3 RX Power Status Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_RXPWRSETEN_PHYB    BIT2    // 0/x/x/x Port 2 RX Power Status Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_RXPWRSETEN_PHYB    BIT1    // 0/x/x/x Port 1 RX Power Status Setting Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_RXPWRSETEN_PHYB    BIT0    // 0/x/x/x Port 0 RX Power Status Setting Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z17 0x12 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_RXPWRSET_PHYB  (BIT6 + BIT7)   // 0/x/x/x Port 3 RX Power Status Setting
    #define CND003_D15F0EPHYINDEXDATA_FRP02_RXPWRSET_PHYB  (BIT4 + BIT5)   // 0/x/x/x Port 2 RX Power Status Setting
    #define CND003_D15F0EPHYINDEXDATA_FRP01_RXPWRSET_PHYB  (BIT2 + BIT3)   // 0/x/x/x Port 1 RX Power Status Setting
    #define CND003_D15F0EPHYINDEXDATA_FRP00_RXPWRSET_PHYB  (BIT0 + BIT1)   // 0/x/x/x Port 0 RX Power Status Setting
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z18 0x13 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_LP03_TRINLPBK_PHYB   BIT3    // 0/x/x/x Port 3 Enable Internal Loop Back from PISO to PD
    #define CND003_D15F0EPHYINDEXDATA_LP02_TRINLPBK_PHYB   BIT2    // 0/x/x/x Port 2 Enable Internal Loop Back from PISO to PD
    #define CND003_D15F0EPHYINDEXDATA_LP01_TRINLPBK_PHYB   BIT1    // 0/x/x/x Port 1 Enable Internal Loop Back from PISO to PD
    #define CND003_D15F0EPHYINDEXDATA_LP00_TRINLPBK_PHYB   BIT0    // 0/x/x/x Port 0 Enable Internal Loop Back from PISO to PD
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z19 0x14 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_LP03_RTINLPBK_PHYB   BIT3    // 0/x/x/x Port 3 Enable Internal Loop back from RCV to DT Driver
    #define CND003_D15F0EPHYINDEXDATA_LP02_RTINLPBK_PHYB   BIT2    // 0/x/x/x Port 2 Enable Internal Loop back from RCV to DT Driver
    #define CND003_D15F0EPHYINDEXDATA_LP01_RTINLPBK_PHYB   BIT1    // 0/x/x/x Port 1 Enable Internal Loop back from RCV to DT Driver
    #define CND003_D15F0EPHYINDEXDATA_LP00_RTINLPBK_PHYB   BIT0    // 0/x/x/x Port 0 Enable Internal Loop back from RCV to DT Driver
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z20 0x15 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_RCV_HBW_G1_PHYB    (BIT4 + BIT5 + BIT6)    // 111b/x/x/x Port 1 Gen1 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define CND003_D15F0EPHYINDEXDATA_FRP00_RCV_HBW_G1_PHYB    (BIT0 + BIT1 + BIT2)    // 111b/x/x/x Port 0 Gen1 for RCV HBW Option for VGA/BUF/VGA_BUF
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z21 0x16 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_RCV_HBW_G1_PHYB    (BIT4 + BIT5 + BIT6)    // 111b/x/x/x Port 3 Gen1 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define CND003_D15F0EPHYINDEXDATA_FRP02_RCV_HBW_G1_PHYB    (BIT0 + BIT1 + BIT2)    // 111b/x/x/x Port 2 Gen1 for RCV HBW Option for VGA/BUF/VGA_BUF
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z22 0x17 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_RCV_HBW_G2_PHYB    (BIT4 + BIT5 + BIT6)    // 111b/x/x/x Port 1 Gen2 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define CND003_D15F0EPHYINDEXDATA_FRP00_RCV_HBW_G2_PHYB    (BIT0 + BIT1 + BIT2)    // 111b/x/x/x Port 0 Gen2 for RCV HBW Option for VGA/BUF/VGA_BUF
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z23 0x18 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_RCV_HBW_G2_PHYB    (BIT4 + BIT5 + BIT6)    // 111b/x/x/x Port 3 Gen1 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define CND003_D15F0EPHYINDEXDATA_FRP02_RCV_HBW_G2_PHYB    (BIT0 + BIT1 + BIT2)    // 111b/x/x/x Port 2 Gen1 for RCV HBW Option for VGA/BUF/VGA_BUF
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z24 0x19 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_RCV_HBW_G3_PHYB    (BIT4 + BIT5 + BIT6)    // 111b/x/x/x Port 1 Gen3 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define CND003_D15F0EPHYINDEXDATA_FRP00_RCV_HBW_G3_PHYB    (BIT0 + BIT1 + BIT2)    // 111b/x/x/x Port 0 Gen3 for RCV HBW Option for VGA/BUF/VGA_BUF
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z25 0x1A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_RCV_HBW_G3_PHYB    (BIT4 + BIT5 + BIT6)    // 111b/x/x/x Port 3 Gen3 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define CND003_D15F0EPHYINDEXDATA_FRP02_RCV_HBW_G3_PHYB    (BIT0 + BIT1 + BIT2)    // 111b/x/x/x Port 2 Gen3 for RCV HBW Option for VGA/BUF/VGA_BUF
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z26 0x1B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TX_DUTY_PHYB   (BIT6 + BIT7)   // 0/x/x/x Port 3 TX_DUTY for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TX_DUTY_PHYB   (BIT4 + BIT5)   // 0/x/x/x Port 2 TX_DUTY for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TX_DUTY_PHYB   (BIT2 + BIT3)   // 0/x/x/x Port 1 TX_DUTY for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TX_DUTY_PHYB   (BIT0 + BIT1)   // 0/x/x/x Port 0 TX_DUTY for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z27 0x1C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TXPSR_PHYB (BIT5 + BIT6 + BIT7)    // 011b/x/x/x Port 0 LPn_TXPSR for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TDCIS_PHYB 0x1F                    // 11101b/x/x/x Port 0 LPn_TDCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z28 0x1D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TXPSR_PHYB (BIT5 + BIT6 + BIT7)    // 011b/x/x/x Port 1 LPn_TXPSR for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TDCIS_PHYB 0x1F                    // 11101b/x/x/x Port 1 LPn_TDCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z29 0x1E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TXPSR_PHYB (BIT5 + BIT6 + BIT7)    // 011b/x/x/x Port 2 LPn_TXPSR for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TDCIS_PHYB 0x1F                    // 11101b/x/x/x Port 2 LPn_TDCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z30 0x1F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TXPSR_PHYB (BIT5 + BIT6 + BIT7)    // 011b/x/x/x Port 3 LPn_TXPSR for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TDCIS_PHYB 0x1F                    // 11101b/x/x/x Port 3 LPn_TDCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z31 0x21 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_RCVTHSEL_PHYB  BIT3    // 0/x/x/x Port 3 RCV VGA Gain Range Selection
    #define CND003_D15F0EPHYINDEXDATA_FHP02_RCVTHSEL_PHYB  BIT2    // 0/x/x/x Port 2 RCV VGA Gain Range Selection
    #define CND003_D15F0EPHYINDEXDATA_FHP01_RCVTHSEL_PHYB  BIT1    // 0/x/x/x Port 1 RCV VGA Gain Range Selection
    #define CND003_D15F0EPHYINDEXDATA_FHP00_RCVTHSEL_PHYB  BIT0    // 0/x/x/x Port 0 RCV VGA Gain Range Selection
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z32 0x22 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_RXCLKSEL_PHYB  (BIT4 + BIT5 + BIT6)    // 000b/x/x/x Port 0 Rise Edge of RXCLK Select
    #define CND003_D15F0EPHYINDEXDATA_FRP00_RXCLKSEL_PHYB  (BIT0 + BIT1 + BIT2)    // 000b/x/x/x Port 0 Rise Edge of RXCLK Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z33 0x23 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_RXCLKSEL_PHYB  (BIT4 + BIT5 + BIT6)    // 000b/x/x/x Port 3 Rise Edge of RXCLK Select
    #define CND003_D15F0EPHYINDEXDATA_FRP02_RXCLKSEL_PHYB  (BIT0 + BIT1 + BIT2)    // 000b/x/x/x Port 2 Rise Edge of RXCLK Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z34 0x24 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP01_IVCPSEL_PHYB   (BIT4 + BIT5 + BIT6)    // 0/x/x/x Port 1 IV Gain Select
    #define CND003_D15F0EPHYINDEXDATA_FHP00_IVCPSEL_PHYB   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Port 0 IV Gain Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z35 0x25 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_IVCPSEL_PHYB   (BIT4 + BIT5 + BIT6)    // 0/x/x/x Port 3 IV Gain Select
    #define CND003_D15F0EPHYINDEXDATA_FHP02_IVCPSEL_PHYB   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Port 2 IV Gain Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z36 0x26 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_VCOPDSEL_PHYB  BIT3    // 0/x/x/x Port 3 VCO Power off Method at P1
    #define CND003_D15F0EPHYINDEXDATA_FHP02_VCOPDSEL_PHYB  BIT2    // 0/x/x/x Port 2 VCO Power off Method at P1
    #define CND003_D15F0EPHYINDEXDATA_FHP01_VCOPDSEL_PHYB  BIT1    // 0/x/x/x Port 1 VCO Power off Method at P1
    #define CND003_D15F0EPHYINDEXDATA_FHP00_VCOPDSEL_PHYB  BIT0    // 0/x/x/x Port 0 VCO Power off Method at P1
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z37 0x27 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_RCVPDSEL_PHYB  BIT3    // 0/x/x/x Port 3 RCV Power off Method
    #define CND003_D15F0EPHYINDEXDATA_FHP02_RCVPDSEL_PHYB  BIT2    // 0/x/x/x Port 2 RCV Power off Method
    #define CND003_D15F0EPHYINDEXDATA_FHP01_RCVPDSEL_PHYB  BIT1    // 0/x/x/x Port 1 RCV Power off Method
    #define CND003_D15F0EPHYINDEXDATA_FHP00_RCVPDSEL_PHYB  BIT0    // 0/x/x/x Port 0 RCV Power off Method
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z38 0x28 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_CDR_UGB_HBW_PHYB   BIT3    // 0/x/x/x Port 3 CDR Loop Filter Buffer Bandwidth
    #define CND003_D15F0EPHYINDEXDATA_FHP02_CDR_UGB_HBW_PHYB   BIT2    // 0/x/x/x Port 2 CDR Loop Filter Buffer Bandwidth
    #define CND003_D15F0EPHYINDEXDATA_FHP01_CDR_UGB_HBW_PHYB   BIT1    // 0/x/x/x Port 1 CDR Loop Filter Buffer Bandwidth
    #define CND003_D15F0EPHYINDEXDATA_FHP00_CDR_UGB_HBW_PHYB   BIT0    // 0/x/x/x Port 0 CDR Loop Filter Buffer Bandwidth
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z39 0x29 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_CDR_VT_SW_PHYB BIT3    // 1b/x/x/x Port 3 CDR IV Control Source Select
    #define CND003_D15F0EPHYINDEXDATA_FHP02_CDR_VT_SW_PHYB BIT2    // 1b/x/x/x Port 2 CDR IV Control Source Select
    #define CND003_D15F0EPHYINDEXDATA_FHP01_CDR_VT_SW_PHYB BIT1    // 1b/x/x/x Port 1 CDR IV Control Source Select
    #define CND003_D15F0EPHYINDEXDATA_FHP00_CDR_VT_SW_PHYB BIT0    // 1b/x/x/x Port 0 CDR IV Control Source Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z40 0x2A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_FDRATIO_G1_PHYB    (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen1 FD Mode Ratio during P1 to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP00_FDRATIO_G1_PHYB    (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen1 FD Mode Ratio during P1 to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z41 0x2B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_FDRATIO_G1_PHYB    (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen1 FD Mode Ratio during P1 to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP02_FDRATIO_G1_PHYB    (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen1 for FD Mode Ratio during P1 to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z42 0x2C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_FDRATIO_G2_PHYB    (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen2 FD Mode Ratio during P1 to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP00_FDRATIO_G2_PHYB    (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen2 FD Mode Ratio during P1 to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z43 0x2D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_FDRATIO_G2_PHYB    (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen2 FD Mode Ratio during P1 to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP02_FDRATIO_G2_PHYB    (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen2 FD Mode Ratio during P1 to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z44 0x2E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_FDRATIO_G3_PHYB    (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen3 FD Mode Ratio during P1 to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP00_FDRATIO_G3_PHYB    (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen3 FD Mode Ratio during P1 to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z45 0x2F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_FDRATIO_G3_PHYB    (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen3 FD Mode Ratio during P1 to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP02_FDRATIO_G3_PHYB    (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen3 FD Mode Ratio during P1 to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z46 0x30 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_FTSRATIO_G1_PHYB   (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Port 1 Gen1 PD Training Mode Ratio during P0s to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP00_FTSRATIO_G1_PHYB   (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Port 0 Gen1 PD Training Mode Ratio during P0s to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z47 0x31 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_FTSRATIO_G1_PHYB   (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Port 1 Gen1 PD Training Mode Ratio during P0s to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP02_FTSRATIO_G1_PHYB   (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Port 0 Gen1 PD Training Mode Ratio during P0s to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z48 0x32 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_FTSRATIO_G2_PHYB   (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Port 1 Gen2 PD Training Mode Ratio during P0s to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP00_FTSRATIO_G2_PHYB   (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Port 0 Gen2 PD Training Mode Ratio during P0s to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z49 0x33 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_FTSRATIO_G2_PHYB   (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Port 1 Gen2 PD Training Mode Ratio during P0s to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP02_FTSRATIO_G2_PHYB   (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Port 0 Gen2 PD Training Mode Ratio during P0s to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z50 0x34 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_FTSRATIO_G3_PHYB   (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Port 1 Gen3 PD Training Mode Ratio during P0s to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP00_FTSRATIO_G3_PHYB   (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Port 0 Gen3 PD Training Mode Ratio during P0s to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z51 0x35 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_FTSRATIO_G3_PHYB   (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Port 3 Gen2 PD Training Mode Ratio during P0s to P0
    #define CND003_D15F0EPHYINDEXDATA_FRP02_FTSRATIO_G3_PHYB   (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Port 2 Gen2 PD Training Mode Ratio during P0s to P0
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z52 0x36 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_P1EXT_G1_PHYB  (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen1 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP00_P1EXT_G1_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen1 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z53 0x37 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_P1EXT_G1_PHYB  (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen1 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP02_P1EXT_G1_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen1 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z54 0x38 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_P1EXT_G2_PHYB  (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen2 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP00_P1EXT_G2_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen2 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z55 0x39 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_P1EXT_G2_PHYB  (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen2 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP02_P1EXT_G2_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen2 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z56 0x3A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_P1EXT_G3_PHYB  (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen3 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP00_P1EXT_G3_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen3 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z57 0x3B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_P1EXT_G3_PHYB  (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen3 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP02_P1EXT_G3_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen3 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z58 0x3C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_P0SP2EXT_G1_PHYB   (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen1 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP00_P0SP2EXT_G1_PHYB   (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen1 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z59 0x3D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_P0SP2EXT_G1_PHYB   (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen1 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP02_P0SP2EXT_G1_PHYB   (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen1 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z60 0x3E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_P0SP2EXT_G2_PHYB   (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen2 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP00_P0SP2EXT_G2_PHYB   (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen2 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z61 0x3F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_P0SP2EXT_G2_PHYB   (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 Gen2 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP02_P0SP2EXT_G2_PHYB   (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 Gen2 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z62 0x40 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_P0SP2EXT_G3_PHYB   (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen3 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP00_P0SP2EXT_G3_PHYB   (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen3 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z63 0x41 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_P0SP2EXT_G3_PHYB   (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 Gen3 ExitLatency P1 Exit Latency
    #define CND003_D15F0EPHYINDEXDATA_FRP02_P0SP2EXT_G3_PHYB   (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 Gen3 ExitLatency P1 Exit Latency
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z64 0x42 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NIPRSEL_G1_PHYB    (BIT6 + BIT7)   // 11b/x/x/x Port 3 Gen1 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NIPRSEL_G1_PHYB    (BIT4 + BIT5)   // 11b/x/x/x Port 2 Gen1 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NIPRSEL_G1_PHYB    (BIT2 + BIT3)   // 11b/x/x/x Port 1 Gen1 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NIPRSEL_G1_PHYB    (BIT0 + BIT1)   // 11b/x/x/x Port 0 Gen1 Gain1 during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z65 0x43 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NIPRSEL_G2_PHYB    (BIT6 + BIT7)   // 10b/x/x/x Port 3 Gen2 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NIPRSEL_G2_PHYB    (BIT4 + BIT5)   // 10b/x/x/x Port 2 Gen2 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NIPRSEL_G2_PHYB    (BIT2 + BIT3)   // 10b/x/x/x Port 1 Gen2 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NIPRSEL_G2_PHYB    (BIT0 + BIT1)   // 10b/x/x/x Port 0 Gen2 Gain1 during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z66 0x44 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NIPRSEL_G3_PHYB    (BIT6 + BIT7)   // 10b/x/x/x Port 3 Gen3 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NIPRSEL_G3_PHYB    (BIT4 + BIT5)   // 10b/x/x/x Port 2 Gen3 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NIPRSEL_G3_PHYB    (BIT2 + BIT3)   // 10b/x/x/x Port 1 Gen3 Gain1 during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NIPRSEL_G3_PHYB    (BIT0 + BIT1)   // 10b/x/x/x Port 0 Gen3 Gain1 during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z67 0x45 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KIPRSEL_G1_PHYB    (BIT6 + BIT7)   // 10b/x/x/x Port 3 Gen1 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KIPRSEL_G1_PHYB    (BIT4 + BIT5)   // 10b/x/x/x Port 2 Gen1 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KIPRSEL_G1_PHYB    (BIT2 + BIT3)   // 10b/x/x/x Port 1 Gen1 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KIPRSEL_G1_PHYB    (BIT0 + BIT1)   // 10b/x/x/x Port 0 Gen1 Gain1 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z68 0x46 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KIPRSEL_G2_PHYB    (BIT6 + BIT7)   // 01b/x/x/x Port 3 Gen2 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KIPRSEL_G2_PHYB    (BIT4 + BIT5)   // 01b/x/x/x Port 2 Gen2 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KIPRSEL_G2_PHYB    (BIT2 + BIT3)   // 01b/x/x/x Port 1 Gen2 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KIPRSEL_G2_PHYB    (BIT0 + BIT1)   // 01b/x/x/x Port 0 Gen2 Gain1 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z69 0x47 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KIPRSEL_G3_PHYB    (BIT6 + BIT7)   // 01b/x/x/x Port 3 Gen3 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KIPRSEL_G3_PHYB    (BIT4 + BIT5)   // 01b/x/x/x Port 2 Gen3 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KIPRSEL_G3_PHYB    (BIT2 + BIT3)   // 01b/x/x/x Port 1 Gen3 Gain1 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KIPRSEL_G3_PHYB    (BIT0 + BIT1)   // 01b/x/x/x Port 0 Gen3 Gain1 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z70 0x48 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NIPCSEL_G1_PHYB    (BIT6 + BIT7)   // 01b/x/x/x Port 3 Gen1 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NIPCSEL_G1_PHYB    (BIT4 + BIT5)   // 01b/x/x/x Port 2 Gen1 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NIPCSEL_G1_PHYB    (BIT2 + BIT3)   // 01b/x/x/x Port 1 Gen1 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NIPCSEL_G1_PHYB    (BIT0 + BIT1)   // 01b/x/x/x Port 0 Gen1 Gain2 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z71 0x49 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NIPCSEL_G2_PHYB    (BIT6 + BIT7)   // 01b/x/x/x Port 3 Gen2 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NIPCSEL_G2_PHYB    (BIT4 + BIT5)   // 01b/x/x/x Port 2 Gen2 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NIPCSEL_G2_PHYB    (BIT2 + BIT3)   // 01b/x/x/x Port 1 Gen2 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NIPCSEL_G2_PHYB    (BIT0 + BIT1)   // 01b/x/x/x Port 0 Gen2 Gain2 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z72 0x4A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NIPCSEL_G3_PHYB    (BIT6 + BIT7)   // 01b/x/x/x Port 3 Gen3 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NIPCSEL_G3_PHYB    (BIT4 + BIT5)   // 01b/x/x/x Port 2 Gen3 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NIPCSEL_G3_PHYB    (BIT2 + BIT3)   // 01b/x/x/x Port 1 Gen3 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NIPCSEL_G3_PHYB    (BIT0 + BIT1)   // 01b/x/x/x Port 0 G3 for Gain2 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z73 0x4B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KIPCSEL_G1_PHYB    (BIT6 + BIT7)   // 00b/x/x/x Port 3 Gen1 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KIPCSEL_G1_PHYB    (BIT4 + BIT5)   // 00b/x/x/x Port 2 Gen1 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KIPCSEL_G1_PHYB    (BIT2 + BIT3)   // 00b/x/x/x Port 1 Gen1 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KIPCSEL_G1_PHYB    (BIT0 + BIT1)   // 00b/x/x/x Port 0 Gen1 Gain2 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z74 0x4C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KIPCSEL_G2_PHYB    (BIT6 + BIT7)   // 00b/x/x/x Port 3 Gen2 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KIPCSEL_G2_PHYB    (BIT4 + BIT5)   // 00b/x/x/x Port 2 Gen2 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KIPCSEL_G2_PHYB    (BIT2 + BIT3)   // 00b/x/x/x Port 1 Gen2 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KIPCSEL_G2_PHYB    (BIT0 + BIT1)   // 00b/x/x/x Port 0 Gen2 Gain2 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z75 0x4D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KIPCSEL_G3_PHYB    (BIT6 + BIT7)   // 00b/x/x/x Port 3 Gen3 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KIPCSEL_G3_PHYB    (BIT4 + BIT5)   // 00b/x/x/x Port 2 Gen3 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KIPCSEL_G3_PHYB    (BIT2 + BIT3)   // 00b/x/x/x Port 1 Gen3 Gain2 during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KIPCSEL_G3_PHYB    (BIT0 + BIT1)   // 00b/x/x/x Port 0 Gen3 Gain2 during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z76 0x4E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NTSEL_G1_PHYB  BIT6    // 1b/x/x/x Port 3 Gen1 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NTSEL_G1_PHYB  BIT4    // 1b/x/x/x Port 2 Gen1 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NTSEL_G1_PHYB  BIT2    // 1b/x/x/x Port 1 Gen1 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NTSEL_G1_PHYB  BIT0    // 1b/x/x/x Port 0 Gen1 Updatetime during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z77 0x4F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NTSEL_G2_PHYB  BIT6    // 1b/x/x/x Port 3 Gen2 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NTSEL_G2_PHYB  BIT4    // 1b/x/x/x Port 2 Gen2 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NTSEL_G2_PHYB  BIT2    // 1b/x/x/x Port 1 Gen2 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NTSEL_G2_PHYB  BIT0    // 1b/x/x/x Port 0 Gen2 Updatetime during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z78 0x50 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NTSEL_G3_PHYB  BIT6    // 1b/x/x/x Port 3 Gen3 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NTSEL_G3_PHYB  BIT4    // 1b/x/x/x Port 2 Gen3 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NTSEL_G3_PHYB  BIT2    // 1b/x/x/x Port 1 Gen3 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NTSEL_G3_PHYB  BIT0    // 1b/x/x/x Port 0 Gen3 Updatetime during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z79 0x51 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KTSEL_G1_PHYB  BIT6    // 0b/x/x/x Port 3 Gen1 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KTSEL_G1_PHYB  BIT4    // 0b/x/x/x Port 2 Gen1 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KTSEL_G1_PHYB  BIT2    // 0b/x/x/x Port 1 Gen1 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KTSEL_G1_PHYB  BIT0    // 0b/x/x/x Port 0 Gen1 Updatetime during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z80 0x52 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KTSEL_G2_PHYB  BIT6    // 0b/x/x/x Port 3 Gen2 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KTSEL_G2_PHYB  BIT4    // 0b/x/x/x Port 2 Gen2 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KTSEL_G2_PHYB  BIT2    // 0b/x/x/x Port 1 Gen2 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KTSEL_G2_PHYB  BIT0    // 0b/x/x/x Port 0 Gen2 Updatetime during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z81 0x53 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KTSEL_G3_PHYB  BIT6    // 0b/x/x/x Port 3 Gen3 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KTSEL_G3_PHYB  BIT4    // 0b/x/x/x Port 2 Gen3 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KTSEL_G3_PHYB  BIT2    // 0b/x/x/x Port 1 Gen3 Updatetime during Tracking Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KTSEL_G3_PHYB  BIT0    // 0b/x/x/x Port 0 Gen3 Updatetime during Tracking Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z82 0x54 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NLFSEL_G1_PHYB (BIT6 + BIT7)   // 01b/x/x/x Port 3 Gen1 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NLFSEL_G1_PHYB (BIT4 + BIT5)   // 01b/x/x/x Port 2 Gen1 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NLFSEL_G1_PHYB (BIT2 + BIT3)   // 01b/x/x/x Port 1 Gen1 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NLFSEL_G1_PHYB (BIT0 + BIT1)   // 01b/x/x/x Port 0 Gen1 LF Select during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z83 0x55 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NLFSEL_G2_PHYB (BIT6 + BIT7)   // 01b/x/x/x Port 3 Gen2 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NLFSEL_G2_PHYB (BIT4 + BIT5)   // 01b/x/x/x Port 2 Gen2 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NLFSEL_G2_PHYB (BIT2 + BIT3)   // 01b/x/x/x Port 1 Gen2 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NLFSEL_G2_PHYB (BIT0 + BIT1)   // 01b/x/x/x Port 0 Gen2 LF Select during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z84 0x56 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_NLFSEL_G3_PHYB (BIT6 + BIT7)   // 01b/x/x/x Port 3 Gen3 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_NLFSEL_G3_PHYB (BIT4 + BIT5)   // 01b/x/x/x Port 2 Gen3 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_NLFSEL_G3_PHYB (BIT2 + BIT3)   // 01b/x/x/x Port 1 Gen3 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_NLFSEL_G3_PHYB (BIT0 + BIT1)   // 01b/x/x/x Port 0 Gen3 LF Select during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z85 0x57 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KLFSEL_G1_PHYB (BIT6 + BIT7)   // 11b/x/x/x Port 3 Gen1 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KLFSEL_G1_PHYB (BIT4 + BIT5)   // 11b/x/x/x Port 2 Gen1 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KLFSEL_G1_PHYB (BIT2 + BIT3)   // 11b/x/x/x Port 1 Gen1 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KLFSEL_G1_PHYB (BIT0 + BIT1)   // 11b/x/x/x Port 0 Gen1 LF select during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z86 0x58 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KLFSEL_G2_PHYB (BIT6 + BIT7)   // 11b/x/x/x Port 3 Gen2 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KLFSEL_G2_PHYB (BIT4 + BIT5)   // 11b/x/x/x Port 2 Gen2 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KLFSEL_G2_PHYB (BIT2 + BIT3)   // 11b/x/x/x Port 1 Gen2 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KLFSEL_G2_PHYB (BIT0 + BIT1)   // 11b/x/x/x Port 0 Gen2 LF Select during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z87 0x59 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_KLFSEL_G3_PHYB (BIT6 + BIT7)   // 10b/x/x/x Port 3 Gen3 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_KLFSEL_G3_PHYB (BIT4 + BIT5)   // 10b/x/x/x Port 2 Gen3 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_KLFSEL_G3_PHYB (BIT2 + BIT3)   // 10b/x/x/x Port 1 Gen3 LF Select during Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_KLFSEL_G3_PHYB (BIT0 + BIT1)   // 10b/x/x/x Port 0 Gen3 LF Select during Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z88 0x5C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNMODE_G1_PHYB   0xFFF   // 0/x/x/x Port 0 Gen1 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z89 0x5E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNMODE_G1_PHYB   0xFFF   // 0/x/x/x Port 1 Gen1 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z90 0x60 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNMODE_G1_PHYB   0xFFF   // 0h/x/x/x Port 2 Gen1 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z91 0x62 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNMODE_G1_PHYB   0xFFF   // 0h/x/x/x Port 3 Gen1 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z92 0x64 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNMODE_G2_PHYB   0xFFF   // 0/x/x/x Port 0 Gen2 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z93 0x66 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNMODE_G2_PHYB   0xFFF   // 0/x/x/x Port 1 Gen2 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z94 0x68 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNMODE_G2_PHYB   0xFFF   // 0/x/x/x Port 2 Gen2 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z95 0x6A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNMODE_G2_PHYB   0xFFF   // 0/x/x/x Port 3 Gen2 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z96 0x6C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNMODE_G3_PHYB   0xFFF   // 0/x/x/x Port 0 Gen3 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z97 0x6E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNMODE_G3_PHYB   0xFFF   // 0/x/x/x Port 1 Gen3 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z98 0x70 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNMODE_G3_PHYB   0xFFF   // 0/x/x/x Port 2 Gen3 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z99 0x72 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNMODE_G3_PHYB   0xFFF   // 0/x/x/x Port 3 Gen3 Equalizer Tuning Mode Select
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z100 0x74 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDCBW_G1_PHYB   0xF0    // 1h/x/x/x Port 1 Gen1 LEQ DC Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDCBW_G1_PHYB   0xF     // 1h/x/x/x Port 0 Gen1 LEQ DC Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z101 0x75 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDCBW_G1_PHYB   0xF0    // 1h/x/x/x Port 3 Gen1 LEQ DC Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDCBW_G1_PHYB   0xF     // 1h/x/x/x Port 2 Gen1 LEQ DC Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z102 0x76 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDCBW_G2_PHYB   0xF0    // 1h/x/x/x Port 1 Gen2 LEQ DC Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDCBW_G2_PHYB   0xF     // 1h/x/x/x Port 0 Gen2 LEQ DC Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z103 0x77 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDCBW_G2_PHYB   0xF0    // 1h/x/x/x Port 3 Gen2 LEQ DC Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDCBW_G2_PHYB   0xF     // 1h/x/x/x Port 2 Gen2 LEQ DC Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z104 0x78 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDCBW_G3_PHYB   0xF0    // 1h/x/x/x Port 1 Gen3 LEQ DC Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDCBW_G3_PHYB   0xF     // 1h/x/x/x Port 0 Gen3 LEQ DC Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z105 0x79 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDCBW_G3_PHYB   0xF0    // 1h/x/x/x Port 3 Gen3 LEQ DC Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDCBW_G3_PHYB   0xF     // 1h/x/x/x Port 2 Gen3 LEQ DC Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z106 0x7A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNHFBW_G1_PHYB   0xF0    // 1h/x/x/x Port 1 Gen1 LEQ HF Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNHFBW_G1_PHYB   0xF     // 1h/x/x/x Port 0 Gen1 LEQ HF Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z107 0x7B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNHFBW_G1_PHYB   0xF0    // 1h/x/x/x Port 3 Gen1 LEQ HF Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNHFBW_G1_PHYB   0xF     // 1h/x/x/x Port 2 Gen1 LEQ HF Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z108 0x7C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNHFBW_G2_PHYB   0xF0    // 1h/x/x/x Port 1 Gen2 LEQ HF Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNHFBW_G2_PHYB   0xF     // 1h/x/x/x Port 0 Gen2 LEQ HF Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z109 0x7D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNHFBW_G2_PHYB   0xF0    // 1h/x/x/x Port 3 Gen2 LEQ HF Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNHFBW_G2_PHYB   0xF     // 1h/x/x/x Port 2 Gen2 LEQ HF Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z110 0x7E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNHFBW_G3_PHYB   0xF0    // 1h/x/x/x Port 1 Gen3 LEQ HF Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNHFBW_G3_PHYB   0xF     // 1h/x/x/x Port 0 Gen3 LEQ HF Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z111 0x7F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNHFBW_G3_PHYB   0xF0    // 1h/x/x/x Port 3 Gen3 LEQ HF Gain Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNHFBW_G3_PHYB   0xF     // 1h/x/x/x Port 2 Gen3 LEQ HF Gain Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z112 0x80 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNOSBW_G1_PHYB   0xF0    // 1h/x/x/x Port 1 Gen1 LEQ Offset Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNOSBW_G1_PHYB   0xF     // 1h/x/x/x Port 0 Gen1 LEQ Offset Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z113 0x81 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNOSBW_G1_PHYB   0xF0    // 1h/x/x/x Port 3 Gen1 LEQ Offset Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNOSBW_G1_PHYB   0xF     // 1h/x/x/x Port 2 Gen1 LEQ Offset Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z114 0x82 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNOSBW_G2_PHYB   0xF0    // 1h/x/x/x Port 1 Gen2 LEQ Offset Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNOSBW_G2_PHYB   0xF     // 1h/x/x/x Port 0 Gen2 LEQ Offset Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z115 0x83 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNOSBW_G2_PHYB   0xF0    // 1h/x/x/x Port 3 Gen2 LEQ Offset Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNOSBW_G2_PHYB   0xF     // 1h/x/x/x Port 2 Gen2 LEQ Offset Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z116 0x84 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNOSBW_G3_PHYB   0xF0    // 1h/x/x/x Port 1 Gen3 LEQ Offset Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNOSBW_G3_PHYB   0xF     // 1h/x/x/x Port 0 Gen3 LEQ Offset Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z117 0x85 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNOSBW_G3_PHYB   0xF0    // 1h/x/x/x Port 3 Gen3 LEQ Offset Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNOSBW_G3_PHYB   0xF     // 1h/x/x/x Port 2 Gen3 LEQ Offset Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z118 0x86 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNWTBW_G1_PHYB   0xF0    // 1h/x/x/x Port 1 Gen1 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNWTBW_G1_PHYB   0xF     // 1h/x/x/x Port 0 Gen1 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z119 0x87 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNWTBW_G1_PHYB   0xF0    // 1h/x/x/x Port 3 Gen1 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNWTBW_G1_PHYB   0xF     // 1h/x/x/x Port 2 Gen1 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z120 0x88 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNWTBW_G2_PHYB   0xF0    // 1h/x/x/x Port 1 Gen2 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNWTBW_G2_PHYB   0xF     // 1h/x/x/x Port 0 Gen2 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z121 0x89 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNWTBW_G2_PHYB   0xF0    // 1h/x/x/x Port 3 Gen2 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNWTBW_G2_PHYB   0xF     // 1h/x/x/x Port 2 Gen2 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z122 0x8A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNWTBW_G3_PHYB   0xF0    // 1h/x/x/x Port 1 Gen3 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNWTBW_G3_PHYB   0xF     // 1h/x/x/x Port 0 Gen3 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z123 0x8B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNWTBW_G3_PHYB   0xF0    // 1h/x/x/x Port 3 Gen3 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNWTBW_G3_PHYB   0xF     // 1h/x/x/x Port 2 Gen3 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z124 0x8C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDFE_G1_PHYB    (BIT6 + BIT7)   // 00b/x/x/x Port 3 Gen1 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDFE_G1_PHYB    (BIT4 + BIT5)   // 00b/x/x/x Port 2 Gen1 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDFE_G1_PHYB    (BIT2 + BIT3)   // 00b/x/x/x Port 1 Gen1 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDFE_G1_PHYB    (BIT0 + BIT1)   // 00b/x/x/x Port 0 Gen1 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z125 0x8D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDFE_G2_PHYB    (BIT6 + BIT7)   // 00b/x/x/x Port 3 Gen2 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDFE_G2_PHYB    (BIT4 + BIT5)   // 00b/x/x/x Port 2 Gen2 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDFE_G2_PHYB    (BIT2 + BIT3)   // 00b/x/x/x Port 1 Gen2 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDFE_G2_PHYB    (BIT0 + BIT1)   // 00b/x/x/x Port 0 Gen2 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z126 0x8E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDFE_G3_PHYB    (BIT6 + BIT7)   // 10b/x/x/x Port 3 Gen3 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDFE_G3_PHYB    (BIT4 + BIT5)   // 10b/x/x/x Port 2 Gen3 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDFE_G3_PHYB    (BIT2 + BIT3)   // 10b/x/x/x Port 1 Gen3 DFE Weight Tuning Bandwidth Set
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDFE_G3_PHYB    (BIT0 + BIT1)   // 10b/x/x/x Port 0 Gen3 DFE Weight Tuning Bandwidth Set
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z127 0x8F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNALWY_G1_PHYB   BIT3    // 0/x/x/x Port 3 Gen1 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNALWY_G1_PHYB   BIT2    // 0/x/x/x Port 2 Gen1 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNALWY_G1_PHYB   BIT1    // 0/x/x/x Port 1 Gen1 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNALWY_G1_PHYB   BIT0    // 0/x/x/x Port 0 Gen1 Equalizer Always Tuning Mode Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z128 0x90 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNALWY_G2_PHYB   BIT3    // 0b/x/x/x Port 3 Gen2 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNALWY_G2_PHYB   BIT2    // 0b/x/x/x Port 2 Gen2 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNALWY_G2_PHYB   BIT1    // 0b/x/x/x Port 1 Gen2 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNALWY_G2_PHYB   BIT0    // 0b/x/x/x Port 0 Gen2 Equalizer Always Tuning Mode Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z129 0x91 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNALWY_G3_PHYB   BIT3    // 0b/x/x/x Port 3 Gen3 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNALWY_G3_PHYB   BIT2    // 0b/x/x/x Port 2 Gen3 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNALWY_G3_PHYB   BIT1    // 0b/x/x/x Port 1 Gen3 Equalizer Always Tuning Mode Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNALWY_G3_PHYB   BIT0    // 0b/x/x/x Port 0 Gen3 Equalizer Always Tuning Mode Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z130 0x92 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNSPDSWEN_PHYB   BIT3    // 0/x/x/x Port 3 Enabling Low Speed Mode after First Tuning Finished
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNSPDSWEN_PHYB   BIT2    // 0/x/x/x Port 2 Enabling Low Speed Mode after First Tuning Finished
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNSPDSWEN_PHYB   BIT1    // 0/x/x/x Port 1 Enable Low Speed Mode after First Tuning Finished
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNSPDSWEN_PHYB   BIT0    // 0/x/x/x Port 0 Enable Low Speed Mode after First Tuning Finished
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z131 0x93 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNVTH_G1_PHYB    (BIT4 + BIT5 + BIT6)    // 001b/x/x/x Port 1 Gen1 Equalizer Tuning Threshold Voltage
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNVTH_G1_PHYB    (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Port 0 Gen1 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z132 0x94 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNVTH_G1_PHYB    (BIT4 + BIT5 + BIT6)    // 001b/x/x/x Port 3 Gen1 Equalizer Tuning Threshold Voltage
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNVTH_G1_PHYB    (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Port 2 Gen1 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z133 0x95 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNVTH_G2_PHYB    (BIT4 + BIT5 + BIT6)    // 001b/x/x/x Port 1 Gen2 Equalizer Tuning Threshold Voltage
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNVTH_G2_PHYB    (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Port 0 Gen2 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z134 0x96 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNVTH_G2_PHYB    (BIT4 + BIT5 + BIT6)    // 001b/x/x/x Port 3 Gen2 Equalizer Tuning Threshold Voltage
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNVTH_G2_PHYB    (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Port 2 Gen2 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z135 0x97 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNVTH_G3_PHYB    (BIT4 + BIT5 + BIT6)    // 001b/x/x/x Port 1 Gen3 Equalizer Tuning Threshold Voltage
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNVTH_G3_PHYB    (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Port 0 Gen3 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z136 0x98 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNVTH_G3_PHYB    (BIT4 + BIT5 + BIT6)    // 001b/x/x/x Port 3 Gen3 Equalizer Tuning Threshold Voltage
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNVTH_G3_PHYB    (BIT0 + BIT1 + BIT2)    // 001b/x/x/x Port 2 Gen3 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z137 0x99 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDFETRN_G1_PHYB BIT3    // 1b/x/x/x Port 3 Gen1 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDFETRN_G1_PHYB BIT2    // 1b/x/x/x Port 2 Gen1 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDFETRN_G1_PHYB BIT1    // 1b/x/x/x Port 1 Gen1 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDFETRN_G1_PHYB BIT0    // 1b/x/x/x Port 0 Gen1 Enabling DFE in Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z138 0x9A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDFETRN_G2_PHYB BIT3    // 1b/x/x/x Port 3 Gen2 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDFETRN_G2_PHYB BIT2    // 1b/x/x/x Port 2 Gen2 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDFETRN_G2_PHYB BIT1    // 1b/x/x/x Port 1 Gen2 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDFETRN_G2_PHYB BIT0    // 1b/x/x/x Port 0 Gen2 Enabling DFE in Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z139 0x9B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNDFETRN_G3_PHYB BIT3    // 1b/x/x/x Port 3 Gen3 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNDFETRN_G3_PHYB BIT2    // 1b/x/x/x Port 2 Gen3 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNDFETRN_G3_PHYB BIT1    // 1b/x/x/x Port 1 Gen3 Enabling DFE in Training Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNDFETRN_G3_PHYB BIT0    // 1b/x/x/x Port 0 Gen3 Enabling DFE in Training Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z140 0x9C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_DCSETEN_PHYB   BIT3    // 0/x/x/x Port 3 LEQ DC Gain Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_DCSETEN_PHYB   BIT2    // 0/x/x/x Port 2 LEQ DC Gain Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_DCSETEN_PHYB   BIT1    // 0/x/x/x Port 1 LEQ DC Gain Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_DCSETEN_PHYB   BIT0    // 0/x/x/x Port 0 LEQ DC Gain Manual Set Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z141 0x9D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_DCSET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen1 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z142 0x9E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_DCSET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen1 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z143 0x9F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_DCSET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen1 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z144 0xA0 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_DCSET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen1 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z145 0xA1 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_DCSET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen2 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z146 0xA2 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_DCSET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen2 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z147 0xA3 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_DCSET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen2 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z148 0xA4 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_DCSET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen2 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z149 0xA5 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_DCSET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen3 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z150 0xA6 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_DCSET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen3 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z151 0xA7 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_DCSET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen3 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z152 0xA8 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_DCSET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen3 Equalizer Tuning Threshold Voltage
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z153 0xA9 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_HFSETEN_PHYB   BIT3    // 0/x/x/x Port 3 LEQ HF Gain Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_HFSETEN_PHYB   BIT2    // 0/x/x/x Port 2 LEQ HF Gain Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_HFSETEN_PHYB   BIT1    // 0/x/x/x Port 1 LEQ HF Gain Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_HFSETEN_PHYB   BIT0    // 0/x/x/x Port 0 LEQ HF Gain Manual Set Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z154 0xAA // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_HFSET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen1 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z155 0xAB // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_HFSET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen1 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z156 0xAC // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_HFSET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen1 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z157 0xAD // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_HFSET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen1 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z158 0xAE // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_HFSET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen2 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z159 0xAF // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_HFSET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen2 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z160 0xB0 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_HFSET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen2 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z161 0xB1 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_HFSET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen2 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z162 0xB2 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_HFSET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen3 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z163 0xB3 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_HFSET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen3 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z164 0xB4 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_HFSET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen3 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z165 0xB5 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_HFSET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen3 LEQ HF Gain Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z166 0xB6 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_OSSETEN_PHYB   BIT3    // 0/x/x/x Port 3 LEQ Offset Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_OSSETEN_PHYB   BIT2    // 0/x/x/x Port 2 LEQ Offset Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_OSSETEN_PHYB   BIT1    // 0/x/x/x Port 1 LEQ Offset Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_OSSETEN_PHYB   BIT0    // 0/x/x/x Port 0 LEQ Offset Manual Set Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z167 0xB7 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_OSSET_G1_PHYB  0x1F                    // 0/x/x/x Port 0 Gen1 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z168 0xB8 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_OSSET_G1_PHYB  0x1F                    // 0/x/x/x Port 1 Gen1 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z169 0xB9 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_OSSET_G1_PHYB  0x1F                    // 0/x/x/x Port 2 Gen1 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z170 0xBA // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_OSSET_G1_PHYB  0x1F                    // 0/x/x/x Port 3 Gen1 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z171 0xBB // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_OSSET_G2_PHYB  0x1F                    // 0/x/x/x Port 0 Gen2 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z172 0xBC // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_OSSET_G2_PHYB  0x1F                    // 0/x/x/x Port 1 Gen2 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z173 0xBD // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_OSSET_G2_PHYB  0x1F                    // 0/x/x/x Port 2 Gen2 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z174 0xBE // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_OSSET_G2_PHYB  0x1F                    // 0/x/x/x Port 3 Gen2 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z175 0xBF // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_OSSET_G3_PHYB  0x1F                    // 0/x/x/x Port 0 Gen3 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z176 0xC0 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_OSSET_G3_PHYB  0x1F                    // 0/x/x/x Port 1 Gen3 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z177 0xC1 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_OSSET_G3_PHYB  0x1F                    // 0/x/x/x Port 2 Gen3 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z178 0xC2 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_OSSET_G3_PHYB  0x1F                    // 0/x/x/x Port 3 Gen3 LEQ Offset Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z179 0xC3 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_W1SETEN_PHYB   BIT3    // 0/x/x/x Port 3 DFE Weight1 Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_W1SETEN_PHYB   BIT2    // 0/x/x/x Port 2 DFE Weight1 Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_W1SETEN_PHYB   BIT1    // 0/x/x/x Port 1 DFE Weight1 Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_W1SETEN_PHYB   BIT0    // 0/x/x/x Port 0 DFE Weight1 Manual Set Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z180 0xC4 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_W1SET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen1 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z181 0xC5 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_W1SET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen1 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z182 0xC6 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_W1SET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen1 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z183 0xC7 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_W1SET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen1 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z184 0xC8 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_W1SET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen2 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z185 0xC9 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_W1SET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen2 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z186 0xCA // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_W1SET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen2 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z187 0xCB // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_W1SET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen2 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z188 0xCC // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_W1SET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen3 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z189 0xCD // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_W1SET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen3 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z190 0xCE // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_W1SET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen3 DFE Weight1 Initial or Set value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z191 0xCF // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_W1SET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen3 DFE Weight1 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z192 0xD0 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_W2SETEN_PHYB   BIT3    // 0/x/x/x Port 3 DFE Weight2 Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_W2SETEN_PHYB   BIT2    // 0/x/x/x Port 2 DFE Weight2 Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_W2SETEN_PHYB   BIT1    // 0/x/x/x Port 1 DFE Weight2 Manual Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_W2SETEN_PHYB   BIT0    // 0/x/x/x Port 0 DFE Weight2 Manual Set Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z193 0xD1 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_W2SET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen1 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z194 0xD2 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_W2SET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen1 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z195 0xD3 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_W2SET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen1 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z196 0xD4 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_W2SET_G1_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen1 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z197 0xD5 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_W2SET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen2 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z198 0xD6 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_W2SET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen2 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z199 0xD7 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_W2SET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen2 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z200 0xD8 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_W2SET_G2_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen2 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z201 0xD9 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_W2SET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 0 Gen3 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z202 0xDA // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_W2SET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 1 Gen3 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z203 0xDB // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_W2SET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 2 Gen3 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z204 0xDC // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_W2SET_G3_PHYB  0x1F                    // 00001b/x/x/x Port 3 Gen3 DFE Weight2 Initial or Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z205 0xDD // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP00_DCOUT_PHYB  0x1F                    // 0/x/x/x Port 0 LEQ DC Gain Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z206 0xDE // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP01_DCOUT_PHYB  0x1F                    // 0/x/x/x Port 1 LEQ DC Gain Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z207 0xDF // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP02_DCOUT_PHYB  0x1F                    // 0/x/x/x Port 2 LEQ DC Gain Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z208 0xE0 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP03_DCOUT_PHYB  0x1F                    // 0/X/x/x Port 3 LEQ DC Gain Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z209 0xE1 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP00_HFOUT_PHYB  0x1F                    // 0/x/x/x Port 0 LEQ HF Gain Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z210 0xE2 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP01_HFOUT_PHYB  0x1F                    // 0/x/x/x Port 1 LEQ HF Gain Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z211 0xE3 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP02_HFOUT_PHYB  0x1F                    // 0/x/x/x Port 2 LEQ HF Gain Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z212 0xE4 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP03_HFOUT_PHYB  0x1F                    // 0/x/x/x Port 3 LEQ HF Gain Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z213 0xE5 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP00_OSOUT_PHYB  0x1F                    // 0/x/x/x Port 0 LEQ Offset Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z214 0xE6 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP01_OSOUT_PHYB  0x1F                    // 0/x/x/x Port 1 LEQ Offset Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z215 0xE7 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP02_OSOUT_PHYB  0x1F                    // 0/x/x/x Port 2 LEQ Offset Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z216 0xE8 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP03_OSOUT_PHYB  0x1F                    // 0/x/x/x Port 3 LEQ Offset Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z217 0xE9 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP00_W1OUT_PHYB  0x1F                    // 0/x/x/x Port 0 LEQ Weight1 Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z218 0xEA // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP01_W1OUT_PHYB  0x1F                    // 0/x/x/x Port 1 LEQ Weight1 Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z219 0xEB // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP02_W1OUT_PHYB  0x1F                    // 0/x/x/x Port 2 LEQ Weight1 Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z220 0xEC // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP03_W1OUT_PHYB  0x1F                    // 0/x/x/x Port 3 LEQ Weight1 Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z221 0xED // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP00_W2OUT_PHYB  0x1F                    // 0/x/x/x Port 0 LEQ Weight2 Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z222 0xEE // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP01_W2OUT_PHYB  0x1F                    // 0/x/x/x Port 1 LEQ Weight2 Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z223 0xEF // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP02_W2OUT_PHYB  0x1F                    // 0/x/x/x Port 2 LEQ Weight2 Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z224 0xF0 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP03_W2OUT_PHYB  0x1F                    // 0/x/x/x Port 3 LEQ Weight2 Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z225 0xF1 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNBISTEN_PHYB    BIT3    // 0/x/x/x Port 3 Tuning Function BIST Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNBISTEN_PHYB    BIT2    // 0/x/x/x Port 2 Tuning Function BIST Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNBISTEN_PHYB    BIT1    // 0/x/x/x Port 1 Tuning Function BIST Enable
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNBISTEN_PHYB    BIT0    // 0/x/x/x Port 0 Tuning Function BIST Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z226 0xF2 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_EQTNBISTEVT_PHYB   (BIT4 + BIT5 + BIT6)    // 0/x/x/x Port 1 Tuning Function BIST: Event Selection
    #define CND003_D15F0EPHYINDEXDATA_FRP00_EQTNBISTEVT_PHYB   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Port 0 Tuning Function BIST: Event Selection
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z227 0xF3 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_EQTNBISTEVT_PHYB   (BIT4 + BIT5 + BIT6)    // 0/x/x/x Port 3 Tuning Function BIST: Event Selection
    #define CND003_D15F0EPHYINDEXDATA_FRP02_EQTNBISTEVT_PHYB   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Port 2 Tuning Function BIST: Event Selection
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z228 0xF4 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP03_PG3_EQ_LS_PHYB BIT3    // 0/x/x/x Port 3 EQTN Tuning Speed at PCIe Gen3
    #define CND003_D15F0EPHYINDEXDATA_FHP02_PG3_EQ_LS_PHYB BIT2    // 0/x/x/x Port 2 EQTN Tuning Speed at PCIe Gen3
    #define CND003_D15F0EPHYINDEXDATA_FHP01_PG3_EQ_LS_PHYB BIT1    // 0b/x/x/x Port 1 EQTN Tuning Speed at PCIe Gen3
    #define CND003_D15F0EPHYINDEXDATA_FHP00_PG3_EQ_LS_PHYB BIT0    // 0b/x/x/x Port 0 EQTN Tuning Speed at PCIe Gen3
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_4_MISC_CTL 0xF5 // SATA_EPHY_4 Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_FTXSWN_PHYB_1_0    (BIT6 + BIT7)   // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP02_FTXSWN_PHYB_1_0    (BIT4 + BIT5)   // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP01_FTXSWN_PHYB_1_0    (BIT2 + BIT3)   // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP00_FTXSWN_PHYB_1_0    (BIT0 + BIT1)   // 0/x/x/x Reserved
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z229 0xF6 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPF6B7               BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EPF6B6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TDNCIS_PHYB    0x3F    // 10 0010b/x/x/x Port 0 LPn_TDNCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z230 0xF7 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPF7B7               BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EPF7B6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TDNCIS_PHYB    0x3F    // 10 0010b/x/x/x Port 1 LPn_TDNCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z231 0xF8 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPF8B7               BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EPF8B6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TDNCIS_PHYB    0x3F    // 10 0010b/x/x/x Port 2 LPn_TDNCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z232 0xF9 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPF9B7               BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EPF9B6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TDNCIS_PHYB    0x3F    // 10 0010b/x/x/x Port 3 LPn_TDNCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z233 0xFA // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPFAB7               BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EPFAB6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TDPCIS_PHYB    0x3F    // 0/x/x/x Port 0 LPn_TDPCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z234 0xFB // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPFBB7               BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EPFBB6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TDPCIS_PHYB    0x3F    // 0/x/x/x Port 1 LPn_TDPCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z235 0xFC // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPFCB7               BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EPFCB6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TDPCIS_PHYB    0x3F    // 0/x/x/x Port 2 LPn_TDPCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z236 0xFD // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPFDB7               BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EPFDB6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TDPCIS_PHYB    0x3F    // 0/x/x/x Port 3 LPn_TDPCIS for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z237 0xFE // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPFEB7           BIT7                    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP01_TXNSR_PHYB (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 LPn_TXNSR for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_EPFEB3           BIT3                    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP00_TXNSR_PHYB (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 LPn_TXNSR for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_4_MISC_CTL_Z1 0xFF // SATA_EPHY_4 Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EPFFB7           BIT7                    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP03_TXNSR_PHYB (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 LPn_TXNSR for SATA INDEX = 00/01b
    #define CND003_D15F0EPHYINDEXDATA_EPFFB3           BIT3                    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP02_TXNSR_PHYB (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 LPn_TXNSR for SATA INDEX = 00/01b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z238 0x100 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP_REFCLK_SEL_PHYB  BIT7            // 0/x/x/x Manual Setting for Selecting Internal or External Clock
    #define CND003_D15F0EPHYINDEXDATA_LP_REFCLKN_A_PHYB    BIT6            // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_LP_REFCLKP_A_PHYB    BIT5            // 0/x/x/x 1.0V Positive Terminal of Internal REFCLK (100MHz)
    #define CND003_D15F0EPHYINDEXDATA_LP_REFCLKN_D_PHYB    BIT4            // 0/x/x/x 0.9V Negative Terminal of Internal REFCLK (100MHz)
    #define CND003_D15F0EPHYINDEXDATA_LP_REFCLKP_D_PHYB    BIT3            // 0/x/x/x 0.9V Positive Terminal of Internal REFCLK (100MHz)
    #define CND003_D15F0EPHYINDEXDATA_FHP_BG_TRIM_PHYB     (BIT1 + BIT2)   // 01b/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FHP_EPHYMSTEN_PHYB   BIT0            // 0/x/x/x Force to Turn on All Functions in Master Block When EPHY Testing
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z239 0x101 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP_MPLL_OP_PHYB         BIT7    // 0/x/x/x MPLL Operation Mode for Debugging
    #define CND003_D15F0EPHYINDEXDATA_FHP_MPLL_CP_PHYB         0x78    // 0011b/x/x/x MPLL CP Current Setting
    #define CND003_D15F0EPHYINDEXDATA_FHP_MPLLMODE_PHYB        BIT2    // 1b/x/x/x MPLL Mode Selection
    #define CND003_D15F0EPHYINDEXDATA_FHP_MPLLREFCLK_SEL_PHYB  BIT1    // 1b/x/x/x MPLL Reference Clock Manual Setting 
    #define CND003_D15F0EPHYINDEXDATA_FHP_REFCLKPS_SEL_PHYB    BIT0    // 1b/x/x/x Internal PCIe or SATA Clock Manual Setting 
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z240 0x102 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP_MPLL_FLAGCK_EN_PHYB  BIT5            // 0/x/x/x Enable MPLL Flag Function When Debug Mode
    #define CND003_D15F0EPHYINDEXDATA_EP_MPLLOK_PHYB           BIT4            // 0/x/x/x MPLL Lock Flag
    #define CND003_D15F0EPHYINDEXDATA_EP_FLAG250_PHYB          BIT3            // 0/x/x/x MPLL and TPLL Synchronization Flag
    #define CND003_D15F0EPHYINDEXDATA_FHP_MPLL_DELAY_PHYB      (BIT1 + BIT2)   // 01b/x/x/x MPLL Feedback Divider Delay Setting.
    #define CND003_D15F0EPHYINDEXDATA_FHP_MPLL_LOCK_EN_PHYB    BIT0            // 0/x/x/x Overwrite MPLL Lock Flag Setting
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z241 0x103 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_CP_G1_PHYB 0xF0    // 5h/x/x/x Main 1 TPLL CP Current Setting for Gen1 Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_CP_G1_PHYB 0xF     // 5h/x/x/x Main 0 TPLL CP Current Setting for Gen1 Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z242 0x104 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_CP_G2_PHYB 0xF0    // 5h/x/x/x Main 1 TPLL CP Current Setting for Gen2 Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_CP_G2_PHYB 0xF     // 5h/x/x/x Main 0 TPLL CP Current Setting for Gen2 Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z243 0x105 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_CP_G3_PHYB 0xF0    // 5h/x/x/x Main 1 TPLL CP Current Setting for Gen3 Mode
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_CP_G3_PHYB 0xF     // 5h/x/x/x Main 0 TPLL CP Current Setting for Gen3 Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z244 0x106 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP1_TPLL_OK_PHYB         BIT5            // 0/x/x/x Main 1 TPLL Lock Flag Lock 
    #define CND003_D15F0EPHYINDEXDATA_EP0_TPLL_OK_PHYB         BIT4            // 0/x/x/x Main 0 TPLL Lock Flag Lock
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_LOCK_EN_PHYB   BIT3            // 0/x/x/x Main 1 Overwrite TPLL Lock Flag Setting
    #define CND003_D15F0EPHYINDEXDATA_FHP0_TPLL_LOCK_EN_PHYB   BIT2            // 0/x/x/x Main 0 Overwrite TPLL Lock Flag Setting
    #define CND003_D15F0EPHYINDEXDATA_EP1_TPLL_DIV_PHYB        BIT1            // 0/x/x/x Main 1 TPLL Feedback Divider Output
    #define CND003_D15F0EPHYINDEXDATA_EP0_TPLL_DIV_PHYB        BIT0            // 0/x/x/x Main 0 TPLL Feedback Divider Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z245 0x107 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_DIV_G1_PHYB    (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Main 1 TPLL Feedback Frequency - Gen1
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_DIV_G1_PHYB    (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Main 0 TPLL Feedback Frequency- Gen1
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z246 0x108 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_DIV_G2_PHYB    (BIT4 + BIT5 + BIT6)    // 110b/x/x/x Main 1 TPLL Feedback Frequency - Gen2
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_DIV_G2_PHYB    (BIT0 + BIT1 + BIT2)    // 110b/x/x/x Main 0 TPLL Feedback Frequency - Gen2
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z247 0x109 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_DIV_G3_PHYB    (BIT4 + BIT5 + BIT6)    // 111b/x/x/x Main 1 TPLL Feedback Frequency - Gen3
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_DIV_G3_PHYB    (BIT0 + BIT1 + BIT2)    // 111b/x/x/x Main 0 TPLL Feedback Frequency- Gen3
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z248 0x10A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_BAND_G1_PHYB   (BIT4 + BIT5)   // 00b/x/x/x Main 1 TPLL VCO Operation Frequency - Gen1
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_BAND_G1_PHYB   (BIT2 + BIT3)   // 00b/x/x/x Main 0 TPLL VCO Operation Frequency- Gen1
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_FLAGCK_EN_PHYB BIT1            // 0/x/x/x Main 1 Enable TPLL Flag Function When in Debug Mode
    #define CND003_D15F0EPHYINDEXDATA_FHP0_TPLL_FLAGCK_EN_PHYB BIT0            // 0/x/x/x Main 0 Enable TPLL Flag Function When in Debug Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z249 0x10B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_BAND_G3_PHYB   (BIT6 + BIT7)   // 00b/x/x/x Main 1 TPLL VCO Operation Frequency- Gen3
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_BAND_G3_PHYB   (BIT4 + BIT5)   // 00b/x/x/x Main 0 TPLL VCO Operation Frequency- Gen3
    #define CND003_D15F0EPHYINDEXDATA_FRP1_TPLL_BAND_G2_PHYB   (BIT2 + BIT3)   // 00b/x/x/x Main 1 TPLL VCO Operation Frequency - Gen2
    #define CND003_D15F0EPHYINDEXDATA_FRP0_TPLL_BAND_G2_PHYB   (BIT0 + BIT1)   // 00b/x/x/x Main 0 TPLL VCO operation frequency - Gen2
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z250 0x10C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_LF_PHYB    BIT3    // 0/x/x/x PLL Loop Order Selection
    #define CND003_D15F0EPHYINDEXDATA_FHP0_TPLL_LF_PHYB    BIT2    // 0/x/x/x PLL Loop Order Selection
    #define CND003_D15F0EPHYINDEXDATA_FHP1_GATECLK_EN_PHYB BIT1    // 1b/x/x/x Main 1 Enable Clock Gating When in Partial Mode
    #define CND003_D15F0EPHYINDEXDATA_FHP0_GATECLK_EN_PHYB BIT0    // 1b/x/x/x Main 0 Enable Clock Gating When in Partial Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z251 0x10D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP_RTNRXSETEN_PHYB  BIT1    // 0/x/x/x RX Resistance Set Enable
    #define CND003_D15F0EPHYINDEXDATA_FHP_RTNTXSETEN_PHYB  BIT0    // 0/x/x/x TX Resistance Set Enable
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z252 0x10E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP_RTNRXSET_PHYB    0xF0    // 8h/x/x/x RX Resistance Set Value
    #define CND003_D15F0EPHYINDEXDATA_FHP_RTNTXSET_PHYB    0xF     // 8h/x/x/x TX Resistance Set Value
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z253 0x10F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP_RTNRXOUT_PHYB 0xF0    // 0/x/x/x TX Resistance Output
    #define CND003_D15F0EPHYINDEXDATA_EP_RTNTXOUT_PHYB 0xF     // 0/x/x/x TX Resistance Output
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z254 0x110 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP_RTNBIST_PHYB (BIT0 + BIT1)   // 00b/x/x/x BIST Control
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z255 0x116 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP1_TPLL_SWBLW_PHYB  BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP1_TPLL_GSEL1_PHYB  BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP1_TPLL_GSEL0_PHYB  BIT0    // 0/x/x/x Reserved
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z256 0x117 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_SE_PHYB        BIT7    // 1b/x/x/x FHP1_TPLL_SE_PHYB
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_ISEL0_PHYB     BIT6    // 0/x/x/x FHP1_TPLL_ISEL0_PHYB
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_ISEL1_PHYB     BIT5    // 0/x/x/x FHP1_TPLL_ISEL1_PHYB
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_FSEL0_PHYB     BIT4    // 1b/x/x/x FHP1_TPLL_FSEL0_PHYB
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_FSEL1_PHYB     BIT3    // 0b/x/x/x FHP1_TPLL_FSEL1_PHYB
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_SWSEL0_PHYB    BIT2    // 1b/x/x/x FHP1_TPLL_SWSEL0_PHYB
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_SWSEL1_PHYB    BIT1    // 0/x/x/x FHP1_TPLL_SWSEL1_PHYB
    #define CND003_D15F0EPHYINDEXDATA_FHP1_TPLL_SWSEL2_PHYB    BIT0    // 1b/x/x/x FHP1_TPLL_SWSEL2_PHYB
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z257 0x118 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_G3_TX_DUTY_PHYB    (BIT6 + BIT7)   // 0/x/x/x Port 3 TX_DUTY for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_FRP02_G3_TX_DUTY_PHYB    (BIT4 + BIT5)   // 0/x/x/x Port 2 TX_DUTY for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_FRP01_G3_TX_DUTY_PHYB    (BIT2 + BIT3)   // 0/x/x/x Port 1 TX_DUTY for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_FRP00_G3_TX_DUTY_PHYB    (BIT0 + BIT1)   // 0/x/x/x Port 0 TX_DUTY for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z258 0x119 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP00_G3_TXPSR_PHYB  (BIT5 + BIT6 + BIT7)    // 011b/x/x/x Port 0 LPn_TXPSR for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_FRP00_G3_TDCIS_PHYB  0x1F                    // 11011b/x/x/x Port 0 LPn_TDCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z259 0x11A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP01_G3_TXPSR_PHYB  (BIT5 + BIT6 + BIT7)    // 011b/x/x/x Port 1 LPn_TXPSR for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_FRP01_G3_TDCIS_PHYB  0x1F                    // 11011b/x/x/x Port 1 LPn_TDCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z260 0x11B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP02_G3_TXPSR_PHYB  (BIT5 + BIT6 + BIT7)    // 011b/x/x/x Port 2 LPn_TXPSR for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_FRP02_G3_TDCIS_PHYB  0x1F                    // 11011b/x/x/x Port 2 LPn_TDCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z261 0x11C // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_FRP03_G3_TXPSR_PHYB  (BIT5 + BIT6 + BIT7)    // 011b/x/x/x Port 3 LPn_TXPSR for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_FRP03_G3_TDCIS_PHYB  0x1F                    // 11011b/x/x/x Port 3 LPn_TDCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z262 0x11D // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP11DB7              BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP11DB6              BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP00_G3_TDNCIS_PHYB 0x3F    // 10 1100b/x/x/x Port 0 LPn_TDNCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z263 0x11E // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP11EB7              BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP11E6               BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP01_G3_TDNCIS_PHYB 0x3F    // 10 1100b/x/x/x Port 1 LPn_TDNCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z264 0x11F // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP11FB7              BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP11FB6              BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP02_G3_TDNCIS_PHYB 0x3F    // 10 1100b/x/x/x Port 2 LPn_TDNCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z265 0x120 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP120B7              BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP120B6              BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP03_G3_TDNCIS_PHYB 0x3F    // 10 1100b/x/x/x Port 3 LPn_TDNCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z266 0x121 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP121B7              BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP121B6              BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP00_G3_TDPCIS_PHYB 0x3F    // 01 0001b/x/x/x Port 0 LPn_TDPCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z267 0x122 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP122B7              BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP122B6              BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP01_G3_TDPCIS_PHYB 0x3F    // 01 0001b/x/x/x Port 1 LPn_TDPCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z268 0x123 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP123B7              BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP123B6              BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP02_G3_TDPCIS_PHYB 0x3F    // 010 001b/x/x/x Port 2 LPn_TDPCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z269 0x124 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP124B7              BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP124B6              BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP03_G3_TDPCIS_PHYB 0x3F    // 010001b/x/x/x Port 3 LPn_TDPCIS for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z270 0x125 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP125B7              BIT7                    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP01_G3_TXNSR_PHYB  (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 1 LPn_TXNSR for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_EP125B3              BIT3                    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP00_G3_TXNSR_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 0 LPn_TXNSR for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z271 0x126 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP126B7              BIT7                    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP03_G3_TXNSR_PHYB  (BIT4 + BIT5 + BIT6)    // 011b/x/x/x Port 3 LPn_TXNSR for SATA INDEX = 10b
    #define CND003_D15F0EPHYINDEXDATA_EP126B3              BIT3                    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_FRP02_G3_TXNSR_PHYB  (BIT0 + BIT1 + BIT2)    // 011b/x/x/x Port 2 LPn_TXNSR for SATA INDEX = 10b
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z272 0x127 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP127B7          BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP127B6          BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP127B5          BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP127B4          BIT4    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP127B3          BIT3    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP127B2          BIT2    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP127B1          BIT1    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_TST_MODE_PHYB    BIT0    // 0/x/x/x MUX Select of Test Data and Normal Data for Parameter Testing
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z273 0x128 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP128B7                  BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP128B6                  BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP128B5                  BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_LP00_RDETEN_TST_PHYB     BIT4    // 0/x/x/x LP00_RDETEN Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP00_TXRDETPDB_TST_PHYB  BIT3    // 0/x/x/x LP00_TXRDETPDB Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP00_RXHZ_TST_PHYB       BIT2    // 0/x/x/x LP00_RXHZ Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP00_TXHZ_TST_PHYB       BIT1    // 0/x/x/x LP00_TXHZ Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP00_EIDLESQPDB_TST_PHYB BIT0    // 0/x/x/x LP00_EIDLESQPDB Control Register under Test Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z274 0x129 // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP129B7                  BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP129B6                  BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP129B5                  BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_LP01_RDETEN_TST_PHYB     BIT4    // 0/x/x/x LP01_RDETEN Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP01_TXRDETPDB_TST_PHYB  BIT3    // 0/x/x/x LP01_TXRDETPDB Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP01_RXHZ_TST_PHYB       BIT2    // 0/x/x/x LP01_RXHZ Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP01_TXHZ_TST_PHYB       BIT1    // 0/x/x/x LP01_TXHZ Control Register Under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP01_EIDLESQPDB_TST_PHYB BIT0    // 0/x/x/x LP01_EIDLESQPDB Control Register under Test Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z275 0x12A // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP12AB7                  BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP12AB6                  BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP12AB5                  BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_LP02_RDETEN_TST_PHYB     BIT4    // 0/x/x/x LP02_RDETEN Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP02_TXRDETPDB_TST_PHYB  BIT3    // 0/x/x/x LP02_TXRDETPDB Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP02_RXHZ_TST_PHYB       BIT2    // 0/x/x/x LP02_RXHZ Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP02_TXHZ_TST_PHYB       BIT1    // 0/x/x/x LP02_TXHZ Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP02_EIDLESQPDB_TST_PHYB BIT0    // 0/x/x/x LP02_EIDLESQPDB Control Register under Test Mode
#define CND003_D15F0EPHYINDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z276 0x12B // SATA_EPHY_PHYB Miscellaneous Control
    #define CND003_D15F0EPHYINDEXDATA_EP12BB7                  BIT7    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP12BB6                  BIT6    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_EP12BB5                  BIT5    // 0/x/x/x Reserved
    #define CND003_D15F0EPHYINDEXDATA_LP03_RDETEN_TST_PHYB     BIT4    // 0/x/x/x LP03_RDETEN Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP03_TXRDETPDB_TST_PHYB  BIT3    // 0/x/x/x LP03_TXRDETPDB Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP03_RXHZ_TST_PHYB       BIT2    // 0/x/x/x LP03_RXHZ Control Register under Test Mode
    #define CND003_D15F0EPHYINDEXDATA_LP03_TXHZ_TST_PHYB       BIT1    // 0/x/x/x LP03_TXHZ Control Register under Test Mode
    
    #define CND003_D15F0EPHYINDEXDATA_LP03_EIDLESQPDB_TST_PHYB BIT0    // 0/x/x/x LP03_EIDLESQPDB Control Register under Test Mode
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CHX001(1.00)
// Pls contact PLW to report Irs2h bugs.
