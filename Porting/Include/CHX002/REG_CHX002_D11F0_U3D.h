//************************************************************************
//************************************************************************
//**									**
//**     Copyright (c) 2015 Shanghai Zhaoxin Semiconductor Co., Ltd. 	**
//**     Project:		CHX002					**
//**     Module:		USB11					**
//**									**
//************************************************************************
//************************************************************************

///
#ifndef REG_CHX001_D11F0_U3D_H
#define REG_CHX001_D11F0_U3D_H
// D11F0
#define D11F0_VID 0x0 // Vendor ID
    #define D11F0_VIA_ID_CODE D11F0_VID // 1106h/R/x/x VIA Technology ID Code
#define D11F0_DID 0x2 // Device ID
    #define D11F0_DEV_ID_CODE D11F0_DID // 9240h/R/x/x Device ID Code
#define D11F0_PCI_CMD 0x4 // PCI Command
    #define D11F0_INT_CTRL          BIT10   // 0/x/x/x Interrupt Control
    #define D11F0_MEMWR_INVALD_EN   BIT4    // 0/x/x/x Memory Write and Invalidation Enable
    #define D11F0_BUS_MASTER        BIT2    // 0/x/x/x Bus Master
    #define D11F0_MEM_SPACE         BIT1    // 0/x/x/x Memory Space
    #define D11F0_IO_SPACE          BIT0    // 0/x/x/x I/O Space
#define D11F0_PCI_STA 0x6 // PCI Status
    #define D11F0_DEV_TIMING    (BIT9 + BIT10)          // 01b/R/x/x DEVSEL# Timing
    #define D11F0_ONLY_33M      BIT5                    // 0/R/x/x Device can work under 33Mhz only
    #define D11F0_NEWCAP_LINK   BIT4                    // 1b/R/x/x There is new capabilities link.
    #define D11F0_INT_STATUS    BIT3                    // 0/R/x/x Interrupt Status
#define D11F0_REV_ID 0x8 // Revision ID
    #define D11F0_RVS_ID D11F0_REV_ID // 00h/R/x/x Revision ID
#define D11F0_CLASS_CODE 0x9 // Class Code
    #define D11F0_CLASS_CODE_Z1 D11F0_CLASS_CODE // 028000h/R/x/x Class Code
#define D11F0_CACHE_LINE_SIZE 0xC // Cache Line Size
    #define D11F0_CACHE_LINE_SIZE_Z1 D11F0_CACHE_LINE_SIZE // 0/x/x/x Cache Line Size
#define D11F0_LATENCY_TIMER 0xD // Latency Timer
    #define D11F0_LATENCY_TIMER_Z1 D11F0_LATENCY_TIMER // 0/x/x/x Latency Timer
#define D11F0_HDR_TYPE_DEFAULT 0xE // Header Type Default
    #define D11F0_HEADER_TYPE D11F0_HDR_TYPE_DEFAULT // 0/R/x/x Header Type
#define D11F0_BIST 0xF // Built In Self Test (BIST)
    #define D11F0_BIST_Z1 D11F0_BIST // 0/R/x/x BIST
#define D11F0_MMIO_BASE_ADR 0x10 // MMIO Base Address
    #define D11F0_AD            0xFFFFF000      // 0/x/x/x Corresponding to AD[31:12]
    #define D11F0_MEM_MAPPING   (BIT1 + BIT2)   // 0/R/x/x Memory Mapping
#define D11F0_RESERVED 0x14 // Reserved
#define D11F0_SVID 0x2C // Subsystem Vendor ID
    #define D11F0_SUBSYS_VENDER_ID D11F0_SVID // 1106h/R/x/x Subsystem Vendor ID
#define D11F0_SSID 0x2E // Subsystem ID
    #define D11F0_SUBSYS_ID D11F0_SSID // 9240h/R/x/x Subsystem ID
#define D11F0_PM_CAP 0x34 // Power Management Capability
    #define D11F0_PWR_MAN_CAP D11F0_PM_CAP // 80h/R/x/x Power Management Capability
#define D11F0_INTR_LINE 0x3C // Interrupt Line
    #define D11F0_INT_ROUTING D11F0_INTR_LINE // 0/x/x/x USB Interrupt Routing
#define D11F0_INTR_PIN 0x3D // Interrupt Pin
    #define D11F0_INT_PIN D11F0_INTR_PIN // 01h/R/x/x Interrupt Pin
#define D11F0_BACKDOOR_CTL 0x41 // Backdoor Control
    #define D11F0_BACKDOOR_EN           BIT4                    // 0/0/x/x Backdoor Enable and Value Write Enable
    #define D11F0_SUBID_BACKDOOR_EN     BIT3                    // 0/0/x/x Subsystem ID and Subsystem Vendor ID Backdoor Enable
    #define D11F0_CLSCODE_BACKDOOR_EN   BIT2                    // 0/0/x/x Class Code Backdoor Enable
    #define D11F0_DEVID_BACKDOOR_EN     BIT1                    // 0/0/x/x Device ID Backdoor Enable
    #define D11F0_UD64_BACKDOOR_EN      BIT0                    // 0/0/x/x 64-Bit Address Space Enable
#define D11F0_UP_DOWNSTREAM_CYCLE_CTL 0x42 // Up/Downstream cycle control
    #define D11F0_UDDSDECEN BIT2    // 1/1/x/x UDDSDECEN
    #define D11F0_UDUSRHP   BIT1    // 0/R/x/x UDUSRHP
    #define D11F0_UDUSWHP   BIT0    // 0/R/x/x UDUSWHP
#define D11F0_DYNAMIC_CLK_CTL_REG 0x43 // Dynamic clock Control Register
    #define D11F0_DYNCLK_EN BIT0    // 0/0/x/x Dynamic clock control for all. ((Random))
#define D11F0_DYNAMIC_CLK_CTL_REG_Z1 0x44 // Dynamic clock Control Register
    #define D11F0_EVTR_CLK_U250_DYDIS                       BIT25       // 1/1/x/x Dynamic clock control for Event Ring 250M.   ((Random))
    #define D11F0_CTLO_CLK_U250_DYDIS                       BIT24       // 1/1/x/x Dynamic clock control for Control Out 250M.   ((Random))
    #define D11F0_CTLI_CLK_U250_DYDIS                       BIT23       // 1/1/x/x Dynamic clock control for Control In 250M.   ((Random))
    #define D11F0_CMD_CLK_U250_DYDIS                        BIT22       // 1/1/x/x Dynamic clock control for CMD Pipe 250M.   ((Random))
    #define D11F0_STAT_CLK_U250_DYDIS                       BIT21       // 1/1/x/x Dynamic clock control for Status Pipe 250M.   ((Random))
    #define D11F0_BLKO_CLK_U250_DYDIS                       BIT20       // 1/1/x/x Dynamic clock control for Bulk Out 250M. ((Random))
    #define D11F0_BLKI_CLK_U250_DYDIS                       BIT19       // 1/1/x/x Dynamic clock control for Bulk In 250M. ((Random))
    #define D11F0_BUFO_CLK_U250_DYDIS                       BIT18       // 1/1/x/x Dynamic clock control for BUFO 250M. ((Random))
    #define D11F0_BUFI_CLK_U250_DYDIS                       BIT17       // 1/1/x/x Dynamic clock control for BUFI 250M. ((Random))
    #define D11F0_DMAM_CLK_U250W_DYDIS                      BIT16       // 1/1/x/x Dynamic clock control for DMAMUX W 250M.  ((Random))
    #define D11F0_DMAM_CLK_U250R_DYDIS                      BIT15       // 1/1/x/x Dynamic clock control for DMAMUX R 250M. ((Random))
    #define D11F0_ENDP_CLK_U125_DYDIS                       BIT14       // 1/1/x/x Dynamic clock control for Endpoint 125M. ((Random))
    #define D11F0_PCIS_CLK_U125_DYDIS                       BIT13       // 1/1/x/x Dynamic clock control for PCIS 125M. ((Random))
    #define D11F0_EVTG_CLK_U125_DYDIS                       BIT12       // 1/1/x/x Dynamic clock control for Event Gen 125M. ((Random))
    #define D11F0_ARBO_CLK_U125_DYDIS                       BIT11       // 1/1/x/x Dynamic clock control for Arb Out 125M. ((Random))
    #define D11F0_ARBI_CLK_U125_DYDIS                       BIT10       // 1/1/x/x Dynamic clock control for Arb In 125M. ((Random))
    #define D11F0_CTLO_CLK_U125_DYDIS                       BIT9        // 1/1/x/x Dynamic clock control for Ctrl Out 125M. ((Random))
    #define D11F0_CTLI_CLK_U125_DYDIS                       BIT8        // 1/1/x/x Dynamic clock control for Ctrl In 125M. ((Random))
    #define D11F0_CMD_CLK_U125_DYDIS                        BIT7        // 1/1/x/x Dynamic clock control for CMD Pipe 125M. ((Random))
    #define D11F0_STAT_CLK_U125_DYDIS                       BIT6        // 1/1/x/x Dynamic clock control for Status Pipe 125M.   ((Random))
    #define D11F0_BLKO_CLK_U125_DYDIS                       BIT5        // 1/1/x/x Dynamic clock control for Bulk Out 125M ((Random))
    #define D11F0_BLKI_CLK_U125_DYDISBLKI_CLK_U125_DYDIS    BIT4        // 1/1/x/x Dynamic clock control for Bulk In 125M. ((Random))
    #define D11F0_EVTR_CLK_U125_DYDIS                       BIT3        // 1/1/x/x Dynamic clock control for Event Ring. ((Random))
    #define D11F0_PCIS_CLK_HCLK_DYDIS                       BIT2        // 1/1/x/x Dynamic clock control for HCLK. ((Random))
    #define D11F0_DMAM_HCLKW_DYDIS                          BIT1        // 1/1/x/x Dynamic clock control for HCLK W. ((Random))
    #define D11F0_DMAM_HCLKR_DYDIS                          BIT0        // 1/1/x/x Dynamic clock control for HCLK R. ((Random))
#define D11F0_DEBUG_SIGNAL_CTL_REG 0x48 // Debug Signal Control Register
    #define D11F0_DBG_GRP_SEL1  0x7F00  // 00h/x/x/x Debug Signal Group Select for Port 2 (High 32bits)
    #define D11F0_DBG_GRP_SEL0  0x7F    // 00h/x/x/x Debug Signal Group Select for Port 1 (Low 32bits)
#define D11F0_DEBUG_SIGNAL_CTL_REG_Z1 0x4A // Debug Signal Control Register
    #define D11F0_DBG_EN    BIT0    // 0/x/x/x Debug Signal Enable
#define D11F0_SUS_REG 0x4C // Sus register
    #define D11F0_IHB_C4P_BACKDOOR  BIT12   // 0/0/x/x The backdoor of inhibit system going to C4P
    #define D11F0_UXTOU0_EN         BIT10   // 0/R/x/x UXTOU0 enable bit
    #define D11F0_U3D_DSCON_EN      BIT9    // 0/R/x/x Disconnect USB3D enable bit
    #define D11F0_U3D_CON_EN        BIT8    // 0/R/x/x Connect USB3D enable bit
    #define D11F0_IHB_C4P_CON_EN    BIT7    // 0/R/x/x Inhibit  system going to C4P when usb3d connected to host
    #define D11F0_IHB_C4P_LNK_EN    BIT6    // 0/R/x/x Inhibit system going to C4P when IP Link layer is ready
    #define D11F0_IHB_C4P_EVT_EN    BIT5    // 0/R/x/x Inhibit system going to C4P when Event ring is not empty
    #define D11F0_IHB_C4P_DMA_EN    BIT4    // 0/R/x/x Inhibit system going to C4P when DMA is busy
    #define D11F0_SSPORT_DISABLE    BIT3    // 0/R/x/x Hardware Attach Process Evaluation Enable
    #define D11F0_C4P_CON_EN        BIT2    // 0/R/x/x UD APIDLE  Control bit -- Level 1
    #define D11F0_SS_RESUME_EN      BIT1    // 0/R/x/x Suspend Resume Enable bit
    #define D11F0_IHB_CX_EN         BIT0    // 0/R/x/x UD APIDLE Control bit -- Level 2
#define D11F0_CLASS_CODE_BACK_DOOR 0x5C // Class Code Back Door
    #define D11F0_CLSCODE_BACKDOOR D11F0_CLASS_CODE_BACK_DOOR // 028000h/028000h/x/x Class Code Back Door
#define D11F0_SSID_BACK_DOOR 0x60 // Subsystem ID Back Door
    #define D11F0_SUBSYS_ID_BACKDOOR D11F0_SSID_BACK_DOOR // 1106h/1106h/x/x Subsystem ID Back Door
#define D11F0_SVID_BACKDOOR 0x62 // Subsystem Vendor ID Backdoor
    #define D11F0_SUBSYS_VENDER_ID_BACKDOOR D11F0_SVID_BACKDOOR // A409h/A409h/x/x Subsystem Vendor ID Back Door
#define D11F0_DID_BACK_DOOR 0x64 // Device ID Back Door
    #define D11F0_DEVID_BACKDOOR D11F0_DID_BACK_DOOR // A409h/A409h/x/x Device ID Back Door
#define D11F0_USBD_PCIS_FREE_RUN_CLK_ENABLE_BACK_DOOR 0x66 // USBD PCIS Free Run Clock Enable Back Door
    #define D11F0_PCIS_FR_EN    BIT0    // 0/0/x/x USBD PCIS Free Run Clock Enable((Random))
#define D11F0_USB_DEV_PM_CAPS_ID 0x80 // USB Device Power Management Capabilities ID
    #define D11F0_USBD_PWM_CAP_ID D11F0_USB_DEV_PM_CAPS_ID // 01h/R/x/x USB Device Power Management Capabilities ID
#define D11F0_NEXT_LINKED_ITEM 0x81 // Next Linked Item
    #define D11F0_NXT_LINKED_ITEM D11F0_NEXT_LINKED_ITEM // 00h/R/x/x Next Linked Item
#define D11F0_PM_CAPS 0x82 // Power Management Capabilities
    #define D11F0_PWM_CAP D11F0_PM_CAPS // ffc2h/R/x/x Power Management Capabilities
#define D11F0_PM_STA 0x84 // Power Management Status
    #define D11F0_PME_STATE     BIT15           // 0/0/x/x PME Status
    #define D11F0_PME_ENABLE    BIT8            // 0/0/x/x PME Enable
    #define D11F0_PW_STATE      (BIT0 + BIT1)   // 0/0/x/x Power State
// USBD MMIO
#define USBDMMIO_CTLLOR_REG 0x0 // Controllor Register
    #define USBDMMIO_CTRLEP_INT_GENMODE     BIT29                   // 0/x/x/x Control Endpoint Interrupt Generation Mode
    #define USBDMMIO_TRINT_GENMODE          BIT28                   // 0/x/x/x Data Transfer Ring Interrupt Generation Mode
    #define USBDMMIO_CMDPIPE_INT_GENMODE    BIT27                   // 0/x/x/x Command Pipe Endpoint Interrupt Generation Mode
    #define USBDMMIO_STATPIPE_INT_GENMODE   BIT26                   // 0/x/x/x Status Pipe Endpoint Interrupt Generation Mode.
    #define USBDMMIO_INTEP_INT_GENMODE      BIT25                   // 0/x/x/x Reserved
    #define USBDMMIO_U3DINT_EN              BIT24                   // 0/x/x/x Interrupt Enable For Usb Device.
    #define USBDMMIO_CTRL_EPT_EN            BIT21                   // 0/x/x/x Control Endpoint Enable Control.
    #define USBDMMIO_BLKOUT_EPT_EN          BIT20                   // 0/x/x/x Out Data (Bulk Out) Endpoint Enable Control.
    #define USBDMMIO_BLKIN_EPT_EN           BIT19                   // 0/x/x/x In Data Pipe (Bulk In) Endpoint Enable Control.
    #define USBDMMIO_CMD_EPT_EN             BIT18                   // 0/x/x/x Command Pipe (Bulk Out) Endpoint Enable Control.
    #define USBDMMIO_STAT_EPT_EN            BIT17                   // 0/x/x/x Status Pipe (Bulk In) Endpoint Enable Control.
    #define USBDMMIO_INT_EP_EN              BIT16                   // 0/x/x/x Interrupt Endpoint Enable Control.
    #define USBDMMIO_DEV_ADDR_CHG           BIT15                   // 0/x/x/x Device Address Change. 
    #define USBDMMIO_WRDEV_ADDR             0x7F00                  // 0/x/x/x Device Address. 
    #define USBDMMIO_WRKING_MODE            BIT4                    // 0/x/x/x Reserved
    #define USBDMMIO_EOB_EN_OPT             BIT3                    // 0/x/x/x EOB Enable Option (Internal Reference)
    #define USBDMMIO_CONTROLLER_RST         BIT2                    // 0/x/x/x Controller Reset  
    #define USBDMMIO_RUN_STOP               BIT1                    // 0/x/x/x Run/Stop Control For USB Device Mode.
    #define USBDMMIO_PORT_STATUS_CHG        BIT0                    // 0/x/x/x Port Status Change Detection Control
#define USBDMMIO_DMA_STA_AND_PORT_STA_REG 0x4 // DMA Status and Port Status register
    #define USBDMMIO_CTRLOUT_DMA_STATUS     BIT14           // 0/R/x/x Default Control Out DMA Status.
    #define USBDMMIO_CTRLIN_DMA_STATUS      BIT13           // 0/R/x/x Default Control In DMA Status.
    #define USBDMMIO_BLKOUT_DMA_STATUS      BIT12           // 0/R/x/x Out Data Pipe (Bulk Out) Endpoint Dma Status
    #define USBDMMIO_BLKIN_DMA_STATUS       BIT11           // 0/R/x/x In Data Pipe (Bulk In) Endpoint Dma Status
    #define USBDMMIO_CMDPIPE_DMA_STATUS     BIT10           // 0/R/x/x Command Pipe (Bulk Out) Endpoint Dma Status
    #define USBDMMIO_STATPIPE_DMA_STATUS    BIT9            // 0/R/x/x Status Pipe (Bulk In) Endpoint Dma Status
    #define USBDMMIO_INTEP_DMA_STATUS       BIT8            // 0/R/x/x Interrupt Endpoint DMA Status
    #define USBDMMIO_U3D_CON_STATUS         BIT5            // 0/R/x/x Usb Device Connection Status
    #define USBDMMIO_VOIDPORT_RST           BIT4            // 0/R/x/x Reserved
    #define USBDMMIO_PORT_LINK_STATE        0xF             // 4h/R/x/x Port Link State (PLS). 
#define USBDMMIO_INTR_STA_REG_LEVEL_1 0x8 // Interrupt Status register (Level 1)
    #define USBDMMIO_CTRL_TRANS_INT_STATUS      BIT23       // 0/R/x/x Default Control Endpoint Interrupt Status. 
    #define USBDMMIO_BLKOUT_TRANS_INT_STATUS    BIT22       // 0/R/x/x OUT Data Pipe (Bulk Out) Interrupt Status. 
    #define USBDMMIO_BLKIN_TRANS_INT_STATUS     BIT21       // 0/R/x/x IN Data Pipe (Bulk In) Interrupt Status. 
    #define USBDMMIO_CMDPIPE_TRANS_INT_STATUS   BIT20       // 0/R/x/x Command Pipe (Bulk Out) Interrupt Status. 
    #define USBDMMIO_STATPIPE_TRANS_INT_STATUS  BIT19       // 0/R/x/x Status Pipe (Bulk In) Interrupt Status. 
    #define USBDMMIO_INT_TRANS_INT_STATUS       BIT18       // 0/R/x/x Interrupt Endpoint Interrupt Status. 
    #define USBDMMIO_PORT_STAUTS_CHG_INT        BIT17       // 0/R/x/x Port Status Change Interrupt Status. 
    #define USBDMMIO_ER_INT_STATUS              BIT16       // 0/R/x/x Event Ring Interrupt Status. 
    #define USBDMMIO_U3D_DISCON_INT             BIT3        // 0/x/x/x USB Device Disconnect Interrupt
    #define USBDMMIO_U3D_CON_INT                BIT2        // 0/x/x/x USB Device Connected Interrupt
    #define USBDMMIO_VOIDPORT_RST_CHG           BIT1        // 0/x/x/x Reserved
    #define USBDMMIO_PORT_LINK_STATUS_CHG       BIT0        // 0/x/x/x Port Link Status Change. 
#define USBDMMIO_PORT_STA_CHANGE_INTR_CTL 0xC // Port Status Change Interrupt Control
    #define USBDMMIO_PORT_STATUS_CHG_INT_EN     BIT15       // 0/x/x/x Port Status Change Interrupt Enable 
    #define USBDMMIO_U3D_DISCON_INT_EN          BIT3        // 0/x/x/x USB Device Disconnected Interrupt Enable
    #define USBDMMIO_U3D_CON_INT_EN             BIT2        // 0/x/x/x USB Device Connected Interrupt Enable
    #define USBDMMIO_VOIDPORT_RST_CHG_INT_EN    BIT1        // 0/x/x/x Reserved
    #define USBDMMIO_PORT_LINK_CHG_INT_EN       BIT0        // 0/x/x/x Port Link Status Change Interrupt Enable
#define USBDMMIO_ENDPOINT_INTR_STA_REG 0x10 // Endpoint Interrupt Status Register
    #define USBDMMIO_INTEP_NODATA_RDY       BIT17       // 0/x/x/x Interrupt Endpoint Needs More Data Interrupt
    #define USBDMMIO_INTEP_RPTTIME_REACH    BIT16       // 0/x/x/x The Times Of Interrupt Endpoint Transfer  Is Reach Interrupt
    #define USBDMMIO_SETUP_CMD_VLD          BIT14       // 0/x/x/x Valid 8 Bytes Setup Command Is Received Interrupt
    #define USBDMMIO_STATUS_TP_VLD          BIT13       // 0/x/x/x Control Endpoint Received Valid STATUS TP Interrupt.
    #define USBDMMIO_CTRLOUT_TR_EMPTY       BIT11       // 0/x/x/x Control Out Transfer Ring Empty Interrupt
    #define USBDMMIO_CTRLEP_BABBLE          BIT10       // 0/x/x/x Control Out Endpoint Babble Error Is Detected
    #define USBDMMIO_CTRLOUT_IOC            BIT9        // 0/x/x/x Control Out Transfer IOC Status 
    #define USBDMMIO_CTRLEP_SHTPKT          BIT8        // 0/x/x/x Control Out Endpoint Short Package Status
    #define USBDMMIO_CTRLIN_TR_EMPTY        BIT3        // 0/x/x/x Control In Transfer Ring Empty Interrupt
    #define USBDMMIO_CTRLIN_IOC             BIT1        // 0/x/x/x Control In Transfer IOC Status 
#define USBDMMIO_ENDPOINT_INTR_STA_REG_2 0x14 // Endpoint Interrupt Status Register 2
    #define USBDMMIO_BLKOUT_TR_EMPTY    BIT27       // 0/x/x/x Out Data Pipe (Bulk Out) Transfer Ring Empty Interrupt
    #define USBDMMIO_BLKOUT_BABBLE_ERR  BIT26       // 0/x/x/x Out Data Pipe (Bulk Out) Babble Error Is Detected
    #define USBDMMIO_BLKOUT_IOC         BIT25       // 0/x/x/x Out Data Pipe (Bulk Out) IOC Status
    #define USBDMMIO_BLKOUT_SHTPKT      BIT24       // 0/x/x/x Out Data Pipe (Bulk Out) Short Package Status
    #define USBDMMIO_BLKIN_TR_EMPTY     BIT19       // 0/x/x/x In Data Pipe (Bulk In) Transfer Ring Empty Interrupt
    #define USBDMMIO_BLKIN_IOC          BIT17       // 0/x/x/x In Data Piep (Bulk In) IOC Status
    #define USBDMMIO_CMDPIPE_TR_EMPTY   BIT11       // 0/x/x/x Command Pipe (Bulk Out) Transfer Ring Empty Interrupt
    #define USBDMMIO_CMDPIPE_BABBLE     BIT10       // 0/x/x/x Command Pipe (Bulk Out) Babble Error Is Detected
    #define USBDMMIO_CMDPIPE_IOC        BIT9        // 0/x/x/x Command Pipe (Bulk Out) Transfer IOC Status
    #define USBDMMIO_CMDPIPE_SHTPKT     BIT8        // 0/x/x/x Command Pipe (Bulk Out) Short Package Status
    #define USBDMMIO_STATPIPE_TR_EMPTY  BIT3        // 0/x/x/x Status Pipe (Bulk In) Transfer Ring Empty Interrupt
    #define USBDMMIO_STATPIPE_IOC       BIT1        // 0/x/x/x Status Pipe (Bulk In) Transfer IOC Status
#define USBDMMIO_ENDPOINT_INTR_CTL_REG 0x18 // Endpoint Interrupt Control Register
    #define USBDMMIO_INTEP_INT_EN           BIT18       // 0/x/x/x Interrupt Endpoint Interrupt Enable
    #define USBDMMIO_INTEP_NODATA_RDY_EN    BIT17       // 0/x/x/x Interrupt Endpoint Needs More Data Interrupt Enable
    #define USBDMMIO_INTEP_RPTTIME_REACH_EN BIT16       // 0/x/x/x The Times Of Interrupt Endpoint Transfer  Is Met Interrupt Enable
    #define USBDMMIO_CTRLEP_INT_EN          BIT15       // 0/x/x/x Control Endpoint Interrupt Enable
    #define USBDMMIO_SETUP_CMD_VLD_EN       BIT14       // 0/x/x/x Valid 8 Bytes Setup Command Is Received Interrupt Enable
    #define USBDMMIO_STATUS_TP_VLD_EN       BIT13       // 0/x/x/x Control Endpoint Received Valid STATUS TP Interrupt Enable. 
    #define USBDMMIO_CTRLOUT_TR_EMPTY_EN    BIT11       // 0/x/x/x Control Out Transfer Ring Empty Interrupt Enable
    #define USBDMMIO_CTRLEP_BABBLE_EN       BIT10       // 0/x/x/x Control Endpoint Babble Error Is Detected Interrupt Enable
    #define USBDMMIO_CTRLOUT_IOC_EN         BIT9        // 0/x/x/x Control Out Transfer IOC Interrupt Enable
    #define USBDMMIO_CTRLEP_SHTPKT_EN       BIT8        // 0/x/x/x Control Endpoint Short Package Interrupt Enable
    #define USBDMMIO_CTRLIN_TR_EMPTY_EN     BIT3        // 0/x/x/x Control In Transfer Ring Empty Interrupt Enable
    #define USBDMMIO_CTRLIN_IOC_EN          BIT1        // 0/x/x/x Control In Transfer IOC Interrupt Enable
#define USBDMMIO_ENDPOINT_INTR_CTL_REG_2 0x1C // Endpoint Interrupt Control Register 2
    #define USBDMMIO_BLKOUT_INT_EN          BIT31                   // 0/x/x/x Out Data Pipe (Bulk Out) Interrupt Enable
    #define USBDMMIO_BLKOUT_TR_OVR_EN       BIT27                   // 0/x/x/x Out Data Pipe (Bulk Out)  Transfer Ring Empty Interrupt Enable
    #define USBDMMIO_BLKOUT_BABBLE_EN       BIT26                   // 0/x/x/x Out Data Pipe (Bulk Out)  Babble Error Detecting Interrupt Enable
    #define USBDMMIO_BLKOUT_IOC_EN          BIT25                   // 0/x/x/x Out Data Pipe (Bulk Out)  IOC Enable
    #define USBDMMIO_BLKOUT_SHTPKT_EN       BIT24                   // 0/x/x/x Out Data Pipe (Bulk Out)  Short Package Interrupt Enable
    #define USBDMMIO_BLKIN_INT_EN           BIT23                   // 0/x/x/x In Data Pipe (Bulk In) Interrupt Enable
    #define USBDMMIO_BLKIN_TR_UDR_EN        BIT19                   // 0/x/x/x In Data Pipe (Bulk In)  Transfer Ring Empty Interrupt Enable
    #define USBDMMIO_BLKIN_IOC_EN           BIT17                   // 0/x/x/x In Data Pipe (Bulk In)  IOC Interrupt Enable
    #define USBDMMIO_CMDPIPE_INT_EN         BIT15                   // 0/x/x/x Command Pipe (Bulk Out) Interrupt Enable
    #define USBDMMIO_CMDPIPE_TR_EMPTY_EN    BIT11                   // 0/x/x/x Command Pipe (Bulk Out) Transfer Ring Empty Interrupt Enable
    #define USBDMMIO_CMDPIPE_BABBLE_EN      BIT10                   // 0/x/x/x Command Pipe (Bulk Out) Transfer Babble Error Is Detected Interrupt E...
    #define USBDMMIO_CMDPIPE_IOC_EN         BIT9                    // 0/x/x/x Command Pipe (Bulk Out) Transfer Ioc Interrupt enable
    #define USBDMMIO_CMDPIPE_SHTPKT_EN      BIT8                    // 0/x/x/x Command Pipe (Bulk Out) Transfer Short Package Interrupt Enable
    #define USBDMMIO_STATPIPE_INT_EN        BIT7                    // 0/x/x/x Status Pipe (Bulk In) Interrupt Enable
    #define USBDMMIO_STATPIPE_TR_EMPTY_EN   BIT3                    // 0/x/x/x Status Pipe (Bulk In) Transfer Ring Empty Interrupt Enable
    #define USBDMMIO_STATPIPE_IOC_EN        BIT1                    // 0/x/x/x Status Pipe (Bulk In) Transfer IOC Interrupt Enable
#define USBDMMIO_CTL_ENDPOINT_CTL_REG_CTRL_IN_DEQUEUE_PTR_AND_CYCLE_BIT 0x30 // Control Endpoint Control Register ? CTRL IN Dequeue Pointer and Cycle Bit
    #define USBDMMIO_CTRLIN_DEQ_H_PTR   0xFFFFFFFF00000000      // 0/x/x/x Control In Transfer TRB Ring Address Hi. 
    #define USBDMMIO_CTRLIN_DEQ_L_PTR   0xFFFFFFF0              // 0/x/x/x Control In Transfer TRB Ring Address Low. 
    #define USBDMMIO_CTRLIN_CYCLE       BIT0                    // 0/x/x/x Cycle Bit. 
#define USBDMMIO_CTL_ENDPOINT_CTL_REG_CTRL_OUT_DEQUEUE_PTR_AND_CYCLE_BIT 0x38 // Control Endpoint Control Register ? CTRL OUT Dequeue Pointer and Cycle Bit
    #define USBDMMIO_CTRLOUT_DEQ_H_PTR  0xFFFFFFFF00000000      // 0/x/x/x Control Out Transfer TRB Ring Address Hi. 
    #define USBDMMIO_CTRLOUT_DEQ_L_PTR  0xFFFFFFF0              // 0/x/x/x Control Out Transfer TRB Ring Address Low. 
    #define USBDMMIO_CTRLOUT_CYCLE      BIT0                    // 0/x/x/x Cycle Bit. 
#define USBDMMIO_CTL_ENDPOINT_CTL_REG_MISC 0x40 // Control Endpoint Control Register - MISC
    #define USBDMMIO_CTRLEP_MAXPKT_SIZE     0x7FF0000               // 200h/x/x/x Endpoint Maximum Package Size.
    #define USBDMMIO_CTRLEP_STATUS_READY    BIT8                    // 0/x/x/x Control Status Stage Ready.
    #define USBDMMIO_CTRLEP_STALL           BIT4                    // 0/x/x/x Endpoint Stall Control. 
    #define USBDMMIO_CTRLEP_LIGHTRST        BIT3                    // 0/x/x/x Control Endpoint Light Reset. 
    #define USBDMMIO_CTRLEP_DIR             BIT2                    // 0/x/x/x Control Endpoint Transfer Direction.
    #define USBDMMIO_CTRLOUTDMA_RUN_STOP    BIT1                    // 0/x/x/x Control Out DMA RUN/STOP Control. 
    #define USBDMMIO_CTRLINDMA_RUN_STOP     BIT0                    // 0/x/x/x Control In DMA RUN/STOP Control. 
#define USBDMMIO_CTL_ENDPOINT_8_BYTE_SETUP_CMD 0x48 // Control Endpoint 8 Byte Setup Command
    #define USBDMMIO_CTRLEP_SETUP_CMD USBDMMIO_CTL_ENDPOINT_8_BYTE_SETUP_CMD // 0/R/x/x Control Endpoint Received 8 Byte Setup Command
#define USBDMMIO_IN_DATA_PIPE_CTL_REG_BULK_IN_DEQUEUE_PTR_AND_CYCLE_BIT 0x50 // In Data Pipe Control Register (Bulk In) ? Dequeue Pointer and Cycle Bit
    #define USBDMMIO_BLKIN_DEQ_H_PTR    0xFFFFFFFF00000000      // 0/x/x/x Bulk In Endpoint Transfer Ring Dequeue Pointer Hi. 
    #define USBDMMIO_BLKIN_DEQ_L_PTR    0xFFFFFFF0              // 0/x/x/x Bulk In Endpoint Transfer Ring Dequeue Pointer Low. 
    #define USBDMMIO_BLKIN_CYCLE        BIT0                    // 0/x/x/x Cycle Bit. 
#define USBDMMIO_IN_DATA_PIPE_CTL_REG_BULK_IN_MISC 0x58 // In Data Pipe Control Register (Bulk In) - MISC
    #define USBDMMIO_BLKIN_STRM_EN      BIT28                   // 0/x/x/x Stream Enable.
    #define USBDMMIO_BLKIN_MAXPKT_SIZE  0x7FF0000               // 400h/x/x/x Maximum Packet Size
    #define USBDMMIO_BLKIN_MAXBST_SIZE  0xF000                  // 0/x/x/x Maximum Burst Size
    #define USBDMMIO_BLKIN_EPNUM        0xF00                   // 1h/x/x/x Endpoint Number.
    #define USBDMMIO_BLKIN_STALL        BIT4                    // 0/x/x/x Endpoint Stall Control. 
    #define USBDMMIO_BLKIN_LIGHTRST     BIT3                    // 0/x/x/x Bulk In Endpoint Light Reset. 
    #define USBDMMIO_BLKINDMA_RUN_STOP  BIT0                    // 0/x/x/x Bulk In DMA RUN/STOP Control. 
#define USBDMMIO_OUT_DATA_PIPE_CTL_REG_BULK_OUT_DEQUEUE_PTR_AND_CYCLE_BIT 0x60 // Out Data Pipe Control Register (Bulk Out) ? Dequeue Pointer and Cycle Bit
    #define USBDMMIO_BLKOUT_DEQ_H_PTR   0xFFFFFFFF00000000      // 0/x/x/x Bulk Out Endpoint Transfer Ring Dequeue Pointer Hi. 
    #define USBDMMIO_BLKOUT_DEQ_L_PTR   0xFFFFFFF0              // 0/x/x/x Bulk Out Endpoint Transfer Ring Dequeue Pointer Low. 
    #define USBDMMIO_BLKOUT_CYCLE       BIT0                    // 0/x/x/x Cycle Bit. 
#define USBDMMIO_OUT_DATA_PIPE_CTL_REG_BULK_OUT_MISC 0x68 // Out Data Pipe Control Register (Bulk Out) ? MISC
    #define USBDMMIO_BLKOUT_STRM_EN     BIT28                   // 0/x/x/x Stream Enable.
    #define USBDMMIO_BLKOUT_MAXPKT_SIZE 0x7FF0000               // 400h/x/x/x Maximum Packet Size
    #define USBDMMIO_BLKOUT_MAXBST_SIZE 0xF000                  // 0/x/x/x Maximum Burst Size
    #define USBDMMIO_BLKOUT_EPNUM       0xF00                   // 2h/x/x/x Endpoint Number
    #define USBDMMIO_BLKOUT_STALL       BIT4                    // 0/x/x/x Endpoint Stall Control. 
    #define USBDMMIO_BLKOUT_LIGHTRST    BIT3                    // 0/x/x/x Bulk Out Endpoint Light Reset. 
    #define USBDMMIO_BLKOUT_NUMPRSP     BIT1                    // 0/x/x/x Reserved
    #define USBDMMIO_BLKOUTDMA_RUN_STOP BIT0                    // 0/x/x/x Bulk Out DMA RUN/STOP Control. 
#define USBDMMIO_STA_PIPE_CTL_REG_BULK_IN_DEQUEUE_PTR_AND_CYCLE_BIT 0x70 // Status Pipe Control Register (Bulk In) ? Dequeue Pointer and Cycle Bit
    #define USBDMMIO_STATPIPE_DEQ_H_PTR 0xFFFFFFFF00000000      // 0/x/x/x Bulk In Endpoint Transfer Ring Start Address Hi. 
    #define USBDMMIO_STATPIPE_DEQ_L_PTR 0xFFFFFFF0              // 0/x/x/x Bulk In Endpoint Transfer Ring Start Address Low. 
    #define USBDMMIO_STATPIPE_CYCLE     BIT0                    // 0/x/x/x Cycle Bit. 
#define USBDMMIO_STA_PIPE_CTL_REG_BULK_IN_MISC 0x78 // Status Pipe Control Register (Bulk In) ? MISC
    #define USBDMMIO_STATPIPE_STRM_EN       BIT28                   // 1/x/x/x Stream Enable.
    #define USBDMMIO_STATPIPE_MAXPKT_SIZE   0x7FF0000               // 400h/x/x/x Maximum Packet Size
    #define USBDMMIO_STATPIPE_MAXBST_SIZE   0xF000                  // 0/x/x/x Max Burst Size
    #define USBDMMIO_STATPIPE_EPNUM         0xF00                   // 3h/x/x/x Endpoint Number
    #define USBDMMIO_STATPIPE_STALL         BIT4                    // 0/x/x/x Endpoint Stall Control. 
    #define USBDMMIO_STATPIPE_LIGHTRST      BIT3                    // 0/x/x/x Bulk In Endpoint Light Reset. 
    #define USBDMMIO_STATPIPEDMA_RUN_STOP   BIT0                    // 0/x/x/x Bulk In DMA RUN/STOP Control. 
#define USBDMMIO_CMD_PIPE_CTL_REG_BULK_OUT_DEQUEUE_PTR_AND_CYCLE_BIT 0x80 // Command Pipe Control Register (Bulk Out) ? Dequeue Pointer and Cycle Bit
    #define USBDMMIO_CMDPIPE_DEQ_H_PTR  0xFFFFFFFF00000000      // 0/x/x/x Bulk Out Endpoint Transfer Ring Dequeue Pointer Hi. 
    #define USBDMMIO_CMDPIPE_DEQ_L_PTR  0xFFFFFFF0              // 0/x/x/x Bulk Out Endpoint Transfer Ring Dequeue Pointer Low. 
    #define USBDMMIO_CMDPIPE_CYCLE      BIT0                    // 0/x/x/x Cycle Bit. 
#define USBDMMIO_CMD_PIPE_CTL_REG_BULK_OUT_MISC 0x88 // Command Pipe Control Register (Bulk Out) ? MISC
    #define USBDMMIO_CMDPIPE_STRM_EN        BIT28                   // 0/x/x/x Stream Enable.
    #define USBDMMIO_CMDPIPE_MAXPKT_SIZE    0x7FF0000               // 400h/x/x/x Maximum Packet Size
    #define USBDMMIO_CMDPIPE_MAXBST_SIZE    0xF000                  // 0/x/x/x Max Burst Size
    #define USBDMMIO_CMDPIPE_EPNUM          0xF00                   // 4h/x/x/x Endpoint Number
    #define USBDMMIO_CMDPIPE_STALL          BIT4                    // 0/x/x/x Endpoint Stall Control. 
    #define USBDMMIO_CMDPIPE_LIGHTRST       BIT3                    // 0/x/x/x Bulk Out Endpoint Light Reset. 
    #define USBDMMIO_CMDPIPE_NUMPRSP        BIT1                    // 0/x/x/x Reserved
    #define USBDMMIO_CMDPIPEDMA_RUN_STOP    BIT0                    // 0/x/x/x Bulk Out DMA RUN/STOP Control. 
#define USBDMMIO_INTR_ENDPOINT_CTL_REG_1 0x90 // Interrupt Endpoint Control Register 1
    #define USBDMMIO_INT_MAXPKT_SIZE    0x3F0000                // 20h/x/x/x Maximum Packet Size
    #define USBDMMIO_INT_EPNUM          0xF00                   // 5h/x/x/x Endpoint Number
    #define USBDMMIO_INT_STALL          BIT4                    // 0/x/x/x Endpoint Stall Control. 
    #define USBDMMIO_INT_LIGHTRST       BIT3                    // 0/x/x/x Interrupt Endpoint Light Reset. 
    #define USBDMMIO_INTBUF_RUN_STOP    BIT0                    // 0/x/x/x Interrupt Endpoint Data Buffer RUN/STOP Control. 
#define USBDMMIO_INTR_ENDPOINT_CTL_REG_2 0x94 // Interrupt Endpoint Control Register 2
    #define USBDMMIO_INT_RPT_NUM    0xFFFF      // 0/x/x/x Repeated Times Of Interrupt Endpoint Buffer Data Transferred. 
#define USBDMMIO_INTR_ENDPOINT_DATA_BUFFER 0xA0 // Interrupt Endpoint Data Buffer
    #define USBDMMIO_INTBUF_DATA USBDMMIO_INTR_ENDPOINT_DATA_BUFFER // 0/x/x/x Interrupt Endpoint Data
#define USBDMMIO_EVENT_RING_INTR_MANAGEMENT_REGISER 0xC0 // Event Ring Interrupt Management Regiser
    #define USBDMMIO_INT_ENABLE     BIT1        // 0/x/x/x Interrupt Enable (IE). ((Random))
    #define USBDMMIO_INT_PENDING    BIT0        // 0/x/x/x Interrupt Pending (IP) . 
#define USBDMMIO_EVENT_RING_INTRER_MODERATION_REG 0xC4 // Event Ring Interrupter Moderation Register
    #define USBDMMIO_IMODC_WD   0xFFFF0000  // 0h/x/x/x Interrupt Moderation Counter (IMODC) . 
    #define USBDMMIO_IMODI      0xFFFF      // 0FA0h/x/x/x Interrupt Moderation Interval (IMODI). 
#define USBDMMIO_EVENT_RING_SEGMENT_TABLE_SIZE_REG 0xC8 // Event Ring Segment Table Size Register
    #define USBDMMIO_ERSTSZ 0xFFFF      // 0/x/x/x Event Ring Segment Table Size ? RW. 
#define USBDMMIO_EVENT_RING_SEGMENT_TABLE_BASE_ADR_REG 0xD0 // Event Ring Segment Table Base Address Register
    #define USBDMMIO_ERSTBA     0xFFFFFFFFFFFFFFF0  // 0/x/x/x Event Ring Segment Table Base Address Register ? RW. This field defin...
    #define USBDMMIO_MAXERST    0xF                 // 2/x/x/x Event Ring Segment Table Max (ERST Max). Valid values are 0 ? 15. Thi...
#define USBDMMIO_EVENT_RING_DEQUEUE_PTR_REG 0xD8 // Event Ring Dequeue Pointer Register
    #define USBDMMIO_ERDP   0xFFFFFFFFFFFFFFF0      // 0/x/x/x Dequeue Pointer ? RW. This field defines the start address of the Eve...
    #define USBDMMIO_EHB    BIT3                    // 0/x/x/x Event Handler Busy (EHB) - RW1C. 
    #define USBDMMIO_DESI   (BIT0 + BIT1 + BIT2)    // 0/x/x/x Dequeue ERST Segment Index (DESI). 
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CND001(1.00)
// Pls contact PLW to report Irs2h bugs.
