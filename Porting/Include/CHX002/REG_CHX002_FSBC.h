//**********************************************************************
//**********************************************************************
//**                                                                  **
//**     Copyright (c) 2018 Shanghai Zhaoxin Semiconductor Co., Ltd.  **
//**                                                                  **
//**********************************************************************
//**********************************************************************

///
#ifndef REG_CHX001_FSBC_H
#define REG_CHX001_FSBC_H
// FSBC
#define FSBC_BASIC_FUN_MODE 0x20 // Basic Function Mode
    #define FSBC_RSV_20_A0          BIT7    // 00b/x/x/x Reserved
    #define FSBC_RSIM_FAST_A0       BIT6    // 0b/x/x/x Enable simulation fast capture mode
    #define FSBC_RUSER_STOP_A0      BIT5    // 0b/x/x/x Stop transaction trigger function
    #define FSBC_RENABLEBUSIDLE_A0  BIT4    // 0b/x/x/x Enable bus idle as transaction trigger 
    #define FSBC_RENABLETRANTRIG_A0 BIT3    // 0b/x/x/x Enable transaction trigger function
    #define FSBC_RCAPDBGSIGNAL_A0   BIT2    // 0b/x/x/x Enable debugging signals capture 
    #define FSBC_RCAPDATA_A0        BIT1    // 0b/x/x/x Enable HD capture capability
    #define FSBC_RENABLECAP_A0      BIT0    // 0b/x/x/x Enable capture Mode 
#define FSBC_HOST_CLK 0x21 // Host Clock
    #define FSBC_RSV_21_A0  BIT7    // 0b/x/x/x Reserved
    #define FSBC_MODE100_A0 BIT6    // 1b/x/x/x Host Clock 100M Frequency Mode
    #define FSBC_MODE133_A0 BIT5    // 0b/x/x/x Host Clock 133M Frequency Mode
    #define FSBC_MODE166_A0 BIT4    // 0b/x/x/x Host Clock 166M Frequency Mode
    #define FSBC_MODE200_A0 BIT3    // 0b/x/x/x Host Clock 200M Frequency Mode
    #define FSBC_MODE266_A0 BIT2    // 0b/x/x/x Host Clock 266M Frequency Mode
    #define FSBC_MODE333_A0 BIT1    // 0b/x/x/x Host Clock 333M Frequency Mode
    #define FSBC_MODE400_A0 BIT0    // 0b/x/x/x Host Clock 400M Frequency Mode
#define FSBC_FIFO_CNTER 0x22 // FIFO counter
    #define FSBC_DRAM_PRI_CNT_A0 FSBC_FIFO_CNTER // 0h/x/x/x Counter for assert DRAMC bus high Priority signal
#define FSBC_FIFO_CNTER_Z1 0x23 // FIFO counter
    #define FSBC_DRAM_REQ_CNT_A0 FSBC_FIFO_CNTER_Z1 // 0h/x/x/x Counter for assert DRAMC bus request  signal
#define FSBC_DRAM_BASE_ADR 0x24 // DRAM Base Address
    #define FSBC_RSV_24_A0  0xF000  // 0h/x/x/x Reserved
    #define FSBC_RFSBCBS_A0 0xFFF   // 0h/x/x/x Base address for captured FSBC data buffer
#define FSBC_DRAM_SIZE 0x26 // DRAM Size
    #define FSBC_RSV_26_A0  0xF8                    // 0h/x/x/x Reserved
    #define FSBC_RFSBCSZ_A0 (BIT0 + BIT1 + BIT2)    // 000b/x/x/x FSBC data buffer size
#define FSBC_DRAM_TRIGGER_POSITION 0x27 // DRAM Trigger Position
    #define FSBC_RSV_27_A0      0xF8                    // 0h/x/x/x Reserved
    #define FSBC_RTRIGPOS_A0    (BIT0 + BIT1 + BIT2)    // 000b/x/x/x Trigger position for FSBC data buffer in trigger mode
#define FSBC_DRAM_TRIGGER_ADR 0x28 // DRAM Trigger Address
    #define FSBC_RWRAPBS_A0 FSBC_DRAM_TRIGGER_ADR // 0h/x/x/x Starting address to access trigger point captured memory
#define FSBC_BASIC_STA 0x2A // Basic Status
    #define FSBC_RSV_2A_A0      0xFFFE  // 0h/x/x/x Reserved
    #define FSBC_RFSBCDONE_A0   BIT0    // 0b/x/x/x Capture done in snapshot/trigger mode
#define FSBC_FIFO_CNTER_Z2 0x2C // FIFO counter
    #define FSBC_FIFO_FULL_CNT0_A0 FSBC_FIFO_CNTER_Z2 // 0h/x/x/x Counter for calculate FSBC internal SRAM Full
#define FSBC_FIFO_CNTER_Z3 0x2D // FIFO counter
    #define FSBC_FIFO_FULL_CNT1_A0 FSBC_FIFO_CNTER_Z3 // 0h/x/x/x Counter for calculate FSBC internal SRAM near Full to assert FSBC_V4...
#define FSBC_FIFO_CNTER_Z4 0x2E // FIFO counter
    #define FSBC_FIFO_FULL_CNT2_A0 FSBC_FIFO_CNTER_Z4 // 0h/x/x/x Counter for calculate FSBC internal SRAM near Full to assert FSBC_V4...
#define FSBC_FIFO_CNTER_Z5 0x2F // FIFO counter
    #define FSBC_FIFO_FULL_CNT3_A0 FSBC_FIFO_CNTER_Z5 // 0h/x/x/x Counter for calculate FSBC internal SRAM near Full to assert FSBC_V4...
#define FSBC_TRIGGER_PATTERN_AND_MASK 0x30 // Trigger Pattern and Mask
    #define FSBC_RHAPATTERN_31_0_A0 FSBC_TRIGGER_PATTERN_AND_MASK // 0h/x/x/x HA bus phase A pattern for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z1 0x34 // Trigger Pattern and Mask
    #define FSBC_RHBPATTERN_31_0_A0 FSBC_TRIGGER_PATTERN_AND_MASK_Z1 // 0h/x/x/x HA bus phase B pattern for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z2 0x38 // Trigger Pattern and Mask
    #define FSBC_RHAMASK_31_0_A0 FSBC_TRIGGER_PATTERN_AND_MASK_Z2 // 0h/x/x/x HA bus phase A pattern mask bit for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z3 0x3C // Trigger Pattern and Mask
    #define FSBC_RHBMASK_31_0_A0 FSBC_TRIGGER_PATTERN_AND_MASK_Z3 // 0h/x/x/x HA bus phase B pattern mask bit for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z4 0x40 // Trigger Pattern and Mask
    #define FSBC_RSV_40_A0              BIT7    // 0b/x/x/x Reserved
    #define FSBC_RHAPATTERN32_A0        BIT6    // 0b/x/x/x HA bus phase A pattern for transaction trigger function
    #define FSBC_RHREQAPATTERN_5_0_A0   0x3F    // 0h/x/x/x Hreq bus phase A pattern for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z5 0x41 // Trigger Pattern and Mask
    #define FSBC_RSV_41_A0              BIT7    // 0b/x/x/x Reserved
    #define FSBC_RHBPATTERN32_A0        BIT6    // 0b/x/x/x HA bus phase B pattern for transaction trigger function
    #define FSBC_RHREQBPATTERN_5_0_A0   0x3F    // 0h/x/x/x Hreq bus phase B pattern for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z6 0x42 // Trigger Pattern and Mask
    #define FSBC_RSV_42_A0          BIT7    // 0b/x/x/x Reserved
    #define FSBC_RHAMASK32_A0       BIT6    // 0b/x/x/x HA bus phase A pattern mask bit for transaction trigger function
    #define FSBC_RHREQAMASK_5_0_A0  0x3F    // 0h/x/x/x Hreq bus phase A pattern mask bit for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z7 0x43 // Trigger Pattern and Mask
    #define FSBC_RSV_43_A0          BIT7    // 0b/x/x/x Reserved
    #define FSBC_RHBMASK32_A0       BIT6    // 0b/x/x/x HA bus phase B pattern mask bit for transaction trigger function
    #define FSBC_RHREQBMASK_5_0_A0  0x3F    // 0h/x/x/x Hreq bus phase B pattern mask bit for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z8 0x50 // Trigger Pattern and Mask
    #define FSBC_RHDPATTERN_31_0_A0 FSBC_TRIGGER_PATTERN_AND_MASK_Z8 // 0h/x/x/x HD bus pattern for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z9 0x54 // Trigger Pattern and Mask
    #define FSBC_RHDPATTERN_63_32_A0 FSBC_TRIGGER_PATTERN_AND_MASK_Z9 // 0h/x/x/x HD bus pattern for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z10 0x58 // Trigger Pattern and Mask
    #define FSBC_RHDMASK_31_0_A0 FSBC_TRIGGER_PATTERN_AND_MASK_Z10 // 0h/x/x/x HD bus pattern mask bit for transaction trigger function
#define FSBC_TRIGGER_PATTERN_AND_MASK_Z11 0x5C // Trigger Pattern and Mask
    #define FSBC_RHDMASK_63_32_A0 FSBC_TRIGGER_PATTERN_AND_MASK_Z11 // 0h/x/x/x HD bus pattern mask bit for transaction trigger function
#define FSBC_NB_DEBUG_SIGNAL_SEL 0x60 // NB Debug signal Select
    #define FSBC_RSV_63_A0                  0xFE000000  // 0h/x/x/x Reserved
    #define FSBC_RDBGMX_NBTOP_G0_4_0_A0     0x1F00000   // 0h/x/x/x NB debug signal group 0 top level select bit
    #define FSBC_RDBGMX_MODULE_G0_19_0_A0   0xFFFFF     // 0h/x/x/x NB debug signal group 0 module level select bit
#define FSBC_NB_DEBUG_SIGNAL_SEL_Z1 0x64 // NB Debug signal Select
    #define FSBC_NB2SB_FSBCDBGEN_A0         BIT31       // 0b/x/x/x Enable use FSBC select debug signal group
    #define FSBC_RSV_67_A0                  0x7E000000  // 0h/x/x/x Reserved
    #define FSBC_RDBGMX_NBTOP_G1_4_0_A0     0x1F00000   // 0h/x/x/x NB debug signal group 1 top level select bit
    #define FSBC_RDBGMX_MODULE_G1_19_0_A0   0xFFFFF     // 0h/x/x/x NB debug signal group 1 module level select bit
#define FSBC_SB_DEBUG_SIGNAL_SEL 0x68 // SB Debug signal Select
    #define FSBC_RSV_6B_A0                  0xFE000000  // 0h/x/x/x Reserved
    #define FSBC_NB2SB_FSBCTOPSEL1_4_0_A0   0x1F00000   // 0h/x/x/x SB debug signal group 0 top level select bit
    #define FSBC_NB2SB_FSBCSUBSEL1_19_0_A0  0xFFFFF     // 0h/x/x/x SB debug signal group 0 module level select bit
#define FSBC_SB_DEBUG_SIGNAL_SEL_Z1 0x6C // SB Debug signal Select
    #define FSBC_RSV_6F_A0                  0xFE000000  // 0h/x/x/x Reserved
    #define FSBC_NB2SB_FSBCTOPSEL2_4_0_A0   0x1F00000   // 0h/x/x/x SB debug signal group 1 top level select bit
    #define FSBC_NB2SB_FSBCSUBSEL2_19_0_A0  0xFFFFF     // 0h/x/x/x SB debug signal group 1 module level select bit
#endif
// Irs2h.exe Revision: 5.0.0.0
// Irs2h.ini Revision: CND001(1.00)
// Pls contact PLW to report Irs2h bugs.
