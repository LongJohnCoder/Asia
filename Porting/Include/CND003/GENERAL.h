//**************************************************************************
//**************************************************************************
//**                                                                      **
//**  Copyright (c) 2015 - 2017 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                      **
//**************************************************************************
//**************************************************************************
#include "RegCommon.h"

#define BUS0	0
#define BUSX	1
#define BUSXP1	2
#define BUSXP2	3
#define BUSXP3	4
//#define BUSX_MMIO_BAR		0xFE028000	//In CND001, From FE016000 to FEBFFFFF, Not be assigned before

#define PCI_BASE	0xE0000000
#define MMIO_ISB_OFFSET 0x1100
#define BUSX_BAR0_BASE 			0xF0200000	 //This is a temp bar for IOE PEEP BAR0
#define BUSXP3_GNIC_BAR1_BASE  	0xF0100000	//This is a temp bar for IOE GNIC
#define BUSXP3_GNIC_BAR2_BASE  	0xF0108000	//This is a temp bar for IOE GNIC
#define MEM_BASE_LIMIT			0xF010F010	//This is a temp base limit for IOE bridges
#define RP_MEM_BASE 	0xF010
#define RP_MEM_LIMIT	0xF020

#define UPPORT_DEV	0
#define UPPORT_FUN  0
#define DNPORT_FUN  0
#define PCIEIF_DEV	0
#define PCIEIF_FUN	0
#define EPTRFC_DEV  0
#define EPTRFC_FUN  0

//For PERST#
#define XBCTL	0
#define PEA0	1
#define PEA1	2
#define PEA2	3
#define PEA3	4	
#define PEA4	5
#define PEB0	6
#define PEB1	7
#define PESB	8

#define DEV_GNIC  0xD
#define FUN_GNIC  0
#define DEV_SATA  0xF
#define FUN_SATA  0
#define DEV_XHCI  0x12
#define FUN_XHCI  0
#define DEV_UHCI  0x10  
#define FUN_UHCI  0
#define DEV_EHCI  0x10
#define FUN_EHCI  7




#define CND003_PEEP ASIA_PCI_ADDRESS(BUSX, UPPORT_DEV, UPPORT_FUN, 0) //PEEP  
#define CND003_XBCTL ASIA_PCI_ADDRESS(BUSXP1, XBCTL, DNPORT_FUN, 0) 	//XBCTL
#define CND003_PEA0 ASIA_PCI_ADDRESS(BUSXP1, PEA0, DNPORT_FUN, 0) 	//PEA0
#define CND003_PEA1 ASIA_PCI_ADDRESS(BUSXP1, PEA1, DNPORT_FUN, 0) 	//PEA1
#define CND003_PEA2 ASIA_PCI_ADDRESS(BUSXP1, PEA2, DNPORT_FUN, 0) 	//
#define CND003_PEA3 ASIA_PCI_ADDRESS(BUSXP1, PEA3, DNPORT_FUN, 0) 	//
#define CND003_PEA4 ASIA_PCI_ADDRESS(BUSXP1, PEA4, DNPORT_FUN, 0) 	//
#define CND003_PEB0 ASIA_PCI_ADDRESS(BUSXP1, PEB0, DNPORT_FUN, 0) 	//PEB0
#define CND003_PEB1 ASIA_PCI_ADDRESS(BUSXP1, PEB1, DNPORT_FUN, 0) 	//
#define CND003_PESB ASIA_PCI_ADDRESS(BUSXP1, PESB, DNPORT_FUN, 0) 	//PESB
#define CND003_PCIEIF ASIA_PCI_ADDRESS(BUSXP2, PCIEIF_DEV, PCIEIF_FUN, 0) //PCIEIF
#define CND003_EPTRFC ASIA_PCI_ADDRESS(BUSXP3, EPTRFC_DEV, EPTRFC_FUN, 0) //EPTRFC




#define CND003_SATA_DEV   15
#define CND003_USBC0_DEV   14
#define CND003_USBC1_DEV   16
#define CND003_XHCI_DEV   18
#define CND003_GNIC_DEV   13
#define CND003_SATA       ASIA_PCI_ADDRESS(0x4, CND003_SATA_DEV, 0, 0) // D15F0
#define CND003_D14UHC0 ASIA_PCI_ADDRESS(0x4, CND003_USBC0_DEV, 0, 0) // D14F0
#define CND003_D14UHC1 ASIA_PCI_ADDRESS(0x4, CND003_USBC0_DEV, 1, 0) // D14F1
#define CND003_D14UHC2 ASIA_PCI_ADDRESS(0x4, CND003_USBC0_DEV, 2, 0) // D14F2
#define CND003_D16UHC0 ASIA_PCI_ADDRESS(0x4, CND003_USBC1_DEV, 0, 0) // D16F0
#define CND003_D16UHC1 ASIA_PCI_ADDRESS(0x4, CND003_USBC1_DEV, 1, 0) // D16F1
#define CND003_D16UHC2 ASIA_PCI_ADDRESS(0x4, CND003_USBC1_DEV, 2, 0) // D16F2
#define CND003_D14EHCI ASIA_PCI_ADDRESS(0x4, CND003_USBC0_DEV, 7, 0) // D14F7
#define CND003_D16EHCI ASIA_PCI_ADDRESS(0x4, CND003_USBC1_DEV, 7, 0) // D16F7
#define CND003_XHCI ASIA_PCI_ADDRESS(0x4, CND003_XHCI_DEV, 0, 0) // D18F0
#define CND003_GNIC ASIA_PCI_ADDRESS(0x4, CND003_GNIC_DEV, 0, 0) // D13F0



#define IOE_BUSX_D0F0 CND003_PEEP
#define IOE_BUSXp1_D0F0 CND003_XBCTL
#define IOE_BUSXp1_D6F0 CND003_PEB0
#define IOE_BUSXp1_D7F0 CND003_PEB1
#define IOE_BUSXp1_D8F0 CND003_PESB
#define IOE_BUSXp2_D0F0 CND003_PCIEIF
#define IOE_BUSXp3_D0F0 CND003_EPTRFC
#define IOE_BUSXp3_D15F0 CND003_SATA


#define IOE_REVISION_A0  0x00
#define IOE_REVISION_A1  0x01



