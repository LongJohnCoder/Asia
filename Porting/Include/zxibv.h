//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************
////
#include "CHX002Reg.h"
////
#define LPC_BUS_NO    0
#define LPC_DEV_NO    17
#define LPC_FUNC_NO   0

#define DRAM_PCI_BUS  0
#define DRAM_PCI_DEV  0
#define DRAM_PCI_FUNC 3

#define IGD_PCI_BUS   0
#define IGD_PCI_DEV   1
#define IGD_PCI_FUNC  0

// PCIE Root Port
#define PE_SVID_CTRL_REG                     0xE4

//PEMCU
#define PEMCU_MMIO_BAR_ADDR                       0x138
#define PEMCU_RESET_AUTOFILL_EN                   0x9B0
#define PEMCU_AUTOFILL_START_ADDR                 0x9B2
#define PEMCU_AUTOFILL_LENGTH                     0x9B4
#define PEMCU_FW_INSTRUCTION_BASEADDR             0x9B8
#define PEMCU_FW_DATA_BASEADDR                    0x9BC

////
#define HC_PCI_REG(Reg)           (PCI_DEV_MMBASE(0,  0, 0)+Reg)
#define ERRRPT_PCI_REG(Reg)       (PCI_DEV_MMBASE(0,  0, 1)+Reg)
//#define V4IF_PCI_REG(Reg)         (PCI_DEV_MMBASE(0,  0, 2)+Reg)
#define DRAM_PCI_REG(Reg)         (PCI_DEV_MMBASE(0,  0, 3)+Reg)
////
#define HIF_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  0, 2)+Reg)
////
#define NPMC_PCI_REG(Reg)         (PCI_DEV_MMBASE(0,  0, 4)+Reg)
#define APIC_PCI_REG(Reg)         (PCI_DEV_MMBASE(0,  0, 5)+Reg)
#define SCRCH_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  0, 6)+Reg)
#define IGD_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  1, 0)+Reg)
#define IGDAC_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  1, 1)+Reg)
////
#define PEG_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  2, 0)+Reg)
#define PE0_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  3, 0)+Reg)
/*//LNA-20161031-S
#define PE1_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  4, 0)+Reg)
#define PE2_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  5, 0)+Reg)
#define PE3_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  6, 0)+Reg)
#define PE4_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  7, 0)+Reg)
*///LNA-20161031-E
//LNA-20161031-S
#define PE1_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  3, 1)+Reg)
#define PE2_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  3, 2)+Reg)
#define PE3_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  3, 3)+Reg)
#define PEG0_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  4, 0)+Reg)
#define PEG1_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  4, 1)+Reg)
#define PEG2_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  5, 0)+Reg)
#define PEG3_PCI_REG(Reg)          (PCI_DEV_MMBASE(0,  5, 1)+Reg)
//LNA-20161031-E
#define VPI_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  7, 0)+Reg)

///
#define RAIDA0_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  8, 0)+Reg)
#define RAIDA1_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  9, 0)+Reg)

//HYL-20160916-start
#define UART0_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  10, 0)+Reg)
#define UART1_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  10, 1)+Reg)
#define UART2_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  10, 2)+Reg)
#define UART3_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  10, 3)+Reg)
#define ESPI_PCI_REG(Reg)        (PCI_DEV_MMBASE(0,  11, 0)+Reg)
//HYL-20160916-end

#define SATA_PCI_REG(Reg)         (PCI_DEV_MMBASE(0, 15, 0)+Reg)
#define UHCI_PCI_REG(func,Reg)    (PCI_DEV_MMBASE(0, 16, func)+Reg)
#define EHCI_PCI_REG(Reg)         (PCI_DEV_MMBASE(0, 16, 7)+Reg)
#define LPC_PCI_REG(Reg)          (PCI_DEV_MMBASE(0, 17, 0)+Reg)
#define SNMIC_PCI_REG(Reg)        (PCI_DEV_MMBASE(0, 17, 7)+Reg)
#define XHCI_PCI_REG(Reg)         (PCI_DEV_MMBASE(0, 18, 0)+Reg)
#define HDAC_PCI_REG(Reg)         (PCI_DEV_MMBASE(0, 20, 0)+Reg)

////
// DRAM
#define IBV_D0F3_RESERVED_Z4                     0x120  // this reg has changed to Rx120 for CHX001
#define   D0F3_REF_STP                         BIT0
#define CPU_DAFBC_REG                        0x124             // CPU Direct Access Frame Buffer Control
//SVADDVAD(D0F2)
#define PAGE_C_SHADOW_CTRL_REG               0xA0
#define PAGE_E_SHADOW_CTRL_REG               0xA2
#define   MEM_E0000_4K_RW_EN                   (BIT7+BIT7)
#define   MEM_E4000_4K_RW_EN                   (BIT4+BIT5)
#define   MEM_E8000_4K_RW_EN                   (BIT2+BIT3)
#define   MEM_EC000_4K_RW_EN                   (BIT0+BIT1)

#define PAGE_F_SHADOW_MH_SD_REG              0xA3
#define   MEM_F0000_64K_RW_EN                  (BIT1+BIT0)

#define SMM_APIC_DECODE_REG                  0x9E
#define SVAD_VGA_DECODE_REG                   0x9C

///
#define   SMM_TSEG_SIZE_MASK                   (BIT0+BIT1)
#define   SMM_TSEG_SIZE_1M                     0
#define   SMM_TSEG_SIZE_2M                     BIT0
#define   SMM_TSEG_SIZE_4M                     BIT1
#define   SMM_TSEG_SIZE_8M                     (BIT0+BIT1)
#define   TSMM_EN                                   BIT2
#define   TSEG_C2M_PROTECT_DISABLE     BIT4
#define   SVAD_ABSEG_SEL                 (BIT2+BIT1)

// NPMC (D0F4)
#define DRAM_DYNCLK_CTRL_REG                 0x70
#define D0F4_INTERNAL_REV_ID                 0xF6


////
////
// SpiBar registers as sample. 2016-05-16
#define SPI0_SPIS_REG                        SPI0MMIO_SPI_STA_SPIS
#define   SPI0_SPIS_CYCLE_PROGRESS             SPI0MMIO_SCIP
#define   SPI0_SPIS_CYCLE_DONE                 SPI0MMIO_BUS_CDS
#define   SPI0_SPIS_BLKACC                     SPI0MMIO_BAS
#define   SPI0_SPIS_LOCKDOWN                   SPI0MMIO_CLD
///
#define SPI0_SPIC_REG                        SPI0MMIO_SPI_CTL_SPIC
#define   SPI0_SPIC_GO                         SPI0MMIO_BUS_SCGO
///
#define SPI0_SPIA_REG                        SPI0MMIO_SPI_ADR_SPIA
#define SPI0_SPID0_REG                       SPI0MMIO_SPI_DATA_0_REG_SPID0
#define SPI0_SPID1_REG                       SPI0MMIO_SPI_DATA_1_REG_SPID1
///
#define SPI0_PREOP_REG                       SPI0MMIO_PREFIX_OPCODE_CFG_PREOP 
#define SPI0_OPTYPE_REG                      SPI0MMIO_OPCODE_TYPE_CFG_OPTYPE
///
#define   SPI0_OPTYPE_RDNOADDR                 0x00                          // Read cycle type without address
#define   SPI0_OPTYPE_WRNOADDR                 0x01                          // Write cycle type without address
#define   SPI0_OPTYPE_RDADDR                   0x02                          // Address required; Read cycle type
#define   SPI0_OPTYPE_WRADDR                   0x03                          // Address required; Write cycle type
///
#define SPI0_OPMENU_REG                      SPI0MMIO_OPCODE_MENU_CFG_OPMENU

#define SPI0_PROTECTED_BIOS_RANGE0_BASE           SPI0MMIO_PROTECTED_BIOS_RANGE_0_PBR0
#define SPI0_PROTECTED_BIOS_RANGE1_BASE           SPI0MMIO_PROTECTED_BIOS_RANGE_1_PBR1
#define SPI0_PROTECTED_BIOS_RANGE2_BASE           SPI0MMIO_PROTECTED_BIOS_RANGE_2_PBR2

#define SPI0_PROTECTED_BIOS_RANGE0_LIMIT		  SPI0MMIO_PROTECTED_BIOS_RANGE0_PBR0_L
#define SPI0_PROTECTED_BIOS_RANGE1_LIMIT		  SPI0MMIO_PROTECTED_BIOS_RANGE1_PBR1_L
#define SPI0_PROTECTED_BIOS_RANGE2_LIMIT		  SPI0MMIO_PROTECTED_BIOS_RANGE2_PBR2_L

#define SPI0_MISC_CTL1_REG                   SPI0MMIO_SPI_BUS_0_MISC_CTL_1

//HYL2018032301-start
#define SPI0_BIOS_BASE_ADR_BBAR                   SPI0MMIO_BIOS_BASE_ADR_BBAR
#define SPI0_ESPI_MASTER_SLAVE_ATTACHED_MODE_STA_REG                   SPI0MMIO_ESPI_MASTER_SLAVE_ATTACHED_MODE_STA_REG
//HYL2018032301-end

////
// ACPI PM 
#define PMIO_REG(Reg)      (PcdGet16(AcpiIoPortBaseAddress)+Reg)



#define   PMIO_PM1_CNT_S0       0x0000
#define   PMIO_PM1_CNT_S1       0x1000		// 4
#define   PMIO_PM1_CNT_S3       0x0400		// 1
#define   PMIO_PM1_CNT_S4       0x0C00		// 3
#define   PMIO_PM1_CNT_S5       0x0800		// 2



#define SB_SWSMI_PORT_REG     (UINT16)(PMIO_REG(PMIO_SW_SMI_CMD))
#define SB_SWSMI_DATA_REG     (UINT16)(PMIO_REG(PMIO_SW_SMI_DATA))


///
// LPC (D17F0)
///
#define LPC_GP23TIMER_CTRL_REG_DEF_VALUE       0x10

// SNMIC (D17F7)
#define SNMIC_SNMIC_CTRL_REG                 0x4F
#define   SNMIC_CTRL_P2PB_EN                   BIT6
#define SNMIC_DRAM_BANK7_END_REG             0x60
#define SNMIC_E_SHADOW_CTRL_REG              0x64
#define SNMIC_PCI_IO_CYCLE_CTRL_REG          0x8A
#define   SNMIC_RX2C_SEL                       BIT3
#define SNMIC_HDAC_P2P_CTRL_REG              0xD1
#define   P2P_CONF_CAP_RW_EN                   BIT3
#define SNMIC_SSID_BACKDOOR_REG              0xD4

// HDAC
#define HDAC_SSID_BACKDOOR_EN_REG            0x40
#define   HDAC_SSID_BACKDOOR_EN                BIT0

/// SATA
#define AHCI_DEVICE_ID            0x9083
#define IDE_DEVICE_ID1            0x9002
#define IDE_DEVICE_ID2            0x9003

