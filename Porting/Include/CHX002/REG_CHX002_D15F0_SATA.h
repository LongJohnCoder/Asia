//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		SATA					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D15F0_SATA_R102(A0).doc(final)MOD_SATA.xls
#ifndef _CHX002_D15F0_SATA_H
#define _CHX002_D15F0_SATA_H
//D15F0
#define D15F0_VID		0x00	//Vendor ID
    #define D15F0_VENDORID			0xFFFF	//1106h/x/x/x Vendor ID
#define D15F0_DID		0x02	//PCI Device ID Register
    #define D15F0_DEVID			0xFFFF	//9003h/x/x/x Device ID
#define D15F0_PCI_CMD_REG		0x04	//PCI Command Register
    #define D15F0_DISINT			BIT10	//0/x/x/x Interrupt Disable
    #define D15F0_RPTYERR			BIT6	//0/R/x/x Parity Error Response
    #define D15F0_R04B5			BIT5	//0/R/x/x VGA Palette Snooping
    #define D15F0_R04B4			BIT4	//0/R/x/x Memory Write and Invalidate
    #define D15F0_R04B3			BIT3	//0/R/x/x Respond to Special Cycle
    #define D15F0_BUSMSTR			BIT2	//0/x/x/x Bus Master
    #define D15F0_PREMMSPACE			BIT1	//0/x/x/x Memory Space Access
    #define D15F0_PREIOSPACE			BIT0	//0/x/x/x I/O Space Access
#define D15F0_PCI_STA_REG		0x06	//PCI Status Register
    #define D15F0_SATADPE			BIT15	//0/R/x/x Detected Parity Error
    #define D15F0_SSE			BIT14	//0/R/x/x Signaled System Error (SERR# Asserted)
    #define D15F0_RMA			BIT13	//0/x/x/x Received Master Abort
    #define D15F0_RTA			BIT12	//0/x/x/x Received Target Abort
    #define D15F0_TAA			BIT11	//0/R/x/x Target-Abort Assertion
    #define D15F0_DT			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D15F0_MDPE			BIT8	//0/R/x/x Master Data Parity Error
    #define D15F0_FBTBC			BIT7	//1b/R/x/x Fast Back-to-Back Capability
    #define D15F0_EN66			BIT5	//0/R/x/x 66 MHz Capable
    #define D15F0_PMCL			BIT4	//1b/R/x/x Power Management Capability List
    #define D15F0_INTS			BIT3	//0/R/x/x Interrupt Status
#define D15F0_REV_ID		0x08	//Revision ID
    #define D15F0_REVID			0xFF	//01h/x/x/x Revision ID
#define D15F0_PROGRAMMING_IF_FOR_RAID_MODE_RX0A_04HCLASS_CODE		0x09	//Programming Interface: For RAID Mode (Rx0A = 04h)Class Code
#define D15F0_SUB_CLASS_CODE		0x0A	//Sub Class Code
    #define D15F0_SUBCLASS			0xFF	//01h/R/x/x Sub Class
#define D15F0_BASE_CLASS_CODE		0x0B	//Base Class Code
    #define D15F0_BASECLASS			0xFF	//01h/R/x/x Base Class
#define D15F0_CACHE_LINE_SIZE		0x0C	//Cache Line Size
    #define D15F0_CACHLINE			0xFF	//0/x/x/x Cache Line Size
#define D15F0_LATENCY_TIMER		0x0D	//Latency Timer
    #define D15F0_LATENCYTIMER			0xF0	//2h/x/x/x Latency Timer
#define D15F0_HEADER_TYPE		0x0E	//Header Type
#define D15F0_AHCI_MODERESERVED		0x10	//) AHCI ModeReserved
#define D15F0_AHCI_MODERESERVED_Z1		0x14	//) AHCI ModeReserved
#define D15F0_IDE_BUS_MASTER_REGS_BASE_ADR_FOR_BOTH_CHNS		0x20	//IDE Bus Master Registers Base Address for Both Channels
    #define D15F0_WCTL15_4			0xFFF0	//cc0h/x/x/x IO Port Address ((Random)) 
    #define D15F0_WCTL3_0			0xF	//0001b/R/x/x IO Port Address
#define D15F0_RESERVED		0x24	//Reserved
#define D15F0_SVID		0x2C	//Subsystem Vendor ID
    #define D15F0_SVID_Z1			0xFFFF	//1106h/R/x/x Subsystem Vendor ID
#define D15F0_DID_Z1		0x2E	//PCI Device ID Register
    #define D15F0_SID			0xFFFF	//9003h/R/x/x Subsystem ID
#define D15F0_PM_CAPS_POINTER		0x34	//Power Management Capabilities Pointer
    #define D15F0_FLRCP			0xFF	//B0h/R/x/x Function Level Reset Capabilities Pointer
#define D15F0_INTR_LINE		0x3C	//Interrupt Line
    #define D15F0_SINTLN_7_4			0xF0	//0h/x/x/x IDE Interrupt Routing - High Byte 
    #define D15F0_ORG_SINTLN_3_0			0xF	//0h/x/x/x IDE Interrupt Routing - Low Byte
#define D15F0_INTR_PIN		0x3D	//Interrupt Pin
    #define D15F0_XINTPIN_2_0			(BIT0 + BIT1 + BIT2)	//001b/R/x/x Interrupt Pin
#define D15F0_MINIMUM_GRANT		0x3E	//Minimum Grant
#define D15F0_MAXIMUM_LATENCY		0x3F	//Maximum Latency
    #define D15F0_MAXLATENCY			0xFF	//0/R/x/x Maximum Latency
#define D15F0_SATA_CHN_ENABLE		0x40	//SATA Channel Enable
    #define D15F0_SA_HBA_RST			BIT3	//0/x/x/x SATA IDE and RAID Controller HBA Reset
    #define D15F0_R40B2			BIT2	//0/x/x/x Reserved
    #define D15F0_ENBLEA			BIT1	//1b/1/x/x Primary Channel (SATA) IO Access
    #define D15F0_ENBLEB			BIT0	//1b/x/x/x Secondary Channel (SATA) IO Access
#define D15F0_SATA_INTR		0x41	//SATA Interrupt
    #define D15F0_R41B7			BIT7	//0/x/x/x Reserved
    #define D15F0_GB_PRDBC2INT			BIT6	//0b/x/x/x Guard Bit for PRDBC to Int
    #define D15F0_GB_FLUSHEND			BIT5	//0b/x/x/x Guard Bit for FLUSHEND to Int
    #define D15F0_AH_GINTMOD			BIT4	//1b/1/X/x Block Interrupt Till Read FIFO Empty for A DMA Read for AHCI Mode
    #define D15F0_R41B3			BIT3	//0/x/X/x Reserved
    #define D15F0_R41B2			BIT2	//0/x/x/x Reserved
    #define D15F0_GINTMOD			BIT1	//1b/1/x/x Block Interrupt Till Read FIFO Empty for A DMA Read for SATA IDE/RAID Mode
    #define D15F0_R41B0			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_LINK_PHY_AND_AHCI_PORT_SEL_CTL		0x42	//SATA LINK/PHY and AHCI Port Selection Control
    #define D15F0_GB_UPDATEREG			BIT7	//0/x/x/x Guard bit for UpdateReg
    #define D15F0_GB_NOTEMPTY       BIT6    // 0/x/x/x Guard bit for NotEmpty
    #define D15F0_GB_RDMADATA_CYC			BIT5	//0/x/x/x Guard bit for RDMADATA_CYC
    #define D15F0_GB_CLRFF			BIT4	//0/x/x/x Guard bit for CLRFF
    #define D15F0_SATA_PORT_SEL_3_0			0xF	//0/x/x/x SATA LINK/PHY and AHCI Port Selection
#define D15F0_SATA_FIFO_THRESHOLD_CTL		0x43	//SATA FIFO Threshold Control
    #define D15F0_FFTHRA_3_0			0xF0	//0100b/x/x/x Reserved 
    #define D15F0_R43B3			BIT3	//0/x/x/x Reserved
    #define D15F0_R43B_2_0			(BIT0 + BIT1 + BIT2)	//100b/x/x/x Reserved
#define D15F0_MISC_CTL_1		0x44	//Miscellaneous Control 1
    #define D15F0_SAPIOGCLKEN			BIT7	//0/0/x/1 Legacy SATA Primary Channel PIOC Downstream GCLK Dynamic Clock Enable
    #define D15F0_SBPIOGCLKEN			BIT6	//0/x/x/x Reserved
    #define D15F0_R44B5			BIT5	//0/x/x/x Reserved
    #define D15F0_WAIT_PHYRDY			BIT4	//1b/1/x/x Gating Soft Reset When PHY Is Not Ready
    #define D15F0_R44B3			BIT3	//0/x/x/x Reserved
    #define D15F0_FFRDT2			BIT2	//1b/x/x/x Reserved
    #define D15F0_R44B1			BIT1	//0/x/x/x Reserved
    #define D15F0_ENEXITRXREG			BIT0	//1b/x/x/x Reserved
#define D15F0_MISC_CTL_2		0x45	//Miscellaneous Control 2
    #define D15F0_WPSUBCLASS			BIT7	//0/x/x/x Sub Class (Rx0A) Write Enable
    #define D15F0_ENSAPIOCLK_GATE			BIT6	//0/0/x/1 SATA Downstream GCLK Clock Dynamic Enable
    #define D15F0_ENSTRFUPECLK_GATE			BIT5	//0b/0/x/1 STRFUP ECLK Clock Dynamic Enable
    #define D15F0_WPINTL			BIT4	//0b/x/x/x Interrupt Line (Rx3C) Write Enable
    #define D15F0_R45B_3_2			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D15F0_ENDINT			BIT1	//1b/1/x/x Flush Read DMA Data After Interrupt
    #define D15F0_R45B0			BIT0	//0/x/x/x Reserved
#define D15F0_MISC_CTL_3		0x46	//Miscellaneous Control 3
    #define D15F0_ENTP_CKGATE_P3			BIT7	//0/x/x/x Reserved
    #define D15F0_ENTP_CKGATE_P2			BIT6	//0/x/x/x Reserved
    #define D15F0_ENTP_CKGATE_P1			BIT5	//0/0/x/1 Primary Channel Slave Port SA_TPECLK Clock Dynamic Gating Enable
    #define D15F0_ENTP_CKGATE_P0			BIT4	//0/0/x/1 Primary Channel Master Port SA_TPECLK Clock Dynamic Gating Enable
    #define D15F0_R46B2			BIT3	//0b/x/x/x Reserved
    #define D15F0_ENSTRFUPCLK_GATE			BIT2	//0/0/x/1 STRFUP UPCLK Clock Dynamic Gating Enable
    #define D15F0_R46B1			BIT1	//0/x/x/x Reserved
    #define D15F0_R46B0			BIT0	//0/x/x/x Reserved
#define D15F0_PORT_MULTIPLIER_PORT_ASSIGNMENT_MISC_CTLS		0x47	//Port Multiplier Port Assignment & MISC Controls
    #define D15F0_R47B_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_R47B3			BIT3	//0/x/x/x Reserved
    #define D15F0_R47B2			BIT2	//0/x/x/x Reserved
    #define D15F0_SELALIGN2OR4			BIT1	//0/x/x/x Option of Qualifying with Only 2 ALIGNs in OOB Sequencing
    #define D15F0_DIS_NOUPEREG			BIT0	//0/x/x/x Update Link and PHY Status for 1st D2H FIS When Software Reset Is In Progress
#define D15F0_SATA_DMAC_ECLK150_GATING		0x48	//SATA DMAC ECLK150 Gating
    #define D15F0_R48B_7_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_R48B4			BIT4	//0/x/x/x Reserved
    #define D15F0_P3_ENSAECLK150_GATE			BIT3	//0/x/x/x Reserved
    #define D15F0_P2_ENSAECLK150_GATE			BIT2	//0/x/x/x Reserved
    #define D15F0_P1_ENSAECLK150_GATE			BIT1	//0/0/x/1 Primary Channel Slave Port DMAC ECLK150 Gating Enable
    #define D15F0_P0_ENSAECLK150_GATE			BIT0	//0/0/x/1 Primary Channel Master Port DMAC ECLK150 Gating Enable
#define D15F0_SATA_PHY_CLK_GATING_CTL_REG		0x49	//SATA PHY Clock Gating Control Register
    #define D15F0_R49B7			BIT7	//0/x/x/x Reserved
    #define D15F0_R49B6			BIT6	//0/x/x/x Reserved
    #define D15F0_R49B5			BIT5	//0/x/x/x Reserved
    #define D15F0_R49B4			BIT4	//0/x/x/x Reserved
    #define D15F0_R49B3			BIT3	//0/x/x/x Reserved
    #define D15F0_R49B2			BIT2	//0/x/x/x Reserved
    #define D15F0_R49B1			BIT1	//0/x/x/x Reserved
    #define D15F0_ENTXCLK_GATE_PN			BIT0	//0/0/x/1 Port n PHY Clock Gating (Random)
#define D15F0_SATA_PHY_CLK_GATING_CTL_REG_Z1		0x4A	//SATA PHY Clock Gating Control Register
    #define D15F0_R4AB7			BIT7	//0/x/x/x Guard bit for R4AB0 R4AB1
    #define D15F0_R4AB_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define D15F0_R4AB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R4AB2			BIT2	//0/0/x/X reserved
    #define D15F0_R4AB1			BIT1	//0/0/x/1 Legacy SATA Primary Channel  (Slave) Hot-plug / Link PM Feature Select
    #define D15F0_R4AB0			BIT0	//0/0/x/1 Legacy SATA Primary Channel (Master) Hot-plug / Link PM Feature Select
#define D15F0_SATA_HOT_PLUG_STA		0x4B	//SATA Hot Plug Status
    #define D15F0_P3_PLUG_OUTSTS			BIT7	//0/x/x/x Reserved
    #define D15F0_P3_PLUG_INSTS			BIT6	//0/x/x/x Reserved
    #define D15F0_P2_PLUG_OUTSTS			BIT5	//0/x/x/x Reserved
    #define D15F0_P2_PLUG_INSTS			BIT4	//0/x/x/x Reserved
    #define D15F0_P1_PLUG_OUTSTS			BIT3	//0/x/x/x Primary Channel Slave Port Plug Out Status
    #define D15F0_P1_PLUG_INSTS			BIT2	//0/x/x/x Primary Channel Slave Port Plug In Status
    #define D15F0_P0_PLUG_OUTSTS			BIT1	//0/x/x/x Primary Channel Master Port Plug Out Status
    #define D15F0_P0_PLUG_INSTS			BIT0	//0/x/x/x Primary Channel Master Port Plug In Status
#define D15F0_COLD_PRESENCE_DETECT_SUPPORT		0x4C	//Cold Presence Detect Support
    #define D15F0_R4CB7			BIT7	//0/x/x/x Reserved
    #define D15F0_R4CB6			BIT6	//0/x/x/x Reserved
    #define D15F0_R4CB5			BIT5	//0/x/x/x Reserved
    #define D15F0_R4CB4			BIT4	//0/x/x/x Reserved
    #define D15F0_R4CB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R4CB2			BIT2	//0/x/x/x Reserved
    #define D15F0_EN_SATA_CPD_PN			BIT1	//0/x/x/x Reserved
    #define D15F0_AHN_SUP_CPD			BIT0	//0/x/x/x Reserved
#define D15F0_COLD_PRESENCE_DETECT_STA		0x4D	//Cold Presence Detect Status
    #define D15F0_R4DB7			BIT7	//0/x/x/x Reserved
    #define D15F0_R4DB6			BIT6	//0/x/x/x Reserved
    #define D15F0_R4DB5			BIT5	//0/x/x/x Reserved
    #define D15F0_R4DB4			BIT4	//0/x/x/x Reserved
    #define D15F0_R4DB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R4DB2			BIT2	//0/x/x/x Reserved
    #define D15F0_R4DB1			BIT1	//0/x/x/x Reserved
    #define D15F0_CPDSTAT			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_SPEED_CTL		0x4E	//SATA Speed Control
    #define D15F0_P3_SPD_SCR			(BIT6 + BIT7)	//10b/x/x/x Reserved
    #define D15F0_P2_SPD_SCR			(BIT4 + BIT5)	//10b/x/x/x Reserved
    #define D15F0_P1_SPD_SCR			(BIT2 + BIT3)	//10b/x/x/x Primary Channel Slave Port Speed Enable
    #define D15F0_P0_SPD_SCR			(BIT0 + BIT1)	//10b/x/x/x Primary Channel Master Port Speed Enable
#define D15F0_SATA_SPEED_NEGOTIATION_CTL		0x4F	//SATA Speed Negotiation Control
    #define D15F0_R4FB7			BIT7	//0/x/x/x Reserved
    #define D15F0_CONNECTRTY_CNT_1_0			(BIT5 + BIT6)	//0/x/x/x Do retry at the same SATA Gen speed before drop to the lower Gen speed when ConnectRty(Rx4F[3]) enabled
    #define D15F0_PN_DISREDSPEED			BIT4	//0/0/x/x PHY Link Speed Negotiation Scheme - Port n 
    #define D15F0_CONNECTRTY			BIT3	//1b/x/x/x Try Current Speed Several Times Before Reducing to Lower Speed  During OOB Speed Detection
    #define D15F0_CONNECTRTY_DLY_EN			BIT2	//0/x/x/x SATA Host Drop Speed Internal Time Delay Enable 
    #define D15F0_CONNECTRTY_DLY_SEL			BIT1	//0/x/x/x SATA Host Drop Speed Internal Time Delay Selection
    #define D15F0_R4FB0			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_MISC_CTL		0x50	//SATA Miscellaneous Control
    #define D15F0_R50B7			BIT7	//0/x/x/x Reserved
    #define D15F0_R50B6			BIT6	//0/x/x/x Reserved
    #define D15F0_BMSTATUS_SEL_A			BIT5	//0/x/x/x Bus Status SGACTV Selection for Primary Channel Master / Slave
    #define D15F0_BMSTATUS_SEL_B			BIT4	//0/x/x/x Reserved
    #define D15F0_ENIRQBYHPA			BIT3	//0/0/x/x Assert Interrupt to CPU When Either Ports of Primary Channel Have Plug-in or Plug-out
    #define D15F0_ENIRQBYHPB			BIT2	//0/x/x/x reserved
    #define D15F0_RSTSHADREG_A			BIT1	//0/x/x/x Reserved (Do Not Program)
    #define D15F0_RSTSHADREG_B			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_PHYRDY_STA_CTL		0x51	//SATA PHYRDY Status Control
    #define D15F0_R51B7			BIT7	//0/x/x/x Reserved
    #define D15F0_R51B6			BIT6	//0/x/x/x Reserved
    #define D15F0_R51B5			BIT5	//0/x/x/x Reserved
    #define D15F0_R51B4			BIT4	//0/x/x/x Reserved
    #define D15F0_R51B3			BIT3	//0/x/x/x Reserved
    #define D15F0_R51B2			BIT2	//0/x/x/x Reserved
    #define D15F0_R51B1			BIT1	//0/x/x/x Reserved
    #define D15F0_ENPHYRDYHLD_HOTPLG			BIT0	//0/x/x/x PHYRDY Keep High during Hot Plug Out
#define D15F0_SATA_PERFORMANCE_CTL		0x52	//SATA Performance Control
    #define D15F0_R52B7			BIT7	//0/x/x/x Reserved
    #define D15F0_PIPELINE_LVL			(BIT4 + BIT5 + BIT6)	//110b/x/x/x SATA Upstream Each Pipeline Level Setting
    #define D15F0_ARB_CNT			(BIT1 + BIT2 + BIT3)	//000b/x/x/x SATA STRFUP Each Port DMA Request Pipe Max Cycle Number Setting
    #define D15F0_ONLY4QW			BIT0	//0/x/0/x ((For Internal Reference:
#define D15F0_SATA_CMD_CTL_REG		0x53	//SATA Command Control Register
    #define D15F0_WDCMD			BIT7	//0/0/x/x TP Layer Idle for at Least 20us Before the Following Command Being Executed
    #define D15F0_CMD_CLKSEL			BIT6	//0/0/x/x The Least Time TP Layer Should Be Idle Before the Following Command Being Executed
    #define D15F0_ENAUTOCOMRSTCLRD2H			BIT5	//1b/1/1/1 Auto-send COMRESET Clear First D2H Signal Enable
    #define D15F0_ENPWRHOTPLUG			BIT4	//0/0/x/x Issue COMRESET When SATA Controller Receives COMINIT in Power Mode
    #define D15F0_R53B3			BIT3	//0/x/x/x Reserved
    #define D15F0_R53B_2_1			(BIT1 + BIT2)	//00b/x/x/x Reserved
    #define D15F0_ENPMNAK_CMD			BIT0	//1b/x/x/x Reject Device Power Request When HW Command Executes
#define D15F0_RESERVED_Z1		0x54	//Reserved
    #define D15F0_R54B7			BIT7	//0/x/x/x Reserved
    #define D15F0_R54B6			BIT6	//0/x/x/x Reserved
    #define D15F0_R54B5			BIT5	//0/x/x/x Reserved
    #define D15F0_R54B4			BIT4	//0/x/x/x Reserved
    #define D15F0_R54B3			BIT3	//0/x/x/x Reserved
    #define D15F0_R54B2			BIT2	//0/x/x/x Reserved
    #define D15F0_R54B1			BIT1	//0/x/x/x Reserved
    #define D15F0_PN_FORCEDEV			BIT0	//0/x/x/x Reserved (Do Not Program) 
#define D15F0_SATA_LINK_CTL_REG_1		0x55	//SATA Link Control Register 1
    #define D15F0_FIX6COMRESET			BIT7	//1b/1/x/x Host Always Transmits 6 COMRESET for Power-on Sequence
    #define D15F0_ENASYNRCOVSTP			BIT6	//1b/1/x/x Limit Continuous Asynchronous Recovery (AsynRcovery) to Five Times Only
    #define D15F0_INHIBITC4PSEL			BIT5	//0/0/x/x Conditions to Allow Back-to-Back Requests of Entering C4P
    #define D15F0_R55B4			BIT4	//0/x/x/x Reserved
    #define D15F0_R55B3			BIT3	//0/x/x/x Reserved
    #define D15F0_R55B2			BIT2	//0/x/x/x Reserved
    #define D15F0_EQTN_DURATION_MODE			(BIT0 + BIT1)	//01b/1/x/x EPHY EQTN Duration Control
#define D15F0_SATA_LINK_CTL_REG_2		0x56	//SATA Link Control Register 2
    #define D15F0_INITAWAKEUP			BIT7	//0/0/x/x Await Sync Before Returning to D0 (Ready & Idle)
    #define D15F0_EN_FREERXCLK			BIT6	//0/0/x/x Reserved
    #define D15F0_DIS_RXSCR			BIT5	//0/0/x/x Receiver Scrambler
    #define D15F0_DIS_TXSCR			BIT4	//0/0/x/x Transmitter Scrambler
    #define D15F0_DIS_ALIGN			BIT3	//0/0/x/x Align Primitive Transmission
    #define D15F0_DIS_CONT			BIT2	//0/0/x/x Continue Primitive Transmission
    #define D15F0_ENABLE_APPC			BIT1	//0/0/x/x (ALIGNp + CONTp) Primitives Transmission
    #define D15F0_ENINIT_WAKEMPLL			BIT0	//0/0/x/0 Hold Host Command for SATA Port Init Command until MPLL Wake up
#define D15F0_PHY_TEST_MODE_CTL_1		0x57	//PHY Test Mode Control 1
    #define D15F0_DXPATTSEL			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_R57B5			BIT5	//0/x/x/x Reserved
    #define D15F0_R57B4			BIT4	//0/x/x/x Reserved
    #define D15F0_R57B3			BIT3	//0/x/x/x Reserved
    #define D15F0_ENC4PHWK			BIT2	//0/x/x/x Reserved
    #define D15F0_ENC4PHREDET			BIT1	//0/x/x/x Reserved
    #define D15F0_RETRYSEL			BIT0	//0/x/x/x Reserved
#define D15F0_PHY_TEST_MODE_CTL_2		0x58	//PHY Test Mode Control 2
    #define D15F0_TSTMODE			BIT7	//0/0/x/x PHY Test Mode Enable
    #define D15F0_R58B_6_4			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define D15F0_MODESEL			0xF	//0/x/x/x PHY Test Pattern Select
#define D15F0_TEST_PATTERN_REPEAT_NUM		0x59	//Test Pattern Repeat Number
    #define D15F0_REPEATNUM			0xFF	//10h/x/x/x Test Pattern Repeat Number
#define D15F0_PHY_TEST_MODE_CTL_3		0x5A	//PHY Test Mode Control 3
    #define D15F0_ASYNRCOVSUP			BIT7	//1b/1/x/x Support Asynchronous Recovery Function
    #define D15F0_R5AB6			BIT6	//0/x/x/x Reserved
    #define D15F0_R5AB5			BIT5	//0/x/x/x Reserved
    #define D15F0_R5AB4			BIT4	//0/x/x/x Reserved
    #define D15F0_R5AB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R5AB2			BIT2	//0/x/x/x Reserved
    #define D15F0_SQUELCH_O			BIT1	//1b/R/x/x PHY RX Status 
    #define D15F0_PINSWAPMODE_N			BIT0	//0/x/x/x Reserved
#define D15F0_PHY_TEST_PORT_SEL_AND_MODE_STA		0x5B	//PHY Test Port Selection and Mode Status
    #define D15F0_R5BB_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_R5BB3			BIT3	//0/x/x/x Reserved
    #define D15F0_COMWAKE_O			BIT2	//0/R/x/x PHY RX Status
    #define D15F0_COMINIT_O			BIT1	//0/R/x/x PHY RX Status
    #define D15F0_CHKERROR			BIT0	//1b/R/x/x PHY Status
#define D15F0_PHY_CTL_REG_1		0x5C	//PHY Control Register 1
    #define D15F0_TOUTOOBX2			BIT7	//0/x/x/x Select The Number of Consecutive Data Bursts for COMRESET and COMWAKE
    #define D15F0_R5CB6			BIT6	//0/x/x/x Reserved
    #define D15F0_R5CB5			BIT5	//0/x/x/x Reserved
    #define D15F0_R5CB4			BIT4	//0/x/x/x Reserved
    #define D15F0_R5CB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R5CB2			BIT2	//0/x/x/x Reserved
    #define D15F0_R5CB1			BIT1	//0/x/x/x Reserved
    #define D15F0_ENPHY_STPCK_PN			BIT0	//0/0/x/1 SATA Port n PHY Dynamic Clock Gating ((Random)) 
#define D15F0_PHY_CTL_REG_2		0x5D	//PHY Control Register 2
    #define D15F0_RUNDISPARITY			BIT7	//0/0/x/x Determine Polarity of the Selected PHY Test Pattern
    #define D15F0_DBG_GRPSEL_14_8			0x7F	//0/x/x/x Reserved
#define D15F0_SATA_PHY_DATA_PATH_DEBUG_SIGNALS_GRPING_AND_RAM_BIST_CTL		0x5E	//SATA PHY Data Path Debug Signals Grouping and RAM BIST Control
    #define D15F0_DBG_GRP_CFGIDX			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_LONGSHORT			BIT4	//0/x/x/x Reserved
    #define D15F0_TPIN_MODE			0xF	//0/x/x/x Select which group of the SATA PHY data path debug signals to be mapped to the debug pins. 
#define D15F0_DEBUG_CTL_SEL		0x5F	//Debug Control Selection
    #define D15F0_DBG_GRPSEL_7_0			0xFF	//0/x/x/x Reserved
#define D15F0_DEBUG_SIGNALS_GRPING_AND_RAM_BIST_CTL		0x60	//Debug Signals Grouping and RAM BIST Control
    #define D15F0_R60B_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_R60B_5_3			(BIT3 + BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_TSTRX2TXMODE			BIT2	//0/x/x/x Reserved 
    #define D15F0_EN_POWERMODE_NEW			BIT1	//0/x/x/x Reserved
    #define D15F0_EN_NOTPOWERMODE_OLD			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_CTL_REG_2_PROVIDE_OPTIONS_FOR_RX_RETIMED_LOOPBACK_BIST_L_TEST		0x61	//SATA Control Register 2: Provide Options for Rx Retimed Loopback (BIST_L) Test
    #define D15F0_GATESQUELCH			BIT7	//0/x/x/x Reserved.
    #define D15F0_LBPSEL			BIT6	//0/0/x/x Select Which LBP Pattern to Use for Testing (Tx)
    #define D15F0_ENLBRX_RETIME			BIT5	//0/0/x/x Enable Rx Retimed Loopback Test Mode
    #define D15F0_ENKEEPALIGN			BIT4	//0/0/x/x During The BIST_L Loopback, Don¡¯t Delete Any Align Primitive in The Received Data Stream 
    #define D15F0_ENINSERT2ALIGN			BIT3	//0/0/x/x Insert Two Align Primitives 
    #define D15F0_R61B2			BIT2	//0/x/x/x Reserved
    #define D15F0_R61B_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D15F0_SATA_CTL_REG_3		0x62	//SATA Control Register 3
    #define D15F0_ENRSTCDR_BISTL			BIT7	//0/0/x/x For BIST_L Only: Reset CDR Module When CDR Disperses (Host Rx Disconnected)
    #define D15F0_FORCEPHYRDY			BIT6	//0/0/x/x Force PHY to PHYRDY State
    #define D15F0_ENTER_BISTL			BIT5	//0/0/x/x Force PHY to Enter BIST_L Mode (Without Receiving BIST_L from the Device)
    #define D15F0_ENHANCEOOBDET			BIT4	//0/0/x/x Relax Timing Margin for OOB Detection
    #define D15F0_PWRTMR_FULLRSTEN			BIT3	//0/0/x/x Reset Power Management Timer When It Counts to ¡®hf
    #define D15F0_NOQPHYRDY			BIT2	//0/0/x/x Command Handling Policies When PHY Is Not Ready (Downstream)
    #define D15F0_TXP_SEL			(BIT0 + BIT1)	//10b/x/x/x Reserved
#define D15F0_SATA_CTL_REG_4		0x63	//SATA Control Register 4
    #define D15F0_ENRECOMRST_ERRPRED2H			BIT7	//1b/x/x/x Resend COMRESET When Recovering Device Error
    #define D15F0_ENTERTPIDLE_SRST			BIT6	//1b/x/x/x Reserved
    #define D15F0_DIS_NIEN_RSTDRVS			BIT5	//0/0/x/x Reset Drive Select to Master When Change Device Control Register Bit[1] (nIEN) for Primary Channel
    #define D15F0_DEVTOCDETEN			BIT4	//1b/x/x/x Device OOB sequence Time-out Clear DEVDET Status Enable
    #define D15F0_POUT_CLRDET_EN			BIT3	//1b/x/x/x Hotplug-out Clear DEVDET Status Enable
    #define D15F0_HOTPLUG_OP			BIT2	//1b/x/x/x Reserved
    #define D15F0_EN_SLU_PLLG			BIT1	//0/0/x/1 When Slumber, Gate SATA EPHY MPLL/TPLL
    #define D15F0_EN_SLU_PLLD			BIT0	//0/0/x/1 Turn Off SATA MPLL/TPLL When Entering Slumber
#define D15F0_SATA_EPHY_CTL_REG_DATA_0		0x64	//SATA EPHY Control Register Data 0
    #define D15F0_EPHYREGDATA0_7_0			0xFF	//0/x/x/x 8-bit Data of EPHY Control Register Which Is Linked by EPHY Register Pointer 0
#define D15F0_SATA_EPHY_CTL_REG_DATA_1		0x65	//SATA EPHY Control Register Data 1
    #define D15F0_EPHYREGDATA1_7_0			0xFF	//0/x/x/x 8-bit Data of EPHY Control Register Which Is Linked by EPHY Register Pointer 1
#define D15F0_SATA_EPHY_CTL_REG_DATA_2		0x66	//SATA EPHY Control Register Data 2
    #define D15F0_EPHYREGDATA2_7_0			0xFF	//0/x/x/x 8-bit Data of EPHY Control Register Which Is Linked by EPHY Register Pointer 2
#define D15F0_SATA_EPHY_CTL_REG_DATA_3		0x67	//SATA EPHY Control Register Data 3
    #define D15F0_EPHYREGDATA3_7_0			0xFF	//0/x/x/x 8-bit Data of EPHY Control Register Which Is Linked by EPHY Register Pointer 3
#define D15F0_SATA_EPHY_CTL_REG_POINTER		0x68	//SATA EPHY Control Register Pointer
    #define D15F0_EPHYREGADDR_15_0			0xFFFF	//0000h/x/x/x EPHY Control Register Address Pointer Low
#define D15F0_SATA_PHY_MISC_CTL_REGS_1		0x6A	//SATA PHY Miscellaneous Control Registers 1
    #define D15F0_TX2RX_ALIGN_ADD			BIT7	//0/x/x/x Reserved
    #define D15F0_RX2TX_ALIGN			BIT6	//0/x/x/x Reserved
    #define D15F0_HOSTC4PWK_LATENCY_1_0			(BIT4 + BIT5)	//11b/x/x/x Reserved
    #define D15F0_PLLDCOND_DLY_1_0			(BIT2 + BIT3)	//01b/x/x/x Reserved
    #define D15F0_R6AB1			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_OOB_SEL_PN			BIT0	//0/x/x/x Select the Pattern Sent in OOB - Port n
#define D15F0_SATA_PHY_MISC_CTL_REGS_2		0x6B	//SATA PHY Miscellaneous Control Registers 2
    #define D15F0_R6BB7			BIT7	//0/x/x/x Reserved
    #define D15F0_R6BB6			BIT6	//0/x/x/x Reserved
    #define D15F0_R6BB5			BIT5	//0/x/x/x Reserved
    #define D15F0_R6BB4			BIT4	//0/x/x/x Reserved
    #define D15F0_R6BB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R6BB2			BIT2	//0/x/x/x Reserved
    #define D15F0_R6BB1			BIT1	//0/x/x/x Reserved
    #define D15F0_RX_TIMER_SEL_PN			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_PHY_MISC_CTL_REGS_3		0x6C	//SATA PHY Miscellaneous Control Registers 3
    #define D15F0_R6CB7			BIT7	//0/x/x/x Reserved
    #define D15F0_R6CB6			BIT6	//0/x/x/x Reserved
    #define D15F0_R6CB5			BIT5	//0/x/x/x Reserved
    #define D15F0_R6CB4			BIT4	//0/x/x/x Reserved
    #define D15F0_R6CB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R6CB2			BIT2	//0/x/x/x Reserved
    #define D15F0_R6CB1			BIT1	//0/x/x/x Reserved
    #define D15F0_ERROR_COUNTER_SEL_PN			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_PHY_PMP_FILED		0x6D	//SATA PHY PMP Filed
    #define D15F0_P1_CUR_TX_PMP			0xF0	//0/x/x/x Reserved
    #define D15F0_P0_CUR_TX_PMP			0xF	//0/x/x/x Reserved
#define D15F0_SATA_PHY_PMP_FILED_Z1		0x6E	//SATA PHY PMP Filed
    #define D15F0_P3_CUR_TX_PMP			0xF0	//0/x/x/x Reserved
    #define D15F0_P2_CUR_TX_PMP			0xF	//0/x/x/x Reserved
#define D15F0_SATA_PHY_PMP_SUPPORT		0x6F	//SATA PHY PMP Support
    #define D15F0_P3_SUP_PMP			BIT7	//0/x/x/x Reserved
    #define D15F0_P2_SUP_PMP			BIT6	//0/x/x/x Reserved
    #define D15F0_P1_SUP_PMP			BIT5	//0/x/x/x Enable PMP Support - Primary Channel Slave Port
    #define D15F0_P0_SUP_PMP			BIT4	//0/x/x/x Enable PMP Support - Primary Channel Master Port
    #define D15F0_R6FB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R6FB2			BIT2	//0/x/x/x Reserved
    #define D15F0_R6FB1			BIT1	//0/x/x/x Reserved
    #define D15F0_R6FB0			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_AUTO_PARTIAL_TO_SLUMBER_TRANSPORT_SPST_ENABLE		0x70	//SATA Auto Partial to Slumber Transport (SPST) Enable
    #define D15F0_ENC4P_APST			BIT7	//0/x/x/x Reserved
    #define D15F0_R70B6			BIT6	//0/x/x/x Reserved
    #define D15F0_R70B5			BIT5	//0/x/x/x Reserved
    #define D15F0_R70B4			BIT4	//0/x/x/x Reserved
    #define D15F0_R70B3			BIT3	//0/x/x/x Reserved
    #define D15F0_R70B2			BIT2	//0/x/x/x Reserved
    #define D15F0_R70B1			BIT1	//0/x/x/x Reserved
    #define D15F0_PN_ENAPST			BIT0	//0/x/x/x Auto Partial to Slumber Transport Enable
#define D15F0_SATA_APST_CLK_SEL		0x71	//SATA APST Clock Selection
    #define D15F0_SACFGWISO			BIT7	//0/x/x/x SATA DMA Read (P2C Write) Transfer ISO Priority Set
    #define D15F0_SACFGRISO			BIT6	//0/x/x/x SATA DMA Write (P2C Read) Transfer ISO Priority Set
    #define D15F0_R71B5			BIT5	//0/x/x/x Reserved
    #define D15F0_APSTCKSEL_4_0			0x1F	//0/x/x/x Auto Partial to Slumber Transport Timer Counter Clock Selection
#define D15F0_SATA_STRFUP_CTL_AND_PMP_ERR_REG		0x72	//SATA STRFUP Control and PMP Error Register
    #define D15F0_R72B7			BIT7	//0/x/x/x Reserved
    #define D15F0_R72B6			BIT6	//0/x/x/x Reserved
    #define D15F0_R72B5			BIT5	//0/x/x/x Reserved
    #define D15F0_R72B4			BIT4	//0/x/x/x Reserved
    #define D15F0_SAWPIPE_EN			BIT3	//0/0/x/x SATA DMA Read (P2C Write) Request Pipe Control
    #define D15F0_SARPIPE_EN			BIT2	//0/0/x/x SATA DMA Write (P2C Read) Request Pipe Control
    #define D15F0_SACFGWHP			BIT1	//0/x/x/x SATA DMA Read (P2C Write) Transfer High Priority set
    #define D15F0_SACFGRHP			BIT0	//0/x/x/x SATA DMA Write(P2C Read) Transfer High Priority Set
#define D15F0_SATA_MSI_TIME_OUT		0x73	//SATA MSI Time out
    #define D15F0_MSI_TIMEOUT_VALUE			0xFE	//0/x/x/x MSI Timeout Value
    #define D15F0_MSI_TIMEOUT_EN			BIT0	//0/x/x/x MSI Timeout Enable
#define D15F0_LEGACY_SATA_PMP_MAP_STA_FOR_PORT_0_PORT_1		0x74	//Legacy SATA PMP Map Status for Port 0 ~ Port 1
    #define D15F0_P1_SNTF_H			0xFF000000	//0/x/x/x Reserved
    #define D15F0_P1_SNTF_L			0xFF0000	//0/x/X/x Reserved
    #define D15F0_P0_SNTF_H			0xFF00	//0/x/X/x Reserved
    #define D15F0_P0_SNTF_L			0xFF	//0/x/X/x Reserved
#define D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_DMA_AND_PIO_CMD_BASIC_STA_RESERVED		0x78	//Legacy SATA Secondary Channel Slave Port DMA and PIO Command Basic Status reserved
    #define D15F0_P3_TXPIODATA_S			BIT7	//0/x/x/x reserved
    #define D15F0_P3_RXPIODATA_S			BIT6	//0/x/x/x reserved
    #define D15F0_P3_TXDMADATA_S			BIT5	//0/x/x/x reserved
    #define D15F0_P3_RXDMADATA_S			BIT4	//0/x/x/x reserved
    #define D15F0_P3_SA_RDMA			BIT3	//0/x/x/x reserved
    #define D15F0_P3_SA_WDMA			BIT2	//0/x/x/x reserved
    #define D15F0_P3_SGACTV			BIT1	//0/x/x/x reserved
    #define D15F0_P3_EMPTY			BIT0	//0/x/x/x reserved
#define D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_DMA_AND_PIO_CMD_BASIC_STA_RESERVED		0x79	//Legacy SATA Secondary Channel Master Port DMA and PIO Command Basic Status reserved
    #define D15F0_P2_TXPIODATA_S			BIT7	//0/x/x/x reserved
    #define D15F0_P2_RXPIODATA_S			BIT6	//0/x/x/x reserved
    #define D15F0_P2_TXDMADATA_S			BIT5	//0/x/x/x reserved
    #define D15F0_P2_RXDMADATA_S			BIT4	//0/x/x/x reserved
    #define D15F0_P2_SA_RDMA			BIT3	//0/x/x/x reserved
    #define D15F0_P2_SA_WDMA			BIT2	//0/x/x/x reserved
    #define D15F0_P2_SGACTV			BIT1	//0/x/x/x reserved
    #define D15F0_P2_EMPTY			BIT0	//0/x/x/x reserved
#define D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_DMA_AND_PIO_CMD_BASIC_STA		0x7A	//Legacy SATA Primary Channel Slave Port DMA and PIO Command Basic Status
    #define D15F0_P1_TXPIODATA_S			BIT7	//0/x/x/x Port 1 SATA TP Enter TXPIODATA State
    #define D15F0_P1_RXPIODATA_S			BIT6	//0/x/x/x Port 1 SATA TP Enter RXPIODATA State
    #define D15F0_P1_TXDMADATA_S			BIT5	//0/x/x/x Port 1 SATA TP Enter TXDAMDATA State
    #define D15F0_P1_RXDMADATA_S			BIT4	//0/x/x/x Port 1 SATA TP Enter RXDMADATA State
    #define D15F0_P1_SA_RDMA			BIT3	//0/x/x/x Port 1 DMA Read Device Cycle Active
    #define D15F0_P1_SA_WDMA			BIT2	//0/x/x/x Port 1 DMA Write Device Cycle Active
    #define D15F0_P1_SGACTV			BIT1	//0/x/x/x Port 1 SG (Scatter/Gather) Operation Active
    #define D15F0_P1_EMPTY			BIT0	//1b/x/x/x Port 1 FIFO Empty Status
#define D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_DMA_AND_PIO_CMD_BASIC_STA		0x7B	//Legacy SATA Primary Channel Master Port DMA and PIO Command Basic Status
    #define D15F0_P0_TXPIODATA_S			BIT7	//0/x/x/x Port 0 SATA TP Enter TXPIODATA State
    #define D15F0_P0_RXPIODATA_S			BIT6	//0/x/x/x Port 0 SATA TP Enter RXPIODATA State
    #define D15F0_P0_TXDMADATA_S			BIT5	//0/x/x/x Port 0 SATA TP Enter TXDAMDATA State
    #define D15F0_P0_RXDMADATA_S			BIT4	//0/x/x/x Port 0 SATA TP Enter RXDMADATA State
    #define D15F0_P0_SA_RDMA			BIT3	//0/x/x/x Port 0 DMA Read Device Cycle Active
    #define D15F0_P0_SA_WDMA			BIT2	//0/x/x/x Port 0 DMA Write Device Cycle Active
    #define D15F0_P0_SGACTV			BIT1	//0/x/x/x Port 0 SG (Scatter/Gather) Operation Active
    #define D15F0_P0_EMPTY			BIT0	//1b/x/x/x Port 0 FIFO Empty Status
#define D15F0_SATA_CTL_REG_5		0x7C	//SATA Control Register 5
    #define D15F0_SRST_DIAGING_EN			BIT7	//1b/x/x/x Reserved
    #define D15F0_RESRST_EN			BIT6	//1b/x/x/x Reserved
    #define D15F0_W4ALIGNTOUT_EN			BIT5	//0/x/x/x Reserved
    #define D15F0_R7CB4			BIT4	//0/x/x/x Reserved
    #define D15F0_R7CB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R7CB2			BIT2	//0/x/x/x Reserved
    #define D15F0_R7CB1			BIT1	//0/x/x/x Reserved
    #define D15F0_R7CB0			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_PHY_STA		0x7D	//SATA PHY Status
    #define D15F0_S_P3_COMINIT			BIT7	//0/x/x/x reserved
    #define D15F0_S_P3_COMWAKE			BIT6	//0/x/x/x reserved
    #define D15F0_S_P2_COMINIT			BIT5	//0/x/x/x reserved
    #define D15F0_S_P2_COMWAKE			BIT4	//0/x/x/x reserved
    #define D15F0_S_P1_COMINIT			BIT3	//0/R/x/x PHY Port 1 Receiving COMINIT (See the note below)
    #define D15F0_S_P1_COMWAKE			BIT2	//0/R/x/x PHY Port 1 Receiving COMWAKE (See the note below)
    #define D15F0_S_P0_COMINIT			BIT1	//0/R/x/x PHY Port 0 Receiving COMINIT (See the note below)
    #define D15F0_S_P0_COMWAKE			BIT0	//0/R/x/x PHY Port 0 Receiving COMWAKE (See the note below)
#define D15F0_SATA_PHY_STA_Z1		0x7E	//SATA PHY Status
    #define D15F0_P3_PMPERR			BIT7	//0/x/x/x Reserved
    #define D15F0_P2_PMPERR			BIT6	//0/x/x/x Reserved
    #define D15F0_P1_PMPERR			BIT5	//0/x/x/x Primary Channel Slave Port Multiple Port (PMP) Error Status
    #define D15F0_P0_PMPERR			BIT4	//0/x/x/x Primary Channel Master Port Multiple Port (PMP) Error Status
    #define D15F0_P3_INTRQ			BIT3	//0/x/x/x Reserved
    #define D15F0_P2_INTRQ			BIT2	//0/x/x/x Reserved
    #define D15F0_P1_INTRQ			BIT1	//0/x/x/x Primary Channel Slave Port Interrupt Status
    #define D15F0_P0_INTRQ			BIT0	//0/x/x/x Primary Channel Master Port Interrupt Status
#define D15F0_SATA_PHY_PM_MODE_ENTERED_BY_SW_REQ		0x80	//SATA PHY Power Management Mode - Entered by Software Request
    #define D15F0_SETSLUM_REQ3			BIT7	//0/x/x/x Reserved
    #define D15F0_SETPART_REQ3			BIT6	//0/x/x/x Reserved
    #define D15F0_SETSLUM_REQ2			BIT5	//0/x/x/x Reserved
    #define D15F0_SETPART_REQ2			BIT4	//0/x/x/x Reserved
    #define D15F0_SETSLUM_REQ1			BIT3	//0/x/x/x For SPM Field (=0010b):
    #define D15F0_SETPART_REQ1			BIT2	//0/x/x/x SPM Field (=0001b):
    #define D15F0_SETSLUM_REQ0			BIT1	//0/x/x/x SPM Field (=0010b):
    #define D15F0_SETPART_REQ0			BIT0	//0/x/x/x SPM Field (=0001b):
#define D15F0_SATA_TRANSPORT_MISC_CTL		0x81	//SATA Transport Miscellaneous Control
    #define D15F0_P3_EARLYTPREQ			BIT7	//0/x/x/x Reserved
    #define D15F0_P2_EARLYTPREQ			BIT6	//0/x/x/x Reserved
    #define D15F0_P1_EARLYTPREQ			BIT5	//0/0/1/x Primary Channel Slave Port Transport Layer to Issue Early Request to Link Layer ((Random))
    #define D15F0_P0_EARLYTPREQ			BIT4	//0/0/1/x Primary Channel Master Port Transport Layer to Issue Early Request to Link Layer ((Random))
    #define D15F0_P3_NOOVER8K			BIT3	//0/x/X/x Reserved
    #define D15F0_P2_NOOVER8K			BIT2	//0/x/x/x Reserved
    #define D15F0_P1_NOOVER8K			BIT1	//0/0/x/x Primary Channel Slave Port Data Size Limit for a Single Data FIS (Legacy SATA USE ONLY)
    #define D15F0_P0_NOOVER8K			BIT0	//0/0/x/x Primary Channel Master Port Data Size Limit for a Single Data FIS (Legacy SATA USE ONLY)
#define D15F0_CHN_TRANSPORT_MISC_CTL		0x82	//Channel TransPort Miscellaneous Control
    #define D15F0_P3_ENBIST4SLV			BIT7	//0/x/x/x Reserved
    #define D15F0_P2_ENBIST4SLV			BIT6	//0/x/x/x Reserved
    #define D15F0_P1_ENBIST4SLV			BIT5	//0/x/x/x Reserved
    #define D15F0_P0_ENBIST4SLV			BIT4	//0/x/x/x Reserved
    #define D15F0_P3_LESSBUF			BIT3	//0/x/x/x Reserved
    #define D15F0_P2_LESSBUF			BIT2	//0/x/x/x Reserved
    #define D15F0_P1_LESSBUF			BIT1	//0/0/x/x Primary Channel Slave Port FIFO Flow Control, Set Water Mark for FIFO Read ((Random)) (Legacy SATA Use Only)
    #define D15F0_P0_LESSBUF			BIT0	//0/0/x/x Primary Channel Master Port FIFO Flow Control, Set Water Mark for FIFO Read ((Random)) (Legacy SATA Use Only)
#define D15F0_SATA_PHY_PM_MODE		0x84	//SATA PHY Power Management Mode
    #define D15F0_R85B7			BIT7	//0/x/x/x Reserved
    #define D15F0_PN_DISPARPWR			(BIT5 + BIT6)	//11b/11/x/10 Settings for Hardware Timer Activated Partial/Slumber Mode - Port n
    #define D15F0_PN_PWRCKSEL_4_0			0x1F	//10000b/x/0Fh/0Fh For RAID Mode:
#define D15F0_SECONDARY_CHN_SLAVE_PORT_RESET_STATE_MACHINE_AND_STA_UNDER_SLAVE_MODE		0x85	//Secondary Channel Slave Port Reset State Machine and Status under Slave Mode
    #define D15F0_P3_RSTSM			0xF0	//0/x/x/x Reserved
    #define D15F0_P3_SLV_CRCERR_STS			BIT3	//0/x/x/x Reserved
    #define D15F0_P3_SLVMEMR_BUSY			BIT2	//0/x/x/x Reserved
    #define D15F0_R85B_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D15F0_SECONDARY_CHN_MASTER_PORT_RESET_STATE_MACHINE_AND_STA_UNDER_SLAVE_MODE		0x86	//Secondary Channel Master Port Reset State Machine and Status under Slave Mode
    #define D15F0_P2_RSTSM			0xF0	//0/x/x/x Reserved
    #define D15F0_P2_SLV_CRCERR_STS			BIT3	//0/x/x/x Reserved
    #define D15F0_P2_SLVMEMR_BUSY			BIT2	//0/x/x/x Reserved
    #define D15F0_R86B_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D15F0_PRIMARY_CHN_SLAVE_PORT_RESET_STATE_MACHINE_AND_STA_UNDER_SLAVE_MODE		0x87	//Primary Channel Slave Port Reset State Machine and Status under Slave Mode
    #define D15F0_P1_RSTSM			0xF0	//0/x/x/x Port Reset State Mechine
    #define D15F0_P1_SLV_CRCERR_STS			BIT3	//0/x/x/x Port Memory Read Cycle Is Busy Now When Work as Slave Mode
    #define D15F0_P1_SLVMEMR_BUSY			BIT2	//0/x/x/x Port CRC Error Status When Works as Slave Mode
    #define D15F0_R87B_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D15F0_PRIMARY_CHN_MASTER_PORT_RESET_STATE_MACHINE_AND_STA_UNDER_SLAVE_MODE		0x88	//Primary Channel Master Port Reset State Machine and Status under Slave Mode
    #define D15F0_P0_RSTSM			0xF0	//0/x/x/x Port Reset State Mechine
    #define D15F0_P0_SLV_CRCERR_STS			BIT3	//0/x/x/x Port Memory Read Cycle Is Busy Now When Works as Slave Mode
    #define D15F0_P0_SLVMEMR_BUSY			BIT2	//0/x/x/x Port CRC Error Status When Works as Slave Mode
    #define D15F0_R88B_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D15F0_PATA_SATA_MISC_CTLS		0x89	//PATA/SATA Miscellaneous Controls
    #define D15F0_P3_DIS_W4D2H			BIT7	//0/x/x/x Reserved
    #define D15F0_P2_DIS_W4D2H			BIT6	//0/x/x/x Reserved
    #define D15F0_P1_DIS_W4D2H			BIT5	//0/0/x/x Primary Channel Slave Port Pass Command Even without First D2H FIS Is Received
    #define D15F0_P0_DIS_W4D2H			BIT4	//0/0/x/x Primary Channel Master Port Pass Command Even without First D2H FIS Is Received
    #define D15F0_P3_EN_CHKPMP_SWRST			BIT3	//0/x/x/x Reserved
    #define D15F0_P2_EN_CHKPMP_SWRST			BIT2	//0/x/x/x Reserved
    #define D15F0_P1_EN_CHKPMP_SWRST			BIT1	//0/0/x/x Primary Channel Slave Port Check if PMP Field Is Correct for a Software Reset
    #define D15F0_P0_EN_CHKPMP_SWRST			BIT0	//0/0/x/x Primary Channel Master Port Check if PMP Field Is Correct for a Software Reset
#define D15F0_SATA_CTL_REG_4_Z1		0x8A	//SATA Control Register 4
    #define D15F0_R8AB7			BIT7	//0/x/x/x Reserved
    #define D15F0_R8AB6			BIT6	//0/x/x/x Reserved
    #define D15F0_RSTD2HCKSEL			(BIT4 + BIT5)	//0/0/x/x Soft Reset Time out Timer Setting
    #define D15F0_P3_ENRSTTOUT			BIT3	//0/x/x/x Reserved
    #define D15F0_P2_ENRSTTOUT			BIT2	//0/x/x/x Reserved
    #define D15F0_P1_ENRSTTOUT			BIT1	//0/0/x/x Primary Channel Slave Port Enable Port Soft Reset Time Out
    #define D15F0_P0_ENRSTTOUT			BIT0	//0/0/x/x Primary Channel Master Port Enable Port Soft Reset Time Out
#define D15F0_SATA_CTL_REG_5_Z1		0x8B	//SATA Control Register 5
    #define D15F0_R8BB7			BIT7	//0/x/x/x Reserved
    #define D15F0_OOB2BURST_LEN_EN			BIT6	//0/x/x/x Check Two Bursts to Judge COMMINIT and COMWAKE When OOB Is Received from Device
    #define D15F0_SPINGPWR_EN			BIT5	//0/x/x/x Let Spin up Gating TXPWR, RXPWR into TX_P2 / RX_P2
    #define D15F0_ENASYNR3TIMES			BIT4	//0/0/x/x Only Try to Re-OOB 3 Times
    #define D15F0_EN_TPRXRDY2T_2			BIT3	//0/x/x/X Reserved
    #define D15F0_R8BB2			BIT2	//0/x/x/x Reserved
    #define D15F0_DISHOLD_EXTEND			BIT1	//0/x/x/x Reserved
    #define D15F0_PMSTATE_MUX_EN			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_PHY_DRIVE_CTL_WHEN_CHANGE_SRST		0x8C	//SATA PHY Drive Control When Change SRST
    #define D15F0_SADIS_SRST_RSTDRVS			BIT7	//0/x/x/x Reset Drive Select to Master When Changing Device Control Register Bit[2] (SRST) for the Primary Channel
    #define D15F0_SADIS_DIAG_RSTDRVS			BIT6	//0/x/x/x Reset Drive Select to Master When Issuing Diagnostic Command for the Primary Channel
    #define D15F0_SBDIS_SRST_RSTDRVS			BIT5	//0/x/x/x Reserved
    #define D15F0_SBDIS_DIAG_RSTDRVS			BIT4	//0/x/x/x Reserved
    #define D15F0_R8CB3			BIT3	//0/x/x/x Reserved
    #define D15F0_R8CB2			BIT2	//0/x/x/x Reserved
    #define D15F0_R8CB1			BIT1	//0/x/x/x Reserved
    #define D15F0_SETWAKE_REQN			BIT0	//0/x/x/x Assert Wakeup (from Partial/Slumber) Request to Port n PHY
#define D15F0_SATA_TXCDC_CTL		0x8D	//SATA TXCDC control
    #define D15F0_R8DB7			BIT7	//0/x/x/x Reserved
    #define D15F0_R8DB6			BIT6	//0/x/x/x Reserved
    #define D15F0_R8DB5			BIT5	//0/x/x/x Reserved
    #define D15F0_MA_STRICT_EN			BIT4	//0/x/x/x Downstream Request Master-abort Condition Selection
    #define D15F0_F_P2CW16QWMAX			BIT3	//0/x/x/x Force P2C Write Request¡¯S Max Length to 16QW
    #define D15F0_F_P2CR16QWMAX			BIT2	//0/x/x/x Force P2C Read Request¡¯S Max Length to 16QW
    #define D15F0_TXCDC_TXCLKDYNEN			BIT1	//0/0/1/1 SAPHYB_TXCDC TXCLK Dynamic Clock Enable
    #define D15F0_TXCDC_FIFORCK_SEL			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_SPEED_STA_CTL		0x8E	//SATA Speed Status Control
    #define D15F0_LKTXCLRPMEN			BIT7	//1b/x/x/x Link Tx State clear Partial/Slumber Request Enable
    #define D15F0_MSIXCAPDIS			BIT6	//0/x/x/x MSIX Capability Disable
    #define D15F0_LDPIOCNTRPSEL			BIT5	//0/x/x/x Use Posedge of LDPIOCNT to Sample Transfer Count Value in PIO SETUP FIS
    #define D15F0_ENRDMAECFLH			BIT4	//1b/x/x/x DMA Read finish Clear Flush Enable
    #define D15F0_MMSI_DISABLE			BIT3	//0/x/x/x Multiple MSI Disable
    #define D15F0_TST_EIDLEFORCE0_EN			BIT2	//0/x/x/x Force RX EIDLE SQUELCH  to 0 when Doing Internal Loop Back Testing.
    #define D15F0_DMAR_INTG_GB			BIT1	//0/x/x/x Interrupt Gating Method during DMA Read
    #define D15F0_SPDCLRSRC_SEL			BIT0	//0/x/x/x Speed Status Cleared by PHYRDY or DEVDET
#define D15F0_SATA_PHY_TEST_SIGNALS_OUTPUT_CTL_2		0x8F	//SATA PHY Test Signals Output Control 2
    #define D15F0_SELBISTERR			BIT7	//0/x/x/x Select BIST Error Signal to Be Output to SATAERR
    #define D15F0_SELSLVERR			BIT6	//0/x/x/x Slave Error Selection
    #define D15F0_R8FB_5_4			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_SATA_HDIM_BIST			BIT3	//0/x/x/x Enable HDMI-SATA BIST
    #define D15F0_MIS_MATCH_CON			BIT2	//0/x/x/x Phy BIST Pattern Mismatch
    #define D15F0_R8FB1			BIT1	//0/x/x/x Reserved
    #define D15F0_R8FB0			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_BIST_ACTIVATE_FIS_DATA_DWORD_1		0x90	//SATA BIST Activate FIS Data Dword 1
    #define D15F0_BIST_FISDW1			0xFFFFFFFF	//55555555h/x/x/x These four bytes are (part of) the data used for the following three different test functions:
#define D15F0_SATA_BIST_ACTIVATE_FIS_DATA_DWORD_2		0x94	//SATA BIST Activate FIS Data Dword 2
    #define D15F0_BIST_FISDW2			0xFFFFFFFF	//AAAAAAAAh/x/x/x These four bytes contain the bottom half of the data used for the following functions.
#define D15F0_SATA_BIST_ACTIVATE_FIS_MODES_CMDS_DEFINED_BY_THE_SATA_SPECIFICATION		0x98	//SATA BIST Activate FIS Modes / Commands Defined by the SATA Specification
    #define D15F0_FAR_TXONLY			BIT7	//0/x/x/x Far End Transmit Only Mode (BIST_T command)
    #define D15F0_BYPASS_ALIGN			BIT6	//0/x/x/x Bypass Transmit ALIGN Primitive (BIST_T option ¡°a¡±)
    #define D15F0_BYPASS_SCR			BIT5	//0/x/x/x Bypass Scramble (BIST_T option ¡°s¡±)
    #define D15F0_FAR_RETLBK			BIT4	//0/x/x/x Far End Retimed Loopback (BIST_L command)
    #define D15F0_FAR_AFEBLK			BIT3	//0/x/x/x Far End Analog (AFE) Loopback (Not supported)
    #define D15F0_TXPRIMONLY			BIT2	//0/x/x/x Primitive Bit (Not supported)
    #define D15F0_R98B1			BIT1	//0/x/x/x Reserved
    #define D15F0_VDRTESTMODE			BIT0	//0/x/x/x Vender Specific Test Mode (Not supported)
#define D15F0_SATA_BIST_ACTIVATE_FIS_STA		0x99	//SATA BIST Activate FIS Status
    #define D15F0_LB_BIST_CYC			BIT7	//0/R/x/x Selected Port in Receive Loopback Mode (BIST_L)
    #define D15F0_TXBIST_CYC			BIT6	//0/R/x/x Selected port in Transmit Loopback Mode (BIST_T)
    #define D15F0_TXBIST_ERR_STS			BIT5	//0/R/x/x BIST Error Detected for the Selected Port
    #define D15F0_TXBIST_BSY			BIT4	//0/R/x/x ¡°1¡± Indicates that the BIST Is Active at the Time of Inquiry for the Selected Port
    #define D15F0_R99B_3_1			(BIT1 + BIT2 + BIT3)	//0/x/x/x Reserved
    #define D15F0_BISTRUN			BIT0	//0/x/x/x Send BIST Activate FIS / BIST Status to Port
#define D15F0_AHCI_BIST_CTL		0x9A	//AHCI BIST Control
    #define D15F0_AH_LB_BIST_CYC			BIT7	//0/R/x/x AHCI In Receive Loop Back Mode
    #define D15F0_AH_TXBIST_CYC			BIT6	//0/R/x/x AHCI In Transmit Loop Back Mode
    #define D15F0_AH_TXBIST_BSY			BIT5	//0/R/x/x AHCI BIST Busy Status
    #define D15F0_AH_TXBIST_ERR			BIT4	//0/R/x/x AHCI BIST Error Status
    #define D15F0_R9AB_3_0			0xF	//0/x/x/x Reserved
#define D15F0_LEGACY_SATA_PMP_MAP_STA_FOR_PORT_2_PORT_3		0x9C	//Legacy SATA PMP Map Status for Port 2 ~ Port 3
    #define D15F0_P3_SNTF_H			0xFF000000	//0/x/x/x Reserved
    #define D15F0_P3_SNTF_L			0xFF0000	//0/x/X/x Reserved
    #define D15F0_P2_SNTF_H			0xFF00	//0/x/X/x Reserved
    #define D15F0_P2_SNTF_L			0xFF	//0/x/X/x Reserved
#define D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_STA_SSTA_IN_SATA_SPECIFICATION		0xA0	//Legacy SATA Primary Channel Master Port Status (SStatus in SATA Specification)
    #define D15F0_S_P0_GEN_SPD			(BIT4 + BIT5)	//0/R/x/x The Negotiated Interface Communication Speed Established (SPD Field)
    #define D15F0_S_P0_PHYSLUMBER			BIT3	//0/R/x/x Slumber Mode Power Management Status (IPM Field)
    #define D15F0_S_P0_PHYPARTIAL			BIT2	//0/R/x/x Partial Mode Power Management Status (IPM Field)
    #define D15F0_S_P0_PHYRDY			BIT1	//0/R/x/x PHY Communication Established (DET Field)
    #define D15F0_S_P0_DEVDET			BIT0	//0/R/x/x Device Detected (DET Field)
#define D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_STA_SSTA_IN_SATA_SPECIFICATION		0xA1	//Legacy SATA Primary Channel Slave Port Status (SStatus in SATA Specification)
    #define D15F0_S_P1_GEN_SPD			(BIT4 + BIT5)	//0/R/x/x The Negotiated Interface Communication Speed Established (SPD Field)
    #define D15F0_S_P1_PHYSLUMBER			BIT3	//0/R/x/x Slumber Mode Power Management Status (IPM Field)
    #define D15F0_S_P1_PHYPARTIAL			BIT2	//0/R/x/x IPM Field: Partial Mode Power Management Status
    #define D15F0_S_P1_PHYRDY			BIT1	//0/R/x/x PHY Communication Established (DET Field) 
    #define D15F0_S_P1_DEVDET			BIT0	//0/R/x/x Device Detected (DET Field)
#define D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_STA_SSTA_IN_SATA_SPECIFICATION		0xA2	//Legacy SATA Secondary Channel Master Port Status (SStatus in SATA Specification)
    #define D15F0_S_P2_GEN_SPD			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_S_P2_PHYSLUMBER			BIT3	//0/x/x/x Reserved
    #define D15F0_S_P2_PHYPARTIAL			BIT2	//0/x/x/x Reserved
    #define D15F0_S_P2_PHYRDY			BIT1	//0/x/x/x Reserved
    #define D15F0_S_P2_DEVDET			BIT0	//0/x/x/x Reserved
#define D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_STA_SSTA_IN_SATA_SPECIFICATION		0xA3	//Legacy SATA Secondary Channel Slave Port Status (SStatus in SATA Specification)
    #define D15F0_S_P3_GEN_SPD			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_S_P3_PHYSLUMBER			BIT3	//0/x/x/x Reserved
    #define D15F0_S_P3_PHYPARTIAL			BIT2	//0/x/x/x Reserved
    #define D15F0_S_P3_PHYRDY			BIT1	//0/x/x/x Reserved
    #define D15F0_S_P3_DEVDET			BIT0	//0/x/x/x Reserved
#define D15F0_LEGACY_SATA_PRIMARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION		0xA4	//Legacy SATA Primary Channel Master Port Control (SControl in SATA Specification)
    #define D15F0_RA4B_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_P0_DISSLUMBER			BIT3	//1b/1/x/0 For IPM Field = 0010b:
    #define D15F0_P0_DISPARTIAL			BIT2	//1b/1/x/0 For IPM Field = 0001b:
    #define D15F0_P0_DISABLE_SATA			BIT1	//0/x/x/x For DET Field = 0100b:
    #define D15F0_P0_SATAINIT			BIT0	//0/x/x/x For DET Field = 0001b:
#define D15F0_LEGACY_SATA_PRIMARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION		0xA5	//Legacy SATA Primary Channel Slave Port Control (SControl in SATA Specification)  
    #define D15F0_RA5B_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_P1_DISSLUMBER			BIT3	//1b/1/x/0 For IPM Field = 0010b:
    #define D15F0_P1_DISPARTIAL			BIT2	//1b/1/x/0 For IPM Field = 0001b:
    #define D15F0_P1_DISABLE_SATA			BIT1	//0/x/x/x For DET Field = 0100b:
    #define D15F0_P1_SATAINIT			BIT0	//0/x/x/x For DET Field = 0001b:
#define D15F0_LEGACY_SATA_SECONDARY_CHN_MASTER_PORT_CTL_SCTL_IN_SATA_SPECIFICATION		0xA6	//Legacy SATA Secondary Channel Master Port Control (SControl in SATA Specification)
    #define D15F0_RA6B_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_P2_DISSLUMBER			BIT3	//1b/x/x/x Reserved
    #define D15F0_P2_DISPARTIAL			BIT2	//1b/x/x/x Reserved
    #define D15F0_P2_DISABLE_SATA			BIT1	//0/x/x/x Reserved
    #define D15F0_P2_SATAINIT			BIT0	//0/x/x/x Reserved
#define D15F0_LEGACY_SATA_SECONDARY_CHN_SLAVE_PORT_CTL_SCTL_IN_SATA_SPECIFICATION		0xA7	//Legacy SATA Secondary Channel Slave Port Control (SControl in SATA Specification)
    #define D15F0_RA7B_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_P3_DISSLUMBER			BIT3	//1b/x/x/x Reserved
    #define D15F0_P3_DISPARTIAL			BIT2	//1b/x/x/x Reserved
    #define D15F0_P3_DISABLE_SATA			BIT1	//0/x/x/x Reserved
    #define D15F0_P3_SATAINIT			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_FUN_LEVEL_RESET_FLR		0xB0	//SATA Function Level Reset (FLR)
    #define D15F0_RB3B_7_2			0xFC000000	//0/x/x/x Reserved
    #define D15F0_FLR_CAP			BIT25	//0/x/x/x Set to 1b to Indicate Support of Function Level Reset (FLR)
    #define D15F0_TP_CAP			BIT24	//0/x/x/x Set to 1b to Indicate Support of the Transactions Pending(TP) Bit
    #define D15F0_FLR_LEN			0xFF0000	//06h/x/x/x FLR Length
    #define D15F0_FLRID_15_8			0xFF00	//C0h/x/x/X Next Capability Pointer
    #define D15F0_FLRID_7_0			0xFF	//13h/x/x/X Capability ID for FLR
//@self defined macro begin
#define D15F0_SATA_FUN_LEVEL_RESET_FLR_2 0xB3
//@self defined macro end
#define D15F0_SATA_FUN_LEVEL_RESET_FLR_Z1		0xB4	//SATA Function Level Reset (FLR)
    #define D15F0_INITFLR			BIT0	//0/x/x/X Function Level Reset Initial
#define D15F0_SATA_FUN_LEVEL_RESET_FLR_Z2		0xB5	//SATA Function Level Reset (FLR)
    #define D15F0_TXP			BIT0	//0/x/x/X Upstream Bus not Idle, or SATA Function Still On-going Indication
#define D15F0_LEGACY_SATA_OOB_KICK_OFF_CTL		0xB8	//Legacy SATA OOB Kick-Off Control
    #define D15F0_RB8B7			BIT7	//0/x/x/x Reserved
    #define D15F0_RB8B6			BIT6	//0/x/x/x Reserved
    #define D15F0_RB8B5			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_P3_SPINUP			BIT3	//0/x/x/x Reserved
    #define D15F0_P2_SPINUP			BIT2	//0/x/x/x Reserved
    #define D15F0_P1_SPINUP			BIT1	//0/x/x/x OOB Kick-Off Control for Primary Channel Slave Port ((Random))
    #define D15F0_P0_SPINUP			BIT0	//0/x/x/x OOB Kick-Off Control for Primary Channel Master Port ((Random))
#define D15F0_INTR_OPTIONAL_REG		0xB9	//Interrupt Optional Register
    #define D15F0_RB9B_7_3			0xF8	//0/x/x/x Reserved
    #define D15F0_INTPIN_2_0			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Reserved
#define D15F0_LED_CTL_OPTIONAL_REG		0xBB	//LED Control Optional Register
    #define D15F0_RBEB_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_LED_CTL_3_0			0xF	//0h/x/x/x SATA LED and Port Status Mapping
#define D15F0_RESERVED_Z2		0xBC	//Reserved
    #define D15F0_SUBVID_RSV			0xFFFF	//0000h/x/x/x Reserved
#define D15F0_VID_ENCLOUSER_MANEGEMENT_BUFFER_CTL_OPTIONAL_REG		0xBE	//Vendor ID/Enclouser Manegement Buffer Control Optional Register
    #define D15F0_RBEB_7_5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_EM_LOC_SEL			BIT4	//0b/x/x/x 0: Enclosure Manegement Buffer Offset is 500h
    #define D15F0_SUBID_SEL			BIT3	//0b/x/x/x Subsystem ID Selection Control
    #define D15F0_SUBVID_SEL			BIT2	//0b/x/x/x Subsystem Vendor ID Selection control
    #define D15F0_DID_RID_LOCK			BIT1	//0b/x/x/x Device ID and Revision ID lock control
    #define D15F0_VID_LOCK			BIT0	//0b/x/x/x VID lock control
#define D15F0_RESERVED_Z3		0xBF	//Reserved
    #define D15F0_RBFB_7_0			0xFF	//00h/x/x/x Reserved
#define D15F0_PM_CAP_ID		0xC0	//Power Management Capability ID
    #define D15F0_PMCID_IDE_15_8			0xFF00	//0/R/x/x Next Capability
    #define D15F0_PMCID_IDE_7_0			0xFF	//01h/R/x/x Capability ID
#define D15F0_PM_IF_REV		0xC2	//Power Management Interface Revision
    #define D15F0_PMREV_15_11			0xF800	//08h/08h/x/x PSUP, Indicates the States That Can Generate PME#
    #define D15F0_PMREV_2_0			(BIT0 + BIT1 + BIT2)	//010b/R/x/x Power Management Interface Revision
#define D15F0_PM_CAP_STA		0xC4	//Power Management Capability Status
    #define D15F0_PME_STS			BIT15	//0/R/x/x PME Status
    #define D15F0_PME_ENABLE			BIT8	//0/0/x/x PME Enable
    #define D15F0_PST1			(BIT0 + BIT1)	//00b/0/x/x Power Management Capability Status ((Random))
#define D15F0_DATA_REG_FOR_PM_CAP		0xC6	//Data Register for Power Management Capability
#define D15F0_SUBSYSTEM_ID_OPTIONAL_REG		0xC8	//Subsystem ID Optional Register
    #define D15F0_SUBID_BD			0xFFFF	//0000h/x/x/x Subsystem ID optional register
#define D15F0_SVID_OPTIONAL_REG		0xCA	//Subsystem Vendor ID Optional Register
    #define D15F0_SUBVID_BD			0xFFFF	//0000h/x/x/x Subsystem Vendor ID (Rx2C-2D) optional register
#define D15F0_RESERVED_Z4		0xCC	//Reserved
    #define D15F0_DEVID_AHCI_RSV			0xFFFF	//0000h/x/x/x Reserved
#define D15F0_RESERVED_Z5		0xCE	//Reserved
    #define D15F0_REVID_RSV			0xFF	//0/x/x/x Reserved
#define D15F0_MISC_REGS_382_RX49		0xD0	//Misc Registers ((382_Rx49))
    #define D15F0_ENGHCSAECLK_GATE			BIT7	//0/x/1/1 GHC GCLK Dynamic Clock Enable
    #define D15F0_ENGHCECLK150_GATE			BIT6	//0/x/1/1 GHC ECLK150 Clock Dynamic Enable
    #define D15F0_RD0B5			BIT5	//0/x/x/x Reserved
    #define D15F0_RD0B4			BIT4	//0/x/x/x Reserved
    #define D15F0_RD0B3			BIT3	//0/x/x/x Reserved
    #define D15F0_RD0B2			BIT2	//0/x/x/x Reserved
    #define D15F0_EN_SCLOCK_GATE			BIT1	//0/x/x/x Reserved
    #define D15F0_SOFT_ENAHCI			BIT0	//0/x/x/x Force Controller AHCI Function
#define D15F0_AHCI_MISC_REGS_382_RX4A		0xD1	//AHCI Misc Registers ((382_Rx4A))
    #define D15F0_PASS_FIRSTD2HX			BIT7	//0/0/x/x Always Write First D2H to Memory Region (Test only)
    #define D15F0_PIPE_RFISMEM			BIT6	//0/0/x/x Pipeline RFIS to Memory Cycle (Test Only)
    #define D15F0_SMSI_BYPIS			BIT5	//0/x/x/x Single MSI Assertion Method
    #define D15F0_FETCHCFIS64			BIT4	//0/0/x/x Fetch All 64 Bytes CFIS Field of Command Table
    #define D15F0_EN_RFISUPDATE			BIT3	//0/0/x/x AHCI Update Received FIS to Memory Function
    #define D15F0_EN_DMABCUPDATE			BIT2	//1b/1/x/x AHCI DMA Update Byte Count Function
    #define D15F0_RD1B1			BIT1	//0/x/x/x Reserved
    #define D15F0_ENCLCACHE			BIT0	//0/x/x/x AHCI Command List CTBA (Command Table Descriptor Base Address) Cache Function
#define D15F0_AHCI_DYNAMIC_CLK_ENABLE		0xD2	//AHCI Dynamic Clk Enable
    #define D15F0_RD2B7			BIT7	//0/x/x/x Reserved
    #define D15F0_RD2B6			BIT6	//0/x/x/x Reserved
    #define D15F0_RD2B5			BIT5	//0/x/x/x Reserved
    #define D15F0_RD2B4			BIT4	//0/x/x/x Reserved
    #define D15F0_RD2B3			BIT3	//0/x/x/x Reserved
    #define D15F0_RD2B2			BIT2	//0/x/x/x Reserved
    #define D15F0_RD2B1			BIT1	//0/x/x/x Reserved
    #define D15F0_RD2B0			BIT0	//0/x/x/x Reserved
#define D15F0_AHCI_TRANSPORT_MISC_CTL_382_RX52		0xD3	//AHCI Transport Misc. Control ((382_Rx52))
    #define D15F0_AHCI_SGSTOP			BIT7	//0/0/x/x Software Issued AHCI DMA Stop (Test Mode Only)
    #define D15F0_AHCI_EARLYTPREQ			BIT6	//0/0/1/x Transport Issues Early Request to Link for Better Performance
    #define D15F0_RD3B5			BIT5	//0/0/x/x Reset AHCI Transport Queue DMA Transfer Count (Test Only)
    #define D15F0_AHCI_NOOVER8K			BIT4	//0/0/x/x Signal Data FIS Transmission (AHCI Controller Only)
    #define D15F0_AHCI_ENBIST4SLV			BIT3	//0/x/x/x BIST FIS (AHCI Controller Only)
    #define D15F0_RD3B2			BIT2	//0/x/x/x Reserved
    #define D15F0_RD3B1			BIT1	//0/x/x/x Reserved
    #define D15F0_AHCI_RSTSHADREG			BIT0	//0/x/x/x Reset Shadow (Test Mode Only)
#define D15F0_SATA_DEV_MODE_TESTING_REG_TEST_MODE_ONLY		0xD4	//SATA Device Mode Testing Register (Test Mode Only)
    #define D15F0_SLV_BYPASSERR			BIT7	//0/x/x/x Port Device Mode Simulation Continues When Handshaking Error Occurs
    #define D15F0_RD4B6			BIT6	//0/x/x/x Reserved
    #define D15F0_RD4B5			BIT5	//0/x/x/x Reserved
    #define D15F0_RD4B4			BIT4	//0/x/x/x Reserved
    #define D15F0_RD4B3			BIT3	//0/x/x/x Reserved
    #define D15F0_RD4B2			BIT2	//0/x/x/x Reserved
    #define D15F0_RD4B1			BIT1	//0/x/x/x Reserved
    #define D15F0_PN_TRGSMEMR			BIT0	//0/x/x/x Trigger Port n Device Mode
#define D15F0_RESERVED_AHCI_DEV_MODE_TESTING_REG_1_TEST_MODE_ONLY		0xD5	//- Reserved AHCI Device Mode Testing Register 1 (Test Mode Only)
    #define D15F0_RD5B7			BIT7	//0/x/x/x Reserved
    #define D15F0_RD5B6			BIT6	//0/x/x/x Reserved
    #define D15F0_RD5B5			BIT5	//0/x/x/x Reserved
    #define D15F0_RD5B4			BIT4	//0/x/x/x Reserved
    #define D15F0_RD5B3			BIT3	//0/x/x/x Reserved
    #define D15F0_RD5B2			BIT2	//0/x/x/x Reserved
    #define D15F0_AH_SLVMEMR_BUSY			BIT1	//0/x/x/x Port Was Busy on Memory Read Cycle
    #define D15F0_AH_SLV_CRCERR_STS			BIT0	//0/x/x/x Port CRC Error Status
#define D15F0_AHCI_GHC_CAP2_OPTIONAL_REGS_AND_SLAVE_TP_REGS		0xD6	//AHCI GHC CAP2 Optional Registers and Slave TP registers
    #define D15F0_SUP_APST			BIT7	//1b/x/x/x Set Automatic Partial to Slumber Transitions Function
    #define D15F0_SUP_NVMP			BIT6	//0/x/x/x Set NVMHCI Present Function
    #define D15F0_SUP_BOH			BIT5	//1b/x/x/x Set BIOS/OS Handoff Function
    #define D15F0_RD6B4			BIT4	//0/x/x/x Reserved
    #define D15F0_RD6B_3_0			0xF	//0/x/x/x Reserved
#define D15F0_AHCI_PMP_ERR_INTR_AND_ENCLOSURE_MANAGEMENT_OPTIONAL_REG		0xD7	//AHCI PMP_ERR Interrupt and Enclosure Management Optional Register
    #define D15F0_RD7B7			BIT7	//0/x/x/x Reserved
    #define D15F0_RD7B6			BIT6	//0/x/x/x Reserved
    #define D15F0_RD7B5			BIT5	//0/x/x/x Reserved
    #define D15F0_SUPP_LED_BD			BIT4	//1b/x/x/x Reserved
    #define D15F0_SUPP_SAFTE_BD			BIT3	//0/x/x/x Reserved
    #define D15F0_SUPP_SES2_BD			BIT2	//0/x/x/x Reserved
    #define D15F0_SUPP_SGPIO_BD			BIT1	//1b/x/x/x Reserved
    #define D15F0_PMPERR_ENN			BIT0	//0/x/x/x AHCI Portn PMP_ERR Interrupt (AHMMIOP1IS[23]) Guard Bit 
#define D15F0_SW_CTL_CI_SACT_ENTRY_RESET_TEST_MODE_ONLY_382_RX82		0xD8	//Software Control CI / SACT Entry Reset (Test Mode Only) ((382_Rx82))
    #define D15F0_SELCI_TAG			BIT7	//0/x/x/x Indicates Port CI[TAG number] to Be Cleared
    #define D15F0_SELSACT_TAG			BIT6	//0/x/x/x Indicates Port SACT[TAG number] to Be Cleared
    #define D15F0_SOFT_CLRTAG			BIT5	//0/x/x/x Trigger Port CI/SACT TAG Clear Operation
    #define D15F0_CLR_TAG_4_0			0x1F	//0/x/x/x TAG Number to Be Cleared
#define D15F0_SATA_SLAVE_TP_STA_TEST_MODE_ONLY		0xD9	//SATA Slave TP Status (Test Mode Only)
    #define D15F0_XSLV_FIS_NUM			0xFF	//0/R/x/x Parsing Port FIS Number When in Device Mode
#define D15F0_AHCI_PORT_IMPLEMENT_REGS		0xDA	//AHCI Port Implement Registers
    #define D15F0_RDAB7			BIT7	//0/x/x/x Reserved
    #define D15F0_RDAB6			BIT6	//0/x/x/x Reserved
    #define D15F0_RDAB5			BIT5	//0/x/x/x Reserved
    #define D15F0_RDAB4			BIT4	//0/x/x/x Reserved
    #define D15F0_RDAB3			BIT3	//0/x/x/x Reserved
    #define D15F0_RDAB2			BIT2	//0/x/x/x Reserved
    #define D15F0_RDAB1			BIT1	//0/x/x/x Reserved
    #define D15F0_PN_PORTIMP			BIT0	//1b/x/x/x Port n Implemented
#define D15F0_AHCI_OPTIONAL_REG_AND_DYNAMIC_CTL_REGS		0xDB	//AHCI Optional Register and Dynamic Control Registers
    #define D15F0_RDBB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SUP_PIOMDRQ			BIT6	//1b/1/x/x Set Multiple DRQ Block
    #define D15F0_SUP_MPS			BIT5	//1b/x/x/x Set Mechanical Presence Switch Function
    #define D15F0_SUP_SPINUP			BIT4	//1b/x/x/x Set AHCI Staggered Spin-up Function
    #define D15F0_RDBB3			BIT3	//0/x/x/x Reserved
    #define D15F0_RDBB2			BIT2	//0/x/x/x Reserved
    #define D15F0_MSICAPDIS			BIT1	//0/x/x/x AHCI MSI Capability Disable Control
    #define D15F0_SGPIO_INT_EN			BIT0	//0/x/x/x Reserved
#define D15F0_AHCI_DYNAMIC_CLK_CTL_REG_1		0xDC	//AHCI Dynamic CLK Control Register 1
    #define D15F0_RDCB7			BIT7	//0/x/x/x Reserved
    #define D15F0_RDCB6			BIT6	//0/x/x/x Reserved
    #define D15F0_RDCB5			BIT5	//0/x/x/x Reserved
    #define D15F0_RDCB4			BIT4	//0/x/x/x Reserved
    #define D15F0_RDCB3			BIT3	//0/x/x/x Reserved
    #define D15F0_RDCB2			BIT2	//0/x/x/x Reserved
    #define D15F0_RDCB1			BIT1	//0/x/x/x Reserved
    #define D15F0_EN_SATA_MPS_PN			BIT0	//0b/x/x/x SATA Port n MPS Enable
#define D15F0_AHCI_DYNAMIC_CLK_CTL_REG_2		0xDD	//AHCI Dynamic CLK Control Register 2
    #define D15F0_RDDB_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_AHN_GCKDYNEN			BIT3	//0/0/1/1 AHCI Port n Downstream GCLK Dynamic CLK Function Control
    #define D15F0_AHN_ECKDYNEN			BIT2	//0/0/1/1 AHCI Port n ECLK150 Dynamic CLK Function Control
    #define D15F0_AHN_TPECKDYNEN			BIT1	//0/0/1/1 AHCI Port n TPECLK Dynamic CLK Function Control
    #define D15F0_AHN_UPCLKDYNEN			BIT0	//0/0/1/1 AHCI Portn Upstream SAECLK Dynamic CLK Function Control
#define D15F0_AHCI_CACHE_BIST_CTL		0xDE	//AHCI Cache BIST Control
    #define D15F0_SUP_AHCISPD			0xF0	//0011b/x/x/x AHCI Port Speed Support
    #define D15F0_LAT_BIST_ERR			BIT3	//0/x/x/x AHCI Cache BIST Result
    #define D15F0_RDEB2			BIT2	//0/x/x/x Reserved
    #define D15F0_LAT_BIST_BSY			BIT1	//0/x/x/x AHCI Cache BIST Process
    #define D15F0_LAT_BIST_CYC			BIT0	//0/0/x/x AHCI Cache BIST function Set
#define D15F0_MSG_SIGNALED_INTR_IDENTIFIERS_MID		0xE0	//Message Signaled Interrupt Identifiers (MID)
    #define D15F0_MSI_NXT_IDE			0xFF00	//00h/x/x/x Reserved
    #define D15F0_MSIID_IDE			0xFF	//05h/x/x/x Reserved
#define D15F0_MSG_SIGNALED_INTR_MSG_CTL_MC		0xE2	//Message Signaled Interrupt Message Control (MC)
    #define D15F0_C64			BIT7	//0/x/x/x Reserved
    #define D15F0_MME			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define D15F0_MMC			(BIT1 + BIT2 + BIT3)	//0/x/x/x Reserved
    #define D15F0_MSIE			BIT0	//0/x/x/x Reserved
#define D15F0_MSG_SIGNALED_INTR_MSG_ADR		0xE4	//Message Signaled Interrupt Message Address
#define D15F0_MSG_SIGNALED_INTR_MSG_DATA		0xE8	//Message Signaled Interrupt Message Data
#define D15F0_AHCI_OPTIONAL_REG_0		0xEA	//AHCI Optional Register 0
    #define D15F0_REAB7			BIT7	//0/x/x/x Reserved
    #define D15F0_REAB6			BIT6	//0/x/x/x Reserved
    #define D15F0_REAB5			BIT5	//0/x/x/x Reserved
    #define D15F0_REAB4			BIT4	//0/x/x/x Reserved
    #define D15F0_REAB3			BIT3	//0/x/x/x Reserved
    #define D15F0_REAB2			BIT2	//0/x/x/x Reserved
    #define D15F0_REAB1			BIT1	//0/x/x/x Reserved
    #define D15F0_FBSDEV_SELN			BIT0	//0/x/x/x Config MPthod for AHCI Port n FBS Port Multiplier Port Value of the Next Command to Issue
#define D15F0_AHCI_FBS_OPTIONAL_REG_1		0xEB	//AHCI FBS Optional Register 1
    #define D15F0_REBB7			BIT7	//0/x/x/x Reserved
    #define D15F0_REBB6			BIT6	//0/x/x/x Reserved
    #define D15F0_TRG_SEL_DMA			BIT5	//0/x/x/x Allow for sending CFIS between DMA Data, such as between DMASETUP and DAMACTIVE
    #define D15F0_P2CRABT_INTEN			BIT4	//0/x/x/x P2C Read master abort PxIS.HBFS status assert enable
    #define D15F0_SUP_FBSADO			0xF	//0/x/x/x Set AHCI FBS Active Device Optimization
#define D15F0_SATA_BACK_OPTIONAL_REGS		0xEC	//SATA Back Optional Registers
    #define D15F0_RECB7			BIT7	//0/x/x/x Reserved
    #define D15F0_RECB6			BIT6	//0/x/x/x Reserved
    #define D15F0_RECB5			BIT5	//0/x/x/x Reserved
    #define D15F0_RECB4			BIT4	//0/x/x/x Reserved
    #define D15F0_RECB3			BIT3	//0/x/x/x Reserved
    #define D15F0_RECB2			BIT2	//0/x/x/x Reserved
    #define D15F0_RECB1			BIT1	//0/x/x/x Reserved
    #define D15F0_PMACKIND3_ONLY			BIT0	//0/x/x/x S3/S4 state Acknowledge in D3 State only
#define D15F0_SID_DEV_FUN		0xEE	//SID_DEV_FUN
    #define D15F0_DEVNUM			0xF8	//01111b/x/x/x SID: DEVNUM
    #define D15F0_FUNNUM			(BIT0 + BIT1 + BIT2)	//000b/0/x/x SID : FUNNUM
#define D15F0_SID_DEV_FUN_Z1		0xEF	//SID_DEV_FUN
    #define D15F0_BUSNUM			0xFF	//0/x/x/x SID: BUSNUM
#define D15F0_SATA_CAP_REG_0_SATACR0		0xF0	//SATA Capability Register 0 ((SATACR0))
    #define D15F0_MAJREV			0xF00000	//1h/R/x/x Major Revision
    #define D15F0_MINREV			0xF0000	//0/R/x/x Minor Revision
    #define D15F0_NEXT			0xFF00	//0/R/x/x Next Capability
    #define D15F0_SATACID			0xFF	//12h/R/x/x Capability ID
#define D15F0_SATA_CAP_REG_1_SATACR1		0xF4	//SATA Capability Register 1 ((SATACR1))
    #define D15F0_BAROFST			0xFFF0	//004h/R/x/x BAR Offset
    #define D15F0_BARLOC			0xF	//8h/R/x/x BAR Location
#define D15F0_AHCI_PORT_HOTPLUG_OPTIONAL_REGS		0xF8	//AHCI Port Hotplug Optional Registers
    #define D15F0_SUP_SLPSLUM			BIT7	//0/x/x/x Device Sleep Can Be Triggerd Only during Slumber Power State
    #define D15F0_SUP_AGRSLP			BIT6	//0/x/x/x Aggressive Device Sleep Support
    #define D15F0_SUP_DEVSLP			BIT5	//1b/x/x/x Device Sleep Support
    #define D15F0_RESERVED_Z6			0x1E	//0/x/x/x Reserved
    #define D15F0_PN_HPLUG_CAP			BIT0	//1b/x/x/x Hot Plug Capable Port
#define D15F0_AHCI_GHC_CAP_OPTIONAL_REG_0		0xF9	//AHCI GHC CAP Optional Register 0
    #define D15F0_SUP_64ADR			BIT7	//1b/x/x/x Set 64-bit Addressing
    #define D15F0_SUP_CMDQ			BIT6	//1b/x/x/x Set Native Command Queuing
    #define D15F0_SUP_SNTF			BIT5	//1b/x/x/x Set SNotification Register
    #define D15F0_SUP_LKPWR			BIT4	//1b/x/x/x Set Aggressive Link Power Management
    #define D15F0_SUP_LED			BIT3	//1b/x/x/x Set Activity LED
    #define D15F0_SUP_RSTBD			BIT2	//1b/x/x/x Set Command List Override
    #define D15F0_SUP_AHCIONLY			BIT1	//0/x/x/x Set AHCI Mode Only
    #define D15F0_SUP_PMP			BIT0	//0/x/x/x Set Port Multiplier
#define D15F0_AHCI_GHC_CAP_BACK_OPTIONAL_REG_1		0xFA	//AHCI GHC CAP Back Optional Register 1
    #define D15F0_SUP_FBSS			BIT7	//0b/x/x/x Set  FIS-based Switching Function
    #define D15F0_SUP_SLUM			BIT6	//1b/x/x/x Set Slumber State Capable
    #define D15F0_SUP_PART			BIT5	//1b/x/x/x Set Partial State Capable
    #define D15F0_SUP_CCCS			BIT4	//1b/x/x/x Set Command Completion Coalescing Function
    #define D15F0_SUP_EMS			BIT3	//1b/x/x/x Set Enclosure Management Function
    #define D15F0_SUP_SXS			BIT2	//1b/x/x/x Set External SATA Function
    #define D15F0_SUP_CMDSLOTS			(BIT0 + BIT1)	//11b/x/x/x Set Number of Command Slots Supported
#define D15F0_AHCI_GHC_CAP_AND_PORT_OPTIONAL_REG_2		0xFB	//AHCI GHC CAP and Port Optional Register 2
    #define D15F0_RFCB_7_6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_OFS_DIS			BIT5	//0/x/x/x AHCI Overflow status (PxIS.OFS) Option Bit
    #define D15F0_AHN_ESP_EN			BIT4	//0/x/x/x Set AHCI Port n Extenal SATA Port Function
    #define D15F0_SUP_PORTSNUM			0xF	//1h/x/x/x Set Number of Ports Supported
#define D15F0_AHCI_GHC_CAP_AND_PORT_OPTIONAL_REG_3		0xFC	//AHCI GHC CAP and Port Optional Register 3
    #define D15F0_RFDB_7_4			0xF0	//0/x/x/x Reserved
    #define D15F0_AHN_SET_SLPDM			0xF	//0/x/x/x Device Sleep Idle Timeout (DITO) Multiplier for AHCI Port n
#define D15F0_AHCI_GHC_CAP_AND_PORT_OPTIONAL_REG_4		0xFD	//AHCI GHC CAP and Port Optional Register 4
    #define D15F0_RFEB7			BIT7	//0/x/x/x Reserved
    #define D15F0_RFEB6			BIT6	//0/x/x/x Reserved
    #define D15F0_RFEB5			BIT5	//0/x/x/x Reserved
    #define D15F0_RFEB4			BIT4	//0/x/x/x Reserved
    #define D15F0_RFEB3			BIT3	//0/x/x/x Reserved
    #define D15F0_RFEB2			BIT2	//0/x/x/x Reserved
    #define D15F0_RFEB1			BIT1	//0/x/x/x Reserved
    #define D15F0_AH_SLP_EN			BIT0	//0/x/x/x AHCI Portn  Device Sleep Enable
#define D15F0_SIMULATION_SPEED_UP_CTL		0xFE	//Simulation speed up control
    #define D15F0_RFFB7			BIT7	//0/x/x/x Reserved
    #define D15F0_RFFB6			BIT6	//0/x/x/x Reserved
    #define D15F0_ASYNSPD			BIT5	//0/x/x/x Async Recovery Timer clock speed up control for simulation
    #define D15F0_SPDUPG2TG1			BIT4	//0/x/x/x OOB sequence and speed negotiation speed up control for simulation
    #define D15F0_TRDYSPDUP			BIT3	//0/x/x/x Reserved
    #define D15F0_INITSPDUP			BIT2	//0/x/x/x EPHY Bandgap, Reference clock, MPLL, TPLL and RTN initial sequence speed up for simulation
    #define D15F0_AHSIM_ACC			BIT1	//0/x/x/x AHCI CCC timer and DEVSLP timer acceleration for simulation
    #define D15F0_FASTDBNC			BIT0	//0/x/x/x Fast Debounce control for simulation
#define D15F0_EPHY_DE_GLITCH_FUN_CTL		0xFF	//EPHY De-glitch function control
    #define D15F0_RXEIDLE_FILTER_EN			BIT7	//0/x/x/x Enable RX EIDLE signal filter function
    #define D15F0_RXEIDLE_ADDPULSE_EN			BIT6	//0/x/x/x Host Add pulse in RXEIDLESQDET during speed negotiation at the time device change speed
    #define D15F0_RXEIDLE_ERRCHK_EN			BIT5	//0/x/x/x RXEIDLESQDET de-glitch function using Decode/Disparity Error check method enable
    #define D15F0_RXEIDLE_ERRCHK_TH			(BIT3 + BIT4)	//10b/x/x/x Decode/Disparity Error threshold
    #define D15F0_RXEIDLE_ALIGNCHK_EN			BIT2	//0/x/x/x RXEIDLESQDET de-glitch function using ALIGNp check method enable
    #define D15F0_RXEIDLE_ALIGNCHK_TH			(BIT0 + BIT1)	//01b/x/x/x ALIGNp Check Time-out value
//D15F0 SATA EPHY INDEX-DATA
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL		0x0001	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_RCVDETN_PHYB			BIT7	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_RCVDETP_PHYB			BIT6	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_RCVDETN_PHYB			BIT5	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_RCVDETP_PHYB			BIT4	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_RCVDETN_PHYB			BIT3	//0/x/x/x Port 1 Receiver Detection Flag at TX-
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_RCVDETP_PHYB			BIT2	//0/x/x/x Port 1 Receiver Detection Flag at TX+ 
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_RCVDETN_PHYB			BIT1	//0/x/x/x Port 0 Receiver Detection Flag at TX-
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_RCVDETP_PHYB			BIT0	//0/x/x/x Port 0 Receiver Detection Flag at TX+ 
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z1		0x0002	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_RCVDET_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_RCVDET_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_RCVDET_PHYB			BIT1	//0/x/x/x PCIe Mode:
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_RCVDET_PHYB			BIT0	//0/x/x/x PCIe Mode:
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z2		0x0003	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R003B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TXPWRSETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TXPWRSETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXPWRSETEN_PHYB			BIT1	//0/x/x/x Port 1 TX Power Status Manual Setting Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXPWRSETEN_PHYB			BIT0	//0/x/x/x Port 0 TX Power Status Manual Setting Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z3		0x0004	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXPWRSET_PHYB			0xF0	//0/x/x/x Port 1 TX Power Status Register Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXPWRSET_PHYB			0xF	//0/x/x/x Port 0 TX Power Status Register Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED		0x0005	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TXPWRSET_PHYB			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TXPWRSET_PHYB			0xF	//0/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z4		0x0006	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R006B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TXEIDLESETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TXEIDLESETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXEIDLESETEN_PHYB			BIT1	//0/x/x/x Port 1 TX Electrical Idle Register Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXEIDLESETEN_PHYB			BIT0	//0/x/x/x Port 0 TX Electrical Idle Register Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z5		0x0007	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R007B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TXEIDLESETB_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TXEIDLESETB_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXEIDLESETB_PHYB			BIT1	//0/x/x/x Port 1 TX Electrical Idle Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXEIDLESETB_PHYB			BIT0	//0/x/x/x Port 0 TX Electrical Idle Control
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z6		0x0008	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R008B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_SPEEDSET_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x Port 1 Speed Manual Setting Register
    #define D15F0_SATA_EPHY_INDEXDATA_R008B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_SPEEDSET_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x Port 0 Speed Manual Setting Register
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z1		0x0009	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R009B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_SPEEDSET_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R009B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_SPEEDSET_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z7		0x000A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R00AB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_SPEEDSETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_SPEEDSETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_SPEEDSETEN_PHYB			BIT1	//0/x/x/x Port 1 Speed Manual Setting Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_SPEEDSETEN_PHYB			BIT0	//0/x/x/x Port 0 Speed Manual Setting Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z8		0x000B	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R00BB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_SATA_TXSET_EN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_SATA_TXSET_EN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_SATA_TXSET_EN_PHYB			BIT1	//0/x/x/x Port 1 SATA TX Swing Manual Setting Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_SATA_TXSET_EN_PHYB			BIT0	//0/x/x/x Port 0 SATA TX Swing Manual Setting Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z9		0x000C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_SATA_TXSET_PHYB			(BIT6 + BIT7)	//0/x/x/x Port 0 SATA TX Swing Manual Setting
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_SATA_TXSET_PHYB			(BIT4 + BIT5)	//0/x/x/x Port 0 SATA TX Swing Manual Setting
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_SATA_TXSET_PHYB			(BIT2 + BIT3)	//0/x/x/x Port 0 SATA TX Swing Manual Setting
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_SATA_TXSET_PHYB			(BIT0 + BIT1)	//0/x/x/x Port 0 SATA TX Swing Manual Setting
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z10		0x000D	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R00DB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_EIDLESQSDET_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_EIDLESQSDET_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_EIDLESQSDET_PHYB			BIT1	//0/x/x/x Port 1 EIDLE/Squelch Detection Flag
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_EIDLESQSDET_PHYB			BIT0	//0/x/x/x Port 0 EIDLE/Squelch Detection Flag
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z11		0x000E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R00EB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_EIDLESQBW_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_EIDLESQBW_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_EIDLESQBW_PHYB			BIT1	//0/x/x/x Port 1 EIDLE/Squelch Detection Mode Select
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_EIDLESQBW_PHYB			BIT0	//0/x/x/x Port 0 EIDLE/Squelch Detection Mode Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z12		0x000F	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R00FB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_EIDLESQTH_PHYB			(BIT4 + BIT5 + BIT6)	//010b/x/x/x Port 1 EIDLE Detection Threshold
    #define D15F0_SATA_EPHY_INDEXDATA_R00FB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_EIDLESQTH_PHYB			(BIT0 + BIT1 + BIT2)	//010b/x/x/x Port 0 EIDLE Detection Threshold
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z13		0x0010	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R010B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_EIDLESQTH_PHYB			(BIT4 + BIT5 + BIT6)	//010b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R010B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_EIDLESQTH_PHYB			(BIT0 + BIT1 + BIT2)	//010b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z14		0x0011	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R011B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_RXPWRSETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_RXPWRSETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RXPWRSETEN_PHYB			BIT1	//0/x/x/x Port 1 RX Power Status Setting Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RXPWRSETEN_PHYB			BIT0	//0/x/x/x Port 0 RX Power Status Setting Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z15		0x0012	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_RXPWRSET_PHYB			(BIT6 + BIT7)	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_RXPWRSET_PHYB			(BIT4 + BIT5)	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RXPWRSET_PHYB			(BIT2 + BIT3)	//0/x/x/x Port 1 RX Power Status Setting
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RXPWRSET_PHYB			(BIT0 + BIT1)	//0/x/x/x Port 0 RX Power Status Setting
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z16		0x0013	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R013B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP03_TRINLPBK_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP02_TRINLPBK_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_TRINLPBK_PHYB			BIT1	//0/x/x/x Port 1 Enable Internal Loop Back from PISO to PD
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_TRINLPBK_PHYB			BIT0	//0/x/x/x Port 0 Enable Internal Loop Back from PISO to PD
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z17		0x0014	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R014B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP03_RTINLPBK_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP02_RTINLPBK_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_RTINLPBK_PHYB			BIT1	//0/x/x/x Port 1 Enable Internal Loop back from RCV to DT Driver
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_RTINLPBK_PHYB			BIT0	//0/x/x/x Port 0 Enable Internal Loop back from RCV to DT Driver
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z18		0x0015	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R015B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCV_HBW_G1_PHYB			(BIT4 + BIT5 + BIT6)	//111b/x/x/x Port 1 Gen1 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define D15F0_SATA_EPHY_INDEXDATA_R015B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCV_HBW_G1_PHYB			(BIT0 + BIT1 + BIT2)	//111b/x/x/x Port 0 Gen1 for RCV HBW Option for VGA/BUF/VGA_BUF
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z2		0x0016	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R016B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_RCV_HBW_G1_PHYB			(BIT4 + BIT5 + BIT6)	//111b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R016B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_RCV_HBW_G1_PHYB			(BIT0 + BIT1 + BIT2)	//111b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z19		0x0017	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R017B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCV_HBW_G2_PHYB			(BIT4 + BIT5 + BIT6)	//111b/x/x/x Port 1 Gen2 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define D15F0_SATA_EPHY_INDEXDATA_R017B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCV_HBW_G2_PHYB			(BIT0 + BIT1 + BIT2)	//111b/x/x/x Port 0 Gen2 for RCV HBW Option for VGA/BUF/VGA_BUF
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z3		0x0018	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R018B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_RCV_HBW_G2_PHYB			(BIT4 + BIT5 + BIT6)	//111b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R018B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_RCV_HBW_G2_PHYB			(BIT0 + BIT1 + BIT2)	//111b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z20		0x0019	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R019B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCV_HBW_G3_PHYB			(BIT4 + BIT5 + BIT6)	//111b/x/x/x Port 1 Gen3 for RCV HBW Option for VGA/BUF/VGA_BUF
    #define D15F0_SATA_EPHY_INDEXDATA_R019B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCV_HBW_G3_PHYB			(BIT0 + BIT1 + BIT2)	//111b/x/x/x Port 0 Gen3 for RCV HBW Option for VGA/BUF/VGA_BUF
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z4		0x001A	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R01AB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_RCV_HBW_G3_PHYB			(BIT4 + BIT5 + BIT6)	//111b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R01AB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_RCV_HBW_G3_PHYB			(BIT0 + BIT1 + BIT2)	//111b/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z21		0x001B	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TX_DUTY_PHYB			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TX_DUTY_PHYB			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TX_DUTY_PHYB			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TX_DUTY_PHYB			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z22		0x001C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXPSR_PHYB			(BIT5 + BIT6 + BIT7)	//011b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TDCIS_PHYB			0x1F	//11101b/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z23		0x001D	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXPSR_PHYB			(BIT5 + BIT6 + BIT7)	//011b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TDCIS_PHYB			0x1F	//11101b/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z5		0x001E	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TXPSR_PHYB			(BIT5 + BIT6 + BIT7)	//011b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TDCIS_PHYB			0x1F	//11101b/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z6		0x001F	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TXPSR_PHYB			(BIT5 + BIT6 + BIT7)	//011b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TDCIS_PHYB			0x1F	//11101b/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z24		0x0021	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R021B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_RCVTHSEL_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_RCVTHSEL_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_RCVTHSEL_PHYB			BIT1	//0/x/x/x Port 1 RCV VGA Gain Range Selection
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_RCVTHSEL_PHYB			BIT0	//0/x/x/x Port 0 RCV VGA Gain Range Selection
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z25		0x0022	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R022B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RXCLKSEL_PHYB			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Port 0 Rise Edge of RXCLK Select
    #define D15F0_SATA_EPHY_INDEXDATA_R022B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RXCLKSEL_PHYB			(BIT0 + BIT1 + BIT2)	//000b/x/x/x Port 0 Rise Edge of RXCLK Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z7		0x0023	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R023B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_RXCLKSEL_PHYB			(BIT4 + BIT5 + BIT6)	//000b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R023B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_RXCLKSEL_PHYB			(BIT0 + BIT1 + BIT2)	//000b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z26		0x0024	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R024B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_IVCPSEL_PHYB			(BIT4 + BIT5 + BIT6)	//0/x/x/x Port 1 IV Gain Select
    #define D15F0_SATA_EPHY_INDEXDATA_R024B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_IVCPSEL_PHYB			(BIT0 + BIT1 + BIT2)	//0/x/x/x Port 0 IV Gain Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z8		0x0025	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R025B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_IVCPSEL_PHYB			(BIT4 + BIT5 + BIT6)	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R025B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_IVCPSEL_PHYB			(BIT0 + BIT1 + BIT2)	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z27		0x0026	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R026B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_VCOPDSEL_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_VCOPDSEL_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_VCOPDSEL_PHYB			BIT1	//0/x/x/x Port 1 VCO Power off Method at P1
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_VCOPDSEL_PHYB			BIT0	//0/x/x/x Port 0 VCO Power off Method at P1
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z28		0x0027	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R027B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_RCVPDSEL_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_RCVPDSEL_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_RCVPDSEL_PHYB			BIT1	//0/x/x/x Port 1 RCV Power off Method
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_RCVPDSEL_PHYB			BIT0	//0/x/x/x Port 0 RCV Power off Method
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z29		0x0028	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R028B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_CDR_UGB_HBW_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_CDR_UGB_HBW_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_CDR_UGB_HBW_PHYB			BIT1	//0/x/x/x Port 1 CDR Loop Filter Buffer Bandwidth
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_CDR_UGB_HBW_PHYB			BIT0	//0/x/x/x Port 0 CDR Loop Filter Buffer Bandwidth
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z30		0x0029	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R029B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_CDR_VT_SW_PHYB			BIT3	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_CDR_VT_SW_PHYB			BIT2	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_CDR_VT_SW_PHYB			BIT1	//1b/x/x/x Port 1 CDR IV Control Source Select
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_CDR_VT_SW_PHYB			BIT0	//1b/x/x/x Port 0 CDR IV Control Source Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z31		0x002A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R02AB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_FDRATIO_G1_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen1 FD Mode Ratio during P1 to P0
    #define D15F0_SATA_EPHY_INDEXDATA_R02AB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_FDRATIO_G1_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen1 FD Mode Ratio during P1 to P0
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z9		0x002B	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R02BB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_FDRATIO_G1_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R02BB3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_FDRATIO_G1_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z32		0x002C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R02CB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_FDRATIO_G2_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen2 FD Mode Ratio during P1 to P0
    #define D15F0_SATA_EPHY_INDEXDATA_R02CB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_FDRATIO_G2_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen2 FD Mode Ratio during P1 to P0
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z10		0x002D	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R02DB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_FDRATIO_G2_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R02DB3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_FDRATIO_G2_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z33		0x002E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R02EB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_FDRATIO_G3_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen3 FD Mode Ratio during P1 to P0
    #define D15F0_SATA_EPHY_INDEXDATA_R02EB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_FDRATIO_G3_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen3 FD Mode Ratio during P1 to P0
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z11		0x002F	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R02FB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_FDRATIO_G3_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R02FB3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_FDRATIO_G3_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z34		0x0030	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R030B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_FTSRATIO_G1_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x Port 1 Gen1 PD Training Mode Ratio during P0s to P0
    #define D15F0_SATA_EPHY_INDEXDATA_R030B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_FTSRATIO_G1_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x Port 0 Gen1 PD Training Mode Ratio during P0s to P0
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z12		0x0031	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R031B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_FTSRATIO_G1_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x Port 1 Gen1 PD Training Mode Ratio during P0s to P0
    #define D15F0_SATA_EPHY_INDEXDATA_R031B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_FTSRATIO_G1_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x Port 0 Gen1 PD Training Mode Ratio during P0s to P0
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z35		0x0032	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R032B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_FTSRATIO_G2_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x Port 1 Gen2 PD Training Mode Ratio during P0s to P0
    #define D15F0_SATA_EPHY_INDEXDATA_R032B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_FTSRATIO_G2_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x Port 0 Gen2 PD Training Mode Ratio during P0s to P0
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z13		0x0033	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R033B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_FTSRATIO_G2_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x Port 1 Gen2 PD Training Mode Ratio during P0s to P0
    #define D15F0_SATA_EPHY_INDEXDATA_R033B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_FTSRATIO_G2_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x Port 0 Gen2 PD Training Mode Ratio during P0s to P0
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z36		0x0034	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R034B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_FTSRATIO_G3_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x Port 1 Gen3 PD Training Mode Ratio during P0s to P0
    #define D15F0_SATA_EPHY_INDEXDATA_R034B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_FTSRATIO_G3_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x Port 0 Gen3 PD Training Mode Ratio during P0s to P0
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z14		0x0035	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R035B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_FTSRATIO_G3_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R035B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_FTSRATIO_G3_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z37		0x0036	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R036B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_P1EXT_G1_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen1 ExitLatency P1 Exit Latency
    #define D15F0_SATA_EPHY_INDEXDATA_R036B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_P1EXT_G1_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen1 ExitLatency P1 Exit Latency
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z15		0x0037	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R037B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_P1EXT_G1_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R037B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_P1EXT_G1_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z38		0x0038	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R038B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_P1EXT_G2_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen2 ExitLatency P1 Exit Latency
    #define D15F0_SATA_EPHY_INDEXDATA_R038B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_P1EXT_G2_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen2 ExitLatency P1 Exit Latency
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z16		0x0039	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R039B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_P1EXT_G2_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R039B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_P1EXT_G2_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z39		0x003A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R03AB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_P1EXT_G3_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen3 ExitLatency P1 Exit Latency
    #define D15F0_SATA_EPHY_INDEXDATA_R03AB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_P1EXT_G3_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen3 ExitLatency P1 Exit Latency
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z17		0x003B	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R03BB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_P1EXT_G3_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R03BB3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_P1EXT_G3_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z40		0x003C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R03CB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_P0SP2EXT_G1_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen1 ExitLatency P1 Exit Latency
    #define D15F0_SATA_EPHY_INDEXDATA_R03CB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_P0SP2EXT_G1_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen1 ExitLatency P1 Exit Latency
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z18		0x003D	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R03DB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_P0SP2EXT_G1_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R03DB3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_P0SP2EXT_G1_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z41		0x003E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R03EB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_P0SP2EXT_G2_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen2 ExitLatency P1 Exit Latency
    #define D15F0_SATA_EPHY_INDEXDATA_R03EB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_P0SP2EXT_G2_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen2 ExitLatency P1 Exit Latency
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z19		0x003F	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R03FB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_P0SP2EXT_G2_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen2 ExitLatency P1 Exit Latency
    #define D15F0_SATA_EPHY_INDEXDATA_R03FB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_P0SP2EXT_G2_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen2 ExitLatency P1 Exit Latency
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z42		0x0040	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R040B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_P0SP2EXT_G3_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 Gen3 ExitLatency P1 Exit Latency
    #define D15F0_SATA_EPHY_INDEXDATA_R040B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_P0SP2EXT_G3_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 Gen3 ExitLatency P1 Exit Latency
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z20		0x0041	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R041B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_P0SP2EXT_G3_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R041B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_P0SP2EXT_G3_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z43		0x0042	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NIPRSEL_G1_PHYB			(BIT6 + BIT7)	//11b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NIPRSEL_G1_PHYB			(BIT4 + BIT5)	//11b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NIPRSEL_G1_PHYB			(BIT2 + BIT3)	//11b/x/x/x Port 1 Gen1 Gain1 during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NIPRSEL_G1_PHYB			(BIT0 + BIT1)	//11b/x/x/x Port 0 Gen1 Gain1 during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z44		0x0043	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NIPRSEL_G2_PHYB			(BIT6 + BIT7)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NIPRSEL_G2_PHYB			(BIT4 + BIT5)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NIPRSEL_G2_PHYB			(BIT2 + BIT3)	//10b/x/x/x Port 1 Gen2 Gain1 during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NIPRSEL_G2_PHYB			(BIT0 + BIT1)	//10b/x/x/x Port 0 Gen2 Gain1 during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z45		0x0044	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NIPRSEL_G3_PHYB			(BIT6 + BIT7)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NIPRSEL_G3_PHYB			(BIT4 + BIT5)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NIPRSEL_G3_PHYB			(BIT2 + BIT3)	//10b/x/x/x Port 1 Gen3 Gain1 during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NIPRSEL_G3_PHYB			(BIT0 + BIT1)	//10b/x/x/x Port 0 Gen3 Gain1 during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z46		0x0045	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KIPRSEL_G1_PHYB			(BIT6 + BIT7)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KIPRSEL_G1_PHYB			(BIT4 + BIT5)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KIPRSEL_G1_PHYB			(BIT2 + BIT3)	//10b/x/x/x Port 1 Gen1 Gain1 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KIPRSEL_G1_PHYB			(BIT0 + BIT1)	//10b/x/x/x Port 0 Gen1 Gain1 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z47		0x0046	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KIPRSEL_G2_PHYB			(BIT6 + BIT7)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KIPRSEL_G2_PHYB			(BIT4 + BIT5)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KIPRSEL_G2_PHYB			(BIT2 + BIT3)	//01b/x/x/x Port 1 Gen2 Gain1 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KIPRSEL_G2_PHYB			(BIT0 + BIT1)	//01b/x/x/x Port 0 Gen2 Gain1 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z48		0x0047	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KIPRSEL_G3_PHYB			(BIT6 + BIT7)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KIPRSEL_G3_PHYB			(BIT4 + BIT5)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KIPRSEL_G3_PHYB			(BIT2 + BIT3)	//01b/x/x/x Port 1 Gen3 Gain1 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KIPRSEL_G3_PHYB			(BIT0 + BIT1)	//01b/x/x/x Port 0 Gen3 Gain1 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z49		0x0048	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NIPCSEL_G1_PHYB			(BIT6 + BIT7)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NIPCSEL_G1_PHYB			(BIT4 + BIT5)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NIPCSEL_G1_PHYB			(BIT2 + BIT3)	//01b/x/x/x Port 1 Gen1 Gain2 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NIPCSEL_G1_PHYB			(BIT0 + BIT1)	//01b/x/x/x Port 0 Gen1 Gain2 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z50		0x0049	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NIPCSEL_G2_PHYB			(BIT6 + BIT7)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NIPCSEL_G2_PHYB			(BIT4 + BIT5)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NIPCSEL_G2_PHYB			(BIT2 + BIT3)	//01b/x/x/x Port 1 Gen2 Gain2 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NIPCSEL_G2_PHYB			(BIT0 + BIT1)	//01b/x/x/x Port 0 Gen2 Gain2 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z51		0x004A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NIPCSEL_G3_PHYB			(BIT6 + BIT7)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NIPCSEL_G3_PHYB			(BIT4 + BIT5)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NIPCSEL_G3_PHYB			(BIT2 + BIT3)	//01b/x/x/x Port 1 Gen3 Gain2 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NIPCSEL_G3_PHYB			(BIT0 + BIT1)	//01b/x/x/x Port 0 G3 for Gain2 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z52		0x004B	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KIPCSEL_G1_PHYB			(BIT6 + BIT7)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KIPCSEL_G1_PHYB			(BIT4 + BIT5)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KIPCSEL_G1_PHYB			(BIT2 + BIT3)	//00b/x/x/x Port 1 Gen1 Gain2 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KIPCSEL_G1_PHYB			(BIT0 + BIT1)	//00b/x/x/x Port 0 Gen1 Gain2 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z53		0x004C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KIPCSEL_G2_PHYB			(BIT6 + BIT7)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KIPCSEL_G2_PHYB			(BIT4 + BIT5)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KIPCSEL_G2_PHYB			(BIT2 + BIT3)	//00b/x/x/x Port 1 Gen2 Gain2 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KIPCSEL_G2_PHYB			(BIT0 + BIT1)	//00b/x/x/x Port 0 Gen2 Gain2 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z54		0x004D	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KIPCSEL_G3_PHYB			(BIT6 + BIT7)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KIPCSEL_G3_PHYB			(BIT4 + BIT5)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KIPCSEL_G3_PHYB			(BIT2 + BIT3)	//00b/x/x/x Port 1 Gen3 Gain2 during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KIPCSEL_G3_PHYB			(BIT0 + BIT1)	//00b/x/x/x Port 0 Gen3 Gain2 during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z55		0x004E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R04EB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NTSEL_G1_PHYB			BIT6	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R04EB5			BIT5	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NTSEL_G1_PHYB			BIT4	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R04EB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NTSEL_G1_PHYB			BIT2	//1b/x/x/x Port 1 Gen1 Updatetime during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_R04EB1			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NTSEL_G1_PHYB			BIT0	//1b/x/x/x Port 0 Gen1 Updatetime during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z56		0x004F	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R04FB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NTSEL_G2_PHYB			BIT6	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R04FB5			BIT5	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NTSEL_G2_PHYB			BIT4	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R04FB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NTSEL_G2_PHYB			BIT2	//1b/x/x/x Port 1 Gen2 Updatetime during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_R04FB1			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NTSEL_G2_PHYB			BIT0	//1b/x/x/x Port 0 Gen2 Updatetime during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z57		0x0050	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R050B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NTSEL_G3_PHYB			BIT6	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R050B5			BIT5	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NTSEL_G3_PHYB			BIT4	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R050B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NTSEL_G3_PHYB			BIT2	//1b/x/x/x Port 1 Gen3 Updatetime during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_R050B1			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NTSEL_G3_PHYB			BIT0	//1b/x/x/x Port 0 Gen3 Updatetime during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z58		0x0051	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R051B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KTSEL_G1_PHYB			BIT6	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R051B5			BIT5	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KTSEL_G1_PHYB			BIT4	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R051B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KTSEL_G1_PHYB			BIT2	//0b/x/x/x Port 1 Gen1 Updatetime during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_R051B1			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KTSEL_G1_PHYB			BIT0	//0b/x/x/x Port 0 Gen1 Updatetime during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z59		0x0052	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R052B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KTSEL_G2_PHYB			BIT6	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R052B5			BIT5	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KTSEL_G2_PHYB			BIT4	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R052B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KTSEL_G2_PHYB			BIT2	//0b/x/x/x Port 1 Gen2 Updatetime during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_R052B1			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KTSEL_G2_PHYB			BIT0	//0b/x/x/x Port 0 Gen2 Updatetime during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z60		0x0053	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R053B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KTSEL_G3_PHYB			BIT6	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R053B5			BIT5	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KTSEL_G3_PHYB			BIT4	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R053B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KTSEL_G3_PHYB			BIT2	//0b/x/x/x Port 1 Gen3 Updatetime during Tracking Mode
    #define D15F0_SATA_EPHY_INDEXDATA_R053B1			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KTSEL_G3_PHYB			BIT0	//0b/x/x/x Port 0 Gen3 Updatetime during Tracking Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z61		0x0054	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NLFSEL_G1_PHYB			(BIT6 + BIT7)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NLFSEL_G1_PHYB			(BIT4 + BIT5)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NLFSEL_G1_PHYB			(BIT2 + BIT3)	//01b/x/x/x Port 1 Gen1 LF Select during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NLFSEL_G1_PHYB			(BIT0 + BIT1)	//01b/x/x/x Port 0 Gen1 LF Select during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z62		0x0055	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NLFSEL_G2_PHYB			(BIT6 + BIT7)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NLFSEL_G2_PHYB			(BIT4 + BIT5)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NLFSEL_G2_PHYB			(BIT2 + BIT3)	//01b/x/x/x Port 1 Gen2 LF Select during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NLFSEL_G2_PHYB			(BIT0 + BIT1)	//01b/x/x/x Port 0 Gen2 LF Select during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z63		0x0056	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_NLFSEL_G3_PHYB			(BIT6 + BIT7)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_NLFSEL_G3_PHYB			(BIT4 + BIT5)	//01b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_NLFSEL_G3_PHYB			(BIT2 + BIT3)	//01b/x/x/x Port 1 Gen3 LF Select during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_NLFSEL_G3_PHYB			(BIT0 + BIT1)	//01b/x/x/x Port 0 Gen3 LF Select during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z64		0x0057	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KLFSEL_G1_PHYB			(BIT6 + BIT7)	//11b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KLFSEL_G1_PHYB			(BIT4 + BIT5)	//11b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KLFSEL_G1_PHYB			(BIT2 + BIT3)	//11b/x/x/x Port 1 Gen1 LF Select during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KLFSEL_G1_PHYB			(BIT0 + BIT1)	//11b/x/x/x Port 0 Gen1 LF select during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z65		0x0058	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KLFSEL_G2_PHYB			(BIT6 + BIT7)	//11b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KLFSEL_G2_PHYB			(BIT4 + BIT5)	//11b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KLFSEL_G2_PHYB			(BIT2 + BIT3)	//11b/x/x/x Port 1 Gen2 LF Select during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KLFSEL_G2_PHYB			(BIT0 + BIT1)	//11b/x/x/x Port 0 Gen2 LF Select during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z66		0x0059	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_KLFSEL_G3_PHYB			(BIT6 + BIT7)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_KLFSEL_G3_PHYB			(BIT4 + BIT5)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_KLFSEL_G3_PHYB			(BIT2 + BIT3)	//10b/x/x/x Port 1 Gen3 LF Select during Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_KLFSEL_G3_PHYB			(BIT0 + BIT1)	//10b/x/x/x Port 0 Gen3 LF Select during Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z67		0x005C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R05DB7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNMODE_G1_PHYB			0xFFF	//0/x/x/x Port 0 Gen1 Equalizer Tuning Mode Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z68		0x005E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R05FB7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNMODE_G1_PHYB			0xFFF	//0/x/x/x Port 1 Gen1 Equalizer Tuning Mode Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z21		0x0060	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R061B7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNMODE_G1_PHYB			0xFFF	//0h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z22		0x0062	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R063B7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNMODE_G1_PHYB			0xFFF	//0h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z69		0x0064	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R065B7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNMODE_G2_PHYB			0xFFF	//0/x/x/x Port 0 Gen2 Equalizer Tuning Mode Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z70		0x0066	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R067B7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNMODE_G2_PHYB			0xFFF	//0/x/x/x Port 1 Gen2 Equalizer Tuning Mode Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z23		0x0068	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R069B7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNMODE_G2_PHYB			0xFFF	//0/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z24		0x006A	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R06BB7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNMODE_G2_PHYB			0xFFF	//0/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z71		0x006C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R06DB7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNMODE_G3_PHYB			0xFFF	//0/x/x/x Port 0 Gen3 Equalizer Tuning Mode Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z72		0x006E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R06FB7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNMODE_G3_PHYB			0xFFF	//0/x/x/x Port 1 Gen3 Equalizer Tuning Mode Select
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z25		0x0070	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R071B7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNMODE_G3_PHYB			0xFFF	//0/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z26		0x0072	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R073B7_B4			0xF000	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNMODE_G3_PHYB			0xFFF	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z73		0x0074	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDCBW_G1_PHYB			0xF0	//1h/x/x/x Port 1 Gen1 LEQ DC Gain Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDCBW_G1_PHYB			0xF	//1h/x/x/x Port 0 Gen1 LEQ DC Gain Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z27		0x0075	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDCBW_G1_PHYB			0xF0	//1h/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDCBW_G1_PHYB			0xF	//1h/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z74		0x0076	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDCBW_G2_PHYB			0xF0	//1h/x/x/x Port 1 Gen2 LEQ DC Gain Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDCBW_G2_PHYB			0xF	//1h/x/x/x Port 0 Gen2 LEQ DC Gain Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z28		0x0077	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDCBW_G2_PHYB			0xF0	//1h/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDCBW_G2_PHYB			0xF	//1h/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z75		0x0078	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDCBW_G3_PHYB			0xF0	//1h/x/x/x Port 1 Gen3 LEQ DC Gain Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDCBW_G3_PHYB			0xF	//1h/x/x/x Port 0 Gen3 LEQ DC Gain Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z29		0x0079	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDCBW_G3_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDCBW_G3_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z76		0x007A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNHFBW_G1_PHYB			0xF0	//1h/x/x/x Port 1 Gen1 LEQ HF Gain Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNHFBW_G1_PHYB			0xF	//1h/x/x/x Port 0 Gen1 LEQ HF Gain Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z30		0x007B	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNHFBW_G1_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNHFBW_G1_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z77		0x007C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNHFBW_G2_PHYB			0xF0	//1h/x/x/x Port 1 Gen2 LEQ HF Gain Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNHFBW_G2_PHYB			0xF	//1h/x/x/x Port 0 Gen2 LEQ HF Gain Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z31		0x007D	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNHFBW_G2_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNHFBW_G2_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z78		0x007E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNHFBW_G3_PHYB			0xF0	//1h/x/x/x Port 1 Gen3 LEQ HF Gain Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNHFBW_G3_PHYB			0xF	//1h/x/x/x Port 0 Gen3 LEQ HF Gain Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z32		0x007F	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNHFBW_G3_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNHFBW_G3_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z79		0x0080	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNOSBW_G1_PHYB			0xF0	//1h/x/x/x Port 1 Gen1 LEQ Offset Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNOSBW_G1_PHYB			0xF	//1h/x/x/x Port 0 Gen1 LEQ Offset Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z33		0x0081	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNOSBW_G1_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNOSBW_G1_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z80		0x0082	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNOSBW_G2_PHYB			0xF0	//1h/x/x/x Port 1 Gen2 LEQ Offset Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNOSBW_G2_PHYB			0xF	//1h/x/x/x Port 0 Gen2 LEQ Offset Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z34		0x0083	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNOSBW_G2_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNOSBW_G2_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z81		0x0084	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNOSBW_G3_PHYB			0xF0	//1h/x/x/x Port 1 Gen3 LEQ Offset Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNOSBW_G3_PHYB			0xF	//1h/x/x/x Port 0 Gen3 LEQ Offset Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z35		0x0085	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNOSBW_G3_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNOSBW_G3_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z82		0x0086	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNWTBW_G1_PHYB			0xF0	//1h/x/x/x Port 1 Gen1 DFE Weight Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNWTBW_G1_PHYB			0xF	//1h/x/x/x Port 0 Gen1 DFE Weight Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z36		0x0087	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNWTBW_G1_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNWTBW_G1_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z83		0x0088	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNWTBW_G2_PHYB			0xF0	//1h/x/x/x Port 1 Gen2 DFE Weight Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNWTBW_G2_PHYB			0xF	//1h/x/x/x Port 0 Gen2 DFE Weight Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z37		0x0089	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNWTBW_G2_PHYB			0xF0	//1h/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNWTBW_G2_PHYB			0xF	//1h/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z84		0x008A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNWTBW_G3_PHYB			0xF0	//1h/x/x/x Port 1 Gen3 DFE Weight Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNWTBW_G3_PHYB			0xF	//1h/x/x/x Port 0 Gen3 DFE Weight Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_RESERVED_Z38		0x008B	//SATA_EPHY_PHYB Miscellaneous Control - Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNWTBW_G3_PHYB			0xF0	//1h/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNWTBW_G3_PHYB			0xF	//1h/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z85		0x008C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDFE_G1_PHYB			(BIT6 + BIT7)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDFE_G1_PHYB			(BIT4 + BIT5)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDFE_G1_PHYB			(BIT2 + BIT3)	//00b/x/x/x Port 1 Gen1 DFE Weight Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDFE_G1_PHYB			(BIT0 + BIT1)	//00b/x/x/x Port 0 Gen1 DFE Weight Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z86		0x008D	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDFE_G2_PHYB			(BIT6 + BIT7)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDFE_G2_PHYB			(BIT4 + BIT5)	//00b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDFE_G2_PHYB			(BIT2 + BIT3)	//00b/x/x/x Port 1 Gen2 DFE Weight Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDFE_G2_PHYB			(BIT0 + BIT1)	//00b/x/x/x Port 0 Gen2 DFE Weight Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z87		0x008E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDFE_G3_PHYB			(BIT6 + BIT7)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDFE_G3_PHYB			(BIT4 + BIT5)	//10b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDFE_G3_PHYB			(BIT2 + BIT3)	//10b/x/x/x Port 1 Gen3 DFE Weight Tuning Bandwidth Set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDFE_G3_PHYB			(BIT0 + BIT1)	//10b/x/x/x Port 0 Gen3 DFE Weight Tuning Bandwidth Set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z88		0x008F	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R08FB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNALWY_G1_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNALWY_G1_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNALWY_G1_PHYB			BIT1	//0/x/x/x Port 1 Gen1 Equalizer Always Tuning Mode Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNALWY_G1_PHYB			BIT0	//0/x/x/x Port 0 Gen1 Equalizer Always Tuning Mode Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z89		0x0090	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R090B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNALWY_G2_PHYB			BIT3	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNALWY_G2_PHYB			BIT2	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNALWY_G2_PHYB			BIT1	//0b/x/x/x Port 1 Gen2 Equalizer Always Tuning Mode Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNALWY_G2_PHYB			BIT0	//0b/x/x/x Port 0 Gen2 Equalizer Always Tuning Mode Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z90		0x0091	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R091B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNALWY_G3_PHYB			BIT3	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNALWY_G3_PHYB			BIT2	//0b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNALWY_G3_PHYB			BIT1	//0b/x/x/x Port 1 Gen3 Equalizer Always Tuning Mode Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNALWY_G3_PHYB			BIT0	//0b/x/x/x Port 0 Gen3 Equalizer Always Tuning Mode Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z91		0x0092	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R092B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNSPDSWEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNSPDSWEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNSPDSWEN_PHYB			BIT1	//0/x/x/x Port 1 Enable Low Speed Mode after First Tuning Finished
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNSPDSWEN_PHYB			BIT0	//0/x/x/x Port 0 Enable Low Speed Mode after First Tuning Finished
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z92		0x0093	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R093B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNVTH_G1_PHYB			0x1F	//01111b/x/x/x Port 0 Gen1 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z93		0x0094	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R094B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNVTH_G1_PHYB			0x1F	//01111b/x/x/x Port 1 Gen1 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z94		0x0095	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R095B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNVTH_G2_PHYB			0x1F	//01111b/x/x/x Port 0 Gen2 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z95		0x0096	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R096B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNVTH_G2_PHYB			0x1F	//01111b/x/x/x Port 1 Gen2 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z96		0x0097	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R097B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNVTH_G3_PHYB			0x1F	//01111b/x/x/x Port 0 Gen3 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z97		0x0098	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R098B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNVTH_G3_PHYB			0x1F	//01111b/x/x/x Port 1 Gen3 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z98		0x0099	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R099B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDFETRN_G1_PHYB			BIT3	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDFETRN_G1_PHYB			BIT2	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDFETRN_G1_PHYB			BIT1	//1b/x/x/x Port 1 Gen1 Enabling DFE in Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDFETRN_G1_PHYB			BIT0	//1b/x/x/x Port 0 Gen1 Enabling DFE in Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z99		0x009A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R09AB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDFETRN_G2_PHYB			BIT3	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDFETRN_G2_PHYB			BIT2	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDFETRN_G2_PHYB			BIT1	//1b/x/x/x Port 1 Gen2 Enabling DFE in Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDFETRN_G2_PHYB			BIT0	//1b/x/x/x Port 0 Gen2 Enabling DFE in Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z100		0x009B	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R09BB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNDFETRN_G3_PHYB			BIT3	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNDFETRN_G3_PHYB			BIT2	//1b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNDFETRN_G3_PHYB			BIT1	//1b/x/x/x Port 1 Gen3 Enabling DFE in Training Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNDFETRN_G3_PHYB			BIT0	//1b/x/x/x Port 0 Gen3 Enabling DFE in Training Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z101		0x009C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R09CB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_DCSETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_DCSETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_DCSETEN_PHYB			BIT1	//0/x/x/x Port 1 LEQ DC Gain Manual Set Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_DCSETEN_PHYB			BIT0	//0/x/x/x Port 0 LEQ DC Gain Manual Set Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z102		0x009D	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R09D7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_DCSET_G1_PHYB			0x1F	//00001b/x/x/x Port 0 Gen1 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z103		0x009E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R09EB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_DCSET_G1_PHYB			0x1F	//00001b/x/x/x Port 1 Gen1 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z104		0x009F	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R09FB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_DCSET_G1_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z105		0x00A0	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A0B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_DCSET_G1_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z106		0x00A1	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A1B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_DCSET_G2_PHYB			0x1F	//00001b/x/x/x Port 0 Gen2 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z107		0x00A2	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A2B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_DCSET_G2_PHYB			0x1F	//00001b/x/x/x Port 1 Gen2 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z108		0x00A3	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A3B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_DCSET_G2_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z109		0x00A4	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A4B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_DCSET_G2_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z110		0x00A5	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A5B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_DCSET_G3_PHYB			0x1F	//00001b/x/x/x Port 0 Gen3 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z111		0x00A6	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A6B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_DCSET_G3_PHYB			0x1F	//00001b/x/x/x Port 1 Gen3 Equalizer Tuning Threshold Voltage
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z112		0x00A7	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A7B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_DCSET_G3_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z113		0x00A8	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A8B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_DCSET_G3_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z114		0x00A9	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0A9B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_HFSETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_HFSETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_HFSETEN_PHYB			BIT1	//0/x/x/x Port 1 LEQ HF Gain Manual Set Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_HFSETEN_PHYB			BIT0	//0/x/x/x Port 0 LEQ HF Gain Manual Set Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z115		0x00AA	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0AAB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_HFSET_G1_PHYB			0x1F	//00001b/x/x/x Port 0 Gen1 LEQ HF Gain Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z116		0x00AB	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0ABB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_HFSET_G1_PHYB			0x1F	//00001b/x/x/x Port 1 Gen1 LEQ HF Gain Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z117		0x00AC	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0ACB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_HFSET_G1_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z118		0x00AD	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0ADB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_HFSET_G1_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z119		0x00AE	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0AEB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_HFSET_G2_PHYB			0x1F	//00001b/x/x/x Port 0 Gen2 LEQ HF Gain Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z120		0x00AF	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0AFB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_HFSET_G2_PHYB			0x1F	//00001b/x/x/x Port 1 Gen2 LEQ HF Gain Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z121		0x00B0	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B0B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_HFSET_G2_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z122		0x00B1	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B1B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_HFSET_G2_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z123		0x00B2	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B2B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_HFSET_G3_PHYB			0x1F	//00001b/x/x/x Port 0 Gen3 LEQ HF Gain Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z124		0x00B3	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B3B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_HFSET_G3_PHYB			0x1F	//00001b/x/x/x Port 1 Gen3 LEQ HF Gain Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z125		0x00B4	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B4B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_HFSET_G3_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z126		0x00B5	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B5B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_HFSET_G3_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z127		0x00B6	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B6B7_B5			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_OSSETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_OSSETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_OSSETEN_PHYB			BIT1	//0/x/x/x Port 1 LEQ Offset Manual Set Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_OSSETEN_PHYB			BIT0	//0/x/x/x Port 0 LEQ Offset Manual Set Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z128		0x00B7	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B7B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_OSSET_G1_PHYB			0x1F	//0/x/x/x Port 0 Gen1 LEQ Offset Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z129		0x00B8	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B8B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_OSSET_G1_PHYB			0x1F	//0/x/x/x Port 1 Gen1 LEQ Offset Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z130		0x00B9	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0B9B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_OSSET_G1_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z131		0x00BA	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0BAB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_OSSET_G1_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z132		0x00BB	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0BBB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_OSSET_G2_PHYB			0x1F	//0/x/x/x Port 0 Gen2 LEQ Offset Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z133		0x00BC	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0BCB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_OSSET_G2_PHYB			0x1F	//0/x/x/x Port 1 Gen2 LEQ Offset Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z134		0x00BD	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0BDB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_OSSET_G2_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z135		0x00BE	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0BEB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_OSSET_G2_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z136		0x00BF	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0BFB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_OSSET_G3_PHYB			0x1F	//0/x/x/x Port 0 Gen3 LEQ Offset Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z137		0x00C0	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C0B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_OSSET_G3_PHYB			0x1F	//0/x/x/x Port 1 Gen3 LEQ Offset Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z138		0x00C1	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C1B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_OSSET_G3_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z139		0x00C2	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C2B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_OSSET_G3_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z140		0x00C3	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C3B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_W1SETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_W1SETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_W1SETEN_PHYB			BIT1	//0/x/x/x Port 1 DFE Weight1 Manual Set Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_W1SETEN_PHYB			BIT0	//0/x/x/x Port 0 DFE Weight1 Manual Set Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z141		0x00C4	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C4B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_W1SET_G1_PHYB			0x1F	//00001b/x/x/x Port 0 Gen1 DFE Weight1 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z142		0x00C5	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C5B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_W1SET_G1_PHYB			0x1F	//00001b/x/x/x Port 1 Gen1 DFE Weight1 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z143		0x00C6	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C6B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_W1SET_G1_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z144		0x00C7	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C7B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_W1SET_G1_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z145		0x00C8	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C8B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_W1SET_G2_PHYB			0x1F	//00001b/x/x/x Port 0 Gen2 DFE Weight1 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z146		0x00C9	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0C9B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_W1SET_G2_PHYB			0x1F	//00001b/x/x/x Port 1 Gen2 DFE Weight1 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z147		0x00CA	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0CAB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_W1SET_G2_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z148		0x00CB	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0CBB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_W1SET_G2_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z149		0x00CC	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0CCB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_W1SET_G3_PHYB			0x1F	//00001b/x/x/x Port 0 Gen3 DFE Weight1 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z150		0x00CD	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0CDB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_W1SET_G3_PHYB			0x1F	//00001b/x/x/x Port 1 Gen3 DFE Weight1 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z151		0x00CE	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0CEB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_W1SET_G3_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z152		0x00CF	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0CFB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_W1SET_G3_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z153		0x00D0	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D0B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_W2SETEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_W2SETEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_W2SETEN_PHYB			BIT1	//0/x/x/x Port 1 DFE Weight2 Manual Set Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_W2SETEN_PHYB			BIT0	//0/x/x/x Port 0 DFE Weight2 Manual Set Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z154		0x00D1	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D1B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_W2SET_G1_PHYB			0x1F	//00001b/x/x/x Port 0 Gen1 DFE Weight2 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z155		0x00D2	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D2B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_W2SET_G1_PHYB			0x1F	//00001b/x/x/x Port 1 Gen1 DFE Weight2 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z156		0x00D3	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D3B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_W2SET_G1_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z157		0x00D4	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D4B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_W2SET_G1_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z158		0x00D5	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D5B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_W2SET_G2_PHYB			0x1F	//00001b/x/x/x Port 0 Gen2 DFE Weight2 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z159		0x00D6	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D6B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_W2SET_G2_PHYB			0x1F	//00001b/x/x/x Port 1 Gen2 DFE Weight2 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z160		0x00D7	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D7B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_W2SET_G2_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z161		0x00D8	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D8B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_W2SET_G2_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z162		0x00D9	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0D9B7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_W2SET_G3_PHYB			0x1F	//00001b/x/x/x Port 0 Gen3 DFE Weight2 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z163		0x00DA	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0DAB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_W2SET_G3_PHYB			0x1F	//00001b/x/x/x Port 1 Gen3 DFE Weight2 Initial or Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z164		0x00DB	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0DBB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_W2SET_G3_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z165		0x00DC	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0DCB7_B5			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_W2SET_G3_PHYB			0x1F	//00001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z166		0x00DD	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_DCOUT_PHYB			0x1F	//0/x/x/x Port 0 LEQ DC Gain Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z167		0x00DE	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_DCOUT_PHYB			0x1F	//0/x/x/x Port 1 LEQ DC Gain Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z168		0x00DF	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_DCOUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z169		0x00E0	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_DCOUT_PHYB			0x1F	//0/X/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z170		0x00E1	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_HFOUT_PHYB			0x1F	//0/x/x/x Port 0 LEQ HF Gain Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z171		0x00E2	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_HFOUT_PHYB			0x1F	//0/x/x/x Port 1 LEQ HF Gain Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z172		0x00E3	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_HFOUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z173		0x00E4	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_HFOUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z174		0x00E5	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_OSOUT_PHYB			0x1F	//0/x/x/x Port 0 LEQ Offset Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z175		0x00E6	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_OSOUT_PHYB			0x1F	//0/x/x/x Port 1 LEQ Offset Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z176		0x00E7	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_OSOUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z177		0x00E8	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_OSOUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z178		0x00E9	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_W1OUT_PHYB			0x1F	//0/x/x/x Port 0 LEQ Weight1 Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z179		0x00EA	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_W1OUT_PHYB			0x1F	//0/x/x/x Port 1 LEQ Weight1 Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z180		0x00EB	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_W1OUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z181		0x00EC	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_W1OUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z182		0x00ED	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_W2OUT_PHYB			0x1F	//0/x/x/x Port 0 LEQ Weight2 Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z183		0x00EE	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_W2OUT_PHYB			0x1F	//0/x/x/x Port 1 LEQ Weight2 Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z184		0x00EF	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP02_W2OUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z185		0x00F0	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP03_W2OUT_PHYB			0x1F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z186		0x00F1	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0F1B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNBISTEN_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNBISTEN_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNBISTEN_PHYB			BIT1	//0/x/x/x Port 1 Tuning Function BIST Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNBISTEN_PHYB			BIT0	//0/x/x/x Port 0 Tuning Function BIST Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z187		0x00F2	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0F2B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_EQTNBISTEVT_PHYB			(BIT4 + BIT5 + BIT6)	//0/x/x/x Port 1 Tuning Function BIST: Event Selection
    #define D15F0_SATA_EPHY_INDEXDATA_R0F2B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_EQTNBISTEVT_PHYB			(BIT0 + BIT1 + BIT2)	//0/x/x/x Port 0 Tuning Function BIST: Event Selection
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z188		0x00F3	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0F3B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_EQTNBISTEVT_PHYB			(BIT4 + BIT5 + BIT6)	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_R0F3B3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_EQTNBISTEVT_PHYB			(BIT0 + BIT1 + BIT2)	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z189		0x00F4	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R0F4B7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP03_PG3_EQ_LS_PHYB			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP02_PG3_EQ_LS_PHYB			BIT2	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP01_PG3_EQ_LS_PHYB			BIT1	//0b/x/x/x Port 1 EQTN Tuning Speed at PCIe Gen3
    #define D15F0_SATA_EPHY_INDEXDATA_FHP00_PG3_EQ_LS_PHYB			BIT0	//0b/x/x/x Port 0 EQTN Tuning Speed at PCIe Gen3
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_4_MISC_CTL		0x00F5	//SATA_EPHY_4 Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_FTXSWN_PHYB_1_0			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_FTXSWN_PHYB_1_0			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_FTXSWN_PHYB_1_0			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_FTXSWN_PHYB_1_0			(BIT0 + BIT1)	//0/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z190		0x00F6	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPF6B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPF6B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPF6B5			BIT5	//1b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPF6B4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TDNCIS_PHYB			0xF	//1010b/x/x/x Port 0 LPn_TDNCIS for SATA INDEX = 00/01b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z191		0x00F7	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPF7B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPF7B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPF7B5			BIT5	//1b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPF7B4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TDNCIS_PHYB			0xF	//1010b/x/x/x Port 1 LPn_TDNCIS for SATA INDEX = 00/01b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z192		0x00F8	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPF8B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPF8B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TDNCIS_PHYB			0x3F	//101010b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z193		0x00F9	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPF9B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPF9B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TDNCIS_PHYB			0x3F	//101010b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z194		0x00FA	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPFAB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPFAB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPFAB5_3			(BIT3 + BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TDPCIS_PHYB			(BIT0 + BIT1 + BIT2)	//0/x/x/x Port 0 LPn_TDPCIS for SATA INDEX = 00/01b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z195		0x00FB	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPFBB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPFBB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPFBB5_3			(BIT3 + BIT4 + BIT5)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TDPCIS_PHYB			(BIT0 + BIT1 + BIT2)	//0/x/x/x Port 1 LPn_TDPCIS for SATA INDEX = 00/01b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z196		0x00FC	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPFCB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPFCB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TDPCIS_PHYB			0x3F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z197		0x00FD	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPFDB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPFDB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TDPCIS_PHYB			0x3F	//0/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z198		0x00FE	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPFEB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXNSR_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 LPn_TXNSR for SATA INDEX = 00/01b
    #define D15F0_SATA_EPHY_INDEXDATA_EPFEB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXNSR_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 LPn_TXNSR for SATA INDEX = 00/01b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_4_MISC_CTL_Z1		0x00FF	//SATA_EPHY_4 Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EPFFB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_TXNSR_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EPFFB3			BIT3	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_TXNSR_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z199		0x0100	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_REFCLK_SEL_PHYB			BIT7	//0/x/x/x Manual Setting for Selecting Internal or External Clock
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_CTSCLKSEL_PHYD			BIT6	//0/x/x/x Selecte CTSCLK source.
    #define D15F0_SATA_EPHY_INDEXDATA_LP_REFCLKN_D_PHYB			BIT5	//0/x/x/x 0.9V Negative Terminal of Internal REFCLK (100MHz)
    #define D15F0_SATA_EPHY_INDEXDATA_LP_REFCLKP_D_PHYB			BIT4	//0/x/x/x 0.9V Positive Terminal of Internal REFCLK (100MHz)
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_BG_TRIM_PHYB			(BIT1 + BIT2 + BIT3)	//100b/x/x/x Fine tune Bandgap setting
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_EPHYMSTEN_PHYB			BIT0	//0/x/x/x Force to Turn on All Functions in Master Block When EPHY Testing
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z200		0x0101	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_MPLL_OP_PHYB			BIT7	//0/x/x/x MPLL Operation Mode for Debugging
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_MPLL_CP_PHYB			0x78	//0011b/x/x/x MPLL CP Current Setting
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_MPLLMODE_PHYB			BIT2	//1b/x/x/x MPLL Mode Selection
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_MPLLREFCLK_SEL_PHYB			BIT1	//1b/x/x/x MPLL Reference Clock Manual Setting 
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_REFCLKPS_SEL_PHYB			BIT0	//1b/x/x/x Internal PCIe or SATA Clock Manual Setting 
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z201		0x0102	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_MPLL_FLAGCK_EN_PHYB			BIT5	//0/x/x/x Enable MPLL Flag Function When Debug Mode
    #define D15F0_SATA_EPHY_INDEXDATA_EP_MPLLOK_PHYB			BIT4	//0/x/x/x MPLL Lock Flag
    #define D15F0_SATA_EPHY_INDEXDATA_EP_FLAG250_PHYB			BIT3	//0/x/x/x MPLL and TPLL Synchronization Flag
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_MPLL_DELAY_PHYB			(BIT1 + BIT2)	//01b/x/x/x MPLL Feedback Divider Delay Setting.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_MPLL_LOCK_EN_PHYB			BIT0	//0/x/x/x Overwrite MPLL Lock Flag Setting
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z202		0x0103	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_CP_G1_PHYB			0xF0	//5h/x/x/x Main 1 TPLL CP Current Setting for Gen1 Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_CP_G1_PHYB			0xF	//5h/x/x/x Main 0 TPLL CP Current Setting for Gen1 Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z203		0x0104	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_CP_G2_PHYB			0xF0	//5h/x/x/x Main 1 TPLL CP Current Setting for Gen2 Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_CP_G2_PHYB			0xF	//5h/x/x/x Main 0 TPLL CP Current Setting for Gen2 Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z204		0x0105	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_CP_G3_PHYB			0xF0	//5h/x/x/x Main 1 TPLL CP Current Setting for Gen3 Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_CP_G3_PHYB			0xF	//5h/x/x/x Main 0 TPLL CP Current Setting for Gen3 Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z205		0x0106	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP1_TPLL_OK_PHYB			BIT5	//0/x/x/x Main 1 TPLL Lock Flag Lock 
    #define D15F0_SATA_EPHY_INDEXDATA_EP0_TPLL_OK_PHYB			BIT4	//0/x/x/x Main 0 TPLL Lock Flag Lock
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_LOCK_EN_PHYB			BIT3	//0/x/x/x Main 1 Overwrite TPLL Lock Flag Setting
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL_LOCK_EN_PHYB			BIT2	//0/x/x/x Main 0 Overwrite TPLL Lock Flag Setting
    #define D15F0_SATA_EPHY_INDEXDATA_EP1_TPLL_DIV_PHYB			BIT1	//0/x/x/x Main 1 TPLL Feedback Divider Output
    #define D15F0_SATA_EPHY_INDEXDATA_EP0_TPLL_DIV_PHYB			BIT0	//0/x/x/x Main 0 TPLL Feedback Divider Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z206		0x0107	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R107B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_DIV_G1_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x Main 1 TPLL Feedback Frequency - Gen1
    #define D15F0_SATA_EPHY_INDEXDATA_R107B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_DIV_G1_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x Main 0 TPLL Feedback Frequency- Gen1
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z207		0x0108	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R108B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_DIV_G2_PHYB			(BIT4 + BIT5 + BIT6)	//110b/x/x/x Main 1 TPLL Feedback Frequency - Gen2
    #define D15F0_SATA_EPHY_INDEXDATA_R108B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_DIV_G2_PHYB			(BIT0 + BIT1 + BIT2)	//110b/x/x/x Main 0 TPLL Feedback Frequency - Gen2
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z208		0x0109	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R109B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_DIV_G3_PHYB			(BIT4 + BIT5 + BIT6)	//111b/x/x/x Main 1 TPLL Feedback Frequency - Gen3
    #define D15F0_SATA_EPHY_INDEXDATA_R109B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_DIV_G3_PHYB			(BIT0 + BIT1 + BIT2)	//111b/x/x/x Main 0 TPLL Feedback Frequency- Gen3
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z209		0x010A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R10AB7_B6			(BIT6 + BIT7)	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_BAND_G1_PHYB			(BIT4 + BIT5)	//00b/x/x/x Main 1 TPLL VCO Operation Frequency - Gen1
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_BAND_G1_PHYB			(BIT2 + BIT3)	//00b/x/x/x Main 0 TPLL VCO Operation Frequency- Gen1
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_FLAGCK_EN_PHYB			BIT1	//0/x/x/x Main 1 Enable TPLL Flag Function When in Debug Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL_FLAGCK_EN_PHYB			BIT0	//0/x/x/x Main 0 Enable TPLL Flag Function When in Debug Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z210		0x010B	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_BAND_G3_PHYB			(BIT6 + BIT7)	//00b/x/x/x Main 1 TPLL VCO Operation Frequency- Gen3
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_BAND_G3_PHYB			(BIT4 + BIT5)	//00b/x/x/x Main 0 TPLL VCO Operation Frequency- Gen3
    #define D15F0_SATA_EPHY_INDEXDATA_FRP1_TPLL_BAND_G2_PHYB			(BIT2 + BIT3)	//00b/x/x/x Main 1 TPLL VCO Operation Frequency - Gen2
    #define D15F0_SATA_EPHY_INDEXDATA_FRP0_TPLL_BAND_G2_PHYB			(BIT0 + BIT1)	//00b/x/x/x Main 0 TPLL VCO operation frequency - Gen2
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z211		0x010C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R10CB7_B4			0xF0	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_LF_PHYB			BIT3	//0/x/x/x PLL Loop Order Selection
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL_LF_PHYB			BIT2	//0/x/x/x PLL Loop Order Selection
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_GATECLK_EN_PHYB			BIT1	//1b/x/x/x Main 1 Enable Clock Gating When in Partial Mode
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_GATECLK_EN_PHYB			BIT0	//1b/x/x/x Main 0 Enable Clock Gating When in Partial Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z212		0x010D	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R10DB7_B2			0xFC	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_RTNRXSETEN_PHYB			BIT1	//0/x/x/x RX Resistance Set Enable
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_RTNTXSETEN_PHYB			BIT0	//0/x/x/x TX Resistance Set Enable
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z213		0x010E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_RTNRXSET_PHYB			0xF0	//8h/x/x/x RX Resistance Set Value
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_RTNTXSET_PHYB			0xF	//8h/x/x/x TX Resistance Set Value
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z214		0x010F	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP_RTNRXOUT_PHYB			0xF0	//0/x/x/x TX Resistance Output
    #define D15F0_SATA_EPHY_INDEXDATA_EP_RTNTXOUT_PHYB			0xF	//0/x/x/x TX Resistance Output
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z215		0x0110	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_R110B7_B2			0xFC	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_RTNBIST_PHYB			(BIT0 + BIT1)	//00b/x/x/x BIST Control
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z216		0x0114	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP1_TPLL_OK_PHYD			BIT7	//0/x/x/x EP1 TPLL OK
    #define D15F0_SATA_EPHY_INDEXDATA_EP0_TPLL_OK_PHYD			BIT6	//0/x/x/x EP0 TPLL OK
    #define D15F0_SATA_EPHY_INDEXDATA_EP_MPLLOK_PHYD			BIT5	//0/x/x/x MPLL Lock Flag
    #define D15F0_SATA_EPHY_INDEXDATA_LP1_TPLL_PDB_PHYD			BIT4	//0/x/x/x TPLL1 Power Down Control Bit
    #define D15F0_SATA_EPHY_INDEXDATA_LP0_TPLL_PDB_PHYD			BIT3	//0/x/x/X TPLL0 Power Down Control Bit
    #define D15F0_SATA_EPHY_INDEXDATA_LP_MPLL_PDB_PHYD			BIT2	//0/x/x/X Power off MPLL and TX/RX Power State Machine Reset
    #define D15F0_SATA_EPHY_INDEXDATA_LP_REFCLK_PDB_PHYD			BIT1	//0/x/x/X Power Down Refclk_Slicer Control Bit
    #define D15F0_SATA_EPHY_INDEXDATA_LP_BGPDB_PHYD			BIT0	//0/x/x/x Power off Bandgap and Isource (low active)
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z217		0x0115	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_LP_RTNEN_PHYD			BIT2	//0/x/x/x Resistance Tuning Enable
    #define D15F0_SATA_EPHY_INDEXDATA_LP_RTNRSTB_PHYD			BIT1	//0/x/x/x Resistance Tuning Reset 
    #define D15F0_SATA_EPHY_INDEXDATA_LP_RTNPDB_PHYD			BIT0	//0/x/x/x Power off Resistance Tuning
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z218		0x0116	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP1_TPLL_SWBLW_PHYB			BIT2	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP1_TPLL_GSEL1_PHYB			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP1_TPLL_GSEL0_PHYB			BIT0	//0/x/x/x Reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z219		0x0117	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_SE_PHYB			BIT7	//1b/x/x/x FHP1_TPLL_SE_PHYB
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_ISEL0_PHYB			BIT6	//0/x/x/x FHP1_TPLL_ISEL0_PHYB
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_ISEL1_PHYB			BIT5	//0/x/x/x FHP1_TPLL_ISEL1_PHYB
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_FSEL0_PHYB			BIT4	//1b/x/x/x FHP1_TPLL_FSEL0_PHYB
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_FSEL1_PHYB			BIT3	//0b/x/x/x FHP1_TPLL_FSEL1_PHYB
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_SWSEL0_PHYB			BIT2	//1b/x/x/x FHP1_TPLL_SWSEL0_PHYB
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_SWSEL1_PHYB			BIT1	//0/x/x/x FHP1_TPLL_SWSEL1_PHYB
    #define D15F0_SATA_EPHY_INDEXDATA_FHP1_TPLL_SWSEL2_PHYB			BIT0	//1b/x/x/x FHP1_TPLL_SWSEL2_PHYB
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z220		0x0118	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_G3_TX_DUTY_PHYB			(BIT6 + BIT7)	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_G3_TX_DUTY_PHYB			(BIT4 + BIT5)	//0/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_G3_TX_DUTY_PHYB			(BIT2 + BIT3)	//0/x/x/x Port 1 TX_DUTY for SATA INDEX = 10b
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_G3_TX_DUTY_PHYB			(BIT0 + BIT1)	//0/x/x/x Port 0 TX_DUTY for SATA INDEX = 10b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z221		0x0119	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_G3_TXPSR_PHYB			(BIT5 + BIT6 + BIT7)	//011b/x/x/x Port 0 LPn_TXPSR for SATA INDEX = 10b
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_G3_TDCIS_PHYB			0x1F	//11011b/x/x/x Port 0 LPn_TDCIS for SATA INDEX = 10b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z222		0x011A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_G3_TXPSR_PHYB			(BIT5 + BIT6 + BIT7)	//011b/x/x/x Port 1 LPn_TXPSR for SATA INDEX = 10b
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_G3_TDCIS_PHYB			0x1F	//11011b/x/x/x Port 1 LPn_TDCIS for SATA INDEX = 10b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z223		0x011B	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_G3_TXPSR_PHYB			(BIT5 + BIT6 + BIT7)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_G3_TDCIS_PHYB			0x1F	//11011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z224		0x011C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_G3_TXPSR_PHYB			(BIT5 + BIT6 + BIT7)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_G3_TDCIS_PHYB			0x1F	//11011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z225		0x011D	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP11DB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP11DB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP11DB5			BIT5	//1b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP11DB4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_G3_TDNCIS_PHYB			0xF	//1000b/x/x/x Port 0 LPn_TDNCIS for SATA INDEX = 10b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z226		0x011E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP11EB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP11EB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP11EB5			BIT5	//1b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP11EB4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_G3_TDNCIS_PHYB			0xF	//1000b/x/x/x Port 1 LPn_TDNCIS for SATA INDEX = 10b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z227		0x011F	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP11FB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP11FB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_G3_TDNCIS_PHYB			0x3F	//101000b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z228		0x0120	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP120B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP120B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_G3_TDNCIS_PHYB			0x3F	//101000b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z229		0x0121	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP121B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP121B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP121B5_3			(BIT3 + BIT4 + BIT5)	//010b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_G3_TDPCIS_PHYB			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Port 0 LPn_TDPCIS for SATA INDEX = 10b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z230		0x0122	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP122B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP122B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP122B5_3			(BIT3 + BIT4 + BIT5)	//010b/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_G3_TDPCIS_PHYB			(BIT0 + BIT1 + BIT2)	//001b/x/x/x Port 1 LPn_TDPCIS for SATA INDEX = 10b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z231		0x0123	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP123B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP123B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_G3_TDPCIS_PHYB			0x3F	//010001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z232		0x0124	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP124B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP124B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_G3_TDPCIS_PHYB			0x3F	//010001b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z233		0x0125	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP125B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_G3_TXNSR_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Port 1 LPn_TXNSR for SATA INDEX = 10b
    #define D15F0_SATA_EPHY_INDEXDATA_EP125B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_G3_TXNSR_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Port 0 LPn_TXNSR for SATA INDEX = 10b
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z234		0x0126	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP126B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP03_G3_TXNSR_PHYB			(BIT4 + BIT5 + BIT6)	//011b/x/x/x reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP126B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP02_G3_TXNSR_PHYB			(BIT0 + BIT1 + BIT2)	//011b/x/x/x reserved
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z235		0x0127	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP127B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP127B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP127B5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP127B4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP127B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP127B2			BIT2	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP127B1			BIT1	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_TST_MODE_PHYB			BIT0	//0/x/x/x MUX Select of Test Data and Normal Data for Parameter Testing
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z236		0x0128	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP128B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP128B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP128B5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_RDETEN_TST_PHYB			BIT4	//0/x/x/x LP00_RDETEN Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_TXRDETPDB_TST_PHYB			BIT3	//0/x/x/x LP00_TXRDETPDB Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_RXHZ_TST_PHYB			BIT2	//0/x/x/x LP00_RXHZ Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_TXHZ_TST_PHYB			BIT1	//0/x/x/x LP00_TXHZ Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_EIDLESQPDB_TST_PHYB			BIT0	//0/x/x/x LP00_EIDLESQPDB Control Register under Test Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z237		0x0129	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP129B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP129B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP129B5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_RDETEN_TST_PHYB			BIT4	//0/x/x/x LP01_RDETEN Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_TXRDETPDB_TST_PHYB			BIT3	//0/x/x/x LP01_TXRDETPDB Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_RXHZ_TST_PHYB			BIT2	//0/x/x/x LP01_RXHZ Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_TXHZ_TST_PHYB			BIT1	//0/x/x/x LP01_TXHZ Control Register Under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_EIDLESQPDB_TST_PHYB			BIT0	//0/x/x/x LP01_EIDLESQPDB Control Register under Test Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z238		0x012A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP12AB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP12AB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP12AB5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP02_RDETEN_TST_PHYB			BIT4	//0/x/x/x LP02_RDETEN Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP02_TXRDETPDB_TST_PHYB			BIT3	//0/x/x/x LP02_TXRDETPDB Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP02_RXHZ_TST_PHYB			BIT2	//0/x/x/x LP02_RXHZ Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP02_TXHZ_TST_PHYB			BIT1	//0/x/x/x LP02_TXHZ Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP02_EIDLESQPDB_TST_PHYB			BIT0	//0/x/x/x LP02_EIDLESQPDB Control Register under Test Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z239		0x012B	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP12BB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP12BB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP12BB5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP03_RDETEN_TST_PHYB			BIT4	//0/x/x/x LP03_RDETEN Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP03_TXRDETPDB_TST_PHYB			BIT3	//0/x/x/x LP03_TXRDETPDB Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP03_RXHZ_TST_PHYB			BIT2	//0/x/x/x LP03_RXHZ Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP03_TXHZ_TST_PHYB			BIT1	//0/x/x/x LP03_TXHZ Control Register under Test Mode
    #define D15F0_SATA_EPHY_INDEXDATA_LP03_EIDLESQPDB_TST_PHYB			BIT0	//0/x/x/x LP03_EIDLESQPDB Control Register under Test Mode
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z240		0x0130	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP130B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_IPTUNE_PHYD			(BIT4 + BIT5 + BIT6)	//000b/x/x/x Internal current source value tuning.
    #define D15F0_SATA_EPHY_INDEXDATA_EP130B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP_IPTATUNE_PHYD			(BIT0 + BIT1 + BIT2)	//000b/x/x/x Internal current source value tuning.
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z241		0x0131	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP131B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP131B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP131B5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL0_BDSET_EN_PHYD			BIT4	//0/x/x/x Enable TPLL0 band manual tuning.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL1_BDSET_EN_PHYD			BIT3	//0/x/x/x Enable TPLL1 band manual tuning.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_MPLL_FSEL_PHYD			(BIT0 + BIT1 + BIT2)	//000b/x/x/x MPLL VCO frequency tuning.
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z242		0x0132	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL1_BDSET_PHYD			0xF0	//0000b/x/x/x TPLL1 manual tuning setting. Changing for debug.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL0_BDSET_PHYD			0xF	//0000b/x/x/x TPLL0 manual tuning setting. Changing for debug.
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z243		0x0133	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP133B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP133B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL1_VCRST_PHYD			(BIT3 + BIT4 + BIT5)	//000b/x/x/x TPLL1 initial vcontrol selection.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL0_VCRST_PHYD			(BIT0 + BIT1 + BIT2)	//000b/x/x/x TPLL0 initial vcontrol selection.
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z244		0x0134	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL0_FTUNE_PHYD_7_0			0xFF	//0/x/x/x TPLL0 manual tuning setting. Changing for debug.[7:0]
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z245		0x0135	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP135B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP135B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP135B5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP135B4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP135B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL0_FTUNE_EN_PHYD			BIT2	//0/x/x/x Enable TPLL0 frequency manual tuning.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL0_FTUNE_PHYD_9_8			(BIT0 + BIT1)	//00b/x/x/x TPLL0 manual tuning setting. Changing for debug.[9:8]
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z246		0x0136	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL1_FTUNE_PHYD_7_0			0xFF	//0/x/x/x TPLL1 manual tuning setting. Changing for debug.[7:0]
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z247		0x0137	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP137B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP137B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP137B5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP137B4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP137B3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL1_FTUNE_EN_PHYD			BIT2	//0/x/x/x Enable TPLL1 frequency manual tuning.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL1_FTUNE_PHYD_9_8			(BIT0 + BIT1)	//00b/x/x/x TPLL1 manual tuning setting. Changing for debug.[9:8]
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z248		0x0138	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP138B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP138B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL1_CKBUFVREG_PHYD			(BIT3 + BIT4 + BIT5)	//000b/x/x/x TPLL0 Clock buffer regulator voltage selection.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL0_CKBUFVREG_PHYD			(BIT0 + BIT1 + BIT2)	//000b/x/x/x TPLL0 Clock buffer regulator voltage selection.
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z249		0x0139	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP139B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP139B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL1_CKBUFDUTY_PHYD			(BIT3 + BIT4 + BIT5)	//000b/x/x/x TPLL1 Clock buffer duty selection.
    #define D15F0_SATA_EPHY_INDEXDATA_FHP0_TPLL0_CKBUFDUTY_PHYD			(BIT0 + BIT1 + BIT2)	//000b/x/x/x TPLL0 Clock buffer duty selection.
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z250		0x013A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FH01_ABCSEL_CDR_PHYD			(BIT6 + BIT7)	//00b/x/x/x Port1 Loop bandwidth mode selection (00)
    #define D15F0_SATA_EPHY_INDEXDATA_FH00_ABCSEL_CDR_PHYD			(BIT4 + BIT5)	//00b/x/x/x Port0 Loop bandwidth mode selection (00)
    #define D15F0_SATA_EPHY_INDEXDATA_FH01_CKBUFSEL_CDR_PHYD			(BIT2 + BIT3)	//00b/x/x/x Port 1 PI clock buffer selection (00)
    #define D15F0_SATA_EPHY_INDEXDATA_FH00_CKBUFSEL_CDR_PHYD			(BIT0 + BIT1)	//00b/x/x/x Port 0 PI clock buffer selection (00)
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z251		0x013B	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_BPFBW_PHYD			0xF0	//0000b/x/x/x Port1 PI bandwidth tuning
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_BPFBW_PHYD			0xF	//0000b/x/x/x Port0 PI bandwidth tuning
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z252		0x013C	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_BERCNT_PHYD_7_0			0xFF	//0/x/x/x Port 0 BER counter result[7:0]
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z253		0x013D	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP13DB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP13DB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP13DB5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP13DB4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_BERCNTRSTB_PHYD			BIT3	//0/x/x/x Port 0 BER counter result reset (low active)
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_BERCNTEN_PHYD			BIT2	//0/x/x/x Port 0 BER counter function enable (0: hold result)
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_BERCNT_PHYD_9_8			(BIT0 + BIT1)	//00b/x/x/x Port 0 BER counter result[9:8]
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z254		0x013E	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_BERCNT_PHYD_7_0			0xFF	//0/x/x/x Port 1 BER counter result[7:0]
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z255		0x013F	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP13FB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP13FB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP13FB5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP13FB4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_BERCNTRSTB_PHYD			BIT3	//0/x/x/x Port 1 BER counter result reset (low active)
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_BERCNTEN_PHYD			BIT2	//0/x/x/x Port 1 BER counter function enable (0: hold result)
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_BERCNT_PHYD_9_8			(BIT0 + BIT1)	//00b/x/x/x Port 1 BER counter result[9:8]
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z256		0x0140	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP140B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_PH_OS_PHYD			0x7F	//0/x/x/x Port0 PI phase offset for data sampling when BER counter
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z257		0x0141	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP141B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_PH_OS_PHYD			0x7F	//0/x/x/x Port1 PI phase offset for data sampling when BER counter
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z258		0x0142	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP142B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP00_PH_IDEAL_PHYD			0x7F	//0/x/x/x Port0 ideal PI phase for data sampling
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z259		0x0143	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP143B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP01_PH_IDEAL_PHYD			0x7F	//0/x/x/x Port1 ideal PI phase for data sampling
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z260		0x0144	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXPWRSW_G1_PHYD			(BIT6 + BIT7)	//00b/x/x/x Port 1 Gen1 TX power supply switch;
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXPWRSW_G1_PHYD			(BIT4 + BIT5)	//00b/x/x/x Port 0 Gen1 TX power supply switch;
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXSW_G1_PHYD			(BIT2 + BIT3)	//11b/x/x/x Port 1 Gen1 Tx output swing control set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXSW_G1_PHYD			(BIT0 + BIT1)	//11b/x/x/x Port 0 Gen1 Tx output swing control set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z261		0x0145	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXPWRSW_G2_PHYD			(BIT6 + BIT7)	//00b/x/x/x Port 1 Gen2 TX power supply switch;
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXPWRSW_G2_PHYD			(BIT4 + BIT5)	//00b/x/x/x Port 0 Gen2 TX power supply switch;
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXSW_G2_PHYD			(BIT2 + BIT3)	//11b/x/x/x Port 1 Gen2 Tx output swing control set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXSW_G2_PHYD			(BIT0 + BIT1)	//11b/x/x/x Port 0 Gen2 Tx output swing control set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z262		0x0146	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXPWRSW_G3_PHYD			(BIT6 + BIT7)	//00b/x/x/x Port 1 Gen3 TX power supply switch;
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXPWRSW_G3_PHYD			(BIT4 + BIT5)	//00b/x/x/x Port 0 Gen3 TX power supply switch;
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_TXSW_G3_PHYD			(BIT2 + BIT3)	//11b/x/x/x Port 1 Gen3 Tx output swing control set
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_TXSW_G3_PHYD			(BIT0 + BIT1)	//11b/x/x/x Port 0 Gen3 Tx output swing control set
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z263		0x0147	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP147B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP147B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCVPWRSW_G1_PHYD			BIT5	//0b/x/x/x Port1 Gen1 RCV power supply switch
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCVPWRSW_G1_PHYD			BIT4	//0b/x/x/x Port0 Gen1 RCV power supply switch
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCVEQ_POW_G1_PHYD			(BIT2 + BIT3)	//00b/x/x/x Port1 Gen1 RCV EQ power consumption tuning
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCVEQ_POW_G1_PHYD			(BIT0 + BIT1)	//00b/x/x/x Port0 Gen1 RCV EQ power consumption tuning
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z264		0x0148	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP148B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP148B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCVPWRSW_G2_PHYD			BIT5	//0b/x/x/x Port1 Gen2 RCV power supply switch
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCVPWRSW_G2_PHYD			BIT4	//0b/x/x/x Port0 Gen2 RCV power supply switch
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCVEQ_POW_G2_PHYD			(BIT2 + BIT3)	//00b/x/x/x Port1 Gen2 RCV EQ power consumption tuning
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCVEQ_POW_G2_PHYD			(BIT0 + BIT1)	//00b/x/x/x Port0 Gen2 RCV EQ power consumption tuning
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z265		0x0149	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP149B7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP149B6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCVPWRSW_G3_PHYD			BIT5	//0b/x/x/x Port1 Gen3 RCV power supply switch
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCVPWRSW_G3_PHYD			BIT4	//0b/x/x/x Port0 Gen3 RCV power supply switch
    #define D15F0_SATA_EPHY_INDEXDATA_FRP01_RCVEQ_POW_G3_PHYD			(BIT2 + BIT3)	//11b/x/x/x Port1 Gen3 RCV EQ power consumption tuning
    #define D15F0_SATA_EPHY_INDEXDATA_FRP00_RCVEQ_POW_G3_PHYD			(BIT0 + BIT1)	//11b/x/x/x Port0 Gen3 RCV EQ power consumption tuning
#define D15F0_SATA_EPHY_INDEXDATA_SATA_EPHY_PHYB_MISC_CTL_Z266		0x014A	//SATA_EPHY_PHYB Miscellaneous Control
    #define D15F0_SATA_EPHY_INDEXDATA_EP14AB7			BIT7	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP14AB6			BIT6	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP14AB5			BIT5	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP14AB4			BIT4	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP14AB3			BIT3	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_EP14AB2			BIT2	//0/x/x/x Reserved
    #define D15F0_SATA_EPHY_INDEXDATA_LP01_TX_ISHORT_EN_PHYD			BIT1	//0b/x/x/x Port1 EIDLE bypass current control
    #define D15F0_SATA_EPHY_INDEXDATA_LP00_TX_ISHORT_EN_PHYD			BIT0	//0b/x/x/x Port0 EIDLE bypass current control
//IDE-IO
#define IDEIO_PATA_PRIMARY_CHN_BUS_MASTER_IDE_CMD		0x00	//PATA Primary Channel Bus Master IDE Command
    #define IDEIO_PRIBMIDEC			0xFF	//0/x/x/x Primary Channel Bus Master IDE Command
#define IDEIO_PATA_PRIMARY_CHN_BUS_MASTER_STA		0x02	//PATA Primary Channel Bus Master Status
    #define IDEIO_PRIBMSTS			0xFF	//0/x/x/x Primary Channel Bus Master Status
#define IDEIO_PATA_PRIMARY_CHN_BUS_MASTER_IDE_DESCRIPTOR_TABLE_POINTER		0x04	//PATA Primary Channel Bus Master IDE Descriptor Table Pointer
    #define IDEIO_PRIBMIDEDTP			0xFFFFFFFF	//0/x/x/x Primary Channel Bus Master IDE Descriptor Table Pointer
#define IDEIO_PATA_SECONDARY_CHN_BUS_MASTER_IDE_CMD		0x08	//PATA Secondary Channel Bus Master IDE Command
    #define IDEIO_SECBMIDEC			0xFF	//0/x/x/x Reserved
#define IDEIO_PATA_SECONDARY_CHN_BUS_MASTER_STA		0x0A	//PATA Secondary Channel Bus Master Status
    #define IDEIO_SECBMSTS			0xFF	//0/x/x/x Reserved
#define IDEIO_PATA_SECONDARY_CHN_BUS_MASTER_IDE_DESCRIPTOR_TABLE_POINTER		0x0C	//PATA Secondary Channel Bus Master IDE Descriptor Table Pointer
    #define IDEIO_SECBMIDEDTP			0xFFFFFFFF	//0/x/x/x Reserved
#define IDEIO_AHCI_INDEX_REG_AHINDEX		0x10	//AHCI Index Register (AHINDEX)
    #define IDEIO_AHINDEX			0xFFFFFFFF	//0/x/x/x Index Register
#define IDEIO_AHCI_INDEX_DATA_REG_AHIDATA		0x14	//AHCI Index Data Register (AHIDATA)
    #define IDEIO_AHIDATA			0xFFFFFFFF	//00000000h/R/x/x Index Data Register
//MSI-XT-MMIO
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_0_MSG_ADR		0x00	//MSI-X Table Structure Entry 0 Message Address
    #define MSIXTMMIO_MSIX0_ADDR			0xFFFFFFFF	//00000000h/x/x/x Message Address for MSI-X Entry 0
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_0_MSG_UPPER_ADR		0x04	//MSI-X Table Structure Entry 0 Message Upper Address
    #define MSIXTMMIO_MSIX0_UADDR			0xFFFFFFFF	//00000000h/x/x/x Message Upper Address for MSI-X Entry 0
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_0_MSG_DATA		0x08	//MSI-X Table Structure entry 0 Message Data
    #define MSIXTMMIO_MSIX0_DATA			0xFFFFFFFF	//00000000h/x/x/x Message Data for MSI-X Entry 0
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_0_MSG_CTL		0x0C	//MSI-X Table Structure Entry 0 Message Control
    #define MSIXTMMIO_MSIX0_RSV			0xFFFFFFFE	//0/x/x/x Reserved
    #define MSIXTMMIO_MSIX0_MASK			BIT0	//1b/x/x/x MSI-X Entry 0 Mask Bit
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_1_MSG_ADR		0x10	//MSI-X Table Structure Entry 1 Message Address
    #define MSIXTMMIO_MSIX1_ADDR			0xFFFFFFFF	//00000000h/x/x/x Message Address for MSI-X Entry 1
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_1_MSG_UPPER_ADR		0x14	//MSI-X Table Structure Entry 1 Message Upper Address
    #define MSIXTMMIO_MSIX1_UADDR			0xFFFFFFFF	//00000000h/x/x/x Message Upper Address for MSI-X Entry 1
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_1_MSG_DATA		0x18	//MSI-X Table Structure Entry 1 Message Data
    #define MSIXTMMIO_MSIX1_DATA			0xFFFFFFFF	//00000000h/x/x/x Message Data for MSI-X Entry 1
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_1_MSG_CTL		0x1C	//MSI-X Table Structure Entry 1 Message Control
    #define MSIXTMMIO_MSIX1_RSV			0xFFFFFFFE	//0/x/x/x Reserved
    #define MSIXTMMIO_MSIX1_MASK			BIT0	//1b/x/x/x MSI-X Entry 1 Mask Bit
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_2_MSG_ADR		0x20	//MSI-X Table Structure Entry 2 Message Address
    #define MSIXTMMIO_MSIX2_ADDR			0xFFFFFFFF	//00000000h/x/x/x Reserved
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_2_MSG_UPPER_ADR		0x24	//MSI-X Table Structure Entry 2 Message Upper Address
    #define MSIXTMMIO_MSIX2_UADDR			0xFFFFFFFF	//00000000h/x/x/x Reserved
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_2_MSG_DATA		0x28	//MSI-X Table Structure Entry 2 Message Data
    #define MSIXTMMIO_MSIX2_DATA			0xFFFFFFFF	//00000000h/x/x/x Reserved
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_2_MSG_ADR_Z1		0x2C	//MSI-X Table Structure Entry 2 Message Address
    #define MSIXTMMIO_MSIX2_RSV			0xFFFFFFFE	//0/x/x/x Reserved
    #define MSIXTMMIO_MSIX2_MASK			BIT0	//1b/x/x/x Reserved
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_3_MSG_ADR		0x30	//MSI-X Table Structure Entry 3 Message Address
    #define MSIXTMMIO_MSIX3_ADDR			0xFFFFFFFF	//00000000h/x/x/x Reserved
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_3_MSG_UPPER_ADR		0x34	//MSI-X Table Structure Entry 3 Message Upper Address
    #define MSIXTMMIO_MSIX3_UADDR			0xFFFFFFFF	//00000000h/x/x/x Reserved
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_3_MSG_DATA		0x38	//MSI-X Table Structure Entry 3 Message Data
    #define MSIXTMMIO_MSIX3_DATA			0xFFFFFFFF	//00000000h/x/x/x Reserved
#define MSIXTMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_3_MSG_ADR_Z1		0x3C	//MSI-X Table Structure Entry 3 Message Address
    #define MSIXTMMIO_MSIX3_RSV			0xFFFFFFFE	//0/x/x/x Reserved
    #define MSIXTMMIO_MSIX3_MASK			BIT0	//1b/x/x/x Reserved
//MSI-XP-MMIO
#define MSIXPMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_0_MSG_ADR		0x00	//MSI-X Table Structure Entry 0 Message Address
    #define MSIXPMMIO_MSIX_PEND0_31_4			0xFFFFFFF0	//0/x/x/x Reserved
    #define MSIXPMMIO_MSIX3_PEND			BIT3	//0/x/x/x Reserved
    #define MSIXPMMIO_MSIX2_PEND			BIT2	//0/x/x/x Reserved
    #define MSIXPMMIO_MSIX1_PEND			BIT1	//0/x/x/x MSI-X Pending Bit for Vector 1
    #define MSIXPMMIO_MSIX0_PEND			BIT0	//0/x/x/x MSI-X Pending Bit for Vector 0
#define MSIXPMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_0_MSG_UPPER_ADR		0x04	//MSI-X Table Structure Entry 0 Message Upper Address
    #define MSIXPMMIO_MSIX_PEND0_63_32			0xFFFFFFFF	//0/x/x/x Reserved
#define MSIXPMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_0_MSG_DATA		0x08	//MSI-X Table Structure Entry 0 Message Data
    #define MSIXPMMIO_MSIX_PEND1_31_0			0xFFFFFFFF	//0/x/x/x Reserved
#define MSIXPMMIO_MSI_X_TABLE_STRUCTURE_ENTRY_0_MSG_CTL		0x0C	//MSI-X Table Structure Entry 0 Message Control
    #define MSIXPMMIO_MSIX_PEND1_63_32			0xFFFFFFFF	//0/x/x/x Reserved
//AHCI-MMIO
#define AHCIMMIO_CAP_HBA_CAPS		0x00	//CAP - HBA Capabilities
    #define AHCIMMIO_S64A			BIT31	//1b/x/x/x Supports 64-bit Addressing (S64A)
    #define AHCIMMIO_SNCQ			BIT30	//1b/x/x/x Supports Native Command Queuing (SNCQ)
    #define AHCIMMIO_SSNTF			BIT29	//1b/x/x/x Supports SNotification Register (SSNTF)
    #define AHCIMMIO_SNPS			BIT28	//1b/x/x/x Supports Mechanical Presence Switch (SMPS)
    #define AHCIMMIO_SSS			BIT27	//1b/x/x/x Supports Staggered Spin-up (SSS)
    #define AHCIMMIO_SALP			BIT26	//1b/x/x/x Supports Aggressive Link Power Management (SALP)
    #define AHCIMMIO_SAL			BIT25	//1b/x/x/x Supports Activity LED (SAL)
    #define AHCIMMIO_SCLO			BIT24	//1b/x/x/x Supports Command List Override (SCLO)
    #define AHCIMMIO_ISS			0xF00000	//3h/x/x/x Interface Speed Support (ISS)
    #define AHCIMMIO_SAM			BIT18	//0/x/x/x Supports AHCI Mode Only (SAM)
    #define AHCIMMIO_SPM			BIT17	//0/x/x/x Supports Port Multiplier (SPM)
    #define AHCIMMIO_FBSS			BIT16	//0/x/x/x FIS-based Switching Supported (FBSS)
    #define AHCIMMIO_PMD			BIT15	//1b/x/x/x PIO Multiple DRQ Block (PMD)
    #define AHCIMMIO_SSC			BIT14	//1b/x/x/x Slumber State Capable (SSC)
    #define AHCIMMIO_PSC			BIT13	//1b/x/x/x Partial State Capable (PSC)
    #define AHCIMMIO_NCS			0x1F00	//1Fh/x/x/x Number of Command Slots (NCS)
    #define AHCIMMIO_CCCS			BIT7	//1b/x/x/x Command Completion Coalescing Supported (CCCS)
    #define AHCIMMIO_EMS			BIT6	//1b/x/x/x Enclosure Management Supported (EMS)
    #define AHCIMMIO_SXS			BIT5	//1b/x/x/x Supports External SATA (SXS)
    #define AHCIMMIO_NP			0x1F	//01h/x/x/x Number of Ports (NP)
#define AHCIMMIO_GHC_GLOBAL_HBA_CTL		0x04	//GHC - Global HBA Control
    #define AHCIMMIO_AE			BIT31	//0/x/x/x AHCI Enable (AE)
    #define AHCIMMIO_MRSM			BIT2	//0/x/x/x MSI Revert to Single Message (MRSM)
    #define AHCIMMIO_IE			BIT1	//0/x/x/x Interrupt Enable (IE)
    #define AHCIMMIO_HR			BIT0	//0/x/x/x HBA Reset (HR)
#define AHCIMMIO_IS_INTR_STA_REG		0x08	//IS - Interrupt Status Register
    #define AHCIMMIO_IPS			0xFFFFFFFF	//0/x/x/x Interrupt Pending Status (IPS)
#define AHCIMMIO_PI_PORTS_IMPLEMENTED		0x0C	//PI - Ports Implemented
    #define AHCIMMIO_PI			0xFFFFFFFF	//00000003h/x/x/x Port Implemented (PI)
#define AHCIMMIO_VS_AHCI_VER		0x10	//VS - AHCI Version
    #define AHCIMMIO_MJR			0xFFFF0000	//0001h/x/x/x Major Version Number (MJR)
    #define AHCIMMIO_MNR			0xFFFF	//0301h/x/x/x Minor Version Number (MNR)
#define AHCIMMIO_CCC_CTL_CMD_COMPLETION_COALESCING_CTL		0x14	//CCC_CTL - Command Completion Coalescing Control
    #define AHCIMMIO_TV			0xFFFF0000	//0001h/x/x/x Timeout Value (TV)
    #define AHCIMMIO_CC			0xFF00	//01h/x/x/x Command Completions (CC)
    #define AHCIMMIO_INT			0xF8	//04h/x/x/x Interrupt (INT)
    #define AHCIMMIO_EN			BIT0	//0/x/x/x Enable (EN)
#define AHCIMMIO_CCC_PORTS_CMD_COMPLETION_COALESCING_PORTS		0x18	//CCC_PORTS - Command Completion Coalescing Ports
    #define AHCIMMIO_PRT			0xFFFFFFFF	//00000000h/x/x/x Ports (PRT)
#define AHCIMMIO_EM_LOC_ENCLOSURE_MANAGEMENT_LOCATION		0x1C	//EM_LOC - Enclosure Management Location
    #define AHCIMMIO_OFST			0xFFFF0000	//0140h/x/x/x Offset (OFST)
    #define AHCIMMIO_SZ			0xFFFF	//0002h/x/x/x Buffer Size (SZ)
#define AHCIMMIO_EM_CTL_ENCLOSURE_MANAGEMENT_CTL		0x20	//EM_CTL - Enclosure Management Control
    #define AHCIMMIO_ATTR_PM			BIT27	//0/x/x/x Port Multiplier Support (ATTR.PM)
    #define AHCIMMIO_ATTR_ALHD			BIT26	//0/x/x/x Activity LED Hardware Driven (ATTR.ALHD)
    #define AHCIMMIO_ATTR_XMT			BIT25	//1b/x/x/x Transmit Only (ATTR.XMT)
    #define AHCIMMIO_ATTR_SMB			BIT24	//1b/x/x/x Single Message Buffer (ATTR.SMB)
    #define AHCIMMIO_SUPP_SGPIO			BIT19	//1b/x/x/x SGPIO Enclosure Management Messages (SUPP.SGPIO)
    #define AHCIMMIO_SUPP_SES2			BIT18	//0/x/x/x SES-2 Enclosure Management Messages (SUPP.SES2)
    #define AHCIMMIO_SUPP_SAFTE			BIT17	//0/x/x/x SAF-TE Enclosure Management Messages (SUPP.SAFTE)
    #define AHCIMMIO_SUPP_LED			BIT16	//1b/x/x/x LED Message Types (SUPP.LED)
    #define AHCIMMIO_CTL_RST			BIT9	//0/x/x/x Reset (CTL.RST)
    #define AHCIMMIO_CTL_TM			BIT8	//0/x/x/x Transmit Message (CTL.TM)
    #define AHCIMMIO_STS_MR			BIT0	//0/x/x/x Message Received (STS.MR)
#define AHCIMMIO_CAP2_HBA_CAPS_EXTENDED		0x24	//CAP2 - HBA Capabilities Extended
    #define AHCIMMIO_DESO			BIT5	//0/x/x/x Device Sleep Can Be Triggerd Only during Slumber Power State (DESO)
    #define AHCIMMIO_SADM			BIT4	//0/x/x/x Support Aggressive Device Sleep Management (SADM) 
    #define AHCIMMIO_SDS			BIT3	//1b/x/x/x Support Device Sleep (SDS)
    #define AHCIMMIO_APST			BIT2	//1b/x/x/x Automatic Partial to Slumber Transitions (APST)
    #define AHCIMMIO_NVMP			BIT1	//0/x/x/x NVMHCI Present (NVMP)
    #define AHCIMMIO_BOH			BIT0	//1b/x/x/x BIOS / OS Handoff (BOH)
#define AHCIMMIO_BOHC_BIOS_OS_HANDOFF_CTL_AND_STA		0x28	//BOHC - BIOS/OS Handoff Control and Status
    #define AHCIMMIO_BB			BIT4	//0/x/x/x BIOS Busy (BB)
    #define AHCIMMIO_OOC			BIT3	//0/x/x/x OS Ownership Change (OOC)
    #define AHCIMMIO_SOOE			BIT2	//0/x/x/x SMI on OS Ownership Change Enable (SOOE)
    #define AHCIMMIO_OOS			BIT1	//0/x/x/x OS Owned Semaphore (OOS)
    #define AHCIMMIO_BOS			BIT0	//0/x/x/x BIOS Owned Semaphore (BOS)
#define AHCIMMIO_PXIS_MG_PORT_X_INTR_STA_MERGE		0xA0	//PxIS_MG - Port x Interrupt Status Merge
    #define AHCIMMIO_P1_IS			BIT3	//0/x/x/x Port 1 IS Merge
    #define AHCIMMIO_P0_IS			BIT2	//0/x/x/x Port 0 IS Merge
    #define AHCIMMIO_GHC_IS1			BIT1	//0b/x/x/x GHC IS 1
    #define AHCIMMIO_GHC_IS0			BIT0	//0b/x/x/x GHC IS 0 (DHRS)
#define AHCIMMIO_PXSACT_PORT_0_SERIAL_ATA_ACTIVE_SCR3_SACTIVE 0xA4 // PxSACT ? Port 0 Serial ATA Active (SCR3: SActive)
    #define AHCIMMIO_P0DS 0xFFFFFFFF // 00000000h/x/x/x Port 0 Device Status (DS)
#define AHCIMMIO_PXSACT_PORT_1_SERIAL_ATA_ACTIVE_SCR3_SACTIVE 0xA8 // PxSACT ? Port 1 Serial ATA Active (SCR3: SActive)	
    #define AHCIMMIO_P1DS 0xFFFFFFFF // 00000000h/x/x/x Port 1 Device Status (DS)
		
#define AHCIMMIO_PXCLB_PORT_X_CMD_LIST_BASE_ADR		0x00	//PxCLB - Port x Command List Base Address
    #define AHCIMMIO_PXCLB			0xFFFFFC00	//0000h/x/x/x Command List Base Address (CLB)
#define AHCIMMIO_PXCLBU_PORT_X_CMD_LIST_BASE_ADR_UPPER_32_BITS		0x04	//PxCLBU - Port x Command List Base Address Upper 32-bits
    #define AHCIMMIO_PXCLBU			0xFFFFFFFF	//0/x/x/x Command List Base Address Upper (CLBU)
#define AHCIMMIO_PXFB_PORT_X_FIS_BASE_ADR		0x08	//PxFB - Port x FIS Base Address
    #define AHCIMMIO_PXFB			0xFFFFFF00	//0000h/x/x/x FIS Base Address (FB)
#define AHCIMMIO_PXFBU_PORT_X_FIS_BASE_ADR_UPPER_32_BITS		0x0C	//PxFBU - Port x FIS Base Address Upper 32-bits
    #define AHCIMMIO_PXFBU			0xFFFFFFFF	//0h/x/x/x FIS Base Address Upper (FBU)
#define AHCIMMIO_PXIS_PORT_X_INTR_STA		0x10	//PxIS - Port x Interrupt Status
    #define AHCIMMIO_PXCPDS			BIT31	//0/x/x/x Cold Port Detect Status (CPDS)
    #define AHCIMMIO_PXTFES			BIT30	//0/x/x/x Task File Error Status (TFES)
    #define AHCIMMIO_PXHBFS			BIT29	//0/x/x/x Host Bus Fatal Error Status (HBFS)
    #define AHCIMMIO_HBDS			BIT28	//0/x/x/x Host Bus Data Error Status (HBDS)
    #define AHCIMMIO_PXIFS			BIT27	//0/x/x/x Interface Fatal Error Status (IFS)
    #define AHCIMMIO_PXINFS			BIT26	//0/x/x/x Interface Non-fatal Error Status (INFS)
    #define AHCIMMIO_PXOFS			BIT24	//0/x/x/x Overflow Status (OFS)
    #define AHCIMMIO_PXIPMS			BIT23	//0/x/x/x Incorrect Port Multiplier Status (IPMS)
    #define AHCIMMIO_PXPRCS			BIT22	//0/x/x/x PhyRdy Change Status (PRCS)
    #define AHCIMMIO_PXDMPS			BIT7	//0/x/x/x Device Mechanical Presence Status (DMPS)
    #define AHCIMMIO_PXPCS			BIT6	//0/x/x/x Port Connect Change Status (PCS)
    #define AHCIMMIO_PXDPS			BIT5	//0/x/x/x Descriptor Processed (DPS)
    #define AHCIMMIO_PXUFS			BIT4	//0/x/x/x Unknown FIS Interrupt (UFS)
    #define AHCIMMIO_PXSDBS			BIT3	//0/x/x/x Set Device Bits Interrupt (SDBS)
    #define AHCIMMIO_PXDSS			BIT2	//0/x/x/x DMA Setup FIS Interrupt (DSS)
    #define AHCIMMIO_PXPSS			BIT1	//0b/x/x/x PIO Setup FIS Interrupt (PSS)
    #define AHCIMMIO_PXDHRS			BIT0	//0b/x/x/x Device to Host Register FIS Interrupt (DHRS)
#define AHCIMMIO_PXIE_PORT_X_INTR_ENABLE		0x14	//PxIE - Port x Interrupt Enable
    #define AHCIMMIO_PXCPDE			BIT31	//0/x/x/x Cold Presence Detect Enable (CPDE)
    #define AHCIMMIO_PXTFEE			BIT30	//0/x/x/x Task File Error Enable (TFEE)
    #define AHCIMMIO_PXHBFE			BIT29	//0/x/x/x Host Bus Fatal Error Enable (HBFE)
    #define AHCIMMIO_PXHBDE			BIT28	//0/x/x/x Host Bus Data Error Enable (HBDE)
    #define AHCIMMIO_PXIFE			BIT27	//0/x/x/x Interface Fatal Error Enable (IFE)
    #define AHCIMMIO_PXINFE			BIT26	//0/x/x/x Interface Non-fatal Error Enable (INFE)
    #define AHCIMMIO_PXOFE			BIT24	//0/x/x/x Overflow Enable (OFE)
    #define AHCIMMIO_PXIPME			BIT23	//0/x/x/x Incorrect Port Multiplier Enable (IPME)
    #define AHCIMMIO_PXPRCE			BIT22	//0/x/x/x PhyRdy Change Interrupt Enable (PRCE)
    #define AHCIMMIO_PXDMPE			BIT7	//0/x/x/x Device Mechanical Presence Enable (DMPE)
    #define AHCIMMIO_PXPCE			BIT6	//0/x/x/x Port Change Interrupt Enable (PCE)
    #define AHCIMMIO_PXDPE			BIT5	//0/x/x/x Descriptor Processed Interrupt Enable (DPE)
    #define AHCIMMIO_PXUFE			BIT4	//0/x/x/x Unknown FIS Interrupt Enable (UFE)
    #define AHCIMMIO_PXSDBE			BIT3	//0/x/x/x Set Device Bits FIS Interrupt Enable (SDBE)
    #define AHCIMMIO_PXDSE			BIT2	//0/x/x/x DMA Setup FIS Interrupt Enable (DSE)
    #define AHCIMMIO_PXPSE			BIT1	//0/x/x/x PIO Setup FIS Interrupt Enable (PSE)
    #define AHCIMMIO_PXDHRE			BIT0	//0/x/x/x Device to Host Register FIS Interrupt Enable (DHRE)
#define AHCIMMIO_PXCMD_PORT_X_CMD_AND_STA		0x18	//PxCMD - Port x Command and Status
    #define AHCIMMIO_PXICC			0xF0000000	//0h/x/x/x Interface Communication Control (ICC)
    #define AHCIMMIO_PXASP			BIT27	//0/x/x/x Aggressive Slumber / Partial (ASP)
    #define AHCIMMIO_PXALPE			BIT26	//0/x/x/x Aggressive Link Power Management Enable (ALPE)
    #define AHCIMMIO_PXDLAE			BIT25	//0/x/x/x Drive LED on ATAPI Enable (DLAE)
    #define AHCIMMIO_PXATAPI			BIT24	//0/x/x/x Device is ATAPI (ATAPI)
    #define AHCIMMIO_PXAPSTE			BIT23	//0/x/x/x Automatic Partial to Slumber Transitions Enabled (APSTE)
    #define AHCIMMIO_PXFBSCP			BIT22	//0/x/x/x FIS-based Switching Capable Port (FBSCP)
    #define AHCIMMIO_PXESP			BIT21	//0/x/x/x External SATA Port (ESP)
    #define AHCIMMIO_PXCPD			BIT20	//0/x/x/x Cold Presence Detection (CPD)
    #define AHCIMMIO_PXMPSP			BIT19	//0/x/x/x Mechanical Presence Switch Attached to Port (MPSP)
    #define AHCIMMIO_PXHPCP			BIT18	//1b/x/x/x Hot Plug Capable Port (HPCP)
    #define AHCIMMIO_PXPMA			BIT17	//0/x/x/x Port Multiplier Attached (PMA)
    #define AHCIMMIO_PXCPS			BIT16	//0/x/x/x Cold Presence State (CPS)
    #define AHCIMMIO_PXCR			BIT15	//0/x/x/x Command List Running (CR)
    #define AHCIMMIO_PXFR			BIT14	//0/x/x/x FIS Receive Running (FR)
    #define AHCIMMIO_PXMPSS			BIT13	//0/x/x/x Mechanical Presence Switch State (MPSS)
    #define AHCIMMIO_PXCCS			0x1F00	//0h/x/x/x Current Command Slot (CCS)
    #define AHCIMMIO_PXFRE			BIT4	//0/x/x/x FIS Receive Enable (FRE)
    #define AHCIMMIO_PXCLO			BIT3	//0/x/x/x Command List Override (CLO)
    #define AHCIMMIO_PXPOD			BIT2	//1b/x/x/x Power On Device (POD)
    #define AHCIMMIO_PXSUD			BIT1	//0/x/x/x Spin-Up Device (SUD)
    #define AHCIMMIO_PXST			BIT0	//0/x/x/x Start (ST)
#define AHCIMMIO_PXTFD_PORT_X_TASK_FILE_DATA		0x20	//PxTFD - Port x Task File Data
    #define AHCIMMIO_PXERR			0xFF00	//0/x/x/x Error (ERR): Contains the latest copy of the task file error register.
    #define AHCIMMIO_PXSTS			0xFF	//7Fh/x/x/x Status (STS)
#define AHCIMMIO_PXSIG_PORT_X_SIGNATURE		0x24	//PxSIG - Port x Signature
    #define AHCIMMIO_PXSIG			0xFFFFFFFF	//FFFFFFFFh/x/x/x Signature (SIG)
#define AHCIMMIO_PXSSTS_PORT_X_SERIAL_ATA_STA_SCR0_SSTA		0x28	//PxSSTS - Port x Serial ATA Status (SCR0: SStatus)
    #define AHCIMMIO_PXIPM			0xF00	//0/x/x/x Interface Power Management (IPM)
    #define AHCIMMIO_PXSPD			0xF0	//0/x/x/x Current Interface Speed (SPD)
    #define AHCIMMIO_PXDET			0xF	//0/x/x/x Device Detection (DET)
#define AHCIMMIO_PXSCTL_PORT_X_SERIAL_ATA_CTL_SCR2_SCTL		0x2C	//PxSCTL - Port x Serial ATA Control (SCR2: SControl)
    #define AHCIMMIO_PXPMP			0xF0000	//0/x/x/x Port Multiplier Port (PMP): This field is not used by AHCI.
    #define AHCIMMIO_PXSPM			0xF000	//0/x/x/x Select Power Management (SPM): This field is not used by AHCI.
    #define AHCIMMIO_PXSIPM			0xF00	//0/x/x/x Interface Power Management Transitions Allowed (IPM)
    #define AHCIMMIO_PXSSPD			0xF0	//0/x/x/x Speed Allowed (SPD)
    #define AHCIMMIO_PXSDET			0xF	//0/x/x/x Device Detection Initialization (DET)
#define AHCIMMIO_PXSERR_PORT_X_SERIAL_ATA_ERR_SCR1_SERR		0x30	//PxSERR - Port x Serial ATA Error (SCR1: SError)
    #define AHCIMMIO_PXDIAG			0xFFFF0000	//0000h/x/x/x Diagnostics  (DIAG)
    #define AHCIMMIO_PXSERR			0xFFFF	//0000h/x/x/x Error (ERR)
#define AHCIMMIO_PXSACT_PORT_X_SERIAL_ATA_ACTIVE_SCR3_SACTIVE		0x34	//PxSACT - Port x Serial ATA Active (SCR3: SActive)
    #define AHCIMMIO_PXDS			0xFFFFFFFF	//00000000h/x/x/x Device Status (DS)
#define AHCIMMIO_PXCI_PORT_X_CMD_ISSUE		0x38	//PxCI - Port x Command Issue
    #define AHCIMMIO_PXCI			0xFFFFFFFF	//00000000h/x/x/x Commands Issued (CI)
#define AHCIMMIO_PXSNTF_PORT_X_SERIAL_ATA_NOTIFICATION_SCR4_SNOTIFICATION		0x3C	//PxSNTF - Port x Serial ATA Notification (SCR4: SNotification)
    #define AHCIMMIO_PXPMN			0xFFFF	//0000h/x/x/x PM Notify (PMN)
#define AHCIMMIO_PXFBS_PORT_X_FIS_BASED_SWITCHING_CTL		0x40	//PxFBS: Port x FIS-based Switching Control
    #define AHCIMMIO_PXDWE			0xF0000	//0/x/x/x Device With Error (DWE)
    #define AHCIMMIO_PXADO			0xF000	//0/x/x/x Active Device Optimization (ADO)
    #define AHCIMMIO_PXDEV			0xF00	//0/x/x/x Device To Issue (DEV)
    #define AHCIMMIO_PXSDE			BIT2	//0/x/x/x Single Device Error (SDE)
    #define AHCIMMIO_PXDEC			BIT1	//0/x/x/x Device Error Clear (DEC)
    #define AHCIMMIO_P_EN			BIT0	//0/x/x/x Enable (EN)
#define AHCIMMIO_PXDEVSLP_PORT_X_DEV_SLEEP		0x44	//PxDEVSLP - Port x Device Sleep
    #define AHCIMMIO_PXDM			0x1E000000	//0/x/x/x DITO Multiplier (DM)
    #define AHCIMMIO_PXDITO			0x1FF8000	//0/x/x/x Device Sleep Idle Timeout (DITO)
    #define AHCIMMIO_PXMDAT			0x7C00	//9h/x/x/x Minimum Device Sleep Assertion Time (MDAT)
    #define AHCIMMIO_PXDETO			0x3FC	//13h/x/x/x Device Sleep Exit Timeout (DETO)
    #define AHCIMMIO_PXDSP			BIT1	//0/x/x/x Device Sleep Present (DSP)
    #define AHCIMMIO_PXADSE			BIT0	//0/x/x/x Aggressive Device Sleep Enable (ADSE)
#endif
