//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		BUSC					**
//**									**
//************************************************************************
//************************************************************************
// This file is auto converted by ZhaoXin Irs2h from IRS_CHX002_D17F0_BUSC_R101(A0).doc(final)MOD_BusCntl.xls
#ifndef _CHX002_D17F0_BUSC_H
#define _CHX002_D17F0_BUSC_H
//D17F0
#define D17F0_VID		0x00	//Vendor ID
    #define D17F0_VENDORID			0xFFFF	//1106h/x/x/x Vendor ID Code
#define D17F0_DID		0x02	//Device ID
    #define D17F0_DEVICEID			0xFFFF	//1001h/x/x/x Device ID
#define D17F0_PCI_CMD		0x04	//PCI Command
    #define D17F0_RPTYERR			BIT6	//0/0/x/x Parity Error Response
    #define D17F0_RSCYC			BIT3	//0/R/x/x Respond To Special Cycle
    #define D17F0_RENMEMX			BIT1	//1b/1/x/x Memory Space Access
    #define D17F0_RENIO1			BIT0	//1b/1/x/x I/O Space Access
#define D17F0_PCI_STA		0x06	//PCI Status
    #define D17F0_PERRS			BIT15	//0/0/x/x Detected Parity Error
    #define D17F0_SERRS			BIT14	//0/0/x/x Signaled System Error (SERR# Asserted)
    #define D17F0_MABORTS			BIT13	//0/0/x/x Received Master-Abort (Except Special Cycle)
    #define D17F0_TABORTR			BIT12	//0/0/x/x Received Target-Abort
    #define D17F0_TABORTS			BIT11	//0/0/x/x Target-Abort Assertion
    #define D17F0_DEVS			(BIT9 + BIT10)	//01b/R/x/x DEVSEL# Timing
    #define D17F0_DPERR			BIT8	//0/0/x/x Master Data Parity Error 
    #define D17F0_FBACKS			BIT7	//0/0/x/x Capable of Accepting Fast Back-to-back as A Target
    #define D17F0_DNP			0x7F	//10h/R/x/x Reserved (Do Not Program)
#define D17F0_REV_ID		0x08	//Revision ID
    #define D17F0_REVISIONID			0xFF	//03h/R/x/x Revision ID
#define D17F0_CLASS_CODE		0x09	//Class Code
    #define D17F0_CLASS			0xFFFFFF	//060100h/x/x/x Class Code
#define D17F0_HEADER_TYPE		0x0E	//Header Type
    #define D17F0_HT			0xFF	//80h/x/x/x Header Type 
#define D17F0_BUILT_IN_SELF_TEST_BIST		0x0F	//Built In Self Test (BIST)
#define D17F0_SVID		0x2C	//Subsystem Vendor ID
    #define D17F0_SVI			0xFFFF	//1106h/x/x/x Subsystem Vendor ID
#define D17F0_SUBSYSTEM_ID		0x2E	//Subsystem ID
    #define D17F0_SID2			0xFFFF	//8410h/x/x/x Subsystem ID
#define D17F0_PM_CAPS_POINTER		0x34	//Power Management Capabilities Pointer
    #define D17F0_PMC			0xFF	//C0h/R/x/x Power Management Capabilities Pointer
#define D17F0_ISA_BUS_CTL		0x40	//ISA Bus Control
    #define D17F0_RCMDLY			BIT7	//0/0/x/x Extra / Normal ISA Command Delay ((Random))
    #define D17F0_RIORCV			BIT6	//0/*/x/x I/O Recovery Time ((Random))
    #define D17F0_RESERVED			BIT5	//0/x/x/x Reserved
    #define D17F0_RROMW			BIT4	//0/0/x/x ROM Write
    #define D17F0_DMA8EN			BIT3	//0/0/x/x Double DMA Clock ((Random))
    #define D17F0_EISAXT			BIT2	//0/*/x/x 4D0 / 4D1 Support
    #define D17F0_RDMEGAS			BIT1	//0/0/x/x MEGA Cells (DMAC, INTC and TMRC) Shadow Register Read
    #define D17F0_ENBCLK4M			BIT0	//0/0/x/x BCLK (Bus Clock) = PCLK (PCI Bus Clock) / 2
#define D17F0_ROM_DECODE_CTL		0x41	//ROM Decode Control
    #define D17F0_EROMS0E			BIT7	//1b/x/x/x For Memory Address 000E0000h-000EFFFFh
    #define D17F0_EROMSF0			BIT6	//1b/x/x/x For Memory Address FFF00000h-FFF7FFFFh and FFB00000h-FFB7FFFFh ,FDF00000h-FDF7FFFFh and FDB00000h-FDB7FFFFh
    #define D17F0_EROMSE8			BIT5	//1b/x/x/x For Memory Address FFE80000h-FFEFFFFFh and FFA80000h-FFAFFFFFh, FDE80000h-FDEFFFFFh and FDA80000h-FDAFFFFFh
    #define D17F0_EROMSE0			BIT4	//1b/x/x/x For Memory Address FFE00000h-FFE7FFFFh and FFA00000h-FFA7FFFFh ,FDE00000h-FDE7FFFFh and FDA00000h-FDA7FFFFh
    #define D17F0_EROMSD8			BIT3	//1b/x/x/x For Memory Address FFD80000h-FFDFFFFFh and FF980000h-FF9FFFFFh ,FDD80000h-FDDFFFFFh and FD980000h-FD9FFFFFh
    #define D17F0_EROMSD0			BIT2	//1b/x/x/x For Memory Address FFD00000h-FFD7FFFFh and FF900000h-FF97FFFFh ,FDD00000h-FDD7FFFFh and FD900000h-FD97FFFFh
    #define D17F0_EROMSC8			BIT1	//1b/x/x/x For Memory Address FFC80000h-FFCFFFFFh and FF880000h-FF8FFFFFh ,FDC80000h-FDCFFFFFh and FD880000h-FD8FFFFFh
    #define D17F0_EROMSC0			BIT0	//1b/x/x/x For Memory Address  FFC00000h-FFC7FFFFh and FF800000h-FF87FFFFh , FDC00000h-FDC7FFFFh and FD800000h-FD87FFFFh
#define D17F0_LINE_BUFFER_CTL		0x42	//Line Buffer Control
    #define D17F0_ENLBUF			BIT7	//0/*/*/x DMA Line Buffer((Random))
    #define D17F0_GINTREN			BIT6	//0/*/*/x Gate INTR Assertion Until Line Buffer Flush Is Complete ((Random))
    #define D17F0_FLUSHEN			BIT5	//0/*/*/x IRQ Flush Line Buffer When No DMA is Granted ((Random))
    #define D17F0_RBRSTRD			BIT4	//0/*/*/x Uninterruptible Burst Read ((Random))
    #define D17F0_ENGSIRQ			BIT3	//0/0/x/x Gate Serial IRQ Inputs Until Line Buffer Flush Is Complete ((Random))
    #define D17F0_ENFTIFSH			BIT2	//0/*/*/x IRQ Flush Line Buffer Even When DMA Is Granted ((Random))
    #define D17F0_SMB_MODE			(BIT0 + BIT1)	//00b/0/x/x SMBus Test Mode Select
#define D17F0_DELAY_TRANSACTION_CTL		0x43	//Delay Transaction Control
    #define D17F0_TM17C			BIT7	//0/x/x/x Reserved
    #define D17F0_RESERVED_Z1			BIT6	//0/x/x/x Reserved
    #define D17F0_TMRMODE			BIT4	//0/x/x/x Reserved
    #define D17F0_RENDTXA			BIT3	//1b/1/x/x Delayed Transactions (PCI Spec Rev 2.1) ((Random))
    #define D17F0_RENPW			BIT2	//0/0/x/x Delayed Transaction - Posted Write Only ((Random))
    #define D17F0_ENWBTO			BIT1	//0/*/1/x Write Delay Transaction Timeout Timer ((Random))
    #define D17F0_ENRBTO			BIT0	//0/*/1/x Read Delay Transaction Timeout Timer((Random))
#define D17F0_PCI_PNP_INTR_ROUTING_INTE_INTF		0x44	//PCI PnP Interrupt Routing  INTE#, INTF#
    #define D17F0_PCII1			0xF0	//0/x/x/x PCI INTF# Routing 
    #define D17F0_PCII2			0xF	//0/x/x/x PCI INTE# Routing
#define D17F0_PCI_PNP_INTR_ROUTING_INTG_INTH		0x45	//PCI PnP Interrupt Routing  INTG#, INTH#
    #define D17F0_PCIINT0			0xF0	//0/x/x/x PCI INTH# Routing
    #define D17F0_PCIINT1			0xF	//0/x/x/x PCI INTG# Routing
#define D17F0_PCI_INT_H_E_UART_MULTX_SEL_INTR_CTL		0x46	//PCI INT[H:E]# UART Multiplex Select Interrupt Control
    #define D17F0_RX46D7			BIT7	//1b/1/x/x SERIRQ Pull-up Enable Signal
    #define D17F0_RENCOM			BIT6	//0/x/x/x Reserved
    #define D17F0_ENSPIP80			BIT5	//0/0/x/x Control the Destination of IO Port 0x80/0x84/0x88 ((Random))
    #define D17F0_ENEXPINTR			BIT4	//1b/1/x/x PCI INT Sharing Control
    #define D17F0_PCIINT6			BIT3	//0/x/x/x Invert PCI INTH# Trigger
    #define D17F0_PCIINT5			BIT2	//0/x/x/x Invert PCI INTG# Trigger
    #define D17F0_PCIINT4			BIT1	//0/x/x/x Invert PCI INTF# Trigger
    #define D17F0_PCIINT3			BIT0	//0/x/x/x Invert PCI INTE# Trigger
#define D17F0_PATA_PAD_CTL		0x47	//PATA PAD Control
    #define D17F0_RX47D7			BIT7	//0/0/x/x Control of VRDSLP Pull-up Control
    #define D17F0_CEC_DEC			BIT6	//0/x/x/x Reserved
    #define D17F0_HOST_DEBMODE			(BIT4 + BIT5)	//0/0/x/x SMB Master De-bounce Mode Select
#define D17F0_APIC_FSB_DATA_CTL		0x48	//APIC FSB Data Control
    #define D17F0_RFSBLDW			BIT7	//0/0/x/x FSB Fixed at Low DW
    #define D17F0_COMPAD_SEL			BIT5	//0/x/x/x Reserved
    #define D17F0_UART_SEL			BIT4	//0/x/x/x Reserved
    #define D17F0_EN_VART3			BIT3	//0/x/x/x Reserved
    #define D17F0_EN_VART2			BIT2	//0/x/x/x Reserved
    #define D17F0_EN_VART1			BIT1	//0/x/x/x PCI UART 1 Enable
    #define D17F0_EN_VART0			BIT0	//0/x/x/x PCI UART 0 Enable
#define D17F0_SM_PERIPHERAL_DEV_CTL		0x49	//SM Peripheral Device Control
    #define D17F0_RVSERR2PMU			BIT7	//0/x/x/x Reserved
    #define D17F0_RSMGM			BIT6	//0/x/x/x Reserved
    #define D17F0_RCLNGIRQ			BIT5	//1b/1/x/x Gated IRQ before SM Buffer Clean ((Random))
    #define D17F0_RSTEP			BIT4	//0/0/x/x PCIM Address Stepping ((Random))
    #define D17F0_RMWS			BIT3	//0/0/x/x PCIM Wait State ((Random))
    #define D17F0_RWSC4INTR			BIT2	//0/0/x/x WSC Mask Off INTR ((Random))
    #define D17F0_RP1OFF			BIT1	//0/x/x/x Reserved
    #define D17F0_RCCAOFF			BIT0	//0/x/x/x Reserved
#define D17F0_LPC_FW_MEM_CTL_1		0x4A	//LPC Firmware Memory Control 1
    #define D17F0_RFIRMBA_23_17			0xFE	//0/x/x/x LPC Firmware Memory Base Address [23:17] ((Random))
    #define D17F0_RLFIRMPID			BIT0	//0/0/x/x LPC Firmware Memory Programmable IDSEL ((Random))
#define D17F0_LPC_FW_MEM_CTL_2		0x4B	//LPC Firmware Memory Control 2
    #define D17F0_RFIRMRD16_NEW			BIT7	//0/0/x/x Firmware Read Cycle New Hit Method
    #define D17F0_RFIRMMSK_2_0			(BIT4 + BIT5 + BIT6)	//000b/x/x/x LPC Firmware Memory Base Address Mask ((Random))
    #define D17F0_RFIRMID_3_0			0xF	//0/0/x/x LPC Firmware Memory IDSEL Value ((Random))
#define D17F0_IDE_INTR_SEL		0x4C	//IDE Interrupt Select
    #define D17F0_IORCVS_1_0			(BIT6 + BIT7)	//00b/*/x/x I/O Recovery Time Select ((Random))
    #define D17F0_TESTFRM			BIT5	//0/x/x/x Reserved
    #define D17F0_TESTDEV			BIT4	//0/x/x/x Reserved
    #define D17F0_RIBSEL_1_0			(BIT2 + BIT3)	//01b/x/x/x Reserved
    #define D17F0_RIASEL_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
#define D17F0_MISC_CTL		0x4D	//Miscellaneous Control
    #define D17F0_ENFIRMEM16B			BIT7	//0/0/x/x LPC Firmware Memory 16 Bytes Burst Read ((Random))
    #define D17F0_ENFIRMEM4B			BIT6	//0/0/x/x LPC Firmware Memory 4 Bytes Burst Read / Write Access ((Random))
    #define D17F0_PCIINT7			BIT5	//0/0/x/x Firmware Memory Burst Detection
    #define D17F0_PCIINT8			BIT4	//0/0/x/x LPC Firmware Memory IDSEL Value ((Random))
    #define D17F0_FIX_EXINT_EN			BIT3	//0/0/x/x Enable Fixed Path of External Interrupt Delivery Only in APIC IRQ0 When the Interrupt Controller Has Not Been Masked Yet
    #define D17F0_RSHSIRQ			BIT2	//0/0/x/x Serial IRQs Always be Shared in APIC Mode
    #define D17F0_RDISGROM			BIT1	//0/0/x/x LPC Firmware Memory Cycle Configuration ((Random))
    #define D17F0_ENTPM			BIT0	//1b/1/x/x TPM Function Enable Bit
#define D17F0_INTERNAL_RTC_TEST_MODE_AND_EXTRA_FEATURE_CTL		0x4E	//Internal RTC Test Mode and Extra Feature Control
    #define D17F0_ENHRXLK			BIT7	//0/0/x/x RTC High Bank Rx3F-38 R/W Protect
    #define D17F0_ENLRXLK			BIT6	//0/0/x/x RTC Low Bank Rx3F-38 R/W Protect
    #define D17F0_RESERVED_Z2			BIT5	//0/x/x/x Reserved
    #define D17F0_RSH70ST			BIT4	//0/x/x/x RTC Last Write Status
    #define D17F0_ENEXRTC			BIT3	//0/*/x/x Enable RTC Port 74/75
    #define D17F0_RTCRSTEN			BIT2	//0/x/x/x Reserved
    #define D17F0_RTCACCEN			BIT1	//0/x/x/x Reserved
    #define D17F0_RTCTSTEN			BIT0	//0/x/x/x Reserved
#define D17F0_PCI_RESET_CTL_AND_KBDC_RESET_CTL		0x4F	//PCI Reset Control and KBDC reset control
    #define D17F0_RSWKRST			BIT3	//0/x/x/x Software KBDC Reset
    #define D17F0_RGATESWPRST			(BIT1 + BIT2)	//0/x/x/x Reserved
    #define D17F0_RSWPRST			BIT0	//0/0/x/x Software PCI Reset
#define D17F0_FUN_CTL_1		0x50	//Function Control 1
    #define D17F0_D15F2ENSATA			BIT7	//1b/x/x/x Reserved
    #define D17F0_D15F1ENSATA			BIT6	//1b/x/x/x Reserved
    #define D17F0_ENUSB2			BIT5	//0/x/x/x Device 16 Function 1 (USB 1.1 UHCI Port 2-3) ((USB 2))
    #define D17F0_ENUSB1			BIT4	//0/x/x/x Device 16 Function 0 (USB 1.1 UHCI Port 0-1) ((USB 1))
    #define D17F0_D15F0ENSATA			BIT3	//1b/x/x/x Device 15 Function 0 (SATA/EIDE)
    #define D17F0_ENUSB3			BIT2	//0/x/x/x Device 14 Function 0(USB2.0)
    #define D17F0_ENUSB5			BIT1	//0/x/x/x Reserved
    #define D17F0_D21ENSATA			BIT0	//1b/x/x/x Reserved
#define D17F0_FUN_CTL_2		0x51	//Function Control 2
    #define D17F0_SDC1			BIT7	//0/x/x/x Reserved
    #define D17F0_ESERVED			BIT6	//0/x/x/x Reserved
    #define D17F0_ENUSB4			BIT5	//0/x/x/x Reserved
    #define D17F0_ENSD			BIT4	//1b/1b/x/x Reserved
    #define D17F0_RRTC			BIT3	//1b/1b/x/x Internal RTC
    #define D17F0_RPS2			BIT2	//1b/1b/x/x Internal PS2 Mouse
    #define D17F0_ENKBCCFG			BIT1	//0/0/x/x Internal Keyboard Controller Configuration
    #define D17F0_RKBC			BIT0	//1b/1b/x/x Internal Keyboard Controller
#define D17F0_SERIAL_IRQ_PCI_DMA_CTL_AND_LPC_CTL		0x52	//Serial IRQ, PCI / DMA Control and LPC Control
    #define D17F0_ENMDCHG			BIT7	//0/x/x/x ENMDCHG is for SERINT to Handle Mode Change
    #define D17F0_ENSWBABT			BIT6	//0/0/x/x LPC Short Wait Abort
    #define D17F0_ENSTRW			BIT5	//0/0/x/x LPC Frame Wait State
    #define D17F0_ENDISSTI			BIT4	//0/0/x/x Serial IRQ Stop to Start Frame Wait State
    #define D17F0_ENSIRQ			BIT3	//0/*/x/x Serial IRQ
    #define D17F0_ENQMODE			BIT2	//0/0/x/x Serial IRQ Quiet Mode ((Random))
    #define D17F0_RSTPLS_1_0			(BIT0 + BIT1)	//00b/*/x/x Serial IRQ Start-Frame Width ((Random))
#define D17F0_PC_PCI_DMA_CTL		0x53	//PC / PCI DMA Control
    #define D17F0_ENPDA			BIT7	//0/x/x/x Reserved
    #define D17F0_ENPDCH7			BIT6	//0/0/x/x DMA Channel 7 for PC/PCI DMA
    #define D17F0_ENPDCH6			BIT5	//0/0/x/x DMA Channel 6 for PC/PCI DMA
    #define D17F0_ENPDCH5			BIT4	//0/0/x/x DMA Channel 5 for PC/PCI DMA
    #define D17F0_ENPDCH3			BIT3	//0/0/x/x DMA Channel 3 for PC/PCI DMA
    #define D17F0_ENPDCH2			BIT2	//0/0/x/x DMA Channel 2 for PC/PCI DMA
    #define D17F0_ENPDCH1			BIT1	//0/0/x/x DMA Channel 1 for PC/PCI DMA
    #define D17F0_ENPDCH0			BIT0	//0/0/x/x DMA Channel 0 for PC/PCI DMA
#define D17F0_PCI_BUS_AND_CPU_IF_CTL		0x54	//PCI Bus and CPU Interface Control
    #define D17F0_FPGA_TIMER_DIV_REG			BIT5	//0/x/x/x Control RTC/TRMC/HPET host clock in FPGA
    #define D17F0_EN_PCIDBG			BIT4	//0/x/x/x Reserved
    #define D17F0_INTAA			BIT3	//0/x/x/x Invert PCI INTA# Trigger
    #define D17F0_INTAB			BIT2	//0/x/x/x Invert PCI INTB# Trigger
    #define D17F0_INTAC			BIT1	//0/x/x/x Invert PCI INTC# Trigger
    #define D17F0_INTAD			BIT0	//0/x/x/x Invert PCI INTD# Trigger
#define D17F0_PCI_PNP_INTR_ROUTING_1		0x55	//PCI PnP Interrupt Routing 1
    #define D17F0_EXINT_EN11			0xF0	//0/x/x/x PCI INTA# Routing (Refer to CNDJ6nn5us4RjIIAqgBLqQsCAAAACAAAAA4AAABfAFIAZQBmADQANQAzADEANAA3ADEAMQA3AAAA
    #define D17F0_EXINT_EN			BIT3	//0/0/x/x Enable External General Interrupt from GPIO88 
    #define D17F0_EXINT_SEL_2_0			(BIT0 + BIT1 + BIT2)	//000b/0/x/x External General Interrupt Routing Selection
#define D17F0_PCI_PNP_INTR_ROUTING_2		0x56	//PCI PnP Interrupt Routing 2
    #define D17F0_EXINT_EN1			0xF0	//0/x/x/x PCI INTC# Routing
    #define D17F0_EXINT_EN2			0xF	//0/x/x/x PCI INTB# Routing
#define D17F0_PCI_PNP_INTR_ROUTING_3		0x57	//PCI PnP Interrupt Routing 3
    #define D17F0_EXINT_EN3			0xF0	//0/x/x/x PCI INTD# Routing
    #define D17F0_EXINT_EN4			0xF	//0/x/x/x Reserved
#define D17F0_SOUTH_MODULE_MISC_CTL_1		0x58	//South Module Miscellaneous Control 1
    #define D17F0_ENPDB			BIT7	//0/x/x/x Reserved
    #define D17F0_ENIAPIC			BIT6	//0/*/x/x Internal APIC
    #define D17F0_ENINTC33			BIT5	//1b/1/x/x South Module Interrupt Cycles Sync. with 33 MHz Clock
    #define D17F0_ENPOSDC			BIT4	//0/0/x/x South Module PCI Cycle Decode
    #define D17F0_ENRTCHBK			BIT3	//0/0/x/x RTC High Bank Access
    #define D17F0_ENRX32WP			BIT2	//0/0/x/x RTC Rx32 Write Protect
    #define D17F0_ENRX0DWP			BIT1	//0/*/x/x RTC Rx0D Write Protect
    #define D17F0_ENRX32MP			BIT0	//0/0/x/x RTC Rx32 Map to Century Byte
#define D17F0_SOUTH_MODULE_MISC_CTL_2		0x59	//South Module Miscellaneous Control 2
    #define D17F0_DISLPCMEM1			BIT7	//0/*/x/x LPC/SPI Memory Space
    #define D17F0_ENNBSERR			BIT6	//0/x/x/x Reserved
    #define D17F0_ENLPCRTC			BIT5	//0/0/x/x LPC RTC
    #define D17F0_ENLPCKB			BIT4	//0/0/x/x LPC Keyboard
    #define D17F0_ENLPCMC			BIT3	//0/0/x/x Port 62h / 66h (MCCS#) to LPC
    #define D17F0_ENMCCS			BIT2	//0/0/x/x Port 62h / 66h (MCCS#) Decode
    #define D17F0_ENA20MA			BIT1	//0/0/x/x Mask A20M# Active
    #define D17F0_ENPARNMI			BIT0	//0/0/x/x NMI on PCI Parity Error
#define D17F0_DMA_BANDWIDTH_CTL		0x5A	//DMA Bandwidth Control
    #define D17F0_ENSPDMA7			BIT7	//0/0/1/x DMA Channel 7 Bandwidth ((Random))
    #define D17F0_ENSPDMA6			BIT6	//0/0/1/x DMA Channel 6 Bandwidth ((Random))
    #define D17F0_ENSPDMA5			BIT5	//0/0/1/x DMA Channel 5 Bandwidth ((Random))
    #define D17F0_ENFSDMASM			BIT4	//0/0/1/x DMA Single Transfer Mode Bandwidth ((Random))
    #define D17F0_ENSPDMA3			BIT3	//0/0/1/x DMA Channel 3 Bandwidth ((Random))
    #define D17F0_ENSPDMA2			BIT2	//0/0/1/x DMA Channel 2 Bandwidth ((Random))
    #define D17F0_ENSPDMA1			BIT1	//0/0/1/x DMA Channel 1 Bandwidth ((Random))
    #define D17F0_ENSPDMA0			BIT0	//0/0/1/x DMA Channel 0 Bandwidth ((Random))
#define D17F0_MISC_CTL_Z1		0x5B	//Miscellaneous Control
    #define D17F0_ENFIRMIT			BIT7	//0/0/x/x LPC Firmware Memory Read TRDY 1 Wait State ((Random))
    #define D17F0_ENLPCP80			BIT6	//1b/1/x/x Destination Selection of IO Port 0x80/0x84/0x88 ((Random))
    #define D17F0_ENDYPDGNT			BIT5	//0/0/x/x PCI/DMA Memory Cycles Output to PCI Bus
    #define D17F0_EN_APIC_GATE			BIT4	//0/*/1/1 APIC Clock Gating Enable
    #define D17F0_DEASSERT_DIS			BIT3	//0/*/x/x Bypass APIC De-assert Message
    #define D17F0_MODE_LDT			BIT2	//0/x/x/x Reserved
    #define D17F0_ENIRQEH			BIT1	//0/*/x/x Reserved
    #define D17F0_ENGF0CLK			BIT0	//1b/1/1/1 Dynamic Clock Stop
#define D17F0_PCS_0_IO_PORT_ADR		0x5C	//PCS 0 I/O Port Address
    #define D17F0_PCS0BA_15_0			0xFFFF	//0/x/x/x PCS 0 I/O Port Address
#define D17F0_PCS_1_IO_PORT_ADR		0x5E	//PCS 1 I/O Port Address
    #define D17F0_PCS1BA_15_0			0xFFFF	//0/x/x/x PCS 1 I/O Port Address
#define D17F0_PCS_2_IO_PORT_ADR		0x60	//PCS 2 I/O Port Address
    #define D17F0_PCS2BA_15_0			0xFFFF	//0/x/x/x PCS 2 I/O Port Address
#define D17F0_PCS_3_IO_PORT_ADR		0x62	//PCS 3 I/O Port Address
    #define D17F0_PCS3BA_15_0			0xFFFF	//0/x/x/x PCS 3 I/O Port Address
#define D17F0_PCS_IO_PORT_ADR_MASK		0x64	//PCS I/O Port Address Mask
    #define D17F0_PCS3MK_3_0			0xF000	//0000b/x/x/x PCS 3 I/O Port Address Mask 3-0
    #define D17F0_PCS2MK_3_0			0xF00	//0000b/x/x/x PCS 2 I/O Port Address Mask 3-0
    #define D17F0_PCS1MK_3_0			0xF0	//0000b/x/x/x PCS 1 I/O Port Address Mask 3-0
    #define D17F0_PCS0MK_3_0			0xF	//0000b/x/x/x PCS 0 I/O Port Address Mask 3-0
#define D17F0_PCS_CTL		0x66	//PCS Control
    #define D17F0_ENIPCS3			BIT7	//0/x/x/x Reserved
    #define D17F0_ENIPCS2			BIT6	//0/x/x/x Reserved
    #define D17F0_ENIPCS1			BIT5	//0/x/x/x Reserved
    #define D17F0_ENIPCS0			BIT4	//0/x/x/x Reserved
    #define D17F0_ENPCS3			BIT3	//0/0/x/x PCS 3
    #define D17F0_ENPCS2			BIT2	//0/0/x/x PCS 2
    #define D17F0_ENPCS1			BIT1	//0/0/x/x PCS 1
    #define D17F0_ENPCS0			BIT0	//0/0/x/x PCS 0
#define D17F0_OUTPUT_AND_PCS_CTL		0x67	//Output and PCS Control
    #define D17F0_PCS3			BIT7	//0/x/x/x PCS 3 IO Cycle is Directed To
    #define D17F0_PCS2			BIT6	//0/0/x/x PCS 2 IO Cycle is Directed To
    #define D17F0_PCS1			BIT5	//0/0/x/x PCS 1 IO Cycle is Directed To
    #define D17F0_PCS0			BIT4	//0/0/x/x PCS 0 IO Cycle is Directed To
    #define D17F0_SPI_INTER			BIT3	//0/0/x/x SPI External Interrupt Status
    #define D17F0_VTFERR			BIT2	//1b/1/x/x FERR# Voltage
    #define D17F0_VPI2SB_NMISLVEN			BIT0	//0/0/x/x VPI2SB Slave NMI Enable
#define D17F0_HPET_CTL		0x68	//HPET Control
    #define D17F0_ENHPET			BIT7	//0/x/x/x High Precision Event Timers
    #define D17F0_RESERVED_Z3			(BIT5 + BIT6)	//0/x/x/x Reserved
    #define D17F0_HPETINT			BIT4	//0/x/x/x HPET Interrupt Polarity Configure
    #define D17F0_ENWDEC3			BIT3	//0/0/x/x PCS 3 256-Byte IO Range Decoding Enable
    #define D17F0_ENWDEC2			BIT2	//0/0/x/x PCS 2 256-Byte IO Range Decoding Enable
    #define D17F0_ENWDEC1			BIT1	//0/0/x/x PCS 1 256-Byte IO Range Decoding Enable
    #define D17F0_ENWDEC0			BIT0	//0/0/x/x PCS 0 256-Byte IO Range Decoding Enable
#define D17F0_HPET_ADR		0x69	//HPET Address
    #define D17F0_HPETBA			0xFFFFFC	//0/x/x/x HPET Memory Base Address [31:10]
    #define D17F0_BATSRAM_CS_BD			BIT1	//1b/x/x/0 Reserved
    #define D17F0_ENBATSRAM			BIT0	//0/0/x/x Reserved
#define D17F0_ISA_POSITIVE_DECODING_CTL_1		0x6C	//ISA Positive Decoding Control 1
    #define D17F0_IXD_DEC			BIT7	//0/0/x/x On-board I/O (Ports 00-FFh) Positive Decoding
    #define D17F0_MSS_DEC			BIT6	//0/0/x/x Microsoft Sound System I/O Port Positive Decoding
    #define D17F0_MSSSEL_1_0			(BIT4 + BIT5)	//00b/0/x/x Microsoft Sound System I/O Decode Range
    #define D17F0_APIC_DEC			BIT3	//0/0/x/x APIC Positive Decoding
    #define D17F0_ROM_DEC			BIT2	//0/0/x/x ROM Positive Decoding
    #define D17F0_PCS1DEC			BIT1	//0/0/x/x PCS1# Positive Decoding
    #define D17F0_PCS0DEC			BIT0	//0/0/x/x PCS0# Positive Decoding
#define D17F0_ISA_POSITIVE_DECODING_CTL_2		0x6D	//ISA Positive Decoding Control 2
    #define D17F0_FDC_DEC			BIT7	//0/0/x/x FDC Positive Decoding
    #define D17F0_LPT_DEC			BIT6	//0/0/x/x LPT Positive Decoding
    #define D17F0_LPTSEL_1_0			(BIT4 + BIT5)	//00b/0/x/x LPT Decode Range
    #define D17F0_GAME_DEC			BIT3	//0/0/x/x Game Port Positive Decoding
    #define D17F0_MIDI_DEC			BIT2	//0/0/x/x MIDI Positive Decoding
    #define D17F0_MIDISEL_1_0			(BIT0 + BIT1)	//00b/0/x/x MIDI Decode Range
#define D17F0_MISC_CTL_2		0x6E	//Miscellaneous Control 2
    #define D17F0_GLOBAL_IO_DEC			BIT7	//0/x/x/x Global Reserved IO Port Direction Select
    #define D17F0_RESERVED_Z4			0x7C	//0/x/x/x Reserved
    #define D17F0_RSPIHIT_NEW			BIT1	//0/*/x/x Use New SPI Hit Mechanism
    #define D17F0_ENLPCEC			BIT0	//0/0/x/x Control the Destination of IO Port 68/6C/6A/6Eh
#define D17F0_ISA_POSITIVE_DECODING_CTL_4		0x6F	//ISA Positive Decoding Control 4
    #define D17F0_SPI_DEC			BIT7	//0/0/x/x SPI Positive Decoding Control ((Random))
    #define D17F0_LPCTPM_DEC			BIT6	//0/0/x/x LPC TPM Positive Decoding ((Random))
    #define D17F0_PCS2S3_DEC			BIT5	//0/0/x/x PCS2# and PCS3# Positive Decoding
    #define D17F0_CF9_DEC			BIT4	//0/0/x/x I/O Port 0CF9h Positive Decoding
    #define D17F0_PDC_SEL			BIT3	//0/0/x/x Floppy Disk Controller (FDC) Decoding Range
    #define D17F0_SB_DEC			BIT2	//0/0/x/x Sound Blaster Positive Decoding
    #define D17F0_SBDR			(BIT0 + BIT1)	//00b/0/x/x Sound Blaster Decode Range
#define D17F0_SVID_BACKDOOR_REGS		0x70	//Subsystem Vendor ID Backdoor Registers
    #define D17F0_SVID_Z1			0xFFFF	//1106h/x/x/x Subsystem Vendor ID (Rx2D-2C) Back Door
#define D17F0_SUBSYSTEM_ID_BACKDOOR_REGS		0x72	//Subsystem ID Backdoor Registers
    #define D17F0_SID			0xFFFF	//8410h/x/x/x Subsystem ID (Rx2F-2E) Back Door
#define D17F0_LPC_ROM_MEM_ADR_RANGE		0x75	//LPC ROM Memory Address Range
    #define D17F0_RFIRMALLID			0xF0	//0/0/x/x Firmware Memory IDSEL for All Memory Range ((Random))
    #define D17F0_EROMS70			BIT3	//1b/1/x/x Select LPC ROM Memory Address Range 1 {FF700000h-FF7FFFFFh, FF300000h-FF3FFFFFh}
    #define D17F0_EROMS60			BIT2	//1b/1/x/x Select LPC ROM Memory Address Range 2 {FF600000h-FF6FFFFFh, FF200000h-FF2FFFFFh}
    #define D17F0_EROMS50			BIT1	//1b/1/x/x Select LPC ROM Memory Address Range 3 {FF500000h-FF5FFFFFh, FF100000h-FF1FFFFFh}
    #define D17F0_EROMS40			BIT0	//1b/1/x/x Select LPC ROM Memory Address Range 4 {FF400000h-FF4FFFFFh, FF000000h-FF0FFFFFh}
#define D17F0_FW_MEM_IDSEL_1		0x76	//Firmware Memory IDSEL 1
    #define D17F0_EROMS50ID			0xF0	//0000b/0/x/x Firmware Memory IDSEL for the Two 1MB Memory Ranges {FF500000h-FF5FFFFFh, FF100000h-FF1FFFFFh} ((Random))
    #define D17F0_EROMS40ID			0xF	//0000b/0/x/x Firmware Memory IDSEL for the Two 1MB Memory Ranges {FF400000h-FF4FFFFFh, FF000000h-FF0FFFFFh} ((Random))
#define D17F0_FW_MEM_IDSEL_2		0x77	//Firmware Memory IDSEL 2
    #define D17F0_EROMS70ID			0xF0	//0000b/0/x/x Firmware Memory IDSEL for the Two 1MB Memory Ranges {FF700000h-FF7FFFFFh, FF300000h-FF3FFFFFh} ((Random))
    #define D17F0_EROMS60ID			0xF	//0000b/0/x/x Firmware Memory IDSEL for the Two 1MB Memory Ranges {FF600000h-FF6FFFFFh, FF200000h-FF2FFFFFh} ((Random))
#define D17F0_PNP_TEST_MODE_1		0x78	//PnP Test Mode 1
    #define D17F0_TSTP_7_0			0xFF	//0/0/x/x PnP IRQ, DRQ Input (TSTP7
#define D17F0_PNP_TEST_MODE_2		0x79	//PnP Test Mode 2
    #define D17F0_TSTPNP			BIT7	//0/0/x/x PnP Test Mode
    #define D17F0_TSTPNP2			BIT6	//0/0/x/x Programmable Device and Vendor ID
    #define D17F0_TSTP_13_8			0x3F	//0/0/x/x PnP IRQ, DRQ Input Test Bit
#define D17F0_USB_TEST_MODE		0x7A	//USB Test Mode
    #define D17F0_ESPI_SUS_EN			BIT7	//0/0/x/x Sub Cycle ESPI Device Decode
    #define D17F0_RESERVED_Z5			(BIT4 + BIT5 + BIT6)	//0/x/x/x Reserved
    #define D17F0_RESERVED_Z6			BIT3	//0/x/x/x Reserved
    #define D17F0_RESERVED_Z7			BIT2	//0/x/x/x Reserved
    #define D17F0_TSTCLKMD			BIT1	//0/0/x/x Counter Test Mode
    #define D17F0_RESERVED_Z8			BIT0	//0/x/x/x Reserved
#define D17F0_TEST_MODE		0x7B	//Test Mode
    #define D17F0_ENHPETTM			BIT7	//0/0/x/x High Precision Event Timer Test Mode
    #define D17F0_ENESPIPCS3			BIT6	//0/0/x/x LPC PCS3 Device Select
    #define D17F0_ENESPIPCS2			BIT5	//0/0/x/x LPC PCS2 Device Select
    #define D17F0_ENESPIPCS1			BIT4	//0/0/x/x LPC PCS1 Device Select
    #define D17F0_ENESPIPCS0			BIT3	//0/0/x/x LPC PCS0 Device Select
    #define D17F0_ENESPIMC			BIT2	//0/0/x/x LPC MC Device Select
    #define D17F0_ENESPIKBDC			BIT1	//0/0/x/x LPC KBDC Device Select
    #define D17F0_ENESPIRTC			BIT0	//0/0/x/x LPC RTC Device Select
#define D17F0_FW_MEM_IDSEL_3		0x7C	//Firmware Memory IDSEL 3
    #define D17F0_EROMSC81D			0xF0	//0000b/0/x/x Firmware Memory IDSEL for the Two 512K Memory Ranges {FFC80000h-FFCFFFFFh, FF880000h-FF8FFFFFh}
    #define D17F0_EROMSC01D			0xF	//0000b/0/x/x Firmware Memory IDSEL for the Two 512K Memory Ranges {FFC00000h-FFC7FFFFh, FF800000h-FF87FFFFh}
#define D17F0_FW_MEM_IDSEL_4		0x7D	//Firmware Memory IDSEL 4
    #define D17F0_EROMSD81D			0xF0	//0000b/0/x/x Firmware Memory IDSEL for the Two 512K Memory Ranges {FFD80000h-FFDFFFFFh, FF980000h-FF9FFFFFh}
    #define D17F0_EROMSD01D			0xF	//0000b/0/x/x Firmware Memory IDSEL for the Two 512K Memory Ranges {FFD00000h-FFD7FFFFh, FF900000h-FF97FFFFh}
#define D17F0_FW_MEM_IDSEL_5		0x7E	//Firmware Memory IDSEL 5
    #define D17F0_EROMSE81D			0xF0	//0000b/0/x/x Firmware Memory IDSEL for the Two 512K Memory Ranges {FFE80000h-FFEFFFFFh, FFA80000h-FFAFFFFFh}
    #define D17F0_EROMSE01D			0xF	//0000b/0/x/x Firmware Memory IDSEL for the Two 512K Memory Ranges {FFE00000h-FFE7FFFFh, FFA00000h-FFA7FFFFh}
#define D17F0_FW_MEM_IDSEL_6		0x7F	//Firmware Memory IDSEL 6
    #define D17F0_EROMSF81D			0xF0	//0/0/x/x Firmware Memory IDSEL for the Two 512K Memory Ranges { FFB80000h-FFBFFFFFh, 000E0000h-000FFFFFh}
    #define D17F0_EROMSF01D			0xF	//0/0/x/x Firmware Memory IDSEL for the Two 512K Memory Ranges {FFF00000h-FFF7FFFFh, FFB00000h-FFB7FFFFh }
#define D17F0_APIC_C4P_STATE_MODE_CTL		0xB0	//APIC C4P State Mode Control
    #define D17F0_RDVIVIP			BIT7	//0/x/x/X Reserved
    #define D17F0_T0FSB_CAP_SW			BIT6	//0/x/x/X HPET Timer 0 FSB Capability Bit Backdoor
    #define D17F0_T1FSB_CAP_SW			BIT5	//0/x/x/X HPET Timer 1 FSB Capability Bit Backdoor
    #define D17F0_T2FSB_CAP_SW			BIT4	//0/x/x/X HPET Timer 2 FSB Capability Bit Backdoor
    #define D17F0_EN_APIC_C4P			BIT3	//1b/1b/x/x Reserved
    #define D17F0_FLRCSSEL			BIT2	//0/x/x/x Function Level Reset Capability Structure Select
    #define D17F0_RESERVED_Z9			(BIT0 + BIT1)	//0/x/x/x Reserved
//D17F0 MMIO
#define D17F0MMIO_RESERVED		0xB1	//Reserved
    #define D17F0MMIO_U4IRQS_3_0			0xF0	//0/x/x/x Reserved
    #define D17F0MMIO_U3IRQS_3_0			0xF	//0/x/x/x Reserved
//D17F0
#define D17F0_PCI_UART_IRQ_ROUTING_LOW		0xB2	//PCI UART IRQ Routing - Low
    #define D17F0_U2IRQS_3_0			0xF0	//0/x/x/x PCI UART 1 IRQ Routing
    #define D17F0_U1IRQS_3_0			0xF	//0/x/x/x PCI UART 0 IRQ Routing
#define D17F0_PCI_UART_0_IO_BASE_ADR		0xB3	//PCI UART 0  I/O Base Address
    #define D17F0_VART0_COMPTBL			BIT7	//0/x/x/x PCI UART 0 Legacy Mode Enable
    #define D17F0_COMPTBA1			0x7F	//0/x/x/x PCI UART 0  I/O Base Address [9:3]
#define D17F0_PCI_UART_1_IO_BASE_ADR		0xB4	//PCI UART 1  I/O Base Address
    #define D17F0_VART1_COMPTBL			BIT7	//0/x/x/x PCI UART 1 Legacy Mode Enable
    #define D17F0_COMPTBA2			0x7F	//0/x/x/x PCI UART 1  I/O Base Address [9:3]
//D17F0 MMIO
#define D17F0MMIO_RESERVED_Z1		0xB5	//Reserved
    #define D17F0MMIO_VART2_COMPTBL			BIT7	//0/0/x/x Reserved
    #define D17F0MMIO_COMPTBA3			0x7F	//0/x/x/x Reserved
#define D17F0MMIO_RESERVED_Z2		0xB6	//Reserved
    #define D17F0MMIO_VART3_COMPTBL			BIT7	//0/0/x/x Reserved
    #define D17F0MMIO_COMPTBA4			0x7F	//0/x/x/x Reserved
//D17F0
#define D17F0_SM_DEBUG_CTL		0xB7	//SM Debug Control
    #define D17F0_RESERVED_Z10			BIT7	//0/x/x/x Reserved
    #define D17F0_DBGEN_SB			BIT6	//0/0/x/X Reserved
    #define D17F0_RESERVED_Z11			BIT5	//0/x/x/x Reserved
    #define D17F0_HPET_VID_LOCK			BIT4	//0/x/x/x Reserved
    #define D17F0_RESERVED_Z12			BIT3	//0/x/x/x Reserved
    #define D17F0_ENTMRCCLK			BIT2	//0/x/1/1 TMRC Dynamic Clock Enable
    #define D17F0_DID_RID_LOCK			BIT1	//0/0/x/x Reserved
    #define D17F0_VID_LOCK			BIT0	//0/x/x/x Reserved
#define D17F0_SB_SRC_ID_LOCK_CTL		0xB8	//SB Source ID Lock Control
    #define D17F0_SID_LOCK			BIT7	//0/x/x/x South Module (SM) Source ID Lock Control
    #define D17F0_RESERVED_Z13			0x7F	//0/x/x/x Reserved
#define D17F0_IDE_INTR_SEL_Z1		0xB9	//IDE Interrupt Select
    #define D17F0_RESERVED_Z14			0xFC	//0/x/x/x Reserved
    #define D17F0_D21RIASEL_1_0			(BIT0 + BIT1)	//0/0/x/x Reserved
//D17F0 MMIO
#define D17F0MMIO_RESERVED_Z3		0xBA	//Reserved
    #define D17F0MMIO_RESERVED_Z4			0xFFFF	//0/x/x/x Reserved
//D17F0
#define D17F0_MMIO_SPACE_BASE_ADR		0xBC	//D17F0 MMIO Space Base Address
    #define D17F0_F0MMIOBA_31_12			0xFFFFF0	//0/x/x/x MMIO Space Base Address [31:12]
//D17F0 MMIO
#define D17F0MMIO_RESERVED_Z5		0xBF	//Reserved
    #define D17F0MMIO_DBGSEL_SB			0xFF	//0/x/x/x Reserved
#define D17F0MMIO_SPI_BUS_0_CTL		0x000	//SPI Bus 0 Control
    #define D17F0MMIO_RESERVED_Z6			0xFE	//0/x/x/x Reserved
    #define D17F0MMIO_SPIBUS_EN0			BIT0	//0/x/x/x SPI Bus 0 Enable
#define D17F0MMIO_SPI_BUS_0_MEM_MAP_BASE_ADR		0x001	//SPI Bus 0 Memory Map Base Address
    #define D17F0MMIO_SPIBA_31_8			0xFFFFFF	//0/x/x/x SPI Bus 0 Memory Map Base Address
#define D17F0MMIO_RESERVED_Z7		0x004	//Reserved
    #define D17F0MMIO_RESERVED_Z8			0xFFFFFFFF	//0/x/x/x Reserved
#define D17F0MMIO_SPI_BUS_MISC_CTL		0x008	//SPI Bus Misc. Control
    #define D17F0MMIO_RESERVED_Z9			0xFC	//0/x/x/x Reserved
    #define D17F0MMIO_ENSPIDEVINT			BIT1	//0/0/x/x SPI External Device Interrupt Enable
    #define D17F0MMIO_ENSPIFR			BIT0	//0/x/*1/x SPI ROMSIP Cycle Fast Read Enable
#define D17F0MMIO_SPI_BUS_INTR_ROUTING_CTL		0x009	//SPI Bus Interrupt Routing Control
    #define D17F0MMIO_SPIRQSEL_3_0			0xF	//0000b/x/x/x SPI IRQ Routing
#define D17F0MMIO_CLK48M_CLK_SRC_SEL_CTL		0x00A	//CLK48M Clock Source Selection Control
    #define D17F0MMIO_RESERVED_Z10			0xFE	//0/x/x/x Reserved
    #define D17F0MMIO_MMIO_RX0AD0_ECO			BIT0	//0/x/x/x Reserved
#define D17F0MMIO_PNP_DEBUG_PIN_AND_SW_INTR		0x00B	//PNP Debug Pin and Software Interrupt
    #define D17F0MMIO_PNP_DBGS_G2			(BIT5 + BIT6 + BIT7)	//0/x/x/x Reserved
    #define D17F0MMIO_IRQ_SWS			BIT4	//0/x/x/x Reserved
    #define D17F0MMIO_IRQ_SWR			0xF	//0/x/x/x Reserved
#define D17F0MMIO_CEC_INTR_ROUTING_CTL		0x00C	//CEC Interrupt Routing Control
    #define D17F0MMIO_CECIRQSEL_3_0			0xF0	//0/x/x/x Reserved
    #define D17F0MMIO_RESERVED_Z11			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D17F0MMIO_CECCLKSEL			BIT1	//0/x/x/x Reserved
    #define D17F0MMIO_ENCEC			BIT0	//0/x/x/x Reserved
#define D17F0MMIO_CEC_MEM_MAP_BASE_ADR		0x00D	//CEC Memory Map Base Address
    #define D17F0MMIO_CECBA_31_8			0xFFFFFF	//0/x/x/x Reserved
#define D17F0MMIO_NMI_SW_TRIGGER_BIT		0x010	//NMI SW Trigger Bit
    #define D17F0MMIO_NMISLV_MSG_EN			BIT2	//0/x/x/x SB2VPI_NMISLV_Enable Bit
    #define D17F0MMIO_CPU2SB_NMI_EN			BIT1	//0/x/x/x NMI CPU2SB_NMI Enable Bit
    #define D17F0MMIO_NMI_SW_ACT			BIT0	//0/x/x/x NMI Software Trigger Bit 
#define D17F0MMIO_NMI_SRC_FROM_NM_OR_SW		0x011	//NMI Source from NM or SW
    #define D17F0MMIO_NMI_SW_STS			BIT3	//0/x/x/x NMI Software Trigger Status
    #define D17F0MMIO_NMI_SW_EN			BIT2	//0/0/x/x Software Trigger NMI Enable
    #define D17F0MMIO_NMI_NB_STS			BIT1	//0/x/x/x Reserved
    #define D17F0MMIO_RNMI_NB			BIT0	//0/0/x/x Reserved
#define D17F0MMIO_PNP_DEBUG_PIN_SEL		0x012	//PNP Debug Pin Select
    #define D17F0MMIO_PNP_DBGS			(BIT2 + BIT3 + BIT4)	//0/x/x/x Reserved
    #define D17F0MMIO_NPMSI_MSK			BIT1	//1b/1/x/x NB2SB_PEND_MSI Mask Bit
#define D17F0MMIO_NB2SB_INTA_NB2SB_INTD_ROUTINE_REG		0x013	//NB2SB_INTA~NB2SB_INTD Routine Register
    #define D17F0MMIO_NBINTA_RR			(BIT6 + BIT7)	//11b/11b/x/x NB2SB_INTA Routine Register
    #define D17F0MMIO_NBINTB_RR			(BIT4 + BIT5)	//11b/11b/x/x NB2SB_INTB Routine Register
    #define D17F0MMIO_NBINTC_RR			(BIT2 + BIT3)	//11b/11b/x/x NB2SB_INTC Routine Register
    #define D17F0MMIO_NBINTD_RR			(BIT0 + BIT1)	//11b/11b/x/x NB2SB_INTD Routine Register
#define D17F0MMIO_APIC_MODE_SATA_D15F0_GSATAIRQI_INTR_ROUTINE_REG		0x014	//APIC Mode SATA D15F0 GSATAIRQI_ Interrupt Routine Register
    #define D17F0MMIO_D15F0SINTLN_APIC			0x1F	//15h/15h/x/x D15F0 GSATAIRQI_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_XHCI_XHCIINTR_INTR_ROUTINE_REG		0x015	//APIC Mode xHCI XHCIINTR_ Interrupt Routine Register
    #define D17F0MMIO_XIRQSEL_APIC			0x1F	//14h/14h/x/x XHCIINTR_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_USB_D16_UINTOE1_INTR_ROUTINE_REG		0x016	//APIC Mode USB D16_UINTOE1_ Interrupt Routine Register
    #define D17F0MMIO_UIRQSA_APIC			0x1F	//14h/14h/x/x USB D16 D16_UINTOE1_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_USB_D16_UINTOE2_INTR_ROUTINE_REG		0x017	//APIC Mode USB D16_UINTOE2_ Interrupt Routine Register
    #define D17F0MMIO_UIRQSB_APIC			0x1F	//16h/16h/x/x USB D16 D16_UINTOE2_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_USB_D16_UINTOE6_INTR_ROUTINE_REG		0x018	//APIC Mode USB D16_UINTOE6_ Interrupt Routine Register
    #define D17F0MMIO_UIRQSC_APIC			0x1F	//15h/15h/x/x USB D16 D16_UINTOE6_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_USB_D14_UINTOE1_INTR_ROUTINE_REG		0x019	//APIC Mode USB D14_UINTOE1_ Interrupt Routine Register
    #define D17F0MMIO_UIRQSD_APIC			0x1F	//17h/17h/x/x USB D14 D14_UINTOE1_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_USB_D14_UINTOE6_INTR_ROUTINE_REG		0x01A	//APIC Mode USB D14_UINTOE6_ Interrupt Routine Register
    #define D17F0MMIO_UIRQSE_APIC			0x1F	//14h/14h/x/x USB D14 D14_UINTOE6_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_VART_INTR_ROUTINE_REG		0x020	//APIC Mode VART Interrupt Routine Register
    #define D17F0MMIO_V0_IRQSEL_APIC_4_0			0x1F	//10h/10h/x/x UART0_INTOE_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_VART_INTR_ROUTINE_REG_Z1		0x021	//APIC Mode VART Interrupt Routine Register
    #define D17F0MMIO_V1_IRQSEL_APIC_4_0			0x1F	//11h/11h/x/x UART1_INTOE_ Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_MODE_HDAC_AZ_INTR_ROUTINE_REG		0x024	//APIC Mode HDAC ((AZ)) Interrupt Routine Register
    #define D17F0MMIO_AZIRQSEL_APIC_4_0			0x1F	//11h/11h/x/x HDAC ((AZALIA)) Interrupt Routine Register in APIC Mode
#define D17F0MMIO_APIC_SRC_ID		0x028	//APIC Source ID
    #define D17F0MMIO_APIC_ID			0xFFFF	//0088h/x/x/x APIC Source ID
#define D17F0MMIO_LPC_SPI_SRC_ID		0x02A	//LPC/SPI Source ID
    #define D17F0MMIO_SPI_LPC_ID			0xFFFF	//0088h/x/x/x LPC/SPI Source ID
#define D17F0MMIO_HPET_SRC_ID		0x02C	//HPET Source ID
    #define D17F0MMIO_HPET_SID			0xFFFF	//8080h/x/x/x HPET Source ID
#define D17F0MMIO_PIC_MODE_INTR_ROUTINE_REG_SEL		0x02F	//PIC Mode Interrupt Routine Register Select
    #define D17F0MMIO_PICRRS			BIT0	//1b/1/x/x PCI Device Interrupt Routine Register Select in PIC Mode
#define D17F0MMIO_PIC_MODE_SATA_XHCI_INTR_ROUTING_CTL_REG		0x030	//PIC Mode SATA xHCI Interrupt Routing Control Register
    #define D17F0MMIO_XIRQSEL_PIC			0xF0	//0/x/x/x xHCI XHCIINTR_ IRQ Routing Register
    #define D17F0MMIO_D15F0SINTLN_PIC			0xF	//0/x/x/x SATA D15F0GSATAIRQI_ IRQ Routing Register
#define D17F0MMIO_PIC_MODE_USB_D16_UHCI_INTR_ROUTING_CTL_REG		0x031	//PIC Mode USB D16 UHCI Interrupt Routing Control Register
    #define D17F0MMIO_UIRQSB_PIC			0xF0	//0/x/x/x USBD16 D16_UINTOE2_  IRQ Routing Register
    #define D17F0MMIO_UIRQSA_PIC			0xF	//0/x/x/x USBD16 D16_UINTOE1_  IRQ Routing Register
#define D17F0MMIO_PIC_MODE_USB_D16_EHCI_D14_UHCI_INTR_ROUTING_CTL_REG		0x032	//PIC Mode USB D16 EHCI D14 UHCI Interrupt Routing Control Register
    #define D17F0MMIO_UIRQSD_PIC			0xF0	//0/x/x/x USBD14 D14_UINTOE1_  IRQ Routing Register
    #define D17F0MMIO_UIRQSC_PIC			0xF	//0/x/x/x USBD16 D16_UINTOE6_  IRQ Routing Register
#define D17F0MMIO_PIC_MODE_USBC2_0_INTR_ROUTINE_REG		0x033	//PIC Mode USBC2.0 Interrupt Routine Register
    #define D17F0MMIO_UIRQSF_PIC_3_0			0xF0	//0/x/x/x Reserved
    #define D17F0MMIO_UIRQSE_PIC_3_0			0xF	//0/x/x/x USBD14 D14_UINTOE6_  IRQ Routing Register
#define D17F0MMIO_RESERVED_Z12		0x034	//Reserved
    #define D17F0MMIO_RESERVED_Z13			0xFFFF	//0/x/x/x Reserved
#define D17F0MMIO_PIC_MODE_VART_INTR_ROUTINE_REG		0x036	//PIC Mode VART Interrupt Routine Register
    #define D17F0MMIO_U1IRQS_PIC_3_0			0xF0	//0/x/x/x UART1_INTOE_ Interrupt Routine Register
    #define D17F0MMIO_U0IRQS_PIC_3_0			0xF	//0/x/x/x UART0_INTOE_ Interrupt Routine Register
#define D17F0MMIO_RESERVED_Z14		0x037	//Reserved
    #define D17F0MMIO_RESERVED_Z15			0xF0	//0/x/x/x Reserved
    #define D17F0MMIO_RESERVED_Z16			0xF	//0/x/x/x Reserved
#define D17F0MMIO_PIC_MODE_HDAC_AZALIA_INTR_ROUTINE_REG		0x038	//PIC Mode HDAC ((AZALIA)) Interrupt Routine Register
    #define D17F0MMIO_AZIRQSEL_PIC_3_0			0xF	//0/x/x/x HDAC ((AZ)) Interrupt Routine Register
#define D17F0MMIO_RESERVED_Z17		0x03A	//Reserved
    #define D17F0MMIO_RESERVED_Z18			0xFF	//0/x/x/x Reserved
#define D17F0MMIO_DEV_FUN_ENABLE		0x040	//Device Function Enable
    #define D17F0MMIO_AZ_SLEW_SEL			BIT7	//0/x/x/x HDAC Pad Slew Rate Selection
    #define D17F0MMIO_DBGSEL_SB1_4_3			(BIT5 + BIT6)	//0/x/x/x Reserved
    #define D17F0MMIO_RESERVED_Z19			BIT4	//1b/x/x/x Reserved
    #define D17F0MMIO_ENEHCI2			BIT3	//0/x/x/x D14 F7 Enable Register
    #define D17F0MMIO_ENCRF1			BIT2	//1b/x/x/x Reserved
    #define D17F0MMIO_ENCRF0			BIT1	//1b/x/x/x Reserved
    #define D17F0MMIO_ENEHCI1			BIT0	//0/x/x/x D16 F7 Enable Register
#define D17F0MMIO_RESERVED_Z20		0x48	//Reserved
    #define D17F0MMIO_RESERVED_Z21			0xFFFFFFFF	//0/x/x/x Reserved
#define D17F0MMIO_RESERVED_Z22		0x4C	//Reserved
    #define D17F0MMIO_RESERVED_Z23			0xFFFFFFFF	//0/x/x/x Reserved
#define D17F0MMIO_BACKDOOR_REG		0x050	//Backdoor Register
    #define D17F0MMIO_RTC_CS_BD			BIT1	//0/x/1/1 RTC CS Selection
    #define D17F0MMIO_ENDUAL_ADDR			BIT0	//0/0/x/x Enable PCIS Respond to Dual Address Cycle
#define D17F0MMIO_SBHSC_DBGM_STA_REG		0x051	//SBHSC-DBGM Status Register
    #define D17F0MMIO_DSOVERRUN			BIT7	//0/R/x/x Reserved
    #define D17F0MMIO_UPWACOVERRUN			BIT6	//0/R/x/x Reserved
    #define D17F0MMIO_UPWDATAOVERRUN			BIT5	//0/R/x/x Reserved
    #define D17F0MMIO_URADDCTLOVERRUN			BIT4	//0/R/x/x Reserved
    #define D17F0MMIO_UPRDATAOVERRUN			BIT3	//0/R/x/x Reserved
    #define D17F0MMIO_SBHSC_DBGM_EN			BIT2	//0/0/x/x Reserved
    #define D17F0MMIO_CHNSEL			(BIT0 + BIT1)	//00b/00b/x/x Reserved
#define D17F0MMIO_SBHSC_DBGM_DEBUG_MONITOR_CTL_REG		0x052	//SBHSC-DBGM Debug Monitor Control Register
    #define D17F0MMIO_OUTARB1			0xFC	//0/x/x/x Reserved
    #define D17F0MMIO_OUTARB			(BIT0 + BIT1)	//00b/00b/x/x Reserved
#define D17F0MMIO_IO_TRAP_CYCLE_CONFIGURE_REG		0x054	//IO Trap Cycle Configure Register
    #define D17F0MMIO_IO_TRAP_ADDR			0xFFFF00	//0/x/x/x IO Trap Cycle Address
    #define D17F0MMIO_IO_TRAP_BE			0xF0	//0/x/x/x IO Trap Cycle BE
    #define D17F0MMIO_IO_TRAP_WRT			BIT3	//0/x/x/x IO Trap Write Cycle
    #define D17F0MMIO_IO_TRAP_RD			BIT2	//0/x/x/x IO Trap Read Cycle
    #define D17F0MMIO_IO_TRAP_MUTI			BIT1	//0/x/x/x IO Trap Multi Cycle Set
    #define D17F0MMIO_IO_TRAP_EN			BIT0	//0/x/x/x IO Trap Cycle Enable Bit
#define D17F0MMIO_SLAVE_SOCKET_SERIRQ_INT_CONFIGURE_REG		0x058	//Slave Socket Serirq INT Configure Register
    #define D17F0MMIO_SIRQ15I2CPU_EN			BIT31	//0/x/x/x Slave Socket Serirq 15 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ14I2CPU_EN			BIT30	//0/x/x/x Slave Socket Serirq 14 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ12I2CPU_EN			BIT29	//0/x/x/x Slave Socket Serirq 12 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ11I2CPU_EN			BIT28	//0/x/x/X Slave Socket Serirq 11 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ10I2CPU_EN			BIT27	//0/x/x/X Slave Socket Serirq 10 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ9I2CPU_EN			BIT26	//0/x/x/x Slave Socket Serirq 9 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ7I2CPU_EN			BIT25	//0/x/x/X Slave Socket Serirq 7 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ6I2CPU_EN			BIT24	//0/x/x/x Slave Socket Serirq 6 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ5I2CPU_EN			BIT23	//0/x/x/x Slave Socket Serirq 5 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ4I2CPU_EN			BIT22	//0/x/x/x Slave Socket Serirq 4 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ3I2CPU_EN			BIT21	//0/x/x/x Slave Socket Serirq 3 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_SIRQ1I2CPU_EN			BIT20	//0/x/x/X Slave Socket Serirq 1 Routing to Master Socket CPU_INTA/ CPU_INTB/ CPU_INTC/ CPU_INTD Enable
    #define D17F0MMIO_CPU2PNP_INTD_EN			BIT19	//0/x/x/X CPU2PNP_INTD (VPI2SB_INTD_B) Enable
    #define D17F0MMIO_CPU2PNP_INTC_EN			BIT18	//0/x/x/x CPU2PNP_INTC (VPI2SB_INTC_B) Enable
    #define D17F0MMIO_CPU2PNP_INTB_EN			BIT17	//0/x/x/x CPU2PNP_INTB (VPI2SB_INTB_B) Enable
    #define D17F0MMIO_CPU2PNP_INTA_EN			BIT16	//0/x/x/x CPU2PNP_INTA (VPI2SB_INTA_B) Enable
    #define D17F0MMIO_CPU2PNP_INTD_SEL			0xF000	//0/x/x/x CPU2PNP_INTD Routing Register
    #define D17F0MMIO_CPU2PNP_INTC_SEL			0xF00	//0/x/x/X CPU2PNP_INTCRouting Register
    #define D17F0MMIO_CPU2PNP_INTB_SEL			0xF0	//0/x/x/X CPU2PNP_INTB Routing Register
    #define D17F0MMIO_CPU2PNP_INTA_SEL			0xF	//0/x/x/x CPU2PNP_INTA Routing Register
#define D17F0MMIO_ESPI_AND_SIRQ_INTR_ROUTING_REG		0x05C	//eSPI and SIRQ Interrupt Routing Register
    #define D17F0MMIO_ESPI2CPU_EN			BIT26	//0/x/X/x ESPI Interrupt Routing to Master Socket SB2VPI_INTA_B
    #define D17F0MMIO_ESPI2CPU_SEL			(BIT24 + BIT25)	//11b/x/X/x ESPI to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ15I2CPU_SEL			(BIT22 + BIT23)	//10b/x/X/x SRIQ15 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ14I2CPU_SEL			(BIT20 + BIT21)	//10b/x/X/x SRIQ14 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ12I2CPU_SEL			(BIT18 + BIT19)	//10b/x/X/x SRIQ12 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ11I2CPU_SEL			(BIT16 + BIT17)	//10b/x/X/x SRIQ11 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ10I2CPU_SEL			(BIT14 + BIT15)	//01b/x/X/x SRIQ10 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ9I2CPU_SEL			(BIT12 + BIT13)	//01b/x/X/x SRIQ9 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ7I2CPU_SEL			(BIT10 + BIT11)	//01b/x/X/x SRIQ7 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ6I2CPU_SEL			(BIT8 + BIT9)	//01b/x/X/x SRIQ6 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ5I2CPU_SEL			(BIT6 + BIT7)	//0/x/X/x SRIQ5 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ4I2CPU_SEL			(BIT4 + BIT5)	//0/x/X/x SRIQ4 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ3I2CPU_SEL			(BIT2 + BIT3)	//0/x/X/x SRIQ3 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_SIRQ1I2CPU_SEL			(BIT0 + BIT1)	//0/x/X/x SRIQ1 to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
#define D17F0MMIO_DEV_INTR_ROUTING_REG		0x060	//Device Interrupt Routing Register
    #define D17F0MMIO_SD2CPU_SEL			(BIT30 + BIT31)	//0/x/x/X Reserved
    #define D17F0MMIO_SPI2CPU_SEL			(BIT28 + BIT29)	//0/x/x/x SPI IRQ to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_VART02CPU_SEL			(BIT26 + BIT27)	//0/x/x/X VART0 IRQ to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_VART12CPU_SEL			(BIT24 + BIT25)	//0/x/x/x VART1 IRQ to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_RESERVED_Z24			(BIT22 + BIT23)	//0/x/x/x Reserved
    #define D17F0MMIO_RESERVED_Z25			(BIT20 + BIT21)	//0/x/x/x Reserved
    #define D17F0MMIO_SCIO2CPU_SEL			(BIT18 + BIT19)	//0/x/x/x SCI to SB2VPI_INTA/INTB/INTC/INTD _B Routing Register
    #define D17F0MMIO_AZ2CPU_SEL			(BIT16 + BIT17)	//0/x/x/X HDAC ((AZ)) IRQ to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_INTA2CPU_SEL			(BIT14 + BIT15)	//0/x/x/X INTA to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_INTB2CPU_SEL			(BIT12 + BIT13)	//01b/x/x/x INTB to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_INTC2CPU_SEL			(BIT10 + BIT11)	//10b/x/x/x INTC to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_INTD2CPU_SEL			(BIT8 + BIT9)	//11b/x/x/x INTD to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_INTE2CPU_SEL			(BIT6 + BIT7)	//0/x/x/x INTE to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_INTF2CPU_SEL			(BIT4 + BIT5)	//01b/x/x/X INTF to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_INTG2CPU_SEL			(BIT2 + BIT3)	//10b/x/x/X INTG to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
    #define D17F0MMIO_INTH2CPU_SEL			(BIT0 + BIT1)	//11b/x/x/x INTH to PNP2CPU_INTA/INTB/INTC/INTD Routing Register
#define D17F0MMIO_SLAVE_SOCKET_IRQ_ROUTING_REG		0x064	//Slave Socket IRQ Routing Register
    #define D17F0MMIO_SD2CPU_EN			BIT15	//0/x/x/X Reserved
    #define D17F0MMIO_SPI2CPU_EN			BIT14	//0/x/x/x Slave Socket SPI IRQ Routing to Master Socket Enable
    #define D17F0MMIO_VART02CPU_EN			BIT13	//0/x/x/X Slave Socket VART0 IRQ Routing to Master Socket Enable
    #define D17F0MMIO_VART12CPU_EN			BIT12	//0/x/x/x Slave Socket VART1 IRQ Routing to Master Socket Enable
    #define D17F0MMIO_SCIO2CPU_EN			BIT9	//0/x/x/x Slave Socket SCI Routing to Master Socket Enable
    #define D17F0MMIO_AZ2CPU_EN			BIT8	//0/x/x/X Slave Socket AZIRQ Routing to Master Socket Enable
    #define D17F0MMIO_INTA2CPU_EN			BIT7	//0/x/x/X Slave Socket INTA Routing to Master Socket Enable
    #define D17F0MMIO_INTB2CPU_EN			BIT6	//0/x/x/x Slave Socket INTB Routing to Master Socket Enable
    #define D17F0MMIO_INTC2CPU_EN			BIT5	//0/x/x/x Slave Socket INTC Routing to Master Socket Enable
    #define D17F0MMIO_INTD2CPU_EN			BIT4	//0/x/x/x Slave Socket INTD Routing to Master Socket Enable
    #define D17F0MMIO_INTE2CPU_EN			BIT3	//0/x/x/x Slave Socket INTE Routing to Master Socket Enable
    #define D17F0MMIO_INTF2CPU_EN			BIT2	//0/x/x/X Slave Socket INTF Routing to Master Socket Enable
    #define D17F0MMIO_INTG2CPU_EN			BIT1	//0/x/x/X Slave Socket INTG Routing to Master Socket Enable
    #define D17F0MMIO_INTH2CPU_EN			BIT0	//0/x/x/x Slave Socket INTH Routing to Master Socket Enable
#define D17F0MMIO_DEV_IRQ_ROUTING_REG		0x068	//Device IRQ Routing Register
    #define D17F0MMIO_SVID2CPU_EN			BIT31	//0/x/x/x Slave Socket SVID Routing to Master Socket Enable
    #define D17F0MMIO_SVID2CPU_SEL			(BIT29 + BIT30)	//0/x/x/x Slave Socket SVID Routing to Master Socket Select
    #define D17F0MMIO_ESPIIRQ_APIC			0x1F000000	//15h/x/x/X eSPI Interrupt Routine Register in APIC Mode
    #define D17F0MMIO_ESPIIRQ_PIC			0xF00000	//0/x/x/X eSPI Interrupt Routine Register in PIC Mode
    #define D17F0MMIO_SVID_IRQ_PIC			0xF0000	//0/x/x/x SVID Interrupt Routine Register in PIC Mode
    #define D17F0MMIO_SVID_IRQ_APIC			0x1F00	//0/x/x/x SVID  Interrupt Routine Register in APIC Mode
    #define D17F0MMIO_GPIO_DPCTL			(BIT4 + BIT5 + BIT6)	//011b/x/x/x Chipset Core Power Domain GIPO Power GPIO_DPCTL Port Control
    #define D17F0MMIO_GPIO_DNCTL			(BIT0 + BIT1 + BIT2)	//011b/x/x/x Chipset Core Power Domain GIPO Power GPIO_DNCTL  Port Control
#define D17F0MMIO_CPU_APIC_ROUTING_REG		0x06C	//CPU APIC Routing Register
    #define D17F0MMIO_CPU2SB_INTD_EN_APIC			BIT29	//0/x/x/x CPU2SB_INTD_B Routing  Master Socket APIC
    #define D17F0MMIO_CPU2SB_INTD_SEL_APIC			0x1F000000	//0/x/x/x CPU2SB_INTD_B Routing Master Socket APIC
    #define D17F0MMIO_CPU2SB_INTC_EN_APIC			BIT21	//0/x/x/X CPU2SB_INTC_B Routing Master Socket APIC Enable
    #define D17F0MMIO_CPU2SB_INTC_SEL_APIC			0x1F0000	//0/x/x/x CPU2SB_INTC_B Routing Master Socket APIC 
    #define D17F0MMIO_CPU2SB_INTB_EN_APIC			BIT13	//0/x/x/x CPU2SB_INTB_B Routing Master Socket APIC
    #define D17F0MMIO_CPU2SB_INTB_SEL_APIC			0x1F00	//0/x/x/x CPU2SB_INTB_B Routing Master Socket APIC
    #define D17F0MMIO_CPU2SB_INTA_EN_APIC			BIT5	//0/x/x/X CPU2SB_INTA_B Routing Master Socket APIC
    #define D17F0MMIO_CPU2SB_INTA_SEL_APIC			0x1F	//0/x/x/X CPU2SB_INTA_B Routing Master Socket APIC
#define D17F0MMIO_PIC_DEBUG_SEL_REG		0x070	//PIC Debug Select Register
    #define D17F0MMIO_PIC_DBG2_SEL			0xF0	//0/x/x/x PIC Debug Signal Group 2 Select Control Register
    #define D17F0MMIO_PIC_DBG1_SEL			0xF	//0/x/x/x PIC Debug Signal Group 1 Select Control Register
#define D17F0MMIO_SW_NMI_INFORMATION_REG		0x074	//Software NMI Information Register
    #define D17F0MMIO_NMI_SW_INF			0xFFFFFFFF	//0/x/x/X Software NMI Information Register
#define D17F0MMIO_LPCCLK_PHASE_SEL_CTL_REG		0x078	//LPCCLK Phase Select Control Register
    #define D17F0MMIO_KCS1_EN			BIT9	//1b/x/x/x KCS1 Channel Port Enable Bit
    #define D17F0MMIO_KCS0_EN			BIT8	//1b/x/x/X KCS0 Channel Port Enable Bit
    #define D17F0MMIO_RESERVED_Z26			BIT3	//0/x/x/x Reserved
    #define D17F0MMIO_LPCCLK_PH_SW			(BIT1 + BIT2)	//0/x/x/X LPCCLK Phase Select Control Register
    #define D17F0MMIO_LPCCLK_PH_EN			BIT0	//0/x/x/X LPCCLK Phase Select Control  Enable Register
#define D17F0MMIO_KCS_BASIC_ADR_CTL_REG		0x07C	//KCS Basic Address Control Register
    #define D17F0MMIO_KCS1_BASE			0xFFFF0000	//0CACh/x/x/x KCS1 Basic Address Register
    #define D17F0MMIO_KCS0_BASE			0xFFFF	//0CA8h/x/x/x KCS0 Basic Address Register
#define D17F0MMIO_USB2_AND_SATA_INTR_ENABLE_REG		0x080	//USB2 and SATA Interrupt Enable Register
    #define D17F0MMIO_GUINTOE52CPU			BIT7	//0/x/x/x D14_UINTOE6_  Interrupt Routing SB2VPI_INT*_B Enable
    #define D17F0MMIO_GUINTOE42CPU			BIT6	//0/x/x/x D14_UINTOE1 _ Interrupt Routing SB2VPI_INT*_B  Enable
    #define D17F0MMIO_GUINTOE32CPU			BIT5	//0/x/x/x D16_UINTOE6_ Interrupt Routing SB2VPI_INT*_B Enable
    #define D17F0MMIO_GUINTOE22CPU			BIT4	//0/x/x/x D16_UINTOE2_ Interrupt Routing SB2VPI_INT*_B Enable
    #define D17F0MMIO_GUINTOE12CPU			BIT3	//0/x/x/x D16_UINTOE1_ Interrupt Routing SB2VPI_INT*_B Enable
    #define D17F0MMIO_SATA32CPU			BIT2	//0/x/x/x Reserved
    #define D17F0MMIO_SATA22CPU			BIT1	//0/x/x/x Reserved
    #define D17F0MMIO_SATA12CPU			BIT0	//0/x/x/x SATA D15F0GSATAIRQI Enable Register
#define D17F0MMIO_USB2_AND_SATA_INTR_SEL_REG		0x081	//USB2 and SATA Interrupt Select Register
    #define D17F0MMIO_GUINTOE52CPUSEL			(BIT14 + BIT15)	//01b/x/x/x D14_UINTOE6_Select Select Register
    #define D17F0MMIO_GUINTOE42CPUSEL			(BIT12 + BIT13)	//0/x/x/x D14_UINTOE1 Select Register
    #define D17F0MMIO_GUINTOE32CPUSEL			(BIT10 + BIT11)	//11b/x/x/x D16_UINTOE6 Select Register
    #define D17F0MMIO_GUINTOE22CPUSEL			(BIT8 + BIT9)	//10b/x/x/x D16_UINTOE2 Select Register
    #define D17F0MMIO_GUINTOE12CPUSEL			(BIT6 + BIT7)	//01b/x/x/x D16_UINTOE1 Select Register
    #define D17F0MMIO_SATA32CPUSEL			(BIT4 + BIT5)	//0/x/x/x Reserved
    #define D17F0MMIO_SATA22CPUSEL			(BIT2 + BIT3)	//0/x/x/x Reserved
    #define D17F0MMIO_SATA12CPUSEL			(BIT0 + BIT1)	//0/x/x/x SATA D15F0GSATAIRQI_ Select Register
#define D17F0MMIO_XHCI_INTR_ENABLE_SEL_REG		0x083	//XHCI Interrupt Enable/Select Register
    #define D17F0MMIO_XHCI2CPUSEL			(BIT5 + BIT6)	//0/x/x/x XHCI_Interrupt Select  Register
    #define D17F0MMIO_XHCI2CPU			BIT4	//0/x/x/x XHCI_ Interrupt Enable Register 
//MMIO
#define MMIO_SVID_MASTER_CTL_REG		0x100	//SVID Master Control Register
    #define MMIO_SVIDM_SCIE			BIT7	//0/x/x/x SVID Master Normal Interrupt Enable for SCI
    #define MMIO_SVIDM_SMIE			BIT6	//0/x/x/x SVID Master Normal Interrupt Enable for SMI
    #define MMIO_SVIDM_MSIE			BIT5	//0/x/x/x SVID Master Normal Interrupt Enable for MSI
    #define MMIO_SVIDM_NMIE			BIT4	//0/x/x/x SVID Master NMI Interrupt Enable
    #define MMIO_C4C5_IR_DIS			BIT3	//0/x/x/x C4C5 State Read Iout
    #define MMIO_SVIDM_CG			BIT2	//0/x/1/1 SVID Master VCLK Dynamic Gating
    #define MMIO_SVIDM_RST			BIT1	//0/x/x/x SVID Master SW Reset
    #define MMIO_RESEND_FAILE			BIT0	//0/x/x/x SVID Master Resend Fail Interrupt Enable
#define MMIO_SVID_MASTER_STA_REG		0x101	//SVID Master Status Register
    #define MMIO_RS_101_4			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_RSD_FAIL_STS			BIT4	//0/x/x/x SVID Resend Fail Status
    #define MMIO_SVIDM_NMI			BIT3	//0/x/x/x SVID Master NMI Interrupt
    #define MMIO_SVIDM_ACK			(BIT1 + BIT2)	//10b/x/x/x VRM ACK Bits
    #define MMIO_SVIDM_TRAN_CMPLT			BIT0	//1b/x/x/x SVID Transaction Complete
#define MMIO_SVID_MASTER_SETREGADR_REG		0x102	//SVID Master SetRegADR Register
    #define MMIO_SETREGADR			0xFF	//0/x/x/x SVID Master SetRegADR Register
#define MMIO_SVID_MASTER_SETREGDAT_REG		0x103	//SVID Master SetRegDAT Register
    #define MMIO_SETREGDAT			0xFF	//0/x/x/x SVID Master SetRegDAT Register
#define MMIO_SVID_MASTER_GETREG_REG		0x104	//SVID Master GetReg Register
    #define MMIO_GETREGADR			0xFF	//0/x/x/x SVID Master GetReg Index Register
#define MMIO_SVID_MASTER_GETREG_DATA_REG		0x105	//SVID Master GetReg DATA Register
    #define MMIO_GETREGDAT			0xFF	//0/x/x/x SVID Master GetReg DATA Register
#define MMIO_SVID_MASTER_DEBUG_SIGNAL_REG		0x106	//SVID Master Debug Signal Register
    #define MMIO_SVIDM_DBG			0xFF	//04h/x/x/x SVID Master Debug Signals
#define MMIO_SVID_MASTER_BUS_TUNE_REG		0x107	//SVID Master BUS TUNE Register
    #define MMIO_RS_107_4			0xF0	//0/x/x/x Reserved
    #define MMIO_SVIDM_RX_ACK_TUNE			(BIT2 + BIT3)	//0/x/x/x SVID Receive ACK Tune
    #define MMIO_SVIDM_RXD_TUNE			(BIT0 + BIT1)	//0/x/x/x SVID Receive Data Tune
#define MMIO_SVID_MASTER_VRM0_CTL_REG		0x108	//SVID Master VRM0 Control Register
    #define MMIO_VRM0_SETPS			(BIT6 + BIT7)	//0/x/x/x VRM0 SetPS State Select
    #define MMIO_VRM0_IOUT_EN			BIT5	//0/x/x/x SVIDM Will Do Iout Read Periodically (Periodically_timer_enable_reg)
    #define MMIO_VRM0_VIDS			BIT4	//0/x/x/x SetVID-Fast/Slow Select Bit
    #define MMIO_RS_108_0			0xF	//0/R/x/x Reserved
#define MMIO_SVID_MASTER_VRM0_INTR_REG		0x109	//SVID Master VRM0 Interrupt Register
    #define MMIO_RS_109_2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM0_IABI			BIT5	//0/x/x/x VRM0 ICC Max Back to Normal Alert Interrupt
    #define MMIO_VRM0_TABI			BIT4	//0/x/x/x VRM0 Thermal Back to Normal Alert Interrupt
    #define MMIO_VRM0_PAI			BIT3	//0/x/x/x VRM0 Parity Interrupt
    #define MMIO_VRM0_IAI			BIT2	//0/x/x/x VRM0 ICC Max Alert Interrupt
    #define MMIO_VRM0_TAI			BIT1	//0/x/x/x VRM0 Thermal Alert Interrupt
    #define MMIO_RS_109_0			BIT0	//0/R/x/x Reserved
#define MMIO_SVID_MASTER_VRM0_INTR_ENABLE_REG		0x10A	//SVID Master VRM0 Interrupt Enable Register
    #define MMIO_RS_10A_2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM0_IABIE			BIT5	//0/x/x/x VRM0 ICC Max Back to Normal Alert Interrupt Enable
    #define MMIO_VRM0_TABIE			BIT4	//0/x/x/x VRM0 Thermal Back to Normal  Alert Interrupt Enable
    #define MMIO_VRM0_PAIE			BIT3	//0/x/x/x VRM0 Parity Interrupt Enable
    #define MMIO_VRM0_IAIE			BIT2	//0/x/x/x VRM0 ICC Max Alert Interrupt Enable
    #define MMIO_VRM0_TAIE			BIT1	//0/x/x/x VRM0 Thermal Alert Interrupt Enable
    #define MMIO_RS_10A_0			BIT0	//0/R/x/x Reserved
#define MMIO_SVID_MASTER_VRM0_CMD_TRIGGER_REG		0x10B	//SVID Master VRM0 Command Trigger Register
    #define MMIO_RS_10B_5			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_SVIDMV0_CMD			0x1F	//0/x/x/x SVID Master VRM0 Command
#define MMIO_SVID_MASTER_VRM0_PERIOD_READ_TIMER_REG		0x10C	//SVID Master VRM0 Period Read Timer Register
    #define MMIO_VRM0_IOUT_TIMER			0xFF	//0/x/x/x SVID Master VRM0 (CPU) Periodically Read Timer Counter
#define MMIO_SVID_MASTER_VRM0_C3_CTL_REG		0x10D	//SVID Master VRM0 C3 Control Register
    #define MMIO_RS_10D_7_1			0xFE	//0/x/x/x Reserved
    #define MMIO_SVID_C3_CTRL_DIS			BIT0	//0/x/x/x This register bit is used to gating ENLVL3 from PMU. SVID will do nothing if this bit was set to 1 during enter/exit C3.
#define MMIO_SVID_MASTER_VRM0_C4_CTL_REG		0x10E	//SVID Master VRM0 C4 Control Register
    #define MMIO_RS_10E_7_4			BIT7	//0/x/x/x Reserved
    #define MMIO_SVID_C3_PS_OP			BIT6	//0/x/x/x SVID send setPS when Enter C3
    #define MMIO_SVID_C4_PS_OP			BIT5	//0/x/x/x SVID Enter C4 send setPS after SETdecat/SetVID cmd or not
    #define MMIO_SVID_C4_DECAY_OP			BIT4	//0/x/x/x SVID Enter C4 SETdecay/SetVID select bit
    #define MMIO_SVID_C4_SETPS_SEL			(BIT2 + BIT3)	//01b/1/x/x VRM0 SetPS State Select for C4 Entry
    #define MMIO_SVID_C4_SETVID_SEL			BIT1	//0/x/x/x SVID Enter C4 SetVID Fast/Slow Select Bit
    #define MMIO_SVID_C4_CTRL_DIS			BIT0	//0/x/x/x This register bit is used to gating VRDSLP and NAP# from PMU.  SVID will do nothing if this bit was set to 1 during enter/exit C4.
#define MMIO_SVID_MASTER_VRM0_VID_REG		0x10F	//SVID Master VRM0 VID Register
    #define MMIO_VRM0_VID			0xFF	//6Fh/x/x/x SVID Master VRM0 VID value
#define MMIO_SVID_MASTER_VRM1_CTL_REG		0x110	//SVID Master VRM1 Control Register
    #define MMIO_RS_110_6			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM1_IOUT_EN			BIT5	//0/x/x/x SVIDM Will Do Iout Read Periodically (Periodically_timer_enable_reg)
    #define MMIO_VRM1_VIDS			BIT4	//0/x/x/x SetVID-Fast/Slow Select Bit
    #define MMIO_VRM1_ADR			0xF	//0h/x/x/x SVID Master VRM1 Address
#define MMIO_SVID_MASTER_VRM1_INTR_REG		0x111	//SVID Master VRM1 Interrupt Register
    #define MMIO_RS_111_2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM1_IABI			BIT5	//0/x/x/x VRM1 ICC Max Back to Normal Alert Interrupt
    #define MMIO_VRM1_TABI			BIT4	//0/x/x/x VRM1 Thermal Back to Normal Alert Interrupt
    #define MMIO_VRM1_PAI			BIT3	//0/x/x/x VRM1 Parity Interrupt
    #define MMIO_VRM1_IAI			BIT2	//0/x/x/x VRM1 ICC Max Alert Interrupt
    #define MMIO_VRM1_TAI			BIT1	//0/x/x/x VRM1 Thermal Alert Interrupt
    #define MMIO_VRM1_SAI			BIT0	//0/x/x/x VRM1Settled Alert Interrupt
#define MMIO_SVID_MASTER_VRM1_INTR_ENABLE_REG		0x112	//SVID Master VRM1 Interrupt Enable Register
    #define MMIO_RS_112_2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM1_IABIE			BIT5	//0/x/x/x VRM1 ICC Max Back to Normal  Alert Interrupt Enable
    #define MMIO_VRM1_TABIE			BIT4	//0/x/x/x VRM1 Thermal Back to Normal  Alert Interrupt Enable
    #define MMIO_VRM1_PAIE			BIT3	//0/x/x/x VRM1  Parity Interrupt Enable
    #define MMIO_VRM1_IAIE			BIT2	//0/x/x/x VRM1 ICC Max Alert Interrupt Enable
    #define MMIO_VRM1_TAIE			BIT1	//0/x/x/x VRM1 Thermal Alert Interrupt Enable
    #define MMIO_VRM1_SAIE			BIT0	//0/x/x/x VRM1 Thermal Alert Interrupt Enable
#define MMIO_SVID_MASTER_VRM1_CMD_TRIGGER_REG		0x113	//SVID Master VRM1 Command Trigger Register
    #define MMIO_RS_113_5			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_SVIDMV1_CMD			0x1F	//0/x/x/x SVID Master VRM1 Command
#define MMIO_SVID_MASTER_VRM1_PERIOD_READ_TIMER_REG		0x114	//SVID Master VRM1 Period Read Timer Register
    #define MMIO_VRM1_IOUT_TIMER			0xFF	//0/x/x/x SVID Master VRM1 Periodically Read Timer Counter
#define MMIO_SVID_MASTER_VRM1_VID_REG		0x115	//SVID Master VRM1 VID Register
    #define MMIO_VRM1_VID			0xFF	//6Fh/x/x/x SVID Master VRM1 VID value
#define MMIO_SVID_MASTER_CTL_2_REG		0x116	//SVID Master Control 2 Register
    #define MMIO_RS_116_7_3			0xF8	//0/x/x/x Reserved
    #define MMIO_PARITY_ERR_MODE			(BIT1 + BIT2)	//0/x/x/x SVID Rx Parity Error Injection Mode for Debug
    #define MMIO_SVID2SME_RSD_FAILE			BIT0	//1b/x/x/x SVID2SME Resend Fail Enable
#define MMIO_SVID_MASTER_VRM2_CTL_REG		0x118	//SVID Master VRM2 Control Register
    #define MMIO_RS_118_6			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM2_IOUT_EN			BIT5	//0/x/x/x SVIDM Will Do Iout Read Periodically (Periodically_timer_enable_reg)
    #define MMIO_VRM2_VIDS			BIT4	//0/x/x/x SetVID-Fast/Slow Select Bit
    #define MMIO_VRM2_CPU			0xF	//0/x/x/x SVID Master VRM2  Address
#define MMIO_SVID_MASTER_VRM2_INTR_REG		0x119	//SVID Master VRM2 Interrupt Register
    #define MMIO_RS_119_2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM2_IABI			BIT5	//0/x/x/x VRM2 ICC Max Back to Normal Alert Interrupt
    #define MMIO_VRM2_TABI			BIT4	//0/x/x/x VRM2 Thermal Back to Normal Alert Interrupt
    #define MMIO_VRM2_IPI			BIT3	//0/x/x/x VRM2 Parity Interrupt
    #define MMIO_VRM2_IAI			BIT2	//0/x/x/x VRM2 ICC Max Alert Interrupt
    #define MMIO_VRM2_TAI			BIT1	//0/x/x/x VRM2 Thermal Alert Interrupt
    #define MMIO_VRM2_SAI			BIT0	//0/x/x/x VRM2 Settled Alert Interrupt
#define MMIO_SVID_MASTER_VRM2_INTR_ENABLE_REG		0x11A	//SVID Master VRM2 Interrupt Enable Register
    #define MMIO_RS_11A_2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM2_IABIE			BIT5	//0/x/x/x VRM2 ICC Max Back to Normal Alert Interrupt Enable
    #define MMIO_VRM2_TABIE			BIT4	//0/x/x/x VRM2 Thermal Back to Normal Alert Interrupt Enable
    #define MMIO_VRM2_PAIE			BIT3	//0/x/x/x VRM2  Parity Interrupt Enable
    #define MMIO_VRM2_IAIE			BIT2	//0/x/x/x VRM2 ICC Max Alert Interrupt Enable
    #define MMIO_VRM2_TAIE			BIT1	//0/x/x/x VRM2 Thermal Alert Interrupt Enable
    #define MMIO_VRM2_SAIE			BIT0	//0/x/x/x VRM2 Settled Alert Interrupt Enable
#define MMIO_SVID_MASTER_VRM2_CMD_TRIGGER_REG		0x11B	//SVID Master VRM2 Command Trigger Register
    #define MMIO_RS_11B_5			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_SVIDMV2_CMD			0x1F	//0/x/x/x SVID Master VRM2 Command
#define MMIO_SVID_MASTER_VRM2_PERIOD_READ_TIMER_REG		0x11C	//SVID Master VRM2 Period Read Timer Register
    #define MMIO_VRM2_IOUT_TIMER			0xFF	//0/x/x/x SVID Master VRM2 Periodically Read Timer Counter
#define MMIO_SVID_MASTER_VRM2_VID_REG		0x11D	//SVID Master VRM2 VID Register
    #define MMIO_VRM2_VID			0xFF	//6Fh/x/x/x SVID Master VRM2 VID value
#define MMIO_SVID_MASTER_VRM4_CTL_REG		0x120	//SVID Master VRM4 Control Register
    #define MMIO_RS_120_6			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM4_IOUT_EN			BIT5	//0/x/x/x SVIDM Will Do Iout Read Periodically (Periodically_timer_enable_reg)
    #define MMIO_VRM4_VIDS			BIT4	//0/x/x/x SetVID-Fast/Slow Select Bit
    #define MMIO_VRM4_CPU			0xF	//0/x/x/x SVID Master VRM4 Address
#define MMIO_SVID_MASTER_VRM4_INTR_REG		0x121	//SVID Master VRM4 Interrupt Register
    #define MMIO_RS_121_2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM4_IABI			BIT5	//0/x/x/x VRM4 ICC Max Back to Normal Alert Interrupt
    #define MMIO_VRM4_TABI			BIT4	//0/x/x/x VRM4 Thermal Back to Normal Alert Interrupt
    #define MMIO_VRM4_PAI			BIT3	//0/x/x/x VRM4 Parity Interrupt
    #define MMIO_VRM4_IAI			BIT2	//0/x/x/x VRM4 ICC Max Alert Interrupt
    #define MMIO_VRM4_TAI			BIT1	//0/x/x/x VRM4 Thermal Alert Interrupt
    #define MMIO_VRM4_SAI			BIT0	//0/x/x/x VRM4 Settled Alert Interrupt
#define MMIO_SVID_MASTER_VRM4_INTR_ENABLE_REG		0x122	//SVID Master VRM4 interrupt Enable Register
    #define MMIO_RS_122_2			(BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_VRM4_IABIE			BIT5	//0/x/x/x VRM4 ICC Max Back to Normal Alert Interrupt Enable
    #define MMIO_VRM4_TABIE			BIT4	//0/x/x/x VRM4 Thermal Back to Normal Alert Interrupt Enable
    #define MMIO_VRM4_PAIE			BIT3	//0/x/x/x VRM4  Parity Interrupt Enable
    #define MMIO_VRM4_IAIE			BIT2	//0/x/x/x VRM4 ICC Max Alert Interrupt Enable
    #define MMIO_VRM4_TAIE			BIT1	//0/x/x/x VRM4 Thermal Alert Interrupt Enable
    #define MMIO_VRM4_SAIE			BIT0	//0/x/x/x VRM4 Settled Alert Interrupt Enable
#define MMIO_SVID_MASTER_VRM0_CMD_TRIGGER_REG_Z1		0x123	//SVID Master VRM0 Command Trigger Register
    #define MMIO_RS_123_5			(BIT5 + BIT6 + BIT7)	//0/R/x/x Reserved
    #define MMIO_SVIDMV4_CMD			0x1F	//0/x/x/x SVID Master VRM4 Command
#define MMIO_SVID_MASTER_VRM4_PERIOD_READ_TIMER_REG		0x124	//SVID Master VRM4 Period Read Timer Register
    #define MMIO_VRM4_IOUT_TIMER			0xFF	//0/x/x/x SVID Master VRM4 Periodically Read Timer Counter
#define MMIO_SVID_MASTER_VRM4_VID_REG		0x125	//SVID Master VRM4 VID Register
    #define MMIO_VRM4_VID			0xFF	//6Fh/x/x/x SVID Master VRM4 VID Value
#endif
