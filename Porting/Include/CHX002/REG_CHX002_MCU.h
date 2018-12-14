//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

///
#ifndef REG_CHX001_MCU_H
#define REG_CHX001_MCU_H
// Normal DMA Management
#define NORMALDMAMANAGEMENT_SYS_MEM_ADR_REG 0x0 // System Memory Address Register
    #define NORMALDMAMANAGEMENT_SYSADDR NORMALDMAMANAGEMENT_SYS_MEM_ADR_REG // 0/x/x/x System Memory Address
#define NORMALDMAMANAGEMENT_PARAM_REG 0x10 // Parameter Register
    #define NORMALDMAMANAGEMENT_DIRECT  BIT16           // 0/x/x/x Direction
    #define NORMALDMAMANAGEMENT_LBE     0xF000          // 0/x/x/x Last BE
    #define NORMALDMAMANAGEMENT_FBE     0xF00           // 0/X/x/x First BE
    #define NORMALDMAMANAGEMENT_TC      0x3C            // 0/x/x/x Terminate Count (Unit is DWORD0)
#define NORMALDMAMANAGEMENT_OPERATION_REG 0x14 // Operation Register
    #define NORMALDMAMANAGEMENT_TRANSSTART  BIT0        // 0/x/x/x Transfer Start
#define NORMALDMAMANAGEMENT_INTR_STA_REG 0x18 // Interrupt Status Register
    #define NORMALDMAMANAGEMENT_TRANSCOMPLETE   BIT0        // 0/x/x/x Transfer Finish
#define NORMALDMAMANAGEMENT_INTR_ENABLE_REG 0x1C // Interrupt Enable Register
    #define NORMALDMAMANAGEMENT_TRANSCOMPLETEEN BIT0        // 0/x/x/x Enable Interrupt Transfer Finish to generate interrupt
#define NORMALDMAMANAGEMENT_CD_CACHE_REG 0x20 // CD Cache Register
    #define NORMALDMAMANAGEMENT_CACHE NORMALDMAMANAGEMENT_CD_CACHE_REG // 0/x/x/x Cache
// Command Ring Management
#define COMMANDRINGMANAGEMENT_IMAGE_REG 0x1000 // Image Register
    #define COMMANDRINGMANAGEMENT_CDRINGPOINTER 0xFFFFFFFFFFFFFFC0  // 0/R/x/x CRC Command Ring Pointer
    #define COMMANDRINGMANAGEMENT_RUNSTOP       BIT4                // 0/R/x/x XHCI.RUN/STOP
    #define COMMANDRINGMANAGEMENT_CRR_IMAG      BIT3                // 0/R/x/x CRCR.CRR
    #define COMMANDRINGMANAGEMENT_RCS           BIT0                // 0/R/x/x CRCR.RCS
#define COMMANDRINGMANAGEMENT_PARAM_REG 0x1008 // Parameter Register
    #define COMMANDRINGMANAGEMENT_CURCDRINGPOINTER  0xFFFFFFFFFFFFFFF0  // 0/x/x/x Current Command Ring Pointer
    #define COMMANDRINGMANAGEMENT_CRR_PAR           BIT3                // 0/x/x/x Current CRR
    #define COMMANDRINGMANAGEMENT_CURRCS            BIT0                // 0/x/x/x Current RCS
#define COMMANDRINGMANAGEMENT_OPERATIONAL_REG 0x1010 // Operational Register
    #define COMMANDRINGMANAGEMENT_ADDRINC   BIT1        // 0/x/x/x Increase Command Ring Pointer by 1
    #define COMMANDRINGMANAGEMENT_FETCHCD   BIT0        // 0/x/x/x Fetch Next Command Descriptor
#define COMMANDRINGMANAGEMENT_INTR_STA_REG 0x1018 // Interrupt Status Register
    #define COMMANDRINGMANAGEMENT_DQPCHG        BIT7        // 0/x/x/x CDR Dequeue Pointer be written when CRR is 0
    #define COMMANDRINGMANAGEMENT_ABORT         BIT6        // 0/x/x/x Abort
    #define COMMANDRINGMANAGEMENT_STOP          BIT5        // 0/x/x/x Stop
    #define COMMANDRINGMANAGEMENT_MISCS         BIT4        // 0/x/x/x Descriptor cycle bit Mismatch
    #define COMMANDRINGMANAGEMENT_CDREADY       BIT3        // 0/x/x/x Descriptor Ready
    #define COMMANDRINGMANAGEMENT_DOORBELL      BIT2        // 0/x/x/x Doorbell Ring
    #define COMMANDRINGMANAGEMENT_CRRCHG        BIT1        // 0/x/x/x Current CRR change ( CRR auto change should be enable)
    #define COMMANDRINGMANAGEMENT_RUNSTOPCHG    BIT0        // 0/x/x/x Run/Stop change
#define COMMANDRINGMANAGEMENT_INTR_ENABLE_REG 0x101C // Interrupt Enable Register
    #define COMMANDRINGMANAGEMENT_DQPCHGEN      BIT7        // 0/x/x/x Enable Interrupt on CDR Dequeue Pointer be written when CRR is 0
    #define COMMANDRINGMANAGEMENT_ABORTEN       BIT6        // 0/x/x/x Enable Interrupt on Abort
    #define COMMANDRINGMANAGEMENT_STOPEN        BIT5        // 0/x/x/x Enable Interrupt on Stop
    #define COMMANDRINGMANAGEMENT_MISCSEN       BIT4        // 0/x/x/x Enable Interrupt Descriptor cycle bit Mismatch (It means when descrip...
    #define COMMANDRINGMANAGEMENT_CDREADYEN     BIT3        // 0/x/x/x Enable Interrupt Descriptor Ready
    #define COMMANDRINGMANAGEMENT_DOORBELLEN    BIT2        // 0/x/x/x Enable Interrupt Doorbell Ring
    #define COMMANDRINGMANAGEMENT_CRRCHGEN      BIT1        // 0/x/x/x Enable Interrupt Current CRR change ( CRR auto change should be enabl...
    #define COMMANDRINGMANAGEMENT_RUNSTOPCHGEN  BIT0        // 0/x/x/x Enable Interrupt Run/Stop change ( This Run/Stop bit is the Run/Stop ...
#define COMMANDRINGMANAGEMENT_CD_CACHE_REG 0x1020 // CD Cache Register
    #define COMMANDRINGMANAGEMENT_REG_CACHE COMMANDRINGMANAGEMENT_CD_CACHE_REG // 0/R/x/x Current CD Cache
// Event Ring Management
#define EVENTRINGMANAGEMENT_EVENT_RING_VECTOR_REG 0x2000 // Event Ring Vector Register
    #define EVENTRINGMANAGEMENT_MCU_EVENTVEC EVENTRINGMANAGEMENT_EVENT_RING_VECTOR_REG // 0/x/x/x MCU Event Vector
#define EVENTRINGMANAGEMENT_MCU_EVENT_CTL_REG 0x2010 // MCU Event Control Register
    #define EVENTRINGMANAGEMENT_EVENTR0FULL     BIT1        // 0/R/x/x 0th Event Ring Full
    #define EVENTRINGMANAGEMENT_MCU_EVENTREQ    BIT0        // 0/x/x/x MCU Event Valid
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_0_ENQUEUE_PTR_REG 0x2014 // MCU Event Ring 0 Enqueue Pointer Register
    #define EVENTRINGMANAGEMENT_EREP0_63_4  0xFFFFFFFFFFFFFFF   // 0/x/x/x Event Ring Enqueue Pointer
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_0_MANAGEMENT_REG 0x201C // MCU Event Ring 0 Management Register
    #define EVENTRINGMANAGEMENT_ERSM0       0xFE000000  // 1h/R/x/x State Machine of Event Ring
    #define EVENTRINGMANAGEMENT_EPCS0       BIT24       // 1b/x/x/x Event Ring Producer Cycle State
    #define EVENTRINGMANAGEMENT_ERSTCNT0    0xF0000     // 0/x/x/x Event Ring Segment Table Count
    #define EVENTRINGMANAGEMENT_ETRBCNT0    0xFFFF      // 0/x/x/x Event Ring TRB Count
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_0_ENQUEUE_PTR_RES_REG 0x2020 // MCU Event Ring 0 Enqueue Pointer RES Register
    #define EVENTRINGMANAGEMENT_EREP0_RES   0xFFFFFFFFFFFFFFF   // 0/x/x/x Event Ring Enqueue Pointer Restore
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_0_MANAGEMENT_REG_Z1 0x2028 // MCU Event Ring 0 Management Register
    #define EVENTRINGMANAGEMENT_EPCS0_RES       BIT24       // 0/x/x/x Event Ring Producer Cycle State Restore
    #define EVENTRINGMANAGEMENT_ERSTCNT0_RES    0xF0000     // 0/x/x/x Event Ring Segment Table Count Restore
    #define EVENTRINGMANAGEMENT_ETRBCNT0_RES    0xFFFF      // 0/x/x/x Event Ring TRB Count Restore
#define EVENTRINGMANAGEMENT_MCU_EVENT_CTL_REG_Z1 0x202C // MCU Event Control Register
    #define EVENTRINGMANAGEMENT_EVENTR1FULL BIT0        // 0/R/x/x 0th Event Ring Full
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_1_ENQUEUE_PTR_REG 0x2030 // MCU Event Ring 1 Enqueue Pointer Register
    #define EVENTRINGMANAGEMENT_EREP1_63_4  0xFFFFFFFFFFFFFFF   // 0/x/x/x Event Ring Enqueue Pointer
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_1_MANAGEMENT_REG 0x2038 // MCU Event Ring 1 Management Register
    #define EVENTRINGMANAGEMENT_ERSM1       0xFE000000  // 1h/R/x/x State Machine of Event Ring
    #define EVENTRINGMANAGEMENT_EPCS1       BIT24       // 1b/x/x/x Event Ring Producer Cycle State
    #define EVENTRINGMANAGEMENT_ERSTCNT1    0xF0000     // 0/x/x/x Event Ring Segment Table Count
    #define EVENTRINGMANAGEMENT_ETRBCNT1    0xFFFF      // 0/x/x/x Event Ring TRB Count
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_1_ENQUEUE_PTR_RES_REG 0x203C // MCU Event Ring 1 Enqueue Pointer RES Register
    #define EVENTRINGMANAGEMENT_EREP1_RES   0xFFFFFFFFFFFFFFF   // 0/x/x/x Event Ring Enqueue Pointer Restore
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_0_MANAGEMENT_REG_Z2 0x2044 // MCU Event Ring 0 Management Register
    #define EVENTRINGMANAGEMENT_EPCS1_RES       BIT24       // 0/x/x/x Event Ring Producer Cycle State Restore
    #define EVENTRINGMANAGEMENT_ERSTCNT1_RES    0xF0000     // 0/x/x/x Event Ring Segment Table Count Restore
    #define EVENTRINGMANAGEMENT_ETRBCNT1_RES    0xFFFF      // 0/x/x/x Event Ring TRB Count Restore
#define EVENTRINGMANAGEMENT_MCU_EVENT_CTL_REG_Z2 0x2048 // MCU Event Control Register
    #define EVENTRINGMANAGEMENT_EVENTR2FULL BIT0        // 0/R/x/x 2th Event Ring Full
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_2_ENQUEUE_PTR_REG 0x204C // MCU Event Ring 2 Enqueue Pointer Register
    #define EVENTRINGMANAGEMENT_EREP2_63_4  0xFFFFFFFFFFFFFFF   // 0/x/x/x Event Ring Enqueue Pointer
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_2_MANAGEMENT_REG 0x2054 // MCU Event Ring 2 Management Register
    #define EVENTRINGMANAGEMENT_ERSM2       0xFE000000  // 1h/R/x/x State Machine of Event Ring
    #define EVENTRINGMANAGEMENT_EPCS2       BIT24       // 1b/x/x/x Event Ring Producer Cycle State
    #define EVENTRINGMANAGEMENT_ERSTCNT2    0xF0000     // 0/x/x/x Event Ring Segment Table Count
    #define EVENTRINGMANAGEMENT_ETRBCNT2    0xFFFF      // 0/x/x/x Event Ring TRB Count
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_2_ENQUEUE_PTR_RES_REG 0x2058 // MCU Event Ring 2 Enqueue Pointer RES Register
    #define EVENTRINGMANAGEMENT_EREP2_RES   0xFFFFFFFFFFFFFFF   // 0/x/x/x Event Ring Enqueue Pointer Restore
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_2_MANAGEMENT_REG_Z1 0x2060 // MCU Event Ring 2 Management Register
    #define EVENTRINGMANAGEMENT_EPCS2_RES       BIT24       // 0/x/x/x Event Ring Producer Cycle State Restore
    #define EVENTRINGMANAGEMENT_ERSTCNT2_RES    0xF0000     // 0/x/x/x Event Ring Segment Table Count Restore
    #define EVENTRINGMANAGEMENT_ETRBCNT2_RES    0xFFFF      // 0/x/x/x Event Ring TRB Count Restore
#define EVENTRINGMANAGEMENT_MCU_EVENT_CTL_REG_Z3 0x2064 // MCU Event Control Register
    #define EVENTRINGMANAGEMENT_EVENTR3FULL BIT0        // 0/R/x/x 3th Event Ring Full
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_3_ENQUEUE_PTR_REG 0x2068 // MCU Event Ring 3 Enqueue Pointer Register
    #define EVENTRINGMANAGEMENT_EREP3_63_4  0xFFFFFFFFFFFFFFF   // 0/x/x/x Event Ring Enqueue Pointer
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_3_MANAGEMENT_REG 0x2070 // MCU Event Ring 3 Management Register
    #define EVENTRINGMANAGEMENT_ERSM3       0xFE000000  // 1h/R/x/x State Machine of Event Ring
    #define EVENTRINGMANAGEMENT_EPCS3       BIT24       // 1b/x/x/x Event Ring Producer Cycle State
    #define EVENTRINGMANAGEMENT_ERSTCNT3    0xF0000     // 0/x/x/x Event Ring Segment Table Count
    #define EVENTRINGMANAGEMENT_ETRBCNT3    0xFFFF      // 0/x/x/x Event Ring TRB Count
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_3_ENQUEUE_PTR_RES_REG 0x2074 // MCU Event Ring 3 Enqueue Pointer RES Register
    #define EVENTRINGMANAGEMENT_EREP3_RES   0xFFFFFFFFFFFFFFF   // 0/x/x/x Event Ring Enqueue Pointer Restore
#define EVENTRINGMANAGEMENT_MCU_EVENT_RING_3_MANAGEMENT_REG_Z1 0x207C // MCU Event Ring 3 Management Register
    #define EVENTRINGMANAGEMENT_EPCS3_RES       BIT24       // 0/x/x/x Event Ring Producer Cycle State Restore
    #define EVENTRINGMANAGEMENT_ERSTCNT3_RES    0xF0000     // 0/x/x/x Event Ring Segment Table Count Restore
    #define EVENTRINGMANAGEMENT_ETRBCNT3_RES    0xFFFF      // 0/x/x/x Event Ring TRB Count Restore
#define EVENTRINGMANAGEMENT_MCU_INTR_TARGET_REG 0x2080 // MCU Interrupt Target Register
    #define EVENTRINGMANAGEMENT_MCUINTRTGT3 BIT3        // 0/x/x/x MCU Interrupt Target 3 
    #define EVENTRINGMANAGEMENT_MCUINTRTGT2 BIT2        // 0/x/x/x MCU Interrupt Target 2 
    #define EVENTRINGMANAGEMENT_MCUINTRTGT1 BIT1        // 0/x/x/x MCU Interrupt Target 1 
    #define EVENTRINGMANAGEMENT_MCUINTRTGT0 BIT0        // 0/x/x/x MCU Interrupt Target 0 
// PCIS Management
#define PCISMANAGEMENT_SW_DEBUG_MSG_TO_MCU_FW_REG 0x36E0 // SW Debug Message to MCU FW Register
    #define PCISMANAGEMENT_SWFWMSG0 PCISMANAGEMENT_SW_DEBUG_MSG_TO_MCU_FW_REG // 0/x/x/x SW Debug Message to MCU FW DW0
#define PCISMANAGEMENT_SW_DEBUG_MSG_TO_MCU_FW_REG_Z1 0x36E4 // SW Debug Message to MCU FW Register
    #define PCISMANAGEMENT_SWFWMSG1 PCISMANAGEMENT_SW_DEBUG_MSG_TO_MCU_FW_REG_Z1 // 0/x/x/x SW Debug Message to MCU FW DW1
#define PCISMANAGEMENT_SW_DEBUG_MSG_TO_MCU_FW_REG_Z2 0x36E8 // SW Debug Message to MCU FW Register
    #define PCISMANAGEMENT_SWFWMSG2 PCISMANAGEMENT_SW_DEBUG_MSG_TO_MCU_FW_REG_Z2 // 0/x/x/x SW Debug Message to MCU FW DW2
#define PCISMANAGEMENT_SW_DEBUG_MSG_TO_MCU_FW_REG_Z3 0x36EC // SW Debug Message to MCU FW Register
    #define PCISMANAGEMENT_SWFWMSG3 PCISMANAGEMENT_SW_DEBUG_MSG_TO_MCU_FW_REG_Z3 // 0/x/x/x SW Debug Message to MCU FW DW3
#define PCISMANAGEMENT_PCIS_MCU_INT_CTL_REG 0x3800 // PCIS MCU INT Control Register
    #define PCISMANAGEMENT_MCUDBCRST    BIT17       // 0/R/x/x MCU DBC Reset
    #define PCISMANAGEMENT_MCURST       BIT16       // 0/x/x/x MCU Reset 
    #define PCISMANAGEMENT_SWINTEN      BIT9        // 0/x/x/x SW Write XHCI Option Space RxE0~EF Interrupt Enable
    #define PCISMANAGEMENT_D3INTEN      BIT8        // 0/x/x/x D3 interrupt Enable 
    #define PCISMANAGEMENT_SRINTEN      BIT7        // 0/x/x/x Save/Restore Interrupt Enable(S/RINTEN)
    #define PCISMANAGEMENT_HCRSTINTEN   BIT6        // 0/x/x/x HCRST Interrupt Enable
    #define PCISMANAGEMENT_RUNCHGINTEN  BIT5        // 0/x/x/x RUNSTOP Change Interrupt Enable(RUNCHGINTEN)
    #define PCISMANAGEMENT_DBINTEN      BIT4        // 1b/x/x/x Doorbell Interrupt Enable
    #define PCISMANAGEMENT_DBQUEUERPTR  0xF         // 0/x/x/x Doorbell Queue Read Pointer
#define PCISMANAGEMENT_PCIS_MCU_INT_STA_REG 0x3804 // PCIS MCU INT Status Register
    #define PCISMANAGEMENT_DSMCUHDL     BIT16                   // 0/x/x/x Downstream MCU Handle Status
    #define PCISMANAGEMENT_SWINTSTS     BIT12                   // 0/x/x/x SW Write XHCI Option Space RxE0~EF Interrupt Status
    #define PCISMANAGEMENT_D3STS        BIT11                   // 0/x/x/x D3 Status  
    #define PCISMANAGEMENT_CRSCHG       BIT10                   // 0/x/x/x Restore State Change
    #define PCISMANAGEMENT_CSSCHG       BIT9                    // 0/x/x/x Save State Change
    #define PCISMANAGEMENT_LHCRSTCHG    BIT8                    // 0/x/x/x LHCRST Change Status
    #define PCISMANAGEMENT_HCRSTSTS     BIT7                    // 0/x/x/x HCRST Status
    #define PCISMANAGEMENT_RUNNEGCHG    BIT6                    // 0/x/x/x RUNSTOP Negedge Change
    #define PCISMANAGEMENT_RUNPOSCHG    BIT5                    // 0/x/x/x RUNSTOP Posedge Change 
    #define PCISMANAGEMENT_DBQFULL      BIT4                    // 0/R/x/x Doorbell Queue Full
    #define PCISMANAGEMENT_DBQUEUEWPTR  0xF                     // 0/R/x/x Doorbell Queue Write Pointer
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_0_REG 0x3810 // PCIS Doorbell Queue 0 Register
    #define PCISMANAGEMENT_DBSTMID0     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID0    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET0    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_1_REG 0x3814 // PCIS Doorbell Queue 1 Register
    #define PCISMANAGEMENT_DBSTMID1     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID1    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET1    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_2_REG 0x3818 // PCIS Doorbell Queue 2 Register
    #define PCISMANAGEMENT_DBSTMID2     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID2    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET2    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_3_REG 0x381C // PCIS Doorbell Queue 3 Register
    #define PCISMANAGEMENT_DBSTMID3     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID3    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET3    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_4_REG 0x3820 // PCIS Doorbell Queue 4 Register
    #define PCISMANAGEMENT_DBSTMID4     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID4    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET4    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_5_REG 0x3824 // PCIS Doorbell Queue 5 Register
    #define PCISMANAGEMENT_DBSTMID5     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID5    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET5    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_6_REG 0x3828 // PCIS Doorbell Queue 6 Register
    #define PCISMANAGEMENT_DBSTMID6     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID6    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET6    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_7_REG 0x382C // PCIS Doorbell Queue 7 Register
    #define PCISMANAGEMENT_DBSTMID7     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID7    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET7    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_8_REG 0x3830 // PCIS Doorbell Queue 8 Register
    #define PCISMANAGEMENT_DBSTMID8     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID8    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET8    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_9_REG 0x3834 // PCIS Doorbell Queue 9 Register
    #define PCISMANAGEMENT_DBSTMID9     0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID9    0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET9    0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_10_REG 0x3838 // PCIS Doorbell Queue 10 Register
    #define PCISMANAGEMENT_DBSTMID10    0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID10   0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET10   0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_11_REG 0x383C // PCIS Doorbell Queue 11 Register
    #define PCISMANAGEMENT_DBSTMID11    0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID11   0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET11   0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_12_REG 0x3840 // PCIS Doorbell Queue 12 Register
    #define PCISMANAGEMENT_DBSTMID12    0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID12   0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET12   0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_13_REG 0x3844 // PCIS Doorbell Queue 13 Register
    #define PCISMANAGEMENT_DBSTMID13    0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID13   0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET13   0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_14_REG 0x3848 // PCIS Doorbell Queue 14 Register
    #define PCISMANAGEMENT_DBSTMID14    0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID14   0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET14   0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_PCIS_DOORBELL_QUEUE_15_REG 0x384C // PCIS Doorbell Queue 15 Register
    #define PCISMANAGEMENT_DBSTMID15    0xFFFF0000  // 0/R/x/x DB Stream ID
    #define PCISMANAGEMENT_DBSLOTID15   0xFF00      // 0/R/x/x DB Slot ID 
    #define PCISMANAGEMENT_DBTARGET15   0xFF        // 0/R/x/x DB Target
#define PCISMANAGEMENT_MCU_STA_REG 0x3860 // MCU Status Register
    #define PCISMANAGEMENT_MCUHWRSTRDY  BIT7    // 0/x/x/x MCU HW is Reset Ready.
    #define PCISMANAGEMENT_PDU3PHY      BIT6    // 0/x/x/x Power Down USB3.0 PHY 
    #define PCISMANAGEMENT_PDU2PHY      BIT5    // 0/x/x/x Power Down USB2.0 PHY
    #define PCISMANAGEMENT_SRE          BIT4    // 0/x/x/x MCU set this register for USBSTS.SRE value
    #define PCISMANAGEMENT_RSS          BIT3    // 0/x/x/x MCU set this register for USBSTS.RSS value
    #define PCISMANAGEMENT_SSS          BIT2    // 0/x/x/x MCU set this register for USBSTS.SSS value
    #define PCISMANAGEMENT_HCE          BIT1    // 0/x/x/X MCU set this register for USBSTS.HCE value
    #define PCISMANAGEMENT_NOTRDY       BIT0    // 1b/x/x/x MCU Not Ready 
#define PCISMANAGEMENT_DEBUG_REG 0x3864 // Debug Register
    #define PCISMANAGEMENT_XHCI_DBG3    0xFF000000  // 0/x/x/x Reserved Debug Registers
    #define PCISMANAGEMENT_XHCI_DBG2    0xFF0000    // 0/x/x/x Reserved Debug Registers
    #define PCISMANAGEMENT_XHCI_DBG1    0xFF00      // 0/x/x/x Reserved Debug Registers
    #define PCISMANAGEMENT_XHCI_DBG0    0xFF        // 0/x/x/x Reserved Debug Registers
#define PCISMANAGEMENT_DOWNSTREAM_CYCLE_MCU_HANDLE_STA_REG 0x3868 // Downstream Cycle MCU Handle Status Register
    #define PCISMANAGEMENT_DSRDVLD  BIT25       // 0/x/x/x Downstream Read Valid 
    #define PCISMANAGEMENT_DSACK    BIT24       // 0/x/x/x Downstream MCU Handle Complete
    #define PCISMANAGEMENT_DSWR     BIT17       // 0/R/x/x Downstream Write/Read 
    #define PCISMANAGEMENT_DSCFG    BIT16       // 0/R/x/x Downstream Configure Cycle
    #define PCISMANAGEMENT_DSCBE    0xF000      // 0/R/x/x Downstream CBE
    #define PCISMANAGEMENT_DSADDR   0xFFF       // 0/R/x/x Downstream Address (DS Address)
#define PCISMANAGEMENT_DOWNSTREAM_CYCLE_MCU_HANDLE_STA_REG_Z1 0x386C // Downstream Cycle MCU Handle Status Register
    #define PCISMANAGEMENT_DSMCURDDATA PCISMANAGEMENT_DOWNSTREAM_CYCLE_MCU_HANDLE_STA_REG_Z1 // 0/x/x/x Downstream Read Data (DSMCURDDATA).
#define PCISMANAGEMENT_PCIS_DEBUG_SIGNAL_REG 0x3900 // PCIS Debug Signal Register
    #define PCISMANAGEMENT_XHCI_DBG_GRP_SYN PCISMANAGEMENT_PCIS_DEBUG_SIGNAL_REG // 0/R/x/x XHCI Debug Group Signal.
// INTC Management
#define INTCMANAGEMENT_INTC_INTR_MASK_REG 0x4002 // INTC Interrupt Mask Register
    #define INTCMANAGEMENT_INTMSK_14    BIT14                   // 0/x/x/x PIPETLB Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_13    BIT13                   // 0/x/x/x USB2BI Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_12    BIT12                   // 0/x/x/x Debug Capability Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_9     BIT9                    // 0/x/x/x SSBI Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_8     BIT8                    // 0/x/x/x PCIS Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_4     BIT4                    // 0/x/x/x Device Notification Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_3     BIT3                    // 0/x/x/x DMA Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_2     BIT2                    // 0/x/x/x Event Ring Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_1     BIT1                    // 0/x/x/x Command Ring Interrupt Mask
    #define INTCMANAGEMENT_INTMSK_0     BIT0                    // 0/x/x/x Reserved
#define INTCMANAGEMENT_INTC_INTR_STA_REG 0x4004 // INTC Interrupt Status Register
    #define INTCMANAGEMENT_TLBINTS      BIT14                   // 0/x/x/x PIPETLB Interrupt Status
    #define INTCMANAGEMENT_USB2BIINTS   BIT13                   // 0/x/x/x USB2BI Interrupt Status
    #define INTCMANAGEMENT_DBGCINTS     BIT12                   // 0/x/x/x Debug Capability Interrupt Status
    #define INTCMANAGEMENT_SSBI1INTS    BIT9                    // 0/x/x/x SSBI Interrupt Status
    #define INTCMANAGEMENT_CFGINTS      BIT8                    // 0/x/x/x PCIS Interrupt Status
    #define INTCMANAGEMENT_DEVNINT1S    BIT4                    // 0/x/x/x Device Notification Interrupt Status
    #define INTCMANAGEMENT_DMAINTS      BIT3                    // 0/x/x/x DMAMUX Interrupt Status
    #define INTCMANAGEMENT_EVTINTS      BIT2                    // 0/x/x/x Event Ring Interrupt Status
    #define INTCMANAGEMENT_CRINTS       BIT1                    // 0/x/x/x CR Interrupt Status
// PIPETLB Management
#define PIPETLBMANAGEMENT_ASYNC_LIST_UPDATE_REG 0x5000 // Async List Update Register
    #define PIPETLBMANAGEMENT_ASYNCUPD_NXTPTR   0x1FFF0000              // 0/x/x/x Next Link Pointer
    #define PIPETLBMANAGEMENT_ASYNCUPD_REQ      BIT13                   // 0/x/x/x Async List Update Request
    #define PIPETLBMANAGEMENT_ASYNCUPD_SLOTID   0x1FE0                  // 0/x/x/x Slot ID
    #define PIPETLBMANAGEMENT_ASYNCUPD_DCI      0x1F                    // 0/x/x/x Device Context Index (DCI)
#define PIPETLBMANAGEMENT_DBPV_UPDATE_REQ_REG 0x5004 // DBPV Update Request Register
    #define PIPETLBMANAGEMENT_PIPEDBPV_STREAMID 0xFFFF0000  // 0/x/x/x DB Stream ID
    #define PIPETLBMANAGEMENT_PIPEDBPV_REQ      BIT14       // 0/x/x/x Doorbell Pending Value Request
    #define PIPETLBMANAGEMENT_PIPEDBPV_STREAMEP BIT13       // 0/x/x/x Stream Endpoint 
    #define PIPETLBMANAGEMENT_PIPEDBPV_SLOTID   0x1FE0      // 0/x/x/x Slot ID
    #define PIPETLBMANAGEMENT_PIPEDBPV_DCI      0x1F        // 0/x/x/x Device Context Index (DCI)
#define PIPETLBMANAGEMENT_PIPE_REMOVE_REQ_REG 0x5008 // Pipe Remove Request Register
    #define PIPETLBMANAGEMENT_PIPERM_NOTINTLB   BIT14       // 0/x/x/x PIPE Not in TLB
    #define PIPETLBMANAGEMENT_PIPERM_REQ        BIT13       // 0/x/x/x Pipe Remove Request 
    #define PIPETLBMANAGEMENT_PIPERM_SLOTID     0x1FE0      // 0/x/x/x Slot ID
    #define PIPETLBMANAGEMENT_PIPERM_DCI        0x1F        // 0/x/x/x Device Context Index (DCI)
#define PIPETLBMANAGEMENT_PIPE_READ_REQ_REG 0x500C // Pipe Read Request Register
    #define PIPETLBMANAGEMENT_PIPERD_CACHE      BIT15       // 0/x/x/x Caching
    #define PIPETLBMANAGEMENT_PIPERD_NOTINTLB   BIT14       // 0/x/x/x PIPE Not in TLB
    #define PIPETLBMANAGEMENT_PIPERD_REQ        BIT13       // 0/x/x/x PIPE Read Request 
    #define PIPETLBMANAGEMENT_PIPERD_SLOTID     0x1FE0      // 0/x/x/x Slot ID
    #define PIPETLBMANAGEMENT_PIPERD_DCI        0x1F        // 0/x/x/x Device Context Index (DCI)
#define PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_0_REG 0x5060 // Pipe Endpoint Data Word 0 Register
    #define PIPETLBMANAGEMENT_PIPEDW0 PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_0_REG // 0/R/x/x Pipe Endpoint Data Word 0
#define PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_1_REG 0x5064 // Pipe Endpoint Data Word 1 Register
    #define PIPETLBMANAGEMENT_PIPEDW1 PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_1_REG // 0/R/x/x Pipe Endpoint Data Word 1
#define PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_2_REG 0x5068 // Pipe Endpoint Data Word 2 Register
    #define PIPETLBMANAGEMENT_PIPEDW2 PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_2_REG // 0/R/x/x Pipe Endpoint Data Word 2
#define PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_3_REG 0x506C // Pipe Endpoint Data Word 3 Register
    #define PIPETLBMANAGEMENT_PIPEDW3 PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_3_REG // 0/R/x/x Pipe Endpoint Data Word 3
#define PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_4_REG 0x5070 // Pipe Endpoint Data Word 4 Register
    #define PIPETLBMANAGEMENT_PIPEDW4 PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_4_REG // 0/R/x/x Pipe Endpoint Data Word 4
#define PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_5_REG 0x5074 // Pipe Endpoint Data Word 5 Register
    #define PIPETLBMANAGEMENT_PIPEDW5 PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_5_REG // 0/R/x/x Pipe Endpoint Data Word 5
#define PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_6_REG 0x5078 // Pipe Endpoint Data Word 6 Register
    #define PIPETLBMANAGEMENT_PIPEDW6 PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_6_REG // 0/R/x/x Pipe Endpoint Data Word 6
#define PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_7_REG 0x507C // Pipe Endpoint Data Word 7 Register
    #define PIPETLBMANAGEMENT_PIPEDW7 PIPETLBMANAGEMENT_PIPE_ENDPOINT_DATA_WORD_7_REG // 0/R/x/x Pipe Endpoint Data Word 7
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_0_REG 0x5080 // TLB Mapping Table Entry 0 Register
    #define PIPETLBMANAGEMENT_MPTBLE0 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_0_REG // 00010000h/R/x/x TLB Mapping Table Entry 0
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_1_REG 0x5084 // TLB Mapping Table Entry 1 Register
    #define PIPETLBMANAGEMENT_MPTBLE1 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_1_REG // 10000h/R/x/x TLB Mapping Table Entry 1
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_2_REG 0x5088 // TLB Mapping Table Entry 2 Register
    #define PIPETLBMANAGEMENT_MPTBLE2 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_2_REG // 10000h/R/x/x TLB Mapping Table Entry 2
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_3_REG 0x508C // TLB Mapping Table Entry 3 Register
    #define PIPETLBMANAGEMENT_MPTBLE3 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_3_REG // 10000h/R/x/x TLB Mapping Table Entry 3
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_4_REG 0x5090 // TLB Mapping Table Entry 4 Register
    #define PIPETLBMANAGEMENT_MPTBLE4 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_4_REG // 10000h/R/x/x TLB Mapping Table Entry 4
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_5_REG 0x5094 // TLB Mapping Table Entry 5 Register
    #define PIPETLBMANAGEMENT_MPTBLE5 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_5_REG // 10000h/R/x/x TLB Mapping Table Entry 5
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_6_REG 0x5098 // TLB Mapping Table Entry 6 Register
    #define PIPETLBMANAGEMENT_MPTBLE6 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_6_REG // 10000h/R/x/x TLB Mapping Table Entry 6
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_7_REG 0x509C // TLB Mapping Table Entry 7 Register
    #define PIPETLBMANAGEMENT_MPTBLE7 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_7_REG // 10000h/R/x/x TLB Mapping Table Entry 7
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_8_REG 0x50A0 // TLB Mapping Table Entry 8 Register
    #define PIPETLBMANAGEMENT_MPTBLE8 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_8_REG // 10000h/R/x/x TLB Mapping Table Entry 8
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_9_REG 0x50A4 // TLB Mapping Table Entry 9 Register
    #define PIPETLBMANAGEMENT_MPTBLE9 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_9_REG // 10000h/R/x/x TLB Mapping Table Entry 9
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_10_REG 0x50A8 // TLB Mapping Table Entry 10 Register
    #define PIPETLBMANAGEMENT_MPTBLE10 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_10_REG // 10000h/R/x/x TLB Mapping Table Entry 10
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_11_REG 0x50AC // TLB Mapping Table Entry 11 Register
    #define PIPETLBMANAGEMENT_MPTBLE11 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_11_REG // 10000h/R/x/x TLB Mapping Table Entry 11
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_12_REG 0x50B0 // TLB Mapping Table Entry 12 Register
    #define PIPETLBMANAGEMENT_MPTBLE12 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_12_REG // 10000h/R/x/x TLB Mapping Table Entry 12
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_13_REG 0x50B4 // TLB Mapping Table Entry 13 Register
    #define PIPETLBMANAGEMENT_MPTBLE13 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_13_REG // 10000h/R/x/x TLB Mapping Table Entry 13
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_14_REG 0x50B8 // TLB Mapping Table Entry 14 Register
    #define PIPETLBMANAGEMENT_MPTBLE14 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_14_REG // 10000h/R/x/x TLB Mapping Table Entry 14
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_15_REG 0x50BC // TLB Mapping Table Entry 15 Register
    #define PIPETLBMANAGEMENT_MPTBLE15 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_15_REG // 10000h/R/x/x TLB Mapping Table Entry 15
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_16_REG 0x50C0 // TLB Mapping Table Entry 16 Register
    #define PIPETLBMANAGEMENT_MPTBLE16 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_16_REG // 10000h/R/x/x TLB Mapping Table Entry 16
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_17_REG 0x50C4 // TLB Mapping Table Entry 17 Register
    #define PIPETLBMANAGEMENT_MPTBLE17 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_17_REG // 10000h/R/x/x TLB Mapping Table Entry 17
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_18_REG 0x50C8 // TLB Mapping Table Entry 18 Register
    #define PIPETLBMANAGEMENT_MPTBLE18 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_18_REG // 10000h/R/x/x TLB Mapping Table Entry 18
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_19_REG 0x50CC // TLB Mapping Table Entry 19 Register
    #define PIPETLBMANAGEMENT_MPTBLE19 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_19_REG // 10000h/R/x/x TLB Mapping Table Entry 19
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_20_REG 0x50D0 // TLB Mapping Table Entry 20 Register
    #define PIPETLBMANAGEMENT_MPTBLE20 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_20_REG // 10000h/R/x/x TLB Mapping Table Entry 20
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_21_REG 0x50D4 // TLB Mapping Table Entry 21 Register
    #define PIPETLBMANAGEMENT_MPTBLE21 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_21_REG // 10000h/R/x/x TLB Mapping Table Entry 21
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_22_REG 0x50D8 // TLB Mapping Table Entry 22 Register
    #define PIPETLBMANAGEMENT_MPTBLE22 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_22_REG // 10000h/R/x/x TLB Mapping Table Entry 22
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_23_REG 0x50DC // TLB Mapping Table Entry 23 Register
    #define PIPETLBMANAGEMENT_MPTBLE23 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_23_REG // 10000h/R/x/x TLB Mapping Table Entry 23
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_24_REG 0x50E0 // TLB Mapping Table Entry 24 Register
    #define PIPETLBMANAGEMENT_MPTBLE24 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_24_REG // 10000h/R/x/x TLB Mapping Table Entry 24
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_25_REG 0x50E4 // TLB Mapping Table Entry 25 Register
    #define PIPETLBMANAGEMENT_MPTBLE25 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_25_REG // 10000h/R/x/x TLB Mapping Table Entry 25
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_26_REG 0x50E8 // TLB Mapping Table Entry 26 Register
    #define PIPETLBMANAGEMENT_MPTBLE26 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_26_REG // 10000h/R/x/x TLB Mapping Table Entry 26
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_27_REG 0x50EC // TLB Mapping Table Entry 27 Register
    #define PIPETLBMANAGEMENT_MPTBLE27 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_27_REG // 10000h/R/x/x TLB Mapping Table Entry 27
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_28_REG 0x50F0 // TLB Mapping Table Entry 28 Register
    #define PIPETLBMANAGEMENT_MPTBLE28 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_28_REG // 10000h/R/x/x TLB Mapping Table Entry 28
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_29_REG 0x50F4 // TLB Mapping Table Entry 29 Register
    #define PIPETLBMANAGEMENT_MPTBLE29 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_29_REG // 10000h/R/x/x TLB Mapping Table Entry 29
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_30_REG 0x50F8 // TLB Mapping Table Entry 30 Register
    #define PIPETLBMANAGEMENT_MPTBLE30 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_30_REG // 10000h/R/x/x TLB Mapping Table Entry 30
#define PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_31_REG 0x50FC // TLB Mapping Table Entry 31 Register
    #define PIPETLBMANAGEMENT_MPTBLE31 PIPETLBMANAGEMENT_TLB_MAPPING_TABLE_ENTRY_31_REG // 10000h/R/x/x TLB Mapping Table Entry 31
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ARRAY_BASE_ADR_REG 0x5100 // Scratchpad Buffer Array Base Address Register
    #define PIPETLBMANAGEMENT_SBABA_63_6    0xFFFFFFFFFFFFFFC0  // 0/R/x/x Scratchpad Buffer Array Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_0_BASE_ADR_REG 0x5108 // Scratchpad Buffer Entry 0 Base Address Register
    #define PIPETLBMANAGEMENT_SBE0BA_63_12  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 0 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_1_BASE_ADR_REG 0x5110 // Scratchpad Buffer Entry 1 Base Address Register
    #define PIPETLBMANAGEMENT_SBE1BA_63_12  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 1 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_2_BASE_ADR_REG 0x5118 // Scratchpad Buffer Entry 2 Base Address Register
    #define PIPETLBMANAGEMENT_SBE2BA_63_6   0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 2 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_3_BASE_ADR_REG 0x5120 // Scratchpad Buffer Entry 3 Base Address Register
    #define PIPETLBMANAGEMENT_SBE3BA_63_6   0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 3 BaseAddress
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_4_BASE_ADR_REG 0x5128 // Scratchpad Buffer Entry 4 Base Address Register
    #define PIPETLBMANAGEMENT_SBE4BA_63_6   0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 4 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_5_BASE_ADR_REG 0x5130 // Scratchpad Buffer Entry 5 Base Address Register
    #define PIPETLBMANAGEMENT_SBE5BA_63_6   0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 5 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_6_BASE_ADR_REG 0x5138 // Scratchpad Buffer Entry 6 Base Address Register
    #define PIPETLBMANAGEMENT_SBE6BA_63_6   0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 6 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_7_BASE_ADR_REG 0x5140 // Scratchpad Buffer Entry 7 Base Address Register
    #define PIPETLBMANAGEMENT_SBE7BA_63_6   0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 7 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_8_BASE_ADR_REG 0x5148 // Scratchpad Buffer Entry 8 Base Address Register
    #define PIPETLBMANAGEMENT_SBE8BA_63_6   0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 8 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_9_BASE_ADR_REG 0x5150 // Scratchpad Buffer Entry 9 Base Address Register
    #define PIPETLBMANAGEMENT_SBE9BA_63_6   0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 9 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_10_BASE_ADR_REG 0x5158 // Scratchpad Buffer Entry 10 Base Address Register
    #define PIPETLBMANAGEMENT_SBE10BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 10 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_11_BASE_ADR_REG 0x5160 // Scratchpad Buffer Entry 11 Base Address Register
    #define PIPETLBMANAGEMENT_SBE11BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 11 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_12_BASE_ADR_REG 0x5168 // Scratchpad Buffer Entry 12 Base Address Register
    #define PIPETLBMANAGEMENT_SBE12BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 12 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_13_BASE_ADR_REG 0x5170 // Scratchpad Buffer Entry 13 Base Address Register
    #define PIPETLBMANAGEMENT_SBE13BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 13 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_14_BASE_ADR_REG 0x5178 // Scratchpad Buffer Entry 14 Base Address Register
    #define PIPETLBMANAGEMENT_SBE14BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 14 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_15_BASE_ADR_REG 0x5180 // Scratchpad Buffer Entry 15 Base Address Register
    #define PIPETLBMANAGEMENT_SBE15BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 15 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_16_BASE_ADR_REG 0x5188 // Scratchpad Buffer Entry 16 Base Address Register
    #define PIPETLBMANAGEMENT_SBE16BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 16 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_17_BASE_ADR_REG 0x5190 // Scratchpad Buffer Entry 17 Base Address Register
    #define PIPETLBMANAGEMENT_SBE117BA_63_6 0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 17 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_18_BASE_ADR_REG 0x5198 // Scratchpad Buffer Entry 18 Base Address Register
    #define PIPETLBMANAGEMENT_SBE18BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 18 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_19_BASE_ADR_REG 0x51A0 // Scratchpad Buffer Entry 19 Base Address Register
    #define PIPETLBMANAGEMENT_SBE19BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 19 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_20_BASE_ADR_REG 0x51A8 // Scratchpad Buffer Entry 20 Base Address Register
    #define PIPETLBMANAGEMENT_SBE20BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 20 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_21_BASE_ADR_REG 0x51B0 // Scratchpad Buffer Entry 21 Base Address Register
    #define PIPETLBMANAGEMENT_SBE21BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 21 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_22_BASE_ADR_REG 0x51B8 // Scratchpad Buffer Entry 22 Base Address Register
    #define PIPETLBMANAGEMENT_SBE22BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 22 Base Address
#define PIPETLBMANAGEMENT_SCRATCHPAD_BUFFER_ENTRY_23_BASE_ADR_REG 0x51C0 // Scratchpad Buffer Entry 23 Base Address Register
    #define PIPETLBMANAGEMENT_SBE23BA_63_6  0xFFFFFFFFFFFFF000  // 0/R/x/x Scratchpad Buffer Entry 23 Base Address
#define PIPETLBMANAGEMENT_PIPETLB_CTLR_STATE_MACHINE_REG 0x5200 // PIPETLB Controller State Machine Register
    #define PIPETLBMANAGEMENT_PTSM  0x3FFF      // 1h/R/x/x PIPETLB Controller State Machine (For debugging)
// FMTIMER Management
#define FMTIMERMANAGEMENT_BEST_EFFORT_LATENCY_TOLERANCE_REG 0x6000 // Best Effort Latency Tolerance Register
    #define FMTIMERMANAGEMENT_BELT  0x3FFFFFFF      // F4240h/x/x/x Minimum BELT
#define FMTIMERMANAGEMENT_BUS_INTERVAL_ADJ_REG 0x6004 // Bus Interval Adjustment Register
    #define FMTIMERMANAGEMENT_BIAC2CNT  0xFFF00000  // 0/x/x/x Interval 2 adjustment number
    #define FMTIMERMANAGEMENT_BIAC1CNT  0xFFF00     // 0/x/x/x Interval 1 adjustment number
    #define FMTIMERMANAGEMENT_BIACDIR   BIT7        // 0/x/x/x Adjustment direction
    #define FMTIMERMANAGEMENT_BIACDEV   0x7F        // 0/x/x/x BIAC DEVADDR
#define FMTIMERMANAGEMENT_BIAC1_REG 0x6008 // BIAC1 Register
    #define FMTIMERMANAGEMENT_BIAC1EN   BIT13       // 0/x/x/x Whether adjustment interva1 l is valid and can be used by H/W for int...
    #define FMTIMERMANAGEMENT_BIAC1VAL  0x1FFF      // 0/x/x/x Adjustment interval 1
#define FMTIMERMANAGEMENT_BIAC2_REG 0x600C // BIAC2 Register
    #define FMTIMERMANAGEMENT_BIAC2EN   BIT13       // 0/x/x/x Whether adjustment interval 2 is valid and can be used by H/W for int...
    #define FMTIMERMANAGEMENT_BIAC2VAL  0x1FFF      // 0/x/x/x Adjustment interval 2
#define FMTIMERMANAGEMENT_SUB_MF_CNTER_REG 0x6010 // Sub MF Counter Register
    #define FMTIMERMANAGEMENT_SUBFRAMECNT   (BIT0 + BIT1)   // 0/R/x/x Sub frame counter(one MF is divided into 4 sub frame)
#define FMTIMERMANAGEMENT_MFINDEX_VALUE_REG 0x6014 // MFINDEX value Register
    #define FMTIMERMANAGEMENT_MFINDEX   0x3FFF      // 0/R/x/x MFINDEX Value
// DEVN Management
#define DEVNMANAGEMENT_DEVN_STA_REG 0x8000 // DEVN Status Register
    #define DEVNMANAGEMENT_DEVNS_3  BIT3    // 0/x/x/x Ping response is received
    #define DEVNMANAGEMENT_DEVNS_2  BIT2    // 0/x/x/x Function wake device notification
    #define DEVNMANAGEMENT_DEVNS_1  BIT1    // 0/x/x/x Bus interval adjustment device notification
    #define DEVNMANAGEMENT_DEVNS_0  BIT0    // 0/x/x/x LTM device notification
#define DEVNMANAGEMENT_LTM_DATA_REG 0x8001 // LTM data Register
    #define DEVNMANAGEMENT_DEVNINFO_19_8    0xFFF00     // 0/R/x/x BELT value
    #define DEVNMANAGEMENT_DEVNADDR_LTM     0x7F        // 0/R/x/x Device address of the device which send LTM
#define DEVNMANAGEMENT_BUS_INTERVAL_ADJ_CTL_REG 0x8004 // Bus Interval Adjustment Control Register
    #define DEVNMANAGEMENT_DEVNINFO_31_16   0xFFFF00    // 0/R/x/x Request Bus interval adjustment value
    #define DEVNMANAGEMENT_DEVNADDR_BIAR    0x7F        // 0/R/x/x Device address of the device which sends BIAR
#define DEVNMANAGEMENT_PING_RESPONSE_INFORMATION_REG 0x8020 // Ping Response Information Register
    #define DEVNMANAGEMENT_DEVNINFO_11_8    0x1E00                  // 0/R/x/x Endpoint number
    #define DEVNMANAGEMENT_DEVNINFO_7       BIT8                    // 0/R/x/x Direction
    #define DEVNMANAGEMENT_DEVNADDR_PING    0x7F                    // 0/R/x/x Device address of the device which sends ping response
#define DEVNMANAGEMENT_PING_RESPONSE_INFORMATION_REG_Z1 0x8024 // Ping Response Information Register
    #define DEVNMANAGEMENT_EVENTRFULL3      BIT6        // 0/R/x/x Event Ring 3 is full
    #define DEVNMANAGEMENT_EVENTRFULL2      BIT5        // 0/R/x/x Event Ring 2 is full
    #define DEVNMANAGEMENT_EVENTRFULL1      BIT4        // 0/R/x/x Event Ring 1 is full
    #define DEVNMANAGEMENT_EVENTRFULL0      BIT3        // 0/R/x/x Event Ring 0 is full
    #define DEVNMANAGEMENT_LTM_EVENTREQ     BIT2        // 0/x/x/x LTM device notification event is needed to sent
    #define DEVNMANAGEMENT_BIAR_EVENTREQ    BIT1        // 0/x/x/x BIAR device notification event is needed to sent
    #define DEVNMANAGEMENT_FW_EVENTREQ      BIT0        // 0/x/x/x Function wakeup device notification event is needed to sent 
#define DEVNMANAGEMENT_FUN_WAKEUP_EVENT_VECTOR_REG 0x8030 // Function Wakeup Event Vector Register
    #define DEVNMANAGEMENT_FW_EVENTVEC DEVNMANAGEMENT_FUN_WAKEUP_EVENT_VECTOR_REG // 0/R/x/x Event Vector For Function Wake Up
#define DEVNMANAGEMENT_BIAR_EVENT_VECTOR_REG 0x8040 // BIAR Event Vector Register
    #define DEVNMANAGEMENT_BIAR_EVENTVEC DEVNMANAGEMENT_BIAR_EVENT_VECTOR_REG // 0/R/x/x Event Vector For BIAR
#define DEVNMANAGEMENT_LTM_EVENT_VECTOR_REG 0x8050 // LTM Event Vector Register
    #define DEVNMANAGEMENT_LTM_EVENTVEC DEVNMANAGEMENT_LTM_EVENT_VECTOR_REG // 0/R/x/x Event Vector For LTM
// SSBI Schedule Management
#define SSBISCHEDULEMANAGEMENT_SCHDINTR_REG 0xC000 // SCHDINTR Register
    #define SSBISCHEDULEMANAGEMENT_NRDYINTE         BIT12                   // 0/x/x/x NRDY/ERDY Controller Interrupt Enable (No use for HSBI part)
    #define SSBISCHEDULEMANAGEMENT_ASY2INTE         BIT11                   // 0/x/x/x Async Controller 2 Interrupt Enable
    #define SSBISCHEDULEMANAGEMENT_ASY1INTE         BIT10                   // 0/x/x/x Async Controller 1 Interrupt Enable
    #define SSBISCHEDULEMANAGEMENT_PER1INTE         BIT8                    // 0/x/x/x Periodic Controller 1 Interrupt Enable
    #define SSBISCHEDULEMANAGEMENT_NRDYNOEMPTYINTE  BIT5                    // 0/x/x/x NRDY Address List is Not Empty For Long Time Interrupt Enable (No use...
    #define SSBISCHEDULEMANAGEMENT_MISSERDYINTE     BIT4                    // 0/x/x/x ERDY Miss Interrupt Enable (No use for HSBI part)
    #define SSBISCHEDULEMANAGEMENT_TRBEINTE         BIT3                    // 0/x/x/x TRB Error Interrupt Enable
    #define SSBISCHEDULEMANAGEMENT_EE               BIT2                    // 0/x/x/x TR Exhausted Interrupt Enable
    #define SSBISCHEDULEMANAGEMENT_HE               BIT1                    // 0/x/x/x Halted Interrupt Enable
    #define SSBISCHEDULEMANAGEMENT_SCHINTE          BIT0                    // 0/x/x/x Schedule Interrupt Enable
#define SSBISCHEDULEMANAGEMENT_SCHEDULE_INTR_STA_REG 0xC002 // Schedule Interrupt Status Register
    #define SSBISCHEDULEMANAGEMENT_PTD7CMPL             BIT15   // 0/x/x/x Periodic TD Queue Entry 7 Complete Status 
    #define SSBISCHEDULEMANAGEMENT_PTD6CMPL             BIT14   // 0/x/x/x Periodic TD Queue Entry 6 Complete Status 
    #define SSBISCHEDULEMANAGEMENT_PTD5CMPL             BIT13   // 0/x/x/x Periodic TD Queue Entry 5 Complete Status 
    #define SSBISCHEDULEMANAGEMENT_PTD4CMPL             BIT12   // 0/x/x/x Periodic TD Queue Entry 4 Complete Status 
    #define SSBISCHEDULEMANAGEMENT_PTD3CMPL             BIT11   // 0/x/x/x Periodic TD Queue Entry 3 Complete Status 
    #define SSBISCHEDULEMANAGEMENT_PTD2CMPL             BIT10   // 0/x/x/x Periodic TD Queue Entry 2 Complete Status 
    #define SSBISCHEDULEMANAGEMENT_PTD1CMPL             BIT9    // 0/x/x/x Periodic TD Queue Entry 1 Complete Status 
    #define SSBISCHEDULEMANAGEMENT_PTD0CMPL             BIT8    // 0/x/x/x Periodic TD Queue Entry 0 Complete Status 
    #define SSBISCHEDULEMANAGEMENT_NRDYNOEMPTY_LONGSTS  BIT6    // 0/x/x/x NRDY Address List is Not Empty For Long Time Interrupt Mirror Status ...
    #define SSBISCHEDULEMANAGEMENT_MISSERDY_INTSTS_MIR  BIT5    // 0/x/x/x ERDY Miss Interrupt Status (No use for HSBI part)
    #define SSBISCHEDULEMANAGEMENT_NRDYSTS              BIT4    // 0/R/x/x NRDY/ERDY Controller Interrupt Status (NRDYSTS).
    #define SSBISCHEDULEMANAGEMENT_ASY2STS              BIT3    // 0/R/x/x Async Controller 2 Interrupt Status 
    #define SSBISCHEDULEMANAGEMENT_ASY1STS              BIT2    // 0/R/x/x Async Controller 1 Interrupt Status 
    #define SSBISCHEDULEMANAGEMENT_PER1STS              BIT0    // 0/R/x/x Periodic Controller 1 Interrupt Status 
#define SSBISCHEDULEMANAGEMENT_PERIODIC_CTLR_INTR_STA_REG 0xC004 // Periodic Controller Interrupt Status Register
    #define SSBISCHEDULEMANAGEMENT_PEREP_TRBERROR   BIT15       // 0/x/x/x TRB Error.
    #define SSBISCHEDULEMANAGEMENT_PEREP_EMPTY      BIT14       // 0/x/x/x TR Exhausted.
    #define SSBISCHEDULEMANAGEMENT_PEREP_HALT       BIT13       // 0/x/x/x Endpoint Halted (HALT).
    #define SSBISCHEDULEMANAGEMENT_PEREP_SLOTID     0x1FE0      // 0/R/x/x Slot ID
    #define SSBISCHEDULEMANAGEMENT_PEREP_DCI        0x1F        // 0/R/x/x Device Context Index.
#define SSBISCHEDULEMANAGEMENT_ASYNC_CTLR_1_INTR_STA_REG 0xC00C // Async Controller 1 Interrupt Status Register
    #define SSBISCHEDULEMANAGEMENT_ASYEP1_TRBERROR  BIT15       // 0/x/x/x TRB Error.
    #define SSBISCHEDULEMANAGEMENT_ASYEP1_EMPTY     BIT14       // 0/x/x/x TR Exhausted.
    #define SSBISCHEDULEMANAGEMENT_ASYEP1_HALT      BIT13       // 0/x/x/x Endpoint Halted (HALT).
    #define SSBISCHEDULEMANAGEMENT_ASYEP1_SLOTID    0x1FE0      // 0/R/x/x Slot ID
    #define SSBISCHEDULEMANAGEMENT_ASYEP1_DCI       0x1F        // 0/R/x/x Device Context Index.
#define SSBISCHEDULEMANAGEMENT_ASYNC_CTLR_2_INTR_STA_REG 0xC010 // Async Controller 2 Interrupt Status Register
    #define SSBISCHEDULEMANAGEMENT_ASYEP2_TRBERROR  BIT15       // 0/x/x/x TRB Error.
    #define SSBISCHEDULEMANAGEMENT_ASYEP2_EMPTY     BIT14       // 0/x/x/x TR Exhausted.
    #define SSBISCHEDULEMANAGEMENT_ASYEP2_HALT      BIT13       // 0/x/x/x Endpoint Halted (HALT).
    #define SSBISCHEDULEMANAGEMENT_ASYEP2_SLOTID    0x1FE0      // 0/R/x/x Slot ID
    #define SSBISCHEDULEMANAGEMENT_ASYEP2_DCI       0x1F        // 0/R/x/x Device Context Index.
#define SSBISCHEDULEMANAGEMENT_NRDY_ERDY_CTLR_INTR_STA_REG_NO_USE_FOR_HSBI 0xC014 // NRDY/ERDY Controller Interrupt Status Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_TRBERROR  BIT15       // 0/x/x/x TRB Error.
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_EMPTY     BIT14       // 0/x/x/x TR Exhausted.
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_HALT      BIT13       // 0/x/x/x Endpoint Halted (HALT).
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_SLOTID    0x1FE0      // 0/R/x/x Slot ID
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_DCI       0x1F        // 0/R/x/x Device Context Index.
#define SSBISCHEDULEMANAGEMENT_MISSERDY_CTLR_INTR_STA_REG_NO_USE_FOR_HSBI 0xC018 // MISSERDY Controller Interrupt Status Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_MISSERDY_INTSTS  BIT28                   // 0/x/x/x ERDY Miss Interrupt Status (No use for HSBI part)
    #define SSBISCHEDULEMANAGEMENT_ERDYSTREAMID     0xFFFF000               // 0/R/x/x STREAMID of ERDY TP
    #define SSBISCHEDULEMANAGEMENT_ERDYDIR          BIT11                   // 0/R/x/x Direction of ERDY TP
    #define SSBISCHEDULEMANAGEMENT_ERDYEPTNUM       0x780                   // 0/R/x/x Endpoint Number of ERDY TP
    #define SSBISCHEDULEMANAGEMENT_ERDYDEVADDR      0x7F                    // 0/R/x/x Device Address of ERDY TP
#define SSBISCHEDULEMANAGEMENT_MISSERDY_CTLR_INTR_STA_REG_NO_USE_FOR_HSBI_Z1 0xC01C // MISSERDY Controller Interrupt Status Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_NRDYNOEMPTY_LONGSTS1 BIT8        // 0/x/x/x NRDY Address List is Not Empty For Long Time Interrupt Mirror Status ...
    #define SSBISCHEDULEMANAGEMENT_EPONEONLY            BIT0        // 0/x/x/x Only 1 Endpoint in Active List
#define SSBISCHEDULEMANAGEMENT_PERIODIC_CTL_AND_STA_REG 0xC020 // Periodic Control and Status Register
    #define SSBISCHEDULEMANAGEMENT_PTDQUEUE_WPTR    (BIT20 + BIT21 + BIT22) // 0/x/x/x Periodic TD Queue Current Write Pointer
    #define SSBISCHEDULEMANAGEMENT_PTDQUEUE_RPTR    (BIT16 + BIT17 + BIT18) // 0/R/x/x Periodic TD Queue Current Read Pointer
    #define SSBISCHEDULEMANAGEMENT_PTDQUEUE_EMPTY   BIT9                    // 0/R/x/x Periodic TD Queue is Empty
    #define SSBISCHEDULEMANAGEMENT_PER_STS          BIT8                    // 0/R/x/x Periodic Status
    #define SSBISCHEDULEMANAGEMENT_PER_EN           BIT0                    // 0/x/x/x Periodic Enable 
#define SSBISCHEDULEMANAGEMENT_PERIODIC_ENDPOINT_CTL_REG 0xC024 // Periodic Endpoint Control Register
    #define SSBISCHEDULEMANAGEMENT_PERIODIC_STPEPREQ    BIT13       // 0/x/x/x Stop Endpoint Request 
    #define SSBISCHEDULEMANAGEMENT_PERIODIC_STPEPSLOTID 0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PERIODIC_STPEPDCI    0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_REMOVE_CTL_REG 0xC028 // Periodic TD Queue Remove Control Register
    #define SSBISCHEDULEMANAGEMENT_PERIODIC_RMEPREQ     BIT13       // 0/x/x/x Remove Endpoint Request 
    #define SSBISCHEDULEMANAGEMENT_PERIODIC_RMEPSLOTID  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PERIODIC_RMEPDCI     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_ENTRY_0_REG 0xC030 // Periodic TD Queue Entry 0 Register
    #define SSBISCHEDULEMANAGEMENT_LSTSO0       BIT31       // 0/x/x/x Last Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_FSTSO0       BIT30       // 0/x/x/x First Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_IOC0         BIT28       // 0/x/x/x IOC.
    #define SSBISCHEDULEMANAGEMENT_ACTIVE0      BIT27       // 0/x/x/x Active.
    #define SSBISCHEDULEMANAGEMENT_EXEMFINDEX0  0x7FFE000   // 0/x/x/x Execute Microframe Index.
    #define SSBISCHEDULEMANAGEMENT_PTD_SLOTID0  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PTD_DCI0     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_ENTRY_1_REG 0xC034 // Periodic TD Queue Entry 1 Register
    #define SSBISCHEDULEMANAGEMENT_LSTSO1       BIT31       // 0/x/x/x Last Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_FSTSO1       BIT30       // 0/x/x/x First Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_IOC1         BIT28       // 0/x/x/x IOC.
    #define SSBISCHEDULEMANAGEMENT_ACTIVE1      BIT27       // 0/x/x/x Active.
    #define SSBISCHEDULEMANAGEMENT_EXEMFINDEX1  0x7FFE000   // 0/x/x/x Execute Microframe Index.
    #define SSBISCHEDULEMANAGEMENT_PTD_SLOTID1  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PTD_DCI1     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_ENTRY_2_REG 0xC038 // Periodic TD Queue Entry 2 Register
    #define SSBISCHEDULEMANAGEMENT_LSTSO2       BIT31       // 0/x/x/x Last Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_FSTSO2       BIT30       // 0/x/x/x First Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_IOC2         BIT28       // 0/x/x/x IOC.
    #define SSBISCHEDULEMANAGEMENT_ACTIVE2      BIT27       // 0/x/x/x Active.
    #define SSBISCHEDULEMANAGEMENT_EXEMFINDEX2  0x7FFE000   // 0/x/x/x Execute Microframe Index.
    #define SSBISCHEDULEMANAGEMENT_PTD_SLOTID2  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PTD_DCI2     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_ENTRY_3_REG 0xC03C // Periodic TD Queue Entry 3 Register
    #define SSBISCHEDULEMANAGEMENT_LSTSO3       BIT31       // 0/x/x/x Last Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_FSTSO3       BIT30       // 0/x/x/x First Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_IOC3         BIT28       // 0/x/x/x IOC.
    #define SSBISCHEDULEMANAGEMENT_ACTIVE3      BIT27       // 0/x/x/x Active.
    #define SSBISCHEDULEMANAGEMENT_EXEMFINDEX3  0x7FFE000   // 0/x/x/x Execute Microframe Index.
    #define SSBISCHEDULEMANAGEMENT_PTD_SLOTID3  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PTD_DCI3     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_ENTRY_4_REG 0xC040 // Periodic TD Queue Entry 4 Register
    #define SSBISCHEDULEMANAGEMENT_LSTSO4       BIT31       // 0/x/x/x Last Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_FSTSO4       BIT30       // 0/x/x/x First Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_IOC4         BIT28       // 0/x/x/x IOC.
    #define SSBISCHEDULEMANAGEMENT_ACTIVE4      BIT27       // 0/x/x/x Active.
    #define SSBISCHEDULEMANAGEMENT_EXEMFINDEX4  0x7FFE000   // 0/x/x/x Execute Microframe Index.
    #define SSBISCHEDULEMANAGEMENT_PTD_SLOTID4  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PTD_DCI4     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_ENTRY_5_REG 0xC044 // Periodic TD Queue Entry 5 Register
    #define SSBISCHEDULEMANAGEMENT_LSTSO5       BIT31       // 0/x/x/x Last Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_FSTSO5       BIT30       // 0/x/x/x First Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_IOC5         BIT28       // 0/x/x/x IOC.
    #define SSBISCHEDULEMANAGEMENT_ACTIVE5      BIT27       // 0/x/x/x Active.
    #define SSBISCHEDULEMANAGEMENT_EXEMFINDEX5  0x7FFE000   // 0/x/x/x Execute Microframe Index.
    #define SSBISCHEDULEMANAGEMENT_PTD_SLOTID5  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PTD_DCI5     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_ENTRY_6_REG 0xC048 // Periodic TD Queue Entry 6 Register
    #define SSBISCHEDULEMANAGEMENT_LSTSO6       BIT31       // 0/x/x/x Last Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_FSTSO6       BIT30       // 0/x/x/x First Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_IOC6         BIT28       // 0/x/x/x IOC.
    #define SSBISCHEDULEMANAGEMENT_ACTIVE6      BIT27       // 0/x/x/x Active.
    #define SSBISCHEDULEMANAGEMENT_EXEMFINDEX6  0x7FFE000   // 0/x/x/x Execute Microframe Index.
    #define SSBISCHEDULEMANAGEMENT_PTD_SLOTID6  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PTD_DCI6     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_PERIODIC_TD_QUEUE_ENTRY_7_REG 0xC04C // Periodic TD Queue Entry 7 Register
    #define SSBISCHEDULEMANAGEMENT_LSTSO7       BIT31       // 0/x/x/x Last Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_FSTSO7       BIT30       // 0/x/x/x First Service Opportunity 
    #define SSBISCHEDULEMANAGEMENT_IOC7         BIT28       // 0/x/x/x IOC.
    #define SSBISCHEDULEMANAGEMENT_ACTIVE7      BIT27       // 0/x/x/x Active.
    #define SSBISCHEDULEMANAGEMENT_EXEMFINDEX7  0x7FFE000   // 0/x/x/x Execute Microframe Index.
    #define SSBISCHEDULEMANAGEMENT_PTD_SLOTID7  0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_PTD_DCI7     0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_ASYNC_LIST_1_CTL_AND_STA_REG 0xC080 // Async List 1 Control and Status Register
    #define SSBISCHEDULEMANAGEMENT_ASYNC1_STS       BIT8    // 0/x/x/x Async Status 
    #define SSBISCHEDULEMANAGEMENT_ASYNC1_DBRING    BIT1    // 0/x/x/x Async List Endpoint Doorbell Ring
    #define SSBISCHEDULEMANAGEMENT_ASYNC1_EN        BIT0    // 0/x/x/x Async Enable 
#define SSBISCHEDULEMANAGEMENT_ASYNC_LIST_1_ADR_REG 0xC082 // Async List 1 Address Register
    #define SSBISCHEDULEMANAGEMENT_SLOTID   0x1FE0                  // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI      0x1F                    // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_ASYNC_LIST_1_ENDPOINT_CTL_REG 0xC084 // Async List 1 Endpoint Control Register
    #define SSBISCHEDULEMANAGEMENT_ASYNC1_STPEPREQ      BIT13       // 0/x/x/x Stop Endpoint Request 
    #define SSBISCHEDULEMANAGEMENT_ASYNC1_STPEPSLOTID   0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_ASYNC1_STPEPDCI      0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_ASYNC_LIST_2_CTL_AND_STA_REG 0xC090 // Async List 2 Control and Status Register
    #define SSBISCHEDULEMANAGEMENT_ASYNC2_STS       BIT8    // 0/R/x/x Async Status 
    #define SSBISCHEDULEMANAGEMENT_ASYNC2_DBRING    BIT1    // 0/x/x/x Async List Endpoint Doorbell Ring
    #define SSBISCHEDULEMANAGEMENT_ASYNC2_EN        BIT0    // 0/x/x/x Async Enable 
#define SSBISCHEDULEMANAGEMENT_ASYNC_LIST_2_ADR_REG 0xC092 // Async List 2 Address Register
    #define SSBISCHEDULEMANAGEMENT_ASYNCLIST2_SLOTID    0x1FE0                  // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_ASYNCLIST2_DCI       0x1F                    // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_ASYNC_LIST_2_ENDPOINT_CTL_REG 0xC094 // Async List 2 Endpoint Control Register
    #define SSBISCHEDULEMANAGEMENT_ASYNC2_STPEPREQ      BIT13       // 0/x/x/x Stop Endpoint Request 
    #define SSBISCHEDULEMANAGEMENT_ASYNC2_STPEPSLOTID   0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_ASYNC2_STPEPDCI      0x1F        // 0/x/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ENDPOINT_CTLR_REG_NO_USE_FOR_HSBI 0xC0D0 // NRDY Endpoint Controller Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_STPEPNOHIT_STS    BIT14       // 0/x/x/x Endpoint Not Hit NRDY Address List.
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_STPEPREQ          BIT13       // 0/x/x/x Stop Endpoint Request.
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_STPEPSLOTID       0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_STOPEPDCI         0x1F        // 0/x/x/x Device Context Index 
#define SSBISCHEDULEMANAGEMENT_STREAM_ENDPOINT_DOORBELL_REG_NO_USE_FOR_HSBI 0xC0D4 // Stream Endpoint Doorbell Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_DBSTREAMID           0xFFFF0000  // 0/x/x/x DB Stream ID.
    #define SSBISCHEDULEMANAGEMENT_STPEPREQ             BIT14       // 0/x/x/x Doorbell Pending Value Request.
    #define SSBISCHEDULEMANAGEMENT_SPIDLEDBPV_SLOTID    0x1FE0      // 0/x/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_SPIDLEDBPV_DCI       0x1F        // 0/x/x/x Device Context Index 
#define SSBISCHEDULEMANAGEMENT_NRDY_OUT_BUFFER_REG_NO_USE_FOR_HSBI 0xC0D8 // NRDY OUT Buffer Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_NRDYOUTBUF_INVALID       BIT14           // 0/x/x/x NRDY OUT Data Buffer Invalid Request
    #define SSBISCHEDULEMANAGEMENT_NRDYOUTBUF_INVALID_INFO  0xFFF           // 0/x/x/x NRDY OUT Data Buffer Invalid Information
#define SSBISCHEDULEMANAGEMENT_PING_PACKET_FORMAT_REG 0xC100 // Ping Packet Format Register
    #define SSBISCHEDULEMANAGEMENT_PINGPKT  0xFFFFFFFFFFF       // 0/x/x/x Ping Packet TP.
#define SSBISCHEDULEMANAGEMENT_PING_PACKET_REQ_REG 0xC10C // Ping Packet Request Register
    #define SSBISCHEDULEMANAGEMENT_PINGPKT_PENDINGP4    BIT19                   // 0/x/x/x SS Port4 Penging Ping Request Status
    #define SSBISCHEDULEMANAGEMENT_PINGPKT_PENDINGP3    BIT18                   // 0/x/x/x SS Port3 Penging Ping Request Status
    #define SSBISCHEDULEMANAGEMENT_PINGPKT_PENDINGP2    BIT17                   // 0/x/x/x SS Port2 Penging Ping Request Status
    #define SSBISCHEDULEMANAGEMENT_PINGPKT_PENDINGP1    BIT16                   // 0/x/x/x SS Port1 Penging Ping Request Status
    #define SSBISCHEDULEMANAGEMENT_PINGPKT_STALL        BIT8                    // 0/x/x/x Ping Packet STALL.
    #define SSBISCHEDULEMANAGEMENT_PINGPKT_PORTNUM      0xF0                    // 0/x/x/x Ping Packet Port Number
    #define SSBISCHEDULEMANAGEMENT_PINGPKT_REQ          BIT0                    // 0/x/x/x Ping Packet Request.
#define SSBISCHEDULEMANAGEMENT_CMD_PACKET_FORMAT_REG 0xC110 // Command Packet Format Register
    #define SSBISCHEDULEMANAGEMENT_CMDPKT SSBISCHEDULEMANAGEMENT_CMD_PACKET_FORMAT_REG // 0/x/x/x Command Packet TP.
#define SSBISCHEDULEMANAGEMENT_CMD_PACKET_REQ_REG 0xC11C // Command Packet Request Register
    #define SSBISCHEDULEMANAGEMENT_CMDPKT_NAK       BIT10                   // 0/x/x/x Command Packet NRDY
    #define SSBISCHEDULEMANAGEMENT_CMDPKT_ERR       BIT9                    // 0/x/x/x Command Packet Error
    #define SSBISCHEDULEMANAGEMENT_CMDPKT_STALL     BIT8                    // 0/x/x/x Command Packet Stall
    #define SSBISCHEDULEMANAGEMENT_CMDPKT_PORTNUM   0xF0                    // 0/x/x/x Command Packet Port Number
    #define SSBISCHEDULEMANAGEMENT_CMDPKT_REQ       BIT0                    // 0/x/x/x Command Packet Request
#define SSBISCHEDULEMANAGEMENT_CMD_DPP_PACKET_FORMAT_REG 0xC120 // Command DPP Packet Format Register
    #define SSBISCHEDULEMANAGEMENT_CMDDPP SSBISCHEDULEMANAGEMENT_CMD_DPP_PACKET_FORMAT_REG // 0/x/x/x Command DPP Packet.
#define SSBISCHEDULEMANAGEMENT_CMD_PACKET_DPP_IN_DATA_REG 0xC140 // Command Packet DPP IN DATA Register
    #define SSBISCHEDULEMANAGEMENT_CMDPKT_INDATABUF SSBISCHEDULEMANAGEMENT_CMD_PACKET_DPP_IN_DATA_REG // 0/R/x/x Command Packet DPP IN Data
#define SSBISCHEDULEMANAGEMENT_CMD_PACKET_IN_DATA_LEN_REG 0xC160 // Command Packet IN Data Length Register
    #define SSBISCHEDULEMANAGEMENT_CMDPKT_INLENGTHBUF   0x3F        // 0/R/x/x Command Packet IN Data Length
#define SSBISCHEDULEMANAGEMENT_PERIODIC_CTLR_EVENT_VECTOR_REG 0xC200 // Periodic Controller Event Vector Register
    #define SSBISCHEDULEMANAGEMENT_PEREP1_INTSTS_EVENTVEC SSBISCHEDULEMANAGEMENT_PERIODIC_CTLR_EVENT_VECTOR_REG // 0/R/x/x Periodic Controller Event Vector Register
#define SSBISCHEDULEMANAGEMENT_ASYNC_1_CTLR_EVENT_VECTOR_REG 0xC210 // Async 1 Controller Event Vector Register
    #define SSBISCHEDULEMANAGEMENT_ASYEP1_INTSTS_EVENTVEC SSBISCHEDULEMANAGEMENT_ASYNC_1_CTLR_EVENT_VECTOR_REG // 0/R/x/x Async 1 Controller Event Vector Register
#define SSBISCHEDULEMANAGEMENT_ASYNC_2_CTLR_EVENT_VECTOR_REG 0xC220 // Async 2 Controller Event Vector Register
    #define SSBISCHEDULEMANAGEMENT_ASYEP2_INTSTS_EVENTVEC SSBISCHEDULEMANAGEMENT_ASYNC_2_CTLR_EVENT_VECTOR_REG // 0/R/x/x Async 2 Controller Event Vector Register
#define SSBISCHEDULEMANAGEMENT_NRDY_CTLR_EVENT_VECTOR_REG 0xC230 // NRDY Controller Event Vector Register
    #define SSBISCHEDULEMANAGEMENT_NRDYEP_INTSTS_EVENTVEC SSBISCHEDULEMANAGEMENT_NRDY_CTLR_EVENT_VECTOR_REG // 0/R/x/x NRDY Controller Event Vector Register
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_0_REG_NO_USE_FOR_HSBI 0xC400 // NRDY Address List 0 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V0       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP0   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR0     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM0  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR0 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID0  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI0     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_1_REG_NO_USE_FOR_HSBI 0xC404 // NRDY Address List 1 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V1       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP1   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR1     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM1  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR1 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID1  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI1     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_2_REG_NO_USE_FOR_HSBI 0xC408 // NRDY Address List 2 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V2       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP2   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR2     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM2  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR2 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID2  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI2     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_3_REG_NO_USE_FOR_HSBI 0xC40C // NRDY Address List 3 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V3       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP3   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR3     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM3  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR3 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID3  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI3     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_4_REG_NO_USE_FOR_HSBI 0xC410 // NRDY Address List 4 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V4       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP4   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR4     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM4  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR4 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID4  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI4     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_5_REG_NO_USE_FOR_HSBI 0xC414 // NRDY Address List 5 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V5       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP5   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR5     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM5  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR5 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID5  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI5     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_6_REG_NO_USE_FOR_HSBI 0xC418 // NRDY Address List 6 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V6       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP6   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR6     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM6  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR6 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID6  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI6     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_7_REG_NO_USE_FOR_HSBI 0xC41C // NRDY Address List 7 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V7       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP7   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR7     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM7  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR7 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID7  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI7     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_8_REG_NO_USE_FOR_HSBI 0xC420 // NRDY Address List 8 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V8       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP8   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR8     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM8  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR8 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID8  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI8     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_9_REG_NO_USE_FOR_HSBI 0xC424 // NRDY Address List 9 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V9       BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP9   BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR9     BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM9  0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR9 0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID9  0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI9     0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_10_REG_NO_USE_FOR_HSBI 0xC428 // NRDY Address List 10 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V10          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP10      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR10        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM10     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR10    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID10     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI10        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_11_REG_NO_USE_FOR_HSBI 0xC42C // NRDY Address List 11 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V11          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP11      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR11        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM11     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR11    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID11     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI11        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_12_REG_NO_USE_FOR_HSBI 0xC430 // NRDY Address List 12 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V12          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP12      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR12        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM12     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR12    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID12     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI12        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_13_REG_NO_USE_FOR_HSBI 0xC434 // NRDY Address List 13 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V13          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP13      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR13        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM13     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR13    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID13     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI13        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_14_REG_NO_USE_FOR_HSBI 0xC438 // NRDY Address List 14 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V14          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP14      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR14        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM14     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR14    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID14     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI14        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_15_REG_NO_USE_FOR_HSBI 0xC43C // NRDY Address List 15 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V15          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP15      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR15        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM15     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR15    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID15     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI15        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_16_REG_NO_USE_FOR_HSBI 0xC440 // NRDY Address List 16 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V16          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP16      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR16        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM16     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR16    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID16     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI16        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_17_REG_NO_USE_FOR_HSBI 0xC444 // NRDY Address List 17 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V17          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP17      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR17        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM17     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR17    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID17     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI17        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_18_REG_NO_USE_FOR_HSBI 0xC448 // NRDY Address List 18 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V18          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP18      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR18        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM18     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR18    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID18     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI18        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_19_REG_NO_USE_FOR_HSBI 0xC44C // NRDY Address List 19 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V19          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP19      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR19        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM19     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR19    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID19     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI19        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_20_REG_NO_USE_FOR_HSBI 0xC450 // NRDY Address List 20 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V20          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP20      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR20        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM20     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR20    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID20     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI20        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_21_REG_NO_USE_FOR_HSBI 0xC454 // NRDY Address List 21 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V21          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP21      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR21        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM21     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR21    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID21     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI21        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_22_REG_NO_USE_FOR_HSBI 0xC458 // NRDY Address List 22 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V22          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP22      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR22        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM22     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR22    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID22     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI22        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_23_REG_NO_USE_FOR_HSBI 0xC45C // NRDY Address List 23 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V23          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP23      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR23        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM23     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR23    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID23     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI23        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_24_REG_NO_USE_FOR_HSBI 0xC460 // NRDY Address List 24 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V24          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP24      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR24        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM24     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR24    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID24     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI24        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_25_REG_NO_USE_FOR_HSBI 0xC464 // NRDY Address List 25 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V25          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP25      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR25        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM25     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR25    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID25     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI25        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_26_REG_NO_USE_FOR_HSBI 0xC468 // NRDY Address List 26 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V26          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP26      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR26        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM26     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR26    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID26     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI26        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_27_REG_NO_USE_FOR_HSBI 0xC46C // NRDY Address List 27 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V27          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP27      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR27        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM27     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR27    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID27     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI27        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_28_REG_NO_USE_FOR_HSBI 0xC470 // NRDY Address List 28 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V28          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP28      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR28        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM28     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR28    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID28     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI28        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_29_REG_NO_USE_FOR_HSBI 0xC474 // NRDY Address List 29 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V29          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP29      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR29        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM29     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR29    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID29     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI29        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_30_REG_NO_USE_FOR_HSBI 0xC478 // NRDY Address List 30 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V30          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP30      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR30        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM30     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR30    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID30     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI30        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_NRDY_ADR_LIST_31_REG_NO_USE_FOR_HSBI 0xC47C // NRDY Address List 31 Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_V31          BIT26       // 0/R/x/x Valid 
    #define SSBISCHEDULEMANAGEMENT_ASYEP31      BIT25       // 0/R/x/x Async Endpoint 
    #define SSBISCHEDULEMANAGEMENT_DIR31        BIT24       // 0/R/x/x Direction 
    #define SSBISCHEDULEMANAGEMENT_EPTNUM31     0xF00000    // 0/R/x/x Endpoint Number.
    #define SSBISCHEDULEMANAGEMENT_DEVADDR31    0xFE000     // 0/R/x/x Device Address.
    #define SSBISCHEDULEMANAGEMENT_SLOTID31     0x1FE0      // 0/R/x/x Slot ID.
    #define SSBISCHEDULEMANAGEMENT_DCI31        0x1F        // 0/R/x/x Device Context Index (DCI).
#define SSBISCHEDULEMANAGEMENT_CMD_PACKET_NUMP0_STA_REG_NO_USE_FOR_HSBI 0xCF00 // Command Packet NUMP0 Status Register (No use for HSBI)
    #define SSBISCHEDULEMANAGEMENT_CMDPKT_ACKNUMP0  BIT0        // 0/R/x/x SS Device Response ACK with NumP=0 Status.
// TRB/Context Management
#define TRBCONTEXTMANAGEMENT_DOORBELL_PRE_FECH_TRB_REQ_ADR_REG 0xD000 // Doorbell Pre-Fech TRB Request Address Register
    #define TRBCONTEXTMANAGEMENT_DBTRBREQADDR   0xFFFFFFFFFFFFFFF0  // 0/x/x/x Doorbell Pre-Fetch TRB Request Address Register
#define TRBCONTEXTMANAGEMENT_DOORBELL_PRE_FECH_TRB_REQ_CTL_REG 0xD008 // Doorbell Pre-Fech TRB Request Control Register
    #define TRBCONTEXTMANAGEMENT_DBTRBREQ   BIT0    // 0/x/x/x Doorbell Pre-Fetch TRB Request.
#define TRBCONTEXTMANAGEMENT_TRB_CACHE_INVALID_CTL_REG 0xD009 // TRB Cache Invalid Control Register
    #define TRBCONTEXTMANAGEMENT_TRBCACEINVLD   BIT0    // 0/x/x/x TRB Cache Invalid Control Register
#define TRBCONTEXTMANAGEMENT_TRB_CACHE_SELIVE_INVALID_ADRS_REG 0xD010 // TRB Cache Selective Invalid Addresss Register
    #define TRBCONTEXTMANAGEMENT_TRBCACHESELINVLDADDR_63_4  0xFFFFFFFFFFFFFFF0  // 0/x/x/x TRB Cache Selective Invalid Request Address
#define TRBCONTEXTMANAGEMENT_TRB_CACHE_SELIVE_INVALID_ADRS_REG_Z1 0xD018 // TRB Cache Selective Invalid Addresss Register
    #define TRBCONTEXTMANAGEMENT_TRBCACHESELINVLDCTL    BIT0    // 0/x/x/x TRB Cache Selective Invalid Request
#define TRBCONTEXTMANAGEMENT_STREAM_CONTEXT_PRE_FETCH_REQ_ADR_REG 0xD020 // Stream Context Pre-Fetch Request Address Register
    #define TRBCONTEXTMANAGEMENT_STRCTXREQADDR  0xFFFFFFFFFFFFFFF0  // 0/x/x/x Stream Context Pre-Fetch Request Address
#define TRBCONTEXTMANAGEMENT_STREAM_CONTEXT_PRE_FETCH_REQ_CTL_REG 0xD028 // Stream Context Pre-Fetch Request Control Register
    #define TRBCONTEXTMANAGEMENT_STRCTXREQ  BIT0    // 0/x/x/x Doorbell Stream Context Pre-Fetch Request.
#define TRBCONTEXTMANAGEMENT_STREAM_CONTEXT_INVALID_CTL_REG 0xD029 // Stream Context Invalid Control Register
    #define TRBCONTEXTMANAGEMENT_STRCTXINVLD    BIT0    // 0/x/x/x Stream Context Invalid Control Register
#define TRBCONTEXTMANAGEMENT_STREAM_CONTEXT_INVALID_ADR_REG 0xD030 // Stream Context Invalid Address Register
    #define TRBCONTEXTMANAGEMENT_STRCTXSELINVLDADDR 0xFFFFFFFFFFFFFFF0  // 0/x/x/x Stream Context Selective Invalid Address
#define TRBCONTEXTMANAGEMENT_STREAM_CONTEXT_SEL_INVALID_CTL_REG 0xD038 // Stream Context Select Invalid Control Register
    #define TRBCONTEXTMANAGEMENT_STRCTXSELINVLDREQ  BIT0    // 0/x/x/x Doorbell Stream Context Select Invalid Request.
// XHCI_MCU_DBC
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_CMD_REG 0xF000 // XHCI Debug Capability Default Control Endpoint Command Register
    #define XHCIMCUDBC_DBC_CCSCHE_EN        BIT5            // 0/x/x/x DBC disconnect change interrupt enbale
    #define XHCIMCUDBC_CTLEP_INTE           BIT4            // 0/x/x/x Control Endpoint Interrupt Enable
    #define XHCIMCUDBC_CTLEP_RXSTATUS_INTE  BIT3            // 0/x/x/x Control Endpoint Rx Status TP Interrupt Enable
    #define XHCIMCUDBC_CTLEP_RXSETUP_INTE   BIT2            // 0/x/x/x Control Endpoint Rx Setup DP Interrupt Enable
    #define XHCIMCUDBC_CTLEP_RXINACK_INTE   BIT1            // 0/x/x/x Control Endpoint Rx IN ACK TP Interrupt Enable
    #define XHCIMCUDBC_DBC_PORTRST_INTE     BIT0            // 0/x/x/x Port reset interrupt enable:
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_STA_REG 0xF001 // XHCI Debug Capability Default Control Endpoint Status Register
    #define XHCIMCUDBC_CTLEP_FCSTS          BIT7            // 0/R/x/x Control Endpoint is Flow Controlled.
    #define XHCIMCUDBC_CTLEP_RXSTATUS_STS   BIT4            // 0/x/x/x Control Endpoint Rx Status TP Status
    #define XHCIMCUDBC_CTLEPIN_RXSETUP_STS  BIT3            // 0/x/x/x Control Endpoint with IN data stage or  no data stage Rx Setup DP Int...
    #define XHCIMCUDBC_CTLEP_RXOUTDP_STS    BIT2            // 0/x/x/x Control Endpoint Rx Control OUT DP Interrupt Status
    #define XHCIMCUDBC_CTLEP_RXINACK_STS    BIT1            // 0/x/x/x Control Endpoint Rx Control IN ACK TP Interrupt Status
    #define XHCIMCUDBC_RESERVEED            BIT0            // 0/x/x/x Reserved
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_STA_REG_Z1 0xF002 // XHCI Debug Capability Default Control Endpoint Status Register
    #define XHCIMCUDBC_CTLEP_RQSTERR    BIT1    // 0/x/x/x Control Endpoint is HALT
    #define XHCIMCUDBC_CTLEP_SETUP_CMPL BIT0    // 0/x/x/x Control Endpoint Setup Parsing Complete 
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_STA_PART_1_REG 0xF003 // XHCI Debug Capability Default Control Endpoint Status Part 1 Register
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_STA_PART_2_REG 0xF004 // XHCI Debug Capability Default Control Endpoint Status Part 2 Register
    #define XHCIMCUDBC_RESERVEDQUICK_MODE XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_STA_PART_2_REG // 0/x/x/x Reserved
#define XHCIMCUDBC_XHCI_DEBUG_CAP_STA_REG 0xF005 // XHCI Debug Capability Status Register
    #define XHCIMCUDBC_DBC_CCS_CHG  BIT10   // 0/x/x/x Connect statu change status:
    #define XHCIMCUDBC_DBC_DCECHG   BIT9    // 0/x/x/x DBC enable status
    #define XHCIMCUDBC_DBC_PORTRST  BIT8    // 0/x/x/X Port reset status
    #define XHCIMCUDBC_DBC_DEVADDR  0xFE    // 0/x/x/x Device Address
    #define XHCIMCUDBC_DBC_RUN      BIT0    // 0/x/x/x Debug Capability Run
#define XHCIMCUDBC_XHCI_DEBUG_CAP_CMD_REG 0xF007 // XHCI Debug Capability command Register
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_CTL_OUT_DPH_REG 0xF008 // XHCI Debug Capability Default Control Endpoint Control OUT DPH Register
    #define XHCIMCUDBC_CTLEP_SETUPCMD_D XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_CTL_OUT_DPH_REG // 0/R/x/x Control Setup DP 8 Bytes Command
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_CTL_OUT_DPH_RX_CTL_IN_RX_TPH_REG 0xF010 // XHCI Debug Capability Default Control Endpoint Control OUT DPH Rx/Control IN Rx TPH Register
    #define XHCIMCUDBC_CTLEP_RXHDR XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_CTL_OUT_DPH_RX_CTL_IN_RX_TPH_REG // 0/R/x/x Control OUT Rx DPH Content
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_512_BYTES_CTL_OUT_RX_IN_TX_DPP_REG 0xF100 // XHCI Debug Capability Default Control Endpoint 512 Bytes Control OUT Rx/IN Tx DPP Register
    #define XHCIMCUDBC_CTLEP_DATSTG_DATA XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_512_BYTES_CTL_OUT_RX_IN_TX_DPP_REG // 0/x/x/x Control OUT Rx DPP/Control IN Tx DPP Content
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_CTL_IN_RESPONSE_TX_DPH_REG 0xF020 // XHCI Debug Capability Default Control Endpoint Control IN Response Tx DPH Register
    #define XHCIMCUDBC_CTLEP_DATSTG_TXDPHEADER XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_CTL_IN_RESPONSE_TX_DPH_REG // 0/x/x/x Control IN Response Tx DPH Register
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_DEBUG_STA_REG 0xF030 // XHCI Debug Capability Default Control Endpoint Debug Status Register
    #define XHCIMCUDBC_CTLEP_DBGSTS XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_CTL_ENDPOINT_DEBUG_STA_REG // 0/R/x/x Control Endpoint Controller Debug Status
#define XHCIMCUDBC_XHCI_DEBUG_CAP_BULK_IN_ENDPOINT_CMD_REG 0xF200 // XHCI Debug Capability Bulk IN Endpoint Command Register
    #define XHCIMCUDBC_BLKIN_TRFCMPL_INTE   BIT6            // 0/x/x/x Bulk IN Endpoint Transfer Complete Interrupt Enable
    #define XHCIMCUDBC_BLKIN_HIT_INTE       BIT5            // 0/x/x/x HOT interrupt enable
    #define XHCIMCUDBC_BLKIN_RXINTP_INTE    BIT4            // 0/x/x/x Bulk IN Endpoint Rx IN ACK TP Interrupt Enable
    #define XHCIMCUDBC_BLKIN_DB_INTE        BIT3            // 0/x/x/x Bulk IN Endpoint Doorbell Ring Interrupt Enable
    #define XHCIMCUDBC_BLKIN_INTE           BIT2            // 0/x/x/x Bulk IN Endpoint Interrupt Enable
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_STA_REG 0xF201 // XHCI Debug Capability Default Bulk IN Endpoint Status Register
    #define XHCIMCUDBC_BLKIN_FCSTS          BIT7    // 0/x/x/x Bulk IN Endpoint is Flow Controlled.
    #define XHCIMCUDBC_BLKIN_TRFCMPL_STS    BIT6    // 0/x/x/x Bulk IN Endpoint Transfer Complete Status
    #define XHCIMCUDBC_BLKIN_HIT_STS        BIT5    // 0/x/x/x Bulk IN HOT assert status:
    #define XHCIMCUDBC_BLKIN_RXINTP_STS     BIT4    // 0/x/x/x Bulk IN Endpoint Rx IN ACK TP Status
    #define XHCIMCUDBC_BLKIN_DB_STS         BIT3    // 0/x/x/x Bulk IN Endpoint Doorbell Ring Status
    #define XHCIMCUDBC_BLKIN_STALL          BIT2    // 0/x/x/x BULK IN Endpoint is HALT
    #define XHCIMCUDBC_BLKIN_OUTDPISIDT     BIT1    // 0/x/x/x Bulk IN Endpoint OUT DP is IDT Data.
    #define XHCIMCUDBC_BLKIN_OUTDPRDY       BIT0    // 0/x/x/x Bulk IN Endpoint OUT DP Ready 
#define XHCIMCUDBC_XHCI_DEBUG_CAP_BULK_IN_ENDPOINT_CMD_REG_Z1 0xF202 // XHCI Debug Capability Bulk IN Endpoint Command Register
    #define XHCIMCUDBC_BLKIN_TDEMPTY    BIT3    // 0/x/x/x Bulk in endpoint TD empty
    #define XHCIMCUDBC_BLKIN_SEQNUM_RST BIT2    // 0/x/x/x Bulk IN endpoint sequence number reset
    #define XHCIMCUDBC_BLKIN_TRBERR     BIT1    // 0/x/x/x Bulk IN TRB error:
    #define XHCIMCUDBC_BLKIN_RST        BIT0    // 0/x/x/x Bulk IN Endpoint Controller Reset
#define XHCIMCUDBC_XHCI_DEBUG_CAP_BULK_IN_ENDPOINT_OUT_TX_IDT_DATA_REG 0xF208 // XHCI Debug Capability Bulk IN Endpoint OUT TX IDT Data Register
    #define XHCIMCUDBC_BLKIN_OUTIDTDP XHCIMCUDBC_XHCI_DEBUG_CAP_BULK_IN_ENDPOINT_OUT_TX_IDT_DATA_REG // 0/x/x/x Bulk IN Endpoint OUT 8Bytes IDT Data
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_OUT_BUFFER_REQ_REG 0xF210 // XHCI Debug Capability Default Bulk IN Endpoint OUT Buffer Request Register
    #define XHCIMCUDBC_BFOUT_ACKTAGFIXTO0   0x7C    // 0/R/x/x OUT Buffer Requested TAG
    #define XHCIMCUDBC_BFOUT_REQ            BIT0    // 0/x/x/x OUT Buffer Request:
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_OUT_BUFFER_RELEASE_REG 0xF211 // XHCI Debug Capability Default Bulk IN Endpoint OUT Buffer Release Register
    #define XHCIMCUDBC_OUTRELEASE_TAGFIXTO0 0x7C    // 0/R/x/x OUT Buffer Release TAG
    #define XHCIMCUDBC_OUTRELEASE           BIT0    // 0/x/x/x OUT Buffer Release:
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_OUT_DATA_FETCH_REQ_REG 0xF214 // XHCI Debug Capability Default Bulk IN Endpoint OUT Data Fetch Request Register
    #define XHCIMCUDBC_OUTDATA_LEN          0x7FF0000   // 0/x/x/x OUT Data Request Length (Byte Number)
    #define XHCIMCUDBC_OUTDATA_NS           BIT7        // 0/x/x/x OUT Data Request Non-Snoop
    #define XHCIMCUDBC_OUTDATA_TAGFIXTO0    0x3E        // 0/x/x/x OUT Data Buffer TAG
    #define XHCIMCUDBC_OUTDATA_REQ          BIT0        // 0/x/x/x OUT Data Request
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_OUT_DATA_FETCH_REQ_ADR_REG 0xF218 // XHCI Debug Capability Default Bulk IN Endpoint OUT Data Fetch Request Address Register
    #define XHCIMCUDBC_OUTDATA_ADDR 0xFFFFFFFFF         // 0/x/x/x OUT Data Request Address
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_RX_TPH_REG 0xF220 // XHCI Debug Capability Default Bulk IN Endpoint Rx TPH Register
    #define XHCIMCUDBC_BLKIN_RXTPH XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_RX_TPH_REG // 0/R/x/x Bulk IN Rx ACK TPH Content
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_RESPONSE_TX_DPH_REG 0xF230 // XHCI Debug Capability Default Bulk IN Endpoint Response Tx DPH Register
    #define XHCIMCUDBC_BLKIN_TXDPH XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_RESPONSE_TX_DPH_REG // 0/x/x/x Bulk IN Endpoint Response Tx DPH Register
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_DEBUG_STA_REG 0xF240 // XHCI Debug Capability Default Bulk IN Endpoint Debug Status Register
    #define XHCIMCUDBC_BLKIN_DBGSTS XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_IN_ENDPOINT_DEBUG_STA_REG // 0/x/x/x Bulk IN Endpoint Debug Status
#define XHCIMCUDBC_XHCI_DEBUG_CAP_BULK_OUT_ENDPOINT_CMD_REG 0xF300 // XHCI Debug Capability Bulk OUT Endpoint Command Register
    #define XHCIMCUDBC_BLKOUT_TRFCMPL_INTE  BIT6            // 0/x/x/x Bulk OUT Endpoint Transfer Complete Interrupt Enable
    #define XHCIMCUDBC_BLKOUT_HOT_INTE      BIT5            // 0/x/x/x HIT interrupt enable
    #define XHCIMCUDBC_BLKOUT_RXDPH_INTE    BIT4            // 0/x/x/x Bulk OUT Endpoint Rx DPH Interrupt Enable
    #define XHCIMCUDBC_BLKOUT_INTE          BIT2            // 0/x/x/x Bulk OUT Endpoint Interrupt Enable
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_STA_REG 0xF301 // XHCI Debug Capability Default Bulk OUT Endpoint Status Register
    #define XHCIMCUDBC_BLKOUT_FCSTS         BIT7    // 0/R/x/x Bulk OUT Endpoint is Flow Controlled.
    #define XHCIMCUDBC_BLKOUT_TRFCMPL_STS   BIT6    // 0/x/x/x Bulk OUT Endpoint Transfer Complete Status
    #define XHCIMCUDBC_BLKOUT_HOT_STS       BIT5    // 0/x/x/x Bulk OUT HIT assert status:
    #define XHCIMCUDBC_BLKOUT_RXDPH_STS     BIT4    // 0/x/x/x Bulk OUT Endpoint Rx DPH Status
    #define XHCIMCUDBC_BLKOUT_DB_STS        BIT3    // 0/x/x/x Bulk OUT Endpoint Doorbell Ring Status
    #define XHCIMCUDBC_BLKOUT_STALL         BIT2    // 0/x/x/x BULK OUT Endpoint is HALT
    #define XHCIMCUDBC_BLKOUT_INBUFRDY      BIT0    // 0/x/x/x Bulk OUT Endpoint IN buffer Ready 
#define XHCIMCUDBC_XHCI_DEBUG_CAP_BULK_OUT_ENDPOINT_CMD_REG_Z1 0xF302 // XHCI Debug Capability Bulk OUT Endpoint Command Register
    #define XHCIMCUDBC_BLKOUT_TDEMPTY       BIT3    // 0/x/x/x Bulk out endpoint TD empty
    #define XHCIMCUDBC_BLKOUT_SEQNUM_RST    BIT2    // 0/x/x/x Bulk OUT endpoint sequence number reset
    #define XHCIMCUDBC_BLKOUT_TRBERR        BIT1    // 0/x/x/x Bulk OUT TRB error:
    #define XHCIMCUDBC_BLKOUT_RST           BIT0    // 0/x/x/x Bulk OUT Endpoint Controller Reset
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_IN_BUFFER_REQ_REG 0xF310 // XHCI Debug Capability Default Bulk OUT Endpoint IN Buffer Request Register
    #define XHCIMCUDBC_BFIN_ACKTAGFIXTO0    0x7C    // 0/R/x/x IN Buffer Requested TAG
    #define XHCIMCUDBC_BFIN_REQ             BIT0    // 0/x/x/x IN Buffer Request
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_OUT_BUFFER_RELEASE_REG 0xF311 // XHCI Debug Capability Default Bulk OUT Endpoint OUT Buffer Release Register
    #define XHCIMCUDBC_INRELEASE_TAGFIXTO0  0x7C    // 0/R/x/x IN Buffer Release TAG
    #define XHCIMCUDBC_OUTBABBLE            BIT1    // 0/x/x/x Babble:
    #define XHCIMCUDBC_INRELEASE            BIT0    // 0/x/x/x IN Buffer Release
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_IN_DATA_FLUSH_REQ_REG 0xF314 // XHCI Debug Capability Default Bulk OUT Endpoint IN Data Flush Request Register
    #define XHCIMCUDBC_INDATA_LEN       0x7FF0000   // 0/x/x/x IN Data Request Length (Byte Number)
    #define XHCIMCUDBC_INDATA_NS        BIT7        // 0/x/x/x IN Data Request Non-Snoop
    #define XHCIMCUDBC_INDATA_TAGFIXTO0 0x3E        // 0/x/x/x IN Data Buffer TAG
    #define XHCIMCUDBC_INDATA_REQ       BIT0        // 0/x/x/x IN Data Flush Request
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_IN_DATA_FLUSH_REQ_ADR_REG 0xF318 // XHCI Debug Capability Default Bulk OUT Endpoint IN Data Flush Request Address Register
    #define XHCIMCUDBC_INDATA_ADDR  0xFFFFFFFFF         // 0/x/x/x IN Data Request Address
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_RX_DPH_REG 0xF320 // XHCI Debug Capability Default Bulk OUT Endpoint Rx DPH Register
    #define XHCIMCUDBC_BLKOUT_RXDPH XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_RX_DPH_REG // 0/R/x/x Bulk OUT Rx DPH Content
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_RESPONSE_TX_TPH_REG 0xF330 // XHCI Debug Capability Default Bulk OUT Endpoint Response Tx TPH Register
#define XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_DEBUG_STA_REG 0xF340 // XHCI Debug Capability Default Bulk OUT Endpoint Debug Status Register
    #define XHCIMCUDBC_BLKOUT_DBGSTS XHCIMCUDBC_XHCI_DEBUG_CAP_DEFAULT_BULK_OUT_ENDPOINT_DEBUG_STA_REG // 0/R/x/x Bulk OUT Endpoint Debug Status
// DATA SRAM
#define DATASRAM_BLOCK_1_ADR_WINDOW_MIN_ADR 0x0 // Block 1 address window min address
    #define DATASRAM_DBLK1_LOWER    0xFFFFFFF0  // 0/x/x/x Data SRAM Block 1 address window min address 
#define DATASRAM_BLOCK_1_ADR_WINDOW_MAX_ADR 0x4 // Block 1 address window max address
    #define DATASRAM_DBLK1_UPPER    0xFFFFFFF0  // 0/x/x/x Data SRAM Block 1 address window max address 
#define DATASRAM_BLOCK_2_ADR_WINDOW_MIN_ADR 0x8 // Block 2 address window min address
    #define DATASRAM_DBLK2_LOWER    0xFFFFFFF0  // 0/x/x/x Data SRAM Block 2 address window min address 
#define DATASRAM_BLOCK_2_ADR_WINDOW_MAX_ADR 0xC // Block 2 address window max address
    #define DATASRAM_DBLK2_UPPER    0xFFFFFFF0  // 0/x/x/x Data SRAM Block 2 address window max address 
#define DATASRAM_MCU_DATA_SRAM_DMA_ADR 0x10 // MCU Data SRAM DMA Address
    #define DATASRAM_MCUDAT_DMA_ADD_31_0 DATASRAM_MCU_DATA_SRAM_DMA_ADR // 0/x/x/x DMA base address 
#define DATASRAM_MCU_DATA_SRAM_DMA_LEN 0x14 // MCU Data SRAM DMA Length
    #define DATASRAM_MCUDAT_DMA_LEN_10_0    0x7FF       // 0/x/x/x DMA data length (DW in unit) 
#define DATASRAM_MCU_DATA_SRAM_DMA_WR 0x18 // MCU Data SRAM DMA WR
    #define DATASRAM_MCUDAT_DMA_WR  BIT0    // 0/x/x/x DMA write or Read 
#define DATASRAM_MCU_DATA_SRAM_DMA_RUN_BIT 0x19 // MCU Data SRAM DMA RUN bit
    #define DATASRAM_MCUDAT_DMA_RUN BIT0    // 0/x/x/x DMA run bit 
#define DATASRAM_MCU_DATA_SRAM_DMA_STA 0x1A // MCU Data SRAM DMA Status
    #define DATASRAM_MCUDAT_DMA_STS BIT0    // 0/x/x/x DMA Status bit (R/WRC)
#define DATASRAM_MCU_MAIN_INSTRUCTION_ADR_WINDOW_MIN_ADR 0x20 // MCU Main Instruction address window min address
    #define DATASRAM_MAININST2_LOWER DATASRAM_MCU_MAIN_INSTRUCTION_ADR_WINDOW_MIN_ADR // 0/x/x/x Main instruction ?s Min Address 2.
#define DATASRAM_MCU_MAIN_INSTRUCTION_ADR_WINDOW_MAX_ADR 0x24 // MCU Main Instruction address window max address
    #define DATASRAM_MAININST2_UPPER DATASRAM_MCU_MAIN_INSTRUCTION_ADR_WINDOW_MAX_ADR // 0/x/x/x Main instruction ?s MAX Address 2.
#define DATASRAM_MCU_MAIN_INSTRUCTION_ADR_WINDOW_MAX_ADR_Z1 0x28 // MCU Main Instruction address window max address
    #define DATASRAM_INS_BUF_EN BIT0        // 0/x/x/x Instruction Buffer Enable
#define DATASRAM_MCU_MAIN_INSTRUCTION_ADR_WINDOW_MAX_ADR_Z2 0x2C // MCU Main Instruction address window max address
    #define DATASRAM_MCU_FSBC_CLKON BIT0        // 0/x/x/x FSBC Clock ON
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CND001(1.00)
// Pls contact PLW to report Irs2h bugs.
